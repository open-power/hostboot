/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/extended/hb_fru.C $                              */
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

/**
 *  @file hb_fru.C
 *  @brief Source code of utility functions that manipulate PLDM
 *         fru record table info
 */

#include <util/align.H>
#include <cstdlib>
#include <map>
#include <memory>
#include <string.h>
#include <pldm/extended/hb_fru.H>
#include "../common/pldmtrace.H"
#include "../extern/fru.h"
#include "pldm_fru_to_ipz_mapping.H"
// From pldm include dir
#include <pldm/pldm_errl.H>
#include <pldm/pldm_reasoncodes.H>
#include <pldm/extended/pdr_manager.H>
#include <pldm/requests/pldm_fru_requests.H>
#include <vpd/ipz_vpd_consts.H>
#include <eeprom/eepromif.H>
#include <eeprom/eeprom_const.H>
#include <targeting/common/target.H>

using namespace ERRORLOG;

namespace PLDM
{

// Create a map of valid record/keyword combinations that can be used to
// convert PLDM Fru Record Field Type Numbers to IPZ Keywords.
// The doc describing this is titled "PLDM_FRU_IPZ_Keyword_Mapping"
const std::map<uint32_t, std::vector<uint16_t> > record_keyword_field_map {
  { VINI, { std::begin(valid_vini_keywords), std::end(valid_vini_keywords) } },
  { VSYS, { std::begin(valid_vsys_keywords), std::end(valid_vsys_keywords) } },
  { LXR0, { std::begin(valid_lxr0_keywords), std::end(valid_lxr0_keywords) } },
};

/**
 *  @brief Given a complete fru record table's set of records, filter the
 *        set of records for a given record set id / record type.
 *        See https://www.dmtf.org/standards/pmci for references
 *
 * @param[in] i_pldm_fru_table_buf  Pointer to a buffer which contains all of
 *                                  Fru Records related to an Entity's Record
 *                                  Set ID
 * @param[in] i_record_count        Number of records in the fru record table
 * @param[in] o_location_code       Null-terminated string containing the
 *                                  location code associated with this
 *                                  Record Set ID
 *
 * @return returns error log if error occurs, otherwise returns nullptr
 */
errlHndl_t getRecordSetLocationCode(const uint8_t* const i_pldm_fru_table_buf,
                                    const uint16_t i_record_count,
                                    std::vector<uint8_t>& o_location_code)
{
    assert( i_pldm_fru_table_buf != nullptr,
            "printFruRecordTable: i_pldm_fru_table_buf is a nullptr!");
    // copy the pointer provided by the caller into
    // a local variable so we can do some ptr arithmetic
    // on it without messing up the caller
  errlHndl_t errl = nullptr;
  const uint8_t * in_table_cur_ptr =
        const_cast<const uint8_t*>(i_pldm_fru_table_buf);

  o_location_code.clear();

  for(uint16_t i = 0; i < i_record_count; i++)
  {
      const pldm_fru_record_data_format *record_data =
          reinterpret_cast<const pldm_fru_record_data_format *>(in_table_cur_ptr);

      size_t offset_of_cur_pldm_record_entry = offsetof(pldm_fru_record_data_format, tlvs);

      for(uint8_t j = 0; j < record_data->num_fru_fields; j++)
      {
          const pldm_fru_record_tlv *fru_tlv =
              reinterpret_cast<const pldm_fru_record_tlv *>(in_table_cur_ptr +
                                                            offset_of_cur_pldm_record_entry);
          // Location code is a record with a single TLV that has the location code
          // associated with the record set id
          constexpr uint8_t LOCATION_CODE_FIELD_ID = 254;

          if(fru_tlv->type == LOCATION_CODE_FIELD_ID)
          {
              const uint8_t * location_val_ptr = in_table_cur_ptr +
                                                 offset_of_cur_pldm_record_entry +
                                                 offsetof(pldm_fru_record_tlv, value);

              o_location_code.insert(o_location_code.begin(),
                                     location_val_ptr,
                                     location_val_ptr + fru_tlv->length);

              // PLDM FRU Record Fields of type string are not null terminated
              // (see DSP0257 1.0.0 section 7.4)
              o_location_code.push_back('\0');

              // if we found the location code we can break out
              break;
          }

          offset_of_cur_pldm_record_entry  += (offsetof(pldm_fru_record_tlv, value) +
                                              fru_tlv->length);
      }

      // if we found the location code we can break out
      if(o_location_code.size()) { break; }

      // otherwise move to the next record in hopes of finding the location code
      in_table_cur_ptr += offset_of_cur_pldm_record_entry;
  }

  if(o_location_code.empty())
  {
      const pldm_fru_record_data_format *record_data =
          reinterpret_cast<const pldm_fru_record_data_format *>(in_table_cur_ptr);
      PLDM_ERR("getRecordSetLocationCode: failed to find location code in"
               "records associated with RSI 0x%04x",
               record_data->record_set_id);

      /*
      * @errortype  ERRL_SEV_UNRECOVERABLE
      * @moduleid   MOD_GET_LOCATION_CODE
      * @reasoncode RC_INVALID_LENGTH
      * @userdata1  record set id of record set passed by called
      * @userdata2  unused
      * @devdesc    Unable to find the location code in the record
      *             set provided by caller
      * @custdesc   A software error occurred during system boot
      */
      errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                              MOD_GET_LOCATION_CODE,
                              RC_INVALID_LENGTH,
                              record_data->record_set_id,
                              0,
                              ERRORLOG::ErrlEntry::NO_SW_CALLOUT);
      addBmcErrorCallouts(errl);
  }

  return errl;
}

/**
 *  @brief Given a complete fru record table's set of records, filter the
 *        set of records for a given record set id / record type.
 *        See https://www.dmtf.org/standards/pmci for references
 *
 * @param[in] i_pldm_fru_table_buf  Pointer to a buffer which contains data
 *                                  defined in Table 7 of DSP0257 v1.0.0
 * @param[in] i_record_count        Number of records in the fru record table
 * @param[in] i_record_set_id       The record set id we would like the records
 *                                  returned to have
 * @param[in] i_record_type         The record type we would like the records
 *                                  returned to have
 * @param[out] o_pldm_fru_table_buf Byte vector which will be filled in with the
 *                                  filtered out pldmn fru records we want. The
 *                                  vector passed in is cleared at func start.
 *                                  Note: this will not contain the Pad or
 *                                  FRUDataStructureIntegrityChecksum defined in
 *                                  DSP0257
 * @param[out] o_records_in_output_table Number of records contained in
 *                                       o_pldm_fru_table_buf
 *
 * @note If no records matching i_recordSetId and i_recordType are found then
 *       o_records_in_output_table will return 0 and o_pldm_fru_table_buf.size()
 *       will be 0
 *
 * @return void
 */
