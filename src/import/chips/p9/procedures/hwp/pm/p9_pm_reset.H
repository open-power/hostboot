/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_reset.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2018                        */
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
// *HWP HWP Backup Owner : Prasad BG Ranganath <prasadbgr@in.ibm.com>
// *HWP FW Owner         : Prem S Jha <premjha2@in.ibm.com>
// *HWP Team             : PM
// *HWP Level            : 3
// *HWP Consumed by      : HS

#ifndef _P9_PM_RESET_H
#define _P9_PM_RESET_H

// -----------------------------------------------------------------------------
// Constant definitions
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include <fapi2.H>
#include <p9_pm.H>
#include <p9_pm_utils.H>
#include <p9_misc_scom_addresses.H>
#include <p9_pm_occ_firinit.H>
#include <p9_pm_firinit.H>
#include <p9_pm_occ_control.H>
#include <p9_pm_stop_gpe_init.H>
#include <p9_pm_occ_gpe_init.H>
#include <p9_pm_corequad_init.H>
#include <p9_pm_occ_sram_init.H>
#include <p9_pm_ocb_init.H>
#include <p9_pm_pss_init.H>
#include <p9_pm_pstate_gpe_init.H>

typedef fapi2::ReturnCode (*p9_pm_reset_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    void* i_pHomerImage);

// -----------------------------------------------------------------------------
// Function Prototype
// -----------------------------------------------------------------------------
extern "C"
{
//------------------------------------------------------------------------------
///
/// @brief Call underlying unit procedures to reset PM complex
///
/// @param[in] i_target Proc Chip target
/// @param[in] i_pHomerImage pointer to the beginning of the HOMER image buffer
///
/// @return FAPI2_RC_SUCCESS on success, else error code.
///
    fapi2::ReturnCode p9_pm_reset(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        void* i_pHomerImage);

//------------------------------------------------------------------------------
///
/// @brief PSAFE values update of DPLL and External voltage
///
/// @param[in] i_target Proc Chip target
///
/// @return FAPI2_RC_SUCCESS on success, else error code.
    fapi2::ReturnCode p9_pm_reset_psafe_update(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

//------------------------------------------------------------------------------
///
/// @brief Walk through each EX chiplet (and each core within an EX) to determine
/// if special wake-up done is asserted.  If so, set auto special wake-up mode to
/// protect the core(s) while the PM complex is being reset
///
/// @param[in] i_target Proc Chip target
///
/// @return FAPI2_RC_SUCCESS on success, else error code.
    fapi2::ReturnCode p9_pm_set_auto_spwkup(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

//------------------------------------------------------------------------------
///
/// @brief Call utilities to collect PM complex FFDC to FFDC section in HOMER
///
/// @param[in] i_target Proc Chip target
/// @param[in] i_pHomerImage pointer to the beginning of the HOMER image buffer
/// @param[in] i_plat Platform Id indicating which part of the PM Complex to collect.
///                   See p9_stop_recov_ffdc::PmComplexPlatId for details
///
/// @return FAPI2_RC_SUCCESS on success, else error code.
///
    fapi2::ReturnCode p9_pm_collect_ffdc (
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        void* i_pHomerImage,
        const uint8_t i_plat );
}

#endif // _P9_PM_RESET_H
