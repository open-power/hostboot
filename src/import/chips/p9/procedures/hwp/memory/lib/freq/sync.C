/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/freq/sync.C $   */
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
/// @file sync.C
/// @brief Synchronous function implementations
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#include <fapi2.H>
#include <vpd_access.H>
#include <algorithm>
#include <vector>
#include <map>
#include <mss.H>
#include <lib/freq/sync.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/utils/assert_noexit.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <generic/memory/lib/spd/spd_facade.H>
#include <generic/memory/lib/spd/spd_utils.H>

using fapi2::TARGET_TYPE_DIMM;
using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_SYSTEM;

namespace mss
{

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


    o_freq_map.clear();

    // The find_if loop is meant to find the "first" good (non-zero) freq value
    // so I can compare it against all other freq values from the MCBIST vector
    // I am checking to make sure I don't get a value of 0
    // Since Cronus can hand me back an MCBIST w/no DIMMs
    // Which would give ATTR_MSS_FREQ value of 0 in p9_mss_freq
    uint64_t l_comparator = 0;
    fapi2::ReturnCode l_rc(fapi2::FAPI2_RC_FALSE);

    const auto l_found_comp = std::find_if(i_targets.begin(), i_targets.end(),
                                           [&l_rc, &l_comparator] (const fapi2::Target<TARGET_TYPE_MCBIST>& i_target)->bool
    {
        l_rc = mss::freq(i_target, l_comparator);
        return l_comparator != 0;
    });

    // Getting error cross initializing with the Assert
    // find_if should work if passed in an empty vector. begin() and end() will match and it'll exit without trying freq()
    FAPI_ASSERT( !i_targets.empty(),
                 fapi2::MSS_EMPTY_MCBIST_VECTOR_PASSED(),
                 "Empty MCBIST target vector found when constructing dimm speed mapping!" );


    FAPI_TRY(l_rc, "Failed accessor mss::freq()");

    // If all MCBISTs are 0 we go no further
    // We shouldn't get here though. We check for DIMMS in freq_system. If no DIMMS, we exit
    // We can assume if there is a dimm configured at this point (after mss_freq)
    // It has a valid freq
    // Thus, this shouldn't ever happen, but let's check anyways
    FAPI_ASSERT( l_found_comp != i_targets.end(),
                 fapi2::MSS_ALL_MCBIST_HAVE_0_FREQ()
                 .set_VECTOR_SIZE(i_targets.size()),
                 "All MCBIST have 0 MSS_FREQ, but there are dimms?");

    // DIMM speed is equal until we deduce otherwise
    o_is_speed_equal = speed_equality::EQUAL_DIMM_SPEEDS;

    // Make sure to stick the first one we found in the freq map.
    o_freq_map.emplace( std::make_pair(*l_found_comp, l_comparator) );

    // Loop through all MCBISTs and store dimm speeds
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
    FAPI_ASSERT( o_freq_map.size() != 0,
                 fapi2::MSS_ERROR_FINDING_DIMM_SPEED_MAP(),
                 "freq system freq map is empty? found mcbist: %s",
                 mss::c_str(*l_found_comp) );

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
                              "Deconfiguring %s due to unequal frequencies: mss: %d, nest: %d",
                              mss::c_str(l_mcs),
                              i_dimm_speed,
                              i_nest_freq );
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
/// @param[out] o_selected_nest_freq final freq selected, only valid if final sync mode is in-sync
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode select_sync_mode(const std::map< fapi2::Target<TARGET_TYPE_MCBIST>, uint64_t >& i_freq_map,
                                   const speed_equality i_equal_dimm_speed,
                                   const uint32_t i_nest_freq,
                                   const uint8_t i_required_sync_mode,
                                   uint8_t& o_selected_sync_mode,
                                   uint64_t& o_selected_nest_freq)
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
            o_selected_nest_freq = i_freq_map.begin()->second;

            // When we selected ATTR_MSS_FREQ, we made sure that for forced sync mode cases we didn't
            // select a DIMM freq the nest couldn't support. So if we're in forced sync mode, we're done.
            if (i_required_sync_mode == fapi2::ENUM_ATTR_REQUIRED_SYNCH_MODE_ALWAYS)
            {
                o_selected_sync_mode = fapi2::ENUM_ATTR_MC_SYNC_MODE_IN_SYNC;
                // On Cronus if the o_selected_nest_freq != i_nest_freq we've got a mismatch. Note that p9_mss_freq ensures
                // we don't select an invalid freq, but doesn't ensure we select the current nest freq.
#ifndef __HOSTBOOT_MODULE
                FAPI_ASSERT(o_selected_nest_freq == i_nest_freq,
                            fapi2::MSS_FAILED_SYNC_MODE().set_NEST_FREQ(i_nest_freq).set_MEM_FREQ(o_selected_nest_freq),
                            "Configured in sync mode, but the DIMM freq (%d) and the nest freq (%d) don't align",
                            o_selected_nest_freq, i_nest_freq);
#endif
                return fapi2::FAPI2_RC_SUCCESS;

            }

            // So we need to decide. We know the DIMM speeds are equal and we know we picked the fastest supportable
            // speed. So, if we're within the nest frequencies then we can run sync mode.
            // If we're outside of the nest frequencies we'll run async (highest DIMM speed.)
            // Remember, if sync_mode is set to not_in_sync, o_selected_nest_freq is ignored

