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
#include <lib/spd/spd_factory.H>
#include <lib/utils/count_dimm.H>

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
/// @brief Return whether a given freq is supported
/// @param[in] a freq to check for
/// @param[in] reference to a std::vector of supported freqs (sorted)
/// @return bool, true iff input freq is supported
///
bool is_freq_supported(const uint32_t i_freq, const std::vector<uint32_t>& i_freqs)
{
    return std::binary_search(i_freqs.begin(), i_freqs.end(), i_freq);
}

///
/// @brief Create a vector of support freq based on VPD config
/// @param[in] MCBIST target for which to get the DIMM configs
/// @param[out] reference to a std::vector of supported VPD frequencies
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode vpd_supported_freqs( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
                                       std::vector<uint32_t>& o_vpd_supported_freqs)
{
    uint8_t l_rank_count_dimm[MAX_DIMM_PER_PORT] = {};
    uint8_t l_mr_blob[mss::VPD_KEYWORD_MAX] = {};
    bool is_first_supported_freq = true;

    // Clearing output Just.In.Case
    o_vpd_supported_freqs.clear();

    fapi2::VPDInfo<fapi2::TARGET_TYPE_MCS> l_vpd_info(fapi2::MemVpdData::MR);

    for( const auto& mcs : mss::find_targets<TARGET_TYPE_MCS>(i_target) )
    {
        for( const auto& p : mss::find_targets<TARGET_TYPE_MCA>(mcs) )
        {
            if( mss::count_dimm(p) == 0 )
            {
                // Cronus lets you have an MCA w/no DIMMs...
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
                // If we are unable to retrieve the keyword size then this speed isn't supported in the VPD
                // and we skip to the next possible speed bin.
                if(  fapi2::getVPD(mcs, l_vpd_info, nullptr) != fapi2::FAPI2_RC_SUCCESS )
                {
                    FAPI_INF("Couldn't retrieve MR size from VPD for this config %s -- skipping freq %d MT/s", mss::c_str(p), freq );

                    // If we added a freq that was supported in one MCA, but isn't supported for
                    // another MCA under the same MCBIST (such as one port running single drop and another dual drop),
                    // we remove it from the VPD supported freq list.
                    auto l_it = std::find(o_vpd_supported_freqs.begin(), o_vpd_supported_freqs.end(), freq);

                    if( l_it != o_vpd_supported_freqs.end()  )
                    {
                        o_vpd_supported_freqs.erase(l_it);
                    }

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

                // If we are here then we should have a valid frequency selected from polling the VPD keyword size above.
                // A hard-fail here means something is wrong and we want to return current_err instead of ignoring it.
                // We turn on FFDC logging here because this is a real fail if we can't read valid VPD, we don't want
                // to return a useless FAPI2_RC_FALSE that FW doesn't know what to do with.
                l_vpd_info.iv_is_config_ffdc_enabled = true;
                FAPI_TRY( fapi2::getVPD(mcs, l_vpd_info, &(l_mr_blob[0])),
                          "Failed to retrieve VPD data for %s", mss::c_str(mcs) );

                // Add non-repeating supported freqs
                auto l_it = std::find(o_vpd_supported_freqs.begin(), o_vpd_supported_freqs.end(), freq);

                if( l_it == o_vpd_supported_freqs.end() || is_first_supported_freq )
                {
                    is_first_supported_freq = false;
                    FAPI_INF("VPD supported freq added: %d for %s", freq, mss::c_str(p) );
                    o_vpd_supported_freqs.push_back(freq);
                }
            }// freqs
        }// mca
    }//mcs

    std::sort( o_vpd_supported_freqs.begin(), o_vpd_supported_freqs.end() );

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Removes frequencies unsupported by SPD from a sorted list of supported freqs -- helper function for testing
/// @param[in] i_target the MCBIST target
/// @param[in] i_highest_freq largest SPD supported freq
/// @param[in,out] io_freqs std::vector of VPD supported freqs (sorted)
///
void rm_unsupported_spd_freqs(const fapi2::Target<TARGET_TYPE_MCBIST>& i_target,
                              const uint32_t i_highest_freq,
                              std::vector<uint32_t>& io_freqs)
{

    // Don't use 'auto' since I want a const iterator and HB compiler
    // bombs out using 'const auto'...
    // The idea here is that if SPD across and MC can only support 2133 MT/s,
    // we remove any supported frequencies in the vector higher than that (e.g. 2400, 2666)
    auto it = std::upper_bound(io_freqs.begin(), io_freqs.end(), i_highest_freq);

    // Remove all frequencies higher than max supported SPD freq per MCBIST
    // since we set freq at that level
    if( it != io_freqs.end() )
    {
        io_freqs.erase(it, io_freqs.end());
    }

    return;
}

///
/// @brief Retrieves largest supported frequency the MC supports due to DIMM SPD
/// @param[in] i_target the MCBIST target
/// @param[out] o_highest_freq the largest SPD supported freq
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode largest_spd_supported_freq(const fapi2::Target<TARGET_TYPE_MCBIST>& i_target,
        uint32_t& o_highest_freq)
{
    uint64_t l_largest_tck = 0;

    // Get cached decoder
    std::vector< std::shared_ptr<mss::spd::decoder> > l_factory_caches;

    FAPI_TRY( mss::spd::populate_decoder_caches(i_target, l_factory_caches),
              "%s. Failed to populate decoder cache", mss::c_str(i_target) );

    // Looking for the biggest application period on an MC.
    // This will further reduce supported frequencies the system can run on.
    for ( const auto& l_cache : l_factory_caches )
    {
        const auto l_dimm = l_cache->iv_target;
        uint64_t l_tckmax_in_ps = 0;
        uint64_t l_tck_min_in_ps = 0;

        FAPI_TRY( get_tckmax(l_cache, l_tckmax_in_ps),
                  "%s. Failed to get tCKmax", mss::c_str(l_dimm) );
        FAPI_TRY( get_tckmin(l_cache, l_tck_min_in_ps),
                  "%s. Failed to get tCKmin", mss::c_str(l_dimm) );

        // Determine a proposed tCK value that is greater than or equal tCKmin
        // But less than tCKmax
        l_largest_tck = std::max(l_largest_tck, l_tck_min_in_ps);
        l_largest_tck = std::min(l_largest_tck, l_tckmax_in_ps);
    }

    FAPI_TRY( mss::ps_to_freq(l_largest_tck, o_highest_freq) );
    FAPI_INF("Biggest freq supported from SPD %d MT/s for %s",
             o_highest_freq, mss::c_str(i_target));

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

    std::vector<uint32_t> l_vpd_supported_freqs;
    uint32_t l_largest_spd_freq = 0;
    uint8_t l_req_sync_mode = 0;

    // Retrieve system MRW constraints
    std::vector<uint32_t> l_max_freqs(NUM_MAX_FREQS, 0);
    FAPI_TRY( mss::max_allowed_dimm_freq(l_max_freqs.data()) );

    // Retrieve frequency constraints due to DIMM SPD and VPD per MCBIST
    FAPI_TRY( largest_spd_supported_freq(i_target, l_largest_spd_freq) );
    FAPI_TRY( vpd_supported_freqs(i_target, l_vpd_supported_freqs) );
    rm_unsupported_spd_freqs(i_target, l_largest_spd_freq, l_vpd_supported_freqs);

    FAPI_TRY( mss::required_synch_mode(l_req_sync_mode) );

    FAPI_TRY( supported_freqs_helper( i_target,
                                      l_vpd_supported_freqs,
                                      l_max_freqs,
                                      l_req_sync_mode == fapi2::ENUM_ATTR_REQUIRED_SYNCH_MODE_ALWAYS,
                                      o_freqs) );
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Create and sort a vector of supported MT/s (freq) - helper for testing purposes
/// @param[in] i_target MCBIST target for which to get the DIMM configs
/// @param[in] i_hw_freqs vector of hardware supported freqs -- from VPD and SPD
/// @param[in] i_max_mrw_freqs vector of max allowed freqs
/// @param[in] i_req_sync_mode bool whether or not we're forced into sync mode
/// @param[out] o_freqs reference to a std::vector to put the sorted vector
/// @return FAPI2_RC_SUCCESS iff ok
/// @note the attributes which drive this are read-only so they're hard to change when
/// testing. So this helper allows us to use the attributes for the main path but
/// have a path for testing (DFT I think the cool kids call it.)
///
fapi2::ReturnCode supported_freqs_helper(const fapi2::Target<TARGET_TYPE_MCBIST>& i_target,
        const std::vector<uint32_t>& i_hw_freqs,
        const std::vector<uint32_t>& i_max_mrw_freqs,
        const bool i_req_sync_mode,
        std::vector<uint32_t>& o_freqs)
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

    // This is the list of supported frequencies for VPD and SPD
    FAPI_ASSERT( !i_hw_freqs.empty(),
                 fapi2::MSS_EMPTY_VECTOR().
                 set_FUNCTION(SUPPORTED_FREQS).
                 set_TARGET(i_target),
                 "Supported system freqs from VPD and SPD are empty for %s",
                 mss::c_str(i_target));

    for( const auto& freq : i_hw_freqs )
    {
        FAPI_DBG("VPD supported freqs %d for %s", freq, mss::c_str(i_target) );
    }

    for( const auto& p : mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target) )
    {
        const auto l_dimms = mss::find_targets<TARGET_TYPE_DIMM>(p);
        const uint64_t l_dimms_on_port = l_dimms.size();

        FAPI_ASSERT( (l_dimms_on_port <= MAX_DIMM_PER_PORT),
                     fapi2::MSS_TOO_MANY_DIMMS_ON_PORT()
                     .set_DIMM_COUNT(l_dimms_on_port)
                     .set_MCA_TARGET(p),
                     "Seeing %d DIMM on port %s",
                     l_dimms_on_port,
                     mss::c_str(p));

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

            l_our_max_freq = std::min(l_our_max_freq, i_max_mrw_freqs[l_index]);
        }// dimm
    }// mca

    FAPI_INF("after processing DIMM, max freq is %d", l_our_max_freq);

    // We need to push things as the memcpy doesn't update the vector's count, etc. and we don't
    // create the vector, we get it passed in. It's not a big deal as we want to touch all the elements
    // to check for 0's anyway.
    for (size_t i = 0; i < i_hw_freqs.size(); ++i)
    {
        // Funky if-tree makes things clearer than a combinatorialy explosive conditional
        if (i_hw_freqs[i] == 0)
        {
            // Skip 0's
            continue;
        }

        if (i_hw_freqs[i] > l_our_max_freq)
        {
            // Skip freqs larger than our max
            continue;
        }

        // Add this freq if we're not in sync mode, or, if we are, add it if it matches a nest freq
        FAPI_INF("attribute required sync mode %d for %s", i_req_sync_mode, mss::c_str(i_target));

        if( i_req_sync_mode && !is_nest_freq_valid(i_hw_freqs[i]) )
        {
            continue;
        }

        o_freqs.push_back(i_hw_freqs[i]);

    }//end for

    {
        // Doing this because the HB compiler freaks out if we have it within the FAPI_ASSERT.
        // Outputting the value and then incrementing the iterator, that's why it's a post increment
        // We have at most 4 memory freqs (1866, 2133, 2400, & 2666), if we ever get a list with < 4 items
        // a value of 0 is logged in FFDC once we hit i_hw_freqs.end()...which is better than no logging.
        auto l_supported = i_hw_freqs.begin();

        const auto l_freq0 = (l_supported != i_hw_freqs.end()) ? *(l_supported++) : 0;
        const auto l_freq1 = (l_supported != i_hw_freqs.end()) ? *(l_supported++) : 0;
        const auto l_freq2 = (l_supported != i_hw_freqs.end()) ? *(l_supported++) : 0;
        const auto l_freq3 = (l_supported != i_hw_freqs.end()) ? *(l_supported++) : 0;

        // If we have an empty set, we have a problem
        FAPI_ASSERT(o_freqs.size() != 0,
                    fapi2::MSS_MRW_FREQ_MAX_FREQ_EMPTY_SET()
                    .set_MSS_VPD_FREQ_0(l_freq0)
                    .set_MSS_VPD_FREQ_1(l_freq1)
                    .set_MSS_VPD_FREQ_2(l_freq2)
                    .set_MSS_VPD_FREQ_3(l_freq3)
                    .set_MSS_MAX_FREQ_0(i_max_mrw_freqs[0])
                    .set_MSS_MAX_FREQ_1(i_max_mrw_freqs[1])
                    .set_MSS_MAX_FREQ_2(i_max_mrw_freqs[2])
                    .set_MSS_MAX_FREQ_3(i_max_mrw_freqs[3])
                    .set_MSS_MAX_FREQ_4(i_max_mrw_freqs[4])
                    .set_MSS_NEST_FREQ_0(fapi2::ENUM_ATTR_FREQ_PB_MHZ_1600)
                    .set_MSS_NEST_FREQ_1(fapi2::ENUM_ATTR_FREQ_PB_MHZ_1866)
                    .set_MSS_NEST_FREQ_2(fapi2::ENUM_ATTR_FREQ_PB_MHZ_2000)
                    .set_MSS_NEST_FREQ_3(fapi2::ENUM_ATTR_FREQ_PB_MHZ_2133)
                    .set_MSS_NEST_FREQ_4(fapi2::ENUM_ATTR_FREQ_PB_MHZ_2400)
                    .set_REQUIRED_SYNC_MODE(i_req_sync_mode)
                    .set_MAX_FREQ_FROM_DIMM(l_our_max_freq)
                    .set_MCBIST_TARGET(i_target),
                    "%s didn't find a frequency which was in VPD and was allowable max", mss::c_str(i_target));
    }

    // We now know o_freqs contains valid frequencies for this DIMM config, system contraints, and sync mode.
    // Sort it so we know supported min is o_freq.begin and supported max is o_freq.end - 1
    std::sort(o_freqs.begin(), o_freqs.end());

fapi_try_exit:
    return fapi2::current_err;
}

}// mss
