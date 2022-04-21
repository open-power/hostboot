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

// Static function used to launch task calling handle_outbound_req_messages on
// the pldmRequester singleton
static void * handle_outbound_req_messages_task(void*)
{
    PLDM_INF("Starting task to issue pldm request messages");
    task_detach();
    Singleton<pldmRequester>::instance().handle_outbound_req_messages();
    return nullptr;
}

std::unique_ptr<pldm_mctp_message> pldmRequester::wait_for_matching_response(const MCTP::outgoing_mctp_msg& i_req,
                                                                             const uint64_t i_max_timeout_milliseconds,
                                                                             uint32_t& o_bad_rsp_count)
{
    bool valid_response_found = false;
    o_bad_rsp_count = 0;

    const auto l_pldm_req_msg = reinterpret_cast<const pldm_msg*>(i_req.data);

    uint64_t l_max_timeout_milliseconds = i_max_timeout_milliseconds;

    std::unique_ptr<pldm_mctp_message> result;

    while ((l_max_timeout_milliseconds > 0) && !result)
    {
        // The PLDM response to our request will actually come back via
        // the g_inboundPldmRspMsgQ
        auto response_msgs = pldmMsgTimeout::pldm_wait_timeout(g_inboundPldmRspMsgQ.queue(), l_max_timeout_milliseconds);

        PLDM_DBG("msg instance_id %d -- pldm_wait_timeout() returned %d records with %lld msec remaining",
            l_pldm_req_msg->hdr.instance_id, response_msgs.size(), l_max_timeout_milliseconds);

        for (auto& rsp_msg : response_msgs)
        {
            auto rsp = g_inboundPldmRspMsgQ.convert_response(rsp_msg);

            if (rsp)
            {
                const auto msg = rsp->pldm();
                const auto hdr = &msg->hdr;

                // make sure this is the message we want
                if((hdr->instance_id == l_pldm_req_msg->hdr.instance_id) &&
                   (hdr->type == l_pldm_req_msg->hdr.type) &&
                   (hdr->command == l_pldm_req_msg->hdr.command))
                {
                    if (valid_response_found)
                    {
                        PLDM_ERR("Received a duplicate PLDM Response type: 0x%02x command 0x%02x instance_id %d to a PLDM request",
                              hdr->type, hdr->command, hdr->instance_id);
                    }
                    else
                    {
                        result = std::move(rsp);
                    }
                }
                else
                {
                    // If it's not a response to a request that we made, it's
                    // likely that the BMC is confused and sending us a response
                    // from a previous IPL. That or the BMC has potentially been
                    // compromised. Either way, look for another one.
                    PLDM_ERR("Received a PLDM Response type: 0x%02x command 0x%02x instance_id %d to a PLDM request we did not send.",
                              hdr->type, hdr->command, hdr->instance_id);
                    o_bad_rsp_count++;
                }
            }
            else
            {
                o_bad_rsp_count++;
            }
        } // loop of response msgs
    } // timeout of message received while loop

    return result;
}

pldm_mctp_response pldmRequester::send_req_with_retry(std::unique_ptr<MCTP::outgoing_mctp_msg> i_req)
{
    // number of attempts to successfully send and receive a response with
    // the current instance req msg
    uint8_t req_attempts = 0;

    // Per PLDM DSP0240 document:
    // Number of request retries = 2 (minimum)
    // Time-out waiting for a response = 5 seconds - 2*100ms (maximum wait)
    // Note: the last retry attempt needs to happen before the max wait time
    // UPDATE: Even though the SPEC indicates max timeout is 5 sec,
    // the DBUS timeout is 20 seconds and hence hostboot also needs to bump up
    // to 20 seconds.
    const uint8_t MAX_ATTEMPTS = 3;  // allow for 2 retries
    const uint64_t MAX_MS_WAIT_PER_ATTEMPT = 20 * MS_PER_SEC; // 20 seconds

    // an interesting count of how many invalid responses are encountered per original msg sent
    uint32_t invalid_rsp_count = 0;

    const auto l_pldm_req_msg = reinterpret_cast<const pldm_msg*>(i_req->data);

    pldm_mctp_response result {
        .error = nullptr,
        .response { false, 0, { } }
    };

    // retry loop
    while (req_attempts++ < MAX_ATTEMPTS)
    {
        const auto errl_and_msg = iv_mctpOutboundMsgQ.sendrecv(move(i_req));

        if (errl_and_msg->errl)
        {
            result.error = errl_and_msg->errl.release();
            break;
        }
        else
        {
            /* PLDM request was sent successfully */

            uint32_t bad_responses = 0;

            // The message queue transfers ownership of the message back to us
            // when it's done sending.
            i_req = move(errl_and_msg->msg);

            // wait for a valid response or timeout on g_inboundPldmRspMsgQ
            const auto response = wait_for_matching_response(*i_req, MAX_MS_WAIT_PER_ATTEMPT, bad_responses);

            // running total of non-matching responses for this req
            invalid_rsp_count += bad_responses;

            if (response)
            {
                result.response = std::move(*response);

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

                result.error = errl;
                errl = nullptr; // ownership transferred to result
                break;
            }
        } // end of else wait for PLDM response
    } // MAX_ATTEMPTS retry loop

    return result;
}

void pldmRequester::handle_outbound_req_messages()
{
    // Does not need to be static as this function should only be called
    // on the singleton pldmRequester
    uint8_t instance_id = 0;

    while (1)
    {
        std::unique_ptr<MCTP::outgoing_mctp_msg> msg;
        auto req = g_outboundPldmReqMsgQ.wait(msg);

        assert(msg.get(),
               "handle_outbound_req_messages was sent an empty message");

        // We will keep track of the instance_id in this loop rather than
        // have the requester manage it. Reinterpret the extra_data as a pldm
        // message so we can easily access the instance_id memeber of the hdr

        const auto l_pldm_req_msg = reinterpret_cast<pldm_msg*>(msg->data);

        // @TODO RTC 249702: Support async messages if needed in this function

        // Update the instance ID and forward the message onto MCTP layer
        l_pldm_req_msg->hdr.instance_id = instance_id;

        PLDM_DBG_BIN("handle_outbound_req_messages: msg sent to mctp outbound: ",
                     &msg->hdr.mctp_msg_type,
                     msg->data_size + sizeof(msg->hdr.mctp_msg_type));

        // Send the request to iv_mctpOutboundMsgQ and monitor for a response
        // Retry 2x if no valid response
        auto response = send_req_with_retry(move(msg));

        g_outboundPldmReqMsgQ.respond(move(req), std::make_unique<pldm_mctp_response>(std::move(response)));

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
    const auto mctpOutboundMsgQ = msg_q_resolve(VFS_ROOT_MSG_MCTP_OUT);

    assert(mctpOutboundMsgQ != nullptr,
           "pldmRequester: VFS_ROOT_MSG_MCTP_OUT resolved to be nullptr, we expected it to be registered during mctp init");

    iv_mctpOutboundMsgQ.queue(mctpOutboundMsgQ);

    // Start cmd daemon first because we want it ready if poll
    // daemon finds something right away
    task_create(handle_outbound_req_messages_task, nullptr);

    PLDM_EXIT("pldmRequester::_init exit");

    return;
}

pldmRequester::pldmRequester(void) : iv_mctpOutboundMsgQ(nullptr) {}