#ifdef __HOSTBOOT_MODULE
            // Can only change nest freq on HB modules
            // If the freq from the DIMM is supported by the nest, we're good
            o_selected_sync_mode = is_nest_freq_valid(o_selected_sync_mode) ? fapi2::ENUM_ATTR_MC_SYNC_MODE_IN_SYNC :
                                   fapi2::ENUM_ATTR_MC_SYNC_MODE_NOT_IN_SYNC;
#else
            // Can't change nest freq in cronus
            o_selected_sync_mode = (o_selected_nest_freq == i_nest_freq) ?
                                   fapi2::ENUM_ATTR_MC_SYNC_MODE_IN_SYNC : fapi2::ENUM_ATTR_MC_SYNC_MODE_NOT_IN_SYNC;
#endif
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
                o_selected_nest_freq = l_max_dimm_speed;
                return fapi2::FAPI2_RC_SUCCESS;
            }

#else
            // Cronus only
            FAPI_ASSERT(i_required_sync_mode != fapi2::ENUM_ATTR_REQUIRED_SYNCH_MODE_ALWAYS,
                        fapi2::MSS_FAILED_SYNC_MODE().set_NEST_FREQ(i_nest_freq),
                        "Seeing forced nest/memory sync mode but DIMM speeds differ from nest speed %d", i_nest_freq);
#endif

            // Notice that if we don't have equal DIMM speeds we're never in sync. We either error out (Cronus)
            // or we toss a bunch of DIMM off the boat (f/w) or they didn't care whether we were sync or not.
            o_selected_sync_mode = fapi2::ENUM_ATTR_MC_SYNC_MODE_NOT_IN_SYNC;
            return fapi2::FAPI2_RC_SUCCESS;
            break;

        default:
            // Switches on an enum class
            // The only valid speed_equality values are NOT_EQUAL and EQUAL.
            // If it's something else ,I think it's a code error and really shouldn't be possible, thus fapi2::Assert below
            FAPI_ERR("Invalid speed_equality parameter!");
            fapi2::Assert(false);
            break;
    }// end switch

    return fapi2::FAPI2_RC_SUCCESS;

#ifndef __HOSTBOOT_MODULE
fapi_try_exit:
    return fapi2::current_err;
#endif
}