void getRecordSetByIdAndType(const uint8_t* const i_pldm_fru_table_buf,
                             const uint16_t i_record_count,
                             const uint16_t i_record_set_id,
                             const uint8_t  i_record_type,
                             std::vector<uint8_t>& o_pldm_fru_table_buf,
                             uint16_t & o_records_in_output_table)
{
  PLDM_ENTER("getRecordSetByIdAndType: o_pldm_fru_table_buf = %p  i_record_set_id = 0x%x  i_record_type = 0x%x",
             o_pldm_fru_table_buf,
             i_record_set_id,
             i_record_type);

  assert( i_pldm_fru_table_buf != nullptr,
        "getRecordSetByIdAndType: i_pldm_fru_table_buf is a nullptr!");

  o_pldm_fru_table_buf.clear();

  // copy the pointers provided by the caller into
  // local variables so we can do some ptr arithmetic
  // on them without messing up the caller
  const uint8_t * in_table_cur_ptr =
        const_cast<const uint8_t*>(i_pldm_fru_table_buf);

  o_records_in_output_table = 0;

  // Loop through all of the records looking for the ones that match
  // i_record_set_id, and i_record_type
  for( uint16_t i = 0; i < i_record_count; i++)
  {
      const pldm_fru_record_data_format *record_data =
        reinterpret_cast<const pldm_fru_record_data_format *>(in_table_cur_ptr);

      // We need to keep a running total of the size of the record as we process
      // the entries in the record because the size of each entry is variable.
      // Start the record size count at the offset at of the TLVs.
      // (TLV == Type, Length, Value .. see fru.h for details)
      size_t record_size = offsetof(pldm_fru_record_data_format, tlvs);

      // Iterate through the TLVs contained in this record, read the
      // length from each TLV and add it to the record_size along with
      // the size of the T and L (type and length) of the TLV struct.
      for( uint8_t j = 0; j < record_data->num_fru_fields; j++)
      {
          const pldm_fru_record_tlv *fru_tlv =
              reinterpret_cast<const pldm_fru_record_tlv *>(in_table_cur_ptr +
                                                            record_size);
          record_size  += (offsetof(pldm_fru_record_tlv, value) +
                           fru_tlv->length);
      }

      // Only copy records into out_table_cur_ptr if they match the
      // record set id and type we desire
      if(le16toh(record_data->record_set_id) == i_record_set_id &&
         record_data->record_type == i_record_type )
      {
          o_pldm_fru_table_buf.insert(o_pldm_fru_table_buf.end(),
                                      in_table_cur_ptr,
                                      in_table_cur_ptr + record_size);
          o_records_in_output_table++;
      }

      // increment local ptr to input fru table by record size
      // so we are ready to process the next record
      in_table_cur_ptr += record_size;
  }
  PLDM_EXIT("getRecordSetByIdAndType: records found: %d  buffer length  0x%llx",
            o_records_in_output_table, o_pldm_fru_table_buf.size());
}

/**
* @brief Build up a vector of pt_entry objects by iterating on
*        a vector of byte vectors containing IPZ records.
*
* @param[in]  i_ipz_records  Vector of byte vectors where each byte vector
*                            contains a IPZ formated VPD Record.
* @param[in]  i_vtoc_length  Total length of the VTOC record, needed for
                             calcuating record offsets.
* @param[out] o_pt_entries  Vector of pt_entry structs which will be
*                            cleared at the start of this function and
*                            filled in as we process the ipz_records
*
* @return returns error log if error occurs, otherwise returns nullptr
*/
errlHndl_t generate_pt_entries(const std::vector<std::vector<uint8_t>>& i_ipz_records,
                               const size_t i_vtoc_length,
                               std::vector<pt_entry>& o_pt_entries)
{
  errlHndl_t errl = nullptr;

  o_pt_entries.clear();

  // While building the table of contents we need to know the offset
  // of each IPZ record. Create a variable that will keep track of our
  // "current" offset in the final IPZ file. This will start after the VHDR
  // and VTOC records, which are always first in IPZ formated data and will
  // be incremented as we iterate throught the ipz_records.
  size_t ipz_record_offset = sizeof(vhdr_record) + i_vtoc_length;

  for(auto ipz_record : i_ipz_records)
  {
      standard_ipz_record_hdr * record_hdr_ptr =
        reinterpret_cast<standard_ipz_record_hdr *>(ipz_record.data());

      if(ipz_record.size() < sizeof(standard_ipz_record_hdr))
      {
          PLDM_ERR("generate_pt_entries:: IPZ record size is 0x%x bytes when we expect at least 0x%x bytes",
                   ipz_record.size(),
                   sizeof(standard_ipz_record_hdr));
          /*
          * @errortype  ERRL_SEV_UNRECOVERABLE
          * @moduleid   MOD_GENERATE_PT_ENTRIES
          * @reasoncode RC_INVALID_LENGTH
          * @userdata1  Expected Size
          * @userdata2  Actual Size
          * @devdesc    Software problem during fru record table translation
          * @custdesc   A software error occurred during system boot
          */
          errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                               MOD_GENERATE_PT_ENTRIES,
                               RC_INVALID_LENGTH,
                               sizeof(standard_ipz_record_hdr),
                               ipz_record.size(),
                               ErrlEntry::ADD_SW_CALLOUT);
          // Hostboot should have caught a problem sooner but the problem
          // could have originated from the BMC
          errl->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                      HWAS::SRCI_PRIORITY_MED);
          break;
      }

      if(record_hdr_ptr->rt_kw_name != ASCII_RT)
      {
          PLDM_ERR("generate_pt_entries:: IPZ record is not in the format we expect. Could not find RT keyword");
          /*
          * @errortype  ERRL_SEV_UNRECOVERABLE
          * @moduleid   MOD_GENERATE_PT_ENTRIES
          * @reasoncode RC_INVALID_IPZ_FORMAT
          * @userdata1  Bytes 0:7 of ipz_record
          * @userdata2  IPZ record size
          * @devdesc    Software problem during fru record table translation
          * @custdesc   A software error occurred during system boot
          */
          errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                               MOD_GENERATE_PT_ENTRIES,
                               RC_INVALID_IPZ_FORMAT,
                               *reinterpret_cast<uint64_t *>(
                                                       ipz_record.data()),
                               ipz_record.size(),
                               ErrlEntry::ADD_SW_CALLOUT);
          // Hostboot should have caught a problem sooner but the problem
          // could have originated from the BMC
          errl->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                    HWAS::SRCI_PRIORITY_MED);
          break;
      }

      pt_entry cur_entry = { };


      // Copy the value of the RT keyword into the pt_entry.record_name
      memcpy(&cur_entry.record_name,
             &record_hdr_ptr->rt_kw_val,
             sizeof(record_hdr_ptr->rt_kw_val));

      cur_entry.record_length = htole16(ipz_record.size());
      cur_entry.record_offset = htole16(ipz_record_offset);

      // increment our "current" ipz_record_offset ptr by this records size
      // (see above for more details)
      ipz_record_offset += ipz_record.size();

      o_pt_entries.push_back(cur_entry);
  }

  if(errl)
  {
      PLDM_ERR("generate_pt_entries:: returning with error after generating %d pt entries",
               o_pt_entries.size());
  }

  return errl;
}

