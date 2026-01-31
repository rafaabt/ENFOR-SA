from typing import List
from collections import defaultdict

from .quant_modules import *

from src.gemmini import gemmini_interface as igemm
from src.gemmini import gemmini_config as conf
from src.conv import tile_ops as tile_ops
from src import definitions as defs
from src.flist.fl import fl

fault_list_collision: defaultdict[int, fl.Fault] = defaultdict(fl.Fault)

def gemmini_tile_matmul(A_int, B_int, tile_A_row=0, tile_A_col=0, tile_B_row=0, tile_B_col=0, gemm_fault=None):

        # extract_tile returns type conf.GEMM_INPUT_DTYPE (ints)
        A_tile = tile_ops.extract_tile(A_int, tile_A_row, tile_A_col, conf.DIM)
        B_tile = tile_ops.extract_tile(B_int, tile_B_row, tile_B_col, conf.DIM)

        #gemm_fault = None # [Debug only]: force to None such that we have runs with Gemmini, but without injections
        
        if not defs.RUN_GOLDEN_MODE and gemm_fault != None:
            igemm.gemmini_device.update_fault_list(gemm_fault)

        Out_gemm = igemm.gemmini_device.matmul(A_tile, B_tile)

        Out_gold = A_tile @ B_tile

        return Out_gemm, Out_gold, torch.equal(Out_gemm, Out_gold)


# TODO: pass the block id as parameter instead of fault_list
# if the layer is defs.TARGET_LAYER == 6, we use the head_fault_list fault list
# otherwise we use the fl.att_blocks_flist_map[defs.TARGET_LAYER][blk_id] fault list


def matmul_gemmini(A, pre_act_scaling_factor_A, B, pre_act_scaling_factor_B, fault_list:List[fl.Fault]=None):
    # this casiting causes a lot of trouble - we have critical faults even without injecting
    A_int = (A / pre_act_scaling_factor_A) #.to(torch.int)
    B_int = (B / pre_act_scaling_factor_B) #.to(torch.int)   

    assert(len(A_int.shape) == 4)
    assert(len(B_int.shape) == 4)   

    act_scaling_factor = pre_act_scaling_factor_A * pre_act_scaling_factor_B

    #[COLLECT LAYER SHAPES] - Note: use a dummy.csv fault list first
    #shape = (A_int.shape, B_int.shape); print(f"\nshape_layer[{defs.TARGET_LAYER}] = {shape}");exit(0)

    # attention.matmul_1: torch.Size([8, 3, 197, 64]) torch.Size([8, 3, 64, 197])   ->  shape: [batch size, num_heads, dim-x, dim-y]
    # attention.matmul_2: torch.Size([8, 3, 197, 197]) torch.Size([8, 3, 197, 64])  ->  shape: [batch size, num_heads, dim-x, dim-y]

    mm_output = A_int @ B_int

    # If using CUDA, then we move the tensors to the CPU to edit them
    if defs.CUDA:
        mm_output = mm_output.to("cpu")
        A_int = A_int.to("cpu")
        B_int = B_int.to("cpu")
        #mm_gold = mm_output.to("cpu") # [Debug only]
       
    batch_size = A_int.shape[0]
    
    # do not cast, as it leads to variation in the logits even w/o injection
    #mm_output = mm_output.to(torch.int)

    fault_list_collision.clear()

    for inp in range(batch_size):
        injected_tiles = {}

        for fault in fault_list:
            head = fault.att_head
            tile_key = (fault.tile.a_row, fault.tile.b_col)

            if tile_key not in injected_tiles:
                tile_gemm, tile_gold, masked = gemmini_tile_matmul(A_int[inp][head], 
                                                                   B_int[inp][head], 
                                                                   tile_A_row=fault.tile.a_row, 
                                                                   tile_A_col= fault.tile.a_col, 
                                                                   tile_B_row=fault.tile.b_row, 
                                                                   tile_B_col=fault.tile.b_col, 
                                                                   gemm_fault=fault.gemm)

                if not masked:
                    # assure sub_tile does not cast the mm_output
                    mm_output[inp][head] = tile_ops.sub_tile(mm_output[inp][head], tile_gold, fault.tile.a_row, fault.tile.b_col, conf.DIM)  
                    mm_output[inp][head] = tile_ops.sum_tile(mm_output[inp][head], tile_gemm, fault.tile.a_row, fault.tile.b_col, conf.DIM) 
                
                #masked_all = masked_all and masked
                injected_tiles[tile_key] = 1
            
            else:
                #print("Collision")
                fault_list_collision[fault.tag] = fault
        #print(f"Masked all: {masked_all}")

    col = len(fault_list_collision)
    #colr = col/total_faults if total_faults != 0 else 0
    #print(f"Collison rate: {100*colr:.2f}%")
    
    if col: # append collide faults back to the list
        fl.fault_list.extend(fault_list_collision.values())

    #mm_gold = (A_int @ B_int).to(torch.int) # [Debug only]
    #print(f"all masked: {torch.equal(mm_output, mm_gold)}")
    
    if defs.CUDA:
        mm_output = mm_output.to("cuda")

    return mm_output


