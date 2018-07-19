/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/perv/p9_core_checkstop_handler.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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

#include "p9_core_checkstop_handler.H"

#include "p9_const_common.H"
#include <p9_quad_scom_addresses.H>
fapi2::ReturnCode p9_core_checkstop_handler(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target_core,
    bool i_override_restore)
{
    FAPI_INF("Entering ...");

    fapi2::buffer<uint64_t> l_action0;
    fapi2::buffer<uint64_t> l_action1;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    //if true, save off the original action, and turn local xstops into system xstops.
    if(i_override_restore == CORE_XSTOP_HNDLR__SAVE_AND_ESCALATE)
    {
        // Getting ACTION0
        FAPI_TRY(fapi2::getScom(i_target_core, C_CORE_ACTION0, l_action0),
                 "Error from getScom (C_CORE_ACTION0)");

        // Getting ACTION1
        FAPI_TRY(fapi2::getScom(i_target_core, C_CORE_ACTION1, l_action1),
                 "Error from getScom (C_CORE_ACTION1");

        // We want to save the original actions into an attribute for a save-restore
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_ORIG_FIR_SETTINGS_ACTION0, FAPI_SYSTEM, l_action0),
                 "Error from FAPI_ATTR_SET (ATTR_ORIG_FIR_SETTINGS_ACTION0)");

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_ORIG_FIR_SETTINGS_ACTION1, FAPI_SYSTEM, l_action1),
                 "Error from FAPI_ATTR_SET (ATTR_ORIG_FIR_SETTINGS_ACTION1)");

        // For every bit, turn every local xstop (0b11) into system xstops (0b00)
        uint64_t l_local_xstop = l_action0 & l_action1; //gets bits that are both set to 1
        l_action0 &= ~l_local_xstop;
        l_action1 &= ~l_local_xstop;
    }
    else
    {
        // We want to pull out the original actions, and restore them
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ORIG_FIR_SETTINGS_ACTION0, FAPI_SYSTEM, l_action0),
                 "Error from FAPI_ATTR_SET (ATTR_ORIG_FIR_SETTINGS_ACTION0)");

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ORIG_FIR_SETTINGS_ACTION1, FAPI_SYSTEM, l_action1),
                 "Error from FAPI_ATTR_SET (ATTR_ORIG_FIR_SETTINGS_ACTION1)");

    }

    // Save off the current values of actions into the register
    FAPI_TRY(fapi2::putScom(i_target_core, C_CORE_ACTION0, l_action0),
             "Error from putScom (C_CORE_ACTION0");

    FAPI_TRY(fapi2::putScom(i_target_core, C_CORE_ACTION1, l_action1),
             "Error from putScrom (C_CORE_ACTION1)");

    FAPI_INF("Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}
