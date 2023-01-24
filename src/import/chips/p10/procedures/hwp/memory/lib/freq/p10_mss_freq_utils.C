/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/freq/p10_mss_freq_utils.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2023                        */
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
#include <lib/dimm/exp_rank.H>

// Odyssey rank API
#include <lib/dimm/ody_rank.H>

// Memory libraries
#include <lib/freq/p10_mss_freq_utils.H>
#include <lib/freq/p10_freq_traits.H>
#include <lib/shared/p10_consts.H>
#include <lib/freq/p10_sync.H>
#include <lib/eff_config/p10_spd_utils.H>

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
    mss::DIMM_SPEED_2666, // DDR4 ONLY
    mss::DIMM_SPEED_2933, // DDR4 ONLY
    mss::DIMM_SPEED_3200, // DDR4 max + DDR5 min
    mss::DIMM_SPEED_4000, // DDR5 ONLY -> p10's OMI limit is 32.0, so 4000 for DDR
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
    const auto FREQ3 = TT::SUPPORTED_FREQ3;

    // If we don't find a valid frequency OR don't get a 0 (nothing configured on this clock domain), then error out
    FAPI_ASSERT( std::binary_search(TT::SUPPORTED_FREQS.begin(), TT::SUPPORTED_FREQS.end(), i_final_freq) ||
                 i_final_freq == 0,
                 fapi2::P10_MSS_BAD_FREQ_CALCULATED()
                 .set_MSS_FREQ(i_final_freq)
                 .set_TARGET(i_target)
                 .set_PROC_TYPE(mss::proc_type::PROC_P10)
                 .set_SUPPORTED_FREQ_0(FREQ0)
                 .set_SUPPORTED_FREQ_1(FREQ1)
                 .set_SUPPORTED_FREQ_2(FREQ2)
                 .set_SUPPORTED_FREQ_3(FREQ3),
                 "%s: Calculated FREQ (%d) isn't supported",
                 mss::c_str(i_target),
                 i_final_freq);

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines if a DIMM is an LR dimm
/// @param[in] i_target the DIMM target on which to operate
/// @param[out] o_is_lr_dimm true if LRDIMM, else false
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success
///
// TODO Zen:MST-1901 Move this function to generic_attribute_accessors_manual.H for general use
fapi2::ReturnCode is_lr_dimm(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target, bool& o_is_lr_dimm)
{
    uint8_t l_dimm_type = 0;
    FAPI_TRY(mss::attr::get_dimm_type(i_target, l_dimm_type));

    o_is_lr_dimm = (l_dimm_type == fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_LRDIMM);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Check VPD config for support of a given freq - EXPLORER, PROC_P10 specialization
/// @param[in] i_target the target on which to operate
/// @param[in] i_proposed_freq frequency to check for support
/// @param[out] o_is_supported true if VPD supports the proposed frequency
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode check_freq_support_vpd<mss::mc_type::EXPLORER, mss::proc_type::PROC_P10>(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
    const uint64_t i_proposed_freq,
    bool& o_is_supported)
{
    FAPI_TRY(mss::check_freq_support_vpd_p10<mss::mc_type::EXPLORER>(i_target, i_proposed_freq, o_is_supported));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Check VPD config for support of a given freq - ODYSSEY, PROC_P10 specialization
/// @param[in] i_target the target on which to operate
/// @param[in] i_proposed_freq frequency to check for support
/// @param[out] o_is_supported true if VPD supports the proposed frequency
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode check_freq_support_vpd<mss::mc_type::ODYSSEY, mss::proc_type::PROC_P10>(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
    const uint64_t i_proposed_freq,
    bool& o_is_supported)
{
    FAPI_TRY(mss::check_freq_support_vpd_p10<mss::mc_type::ODYSSEY>(i_target, i_proposed_freq, o_is_supported));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Update supported frequency scoreboard according to processor limits - specialization for EXPLORER, PROC_P10, and PROC_CHIP
/// @param[in] i_target processor frequency domain
/// @param[in,out] io_scoreboard scoreboard of port targets supporting each frequency
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode limit_freq_by_processor<mss::mc_type::EXPLORER, mss::proc_type::PROC_P10>(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    freq_scoreboard& io_scoreboard)
{
    FAPI_TRY(limit_freq_by_processor_p10<mss::mc_type::EXPLORER>(i_target, io_scoreboard));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Update supported frequency scoreboard according to processor limits - specialization for ODYSSEY, PROC_P10, and PROC_CHIP
/// @param[in] i_target processor frequency domain
/// @param[in,out] io_scoreboard scoreboard of port targets supporting each frequency
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode limit_freq_by_processor<mss::mc_type::ODYSSEY, mss::proc_type::PROC_P10>(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    freq_scoreboard& io_scoreboard)
{
    FAPI_TRY(limit_freq_by_processor_p10<mss::mc_type::ODYSSEY>(i_target, io_scoreboard));

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

                case TT::SUPPORTED_FREQ3:
                    l_freq_bit = 3;
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
                .set_PORT15_FREQ_SUPPORT(l_supported_freq_bitmap[15])
                .set_PORT16_FREQ_SUPPORT(l_supported_freq_bitmap[16])
                .set_PORT17_FREQ_SUPPORT(l_supported_freq_bitmap[17])
                .set_PORT18_FREQ_SUPPORT(l_supported_freq_bitmap[18])
                .set_PORT19_FREQ_SUPPORT(l_supported_freq_bitmap[19])
                .set_PORT20_FREQ_SUPPORT(l_supported_freq_bitmap[20])
                .set_PORT21_FREQ_SUPPORT(l_supported_freq_bitmap[21])
                .set_PORT22_FREQ_SUPPORT(l_supported_freq_bitmap[22])
                .set_PORT23_FREQ_SUPPORT(l_supported_freq_bitmap[23])
                .set_PORT24_FREQ_SUPPORT(l_supported_freq_bitmap[24])
                .set_PORT25_FREQ_SUPPORT(l_supported_freq_bitmap[25])
                .set_PORT26_FREQ_SUPPORT(l_supported_freq_bitmap[26])
                .set_PORT27_FREQ_SUPPORT(l_supported_freq_bitmap[27])
                .set_PORT28_FREQ_SUPPORT(l_supported_freq_bitmap[28])
                .set_PORT29_FREQ_SUPPORT(l_supported_freq_bitmap[29])
                .set_PORT30_FREQ_SUPPORT(l_supported_freq_bitmap[30])
                .set_PORT31_FREQ_SUPPORT(l_supported_freq_bitmap[31]),
                "%s didn't find a frequency that was supported on any ports. Freq support bitmap: "
                "port 0- 3:0x%02X 0x%02X 0x%02X 0x%02X "
                "port 4- 7:0x%02X 0x%02X 0x%02X 0x%02X "
                "port 8-11:0x%02X 0x%02X 0x%02X 0x%02X "
                "port12-15:0x%02X 0x%02X 0x%02X 0x%02X "
                "port16-19:0x%02X 0x%02X 0x%02X 0x%02X "
                "port20-23:0x%02X 0x%02X 0x%02X 0x%02X "
                "port24-27:0x%02X 0x%02X 0x%02X 0x%02X "
                "port28-31:0x%02X 0x%02X 0x%02X 0x%02X",
                mss::c_str(i_target), l_supported_freq_bitmap[0], l_supported_freq_bitmap[1],
                l_supported_freq_bitmap[2], l_supported_freq_bitmap[3], l_supported_freq_bitmap[4],
                l_supported_freq_bitmap[5], l_supported_freq_bitmap[6], l_supported_freq_bitmap[7],
                l_supported_freq_bitmap[8], l_supported_freq_bitmap[9], l_supported_freq_bitmap[10],
                l_supported_freq_bitmap[11], l_supported_freq_bitmap[12], l_supported_freq_bitmap[13],
                l_supported_freq_bitmap[14], l_supported_freq_bitmap[15], l_supported_freq_bitmap[16],
                l_supported_freq_bitmap[17], l_supported_freq_bitmap[18], l_supported_freq_bitmap[19],
                l_supported_freq_bitmap[20], l_supported_freq_bitmap[21], l_supported_freq_bitmap[22],
                l_supported_freq_bitmap[23], l_supported_freq_bitmap[24], l_supported_freq_bitmap[25],
                l_supported_freq_bitmap[26], l_supported_freq_bitmap[27], l_supported_freq_bitmap[28],
                l_supported_freq_bitmap[29], l_supported_freq_bitmap[30], l_supported_freq_bitmap[31]);

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
                           .set_OMI_FREQ_3(fapi2::ENUM_ATTR_FREQ_OMI_MHZ_32000)
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
