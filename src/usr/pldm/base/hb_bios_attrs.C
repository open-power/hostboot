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
#include <stdlib.h>

#include <map>

// pldm /include/ headers
#include <pldm/requests/pldm_bios_attr_requests.H>
#include <pldm/base/hb_bios_attrs.H>
#include <pldm/base/hb_bios_attrs_if.H>
#include <pldm/pldm_errl.H>
#include <pldm/pldm_reasoncodes.H>

// pldm /src/ headers
#include "../common/pldmtrace.H"

// support for string user details sections
#include <errl/errludstring.H>
#include <errl/errlmanager.H>

// SectionId eyecatch string lookup
#include <pnor/pnorif.H>

// sys target
#include <targeting/common/targetservice.H>

// BMC Console tracing
#include <console/consoleif.H>

namespace PLDM {

// Attributes
const char PLDM_BIOS_HB_HYP_SWITCH_STRING[]                = "hb_hyp_switch_current";
const char PLDM_BIOS_HB_DEBUG_CONSOLE_STRING[]             = "hb_debug_console";
const char PLDM_BIOS_HB_HUGE_PAGE_COUNT_STRING[]           = "hb_number_huge_pages_current";
const char PLDM_BIOS_HB_HUGE_PAGE_SIZE_STRING[]            = "hb_huge_page_size_current";
const char PLDM_BIOS_HB_LMB_SIZE_STRING[]                  = "hb_memory_region_size_current";
const char PLDM_BIOS_HB_MFG_FLAGS_STRING[]                 = "hb_mfg_flags_current";
const char PLDM_BIOS_HB_FIELD_CORE_OVERRIDE_STRING[]       = "hb_field_core_override_current";
const char PLDM_BIOS_HB_USB_ENABLEMENT_STRING[]            = "hb_host_usb_enablement_current";
const char PLDM_BIOS_HB_MAX_NUMBER_HUGE_PAGES_STRING[]     = "hb_max_number_huge_pages";
const char PLDM_BIOS_HB_ENLARGED_CAPACITY_STRING[]         = "hb_ioadapter_enlarged_capacity_current";

// When power limit values change, the effect on the OCCs is immediate, so we
// always want the most recent values here.
const char PLDM_BIOS_HB_POWER_LIMIT_ENABLE_STRING[]        = "hb_power_limit_enable";
const char PLDM_BIOS_HB_POWER_LIMIT_IN_WATTS_STRING[]      = "hb_power_limit_in_watts";

const char PLDM_BIOS_HB_SEC_VER_LOCKIN_SUPPORTED_STRING[]  = "hb_secure_ver_lockin_enabled";
const char PLDM_BIOS_HB_LID_IDS_STRING[]                   = "hb_lid_ids";
const char PLDM_BIOS_HB_TPM_REQUIRED_POLICY_STRING[]       = "hb_tpm_required_current";

const char PLDM_BIOS_PVM_FW_BOOT_SIDE_STRING[]             = "pvm_fw_boot_side";
const char PLDM_BIOS_HB_MIRROR_MEMORY_STRING[]             = "hb_memory_mirror_mode_current";

const char PLDM_BIOS_HB_KEY_CLEAR_REQUEST_STRING[]         = "hb_key_clear_request_current";
const char PLDM_BIOS_HB_KEY_CLEAR_REQUEST_STRING_PENDING[] = "hb_key_clear_request";

// Possible Values
const char PLDM_BIOS_HB_OPAL_STRING[]          = "OPAL";
const char PLDM_BIOS_HB_POWERVM_STRING[]       = "PowerVM";
const char PLDM_BIOS_ENABLED_STRING[]          = "Enabled";
const char PLDM_BIOS_DISABLED_STRING[]         = "Disabled";
const char PLDM_BIOS_128_MB_STRING[]           = "128MB";
const char PLDM_BIOS_256_MB_STRING[]           = "256MB";
const char PLDM_BIOS_PERM_STRING[]             = "Perm";
const char PLDM_BIOS_TEMP_STRING[]             = "Temp";
const char PLDM_BIOS_TPM_REQUIRED_STRING[]     = "Required";
const char PLDM_BIOS_TPM_NOT_REQUIRED_STRING[] = "Not Required";

// Possible Key Clear Request Values
const char PLDM_BIOS_KEY_CLEAR_NONE_STRING[]           = "NONE";
const char PLDM_BIOS_KEY_CLEAR_ALL_STRING[]            = "ALL";
const char PLDM_BIOS_KEY_CLEAR_OS_KEYS_STRING[]        = "OS_KEYS";
const char PLDM_BIOS_KEY_CLEAR_POWERVM_SYSKEY_STRING[] = "POWERVM_SYSKEY";
const char PLDM_BIOS_KEY_CLEAR_MFG_ALL_STRING[]        = "MFG_ALL";
const char PLDM_BIOS_KEY_CLEAR_MFG_STRING[]            = "MFG";

const std::vector<const char*> POSSIBLE_HYP_VALUE_STRINGS = {PLDM_BIOS_HB_OPAL_STRING,
                                                             PLDM_BIOS_HB_POWERVM_STRING};

const std::vector<const char*> POSSIBLE_HB_DEBUG_CONSOLE_STRINGS = {PLDM_BIOS_ENABLED_STRING,
                                                                    PLDM_BIOS_DISABLED_STRING};

const std::vector<const char*> POSSIBLE_HB_MIRROR_MEM_STRINGS = {PLDM_BIOS_ENABLED_STRING,
                                                                 PLDM_BIOS_DISABLED_STRING};

const std::vector<const char*> POSSIBLE_HB_USB_ENABLEMENT_STRINGS = {PLDM_BIOS_ENABLED_STRING,
                                                                     PLDM_BIOS_DISABLED_STRING};

const std::vector<const char*> POSSIBLE_HB_MEM_REGION_SIZE_STRINGS = {PLDM_BIOS_128_MB_STRING,
                                                                      PLDM_BIOS_256_MB_STRING};

const std::vector<const char*> POSSIBLE_HB_POWER_LIMIT_STRINGS = {PLDM_BIOS_ENABLED_STRING,
                                                                  PLDM_BIOS_DISABLED_STRING};

const std::vector<const char*> POSSIBLE_PVM_FW_BOOT_SIDE_STRINGS = {PLDM_BIOS_PERM_STRING,
                                                                    PLDM_BIOS_TEMP_STRING};

const std::vector<const char*> POSSIBLE_SEC_VER_LOCKIN_STRINGS = {PLDM_BIOS_ENABLED_STRING,
                                                                  PLDM_BIOS_DISABLED_STRING};

const std::vector<const char*> POSSIBLE_HB_KEY_CLEAR_STRINGS = { PLDM_BIOS_KEY_CLEAR_NONE_STRING,
                                                                 PLDM_BIOS_KEY_CLEAR_ALL_STRING,
                                                                 PLDM_BIOS_KEY_CLEAR_OS_KEYS_STRING,
                                                                 PLDM_BIOS_KEY_CLEAR_POWERVM_SYSKEY_STRING,
                                                                 PLDM_BIOS_KEY_CLEAR_MFG_ALL_STRING,
                                                                 PLDM_BIOS_KEY_CLEAR_MFG_STRING };

const std::vector<const char*> POSSIBLE_TPM_REQUIRED_STRINGS = {PLDM_BIOS_TPM_REQUIRED_STRING,
                                                                PLDM_BIOS_TPM_NOT_REQUIRED_STRING};

constexpr uint8_t PLDM_BIOS_STRING_TYPE_ASCII = 0x1;
constexpr uint8_t PLDM_BIOS_STRING_TYPE_HEX = 0x2;
constexpr size_t MFG_FLAGS_CONVERT_STRING_SIZE = 8;
constexpr size_t STRTOUL_BASE_VALUE_HEX = 16;


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

/* @brief Look up a string handle in the string table and decode it.
 *
 * @param[in] i_string_table   The string table. Must be populated before calling this function.
 * @param[in] i_string_handle  The string handle to look up and decode.
 * @return                     The string, if any. Empty when the string handle is not present in the table.
 */
static std::vector<char> decode_string_handle(const std::vector<uint8_t>& i_string_table, const uint16_t i_string_handle)
{
    std::vector<char> string_contents;

    const auto string_entry =
        pldm_bios_table_string_find_by_handle(i_string_table.data(), i_string_table.size(), i_string_handle);

    if (string_entry)
    {
        const uint16_t string_length = pldm_bios_table_string_entry_decode_string_length(string_entry);
        string_contents.resize(string_length + 1);
        pldm_bios_table_string_entry_decode_string(string_entry, string_contents.data(), string_contents.size());
    }

    return string_contents;
}

/** @brief Given a string describing the name of a PLDM bios attribute
*          Hostboot wants to read from the BMC, retrieve the value
*          and value type of that attribute.
*
* @param[in]     i_attr_string
*       String representing PLDM Bios attribute we want the value of.
* @param[in,out] io_attr_type
*       Type of PLDM attribute, See bios.h. On input, this param is the type
*       of bios attr we expect to be returned from the other terminus. Note
*       that Hostboot does not care if the attribute is read-only or not. If
*       the other terminus returns a read-only version of the type then set
*       this param to that type prior to returning from this function.
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
                               pldm_bios_attribute_type & io_attr_type,
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
        * @errortype
        * @moduleid   MOD_GET_CURRENT_VALUE
        * @reasoncode RC_UNSUPPORTED_ATTRIBUTE
        * @userdata1  Unused
        * @userdata2  Unused
        * @devdesc    Software problem, PLDM transaction failed
        * @custdesc   A software error occurred during system boot
        */
      errl = new ErrlEntry(ERRL_SEV_PREDICTIVE,
                           MOD_GET_CURRENT_VALUE,
                           RC_UNSUPPORTED_ATTRIBUTE,
                           0,
                           0,
                           ErrlEntry::NO_SW_CALLOUT);
      ErrlUserDetailsString(i_attr_string).addToLog(errl);
      addBmcErrorCallouts(errl);

