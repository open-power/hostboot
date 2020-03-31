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

// Error logs
#include <errl/errlentry.H>

// MCTP
#include <mctp/mctp_message_types.H>

// libpldm
// TODO: do we want to relocate these headers to src/include?
#include "../../../usr/pldm/extern/base.h"
#include "../../../usr/pldm/extern/platform.h"
#include <pldm/pldmif.H>
#include <pldm/pldm_const.H>

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
    // This is set by the MCTP stack
    decltype(MCTP::MCTP_MSG_TYPE_PLDM) mctp_message = 0;

    pldm_msg pldm_message { };

    // subtract the size of the existing payload in pldm_msg to compensate
    // for the array trick
    uint8_t body[MsgSize - sizeof(pldm_msg::payload)] = { };
} __attribute__((packed));

/* @brief Represents a PLDM message (without a payload) that will be sent
 *        through the PLDM message queue to the MCTP stack.
 */
template<>
struct mctp_pldm_msg<0>
{
    // This is set by the MCTP stack
    decltype(MCTP::MCTP_MSG_TYPE_PLDM) mctp_message = 0;

    pldm_msg pldm_message { };
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
 * @return errlHndl_t            Contains error log if one occurred otherwise
 *                               returns nullptr
 *
 * @note                         If message encoding fails, assert triggers.
 */
template<size_t MsgSize, typename Encoder, typename... Args>
errlHndl_t sendrecv_pldm_request_payload(std::vector<uint8_t>& o_response_bytes,
                          const msg_q_t i_msgQ,
                          const Encoder i_encoder,
                          Args... i_args)
{
    errlHndl_t errl = nullptr;
    o_response_bytes.clear();

    mctp_pldm_msg<MsgSize> msgbuf { };

    pldm_msg* const pldm_request = &msgbuf.pldm_message;

    do
    {
        {
            const int encoder_rc = i_encoder(i_args...,
                                     pldm_request,
                                     MsgSize);

            assert(encoder_rc == PLDM_SUCCESS,
                   "PLDM message encoder at address %p failed with code %d",
                   i_encoder,
                   encoder_rc);

        }

        const std::unique_ptr<msg_t, decltype(&msg_free)> msg { msg_allocate(), msg_free };
        msg->data[0] = sizeof(msgbuf);
        msg->extra_data = &msgbuf;

        // Place message on the queue and wait for a response
        const int return_code = msg_sendrecv(i_msgQ, msg.get());

        if(return_code)
        {
            const uint64_t request_hdr_data = pldmHdrToUint64(*pldm_request);
            /*
            * @errortype  ERRL_SEV_UNRECOVERABLE
            * @moduleid   MOD_MAKE_PLDM_REQUEST_PAYLOAD
            * @reasoncode RC_SENDRECV_FAIL
            * @userdata1  Return code returned by msg_sendrecv
            * @userdata2  Header of pldm request
            * @devdesc    Software problem, sendrecv from PLDM->MCTP layers
            * @custdesc   A software error occurred during system boot
            */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                  MOD_MAKE_PLDM_REQUEST_PAYLOAD,
                                  RC_SENDRECV_FAIL,
                                  return_code,
                                  request_hdr_data,
                                  ErrlEntry::ADD_SW_CALLOUT);
            errl->collectTrace(PLDM_COMP_NAME);
            break;
        }
        else if(msg->data[1] != REQ_SUCCESS)
        {
            errl = reinterpret_cast<errlHndl_t>(msg->extra_data);
            msg->extra_data = 0;
            break;
        }

        // we own the memory pointed to by msg->extra_data
        std::unique_ptr<uint8_t, decltype(&free)>
            extra_data(static_cast<uint8_t*>(msg->extra_data), free);

        o_response_bytes.assign(extra_data.get(),
                                extra_data.get() + msg->data[0]);

    } while (false);


    return errl;
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
errlHndl_t decode_pldm_response(const Decoder i_decoder,
                                           const std::vector<uint8_t>& i_data,
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
          * @moduleid   MODE_DECODE_RESPONSE
          * @reasoncode RC_MSG_DECODE_FAIL
          * @userdata1  RC returned from decode function
          * @userdata2  PLDM Header
          * @devdesc    Software problem, failed to decode PLDM message
          * @custdesc   A software error occurred during system boot
          */
        errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                              MODE_DECODE_RESPONSE,
                              RC_MSG_DECODE_FAIL,
                              decoder_rc,
                              response_hdr_data,
                              ErrlEntry::NO_SW_CALLOUT);

        errl->collectTrace(PLDM_COMP_NAME);

        // Call out service processor / BMC firmware as high priority
        errl->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                  HWAS::SRCI_PRIORITY_HIGH);

        // Call out Hostboot firmware as medium priority
        errl->addProcedureCallout( HWAS::EPUB_PRC_HB_CODE,
                                    HWAS::SRCI_PRIORITY_MED );
    }

    return errl;
}

}

#endif
