//#include "../../../../../verilated/CustomGemminiOSDIM64SoCConfig_RTL_HDFIT/ClusterLoader.h"
#include "../../../../../verilated/CustomGemminiOSDIM64SoCConfig_RTL_HDFIT/VMesh.h"
#include "../../../../../verilated/CustomGemminiOSDIM64SoCConfig_RTL_HDFIT/VMesh___024root.h"

#define GEMM_CONFIG_ALIAS "CustomGemminiOSDIM64SoCConfig_RTL_HDFIT"




#define DIM 64

/*
using char data type is causing issues in the PyTorch ext lib:

run: c++filt _ZNK2at10TensorBase8data_ptrIcEEPT_v
output: char* at::TensorBase::data_ptr<char>() cons
*/


#define Input_t int //char 
#define Output_t int //char
