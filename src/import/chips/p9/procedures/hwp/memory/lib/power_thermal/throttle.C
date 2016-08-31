/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/power_thermal/throttle.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
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
throttle::throttle( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_mca, fapi2::ReturnCode o_rc) :
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
    FAPI_TRY( mrw_max_dram_databus_util(iv_databus_port_max) );

    FAPI_TRY( mrw_dimm_power_curve_percent_uplift(iv_power_uplift) );
    FAPI_TRY( mrw_dimm_power_curve_percent_uplift_idle(iv_power_uplift_idle) );
    FAPI_TRY( dimm_thermal_limit( iv_target, iv_dimm_thermal_limit) );
    FAPI_TRY( total_pwr_intercept( iv_target, iv_pwr_int));
    FAPI_TRY( total_pwr_slope( iv_target, iv_pwr_slope));
    FAPI_TRY( runtime_mem_throttled_n_commands_per_slot(iv_target, iv_runtime_n_slot ) );
    FAPI_TRY( runtime_mem_throttled_n_commands_per_port(iv_target, iv_runtime_n_port ) );
    FAPI_TRY( mem_watt_target( iv_target, l_dimm_power_limits) );
    FAPI_TRY( mrw_mem_m_dram_clocks(iv_m_clocks) );

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

    FAPI_INF("The dimm power limit is %d, port power limit is %d, dram clocks are %d, dimm power curve slopes are %d %d,",
             l_dimm_power_limits[0],
             iv_port_power_limit,
             iv_m_clocks,
             iv_pwr_slope[0],
             iv_pwr_slope[1]);

    FAPI_INF("DIMM power curve intercepts are %d %d, DIMM power thermal limits are %d %d",
             iv_pwr_int[0],
             iv_pwr_int[1],
             iv_dimm_thermal_limit[0],
             iv_dimm_thermal_limit[1]);

    o_rc = fapi2::FAPI2_RC_SUCCESS;
    FAPI_ASSERT ( (iv_databus_port_max != 0),
                  fapi2::MSS_NO_DATABUS_UTILIZATION()
                  .set_PORT_DATABUS_UTIL(iv_databus_port_max)
                  .set_MCA_TARGET(iv_target),
                  "Failed to get max databus utilization for target %s",
                  mss::c_str(iv_target));
    return;
fapi_try_exit:
    o_rc = fapi2::current_err;
    FAPI_ERR("Error getting attributes for mss::power_thermal::throttle ctor");
    return;
}