      // Force to informational if requested by HB attribute.
      // This allows new attributes to be added while waiting
      // for the equivalent BMC BIOS attribute to be added.
      const auto sys = TARGETING::UTIL::assertGetToplevelTarget();
      if(sys->getAttr<TARGETING::ATTR_PLDM_BIOS_ERROR_INFORMATIONAL>())
      {
          errl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
      }

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
        * @errortype  ERRL_SEV_PREDICTIVE
        * @moduleid   MOD_GET_CURRENT_VALUE
        * @reasoncode RC_NO_ATTRIBUTE_MATCH
        * @userdata1  String handle we found in string table
        * @userdata2  Unused
        * @devdesc    Software problem, PLDM transaction failed
        * @custdesc   A software error occurred during system boot
        */
      errl = new ErrlEntry(ERRL_SEV_PREDICTIVE,
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

  // Bit 0 indicates if its read-only or not. Only the BMC honors read-only status
  // of bios attributes. Hostboot ignores the read-only status of bios attributes.
  const uint8_t IGNORE_READONLY = 0x7f;
  if((attr_type_found & IGNORE_READONLY) != (io_attr_type & IGNORE_READONLY))
  {
      PLDM_ERR("Attribute type as 0x%x reported when we expected 0x%x for attribute %s",
                attr_type_found,
                io_attr_type,
                i_attr_string);
      /*@
        * @errortype
        * @severity   ERRL_SEV_PREDICTIVE
        * @moduleid   MOD_GET_CURRENT_VALUE
        * @reasoncode RC_UNSUPPORTED_TYPE
        * @userdata1  Actual type returned
        * @userdata2  Expected type
        * @devdesc    Software problem, incorrect data from BMC
        * @custdesc   A software error occurred during system boot
        */
      errl = new ErrlEntry(ERRL_SEV_PREDICTIVE,
                            MOD_GET_CURRENT_VALUE,
                            RC_UNSUPPORTED_TYPE,
                            attr_type_found,
                            io_attr_type,
                            ErrlEntry::NO_SW_CALLOUT);
      ErrlUserDetailsString(i_attr_string).addToLog(errl);
      addBmcErrorCallouts(errl);
      break;
  }

  // It's possible the attribute type found was actually the read-only
  // type. If this is the case we want to return that type.
  io_attr_type = attr_type_found;

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
             io_attr_type, i_attr_string);

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
        pldm_bios_attribute_type expected_type = PLDM_BIOS_ENUMERATION;
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

/** @brief Helper function to fetch and decode the value of an enum attribute.
 *         The output will be cleared on error.
 *
 * @param[in/out] io_string_table See file brief in hb_bios_attrs.H.
 * @param[in/out] io_attr_table See file brief in hb_bios_attrs.H.
 * @param[in] i_attr_string the string representing the attribute name to fetch.
 * @param[in] i_possible_string_arr the array of all possible values that the
 *            attribute can take.
 * @param[out] o_decoded_value the decoded value of the attribute (cleared on error).
 * @return nullptr on success; non-nullptr on error.
 */
errlHndl_t getDecodedEnumAttr(std::vector<uint8_t>& io_string_table,
                              std::vector<uint8_t>& io_attr_table,
                              const char *i_attr_string,
                              const std::vector<const char*>& i_possible_string_arr,
                              std::vector<char>& o_decoded_value)
{
    errlHndl_t l_errl = nullptr;

    do {
    const pldm_bios_string_table_entry * cur_val_string_entry_ptr = nullptr;

    l_errl = systemEnumAttrLookup(io_string_table,
                                  io_attr_table,
                                  i_attr_string,
                                  cur_val_string_entry_ptr);
    if(l_errl)
    {
        PLDM_ERR("getDecodedEnumAttr: failed to lookup value for %s", i_attr_string);
        o_decoded_value.clear();
        break;
    }

    // Find the longest string that we will accept as a
    // possible value for a given PLDM BIOS attribute
    // so a sufficiently sized buffer can be allocated.
    // Add 1 byte to buffer to account for null terminator
    const auto max_possible_value_length =
         std::accumulate(i_possible_string_arr.cbegin(),
                         i_possible_string_arr.cend(),
                         0ul,
                         find_maxstrlen) + 1;

    assert(max_possible_value_length > 1, "getDecodedEnumAttr: Passed possible string vector has incorrect size");
    o_decoded_value.resize(max_possible_value_length);

    pldm_bios_table_string_entry_decode_string(cur_val_string_entry_ptr,
                                               o_decoded_value.data(),
                                               max_possible_value_length);
    } while(0);

    return l_errl;
}

errlHndl_t getDebugConsoleEnabled(std::vector<uint8_t>& io_string_table,
                                  std::vector<uint8_t>& io_attr_table,
                                  bool &o_debugConsoleEnabled)
{
    errlHndl_t errl = nullptr;
    o_debugConsoleEnabled = false;
    do{

    std::vector<char>decoded_value;
    errl = getDecodedEnumAttr(io_string_table,
                              io_attr_table,
                              PLDM_BIOS_HB_DEBUG_CONSOLE_STRING,
                              POSSIBLE_HB_DEBUG_CONSOLE_STRINGS,
                              decoded_value);
    if(errl)
    {
        PLDM_ERR("Failed to lookup value for %s", PLDM_BIOS_HB_DEBUG_CONSOLE_STRING);
        break;
    }

    if(strncmp(decoded_value.data(), PLDM_BIOS_DISABLED_STRING, decoded_value.size()) == 0)
    {
        PLDM_INF("Debug console traces are disabled by the BMC!");
        // o_debugConsoleEnabled is defaulted to false at start of function
    }
    else if(strncmp(decoded_value.data(), PLDM_BIOS_ENABLED_STRING, decoded_value.size()) == 0)
    {
        PLDM_INF("Debug console traces are enabled by the BMC!");
        o_debugConsoleEnabled = true;
    }
    else
    {
        // print the entire buffer
        PLDM_INF_BIN("Unexpected string : ",decoded_value.data(), decoded_value.size());
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
        ErrlUserDetailsString(decoded_value.data()).addToLog(errl);
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

    std::vector<char>decoded_value;
    errl = getDecodedEnumAttr(io_string_table,
                              io_attr_table,
                              PLDM_BIOS_HB_HYP_SWITCH_STRING,
                              POSSIBLE_HYP_VALUE_STRINGS,
                              decoded_value);
    if(errl)
    {
        PLDM_ERR("Failed to lookup value for %s", PLDM_BIOS_HB_HYP_SWITCH_STRING);
        break;
    }

    if(strncmp(decoded_value.data(), PLDM_BIOS_HB_POWERVM_STRING, decoded_value.size()) == 0)
    {
        PLDM_INF("Power VM hypervisor found!");
        o_payloadType = TARGETING::PAYLOAD_KIND_PHYP;
    }
    else if(strncmp(decoded_value.data(), PLDM_BIOS_HB_OPAL_STRING, decoded_value.size()) == 0)
    {
        PLDM_INF("Opal hypervisor found!");
        o_payloadType = TARGETING::PAYLOAD_KIND_SAPPHIRE;
    }
    else
    {
        // print the entire buffer
        PLDM_INF_BIN("Unexpected string : ",decoded_value.data(), decoded_value.size());
        o_payloadType = TARGETING::PAYLOAD_KIND_INVALID;
    }

    }while(0);

    return errl;
}

/** @brief Given the string representing a PLDM BIOS attribute of type integer,
 *         get the integer value of this attribute from the BMC
 *
 * @param[in,out] io_string_table
 *       See file brief in hb_bios_attrs.H.
 * @param[in,out] io_attr_table
 *       See file brief in hb_bios_attrs.H.
 * @param[in] i_attr_string
 *       String representing the attribute we are looking up on the BMC.
 * @param[out] o_attr_val
 *       Integer value found in the BMC's return data.
 *
 * @return Error if any, otherwise nullptr.
 */
errlHndl_t systemIntAttrLookup(
        std::vector<uint8_t>& io_string_table,
        std::vector<uint8_t>& io_attr_table,
        const char *i_attr_string,
        uint64_t& o_attr_val)
{
    errlHndl_t errl = nullptr;

    do{

    // Init the output value
    o_attr_val = 0;

    // Get the bios attribute info from the attr table
    pldm_bios_attribute_type expected_type = PLDM_BIOS_INTEGER;
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

    // pldm functions are little endian
    // convert to big endian before returning
    o_attr_val = *reinterpret_cast<uint64_t*>(attr_value.data());
    o_attr_val = le64toh(o_attr_val);

    } while(0);

    return errl;
}

errlHndl_t getHugePageCount(
        std::vector<uint8_t>& io_string_table,
        std::vector<uint8_t>& io_attr_table,
        TARGETING::ATTR_HUGE_PAGE_COUNT_type &o_hugePageCount)
{
    errlHndl_t errl = nullptr;

    do{

        uint64_t l_attr_val = 0;
        errl = systemIntAttrLookup(io_string_table,
                                   io_attr_table,
                                   PLDM_BIOS_HB_HUGE_PAGE_COUNT_STRING,
                                   l_attr_val);
        if(errl)
        {
            PLDM_ERR("getHugePageCount() Failed to lookup value for %s",
                     PLDM_BIOS_HB_HUGE_PAGE_COUNT_STRING);
            break;
        }

        o_hugePageCount = l_attr_val;

    } while(0);

    return errl;
}

errlHndl_t getHugePageSize(
        std::vector<uint8_t>& io_string_table,
        std::vector<uint8_t>& io_attr_table,
        TARGETING::ATTR_HUGE_PAGE_SIZE_type &o_hugePageSize)
{
    errlHndl_t errl = nullptr;

    do{

        uint64_t l_attr_val = 0;
        errl = systemIntAttrLookup(io_string_table,
                                   io_attr_table,
                                   PLDM_BIOS_HB_HUGE_PAGE_SIZE_STRING,
                                   l_attr_val);
        if(errl)
        {
            PLDM_ERR("getHugePageSize() Failed to lookup value for %s",
                     PLDM_BIOS_HB_HUGE_PAGE_SIZE_STRING);
            break;
        }

        o_hugePageSize = static_cast<TARGETING::ATTR_HUGE_PAGE_SIZE_type>(l_attr_val);

    } while(0);

    return errl;
}

errlHndl_t getLmbSize(
        std::vector<uint8_t>& io_string_table,
        std::vector<uint8_t>& io_attr_table,
        TARGETING::ATTR_LMB_SIZE_type &o_lmbSize)
{
    errlHndl_t errl = nullptr;

    do {

    std::vector<char>decoded_value;
    errl = getDecodedEnumAttr(io_string_table,
                              io_attr_table,
                              PLDM_BIOS_HB_LMB_SIZE_STRING,
                              POSSIBLE_HB_MEM_REGION_SIZE_STRINGS,
                              decoded_value);
    if(errl)
    {
        PLDM_ERR("getLmbSize() Failed to lookup enum value for %s",
                 PLDM_BIOS_HB_LMB_SIZE_STRING);

        if ((errl->moduleId() != MOD_GET_CURRENT_VALUE) ||
            (errl->reasonCode() != RC_UNSUPPORTED_TYPE))
        {
            break;
        }

        // Found bios attr but not enum type, make the error informational
        const auto sys = TARGETING::UTIL::assertGetToplevelTarget();
        if(sys->getAttr<TARGETING::ATTR_PLDM_BIOS_ERROR_INFORMATIONAL>())
        {
            errl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
        }

        // Commit the error and try int type
        ERRORLOG::errlCommit(errl, PLDM_COMP_ID);

        uint64_t l_attr_val = 0;
        errl = systemIntAttrLookup(io_string_table,
                                   io_attr_table,
                                   PLDM_BIOS_HB_LMB_SIZE_STRING,
                                   l_attr_val);
        if(errl)
        {
            PLDM_ERR("getLmbSize() Failed to lookup int value for %s",
                     PLDM_BIOS_HB_LMB_SIZE_STRING);
            break;
        }

        // Set size and exit
        o_lmbSize = l_attr_val;
        break;
    }

    if(strncmp(decoded_value.data(), PLDM_BIOS_128_MB_STRING, decoded_value.size()) == 0)
    {
        PLDM_INF("Memory region size set to 128MB by the BMC");
        o_lmbSize = LMB_SIZE_ENCODE_128MB;
    }
    else if(strncmp(decoded_value.data(), PLDM_BIOS_256_MB_STRING, decoded_value.size()) == 0)
    {
        PLDM_INF("Memory region size set to 256MB by the BMC");
        o_lmbSize = LMB_SIZE_ENCODE_256MB;
    }
    else
    {
        // Print the entire buffer
        PLDM_INF_BIN("Unexpected string : ",decoded_value.data(), decoded_value.size());
        /*@
          * @errortype
          * @severity   ERRL_SEV_UNRECOVERABLE
          * @moduleid   MOD_GET_LMB_SIZE
          * @reasoncode RC_UNSUPPORTED_TYPE
          * @userdata1  Unused
          * @userdata2  Unused
          * @devdesc    Software problem, incorrect data from BMC
          * @custdesc   A software error occurred during system boot
          */
        errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                             MOD_GET_LMB_SIZE,
                             RC_UNSUPPORTED_TYPE,
                             0,
                             0,
                             ErrlEntry::NO_SW_CALLOUT);
        ErrlUserDetailsString(PLDM_BIOS_HB_LMB_SIZE_STRING).addToLog(errl);
        ErrlUserDetailsString(decoded_value.data()).addToLog(errl);
        addBmcErrorCallouts(errl);
        break;
    }

    } while(0);

    return errl;
}


/** @brief Given the string representing a PLDM BIOS attribute of type string,
 *         get string entry returned as the value of this attribute by the BMC
 *
 * @param[in,out] io_string_table
 *       See file brief in hb_bios_attrs.H.
 * @param[in,out] io_attr_table
 *       See file brief in hb_bios_attrs.H.
 * @param[in] i_attr_string
 *       String representing the attribute we are looking up on the BMC.
 * @param[out] o_string_type
 *       Type of string returned: ASCII / Hex / UTF
 * @param[out] o_attr_val_string
 *       Vector containing string value of requested attribute
 *
 * @return Error if any, otherwise nullptr.
 */
errlHndl_t systemStringAttrLookup(std::vector<uint8_t>& io_string_table,
                                  std::vector<uint8_t>& io_attr_table,
                                  const char *i_attr_string,
                                  uint8_t& o_string_type,
                                  std::vector<char>& o_attr_val_string)
{
    errlHndl_t errl = nullptr;

    do{

    // Get the attribute info from the attr table
    pldm_bios_attribute_type expected_type = PLDM_BIOS_STRING;
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
        PLDM_ERR(
            "An error occurred while requesting the value of %s from the BMC",
            i_attr_string)
        break;
    }

    // Get the type of string data in the bios attribute
    // Unknown=0x00, ASCII=0x01, Hex=0x02, UTF-8=0x03,
    // UTF-16LE=0x04, UTF-16BE=0x05, Vendor Specific=0xFF
    o_string_type =
        pldm_bios_table_attr_entry_string_decode_string_type(
            attr_entry_ptr);

    // Size is the first 2 bytes of the data
    // Little endian so swap bytes
    uint16_t stringLength = (attr_value[1] << 8) | attr_value[0];

    bool useDefault = false;

    // If string is not set get the default
    if (stringLength == 0)
    {
        // Get the default string length of the bios attribute
        stringLength =
            pldm_bios_table_attr_entry_string_decode_def_string_length(
                attr_entry_ptr);
        useDefault = true;
    }

    // If the input vector is not large enough then resize it
    // Input vector includes null terminator so add 1
    if (o_attr_val_string.size() < size_t(stringLength + 1))
    {
        PLDM_INF("systemStringAttrLookup: resizing input vector from %d to %d",
                 o_attr_val_string.size(), stringLength);
        o_attr_val_string.resize(stringLength + 1);
    }

    if (useDefault)
    {
        // Get the default string of the bios attribute
        pldm_bios_table_attr_entry_string_decode_def_string(
            attr_entry_ptr,
            o_attr_val_string.data(),
            o_attr_val_string.size());
    }
    else
    {
        // Copy the string, first two bytes are the size
        // so string data starts at byte 2
        strncpy(o_attr_val_string.data(),
                reinterpret_cast<const char*>(attr_value.data()+2),
                stringLength);
    }

    }while(0);

