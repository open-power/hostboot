/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_bulk_pwr_throttles.C $ */
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


/// @file p9c_mss_bulk_pwr_throttles.C
/// @brief  Sets the throttle attributes based on a power limit for the dimms on the channel pair
///
/// *HWP HWP Owner: Andre Marin <aamaring@us.ibm.com>
/// *HWP HWP Backup: Mike Pardeik <pardeik@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB
///

// DESCRIPTION:
// The purpose of this procedure is to set the throttle attributes based on a
// power limit for the dimms on the channel pair
// At the end, output attributes will be updated with throttle values that will
// have dimms at or below the limit
// NOTE:  ISDIMMs and CDIMMs are handled differently
//   ISDIMMs use a power per DIMM for the thermal power limit from the MRW
//   CDIMM will use power per CDIMM (power for all virtual dimms) for the
//    thermal power limit from the MRW
// Plan is to have ISDIMM use the per-slot throttles (thermal throttles) or
//  per-mba throttles (power throttles), and CDIMM to use the per-chip throttles
// Note that throttle_n_per_mba takes on different meanings depending on how
// cfg_nm_per_slot_enabled is set
//   Can be slot0/slot1 OR slot0/MBA throttling
// Note that throttle_n_per_chip takes on different meaning depending on how
// cfg_count_other_mba_dis is set
//  Can be per-chip OR per-mba throttling
// These inits here are done in mss_scominit
// ISDIMM:  These registers need to be setup to these values, will be able to
//  do per slot or per MBA throttling
//   cfg_nm_per_slot_enabled = 1
//   cfg_count_other_mba_dis = 1
// CDIMM:  These registers need to be setup to these values, will be able to
//  do per mba or per chip throttling
//   cfg_nm_per_slot_enabled = 0
//   cfg_count_other_mba_dis = 0

//------------------------------------------------------------------------------
//  My Includes
//------------------------------------------------------------------------------
#include <p9c_mss_bulk_pwr_throttles.H>
#include <generic/memory/lib/utils/c_str.H>
#include <dimmConsts.H>
#include <lib/utils/cumulus_find.H>
#include <generic/memory/lib/utils/count_dimm.H>
//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

using fapi2::TARGET_TYPE_MEMBUF_CHIP;
using fapi2::TARGET_TYPE_MBA;
using fapi2::FAPI2_RC_SUCCESS;

constexpr uint32_t DRAM_UTIL_LIMIT_BOTH_MBA_WITH_DIMMS = 5625; // units c%
constexpr uint8_t IDLE_UTIL = 0; // in percent
constexpr double UTIL_FLOOR = 1; // in percent, utilization floor

