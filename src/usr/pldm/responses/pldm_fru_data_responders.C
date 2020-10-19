/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/responses/pldm_fru_data_responders.C $           */
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

/* @file pldm_fru_data_responders.C
 *
 * @brief Implementation of the PLDM FRU Data responder functions.
 */

// PLDM
#include <pldm/pldm_errl.H>
#include <pldm/pldm_const.H>
#include <pldm/pldm_reasoncodes.H>
#include <pldm/pldm_response.H>
#include <pldm/extended/pldm_fru.H>
#include <pldm/extended/pdr_manager.H>
#include <pldm/extended/hb_pdrs.H>
#include <pldm/responses/pldm_fru_data_responders.H>
#include "../common/pldmtrace.H"

// libpldm headers from pldm subtree
#include <openbmc/pldm/libpldm/platform.h>
#include <openbmc/pldm/libpldm/base.h>
#include <openbmc/pldm/libpldm/fru.h>

// Targeting
#include <targeting/common/utilFilter.H>
#include <targeting/targplatutil.H>

// Device FW, VPD constants
#include <devicefw/driverif.H>
#include <vpd/mvpdenums.H>
#include <vpd/spdenums.H>

// Standard library
#include <map>
#include <assert.h>

using namespace TARGETING;
using namespace ERRORLOG;
using namespace PLDM;

namespace
{

// Used by the metadata request handler for the value of FRUTableMaximumSize; 0
// means SetFRURecordTable command is not supported (see DSP 0257 v1.0.0 Table
// 9)
const int FRU_TABLE_MAX_SIZE_UNSUPPORTED = 0;

// This is a list of types for which we need to send a location code to the BMC
const fru_inventory_class host_location_code_frus[] =
{
    { CLASS_CHIP, TYPE_PROC, ENTITY_TYPE_PROCESSOR_MODULE },
    { CLASS_LOGICAL_CARD, TYPE_DIMM, ENTITY_TYPE_DIMM }
};

/* @brief  Encode a GetFRURecordTable response
 *
 * @param[in] i_instance_id                Forwarded to encode_get_fru_record_table_resp
 * @param[in] i_completion_code            Forwarded
 * @param[in] i_next_data_transfer_handle  Forwarded
 * @param[in] i_transfer_flag              Forwarded
 * @param[in] i_fru_record_table_bytes     FRU record table to send
 * @param[in] i_fru_record_table_size      Size of FRU record table in bytes
 * @param[out] o_msg                       PLDM message to encode
 * @return int                             PLDM result code
 * @note The libpldm encoder for responses to GetFRURecordTable requests has an
 *       aberrant signature and will not work nicely with send_pldm_response, so
 *       we have to make our own here.
*/
int encode_get_fru_record_table_resp_hb(const uint8_t i_instance_id,
                                        const uint8_t i_completion_code,
                                        const uint32_t i_next_data_transfer_handle,
                                        const uint8_t i_transfer_flag,
                                        const uint8_t* const i_fru_record_table_bytes,
                                        const size_t i_fru_record_table_size,
                                        pldm_msg* const o_msg)
{
    const int rc = encode_get_fru_record_table_resp(i_instance_id,
                                                    i_completion_code,
                                                    i_next_data_transfer_handle,
                                                    i_transfer_flag,
                                                    o_msg);

    if (rc == PLDM_SUCCESS)
    {
        const auto response =
            reinterpret_cast<pldm_get_fru_record_table_resp*>(o_msg->payload);

        memcpy(response->fru_record_table_data,
               i_fru_record_table_bytes,
               i_fru_record_table_size);
    }

    return rc;
}

// @brief A class to manage creating a FRU record table
class FruRecordTable
{
public:
    /* @brief Returns the size of the record table data in bytes
     */
    uint32_t recordDataByteSize() const;

    /* @brief Returns pointer to the record data bytes
     */
    const uint8_t* recordData() const;

    /* @brief Returns the number of records in this table
     */
    uint16_t recordCount() const;

    /* @brief Returns the number of record sets in this table
     */
    uint16_t recordSetCount() const;

