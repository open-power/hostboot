/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/power_thermal/ody_throttle.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2024                        */
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
// EKB-Mirror-To: hostboot

///
/// @file ody_throttle.C
/// @brief Determine throttle settings for memory
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include <lib/shared/ody_consts.H>
#include <lib/mc/ody_port_traits.H>
#include <lib/power_thermal/ody_throttle.H>
#include <lib/power_thermal/ody_throttle_traits.H>
#include <generic/memory/lib/utils/mss_generic_check.H>
#include <generic/memory/lib/utils/num.H>
#include <generic/memory/lib/utils/pos.H>
#include <lib/mc/ody_port_traits.H>
#include <mss_generic_system_attribute_getters.H>
#include <mss_generic_attribute_setters.H>
#include <mss_generic_attribute_getters.H>

namespace mss
{
namespace power_thermal
{
// Max achievable utilization value based on frequency per port
// and number of ports on the dimm in c% units
const uint32_t throttle_traits<mss::mc_type::ODYSSEY>::PORT_UTIL_MAP_3200[mss::ody::sizes::MAX_PORT_PER_OCMB] = {8000, 6800};
const uint32_t throttle_traits<mss::mc_type::ODYSSEY>::PORT_UTIL_MAP_4000[mss::ody::sizes::MAX_PORT_PER_OCMB] = {7600, 6400};
const uint32_t throttle_traits<mss::mc_type::ODYSSEY>::PORT_UTIL_MAP_4800[mss::ody::sizes::MAX_PORT_PER_OCMB] = {7100, 5500};


#ifndef __PPE__
///
/// @brief Determine the optimized ocmb level throttle values
/// @param[in]  i_target the MC target
/// @param[in]  i_throttle_type thermal boolean to determine whether to calculate throttles based on the power regulator or thermal limits
/// @param[in]  i_ocmb_port_count  number of ocmb ports configured
/// @param[in]  i_port_min_slot    minimum port level slot throttle
/// @param[out] o_ocmb_slot        ocmb level slot throttle to use (optimized or not)
/// @param[out] o_ocmb_port        ocmb level port throttle to use (optimized or not)
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode get_optimized_ocmb_throttles(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const mss::throttle_type i_throttle_type,
        const uint8_t i_ocmb_port_count,
        const uint16_t i_port_min_slot,
        uint16_t& o_ocmb_slot,
        uint16_t& o_ocmb_port)
{
    bool l_throttle_optimize = false;
    uint16_t l_runtime_ocmb_port = 0;
    uint16_t l_runtime_ocmb_slot = 0;
    constexpr uint32_t ONE_HUNDRED_CENTI_PERCENT = 10000;

    // get ocmb level runtime throttles to help with calculations and limits
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_ODY_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_SLOT, i_target, l_runtime_ocmb_slot));
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_ODY_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_PORT, i_target, l_runtime_ocmb_port));

    // determine if ocmb level throttles can be optimized when there is more than one port
    // this is done to preserve any thermal throttles which are not optimized
    if (i_ocmb_port_count > 1)
    {
        if (i_throttle_type == mss::throttle_type::POWER)
        {
            // power throttling:  ocmb runtime throttles are at initialized values of zero
            //   will be used when restore_runtime_throttles is run in eff_config_thermal
            if ((l_runtime_ocmb_slot == 0) || (l_runtime_ocmb_port == 0))
            {
                l_throttle_optimize = true;
            }

            // power throttling:  ocmb runtime slot = ocmb runtime port and non-zero (previously optimized)
            // power throttling:  ocmb runtime slot < ocmb runtime port (optimize power throttles up to thermal throttle values)
            if ((l_runtime_ocmb_slot <= l_runtime_ocmb_port) && (l_runtime_ocmb_slot > 0))
            {
                l_throttle_optimize = true;
            }
        }

        if (i_throttle_type == mss::throttle_type::THERMAL)
        {
            uint32_t l_throttle_denominator = 0;
            uint32_t l_unthrottled_n_per_port = 0;

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_MEM_M_DRAM_CLOCKS, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                                   l_throttle_denominator));

            // get N throttle value for 100% utilization (unthrottled)
            l_unthrottled_n_per_port = calc_n_from_dram_util(ONE_HUNDRED_CENTI_PERCENT, l_throttle_denominator);

            // thermal throttling:  the only time optimization for thermal throttling can be done would be
            //   immediately after runtime throttles were initially setup based on MRW max util attribute
            //   as long as we know that memory can be unthrottled at 100% utilization (no thermal throttles needed)
            //   for this reason do thermal throttling first followed by power throttling in eff_config_thermal
            if (i_port_min_slot == l_unthrottled_n_per_port)
            {
                l_throttle_optimize = true;
            }
        }
    }

    // calulate new ocmb throttles, optimizing slot, port is slot times number of ports
    o_ocmb_slot = (l_throttle_optimize) ? i_port_min_slot * i_ocmb_port_count : i_port_min_slot;
    o_ocmb_port = i_port_min_slot * i_ocmb_port_count;

    // limit optimized throttle values to runtime throttle values
    o_ocmb_slot = ((o_ocmb_slot > l_runtime_ocmb_slot) && (l_runtime_ocmb_slot > 0)) ? l_runtime_ocmb_slot : o_ocmb_slot;
    o_ocmb_port = ((o_ocmb_port > l_runtime_ocmb_port) && (l_runtime_ocmb_port > 0)) ? l_runtime_ocmb_port : o_ocmb_port;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Combine the runtime throttle values for the port targets and set the final OCMB values
