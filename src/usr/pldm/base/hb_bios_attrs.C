/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/base/hb_bios_attrs.C $                           */
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

/** @file  hb_bios_attrs.C
 *  @brief This file contains the implementations of the functions that
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

// support for string user details sections
#include <errl/errludstring.H>

namespace PLDM {

// Attributes
const char PLDM_BIOS_HB_HYP_SWITCH_STRING[] = "hb-hyp-switch";
const char PLDM_BIOS_HB_DEBUG_CONSOLE_STRING[] = "hb-debug-console";

// Possible Values
constexpr char PLDM_BIOS_HB_OPAL_STRING[] = "OPAL";
constexpr char PLDM_BIOS_HB_POWERVM_STRING[] = "PowerVM";
constexpr char PLDM_BIOS_ENABLED_STRING[] = "Enabled";
constexpr char PLDM_BIOS_DISABLED_STRING[] = "Disabled";

constexpr const char* POSSIBLE_HYP_VALUE_STRINGS[] =
                      { PLDM_BIOS_HB_OPAL_STRING,
                        PLDM_BIOS_HB_POWERVM_STRING };

constexpr const char* POSSIBLE_HB_DEBUG_CONSOLE_STRINGS[] =
                      { PLDM_BIOS_ENABLED_STRING,
                        PLDM_BIOS_DISABLED_STRING };


/** @brief Given a size_t s, and a string ptr c,
*          determine if the strlen of the string pointed
*          to by c is > s. If it is, return strlen of c,
*          else return s.
*
* @param[in] s
*       A length to compare against.
* @param[in] c
*       Char ptr which points to a string that we will
*       take the length of and compare against s.
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
*       See file brief in hb_bios_attrs.H.
* @param[in,out] io_attr_table
*       See file brief in hb_bios_attrs.H.
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
*          and value type of that attribute.
*
* @param[in]     i_attr_string
*       String representing PLDM Bios attribute we want the value of.
* @param[in]     i_expected_attr_type
*       Type of PLDM attribute, See bios.h.
* @param[in,out] io_string_table
*       See file brief in hb_bios_attrs.H.
* @param[in,out] io_attr_table
*       See file brief in hb_bios_attrs.H.
* @param[out]    o_attr_entry_ptr
*       Ptr to this attribute's entry in the attr_table. This should be null
*       on entry.
* @param[out]    o_attr_val
*       Expected to be empty on input, will be cleared during the function.
*       If no error occurs then will contain bios attribute value when
*       the function completes.
*
* @return Error if any, otherwise nullptr.
*/
errlHndl_t getCurrentAttrValue(const char *i_attr_string,
                               const pldm_bios_attribute_type i_expected_attr_type,
                               std::vector<uint8_t>& io_string_table,
                               std::vector<uint8_t>& io_attr_table,
                               const pldm_bios_attr_table_entry * &o_attr_entry_ptr,
                               std::vector<uint8_t>& o_attr_val)
{
  errlHndl_t errl = nullptr;
  assert(o_attr_entry_ptr == nullptr, "getCurrentAttrValue was passed a non-null ptr");

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
      PLDM_ERR("Could not find %s in the string_table provided by the BMC",
               i_attr_string);
      /*@
        * @errortype  ERRL_SEV_UNRECOVERABLE
        * @moduleid   MOD_GET_CURRENT_VALUE
        * @reasoncode RC_UNSUPPORTED_ATTRIBUTE
        * @userdata1  Unused
        * @userdata2  Unused
        * @devdesc    Software problem, PLDM transaction failed
        * @custdesc   A software error occurred during system boot
        */
      errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                            MOD_GET_CURRENT_VALUE,
                            RC_UNSUPPORTED_ATTRIBUTE,
                            0,
                            0,
                            ErrlEntry::NO_SW_CALLOUT);
      ErrlUserDetailsString(i_attr_string).addToLog(errl);
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

          o_attr_entry_ptr = attr_entry_ptr;
          break;
      }
  }
  pldm_bios_table_iter_free(attr_table_iter);

  // we found a valid string handle but it did not match
  // up with anything in the attribute table, BMC bug likely
  if(o_attr_entry_ptr == nullptr)
  {
      PLDM_ERR("Could not find %s in the in the attr_table provided by the BMC",
               i_attr_string);
      /*@
        * @errortype  ERRL_SEV_UNRECOVERABLE
        * @moduleid   MOD_GET_CURRENT_VALUE
        * @reasoncode RC_NO_ATTRIBUTE_MATCH
        * @userdata1  String handle we found in string table
        * @userdata2  Unused
        * @devdesc    Software problem, PLDM transaction failed
        * @custdesc   A software error occurred during system boot
        */
      errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                            MOD_GET_CURRENT_VALUE,
                            RC_NO_ATTRIBUTE_MATCH,
                            string_handle,
                            0,
                            ErrlEntry::NO_SW_CALLOUT);
      ErrlUserDetailsString(i_attr_string).addToLog(errl);
      addBmcErrorCallouts(errl);
      break;
  }
  const auto attr_type_found =
    static_cast<pldm_bios_attribute_type>(
                pldm_bios_table_attr_entry_decode_attribute_type(o_attr_entry_ptr));

  if(attr_type_found != i_expected_attr_type)
  {
      PLDM_ERR("Attribute type as 0x%x reported when we expected 0x%x for attribute %s",
                attr_type_found,
                i_expected_attr_type,
                i_attr_string);
      /*@
        * @errortype
        * @severity   ERRL_SEV_UNRECOVERABLE
        * @moduleid   MOD_GET_CURRENT_VALUE
        * @reasoncode RC_UNSUPPORTED_TYPE
        * @userdata1  Actual type returned
        * @userdata2  Expected type
        * @devdesc    Software problem, incorrect data from BMC
        * @custdesc   A software error occurred during system boot
        */
      errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                            MOD_GET_CURRENT_VALUE,
                            RC_UNSUPPORTED_TYPE,
                            attr_type_found,
                            i_expected_attr_type,
                            ErrlEntry::NO_SW_CALLOUT);
      ErrlUserDetailsString(i_attr_string).addToLog(errl);
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
  PLDM_EXIT("getCurrentAttrValue Found type 0x%x for attribute %s",
             attr_type_found, i_attr_string);

  }while(0);

  return errl;
}

