/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/workarounds/exp_fir_workarounds.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
/// @file exp_fir_workarounds.C
/// @brief Workarounds for Explorer FIR settings
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: Memory

#include <fapi2.H>
#include <generic/memory/lib/utils/scom.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/workarounds/exp_fir_workarounds.H>

namespace mss
{
namespace exp
{
namespace workarounds
{
namespace fir
{

///
/// @brief Function handling the MC_OMI_FIR x4 degrade FIR settings
/// @param[in] i_target the OCMB_CHIP target of the MC_OMI fir
/// @param[in] i_omi_fail_action value from ATTR_OMI_X4_DEGRADE_ACTION
/// @param[in,out] io_exp_mc_omi_fir_reg the MC_OMI_FIR register instance
///
void override_x4_degrade_fir( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                              const uint8_t i_omi_fail_action,
                              mss::fir::reg<EXPLR_DLX_MC_OMI_FIR_REG>& io_exp_mc_omi_fir_reg )
{
    // Write MC_OMI_FIR register per attr setting
    switch(i_omi_fail_action)
    {
        case fapi2::ENUM_ATTR_OMI_X4_DEGRADE_ACTION_XSTOP:
            FAPI_DBG("%s Setting MC_OMI_FIR degrade FIR to checkstop per attribute setting", mss::c_str(i_target));
            io_exp_mc_omi_fir_reg.checkstop<EXPLR_DLX_MC_OMI_FIR_REG_DL0_X4_MODE>();
            break;

        case fapi2::ENUM_ATTR_OMI_X4_DEGRADE_ACTION_MASKED:
            FAPI_DBG("%s Setting MC_OMI_FIR degrade FIR to masked per attribute setting", mss::c_str(i_target));
            io_exp_mc_omi_fir_reg.masked<EXPLR_DLX_MC_OMI_FIR_REG_DL0_X4_MODE>();
            break;

        case fapi2::ENUM_ATTR_OMI_X4_DEGRADE_ACTION_LOCAL_XSTOP:
            FAPI_DBG("%s Setting MC_OMI_FIR degrade FIR to local_checkstop per attribute setting", mss::c_str(i_target));
            io_exp_mc_omi_fir_reg.local_checkstop<EXPLR_DLX_MC_OMI_FIR_REG_DL0_X4_MODE>();
            break;

        default:
            // By default just leave it recoverable
            FAPI_DBG("%s Leaving MC_OMI_FIR degrade FIR as recoverable per attribute setting", mss::c_str(i_target));
            io_exp_mc_omi_fir_reg.recoverable_error<EXPLR_DLX_MC_OMI_FIR_REG_DL0_X4_MODE>();
            break;
    }
}

} // fir
} // workarounds
} // exp
} // mss
