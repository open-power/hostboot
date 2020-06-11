/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/power_thermal/exp_throttle.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
// *HWP HWP Owner: Andre A. Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <lib/shared/exp_defaults.H>
#include <fapi2.H>

#include <lib/shared/exp_consts.H>
#include <lib/power_thermal/exp_throttle.H>
#include <lib/power_thermal/exp_throttle_traits.H>
#include <mss_explorer_attribute_getters.H>
#include <mss_explorer_attribute_setters.H>
#include <generic/memory/lib/utils/count_dimm.H>

namespace mss
{
namespace power_thermal
{
///
/// @brief Calcuate the throttle values based on throttle type
/// @param[in] i_target
/// @param[in] i_throttle_type thermal boolean to determine whether to calculate throttles based on the power regulator or thermal limits
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
/// @note Called in p9_mss_bulk_pwr_throttles
/// @note determines the throttle levels based off of the port's power curve,
/// sets the slot throttles to the same
/// @note Enums are POWER for power egulator throttles and THERMAL for thermal throttles
/// @note equalizes the throttles to the lowest of runtime and the lowest slot-throttle value
///
fapi2::ReturnCode pwr_throttles( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
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

        mss::power_thermal::throttle<> l_pwr_struct(l_port_target, l_rc);
        FAPI_TRY(l_rc, "Error constructing mss:power_thermal::throttle object for target %s",
                 mss::c_str(l_port_target));

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

        FAPI_INF("For target %s Calculated power is %d, throttle per slot is %d, throttle per port is %d",
                 mss::c_str(l_port_target), l_power, l_slot, l_port);

        FAPI_TRY(mss::attr::set_port_maxpower( l_port_target, l_power));
        FAPI_TRY(mss::attr::set_mem_throttled_n_commands_per_slot( l_port_target, l_slot));
        FAPI_TRY(mss::attr::set_mem_throttled_n_commands_per_port( l_port_target, l_port));
    }

    return fapi2::current_err;

fapi_try_exit:
    FAPI_ERR("Error calculating pwr_throttles using %s throttling",
             ((i_throttle_type == mss::throttle_type::POWER) ? "power" : "thermal"));
    return fapi2::current_err;
}

///
/// @brief Equalize the throttles among OCMB chips
/// @param[in] i_targets vector of OCMB chips
/// @param[in] i_throttle_type thermal boolean to determine whether to calculate throttles based on the power regulator or thermal limits
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
/// @note equalizes the throttles to the lowest of runtime and the lowest slot-throttle value
///
fapi2::ReturnCode equalize_throttles( const std::vector< fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> >& i_targets,
                                      const mss::throttle_type i_throttle_type)
{
    std::vector< fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> > l_exceeded_power;

    // Set all of the throttles to the lowest value per port for performance reasons
    FAPI_TRY(mss::power_thermal::equalize_throttles(i_targets, i_throttle_type, l_exceeded_power));

    // Report any port that exceeded the max power limit, and return a failing RC if we have any
    for (const auto& l_port : l_exceeded_power)
    {
        FAPI_ERR(" MEM_PORT %s estimated power exceeded the maximum allowed", mss::c_str(l_port) );
        fapi2::current_err = fapi2::FAPI2_RC_FALSE;
    }

    return fapi2::current_err;

fapi_try_exit:
    FAPI_ERR("Error calculating equalize_throttles using %s throttling",
             ((i_throttle_type == mss::throttle_type::POWER) ? "power" : "thermal"));
    return fapi2::current_err;
}

///
/// @brief set the safemode throttle register
/// @param[in] i_target the port target
/// @return fapi2::FAPI2_RC_SUCCESS if ok
/// @note sets FARB4Q
/// @note used to set throttle window (N throttles  / M clocks)
/// @note EXPLORER specialization
///
template<>
fapi2::ReturnCode set_safemode_throttles<mss::mc_type::EXPLORER>(
    const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target)
{
    using TT = throttle_traits<mss::mc_type::EXPLORER>;

    fapi2::buffer<uint64_t> l_data;
    fapi2::ATTR_MSS_MRW_MEM_M_DRAM_CLOCKS_Type l_throttle_denominator = 0;
    uint32_t l_throttle_per_port = 0;
    fapi2::ATTR_MSS_MRW_SAFEMODE_DRAM_DATABUS_UTIL_Type l_util_per_port = 0;

    FAPI_TRY(mss::attr::get_mrw_safemode_dram_databus_util(l_util_per_port));
    FAPI_TRY(mss::attr::get_mrw_mem_m_dram_clocks(l_throttle_denominator));

    FAPI_TRY(fapi2::getScom(i_target, TT::FARB4Q_REG, l_data));

    // l_util_per_port is in c%, so convert to % when calling calc_n_from_dram_util
    l_throttle_per_port = calc_n_from_dram_util((l_util_per_port / PERCENT_CONVERSION), l_throttle_denominator);

    l_data.insertFromRight<TT::EMERGENCY_M, TT::EMERGENCY_M_LEN>(l_throttle_denominator);
    l_data.insertFromRight<TT::EMERGENCY_N, TT::EMERGENCY_N_LEN>(l_throttle_per_port);

    FAPI_TRY(fapi2::putScom(i_target, TT::FARB4Q_REG, l_data));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    FAPI_ERR("%s Error setting safemode throttles", mss::c_str(i_target));
    return fapi2::current_err;
}

}//namespace power_thermal
}//namespace mss
