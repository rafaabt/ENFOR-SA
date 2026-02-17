import random
import csv
import torch
import os
import random
import pandas as pd

from src import definitions as defs
from src.utils import utils as u

from dataclasses import dataclass
from collections import deque
from collections import defaultdict
from typing import Deque, List, Union, Tuple, Optional


# faults for 2d tensors only (only inputs)
@dataclass
class Fault:
    tag: int         # fault id
    layer_id:  int   # target layer
    att_block: int   # target attention block
    att_head:  int   # target attention head
    x: int           # tensor row 
    y: int           # tensor col
    target: int      # target input (A or B)
    bit: int         # target bit


# this is the global fault list used for each fault injection trial
# load this with fault_list = load_fault_list(<file name>, (start line, end line))
fault_list = deque[Fault]()

# marks the next fault is a leaf node
next_fault_is_leaf = False

# marks the next fault (for sequential fault injection)
next_fault: Fault

BLOCKS=12
LAYERS_IN_BLOCKS=6

# the fault list for the attention blocks
# each block, in each layer type (qkv, matmul_1, matmul_2, mlps) has it's own fault list

att_blocks_flist_map = {
    blk: {layer: [] for layer in range(LAYERS_IN_BLOCKS)}
    for blk in range(BLOCKS)
}

# the class head is not inside a block, so we do not keed to consider the block dimention like in att_blocks_flist_map
head_fault_list = []


def gen_random_fault(shape_A: Tuple[int, int], 
                     layer_id:int, 
                     depth:int=12, 
                     num_heads:int=6) -> Fault:
    rows_A, cols_A = shape_A

    att_block = random.randint(0, depth-1)

    x = random.randint(0, rows_A-1)
    y = random.randint(0, cols_A-1)

    # the target bit
    bits = 8
    bit = random.randint(0, bits-1)
    target = 1
    att_head = random.randint(0, num_heads-1)

    return Fault(42, layer_id, att_block, att_head, x, y, target, bit)


def generate_fault_list(layer_id, 
                        shape_A, 
                        start_tag, 
                        depth:int=12, 
                        num_heads:int=6,
                        max_faults=10000) -> List[Fault]:
    rows_A, cols_A = shape_A

    new_fault_list = []
    # use a fixed random if required
    random.seed(42)

    # start_tag: when generating the fault list for all layers generate_fault_list() is called once per layer. start_tag allows to keep the tag counter accross all layers
    l = 0

    while l < max_faults:
        random_fault = gen_random_fault(
            shape_A, 
            layer_id, 
            depth=depth, 
            num_heads=num_heads)

        random_fault.tag = start_tag + l
        new_fault_list.append(random_fault)
        l += 1

    return new_fault_list


# dumps the fault list to a file
def dump_fault_list (flist: List[Fault], fn="default.csv"):
    filename = f"./fault_lists/{fn}"
    header = ['tag', 'layer', 'block', 'head', 'x', 'y', 'target', 'bit']

    #print(f"Dumping fault list to file {filename} - size {len(flist)}")

    target = 1

    with open(filename, mode='w', newline='') as file:
        writer = csv.writer(file, delimiter='\t')
        writer.writerow(header)

        for fault in flist:
            csv_row = [
                fault.tag, 
                fault.layer_id, 
                fault.att_block, 
                fault.att_head, 
                fault.x, 
                fault.y, 
                target, 
                fault.bit
            ]

            writer.writerow(csv_row)

    print(f"Saved fault list: {fn}  -  Size: {len(flist)} rows")


# loads the fault list in a given line range (line zero is always skipped)
# the list is read from the file created by the generate_fault_list() function
# the fault list is returned in form of a deque
def load_fault_list(fn_list: str, 
                    itv_tuple: Union[int, Tuple[int, int]],  # itvl tuple = (row_start, row_end)
                    filters: Optional[dict]=None, 
                    shuffle_list=False) -> deque[Fault]: 

    file_path = f"./fault_lists/{defs.MODEL_NAME}/{fn_list}"

    if not os.path.exists(file_path):
        raise ValueError(f"Missing fault list: {file_path}")

    if filters:
        df = u.filter_csv(in_fn=file_path, filters=filters)
    else:
        df = pd.read_csv(file_path, comment='#', sep='\t')   

    row_start, row_end = (itv_tuple, itv_tuple) if isinstance(itv_tuple, int) else itv_tuple

    filtered_rows = df.iloc[row_start:row_end+1]

    # Convert each row into a list and store in a list
    fault_list_rows = filtered_rows.values.tolist()

    if shuffle_list:
        random.shuffle(fault_list_rows)
                
    new_fault_list = deque()

    for vals in fault_list_rows: 
        new_fault_list.append(Fault(*vals[0:8]))

    #print(f"Returning fault list of size {len(new_fault_list)}")
    return new_fault_list


