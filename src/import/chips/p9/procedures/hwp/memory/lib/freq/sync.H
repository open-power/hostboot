/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/freq/sync.H $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2018                        */
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
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_SYNC_H_
#define _MSS_SYNC_H_

#include <map>
#include <vector>

#include <fapi2.H>
#include <lib/shared/mss_const.H>
#include <generic/memory/lib/utils/freq/mss_freq_scoreboard.H>
#include <generic/memory/lib/utils/c_str.H>

namespace mss
{

// List of the nest frequencies for nimbus
// Note: these need to be sorted so binary search works
static const std::vector<uint64_t> NIMBUS_NEST_FREQS =
{
    fapi2::ENUM_ATTR_FREQ_PB_MHZ_1600,
    fapi2::ENUM_ATTR_FREQ_PB_MHZ_1866,
    fapi2::ENUM_ATTR_FREQ_PB_MHZ_2000,
    fapi2::ENUM_ATTR_FREQ_PB_MHZ_2133,
    fapi2::ENUM_ATTR_FREQ_PB_MHZ_2400
};

///
/// @brief Checks to see if a passed in value could be a valid nest frequency
/// @param[in] i_proposed_freq a frequency value that is to be checked
/// @return boolean true, false whether the value is a valid nest frequency
///
inline bool is_nest_freq_valid (const uint64_t i_proposed_freq)
{
    return ( std::binary_search(NIMBUS_NEST_FREQS.begin(), NIMBUS_NEST_FREQS.end(), i_proposed_freq) );
}

enum class speed_equality : uint8_t
{
    NOT_EQUAL_DIMM_SPEEDS = 0, ///< denotes all DIMMs don't have the same speed
    EQUAL_DIMM_SPEEDS = 1, ///< denotes all DIMMs have the same speed
};

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
/// @brief Update supported frequency scoreboard according to whether the processor is in sync mode or not
/// @param[in] i_target processor frequency domain
/// @param[in,out] io_scoreboard scoreboard of port targets supporting each frequency
/// @return FAPI2_RC_SUCCESS iff ok
/// @note the attributes which drive this are read-only so they're hard to change when
/// testing. So this helper allows us to use the attributes for the main path but
/// have a path for testing
///
inline fapi2::ReturnCode limit_freq_by_processor(const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
        const bool i_sync_mode,
        freq_scoreboard& io_scoreboard)
{
    // If we're not in sync mode, just exit
    if(!i_sync_mode)
    {
        FAPI_INF("%s is not in sync mode, skipping the sync mode check", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Loop through all potential ports
    for(uint64_t l_port_pos = 0; l_port_pos < PORTS_PER_MCBIST; ++l_port_pos)
    {
        FAPI_TRY(io_scoreboard.remove_freqs_not_on_list(l_port_pos, NIMBUS_NEST_FREQS));
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

}// mss

#endif
