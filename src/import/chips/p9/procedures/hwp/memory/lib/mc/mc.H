/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/mc/mc.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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

///
/// @file mc.H
/// @brief Subroutines to manipulate the memory controller
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _MSS_MC_H_
#define _MSS_MC_H_

#include <fapi2.H>

#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>
#include <lib/mss_attribute_accessors.H>
#include <lib/dimm/kind.H>
#include <lib/utils/scom.H>

namespace mss
{

// I have a dream that the xlate code can be shared among controllers. So, I drive the
// engine from a set of traits. This might be folly. Allow me to dream. BRS

///
/// @class mcTraits
/// @brief a collection of traits associated with the MC
/// @tparam T, fapi2::TargetType representing the MC
///
template< fapi2::TargetType T >
class mcTraits;

///
/// @class mcTraits
/// @brief a collection of traits associated with the Centaur controller
///
template<>
class mcTraits<fapi2::TARGET_TYPE_MBA>
{
};

///
/// @class mcTraits
/// @brief a collection of traits associated with the Nimbus controller
///
template<>
class mcTraits<fapi2::TARGET_TYPE_MCA>
{
    public:
        enum
        {
            SLOT0_VALID = MCS_PORT02_MCP0XLT0_SLOT0_VALID,
            SLOT0_ROW15_VALID = MCS_PORT02_MCP0XLT0_SLOT0_ROW15_VALID,
            SLOT0_M1_VALID = MCS_PORT02_MCP0XLT0_SLOT0_M1_VALID,
            M1_BIT_MAP = MCS_PORT02_MCP0XLT0_M1_BIT_MAP,
            M1_BIT_MAP_LEN = MCS_PORT02_MCP0XLT0_M1_BIT_MAP_LEN,
            D_BIT_MAP = MCS_PORT02_MCP0XLT0_D_BIT_MAP,
            D_BIT_MAP_LEN = MCS_PORT02_MCP0XLT0_D_BIT_MAP_LEN,
            R15_BIT_MAP = MCS_PORT02_MCP0XLT0_R15_BIT_MAP,
            R15_BIT_MAP_LEN = MCS_PORT02_MCP0XLT0_R15_BIT_MAP_LEN,
            COL4_BIT_MAP = MCS_PORT02_MCP0XLT1_COL4_BIT_MAP,
            COL4_BIT_MAP_LEN = MCS_PORT02_MCP0XLT1_COL4_BIT_MAP_LEN,
            COL5_BIT_MAP = MCS_PORT02_MCP0XLT1_COL5_BIT_MAP,
            COL5_BIT_MAP_LEN = MCS_PORT02_MCP0XLT1_COL5_BIT_MAP_LEN,
            COL6_BIT_MAP = MCS_PORT02_MCP0XLT1_COL6_BIT_MAP,
            COL6_BIT_MAP_LEN = MCS_PORT02_MCP0XLT1_COL6_BIT_MAP_LEN,
            COL7_BIT_MAP = MCS_PORT02_MCP0XLT1_COL7_BIT_MAP,
            COL7_BIT_MAP_LEN = MCS_PORT02_MCP0XLT1_COL7_BIT_MAP_LEN,
            COL8_BIT_MAP = MCS_PORT02_MCP0XLT2_COL8_BIT_MAP,
            COL8_BIT_MAP_LEN = MCS_PORT02_MCP0XLT2_COL8_BIT_MAP_LEN,
            COL9_BIT_MAP = MCS_PORT02_MCP0XLT2_COL9_BIT_MAP,
            COL9_BIT_MAP_LEN = MCS_PORT02_MCP0XLT2_COL9_BIT_MAP_LEN,
            BANK0_BIT_MAP = MCS_PORT02_MCP0XLT2_BANK0_BIT_MAP,
            BANK0_BIT_MAP_LEN = MCS_PORT02_MCP0XLT2_BANK0_BIT_MAP_LEN,
            BANK1_BIT_MAP = MCS_PORT02_MCP0XLT2_BANK1_BIT_MAP,
            BANK1_BIT_MAP_LEN = MCS_PORT02_MCP0XLT2_BANK1_BIT_MAP_LEN,
            BANK_GROUP0_BIT_MAP = MCS_PORT02_MCP0XLT2_BANK_GROUP0_BIT_MAP,
            BANK_GROUP0_BIT_MAP_LEN = MCS_PORT02_MCP0XLT2_BANK_GROUP0_BIT_MAP_LEN,
            BANK_GROUP1_BIT_MAP = MCS_PORT02_MCP0XLT2_BANK_GROUP1_BIT_MAP,
            BANK_GROUP1_BIT_MAP_LEN = MCS_PORT02_MCP0XLT2_BANK_GROUP1_BIT_MAP_LEN,
        };

};

// Why two enums? Two reasons. First, we need these to be contiguous, and
// we can't always guarentee the symbols will be generated as such. Second,
// we want to be 0'based so that we can use a static array as a table and
// it's probably not possible for the symbols to be 0'based.
enum
{
    THIS_ENTRY_VALID = 0,
    VALUE_OF_D_BIT_INDEX = 1,
    GB12_ENABLE_INDEX = 2,
    MASTER_BIT_0_VALID_INDEX = 3,
    MASTER_BIT_1_VALID_INDEX = 4,
    SLAVE_BIT_0_VALID_INDEX = 5,
    SLAVE_BIT_1_VALID_INDEX = 6,
    SLAVE_BIT_2_VALID_INDEX = 7,
    ROW_BIT_15_VALID_INDEX = 8,
    ROW_BIT_16_VALID_INDEX = 9,
    ROW_BIT_17_VALID_INDEX = 10,
    BANK_BIT_2_VALID_INDEX = 11,
    DIMM_BIT_INDEX = 12,
    MASTER_BIT_0_INDEX = 13,
    MASTER_BIT_1_INDEX = 14,
    SLAVE_BIT_0_INDEX = 15,
    SLAVE_BIT_1_INDEX = 16,
    SLAVE_BIT_2_INDEX = 17,
    ROW_17_INDEX = 18,
    ROW_16_INDEX = 19,
    COLUMN_4_INDEX = 20,
    COLUMN_5_INDEX = 21,
    COLUMN_6_INDEX = 22,
    COLUMN_7_INDEX = 23,
    COLUMN_8_INDEX = 24,
    COLUMN_9_INDEX = 25,
    BANK_0_INDEX = 26,
    BANK_1_INDEX = 27,
    BANK_2_INDEX = 28,
    BANK_GROUP_0_BIT_INDEX = 29,
    BANK_GROUP_1_BIT_INDEX = 30,
    MAX_TRANSLATIONS = 31,
};

namespace mc
{

///
/// @brief safemode throttle values defined from MRW attributes
/// @param[in] i_target the MCA target
/// @return FAPI2_RC_SUCCESS iff ok
/// @note sets safemode values for emergency mode and regular throttling
///
fapi2::ReturnCode thermal_throttle_scominit (const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target);
///
/// @brief Disable emergency mode throttle for thermal_init
/// @param[in] i_target the MCS target
/// @return FAPI_RC_SUCCESS iff ok
/// @note Clears MCMODE0_ENABLE_EMER_THROTTLE bit in MCSMODE0
///
fapi2::ReturnCode disable_emergency_throttle (const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target);

///
/// @brief Perform initializations of the MC performance registers
/// @note Some of these bits are taken care of in the scom initfiles
/// @param[in] i_target the target which has the MCA to map
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode setup_perf2_register(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target);

///
/// @brief Calculate the value of the MC perf2 register.
/// @param[in] i_target the target which has the MCA to map
/// @param[out] o_value the perf2 value for the MCA
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode calculate_perf2(const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target, uint64_t& o_value);

///
/// @brief Helper to setup the translation map - useful for testing
/// @param[in] i_dimm_kinds std::vector of DIMM kind's representing the DIMM (Not const as we sort the vector)
/// @param[out] fapi2::buffer<uint64_t> o_xlate0  - xlt register 0's value
/// @param[out] fapi2::buffer<uint64_t> o_xlate1  - xlt register 1's value
/// @param[out] fapi2::buffer<uint64_t> o_xlate2  - xlt register 2's value
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode setup_xlate_map_helper( std::vector<dimm::kind>& i_dimm_kinds,
        fapi2::buffer<uint64_t>& o_xlate0,
        fapi2::buffer<uint64_t>& o_xlate1,
        fapi2::buffer<uint64_t>& o_xlate2 );

///
/// @brief Perform initializations of the MC translation
/// @tparam P the fapi2::TargetType of the port
/// @tparam TT the mcTraits associated with P
/// @param[in] i_target the target which has the MCA to map
/// @return FAPI2_RC_SUCCESS iff ok
///
template< fapi2::TargetType P,  typename TT = mcTraits<P> >
fapi2::ReturnCode setup_xlate_map(const fapi2::Target<P>& i_target);

} //mc

} //mss

#endif
