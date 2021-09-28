/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/pldm/pldm_request.H $                         */
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

#ifdef __HOSTBOOT_RUNTIME
#include <mctp/mctp_const.H>
#include <mctp/mctpif_rt.H>
#include <runtime/interface.h>
#include <sys/time.h>
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
 */
template<size_t MsgSize>
struct mctp_pldm_msg
{
    decltype(MCTP::MCTP_MSG_TYPE_PLDM) mctp_message = 0;

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
struct mctp_pldm_msg<1>
{
    decltype(MCTP::MCTP_MSG_TYPE_PLDM) mctp_message = 0;

    pldm_msg pldm_message { };
} __attribute__((packed));

/* @brief Represents a PLDM message, without a payload, that will be sent
 *        through the PLDM message queue to the MCTP stack.
 *
 * @note  In this case, we will pass an extra byte ( sizeof(pldm_msg::payload) )
 *        down to the MCTP layer. The MCTP layer will put this on the LPC bus
 *        and it will get propagated to the BMC. This is okay because for
 *        commands with no PLDM message payload the BMC will ignore the size and
 *        just look at the first 3 bytes that make up the header.
 */
template<>
struct mctp_pldm_msg<0>
{
    decltype(MCTP::MCTP_MSG_TYPE_PLDM) mctp_message = 0;

    pldm_msg pldm_message { };
} __attribute__((packed));

/* @brief  Assign the contents of a memory region to the given vector.
 *         This is a public interface meant to be overloaded by callers of
 *         sendrecv_pldm_request to customize memory management.
 *
 * param[in/out] io_response_container  The container to insert data into.
 * param[in/out] io_data                The data to insert.
 * param[in]     i_data_length          The length of the data in io_data.
 *
 * @note Callers of sendrecv_pldm_request who use a custom ResponseContainer can
 *       overload this function to customize how data is owned and
 *       deallocated. This function should either copy the data from io_data
 *       into the container, or else take ownership of the data directly and
 *       call io_data.release().
 */
inline void sendrecv_pldm_request_assign_response_container(std::vector<uint8_t>& io_response_container,
                                                            std::unique_ptr<uint8_t, decltype(&free)>& io_data,
                                                            const size_t i_data_length)
{
    io_response_container.assign(io_data.get(), io_data.get() + i_data_length);
}

/* @brief sendrecv_pldm_request
 *
 *        Encode and send a PLDM request with a fixed-size payload section and a
 *        subsequent variable-size payload section to the BMC, and then receive
 *        a reply.
 *
 * @param[out] o_response_bytes  Array of bytes of the response from the BMC
 * @param[in] i_payload_size     Length of the variable length payload
 * @param[in] i_msgQ             Handle to the outgoing PLDM request message queue
 * @param[in] i_encoder          Message encoder function
 * @param[in] i_args...          Arguments to the encoder function, not including the
 *                               pldm_msg* and payload size.
 * @return errlHndl_t            Error if any, otherwise nullptr.
 */
template<size_t MsgSize, typename ResponseContainer, typename Encoder, typename... Args>
errlHndl_t sendrecv_pldm_request(ResponseContainer& o_response_bytes,
                                 const size_t i_payload_size,
                                 const msg_q_t i_msgQ,
                                 const Encoder i_encoder,
                                 Args... i_args)
{
    errlHndl_t errl = nullptr;
    o_response_bytes.clear();

    std::vector<uint8_t> msgbuf_bytes(sizeof(mctp_pldm_msg<MsgSize>) + i_payload_size);

    const auto msgbuf = reinterpret_cast<mctp_pldm_msg<MsgSize>*>(msgbuf_bytes.data());

    msgbuf_bytes[0] = MCTP::MCTP_MSG_TYPE_PLDM;

    pldm_msg* const pldm_request = &msgbuf->pldm_message;

    do
    {
        {
            const int encoder_rc = i_encoder(i_args...,
                                             pldm_request,
                                             MsgSize + i_payload_size);

            assert(encoder_rc == PLDM_SUCCESS,
                   "PLDM message encoder at address %p failed with code %d",
                   i_encoder,
                   encoder_rc);
        }

#ifndef __HOSTBOOT_RUNTIME
        const std::unique_ptr<msg_t, decltype(&msg_free)> msg { msg_allocate(), msg_free };
        msg->data[0] = msgbuf_bytes.size();
        msg->extra_data = msgbuf_bytes.data();

        // Place message on the queue and wait for a response
        const int return_code = msg_sendrecv(i_msgQ, msg.get());

        if (return_code)
        {
            const uint64_t request_hdr_data = pldmHdrToUint64(*pldm_request);
            /*
            * @errortype  ERRL_SEV_UNRECOVERABLE
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
            errl->collectTrace(PLDM_COMP_NAME);
            break;
        }
        else if (msg.get()->data[1] != REQ_SUCCESS)
        {
            errl = reinterpret_cast<errlHndl_t>(msg.get()->extra_data);
            msg->extra_data = nullptr;
            break;
        }

        // we own the memory pointed to by msg->extra_data
        std::unique_ptr<uint8_t, decltype(&free)>
            extra_data(static_cast<uint8_t*>(msg->extra_data), free);

        sendrecv_pldm_request_assign_response_container(o_response_bytes, extra_data, msg->data[0]);
#else
        int return_code = MCTP::send_message(msgbuf_bytes);

        if(return_code)
        {
            /*
            * @errortype  ERRL_SEV_UNRECOVERABLE
            * @moduleid   MOD_MAKE_PLDM_REQUEST
            * @reasoncode RC_SEND_FAIL
            * @userdata1  Return code returned by MCTP::send_message
            * @userdata2  Header of pldm request
            * @devdesc    Software problem, failed to decode PLDM message
            * @custdesc   A software error occurred during host/bmc
            *             communication
            */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                  MOD_MAKE_PLDM_REQUEST,
                                  RC_SEND_FAIL,
                                  return_code,
                                  pldmHdrToUint64(*pldm_request),
                                  ErrlEntry::NO_SW_CALLOUT);
            addBmcAndHypErrorCallouts(errl);
            break;
        }

        uint8_t sleep_time_sec = 0;
        do
        {
            return_code = MCTP::get_next_packet();
            if(return_code)
            {
                if(return_code == HBRT_RC_NO_MCTP_PACKET)
                {
                    constexpr uint8_t one_sec = 1;
                    constexpr uint8_t zero_nsec = 0;
                    nanosleep(one_sec, zero_nsec);
                    constexpr uint8_t sleep_timeout_sec = 90;
                    if(++sleep_time_sec < sleep_timeout_sec) { continue; }
                }
                /*
                * @errortype  ERRL_SEV_UNRECOVERABLE
                * @moduleid   MOD_MAKE_PLDM_REQUEST
                * @reasoncode RC_RECV_FAIL
                * @userdata1  Return code returned by MCTP::get_next_packet
                * @userdata2  Header of pldm request
                * @devdesc    Software problem, failed to get next PLDM message
                * @custdesc   A software error occurred during host/bmc
                *             communication
                */
                errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                      MOD_MAKE_PLDM_REQUEST,
                                      RC_RECV_FAIL,
                                      return_code,
                                      pldmHdrToUint64(*pldm_request),
                                      ErrlEntry::NO_SW_CALLOUT);

                addBmcAndHypErrorCallouts(errl);
                break;
            }
        }while (PLDM::get_next_response().empty());

