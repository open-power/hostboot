/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_firinit.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file p9_pm_firinit.H
/// @brief  common .H file for all FIRINITS
///
// *HWP HWP Owner: Amit Kumar <akumar3@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner: Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 3
// *HWP Consumed by: HS

#ifndef _P9_PM_FIRINIT_H_
#define _P9_PM_FIRINIT_H_
//------------------------------------------------------------------------------
//
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>
#include <p9_pm.H>
#include <p9_perv_scom_addresses.H>
#include <p9_misc_scom_addresses.H>

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_pm_firinit_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    const p9pm::PM_FLOW_MODE);

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
///        p9_pm_pba_firinit
///        p9_pm_ppm_firinit
///        p9_pm_cme_firinit
///
/// @param[in] i_target   Chip target which will be passed to all the procedures
/// @param[in] i_mode     Control mode for the procedure:
///                       PM_INIT, PM_RESET
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_pm_firinit(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const p9pm::PM_FLOW_MODE i_mode);

} // extern "C"

#endif //_P9_PM_FIRINIT_H_