/// @param[in] i_target the MC target
/// @param[in] i_throttle_type thermal boolean to determine whether to calculate throttles based on the power regulator or thermal limits
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
///
fapi2::ReturnCode combine_runtime_port_throttles( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const mss::throttle_type i_throttle_type)
{
    using TT = throttle_traits<mss::mc_type::ODYSSEY>;

    if (mss::count_dimm (i_target) == 0)
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    uint16_t l_ocmb_slot = 0;
    uint16_t l_ocmb_port = 0;

    // Combine the MEM_PORT values to set the OCMB ones:
    // Set the ocmb target Nslot to the minimum Nslot value from both port targets
    // Set the ocmb target Nport to the ocmb target Nslot value multipled by the number of configured ports
    const auto l_port_count = mss::count_mem_port(i_target);
    uint16_t l_min_slot = ~(0);

    for (const auto& l_port : mss::find_targets<TT::PORT_TARGET_TYPE>(i_target))
    {
        // Pick up the N slot from the attribute just in case it's overridden from what we calculated
        uint16_t l_slot = 0;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_EXP_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_SLOT, l_port, l_slot));
        l_min_slot = std::min(l_slot, l_min_slot);
    }

    FAPI_TRY(get_optimized_ocmb_throttles(i_target, i_throttle_type, l_port_count, l_min_slot, l_ocmb_slot, l_ocmb_port));

    FAPI_INF_NO_SBE("For OCMB target " GENTARGTIDFORMAT " throttle per slot is %d, throttle per port is %d",
                    GENTARGTID(i_target), l_ocmb_slot, l_ocmb_port);

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_ODY_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_SLOT, i_target, l_ocmb_slot));
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_ODY_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_PORT, i_target, l_ocmb_port));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Perform thermal calculations as part of the effective configuration - Odyssey specialization
/// @param[in] i_target the MC target in which the runtime throttles will be reset
/// @param[in] i_throttle_type thermal boolean to determine whether to calculate throttles based on the power regulator or thermal limits
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode restore_runtime_throttles<mss::mc_type::ODYSSEY>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target,
        const mss::throttle_type i_throttle_type)
{
    using TT = throttle_traits<mss::mc_type::ODYSSEY>;

    uint32_t l_max_databus = 0;
    uint32_t l_throttle_m_clocks = 0;

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_MEM_M_DRAM_CLOCKS, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                            l_throttle_m_clocks) );
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_DDR5_MAX_DRAM_DATABUS_UTIL, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                            l_max_databus) );

    //Set runtime throttles to unthrottled value, using max dram utilization and M throttle
    for (const auto& l_port : mss::find_targets<TT::PORT_TARGET_TYPE>(i_target))
    {
        uint16_t l_run_throttle = 0;

        if (mss::count_dimm (i_target) != 0)
        {
            l_run_throttle = mss::power_thermal::throttled_cmds(l_max_databus, l_throttle_m_clocks);
        }

        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EXP_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_PORT, l_port, l_run_throttle) );
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EXP_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_SLOT, l_port, l_run_throttle) );
    }

    FAPI_TRY(combine_runtime_port_throttles(i_target, i_throttle_type));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Update the runtime throttles to the worst case of the general throttle values and the runtime values - Odyssey specialization
