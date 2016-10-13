/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/power_thermal/throttle.H $ */
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
/// @file p9_mss_utils_to_throttle.H
/// @brief throttle API
///

// *HWP HWP Owner: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _MSS_POWER_THROTTLE_
#define _MSS_POWER_THROTTLE_

#include <fapi2.H>
#include <mss.H>
namespace mss
{
namespace power_thermal
{
enum throttle_const : size_t
{
    // Dram data bus utilization is bus utilization / 4
    DRAM_BUS_UTILS = 4,
    UTIL_CONVERSION = 10000,
    PERCENT_CONVERSION = 100,
    MIN_UTIL = 1,
    IDLE_UTIL = 0,
};
///
/// @class throttle
/// @brief Determine power_thermal throttles for memory
///
class throttle
{
    private:

    public:
        const fapi2::Target<fapi2::TARGET_TYPE_MCA>& iv_target;
        //dimm level
        uint32_t iv_databus_port_max;

        uint8_t iv_power_uplift_idle;
        uint8_t iv_power_uplift;

        uint32_t iv_runtime_n_slot;
        uint32_t iv_runtime_n_port;
        uint32_t iv_m_clocks;
        uint32_t iv_dimm_thermal_limit[MAX_DIMM_PER_PORT] = {};
        uint16_t iv_pwr_slope[MAX_DIMM_PER_PORT] = {};
        uint16_t iv_pwr_int[MAX_DIMM_PER_PORT] = {};
        uint32_t iv_n_slot;
        uint32_t iv_n_port;
        uint32_t iv_port_power_limit;
        uint32_t iv_port_maxpower;
        uint32_t iv_calc_port_maxpower;

        //default ctor deleted
        throttle() = delete;

        ///
        /// @brief Constructor
        /// @param[in] i_target MCA target to call power thermal stuff on
        /// @param[out] o_rc fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ctor was successful
        ///
        throttle( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_mca, fapi2::ReturnCode o_rc);

        //
        // @brief Destructor
        //
        ~throttle() = default;

        ///
        /// @brief Calculates the min and max power usage for a port based off of power curves and utilizati
        /// @param[in] i_idle_util the utilization of the databus in idle mode
        /// @param[in] i_max_util  the utilization of the port at maximum possible (mrw or calculated)
        /// @param[out] o_port_power_idle max value of port power in cW
        /// @param[out] o_port_power_max max value of port power in cW
        /// @note Called twice in p9_mss_bulk_pwr_throttles
        /// @note uses dimm power curves from class variables
        ///
        void calc_port_power(const double i_idle_util [MAX_DIMM_PER_PORT],
                             const double i_max_util [MAX_DIMM_PER_PORT],
                             double& o_port_power_idle,
                             double& o_port_power_max);
        ///
        /// @brief Calculate the port power curve in order to calculate the port utilization
        /// @paramp[in] i_port_power_calc_idle double of the port's power consumption at idle
        /// @paramp[in] i_port_power_calc_max double of the port's power consumption at max utilization
        /// @paramp[out] o_port_power_slope
        /// @paramp[out] o_port_power_int
        /// @return FAPI2_RC_SUCCESS iff success
        /// @note Called in p9_mss_bulk_pwr_throttles
        /// @note Port power curve needed to calculate the port utilization
        ///
        fapi2::ReturnCode calc_port_power_curve(const double& i_port_power_calc_idle,
                                                const double& i_port_power_calc_max,
                                                uint32_t& o_port_power_slope,
                                                uint32_t& o_port_power_int);
        ///
        /// @brief Calculate the port's databus utilization given the port's power curve
        /// @paramp[in] i_port_power_slope
        /// @paramp[in] i_port_power_int
        /// @paramp[out] o_port_util the port's databus utilization
        /// @note Called in p9_mss_bulk_pwr_throttles
        /// @note Chooses worst case between the maximum allowed databus utilization and the calculated value
        /// @notes makes sure that the utilization isn't 0
        ///
        void calc_port_util_usage(const uint32_t& i_port_power_slope,
                                  const uint32_t& i_port_power_int,
                                  double& o_port_util);

