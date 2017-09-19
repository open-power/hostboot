/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_corequad_init.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file  p9_pm_corequad_init.H
/// @brief Establish safe settings for Core and Quad.
///
// *HWP HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner:  Prasad BG Ranganath <prasadbgr@in.ibm.com>
// *HWP Team:      PM
// *HWP Level:     3
// *HWP Consumed by: HS

#ifndef _P9_COREQUAD_INIT_H_
#define _P9_COREQUAD_INIT_H_

// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include <fapi2.H>
#include <p9_pm.H>

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_pm_corequad_init_FP_t)
(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
 const p9pm::PM_FLOW_MODE,
 const uint32_t,
 const uint32_t,
 const uint32_t);

// -----------------------------------------------------------------------------
// Function Prototype
// -----------------------------------------------------------------------------
extern "C"
{
///
/// @brief Perform necessary actions to Core and Quad PPMs as well as CMEs
///        for reset and initialization.
///
/// @param[in] i_target      Proc Chip target
/// @param[in] i_mode        Control mode for the procedure
///                          PM_INIT, PM_RESET
/// @param[in] i_cmeFirMask  Mask value for CME FIR
///                          (applied during PM_RESET phase)
/// @param[in] i_cppmErrMask Mask value for Core PPM Error
///                          (applied during PM_RESET phase)
/// @param[in] i_qppmErrMask Mask value for Quad PPM Error
///                          (applied during PM_RESET phase)
///
/// @return FAPI2_RC_SUCCESS on success or error return code
///
    fapi2::ReturnCode p9_pm_corequad_init(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const p9pm::PM_FLOW_MODE i_mode,
        const uint32_t i_cmeFirMask,
        const uint32_t i_cppmErrMask,
        const uint32_t i_qppmErrMask);
} // extern "C"

#endif // _P9_COREQUAD_INIT_H_
