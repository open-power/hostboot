/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/p9_mss_freq_system.C $ */
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
/// @file p9_freq_system.C
/// @brief Sets synchronous mode an
///
// *HWP HWP Owner: Andre A. Marin  <aamarin@us.ibm.com>
// *HWP FW Owner: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB
#include <vector>
#include <map>

#include <fapi2.H>
#include <mss.H>

#include <p9_mss_freq_system.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/utils/count_dimm.H>
#include <lib/freq/sync.H>


using fapi2::TARGET_TYPE_SYSTEM;
using fapi2::TARGET_TYPE_PROC_CHIP;
using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCS;

extern "C"
{
    ///
    /// @brief Set synchronous mode
    /// @param[in] i_targets vector of controllers (e.g., MCS)
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode p9_mss_freq_system( const std::vector< fapi2::Target<TARGET_TYPE_MCBIST> >& i_targets )
    {
        FAPI_INF("----- In p9_mss_freq_system ----");

        // If there are no DIMM we don't need to bother. In fact, we can't as we didn't setup
        // attributes for the PHY, etc. If there is even one DIMM on any of this list of MCBIST,
        // we do the right thing.
        uint64_t l_dimm_count = 0;
        std::for_each( i_targets.begin(),
                       i_targets.end(),
                       [&l_dimm_count](const fapi2::Target<TARGET_TYPE_MCBIST>& i_target)
        {
            l_dimm_count += mss::count_dimm(i_target);
        } );

        if (l_dimm_count == 0)
        {
            FAPI_INF("... skipping freq_system - no DIMM ...");
            return fapi2::FAPI2_RC_SUCCESS;
        }

        std::map< fapi2::Target<TARGET_TYPE_MCBIST>, uint64_t > l_freq_map;
        uint32_t l_nest_freq = 0;
        uint8_t l_required_sync_mode = 0;
        uint8_t l_mc_in_sync = 0;
        uint64_t l_selected_nest_freq = 0;
        mss::speed_equality l_equal_dimm_speed;

        // Get nest freq && F/W attr that tells me if sync mode is required
        // or if I have to figure that out
        FAPI_TRY( mss::required_synch_mode(l_required_sync_mode) );
        FAPI_TRY( mss::freq_pb_mhz(l_nest_freq) );

        FAPI_INF("Retrieved req'd sync mode: %d and nest freq %d", l_required_sync_mode, l_nest_freq);

        // Populate dimm speed map
        FAPI_TRY( mss::dimm_speed_map(i_targets, l_freq_map, l_equal_dimm_speed),
                  "Failed to get dimm speed mapping" );

        FAPI_INF("Dimm speed for all MCBISTs are the same : %s",
                 uint8_t(l_equal_dimm_speed) ? "true" : "false");

        // Select SYNCH mode
        FAPI_TRY( mss::select_sync_mode(l_freq_map,
                                        l_equal_dimm_speed,
                                        l_nest_freq,
                                        l_required_sync_mode,
                                        l_mc_in_sync,
                                        l_selected_nest_freq) );

        FAPI_INF("Selected SYNC mode : %s",
                 (l_mc_in_sync == fapi2::ENUM_ATTR_MC_SYNC_MODE_IN_SYNC) ? "MC in sync" : "MC NOT in sync");

        // Set attributes.
        // set ATTR_FREQ_PB_MHZ based on sync logic
        // set ATTR_MC_SYNC_MODE to 0 (not in sync) or 1 (in sync)
        for(const auto& l_mcbist : i_targets)
        {
            // Convert from uint64_t to uint32_t for attribute macros
            uint32_t l_pb_freq_value = l_selected_nest_freq;

            const auto& l_proc_chip = mss::find_target<TARGET_TYPE_PROC_CHIP>(l_mcbist);

            FAPI_INF("%s: Setting ATTR_MC_SYNC_MODE to %d", mss::c_str(l_mcbist), l_mc_in_sync);

            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MC_SYNC_MODE, l_proc_chip, l_mc_in_sync),
                      "Failed to set ATTR_MC_SYNC_MODE" );

            if (l_mc_in_sync == fapi2::ENUM_ATTR_MC_SYNC_MODE_IN_SYNC)
            {
                FAPI_INF("%s: Setting ATTR_FREQ_PB_MHZ to %d", mss::c_str(l_mcbist), l_pb_freq_value);
                FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_FREQ_PB_MHZ, fapi2::Target<TARGET_TYPE_SYSTEM>(), l_pb_freq_value),
                          "Failed to set ATTR_FREQ_PB_MHZ" );
            }
        }

    fapi_try_exit:
        return fapi2::current_err;

    } // p9_freq_system

} //extern "C"
