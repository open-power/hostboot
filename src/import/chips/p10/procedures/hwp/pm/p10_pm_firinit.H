/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_firinit.H $     */
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
/// @file p10_pm_firinit.H
/// @brief  common .H file for all FIRINITS
///
// *HWP HW Owner        :   Greg Still <stillgs@us.ibm.com>
// *HWP Backup Owner    :   Prasad BG Ranganath <prasadbgr@in.ibm.com>
// *HWP FW Owner        :   Prem S Jha <premjha2@in.ibm.com>
// *HWP Team            :   PM
// *HWP Level           :   1
// *HWP Consumed by     :   HS

#ifndef _P10_PM_FIRINIT_H_
#define _P10_PM_FIRINIT_H_
//------------------------------------------------------------------------------
//
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>
#include <p10_pm.H>

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_pm_firinit_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    const pm::PM_FLOW_MODE);

extern "C"
{
//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
///
/// @brief Calls each PM unit firinit procedures based on the input mode,
///        to configure the FIRs of the chip to  predefined types.
///        The procedures invoked are:
///        p10_pm_pba_firinit
///        p10_pm_ppm_firinit
///        p10_pm_cme_firinit
///
/// @param[in] i_target   Chip target which will be passed to all the procedures
/// @param[in] i_mode     Control mode for the procedure:
///                       PM_INIT, PM_RESET
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p10_pm_firinit(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const pm::PM_FLOW_MODE i_mode);

} // extern "C"

#endif //_P10_PM_FIRINIT_H_
