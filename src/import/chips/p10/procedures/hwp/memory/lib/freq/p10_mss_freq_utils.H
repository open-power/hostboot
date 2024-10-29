/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/freq/p10_mss_freq_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023,2025                        */
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
// TODO JIRA:MSWT-203 Move this function to generic_attribute_accessors_manual.H for general use
fapi2::ReturnCode is_lr_dimm(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, bool& o_is_lr_dimm);

///
/// @brief Check VPD config for support of a given freq - helper for PROC_P10 specializations
/// @tparam MC mss:mc_type memory controller type
/// @param[in] i_target the target on which to operate
/// @param[in] i_proposed_freq frequency to check for support
/// @param[out] o_is_supported true if VPD supports the proposed frequency
/// @return FAPI2_RC_SUCCESS iff ok
///
// TODO JIRA:MSWT-203 Break up this function into smaller parts and add UTs
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
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MEM_MRW_IS_PLANAR, l_vpd_target, l_is_planar) );

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

        l_vpd_info.iv_rank = l_rank.get_efd_rank();

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
/// @brief Helper for limit_freq_by_processor_p10; determines the mem frequency limit for the system
/// @tparam MC mss:mc_type memory controller type
/// @param[in] i_port mem port
/// @param[in] i_limited_omi_freq ATTR_CHIP_EC_FEATURE_DD1_LIMITED_OMI_FREQ value
/// @param[in] i_slow_mem_test ATTR_SLOW_MEM_POOL_TEST value
/// @param[in] i_system_type ATTR_PVR_82_MODE value
/// @param[in] i_interposer_rev value of ATTR_INTERPOSER_REV
/// @param[in] i_is_ioSCM value of ATTR_IS_IOSCM
/// @param[in] i_ioSCM_freq_limit value of ATTR_MRW_MAX_DDR_FREQ_ON_IOSCM
/// @param[in] i_is_apollo value of ATTR_MSS_IS_APOLLO
/// @param[in] i_override value of ATTR_MEM_OVERRIDE_FREQ_LIMITATION, overrides mem freq limitations
/// @param[in,out] io_scoreboard vector to hold converted/limited omi frequencies
/// @return FAPI2_RC_SUCCESS iff ok
///
template<mss::mc_type MC>
fapi2::ReturnCode limit_freq_helper(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_port,
    const fapi2::ATTR_CHIP_EC_FEATURE_DD1_LIMITED_OMI_FREQ_Type& i_limited_omi_freq,
    const fapi2::ATTR_SLOW_MEM_POOL_TEST_Type& i_slow_mem_test,
    const fapi2:: ATTR_PVR_82_MODE_Type& i_system_type,
    const fapi2::ATTR_INTERPOSER_REV_Type& i_interposer_rev,
    const fapi2::ATTR_IS_IOSCM_Type& i_is_ioSCM,
    const uint16_t& i_ioSCM_freq_limit,
    const fapi2::ATTR_MSS_IS_APOLLO_Type& i_is_apollo,
    const fapi2::ATTR_MEM_OVERRIDE_FREQ_LIMITATION_Type& i_override,
    freq_scoreboard& io_scoreboard )
{
    const auto l_port_pos = mss::relative_pos<MC, fapi2::TARGET_TYPE_PROC_CHIP>(i_port);

    std::vector<uint64_t> l_converted_ddr_freqs;
    std::vector<uint64_t> l_omi_freqs = P10_LIMITED_OMI_FREQS;

    // check for OMI frequency limitation
    // PVR_82_MODE | DD1_LIMITED_OMI_FREQ | SLOW_MEM_POOL | ISC rev | ioSCM | Freq
    // ------------|----------------------|---------------|---------|-------|-----------
    // OFF         |   yes                |       x       |   x     |   x   | 21330
    // OFF         |   no                 |      yes      |   x     |   x   | 21330
    // OFF         |   no                 |      no       |   x     |   x   | 21330-38400
    // ON          |    x                 |      yes      |   x     |   x   | 21330
    // ON          |    x                 |      no       |  none   |   x   | 21330-32000
    // ON          |    x                 |      no       |  DD1    |   x   | 21330-32000
    // ON          |    x                 |      no       |  >DD1   |  yes  | limit to ATTR_MRW_MAX_DDR_FREQ_ON_IOSCM
    // ON          |    x                 |      no       |  >DD1   |  no   | 21330-38400
    //
    // NOTE: ATTR_IS_APOLLO and ATTR_MEM_OVERRIDE_FREQ_LIMITATION will override the above table to run at max frequency
    if ( i_is_apollo || i_override)
    {
        l_omi_freqs = P10_OMI_FREQS;
    }
    else if (i_system_type == fapi2::ENUM_ATTR_PVR_82_MODE_ON
             && i_slow_mem_test == fapi2::ENUM_ATTR_SLOW_MEM_POOL_TEST_DISABLE)
    {
        if (  i_interposer_rev == fapi2::ENUM_ATTR_INTERPOSER_REV_NONE
              || i_interposer_rev == fapi2::ENUM_ATTR_INTERPOSER_REV_REV1)
        {
            l_omi_freqs = P11_4000_LIMITED_OMI_FREQS;
        }
        else if (i_is_ioSCM)
        {
            // PVR_82 mode with ioSCMs
            uint32_t l_omi_freq = 0;
            FAPI_TRY(convert_ddr_freq_to_omi_freq(i_port, i_ioSCM_freq_limit, l_omi_freq));

            l_omi_freqs = P10_OMI_FREQS;

            while (!l_omi_freqs.empty() && l_omi_freqs.back() > l_omi_freq)
            {
                l_omi_freqs.pop_back();
            }
        }
        else
        {
            l_omi_freqs = P10_OMI_FREQS;
        }
    }
    else if (i_system_type == fapi2::ENUM_ATTR_PVR_82_MODE_OFF
             && i_slow_mem_test == fapi2::ENUM_ATTR_SLOW_MEM_POOL_TEST_DISABLE
             && !i_limited_omi_freq )
    {
        l_omi_freqs = P10_OMI_FREQS;
    }

    for (const auto l_omi_freq : l_omi_freqs)
    {
        uint64_t l_ddr_freq = 0;
        FAPI_TRY(convert_omi_freq_to_ddr_freq(i_port, l_omi_freq, l_ddr_freq));
        l_converted_ddr_freqs.push_back(l_ddr_freq);
    }

    FAPI_TRY(io_scoreboard.remove_freqs_not_on_list(l_port_pos, l_converted_ddr_freqs));

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
    fapi2::ATTR_SLOW_MEM_POOL_TEST_Type l_slow_mem_test;
    uint8_t l_pvr_82_sys;
    fapi2::ATTR_INTERPOSER_REV_Type l_interposer_rev;
    fapi2::ATTR_IS_IOSCM_Type l_is_ioSCM;
    uint16_t l_ioSCM_freq_limit;
    fapi2::ATTR_MSS_IS_APOLLO_Type l_is_apollo;
    fapi2::ATTR_MEM_OVERRIDE_FREQ_LIMITATION_Type l_override;

    // Set omi frequency limit flag based on whether the system is DD1
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_DD1_LIMITED_OMI_FREQ, i_target, l_limited_omi_freq),
             "%s failed to read ATTR_CHIP_EC_FEATURE_DD1_LIMITED_OMI_FREQ", mss::c_str(i_target));

    // Set up frequency limit override for slow memory test
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SLOW_MEM_POOL_TEST, i_target, l_slow_mem_test),
             "%s failed to read ATTR_SLOW_MEM_POOL_TEST", mss::c_str(i_target));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PVR_82_MODE, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_pvr_82_sys),
             "%s failed to read ATTR_PVR_82_MODE", mss::c_str(i_target));

    // Get revision and ioSCM presence to determine mem freq limits
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_INTERPOSER_REV, i_target, l_interposer_rev),
             "%s failed to read ATTR_INTERPOSER_REV", mss::c_str(i_target));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_IOSCM, i_target, l_is_ioSCM),
             "%s failed to read ATTR_IS_IOSCM", mss::c_str(i_target));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MRW_MAX_DDR_FREQ_ON_IOSCM, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           l_ioSCM_freq_limit),
             "%s failed to read ATTR_MRW_MAX_DDR_FREQ_ON_IOSCM", mss::c_str(i_target));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_IS_APOLLO, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_is_apollo),
             "%s failed to read ATTR_MSS_IS_APOLLO", mss::c_str(i_target));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_OVERRIDE_FREQ_LIMITATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           l_override),
             "%s failed to read ATTR_MEM_OVERRIDE_FREQ_LIMITATION", mss::c_str(i_target));

    // OCMB always needs to be in sync between OMI and DDR, by the given ratio
    // so we convert the supported OMI freqs and remove every other DDR freq
    // from the scoreboard
    for (const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
    {
        limit_freq_helper<MC>(l_port, l_limited_omi_freq, l_slow_mem_test, l_pvr_82_sys, l_interposer_rev,
                              l_is_ioSCM, l_ioSCM_freq_limit, l_is_apollo, l_override, io_scoreboard);
    }

fapi_try_exit:
    return fapi2::current_err;
}

}// mss

#endif
