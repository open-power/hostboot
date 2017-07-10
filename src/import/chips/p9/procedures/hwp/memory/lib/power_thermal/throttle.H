/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/power_thermal/throttle.H $ */
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
/// @file p9_mss_utils_to_throttle.H
/// @brief throttle API
///

// *HWP HWP Owner: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_POWER_THROTTLE_
#define _MSS_POWER_THROTTLE_

#include <fapi2.H>
#include <mss.H>
namespace mss
{
namespace power_thermal
{
///
/// @brief throttle constants used in the power_thermal functions
///
enum throttle_const : size_t
{
    /// Dram data bus utilization is bus utilization / 4
    DRAM_BUS_UTILS = 4,

    /// 10000 to convert to and from c%
    UTIL_CONVERSION = 10000,

    /// Conversion to percentage
    PERCENT_CONVERSION = 100,

    /// MIN_UTIL is  in c%
    MIN_UTIL = 100,

    /// IDLE_UTIL is  in c%
    IDLE_UTIL = 0,

    /// Minimum throttle allowed for the port and or slot. If we set to 0, we brick the port
    MIN_THROTTLE = 1,
};

///
/// @class throttle
/// @brief Determine power_thermal throttles for memory
///
class throttle
{
    private:
        ///
        /// @brief Calculate the power (cW) of inputs and the power curve
        /// @tparam T
        /// @param[in] i_util the databus utilization that the power will be based on
        /// @param[in] l_pos the dimm position for the power value being calculated.
        /// @return Integral type T
        ///
        template<typename T>
        inline T calc_power (const T i_util, const size_t i_pos) const
        {
            return ((i_util / UTIL_CONVERSION) * iv_pwr_slope[i_pos]) + iv_pwr_int[i_pos];
        }

        ///
        /// @brief Raise the o_value by the percent passed in
        /// @param[in] i_uplift the percent the o_Value should be raised by
        /// @param[out] o_value the value that will be modified
        ///
        inline void calc_power_uplift (const uint8_t i_uplift, double& o_value) const
        {
            o_value *= (1 + (static_cast<double>(i_uplift) / PERCENT_CONVERSION));
        }

    public:
        const fapi2::Target<fapi2::TARGET_TYPE_MCA>& iv_target;

        uint32_t iv_databus_port_max;

        uint8_t iv_power_uplift_idle;
        uint8_t iv_power_uplift;

        uint16_t iv_runtime_n_slot;
        uint16_t iv_runtime_n_port;
        uint32_t iv_m_clocks;
        uint32_t iv_dimm_thermal_limit[MAX_DIMM_PER_PORT] = {};
        uint16_t iv_pwr_slope[MAX_DIMM_PER_PORT] = {};
        uint16_t iv_pwr_int[MAX_DIMM_PER_PORT] = {};
        uint16_t iv_n_slot;
        uint16_t iv_n_port;
        uint32_t iv_port_power_limit;
        uint32_t iv_calc_port_maxpower;

        //default ctor deleted
        throttle() = delete;

        ///
        /// @brief Constructor
        /// @param[in] i_target MCA target to call power thermal stuff on
        /// @param[out] o_rc fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ctor was successful
        ///
        throttle( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_mca, fapi2::ReturnCode& o_rc);

        //
        // @brief Destructor
        //
        ~throttle() = default;

        ///
        /// @brief Calculates the min and max power usage for a port
        /// @param[in] i_idle_util the utilization of the databus in idle mode
        /// @param[in] i_max_util  the utilization of the port at maximum possible (mrw or calculated)
        /// @param[out] o_port_power_idle max value of port power in cW
        /// @param[out] o_port_power_max max value of port power in cW
        /// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff the split is OK
        /// @note Called twice in p9_mss_bulk_pwr_throttles
        ///
        fapi2::ReturnCode calc_port_power( const double i_idle_util [MAX_DIMM_PER_PORT],
                                           const double i_max_util [MAX_DIMM_PER_PORT],
                                           double& o_port_power_idle,
                                           double& o_port_power_max) const;
        ///
        /// @brief Calculates max and min power usages based off of DIMM power curves
        /// @param[in] i_databus_port_max max databus utilization for the port (either calculated or mrw)
        /// @param[in] i_port_power_calc_idle double of the port's power consumption at idle
        /// @param[out] o_dimm_power_idle array of dimm power in cW
        /// @param[out] o_dimm_power_max array of dimm power in cW
        /// @note Called in p9_mss_bulk_pwr_throttles
        /// @note used for the thermal throttles
        ///
        void calc_dimm_power(const double i_databus_idle,
                             const double i_databus_max,
                             double o_dimm_power_idle [MAX_DIMM_PER_PORT],
                             double o_dimm_power_max [MAX_DIMM_PER_PORT]) const;

