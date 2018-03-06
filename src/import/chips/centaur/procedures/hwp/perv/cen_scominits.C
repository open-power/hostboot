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

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

