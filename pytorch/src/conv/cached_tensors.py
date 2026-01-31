import torch
import os
import torch.nn.functional as F
from torch._ops import ops
from collections import defaultdict
from src.conv import flattener as flattener
from src import definitions as defs


DO_USE_LUTS = True


gl_lut_inputs_int_repr = {}
conv_ofm_lut = {}
conv_batch_ofm_lut = {}

def load_cached_inputs(conv_model, input_tensor, input_id):
    global gl_lut_inputs_int_repr

    # we load the extracted int representation of the inputs from the cache, if available
    if DO_USE_LUTS:
        # if the luts are available
        if input_id in gl_lut_inputs_int_repr:
            return gl_lut_inputs_int_repr[input_id]

        gl_lut_inputs_int_repr[input_id] = flattener.im2col_quant(conv_model, input_tensor)
        
        return gl_lut_inputs_int_repr[input_id]

    return flattener.im2col_quant(conv_model, input_tensor)
  

# this returns gold_tensor = ops.quantized.conv2d(input_tensor, conv_model._packed_params, conv_model.scale, conv_model.zero_point)
def load_conv_ofm(input_id, conv_model, input_tensor):
    global conv_ofm_lut

    if DO_USE_LUTS:
        if input_id in conv_ofm_lut:
            return conv_ofm_lut[input_id]
        
        conv_ofm_lut[input_id] = ops.quantized.conv2d(input_tensor, conv_model._packed_params, conv_model.scale, conv_model.zero_point)
        return conv_ofm_lut[input_id]
    
    if input_tensor.is_quantized:
        return ops.quantized.conv2d(input_tensor, conv_model._packed_params, conv_model.scale, conv_model.zero_point)
    return conv_model(input_tensor)



# this returns gold_tensor = ops.quantized.conv2d(input_tensor, conv_model._packed_params, conv_model.scale, conv_model.zero_point)
def load_conv_batch_ofm(batch_id, conv_model, input_batch_tensor):
    global conv_batch_ofm_lut

    if DO_USE_LUTS:
        if batch_id in conv_batch_ofm_lut:
            return conv_batch_ofm_lut[batch_id]
    
        conv_batch_ofm_lut[batch_id] = ops.quantized.conv2d(input_batch_tensor, conv_model._packed_params, conv_model.scale, conv_model.zero_point)
        return conv_batch_ofm_lut[batch_id]
    
    if input_batch_tensor[0].is_quantized:
        return ops.quantized.conv2d(input_batch_tensor, conv_model._packed_params, conv_model.scale, conv_model.zero_point)
    return conv_model(input_batch_tensor)




# this empties all lusts. call this before running a new input batch
def clear_luts():
    global gl_lut_weights_int_repr
    global gl_lut_inputs_int_repr

    gl_lut_inputs_int_repr.clear()
    conv_ofm_lut.clear()
    conv_batch_ofm_lut.clear()

