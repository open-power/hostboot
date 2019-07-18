/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/freq/sync.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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

// Memory libraries
#include <lib/freq/nimbus_freq_traits.H>
#include <lib/freq/sync.H>
#include <lib/mss_attribute_accessors.H>

// Generic libraries
#include <generic/memory/lib/utils/assert_noexit.H>
#include <lib/utils/nimbus_find.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <generic/memory/lib/spd/spd_facade.H>
#include <generic/memory/lib/spd/spd_utils.H>
#include <generic/memory/lib/utils/conversions.H>
#include <generic/memory/lib/utils/freq/gen_mss_freq.H>
#include <generic/memory/lib/utils/freq/mss_freq_scoreboard.H>

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
                 fapi2::MSS_EMPTY_FREQ_TARGET_VECTOR_PASSED(),
                 "Empty MCBIST target vector found when constructing dimm speed mapping!" );


    FAPI_TRY(l_rc, "Failed accessor mss::freq()");

    // If all MCBISTs are 0 we go no further
    // We shouldn't get here though. We check for DIMMS in freq_system. If no DIMMS, we exit
    // We can assume if there is a dimm configured at this point (after mss_freq)
    // It has a valid freq
    // Thus, this shouldn't ever happen, but let's check anyways
    FAPI_ASSERT( l_found_comp != i_targets.end(),
                 fapi2::MSS_ALL_TARGETS_HAVE_0_FREQ()
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
                              fapi2::MSS_FREQ_NOT_EQUAL_MAX_DOMAIN_FREQ()
                              .set_MSS_FREQ(i_dimm_speed)
                              .set_DOMAIN_FREQ(i_nest_freq)
                              .set_DOMAIN_TARGET(l_mcs),
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

}// mss