    return errl;
}

// getFieldCoreOverride
errlHndl_t
getFieldCoreOverride( std::vector<uint8_t>& io_string_table,
                      std::vector<uint8_t>& io_attr_table,
                      TARGETING::ATTR_FIELD_CORE_OVERRIDE_type &o_fieldCoreOverride)
{
    PLDM_ENTER("getFieldCoreOverride(): %s", PLDM_BIOS_HB_FIELD_CORE_OVERRIDE_STRING);

    errlHndl_t l_errl = nullptr;

    // Zero out the FCO value before continuing
    o_fieldCoreOverride = 0;

    do
    {
        // Create a variable to hold the retrieved BMC bios value
        uint64_t l_retrievedBmcAttributeValue = 0;

        l_errl = systemIntAttrLookup( io_string_table,
                                      io_attr_table,
                                      PLDM_BIOS_HB_FIELD_CORE_OVERRIDE_STRING,
                                      l_retrievedBmcAttributeValue);

        if (l_errl)
        {
            PLDM_ERR( "getFieldCoreOverride(): Failed to retrieve the Field Core "
                      "Override (FCO) from the BMC bios %s",
                      PLDM_BIOS_HB_FIELD_CORE_OVERRIDE_STRING );
            break;
        }

        PLDM_INF( "getFieldCoreOverride(): Call to systemIntAttrLookup succeeded. FCO %d",
                  l_retrievedBmcAttributeValue );

        // Return the value with the correct type
        o_fieldCoreOverride = static_cast<TARGETING::ATTR_FIELD_CORE_OVERRIDE_type>
                              (l_retrievedBmcAttributeValue);
    } while(0);

    PLDM_EXIT("getFieldCoreOverride(): returning FCO %d", o_fieldCoreOverride);

    return l_errl;
} // getFieldCoreOverride
#ifdef CONFIG_INCLUDE_XML_OPPOWERVM
errlHndl_t getBootside(std::vector<uint8_t>                     & io_string_table,
                       std::vector<uint8_t>                     & io_attr_table,
                       TARGETING::ATTR_HYPERVISOR_IPL_SIDE_type & o_bootside)
{
    errlHndl_t errl = nullptr;
    do{

    std::vector<char>decoded_value;

    errl = getDecodedEnumAttr(io_string_table,
                              io_attr_table,
                              PLDM_BIOS_PVM_FW_BOOT_SIDE_STRING,
                              POSSIBLE_PVM_FW_BOOT_SIDE_STRINGS,
                              decoded_value);
    if(errl)
    {
        PLDM_ERR("Failed to lookup value for %s", PLDM_BIOS_PVM_FW_BOOT_SIDE_STRING);
        break;
    }

    if(strncmp(decoded_value.data(), PLDM_BIOS_PERM_STRING, decoded_value.size()) == 0)
    {
        PLDM_INF("Booting from %s side!", PLDM_BIOS_PERM_STRING);
        CONSOLE::displayf(CONSOLE::DEFAULT, NULL, "Booting from %s side.", PLDM_BIOS_PERM_STRING);
        o_bootside = TARGETING::HYPERVISOR_IPL_SIDE_PERM;
    }
    else if(strncmp(decoded_value.data(), PLDM_BIOS_TEMP_STRING, decoded_value.size()) == 0)
    {
        PLDM_INF("Booting from %s side!", PLDM_BIOS_TEMP_STRING);
        CONSOLE::displayf(CONSOLE::DEFAULT, NULL, "Booting from %s side.", PLDM_BIOS_TEMP_STRING);
        o_bootside = TARGETING::HYPERVISOR_IPL_SIDE_TEMP;
    }
    else
    {
        // print the entire buffer
        PLDM_INF_BIN("Unexpected string: ",decoded_value.data(), decoded_value.size());
        o_bootside = TARGETING::HYPERVISOR_IPL_SIDE_INVALID;
    }

    }while(0);

    return errl;
}
#endif
errlHndl_t getBootside(std::vector<uint8_t>   & io_string_table,
                       std::vector<uint8_t>   & io_attr_table,
                       pldm_fileio_file_type  & o_bootside)
{
    errlHndl_t errl = nullptr;
    do{

    std::vector<char>decoded_value;

    errl = getDecodedEnumAttr(io_string_table,
                              io_attr_table,
                              PLDM_BIOS_PVM_FW_BOOT_SIDE_STRING,
                              POSSIBLE_PVM_FW_BOOT_SIDE_STRINGS,
                              decoded_value);
    if(errl)
    {
        PLDM_ERR("Failed to lookup value for %s", PLDM_BIOS_PVM_FW_BOOT_SIDE_STRING);
        break;
    }

    if(strncmp(decoded_value.data(), PLDM_BIOS_PERM_STRING, decoded_value.size()) == 0)
    {
        o_bootside = PLDM_FILE_TYPE_LID_PERM;
    }
    else if(strncmp(decoded_value.data(), PLDM_BIOS_TEMP_STRING, decoded_value.size()) == 0)
    {
        o_bootside = PLDM_FILE_TYPE_LID_TEMP;
    }
    else
    {
        // print the entire buffer
        PLDM_INF_BIN("Unexpected string: ",decoded_value.data(), decoded_value.size());
        // Set to an invalid value, PLDM_FILE_TYPE_PEL = 0 and is
        // invalid for hostboot's use case.
        o_bootside = PLDM_FILE_TYPE_PEL;
    }

    }while(0);

    return errl;
}


