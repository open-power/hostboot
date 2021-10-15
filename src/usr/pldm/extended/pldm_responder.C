/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/extended/pldm_responder.C $                      */
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
#include "pldm_responder.H"

// Standard library
#include <memory>

// KILOBYTE def
#include <limits.h>

// Userspace Headers
#include <trace/interface.H>
#include <initservice/taskargs.H>

// PLDM
#include <pldm/pldm_errl.H>
#include <pldm/pldm_const.H>
#include <pldm/pldm_reasoncodes.H>
#include <pldm/pldmif.H>
#include <pldm/pldm_response.H>
#include <pldm/pldm_trace.H>
#include "pldm_responder.H"

// libpldm
#include <base.h>
#include <platform.h>
#include <fru.h>

// Message handler headers
#include <pldm/responses/pldm_discovery_control_responders.H>
#include <pldm/responses/pldm_monitor_control_responders.H>
#include <pldm/responses/pldm_fru_data_responders.H>

// Hostboot utils
#include <util/misc.H>

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


/*** Handlers for the MSG_CONTROL_DISCOVERY (pldm_const.H - enum msgq_msg_t) type ***/
const msg_type_handler pldm_discovery_control_handlers[] =
{
    { PLDM_GET_PLDM_VERSION, handleGetPldmVersionRequest },
};

/*** Handlers for the MSG_MONITOR_CONTROL (PLDM_MC) type ***/

const msg_type_handler pldm_monitor_control_handlers[] =
{
    { PLDM_GET_PDR, handleGetPdrRequest },
    { PLDM_PLATFORM_EVENT_MESSAGE, handlePdrRepoChangeEventRequest },
    { PLDM_SET_STATE_EFFECTER_STATES, handleSetStateEffecterStatesRequest },
    { PLDM_GET_STATE_SENSOR_READINGS, handleGetStateSensorReadingsRequest },
    { PLDM_SET_EVENT_RECEIVER, handleSetEventReceiverRequest },
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
    { PLDM::MSG_CONTROL_DISCOVERY, pldm_discovery_control_handlers,
                                   std::size(pldm_discovery_control_handlers) },
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

/* @brief Add a debug section to error log with PLDM msg
 * @param[in/out] io_errl Error log for adding new section
 * @param[in] i_msg       PLDM message handle
 * @param[in] i_msg_len   Size of message
 */
void addPldmMsgSection(errlHndl_t & io_errl, const void *i_msg, const size_t i_msg_len)
{
    assert(io_errl != nullptr, "io_errl is nullptr in addPldmMsgSection");
    const size_t MAX_SECTION_SIZE = 2*KILOBYTE;

    if (i_msg_len > MAX_SECTION_SIZE)
    {
        // Only add MAX_SECTION_SIZE of the PLDM msg with version 1, subsection 1
        io_errl->addFFDC(PLDM_COMP_ID, i_msg, MAX_SECTION_SIZE, 1, PLDM_UDT_MSG_INCOMPLETE_DATA);
    }
    else
    {
        // Add the full PLDM msg with version 1, subsection 2
        io_errl->addFFDC(PLDM_COMP_ID, i_msg, i_msg_len, 1, PLDM_UDT_MSG_DATA);
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

        // Will contain first 8 bytes of msg (first 3 are just header)
        uint64_t response_hdr_data = 0;
        if (i_msg_len >= sizeof(response_hdr_data))
        {
            memcpy(&response_hdr_data, i_msg, sizeof(response_hdr_data));
        }
        else
        {
            memcpy(&response_hdr_data, i_msg, i_msg_len);
        }
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
            PLDM_INF("handle_inbound_req PLDM_ERROR_NOT_READY RC_INVALID_MSG_CATEGORY=%d",
                     category);

            send_cc_only_response(i_msgQ, pldm_message, PLDM_ERROR_NOT_READY);

            /*@
             * @errortype  ERRL_SEV_INFORMATIONAL
             * @moduleid   MOD_HANDLE_INBOUND_REQ
             * @reasoncode RC_INVALID_MSG_CATEGORY
             * @userdata1  The unsupported category of the PLDM message
             * @userdata2  PLDM message header
             * @devdesc    Software problem, unknown PLDM message category
             * @custdesc   A software error occurred during system boot
             */
            errl = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                 MOD_HANDLE_INBOUND_REQ,
                                 RC_INVALID_MSG_CATEGORY,
                                 category,
                                 response_hdr_data,
                                 ErrlEntry::NO_SW_CALLOUT);

            addBmcErrorCallouts(errl);
            // Add PLDM msg to error for debug
            addPldmMsgSection(errl, i_msg, i_msg_len);
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
                // Add PLDM msg to error for debug
                addPldmMsgSection(errl, i_msg, i_msg_len);
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
            // Add PLDM msg to error for debug
            addPldmMsgSection(errl, i_msg, i_msg_len);
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
            PLDM_INF("handle_inbound_req PLDM_ERROR_NOT_READY RC_INVALID_COMMAND category=%d pldm_command=%d",
                     category, pldm_command);

            send_cc_only_response(i_msgQ, pldm_message, PLDM_ERROR_NOT_READY);

            /*@
             * @errortype  ERRL_SEV_INFORMATIONAL
             * @moduleid   MOD_HANDLE_INBOUND_REQ
             * @reasoncode RC_INVALID_COMMAND
             * @userdata1  Unrecognized PLDM command
             * @userdata2  PLDM message category
             * @devdesc    Software problem, unrecognized PLDM command
             * @custdesc   A software error occurred during system boot
             */
            errl = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                 MOD_HANDLE_INBOUND_REQ,
                                 RC_INVALID_COMMAND,
                                 pldm_command,
                                 category,
                                 ErrlEntry::NO_SW_CALLOUT);
            addBmcErrorCallouts(errl);
            // Add PLDM msg to error for debug
            addPldmMsgSection(errl, i_msg, i_msg_len);
            break;
        }

        if(!Util::isTargetingLoaded())
        {
            send_cc_only_response(i_msgQ, pldm_message, PLDM_ERROR_NOT_READY);
            PLDM_INF("handle_inbound_req PLDM_ERROR_NOT_READY IGNORING "
                     "category=%d pldm_command=%d, TARGETING -NOT- loaded, "
                     "probably stray from previous boot or intended for PHYP at runtime",
                     category, pldm_command);
            /*@
             * @errortype  ERRL_SEV_INFORMATIONAL
             * @moduleid   MOD_HANDLE_INBOUND_REQ
             * @reasoncode RC_NOT_READY
             * @userdata1  Unrecognized PLDM command
             * @userdata2  PLDM message category
             * @devdesc    Software problem, Hostboot got a PLDM request
             *             before we were ready to handle it.
             * @custdesc   A software error occurred during system boot
             */
            errl = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                 MOD_HANDLE_INBOUND_REQ,
                                 RC_NOT_READY,
                                 pldm_command,
                                 category,
                                 ErrlEntry::NO_SW_CALLOUT);
            addBmcErrorCallouts(errl);
            // Add PLDM msg to error for debug
            addPldmMsgSection(errl, i_msg, i_msg_len);
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
