/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/extended/pldm_responder.C $                      */
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

// Standard library
#include <memory>

// Userspace Headers
#include <trace/interface.H>
#include <initservice/taskargs.H>

// PLDM
#include <pldm/pldm_errl.H>
#include <pldm/pldm_const.H>
#include <pldm/pldm_reasoncodes.H>
#include <pldm/pldmif.H>
#include <pldm/pldm_response.H>
#include "../common/pldmtrace.H"
#include "pldm_responder.H"

// libpldm
#include <base.h>
#include <platform.h>
#include <fru.h>

// Message handler headers
#include <pldm/responses/pldm_monitor_control_responders.H>
#include <pldm/responses/pldm_fru_data_responders.H>

/* PLDM message handler lookup tables */

using namespace PLDM;
using namespace ERRORLOG;

namespace
{

/** Types and tables for message handler lookup **/

using msg_handler = errlHndl_t(*)(msg_q_t, const pldm_msg*, size_t);

struct msg_type_handler
{
    uint8_t command;
    msg_handler handler;
};

/*** Handlers for the MSG_MONITOR_CONTROL (PLDM_MC) type ***/

const msg_type_handler pldm_monitor_control_handlers[] =
{
    { PLDM_GET_PDR, handleGetPdrRequest },
    { PLDM_PLATFORM_EVENT_MESSAGE, handlePdrRepoChangeEventRequest },
    { PLDM_SET_STATE_EFFECTER_STATES, handleSetStateEffecterStatesRequest }
};

/*** Handlers for the MSG_FRU_DATA type ***/

const msg_type_handler pldm_fru_data_handlers[] =
{
    { PLDM_GET_FRU_RECORD_TABLE_METADATA, handleGetFruRecordTableMetadataRequest },
    { PLDM_GET_FRU_RECORD_TABLE, handleGetFruRecordTableRequest }
};

/*** Top-level table of handler tables ***/

struct msg_category
{
    PLDM::msgq_msg_t category;
    const msg_type_handler* handlers;
    size_t num_handlers;
};

const msg_category pldm_message_categories[] =
{
    { PLDM::MSG_MONITOR_CONTROL, pldm_monitor_control_handlers,
                                 std::size(pldm_monitor_control_handlers) },
    { PLDM::MSG_FRU_DATA,        pldm_fru_data_handlers,
                                 std::size(pldm_fru_data_handlers) }
};

#ifndef __HOSTBOOT_RUNTIME
/* Handler logic */

// Static function used to launch task calling handle_inbound_req_messages on
// the pldmResponder singleton
void * handle_inbound_req_messages_task(void*)
{
    PLDM_INF("Starting task to respond to pldm request messages");
    task_detach();
    Singleton<pldmResponder>::instance().handle_inbound_req_messages();
    return nullptr;
}
#endif

/* @brief send_cc_only_response
 *
 *        Send a PLDM response that consists solely of a PLDM header and a
 *        completion code.
 *
 * @param[in] i_msgQ  Handle to the MCTP outgoing response queue
 * @param[in] i_msg   Message to respond to
 * @param[in] i_cc    Completion code
 */
void send_cc_only_response(const msg_q_t i_msgQ,
                           const pldm_msg* i_msg,
                           const uint8_t i_cc)
{
    static const int PLDM_CC_ONLY_RESP_BYTES = 1;

    errlHndl_t errl =
        send_pldm_response<PLDM_CC_ONLY_RESP_BYTES>
        (i_msgQ,
         encode_cc_only_resp,
         0, // No variable-size payload
         i_msg->hdr.instance_id,
         i_msg->hdr.type,
         i_msg->hdr.command,
         i_cc);

    if (errl)
    {
        PLDM_INF("Failed to send completion code-only response");

        errl->collectTrace(PLDM_COMP_NAME);
        errlCommit(errl, PLDM_COMP_ID);
    }
}

/* @brief handle_inbound_req
 *
 *        Dispatches incoming PLDM requests according to their contents.
 *
 * @param[in] i_msgQ      MCTP message queue handle
 * @param[in] i_msg       PLDM message handle
 * @return    errlHndl_t  Error if any, otherwise nullptr.
 */
errlHndl_t handle_inbound_req(const msg_q_t i_msgQ, const void* i_msg, const size_t i_msg_len)
{
    PLDM_INF("Handling inbound PLDM request");

    errlHndl_t errl = nullptr;

    do
    {
        if (i_msg_len < sizeof(pldm_msg_hdr))
        {
            PLDM_INF("PLDM request shorter than PLDM header size (%u < %u)",
                     static_cast<uint32_t>(i_msg_len),
                     static_cast<uint32_t>(sizeof(pldm_msg_hdr)));

            /*@
             * @errortype  ERRL_SEV_UNRECOVERABLE
             * @moduleid   MOD_HANDLE_INBOUND_REQ
             * @reasoncode RC_INVALID_LENGTH
             * @userdata1  The length of the short PLDM message
             * @userdata2  Minimum length of a PLDM message
             * @devdesc    Software problem, PLDM message is too short
             * @custdesc   A software error occurred during system boot
             */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                 MOD_HANDLE_INBOUND_REQ,
                                 RC_INVALID_LENGTH,
                                 i_msg_len,
                                 sizeof(pldm_msg_hdr),
                                 ErrlEntry::NO_SW_CALLOUT);

            addBmcErrorCallouts(errl);
            break;
        }

        const pldm_msg* const pldm_message = reinterpret_cast<const pldm_msg* const>(i_msg);
        const uint64_t response_hdr_data = pldmHdrToUint64(*pldm_message);
        const size_t payload_len = i_msg_len - sizeof(pldm_msg_hdr);

        /* Lookup the message category in the first-level dispatch table to get
         * the second-level dispatch table */

        const auto category = static_cast<PLDM::msgq_msg_t>(pldm_message->hdr.type);

        const auto cat_table =
            std::find_if(std::cbegin(pldm_message_categories),
                         std::cend(pldm_message_categories),
                         [category](const msg_category& cat)
                         { return cat.category == category; });

        if (cat_table == std::cend(pldm_message_categories))
        {
            PLDM_INF("Unsupported PLDM request category %d",
                     category);

            send_cc_only_response(i_msgQ, pldm_message, PLDM_ERROR_INVALID_PLDM_TYPE);

            /*@
             * @errortype  ERRL_SEV_UNRECOVERABLE
             * @moduleid   MOD_HANDLE_INBOUND_REQ
             * @reasoncode RC_INVALID_MSG_CATEGORY
             * @userdata1  The unsupported category of the PLDM message
             * @userdata2  PLDM message header
             * @devdesc    Software problem, unknown PLDM message category
             * @custdesc   A software error occurred during system boot
             */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                 MOD_HANDLE_INBOUND_REQ,
                                 RC_INVALID_MSG_CATEGORY,
                                 category,
                                 response_hdr_data,
                                 ErrlEntry::NO_SW_CALLOUT);

            addBmcErrorCallouts(errl);
            break;
        }

