/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/pldm_response.H $                        */
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

/* @file  pldm_response.H
 *
 * @brief Contains utilities for sending and receiving PLDM responses.
 */
#ifndef PLDM_RESPONSE_H__
#define PLDM_RESPONSE_H__

// Standard library
#include <vector>
#include <memory>

// PLDM/MCTP
#include <mctp/mctp_const.H>
#include <mctp/mctp_message_types.H>
#include <pldm/pldm_reasoncodes.H>
#include <pldm/pldm_errl.H>
#include <pldm/pldmif.H>
#include "../../../src/usr/pldm/common/pldmtrace.H"
#include "../../../src/usr/pldm/extern/base.h"

// IPC
#include <sys/msg.h>

// Error handling
#include <errl/errlentry.H>

namespace PLDM
{

/* This struct is used as a tag for the replace_payload_length_placeholder
 * function. It marks where the payload length should be replaced in an argument
 * list. */
struct payload_length_placeholder_t { };

/* @brief replace_payload_length_placeholder
 *
 *        When called with a length and an argument, this function will return
 *        the length if the argument is of type payload_length_placeholder_t, or
 *        else it will return the argument itself if not. This is used to
 *        substitute the payload length at an arbitrary position in the argument
 *        list to a PLDM response payload encoder, since the positions of the
 *        payload length arguments are not consistent within the libpldm API.
 *
 * @param[in] i_payload_length  The payload length of the PLDM message
 * @param[in] i_t               Arbitrary value
 * @return    T                 i_t or i_payload_length depending on the type of i_t
 */

template<typename T>
inline const T& replace_payload_length_placeholder(const size_t i_payload_length,
                                                   const T& i_t)
{
    return i_t;
}

inline const size_t replace_payload_length_placeholder(const size_t i_payload_length,
                                                       payload_length_placeholder_t)
{
    return i_payload_length;
}

/* @brief pldm_response_t
 *
 *        Represents an MCTP IPC message structure for a PLDM response message
 *        with a fixed-size payload header (and optional variable-size payload
 *        body, which is allocated "after the end" of the struct).
 */
template<size_t PayloadHeaderSize>
struct pldm_response_t
{
    // Filled in by MCTP layer
    decltype(MCTP::MCTP_MSG_TYPE_PLDM) mctp_msg_type = 0;

    pldm_msg pldm_message { };

    // Any variable-length information will be positioned after this member
    uint8_t pldm_payload[PayloadHeaderSize - sizeof(pldm_msg::payload)];
};

/* @brief send_pldm_response
 *
 *        Encodes a PLDM response message and sends it on the given message queue.
 *
 * @param[in] i_msgQ            Handle to outgoing MCTP message queue
 * @param[in] i_encoder         PLDM message encoder function
 * @param[in] i_payload_size    Size of message payload
 * @param[in] i_args...         Arguments to i_encoder
 * @return    errlHndl_t        Error if any, otherwise nullptr.
 */
template<size_t PayloadHeaderSize, typename Encoder, typename... Args>
errlHndl_t send_pldm_response(const msg_q_t i_msgQ,
                              const Encoder i_encoder,
                              const size_t i_payload_size,
                              Args... i_args)
{
    using response_t = pldm_response_t<PayloadHeaderSize>;

    const size_t mctp_message_size =
        sizeof(response_t)
        + i_payload_size;

    std::vector<uint8_t> response_alloc(mctp_message_size);

    const auto response = reinterpret_cast<response_t*>(response_alloc.data());

    {
        const int rc = i_encoder(replace_payload_length_placeholder(i_payload_size, i_args)...,
                                 &response->pldm_message);

        assert(rc == PLDM_SUCCESS,
               "Response encoder at %p failed with code %d (mctp message size = %d)",
               i_encoder, rc, mctp_message_size);
    }

    std::unique_ptr<msg_t, decltype(&msg_free)> msg(msg_allocate(), msg_free);

    msg->type = MCTP::MSG_SEND_PLDM;
    msg->data[0] = mctp_message_size;
    msg->extra_data = response;

    errlHndl_t errl = nullptr;

    {
        const int rc = msg_sendrecv(i_msgQ, msg.get());

        if (rc != 0)
        {
            /*
             * @errortype  ERRL_SEV_UNRECOVERABLE
             * @moduleid   MOD_SEND_PLDM_RESPONSE
             * @reasoncode RC_SEND_FAIL
             * @userdata1  RC returned from message send routine
             * @userdata2  PLDM response message encoder function
             * @devdesc    Software problem, failed to send PLDM IPC message
             * @custdesc   A software error occurred during system boot
             */
            errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           MOD_SEND_PLDM_RESPONSE,
                                           RC_SEND_FAIL,
                                           rc,
                                           reinterpret_cast<uint64_t>(i_encoder),
                                           ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        }
        else if (msg->data[1] != REQ_SUCCESS)
        {
            errl = reinterpret_cast<errlHndl_t>(msg->extra_data);
        }

        msg->extra_data = nullptr;
    }

    return errl;
}

/* @brief Decode a PLDM request.
 *
 * @param[in] i_decoder      The decoder function.
 * @param[in] i_msg          The PLDM message to decode
 * @param[in] i_payload_len  Length of PLDM message payload in i_msg
 * @param[in] i_args         Arguments to i_decoder, not including the
 *                           payload or payload size arguments.
 * @return                   Error if any, otherwise nullptr.
 */
template<typename Decoder, typename... Args>
errlHndl_t decode_pldm_request(const Decoder i_decoder,
                               const pldm_msg* i_msg,
                               const size_t i_payload_len,
                               Args... i_args)
{
    using namespace ERRORLOG;

    errlHndl_t errl = nullptr;

    const int decoder_rc =
        i_decoder(i_msg,
                  i_payload_len,
                  i_args...);

    if(decoder_rc != PLDM_SUCCESS)
    {
        PLDM_INF("Failed to decode PLDM request (decoder at %p, payload length %u)",
                 i_decoder,
                 static_cast<unsigned int>(i_payload_len));

        const uint64_t response_hdr_data = pldmHdrToUint64(*i_msg);

        /*
         * @errortype  ERRL_SEV_UNRECOVERABLE
         * @moduleid   MOD_SEND_PLDM_RESPONSE
         * @reasoncode RC_MSG_DECODE_FAIL
         * @userdata1  RC returned from decode function
         * @userdata2  PLDM Header (3 bytes)
         * @devdesc    Software problem, failed to decode PLDM message
         * @custdesc   A software error occurred during system boot
         */
        errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                             MOD_SEND_PLDM_RESPONSE,
                             RC_MSG_DECODE_FAIL,
                             decoder_rc,
                             response_hdr_data,
                             ErrlEntry::NO_SW_CALLOUT);

        addBmcErrorCallouts(errl);
    }

    return errl;
}

}

#endif
