/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/power_thermal/gen_throttle.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file gen_throttle.H
/// @brief throttle API
///

// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_GEN_POWER_THROTTLE_
#define _MSS_GEN_POWER_THROTTLE_

#include <fapi2.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/power_thermal/gen_throttle_traits.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <generic/memory/lib/mss_generic_system_attribute_getters.H>
#include <generic/memory/lib/mss_generic_system_attribute_setters.H>
#include <generic/memory/lib/mss_generic_attribute_setters.H>
#include <generic/memory/lib/utils/mss_math.H>
#include <generic/memory/lib/utils/pos.H>

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

};

///
/// @brief Calculate the N throttle for a given dram data bus utilization value
///
/// @tparam T1  template parameter, type of input to be processed
/// @tparam T2  template parameter, type of input to be processed
/// @param[in]  i_dram_util     dram data bus utilization value
/// @param[in]  i_throttle_m   M throttle value in N/M throttling
///
/// @return int32_t calculated N throttle value
///
template<typename T1, typename T2>
inline uint32_t calc_n_from_dram_util(const T1 i_dram_util, const T2 i_throttle_m)
{
    constexpr uint64_t CONVERT_ADDR_UTIL_TO_DATA_UTIL = 4;

    return (static_cast<int>(static_cast<double>(i_dram_util)
                             * (i_throttle_m)
                             / (CONVERT_ADDR_UTIL_TO_DATA_UTIL)
                             / (PERCENT_CONVERSION)
                            )
           );
}

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
/// @tparam MC mss::mc_type
/// @tparam TT throttle_traits throttle traits for the given mc_type
/// @tparam T output type
/// @param[in] i_n_throttles N (address operations) allowed within a window of M DRAM clocks
/// @param[in] i_num_dram_clocks window of M DRAM clocks
/// @param[out] o_calc_util
/// @return FAPI2_RC_SUCCESS iff method was a success
/// @note Uses N/M Throttling.
/// @note DRAM databus utilization = N * 4 * 10000 / M
///
template<mss::mc_type MC = DEFAULT_MC_TYPE, typename TT = throttle_traits<MC>, typename T>
fapi2::ReturnCode calc_util_from_throttles(const uint16_t i_n_throttles,
        const uint32_t i_num_dram_clocks,
        T& o_calc_util)
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    constexpr uint32_t l_multiplier = DRAM_BUS_UTILS * UTIL_CONVERSION;
    const uint64_t l_calc_util_uint64 = static_cast<uint64_t>((static_cast<double>(i_n_throttles) * l_multiplier) /
                                        i_num_dram_clocks);
    FAPI_ASSERT( (i_num_dram_clocks != 0),
                 fapi2::MSS_M_DRAM_CLOCKS_EQUALS_ZERO(),
                 "ATTR_MSS_MRW_MEM_M_DRAM_CLOCKS was not set and equals zero");

    o_calc_util = (static_cast<double>(i_n_throttles) * l_multiplier) / i_num_dram_clocks;

    // Best way to check for overflow if o_calc_util can be a double?
    // If o_calc_util overflows, the value inside will be below the expected outcome
    // So compare o_calc_util with the calculated value, but store calculated value in largest storage
    // Compare ">=" because o_calc_util can be a double, and so we can't compare just equality due to truncation
    FAPI_ASSERT( o_calc_util >= l_calc_util_uint64,
                 fapi2::MSS_OUTPUT_OVERFLOW_CALC_UTIL()
                 .set_RESULT(o_calc_util)
                 .set_THROTTLES(i_n_throttles)
                 .set_DRAM_CLOCKS(i_num_dram_clocks)
                 .set_MULTIPLIER(l_multiplier),
                 "Overflow of output variable in calc_util_from_throttles throttles: %d, multiplier %d, dram_clocks %d",
                 i_n_throttles,
                 l_multiplier,
                 i_num_dram_clocks);

    // Check for the minimum
    if(o_calc_util < TT::MIN_UTIL)
    {
        FAPI_INF("Calculated utilization (%u) is less than the minimum utilization: %u. Setting to minimum value",
                 static_cast<uint32_t>(o_calc_util), static_cast<uint32_t>(TT::MIN_UTIL));
        o_calc_util = TT::MIN_UTIL;
    }

    FAPI_INF("In calc_util_from_throttles, calculated %u for output utilization from throttles:%d, dram_clocks %d",
             static_cast<uint32_t>(o_calc_util), i_n_throttles, i_num_dram_clocks);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform thermal calculations as part of the effective configuration