        /* Unpack the PLDM header so we can get the command type for the
         * second-level dispatch table lookup */

        pldm_header_info header_info { };

        {
            const int rc = unpack_pldm_header(&pldm_message->hdr, &header_info);

            if (rc != 0)
            {
                PLDM_INF("Failed to unpack PLDM request header (rc = %d)",
                         rc);

                send_cc_only_response(i_msgQ, pldm_message, PLDM_ERROR_INVALID_DATA);

                /*@
                 * @errortype  ERRL_SEV_UNRECOVERABLE
                 * @moduleid   MOD_HANDLE_INBOUND_REQ
                 * @reasoncode RC_INVALID_HEADER
                 * @userdata1  Return code from unpack routine
                 * @userdata2  PLDM message header
                 * @devdesc    Software problem, cannot unpack PLDM header
                 * @custdesc   A software error occurred during system boot
                 */
                errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                     MOD_HANDLE_INBOUND_REQ,
                                     RC_INVALID_HEADER,
                                     rc,
                                     response_hdr_data,
                                     ErrlEntry::NO_SW_CALLOUT);

                addBmcErrorCallouts(errl);
                break;
            }
        }

        if (header_info.msg_type != PLDM_REQUEST)
        {
            PLDM_INF("PLDM message is not a request, "
                     "expected PLDM_REQUEST (%d), got %d",
                     PLDM_REQUEST,
                     header_info.msg_type);

            send_cc_only_response(i_msgQ, pldm_message, PLDM_ERROR);

            /*@
             * @errortype  ERRL_SEV_UNRECOVERABLE
             * @moduleid   MOD_HANDLE_INBOUND_REQ
             * @reasoncode RC_INVALID_MSG_TYPE
             * @userdata1  Unrecognized PLDM message type
             * @userdata2  PLDM message header
             * @devdesc    Software problem, invalid PLDM request type
             * @custdesc   A software error occurred during system boot
             */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                 MOD_HANDLE_INBOUND_REQ,
                                 RC_INVALID_MSG_TYPE,
                                 header_info.msg_type,
                                 response_hdr_data,
                                 ErrlEntry::ADD_SW_CALLOUT);
            break;
        }

        /* Lookup the command in the second-level dispatch table to get the
         * handler function */

        const uint8_t pldm_command = header_info.command;

        const auto handler =
            std::find_if(cat_table->handlers,
                         cat_table->handlers + cat_table->num_handlers,
                         [pldm_command](const msg_type_handler& handler)
                         { return handler.command == pldm_command; });

        if (handler == cat_table->handlers + cat_table->num_handlers)
        {
            PLDM_INF("Unsupported PLDM request command type "
                     "(category = %d, command = %d)",
                     category, pldm_command);

            send_cc_only_response(i_msgQ, pldm_message, PLDM_ERROR_UNSUPPORTED_PLDM_CMD);

            /*@
             * @errortype  ERRL_SEV_UNRECOVERABLE
             * @moduleid   MOD_HANDLE_INBOUND_REQ
             * @reasoncode RC_INVALID_COMMAND
             * @userdata1  Unrecognized PLDM command
             * @userdata2  PLDM message category
             * @devdesc    Software problem, unrecognized PLDM command
             * @custdesc   A software error occurred during system boot
             */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                 MOD_HANDLE_INBOUND_REQ,
                                 RC_INVALID_COMMAND,
                                 pldm_command,
                                 category,
                                 ErrlEntry::NO_SW_CALLOUT);

            addBmcErrorCallouts(errl);
            break;
        }

        /* Invoke the handler and return any error */

        PLDM_INF("Invoking handler for category %d message type %d",
                 category, pldm_command);

        errl = handler->handler(i_msgQ, pldm_message, payload_len);
    } while (false);

    return errl;
}

}

