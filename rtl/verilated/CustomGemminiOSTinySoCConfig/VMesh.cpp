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
    , io_in_id_0_0{vlSymsp->TOP.io_in_id_0_0}
    , io_in_id_1_0{vlSymsp->TOP.io_in_id_1_0}
    , io_in_id_2_0{vlSymsp->TOP.io_in_id_2_0}
    , io_in_id_3_0{vlSymsp->TOP.io_in_id_3_0}
    , io_in_last_0_0{vlSymsp->TOP.io_in_last_0_0}
    , io_in_last_1_0{vlSymsp->TOP.io_in_last_1_0}
    , io_in_last_2_0{vlSymsp->TOP.io_in_last_2_0}
    , io_in_last_3_0{vlSymsp->TOP.io_in_last_3_0}
    , io_in_valid_0_0{vlSymsp->TOP.io_in_valid_0_0}
    , io_in_valid_1_0{vlSymsp->TOP.io_in_valid_1_0}
    , io_in_valid_2_0{vlSymsp->TOP.io_in_valid_2_0}
    , io_in_valid_3_0{vlSymsp->TOP.io_in_valid_3_0}
    , io_out_valid_0_0{vlSymsp->TOP.io_out_valid_0_0}
    , io_out_control_0_0_dataflow{vlSymsp->TOP.io_out_control_0_0_dataflow}
    , io_out_id_0_0{vlSymsp->TOP.io_out_id_0_0}
    , io_out_last_0_0{vlSymsp->TOP.io_out_last_0_0}
    , io_in_a_0_0{vlSymsp->TOP.io_in_a_0_0}
    , io_in_a_1_0{vlSymsp->TOP.io_in_a_1_0}
    , io_in_a_2_0{vlSymsp->TOP.io_in_a_2_0}
    , io_in_a_3_0{vlSymsp->TOP.io_in_a_3_0}
    , io_in_b_0_0{vlSymsp->TOP.io_in_b_0_0}
    , io_in_b_1_0{vlSymsp->TOP.io_in_b_1_0}
    , io_in_b_2_0{vlSymsp->TOP.io_in_b_2_0}
    , io_in_b_3_0{vlSymsp->TOP.io_in_b_3_0}
    , io_in_d_0_0{vlSymsp->TOP.io_in_d_0_0}
    , io_in_d_1_0{vlSymsp->TOP.io_in_d_1_0}
    , io_in_d_2_0{vlSymsp->TOP.io_in_d_2_0}
    , io_in_d_3_0{vlSymsp->TOP.io_in_d_3_0}
    , io_out_b_0_0{vlSymsp->TOP.io_out_b_0_0}
    , io_out_b_1_0{vlSymsp->TOP.io_out_b_1_0}
    , io_out_b_2_0{vlSymsp->TOP.io_out_b_2_0}
    , io_out_b_3_0{vlSymsp->TOP.io_out_b_3_0}
    , io_out_c_0_0{vlSymsp->TOP.io_out_c_0_0}
    , io_out_c_1_0{vlSymsp->TOP.io_out_c_1_0}
    , io_out_c_2_0{vlSymsp->TOP.io_out_c_2_0}
    , io_out_c_3_0{vlSymsp->TOP.io_out_c_3_0}
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