/**
* @brief Fully populate a byte vector with an IPZ-styled VTOC Record
*
* @param[out]    o_vtoc_buf      Byte vector that will be filled with a fully populated
*                                VTOC record
* @param[in]     i_ipz_records   A vector of byte vectors. Each byte vector contains
*                                a fully populated IPZ record.
* @param[in]     i_pad_bytes     Number of pad bytes we need to add in the PF keyword
*
* See Common VPD Architecture document for details (search "VPD Table Of Contents")
*
* @return returns error log if error occurs, otherwise returns nullptr
*/
//     ==============================================================================
//                                V T O C  (EXAMPLE)
//     ==============================================================================
//     Field             Size  Content                                         Format
//     ==============================================================================
//     Large Resource       1  '84'x                                           Hex
//     -----------------------------------------------------------------------------
//     Record Length        2  '3800'x  (=56, little endian)                   Hex
//     -----------------------------------------------------------------------------
//     Keyword              2  "RT"                             Record Name
//     Length               1  '04'x  (=4)
//     Data                 4  "VTOC"                                          ASCII
//     -----------------------------------------------------------------------------
//     Keyword              2  "PT"                       Table of Contents
//     Length               1  '2A'x  (=42)
//     Data                 4  "VINI"                                          ASCII
//                          2  '????'x  (Record Type, little endian)           Hex
//                          2  '????'x  (Record Offset, little endian)         Hex
//                          2  '????'x  (Record Length, little endian)         Hex
//                          2  '????'x  (ECC Offset, little endian)            Hex
//                          2  '????'x  (ECC Length, little endian)            Hex
//                          4  "VMSC"                                          ASCII
//                          2  '????'x  (Record Type, little endian)           Hex
//                          2  '????'x  (Record Offset, little endian)         Hex
//                          2  '????'x  (Record Length, little endian)         Hex
//                          2  '????'x  (ECC Offset, little endian)            Hex
//                          2  '????'x  (ECC Length, little endian)            Hex
//                          4  "VRTN"                                          ASCII
//                          2  '????'x  (Record Type, little endian)           Hex
//                          2  '????'x  (Record Offset, little endian)         Hex
//                          2  '????'x  (Record Length, little endian)         Hex
//                          2  '????'x  (ECC Offset, little endian)            Hex
//                          2  '????'x  (ECC Length, little endian)            Hex
//     -----------------------------------------------------------------------------
//     Keyword              2  "PF"                                Pad Fill
//     Length               1  '01'x  (=1) (calculated by VPD tool, may vary)
//     Data                 1  '00'x                                           Hex
//     -----------------------------------------------------------------------------
//     Small Resource       1  '78'x                                           Hex
//     ==============================================================================
//     Total Byte Count: 60*
//     ==============================================================================
errlHndl_t generate_vtoc_record(std::vector<uint8_t>& o_vtoc_buf,
                                const std::vector<std::vector<uint8_t>>& i_ipz_records,
                                const uint8_t i_pad_bytes)
{
    PLDM_ENTER("generate_vtoc_record");
    errlHndl_t errl = nullptr;
    do{

    if( (sizeof(pt_entry)*i_ipz_records.size()) > UINT8_MAX ||
        i_ipz_records.size() == 0 )
    {
        PLDM_ERR("generate_vtoc_record:: estimated PT kw size 0x%x will exceed max size for a pt keyword, or is 0 and is invalid",
                 sizeof(pt_entry)*i_ipz_records.size());
        /*
        * @errortype  ERRL_SEV_UNRECOVERABLE
        * @moduleid   MOD_GENERATE_VTOC_RECORD
        * @reasoncode RC_INVALID_LENGTH
        * @userdata1  Estimated size of the PT entry
        * @userdata2  unused
        * @devdesc    Software problem, unable to translate PLDM
        *             Fru Table from BMC to IPZ format
        * @custdesc   A software error occurred during system boot
        */
        errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                             MOD_GENERATE_VTOC_RECORD,
                             RC_INVALID_LENGTH,
                             sizeof(pt_entry)*i_ipz_records.size(),
                             0,
                             ErrlEntry::NO_SW_CALLOUT);
        addBmcErrorCallouts(errl);
        break;
    }

    uint8_t pt_kw_len = (sizeof(pt_entry)*i_ipz_records.size());


    // This structure represents the start of the vtoc record up to but not
    // including the value of its pt keyword.
    struct vtoc_first_part
    {
      uint8_t  vtoc_rec_start = VPD_RECORD_START_MAGIC_NUM;
      uint16_t vtoc_rec_len;            // variable
      uint16_t rt_kw_name = 0x5254;     // ascii "RT"
      uint8_t  rt_kw_len  = 0x04;       // always 4 bytes
      uint32_t rt_kw_val  = 0x56544F43; // ascii "VTOC"
      uint16_t pt_kw_name = 0x5054;     // ascii "PT"
      uint8_t  pt_kw_len;               // variable

      vtoc_first_part(uint16_t vtoc_len, uint8_t pt_len) {
        vtoc_rec_len = htole16(vtoc_len);
        pt_kw_len = pt_len;
      }
    } PACKED;

    // Note: this vtoc_len DOES NOT include the Large/Small Resources,
    // nor the Record Size fields
    uint16_t vtoc_len = offsetof(vtoc_first_part, pt_kw_len) +
                        pt_kw_len +              // (see above)
                        KEYWORD_BYTE_SIZE +      // 2 bytes ('PF')
                        KEYWORD_SIZE_BYTE_SIZE + // 2 bytes (variable);
                        i_pad_bytes;

    // subtract off the parts of the struct that are not included  in the 
    // vtoc record length field
    vtoc_len = vtoc_len -
             sizeof(((vtoc_first_part *)0)->vtoc_rec_start) - // large resource
             sizeof(((vtoc_first_part *)0)->vtoc_rec_len);    // record size bytes
    // make sure the vector the called passed us is empty
    o_vtoc_buf.clear();

    // resize the vtoc buffer to the actual size the buffer will be
    // including the Large/Small Resources and the Record Size fields
    o_vtoc_buf.resize(vtoc_len +
                      (RESOURCE_ID_SIZE * 2) + // Large/Small Resources
                      RECORD_SIZE_BYTE_SIZE,   // Record Size fields
                      0);


    // create a struct to help fill in everything in a vtoc record
    // up to (but not including) the value of its pt keyword
    auto vtoc_start_ptr =
              reinterpret_cast<vtoc_first_part*>(o_vtoc_buf.data());
    *vtoc_start_ptr = vtoc_first_part(vtoc_len, pt_kw_len);

    std::vector<pt_entry> pt_entries;
    errl = generate_pt_entries(i_ipz_records, o_vtoc_buf.size(), pt_entries);

    if(errl)
    {
        PLDM_ERR("generate_vtoc_record: error occurred during generate_pt_entries, see error for details");
        break;
    }

    assert(pt_kw_len == (pt_entries.size() * sizeof(pt_entries[0])),
          "generate_vtoc_record: the len of the pt kw we calculated %u did not match the size of the pt kw we generated %ull",
           pt_kw_len,
           (pt_entries.size() * sizeof(pt_entries[0])));

    // copy the pt keyword data we generated after the vtoc_first_part struct
    memcpy(reinterpret_cast<void*>(&o_vtoc_buf.at(sizeof(vtoc_first_part))),
           reinterpret_cast<const void*>(pt_entries.data()),
           pt_kw_len);

    // We must fill in the PF keyword which comes after the PT keyword.
    // The PF kw is the padding keyword -- the idea is to allow for some
    // variable amount of bytes to ensure we get the VTOC record 4 byte aligned
    size_t pf_kw_offset = sizeof(vtoc_first_part) + pt_kw_len;

    o_vtoc_buf[pf_kw_offset]   = 0x50; // ascii "P"
    o_vtoc_buf[pf_kw_offset+1] = 0x46; // ascii "F"
    o_vtoc_buf[pf_kw_offset+2] = i_pad_bytes;
    // pad bytes already accounted for and set to 0 by vector resize above

    // write the magic number that signifies the end of the record
    auto vtoc_rec_end = &o_vtoc_buf.back();
    *vtoc_rec_end = VPD_RECORD_END_MAGIC_NUM;

    }while(0);

    PLDM_EXIT("generate_vtoc_record");

    return errl;
}

