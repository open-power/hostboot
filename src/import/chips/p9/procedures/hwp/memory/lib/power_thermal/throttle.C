/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/power_thermal/throttle.C $ */
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
/// @file throttle.C
/// @brief Determine throttle settings for memory
///
// *HWP HWP Owner: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP HWP Backup: Andre A. Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB
//std lib
#include<algorithm>
// fapi2
#include <fapi2.H>

// mss lib
#include <lib/power_thermal/throttle.H>
#include <lib/utils/count_dimm.H>
#include <mss.H>
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_DIMM;
using fapi2::TARGET_TYPE_MCBIST;

namespace mss
{
namespace power_thermal
{

///
/// @brief Constructor
/// @param[in] i_target MCS target to call power thermal stuff on
/// @param[out] o_rc, a return code which determines the success of the constructor
///
throttle::throttle( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_mca, fapi2::ReturnCode& o_rc) :
    iv_target(i_mca),
    iv_databus_port_max(0),
    iv_runtime_n_slot(0),
    iv_runtime_n_port(0),
    iv_n_slot(0),
    iv_n_port(0),
    iv_port_power_limit(0),
    iv_calc_port_maxpower(0)
{
    //holder for watt_target to add up for port
    uint32_t l_dimm_power_limits [MAX_DIMM_PER_PORT] = {};

    FAPI_TRY( mrw_max_dram_databus_util(iv_databus_port_max), "%s Error in throttle ctor", mss::c_str(i_mca) );
    FAPI_TRY( mrw_dimm_power_curve_percent_uplift(iv_power_uplift), "%s Error in throttle ctor", mss::c_str(i_mca) );
    FAPI_TRY( mrw_dimm_power_curve_percent_uplift_idle(iv_power_uplift_idle), "%s Error in throttle ctor",
              mss::c_str(i_mca) );
    FAPI_TRY( dimm_thermal_limit( iv_target, iv_dimm_thermal_limit), "%s Error in throttle ctor", mss::c_str(i_mca) );
    FAPI_TRY( total_pwr_intercept( iv_target, iv_pwr_int), "%s Error in throttle ctor", mss::c_str(i_mca) );
    FAPI_TRY( total_pwr_slope( iv_target, iv_pwr_slope), "%s Error in throttle ctor", mss::c_str(i_mca) );
    FAPI_TRY( runtime_mem_throttled_n_commands_per_slot(iv_target, iv_runtime_n_slot ), "%s Error in throttle ctor",
              mss::c_str(i_mca) );
    FAPI_TRY( runtime_mem_throttled_n_commands_per_port(iv_target, iv_runtime_n_port ), "%s Error in throttle ctor",
              mss::c_str(i_mca) );
    FAPI_TRY( mem_watt_target( iv_target, l_dimm_power_limits), "%s Error in throttle ctor", mss::c_str(i_mca) );
    FAPI_TRY( mrw_mem_m_dram_clocks(iv_m_clocks), "%s Error in throttle ctor", mss::c_str(i_mca) );

    //Port power limit = sum of dimm power limits
    for ( const auto& l_dimm : mss::find_targets<TARGET_TYPE_DIMM>(iv_target) )
    {
        iv_port_power_limit += l_dimm_power_limits[mss::index(l_dimm)];
    }

    FAPI_INF("Setting up throttle for target %s, Values are: max databus is %d, uplifts are %d %d, runtime throttles are %d %d",
             mss::c_str(iv_target),
             iv_databus_port_max,
             iv_power_uplift,
             iv_power_uplift_idle,
             iv_runtime_n_slot,
             iv_runtime_n_port);

    FAPI_INF("The dimm power limit for dimm0 is %d, dimm1 is %d,  port power limit is %d, dram clocks are %d, dimm power curve slopes are %d %d,",
             l_dimm_power_limits[0],
             l_dimm_power_limits[1],
             iv_port_power_limit,
             iv_m_clocks,
             iv_pwr_slope[0],
             iv_pwr_slope[1]);

    FAPI_INF("DIMM power curve intercepts are %d %d, DIMM power thermal limits are %d %d",
             iv_pwr_int[0],
             iv_pwr_int[1],
             iv_dimm_thermal_limit[0],
             iv_dimm_thermal_limit[1]);

    FAPI_ASSERT( (iv_databus_port_max != 0),
                 fapi2::MSS_NO_DATABUS_UTILIZATION()
                 .set_PORT_DATABUS_UTIL(iv_databus_port_max)
                 .set_DIMM_COUNT(mss::count_dimm(iv_target)),
                 "Failed to get max databus utilization for target %s",
                 mss::c_str(iv_target));

    FAPI_ASSERT( (iv_port_power_limit != 0),
                 fapi2::MSS_NO_PORT_POWER_LIMIT()
                 .set_COUNT_DIMMS( mss::count_dimm(iv_target))
                 .set_PORT_POWER_LIMIT( iv_port_power_limit),
                 "Error calculating port_power_limit on target %s with %d DIMMs installed",
                 mss::c_str(iv_target),
                 iv_port_power_limit);

    //Checking to make sure all of the attributes are valid
    for ( const auto& l_dimm : mss::find_targets<TARGET_TYPE_DIMM>(iv_target) )
    {
        const auto l_pos = mss::index(l_dimm);
        FAPI_ASSERT( (iv_pwr_int[l_pos] != 0),
                     fapi2::MSS_POWER_INTERCEPT_NOT_SET(),
                     "The attribute ATTR_MSS_TOTAL_PWR_INTERCEPT equals 0 for %s",
                     mss::c_str(l_dimm));

        FAPI_ASSERT( (iv_pwr_slope[l_pos] != 0),
                     fapi2::MSS_POWER_SLOPE_NOT_SET(),
                     "The attribute ATTR_MSS_TOTAL_PWR_SLOPE equals 0 for %s",
                     mss::c_str(l_dimm));
    }

fapi_try_exit:
    o_rc = fapi2::current_err;
    return;
}

///
/// @brief Set ATTR_MSS_CHANNEL_PAIR_MAXPOWER, ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_SLOT and _PER_PORT
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
/// @note Called in p9_mss_bulk_pwr_throttles
/// @note determines the throttle levels based off of the port's power curve,
/// @note the _per_slot throttles are set to the _per_port values
/// @note throttles are all equalized and set to the worst case value
///
fapi2::ReturnCode throttle::power_regulator_throttles ()
{
    double l_port_power_calc_idle = 0;
    double l_port_power_calc_max = 0;
    uint32_t l_port_power_slope = 0;
    uint32_t l_port_power_int = 0;
    double l_calc_util_port = 0;
    double  l_databus_dimm_max[MAX_DIMM_PER_PORT] = {};
    double  l_calc_databus_port_idle[MAX_DIMM_PER_PORT] = {IDLE_UTIL, IDLE_UTIL};

    FAPI_INF("Starting power regulator throttles");

    //Decide utilization for each dimm based off of dimm count and power slopes
    FAPI_TRY( calc_databus(iv_databus_port_max, l_databus_dimm_max),
              "Failed to calculate each DIMMs' percentage of dram databus utilization for target %s, max port databus is %d",
              mss::c_str(iv_target),
              iv_databus_port_max);

    //Use the dimm utilizations and dimm power slopes to calculate port min and max power
    FAPI_TRY( calc_port_power(l_calc_databus_port_idle,
                              l_databus_dimm_max,
                              l_port_power_calc_idle,
                              l_port_power_calc_max),
              "Failed to calculate the max and idle power for port %s",
              mss::c_str(iv_target));

    FAPI_INF("POWER throttles: %s max port power is %f", mss::c_str(iv_target), l_port_power_calc_max);

    //Calculate the power curve slope and intercept using the port's min and max power values
    FAPI_TRY(calc_power_curve(l_port_power_calc_idle,
                              l_port_power_calc_max,
                              l_port_power_slope,
                              l_port_power_int),
             "Failed to calculate the power curve for port %s, calculated port power max is %d, idle is %d",
             mss::c_str(iv_target),
             l_port_power_calc_max,
             l_port_power_calc_idle);

    FAPI_INF("%s POWER Port power limit is %d", mss::c_str(iv_target), iv_port_power_limit);
    //Calculate the port's utilization to get under watt target using the port's calculated slopes
    calc_util_usage(l_port_power_slope,
                    l_port_power_int,
                    iv_port_power_limit,
                    l_calc_util_port);

    FAPI_INF("%s POWER calc util port is %f",  mss::c_str(iv_target), l_calc_util_port);

    //Calculate the new slot values and the max power value for the port
    FAPI_TRY( calc_slots_and_power( l_calc_util_port),
              "%s Error calculating the final throttles and power values for target with passed in port utilization %d",
              mss::c_str(iv_target),
              l_calc_util_port);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief set iv_n_port, iv_n_slot, iv_calc_port_maxpower
/// @param[in] i_util_port pass in the calculated port databus utilization
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
///
fapi2::ReturnCode throttle::calc_slots_and_power (const double i_util_port)
{
    //Calculate the Port N throttles
    iv_n_port = power_thermal::throttled_cmds(i_util_port, iv_m_clocks);

    //Set iv_n_slot to the lower value between the slot runtime and iv_n_port
    iv_n_slot = (iv_runtime_n_slot != 0) ? std::min (iv_n_port, iv_runtime_n_slot) : iv_n_port;

    //Choose the lowest value of the runtime and the calculated
    iv_n_port = (iv_runtime_n_port != 0) ? std::min (iv_n_port, iv_runtime_n_port) : iv_n_port;

    //Use the throttle value to calculate the power that gets to exactly that value
    FAPI_TRY( calc_power_from_n(iv_n_slot, iv_n_port, iv_calc_port_maxpower));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_SLOT and PER_PORT
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
/// @note Called in p9_mss_bulk_pwr_throttles
/// @note Sets the throttle levels based off of the dimm's thermal limits
/// @note both DIMM's on a port are set to the same throttle level
///
fapi2::ReturnCode throttle::thermal_throttles ()
{
    double l_dimm_power_idle [MAX_DIMM_PER_PORT] = {};
    double l_dimm_power_max [MAX_DIMM_PER_PORT] = {};
    uint32_t l_dimm_power_slope [MAX_DIMM_PER_PORT] = {};
    uint32_t l_dimm_power_int [MAX_DIMM_PER_PORT] = {};
    double l_calc_util [MAX_DIMM_PER_PORT] = {};
    const auto l_count = count_dimm (iv_target);

    //Calculate the dimm power range for each dimm at max utilization for each
    calc_dimm_power(power_thermal::IDLE_UTIL,
                    iv_databus_port_max,
                    l_dimm_power_idle,
                    l_dimm_power_max);

    //Let's calculate the N throttle for each DIMM
    for ( const auto& l_dimm : mss::find_targets<TARGET_TYPE_DIMM>(iv_target) )
    {
        uint16_t l_temp_n_slot = 0;
        uint8_t l_pos = mss::index(l_dimm);
        //Calculate the power curve taking the thermal limit into account
        FAPI_TRY( calc_power_curve(l_dimm_power_idle[l_pos],
                                   l_dimm_power_max[l_pos],
                                   l_dimm_power_slope[l_pos],
                                   l_dimm_power_int[l_pos]),
                  "Failed to calculate the power curve for dimm %s, calculated dimm power curve slope is %d, intercept %d",
                  mss::c_str(l_dimm),
                  l_dimm_power_slope[l_pos],
                  l_dimm_power_int[l_pos]);

        //Calculate the databus utilization at the calculated power curve
        calc_util_usage(l_dimm_power_slope[l_pos],
                        l_dimm_power_int[l_pos],
                        iv_dimm_thermal_limit[l_pos],
                        l_calc_util[l_pos]);

        FAPI_INF("THERMAL throttles: %s dram databus utilization is %f", mss::c_str(l_dimm), l_calc_util[l_pos]);

        l_temp_n_slot = power_thermal::throttled_cmds (l_calc_util[l_pos], iv_m_clocks);

        //Set to the min between the two value
        //If iv_n_slot == 0 (so uninitialized), set it to the calculated slot value
        //The l_n_slot value can't be equal to 0 because there's a dimm installed
        if ((l_temp_n_slot < iv_n_slot) || (iv_n_slot == 0))
        {
            iv_n_slot = l_temp_n_slot;
        }
    }

    //Set to lowest value between calculated and runtime
    FAPI_INF("THERMAL throttles: runtime slot is %d, calc n slot is %d", iv_runtime_n_slot, iv_n_slot);
    //Taking the min of the SLOT * (# of dimms on the port) and the iv_runtime_port throttle value
    //Thermal throttling happens after the POWER calculations. the iv_runtime_n_port value shouldn't be set to 0
    iv_n_port = std::min(iv_runtime_n_port, static_cast<uint16_t>(iv_n_slot * l_count));
    iv_n_port = (iv_n_port == 0) ? MIN_THROTTLE : iv_n_port;

    iv_n_slot = std::min(iv_n_slot, iv_runtime_n_slot);
    iv_n_slot = (iv_n_slot == 0) ? MIN_THROTTLE : iv_n_slot;

    //Now time to get and set iv_calc_port_max from the calculated N throttle
    FAPI_TRY( calc_power_from_n(iv_n_slot, iv_n_port, iv_calc_port_maxpower),
              "Failed to calculate the final max port maxpower. Slot throttle value is %d, port value is %d",
              iv_n_slot,
              iv_n_port);

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    FAPI_ERR("Error calculating mss::power_thermal::thermal_throttles()");
    return fapi2::current_err;
}

///
/// @brief Calculates the min and max power usage for a port based off of power curves and utilizations
/// @param[in] i_idle_util the utilization of the databus in idle mode (0% most likely)
/// @param[in] i_max_util the utilization of the dimm at maximum possible percentage (mrw or calculated)
/// @param[out] o_port_power_idle max value of port power in cW
/// @param[out] o_port_power_max max value of port power in cW
/// @return fapi2::FAPI2_RC_SUCCESS iff the method was a success
/// @note Called twice in p9_mss_bulk_pwr_throttles
/// @note uses dimm power curves from class variables
///
fapi2::ReturnCode throttle::calc_port_power(const double i_idle_util [MAX_DIMM_PER_PORT],
        const double i_max_util [MAX_DIMM_PER_PORT],
        double& o_port_power_idle,
        double& o_port_power_max) const
{
    //Playing it safe
    o_port_power_idle = 0;
    o_port_power_max = 0;

    //Calculate the port power curve info by summing the dimms on the port
    for ( const auto& l_dimm : mss::find_targets<TARGET_TYPE_DIMM>(iv_target) )
    {
        const auto l_pos = mss::index(l_dimm);
        //Printing as decimals because HB messes up floats
        FAPI_INF("%s max dram databus for DIMM in pos %d is %d, databus for idle is %d",
                 mss::c_str(iv_target),
                 l_pos,
                 static_cast<uint64_t>( i_max_util[l_pos]),
                 static_cast<uint64_t>( i_idle_util[l_pos]) );
        //Sum up the dim's power to calculate the port power curve
        o_port_power_idle += calc_power(i_idle_util[l_pos], l_pos);
        o_port_power_max  += calc_power(i_max_util[l_pos], l_pos);
    }

    //Raise the powers by the uplift percent
    calc_power_uplift(iv_power_uplift_idle, o_port_power_idle);
    calc_power_uplift(iv_power_uplift, o_port_power_max);

    FAPI_ASSERT( (o_port_power_max > 0),
                 fapi2::MSS_NO_PORT_POWER()
                 .set_COUNT_DIMMS(mss::count_dimm(iv_target))
                 .set_MAX_UTILIZATION_DIMM_0(i_max_util[0])
                 .set_MAX_UTILIZATION_DIMM_1(i_max_util[1]),
                 "No Port Power limit was calculated for %s, %d DIMMs installed, utilizations: DIMM 0 %d, DIMM 1 %d",
                 mss::c_str(iv_target),
                 mss::count_dimm(iv_target),
                 i_max_util[0],
                 i_max_util[1]);

    //FAPI_ASSERTs don't set the current err to good
    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Calculates max and min power usages based off of DIMM power curves
/// @param[in] i_databus_idle idle databus utilization (either calculated or mrw)
/// @param[in] i_databus_max max databus utilization (either calculated or mrw)
/// @param[out] o_dimm_power_idle array of dimm power in cW
/// @param[out] o_dimm_power_max array of dimm power in cW
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff the split is OK
/// @note Called in p9_mss_bulk_pwr_throttles
/// @note used for the thermal throttles
///
void throttle::calc_dimm_power(const double i_databus_idle,
                               const double i_databus_max,
                               double o_dimm_power_idle [MAX_DIMM_PER_PORT],
                               double o_dimm_power_max [MAX_DIMM_PER_PORT]) const
{
    for ( const auto& l_dimm : mss::find_targets<TARGET_TYPE_DIMM>(iv_target) )
    {
        const uint8_t l_pos = mss::index(l_dimm);
        o_dimm_power_idle[l_pos] = calc_power(i_databus_idle, l_pos);
        o_dimm_power_max[l_pos]  = calc_power(i_databus_max, l_pos);

        //Raise the powers by the uplift percent

        calc_power_uplift(iv_power_uplift_idle, o_dimm_power_idle[l_pos]);
        calc_power_uplift(iv_power_uplift, o_dimm_power_max[l_pos]);

        FAPI_INF("Calc_dimm_power: dimm (%d) power max is %f, %f for  dimm slope of  %d, intercept of %d",
                 l_pos,
                 o_dimm_power_max[l_pos],
                 o_dimm_power_max[l_pos],
                 iv_pwr_slope[l_pos],
                 iv_pwr_int[l_pos]);
    }
}

///
/// @brief Calculate the port power curve in order to calculate the port utilization
/// @param[in] i_power_idle double of the port's power consumption at idle
/// @param[in] i_power_max double of the port's power consumption at max utilization
/// @param[out] o_slope
/// @param[out] o_int
/// @note Called in p9_mss_bulk_pwr_throttles
/// @note Port power curve needed to calculate the port utilization
///
fapi2::ReturnCode throttle::calc_power_curve(const double i_power_idle,
        const double i_power_max,
        uint32_t& o_slope,
        uint32_t& o_int) const
{
    const double l_divisor = ((static_cast<double>(iv_databus_port_max) / UTIL_CONVERSION) - IDLE_UTIL);
    FAPI_ASSERT ((l_divisor > 0),
                 fapi2::MSS_CALC_POWER_CURVE_DIVIDE_BY_ZERO()
                 .set_PORT_DATABUS_UTIL(iv_databus_port_max)
                 .set_UTIL_CONVERSION(UTIL_CONVERSION)
                 .set_IDLE_UTIL(IDLE_UTIL)
                 .set_RESULT(l_divisor),
                 "Calculated zero for the divisor in calc_power_curve on target %s",
                 mss::c_str(iv_target) );

    o_slope = (i_power_max - i_power_idle) / l_divisor;
    o_int = i_power_idle - (o_slope * IDLE_UTIL);
    FAPI_INF("Calc_power_curve: power idle is %f, max is %f, slope is %d, int is %d",
             i_power_idle,
             i_power_max,
             o_slope,
             o_int);
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    FAPI_INF("Error calculating mss::power_thermal::calc_power_curve");
    return fapi2::current_err;

}

///
/// @brief Calculate the databus utilization given the power curve
/// @param[in] i_slope
/// @param[in] i_int
/// @param[in] i_power_limit either the port_power_limit or the dimm thermal power limit
/// @param[out] o_port_util the port's databus utilization
/// @note Called in p9_mss_bulk_pwr_throttles
/// @note Chooses worst case between the maximum allowed databus utilization and the calculated value
///
void throttle::calc_util_usage(const uint32_t i_slope,
                               const uint32_t i_int,
                               const uint32_t i_power_limit,
                               double& o_util) const
{
    o_util = ((static_cast<double>(i_power_limit) - i_int) / i_slope ) * UTIL_CONVERSION;

    //Cast to uint32 for edge case where it has decimals
    o_util = (static_cast<uint32_t>(o_util) < iv_databus_port_max) ? static_cast<uint32_t>(o_util) : iv_databus_port_max;

    // Check for the minimum threshnold and update if need be
    if(o_util < MIN_UTIL)
    {
        FAPI_INF("Calculated utilization (%lu) is less than the minimum utilization: %lu. Setting to minimum value", o_util,
                 MIN_UTIL);
        o_util = MIN_UTIL;
    }
}

///
/// @brief calculated the output power estimate from the calculated N throttle
/// @param[in] i_n_slot the throttle per slot in terms of N commands
/// @param[in] i_n_port the throttle per port in terms of N commands
/// @param[out] o_power the calculated power
/// @return fapi2::ReturnCode iff it was a success
///
fapi2::ReturnCode throttle::calc_power_from_n (const uint16_t i_n_slot,
        const uint16_t i_n_port,
        uint32_t& o_power) const
{
    double l_calc_util_port = 0;
    double l_calc_util_slot = 0;
    double l_calc_databus_port_max[MAX_DIMM_PER_PORT] = {};
    double l_calc_databus_port_idle[MAX_DIMM_PER_PORT] = {};
    double l_port_power_max = 0;
    double l_port_power_idle = 0;

    FAPI_TRY( calc_util_from_throttles(i_n_slot, iv_m_clocks, l_calc_util_slot),
              "%s Error calculating utilization from slot throttle %d and mem clocks %d",
              mss::c_str(iv_target),
              i_n_slot,
              iv_m_clocks);
    FAPI_TRY( calc_util_from_throttles(i_n_port, iv_m_clocks, l_calc_util_port),
              "%s Error calculating utilization from port throttle %d and mem clocks %d",
              mss::c_str(iv_target),
              i_n_port,
              iv_m_clocks);

    //Determine the utilization for each DIMM that will maximize the port power
    FAPI_TRY( calc_split_util(l_calc_util_slot, l_calc_util_port, l_calc_databus_port_max),
              "Error splitting the utilization for target %s with slot utilizatio %d and port util %d",
              mss::c_str(iv_target),
              l_calc_util_slot,
              l_calc_util_port);

    FAPI_TRY( calc_port_power(l_calc_databus_port_idle,
                              l_calc_databus_port_max,
                              l_port_power_idle,
                              l_port_power_max),
              "Error calculating the port power value for %s. Slot value is %d, port value is %d",
              mss::c_str(iv_target),
              i_n_slot,
              i_n_port);

    o_power = power_thermal::round_up (l_port_power_max);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Converts the port maximum databus to a dimm level based on powerslopes and dimms installed
/// @param[in] i_databus_port_max max databus utilization for the port (either calculated or mrw)
/// @param[out] o_databus_dimm_max array of dimm utilization values
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff the split is OK
/// @note Called in p9_mss_bulk_pwr_throttles
/// @used to calculate the port power based off of DIMM power curves
///
fapi2::ReturnCode throttle::calc_databus (const double i_databus_port_max,
        double o_databus_dimm_max [MAX_DIMM_PER_PORT])
{
    uint8_t l_count_dimms = count_dimm(iv_target);

    //No work for no dimms
    if (l_count_dimms == 0)
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    for (const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(iv_target))
    {
        //Left early if count_dimms == 0
        o_databus_dimm_max[mss::index(l_dimm)] = i_databus_port_max / l_count_dimms;
    }

    //If the power slopes aren't equal, set the dimm with the highest power slope
    //Should be correct even if only one DIMM is installed
    if (iv_pwr_slope[0] != iv_pwr_slope[1])
    {
        o_databus_dimm_max[0] = (iv_pwr_slope[0] > iv_pwr_slope[1]) ? i_databus_port_max : 0;
        o_databus_dimm_max[1] = (iv_pwr_slope[1] > iv_pwr_slope[0]) ? i_databus_port_max : 0;
    }

    //Make sure both are not 0
    FAPI_ASSERT ( (o_databus_dimm_max[0] != 0) || (o_databus_dimm_max[1] != 0),
                  fapi2::MSS_NO_DATABUS_UTILIZATION()
                  .set_PORT_DATABUS_UTIL(i_databus_port_max)
                  .set_DIMM_COUNT(l_count_dimms),
                  "Failed to calculated databus utilization for target %s",
                  mss::c_str(iv_target));

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Converts the port and slot util to a dimm level based on powerslopes and number of dimms installed
/// @param[in] i_util_slot databus utilization for the slot
/// @param[in] i_util_port databus utilization for the port
/// @param[out] o_util_dimm_max array of dimm utilization values
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff the split is OK
/// @note determines worst case utilization per dimms, takes into account port and combine slot throttles
/// @note used in calculating the port power, not for calculating the slot and port utilization
///
fapi2::ReturnCode throttle::calc_split_util(
    const double i_util_slot,
    const double i_util_port,
    double o_util_dimm_max [MAX_DIMM_PER_PORT]) const
{
    uint8_t l_count_dimms = count_dimm (iv_target);
    //The total utilization to be used is limited by either what the port can allow or what the dimms can use
    FAPI_ASSERT( (i_util_slot <= i_util_port),
                 fapi2::MSS_SLOT_UTIL_EXCEEDS_PORT()
                 .set_SLOT_UTIL(i_util_slot)
                 .set_PORT_UTIL(i_util_port),
                 "The slot utilization (%f) exceeds the port's utilization (%f)",
                 i_util_slot,
                 i_util_port);

    if (l_count_dimms == 0)
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    //assumptions slot <= port, l_count_dimms <=2
    else if (i_util_slot * l_count_dimms > i_util_port)
    {
        FAPI_INF("In mss::power_thermal::calc_split i_util_slot is %f, i_util_port is %f, l_count_dimms is %d",
                 i_util_slot,
                 i_util_port,
                 l_count_dimms);
        const uint8_t l_high_pos = (iv_pwr_slope[0] >= iv_pwr_slope[1]) ? 0 : 1;

        //Highest power_slope gets the higher utilization
        o_util_dimm_max[l_high_pos] = std::min(i_util_slot, i_util_port);
        //Set the other dimm to the left over utilization (i_util_port - i_util_slot)
        o_util_dimm_max[(!l_high_pos)] = (l_count_dimms == 2) ? (i_util_port - o_util_dimm_max[l_high_pos]) : 0;

        FAPI_INF("Split utilization for target %s, DIMM in %d gets %f, DIMM in %d gets %f",
                 mss::c_str(iv_target),
                 l_high_pos,
                 o_util_dimm_max[l_high_pos],
                 !l_high_pos,
                 o_util_dimm_max[!l_high_pos]);
    }

    else
    {
        //If only 1 dimm, i_util_port == i_util_slot
        //If 2 dimms, 2*i_util_slot <= i_util_pot
        //Either way, limit utilization by the slot value
        for (const auto& l_dimm : mss::find_targets<TARGET_TYPE_DIMM>(iv_target))
        {
            const size_t l_pos = mss::index(l_dimm);
            o_util_dimm_max[l_pos] = i_util_slot;
        }
    }

    //make sure both are not 0
    FAPI_ASSERT ( (o_util_dimm_max[0] != 0) || (o_util_dimm_max[1] != 0),
                  fapi2::MSS_NO_DATABUS_UTILIZATION()
                  .set_PORT_DATABUS_UTIL(i_util_port)
                  .set_DIMM_COUNT(mss::count_dimm(iv_target)),
                  "Failed to calculated util utilization for target %s",
                  mss::c_str(iv_target));
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform thermal calculations as part of the effective configuration
/// @param[in] i_target the MCS target in which the runtime throttles will be reset
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode restore_runtime_throttles( const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target )
{
    uint16_t l_run_throttles [MAX_DIMM_PER_PORT] = {};
    uint32_t l_max_databus = 0;
    uint32_t l_throttle_m_clocks = {};

    FAPI_TRY( mrw_mem_m_dram_clocks(l_throttle_m_clocks) );
    FAPI_TRY( mrw_max_dram_databus_util(l_max_databus) );

    //Set runtime throttles to unthrottled value, using max dram utilization and M throttle
    //Do I need to check to see if any DIMMS configured  on the port?
    for (const auto& l_mca : mss::find_targets<TARGET_TYPE_MCA>(i_target))
    {
        const auto l_pos = mss::index(l_mca);

        if (mss::count_dimm (l_mca) != 0)
        {
            l_run_throttles[l_pos] = mss::power_thermal::throttled_cmds (l_max_databus, l_throttle_m_clocks);
        }
    }

    FAPI_TRY( FAPI_ATTR_SET( fapi2::ATTR_MSS_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_PORT, i_target, l_run_throttles) );
    FAPI_TRY( FAPI_ATTR_SET( fapi2::ATTR_MSS_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_SLOT, i_target, l_run_throttles) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Update the runtime throttles to the worst case of the general throttle values and the runtime values
/// @param[in] i_target the MCS target in which the runtime throttles will be set
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode update_runtime_throttles( const std::vector< fapi2::Target<fapi2::TARGET_TYPE_MCS> >& i_targets )
{
    for (const auto& l_mcs : i_targets)
    {
        if (mss::count_dimm(l_mcs) == 0)
        {
            continue;
        }

        uint16_t l_run_slot [PORTS_PER_MCS] = {};
        uint16_t l_run_port [PORTS_PER_MCS] = {};
        uint16_t l_calc_slot [PORTS_PER_MCS] = {};
        uint16_t l_calc_port [PORTS_PER_MCS] = {};

        FAPI_TRY(runtime_mem_throttled_n_commands_per_slot(l_mcs, l_run_slot));
        FAPI_TRY(runtime_mem_throttled_n_commands_per_port(l_mcs, l_run_port));
        FAPI_TRY(mem_throttled_n_commands_per_slot(l_mcs, l_calc_slot));
        FAPI_TRY(mem_throttled_n_commands_per_port(l_mcs, l_calc_port));

        for (const auto& l_mca : mss::find_targets<TARGET_TYPE_MCA>(l_mcs))
        {
            const auto l_pos = mss::index(l_mca);
            //Choose the worst case between runtime and calculated throttles
            //Have to make sure the calc_slot isn't equal to 0 though
            l_run_slot[l_pos] = (l_calc_slot[l_pos] != 0) ?
                                std::min(l_run_slot[l_pos], l_calc_slot[l_pos]) : l_run_slot[l_pos];
            l_run_port[l_pos] = (l_calc_port[l_pos] != 0) ?
                                std::min(l_run_port[l_pos], l_calc_port[l_pos]) : l_run_port[l_pos];

            FAPI_INF("New runtime throttles for %s for slot are %d, port are  %d",
                     mss::c_str(l_mca),
                     l_run_slot[l_pos],
                     l_run_port[l_pos]);
        }

        FAPI_TRY( FAPI_ATTR_SET( fapi2::ATTR_MSS_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_PORT, l_mcs, l_run_port) );
        FAPI_TRY( FAPI_ATTR_SET( fapi2::ATTR_MSS_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_SLOT, l_mcs, l_run_slot) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief set ATTR_MSS_RUNTIME_MEM_M_DRAM_CLOCKS and ATTR_MSS_MEM_WATT_TARGET
/// @param[in] i_targets vector of mcs targets all on the same vddr domain
/// @return FAPI2_RC_SUCCESS iff it was a success
///
fapi2::ReturnCode set_runtime_m_and_watt_limit( const std::vector< fapi2::Target<fapi2::TARGET_TYPE_MCS> >& i_targets )
{
    uint32_t l_m_clocks = 0;
    uint32_t l_vmem_power_limit_dimm = 0;
    uint8_t l_max_dimms = 0;

    uint32_t l_count_dimms_vec = 0;
    uint32_t l_watt_target = 0;

    for (const auto& l_mcs : i_targets)
    {
        l_count_dimms_vec += mss::count_dimm(l_mcs);
    }

    if ( l_count_dimms_vec == 0)
    {
        FAPI_INF("No DIMMs found. Can't calculate WATT_TARGET");
        return fapi2::FAPI2_RC_SUCCESS;
    }

    FAPI_TRY( mrw_vmem_regulator_power_limit_per_dimm_ddr4(l_vmem_power_limit_dimm));
    FAPI_TRY( mrw_mem_m_dram_clocks(l_m_clocks));
    FAPI_TRY( mrw_max_number_dimms_possible_per_vmem_regulator(l_max_dimms));

    //Now calculate the watt target
    //Calculate max power available / number of dimms configured on the VDDR rail
    l_watt_target = (l_vmem_power_limit_dimm * l_max_dimms) / l_count_dimms_vec;

    // If we have too many dimms, deconfigure the first MCS
    // We know there are MCSs on the vector due to the check above
    FAPI_ASSERT( (l_count_dimms_vec <= l_max_dimms),
                 fapi2::MSS_DIMM_COUNT_EXCEEDS_VMEM_REGULATOR_LIMIT()
                 .set_MAX_DIMM_AMOUNT(l_max_dimms)
                 .set_DIMMS_SEEN(l_count_dimms_vec),
                 "The number of dimms counted (%d) on the vector of MCS surpasses the limit (%d)",
                 l_count_dimms_vec,
                 l_max_dimms);

    FAPI_INF("Calculated ATTR_MSS_MEM_WATT_TARGET is %d, power_limit dimm is %d, max_dimms is %d, count dimms on vector is %d",
             l_watt_target,
             l_vmem_power_limit_dimm,
             l_max_dimms,
             l_count_dimms_vec);

    for (const auto& l_mcs : i_targets)
    {
        uint32_t l_watt_temp [PORTS_PER_MCS][MAX_DIMM_PER_PORT] = {{l_watt_target, l_watt_target}, {l_watt_target, l_watt_target}};
        uint32_t l_runtime_m [PORTS_PER_MCS] = {l_m_clocks, l_m_clocks};

        FAPI_TRY( FAPI_ATTR_SET( fapi2::ATTR_MSS_RUNTIME_MEM_M_DRAM_CLOCKS, l_mcs, l_runtime_m));
        FAPI_TRY( FAPI_ATTR_SET( fapi2::ATTR_MSS_MEM_WATT_TARGET, l_mcs, l_watt_temp));
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    FAPI_ERR("Error setting power_thermal attributes MSS_WATT_TARGET");
    return fapi2::current_err;
}

///
/// @brief Equalize the throttles and estimated power at those throttle levels
/// @param[in] i_targets vector of MCS targets all on the same VDDR domain
/// @param[in] i_throttle_type denotes if this was done for POWER (VMEM) or THERMAL (VMEM+VPP) throttles
/// @return FAPI2_RC_SUCCESS iff ok
/// @note sets the throttles and power to the worst case
/// Called by p9_mss_bulk_pwr_throttles and by p9_mss_utils_to_throttle (so by IPL or by OCC)
///
fapi2::ReturnCode equalize_throttles (const std::vector< fapi2::Target<fapi2::TARGET_TYPE_MCS> >& i_targets,
                                      const throttle_type i_throttle_type)
{
    //Set to max values so every compare will change to min value
    uint16_t l_min_slot = ~(0);
    uint16_t l_min_port = ~(0);

    //Loop through all of the MCS targets to find the worst case throttle value (lowest) for the slot and port
    for (const auto& l_mcs : i_targets)
    {
        uint16_t l_calc_slot [mss::PORTS_PER_MCS] = {};
        uint16_t l_calc_port [mss::PORTS_PER_MCS] = {};
        uint16_t l_run_slot [mss::PORTS_PER_MCS] = {};
        uint16_t l_run_port [mss::PORTS_PER_MCS] = {};

        FAPI_TRY(mem_throttled_n_commands_per_slot(l_mcs, l_calc_slot));
        FAPI_TRY(mem_throttled_n_commands_per_port(l_mcs, l_calc_port));
        FAPI_TRY(runtime_mem_throttled_n_commands_per_slot(l_mcs, l_run_slot));
        FAPI_TRY(runtime_mem_throttled_n_commands_per_port(l_mcs, l_run_port));

        for (const auto& l_mca : mss::find_targets<TARGET_TYPE_MCA>(l_mcs))
        {
            if (mss::count_dimm(l_mca) == 0)
            {
                continue;
            }

            const auto l_pos = mss::index(l_mca);
            //Find the smaller of the three values (calculated slot, runtime slot, and min slot)
            l_min_slot = (l_calc_slot[l_pos] != 0) ? std::min( std::min (l_calc_slot[l_pos], l_run_slot[l_pos]),
                         l_min_slot) : l_min_slot;
            l_min_port = (l_calc_port[l_pos] != 0) ? std::min( std::min( l_calc_port[l_pos], l_run_port[l_pos]),
                         l_min_port) : l_min_port;
        }
    }

    FAPI_INF("Calculated min slot is %d, min port is %d for the system", l_min_slot, l_min_port);

    //Now set every port to have those values
    {
        for (const auto& l_mcs : i_targets)
        {
            uint16_t l_fin_slot [mss::PORTS_PER_MCS] = {};
            uint16_t l_fin_port [mss::PORTS_PER_MCS] = {};
            uint32_t l_fin_power [mss::PORTS_PER_MCS] = {};

            for (const auto& l_mca : mss::find_targets<TARGET_TYPE_MCA>(l_mcs))
            {
                if (mss::count_dimm(l_mca) == 0)
                {
                    continue;
                }

                const auto l_pos = mss::index(l_mca);
                // Declaring above to avoid fapi2 jump
                uint64_t l_power_limit = 0;

                l_fin_slot[l_pos] = (mss::count_dimm(l_mca)) ? l_min_slot : 0;
                l_fin_port[l_pos] = (mss::count_dimm(l_mca)) ? l_min_port : 0;

                //Need to create throttle object for each mca in order to get dimm configuration and power curves
                //To calculate the slot/port utilization and total port power consumption
                fapi2::ReturnCode l_rc;

                const auto l_dummy = mss::power_thermal::throttle(l_mca, l_rc);
                FAPI_TRY(l_rc, "Failed creating a throttle object in equalize_throttles");

                FAPI_TRY( l_dummy.calc_power_from_n(l_fin_slot[l_pos], l_fin_port[l_pos], l_fin_power[l_pos]),
                          "Failed calculating the power value for throttles: slot %d, port %d for target %s",
                          l_fin_slot[l_pos],
                          l_fin_port[l_pos],
                          mss::c_str(l_mca));

                //Only calculate the power for ports that have dimms
                l_fin_power[l_pos] = (mss::count_dimm(l_mca) != 0 ) ? l_fin_power[l_pos] : 0;

                // You may ask why this is not a variable within the throttle struct
                // It's because POWER throttling is on a per port basis while the THERMAL throttle is per dimm
                // Didn't feel like adding a variable just for this check
                l_power_limit = (i_throttle_type == throttle_type::POWER) ?
                                l_dummy.iv_port_power_limit : (l_dummy.iv_dimm_thermal_limit[0] + l_dummy.iv_dimm_thermal_limit[1]);

                FAPI_INF("Calculated power is %d, limit is %d", l_fin_power[l_pos], l_power_limit);

                //If there's an error with calculating port power, the wrong watt target was passed in
                //Returns an error but doesn't deconfigure anything. Calling function can log if it wants to
                //Called by OCC and by p9_mss_eff_config_thermal, thus different ways for error handling
                //Continue setting throttles to prevent a possible throttle == 0
                //The error will be the last bad port found
                if (l_fin_power[l_pos] > l_power_limit)
                {
                    //Need this because of pos traits and templating stuff
                    uint64_t l_fail = mss::fapi_pos(l_mca);
                    //Set the failing port. OCC just needs one failing port, doesn't need all of them
                    FAPI_TRY( FAPI_ATTR_SET( fapi2::ATTR_MSS_MEM_PORT_POS_OF_FAIL_THROTTLE,
                                             fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                                             l_fail) );

                    FAPI_ASSERT_NOEXIT( false,
                                        fapi2::MSS_CALC_PORT_POWER_EXCEEDS_MAX()
                                        .set_CALCULATED_PORT_POWER(l_fin_power[l_pos])
                                        .set_MAX_POWER_ALLOWED(l_power_limit)
                                        .set_PORT_POS(mss::pos(l_mca))
                                        .set_MCA_TARGET(l_mca),
                                        "Error calculating the final port power value for target %s, calculated power is %d, max value can be %d",
                                        mss::c_str(l_mca),
                                        l_fin_power[l_pos],
                                        l_power_limit);
                }
            }

            FAPI_INF("%s Final throttles values for slot %d, for port %d, power value %d",
                     mss::c_str(l_mcs),
                     l_fin_port,
                     l_fin_slot,
                     l_fin_port);
            //Even if there's an error, still calculate and set the throttles.
            //OCC will set to safemode if there's an error
            //Better to set the throttles than leave them 0, and potentially brick the memory
            FAPI_TRY( FAPI_ATTR_SET( fapi2::ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_PORT, l_mcs, l_fin_port) );
            FAPI_TRY( FAPI_ATTR_SET( fapi2::ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_SLOT, l_mcs, l_fin_slot) );
            FAPI_TRY( FAPI_ATTR_SET( fapi2::ATTR_MSS_PORT_MAXPOWER, l_mcs, l_fin_power) );
        }
    }
    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    FAPI_ERR("Error equalizing memory throttles");
    return fapi2::current_err;
}
}//namespace power_thermal
}//namespace mss
