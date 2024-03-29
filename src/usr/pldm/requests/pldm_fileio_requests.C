/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/requests/pldm_fileio_requests.C $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2023                        */
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
// VFS_ROOT_MSG_PLDM_REQ_OUT
#include <sys/vfs.h>

#include <pldm/requests/pldm_fileio_requests.H>
#include <file_io.h>
#include <openbmc/pldm/libpldm/include/libpldm/base.h>
#include <pldm/pldm_request.H>
#include <pldm/pldm_trace.H>
#include "../common/pldm_utils.H"
#include <pldm/pldmif.H>
#include <hbotcompid.H>
#include <hwas/common/hwasCallout.H>
#include <pldm/pldm_errl.H>
#include <limits.h>
#include <util/misc.H>
#include <targeting/common/targetservice.H>
#include "pldm_request_utils.H"

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

    do {
    l_errl = sendrecv_pldm_request<PLDM_GET_FILE_TABLE_REQ_BYTES>(
                l_responseBytes,
                g_outboundPldmReqMsgQ,
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
    uint8_t  l_dataOffset = 0;
    size_t l_fileTableSize = 0;

    l_errl = decode_pldm_response(decode_get_file_table_resp,
                                  l_responseBytes,
                                  &l_fileTableResp.completion_code,
                                  &l_fileTableResp.next_transfer_handle,
                                  &l_fileTableResp.transfer_flag,
                                  &l_dataOffset,
                                  &l_fileTableSize);
    if(l_errl)
    {
        PLDM_ERR("getFileTable: Could not decode PLDM response");
        break;
    }

    /*@
      * @errortype
      * @severity   ERRL_SEV_UNRECOVERABLE
      * @moduleid   MOD_GET_FILE_TABLE
      * @reasoncode RC_BAD_COMPLETION_CODE
      * @userdata1  Actual Completion Code
      * @userdata2  Expected Completion Code
      * @devdesc    Software problem, bad PLDM response from BMC
      * @custdesc   A software error occurred during system boot
      */
    l_errl = validate_resp(l_fileTableResp.completion_code, PLDM_SUCCESS,
                           MOD_GET_FILE_TABLE, RC_BAD_COMPLETION_CODE,
                           l_responseBytes);
    if(l_errl)
    {
        break;
    }

    /*@
      * @errortype
      * @severity   ERRL_SEV_UNRECOVERABLE
      * @moduleid   MOD_GET_FILE_TABLE
      * @reasoncode RC_BAD_NEXT_TRANSFER_HANDLE
      * @userdata1  Actual Next Transfer Handle
      * @userdata2  Expected Next Transfer Handle
      * @devdesc    Software problem, bad PLDM response from BMC
      * @custdesc   A software error occurred during system boot
      */
    l_errl = validate_resp(l_fileTableResp.next_transfer_handle, static_cast<pdr_handle_t>(0),
                           MOD_GET_FILE_TABLE, RC_BAD_NEXT_TRANSFER_HANDLE,
                           l_responseBytes);
    if(l_errl)
    {
        break;
    }

    /*@
      * @errortype
      * @severity   ERRL_SEV_UNRECOVERABLE
      * @moduleid   MOD_GET_FILE_TABLE
      * @reasoncode RC_BAD_TRANSFER_FLAG
      * @userdata1  Actual Transfer Flag
      * @userdata2  Expected Transfer Flag
      * @devdesc    Software problem, bad PLDM response from BMC
      * @custdesc   A software error occurred during system boot
      */
    l_errl = validate_resp(l_fileTableResp.transfer_flag, PLDM_START_AND_END,
                           MOD_GET_FILE_TABLE, RC_BAD_TRANSFER_FLAG,
                           l_responseBytes);
    if(l_errl)
    {
        break;
    }

    if(l_fileTableSize && (l_outputBuffer == nullptr))
    {
        PLDM_INF("getFileTable: file table size: %llu", l_fileTableSize);
        o_table.resize(l_fileTableSize);
        memcpy(o_table.data(), l_responseBytes.data() + l_dataOffset + sizeof(pldm_msg_hdr), l_fileTableSize);
    }
    else if(l_fileTableSize == 0)
    {
        // BMC returned file table size of 0; no need to decode again
        break;
    }

    }while(0);

    // If issues with RC_INVALID_SECTION in populateTOC investigate mappings between PNOR sections
    PLDM_INF_BIN("getFileTable (fileTable.json on the BMC) o_table.data()=", o_table.data(), o_table.size());
    PLDM_EXIT("getFileTable");
    return l_errl;
}

