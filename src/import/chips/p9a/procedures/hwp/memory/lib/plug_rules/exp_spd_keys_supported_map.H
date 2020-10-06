/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9a/procedures/hwp/memory/lib/plug_rules/exp_spd_keys_supported_map.H $ */
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
#ifndef _EXP_SPD_KEYS_SUPPORTED_MAP_H_
#define _EXP_SPD_KEYS_SUPPORTED_MAP_H_

#include <lib/plug_rules/p9a_plug_rules.H>

namespace mss
{
namespace plug_rule
{
/// @note These are the latest and minimum allowed DDIMM SPD combined revisions
///       combined revision is the SPD revision and the SPD content revision
///       any DIMMs with older SPD will generate an error
///       The first byte is the major revision
///               any updates to this are usually new bytes and will require code updates
///       The second byte is the content revision
///               updates to this byte are most likely values and it's less likely that code will need to be updated
///       The vectors go from a lookup key to a combined revisions
///       The first vector is the minimum allowed combined revision
///       The second vector is the latest version of the combined revision
/// @note When adding new vendors/heights/sizes, THIS NEEDS TO BE IN SORTED ORDER BY VENDOR ID ENCODING
static const std::vector<std::pair<spd_lookup_key, uint16_t>> MINIMUM_SPD_KEY_COMBINED_REV =
{
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_1U, fapi2::ENUM_ATTR_MEM_EFF_DIMM_SIZE_16GB}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_2U, fapi2::ENUM_ATTR_MEM_EFF_DIMM_SIZE_16GB}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_2U, fapi2::ENUM_ATTR_MEM_EFF_DIMM_SIZE_32GB}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_2U, fapi2::ENUM_ATTR_MEM_EFF_DIMM_SIZE_64GB}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_4U, fapi2::ENUM_ATTR_MEM_EFF_DIMM_SIZE_32GB}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_4U, fapi2::ENUM_ATTR_MEM_EFF_DIMM_SIZE_64GB}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_MICRON, fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_2U, fapi2::ENUM_ATTR_MEM_EFF_DIMM_SIZE_32GB}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_MICRON, fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_2U, fapi2::ENUM_ATTR_MEM_EFF_DIMM_SIZE_64GB}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_MICRON, fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_4U, fapi2::ENUM_ATTR_MEM_EFF_DIMM_SIZE_32GB}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_1U, fapi2::ENUM_ATTR_MEM_EFF_DIMM_SIZE_16GB}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_2U, fapi2::ENUM_ATTR_MEM_EFF_DIMM_SIZE_16GB}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_2U, fapi2::ENUM_ATTR_MEM_EFF_DIMM_SIZE_32GB}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_2U, fapi2::ENUM_ATTR_MEM_EFF_DIMM_SIZE_64GB}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_2U, fapi2::ENUM_ATTR_MEM_EFF_DIMM_SIZE_128GB}, 0x0309},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_4U, fapi2::ENUM_ATTR_MEM_EFF_DIMM_SIZE_32GB}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_4U, fapi2::ENUM_ATTR_MEM_EFF_DIMM_SIZE_64GB}, 0x0400},
};

static const std::vector<std::pair<spd_lookup_key, uint16_t>> LATEST_SPD_KEY_COMBINED_REV =
{
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_1U, fapi2::ENUM_ATTR_MEM_EFF_DIMM_SIZE_16GB}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_2U, fapi2::ENUM_ATTR_MEM_EFF_DIMM_SIZE_16GB}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_2U, fapi2::ENUM_ATTR_MEM_EFF_DIMM_SIZE_32GB}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_2U, fapi2::ENUM_ATTR_MEM_EFF_DIMM_SIZE_64GB}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_4U, fapi2::ENUM_ATTR_MEM_EFF_DIMM_SIZE_32GB}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_4U, fapi2::ENUM_ATTR_MEM_EFF_DIMM_SIZE_64GB}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_MICRON, fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_2U, fapi2::ENUM_ATTR_MEM_EFF_DIMM_SIZE_32GB}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_MICRON, fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_2U, fapi2::ENUM_ATTR_MEM_EFF_DIMM_SIZE_64GB}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_MICRON, fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_4U, fapi2::ENUM_ATTR_MEM_EFF_DIMM_SIZE_32GB}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_1U, fapi2::ENUM_ATTR_MEM_EFF_DIMM_SIZE_16GB}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_2U, fapi2::ENUM_ATTR_MEM_EFF_DIMM_SIZE_16GB}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_2U, fapi2::ENUM_ATTR_MEM_EFF_DIMM_SIZE_32GB}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_2U, fapi2::ENUM_ATTR_MEM_EFF_DIMM_SIZE_64GB}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_2U, fapi2::ENUM_ATTR_MEM_EFF_DIMM_SIZE_128GB}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_4U, fapi2::ENUM_ATTR_MEM_EFF_DIMM_SIZE_32GB}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, fapi2::ENUM_ATTR_MEM_EFF_DRAM_MODULE_HEIGHT_4U, fapi2::ENUM_ATTR_MEM_EFF_DIMM_SIZE_64GB}, 0x0400},
};

} // ns plug_rules
} // ns mss
#endif
