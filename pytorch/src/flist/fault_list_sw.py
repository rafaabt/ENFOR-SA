import torch
import random
import csv
import os
import random
import pandas as pd
import src.definitions as defs

from dataclasses import dataclass
from collections import deque
from typing import Deque, List, Union, Tuple, Optional
from src.utils import utils as u

@dataclass
class Fault:
    tag: int      # the fault tag
    layer_id: int # the layer the fault is attributed to
    target: int   # activations or weights
    N: int        # for inputs, N = #batches. for weights, N = #filters
    C: int        # input channels
    H: int        # kernel or input/activation height
    W: int        # kernel or input/activation width
    bit: int      # the target bit in the target bit in the tensor

    def __str__(self):
        return f"Tag {self.tag} - Layer: {self.layer_id} - Target: {self.N} - Channel: {self.C} - Pos: [{self.H}, {self.W}] - Bit: {self.bit}"

# this is the global fault list used for each fault injection trial
# load this with fault_list = load_fault_list(<file name>, (start line, end line))
fault_list = deque[Fault]

# marks the next fault is a leaf node
next_fault_is_leaf = False

# marks the next fault (for sequential fault injection)
next_fault: Fault



# a tensor fault. defined a position for tensors of shape (N, C, H, W)
# generates a random fault
def gen_random_fault(shape_tensor: Tuple[int, int], layer_id: int=0, target: int=0) -> Fault:  
    bits = 8

    N, C, H, W = shape_tensor

    # the random target positions
    N_tgt = random.randint(0, N-1)  # for faults in the inputs, this is ignored. for faults in the weights, this represents which filter is affected
    C_tgt = random.randint(0, C-1)  # for faults in the inputs or weights: this represetns which channel is affected
    H_tgt = random.randint(0, H-1)
    W_tgt = random.randint(0, W-1)
    bit   = random.randint(0, bits-1)

    return Fault(42, layer_id, target, N_tgt, C_tgt, H_tgt, W_tgt, bit)


# returns a random fault list
def generate_fault_list(layer_id, 
                        shape_tensor, 
                        start_tag=0, 
                        max_faults=10000, 
                        target=0) -> List[Fault]:
    # use a fixed random if required
    random.seed(42)

    new_fault_list = []
    l = 0

    while l < max_faults:
        new_fault = gen_random_fault(shape_tensor, layer_id, target)
        new_fault.tag = start_tag + l
        new_fault_list.append(new_fault)
        l += 1

    return new_fault_list


# dumps the fault list to a file. must have a folder "fault_lists"
def dump_fault_list (flist: List[Fault], fn="default_fault_list.csv"):
    filename = f"./fault_lists/{fn}"

    header = ['tag', 'layer', 'target', 'N', 'C', 'H', 'W', 'bit']

    #print(f"Dumping fault list to file {filename} - size {len(flist)}")

    with open(filename, mode='w', newline='') as file:
        writer = csv.writer(file, delimiter='\t')
        writer.writerow(header)

        for fault in flist:
            csv_row = [fault.tag, fault.layer_id, fault.target, fault.N, fault.C, fault.H, fault.W, fault.bit]
            writer.writerow(csv_row)

    print(f"Saved fault list: {fn}  -  Size: {len(flist)} rows")


