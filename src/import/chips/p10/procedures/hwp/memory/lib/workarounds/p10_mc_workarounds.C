/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/workarounds/p10_mc_workarounds.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
// EKB-Mirror-To: hostboot

///
/// @file p10_mc_workarounds.C
/// @brief Workarounds for P10 MC procedures
///
// *HWP HWP Owner: Mark Pizzutillo <Mark.Pizzutillo@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: Memory

#include <fapi2.H>
#include <generic/memory/lib/utils/find.H>
#include <mss_generic_system_attribute_getters.H>
#include <mss_generic_attribute_getters.H>
#include <lib/workarounds/p10_mc_workarounds.H>

namespace mss
{
namespace workarounds
{
namespace mc
{

///
/// @brief Get EC-specific value for MCMODE0_DISABLE_MC_SYNC
/// @param[in] i_primary true if this is the primary MI to program, otherwise false
/// @param[in] i_ec_workaround value from ATTR_CHIP_EC_FEATURE_THROTTLE_SYNC_HW550549
/// @return mss::states value for the reg field
///
mss::states get_mc_sync_value(
    const bool i_primary,
    const bool i_ec_workaround)
{
    // For DD2.0 and beyond we need to set MCMODE0_DISABLE_MC_SYNC to 0 for all MCs
    if (!i_ec_workaround)
    {
        return mss::states::OFF;
    }

    // For DD1.x we only set MCMODE0_DISABLE_MC_SYNC to 0 for the primary MC
    return i_primary ? mss::states::OFF : mss::states::ON;
}

} // mc
} // workarounds
} // mss
