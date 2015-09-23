/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_reset.H $         */
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
/// @file p9_pm_reset.H
/// @brief Wrapper that calls underlying HWPs to perform a Power Management
///        Reset function when needing to restart the OCC complex.
///
// *HWP HWP Owner        : Greg Still <stillgs@us.ibm.com>
// *HWP HWP Backup Owner :
// *HWP FW Owner         : Bilicon Patil <bilpatil@in.ibm.com>
// *HWP Team             : PM
// *HWP Level            : 1
// *HWP Consumed by      : HS

#ifndef _P9_PM_RESET_H
#define _P9_PM_RESET_H

// -----------------------------------------------------------------------------
// Constant definitions
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include <p9_pm.H>
#include <fapi2.H>

extern "C"
{
//------------------------------------------------------------------------------
///
/// p9_pm_reset Call underlying unit procedures to perform readiness for
///             reinitialization of PM complex.
///
/// @param[in] i_target Primary Chip target which will be passed
///                     to all the procedures
/// @param[in] i_mode (PM_RESET (hard - will kill the PMC);
///                    PM_RESET_SOFT (will not fully reset the PMC))
///
/// @return FAPI2_RC_SUCCESS on success, else error code.
///
    fapi2::ReturnCode p9_pm_reset(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const uint32_t i_mode);
}

#endif // _P9_PM_RESET_H