# loads the fault list in a given line range (line zero is always skipped)
# the list is read from the file created by the generate_fault_list() function
# the fault list is returned in form of a deque
#def load_fault_list(fn_list: str, itv_tuple: Union[int, Tuple[int, int]], shuffle_list=False) -> deque[Fault]: # itvl tuple = (row_start, row_end)
def load_fault_list(fn_list: str, 
                    itv_tuple: Union[int, Tuple[int, int]], # itvl tuple = (row_start, row_end)
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

    #print(f"Returns sub list of size: {len(sub_list)} -> itv: {itv_tuple} = {idx_start}, {idx_end}")
    return sub_list





# Fault injection stuff


# receives a batch of input tensors, and injects the same fault in every input
# a tensor fault. defined a position for tensors of shape (N, C, H, W)
# weights.shape: torch.Size([64, 3, 7, 7])    -> [#filters][#channels][h][w]
# input.shape:   torch.Size([1, 3, 224, 224]) -> [#baches][#channels][h][w]
def tensor_fi_input_batch_quantized(tensor: torch.Tensor) -> torch.Tensor:
    if len(tensor.shape) != 4:
        raise ValueError("Input shape must be `(N, C, H, W)`!")

    input_int = tensor.int_repr()

    batches = tensor.shape[0]
    C_tgt = next_fault.C
    H_tgt = next_fault.H
    W_tgt = next_fault.W

    for i in range(batches):
        input_int[i][C_tgt][W_tgt][H_tgt] = input_int[i][C_tgt][W_tgt][H_tgt]^(1 << next_fault.bit)

    return torch._make_per_tensor_quantized_tensor(input_int, scale=tensor.q_scale(), zero_point=tensor.q_zero_point())


def tensor_fi_input_batch_quantized_all_list(tensor: torch.Tensor) -> torch.Tensor:
    if len(tensor.shape) != 4:
        raise ValueError("Input shape must be `(N, C, H, W)`!")

    batches = tensor.shape[0]
    input_int = tensor.int_repr()
    batch_len = tensor.shape[0]
    injected = {}

    while fault_list: # reads the next fault in the list
        fault = fault_list.popleft()
        
        key = (fault.C, fault.H, fault.W)

        if key in injected:
            continue

        injected[key] = 1
        C_tgt = fault.C
        H_tgt = fault.H
        W_tgt = fault.W

        for i in range(batches):
            input_int[i][C_tgt][W_tgt][H_tgt] = input_int[i][C_tgt][W_tgt][H_tgt]^(1 << fault.bit)
    
    return torch._make_per_tensor_quantized_tensor(input_int, scale=tensor.q_scale(), zero_point=tensor.q_zero_point())


# receives a single weight tensor, and injects the fault in the position taken from the fault list
# here, the number of "`" means the number of filters in the weight. the fault injection targets a single filter, in a single channel position
def tensor_fi_weight_quantized(weight: torch.Tensor) -> torch.Tensor:
    if len(weight.shape) != 4:
        raise ValueError("Input shape must be `(N, C, H, W)`!")

    weight_int = weight.int_repr()
    batch_len = weight.shape[0]

    N_tgt = next_fault.N
    C_tgt = next_fault.C
    H_tgt = next_fault.H
    W_tgt = next_fault.W

    weight_int[N_tgt][C_tgt][W_tgt][H_tgt] = weight_int[N_tgt][C_tgt][W_tgt][H_tgt]^(1 << next_fault.bit)

    return torch._make_per_tensor_quantized_tensor(weight, scale=weight.q_scale(), zero_point=weight.q_zero_point())


def tensor_fi_weight_quantized_all_list(weight: torch.Tensor) -> torch.Tensor:
    global fault_list
    if len(weight.shape) != 4:
        raise ValueError("Input shape must be `(N, C, H, W)`!")

    weight_int = weight.int_repr()
    batch_len = weight.shape[0]

    injected = {}

    while fault_list: # reads the next fault in the list
        fault = fault_list.popleft()
       
        key = (fault.C, fault.H, fault.W)

        if key in injected:
            continue

        injected[key] = 1

        N_tgt = fault.N
        C_tgt = fault.C
        H_tgt = fault.H
        W_tgt = fault.W

        weight_int[N_tgt][C_tgt][W_tgt][H_tgt] = weight_int[N_tgt][C_tgt][W_tgt][H_tgt]^(1 << fault.bit)

    return torch._make_per_tensor_quantized_tensor(weight_int, scale=weight.q_scale(), zero_point=weight.q_zero_point())