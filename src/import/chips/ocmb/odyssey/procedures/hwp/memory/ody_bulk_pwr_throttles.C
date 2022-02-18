/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/ody_bulk_pwr_throttles.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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

extern "C"
{
    ///
    /// @brief Set ATTR_ODY_PORT_MAXPOWER, ATTR_ODY_MEM_THROTTLED_N_COMMANDS_PER_SLOT, ATTR_ODY_MEM_THROTTLED_N_COMMANDS_PER_PORT
    /// @param[in] i_targets vector of OCMB chips
    /// @param[in] i_throttle_type thermal boolean to determine whether to calculate throttles based on the power regulator or thermal limits
    /// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
    /// @note determines the throttle levels based off of the port's power curve,
    /// sets the slot throttles to the same
    /// @note Enums are POWER for power egulator throttles and THERMAL for thermal throttles
    /// @note equalizes the throttles to the lowest of runtime and the lowest slot-throttle value
    ///
    fapi2::ReturnCode ody_bulk_pwr_throttles( const std::vector< fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> >& i_targets,
            const mss::throttle_type i_throttle_type)
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

} //extern C
