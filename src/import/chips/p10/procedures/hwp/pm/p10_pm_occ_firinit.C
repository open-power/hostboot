/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_occ_firinit.C $ */
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
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p10/procedures/hwp/pm/p10_pm_occ_firinit.C $            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2019                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///
/// @file p10_pm_occ_firinit.C
/// @brief Configures the OCC LFIR Mask and Action
///
// *HWP HW Owner        :   Greg Still <stillgs@us.ibm.com>
// *HWP Backup Owner    :   Prasad BG Ranganath <prasadbgr@in.ibm.com>
// *HWP FW Owner        :   Prem S Jha <premjha2@in.ibm.com>
// *HWP Team            :   PM
// *HWP Level           :   1
// *HWP Consumed by     :   HS

/// High-level procedure flow:
/// @verbatim
///   if reset:
///      Mask all bits of FIR
///   else if init:
///      Establish the respective mask/action bits for the following settings:
///          1) Checkstop
///          2) Malf Alert
///          3) Recoverable Attention
///          4) Recoverable Interrupt
/// @endverbatim
///
/// Procedure Prereq:
///   o System clocks are running
///

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <p10_pm_occ_firinit.H>

// ----------------------------------------------------------------------
// Constant definitions
// ----------------------------------------------------------------------


enum OCC_FIR_BITS
{

};

// ----------------------------------------------------------------------
// Function prototypes
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------

fapi2::ReturnCode p10_pm_occ_firinit(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const pm::PM_FLOW_MODE i_mode)
{
    FAPI_IMP("p10_pm_occ_firinit Enter");

    FAPI_IMP("p10_pm_occ_firinit Exit");
    return fapi2::current_err;
}