/** @brief Given a byte vector that was returned as the "value"
 *         of i_attr_string, verify the size is correct and
 *         translate all relevent bytes into string handles
 *         by parsing i_attr_entry possible_values list.
 *
 * @param[in] i_string_table
 *       A populated copy of the PLDM BIOS String Table.
 * @param[in] i_attr_value
 *       Byte vector containing the value that was returned by the BMC
 *       for i_attr_string.
 * @param[in] i_attr_entry
 *       Entry in the PLDM BIOS Attribute Table corresponding to i_attr_string.
 * @param[in] i_attr_string
 *       String representing the attribute we are looking up on the BMC.
 * @param[out] o_cur_val_string_entries
 *       Vector of string table entry pointers pointing the string entries
 *       matching the values found in i_attr_value vector.
 *
 * @return Error if any, otherwise nullptr.
 */
errlHndl_t lookupEnumAttrValuesInStringTable(const std::vector<uint8_t>& i_string_table,
                                             const std::vector<uint8_t>& i_attr_value,
                                             const pldm_bios_attr_table_entry *const i_attr_entry,
                                             const char *i_attr_string,
                                             std::vector<pldm_bios_string_table_entry *> &o_cur_val_string_entries)
{
    errlHndl_t errl = nullptr;
    PLDM_ENTER("lookupAttrValueInStringTable");
    do
    {

    auto num_possible_values = pldm_bios_table_attr_entry_enum_decode_pv_num(i_attr_entry);
    uint16_t possible_values[num_possible_values] = {0};
    pldm_bios_table_attr_entry_enum_decode_pv_hdls(i_attr_entry,
                                                   possible_values,
                                                   num_possible_values);

    if(i_attr_value[0] != i_attr_value.size() - 1)
    {
        // The first byte should have the number of remaining bytes
        PLDM_ERR("The first byte should have the number of remaining bytes");
        /*@
          * @errortype
          * @severity   ERRL_SEV_UNRECOVERABLE
          * @moduleid   MOD_LOOKUP_VALUE_IN_STRING_TABLE
          * @reasoncode RC_INVALID_LENGTH
          * @userdata1  Stated Size
          * @userdata2  Size found
          * @devdesc    Software problem, incorrect data from BMC
          * @custdesc   A software error occurred during system boot
          */
        errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                             MOD_LOOKUP_VALUE_IN_STRING_TABLE,
                             RC_INVALID_LENGTH,
                             i_attr_value[0],
                             (i_attr_value.size() -1),
                             ErrlEntry::NO_SW_CALLOUT);
        ErrlUserDetailsString(i_attr_string).addToLog(errl);
        addBmcErrorCallouts(errl);
        break;
    }

    // Skip the first byte because, as mentioned above, it contains the
    // number of remaing bytes
    for(uint8_t i = 1; i < i_attr_value.size(); i++)
    {
        const uint8_t possible_value_index = i_attr_value[i];
        if(possible_value_index >= num_possible_values)
        {
            PLDM_ERR("Possible value selection %d exceeds the maximum size of possible of %d for %s",
                    possible_value_index,
                    num_possible_values,
                    i_attr_string);
            /*@
              * @errortype
              * @severity   ERRL_SEV_UNRECOVERABLE
              * @moduleid   MOD_LOOKUP_VALUE_IN_STRING_TABLE
              * @reasoncode RC_OUT_OF_RANGE
              * @userdata1  possible_value_index
              * @userdata2  max possible value
              * @devdesc    Software problem, incorrect data from BMC
              * @custdesc   A software error occurred during system boot
              */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                  MOD_LOOKUP_VALUE_IN_STRING_TABLE,
                                  RC_OUT_OF_RANGE,
                                  possible_value_index,
                                  num_possible_values,
                                  ErrlEntry::NO_SW_CALLOUT);
            ErrlUserDetailsString(i_attr_string).addToLog(errl);
            addBmcErrorCallouts(errl);
            break;
        }

        // Each byte after the first byte in the value returned for a
        // enum pldm bios attribute maps to a possible value which in
        // turn maps to a string handle which we can lookup in the
        // string table
        const pldm_bios_string_table_entry * string_entry =
                pldm_bios_table_string_find_by_handle(i_string_table.data(),
                                                      i_string_table.size(),
                                                      possible_values[possible_value_index]);
        if(string_entry == nullptr)
        {
            PLDM_ERR("The BMC has an invalid string handle set for the possible values of the attribute %s",
                    i_attr_string);
            /*@
              * @errortype
              * @severity   ERRL_SEV_UNRECOVERABLE
              * @moduleid   MOD_LOOKUP_VALUE_IN_STRING_TABLE
              * @reasoncode RC_NO_MATCH_IN_TABLE
              * @userdata1  String handle we tried to lookup
              * @userdata2  Unused
              * @devdesc    Software problem, incorrect data from BMC
              * @custdesc   A software error occurred during system boot
              */
            errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                                  MOD_LOOKUP_VALUE_IN_STRING_TABLE,
                                  RC_NO_MATCH_IN_TABLE,
                                  possible_values[possible_value_index],
                                  0,
                                  ErrlEntry::NO_SW_CALLOUT);
            ErrlUserDetailsString(i_attr_string).addToLog(errl);
            addBmcErrorCallouts(errl);
            break;
        }
        o_cur_val_string_entries.push_back(
            const_cast<pldm_bios_string_table_entry *>(string_entry));
    }

    }while(0);
    PLDM_EXIT("lookupAttrValueInStringTable");
    return errl;
}

