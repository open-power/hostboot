/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/freq/mss_freq_scoreboard.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2021                        */
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
/// @file mss_freq_scoreboard.H
/// @brief Frequency scoreboard class declaration
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef MSS_FREQ_SCOREBOARD_H
#define MSS_FREQ_SCOREBOARD_H

#include <vector>
#include <fapi2.H>
#include <generic/memory/lib/utils/freq/gen_mss_freq_traits.H>
#include <generic/memory/lib/utils/pos.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/pos.H>

namespace mss
{

///////////////////////////////////////////////////////////////////////
/// Helper functions first
///////////////////////////////////////////////////////////////////////

///
/// @brief Gets the number of master ranks on each DIMM
/// @tparam P mss::proc_type on which to operate
/// @param[in] i_target DIMM target
/// @param[out] o_master_ranks number of master ranks
/// @return FAPI2_RC_SUCCESS iff ok
///
template<mss::proc_type P>
fapi2::ReturnCode num_master_ranks_per_dimm(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_master_ranks);

///
/// @brief Gets the DIMM type for a specific DIMM
/// @tparam P mss::proc_type on which to operate
/// @param[in] i_target DIMM target
/// @param[out] o_dimm_type DIMM type on the DIMM target
/// @return FAPI2_RC_SUCCESS iff ok
///
template<mss::proc_type P>
fapi2::ReturnCode get_dimm_type(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                uint8_t& o_dimm_type);

///
/// @brief Gets the attribute for the maximum allowed dimm frequency
/// @tparam P mss::proc_type on which to operate
/// @param[out] o_allowed_dimm_freq allowed dimm frequency
/// @return FAPI2_RC_SUCCESS iff ok
///
template<mss::proc_type P>
fapi2::ReturnCode max_allowed_dimm_freq(uint32_t* o_allowed_dimm_freq);

///
/// @brief Calls out the target if no DIMM frequencies are supported
/// @tparam P mss::proc_type on which to operate
/// @tparam T fapi2::TargetType on which to set the frequency
/// @param[in] i_target target on which to operate
/// @param[in] i_supported_freq true if any FREQ's are supported
/// @param[in] i_num_ports number of ports on the frequency domain
/// @return FAPI2_RC_SUCCESS iff ok
///
template<mss::proc_type P, fapi2::TargetType T>
fapi2::ReturnCode callout_no_common_freq(const fapi2::Target<T>& i_target,
        const bool l_supported_freq,
        const uint64_t i_num_ports);

///
/// @brief Calls out the target if no DIMM frequencies are supported
/// @tparam P mss::proc_type on which to operate
/// @tparam T fapi2::TargetType on which to set the frequency
/// @param[in] i_target target on which to operate
/// @param[in] i_vpd_supported_freqs VPD supported frequencies for the callout
/// @return FAPI2_RC_SUCCESS iff ok
///
template<mss::proc_type P, fapi2::TargetType T>
fapi2::ReturnCode callout_max_freq_empty_set(const fapi2::Target<T>& i_target,
        const std::vector<std::vector<uint32_t>>& i_vpd_supported_freqs);

///
/// @class freq_scoreboard
/// @brief class that encapsulates port supported frequencies
///
class freq_scoreboard
{
    public:
        // We need to know the number of ports on each frequency domain and how many frequencies are available for a given processor
        // Therefor, the base constructor is not allowed
        freq_scoreboard() = delete;