/**
* @brief Fully populate a byte vector with an IPZ-styled VHDR Record
*
* @param[out] o_vhdr_buf      Byte vector that will be filled with a fully
*                             populated VHDR record. Note that any elements
*                             of the vector that get passed in are cleared.
* @param[in]  i_vtoc_len      The length of the VTOC record that will follow
*                             this VHDR record.
*
* See Common VPD Architecture document for details (search "VPD Header")
*
* @return void
*/
void generate_vhdr_record(std::vector<uint8_t>& o_vhdr_buf,
                       const uint8_t i_vtoc_len)
{
    PLDM_ENTER("generate_vhdr_record");

    // setup the vector to the appropriate size for a VHDR record
    o_vhdr_buf.clear();
    o_vhdr_buf.resize(sizeof(vhdr_record));

    // Use the specialized vhdr_record struct ctor to fill in the first
    // sizeof(vhdr_record) bytes of o_ipz_vpd_buf
    auto vhdr_ptr = reinterpret_cast<vhdr_record*>(o_vhdr_buf.data());
    *vhdr_ptr = vhdr_record(i_vtoc_len);
    PLDM_EXIT("generate_vhdr_record");
}

/**
* @brief Parse through a pointer containing a PLDM-styled Fru Record Table
*        and convert each PLDM Fru record into a fully populated IPZ-styled
*        record.
*
* @param[in]     i_pldm_fru_table_buf    Ptr to PLDM-styled FRU record table
*                                        that contains OEM type Fru Records.
* @param[in]     i_pldm_fru_record_count Number of records in
*                                        i_pldm_fru_table_buf
* @param[out]    o_ipz_records           Vector of byte vectors where each
*                                        byte vector will contain a fully
*                                        populated IPZ-style record. Note
*                                        that any elements the vector that
*                                        gets passed in are cleared.
*
* See Common VPD Architecture document for details
*
* @return returns error log if error occurs, otherwise returns nullptr
*/
errlHndl_t generate_ipz_formatted_vpd(const uint8_t* const i_pldm_fru_table_buf,
                                      const uint16_t i_pldm_fru_record_count,
                                      std::vector<std::vector<uint8_t>>& o_ipz_records)
{
    PLDM_ENTER("generate_ipz_formatted_vpd i_pldm_fru_table_buf = %p  i_pldm_fru_record_count = %d",
               i_pldm_fru_table_buf,
               i_pldm_fru_record_count);

    assert(i_pldm_fru_table_buf != nullptr,
           "generate_ipz_formatted_vpd passed a nullptr");
    errlHndl_t errl = nullptr;
    // We will be iterating through the input pldm_record buffer we were
    // passed in. To avoid messing up the caller's ptr create a local copy
    // of the ptr to do ptr math on.
    const uint8_t * cur_pldm_rec_ptr =
          const_cast<const uint8_t*>(i_pldm_fru_table_buf);

    o_ipz_records.clear();

    // Loop through all of the pldm records in i_pldm_fru_table_buf.
    // On each loop, translate the pldm fru record into IPZ format and copy
    // it to the output buffer
    for( uint16_t i = 0; i < i_pldm_fru_record_count; i++)
    {
        const pldm_fru_record_data_format *record_data =
            reinterpret_cast<const pldm_fru_record_data_format *>(cur_pldm_rec_ptr);

        if(record_data->record_type != PLDM_FRU_RECORD_TYPE_OEM)
        {
            PLDM_ERR("generate_ipz_formatted_vpd: cannot process non-oem type 0x%02x in pldmFruRecordSetToIPZ. "
                     "Note: this is also a sanity check, this will be the first fail we hit if contents of"
                     " i_pldm_fru_table_buf is junk.", record_data->record_type);
            /*
            * @errortype  ERRL_SEV_UNRECOVERABLE
            * @moduleid   MOD_PLDM_FRU_TO_IPZ
            * @reasoncode RC_UNSUPPORTED_TYPE
            * @userdata1[0:15]  Record set ID of current record "i"
            * @userdata1[16:31] Record type of current record "i"
            * @userdata2  unused
            * @devdesc    Software problem, failed to encode PLDM message
            * @custdesc   A software error occurred during system boot
            */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                   MOD_PLDM_FRU_TO_IPZ,
                                   RC_UNSUPPORTED_TYPE,
                                   TWO_UINT16_TO_UINT32(
                                      record_data->record_set_id,
                                      TO_UINT16(record_data->record_type)),
                                   0,
                                   ErrlEntry::ADD_SW_CALLOUT);
            errl->collectTrace(PLDM_COMP_NAME);
            break;
        }

        // We must keep a running total of the size of the record as we process
        // the entries because the size of each entry is variable.
        // Start the record size count at the offset at of the TLVs.
        // (TLV == Type, Length, Value .. see fru.h for details)
        size_t offset_of_cur_pldm_record_entry = offsetof(pldm_fru_record_data_format, tlvs);

        // Start filling the in vpd record data by writing the
        // VPD_RECORD_START_MAGIC_NUM and leaving 2 bytes for the size
        // to be written after the entries have been processed
        std::vector<uint8_t> record_bytes{VPD_RECORD_START_MAGIC_NUM, 0x00, 0x00};

        // we are not sure yet if the PLDM Fru record contains IPZ data or not
        // so for now be safe and assume its not IPZ data
        bool is_ipz_record = false;

        uint32_t record_name = 0;

        // Walk through the TLVs in this PLDM Fru Record
        // NOTE: as we iterate through the TLVs below offset_of_cur_pldm_record_entry can be
        //       viewed as the offset of the current TLV from the start of the
        //       PLDM Fru Record
        for(uint8_t j = 0; j < record_data->num_fru_fields; j++)
        {
            const pldm_fru_record_tlv *fru_tlv =
                reinterpret_cast<const pldm_fru_record_tlv *>(cur_pldm_rec_ptr +
                                                              offset_of_cur_pldm_record_entry);

            // Following value is from the PLDM_FRU_IPZ_Keyword_Mapping doc
            // RT keyword is first TLV for IPZ records
            constexpr uint8_t RT_KEYWORD_FIELD_ID = 2;
            // The RT keyword mapping is the same for each IPZ VPD record.
            // The RT keyword tells us what the IPZ VPD record is.
            // We need to keep track of the RT keyword's value so we know
            // what the other fru record entry's FIELD_IDs represent
            if(fru_tlv->type == RT_KEYWORD_FIELD_ID)
            {
                assert(RECORD_BYTE_SIZE == fru_tlv->length,
                       "generate_ipz_formatted_vpd: unexepcted field length 0x%.02x or RT keyword",
                       fru_tlv->length);
                record_name = *reinterpret_cast<const uint32_t *>(fru_tlv->value);
                is_ipz_record = true;
                PLDM_INF("generate_ipz_formatted_vpd: found record 0x%.08x", record_name);
            }


            bool is_known_ipz_record = (record_keyword_field_map.find(record_name) !=
                     record_keyword_field_map.end());

            // If we do not find RT_KEYWORD_FIELD_ID to be the first entry in
            // a given fru record, then it is safe to assume that this record
            // does not represent IPZ VPD data
            if( is_known_ipz_record )
            {
                std::vector<uint16_t> record_keywords = record_keyword_field_map.at(record_name);

                if(fru_tlv->type < RT_FIELD_TYPE ||
                   fru_tlv->type >= record_keywords.size())
                {
                    PLDM_ERR("generate_ipz_formatted_vpd: Unsupported PLDM Fru Record Field Type %u for record 0x%04x found",
                             fru_tlv->type, record_name)
                    /*
                    * @errortype  ERRL_SEV_UNRECOVERABLE
                    * @moduleid   MOD_PLDM_FRU_TO_IPZ
                    * @reasoncode RC_UNSUPPORTED_FIELD
                    * @userdata1  record name (ascii)
                    * @userdata2  PLDM Fru field type
                    * @devdesc    BMC sent fru info host does not understand
                    * @custdesc   A software error occurred during system boot
                    */
                    errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                         MOD_PLDM_FRU_TO_IPZ,
                                         RC_UNSUPPORTED_FIELD,
                                         record_name,
                                         fru_tlv->type,
                                         ErrlEntry::NO_SW_CALLOUT);
                    addBmcErrorCallouts(errl);
                    break;
                }

                auto keyword_name_ptr =
                      reinterpret_cast<uint8_t *>(&record_keywords[fru_tlv->type]);

                PLDM_DBG("generate_ipz_formatted_vpd: found record 0x%.08x  keyword 0x%.04x",
                         record_name,
                         record_keywords[fru_tlv->type]);

                // Add the keyword name, length, and value to the ipz_record
                // we are building
                record_bytes.push_back(*keyword_name_ptr);
                record_bytes.push_back(*(keyword_name_ptr + 1));

                record_bytes.push_back(fru_tlv->length);

                std::copy(fru_tlv->value,
                          fru_tlv->value + fru_tlv->length,
                          back_inserter(record_bytes));
            }

            if(is_ipz_record && !is_known_ipz_record)
            {
                PLDM_INF("BMC sent us the IPZ record 0x%.08x which Hostboot does not know how to process, skipping it");
            }

            // increment the offset_of_cur_pldm_record_entry variable by the total size of
            // this TLV
            offset_of_cur_pldm_record_entry +=  (offsetof(pldm_fru_record_tlv, value) +
                                                fru_tlv->length);
        } // end loop through TLVs

        if(errl)
        {
            break;
        }

        // Increment the cur_pldm_rec_ptr by offset_of_cur_pldm_record_entry
        // now that we have completed processing the TLVs. Do this regardless
        // of whether or not the fru record was IPZ data in order to get to the
        // next pldm fru record if there is one.
        cur_pldm_rec_ptr += offset_of_cur_pldm_record_entry;

        if(is_ipz_record)
        {
            // The last byte in the IPZ record is the END MAGIC NUM 0x78
            record_bytes.push_back(VPD_RECORD_END_MAGIC_NUM);

            // Now that we have the total size of the record we can set
            // the record size ptr
            // NOTE : field is little-endian and we don't include the size of
            // the resource ids (2 bytes) nor the record length (2 bytes)
            // according to the Common VPD specification
            auto record_hdr_ptr =
              reinterpret_cast<standard_ipz_record_hdr *>(record_bytes.data());
            record_hdr_ptr->record_length = htole16(record_bytes.size() -
                                                    (2 * RESOURCE_ID_SIZE) -
                                                    RECORD_SIZE_BYTE_SIZE);

            o_ipz_records.push_back(record_bytes);
        }
    }  // end loop through i_pldm_fru_record_count records

    return errl;
}

