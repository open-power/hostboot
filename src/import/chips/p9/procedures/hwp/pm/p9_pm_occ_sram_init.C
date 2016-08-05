/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_occ_sram_init.C $ */
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
/// @file  p9_pm_occ_sram_init.C
/// @brief Initialize the SRAM in the OCC
///
// *HWP HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner: Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 1
// *HWP Consumed by: FSP:HS
//

// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include <p9_pm_occ_sram_init.H>

// -----------------------------------------------------------------------------
// Function definitions
// -----------------------------------------------------------------------------

fapi2::ReturnCode p9_pm_occ_sram_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9pm::PM_FLOW_MODE i_mode)
{
    FAPI_INF("Entering p9_pm_occ_sram_init...");

    // Initialization:  perform order or dynamic operations to initialize
    // the OCC SRAM using necessary Platform or Feature attributes.
    if (i_mode == p9pm::PM_INIT)
    {
        FAPI_INF("OCC SRAM initialization...");
    }
    // Reset:  perform reset of OCC SRAM so that it can reconfigured and
    // reinitialized
    else if (i_mode == p9pm::PM_RESET)
    {
        FAPI_INF("OCC SRAM reset...");
    }
    // Unsupported Mode
    else
    {
        FAPI_ASSERT(false, fapi2::PM_OCCSRAM_BAD_MODE().set_MODE(i_mode),
                    "ERROR; Unknown mode passed to p9_pm_occ_sram_init. Mode %x",
                    i_mode);
    }

fapi_try_exit:
    return fapi2::current_err;
}
