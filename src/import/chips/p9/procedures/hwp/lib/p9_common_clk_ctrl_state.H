/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/lib/p9_common_clk_ctrl_state.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file  p9_common_clk_ctrl_state.H
/// @brief Check cache/core clock controller status
///
/// Procedure Summary:

// *HWP HWP Owner          : David Du       <daviddu@us.ibm.com>
// *HWP Backup HWP Owner   : Greg Still     <stillgs@us.ibm.com>
// *HWP FW Owner           : Sangeetha T S  <sangeet2@in.ibm.com>
// *HWP Team               : PM
// *HWP Consumed by        : HB:PERV
// *HWP Level              : 2

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include <fapi2.H>
#include <p9_quad_scom_addresses.H>
#include <p9_hcd_common.H>

//------------------------------------------------------------------------------
// Constant Definitions
//------------------------------------------------------------------------------

const uint64_t NET_CTRL0[2] = { C_NET_CTRL0, EQ_NET_CTRL0};
const uint64_t PPM_PFSNS[2] = { C_PPM_PFSNS, EQ_PPM_PFSNS};

#define RETURN_FALSE_IF(cause, message) \
    if (cause)                          \
    {                                   \
        FAPI_INF(message);              \
        l_rc = fapi2::FAPI2_RC_FALSE;   \
        goto fapi_try_exit;             \
    }

//-----------------------------------------------------------------------------
// Template Procedure
//------------------------------------------------------------------------------

template <fapi2::TargetType K>
fapi2::ReturnCode
p9_common_clk_ctrl_state(
    const fapi2::Target<K>& i_target)
{
    FAPI_INF(">>p9_common_clk_ctrl_state");
    fapi2::ReturnCode       l_rc = fapi2::FAPI2_RC_SUCCESS;
    fapi2::buffer<uint64_t> l_data64;
    uint32_t                l_type = 0; // Assumes core

    if((i_target.getType() & fapi2::TARGET_TYPE_EQ))
    {
        l_type = 1;
    }

    FAPI_DBG("Check chiplet accessibility via NET_CTRL0[0,1,16,25,26]");
    FAPI_TRY(getScom(i_target, NET_CTRL0[l_type], l_data64));

    RETURN_FALSE_IF((l_data64.getBit<25>() == 1),
                    "WARNING: Chiplet appears Offline as PCB Fence is up. Skipping");

    RETURN_FALSE_IF((l_data64.getBit<0>() == 0),
                    "WARNING: Chiplet Disabled. Assume being Partial Bad. Skipping");

    RETURN_FALSE_IF((l_data64.getBit<1>() == 1),
                    "WARNING: Chiplet in fixed state as PcbEpReset is on. Skipping");

    RETURN_FALSE_IF((l_data64.getBit<26>() == 1),
                    "WARNING: Chiplet Elec Fence is up. PCB path blocked. Skipping");

    RETURN_FALSE_IF((l_data64.getBit<16>() == 1),
                    "WARNING: Chiplet VitalClk off. ClkCtrl inaccessible. Skipping");

    FAPI_DBG("Check chiplet power state via PPM_PFSNS[1]");
    FAPI_TRY(getScom(i_target, PPM_PFSNS[l_type], l_data64));

    RETURN_FALSE_IF((l_data64.getBit<1>() == 1),
                    "WARNING: Chiplet out of power while Elec Fence down. Skipping");

fapi_try_exit:

    FAPI_INF("<<p9_common_clk_ctrl_state");
    return l_rc;
}