struct pnor_lid_mapping_t
{
    PNOR::SectionId section_id;
    uint32_t lid_id;
};

/** @brief Validate the contents of the parsed pnor to lid mapping
*
* @details This method will check that the section id and lid id found
*          when parsing the hb_lid_ids attribute make sense.
*
* @param[in]  i_mapping               SectionId to Lid Id mapping to check
* @param[in,out] io_pnorToLidMappings An array of length PNOR::NUM_SECTIONS
*                                     that this function will update any lid
*                                     id mappings it finds in if the mapping
*                                     is valid.
*
* @return Errorlog is an error occurred, otherwise nullptr on success
*/
void checkPnorToLidMapping(const pnor_lid_mapping_t & i_mapping,
                           std::array<uint32_t, PNOR::NUM_SECTIONS>& io_pnorToLidMappings)
{
    const uint32_t MIN_LID_ID_NUM = 0x80000000;
    do{
        if(i_mapping.section_id >= PNOR::INVALID_SECTION)
        {
            // Skip entries who we could not translate
            PLDM_ERR("checkPnorToLidMapping: Could not find SectionId for entry with lidId %x so we will discard the map entry",
                      i_mapping.lid_id);
            break;
        }
        else if( i_mapping.lid_id < MIN_LID_ID_NUM )
        {
            PLDM_ERR("checkPnorToLidMapping: Invalid lid_id %lx", i_mapping.lid_id);
            // This likely indicates a parsing problem. All valid lids ids
            // should have first bit set. Commit a visible error but go ahead
            // and attempt to use the lid
            /*@
              * @errortype
              * @severity   ERRL_SEV_PREDICTIVE
              * @moduleid   MOD_GET_LID_IDS
              * @reasoncode RC_INVALID_LID_ID
              * @userdata1  Lid Id Found
              * @userdata2  Section Id Found
              * @devdesc    Software problem, incorrect data from BMC
              * @custdesc   A software error occurred during system boot
              */
            errlHndl_t errl = new ErrlEntry(ERRL_SEV_PREDICTIVE,
                                MOD_GET_LID_IDS,
                                RC_INVALID_LID_ID,
                                i_mapping.lid_id,
                                i_mapping.section_id,
                                ErrlEntry::NO_SW_CALLOUT);
            ErrlUserDetailsString(PLDM_BIOS_HB_LID_IDS_STRING).addToLog(errl);
            addBmcErrorCallouts(errl);
            errlCommit(errl, PLDM_COMP_ID);
            break;
        }
        // if we pass the checks above add i_mapping.lid_id to
        // io_pnorToLidMappings which is returned as an out param
        io_pnorToLidMappings[i_mapping.section_id] = i_mapping.lid_id;
        PLDM_INF("checkPnorToLidMapping: %s = %lx ", PNOR::SectionIdToString(i_mapping.section_id) , i_mapping.lid_id);
    }while(0);
}

errlHndl_t getLidIds(std::vector<uint8_t>& io_string_table,
                      std::vector<uint8_t>& io_attr_table,
                      std::array<uint32_t, PNOR::NUM_SECTIONS>& io_pnorToLidMappings)
{
    errlHndl_t errl = nullptr;
    do {

    constexpr uint32_t INVALID_LID = 0xffffffff;
    for(auto &entry : io_pnorToLidMappings)
    {
        entry = INVALID_LID;
    }

    uint8_t bios_string_type = 0;
    std::vector<char> lid_ids_string;
    // Get the ascii string value from the BMC
    errl = systemStringAttrLookup(io_string_table,
                                  io_attr_table,
                                  PLDM_BIOS_HB_LID_IDS_STRING,
                                  bios_string_type,
                                  lid_ids_string);

    if(errl)
    {
        PLDM_ERR("getLidIds: Failed to lookup value for %s", PLDM_BIOS_HB_LID_IDS_STRING);
        break;
    }
    // Check for string type == 0x01 ASCII
    if (bios_string_type != PLDM_BIOS_STRING_TYPE_ASCII)
    {
        PLDM_ERR("getLidIds: Unexpected string type 0x%X for %s",
                 bios_string_type, PLDM_BIOS_HB_LID_IDS_STRING);
        /*@
          * @errortype
          * @severity   ERRL_SEV_PREDICTIVE
          * @moduleid   MOD_GET_LID_IDS
          * @reasoncode RC_UNSUPPORTED_STRING_TYPE
          * @userdata1  Expected String Type
          * @userdata2  Returned String Type
          * @devdesc    Software problem, incorrect data from BMC
          * @custdesc   A software error occurred during system boot
          */
        errl = new ErrlEntry(ERRL_SEV_PREDICTIVE,
                             MOD_GET_LID_IDS,
                             RC_UNSUPPORTED_STRING_TYPE,
                             PLDM_BIOS_STRING_TYPE_ASCII,
                             bios_string_type,
                             ErrlEntry::NO_SW_CALLOUT);
        ErrlUserDetailsString(PLDM_BIOS_HB_LID_IDS_STRING).addToLog(errl);
        addBmcErrorCallouts(errl);
        break;
    }

    // setup some working variables which will be used
    // in the for-loop below
    std::vector<char> eyecatch, lid_id;
    pnor_lid_mapping_t mapping = {PNOR::INVALID_SECTION, 0};

    // We will fill this vector with all mappings we
    // parse from the hb_lid_ids attribute value
    std::vector<pnor_lid_mapping_t> mappings_found;

    // parse a string of the format:
    //   <EYECATCH_a>=<lid_id_1>,<EYECATCH_b>=<lid_id_2>
    for(size_t i = 0; i < lid_ids_string.size(); i++)
    {
        char c = lid_ids_string[i];
        switch(c)
        {
            case '=' :
                eyecatch.push_back('\0');
                // lookup eyecatch string's SectionId mapping and
                // set it in the mapping struct we are using to
                //  fill mappings_found
                for(uint32_t eye_index=PNOR::FIRST_SECTION;
                    eye_index < PNOR::NUM_SECTIONS;
                    eye_index++)
                    {
                        if(strcmp(PNOR::SectionIdToString(eye_index), eyecatch.data()) == 0)
                        {
                            mapping.section_id = static_cast<PNOR::SectionId>(eye_index);
                            break;
                        }
                    }
                break;
            case ',' :
                lid_id.push_back('\0');
                mapping.lid_id = strtoul(lid_id.data(), nullptr, STRTOUL_BASE_VALUE_HEX);
                checkPnorToLidMapping(mapping, io_pnorToLidMappings);
                // reset working variables
                eyecatch.clear();
                lid_id.clear();
                mapping = {PNOR::INVALID_SECTION, 0};
                break;
            default :
                if(eyecatch.size() == 0 ||
                   eyecatch.back() != '\0')
                {
                    eyecatch.push_back(c);
                }
                else
                {
                    lid_id.push_back(c);
                }
                break;
        }
    }

    // catch the case where the list of entries was not terminated by ','
    if(eyecatch.size() && lid_id.size())
    {
        lid_id.push_back('\0');
        mapping.lid_id = strtoul(lid_id.data(), nullptr, STRTOUL_BASE_VALUE_HEX);
        checkPnorToLidMapping(mapping, io_pnorToLidMappings);
    }

    }while(0);

    return errl;
}

