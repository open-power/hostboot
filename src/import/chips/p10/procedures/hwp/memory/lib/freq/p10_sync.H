/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/freq/p10_sync.H $ */
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
/// @file p10_sync.H
/// @brief Synchronous function implementations for P10
///
/// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
/// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 3
/// *HWP Consumed by: HB:FSP

#ifndef _P10_MSS_SYNC_H_
#define _P10_MSS_SYNC_H_

#include <map>
#include <vector>

#include <fapi2.H>
#include <mss_generic_attribute_getters.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <lib/shared/p10_consts.H>
#include <lib/freq/p10_freq_traits.H>
#include <generic/memory/lib/utils/freq/mss_freq_scoreboard.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/mss_math.H>

namespace mss
{

// List of the OMI frequencies for P10 newer than DD1
// Note: these need to be sorted so binary search works
static const std::vector<uint64_t> P10_OMI_FREQS =
{
    21330, // fapi2::ENUM_ATTR_FREQ_OMI_MHZ_21330,
    23460, // fapi2::ENUM_ATTR_FREQ_OMI_MHZ_23460,
    25600, // fapi2::ENUM_ATTR_FREQ_OMI_MHZ_25600,
    32000, // fapi2::ENUM_ATTR_FREQ_OMI_MHZ_32000,
};

// List of the OMI frequencies for P10 DD1
// Note: these need to be sorted so binary search works
static const std::vector<uint64_t> P10_LIMITED_OMI_FREQS =
{
    21330, // fapi2::ENUM_ATTR_FREQ_OMI_MHZ_21330,
};

///
/// @brief determines if rank is not supported in VPD config, will be skipped in check_freq_support_vpd()
///
/// @param[in] i_is_lr_dimm is LR
/// @param[in] i_dimm_rank DIMM rank
/// @return true if LR & rank > 0, else false
///
inline bool rank_not_supported_in_vpd_config(const bool i_is_lr_dimm, const uint8_t i_dimm_rank)
{
    return (i_is_lr_dimm && i_dimm_rank > 0);
}

///
/// @brief Converts a DDR frequency to the corresponding OMI frequency
/// @param[in] i_target the port target
/// @param[in] i_ddr_freq a frequency value that is to be converted
/// @param[out] o_omi_freq the corresponding OMI frequency
/// @return FAPI2_RC_SUCCESS iff successful
///
inline fapi2::ReturnCode convert_ddr_freq_to_omi_freq(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const uint64_t i_ddr_freq,
        uint32_t& o_omi_freq)
{
    using TT = mss::frequency_traits<mss::proc_type::PROC_P10>;
    constexpr uint64_t ROUND_UNITS = 10;
    uint64_t l_omi_freq = 0;

    // Get the OMI to DDR freq ratio
    uint8_t l_ratio[TT::MAX_DIMM_PER_PORT] = {0};
    FAPI_TRY(mss::attr::get_host_to_ddr_speed_ratio(i_target, l_ratio));

    // Multiply by the ratio and round to the nearest 10GBPS
    FAPI_TRY(mss::divide_and_round((i_ddr_freq * l_ratio[0]), ROUND_UNITS, mss::generic_ffdc_codes::DDR_TO_OMI_FREQ,
                                   l_omi_freq));
    o_omi_freq = ROUND_UNITS * l_omi_freq;
    FAPI_DBG("For ratio %d and DDR freq %d, corresponding OMI freq is %d", l_ratio[0], i_ddr_freq, o_omi_freq);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Converts an OMI frequency to the corresponding DDR frequency
/// @param[in] i_target the port target
/// @param[in] i_omi_freq a frequency value that is to be converted
/// @param[out] o_ddr_freq the corresponding DDR frequency
/// @return FAPI2_RC_SUCCESS iff successful
///
inline fapi2::ReturnCode convert_omi_freq_to_ddr_freq(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const uint32_t i_omi_freq,
        uint64_t& o_ddr_freq)
{
    using TT = mss::frequency_traits<mss::proc_type::PROC_P10>;

    // Get the OMI to DDR freq ratio
    uint8_t l_ratio[TT::MAX_DIMM_PER_PORT] = {0};
    FAPI_TRY(mss::attr::get_host_to_ddr_speed_ratio(i_target, l_ratio));

    FAPI_TRY(mss::divide_and_round(static_cast<uint64_t>(i_omi_freq), static_cast<uint64_t>(l_ratio[0]),
                                   mss::generic_ffdc_codes::OMI_TO_DDR_FREQ, o_ddr_freq),
             "%s freq system saw a zero Host (OMI) to DDR frequency ratio", mss::c_str(i_target));
    FAPI_DBG( "For ratio %d and OMI freq %d, corresponding DDR freq is %d", l_ratio[0], i_omi_freq, o_ddr_freq);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Retrieves a mapping of MSS frequency values per port target
/// @param[in] i_targets vector of port targets
/// @param[out] o_freq_map dimm speed map <key, value> = (port target, frequency)
/// @param[out] o_is_speed_equal holds whether map dimm speed is equal
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode dimm_speed_map(const std::vector< fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> >& i_targets,
                                 std::map< fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>, uint64_t >& o_freq_map,
                                 speed_equality& o_is_speed_equal);

///
/// @brief Helper function to deconfigure MEM_PORT target
/// @param[in] i_target the port target
/// @param[in] i_dimm_speed dimm speed in MT/s
/// @param[in] i_omi_freq OMI freq in MHz
/// @return true if hardware was deconfigured
///
bool deconfigure(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                 const uint64_t i_dimm_speed,
                 const uint64_t i_omi_freq);

///
/// @brief Selects OMI frequency based on selected port frequencies
/// @param[in] i_freq_map dimm speed mapping
/// @param[in] i_equal_dimm_speed tracks whether map has equal dimm speeds
/// @param[in] i_omi_freq OMI frequency
/// @param[out] o_selected_omi_freq final freq selected
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode select_omi_freq(const std::map< fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>, uint64_t >& i_freq_map,
                                  const speed_equality i_equal_dimm_speed,
                                  const uint32_t i_omi_freq,
                                  uint32_t& o_selected_omi_freq);


///
/// @brief Set system freq attributes based on selected OMI frequency
/// @param[in] i_target proc chip target
/// @param[in] i_omi_freq OMI frequency
/// @return FAPI2_RC_SUCCESS iff successful
/// @note i_omi_freq cannot be const due to FAPI_ATTR_SET not allowing const
///
fapi2::ReturnCode set_freq_system_attrs(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                                        uint32_t i_omi_freq);
}// mss

#endif
