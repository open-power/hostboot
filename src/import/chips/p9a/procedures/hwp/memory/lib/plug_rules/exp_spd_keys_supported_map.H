/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9a/procedures/hwp/memory/lib/plug_rules/exp_spd_keys_supported_map.H $ */
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
#ifndef _EXP_SPD_KEYS_SUPPORTED_MAP_H_
#define _EXP_SPD_KEYS_SUPPORTED_MAP_H_

#include <lib/plug_rules/p9a_plug_rules.H>

namespace mss
{
namespace plug_rule
{
/// @note Using constexprs to make the partnumbers and rawcard numbers human readable
/// This way, you see a string (ie PART) instead of ASCII values (0x50415254)
/// Per the below comment, these values need to be sortable. As how an array is sorted is non-obvious,
/// we define these to be numbers so we can easily predict how they can be sorted.
constexpr uint64_t PN_01GY860 = 0x30314759383630;
constexpr uint64_t PN_01GY867 = 0x30314759383637;
constexpr uint64_t PN_01GY874 = 0x30314759383734;
constexpr uint64_t PN_01GY881 = 0x30314759383831;
constexpr uint64_t PN_01GY888 = 0x30314759383838;
constexpr uint64_t PN_78P6572 = 0x37385036353732;
constexpr uint64_t PN_78P6574 = 0x37385036353734;
constexpr uint64_t PN_78P6575 = 0x37385036353735;
constexpr uint64_t PN_78P6576 = 0x37385036353736;
constexpr uint64_t PN_78P6855 = 0x37385036383535;
constexpr uint32_t RC_YH30 = 0x59483330;
constexpr uint32_t RC_YH31 = 0x59483331;
constexpr uint32_t RC_YH32 = 0x59483332;
constexpr uint32_t RC_YH33 = 0x59483333;
constexpr uint32_t RC_YH34 = 0x59483334;

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
/// @note When adding new vendors/partnumbers/rawcards, THIS NEEDS TO BE IN SORTED ORDER BY VENDOR ID ENCODING
static const std::vector<std::pair<spd_lookup_key, uint16_t>> MINIMUM_SPD_KEY_COMBINED_REV =
{
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, PN_01GY860, RC_YH30}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, PN_01GY860, RC_YH31}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, PN_01GY867, RC_YH30}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, PN_01GY867, RC_YH31}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, PN_01GY874, RC_YH30}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, PN_78P6572, RC_YH30}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, PN_78P6574, RC_YH30}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, PN_78P6574, RC_YH31}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, PN_78P6574, RC_YH32}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, PN_78P6574, RC_YH33}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, PN_78P6574, RC_YH34}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, PN_78P6575, RC_YH30}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, PN_78P6575, RC_YH31}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, PN_78P6575, RC_YH32}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, PN_78P6575, RC_YH33}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, PN_78P6575, RC_YH34}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, PN_78P6855, RC_YH30}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_MICRON, PN_01GY860, RC_YH30}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_MICRON, PN_01GY860, RC_YH31}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_MICRON, PN_01GY867, RC_YH30}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_MICRON, PN_01GY867, RC_YH31}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_MICRON, PN_01GY874, RC_YH30}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_MICRON, PN_78P6574, RC_YH30}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_MICRON, PN_78P6574, RC_YH31}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_MICRON, PN_78P6574, RC_YH32}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_MICRON, PN_78P6574, RC_YH33}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_MICRON, PN_78P6574, RC_YH34}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_MICRON, PN_78P6575, RC_YH30}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_MICRON, PN_78P6575, RC_YH31}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_MICRON, PN_78P6575, RC_YH32}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_MICRON, PN_78P6575, RC_YH33}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_MICRON, PN_78P6575, RC_YH34}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_01GY860, RC_YH30}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_01GY860, RC_YH31}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_01GY860, RC_YH32}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_01GY867, RC_YH30}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_01GY867, RC_YH31}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_01GY867, RC_YH32}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_01GY881, RC_YH30}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_01GY881, RC_YH31}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_01GY888, RC_YH30}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_01GY888, RC_YH31}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_78P6572, RC_YH30}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_78P6574, RC_YH30}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_78P6574, RC_YH31}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_78P6574, RC_YH32}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_78P6574, RC_YH33}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_78P6574, RC_YH34}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_78P6575, RC_YH30}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_78P6575, RC_YH31}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_78P6575, RC_YH32}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_78P6575, RC_YH33}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_78P6575, RC_YH34}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_78P6576, RC_YH30}, 0x0309},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_78P6576, RC_YH31}, 0x0309},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_78P6576, RC_YH32}, 0x0309},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_78P6576, RC_YH33}, 0x0309},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_78P6576, RC_YH34}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_78P6855, RC_YH30}, 0x0308},
};

static const std::vector<std::pair<spd_lookup_key, uint16_t>> LATEST_SPD_KEY_COMBINED_REV =
{
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, PN_01GY860, RC_YH30}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, PN_01GY860, RC_YH31}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, PN_01GY867, RC_YH30}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, PN_01GY867, RC_YH31}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, PN_01GY874, RC_YH30}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, PN_78P6572, RC_YH30}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, PN_78P6574, RC_YH30}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, PN_78P6574, RC_YH31}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, PN_78P6574, RC_YH32}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, PN_78P6574, RC_YH33}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, PN_78P6574, RC_YH34}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, PN_78P6575, RC_YH30}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, PN_78P6575, RC_YH31}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, PN_78P6575, RC_YH32}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, PN_78P6575, RC_YH33}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, PN_78P6575, RC_YH34}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SMART, PN_78P6855, RC_YH30}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_MICRON, PN_01GY860, RC_YH30}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_MICRON, PN_01GY860, RC_YH31}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_MICRON, PN_01GY867, RC_YH30}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_MICRON, PN_01GY867, RC_YH31}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_MICRON, PN_01GY874, RC_YH30}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_MICRON, PN_78P6574, RC_YH30}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_MICRON, PN_78P6574, RC_YH31}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_MICRON, PN_78P6574, RC_YH32}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_MICRON, PN_78P6574, RC_YH33}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_MICRON, PN_78P6574, RC_YH34}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_MICRON, PN_78P6575, RC_YH30}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_MICRON, PN_78P6575, RC_YH31}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_MICRON, PN_78P6575, RC_YH32}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_MICRON, PN_78P6575, RC_YH33}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_MICRON, PN_78P6575, RC_YH34}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_01GY860, RC_YH30}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_01GY860, RC_YH31}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_01GY860, RC_YH32}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_01GY867, RC_YH30}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_01GY867, RC_YH31}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_01GY867, RC_YH32}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_01GY881, RC_YH30}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_01GY881, RC_YH31}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_01GY888, RC_YH30}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_01GY888, RC_YH31}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_78P6572, RC_YH30}, 0x0308},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_78P6574, RC_YH30}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_78P6574, RC_YH31}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_78P6574, RC_YH32}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_78P6574, RC_YH33}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_78P6574, RC_YH34}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_78P6575, RC_YH30}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_78P6575, RC_YH31}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_78P6575, RC_YH32}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_78P6575, RC_YH33}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_78P6575, RC_YH34}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_78P6576, RC_YH30}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_78P6576, RC_YH31}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_78P6576, RC_YH32}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_78P6576, RC_YH33}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_78P6576, RC_YH34}, 0x0400},
    {{fapi2::ENUM_ATTR_MEM_EFF_MODULE_MFG_ID_SAMSUNG, PN_78P6855, RC_YH30}, 0x0308},
};

} // ns plug_rules
} // ns mss
#endif
