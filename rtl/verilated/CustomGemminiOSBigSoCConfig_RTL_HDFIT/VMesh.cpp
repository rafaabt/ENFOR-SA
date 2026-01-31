// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VMesh.h"
#include "VMesh__Syms.h"

//============================================================
// Constructors

VMesh::VMesh(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new VMesh__Syms(_vcontextp__, _vcname__, this)}
    , clock{vlSymsp->TOP.clock}
    , io_in_control_0_0_dataflow{vlSymsp->TOP.io_in_control_0_0_dataflow}
    , io_in_control_0_0_propagate{vlSymsp->TOP.io_in_control_0_0_propagate}
    , io_in_control_0_0_shift{vlSymsp->TOP.io_in_control_0_0_shift}
    , io_in_control_1_0_dataflow{vlSymsp->TOP.io_in_control_1_0_dataflow}
    , io_in_control_1_0_propagate{vlSymsp->TOP.io_in_control_1_0_propagate}
    , io_in_control_1_0_shift{vlSymsp->TOP.io_in_control_1_0_shift}
    , io_in_control_2_0_dataflow{vlSymsp->TOP.io_in_control_2_0_dataflow}
    , io_in_control_2_0_propagate{vlSymsp->TOP.io_in_control_2_0_propagate}
    , io_in_control_2_0_shift{vlSymsp->TOP.io_in_control_2_0_shift}
    , io_in_control_3_0_dataflow{vlSymsp->TOP.io_in_control_3_0_dataflow}
    , io_in_control_3_0_propagate{vlSymsp->TOP.io_in_control_3_0_propagate}
    , io_in_control_3_0_shift{vlSymsp->TOP.io_in_control_3_0_shift}
    , io_in_control_4_0_dataflow{vlSymsp->TOP.io_in_control_4_0_dataflow}
    , io_in_control_4_0_propagate{vlSymsp->TOP.io_in_control_4_0_propagate}
    , io_in_control_4_0_shift{vlSymsp->TOP.io_in_control_4_0_shift}
    , io_in_control_5_0_dataflow{vlSymsp->TOP.io_in_control_5_0_dataflow}
    , io_in_control_5_0_propagate{vlSymsp->TOP.io_in_control_5_0_propagate}
    , io_in_control_5_0_shift{vlSymsp->TOP.io_in_control_5_0_shift}
    , io_in_control_6_0_dataflow{vlSymsp->TOP.io_in_control_6_0_dataflow}
    , io_in_control_6_0_propagate{vlSymsp->TOP.io_in_control_6_0_propagate}
    , io_in_control_6_0_shift{vlSymsp->TOP.io_in_control_6_0_shift}
    , io_in_control_7_0_dataflow{vlSymsp->TOP.io_in_control_7_0_dataflow}
    , io_in_control_7_0_propagate{vlSymsp->TOP.io_in_control_7_0_propagate}
    , io_in_control_7_0_shift{vlSymsp->TOP.io_in_control_7_0_shift}
    , io_in_control_8_0_dataflow{vlSymsp->TOP.io_in_control_8_0_dataflow}
    , io_in_control_8_0_propagate{vlSymsp->TOP.io_in_control_8_0_propagate}
    , io_in_control_8_0_shift{vlSymsp->TOP.io_in_control_8_0_shift}
    , io_in_control_9_0_dataflow{vlSymsp->TOP.io_in_control_9_0_dataflow}
    , io_in_control_9_0_propagate{vlSymsp->TOP.io_in_control_9_0_propagate}
    , io_in_control_9_0_shift{vlSymsp->TOP.io_in_control_9_0_shift}
    , io_in_control_10_0_dataflow{vlSymsp->TOP.io_in_control_10_0_dataflow}
    , io_in_control_10_0_propagate{vlSymsp->TOP.io_in_control_10_0_propagate}
    , io_in_control_10_0_shift{vlSymsp->TOP.io_in_control_10_0_shift}
    , io_in_control_11_0_dataflow{vlSymsp->TOP.io_in_control_11_0_dataflow}
    , io_in_control_11_0_propagate{vlSymsp->TOP.io_in_control_11_0_propagate}
    , io_in_control_11_0_shift{vlSymsp->TOP.io_in_control_11_0_shift}
    , io_in_control_12_0_dataflow{vlSymsp->TOP.io_in_control_12_0_dataflow}
    , io_in_control_12_0_propagate{vlSymsp->TOP.io_in_control_12_0_propagate}
    , io_in_control_12_0_shift{vlSymsp->TOP.io_in_control_12_0_shift}
    , io_in_control_13_0_dataflow{vlSymsp->TOP.io_in_control_13_0_dataflow}
    , io_in_control_13_0_propagate{vlSymsp->TOP.io_in_control_13_0_propagate}
    , io_in_control_13_0_shift{vlSymsp->TOP.io_in_control_13_0_shift}
    , io_in_control_14_0_dataflow{vlSymsp->TOP.io_in_control_14_0_dataflow}
    , io_in_control_14_0_propagate{vlSymsp->TOP.io_in_control_14_0_propagate}
    , io_in_control_14_0_shift{vlSymsp->TOP.io_in_control_14_0_shift}
    , io_in_control_15_0_dataflow{vlSymsp->TOP.io_in_control_15_0_dataflow}
    , io_in_control_15_0_propagate{vlSymsp->TOP.io_in_control_15_0_propagate}
    , io_in_control_15_0_shift{vlSymsp->TOP.io_in_control_15_0_shift}
    , io_in_id_0_0{vlSymsp->TOP.io_in_id_0_0}
    , io_in_id_1_0{vlSymsp->TOP.io_in_id_1_0}
    , io_in_id_2_0{vlSymsp->TOP.io_in_id_2_0}
    , io_in_id_3_0{vlSymsp->TOP.io_in_id_3_0}
    , io_in_id_4_0{vlSymsp->TOP.io_in_id_4_0}
    , io_in_id_5_0{vlSymsp->TOP.io_in_id_5_0}
    , io_in_id_6_0{vlSymsp->TOP.io_in_id_6_0}
    , io_in_id_7_0{vlSymsp->TOP.io_in_id_7_0}
    , io_in_id_8_0{vlSymsp->TOP.io_in_id_8_0}
    , io_in_id_9_0{vlSymsp->TOP.io_in_id_9_0}
    , io_in_id_10_0{vlSymsp->TOP.io_in_id_10_0}
    , io_in_id_11_0{vlSymsp->TOP.io_in_id_11_0}
    , io_in_id_12_0{vlSymsp->TOP.io_in_id_12_0}
    , io_in_id_13_0{vlSymsp->TOP.io_in_id_13_0}
    , io_in_id_14_0{vlSymsp->TOP.io_in_id_14_0}
    , io_in_id_15_0{vlSymsp->TOP.io_in_id_15_0}
    , io_in_last_0_0{vlSymsp->TOP.io_in_last_0_0}
    , io_in_last_1_0{vlSymsp->TOP.io_in_last_1_0}
    , io_in_last_2_0{vlSymsp->TOP.io_in_last_2_0}
    , io_in_last_3_0{vlSymsp->TOP.io_in_last_3_0}
    , io_in_last_4_0{vlSymsp->TOP.io_in_last_4_0}
    , io_in_last_5_0{vlSymsp->TOP.io_in_last_5_0}
    , io_in_last_6_0{vlSymsp->TOP.io_in_last_6_0}
    , io_in_last_7_0{vlSymsp->TOP.io_in_last_7_0}
    , io_in_last_8_0{vlSymsp->TOP.io_in_last_8_0}
    , io_in_last_9_0{vlSymsp->TOP.io_in_last_9_0}
    , io_in_last_10_0{vlSymsp->TOP.io_in_last_10_0}
    , io_in_last_11_0{vlSymsp->TOP.io_in_last_11_0}
    , io_in_last_12_0{vlSymsp->TOP.io_in_last_12_0}
    , io_in_last_13_0{vlSymsp->TOP.io_in_last_13_0}
    , io_in_last_14_0{vlSymsp->TOP.io_in_last_14_0}
    , io_in_last_15_0{vlSymsp->TOP.io_in_last_15_0}
    , io_in_valid_0_0{vlSymsp->TOP.io_in_valid_0_0}
    , io_in_valid_1_0{vlSymsp->TOP.io_in_valid_1_0}
    , io_in_valid_2_0{vlSymsp->TOP.io_in_valid_2_0}
    , io_in_valid_3_0{vlSymsp->TOP.io_in_valid_3_0}
    , io_in_valid_4_0{vlSymsp->TOP.io_in_valid_4_0}
    , io_in_valid_5_0{vlSymsp->TOP.io_in_valid_5_0}
    , io_in_valid_6_0{vlSymsp->TOP.io_in_valid_6_0}
    , io_in_valid_7_0{vlSymsp->TOP.io_in_valid_7_0}
    , io_in_valid_8_0{vlSymsp->TOP.io_in_valid_8_0}
    , io_in_valid_9_0{vlSymsp->TOP.io_in_valid_9_0}
    , io_in_valid_10_0{vlSymsp->TOP.io_in_valid_10_0}
    , io_in_valid_11_0{vlSymsp->TOP.io_in_valid_11_0}
    , io_in_valid_12_0{vlSymsp->TOP.io_in_valid_12_0}
    , io_in_valid_13_0{vlSymsp->TOP.io_in_valid_13_0}
    , io_in_valid_14_0{vlSymsp->TOP.io_in_valid_14_0}
    , io_in_valid_15_0{vlSymsp->TOP.io_in_valid_15_0}
    , io_out_valid_0_0{vlSymsp->TOP.io_out_valid_0_0}
    , io_out_control_0_0_dataflow{vlSymsp->TOP.io_out_control_0_0_dataflow}
    , io_out_id_0_0{vlSymsp->TOP.io_out_id_0_0}
    , io_out_last_0_0{vlSymsp->TOP.io_out_last_0_0}
    , GlobalFiSignal{vlSymsp->TOP.GlobalFiSignal}
    , GlobalFiNumber{vlSymsp->TOP.GlobalFiNumber}
    , io_in_a_0_0{vlSymsp->TOP.io_in_a_0_0}
    , io_in_a_1_0{vlSymsp->TOP.io_in_a_1_0}
    , io_in_a_2_0{vlSymsp->TOP.io_in_a_2_0}
    , io_in_a_3_0{vlSymsp->TOP.io_in_a_3_0}
    , io_in_a_4_0{vlSymsp->TOP.io_in_a_4_0}
    , io_in_a_5_0{vlSymsp->TOP.io_in_a_5_0}
    , io_in_a_6_0{vlSymsp->TOP.io_in_a_6_0}
    , io_in_a_7_0{vlSymsp->TOP.io_in_a_7_0}
    , io_in_a_8_0{vlSymsp->TOP.io_in_a_8_0}
    , io_in_a_9_0{vlSymsp->TOP.io_in_a_9_0}
    , io_in_a_10_0{vlSymsp->TOP.io_in_a_10_0}
    , io_in_a_11_0{vlSymsp->TOP.io_in_a_11_0}
    , io_in_a_12_0{vlSymsp->TOP.io_in_a_12_0}
    , io_in_a_13_0{vlSymsp->TOP.io_in_a_13_0}
    , io_in_a_14_0{vlSymsp->TOP.io_in_a_14_0}
    , io_in_a_15_0{vlSymsp->TOP.io_in_a_15_0}
    , io_in_b_0_0{vlSymsp->TOP.io_in_b_0_0}
    , io_in_b_1_0{vlSymsp->TOP.io_in_b_1_0}
    , io_in_b_2_0{vlSymsp->TOP.io_in_b_2_0}
    , io_in_b_3_0{vlSymsp->TOP.io_in_b_3_0}
    , io_in_b_4_0{vlSymsp->TOP.io_in_b_4_0}
    , io_in_b_5_0{vlSymsp->TOP.io_in_b_5_0}
    , io_in_b_6_0{vlSymsp->TOP.io_in_b_6_0}
    , io_in_b_7_0{vlSymsp->TOP.io_in_b_7_0}
    , io_in_b_8_0{vlSymsp->TOP.io_in_b_8_0}
    , io_in_b_9_0{vlSymsp->TOP.io_in_b_9_0}
    , io_in_b_10_0{vlSymsp->TOP.io_in_b_10_0}
    , io_in_b_11_0{vlSymsp->TOP.io_in_b_11_0}
    , io_in_b_12_0{vlSymsp->TOP.io_in_b_12_0}
    , io_in_b_13_0{vlSymsp->TOP.io_in_b_13_0}
    , io_in_b_14_0{vlSymsp->TOP.io_in_b_14_0}
    , io_in_b_15_0{vlSymsp->TOP.io_in_b_15_0}
    , io_in_d_0_0{vlSymsp->TOP.io_in_d_0_0}
    , io_in_d_1_0{vlSymsp->TOP.io_in_d_1_0}
    , io_in_d_2_0{vlSymsp->TOP.io_in_d_2_0}
    , io_in_d_3_0{vlSymsp->TOP.io_in_d_3_0}
    , io_in_d_4_0{vlSymsp->TOP.io_in_d_4_0}
    , io_in_d_5_0{vlSymsp->TOP.io_in_d_5_0}
    , io_in_d_6_0{vlSymsp->TOP.io_in_d_6_0}
    , io_in_d_7_0{vlSymsp->TOP.io_in_d_7_0}
    , io_in_d_8_0{vlSymsp->TOP.io_in_d_8_0}
    , io_in_d_9_0{vlSymsp->TOP.io_in_d_9_0}
    , io_in_d_10_0{vlSymsp->TOP.io_in_d_10_0}
    , io_in_d_11_0{vlSymsp->TOP.io_in_d_11_0}
    , io_in_d_12_0{vlSymsp->TOP.io_in_d_12_0}
    , io_in_d_13_0{vlSymsp->TOP.io_in_d_13_0}
    , io_in_d_14_0{vlSymsp->TOP.io_in_d_14_0}
    , io_in_d_15_0{vlSymsp->TOP.io_in_d_15_0}
    , io_out_b_0_0{vlSymsp->TOP.io_out_b_0_0}
    , io_out_b_1_0{vlSymsp->TOP.io_out_b_1_0}
    , io_out_b_2_0{vlSymsp->TOP.io_out_b_2_0}
    , io_out_b_3_0{vlSymsp->TOP.io_out_b_3_0}
    , io_out_b_4_0{vlSymsp->TOP.io_out_b_4_0}
    , io_out_b_5_0{vlSymsp->TOP.io_out_b_5_0}
    , io_out_b_6_0{vlSymsp->TOP.io_out_b_6_0}
    , io_out_b_7_0{vlSymsp->TOP.io_out_b_7_0}
    , io_out_b_8_0{vlSymsp->TOP.io_out_b_8_0}
    , io_out_b_9_0{vlSymsp->TOP.io_out_b_9_0}
    , io_out_b_10_0{vlSymsp->TOP.io_out_b_10_0}
    , io_out_b_11_0{vlSymsp->TOP.io_out_b_11_0}
    , io_out_b_12_0{vlSymsp->TOP.io_out_b_12_0}
    , io_out_b_13_0{vlSymsp->TOP.io_out_b_13_0}
    , io_out_b_14_0{vlSymsp->TOP.io_out_b_14_0}
    , io_out_b_15_0{vlSymsp->TOP.io_out_b_15_0}
    , io_out_c_0_0{vlSymsp->TOP.io_out_c_0_0}
    , io_out_c_1_0{vlSymsp->TOP.io_out_c_1_0}
    , io_out_c_2_0{vlSymsp->TOP.io_out_c_2_0}
    , io_out_c_3_0{vlSymsp->TOP.io_out_c_3_0}
    , io_out_c_4_0{vlSymsp->TOP.io_out_c_4_0}
    , io_out_c_5_0{vlSymsp->TOP.io_out_c_5_0}
    , io_out_c_6_0{vlSymsp->TOP.io_out_c_6_0}
    , io_out_c_7_0{vlSymsp->TOP.io_out_c_7_0}
    , io_out_c_8_0{vlSymsp->TOP.io_out_c_8_0}
    , io_out_c_9_0{vlSymsp->TOP.io_out_c_9_0}
    , io_out_c_10_0{vlSymsp->TOP.io_out_c_10_0}
    , io_out_c_11_0{vlSymsp->TOP.io_out_c_11_0}
    , io_out_c_12_0{vlSymsp->TOP.io_out_c_12_0}
    , io_out_c_13_0{vlSymsp->TOP.io_out_c_13_0}
    , io_out_c_14_0{vlSymsp->TOP.io_out_c_14_0}
    , io_out_c_15_0{vlSymsp->TOP.io_out_c_15_0}
    , GlobalFiModInstNr{vlSymsp->TOP.GlobalFiModInstNr}
    , rootp{&(vlSymsp->TOP)}
{
}

VMesh::VMesh(const char* _vcname__)
    : VMesh(nullptr, _vcname__)
{
}

//============================================================
// Destructor

VMesh::~VMesh() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void VMesh___024root___eval_initial(VMesh___024root* vlSelf);
void VMesh___024root___eval_settle(VMesh___024root* vlSelf);
void VMesh___024root___eval(VMesh___024root* vlSelf);
#ifdef VL_DEBUG
void VMesh___024root___eval_debug_assertions(VMesh___024root* vlSelf);
#endif  // VL_DEBUG
void VMesh___024root___final(VMesh___024root* vlSelf);

static void _eval_initial_loop(VMesh__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    VMesh___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        VMesh___024root___eval_settle(&(vlSymsp->TOP));
        VMesh___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void VMesh::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VMesh::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VMesh___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        VMesh___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

VerilatedContext* VMesh::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* VMesh::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void VMesh::final() {
    VMesh___024root___final(&(vlSymsp->TOP));
}
