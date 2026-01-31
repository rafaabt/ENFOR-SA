from src.gemmini import gemmini_config as conf
from src.utils import utils as u
from src import definitions as defs


# this file defines a global filter for the fault injection target (fault_target below)
# the target is defined the column attributes in a fault list
# currently the fault list for CNN models + RTL is defined according to the header:
#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
# tag   layer   tile_a_row  tile_a_col  tile_b_row  tile_b_col  target  pe_row  pe_col  bit cell
#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

# fault targets are configured with a customized filter on the rows of the fault list, as shown in the examples below
# if a filter value is not set, it's ignored. e.g., by not setting the 'bit' value, all bits are considered for fault injection

ANY, NONE, ITVL, SIGNAL = u.ANY, u.NONE, u.ITVL, conf.SIGNAL

example_generic_target = {
	#
	# the target conv layer (QuantizedConv2d, QuantizedConvReLU2d, etc...)
	#
    'layer': 2, # only layer 2 considered
    
	#
    # target PE position
    #
    'pe_row': 0, # targets only PEs of row 0
    'pe_col':(NONE, [0, 3, 5]), # e.g., excludes PE cols 0, 3 and 5

    #
    # the target bit in each PE
    #
    'bit': (ANY, [0, 3, 5]),  # e.g., injects only only in bits 0, 3 and 5

    #
    # the target signal in each PE (inputs, outputs or ctrl signals)
    #
    'target': (ANY, [SIGNAL["IN_A"][0], SIGNAL["IN_B"][0]]), # inject only in the PE inputs
	#'target': SIGNAL["OUT_C"][0], # inject only in the PE outputs
    #'target': (ANY, [SIGNAL["SIG_PROPAG"][0], SIGNAL["SIG_VALID"][0], SIGNAL["SIG_DATAFLOW"][0]]), # inject only control signals
}

target_inputs_lsb = {
    'bit': 0,
    'target': (ANY, [SIGNAL["IN_A"][0], SIGNAL["IN_B"][0]])
}

target_output_msb = {
    'bit': 7,
    'target': SIGNAL["OUT_C"][0]
}

target_inputs = {
    'target': (ANY, [SIGNAL["IN_A"][0], SIGNAL["IN_B"][0]])
}

target_outputs = {
    'target': SIGNAL["OUT_C"][0]
}

target_control = {
    #'target': (ANY, [SIGNAL["SIG_VALID"][0]])
    #'target': (ANY, [SIGNAL["SIG_PROPAG"][0]])
    'target': (ANY, [SIGNAL["SIG_PROPAG"][0], SIGNAL["SIG_VALID"][0]]) # inject only control signals
}

# SW only filters
target_sw_weights = {
    'target': 0
}

target_sw_activation = {
    'target': 1
}

fault_target = target_outputs

# fault_target this is the GLOBAL fault target used across all simulations.
# the fault target filter. the default target layer config must be overwritten with the desired target option (--layer option) 
def setup_target():
    global fault_target

    if defs.FI_GEMM:  # RTL injections in selected signal types
        #fault_target = target_inputs
        fault_target = target_outputs
        #fault_target = target_control
    else: # SW injections in activations only
        fault_target = target_sw_activation
    
    fault_target['layer'] = defs.TARGET_LAYER 