/// @param[in] i_target the MC target in which the runtime throttles will be set
/// @param[in] i_throttle_type thermal boolean to determine whether to calculate throttles based on the power regulator or thermal limits
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode update_runtime_throttle<mss::mc_type::ODYSSEY>(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target,
        const mss::throttle_type i_throttle_type)
{
    using TT = throttle_traits<mss::mc_type::ODYSSEY>;

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

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_EXP_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_SLOT, l_port, l_run_slot));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_EXP_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_PORT, l_port, l_run_port));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_EXP_MEM_THROTTLED_N_COMMANDS_PER_SLOT, l_port, l_calc_slot));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_EXP_MEM_THROTTLED_N_COMMANDS_PER_PORT, l_port, l_calc_port));

        //Choose the worst case between runtime and calculated throttles
        //Have to make sure the calc_slot isn't equal to 0 though
        l_run_slot = (l_calc_slot != 0) ?
                     std::min(l_run_slot, l_calc_slot) : l_run_slot;
        l_run_port = (l_calc_port != 0) ?
                     std::min(l_run_port, l_calc_port) : l_run_port;

        FAPI_INF_NO_SBE("New runtime throttles for " GENTARGTIDFORMAT " for slot are %d, port are %d",
                        GENTARGTID(l_port),
                        l_run_slot,
                        l_run_port);

        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EXP_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_PORT, l_port, l_run_port) );
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EXP_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_SLOT, l_port, l_run_slot) );
    }

    FAPI_TRY(combine_runtime_port_throttles(i_target, i_throttle_type));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Updates the max databus utilization based upon the DIMM type - ODYSSEY specialization
/// @param[in] i_target the target on which to operate
/// @param[in,out] io_max_util the utilization of the dimm at maximum possible percentage (mrw or calculated)
/// @return fapi2::FAPI2_RC_SUCCESS iff the method was a success
///
template<>
fapi2::ReturnCode update_max_util_by_dimm_type<mss::mc_type::ODYSSEY>(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
    double& io_max_util)
{
    // Nothing to do for Odyssey since it doesn't support MDS
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Updates the database port max utilization based upon the DIMM type - ODYSSEY/MEM_PORT specialization
/// @param[in] i_target the target on which to operate
/// @param[in] i_database_port_max the maximum utilization to use depending upon the DIMM type
/// @param[in,out] io_util the utilization of the dimm at maximum possible percentage (mrw or calculated)
/// @return fapi2::FAPI2_RC_SUCCESS iff the method was a success
///
template<>
fapi2::ReturnCode update_databus_port_max_util_by_dimm_type<mss::mc_type::ODYSSEY>(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
    const double i_databus_port_max,
    double& io_util)
{
    // Nothing to do for Odyssey since it doesn't support MDS
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Write the runtime memory throttle settings from attributes to scom registers - Odyssey specialization
/// @param[in] i_target the MC target
/// @return fapi2::FAPI2_RC_SUCCESS iff ok
/// @note overwriting the safemode throttle values
///
template<>
fapi2::ReturnCode write_runtime_throttles<mss::mc_type::ODYSSEY>(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target)
{
    using TT = throttle_traits<mss::mc_type::ODYSSEY>;

    FAPI_INF_NO_SBE(GENTARGTIDFORMAT " Start write_runtime_throttles", GENTARGTID(i_target));

    uint16_t l_runtime_port = 0;
    uint16_t l_runtime_slot = 0;

    fapi2::buffer<uint64_t> l_data;
    FAPI_TRY(fapi2::getScom(i_target, TT::FARB3Q_REG, l_data));

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_ODY_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_PORT, i_target, l_runtime_port));
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_ODY_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_SLOT, i_target, l_runtime_slot));

    l_data.insertFromRight<TT::RUNTIME_N_SLOT, TT::RUNTIME_N_SLOT_LEN>(l_runtime_slot);
    l_data.insertFromRight<TT::RUNTIME_N_PORT, TT::RUNTIME_N_PORT_LEN>(l_runtime_port);

    FAPI_TRY( fapi2::putScom(i_target, TT::FARB3Q_REG, l_data) );

    FAPI_INF_NO_SBE(GENTARGTIDFORMAT " End write_runtime_throttles", GENTARGTID(i_target));
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    FAPI_ERR(GENTARGTIDFORMAT " Couldn't finish write_runtime_throttles", GENTARGTID(i_target));
    return fapi2::current_err;
}