/** @brief Given the string representing a PLDM BIOS attribute of type enumeration,
 *         get string entry(s) returned as the value of this attribute by the BMC
 *
 * @param[in,out] io_string_table
 *       See file brief in hb_bios_attrs.H.
 * @param[in,out] io_attr_table
 *       See file brief in hb_bios_attrs.H.
 * @param[in] i_attr_string
 *       String representing the attribute we are looking up on the BMC.
 * @param[out] o_cur_val_string_entries
 *       Vector of string table entry pointers pointing the string entries
 *       matching the values found in the BMC's return data.
 *
 * @return Error if any, otherwise nullptr.
 */
errlHndl_t genericEnumAttrLookup(std::vector<uint8_t>& io_string_table,
                                 std::vector<uint8_t>& io_attr_table,
                                 const char *i_attr_string,
                                 std::vector<pldm_bios_string_table_entry *> &o_cur_val_string_entries)
{
    errlHndl_t errl = nullptr;
    PLDM_ENTER("genericEnumAttrLookup %s", i_attr_string);
    do{

        // we have to default to something
        // enum has no invalid values
        const pldm_bios_attribute_type expected_type = PLDM_BIOS_ENUMERATION;
        const pldm_bios_attr_table_entry * attr_entry_ptr = nullptr;
        std::vector<uint8_t> attr_value;

        errl = getCurrentAttrValue(i_attr_string,
                                  expected_type,
                                  io_string_table,
                                  io_attr_table,
                                  attr_entry_ptr,
                                  attr_value);
        if(errl)
        {
            PLDM_ERR("An error occurred while requesting the value of %s from the BMC",
                    i_attr_string)
            break;
        }

        errl = lookupEnumAttrValuesInStringTable(io_string_table,
                                                attr_value,
                                                attr_entry_ptr,
                                                i_attr_string,
                                                o_cur_val_string_entries);
        if(errl)
        {
            PLDM_ERR("An error occurred looking up the value we got for %s in the string table",
                    i_attr_string)
            break;
        }
    }while(0);

    PLDM_EXIT("genericEnumAttrLookup");
    return errl;
}

