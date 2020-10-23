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

// pldm /include/ headers
#include <pldm/requests/pldm_bios_attr_requests.H>
#include <pldm/base/hb_bios_attrs.H>
#include <pldm/pldm_errl.H>
#include <pldm/pldm_reasoncodes.H>

// pldm /src/ headers
#include "../common/pldmtrace.H"

namespace PLDM {

errlHndl_t getCurrentAttrValue(const char *i_attr_string,
                               pldm_bios_attribute_type& o_attr_type,
                               std::vector<uint8_t> o_attr_val)
{
  errlHndl_t errl = nullptr;
  do {
  PLDM_ENTER("getCurrentAttrValue %s", i_attr_string);

  // We will need a copy of the string table to figure out
  // the string handle
  std::vector<uint8_t> string_table;
  pldm_bios_table_types table_type = PLDM_BIOS_STRING_TABLE;

  errl = getBiosTable(table_type, string_table);
  if(errl)
  {
      PLDM_ERR("getCurrentAttrValue failed reading string table");
      break;
  }
  PLDM_DBG("getCurrentAttrValue: Looking up string %s in string table...", i_attr_string);
  // Get the string handle by looking up i_attr_string in string_table
  const struct pldm_bios_string_table_entry * string_entry =
      pldm_bios_table_string_find_by_string(string_table.data(),
                                            string_table.size(),
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

  // We will need a copy of the attribute table to figure out
  // the attribute handle
  std::vector<uint8_t> attr_table;
  table_type = PLDM_BIOS_ATTR_TABLE;
  errl = getBiosTable(table_type, attr_table);

  if(errl)
  {
      PLDM_ERR("getCurrentAttrValue failed reading attribute table");
      break;
  }

  uint16_t attribute_handle = 0;
  bool match_found = false;

  auto attr_table_iter = pldm_bios_table_iter_create(attr_table.data(),
                                                     attr_table.size(),
                                                     table_type);

  // Get the attribute handle by looking through the attribute table
  for (;
       pldm_bios_table_iter_is_end(attr_table_iter) != true;
       pldm_bios_table_iter_next(attr_table_iter))
  {
      const pldm_bios_attr_table_entry * attr =
          reinterpret_cast<const pldm_bios_attr_table_entry * >(
            pldm_bios_table_iter_value(attr_table_iter));

      if(pldm_bios_table_attr_entry_decode_string_handle(attr) == string_handle)
      {
          attribute_handle =
            pldm_bios_table_attr_entry_decode_attribute_handle(attr);
          match_found = true;
          break;
      }
  }

  pldm_bios_table_iter_free(attr_table_iter);

  // we found a valid string handle but it did not match
  // up with anything in the attribute table, BMC bug likely
  if(!match_found)
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

  std::vector<uint8_t> entry_vector;
  errl = getBiosAttrFromHandle(attribute_handle,
                               entry_vector);
  if(errl)
  {
      PLDM_ERR("getCurrentAttrValue failed attempting to attribute entry");
      break;
  }

  pldm_bios_attr_val_table_entry * value_entry =
      reinterpret_cast<pldm_bios_attr_val_table_entry *>(entry_vector.data());

  o_attr_type = static_cast<pldm_bios_attribute_type>(value_entry->attr_type);

  const size_t value_size = entry_vector.size() - offsetof(pldm_bios_attr_val_table_entry, value);

  o_attr_val.insert(o_attr_val.begin(),
                    value_entry->value,
                    value_entry->value + value_size);

  PLDM_DBG_BIN("Value found was ", o_attr_val.data(), o_attr_val.size());
  PLDM_EXIT("getCurrentAttrValue Found type 0x%x for attribute %s", o_attr_type, i_attr_string);

  }while(0);

  return errl;
}

}
