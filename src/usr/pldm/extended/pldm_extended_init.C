/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/extended/pldm_extended_init.C $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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

/**
 * @file pldm_extended_init.C
 *
 * @brief Source code for function that will be called when the pldm_extended module
 *        is loaded by the init service.
 *
 */

#include "pldm_responder.H"
#include <initservice/taskargs.H>
#include <pldm/pldmif.H>
#include <pldm/extended/pdr_manager.H>

namespace PLDM
{

/**
* @brief This is the function that gets called when pldm_extended is loaded by
*        initservice. It initializes the pldm responder task.
*/
static void extended_init(errlHndl_t& o_errl)
{
    // This will call the pldmResponder
    Singleton<pldmResponder>::instance().init();

    // Sync PLDM states on shutdown
    PLDM::registerShutdownCallback([](void*) { thePdrManager().sendAllFruFunctionalStates(); }, nullptr);
}

}

TASK_ENTRY_MACRO( PLDM::extended_init );
