/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/sppe/ody_code_getlevels.H $ */
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
/// @file ody_code_getlevels.H
/// @brief Odyssey Code Get Levels
///
// *HWP Owner: Hostboot Team
// *HWP Backup: SBE Team
// *HWP Level: 1
// *HWP Consumed by: HB:Cronus

#ifndef _ODY_CODE_GETLEVELS_
#define _ODY_CODE_GETLEVELS_

#include <fapi2.H>
#include <stdint.h>
#include <cstring>

#include <ody_sbe_utils.H>

extern "C"
{

// Required for Cronus linkage
    typedef fapi2::ReturnCode (*ody_code_getlevels_FP_t) (
        const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        std::vector<sppeCLIP_t>& o_sppeCLIPdata
    );


///
/// @brief Execute one or more chipops to perform a code update of the Odyssey
///       firmware images.
///
/// @param[in] i_ocmb  Odyssey chip being updated
/// @param[out] o_sppeCLIPdata  Vector of hash data returned from chipop
/// @return FAPI2_RC_SUCCESS iff ok
///
    fapi2::ReturnCode ody_code_getlevels(
        const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        std::vector<sppeCLIP_t>& o_sppeCLIPdata
    );

}//extern C

#endif
