/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/perv/ody_sbe_hreset.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2023                        */
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
//------------------------------------------------------------------------------
/// @file  ody_sbe_hreset.H
/// @brief Applies hreset for Ody Chip
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Swathips (swathi@in.ibm.com)
// *HWP FW Maintainer   : Amit Tendolkar (amit.tendolkar@in.ibm.com)
//------------------------------------------------------------------------------

#pragma once

#include <fapi2.H>

typedef fapi2::ReturnCode (*ody_sbe_hreset_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&, bool);

/// @brief       Applying hreset for Ody chip
/// @param[in]   i_target         Reference to TARGET_TYPE_OCMB_CHIP
/// @param[in]   i_use_scom_path  Set it to true to use SCOM Path (Default is CFAM Path)
/// @return  FAPI2_RC_SUCCESS if success, else error code.

extern "C"
{
    fapi2::ReturnCode ody_sbe_hreset(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                     bool i_use_scom_path = false);

}