///
/// @brief Set ATTR_MSS_CHANNEL_PAIR_MAXPOWER,  ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_SLOT and _PER_PORT
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
    FAPI_TRY( calc_databus(iv_databus_port_max, l_databus_dimm_max));

    //Use the dimm utilizations and dimm power slopes to calculate port min and max power
    calc_port_power(l_calc_databus_port_idle,
                    l_databus_dimm_max,
                    l_port_power_calc_idle,
                    l_port_power_calc_max);
    FAPI_INF("POWER calculated port power is %f", l_port_power_calc_max);

    //Calculate the power curve slope and intercept using the port's min and max power values
    FAPI_TRY(calc_power_curve(l_port_power_calc_idle,
                              l_port_power_calc_max,
                              l_port_power_slope,
                              l_port_power_int));

    FAPI_INF("POWER Port power limit is %d", iv_port_power_limit);
    //Calculate the port's utilization to get under watt target using the port's calculated slopes
    calc_util_usage(l_port_power_slope,
                    l_port_power_int,
                    iv_port_power_limit,
                    l_calc_util_port);

    FAPI_INF("POWER calc util port is %f", l_calc_util_port);

    //Calculate the N throttles
    iv_n_port = power_thermal::throttled_cmds(l_calc_util_port, iv_m_clocks);

    //Set iv_n_slot to the lower value between the slot runtime and iv_n_port
    iv_n_slot = (iv_runtime_n_slot != 0) ? std::min (iv_n_port, iv_runtime_n_slot) : iv_n_port;

    //Choose the lowest value of the runtime and the calculated
    iv_n_port = (iv_runtime_n_port != 0) ? std::min (iv_n_port, iv_runtime_n_port) : iv_n_port;

    //Use the throttle value to calculate the power that gets to exactly that value
    iv_calc_port_maxpower = calc_power_from_n(iv_n_port);

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
    uint16_t l_n_slots [MAX_DIMM_PER_PORT] = {};
    const auto l_count = count_dimm (iv_target);

    //Calculate the dimm power range for each dimm at max utilization for each
    calc_dimm_power(power_thermal::IDLE_UTIL,
                    iv_databus_port_max,
                    l_dimm_power_idle,
                    l_dimm_power_max);

    //Let's calculate the N throttle for each DIMM
    for ( const auto& l_dimm : find_targets<TARGET_TYPE_DIMM>(iv_target) )
    {
        uint8_t l_pos = mss::index(l_dimm);
        //Calculate the power curve taking the thermal limit into account
        FAPI_TRY( calc_power_curve(l_dimm_power_idle[l_pos],
                                   l_dimm_power_max[l_pos],
                                   l_dimm_power_slope[l_pos],
                                   l_dimm_power_int[l_pos]));

        //Calculate the databus utilization at the calculated power curve
        calc_util_usage(l_dimm_power_slope[l_pos],
                        l_dimm_power_int[l_pos],
                        iv_dimm_thermal_limit[l_pos],
                        l_calc_util[l_pos]);

        FAPI_INF("THERMAL Dimm at pos %d's util is %f", l_pos, l_calc_util[l_pos]);

        l_n_slots[l_pos] = power_thermal::throttled_cmds (l_calc_util[l_pos], iv_m_clocks);

        //Set to the min between the two value
        //If iv_n_slot == 0 (so uninitialized), set it to the calculated slot value
        //The l_n_slot value can't be equal to 0 because there's a dimm installed
        if ((l_n_slots[l_pos] < iv_n_slot) || (iv_n_slot == 0))
        {
            iv_n_slot = l_n_slots[l_pos];
        }
    }

    //Set to lowest value between calculated and runtime
    FAPI_INF("THERMAL runtime slot is %d, calc n slot is %d", iv_runtime_n_slot, iv_n_slot);
    //Taking the min of the SLOT * (# of dimms on the port) and that maximum allowed port throttle (iv_runtime_port)
    //So it's the min of either to actually utilized to the maximum allowed utilization
    iv_n_port = std::min(iv_runtime_n_port, uint16_t(iv_n_slot * l_count));

    iv_n_slot = std::min(iv_n_slot, iv_runtime_n_slot);

    //Now time to get and set iv_calc_port_max  from the calculated N throttle
    iv_calc_port_maxpower = calc_power_from_n(iv_n_port);

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    FAPI_ERR("Error calculating mss::power_thermal::thermal_throttles()");
    return fapi2::current_err;
}



///
/// @brief Calculates the min and max power usage for a port based off of power curves and utilizations
/// @param[in] i_idle_util the utilization of the databus in idle mode
/// @param[in] i_max_util  the utilization of the port at maximum possible (mrw or calculated)
/// @param[out] o_port_power_idle max value of port power in cW
/// @param[out] o_port_power_max max value of port power in cW
/// @note Called twice in p9_mss_bulk_pwr_throttles
/// @note uses dimm power curves from class variables
///
void throttle::calc_port_power(const double i_idle_util [MAX_DIMM_PER_PORT],
                               const double i_max_util [MAX_DIMM_PER_PORT],
                               double& o_port_power_idle,
                               double& o_port_power_max)
{
    //Playing it safe
    o_port_power_idle = 0;
    o_port_power_max = 0;
    FAPI_INF("max util is %f, %f", i_max_util[0], i_max_util[1]);

    //Calculate the port power curve info by summing the dimms on the port
    for ( const auto& l_dimm : mss::find_targets<TARGET_TYPE_DIMM>(iv_target) )
    {
        uint32_t l_pos = mss::index(l_dimm);
        //Sum up the dim's power to calculate the port power curve
        o_port_power_idle += calc_power(i_idle_util[l_pos], l_pos);
        o_port_power_max  += calc_power(i_max_util[l_pos], l_pos);
    }

    //Raise the powers by the uplift percent
    calc_power_uplift(iv_power_uplift_idle, o_port_power_idle);
    calc_power_uplift(iv_power_uplift, o_port_power_max);
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
                               double o_dimm_power_max [MAX_DIMM_PER_PORT])
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
        uint32_t& o_int)
{
    double l_divisor = ((double(iv_databus_port_max) / UTIL_CONVERSION) - IDLE_UTIL);
    FAPI_ASSERT ((l_divisor != 0),
                 fapi2::MSS_CALC_POWER_CURVE_DIVIDE_BY_ZERO()
                 .set_PORT_DATABUS_UTIL(iv_databus_port_max)
                 .set_UTIL_CONVERSION(UTIL_CONVERSION)
                 .set_IDLE_UTIL(IDLE_UTIL),
                 "Calculated zero for the divisor in calc_power_curve on target %s, the equation is %s",
                 mss::c_str(iv_target),
                 "(double(iv_databus_port_max) / UTIL_CONVERSION) - IDLE_UTIL");

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
                               double& o_util)
{
    o_util = (double(i_power_limit) - i_int) / i_slope * UTIL_CONVERSION;
    o_util = (uint32_t(o_util) < iv_databus_port_max) ? o_util : iv_databus_port_max;
    o_util = (o_util == 0) ? MIN_UTIL : o_util;
}

