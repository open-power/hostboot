/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/freq/mss_freq_scoreboard.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
/// @file mss_freq_scoreboard.C
/// @brief Frequency scoreboard class definitions
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#include <vector>
#include <fapi2.H>
#include <generic/memory/lib/utils/freq/mss_freq_scoreboard.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

namespace mss
{

///
/// @brief Remove frequencies above a limit from the scoreboard
/// @param[in] i_port_pos position index of port within parent MCBIST
/// @param[in] i_freq_limit upper limit for frequency
/// @return FAPI2_RC_SUCCESS if successful
///
fapi2::ReturnCode freq_scoreboard::remove_freqs_above_limit(const uint64_t i_port_pos,
        const uint32_t i_freq_limit)
{
    FAPI_TRY( check_port_position(i_port_pos,
                                  generic_ffdc_codes::FREQ_SCOREBOARD_REMOVE_FREQS_ABOVE_LIMIT),
              "Invalid port index passed to remove_freqs_above_limit (%d)",
              i_port_pos);

    {
        auto& l_port_supported_freqs = iv_supported_port_freqs[i_port_pos];

        // Can't do a ranged for loop here because we need the index to get the frequency out of iv_freq_values
        for ( size_t l_index = 0; l_index < l_port_supported_freqs.size(); ++l_index )
        {
            const auto l_scoreboard_freq = iv_freq_values[l_index];

            if ( l_scoreboard_freq > i_freq_limit )
            {
                FAPI_INF("Removing freq %d on port %d since it's above the limit %d", l_scoreboard_freq, i_port_pos, i_freq_limit);
                l_port_supported_freqs[l_index] = false;
            }
        }
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Remove frequencies above a limit from the scoreboard
/// @param[in] i_port_pos position index of port within parent MCBIST
/// @param[in] i_freq_limits reference to vector of upper limits for frequency per port
/// @return FAPI2_RC_SUCCESS if successful
///
fapi2::ReturnCode freq_scoreboard::remove_freqs_above_limit(const uint64_t i_port_pos,
        const std::vector<uint32_t> i_freq_limits)
{
    FAPI_TRY( check_port_position(i_port_pos,
                                  generic_ffdc_codes::FREQ_SCOREBOARD_REMOVE_FREQS_ABOVE_LIMIT_VECTOR),
              "Invalid port index passed to remove_freqs_above_limit (%d)",
              i_port_pos);

    FAPI_ASSERT(i_freq_limits.size() == iv_num_ports,
                fapi2::MSS_INVALID_FREQ_LIST_PASSED()
                .set_SIZE(i_freq_limits.size())
                .set_EXPECTED(iv_num_ports),
                "Invalid frequency list passed to remove_freqs_above_limit (size should be %d but got %d)",
                iv_num_ports, i_freq_limits.size());

    {
        const auto l_freq_limit = i_freq_limits[i_port_pos];
        FAPI_TRY( this->remove_freqs_above_limit(i_port_pos, l_freq_limit) );
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Return the maximum supported frequency for a given port
/// @param[in] i_port_pos position index of port within parent MCBIST
/// @param[out] o_freq max supported frequency
/// @return FAPI2_RC_SUCCESS if successful
///
fapi2::ReturnCode freq_scoreboard::max_supported_freq(const uint64_t i_port_pos,
        uint32_t& o_freq) const
{
    FAPI_TRY( this->check_port_position(i_port_pos,
                                        generic_ffdc_codes::FREQ_SCOREBOARD_MAX_SUPPORTED_FREQ),
              "Invalid port index passed to max_supported_freq (%d)",
              i_port_pos);

    {
        std::vector<uint32_t> l_supported_freqs;
        FAPI_TRY( this->supported_freqs(i_port_pos, l_supported_freqs) );

        o_freq = l_supported_freqs.empty() ? 0 : l_supported_freqs.back();
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Return a list of supported frequencies for a given port
/// @param[in] i_port_pos position index of port within parent MCBIST
/// @param[out] o_freq vector of supported frequencies
/// @return FAPI2_RC_SUCCESS if successful
///
fapi2::ReturnCode freq_scoreboard::supported_freqs(const uint64_t i_port_pos,
        std::vector<uint32_t>& o_freqs) const
{
    FAPI_TRY( check_port_position(i_port_pos,
                                  generic_ffdc_codes::FREQ_SCOREBOARD_SUPPORTED_FREQS),
              "Invalid port index passed to supported_freqs (%d)",
              i_port_pos);

    {
        o_freqs.clear();
        auto& l_port_supported_freqs = iv_supported_port_freqs[i_port_pos];

        for ( size_t l_index = 0; l_index < iv_freq_values.size(); ++l_index )
        {
            if (l_port_supported_freqs[l_index])
            {
                o_freqs.push_back(iv_freq_values[l_index]);
            }
        }
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

} // ns mss