        ///
        /// @brief Calculate the power curve in order to calculate databus utilization
        /// @param[in] i_power_idle double of the port's power consumption at idle
        /// @param[in] i_power_max double of the port's power consumption at max utilization
        /// @param[out] o_power_slope
        /// @param[out] o_power_int
        /// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff the split is OK
        /// @note Called in p9_mss_bulk_pwr_throttles
        /// @note Power curve needed to calculate the utilization
        ///
        fapi2::ReturnCode calc_power_curve(const double i_power_idle,
                                           const double i_power_max,
                                           uint32_t& o_power_slope,
                                           uint32_t& o_power_int) const;
        ///
        /// @brief Calculate the databus utilization given the power curve
        /// @param[in] i_slope
        /// @param[in] i_int
        /// @param[in] i_power_limit either iv_port_power_limit or thermal_power_limit depending on throttle type
        /// @param[out] o_port_util the port's databus utilization
        /// @note Called in p9_mss_bulk_pwr_throttles
        /// @note Chooses worst case between the maximum allowed databus utilization and the calculated value
        ///
        void calc_util_usage(const uint32_t i_slope,
                             const uint32_t i_int,
                             const uint32_t i_power_limit,
                             double& o_util) const;
        ///
        /// @brief set iv_n_port, iv_n_slot, iv_calc_port_maxpower
        /// @param[in] i_util_port pass in the calculated port databus utilization
        /// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
        ///
        fapi2::ReturnCode calc_slots_and_power (const double i_util_port);

        ///
        /// @brief calculated the output power estimate from the calculated N throttle
        /// @param[in] i_n_slot the N throttle per slot
        /// @param[in] i_n_port the N throttle per port
        /// @param[out] o_power the calculated power
        /// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff the split is OK
        ///
        fapi2::ReturnCode calc_power_from_n (const uint16_t i_n_slot, const uint16_t i_n_port, uint32_t& o_power) const;

        ///
        /// @brief Converts the port maximum databus util to a dimm level based on powerslopes and dimms installed
        /// @param[in] i_databus_port_max max databus utilization for the port (either calculated or mrw)
        /// @param[out] o_databus_dimm_max array of dimm utilization values
        /// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff the split is OK
        /// @note Called in p9_mss_bulk_pwr_throttles
        /// @used to calculate the port power based off of DIMM power curves
        ///
        fapi2::ReturnCode calc_databus( const double i_databus_port_max,
                                        double o_databus_dimm_max [MAX_DIMM_PER_PORT]);
        ///
        /// @brief Converts the port and slot util to a dimm level based on powerslopes and number of dimms installed
        /// @param[in] i_util_slot databus utilization for the slot
        /// @param[in] i_util_port databus utilization for the port
        /// @param[out] o_util_dimm_max array of dimm utilization values
        /// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff the split is OK
        /// @note determines worst case utilization per dimms, takes into account port and combine slot throttles
        ///
        fapi2::ReturnCode calc_split_util(
            const double i_util_slot,
            const double i_util_port,
            double o_util_dimm_max [MAX_DIMM_PER_PORT]) const;