        ///
        /// @brief Create a new frequency scoreboard
        /// @param[in] i_num_ports number of ports on this frequency domain
        /// @param[in] i_freq_values the list of allowed frequencis for this system
        ///
        freq_scoreboard(const uint64_t i_num_ports, const std::vector<uint64_t>& i_freq_values) :
            iv_num_ports(i_num_ports),
            iv_freq_values(i_freq_values)
        {
            iv_supported_port_freqs = std::vector<std::vector<bool>>(i_num_ports,
                                      std::vector<bool>(i_freq_values.size(), true));
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
        fapi2::ReturnCode remove_freqs_above_limit(const uint64_t i_port_pos,
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
        /// @brief Remove frequencies not on a given list from the scoreboard
        /// @tparam T the type of data in the vector
        /// @param[in] i_port_pos position index of port within parent MCBIST
        /// @param[in] i_freq_list vector of supported frequencies
        /// @return FAPI2_RC_SUCCESS if successful
        ///
        template<typename T>
        fapi2::ReturnCode remove_freqs_not_on_list(const uint64_t i_port_pos,
                const std::vector<T>& i_freq_list)
        {
            FAPI_ASSERT(i_port_pos < iv_num_ports,
                        fapi2::MSS_INVALID_PORT_INDEX_PASSED()
                        .set_INDEX(i_port_pos)
                        .set_FUNCTION(generic_ffdc_codes::FREQ_SCOREBOARD_REMOVE_FREQS_NOT_ON_LIST),
                        "Invalid port index passed to remove_freqs_not_on_list (%d)",
                        i_port_pos);

            for ( size_t l_index = 0; l_index < iv_freq_values.size(); ++l_index )
            {
                const auto l_it = std::find(i_freq_list.begin(), i_freq_list.end(), iv_freq_values[l_index]);

                if (l_it == i_freq_list.end())
                {
                    iv_supported_port_freqs[i_port_pos][l_index] = false;
                }
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
        fapi2::ReturnCode max_supported_freq(const uint64_t i_port_pos,
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
        fapi2::ReturnCode supported_freqs(const uint64_t i_port_pos,
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

        ///
        /// @brief Resolve frequency scoreboard by deconfiguring any non-conforming ports
        /// and return a list of the supported frequencies
        /// @tparam P mss::proc_type on which to operate
        /// @tparam TT Traits associated with the processor type
        /// @param[in] i_target MCBIST target
        /// @param[in] i_vpd_supported_freqs vector of hardware supported freqs -- from VPD
        /// @param[out] o_deconfigured vector of port positions that were deconfigured by this function
        /// @param[out] o_deconfigured_targets vector of port targets that were deconfigured by this function
        /// @param[out] o_freqs vector of frequencies supported by all ports
        /// @return FAPI2_RC_SUCCESS if successful
        ///
        template<mss::proc_type P, typename TT = mss::frequency_traits<P>>
        fapi2::ReturnCode resolve(const fapi2::Target<TT::FREQ_DOMAIN_TARGET_TYPE>& i_target,
                                  const std::vector<std::vector<uint32_t>>& i_vpd_supported_freqs,
                                  std::vector<uint8_t>& o_deconfigured,
                                  std::vector<fapi2::Target<TT::PORT_TARGET_TYPE>>& o_deconfigured_targets,
                                  std::vector<uint32_t>& o_freqs)
        {
            const auto l_ports = mss::find_targets_sorted_by_pos<TT::PORT_TARGET_TYPE>(i_target);
            const auto l_port_count = l_ports.size();

            // empty_port_count is the number of port that are deconfigured
            // We use it later to make sure our common freq is supported by at least one configured port
            const auto l_empty_port_count = iv_num_ports - l_port_count;

            // Get a count of how many ports support each frequency
            const auto l_support_counts = count_supported_frequencies<P>(i_target, l_ports, o_freqs);

            // If we have at least one common frequency, we're done
            if (!o_freqs.empty())
            {
                return fapi2::FAPI2_RC_SUCCESS;
            }

            // If we made it here, that means we don't have a common supported freq for all ports
            // So let's deconfigure the least number of ports to get a common freq

            // Find the last instance of the most ports that support a given frequency
            // That way we get the highest frequency supported by the most ports
            // Note: this may be inefficient, but this is a small vector and HB doesn't support reverse iterators
            uint64_t l_common_ports = 0;
            size_t l_best_freq_index = 0;

            for ( size_t l_index = 0; l_index < l_support_counts.size(); ++l_index )
            {
                if (l_support_counts[l_index] >= l_common_ports)
                {
                    l_common_ports = l_support_counts[l_index];
                    l_best_freq_index = l_index;
                }
            }

            FAPI_INF("%s Max ports supporting a common frequency is %d", mss::c_str(i_target), l_common_ports);
            FAPI_INF("%s Fastest common frequency is %d", mss::c_str(i_target), TT::SUPPORTED_FREQS[l_best_freq_index]);

            // Assert if we don't have any frequencies supported by at least one configured port
            FAPI_TRY(callout_no_common_freq<P>(i_target, l_common_ports > l_empty_port_count, l_port_count));

            // Now find and deconfigure all ports that don't support our selected frequency
            FAPI_TRY(deconfigure_ports<P>(i_target, l_ports, l_best_freq_index, o_deconfigured, o_deconfigured_targets));

            // Now find all the frequencies supported by the ports that are left over
            FAPI_TRY(this->template resolve<P>(i_target, i_vpd_supported_freqs, o_deconfigured, o_deconfigured_targets, o_freqs));

#ifndef __HOSTBOOT_MODULE

            // Cronus doesn't deconfigure, so let's bail out if we didn't find a common frequency
            if (!o_deconfigured.empty())
            {
                FAPI_TRY(callout_max_freq_empty_set<P>(i_target, i_vpd_supported_freqs));
            }

#endif

            return fapi2::FAPI2_RC_SUCCESS;

        fapi_try_exit:
            return fapi2::current_err;
        }

    private:
        uint64_t iv_num_ports;
        std::vector<uint64_t> iv_freq_values;
        std::vector<std::vector<bool>> iv_supported_port_freqs;

        // Private helper functions

        ///
        /// @brief Checks our port position
        /// @param[in] i_port_pos port position
        /// @param[in] i_ffdc generic_ffdc_codes for the calling function
        /// @return FAPI2_RC_SUCCESS iff ok
        ///
        inline fapi2::ReturnCode check_port_position(const uint64_t i_port_pos, const generic_ffdc_codes i_ffdc) const
        {
            FAPI_ASSERT(i_port_pos < iv_num_ports,
                        fapi2::MSS_INVALID_PORT_INDEX_PASSED()
                        .set_INDEX(i_port_pos)
                        .set_FUNCTION(i_ffdc),
                        "Invalid port index passed into the function (%d)",
                        i_port_pos);

            return fapi2::FAPI2_RC_SUCCESS;

        fapi_try_exit:
            return fapi2::current_err;
        }

        ///
        /// @brief Counts the common port frequencies
        /// @tparam P mss::proc_type on which to operate
        /// @tparam TT Traits associated with the processor type
        /// @param[in] i_target frequency domain target
        /// @param[in] i_ports vector of ports
        /// @param[out] o_freqs vector of frequencies
        /// @returh l_supported_vector return the fector of supported frequencies
        ///
        template<mss::proc_type P, typename TT = mss::frequency_traits<P>>
        std::vector<uint64_t> count_supported_frequencies(const fapi2::Target<TT::FREQ_DOMAIN_TARGET_TYPE>& i_target,
                const std::vector<fapi2::Target<TT::PORT_TARGET_TYPE>>& i_ports,
                std::vector<uint32_t>& o_freqs)
        {
            // This vector will hold the number of ports that support each frequency in TT::SUPPORTED_FREQS
            std::vector<uint64_t> l_support_counts(TT::SUPPORTED_FREQS.size(), 0);
            o_freqs.clear();

            // Get a count of how many ports support each frequency
            for ( size_t l_index = 0; l_index < TT::SUPPORTED_FREQS.size(); ++l_index )
            {
                size_t l_pos = 0;

                for ( const auto& l_supported : iv_supported_port_freqs )
                {
                    if (l_supported[l_index])
                    {
                        FAPI_DBG("%s Frequency %d is supported by port%d", mss::c_str(i_target), TT::SUPPORTED_FREQS[l_index], l_pos);
                        ++l_support_counts[l_index];
                    }

                    // Add any frequencies supported by all configured ports to our output list
                    // Note that deconfigured ports will support all frequencies due to the way the scoreboard is built
                    if (l_support_counts[l_index] == iv_num_ports)
                    {
                        FAPI_DBG("%s Frequency %d is supported by all ports", mss::c_str(i_target), TT::SUPPORTED_FREQS[l_index]);
                        o_freqs.push_back(TT::SUPPORTED_FREQS[l_index]);
                    }

                    ++l_pos;
                }
            }

            return l_support_counts;
        }

        ///
        /// @brief Counts the common port frequencies
        /// @tparam P mss::proc_type on which to operate
        /// @tparam TT Traits associated with the processor type
        /// @param[in] i_target frequency domain target
        /// @param[in] i_ports vector of ports
        /// @param[in] i_best_freq_index index corresponding to the best case frequency
        /// @param[out] o_deconfigured vector of deconfigured port positions
        /// @param[out] o_deconfigured_targets vector of deconfigured targets
        /// @return FAPI2_RC_SUCCESS iff ok
        ///
        template<mss::proc_type P, typename TT = mss::frequency_traits<P>>
        fapi2::ReturnCode deconfigure_ports(const fapi2::Target<TT::FREQ_DOMAIN_TARGET_TYPE>& i_target,
                                            const std::vector<fapi2::Target<TT::PORT_TARGET_TYPE>>& i_ports,
                                            const uint64_t i_best_freq_index,
                                            std::vector<uint8_t>& o_deconfigured,
                                            std::vector<fapi2::Target<TT::PORT_TARGET_TYPE>>& o_deconfigured_targets)
        {
            o_deconfigured.clear();
            o_deconfigured_targets.clear();

            for ( size_t l_pos = 0; l_pos < iv_num_ports; ++l_pos )
            {
                // Find the port with this position
                const auto l_it_port = std::find_if(i_ports.begin(),
                                                    i_ports.end(),
                                                    [l_pos]( const fapi2::Target<TT::PORT_TARGET_TYPE>& i_rhs) -> bool
                {
                    return (mss::relative_pos<TT::FREQ_DOMAIN_TARGET_TYPE>(i_rhs) == l_pos);
                });

                // If we didn't find an port for a given position, there wasn't one configured there
                if (l_it_port == i_ports.end())
                {
                    continue;
                }

                // and call it out if it doesn't support the selected freq
                const auto& p = *l_it_port;
                FAPI_DBG("Checking if port %d (%s) supports common frequency", l_pos, mss::c_str(p));

                if (!iv_supported_port_freqs[l_pos][i_best_freq_index])
                {
                    FAPI_INF("Port %d (%s) does not support the common frequency so will be deconfigured", l_pos, mss::c_str(p));
                    auto& l_port_supported_freqs = iv_supported_port_freqs[l_pos];

                    o_deconfigured.push_back(l_pos);
                    o_deconfigured_targets.push_back(p);
                    FAPI_ASSERT_NOEXIT( false,
                                        fapi2::MSS_PORT_DOES_NOT_SUPPORT_MAJORITY_FREQ()
                                        .set_FREQ_TARGET(i_target)
                                        .set_PORT_TARGET(p)
                                        .set_FREQUENCY(TT::SUPPORTED_FREQS[i_best_freq_index]),
                                        "%s does not support the majority frequency (%d) so will be deconfigured",
                                        mss::c_str(p), TT::SUPPORTED_FREQS[i_best_freq_index] );

                    // Now mark all frequencies as supported by that port since it was deconfigured
                    for ( size_t l_index = 0; l_index < l_port_supported_freqs.size(); ++l_index )
                    {
                        l_port_supported_freqs[l_index] = true;
                    }
                }
            }

            return fapi2::FAPI2_RC_SUCCESS;
        }
};

///
/// @brief Update supported frequency scoreboard according to processor limits
/// @tparam P mss::proc_type on which to operate
/// @tparam TT Traits associated with the processor type
/// @param[in] i_target processor frequency domain
/// @param[in,out] io_scoreboard scoreboard of port targets supporting each frequency
/// @return FAPI2_RC_SUCCESS iff ok
///
template<mss::proc_type P, typename TT = mss::frequency_traits<P>>
fapi2::ReturnCode limit_freq_by_processor(const fapi2::Target<TT::FREQ_DOMAIN_TARGET_TYPE>& i_target,
        freq_scoreboard& io_scoreboard);

///
/// @brief Update supported frequency scoreboard according to MRW/config limits
/// @tparam P mss::proc_type on which to operate
/// @tparam TT Traits associated with the processor type
/// @param[in] i_target target for which to get the DIMM configs
/// @param[in] i_max_mrw_freqs vector of max allowed freqs
/// @param[in,out] io_scoreboard scoreboard of targets supporting each frequency
/// @return FAPI2_RC_SUCCESS iff ok
/// @note This helper allows us to use the attributes for the main path but
/// have a path for testing
///
template<mss::proc_type P, typename TT = mss::frequency_traits<P>>
inline fapi2::ReturnCode limit_freq_by_mrw(const fapi2::Target<TT::FREQ_DOMAIN_TARGET_TYPE>& i_target,
        const std::vector<uint32_t>& i_max_mrw_freqs,
        freq_scoreboard& io_scoreboard)
{
    // Static asserting to ensure that we have the correct sized array bellow
    // We'll need to do some code updates if this changes anyways
    static_assert(2 == TT::MAX_DIMM_PER_PORT, "Number of DIMM's per port is not 2!");
    static_assert(4 == TT::MAX_PRIMARY_RANK_PER_DIMM, "Maximum number of primary ranks per DIMM is not 4!");

    // Indexes into the ATTR_MAX_ALLOWED_DIMM_FREQ arrary. e.g., [0][0] is 1R 1 drop
    constexpr size_t l_indexes[2][4] =
    {
        {0, 1, 0xFF, 2},
        {3, 4, 0xFF, 0xFF}
    };

    // This is the number of elements in the max_allowed_dimm_freq attribute, not the frequencies of
    // the system.
    FAPI_ASSERT( i_max_mrw_freqs.size() == NUM_MAX_FREQS,
                 fapi2::MSS_MAX_FREQ_ATTR_SIZE_CHANGED()
                 .set_ACTUAL_SIZE(i_max_mrw_freqs.size())
                 .set_SUPPOSED_SIZE(NUM_MAX_FREQS)
                 .set_PORT_TARGET(i_target),
                 "%s Incorrect number of max frequencies in attribute for (%d)",
                 mss::c_str(i_target),
                 i_max_mrw_freqs.size());

    FAPI_DBG("attribute supported max allowed dimm freqs %d %d %d %d %d for %s",
             i_max_mrw_freqs[0], i_max_mrw_freqs[1], i_max_mrw_freqs[2], i_max_mrw_freqs[3], i_max_mrw_freqs[4],
             mss::c_str(i_target));

    for( const auto& p : mss::find_targets<TT::PORT_TARGET_TYPE>(i_target) )
    {
        const auto l_port_pos = mss::relative_pos<TT::FREQ_DOMAIN_TARGET_TYPE>(p);
        const auto l_dimms = mss::find_targets<fapi2::TARGET_TYPE_DIMM>(p);
        const uint64_t l_dimms_on_port = l_dimms.size();

        // Holds the max freq allowed for this port. This is the minimum of maximum
        // frequencies allowed by the DIMM. So, we start way off the charts so std::min can do the lifting for us.
        uint32_t l_port_max_freq = ~(0);

        FAPI_ASSERT( (l_dimms_on_port <= TT::MAX_DIMM_PER_PORT),
                     fapi2::MSS_TOO_MANY_DIMMS_ON_PORT()
                     .set_DIMM_COUNT(l_dimms_on_port)
                     .set_PORT_TARGET(p),
                     "Seeing %d DIMM on port %s",
                     l_dimms_on_port,
                     mss::c_str(p));

        // Find the max supported frequency for this port
        for (const auto& d : l_dimms)
        {
            uint8_t l_num_master_ranks = 0;
            uint8_t l_dimm_type = 0;
            uint8_t l_rank_index = 0;
            size_t l_index = 0xFF;
            FAPI_TRY( num_master_ranks_per_dimm<P>(d, l_num_master_ranks) );
            FAPI_TRY( get_dimm_type<P>(d, l_dimm_type));

            // Just a quick check but we're in deep yogurt if this triggers
            FAPI_ASSERT( (l_num_master_ranks <= TT::MAX_PRIMARY_RANK_PER_DIMM),
                         fapi2::MSS_TOO_MANY_PRIMARY_RANKS_ON_DIMM()
                         .set_RANK_COUNT(l_num_master_ranks)
                         .set_DIMM_TARGET(d),
                         "seeing %d primary ranks on DIMM %s",
                         l_dimms_on_port,
                         mss::c_str(d));

            // If we have an LRDIMM, it's treated as a one rank DIMM from the memory controller's perspective
            l_rank_index = l_dimm_type == TT::LRDIMM_TYPE ? 0 : l_num_master_ranks - 1;
            l_index = l_indexes[l_dimms_on_port - 1][l_rank_index];
            FAPI_DBG("%s is %s. rank_index%u index:%u", spd::c_str(d), l_dimm_type == TT::LRDIMM_TYPE ? "LRDIMM" : "RDIMM",
                     l_rank_index, l_index);

            FAPI_ASSERT( (l_index < NUM_MAX_FREQS),
                         fapi2::MSS_FREQ_INDEX_TOO_LARGE()
                         .set_INDEX(l_index)
                         .set_NUM_MAX_FREQS(NUM_MAX_FREQS),
                         "seeing %d index for %d DIMM and %d ranks on DIMM %s",
                         l_index,
                         l_dimms_on_port,
                         l_num_master_ranks,
                         mss::c_str(d));

            FAPI_DBG("%s rank config %d drop %d yields max freq attribute index of %d (%d)",
                     mss::c_str(d), l_num_master_ranks, l_dimms_on_port,
                     l_indexes[l_dimms_on_port - 1][l_rank_index],
                     i_max_mrw_freqs[l_index] );

            l_port_max_freq = std::min(l_port_max_freq, i_max_mrw_freqs[l_index]);
        }// dimm

        // Remove any frequencies bigger than this port's max from the scoreboard
        io_scoreboard.remove_freqs_above_limit(l_port_pos, l_port_max_freq);

        FAPI_INF("%s after processing MRW, max freq is %d", mss::c_str(p), l_port_max_freq);
    }// port

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Update supported frequency scoreboard according to VPD limits
/// @tparam P mss::proc_type on which to operate
/// @tparam TT Traits associated with the processor type
/// @param[in] i_target MCBIST target for which to get the DIMM configs
/// @param[in] i_hw_freqs vector of hardware supported freqs -- from VPD
/// @param[in,out] io_scoreboard scoreboard of port targets supporting each frequency
/// @return FAPI2_RC_SUCCESS iff ok
/// @note This helper allows us to use the attributes for the main path but
/// have a path for testing
///
template<mss::proc_type P, typename TT = mss::frequency_traits<P>>
fapi2::ReturnCode limit_freq_by_vpd(const fapi2::Target<TT::FREQ_DOMAIN_TARGET_TYPE>& i_target,
                                    const std::vector<std::vector<uint32_t>>& i_hw_freqs,
                                    freq_scoreboard& io_scoreboard)
{
    const auto PORTS_PER_FREQ_DOMAIN = TT::PORTS_PER_FREQ_DOMAIN;
    FAPI_ASSERT(i_hw_freqs.size() == TT::PORTS_PER_FREQ_DOMAIN,
                fapi2::MSS_INVALID_VPD_FREQ_LIST_PASSED()
                .set_SIZE(i_hw_freqs.size())
                .set_EXPECTED(PORTS_PER_FREQ_DOMAIN),
                "Wrong size VPD frequency vector passed to limit_freq_by_vpd (got %d, expected %d)",
                i_hw_freqs.size(), TT::PORTS_PER_FREQ_DOMAIN);

    for( const auto& p : mss::find_targets<TT::PORT_TARGET_TYPE>(i_target) )
    {
        const auto l_port_pos = mss::relative_pos<TT::FREQ_DOMAIN_TARGET_TYPE>(p);
        const auto& l_port_freqs = i_hw_freqs[l_port_pos];

        // This is the list of supported frequencies for VPD
        FAPI_ASSERT( !l_port_freqs.empty(),
                     fapi2::MSS_EMPTY_VECTOR().
                     set_FUNCTION(LIMIT_FREQ_BY_VPD).
                     set_TARGET(p),
                     "Supported system freqs from VPD are empty for %s",
                     mss::c_str(p));

        for( const auto& freq : l_port_freqs )
        {
            FAPI_DBG("VPD supported freqs %d for %s", freq, mss::c_str(p) );
        }

        // Remove any frequencies that aren't in this port's list from the scoreboard
        io_scoreboard.remove_freqs_not_on_list(l_port_pos, l_port_freqs);

        uint32_t l_max_freq = 0;
        FAPI_TRY( io_scoreboard.max_supported_freq(l_port_pos, l_max_freq) );
        FAPI_INF("%s after processing VPD, max freq is %d", mss::c_str(p), l_max_freq);
    }// port

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Update supported frequency scoreboard according to SPD limits
/// @tparam P mss::proc_type on which to operate
/// @tparam TT Traits associated with the processor type
/// @param[in] i_target target for which to get the DIMM configs
/// @param[in] i_hw_freqs vector of hardware supported freqs -- from SPD
/// @param[in,out] io_scoreboard scoreboard of port targets supporting each frequency
/// @return FAPI2_RC_SUCCESS iff ok
/// @note This helper allows us to use the attributes for the main path but
/// have a path for testing
///
template<mss::proc_type P, typename TT = mss::frequency_traits<P>>
fapi2::ReturnCode limit_freq_by_spd(const fapi2::Target<TT::FREQ_DOMAIN_TARGET_TYPE>& i_target,
                                    const std::vector<uint32_t>& i_hw_freqs,
                                    freq_scoreboard& io_scoreboard)
{
    for( const auto& p : mss::find_targets<TT::PORT_TARGET_TYPE>(i_target) )
    {
        const auto l_port_pos = mss::relative_pos<TT::FREQ_DOMAIN_TARGET_TYPE>(p);

        // Remove any frequencies that aren't in this port's list from the scoreboard
        io_scoreboard.remove_freqs_above_limit(l_port_pos, i_hw_freqs);

        uint32_t l_max_freq = 0;
        FAPI_TRY( io_scoreboard.max_supported_freq(l_port_pos, l_max_freq) );
        FAPI_INF("%s after processing SPD, max freq is %d", mss::c_str(p), l_max_freq);
    }// port

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

} // ns mss

#endif