/**
 * @brief Convert a serialized fru record set in IPZ style VPD
 *        See https://www.dmtf.org/standards/pmci for references
 *
 * @param[in]  i_pldm_fru_table_buf     Pointer to a buffer which is a series
 *                                      of PLDM fru records of type
 *                                      FRU_RECORD_TYPE_OEM
 *                                      (See Table 2 & 3 of DSP0257 v1.0.0)
 * @param[in]  i_pldm_fru_record_count  Number of records in i_pldm_fru_table_buf
 * @param[out] o_ipz_vpd_buf            Vector which will be populated with a completeIPD VPD translated from
 *                                      the data in i_pldm_fru_table_buf
 *
 * @return returns error log if error occurs, otherwise returns nullptr
 */
errlHndl_t pldmFruRecordSetToIPZ(const uint8_t* const i_pldm_fru_table_buf,
                                 const uint16_t i_pldm_fru_record_count,
                                 std::vector<uint8_t>& o_ipz_vpd_buf)
{
    PLDM_ENTER("pldmFruRecordSetToIPZ: input fru record count %d   i_pldm_fru_table_buf = %p",
               i_pldm_fru_record_count,
               i_pldm_fru_table_buf);
    errlHndl_t errl = nullptr;

    do{
    // ******* IPZ BUFFER LAYOUT *************
    // VHDR record (contains ptr to VTOC)
    // VTOC record (contains table of contents)
    // <PLDM Fru Records from BMC converted to IPZ format>
    // ***************************************

    // first process the input PLDM Fru records and translate them into
    // IPZ formated VPD Records
    std::vector<std::vector<uint8_t>> ipz_records;
    errl = generate_ipz_formatted_vpd(i_pldm_fru_table_buf,
                                      i_pldm_fru_record_count,
                                      ipz_records);
    if(errl)
    {
        PLDM_ERR("pldmFruRecordSetToIPZ: error returned from generate_ipz_formatted_vpd");
        break;
    }

    // vtoc_len is needed for vhdr generation
    // Note: this vtoc_len DOES include the Large/Small Resources,
    // and the Record Length fields, but DOES NOT include
    // the padding byte, which is calculated below.
    // calculations from VTOC layout example above
    size_t vtoc_len = RESOURCE_ID_SIZE +       // 1 byte  (0x84)
                      RECORD_SIZE_BYTE_SIZE +  // 2 bytes (variable)
                      KEYWORD_BYTE_SIZE +      // 2 bytes ('RT')
                      KEYWORD_SIZE_BYTE_SIZE + // 2 bytes (0x04)
                      RECORD_BYTE_SIZE +       // 4 bytes ('VTOC')
                      KEYWORD_BYTE_SIZE +      // 2 bytes ('PT')
                      KEYWORD_SIZE_BYTE_SIZE + // 2 bytes (variable)
                      // 14 bytes/entry * pt entry count
                      (sizeof(pt_entry) * ipz_records.size()) +
                      KEYWORD_BYTE_SIZE +      // 2 bytes ('PF')
                      KEYWORD_SIZE_BYTE_SIZE + // 2 bytes (variable);
                      RESOURCE_ID_SIZE;        // 1 byte  (0x78)

    // VTOC record must be 4 byte aligned, calculate the pad bytes required
    // to make this happen.
    uint8_t vtoc_pad_bytes = ALIGN_4(vtoc_len) - vtoc_len;

    // create a byte vector containing a fully populated VHDR record
    std::vector<uint8_t> vhdr_record_bytes;
    generate_vhdr_record(vhdr_record_bytes,
                         vtoc_len + vtoc_pad_bytes);

    assert(!vhdr_record_bytes.empty(),
           "generated empty vhdr record during pldm fru->ipz translation");

    // create a byte vector containing a fully populated VTOC record
    std::vector<uint8_t> vtoc_record_bytes;
    errl = generate_vtoc_record(vtoc_record_bytes,
                                ipz_records,
                                vtoc_pad_bytes );
    if(errl)
    {
        PLDM_ERR("pldmFruRecordSetToIPZ: error returned from generate_vtoc_record");
        break;
    }

    PLDM_DBG("pldmFruRecordSetToIPZ: start copying generated/translated data into output buffer");

    o_ipz_vpd_buf.clear();

    // copy the VHDR record into the output buffer
    std::copy(vhdr_record_bytes.begin(),
              vhdr_record_bytes.end(),
              back_inserter(o_ipz_vpd_buf));
    PLDM_DBG("pldmFruRecordSetToIPZ: o_ipz_vpd_buf size after copying vhdr record: %d", o_ipz_vpd_buf.size());

    // copy the VTOC record into the output buffer
    std::copy(vtoc_record_bytes.begin(),
              vtoc_record_bytes.end(),
              back_inserter(o_ipz_vpd_buf));
    PLDM_DBG("pldmFruRecordSetToIPZ: o_ipz_vpd_buf size after copying vtoc record: %d", o_ipz_vpd_buf.size());

    // copy the each of the translated IPZ records into the output buffer
    for(size_t i = 0; i < ipz_records.size(); i++)
    {
        std::copy(ipz_records[i].begin(),
                  ipz_records[i].end(),
                  back_inserter(o_ipz_vpd_buf));

        PLDM_DBG("pldmFruRecordSetToIPZ: o_ipz_vpd_buf size after copying ipz record %d : %d",
                 i, o_ipz_vpd_buf.size());
    }

    }while(0);

    PLDM_EXIT("pldmFruRecordSetToIPZ");
    return errl;
}

