/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/freq/sync.H $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file synch.H
/// @brief Synchronous function implementations
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_SYNC_H_
#define _MSS_SYNC_H_

#include <map>
#include <vector>

#include <fapi2.H>

namespace mss
{

enum class speed_equality : uint8_t
{
    NOT_EQUAL_DIMM_SPEEDS = 0,
    EQUAL_DIMM_SPEEDS = 1,
};

///
/// @brief Checks to see if a passed in value could be a valid nest frequency
/// @param[in] i_proposed_freq a frequency value that is to be checked
/// @return boolean true, false whether the value is a valid nest frequency
///
inline bool is_nest_freq_valid (const uint64_t i_proposed_freq)
{
    std::vector<uint64_t> l_nest_freqs_supported = { fapi2::ENUM_ATTR_FREQ_PB_MHZ_1600,
                                                     fapi2::ENUM_ATTR_FREQ_PB_MHZ_1866,
                                                     fapi2::ENUM_ATTR_FREQ_PB_MHZ_2000,
                                                     fapi2::ENUM_ATTR_FREQ_PB_MHZ_2133,
                                                     fapi2::ENUM_ATTR_FREQ_PB_MHZ_2400
                                                   };
    std::sort(l_nest_freqs_supported.begin(), l_nest_freqs_supported.end());

    return ( std::binary_search(l_nest_freqs_supported.begin(), l_nest_freqs_supported.end(), i_proposed_freq) );
}

///
/// @brief Retrieves a mapping of MSS frequency values per mcbist target
/// @param[in] i_targets vector of controller targets
/// @param[out] o_freq_map dimm speed map <key, value> = (mcbist target, frequency)
/// @param[out] o_is_speed_equal holds whether map dimm speed is equal
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode dimm_speed_map(const std::vector< fapi2::Target<fapi2::TARGET_TYPE_MCBIST> >& i_targets,
                                 std::map< fapi2::Target<fapi2::TARGET_TYPE_MCBIST>, uint64_t >& o_freq_map,
                                 speed_equality& o_is_speed_equal);

///
/// @brief Helper function to deconfigure MCS targets connected to MCBIST
/// @param[in] i_target the controller target
/// @param[in] i_dimm_speed dimm speed in MT/s
/// @param[in] i_nest_freq nest freq in MHz
/// @return true if hardware was deconfigured
///
bool deconfigure(const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
                 const uint64_t i_dimm_speed,
                 const uint32_t i_nest_freq);

///
/// @brief Selects synchronous mode and performs requirements enforced by ATTR_REQUIRED_SYNCH_MODE
/// @param[in] i_freq_map dimm speed mapping
/// @param[in] i_equal_dimm_speed tracks whether map has equal dimm speeds
/// @param[in] i_nest_freq nest frequency
/// @param[in] i_required_sync_mode system policy to enforce synchronous mode
/// @param[out] o_selected_sync_mode final synchronous mode
/// @param[out] o_selected_freq final freq selected, only valid if final sync mode is in-sync
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode select_sync_mode(const std::map< fapi2::Target<fapi2::TARGET_TYPE_MCBIST>, uint64_t >& i_freq_map,
                                   const speed_equality i_equal_dimm_speed,
                                   const uint32_t i_nest_freq,
                                   const uint8_t i_required_sync_mode,
                                   uint8_t& o_selected_sync_mode,
                                   uint64_t& o_selected_freq);

///
/// @brief Create and sort a vector of supported MT/s (freq) - helper for testing purposes
/// @param[in] MCA target for which to get the DIMM configs
/// @param[in] vector of MVPD freqs
/// @param[in] vector of max allowed freqs
/// @param[in] bool whether or not we're forced into sync mode
/// @param[out] reference to a std::vector<uint32_t> space to put the sorted vector
/// @return FAPI2_RC_SUCCESS iff ok
/// @note Taken from ATTR_MSS_MRW_SUPPORTED_FREQ. The result is sorted so such that the min
/// supported freq is std::vector<>.begin and the max is std::vector<>.end - 1. You can
/// search the resulting vector for valid frequencies as it is sorted.
///
fapi2::ReturnCode supported_freqs_helper(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const std::vector<uint32_t>& i_freqs,
        const std::vector<uint32_t>& i_max_freqs,
        const bool i_req_sync_mode,
        std::vector<uint32_t>& o_freqs);

///
/// @brief Create and sort a vector of supported MT/s (freq)
/// @param[in] MCA target for which to get the DIMM configs
/// @param[out] reference to a std::vector<uint32_t> space to put the sorted vector
/// @return FAPI2_RC_SUCCESS iff ok
/// @note Taken from ATTR_MSS_MRW_SUPPORTED_FREQ. The result is sorted so such that the min
/// supported freq is std::vector<>.begin and the max is std::vector<>.end - 1. You can
/// search the resulting vector for valid frequencies as it is sorted.
///
fapi2::ReturnCode supported_freqs(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
                                  std::vector<uint32_t>& o_freqs);

///
/// @brief Return whether a given freq is supported
/// @param[in] a freq to check for
/// @param[in] reference to a std::vector<uint32_t> of freqs
/// @return bool, true iff input freq is supported
///
bool is_freq_supported(const uint32_t i_freq, const std::vector<uint32_t>& i_freqs);

///
/// @brief          Selects DIMM frequency to run based on supported system frequencies
/// @tparam         T the fapi2::TargetType for which the DIMM information exists.
/// @param[in]      target from which to get the dimm information
/// @param[in,out]  io_dimm_freq input is current dimm freq & output is next
///                 lowest dimm freq between 1866 MT/s (-5% margin)  - 2666 MT/s (+5% margin)
/// @return         FAPI2_RC_SUCCESS iff ok
/// @note           Frequency values obtained from:
/// @note           From P9 User's Manual Version 0.8 - June 08, 2015
/// @note           Memory Controller Unit - page 199 of 456
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode select_supported_freq(const fapi2::Target<T>& i_target, uint64_t& io_dimm_freq)
{
    std::vector<uint32_t> l_freqs;

    FAPI_TRY( mss::supported_freqs(i_target, l_freqs) );

    {
        // supported_freqs sorts so upper_bound is valid.
        auto iterator = std::upper_bound(l_freqs.begin(), l_freqs.end(), io_dimm_freq);

        auto l_supported = l_freqs.begin();

        // Doing this because the HB compiler freaks out if we have it within the FAPI_ASSERT.
        // Outputting the value and then incrementing the iterator, that's why it's a post increment
        const auto l_0 = (l_supported != l_freqs.end()) ? *(l_supported++) : 0;
        const auto l_1 = (l_supported != l_freqs.end()) ? *(l_supported++) : 0;
        const auto l_2 = (l_supported != l_freqs.end()) ? *(l_supported++) : 0;
        const auto l_3 = (l_supported != l_freqs.end()) ? *(l_supported++) : 0;

        FAPI_ASSERT( (iterator != l_freqs.begin() && l_freqs.size() != 0),
                     fapi2::MSS_SELECTED_FREQ_NOT_SUPPORTED()
                     .set_FREQ(io_dimm_freq)
                     .set_SUPPORTED_FREQ_0( l_0 )
                     .set_SUPPORTED_FREQ_1( l_1 )
                     .set_SUPPORTED_FREQ_2( l_2 )
                     .set_SUPPORTED_FREQ_3( l_3 )
                     .set_TARGET(i_target),
                     "%s Error finding selected freq (%d) from list",
                     mss::c_str(i_target),
                     io_dimm_freq );
        // Upper bound checks just greater than, not equals. Return one up
        io_dimm_freq = *(--iterator);
    }

fapi_try_exit:
    return fapi2::current_err;
}

}// mss

#endif
