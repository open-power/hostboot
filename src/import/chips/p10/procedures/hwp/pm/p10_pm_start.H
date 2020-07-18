/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_start.H $       */
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
/// @file p10_pm_start.H
/// @brief Wrapper that start or halt the OCC complex.
///
// *HWP HWP Owner        : Greg Still <stillgs@us.ibm.com>
// *HWP HWP Backup Owner : Prasad BG Ranganath <prasadbgr@in.ibm.com>
// *HWP FW Owner         : Prem S Jha <premjha2@in.ibm.com>
// *HWP Team             : PM
// *HWP Level            : 2
// *HWP Consumed by      : HS

#ifndef _P10_PM_START_H
#define _P10_PM_START_H

// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include <fapi2.H>
#include <p10_pm.H>
#include <p10_pm_pgpe_init.H>
#include <p10_pm_xgpe_init.H>
#include <p10_pm_qme_init.H>
#include <p10_pm_occ_control.H>
#include <p10_pm_ocb_init.H>
#include <p10_pm_pss_init.H>
#include <p10_pm_pba_init.H>
#include <p10_pm_firinit.H>
#include <p10_pm_occ_firinit.H>
#include <p10_check_proc_config.H>

// Function pointer defintion
typedef fapi2::ReturnCode (*p10_pm_start_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    void* i_pHomerImage);

extern "C"
{
//------------------------------------------------------------------------------
///
/// @brief Wrapper that initializes or resets the OCC complex.
///
/// @param[in] i_target Chip target
/// @param[in] i_pHomerImage pointer to the beginning of the HOMER image buffer
///
/// @return FAPI2_RC_SUCCESS on success, else error code.
///
    fapi2::ReturnCode p10_pm_start(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        void* i_pHomerImage);

}

#endif // _P10_PM_START_H
