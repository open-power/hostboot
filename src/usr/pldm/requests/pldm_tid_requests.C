/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/requests/pldm_tid_requests.C $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2022                        */
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
#include <pldm/requests/pldm_tid_requests.H>
#include <pldm/pldm_request.H>
#include <pldm/pldm_trace.H>
#include "pldm_request_utils.H"
#include <sys/msg.h>
// VFS_ROOT_MSG_PLDM_REQ_OUT
#include <sys/vfs.h>

/* @file pldm_tid_requests.C
 *
 * This file provides the implementation of PLDM TID operations
 */

namespace PLDM
{

/*
 * @brief A wrapper around encode_get_tid_req that takes in an additional
 * size parameter to accommodate Hostboot PLDM APIs. The size parameter is
 * actually unused, since getTID command doesn't have a message payload.
 *
 * @param[in] i_instance_id the PLDM instance ID
 * @param[out] o_msg the encoded PLDM message
 * @param[in] i_unused_payload_size payload size (unused for getTID)
 * @return The RC from encoder
 */
int encode_get_tid_req_hb(const uint8_t i_instance_id,
                          pldm_msg* const o_msg,
                          const size_t i_unused_payload_size)
{
    return encode_get_tid_req(i_instance_id,
                              o_msg);
}

errlHndl_t getTID()
{
    errlHndl_t l_errl = nullptr;

    do {
    std::vector<uint8_t>l_responseBytes;

    // Get TID doesn't have any payload, so effectively it's 0 size
    l_errl = sendrecv_pldm_request<0>(l_responseBytes,
                                      g_outboundPldmReqMsgQ,
                                      encode_get_tid_req_hb,
                                      DEFAULT_INSTANCE_ID);
    if(l_errl)
    {
        PLDM_ERR("getTID: Could not send the message to get TID to BMC");
        break;
    }

    pldm_get_tid_resp l_resp {};
    l_errl = decode_pldm_response(decode_get_tid_resp,
                                  l_responseBytes,
                                  &l_resp.completion_code,
                                  &l_resp.tid);
    if(l_errl)
    {
        PLDM_ERR("getTID: Could not decode PLDM response");
        break;
    }

    /*@
      * @errortype
      * @severity   ERRL_SEV_UNRECOVERABLE
      * @moduleid   MOD_GET_TID
      * @reasoncode RC_BAD_COMPLETION_CODE
      * @userdata1  Actual Completion Code
      * @userdata2  Expected Completion Code
      * @devdesc    Software problem, bad PLDM response from BMC
      * @custdesc   A software error occurred during system boot
      */
    l_errl = validate_resp(l_resp.completion_code, PLDM_SUCCESS,
                           MOD_GET_TID, RC_BAD_COMPLETION_CODE,
                           l_responseBytes);
    if(l_errl)
    {
        break;
    }

    PLDM_INF("getTID: BMC's TID is %d", l_resp.tid);
    } while(0);
    return l_errl;
}

} // namespace PLDM