errlHndl_t getMfgFlags(std::vector<uint8_t>& io_string_table,
                       std::vector<uint8_t>& io_attr_table,
                       TARGETING::ATTR_MFG_FLAGS_typeStdArr &o_mfgFlags)
{
    errlHndl_t errl = nullptr;

    do{

    size_t array_size = o_mfgFlags.size();
    size_t bios_string_size = 0;
    uint8_t bios_string_type = 0;
    std::vector<char> mfg_flags_string;

    // Set the size of the vector to store the BMC mfg flags
    // 8 Hex string characters represents 4 bytes of data
    // Times 4 entries in the array
    // Equals 32 characters / 16 bytes / 128 bits of mfg flag attribute data
    // Add a byte for the null terminator
    bios_string_size = MFG_FLAGS_CONVERT_STRING_SIZE * array_size + 1;
    mfg_flags_string.resize(bios_string_size);

    // Get the hex string value from the BMC
    errl = systemStringAttrLookup(io_string_table,
                                    io_attr_table,
                                    PLDM_BIOS_HB_MFG_FLAGS_STRING,
                                    bios_string_type,
                                    mfg_flags_string);
    if(errl)
    {
        PLDM_ERR("Failed to lookup value for %s",
                    PLDM_BIOS_HB_MFG_FLAGS_STRING);
        break;
    }

    // Check for string type == 0x02 Hex
    if (bios_string_type != PLDM_BIOS_STRING_TYPE_HEX)
    {
        PLDM_ERR("Unexpected string type 0x%X for %s",
                 bios_string_type, PLDM_BIOS_HB_MFG_FLAGS_STRING);
        /*@
          * @errortype
          * @severity   ERRL_SEV_PREDICTIVE
          * @moduleid   MOD_GET_MFG_FLAGS
          * @reasoncode RC_UNSUPPORTED_STRING_TYPE
          * @userdata1  Expected String Type
          * @userdata2  Returned String Type
          * @devdesc    Software problem, incorrect data from BMC
          * @custdesc   A software error occurred during system boot
          */
        errl = new ErrlEntry(ERRL_SEV_PREDICTIVE,
                             MOD_GET_MFG_FLAGS,
                             RC_UNSUPPORTED_STRING_TYPE,
                             PLDM_BIOS_STRING_TYPE_HEX,
                             bios_string_type,
                             ErrlEntry::NO_SW_CALLOUT);
        ErrlUserDetailsString(PLDM_BIOS_HB_MFG_FLAGS_STRING).addToLog(errl);
        addBmcErrorCallouts(errl);
        break;
    }

    // Check the string size against original, it may have been resized
    if (mfg_flags_string.size() != bios_string_size)
    {
        PLDM_ERR("BMC attr size %d does not match HB attr size %d",
                 mfg_flags_string.size(), bios_string_size);
        /*@
          * @errortype
          * @severity   ERRL_SEV_PREDICTIVE
          * @moduleid   MOD_GET_MFG_FLAGS
          * @reasoncode RC_UNEXPECTED_STRING_SIZE
          * @userdata1  Expected string size
          * @userdata2  Returned string size
          * @devdesc    Software problem, incorrect data from BMC
          * @custdesc   A software error occurred during system boot
          */
        errl = new ErrlEntry(ERRL_SEV_PREDICTIVE,
                             MOD_GET_MFG_FLAGS,
                             RC_UNEXPECTED_STRING_SIZE,
                             bios_string_size,
                             mfg_flags_string.size(),
                             ErrlEntry::NO_SW_CALLOUT);
        ErrlUserDetailsString(PLDM_BIOS_HB_MFG_FLAGS_STRING).addToLog(errl);
        addBmcErrorCallouts(errl);
        break;
    }

    // Convert the hex string to regular hex data
    // Full string is 32 characters, representing 16 bytes
    // strtoul can convert up to 8 bytes at a time (uint64_t)
    // Convert 4 bytes at a time, add 1 for null terminator
    char tmp_str[MFG_FLAGS_CONVERT_STRING_SIZE+1] = {};

    for(uint32_t idx=0; idx<array_size; idx++)
    {
        strncpy(tmp_str,
                &mfg_flags_string[idx * MFG_FLAGS_CONVERT_STRING_SIZE],
                MFG_FLAGS_CONVERT_STRING_SIZE);
        o_mfgFlags[idx] = strtoul(tmp_str, nullptr, STRTOUL_BASE_VALUE_HEX);
    }

    }while(0);

    return errl;
}

errlHndl_t getUsbEnablement(
        std::vector<uint8_t>& io_string_table,
        std::vector<uint8_t>& io_attr_table,
        TARGETING::ATTR_USB_SECURITY_type &o_usbEnablement)
{
    errlHndl_t errl = nullptr;

    do {

    // Enable Attribute
    std::vector<char> decoded_value;

    errl = getDecodedEnumAttr(io_string_table,
                              io_attr_table,
                              PLDM_BIOS_HB_USB_ENABLEMENT_STRING,
                              POSSIBLE_HB_USB_ENABLEMENT_STRINGS,
                              decoded_value);

    if (errl)
    {
        PLDM_ERR("Failed to lookup value for %s",
                 PLDM_BIOS_HB_USB_ENABLEMENT_STRING);
        break;
    }

    if (strncmp(decoded_value.data(), PLDM_BIOS_DISABLED_STRING, decoded_value.size()) == 0)
    {
        o_usbEnablement = static_cast<TARGETING::ATTR_USB_SECURITY_type>(false);
        PLDM_INF("USB Enablement disabled by BMC PLDM BIOS attribute");
    }
    else if (strncmp(decoded_value.data(), PLDM_BIOS_ENABLED_STRING, decoded_value.size()) == 0)
    {
        o_usbEnablement = static_cast<TARGETING::ATTR_USB_SECURITY_type>(true);
        PLDM_INF("USB Enablement enabled by BMC PLDM BIOS attribute");
    }
    else
    {
        // print the entire buffer
        PLDM_INF_BIN("Unexpected string : ",decoded_value.data(), decoded_value.size());
        /*@
          * @errortype
          * @severity   ERRL_SEV_UNRECOVERABLE
          * @moduleid   MOD_GET_USB_ENABLEMENT
          * @reasoncode RC_UNSUPPORTED_TYPE
          * @userdata1  Unused
          * @userdata2  Unused
          * @devdesc    Software problem, incorrect data from BMC
          * @custdesc   A software error occurred during system boot
          */
        errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                             MOD_GET_USB_ENABLEMENT,
                             RC_UNSUPPORTED_TYPE,
                             0,
                             0,
                             ErrlEntry::NO_SW_CALLOUT);
        ErrlUserDetailsString(PLDM_BIOS_HB_USB_ENABLEMENT_STRING).addToLog(errl);
        ErrlUserDetailsString(decoded_value.data()).addToLog(errl);
        addBmcErrorCallouts(errl);
        break;
    }

    } while(0);

    return errl;
}

