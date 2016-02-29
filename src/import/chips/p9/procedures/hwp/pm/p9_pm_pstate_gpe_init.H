/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_pstate_gpe_init.H $ */
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
/// @file  p9_pm_pstate_gpe_init.H
/// @brief Initialize the STOP GPE Engine in the OCC
///
// *HWP HWP Owner:          Greg Still <stillgs@us.ibm.com>
// *HWP BackupHWP Owner:    Amit Kumar <akumar3@us.ibm.com>
// *HWP FW Owner:           Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 2
// *HWP Consumed by: FSP:HS
///
/// High-level procedure flow:
/// @verbatim
///   if PM_RESET
///   - Halt the PGPE
///   if PM_INIT
///   - Read the PGPE IVPR value, the address of boot copier in HOMER region.
///   - clear OCC Scratch2 flag indicating HCode init completion.
///   - Write to XCR to activate the PGPE
///   - Poll OCC Scratch 2 flag for HCode init completion
///   - Call p9_pm_pba_init in PM_INIT mode to activate the PBA channels for
///     runtime configuration.
/// @endverbatim

#ifndef _P9_PSTATE_GPEINIT_H_
#define _P9_PSTATE_GPEINIT_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <p9_pm.H>
#include <fapi2.H>
#include <p9_misc_scom_addresses.H>
#include <p9_hcd_common.H>
#include <p9_pm_hcd_flags.h>
#include <p9_pm_pba_init.H>


// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_pm_pstate_gpe_init_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    const p9pm::PM_FLOW_MODE);

// -----------------------------------------------------------------------------
//  Function prototype
// -----------------------------------------------------------------------------
extern "C" {

/// @addtogroup pm_fapi
/// @{

/// @brief Initialize the Pstate GPE Engine in the OCC
///
/// @param [in] i_target    Chip target
/// @param [in] i_mode      Control mode PM_INIT, PM_RESET
///
/// @retval FAPI2_RC_SUCCESS on success, else error RC
///
    fapi2::ReturnCode p9_pm_pstate_gpe_init(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const p9pm::PM_FLOW_MODE i_mode);

/// @}  end addtogroup

} // extern "C"

#endif // _P9_PSTATE_GPEINIT_H_
