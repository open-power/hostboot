/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/perv/ody_cbs_start.C $ */
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
/// @file  ody_cbs_start.C
/// @brief Start CFAM boot sequencer
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Daniela Yacovone (falconed@us.ibm.com)
// *HWP FW Maintainer   : Raja Das (rajadas2@in.ibm.com)
//------------------------------------------------------------------------------

#include <ody_cbs_start.H>
#include <poz_perv_common_params.H>
#include <poz_perv_mod_misc.H>

using namespace fapi2;

enum ODY_CBS_START_Private_Constants
{
};

ReturnCode ody_cbs_start(const Target<TARGET_TYPE_OCMB_CHIP>& i_target, bool i_start_sbe, bool i_scan0_clockstart)
{
    FAPI_INF("Entering ...");
    FAPI_TRY(mod_cbs_start(i_target, i_start_sbe, i_scan0_clockstart));

fapi_try_exit:
    FAPI_INF("Exiting ...");
    return current_err;
}
