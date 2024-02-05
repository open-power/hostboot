/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/power_thermal/exp_throttle.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2024                        */
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
/// @file exp_throttle.C
/// @brief Determine throttle settings for memory
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include <lib/shared/exp_consts.H>
#include <lib/power_thermal/exp_throttle.H>
#include <lib/power_thermal/exp_throttle_traits.H>
#include <generic/memory/lib/utils/pos.H>

namespace mss
{
namespace power_thermal
{

///
/// @brief Perform thermal calculations as part of the effective configuration - EXPLORER specialization
/// @param[in] i_target the OCMB_CHIP target in which the runtime throttles will be reset
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode restore_runtime_throttles<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target )
{
    using TT = throttle_traits<mss::mc_type::EXPLORER>;

    uint32_t l_max_databus = 0;
    uint32_t l_throttle_m_clocks = 0;

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_MEM_M_DRAM_CLOCKS, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                            l_throttle_m_clocks) );
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_MAX_DRAM_DATABUS_UTIL, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                            l_max_databus) );

    //Set runtime throttles to unthrottled value, using max dram utilization and M throttle
    for (const auto& l_port : mss::find_targets<TT::PORT_TARGET_TYPE>(i_target))
    {
        uint16_t l_run_throttle = 0;

        if (mss::count_dimm (l_port) != 0)
        {
            l_run_throttle = mss::power_thermal::throttled_cmds (l_max_databus, l_throttle_m_clocks);
        }

        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EXP_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_PORT,  l_port, l_run_throttle) );
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EXP_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_SLOT,  l_port, l_run_throttle) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Update the runtime throttles to the worst case of the general throttle values and the runtime values - EXPLORER specialization
/// @param[in] i_target the MC target in which the runtime throttles will be set
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode update_runtime_throttle<mss::mc_type::EXPLORER>(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target)
{
    using TT = throttle_traits<mss::mc_type::EXPLORER>;

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

        FAPI_INF("New runtime throttles for " TARGTIDFORMAT " for slot are %d, port are %d",
                 TARGTID,
                 l_run_slot,
                 l_run_port);

        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EXP_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_PORT, l_port, l_run_port) );
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EXP_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_SLOT, l_port, l_run_slot) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Updates the max databus utilization based upon the DIMM type - EXPLORER specialization
/// @param[in] i_target the target on which to operate
/// @param[in,out] io_max_util the utilization of the dimm at maximum possible percentage (mrw or calculated)
/// @return fapi2::FAPI2_RC_SUCCESS iff the method was a success
///
template<>
fapi2::ReturnCode update_max_util_by_dimm_type<mss::mc_type::EXPLORER>(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>&
        i_target,
        double& io_max_util)
{
    uint8_t l_is_mds = 0;
    FAPI_TRY(mss::attr::get_mds_ddimm(i_target, l_is_mds));

    // If this part is an MDS DIMM, then limit the power thermal calculations
    if(l_is_mds == fapi2::ENUM_ATTR_MEM_EFF_MDS_DDIMM_TRUE )
    {
        constexpr auto MDS_MAX_UTILIZATION = throttle_traits<mss::mc_type::EXPLORER>::MDS_MAX_UTILIZATION;
        io_max_util = std::min(io_max_util, MDS_MAX_UTILIZATION);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Updates the database port max utilization based upon the DIMM type - EXPLORER/MEM_PORT specialization
/// @param[in] i_target the target on which to operate
/// @param[in] i_database_port_max the maximum utilization to use depending upon the DIMM type
/// @param[in,out] io_util the utilization of the dimm at maximum possible percentage (mrw or calculated)
/// @return fapi2::FAPI2_RC_SUCCESS iff the method was a success
///
template<>
fapi2::ReturnCode update_databus_port_max_util_by_dimm_type<mss::mc_type::EXPLORER>(const
        fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
        const double i_databus_port_max,
        double& io_util)
{
    uint8_t l_is_mds[2] = {};
    FAPI_TRY(mss::attr::get_mds_ddimm(i_target, l_is_mds));

    // If this part is an MDS DIMM, then do not limit the utilization if above the MDS maximum defined utilization
    if(l_is_mds[0] == fapi2::ENUM_ATTR_MEM_EFF_MDS_DDIMM_TRUE)
    {
        constexpr auto MDS_MAX_UTILIZATION = throttle_traits<mss::mc_type::EXPLORER>::MDS_MAX_UTILIZATION;
        io_util = io_util > MDS_MAX_UTILIZATION ? i_databus_port_max : io_util;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write the runtime memory throttle settings from attributes to scom registers - Explorer specialization
/// @param[in] i_target the port target
/// @return fapi2::FAPI2_RC_SUCCESS iff ok
/// @note overwriting the safemode throttle values
///
template<>
fapi2::ReturnCode write_runtime_throttles<mss::mc_type::EXPLORER>(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>&
        i_target)
{
    using TT = throttle_traits<mss::mc_type::EXPLORER>;

    FAPI_INF(GENTARGTIDFORMAT " Start write_runtime_throttles", GENTARGTID(i_target));

    uint16_t l_runtime_port = 0;
    uint16_t l_runtime_slot = 0;

    fapi2::buffer<uint64_t> l_data;
    FAPI_TRY(fapi2::getScom(i_target, TT::FARB3Q_REG, l_data));

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_EXP_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_PORT, i_target, l_runtime_port));
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_EXP_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_SLOT, i_target, l_runtime_slot));

    l_data.insertFromRight<TT::RUNTIME_N_SLOT, TT::RUNTIME_N_SLOT_LEN>(l_runtime_slot);
    l_data.insertFromRight<TT::RUNTIME_N_PORT, TT::RUNTIME_N_PORT_LEN>(l_runtime_port);

    FAPI_TRY( fapi2::putScom(i_target, TT::FARB3Q_REG, l_data) );

    FAPI_INF(GENTARGTIDFORMAT " End write_runtime_throttles", GENTARGTID(i_target));
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    FAPI_ERR(GENTARGTIDFORMAT " Couldn't finish write_runtime_throttles", GENTARGTID(i_target));
    return fapi2::current_err;
}

