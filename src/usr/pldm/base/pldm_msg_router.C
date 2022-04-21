/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/base/pldm_msg_router.C $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2022                        */
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
 * @file pldm_msg_router.C
 *
 * @brief Source code for routing inbound PLDM messages coming from the
 *        transport layer. Providing a interface like this in the PLDM
 *        namespace allows us to keep the PLDM logic out of the MCTP namespace
 */

// System Includes
#include <sys/msg.h>
#include <cstring>
#include <cassert>
// Userspace Includes
#include <pldm/pldmif.H>
#include <pldm/pldm_reasoncodes.H>
#include <pldm/pldm_errl.H>
#include <pldm/pldm_trace.H>
#include <mctp/mctp_message_types.H>
// From src/usr/pldm/extern/
#include <base.h>

#include "pldm_msg_queues.H"

using namespace ERRORLOG;

namespace PLDM {

errlHndl_t routeInboundMsg(const pldm_mctp_message_view i_req)
{
    assert(i_req.pldm_msg_no_own != nullptr, "PLDM::routeInboundMsg nullptr passed for i_msg");
    errlHndl_t errl = nullptr;

    do {

    if (i_req.pldm_msg_size < sizeof(pldm_msg_hdr))
    {
        /*@errorlog
        * @errortype   ERRL_SEV_PREDICTIVE
        * @moduleid    MOD_ROUTE_MESSAGES
        * @reasoncode  RC_INVALID_LENGTH
        * @userdata1   actual length
        * @userdata2   minimum length
        * @devdesc     PLDM message from BMC is too small to process
        * @custdesc    A problem occurred during the IPL of the system
        */
        errl = new ErrlEntry(ERRL_SEV_PREDICTIVE,
                             MOD_ROUTE_MESSAGES,
                             RC_INVALID_LENGTH,
                             i_req.pldm_msg_size,
                             sizeof(pldm_msg_hdr),
                             ErrlEntry::NO_SW_CALLOUT);

        addBmcErrorCallouts(errl);
        break;
    }

    Util::unipipe<pldm_mctp_message>* l_msgQ = nullptr;

    const pldm_msg_hdr* const l_pldm_hdr = &i_req.pldm_msg_no_own->hdr;

    // Make a copy of the incoming message so that we own the memory and can
    // send it to the appropriate queue.
    auto req_copy = std::make_unique<pldm_mctp_message>(i_req);

    // If pldm msg header tells us its a request, route to inbound
    // request queue, else route to inbound response queue
    if (l_pldm_hdr->request)
    {
        assert(g_inboundPldmReqMsgQ.queue() != nullptr, "pldm inbound request message queue is set to nullptr");
        l_msgQ = &g_inboundPldmReqMsgQ;
    }
    else
    {
        assert(g_inboundPldmRspMsgQ.queue() != nullptr, "pldm inbound response message queue is set to nullptr");
        l_msgQ = &g_inboundPldmRspMsgQ;
    }

    // No need to wait for a reply, just send the message on and return
    l_msgQ->send(move(req_copy));

    }while(0);

    // no need to free l_pldm_hdr, this buffer is managed by
    // the core mctp logic

    return errl;
}

} // end namespace PLDM
