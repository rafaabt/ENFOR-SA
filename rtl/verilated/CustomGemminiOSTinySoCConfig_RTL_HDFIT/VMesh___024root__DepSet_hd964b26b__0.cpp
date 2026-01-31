// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VMesh.h for the primary calling header

#include "verilated.h"

#include "VMesh___024root.h"

VL_INLINE_OPT void VMesh___024root___sequent__TOP__0(VMesh___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMesh__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMesh___024root___sequent__TOP__0\n"); );
    // Body
    vlSelf->Mesh__DOT__r_66_0 = (((IData)(vlSelf->Mesh__DOT__r_19_0) 
                                  ^ (((IData)(vlSelf->Mesh__DOT__mesh_3_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                                      & (0x10U == vlSelf->GlobalFiNumber)) 
                                     & vlSelf->GlobalFiSignal)) 
                                 ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                     & (0xa3U == vlSelf->GlobalFiNumber)) 
                                    & vlSelf->GlobalFiSignal));
    vlSelf->Mesh__DOT__r_15_0 = ((vlSelf->Mesh__DOT__r_14_0 
                                  ^ (((IData)(vlSelf->Mesh__DOT__mesh_3_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                                      & (8U == vlSelf->GlobalFiNumber))
                                      ? vlSelf->GlobalFiSignal
                                      : 0U)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                 & (0x20U 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
    vlSelf->Mesh__DOT__r_11_0 = ((vlSelf->Mesh__DOT__r_10_0 
                                  ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                                      & (8U == vlSelf->GlobalFiNumber))
                                      ? vlSelf->GlobalFiSignal
                                      : 0U)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                 & (0x1cU 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
    vlSelf->Mesh__DOT__r_7_0 = ((vlSelf->Mesh__DOT__r_6_0 
                                 ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                                     & (8U == vlSelf->GlobalFiNumber))
                                     ? vlSelf->GlobalFiSignal
                                     : 0U)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                & (0x18U 
                                                   == vlSelf->GlobalFiNumber))
                                                ? vlSelf->GlobalFiSignal
                                                : 0U));
    vlSelf->Mesh__DOT__r_3_0 = ((vlSelf->Mesh__DOT__r_2_0 
                                 ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                                     & (8U == vlSelf->GlobalFiNumber))
                                     ? vlSelf->GlobalFiSignal
                                     : 0U)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                & (0x14U 
                                                   == vlSelf->GlobalFiNumber))
                                                ? vlSelf->GlobalFiSignal
                                                : 0U));
    vlSelf->Mesh__DOT__r_69_0 = (((IData)(vlSelf->Mesh__DOT__r_51_0) 
                                  ^ (((IData)(vlSelf->Mesh__DOT__mesh_3_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                                      & (0xfU == vlSelf->GlobalFiNumber)) 
                                     & vlSelf->GlobalFiSignal)) 
                                 ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                     & (0xa6U == vlSelf->GlobalFiNumber)) 
                                    & vlSelf->GlobalFiSignal));
    vlSelf->Mesh__DOT__r_68_0 = (7U & (((IData)(vlSelf->Mesh__DOT__r_35_0) 
                                        ^ (((IData)(vlSelf->Mesh__DOT__mesh_3_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                                            & (0xeU 
                                               == vlSelf->GlobalFiNumber))
                                            ? vlSelf->GlobalFiSignal
                                            : 0U)) 
                                       ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                           & (0xa5U 
                                              == vlSelf->GlobalFiNumber))
                                           ? vlSelf->GlobalFiSignal
                                           : 0U)));
    vlSelf->Mesh__DOT__r_67_0_dataflow = (((IData)(vlSelf->Mesh__DOT__mesh_3_0_io_in_control_0_dataflow_b) 
                                           ^ (((IData)(vlSelf->Mesh__DOT__mesh_3_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                                               & (0xbU 
                                                  == vlSelf->GlobalFiNumber)) 
                                              & vlSelf->GlobalFiSignal)) 
                                          ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                              & (0xa4U 
                                                 == vlSelf->GlobalFiNumber)) 
                                             & vlSelf->GlobalFiSignal));
    vlSelf->Mesh__DOT__r_82_0 = ((vlSelf->Mesh__DOT__b_15_0 
                                  ^ (((IData)(vlSelf->Mesh__DOT__mesh_3_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                                      & (9U == vlSelf->GlobalFiNumber))
                                      ? vlSelf->GlobalFiSignal
                                      : 0U)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                 & (0xabU 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
    vlSelf->Mesh__DOT__r_70_0 = ((vlSelf->Mesh__DOT__b_7_0 
                                  ^ (((IData)(vlSelf->Mesh__DOT__mesh_3_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                                      & (9U == vlSelf->GlobalFiNumber))
                                      ? vlSelf->GlobalFiSignal
                                      : 0U)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                 & (0xa7U 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
    vlSelf->Mesh__DOT__r_76_0 = ((vlSelf->Mesh__DOT__b_11_0 
                                  ^ (((IData)(vlSelf->Mesh__DOT__mesh_3_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                                      & (9U == vlSelf->GlobalFiNumber))
                                      ? vlSelf->GlobalFiSignal
                                      : 0U)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                 & (0xa9U 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
    vlSelf->Mesh__DOT__r_64_0 = ((vlSelf->Mesh__DOT__b_3_0 
                                  ^ (((IData)(vlSelf->Mesh__DOT__mesh_3_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                                      & (9U == vlSelf->GlobalFiNumber))
                                      ? vlSelf->GlobalFiSignal
                                      : 0U)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                 & (0xa1U 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
    vlSelf->Mesh__DOT__r_83_0 = ((((IData)(vlSelf->Mesh__DOT__mesh_3_3_io_in_control_0_propagate_b)
                                    ? (vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT___io_out_c_T 
                                       + (((0U != (IData)(vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT__shift_offset)) 
                                           & ((0x1fU 
                                               >= (0x1fU 
                                                   & ((IData)(vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT__shift_offset) 
                                                      - (IData)(1U))))
                                               ? VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT__c1, 
                                                                (0x1fU 
                                                                 & ((IData)(vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT__shift_offset) 
                                                                    - (IData)(1U))))
                                               : (- 
                                                  (vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT__c1 
                                                   >> 0x1fU)))) 
                                          & ((0U != 
                                              ((2U 
                                                > (IData)(vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT__shift_offset))
                                                ? 0U
                                                : (vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT__c1 
                                                   & (((0x1fU 
                                                        >= 
                                                        (0x1fU 
                                                         & ((IData)(vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT__shift_offset) 
                                                            - (IData)(1U))))
                                                        ? 
                                                       ((IData)(1U) 
                                                        << 
                                                        (0x1fU 
                                                         & ((IData)(vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT__shift_offset) 
                                                            - (IData)(1U))))
                                                        : 0U) 
                                                      - (IData)(1U))))) 
                                             | vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT___io_out_c_T)))
                                    : (vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT___io_out_c_T_11 
                                       + (((0U != (IData)(vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT__shift_offset)) 
                                           & ((0x1fU 
                                               >= (0x1fU 
                                                   & ((IData)(vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT__shift_offset) 
                                                      - (IData)(1U))))
                                               ? VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT__c2, 
                                                                (0x1fU 
                                                                 & ((IData)(vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT__shift_offset) 
                                                                    - (IData)(1U))))
                                               : (- 
                                                  (vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT__c2 
                                                   >> 0x1fU)))) 
                                          & ((0U != 
                                              ((2U 
                                                > (IData)(vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT__shift_offset))
                                                ? 0U
                                                : (vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT__c2 
                                                   & (((0x1fU 
                                                        >= 
                                                        (0x1fU 
                                                         & ((IData)(vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT__shift_offset) 
                                                            - (IData)(1U))))
                                                        ? 
                                                       ((IData)(1U) 
                                                        << 
                                                        (0x1fU 
                                                         & ((IData)(vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT__shift_offset) 
                                                            - (IData)(1U))))
                                                        : 0U) 
                                                      - (IData)(1U))))) 
                                             | vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT___io_out_c_T_11)))) 
                                  ^ (((IData)(vlSelf->Mesh__DOT__mesh_3_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                                      & (0xaU == vlSelf->GlobalFiNumber))
                                      ? vlSelf->GlobalFiSignal
                                      : 0U)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                 & (0xacU 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
    if (vlSelf->Mesh__DOT__r_31_0) {
        vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT__last_s 
            = ((IData)(vlSelf->Mesh__DOT__mesh_3_3_io_in_control_0_propagate_b) 
               ^ (((IData)(vlSelf->Mesh__DOT__mesh_3_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                   & (7U == vlSelf->GlobalFiNumber)) 
                  & vlSelf->GlobalFiSignal));
        if (vlSelf->Mesh__DOT__mesh_3_3_io_in_control_0_propagate_b) {
            vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT__c1 
                = (vlSelf->Mesh__DOT__b_31_0 ^ (((IData)(vlSelf->Mesh__DOT__mesh_3_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                 & (3U 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
            vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT__c2 
                = (vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT___mac_unit_io_out_d 
                   ^ (((IData)(vlSelf->Mesh__DOT__mesh_3_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                       & (4U == vlSelf->GlobalFiNumber))
                       ? vlSelf->GlobalFiSignal : 0U));
        } else {
            vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT__c1 
                = (vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT___mac_unit_io_out_d 
                   ^ (((IData)(vlSelf->Mesh__DOT__mesh_3_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                       & (5U == vlSelf->GlobalFiNumber))
                       ? vlSelf->GlobalFiSignal : 0U));
            vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT__c2 
                = (vlSelf->Mesh__DOT__b_31_0 ^ (((IData)(vlSelf->Mesh__DOT__mesh_3_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                 & (6U 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
        }
    }
    if (vlSelf->Mesh__DOT___mesh_2_3_io_out_valid_0) {
        vlSelf->Mesh__DOT__mesh_3_3_io_in_control_0_shift_b 
            = (0x1fU & (((IData)(vlSelf->Mesh__DOT__mesh_2_3_io_in_control_0_shift_b) 
                         ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                             & (0xdU == vlSelf->GlobalFiNumber))
                             ? vlSelf->GlobalFiSignal
                             : 0U)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                        & (0x6eU == vlSelf->GlobalFiNumber))
                                        ? vlSelf->GlobalFiSignal
                                        : 0U)));
        vlSelf->Mesh__DOT__b_15_0 = ((vlSelf->Mesh__DOT__b_14_0 
                                      ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                                          & (9U == vlSelf->GlobalFiNumber))
                                          ? vlSelf->GlobalFiSignal
                                          : 0U)) ^ 
                                     (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                       & (0x6cU == vlSelf->GlobalFiNumber))
                                       ? vlSelf->GlobalFiSignal
                                       : 0U));
        vlSelf->Mesh__DOT__mesh_3_3_io_in_control_0_propagate_b 
            = (((IData)(vlSelf->Mesh__DOT__mesh_2_3_io_in_control_0_propagate_b) 
                ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                    & (0xcU == vlSelf->GlobalFiNumber)) 
                   & vlSelf->GlobalFiSignal)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                  & (0x70U 
                                                     == vlSelf->GlobalFiNumber)) 
                                                 & vlSelf->GlobalFiSignal));
        vlSelf->Mesh__DOT__b_31_0 = ((((IData)(vlSelf->Mesh__DOT__mesh_2_3_io_in_control_0_propagate_b)
                                        ? (vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT___io_out_c_T 
                                           + (((0U 
                                                != (IData)(vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT__shift_offset)) 
                                               & ((0x1fU 
                                                   >= 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT__shift_offset) 
                                                       - (IData)(1U))))
                                                   ? 
                                                  VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT__c1, 
                                                                 (0x1fU 
                                                                  & ((IData)(vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT__shift_offset) 
                                                                     - (IData)(1U))))
                                                   : 
                                                  (- 
                                                   (vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT__c1 
                                                    >> 0x1fU)))) 
                                              & ((0U 
                                                  != 
                                                  ((2U 
                                                    > (IData)(vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT__shift_offset))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT__c1 
                                                    & (((0x1fU 
                                                         >= 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         ? 
                                                        ((IData)(1U) 
                                                         << 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         : 0U) 
                                                       - (IData)(1U))))) 
                                                 | vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT___io_out_c_T)))
                                        : (vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT___io_out_c_T_11 
                                           + (((0U 
                                                != (IData)(vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT__shift_offset)) 
                                               & ((0x1fU 
                                                   >= 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT__shift_offset) 
                                                       - (IData)(1U))))
                                                   ? 
                                                  VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT__c2, 
                                                                 (0x1fU 
                                                                  & ((IData)(vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT__shift_offset) 
                                                                     - (IData)(1U))))
                                                   : 
                                                  (- 
                                                   (vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT__c2 
                                                    >> 0x1fU)))) 
                                              & ((0U 
                                                  != 
                                                  ((2U 
                                                    > (IData)(vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT__shift_offset))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT__c2 
                                                    & (((0x1fU 
                                                         >= 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         ? 
                                                        ((IData)(1U) 
                                                         << 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         : 0U) 
                                                       - (IData)(1U))))) 
                                                 | vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT___io_out_c_T_11)))) 
                                      ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                                          & (0xaU == vlSelf->GlobalFiNumber))
                                          ? vlSelf->GlobalFiSignal
                                          : 0U)) ^ 
                                     (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                       & (0x6dU == vlSelf->GlobalFiNumber))
                                       ? vlSelf->GlobalFiSignal
                                       : 0U));
    }
    if (vlSelf->Mesh__DOT__r_30_0) {
        vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT__last_s 
            = ((IData)(vlSelf->Mesh__DOT__mesh_2_3_io_in_control_0_propagate_b) 
               ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                   & (7U == vlSelf->GlobalFiNumber)) 
                  & vlSelf->GlobalFiSignal));
        if (vlSelf->Mesh__DOT__mesh_2_3_io_in_control_0_propagate_b) {
            vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT__c1 
                = (vlSelf->Mesh__DOT__b_30_0 ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                 & (3U 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
            vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT__c2 
                = (vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT___mac_unit_io_out_d 
                   ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                       & (4U == vlSelf->GlobalFiNumber))
                       ? vlSelf->GlobalFiSignal : 0U));
        } else {
            vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT__c1 
                = (vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT___mac_unit_io_out_d 
                   ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                       & (5U == vlSelf->GlobalFiNumber))
                       ? vlSelf->GlobalFiSignal : 0U));
            vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT__c2 
                = (vlSelf->Mesh__DOT__b_30_0 ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                 & (6U 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
        }
    }
    vlSelf->Mesh__DOT__r_71_0 = ((((IData)(vlSelf->Mesh__DOT__mesh_3_1_io_in_control_0_propagate_b)
                                    ? (vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT___io_out_c_T 
                                       + (((0U != (IData)(vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT__shift_offset)) 
                                           & ((0x1fU 
                                               >= (0x1fU 
                                                   & ((IData)(vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT__shift_offset) 
                                                      - (IData)(1U))))
                                               ? VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT__c1, 
                                                                (0x1fU 
                                                                 & ((IData)(vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT__shift_offset) 
                                                                    - (IData)(1U))))
                                               : (- 
                                                  (vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT__c1 
                                                   >> 0x1fU)))) 
                                          & ((0U != 
                                              ((2U 
                                                > (IData)(vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT__shift_offset))
                                                ? 0U
                                                : (vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT__c1 
                                                   & (((0x1fU 
                                                        >= 
                                                        (0x1fU 
                                                         & ((IData)(vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT__shift_offset) 
                                                            - (IData)(1U))))
                                                        ? 
                                                       ((IData)(1U) 
                                                        << 
                                                        (0x1fU 
                                                         & ((IData)(vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT__shift_offset) 
                                                            - (IData)(1U))))
                                                        : 0U) 
                                                      - (IData)(1U))))) 
                                             | vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT___io_out_c_T)))
                                    : (vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT___io_out_c_T_11 
                                       + (((0U != (IData)(vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT__shift_offset)) 
                                           & ((0x1fU 
                                               >= (0x1fU 
                                                   & ((IData)(vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT__shift_offset) 
                                                      - (IData)(1U))))
                                               ? VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT__c2, 
                                                                (0x1fU 
                                                                 & ((IData)(vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT__shift_offset) 
                                                                    - (IData)(1U))))
                                               : (- 
                                                  (vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT__c2 
                                                   >> 0x1fU)))) 
                                          & ((0U != 
                                              ((2U 
                                                > (IData)(vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT__shift_offset))
                                                ? 0U
                                                : (vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT__c2 
                                                   & (((0x1fU 
                                                        >= 
                                                        (0x1fU 
                                                         & ((IData)(vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT__shift_offset) 
                                                            - (IData)(1U))))
                                                        ? 
                                                       ((IData)(1U) 
                                                        << 
                                                        (0x1fU 
                                                         & ((IData)(vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT__shift_offset) 
                                                            - (IData)(1U))))
                                                        : 0U) 
                                                      - (IData)(1U))))) 
                                             | vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT___io_out_c_T_11)))) 
                                  ^ (((IData)(vlSelf->Mesh__DOT__mesh_3_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                                      & (0xaU == vlSelf->GlobalFiNumber))
                                      ? vlSelf->GlobalFiSignal
                                      : 0U)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                 & (0xa8U 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
    if (vlSelf->Mesh__DOT__r_23_0) {
        vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT__last_s 
            = ((IData)(vlSelf->Mesh__DOT__mesh_3_1_io_in_control_0_propagate_b) 
               ^ (((IData)(vlSelf->Mesh__DOT__mesh_3_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                   & (7U == vlSelf->GlobalFiNumber)) 
                  & vlSelf->GlobalFiSignal));
        if (vlSelf->Mesh__DOT__mesh_3_1_io_in_control_0_propagate_b) {
            vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT__c1 
                = (vlSelf->Mesh__DOT__b_23_0 ^ (((IData)(vlSelf->Mesh__DOT__mesh_3_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                 & (3U 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
            vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT__c2 
                = (vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT___mac_unit_io_out_d 
                   ^ (((IData)(vlSelf->Mesh__DOT__mesh_3_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                       & (4U == vlSelf->GlobalFiNumber))
                       ? vlSelf->GlobalFiSignal : 0U));
        } else {
            vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT__c1 
                = (vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT___mac_unit_io_out_d 
                   ^ (((IData)(vlSelf->Mesh__DOT__mesh_3_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                       & (5U == vlSelf->GlobalFiNumber))
                       ? vlSelf->GlobalFiSignal : 0U));
            vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT__c2 
                = (vlSelf->Mesh__DOT__b_23_0 ^ (((IData)(vlSelf->Mesh__DOT__mesh_3_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                 & (6U 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
        }
    }
    if (vlSelf->Mesh__DOT___mesh_2_1_io_out_valid_0) {
        vlSelf->Mesh__DOT__mesh_3_1_io_in_control_0_shift_b 
            = (0x1fU & (((IData)(vlSelf->Mesh__DOT__mesh_2_1_io_in_control_0_shift_b) 
                         ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                             & (0xdU == vlSelf->GlobalFiNumber))
                             ? vlSelf->GlobalFiSignal
                             : 0U)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                        & (0x46U == vlSelf->GlobalFiNumber))
                                        ? vlSelf->GlobalFiSignal
                                        : 0U)));
        vlSelf->Mesh__DOT__b_7_0 = ((vlSelf->Mesh__DOT__b_6_0 
                                     ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                                         & (9U == vlSelf->GlobalFiNumber))
                                         ? vlSelf->GlobalFiSignal
                                         : 0U)) ^ (
                                                   ((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                    & (0x44U 
                                                       == vlSelf->GlobalFiNumber))
                                                    ? vlSelf->GlobalFiSignal
                                                    : 0U));
        vlSelf->Mesh__DOT__mesh_3_1_io_in_control_0_propagate_b 
            = (((IData)(vlSelf->Mesh__DOT__mesh_2_1_io_in_control_0_propagate_b) 
                ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                    & (0xcU == vlSelf->GlobalFiNumber)) 
                   & vlSelf->GlobalFiSignal)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                  & (0x48U 
                                                     == vlSelf->GlobalFiNumber)) 
                                                 & vlSelf->GlobalFiSignal));
        vlSelf->Mesh__DOT__b_23_0 = ((((IData)(vlSelf->Mesh__DOT__mesh_2_1_io_in_control_0_propagate_b)
                                        ? (vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT___io_out_c_T 
                                           + (((0U 
                                                != (IData)(vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT__shift_offset)) 
                                               & ((0x1fU 
                                                   >= 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT__shift_offset) 
                                                       - (IData)(1U))))
                                                   ? 
                                                  VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT__c1, 
                                                                 (0x1fU 
                                                                  & ((IData)(vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT__shift_offset) 
                                                                     - (IData)(1U))))
                                                   : 
                                                  (- 
                                                   (vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT__c1 
                                                    >> 0x1fU)))) 
                                              & ((0U 
                                                  != 
                                                  ((2U 
                                                    > (IData)(vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT__shift_offset))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT__c1 
                                                    & (((0x1fU 
                                                         >= 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         ? 
                                                        ((IData)(1U) 
                                                         << 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         : 0U) 
                                                       - (IData)(1U))))) 
                                                 | vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT___io_out_c_T)))
                                        : (vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT___io_out_c_T_11 
                                           + (((0U 
                                                != (IData)(vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT__shift_offset)) 
                                               & ((0x1fU 
                                                   >= 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT__shift_offset) 
                                                       - (IData)(1U))))
                                                   ? 
                                                  VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT__c2, 
                                                                 (0x1fU 
                                                                  & ((IData)(vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT__shift_offset) 
                                                                     - (IData)(1U))))
                                                   : 
                                                  (- 
                                                   (vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT__c2 
                                                    >> 0x1fU)))) 
                                              & ((0U 
                                                  != 
                                                  ((2U 
                                                    > (IData)(vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT__shift_offset))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT__c2 
                                                    & (((0x1fU 
                                                         >= 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         ? 
                                                        ((IData)(1U) 
                                                         << 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         : 0U) 
                                                       - (IData)(1U))))) 
                                                 | vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT___io_out_c_T_11)))) 
                                      ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                                          & (0xaU == vlSelf->GlobalFiNumber))
                                          ? vlSelf->GlobalFiSignal
                                          : 0U)) ^ 
                                     (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                       & (0x45U == vlSelf->GlobalFiNumber))
                                       ? vlSelf->GlobalFiSignal
                                       : 0U));
    }
    if (vlSelf->Mesh__DOT__r_22_0) {
        vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT__last_s 
            = ((IData)(vlSelf->Mesh__DOT__mesh_2_1_io_in_control_0_propagate_b) 
               ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                   & (7U == vlSelf->GlobalFiNumber)) 
                  & vlSelf->GlobalFiSignal));
        if (vlSelf->Mesh__DOT__mesh_2_1_io_in_control_0_propagate_b) {
            vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT__c1 
                = (vlSelf->Mesh__DOT__b_22_0 ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                 & (3U 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
            vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT__c2 
                = (vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT___mac_unit_io_out_d 
                   ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                       & (4U == vlSelf->GlobalFiNumber))
                       ? vlSelf->GlobalFiSignal : 0U));
        } else {
            vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT__c1 
                = (vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT___mac_unit_io_out_d 
                   ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                       & (5U == vlSelf->GlobalFiNumber))
                       ? vlSelf->GlobalFiSignal : 0U));
            vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT__c2 
                = (vlSelf->Mesh__DOT__b_22_0 ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                 & (6U 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
        }
    }
    vlSelf->Mesh__DOT__r_77_0 = ((((IData)(vlSelf->Mesh__DOT__mesh_3_2_io_in_control_0_propagate_b)
                                    ? (vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT___io_out_c_T 
                                       + (((0U != (IData)(vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT__shift_offset)) 
                                           & ((0x1fU 
                                               >= (0x1fU 
                                                   & ((IData)(vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT__shift_offset) 
                                                      - (IData)(1U))))
                                               ? VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT__c1, 
                                                                (0x1fU 
                                                                 & ((IData)(vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT__shift_offset) 
                                                                    - (IData)(1U))))
                                               : (- 
                                                  (vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT__c1 
                                                   >> 0x1fU)))) 
                                          & ((0U != 
                                              ((2U 
                                                > (IData)(vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT__shift_offset))
                                                ? 0U
                                                : (vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT__c1 
                                                   & (((0x1fU 
                                                        >= 
                                                        (0x1fU 
                                                         & ((IData)(vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT__shift_offset) 
                                                            - (IData)(1U))))
                                                        ? 
                                                       ((IData)(1U) 
                                                        << 
                                                        (0x1fU 
                                                         & ((IData)(vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT__shift_offset) 
                                                            - (IData)(1U))))
                                                        : 0U) 
                                                      - (IData)(1U))))) 
                                             | vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT___io_out_c_T)))
                                    : (vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT___io_out_c_T_11 
                                       + (((0U != (IData)(vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT__shift_offset)) 
                                           & ((0x1fU 
                                               >= (0x1fU 
                                                   & ((IData)(vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT__shift_offset) 
                                                      - (IData)(1U))))
                                               ? VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT__c2, 
                                                                (0x1fU 
                                                                 & ((IData)(vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT__shift_offset) 
                                                                    - (IData)(1U))))
                                               : (- 
                                                  (vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT__c2 
                                                   >> 0x1fU)))) 
                                          & ((0U != 
                                              ((2U 
                                                > (IData)(vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT__shift_offset))
                                                ? 0U
                                                : (vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT__c2 
                                                   & (((0x1fU 
                                                        >= 
                                                        (0x1fU 
                                                         & ((IData)(vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT__shift_offset) 
                                                            - (IData)(1U))))
                                                        ? 
                                                       ((IData)(1U) 
                                                        << 
                                                        (0x1fU 
                                                         & ((IData)(vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT__shift_offset) 
                                                            - (IData)(1U))))
                                                        : 0U) 
                                                      - (IData)(1U))))) 
                                             | vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT___io_out_c_T_11)))) 
                                  ^ (((IData)(vlSelf->Mesh__DOT__mesh_3_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                                      & (0xaU == vlSelf->GlobalFiNumber))
                                      ? vlSelf->GlobalFiSignal
                                      : 0U)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                 & (0xaaU 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
    if (vlSelf->Mesh__DOT__r_27_0) {
        vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT__last_s 
            = ((IData)(vlSelf->Mesh__DOT__mesh_3_2_io_in_control_0_propagate_b) 
               ^ (((IData)(vlSelf->Mesh__DOT__mesh_3_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                   & (7U == vlSelf->GlobalFiNumber)) 
                  & vlSelf->GlobalFiSignal));
        if (vlSelf->Mesh__DOT__mesh_3_2_io_in_control_0_propagate_b) {
            vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT__c1 
                = (vlSelf->Mesh__DOT__b_27_0 ^ (((IData)(vlSelf->Mesh__DOT__mesh_3_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                 & (3U 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
            vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT__c2 
                = (vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT___mac_unit_io_out_d 
                   ^ (((IData)(vlSelf->Mesh__DOT__mesh_3_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                       & (4U == vlSelf->GlobalFiNumber))
                       ? vlSelf->GlobalFiSignal : 0U));
        } else {
            vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT__c1 
                = (vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT___mac_unit_io_out_d 
                   ^ (((IData)(vlSelf->Mesh__DOT__mesh_3_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                       & (5U == vlSelf->GlobalFiNumber))
                       ? vlSelf->GlobalFiSignal : 0U));
            vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT__c2 
                = (vlSelf->Mesh__DOT__b_27_0 ^ (((IData)(vlSelf->Mesh__DOT__mesh_3_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                 & (6U 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
        }
    }
    if (vlSelf->Mesh__DOT___mesh_2_2_io_out_valid_0) {
        vlSelf->Mesh__DOT__mesh_3_2_io_in_control_0_shift_b 
            = (0x1fU & (((IData)(vlSelf->Mesh__DOT__mesh_2_2_io_in_control_0_shift_b) 
                         ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                             & (0xdU == vlSelf->GlobalFiNumber))
                             ? vlSelf->GlobalFiSignal
                             : 0U)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                        & (0x5aU == vlSelf->GlobalFiNumber))
                                        ? vlSelf->GlobalFiSignal
                                        : 0U)));
        vlSelf->Mesh__DOT__b_11_0 = ((vlSelf->Mesh__DOT__b_10_0 
                                      ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                                          & (9U == vlSelf->GlobalFiNumber))
                                          ? vlSelf->GlobalFiSignal
                                          : 0U)) ^ 
                                     (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                       & (0x58U == vlSelf->GlobalFiNumber))
                                       ? vlSelf->GlobalFiSignal
                                       : 0U));
        vlSelf->Mesh__DOT__mesh_3_2_io_in_control_0_propagate_b 
            = (((IData)(vlSelf->Mesh__DOT__mesh_2_2_io_in_control_0_propagate_b) 
                ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                    & (0xcU == vlSelf->GlobalFiNumber)) 
                   & vlSelf->GlobalFiSignal)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                  & (0x5cU 
                                                     == vlSelf->GlobalFiNumber)) 
                                                 & vlSelf->GlobalFiSignal));
        vlSelf->Mesh__DOT__b_27_0 = ((((IData)(vlSelf->Mesh__DOT__mesh_2_2_io_in_control_0_propagate_b)
                                        ? (vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT___io_out_c_T 
                                           + (((0U 
                                                != (IData)(vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT__shift_offset)) 
                                               & ((0x1fU 
                                                   >= 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT__shift_offset) 
                                                       - (IData)(1U))))
                                                   ? 
                                                  VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT__c1, 
                                                                 (0x1fU 
                                                                  & ((IData)(vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT__shift_offset) 
                                                                     - (IData)(1U))))
                                                   : 
                                                  (- 
                                                   (vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT__c1 
                                                    >> 0x1fU)))) 
                                              & ((0U 
                                                  != 
                                                  ((2U 
                                                    > (IData)(vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT__shift_offset))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT__c1 
                                                    & (((0x1fU 
                                                         >= 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         ? 
                                                        ((IData)(1U) 
                                                         << 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         : 0U) 
                                                       - (IData)(1U))))) 
                                                 | vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT___io_out_c_T)))
                                        : (vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT___io_out_c_T_11 
                                           + (((0U 
                                                != (IData)(vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT__shift_offset)) 
                                               & ((0x1fU 
                                                   >= 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT__shift_offset) 
                                                       - (IData)(1U))))
                                                   ? 
                                                  VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT__c2, 
                                                                 (0x1fU 
                                                                  & ((IData)(vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT__shift_offset) 
                                                                     - (IData)(1U))))
                                                   : 
                                                  (- 
                                                   (vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT__c2 
                                                    >> 0x1fU)))) 
                                              & ((0U 
                                                  != 
                                                  ((2U 
                                                    > (IData)(vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT__shift_offset))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT__c2 
                                                    & (((0x1fU 
                                                         >= 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         ? 
                                                        ((IData)(1U) 
                                                         << 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         : 0U) 
                                                       - (IData)(1U))))) 
                                                 | vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT___io_out_c_T_11)))) 
                                      ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                                          & (0xaU == vlSelf->GlobalFiNumber))
                                          ? vlSelf->GlobalFiSignal
                                          : 0U)) ^ 
                                     (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                       & (0x59U == vlSelf->GlobalFiNumber))
                                       ? vlSelf->GlobalFiSignal
                                       : 0U));
    }
    if (vlSelf->Mesh__DOT__r_26_0) {
        vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT__last_s 
            = ((IData)(vlSelf->Mesh__DOT__mesh_2_2_io_in_control_0_propagate_b) 
               ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                   & (7U == vlSelf->GlobalFiNumber)) 
                  & vlSelf->GlobalFiSignal));
        if (vlSelf->Mesh__DOT__mesh_2_2_io_in_control_0_propagate_b) {
            vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT__c1 
                = (vlSelf->Mesh__DOT__b_26_0 ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                 & (3U 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
            vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT__c2 
                = (vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT___mac_unit_io_out_d 
                   ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                       & (4U == vlSelf->GlobalFiNumber))
                       ? vlSelf->GlobalFiSignal : 0U));
        } else {
            vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT__c1 
                = (vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT___mac_unit_io_out_d 
                   ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                       & (5U == vlSelf->GlobalFiNumber))
                       ? vlSelf->GlobalFiSignal : 0U));
            vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT__c2 
                = (vlSelf->Mesh__DOT__b_26_0 ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                 & (6U 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
        }
    }
    vlSelf->Mesh__DOT__r_65_0 = ((((IData)(vlSelf->Mesh__DOT__mesh_3_0_io_in_control_0_propagate_b)
                                    ? (vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT___io_out_c_T 
                                       + (((0U != (IData)(vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT__shift_offset)) 
                                           & ((0x1fU 
                                               >= (0x1fU 
                                                   & ((IData)(vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT__shift_offset) 
                                                      - (IData)(1U))))
                                               ? VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT__c1, 
                                                                (0x1fU 
                                                                 & ((IData)(vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT__shift_offset) 
                                                                    - (IData)(1U))))
                                               : (- 
                                                  (vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT__c1 
                                                   >> 0x1fU)))) 
                                          & ((0U != 
                                              ((2U 
                                                > (IData)(vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT__shift_offset))
                                                ? 0U
                                                : (vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT__c1 
                                                   & (((0x1fU 
                                                        >= 
                                                        (0x1fU 
                                                         & ((IData)(vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT__shift_offset) 
                                                            - (IData)(1U))))
                                                        ? 
                                                       ((IData)(1U) 
                                                        << 
                                                        (0x1fU 
                                                         & ((IData)(vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT__shift_offset) 
                                                            - (IData)(1U))))
                                                        : 0U) 
                                                      - (IData)(1U))))) 
                                             | vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT___io_out_c_T)))
                                    : (vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT___io_out_c_T_11 
                                       + (((0U != (IData)(vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT__shift_offset)) 
                                           & ((0x1fU 
                                               >= (0x1fU 
                                                   & ((IData)(vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT__shift_offset) 
                                                      - (IData)(1U))))
                                               ? VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT__c2, 
                                                                (0x1fU 
                                                                 & ((IData)(vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT__shift_offset) 
                                                                    - (IData)(1U))))
                                               : (- 
                                                  (vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT__c2 
                                                   >> 0x1fU)))) 
                                          & ((0U != 
                                              ((2U 
                                                > (IData)(vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT__shift_offset))
                                                ? 0U
                                                : (vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT__c2 
                                                   & (((0x1fU 
                                                        >= 
                                                        (0x1fU 
                                                         & ((IData)(vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT__shift_offset) 
                                                            - (IData)(1U))))
                                                        ? 
                                                       ((IData)(1U) 
                                                        << 
                                                        (0x1fU 
                                                         & ((IData)(vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT__shift_offset) 
                                                            - (IData)(1U))))
                                                        : 0U) 
                                                      - (IData)(1U))))) 
                                             | vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT___io_out_c_T_11)))) 
                                  ^ (((IData)(vlSelf->Mesh__DOT__mesh_3_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                                      & (0xaU == vlSelf->GlobalFiNumber))
                                      ? vlSelf->GlobalFiSignal
                                      : 0U)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                 & (0xa2U 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
    if (vlSelf->Mesh__DOT__r_19_0) {
        vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT__last_s 
            = ((IData)(vlSelf->Mesh__DOT__mesh_3_0_io_in_control_0_propagate_b) 
               ^ (((IData)(vlSelf->Mesh__DOT__mesh_3_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                   & (7U == vlSelf->GlobalFiNumber)) 
                  & vlSelf->GlobalFiSignal));
        if (vlSelf->Mesh__DOT__mesh_3_0_io_in_control_0_propagate_b) {
            vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT__c1 
                = (vlSelf->Mesh__DOT__b_19_0 ^ (((IData)(vlSelf->Mesh__DOT__mesh_3_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                 & (3U 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
            vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT__c2 
                = (vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT___mac_unit_io_out_d 
                   ^ (((IData)(vlSelf->Mesh__DOT__mesh_3_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                       & (4U == vlSelf->GlobalFiNumber))
                       ? vlSelf->GlobalFiSignal : 0U));
        } else {
            vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT__c1 
                = (vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT___mac_unit_io_out_d 
                   ^ (((IData)(vlSelf->Mesh__DOT__mesh_3_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                       & (5U == vlSelf->GlobalFiNumber))
                       ? vlSelf->GlobalFiSignal : 0U));
            vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT__c2 
                = (vlSelf->Mesh__DOT__b_19_0 ^ (((IData)(vlSelf->Mesh__DOT__mesh_3_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                 & (6U 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
        }
    }
    if (vlSelf->Mesh__DOT___mesh_2_0_io_out_valid_0) {
        vlSelf->Mesh__DOT__mesh_3_0_io_in_control_0_shift_b 
            = (0x1fU & (((IData)(vlSelf->Mesh__DOT__mesh_2_0_io_in_control_0_shift_b) 
                         ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                             & (0xdU == vlSelf->GlobalFiNumber))
                             ? vlSelf->GlobalFiSignal
                             : 0U)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                        & (0x32U == vlSelf->GlobalFiNumber))
                                        ? vlSelf->GlobalFiSignal
                                        : 0U)));
        vlSelf->Mesh__DOT__mesh_3_0_io_in_control_0_dataflow_b 
            = (((IData)(vlSelf->Mesh__DOT__mesh_2_0_io_in_control_0_dataflow_b) 
                ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                    & (0xbU == vlSelf->GlobalFiNumber)) 
                   & vlSelf->GlobalFiSignal)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                  & (0x33U 
                                                     == vlSelf->GlobalFiNumber)) 
                                                 & vlSelf->GlobalFiSignal));
        vlSelf->Mesh__DOT__b_3_0 = ((vlSelf->Mesh__DOT__b_2_0 
                                     ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                                         & (9U == vlSelf->GlobalFiNumber))
                                         ? vlSelf->GlobalFiSignal
                                         : 0U)) ^ (
                                                   ((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                    & (0x30U 
                                                       == vlSelf->GlobalFiNumber))
                                                    ? vlSelf->GlobalFiSignal
                                                    : 0U));
        vlSelf->Mesh__DOT__mesh_3_0_io_in_control_0_propagate_b 
            = (((IData)(vlSelf->Mesh__DOT__mesh_2_0_io_in_control_0_propagate_b) 
                ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                    & (0xcU == vlSelf->GlobalFiNumber)) 
                   & vlSelf->GlobalFiSignal)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                  & (0x34U 
                                                     == vlSelf->GlobalFiNumber)) 
                                                 & vlSelf->GlobalFiSignal));
        vlSelf->Mesh__DOT__b_19_0 = ((((IData)(vlSelf->Mesh__DOT__mesh_2_0_io_in_control_0_propagate_b)
                                        ? (vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT___io_out_c_T 
                                           + (((0U 
                                                != (IData)(vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT__shift_offset)) 
                                               & ((0x1fU 
                                                   >= 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT__shift_offset) 
                                                       - (IData)(1U))))
                                                   ? 
                                                  VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT__c1, 
                                                                 (0x1fU 
                                                                  & ((IData)(vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT__shift_offset) 
                                                                     - (IData)(1U))))
                                                   : 
                                                  (- 
                                                   (vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT__c1 
                                                    >> 0x1fU)))) 
                                              & ((0U 
                                                  != 
                                                  ((2U 
                                                    > (IData)(vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT__shift_offset))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT__c1 
                                                    & (((0x1fU 
                                                         >= 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         ? 
                                                        ((IData)(1U) 
                                                         << 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         : 0U) 
                                                       - (IData)(1U))))) 
                                                 | vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT___io_out_c_T)))
                                        : (vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT___io_out_c_T_11 
                                           + (((0U 
                                                != (IData)(vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT__shift_offset)) 
                                               & ((0x1fU 
                                                   >= 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT__shift_offset) 
                                                       - (IData)(1U))))
                                                   ? 
                                                  VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT__c2, 
                                                                 (0x1fU 
                                                                  & ((IData)(vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT__shift_offset) 
                                                                     - (IData)(1U))))
                                                   : 
                                                  (- 
                                                   (vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT__c2 
                                                    >> 0x1fU)))) 
                                              & ((0U 
                                                  != 
                                                  ((2U 
                                                    > (IData)(vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT__shift_offset))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT__c2 
                                                    & (((0x1fU 
                                                         >= 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         ? 
                                                        ((IData)(1U) 
                                                         << 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         : 0U) 
                                                       - (IData)(1U))))) 
                                                 | vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT___io_out_c_T_11)))) 
                                      ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                                          & (0xaU == vlSelf->GlobalFiNumber))
                                          ? vlSelf->GlobalFiSignal
                                          : 0U)) ^ 
                                     (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                       & (0x31U == vlSelf->GlobalFiNumber))
                                       ? vlSelf->GlobalFiSignal
                                       : 0U));
    }
    if (vlSelf->Mesh__DOT__r_18_0) {
        vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT__last_s 
            = ((IData)(vlSelf->Mesh__DOT__mesh_2_0_io_in_control_0_propagate_b) 
               ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                   & (7U == vlSelf->GlobalFiNumber)) 
                  & vlSelf->GlobalFiSignal));
        if (vlSelf->Mesh__DOT__mesh_2_0_io_in_control_0_propagate_b) {
            vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT__c1 
                = (vlSelf->Mesh__DOT__b_18_0 ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                 & (3U 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
            vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT__c2 
                = (vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT___mac_unit_io_out_d 
                   ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                       & (4U == vlSelf->GlobalFiNumber))
                       ? vlSelf->GlobalFiSignal : 0U));
        } else {
            vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT__c1 
                = (vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT___mac_unit_io_out_d 
                   ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                       & (5U == vlSelf->GlobalFiNumber))
                       ? vlSelf->GlobalFiSignal : 0U));
            vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT__c2 
                = (vlSelf->Mesh__DOT__b_18_0 ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                 & (6U 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
        }
    }
    vlSelf->Mesh__DOT__r_14_0 = ((vlSelf->Mesh__DOT__r_13_0 
                                  ^ (((IData)(vlSelf->Mesh__DOT__mesh_3_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                                      & (8U == vlSelf->GlobalFiNumber))
                                      ? vlSelf->GlobalFiSignal
                                      : 0U)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                 & (0x1fU 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
    vlSelf->Mesh__DOT__r_10_0 = ((vlSelf->Mesh__DOT__r_9_0 
                                  ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                                      & (8U == vlSelf->GlobalFiNumber))
                                      ? vlSelf->GlobalFiSignal
                                      : 0U)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                 & (0x1bU 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
    vlSelf->Mesh__DOT__r_6_0 = ((vlSelf->Mesh__DOT__r_5_0 
                                 ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                                     & (8U == vlSelf->GlobalFiNumber))
                                     ? vlSelf->GlobalFiSignal
                                     : 0U)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                & (0x17U 
                                                   == vlSelf->GlobalFiNumber))
                                                ? vlSelf->GlobalFiSignal
                                                : 0U));
    vlSelf->Mesh__DOT__r_2_0 = ((vlSelf->Mesh__DOT__r_1_0 
                                 ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                                     & (8U == vlSelf->GlobalFiNumber))
                                     ? vlSelf->GlobalFiSignal
                                     : 0U)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                & (0x13U 
                                                   == vlSelf->GlobalFiNumber))
                                                ? vlSelf->GlobalFiSignal
                                                : 0U));
    if (vlSelf->Mesh__DOT___mesh_1_3_io_out_valid_0) {
        vlSelf->Mesh__DOT__mesh_2_3_io_in_control_0_shift_b 
            = (0x1fU & (((IData)(vlSelf->Mesh__DOT__mesh_1_3_io_in_control_0_shift_b) 
                         ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                             & (0xdU == vlSelf->GlobalFiNumber))
                             ? vlSelf->GlobalFiSignal
                             : 0U)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                        & (0x69U == vlSelf->GlobalFiNumber))
                                        ? vlSelf->GlobalFiSignal
                                        : 0U)));
        vlSelf->Mesh__DOT__b_14_0 = ((vlSelf->Mesh__DOT__b_13_0 
                                      ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                                          & (9U == vlSelf->GlobalFiNumber))
                                          ? vlSelf->GlobalFiSignal
                                          : 0U)) ^ 
                                     (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                       & (0x67U == vlSelf->GlobalFiNumber))
                                       ? vlSelf->GlobalFiSignal
                                       : 0U));
        vlSelf->Mesh__DOT__mesh_2_3_io_in_control_0_propagate_b 
            = (((IData)(vlSelf->Mesh__DOT__mesh_1_3_io_in_control_0_propagate_b) 
                ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                    & (0xcU == vlSelf->GlobalFiNumber)) 
                   & vlSelf->GlobalFiSignal)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                  & (0x6bU 
                                                     == vlSelf->GlobalFiNumber)) 
                                                 & vlSelf->GlobalFiSignal));
        vlSelf->Mesh__DOT__b_30_0 = ((((IData)(vlSelf->Mesh__DOT__mesh_1_3_io_in_control_0_propagate_b)
                                        ? (vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT___io_out_c_T 
                                           + (((0U 
                                                != (IData)(vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT__shift_offset)) 
                                               & ((0x1fU 
                                                   >= 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT__shift_offset) 
                                                       - (IData)(1U))))
                                                   ? 
                                                  VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT__c1, 
                                                                 (0x1fU 
                                                                  & ((IData)(vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT__shift_offset) 
                                                                     - (IData)(1U))))
                                                   : 
                                                  (- 
                                                   (vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT__c1 
                                                    >> 0x1fU)))) 
                                              & ((0U 
                                                  != 
                                                  ((2U 
                                                    > (IData)(vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT__shift_offset))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT__c1 
                                                    & (((0x1fU 
                                                         >= 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         ? 
                                                        ((IData)(1U) 
                                                         << 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         : 0U) 
                                                       - (IData)(1U))))) 
                                                 | vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT___io_out_c_T)))
                                        : (vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT___io_out_c_T_11 
                                           + (((0U 
                                                != (IData)(vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT__shift_offset)) 
                                               & ((0x1fU 
                                                   >= 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT__shift_offset) 
                                                       - (IData)(1U))))
                                                   ? 
                                                  VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT__c2, 
                                                                 (0x1fU 
                                                                  & ((IData)(vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT__shift_offset) 
                                                                     - (IData)(1U))))
                                                   : 
                                                  (- 
                                                   (vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT__c2 
                                                    >> 0x1fU)))) 
                                              & ((0U 
                                                  != 
                                                  ((2U 
                                                    > (IData)(vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT__shift_offset))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT__c2 
                                                    & (((0x1fU 
                                                         >= 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         ? 
                                                        ((IData)(1U) 
                                                         << 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         : 0U) 
                                                       - (IData)(1U))))) 
                                                 | vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT___io_out_c_T_11)))) 
                                      ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                                          & (0xaU == vlSelf->GlobalFiNumber))
                                          ? vlSelf->GlobalFiSignal
                                          : 0U)) ^ 
                                     (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                       & (0x68U == vlSelf->GlobalFiNumber))
                                       ? vlSelf->GlobalFiSignal
                                       : 0U));
    }
    if (vlSelf->Mesh__DOT__r_29_0) {
        vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT__last_s 
            = ((IData)(vlSelf->Mesh__DOT__mesh_1_3_io_in_control_0_propagate_b) 
               ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                   & (7U == vlSelf->GlobalFiNumber)) 
                  & vlSelf->GlobalFiSignal));
        if (vlSelf->Mesh__DOT__mesh_1_3_io_in_control_0_propagate_b) {
            vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT__c1 
                = (vlSelf->Mesh__DOT__b_29_0 ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                 & (3U 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
            vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT__c2 
                = (vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT___mac_unit_io_out_d 
                   ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                       & (4U == vlSelf->GlobalFiNumber))
                       ? vlSelf->GlobalFiSignal : 0U));
        } else {
            vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT__c1 
                = (vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT___mac_unit_io_out_d 
                   ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                       & (5U == vlSelf->GlobalFiNumber))
                       ? vlSelf->GlobalFiSignal : 0U));
            vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT__c2 
                = (vlSelf->Mesh__DOT__b_29_0 ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                 & (6U 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
        }
    }
    if (vlSelf->Mesh__DOT___mesh_1_1_io_out_valid_0) {
        vlSelf->Mesh__DOT__mesh_2_1_io_in_control_0_shift_b 
            = (0x1fU & (((IData)(vlSelf->Mesh__DOT__mesh_1_1_io_in_control_0_shift_b) 
                         ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                             & (0xdU == vlSelf->GlobalFiNumber))
                             ? vlSelf->GlobalFiSignal
                             : 0U)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                        & (0x41U == vlSelf->GlobalFiNumber))
                                        ? vlSelf->GlobalFiSignal
                                        : 0U)));
        vlSelf->Mesh__DOT__b_6_0 = ((vlSelf->Mesh__DOT__b_5_0 
                                     ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                                         & (9U == vlSelf->GlobalFiNumber))
                                         ? vlSelf->GlobalFiSignal
                                         : 0U)) ^ (
                                                   ((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                    & (0x3fU 
                                                       == vlSelf->GlobalFiNumber))
                                                    ? vlSelf->GlobalFiSignal
                                                    : 0U));
        vlSelf->Mesh__DOT__mesh_2_1_io_in_control_0_propagate_b 
            = (((IData)(vlSelf->Mesh__DOT__mesh_1_1_io_in_control_0_propagate_b) 
                ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                    & (0xcU == vlSelf->GlobalFiNumber)) 
                   & vlSelf->GlobalFiSignal)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                  & (0x43U 
                                                     == vlSelf->GlobalFiNumber)) 
                                                 & vlSelf->GlobalFiSignal));
        vlSelf->Mesh__DOT__b_22_0 = ((((IData)(vlSelf->Mesh__DOT__mesh_1_1_io_in_control_0_propagate_b)
                                        ? (vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT___io_out_c_T 
                                           + (((0U 
                                                != (IData)(vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT__shift_offset)) 
                                               & ((0x1fU 
                                                   >= 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT__shift_offset) 
                                                       - (IData)(1U))))
                                                   ? 
                                                  VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT__c1, 
                                                                 (0x1fU 
                                                                  & ((IData)(vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT__shift_offset) 
                                                                     - (IData)(1U))))
                                                   : 
                                                  (- 
                                                   (vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT__c1 
                                                    >> 0x1fU)))) 
                                              & ((0U 
                                                  != 
                                                  ((2U 
                                                    > (IData)(vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT__shift_offset))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT__c1 
                                                    & (((0x1fU 
                                                         >= 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         ? 
                                                        ((IData)(1U) 
                                                         << 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         : 0U) 
                                                       - (IData)(1U))))) 
                                                 | vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT___io_out_c_T)))
                                        : (vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT___io_out_c_T_11 
                                           + (((0U 
                                                != (IData)(vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT__shift_offset)) 
                                               & ((0x1fU 
                                                   >= 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT__shift_offset) 
                                                       - (IData)(1U))))
                                                   ? 
                                                  VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT__c2, 
                                                                 (0x1fU 
                                                                  & ((IData)(vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT__shift_offset) 
                                                                     - (IData)(1U))))
                                                   : 
                                                  (- 
                                                   (vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT__c2 
                                                    >> 0x1fU)))) 
                                              & ((0U 
                                                  != 
                                                  ((2U 
                                                    > (IData)(vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT__shift_offset))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT__c2 
                                                    & (((0x1fU 
                                                         >= 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         ? 
                                                        ((IData)(1U) 
                                                         << 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         : 0U) 
                                                       - (IData)(1U))))) 
                                                 | vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT___io_out_c_T_11)))) 
                                      ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                                          & (0xaU == vlSelf->GlobalFiNumber))
                                          ? vlSelf->GlobalFiSignal
                                          : 0U)) ^ 
                                     (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                       & (0x40U == vlSelf->GlobalFiNumber))
                                       ? vlSelf->GlobalFiSignal
                                       : 0U));
    }
    if (vlSelf->Mesh__DOT__r_21_0) {
        vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT__last_s 
            = ((IData)(vlSelf->Mesh__DOT__mesh_1_1_io_in_control_0_propagate_b) 
               ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                   & (7U == vlSelf->GlobalFiNumber)) 
                  & vlSelf->GlobalFiSignal));
        if (vlSelf->Mesh__DOT__mesh_1_1_io_in_control_0_propagate_b) {
            vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT__c1 
                = (vlSelf->Mesh__DOT__b_21_0 ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                 & (3U 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
            vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT__c2 
                = (vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT___mac_unit_io_out_d 
                   ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                       & (4U == vlSelf->GlobalFiNumber))
                       ? vlSelf->GlobalFiSignal : 0U));
        } else {
            vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT__c1 
                = (vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT___mac_unit_io_out_d 
                   ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                       & (5U == vlSelf->GlobalFiNumber))
                       ? vlSelf->GlobalFiSignal : 0U));
            vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT__c2 
                = (vlSelf->Mesh__DOT__b_21_0 ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                 & (6U 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
        }
    }
    if (vlSelf->Mesh__DOT___mesh_1_2_io_out_valid_0) {
        vlSelf->Mesh__DOT__mesh_2_2_io_in_control_0_shift_b 
            = (0x1fU & (((IData)(vlSelf->Mesh__DOT__mesh_1_2_io_in_control_0_shift_b) 
                         ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                             & (0xdU == vlSelf->GlobalFiNumber))
                             ? vlSelf->GlobalFiSignal
                             : 0U)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                        & (0x55U == vlSelf->GlobalFiNumber))
                                        ? vlSelf->GlobalFiSignal
                                        : 0U)));
        vlSelf->Mesh__DOT__b_10_0 = ((vlSelf->Mesh__DOT__b_9_0 
                                      ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                                          & (9U == vlSelf->GlobalFiNumber))
                                          ? vlSelf->GlobalFiSignal
                                          : 0U)) ^ 
                                     (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                       & (0x53U == vlSelf->GlobalFiNumber))
                                       ? vlSelf->GlobalFiSignal
                                       : 0U));
        vlSelf->Mesh__DOT__mesh_2_2_io_in_control_0_propagate_b 
            = (((IData)(vlSelf->Mesh__DOT__mesh_1_2_io_in_control_0_propagate_b) 
                ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                    & (0xcU == vlSelf->GlobalFiNumber)) 
                   & vlSelf->GlobalFiSignal)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                  & (0x57U 
                                                     == vlSelf->GlobalFiNumber)) 
                                                 & vlSelf->GlobalFiSignal));
        vlSelf->Mesh__DOT__b_26_0 = ((((IData)(vlSelf->Mesh__DOT__mesh_1_2_io_in_control_0_propagate_b)
                                        ? (vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT___io_out_c_T 
                                           + (((0U 
                                                != (IData)(vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT__shift_offset)) 
                                               & ((0x1fU 
                                                   >= 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT__shift_offset) 
                                                       - (IData)(1U))))
                                                   ? 
                                                  VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT__c1, 
                                                                 (0x1fU 
                                                                  & ((IData)(vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT__shift_offset) 
                                                                     - (IData)(1U))))
                                                   : 
                                                  (- 
                                                   (vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT__c1 
                                                    >> 0x1fU)))) 
                                              & ((0U 
                                                  != 
                                                  ((2U 
                                                    > (IData)(vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT__shift_offset))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT__c1 
                                                    & (((0x1fU 
                                                         >= 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         ? 
                                                        ((IData)(1U) 
                                                         << 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         : 0U) 
                                                       - (IData)(1U))))) 
                                                 | vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT___io_out_c_T)))
                                        : (vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT___io_out_c_T_11 
                                           + (((0U 
                                                != (IData)(vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT__shift_offset)) 
                                               & ((0x1fU 
                                                   >= 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT__shift_offset) 
                                                       - (IData)(1U))))
                                                   ? 
                                                  VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT__c2, 
                                                                 (0x1fU 
                                                                  & ((IData)(vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT__shift_offset) 
                                                                     - (IData)(1U))))
                                                   : 
                                                  (- 
                                                   (vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT__c2 
                                                    >> 0x1fU)))) 
                                              & ((0U 
                                                  != 
                                                  ((2U 
                                                    > (IData)(vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT__shift_offset))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT__c2 
                                                    & (((0x1fU 
                                                         >= 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         ? 
                                                        ((IData)(1U) 
                                                         << 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         : 0U) 
                                                       - (IData)(1U))))) 
                                                 | vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT___io_out_c_T_11)))) 
                                      ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                                          & (0xaU == vlSelf->GlobalFiNumber))
                                          ? vlSelf->GlobalFiSignal
                                          : 0U)) ^ 
                                     (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                       & (0x54U == vlSelf->GlobalFiNumber))
                                       ? vlSelf->GlobalFiSignal
                                       : 0U));
    }
    if (vlSelf->Mesh__DOT__r_25_0) {
        vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT__last_s 
            = ((IData)(vlSelf->Mesh__DOT__mesh_1_2_io_in_control_0_propagate_b) 
               ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                   & (7U == vlSelf->GlobalFiNumber)) 
                  & vlSelf->GlobalFiSignal));
        if (vlSelf->Mesh__DOT__mesh_1_2_io_in_control_0_propagate_b) {
            vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT__c1 
                = (vlSelf->Mesh__DOT__b_25_0 ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                 & (3U 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
            vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT__c2 
                = (vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT___mac_unit_io_out_d 
                   ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                       & (4U == vlSelf->GlobalFiNumber))
                       ? vlSelf->GlobalFiSignal : 0U));
        } else {
            vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT__c1 
                = (vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT___mac_unit_io_out_d 
                   ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                       & (5U == vlSelf->GlobalFiNumber))
                       ? vlSelf->GlobalFiSignal : 0U));
            vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT__c2 
                = (vlSelf->Mesh__DOT__b_25_0 ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                 & (6U 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
        }
    }
    if (vlSelf->Mesh__DOT___mesh_1_0_io_out_valid_0) {
        vlSelf->Mesh__DOT__mesh_2_0_io_in_control_0_shift_b 
            = (0x1fU & (((IData)(vlSelf->Mesh__DOT__mesh_1_0_io_in_control_0_shift_b) 
                         ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                             & (0xdU == vlSelf->GlobalFiNumber))
                             ? vlSelf->GlobalFiSignal
                             : 0U)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                        & (0x2dU == vlSelf->GlobalFiNumber))
                                        ? vlSelf->GlobalFiSignal
                                        : 0U)));
        vlSelf->Mesh__DOT__mesh_2_0_io_in_control_0_dataflow_b 
            = (((IData)(vlSelf->Mesh__DOT__mesh_1_0_io_in_control_0_dataflow_b) 
                ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                    & (0xbU == vlSelf->GlobalFiNumber)) 
                   & vlSelf->GlobalFiSignal)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                  & (0x2eU 
                                                     == vlSelf->GlobalFiNumber)) 
                                                 & vlSelf->GlobalFiSignal));
        vlSelf->Mesh__DOT__b_2_0 = ((vlSelf->Mesh__DOT__b_1_0 
                                     ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                                         & (9U == vlSelf->GlobalFiNumber))
                                         ? vlSelf->GlobalFiSignal
                                         : 0U)) ^ (
                                                   ((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                    & (0x2bU 
                                                       == vlSelf->GlobalFiNumber))
                                                    ? vlSelf->GlobalFiSignal
                                                    : 0U));
        vlSelf->Mesh__DOT__mesh_2_0_io_in_control_0_propagate_b 
            = (((IData)(vlSelf->Mesh__DOT__mesh_1_0_io_in_control_0_propagate_b) 
                ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                    & (0xcU == vlSelf->GlobalFiNumber)) 
                   & vlSelf->GlobalFiSignal)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                  & (0x2fU 
                                                     == vlSelf->GlobalFiNumber)) 
                                                 & vlSelf->GlobalFiSignal));
        vlSelf->Mesh__DOT__b_18_0 = ((((IData)(vlSelf->Mesh__DOT__mesh_1_0_io_in_control_0_propagate_b)
                                        ? (vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT___io_out_c_T 
                                           + (((0U 
                                                != (IData)(vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT__shift_offset)) 
                                               & ((0x1fU 
                                                   >= 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT__shift_offset) 
                                                       - (IData)(1U))))
                                                   ? 
                                                  VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT__c1, 
                                                                 (0x1fU 
                                                                  & ((IData)(vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT__shift_offset) 
                                                                     - (IData)(1U))))
                                                   : 
                                                  (- 
                                                   (vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT__c1 
                                                    >> 0x1fU)))) 
                                              & ((0U 
                                                  != 
                                                  ((2U 
                                                    > (IData)(vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT__shift_offset))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT__c1 
                                                    & (((0x1fU 
                                                         >= 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         ? 
                                                        ((IData)(1U) 
                                                         << 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         : 0U) 
                                                       - (IData)(1U))))) 
                                                 | vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT___io_out_c_T)))
                                        : (vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT___io_out_c_T_11 
                                           + (((0U 
                                                != (IData)(vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT__shift_offset)) 
                                               & ((0x1fU 
                                                   >= 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT__shift_offset) 
                                                       - (IData)(1U))))
                                                   ? 
                                                  VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT__c2, 
                                                                 (0x1fU 
                                                                  & ((IData)(vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT__shift_offset) 
                                                                     - (IData)(1U))))
                                                   : 
                                                  (- 
                                                   (vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT__c2 
                                                    >> 0x1fU)))) 
                                              & ((0U 
                                                  != 
                                                  ((2U 
                                                    > (IData)(vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT__shift_offset))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT__c2 
                                                    & (((0x1fU 
                                                         >= 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         ? 
                                                        ((IData)(1U) 
                                                         << 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         : 0U) 
                                                       - (IData)(1U))))) 
                                                 | vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT___io_out_c_T_11)))) 
                                      ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                                          & (0xaU == vlSelf->GlobalFiNumber))
                                          ? vlSelf->GlobalFiSignal
                                          : 0U)) ^ 
                                     (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                       & (0x2cU == vlSelf->GlobalFiNumber))
                                       ? vlSelf->GlobalFiSignal
                                       : 0U));
    }
    if (vlSelf->Mesh__DOT__r_17_0) {
        vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT__last_s 
            = ((IData)(vlSelf->Mesh__DOT__mesh_1_0_io_in_control_0_propagate_b) 
               ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                   & (7U == vlSelf->GlobalFiNumber)) 
                  & vlSelf->GlobalFiSignal));
        if (vlSelf->Mesh__DOT__mesh_1_0_io_in_control_0_propagate_b) {
            vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT__c1 
                = (vlSelf->Mesh__DOT__b_17_0 ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                 & (3U 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
            vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT__c2 
                = (vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT___mac_unit_io_out_d 
                   ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                       & (4U == vlSelf->GlobalFiNumber))
                       ? vlSelf->GlobalFiSignal : 0U));
        } else {
            vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT__c1 
                = (vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT___mac_unit_io_out_d 
                   ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                       & (5U == vlSelf->GlobalFiNumber))
                       ? vlSelf->GlobalFiSignal : 0U));
            vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT__c2 
                = (vlSelf->Mesh__DOT__b_17_0 ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                 & (6U 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
        }
    }
    vlSelf->Mesh__DOT__r_51_0 = (((IData)(vlSelf->Mesh__DOT__r_50_0) 
                                  ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                                      & (0xfU == vlSelf->GlobalFiNumber)) 
                                     & vlSelf->GlobalFiSignal)) 
                                 ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                     & (0x94U == vlSelf->GlobalFiNumber)) 
                                    & vlSelf->GlobalFiSignal));
    vlSelf->Mesh__DOT__r_35_0 = (7U & (((IData)(vlSelf->Mesh__DOT__r_34_0) 
                                        ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                                            & (0xeU 
                                               == vlSelf->GlobalFiNumber))
                                            ? vlSelf->GlobalFiSignal
                                            : 0U)) 
                                       ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                           & (0x84U 
                                              == vlSelf->GlobalFiNumber))
                                           ? vlSelf->GlobalFiSignal
                                           : 0U)));
    vlSelf->Mesh__DOT__r_13_0 = ((vlSelf->Mesh__DOT__r_12_0 
                                  ^ (((IData)(vlSelf->Mesh__DOT__mesh_3_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                                      & (8U == vlSelf->GlobalFiNumber))
                                      ? vlSelf->GlobalFiSignal
                                      : 0U)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                 & (0x1eU 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
    vlSelf->Mesh__DOT__r_9_0 = ((vlSelf->Mesh__DOT__r_8_0 
                                 ^ (((IData)(vlSelf->Mesh__DOT__mesh_2_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                                     & (8U == vlSelf->GlobalFiNumber))
                                     ? vlSelf->GlobalFiSignal
                                     : 0U)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                & (0x1aU 
                                                   == vlSelf->GlobalFiNumber))
                                                ? vlSelf->GlobalFiSignal
                                                : 0U));
    vlSelf->Mesh__DOT__r_5_0 = ((vlSelf->Mesh__DOT__r_4_0 
                                 ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                                     & (8U == vlSelf->GlobalFiNumber))
                                     ? vlSelf->GlobalFiSignal
                                     : 0U)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                & (0x16U 
                                                   == vlSelf->GlobalFiNumber))
                                                ? vlSelf->GlobalFiSignal
                                                : 0U));
    vlSelf->Mesh__DOT__r_1_0 = ((vlSelf->Mesh__DOT__r_0 
                                 ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                                     & (8U == vlSelf->GlobalFiNumber))
                                     ? vlSelf->GlobalFiSignal
                                     : 0U)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                & (0x12U 
                                                   == vlSelf->GlobalFiNumber))
                                                ? vlSelf->GlobalFiSignal
                                                : 0U));
    if (vlSelf->Mesh__DOT___mesh_0_3_io_out_valid_0) {
        vlSelf->Mesh__DOT__mesh_1_3_io_in_control_0_shift_b 
            = (0x1fU & (((IData)(vlSelf->Mesh__DOT__mesh_0_3_io_in_control_0_shift_b) 
                         ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                             & (0xdU == vlSelf->GlobalFiNumber))
                             ? vlSelf->GlobalFiSignal
                             : 0U)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                        & (0x64U == vlSelf->GlobalFiNumber))
                                        ? vlSelf->GlobalFiSignal
                                        : 0U)));
        vlSelf->Mesh__DOT__b_13_0 = ((vlSelf->Mesh__DOT__b_12_0 
                                      ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                                          & (9U == vlSelf->GlobalFiNumber))
                                          ? vlSelf->GlobalFiSignal
                                          : 0U)) ^ 
                                     (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                       & (0x62U == vlSelf->GlobalFiNumber))
                                       ? vlSelf->GlobalFiSignal
                                       : 0U));
        vlSelf->Mesh__DOT__mesh_1_3_io_in_control_0_propagate_b 
            = (((IData)(vlSelf->Mesh__DOT__mesh_0_3_io_in_control_0_propagate_b) 
                ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                    & (0xcU == vlSelf->GlobalFiNumber)) 
                   & vlSelf->GlobalFiSignal)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                  & (0x66U 
                                                     == vlSelf->GlobalFiNumber)) 
                                                 & vlSelf->GlobalFiSignal));
        vlSelf->Mesh__DOT__b_29_0 = ((((IData)(vlSelf->Mesh__DOT__mesh_0_3_io_in_control_0_propagate_b)
                                        ? (vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT___io_out_c_T 
                                           + (((0U 
                                                != (IData)(vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT__shift_offset)) 
                                               & ((0x1fU 
                                                   >= 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT__shift_offset) 
                                                       - (IData)(1U))))
                                                   ? 
                                                  VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT__c1, 
                                                                 (0x1fU 
                                                                  & ((IData)(vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT__shift_offset) 
                                                                     - (IData)(1U))))
                                                   : 
                                                  (- 
                                                   (vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT__c1 
                                                    >> 0x1fU)))) 
                                              & ((0U 
                                                  != 
                                                  ((2U 
                                                    > (IData)(vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT__shift_offset))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT__c1 
                                                    & (((0x1fU 
                                                         >= 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         ? 
                                                        ((IData)(1U) 
                                                         << 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         : 0U) 
                                                       - (IData)(1U))))) 
                                                 | vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT___io_out_c_T)))
                                        : (vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT___io_out_c_T_11 
                                           + (((0U 
                                                != (IData)(vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT__shift_offset)) 
                                               & ((0x1fU 
                                                   >= 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT__shift_offset) 
                                                       - (IData)(1U))))
                                                   ? 
                                                  VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT__c2, 
                                                                 (0x1fU 
                                                                  & ((IData)(vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT__shift_offset) 
                                                                     - (IData)(1U))))
                                                   : 
                                                  (- 
                                                   (vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT__c2 
                                                    >> 0x1fU)))) 
                                              & ((0U 
                                                  != 
                                                  ((2U 
                                                    > (IData)(vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT__shift_offset))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT__c2 
                                                    & (((0x1fU 
                                                         >= 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         ? 
                                                        ((IData)(1U) 
                                                         << 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         : 0U) 
                                                       - (IData)(1U))))) 
                                                 | vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT___io_out_c_T_11)))) 
                                      ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                                          & (0xaU == vlSelf->GlobalFiNumber))
                                          ? vlSelf->GlobalFiSignal
                                          : 0U)) ^ 
                                     (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                       & (0x63U == vlSelf->GlobalFiNumber))
                                       ? vlSelf->GlobalFiSignal
                                       : 0U));
    }
    if (vlSelf->Mesh__DOT__r_28_0) {
        vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT__last_s 
            = ((IData)(vlSelf->Mesh__DOT__mesh_0_3_io_in_control_0_propagate_b) 
               ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                   & (7U == vlSelf->GlobalFiNumber)) 
                  & vlSelf->GlobalFiSignal));
        if (vlSelf->Mesh__DOT__mesh_0_3_io_in_control_0_propagate_b) {
            vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT__c1 
                = (vlSelf->Mesh__DOT__b_28_0 ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                 & (3U 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
            vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT__c2 
                = (vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT___mac_unit_io_out_d 
                   ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                       & (4U == vlSelf->GlobalFiNumber))
                       ? vlSelf->GlobalFiSignal : 0U));
        } else {
            vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT__c1 
                = (vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT___mac_unit_io_out_d 
                   ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                       & (5U == vlSelf->GlobalFiNumber))
                       ? vlSelf->GlobalFiSignal : 0U));
            vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT__c2 
                = (vlSelf->Mesh__DOT__b_28_0 ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                 & (6U 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
        }
    }
    if (vlSelf->Mesh__DOT___mesh_0_1_io_out_valid_0) {
        vlSelf->Mesh__DOT__mesh_1_1_io_in_control_0_shift_b 
            = (0x1fU & (((IData)(vlSelf->Mesh__DOT__mesh_0_1_io_in_control_0_shift_b) 
                         ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                             & (0xdU == vlSelf->GlobalFiNumber))
                             ? vlSelf->GlobalFiSignal
                             : 0U)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                        & (0x3cU == vlSelf->GlobalFiNumber))
                                        ? vlSelf->GlobalFiSignal
                                        : 0U)));
        vlSelf->Mesh__DOT__b_5_0 = ((vlSelf->Mesh__DOT__b_4_0 
                                     ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                                         & (9U == vlSelf->GlobalFiNumber))
                                         ? vlSelf->GlobalFiSignal
                                         : 0U)) ^ (
                                                   ((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                    & (0x3aU 
                                                       == vlSelf->GlobalFiNumber))
                                                    ? vlSelf->GlobalFiSignal
                                                    : 0U));
        vlSelf->Mesh__DOT__mesh_1_1_io_in_control_0_propagate_b 
            = (((IData)(vlSelf->Mesh__DOT__mesh_0_1_io_in_control_0_propagate_b) 
                ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                    & (0xcU == vlSelf->GlobalFiNumber)) 
                   & vlSelf->GlobalFiSignal)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                  & (0x3eU 
                                                     == vlSelf->GlobalFiNumber)) 
                                                 & vlSelf->GlobalFiSignal));
        vlSelf->Mesh__DOT__b_21_0 = ((((IData)(vlSelf->Mesh__DOT__mesh_0_1_io_in_control_0_propagate_b)
                                        ? (vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT___io_out_c_T 
                                           + (((0U 
                                                != (IData)(vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT__shift_offset)) 
                                               & ((0x1fU 
                                                   >= 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT__shift_offset) 
                                                       - (IData)(1U))))
                                                   ? 
                                                  VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT__c1, 
                                                                 (0x1fU 
                                                                  & ((IData)(vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT__shift_offset) 
                                                                     - (IData)(1U))))
                                                   : 
                                                  (- 
                                                   (vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT__c1 
                                                    >> 0x1fU)))) 
                                              & ((0U 
                                                  != 
                                                  ((2U 
                                                    > (IData)(vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT__shift_offset))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT__c1 
                                                    & (((0x1fU 
                                                         >= 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         ? 
                                                        ((IData)(1U) 
                                                         << 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         : 0U) 
                                                       - (IData)(1U))))) 
                                                 | vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT___io_out_c_T)))
                                        : (vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT___io_out_c_T_11 
                                           + (((0U 
                                                != (IData)(vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT__shift_offset)) 
                                               & ((0x1fU 
                                                   >= 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT__shift_offset) 
                                                       - (IData)(1U))))
                                                   ? 
                                                  VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT__c2, 
                                                                 (0x1fU 
                                                                  & ((IData)(vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT__shift_offset) 
                                                                     - (IData)(1U))))
                                                   : 
                                                  (- 
                                                   (vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT__c2 
                                                    >> 0x1fU)))) 
                                              & ((0U 
                                                  != 
                                                  ((2U 
                                                    > (IData)(vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT__shift_offset))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT__c2 
                                                    & (((0x1fU 
                                                         >= 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         ? 
                                                        ((IData)(1U) 
                                                         << 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         : 0U) 
                                                       - (IData)(1U))))) 
                                                 | vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT___io_out_c_T_11)))) 
                                      ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                                          & (0xaU == vlSelf->GlobalFiNumber))
                                          ? vlSelf->GlobalFiSignal
                                          : 0U)) ^ 
                                     (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                       & (0x3bU == vlSelf->GlobalFiNumber))
                                       ? vlSelf->GlobalFiSignal
                                       : 0U));
    }
    if (vlSelf->Mesh__DOT__r_20_0) {
        vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT__last_s 
            = ((IData)(vlSelf->Mesh__DOT__mesh_0_1_io_in_control_0_propagate_b) 
               ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                   & (7U == vlSelf->GlobalFiNumber)) 
                  & vlSelf->GlobalFiSignal));
        if (vlSelf->Mesh__DOT__mesh_0_1_io_in_control_0_propagate_b) {
            vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT__c1 
                = (vlSelf->Mesh__DOT__b_20_0 ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                 & (3U 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
            vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT__c2 
                = (vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT___mac_unit_io_out_d 
                   ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                       & (4U == vlSelf->GlobalFiNumber))
                       ? vlSelf->GlobalFiSignal : 0U));
        } else {
            vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT__c1 
                = (vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT___mac_unit_io_out_d 
                   ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                       & (5U == vlSelf->GlobalFiNumber))
                       ? vlSelf->GlobalFiSignal : 0U));
            vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT__c2 
                = (vlSelf->Mesh__DOT__b_20_0 ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                 & (6U 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
        }
    }
    if (vlSelf->Mesh__DOT___mesh_0_2_io_out_valid_0) {
        vlSelf->Mesh__DOT__mesh_1_2_io_in_control_0_shift_b 
            = (0x1fU & (((IData)(vlSelf->Mesh__DOT__mesh_0_2_io_in_control_0_shift_b) 
                         ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                             & (0xdU == vlSelf->GlobalFiNumber))
                             ? vlSelf->GlobalFiSignal
                             : 0U)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                        & (0x50U == vlSelf->GlobalFiNumber))
                                        ? vlSelf->GlobalFiSignal
                                        : 0U)));
        vlSelf->Mesh__DOT__b_9_0 = ((vlSelf->Mesh__DOT__b_8_0 
                                     ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                                         & (9U == vlSelf->GlobalFiNumber))
                                         ? vlSelf->GlobalFiSignal
                                         : 0U)) ^ (
                                                   ((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                    & (0x4eU 
                                                       == vlSelf->GlobalFiNumber))
                                                    ? vlSelf->GlobalFiSignal
                                                    : 0U));
        vlSelf->Mesh__DOT__mesh_1_2_io_in_control_0_propagate_b 
            = (((IData)(vlSelf->Mesh__DOT__mesh_0_2_io_in_control_0_propagate_b) 
                ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                    & (0xcU == vlSelf->GlobalFiNumber)) 
                   & vlSelf->GlobalFiSignal)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                  & (0x52U 
                                                     == vlSelf->GlobalFiNumber)) 
                                                 & vlSelf->GlobalFiSignal));
        vlSelf->Mesh__DOT__b_25_0 = ((((IData)(vlSelf->Mesh__DOT__mesh_0_2_io_in_control_0_propagate_b)
                                        ? (vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT___io_out_c_T 
                                           + (((0U 
                                                != (IData)(vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT__shift_offset)) 
                                               & ((0x1fU 
                                                   >= 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT__shift_offset) 
                                                       - (IData)(1U))))
                                                   ? 
                                                  VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT__c1, 
                                                                 (0x1fU 
                                                                  & ((IData)(vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT__shift_offset) 
                                                                     - (IData)(1U))))
                                                   : 
                                                  (- 
                                                   (vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT__c1 
                                                    >> 0x1fU)))) 
                                              & ((0U 
                                                  != 
                                                  ((2U 
                                                    > (IData)(vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT__shift_offset))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT__c1 
                                                    & (((0x1fU 
                                                         >= 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         ? 
                                                        ((IData)(1U) 
                                                         << 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         : 0U) 
                                                       - (IData)(1U))))) 
                                                 | vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT___io_out_c_T)))
                                        : (vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT___io_out_c_T_11 
                                           + (((0U 
                                                != (IData)(vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT__shift_offset)) 
                                               & ((0x1fU 
                                                   >= 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT__shift_offset) 
                                                       - (IData)(1U))))
                                                   ? 
                                                  VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT__c2, 
                                                                 (0x1fU 
                                                                  & ((IData)(vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT__shift_offset) 
                                                                     - (IData)(1U))))
                                                   : 
                                                  (- 
                                                   (vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT__c2 
                                                    >> 0x1fU)))) 
                                              & ((0U 
                                                  != 
                                                  ((2U 
                                                    > (IData)(vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT__shift_offset))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT__c2 
                                                    & (((0x1fU 
                                                         >= 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         ? 
                                                        ((IData)(1U) 
                                                         << 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         : 0U) 
                                                       - (IData)(1U))))) 
                                                 | vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT___io_out_c_T_11)))) 
                                      ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                                          & (0xaU == vlSelf->GlobalFiNumber))
                                          ? vlSelf->GlobalFiSignal
                                          : 0U)) ^ 
                                     (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                       & (0x4fU == vlSelf->GlobalFiNumber))
                                       ? vlSelf->GlobalFiSignal
                                       : 0U));
    }
    if (vlSelf->Mesh__DOT__r_24_0) {
        vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT__last_s 
            = ((IData)(vlSelf->Mesh__DOT__mesh_0_2_io_in_control_0_propagate_b) 
               ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                   & (7U == vlSelf->GlobalFiNumber)) 
                  & vlSelf->GlobalFiSignal));
        if (vlSelf->Mesh__DOT__mesh_0_2_io_in_control_0_propagate_b) {
            vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT__c1 
                = (vlSelf->Mesh__DOT__b_24_0 ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                 & (3U 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
            vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT__c2 
                = (vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT___mac_unit_io_out_d 
                   ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                       & (4U == vlSelf->GlobalFiNumber))
                       ? vlSelf->GlobalFiSignal : 0U));
        } else {
            vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT__c1 
                = (vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT___mac_unit_io_out_d 
                   ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                       & (5U == vlSelf->GlobalFiNumber))
                       ? vlSelf->GlobalFiSignal : 0U));
            vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT__c2 
                = (vlSelf->Mesh__DOT__b_24_0 ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                 & (6U 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
        }
    }
    if (vlSelf->Mesh__DOT___mesh_0_0_io_out_valid_0) {
        vlSelf->Mesh__DOT__mesh_1_0_io_in_control_0_shift_b 
            = (0x1fU & (((IData)(vlSelf->Mesh__DOT__mesh_0_0_io_in_control_0_shift_b) 
                         ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                             & (0xdU == vlSelf->GlobalFiNumber))
                             ? vlSelf->GlobalFiSignal
                             : 0U)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                        & (0x28U == vlSelf->GlobalFiNumber))
                                        ? vlSelf->GlobalFiSignal
                                        : 0U)));
        vlSelf->Mesh__DOT__mesh_1_0_io_in_control_0_dataflow_b 
            = (((IData)(vlSelf->Mesh__DOT__mesh_0_0_io_in_control_0_dataflow_b) 
                ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                    & (0xbU == vlSelf->GlobalFiNumber)) 
                   & vlSelf->GlobalFiSignal)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                  & (0x29U 
                                                     == vlSelf->GlobalFiNumber)) 
                                                 & vlSelf->GlobalFiSignal));
        vlSelf->Mesh__DOT__b_1_0 = ((vlSelf->Mesh__DOT__b_0 
                                     ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                                         & (9U == vlSelf->GlobalFiNumber))
                                         ? vlSelf->GlobalFiSignal
                                         : 0U)) ^ (
                                                   ((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                    & (0x26U 
                                                       == vlSelf->GlobalFiNumber))
                                                    ? vlSelf->GlobalFiSignal
                                                    : 0U));
        vlSelf->Mesh__DOT__mesh_1_0_io_in_control_0_propagate_b 
            = (((IData)(vlSelf->Mesh__DOT__mesh_0_0_io_in_control_0_propagate_b) 
                ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                    & (0xcU == vlSelf->GlobalFiNumber)) 
                   & vlSelf->GlobalFiSignal)) ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                                  & (0x2aU 
                                                     == vlSelf->GlobalFiNumber)) 
                                                 & vlSelf->GlobalFiSignal));
        vlSelf->Mesh__DOT__b_17_0 = ((((IData)(vlSelf->Mesh__DOT__mesh_0_0_io_in_control_0_propagate_b)
                                        ? (vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT___io_out_c_T 
                                           + (((0U 
                                                != (IData)(vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT__shift_offset)) 
                                               & ((0x1fU 
                                                   >= 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT__shift_offset) 
                                                       - (IData)(1U))))
                                                   ? 
                                                  VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT__c1, 
                                                                 (0x1fU 
                                                                  & ((IData)(vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT__shift_offset) 
                                                                     - (IData)(1U))))
                                                   : 
                                                  (- 
                                                   (vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT__c1 
                                                    >> 0x1fU)))) 
                                              & ((0U 
                                                  != 
                                                  ((2U 
                                                    > (IData)(vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT__shift_offset))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT__c1 
                                                    & (((0x1fU 
                                                         >= 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         ? 
                                                        ((IData)(1U) 
                                                         << 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         : 0U) 
                                                       - (IData)(1U))))) 
                                                 | vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT___io_out_c_T)))
                                        : (vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT___io_out_c_T_11 
                                           + (((0U 
                                                != (IData)(vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT__shift_offset)) 
                                               & ((0x1fU 
                                                   >= 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT__shift_offset) 
                                                       - (IData)(1U))))
                                                   ? 
                                                  VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT__c2, 
                                                                 (0x1fU 
                                                                  & ((IData)(vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT__shift_offset) 
                                                                     - (IData)(1U))))
                                                   : 
                                                  (- 
                                                   (vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT__c2 
                                                    >> 0x1fU)))) 
                                              & ((0U 
                                                  != 
                                                  ((2U 
                                                    > (IData)(vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT__shift_offset))
                                                    ? 0U
                                                    : 
                                                   (vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT__c2 
                                                    & (((0x1fU 
                                                         >= 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         ? 
                                                        ((IData)(1U) 
                                                         << 
                                                         (0x1fU 
                                                          & ((IData)(vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT__shift_offset) 
                                                             - (IData)(1U))))
                                                         : 0U) 
                                                       - (IData)(1U))))) 
                                                 | vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT___io_out_c_T_11)))) 
                                      ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                                          & (0xaU == vlSelf->GlobalFiNumber))
                                          ? vlSelf->GlobalFiSignal
                                          : 0U)) ^ 
                                     (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                       & (0x27U == vlSelf->GlobalFiNumber))
                                       ? vlSelf->GlobalFiSignal
                                       : 0U));
    }
    if (vlSelf->Mesh__DOT__r_16_0) {
        vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT__last_s 
            = ((IData)(vlSelf->Mesh__DOT__mesh_0_0_io_in_control_0_propagate_b) 
               ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                   & (7U == vlSelf->GlobalFiNumber)) 
                  & vlSelf->GlobalFiSignal));
        if (vlSelf->Mesh__DOT__mesh_0_0_io_in_control_0_propagate_b) {
            vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT__c1 
                = (vlSelf->Mesh__DOT__b_16_0 ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                 & (3U 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
            vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT__c2 
                = (vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT___mac_unit_io_out_d 
                   ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                       & (4U == vlSelf->GlobalFiNumber))
                       ? vlSelf->GlobalFiSignal : 0U));
        } else {
            vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT__c1 
                = (vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT___mac_unit_io_out_d 
                   ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                       & (5U == vlSelf->GlobalFiNumber))
                       ? vlSelf->GlobalFiSignal : 0U));
            vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT__c2 
                = (vlSelf->Mesh__DOT__b_16_0 ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                 & (6U 
                                                    == vlSelf->GlobalFiNumber))
                                                 ? vlSelf->GlobalFiSignal
                                                 : 0U));
        }
    }
    vlSelf->Mesh__DOT__r_50_0 = (((IData)(vlSelf->Mesh__DOT__r_49_0) 
                                  ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                                      & (0xfU == vlSelf->GlobalFiNumber)) 
                                     & vlSelf->GlobalFiSignal)) 
                                 ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                     & (0x93U == vlSelf->GlobalFiNumber)) 
                                    & vlSelf->GlobalFiSignal));
    vlSelf->Mesh__DOT__r_34_0 = (7U & (((IData)(vlSelf->Mesh__DOT__r_33_0) 
                                        ^ (((IData)(vlSelf->Mesh__DOT__mesh_1_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                                            & (0xeU 
                                               == vlSelf->GlobalFiNumber))
                                            ? vlSelf->GlobalFiSignal
                                            : 0U)) 
                                       ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                           & (0x83U 
                                              == vlSelf->GlobalFiNumber))
                                           ? vlSelf->GlobalFiSignal
                                           : 0U)));
    vlSelf->Mesh__DOT__r_31_0 = ((IData)(vlSelf->Mesh__DOT___mesh_2_3_io_out_valid_0) 
                                 ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                     & (0x80U == vlSelf->GlobalFiNumber)) 
                                    & vlSelf->GlobalFiSignal));
    vlSelf->Mesh__DOT__r_23_0 = ((IData)(vlSelf->Mesh__DOT___mesh_2_1_io_out_valid_0) 
                                 ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                     & (0x78U == vlSelf->GlobalFiNumber)) 
                                    & vlSelf->GlobalFiSignal));
    vlSelf->Mesh__DOT__r_27_0 = ((IData)(vlSelf->Mesh__DOT___mesh_2_2_io_out_valid_0) 
                                 ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                     & (0x7cU == vlSelf->GlobalFiNumber)) 
                                    & vlSelf->GlobalFiSignal));
    vlSelf->Mesh__DOT__r_19_0 = ((IData)(vlSelf->Mesh__DOT___mesh_2_0_io_out_valid_0) 
                                 ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                     & (0x74U == vlSelf->GlobalFiNumber)) 
                                    & vlSelf->GlobalFiSignal));
    vlSelf->Mesh__DOT__r_12_0 = (vlSelf->io_in_a_3_0 
                                 ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                     & (0x1dU == vlSelf->GlobalFiNumber))
                                     ? vlSelf->GlobalFiSignal
                                     : 0U));
    vlSelf->Mesh__DOT__r_8_0 = (vlSelf->io_in_a_2_0 
                                ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                    & (0x19U == vlSelf->GlobalFiNumber))
                                    ? vlSelf->GlobalFiSignal
                                    : 0U));
    vlSelf->Mesh__DOT__r_4_0 = (vlSelf->io_in_a_1_0 
                                ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                    & (0x15U == vlSelf->GlobalFiNumber))
                                    ? vlSelf->GlobalFiSignal
                                    : 0U));
    vlSelf->Mesh__DOT__r_0 = (vlSelf->io_in_a_0_0 ^ 
                              (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                & (0x11U == vlSelf->GlobalFiNumber))
                                ? vlSelf->GlobalFiSignal
                                : 0U));
    if (vlSelf->io_in_valid_3_0) {
        vlSelf->Mesh__DOT__mesh_0_3_io_in_control_0_shift_b 
            = (0x1fU & ((IData)(vlSelf->io_in_control_3_0_shift) 
                        ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                            & (0x5fU == vlSelf->GlobalFiNumber))
                            ? vlSelf->GlobalFiSignal
                            : 0U)));
        vlSelf->Mesh__DOT__b_12_0 = (vlSelf->io_in_b_3_0 
                                     ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                         & (0x5dU == vlSelf->GlobalFiNumber))
                                         ? vlSelf->GlobalFiSignal
                                         : 0U));
        vlSelf->Mesh__DOT__b_28_0 = (vlSelf->io_in_d_3_0 
                                     ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                         & (0x5eU == vlSelf->GlobalFiNumber))
                                         ? vlSelf->GlobalFiSignal
                                         : 0U));
        vlSelf->Mesh__DOT__mesh_0_3_io_in_control_0_propagate_b 
            = ((IData)(vlSelf->io_in_control_3_0_propagate) 
               ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                   & (0x61U == vlSelf->GlobalFiNumber)) 
                  & vlSelf->GlobalFiSignal));
    }
    if (vlSelf->io_in_valid_1_0) {
        vlSelf->Mesh__DOT__mesh_0_1_io_in_control_0_shift_b 
            = (0x1fU & ((IData)(vlSelf->io_in_control_1_0_shift) 
                        ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                            & (0x37U == vlSelf->GlobalFiNumber))
                            ? vlSelf->GlobalFiSignal
                            : 0U)));
        vlSelf->Mesh__DOT__b_4_0 = (vlSelf->io_in_b_1_0 
                                    ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                        & (0x35U == vlSelf->GlobalFiNumber))
                                        ? vlSelf->GlobalFiSignal
                                        : 0U));
        vlSelf->Mesh__DOT__b_20_0 = (vlSelf->io_in_d_1_0 
                                     ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                         & (0x36U == vlSelf->GlobalFiNumber))
                                         ? vlSelf->GlobalFiSignal
                                         : 0U));
        vlSelf->Mesh__DOT__mesh_0_1_io_in_control_0_propagate_b 
            = ((IData)(vlSelf->io_in_control_1_0_propagate) 
               ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                   & (0x39U == vlSelf->GlobalFiNumber)) 
                  & vlSelf->GlobalFiSignal));
    }
    if (vlSelf->io_in_valid_2_0) {
        vlSelf->Mesh__DOT__mesh_0_2_io_in_control_0_shift_b 
            = (0x1fU & ((IData)(vlSelf->io_in_control_2_0_shift) 
                        ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                            & (0x4bU == vlSelf->GlobalFiNumber))
                            ? vlSelf->GlobalFiSignal
                            : 0U)));
        vlSelf->Mesh__DOT__b_8_0 = (vlSelf->io_in_b_2_0 
                                    ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                        & (0x49U == vlSelf->GlobalFiNumber))
                                        ? vlSelf->GlobalFiSignal
                                        : 0U));
        vlSelf->Mesh__DOT__b_24_0 = (vlSelf->io_in_d_2_0 
                                     ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                         & (0x4aU == vlSelf->GlobalFiNumber))
                                         ? vlSelf->GlobalFiSignal
                                         : 0U));
        vlSelf->Mesh__DOT__mesh_0_2_io_in_control_0_propagate_b 
            = ((IData)(vlSelf->io_in_control_2_0_propagate) 
               ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                   & (0x4dU == vlSelf->GlobalFiNumber)) 
                  & vlSelf->GlobalFiSignal));
    }
    if (vlSelf->io_in_valid_0_0) {
        vlSelf->Mesh__DOT__mesh_0_0_io_in_control_0_shift_b 
            = (0x1fU & ((IData)(vlSelf->io_in_control_0_0_shift) 
                        ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                            & (0x23U == vlSelf->GlobalFiNumber))
                            ? vlSelf->GlobalFiSignal
                            : 0U)));
        vlSelf->Mesh__DOT__mesh_0_0_io_in_control_0_dataflow_b 
            = ((IData)(vlSelf->io_in_control_0_0_dataflow) 
               ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                   & (0x24U == vlSelf->GlobalFiNumber)) 
                  & vlSelf->GlobalFiSignal));
        vlSelf->Mesh__DOT__b_0 = (vlSelf->io_in_b_0_0 
                                  ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                      & (0x21U == vlSelf->GlobalFiNumber))
                                      ? vlSelf->GlobalFiSignal
                                      : 0U));
        vlSelf->Mesh__DOT__b_16_0 = (vlSelf->io_in_d_0_0 
                                     ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                         & (0x22U == vlSelf->GlobalFiNumber))
                                         ? vlSelf->GlobalFiSignal
                                         : 0U));
        vlSelf->Mesh__DOT__mesh_0_0_io_in_control_0_propagate_b 
            = ((IData)(vlSelf->io_in_control_0_0_propagate) 
               ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                   & (0x25U == vlSelf->GlobalFiNumber)) 
                  & vlSelf->GlobalFiSignal));
    }
    vlSelf->Mesh__DOT__r_49_0 = (((IData)(vlSelf->Mesh__DOT__r_48_0) 
                                  ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                                      & (0xfU == vlSelf->GlobalFiNumber)) 
                                     & vlSelf->GlobalFiSignal)) 
                                 ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                     & (0x92U == vlSelf->GlobalFiNumber)) 
                                    & vlSelf->GlobalFiSignal));
    vlSelf->Mesh__DOT__r_33_0 = (7U & (((IData)(vlSelf->Mesh__DOT__r_32_0) 
                                        ^ (((IData)(vlSelf->Mesh__DOT__mesh_0_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                                            & (0xeU 
                                               == vlSelf->GlobalFiNumber))
                                            ? vlSelf->GlobalFiSignal
                                            : 0U)) 
                                       ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                           & (0x82U 
                                              == vlSelf->GlobalFiNumber))
                                           ? vlSelf->GlobalFiSignal
                                           : 0U)));
    vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT__shift_offset 
        = (((IData)(vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT__last_s) 
            != (IData)(vlSelf->Mesh__DOT__mesh_3_3_io_in_control_0_propagate_b))
            ? (IData)(vlSelf->Mesh__DOT__mesh_3_3_io_in_control_0_shift_b)
            : 0U);
    vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT__shift_offset 
        = (((IData)(vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT__last_s) 
            != (IData)(vlSelf->Mesh__DOT__mesh_3_1_io_in_control_0_propagate_b))
            ? (IData)(vlSelf->Mesh__DOT__mesh_3_1_io_in_control_0_shift_b)
            : 0U);
    vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT__shift_offset 
        = (((IData)(vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT__last_s) 
            != (IData)(vlSelf->Mesh__DOT__mesh_3_2_io_in_control_0_propagate_b))
            ? (IData)(vlSelf->Mesh__DOT__mesh_3_2_io_in_control_0_shift_b)
            : 0U);
    vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT__shift_offset 
        = (((IData)(vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT__last_s) 
            != (IData)(vlSelf->Mesh__DOT__mesh_3_0_io_in_control_0_propagate_b))
            ? (IData)(vlSelf->Mesh__DOT__mesh_3_0_io_in_control_0_shift_b)
            : 0U);
    if ((0x1fU >= (IData)(vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT__shift_offset))) {
        vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT___io_out_c_T 
            = VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT__c1, (IData)(vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT__shift_offset));
        vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT___io_out_c_T_11 
            = VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT__c2, (IData)(vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT__shift_offset));
    } else {
        vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT___io_out_c_T 
            = (- (vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT__c1 
                  >> 0x1fU));
        vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT___io_out_c_T_11 
            = (- (vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT__c2 
                  >> 0x1fU));
    }
    if ((0x1fU >= (IData)(vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT__shift_offset))) {
        vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT___io_out_c_T 
            = VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT__c1, (IData)(vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT__shift_offset));
        vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT___io_out_c_T_11 
            = VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT__c2, (IData)(vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT__shift_offset));
    } else {
        vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT___io_out_c_T 
            = (- (vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT__c1 
                  >> 0x1fU));
        vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT___io_out_c_T_11 
            = (- (vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT__c2 
                  >> 0x1fU));
    }
    if ((0x1fU >= (IData)(vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT__shift_offset))) {
        vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT___io_out_c_T 
            = VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT__c1, (IData)(vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT__shift_offset));
        vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT___io_out_c_T_11 
            = VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT__c2, (IData)(vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT__shift_offset));
    } else {
        vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT___io_out_c_T 
            = (- (vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT__c1 
                  >> 0x1fU));
        vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT___io_out_c_T_11 
            = (- (vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT__c2 
                  >> 0x1fU));
    }
    if ((0x1fU >= (IData)(vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT__shift_offset))) {
        vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT___io_out_c_T 
            = VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT__c1, (IData)(vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT__shift_offset));
        vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT___io_out_c_T_11 
            = VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT__c2, (IData)(vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT__shift_offset));
    } else {
        vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT___io_out_c_T 
            = (- (vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT__c1 
                  >> 0x1fU));
        vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT___io_out_c_T_11 
            = (- (vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT__c2 
                  >> 0x1fU));
    }
    vlSelf->Mesh__DOT__r_48_0 = ((IData)(vlSelf->io_in_last_0_0) 
                                 ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                     & (0x91U == vlSelf->GlobalFiNumber)) 
                                    & vlSelf->GlobalFiSignal));
    vlSelf->Mesh__DOT__r_32_0 = (7U & ((IData)(vlSelf->io_in_id_0_0) 
                                       ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                           & (0x81U 
                                              == vlSelf->GlobalFiNumber))
                                           ? vlSelf->GlobalFiSignal
                                           : 0U)));
    vlSelf->Mesh__DOT__r_30_0 = ((IData)(vlSelf->Mesh__DOT___mesh_1_3_io_out_valid_0) 
                                 ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                     & (0x7fU == vlSelf->GlobalFiNumber)) 
                                    & vlSelf->GlobalFiSignal));
    vlSelf->Mesh__DOT__r_22_0 = ((IData)(vlSelf->Mesh__DOT___mesh_1_1_io_out_valid_0) 
                                 ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                     & (0x77U == vlSelf->GlobalFiNumber)) 
                                    & vlSelf->GlobalFiSignal));
    vlSelf->Mesh__DOT__r_26_0 = ((IData)(vlSelf->Mesh__DOT___mesh_1_2_io_out_valid_0) 
                                 ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                     & (0x7bU == vlSelf->GlobalFiNumber)) 
                                    & vlSelf->GlobalFiSignal));
    vlSelf->Mesh__DOT__r_18_0 = ((IData)(vlSelf->Mesh__DOT___mesh_1_0_io_out_valid_0) 
                                 ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                     & (0x73U == vlSelf->GlobalFiNumber)) 
                                    & vlSelf->GlobalFiSignal));
    vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT__shift_offset 
        = (((IData)(vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT__last_s) 
            != (IData)(vlSelf->Mesh__DOT__mesh_2_3_io_in_control_0_propagate_b))
            ? (IData)(vlSelf->Mesh__DOT__mesh_2_3_io_in_control_0_shift_b)
            : 0U);
    vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT__shift_offset 
        = (((IData)(vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT__last_s) 
            != (IData)(vlSelf->Mesh__DOT__mesh_2_1_io_in_control_0_propagate_b))
            ? (IData)(vlSelf->Mesh__DOT__mesh_2_1_io_in_control_0_shift_b)
            : 0U);
    vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT__shift_offset 
        = (((IData)(vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT__last_s) 
            != (IData)(vlSelf->Mesh__DOT__mesh_2_2_io_in_control_0_propagate_b))
            ? (IData)(vlSelf->Mesh__DOT__mesh_2_2_io_in_control_0_shift_b)
            : 0U);
    vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT__shift_offset 
        = (((IData)(vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT__last_s) 
            != (IData)(vlSelf->Mesh__DOT__mesh_2_0_io_in_control_0_propagate_b))
            ? (IData)(vlSelf->Mesh__DOT__mesh_2_0_io_in_control_0_shift_b)
            : 0U);
    if ((0x1fU >= (IData)(vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT__shift_offset))) {
        vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT___io_out_c_T 
            = VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT__c1, (IData)(vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT__shift_offset));
        vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT___io_out_c_T_11 
            = VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT__c2, (IData)(vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT__shift_offset));
    } else {
        vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT___io_out_c_T 
            = (- (vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT__c1 
                  >> 0x1fU));
        vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT___io_out_c_T_11 
            = (- (vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT__c2 
                  >> 0x1fU));
    }
    if ((0x1fU >= (IData)(vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT__shift_offset))) {
        vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT___io_out_c_T 
            = VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT__c1, (IData)(vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT__shift_offset));
        vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT___io_out_c_T_11 
            = VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT__c2, (IData)(vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT__shift_offset));
    } else {
        vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT___io_out_c_T 
            = (- (vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT__c1 
                  >> 0x1fU));
        vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT___io_out_c_T_11 
            = (- (vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT__c2 
                  >> 0x1fU));
    }
    if ((0x1fU >= (IData)(vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT__shift_offset))) {
        vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT___io_out_c_T 
            = VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT__c1, (IData)(vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT__shift_offset));
        vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT___io_out_c_T_11 
            = VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT__c2, (IData)(vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT__shift_offset));
    } else {
        vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT___io_out_c_T 
            = (- (vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT__c1 
                  >> 0x1fU));
        vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT___io_out_c_T_11 
            = (- (vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT__c2 
                  >> 0x1fU));
    }
    if ((0x1fU >= (IData)(vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT__shift_offset))) {
        vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT___io_out_c_T 
            = VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT__c1, (IData)(vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT__shift_offset));
        vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT___io_out_c_T_11 
            = VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT__c2, (IData)(vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT__shift_offset));
    } else {
        vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT___io_out_c_T 
            = (- (vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT__c1 
                  >> 0x1fU));
        vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT___io_out_c_T_11 
            = (- (vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT__c2 
                  >> 0x1fU));
    }
    vlSelf->Mesh__DOT__r_29_0 = ((IData)(vlSelf->Mesh__DOT___mesh_0_3_io_out_valid_0) 
                                 ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                     & (0x7eU == vlSelf->GlobalFiNumber)) 
                                    & vlSelf->GlobalFiSignal));
    vlSelf->Mesh__DOT__r_21_0 = ((IData)(vlSelf->Mesh__DOT___mesh_0_1_io_out_valid_0) 
                                 ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                     & (0x76U == vlSelf->GlobalFiNumber)) 
                                    & vlSelf->GlobalFiSignal));
    vlSelf->Mesh__DOT__r_25_0 = ((IData)(vlSelf->Mesh__DOT___mesh_0_2_io_out_valid_0) 
                                 ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                     & (0x7aU == vlSelf->GlobalFiNumber)) 
                                    & vlSelf->GlobalFiSignal));
    vlSelf->Mesh__DOT__r_17_0 = ((IData)(vlSelf->Mesh__DOT___mesh_0_0_io_out_valid_0) 
                                 ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                     & (0x72U == vlSelf->GlobalFiNumber)) 
                                    & vlSelf->GlobalFiSignal));
    vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT__shift_offset 
        = (((IData)(vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT__last_s) 
            != (IData)(vlSelf->Mesh__DOT__mesh_1_3_io_in_control_0_propagate_b))
            ? (IData)(vlSelf->Mesh__DOT__mesh_1_3_io_in_control_0_shift_b)
            : 0U);
    vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT__shift_offset 
        = (((IData)(vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT__last_s) 
            != (IData)(vlSelf->Mesh__DOT__mesh_1_1_io_in_control_0_propagate_b))
            ? (IData)(vlSelf->Mesh__DOT__mesh_1_1_io_in_control_0_shift_b)
            : 0U);
    vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT__shift_offset 
        = (((IData)(vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT__last_s) 
            != (IData)(vlSelf->Mesh__DOT__mesh_1_2_io_in_control_0_propagate_b))
            ? (IData)(vlSelf->Mesh__DOT__mesh_1_2_io_in_control_0_shift_b)
            : 0U);
    vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT__shift_offset 
        = (((IData)(vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT__last_s) 
            != (IData)(vlSelf->Mesh__DOT__mesh_1_0_io_in_control_0_propagate_b))
            ? (IData)(vlSelf->Mesh__DOT__mesh_1_0_io_in_control_0_shift_b)
            : 0U);
    if ((0x1fU >= (IData)(vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT__shift_offset))) {
        vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT___io_out_c_T 
            = VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT__c1, (IData)(vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT__shift_offset));
        vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT___io_out_c_T_11 
            = VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT__c2, (IData)(vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT__shift_offset));
    } else {
        vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT___io_out_c_T 
            = (- (vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT__c1 
                  >> 0x1fU));
        vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT___io_out_c_T_11 
            = (- (vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT__c2 
                  >> 0x1fU));
    }
    if ((0x1fU >= (IData)(vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT__shift_offset))) {
        vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT___io_out_c_T 
            = VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT__c1, (IData)(vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT__shift_offset));
        vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT___io_out_c_T_11 
            = VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT__c2, (IData)(vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT__shift_offset));
    } else {
        vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT___io_out_c_T 
            = (- (vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT__c1 
                  >> 0x1fU));
        vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT___io_out_c_T_11 
            = (- (vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT__c2 
                  >> 0x1fU));
    }
    if ((0x1fU >= (IData)(vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT__shift_offset))) {
        vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT___io_out_c_T 
            = VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT__c1, (IData)(vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT__shift_offset));
        vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT___io_out_c_T_11 
            = VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT__c2, (IData)(vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT__shift_offset));
    } else {
        vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT___io_out_c_T 
            = (- (vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT__c1 
                  >> 0x1fU));
        vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT___io_out_c_T_11 
            = (- (vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT__c2 
                  >> 0x1fU));
    }
    if ((0x1fU >= (IData)(vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT__shift_offset))) {
        vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT___io_out_c_T 
            = VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT__c1, (IData)(vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT__shift_offset));
        vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT___io_out_c_T_11 
            = VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT__c2, (IData)(vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT__shift_offset));
    } else {
        vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT___io_out_c_T 
            = (- (vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT__c1 
                  >> 0x1fU));
        vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT___io_out_c_T_11 
            = (- (vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT__c2 
                  >> 0x1fU));
    }
    vlSelf->Mesh__DOT__r_28_0 = ((IData)(vlSelf->io_in_valid_3_0) 
                                 ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                     & (0x7dU == vlSelf->GlobalFiNumber)) 
                                    & vlSelf->GlobalFiSignal));
    vlSelf->Mesh__DOT__r_20_0 = ((IData)(vlSelf->io_in_valid_1_0) 
                                 ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                     & (0x75U == vlSelf->GlobalFiNumber)) 
                                    & vlSelf->GlobalFiSignal));
    vlSelf->Mesh__DOT__r_24_0 = ((IData)(vlSelf->io_in_valid_2_0) 
                                 ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                     & (0x79U == vlSelf->GlobalFiNumber)) 
                                    & vlSelf->GlobalFiSignal));
    vlSelf->Mesh__DOT__r_16_0 = ((IData)(vlSelf->io_in_valid_0_0) 
                                 ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                     & (0x71U == vlSelf->GlobalFiNumber)) 
                                    & vlSelf->GlobalFiSignal));
    vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT__shift_offset 
        = (((IData)(vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT__last_s) 
            != (IData)(vlSelf->Mesh__DOT__mesh_0_3_io_in_control_0_propagate_b))
            ? (IData)(vlSelf->Mesh__DOT__mesh_0_3_io_in_control_0_shift_b)
            : 0U);
    vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT__shift_offset 
        = (((IData)(vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT__last_s) 
            != (IData)(vlSelf->Mesh__DOT__mesh_0_1_io_in_control_0_propagate_b))
            ? (IData)(vlSelf->Mesh__DOT__mesh_0_1_io_in_control_0_shift_b)
            : 0U);
    vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT__shift_offset 
        = (((IData)(vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT__last_s) 
            != (IData)(vlSelf->Mesh__DOT__mesh_0_2_io_in_control_0_propagate_b))
            ? (IData)(vlSelf->Mesh__DOT__mesh_0_2_io_in_control_0_shift_b)
            : 0U);
    vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT__shift_offset 
        = (((IData)(vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT__last_s) 
            != (IData)(vlSelf->Mesh__DOT__mesh_0_0_io_in_control_0_propagate_b))
            ? (IData)(vlSelf->Mesh__DOT__mesh_0_0_io_in_control_0_shift_b)
            : 0U);
    if ((0x1fU >= (IData)(vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT__shift_offset))) {
        vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT___io_out_c_T 
            = VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT__c1, (IData)(vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT__shift_offset));
        vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT___io_out_c_T_11 
            = VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT__c2, (IData)(vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT__shift_offset));
    } else {
        vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT___io_out_c_T 
            = (- (vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT__c1 
                  >> 0x1fU));
        vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT___io_out_c_T_11 
            = (- (vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT__c2 
                  >> 0x1fU));
    }
    if ((0x1fU >= (IData)(vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT__shift_offset))) {
        vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT___io_out_c_T 
            = VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT__c1, (IData)(vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT__shift_offset));
        vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT___io_out_c_T_11 
            = VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT__c2, (IData)(vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT__shift_offset));
    } else {
        vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT___io_out_c_T 
            = (- (vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT__c1 
                  >> 0x1fU));
        vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT___io_out_c_T_11 
            = (- (vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT__c2 
                  >> 0x1fU));
    }
    if ((0x1fU >= (IData)(vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT__shift_offset))) {
        vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT___io_out_c_T 
            = VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT__c1, (IData)(vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT__shift_offset));
        vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT___io_out_c_T_11 
            = VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT__c2, (IData)(vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT__shift_offset));
    } else {
        vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT___io_out_c_T 
            = (- (vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT__c1 
                  >> 0x1fU));
        vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT___io_out_c_T_11 
            = (- (vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT__c2 
                  >> 0x1fU));
    }
    if ((0x1fU >= (IData)(vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT__shift_offset))) {
        vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT___io_out_c_T 
            = VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT__c1, (IData)(vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT__shift_offset));
        vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT___io_out_c_T_11 
            = VL_SHIFTRS_III(32,32,32, vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT__c2, (IData)(vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT__shift_offset));
    } else {
        vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT___io_out_c_T 
            = (- (vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT__c1 
                  >> 0x1fU));
        vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT___io_out_c_T_11 
            = (- (vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT__c2 
                  >> 0x1fU));
    }
}