/* @brief Sets an attribute on a Target to a given string value
 *
 * @param[in] i_target  The target
 * @param[in] i_value   The attribute value
 * @return errlHndl_t   Error if the string is too long for the attribute
 *
 * @note The attribute to set is given in the template parameter
 */
template<TARGETING::ATTRIBUTE_ID AttrID>
errlHndl_t setAttribute(TARGETING::Target* const i_target, const char* const i_value)
{
    errlHndl_t errl = nullptr;

    do {
        typename TARGETING::AttributeTraits<AttrID>::Type value = { };

        // subtract 1 for the terminator
        if (strlen(i_value) > sizeof(value) - 1)
        {
            PLDM_ERR("Location code from BMC is too long "
                     "(expected no longer than %llu bytes, got %llu)",
                     sizeof(value) - 1,
                     strlen(i_value));

            /*
             * @errortype  ERRL_SEV_UNRECOVERABLE
             * @moduleid   MOD_CACHE_REMOTE_FRU_VPD
             * @reasoncode RC_OVERLONG_LOCATION_CODE
             * @userdata1  Max length of location codes
             * @userdata2  Length of location code
             * @devdesc    Location code from BMC is too long to store in attribute
             * @custdesc   A software error occurred during system boot
             */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                 MOD_CACHE_REMOTE_FRU_VPD,
                                 RC_OVERLONG_LOCATION_CODE,
                                 sizeof(value) - 1,
                                 strlen(i_value),
                                 ERRORLOG::ErrlEntry::NO_SW_CALLOUT);
            addBmcErrorCallouts(errl);
            break;
        }

        strcpy(value, i_value);
        i_target->setAttr<AttrID>(value);
    } while (false);

    return errl;
}