# returs a sublis in baselist
def load_sub_fault_list(base_list: deque[Fault], itv_tuple: Union[int, Tuple[int, int]]) -> deque[Fault]:
    # Ensure itv_tuple is a valid interval
    idx_start, idx_end = (itv_tuple, itv_tuple) if isinstance(itv_tuple, int) else itv_tuple

    # Extract elements manually since deque does not support slicing
    sub_list = deque(list(base_list)[idx_start:idx_end+1]) # [start, end]  

    return sub_list




"""
    Fault injection stuff
"""

# casts the fp tensor to int, so that we inject errors in the integer repr. of the tensor
def safe_cast_to_int(x_float: torch.Tensor, dtype=torch.int32):
    info = torch.iinfo(dtype)
    x = torch.clamp(x_float, info.min, info.max)
    x = x.round()
    return x.to(dtype)


def inject_int_2d_tensor_sw(int_2dtensor, fault):
    assert(len(int_2dtensor.shape) == 2)

    i = fault.x
    j = fault.y
    b = fault.bit

    # removed for opne source
    #if defs.PRUNE_INPUTS:
    #    i = random.randint(0, int_2dtensor.shape[0]-1)
    
    int_2dtensor[i][j] = int_2dtensor[i][j]^(1 << b)

    return int_2dtensor


def inject_int_2d_tensor_class_head_sw(int_2dtensor, fault): 
    assert(len(int_2dtensor.shape) == 2)

    bsize = int_2dtensor.shape[0]
    #return int_2dtensor # sanity checks...

    j = fault.y
    b = fault.bit
    
    for i in range(bsize):
        int_2dtensor[i][j] = int_2dtensor[i][j]^(1 << b)

    return int_2dtensor


"""
shape input tensors (SW):

example with batch size=8 and num_heads=3

layer 0: torch.Size([8, 197, 192])     attention.qkv
layer 1: torch.Size([8, 3, 197, 64])   attention.matmul_1 
layer 2: torch.Size([8, 3, 197, 197])  attention.matmul_2
layer 3: torch.Size([8, 197, 192])     attention.proj
layer 4: torch.Size([8, 197, 192])     block.mlp.fc1
layer 5: torch.Size([8, 197, 768])     block.mlp.fc2
layer 6: torch.Size([8, 192])          model.head
"""

def inject_fp_tensor_sw(fp_tensor_gold, scaling_factor, fault: Fault):
    #if fault.tag == 6050 or fault.tag == 6061 or fault.tag == 6083:
    #return fp_tensor_gold # sanity checks...

    #[COLLECT LAYER SHAPES] - Note: use a dummy.csv fault list first
    #print(f"\n *** shape_layer_sw[{defs.TARGET_LAYER}] = {fp_tensor_gold.shape}");exit(0)

    # get the integer equivalent (no zero points are used so far)
    int_tensor_gold = safe_cast_to_int(fp_tensor_gold/scaling_factor)
    #int_tensor_gold_cp = int_tensor_gold.clone().detach()

    ndim = len(fp_tensor_gold.shape)

    if ndim == 2: # class head
        int_tensor_faulty = inject_int_2d_tensor_class_head_sw(int_tensor_gold, fault)
        
    elif ndim == 3:
        int_tensor_faulty = torch.Tensor(fp_tensor_gold.shape)
        if defs.CUDA: 
            int_tensor_faulty = int_tensor_faulty.to("cuda")
        
        for inp in range(fp_tensor_gold.shape[0]):
            int_tensor_faulty[inp] = inject_int_2d_tensor_sw(int_tensor_gold[inp], fault)    
   
    elif ndim == 4: # layers 1 and 2 (matmul_1 and matmul_2)
        int_tensor_faulty = torch.Tensor(fp_tensor_gold.shape)

        if defs.CUDA: 
            int_tensor_faulty = int_tensor_faulty.to("cuda")

        for inp in range(fp_tensor_gold.shape[0]):
            int_tensor_faulty[inp][fault.att_head] = inject_int_2d_tensor_sw(int_tensor_gold[inp][fault.att_head], fault)
    
    else:
        raise("Invalid tensor shape")

    # multiplies back by the scale, to get the fp version
    return int_tensor_faulty*scaling_factor
    
    
    
    
    
    
    
    
    
    
