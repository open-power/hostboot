/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/freq/p10_sync.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
/// *HWP HW Maintainer: Louis Stermole <stermole@us.ibm.com>
/// *HWP FW Maintainer: Christian Geddes <crgeddes@us.ibm.com>
/// *HWP Consumed by: HB

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

// List of the OMI frequencies for P10
// Note: these need to be sorted so binary search works
static const std::vector<uint64_t> P10_OMI_FREQS =
{
    21330, // fapi2::ENUM_ATTR_MSS_OCMB_EXP_BOOT_CONFIG_SERDES_FREQUENCY_SERDES_21_33GBPS,
    23460, // fapi2::ENUM_ATTR_MSS_OCMB_EXP_BOOT_CONFIG_SERDES_FREQUENCY_SERDES_23_46GBPS,
    25600, // fapi2::ENUM_ATTR_MSS_OCMB_EXP_BOOT_CONFIG_SERDES_FREQUENCY_SERDES_25_60GBPS,
};

///
/// @brief Converts an OMI frequency attribute enum to the corresponding OMI frequency
/// @param[in] i_omi_enum a frequency enum value that is to be converted
/// @return the corresponding OMI frequency
///
inline uint64_t convert_omi_freq_attr_to_freq(const fapi2::ATTR_MSS_OCMB_EXP_BOOT_CONFIG_SERDES_FREQUENCY_Type
        i_omi_enum)
{
    switch (i_omi_enum)
    {
        case fapi2::ENUM_ATTR_MSS_OCMB_EXP_BOOT_CONFIG_SERDES_FREQUENCY_SERDES_21_33GBPS:
            return 21330;

        case fapi2::ENUM_ATTR_MSS_OCMB_EXP_BOOT_CONFIG_SERDES_FREQUENCY_SERDES_23_46GBPS:
            return 23460;

        case fapi2::ENUM_ATTR_MSS_OCMB_EXP_BOOT_CONFIG_SERDES_FREQUENCY_SERDES_25_60GBPS:
            return 25600;

        default:
            FAPI_ASSERT( false,
                         fapi2::P10_MSS_UNSUPPORTED_OMI_FREQ()
                         .set_OMI_FREQ_ENUM(i_omi_enum),
                         "freq system saw an unsupported OMI frequency with enum value: %d",
                         i_omi_enum );
    }

fapi_try_exit:
    return 0;
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
    using TT = mss::frequency_traits<mss::proc_type::P10>;
    constexpr uint64_t ROUND_UNITS = 10;
    uint64_t l_omi_freq = 0;

    // Get the OMI to DDR freq ratio
    uint8_t l_ratio[TT::MAX_DIMM_PER_PORT] = {0};
    FAPI_TRY(mss::attr::get_host_to_ddr_speed_ratio(i_target, l_ratio));

    // Multiply by the ratio and round to the nearest 10GBPS
    FAPI_TRY(mss::divide_and_round((i_ddr_freq * l_ratio[0]), ROUND_UNITS, l_omi_freq));
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
    using TT = mss::frequency_traits<mss::proc_type::P10>;

    // Get the OMI to DDR freq ratio
    uint8_t l_ratio[TT::MAX_DIMM_PER_PORT] = {0};
    FAPI_TRY(mss::attr::get_host_to_ddr_speed_ratio(i_target, l_ratio));

    FAPI_TRY(mss::divide_and_round(static_cast<uint64_t>(i_omi_freq), static_cast<uint64_t>(l_ratio[0]), o_ddr_freq),
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

}// mss

#endif
