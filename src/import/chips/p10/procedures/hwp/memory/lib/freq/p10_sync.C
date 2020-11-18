/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/freq/p10_sync.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file p10_sync.C
/// @brief Synchronous function implementations for Axone
///
/// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
/// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 3
/// *HWP Consumed by: HB:FSP

#include <fapi2.H>
#include <vpd_access.H>
#include <algorithm>
#include <vector>
#include <map>

// Memory libraries
#include <lib/freq/p10_freq_traits.H>
#include <lib/freq/p10_sync.H>
#include <mss_explorer_attribute_getters.H>

// Generic libraries
#include <mss_generic_attribute_getters.H>
#include <generic/memory/lib/utils/assert_noexit.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <generic/memory/lib/spd/spd_facade.H>
#include <generic/memory/lib/spd/spd_utils.H>
#include <generic/memory/lib/utils/conversions.H>
#include <generic/memory/lib/utils/freq/gen_mss_freq.H>
#include <generic/memory/lib/utils/freq/mss_freq_scoreboard.H>

namespace mss
{

///
/// @brief Retrieves a mapping of MSS frequency values per port target
/// @param[in] i_targets vector of port targets
/// @param[out] o_freq_map dimm speed map <key, value> = (port target, frequency)
/// @param[out] o_is_speed_equal holds whether map dimm speed is equal
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode dimm_speed_map(const std::vector< fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> >& i_targets,
                                 std::map< fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>, uint64_t >& o_freq_map,
                                 speed_equality& o_is_speed_equal)
{
    o_freq_map.clear();

    // The find_if loop is meant to find the "first" good (non-zero) freq value
    // so I can compare it against all other freq values from the MEM_PORT vector
    // I am checking to make sure I don't get a value of 0
    // Since Cronus can hand me back a MEM_PORT w/no DIMMs
    // Which would give ATTR_MSS_FREQ value of 0 in p9_mss_freq
    uint64_t l_comparator = 0;
    fapi2::ReturnCode l_rc(fapi2::FAPI2_RC_FALSE);

    const auto l_found_comp = std::find_if(i_targets.begin(), i_targets.end(),
                                           [&l_rc, &l_comparator] (const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target)->bool
    {
        l_rc = mss::attr::get_freq(i_target, l_comparator);
        return l_comparator != 0;
    });

    // Getting error cross initializing with the Assert
    // find_if should work if passed in an empty vector. begin() and end() will match and it'll exit without trying freq()
    FAPI_ASSERT( !i_targets.empty(),
                 fapi2::MSS_EMPTY_FREQ_TARGET_VECTOR_PASSED(),
                 "Empty MEM_PORT target vector found when constructing dimm speed mapping!" );

    FAPI_TRY(l_rc, "Failed accessor mss::freq()");

    // If all MEM_PORTs are 0 we go no further
    // We shouldn't get here though. We check for DIMMS in freq_system. If no DIMMS, we exit
    // We can assume if there is a dimm configured at this point (after mss_freq)
    // It has a valid freq
    // Thus, this shouldn't ever happen, but let's check anyways
    FAPI_ASSERT( l_found_comp != i_targets.end(),
                 fapi2::MSS_ALL_TARGETS_HAVE_0_FREQ()
                 .set_VECTOR_SIZE(i_targets.size()),
                 "All MEM_PORTs have 0 MSS_FREQ, but there are dimms?");

    // DIMM speed is equal until we deduce otherwise
    o_is_speed_equal = speed_equality::EQUAL_DIMM_SPEEDS;

    // Make sure to stick the first one we found in the freq map.
    o_freq_map.emplace( std::make_pair(*l_found_comp, l_comparator) );

    // Loop through all MEM_PORTs and store dimm speeds
    // Starting from 1st known good freq (non-zero) value
    // I found above to avoid double looping target vector
    for (auto l_iter = l_found_comp + 1; l_iter != i_targets.end(); ++l_iter)
    {
        uint64_t l_dimm_speed = 0;
        FAPI_TRY( mss::attr::get_freq(*l_iter, l_dimm_speed), "Failed accessor to mss_freq" );

        // In FW, parents are deconfigured if they have no children
        // So there is no way to get a MEM_PORT w/no DIMMs.
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
                 "freq system freq map is empty? found port: %s",
                 mss::c_str(*l_found_comp) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Deconfigures MEM_PORT targets
/// @param[in] i_target the port target
/// @param[in] i_dimm_speed dimm speed in MT/s
/// @param[in] i_max_freq maximum dimm freq in MT/s of freq domain
/// @return true if hardware was deconfigured
///
bool deconfigure(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                 const uint64_t i_dimm_speed,
                 const uint64_t i_max_freq)
{
    bool l_is_hw_deconfigured = (i_dimm_speed != i_max_freq);

    MSS_ASSERT_NOEXIT(!l_is_hw_deconfigured,
                      fapi2::MSS_FREQ_NOT_EQUAL_MAX_DOMAIN_FREQ()
                      .set_MSS_FREQ(i_dimm_speed)
                      .set_DOMAIN_FREQ(i_max_freq)
                      .set_DOMAIN_TARGET(i_target),
                      "Deconfiguring %s due to unequal frequencies: this port: %d, Max in freq domain: %d",
                      mss::c_str(i_target),
                      i_dimm_speed,
                      i_max_freq );

    return l_is_hw_deconfigured;
}

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
                                  uint32_t& o_selected_omi_freq)
{
    switch(i_equal_dimm_speed)
    {
        // If we resolved to equal speeds ...
        case speed_equality::EQUAL_DIMM_SPEEDS:
            {
                // Return back the resulting speed. It doesn't matter which we select from the map as they're all equal
                // If we end up not in sync in the conditional below, thats ok - this parameter is ignored by the
                // caller if we're not in sync mode
                const auto l_ddr_freq = i_freq_map.begin()->second;
                FAPI_TRY(convert_ddr_freq_to_omi_freq(i_freq_map.begin()->first,
                                                      l_ddr_freq,
                                                      o_selected_omi_freq));

                // When we selected ATTR_MSS_FREQ, we made sure that we didn't
                // select a DIMM freq the OMI couldn't support.

#ifndef __HOSTBOOT_MODULE
                // On Cronus if the o_selected_omi_freq != i_omi_freq we've got a mismatch. Note that p10_mss_freq ensures
                // we don't select an invalid freq, but doesn't ensure we select the current OMI freq.
                FAPI_ASSERT(o_selected_omi_freq == i_omi_freq,
                            fapi2::P10_MSS_FAILED_SYNC_MODE()
                            .set_OMI_FREQ(i_omi_freq)
                            .set_MEM_FREQ(o_selected_omi_freq),
                            "The OMI freq selected by DIMM speed (%d) and the currently selected OMI freq (%d) don't align",
                            o_selected_omi_freq, i_omi_freq);
#endif
                return fapi2::FAPI2_RC_SUCCESS;
                break;
            }

        case speed_equality::NOT_EQUAL_DIMM_SPEEDS:
            {
                // When we selected ATTR_MSS_FREQ, we made sure that we didn't
                // select a DIMM freq the OMI couldn't support. That means that the fastest of the ports
                // is the one that rules the roost (the OMI can support it too.) So find that, and set it to
                // the selected frequency. Then deconfigure the slower ports (unless we're in Cronus in which
                // case we just bomb out.)
#ifdef __HOSTBOOT_MODULE
                uint64_t l_max_dimm_speed = 0;
                fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> l_fastest_port_target = i_freq_map.begin()->first;
                std::for_each(i_freq_map.begin(), i_freq_map.end(),
                              [&l_max_dimm_speed, &l_fastest_port_target]
                              (const std::pair<fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>, uint64_t>& m)
                {
                    l_max_dimm_speed = std::max(l_max_dimm_speed, m.second);
                    l_fastest_port_target = m.first;
                });

                std::for_each(i_freq_map.begin(), i_freq_map.end(),
                              [&l_max_dimm_speed](const std::pair<fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>, uint64_t>& m)
                {
                    deconfigure(m.first, m.second, l_max_dimm_speed);
                });

                FAPI_TRY(convert_ddr_freq_to_omi_freq(l_fastest_port_target,
                                                      l_max_dimm_speed,
                                                      o_selected_omi_freq));
                return fapi2::FAPI2_RC_SUCCESS;
#else
                // Cronus only
                FAPI_ASSERT(false,
                            fapi2::P10_MSS_FAILED_SYNC_MODE()
                            .set_OMI_FREQ(i_omi_freq),
                            "Some DIMM speeds are incompatible with OMI speed %d", i_omi_freq);
#endif
                break;
            }

        default:
            // Switches on an enum class
            // The only valid speed_equality values are NOT_EQUAL and EQUAL.
            // If it's something else ,I think it's a code error and really shouldn't be possible, thus fapi2::Assert below
            FAPI_ERR("Invalid speed_equality parameter!");
            fapi2::Assert(false);
            break;
    }// end switch

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set system freq attributes based on selected OMI frequency
/// @param[in] i_target proc chip target
/// @param[in] i_omi_freq OMI frequency
/// @return FAPI2_RC_SUCCESS iff successful
/// @note i_omi_freq cannot be const due to FAPI_ATTR_SET not allowing const
///
fapi2::ReturnCode set_freq_system_attrs(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                                        uint32_t i_omi_freq)
{
    // l_mc_freq is the frequency of the memory controller mesh clock, which
    // is always 1/16th of the OMI frequency. Note this is the MC in the host, not in the DDIMM.
    constexpr uint32_t MC_TO_OMI_FREQ_RATIO = 16;

    // Note that this also cannot be const due to the FAPI_ATTR_SET below
    uint32_t l_mc_freq = i_omi_freq / MC_TO_OMI_FREQ_RATIO;

    FAPI_INF("%s: Setting recommended OMI frequency in ATTR_FREQ_OMI_MHZ to %d", mss::c_str(i_target), i_omi_freq);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_FREQ_OMI_MHZ, i_target, i_omi_freq) );

    for (const auto& l_mc : mss::find_targets<fapi2::TARGET_TYPE_MC>(i_target))
    {
        FAPI_INF("%s: Setting memory controller mesh clock frequency in ATTR_FREQ_MC_MHZ to %d",
                 mss::c_str(l_mc), l_mc_freq);
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_FREQ_MC_MHZ, l_mc, l_mc_freq) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

}// mss
