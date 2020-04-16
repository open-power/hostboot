/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/requests/pldm_fileio_requests.C $                */
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
/* @file pldm_fileio_requests.C
 * This file contains the implementations of the APIs/wrappers for PLDM File IO
 * operations.
 */

#include <vector>
#include <sys/msg.h>

#include <pldm/requests/pldm_fileio_requests.H>
#include "../extern/file_io.h"
#include "../extern/base.h"
#include <pldm/pldm_request.H>
#include "../common/pldmtrace.H"
#include <pldm/pldmif.H>
#include <hbotcompid.H>
#include <hwas/common/hwasCallout.H>
#include <pldm/pldm_errl.H>

// This is the name of the outgoing PLDM message queue.
extern const char* VFS_ROOT_MSG_PLDM_REQ_OUT;

namespace PLDM
{

errlHndl_t getFileTable(std::vector<uint8_t>& o_table)
{
    PLDM_ENTER("getFileTable");
    errlHndl_t l_errl = nullptr;

    // Clear the output
    o_table.clear();

    struct pldm_get_file_table_req l_fileTableReq
    {
        .transfer_handle = 0, // 0 for PLDM_GET_FIRSTPART (ignored)
        .operation_flag = PLDM_GET_FIRSTPART,
        .table_type = PLDM_FILE_ATTRIBUTE_TABLE,
    };

    std::vector<uint8_t>l_responseBytes;
    const msg_q_t l_msgQ = msg_q_resolve(VFS_ROOT_MSG_PLDM_REQ_OUT);
    assert(l_msgQ, "getFileTable: message queue not found!");

    do {
    l_errl = sendrecv_pldm_request<PLDM_GET_FILE_TABLE_REQ_BYTES>(
                l_responseBytes,
                l_msgQ,
                encode_get_file_table_req,
                DEFAULT_INSTANCE_ID,
                l_fileTableReq.transfer_handle,
                l_fileTableReq.operation_flag,
                l_fileTableReq.table_type);
    if(l_errl)
    {
        PLDM_ERR("getFileTable: Could not send the PLDM request");
        break;
    }

    struct pldm_get_file_table_resp l_fileTableResp
    {
        .completion_code = PLDM_ERROR,
        .next_transfer_handle = 0,
        .transfer_flag = 0,
    };

    uint8_t* l_outputBuffer = nullptr;
    size_t l_fileTableSize = 0;

    // Decode twice: the first time decode_get_file_table_resp will return the
    // size of the requested table; then we resize the output buffer to fit
    // the table and decode again, in which case decode_get_file_table will
    // populate the output buffer.
    for(int i = 0; i < 2; ++i)
    {
        l_errl = decode_pldm_response(decode_get_file_table_resp,
                                      l_responseBytes,
                                      &l_fileTableResp.completion_code,
                                      &l_fileTableResp.next_transfer_handle,
                                      &l_fileTableResp.transfer_flag,
                                      &l_fileTableSize,
                                      l_outputBuffer);
        if(l_errl)
        {
            PLDM_ERR("getFileTable: Could not decode PLDM response (pass %d)",
                     i);
            break;
        }

        if(l_fileTableResp.completion_code != PLDM_SUCCESS)
        {
            PLDM_ERR("getFileTable: PLDM op retuned code %d",
                     l_fileTableResp.completion_code);
            pldm_msg* const l_pldmResponse =
                reinterpret_cast<pldm_msg*>(l_responseBytes.data());
            const uint64_t l_responseHeader = pldmHdrToUint64(*l_pldmResponse);

            /*
             * @errortype
             * @severity   ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid   MOD_GET_FILE_TABLE
             * @reasoncode RC_BAD_COMPLETION_CODE
             * @userdata1  Completion code
             * @userdata2  Response header data
             * @devdesc    File Table request completed unsuccessfully
             *             (bad completion code)
             * @custdesc   A host failure occurred
             */
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                             MOD_GET_FILE_TABLE,
                                             RC_BAD_COMPLETION_CODE,
                                             l_fileTableResp.completion_code,
                                             l_responseHeader);
            addBmcErrorCallouts(l_errl);
            break;
        }

        if(l_fileTableResp.transfer_flag != PLDM_START_AND_END)
        {
            PLDM_ERR("getFileTable: bad transfer flag %d",
                     l_fileTableResp.transfer_flag);
            pldm_msg* const l_pldmResponse =
                reinterpret_cast<pldm_msg*>(l_responseBytes.data());
            const uint64_t l_responseHeader = pldmHdrToUint64(*l_pldmResponse);

            /*
             * @errortype
             * @severity   ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid   MOD_GET_FILE_TABLE
             * @reasoncode RC_BAD_TRANSFER_FLAG
             * @userdata1  Returned transfer flag
             * @userdata2  Response header data
             * @devdesc    File Table request completed unsuccessfully
             *             (bad response flag)
             * @custdesc   A host failure occurred
             */
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                             MOD_GET_FILE_TABLE,
                                             RC_BAD_TRANSFER_FLAG,
                                             l_fileTableResp.transfer_flag,
                                             l_responseHeader);
            addBmcErrorCallouts(l_errl);
            break;

        }

        if(l_fileTableSize && (l_outputBuffer == nullptr))
        {
            PLDM_INF("getFileTable: file table size: %llu", l_fileTableSize);
            o_table.resize(l_fileTableSize);
            l_outputBuffer = o_table.data();
        }
        else if(l_fileTableSize == 0)
        {
            // BMC returned file table size of 0; no need to decode again
            break;
        }
    } // end for loop

    if(l_errl)
    {
        break;
    }

    }while(0);

    PLDM_EXIT("getFileTable");
    return l_errl;
}

} // namespace PLDM