///
/// @brief set the PWR CNTRL register - specialization for Explorer
/// @param[in] i_target the port target
/// @return fapi2::FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode set_pwr_cntrl_reg<mss::mc_type::EXPLORER>(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target)
{
    using TT = throttle_traits<mss::mc_type::EXPLORER>;

    fapi2::ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_Type l_pwr_cntrl = 0;
    fapi2::buffer<uint64_t> l_data;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_POWER_CONTROL_REQUESTED, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           l_pwr_cntrl));
    FAPI_TRY(fapi2::getScom(i_target, TT::MBARPC0Q_REG, l_data));

    l_data.insertFromRight<TT::CFG_MIN_MAX_DOMAINS, TT::CFG_MIN_MAX_DOMAINS_LEN>(TT::MAXALL_MINALL);

    // Write data if PWR_CNTRL_REQUESTED includes power down
    switch (l_pwr_cntrl)
    {
        case fapi2::ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_POWER_DOWN:
            l_data.clearBit<TT::CFG_LP_CTRL_ENABLE>()
            .clearBit<TT::CFG_LP_DATA_ENABLE>()
            .setBit<TT::CFG_MIN_DOMAIN_REDUCTION_ENABLE>();
            break;

        case fapi2::ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_PD_AND_STR:
        case fapi2::ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_PD_AND_STR_CLK_STOP:
            l_data.setBit<TT::CFG_LP_CTRL_ENABLE>()
            .setBit<TT::CFG_LP_DATA_ENABLE>()
            .setBit<TT::CFG_MIN_DOMAIN_REDUCTION_ENABLE>();
            break;

        case fapi2::ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_OFF:
            l_data.clearBit<TT::CFG_LP_CTRL_ENABLE>()
            .clearBit<TT::CFG_LP_DATA_ENABLE>()
            .clearBit<TT::CFG_MIN_DOMAIN_REDUCTION_ENABLE>();
            break;

        default:
            FAPI_ASSERT( false,
                         fapi2::MSS_UNSUPPORTED_MRW_POWER_CONTROL_REQUESTED()
                         .set_PORT_TARGET(i_target)
                         .set_FUNCTION(mss::SET_PWR_CNTRL_REG)
                         .set_VALUE(l_pwr_cntrl),
                         GENTARGTIDFORMAT " ATTR_MSS_MRW_POWER_CONTROL_REQUESTED not set correctly in MRW: %u",
                         GENTARGTID(i_target),
                         l_pwr_cntrl);
            break;
    }

    //Set the MIN_DOMAIN_REDUCTION time
    l_data.insertFromRight<TT::CFG_MIN_DOMAIN_REDUCTION_TIME, TT::CFG_MIN_DOMAIN_REDUCTION_TIME_LEN>
    (TT::MIN_DOMAIN_REDUCTION_TIME);

    FAPI_TRY(fapi2::putScom(i_target, TT::MBARPC0Q_REG, l_data));

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    FAPI_ERR(GENTARGTIDFORMAT " Error setting power control register MBARPC0Q", GENTARGTID(i_target));
    return fapi2::current_err;
}

