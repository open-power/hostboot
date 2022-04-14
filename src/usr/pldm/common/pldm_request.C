/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/common/pldm_request.C $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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

/* @brief Provides the IPL and runtime implementations of the
 *        sendrecv_pldm_request_impl function.
 */

#include <pldm/pldm_request.H>

using namespace PLDM;

#ifdef __HOSTBOOT_RUNTIME

/* @brief  Check the next incoming MCTP packet and see whether it's a response
 *         to the request we sent. If there is no response available at the time
 *         and io_seconds_remaining is 0, create an error log for the
 *         timeout. If there is time remaining, sleep for 1 second instead.
 *
 * @param[in]     i_pldm_request        The PLDM request that we are waiting on a response for
 * @param[in/out] io_seconds_remaining  The number of seconds remaining before timing out
 * @return        errlHndl_t            Error on timeout, nullptr otherwise
 */
errlHndl_t check_pldm_response(const pldm_msg* const i_pldm_request,
                               int& io_seconds_remaining)
{
    errlHndl_t errl = nullptr;

    const int request_instance_id = i_pldm_request->hdr.instance_id;

    const int return_code = MCTP::get_next_packet();

    if (return_code)
    {
        if (return_code == HBRT_RC_NO_MCTP_PACKET && io_seconds_remaining > 0)
        {
            const uint8_t one_sec = 1;
            const uint8_t zero_nsec = 0;
            nanosleep(one_sec, zero_nsec);

            io_seconds_remaining--;
        }
        else
        {
            if (return_code == HBRT_RC_NO_MCTP_PACKET)
            {
                PLDM_ERR("Timed out waiting for next PLDM message");
            }
            else
            {
                PLDM_ERR("Unexpected Return Code: 0x%.16llX", return_code);
            }

            /*@
             * @moduleid   MOD_MAKE_PLDM_REQUEST_RUNTIME
             * @reasoncode RC_RECV_FAIL
             * @userdata1  Return code returned by MCTP::get_next_packet
             * @userdata2  Header of pldm request
             * @devdesc    Software problem, failed to get next PLDM message
             * @custdesc   A software error occurred during host/bmc
             *             communication
             */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                 MOD_MAKE_PLDM_REQUEST_RUNTIME,
                                 RC_RECV_FAIL,
                                 return_code,
                                 pldmHdrToUint64(*i_pldm_request),
                                 ErrlEntry::NO_SW_CALLOUT);

            addBmcAndHypErrorCallouts(errl);
        }
    }
    else
    {
        const auto& response = PLDM::get_next_response();

        if (!response.empty())
        {
            const auto response_msg = reinterpret_cast<const pldm_msg*>(response.data());

            // If we get a response to some other request, ignore the response and
            // keep looking for the instance ID we were told to expect.
            if (request_instance_id != response_msg->hdr.instance_id)
            {
                PLDM_INF("Received a response with an unexpected instance ID (got %d, expected %d); dropping message",
                         response_msg->hdr.instance_id, request_instance_id);

                PLDM::clear_next_response();
            }
        }
    }

    return errl;
}

errlHndl_t PLDM::sendrecv_pldm_request_impl(const std::vector<uint8_t>& i_msg,
                                            std::vector<uint8_t>& o_response_bytes)
{
    errlHndl_t errl = nullptr;

    // The PLDM instance ID of the next outgoing request
    static int instance_id = 0;

    do
    {

        const auto msgbuf = reinterpret_cast<const mctp_pldm_msg<0>*>(i_msg.data());
        const pldm_msg* const pldm_request = &msgbuf->pldm_message;

        const_cast<pldm_msg*>(pldm_request)->hdr.instance_id = instance_id;

        // This function needs to be reentrant; do this now in case the below
        // code causes a PLDM request to be sent.
        // instance_id is a 5-bit field in the PLDM header.
        instance_id = (instance_id + 1) & 0x1F;

        PLDM::clear_next_response(); // This should already be empty, but we
                                     // clear it here just to make sure.

        // Try to send the PLDM message at least once, at most twice. The
        // difference between a retry and a real message send is that a retry
        // uses the same sequence ID as any retried messages.
        const int retries = 2;

        for (int attempt = 0; PLDM::get_next_response().empty() && attempt < retries; ++attempt)
        {
            if (errl)
            { // ignore errors from previous tries if we're going to try again
                PLDM_INF("Timed out sending PLDM request with instance ID = %d; retrying",
                         pldm_request->hdr.instance_id);
                delete errl;
                errl = nullptr;
            }

            const int return_code = MCTP::send_message(i_msg);

            if (return_code)
            {
                /*@
                 * @moduleid   MOD_MAKE_PLDM_REQUEST_RUNTIME
                 * @reasoncode RC_SEND_FAIL
                 * @userdata1  Return code returned by MCTP::send_message
                 * @userdata2  Header of pldm request
                 * @devdesc    Software problem, failed to decode PLDM message
                 * @custdesc   A software error occurred during host/bmc
                 *             communication
                 */
                errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                     MOD_MAKE_PLDM_REQUEST_RUNTIME,
                                     RC_SEND_FAIL,
                                     return_code,
                                     pldmHdrToUint64(*pldm_request),
                                     ErrlEntry::NO_SW_CALLOUT);
                addBmcAndHypErrorCallouts(errl);

                PLDM_ERR("sendrecv_pldm_request_impl: Unable to send MCTP message (rc=%d, PLID=0x%08x)",
                         return_code, ERRL_GETPLID_SAFE(errl));

                break;
            }

            int sleep_time_sec = 90;

            do
            {
                // Note that if this is a retry, we are sending the request
                // using the same instance ID. This allows the BMC to handle
                // duplicate requests appropriately if for some reason they
                // received our first request and acted on it, but we did not
                // receive their first response.
                errl = check_pldm_response(pldm_request, sleep_time_sec);
            } while (!errl && PLDM::get_next_response().empty());
        }

        // break if we encounter an error
        if (errl)
        {
            break;
        }

        o_response_bytes = move(PLDM::get_next_response());

        PLDM::clear_next_response();

        const size_t MIN_RESP_LEN = sizeof(pldm_msg_hdr) + 1;
        if (o_response_bytes.size() < MIN_RESP_LEN)
        {
            auto hdr64 = pldmHdrToUint64(*reinterpret_cast<pldm_msg*>(o_response_bytes.data()));
            PLDM_ERR("The length of the response to request (0x%lx) was %d bytes when at least %d bytes was expected",
                     hdr64, o_response_bytes.size(), MIN_RESP_LEN);
            /*@
             * @moduleid   MOD_MAKE_PLDM_REQUEST_RUNTIME
             * @reasoncode RC_INVALID_LENGTH
             * @userdata1  Actual Response Length
             * @userdata2  Header of original pldm request
             * @devdesc    PLDM Response from BMC is too small.
             * @custdesc   A host failure occurred
             */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                 MOD_MAKE_PLDM_REQUEST_RUNTIME,
                                 RC_INVALID_LENGTH,
                                 o_response_bytes.size(),
                                 hdr64);
            addBmcErrorCallouts(errl);
            break;
        }
    } while (false);

    return errl;
}

