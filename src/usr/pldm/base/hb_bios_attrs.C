/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/base/hb_bios_attrs.C $                           */
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
/** @file  hb_bios_attrs.C
 *  @brief This file contains the implementation(s) of the function(s) that
 *         are used to get the current value of the PLDM BIOS attributes from
 *         the BMC.
 */

#include <util/comptime_util.H>
#include <algorithm>

// pldm /include/ headers
#include <pldm/requests/pldm_bios_attr_requests.H>
#include <pldm/base/hb_bios_attrs.H>
#include <pldm/pldm_errl.H>
#include <pldm/pldm_reasoncodes.H>

// pldm /src/ headers
#include "../common/pldmtrace.H"

namespace PLDM {

// Attributes
const char PLDM_BIOS_HB_HYP_SWITCH_STRING[] = "hb-hyp-switch";

// Possible Values
constexpr char PLDM_BIOS_HB_OPAL_STRING[] = "OPAL";
constexpr char PLDM_BIOS_HB_POWERVM_STRING[] = "PowerVM";

constexpr const char* POSSIBLE_HYP_VALUE_STRINGS[] = {PLDM_BIOS_HB_OPAL_STRING,
                                                      PLDM_BIOS_HB_POWERVM_STRING};

/** @brief Given a size_t s, and a string ptr c,
*          determine if the strlen of the string pointed
*          to by c is > s. If it is, return strlen of c,
*          else return s.
*
* @param[in] s
*          A length to compare against.
* @param[in] c
*          Char ptrs which points to a string that we will
*          take the length of and compare against s
*
* @return the max of strlen(c) and s
*/
constexpr size_t find_maxstrlen(size_t s, const char* c)
                    {return std::max(s, Util::comptime_strlen(c));};

/** @brief Given two vectors, one representing PLDM Bios Table
*          String Table, and one representing PLDM Bios Attribute
*          Table, ensure that the tables have content, if they do
*          not, perform the neccesary PLDM requests to the BMC to
*          populate the tables.
*
* @param[in,out] io_string_table
*          A byte vector that if empty will be filled
*          with the string table via a PLDM Bios Table
*          request to the BMC. If it already has contents
*          no request will be made and vector will not
*          be modified.
* @param[in,out] io_attr_table
*          A byte vector that if empty will be filled
*          with the attribute table via a PLDM Bios Table
*          request to the BMC. If it already has contents
*          no request will be made and vector will not
*          be modified.
*
* @return Error if any, otherwise nullptr.
*/
errlHndl_t ensureTablesAreSet(std::vector<uint8_t>& io_string_table,
                              std::vector<uint8_t>& io_attr_table)
{
  errlHndl_t errl = nullptr;

  do{

  pldm_bios_table_types table_type = PLDM_BIOS_STRING_TABLE;
  if(io_string_table.empty())
  {
      PLDM_DBG("ensureTablesAreSet: populating string table");
      errl = getBiosTable(table_type, io_string_table);
      if(errl)
      {
          PLDM_ERR("ensureTablesAreSet: failed populating string table");
          break;
      }
  }

  table_type = PLDM_BIOS_ATTR_TABLE;
  if(io_attr_table.empty())
  {
      PLDM_DBG("ensureTablesAreSet: populating attribute table");
      errl = getBiosTable(table_type, io_attr_table);
      if(errl)
      {
          PLDM_ERR("ensureTablesAreSet: failed populating attribute table");
          break;
      }
  }

  }while(0);

  return errl;
}


/** @brief Given a string describing the name of a PLDM bios attribute
*          Hostboot wants to read from the BMC, retrieve the value
*          and value type of that attribute
*
* @param[in] i_attr_string
*          String representing PLDM Bios attribute we want
*          the value of.
* @param[in,out] io_string_table
*          A byte vector that if empty will be filled
*          with the string table via a PLDM Bios Table
*          request to the BMC. If it already has contents
*          no request will be made and vector will not
*          be modified.
* @param[in,out] io_attr_table
*          A byte vector that if empty will be filled
*          with the attribute table via a PLDM Bios Table
*          request to the BMC. If it already has contents
*          no request will be made and vector will not
*          be modified.
* @param[out] o_attr_type
*          Type of PLDM attribute, See bios.h.
* @param[out] o_attr_val
*          Expected to be empty on input, will be cleared
*          during the function. If no error then will
*          contain bios attribute value when
*          function completes.
* @return Error if any, otherwise nullptr.
*/
errlHndl_t getCurrentAttrValue(const char *i_attr_string,
                               std::vector<uint8_t>& io_string_table,
                               std::vector<uint8_t>& io_attr_table,
                               pldm_bios_attribute_type& o_attr_type,
                               const pldm_bios_attr_table_entry ** o_attr_entry_ptr,
                               std::vector<uint8_t>& o_attr_val)
{
  errlHndl_t errl = nullptr;
  assert(*o_attr_entry_ptr == nullptr, "getCurrentAttrValue was passed a non-null ptr");

  // start with clean output vector
  o_attr_val.clear();

  do {
  PLDM_ENTER("getCurrentAttrValue %s", i_attr_string);
  // We will need a copy of the string table to figure out
  // the string handle
  errl = ensureTablesAreSet(io_string_table, io_attr_table);
  if(errl)
  {
      break;
  }

  assert(!io_string_table.empty(), "Empty string table returned from ensureTablesAreSet");
  assert(!io_attr_table.empty(), "Empty attribute table returned from ensureTablesAreSet");

  PLDM_DBG("getCurrentAttrValue: Looking up string %s in string table...", i_attr_string);
  // Get the string handle by looking up i_attr_string in io_string_table
  const struct pldm_bios_string_table_entry * string_entry =
      pldm_bios_table_string_find_by_string(io_string_table.data(),
                                            io_string_table.size(),
                                            i_attr_string);
  if(string_entry == nullptr)
  {
      /*
        * @errortype  ERRL_SEV_UNRECOVERABLE
        * @moduleid   MOD_GET_CURRENT_VALUE
        * @reasoncode RC_UNSUPPORTED_ATTRIBUTE
        * @userdata1  First 8 char of attr string
        * @userdata2  unused
        * @devdesc    Software problem, PLDM transaction failed
        * @custdesc   A software error occurred during system boot
        */
      errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                            MOD_GET_CURRENT_VALUE,
                            RC_UNSUPPORTED_ATTRIBUTE,
                            *reinterpret_cast<const uint64_t *>(i_attr_string),
                            0,
                            ErrlEntry::NO_SW_CALLOUT);

      addBmcErrorCallouts(errl);
      break;
  }

  auto string_handle =
      pldm_bios_table_string_entry_decode_handle(string_entry);

  PLDM_DBG("getCurrentAttrValue: Decoded string handle %x", string_handle);

  uint16_t attribute_handle = 0;

  auto attr_table_iter = pldm_bios_table_iter_create(io_attr_table.data(),
                                                     io_attr_table.size(),
                                                     PLDM_BIOS_ATTR_TABLE);

  // Get the attribute handle by looking through the attribute table
  for (;
       pldm_bios_table_iter_is_end(attr_table_iter) != true;
       pldm_bios_table_iter_next(attr_table_iter))
  {
      const pldm_bios_attr_table_entry * attr_entry_ptr =
          reinterpret_cast<const pldm_bios_attr_table_entry * >(
            pldm_bios_table_iter_value(attr_table_iter));
      if(pldm_bios_table_attr_entry_decode_string_handle(attr_entry_ptr) == string_handle)
      {
          attribute_handle =
            pldm_bios_table_attr_entry_decode_attribute_handle(attr_entry_ptr);

          o_attr_type =
            static_cast<pldm_bios_attribute_type>(
                pldm_bios_table_attr_entry_decode_attribute_type(attr_entry_ptr));

          *o_attr_entry_ptr = attr_entry_ptr;
          break;
      }
  }

  pldm_bios_table_iter_free(attr_table_iter);

  // we found a valid string handle but it did not match
  // up with anything in the attribute table, BMC bug likely
  if(*o_attr_entry_ptr == nullptr)
  {
      /*
        * @errortype  ERRL_SEV_UNRECOVERABLE
        * @moduleid   MOD_GET_CURRENT_VALUE
        * @reasoncode RC_NO_ATTRIBUTE_MATCH
        * @userdata1  String handle we found in string table
        * @userdata2  unused
        * @devdesc    Software problem, PLDM transaction failed
        * @custdesc   A software error occurred during system boot
        */
      errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                            MOD_GET_CURRENT_VALUE,
                            RC_NO_ATTRIBUTE_MATCH,
                            string_handle,
                            0,
                            ErrlEntry::NO_SW_CALLOUT);
      addBmcErrorCallouts(errl);
      break;
  }

