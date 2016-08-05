/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/p9_mss_thermal_init.C $ */
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
/// @file p9_mss_thermal_init.C
/// @brief configure and start the OCC and thermal cache
///
// *HWP HWP Owner: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/mc/mc.H>
#include <lib/utils/find.H>
#include <p9_mss_thermal_init.H>

using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_MCA;
extern "C"
{

///
/// @brief configure and start the OCC and thermal cache
/// @param[in] i_target the controller target
/// @return FAPI2_RC_SUCCESS iff ok
///
    fapi2::ReturnCode p9_mss_thermal_init( const fapi2::Target<TARGET_TYPE_MCS>& i_target )
    {
        FAPI_INF("Start thermal_init");

        for (const auto& p : mss::find_targets<TARGET_TYPE_MCA>(i_target))
        {
            FAPI_TRY(mss::mc::thermal_throttle_scominit(p));
        }

        FAPI_TRY (mss::mc::disable_emergency_throttle(i_target));
        FAPI_INF("End thermal_init");
    fapi_try_exit:
        return fapi2::current_err;
    }
} //extern C
