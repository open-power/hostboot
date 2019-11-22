/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/exp_mss_thermal_init.C $ */
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
#include <lib/inband/exp_inband.H>
#include <exp_mss_thermal_init.H>

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

#if 0
// Skip EXP_FW_TEMP_SENSOR_CONFIG_INTERVAL_READ until it's available in Explorer FW
        // Declare variables
        host_fw_command_struct l_cmd_sensor;
        host_fw_response_struct l_response;
        std::vector<uint8_t> l_rsp_data;

        // Sets up EXP_FW_TEMP_SENSOR_CONFIG_INTERVAL_READ cmd params
        mss::exp::setup_sensor_interval_read_cmd_params(l_cmd_sensor);

        // Enable sensors
        FAPI_TRY( mss::exp::ib::putCMD(i_target, l_cmd_sensor),
                  "Failed putCMD() for  %s", mss::c_str(i_target) );

        FAPI_TRY( mss::exp::ib::getRSP(i_target, l_response, l_rsp_data),
                  "Failed getRSP() for  %s", mss::c_str(i_target) );

        FAPI_TRY( mss::exp::check::sensor_response(i_target, l_response),
                  "Failed sensor_response() for  %s", mss::c_str(i_target) );
#endif

#ifdef __HOSTBOOT_MODULE
        // Prior to starting OCC, we go into "safemode" throttling
        // After OCC is started, they can change throttles however they want
        // We don't want to do this in Cronus mode
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
