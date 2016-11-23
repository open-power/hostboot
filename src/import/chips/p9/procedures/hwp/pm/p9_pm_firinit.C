/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_firinit.C $       */
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
/// @file p9_pm_firinit.C
/// @brief  Calls firinit procedures to configure the FIRs to predefined types
///
// *HWP HWP Owner: Amit Kumar <akumar3@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner: Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 2
// *HWP Consumed by: FSP:HS

///
/// High-level procedure flow:
///
/// \verbatim
///     - call p9_pm_pba_firinit.C
///     - evaluate RC
///
///     - call p9_pm_ppm_firinit.C
///     - evaluate RC
///
///     - call p9_pm_cme_firinit.C
///     - evaluate RC
///
///  \endverbatim
///
///  Procedure Prereq:
///  - System clocks are running
///

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <p9_pm_firinit.H>
#include <p9_pm_pba_firinit.H>
#include <p9_pm_ppm_firinit.H>
#include <p9_pm_cme_firinit.H>

// ----------------------------------------------------------------------
// Function definitions
// ----------------------------------------------------------------------
fapi2::ReturnCode p9_pm_firinit(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9pm::PM_FLOW_MODE i_mode)
{
    FAPI_IMP("p9_pm_firinit start");

    fapi2::ReturnCode l_rc;
    uint8_t l_pm_firinit_flag;
    fapi2::buffer<uint64_t> l_data64;

    // CHECKING FOR FIRS BEFORE RESET and INIT
    FAPI_DBG("Checking PBA FIRs");
    FAPI_TRY(fapi2::getScom(i_target, PU_PBAFIR , l_data64),
             "ERROR: Failed to fetch PBA FIR");

    if(l_data64)
    {
        FAPI_INF("WARNING: PBA has active error(s)");
    }

    // Handle PBA FIRs, Masks and actions
    FAPI_DBG("Calling PBA firinit ...");
    FAPI_EXEC_HWP(l_rc, p9_pm_pba_firinit, i_target, i_mode);
    FAPI_TRY(l_rc);

    // Handle Core and Quad errors
    FAPI_DBG("Calling PPM firinit ...");
    FAPI_EXEC_HWP(l_rc, p9_pm_ppm_firinit, i_target, i_mode);
    FAPI_TRY(l_rc);

    // Handle CME FIRs, Masks and actions
    FAPI_DBG("Calling CME firinit ...");
    FAPI_EXEC_HWP(l_rc, p9_pm_cme_firinit, i_target, i_mode);
    FAPI_TRY(l_rc);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PM_FIRINIT_DONE_ONCE_FLAG, i_target,
                           l_pm_firinit_flag),
             "ERROR: Failed to fetch the firinit call status flag");

    // Set the ATTR_PM_FIRINIT_DONE_ONCE_FLAG attribute
    if (i_mode == p9pm::PM_INIT)
    {
        if (l_pm_firinit_flag != 1)
        {
            l_pm_firinit_flag = 1;
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PM_FIRINIT_DONE_ONCE_FLAG,
                                   i_target, l_pm_firinit_flag),
                     "ERROR: Failed to set firinit call status after init");
        }
    }
    else if (i_mode == p9pm::PM_RESET)
    {
        if (l_pm_firinit_flag != 2)
        {
            l_pm_firinit_flag = 2;
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PM_FIRINIT_DONE_ONCE_FLAG,
                                   i_target, l_pm_firinit_flag),
                     "ERROR: Failed to set firinit call status after reset");
        }
    }

fapi_try_exit:
    FAPI_INF("p9_pm_firinit end");
    return fapi2::current_err;
} // END p9_pm_firinit