///
/// @brief Calcuate the throttle values based on throttle type - Explorer specialization
/// @param[in] i_target the MC target
/// @param[in] i_throttle_type thermal boolean to determine whether to calculate throttles based on the power regulator or thermal limits
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
/// @note determines the throttle levels based off of the port's power curve,
/// sets the slot throttles to the same
/// Enums are POWER for power egulator throttles and THERMAL for thermal throttles
/// equalizes the throttles to the lowest of runtime and the lowest slot-throttle value
///
template<>
fapi2::ReturnCode pwr_throttles<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const mss::throttle_type i_throttle_type)
{
    if (mss::count_dimm (i_target) == 0)
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    uint16_t l_slot = 0;
    uint16_t l_port  = 0;
    uint32_t l_power = 0;

    for (const auto& l_port_target : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
    {
        fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

        //Don't run if there are no dimms on the port
        if (mss::count_dimm(l_port_target) == 0)
        {
            continue;
        }

        mss::power_thermal::throttle<mss::mc_type::EXPLORER> l_pwr_struct(l_port_target, l_rc);
        FAPI_TRY(l_rc, "Error constructing mss:power_thermal::throttle object for target " GENTARGTIDFORMAT,
                 GENTARGTID(l_port_target));

        //Let's do the actual work now
        if ( i_throttle_type == mss::throttle_type::THERMAL)
        {
            FAPI_TRY (l_pwr_struct.thermal_throttles());
        }
        else
        {
            FAPI_TRY (l_pwr_struct.power_regulator_throttles());
        }

        l_slot = l_pwr_struct.iv_n_slot;
        l_port = l_pwr_struct.iv_n_port;
        l_power = l_pwr_struct.iv_calc_port_maxpower;

        FAPI_INF("For target " GENTARGTIDFORMAT " Calculated power is %d, throttle per slot is %d, throttle per port is %d",
                 GENTARGTID(l_port_target), l_power, l_slot, l_port);

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_EXP_PORT_MAXPOWER,  l_port_target, l_power));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_EXP_MEM_THROTTLED_N_COMMANDS_PER_SLOT,  l_port_target, l_slot));
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_EXP_MEM_THROTTLED_N_COMMANDS_PER_PORT,  l_port_target, l_port));
    }

    return fapi2::current_err;

fapi_try_exit:
    FAPI_ERR(GENTARGTIDFORMAT " Error calculating pwr_throttles using %s throttling",
             GENTARGTID(i_target),
             ((i_throttle_type == mss::throttle_type::POWER) ? "power" : "thermal"));
    return fapi2::current_err;
}

