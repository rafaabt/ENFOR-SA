import argparse
import torch
from src import definitions as defs


"""
    Imports the proper fault list source file according to the fault injection setup.
    The fault list modules to be loaded depend on the fault model and type of DNN (CNN or transformer)

    The fault list structure is different for RTL/SW and ViT/CNNs:
        1. RTL fault lists:
            1.1. CNN: fault_list.py
            1.2. ViT: fault_list_vit.py
        2. SW fault list:
            2.1. CNN: fault_list_sw.py
            2.2. ViT: fault_list_vit_sw.py
"""

vit_models = ["deit_tiny", "deit_small", "deit_base",
              "swin_tiny", "swin_small", "swin_base",
              "vit_base", "vit_large"]

# load these two arg options earlier, because i need them before loading the right fault list source file 
early_parser = argparse.ArgumentParser(add_help=False)
early_parser.add_argument("-m", "--model",  type=str, default=defs.MODEL_NAME,    help="The DNN model name")
early_parser.add_argument("-F", "--fmodel", choices=["sw", "rtl"], default="rtl", help="The fault model")
early_args, remaining_argv = early_parser.parse_known_args()

# set the default args
# check if we need Gemmini for RTL injection or not
defs.FI_GEMM = True if early_args.fmodel == "rtl" else False
# check if the model is any transformer model, and asserts defs.VIT if True
defs.VIT = True if early_args.model in vit_models else False
# use CUDA only for the ViT models iff there's a GPU available
defs.CUDA = torch.cuda.is_available() if defs.VIT else False
# use cuda if we can (ViTs only)
defs.DEVICE = "cuda" if defs.CUDA else "cpu"
# SW fault injection mode. just an inverted alias...
defs.FI_SW = not defs.FI_GEMM
# removed for open source
#defs.ENABLE_GL_FAULT_MODEL = True if early_args.fmodel == "gl" else False

# import the global fault list manager file
if defs.FI_GEMM:
    if defs.VIT: 
        import src.flist.fault_list_vit as fl 
    else: 
       import src.flist.fault_list as fl

else:
    if defs.VIT: 
        import src.flist.fault_list_vit_sw as fl 
    else: 
        import src.flist.fault_list_sw as fl