///
/// @brief Combine the throttle values for the port targets and set the final OCMB values
/// @param[in] i_target the MC target
/// @param[in] i_throttle_type thermal boolean to determine whether to calculate throttles based on the power regulator or thermal limits
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
/// Enums are POWER for power egulator throttles and THERMAL for thermal throttles
///
fapi2::ReturnCode combine_port_throttles( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const mss::throttle_type i_throttle_type)
{
    using TT = throttle_traits<mss::mc_type::ODYSSEY>;

    if (mss::count_dimm(i_target) == 0)
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    uint16_t l_ocmb_slot = 0;
    uint16_t l_ocmb_port = 0;

    // Combine the MEM_PORT values to set the OCMB ones:
    // Set the ocmb target Nslot to the minimum Nslot value from both port targets
    // Set the ocmb target Nport to the number of ports configured times the ocmb target Nslot value
    // For power throttling (not thermal throttling) set the Nslot to Nport to maximize performance
    const auto l_port_count = mss::count_mem_port(i_target);
    uint16_t l_min_slot = ~(0);

    for (const auto& l_port : mss::find_targets<TT::PORT_TARGET_TYPE>(i_target))
    {
        // Pick up the N slot from the attribute just in case it's overridden from what we calculated
        uint16_t l_slot = 0;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_EXP_MEM_THROTTLED_N_COMMANDS_PER_SLOT, l_port, l_slot));
        l_min_slot = std::min(l_slot, l_min_slot);
    }

    FAPI_TRY(get_optimized_ocmb_throttles(i_target, i_throttle_type, l_port_count, l_min_slot, l_ocmb_slot, l_ocmb_port));

    FAPI_INF_NO_SBE("For OCMB target " GENTARGTIDFORMAT " throttle per slot is %d, throttle per port is %d",
                    GENTARGTID(i_target), l_ocmb_slot, l_ocmb_port);

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_ODY_MEM_THROTTLED_N_COMMANDS_PER_SLOT, i_target, l_ocmb_slot));
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_ODY_MEM_THROTTLED_N_COMMANDS_PER_PORT, i_target, l_ocmb_port));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Calcuate the throttle values based on throttle type - Odyssey specialization
/// @param[in] i_target the MC target
/// @param[in] i_throttle_type thermal boolean to determine whether to calculate throttles based on the power regulator or thermal limits
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
/// @note determines the throttle levels based off of both ports' power curves,
/// sets the slot throttles to the same
/// Enums are POWER for power egulator throttles and THERMAL for thermal throttles
/// equalizes the throttles to the lowest of runtime and the lowest slot-throttle value
///
template<>
fapi2::ReturnCode pwr_throttles<mss::mc_type::ODYSSEY>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const mss::throttle_type i_throttle_type)
{
    using TT = throttle_traits<mss::mc_type::ODYSSEY>;

    if (mss::count_dimm (i_target) == 0)
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    // Odyssey has two "sides" which we refer to as MEM_PORTs but only one N/M throttle register,
    // so we need to calculate the throttles on each MEM_PORT then combine them for the OCMB
    for (const auto& l_port : mss::find_targets<TT::PORT_TARGET_TYPE>(i_target))
    {
        uint16_t l_n_slot = 0;
        uint16_t l_n_port  = 0;
        uint32_t l_power = 0;
        fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

        mss::power_thermal::throttle<mss::mc_type::ODYSSEY> l_pwr_struct(l_port, l_rc);
        FAPI_TRY(l_rc, "Error constructing mss:power_thermal::throttle object for target " GENTARGTIDFORMAT,
                 GENTARGTID(i_target));

        if ( i_throttle_type == mss::throttle_type::THERMAL)
        {
            FAPI_TRY(l_pwr_struct.thermal_throttles());
        }
        else
        {
            FAPI_TRY (l_pwr_struct.power_regulator_throttles());
        }

        l_n_slot = l_pwr_struct.iv_n_slot;
        l_n_port = l_pwr_struct.iv_n_port;
        l_power = l_pwr_struct.iv_calc_port_maxpower;

        FAPI_INF_NO_SBE("For target " GENTARGTIDFORMAT
                        " Calculated power is %d, throttle per slot is %d, throttle per port is %d",
                        GENTARGTID(l_port), l_power, l_n_slot, l_n_port);

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_EXP_PORT_MAXPOWER, l_port, l_power));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_EXP_MEM_THROTTLED_N_COMMANDS_PER_SLOT, l_port, l_n_slot));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_EXP_MEM_THROTTLED_N_COMMANDS_PER_PORT, l_port, l_n_port));
    }

    // Combine the MEM_PORT values to set the OCMB ones
    FAPI_TRY(combine_port_throttles(i_target, i_throttle_type));

    return fapi2::current_err;

