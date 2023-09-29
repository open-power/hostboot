/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/perv/ody_sbe_hreset.C $ */
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
/// @file  ody_sbe_hreset.C
/// @brief Applies Herest during runtime
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Swathips (swathips@in.ibm.com)
// *HWP FW Maintainer   : Amit Tendolkar (amit.tendolkar@in.ibm.com)
//------------------------------------------------------------------------------

#include <ody_sbe_hreset.H>
#include <poz_sbe_hreset.H>
#include <poz_perv_common_params.H>

using namespace fapi2;

enum ODY_SBE_HRESET_Private_Constants
{
    MAX_POLLS = 25,
    POLL_DELAY_CYCLES = 10000000, // 10m
    POLL_DELAY_NS = 1000000000,   // 1s
};

ReturnCode ody_sbe_hreset(
    const Target<TARGET_TYPE_OCMB_CHIP>& i_target, bool i_use_scom_path)
{
    poz_sbe_boot_parms l_boot_parms;
    Target<TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    FAPI_DBG("Entering...");

    // fill common boot parms structure
    //FAPI_TRY(FAPI_ATTR_GET(ATTR_OCMB_BOOT_FLAGS, FAPI_SYSTEM, l_boot_parms.boot_flags));
    l_boot_parms.max_polls = MAX_POLLS;
    l_boot_parms.poll_delay_cycles = POLL_DELAY_CYCLES;
    l_boot_parms.poll_delay_ns = POLL_DELAY_NS;

    // call common HWP
    FAPI_TRY(poz_sbe_hreset(i_target, l_boot_parms, i_use_scom_path));

fapi_try_exit:
    FAPI_DBG("Exiting...");
    return current_err;
}