///
/// @brief Create a vector of support freq based on VPD config
/// @param[in] i_target MCBIST target for which to get the DIMM configs
/// @param[out] o_vpd_supported_freqs reference to a 2 dimensional vector of supported VPD frequencies for each MCA
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode vpd_supported_freqs( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
                                       std::vector<std::vector<uint32_t>>& o_vpd_supported_freqs)
{
    uint8_t l_rank_count_dimm[MAX_DIMM_PER_PORT] = {};
    uint8_t l_mr_blob[mss::VPD_KEYWORD_MAX] = {};

    // This bitmap will keep track of the ports we visit.
    // Any we don't are not configured, so will support all frequencies in the scoreboard
    fapi2::buffer<uint8_t> configured_ports;

    // Clearing output Just.In.Case
    o_vpd_supported_freqs.clear();

    for ( size_t l_index = 0; l_index < PORTS_PER_MCBIST; ++l_index )
    {
        o_vpd_supported_freqs.push_back(std::vector<uint32_t>());
    }

    fapi2::VPDInfo<fapi2::TARGET_TYPE_MCS> l_vpd_info(fapi2::MemVpdData::MR);

    for( const auto& mcs : mss::find_targets<TARGET_TYPE_MCS>(i_target) )
    {
        for( const auto& p : mss::find_targets<TARGET_TYPE_MCA>(mcs) )
        {
            const auto l_port_pos = mss::relative_pos<fapi2::TARGET_TYPE_MCBIST>(p);
            FAPI_TRY( configured_ports.setBit(l_port_pos) );

            if( mss::count_dimm(p) == 0 )
            {
                // Cronus lets you have an MCA w/no DIMMs. In this case, we say the port supports all frequencies
                for( const auto& freq : NIMBUS_SUPPORTED_FREQS )
                {
                    o_vpd_supported_freqs[l_port_pos].push_back(freq);
                }

                continue;
            }

            FAPI_TRY( mss::eff_num_master_ranks_per_dimm(p, &(l_rank_count_dimm[0])) );

            l_vpd_info.iv_rank_count_dimm_0 = l_rank_count_dimm[0];
            l_vpd_info.iv_rank_count_dimm_1 = l_rank_count_dimm[1];
            l_vpd_info.iv_is_config_ffdc_enabled = false;

            // Iterate through all Nimbus supported freqs
            for( const auto& freq : NIMBUS_SUPPORTED_FREQS )
            {
                l_vpd_info.iv_freq_mhz = freq;

                FAPI_INF("%s. VPD info - frequency: %d MT/s, rank count for dimm_0: %d, dimm_1: %d",
                         mss::c_str(p), l_vpd_info.iv_freq_mhz, l_vpd_info.iv_rank_count_dimm_0, l_vpd_info.iv_rank_count_dimm_1);

                // In order to retrieve the VPD contents we first need the keyword size.
                // If we are unable to retrieve the keyword size then this speed isn't
                // supported in the VPD in Cronus (but not FW) and we skip to the next
                // possible speed bin.
                if(  fapi2::getVPD(mcs, l_vpd_info, nullptr) != fapi2::FAPI2_RC_SUCCESS )
                {
                    FAPI_INF("Couldn't retrieve MR size from VPD for this config %s -- skipping freq %d MT/s", mss::c_str(p), freq );

                    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
                    continue;
                }

                FAPI_ASSERT( l_vpd_info.iv_size <= mss::VPD_KEYWORD_MAX,
                             fapi2::MSS_INVALID_VPD_KEYWORD_MAX().
                             set_MAX(mss::VPD_KEYWORD_MAX).
                             set_ACTUAL(l_vpd_info.iv_size).
                             set_KEYWORD(fapi2::MemVpdData::MR).
                             set_MCS_TARGET(i_target),
                             "VPD MR keyword size retrieved: %d, is larger than max: %d for %s",
                             l_vpd_info.iv_size, mss::VPD_KEYWORD_MAX, mss::c_str(i_target));

                // Firmware doesn't do the VPD lookup in the size check so repeat the logic here
                if(  fapi2::getVPD(mcs, l_vpd_info, &(l_mr_blob[0])) != fapi2::FAPI2_RC_SUCCESS )
                {
                    FAPI_INF("Couldn't retrieve MR data from VPD for this config %s -- skipping freq %d MT/s", mss::c_str(p), freq );

                    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
                    continue;
                }

                // Add supported freqs to our output
                FAPI_INF("VPD supported freq added: %d for %s", freq, mss::c_str(p) );
                o_vpd_supported_freqs[l_port_pos].push_back(freq);
            }// freqs
        }// mca
    }//mcs

    // Mark any ports we didn't visit as supporting all frequencies
    for ( uint64_t l_port_pos = 0; l_port_pos < PORTS_PER_MCBIST; ++l_port_pos )
    {
        if ( !configured_ports.getBit(l_port_pos) )
        {
            for ( const auto l_freq : NIMBUS_SUPPORTED_FREQS )
            {
                o_vpd_supported_freqs[l_port_pos].push_back(l_freq);
            }
        }
    }

    for ( auto& l_freqs : o_vpd_supported_freqs )
    {
        std::sort( l_freqs.begin(), l_freqs.end() );
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Retrieves max frequency each port supports due to DIMM SPD
/// @param[in] i_target the MCBIST target
/// @param[out] o_supported_freqs reference to vector of max SPD supported freq for each port
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode spd_supported_freq(const fapi2::Target<TARGET_TYPE_MCBIST>& i_target,
                                     std::vector<uint32_t>& o_supported_freqs)
{
    uint64_t l_largest_tck = 0;

    // Start with a really high value so we can use std::min to reduce it below
    o_supported_freqs = std::vector<uint32_t>(PORTS_PER_MCBIST, ~(0));

    // Get cached decoder
    std::vector< mss::spd::facade > l_spd_facades;
    FAPI_TRY( get_spd_decoder_list(i_target, l_spd_facades), "%s get decoder - spd", mss::c_str(i_target) );

    // Looking for the biggest application period on an MC.
    // This will further reduce supported frequencies the system can run on.
    for ( const auto& l_cache : l_spd_facades )
    {
        const auto l_dimm = l_cache.get_dimm_target();
        const auto l_mca = mss::find_target<TARGET_TYPE_MCA>(l_dimm);
        const auto l_port_pos = mss::relative_pos<fapi2::TARGET_TYPE_MCBIST>(l_mca);
        uint64_t l_tckmax_in_ps = 0;
        uint64_t l_tck_min_in_ps = 0;
        uint32_t l_dimm_freq = 0;

        FAPI_TRY( spd::get_tckmax(l_cache, l_tckmax_in_ps),
                  "%s. Failed to get tCKmax", mss::c_str(l_dimm) );
        FAPI_TRY( spd::get_tckmin(l_cache, l_tck_min_in_ps),
                  "%s. Failed to get tCKmin", mss::c_str(l_dimm) );

        // Determine a proposed tCK value that is greater than or equal tCKmin
        // But less than tCKmax
        l_largest_tck = std::max(l_largest_tck, l_tck_min_in_ps);
        l_largest_tck = std::min(l_largest_tck, l_tckmax_in_ps);

        FAPI_TRY( mss::ps_to_freq(l_largest_tck, l_dimm_freq), "%s ps to freq %lu", mss::c_str(i_target), l_largest_tck );
        FAPI_INF("Biggest freq supported from SPD %d MT/s for %s",
                 l_dimm_freq, mss::c_str(l_dimm));

        o_supported_freqs[l_port_pos] = std::min(l_dimm_freq, o_supported_freqs[l_port_pos]);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Create and sort a vector of supported MT/s (freq)
/// @param[in] i_target MCBIST target for which to get the DIMM configs
/// @param[out] o_freqs reference to a std::vector to put the sorted vector
/// @return FAPI2_RC_SUCCESS iff ok
/// @note Taken from VPD supported freqs. The result is sorted so such that the min
/// supported freq is std::vector<>.begin and the max is std::vector<>.end - 1. You can
/// search the resulting vector for valid frequencies as it is sorted.
///
fapi2::ReturnCode supported_freqs(const fapi2::Target<TARGET_TYPE_MCBIST>& i_target,
                                  std::vector<uint32_t>& o_freqs)
{
    o_freqs.clear();

    freq_scoreboard l_scoreboard;
    std::vector<uint32_t> l_max_freqs(NUM_MAX_FREQS, 0);
    std::vector<std::vector<uint32_t>> l_vpd_supported_freqs;
    std::vector<uint32_t> l_spd_supported_freq(NUM_MAX_FREQS, 0);
    uint8_t l_req_sync_mode = 0;
    std::vector<uint8_t> l_deconfigured = {0};

    // Retrieve system MRW, SPD, and VPD constraints
    FAPI_TRY( mss::max_allowed_dimm_freq(l_max_freqs.data()), "%s max_allowed_dimm_freq", mss::c_str(i_target) );
    FAPI_TRY( spd_supported_freq(i_target, l_spd_supported_freq), "%s spd supported freqs", mss::c_str(i_target) );
    FAPI_TRY( vpd_supported_freqs(i_target, l_vpd_supported_freqs), "%s vpd supported freqs", mss::c_str(i_target) );

    // Limit frequency scoreboard according to MRW constraints
    FAPI_TRY( limit_freq_by_mrw(i_target, l_max_freqs, l_scoreboard) );

    // Limit frequency scoreboard according to VPD constraints
    FAPI_TRY( limit_freq_by_vpd(i_target, l_vpd_supported_freqs, l_scoreboard) );

    // Limit frequency scoreboard according to SPD (DIMM) constraints
    FAPI_TRY( limit_freq_by_spd(i_target, l_spd_supported_freq, l_scoreboard) );

    // Callout the fewest number of MCAs to achieve a common shared freq
    FAPI_TRY( mss::required_synch_mode(l_req_sync_mode) );
    FAPI_TRY( l_scoreboard.resolve(i_target,
                                   l_req_sync_mode == fapi2::ENUM_ATTR_REQUIRED_SYNCH_MODE_ALWAYS,
                                   l_vpd_supported_freqs,
                                   l_deconfigured,
                                   o_freqs) );

    FAPI_INF("%s supported freqs:", mss::c_str(i_target));

    for (const auto l_freq : o_freqs)
    {
        FAPI_INF("%s            %d", mss::c_str(i_target), l_freq);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Update supported frequency scoreboard according to MRW/config limits
/// @param[in] i_target MCBIST target for which to get the DIMM configs
/// @param[in] i_max_mrw_freqs vector of max allowed freqs
/// @param[in,out] io_scoreboard scoreboard of MCA targets supporting each frequency
/// @return FAPI2_RC_SUCCESS iff ok
/// @note This helper allows us to use the attributes for the main path but
/// have a path for testing
///
fapi2::ReturnCode limit_freq_by_mrw(const fapi2::Target<TARGET_TYPE_MCBIST>& i_target,
                                    const std::vector<uint32_t>& i_max_mrw_freqs,
                                    freq_scoreboard& io_scoreboard)
{
    // Indexes into the ATTR_MAX_ALLOWED_DIMM_FREQ arrary. e.g., [0][0] is 1R 1 drop
    constexpr size_t l_indexes[MAX_DIMM_PER_PORT][MAX_PRIMARY_RANKS_PER_PORT] =
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
                 .set_MCA_TARGET(i_target),
                 "%s Incorrect number of max frequencies in attribute for (%d)",
                 mss::c_str(i_target),
                 i_max_mrw_freqs.size());

    FAPI_INF("attribute supported max allowed dimm freqs %d %d %d %d %d for %s",
             i_max_mrw_freqs[0], i_max_mrw_freqs[1], i_max_mrw_freqs[2], i_max_mrw_freqs[3], i_max_mrw_freqs[4],
             mss::c_str(i_target));

    for( const auto& p : mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target) )
    {
        const auto l_port_pos = mss::relative_pos<fapi2::TARGET_TYPE_MCBIST>(p);
        const auto l_dimms = mss::find_targets<TARGET_TYPE_DIMM>(p);
        const uint64_t l_dimms_on_port = l_dimms.size();

        // Holds the max freq allowed for this port. This is the minimum of maximum
        // frequencies allowed by the DIMM. So, we start way off the charts so std::min can do the lifting for us.
        uint32_t l_mca_max_freq = ~(0);

        FAPI_ASSERT( (l_dimms_on_port <= MAX_DIMM_PER_PORT),
                     fapi2::MSS_TOO_MANY_DIMMS_ON_PORT()
                     .set_DIMM_COUNT(l_dimms_on_port)
                     .set_MCA_TARGET(p),
                     "Seeing %d DIMM on port %s",
                     l_dimms_on_port,
                     mss::c_str(p));

        // Find the max supported frequency for this port
        for (const auto& d : l_dimms)
        {
            uint8_t l_num_master_ranks = 0;
            size_t l_index = 0xFF;

            FAPI_TRY( mss::eff_num_master_ranks_per_dimm(d, l_num_master_ranks) );

            // Just a quick check but we're in deep yogurt if this triggers
            FAPI_ASSERT( (l_num_master_ranks <= MAX_PRIMARY_RANKS_PER_PORT),
                         fapi2::MSS_TOO_MANY_PRIMARY_RANKS_ON_DIMM()
                         .set_RANK_COUNT(l_num_master_ranks)
                         .set_DIMM_TARGET(d),
                         "seeing %d primary ranks on DIMM %s",
                         l_dimms_on_port,
                         mss::c_str(d));

            l_index = l_indexes[l_dimms_on_port - 1][l_num_master_ranks - 1];

            FAPI_ASSERT( (l_index < NUM_MAX_FREQS),
                         fapi2::MSS_FREQ_INDEX_TOO_LARGE()
                         .set_INDEX(l_index)
                         .set_NUM_MAX_FREQS(NUM_MAX_FREQS),
                         "seeing %d index for %d DIMM and %d ranks on DIMM %s",
                         l_index,
                         l_dimms_on_port,
                         l_num_master_ranks,
                         mss::c_str(d));

            FAPI_INF("%s rank config %d drop %d yields max freq attribute index of %d (%d)",
                     mss::c_str(d), l_num_master_ranks, l_dimms_on_port,
                     l_indexes[l_dimms_on_port - 1][l_num_master_ranks - 1],
                     i_max_mrw_freqs[l_index] );

            l_mca_max_freq = std::min(l_mca_max_freq, i_max_mrw_freqs[l_index]);
        }// dimm

        // Remove any frequencies bigger than this port's max from the scoreboard
        io_scoreboard.remove_freqs_above_limit(l_port_pos, l_mca_max_freq);

        FAPI_INF("%s after processing MRW, max freq is %d", mss::c_str(p), l_mca_max_freq);
    }// mca

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Update supported frequency scoreboard according to VPD limits
/// @param[in] i_target MCBIST target for which to get the DIMM configs
/// @param[in] i_hw_freqs vector of hardware supported freqs -- from VPD
/// @param[in,out] io_scoreboard scoreboard of MCA targets supporting each frequency
/// @return FAPI2_RC_SUCCESS iff ok
/// @note This helper allows us to use the attributes for the main path but
/// have a path for testing
///
fapi2::ReturnCode limit_freq_by_vpd(const fapi2::Target<TARGET_TYPE_MCBIST>& i_target,
                                    const std::vector<std::vector<uint32_t>>& i_hw_freqs,
                                    freq_scoreboard& io_scoreboard)
{
    FAPI_ASSERT(i_hw_freqs.size() == PORTS_PER_MCBIST,
                fapi2::MSS_INVALID_VPD_FREQ_LIST_PASSED()
                .set_SIZE(i_hw_freqs.size())
                .set_EXPECTED(PORTS_PER_MCBIST),
                "Wrong size VPD frequency vector passed to limit_freq_by_vpd (got %d, expected %d)",
                i_hw_freqs.size(), PORTS_PER_MCBIST);

    for( const auto& p : mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target) )
    {
        const auto l_port_pos = mss::relative_pos<fapi2::TARGET_TYPE_MCBIST>(p);
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
    }// mca

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Update supported frequency scoreboard according to SPD limits
/// @param[in] i_target MCBIST target for which to get the DIMM configs
/// @param[in] i_hw_freqs vector of hardware supported freqs -- from SPD
/// @param[in,out] io_scoreboard scoreboard of MCA targets supporting each frequency
/// @return FAPI2_RC_SUCCESS iff ok
/// @note This helper allows us to use the attributes for the main path but
/// have a path for testing
///
fapi2::ReturnCode limit_freq_by_spd(const fapi2::Target<TARGET_TYPE_MCBIST>& i_target,
                                    const std::vector<uint32_t>& i_hw_freqs,
                                    freq_scoreboard& io_scoreboard)
{
    for( const auto& p : mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target) )
    {
        const auto l_port_pos = mss::relative_pos<fapi2::TARGET_TYPE_MCBIST>(p);

        // Remove any frequencies that aren't in this port's list from the scoreboard
        io_scoreboard.remove_freqs_above_limit(l_port_pos, i_hw_freqs);

        uint32_t l_max_freq = 0;
        FAPI_TRY( io_scoreboard.max_supported_freq(l_port_pos, l_max_freq) );
        FAPI_INF("%s after processing SPD, max freq is %d", mss::c_str(p), l_max_freq);
    }// mca

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Remove frequencies above a limit from the scoreboard
/// @param[in] i_port_pos position index of port within parent MCBIST
/// @param[in] i_freq_limit upper limit for frequency
/// @return FAPI2_RC_SUCCESS if successful
///
fapi2::ReturnCode freq_scoreboard::remove_freqs_above_limit(const uint64_t i_port_pos,
        const uint32_t i_freq_limit)
{
    FAPI_ASSERT(i_port_pos < PORTS_PER_MCBIST,
                fapi2::MSS_INVALID_PORT_INDEX_PASSED()
                .set_INDEX(i_port_pos)
                .set_FUNCTION(ffdc_function_codes::FREQ_SCOREBOARD_REMOVE_FREQS_ABOVE_LIMIT),
                "Invalid port index passed to remove_freqs_above_limit (%d)",
                i_port_pos);

    {
        auto& l_port_supported_freqs = iv_freq_mca_supported[i_port_pos];

        // Can't do a ranged for loop here because we need the index to get the frequency out of NIMBUS_SUPPORTED_FREQS
        for ( size_t l_index = 0; l_index < l_port_supported_freqs.size(); ++l_index )
        {
            const auto l_scoreboard_freq = NIMBUS_SUPPORTED_FREQS[l_index];

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
    FAPI_ASSERT(i_port_pos < PORTS_PER_MCBIST,
                fapi2::MSS_INVALID_PORT_INDEX_PASSED()
                .set_INDEX(i_port_pos)
                .set_FUNCTION(ffdc_function_codes::FREQ_SCOREBOARD_REMOVE_FREQS_ABOVE_LIMIT_VECTOR),
                "Invalid port index passed to remove_freqs_above_limit (%d)",
                i_port_pos);

    FAPI_ASSERT(i_freq_limits.size() == PORTS_PER_MCBIST,
                fapi2::MSS_INVALID_FREQ_LIST_PASSED()
                .set_SIZE(i_freq_limits.size())
                .set_EXPECTED(PORTS_PER_MCBIST),
                "Invalid frequency list passed to remove_freqs_above_limit (size should be %d but got %d)",
                PORTS_PER_MCBIST, i_freq_limits.size());

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
/// @param[in] i_port_pos position index of port within parent MCBIST
/// @param[in] i_freq_list vector of supported frequencies
/// @return FAPI2_RC_SUCCESS if successful
///
fapi2::ReturnCode freq_scoreboard::remove_freqs_not_on_list(const uint64_t i_port_pos,
        const std::vector<uint32_t>& i_freq_list)
{
    FAPI_ASSERT(i_port_pos < PORTS_PER_MCBIST,
                fapi2::MSS_INVALID_PORT_INDEX_PASSED()
                .set_INDEX(i_port_pos)
                .set_FUNCTION(ffdc_function_codes::FREQ_SCOREBOARD_REMOVE_FREQS_NOT_ON_LIST),
                "Invalid port index passed to remove_freqs_not_on_list (%d)",
                i_port_pos);

    for ( size_t l_index = 0; l_index < NIMBUS_SUPPORTED_FREQS.size(); ++l_index )
    {
        const auto l_it = std::find(i_freq_list.begin(), i_freq_list.end(), NIMBUS_SUPPORTED_FREQS[l_index]);

        if (l_it == i_freq_list.end())
        {
            FAPI_INF("Removing freq %d on port %d since it's not supported", NIMBUS_SUPPORTED_FREQS[l_index], i_port_pos);
            iv_freq_mca_supported[i_port_pos][l_index] = false;
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
fapi2::ReturnCode freq_scoreboard::max_supported_freq(const uint64_t i_port_pos,
        uint32_t& o_freq) const
{
    FAPI_ASSERT(i_port_pos < PORTS_PER_MCBIST,
                fapi2::MSS_INVALID_PORT_INDEX_PASSED()
                .set_INDEX(i_port_pos)
                .set_FUNCTION(ffdc_function_codes::FREQ_SCOREBOARD_MAX_SUPPORTED_FREQ),
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
    FAPI_ASSERT(i_port_pos < PORTS_PER_MCBIST,
                fapi2::MSS_INVALID_PORT_INDEX_PASSED()
                .set_INDEX(i_port_pos)
                .set_FUNCTION(ffdc_function_codes::FREQ_SCOREBOARD_SUPPORTED_FREQS),
                "Invalid port index passed to supported_freqs (%d)",
                i_port_pos);

    {
        o_freqs.clear();
        auto& l_port_supported_freqs = iv_freq_mca_supported[i_port_pos];

        for ( size_t l_index = 0; l_index < NIMBUS_SUPPORTED_FREQS.size(); ++l_index )
        {
            if (l_port_supported_freqs[l_index])
            {
                o_freqs.push_back(NIMBUS_SUPPORTED_FREQS[l_index]);
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
/// @param[in] i_target MCBIST target
/// @param[in] i_req_sync_mode bool whether or not we're forced into sync mode
/// @param[in] i_vpd_supported_freqs vector of hardware supported freqs -- from VPD
/// @param[out] o_deconfigured vector of port positions that were deconfigured by this function
/// @param[out] o_freqs vector of frequencies supported by all ports
/// @return FAPI2_RC_SUCCESS if successful
///
fapi2::ReturnCode freq_scoreboard::resolve(const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
        const bool i_req_sync_mode,
        const std::vector<std::vector<uint32_t>>& i_vpd_supported_freqs,
        std::vector<uint8_t>& o_deconfigured,
        std::vector<uint32_t>& o_freqs)
{
    // This vector will hold the number of ports that support each frequency in NIMBUS_SUPPORTED_FREQS
    std::vector<uint64_t> l_support_counts(NIMBUS_SUPPORTED_FREQS.size(), 0);

    o_freqs.clear();
    FAPI_INF("%s Attribute required sync mode %d", mss::c_str(i_target), i_req_sync_mode);

    const auto l_mcas = mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target);
    const auto l_port_count = l_mcas.size();

    // empty_port_count is the number of MCA that are deconfigured
    // We use it later to make sure our common freq is supported by at least one configured port
    const auto l_empty_port_count = PORTS_PER_MCBIST - l_port_count;

    // Get a count of how many ports support each frequency
    for ( size_t l_index = 0; l_index < NIMBUS_SUPPORTED_FREQS.size(); ++l_index )
    {
        size_t l_pos = 0;

        for ( const auto& l_supported : iv_freq_mca_supported )
        {
            if (l_supported[l_index])
            {
                FAPI_INF("%s Frequency %d is supported by port%d", mss::c_str(i_target), NIMBUS_SUPPORTED_FREQS[l_index], l_pos);
                // Add this freq if we're not in sync mode, or, if we are, add it if it matches a nest freq

                if( i_req_sync_mode && !is_nest_freq_valid(NIMBUS_SUPPORTED_FREQS[l_index]) )
                {
                    FAPI_INF("%s Frequency %d is not supported by the nest logic", mss::c_str(i_target), NIMBUS_SUPPORTED_FREQS[l_index]);
                    ++l_pos;
                    continue;
                }

                ++l_support_counts[l_index];
            }

            // Add any frequencies supported by all configured ports to our output list
            // Note that deconfigured ports will support all frequencies due to the way the scoreboard is built
            if (l_support_counts[l_index] == PORTS_PER_MCBIST)
            {
                FAPI_INF("%s Frequency %d is supported by all ports", mss::c_str(i_target), NIMBUS_SUPPORTED_FREQS[l_index]);
                o_freqs.push_back(NIMBUS_SUPPORTED_FREQS[l_index]);
            }

            ++l_pos;
        }
    }

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
    FAPI_INF("%s Fastest common frequency is %d", mss::c_str(i_target), NIMBUS_SUPPORTED_FREQS[l_best_freq_index]);

    // Assert if we don't have any frequencies supported by at least one configured port
    // Note: we know max_allowed_dimm_freq is size 5 because we checked it in limit_freq_by_mrw
    std::vector<uint32_t> l_max_mrw_freqs(NUM_MAX_FREQS, 0);
    FAPI_TRY( mss::max_allowed_dimm_freq(l_max_mrw_freqs.data()) );
    FAPI_ASSERT(l_common_ports > l_empty_port_count,
                fapi2::MSS_NO_SUPPORTED_FREQ()
                .set_REQUIRED_SYNC_MODE(i_req_sync_mode)
                .set_MCBIST_TARGET(i_target)
                .set_NUM_PORTS(l_port_count)
                .set_MRW_MAX_FREQ_0(l_max_mrw_freqs[0])
                .set_MRW_MAX_FREQ_1(l_max_mrw_freqs[1])
                .set_MRW_MAX_FREQ_2(l_max_mrw_freqs[2])
                .set_MRW_MAX_FREQ_3(l_max_mrw_freqs[3])
                .set_MRW_MAX_FREQ_4(l_max_mrw_freqs[4]),
                "%s didn't find a frequency that was supported on any ports", mss::c_str(i_target));

    // Now find and deconfigure all ports that don't support our selected frequency
    o_deconfigured.clear();

    for ( size_t l_pos = 0; l_pos < PORTS_PER_MCBIST; ++l_pos )
    {
        // Find the MCA with this position
        const auto l_it_mca = std::find_if(l_mcas.begin(),
                                           l_mcas.end(),
                                           [l_pos]( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_rhs) -> bool
        {
            return (mss::relative_pos<fapi2::TARGET_TYPE_MCBIST>(i_rhs) != l_pos);
        });

        // If we didn't find an MCA for a given position, there wasn't one configured there
        if (l_it_mca == l_mcas.end())
        {
            continue;
        }

        // and call it out if it doesn't support the selected freq
        const auto& p = *l_it_mca;
        FAPI_INF("Checking if port %d (%s) supports common frequency", l_pos, mss::c_str(p));

        if (!iv_freq_mca_supported[l_pos][l_best_freq_index])
        {
            FAPI_INF("Port %d (%s) does not support the common frequency so will be deconfigured", l_pos, mss::c_str(p));
            auto& l_port_supported_freqs = iv_freq_mca_supported[l_pos];

            o_deconfigured.push_back(l_pos);
            FAPI_ASSERT_NOEXIT( false,
                                fapi2::MSS_PORT_DOES_NOT_SUPPORT_MAJORITY_FREQ()
                                .set_MCBIST_TARGET(i_target)
                                .set_MCA_TARGET(p)
                                .set_FREQUENCY(NIMBUS_SUPPORTED_FREQS[l_best_freq_index]),
                                "%s does not support the majority frequency (%d) so will be deconfigured",
                                mss::c_str(p), NIMBUS_SUPPORTED_FREQS[l_best_freq_index] );

            // Now mark all frequencies as supported by that port since it was deconfigured
            for ( size_t l_index = 0; l_index < l_port_supported_freqs.size(); ++l_index )
            {
                l_port_supported_freqs[l_index] = true;
            }
        }
    }

    // Now find all the frequencies supported by the ports that are left over
    FAPI_TRY(this->resolve(i_target, i_req_sync_mode, i_vpd_supported_freqs, o_deconfigured, o_freqs));

#ifndef __HOSTBOOT_MODULE

    // Cronus doesn't deconfigure, so let's bail out if we didn't find a common frequency
    if (!o_deconfigured.empty())
    {
        std::vector<uint32_t> l_port_vpd_max_freq;

        {
            // Get the max freq supported on each port
            for ( const auto& l_port_supported_freqs : i_vpd_supported_freqs )
            {
                l_port_vpd_max_freq.push_back(l_port_supported_freqs.back());
            }

            FAPI_ASSERT(false,
                        fapi2::MSS_MRW_FREQ_MAX_FREQ_EMPTY_SET()
                        .set_MSS_VPD_FREQ_0(l_port_vpd_max_freq[0])
                        .set_MSS_VPD_FREQ_1(l_port_vpd_max_freq[1])
                        .set_MSS_VPD_FREQ_2(l_port_vpd_max_freq[2])
                        .set_MSS_VPD_FREQ_3(l_port_vpd_max_freq[3])
                        .set_MSS_VPD_FREQ_4(l_port_vpd_max_freq[4])
                        .set_MSS_VPD_FREQ_5(l_port_vpd_max_freq[5])
                        .set_MSS_VPD_FREQ_6(l_port_vpd_max_freq[6])
                        .set_MSS_VPD_FREQ_7(l_port_vpd_max_freq[7])
                        .set_MSS_MAX_FREQ_0(l_max_mrw_freqs[0])
                        .set_MSS_MAX_FREQ_1(l_max_mrw_freqs[1])
                        .set_MSS_MAX_FREQ_2(l_max_mrw_freqs[2])
                        .set_MSS_MAX_FREQ_3(l_max_mrw_freqs[3])
                        .set_MSS_MAX_FREQ_4(l_max_mrw_freqs[4])
                        .set_MSS_NEST_FREQ_0(fapi2::ENUM_ATTR_FREQ_PB_MHZ_1600)
                        .set_MSS_NEST_FREQ_1(fapi2::ENUM_ATTR_FREQ_PB_MHZ_1866)
                        .set_MSS_NEST_FREQ_2(fapi2::ENUM_ATTR_FREQ_PB_MHZ_2000)
                        .set_MSS_NEST_FREQ_3(fapi2::ENUM_ATTR_FREQ_PB_MHZ_2133)
                        .set_MSS_NEST_FREQ_4(fapi2::ENUM_ATTR_FREQ_PB_MHZ_2400)
                        .set_REQUIRED_SYNC_MODE(i_req_sync_mode)
                        .set_MCBIST_TARGET(i_target),
                        "%s didn't find a common frequency for all ports", mss::c_str(i_target));
        }
    }

#endif

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

}// mss
