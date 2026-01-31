# a hardcoded script to run verilator and generate the verilated code for a target verilog design

#
# SRC: the src of the top verilog module
#
SRC="Mesh.sv"

CONFIG=$1

# Gemmini configs
#CONFIG=CustomGemminiOSTinySoCConfig
#CONFIG=CustomGemminiOSTinySoCConfig_RTL_HDFIT

#CONFIG=CustomGemminiOSMediumSoCConfig
#CONFIG=CustomGemminiOSMediumSoCConfig_RTL_HDFIT

#CONFIG=CustomGemminiOSBigSoCConfig
#CONFIG=CustomGemminiOSBigSoCConfig_RTL_HDFIT

#CONFIG=CustomGemminiOSHugeSoCConfig
#CONFIG=CustomGemminiOSHugeSoCConfig_RTL_HDFIT

#CONFIG=CustomGemminiOSDIM64SoCConfig
#CONFIG=CustomGemminiOSDIM64SoCConfig_RTL_HDFIT

#CONFIG=CustomGemminiWSTinySoCConfig
#CONFIG=CustomGemminiWSMediumSoCConfig


#
# DESIGN_PATH: the path containing the verilog modules
#
DESIGN_PATH=./designs/$CONFIG

#
# the verilated output path
# 
VERILATED_OBJ_PATH=verilated/$CONFIG

# touch the verilog src to force verilator to always re-generate and compile the verilated code
touch "$DESIGN_PATH/$SRC"

MAIN=main.cpp
#MAIN="../"$DESIGN_PATH"/main.cpp" 

# run verilator
# if to enable VCD tracing, use the flag --trace and use "#define VCD 1" in rtl/lib/Gemmini/headers/config.h)
#

# if using single-threaded verilator
verilator -CFLAGS "-O3 -fPIC" --output-split 0 --flatten --cc --exe --build $MAIN --Mdir $VERILATED_OBJ_PATH -I$DESIGN_PATH $SRC

# if using multithreded verilator:
#verilator -CFLAGS "-O3 -fPIC -std=c++17" --output-split 0 --threads 4 --flatten --cc --exe --build $MAIN --Mdir $VERILATED_OBJ_PATH -I$DESIGN_PATH $SRC