///
///@brief calculated the output power estimate from the calculated N throttle
///@param[in] i_n_throttle is the throtte N (address operations) that the power (cW) should be calculated fro
///@return the power calculated from the uint
///
uint32_t throttle::calc_power_from_n (const uint16_t i_n_throttle)
{
    double l_calc_util;
    double l_calc_databus_port_max[MAX_DIMM_PER_PORT] = {};
    double l_calc_databus_port_idle[MAX_DIMM_PER_PORT] = {};
    double l_port_power_max = 0;
    double l_port_power_idle = 0;

    l_calc_util = calc_util_from_throttles(i_n_throttle, iv_m_clocks);

    //Now do everything as port stuff
    calc_databus(l_calc_util, l_calc_databus_port_max);

    calc_port_power(l_calc_databus_port_idle,
                    l_calc_databus_port_max,
                    l_port_power_idle,
                    l_port_power_max);

    return uint32_t(power_thermal::round_up (l_port_power_max));
}

///
/// @brief Converts the port maximum databus to a dimm level based on powerslopes and dimms installed
/// @param[in] i_databus_port_max max databus utilization for the port (either calculated or mrw)
/// @param[out] o_databus_dimm_max array of dimm utilization values
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff the split is OK
/// @note Called in p9_mss_bulk_pwr_throttles
/// @used to calculate the port power based off of DIMM power curves
///
fapi2::ReturnCode throttle::calc_databus( const double i_databus_port_max,
        double o_databus_dimm_max [MAX_DIMM_PER_PORT])
{
    uint8_t l_count_dimms = count_dimm (iv_target);

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

    //make sure both are not 0
    FAPI_ASSERT ( (o_databus_dimm_max[0] != 0) || (o_databus_dimm_max[1] != 0),
                  fapi2::MSS_NO_DATABUS_UTILIZATION()
                  .set_PORT_DATABUS_UTIL(i_databus_port_max)
                  .set_MCA_TARGET(iv_target),
                  "Failed to calculated databus utilization for target %s",
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

    //set runtime throttles to unthrottled value, using max dram utilization and M throttle
    //Do I need to check to see if any DIMMS configured  on the port?
    for (const auto& l_mca : find_targets<TARGET_TYPE_MCA>(i_target))
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
        uint16_t l_run_slot [PORTS_PER_MCS] = {};
        uint16_t l_run_port [PORTS_PER_MCS] = {};
        uint16_t l_calc_slot [PORTS_PER_MCS] = {};
        uint16_t l_calc_port [PORTS_PER_MCS] = {};

        FAPI_TRY(runtime_mem_throttled_n_commands_per_slot(l_mcs, l_run_slot));
        FAPI_TRY(runtime_mem_throttled_n_commands_per_port(l_mcs, l_run_port));
        FAPI_TRY(mem_throttled_n_commands_per_slot(l_mcs, l_calc_slot));
        FAPI_TRY(mem_throttled_n_commands_per_port(l_mcs, l_calc_port));

        for (const auto& l_mca : find_targets<TARGET_TYPE_MCA>(l_mcs))
        {
            const auto l_pos = mss::index(l_mca);
            //Choose the worst case between runtime and calculated throttles
            //Have to make sure the calc_slot isn't equal to 0 though
            l_run_slot[l_pos] = (l_calc_slot[l_pos] != 0) ? std::min(l_run_slot[l_pos], l_calc_slot[l_pos]) : l_run_slot[l_pos];
            l_run_port[l_pos] = (l_calc_port[l_pos] != 0) ? std::min(l_run_port[l_pos], l_calc_port[l_pos]) : l_run_port[l_pos];
            FAPI_INF("New runtime throttles dimm %d for slot are %d, port are  %d", l_pos, l_run_slot[l_pos], l_run_port[l_pos]);
        }

        FAPI_TRY( FAPI_ATTR_SET( fapi2::ATTR_MSS_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_PORT, l_mcs, l_run_port) );
        FAPI_TRY( FAPI_ATTR_SET( fapi2::ATTR_MSS_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_SLOT, l_mcs, l_run_slot) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

}//namespace power_thermal
}//namespace mss
