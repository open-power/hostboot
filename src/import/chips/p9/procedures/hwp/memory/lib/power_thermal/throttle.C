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
#include <mss.H>
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_DIMM;
using fapi2::TARGET_TYPE_MCBIST;

namespace mss
{

///
/// @brief Set ATTR_MSS_CHANNEL_PAIR_MAXPOWER,  ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_SLOT and _PER_PORT
/// @param[in] Vector of MCS's on the same VDDR domain
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
/// @note Called in p9_mss_bulk_pwr_throttles
/// @note determines the throttle levels based off of the port's power curve,
/// @note the _per_slot throttles are set to the _per_port values
/// @note throttles are all equalized and set to the worst case value
///
fapi2::ReturnCode bulk_power_regulator_throttles (const std::vector<fapi2::Target<TARGET_TYPE_MCS>>& i_targets)
{

    for (const auto& l_mcs : i_targets)
    {
        uint32_t l_databus_util_max = 0;
        uint8_t l_power_uplift = 0;
        uint8_t l_power_uplift_idle = 0;
        uint32_t l_dimm_power_limit [2][2] = {};
        uint32_t l_runtime_n_slot [2] = {};
        uint32_t l_m_clocks = 0;
        uint32_t l_final_n_slot_array[2] = {};
        uint32_t l_port_maxpower[2] = {};

        FAPI_TRY( mem_throttled_n_commands_per_slot( l_mcs, &(l_final_n_slot_array[0])) );
        FAPI_TRY( port_maxpower ( l_mcs, l_port_maxpower) );
        FAPI_TRY( mrw_max_dram_databus_util(l_databus_util_max) );
        FAPI_TRY( mrw_dimm_power_curve_percent_uplift( l_power_uplift) );
        FAPI_TRY( mrw_dimm_power_curve_percent_uplift_idle( l_power_uplift_idle) );
        FAPI_TRY( runtime_mem_throttled_n_commands_per_slot(l_mcs, &(l_runtime_n_slot[0]) ) );
        FAPI_TRY( mem_watt_target( l_mcs, &(l_dimm_power_limit[0][0])) );
        FAPI_TRY( mrw_mem_m_dram_clocks(l_m_clocks) );
        //Temp values until totally implemented
        l_port_maxpower[0] = 2088;
        l_port_maxpower[1] = 2088;
        //same for per port and per slot
        //Throttle per slot is set to per port value
        l_final_n_slot_array[0] = 115;
        l_final_n_slot_array[1] = 115;
        FAPI_TRY( FAPI_ATTR_SET( fapi2::ATTR_MSS_PORT_MAXPOWER, l_mcs, l_port_maxpower) );
        //Set the throttle for the MCS target
        FAPI_TRY( FAPI_ATTR_SET( fapi2::ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_SLOT, l_mcs, l_final_n_slot_array ) );
        FAPI_TRY( FAPI_ATTR_SET( fapi2::ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_PORT, l_mcs, l_final_n_slot_array ) );
    } // MCS

fapi_try_exit:
    FAPI_INF("End power regulator bulk throttles");
    return fapi2::current_err;
}

///
/// @brief Set ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_SLOT and PER_PORT
/// @param[in] Vector of MCS's on the same VDDR domain
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
/// @note Called in p9_mss_bulk_pwr_throttles
/// @note Sets the throttle levels based off of the dimm's thermal limits
/// @note both DIMM's on a port are set to the same throttle level
///
fapi2::ReturnCode bulk_thermal_throttles (const std::vector<fapi2::Target<TARGET_TYPE_MCS>>& i_targets)
{
    FAPI_INF("End thermal bulk throttles");
    return fapi2::FAPI2_RC_SUCCESS;
}

}//namespace mss
