/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/pldm_request.H $                         */
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

/** @file pldm_request.H
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

// Error logs
#include <errl/errlentry.H>

// MCTP
#include <mctp/mctp_message_types.H>

// libpldm
#include <base.h>
#include <platform.h>

// PLDM module
#include <pldm/pldmif.H>
#include <pldm/pldm_const.H>
#include <pldm/pldm_errl.H>
#include <pldm/pldm_reasoncodes.H>
#include <pldm/pldm_trace.H>

#ifdef __HOSTBOOT_RUNTIME
#include <mctp/mctp_const.H>
#include <mctp/mctpif_rt.H>
#include <runtime/interface.h>
#include <sys/time.h>
#include <util/runtime/rt_fwreq_helper.H>
#endif


using namespace ERRORLOG;

namespace PLDM
{

// The pldmRequester task that manages outbound PLDM requests will set
// the instance ID in the PLDM header to the correct value. For all of
// the encode functions just pass in a default ID (0x00)
constexpr uint8_t DEFAULT_INSTANCE_ID = 0x00;

/* @brief Represents a PLDM message (with a payload) that will be sent
 *        through the PLDM message queue to the MCTP stack.
 *
 * @note  The outgoing_mctp_msg member is used by the MCTP stack to route the
 *        MCTP packet.
 */
template<size_t MsgSize>
struct pldm_mctp_msgbuf
{
    MCTP::outgoing_mctp_msg mctp_msg;

    pldm_msg pldm_message { };

    // subtract the size of the existing payload in pldm_msg to compensate
    // for the array trick
    uint8_t body[MsgSize - sizeof(pldm_msg::payload)] = { };
} __attribute__((packed));

/* @brief Represents a PLDM message, with a single byte payload, that will be
 *        sent through the PLDM message queue to the MCTP stack.
 *
 */
template<>
struct pldm_mctp_msgbuf<1>
{
    MCTP::outgoing_mctp_msg mctp_msg;

    pldm_msg pldm_message { };
} __attribute__((packed));

/* @brief Represents a PLDM message, without a payload, that will be sent
 *        through the PLDM message queue to the MCTP stack.
 */
template<>
struct pldm_mctp_msgbuf<0>
{
    MCTP::outgoing_mctp_msg mctp_msg;

    pldm_msg pldm_message { };
} __attribute__((packed));

#ifdef __HOSTBOOT_RUNTIME
/* @brief sendrecv_pldm_request_impl
 *        Implementation function for sendrecv_pldm_request
 *
 * @param[in] i_msg                  The outgoing PLDM message
 * @param[out] o_response_pldm_body  The PLDM response
 * @return errlHndl_t                Error if any, otherwise nullptr
 */
errlHndl_t sendrecv_pldm_request_impl(MCTP::outgoing_mctp_msg* i_msg,
                                      std::vector<uint8_t>& o_response_pldm_body);
#else
/* @brief sendrecv_pldm_request_impl
 *        Implementation function for sendrecv_pldm_request
 *
 * @param[in] i_msgQ                 Handle to the PLDM outgoing-request message queue
 * @param[in] i_msg                  The outgoing PLDM message
 * @param[out] o_response_pldm_body  The PLDM response
 * @return errlHndl_t                Error if any, otherwise nullptr
 */
errlHndl_t sendrecv_pldm_request_impl(pldm_outbound_req_msgq_t i_msgQ,
                                      std::unique_ptr<MCTP::outgoing_mctp_msg> i_msg,
                                      std::vector<uint8_t>& o_response_pldm_body);
#endif

/* @brief sendrecv_pldm_request
 *
 *        Encode and send a PLDM request with a fixed-size payload section and a
 *        subsequent variable-size payload section to the BMC, and then receive
 *        a reply.
 *
 * @param[out] o_response_body   Array of bytes of the response from the BMC
 * @param[in] i_payload_size     Length of the variable length payload
 * @param[in] i_msgQ             Handle to the outgoing PLDM request message queue
 * @param[in] i_encoder          Message encoder function
 * @param[in] i_args...          Arguments to the encoder function, not including the
 *                               pldm_msg* and payload size.
 * @return errlHndl_t            Error if any, otherwise nullptr.
 */
template<size_t MsgSize, typename Encoder, typename... Args>
errlHndl_t sendrecv_pldm_request(std::vector<uint8_t>& o_response_body,
                                 const size_t i_payload_size,
                                 pldm_outbound_req_msgq_t i_msgQ,
                                 const Encoder i_encoder,
                                 Args... i_args)
{
    using pldm_mctp_msgbuf_t = pldm_mctp_msgbuf<MsgSize>;

    errlHndl_t errl = nullptr;
    o_response_body.clear();

    const size_t total_buffer_size = sizeof(pldm_mctp_msgbuf_t) + i_payload_size;

    std::unique_ptr<MCTP::outgoing_mctp_msg> msgbuf {
        reinterpret_cast<MCTP::outgoing_mctp_msg*>(new uint8_t[total_buffer_size])
    };

    msgbuf->data_size = total_buffer_size - sizeof(pldm_mctp_msgbuf_t::mctp_msg);
    msgbuf->hdr.tag_owner = false; // Hostboot doesn't send tags
    msgbuf->hdr.msg_tag = 0;       // itself; they only matter when
                                   // sending replies to the BMC.
    msgbuf->hdr.mctp_msg_type = MCTP::MCTP_MSG_TYPE_PLDM;

    const auto pldm_request = reinterpret_cast<pldm_msg*>(msgbuf->data);

    const int encoder_rc = i_encoder(i_args...,
                                     pldm_request,
                                     MsgSize + i_payload_size);

    assert(encoder_rc == PLDM_SUCCESS,
           "PLDM message encoder at address %p failed with code %d",
           i_encoder,
           encoder_rc);

#ifdef __HOSTBOOT_RUNTIME
    PLDM::set_waiting_for_response(true);
    setMctpBridgeState(hostInterfaces::MCTP_BRIDGE_ENABLED);

    errl = sendrecv_pldm_request_impl(msgbuf.get(), o_response_body);

    setMctpBridgeState(hostInterfaces::MCTP_BRIDGE_DISABLED);
    PLDM::set_waiting_for_response(false);

    // If a request message was queued while waiting for a response,
    // clear out that request as HBRT will never do a host_callback
    // for incoming MCTP packets that we aren't ready to handle.
    // Hostboot will rely on BMC to send the requests again.
    // Doing a PLDM host callback on a non-empty next request has
    // caused an mctp queue overrun
    const auto& skipReqMsg = PLDM::get_next_request();

    if (!skipReqMsg.empty())
    {
        PLDM_INF("sendrecv_pldm_request: discarding queued PLDM request as "
                 "new one arrived while hostboot was busy handling another request.");
        PLDM_INF_BIN("Discarded PLDM request msg header",
                     skipReqMsg.pldm_data.data(),
                     std::min(skipReqMsg.pldm_data.size(), sizeof(pldm_msg_hdr)));
        PLDM::clear_next_request();
    }
#else
    errl = sendrecv_pldm_request_impl(i_msgQ, move(msgbuf), o_response_body);
#endif

    return errl;
}

