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

namespace mss
{

enum class speed_equality : uint8_t
{
    NOT_EQUAL_DIMM_SPEEDS = 0, ///< denotes all DIMMs don't have the same speed
    EQUAL_DIMM_SPEEDS = 1, ///< denotes all DIMMs have the same speed
};

// DDR4 speed NIMBUS supports
static const std::vector<uint32_t> NIMBUS_SUPPORTED_FREQS =
{
    fapi2::ENUM_ATTR_MSS_FREQ_MT1866,
    fapi2::ENUM_ATTR_MSS_FREQ_MT2133,
    fapi2::ENUM_ATTR_MSS_FREQ_MT2400,
    fapi2::ENUM_ATTR_MSS_FREQ_MT2666,
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
/// @class freq_scoreboard
/// @brief class that encapsulates MCA supported frequencies
///
class freq_scoreboard
{
    public:
        ///
        /// @brief Create a new frequency scoreboard
        ///
        freq_scoreboard()
        {
            iv_freq_mca_supported = std::vector<std::vector<bool>>(PORTS_PER_MCBIST,
                                    std::vector<bool>(NIMBUS_SUPPORTED_FREQS.size(), true));
        }

        ///
        /// @brief default destructor
        ///
        ~freq_scoreboard() = default;

        ///
        /// @brief Remove frequencies above a limit from the scoreboard
        /// @param[in] i_port_pos position index of port within parent MCBIST
        /// @param[in] i_freq_limit upper limit for frequency
        /// @return FAPI2_RC_SUCCESS if successful
        ///
        fapi2::ReturnCode remove_freqs_above_limit(const uint64_t i_port_pos,
                const uint32_t i_freq_limit);

        ///
        /// @brief Remove frequencies above a limit from the scoreboard
        /// @param[in] i_port_pos position index of port within parent MCBIST
        /// @param[in] i_freq_limits reference to vector of upper limits for frequency per port
        /// @return FAPI2_RC_SUCCESS if successful
        ///
        fapi2::ReturnCode remove_freqs_above_limit(const uint64_t i_port_pos,
                const std::vector<uint32_t> i_freq_limits);

        ///
        /// @brief Remove frequencies not on a given list from the scoreboard
        /// @param[in] i_port_pos position index of port within parent MCBIST
        /// @param[in] i_freq_list vector of supported frequencies
        /// @return FAPI2_RC_SUCCESS if successful
        ///
        fapi2::ReturnCode remove_freqs_not_on_list(const uint64_t i_port_pos,
                const std::vector<uint32_t>& i_freq_list);

        ///
        /// @brief Return the maximum supported frequency for a given port
        /// @param[in] i_port_pos position index of port within parent MCBIST
        /// @param[out] o_freq max supported frequency
        /// @return FAPI2_RC_SUCCESS if successful
        ///
        fapi2::ReturnCode max_supported_freq(const uint64_t i_port_pos,
                                             uint32_t& o_freq) const;

        ///
        /// @brief Return a list of supported frequencies for a given port
        /// @param[in] i_port_pos position index of port within parent MCBIST
        /// @param[out] o_freq vector of supported frequencies
        /// @return FAPI2_RC_SUCCESS if successful
        ///
        fapi2::ReturnCode supported_freqs(const uint64_t i_port_pos,
                                          std::vector<uint32_t>& o_freqs) const;

        ///
        /// @brief Resolve frequency scoreboard by deconfiguring any non-conforming ports
        /// and return a list of the supported frequencies
        /// @param[in] i_target MCBIST target
        /// @param[in] i_req_sync_mode bool whether or not we're forced into sync mode
        /// @param[in] i_vpd_supported_freqs vector of hardware supported freqs -- from VPD
        /// @param[out] o_deconfigured vector of port positions that were deconfigured by this function
        /// @param[out] o_freqs vector of frequencies supported by all ports
        /// @return FAPI2_RC_SUCCESS if successful
        ///
        fapi2::ReturnCode resolve(const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
                                  const bool i_req_sync_mode,
                                  const std::vector<std::vector<uint32_t>>& i_vpd_supported_freqs,
                                  std::vector<uint8_t>& o_deconfigured,
                                  std::vector<uint32_t>& o_freqs);

    private:
        std::vector<std::vector<bool>> iv_freq_mca_supported;

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
/// @brief Create a vector of support freq based on VPD config
/// @param[in] i_target MCBIST target for which to get the DIMM configs
/// @param[out] reference to a 2 dimensional std::vector of supported VPD frequencies for each MCA
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode vpd_supported_freqs( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
                                       std::vector<std::vector<uint32_t>>& o_vpd_supported_freqs);

///
/// @brief Retrieves max frequency each port supports due to DIMM SPD
/// @param[in] i_target the MCBIST target
/// @param[out] o_supported_freqs reference to vector of max SPD supported freq for each port
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode spd_supported_freq(const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
                                     std::vector<uint32_t>& o_supported_freqs);

///
/// @brief Create and sort a vector of supported MT/s (freq)
/// @param[in] i_target MCA target for which to get the DIMM configs
/// @param[out] o_freqs reference to a std::vector to put the sorted vector
/// @return FAPI2_RC_SUCCESS iff ok
/// @note Taken from VPD supported freqs. The result is sorted so such that the min
/// supported freq is std::vector<>.begin and the max is std::vector<>.end - 1. You can
/// search the resulting vector for valid frequencies as it is sorted.
///
fapi2::ReturnCode supported_freqs(const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
                                  std::vector<uint32_t>& o_freqs);

///
/// @brief Update supported frequency scoreboard according to MRW/config limits
/// @param[in] i_target MCBIST target for which to get the DIMM configs
/// @param[in] i_max_mrw_freqs vector of max allowed freqs
/// @param[in,out] io_scoreboard scoreboard of MCA targets supporting each frequency
/// @return FAPI2_RC_SUCCESS iff ok
/// @note the attributes which drive this are read-only so they're hard to change when
/// testing. So this helper allows us to use the attributes for the main path but
/// have a path for testing
///
fapi2::ReturnCode limit_freq_by_mrw(const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
                                    const std::vector<uint32_t>& i_max_mrw_freqs,
                                    freq_scoreboard& io_scoreboard);

///
/// @brief Update supported frequency scoreboard according to VPD limits
/// @param[in] i_target MCBIST target for which to get the DIMM configs
/// @param[in] i_hw_freqs vector of hardware supported freqs -- from VPD
/// @param[in,out] io_scoreboard scoreboard of MCA targets supporting each frequency
/// @return FAPI2_RC_SUCCESS iff ok
/// @note the attributes which drive this are read-only so they're hard to change when
/// testing. So this helper allows us to use the attributes for the main path but
/// have a path for testing
///
fapi2::ReturnCode limit_freq_by_vpd(const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
                                    const std::vector<std::vector<uint32_t>>& i_hw_freqs,
                                    freq_scoreboard& io_scoreboard);

///
/// @brief Update supported frequency scoreboard according to SPD limits
/// @param[in] i_target MCBIST target for which to get the DIMM configs
/// @param[in] i_hw_freqs vector of hardware supported freqs -- from SPD
/// @param[in,out] io_scoreboard scoreboard of MCA targets supporting each frequency
/// @return FAPI2_RC_SUCCESS iff ok
/// @note the attributes which drive this are read-only so they're hard to change when
/// testing. So this helper allows us to use the attributes for the main path but
/// have a path for testing
///
fapi2::ReturnCode limit_freq_by_spd(const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
                                    const std::vector<uint32_t>& i_hw_freqs,
                                    freq_scoreboard& io_scoreboard);

}// mss

#endif
