/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/freq/p10_mss_freq_utils.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file p10_mss_freq.C
/// @brief p10 specializations for frequency library
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#include <fapi2.H>
#include <vpd_access.H>
#include <vector>

// Explorer rank API
#include <lib/shared/exp_defaults.H>
#include <lib/dimm/exp_rank.H>

// Memory libraries
#include <lib/freq/p10_freq_traits.H>
#include <lib/shared/p10_consts.H>
#include <lib/freq/p10_sync.H>

// Generic libraries
#include <mss_generic_attribute_getters.H>
#include <mss_generic_attribute_setters.H>
#include <mss_generic_system_attribute_getters.H>
#include <generic/memory/lib/utils/assert_noexit.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <generic/memory/lib/utils/freq/gen_mss_freq.H>
#include <generic/memory/lib/utils/freq/mss_freq_scoreboard.H>

namespace mss
{

const std::vector< uint64_t > frequency_traits<mss::proc_type::PROC_P10>::SUPPORTED_FREQS =
{
    mss::DIMM_SPEED_2666,
    mss::DIMM_SPEED_2933,
    mss::DIMM_SPEED_3200,
};

///
/// @brief      Sets DRAM CAS latency attributes - specialization for PROC_P10 and MEM_PORT
/// @param[in]  i_target the controller target for the cas_latency value
/// @param[in]  i_cas_latency cas latency to update
/// @return     FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode set_CL_attr<mss::proc_type::PROC_P10>(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
    const uint64_t i_cas_latency)
{
    const auto l_temp = static_cast<uint8_t>(i_cas_latency);

    //Check for rounding issues. Going from a uint64_t to a uint8_t
    FAPI_ASSERT( l_temp == i_cas_latency,
                 fapi2::MSS_BAD_CL_CAST()
                 .set_CL(i_cas_latency)
                 .set_PORT_TARGET(i_target),
                 "%s bad cast for cas latency from %d to %d",
                 mss::c_str(i_target),
                 i_cas_latency,
                 l_temp);

    FAPI_INF( "Final Chosen CL: %d for %s", l_temp, mss::c_str(i_target));

    FAPI_TRY( mss::attr::set_dram_cl(i_target, l_temp) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Sets the frequency value - specialization for PROC_P10 and MEM_PORT
/// @param[in]  i_target the target on which to set the frequency values
/// @param[in]  i_freq frequency value to set
/// @return     FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode set_freq<mss::proc_type::PROC_P10>(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_freq)
{
    for (const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
    {
        FAPI_TRY( mss::attr::set_freq(l_port, i_freq) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Gets the number of master ranks per DIMM - specialization for PROC_P10 and MEM_PORT
/// @param[in]  i_target the target on which to get the number of master ranks per DIMM
/// @param[out] o_master_ranks number of master ranks per DIMM
/// @return     FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode get_master_rank_per_dimm<mss::proc_type::PROC_P10>(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
    uint8_t* o_master_ranks)
{
    using TT = mss::frequency_traits<mss::proc_type::PROC_P10>;

    uint8_t l_master_ranks[TT::MAX_DIMM_PER_PORT] = {0};
    FAPI_TRY(mss::attr::get_num_master_ranks_per_dimm(i_target, l_master_ranks));
    std::copy(&l_master_ranks[0], &l_master_ranks[0] + TT::MAX_DIMM_PER_PORT, &o_master_ranks[0]);

fapi_try_exit:
    return fapi2::current_err;
}
///
/// @brief Gets the DIMM type for a specific DIMM - specialization for the PROC_P10 processor type
/// @param[in] i_target DIMM target
/// @param[out] o_dimm_type DIMM type on the DIMM target
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode get_dimm_type<mss::proc_type::PROC_P10>(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_dimm_type)
{
    return mss::attr::get_dimm_type(i_target, o_dimm_type);
}

///
/// @brief Gets the attribute for the maximum - specialization for PROC_P10
/// @param[out] o_allowed_dimm_freq allowed dimm frequency
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode max_allowed_dimm_freq<mss::proc_type::PROC_P10>(uint32_t* o_allowed_dimm_freq)
{
    uint32_t l_allowed_dimm_freq[NUM_MAX_FREQS] = {0};
    FAPI_TRY(mss::attr::get_max_allowed_dimm_freq(l_allowed_dimm_freq));
    std::copy(&l_allowed_dimm_freq[0], &l_allowed_dimm_freq[0] + NUM_MAX_FREQS, &o_allowed_dimm_freq[0]);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief      Gets the DIMM type - specialization for PROC_P10 and MEM_PORT
/// @param[in]  i_target the target on which to get the DIMM types
/// @param[out] o_dimm_type DIMM types
/// @return     FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode get_dimm_type<mss::proc_type::PROC_P10>(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
    uint8_t* o_dimm_type)
{
    using TT = mss::frequency_traits<mss::proc_type::PROC_P10>;

    uint8_t l_dimm_type[TT::MAX_DIMM_PER_PORT] = {0};
    FAPI_TRY(mss::attr::get_dimm_type(i_target, l_dimm_type));
    std::copy(&l_dimm_type[0], &l_dimm_type[0] + TT::MAX_DIMM_PER_PORT, &o_dimm_type[0]);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Calls out the code if we calculated a bad frequency for the domain - specialization for PROC_P10 and MEM_PORT
/// @param[in] i_target target on which to operate
/// @param[in] i_final_freq frequency calculated for domain
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode callout_bad_freq_calculated<mss::proc_type::PROC_P10>(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint64_t i_final_freq)
{
    using TT = mss::frequency_traits<mss::proc_type::PROC_P10>;

    // Declaring temporary variables to avoid linker errors associated with FAPI_ASSERT
    const auto FREQ0 = TT::SUPPORTED_FREQ0;
    const auto FREQ1 = TT::SUPPORTED_FREQ1;
    const auto FREQ2 = TT::SUPPORTED_FREQ2;

    // If we don't find a valid frequency OR don't get a 0 (nothing configured on this clock domain), then error out
    FAPI_ASSERT( std::binary_search(TT::SUPPORTED_FREQS.begin(), TT::SUPPORTED_FREQS.end(), i_final_freq) ||
                 i_final_freq == 0,
                 fapi2::P10_MSS_BAD_FREQ_CALCULATED()
                 .set_MSS_FREQ(i_final_freq)
                 .set_TARGET(i_target)
                 .set_PROC_TYPE(mss::proc_type::PROC_P10)
                 .set_SUPPORTED_FREQ_0(FREQ0)
                 .set_SUPPORTED_FREQ_1(FREQ1)
                 .set_SUPPORTED_FREQ_2(FREQ2),
                 "%s: Calculated FREQ (%d) isn't supported",
                 mss::c_str(i_target),
                 i_final_freq);

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines if rank info object is that of an LR dimm
///
/// @param[in] i_rank_info rank info object
/// @param[out] l_lr_dimm true if LRDIMM, else false
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success
///
inline fapi2::ReturnCode rank_is_lr_dimm(const mss::rank::info<> i_rank_info, bool& o_lr_dimm)
{
    uint8_t l_dimm_type = 0;
    FAPI_TRY(mss::attr::get_dimm_type(i_rank_info.get_dimm_target(), l_dimm_type));

    o_lr_dimm = (l_dimm_type == fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_LRDIMM);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Check VPD config for support of a given freq - PROC_P10 specialization
/// @param[in] i_target the target on which to operate
/// @param[in] i_proposed_freq frequency to check for support
/// @param[out] o_supported true if VPD supports the proposed frequency
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode check_freq_support_vpd<mss::proc_type::PROC_P10>( const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>&
        i_target,
        const uint64_t i_proposed_freq,
        bool& o_supported)
{
    using TT = mss::frequency_traits<mss::proc_type::PROC_P10>;
    o_supported = false;

    std::vector<mss::rank::info<>> l_ranks;
    fapi2::VPDInfo<TT::VPD_TARGET_TYPE> l_vpd_info(TT::VPD_BLOB);

    const auto& l_vpd_target = mss::find_target<TT::VPD_TARGET_TYPE>(i_target);
    uint32_t l_omi_freq = 0;

    l_vpd_info.iv_is_config_ffdc_enabled = false;

    FAPI_TRY(convert_ddr_freq_to_omi_freq(i_target, i_proposed_freq, l_omi_freq));
    l_vpd_info.iv_omi_freq_mhz = l_omi_freq;

    // DDIMM SPD can contain different SI settings for each master rank.
    // To determine which frequencies are supported, we have to check for each valid
    // master rank on the port's DIMMs
    FAPI_TRY(mss::rank::ranks_on_port(i_target, l_ranks));

    for (const auto& l_rank : l_ranks)
    {
        // We will skip LRDIMMs with ranks > 0
        bool l_is_lr_dimm = false;
        FAPI_TRY(rank_is_lr_dimm(l_rank, l_is_lr_dimm));

        if (rank_not_supported_in_vpd_config(l_is_lr_dimm, l_rank.get_dimm_rank()))
        {
            FAPI_DBG("LRDIMM ranks > 0 are not supported for check_freq_support_vpd. Skipping this rank. Target: %s",
                     mss::c_str(i_target));
            continue;
        }

        l_vpd_info.iv_rank = l_rank.get_phy_rank();

        // Check if this VPD configuration is supported
        FAPI_TRY(is_vpd_config_supported<mss::proc_type::PROC_P10>(l_vpd_target, i_proposed_freq, l_vpd_info, o_supported),
                 "%s failed to determine if %u freq is supported on rank %d", mss::c_str(i_target), i_proposed_freq, l_vpd_info.iv_rank);

        // If we fail any of the ranks, then this VPD configuration is not supported
        if(o_supported == false)
        {
            FAPI_INF("%s is not supported on rank %u exiting...", mss::c_str(i_target), l_rank.get_port_rank());
            break;
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Update supported frequency scoreboard according to processor limits - specialization for PROC_P10 and PROC_CHIP
/// @param[in] i_target processor frequency domain
/// @param[in,out] io_scoreboard scoreboard of port targets supporting each frequency
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode limit_freq_by_processor<mss::proc_type::PROC_P10>(
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
        const auto l_port_pos = mss::relative_pos<fapi2::TARGET_TYPE_PROC_CHIP>(l_port);

        std::vector<uint64_t> l_converted_omi_freqs;
        const std::vector<uint64_t> l_P10_OMI_FREQ_DD1{P10_OMI_FREQS[0]};

        // Check for DD1 OMI frequency limitation - if exists use 21330 MHz
        for (const auto l_omi_freq : (l_limited_omi_freq ? l_P10_OMI_FREQ_DD1 : P10_OMI_FREQS))
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

///
/// @brief Gets the number of master ranks on each DIMM - specialization for the PROC_P10 processor type
/// @param[in] i_target DIMM target
/// @param[out] o_master_ranks number of master ranks
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode num_master_ranks_per_dimm<mss::proc_type::PROC_P10>(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
    uint8_t& o_master_ranks)
{
    return mss::attr::get_num_master_ranks_per_dimm(i_target, o_master_ranks);
}

///
/// @brief Creates a bitmap of supported frequencies per port - specialization for the PROC_P10 processor type
/// @param[in] i_vpd_supported_freqs vector of hardware supported freqs
/// @param[out] o_supported_freq_bitmap array of bitmaps
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode freq_support_bitmap_helper<mss::proc_type::PROC_P10>(
    const std::vector<std::vector<uint32_t>>& i_vpd_supported_freqs,
    fapi2::buffer<uint8_t>
    (&o_supported_freq_bitmap)[mss::frequency_traits<mss::proc_type::PROC_P10>::PORTS_PER_FREQ_DOMAIN])
{
    using TT = mss::frequency_traits<mss::proc_type::PROC_P10>;

    for (size_t l_port = 0; l_port < TT::PORTS_PER_FREQ_DOMAIN; ++l_port)
    {
        // NOTE: the size of i_vpd_supported_freqs was checked in limit_freq_by_vpd
        // so we should not overrun it here
        for (const auto l_freq : i_vpd_supported_freqs[l_port])
        {
            // Set to the 'unknown freq' position (shouldn't occur, but just in case)
            uint8_t l_freq_bit = 7;

            switch (l_freq)
            {
                case TT::SUPPORTED_FREQ0:
                    l_freq_bit = 0;
                    break;

                case TT::SUPPORTED_FREQ1:
                    l_freq_bit = 1;
                    break;

                case TT::SUPPORTED_FREQ2:
                    l_freq_bit = 2;
                    break;

                default:
                    break;
            }

            FAPI_TRY(o_supported_freq_bitmap[l_port].setBit(l_freq_bit));
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Calls out the target if no DIMM frequencies are supported - specialization for PROC_P10 and MEM_PORT
/// @param[in] i_target target on which to operate
/// @param[in] i_supported_freq true if any FREQ's are supported
/// @param[in] i_num_ports number of configured ports
/// @param[in] i_vpd_supported_freqs vector of hardware supported freqs
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode callout_no_common_freq<mss::proc_type::PROC_P10>(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const bool i_supported_freq,
    const uint64_t i_num_ports,
    const std::vector<std::vector<uint32_t>>& i_vpd_supported_freqs)
{
    using TT = mss::frequency_traits<mss::proc_type::PROC_P10>;

    fapi2::buffer<uint8_t> l_supported_freq_bitmap[TT::PORTS_PER_FREQ_DOMAIN] = {0};
    uint32_t l_max_mrw_freqs[NUM_MAX_FREQS] = {0};
    FAPI_TRY( mss::attr::get_max_allowed_dimm_freq(l_max_mrw_freqs) );

    // Fill in a bitmap of supported freqs for each port in the domain
    FAPI_TRY(freq_support_bitmap_helper<mss::proc_type::PROC_P10>(i_vpd_supported_freqs, l_supported_freq_bitmap));

    FAPI_ASSERT(i_supported_freq,
                fapi2::P10_MSS_NO_SUPPORTED_FREQ()
                .set_FREQ_DOMAIN_TARGET(i_target)
                .set_MRW_MAX_FREQ_0(l_max_mrw_freqs[0])
                .set_MRW_MAX_FREQ_1(l_max_mrw_freqs[1])
                .set_MRW_MAX_FREQ_2(l_max_mrw_freqs[2])
                .set_MRW_MAX_FREQ_3(l_max_mrw_freqs[3])
                .set_MRW_MAX_FREQ_4(l_max_mrw_freqs[4])
                .set_PORT0_FREQ_SUPPORT(l_supported_freq_bitmap[0])
                .set_PORT1_FREQ_SUPPORT(l_supported_freq_bitmap[1])
                .set_PORT2_FREQ_SUPPORT(l_supported_freq_bitmap[2])
                .set_PORT3_FREQ_SUPPORT(l_supported_freq_bitmap[3])
                .set_PORT4_FREQ_SUPPORT(l_supported_freq_bitmap[4])
                .set_PORT5_FREQ_SUPPORT(l_supported_freq_bitmap[5])
                .set_PORT6_FREQ_SUPPORT(l_supported_freq_bitmap[6])
                .set_PORT7_FREQ_SUPPORT(l_supported_freq_bitmap[7])
                .set_PORT8_FREQ_SUPPORT(l_supported_freq_bitmap[8])
                .set_PORT9_FREQ_SUPPORT(l_supported_freq_bitmap[9])
                .set_PORT10_FREQ_SUPPORT(l_supported_freq_bitmap[10])
                .set_PORT11_FREQ_SUPPORT(l_supported_freq_bitmap[11])
                .set_PORT12_FREQ_SUPPORT(l_supported_freq_bitmap[12])
                .set_PORT13_FREQ_SUPPORT(l_supported_freq_bitmap[13])
                .set_PORT14_FREQ_SUPPORT(l_supported_freq_bitmap[14])
                .set_PORT15_FREQ_SUPPORT(l_supported_freq_bitmap[15]),
                "%s didn't find a frequency that was supported on any ports. Freq support bitmap: "
                "port0:0x%02X port1:0x%02X port2:0x%02X port3:0x%02X port4:0x%02X "
                "port5:0x%02X port6:0x%02X port7:0x%02X port8:0x%02X port9:0x%02X "
                "port10:0x%02X port11:0x%02X port12:0x%02X port13:0x%02X port14:0x%02X port15:0x%02X",
                mss::c_str(i_target), l_supported_freq_bitmap[0], l_supported_freq_bitmap[1],
                l_supported_freq_bitmap[2], l_supported_freq_bitmap[3], l_supported_freq_bitmap[4],
                l_supported_freq_bitmap[5], l_supported_freq_bitmap[6], l_supported_freq_bitmap[7],
                l_supported_freq_bitmap[8], l_supported_freq_bitmap[9], l_supported_freq_bitmap[10],
                l_supported_freq_bitmap[11], l_supported_freq_bitmap[12], l_supported_freq_bitmap[13],
                l_supported_freq_bitmap[14], l_supported_freq_bitmap[15]);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Calls out the target if no DIMM frequencies are supported - specialization for PROC_P10 and MEM_PORT
/// @param[in] i_target target on which to operate
/// @param[in] i_vpd_supported_freqs VPD supported frequencies for the callout
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode callout_max_freq_empty_set<mss::proc_type::PROC_P10>(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const std::vector<std::vector<uint32_t>>& i_vpd_supported_freqs)
{

    std::vector<uint32_t> l_port_vpd_max_freq;

    // Get the max freq supported on each port
    for ( const auto& l_port_supported_freqs : i_vpd_supported_freqs )
    {
        l_port_vpd_max_freq.push_back(l_port_supported_freqs.back());
    }

    uint32_t l_max_mrw_freqs[NUM_MAX_FREQS] = {0};
    FAPI_TRY( mss::attr::get_max_allowed_dimm_freq(l_max_mrw_freqs) );

    for (const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
    {
        FAPI_ASSERT_NOEXIT(false,
                           fapi2::P10_MSS_MRW_FREQ_MAX_FREQ_EMPTY_SET()
                           .set_MSS_VPD_FREQ_0(l_port_vpd_max_freq[0])
                           .set_MSS_VPD_FREQ_1(l_port_vpd_max_freq[1])
                           .set_MSS_VPD_FREQ_2(l_port_vpd_max_freq[2])
                           .set_MSS_MAX_FREQ_0(l_max_mrw_freqs[0])
                           .set_MSS_MAX_FREQ_1(l_max_mrw_freqs[1])
                           .set_MSS_MAX_FREQ_2(l_max_mrw_freqs[2])
                           .set_MSS_MAX_FREQ_3(l_max_mrw_freqs[3])
                           .set_MSS_MAX_FREQ_4(l_max_mrw_freqs[4])
                           .set_OMI_FREQ_0(fapi2::ENUM_ATTR_FREQ_OMI_MHZ_21330)
                           .set_OMI_FREQ_1(fapi2::ENUM_ATTR_FREQ_OMI_MHZ_23460)
                           .set_OMI_FREQ_2(fapi2::ENUM_ATTR_FREQ_OMI_MHZ_25600)
                           .set_PORT_TARGET(l_port),
                           "%s didn't find a supported frequency for any ports in this domain", mss::c_str(l_port));
    }

    return fapi2::RC_P10_MSS_MRW_FREQ_MAX_FREQ_EMPTY_SET;

fapi_try_exit:
    return fapi2::current_err;
}
namespace check
{

///
/// @brief Checks the final frequency for the system type - PROC_P10 and PROC_CHIP specialization
/// @param[in] i_target the target on which to operate
/// @return FAPI2_RC_SUCCESS iff okay
/// @note This function was needed in Nimbus to enforce a frequency limit due to a hardware limitation
///       and is not needed here.
///
template<>
fapi2::ReturnCode final_freq<mss::proc_type::PROC_P10>(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    return fapi2::FAPI2_RC_SUCCESS;
}

} // ns check

} // ns mss
