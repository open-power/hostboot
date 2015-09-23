/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_occ_firinit.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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
/// @file p9_pm_occ_firinit.C
/// @brief Configures the OCC LFIR Mask and Action
///
// *HWP HWP Owner: Jim Yacynych <jimyac@us.ibm.com>
// *HWP FW  Owner: Sunil Kumar  <skumar8j@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 1
// *HWP Consumed by: HS
//

/// \todo
/// High-level procedure flow:
/// \verbatim
///
/// Procedure Prereq:
///   o System clocks are running
/// \endverbatim
///

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include "p9_pm_occ_firinit.H"

// ----------------------------------------------------------------------
// Constant definitions
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Macro definitions
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Global variables
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Function prototypes
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------

fapi2::ReturnCode p9_pm_occ_firinit(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9pm::P9_PM_FLOW_MODE i_mode)
{
    FAPI_IMP("p9_pm_occ_firinit Enter");

    FAPI_IMP("p9_pm_occ_firinit Exit");
    return fapi2::FAPI2_RC_SUCCESS;
} // end p9_pm_occ_firinit
