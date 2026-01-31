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
    VL_IN8(&io_in_control_1_0_dataflow,0,0);
    VL_IN8(&io_in_control_1_0_propagate,0,0);
    VL_IN8(&io_in_control_2_0_dataflow,0,0);
    VL_IN8(&io_in_control_2_0_propagate,0,0);
    VL_IN8(&io_in_control_3_0_dataflow,0,0);
    VL_IN8(&io_in_control_3_0_propagate,0,0);
    VL_IN8(&io_in_control_4_0_dataflow,0,0);
    VL_IN8(&io_in_control_4_0_propagate,0,0);
    VL_IN8(&io_in_control_5_0_dataflow,0,0);
    VL_IN8(&io_in_control_5_0_propagate,0,0);
    VL_IN8(&io_in_control_6_0_dataflow,0,0);
    VL_IN8(&io_in_control_6_0_propagate,0,0);
    VL_IN8(&io_in_control_7_0_dataflow,0,0);
    VL_IN8(&io_in_control_7_0_propagate,0,0);
    VL_IN8(&io_in_id_0_0,2,0);
    VL_IN8(&io_in_id_1_0,2,0);
    VL_IN8(&io_in_id_2_0,2,0);
    VL_IN8(&io_in_id_3_0,2,0);
    VL_IN8(&io_in_id_4_0,2,0);
    VL_IN8(&io_in_id_5_0,2,0);
    VL_IN8(&io_in_id_6_0,2,0);
    VL_IN8(&io_in_id_7_0,2,0);
    VL_IN8(&io_in_last_0_0,0,0);
    VL_IN8(&io_in_last_1_0,0,0);
    VL_IN8(&io_in_last_2_0,0,0);
    VL_IN8(&io_in_last_3_0,0,0);
    VL_IN8(&io_in_last_4_0,0,0);
    VL_IN8(&io_in_last_5_0,0,0);
    VL_IN8(&io_in_last_6_0,0,0);
    VL_IN8(&io_in_last_7_0,0,0);
    VL_IN8(&io_in_valid_0_0,0,0);
    VL_IN8(&io_in_valid_1_0,0,0);
    VL_IN8(&io_in_valid_2_0,0,0);
    VL_IN8(&io_in_valid_3_0,0,0);
    VL_IN8(&io_in_valid_4_0,0,0);
    VL_IN8(&io_in_valid_5_0,0,0);
    VL_IN8(&io_in_valid_6_0,0,0);
    VL_IN8(&io_in_valid_7_0,0,0);
    VL_OUT8(&io_out_valid_0_0,0,0);
    VL_OUT8(&io_out_control_0_0_dataflow,0,0);
    VL_OUT8(&io_out_id_0_0,2,0);
    VL_OUT8(&io_out_last_0_0,0,0);
    VL_IN(&io_in_a_0_0,31,0);
    VL_IN(&io_in_a_1_0,31,0);
    VL_IN(&io_in_a_2_0,31,0);
    VL_IN(&io_in_a_3_0,31,0);
    VL_IN(&io_in_a_4_0,31,0);
    VL_IN(&io_in_a_5_0,31,0);
    VL_IN(&io_in_a_6_0,31,0);
    VL_IN(&io_in_a_7_0,31,0);
    VL_IN(&io_in_b_0_0,31,0);
    VL_IN(&io_in_b_1_0,31,0);
    VL_IN(&io_in_b_2_0,31,0);
    VL_IN(&io_in_b_3_0,31,0);
    VL_IN(&io_in_b_4_0,31,0);
    VL_IN(&io_in_b_5_0,31,0);
    VL_IN(&io_in_b_6_0,31,0);
    VL_IN(&io_in_b_7_0,31,0);
    VL_IN(&io_in_d_0_0,31,0);
    VL_IN(&io_in_d_1_0,31,0);
    VL_IN(&io_in_d_2_0,31,0);
    VL_IN(&io_in_d_3_0,31,0);
    VL_IN(&io_in_d_4_0,31,0);
    VL_IN(&io_in_d_5_0,31,0);
    VL_IN(&io_in_d_6_0,31,0);
    VL_IN(&io_in_d_7_0,31,0);
    VL_OUT(&io_out_b_0_0,31,0);
    VL_OUT(&io_out_b_1_0,31,0);
    VL_OUT(&io_out_b_2_0,31,0);
    VL_OUT(&io_out_b_3_0,31,0);
    VL_OUT(&io_out_b_4_0,31,0);
    VL_OUT(&io_out_b_5_0,31,0);
    VL_OUT(&io_out_b_6_0,31,0);
    VL_OUT(&io_out_b_7_0,31,0);
    VL_OUT(&io_out_c_0_0,31,0);
    VL_OUT(&io_out_c_1_0,31,0);
    VL_OUT(&io_out_c_2_0,31,0);
    VL_OUT(&io_out_c_3_0,31,0);
    VL_OUT(&io_out_c_4_0,31,0);
    VL_OUT(&io_out_c_5_0,31,0);
    VL_OUT(&io_out_c_6_0,31,0);
    VL_OUT(&io_out_c_7_0,31,0);

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