using location_code_setter_t = errlHndl_t(*)(TARGETING::Target*, const char*);

// see hb_fru.H for doxygen
errlHndl_t cacheRemoteFruVpd()
{
    using namespace TARGETING;

    PLDM_ENTER("cacheRemoteFruVpd");
    errlHndl_t errl = nullptr;
    do{

    PLDM::pldm_fru_record_table_metadata_t table_metadata;
    errl =  getFruRecordTableMetaData(table_metadata);
    if(errl) { break; }

    std::unique_ptr<uint8_t, decltype(&free)>
        table_ptr(static_cast<uint8_t*>(malloc(table_metadata.fruTableSize)), free);

    errl = getFruRecordTable(table_metadata.fruTableSize,
                             table_ptr.get() );
    if(errl) { break; }

    const bool CACHE_VPD = true;
    const bool NO_CACHE_VPD = false;

    struct pldm_entity_to_targeting_mapping
    {
        entity_type pldm_entity_type;
        TARGETING::TYPE targeting_type;
        EEPROM::EEPROM_ROLE device_role;
        size_t max_expected_records;
        bool cache_vpd = CACHE_VPD;
        location_code_setter_t location_code_setter = nullptr;
    };

    static const pldm_entity_to_targeting_mapping pldm_entity_to_targeting_map[] = {
        { ENTITY_TYPE_BACKPLANE,
          TYPE_NODE,
          EEPROM::VPD_PRIMARY,
          1},
        { ENTITY_TYPE_CHASSIS,
          TYPE_SYS,
          EEPROM::VPD_PRIMARY,
          1,
          NO_CACHE_VPD,
          setAttribute<ATTR_CHASSIS_LOCATION_CODE> },
        { ENTITY_TYPE_LOGICAL_SYSTEM,
          TYPE_SYS,
          EEPROM::VPD_PRIMARY,
          1,
          NO_CACHE_VPD,
          setAttribute<ATTR_SYS_LOCATION_CODE> }
    };

    for(const auto& map_entry : pldm_entity_to_targeting_map)
    {
         auto device_rsis
             = thePdrManager().findFruRecordSetIdsByType(map_entry.pldm_entity_type);

        if(device_rsis.empty() ||
           device_rsis.size() > map_entry.max_expected_records)
        {
            // error, expected exactly 1 RSI associated with a device
            PLDM_ERR("cacheRemoteFruVpd: Found %d record set IDs matching"
                     "entity type 0x%.02x and expected at least 1 and a max of %d",
                     device_rsis.size(),
                     map_entry.pldm_entity_type,
                     map_entry.max_expected_records);
            /*
            * @errortype  ERRL_SEV_UNRECOVERABLE
            * @moduleid   MOD_CACHE_REMOTE_FRU_VPD
            * @reasoncode RC_INVALID_RSI_COUNT
            * @userdata1  # of Record Set Ids found
            * @userdata2  Entity Type
            * @devdesc    Unable to find correct record set ID(s) for
            *             PLDM entity
            * @custdesc   A software error occurred during system boot
            */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                 MOD_CACHE_REMOTE_FRU_VPD,
                                 RC_INVALID_RSI_COUNT,
                                 device_rsis.size(),
                                 map_entry.pldm_entity_type,
                                 ERRORLOG::ErrlEntry::NO_SW_CALLOUT);
            addBmcErrorCallouts(errl);
            break;
        }

        for(const auto device_rsi : device_rsis)
        {
            uint16_t records_in_set = 0;
            std::vector<uint8_t> device_fru_records;
            PLDM::getRecordSetByIdAndType(table_ptr.get(), table_metadata.recordCount,
                                          device_rsi, PLDM_FRU_RECORD_TYPE_OEM,
                                          device_fru_records, records_in_set);

            if(device_fru_records.empty() ||
               records_in_set == 0)
            {
                PLDM_ERR("cacheRemoteFruVpd: Failed to find any OEM Fru records"
                         " matching record set id 0x%.4x entity type 0x%.02x",
                         device_rsi, map_entry.pldm_entity_type);
                /*
                * @errortype  ERRL_SEV_UNRECOVERABLE
                * @moduleid   MOD_CACHE_REMOTE_FRU_VPD
                * @reasoncode RC_INVALID_RECORD_COUNT
                * @userdata1  record set id we are looking up
                * @userdata2  entity type
                * @devdesc    Unable to find records associated with record
                *             set id in fru record table
                * @custdesc   A software error occurred during system boot
                */
                errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                     MOD_CACHE_REMOTE_FRU_VPD,
                                     RC_INVALID_RECORD_COUNT,
                                     device_rsi,
                                     map_entry.pldm_entity_type,
                                     ERRORLOG::ErrlEntry::NO_SW_CALLOUT);
                addBmcErrorCallouts(errl);
                break;
            }

            // lookup the location code in the fru records associated with this RSI
            std::vector<uint8_t> location_code;
            errl = PLDM::getRecordSetLocationCode(device_fru_records.data(),
                                                  records_in_set,
                                                  location_code);

            if(errl)
            {
                PLDM_ERR("cacheRemoteFruVpd: Failed to find location code");
                break;
            }

            TargetHandle_t entity_target =
                getTargetFromLocationCode(location_code,
                                          map_entry.targeting_type);

            if(entity_target == nullptr)
            {
                PLDM_ERR("cacheRemoteFruVpd: Failed to find target associated w/ location code found");
                /*
                 * @errortype  ERRL_SEV_UNRECOVERABLE
                 * @moduleid   MOD_CACHE_REMOTE_FRU_VPD
                 * @reasoncode RC_INVALID_LOCATION_CODE
                 * @userdata1  record set id we are looking up
                 * @userdata2  entity type
                 * @devdesc    Unable to find records associated with record
                 *             set id in fru record table
                 * @custdesc   A software error occurred during system boot
                 */
                errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                     MOD_CACHE_REMOTE_FRU_VPD,
                                     RC_INVALID_LOCATION_CODE,
                                     device_rsi,
                                     map_entry.pldm_entity_type,
                                     ERRORLOG::ErrlEntry::NO_SW_CALLOUT);
                addBmcErrorCallouts(errl);
                break;
            }

            /* Set the location code of the target if necessary */

            if (map_entry.location_code_setter)
            {
                errl = map_entry.location_code_setter(entity_target,
                                                      reinterpret_cast<const char*>(location_code.data()));

                if (errl)
                {
                    PLDM_ERR("Failed to set location code attribute on %s target (HUID 0x%08x)",
                             attrToString<ATTR_TYPE>(entity_target->getAttr<ATTR_TYPE>()),
                             get_huid(entity_target));
                    break;
                }
            }

            /* Cache VPD if necessary */

            if (map_entry.cache_vpd == CACHE_VPD)
            {
                std::vector<uint8_t> ipz_record;
                errl = PLDM::pldmFruRecordSetToIPZ(device_fru_records.data(),
                                                   records_in_set,
                                                   ipz_record);
                if(errl)
                {
                    PLDM_ERR("cacheRemoteFruVpd: An error occurred during pldmFruRecordSetToIPZ");
                    break;
                }

                errl = EEPROM::cacheEepromBuffer(entity_target,
                                                 true,
                                                 ipz_record);

                if(errl)
                {
                    PLDM_ERR("cacheRemoteFruVpd: An error occurred during EEPROM::cacheEepromBuffer");
                    break;
                }
            }
        }

        if(errl)
        {
            PLDM_ERR("cacheRemoteFruVpd: An error while caching remote eeprom w/"
                     "entity type 0x%.02x target type 0x%.04x device role 0x.02x",
                     map_entry.pldm_entity_type,
                     map_entry.targeting_type,
                     map_entry.device_role);
            break;
        }

    }

    }while(0);
    PLDM_EXIT("cacheRemoteFruVpd");
    return errl;
}


