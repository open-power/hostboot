/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/requests/pldm_fru_requests.C $                   */
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

// System Headers
#include <assert.h>
#include <string.h>
#include <sys/msg.h>
#include <util/align.H>
#include <cstdlib>
#include <map>
#include <vector>
#include <endian.h>
// From pldm include dir
#include <pldm/pldm_const.H>
#include <pldm/pldm_reasoncodes.H>
#include <pldm/requests/pldm_fru_requests.H>
// From local pldm src dir
#include "../common/pldmtrace.H"
#include "../extern/fru.h"
// Other userspace module includes
#include <mctp/mctp_message_types.H>

using namespace ERRORLOG;

// currently we support version 1.0 of fru table
constexpr uint8_t SUPPORTED_VERSION_MAJOR = 1;
constexpr uint8_t SUPPORTED_VERSION_MINOR = 0;


extern const char* VFS_ROOT_MSG_PLDM_REQ_OUT;

errlHndl_t PLDM::getFruRecordTableMetaData(PLDM::pldm_fru_record_table_metadata_t& o_table_metadata)
{
    msg_t* l_msg = nullptr;
    errlHndl_t l_errl = nullptr;
    do {

    PLDM_ENTER("Enter getFruRecordTableMetaData");
    msg_q_t l_msgQ = msg_q_resolve(VFS_ROOT_MSG_PLDM_REQ_OUT);
    assert(l_msgQ != nullptr,
            "Bug! PLDM Req Out Message queue did not resolve properly!");

    // Size will be size of standard pldm msg + number of bytes we
    // must leave empty in front of buffer for MCTP's Payload Type
    size_t l_bufLen = sizeof(pldm_msg) + sizeof(MCTP::MCTP_MSG_TYPE_PLDM);
    // Allocate a buffer which will be passed in the extra_data of the msg_t struct
    // on the stack
    uint8_t l_buffer[l_bufLen] = {0};
    // Offset the ptr by sizeof(MCTP::MCTP_MSG_TYPE_PLDM) so we leave space
    // in buffer for MCTP layer to fill in
    struct pldm_msg *l_pldm_msg =
          reinterpret_cast<pldm_msg *>(l_buffer +
                                        sizeof(MCTP::MCTP_MSG_TYPE_PLDM));

    // Pass 0 for the message id, the task managing the outbound PLDM
    // request msg Q will set the message ID for us
    uint8_t l_rc = encode_get_fru_record_table_metadata_req(0, l_pldm_msg);

    if(l_rc != PLDM_SUCCESS)
    {
        PLDM_ERR("encode_get_fru_record_table_req failed with rc 0x%.02x",
                  l_rc);
        /*
        * @errortype  ERRL_SEV_UNRECOVERABLE
        * @moduleid   MOD_GET_FRU_METADATA
        * @reasoncode RC_MSG_ENCODE_FAIL
        * @userdata1  RC returned from encode function
        * @devdesc    Software problem, failed to encode PLDM message
        * @custdesc   A software error occurred during system boot
        */
        l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                               PLDM::MOD_GET_FRU_METADATA,
                               PLDM::RC_MSG_ENCODE_FAIL,
                               l_rc,
                               0,
                               ErrlEntry::ADD_SW_CALLOUT);
        l_errl->collectTrace(PLDM_COMP_NAME);
        break;
    }

    // Build up the message we will put on the PLDM REQ OUT MSGQ
    l_msg = msg_allocate();
    l_msg->data[0] = l_bufLen;
    l_msg->extra_data = l_buffer;

    // Place message on the queue and wait for a response
    l_rc = msg_sendrecv(l_msgQ, l_msg);

    assert(l_rc == 0,
            "Error occurred performing send_recv for getFruRecordTableMetaData");

    // Calculate the payload length by taking the total message
    // size (data[0]) minus the sizeof(pldm_msg_hdr)
    size_t l_payloadLen = l_msg->data[0] - sizeof(pldm_msg_hdr);
    uint8_t  l_completionCode = PLDM_SUCCESS;

    // NOTE that the o_table_metadata->fruTableMaxSize filled out in the
    // function below does not include the padding or checksum at the end of
    // the PLDM representation of the Fru Record data. If you are looking at
    // v1.0.0 of the DSP0257 spec the size represents data in table 3,
    // NOT table 7.
    l_rc =
      decode_get_fru_record_table_metadata_resp(
          reinterpret_cast<pldm_msg *>(l_msg->extra_data),
          l_payloadLen, &l_completionCode,
          &o_table_metadata.fruDataVerMajor,
          &o_table_metadata.fruDataVerMinor,
          &o_table_metadata.fruTableMaxSize,
          &o_table_metadata.fruTableSize,
          &o_table_metadata.rsiCount,
          &o_table_metadata.recordCount,
          &o_table_metadata.checksum);

    // Bad RC means we had issues decoding the response
    if(l_rc != PLDM_SUCCESS)
    {
        PLDM_ERR("decode_get_fru_record_table_metadata_resp failed with rc 0x%.02x",
                l_rc);

        /*
        * @errortype  ERRL_SEV_UNRECOVERABLE
        * @moduleid   MOD_GET_FRU_METADATA
        * @reasoncode RC_MSG_DECODE_FAIL
        * @userdata1  RC returned from decode function
        * @userdata2  Calculated payload length
        * @devdesc    Software problem, failed to decode PLDM message
        * @custdesc   A software error occurred during system boot
        */
        l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                               PLDM::MOD_GET_FRU_METADATA,
                               PLDM::RC_MSG_DECODE_FAIL,
                               l_rc,
                               l_payloadLen,
                               ErrlEntry::ADD_SW_CALLOUT);
        l_errl->collectTrace(PLDM_COMP_NAME);
        break;
    }

    // Bad completion code means BMC had problems processing our request
    if(l_completionCode != PLDM_SUCCESS)
    {
        PLDM_ERR("decode_get_fru_record_table_metadata_resp failed with rc 0x%.02x",
                l_rc);

        /*
        * @errortype  ERRL_SEV_UNRECOVERABLE
        * @moduleid   MOD_GET_FRU_METADATA
        * @reasoncode RC_BAD_COMPLETION_CODE
        * @userdata1  RC returned from decode function
        * @userdata2  Calculated payload length
        * @devdesc    Software problem, failed to decode PLDM message
        * @custdesc   A software error occurred during system boot
        */
        l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                               PLDM::MOD_GET_FRU_METADATA,
                               PLDM::RC_BAD_COMPLETION_CODE,
                               l_completionCode,
                               l_payloadLen,
                               ErrlEntry::ADD_SW_CALLOUT);
        l_errl->collectTrace(PLDM_COMP_NAME);
        break;
    }

    if(o_table_metadata.fruDataVerMajor != SUPPORTED_VERSION_MAJOR ||
        o_table_metadata.fruDataVerMinor != SUPPORTED_VERSION_MINOR )
    {
        PLDM_ERR("decode_get_fru_record_table_metadata_resp invalid version %d.%d when expecting 1.0",
                  o_table_metadata.fruDataVerMajor,
                  o_table_metadata.fruDataVerMinor);
        /*
        * @errortype  ERRL_SEV_UNRECOVERABLE
        * @moduleid   MOD_GET_FRU_METADATA
        * @reasoncode RC_UNSUPPORTED_VERSION
        * @userdata1  Calculated payload length
        * @userdata2  Unused
        * @devdesc    Software problem, failed to decode PLDM message
        * @custdesc   A software error occurred during system boot
        */
        l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                               PLDM::MOD_GET_FRU_METADATA,
                               PLDM::RC_UNSUPPORTED_VERSION,
                               l_payloadLen,
                               0,
                               ErrlEntry::ADD_SW_CALLOUT);
        l_errl->collectTrace(PLDM_COMP_NAME);
        break;
    }

    PLDM_INF("decode_get_fru_record_table_metadata_resp returned: "
            "Completion Code 0x%.02x",
              l_completionCode);
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

    // free up the message pointer and the associated extra data before we exit
    free(l_msg->extra_data);
    l_msg->extra_data = nullptr;
    msg_free(l_msg);
    l_msg = nullptr;

    PLDM_EXIT("Exit getFruRecordTableMetaData");
    return l_errl;

}

