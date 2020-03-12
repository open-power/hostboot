/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/base/pldm_requester.C $                          */
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
 * @file pldm_requester.C
 *
 * @brief Source code for the class that handles when other userspace modules
 *        wish to issue PLDM requests to the BMC. During pldm_base_init a singleton
 *        of the pldmRequester class has its init() function called which launches a
 *        task which will loop on the outbound_pldm_request message queue.
 */

// Headers from local directory
#include "../extern/utils.h"
#include "../extern/base.h"
#include "../common/pldmtrace.H"
#include "pldm_requester.H"

// Userspace Headers
#include <trace/interface.H>
#include <initservice/taskargs.H>
#include <mctp/mctp_message_types.H>
#include <pldm/pldmif.H>
#include <mctp/mctp_const.H>

extern const char* VFS_ROOT_MSG_MCTP_OUT;
extern msg_q_t g_inboundPldmRspMsgQ;  // pldm inbound response msgQ
extern msg_q_t g_outboundPldmReqMsgQ;  // pldm outbound request msgQ


// Static function used to launch task calling handle_outbound_req_messages on
// the pldmRequester singleton
static void * handle_outbound_req_messages_task(void*)
{
    PLDM_INF("Starting task to issue pldm request messages");
    task_detach();
    Singleton<pldmRequester>::instance().handle_outbound_req_messages();
    return nullptr;
}

void pldmRequester::handle_outbound_req_messages(void)
{
    // Does not need to be static as this function should only be called
    // on the singleton pldmRequester
    uint8_t instance_id = 0;

    while(1)
    {
        msg_t* req = msg_wait(g_outboundPldmReqMsgQ);

        assert(req->extra_data != nullptr,
               "handle_outbound_req_messages was send a msg_t with nothing in extra_data");

        // Check if the initial request is aysnc or not
        bool l_asyncReq = msg_is_async(req);

        // We will keep track of the instance_id in this loop rather than
        // have the requester manage it. Reinterpret the extra_data as a pldm
        // message so we can easily access the instance_id memeber of the hdr

        // We must offset into sizeof(MCTP::MCTP_MSG_TYPE_PLDM) of the MCTP
        // packet payload as where PLDM message begins. MCTP layer will set
        // this byte after we pass them the message.
        // (see DSP0236 v1.3.0 figure 4)
        struct pldm_msg *l_pldm_msg =
            reinterpret_cast<pldm_msg *>(
                reinterpret_cast<uint8_t *>(req->extra_data) +
                sizeof(MCTP::MCTP_MSG_TYPE_PLDM));

        // Update the instance ID and forward the message onto MCTP layer
        l_pldm_msg->hdr.instance_id = instance_id;

        // Update the type of req to be MSG_SEND_PLDM so the mctp layer
        // knows its receiving a PLDM message. In the messages other than
        // PLDM could be using the MCTP layer simultaneously so this is important.
        req->type = MCTP::MSG_SEND_PLDM;

        PLDM_DBG_BIN("handle_outbound_req_messages: msg sent to mctp outbound: ",
                    reinterpret_cast<uint8_t *>(req->extra_data),
                    req->data[0] );

        // Note we do not need to wait for the response on this queue because
        // the message will come back on the response Q
        const int rc = msg_send(iv_mctpOutboundMsgQ, req);
        assert(rc == 0, "handle_outbound_req_messages: failed to send to message to mctp")

        // TODO RTC:249701 add deadman timer
        msg_t* rsp = msg_wait(g_inboundPldmRspMsgQ);

        // original extra_data will need to be free'd by request func
        req->extra_data = rsp->extra_data;
        rsp->extra_data = 0;
        req->data[0] = rsp->data[0];

        // If the original message was not async, then the requester task is still
        // waiting so we must respond.
        if(!l_asyncReq)
        {
            PLDM_INF("Responding to message %d", instance_id);
            const int rc = msg_respond(g_outboundPldmReqMsgQ, req);
            assert(rc == 0, "handle_outbound_req_messages: failed to respond to message");
        }
        else
        {
            // Parse out if response was at least valid else throw error
            // clean up buffers because caller will not
            // TODO 249702
            PLDM_INF("handle_outbound_req_messages: async req encountered."
                     "This is currently unsupported so we are ignoring result of async request");
        }

        // Instance id is 5 bits so roll-back so valid numbers are 0-31
        // must rollback the number to 0 if id == 31
        instance_id = instance_id < 31 ? (instance_id + 1) : 0;
    }
}
void pldmRequester::init(void)
{
    PLDM_ENTER("pldmRequester::_init entry");

    // Resolve the pointer to the mctp outbound msg q
    // MCTP gets initialized first so its safe to assume the queue is initialized
    iv_mctpOutboundMsgQ = msg_q_resolve(VFS_ROOT_MSG_MCTP_OUT);

    assert(iv_mctpOutboundMsgQ != nullptr,
           "pldmRequester: VFS_ROOT_MSG_MCTP_OUT resolved to be nullptr, we expected it to be registered during mctp init");

    // Start cmd daemon first because we want it ready if poll
    // daemon finds something right away
    task_create(handle_outbound_req_messages_task, nullptr);

    PLDM_EXIT("pldmRequester::_init exit");

    return;
}

pldmRequester::pldmRequester(void) : iv_mctpOutboundMsgQ(nullptr) {}