errlHndl_t getMirrorMemory(
        std::vector<uint8_t>& io_string_table,
        std::vector<uint8_t>& io_attr_table,
        TARGETING::ATTR_PAYLOAD_IN_MIRROR_MEM_type &o_mirrorMem)
{
    errlHndl_t errl = nullptr;

    do {

    // Enable Attribute
    std::vector<char> decoded_value;

    errl = getDecodedEnumAttr(io_string_table,
                              io_attr_table,
                              PLDM_BIOS_HB_MIRROR_MEMORY_STRING,
                              POSSIBLE_HB_MIRROR_MEM_STRINGS,
                              decoded_value);

    if (errl)
    {
        PLDM_ERR("Failed to lookup value for %s",
                 PLDM_BIOS_HB_MIRROR_MEMORY_STRING);
        break;
    }

    if (strncmp(decoded_value.data(), PLDM_BIOS_DISABLED_STRING, decoded_value.size()) == 0)
    {
        o_mirrorMem = static_cast<TARGETING::ATTR_PAYLOAD_IN_MIRROR_MEM_type>(false);
        PLDM_INF("Memory Mirror disabled by BMC PLDM BIOS attribute");
    }
    else if (strncmp(decoded_value.data(), PLDM_BIOS_ENABLED_STRING, decoded_value.size()) == 0)
    {
        o_mirrorMem = static_cast<TARGETING::ATTR_PAYLOAD_IN_MIRROR_MEM_type>(true);
        PLDM_INF("Memory Mirror enabled by BMC PLDM BIOS attribute");
    }
    else
    {
        // print the entire buffer
        PLDM_INF_BIN("Unexpected string : ",decoded_value.data(), decoded_value.size());
        /*@
          * @errortype
          * @severity   ERRL_SEV_UNRECOVERABLE
          * @moduleid   MOD_GET_MIRROR_MEMORY
          * @reasoncode RC_UNSUPPORTED_TYPE
          * @userdata1  Unused
          * @userdata2  Unused
          * @devdesc    Software problem, incorrect data from BMC
          * @custdesc   A software error occurred during system boot
          */
        errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                             MOD_GET_MIRROR_MEMORY,
                             RC_UNSUPPORTED_TYPE,
                             0,
                             0,
                             ErrlEntry::NO_SW_CALLOUT);
        ErrlUserDetailsString(PLDM_BIOS_HB_MIRROR_MEMORY_STRING).addToLog(errl);
        ErrlUserDetailsString(decoded_value.data()).addToLog(errl);
        addBmcErrorCallouts(errl);
        break;
    }

    } while(0);

    return errl;
}

errlHndl_t getKeyClearRequest(std::vector<uint8_t>& io_string_table,
                              std::vector<uint8_t>& io_attr_table,
                              TARGETING::ATTR_KEY_CLEAR_REQUEST_type &o_key_clear_request)
{
    errlHndl_t errl = nullptr;
    o_key_clear_request = TARGETING::KEY_CLEAR_REQUEST_INVALID;

    do{

    std::vector<char>decoded_value;

    errl = getDecodedEnumAttr(io_string_table,
                              io_attr_table,
                              PLDM_BIOS_HB_KEY_CLEAR_REQUEST_STRING,
                              POSSIBLE_HB_KEY_CLEAR_STRINGS,
                              decoded_value);
    if(errl)
    {
        PLDM_ERR("Failed to lookup value for %s", PLDM_BIOS_HB_KEY_CLEAR_REQUEST_STRING);
        break;
    }

    std::map<const char*, TARGETING::KEY_CLEAR_REQUEST> const bios_to_hb_key_clear_map = {
                           {PLDM_BIOS_KEY_CLEAR_NONE_STRING, TARGETING::KEY_CLEAR_REQUEST_NONE},
                           {PLDM_BIOS_KEY_CLEAR_ALL_STRING, TARGETING::KEY_CLEAR_REQUEST_ALL},
                           {PLDM_BIOS_KEY_CLEAR_OS_KEYS_STRING, TARGETING::KEY_CLEAR_REQUEST_OS_KEYS},
                           {PLDM_BIOS_KEY_CLEAR_POWERVM_SYSKEY_STRING, TARGETING::KEY_CLEAR_REQUEST_POWERVM_SYSKEY},
                           {PLDM_BIOS_KEY_CLEAR_MFG_ALL_STRING, TARGETING::KEY_CLEAR_REQUEST_MFG_ALL},
                           {PLDM_BIOS_KEY_CLEAR_MFG_STRING, TARGETING::KEY_CLEAR_REQUEST_MFG}
                         };
    // iterate over the map
    for (const auto pair : bios_to_hb_key_clear_map)
    {
        if(strncmp(decoded_value.data(), pair.first, decoded_value.size()) == 0)
        {
            PLDM_INF("Found BMC PLDM BIOS attribute Key Clear Request: %s", decoded_value.data());
            o_key_clear_request = pair.second;
            break;
        }
    }

    // if a valid BIOS val isn't found in the map, create an error
    if (o_key_clear_request == TARGETING::KEY_CLEAR_REQUEST_INVALID)
    {
        // print the entire buffer
        PLDM_INF_BIN("Unexpected string : ", decoded_value.data(), decoded_value.size());
        /*@
          * @errortype
          * @severity   ERRL_SEV_UNRECOVERABLE
          * @moduleid   MOD_GET_KEY_CLEAR_REQUEST
          * @reasoncode RC_UNSUPPORTED_TYPE
          * @userdata1  Unused
          * @userdata2  Unused
          * @devdesc    Software problem, incorrect data from BMC
          * @custdesc   A software error occurred during system boot
          */
        errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                             MOD_GET_KEY_CLEAR_REQUEST,
                             RC_UNSUPPORTED_TYPE,
                             0,
                             0,
                             ErrlEntry::NO_SW_CALLOUT);
        ErrlUserDetailsString(PLDM_BIOS_HB_KEY_CLEAR_REQUEST_STRING).addToLog(errl);
        ErrlUserDetailsString(decoded_value.data()).addToLog(errl);
        addBmcErrorCallouts(errl);
        break;
    }


    }while(0);

    return errl;
}

errlHndl_t setBiosIntegerAttrValue(std::vector<uint8_t>& io_string_table,
                                   std::vector<uint8_t>& io_attr_table,
                                   const char *i_attr_string,
                                   uint64_t i_attr_value)
{
    errlHndl_t errl = nullptr;
    do {

    errl = ensureTablesAreSet(io_string_table, io_attr_table);
    if (errl)
    {
        PLDM_ERR("setBiosIntegerValue: An error occured when attempting to populate the bios tables");
        break;
    }

    pldm_bios_attribute_type expected_type = PLDM_BIOS_INTEGER;
    const pldm_bios_attr_table_entry * attr_entry_ptr = nullptr;
    std::vector<uint8_t> attr_value;

    // get attr_entry_ptr for the passed i_attr_string
    errl = getCurrentAttrValue(i_attr_string,
                               expected_type,
                               io_string_table,
                               io_attr_table,
                               attr_entry_ptr,
                               attr_value);
    if(errl)
    {
        PLDM_ERR("setBiosIntegerValue: An error occurred while requesting the value of %s from the BMC",
                 i_attr_string)
        break;
    }
    auto entry_fields =
        reinterpret_cast<const attr_table_integer_entry_fields*>(attr_entry_ptr->metadata);

    if(i_attr_value > entry_fields->upper_bound ||
       i_attr_value < entry_fields->lower_bound)
    {
        PLDM_ERR("setBiosIntegerValue: The value for %s we tried to write, %ld, is out of range."
                 " The maximum allowed = 0x%ld and the minimum allowed = %ld",
                 i_attr_string,
                 i_attr_value,
                 entry_fields->upper_bound,
                 entry_fields->lower_bound);
        /*@
         * @errortype
         * @severity   ERRL_SEV_UNRECOVERABLE
         * @moduleid   MOD_SET_BIOS_ATTR_INTEGER_VALUE
         * @reasoncode RC_OUT_OF_RANGE
         * @userdata1  Ascii representation of the bios attr to set
         * @userdata2  Value hb is attempting to set the attr with
         * @devdesc    Value we are trying to set BIOS attr with is
         *             out of acceptable range of values.
         * @custdesc   A software error occurred during system boot.
         */
        errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                             MOD_SET_BIOS_ATTR_INTEGER_VALUE,
                             RC_OUT_OF_RANGE,
                             *reinterpret_cast<const uint64_t *>(i_attr_string),
                             i_attr_value,
                             ErrlEntry::NO_SW_CALLOUT);
        addBmcErrorCallouts(errl);
        break;
    }

    // set the BIOS attr to the new value
    const auto attr_handle = pldm_bios_table_attr_entry_decode_attribute_handle(attr_entry_ptr);
    // Make sure the integer value we pass is little-endian
    const auto attr_value_le = htole64(i_attr_value);
    errl = setBiosAttrByHandle(attr_handle, expected_type,
                               &attr_value_le, sizeof(attr_value_le));
    if(errl)
    {
        PLDM_ERR("setBiosIntegerValue: An error occurred while sending the new value of %s, %ld, to the BMC",
                 i_attr_string, i_attr_value);
        break;
    }

    }
    while(0);

    return errl;

}

errlHndl_t setMaxNumberHugePages(std::vector<uint8_t>& io_string_table,
                                 std::vector<uint8_t>& io_attr_table,
                                 uint64_t i_maxPages)
{
    return setBiosIntegerAttrValue(io_string_table,
                                   io_attr_table,
                                   PLDM_BIOS_HB_MAX_NUMBER_HUGE_PAGES_STRING,
                                   i_maxPages);
}