    /* @brief Load all the FRU records from VPD into the table.
     */
    void loadAllFruRecords();

private:
    /* @brief Load all the FRU records for a particular target.
     *
     * @note Right now this only loads the location code.
     *
     * @param[in] i_target      The Target to read VPD from
     * @param[in] i_entityType  The entity type of the target
     */
    void loadFruRecords(TARGETING::Target* const i_target,
                        const entity_type i_entityType);

    std::vector<uint8_t> iv_fru_record_table_bytes;
    uint16_t iv_num_records = 0;
    std::map<fru_record_set_id_t, bool> iv_record_sets;
};

uint32_t FruRecordTable::recordDataByteSize() const
{
    return iv_fru_record_table_bytes.size();
}

const uint8_t* FruRecordTable::recordData() const
{
    return iv_fru_record_table_bytes.data();
}

uint16_t FruRecordTable::recordCount() const
{
    return iv_num_records;
}

uint16_t FruRecordTable::recordSetCount() const
{
    return iv_record_sets.size();
}

void FruRecordTable::loadAllFruRecords()
{
    PLDM_INF("Loading all FRU records...");

    /* Iterate the relevant targets and serialize each location code */

    for (const auto& info : host_location_code_frus)
    {
        TargetHandleList targets;

        getClassResources(targets,
                          info.targetClass,
                          info.targetType,
                          UTIL_FILTER_PRESENT);

        for (const auto target : targets)
        {
            loadFruRecords(target, info.entityType);
        }
    }

    PLDM_INF("Done loading all FRU records (%d records, %d record sets, %d bytes)",
             recordCount(),
             recordSetCount(),
             recordDataByteSize());

    PLDM_DBG_BIN("Encoded FRU record table",
                 iv_fru_record_table_bytes.data(),
                 iv_fru_record_table_bytes.size());
}

/* @brief Encode a FRU Record key/value pair and append it to a buffer.
 *
 * @param[in] i_type       The type of the value
 * @param[in] i_length     The length of the value
 * @param[in] i_value      The value
 * @param[in/out] io_data  The buffer to append to
 */
void encodeTlv(const uint8_t i_type,
               const size_t i_length,
               const void* const i_value,
               std::vector<uint8_t>& io_data)
{
    assert(i_length <= UINT8_MAX,
           "Length of FRU record field value is too large to encode in TLV");

    io_data.push_back(i_type);
    io_data.push_back(i_length);
    io_data.insert(end(io_data),
                   static_cast<const uint8_t*>(i_value),
                   static_cast<const uint8_t*>(i_value) + i_length);
}

using fru_data_t = std::vector<uint8_t>;

/* @brief Reads the location code from a target and encodes it as in TLV format.
 *
 * @param[in] i_target        The target to read VPD from
 * @param[out] o_fru_data     The vector to fill with FRU TLVs
 */
void read_location_code_tlv(Target* const i_target,
                            fru_data_t& o_fru_data)
{
    o_fru_data.clear();

    /* The location code attribute only contains the "local" location code, so
     * we have to prefix the chassis location code to root it properly. */

    std::vector<char> full_location_code;

    /* Read the chassis location code */

    {
        Target* const sys = UTIL::assertGetToplevelTarget();

        ATTR_CHASSIS_LOCATION_CODE_type location_code { };

        static_assert(sizeof(location_code) <= UINT8_MAX,
                      "Location code too large to encode in a FRU TLV");

        assert(sys->tryGetAttr<ATTR_CHASSIS_LOCATION_CODE>(location_code),
               "Cannot get ATTR_CHASSIS_LOCATION_CODE from toplevel target");

        full_location_code.insert(end(full_location_code),
                                  location_code, location_code + strlen(location_code));
    }

    /* Append separator */

    full_location_code.push_back('-');

    /* Append the target location code */

    {
        ATTR_LOCATION_CODE_type location_code { };

        static_assert(sizeof(location_code) <= UINT8_MAX,
                      "Location code too large to encode in a FRU TLV");

        assert(i_target->tryGetAttr<ATTR_LOCATION_CODE>(location_code),
               "Cannot get ATTR_LOCATION_CODE from HUID = 0x%08x",
               get_huid(i_target));

        full_location_code.insert(end(full_location_code),
                                  location_code, location_code + strlen(location_code));
    }

    /* Encode the TLV */

    const int location_code_key = 254;

    encodeTlv(location_code_key,
              full_location_code.size(),
              full_location_code.data(),
              o_fru_data);
}

void FruRecordTable::loadFruRecords(Target* const i_target,
                                    const entity_type i_entityType)
{
    PLDM_INF("Loading FRU records for %s (0x%08x)",
             attrToString<ATTR_TYPE>(i_target->getAttr<ATTR_TYPE>()),
             get_huid(i_target));

    const fru_record_set_id_t rsid = getTargetFruRecordSetID(i_target);

    /* Read the target's location code, encoded as a TLV */

    fru_data_t fru_tlvs;

    read_location_code_tlv(i_target, fru_tlvs);

    /* Reserve space in the record table */

    size_t fru_record_table_used_bytes = iv_fru_record_table_bytes.size();

    const size_t record_hdr_size =
        (sizeof(struct pldm_fru_record_data_format)
         - sizeof(struct pldm_fru_record_tlv));

    iv_fru_record_table_bytes.resize(iv_fru_record_table_bytes.size()
                                     + record_hdr_size
                                     + fru_tlvs.size());

    /* Encode the record in the table */

    const int num_tlvs = 1;

    const int encode_rc = encode_fru_record(iv_fru_record_table_bytes.data(),
                                            iv_fru_record_table_bytes.size(),
                                            &fru_record_table_used_bytes,
                                            rsid,
                                            PLDM_FRU_RECORD_TYPE_OEM,
                                            num_tlvs,
                                            PLDM_FRU_ENCODING_ASCII,
                                            fru_tlvs.data(),
                                            fru_tlvs.size());

    assert(encode_rc == PLDM_SUCCESS,
           "encode_fru_record failed with rc = %d",
           encode_rc);

    /* Adjust bookkeeping numbers */

    ++iv_num_records;
    iv_record_sets[rsid] = true;
}

} // anonymous namespace

