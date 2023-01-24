/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/freq/p10_mss_freq_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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
/// @file p10_mss_freq_utils.H
/// @brief p10 specializations for frequency library
///
/// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
/// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 3
/// *HWP Consumed by: HB:FSP

#ifndef _P10_MSS_FREQ_UTILS_H_
#define _P10_MSS_FREQ_UTILS_H_

#include <fapi2.H>
#include <vpd_access.H>
#include <vector>

#include <lib/dimm/exp_rank.H>
#include <lib/dimm/ody_rank.H>

#include <lib/freq/p10_freq_traits.H>
#include <lib/freq/p10_sync.H>
#include <lib/eff_config/p10_spd_utils.H>

#include <generic/memory/lib/utils/find.H>
#include <mss_generic_attribute_getters.H>
#include <mss_generic_system_attribute_getters.H>
#include <generic/memory/lib/utils/freq/gen_mss_freq.H>
#include <generic/memory/lib/utils/freq/mss_freq_scoreboard.H>

namespace mss
{

///
/// @brief Determines if a DIMM is an LR dimm
/// @param[in] i_target the DIMM target on which to operate
/// @param[out] o_is_lr_dimm true if LRDIMM, else false
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success
///
// TODO Zen:MST-1901 Move this function to generic_attribute_accessors_manual.H for general use
fapi2::ReturnCode is_lr_dimm(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, bool& o_is_lr_dimm);

///
/// @brief Check VPD config for support of a given freq - helper for PROC_P10 specializations
/// @tparam MC mss:mc_type memory controller type
/// @param[in] i_target the target on which to operate
/// @param[in] i_proposed_freq frequency to check for support
/// @param[out] o_is_supported true if VPD supports the proposed frequency
/// @return FAPI2_RC_SUCCESS iff ok
///
// TODO Zen:MST-1901 Break up this function into smaller parts and add UTs
template<mss::mc_type MC>
fapi2::ReturnCode check_freq_support_vpd_p10(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
    const uint64_t i_proposed_freq,
    bool& o_is_supported)
{
    using TT = mss::frequency_traits<mss::proc_type::PROC_P10>;
    o_is_supported = false;

    std::vector<mss::rank::info<MC>> l_ranks;
    fapi2::VPDInfo<TT::VPD_TARGET_TYPE> l_vpd_info(TT::VPD_BLOB);

    const auto& l_vpd_target = mss::find_target<TT::VPD_TARGET_TYPE>(i_target);
    uint32_t l_omi_freq = 0;
    uint8_t l_is_planar = 0;

    l_vpd_info.iv_is_config_ffdc_enabled = false;

    FAPI_TRY(convert_ddr_freq_to_omi_freq(i_target, i_proposed_freq, l_omi_freq));
    l_vpd_info.iv_omi_freq_mhz = l_omi_freq;

    // Add planar EFD lookup info if we need it
    FAPI_TRY( mss::attr::get_mem_mrw_is_planar(l_vpd_target, l_is_planar) );

    for (const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target))
    {
        FAPI_TRY(mss::spd::ddr4::add_planar_efd_info(l_dimm, l_is_planar, l_vpd_info));
    }

    // DDIMM SPD can contain different SI settings for each master rank.
    // To determine which frequencies are supported, we have to check for each valid
    // master rank on the port's DIMMs
    FAPI_TRY(mss::rank::ranks_on_port(i_target, l_ranks));

    for (const auto& l_rank : l_ranks)
    {
        // We will skip LRDIMMs with ranks > 0
        bool l_is_lr_dimm = false;
        FAPI_TRY(is_lr_dimm(l_rank.get_dimm_target(), l_is_lr_dimm));

        if (rank_not_supported_in_vpd_config(l_is_lr_dimm, l_rank.get_dimm_rank()))
        {
            FAPI_DBG("LRDIMM ranks > 0 are not supported for check_freq_support_vpd. Skipping this rank. Target: %s",
                     mss::c_str(i_target));
            continue;
        }

        l_vpd_info.iv_rank = l_rank.get_phy_rank();

        // Check if this VPD configuration is supported
        FAPI_TRY(is_vpd_config_supported<mss::proc_type::PROC_P10>(l_vpd_target, i_proposed_freq, l_vpd_info, o_is_supported),
                 "%s failed to determine if %u freq is supported on rank %d", mss::c_str(i_target), i_proposed_freq, l_vpd_info.iv_rank);

        // If we fail any of the ranks, then this VPD configuration is not supported
        if(o_is_supported == false)
        {
            FAPI_INF("%s is not supported on rank %u exiting...", mss::c_str(i_target), l_rank.get_port_rank());
            break;
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Update supported frequency scoreboard according to processor limits - helper for PROC_P10 specializations
/// @tparam MC mss:mc_type memory controller type
/// @param[in] i_target processor frequency domain
/// @param[in,out] io_scoreboard scoreboard of port targets supporting each frequency
/// @return FAPI2_RC_SUCCESS iff ok
///
template<mss::mc_type MC>
fapi2::ReturnCode limit_freq_by_processor_p10(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    freq_scoreboard& io_scoreboard)
{
    fapi2::ATTR_CHIP_EC_FEATURE_DD1_LIMITED_OMI_FREQ_Type l_limited_omi_freq;

    // Set omi frequency limit flag based on whether the system is DD1
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_DD1_LIMITED_OMI_FREQ, i_target, l_limited_omi_freq),
             "%s failed to read ATTR_CHIP_EC_FEATURE_DD1_LIMITED_OMI_FREQ", mss::c_str(i_target));

    // OCMB always needs to be in sync between OMI and DDR, by the given ratio
    // so we convert the supported OMI freqs and remove every other DDR freq
    // from the scoreboard
    for (const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
    {
        const auto l_port_pos = mss::relative_pos<MC, fapi2::TARGET_TYPE_PROC_CHIP>(l_port);

        std::vector<uint64_t> l_converted_omi_freqs;

        // Check for DD1 OMI frequency limitation - if exists use 21330 MHz
        for (const auto l_omi_freq : (l_limited_omi_freq ? P10_LIMITED_OMI_FREQS : P10_OMI_FREQS))
        {
            uint64_t l_ddr_freq = 0;
            FAPI_TRY(convert_omi_freq_to_ddr_freq(l_port, l_omi_freq, l_ddr_freq));
            l_converted_omi_freqs.push_back(l_ddr_freq);
        }

        FAPI_TRY(io_scoreboard.remove_freqs_not_on_list(l_port_pos, l_converted_omi_freqs));
    }

fapi_try_exit:
    return fapi2::current_err;
}

}// mss

#endif
