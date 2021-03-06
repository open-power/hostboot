/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9a/procedures/hwp/memory/p9a_mss_freq_system.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
/// @file p9a_mss_freq_system.C
/// @brief Matches OMI freq with DDR freq
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB

// fapi2
#include <p9a_mss_freq_system.H>
#include <lib/freq/axone_sync.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/count_dimm.H>

extern "C"
{
///
/// @brief Matches OMI freq with DDR freq
/// @param[in] i_target PROC_CHIP target
/// @return FAPI2_RC_SUCCESS iff ok
///
    fapi2::ReturnCode p9a_mss_freq_system( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target )
    {
        const auto& l_ports = mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target);

        // If there are no DIMM we don't need to bother. In fact, we can't as we didn't setup
        // attributes for the PHY, etc. If there is even one DIMM on this proc,
        // we do the right thing.
        if (mss::count_dimm(l_ports) == 0)
        {
            FAPI_INF("... skipping freq_system - no DIMM ...");
            return fapi2::FAPI2_RC_SUCCESS;
        }

        std::map< fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>, uint64_t > l_freq_map;
        uint32_t l_omi_freq = 0;
        uint32_t l_selected_omi_freq = 0;
        mss::speed_equality l_equal_dimm_speed;

        // Get OMI freq
        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_FREQ_OMI_MHZ, i_target, l_omi_freq) );

        // Populate dimm speed map
        FAPI_TRY( mss::dimm_speed_map(l_ports, l_freq_map, l_equal_dimm_speed),
                  "Failed to get dimm speed mapping" );

        FAPI_INF("Dimm speed for all OCMBs are the same : %s",
                 uint8_t(l_equal_dimm_speed) ? "true" : "false");

        // Select OMI freq, or check in the case of Cronus
        FAPI_TRY( mss::select_omi_freq(l_freq_map,
                                       l_equal_dimm_speed,
                                       l_omi_freq,
                                       l_selected_omi_freq) );

        // Set attributes.
        FAPI_INF("%s: Setting recommended OMI frequency in ATTR_FREQ_OMI_MHZ to %d", mss::c_str(i_target), l_selected_omi_freq);
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_FREQ_OMI_MHZ, i_target, l_selected_omi_freq) );

    fapi_try_exit:
        return fapi2::current_err;
    }

} //extern "C"
