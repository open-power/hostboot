/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/base/pldmrp.C $                                  */
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


// Headers from local directory
#include "../extern/utils.h"
#include "../extern/base.h"
#include "../common/pldmtrace.H"
#include "pldmrp.H"

// Userspace Headers
#include <trace/interface.H>
#include <initservice/taskargs.H>
#include <mctp/mctp_message_types.H>
#include <pldm/pldmif.H>
#include <mctp/mctp_const.H>

trace_desc_t* g_trac_pldm = nullptr;
TRAC_INIT(&g_trac_pldm, PLDM_COMP_NAME, 4*KILOBYTE, TRACE::BUFFER_SLOW);

extern const char* VFS_ROOT_MSG_MCTP_OUT;
extern const char* VFS_ROOT_MSG_PLDM_REQ_IN;
extern const char* VFS_ROOT_MSG_PLDM_RSP_IN;
extern const char* VFS_ROOT_MSG_PLDM_REQ_OUT;

namespace PLDM {

void routeInboundMessage(uint8_t* i_msg, size_t i_len)
{
    msg_t*  l_msg = msg_allocate();
    msg_q_t l_msgQ = nullptr;

    // PLDM header is the start of the PLDM message
    pldm_msg_hdr * l_pldm_hdr =
            reinterpret_cast<pldm_msg_hdr *>(reinterpret_cast<uint8_t *>(i_msg));

    // set the message type to be the pldm msg type
    l_msg->type = l_pldm_hdr->type;

    // If pldm msg header tells us its a request, route to inbound
    // request queue, else route to inbound response queue
    if (l_pldm_hdr->request)
    {
        l_msgQ = Singleton<PldmRP>::instance().getInboundReqMsgQ();
    }
    else
    {
        l_msgQ = Singleton<PldmRP>::instance().getInboundRspMsgQ();
    }

    assert(l_msgQ != nullptr, "pldm inbound message queue is set to nullptr");

    l_msg->data[0] = i_len;

    // allocate a buffer which will be free'd by the PLDM handler
    l_msg->extra_data = malloc(l_msg->data[0]);

    memcpy(l_msg->extra_data,
            reinterpret_cast<uint8_t *>(l_pldm_hdr),
            l_msg->data[0]);


    // No need to wait for a reply, just send the message on and return
    msg_send(l_msgQ, l_msg);

    // no need to free l_pldm_hdr, this buffer is managed by
    // the core mctp logic

    return;
}

} // end namespace PLDM

// Static function used to launch task calling handle_inbound_req_messages on
// the PldmRP singleton
static void * handle_inbound_req_messages_task(void*)
{
    PLDM_INF("Starting task to handle pldm inbound messages");
    Singleton<PldmRP>::instance().handle_inbound_req_messages();
    return nullptr;
}

// TODO RTC:249696 handle inbound requests
// Ignore this function for now
void PldmRP::handle_inbound_req_messages(void)
{
    uint8_t l_rc = 0;
    while(1)
    {
        msg_t* msg = msg_wait(iv_inboundReqMsgQ);
        assert(0, "Hostboot does not currently support handling PLDM requests");
//         pldm_msg * l_pldm_msg_ptr = reinterpret_cast<pldm_msg *>(msg->extra_data);
//         size_t l_payloadLen = msg->data[0] - sizeof(pldm_msg_hdr);
        switch(msg->type)
        {
          case PLDM::MSG_CONTROL_DISCOVERY: // PLDM_CD
              // Send control/discovery message to correct handler
//              process_pldm_cd_req(l_pldm_msg_ptr, l_payloadLen );
              break;
          case PLDM::MSG_SMBIOS:  // PLDM_SMBIOS
              break;
          case PLDM::MSG_MONITOR_CONTROL: // PLDM_MC
              break;
          case PLDM::MSG_BIOS_CONTROL: // PLDM_BIOS
              break;
          case PLDM::MSG_OEM:  //PLDM_OEM
              break;
          default:
              // Error because its an unknown type
              break;
        }

        if(l_rc != 0)
        {
            break;
        }
    }
}

// Static function used to launch task calling handle_outbound_req_messages on
// the PldmRP singleton
static void * handle_outbound_req_messages_task(void*)
{
    PLDM_INF("Starting task to handle pldm inbound messages");
    Singleton<PldmRP>::instance().handle_outbound_req_messages();
    return nullptr;
}

void PldmRP::handle_outbound_req_messages(void)
{
    // Does not need to be static as this function should only be called
    // on the singleton PldmRP
    uint8_t instance_id = 0;

    while(1)
    {
        msg_t* req = msg_wait(iv_outboundReqMsgQ);

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
        msg_send(iv_mctpOutboundMsgQ, req);

        // TODO RTC:249701 add deadman timer
        msg_t* rsp = msg_wait(iv_inboundRspMsgQ);

        // original extra_data will need to be free'd by request func
        req->extra_data = rsp->extra_data;
        req->data[0] = rsp->data[0];

        // If the original message was not async, then the requester task is still
        // waiting so we must respond.
        if(!l_asyncReq)
        {
            PLDM_INF("Responding to message %d", instance_id);
            msg_respond(iv_outboundReqMsgQ, req);
        }
        else
        {
            // Parse out if response was at least valid else throw error
            // clean up buffers because caller will not
            // TODO 249702
            PLDM_INF("Async request we must handle it ourselves handle it");
        }

        // Instance id is 5 bits so roll-back so valid numbers are 0-31
        // must rollback the number to 0 if id == 31
        instance_id = instance_id < 31 ? (instance_id + 1) : 0;
    }
}
void PldmRP::_init(void)
{
    PLDM_ENTER("PldmRP::_init entry");

    // Start cmd daemon first because we want it ready if poll
    // daemon finds something right away
    task_create(handle_inbound_req_messages_task, NULL);
    task_create(handle_outbound_req_messages_task, NULL);

    // MCTP will route inbound PLDM messages to the approriate
    // queue ( request or response)
    msg_q_register(iv_inboundReqMsgQ, VFS_ROOT_MSG_PLDM_REQ_IN);
    msg_q_register(iv_inboundRspMsgQ, VFS_ROOT_MSG_PLDM_RSP_IN);

    // Other modules will need to find this queue to make pldm requests
    // so register it for them
    msg_q_register(iv_outboundReqMsgQ, VFS_ROOT_MSG_PLDM_REQ_OUT);

    // Resolve the pointer to the mctp outbound msg q
    // MCTP gets initialized first so its safe to assume the queue is initialized
    iv_mctpOutboundMsgQ = msg_q_resolve(VFS_ROOT_MSG_MCTP_OUT);

    PLDM_EXIT("PldmRP::_init exit");

    return;
}

void PldmRP::init(errlHndl_t& o_errl)
{
    // This will call the MctpRP construction which initializes MCTP
    // polling loops
    return Singleton<PldmRP>::instance()._init();
}

PldmRP::PldmRP(void):
    iv_inboundReqMsgQ(msg_q_create()),
    iv_outboundReqMsgQ(msg_q_create()),
    iv_inboundRspMsgQ(msg_q_create())

{
}

// Set the function that will be called when pldm_base.so is loaded
TASK_ENTRY_MACRO( PldmRP::init );
