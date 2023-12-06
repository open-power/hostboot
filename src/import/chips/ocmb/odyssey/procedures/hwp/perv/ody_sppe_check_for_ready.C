/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/perv/ody_sppe_check_for_ready.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2023                        */
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
//------------------------------------------------------------------------------
/// @file  ody_sppe_check_for_ready.C
/// @brief Confirm SPPE boot progress
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Anusha Reddy (anusrang@in.ibm.com)
// *HWP FW Maintainer   : Raja Das (rajadas2@in.ibm.com)
//------------------------------------------------------------------------------

#include <ody_sppe_check_for_ready.H>
#include <poz_sppe_check_for_ready.H>

using namespace fapi2;

enum ODY_SPPE_BOOT_CHECK_Private_Constants
{
    MAX_POLLS = 100,
    MAX_SIMICS_POLLS = 1500,
    POLL_DELAY_CYCLES = 10000000, // 10m
    POLL_DELAY_NS = 1000000000,   // 1s
};

ReturnCode ody_sppe_check_for_ready(
    const Target<TARGET_TYPE_OCMB_CHIP>& i_target)
{
    poz_sppe_boot_parms l_boot_parms;
    Target<TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    FAPI_DBG("Entering...");

    // fill common boot parms structure
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OCMB_BOOT_FLAGS, i_target, l_boot_parms.boot_flags));
    l_boot_parms.max_polls = MAX_POLLS;
    l_boot_parms.poll_delay_cycles = POLL_DELAY_CYCLES;
    l_boot_parms.poll_delay_ns = POLL_DELAY_NS;

    // SIMICS workaround
    fapi2::ATTR_IS_SIMICS_Type l_simics;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMICS, FAPI_SYSTEM, l_simics),
             "ody_sppe_check_for_ready: Error from FAPI_ATTR_GET (ATTR_IS_SIMICS)");

    if (l_simics == fapi2::ENUM_ATTR_IS_SIMICS_SIMICS)
    {
        //  Since the delay in poz_sppe_check_for_ready is much less in simics,
        //   we must increase the number of polls to allow enough time
        l_boot_parms.max_polls = MAX_SIMICS_POLLS;
    }

    // call common HWP
    FAPI_TRY(poz_sppe_check_for_ready(i_target, l_boot_parms));

fapi_try_exit:
    FAPI_DBG("Exiting...");
    return current_err;
}
