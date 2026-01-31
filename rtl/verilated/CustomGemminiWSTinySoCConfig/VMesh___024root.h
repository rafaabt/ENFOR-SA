// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VMesh.h for the primary calling header

#ifndef VERILATED_VMESH___024ROOT_H_
#define VERILATED_VMESH___024ROOT_H_  // guard

#include "verilated.h"

class VMesh__Syms;
VL_MODULE(VMesh___024root) {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clock,0,0);
        VL_IN8(io_in_control_0_0_dataflow,0,0);
        VL_IN8(io_in_control_0_0_propagate,0,0);
        VL_IN8(io_in_control_1_0_dataflow,0,0);
        VL_IN8(io_in_control_1_0_propagate,0,0);
        VL_IN8(io_in_control_2_0_dataflow,0,0);
        VL_IN8(io_in_control_2_0_propagate,0,0);
        VL_IN8(io_in_control_3_0_dataflow,0,0);
        VL_IN8(io_in_control_3_0_propagate,0,0);
        VL_IN8(io_in_id_0_0,2,0);
        VL_IN8(io_in_id_1_0,2,0);
        VL_IN8(io_in_id_2_0,2,0);
        VL_IN8(io_in_id_3_0,2,0);
        VL_IN8(io_in_last_0_0,0,0);
        VL_IN8(io_in_last_1_0,0,0);
        VL_IN8(io_in_last_2_0,0,0);
        VL_IN8(io_in_last_3_0,0,0);
        VL_IN8(io_in_valid_0_0,0,0);
        VL_IN8(io_in_valid_1_0,0,0);
        VL_IN8(io_in_valid_2_0,0,0);
        VL_IN8(io_in_valid_3_0,0,0);
        VL_OUT8(io_out_valid_0_0,0,0);
        VL_OUT8(io_out_control_0_0_dataflow,0,0);
        VL_OUT8(io_out_id_0_0,2,0);
        VL_OUT8(io_out_last_0_0,0,0);
        CData/*0:0*/ Mesh__DOT__mesh_0_0_io_in_control_0_dataflow_b;
        CData/*0:0*/ Mesh__DOT__mesh_0_0_io_in_control_0_propagate_b;
        CData/*0:0*/ Mesh__DOT__mesh_1_0_io_in_control_0_dataflow_b;
        CData/*0:0*/ Mesh__DOT__mesh_1_0_io_in_control_0_propagate_b;
        CData/*0:0*/ Mesh__DOT__mesh_2_0_io_in_control_0_dataflow_b;
        CData/*0:0*/ Mesh__DOT__mesh_2_0_io_in_control_0_propagate_b;
        CData/*0:0*/ Mesh__DOT__mesh_3_0_io_in_control_0_dataflow_b;
        CData/*0:0*/ Mesh__DOT__mesh_3_0_io_in_control_0_propagate_b;
        CData/*0:0*/ Mesh__DOT__mesh_0_1_io_in_control_0_propagate_b;
        CData/*0:0*/ Mesh__DOT__mesh_1_1_io_in_control_0_propagate_b;
        CData/*0:0*/ Mesh__DOT__mesh_2_1_io_in_control_0_propagate_b;
        CData/*0:0*/ Mesh__DOT__mesh_3_1_io_in_control_0_propagate_b;
        CData/*0:0*/ Mesh__DOT__mesh_0_2_io_in_control_0_propagate_b;
        CData/*0:0*/ Mesh__DOT__mesh_1_2_io_in_control_0_propagate_b;
        CData/*0:0*/ Mesh__DOT__mesh_2_2_io_in_control_0_propagate_b;
        CData/*0:0*/ Mesh__DOT__mesh_3_2_io_in_control_0_propagate_b;
        CData/*0:0*/ Mesh__DOT__mesh_0_3_io_in_control_0_propagate_b;
        CData/*0:0*/ Mesh__DOT__mesh_1_3_io_in_control_0_propagate_b;
        CData/*0:0*/ Mesh__DOT__mesh_2_3_io_in_control_0_propagate_b;
        CData/*0:0*/ Mesh__DOT__mesh_3_3_io_in_control_0_propagate_b;
        CData/*0:0*/ Mesh__DOT__r_16_0;
        CData/*0:0*/ Mesh__DOT__r_17_0;
        CData/*0:0*/ Mesh__DOT__r_18_0;
        CData/*0:0*/ Mesh__DOT__r_19_0;
        CData/*0:0*/ Mesh__DOT__r_20_0;
        CData/*0:0*/ Mesh__DOT__r_21_0;
        CData/*0:0*/ Mesh__DOT__r_22_0;
        CData/*0:0*/ Mesh__DOT__r_23_0;
        CData/*0:0*/ Mesh__DOT__r_24_0;
        CData/*0:0*/ Mesh__DOT__r_25_0;
        CData/*0:0*/ Mesh__DOT__r_26_0;
        CData/*0:0*/ Mesh__DOT__r_27_0;
        CData/*0:0*/ Mesh__DOT__r_28_0;
        CData/*0:0*/ Mesh__DOT__r_29_0;
        CData/*0:0*/ Mesh__DOT__r_30_0;
        CData/*0:0*/ Mesh__DOT__r_31_0;
        CData/*2:0*/ Mesh__DOT__r_32_0;
        CData/*2:0*/ Mesh__DOT__r_33_0;
        CData/*2:0*/ Mesh__DOT__r_34_0;
    };
    struct {
        CData/*2:0*/ Mesh__DOT__r_35_0;
        CData/*0:0*/ Mesh__DOT__r_48_0;
        CData/*0:0*/ Mesh__DOT__r_49_0;
        CData/*0:0*/ Mesh__DOT__r_50_0;
        CData/*0:0*/ Mesh__DOT__r_51_0;
        CData/*0:0*/ Mesh__DOT__r_66_0;
        CData/*0:0*/ Mesh__DOT__r_67_0_dataflow;
        CData/*2:0*/ Mesh__DOT__r_68_0;
        CData/*0:0*/ Mesh__DOT__r_69_0;
        CData/*0:0*/ __Vclklast__TOP__clock;
        VL_IN(io_in_a_0_0,31,0);
        VL_IN(io_in_a_1_0,31,0);
        VL_IN(io_in_a_2_0,31,0);
        VL_IN(io_in_a_3_0,31,0);
        VL_IN(io_in_b_0_0,31,0);
        VL_IN(io_in_b_1_0,31,0);
        VL_IN(io_in_b_2_0,31,0);
        VL_IN(io_in_b_3_0,31,0);
        VL_IN(io_in_d_0_0,31,0);
        VL_IN(io_in_d_1_0,31,0);
        VL_IN(io_in_d_2_0,31,0);
        VL_IN(io_in_d_3_0,31,0);
        VL_OUT(io_out_b_0_0,31,0);
        VL_OUT(io_out_b_1_0,31,0);
        VL_OUT(io_out_b_2_0,31,0);
        VL_OUT(io_out_b_3_0,31,0);
        VL_OUT(io_out_c_0_0,31,0);
        VL_OUT(io_out_c_1_0,31,0);
        VL_OUT(io_out_c_2_0,31,0);
        VL_OUT(io_out_c_3_0,31,0);
        IData/*31:0*/ Mesh__DOT__r_0;
        IData/*31:0*/ Mesh__DOT__r_1_0;
        IData/*31:0*/ Mesh__DOT__r_2_0;
        IData/*31:0*/ Mesh__DOT__r_3_0;
        IData/*31:0*/ Mesh__DOT__r_4_0;
        IData/*31:0*/ Mesh__DOT__r_5_0;
        IData/*31:0*/ Mesh__DOT__r_6_0;
        IData/*31:0*/ Mesh__DOT__r_7_0;
        IData/*31:0*/ Mesh__DOT__r_8_0;
        IData/*31:0*/ Mesh__DOT__r_9_0;
        IData/*31:0*/ Mesh__DOT__r_10_0;
        IData/*31:0*/ Mesh__DOT__r_11_0;
        IData/*31:0*/ Mesh__DOT__r_12_0;
        IData/*31:0*/ Mesh__DOT__r_13_0;
        IData/*31:0*/ Mesh__DOT__r_14_0;
        IData/*31:0*/ Mesh__DOT__r_15_0;
        IData/*31:0*/ Mesh__DOT__b_0;
        IData/*31:0*/ Mesh__DOT__b_1_0;
        IData/*31:0*/ Mesh__DOT__b_2_0;
        IData/*31:0*/ Mesh__DOT__b_3_0;
        IData/*31:0*/ Mesh__DOT__b_4_0;
        IData/*31:0*/ Mesh__DOT__b_5_0;
        IData/*31:0*/ Mesh__DOT__b_6_0;
        IData/*31:0*/ Mesh__DOT__b_7_0;
        IData/*31:0*/ Mesh__DOT__b_8_0;
        IData/*31:0*/ Mesh__DOT__b_9_0;
        IData/*31:0*/ Mesh__DOT__b_10_0;
        IData/*31:0*/ Mesh__DOT__b_11_0;
        IData/*31:0*/ Mesh__DOT__b_12_0;
        IData/*31:0*/ Mesh__DOT__b_13_0;
        IData/*31:0*/ Mesh__DOT__b_14_0;
        IData/*31:0*/ Mesh__DOT__b_15_0;
        IData/*31:0*/ Mesh__DOT__b_16_0;
        IData/*31:0*/ Mesh__DOT__b_17_0;
    };
    struct {
        IData/*31:0*/ Mesh__DOT__b_18_0;
        IData/*31:0*/ Mesh__DOT__b_19_0;
        IData/*31:0*/ Mesh__DOT__b_20_0;
        IData/*31:0*/ Mesh__DOT__b_21_0;
        IData/*31:0*/ Mesh__DOT__b_22_0;
        IData/*31:0*/ Mesh__DOT__b_23_0;
        IData/*31:0*/ Mesh__DOT__b_24_0;
        IData/*31:0*/ Mesh__DOT__b_25_0;
        IData/*31:0*/ Mesh__DOT__b_26_0;
        IData/*31:0*/ Mesh__DOT__b_27_0;
        IData/*31:0*/ Mesh__DOT__b_28_0;
        IData/*31:0*/ Mesh__DOT__b_29_0;
        IData/*31:0*/ Mesh__DOT__b_30_0;
        IData/*31:0*/ Mesh__DOT__b_31_0;
        IData/*31:0*/ Mesh__DOT__r_64_0;
        IData/*31:0*/ Mesh__DOT__r_65_0;
        IData/*31:0*/ Mesh__DOT__r_70_0;
        IData/*31:0*/ Mesh__DOT__r_71_0;
        IData/*31:0*/ Mesh__DOT__r_76_0;
        IData/*31:0*/ Mesh__DOT__r_77_0;
        IData/*31:0*/ Mesh__DOT__r_82_0;
        IData/*31:0*/ Mesh__DOT__r_83_0;
        IData/*31:0*/ Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT__c1;
        IData/*31:0*/ Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT__c2;
        IData/*31:0*/ Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT__c1;
        IData/*31:0*/ Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT__c2;
        IData/*31:0*/ Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT__c1;
        IData/*31:0*/ Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT__c2;
        IData/*31:0*/ Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT__c1;
        IData/*31:0*/ Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT__c2;
        IData/*31:0*/ Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT__c1;
        IData/*31:0*/ Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT__c2;
        IData/*31:0*/ Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT__c1;
        IData/*31:0*/ Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT__c2;
        IData/*31:0*/ Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT__c1;
        IData/*31:0*/ Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT__c2;
        IData/*31:0*/ Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT__c1;
        IData/*31:0*/ Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT__c2;
        IData/*31:0*/ Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT__c1;
        IData/*31:0*/ Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT__c2;
        IData/*31:0*/ Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT__c1;
        IData/*31:0*/ Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT__c2;
        IData/*31:0*/ Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT__c1;
        IData/*31:0*/ Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT__c2;
        IData/*31:0*/ Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT__c1;
        IData/*31:0*/ Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT__c2;
        IData/*31:0*/ Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT__c1;
        IData/*31:0*/ Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT__c2;
        IData/*31:0*/ Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT__c1;
        IData/*31:0*/ Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT__c2;
        IData/*31:0*/ Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT__c1;
        IData/*31:0*/ Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT__c2;
        IData/*31:0*/ Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT__c1;
        IData/*31:0*/ Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT__c2;
    };

    // INTERNAL VARIABLES
    VMesh__Syms* const vlSymsp;

    // CONSTRUCTORS
    VMesh___024root(VMesh__Syms* symsp, const char* name);
    ~VMesh___024root();
    VL_UNCOPYABLE(VMesh___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