        ///
        /// @brief Calculate ATTR_MSS_CHANNEL_PAIR_MAXPOWER and  ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_SLOT,
        /// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
        /// @note Called in p9_mss_bulk_pwr_throttles
        /// @note determines the throttle levels based off of the port's power curve, max databus utilization,
        /// and memwat target.
        /// @note currently sets the slot and port throttles to the same value
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
/// Equation:  N = (DRAM data bus utilization * M) / (4 * 10000)
///
inline uint32_t throttled_cmds(const uint32_t i_databus_util, const uint32_t i_num_dram_clocks)
{
    constexpr uint64_t l_divisor = DRAM_BUS_UTILS * UTIL_CONVERSION;
    const uint64_t l_dividend = i_databus_util * i_num_dram_clocks;
    const uint64_t l_result = l_dividend / l_divisor;

    //Make sure N is not equal to 0, or we brick the dram until reboot
    return ((l_result == 0) ? 1 : l_result);
}

///
/// @brief Calculate the port databus utilization based off of N throttles and M dram clocks
/// @param[in] i_n_throttles N (address operations) allowed within a window of M DRAM clocks
/// @param[in] i_num_dram_clocks window of M DRAM clocks
/// @param[out] o_calc_util
/// @return FAPI2_RC_SUCCESS iff method was a success
/// @note Uses N/M Throttling.
/// @note DRAM databus utilization = N * 4 * 10000 / M
///
template<typename T>
fapi2::ReturnCode calc_util_from_throttles(const uint16_t i_n_throttles,
        const uint32_t i_num_dram_clocks,
        T& o_calc_util)
{
    constexpr uint32_t l_multiplier = DRAM_BUS_UTILS * UTIL_CONVERSION;
    FAPI_ASSERT( (i_num_dram_clocks != 0),
                 fapi2::MSS_M_DRAM_CLOCKS_EQUALS_ZERO(),
                 "ATTR_MSS_MRW_MEM_M_DRAM_CLOCKS was not set and equals zero");

    o_calc_util = (static_cast<double>(i_n_throttles) * l_multiplier) / i_num_dram_clocks;

    // Best way to check for overflow if o_calc_util can be a double?
    // If o_calc_util overflows, the value inside will be below the expected outcome
    // So compare o_calc_util with the calculated value, but store calculated value in largest storage
    // Compare ">=" because o_calc_util can be a double, and so we can't compare just equality due to truncation
    FAPI_ASSERT( o_calc_util >= static_cast<uint64_t>((static_cast<double>(i_n_throttles) * l_multiplier) /
                 i_num_dram_clocks),
                 fapi2::MSS_OUTPUT_OVERFLOW_CALC_UTIL()
                 .set_RESULT((static_cast<double>(i_n_throttles) * l_multiplier) / i_num_dram_clocks),
                 "Overflow of output variable in calc_util_from_throttles throttles: %d, multiplier %d, dram_clocks %d",
                 i_n_throttles,
                 l_multiplier,
                 i_num_dram_clocks);

    o_calc_util = ( (o_calc_util == 0) ? MIN_UTIL : o_calc_util);

    FAPI_INF("In calc_util_from_throttles, calculated %d for output utilization", o_calc_util);
    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Determines if the double has decimal digits and adds 1 and rounds if true
/// @param[in] i_val the double to be rounded up if trialing digits
/// @return the input value rounded up to the next whole digit
/// @note Called in p9_mss_bulk_pwr_throttles
///
inline uint32_t round_up(double i_val)
{
    //convert to uint to truncate decimals and convert back to double for comparison
    uint32_t temp = uint32_t (i_val);

    //if not equal, lost something from truncating, so add 1
    temp += (temp == i_val) ? 0 : 1;

    //Truncate final value
    return temp;
}

///
/// @brief Perform thermal calculations as part of the effective configuration
/// @param[in] i_target the MCS target in which the runtime throttles will be reset
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode restore_runtime_throttles( const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target );

///
/// @brief Update the runtime throttles to the worst case of the general throttle values and the runtime values
/// @param[in] i_target the MCS target in which the runtime throttles will be set
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode update_runtime_throttles(const std::vector< fapi2::Target<fapi2::TARGET_TYPE_MCS> >& i_targets);

///
/// @brief set ATTR_MSS_RUNTIME_MEM_M_DRAM_CLOCKS and ATTR_MSS_MEM_WATT_TARGET
/// @param[in] i_targets vector of mcs targets all on the same vddr domain
/// @return FAPI2_RC_SUCCESS iff it was a success
///
fapi2::ReturnCode set_runtime_m_and_watt_limit( const std::vector< fapi2::Target<fapi2::TARGET_TYPE_MCS> >& i_targets );

///
/// @brief Equalize the throttles and estimated power at those throttle levels
/// @param[in] i_targets vector of MCS targets all on the same VDDR domain
/// @param[in] i_throttle_type denotes if this was done for POWER (VMEM) or THERMAL (VMEM+VPP) throttles
/// @return FAPI2_RC_SUCCESS iff ok
/// @note sets the throttles and power to the worst case
///
fapi2::ReturnCode equalize_throttles (const std::vector< fapi2::Target<fapi2::TARGET_TYPE_MCS> >& i_targets,
                                      const throttle_type i_throttle_type);

}//power_thermal
}// mss

#endif
