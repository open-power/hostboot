/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_init.H $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
/// @file p9_pm_init.H
/// @brief Wrapper that calls underlying HWPs to perform a Power Management
///        Init function when needing to initialize the OCC complex.
///
// *HWP HWP Owner        : Greg Still <stillgs@us.ibm.com>
// *HWP HWP Backup Owner :
// *HWP FW Owner         : Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team             : PM
// *HWP Level            : 1
// *HWP Consumed by      : HS

#ifndef _P9_PM_INIT_H
#define _P9_PM_INIT_H

// -----------------------------------------------------------------------------
// Constant definitions
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include <p9_pm.H>
#include <fapi2.H>

// Function pointer defintion
typedef fapi2::ReturnCode (*p9_pm_init_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    const p9pm::PM_FLOW_MODE);

extern "C"
{
//------------------------------------------------------------------------------
///
/// @brief Call underlying unit procedures to perform readiness for
///             initialization of PM complex.
///
/// @param[in] i_target Primary Chip target which will be passed
///                     to all the procedures
/// @param[in] i_mode   (PM_INIT / PM_RESET)
///
/// @return FAPI2_RC_SUCCESS on success, else error code.
///
    fapi2::ReturnCode p9_pm_init(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const p9pm::PM_FLOW_MODE i_mode);
}

#endif // _P9_PM_INIT_H