/** @brief A wrapper around genericEnumAttrLookup that ensures only
 *         a single string table entry is returned as a result of
 *         the attribute value lookup.
 *
 * @param[in,out] io_string_table
 *       See file brief in hb_bios_attrs.H.
 * @param[in,out] io_attr_table
 *       See file brief in hb_bios_attrs.H.
 * @param[in] i_attr_string
 *       String representing the attribute we are looking up on the BMC.
 * @param[out] o_cur_val_string_entry
 *       String entry ptr which points to the entry in the string_table
 *       that matches this attribute's current value.
 *
 * @return Error if any, otherwise nullptr.
 */
errlHndl_t systemEnumAttrLookup(std::vector<uint8_t>& io_string_table,
                     std::vector<uint8_t>& io_attr_table,
                     const char *i_attr_string,
                     const pldm_bios_string_table_entry * &o_cur_val_string_entry)
{
    errlHndl_t errl = nullptr;

    do{
    std::vector<pldm_bios_string_table_entry *> cur_val_string_entries;

    errl = genericEnumAttrLookup(io_string_table, io_attr_table,
                                 i_attr_string, cur_val_string_entries);
    if(errl)
    {
        break;
    }

    // This is a system level attribute so we only expect a single entry
    if(cur_val_string_entries.size() != 1)
    {
        PLDM_ERR("Found %d string handles when we expected to see a single string handle returned for attribute %s",
                 cur_val_string_entries.size(),
                 i_attr_string);
        /*@
          * @errortype
          * @severity   ERRL_SEV_UNRECOVERABLE
          * @moduleid   MOD_SYSTEM_ENUM_ATTR_LOOKUP
          * @reasoncode RC_INVALID_LENGTH
          * @userdata1  # String Handles Returned
          * @userdata2  Unused
          * @devdesc    Software problem, incorrect data from BMC
          * @custdesc   A software error occurred during system boot
          */
        errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                             MOD_SYSTEM_ENUM_ATTR_LOOKUP,
                             RC_INVALID_LENGTH,
                             cur_val_string_entries.size(),
                             0,
                             ErrlEntry::NO_SW_CALLOUT);
        ErrlUserDetailsString(i_attr_string).addToLog(errl);
        addBmcErrorCallouts(errl);
        break;
    }
    o_cur_val_string_entry = cur_val_string_entries[0];

    }while(0);

    return errl;
}

