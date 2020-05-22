/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_util_to_throttle.C $ */
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
/// @file p9c_mss_util_to_throttle.C
/// @brief determine N throttle settings for N/M throttling for a given dram data bus util value
///     and the channel pair power at the given utilization value
////    OCC calls this HWP after setting ATTR_CEN_MSS_DATABUS_UTIL_PER_MBA
////    ATTR_CEN_MSS_DATABUS_UTIL_PER_MBA is a floor or minimum value to meet
////    If input utilization is zero, then safemode values from MRW will be used
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
#include <math.h>
#include <p9c_mss_util_to_throttle.H>
#include <p9c_mss_bulk_pwr_throttles.H>
#include <generic/memory/lib/utils/c_str.H>
#include <fapi2.H>
#include <generic/memory/lib/utils/count_dimm.H>

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
        uint8_t l_safemode_util = 0;
        uint32_t l_safemode_throttle_n_per_mba = 0;
        uint32_t l_safemode_throttle_n_per_chip = 0;
        uint32_t l_throttle_d = 0;
        bool l_safemode = false;

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

        // If input utilizaiton is zero, then use safemode throttle attributes to calculate utilization
        if (l_data_bus_util == 0)
        {
            FAPI_TRY(p9c_mss_util_to_throttle_safemode(i_target_mba, l_safemode_util));
            FAPI_INF("[%s Using Safemode Utilization %d percent]", mss::c_str(i_target_mba), l_safemode_util);
            l_data_bus_util = l_safemode_util;
            l_safemode = true;
        }

        // call p9c_mss_bulk_pwr_channel_power to get the channel pair power slope and intercept values to use
        FAPI_TRY(p9c_mss_bulk_pwr_channel_pair_power_curve(i_target_mba, l_channel_power_slope, l_channel_power_intercept));

        // call p9c_mss_bulk_pwr_util_to_throttle_power to get the memory throttle and channel pair power attributes defined
        // This call will return an error if calculated util does not meet input util target (l_data_bus_util)
        FAPI_TRY(p9c_mss_bulk_pwr_util_to_throttle_power(i_target_mba,
                 (static_cast<double>(l_data_bus_util)), l_channel_power_slope,
                 l_channel_power_intercept, l_utilization_is_a_min_value));

        // Set throttle attributes to the safemode throttle attributes if input utilization was zero
        // This is done in case the utilization from the mrw safemode throttles is not a whole integer value
        // The calculated N throttle values may be different than the mrw safemode throttles, so make sure we end up at the mrw values
        if (l_safemode)
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MRW_SAFEMODE_MEM_THROTTLE_NUMERATOR_PER_MBA,
                                   fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                                   l_safemode_throttle_n_per_mba));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MRW_SAFEMODE_MEM_THROTTLE_NUMERATOR_PER_CHIP,
                                   fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                                   l_safemode_throttle_n_per_chip));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_MEM_M_DRAM_CLOCKS,
                                   fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                                   l_throttle_d));
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_MEM_THROTTLE_NUMERATOR_PER_MBA,
                                   i_target_mba, l_safemode_throttle_n_per_mba));
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_MEM_THROTTLE_NUMERATOR_PER_CHIP,
                                   i_target_mba, l_safemode_throttle_n_per_chip));
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_MEM_THROTTLE_DENOMINATOR,
                                   i_target_mba, l_throttle_d));
            FAPI_INF("[%s Throttle attributes set to safemode values %d/%d/%d]", mss::c_str(i_target_mba),
                     l_safemode_throttle_n_per_mba, l_safemode_throttle_n_per_chip, l_throttle_d);
        }

        FAPI_INF("*** p9c_mss_util_to_throttle COMPLETE on %s ***", mss::c_str(i_target_mba));

    fapi_try_exit:
        return fapi2::current_err;
    }

    ///
    /// @brief This function will determine the safemode dram utilization
    ///    for the MRW safemode throttle values
    /// @param[in]  i_target_mba:  MBA Target
    /// @param[out]  o_safemode_util:  safemode utilization value from MRW attributes
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode p9c_mss_util_to_throttle_safemode(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
            uint8_t& o_safemode_util)
    {
        FAPI_INF("*** Running p9c_mss_util_to_throttle_safemode on %s ***", mss::c_str(i_target_mba));

        uint32_t l_safemode_throttle_n_per_mba = 0;
        uint32_t l_safemode_throttle_n_per_chip = 0;
        uint32_t l_throttle_d = 0;
        uint8_t l_custom_dimm = 0;
        uint8_t l_throttle_multiplier = 0;
        double l_utilization = 0;
        double l_util_mba = 0;
        double l_util_chip = 0;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MRW_SAFEMODE_MEM_THROTTLE_NUMERATOR_PER_MBA,
                               fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                               l_safemode_throttle_n_per_mba));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MRW_SAFEMODE_MEM_THROTTLE_NUMERATOR_PER_CHIP,
                               fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                               l_safemode_throttle_n_per_chip));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_MEM_M_DRAM_CLOCKS,
                               fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                               l_throttle_d));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CUSTOM_DIMM, i_target_mba,  l_custom_dimm));

        // Set the throttle multiplier based on how throttles are used
        // CDIMMs use per mba and per chip throttles (for l_throttle_n_per_mba and l_throttle_n_per_chip), set to 2
        // ISDIMMs use per slot and per mba throttles (for l_throttle_n_per_mba and l_throttle_n_per_chip), set to 1
        l_throttle_multiplier = (l_custom_dimm == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES) ? 2 : 1;

        // Calculate the utilization value from the safemode throttle values
        // Throttling is disabled if M (or l_throttle_d) is 0.  If that is the case, then set util to MAX_UTIL.
        if (l_throttle_d == 0)
        {
            l_utilization = static_cast<double>(MAX_UTIL) / PERCENT_CONVERSION;
        }
        else
        {
            l_util_mba = (static_cast<double>(l_safemode_throttle_n_per_mba) * ADDR_TO_DATA_UTIL_CONVERSION / l_throttle_d *
                          PERCENT_CONVERSION);
            l_util_chip = (static_cast<double>(l_safemode_throttle_n_per_chip) * ADDR_TO_DATA_UTIL_CONVERSION / l_throttle_d /
                           l_throttle_multiplier * PERCENT_CONVERSION);
            l_utilization = ((l_safemode_throttle_n_per_mba * l_throttle_multiplier) <= l_safemode_throttle_n_per_chip) ?
                            l_util_mba : l_util_chip;
        }

        // round up if not a whole integer (may end up with a litle more power if not a whole integer which shouldn't be an issue)
        o_safemode_util = ceil(l_utilization);

        FAPI_INF("%s Safemode Throttles %d/%d/%d, Util %4.2lf/%d percent", mss::c_str(i_target_mba),
                 l_safemode_throttle_n_per_mba, l_safemode_throttle_n_per_chip, l_throttle_d, l_utilization, o_safemode_util);
        FAPI_INF("*** p9c_mss_util_to_throttle_safemode COMPLETE on %s ***", mss::c_str(i_target_mba));

    fapi_try_exit:
        return fapi2::current_err;
    }

} //end extern C