// TODO add crc integrity check
errlHndl_t PLDM::getFruRecordTable(const size_t i_tableBufferLen,
                                   uint8_t * o_tableBuffer)
{
    msg_t* l_msg = nullptr;
    errlHndl_t l_errl = nullptr;
    do
    {

    PLDM_ENTER("Enter getFruRecordTable buflen 0x%.08x",
                i_tableBufferLen);
    msg_q_t l_msgQ = msg_q_resolve(VFS_ROOT_MSG_PLDM_REQ_OUT);
    assert(l_msgQ != nullptr,
            "Bug! PLDM Req Out Message queue did not resolve properly!");

    // Size will be size of standard pldm msg + number of bytes we
    // must leave empty in front of buffer for MCTP's Payload Type
    size_t l_bufLen = sizeof(pldm_msg_hdr) +
                      PLDM_GET_FRU_RECORD_TABLE_REQ_BYTES +
                      sizeof(MCTP::MCTP_MSG_TYPE_PLDM);
    uint8_t l_buffer[l_bufLen] = {0};
    // Offset the ptr by sizeof(MCTP::MCTP_MSG_TYPE_PLDM) so we leave space in buffer
    // for MCTP layer to fill in
    struct pldm_msg *l_pldm_msg =
            reinterpret_cast<pldm_msg *>(l_buffer +
                                          sizeof(MCTP::MCTP_MSG_TYPE_PLDM));

    uint8_t l_rc = encode_get_fru_record_table_req(0,
                                           PLDM::INITIAL_TRANS_HNDL,
                                           PLDM::GET_FIRST_PART,
                                           l_pldm_msg);
    if(l_rc != PLDM_SUCCESS)
    {
        PLDM_ERR("encode_get_fru_record_table_req failed with rc 0x%.02x",
                  l_rc);
        /*
        * @errortype  ERRL_SEV_UNRECOVERABLE
        * @moduleid   MOD_GET_FRU_TABLE
        * @reasoncode RC_MSG_ENCODE_FAIL
        * @userdata1  RC returned from encode function
        * @devdesc    Software problem, failed to encode PLDM message
        * @custdesc   A software error occurred during system boot
        */
        l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                               PLDM::MOD_GET_FRU_TABLE,
                               PLDM::RC_MSG_ENCODE_FAIL,
                               l_rc,
                               0,
                               ErrlEntry::ADD_SW_CALLOUT);
        l_errl->collectTrace(PLDM_COMP_NAME);
        break;
    }

    // Build up the message we will put on the PLDM REQ OUT MSGQ
    l_msg = msg_allocate();
    l_msg->data[0] = l_bufLen;
    l_msg->extra_data = l_buffer;
    // Place message on the queue and wait for a response
    l_rc = msg_sendrecv(l_msgQ, l_msg);

    assert(l_rc == 0,
            "Error occurred performing send_recv for getFruRecordTableMetaData");

    // Calculate the payload length by taking the total message
    // size (data[0]) minus the sizeof(pldm_msg_hdr)
    pldm_msg * l_pldm_msg_ptr =
                      reinterpret_cast<pldm_msg *>(l_msg->extra_data);
    size_t l_payloadLen = l_msg->data[0] - sizeof(pldm_msg_hdr);
    uint8_t  l_completionCode = PLDM_SUCCESS;
    uint32_t l_next_data_transfer = 0x00000000;
    uint8_t  l_transfer_flag = 0x00;
    uint8_t * l_table_data = nullptr;

    l_rc = decode_get_fru_record_table_resp(l_pldm_msg_ptr,
                                            l_payloadLen,
                                            &l_completionCode,
                                            &l_next_data_transfer,
                                            &l_transfer_flag);

    if(l_rc != PLDM_SUCCESS)
    {
        PLDM_ERR("decode_get_fru_record_table_metadata_resp failed with rc 0x%.02x",
                l_rc);

        /*
        * @errortype  ERRL_SEV_UNRECOVERABLE
        * @moduleid   MOD_GET_FRU_TABLE
        * @reasoncode RC_MSG_DECODE_FAIL
        * @userdata1  RC returned from decode function
        * @userdata2  Calculated payload length
        * @devdesc    Software problem, failed to decode PLDM message
        * @custdesc   A software error occurred during system boot
        */
        l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                               PLDM::MOD_GET_FRU_TABLE,
                               PLDM::RC_MSG_DECODE_FAIL,
                               l_rc,
                               l_payloadLen,
                               ErrlEntry::ADD_SW_CALLOUT);
        l_errl->collectTrace(PLDM_COMP_NAME);
        break;
    }

    // Bad completion code means BMC had problems processing our request
    if(l_completionCode != PLDM_SUCCESS)
    {
        PLDM_ERR("decode_get_fru_record_table_metadata_resp failed with completion code 0x%.02x",
                l_completionCode);

        /*
        * @errortype  ERRL_SEV_UNRECOVERABLE
        * @moduleid   MOD_GET_FRU_TABLE
        * @reasoncode RC_BAD_COMPLETION_CODE
        * @userdata1  Completion returned by BMC
        * @userdata2  Calculated payload length
        * @devdesc    Software problem, bmc unable to handle pldm
                      request
        * @custdesc   A software error occurred during system boot
        */
        l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                               PLDM::MOD_GET_FRU_TABLE,
                               PLDM::RC_BAD_COMPLETION_CODE,
                               l_completionCode,
                               l_payloadLen,
                               ErrlEntry::ADD_SW_CALLOUT);
        l_errl->collectTrace(PLDM_COMP_NAME);
        break;
    }

    // table data starts after header + completion code, next data transfer, and
    // transfer flag fields of the response so offset the ptr accordingly
    l_table_data = reinterpret_cast<uint8_t *>(l_pldm_msg_ptr +
                                                offsetof(pldm_get_fru_record_table_resp,
                                                        fru_record_table_data) +
                                                offsetof(pldm_msg,
                                                        payload));

    // Remove the size of the return values that are not included in the
    // size returned from the getFruRecordTableMetaData request
    size_t l_tableDataLen = l_payloadLen -
                            (sizeof(l_completionCode) + sizeof(l_next_data_transfer) +
                            sizeof(l_transfer_flag) + FRU_TABLE_CHECKSUM_SIZE);

    // The table returned could have some padding at the end we do not want.
    // Just make sure the padding it within a valid range (0-3 bytes)
    if(l_tableDataLen < i_tableBufferLen ||
        l_tableDataLen - i_tableBufferLen > 3)
    {
        // The buffer that was returnd from BMC that contains table info does
        // not match the size that the get fru table meta data cmd told us
        PLDM_ERR("decode_get_fru_record_table_resp l_tableDataLen - i_tableBufferLen = %d  , expected this difference to be between 0-3",
                l_tableDataLen - i_tableBufferLen );
        /*
        * @errortype  ERRL_SEV_UNRECOVERABLE
        * @moduleid   MOD_GET_FRU_TABLE
        * @reasoncode RC_INVALID_LENGTH
        * @userdata1  Table Length Expected
        * @userdata2  Table Length returned from BMC
        *             (Expected diff between 1 and 2 should be 0<= diff <=3)
        * @devdesc    Software problem, likely PLDM version problem w/ bmc
        * @custdesc   A software error occurred during system boot
        */
        l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                               PLDM::MOD_GET_FRU_TABLE,
                               PLDM::RC_INVALID_LENGTH,
                               i_tableBufferLen,
                               i_tableBufferLen,
                               ErrlEntry::ADD_SW_CALLOUT);
        l_errl->collectTrace(PLDM_COMP_NAME);
        break;
    }

    TRACDBIN( PLDM::g_trac_pldm,"Table Buffer:", l_table_data, i_tableBufferLen);
    // Copy the data to the out buffer
    memcpy(o_tableBuffer, l_table_data, i_tableBufferLen);

    }while(0);

    // free up the message pointer and the associated extra data before we exit
    free(l_msg->extra_data);
    l_msg->extra_data = nullptr;
    msg_free(l_msg);
    l_msg = nullptr;

    PLDM_EXIT("Exit getFruRecordTableMetaData");
    return l_errl;
}