/* @brief sendrecv_pldm_request
 *
 *        Encode and send a PLDM request with a fixed-size payload section and a
 *        subsequent variable-size payload section to the BMC, and then receive
 *        a reply.
 *
 * @param[out] o_response_body   Array of bytes of the response from the BMC
 * @param[in] i_payload_bytes    Variable-length payload for the message
 * @param[in] i_msgQ             Handle to the outgoing PLDM request message queue
 * @param[in] i_encoder          Message encoder function
 * @param[in] i_args...          Arguments to the encoder function, not including the
 *                               pldm_msg* and payload size.
 * @return errlHndl_t            Error if any, otherwise nullptr.
 */
template<size_t MsgSize, typename Encoder, typename... Args>
errlHndl_t sendrecv_pldm_request(std::vector<uint8_t>& o_response_body,
                                 const std::vector<uint8_t>& i_payload_bytes,
                                 const pldm_outbound_req_msgq_t i_msgQ,
                                 const Encoder i_encoder,
                                 Args... i_args)
{
    return sendrecv_pldm_request<MsgSize>(o_response_body,
                                          i_payload_bytes.size(),
                                          i_msgQ,
                                          i_encoder,
                                          i_args...);
}

/* @brief Makes a PLDM request with a fixed-size payload to the BMC, and returns
 *        the bytes making up the response.
 *
 * Explicit template parameters:
 *
 * size_t      MsgSize           The size of the PLDM message payload
 *                               (e.g. PLDM_GET_PDR_REQ_BYTES)
 *
 * Runtime parameters:
 *
 * @param[out] o_response_body   The bytes of the response. Cleared before
 *                               storing response (i.e. does not concatenate).
 * @param[in]  i_msgQ            The PLDM message queue.
 * @param[in]  i_encoder         The function to encode the PLDM request with
 *                               the given arguments.
 * @param[in]  i_args            The arguments to i_encoder which comprise the
 *                               request (not including the last two pldm_msg
 *                               or message size parameters).
 * @return errlHndl_t            Contains error log if one occurred otherwise
 *                               returns nullptr
 *
 * @note                         If message encoding fails, assert triggers.
 */
template<size_t MsgSize, typename Encoder, typename... Args>
errlHndl_t sendrecv_pldm_request(std::vector<uint8_t>& o_response_body,
                                 const pldm_outbound_req_msgq_t i_msgQ,
                                 const Encoder i_encoder,
                                 Args... i_args)
{
    return sendrecv_pldm_request<MsgSize>(o_response_body,
                                          std::vector<uint8_t> { }, // Empty variable-size payload
                                          // portion (this does not make any
                                          // dynamic allocation at runtime)
                                          i_msgQ,
                                          i_encoder,
                                          i_args...);
}

/* @brief Decode a PLDM response.
 *
 * @param[in] i_decoder  The decoder function.
 * @param[in] i_data     The data to decode
 * @param[in] i_args     Arguments to i_decoder, not including the
 *                       payload or payload size arguments.
 * @return               Return value of message decoder function
 */
template<typename Decoder, typename Container, typename... Args>
errlHndl_t decode_pldm_response(const Decoder i_decoder,
                                const Container& i_data,
                                Args... i_args)
{
    errlHndl_t errl = nullptr;
    assert(i_data.size() >= sizeof(pldm_msg_hdr),
           "decode_pldm_response: data is too short to decode");

    pldm_msg* const pldm_response = const_cast<pldm_msg* >(
                reinterpret_cast<const pldm_msg*>(i_data.data()));

    const int decoder_rc =
        i_decoder(pldm_response,
                  i_data.size() - sizeof(pldm_msg_hdr),
                  i_args...);

    if(decoder_rc != PLDM_SUCCESS)
    {
        const uint64_t response_hdr_data = pldmHdrToUint64(*pldm_response);

        /*@
         * @errortype  ERRL_SEV_UNRECOVERABLE
         * @moduleid   MOD_DECODE_RESPONSE
         * @reasoncode RC_MSG_DECODE_FAIL
         * @userdata1  RC returned from decode function
         * @userdata2  PLDM Header
         * @devdesc    Software problem, failed to decode PLDM message
         * @custdesc   A software error occurred during system boot
         */
        errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                              MOD_DECODE_RESPONSE,
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
