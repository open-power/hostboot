/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/responses/pldm_fru_data_responders.C $           */
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

/* @file pldm_fru_data_responders.C
 *
 * @brief Implementation of the PLDM FRU Data responder functions.
 */

// PLDM
#include <pldm/pldm_errl.H>
#include <pldm/pldm_const.H>
#include <pldm/pldm_reasoncodes.H>
#include <pldm/pldm_response.H>
#include <pldm/pldm_trace.H>
#include <pldm/extended/pldm_fru.H>
#include <pldm/extended/pdr_manager.H>
#include <pldm/extended/hb_pdrs.H>
#include <pldm/responses/pldm_fru_data_responders.H>

// libpldm headers from pldm subtree
#include <openbmc/pldm/libpldm/platform.h>
#include <openbmc/pldm/libpldm/base.h>
#include <openbmc/pldm/libpldm/fru.h>

#include <openbmc/pldm/oem/ibm/libpldm/fru.h>

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
    { CLASS_CHIP, TYPE_PROC, ENTITY_TYPE_PROCESSOR },
    { CLASS_LOGICAL_CARD, TYPE_DIMM, ENTITY_TYPE_DIMM },
    { CLASS_UNIT, TYPE_CORE, ENTITY_TYPE_LOGICAL_PROCESSOR },
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

using fru_data_t = std::vector<uint8_t>;

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
    /* @brief Add FRU record entry into table
     *
     * @parm[in]  i_rsid        FRU record set identifier
     * @parm[in]  i_num_tlvs    Number of FRU fields in formatted data
     * @parm[in]  i_fru_tlvs    TLV formatted FRU field data
     * @parm[in]  i_record_type FRU record type
     * @parm[in]  i_encoding    FRU encoding type for FRU fields
     *
     */
    void addFruRecord(const fru_record_set_id_t & i_rsid,
                      const uint8_t i_num_tlvs,
                      fru_data_t & i_fru_tlvs,
                      const uint8_t i_record_type,
                      const uint8_t i_encoding);

    /* @brief Load all the FRU records for a particular target.
     *
     * @note Right now this only loads the location code.
     *
     * @param[in] i_target      The Target to read VPD from
     * @param[in] i_entityType  The entity type of the target
     */
    void loadFruRecords(TARGETING::Target* const i_target,
                        const entity_type i_entityType);

    /* @brief Loads all the FRU records for every DCM.
     *
     * @note DCMs do not have a target, so this is a special case
     */
    void loadFruRecordsForDCMs();

    /* @brief Loads a particular DCM FRU record
     * @note Called by loadFruRecordsForDCMs
     * @param[in] i_proc    The processor target associated with DCM (used for RSID)
     *                      This should be the lowest position processor grouped by location_code
     */
    void loadDcmFruRecord(TARGETING::Target* const i_proc);

    // storage of the full fru record table
    std::vector<uint8_t> iv_fru_record_table_bytes;

    // current bytes used in iv_fru_record_table_bytes
    size_t iv_fru_record_table_used_bytes = 0;

    // total number of fru records in table
    uint16_t iv_num_records = 0;

    // set of unique records in fru record table
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

        TARGETING::TYPE l_target_type = info.targetType;
        if (l_target_type == TYPE_CORE && TARGETING::is_fused_mode())
        {
            l_target_type = TYPE_FC;
        }

        getClassResources(targets,
                          info.targetClass,
                          l_target_type,
                          UTIL_FILTER_PRESENT);

        for (const auto target : targets)
        {
            loadFruRecords(target, info.entityType);
        }
    }

    loadFruRecordsForDCMs();

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
        ATTR_STATIC_ABS_LOCATION_CODE_type abs_location_code { };

        // this is here to help notify future developers of a possible size conflict
        // encodeTlv() has an assert to check against real size being passed in for location code
        static_assert(sizeof(abs_location_code) <= UINT8_MAX,
                      "Location code too large to encode in a FRU TLV");

        assert(UTIL::tryGetAttributeInHierarchy<ATTR_STATIC_ABS_LOCATION_CODE>(i_target, abs_location_code),
            "Cannot get ATTR_STATIC_ABS_LOCATION_CODE from HUID = 0x%08x", get_huid(i_target));

        // location code is not null terminated
        full_location_code.insert(end(full_location_code),
                                  abs_location_code, abs_location_code + strlen(abs_location_code));
    }

    /* Encode the TLV */

    const int location_code_key = PLDM_OEM_FRU_FIELD_TYPE_LOCATION_CODE;

    encodeTlv(location_code_key,
              full_location_code.size(),
              full_location_code.data(),
              o_fru_data);
}