def linear_gemmini(x_int, weight_integer, bias_integer, fault_list:List[fl.Fault]=None):
    batch_size = x_int.shape[0]   

    weight_integer_t = (weight_integer.transpose(0, 1)) # this will become non-contiguous

    #[COLLECT LAYER SHAPES] - Note: use a dummy.csv fault list first
    #shape = (x_int.shape, weight_integer_t.shape); print(f"\nshape_layer[{defs.TARGET_LAYER}] = {shape}");exit(0)

    linear_output = F.linear(x_int, weight=weight_integer, bias=bias_integer) 
    #linear_gold = F.linear(x_int, weight=weight_integer, bias=bias_integer) # [Debug only]

    # If using CUDA, then we move the tensors to the CPU to edit them
    if defs.CUDA:
        linear_output = linear_output.to("cpu")
        x_int = x_int.to("cpu")
        weight_integer = weight_integer.to("cpu")

    # casting this leads to variation in the logits even without injection. do not cast!!!
    #linear_output = linear_output.to(torch.int)

    fault_list_collision.clear()

    #total_faults = len(fault_list) if fault_list else 0

    if len(x_int.shape) == 3:  # x_int shape torch.Size([8, 197, 192])  -  attention.qkv,  att.proj, blk.mlp.fc1 and blk.mlp.fc2
        for inp in range(batch_size):
            injected_tiles = {}
            #all_masked = True #[Debug only]

            for fault in fault_list:
                #head = fault.att_head
                tile_key = (fault.tile.a_row, fault.tile.b_col)

                if tile_key not in injected_tiles:
                    tile_key = (fault.tile.a_row, fault.tile.b_col)

                    tile_gemm, tile_gold, masked = gemmini_tile_matmul(x_int[inp], 
                                                                       weight_integer_t, 
                                                                       tile_A_row=fault.tile.a_row, 
                                                                       tile_A_col=fault.tile.a_col, 
                                                                       tile_B_row=fault.tile.b_row, 
                                                                       tile_B_col=fault.tile.b_col, 
                                                                       gemm_fault=fault.gemm)

                    if not masked:
                        # important: sub_tile and sum_tile do not perform any casing, as it should be...
                        linear_output[inp] = tile_ops.sub_tile(linear_output[inp], tile_gold, fault.tile.a_row, fault.tile.b_col, conf.DIM)
                        linear_output[inp] = tile_ops.sum_tile(linear_output[inp], tile_gemm, fault.tile.a_row, fault.tile.b_col, conf.DIM)
                        
                    injected_tiles[tile_key] = 1
                    #all_masked = all_masked and masked
                else:
                    #print("Collision")
                    fault_list_collision[fault.tag] = fault
            #print(f"all_masked: {all_masked}")

    else: # x_int shape torch.Size([8, 192]. -  self.model.head. TODO: Fix this too. fault.tile.a_row depends on the batch size...
        injected_tiles = {}

        for fault in fault_list:

            fault.tile.a_row = fault.tile.a_row%batch_size # Attempt to solve the class head issue (as described in the models/layers/deit_tiny.py file)

            tile_key = (fault.tile.a_row, fault.tile.b_col)  

            if tile_key not in injected_tiles:
                tile_gemm, tile_gold, masked = gemmini_tile_matmul(x_int, 
                                                                   weight_integer_t,
                                                                   tile_A_row=fault.tile.a_row, 
                                                                   tile_A_col=fault.tile.a_col, 
                                                                   tile_B_row=fault.tile.b_row, 
                                                                   tile_B_col=fault.tile.b_col, 
                                                                   gemm_fault=fault.gemm)

                if not masked:
                    # assure sub_tile does not cast linear_output
                    linear_output = tile_ops.sub_tile(linear_output, tile_gold, fault.tile.a_row, fault.tile.b_col, conf.DIM)
                    linear_output = tile_ops.sum_tile(linear_output, tile_gemm, fault.tile.a_row, fault.tile.b_col, conf.DIM)
                
                injected_tiles[tile_key] = 1
            else:
                fault_list_collision[fault.tag] = fault

    col = len(fault_list_collision)
    #colr = col/total_faults if total_faults != 0 else 0
    #print(f"Collison rate: {100*colr:.2f}%")
    
    if col: # append collide faults back to the list
        fl.fault_list.extend(fault_list_collision.values())
    
    if defs.CUDA:
        linear_output = linear_output.to("cuda")

    return linear_output


