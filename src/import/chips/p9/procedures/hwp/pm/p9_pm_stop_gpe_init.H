/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_stop_gpe_init.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
/// @file  p9_pm_stop_gpe_init.H
/// @brief Initialize the STOP GPE Engine in the OCC
///
// *HWP HWP Owner: Amit Kumar <akumar3@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner: Bilicon Patil <bilpatil@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 1
// *HWP Consumed by: FSP:HS
///
///-----------------------------------------------------------------------------

#ifndef _P9_STOP_GPEINIT_H_
#define _P9_STOP_GPEINIT_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <p9_pm.H>
#include <fapi2.H>
#include <p9_quad_scom_addresses.H>
#include <p9_quad_scom_addresses_fld.H>
#include <p9_misc_scom_addresses.H>
#include <p9_misc_scom_addresses_fld.H>

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_pm_stop_gpe_init_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    const p9pm::PM_FLOW_MODE);

extern "C" {


// -----------------------------------------------------------------------------
//  Function prototype
// -----------------------------------------------------------------------------

/// @addtogroup pm_fapi
/// @{

/// @brief Initialize the STOP GPE Engine in the OCC
///
/// High-level procedure flow:
///
///     - Check for valid parameters
///     - PM_INIT
///         - Nothing defined
///     - PM_RESET
///         - write to XSR register to reset the PPE
///
///  Procedure Prereq:
///     - System clocks are running
///
/// @param [in] i_target    Chip target
/// @param [in] i_mode      Control mode PM_INIT, PM_RESET
///
/// @retval FAPI2_RC_SUCCESS
/// @retval RC_PROCPM_GPE_CODE_BAD_MODE
    fapi2::ReturnCode p9_pm_stop_gpe_init(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const p9pm::PM_FLOW_MODE i_mode);

/// @}  end addtogroup

} // extern "C"

#endif // _P9_STOP_GPEINIT_H_
