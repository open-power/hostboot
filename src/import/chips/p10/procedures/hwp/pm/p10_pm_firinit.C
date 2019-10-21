/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_firinit.C $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file p10_pm_firinit.C
/// @brief  Calls firinit procedures to configure the FIRs to predefined types
//
// *HWP HW Owner        :   Greg Still <stillgs@us.ibm.com>
// *HWP Backup Owner    :   Prasad BG Ranganath <prasadbgr@in.ibm.com>
// *HWP FW Owner        :   Prem S Jha <premjha2@in.ibm.com>
// *HWP Team            :   PM
// *HWP Level           :   1
// *HWP Consumed by     :   HS

///
/// High-level procedure flow:
///
/// @verbatim
///     - call p10_pm_pba_firinit.C
///     - evaluate RC
///
///     - call p10_pm_qme_firinit.C
///     - evaluate RC
///
///  @endverbatim
///
///  Procedure Prereq:
///  - System clocks are running
///

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <p10_pm_firinit.H>

// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------
fapi2::ReturnCode p10_pm_firinit(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const pm::PM_FLOW_MODE i_mode)
{
    FAPI_IMP("p10_pm_firinit start");

    FAPI_INF("p10_pm_firinit end");
    return fapi2::current_err;
} // END p10_pm_firinit