fapi_try_exit:
    FAPI_ERR(GENTARGTIDFORMAT " Error calculating pwr_throttles using %s throttling",
             GENTARGTID(i_target),
             ((i_throttle_type == mss::throttle_type::POWER) ? "power" : "thermal"));
    return fapi2::current_err;
}

///
/// @brief Adjusts memory power according to max achievable
///          utilization based on DIMM freq and port count  - Odyssey specialization
/// @param[in] i_port_target mem port target that is being executed
/// @param[in,out] io_fin_power Final power that is calculated based on frequency and port
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode memory_power_adjustment<mss::mc_type::ODYSSEY>(const
        fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_port_target,
        uint32_t& io_fin_power)
{
    uint32_t l_throttle_denominator = 0;

    uint64_t l_dram_freq = 0;
    uint32_t l_max_util = 10000;
    uint32_t l_n_throttle_for_maxutil = 0;
    uint32_t l_max_achievable_pwr = 0;

    //Need to create throttle object for each MC in order to get dimm configuration and power curves
    //To calculate the slot/port utilization and total port power consumption
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

    const auto l_dummy = mss::power_thermal::throttle<mss::mc_type::ODYSSEY>(i_port_target, l_rc);

    // Get the port count
    const uint8_t l_port_count = mss::count_mem_port(mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_port_target));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_MEM_M_DRAM_CLOCKS, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           l_throttle_denominator));
    FAPI_TRY(l_rc, "Failed creating a throttle object in equalize_throttles for " GENTARGTIDFORMAT,
             GENTARGTID(i_port_target));

    // Get the DRAM frequency for the port
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_FREQ, i_port_target, l_dram_freq));

    // Get the max achievable utilization based on frequency and port
    if (l_dram_freq == 3200)
    {
        l_max_util = throttle_traits<mss::mc_type::ODYSSEY>::PORT_UTIL_MAP_3200[l_port_count - 1];
    }
    else if (l_dram_freq == 4000)
    {
        l_max_util = throttle_traits<mss::mc_type::ODYSSEY>::PORT_UTIL_MAP_4000[l_port_count - 1];
    }
    else if (l_dram_freq == 4800)
    {
        l_max_util = throttle_traits<mss::mc_type::ODYSSEY>::PORT_UTIL_MAP_4800[l_port_count - 1];
    }

    // Calculate out the throttle value using the utilization value
    l_n_throttle_for_maxutil = calc_n_from_dram_util(l_max_util, l_throttle_denominator);

    // Calculate the max achievable value from the above throttle value
    FAPI_TRY( l_dummy.calc_power_from_n(l_n_throttle_for_maxutil, l_n_throttle_for_maxutil, l_max_achievable_pwr),
              "Failed calculating the power value for throttles: slot %d, port %d, for target: " GENTARGTIDFORMAT,
              l_n_throttle_for_maxutil,
              l_n_throttle_for_maxutil,
              GENTARGTID(i_port_target));

    // Compare to the calculated power at the hardcoded util value
    // If the calculated power is less than what is in the attribute
    // then update the attribute with the calculated power value
    if( l_max_achievable_pwr < io_fin_power)
    {

        FAPI_INF_NO_SBE("Memory power adjustment was made because max achievable power: %d is less than final power: %d for target "
                        GENTARGTIDFORMAT,
                        l_max_achievable_pwr, io_fin_power, GENTARGTID(i_port_target));
    }
    else
    {
        FAPI_INF_NO_SBE("Memory power adjustment was not made because max achievable power: %d is greater than final power: %d for target "
                        GENTARGTIDFORMAT,
                        l_max_achievable_pwr, io_fin_power, GENTARGTID(i_port_target));
    }

    io_fin_power = std::min(io_fin_power, l_max_achievable_pwr);

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    FAPI_ERR("Error on memory power adjustment on " GENTARGTIDFORMAT, GENTARGTID(i_port_target));
    return fapi2::current_err;
}

