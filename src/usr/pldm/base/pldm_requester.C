/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/base/pldm_requester.C $                          */
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
 * @file pldm_requester.C
 * @brief Source code for the class that handles when other userspace modules
 *        wish to issue PLDM requests to the BMC. During pldm_base_init a singleton
 *        of the pldmRequester class has its init() function called which launches a
 *        task which will loop on the outbound_pldm_request message queue.
 */

// Headers from local directory
#include <utils.h>
#include <base.h>
#include <pldm/pldm_trace.H>
#include "pldm_requester.H"
#include "pldm_msg_timeout.H"

// Userspace Headers
#include <errl/errlentry.H>
#include <initservice/taskargs.H>
#include <mctp/mctp_const.H>
#include <mctp/mctp_message_types.H>
#include <pldm/pldmif.H>
#include <pldm/pldm_const.H>
#include <pldm/pldm_reasoncodes.H>
#include <pldm/pldm_errl.H>
#include <trace/interface.H>


// System headers
#include <sys/time.h>


using namespace PLDM;
using namespace ERRORLOG;

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

bool pldmRequester::wait_for_matching_response(msg_t* io_req,
                                              const uint64_t i_max_timeout_milliseconds,
                                              uint32_t & o_bad_rsp_count)
{
    bool valid_response_found(false);
    o_bad_rsp_count = 0;

    struct pldm_msg *l_pldm_req_msg =
        reinterpret_cast<pldm_msg *>(
            reinterpret_cast<uint8_t *>(io_req->extra_data) +
            sizeof(MCTP::MCTP_MSG_TYPE_PLDM));
    uint64_t l_max_timeout_milliseconds = i_max_timeout_milliseconds;

    while((l_max_timeout_milliseconds > 0) && (!valid_response_found))
    {
        // The PLDM response to our request will actually come back via
        // the g_inboundPldmRspMsgQ
        auto response_msgs = pldmMsgTimeout::pldm_wait_timeout(g_inboundPldmRspMsgQ, l_max_timeout_milliseconds);
        PLDM_DBG("msg instance_id %d -- pldm_wait_timeout() returned %d records with %lld msec remaining",
            l_pldm_req_msg->hdr.instance_id, response_msgs.size(), l_max_timeout_milliseconds);
        for( auto rsp_msg : response_msgs)
        {
            if (rsp_msg->extra_data != nullptr)
            {
                struct pldm_msg_hdr *hdr =
                            (struct pldm_msg_hdr *)rsp_msg->extra_data;

                // make sure this is the message we want
                if((hdr->instance_id == l_pldm_req_msg->hdr.instance_id) &&
                   (hdr->type == l_pldm_req_msg->hdr.type) &&
                   (hdr->command == l_pldm_req_msg->hdr.command))
                {
                    if (valid_response_found)
                    {
                        PLDM_ERR("Received a duplicate PLDM Response type: 0x%02x command 0x%02x instance_id %d to a PLDM request",
                              hdr->type, hdr->command, hdr->instance_id);
                        free(rsp_msg->extra_data);
                    }
                    else
                    {
                        valid_response_found = true;

                        // This is a soft copy, as extra_data points to allocated memory
                        // original extra_data will need to be free'd by request func
                        io_req->extra_data = rsp_msg->extra_data;
                        io_req->data[0] = rsp_msg->data[0];
                    }
                }
                else
                {
                    // If it's not a response to a request that we made, it's
                    // likely that the BMC is confused and sending us a response
                    // from a previous IPL. That or the BMC has potentially been
                    // compromised. Either way, free the msg and look for
                    // another one.
                    PLDM_ERR("Received a PLDM Response type: 0x%02x command 0x%02x instance_id %d to a PLDM request we did not send.",
                              hdr->type, hdr->command, hdr->instance_id);
                    free(rsp_msg->extra_data);
                    o_bad_rsp_count++;
                }
            }
            else
            {
                o_bad_rsp_count++;
            }
            rsp_msg->extra_data = nullptr;
            msg_free(rsp_msg);
            rsp_msg = nullptr;
        } // loop of response msgs
    } // timeout of message received while loop

    return valid_response_found;
}

