/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/sppe/ody_chipop_tsns_dqs_period.H $ */
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
/// @file ody_chipop_tsns_dqs_period.H
/// @brief Odyssey Chipop Modify Temperature Sensor and/or DQS Drift Tracking Polling Period
///
// *HWP Owner: Hostboot Team
// *HWP Backup: SBE Team
// *HWP Level: 3
// *HWP Consumed by: HB:Cronus

#ifndef _ODY_CHIPOP_TSNS_DQS_PERIOD_
#define _ODY_CHIPOP_TSNS_DQS_PERIOD_

#include <ody_tsns_dqs_period.H>

#include <fapi2.H>

// Required for Cronus linkage
typedef fapi2::ReturnCode (*ody_chipop_tsns_dqs_period_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const uint32_t i_tsns_period_ms,
    const uint8_t i_dqs_period
);

extern "C"
{
///
/// @brief Execute chipop to modify the Odyssey temperature sensor and/or
///       DQS drift tracking polling period.
///
/// @param[in] i_ocmb  Odyssey chip being queried
/// @param[out] o_sppeCLIPData  Vector of sppeCLIP_t returned from chipop
/// @return FAPI2_RC_SUCCESS if ok
///
    fapi2::ReturnCode ody_chipop_tsns_dqs_period(
        const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const uint32_t i_tsns_period_ms,
        const uint8_t i_dqs_period
    );

}//extern C

#endif
