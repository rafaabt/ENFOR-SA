import torch
import sys
import random

import src.definitions as defs
from src.models.instrumented_model import InstrumentedModel
from src.models.base_model import BaseModel
import src.utils.dataset_loader as dataloader
import src.experiment.experiment_sequential as exp_seq
import src.experiment.experiment as exp
import src.sim_options as simopt
import src.utils.utils as u
from collections import defaultdict


def init():

    simopt.parse_args()

    print(f"{u.Co['fg'][65]}[Setting threads]:{u.R}\n- Inter:  {defs.N_INTER_THREADS}\n- Intra:  {defs.N_INTRA_THREADS}\n- Device: {defs.DEVICE}\n")

    #torch.use_deterministic_algorithms(True)
    torch.set_num_interop_threads(defs.N_INTER_THREADS)
    torch.set_num_threads(defs.N_INTRA_THREADS)

    random.seed(defs.SEED)
    torch.manual_seed(defs.SEED)
    torch.cuda.manual_seed(defs.SEED)

    dataloader.load_dataset_imagenet()


def main():
    init()

    model_golden = BaseModel(defs.MODEL_NAME)
    model_faulty = InstrumentedModel(defs.MODEL_NAME)
    
    experiment = exp_seq.ExperimentSequential(model_faulty=model_faulty, 
                                              model_golden=model_golden) 

    #generates a random set of indices. inputs are loaded from the dataset based on the indices
    input_indices = u.random_indices(size=defs.BATCHES*defs.BATCH_SIZE, 
                                     max=dataloader.dataset_len-1)

    critical_faults = experiment.run_experiment(input_indices)

    return 0


if __name__ == '__main__':
    u.register_sig_handlers()
    sys.exit(main())












































# Backup

"""
# backup - random stuff
runner.test_all_models(dataset_input_idx)
runner.measure_perf(model, dataset_input_idx)
runner.measure_similarity(model_golden)
runner.debug_sym_tracing(model_golden)
tensor, _ = datasetld.get_input(4)
traced = symbolic_trace(model.model)
traced(tensor)
"""


""" 
input_tensor = torch.randn(1, 3, 224, 224)  # (batch_size, channels, height, width)

torch.onnx.export(
    model,                       # The model being exported
    input_tensor,                 # A sample input for the model
    "resnet18-replaced.onnx",             # The output file path for the ONNX model
    export_params=True,          # Store the trained parameter weights inside the model file
    opset_version=11,            # ONNX version to export the model to
    do_constant_folding=True,    # Whether to execute constant folding for optimization
    input_names=['input'],       # Name of the input layer(s)
    output_names=['output'],     # Name of the output layer(s)
    dynamic_axes={'input': {0: 'batch_size'}, 'output': {0: 'batch_size'}}  # Dynamic batch size support
)
"""

"""
def conv2d_as_matmul(conv_obj, input_tensor): 
    conv_weight = conv_obj.weight()
    bias        = conv_obj.bias()
    kernel_size = conv_obj.kernel_size
    stride      = conv_obj.stride
    padding     = conv_obj.padding
    dilation    = conv_obj.dilation
    return ops.quantized.conv2d(input_tensor, conv_obj._packed_params, conv_obj.scale, conv_obj.zero_point)


class Replacer(fx.Transformer):
    def call_module(self, target, args, kwargs):
        # Check if the target is an instance of quantized Conv2d
        if isinstance(self.submodules[target], torch.nn.quantized.Conv2d):
            print(f"Replacing quantized {target} with custom_quant_conv")
            return conv2d_as_matmul(self.submodules[target], *args)  # Call custom function
        return super().call_module(target, args, kwargs)
"""
