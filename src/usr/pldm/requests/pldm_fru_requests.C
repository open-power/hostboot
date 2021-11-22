/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/requests/pldm_fru_requests.C $                   */
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

/** @file  pldm_fru_requests.C
 *  @brief This file contains the implementations of the APIs/wrappers for PLDM FRU
 *         request operations.
 */

// System Headers
#include <assert.h>
#include <string.h>
#include <util/align.H>
#include <cstdlib>
#include <map>
#include <vector>
#include <endian.h>
// IPC
#include <sys/msg.h>
//VFS_ROOT_MSG_PLDM_REQ_OUT
#include <sys/vfs.h>
// Hostboot PLDM includes
#include <pldm/pldm_const.H>
#include <pldm/pldm_reasoncodes.H>
#include <pldm/requests/pldm_fru_requests.H>
#include <pldm/pldm_request.H>
#include <pldm/extended/pldm_fru.H>
// Common PLDM
#include <pldm/pldm_trace.H>
// libpldm
#include <fru.h>

// Other userspace module includes
#include <mctp/mctp_message_types.H>

using namespace ERRORLOG;

namespace PLDM
{

errlHndl_t getFruRecordTableMetaData(pldm_fru_record_table_metadata_t& o_table_metadata)
{
    errlHndl_t errl = nullptr;
    do {

    PLDM_ENTER("Enter getFruRecordTableMetaData");

#ifndef __HOSTBOOT_RUNTIME
    msg_q_t msgQ = msg_q_resolve(VFS_ROOT_MSG_PLDM_REQ_OUT);
    assert(msgQ != nullptr,
            "Bug! PLDM Req Out Message queue did not resolve properly!");
#else
    msg_q_t msgQ = nullptr;
#endif

    std::vector<uint8_t> response_bytes;

    errl = sendrecv_pldm_request<PLDM_GET_FRU_RECORD_TABLE_METADATA_REQ_BYTES>(
                      response_bytes,
                      msgQ,
                      encode_get_fru_record_table_metadata_req,
                      DEFAULT_INSTANCE_ID);

    if(errl)
    {
        PLDM_ERR("error attempting get_fru_record_table_metadata request");
        break;
    }

    // pack the PLDM header of the response into a uint64_t which can
    // be used for error logging / debugging
    uint64_t response_hdr_data =
      pldmHdrToUint64(*reinterpret_cast<pldm_msg*>(response_bytes.data()));

    uint8_t completion_code = PLDM_SUCCESS;

    errl =
        decode_pldm_response(decode_get_fru_record_table_metadata_resp,
                              response_bytes,
                              &completion_code,
                              &o_table_metadata.fruDataVerMajor,
                              &o_table_metadata.fruDataVerMinor,
                              &o_table_metadata.fruTableMaxSize,
                              &o_table_metadata.fruTableSize,
                              &o_table_metadata.rsiCount,
                              &o_table_metadata.recordCount,
                              &o_table_metadata.checksum);

    if (errl)
    {
        PLDM_ERR("decode_get_fru_record_table_metadata_resp decode failed see error log");
        break;
    }

    // Bad completion code means BMC had problems processing our request
    if(completion_code != PLDM_SUCCESS)
    {
        PLDM_ERR("decode_get_fru_record_table_metadata_resp failed with rc 0x%.02x",
                 completion_code);

        /*@
        * @errortype  ERRL_SEV_UNRECOVERABLE
        * @moduleid   MOD_GET_FRU_METADATA
        * @reasoncode RC_BAD_COMPLETION_CODE
        * @userdata1  RC returned from decode function
        * @userdata2  Response header data (see pldm_msg_hdr struct)
        * @devdesc    Software problem, BMC returned bad PLDM response code
        * @custdesc   A software error occurred during system boot
        */
        errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                               PLDM::MOD_GET_FRU_METADATA,
                               PLDM::RC_BAD_COMPLETION_CODE,
                               completion_code,
                               response_hdr_data,
                               ErrlEntry::NO_SW_CALLOUT);
        addBmcErrorCallouts(errl);
        break;
    }

    if(o_table_metadata.fruDataVerMajor != SUPPORTED_FRU_VERSION_MAJOR ||
       o_table_metadata.fruDataVerMinor != SUPPORTED_FRU_VERSION_MINOR)
    {
        PLDM_ERR("decode_get_fru_record_table_metadata_resp invalid version %d.%d when expecting 1.0",
                  o_table_metadata.fruDataVerMajor,
                  o_table_metadata.fruDataVerMinor);
        /*@
        * @errortype  ERRL_SEV_UNRECOVERABLE
        * @moduleid   MOD_GET_FRU_METADATA
        * @reasoncode RC_UNSUPPORTED_VERSION
        * @userdata1[0:15]  Actual Major version
        * @userdata1[16:31] Actual Minor version
        * @userdata1[32:47] Supported Major version
        * @userdata1[48:63] Supported Minor version
        * @userdata2  Response header data (see pldm_msg_hdr struct)
        * @devdesc    Software problem, BMC using PLDM Fru Record
        *             table format not supported by Hostboot
        * @custdesc   A software error occurred during system boot
        */
        errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                               PLDM::MOD_GET_FRU_METADATA,
                               PLDM::RC_UNSUPPORTED_VERSION,
                               TWO_UINT32_TO_UINT64(
                                  TWO_UINT16_TO_UINT32(
                                      TO_UINT16(o_table_metadata.fruDataVerMajor),
                                      TO_UINT16(o_table_metadata.fruDataVerMinor)),
                                  TWO_UINT16_TO_UINT32(
                                      TO_UINT16(SUPPORTED_FRU_VERSION_MAJOR),
                                      TO_UINT16(SUPPORTED_FRU_VERSION_MINOR))),
                               response_hdr_data,
                               ErrlEntry::ADD_SW_CALLOUT);
        errl->collectTrace(PLDM_COMP_NAME);
        break;
    }

