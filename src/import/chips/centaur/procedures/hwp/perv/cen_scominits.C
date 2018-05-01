/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/perv/cen_scominits.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2018                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/* Ibm_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/centaur/procedures/hwp/perv/cen_scominits.C $           */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
///
/// @file cen_scominits.C
/// @brief: Centaur scom inits (FAPI2)
///
/// empty procedure for now.
///

//
/// @author Peng Fei GOU <shgoupf@cn.ibm.com>
///

//
// *HWP HWP Owner: Peng Fei GOU <shgoupf@cn.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Perv
// *HWP Level: 2
// *HWP Consumed by: HB
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <cen_scominits.H>
#include <cen_gen_scom_addresses.H>
#include <cen_gen_scom_addresses_fixes.H>
#include <cen_gen_scom_addresses_fld.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode
cen_scominits(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target)
{
    FAPI_DBG("Start");

    // trace setup, moved from MBS SCOM initfile based on inability to apply
    // via inband (HW440754)
    //
    {
        // set controls in each chiplet to force trace freeze on xstop
        fapi2::buffer<uint64_t> l_dbg_mode_reg;
        fapi2::buffer<uint64_t> l_dbg_trace_mode_reg2;

        // TP
        FAPI_TRY(fapi2::getScom(i_target,
                                CEN_DBG_MODE_REG,
                                l_dbg_mode_reg),
                 "Error from getScom (CEN_DBG_MODE_REG)");
        l_dbg_mode_reg.setBit<CEN_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION>();
        FAPI_TRY(fapi2::putScom(i_target,
                                CEN_DBG_MODE_REG,
                                l_dbg_mode_reg),
                 "Error from putScom (CEN_DBG_MODE_REG)");

        FAPI_TRY(fapi2::getScom(i_target,
                                CEN_DBG_TRACE_MODE_REG_2,
                                l_dbg_trace_mode_reg2),
                 "Error from getScom (CEN_DBG_TRACE_MODE_REG_2)");
        l_dbg_trace_mode_reg2.setBit<CEN_DBG_TRACE_MODE_REG_2_STOP_ON_ERR>();
        FAPI_TRY(fapi2::putScom(i_target,
                                CEN_DBG_TRACE_MODE_REG_2,
                                l_dbg_trace_mode_reg2),
                 "Error from putScom (CEN_DBG_TRACE_MODE_REG_2)");

        // NEST
        FAPI_TRY(fapi2::getScom(i_target,
                                CEN_TCN_DBG_MODE_REG,
                                l_dbg_mode_reg),
                 "Error from getScom (CEN_TCN_DBG_MODE_REG)");
        l_dbg_mode_reg.setBit<CEN_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION>();
        FAPI_TRY(fapi2::putScom(i_target,
                                CEN_TCN_DBG_MODE_REG,
                                l_dbg_mode_reg),
                 "Error from putScom (CEN_TCN_DBG_MODE_REG)");

        FAPI_TRY(fapi2::getScom(i_target,
                                CEN_TCN_DBG_TRACE_MODE_REG_2,
                                l_dbg_trace_mode_reg2),
                 "Error from getScom (CEN_TCN_DBG_TRACE_MODE_REG_2)");
        l_dbg_trace_mode_reg2.setBit<CEN_DBG_TRACE_MODE_REG_2_STOP_ON_ERR>();
        FAPI_TRY(fapi2::putScom(i_target,
                                CEN_TCN_DBG_TRACE_MODE_REG_2,
                                l_dbg_trace_mode_reg2),
                 "Error from putScom (CEN_TCN_DBG_TRACE_MODE_REG_2)");

        // MEM
        FAPI_TRY(fapi2::getScom(i_target,
                                CEN_TCM_DBG_MODE_REG,
                                l_dbg_mode_reg),
                 "Error from getScom (CEN_TCM_DBG_MODE_REG)");
        l_dbg_mode_reg.setBit<CEN_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION>();
        FAPI_TRY(fapi2::putScom(i_target,
                                CEN_TCM_DBG_MODE_REG,
                                l_dbg_mode_reg),
                 "Error from putScom (CEN_TCM_DBG_MODE_REG)");

        FAPI_TRY(fapi2::getScom(i_target,
                                CEN_TCM_DBG_TRACE_MODE_REG_2,
                                l_dbg_trace_mode_reg2),
                 "Error from getScom (CEN_TCM_DBG_TRACE_MODE_REG_2)");
        l_dbg_trace_mode_reg2.setBit<CEN_DBG_TRACE_MODE_REG_2_STOP_ON_ERR>();
        FAPI_TRY(fapi2::putScom(i_target,
                                CEN_TCM_DBG_TRACE_MODE_REG_2,
                                l_dbg_trace_mode_reg2),
                 "Error from putScom (CEN_TCM_DBG_TRACE_MODE_REG_2)");
    }

    // ensure that MBI traces are running, to trace framelock/FRTL activity
    {
        fapi2::buffer<uint64_t> l_trctrl_config = 0;
        l_trctrl_config.setBit<CEN_TCN_TRA_MBITRA_TRACE_TRCTRL_CONFIG_LCL_CLK_GATE_CTRL,
                               CEN_TCN_TRA_MBITRA_TRACE_TRCTRL_CONFIG_LCL_CLK_GATE_CTRL_LEN>();

        FAPI_TRY(fapi2::putScom(i_target,
                                CEN_TCN_TRA_MBITRA_TRACE_TRCTRL_CONFIG,
                                l_trctrl_config),
                 "Error from putScom (CEN_TCN_TRA_MBITRA_TRACE_TRCTRL_CONFIG)");
    }

    // TP pervasive LFIR setup
    {
        fapi2::buffer<uint64_t> l_tp_perv_lfir_mask_or;
        fapi2::buffer<uint64_t> l_tp_perv_lfir_mask_and;
        fapi2::buffer<uint64_t> l_tp_perv_lfir_action0;
        fapi2::buffer<uint64_t> l_tp_perv_lfir_action1;
        l_tp_perv_lfir_mask_and.flush<1>();

        // 0    CFIR internal parity error          recoverable     unmask
        l_tp_perv_lfir_action0.clearBit<0>();
        l_tp_perv_lfir_action1.setBit<0>();
        l_tp_perv_lfir_mask_and.clearBit<0>();

        // 1    GPIO (PCB error)                    recoverable     mask (forever)
        // 2    CC (PCB error)                      recoverable     mask (forever)
        // 3    CC (OPCG, parity, scan collision)   recoverable     mask (forever)
        // 4    PSC (PCB error)                     recoverable     mask (forever)
        // 5    PSC (parity error)                  recoverable     mask (forever)
        // 6    Thermal (parity error)              recoverable     mask (forever)
        // 7    Thermal (PCB error)                 recoverable     mask (forever)
        // 8    Thermal (critical Trip error)       recoverable     mask (forever)
        // 9    Thermal (fatal Trip error)          recoverable     mask (forever)
        // 10   Thermal (Voltage trip error)        recoverable     mask (forever)
        // 11   Trace Array                         recoverable     mask (forever)
        // 12   Trace Array                         recoverable     mask (forever)
        l_tp_perv_lfir_action0.clearBit<1, 12>();
        l_tp_perv_lfir_action1.setBit<1, 12>();
        l_tp_perv_lfir_mask_or.setBit<1, 12>();

        // 13   ITR                                 recoverable     unmask
        l_tp_perv_lfir_action0.clearBit<13>();
        l_tp_perv_lfir_action1.setBit<13>();
        l_tp_perv_lfir_mask_and.clearBit<13>();

        // 14   ITR                                 recoverable     unmask
        l_tp_perv_lfir_action0.clearBit<14>();
        l_tp_perv_lfir_action1.setBit<14>();
        l_tp_perv_lfir_mask_and.clearBit<14>();

        // 15   ITR (itr_tc_pcbsl_slave_fir_err)    recoverable     mask (forever)
        // 16   PIB                                 recoverable     mask (forever)
        // 17   PIB                                 recoverable     mask (forever)
        // 18   PIB                                 recoverable     mask (forever)
        l_tp_perv_lfir_action0.clearBit<15, 4>();
        l_tp_perv_lfir_action1.setBit<15, 4>();
        l_tp_perv_lfir_mask_or.setBit<15, 4>();

        // 19   nest PLLlock                        recoverable     unmask
        // 20   mem PLLlock                         recoverable     unmask
        l_tp_perv_lfir_action0.clearBit<19, 2>();
        l_tp_perv_lfir_action1.setBit<19, 2>();
        l_tp_perv_lfir_mask_and.clearBit<19, 2>();

        // 21:39 unused local errors                recoverable     mask (forever)
        // 40   local xstop in another chiplet      recoverable     mask (forever)
        l_tp_perv_lfir_action0.clearBit<21, 20>();
        l_tp_perv_lfir_action1.setBit<21, 20>();
        l_tp_perv_lfir_mask_or.setBit<21, 20>();

        // 41:63 Reserved                           not implemented, so won't touch these

        FAPI_TRY(fapi2::putScom(i_target, CEN_LOCAL_FIR_ACTION0_PCB, l_tp_perv_lfir_action0),
                 "Error from putScom (CEN_PERV_TP_LOCAL_FIR_ACTION0)");
        FAPI_TRY(fapi2::putScom(i_target, CEN_LOCAL_FIR_ACTION1_PCB, l_tp_perv_lfir_action1),
                 "Error from putScom (CEN_PERV_TP_LOCAL_FIR_ACTION1)");
        FAPI_TRY(fapi2::putScom(i_target, CEN_PERV_TP_LOCAL_FIR_MASK_OR, l_tp_perv_lfir_mask_or),
                 "Error from putScom (CEN_PERV_TP_LOCAL_FIR_MASK_OR)");
        FAPI_TRY(fapi2::putScom(i_target, CEN_PERV_TP_LOCAL_FIR_MASK_AND, l_tp_perv_lfir_mask_and),
                 "Error from putScom (CEN_PERV_TP_LOCAL_FIR_MASK_AND)");
    }

    // Nest pervasive LFIR setup
    {
        fapi2::buffer<uint64_t> l_nest_perv_lfir_mask_or;
        fapi2::buffer<uint64_t> l_nest_perv_lfir_mask_and;
        fapi2::buffer<uint64_t> l_nest_perv_lfir_action0;
        fapi2::buffer<uint64_t> l_nest_perv_lfir_action1;
        l_nest_perv_lfir_mask_and.flush<1>();

        // 0    CFIR internal parity error          recoverable     unmask
        l_nest_perv_lfir_action0.clearBit<0>();
        l_nest_perv_lfir_action1.setBit<0>();
        l_nest_perv_lfir_mask_and.clearBit<0>();

        // 1    GPIO (PCB error)                    recoverable     mask (forever)
        // 2    CC (PCB error)                      recoverable     mask (forever)
        // 3    CC (OPCG, parity, scan collision)   recoverable     mask (forever)
        // 4    PSC (PCB error)                     recoverable     mask (forever)
        // 5    PSC (parity error)                  recoverable     mask (forever)
        // 6    Thermal (parity error)              recoverable     mask (forever)
        // 7    Thermal (PCB error)                 recoverable     mask (forever)
        // 8    Thermal (critical Trip error)       recoverable     mask (forever)
        // 9    Thermal (fatal Trip error)          recoverable     mask (forever)
        // 10   Thermal (Voltage trip error)        recoverable     mask (forever)
        // 11   Trace Array                         recoverable     mask (forever)
        // 12   Trace Array                         recoverable     mask (forever)
        // 13:39 unused local errors                recoverable     mask (forever)
        // 40   local xstop in another chiplet      recoverable     mask (forever)
        l_nest_perv_lfir_action0.clearBit<1, 40>();
        l_nest_perv_lfir_action1.setBit<1, 40>();
        l_nest_perv_lfir_mask_or.setBit<1, 40>();

        // 41:63 Reserved                           not implemented, so won't touch these

        FAPI_TRY(fapi2::putScom(i_target, CEN_TCN_LOCAL_FIR_ACTION0_PCB, l_nest_perv_lfir_action0),
                 "Error from putScom (CEN_NEST_TP_LOCAL_FIR_ACTION0)");
        FAPI_TRY(fapi2::putScom(i_target, CEN_TCN_LOCAL_FIR_ACTION1_PCB, l_nest_perv_lfir_action1),
                 "Error from putScom (CEN_NEST_TP_LOCAL_FIR_ACTION1)");
        FAPI_TRY(fapi2::putScom(i_target, CEN_TCN_LOCAL_FIR_MASK_PCB2, l_nest_perv_lfir_mask_or),
                 "Error from putScom (CEN_NEST_TP_LOCAL_FIR_MASK_OR)");
        FAPI_TRY(fapi2::putScom(i_target, CEN_TCN_LOCAL_FIR_MASK_PCB1, l_nest_perv_lfir_mask_and),
                 "Error from putScom (CEN_NEST_TP_LOCAL_FIR_MASK_AND)");
    }

    // Mem pervasive LFIR setup
    {
        fapi2::buffer<uint64_t> l_mem_perv_lfir_mask_or;
        fapi2::buffer<uint64_t> l_mem_perv_lfir_mask_and;
        fapi2::buffer<uint64_t> l_mem_perv_lfir_action0;
        fapi2::buffer<uint64_t> l_mem_perv_lfir_action1;
        l_mem_perv_lfir_mask_and.flush<1>();

        // 0    CFIR internal parity error          recoverable     unmask
        l_mem_perv_lfir_action0.clearBit<0>();
        l_mem_perv_lfir_action1.setBit<0>();
        l_mem_perv_lfir_mask_and.clearBit<0>();

        // 1    GPIO (PCB error)                    recoverable     mask (forever)
        // 2    CC (PCB error)                      recoverable     mask (forever)
        // 3    CC (OPCG, parity, scan collision)   recoverable     mask (forever)
        // 4    PSC (PCB error)                     recoverable     mask (forever)
        // 5    PSC (parity error)                  recoverable     mask (forever)
        // 6    Thermal (parity error)              recoverable     mask (forever)
        // 7    Thermal (PCB error)                 recoverable     mask (forever)
        // 8    Thermal (critical Trip error)       recoverable     mask (forever)
        // 9    Thermal (fatal Trip error)          recoverable     mask (forever)
        // 11   mba01 Trace Array                   recoverable     mask (forever)
        // 12   mba01 Trace Array                   recoverable     mask (forever)
        // 13   mba23 Trace Array                   recoverable     mask (forever)
        // 14   mba23 Trace Array                   recoverable     mask (forever)
        // 15:39 unused local errors                recoverable     mask (forever)
        // 40   local xstop in another chiplet      recoverable     mask (forever)
        l_mem_perv_lfir_action0.clearBit<1, 40>();
        l_mem_perv_lfir_action1.setBit<1, 40>();
        l_mem_perv_lfir_mask_or.setBit<1, 40>();

        // 41:63 Reserved                           not implemented, so won't touch these

        FAPI_TRY(fapi2::putScom(i_target, CEN_TCM_LOCAL_FIR_ACTION0_PCB, l_mem_perv_lfir_action0),
                 "Error from putScom (CEN_MEM_TP_LOCAL_FIR_ACTION0)");
        FAPI_TRY(fapi2::putScom(i_target, CEN_TCM_LOCAL_FIR_ACTION1_PCB, l_mem_perv_lfir_action1),
                 "Error from putScom (CEN_MEM_TP_LOCAL_FIR_ACTION1)");
        FAPI_TRY(fapi2::putScom(i_target, CEN_TCM_LOCAL_FIR_MASK_PCB2, l_mem_perv_lfir_mask_or),
                 "Error from putScom (CEN_MEM_TP_LOCAL_FIR_MASK_OR)");
        FAPI_TRY(fapi2::putScom(i_target, CEN_TCM_LOCAL_FIR_MASK_PCB1, l_mem_perv_lfir_mask_and),
                 "Error from putScom (CEN_MEM_TP_LOCAL_FIR_MASK_AND)");
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

