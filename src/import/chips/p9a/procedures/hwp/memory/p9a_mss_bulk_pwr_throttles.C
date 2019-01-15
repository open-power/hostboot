/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9a/procedures/hwp/memory/p9a_mss_bulk_pwr_throttles.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
/// @file p9a_mss_bulk_pwr_throttles.C
/// @brief Set the OCMB throttle attributes based on any power limits (thermal, regulator, or bulk)
///
// *HWP HWP Owner: Andre A. Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <vector>
#include <p9a_mss_bulk_pwr_throttles.H>

///
/// @brief Set ATTR_MSS_PORT_MAXPOWER, ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_SLOT, ATTR_MSS_MEM_THROTTLED_N_COMMANDS_PER_PORT
/// @param[in] i_targets vector of OCMB_CHIP's on the same processor or in the same node
/// @param[in] i_throttle_type thermal boolean to determine whether to calculate throttles based on the power regulator or thermal limits
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
/// @note Called by p9a_mss_eff_config_thermal or by TMGT
/// @note determines the throttle levels based off of the DIMM's power curve, sets the slot throttles to the same
/// @note Enums are POWER for power regulator throttles and THERMAL for thermal throttles
/// @note equalizes the throttles to the lowest of runtime and the lowest slot-throttle value
///
fapi2::ReturnCode p9a_mss_bulk_pwr_throttles(const std::vector< fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> >&
        i_targets,
        const mss::throttle_type i_throttle_type)
{
    FAPI_INF("Start p9a_mss_bulk_pwr_throttles for %s type throttling",
             (( i_throttle_type == mss::throttle_type::THERMAL) ? "THERMAL" : "POWER"));

    return fapi2::FAPI2_RC_SUCCESS;
}