class QuantMatMulGemmini(QuantMatMul):
    """
    Class to quantize weights of given matmul layer
    """
    def __init__(self):
        super(QuantMatMulGemmini, self).__init__()

    def forward(self, A, pre_act_scaling_factor_A, B, pre_act_scaling_factor_B, fault_list:List[fl.Fault]=None):

        # if we're running sw injections, than there's nothing for us to do here in this layer (x was injected in the upper layers, in sw)
        # TODO: actually in SW there's no layer replacement (as we use input hooks), so this QuantMatMulGemmini module should even be called (see if we need this if)
        if defs.FI_SW:
            return super().forward(A, pre_act_scaling_factor_A, B, pre_act_scaling_factor_B)

        if not hasattr(fl, "next_fault"): #  no faults yet. this is the calibration phase, before the fault list is loaded
            return super().forward(A, pre_act_scaling_factor_A, B, pre_act_scaling_factor_B)
        
        # if there's no fault in the list, then it means this is not a target block for fault injection, and we return the golden function
        # explanation:
        # in the tree mode, the fault nodes have any types of faults, any layers and any blocks
        # the fault list for each layer/block is loaded in the beginning, from the base fault list (or subfault list for child nodes)
        # this means that for this particular layer/block pair, there's no certainty that there's going to be a fault to be injected
        if len(fault_list) == 0:
            return super().forward(A, pre_act_scaling_factor_A, B, pre_act_scaling_factor_B)

        act_scaling_factor = pre_act_scaling_factor_A * pre_act_scaling_factor_B
        self.act_scaling_factor = act_scaling_factor

        mm_output = matmul_gemmini(A, pre_act_scaling_factor_A, B, pre_act_scaling_factor_B, fault_list)

        # original
        #return (A_int @ B_int) * act_scaling_factor, act_scaling_factor
        return mm_output*act_scaling_factor, act_scaling_factor


class QuantLinearGemmini(QuantLinear):
    """
    Class to quantize weights of given Linear layer

    Parameters:
    ----------
    weight_bit : int
        Bitwidth for quantized weights.
    bias_bit : int, default None
        Bitwidth for quantized bias.
    per_channel : bool, default False
        Whether to use channel-wise quantization.
    quant_mode : 'none' or 'symmetric', default 'none'
        The mode for quantization. 'none' for no quantization.
    """

    def __init__(self,
                 in_features,
                 out_features,
                 bias=True,
                 weight_bit=8,
                 bias_bit=32,
                 per_channel=True,
                 quant_mode='symmetric'):

        super(QuantLinearGemmini, self).__init__(in_features, out_features, bias)


    def forward(self, x, prev_act_scaling_factor=None, fault_list:List[fl.Fault]=None):

        # if we're running sw injections, than there's nothing for us to do here in this layer (x was injected in the upper layers, in sw)
        if defs.FI_SW:
            return super().forward(x, prev_act_scaling_factor)

        if not hasattr(fl, "next_fault"): # this is the calibration phase, before the fault list is loaded
            # original
            #return F.linear(x_int, weight=self.weight_integer, bias=self.bias_integer)* bias_scaling_factor, bias_scaling_factor

            return super().forward(x, prev_act_scaling_factor)
  
        # if there's no fault in the list, then it means this is not a target block for fault injection, and we return the golden function
        # explanation:
        # in the tree mode, the fault nodes have any types of faults, any layers and any blocks
        # the fault list for each layer/block is loaded in the beginning, from the base fault list (or subfault list for child nodes)
        # this means that for this particular layer/block pair, there's no certainty that there's going to be a fault to be injected
        if len(fault_list) == 0:
            return super().forward(x, prev_act_scaling_factor)

        with torch.no_grad():
            w = self.weight
            if self.per_channel:
                v = w.reshape(w.shape[0], -1)
                cur_min = v.min(axis=1).values
                cur_max = v.max(axis=1).values
                self.min_val = cur_min
                self.max_val = cur_max
            else:
                raise Exception('For weight, we only support per_channel quantization.')

            self.fc_scaling_factor = symmetric_linear_quantization_params(
                self.weight_bit, self.min_val, self.max_val)

        self.weight_integer = self.weight_function(
            self.weight, self.weight_bit, self.fc_scaling_factor, True)

        bias_scaling_factor = self.fc_scaling_factor * prev_act_scaling_factor

        if self.bias is not None:
            self.bias_integer = self.weight_function(
                self.bias, self.bias_bit, bias_scaling_factor, True)
        else:
            self.bias_integer = None

        prev_act_scaling_factor = prev_act_scaling_factor.view(1, -1)
        x_int = x / prev_act_scaling_factor

        linear_output = linear_gemmini(x_int, self.weight_integer, self.bias_integer, fault_list)
        #linear_output_gold = F.linear(x_int, weight=self.weight_integer, bias=self.bias_integer) # [Debug only]


        #r1 = linear_output*bias_scaling_factor
        #r2 = linear_output_gold*bias_scaling_factor
        #print(torch.allclose(r1,r2))
        #print(linear_output_gold)
        #print(f"MASKED: {torch.equal(linear_output.to(torch.int), linear_output_gold.to(torch.int))}")
        return linear_output*bias_scaling_factor, bias_scaling_factor
