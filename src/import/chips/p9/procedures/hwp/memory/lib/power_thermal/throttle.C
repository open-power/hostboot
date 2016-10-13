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
/// @file eff_config.C
/// @brief Determine effective config for mss settings
///
// *HWP HWP Owner: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

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
    iv_port_maxpower(0),
    iv_calc_port_maxpower(0)
{
    uint32_t l_dimm_power_limits [MAX_DIMM_PER_PORT] = {};

    FAPI_TRY( mem_throttled_n_commands_per_slot( iv_target, iv_n_slot) );
    FAPI_TRY( mem_throttled_n_commands_per_port( iv_target, iv_n_port) );
    FAPI_TRY( port_maxpower ( iv_target, iv_port_maxpower) );
    FAPI_TRY( mrw_max_dram_databus_util(iv_databus_port_max) );

    FAPI_TRY( mrw_dimm_power_curve_percent_uplift( iv_power_uplift) );
    FAPI_TRY( mrw_dimm_power_curve_percent_uplift_idle( iv_power_uplift_idle) );
    //FAPI_TRY( mrw_thermal_memory_power_limit( iv_dimm_thermal_limit) );

    FAPI_TRY( runtime_mem_throttled_n_commands_per_slot(iv_target, iv_runtime_n_slot ) );
    FAPI_TRY( runtime_mem_throttled_n_commands_per_port(iv_target, iv_runtime_n_port ) );
    FAPI_TRY( mem_watt_target( iv_target, &(l_dimm_power_limits[0])) );
    FAPI_TRY( mrw_mem_m_dram_clocks(iv_m_clocks) );

    //Port power limit = sum of dimm power limits
    for ( const auto& l_dimm : mss::find_targets<TARGET_TYPE_DIMM>(iv_target) )
    {
        iv_port_power_limit += l_dimm_power_limits[mss::index(l_dimm)];
    }

    FAPI_ASSERT ( (iv_databus_port_max != 0),
                  fapi2::MSS_NO_DATABUS_UTILIZATION()
                  .set_PORT_DATABUS_UTIL(iv_databus_port_max)
                  .set_MCA_TARGET(iv_target),
                  "Failed to get max databus utilization for target %s",
                  mss::c_str(iv_target));
    o_rc = fapi2::FAPI2_RC_SUCCESS;
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

    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Calculates the min and max power usage for a port based off of power curves and utilizati
/// @param[in] i_idle_util the utilization of the databus in idle mode
/// @param[in] i_max_util  the utilization of the port at maximum possible (mrw or calculated)
/// @param[out] o_port_power_idle max value of port power in cW
/// @param[out] o_port_power_max max value of port power in cW
/// @note Called twice in p9_mss_bulk_pwr_throttles
/// @note uses dimm power curves from class variables
///
void throttle::calc_port_power( const double i_idle_util [MAX_DIMM_PER_PORT],
                                const double i_max_util [MAX_DIMM_PER_PORT],
                                double& o_port_power_idle,
                                double& o_port_power_max)
{
    //Playing it safe
    o_port_power_idle = 0;
    o_port_power_max = 0;

    //Calculate the port power curve info by summing the dimms on the port
    for ( const auto& l_dimm : mss::find_targets<TARGET_TYPE_DIMM>(iv_target) )
    {
        uint32_t l_pos = mss::index(l_dimm);
        //Sum up the dim's power to calculate the port power curve
        o_port_power_idle +=
            ( i_idle_util[l_pos] / UTIL_CONVERSION * iv_pwr_slope[l_pos]) + iv_pwr_int[l_pos];

        o_port_power_max  +=
            ( i_max_util[l_pos] / UTIL_CONVERSION * iv_pwr_slope[l_pos]) + iv_pwr_int[l_pos];
    }

    //Raise the powers by the uplift percent
    o_port_power_idle *= (1 + (double(iv_power_uplift_idle) / PERCENT_CONVERSION));
    o_port_power_max  *= (1 + (double(iv_power_uplift) / PERCENT_CONVERSION));
}

///
/// @brief Calculate the port power curve in order to calculate the port utilization
/// @paramp[in] i_port_power_calc_idle double of the port's power consumption at idle
/// @paramp[in] i_port_power_calc_max double of the port's power consumption at max utilization
/// @paramp[out] o_port_power_slope
/// @paramp[out] o_port_power_int
/// @note Called in p9_mss_bulk_pwr_throttles
/// @note Port power curve needed to calculate the port utilization
///
fapi2::ReturnCode throttle::calc_port_power_curve (const double& i_port_power_calc_idle,
        const double& i_port_power_calc_max,
        uint32_t& o_port_power_slope,
        uint32_t& o_port_power_int)
{
    double l_denominator = ((double(iv_databus_port_max) / UTIL_CONVERSION) - IDLE_UTIL);

    FAPI_ASSERT(l_denominator != 0,
                fapi2::MSS_CALC_PORT_POWER_CURVE_DIVIDE_BY_ZERO().
                set_PORT_DATABUS_UTIL(iv_databus_port_max).
                set_UTIL_CONVERSION(UTIL_CONVERSION).
                set_IDLE_UTIL(IDLE_UTIL),
                "Denominator = (databus(%d) / UTIL_CONVERSION (%d)) - IDLE_UTIL(%d)",
                iv_databus_port_max,
                UTIL_CONVERSION,
                IDLE_UTIL);

    o_port_power_slope = (i_port_power_calc_max - i_port_power_calc_idle) / l_denominator;
    o_port_power_int = i_port_power_calc_idle - (o_port_power_slope * IDLE_UTIL);

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Calculate the port's databus utilization given the port's power curve
/// @paramp[in] i_port_power_slope
/// @paramp[in] i_port_power_int
/// @paramp[out] o_port_util the port's databus utilization
/// @note Called in p9_mss_bulk_pwr_throttles
/// @note Chooses worst case between the maximum allowed databus utilization and the calculated value
/// @notes makes sure that the utilization isn't 0
///
void throttle::calc_port_util_usage (const uint32_t& i_port_power_slope,
                                     const uint32_t& i_port_power_int,
                                     double& o_port_util)
{
    o_port_util = (double(iv_port_power_limit) - i_port_power_int) / i_port_power_slope * UTIL_CONVERSION;
    o_port_util = (uint32_t(o_port_util) < iv_databus_port_max) ? o_port_util : iv_databus_port_max;
    o_port_util = (o_port_util == 0) ? 1 : o_port_util;
}

///
/// @brief Calculates the power max and idle for each dimm using power curves and databus utilization
/// @param[out] o_dimm_power_idle double type for precision, the DIMM power limit in idle state (0 utilization)
/// @param[out] o_dimm_power_max double type for precision, the DIMM power limit at max utilization
/// @note Called in p9_mss_bulk_pwr_throttle for thermal_throttles, eff_config_thermal
/// @note power values are as if dimm is alone on port, using port_databus_util_max
///
void throttle::calc_dimm_power( double o_dimm_power_idle [MAX_DIMM_PER_PORT],
                                double o_dimm_power_max [MAX_DIMM_PER_PORT])
{
    for ( const auto& l_dimm : mss::find_targets<TARGET_TYPE_DIMM>(iv_target) )
    {
        const auto l_pos = mss::index(l_dimm);

        o_dimm_power_idle[l_pos] = iv_pwr_int[l_pos];
        o_dimm_power_max[l_pos]  = (double(iv_databus_port_max) / UTIL_CONVERSION) * iv_pwr_slope[l_pos] +
                                   iv_pwr_int[l_pos];


        //Raise the powers by the uplift percent
        o_dimm_power_idle[l_pos] *= (1 + (iv_power_uplift_idle / PERCENT_CONVERSION));
        o_dimm_power_max[l_pos]  *= (1 + (iv_power_uplift / PERCENT_CONVERSION));
    }
}

///
/// @brief Converts the port maximum databus to a dimm level based on powerslopes and dimms installed
/// @param[in] i_databus_port_max max databus utilization for the port (either calculated or mrw)
/// @param[out] o_databus_dimm_max array of dimm utilization values
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff the split is OK
/// @note Called in p9_mss_bulk_pwr_throttles
/// @used to calculate the port power based off of DIMM power curves
///
fapi2::ReturnCode throttle::calc_databus( const double& i_databus_port_max,
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

    //If not equal power slopes, set the dimm with the highest power slope
    //Should be correct even if only one DIMM installed
    if (iv_pwr_slope[0] != iv_pwr_slope[1])
    {
        o_databus_dimm_max[0] = (iv_pwr_slope[0] > iv_pwr_slope[1]) ? i_databus_port_max : 0;
        o_databus_dimm_max[1] = (iv_pwr_slope[1] > iv_pwr_slope[0]) ? i_databus_port_max : 0;
    }

    //make sure both aren't equal to 0
    FAPI_ASSERT ( (o_databus_dimm_max[0] != 0) || (o_databus_dimm_max[1] != 0),
                  fapi2::MSS_NO_DATABUS_UTILIZATION()
                  .set_PORT_DATABUS_UTIL(iv_databus_port_max)
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
/// TK implement/ will be overun?
///
fapi2::ReturnCode restore_runtime_throttles( const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target )
{
    uint32_t l_run_throttles [PORTS_PER_MCS] = {};
    uint32_t l_max_databus = 0;
    uint32_t l_throttle_m_clocks [PORTS_PER_MCS] = {};

    FAPI_TRY( runtime_mem_m_dram_clocks(i_target, l_throttle_m_clocks) );
    FAPI_TRY( mrw_max_dram_databus_util(l_max_databus) );

    for (const auto& l_mca : find_targets<TARGET_TYPE_MCA> (i_target))
    {
        const uint8_t l_pos = mss::index(l_mca);
        l_run_throttles[l_pos] = mss::power_thermal::throttled_cmds(l_max_databus, l_throttle_m_clocks[0]);
    }

    FAPI_TRY( FAPI_ATTR_SET( fapi2::ATTR_MSS_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_PORT, i_target, l_run_throttles) );

fapi_try_exit:
    return fapi2::current_err;
}
}//namespace power_thermal

}//namespace mss
