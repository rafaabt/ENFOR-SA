//#include "../../../../../verilated/CustomGemminiOSDIM64SoCConfig/ClusterLoader.h"
#include "../../../../../verilated/CustomGemminiOSDIM64SoCConfig/VMesh.h"
#include "../../../../../verilated/CustomGemminiOSDIM64SoCConfig/VMesh___024root.h"

#define GEMM_CONFIG_ALIAS "Gemmini-OS-DIM64"

#define DIM 64

/*
using char data type is causing issues in the PyTorch ext lib:

run: c++filt _ZNK2at10TensorBase8data_ptrIcEEPT_v
output: char* at::TensorBase::data_ptr<char>() cons
*/


#define Input_t int //char 
#define Output_t int //char
