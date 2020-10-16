/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/corecache/p10_ncu_enable_darn.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
#ifndef _P10_NCU_ENABLE_DARN_H_
#define _P10_NCU_ENABLE_DARN_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_ncu_enable_darn_FP_t) (
    const fapi2::Target <fapi2::TARGET_TYPE_CORE> i_core_target,
    const fapi2::Target <fapi2::TARGET_TYPE_PROC_CHIP> i_chip_target);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

///
/// @brief
///
/// @param[in] i_core_target  Reference to fapi2::TARGET_TYPE_CORE which defines
///                           NCU to enable for DARN instruction support
/// @param[in] i_chip_target  Reference to fapi2::TARGET_TYPE_CHIP which defines
///                           chip which above NCU should target for random
///                           numbers via DARN
/// @return fapi::ReturnCode  FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p10_ncu_enable_darn(
        const fapi2::Target <fapi2::TARGET_TYPE_CORE> i_core_target,
        const fapi2::Target <fapi2::TARGET_TYPE_PROC_CHIP> i_chip_target);

} // extern "C"

#endif // _P10_NCU_ENABLE_DARN_H_