errlHndl_t getDebugConsoleEnabled(bool &o_debugConsoleEnabled)
{
    errlHndl_t errl = nullptr;
    o_debugConsoleEnabled = false;
    do{
    const pldm_bios_string_table_entry * cur_val_string_entry_ptr = nullptr;
    std::vector<uint8_t> string_table, attr_table;

    errl = systemEnumAttrLookup(string_table,
                                attr_table,
                                PLDM_BIOS_HB_DEBUG_CONSOLE_STRING,
                                cur_val_string_entry_ptr);
    if(errl)
    {
      PLDM_ERR("Failed to lookup value for %s", PLDM_BIOS_HB_DEBUG_CONSOLE_STRING);
      break;
    }

    // Find the longest string that we will accept as a
    // possible value for the a given PLDM BIOS attribute
    // so we can allocate a sufficiently sized buffer.
    // Add 1 byte to buffer to account for null terminator
    constexpr auto max_possible_value_length =
         std::accumulate(std::begin(POSSIBLE_HB_DEBUG_CONSOLE_STRINGS),
                         std::end(POSSIBLE_HB_DEBUG_CONSOLE_STRINGS),
                         0ul,
                         find_maxstrlen) + 1;

    // Ensure max_possible_value_length is larger than the extra
    // extra byte we added to account for the null terminator.
    // This assert forces the constexpr to be evaluated at
    // compile-time
    static_assert(max_possible_value_length > 1);
    char translated_string[max_possible_value_length] = {0};

    pldm_bios_table_string_entry_decode_string(cur_val_string_entry_ptr,
                                               translated_string,
                                               max_possible_value_length);

    if(strncmp(translated_string, PLDM_BIOS_DISABLED_STRING, max_possible_value_length) == 0)
    {
        PLDM_INF("Debug console traces are disabled by the BMC!");
        // o_debugConsoleEnabled is defaulted to false at start of function
    }
    else if(strncmp(translated_string, PLDM_BIOS_ENABLED_STRING, max_possible_value_length) == 0)
    {
        PLDM_INF("Debug console traces are enabled by the BMC!");
        o_debugConsoleEnabled = true;
    }
    else
    {
        // print the entire buffer
        PLDM_INF_BIN("Unexpected string : ",translated_string, max_possible_value_length);
        /*@
          * @errortype
          * @severity   ERRL_SEV_UNRECOVERABLE
          * @moduleid   MOD_GET_DEBUG_CONSOLE_ENABLED
          * @reasoncode RC_UNSUPPORTED_TYPE
          * @userdata1  Unused
          * @userdata2  Unused
          * @devdesc    Software problem, incorrect data from BMC
          * @custdesc   A software error occurred during system boot
          */
        errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                              MOD_GET_DEBUG_CONSOLE_ENABLED,
                              RC_UNSUPPORTED_TYPE,
                              0,
                              0,
                              ErrlEntry::NO_SW_CALLOUT);
        ErrlUserDetailsString(PLDM_BIOS_HB_DEBUG_CONSOLE_STRING).addToLog(errl);
        ErrlUserDetailsString(translated_string).addToLog(errl);
        addBmcErrorCallouts(errl);
        break;
    }

    }while(0);
    return errl;
}

errlHndl_t getHypervisorMode(std::vector<uint8_t>& io_string_table,
                             std::vector<uint8_t>& io_attr_table,
                             TARGETING::ATTR_PAYLOAD_KIND_type &o_payloadType)
{
    errlHndl_t errl = nullptr;
    do{
    const pldm_bios_string_table_entry * cur_val_string_entry_ptr = nullptr;

    errl = systemEnumAttrLookup(io_string_table,
                                io_attr_table,
                                PLDM_BIOS_HB_HYP_SWITCH_STRING,
                                cur_val_string_entry_ptr);
    if(errl)
    {
      PLDM_ERR("Failed to lookup value for %s", PLDM_BIOS_HB_HYP_SWITCH_STRING);
      break;
    }
    // Find the longest string that we will accept as a
    // possible value for the a given PLDM BIOS attribute
    // so we can allocate a sufficiently sized buffer.
    // Add 1 byte to buffer to account for null terminator
    constexpr auto max_possible_value_length =
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

    pldm_bios_table_string_entry_decode_string(cur_val_string_entry_ptr,
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
        PLDM_INF_BIN("Unexpected string string : ",translated_string, max_possible_value_length);
        o_payloadType = TARGETING::PAYLOAD_KIND_INVALID;
    }

    }while(0);

    return errl;
}

}