void pldmRequester::send_req_with_retry(msg_t* io_req)
{
    // number of attempts to successfully send and receive a response with
    // the current instance req msg
    uint8_t req_attempts = 0;

    // Per PLDM DSP0240 document:
    // Number of request retries = 2 (minimum)
    // Time-out waiting for a response = 5 seconds - 2*100ms (maximum wait)
    // Note: the last retry attempt needs to happen before the max wait time
    const uint8_t MAX_ATTEMPTS = 3;  // allow for 2 retries
    const uint64_t MAX_MS_WAIT_PER_ATTEMPT = 2 * MS_PER_SEC; // 2 seconds

    // an interesting count of how many invalid responses are encountered per original msg sent
    uint32_t invalid_rsp_count = 0;

    // We must offset into sizeof(MCTP::MCTP_MSG_TYPE_PLDM) of the MCTP
    // packet payload as where PLDM message begins. MCTP layer will set
    // this byte after we pass them the message.
    // (see DSP0236 v1.3.0 figure 4)
    struct pldm_msg *l_pldm_req_msg =
        reinterpret_cast<pldm_msg *>(
        reinterpret_cast<uint8_t *>(io_req->extra_data) +
            sizeof(MCTP::MCTP_MSG_TYPE_PLDM));

    // retry loop
    while (req_attempts++ < MAX_ATTEMPTS)
    {
        const int l_rc = msg_sendrecv(iv_mctpOutboundMsgQ, io_req);

        // The MCTP layer will set data[1] on the msg when
        // they respond if there was an error
        if(io_req->data[1])
        {
            // io_req->extra_data has an error log in it generated by the MCTP
            // resource provider. Set io_req->data[1] to REQ_FAILED to notify
                // the requester that there was a fail and they should parse the
                // extra data as an error log
            io_req->data[1] = REQ_FAILED;
            break;
        }
        // The response from the sendrecv call to the outbound mctp queue tells
        // us if there was a problem or not sending the message to the MCTP layer
        else if(l_rc)
        {
            const uint64_t request_hdr_data = pldmHdrToUint64(*l_pldm_req_msg);

            /*@
              * @errortype
              * @moduleid   MOD_PLDM_SEND_REQ_RETRY
              * @reasoncode RC_SENDRECV_FAIL
              * @userdata1  Return code returned by msg_sendrecv
              * @userdata2  Header of pldm request
              * @devdesc    Software problem, failed msg_sendrecv
              * @custdesc   A software error occurred during system boot
              */
            errlHndl_t errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                  MOD_PLDM_SEND_REQ_RETRY,
                                  RC_SENDRECV_FAIL,
                                  l_rc,
                                  request_hdr_data,
                                  ErrlEntry::ADD_SW_CALLOUT);
            errl->collectTrace(PLDM_COMP_NAME);

            // original extra_data will need to be free'd by request func
            io_req->extra_data = errl;
            errl = nullptr;
            io_req->data[1] = REQ_FAILED;
            break;
        }
        // otherwise the PLDM request successfully went through
        else
        {
            bool valid_response_found = false;
            uint32_t bad_responses = 0;

            // wait for a valid response or timeout on g_inboundPldmRspMsgQ
            valid_response_found = wait_for_matching_response(io_req,
                                                              MAX_MS_WAIT_PER_ATTEMPT,
                                                              bad_responses);
            // running total of non-matching responses for this req
            invalid_rsp_count += bad_responses;

            if (valid_response_found)
            {
                // exit MAX_ATTEMPTS retry loop, found a valid response
                break;
            }

            // If no valid response from msg_wait_timeout
            // and all retries have been done for this req instance
            if (req_attempts == MAX_ATTEMPTS)
            {
                PLDM_ERR("No valid response after exceeding maximum retry attempts (%d). "
                  "Found %lld invalid responses while waiting for a valid response to message %d.",
                  MAX_ATTEMPTS, invalid_rsp_count, l_pldm_req_msg->hdr.instance_id);

                // create a timeout error
                const uint64_t request_hdr_data = pldmHdrToUint64(*l_pldm_req_msg);

                /*@
                  * @errortype
                  * @moduleid   MOD_PLDM_SEND_REQ_RETRY
                  * @reasoncode RC_TIMEOUT
                  * @userdata1  Header of pldm request
                  * @userdata2  Total invalid responses encountered
                  * @devdesc    Software problem, no PLDM response after multiple retries
                  * @custdesc   A software error occurred during system boot
                  */
                errlHndl_t errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                                MOD_PLDM_SEND_REQ_RETRY,
                                                RC_TIMEOUT,
                                                request_hdr_data,
                                                invalid_rsp_count,
                                                ErrlEntry::NO_SW_CALLOUT);
                addBmcErrorCallouts(errl);
                errl->collectTrace(PLDM_COMP_NAME);

                // original extra_data will need to be free'd by request func
                io_req->extra_data = errl;
                errl = nullptr;

                // Set io_req->data[1] to REQ_FAILED to notify the requester
                // that there was a fail and they should parse the
                // extra data as an error log
                io_req->data[1] = REQ_FAILED;
                break;
            }
        } // end of else wait for PLDM response
    } // MAX_ATTEMPTS retry loop
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
               "handle_outbound_req_messages was sent a msg_t with nothing in extra_data");

        // Check if the initial request is aysnc or not
        bool l_asyncReq = msg_is_async(req);

        // We will keep track of the instance_id in this loop rather than
        // have the requester manage it. Reinterpret the extra_data as a pldm
        // message so we can easily access the instance_id memeber of the hdr

        // We must offset into sizeof(MCTP::MCTP_MSG_TYPE_PLDM) of the MCTP
        // packet payload as where PLDM message begins. MCTP layer will set
        // this byte after we pass them the message.
        // (see DSP0236 v1.3.0 figure 4)
        struct pldm_msg *l_pldm_req_msg =
            reinterpret_cast<pldm_msg *>(
                reinterpret_cast<uint8_t *>(req->extra_data) +
                sizeof(MCTP::MCTP_MSG_TYPE_PLDM));

        // Update the instance ID and forward the message onto MCTP layer
        l_pldm_req_msg->hdr.instance_id = instance_id;

        // Update the type of req to be MSG_SEND_PLDM so the mctp layer
        // knows its receiving a PLDM message. In the messages other than
        // PLDM could be using the MCTP layer simultaneously so this is important.
        req->type = MCTP::MSG_SEND_PLDM;

        PLDM_DBG_BIN("handle_outbound_req_messages: msg sent to mctp outbound: ",
                    reinterpret_cast<uint8_t *>(req->extra_data),
                    req->data[0] );

        // Send the request to iv_mctpOutboundMsgQ and monitor for a response
        // Retry 2x if no valid response
        send_req_with_retry(req);

        // If the original message was not async, then the requester task is still
        // waiting so we must respond.
        if(!l_asyncReq)
        {
            PLDM_DBG("Responding to message %d", instance_id);
            const int rc = msg_respond(g_outboundPldmReqMsgQ, req);
            if (rc != 0)
            {
                PLDM_ERR("handle_outbound_req_messages: failed to respond to message, rc=%d", rc);
                assert(rc == 0, "handle_outbound_req_messages: failed to respond to message");
            }
        }
        else
        {
            // Parse out if response was at least valid else throw error
            // clean up buffers because caller will not
            // TODO 249702
            PLDM_INF("handle_outbound_req_messages: async req encountered."
                     "This is currently unsupported so we are ignoring result of async request");
        }

        // Instance id is 5 bits so valid numbers are 0-31. Therefore we
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