VL_INLINE_OPT void VMesh___024root___combo__TOP__0(VMesh___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMesh__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMesh___024root___combo__TOP__0\n"); );
    // Body
    vlSelf->Mesh__DOT__fiEnable = ((((1U == vlSelf->GlobalFiModInstNr
                                      [0U]) | (1U == 
                                               vlSelf->GlobalFiModInstNr
                                               [1U])) 
                                    | (1U == vlSelf->GlobalFiModInstNr
                                       [2U])) | (1U 
                                                 == 
                                                 vlSelf->GlobalFiModInstNr
                                                 [3U]));
    vlSelf->io_out_b_0_0 = (vlSelf->Mesh__DOT__r_64_0 
                            ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                & (0xadU == vlSelf->GlobalFiNumber))
                                ? vlSelf->GlobalFiSignal
                                : 0U));
    vlSelf->io_out_b_1_0 = (vlSelf->Mesh__DOT__r_70_0 
                            ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                & (0xaeU == vlSelf->GlobalFiNumber))
                                ? vlSelf->GlobalFiSignal
                                : 0U));
    vlSelf->io_out_b_2_0 = (vlSelf->Mesh__DOT__r_76_0 
                            ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                & (0xafU == vlSelf->GlobalFiNumber))
                                ? vlSelf->GlobalFiSignal
                                : 0U));
    vlSelf->io_out_b_3_0 = (vlSelf->Mesh__DOT__r_82_0 
                            ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                & (0xb0U == vlSelf->GlobalFiNumber))
                                ? vlSelf->GlobalFiSignal
                                : 0U));
    vlSelf->io_out_c_0_0 = (vlSelf->Mesh__DOT__r_65_0 
                            ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                & (0xb1U == vlSelf->GlobalFiNumber))
                                ? vlSelf->GlobalFiSignal
                                : 0U));
    vlSelf->io_out_c_1_0 = (vlSelf->Mesh__DOT__r_71_0 
                            ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                & (0xb2U == vlSelf->GlobalFiNumber))
                                ? vlSelf->GlobalFiSignal
                                : 0U));
    vlSelf->io_out_c_2_0 = (vlSelf->Mesh__DOT__r_77_0 
                            ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                & (0xb3U == vlSelf->GlobalFiNumber))
                                ? vlSelf->GlobalFiSignal
                                : 0U));
    vlSelf->io_out_c_3_0 = (vlSelf->Mesh__DOT__r_83_0 
                            ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                & (0xb4U == vlSelf->GlobalFiNumber))
                                ? vlSelf->GlobalFiSignal
                                : 0U));
    vlSelf->io_out_valid_0_0 = ((IData)(vlSelf->Mesh__DOT__r_66_0) 
                                ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                    & (0xb5U == vlSelf->GlobalFiNumber)) 
                                   & vlSelf->GlobalFiSignal));
    vlSelf->io_out_control_0_0_dataflow = ((IData)(vlSelf->Mesh__DOT__r_67_0_dataflow) 
                                           ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                               & (0xb6U 
                                                  == vlSelf->GlobalFiNumber)) 
                                              & vlSelf->GlobalFiSignal));
    vlSelf->io_out_id_0_0 = (7U & ((IData)(vlSelf->Mesh__DOT__r_68_0) 
                                   ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                       & (0xb7U == vlSelf->GlobalFiNumber))
                                       ? vlSelf->GlobalFiSignal
                                       : 0U)));
    vlSelf->io_out_last_0_0 = ((IData)(vlSelf->Mesh__DOT__r_69_0) 
                               ^ (((IData)(vlSelf->Mesh__DOT__fiEnable) 
                                   & (0xb8U == vlSelf->GlobalFiNumber)) 
                                  & vlSelf->GlobalFiSignal));
    vlSelf->Mesh__DOT__mesh_3_0__DOT____Vcellinp__tile_0_0__fiEnable 
        = (((IData)(vlSelf->Mesh__DOT__fiEnable) & 
            ((((0xc7U == vlSelf->GlobalFiModInstNr[0U]) 
               | (0xc7U == vlSelf->GlobalFiModInstNr
                  [1U])) | (0xc7U == vlSelf->GlobalFiModInstNr
                            [2U])) | (0xc7U == vlSelf->GlobalFiModInstNr
                                      [3U]))) & (((
                                                   (0xbaU 
                                                    == 
                                                    vlSelf->GlobalFiModInstNr
                                                    [0U]) 
                                                   | (0xbaU 
                                                      == 
                                                      vlSelf->GlobalFiModInstNr
                                                      [1U])) 
                                                  | (0xbaU 
                                                     == 
                                                     vlSelf->GlobalFiModInstNr
                                                     [2U])) 
                                                 | (0xbaU 
                                                    == 
                                                    vlSelf->GlobalFiModInstNr
                                                    [3U])));
    vlSelf->Mesh__DOT__mesh_3_1__DOT____Vcellinp__tile_0_0__fiEnable 
        = (((IData)(vlSelf->Mesh__DOT__fiEnable) & 
            ((((0xc8U == vlSelf->GlobalFiModInstNr[0U]) 
               | (0xc8U == vlSelf->GlobalFiModInstNr
                  [1U])) | (0xc8U == vlSelf->GlobalFiModInstNr
                            [2U])) | (0xc8U == vlSelf->GlobalFiModInstNr
                                      [3U]))) & (((
                                                   (0xbaU 
                                                    == 
                                                    vlSelf->GlobalFiModInstNr
                                                    [0U]) 
                                                   | (0xbaU 
                                                      == 
                                                      vlSelf->GlobalFiModInstNr
                                                      [1U])) 
                                                  | (0xbaU 
                                                     == 
                                                     vlSelf->GlobalFiModInstNr
                                                     [2U])) 
                                                 | (0xbaU 
                                                    == 
                                                    vlSelf->GlobalFiModInstNr
                                                    [3U])));
    vlSelf->Mesh__DOT__mesh_3_2__DOT____Vcellinp__tile_0_0__fiEnable 
        = (((IData)(vlSelf->Mesh__DOT__fiEnable) & 
            ((((0xc9U == vlSelf->GlobalFiModInstNr[0U]) 
               | (0xc9U == vlSelf->GlobalFiModInstNr
                  [1U])) | (0xc9U == vlSelf->GlobalFiModInstNr
                            [2U])) | (0xc9U == vlSelf->GlobalFiModInstNr
                                      [3U]))) & (((
                                                   (0xbaU 
                                                    == 
                                                    vlSelf->GlobalFiModInstNr
                                                    [0U]) 
                                                   | (0xbaU 
                                                      == 
                                                      vlSelf->GlobalFiModInstNr
                                                      [1U])) 
                                                  | (0xbaU 
                                                     == 
                                                     vlSelf->GlobalFiModInstNr
                                                     [2U])) 
                                                 | (0xbaU 
                                                    == 
                                                    vlSelf->GlobalFiModInstNr
                                                    [3U])));
    vlSelf->Mesh__DOT__mesh_3_3__DOT____Vcellinp__tile_0_0__fiEnable 
        = (((IData)(vlSelf->Mesh__DOT__fiEnable) & 
            ((((0xcaU == vlSelf->GlobalFiModInstNr[0U]) 
               | (0xcaU == vlSelf->GlobalFiModInstNr
                  [1U])) | (0xcaU == vlSelf->GlobalFiModInstNr
                            [2U])) | (0xcaU == vlSelf->GlobalFiModInstNr
                                      [3U]))) & (((
                                                   (0xbaU 
                                                    == 
                                                    vlSelf->GlobalFiModInstNr
                                                    [0U]) 
                                                   | (0xbaU 
                                                      == 
                                                      vlSelf->GlobalFiModInstNr
                                                      [1U])) 
                                                  | (0xbaU 
                                                     == 
                                                     vlSelf->GlobalFiModInstNr
                                                     [2U])) 
                                                 | (0xbaU 
                                                    == 
                                                    vlSelf->GlobalFiModInstNr
                                                    [3U])));
    vlSelf->Mesh__DOT__mesh_0_0__DOT____Vcellinp__tile_0_0__fiEnable 
        = (((IData)(vlSelf->Mesh__DOT__fiEnable) & 
            ((((0xbbU == vlSelf->GlobalFiModInstNr[0U]) 
               | (0xbbU == vlSelf->GlobalFiModInstNr
                  [1U])) | (0xbbU == vlSelf->GlobalFiModInstNr
                            [2U])) | (0xbbU == vlSelf->GlobalFiModInstNr
                                      [3U]))) & (((
                                                   (0xbaU 
                                                    == 
                                                    vlSelf->GlobalFiModInstNr
                                                    [0U]) 
                                                   | (0xbaU 
                                                      == 
                                                      vlSelf->GlobalFiModInstNr
                                                      [1U])) 
                                                  | (0xbaU 
                                                     == 
                                                     vlSelf->GlobalFiModInstNr
                                                     [2U])) 
                                                 | (0xbaU 
                                                    == 
                                                    vlSelf->GlobalFiModInstNr
                                                    [3U])));
    vlSelf->Mesh__DOT__mesh_0_1__DOT____Vcellinp__tile_0_0__fiEnable 
        = (((IData)(vlSelf->Mesh__DOT__fiEnable) & 
            ((((0xbcU == vlSelf->GlobalFiModInstNr[0U]) 
               | (0xbcU == vlSelf->GlobalFiModInstNr
                  [1U])) | (0xbcU == vlSelf->GlobalFiModInstNr
                            [2U])) | (0xbcU == vlSelf->GlobalFiModInstNr
                                      [3U]))) & (((
                                                   (0xbaU 
                                                    == 
                                                    vlSelf->GlobalFiModInstNr
                                                    [0U]) 
                                                   | (0xbaU 
                                                      == 
                                                      vlSelf->GlobalFiModInstNr
                                                      [1U])) 
                                                  | (0xbaU 
                                                     == 
                                                     vlSelf->GlobalFiModInstNr
                                                     [2U])) 
                                                 | (0xbaU 
                                                    == 
                                                    vlSelf->GlobalFiModInstNr
                                                    [3U])));
    vlSelf->Mesh__DOT__mesh_0_2__DOT____Vcellinp__tile_0_0__fiEnable 
        = (((IData)(vlSelf->Mesh__DOT__fiEnable) & 
            ((((0xbdU == vlSelf->GlobalFiModInstNr[0U]) 
               | (0xbdU == vlSelf->GlobalFiModInstNr
                  [1U])) | (0xbdU == vlSelf->GlobalFiModInstNr
                            [2U])) | (0xbdU == vlSelf->GlobalFiModInstNr
                                      [3U]))) & (((
                                                   (0xbaU 
                                                    == 
                                                    vlSelf->GlobalFiModInstNr
                                                    [0U]) 
                                                   | (0xbaU 
                                                      == 
                                                      vlSelf->GlobalFiModInstNr
                                                      [1U])) 
                                                  | (0xbaU 
                                                     == 
                                                     vlSelf->GlobalFiModInstNr
                                                     [2U])) 
                                                 | (0xbaU 
                                                    == 
                                                    vlSelf->GlobalFiModInstNr
                                                    [3U])));
    vlSelf->Mesh__DOT__mesh_0_3__DOT____Vcellinp__tile_0_0__fiEnable 
        = (((IData)(vlSelf->Mesh__DOT__fiEnable) & 
            ((((0xbeU == vlSelf->GlobalFiModInstNr[0U]) 
               | (0xbeU == vlSelf->GlobalFiModInstNr
                  [1U])) | (0xbeU == vlSelf->GlobalFiModInstNr
                            [2U])) | (0xbeU == vlSelf->GlobalFiModInstNr
                                      [3U]))) & (((
                                                   (0xbaU 
                                                    == 
                                                    vlSelf->GlobalFiModInstNr
                                                    [0U]) 
                                                   | (0xbaU 
                                                      == 
                                                      vlSelf->GlobalFiModInstNr
                                                      [1U])) 
                                                  | (0xbaU 
                                                     == 
                                                     vlSelf->GlobalFiModInstNr
                                                     [2U])) 
                                                 | (0xbaU 
                                                    == 
                                                    vlSelf->GlobalFiModInstNr
                                                    [3U])));
    vlSelf->Mesh__DOT__mesh_1_0__DOT____Vcellinp__tile_0_0__fiEnable 
        = (((IData)(vlSelf->Mesh__DOT__fiEnable) & 
            ((((0xbfU == vlSelf->GlobalFiModInstNr[0U]) 
               | (0xbfU == vlSelf->GlobalFiModInstNr
                  [1U])) | (0xbfU == vlSelf->GlobalFiModInstNr
                            [2U])) | (0xbfU == vlSelf->GlobalFiModInstNr
                                      [3U]))) & (((
                                                   (0xbaU 
                                                    == 
                                                    vlSelf->GlobalFiModInstNr
                                                    [0U]) 
                                                   | (0xbaU 
                                                      == 
                                                      vlSelf->GlobalFiModInstNr
                                                      [1U])) 
                                                  | (0xbaU 
                                                     == 
                                                     vlSelf->GlobalFiModInstNr
                                                     [2U])) 
                                                 | (0xbaU 
                                                    == 
                                                    vlSelf->GlobalFiModInstNr
                                                    [3U])));
    vlSelf->Mesh__DOT__mesh_1_1__DOT____Vcellinp__tile_0_0__fiEnable 
        = (((IData)(vlSelf->Mesh__DOT__fiEnable) & 
            ((((0xc0U == vlSelf->GlobalFiModInstNr[0U]) 
               | (0xc0U == vlSelf->GlobalFiModInstNr
                  [1U])) | (0xc0U == vlSelf->GlobalFiModInstNr
                            [2U])) | (0xc0U == vlSelf->GlobalFiModInstNr
                                      [3U]))) & (((
                                                   (0xbaU 
                                                    == 
                                                    vlSelf->GlobalFiModInstNr
                                                    [0U]) 
                                                   | (0xbaU 
                                                      == 
                                                      vlSelf->GlobalFiModInstNr
                                                      [1U])) 
                                                  | (0xbaU 
                                                     == 
                                                     vlSelf->GlobalFiModInstNr
                                                     [2U])) 
                                                 | (0xbaU 
                                                    == 
                                                    vlSelf->GlobalFiModInstNr
                                                    [3U])));
    vlSelf->Mesh__DOT__mesh_1_2__DOT____Vcellinp__tile_0_0__fiEnable 
        = (((IData)(vlSelf->Mesh__DOT__fiEnable) & 
            ((((0xc1U == vlSelf->GlobalFiModInstNr[0U]) 
               | (0xc1U == vlSelf->GlobalFiModInstNr
                  [1U])) | (0xc1U == vlSelf->GlobalFiModInstNr
                            [2U])) | (0xc1U == vlSelf->GlobalFiModInstNr
                                      [3U]))) & (((
                                                   (0xbaU 
                                                    == 
                                                    vlSelf->GlobalFiModInstNr
                                                    [0U]) 
                                                   | (0xbaU 
                                                      == 
                                                      vlSelf->GlobalFiModInstNr
                                                      [1U])) 
                                                  | (0xbaU 
                                                     == 
                                                     vlSelf->GlobalFiModInstNr
                                                     [2U])) 
                                                 | (0xbaU 
                                                    == 
                                                    vlSelf->GlobalFiModInstNr
                                                    [3U])));
    vlSelf->Mesh__DOT__mesh_1_3__DOT____Vcellinp__tile_0_0__fiEnable 
        = (((IData)(vlSelf->Mesh__DOT__fiEnable) & 
            ((((0xc2U == vlSelf->GlobalFiModInstNr[0U]) 
               | (0xc2U == vlSelf->GlobalFiModInstNr
                  [1U])) | (0xc2U == vlSelf->GlobalFiModInstNr
                            [2U])) | (0xc2U == vlSelf->GlobalFiModInstNr
                                      [3U]))) & (((
                                                   (0xbaU 
                                                    == 
                                                    vlSelf->GlobalFiModInstNr
                                                    [0U]) 
                                                   | (0xbaU 
                                                      == 
                                                      vlSelf->GlobalFiModInstNr
                                                      [1U])) 
                                                  | (0xbaU 
                                                     == 
                                                     vlSelf->GlobalFiModInstNr
                                                     [2U])) 
                                                 | (0xbaU 
                                                    == 
                                                    vlSelf->GlobalFiModInstNr
                                                    [3U])));
    vlSelf->Mesh__DOT__mesh_2_0__DOT____Vcellinp__tile_0_0__fiEnable 
        = (((IData)(vlSelf->Mesh__DOT__fiEnable) & 
            ((((0xc3U == vlSelf->GlobalFiModInstNr[0U]) 
               | (0xc3U == vlSelf->GlobalFiModInstNr
                  [1U])) | (0xc3U == vlSelf->GlobalFiModInstNr
                            [2U])) | (0xc3U == vlSelf->GlobalFiModInstNr
                                      [3U]))) & (((
                                                   (0xbaU 
                                                    == 
                                                    vlSelf->GlobalFiModInstNr
                                                    [0U]) 
                                                   | (0xbaU 
                                                      == 
                                                      vlSelf->GlobalFiModInstNr
                                                      [1U])) 
                                                  | (0xbaU 
                                                     == 
                                                     vlSelf->GlobalFiModInstNr
                                                     [2U])) 
                                                 | (0xbaU 
                                                    == 
                                                    vlSelf->GlobalFiModInstNr
                                                    [3U])));
    vlSelf->Mesh__DOT__mesh_2_1__DOT____Vcellinp__tile_0_0__fiEnable 
        = (((IData)(vlSelf->Mesh__DOT__fiEnable) & 
            ((((0xc4U == vlSelf->GlobalFiModInstNr[0U]) 
               | (0xc4U == vlSelf->GlobalFiModInstNr
                  [1U])) | (0xc4U == vlSelf->GlobalFiModInstNr
                            [2U])) | (0xc4U == vlSelf->GlobalFiModInstNr
                                      [3U]))) & (((
                                                   (0xbaU 
                                                    == 
                                                    vlSelf->GlobalFiModInstNr
                                                    [0U]) 
                                                   | (0xbaU 
                                                      == 
                                                      vlSelf->GlobalFiModInstNr
                                                      [1U])) 
                                                  | (0xbaU 
                                                     == 
                                                     vlSelf->GlobalFiModInstNr
                                                     [2U])) 
                                                 | (0xbaU 
                                                    == 
                                                    vlSelf->GlobalFiModInstNr
                                                    [3U])));
    vlSelf->Mesh__DOT__mesh_2_2__DOT____Vcellinp__tile_0_0__fiEnable 
        = (((IData)(vlSelf->Mesh__DOT__fiEnable) & 
            ((((0xc5U == vlSelf->GlobalFiModInstNr[0U]) 
               | (0xc5U == vlSelf->GlobalFiModInstNr
                  [1U])) | (0xc5U == vlSelf->GlobalFiModInstNr
                            [2U])) | (0xc5U == vlSelf->GlobalFiModInstNr
                                      [3U]))) & (((
                                                   (0xbaU 
                                                    == 
                                                    vlSelf->GlobalFiModInstNr
                                                    [0U]) 
                                                   | (0xbaU 
                                                      == 
                                                      vlSelf->GlobalFiModInstNr
                                                      [1U])) 
                                                  | (0xbaU 
                                                     == 
                                                     vlSelf->GlobalFiModInstNr
                                                     [2U])) 
                                                 | (0xbaU 
                                                    == 
                                                    vlSelf->GlobalFiModInstNr
                                                    [3U])));
    vlSelf->Mesh__DOT__mesh_2_3__DOT____Vcellinp__tile_0_0__fiEnable 
        = (((IData)(vlSelf->Mesh__DOT__fiEnable) & 
            ((((0xc6U == vlSelf->GlobalFiModInstNr[0U]) 
               | (0xc6U == vlSelf->GlobalFiModInstNr
                  [1U])) | (0xc6U == vlSelf->GlobalFiModInstNr
                            [2U])) | (0xc6U == vlSelf->GlobalFiModInstNr
                                      [3U]))) & (((
                                                   (0xbaU 
                                                    == 
                                                    vlSelf->GlobalFiModInstNr
                                                    [0U]) 
                                                   | (0xbaU 
                                                      == 
                                                      vlSelf->GlobalFiModInstNr
                                                      [1U])) 
                                                  | (0xbaU 
                                                     == 
                                                     vlSelf->GlobalFiModInstNr
                                                     [2U])) 
                                                 | (0xbaU 
                                                    == 
                                                    vlSelf->GlobalFiModInstNr
                                                    [3U])));
    vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT___mac_unit_io_out_d 
        = (((vlSelf->Mesh__DOT__r_12_0 * vlSelf->Mesh__DOT__b_3_0) 
            + ((IData)(vlSelf->Mesh__DOT__mesh_3_0_io_in_control_0_propagate_b)
                ? vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT__c2
                : vlSelf->Mesh__DOT__mesh_3_0__DOT__tile_0_0__DOT__c1)) 
           ^ ((((IData)(vlSelf->Mesh__DOT__mesh_3_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                & ((((0xb9U == vlSelf->GlobalFiModInstNr
                      [0U]) | (0xb9U == vlSelf->GlobalFiModInstNr
                               [1U])) | (0xb9U == vlSelf->GlobalFiModInstNr
                                         [2U])) | (0xb9U 
                                                   == 
                                                   vlSelf->GlobalFiModInstNr
                                                   [3U]))) 
               & (2U == vlSelf->GlobalFiNumber)) ? vlSelf->GlobalFiSignal
               : 0U));
    vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT___mac_unit_io_out_d 
        = (((vlSelf->Mesh__DOT__r_13_0 * vlSelf->Mesh__DOT__b_7_0) 
            + ((IData)(vlSelf->Mesh__DOT__mesh_3_1_io_in_control_0_propagate_b)
                ? vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT__c2
                : vlSelf->Mesh__DOT__mesh_3_1__DOT__tile_0_0__DOT__c1)) 
           ^ ((((IData)(vlSelf->Mesh__DOT__mesh_3_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                & ((((0xb9U == vlSelf->GlobalFiModInstNr
                      [0U]) | (0xb9U == vlSelf->GlobalFiModInstNr
                               [1U])) | (0xb9U == vlSelf->GlobalFiModInstNr
                                         [2U])) | (0xb9U 
                                                   == 
                                                   vlSelf->GlobalFiModInstNr
                                                   [3U]))) 
               & (2U == vlSelf->GlobalFiNumber)) ? vlSelf->GlobalFiSignal
               : 0U));
    vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT___mac_unit_io_out_d 
        = (((vlSelf->Mesh__DOT__r_14_0 * vlSelf->Mesh__DOT__b_11_0) 
            + ((IData)(vlSelf->Mesh__DOT__mesh_3_2_io_in_control_0_propagate_b)
                ? vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT__c2
                : vlSelf->Mesh__DOT__mesh_3_2__DOT__tile_0_0__DOT__c1)) 
           ^ ((((IData)(vlSelf->Mesh__DOT__mesh_3_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                & ((((0xb9U == vlSelf->GlobalFiModInstNr
                      [0U]) | (0xb9U == vlSelf->GlobalFiModInstNr
                               [1U])) | (0xb9U == vlSelf->GlobalFiModInstNr
                                         [2U])) | (0xb9U 
                                                   == 
                                                   vlSelf->GlobalFiModInstNr
                                                   [3U]))) 
               & (2U == vlSelf->GlobalFiNumber)) ? vlSelf->GlobalFiSignal
               : 0U));
    vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT___mac_unit_io_out_d 
        = (((vlSelf->Mesh__DOT__r_15_0 * vlSelf->Mesh__DOT__b_15_0) 
            + ((IData)(vlSelf->Mesh__DOT__mesh_3_3_io_in_control_0_propagate_b)
                ? vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT__c2
                : vlSelf->Mesh__DOT__mesh_3_3__DOT__tile_0_0__DOT__c1)) 
           ^ ((((IData)(vlSelf->Mesh__DOT__mesh_3_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                & ((((0xb9U == vlSelf->GlobalFiModInstNr
                      [0U]) | (0xb9U == vlSelf->GlobalFiModInstNr
                               [1U])) | (0xb9U == vlSelf->GlobalFiModInstNr
                                         [2U])) | (0xb9U 
                                                   == 
                                                   vlSelf->GlobalFiModInstNr
                                                   [3U]))) 
               & (2U == vlSelf->GlobalFiNumber)) ? vlSelf->GlobalFiSignal
               : 0U));
    vlSelf->Mesh__DOT___mesh_0_0_io_out_valid_0 = ((IData)(vlSelf->Mesh__DOT__r_16_0) 
                                                   ^ 
                                                   (((IData)(vlSelf->Mesh__DOT__mesh_0_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                     & (0x10U 
                                                        == vlSelf->GlobalFiNumber)) 
                                                    & vlSelf->GlobalFiSignal));
    vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT___mac_unit_io_out_d 
        = (((vlSelf->Mesh__DOT__r_0 * vlSelf->Mesh__DOT__b_0) 
            + ((IData)(vlSelf->Mesh__DOT__mesh_0_0_io_in_control_0_propagate_b)
                ? vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT__c2
                : vlSelf->Mesh__DOT__mesh_0_0__DOT__tile_0_0__DOT__c1)) 
           ^ ((((IData)(vlSelf->Mesh__DOT__mesh_0_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                & ((((0xb9U == vlSelf->GlobalFiModInstNr
                      [0U]) | (0xb9U == vlSelf->GlobalFiModInstNr
                               [1U])) | (0xb9U == vlSelf->GlobalFiModInstNr
                                         [2U])) | (0xb9U 
                                                   == 
                                                   vlSelf->GlobalFiModInstNr
                                                   [3U]))) 
               & (2U == vlSelf->GlobalFiNumber)) ? vlSelf->GlobalFiSignal
               : 0U));
    vlSelf->Mesh__DOT___mesh_0_1_io_out_valid_0 = ((IData)(vlSelf->Mesh__DOT__r_20_0) 
                                                   ^ 
                                                   (((IData)(vlSelf->Mesh__DOT__mesh_0_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                     & (0x10U 
                                                        == vlSelf->GlobalFiNumber)) 
                                                    & vlSelf->GlobalFiSignal));
    vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT___mac_unit_io_out_d 
        = (((vlSelf->Mesh__DOT__r_1_0 * vlSelf->Mesh__DOT__b_4_0) 
            + ((IData)(vlSelf->Mesh__DOT__mesh_0_1_io_in_control_0_propagate_b)
                ? vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT__c2
                : vlSelf->Mesh__DOT__mesh_0_1__DOT__tile_0_0__DOT__c1)) 
           ^ ((((IData)(vlSelf->Mesh__DOT__mesh_0_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                & ((((0xb9U == vlSelf->GlobalFiModInstNr
                      [0U]) | (0xb9U == vlSelf->GlobalFiModInstNr
                               [1U])) | (0xb9U == vlSelf->GlobalFiModInstNr
                                         [2U])) | (0xb9U 
                                                   == 
                                                   vlSelf->GlobalFiModInstNr
                                                   [3U]))) 
               & (2U == vlSelf->GlobalFiNumber)) ? vlSelf->GlobalFiSignal
               : 0U));
    vlSelf->Mesh__DOT___mesh_0_2_io_out_valid_0 = ((IData)(vlSelf->Mesh__DOT__r_24_0) 
                                                   ^ 
                                                   (((IData)(vlSelf->Mesh__DOT__mesh_0_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                     & (0x10U 
                                                        == vlSelf->GlobalFiNumber)) 
                                                    & vlSelf->GlobalFiSignal));
    vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT___mac_unit_io_out_d 
        = (((vlSelf->Mesh__DOT__r_2_0 * vlSelf->Mesh__DOT__b_8_0) 
            + ((IData)(vlSelf->Mesh__DOT__mesh_0_2_io_in_control_0_propagate_b)
                ? vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT__c2
                : vlSelf->Mesh__DOT__mesh_0_2__DOT__tile_0_0__DOT__c1)) 
           ^ ((((IData)(vlSelf->Mesh__DOT__mesh_0_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                & ((((0xb9U == vlSelf->GlobalFiModInstNr
                      [0U]) | (0xb9U == vlSelf->GlobalFiModInstNr
                               [1U])) | (0xb9U == vlSelf->GlobalFiModInstNr
                                         [2U])) | (0xb9U 
                                                   == 
                                                   vlSelf->GlobalFiModInstNr
                                                   [3U]))) 
               & (2U == vlSelf->GlobalFiNumber)) ? vlSelf->GlobalFiSignal
               : 0U));
    vlSelf->Mesh__DOT___mesh_0_3_io_out_valid_0 = ((IData)(vlSelf->Mesh__DOT__r_28_0) 
                                                   ^ 
                                                   (((IData)(vlSelf->Mesh__DOT__mesh_0_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                     & (0x10U 
                                                        == vlSelf->GlobalFiNumber)) 
                                                    & vlSelf->GlobalFiSignal));
    vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT___mac_unit_io_out_d 
        = (((vlSelf->Mesh__DOT__r_3_0 * vlSelf->Mesh__DOT__b_12_0) 
            + ((IData)(vlSelf->Mesh__DOT__mesh_0_3_io_in_control_0_propagate_b)
                ? vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT__c2
                : vlSelf->Mesh__DOT__mesh_0_3__DOT__tile_0_0__DOT__c1)) 
           ^ ((((IData)(vlSelf->Mesh__DOT__mesh_0_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                & ((((0xb9U == vlSelf->GlobalFiModInstNr
                      [0U]) | (0xb9U == vlSelf->GlobalFiModInstNr
                               [1U])) | (0xb9U == vlSelf->GlobalFiModInstNr
                                         [2U])) | (0xb9U 
                                                   == 
                                                   vlSelf->GlobalFiModInstNr
                                                   [3U]))) 
               & (2U == vlSelf->GlobalFiNumber)) ? vlSelf->GlobalFiSignal
               : 0U));
    vlSelf->Mesh__DOT___mesh_1_0_io_out_valid_0 = ((IData)(vlSelf->Mesh__DOT__r_17_0) 
                                                   ^ 
                                                   (((IData)(vlSelf->Mesh__DOT__mesh_1_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                     & (0x10U 
                                                        == vlSelf->GlobalFiNumber)) 
                                                    & vlSelf->GlobalFiSignal));
    vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT___mac_unit_io_out_d 
        = (((vlSelf->Mesh__DOT__r_4_0 * vlSelf->Mesh__DOT__b_1_0) 
            + ((IData)(vlSelf->Mesh__DOT__mesh_1_0_io_in_control_0_propagate_b)
                ? vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT__c2
                : vlSelf->Mesh__DOT__mesh_1_0__DOT__tile_0_0__DOT__c1)) 
           ^ ((((IData)(vlSelf->Mesh__DOT__mesh_1_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                & ((((0xb9U == vlSelf->GlobalFiModInstNr
                      [0U]) | (0xb9U == vlSelf->GlobalFiModInstNr
                               [1U])) | (0xb9U == vlSelf->GlobalFiModInstNr
                                         [2U])) | (0xb9U 
                                                   == 
                                                   vlSelf->GlobalFiModInstNr
                                                   [3U]))) 
               & (2U == vlSelf->GlobalFiNumber)) ? vlSelf->GlobalFiSignal
               : 0U));
    vlSelf->Mesh__DOT___mesh_1_1_io_out_valid_0 = ((IData)(vlSelf->Mesh__DOT__r_21_0) 
                                                   ^ 
                                                   (((IData)(vlSelf->Mesh__DOT__mesh_1_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                     & (0x10U 
                                                        == vlSelf->GlobalFiNumber)) 
                                                    & vlSelf->GlobalFiSignal));
    vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT___mac_unit_io_out_d 
        = (((vlSelf->Mesh__DOT__r_5_0 * vlSelf->Mesh__DOT__b_5_0) 
            + ((IData)(vlSelf->Mesh__DOT__mesh_1_1_io_in_control_0_propagate_b)
                ? vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT__c2
                : vlSelf->Mesh__DOT__mesh_1_1__DOT__tile_0_0__DOT__c1)) 
           ^ ((((IData)(vlSelf->Mesh__DOT__mesh_1_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                & ((((0xb9U == vlSelf->GlobalFiModInstNr
                      [0U]) | (0xb9U == vlSelf->GlobalFiModInstNr
                               [1U])) | (0xb9U == vlSelf->GlobalFiModInstNr
                                         [2U])) | (0xb9U 
                                                   == 
                                                   vlSelf->GlobalFiModInstNr
                                                   [3U]))) 
               & (2U == vlSelf->GlobalFiNumber)) ? vlSelf->GlobalFiSignal
               : 0U));
    vlSelf->Mesh__DOT___mesh_1_2_io_out_valid_0 = ((IData)(vlSelf->Mesh__DOT__r_25_0) 
                                                   ^ 
                                                   (((IData)(vlSelf->Mesh__DOT__mesh_1_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                     & (0x10U 
                                                        == vlSelf->GlobalFiNumber)) 
                                                    & vlSelf->GlobalFiSignal));
    vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT___mac_unit_io_out_d 
        = (((vlSelf->Mesh__DOT__r_6_0 * vlSelf->Mesh__DOT__b_9_0) 
            + ((IData)(vlSelf->Mesh__DOT__mesh_1_2_io_in_control_0_propagate_b)
                ? vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT__c2
                : vlSelf->Mesh__DOT__mesh_1_2__DOT__tile_0_0__DOT__c1)) 
           ^ ((((IData)(vlSelf->Mesh__DOT__mesh_1_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                & ((((0xb9U == vlSelf->GlobalFiModInstNr
                      [0U]) | (0xb9U == vlSelf->GlobalFiModInstNr
                               [1U])) | (0xb9U == vlSelf->GlobalFiModInstNr
                                         [2U])) | (0xb9U 
                                                   == 
                                                   vlSelf->GlobalFiModInstNr
                                                   [3U]))) 
               & (2U == vlSelf->GlobalFiNumber)) ? vlSelf->GlobalFiSignal
               : 0U));
    vlSelf->Mesh__DOT___mesh_1_3_io_out_valid_0 = ((IData)(vlSelf->Mesh__DOT__r_29_0) 
                                                   ^ 
                                                   (((IData)(vlSelf->Mesh__DOT__mesh_1_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                     & (0x10U 
                                                        == vlSelf->GlobalFiNumber)) 
                                                    & vlSelf->GlobalFiSignal));
    vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT___mac_unit_io_out_d 
        = (((vlSelf->Mesh__DOT__r_7_0 * vlSelf->Mesh__DOT__b_13_0) 
            + ((IData)(vlSelf->Mesh__DOT__mesh_1_3_io_in_control_0_propagate_b)
                ? vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT__c2
                : vlSelf->Mesh__DOT__mesh_1_3__DOT__tile_0_0__DOT__c1)) 
           ^ ((((IData)(vlSelf->Mesh__DOT__mesh_1_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                & ((((0xb9U == vlSelf->GlobalFiModInstNr
                      [0U]) | (0xb9U == vlSelf->GlobalFiModInstNr
                               [1U])) | (0xb9U == vlSelf->GlobalFiModInstNr
                                         [2U])) | (0xb9U 
                                                   == 
                                                   vlSelf->GlobalFiModInstNr
                                                   [3U]))) 
               & (2U == vlSelf->GlobalFiNumber)) ? vlSelf->GlobalFiSignal
               : 0U));
    vlSelf->Mesh__DOT___mesh_2_0_io_out_valid_0 = ((IData)(vlSelf->Mesh__DOT__r_18_0) 
                                                   ^ 
                                                   (((IData)(vlSelf->Mesh__DOT__mesh_2_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                     & (0x10U 
                                                        == vlSelf->GlobalFiNumber)) 
                                                    & vlSelf->GlobalFiSignal));
    vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT___mac_unit_io_out_d 
        = (((vlSelf->Mesh__DOT__r_8_0 * vlSelf->Mesh__DOT__b_2_0) 
            + ((IData)(vlSelf->Mesh__DOT__mesh_2_0_io_in_control_0_propagate_b)
                ? vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT__c2
                : vlSelf->Mesh__DOT__mesh_2_0__DOT__tile_0_0__DOT__c1)) 
           ^ ((((IData)(vlSelf->Mesh__DOT__mesh_2_0__DOT____Vcellinp__tile_0_0__fiEnable) 
                & ((((0xb9U == vlSelf->GlobalFiModInstNr
                      [0U]) | (0xb9U == vlSelf->GlobalFiModInstNr
                               [1U])) | (0xb9U == vlSelf->GlobalFiModInstNr
                                         [2U])) | (0xb9U 
                                                   == 
                                                   vlSelf->GlobalFiModInstNr
                                                   [3U]))) 
               & (2U == vlSelf->GlobalFiNumber)) ? vlSelf->GlobalFiSignal
               : 0U));
    vlSelf->Mesh__DOT___mesh_2_1_io_out_valid_0 = ((IData)(vlSelf->Mesh__DOT__r_22_0) 
                                                   ^ 
                                                   (((IData)(vlSelf->Mesh__DOT__mesh_2_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                     & (0x10U 
                                                        == vlSelf->GlobalFiNumber)) 
                                                    & vlSelf->GlobalFiSignal));
    vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT___mac_unit_io_out_d 
        = (((vlSelf->Mesh__DOT__r_9_0 * vlSelf->Mesh__DOT__b_6_0) 
            + ((IData)(vlSelf->Mesh__DOT__mesh_2_1_io_in_control_0_propagate_b)
                ? vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT__c2
                : vlSelf->Mesh__DOT__mesh_2_1__DOT__tile_0_0__DOT__c1)) 
           ^ ((((IData)(vlSelf->Mesh__DOT__mesh_2_1__DOT____Vcellinp__tile_0_0__fiEnable) 
                & ((((0xb9U == vlSelf->GlobalFiModInstNr
                      [0U]) | (0xb9U == vlSelf->GlobalFiModInstNr
                               [1U])) | (0xb9U == vlSelf->GlobalFiModInstNr
                                         [2U])) | (0xb9U 
                                                   == 
                                                   vlSelf->GlobalFiModInstNr
                                                   [3U]))) 
               & (2U == vlSelf->GlobalFiNumber)) ? vlSelf->GlobalFiSignal
               : 0U));
    vlSelf->Mesh__DOT___mesh_2_2_io_out_valid_0 = ((IData)(vlSelf->Mesh__DOT__r_26_0) 
                                                   ^ 
                                                   (((IData)(vlSelf->Mesh__DOT__mesh_2_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                     & (0x10U 
                                                        == vlSelf->GlobalFiNumber)) 
                                                    & vlSelf->GlobalFiSignal));
    vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT___mac_unit_io_out_d 
        = (((vlSelf->Mesh__DOT__r_10_0 * vlSelf->Mesh__DOT__b_10_0) 
            + ((IData)(vlSelf->Mesh__DOT__mesh_2_2_io_in_control_0_propagate_b)
                ? vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT__c2
                : vlSelf->Mesh__DOT__mesh_2_2__DOT__tile_0_0__DOT__c1)) 
           ^ ((((IData)(vlSelf->Mesh__DOT__mesh_2_2__DOT____Vcellinp__tile_0_0__fiEnable) 
                & ((((0xb9U == vlSelf->GlobalFiModInstNr
                      [0U]) | (0xb9U == vlSelf->GlobalFiModInstNr
                               [1U])) | (0xb9U == vlSelf->GlobalFiModInstNr
                                         [2U])) | (0xb9U 
                                                   == 
                                                   vlSelf->GlobalFiModInstNr
                                                   [3U]))) 
               & (2U == vlSelf->GlobalFiNumber)) ? vlSelf->GlobalFiSignal
               : 0U));
    vlSelf->Mesh__DOT___mesh_2_3_io_out_valid_0 = ((IData)(vlSelf->Mesh__DOT__r_30_0) 
                                                   ^ 
                                                   (((IData)(vlSelf->Mesh__DOT__mesh_2_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                                                     & (0x10U 
                                                        == vlSelf->GlobalFiNumber)) 
                                                    & vlSelf->GlobalFiSignal));
    vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT___mac_unit_io_out_d 
        = (((vlSelf->Mesh__DOT__r_11_0 * vlSelf->Mesh__DOT__b_14_0) 
            + ((IData)(vlSelf->Mesh__DOT__mesh_2_3_io_in_control_0_propagate_b)
                ? vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT__c2
                : vlSelf->Mesh__DOT__mesh_2_3__DOT__tile_0_0__DOT__c1)) 
           ^ ((((IData)(vlSelf->Mesh__DOT__mesh_2_3__DOT____Vcellinp__tile_0_0__fiEnable) 
                & ((((0xb9U == vlSelf->GlobalFiModInstNr
                      [0U]) | (0xb9U == vlSelf->GlobalFiModInstNr
                               [1U])) | (0xb9U == vlSelf->GlobalFiModInstNr
                                         [2U])) | (0xb9U 
                                                   == 
                                                   vlSelf->GlobalFiModInstNr
                                                   [3U]))) 
               & (2U == vlSelf->GlobalFiNumber)) ? vlSelf->GlobalFiSignal
               : 0U));
}

void VMesh___024root___eval(VMesh___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMesh__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMesh___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clock) & (~ (IData)(vlSelf->__Vclklast__TOP__clock)))) {
        VMesh___024root___sequent__TOP__0(vlSelf);
    }
    VMesh___024root___combo__TOP__0(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__clock = vlSelf->clock;
}

#ifdef VL_DEBUG
void VMesh___024root___eval_debug_assertions(VMesh___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VMesh__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMesh___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((vlSelf->io_in_control_0_0_dataflow 
                     & 0xfeU))) {
        Verilated::overWidthError("io_in_control_0_0_dataflow");}
    if (VL_UNLIKELY((vlSelf->io_in_control_0_0_propagate 
                     & 0xfeU))) {
        Verilated::overWidthError("io_in_control_0_0_propagate");}
    if (VL_UNLIKELY((vlSelf->io_in_control_0_0_shift 
                     & 0xe0U))) {
        Verilated::overWidthError("io_in_control_0_0_shift");}
    if (VL_UNLIKELY((vlSelf->io_in_control_1_0_dataflow 
                     & 0xfeU))) {
        Verilated::overWidthError("io_in_control_1_0_dataflow");}
    if (VL_UNLIKELY((vlSelf->io_in_control_1_0_propagate 
                     & 0xfeU))) {
        Verilated::overWidthError("io_in_control_1_0_propagate");}
    if (VL_UNLIKELY((vlSelf->io_in_control_1_0_shift 
                     & 0xe0U))) {
        Verilated::overWidthError("io_in_control_1_0_shift");}
    if (VL_UNLIKELY((vlSelf->io_in_control_2_0_dataflow 
                     & 0xfeU))) {
        Verilated::overWidthError("io_in_control_2_0_dataflow");}
    if (VL_UNLIKELY((vlSelf->io_in_control_2_0_propagate 
                     & 0xfeU))) {
        Verilated::overWidthError("io_in_control_2_0_propagate");}
    if (VL_UNLIKELY((vlSelf->io_in_control_2_0_shift 
                     & 0xe0U))) {
        Verilated::overWidthError("io_in_control_2_0_shift");}
    if (VL_UNLIKELY((vlSelf->io_in_control_3_0_dataflow 
                     & 0xfeU))) {
        Verilated::overWidthError("io_in_control_3_0_dataflow");}
    if (VL_UNLIKELY((vlSelf->io_in_control_3_0_propagate 
                     & 0xfeU))) {
        Verilated::overWidthError("io_in_control_3_0_propagate");}
    if (VL_UNLIKELY((vlSelf->io_in_control_3_0_shift 
                     & 0xe0U))) {
        Verilated::overWidthError("io_in_control_3_0_shift");}
    if (VL_UNLIKELY((vlSelf->io_in_id_0_0 & 0xf8U))) {
        Verilated::overWidthError("io_in_id_0_0");}
    if (VL_UNLIKELY((vlSelf->io_in_id_1_0 & 0xf8U))) {
        Verilated::overWidthError("io_in_id_1_0");}
    if (VL_UNLIKELY((vlSelf->io_in_id_2_0 & 0xf8U))) {
        Verilated::overWidthError("io_in_id_2_0");}
    if (VL_UNLIKELY((vlSelf->io_in_id_3_0 & 0xf8U))) {
        Verilated::overWidthError("io_in_id_3_0");}
    if (VL_UNLIKELY((vlSelf->io_in_last_0_0 & 0xfeU))) {
        Verilated::overWidthError("io_in_last_0_0");}
    if (VL_UNLIKELY((vlSelf->io_in_last_1_0 & 0xfeU))) {
        Verilated::overWidthError("io_in_last_1_0");}
    if (VL_UNLIKELY((vlSelf->io_in_last_2_0 & 0xfeU))) {
        Verilated::overWidthError("io_in_last_2_0");}
    if (VL_UNLIKELY((vlSelf->io_in_last_3_0 & 0xfeU))) {
        Verilated::overWidthError("io_in_last_3_0");}
    if (VL_UNLIKELY((vlSelf->io_in_valid_0_0 & 0xfeU))) {
        Verilated::overWidthError("io_in_valid_0_0");}
    if (VL_UNLIKELY((vlSelf->io_in_valid_1_0 & 0xfeU))) {
        Verilated::overWidthError("io_in_valid_1_0");}
    if (VL_UNLIKELY((vlSelf->io_in_valid_2_0 & 0xfeU))) {
        Verilated::overWidthError("io_in_valid_2_0");}
    if (VL_UNLIKELY((vlSelf->io_in_valid_3_0 & 0xfeU))) {
        Verilated::overWidthError("io_in_valid_3_0");}
}
#endif  // VL_DEBUG
