/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/sppe/ody_chipop_getcodelevels.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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
/// @file ody_chipop_getcodelevels.H
/// @brief Odyssey Chipop Get Code Levels
///
// *HWP Owner: Hostboot Team
// *HWP Backup: SBE Team
// *HWP Level: 1
// *HWP Consumed by: HB:Cronus

#ifndef _ODY_CHIPOP_GETCODELEVELS_
#define _ODY_CHIPOP_GETCODELEVELS_

#include <ody_code_update.H>

#include <fapi2.H>

// Required for Cronus linkage
typedef fapi2::ReturnCode (*ody_chipop_getcodelevels_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    std::vector<sppeCLIP_t>& o_sppeCLIPdata
);

extern "C"
{
///
/// @brief Execute chipop to retrieve the code levels from the Odyssey
///       firmware images.
///
/// @param[in] i_ocmb  Odyssey chip being queried
/// @param[out] o_sppeCLIPData  Vector of sppeCLIP_t returned from chipop
/// @return FAPI2_RC_SUCCESS if ok
///
    fapi2::ReturnCode ody_chipop_getcodelevels(
        const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        std::vector<sppeCLIP_t>& o_sppeCLIPdata
    );

}//extern C

#endif