  std::vector<uint8_t> entry_val_vector;
  errl = getBiosAttrFromHandle(attribute_handle,
                               entry_val_vector);

  if(errl)
  {
      PLDM_ERR("getCurrentAttrValue failed attempting to get the attribute entry for attribute handle %04x (%s)",
               attribute_handle, i_attr_string);
      break;
  }

  pldm_bios_attr_val_table_entry * value_entry =
      reinterpret_cast<pldm_bios_attr_val_table_entry *>(entry_val_vector.data());

  const size_t value_size = entry_val_vector.size() -
                            offsetof(pldm_bios_attr_val_table_entry, value);

  o_attr_val.insert(o_attr_val.begin(),
                    value_entry->value,
                    value_entry->value + value_size);

  PLDM_DBG_BIN("Value found was ", o_attr_val.data(), o_attr_val.size());
  PLDM_EXIT("getCurrentAttrValue Found type 0x%x for attribute %s", o_attr_type, i_attr_string);

  }while(0);

  return errl;
}

errlHndl_t getHypervisorMode(std::vector<uint8_t>& io_string_table,
                             std::vector<uint8_t>& io_attr_table,
                             TARGETING::ATTR_PAYLOAD_KIND_type &o_payloadType)
{
    errlHndl_t errl = nullptr;
    do{
    // we have to default to something
    // enum has no invalid values
    pldm_bios_attribute_type hyp_attr_type = PLDM_BIOS_ENUMERATION;
    const pldm_bios_attr_table_entry * attr_entry_ptr = nullptr;
    std::vector<uint8_t> hyp_attr_value;

    errl = getCurrentAttrValue(PLDM_BIOS_HB_HYP_SWITCH_STRING,
                               io_string_table,
                               io_attr_table,
                               hyp_attr_type,
                               &attr_entry_ptr,
                               hyp_attr_value);
    if(errl)
    {
        PLDM_ERR("An error occurred while requesting the value of %s from the BMC",
                 PLDM_BIOS_HB_HYP_SWITCH_STRING)
        break;
    }

    if(hyp_attr_type != PLDM_BIOS_ENUMERATION)
    {
        PLDM_ERR("Attribute type of %s is reported as 0x%x when we expected 0x%x",
                 PLDM_BIOS_HB_HYP_SWITCH_STRING,
                 hyp_attr_type,
                 PLDM_BIOS_ENUMERATION);
        /*
          * @errortype
          * @severity   ERRL_SEV_UNRECOVERABLE
          * @moduleid   MOD_GET_HYPERVISOR_MODE
          * @reasoncode RC_UNSUPPORTED_TYPE
          * @userdata1  Actual type returned
          * @userdata2  Expected type
          * @devdesc    Software problem, incorrect data from BMC
          * @custdesc   A software error occurred during system boot
          */
        errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                              MOD_GET_HYPERVISOR_MODE,
                              RC_UNSUPPORTED_TYPE,
                              hyp_attr_type,
                              PLDM_BIOS_ENUMERATION,
                              ErrlEntry::NO_SW_CALLOUT);
        addBmcErrorCallouts(errl);
        break;
    }

    // There should be 2 bytes in the value, 1 byte stating there is 1 value
    // and 1 byte stating the value itself
    const uint8_t expected_value_length = 2;
    if(hyp_attr_value.size() != expected_value_length)
    {
        PLDM_ERR("Attribute value size of %s is reported as 0x%x bytes when we expected 0x%x bytes",
                 PLDM_BIOS_HB_HYP_SWITCH_STRING,
                 hyp_attr_value.size(),
                 expected_value_length);
        /*
          * @errortype
          * @severity   ERRL_SEV_UNRECOVERABLE
          * @moduleid   MOD_GET_HYPERVISOR_MODE
          * @reasoncode RC_UNSUPPORTED_TYPE
          * @userdata1  Actual Size
          * @userdata2  Expected Size
          * @devdesc    Software problem, incorrect data from BMC
          * @custdesc   A software error occurred during system boot
          */
        errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                              MOD_GET_HYPERVISOR_MODE,
                              RC_UNSUPPORTED_TYPE,
                              hyp_attr_value.size(),
                              expected_value_length,
                              ErrlEntry::NO_SW_CALLOUT);
        addBmcErrorCallouts(errl);
        break;
    }

    auto num_possible_values = pldm_bios_table_attr_entry_enum_decode_pv_num(attr_entry_ptr);
    uint16_t possible_values[num_possible_values] = {0};

    pldm_bios_table_attr_entry_enum_decode_pv_hdls(attr_entry_ptr,
                                                   possible_values,
                                                   num_possible_values);

    auto string_table_entry = pldm_bios_table_string_find_by_handle(io_string_table.data(),
                                                                    io_string_table.size(),
                                                                    possible_values[hyp_attr_value[1]]);

    // Find the longest string that we will accept as a
    // possible value for the "hb-hyp-switch" PLDM BIOS attribute
    // so we can allocate a sufficiently sized buffer.
    // Add 1 byte to buffer to account for null terminator
    constexpr size_t max_possible_value_length =
        std::accumulate(std::begin(POSSIBLE_HYP_VALUE_STRINGS),
                        std::end(POSSIBLE_HYP_VALUE_STRINGS),
                        0ul,
                        find_maxstrlen) + 1;

    // Ensure max_possible_value_length is larger than the extra
    // extra byte we added to account for the null terminator.
    // This assert forces the constexpr to be evaluated at
    // compile-time
    static_assert(max_possible_value_length > 1);
    char translated_string[max_possible_value_length] = {0};

    pldm_bios_table_string_entry_decode_string(string_table_entry,
                                               translated_string,
                                               max_possible_value_length);

    if(strncmp(translated_string, PLDM_BIOS_HB_POWERVM_STRING, max_possible_value_length) == 0)
    {
        PLDM_INF("Power VM hypervisor found!");
        o_payloadType = TARGETING::PAYLOAD_KIND_PHYP;
    }
    else if(strncmp(translated_string, PLDM_BIOS_HB_OPAL_STRING, max_possible_value_length) == 0)
    {
        PLDM_INF("Opal hypervisor found!");
        o_payloadType = TARGETING::PAYLOAD_KIND_SAPPHIRE;
    }
    else
    {
        // print the entire buffer
        PLDM_INF_BIN("unknown string : ",translated_string, max_possible_value_length);
        o_payloadType = TARGETING::PAYLOAD_KIND_INVALID;
    }

    }while(0);

    return errl;
}

}
