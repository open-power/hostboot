/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/pldm_response.H $                        */
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

/** @file  pldm_response.H
 *
 *  @brief Contains utilities for sending and receiving PLDM responses.
 */
#ifndef PLDM_RESPONSE_H__
#define PLDM_RESPONSE_H__

// Standard library
#include <vector>
#include <memory>

// PLDM/MCTP
#include <mctp/mctp_const.H>
#include <pldm/pldm_reasoncodes.H>
#include <pldm/pldm_errl.H>
#include <pldm/pldmif.H>
#include <pldm/pldm_trace.H>
#include <base.h>

// IPC
#include <sys/msg.h>

// Error handling
#include <errl/errlentry.H>
#include <errl/errlmanager.H>

#ifdef __HOSTBOOT_RUNTIME
#include <mctp/mctpif_rt.H>
#include <runtime/interface.h>
#include <sys/time.h>
#include <util/runtime/rt_fwreq_helper.H>
#endif

using namespace ERRORLOG;

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
    decltype(MCTP::MCTP_MSG_TYPE_PLDM) mctp_msg_type = 0;

    pldm_msg pldm_message { };

    // Any variable-length information will be positioned after this member
    uint8_t pldm_payload[PayloadHeaderSize - sizeof(pldm_msg::payload)];
};

// Special value for send_pldm_response indicating an empty variable-size
// payload portion.
const size_t PLDM_RESPONSE_EMPTY_PAYLOAD_SIZE = 0;

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
    errlHndl_t errl = nullptr;
    using response_t = pldm_response_t<PayloadHeaderSize>;

    // This is an arbitrary but hopefully unique value used to catch any
    // accidental buffer overflows from the message encoder functions.
    const uint64_t buffer_canary = 0x0BADF00DDEADBEEFull;

    const size_t mctp_message_size =
        sizeof(response_t)
        + i_payload_size;

    // Allocate enough space for the message and the canary, then store the
    // canary at the end of the message. After the encoder runs, check the
    // canary to make sure that it didn't get overwritten, and if it did, we
    // have detected an overflow and we assert.
    std::vector<uint8_t> response_alloc(mctp_message_size + sizeof(buffer_canary));
    response_alloc[0] = MCTP::MCTP_MSG_TYPE_PLDM;

    memcpy(&response_alloc[mctp_message_size],
           &buffer_canary,
           sizeof(buffer_canary));

    const auto response = reinterpret_cast<response_t*>(response_alloc.data());

    {
        const int rc = i_encoder(replace_payload_length_placeholder(i_payload_size, i_args)...,
                                 &response->pldm_message);

        assert(rc == PLDM_SUCCESS,
               "Response encoder at address %p failed with code %d (mctp message size = %d)",
               i_encoder, rc, mctp_message_size);
    }

    {
        uint64_t real_canary = 0;

        memcpy(&real_canary,
               &response_alloc[mctp_message_size],
               sizeof(real_canary));

        assert(buffer_canary == real_canary,
               "Response encoder at address %p corrupted the buffer canary",
               i_encoder);
    }


#ifndef __HOSTBOOT_RUNTIME
    std::unique_ptr<msg_t, decltype(&msg_free)> msg(msg_allocate(), msg_free);

    msg->type = MCTP::MSG_SEND_PLDM;
    msg->data[0] = mctp_message_size;
    msg->extra_data = response;

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
            errl = new ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                 MOD_SEND_PLDM_RESPONSE,
                                 RC_SEND_FAIL,
                                 rc,
                                 reinterpret_cast<uint64_t>(i_encoder),
                                 ErrlEntry::ADD_SW_CALLOUT);
        }
        else if (msg->data[1] != REQ_SUCCESS)
        {
            errl = reinterpret_cast<errlHndl_t>(msg->extra_data);
        }

        msg->extra_data = nullptr;
    }
#else
    // Make sure mctp bridge is enabled
    setMctpBridgeState(hostInterfaces::MCTP_BRIDGE_ENABLED);

    // trim the buffer canary
    response_alloc.resize(response_alloc.size()-sizeof(buffer_canary));
    int return_code = MCTP::send_message(response_alloc);

    if(return_code)
    {
        /*
        * @errortype  ERRL_SEV_UNRECOVERABLE
        * @moduleid   MOD_SEND_PLDM_RESPONSE
        * @reasoncode RC_SEND_FAIL
        * @userdata1  Return code returned by MCTP::send_message
        * @userdata2  Header of pldm request
        * @devdesc    Software problem, failed to send PLDM resp over MCTP
        * @custdesc   A software error occurred during system runtime
        */
        errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                             MOD_SEND_PLDM_RESPONSE,
                             RC_SEND_FAIL,
                             return_code,
                             pldmHdrToUint64(response->pldm_message),
                             ErrlEntry::NO_SW_CALLOUT);
        addBmcAndHypErrorCallouts(errl);
    }

    // Make sure mctp bridge is disabled
    setMctpBridgeState(hostInterfaces::MCTP_BRIDGE_DISABLED);

#endif

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

/* @brief send_cc_only_response
 *
 *        Send a PLDM response that consists solely of a PLDM header and a
 *        completion code.
 *
 * @param[in] i_msgQ  Handle to the MCTP outgoing response queue
 * @param[in] i_msg   Message to respond to
 * @param[in] i_cc    Completion code
 */
inline void send_cc_only_response(const msg_q_t i_msgQ,
                                  const pldm_msg* const i_msg,
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

}

#endif