        ///
        /// @brief Calculates the power max and idle for each dimm using power curves and databus utilization
        /// @param[out] o_dimm_power_idle double type for precision, the DIMM power limit in idle state (0 utilization)
        /// @param[out] o_dimm_power_max double type for precision, the DIMM power limit at max utilization
        /// @note Called in p9_mss_bulk_pwr_throttle for thermal_throttles, eff_config_thermal
        /// @note power values are as if dimm is alone on port, using port_databus_util_max
        ///
        void calc_dimm_power(double o_dimm_power_idle [MAX_DIMM_PER_PORT],
                             double o_dimm_power_max [MAX_DIMM_PER_PORT]);
        ///
        /// @brief Converts the port maximum databus to a dimm level based on powerslopes and dimms installed
        /// @param[in] i_databus_port_max max databus utilization for the port (either calculated or mrw)
        /// @param[out] o_databus_dimm_max array of dimm utilization values
        /// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff the split is OK
        /// @note Called in p9_mss_bulk_pwr_throttles
        /// @used to calculate the port power based off of DIMM power curves
        ///
        fapi2::ReturnCode calc_databus(const double& i_databus_port_max,
                                       double o_databus_dimm_max [MAX_DIMM_PER_PORT]);

        ///
        /// @brief Set ATTR_MSS_CHANNEL_PAIR_MAXPOWER and  ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_SLOT,
        /// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
        /// @note Called in p9_mss_bulk_pwr_throttles
        /// @note determines the throttle levels based off of the port's power curve,
        /// sets the slot throttles to the same
        ///
        fapi2::ReturnCode power_regulator_throttles ();

        ///
        /// @brief Set ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_SLOT,
        /// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
        /// @note Called in p9_mss_bulk_pwr_throttles
        /// @note Sets the throttle levels based off of the dimm's thermal limits
        /// @note both DIMM's on a port are set to the same throttle level
        ///
        fapi2::ReturnCode thermal_throttles ();
};

///
/// @brief Calculate N (address operations) allowed within a window of M DRAM clocks
/// @param[in] i_databus_util databus utilization percentage (e.g. 5% = 5)
/// @param[in] i_num_dram_clocks window of M DRAM clocks
/// @return number of throttled commands allowed
/// @note Uses N/M Throttling.
/// Equation:  (DRAM data bus utilization Percent / 10000 ) = ((N * M) / 4 )
/// Equation: N = (DRAM data bus utilization Percent * M) / (4 * 10000)
inline uint32_t throttled_cmds(const uint32_t i_databus_util, const uint32_t i_num_dram_clocks)
{
    constexpr uint64_t l_divisor = DRAM_BUS_UTILS * UTIL_CONVERSION;
    const uint64_t l_dividend = i_databus_util * i_num_dram_clocks;
    const uint64_t l_result = l_dividend / l_divisor;

    return l_result;
}

///
/// @brief Calculate the port databus utilization based off of N throttles and M dram clocks
/// @param[in] i_n_throttles N (address operations) allowed within a window of M DRAM clocks
/// @param[in] i_num_dram_clocks window of M DRAM clocks
/// @return number of throttled commands allowed
/// @note Uses N/M Throttling.
/// Equation: databus utilization = (N * 4 * 100000) / M
///
inline double calc_util_from_throttles(const uint16_t i_n_throttles, const uint32_t i_num_dram_clocks)
{
    constexpr uint32_t l_multiplier = DRAM_BUS_UTILS * UTIL_CONVERSION;
    return  ( (double(i_n_throttles) * l_multiplier) / i_num_dram_clocks);

}

///
/// @brief Perform thermal calculations as part of the effective configuration
/// @param[in] i_target the MCS target in which the runtime throttles will be reset
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode restore_runtime_throttles( const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target );


}//power_thermal
}// mss

#endif
