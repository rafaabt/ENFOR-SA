#
# OS CONFIGS
#
#CONFIG=CustomGemminiOSTinySoCConfig
CONFIG=CustomGemminiOSMediumSoCConfig
#CONFIG=CustomGemminiOSBigSoCConfig
#CONFIG=CustomGemminiOSHugeSoCConfig
#CONFIG=CustomGemminiOSMediumFTSoCConfig
#CONFIG=CustomGemminiOSDIM64SoCConfig

#CONFIG=CustomGemminiOSTinySoCConfig_RTL_HDFIT
#CONFIG=CustomGemminiOSMediumSoCConfig_RTL_HDFIT
#CONFIG=CustomGemminiOSMediumSoCConfig_GL_HDFIT

#
# WS CONFIGS
#
#CONFIG=CustomGemminiWSTinySoCConfig
#CONFIG=CustomGemminiWSMediumSoCConfig

MODE=GEMM_OS
#MODE=GEMM_WS

FI_LEVEL=USE_RTL_INJECTION
#FI_LEVEL=USE_GL_INJECTION

# can also just pass:  make CONFIG=CustomGemminiOSMediumSoCConfig

# The target verilated module
MODULE=VMesh__ALL

# The root dir
ROOT:=$(abspath ../../../)

# The location of the verilator's include path (if VERILATOR_ROOT is set, the path will be $VERILATOR_ROOT/include)
VERILATOR_INC_PATH=/usr/local/share/verilator/include

# this works well too
#VERILATOR_INC_PATH = ${ROOT}/rtl/lib/verilator-include/include

# The location of the verilated objects (e.g., verilated.o and VMesh__ALL.a)
VERILATED_MODULE_PATH=${ROOT}/rtl/verilated/${CONFIG}

# Verilated Mesh module
MESH_MODULE=${VERILATED_MODULE_PATH}/${MODULE}.a

# The verilated.o object file
VERILATED_O = ${VERILATED_MODULE_PATH}/verilated.o
