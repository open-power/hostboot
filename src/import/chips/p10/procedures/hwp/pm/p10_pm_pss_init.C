/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_pss_init.C $    */
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
/// @file p10_pm_pss_init.C
/// @brief Initializes P2S and HWC logic
///
// *HWP HW Owner        :   Greg Still <stillgs@us.ibm.com>
// *HWP Backup Owner    :   Prasad BG Ranganath <prasadbgr@in.ibm.com>
// *HWP FW Owner        :   Prem S Jha <premjha2@in.ibm.com>
// *HWP Team            :   PM
// *HWP Level           :   1
// *HWP Consumed by     :   HS

// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include <p10_pm_pss_init.H>

// -----------------------------------------------------------------------------
// Function prototypes
// -----------------------------------------------------------------------------

//------------------------------------------------------------------------------
///
/// @brief Using configured attributed, performs the startialization of the PSS
///        function
///
/// @param[in] i_target Chip target
///
/// @return FAPI2_RC_SUCCESS on success, else error.
///
fapi2::ReturnCode pm_pss_start(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

//------------------------------------------------------------------------------
///
/// @brief Performs the halt of the PSS function
///
/// @param[in] i_target Chip target
///
/// @return FAPI2_RC_SUCCESS on success, else error.
///
fapi2::ReturnCode pm_pss_halt(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);


// -----------------------------------------------------------------------------
// Function defstartions
// -----------------------------------------------------------------------------

fapi2::ReturnCode p10_pm_pss_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const pm::PM_FLOW_MODE i_mode)
{
    FAPI_IMP(">> p10_pm_pss_init");

    // Initialization:  perform order or dynamic operations to startialize
    // the PMC using necessary Platform or Feature attributes.
    if (i_mode == pm::PM_START)
    {
        FAPI_TRY(pm_pss_start(i_target), "Failed to start the PSS logic");
    }
    // Reset:  perform halt of PSS
    else if (i_mode == pm::PM_HALT)
    {
        FAPI_TRY(pm_pss_halt(i_target), "Failed to halt PSS logic.");
    }

fapi_try_exit:
    FAPI_IMP("<< p10_pm_pss_init");
    return fapi2::current_err;
}

fapi2::ReturnCode pm_pss_start(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_IMP(">> pm_pss_start Enter");


    FAPI_IMP("<< pm_pss_start");
    return fapi2::current_err;
}


fapi2::ReturnCode pm_pss_halt(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_IMP(">> pm_pss_halt");

    FAPI_IMP(" << pm_pss_halt");
    return fapi2::current_err;
}