///
/// @brief Equalize the throttles and estimated power at those throttle levels - Odyssey specialization
/// @param[in] i_targets vector of MC targets all on the same VDDR domain
/// @param[in] i_throttle_type denotes if this was done for POWER (VMEM) or THERMAL (VMEM+VPP) throttles
/// @param[out] o_exceeded_power vector of port targets where the estimated power exceeded the maximum allowed
/// @return FAPI2_RC_SUCCESS iff ok
/// @note sets the throttles and power to the worst case
/// Called by mss_bulk_pwr_throttles and by mss_utils_to_throttle (so by IPL or by OCC)
///
template<>
fapi2::ReturnCode equalize_throttles_helper<mss::mc_type::ODYSSEY>(const
        std::vector<fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>>& i_targets,
        const throttle_type i_throttle_type,
        std::vector<fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>>& o_exceeded_power)
{
    using TT = throttle_traits<mss::mc_type::ODYSSEY>;

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

            if (mss::count_dimm(l_mc) == 0)
            {
                FAPI_INF_NO_SBE("Seeing no DIMMs on " GENTARGTIDFORMAT " -- skipping", GENTARGTID(l_mc));
                continue;
            }

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_EXP_MEM_THROTTLED_N_COMMANDS_PER_SLOT, l_port, l_calc_slot));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_EXP_MEM_THROTTLED_N_COMMANDS_PER_PORT, l_port, l_calc_port));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_EXP_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_SLOT, l_port, l_run_slot));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_EXP_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_PORT, l_port, l_run_port));

            //Find the smaller of the three values (calculated slot, runtime slot, and min slot)
            l_min_slot = (l_calc_slot != 0) ? std::min( std::min (l_calc_slot, l_run_slot),
                         l_min_slot) : l_min_slot;
            l_min_port = (l_calc_port != 0) ? std::min( std::min( l_calc_port, l_run_port),
                         l_min_port) : l_min_port;
        }
    }

    FAPI_INF_NO_SBE("Calculated min slot is %d, min port is %d for the system", l_min_slot, l_min_port);

    //Now set every MC to have those values
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
                    FAPI_INF_NO_SBE("Seeing no DIMMs on " GENTARGTIDFORMAT " -- skipping", GENTARGTID(l_port));
                    continue;
                }

                // Declaring above to avoid fapi2 jump
                uint64_t l_power_limit = 0;

                l_fin_slot = l_min_slot;
                l_fin_port = l_min_port;

                //Need to create throttle object for each MC in order to get dimm configuration and power curves
                //To calculate the slot/port utilization and total port power consumption
                fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

                const auto l_dummy = mss::power_thermal::throttle<mss::mc_type::ODYSSEY>(l_port, l_rc);
                FAPI_TRY(l_rc, "Failed creating a throttle object in equalize_throttles for " GENTARGTIDFORMAT, GENTARGTID(l_port));

                FAPI_TRY( l_dummy.calc_power_from_n(l_fin_slot, l_fin_port, l_fin_power),
                          "Failed calculating the power value for throttles: slot %d, port %d for target %s",
                          l_fin_slot,
                          l_fin_port,
                          GENTARGTID(l_port));

                // You may ask why this is not a variable within the throttle struct
                // It's because POWER throttling is on a per port basis while the THERMAL throttle is per dimm
                // Didn't feel like adding a variable just for this check
                l_power_limit = (i_throttle_type == throttle_type::POWER) ?
                                l_dummy.iv_port_power_limit : (l_dummy.iv_dimm_thermal_limit[0] + l_dummy.iv_dimm_thermal_limit[1]);

                FAPI_INF_NO_SBE(GENTARGTIDFORMAT " Calculated power is %d, limit is %d", GENTARGTID(l_port), l_fin_power,
                                static_cast<uint32_t>(l_power_limit));

                //If there's an error with calculating port power, the wrong watt target was passed in
                //Returns an error but doesn't deconfigure anything. Calling function can log if it wants to
                //Called by OCC and by mss_eff_config_thermal, thus different ways for error handling
                //Continue setting throttles to prevent a possible throttle == 0
                //The error will be the last bad MC found
                if (l_fin_power > l_power_limit)
                {
                    //Need this because of pos traits and templating stuff
                    uint64_t l_fail = mss::fapi_pos(l_port);

                    //Set the failing port. OCC just needs one failing port, doesn't need all of them
                    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MEM_PORT_POS_OF_FAIL_THROTTLE, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                                            l_fail) );

                    //Note: any failing RC from this assert will be overwritten by the FAPI_TRYs below
                    //but that's ok since we're only using this for deconfigures in FFDC. The RC will be
                    //handled using the list of targets in o_exceeded_power in equalize_throttles
                    FAPI_ASSERT_NOEXIT( false,
                                        fapi2::MSS_CALC_PORT_POWER_EXCEEDS_MAX()
                                        .set_CALCULATED_PORT_POWER(l_fin_power)
                                        .set_MAX_POWER_ALLOWED(l_power_limit)
                                        .set_PORT_POS(mss::fapi_pos(l_port))
                                        .set_PORT_TARGET(l_port),
                                        "Error calculating the final port power value for target " GENTARGTIDFORMAT
                                        ", calculated power is %d, max value can be %d",
                                        GENTARGTID(l_port),
                                        l_fin_power,
                                        static_cast<uint32_t>(l_power_limit));

                    o_exceeded_power.push_back(l_port);
                }

                FAPI_INF_NO_SBE(GENTARGTIDFORMAT " Final throttle values for slot %d, for port %d, power value %d",
                                GENTARGTID(l_port),
                                l_fin_slot,
                                l_fin_port,
                                l_fin_power);

                //Even if there's an error, still calculate and set the throttles.
                //OCC will set to safemode if there's an error
                //Better to set the throttles than leave them 0, and potentially brick the memory
                FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_EXP_MEM_THROTTLED_N_COMMANDS_PER_PORT, l_port, l_fin_port));
                FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_EXP_MEM_THROTTLED_N_COMMANDS_PER_SLOT, l_port, l_fin_slot));
                FAPI_TRY(memory_power_adjustment<mss::mc_type::ODYSSEY>( l_port, l_fin_power));
                FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_EXP_PORT_MAXPOWER, l_port, l_fin_power));
            }

            // Combine the MEM_PORT values to set the OCMB ones
            FAPI_TRY(combine_port_throttles(l_mc, i_throttle_type));
        }
    }
    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    FAPI_ERR("Error equalizing memory throttles on " GENTARGTIDFORMAT, GENTARGTID(l_current_mc));
    return fapi2::current_err;
}

