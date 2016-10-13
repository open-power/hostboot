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
// *HWP Level: 1
// *HWP Consumed by: FSP:HB
#include <vector>

#include <mss.H>
#include <fapi2.H>
#include <p9_mss_bulk_pwr_throttles.H>
#include <lib/utils/find.H>
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
//To be implemented in next commit
#if 0

        //Check for THERMAL
        if (t == THERMAL)
        {
            for ( const auto& l_mcs : i_targets)
            {
                for (const auto& l_mca : mss::find_targets<TARGET_TYPE_MCA>(l_mcs))
                {
                    //mss::power_thermal::throttle l_pwr_struct(l_mca);
                    //FAPI_TRY (l_pwr_struct.thermal_throttles() );
                }
            }

            //Equalize throttles
        }
        //else do POWER
        else
        {
            for ( const auto& l_mcs : i_targets)
            {
                for (const auto& l_mca : mss::find_targets<TARGET_TYPE_MCA>(l_mcs))
                {
                    //mss::power_thermal::throttle l_pwr_struct(l_mca);
                    //FAPI_TRY (l_pwr_struct.power_regulator_throttles() );
                }
            }

            //Equalize throttles
        }


        FAPI_INF("End bulk_pwr_throttles");
    fapi_try_exit:
#endif
        return fapi2::current_err;
    }
} //extern C
