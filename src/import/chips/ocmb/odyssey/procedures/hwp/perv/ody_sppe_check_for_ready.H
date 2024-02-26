/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/perv/ody_sppe_check_for_ready.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2024                        */
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
/// @file  ody_sppe_check_for_ready.H
/// @brief Confirm SPPE boot progress
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Anusha Reddy (anusrang@in.ibm.com)
// *HWP FW Maintainer   : Raja Das (rajadas2@in.ibm.com)
//------------------------------------------------------------------------------

#pragma once

#include <fapi2.H>

typedef fapi2::ReturnCode (*ody_sppe_check_for_ready_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&);

/// @brief Confirm SPPE boot progress
///
/// @param[in]   i_target                  Reference to TARGET_TYPE_OCMB_CHIP
///
/// @param[in]   i_isHreset        To check Hreset bit is set or not , default is false
//
/// @return  FAPI2_RC_SUCCESS if success, else error code.
extern "C"
{
    fapi2::ReturnCode ody_sppe_check_for_ready(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
            const bool i_isHreset = false);
}