#endif //endif for __PPE__

///
/// @brief set the general N/M throttle register - Odyssey specialization
/// @param[in] i_target the port target
/// @return fapi2::FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode set_nm_support<mss::mc_type::ODYSSEY>(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    using TT = throttle_traits<mss::mc_type::ODYSSEY>;

    uint16_t l_run_slot = 0;
    uint16_t l_run_port = 0;
    fapi2::ATTR_MSS_MRW_MEM_M_DRAM_CLOCKS_Type l_throttle_denominator = 0;

    fapi2::buffer<uint64_t> l_data;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_MEM_M_DRAM_CLOCKS, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           l_throttle_denominator));

    FAPI_TRY(fapi2::getScom(i_target, TT::FARB3Q_REG, l_data));

    // runtime should be calculated in eff_config_thermal, which is called before scominit in ipl
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_PORT, i_target, l_run_port));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_SLOT, i_target, l_run_slot));
    FAPI_INF_NO_SBE("For target " GENTARGTIDFORMAT
                    " throttled n commands per port are %d, per slot are %d, and dram m clocks are %d",
                    GENTARGTID(i_target),
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
    l_data.writeBit<TT::CFG_NM_CHANGE_AFTER_SYNC>(TT::CFG_NM_CHANGE_AFTER_SYNC_VALUE);

    FAPI_TRY(fapi2::putScom(i_target, TT::FARB3Q_REG, l_data));

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    FAPI_ERR(GENTARGTIDFORMAT " Error setting nm throttles", GENTARGTID(i_target));
    return fapi2::current_err;
}