        o_response_bytes = PLDM::get_next_response();
        PLDM::clear_next_response();
#endif

    } while (false);

    return errl;
}

/* @brief sendrecv_pldm_request
 *
 *        Encode and send a PLDM request with a fixed-size payload section and a
 *        subsequent variable-size payload section to the BMC, and then receive
 *        a reply.
 *
 * @param[out] o_response_bytes  Array of bytes of the response from the BMC
 * @param[in] i_payload_bytes    Variable-length payload for the message
 * @param[in] i_msgQ             Handle to the outgoing PLDM request message queue
 * @param[in] i_encoder          Message encoder function
 * @param[in] i_args...          Arguments to the encoder function, not including the
 *                               pldm_msg* and payload size.
 * @return errlHndl_t            Error if any, otherwise nullptr.
 */
template<size_t MsgSize, typename ResponseContainer, typename Encoder, typename... Args>
errlHndl_t sendrecv_pldm_request(ResponseContainer& o_response_bytes,
                                 const std::vector<uint8_t>& i_payload_bytes,
                                 const msg_q_t i_msgQ,
                                 const Encoder i_encoder,
                                 Args... i_args)
{
    return sendrecv_pldm_request<MsgSize>(o_response_bytes,
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
 * @param[out] o_response_bytes  The bytes of the response. Cleared before
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
template<size_t MsgSize, typename ResponseContainer, typename Encoder, typename... Args>
errlHndl_t sendrecv_pldm_request(ResponseContainer& o_response_bytes,
                                 const msg_q_t i_msgQ,
                                 const Encoder i_encoder,
                                 Args... i_args)
{
    return sendrecv_pldm_request<MsgSize>(o_response_bytes,
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

        /*
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
