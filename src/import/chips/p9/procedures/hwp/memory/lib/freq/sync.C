/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/freq/sync.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
/// @file sync.C
/// @brief Synchronous function implementations
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#include  <vector>
#include <map>

#include <fapi2.H>
#include <mss.H>
#include <lib/freq/sync.H>
#include <lib/utils/find.H>
#include <lib/utils/assert_noexit.H>

using fapi2::TARGET_TYPE_DIMM;
using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_SYSTEM;

namespace mss
{

// This doesn't seem to be available from the XML, so we'll kind of just hard-wire it. They're
// here as I don't think these values are generally useful and I really don't want them used
// other places.
constexpr size_t NUM_VPD_FREQS = 4;
constexpr size_t NUM_MAX_FREQS = 5;

///
/// @brief Retrieves a mapping of MSS frequency values per mcbist target
/// @param[in] i_targets vector of controller targets
/// @param[out] o_freq_map dimm speed map <key, value> = (mcbist target, frequency)
/// @param[out] o_is_speed_equal true if all map dimm speeds are the same
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode dimm_speed_map(const std::vector< fapi2::Target<TARGET_TYPE_MCBIST> >& i_targets,
                                 std::map< fapi2::Target<TARGET_TYPE_MCBIST>, uint64_t >& o_freq_map,
                                 speed_equality& o_is_speed_equal)
{
    FAPI_INF("---- In dimm_speed_pairs ----");

    if(i_targets.empty())
    {
        FAPI_ERR("Empty MCBIST target vector found when constructing dimm speed mapping!");
        return fapi2::FAPI2_RC_INVALID_PARAMETER;
    }

    // The find_if loop is meant to find the "first" good (non-zero) freq value
    // so I can compare it against all other freq values from the MCBIST vector
    // I am checking to make sure I don't get a value of 0
    // Since Cronus can hand me back an MCBIST w/no DIMMs
    // Which would give ATTR_MSS_FREQ value of 0 in p9_mss_freq
    uint64_t l_comparator = 0;
    fapi2::ReturnCode l_rc(fapi2::FAPI2_RC_SUCCESS);
    const auto l_found_comp = std::find_if(i_targets.begin(), i_targets.end(),
                                           [&l_rc, &l_comparator] (const fapi2::Target<TARGET_TYPE_MCBIST>& i_target)->bool
    {
        l_rc = mss::freq(i_target, l_comparator);
        return l_comparator != 0;
    });

    FAPI_TRY(l_rc, "Failed accessor mss::freq()");

    // If all MCBISTs are 0 we go no further
    if( l_found_comp == i_targets.end() )
    {
        FAPI_ERR( "All MCBIST have a 0 MSS_FREQ" );
        return fapi2::FAPI2_RC_FALSE;
    }

    // DIMM speed is equal until we deduce otherwise
    o_is_speed_equal = speed_equality::EQUAL_DIMM_SPEEDS;

    // Make sure to stick the first one we found in the freq map.
    o_freq_map.emplace( std::make_pair(*l_found_comp, l_comparator) );

    // Loop through all MCSBISTs and store dimm speeds
    // Starting from known 1st known good freq (non-zero) value
    // I found above to avoid double looping target vector
    for (auto l_iter = l_found_comp + 1; l_iter != i_targets.end(); ++l_iter)
    {
        uint64_t l_dimm_speed = 0;
        FAPI_TRY( mss::freq(*l_iter, l_dimm_speed), "Failed accessor to mss_freq" );

        // In FW, parents are deconfigured if they have no children
        // So there is no way to get an MCBIST w/no DIMMs.
        // This isn't true for Cronus so I am skipping map
        // insertion and check for dimm speed equality
        // to avoid incorrect settings
        if( l_dimm_speed != 0)
        {
            // At least one mismatch freq value occurred
            if(l_comparator != l_dimm_speed)
            {
                o_is_speed_equal = speed_equality::NOT_EQUAL_DIMM_SPEEDS;
            }

            FAPI_INF("%s: Dimm speed %d MT/s", c_str(*l_iter), l_dimm_speed);

            o_freq_map.emplace( std::make_pair(*l_iter, l_dimm_speed) );
        }
    }

    // Idiot check - most certainly a programming error
    if (o_freq_map.size() == 0 )
    {
        FAPI_ERR("freq system freq map is empty? found mcbist: %s", mss::c_str(*l_found_comp));
        fapi2::Assert(false);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Deconfigures MCS targets connected to MCBIST
/// @param[in] i_target the controller target
/// @param[in] i_dimm_speed dimm speed in MT/s
/// @param[in] i_nest_freq nest freq in MHz
/// @return true if hardware was deconfigured
///
bool deconfigure(const fapi2::Target<TARGET_TYPE_MCBIST>& i_target,
                 const uint64_t i_dimm_speed,
                 const uint32_t i_nest_freq)
{
    FAPI_INF("---- In deconfigure ----");
    bool l_is_hw_deconfigured = false;

    if(i_dimm_speed != i_nest_freq)
    {
        // Deconfigure MCSes
        for( const auto& l_mcs : mss::find_targets<TARGET_TYPE_MCS>(i_target) )
        {
            l_is_hw_deconfigured = true;

            MSS_ASSERT_NOEXIT(false,
                              fapi2::MSS_FREQ_NOT_EQUAL_NEST_FREQ()
                              .set_MSS_FREQ(i_dimm_speed)
                              .set_NEST_FREQ(i_nest_freq)
                              .set_MCS_TARGET(l_mcs),
                              "Deconfiguring %s",
                              mss::c_str(l_mcs) );
        }// end for
    }// end if

    return l_is_hw_deconfigured;
}

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
fapi2::ReturnCode select_sync_mode(const std::map< fapi2::Target<TARGET_TYPE_MCBIST>, uint64_t >& i_freq_map,
                                   const speed_equality i_equal_dimm_speed,
                                   const uint32_t i_nest_freq,
                                   const uint8_t i_required_sync_mode,
                                   uint8_t& o_selected_sync_mode,
                                   uint64_t& o_selected_freq)
{
    FAPI_INF("---- In select_sync_mode ----");

    // If we're in SYNC_MODE_NEVER, then we're done and we tell the caller we're not in sync mode
    if (fapi2::ENUM_ATTR_REQUIRED_SYNCH_MODE_NEVER == i_required_sync_mode)
    {
        o_selected_sync_mode = fapi2::ENUM_ATTR_MC_SYNC_MODE_NOT_IN_SYNC;
        return fapi2::FAPI2_RC_SUCCESS;
    }

    switch(i_equal_dimm_speed)
    {
        // If we have MCBIST which have resolved to equal speeds ...
        case speed_equality::EQUAL_DIMM_SPEEDS:

            // Return back the resulting speed. It doesn't matter which we select from the map as they're all equal
            // If we end up not in sync in the conditional below, thats ok - this parameter is ignored by the
            // caller if we're not in sync mode
            o_selected_freq = i_freq_map.begin()->second;

            // When we selected ATTR_MSS_FREQ, we made sure that for forced sync mode cases we didn't
            // select a DIMM freq the nest couldn't support. So if we're in forced sync mode, we're done.
            if (i_required_sync_mode == fapi2::ENUM_ATTR_REQUIRED_SYNCH_MODE_ALWAYS)
            {
                o_selected_sync_mode = fapi2::ENUM_ATTR_MC_SYNC_MODE_IN_SYNC;
                // On Cronus if the o_selected_freq != i_nest_freq we've got a mismatch. Note that p9_mss_freq ensures
                // we don't select an invalid freq, but doesn't ensure we select the current nest freq.
#ifndef __HOSTBOOT_MODULE
                FAPI_ASSERT(o_selected_freq == i_nest_freq,
                            fapi2::MSS_FAILED_SYNC_MODE().set_NEST_FREQ(i_nest_freq),
                            "Configured in sync mode, but the DIMM freq (%d) and the nest freq (%d) don't align",
                            o_selected_freq, i_nest_freq);
#endif
                return fapi2::FAPI2_RC_SUCCESS;

            }

            // So we need to decide. We know the DIMM speeds are equal and we know we picked the fastest supportable
            // speed. So, if we're within the nest frequencies then we can run sync mode (lowest latency.) If we're
            // outside of the nest frequencies we'll run async (higest DIMM speed.)
            o_selected_sync_mode = (i_nest_freq <= fapi2::ENUM_ATTR_MSS_FREQ_MT2400) ?
                                   fapi2::ENUM_ATTR_MC_SYNC_MODE_IN_SYNC : fapi2::ENUM_ATTR_MC_SYNC_MODE_NOT_IN_SYNC;
            return fapi2::FAPI2_RC_SUCCESS;
            break;

        case speed_equality::NOT_EQUAL_DIMM_SPEEDS:

            // When we selected ATTR_MSS_FREQ, we made sure that for forced sync mode cases we didn't
            // select a DIMM freq the nest couldn't support. That means that the fastest of the MCBIST
            // is the one that rules the roost (the nest can support it too.) So find that, and set it to
            // the selected frequency. Then deconfigure the slower MCBIST (unless we're in Cronus in which
            // case we just bomb out.)
#ifdef __HOSTBOOT_MODULE
            if( i_required_sync_mode == fapi2::ENUM_ATTR_REQUIRED_SYNCH_MODE_ALWAYS )
            {
                uint64_t l_max_dimm_speed = 0;
                std::for_each(i_freq_map.begin(), i_freq_map.end(),
                              [&l_max_dimm_speed](const std::pair<fapi2::Target<TARGET_TYPE_MCBIST>, uint64_t>& m)
                {
                    l_max_dimm_speed = std::max(l_max_dimm_speed, m.second);
                });

                std::for_each(i_freq_map.begin(), i_freq_map.end(),
                              [&l_max_dimm_speed](const std::pair<fapi2::Target<TARGET_TYPE_MCBIST>, uint64_t>& m)
                {
                    deconfigure(m.first, m.second, l_max_dimm_speed);
                });

                o_selected_sync_mode = fapi2::ENUM_ATTR_MC_SYNC_MODE_IN_SYNC;
                o_selected_freq = l_max_dimm_speed;
                return fapi2::FAPI2_RC_SUCCESS;
            }

#else
            // Cronus only
            FAPI_ASSERT(i_required_sync_mode != fapi2::ENUM_ATTR_REQUIRED_SYNCH_MODE_ALWAYS,
                        fapi2::MSS_FAILED_SYNC_MODE().set_NEST_FREQ(i_nest_freq),
                        "Seeing forced nest/memory sync mode but DIMM speeds differ from nest speed %d", i_nest_freq);
#endif

            // Notce that if we don't have equal DIMM speeds we're never in sync. We either error out (Cronus)
            // or we toss a bunch of DIMM off the boat (f/w) or they didn't care wether we were sync or not.
            o_selected_sync_mode = fapi2::ENUM_ATTR_MC_SYNC_MODE_NOT_IN_SYNC;
            return fapi2::FAPI2_RC_SUCCESS;
            break;

        default:
            FAPI_ERR("Invalid speed_equality parameter!");
            return fapi2::FAPI2_RC_INVALID_PARAMETER;
            break;
    }// end switch

    return fapi2::FAPI2_RC_SUCCESS;

#ifndef __HOSTBOOT_MODULE
fapi_try_exit:
    return fapi2::current_err;
#endif
}

///
/// @brief Create and sort a vector of supported MT/s (freq)
/// @param[in] MCS target for which to get the DIMM configs
/// @param[in,out] reference to a std::vector<uint32_t> space to put the sorted vector
/// @return FAPI2_RC_SUCCESS iff ok
/// @note Taken from ATTR_MSS_MRW_SUPPORTED_FREQ. The result is sorted so such that the min
/// supported freq is std::vector<>.begin and the max is std::vector<>.end - 1. You can
/// search the resulting vector for valid frequencies as it is sorted.
///
fapi2::ReturnCode supported_freqs(const fapi2::Target<TARGET_TYPE_MCS>& i_target, std::vector<uint32_t>& io_freqs)
{
    std::vector<uint32_t> l_freqs(NUM_VPD_FREQS, 0);
    std::vector<uint32_t> l_max_freqs(NUM_MAX_FREQS, 0);
    uint8_t l_req_sync_mode = 0;

    FAPI_TRY( mss::mrw_supported_freq(l_freqs.data()) );
    FAPI_TRY( mss::max_allowed_dimm_freq(l_max_freqs.data()) );
    FAPI_TRY( mss::required_synch_mode(l_req_sync_mode) );

    FAPI_INF("attribute supported freqs %d %d %d %d",
             l_freqs[0], l_freqs[1], l_freqs[2], l_freqs[3]);

    FAPI_INF("attribute supported max freqs %d %d %d %d %d",
             l_max_freqs[0], l_max_freqs[1], l_max_freqs[2], l_max_freqs[3], l_max_freqs[4]);

    FAPI_INF("attribute required sync mode %d", l_req_sync_mode);

    FAPI_TRY( supported_freqs_helper(i_target,
                                     l_freqs,
                                     l_max_freqs,
                                     l_req_sync_mode == fapi2::ENUM_ATTR_REQUIRED_SYNCH_MODE_ALWAYS,
                                     io_freqs) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Create and sort a vector of supported MT/s (freq) - helper for testing purposes
/// @param[in] MCS target for which to get the DIMM configs
/// @param[in] vector of MVPD freqs
/// @param[in] vector of max allowed freqs
/// @param[in] bool whether or not we're forced into sync mode
/// @param[in,out] reference to a std::vector<uint32_t> space to put the sorted vector
/// @return FAPI2_RC_SUCCESS iff ok
/// @note the attributes which drive this are read-only so they're hard to change when
/// testing. So this helper allows us to use the attributes for the main path but
/// have a path for testing (DFT I think the cool kids call it.)
///
fapi2::ReturnCode supported_freqs_helper(const fapi2::Target<TARGET_TYPE_MCS>& i_target,
        const std::vector<uint32_t>& i_freqs,
        const std::vector<uint32_t>& i_max_freqs,
        const bool i_req_sync_mode,
        std::vector<uint32_t>& io_freqs)
{
    // Indexes into the ATTR_MAX_ALLOWED_DIMM_FREQ arrary. e.g., [0][0] is 1R 1 drop
    constexpr size_t l_indexes[MAX_DIMM_PER_PORT][MAX_PRIMARY_RANKS_PER_PORT] =
    {
        {0, 1, 0xFF, 2},
        {3, 4, 0xFF, 0xFF}
    };

    // Holds the max freq allowed for this configuration of DIMMs. This is the minimum of maximum
    // frequencies allowed by the DIMM. So, we start way off the charts so std::min can do the lifting for us.
    uint32_t l_our_max_freq = ~(0);

    io_freqs.clear();

    // This magic number isn't the number of frequencies supported by the hardware, it's the number
    // of frequencies in the attribute or VPD. They may be different (see *1 below)
    if (i_freqs.size() != NUM_VPD_FREQS)
    {
        FAPI_ERR("incorrect number of frequencies for %s (%d)", mss::c_str(i_target), i_freqs.size());
        fapi2::Assert(false);
    }

    FAPI_INF("unsorted supported freqs %d %d %d %d",
             i_freqs[0], i_freqs[1], i_freqs[2], i_freqs[3]);

    // (*1) This is the number of elelments in the max_allowed_dimm_freq attribute, not the frequencies of
    // the system. Hence the magic number.
    if (i_max_freqs.size() != NUM_MAX_FREQS)
    {
        FAPI_ERR("incorrect number of max frequencies for %s (%d)", mss::c_str(i_target), i_max_freqs.size());
        fapi2::Assert(false);
    }

    FAPI_INF("max supported freqs %d %d %d %d %d",
             i_max_freqs[0], i_max_freqs[1], i_max_freqs[2], i_max_freqs[3], i_max_freqs[4]);

    // Given the max supported freqs, find the config based on our DIMMs. There's no great way to do this ...
    for (const auto& p : mss::find_targets<TARGET_TYPE_MCA>(i_target))
    {
        const auto l_dimms = mss::find_targets<TARGET_TYPE_DIMM>(p);
        uint64_t l_dimms_on_port = l_dimms.size();

        // Just a quick check but we're in deep yogurt if this triggers
        if (l_dimms_on_port > MAX_DIMM_PER_PORT)
        {
            FAPI_ERR("seeing %d DIMM on port %s", l_dimms_on_port, mss::c_str(p));
            fapi2::Assert(false);
        }

        for (const auto& d : l_dimms)
        {
            uint8_t l_num_master_ranks = 0;
            size_t l_index = 0xFF;

            FAPI_TRY( mss::eff_num_master_ranks_per_dimm(d, l_num_master_ranks) );

            // Just a quick check but we're in deep yogurt if this triggers
            if (l_num_master_ranks > MAX_PRIMARY_RANKS_PER_PORT)
            {
                FAPI_ERR("seeing %d primary ranks on DIMM %s", l_num_master_ranks, mss::c_str(d));
                fapi2::Assert(false);
            }

            FAPI_INF("%s rank config %d drop %d yields max freq attribute index of %d (%d)",
                     mss::c_str(d), l_num_master_ranks, l_dimms_on_port,
                     l_indexes[l_dimms_on_port - 1][l_num_master_ranks - 1],
                     i_max_freqs[l_indexes[l_dimms_on_port - 1][l_num_master_ranks - 1]] );

            l_index = l_indexes[l_dimms_on_port - 1][l_num_master_ranks - 1];

            // Just a quick check but we're in deep yogurt if this triggers
            if (l_index > NUM_MAX_FREQS)
            {
                FAPI_ERR("seeing %d index for %d DIMM and %d ranks on DIMM %s",
                         l_index, l_dimms_on_port, l_num_master_ranks, mss::c_str(d));
                fapi2::Assert(false);
            }

            l_our_max_freq = std::min(l_our_max_freq, i_max_freqs[l_index]);
        }
    }

    FAPI_INF("after processing DIMM, max freq is %d", l_our_max_freq);

    // We need to push things as the memcpy doesn't update the vector's count, etc. and we don't
    // create the vector, we get it passed in. It's not a big deal as we want to touch all the elements
    // to check for 0's anyway.
    for (size_t i = 0; i < NUM_VPD_FREQS; ++i)
    {
        // Funky if-tree makes things clearer than a combinatorialy explosive conditional
        if (i_freqs[i] == 0)
        {
            // Skip 0's
            continue;
        }

        if (i_freqs[i] > l_our_max_freq)
        {
            // Skip freqs larger than our max
            continue;
        }

        // Add this freq if we're not in sync mode, or, if we are add it if it matches a nest freq
        if (!i_req_sync_mode || (i_req_sync_mode && (i_freqs[i] <= fapi2::ENUM_ATTR_MSS_FREQ_MT2400)))
        {
            io_freqs.push_back(i_freqs[i]);
        }
    }

    // We now know io_freqs contains valid frequencies for this DIMM config, system contraints, and sync mode.
    // Sort it so we know supported min is io_freq.begin and supported max is io_freq.end - 1
    std::sort(io_freqs.begin(), io_freqs.end());

    // If we have an empty set, we have a pro'lem
    FAPI_ASSERT(io_freqs.size() != 0,
                fapi2::MSS_VPD_FREQ_MAX_FREQ_EMPTY_SET()
                .set_MSS_VPD_FREQ_0(i_freqs[0])
                .set_MSS_VPD_FREQ_1(i_freqs[1])
                .set_MSS_VPD_FREQ_2(i_freqs[2])
                .set_MSS_VPD_FREQ_3(i_freqs[3])
                .set_MSS_MAX_FREQ_0(i_max_freqs[0])
                .set_MSS_MAX_FREQ_1(i_max_freqs[1])
                .set_MSS_MAX_FREQ_2(i_max_freqs[2])
                .set_MSS_MAX_FREQ_3(i_max_freqs[3])
                .set_MSS_MAX_FREQ_4(i_max_freqs[4])
                .set_REQUIRED_SYNC_MODE(i_req_sync_mode)
                .set_MAX_FREQ_FROM_DIMM(l_our_max_freq)
                .set_MCS_TARGET(i_target),
                "%s didn't find a frequency which was in VPD and was allowable max", mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Return whether a given freq is supported
/// @param[in] a freq to check for
/// @param[in] reference to a std::vector<uint32_t> of freqs
/// @return bool, true iff input freq is supported
///
fapi2::ReturnCode is_freq_supported(const uint32_t i_freq, const std::vector<uint32_t>& i_freqs)
{
    return std::binary_search(i_freqs.begin(), i_freqs.end(), i_freq);
}

}// mss
