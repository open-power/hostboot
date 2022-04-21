/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/requests/pldm_fru_requests.C $                   */
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
#include <sys/msg.h>
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
#include <openbmc/pldm/libpldm/utils.h>
// Local includes
#include "pldm_request_utils.H"

// Other userspace module includes
#include <mctp/mctp_message_types.H>


using namespace ERRORLOG;

namespace PLDM
{

errlHndl_t getFruRecordTableMetaData(pldm_get_fru_record_table_metadata_resp & o_table_metadata)
{
    errlHndl_t errl = nullptr;
    do {

    PLDM_ENTER("Enter getFruRecordTableMetaData");

    std::vector<uint8_t> response_bytes;

    errl = sendrecv_pldm_request<PLDM_GET_FRU_RECORD_TABLE_METADATA_REQ_BYTES>(
                      response_bytes,
                      g_outboundPldmReqMsgQ,
                      encode_get_fru_record_table_metadata_req,
                      DEFAULT_INSTANCE_ID);

    if(errl)
    {
        PLDM_ERR("error attempting get_fru_record_table_metadata request");
        break;
    }

    errl =
        decode_pldm_response(decode_get_fru_record_table_metadata_resp,
                              response_bytes,
                              &o_table_metadata.completion_code,
                              &o_table_metadata.fru_data_major_version,
                              &o_table_metadata.fru_data_minor_version,
                              &o_table_metadata.fru_table_maximum_size,
                              &o_table_metadata.fru_table_length,
                              &o_table_metadata.total_record_set_identifiers,
                              &o_table_metadata.total_table_records,
                              &o_table_metadata.checksum);
    if (errl)
    {
        PLDM_ERR("decode_get_fru_record_table_metadata_resp decode failed see error log");
        break;
    }

    PLDM_INF("Output Vars:"
             "Max Table Size 0x%.08x  Actual Table Size 0x%.08x  "
             "Record Set Indexes 0x%.04x    Record Count 0x%.04x "
             "Checksum = 0x%.04x" ,
             o_table_metadata.fru_table_maximum_size,
             o_table_metadata.fru_table_length,
             o_table_metadata.total_record_set_identifiers,
             o_table_metadata.total_table_records,
             o_table_metadata.checksum);

    /*@
      * @errortype
      * @severity   ERRL_SEV_UNRECOVERABLE
      * @moduleid   MOD_GET_FRU_METADATA
      * @reasoncode RC_BAD_COMPLETION_CODE
      * @userdata1  Actual Completion Code
      * @userdata2  Expected Completion Code
      * @devdesc    Software problem, bad PLDM response from BMC
      * @custdesc   A software error occurred during system boot
      */
    errl = validate_resp(o_table_metadata.completion_code, PLDM_SUCCESS,
                         MOD_GET_FRU_METADATA, RC_BAD_COMPLETION_CODE,
                         response_bytes);
    if(errl)
    {
        break;
    }

    /*@
      * @errortype
      * @severity   ERRL_SEV_UNRECOVERABLE
      * @moduleid   MOD_GET_FRU_METADATA
      * @reasoncode RC_UNSUPPORTED_MAJOR_VERSION
      * @userdata1  Actual Major Version
      * @userdata2  Expected Major Version
      * @devdesc    Software problem, bad PLDM response from BMC
      * @custdesc   A software error occurred during system boot
      */
    errl = validate_resp(o_table_metadata.fru_data_major_version, SUPPORTED_FRU_VERSION_MAJOR,
                         MOD_GET_FRU_METADATA, RC_UNSUPPORTED_MAJOR_VERSION,
                         response_bytes);
    if(errl)
    {
        break;
    }

    /*@
      * @errortype
      * @severity   ERRL_SEV_UNRECOVERABLE
      * @moduleid   MOD_GET_FRU_METADATA
      * @reasoncode RC_UNSUPPORTED_MINOR_VERSION
      * @userdata1  Actual Minor Version
      * @userdata2  Expected Minor Version
      * @devdesc    Software problem, bad PLDM response from BMC
      * @custdesc   A software error occurred during system boot
      */
    errl = validate_resp(o_table_metadata.fru_data_minor_version, SUPPORTED_FRU_VERSION_MINOR,
                         MOD_GET_FRU_METADATA, RC_UNSUPPORTED_MINOR_VERSION,
                         response_bytes);
    if(errl)
    {
        break;
    }

    }while(0);

    PLDM_EXIT("Exit getFruRecordTableMetaData");
    return errl;

}

errlHndl_t getFruRecordTable(const size_t i_table_buffer_len,
                             uint8_t * o_table_buffer)
{
    errlHndl_t errl = nullptr;
    do
    {

    PLDM_ENTER("Enter getFruRecordTable buflen 0x%.08x",
                i_table_buffer_len);

    std::vector<uint8_t> response_bytes;

    errl = sendrecv_pldm_request<PLDM_GET_FRU_RECORD_TABLE_REQ_BYTES>(
        response_bytes,
        g_outboundPldmReqMsgQ,
        encode_get_fru_record_table_req,
        DEFAULT_INSTANCE_ID,
        PLDM::INITIAL_TRANS_HNDL,
        PLDM::GET_FIRST_PART);

    if(errl)
    {
        PLDM_ERR("error attempting get_fru_record_table request");
        break;
    }

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

    /*@
      * @errortype
      * @severity   ERRL_SEV_UNRECOVERABLE
      * @moduleid   MOD_GET_FRU_TABLE
      * @reasoncode RC_BAD_COMPLETION_CODE
      * @userdata1  Actual Completion Code
      * @userdata2  Expected Completion Code
      * @devdesc    Software problem, bad PLDM response from BMC
      * @custdesc   A software error occurred during system boot
      */
    // Bad completion code means BMC had problems processing our request
    errl = validate_resp(response.completion_code, PLDM_SUCCESS,
                         MOD_GET_FRU_TABLE, RC_BAD_COMPLETION_CODE,
                         response_bytes);
    if(errl)
    {
        break;
    }

    /*@
      * @errortype
      * @severity   ERRL_SEV_UNRECOVERABLE
      * @moduleid   MOD_GET_FRU_TABLE
      * @reasoncode RC_BAD_NEXT_TRANSFER_HANDLE
      * @userdata1  Actual Next Transfer Handle
      * @userdata2  Expected Next Transfer Handle
      * @devdesc    Software problem, bad PLDM response from BMC
      * @custdesc   A software error occurred during system boot
      */
    /* HB does not support multipart transfers */
    errl = validate_resp(response.next_data_transfer_handle, static_cast<pdr_handle_t>(0),
                         MOD_GET_FRU_TABLE, RC_BAD_NEXT_TRANSFER_HANDLE,
                         response_bytes);
    if(errl)
    {
        break;
    }

    /*@
      * @errortype
      * @severity   ERRL_SEV_UNRECOVERABLE
      * @moduleid   MOD_GET_FRU_TABLE
      * @reasoncode RC_BAD_TRANSFER_FLAG
      * @userdata1  Actual Transfer Flag
      * @userdata2  Expected Transfer Flag
      * @devdesc    Software problem, bad PLDM response from BMC
      * @custdesc   A software error occurred during system boot
      */
    errl = validate_resp(response.transfer_flag, PLDM_START_AND_END,
                         MOD_GET_FRU_TABLE, RC_BAD_TRANSFER_FLAG,
                         response_bytes);
    if(errl)
    {
        break;
    }

    /*@
      * @errortype
      * @severity   ERRL_SEV_UNRECOVERABLE
      * @moduleid   MOD_GET_FRU_TABLE
      * @reasoncode RC_INVALID_LENGTH
      * @userdata1  Actual table length
      * @userdata2  Table length from metadata
      * @devdesc    Software problem, bad PLDM response from BMC
      * @custdesc   A software error occurred during system boot
      */
    errl = validate_resp(table_data_len, i_table_buffer_len,
                         MOD_GET_FRU_TABLE, RC_INVALID_LENGTH,
                         response_bytes);
    if(errl)
    {
        break;
    }

    /* Calculate the CRC32 on the table data excluding the last 4 bytes which
       contains the CRC32 we will compare our result against.*/
    auto actual_crc = crc32(o_table_buffer, table_data_len - 4);
    auto expected_crc = le32toh(*reinterpret_cast<uint32_t *>(o_table_buffer + table_data_len - 4));

    /*@
      * @errortype
      * @severity   ERRL_SEV_UNRECOVERABLE
      * @moduleid   MOD_GET_FRU_TABLE
      * @reasoncode RC_CRC_MISMATCH
      * @userdata1  Actual CRC
      * @userdata2  Expected CRC
      * @devdesc    Software problem, bad PLDM response from BMC
      * @custdesc   A software error occurred during system boot
      */
    errl = validate_resp(actual_crc, expected_crc,
                         MOD_GET_FRU_TABLE, RC_CRC_MISMATCH,
                         response_bytes);
    if(errl)
    {
        break;
    }

    TRACFBIN( PLDM::g_trac_pldm,"Table Buffer:", o_table_buffer, i_table_buffer_len);

    }while(0);

    PLDM_EXIT("Exit getFruRecordTable");
    return errl;
}
}
