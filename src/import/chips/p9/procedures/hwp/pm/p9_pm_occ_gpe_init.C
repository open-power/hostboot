/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_occ_gpe_init.C $  */
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
/// @file p9_pm_occ_gpe_init.C
/// @brief Configure or reset the targeted GPE0 and/or GPE1
///
// *HWP HWP Owner: Greg Still  <stillgs@us.ibm.com>
// *HWP FW  Owner: Sunil Kumar <skumar8j@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 1
// *HWP Consumed by: HS

///
/// todo add to required proc ENUM requests
///
/// High-level procedure flow:
/// \verbatim
///
///     Check for valid parameters
///     if PM_CONFIG {
///        Do nothing (done by OCC programs)
///     } else if PM_RESET {
///         for each GPE,
///             set and then reset bit 0 in the GPEx_RESET_REGISTER
///
///     }
///
///  Procedure Prereq:
///     - System clocks are running
/// \endverbatim
///

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------

#include "p9_pm_occ_gpe_init.H"

// ----------------------------------------------------------------------
// Constant definitions
// ----------------------------------------------------------------------

// ----------------------------------------------------------------------
// Global variables
// ----------------------------------------------------------------------

enum POREGPE_ENGINES
{
    GPE0        = 0x0,
    GPE1        = 0x1,
    GPEALL      = 0XF
};

// ----------------------------------------------------------------------
// Function prototypes
// ----------------------------------------------------------------------

fapi2::ReturnCode pm_occ_gpe_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint32_t i_engine);

// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------

fapi2::ReturnCode p9_pm_occ_gpe_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9pm::P9_PM_FLOW_MODE i_mode, const uint32_t i_engine)
{
    FAPI_IMP("p9_pm_occ_gpe_init Enter");

    FAPI_IMP("p9_pm_occ_gpe_init Exit");
    return fapi2::FAPI2_RC_SUCCESS;
}

//--------------------------------------------------------------------------
/// PORE GPE Reset Function
//--------------------------------------------------------------------------
/// @brief Reset the targeted GPE0 and/or GPE1
///
/// param[in] i_target   Chip target
/// param[in] i_engine   Targeted engine:  GPE0, GPE1, GPEALL
///
/// @return FAPI2_RC_SUCCESS incase of success
///         error code otherwise

fapi2::ReturnCode
pm_occ_gpe_reset(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                 const uint32_t i_engine)
{
    FAPI_IMP("pm_occ_gpe_reset Enter");

    return fapi2::FAPI2_RC_SUCCESS;
}
