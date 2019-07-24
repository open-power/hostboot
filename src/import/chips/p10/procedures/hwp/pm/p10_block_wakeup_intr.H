/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_block_wakeup_intr.H $ */
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
/// @file  p10_block_wakeup_intr.H
/// @brief Enable/Disable block stop entry/exit protocol
///         associated with an core chiplet
///
// *HWP HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner : Prasad Bg Ranganath <prasadbgr@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 2
// *HWP Consumed by: FSP:HS
///
///-----------------------------------------------------------------------------

#ifndef _P10_BLKWKUP_H_
#define _P10_BLKWKUP_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi2.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

namespace p10pmblockwkup
{

enum OP_TYPE
{
    ENABLE_BLOCK_EXIT   = 0,
    DISABLE_BLOCK_EXIT  = 1,
    ENABLE_BLOCK_ENTRY  = 2,
    DISABLE_BLOCK_ENTRY = 3,
    NONE = 0xFF,
};


} // namespace p10pmblockwkup



// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_block_wakeup_intr_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>&,
    const p10pmblockwkup::OP_TYPE);

extern "C"
{

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------

/// @brief @brief Set/reset the Block Wake-up function in the QME for the
//                targeted core.
///
/// @param[in] i_core_target    Core target
/// @param[in] i_operation      option to enable/disable stop exit/entry
///                             protocol
///
/// @return FAPI2_RC_SUCCESS if success, else error code.

    fapi2::ReturnCode
    p10_block_wakeup_intr(
        const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_core_target,
        const p10pmblockwkup::OP_TYPE i_operation);

} // extern "C"

#endif // _P10_BLKWKUP_H_
