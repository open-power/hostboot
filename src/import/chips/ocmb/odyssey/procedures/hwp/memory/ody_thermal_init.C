/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/ody_thermal_init.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2022                        */
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
/// @file ody_thermal_init.C
/// @brief Procedure definition to initialize thermal sensor
///
// *HWP HWP Owner: Geetha Pisapati <geetha.pisapati@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP,HB, SBE

#include <fapi2.H>
#include <ody_thermal_init.H>
#include <lib/power_thermal/ody_thermal_init_utils.H>

extern "C"
{

    ///
    /// @brief Initializes thermal sensor
    /// @param[in] i_target the controller target
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode ody_thermal_init( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target )
    {
        // Polls the DTS for initial values
        FAPI_TRY(mss::ody::thermal::read_dts_sensors(i_target));

        // Sets up throttling
        FAPI_TRY (mss::ody::thermal::mc::setup_emergency_throttles(i_target));

        // Clear the emergency mode throttle bit
        FAPI_TRY (mss::ody::thermal::mc::disable_safe_mode_throttles(i_target));

    fapi_try_exit:
        return fapi2::current_err;
    }
} //extern C