namespace PLDM
{

errlHndl_t handleGetFruRecordTableMetadataRequest(const msg_q_t i_msgQ,
                                                  const pldm_msg* const i_msg,
                                                  const size_t i_payload_len)
{
    PLDM_ENTER("handleGetFruRecordTableMetadataRequest");

    // getFruRecordTableMetadata requests don't have any payload, so no need to
    // decode them.

    FruRecordTable table;
    table.loadAllFruRecords();

    const errlHndl_t errl =
        send_pldm_response<PLDM_GET_FRU_RECORD_TABLE_METADATA_RESP_BYTES>
        (i_msgQ,
         encode_get_fru_record_table_metadata_resp,
         PLDM_RESPONSE_EMPTY_PAYLOAD_SIZE,
         i_msg->hdr.instance_id,
         PLDM_SUCCESS,
         SUPPORTED_FRU_VERSION_MAJOR,
         SUPPORTED_FRU_VERSION_MINOR,
         FRU_TABLE_MAX_SIZE_UNSUPPORTED,
         table.recordDataByteSize(),
         table.recordSetCount(),
         table.recordCount(),
         0); // checksum, not calculated

    if (errl)
    {
        PLDM_ERR("handleGetFruRecordTableMetadataRequest: send_pldm_response failed");
    }

    PLDM_EXIT("handleGetFruRecordTableMetadataRequest");

    return errl;
}

errlHndl_t handleGetFruRecordTableRequest(const msg_q_t i_msgQ,
                                          const pldm_msg* const i_msg,
                                          const size_t i_payload_len)
{
    PLDM_ENTER("handleGetFruRecordTableRequest");

    // The getFruRecordTable requests do have request data, but it's only
    // related to multi-part transfers which we don't support and which the BMC
    // will not send us.

    FruRecordTable table;
    table.loadAllFruRecords();

    const errlHndl_t errl =
        send_pldm_response<PLDM_GET_FRU_RECORD_TABLE_MIN_RESP_BYTES>
        (i_msgQ,
         encode_get_fru_record_table_resp_hb,
         table.recordDataByteSize(),
         i_msg->hdr.instance_id,
         PLDM_SUCCESS,
         0, // No next transfer handle
         PLDM_START_AND_END,
         table.recordData(),
         payload_length_placeholder_t{});

    if (errl)
    {
        PLDM_ERR("handleGetFruRecordTableRequest: send_pldm_response failed");
    }

    PLDM_EXIT("handleGetFruRecordTableRequest");

    return errl;
}

}
