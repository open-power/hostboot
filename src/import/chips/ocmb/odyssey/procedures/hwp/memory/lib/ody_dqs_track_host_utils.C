/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/ody_dqs_track_host_utils.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023,2024                        */
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

// EKB-Mirror-To: hostboot

///
/// @file ody_dqs_track_host_utils.C
/// @brief DQS tracking host-side utils
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: David J Chung <dj.chung@ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#include <fapi2.H>

#include <ody_tsns_dqs_period.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

namespace mss
{
namespace ody
{

///
/// @brief Suspend DQS drift track and poll MCBIST until it's done executing
/// @param [in] i_target OCMB target
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode suspend_dqs_track(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    uint8_t l_thermal_init_complete = 0;
    uint32_t l_tsns_period_ms = 0;
    uint8_t l_dqs_period = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_THERMAL_INIT_COMPLETE,
                           i_target,
                           l_thermal_init_complete));

    // Do not send the chip-op if we haven't yet run mss_thermal_init
    if (l_thermal_init_complete == fapi2::ENUM_ATTR_MEM_THERMAL_INIT_COMPLETE_NO)
    {
        FAPI_INF("%s skipping DQS track suspend chip-op since called before mss_thermal_init", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_SENSOR_POLLING_PERIOD_MS_INIT,
                           i_target,
                           l_tsns_period_ms));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_DQS_TRACKING_PERIOD_INIT,
                           i_target,
                           l_dqs_period));

    FAPI_EXEC_HWP(l_rc,
                  ody_tsns_dqs_period,
                  i_target,
                  l_tsns_period_ms,
                  0);
    FAPI_TRY(l_rc);

    // Wait one polling cycle to ensure any currently-running recal is complete
    fapi2::delay(l_tsns_period_ms * l_dqs_period * mss::DELAY_1MS, 200);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Resume DQS drift track
/// @param [in] i_target OCMB target
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode resume_dqs_track(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    uint8_t l_thermal_init_complete = 0;
    uint32_t l_tsns_period_ms = 0;
    uint8_t l_dqs_period = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_THERMAL_INIT_COMPLETE,
                           i_target,
                           l_thermal_init_complete));

    // Do not send the chip-op if we haven't yet run mss_thermal_init
    if (l_thermal_init_complete == fapi2::ENUM_ATTR_MEM_THERMAL_INIT_COMPLETE_NO)
    {
        FAPI_INF("%s skipping DQS track resume chip-op since called before mss_thermal_init", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_SENSOR_POLLING_PERIOD_MS_INIT,
                           i_target,
                           l_tsns_period_ms));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ODY_DQS_TRACKING_PERIOD_INIT,
                           i_target,
                           l_dqs_period));

    FAPI_EXEC_HWP(l_rc,
                  ody_tsns_dqs_period,
                  i_target,
                  l_tsns_period_ms,
                  l_dqs_period);
    FAPI_TRY(l_rc);

fapi_try_exit:
    return fapi2::current_err;
}

} // end ns ody
} // end ns mss
