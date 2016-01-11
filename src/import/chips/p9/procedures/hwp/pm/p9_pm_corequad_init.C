/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_corequad_init.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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
/// @file  p9_pm_corequad_init.C
/// @brief Establish safe settings for Core and Quad.
///
// *HWP HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner: Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 1
// *HWP Consumed by: HS

// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include <p9_pm_corequad_init.H>

// -----------------------------------------------------------------------------
// Function prototypes
// -----------------------------------------------------------------------------

// Reset function
///
/// @brief Stop the CMEs and clear the CME FIRs, PPM Errors and their masks
///        for all functional and enabled EX chiplets
///
/// @param[in] i_target Proc Chip target
///
/// @return FAPI2_RC_SUCCESS on success or error return code
///
fapi2::ReturnCode pm_corequad_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

// Init function
///
/// @brief Setup the CME and PPM Core & Quad for all functional and enabled
///        EX chiplets
///
/// @param[in] i_target Proc Chip target
///
/// @return FAPI2_RC_SUCCESS on success or error return code
///
fapi2::ReturnCode pm_corequad_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------

fapi2::ReturnCode p9_pm_corequad_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9pm::PM_FLOW_MODE i_mode)
{
    FAPI_IMP("Entering p9_pm_corequad_init...");

    FAPI_IMP("Exiting p9_pm_corequad_init...");
    return fapi2::current_err;
}

fapi2::ReturnCode pm_corequad_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_IMP("Entering pm_corequad_init...");

    return fapi2::current_err;
}

fapi2::ReturnCode pm_corequad_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_IMP("Entering pm_corequad_reset...");

    return fapi2::current_err;
}
