/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/base/pldm_msg_router.C $                         */
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
#include <mctp/mctp_message_types.H>
// From src/usr/pldm/extern/
#include "../extern/base.h"
// From src/usr/pldm/common/
#include "../common/pldmtrace.H"

using namespace ERRORLOG;

extern msg_q_t g_inboundPldmRspMsgQ;  // pldm inbound response msgQ
extern msg_q_t g_inboundPldmReqMsgQ;  // pldm inbound request msgQ

namespace PLDM {

errlHndl_t routeInboundMsg(const uint8_t* const i_msg, const size_t i_len)
{
    assert(i_msg != nullptr, "PLDM::routeInboundMsg nullptr passed for i_msg");
    errlHndl_t errl = nullptr;

    do {

    if(i_len < sizeof(pldm_msg_hdr))
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
                             i_len,
                             sizeof(pldm_msg_hdr),
                             ErrlEntry::NO_SW_CALLOUT);

        addBmcErrorCallouts(errl);
        break;
    }

    msg_t*  l_msg = msg_allocate();
    msg_q_t l_msgQ = nullptr;

    const pldm_msg_hdr * l_pldm_hdr =
            reinterpret_cast<const pldm_msg_hdr *>(i_msg);

    // set the message type to be the pldm msg type
    l_msg->type = l_pldm_hdr->type;

    // set data[0] to be the length of the msg payload in extra_data
    l_msg->data[0] = i_len;

    // allocate a buffer which will be free'd by recipient of this msg
    l_msg->extra_data = calloc(l_msg->data[0], 1);

    memcpy(l_msg->extra_data,
           l_pldm_hdr,
           l_msg->data[0]);

    // If pldm msg header tells us its a request, route to inbound
    // request queue, else route to inbound response queue
    if (l_pldm_hdr->request)
    {
        assert(g_inboundPldmReqMsgQ != nullptr, "pldm inbound request message queue is set to nullptr");
        l_msgQ = g_inboundPldmReqMsgQ;
    }
    else
    {
        assert(g_inboundPldmRspMsgQ != nullptr, "pldm inbound response message queue is set to nullptr");
        l_msgQ = g_inboundPldmRspMsgQ;
    }

    // No need to wait for a reply, just send the message on and return
    const int rc = msg_send(l_msgQ, l_msg);

    if(rc)
    {
        PLDM_ERR("routeInboundMsg: Failed sending a message to msg_q %p", l_msgQ);

        /*@errorlog
        * @errortype   ERRL_SEV_PREDICTIVE
        * @moduleid    MOD_ROUTE_MESSAGES
        * @reasoncode  RC_SEND_FAIL
        * @userdata1   rc from msg_send
        * @userdata2   ptr to message as uint64_t
        * @devdesc     Error sending message to PLDM message q
        * @custdesc    A problem occurred during the IPL of the system
        */
        errl = new ErrlEntry(ERRL_SEV_PREDICTIVE,
                              MOD_ROUTE_MESSAGES,
                              RC_SEND_FAIL,
                              rc,
                              reinterpret_cast<uint64_t>(l_msg),
                              ErrlEntry::ADD_SW_CALLOUT);
        errl->collectTrace(PLDM_COMP_NAME);
        free(l_msg->extra_data);
        l_msg->extra_data = nullptr;
        msg_free(l_msg);
        l_msg = nullptr;
        break;
    }

    }while(0);

    // no need to free l_pldm_hdr, this buffer is managed by
    // the core mctp logic

    return errl;
}

} // end namespace PLDM