errlHndl_t getLidFile(const uint32_t i_fileHandle,
                      uint32_t& io_numBytesToRead,
                      uint8_t* o_file)
{
    errlHndl_t l_errl = getLidFileFromOffset(i_fileHandle,
                                             0, // Start at offset 0
                                             io_numBytesToRead,
                                             o_file);

    return l_errl;
}

errlHndl_t getLidFileFromOffset(const uint32_t i_fileHandle,
                                const uint32_t i_offset,
                                uint32_t& io_numBytesToRead,
                                uint8_t* o_file,
                                bool* const o_eof,
                                pldm_fileio_file_type i_pound_keyword_type)
{
    PLDM_DBG("getLidFileFromOffset: File handle 0x%08x, Input size 0x%08x, Offset 0x%08x i_pound_keyword_type=0x%X",
               i_fileHandle, io_numBytesToRead, i_offset, i_pound_keyword_type);
    errlHndl_t l_errl = nullptr;

    size_t l_numTransfers = 1;
    uint32_t l_totalRead = 0;
    uint8_t* l_currPtr = o_file;
    do {

    struct pldm_read_write_file_by_type_req l_req
    {
        .file_type = PLDM_FILE_TYPE_LID_RUNNING,
        .file_handle = i_fileHandle,
        .offset = i_offset,
        .length = 0, // calculated later
    };

    // i_pound_keyword_type will provide special case values provided for one-off pound keyword
    // support provided by PLDM, i.e. today the ONLY case supported is PLDM_FILE_TYPE_PSPD_VPD_PDD_KEYWORD
    // In the future additional one-off pound keyword values will be added if required
    if (i_pound_keyword_type != PLDM_FILE_TYPE_INVALID)
    {
        l_req.file_type = i_pound_keyword_type;
        // This field allows special request types to be sent to PLDM, i.e. PLDM_FILE_TYPE_PSPD_VPD_PDD_KEYWORD
        PLDM_INF("getLidFileFromOffset SPECIAL OVERRIDE l_req.file_type=0x%X l_req.file_handle=0x%X",
                 l_req.file_type, l_req.file_handle);
    }

    if(io_numBytesToRead > MAX_TRANSFER_SIZE_BYTES)
    {
        // Round up
        l_numTransfers = (io_numBytesToRead + MAX_TRANSFER_SIZE_BYTES - 1) /
                         MAX_TRANSFER_SIZE_BYTES;
        l_req.length = MAX_TRANSFER_SIZE_BYTES;
    }
    else if (io_numBytesToRead == 0)
    {
        // The caller doesn't know the size of the file, so we need to
        // read it until BMC indicates that the file ended (returned read
        // size is less than requested read size). Set the number of transfers
        // to a really large number.
        l_req.length = MAX_TRANSFER_SIZE_BYTES;
        l_numTransfers = 0xFFFFFFFF;
    }
    else
    {
        l_req.length = io_numBytesToRead;
    }

    PLDM_DBG("getLidFileFromOffset: %d transfers to get 0x%08x of data",
             l_numTransfers, io_numBytesToRead);


    std::vector<uint8_t> l_responseBytes;

    for(size_t i = 0; i < l_numTransfers; ++i)
    {
        l_req.offset = i_offset + (i * MAX_TRANSFER_SIZE_BYTES);
        l_errl = sendrecv_pldm_request<PLDM_RW_FILE_BY_TYPE_REQ_BYTES>(
                    l_responseBytes,
                    g_outboundPldmReqMsgQ,
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

        if (l_resp.completion_code == PLDM_DATA_OUT_OF_RANGE)
        {
            o_eof && (*o_eof = true);
        }

        // PLDM_DATA_OUT_OF_RANGE is another signal for the end-of-file.
        // If the file is an exact multiple of MAX_TRANSFER_SIZE_BYTES, and
        // if we read the last part of the file during the last read, we
        // will have advanced the file offset pointer past the end of the
        // file. If we make another request with the offset past the end
        // of the file, the BMC will respond with PLDM_DATA_OUT_OF_RANGE rc.
        // We need to stop reading the file and return (without error).
        if(io_numBytesToRead == 0 && l_resp.completion_code == PLDM_DATA_OUT_OF_RANGE)
        {
            PLDM_INF("getLidFileFromOffset: PLDM_DATA_OUT_OF_RANGE EOF condition encountered for file 0x%08X",
                     i_fileHandle);
            if(l_errl)
            {
                delete l_errl;
                l_errl = nullptr;
            }

            l_resp.completion_code = PLDM_SUCCESS;
        }

        /*@
          * @errortype
          * @severity   ERRL_SEV_UNRECOVERABLE
          * @moduleid   MOD_GET_LID_FILE
          * @reasoncode RC_BAD_COMPLETION_CODE
          * @userdata1  Actual Completion Code
          * @userdata2  Expected Completion Code
          * @devdesc    Software problem, bad PLDM response from BMC
          * @custdesc   A software error occurred during system boot
          */
        l_errl = validate_resp(l_resp.completion_code, PLDM_SUCCESS,
                               MOD_GET_LID_FILE, RC_BAD_COMPLETION_CODE,
                               l_responseBytes);
        if(l_errl)
        {
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
            // This may be perfectly okay but just in case it isn't trace it out
            if( io_numBytesToRead != 0 ) //0=infinite, i.e. user doesn't know size
            {
                 // user thought they knew the size
                PLDM_DBG("getLidFileFromOffset: BMC returned length 0x%08x for read of file 0x%08x; requested length was 0x%08x. That indicates End Of File (total length: 0x%08x, buffer length: 0x%08x).",
                         l_resp.length, i_fileHandle, l_req.length, l_totalRead, io_numBytesToRead);
            }
            break;
        }
        else if((MAX_TRANSFER_SIZE_BYTES > (io_numBytesToRead - l_totalRead)) &&
                (io_numBytesToRead != 0))
        {
            // We need to request a smaller chunk than MAX_TRANSFER_SIZE_BYTES
            l_req.length = io_numBytesToRead - l_totalRead;
        }
    } // number of transfers

    io_numBytesToRead = l_totalRead;

    if(l_errl)
    {
        break;
    }

    }while(0);

    PLDM_DBG("getLidFileFromOffset");
    return l_errl;
}


/**
 * @brief Calls PLDM writeFileByType interface and checks for error conditions
 *        Possible error conditions:
 *        - could not send the request to PLDM
 *        - decoding the response failed
 *        - completion_code was not PLDM_SUCCESS
 *        - requesting length did not meet actual length written in bytes
 * @param[in/out] io_request Request to send down to BMC
 *                      Length field could be set to MAX_TRANSFER_SIZE_BYTES or a
 *                      remainder amount of length if requested length had to be
 *                      broken up into multiple writes.
 * @param[in/out] io_writeSizeBytes How many buffer bytes to write (set to what was actually written)
 * @param[in]     i_writeBuffer Buffer of bytes to write
 * @return error handle for error condition found, else nullptr
 */
errlHndl_t writeFileByType(pldm_read_write_file_by_type_req & io_request,
                           uint32_t& io_writeSizeBytes,
                           const uint8_t* const i_writeBuffer)
{
    PLDM_DBG("writeFileByType: File type 0x%08x, File handle 0x%08x, Input size 0x%08x, Offset 0x%08x",
              io_request.file_type, io_request.file_handle, io_writeSizeBytes, io_request.offset);
    errlHndl_t errl = nullptr;
    size_t num_transfers = 1;
    uint32_t bytes_written = 0;
    uint32_t l_offset = io_request.offset;
    auto current_ptr = const_cast<uint8_t* const >(i_writeBuffer);

    if(io_writeSizeBytes > MAX_TRANSFER_SIZE_BYTES)
    {
        // Round up
        num_transfers = (io_writeSizeBytes + MAX_TRANSFER_SIZE_BYTES - 1) /
                         MAX_TRANSFER_SIZE_BYTES;
        io_request.length = MAX_TRANSFER_SIZE_BYTES;
    }
    else
    {
        io_request.length = io_writeSizeBytes;
    }

    PLDM_DBG("writeFileByType: %d transfers to send 0x%08x of data",
             num_transfers, io_writeSizeBytes);

    std::vector<uint8_t> response_bytes;
#ifndef __HOSTBOOT_RUNTIME
    const msg_q_t msgQ = msg_q_resolve(VFS_ROOT_MSG_PLDM_REQ_OUT);
    assert(msgQ, "writeFileByType: message queue not found!");
#else
    const msg_q_t msgQ = nullptr;
#endif

    do {

    for(size_t i = 0; i < num_transfers; ++i)
    {
        io_request.offset = l_offset + (i * MAX_TRANSFER_SIZE_BYTES);
        errl = sendrecv_pldm_request<PLDM_RW_FILE_BY_TYPE_REQ_BYTES>(
                    response_bytes,
                    io_request.length,
                    msgQ,
                    encode_write_file_by_type_req,
                    DEFAULT_INSTANCE_ID,
                    PLDM_WRITE_FILE_BY_TYPE ,
                    io_request.file_type,
                    io_request.file_handle,
                    io_request.offset,
                    io_request.length,
                    current_ptr);
        if(errl)
        {
            PLDM_ERR("writeFileByType: Could not send the PLDM request for fileio write");
            break;
        }

        struct pldm_read_write_file_by_type_resp response {};

        errl = decode_pldm_response(decode_rw_file_by_type_resp,
                                    response_bytes,
                                    &response.completion_code,
                                    &response.length,
                                    nullptr);
        if(errl)
        {
            PLDM_ERR("writeFileByType: Could not decode PLDM response");
            break;
        }

        /*@
          * @errortype
          * @severity   ERRL_SEV_UNRECOVERABLE
          * @moduleid   MOD_WRITE_FILE_BY_TYPE
          * @reasoncode RC_BAD_COMPLETION_CODE
          * @userdata1  Actual Completion Code
          * @userdata2  Expected Completion Code
          * @devdesc    Software problem, bad PLDM response from BMC
          * @custdesc   A software error occurred during system boot
          */
        errl = validate_resp(response.completion_code, PLDM_SUCCESS,
                             MOD_WRITE_FILE_BY_TYPE, RC_BAD_COMPLETION_CODE,
                             response_bytes);
        if(errl)
        {
            break;
        }

        bytes_written += response.length;
        current_ptr += response.length;

        /*@
          * @errortype
          * @severity   ERRL_SEV_UNRECOVERABLE
          * @moduleid   MOD_WRITE_FILE_BY_TYPE
          * @reasoncode RC_INVALID_LENGTH
          * @userdata1  Actual Length
          * @userdata2  Expected Length
          * @devdesc    Software problem, bad PLDM response from BMC
          * @custdesc   A software error occurred during system boot
          */
        errl = validate_resp(response.length, io_request.length,
                             MOD_WRITE_FILE_BY_TYPE, RC_INVALID_LENGTH,
                             response_bytes);
        if(errl)
        {
            PLDM_ERR("writeFileByType: BMC returned length 0x%08x of file written; requested length was 0x%08x."
                     " This indicates End Of File overrun (total bytes written: 0x%08x).",
                     response.length, io_request.length, bytes_written);
            break;
        }


        if((MAX_TRANSFER_SIZE_BYTES > (io_writeSizeBytes - bytes_written)) &&
                (io_writeSizeBytes != 0))
        {
            // We need to request a smaller chunk than MAX_TRANSFER_SIZE_BYTES
            io_request.length = io_writeSizeBytes - bytes_written;
        }
    }
    io_writeSizeBytes = bytes_written;

    }while(0);

    return errl;
}

errlHndl_t writeLidFileFromOffset(const uint32_t i_fileHandle,
                                 const uint32_t i_offset,
                                 uint32_t& io_writeSizeBytes,
                                 const uint8_t* const i_writeBuffer)
{
    PLDM_DBG("writeLidFileFromOffset: File handle 0x%08x, Input size 0x%08x, Offset 0x%08x",
               i_fileHandle, io_writeSizeBytes, i_offset);

    errlHndl_t errl = nullptr;
    do {

    struct pldm_read_write_file_by_type_req request
    {
        .file_type = PLDM_FILE_TYPE_LID_RUNNING,
        .file_handle = i_fileHandle,
        .offset = i_offset,
        .length = 0, // calculated later
    };
    uint32_t requestedBytes = io_writeSizeBytes;
    errl = writeFileByType(request, io_writeSizeBytes, i_writeBuffer);
    if (errl)
    {
        PLDM_ERR("writeLidFileFromOffset: writeFileByType failed - RC: 0x%X, requestedSize: 0x%08X, writtenSize: 0x%08X",
          ERRL_GETRC_SAFE(errl), requestedBytes, io_writeSizeBytes);
        break;
    }

    }while (0);

    return errl;
}

errlHndl_t sendErrLog(const uint32_t i_eid,
                      const uint8_t * const i_pelData,
                      uint32_t & io_dataSize)
{
    PLDM_DBG("sendErrLog: EID 0x%08x, Input size 0x%08x", i_eid, io_dataSize);

    // can only send a single writeFileByType request for PEL transfer
    assert((io_dataSize <= MAX_TRANSFER_SIZE_BYTES),
        "sendErrLog: EID 0x%08x size 0x%08x is more than single transaction size 0x%08x",
        i_eid, io_dataSize, MAX_TRANSFER_SIZE_BYTES);

    struct pldm_read_write_file_by_type_req request
    {
        .file_type = PLDM_FILE_TYPE_PEL,
        .file_handle = i_eid,
        .offset = 0,
        .length = io_dataSize,
    };
    uint32_t requestedBytes = io_dataSize;

    errlHndl_t errl = writeFileByType(request, io_dataSize, i_pelData);
    if (errl)
    {
        PLDM_ERR("sendErrLog: EID 0x%08X writeFileByType failed - RC: 0x%X, requestedSize: 0x%08X, writtenSize: 0x%08X",
          i_eid, ERRL_GETRC_SAFE(errl), requestedBytes, io_dataSize);
    }
    return errl;
}


errlHndl_t sendProgressSrc(const uint8_t * const i_progressSrc, uint32_t & io_dataSize)
{
    PLDM_DBG_BIN("Enter sendProgressSrc", i_progressSrc, io_dataSize);

    // should never be sending more than one transaction for progress code transfer
    assert((io_dataSize <= MAX_TRANSFER_SIZE_BYTES),
        "sendProgressSrc: Trying to send a progress SRC size 0x%08x that is more than a single transaction size 0x%08x",
        io_dataSize, MAX_TRANSFER_SIZE_BYTES);

    struct pldm_read_write_file_by_type_req request
    {
        .file_type = PLDM_FILE_TYPE_PROGRESS_SRC, // 0x0A
        .file_handle = 0xFFFFFFFF,
        .offset = 0,
        .length = io_dataSize,
    };
    uint32_t requestedBytes = io_dataSize;
    errlHndl_t errl = writeFileByType(request, io_dataSize, i_progressSrc);
    if (errl)
    {
        PLDM_ERR("sendProgressSrc: writeFileByType failed - RC: 0x%X, requestedSize: 0x%08X, writtenSize: 0x%08X",
          ERRL_GETRC_SAFE(errl), requestedBytes, io_dataSize);
        PLDM_INF_BIN("sendProgressSrc SRC", i_progressSrc, requestedBytes);
    }
    return errl;
}


} // namespace PLDM