/* @brief Reads the MRU_ID from a target and encodes it as in TLV format.
 *
 * @param[in] i_target        The target to grab MRU_ID from
 * @param[in] i_field_type    The pldm field type
 * @param[out] o_fru_data     The vector to fill with FRU TLVs
 * @return true if tlv added, else false
 */
bool read_mru_id_tlv( Target* const i_target,
                      const uint8_t i_field_type,
                      fru_data_t& o_fru_data )
{
    bool l_mru_id_added = false;
    uint32_t l_mru_id = 0xbaaddead;

    // Only add for targets that have MRU_ID attribute
    if (i_target->tryGetAttr<ATTR_MRU_ID>(l_mru_id))
    {
        /* Encode the TLV */
        char asciiMruId[11] = {0};
        snprintf(asciiMruId, sizeof(asciiMruId), "0x%08X", l_mru_id);
        encodeTlv(i_field_type,
                  strnlen(asciiMruId, sizeof(asciiMruId)-1),
                  asciiMruId,
                  o_fru_data);
        l_mru_id_added = true;
    }
    else
    {
        PLDM_DBG("Skipping read_mru_id_tlv(0x%08X, 0x%02X) because ATTR_MRU_ID isn't defined for ATTR_TYPE %s",
            get_huid(i_target), i_field_type, attrToString<ATTR_TYPE>(i_target->getAttr<ATTR_TYPE>()));
    }
    return l_mru_id_added;
}

/* @brief Reads the Serial number from a target and encodes it in TLV format.
 *
 * @param[in] i_target        The target to grab serial number from
 * @param[in] i_field_type    The pldm field type
 * @param[out] o_fru_data     The vector to fill with FRU TLVs
 */
void read_serial_tlv( Target* const i_target,
                      const uint8_t i_field_type,
                      fru_data_t& o_fru_data )
{
    ATTR_SERIAL_NUMBER_type serial_number = { };
    static_assert(sizeof(serial_number) <= UINT8_MAX,
            "Serial number too large to encode in a FRU TLV");

    assert(i_target->tryGetAttr<ATTR_SERIAL_NUMBER>(serial_number),
               "Cannot get ATTR_SERIAL_NUMBER from target 0x%08x",
               get_huid(i_target));

    /* Encode the TLV */
    encodeTlv(i_field_type,
              strnlen(reinterpret_cast<char*>(serial_number), sizeof(serial_number)),
              serial_number,
              o_fru_data);
}


void FruRecordTable::addFruRecord(const fru_record_set_id_t & i_rsid,
                                  const uint8_t i_num_tlvs,
                                  fru_data_t & i_fru_tlvs,
                                  const uint8_t i_record_type,
                                  const uint8_t i_encoding)
{
    /* Reserve space in the record table */
    const size_t record_hdr_size =
        (sizeof(struct pldm_fru_record_data_format)
         - sizeof(struct pldm_fru_record_tlv));

    iv_fru_record_table_bytes.resize(iv_fru_record_table_used_bytes
                                     + record_hdr_size
                                     + i_fru_tlvs.size());

    /* Encode the record in the table */
    const int encode_rc = encode_fru_record(iv_fru_record_table_bytes.data(),
                                    iv_fru_record_table_bytes.size(),
                                    &iv_fru_record_table_used_bytes,
                                    i_rsid,
                                    i_record_type,
                                    i_num_tlvs,
                                    i_encoding,
                                    i_fru_tlvs.data(),
                                    i_fru_tlvs.size());

    assert(encode_rc == PLDM_SUCCESS,
           "encode_fru_record record RSID: 0x%04X, record type %x, encoding %x failed with rc = %d",
           i_rsid, i_record_type, i_encoding, encode_rc);

    /* Adjust bookkeeping numbers */
    // NOTE: iv_fru_record_table_used_bytes is updated via encode_fru_record()
    ++iv_num_records;
    iv_record_sets[i_rsid] = true;
}

