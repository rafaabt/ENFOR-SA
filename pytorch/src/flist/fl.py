from src import definitions as defs
from src import sim_options as opt

"""
    Imports the proper fault list source file according to the fault injection setup.
    The fault list modules to be loaded depend on the fault model and type of DNN (CNN or transformer)
"""


#
# load the arg options earlier, before importing the proper fault list managers 
#
opt.set_definitions()

#
# import the global fault list manager file
#
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