extern "C" {
    /// @brief This function determines the throttle values power limit for the dimms on the channel pair
    /// @param[in] i_target_mba:  MBA Target
    /// @return fapi2::ReturnCode
    fapi2::ReturnCode p9c_mss_bulk_pwr_throttles(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba)
    {
        FAPI_INF("*** Running mss_bulk_pwr_throttles on %s ***", mss::c_str(i_target_mba));
        uint32_t l_channel_pair_watt_target = 0;
        double l_utilization = 0;
        double l_channel_power_slope = 0;
        double l_channel_power_intercept = 0;
        uint32_t l_channel_pair_power = 0;
        constexpr bool l_utilization_is_a_min_value = false; //.set to false

        // If MBA has no DIMMs, return as there is nothing to do
        if (mss::count_dimm(i_target_mba) == 0)
        {
            FAPI_INF("++++ NO DIMM on %s ++++", mss::c_str(i_target_mba));
            return fapi2::FAPI2_RC_SUCCESS;
        }

        // get input attributes
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_MEM_WATT_TARGET,
                               i_target_mba, l_channel_pair_watt_target));

        FAPI_INF("[%s Available Channel Pair Power (Watt Target) %d cW]", mss::c_str(i_target_mba), l_channel_pair_watt_target);

        // call p9c_mss_bulk_pwr_channel_power to get the channel pair power slope and intercept values to use
        FAPI_TRY(p9c_mss_bulk_pwr_channel_pair_power_curve(i_target_mba, l_channel_power_slope, l_channel_power_intercept));

        // calculate the utilization needed to be under power limit
        if ((l_channel_pair_watt_target > l_channel_power_intercept) && (l_channel_power_slope > 0))
        {
            l_utilization = (l_channel_pair_watt_target - l_channel_power_intercept) / l_channel_power_slope * PERCENT_CONVERSION;
        }

        // call p9c_mss_bulk_pwr_util_to_throttle_power to get the memory throttle and channel pair power attributes defined
        FAPI_TRY(p9c_mss_bulk_pwr_util_to_throttle_power(i_target_mba, l_utilization, l_channel_power_slope,
                 l_channel_power_intercept, l_utilization_is_a_min_value));

        // Get channel pair power attribute value just defined from above call to p9c_mss_bulk_pwr_util_to_throttle_power
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_CHANNEL_PAIR_MAXPOWER,
                               i_target_mba, l_channel_pair_power));

        // Check to see if there is not enough available power (units are in cW)
        // Return a bad RC if power is over the limit
        FAPI_ASSERT((l_channel_pair_power <= l_channel_pair_watt_target),
                    fapi2::CEN_MSS_NOT_ENOUGH_AVAILABLE_DIMM_POWER().
                    set_PAIR_POWER(l_channel_pair_power).
                    set_PAIR_WATT_TARGET(l_channel_pair_watt_target).
                    set_MEM_MBA(i_target_mba),
                    "%s Not enough available memory power [Channel Pair Power %d/%d cW]", mss::c_str(i_target_mba), l_channel_pair_power,
                    l_channel_pair_watt_target);

        FAPI_INF("*** mss_bulk_pwr_throttles COMPLETE on %s ***", mss::c_str(i_target_mba));

    fapi_try_exit:
        return fapi2::current_err;
    }

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
            double& o_channel_power_intercept
                                                               )
    {
        FAPI_INF("*** Running p9c_mss_bulk_pwr_channel_pair_power_curve on %s ***", mss::c_str(i_target_mba));

        // add up the power from all dimms for this MBA (across both channels)
        // for IDLE (utilization=0) and maximum utilization
        double l_max_util = 0;
        double l_channel_pair_power_idle = 0;
        double l_channel_pair_power_max = 0;
        uint8_t l_port = 0;
        uint8_t l_dimm = 0;
        double l_channel_power_array_idle[MAX_PORTS_PER_MBA] = {0};
        double l_channel_power_array_max[MAX_PORTS_PER_MBA] = {0};
        double l_dimm_power_array_idle[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        double l_dimm_power_array_max[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint8_t l_dimm_ranks_array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint32_t l_total_power_slope_array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint32_t l_total_power_int_array[MAX_PORTS_PER_MBA][MAX_DIMM_PER_PORT] = {0};
        uint8_t l_power_curve_percent_uplift = 0;
        uint8_t l_power_curve_percent_uplift_idle = 0;
        uint32_t l_max_dram_databus_util = 0;
        uint32_t l_throttle_d = 0;

        // If MBA has no DIMMs, return as there is nothing to do
        if (mss::count_dimm(i_target_mba) == 0)
        {
            FAPI_INF("++++ NO DIMM on %s ++++", mss::c_str(i_target_mba));
            return fapi2::FAPI2_RC_SUCCESS;
        }

        // get input attributes
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_MAX_DRAM_DATABUS_UTIL,
                               fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_max_dram_databus_util));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_NUM_RANKS_PER_DIMM,
                               i_target_mba, l_dimm_ranks_array));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_TOTAL_POWER_SLOPE,
                               i_target_mba, l_total_power_slope_array));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_TOTAL_POWER_INT,
                               i_target_mba, l_total_power_int_array));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_DIMM_POWER_CURVE_PERCENT_UPLIFT,
                               fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_power_curve_percent_uplift));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_DIMM_POWER_CURVE_PERCENT_UPLIFT_IDLE,
                               fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_power_curve_percent_uplift_idle));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_MEM_M_DRAM_CLOCKS, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                               l_throttle_d));

        // If throttling is disabled, set max util to MAX_UTIL
        if (l_throttle_d == 0)
        {
            FAPI_INF("%s Memory Throttling is Disabled with M=0", mss::c_str(i_target_mba));
            l_max_dram_databus_util = MAX_UTIL;
        }

        // Maximum theoretical data bus utilization (percent of max) (for ceiling)
        // Comes from MRW value in c% - convert to %
        // We don't need to limit this because this function is only determining the channel pair power slope and interecpt
        l_max_util = convert_to_percent(static_cast<double>(l_max_dram_databus_util));

        for (l_port = 0; l_port < MAX_PORTS_PER_MBA; l_port++)
        {
            l_channel_power_array_idle[l_port] = 0;
            l_channel_power_array_max[l_port] = 0;

            for (l_dimm = 0; l_dimm < MAX_DIMM_PER_PORT; l_dimm++)
            {
                // default dimm power is zero (used for dimms that are not physically present)
                l_dimm_power_array_idle[l_port][l_dimm] = 0;
                l_dimm_power_array_max[l_port][l_dimm] = 0;

                // See if there are any ranks present on the dimm (configured or deconfigured)
                if ((l_dimm_ranks_array[l_port][l_dimm] > 0) && (l_total_power_slope_array[l_port][l_dimm] > 0)
                    && (l_total_power_int_array[l_port][l_dimm] > 0))
                {
                    l_dimm_power_array_idle[l_port][l_dimm] = l_dimm_power_array_idle[l_port][l_dimm] +
                            (convert_to_percent(IDLE_UTIL) * l_total_power_slope_array[l_port][l_dimm]) + l_total_power_int_array[l_port][l_dimm];
                    l_dimm_power_array_max[l_port][l_dimm] = l_dimm_power_array_max[l_port][l_dimm] + (convert_to_percent(l_max_util) *
                            l_total_power_slope_array[l_port][l_dimm]) + l_total_power_int_array[l_port][l_dimm];
                    // Include any system uplift here too
                    l_dimm_power_array_idle[l_port][l_dimm] =
                        l_dimm_power_array_idle[l_port][l_dimm] *
                        (1 + (static_cast<double>(l_power_curve_percent_uplift_idle)) / 100);
                    l_dimm_power_array_max[l_port][l_dimm] =
                        l_dimm_power_array_max[l_port][l_dimm] *
                        (1 + (static_cast<double>(l_power_curve_percent_uplift)) / 100);
                    FAPI_DBG("%s [P%d:D%d][IDLE/MAX CH Util %d/%4.2lf][Slope:Int %d:%d][UpliftPercent IDLE/MAX %d/%d)][IDLE/MAX Power %4.2lf/%4.2lf cW]",
                             mss::c_str(i_target_mba), l_port, l_dimm, IDLE_UTIL, l_max_util, l_total_power_slope_array[l_port][l_dimm],
                             l_total_power_int_array[l_port][l_dimm],
                             l_power_curve_percent_uplift_idle, l_power_curve_percent_uplift, l_dimm_power_array_idle[l_port][l_dimm],
                             l_dimm_power_array_max[l_port][l_dimm]);
                }

                // calculate channel power by adding up the power of each dimm
                l_channel_power_array_idle[l_port] += l_dimm_power_array_idle[l_port][l_dimm];
                l_channel_power_array_max[l_port] += l_dimm_power_array_max[l_port][l_dimm];
            }

            FAPI_DBG("%s [P%d][IDLE/MAX CH Util %d/%4.2lf][IDLE/MAX Power %4.2lf/%4.2lf cW]",
                     mss::c_str(i_target_mba), l_port, IDLE_UTIL, l_max_util,
                     l_channel_power_array_idle[l_port], l_channel_power_array_max[l_port]);
            l_channel_pair_power_idle += l_channel_power_array_idle[l_port];
            l_channel_pair_power_max += l_channel_power_array_max[l_port];
        }

        // calculate the slope/intercept values from power values just calculated above
        o_channel_power_slope = (l_channel_pair_power_max - l_channel_pair_power_idle) / ( convert_to_percent(l_max_util) -
                                convert_to_percent(IDLE_UTIL) );
        o_channel_power_intercept = l_channel_pair_power_idle;

        FAPI_INF("%s [Channel Pair Power IDLE/MAX %4.2lf/%4.2lf cW][Slope/Intercept %4.2lf/%4.2lf cW]",
                 mss::c_str(i_target_mba), l_channel_pair_power_idle, l_channel_pair_power_max, o_channel_power_slope,
                 o_channel_power_intercept);


        FAPI_INF("*** p9c_mss_bulk_pwr_channel_pair_power_curve COMPLETE on %s ***", mss::c_str(i_target_mba));

    fapi_try_exit:
        return fapi2::current_err;
    }


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
            const bool i_utilization_is_a_min_value
                                                             )
    {
        FAPI_INF("*** Running p9c_mss_bulk_pwr_util_to_throttle_power on %s ***", mss::c_str(i_target_mba));
        FAPI_INF("%s [Input Util %4.2lf percent]", mss::c_str(i_target_mba), i_utilization);

        // Limit max utilization to 100% DMI utilization so we don't end up with memory powers that can never be achieved
        // For CDIMMs, limit to 56.25% dram data bus utilization (Note that CDIMMs have both MBAs with DIMMs)
        // For ISDIMMs, limit to 56.25% dram data bus utilization if both MBAs have DIMMs
        // For ISDIMMs, no limitation if only one MBA has DIMMs (power will be higher than it should be, but this is not a full
        //     configuration so we should not be stressing any power limitations so ok to over estimate the power)
        double l_max_util = 0;
        uint8_t l_custom_dimm = 0;
        uint32_t l_throttle_d = 0;
        uint32_t l_throttle_n_per_mba = 0;
        uint32_t l_throttle_n_per_chip = 0;
        uint8_t l_num_mba_with_dimms = 0;
        uint32_t l_max_dram_databus_util = 0;
        uint32_t l_channel_pair_power = 0;
        uint8_t l_throttle_multiplier = 0;
        double l_max_util_power_calc = 0;
        double l_util_power_calc = 0;
        double l_utilization_calc_without_throttle_adder = 0;
        double l_utilization_calc = 0;
        uint8_t l_throttle_adder = 0;

        // If MBA has no DIMMs, return as there is nothing to do
        if (mss::count_dimm(i_target_mba) == 0)
        {
            FAPI_INF("++++ NO DIMM on %s ++++", mss::c_str(i_target_mba));
            return fapi2::FAPI2_RC_SUCCESS;
        }

        // get input attributes
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_MAX_DRAM_DATABUS_UTIL,
                               fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_max_dram_databus_util));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CUSTOM_DIMM, i_target_mba,  l_custom_dimm));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_MEM_M_DRAM_CLOCKS, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                               l_throttle_d));

        // If throttling is disabled, set max util to MAX_UTIL
        if (l_throttle_d == 0)
        {
            FAPI_INF("%s Memory Throttling is Disabled with M=0", mss::c_str(i_target_mba));
            l_max_dram_databus_util = MAX_UTIL;
        }

        // Maximum theoretical data bus utilization (percent of max) (for ceiling)
        // Comes from MRW value in c% - convert to %
        if (l_max_dram_databus_util > MAX_UTIL)
        {
            l_max_dram_databus_util = MAX_UTIL;
            FAPI_INF("%s [Max Util Limited to %4.2lf centi percent]", mss::c_str(i_target_mba), l_max_dram_databus_util);
        }

        l_max_util = convert_to_percent(static_cast<double>(l_max_dram_databus_util));

        // Limit input utilization if needed
        if (i_utilization > l_max_util)
        {
            i_utilization = l_max_util;
            FAPI_INF("%s [Input Util Limited to %4.2lf percent]", mss::c_str(i_target_mba), i_utilization);
        }

        // get number of mba's with dimms, used below to help determine utilization values for power calculations
        // Have to have this section in braces otherwise compile fails
        {
            const auto& l_target_chip = mss::find_target<TARGET_TYPE_MEMBUF_CHIP>(i_target_mba);

            for (const auto& l_mba : mss::find_targets<TARGET_TYPE_MBA>(l_target_chip))
            {
                if (mss::count_dimm(l_mba) > 0)
                {
                    l_num_mba_with_dimms++;
                }
            }
        }

        // Set the throttle multiplier based on how throttles are used
        // CDIMMs use per mba and per chip throttles (for l_throttle_n_per_mba and l_throttle_n_per_chip), set to 2
        // ISDIMMs use per slot and per mba throttles (for l_throttle_n_per_mba and l_throttle_n_per_chip), set to 1
        l_throttle_multiplier = (l_custom_dimm == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES) ? 2 : 1;

        FAPI_INF("%s [Number MBAs with DIMMs %d][Throttle Multiplier %d]", mss::c_str(i_target_mba), l_num_mba_with_dimms,
                 l_throttle_multiplier);

        // Power calculation for channel pair power
        l_max_util_power_calc = l_max_util;

        if (l_num_mba_with_dimms > 1)
        {
            l_max_util_power_calc = (l_max_util < (convert_to_percent(static_cast<double>(DRAM_UTIL_LIMIT_BOTH_MBA_WITH_DIMMS)))) ?
                                    l_max_util : (convert_to_percent(static_cast<double>(DRAM_UTIL_LIMIT_BOTH_MBA_WITH_DIMMS)));
        }

        FAPI_INF("%s [Max Util for power calculations %4.2lf percent]", mss::c_str(i_target_mba), l_max_util_power_calc);

        // Limit utilization to max utilization
        l_util_power_calc = (i_utilization > l_max_util_power_calc) ? l_max_util_power_calc : i_utilization;
        FAPI_INF("%s [Util for power calculations %4.2lf percent]", mss::c_str(i_target_mba), l_util_power_calc);

        // call p9c_mss_bulk_pwr_util_to_throttle to get the memory throttle Nmba and Nchip settings for the realistic load for power calculations
        FAPI_TRY(p9c_mss_bulk_pwr_util_to_throttle(i_target_mba, l_util_power_calc, l_max_util_power_calc, l_throttle_n_per_mba,
                 l_throttle_n_per_chip, l_throttle_adder, i_utilization_is_a_min_value));

        // Calculate out the utilization at the throttle settings determined for power calculations (units %)
        // throttling disabled with M=0, use MAX_UTIL
        if (l_throttle_d == 0)
        {
            l_util_power_calc = convert_to_percent(static_cast<double>(MAX_UTIL));
        }
        // throttling enabled, use calculated throttle settings to determine utilization
        else
        {
            l_util_power_calc = (static_cast<double>(l_throttle_n_per_chip)) * ADDR_TO_DATA_UTIL_CONVERSION / l_throttle_d /
                                l_throttle_multiplier * PERCENT_CONVERSION;
        }

        // Calculate out the channel pair power at this new utilization setting
        l_channel_pair_power = static_cast<uint32_t>((convert_to_percent(l_util_power_calc)) * i_channel_power_slope +
                               i_channel_power_intercept);

        FAPI_INF("%s [Throttles for power calculations %d/%d/%d]",
                 mss::c_str(i_target_mba), l_throttle_n_per_mba, l_throttle_n_per_chip, l_throttle_d);
        FAPI_INF("%s [UTIL for power calculations %4.2lf percent][Channel Pair Power %d cW]",
                 mss::c_str(i_target_mba), l_util_power_calc, l_channel_pair_power);

        // N Throttle determination (throttles that will actually be used in hardware)
        // Here we calculate the throttle settings based on the input utilization
        // Note that the channel pair power is not based on these since those throttle values could be limited
        // call p9c_mss_bulk_pwr_util_to_throttle to get the memory throttle Nmba and Nchip settings for the input utilization
        FAPI_TRY(p9c_mss_bulk_pwr_util_to_throttle(i_target_mba, i_utilization, l_max_util, l_throttle_n_per_mba,
                 l_throttle_n_per_chip, l_throttle_adder, i_utilization_is_a_min_value));

        // Calculate out the utilization at the throttle settings determined based on input utilization
        // throttling disabled with M=0, use MAX_UTIL
        if (l_throttle_d == 0)
        {
            l_utilization_calc = convert_to_percent(static_cast<double>(MAX_UTIL));
            l_utilization_calc_without_throttle_adder = convert_to_percent(static_cast<double>(MAX_UTIL));
        }
        // throttling enabled, use calculated throttle settings to determine utilization
        else
        {
            l_utilization_calc = (static_cast<double>(l_throttle_n_per_chip)) * ADDR_TO_DATA_UTIL_CONVERSION / l_throttle_d /
                                 l_throttle_multiplier * PERCENT_CONVERSION;
            l_utilization_calc_without_throttle_adder = (static_cast<double>(l_throttle_n_per_chip - l_throttle_adder)) *
                    ADDR_TO_DATA_UTIL_CONVERSION /
                    l_throttle_d / l_throttle_multiplier * PERCENT_CONVERSION;
        }

        FAPI_INF("%s [Final Utilization %4.2lf percent][Final Throttles %d/%d/%d]",
                 mss::c_str(i_target_mba), l_utilization_calc, l_throttle_n_per_mba, l_throttle_n_per_chip, l_throttle_d);

        // Update output attributes
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_MEM_THROTTLE_NUMERATOR_PER_MBA,
                               i_target_mba, l_throttle_n_per_mba));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_MEM_THROTTLE_NUMERATOR_PER_CHIP,
                               i_target_mba, l_throttle_n_per_chip));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_MEM_THROTTLE_DENOMINATOR,
                               i_target_mba, l_throttle_d));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_CEN_MSS_CHANNEL_PAIR_MAXPOWER,
                               i_target_mba, l_channel_pair_power));

        // Check for error condition if input utilization was a minimum target value to ensure we have
        //     throttle values that meet it (ie.  throttles have util equal to or greater than min util target)
        // Note:  this applies when p9c_mss_util_to_throttle calls this function
        // The calculated utilization could be much higher than the min target, so this will check for that
        // Check should make sure input utilization is equal to or less than calculated util without throttle adder
        //   and input utilization is equal to or greater than the calculated utilization without throttle adder

        FAPI_ASSERT( !((i_utilization_is_a_min_value == true) &&
                       ((l_utilization_calc < i_utilization) ||
                        (l_utilization_calc_without_throttle_adder > i_utilization))),
                     fapi2::CEN_MSS_MIN_UTILIZATION_ERROR().
                     set_UTIL_CALC(static_cast<uint32_t>(l_utilization_calc * PERCENT_CONVERSION)).
                     set_UTIL_TARGET(static_cast<uint32_t>(i_utilization * PERCENT_CONVERSION)).
                     set_MEM_MBA(i_target_mba),
                     "%s Calculated util [%d:%d centi percent] does not meet input min util target [%d centi percent]",
                     mss::c_str(i_target_mba),
                     static_cast<uint32_t>(l_utilization_calc_without_throttle_adder * PERCENT_CONVERSION),
                     static_cast<uint32_t>(l_utilization_calc * PERCENT_CONVERSION),
                     static_cast<uint32_t>(i_utilization * PERCENT_CONVERSION)
                   );

        FAPI_INF("*** p9c_mss_bulk_pwr_util_to_throttle_power COMPLETE on %s ***", mss::c_str(i_target_mba));

    fapi_try_exit:
        return fapi2::current_err;
    }


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
            const bool i_utilization_is_a_min_value
                                                       )
    {
        FAPI_INF("*** Running p9c_mss_bulk_pwr_util_to_throttle on %s ***", mss::c_str(i_target_mba));

        constexpr uint32_t l_min_n_throttle = 1;
        uint32_t l_runtime_throttle_n_per_mba = 0;
        uint32_t l_runtime_throttle_n_per_chip = 0;
        uint8_t l_custom_dimm = 0;
        uint32_t l_throttle_d = 0;
        uint8_t l_throttle_multiplier = 0;
        double l_utilization_calc = 0;

        // get input attributes
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_EFF_CUSTOM_DIMM, i_target_mba,  l_custom_dimm));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_MEM_M_DRAM_CLOCKS, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                               l_throttle_d));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_RUNTIME_MEM_THROTTLE_NUMERATOR_PER_MBA,
                               i_target_mba, l_runtime_throttle_n_per_mba));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MSS_RUNTIME_MEM_THROTTLE_NUMERATOR_PER_CHIP,
                               i_target_mba, l_runtime_throttle_n_per_chip));

        // Set the throttle multiplier based on how throttles are used
        // CDIMMs use per mba and per chip throttles (for l_throttle_n_per_mba and l_throttle_n_per_chip), set to 2
        // ISDIMMs use per slot and per mba throttles (for l_throttle_n_per_mba and l_throttle_n_per_chip), set to 1
        l_throttle_multiplier = (l_custom_dimm == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES) ? 2 : 1;

        // If input util is a min target, then we need to end up with a utilization equal to or higher than it
        // Set the throttle adder based on whether input utilization is a min or a max target
        // Account for the case when the calculated utilization will equal the input utilization
        if ( ( static_cast<uint32_t>((convert_to_percent(i_utilization)) * l_throttle_d / ADDR_TO_DATA_UTIL_CONVERSION *
                                     PERCENT_CONVERSION) !=
               ( static_cast<uint32_t>((convert_to_percent(i_utilization)) * l_throttle_d / ADDR_TO_DATA_UTIL_CONVERSION) *
                 PERCENT_CONVERSION) )
             && (i_utilization_is_a_min_value == true) )
        {
            o_throttle_adder = 1;
        }

        // Calculate the NperChip and NperMBA Throttles
        //   Uses N/M Throttling.   Equation:  (DRAM data bus utilization Percent / 100 ) = ((N * 4) / M)
        //   The 4 is a constant since dram data bus utilization is 4X the address bus utilization
        // adjust the throttles to minimum utilization if needed
        l_utilization_calc = (i_utilization < UTIL_FLOOR) ? UTIL_FLOOR : i_utilization;
        o_throttle_n_per_chip = static_cast<uint32_t>(((convert_to_percent(l_utilization_calc)) * l_throttle_d /
                                ADDR_TO_DATA_UTIL_CONVERSION) * l_throttle_multiplier +
                                o_throttle_adder);

        // For throttling efficiency, have the per mba throttle be at max value as long as it is less than or equal to the per chip throttle
        if (o_throttle_n_per_chip > ((convert_to_percent(i_max_util)) * l_throttle_d / ADDR_TO_DATA_UTIL_CONVERSION) )
        {
            o_throttle_n_per_mba = static_cast<uint32_t>(((convert_to_percent(i_max_util)) * l_throttle_d /
                                   ADDR_TO_DATA_UTIL_CONVERSION));
        }
        else
        {
            o_throttle_n_per_mba = o_throttle_n_per_chip;
        }

        // ensure that N throttle values are not zero, if so set to l_min_n_throttle to prevent hangs
        if ( (o_throttle_n_per_mba == 0) || (o_throttle_n_per_chip == 0))
        {
            o_throttle_n_per_mba = l_min_n_throttle;
            o_throttle_n_per_chip = o_throttle_n_per_mba * l_throttle_multiplier;
        }

        // for better custom dimm performance, set the per mba throttle to the per chip throttle
        o_throttle_n_per_mba = (l_custom_dimm == fapi2::ENUM_ATTR_CEN_EFF_CUSTOM_DIMM_YES) ? o_throttle_n_per_chip :
                               o_throttle_n_per_mba;

        // adjust the throttles to the runtime throttles that are based on thermal/power limits
        if ( (o_throttle_n_per_mba > l_runtime_throttle_n_per_mba) ||
             (o_throttle_n_per_chip > l_runtime_throttle_n_per_chip) )
        {
            FAPI_INF("%s Throttles for power calculations [%d/%d/%d] will be limited to runtime throttle values [%d/%d/%d].",
                     mss::c_str(i_target_mba), o_throttle_n_per_mba, o_throttle_n_per_chip, l_throttle_d,
                     l_runtime_throttle_n_per_mba, l_runtime_throttle_n_per_chip, l_throttle_d);
            o_throttle_n_per_mba = (o_throttle_n_per_mba > l_runtime_throttle_n_per_mba) ? l_runtime_throttle_n_per_mba :
                                   o_throttle_n_per_mba;
            o_throttle_n_per_chip = (o_throttle_n_per_chip > l_runtime_throttle_n_per_chip) ? l_runtime_throttle_n_per_chip :
                                    o_throttle_n_per_chip;
        }

        FAPI_INF("*** p9c_mss_bulk_pwr_util_to_throttle COMPLETE on %s ***", mss::c_str(i_target_mba));

    fapi_try_exit:
        return fapi2::current_err;
    }


} //end extern C