void FruRecordTable::loadDcmFruRecord(TARGETING::Target* const i_proc)
{
    PLDM_INF("Loading FRU record for DCM associated with proc 0x%08x", get_huid(i_proc));

    const fru_record_set_id_t rsid = getTargetFruRecordSetID(i_proc, TYPE_DCM);

    /* Read the target's serial number, encoded as a TLV */
    fru_data_t fru_tlvs;
    read_serial_tlv(i_proc, PLDM_FRU_FIELD_TYPE_SN, fru_tlvs);
    const uint8_t num_tlvs = 1;

    addFruRecord(rsid, num_tlvs, fru_tlvs, PLDM_FRU_RECORD_TYPE_GENERAL, PLDM_FRU_ENCODING_ASCII);
}

void FruRecordTable::loadFruRecordsForDCMs()
{
    PLDM_INF("Loading DCM FRU records...");

    struct cmp_str
    {
       // note: vectors contain strings (null-terminated)
       bool operator()(std::vector<char> a, std::vector<char> b) const
       {
            return strcmp(a.data(), b.data()) > 0;
       }
    };
    // using vector for memory cleanup
    std::map<std::vector<char>, TARGETING::Target*, cmp_str> l_dcmLocationMap;

    TargetHandleList procTargets;
    getClassResources(procTargets,
                      CLASS_CHIP,
                      TYPE_PROC,
                      UTIL_FILTER_PRESENT);

    std::sort(begin(procTargets), end(procTargets),
              [](const Target* const t1, const Target* const t2) {
                  return t1->getAttr<ATTR_POSITION>() < t2->getAttr<ATTR_POSITION>();
              });

    // figure out what processors are associated with DCMs
    for (const auto & l_procTarget : procTargets)
    {
        ATTR_STATIC_ABS_LOCATION_CODE_type abs_location_code { };
        assert(UTIL::tryGetAttributeInHierarchy<ATTR_STATIC_ABS_LOCATION_CODE>(l_procTarget, abs_location_code),
                "Cannot get ATTR_STATIC_ABS_LOCATION_CODE from PROC HUID = 0x%08x", get_huid(l_procTarget));
        std::vector<char> vLocationStr(abs_location_code, abs_location_code + std::size(abs_location_code));
        auto it = l_dcmLocationMap.find(vLocationStr);
        if (it == l_dcmLocationMap.end())
        {
            // no DCM yet for this processor
            loadDcmFruRecord(l_procTarget);
            l_dcmLocationMap[vLocationStr] = l_procTarget;
        }
    }
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

    /* Encode the record in the table */

    // location code
    const uint8_t num_tlvs = 1;
    addFruRecord(rsid, num_tlvs, fru_tlvs, PLDM_FRU_RECORD_TYPE_OEM, PLDM_FRU_ENCODING_ASCII);

    // add the MRU_ID to the SN field for a general record if allowed
    fru_tlvs.clear();

    /* Read the target's mru_id, encoded as a TLV */
    /* Adds the mru_id to fru_tlvs if mru_id exists on target */
    bool mruid_added = read_mru_id_tlv(i_target, PLDM_FRU_FIELD_TYPE_SN, fru_tlvs);
    if (mruid_added)
    {
        addFruRecord(rsid, num_tlvs, fru_tlvs, PLDM_FRU_RECORD_TYPE_GENERAL, PLDM_FRU_ENCODING_ASCII);
    }
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
