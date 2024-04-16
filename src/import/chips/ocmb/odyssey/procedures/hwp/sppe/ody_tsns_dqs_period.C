/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/sppe/ody_tsns_dqs_period.C $ */
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
/// @file ody_tsns_dqs_period.C
/// @brief Odyssey Modify Temperature Sensor and/or DQS Drift Tracking Polling Period
///
// *HWP Owner: Hostboot Team
// *HWP Backup: SBE Team
// *HWP Level: 3
// *HWP Consumed by: HB:Cronus

#include <fapi2.H>
#include <fapi2_subroutine_executor.H>
#include <ody_tsns_dqs_period.H>
#include <ody_chipop_tsns_dqs_period.H>

extern "C"
{

///
/// @brief Execute chipop to modify the Odyssey temperature sensor and/or
///       DQS drift tracking polling period
///
    fapi2::ReturnCode ody_tsns_dqs_period(
        const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb,
        const uint32_t i_tsns_period_ms,
        const uint8_t i_dqs_period )
    {
        fapi2::ReturnCode l_rc;
        char l_targStr[fapi2::MAX_ECMD_STRING_LEN] = {0};
        fapi2::toString(i_ocmb, l_targStr, sizeof(l_targStr));
        FAPI_INF("ENTER> ody_tsns_dqs_period: Ody=%s tsns_period=%d dqs_period=%d",
                 l_targStr, i_tsns_period_ms, i_dqs_period);

        FAPI_CALL_SUBROUTINE(l_rc,
                             ody_chipop_tsns_dqs_period,
                             i_ocmb,
                             i_tsns_period_ms,
                             i_dqs_period);
        FAPI_TRY(l_rc,
                 "Error from ody_chipop_tsns_dqs_period");

    fapi_try_exit:
        FAPI_INF("EXIT> ody_tsns_dqs_period: Ody=%s", l_targStr);

        return fapi2::current_err;
    }

} //extern "C"
