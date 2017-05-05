/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_occ_firinit.H $   */
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
/// @file p9_pm_occ_firinit.C
/// @brief Configures the OCC LFIR Mask and Action
///
// *HWP HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP Backup HWP Owner : Amit Kumar <akumar3@us.ibm.com>
// *HWP FW  Owner: Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 3
// *HWP Consumed by: HS
//

#ifndef _P9_PM_OCC_FIRINIT_H_
#define _P9_PM_OCC_FIRINIT_H_

#include <fapi2.H>
#include <p9_pm.H>
#include <p9_pm_fir_class.H>

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_pm_occ_firinit_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    const p9pm::PM_FLOW_MODE);

extern "C" {
//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------
/// @brief  Configures the OCC LFIR Mask and Action
/// param[in] i_target   Chip Target
/// param[in] i_mode     Control mode for the procedure
/// @return FAPI2_RC_SUCCESS in case of success, error code otherwise

    fapi2::ReturnCode p9_pm_occ_firinit(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const p9pm::PM_FLOW_MODE i_mode);

} // extern "C"

#endif