errlHndl_t setBiosEnumAttrValue(std::vector<uint8_t>& io_string_table,
                                std::vector<uint8_t>& io_attr_table,
                                const char *i_attr_string,
                                const char *i_attr_enum_value_string)
{

    errlHndl_t errl = nullptr;

    do {

    errl = ensureTablesAreSet(io_string_table, io_attr_table);
    if (errl)
    {
        PLDM_ERR("setBiosEnumAttrValue: An error occured when attempting to populate the bios tables");
        break;
    }

    pldm_bios_attribute_type expected_type = PLDM_BIOS_ENUMERATION;
    const pldm_bios_attr_table_entry * attr_entry_ptr = nullptr;
    std::vector<uint8_t> attr_value;

    // get attr_entry_ptr for the passed i_attr_string
    errl = getCurrentAttrValue(i_attr_string,
                               expected_type,
                               io_string_table,
                               io_attr_table,
                               attr_entry_ptr,
                               attr_value);

    if(errl)
    {
        PLDM_ERR("setBiosEnumAttrValue: An error occurred while requesting the value of %s from the BMC",
                 i_attr_string)
        break;
    }

    // get all the possible values for the attr enum
    // This possible_values[] is an array of the bios table handles for the enum values.
    // The values for the enums are the indicies of this possible_values[] array for the
    // coresponding table handles
    auto num_possible_values = pldm_bios_table_attr_entry_enum_decode_pv_num(attr_entry_ptr);
    uint16_t possible_values[num_possible_values] = {0};
    pldm_bios_table_attr_entry_enum_decode_pv_hdls(attr_entry_ptr,
                                                   possible_values,
                                                   num_possible_values);

    PLDM_DBG("setBiosEnumAttrValue: num_possible_values for %s: %d", i_attr_string, num_possible_values);

    uint8_t possible_value_index = 0;
    for(; possible_value_index < num_possible_values; possible_value_index++)
    {
         // get the string representation of the BIOS attr value
         const auto& enum_value_string =
                     decode_string_handle(io_string_table, possible_values[possible_value_index]);

         PLDM_DBG("setBiosEnumAttrValue: BMC PLDM BIOS attribute enum %s has a value of (0x%X)",
                  enum_value_string.data(), possible_value_index);

         if(strcmp(enum_value_string.data(), i_attr_enum_value_string) == 0)
         {
             // BIOS enum attr values are stored as 2 bytes. The first byte, attr_value[0],
             // indicates the number of following bytes to read as the enum value. Possible
             // BIOS enum values are of uint8_t size, see pldm_bios_enum_attr in
             // src/subtree/openbmc/pldm/libpldm/bios.h. This means attr_value[0] = 1,
             // which is already set after the call to getCurrentAttrValue(). This just
             // leaves us to set attr_value[1] to values in range of num_possible_values
             //
             // To see how other BIOS attr types are validated on PLDM's side, see
             // checkAttrValueToUpdate() in src/subtree/openbmc/pldm/libpldmresponder/bios_config.cpp
             attr_value[1] = possible_value_index;
             PLDM_DBG("setBiosEnumAttrValue: Found matching BMC PLDM BIOS attribute enum value: %s (0x%X)",
                      enum_value_string.data(), possible_value_index);
             break;
         }
    }

    if (possible_value_index >= num_possible_values)
    {
        PLDM_ERR("setBiosEnumAttrValue: No match found in BMC PLDM BIOS attribute values for attr: %s, and string value: %s",
                 i_attr_string, i_attr_enum_value_string);
        /*@
         * @errortype  ERRL_SEV_UNRECOVERABLE
         * @moduleid   MOD_SET_BIOS_ATTR_ENUM_VALUE
         * @reasoncode RC_NO_MATCHING_VALUE
         * @userdata1  Ascii representation of the bios attr to set
         * @userdata2  Ascii representation of the unmatched enum
         *             value string
         * @devdesc    BIOS attr does not have a matching possible
         *             value for the given enum string.
         * @custdesc   A software error occurred during system boot.
         */
        errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                             MOD_SET_BIOS_ATTR_ENUM_VALUE,
                             RC_NO_MATCHING_VALUE,
                             *reinterpret_cast<const uint64_t *>(i_attr_string),
                             *reinterpret_cast<const uint64_t *>(i_attr_enum_value_string),
                             ErrlEntry::NO_SW_CALLOUT);
        addBmcErrorCallouts(errl);
        break;
    }

    // set the BIOS attr to the new value
    const auto attr_handle = pldm_bios_table_attr_entry_decode_attribute_handle(attr_entry_ptr);
    errl = setBiosAttrByHandle(attr_handle, expected_type,
                               attr_value.data(), attr_value.size());
    if (errl)
    {
        PLDM_ERR("setBiosEnumAttrValue: Cannot set current value for attribute %s", i_attr_string);
        break;
    }


    } while (0);

    return errl;
}

errlHndl_t clearKeyClearRequest(std::vector<uint8_t>& io_string_table,
                                std::vector<uint8_t>& io_attr_table)
{
    return setBiosEnumAttrValue(io_string_table,
                                io_attr_table,
                                PLDM_BIOS_HB_KEY_CLEAR_REQUEST_STRING_PENDING,
                                PLDM_BIOS_KEY_CLEAR_NONE_STRING);
}

errlHndl_t clearKeyClearRequest(void)
{
    std::vector<uint8_t> bios_string_table;
    std::vector<uint8_t> bios_attr_table;

    return clearKeyClearRequest(bios_string_table,
                                bios_attr_table);
}


errlHndl_t getPowerLimit(bool &o_powerLimitEnable,
                         uint16_t &o_powerLimitWatts)
{
    errlHndl_t errl = nullptr;

    do{

    // Enable Attribute
    std::vector<uint8_t> string_table, attr_table;
    std::vector<char> decoded_value;

    errl = getDecodedEnumAttr(string_table,
                              attr_table,
                              PLDM_BIOS_HB_POWER_LIMIT_ENABLE_STRING,
                              POSSIBLE_HB_POWER_LIMIT_STRINGS,
                              decoded_value);
    if(errl)
    {
        PLDM_ERR("Failed to lookup value for %s",
                 PLDM_BIOS_HB_POWER_LIMIT_ENABLE_STRING);
        break;
    }

    if(strncmp(decoded_value.data(), PLDM_BIOS_DISABLED_STRING, decoded_value.size()) == 0)
    {
        o_powerLimitEnable = false;
        PLDM_INF("Power Limit Disabled by BMC PLDM BIOS attribute");
    }
    else if(strncmp(decoded_value.data(), PLDM_BIOS_ENABLED_STRING, decoded_value.size()) == 0)
    {
        o_powerLimitEnable = true;
        PLDM_INF("Power Limit Enabled by BMC PLDM BIOS attribute");
    }
    else
    {
        // print the entire buffer
        PLDM_INF_BIN("Unexpected string : ",decoded_value.data(), decoded_value.size());
        /*@
          * @errortype
          * @severity   ERRL_SEV_UNRECOVERABLE
          * @moduleid   MOD_GET_POWER_LIMIT
          * @reasoncode RC_UNSUPPORTED_TYPE
          * @userdata1  Unused
          * @userdata2  Unused
          * @devdesc    Software problem, incorrect data from BMC
          * @custdesc   A software error occurred during system boot
          */
        errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                             MOD_GET_POWER_LIMIT,
                             RC_UNSUPPORTED_TYPE,
                             0,
                             0,
                             ErrlEntry::NO_SW_CALLOUT);
        ErrlUserDetailsString(PLDM_BIOS_HB_POWER_LIMIT_ENABLE_STRING).addToLog(errl);
        ErrlUserDetailsString(decoded_value.data()).addToLog(errl);
        addBmcErrorCallouts(errl);
        break;
    }


    // Limit Attribute
    uint64_t l_attr_val = 0;
    errl = systemIntAttrLookup(string_table,
                               attr_table,
                               PLDM_BIOS_HB_POWER_LIMIT_IN_WATTS_STRING,
                               l_attr_val);
    if(errl)
    {
        PLDM_ERR("getPowerLimit() Failed to lookup value for %s",
                 PLDM_BIOS_HB_POWER_LIMIT_IN_WATTS_STRING);
        break;
    }

    o_powerLimitWatts = l_attr_val;
    PLDM_INF("Power Limit Watts from BMC PLDM BIOS attribute 0x%X",o_powerLimitWatts);

    }while(0);

    return errl;
}