// see hb_fru.H for doxygen
void printFruRecordTable(const uint8_t* const  i_pldm_fru_table_buf,
                         const uint16_t i_record_count)
{
    PLDM_ENTER("printFruRecordTable");
    assert( i_pldm_fru_table_buf != nullptr,
            "i_pldm_fru_table_buf is a nullptr!");
    // copy the pointer provided by the caller into
    // a local variable so we can do some ptr arithmatic
    // on it without messing up the caller
    const uint8_t * in_table_cur_ptr =
        const_cast<const uint8_t*>(i_pldm_fru_table_buf);

    // loop through the PLDM Fru Records in this PLDM Fru Record Table
    for( uint16_t i = 0; i < i_record_count; i++)
    {
        const pldm_fru_record_data_format *record_data =
            reinterpret_cast<const pldm_fru_record_data_format *>(in_table_cur_ptr);

        PLDM_INF("record set id  0x%.04x  "
                 "record type: 0x%.02x  "
                 "num fru fields: 0x%.02x  "
                 "encoding type: 0x%.02x  ",
                 record_data->record_set_id,
                 record_data->record_type,
                 record_data->num_fru_fields,
                 record_data->encoding_type);

        // we will need to keep a running count of the size of this record as we
        // process the TLVs associated with it. To start set the size as the start
        // of the TLV structs
        size_t record_size = offsetof(pldm_fru_record_data_format, tlvs);

        // loop through the TLVs which describe the entries of this PLDM Fru Record
        for( uint8_t j = 0; j < record_data->num_fru_fields; j++)
        {
            const pldm_fru_record_tlv *fru_tlv =
                reinterpret_cast<const pldm_fru_record_tlv *>(in_table_cur_ptr + record_size);
            PLDM_INF("field type 0x%.02x  "
                     "field len: 0x%.02x  ",
                      fru_tlv->type,
                      fru_tlv->length);
            PLDM_INF_BIN("Fru Field Value:",
                      fru_tlv->value,
                      fru_tlv->length);

            // increment record_size by total size of this TLV
            record_size += (offsetof(pldm_fru_record_tlv, value) +
                           fru_tlv->length);
        }
        // increment the in_table_cur_ptr to the next record
        in_table_cur_ptr += record_size;
    }
    PLDM_EXIT("printFruRecordTable");
}

}