/// @tparam MC mss::mc_type
/// @tparam T the fapi2 target type of the target
/// @tparam TT throttle_traits throttle traits for the given mc_type
/// @param[in] i_target the MCS target in which the runtime throttles will be reset
/// @return FAPI2_RC_SUCCESS iff ok
///
template<mss::mc_type MC = DEFAULT_MC_TYPE, fapi2::TargetType T, typename TT = throttle_traits<MC>>
fapi2::ReturnCode restore_runtime_throttles( const fapi2::Target<T>& i_target )
{

    uint32_t l_max_databus = 0;
    uint32_t l_throttle_m_clocks = 0;

    FAPI_TRY( mss::attr::get_mrw_mem_m_dram_clocks(l_throttle_m_clocks) );
    FAPI_TRY( mss::attr::get_mrw_max_dram_databus_util(l_max_databus) );

    //Set runtime throttles to unthrottled value, using max dram utilization and M throttle
    //Do I need to check to see if any DIMMS configured  on the port?
    for (const auto& l_port : mss::find_targets<TT::PORT_TARGET_TYPE>(i_target))
    {
        uint16_t l_run_throttle = 0;

        if (mss::count_dimm (l_port) != 0)
        {
            l_run_throttle = mss::power_thermal::throttled_cmds (l_max_databus, l_throttle_m_clocks);
        }

        FAPI_TRY( mss::attr::set_runtime_mem_throttled_n_commands_per_port( l_port, l_run_throttle) );
        FAPI_TRY( mss::attr::set_runtime_mem_throttled_n_commands_per_slot( l_port, l_run_throttle) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Update the runtime throttles to the worst case of the general throttle values and the runtime values
/// @tparam MC mss::mc_type
/// @tparam T the fapi2 target type of the target
/// @tparam TT throttle_traits throttle traits for the given mc_type
/// @param[in] i_target the MCS target in which the runtime throttles will be set
/// @return FAPI2_RC_SUCCESS iff ok
///
template<mss::mc_type MC = DEFAULT_MC_TYPE, fapi2::TargetType T, typename TT = throttle_traits<MC>>
fapi2::ReturnCode update_runtime_throttle(const fapi2::Target<T>& i_target)

{

    if (mss::count_dimm(i_target) == 0)
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    for (const auto& l_port : mss::find_targets<TT::PORT_TARGET_TYPE>(i_target))
    {

        uint16_t l_run_slot = 0;
        uint16_t l_run_port = 0;
        uint16_t l_calc_slot = 0;
        uint16_t l_calc_port = 0;

        FAPI_TRY(mss::attr::get_runtime_mem_throttled_n_commands_per_slot(l_port, l_run_slot));
        FAPI_TRY(mss::attr::get_runtime_mem_throttled_n_commands_per_port(l_port, l_run_port));
        FAPI_TRY(mss::attr::get_mem_throttled_n_commands_per_slot(l_port, l_calc_slot));
        FAPI_TRY(mss::attr::get_mem_throttled_n_commands_per_port(l_port, l_calc_port));

        //Choose the worst case between runtime and calculated throttles
        //Have to make sure the calc_slot isn't equal to 0 though
        l_run_slot = (l_calc_slot != 0) ?
                     std::min(l_run_slot, l_calc_slot) : l_run_slot;
        l_run_port = (l_calc_port != 0) ?
                     std::min(l_run_port, l_calc_port) : l_run_port;

        FAPI_INF("New runtime throttles for %s for slot are %d, port are %d",
                 mss::c_str(l_port),
                 l_run_slot,
                 l_run_port);

        FAPI_TRY( mss::attr::set_runtime_mem_throttled_n_commands_per_port(l_port, l_run_port) );
        FAPI_TRY( mss::attr::set_runtime_mem_throttled_n_commands_per_slot(l_port, l_run_slot) );
    }


fapi_try_exit:
    return fapi2::current_err;
}



///
/// @brief Update the runtime throttles to the worst case of the general throttle values and the runtime values
/// @tparam MC mss::mc_type
/// @tparam T the fapi2 target type of the target
/// @tparam TT throttle_traits throttle traits for the given mc_type
/// @param[in] i_target the MCS target in which the runtime throttles will be set
/// @return FAPI2_RC_SUCCESS iff ok
///
template<mss::mc_type MC = DEFAULT_MC_TYPE, fapi2::TargetType T, typename TT = throttle_traits<MC>>
fapi2::ReturnCode update_runtime_throttles(const std::vector< fapi2::Target<T> >& i_targets)

{
    for (const auto& l_mc : i_targets)
    {
        FAPI_TRY(update_runtime_throttle(l_mc));
    }

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @class throttle
/// @brief Determine power_thermal throttles for memory
/// @tparam MC mss::mc_type
/// @tparam TT throttle_traits throttle traits for the given mc_type
///
template<mss::mc_type MC = DEFAULT_MC_TYPE, typename TT = throttle_traits<MC>>
class throttle
{
    private:
        ///
        /// @brief Calculate the power (cW) of inputs and the power curve
        /// @tparam T the type of i_util and return value
        /// @param[in] i_util the databus utilization that the power will be based on
        /// @param[in] l_pos the dimm position for the power value being calculated.
        /// @return Integral type T
        ///
        template<typename T>
        inline T calc_power (const T i_util, const size_t i_pos, fapi2::ReturnCode& o_rc ) const
        {
            o_rc = fapi2::FAPI2_RC_SUCCESS;
            FAPI_ASSERT( (i_pos < TT::DIMMS_PER_PORT),
                         fapi2::MSS_POWER_THERMAL_DIMM_INDEX_OUT_OF_BOUND()
                         .set_PORT_TARGET(iv_target)
                         .set_INPUT_SIZE(i_pos)
                         .set_MAX_SIZE(TT::DIMMS_PER_PORT),
                         "The dimm is index is out of bound for the port index: %d, max: %d for port %s",
                         i_pos, TT::DIMMS_PER_PORT, mss::c_str(iv_target) );

            return ((i_util / UTIL_CONVERSION) * iv_pwr_slope[i_pos]) + iv_pwr_int[i_pos];

        fapi_try_exit:
            o_rc = fapi2::current_err;
            return 0;
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
        const fapi2::Target<TT::PORT_TARGET_TYPE>& iv_target;

        uint32_t iv_databus_port_max;

        uint8_t iv_power_uplift_idle;
        uint8_t iv_power_uplift;

        uint16_t iv_runtime_n_slot;
        uint16_t iv_runtime_n_port;
        uint32_t iv_m_clocks;
        uint32_t iv_dimm_thermal_limit[TT::DIMMS_PER_PORT] = {};
        uint16_t iv_pwr_slope[TT::DIMMS_PER_PORT] = {};
        uint16_t iv_pwr_int[TT::DIMMS_PER_PORT] = {};
        uint16_t iv_n_slot;
        uint16_t iv_n_port;
        uint32_t iv_port_power_limit;
        uint32_t iv_calc_port_maxpower;

        //default ctor deleted
        throttle() = delete;

        ///
        /// @brief Constructor
        /// @param[in] i_target port target to call power thermal stuff on
        /// @param[out] o_rc fapi2::ReturnCode fapi2::FAPI2_RC_SUCCESS iff ctor was successful
        ///
        throttle( const fapi2::Target<TT::PORT_TARGET_TYPE>& i_port, fapi2::ReturnCode& o_rc);

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
        fapi2::ReturnCode calc_port_power( const double i_idle_util [TT::DIMMS_PER_PORT],
                                           const double i_max_util [TT::DIMMS_PER_PORT],
                                           double& o_port_power_idle,
                                           double& o_port_power_max) const;
        ///
        /// @brief Calculates max and min power usages based off of DIMM power curves
        /// @param[in] i_databus_port_max max databus utilization for the port (either calculated or mrw)
        /// @param[in] i_port_power_calc_idle double of the port's power consumption at idle
        /// @param[out] o_dimm_power_idle array of dimm power in cW
        /// @param[out] o_dimm_power_max array of dimm power in cW
        /// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff the split is OK
        /// @note Called in p9_mss_bulk_pwr_throttles
        /// @note used for the thermal throttles
        ///
        fapi2::ReturnCode calc_dimm_power(const double i_databus_idle,
                                          const double i_databus_max,
                                          double o_dimm_power_idle [TT::DIMMS_PER_PORT],
                                          double o_dimm_power_max [TT::DIMMS_PER_PORT]) const;

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
        /// @param[in] i_slope the slope of power curve
        /// @param[in] i_int the intercept of power curve
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
                                        double o_databus_dimm_max [TT::DIMMS_PER_PORT]);
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
            double o_util_dimm_max [TT::DIMMS_PER_PORT]) const;


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
/// @brief Constructor
/// @tparam MC mss::mc_type
/// @tparam TT throttle_traits throttle traits for the given mc_type
/// @param[in] i_target MCS target to call power thermal stuff on
/// @param[out] o_rc, a return code which determines the success of the constructor
///
template<mss::mc_type MC, typename TT>
throttle<MC, TT>::throttle( const fapi2::Target<TT::PORT_TARGET_TYPE>& i_port, fapi2::ReturnCode& o_rc) :
    iv_target(i_port),
    iv_databus_port_max(0),
    iv_runtime_n_slot(0),
    iv_runtime_n_port(0),
    iv_n_slot(0),
    iv_n_port(0),
    iv_port_power_limit(0),
    iv_calc_port_maxpower(0)
{
    FAPI_TRY( mss::attr::get_mrw_max_dram_databus_util(iv_databus_port_max), "%s Error in throttle ctor",
              mss::c_str(i_port) );
    FAPI_TRY( mss::attr::get_mrw_dimm_power_curve_percent_uplift(iv_power_uplift), "%s Error in throttle ctor",
              mss::c_str(i_port) );
    FAPI_TRY( mss::attr::get_mrw_dimm_power_curve_percent_uplift_idle(iv_power_uplift_idle), "%s Error in throttle ctor",
              mss::c_str(i_port) );
    FAPI_TRY( mss::attr::get_dimm_thermal_limit( iv_target, iv_dimm_thermal_limit), "%s Error in throttle ctor",
              mss::c_str(i_port) );
    FAPI_TRY( mss::attr::get_total_pwr_intercept( iv_target, iv_pwr_int), "%s Error in throttle ctor", mss::c_str(i_port) );
    FAPI_TRY( mss::attr::get_total_pwr_slope( iv_target, iv_pwr_slope), "%s Error in throttle ctor", mss::c_str(i_port) );
    FAPI_TRY( mss::attr::get_runtime_mem_throttled_n_commands_per_slot(iv_target, iv_runtime_n_slot ),
              "%s Error in throttle ctor",
              mss::c_str(i_port) );
    FAPI_TRY( mss::attr::get_runtime_mem_throttled_n_commands_per_port(iv_target, iv_runtime_n_port ),
              "%s Error in throttle ctor",
              mss::c_str(i_port) );
    FAPI_TRY( mss::attr::get_mrw_mem_m_dram_clocks(iv_m_clocks), "%s Error in throttle ctor", mss::c_str(i_port) );

    //Port power limit = sum of dimm power limits
    for ( const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(iv_target) )
    {
        uint32_t l_dimm_limit = 0;
        FAPI_TRY( mss::attr::get_mem_watt_target( l_dimm, l_dimm_limit) );
        iv_port_power_limit += l_dimm_limit;
    }

    FAPI_INF("Setting up throttle for target %s, Values are: max databus is %d, uplifts are %d %d, runtime throttles are %d %d",
             mss::c_str(iv_target),
             iv_databus_port_max,
             iv_power_uplift,
             iv_power_uplift_idle,
             iv_runtime_n_slot,
             iv_runtime_n_port);

    FAPI_INF("The dimm power limit is %d, dram clocks are %d, dimm power curve slopes are %d %d for %s",
             iv_port_power_limit,
             iv_m_clocks,
             iv_pwr_slope[0],
             iv_pwr_slope[1],
             mss::c_str(iv_target));

    FAPI_INF("DIMM power curve intercepts are %d %d, DIMM power thermal limits are %d %d for %s",
             iv_pwr_int[0],
             iv_pwr_int[1],
             iv_dimm_thermal_limit[0],
             iv_dimm_thermal_limit[1],
             mss::c_str(iv_target));

    FAPI_ASSERT( (iv_databus_port_max != 0),
                 fapi2::MSS_NO_DATABUS_UTILIZATION()
                 .set_PORT_TARGET(iv_target)
                 .set_PORT_DATABUS_UTIL(iv_databus_port_max)
                 .set_DIMM_COUNT(mss::count_dimm(iv_target)),
                 "Failed to get max databus utilization for target %s",
                 mss::c_str(iv_target));

    FAPI_ASSERT( (iv_port_power_limit != 0),
                 fapi2::MSS_NO_PORT_POWER_LIMIT()
                 .set_PORT_TARGET(iv_target)
                 .set_COUNT_DIMMS( mss::count_dimm(iv_target))
                 .set_PORT_POWER_LIMIT( iv_port_power_limit),
                 "Error calculating port_power_limit on target %s with %d DIMMs installed",
                 mss::c_str(iv_target),
                 iv_port_power_limit);

    //Checking to make sure all of the attributes are valid
    for ( const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(iv_target) )
    {
        const auto l_pos = mss::index(l_dimm);
        FAPI_ASSERT( (iv_pwr_int[l_pos] != 0),
                     fapi2::MSS_POWER_INTERCEPT_NOT_SET()
                     .set_PORT_TARGET(iv_target),
                     "The attribute ATTR_MSS_TOTAL_PWR_INTERCEPT equals 0 for %s",
                     mss::c_str(l_dimm));

        FAPI_ASSERT( (iv_pwr_slope[l_pos] != 0),
                     fapi2::MSS_POWER_SLOPE_NOT_SET()
                     .set_PORT_TARGET(iv_target),
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
template<mss::mc_type MC, typename TT>
fapi2::ReturnCode throttle<MC, TT>::power_regulator_throttles ()
{
    double l_port_power_calc_idle = 0;
    double l_port_power_calc_max = 0;
    uint32_t l_port_power_slope = 0;
    uint32_t l_port_power_int = 0;
    double l_calc_util_port = 0;
    double  l_databus_dimm_max[TT::DIMMS_PER_PORT] = {};
    double  l_calc_databus_port_idle[TT::DIMMS_PER_PORT] = {TT::IDLE_UTIL, TT::IDLE_UTIL};

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

    FAPI_INF("POWER throttles: %s max port power is %u", mss::c_str(iv_target),
             static_cast<uint32_t>(l_port_power_calc_max));

    //Calculate the power curve slope and intercept using the port's min and max power values
    FAPI_TRY(calc_power_curve(l_port_power_calc_idle,
                              l_port_power_calc_max,
                              l_port_power_slope,
                              l_port_power_int),
             "Failed to calculate the power curve for port %s, calculated port power max is %u, idle is %u",
             mss::c_str(iv_target),
             static_cast<uint32_t>(l_port_power_calc_max),
             static_cast<uint32_t>(l_port_power_calc_idle));

    FAPI_INF("%s POWER Port power limit is %d", mss::c_str(iv_target), iv_port_power_limit);
    //Calculate the port's utilization to get under watt target using the port's calculated slopes
    calc_util_usage(l_port_power_slope,
                    l_port_power_int,
                    iv_port_power_limit,
                    l_calc_util_port);

    FAPI_INF("%s POWER calc util port is %u",  mss::c_str(iv_target), static_cast<uint32_t>(l_calc_util_port));

    //Calculate the new slot values and the max power value for the port
    FAPI_TRY( calc_slots_and_power( l_calc_util_port),
              "%s Error calculating the final throttles and power values for target with passed in port utilization %u",
              mss::c_str(iv_target),
              static_cast<uint32_t>(l_calc_util_port));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief set iv_n_port, iv_n_slot, iv_calc_port_maxpower
/// @param[in] i_util_port pass in the calculated port databus utilization
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
///
template<mss::mc_type MC, typename TT>
fapi2::ReturnCode throttle<MC, TT>::calc_slots_and_power (const double i_util_port)
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
template<mss::mc_type MC, typename TT>
fapi2::ReturnCode throttle<MC, TT>::thermal_throttles ()
{
    double l_dimm_power_idle [TT::DIMMS_PER_PORT] = {};
    double l_dimm_power_max [TT::DIMMS_PER_PORT] = {};
    uint32_t l_dimm_power_slope [TT::DIMMS_PER_PORT] = {};
    uint32_t l_dimm_power_int [TT::DIMMS_PER_PORT] = {};
    double l_calc_util [TT::DIMMS_PER_PORT] = {};
    const auto l_count = count_dimm (iv_target);
    uint8_t l_found_ddimm = 0;

    //Calculate the dimm power range for each dimm at max utilization for each
    FAPI_TRY( calc_dimm_power(TT::IDLE_UTIL,
                              iv_databus_port_max,
                              l_dimm_power_idle,
                              l_dimm_power_max));

    //Let's calculate the N throttle for each DIMM
    for ( const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(iv_target) )
    {
        uint16_t l_temp_n_slot = 0;
        const uint8_t l_pos = mss::index(l_dimm);
        mss::dimm::kind<MC> l_kind (l_dimm);
        l_found_ddimm = (l_kind.iv_dimm_type == fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_DDIMM) ? 1 : l_found_ddimm;
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

        FAPI_INF("THERMAL throttles: %s dram databus utilization is %u", mss::c_str(l_dimm),
                 static_cast<uint32_t>(l_calc_util[l_pos]));

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
    FAPI_INF("THERMAL throttles: runtime slot is %d, calc n slot is %d for %s", iv_runtime_n_slot, iv_n_slot,
             mss::c_str(iv_target));
    //DDDIMMs: Taking the min of the SLOT and the iv_runtime_port throttle value
    //ISDIMMs: Taking the min of the SLOT * (# of dimms on the port) and the iv_runtime_port throttle value
    //Thermal throttling happens after the POWER calculations. the iv_runtime_n_port value shouldn't be set to 0
    iv_n_port = (l_found_ddimm) ?
                std::min(iv_runtime_n_port, static_cast<uint16_t>(iv_n_slot)) :
                std::min(iv_runtime_n_port, static_cast<uint16_t>(iv_n_slot * l_count));
    iv_n_port = (iv_n_port == 0) ? TT::MIN_THROTTLE : iv_n_port;

    iv_n_slot = std::min(iv_n_slot, iv_runtime_n_slot);
    iv_n_slot = (iv_n_slot == 0) ? TT::MIN_THROTTLE : iv_n_slot;

    //Now time to get and set iv_calc_port_max from the calculated N throttle
    FAPI_TRY( calc_power_from_n(iv_n_slot, iv_n_port, iv_calc_port_maxpower),
              "Failed to calculate the final max port maxpower. Slot throttle value is %d, port value is %d for %s",
              iv_n_slot,
              iv_n_port,
              mss::c_str(iv_target));

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    FAPI_ERR("Error calculating mss::power_thermal::thermal_throttles() for %s", mss::c_str(iv_target));
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
template<mss::mc_type MC, typename TT>
fapi2::ReturnCode throttle<MC, TT>::calc_port_power(const double i_idle_util [TT::DIMMS_PER_PORT],
        const double i_max_util [TT::DIMMS_PER_PORT],
        double& o_port_power_idle,
        double& o_port_power_max) const
{
    //Playing it safe
    o_port_power_idle = 0;
    o_port_power_max = 0;
    fapi2::ReturnCode l_rc;

    //Calculate the port power curve info by summing the dimms on the port
    for ( const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(iv_target) )
    {
        const auto l_pos = mss::index(l_dimm);
        //Printing as decimals because HB messes up floats
        FAPI_INF("%s max dram databus for DIMM in pos %d is %u, databus for idle is %u",
                 mss::c_str(iv_target),
                 l_pos,
                 static_cast<uint32_t>(i_max_util[l_pos]),
                 static_cast<uint32_t>(i_idle_util[l_pos]) );
        //Sum up the dimm's power to calculate the port power curve
        o_port_power_idle += calc_power(i_idle_util[l_pos], l_pos, l_rc);
        FAPI_TRY(l_rc, "calc_power failed on %s", l_dimm);
        o_port_power_max  += calc_power(i_max_util[l_pos], l_pos, l_rc);
        FAPI_TRY(l_rc, "calc_power failed on %s", l_dimm);
    }

    //Raise the powers by the uplift percent
    calc_power_uplift(iv_power_uplift_idle, o_port_power_idle);
    calc_power_uplift(iv_power_uplift, o_port_power_max);

    FAPI_ASSERT( (o_port_power_max > 0),
                 fapi2::MSS_NO_PORT_POWER()
                 .set_PORT_TARGET(iv_target)
                 .set_COUNT_DIMMS(mss::count_dimm(iv_target))
                 .set_IDLE_UTILIZATION_DIMM_0(i_idle_util[0])
                 .set_IDLE_UTILIZATION_DIMM_1(i_idle_util[1])
                 .set_MAX_UTILIZATION_DIMM_0(i_max_util[0])
                 .set_MAX_UTILIZATION_DIMM_1(i_max_util[1]),
                 "No Port Power limit was calculated for %s, %d DIMMs installed, DIMM 0 Utils Idle %d Max %d, DIMM 1 Utils Idle %d Max %d",
                 mss::c_str(iv_target),
                 mss::count_dimm(iv_target),
                 i_idle_util[0],
                 i_max_util[0],
                 i_idle_util[1],
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
template<mss::mc_type MC, typename TT>
fapi2::ReturnCode throttle<MC, TT>::calc_dimm_power(const double i_databus_idle,
        const double i_databus_max,
        double o_dimm_power_idle [TT::DIMMS_PER_PORT],
        double o_dimm_power_max [TT::DIMMS_PER_PORT]) const
{
    for ( const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(iv_target) )
    {
        fapi2::ReturnCode l_rc;
        const uint8_t l_pos = mss::index(l_dimm);
        o_dimm_power_idle[l_pos] = calc_power(i_databus_idle, l_pos, l_rc);
        FAPI_TRY(l_rc, "calc_power failed on %s", l_dimm);
        o_dimm_power_max[l_pos]  = calc_power(i_databus_max, l_pos, l_rc);
        FAPI_TRY(l_rc, "calc_power failed on %s", l_dimm);

        //Raise the powers by the uplift percent
        calc_power_uplift(iv_power_uplift_idle, o_dimm_power_idle[l_pos]);
        calc_power_uplift(iv_power_uplift, o_dimm_power_max[l_pos]);

        FAPI_INF("Calc_dimm_power: dimm (%d) power max is %u, dimm slope %d, intercept %d for %s",
                 l_pos,
                 static_cast<uint32_t>(o_dimm_power_max[l_pos]),
                 iv_pwr_slope[l_pos],
                 iv_pwr_int[l_pos],
                 mss::c_str(l_dimm));
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    FAPI_INF("Error calculating mss::power_thermal::calc_dimm_power for %s", mss::c_str(iv_target));
    return fapi2::current_err;
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
template<mss::mc_type MC, typename TT>
fapi2::ReturnCode throttle<MC, TT>::calc_power_curve(const double i_power_idle,
        const double i_power_max,
        uint32_t& o_slope,
        uint32_t& o_int) const
{
    auto l_min_util = TT::MIN_UTIL;
    const double l_divisor = ((static_cast<double>(iv_databus_port_max) / UTIL_CONVERSION) - TT::IDLE_UTIL);
    FAPI_ASSERT ((l_divisor > 0),
                 fapi2::MSS_CALC_POWER_CURVE_DIVIDE_BY_ZERO()
                 .set_PORT_TARGET(iv_target)
                 .set_PORT_DATABUS_UTIL(iv_databus_port_max)
                 .set_UTIL_CONVERSION(UTIL_CONVERSION)
                 .set_IDLE_UTIL(l_min_util)
                 .set_RESULT(l_divisor),
                 "Calculated zero for the divisor in calc_power_curve on target %s",
                 mss::c_str(iv_target) );

    FAPI_ASSERT (((i_power_max - i_power_idle) > 0),
                 fapi2::MSS_CALC_POWER_CURVE_NEGATIVE_OR_ZERO_SLOPE()
                 .set_PORT_TARGET(iv_target)
                 .set_PORT_IDLE_POWER(i_power_idle)
                 .set_PORT_MAX_UTIL_POWER(i_power_max)
                 .set_RESULT(i_power_max - i_power_idle),
                 "Calculated zero or negative value for the slope in calc_power_curve (%u - %u) on target %s",
                 static_cast<uint32_t>(i_power_max), static_cast<uint32_t>(i_power_idle), mss::c_str(iv_target) );

    o_slope = (i_power_max - i_power_idle) / l_divisor;
    o_int = i_power_idle - (o_slope * TT::IDLE_UTIL);
    FAPI_INF("Calc_power_curve: power idle is %u, max is %u, slope is %d, int is %d for %s",
             static_cast<uint32_t>(i_power_idle),
             static_cast<uint32_t>(i_power_max),
             o_slope,
             o_int,
             mss::c_str(iv_target));
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    FAPI_INF("Error calculating mss::power_thermal::calc_power_curve for %s", mss::c_str(iv_target));
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
template<mss::mc_type MC, typename TT>
void throttle<MC, TT>::calc_util_usage(const uint32_t i_slope,
                                       const uint32_t i_int,
                                       const uint32_t i_power_limit,
                                       double& o_util) const
{
    // Return 0 utilization if our intercept is above the power limit
    o_util = (i_power_limit > i_int) ? (((static_cast<double>(i_power_limit) - i_int) / i_slope ) * UTIL_CONVERSION) : 0;

    // Cast to uint32 for edge case where it has decimals
    o_util = (static_cast<uint32_t>(o_util) < iv_databus_port_max) ? static_cast<uint32_t>(o_util) : iv_databus_port_max;

    // Check for the minimum threshnold and update if need be
    if(o_util < TT::MIN_UTIL)
    {
        FAPI_INF("Calculated utilization (%u) is less than the minimum utilization: %u. Setting to minimum value for %s",
                 static_cast<uint32_t>(o_util),
                 static_cast<uint32_t>(TT::MIN_UTIL), mss::c_str(iv_target));
        o_util = TT::MIN_UTIL;
    }
}

///
/// @brief calculated the output power estimate from the calculated N throttle
/// @param[in] i_n_slot the throttle per slot in terms of N commands
/// @param[in] i_n_port the throttle per port in terms of N commands
/// @param[out] o_power the calculated power
/// @return fapi2::ReturnCode iff it was a success
///
template<mss::mc_type MC, typename TT>
fapi2::ReturnCode throttle<MC, TT>::calc_power_from_n (const uint16_t i_n_slot,
        const uint16_t i_n_port,
        uint32_t& o_power) const
{
    double l_calc_util_port = 0;
    double l_calc_util_slot = 0;
    double l_calc_databus_port_max[TT::DIMMS_PER_PORT] = {};
    double l_calc_databus_port_idle[TT::DIMMS_PER_PORT] = {};
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
              "Error splitting the utilization for target %s with slot utilization %u and port util %u",
              mss::c_str(iv_target),
              static_cast<uint32_t>(l_calc_util_slot),
              static_cast<uint32_t>(l_calc_util_port));

    FAPI_TRY( calc_port_power(l_calc_databus_port_idle,
                              l_calc_databus_port_max,
                              l_port_power_idle,
                              l_port_power_max),
              "Error calculating the port power value for %s. Slot value is %d, port value is %d",
              mss::c_str(iv_target),
              i_n_slot,
              i_n_port);

    o_power = mss::round_up (l_port_power_max);

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
template<mss::mc_type MC, typename TT>
fapi2::ReturnCode throttle<MC, TT>::calc_databus (const double i_databus_port_max,
        double o_databus_dimm_max [TT::DIMMS_PER_PORT])
{
    const uint8_t l_count_dimms = count_dimm(iv_target);

    //No work for no dimms
    if (l_count_dimms == 0)
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    for (const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(iv_target))
    {
        //Left early if count_dimms == 0
        // For DDIMM, set each virtual DIMM to the same utilization value since mrw slope/intercept/limit attributes
        //   are equally divided by number of virtual dimms  (ie.  mrw values are for whole DDIMM, not individual virtual DIMMs)
        // For ISDIMM, divide utilization by number of DIMMs on the port
        mss::dimm::kind<MC> l_kind (l_dimm);
        o_databus_dimm_max[mss::index(l_dimm)] = (l_kind.iv_dimm_type == fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_DDIMM) ?
                i_databus_port_max :
                i_databus_port_max / l_count_dimms;
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
                  .set_PORT_TARGET(iv_target)
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
template<mss::mc_type MC, typename TT>
fapi2::ReturnCode throttle<MC, TT>::calc_split_util(
    const double i_util_slot,
    const double i_util_port,
    double o_util_dimm_max [TT::DIMMS_PER_PORT]) const
{
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    uint8_t l_found_ddimm = 0;
    const uint8_t l_count_dimms = count_dimm (iv_target);
    //The total utilization to be used is limited by either what the port can allow or what the dimms can use
    FAPI_ASSERT( (i_util_slot <= i_util_port),
                 fapi2::MSS_SLOT_UTIL_EXCEEDS_PORT()
                 .set_PORT_TARGET(iv_target)
                 .set_SLOT_UTIL(i_util_slot)
                 .set_PORT_UTIL(i_util_port),
                 "The slot utilization (%u) exceeds the port's utilization (%u) for %s",
                 static_cast<uint32_t>(i_util_slot),
                 static_cast<uint32_t>(i_util_port),
                 mss::c_str(iv_target));

    if (l_count_dimms == 0)
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    for ( const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(iv_target) )
    {
        mss::dimm::kind<MC> l_kind (l_dimm);
        l_found_ddimm = (l_kind.iv_dimm_type == fapi2::ENUM_ATTR_MEM_EFF_DIMM_TYPE_DDIMM) ? 1 : l_found_ddimm;
    }

    //assumptions slot <= port, l_count_dimms <=2
    if (i_util_slot * l_count_dimms > i_util_port)
    {
        FAPI_INF("i_util_slot is %u, i_util_port is %u, l_count_dimms is %d for %s",
                 static_cast<uint32_t>(i_util_slot),
                 static_cast<uint32_t>(i_util_port),
                 l_count_dimms,
                 mss::c_str(iv_target));
        const uint8_t l_high_pos = (iv_pwr_slope[0] >= iv_pwr_slope[1]) ? 0 : 1;

        //Highest power_slope gets the higher utilization
        o_util_dimm_max[l_high_pos] = std::min(i_util_slot, i_util_port);
        //Set the other dimm to the left over utilization (i_util_port - i_util_slot) if not a DDIMM, otherwise set to same value as above
        o_util_dimm_max[(!l_high_pos)] = (l_found_ddimm) ?
                                         o_util_dimm_max[l_high_pos] :
                                         ((l_count_dimms == TT::DIMMS_PER_PORT) ?
                                          (i_util_port - o_util_dimm_max[l_high_pos]) :
                                          0
                                         );

        FAPI_INF("Split utilization for target %s, DIMM in %d gets %u, DIMM in %d gets %u",
                 mss::c_str(iv_target),
                 l_high_pos,
                 static_cast<uint32_t>(o_util_dimm_max[l_high_pos]),
                 !l_high_pos,
                 static_cast<uint32_t>(o_util_dimm_max[!l_high_pos]));
    }
    else
    {
        //If only 1 dimm, i_util_port == i_util_slot
        //If 2 dimms, 2*i_util_slot <= i_util_pot
        //Either way, limit utilization by the slot value
        for (const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(iv_target))
        {
            const size_t l_pos = mss::index(l_dimm);
            o_util_dimm_max[l_pos] = i_util_slot;
        }
    }

    //make sure both are not 0
    FAPI_ASSERT ( (o_util_dimm_max[0] != 0) || (o_util_dimm_max[1] != 0),
                  fapi2::MSS_NO_DATABUS_UTILIZATION()
                  .set_PORT_TARGET(iv_target)
                  .set_PORT_DATABUS_UTIL(i_util_port)
                  .set_DIMM_COUNT(mss::count_dimm(iv_target)),
                  "Failed to calculated util utilization for target %s",
                  mss::c_str(iv_target));
fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Calculate utilization from input or safemode throttles
/// @tparam MC mss::mc_type
/// @tparam T the fapi2 target type of the target
/// @tparam TT throttle_traits throttle traits for the given MC target type
/// @param[in] i_target the port target
/// @param[in] i_input_databus_util input utilization
/// @param[in] i_dram_clocks window of M DRAM clocks
/// @param[in] i_safemode_throttle_per_port safemode throttle value
/// @param[in] i_max_databus_util databus utilization limit
/// @param[out] o_util calculated utilization
/// @param[out] o_util_error true if input utilization is lower than minimum allowed
/// @param[out] o_safemode true if safemode throttle values were used for calculation
/// @return fapi2::FAPI2_RC_SUCCESS if ok
///
template<mss::mc_type MC = DEFAULT_MC_TYPE, fapi2::TargetType T, typename TT = throttle_traits<MC>>
fapi2::ReturnCode calc_utilization(const fapi2::Target<T>& i_target,
                                   const uint32_t i_input_databus_util,
                                   const uint32_t i_dram_clocks,
                                   const uint16_t i_safemode_throttle_per_port,
                                   const uint32_t i_max_databus_util,
                                   uint32_t& o_util,
                                   bool& o_util_error,
                                   bool& o_safemode)
{
    constexpr uint64_t l_min_util = TT::MIN_UTIL;

    o_util = i_input_databus_util;
    o_safemode = false;

    // Use MRW safemode throttle values if input utilization is zero
    if (i_input_databus_util == 0)
    {
        FAPI_TRY(calc_util_from_throttles<MC>(i_safemode_throttle_per_port,
                                              i_dram_clocks,
                                              o_util),
                 "%s Error calculating utilization from safemode throttle %d and mem clocks %d",
                 mss::c_str(i_target),
                 i_safemode_throttle_per_port,
                 i_dram_clocks);
        FAPI_INF("%s Safemode throttles being used since input util is zero:  Using N=%d, Utilization %d %%",
                 mss::c_str(i_target),
                 i_safemode_throttle_per_port,
                 o_util);
        o_safemode = true;
    }
    else if (i_input_databus_util < l_min_util)
    {
        o_util_error = true;
    }

    // Make sure MIN_UTIL <= input_utilization <= max_utilization
    o_util = (o_util >= l_min_util) ? std::min(o_util, i_max_databus_util) : l_min_util;

    FAPI_INF("%s MRW dram clock window: %d, databus utilization: %d",
             mss::c_str(i_target),
             i_dram_clocks,
             o_util);

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Equalize the throttles and estimated power at those throttle levels
/// @tparam MC mss::mc_type
/// @tparam T the fapi2 MC target type of the target
/// @tparam TT throttle_traits throttle traits for the given mc_type
/// @param[in] i_targets vector of MCS targets all on the same VDDR domain
/// @param[in] i_throttle_type denotes if this was done for POWER (VMEM) or THERMAL (VMEM+VPP) throttles
/// @param[out] o_exceeded_power vector of MCA targets where the estimated power exceeded the maximum allowed
/// @return FAPI2_RC_SUCCESS iff ok
/// @note sets the throttles and power to the worst case
/// Called by p9_mss_bulk_pwr_throttles and by p9_mss_utils_to_throttle (so by IPL or by OCC)
///
template<mss::mc_type MC = DEFAULT_MC_TYPE, fapi2::TargetType T, typename TT = throttle_traits<MC>>
fapi2::ReturnCode equalize_throttles (const std::vector< fapi2::Target<T> >& i_targets,
                                      const throttle_type i_throttle_type,
                                      std::vector< fapi2::Target<TT::PORT_TARGET_TYPE> >& o_exceeded_power)

{
    // Check if target list is empty
    if (i_targets.empty())
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Save off failing MC for traces
    auto l_current_mc = i_targets[0];

    o_exceeded_power.clear();

    //Set to max values so every compare will change to min value
    uint16_t l_min_slot = ~(0);
    uint16_t l_min_port = ~(0);

    //Loop through all of the MC targets to find the worst case throttle value (lowest) for the slot and port
    for (const auto& l_mc : i_targets)
    {
        l_current_mc = l_mc;

        for (const auto& l_port : mss::find_targets<TT::PORT_TARGET_TYPE>(l_mc))
        {
            uint16_t l_calc_slot = 0;
            uint16_t l_calc_port = 0;
            uint16_t l_run_slot = 0;
            uint16_t l_run_port = 0;

            if (mss::count_dimm(l_port) == 0)
            {
                FAPI_INF("Seeing no DIMMs on %s -- skipping", mss::c_str(l_port));
                continue;
            }

            FAPI_TRY(mss::attr::get_mem_throttled_n_commands_per_slot(l_port, l_calc_slot));
            FAPI_TRY(mss::attr::get_mem_throttled_n_commands_per_port(l_port, l_calc_port));
            FAPI_TRY(mss::attr::get_runtime_mem_throttled_n_commands_per_slot(l_port, l_run_slot));
            FAPI_TRY(mss::attr::get_runtime_mem_throttled_n_commands_per_port(l_port, l_run_port));

            //Find the smaller of the three values (calculated slot, runtime slot, and min slot)
            l_min_slot = (l_calc_slot != 0) ? std::min( std::min (l_calc_slot, l_run_slot),
                         l_min_slot) : l_min_slot;
            l_min_port = (l_calc_port != 0) ? std::min( std::min( l_calc_port, l_run_port),
                         l_min_port) : l_min_port;
        }
    }

    FAPI_INF("Calculated min slot is %d, min port is %d for the system", l_min_slot, l_min_port);

    //Now set every port to have those values
    {
        for (const auto& l_mc : i_targets)
        {
            l_current_mc = l_mc;

            for (const auto& l_port : mss::find_targets<TT::PORT_TARGET_TYPE>(l_mc))
            {
                uint16_t l_fin_slot = 0;
                uint16_t l_fin_port  = 0;
                uint32_t l_fin_power  = 0;;

                if (mss::count_dimm(l_port) == 0)
                {
                    FAPI_INF("Seeing no DIMMs on %s -- skipping", mss::c_str(l_port));
                    continue;
                }

                // Declaring above to avoid fapi2 jump
                uint64_t l_power_limit = 0;

                l_fin_slot = l_min_slot;
                l_fin_port = l_min_port;

                //Need to create throttle object for each port in order to get dimm configuration and power curves
                //To calculate the slot/port utilization and total port power consumption
                fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

                const auto l_dummy = mss::power_thermal::throttle<MC>(l_port, l_rc);
                FAPI_TRY(l_rc, "Failed creating a throttle object in equalize_throttles for %s", mss::c_str(l_port));

                FAPI_TRY( l_dummy.calc_power_from_n(l_fin_slot, l_fin_port, l_fin_power),
                          "Failed calculating the power value for throttles: slot %d, port %d for target %s",
                          l_fin_slot,
                          l_fin_port,
                          mss::c_str(l_port));

                // You may ask why this is not a variable within the throttle struct
                // It's because POWER throttling is on a per port basis while the THERMAL throttle is per dimm
                // Didn't feel like adding a variable just for this check
                l_power_limit = (i_throttle_type == throttle_type::POWER) ?
                                l_dummy.iv_port_power_limit : (l_dummy.iv_dimm_thermal_limit[0] + l_dummy.iv_dimm_thermal_limit[1]);

                FAPI_INF("%s Calculated power is %d, limit is %ld", mss::c_str(l_port), l_fin_power, l_power_limit);

                //If there's an error with calculating port power, the wrong watt target was passed in
                //Returns an error but doesn't deconfigure anything. Calling function can log if it wants to
                //Called by OCC and by p9_mss_eff_config_thermal, thus different ways for error handling
                //Continue setting throttles to prevent a possible throttle == 0
                //The error will be the last bad port found
                if (l_fin_power > l_power_limit)
                {
                    //Need this because of pos traits and templating stuff
                    uint64_t l_fail = mss::fapi_pos(l_port);

                    //Set the failing port. OCC just needs one failing port, doesn't need all of them
                    FAPI_TRY( mss::attr::set_port_pos_of_fail_throttle(l_fail) );

                    FAPI_ASSERT_NOEXIT( false,
                                        fapi2::MSS_CALC_PORT_POWER_EXCEEDS_MAX()
                                        .set_CALCULATED_PORT_POWER(l_fin_power)
                                        .set_MAX_POWER_ALLOWED(l_power_limit)
                                        .set_PORT_POS(mss::pos(l_port))
                                        .set_PORT_TARGET(l_port),
                                        "Error calculating the final port power value for target %s, calculated power is %d, max value can be %d",
                                        mss::c_str(l_port),
                                        l_fin_power,
                                        l_power_limit);

                    o_exceeded_power.push_back(l_port);
                }

                FAPI_INF("%s Final throttles values for slot %d, for port %d, power value %d",
                         mss::c_str(l_port),
                         l_fin_slot,
                         l_fin_port,
                         l_fin_power);

                //Even if there's an error, still calculate and set the throttles.
                //OCC will set to safemode if there's an error
                //Better to set the throttles than leave them 0, and potentially brick the memory
                FAPI_TRY( mss::attr::set_mem_throttled_n_commands_per_port( l_port, l_fin_port) );
                FAPI_TRY( mss::attr::set_mem_throttled_n_commands_per_slot( l_port, l_fin_slot) );
                FAPI_TRY( mss::attr::set_port_maxpower( l_port, l_fin_power) );
            }
        }
    }
    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    FAPI_ERR("Error equalizing memory throttles on %s", mss::c_str(l_current_mc));
    return fapi2::current_err;
}

///
/// @brief Write the runtime memory throttle settings from attributes to scom registers
/// @tparam MC mss::mc_type
/// @tparam T the fapi2 target type of the target
/// @tparam TT throttle traits for the given MC target type
/// @param[in] i_target the port target
/// @return fapi2::FAPI2_RC_SUCCESS iff ok
/// @note overwriting the safemode throttle values
///
template<mss::mc_type MC = DEFAULT_MC_TYPE, fapi2::TargetType T, typename TT = throttle_traits<MC>>
fapi2::ReturnCode write_runtime_throttles(const fapi2::Target<T>& i_target)
{
    FAPI_INF("%s Start write_runtime_throttles", mss::c_str(i_target));

    uint16_t l_runtime_port = 0;
    uint16_t l_runtime_slot = 0;

    fapi2::buffer<uint64_t> l_data;
    FAPI_TRY(fapi2::getScom(i_target, TT::FARB3Q_REG, l_data));

    FAPI_TRY( mss::attr::get_runtime_mem_throttled_n_commands_per_port(i_target, l_runtime_port));
    FAPI_TRY( mss::attr::get_runtime_mem_throttled_n_commands_per_slot(i_target, l_runtime_slot));

    l_data.insertFromRight<TT::RUNTIME_N_SLOT, TT::RUNTIME_N_SLOT_LEN>(l_runtime_slot);
    l_data.insertFromRight<TT::RUNTIME_N_PORT, TT::RUNTIME_N_PORT_LEN>(l_runtime_port);

    FAPI_TRY( fapi2::putScom(i_target, TT::FARB3Q_REG, l_data) );

    FAPI_INF("%s End write_runtime_throttles", mss::c_str(i_target));
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    FAPI_ERR("%s Couldn't finish write_runtime_throttles", mss::c_str(i_target));
    return fapi2::current_err;
}

///
/// @brief set the PWR CNTRL register
/// @tparam MC mss::mc_type
/// @tparam T the fapi2 target type of the target
/// @tparam TT throttle traits for the given MC target type
/// @param[in] i_target the port target
/// @return fapi2::FAPI2_RC_SUCCESS if ok
///
template<mss::mc_type MC, fapi2::TargetType T, typename TT = throttle_traits<MC>>
fapi2::ReturnCode set_pwr_cntrl_reg(const fapi2::Target<T>& i_target)
{
    fapi2::ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_Type l_pwr_cntrl = 0;
    fapi2::buffer<uint64_t> l_data;

    FAPI_TRY(mss::attr::get_mrw_power_control_requested(l_pwr_cntrl));
    FAPI_TRY(fapi2::getScom(i_target, TT::MBARPC0Q_REG, l_data));

    l_data.insertFromRight<TT::CFG_MIN_MAX_DOMAINS, TT::CFG_MIN_MAX_DOMAINS_LEN>(TT::MAXALL_MINALL);

    // Write data if PWR_CNTRL_REQUESTED includes power down
    switch (l_pwr_cntrl)
    {
        case fapi2::ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_POWER_DOWN:
            l_data.clearBit<TT::CFG_LP_CTRL_ENABLE>();
            l_data.clearBit<TT::CFG_LP_DATA_ENABLE>();
            l_data.setBit<TT::CFG_MIN_DOMAIN_REDUCTION_ENABLE>();
            break;

        case fapi2::ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_PD_AND_STR:
        case fapi2::ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_PD_AND_STR_CLK_STOP:
            l_data.setBit<TT::CFG_LP_CTRL_ENABLE>();
            l_data.setBit<TT::CFG_LP_DATA_ENABLE>();
            l_data.setBit<TT::CFG_MIN_DOMAIN_REDUCTION_ENABLE>();
            break;

        case fapi2::ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_OFF:
            l_data.clearBit<TT::CFG_LP_CTRL_ENABLE>();
            l_data.clearBit<TT::CFG_LP_DATA_ENABLE>();
            l_data.clearBit<TT::CFG_MIN_DOMAIN_REDUCTION_ENABLE>();
            break;

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_UNSUPPORTED_MRW_POWER_CONTROL_REQUESTED()
                         .set_PORT_TARGET(i_target)
                         .set_FUNCTION(mss::SET_PWR_CNTRL_REG)
                         .set_VALUE(l_pwr_cntrl),
                         "%s ATTR_MSS_MRW_POWER_CONTROL_REQUESTED not set correctly in MRW: %u",
                         mss::c_str(i_target),
                         l_pwr_cntrl);
            break;
    }

    //Set the MIN_DOMAIN_REDUCTION time
    l_data.insertFromRight<TT::CFG_MIN_DOMAIN_REDUCTION_TIME, TT::CFG_MIN_DOMAIN_REDUCTION_TIME_LEN>
    (TT::MIN_DOMAIN_REDUCTION_TIME);

    FAPI_TRY(fapi2::putScom(i_target, TT::MBARPC0Q_REG, l_data));

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    FAPI_ERR("%s Error setting power control register MBARPC0Q", mss::c_str(i_target));
    return fapi2::current_err;
}

///
/// @brief set the STR register
/// @tparam MC mss::mc_type
/// @tparam T the fapi2 target type of the target
/// @tparam TT throttle traits for the given MC target type
/// @param[in] i_target the port target
/// @return fapi2::FAPI2_RC_SUCCESS if ok
///
template<mss::mc_type MC, fapi2::TargetType T, typename TT = throttle_traits<MC>>
fapi2::ReturnCode set_str_reg(const fapi2::Target<T>& i_target)
{
    fapi2::ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_Type l_str_enable = 0;
    fapi2::buffer<uint64_t> l_data;

    FAPI_TRY(mss::attr::get_mrw_power_control_requested(l_str_enable));
    FAPI_TRY(fapi2::getScom(i_target, TT::STR0Q_REG, l_data));

    //Write bit if STR should be enabled
    switch (l_str_enable)
    {
        case fapi2::ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_PD_AND_STR:
            l_data.setBit<TT::CFG_STR_ENABLE>();
            l_data.clearBit<TT::CFG_DIS_CLK_IN_STR>();
            break;

        case fapi2::ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_PD_AND_STR_CLK_STOP:
            l_data.setBit<TT::CFG_STR_ENABLE>();
            l_data.setBit<TT::CFG_DIS_CLK_IN_STR>();
            break;

        case fapi2::ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_POWER_DOWN:
        case fapi2::ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_OFF:
            l_data.clearBit<TT::CFG_STR_ENABLE>();
            l_data.clearBit<TT::CFG_DIS_CLK_IN_STR>();
            break;

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_UNSUPPORTED_MRW_POWER_CONTROL_REQUESTED()
                         .set_PORT_TARGET(i_target)
                         .set_FUNCTION(mss::SET_STR_REG)
                         .set_VALUE(l_str_enable),
                         "%s ATTR_MSS_MRW_POWER_CONTROL_REQUESTED not set correctly in MRW: %u",
                         mss::c_str(i_target),
                         l_str_enable);
            break;
    }

    l_data.insertFromRight<TT::CFG_ENTER_STR_TIME, TT::CFG_ENTER_STR_TIME_LEN>(TT::ENTER_STR_TIME);

    FAPI_TRY(fapi2::putScom(i_target, TT::STR0Q_REG, l_data));

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    FAPI_ERR("%s Error setting the STR register MBASTR0Q", mss::c_str(i_target));
    return fapi2::current_err;
}

///
/// @brief set the general N/M throttle register
/// @tparam MC mss::mc_type
/// @tparam T the fapi2 target type of the target
/// @tparam TT throttle traits for the given MC target type
/// @param[in] i_target the port target
/// @return fapi2::FAPI2_RC_SUCCESS if ok
///
template<mss::mc_type MC = DEFAULT_MC_TYPE, fapi2::TargetType T, typename TT = throttle_traits<MC>>
fapi2::ReturnCode set_nm_support(const fapi2::Target<T>& i_target)
{
    uint16_t l_run_slot = 0;
    uint16_t l_run_port = 0;
    fapi2::ATTR_MSS_MRW_MEM_M_DRAM_CLOCKS_Type l_throttle_denominator = 0;

    fapi2::buffer<uint64_t> l_data;

    FAPI_TRY(mss::attr::get_mrw_mem_m_dram_clocks(l_throttle_denominator));

    FAPI_TRY(fapi2::getScom(i_target, TT::FARB3Q_REG, l_data));

    // runtime should be calculated in eff_config_thermal, which is called before scominit in ipl
    FAPI_TRY(mss::attr::get_runtime_mem_throttled_n_commands_per_port(i_target, l_run_port));
    FAPI_TRY(mss::attr::get_runtime_mem_throttled_n_commands_per_slot(i_target, l_run_slot));
    FAPI_INF("For target %s throttled n commands per port are %d, per slot are %d, and dram m clocks are %d",
             mss::c_str(i_target),
             l_run_port,
             l_run_slot,
             l_throttle_denominator);

    l_data.insertFromRight<TT::RUNTIME_N_SLOT, TT::RUNTIME_N_SLOT_LEN>(l_run_slot);
    l_data.insertFromRight<TT::RUNTIME_N_PORT, TT::RUNTIME_N_PORT_LEN>(l_run_port);
    l_data.insertFromRight<TT::RUNTIME_M, TT::RUNTIME_M_LEN>(l_throttle_denominator);
    l_data.insertFromRight<TT::CFG_RAS_WEIGHT, TT::CFG_RAS_WEIGHT_LEN>(TT::NM_RAS_WEIGHT);
    l_data.insertFromRight<TT::CFG_CAS_WEIGHT, TT::CFG_CAS_WEIGHT_LEN>(TT::NM_CAS_WEIGHT);

    // If set, changes to cfg_nm_n_per_slot, cfg_nm_n_per_port, cfg_nm_m, min_max_domains
    // will only be applied after a pc_sync command is seen
    // Set differently for different MC types because of hardware differences (see portTraits<MC> for details)
    l_data.writeBit<TT::CFG_NM_CHANGE_AFTER_SYNC>(TT::CFG_NM_CHANGE_AFTER_SYNC_VALUE);

    FAPI_TRY(fapi2::putScom(i_target, TT::FARB3Q_REG, l_data));

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    FAPI_ERR("%s Error setting nm throttles", mss::c_str(i_target));
    return fapi2::current_err;
}

///
/// @brief set the safemode throttle register
/// @tparam MC mss::mc_type
/// @tparam T the fapi2 target type of the target
/// @tparam TT throttle traits for the given MC target type
/// @param[in] i_target the port target
/// @return fapi2::FAPI2_RC_SUCCESS if ok
/// @note sets FARB4Q
/// @note used to set throttle window (N throttles  / M clocks)
///
template<mss::mc_type MC = DEFAULT_MC_TYPE, fapi2::TargetType T, typename TT = throttle_traits<MC>>
fapi2::ReturnCode set_safemode_throttles(const fapi2::Target<T>& i_target)
{
    fapi2::buffer<uint64_t> l_data;
    fapi2::ATTR_MSS_MRW_SAFEMODE_MEM_THROTTLED_N_COMMANDS_PER_PORT_Type l_throttle_per_port = 0;
    fapi2::ATTR_MSS_MRW_MEM_M_DRAM_CLOCKS_Type l_throttle_denominator = 0;

    FAPI_TRY(mss::attr::get_mrw_mem_m_dram_clocks(l_throttle_denominator));
    FAPI_TRY(mss::attr::get_mrw_safemode_mem_throttled_n_commands_per_port(l_throttle_per_port));

    FAPI_TRY(fapi2::getScom(i_target, TT::FARB4Q_REG, l_data));

    l_data.insertFromRight<TT::EMERGENCY_M, TT::EMERGENCY_M_LEN>(l_throttle_denominator);
    l_data.insertFromRight<TT::EMERGENCY_N, TT::EMERGENCY_N_LEN>(l_throttle_per_port);

    FAPI_TRY(fapi2::putScom(i_target, TT::FARB4Q_REG, l_data));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    FAPI_ERR("%s Error setting safemode throttles", mss::c_str(i_target));
    return fapi2::current_err;
}

///
/// @brief safemode throttle values defined from MRW attributes
/// @tparam MC mss::mc_type
/// @tparam T the fapi2 target type of the target
/// @param[in] i_target the port target
/// @return fapi2::FAPI2_RC_SUCCESS if ok
/// @note sets safemode values for emergency mode and regular throttling
///
template<mss::mc_type MC = DEFAULT_MC_TYPE, fapi2::TargetType T>
fapi2::ReturnCode thermal_throttle_scominit(const fapi2::Target<T>& i_target)
{
    FAPI_TRY(set_pwr_cntrl_reg<MC>(i_target));
    FAPI_TRY(set_str_reg<MC>(i_target));
    FAPI_TRY(set_nm_support<MC>(i_target));
    FAPI_TRY(set_safemode_throttles<MC>(i_target));

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    FAPI_ERR("%s Error setting scominits for power_thermal values", mss::c_str(i_target));
    return fapi2::current_err;
}

} //ns power_thermal
}// mss

#endif