#else

errlHndl_t PLDM::sendrecv_pldm_request_impl(const msg_q_t i_msgQ,
                                            const std::vector<uint8_t>& i_msg,
                                            std::unique_ptr<uint8_t, decltype(&free)>& o_response,
                                            size_t& o_response_length)
{
    errlHndl_t errl = nullptr;

    do
    {
        const std::unique_ptr<msg_t, decltype(&msg_free)> msg { msg_allocate(), msg_free };
        msg->data[0] = i_msg.size();
        msg->extra_data = const_cast<uint8_t*>(i_msg.data());

        // Place message on the queue and wait for a response
        const int return_code = msg_sendrecv(i_msgQ, msg.get());

        const auto msgbuf = reinterpret_cast<const mctp_pldm_msg<0>*>(i_msg.data());
        const pldm_msg* const pldm_request = &(msgbuf->pldm_message);

        if (return_code)
        {
            const uint64_t request_hdr_data = pldmHdrToUint64(*pldm_request);
            /*@
             * @moduleid   MOD_MAKE_PLDM_REQUEST
             * @reasoncode RC_SENDRECV_FAIL
             * @userdata1  Return code returned by msg_sendrecv
             * @userdata2  Header of pldm request
             * @devdesc    Software problem, failed to decode PLDM message
             * @custdesc   A software error occurred during system boot
             */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                 MOD_MAKE_PLDM_REQUEST,
                                 RC_SENDRECV_FAIL,
                                 return_code,
                                 request_hdr_data,
                                 ErrlEntry::ADD_SW_CALLOUT);

            PLDM_ERR("sendrecv_pldm_request_impl: msg_sendrecv failed (rc=%d, PLID=0x%08x)",
                     return_code, ERRL_GETPLID_SAFE(errl));

            errl->collectTrace(PLDM_COMP_NAME);
            break;
        }
        else if (msg->data[1] != REQ_SUCCESS)
        {
            errl = reinterpret_cast<errlHndl_t>(msg->extra_data);
            msg->extra_data = nullptr;
            break;
        }

        // we own the memory pointed to by msg->extra_data
        o_response.reset(static_cast<uint8_t*>(msg->extra_data));
        o_response_length = msg->data[0];

        const size_t MIN_RESP_LEN = sizeof(pldm_msg_hdr) + 1;
        if (o_response_length < MIN_RESP_LEN)
        {
            auto hdr64 = pldmHdrToUint64(*reinterpret_cast<pldm_msg*>(o_response.get()));
            PLDM_ERR("The length of the response to request (0x%lx) was %d bytes when at least %d bytes was expected",
                     hdr64, o_response_length, MIN_RESP_LEN);

            /*@
             * @moduleid   MOD_MAKE_PLDM_REQUEST
             * @reasoncode RC_INVALID_LENGTH
             * @userdata1  Length of response in bytes
             * @userdata2  First bytes of PLDM header
             * @devdesc    Software problem, PLDM response message was too short
             * @custdesc   A software error occurred during system boot
             */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                 MOD_MAKE_PLDM_REQUEST,
                                 RC_INVALID_LENGTH,
                                 o_response_length,
                                 hdr64);
            addBmcErrorCallouts(errl);
            break;
        }
    } while (false);

    return errl;
}

#endif