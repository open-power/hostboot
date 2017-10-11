/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_util_to_throttle.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
/// @file p9c_mss_util_to_throttle.C
/// @brief determine N throttle settings for N/M throttling for a given dram data bus util value
///     and the channel pair power at the given utilization value
////    OCC calls this HWP after setting ATTR_CEN_MSS_DATABUS_UTIL_PER_MBA
////    ATTR_CEN_MSS_DATABUS_UTIL_PER_MBA is a floor or minimum value to meet
///
/// *HWP HWP Owner: Andre Marin <aamaring@us.ibm.com>
/// *HWP HWP Backup: Michael Pardeik <pardeik@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB:CI
///

//------------------------------------------------------------------------------
//  My Includes
//------------------------------------------------------------------------------
#include <p9c_mss_util_to_throttle.H>
#include <p9c_mss_bulk_pwr_throttles.C>
#include <p9c_mss_bulk_pwr_throttles.H>
#include <generic/memory/lib/utils/c_str.H>
#include <fapi2.H>
#include <generic/memory/lib/utils/c_str.H>

using fapi2::FAPI2_RC_SUCCESS;

extern "C" {
    ///
    /// @brief This function will determine N/M throttles and channel pair power
    ///    for a given dram data bus util value from attribute ATTR_CEN_MSS_DATABUS_UTIL_PER_MBA
    /// @param[in]  i_target_mba:  MBA Target
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode p9c_mss_util_to_throttle(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba)
    {
        FAPI_INF("*** Running p9c_mss_util_to_throttle on %s ***", mss::c_str(i_target_mba));

        uint8_t l_data_bus_util = 0;
        double l_channel_power_slope = 0;
        double l_channel_power_intercept = 0;
        constexpr bool l_utilization_is_a_min_value = true; // set to true

        // If MBA has no DIMMs, return as there is nothing to do
        if (mss::count_dimm(i_target_mba) == 0)
        {
            FAPI_INF("++++ NO DIMM on %s ++++", mss::c_str(i_target_mba));
            return fapi2::FAPI2_RC_SUCCESS;
        }

        // Get input attributes
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_DATABUS_UTIL_PER_MBA,
                               i_target_mba, l_data_bus_util));
        FAPI_INF("[%s Input Attribute Utilization %d percent]", mss::c_str(i_target_mba), l_data_bus_util);

        // call p9c_mss_bulk_pwr_channel_power to get the channel pair power slope and intercept values to use
        FAPI_TRY(p9c_mss_bulk_pwr_channel_pair_power_curve(i_target_mba, l_channel_power_slope, l_channel_power_intercept));

        // call p9c_mss_bulk_pwr_util_to_throttle_power to get the memory throttle and channel pair power attributes defined
        FAPI_TRY(p9c_mss_bulk_pwr_util_to_throttle_power(i_target_mba,
                 (static_cast<double>(l_data_bus_util)), l_channel_power_slope,
                 l_channel_power_intercept, l_utilization_is_a_min_value));

        FAPI_INF("*** p9c_mss_util_to_throttle COMPLETE on %s ***", mss::c_str(i_target_mba));

    fapi_try_exit:
        return fapi2::current_err;
    }
} //end extern C