///
/// @brief set the safemode throttle register - Odyssey specialization
/// @param[in] i_target the port target
/// @return fapi2::FAPI2_RC_SUCCESS if ok
/// @note sets FARB4Q
/// @note used to set throttle window (N throttles  / M clocks)
///
template<>
fapi2::ReturnCode set_safemode_throttles<mss::mc_type::ODYSSEY>(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target)
{
    using TT = throttle_traits<mss::mc_type::ODYSSEY>;

    fapi2::buffer<uint64_t> l_data;
    fapi2::ATTR_MSS_MRW_MEM_M_DRAM_CLOCKS_Type l_throttle_denominator = 0;
    uint32_t l_throttle_per_port = 0;
    fapi2::ATTR_MSS_SAFEMODE_DRAM_DATABUS_UTIL_Type l_util_per_port = 0;
    const auto l_port_count = mss::count_mem_port(i_target);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_MEM_M_DRAM_CLOCKS, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           l_throttle_denominator));

    for (const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
    {
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_SAFEMODE_DRAM_DATABUS_UTIL, l_port, l_util_per_port));
        break;
    }

    FAPI_TRY(fapi2::getScom(i_target, TT::FARB4Q_REG, l_data));

    // l_util_per_port is in c%
    l_throttle_per_port = calc_n_from_dram_util(l_util_per_port, l_throttle_denominator);

    l_data.insertFromRight<TT::EMERGENCY_M, TT::EMERGENCY_M_LEN>(l_throttle_denominator);
    l_data.insertFromRight<TT::EMERGENCY_N, TT::EMERGENCY_N_LEN>(l_throttle_per_port * l_port_count);

    FAPI_TRY(fapi2::putScom(i_target, TT::FARB4Q_REG, l_data));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    FAPI_ERR(GENTARGTIDFORMAT " Error setting safemode throttles", GENTARGTID(i_target));
    return fapi2::current_err;
}

///
/// @brief safemode throttle values defined from MRW attributes - Odyssey specialization
/// @param[in] i_target the port target
/// @return fapi2::FAPI2_RC_SUCCESS if ok
/// @note sets safemode values for emergency mode and regular throttling
///       power controls are set up in draminit_mc
///
template<>
fapi2::ReturnCode thermal_throttle_scominit<mss::mc_type::ODYSSEY>(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target)
{
    FAPI_TRY(set_nm_support<mss::mc_type::ODYSSEY>(i_target));
    FAPI_TRY(set_safemode_throttles<mss::mc_type::ODYSSEY>(i_target));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    FAPI_ERR(TARGTIDFORMAT " Error setting scominits for power_thermal values", TARGTID);
    return fapi2::current_err;
}

}//namespace power_thermal
}//namespace mss
