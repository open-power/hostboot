/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/exp_mss_thermal_init.C $ */
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
/// @file exp_mss_thermal_init.C
/// @brief Procedure definition to initialize thermal sensor
///
// *HWP HWP Owner: Sharath Manjunath <shamanj4@in.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/exp_mss_thermal_init_utils.H>
#include <exp_mss_thermal_init.H>
#include <generic/memory/lib/utils/find.H>

extern "C"
{

    ///
    /// @brief Initializes thermal sensor
    /// @param[in] i_target the controller target
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode exp_mss_thermal_init( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target )
    {
        FAPI_INF("%s Start thermal_init", mss::c_str(i_target));

        uint8_t l_interval_read_dis = 0;
        FAPI_TRY(mss::attr::get_disable_therm_init_read(i_target, l_interval_read_dis));

        // Attribute is 0 == enabled, 1 == disabled (enabled by default (0), make sure the disable is not set)
        if (l_interval_read_dis == fapi2::ENUM_ATTR_MSS_OCMB_DISABLE_THERM_INIT_READ_ENABLED)
        {
            FAPI_TRY(mss::exp::sensor_interval_read(i_target),
                     "Error performing EXP_FW_TEMP_SENSOR_CONFIG_INTERVAL_READ operation on %s", mss::c_str(i_target));
        }

#if 0
        // Prior to starting OCC, we go into "safemode" throttling
        // After OCC is started, they can change throttles however they want
        // We don't want to do this in Cronus mode
        // TK ZEN #676 Enable safemode throttles once OCC supports it
        // but still only in Hostboot
        FAPI_TRY (mss::exp::mc::setup_emergency_throttles(i_target));
#endif
        // Clear the emergency mode throttle bit
        FAPI_TRY (mss::exp::mc::disable_safe_mode_throttles(i_target));

        FAPI_INF("%s End thermal_init", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    fapi_try_exit:
        FAPI_ERR("%s Error executing thermal_init", mss::c_str(i_target));
        return fapi2::current_err;
    }
} //extern C
