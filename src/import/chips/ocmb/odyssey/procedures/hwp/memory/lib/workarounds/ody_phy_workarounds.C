/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/workarounds/ody_phy_workarounds.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023,2024                        */
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
/// @file ody_phy_workarounds.C
/// @brief Workarounds for PHY related issues
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#include <fapi2.H>
#include <mss_generic_attribute_getters.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/workarounds/ody_phy_workarounds.H>
#include <lib/shared/ody_consts.H>

namespace mss
{
namespace ody
{
namespace phy
{
namespace workarounds
{

///
/// @brief Clones data between redundant CS for tdqstracking
/// @param[in] i_target the target on which to operate
/// @param[in,out] io_struct the structure to update
/// @return FAPI2_RC_SUCCSS iff ok
///
fapi2::ReturnCode clone_redundant_cs_data_tdqstracking( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        user_input_advanced& io_struct )
{
    uint8_t l_redundant_cs[mss::ody::MAX_DIMM_PER_PORT] = {};
    FAPI_TRY(mss::attr::get_ddr5_redundant_cs_en(i_target, l_redundant_cs));

    // If redundant CS is enabled, the PHY needs the same data cloned across two CS
    // CS0/1 need the same data as well as CS2/3 needing the same data
    if(l_redundant_cs[0] == fapi2::ENUM_ATTR_MEM_EFF_REDUNDANT_CS_EN_ENABLE)
    {
        for (uint8_t l_pstate = 0; l_pstate < mss::ody::NUM_PSTATES; l_pstate++)
        {
            io_struct.EnTdqs2dqTrackingTg1[l_pstate] = io_struct.EnTdqs2dqTrackingTg0[l_pstate];
            io_struct.EnTdqs2dqTrackingTg3[l_pstate] = io_struct.EnTdqs2dqTrackingTg2[l_pstate];
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Checks if the Odyssey 2R redundant CS workaround is needed - DIMM target type specialization
/// @param[in] i_target the target on which to operate
/// @param[out] o_is_workaround_needed true if the workaround is needed, otherwise false
/// @return FAPI2_RC_SUCCSS iff ok
///
template <>
fapi2::ReturnCode is_2r_redundant_cs( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                      bool& o_is_workaround_needed )
{
    o_is_workaround_needed = false;

    uint8_t l_redundant_cs = 0;
    uint8_t l_mranks = 0;

    FAPI_TRY(mss::attr::get_ddr5_redundant_cs_en(i_target, l_redundant_cs));
    FAPI_TRY(mss::attr::get_num_master_ranks_per_dimm(i_target, l_mranks));

    // The workaround is needed for 2R, redundant CS DIMMs
    // Note: it might be needed on just 2R DIMMs but has only been confirmed on 2R, redundant CS DIMMs
    o_is_workaround_needed = (l_redundant_cs == fapi2::ENUM_ATTR_MEM_EFF_REDUNDANT_CS_EN_ENABLE) &&
                             (l_mranks == fapi2::ENUM_ATTR_MEM_EFF_NUM_MASTER_RANKS_PER_DIMM_2R);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Checks if the Odyssey 2R redundant CS workaround is needed - MEM_PORT target type specialization
/// @param[in] i_target the target on which to operate
/// @param[out] o_is_workaround_needed true if the workaround is needed, otherwise false
/// @return FAPI2_RC_SUCCSS iff ok
///
template <>
fapi2::ReturnCode is_2r_redundant_cs( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                      bool& o_is_workaround_needed )
{
    o_is_workaround_needed = false;

    // Loop over and check all DIMM targets
    for(const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target))
    {
        FAPI_TRY(is_2r_redundant_cs(l_dimm, o_is_workaround_needed ));

        // The workaround is needed, exit out
        if(o_is_workaround_needed)
        {
            return fapi2::FAPI2_RC_SUCCESS;
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // ns workarounds
} // ns phy
} // ns ody
} // ns mss
