/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/ody_bulk_pwr_throttles.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2023                        */
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
/// @file ody_bulk_pwr_throttles.C
/// @brief The odyssey thermal/power config
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB
// EKB-Mirror-To: hostboot

#include <vector>

#include <fapi2.H>
#include <ody_bulk_pwr_throttles.H>
#include <lib/shared/ody_consts.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <lib/power_thermal/ody_throttle_traits.H>
#include <lib/power_thermal/ody_throttle.H>

extern "C"
{
    ///
    /// @brief Set ATTR_ODY_PORT_MAXPOWER, ATTR_ODY_MEM_THROTTLED_N_COMMANDS_PER_SLOT, ATTR_ODY_MEM_THROTTLED_N_COMMANDS_PER_PORT
    /// @param[in] i_targets vector of OCMB chips
    /// @param[in] i_throttle_type thermal boolean to determine whether to calculate throttles based on the power regulator or thermal limits
    /// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
    /// @note determines the throttle levels based off of both ports' power curves,
    /// sets the slot throttles to the same
    /// @note Enums are POWER for power egulator throttles and THERMAL for thermal throttles
    /// @note equalizes the throttles to the lowest of runtime and the lowest slot-throttle value
    ///
    fapi2::ReturnCode ody_bulk_pwr_throttles( const std::vector< fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> >& i_targets,
            const mss::throttle_type i_throttle_type)
    {
        FAPI_INF("Start ody_bulk_pwr_throttles for %s type throttling",
                 (( i_throttle_type == mss::throttle_type::THERMAL) ? "THERMAL" : "POWER"));

        for ( const auto& l_ocmb : i_targets)
        {
            FAPI_TRY(mss::power_thermal::pwr_throttles<mss::mc_type::ODYSSEY>(l_ocmb, i_throttle_type));
        }

        // Equalizes the throttles to the lowest of runtime and the lowest slot-throttle value
        FAPI_TRY(mss::power_thermal::equalize_throttles<mss::mc_type::ODYSSEY>(i_targets, i_throttle_type));

        FAPI_INF("End ody_bulk_pwr_throttles");
        return fapi2::current_err;

    fapi_try_exit:
        FAPI_ERR("Error calculating ody_bulk_pwr_throttles using %s throttling",
                 ((i_throttle_type == mss::throttle_type::POWER) ? "power" : "thermal"));
        return fapi2::current_err;
    }

} //extern C