///
/// @brief Adjusts memory power according to max achievable
///        utilization based on DIMM freq and port count  - Explorer specialization
/// @param[in] i_port_target mem port target that is being executed
/// @param[in,out] io_fin_power Final power that is calculated based on frequency and port
/// @return FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode memory_power_adjustment<mss::mc_type::EXPLORER>(const
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

    const auto l_dummy = mss::power_thermal::throttle<mss::mc_type::EXPLORER>(i_port_target, l_rc);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_MEM_M_DRAM_CLOCKS, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           l_throttle_denominator));
    FAPI_TRY(l_rc, "Failed creating a throttle object in equalize_throttles for " GENTARGTIDFORMAT,
             GENTARGTID(i_port_target));

    // Get the DRAM frequency for the port
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_EFF_FREQ, i_port_target, l_dram_freq));

    // Get the max achievable utilization based on frequency and port
    if (l_dram_freq == 2666)
    {
        l_max_util = throttle_traits<mss::mc_type::EXPLORER>::PORT_UTIL_MAP_2666;
    }
    else if (l_dram_freq == 2933)
    {
        l_max_util = throttle_traits<mss::mc_type::EXPLORER>::PORT_UTIL_MAP_2933;
    }
    else if (l_dram_freq == 3200)
    {
        l_max_util = throttle_traits<mss::mc_type::EXPLORER>::PORT_UTIL_MAP_3200;
    }

    // Calculate out the throttle value using the utilization value
    l_n_throttle_for_maxutil = calc_n_from_dram_util(l_max_util, l_throttle_denominator);

    // Calculate the max achievable value from the above throttle value
    FAPI_TRY( l_dummy.calc_power_from_n(l_n_throttle_for_maxutil, l_n_throttle_for_maxutil, l_max_achievable_pwr),
              "Failed calculating the power value for throttles: slot %d, port %d for target: " GENTARGTIDFORMAT,
              l_n_throttle_for_maxutil,
              l_n_throttle_for_maxutil,
              GENTARGTID(i_port_target));

    // Compare to the calculated power at the hardcoded util value
    // If the calculated power is less than what is in the attribute
    // then update the attribute with the calculated power value
    if( l_max_achievable_pwr < io_fin_power)
    {
        FAPI_INF("Memory power adjustment was made because max achievable power: %d is less than final power: %d for target "
                 GENTARGTIDFORMAT,
                 l_max_achievable_pwr, io_fin_power, GENTARGTID(i_port_target));
    }
    else
    {
        FAPI_INF("Memory power adjustment was not made because max achievable power: %d is greater than final power: %d for target "
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
/// @brief Equalize the throttles and estimated power at those throttle levels - Explorer specialization
/// @param[in] i_targets vector of MC targets all on the same VDDR domain
/// @param[in] i_throttle_type denotes if this was done for POWER (VMEM) or THERMAL (VMEM+VPP) throttles
/// @param[out] o_exceeded_power vector of port targets where the estimated power exceeded the maximum allowed
/// @return FAPI2_RC_SUCCESS iff ok
/// @note sets the throttles and power to the worst case
/// Called by mss_bulk_pwr_throttles and by mss_utils_to_throttle (so by IPL or by OCC)
///
template<>
fapi2::ReturnCode equalize_throttles_helper<mss::mc_type::EXPLORER>(const
        std::vector<fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>>& i_targets,
        const throttle_type i_throttle_type,
        std::vector<fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>>& o_exceeded_power)
{
    using TT = throttle_traits<mss::mc_type::EXPLORER>;

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
                FAPI_INF("Seeing no DIMMs on " GENTARGTIDFORMAT " -- skipping", GENTARGTID(l_port));
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
                    FAPI_INF("Seeing no DIMMs on " GENTARGTIDFORMAT " -- skipping", GENTARGTID(l_port));
                    continue;
                }

                // Declaring above to avoid fapi2 jump
                uint64_t l_power_limit = 0;

                l_fin_slot = l_min_slot;
                l_fin_port = l_min_port;

                //Need to create throttle object for each port in order to get dimm configuration and power curves
                //To calculate the slot/port utilization and total port power consumption
                fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

                const auto l_dummy = mss::power_thermal::throttle<mss::mc_type::EXPLORER>(l_port, l_rc);
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

                FAPI_INF(GENTARGTIDFORMAT " Calculated power is %d, limit is %d", GENTARGTID(l_port), l_fin_power,
                         static_cast<uint32_t>(l_power_limit));

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
                    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MEM_PORT_POS_OF_FAIL_THROTTLE, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                                            l_fail) );

                    //Note: any failing RC from this assert will be overwritten by the FAPI_TRYs below
                    //but that's ok since we're only using this for deconfigures in FFDC. The RC will be
                    //handled using the list of targets in o_exceeded_power in equalize_throttles
                    FAPI_ASSERT_NOEXIT( false,
                                        fapi2::MSS_CALC_PORT_POWER_EXCEEDS_MAX()
                                        .set_CALCULATED_PORT_POWER(l_fin_power)
                                        .set_MAX_POWER_ALLOWED(l_power_limit)
                                        .set_PORT_POS(mss::pos(l_port))
                                        .set_PORT_TARGET(l_port),
                                        "Error calculating the final port power value for target " GENTARGTIDFORMAT
                                        ", calculated power is %d, max value can be %d",
                                        GENTARGTID(l_port),
                                        l_fin_power,
                                        static_cast<uint32_t>(l_power_limit));

                    o_exceeded_power.push_back(l_port);
                }

                FAPI_INF(GENTARGTIDFORMAT " Final throttles values for slot %d, for port %d, power value %d",
                         GENTARGTID(l_port),
                         l_fin_slot,
                         l_fin_port,
                         l_fin_power);

                //Even if there's an error, still calculate and set the throttles.
                //OCC will set to safemode if there's an error
                //Better to set the throttles than leave them 0, and potentially brick the memory
                FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EXP_MEM_THROTTLED_N_COMMANDS_PER_PORT,  l_port, l_fin_port) );
                FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EXP_MEM_THROTTLED_N_COMMANDS_PER_SLOT,  l_port, l_fin_slot) );
                FAPI_TRY(memory_power_adjustment<mss::mc_type::EXPLORER>( l_port, l_fin_power));
                FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_EXP_PORT_MAXPOWER,  l_port, l_fin_power) );
            }
        }
    }
    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    FAPI_ERR("Error equalizing memory throttles on " GENTARGTIDFORMAT, GENTARGTID(l_current_mc));
    return fapi2::current_err;
}

