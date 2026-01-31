// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VMESH_H_
#define VERILATED_VMESH_H_  // guard

#include "verilated.h"

class VMesh__Syms;
class VMesh___024root;

// This class is the main interface to the Verilated model
class VMesh VL_NOT_FINAL {
  private:
    // Symbol table holding complete model state (owned by this class)
    VMesh__Syms* const vlSymsp;

  public:

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(&clock,0,0);
    VL_IN8(&io_in_control_0_0_dataflow,0,0);
    VL_IN8(&io_in_control_0_0_propagate,0,0);
    VL_IN8(&io_in_control_0_0_shift,4,0);
    VL_IN8(&io_in_control_1_0_dataflow,0,0);
    VL_IN8(&io_in_control_1_0_propagate,0,0);
    VL_IN8(&io_in_control_1_0_shift,4,0);
    VL_IN8(&io_in_control_2_0_dataflow,0,0);
    VL_IN8(&io_in_control_2_0_propagate,0,0);
    VL_IN8(&io_in_control_2_0_shift,4,0);
    VL_IN8(&io_in_control_3_0_dataflow,0,0);
    VL_IN8(&io_in_control_3_0_propagate,0,0);
    VL_IN8(&io_in_control_3_0_shift,4,0);
    VL_IN8(&io_in_control_4_0_dataflow,0,0);
    VL_IN8(&io_in_control_4_0_propagate,0,0);
    VL_IN8(&io_in_control_4_0_shift,4,0);
    VL_IN8(&io_in_control_5_0_dataflow,0,0);
    VL_IN8(&io_in_control_5_0_propagate,0,0);
    VL_IN8(&io_in_control_5_0_shift,4,0);
    VL_IN8(&io_in_control_6_0_dataflow,0,0);
    VL_IN8(&io_in_control_6_0_propagate,0,0);
    VL_IN8(&io_in_control_6_0_shift,4,0);
    VL_IN8(&io_in_control_7_0_dataflow,0,0);
    VL_IN8(&io_in_control_7_0_propagate,0,0);
    VL_IN8(&io_in_control_7_0_shift,4,0);
    VL_IN8(&io_in_control_8_0_dataflow,0,0);
    VL_IN8(&io_in_control_8_0_propagate,0,0);
    VL_IN8(&io_in_control_8_0_shift,4,0);
    VL_IN8(&io_in_control_9_0_dataflow,0,0);
    VL_IN8(&io_in_control_9_0_propagate,0,0);
    VL_IN8(&io_in_control_9_0_shift,4,0);
    VL_IN8(&io_in_control_10_0_dataflow,0,0);
    VL_IN8(&io_in_control_10_0_propagate,0,0);
    VL_IN8(&io_in_control_10_0_shift,4,0);
    VL_IN8(&io_in_control_11_0_dataflow,0,0);
    VL_IN8(&io_in_control_11_0_propagate,0,0);
    VL_IN8(&io_in_control_11_0_shift,4,0);
    VL_IN8(&io_in_control_12_0_dataflow,0,0);
    VL_IN8(&io_in_control_12_0_propagate,0,0);
    VL_IN8(&io_in_control_12_0_shift,4,0);
    VL_IN8(&io_in_control_13_0_dataflow,0,0);
    VL_IN8(&io_in_control_13_0_propagate,0,0);
    VL_IN8(&io_in_control_13_0_shift,4,0);
    VL_IN8(&io_in_control_14_0_dataflow,0,0);
    VL_IN8(&io_in_control_14_0_propagate,0,0);
    VL_IN8(&io_in_control_14_0_shift,4,0);
    VL_IN8(&io_in_control_15_0_dataflow,0,0);
    VL_IN8(&io_in_control_15_0_propagate,0,0);
    VL_IN8(&io_in_control_15_0_shift,4,0);
    VL_IN8(&io_in_control_16_0_dataflow,0,0);
    VL_IN8(&io_in_control_16_0_propagate,0,0);
    VL_IN8(&io_in_control_16_0_shift,4,0);
    VL_IN8(&io_in_control_17_0_dataflow,0,0);
    VL_IN8(&io_in_control_17_0_propagate,0,0);
    VL_IN8(&io_in_control_17_0_shift,4,0);
    VL_IN8(&io_in_control_18_0_dataflow,0,0);
    VL_IN8(&io_in_control_18_0_propagate,0,0);
    VL_IN8(&io_in_control_18_0_shift,4,0);
    VL_IN8(&io_in_control_19_0_dataflow,0,0);
    VL_IN8(&io_in_control_19_0_propagate,0,0);
    VL_IN8(&io_in_control_19_0_shift,4,0);
    VL_IN8(&io_in_control_20_0_dataflow,0,0);
    VL_IN8(&io_in_control_20_0_propagate,0,0);
    VL_IN8(&io_in_control_20_0_shift,4,0);
    VL_IN8(&io_in_control_21_0_dataflow,0,0);
    VL_IN8(&io_in_control_21_0_propagate,0,0);
    VL_IN8(&io_in_control_21_0_shift,4,0);
    VL_IN8(&io_in_control_22_0_dataflow,0,0);
    VL_IN8(&io_in_control_22_0_propagate,0,0);
    VL_IN8(&io_in_control_22_0_shift,4,0);
    VL_IN8(&io_in_control_23_0_dataflow,0,0);
    VL_IN8(&io_in_control_23_0_propagate,0,0);
    VL_IN8(&io_in_control_23_0_shift,4,0);
    VL_IN8(&io_in_control_24_0_dataflow,0,0);
    VL_IN8(&io_in_control_24_0_propagate,0,0);
    VL_IN8(&io_in_control_24_0_shift,4,0);
    VL_IN8(&io_in_control_25_0_dataflow,0,0);
    VL_IN8(&io_in_control_25_0_propagate,0,0);
    VL_IN8(&io_in_control_25_0_shift,4,0);
    VL_IN8(&io_in_control_26_0_dataflow,0,0);
    VL_IN8(&io_in_control_26_0_propagate,0,0);
    VL_IN8(&io_in_control_26_0_shift,4,0);
    VL_IN8(&io_in_control_27_0_dataflow,0,0);
    VL_IN8(&io_in_control_27_0_propagate,0,0);
    VL_IN8(&io_in_control_27_0_shift,4,0);
    VL_IN8(&io_in_control_28_0_dataflow,0,0);
    VL_IN8(&io_in_control_28_0_propagate,0,0);
    VL_IN8(&io_in_control_28_0_shift,4,0);
    VL_IN8(&io_in_control_29_0_dataflow,0,0);
    VL_IN8(&io_in_control_29_0_propagate,0,0);
    VL_IN8(&io_in_control_29_0_shift,4,0);
    VL_IN8(&io_in_control_30_0_dataflow,0,0);
    VL_IN8(&io_in_control_30_0_propagate,0,0);
    VL_IN8(&io_in_control_30_0_shift,4,0);
    VL_IN8(&io_in_control_31_0_dataflow,0,0);
    VL_IN8(&io_in_control_31_0_propagate,0,0);
    VL_IN8(&io_in_control_31_0_shift,4,0);
    VL_IN8(&io_in_id_0_0,2,0);
    VL_IN8(&io_in_id_1_0,2,0);
    VL_IN8(&io_in_id_2_0,2,0);
    VL_IN8(&io_in_id_3_0,2,0);
    VL_IN8(&io_in_id_4_0,2,0);
    VL_IN8(&io_in_id_5_0,2,0);
    VL_IN8(&io_in_id_6_0,2,0);
    VL_IN8(&io_in_id_7_0,2,0);
    VL_IN8(&io_in_id_8_0,2,0);
    VL_IN8(&io_in_id_9_0,2,0);
    VL_IN8(&io_in_id_10_0,2,0);
    VL_IN8(&io_in_id_11_0,2,0);
    VL_IN8(&io_in_id_12_0,2,0);
    VL_IN8(&io_in_id_13_0,2,0);
    VL_IN8(&io_in_id_14_0,2,0);
    VL_IN8(&io_in_id_15_0,2,0);
    VL_IN8(&io_in_id_16_0,2,0);
    VL_IN8(&io_in_id_17_0,2,0);
    VL_IN8(&io_in_id_18_0,2,0);
    VL_IN8(&io_in_id_19_0,2,0);
    VL_IN8(&io_in_id_20_0,2,0);
    VL_IN8(&io_in_id_21_0,2,0);
    VL_IN8(&io_in_id_22_0,2,0);
    VL_IN8(&io_in_id_23_0,2,0);
    VL_IN8(&io_in_id_24_0,2,0);
    VL_IN8(&io_in_id_25_0,2,0);
    VL_IN8(&io_in_id_26_0,2,0);
    VL_IN8(&io_in_id_27_0,2,0);
    VL_IN8(&io_in_id_28_0,2,0);
    VL_IN8(&io_in_id_29_0,2,0);
    VL_IN8(&io_in_id_30_0,2,0);
    VL_IN8(&io_in_id_31_0,2,0);
    VL_IN8(&io_in_last_0_0,0,0);
    VL_IN8(&io_in_last_1_0,0,0);
    VL_IN8(&io_in_last_2_0,0,0);
    VL_IN8(&io_in_last_3_0,0,0);
    VL_IN8(&io_in_last_4_0,0,0);
    VL_IN8(&io_in_last_5_0,0,0);
    VL_IN8(&io_in_last_6_0,0,0);
    VL_IN8(&io_in_last_7_0,0,0);
    VL_IN8(&io_in_last_8_0,0,0);
    VL_IN8(&io_in_last_9_0,0,0);
    VL_IN8(&io_in_last_10_0,0,0);
    VL_IN8(&io_in_last_11_0,0,0);
    VL_IN8(&io_in_last_12_0,0,0);
    VL_IN8(&io_in_last_13_0,0,0);
    VL_IN8(&io_in_last_14_0,0,0);
    VL_IN8(&io_in_last_15_0,0,0);
    VL_IN8(&io_in_last_16_0,0,0);
    VL_IN8(&io_in_last_17_0,0,0);
    VL_IN8(&io_in_last_18_0,0,0);
    VL_IN8(&io_in_last_19_0,0,0);
    VL_IN8(&io_in_last_20_0,0,0);
    VL_IN8(&io_in_last_21_0,0,0);
    VL_IN8(&io_in_last_22_0,0,0);
    VL_IN8(&io_in_last_23_0,0,0);
    VL_IN8(&io_in_last_24_0,0,0);
    VL_IN8(&io_in_last_25_0,0,0);
    VL_IN8(&io_in_last_26_0,0,0);
    VL_IN8(&io_in_last_27_0,0,0);
    VL_IN8(&io_in_last_28_0,0,0);
    VL_IN8(&io_in_last_29_0,0,0);
    VL_IN8(&io_in_last_30_0,0,0);
    VL_IN8(&io_in_last_31_0,0,0);
    VL_IN8(&io_in_valid_0_0,0,0);
    VL_IN8(&io_in_valid_1_0,0,0);
    VL_IN8(&io_in_valid_2_0,0,0);
    VL_IN8(&io_in_valid_3_0,0,0);
    VL_IN8(&io_in_valid_4_0,0,0);
    VL_IN8(&io_in_valid_5_0,0,0);
    VL_IN8(&io_in_valid_6_0,0,0);
    VL_IN8(&io_in_valid_7_0,0,0);
    VL_IN8(&io_in_valid_8_0,0,0);
    VL_IN8(&io_in_valid_9_0,0,0);
    VL_IN8(&io_in_valid_10_0,0,0);
    VL_IN8(&io_in_valid_11_0,0,0);
    VL_IN8(&io_in_valid_12_0,0,0);
    VL_IN8(&io_in_valid_13_0,0,0);
    VL_IN8(&io_in_valid_14_0,0,0);
    VL_IN8(&io_in_valid_15_0,0,0);
    VL_IN8(&io_in_valid_16_0,0,0);
    VL_IN8(&io_in_valid_17_0,0,0);
    VL_IN8(&io_in_valid_18_0,0,0);
    VL_IN8(&io_in_valid_19_0,0,0);
    VL_IN8(&io_in_valid_20_0,0,0);
    VL_IN8(&io_in_valid_21_0,0,0);
    VL_IN8(&io_in_valid_22_0,0,0);
    VL_IN8(&io_in_valid_23_0,0,0);
    VL_IN8(&io_in_valid_24_0,0,0);
    VL_IN8(&io_in_valid_25_0,0,0);
    VL_IN8(&io_in_valid_26_0,0,0);
    VL_IN8(&io_in_valid_27_0,0,0);
    VL_IN8(&io_in_valid_28_0,0,0);
    VL_IN8(&io_in_valid_29_0,0,0);
    VL_IN8(&io_in_valid_30_0,0,0);
    VL_IN8(&io_in_valid_31_0,0,0);
    VL_OUT8(&io_out_valid_0_0,0,0);
    VL_OUT8(&io_out_control_0_0_dataflow,0,0);
    VL_OUT8(&io_out_id_0_0,2,0);
    VL_OUT8(&io_out_last_0_0,0,0);
    VL_IN(&GlobalFiSignal,31,0);
    VL_IN(&GlobalFiNumber,31,0);
    VL_IN(&io_in_a_0_0,31,0);
    VL_IN(&io_in_a_1_0,31,0);
    VL_IN(&io_in_a_2_0,31,0);
    VL_IN(&io_in_a_3_0,31,0);
    VL_IN(&io_in_a_4_0,31,0);
    VL_IN(&io_in_a_5_0,31,0);
    VL_IN(&io_in_a_6_0,31,0);
    VL_IN(&io_in_a_7_0,31,0);
    VL_IN(&io_in_a_8_0,31,0);
    VL_IN(&io_in_a_9_0,31,0);
    VL_IN(&io_in_a_10_0,31,0);
    VL_IN(&io_in_a_11_0,31,0);
    VL_IN(&io_in_a_12_0,31,0);
    VL_IN(&io_in_a_13_0,31,0);
    VL_IN(&io_in_a_14_0,31,0);
    VL_IN(&io_in_a_15_0,31,0);
    VL_IN(&io_in_a_16_0,31,0);
    VL_IN(&io_in_a_17_0,31,0);
    VL_IN(&io_in_a_18_0,31,0);
    VL_IN(&io_in_a_19_0,31,0);
    VL_IN(&io_in_a_20_0,31,0);
    VL_IN(&io_in_a_21_0,31,0);
    VL_IN(&io_in_a_22_0,31,0);
    VL_IN(&io_in_a_23_0,31,0);
    VL_IN(&io_in_a_24_0,31,0);
    VL_IN(&io_in_a_25_0,31,0);
    VL_IN(&io_in_a_26_0,31,0);
    VL_IN(&io_in_a_27_0,31,0);
    VL_IN(&io_in_a_28_0,31,0);
    VL_IN(&io_in_a_29_0,31,0);
    VL_IN(&io_in_a_30_0,31,0);
    VL_IN(&io_in_a_31_0,31,0);
    VL_IN(&io_in_b_0_0,31,0);
    VL_IN(&io_in_b_1_0,31,0);
    VL_IN(&io_in_b_2_0,31,0);
    VL_IN(&io_in_b_3_0,31,0);
    VL_IN(&io_in_b_4_0,31,0);
    VL_IN(&io_in_b_5_0,31,0);
    VL_IN(&io_in_b_6_0,31,0);
    VL_IN(&io_in_b_7_0,31,0);
    VL_IN(&io_in_b_8_0,31,0);
    VL_IN(&io_in_b_9_0,31,0);
    VL_IN(&io_in_b_10_0,31,0);
    VL_IN(&io_in_b_11_0,31,0);
    VL_IN(&io_in_b_12_0,31,0);
    VL_IN(&io_in_b_13_0,31,0);
    VL_IN(&io_in_b_14_0,31,0);
    VL_IN(&io_in_b_15_0,31,0);
    VL_IN(&io_in_b_16_0,31,0);
    VL_IN(&io_in_b_17_0,31,0);
    VL_IN(&io_in_b_18_0,31,0);
    VL_IN(&io_in_b_19_0,31,0);
    VL_IN(&io_in_b_20_0,31,0);
    VL_IN(&io_in_b_21_0,31,0);
    VL_IN(&io_in_b_22_0,31,0);
    VL_IN(&io_in_b_23_0,31,0);
    VL_IN(&io_in_b_24_0,31,0);
    VL_IN(&io_in_b_25_0,31,0);
    VL_IN(&io_in_b_26_0,31,0);
    VL_IN(&io_in_b_27_0,31,0);
    VL_IN(&io_in_b_28_0,31,0);
    VL_IN(&io_in_b_29_0,31,0);
    VL_IN(&io_in_b_30_0,31,0);
    VL_IN(&io_in_b_31_0,31,0);
    VL_IN(&io_in_d_0_0,31,0);
    VL_IN(&io_in_d_1_0,31,0);
    VL_IN(&io_in_d_2_0,31,0);
    VL_IN(&io_in_d_3_0,31,0);
    VL_IN(&io_in_d_4_0,31,0);
    VL_IN(&io_in_d_5_0,31,0);
    VL_IN(&io_in_d_6_0,31,0);
    VL_IN(&io_in_d_7_0,31,0);
    VL_IN(&io_in_d_8_0,31,0);
    VL_IN(&io_in_d_9_0,31,0);
    VL_IN(&io_in_d_10_0,31,0);
    VL_IN(&io_in_d_11_0,31,0);
    VL_IN(&io_in_d_12_0,31,0);
    VL_IN(&io_in_d_13_0,31,0);
    VL_IN(&io_in_d_14_0,31,0);
    VL_IN(&io_in_d_15_0,31,0);
    VL_IN(&io_in_d_16_0,31,0);
    VL_IN(&io_in_d_17_0,31,0);
    VL_IN(&io_in_d_18_0,31,0);
    VL_IN(&io_in_d_19_0,31,0);
    VL_IN(&io_in_d_20_0,31,0);
    VL_IN(&io_in_d_21_0,31,0);
    VL_IN(&io_in_d_22_0,31,0);
    VL_IN(&io_in_d_23_0,31,0);
    VL_IN(&io_in_d_24_0,31,0);
    VL_IN(&io_in_d_25_0,31,0);
    VL_IN(&io_in_d_26_0,31,0);
    VL_IN(&io_in_d_27_0,31,0);
    VL_IN(&io_in_d_28_0,31,0);
    VL_IN(&io_in_d_29_0,31,0);
    VL_IN(&io_in_d_30_0,31,0);
    VL_IN(&io_in_d_31_0,31,0);
    VL_OUT(&io_out_b_0_0,31,0);
    VL_OUT(&io_out_b_1_0,31,0);
    VL_OUT(&io_out_b_2_0,31,0);
    VL_OUT(&io_out_b_3_0,31,0);
    VL_OUT(&io_out_b_4_0,31,0);
    VL_OUT(&io_out_b_5_0,31,0);
    VL_OUT(&io_out_b_6_0,31,0);
    VL_OUT(&io_out_b_7_0,31,0);
    VL_OUT(&io_out_b_8_0,31,0);
    VL_OUT(&io_out_b_9_0,31,0);
    VL_OUT(&io_out_b_10_0,31,0);
    VL_OUT(&io_out_b_11_0,31,0);
    VL_OUT(&io_out_b_12_0,31,0);
    VL_OUT(&io_out_b_13_0,31,0);
    VL_OUT(&io_out_b_14_0,31,0);
    VL_OUT(&io_out_b_15_0,31,0);
    VL_OUT(&io_out_b_16_0,31,0);
    VL_OUT(&io_out_b_17_0,31,0);
    VL_OUT(&io_out_b_18_0,31,0);
    VL_OUT(&io_out_b_19_0,31,0);
    VL_OUT(&io_out_b_20_0,31,0);
    VL_OUT(&io_out_b_21_0,31,0);
    VL_OUT(&io_out_b_22_0,31,0);
    VL_OUT(&io_out_b_23_0,31,0);
    VL_OUT(&io_out_b_24_0,31,0);
    VL_OUT(&io_out_b_25_0,31,0);
    VL_OUT(&io_out_b_26_0,31,0);
    VL_OUT(&io_out_b_27_0,31,0);
    VL_OUT(&io_out_b_28_0,31,0);
    VL_OUT(&io_out_b_29_0,31,0);
    VL_OUT(&io_out_b_30_0,31,0);
    VL_OUT(&io_out_b_31_0,31,0);
    VL_OUT(&io_out_c_0_0,31,0);
    VL_OUT(&io_out_c_1_0,31,0);
    VL_OUT(&io_out_c_2_0,31,0);
    VL_OUT(&io_out_c_3_0,31,0);
    VL_OUT(&io_out_c_4_0,31,0);
    VL_OUT(&io_out_c_5_0,31,0);
    VL_OUT(&io_out_c_6_0,31,0);
    VL_OUT(&io_out_c_7_0,31,0);
    VL_OUT(&io_out_c_8_0,31,0);
    VL_OUT(&io_out_c_9_0,31,0);
    VL_OUT(&io_out_c_10_0,31,0);
    VL_OUT(&io_out_c_11_0,31,0);
    VL_OUT(&io_out_c_12_0,31,0);
    VL_OUT(&io_out_c_13_0,31,0);
    VL_OUT(&io_out_c_14_0,31,0);
    VL_OUT(&io_out_c_15_0,31,0);
    VL_OUT(&io_out_c_16_0,31,0);
    VL_OUT(&io_out_c_17_0,31,0);
    VL_OUT(&io_out_c_18_0,31,0);
    VL_OUT(&io_out_c_19_0,31,0);
    VL_OUT(&io_out_c_20_0,31,0);
    VL_OUT(&io_out_c_21_0,31,0);
    VL_OUT(&io_out_c_22_0,31,0);
    VL_OUT(&io_out_c_23_0,31,0);
    VL_OUT(&io_out_c_24_0,31,0);
    VL_OUT(&io_out_c_25_0,31,0);
    VL_OUT(&io_out_c_26_0,31,0);
    VL_OUT(&io_out_c_27_0,31,0);
    VL_OUT(&io_out_c_28_0,31,0);
    VL_OUT(&io_out_c_29_0,31,0);
    VL_OUT(&io_out_c_30_0,31,0);
    VL_OUT(&io_out_c_31_0,31,0);
    VL_IN16((&GlobalFiModInstNr)[4],15,0);

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    VMesh___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit VMesh(VerilatedContext* contextp, const char* name = "TOP");
    explicit VMesh(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~VMesh();
  private:
    VL_UNCOPYABLE(VMesh);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    /// Return current simulation context for this model.
    /// Used to get to e.g. simulation time via contextp()->time()
    VerilatedContext* contextp() const;
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
