/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/requests/pldm_fileio_requests.C $                */
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

/** @file  pldm_fileio_requests.C
 *  @brief This file contains the implementations of the APIs/wrappers for PLDM File IO
 *         request operations.
 */

#include <vector>
#include <sys/msg.h>

#include <pldm/requests/pldm_fileio_requests.H>
#include <openbmc/pldm/oem/ibm/libpldm/file_io.h>
#include <openbmc/pldm/libpldm/base.h>
#include <pldm/pldm_request.H>
#include "../common/pldmtrace.H"
#include <pldm/pldmif.H>
#include <hbotcompid.H>
#include <hwas/common/hwasCallout.H>
#include <pldm/pldm_errl.H>
#include <limits.h>

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

#ifndef __HOSTBOOT_RUNTIME
    const msg_q_t l_msgQ = msg_q_resolve(VFS_ROOT_MSG_PLDM_REQ_OUT);
    assert(l_msgQ, "getFileTable: message queue not found!");
#else
    const msg_q_t l_msgQ = nullptr;
#endif

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
                                      l_outputBuffer,
                                      &l_fileTableSize);
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

            /*@
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

            /*@
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

errlHndl_t getLidFile(const uint32_t i_fileHandle,
                      uint32_t& io_numBytesToRead,
                      uint8_t* o_file)
{
    PLDM_ENTER("getLidFile");
    errlHndl_t l_errl = getLidFileFromOffset(i_fileHandle,
                                             0, // Start at offset 0
                                             io_numBytesToRead,
                                             o_file);

    PLDM_EXIT("getLidFile");
    return l_errl;
}

errlHndl_t getLidFileFromOffset(const uint32_t i_fileHandle,
                                const uint32_t i_offset,
                                uint32_t& io_numBytesToRead,
                                uint8_t* o_file)
{
    PLDM_ENTER("getLidFileFromOffset: File handle 0x%08x, Input size 0x%08x, Offset 0x%08x",
               i_fileHandle, io_numBytesToRead, i_offset);
    errlHndl_t l_errl = nullptr;
    // Currently the maximum transfer size for PLDM is defined as 180K; however,
    // we shoudn't be allocating that much memory on the heap in HB. It was
    // found experimentally that the optimal transfer size that doesn't make
    // HB crash is (127k + 1) bytes. That specific number will ask kernel for
    // 128k of memory, which will have enough space to accomodate PLDM headers
    // that are not part of the actual payload without fragmenting the memory
    // too much.
    const uint32_t MAX_TRANSFER_SIZE = 127 * KILOBYTE + 1;
    size_t l_numTransfers = 1;
    uint32_t l_totalRead = 0;
    uint8_t* l_currPtr = o_file;

    struct pldm_read_write_file_by_type_req l_req
    {
        // Currently BMC is hardcoded to use the TEMP side
        .file_type = PLDM_FILE_TYPE_LID_TEMP,
        .file_handle = i_fileHandle,
        .offset = i_offset,
        .length = 0, // calculated later
    };

    if(io_numBytesToRead > MAX_TRANSFER_SIZE)
    {
        // Round up
        l_numTransfers = (io_numBytesToRead + MAX_TRANSFER_SIZE - 1) /
                         MAX_TRANSFER_SIZE;
        l_req.length = MAX_TRANSFER_SIZE;
    }
    else if (io_numBytesToRead == 0)
    {
        // The caller doesn't know the size of the file, so we need to
        // read it until BMC indicates that the file ended (returned read
        // size is less than requested read size). Set the number of transfers
        // to a really large number.
        l_req.length = MAX_TRANSFER_SIZE;
        l_numTransfers = 0xFFFFFFFF;
    }
    else
    {
        l_req.length = io_numBytesToRead;
    }

    PLDM_INF("getLidFileFromOffset: %d transfers to get 0x%08x of data",
             l_numTransfers, io_numBytesToRead);

    std::vector<uint8_t>l_responseBytes;
#ifndef __HOSTBOOT_RUNTIME
    const msg_q_t l_msgQ = msg_q_resolve(VFS_ROOT_MSG_PLDM_REQ_OUT);
    assert(l_msgQ, "getLidFileFromOffset: message queue not found!");
#else
    const msg_q_t l_msgQ = nullptr;
#endif

    do {
    for(size_t i = 0; i < l_numTransfers; ++i)
    {
        l_req.offset = i_offset + (i * MAX_TRANSFER_SIZE);
        l_errl = sendrecv_pldm_request<PLDM_RW_FILE_BY_TYPE_REQ_BYTES>(
                    l_responseBytes,
                    l_msgQ,
                    encode_rw_file_by_type_req,
                    DEFAULT_INSTANCE_ID,
                    PLDM_READ_FILE_BY_TYPE,
                    l_req.file_type,
                    l_req.file_handle,
                    l_req.offset,
                    l_req.length);
        if(l_errl)
        {
            PLDM_ERR("getLidFileFromOffset: Could not send the PLDM request");
            break;
        }

        struct pldm_read_write_file_by_type_resp l_resp {};

        l_errl = decode_pldm_response(decode_rw_file_by_type_resp,
                                      l_responseBytes,
                                      &l_resp.completion_code,
                                      &l_resp.length,
                                      l_currPtr);
        if(l_errl)
        {
            PLDM_ERR("getLidFileFromOffset: Could not decode PLDM response");
            break;
        }

        // PLDM_DATA_OUT_OF_RANGE is another signal for the end-of-file.
        // If the file is an exact multiple of MAX_TRANSFER_SIZE, and
        // if we read the last part of the file during the last read, we
        // will have advanced the file offset pointer past the end of the
        // file. If we make another request with the offset past the end
        // of the file, the BMC will respond with PLDM_DATA_OUT_OF_RANGE rc.
        // We need to stop reading the file and return (without error).
        if(l_resp.completion_code == PLDM_DATA_OUT_OF_RANGE)
        {
            PLDM_INF("getLidFileFromOffset: PLDM_DATA_OUT_OF_RANGE EOF condition encountered");
            if(l_errl)
            {
                delete l_errl;
                l_errl = nullptr;
            }
            l_resp.completion_code = PLDM_SUCCESS;
        }


        if(l_resp.completion_code != PLDM_SUCCESS)
        {
            PLDM_ERR("getLidFileFromOffset: PLDM op returned code %d",
                     l_resp.completion_code);
            pldm_msg* const l_pldmResponse =
                reinterpret_cast<pldm_msg*>(l_responseBytes.data());
            const uint64_t l_responseHeader =
                pldmHdrToUint64(*l_pldmResponse);

            /*@
             * @errortype
             * @severity   ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid   MOD_GET_LID_FILE
             * @reasoncode RC_BAD_COMPLETION_CODE
             * @userdata1  Completion code
             * @userdata2  Response header data
             * @devdesc    File request completed unsuccessfully
             * @custdesc   A host failure occurred
             */
            l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            MOD_GET_LID_FILE,
                            RC_BAD_COMPLETION_CODE,
                            l_resp.completion_code,
                            l_responseHeader);
            addBmcErrorCallouts(l_errl);
            break;
        }

        if(l_resp.length == 0)
        {
            PLDM_INF("getLidFileFromOffset: BMC returned size 0 for file handle 0x%08x at offset 0x%08x",
                     i_fileHandle, l_req.offset);
            break;
        }
        else
        {
            PLDM_DBG("getLidFileFromOffset: Response %llu; the actual size of read is 0x%08x",
                     i, l_resp.length);
        }

        l_totalRead += l_resp.length;
        l_currPtr += l_resp.length;
        if(io_numBytesToRead == l_totalRead)
        {
            break;
        }
        else if(l_resp.length != l_req.length)
        {
            PLDM_INF("getLidFileFromOffset: BMC returned length 0x%08x of file read; requested length was 0x%08x. That indicates End Of File (total length: 0x%08x).",
                     l_resp.length, l_req.length, l_totalRead);
            break;
        }
        else if((MAX_TRANSFER_SIZE > (io_numBytesToRead - l_totalRead)) &&
                (io_numBytesToRead != 0))
        {
            // We need to request a smaller chunk than MAX_TRANSFER_SIZE
            l_req.length = io_numBytesToRead - l_totalRead;
        }

        if(l_errl)
        {
            break;
        }

    } // number of transfers

    io_numBytesToRead = l_totalRead;

    if(l_errl)
    {
        break;
    }

    }while(0);

    PLDM_EXIT("getLidFileFromOffset");
    return l_errl;
}

} // namespace PLDM