    PLDM_INF("decode_get_fru_record_table_metadata_resp returned: "
            "Completion Code 0x%.02x",
             completion_code);
    PLDM_INF("Output Vars:  FruVer %.02x.%.02x  "
            "Max Table Size 0x%.08x  Actual Table Size 0x%.08x  "
            "Record Set Indexes 0x%.04x    Record Count 0x%.04x ",
            o_table_metadata.fruDataVerMajor,
            o_table_metadata.fruDataVerMinor,
            o_table_metadata.fruTableMaxSize,
            o_table_metadata.fruTableSize,
            o_table_metadata.rsiCount,
            o_table_metadata.recordCount);

    }while(0);

    PLDM_EXIT("Exit getFruRecordTableMetaData");
    return errl;

}

// TODO RTC:248498 add crc integrity check
errlHndl_t getFruRecordTable(const size_t i_table_buffer_len,
                             uint8_t * o_table_buffer)
{
    errlHndl_t errl = nullptr;
    do
    {

    PLDM_ENTER("Enter getFruRecordTable buflen 0x%.08x",
                i_table_buffer_len);
#ifndef __HOSTBOOT_RUNTIME
    msg_q_t msgQ = msg_q_resolve(VFS_ROOT_MSG_PLDM_REQ_OUT);
    assert(msgQ != nullptr,
            "Bug! PLDM Req Out Message queue did not resolve properly!");
#else
    msg_q_t msgQ = nullptr;
#endif

    std::vector<uint8_t> response_bytes;

    errl = sendrecv_pldm_request<PLDM_GET_FRU_RECORD_TABLE_REQ_BYTES>(
        response_bytes,
        msgQ,
        encode_get_fru_record_table_req,
        DEFAULT_INSTANCE_ID,
        PLDM::INITIAL_TRANS_HNDL,
        PLDM::GET_FIRST_PART);

    if(errl)
    {
        PLDM_ERR("error attempting get_fru_record_table request");
        break;
    }

    // pack the PLDM header of the response into a uint64_t which can
    // be used for error logging / debugging
    uint64_t response_hdr_data =
      pldmHdrToUint64(*reinterpret_cast<pldm_msg*>(response_bytes.data()));

    pldm_get_fru_record_table_resp response = { };
    size_t table_data_len = 0;


    errl =
        decode_pldm_response(decode_get_fru_record_table_resp,
                             response_bytes,
                             &response.completion_code,
                             &response.next_data_transfer_handle,
                             &response.transfer_flag,
                             o_table_buffer,
                             &table_data_len);

    if(errl)
    {
        PLDM_ERR("decode_get_fru_record_table_resp failed see error log");
        break;
    }

    // Bad completion code means BMC had problems processing our request
    if(response.completion_code != PLDM_SUCCESS)
    {
        PLDM_ERR("decode_get_fru_record_table_metadata_resp failed with completion code 0x%.02x",
                 response.completion_code);

        /*@
        * @errortype  ERRL_SEV_UNRECOVERABLE
        * @moduleid   MOD_GET_FRU_TABLE
        * @reasoncode RC_BAD_COMPLETION_CODE
        * @userdata1  Completion returned by BMC
        * @userdata2  Response header data (see pldm_msg_hdr struct)
        * @devdesc    Software problem, BMC returned bad PLDM response code
        * @custdesc   A software error occurred during system boot
        */
        errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                               PLDM::MOD_GET_FRU_TABLE,
                               PLDM::RC_BAD_COMPLETION_CODE,
                               response.completion_code,
                               response_hdr_data,
                               ErrlEntry::NO_SW_CALLOUT);
        addBmcErrorCallouts(errl);
        break;
    }

    // The table returned could have some padding at the end we do not want.
    // Just make sure the padding it within a valid range (0-3 bytes)
    if((table_data_len < i_table_buffer_len) ||
       (table_data_len - i_table_buffer_len > 3))
    {
        // The buffer that was returnd from BMC that contains table info does
        // not match the size that the get fru table meta data cmd told us

        PLDM_ERR("decode_get_fru_record_table_resp table_data_len - i_table_buffer_len = %d  , expected this difference to be between 0-3",
                table_data_len - i_table_buffer_len );
        /*@
         * @errortype  ERRL_SEV_UNRECOVERABLE
         * @moduleid   MOD_GET_FRU_TABLE
         * @reasoncode RC_INVALID_LENGTH
         * @userdata1[0:31]   Table Length Expected
         * @userdata1[32:63]  Table Length returned from BMC
         *                    (We expected diff between 0<= diff <=3)
         * @userdata2  Response header data (see pldm_msg_hdr struct)
         * @devdesc    Software problem, likely PLDM version problem w/ bmc
         * @custdesc   A software error occurred during system boot
         */
        errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                             PLDM::MOD_GET_FRU_TABLE,
                             PLDM::RC_INVALID_LENGTH,
                             TWO_UINT32_TO_UINT64(i_table_buffer_len,
                                                  table_data_len),
                             response_hdr_data,
                             ErrlEntry::NO_SW_CALLOUT);
        addBmcErrorCallouts(errl);
        break;
    }

    TRACDBIN( PLDM::g_trac_pldm,"Table Buffer:", o_table_buffer, i_table_buffer_len);
    // Use i_table_buffer_len to avoid copying the extra padding we dont care about.

    }while(0);

    PLDM_EXIT("Exit getFruRecordTableMetaData");
    return errl;
}
}
