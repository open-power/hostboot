/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/responses/pldm_monitor_control_responders.C $    */
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

/* @file  pldm_monitor_control_responders.C
 *
 * @brief Contains definitions for the PLDM Platform Monitor & Control message
 *        handlers.
 */

#include <pldm/responses/pldm_monitor_control_responders.H>

// PLDM
#include <pldm/pldm_errl.H>
#include <pldm/pldm_const.H>
#include <pldm/pldm_reasoncodes.H>
#include <pldm/pldm_response.H>
#include "../common/pldmtrace.H"

// MCTP
#include <mctp/mctp_message_types.H>
#include <mctp/mctp_const.H>

// libpldm
#include "../extern/platform.h"
#include "../extern/base.h"

// PdrManager
#include <pldm/extended/pdr_manager.H>

using namespace ERRORLOG;

namespace PLDM
{

errlHndl_t handleGetPdrRequest(const msg_q_t i_msgQ,
                               const pldm_msg* const i_msg,
                               const size_t i_msg_len)
{
    PLDM_ENTER("handleGetPdrRequest");

    pldm_get_pdr_req pdr_req { };
    errlHndl_t errl = nullptr;
    std::vector<uint8_t> pdr_data;
    pdr_handle_t next_record_handle = 0;
    uint8_t pldm_response_code = PLDM_SUCCESS;

    do
    {
        {
            const int rc =
                decode_get_pdr_req(i_msg,
                                   i_msg_len,
                                   &pdr_req.record_handle,
                                   &pdr_req.data_transfer_handle,
                                   &pdr_req.transfer_op_flag,
                                   &pdr_req.request_count,
                                   &pdr_req.record_change_number);

            if (rc != PLDM_SUCCESS)
            {
                PLDM_INF("Failed to decode getPDR request, rc = %d",
                         rc);

                /*
                 * @errortype  ERRL_SEV_UNRECOVERABLE
                 * @moduleid   MOD_HANDLE_GET_PDR
                 * @reasoncode RC_MSG_DECODE_FAIL
                 * @userdata1  RC returned from decode function
                 * @devdesc    Software problem, failed to decode PLDM getPDR request
                 * @custdesc   A software error occurred during system boot
                 */
                errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                     MOD_HANDLE_GET_PDR,
                                     RC_MSG_DECODE_FAIL,
                                     rc,
                                     0,
                                     ErrlEntry::NO_SW_CALLOUT);

                addBmcErrorCallouts(errl);
                break;
            }
        }

        if (pdr_req.data_transfer_handle != 0)
        {
            // We don't support multipart transfers
            PLDM_INF("Got invalid data transfer handle 0x%x in getPDR request",
                     pdr_req.data_transfer_handle);
            pldm_response_code = PLDM_PLATFORM_INVALID_DATA_TRANSFER_HANDLE;
            break;
        }

        if (pdr_req.transfer_op_flag != PLDM_GET_FIRSTPART)
        {
            PLDM_INF("Got invalid transfer op flag 0x%x in getPDR request",
                     pdr_req.transfer_op_flag);
            pldm_response_code = PLDM_PLATFORM_INVALID_TRANSFER_OPERATION_FLAG;
            break;
        }

        if (pdr_req.record_change_number != 0)
        {
            PLDM_INF("Got invalid record change number 0x%x in getPDR request",
                     pdr_req.record_change_number);
            pldm_response_code = PLDM_PLATFORM_INVALID_RECORD_CHANGE_NUMBER;
            break;
        }

        pdr_handle_t record_handle = pdr_req.record_handle;

        const bool record_found
            = PLDM::thePdrManager().findPdr(record_handle,
                                            &pdr_data,
                                            next_record_handle);

        if (!record_found)
        {
            PLDM_INF("Got invalid record handle 0x%x in getPDR request",
                     pdr_req.record_handle);
            pldm_response_code = PLDM_PLATFORM_INVALID_RECORD_HANDLE;
            break;
        }
    } while (false);

    if (!errl)
    {
        const size_t max_request_count = pdr_req.request_count;

        // If we found the PDR with the given record handle, we send back at
        // most the number of bytes that the client asked for.
        const uint32_t response_pdr_size
            = (pldm_response_code == PLDM_SUCCESS
               ? std::min(pdr_data.size(), max_request_count)
               : 0);

        errl =
            send_pldm_response<PLDM_GET_PDR_MIN_RESP_BYTES>
            (i_msgQ,
             encode_get_pdr_resp,
             response_pdr_size,
             i_msg->hdr.instance_id,
             pldm_response_code,
             next_record_handle,
             0, // No remaining data
             PLDM_START_AND_END,
             payload_length_placeholder_t(),
             pdr_data.data(),
             0); // CRC, not used for START_AND_END

        if (errl)
        {
            PLDM_INF("Failed to encode and/or send getPDR response "
                     "(response size = %d, response code = 0x%x, "
                     "next record handle = 0x%08x)",
                     response_pdr_size, pldm_response_code,
                     next_record_handle);

            errl->collectTrace(PLDM_COMP_NAME);
        }
    }

    PLDM_EXIT("handleGetPdrRequest");

    return errl;
}

}
