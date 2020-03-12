/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/base/pldm_base_init.C $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
 * @file pldm_base_init.C
 *
 * @brief Source code for the function that will be called when the pldm_base
 *        module is loaded by the init service.
 *
 */

#include <mctp/mctpif.H>
#include "pldm_requester.H"
#include "pldm_msg_queues.H"
#include <initservice/taskargs.H>

namespace PLDM
{
/**
* @brief This is the function that gets called when pldm_base is loaded by
*        initservice. It handles registering the pldm msg queues, initializing
*        the pldm requester task, and telling the mctp layer we are ready to
*        register the lpc bus to start MCTP traffic.
*/
static void base_init(errlHndl_t& o_errl)
{
    // register g_outboundPldmReqMsgQ, g_inboundPldmRspMsgQ,
    // and g_inboundPldmReqMsgQ so external modules can resolve
    // them easily
    registerPldmMsgQs();

    // This will call the pldmRequester constructor which
    // will launch the task waiting for inbound PLDM requests
    // from the BMC
    Singleton<pldmRequester>::instance().init();

    // Notify MCTP layer that they can register the bus
    // and start MCTP traffic
    MCTP::register_mctp_bus();

    return;
}

}

TASK_ENTRY_MACRO( PLDM::base_init );