// getTpmRequiredPolicy
errlHndl_t getTpmRequiredPolicy(
        std::vector<uint8_t>& io_string_table,
        std::vector<uint8_t>& io_attr_table,
        TARGETING::ATTR_TPM_REQUIRED_type &o_tpmRequiredPolicy)
{
    errlHndl_t errl = nullptr;

    do {

    // Enable Attribute
    std::vector<char> decoded_value;

    errl = getDecodedEnumAttr(io_string_table,
                              io_attr_table,
                              PLDM_BIOS_HB_TPM_REQUIRED_POLICY_STRING,
                              POSSIBLE_TPM_REQUIRED_STRINGS,
                              decoded_value);

    if (errl)
    {
        PLDM_ERR("PLDM::getTpmRequiredPolicy: Failed to lookup value for %s",
                 PLDM_BIOS_HB_TPM_REQUIRED_POLICY_STRING);
        break;
    }

    if (strncmp(decoded_value.data(), PLDM_BIOS_TPM_REQUIRED_STRING, decoded_value.size()) == 0)
    {
        o_tpmRequiredPolicy = static_cast<TARGETING::ATTR_TPM_REQUIRED_type>(1);
        PLDM_INF("PLDM::getTpmRequiredPolicy: TPM Required Policy set to required by BMC PLDM BIOS attribute %s",
                  PLDM_BIOS_HB_TPM_REQUIRED_POLICY_STRING);
    }
    else if (strncmp(decoded_value.data(), PLDM_BIOS_TPM_NOT_REQUIRED_STRING, decoded_value.size()) == 0)
    {
        o_tpmRequiredPolicy = static_cast<TARGETING::ATTR_TPM_REQUIRED_type>(0);
        PLDM_INF("PLDM::getTpmRequiredPolicy: TPM Required Policy set to *not* required by BMC PLDM BIOS attribute %s",
                  PLDM_BIOS_HB_TPM_REQUIRED_POLICY_STRING);
    }
    else
    {
        // print the entire buffer
        PLDM_INF_BIN("PLDM::getTpmRequiredPolicy: Unexpected string : ",decoded_value.data(), decoded_value.size());
        /*@
          * @errortype
          * @severity   ERRL_SEV_UNRECOVERABLE
          * @moduleid   MOD_GET_TPM_REQUIRED_POLICY
          * @reasoncode RC_UNSUPPORTED_TYPE
          * @userdata1  Unused
          * @userdata2  Unused
          * @devdesc    Software problem, incorrect data from BMC
          * @custdesc   A software error occurred during system boot
          */
        errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                             MOD_GET_TPM_REQUIRED_POLICY,
                             RC_UNSUPPORTED_TYPE,
                             0,
                             0,
                             ErrlEntry::NO_SW_CALLOUT);
        ErrlUserDetailsString(PLDM_BIOS_HB_TPM_REQUIRED_POLICY_STRING).addToLog(errl);
        ErrlUserDetailsString(decoded_value.data()).addToLog(errl);
        addBmcErrorCallouts(errl);
        break;
    }

    } while(0);

    return errl;
}


errlHndl_t getSecVerLockinEnabled(std::vector<uint8_t>& io_string_table,
                                  std::vector<uint8_t>& io_attr_table,
                                  TARGETING::ATTR_SECURE_VERSION_LOCKIN_POLICY_type& o_lockinEnabled)
{
    errlHndl_t l_errl = nullptr;
    o_lockinEnabled = false;

    do {

    std::vector<char>l_decodedValue = {};

    l_errl = getDecodedEnumAttr(io_string_table,
                                io_attr_table,
                                PLDM_BIOS_HB_SEC_VER_LOCKIN_SUPPORTED_STRING,
                                POSSIBLE_SEC_VER_LOCKIN_STRINGS,
                                l_decodedValue);
    if(l_errl)
    {
        break;
    }

    if(strncmp(l_decodedValue.data(), PLDM_BIOS_DISABLED_STRING, l_decodedValue.size()) == 0)
    {
        o_lockinEnabled = false;
    }
    else if(strncmp(l_decodedValue.data(), PLDM_BIOS_ENABLED_STRING, l_decodedValue.size()) == 0)
    {
        o_lockinEnabled = true;
    }
    else
    {
        PLDM_INF_BIN("getSecVerLockinEnabled: Unknown string returned from BMC:", l_decodedValue.data(), l_decodedValue.size());
        /*@
         * @errortype
         * @severity   ERRL_SEV_UNRECOVERABLE
         * @moduleid   MOD_GET_SEC_VER_LOCKIN_ENABLED
         * @reasoncode RC_UNSUPPORTED_TYPE
         * @devdesc    BMC returned an unknown enum for secure
         *             version lockin enabled
         * @custdesc   A software error occurred during system boot
         */
        l_errl = new ErrlEntry(ERRL_SEV_UNRECOVERABLE,
                               MOD_GET_SEC_VER_LOCKIN_ENABLED,
                               RC_UNSUPPORTED_TYPE);
        ErrlUserDetailsString(PLDM_BIOS_HB_SEC_VER_LOCKIN_SUPPORTED_STRING).addToLog(l_errl);
        ErrlUserDetailsString(l_decodedValue.data()).addToLog(l_errl);
        addBmcErrorCallouts(l_errl);
        break;
    }

    } while(0);

    return l_errl;
}

errlHndl_t latchBiosAttrs(std::vector<uint8_t>& io_string_table,
                          std::vector<uint8_t>& io_attr_table)
{
    PLDM_ENTER("latchBiosAttrs");

    errlHndl_t errl = nullptr;

    do
    {

    errl = ensureTablesAreSet(io_string_table, io_attr_table);
    if (errl)
    {
        break;
    }

    /* Iterate all attribute names looking for ones matching the pattern "hb_*_current". */

    const std::unique_ptr<pldm_bios_table_iter, decltype(&pldm_bios_table_iter_free)>
        it { pldm_bios_table_iter_create(io_attr_table.data(), io_attr_table.size(), PLDM_BIOS_ATTR_TABLE),
            pldm_bios_table_iter_free };

    for (; !pldm_bios_table_iter_is_end(it.get()); pldm_bios_table_iter_next(it.get()))
    {
        const auto current_attr_entry = pldm_bios_table_iter_attr_entry_value(it.get());
        const auto current_attr_handle = pldm_bios_table_attr_entry_decode_attribute_handle(current_attr_entry);
        const auto current_attr_name_string_handle = pldm_bios_table_attr_entry_decode_string_handle(current_attr_entry);
        const auto& current_attr_name = decode_string_handle(io_string_table, current_attr_name_string_handle);

        if (strncmp(current_attr_name.data(), "hb_", 3) == 0)
        {
            /* If we find an hb_*_current "latched" attribute, then try to read an
             * attribute named hb_* (which contains the "pending" value). If that
             * succeeds, then we will copy it into the hb_*_current attribute. */
            const char* const suffix = "_current";
            if (strcmp(current_attr_name.data() + current_attr_name.size() - 1 - strlen(suffix), suffix) == 0)
            {
                // Strip off the _current suffix from current_attr_name to get the name of the "pending" attribute
                std::vector<char> pending_attr_name(current_attr_name.data(),
                                                    current_attr_name.data() + current_attr_name.size() - 1 - strlen(suffix));
                pending_attr_name.push_back('\0');

                auto current_attr_type
                    = static_cast<pldm_bios_attribute_type>(pldm_bios_table_attr_entry_decode_attribute_type(current_attr_entry));

                const pldm_bios_attr_table_entry* pending_attr_entry = nullptr;
                std::vector<uint8_t> pending_attr_value;

                /* Attributes with _current will likely be readonly, and their pending counterparts
                 * are likely not. getCurrentAttrValue will accept either the read-only version of the type
                 * or the read-write version on input but will return whichever is found. We want to preserve
                 * current_attr_type for when we call setBiosAttrByHandle later on.
                 */
                pldm_bios_attribute_type pending_attr_type = current_attr_type;
                errlHndl_t attr_errl =
                    getCurrentAttrValue(pending_attr_name.data(), pending_attr_type,
                                        io_string_table, io_attr_table, pending_attr_entry, pending_attr_value);

                if (attr_errl)
                {
                    PLDM_ERR("Cannot get pending value for attribute %s", pending_attr_name.data());
                    // We want these logs to be visible, but not halt the IPL.
                    attr_errl->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
                    errlCommit(attr_errl, PLDM_COMP_ID);
                    continue;
                }

                attr_errl = setBiosAttrByHandle(current_attr_handle, current_attr_type,
                                                pending_attr_value.data(), pending_attr_value.size());

                if (attr_errl)
                {
                    PLDM_ERR("Cannot set current value for attribute %s (size %d)",
                             current_attr_name.data(), pending_attr_value.size());
                    // We want these logs to be visible, but not halt the IPL.
                    attr_errl->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
                    errlCommit(attr_errl, PLDM_COMP_ID);
                }
            }
        }
    }

    } while (false);

    PLDM_EXIT("latchBiosAttrs");

    return errl;
}

errlHndl_t getEnlargedCapacity(
        std::vector<uint8_t>& io_string_table,
        std::vector<uint8_t>& io_attr_table,
        TARGETING::ATTR_ENLARGED_IO_SLOT_COUNT_type &o_enlargedCapacity)
{
    errlHndl_t errl = nullptr;

    do {

    uint64_t l_attr_val = 0;
    errl = systemIntAttrLookup(io_string_table,
                               io_attr_table,
                               PLDM_BIOS_HB_ENLARGED_CAPACITY_STRING,
                               l_attr_val);
    if(errl)
    {
        PLDM_ERR("getEnlargedCapacity() Failed to lookup value for %s",
                 PLDM_BIOS_HB_ENLARGED_CAPACITY_STRING);
        break;
    }

    o_enlargedCapacity =
        static_cast<TARGETING::ATTR_ENLARGED_IO_SLOT_COUNT_type>(l_attr_val);
    } while(0);

    return errl;
}

} // end namespace PLDM
