/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/p9_mss_bulk_pwr_throttles.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
/// @file p9_mss_bulk_pwr_throttles.C
/// @brief Set the throttle attributes based on a power limit for the dimms on the channel pair
///
// *HWP HWP Owner: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB
#include <vector>

#include <mss.H>
#include <fapi2.H>
#include <p9_mss_bulk_pwr_throttles.H>
#include <lib/utils/find.H>
#include <lib/utils/count_dimm.H>
#include <lib/power_thermal/throttle.H>

using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_DIMM;
extern "C"
{

///
/// @brief Set ATTR_MSS_PORT_MAXPOWER, ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_SLOT, ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_PORT
/// @param[in] i_targets vector of MCS's on the same VDDR domain
/// @param[in] thermal boolean to determine whether to calculate throttles based on the power regulator or thermal limits
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
/// @note Called in p9_mss_bulk_pwr_throttles
/// @note determines the throttle levels based off of the port's power curve,
/// sets the slot throttles to the same
/// @note Enums are POWER for power egulator throttles and THERMAL for thermal throttles
/// @note equalizes the throttles to the lowest of runtime and the lowest slot-throttle value
///

    fapi2::ReturnCode p9_mss_bulk_pwr_throttles( const std::vector< fapi2::Target<TARGET_TYPE_MCS> >& i_targets,
            throttle_type t)
    {
        FAPI_INF("Start bulk_pwr_throttles");

        //Check for THERMAL
        if (t == THERMAL)
        {
            for ( const auto& l_mcs : i_targets)
            {
                uint16_t l_slot [mss::PORTS_PER_MCS] = {};
                uint16_t l_port [mss::PORTS_PER_MCS] = {};
                uint32_t l_power [mss::PORTS_PER_MCS] = {};

                for (const auto& l_mca : mss::find_targets<TARGET_TYPE_MCA>(l_mcs))
                {
                    //Don't run if there are no dimms on the port
                    if (mss::count_dimm(l_mca) == 0)
                    {
                        continue;
                    }

                    const uint8_t l_pos = mss::index(l_mca);
                    fapi2::ReturnCode l_rc;
                    mss::power_thermal::throttle l_pwr_struct(l_mca, l_rc);
                    FAPI_TRY(l_rc, "Error constructing mss:power_thermal::throttle object for target %s",
                             mss::c_str(l_mca));
                    FAPI_TRY (l_pwr_struct.thermal_throttles());

                    l_slot[l_pos] = l_pwr_struct.iv_n_slot;
                    l_port[l_pos] = l_pwr_struct.iv_n_port;
                    l_power[l_pos] = l_pwr_struct.iv_calc_port_maxpower;
                }

                FAPI_INF("Port maxpower is %d, %d slot is %d, %d, port is %d %d",
                         l_power[0], l_power[1], l_slot[0], l_slot[1], l_port[0], l_port[1]);

                FAPI_TRY(FAPI_ATTR_SET( fapi2::ATTR_MSS_PORT_MAXPOWER, l_mcs, l_power));
                FAPI_TRY(FAPI_ATTR_SET( fapi2::ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_SLOT, l_mcs, l_slot));
                FAPI_TRY(FAPI_ATTR_SET( fapi2::ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_PORT, l_mcs, l_port));
            }

            //Equalize throttles
        }
        //else do POWER
        else
        {
            for ( const auto& l_mcs : i_targets)
            {
                uint16_t l_slot [mss::PORTS_PER_MCS] = {};
                uint16_t l_port [mss::PORTS_PER_MCS] = {};
                uint32_t l_power [mss::PORTS_PER_MCS] = {};

                for (const auto& l_mca : mss::find_targets<TARGET_TYPE_MCA>(l_mcs))
                {
                    //Don't run if there are no dimms on the port
                    if (mss::count_dimm(l_mca) == 0)
                    {
                        continue;
                    }

                    uint8_t l_pos = mss::index(l_mca);
                    fapi2::ReturnCode l_rc;
                    mss::power_thermal::throttle l_pwr_struct(l_mca, l_rc);
                    FAPI_TRY(l_rc, "Error constructing mss:power_thermal::throttle object for target %s",
                             mss::c_str(l_mca));

                    FAPI_TRY (l_pwr_struct.power_regulator_throttles());

                    l_slot[l_pos] = l_pwr_struct.iv_n_slot;
                    l_port[l_pos] = l_pwr_struct.iv_n_port;
                    l_power[l_pos] = l_pwr_struct.iv_calc_port_maxpower;
                }

                FAPI_INF("Port maxpower is %d, %d slot is %d, %d, port is %d %d",
                         l_power[0], l_power[1], l_slot[0], l_slot[1], l_port[0], l_port[1]);
                FAPI_TRY(FAPI_ATTR_SET( fapi2::ATTR_MSS_PORT_MAXPOWER, l_mcs, l_power));
                FAPI_TRY(FAPI_ATTR_SET( fapi2::ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_SLOT, l_mcs, l_slot));
                FAPI_TRY(FAPI_ATTR_SET( fapi2::ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_PORT, l_mcs, l_port));
            }

            //Equalize throttles
        }

        FAPI_INF("End bulk_pwr_throttles");
        return fapi2::FAPI2_RC_SUCCESS;

    fapi_try_exit:
        FAPI_ERR("Error calculating bulk_pwr_throttles");
        return fapi2::current_err;
    }
} //extern C