///
/// @brief set the STR register - Explorer specialization
/// @param[in] i_target the port target
/// @return fapi2::FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode set_str_reg<mss::mc_type::EXPLORER>(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target)
{
    using TT = throttle_traits<mss::mc_type::EXPLORER>;
    fapi2::ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_Type l_str_enable = 0;
    fapi2::buffer<uint64_t> l_data;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_POWER_CONTROL_REQUESTED, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           l_str_enable));
    FAPI_TRY(fapi2::getScom(i_target, TT::STR0Q_REG, l_data));

    //Write bit if STR should be enabled
    switch (l_str_enable)
    {
        case fapi2::ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_PD_AND_STR:
        case fapi2::ENUM_ATTR_MSS_MRW_POWER_CONTROL_REQUESTED_PD_AND_STR_CLK_STOP:
            FAPI_INF("%s STR requested but STR is not allowed for DDR4 DIMM's. Using Power down mode", mss::c_str(i_target));

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
    FAPI_ERR(GENTARGTIDFORMAT " Error setting the STR register MBASTR0Q", GENTARGTID(i_target));
    return fapi2::current_err;
}

///
/// @brief set the general N/M throttle register - Explorer specialization
/// @param[in] i_target the port target
/// @return fapi2::FAPI2_RC_SUCCESS if ok
///
template<>
fapi2::ReturnCode set_nm_support<mss::mc_type::EXPLORER>(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target)
{
    using TT = throttle_traits<mss::mc_type::EXPLORER>;

    uint16_t l_run_slot = 0;
    uint16_t l_run_port = 0;
    fapi2::ATTR_MSS_MRW_MEM_M_DRAM_CLOCKS_Type l_throttle_denominator = 0;

    fapi2::buffer<uint64_t> l_data;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_MEM_M_DRAM_CLOCKS, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           l_throttle_denominator));

    FAPI_TRY(fapi2::getScom(i_target, TT::FARB3Q_REG, l_data));

    // runtime should be calculated in eff_config_thermal, which is called before scominit in ipl
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_EXP_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_PORT, i_target, l_run_port));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_EXP_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_SLOT, i_target, l_run_slot));
    FAPI_INF("For target " GENTARGTIDFORMAT
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
/// @brief set the safemode throttle register - Explorer specialization
/// @param[in] i_target the port target
/// @return fapi2::FAPI2_RC_SUCCESS if ok
/// @note sets FARB4Q
/// @note used to set throttle window (N throttles  / M clocks)
///
template<>
fapi2::ReturnCode set_safemode_throttles<mss::mc_type::EXPLORER>(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>&
        i_target)
{
    using TT = throttle_traits<mss::mc_type::EXPLORER>;

    fapi2::buffer<uint64_t> l_data;
    fapi2::ATTR_MSS_MRW_MEM_M_DRAM_CLOCKS_Type l_throttle_denominator = 0;
    uint32_t l_throttle_per_port = 0;
    fapi2::ATTR_MSS_SAFEMODE_DRAM_DATABUS_UTIL_Type l_util_per_port = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_SAFEMODE_DRAM_DATABUS_UTIL, i_target, l_util_per_port));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MSS_MRW_MEM_M_DRAM_CLOCKS, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           l_throttle_denominator));

    FAPI_TRY(fapi2::getScom(i_target, TT::FARB4Q_REG, l_data));

    // l_util_per_port is in c%
    l_throttle_per_port = calc_n_from_dram_util(l_util_per_port, l_throttle_denominator);

    l_data.insertFromRight<TT::EMERGENCY_M, TT::EMERGENCY_M_LEN>(l_throttle_denominator);
    l_data.insertFromRight<TT::EMERGENCY_N, TT::EMERGENCY_N_LEN>(l_throttle_per_port);

    FAPI_TRY(fapi2::putScom(i_target, TT::FARB4Q_REG, l_data));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    FAPI_ERR(GENTARGTIDFORMAT " Error setting safemode throttles", GENTARGTID(i_target));
    return fapi2::current_err;
}

///
/// @brief safemode throttle values defined from MRW attributes - Explorer specialization
/// @param[in] i_target the port target
/// @return fapi2::FAPI2_RC_SUCCESS if ok
/// @note sets safemode values for emergency mode and regular throttling, and some power controls
///
template<>
fapi2::ReturnCode thermal_throttle_scominit<mss::mc_type::EXPLORER>(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>&
        i_target)
{
    FAPI_TRY(set_pwr_cntrl_reg<mss::mc_type::EXPLORER>(i_target));
    FAPI_TRY(set_str_reg<mss::mc_type::EXPLORER>(i_target));
    FAPI_TRY(set_nm_support<mss::mc_type::EXPLORER>(i_target));
    FAPI_TRY(set_safemode_throttles<mss::mc_type::EXPLORER>(i_target));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    FAPI_ERR("%s Error setting scominits for power_thermal values", mss::c_str(i_target));
    return fapi2::current_err;
}

}//namespace power_thermal
}//namespace mss
