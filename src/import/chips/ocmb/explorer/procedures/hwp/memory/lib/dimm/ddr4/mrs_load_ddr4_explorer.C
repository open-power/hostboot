/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/dimm/ddr4/mrs_load_ddr4_explorer.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
/// @file mrs_load_ddr4_explorer.C
/// @brief Run and manage the DDR4 mrs loading
///
// *HWP HWP Owner: Matthew Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <lib/shared/exp_defaults.H>
#include <lib/ccs/ccs_traits_explorer.H>
#include <lib/ecc/ecc_traits_explorer.H>
#include <lib/dimm/exp_mrs_traits.H>
#include <fapi2.H>
#include <mss_generic_attribute_getters.H>
#include <generic/memory/lib/dimm/ddr4/mrs_load_ddr4.H>
#include <lib/dimm/exp_rank.H>
#include <lib/ccs/ccs_explorer.H>

namespace mss
{

///
/// @brief Helper function to determine whether the A17 is needed
/// @param[in] i_target the DIMM target
/// @param[out] o_is_needed boolean whether A17 should be turned on or off
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note Based off of Table 2.8 Proposed DDR4 Full spec update(79-4B) page 28
///
template<>
fapi2::ReturnCode is_a17_needed<mss::mc_type::EXPLORER>(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        bool& o_is_needed)
{
    uint8_t l_dram_density = 0;
    uint8_t l_dram_width = 0;

    FAPI_TRY( mss::attr::get_dram_density( i_target, l_dram_density) );
    FAPI_TRY( mss::attr::get_dram_width( i_target, l_dram_width) );

    o_is_needed = (l_dram_density == fapi2::ENUM_ATTR_EFF_DRAM_DENSITY_16G
                   && l_dram_width == fapi2::ENUM_ATTR_EFF_DRAM_WIDTH_X4);

    FAPI_INF("%s Turning A17 %s", mss::c_str(i_target), o_is_needed ? "on" : "off" );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to determine whether the A17 is needed
/// @param[in] i_target the MEM_PORT target
/// @param[out] o_is_needed boolean whether A17 should be turned on or off
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note Based off of Table 2.8 Proposed DDR4 Full spec update(79-4B) page 28
///
template<>
fapi2::ReturnCode is_a17_needed<mss::mc_type::EXPLORER>(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        bool& o_is_needed)
{
    o_is_needed = false;

    // Loop over the DIMMs and see if A17 is needed for one of them
    // If so, we enable the parity bit in the PHY
    for (const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target) )
    {
        // Default to not used
        // Using temp because we want to OR the two results together. Don't want the false to overwrite
        bool l_temp = false;
        FAPI_TRY( is_a17_needed<mss::mc_type::EXPLORER>( l_dimm, l_temp), "%s Failed to get a17 boolean", mss::c_str(l_dimm) );

        o_is_needed = o_is_needed || l_temp;
    }

    // Returning success here for safety - if we don't have DIMM's we want to return successfully
    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

namespace ddr4
{

///
/// @brief Checks if the RTT_NOM override should be run - explorer specialization
/// @param[in] i_target the target on which to operate
/// @param[out] o_run_override true if the override should be run
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode is_rtt_nom_override_needed<mss::mc_type::EXPLORER>(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
    bool& o_run_override)
{
    // Always run for explorer as we're just using this for PDA and not for any initialization
    o_run_override = true;
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Attribute getter helper for RTT_NOM - explorer specialization
/// @param[in] i_target the target on which to operate
/// @param[out] o_array the array with the attr values
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode rtt_nom_attr_helper<mss::mc_type::EXPLORER>(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        uint8_t (&o_array)[MAX_RANK_PER_DIMM])
{
    return mss::attr::get_exp_resp_dram_rtt_nom(i_target, o_array);
}

///
/// @brief Attribute getter helper for RTT_WR - explorer specialization
/// @param[in] i_target the target on which to operate
/// @param[out] o_array the array with the attr values
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template<>
fapi2::ReturnCode rtt_wr_attr_helper<mss::mc_type::EXPLORER>(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        uint8_t (&o_array)[MAX_RANK_PER_DIMM])
{
    return mss::attr::get_exp_resp_dram_rtt_wr(i_target, o_array);
}

} // ns ddr4
} // ns mss
