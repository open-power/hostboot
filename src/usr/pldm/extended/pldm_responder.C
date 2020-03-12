/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/extended/pldm_responder.C $                      */
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
 * @file pldm_responder.C
 *
 * @brief Source code for the class that handles pldm requests that MCTP has
 *        read off the LPC bus. These requests are coming from the BMC
 *        so we must handle the requests and respond accordingly. During
 *        pldm_extended_init a singleton of the pldmResponder class has its
 *        init() function called which launches a task which will loop on the
 *        inbound_pldm_request message queue.
 */

// Headers from local directory
#include "../common/pldmtrace.H"
#include "pldm_responder.H"

// Userspace Headers
#include <trace/interface.H>
#include <initservice/taskargs.H>
#include <pldm/pldm_const.H>

extern const char* VFS_ROOT_MSG_MCTP_OUT;

extern msg_q_t g_inboundPldmReqMsgQ;  // pldm inbound response msgQ

// Static function used to launch task calling handle_inbound_req_messages on
// the pldmResponder singleton
static void * handle_inbound_req_messages_task(void*)
{
    PLDM_INF("Starting task to respond to pldm request messages");
    task_detach();
    Singleton<pldmResponder>::instance().handle_inbound_req_messages();
    return nullptr;
}

void pldmResponder::handle_inbound_req_messages(void)
{
    uint8_t l_rc = 0;
    while(1)
    {
        msg_t* msg = msg_wait(g_inboundPldmReqMsgQ);
        assert(0, "Hostboot does not currently support handling PLDM requests");
//      TODO RTC: 249696 Handle inbound PLDM Requests from the BMC
//      pldm_msg * l_pldm_msg_ptr = reinterpret_cast<pldm_msg *>(msg->extra_data);
//      size_t l_payloadLen = msg->data[0] - sizeof(pldm_msg_hdr);
        switch(msg->type)
        {
          case PLDM::MSG_CONTROL_DISCOVERY: // PLDM_CD
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

void pldmResponder::init(void)
{
    PLDM_ENTER("pldmResponder::_init entry");

    // Resolve the pointer to the mctp outbound msg q
    // MCTP gets initialized first so its safe to assume the queue is initialized
    iv_mctpOutboundMsgQ = msg_q_resolve(VFS_ROOT_MSG_MCTP_OUT);

    assert(iv_mctpOutboundMsgQ != nullptr,
           "pldmResponder: VFS_ROOT_MSG_MCTP_OUT resolved to be nullptr, we expected it to be registered during mctp init");

    // Start cmd daemon first because we want it ready if poll
    // daemon finds something right away
    task_create(handle_inbound_req_messages_task, NULL);

    PLDM_EXIT("pldmResponder::_init exit");

    return;
}

pldmResponder::pldmResponder(void) : iv_mctpOutboundMsgQ(nullptr) {}