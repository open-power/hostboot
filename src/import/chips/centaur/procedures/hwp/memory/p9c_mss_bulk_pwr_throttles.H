/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_bulk_pwr_throttles.H $ */
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

/// @file p9c_mss_bulk_pwr_throttles.H
/// @brief  Sets the throttle attributes based on a power limit for the dimms on the channel pair
///
/// *HWP HWP Owner: Andre Marin <aamaring@us.ibm.com>
/// *HWP HWP Backup: Mike Pardeik <pardeik@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB
///

#ifndef MSS_BULK_PWR_THROTTLES_H_
#define MSS_BULK_PWR_THROTTLES_H_

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

// Units c%, set to 100%
constexpr uint32_t MAX_UTIL = 10000;
// Conversion factor to convert from address bus utilization to data bus utilization
constexpr uint8_t ADDR_TO_DATA_UTIL_CONVERSION = 4;
// Conversion factor to convert from centi percent to percent
constexpr uint8_t PERCENT_CONVERSION = 100;

///
/// @brief This function will convert a value with units of centi percent to percent
/// @tparam T the type to convert into a percentage
/// @param[in] i_value:  value in centi percent
/// @return the value in percent
///
template<typename T>
inline T convert_to_percent(const T i_value)
{
    return (i_value / PERCENT_CONVERSION);
}

typedef fapi2::ReturnCode (*p9c_mss_bulk_pwr_throttles_FP_t)
(
    const fapi2::Target<fapi2::TARGET_TYPE_MBA>&
);

typedef fapi2::ReturnCode (*p9c_mss_bulk_pwr_channel_pair_power_curve_FP_t)
(
    const fapi2::Target<fapi2::TARGET_TYPE_MBA>&,
    double&,
    double&
);

typedef fapi2::ReturnCode (*p9c_mss_bulk_pwr_util_to_throttle_power_FP_t)
(
    const fapi2::Target<fapi2::TARGET_TYPE_MBA>&,
    double,
    const double,
    const double,
    const bool
);


extern "C"
{
    /// @brief Set dimm and channel throttle attributes based on available centaur mba port power
    /// @param[in]  i_target_mba:  MBA Target
    /// @return ReturnCode
    fapi2::ReturnCode p9c_mss_bulk_pwr_throttles(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba);

    ///
    /// @brief This function determines the channel pair power slope and intercept values to use
    ///   to calculate the channel pair power (ie.  power of dimms attached to channel pair)
    /// @param[in] i_target_mba:  MBA Target
    /// @param[out]  o_channel_power_slope channel pair power slope
    /// @param[out]  o_channel_power_intercept channel pair power intercept
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode p9c_mss_bulk_pwr_channel_pair_power_curve(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
            double& o_channel_power_slope,
            double& o_channel_power_intercept);

    ///
    /// @brief This function determines the memory throttle and channel pair power
    ///   attribute values for a given dram data bus utilization value
    /// @param[in] i_target_mba:  MBA Target
    /// @param[in]  i_utilization Dram data bus utilization value (units %)
    /// @param[in]  i_channel_power_slope channel pair power slope
    /// @param[in]  i_channel_power_intercept channel pair power
    /// @param[in]  i_utilization_is_a_min_value tells us if i_utilization is a min or max target to meet (0=max, 1=min)
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode p9c_mss_bulk_pwr_util_to_throttle_power(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
            double i_utilization,
            const double i_channel_power_slope,
            const double i_channel_power_intercept,
            const bool i_utilization_is_a_min_value);

    ///
    /// @brief This function determines the memory throttle values
    ///   for a given dram data bus utilization value
    /// @param[in] i_target_mba:  MBA Target
    /// @param[in]  i_utilization Input Dram data bus utilization value (units %)
    /// @param[in]  i_max_util Max Dram data bus utilization value (units %)
    /// @param[out]  o_throttle_n_per_mba N memory throttle for per mba throttles
    /// @param[out]  o_throttle_n_per_chip N memory throttle for per mba throttles
    /// @param[out]  o_throttle_adder N throttle adder to use to meet utilization min or max target
    /// @param[in]  i_utilization_is_a_min_value tells us if i_utilization is a min or max target to meet (0=max, 1=min)
    /// @return fapi2::ReturnCode
    ///
    fapi2::ReturnCode p9c_mss_bulk_pwr_util_to_throttle(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
            const double i_utilization,
            const double i_max_util,
            uint32_t& o_throttle_n_per_mba,
            uint32_t& o_throttle_n_per_chip,
            uint8_t& o_throttle_adder,
            const bool i_utilization_is_a_min_value);

} // extern "C"

#endif // MSS_BULK_PWR_THROTTLES_H_
