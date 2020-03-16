/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/pldm_request.H $                         */
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

/* @file pldm_request.H
 *
 * Utilities for making/receiving PLDM requests.
 */

#ifndef PLDM_REQUEST_H__
#define PLDM_REQUEST_H__

// Standard library
#include <vector>
#include <memory>
#include <assert.h>

// Message handling
#include <sys/msg.h>

// MCTP
#include <mctp/mctp_message_types.H>

// libpldm
// TODO: do we want to relocate these headers to src/include?
#include "../../../usr/pldm/extern/base.h"
#include "../../../usr/pldm/extern/platform.h"

namespace PLDM
{

/* @brief Represents a PLDM message (with a payload) that will be sent
 *        through the PLDM message queue to the MCTP stack.
 */
template<size_t MsgSize>
struct mctp_pldm_msg
{
    // This is set by the MCTP stack
    decltype(MCTP::MCTP_MSG_TYPE_PLDM) mctp_message = 0;

    pldm_msg pldm_message { };

    // subtract the size of the existing payload in pldm_msg to compensate
    // for the array trick
    uint8_t body[MsgSize - sizeof(pldm_msg::payload)] = { };
} __attribute__((packed));

/* @brief Makes a PLDM request with a payload to the BMC, and returns the bytes
 *        making up the response.
 *
 * Explicit template parameters:
 *
 * size_t      MsgSize           The size of the PLDM message payload
 *                               (e.g. PLDM_GET_PDR_REQ_BYTES)
 *
 * Runtime parameters:
 *
 * @param[out] o_response_bytes  The bytes of the response. Cleared before
 *                               storing response (i.e. does not concatenate).
 * @param[in]  i_msgQ            The PLDM message queue.

 * @param[in]  i_encoder         The function to encode the PLDM request with
 *                               the given arguments.
 * @param[in]  i_args            The arguments to i_encoder which comprise the
 *                               request (not including the last two pldm_msg
 *                               or message size parameters).
 * @return int                   Return code of message send routine.
 *
 * @note                         If message encoding fails, assert triggers.
 */
template<size_t MsgSize, typename Encoder, typename... Args>
int sendrecv_pldm_request(std::vector<uint8_t>& o_response_bytes,
                          const msg_q_t i_msgQ,
                          const Encoder i_encoder,
                          Args... i_args)
{
    o_response_bytes.clear();

    mctp_pldm_msg<MsgSize> msgbuf { };

    pldm_msg* const pldm_request = &msgbuf.pldm_message;

    int return_code = 0;

    do
    {
        {
            const int rc = i_encoder(i_args...,
                                     pldm_request,
                                     MsgSize);

            assert(rc == PLDM_SUCCESS,
                   "PLDM message encoder at address %p failed with code %d",
                   i_encoder,
                   rc);
        }

        const std::unique_ptr<msg_t, decltype(&msg_free)> msg { msg_allocate(), msg_free };
        msg->data[0] = sizeof(msgbuf);
        msg->extra_data = &msgbuf;

        // Place message on the queue and wait for a response
        return_code = msg_sendrecv(i_msgQ, msg.get());

        if (return_code != 0)
        {
            break;
        }

        // we own the memory pointed to by msg->extra_data
        std::unique_ptr<uint8_t, decltype(&free)>
            extra_data(static_cast<uint8_t*>(msg->extra_data), free);

        o_response_bytes.assign(extra_data.get(),
                                extra_data.get() + msg->data[0]);
    } while (false);

    return return_code;
}

/* @brief Decode a PLDM response.
 *
 * @param[in] i_decoder  The decoder function.
 * @param[in] i_data     The data to decode
 * @param[in] i_args     Arguments to i_decoder, not including the
 *                       payload or payload size arguments.
 * @return               Return value of message decoder function
 */
template<typename Decoder, typename... Args>
pldm_completion_codes decode_pldm_response(const Decoder i_decoder,
                                           const std::vector<uint8_t>& i_data,
                                           Args... i_args)
{
    assert(i_data.size() >= sizeof(pldm_msg_hdr),
           "decode_pldm_response: data is too short to decode");

    const int response =
        i_decoder(reinterpret_cast<const pldm_msg*>(i_data.data()),
                  i_data.size() - sizeof(pldm_msg_hdr),
                  i_args...);

    return static_cast<pldm_completion_codes>(response);
}

}

#endif