#ifndef __HOSTBOOT_RUNTIME
/* pldmResponder class implementation */

extern msg_q_t g_inboundPldmReqMsgQ;  // pldm inbound request msgQ

extern const char* VFS_ROOT_MSG_MCTP_OUT;

void pldmResponder::handle_inbound_req_messages(void)
{
    while(1)
    {
        const std::unique_ptr<msg_t, decltype(&msg_free)> msg
        {
            msg_wait(g_inboundPldmReqMsgQ),
            msg_free
        };

        errlHndl_t errl = handle_inbound_req(iv_mctpOutboundMsgQ,
                                             msg->extra_data,
                                             msg->data[0]);

        if (errl)
        {
            PLDM_INF("handle_inbound_req returned an error");

            errlCommit(errl, PLDM_COMP_ID);
        }
    }
}

void pldmResponder::init(void)
{
    PLDM_ENTER("pldmResponder::_init entry");

    // Resolve the pointer to the MCTP outbound message queue
    // MCTP gets initialized first so its safe to assume the queue is initialized
    iv_mctpOutboundMsgQ = msg_q_resolve(VFS_ROOT_MSG_MCTP_OUT);

    assert(iv_mctpOutboundMsgQ != nullptr,
           "pldmResponder: VFS_ROOT_MSG_MCTP_OUT resolved to be nullptr, we "
           "expected it to be registered during mctp init");

    // Start cmd daemon first because we want it ready if poll
    // daemon finds something right away
    task_create(handle_inbound_req_messages_task, NULL);

    PLDM_EXIT("pldmResponder::_init exit");

    return;
}

pldmResponder::pldmResponder(void) : iv_mctpOutboundMsgQ(nullptr) {}
#else

errlHndl_t PLDM::handle_next_pldm_request(void)
{
    auto& next_pldm_request = PLDM::get_next_request();
    assert (!next_pldm_request.empty(), "SW bug! we should never attempt to handle next pldm request if there is not one");
    errlHndl_t errl = handle_inbound_req(nullptr,
                                         next_pldm_request.data(),
                                         next_pldm_request.size());
    // clear the request we attempted to handle regardless
    // if we were successful or not
    PLDM::clear_next_request();
    return errl;
}

#endif
