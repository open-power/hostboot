/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/spd/common/spd_decoder.C $ */
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
/// @file spd_decoder.C
/// @brief SPD decoder definitions
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

// std lib
#include <map>
#include <vector>

// fapi2
#include <fapi2.H>

// mss lib
#include <lib/spd/common/spd_decoder.H>
#include <lib/spd/rdimm/rdimm_decoder.H>
#include <lib/utils/checker.H>
#include <lib/utils/c_str.H>
#include <lib/utils/find.H>

using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_DIMM;

namespace mss
{
namespace spd
{

/////////////////////////
// Member Method implementation
/////////////////////////

///
/// @brief ctor
/// @param[in] i_target dimm target
/// @param[in] i_spd_data SPD data vector
/// @param[in] i_module_decoder shared_ptr to dimm module decoder
///
decoder::decoder(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                 const std::vector<uint8_t>& i_spd_data,
                 const std::shared_ptr<dimm_module_decoder>& i_module_decoder)
    :  iv_module_decoder(i_module_decoder), iv_spd_data(i_spd_data), iv_target(i_target)
{}

///
/// @brief Decodes number of used SPD bytes
/// @param[in] i_target dimm target
/// @param[out] o_value number of SPD bytes used
/// @return FAPI2_RC_SUCCESS if okay
/// @note Decodes SPD Byte 0 bits(0~3)
/// @note Item JC-45-2220.01x
/// @note Page 14
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::number_of_used_bytes(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint16_t& o_value)
{
    // =========================================================
    // Byte 0 maps
    // Item JC-45-2220.01x
    // Page 14
    // DDR4 SPD Document Release 3
    // Byte 0 (0x000): Number of Bytes Used / Number of Bytes in SPD Device
    // =========================================================
    static const std::vector<std::pair<uint8_t, uint16_t> > BYTES_USED_MAP =
    {
        //{key byte, number of used bytes}
        {1, 128},
        {2, 256},
        {3, 384},
        {4, 512}
    };

    // Extracting desired bits
    constexpr size_t BYTE_INDEX = 0;
    uint8_t l_field_bits = extract_spd_field< BYTE_INDEX, BYTES_USED_START, BYTES_USED_LEN >(i_target, iv_spd_data);

    FAPI_INF("Field_Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(BYTES_USED_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check on SPD used bytes") );

    FAPI_INF("%s. Bytes Used: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes total number of SPD bytes
/// @param[in] i_target dimm target
/// @param[out] o_value number of total SPD bytes
/// @return FAPI2_RC_SUCCESS if okay
/// @note Decodes SPD Byte 0 (bits 4~6)
/// @note Item JC-45-2220.01x
/// @note Page 14
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::number_of_total_bytes(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint16_t& o_value)
{

    // =========================================================
    // Byte 0 maps
    // Item JC-45-2220.01x
    // Page 14
    // DDR4 SPD Document Release 3
    // Byte 0 (0x000): Number of Bytes Used / Number of Bytes in SPD Device
    // =========================================================
    static const std::vector<std::pair<uint8_t, uint16_t> > BYTES_TOTAL_MAP =
    {
        //{key byte, number of total bytes}
        {1, 256},
        {2, 512}
    };

    // Extracting desired bits
    constexpr size_t BYTE_INDEX = 0;
    uint8_t l_field_bits = extract_spd_field< BYTE_INDEX, BYTES_TOTAL_START, BYTES_TOTAL_LEN >(i_target, iv_spd_data);

    FAPI_INF("Field_Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(BYTES_TOTAL_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check on SPD total bytes") );

    FAPI_INF("%s. Total Bytes: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes hybrid media field from SPD
/// @param[in] i_target dimm target
/// @param[out] o_value enum representing hybrid memory type
/// @return FAPI2_RC_SUCCESS if okay
/// @note Decodes SPD Byte 3 (bits 4~6)
/// @note Item JC-45-2220.01x
/// @note Page 17
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::hybrid_media(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                        uint8_t& o_value)
{
    // For General Section rev 1.0 of the SPD,
    // Decodes SPD Byte 3 (bits 4~6) were reserved
    // and coded as zeros. There was no concept of hybrid media so this
    // is thus hard-wired to zero.
    o_value = 0x00;
    return fapi2::FAPI2_RC_SUCCESS;

}

///
/// @brief Decodes hybrid field from SPD
/// @param[in] i_target
/// @param[out] o_value enum representing if module is hybrid
/// @return fapi2::ReturnCode
/// @note Decodes SPD Byte 3 (bit 7)
/// @note Item JC-45-2220.01x
/// @note Page 17
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::hybrid(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                  uint8_t& o_value)
{
    // For General Section rev 1.0 of the SPD,
    // Decodes SPD Byte 3 (bit 7) were reserved
    // and coded as zeros. There was no concept of hybrid media so this
    // is thus hard-wired to zero.
    o_value = 0x00;
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Decodes SDRAM density from SPD
/// @param[in] i_target dimm target
/// @param[out] o_value SDRAM density in GBs
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 4 (bits 0~3)
/// @note Item JC-45-2220.01x
/// @note Page 18
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::sdram_density(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_value)
{
    // =========================================================
    // Byte 4 maps
    // Item JC-45-2220.01x
    // Page 18
    // DDR4 SPD Document Release 3
    // Byte 4 (0x004): SDRAM Density and Banks
    // =========================================================
    static const std::vector< std::pair<uint8_t, uint8_t> > SDRAM_DENSITY_MAP =
    {
        // {key byte, capacity in GBs}
        {2, 1},
        {3, 2},
        {4, 4},
        {5, 8},
        {6, 16},
        {7, 32},
    };

    // Extracting desired bits
    constexpr size_t BYTE_INDEX = 4;
    uint8_t l_field_bits = extract_spd_field< BYTE_INDEX, SDRAM_CAPACITY_START, SDRAM_CAPACITY_LEN >(i_target, iv_spd_data);

    FAPI_INF("Field Bits value: %d", l_field_bits);

    // Check to assure SPD DRAM capacity (map) wont be at invalid values
    bool l_is_val_found = mss::find_value_from_key(SDRAM_DENSITY_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for SPD DRAM capacity") );

    FAPI_INF("%s. SDRAM density: %d Gb",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes number of SDRAM bank_bits from SPD
/// @param[in] i_target dimm target
/// @param[out] o_value Number of SDRAM bank bits
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 4 (bits 5~4)
/// @note Item JC-45-2220.01x
/// @note Page 18
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::bank_bits(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                     uint8_t& o_value)

{
    // =========================================================
    // Byte 4 maps
    // Item JC-45-2220.01x
    // Page 18
    // DDR4 SPD Document Release 3
    // Byte 4 (0x004): SDRAM Density and Banks
    // =========================================================
    static const std::vector< std::pair<uint8_t, uint8_t> > BANK_ADDR_BITS_MAP =
    {
        // {key byte, number of bank address bits}
        {0, 2},
        {1, 3}
    };

    // Extracting desired bits
    constexpr size_t BYTE_INDEX = 4;
    uint8_t l_field_bits = extract_spd_field< BYTE_INDEX, SDRAM_BANKS_START, SDRAM_BANKS_LEN >(i_target, iv_spd_data);

    FAPI_INF("Field Bits value: %d", l_field_bits);

    // Check to assure SPD DRAM capacity (map) wont be at invalid values
    bool l_is_val_found = mss::find_value_from_key(BANK_ADDR_BITS_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for SPD DRAM banks") );

    FAPI_INF("%s. Number of banks address bits: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes number of SDRAM bank group bits from SPD
/// @param[in] i_target dimm target
/// @param[out] o_value Number of SDRAM bank group bits
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 4 (bits 6~7)
/// @note Item JC-45-2220.01x
/// @note Page 18
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::bank_group_bits(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_value)
{
    // =========================================================
    // Byte 4 maps
    // Item JC-45-2220.01x
    // Page 18
    // DDR4 SPD Document Release 3
    // Byte 4 (0x004): SDRAM Density and Banks
    // =========================================================
    static const std::vector<std::pair<uint8_t, uint8_t> > BANK_GROUP_BITS_MAP =
    {
        // {key byte, number of bank groups bits}
        {0, 0},
        {1, 1},
        {2, 2}
    };

    // Extracting desired bits
    constexpr size_t BYTE_INDEX = 4;
    uint8_t l_field_bits = extract_spd_field< BYTE_INDEX, BANK_GROUP_START, BANK_GROUP_LEN >(i_target, iv_spd_data);

    FAPI_INF("Field Bits value: %d", l_field_bits);

    // Check to assure SPD DRAM capacity (map) wont be at invalid values
    bool l_is_val_found = mss::find_value_from_key(BANK_GROUP_BITS_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for SPD DRAM bank groups") );

    FAPI_INF("%s. Number of bank group bits: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes number of SDRAM column address bits
/// @param[in] i_target dimm target
/// @param[out] o_value number of column address bits
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 5 (bits 2~0)
/// @note Item JC-45-2220.01x
/// @note Page 18
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::column_address_bits(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_value)
{
    // =========================================================
    // Byte 5 maps
    // Item JC-45-2220.01x
    // Page 18
    // DDR4 SPD Document Release 3
    // Byte 5 (0x005): SDRAM Addressing
    // =========================================================
    static const std::vector<std::pair<uint8_t, uint8_t> > COLUMN_ADDRESS_BITS_MAP =
    {
        //{key byte,col address bits}
        {0, 9},
        {1, 10},
        {2, 11},
        {3, 12}
    };

    // Extracting desired bits
    constexpr size_t BYTE_INDEX = 5;
    uint8_t l_field_bits = extract_spd_field< BYTE_INDEX, COL_ADDRESS_START, COL_ADDRESS_LEN >(i_target, iv_spd_data);

    FAPI_INF("Field Bits value: %d", l_field_bits);

    // Check to assure SPD DRAM capacity (map) wont be at invalid values
    bool l_is_val_found = mss::find_value_from_key(COLUMN_ADDRESS_BITS_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for SDRAM Column Address Bits") );

    FAPI_INF("%s. Number of Column Address Bits: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes number of SDRAM row address bits
/// @param[in] i_target dimm target
/// @param[out] o_value number of row address bits
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 5 (bits 5~3)
/// @note Item JC-45-2220.01x
/// @note Page 18
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::row_address_bits(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_value)
{
    // =========================================================
    // Byte 5 maps
    // Item JC-45-2220.01x
    // Page 18
    // DDR4 SPD Document Release 3
    // Byte 5 (0x005): SDRAM Addressing
    // =========================================================
    static const std::vector<std::pair<uint8_t, uint8_t> > ROW_ADDRESS_BITS_MAP =
    {
        //{key byte,row address bits}
        {0, 12},
        {1, 13},
        {2, 14},
        {3, 15},
        {4, 16},
        {5, 17},
        {6, 18}
    };

    // Extracting desired bits
    constexpr size_t BYTE_INDEX = 5;
    uint8_t l_field_bits = extract_spd_field< BYTE_INDEX, ROW_ADDRESS_START, ROW_ADDRESS_LEN >(i_target, iv_spd_data);

    FAPI_INF("Field Bits value: %d", l_field_bits);

    // Check to assure SPD DRAM capacity (map) wont be at invalid values
    bool l_is_val_found = mss::find_value_from_key(ROW_ADDRESS_BITS_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd:: fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for SDRAM Row Address Bits") );

    FAPI_INF("%s. Number of Row Address Bits: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Decodes Primary SDRAM signal loading
/// @param[in] i_target dimm target
/// @param[out] o_value enum representing signal loading type
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 6 (bits 1~0)
/// @note Item JC-45-2220.01x
/// @note Page 19
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::prim_sdram_signal_loading(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_value)
{
    // =========================================================
    // Byte 6 maps
    // Item JC-45-2220.01x
    // Page 19
    // DDR4 SPD Document Release 3
    // Byte 6 (0x006): Primary SDRAM Package Type
    // =========================================================
    static const std::vector<std::pair<uint8_t, uint8_t> > PRIM_SIGNAL_LOADING_MAP =
    {
        // {key byte, signal loading}
        {0, fapi2::ENUM_ATTR_EFF_PRIM_STACK_TYPE_SDP},
        {1, fapi2::ENUM_ATTR_EFF_PRIM_STACK_TYPE_DDP_QDP},
        {2, fapi2::ENUM_ATTR_EFF_PRIM_STACK_TYPE_3DS}
    };

    // Extracting desired bits
    constexpr size_t BYTE_INDEX = 6;
    uint8_t l_field_bits = extract_spd_field< BYTE_INDEX, PRIM_SIGNAL_LOAD_START, PRIM_SIGNAL_LOAD_LEN >(i_target,
                           iv_spd_data);

    FAPI_INF("Field Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(PRIM_SIGNAL_LOADING_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd:: fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for Primary SDRAM Signal Loading") );

    FAPI_INF("%s. Primary SDRAM Signal Loading: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes Primary SDRAM die count
/// @param[in] i_target dimm target
/// @param[out] o_value die count
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 6 (bits 6~4)
/// @note Item JC-45-2220.01x
/// @note Page 19
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::prim_sdram_die_count(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_value)
{
    // =========================================================
    // Byte 6 maps
    // Item JC-45-2220.01x
    // Page 19
    // DDR4 SPD Document Release 3
    // Byte 6 (0x006): Primary SDRAM Package Type
    // =========================================================
    static const std::vector<std::pair<uint8_t, uint8_t> > PRIM_DIE_COUNT_MAP =
    {
        // {key byte, number of die}
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 5},
        {5, 6},
        {6, 7},
        {7, 8}
    };

    // Extracting desired bits
    constexpr size_t BYTE_INDEX = 6;
    uint8_t l_field_bits = extract_spd_field< BYTE_INDEX, PRIM_DIE_COUNT_START, PRIM_DIE_COUNT_LEN >(i_target, iv_spd_data);

    FAPI_INF("Field Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(PRIM_DIE_COUNT_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd:: fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for SDRAM Row Address Bits") );

    FAPI_INF("%s. Number of Row Address Bits: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes Primary SDRAM  package type
/// @param[in] i_target dimm target
/// @param[out] o_value enum representing package type
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 6 (bit 7)
/// @note Item JC-45-2220.01x
/// @note Page 19
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::prim_sdram_package_type(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_value)
{
    // =========================================================
    // Byte 6 maps
    // Item JC-45-2220.01x
    // Page 19
    // DDR4 SPD Document Release 3
    // Byte 6 (0x006): Primary SDRAM Package Type
    // =========================================================
    static const std::vector<std::pair<uint8_t, uint8_t> > PRIM_PACKAGE_TYPE_MAP =
    {
        // {key byte, value}
        {0, MONOLITHIC},
        {1, NON_MONOLITHIC}
    };

    // Extracting desired bits
    constexpr size_t BYTE_INDEX = 6;
    uint8_t l_field_bits = extract_spd_field< BYTE_INDEX, PRIM_PACKAGE_TYPE_START, PRIM_PACKAGE_TYPE_LEN >(i_target,
                           iv_spd_data);

    FAPI_INF("Field Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(PRIM_PACKAGE_TYPE_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for Primary SDRAM package type") );

    FAPI_INF("%s. Primary SDRAM package type: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Decode SDRAM Maximum activate count
/// @param[in] i_target dimm target
/// @param[out] o_value enum representing max activate count
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 7 (bits 3~0)
/// @note Item JC-45-2220.01x
/// @note Page 20
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::maximum_activate_count(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint32_t& o_value)
{
    // =========================================================
    // Byte 7 maps
    // Item JC-45-2220.01x
    // Page 20
    // DDR4 SPD Document Release 3
    // Byte 7 (0x007): SDRAM Optional Features
    // =========================================================
    static const std::vector<std::pair<uint8_t, uint32_t> > MAC_MAP =
    {
        // {key byte, maximum activate count}
        {0, fapi2::ENUM_ATTR_EFF_DRAM_MAC_UNTESTED},
        {1, fapi2::ENUM_ATTR_EFF_DRAM_MAC_700K},
        {2, fapi2::ENUM_ATTR_EFF_DRAM_MAC_600K},
        {3, fapi2::ENUM_ATTR_EFF_DRAM_MAC_500K},
        {4, fapi2::ENUM_ATTR_EFF_DRAM_MAC_400K},
        {5, fapi2::ENUM_ATTR_EFF_DRAM_MAC_300K},
        {6, fapi2::ENUM_ATTR_EFF_DRAM_MAC_200K},
        {8, fapi2::ENUM_ATTR_EFF_DRAM_MAC_UNLIMITED}
    };

    // Extracting desired bits
    constexpr size_t BYTE_INDEX = 7;
    uint8_t l_field_bits = extract_spd_field< BYTE_INDEX, MAC_START, MAC_LEN >(i_target, iv_spd_data);

    FAPI_INF("Field Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(MAC_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for SDRAM Maximum Active Count (MAC)") );

    FAPI_INF("%s. Maximum Active Count (MAC): %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decode SDRAM Maximum activate window (multiplier), tREFI uknown at this point
/// @param[in]  i_target dimm target
/// @param[out] o_value max activate window multiplier
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 7 (bits 3~0)
/// @note Item JC-45-2220.01x
/// @note Page 20
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::maximum_activate_window_multiplier(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint32_t& o_value)
{
    // =========================================================
    // Byte 7 maps
    // Item JC-45-2220.01x
    // Page 20
    // DDR4 SPD Document Release 3
    // Byte 7 (0x007): SDRAM Optional Features
    // =========================================================
    // Multiplier with tREFI is not taken into account here
    static const std::vector<std::pair<uint8_t, uint32_t> > TMAW_MAP =
    {
        // {key byte, tMAW multiplier}
        {0, 8192},
        {1, 4096},
        {2, 2048}
    };

    // Extracting desired bits
    constexpr size_t BYTE_INDEX = 7;
    uint8_t l_field_bits = extract_spd_field< BYTE_INDEX, TMAW_START, TMAW_LEN >(i_target, iv_spd_data);

    FAPI_INF("Field Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(TMAW_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for Maximum Active Window (tMAW)") );

    FAPI_INF("%s. Maximum Active Window multiplier: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decode Post package repair (PPR)
/// @param[in] i_target dimm target
/// @param[out] o_value enum representing if (hard) PPR is supported
/// @return fapi2::ReturnCode
/// @note SPD Byte 9 (bits 7~6)
/// @note Item JC-45-2220.01x
/// @note Page 21
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::post_package_repair(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_value)
{
    // =========================================================
    // Byte 9 maps
    // Item JC-45-2220.01x
    // Page 21
    // DDR4 SPD Document Release 3
    // Byte 9 (0x009): Other SDRAM Optional Features
    // =========================================================
    static const std::vector<std::pair<uint8_t, uint8_t> > PPR_MAP =
    {
        // {key byte, value }
        {0, fapi2::ENUM_ATTR_EFF_DRAM_PPR_NOT_SUPPORTED},
        {1, fapi2::ENUM_ATTR_EFF_DRAM_PPR_SUPPORTED}
    };

    // Extracting desired bits
    constexpr size_t BYTE_INDEX = 9;
    uint8_t l_field_bits = extract_spd_field< BYTE_INDEX, PPR_START, PPR_LEN >(i_target, iv_spd_data);

    FAPI_INF("Field Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(PPR_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for PPR") );

    FAPI_INF("%s. Post Package Repair (PPR): %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes Secondary SDRAM signal loading
/// @param[in] i_target dimm target
/// @param[out] o_value enum representing signal loading type
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 10 (bits 1~0)
/// @note Item JC-45-2220.01x
/// @note Page 22
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::sec_sdram_signal_loading(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_value)
{
    // For General Section rev 1.0 of the SPD,
    // SPD Byte 10 (bits 1~0) were reserved
    // and coded as zeros. There was no concept of
    // secondary SDRAM signal loading so this
    // is thus hard-wired to zero.
    o_value = 0x00;
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Decode Soft post package repair (soft PPR)
/// @param[in] i_target dimm target
/// @param[out] o_value enum representing if soft PPR is supported
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 9 (bit 5)
/// @note Item JC-45-2220.01x
/// @note Page 21
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::soft_post_package_repair(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_value)
{
    // For General Section rev 1.0 of the SPD,
    // SPD Byte 9 (bit 5) was reserved
    // and coded as zeros. There was no concept of soft PPR so this
    // is thus hard-wired to zero.
    o_value = 0x00;
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Decodes Secondary DRAM Density Ratio
/// @param[in] i_target dimm target
/// @param[out] o_value raw bits from SPD
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 10 (bits 3~2)
/// @note Item JC-45-2220.01x
/// @note Page 22
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::sec_dram_density_ratio(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_value)
{
    // For General Section rev 1.0 of the SPD,
    // SPD Byte 10 (bits 3~2) were reserved
    // and coded as zeros. There was no concept of
    // secondary SDRAM density ratio so this
    // is thus hard-wired to zero.
    o_value = 0x00;
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Decodes Secondary SDRAM die count
/// @param[in] i_target dimm target
/// @param[out] o_value die count
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 10 (bits 6~4)
/// @note Item JC-45-2220.01x
/// @note Page 22
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::sec_sdram_die_count(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_value)
{
    // For General Section rev 1.0 of the SPD,
    // SPD Byte 10 (bits 6~4) were reserved
    // and coded as zeros. There was no concept of
    // secondary SDRAM hybrid media so this
    // is thus hard-wired to zero.
    o_value = 0x00;
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Decodes Secondary SDRAM package type
/// @param[in] i_target dimm target
/// @param[out] o_value  enum representing package type
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 10 (bit 7)
/// @note Item JC-45-2220.01x
/// @note Page 22
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::sec_sdram_package_type(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_value)
{
    // For General Section rev 1.0 of the SPD,
    // SPD Byte 10 (bit 7) was reserved
    // and coded as zeros. There was no concept of
    // secondary SDRAM package type so this
    // is thus hard-wired to zero.
    o_value = 0x00;
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Decode Module Nominal Voltage, VDD
/// @param[in] i_target dimm target
/// @param[out] o_value enum representing if 1.2V is operable
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 11 (bit 0)
/// @note Item JC-45-2220.01x
/// @note Page 23
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::operable_nominal_voltage(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_value)
{
    // =========================================================
    // Byte 11 maps
    // Item JC-45-2220.01x
    // Page 22-23
    // DDR4 SPD Document Release 3
    // Byte 11 (0x00B): Modle Nominal Voltage
    // =========================================================
    static const std::vector<std::pair<uint8_t, uint8_t> > OPERABLE_MAP =
    {
        // {key byte, value }
        {0, NOT_OPERABLE },
        {1, OPERABLE}
    };

    // Extracting desired bits
    constexpr size_t BYTE_INDEX = 11;
    uint8_t l_field_bits = extract_spd_field< BYTE_INDEX, OPERABLE_START, OPERABLE_LEN >(i_target, iv_spd_data);

    FAPI_INF("Field Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(OPERABLE_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for Operable nominal voltage") );

    FAPI_INF("%s. Operable: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decode Module Nominal Voltage, VDD
/// @param[in] i_target dimm target
/// @param[out] o_value enum representing if 1.2V is endurant
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 11 (bit 1)
/// @note Item JC-45-2220.01x
/// @note Page 23
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::endurant_nominal_voltage(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_value)
{
    // =========================================================
    // Byte 11 maps
    // Item JC-45-2220.01x
    // Page 22-23
    // DDR4 SPD Document Release 3
    // Byte 11 (0x00B): Modle Nominal Voltage
    // =========================================================
    static const std::vector<std::pair<uint8_t, uint8_t> > ENDURANT_MAP =
    {
        // {key byte, value }
        {0, NOT_ENDURANT},
        {1, ENDURANT}
    };

    // Extracting desired bits
    constexpr size_t BYTE_INDEX = 11;
    uint8_t l_field_bits = extract_spd_field< BYTE_INDEX, ENDURANT_START, ENDURANT_LEN >(i_target, iv_spd_data);

    FAPI_INF("Field Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(ENDURANT_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for Endurant nominal voltage") );

    FAPI_INF("%s. Endurant: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes SDRAM device width
/// @param[in] i_target dimm target
/// @param[out] o_value device width in bits
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 12 (bits 2~0)
/// @note Item JC-45-2220.01x
/// @note Page 23
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::device_width(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                        uint8_t& o_value)
{
    // =========================================================
    // Byte 12 maps
    // Item JC-45-2220.01x
    // Page 23
    // DDR4 SPD Document Release 3
    // Byte 12 (0x00C): Module Organization
    // =========================================================
    static const std::vector<std::pair<uint8_t, uint8_t> > DEVICE_WIDTH_MAP =
    {
        // {key byte, device width (bits)}
        {0, 4},
        {1, 8},
        {2, 16},
        {3, 32},
        // All others reserved
    };

    // Extracting desired bits
    constexpr size_t BYTE_INDEX = 12;
    uint8_t l_field_bits = extract_spd_field< BYTE_INDEX, SDRAM_WIDTH_START, SDRAM_WIDTH_LEN >(i_target, iv_spd_data);

    FAPI_INF("Field Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(DEVICE_WIDTH_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for Device Width") );

    FAPI_INF("%s. Device Width: %d bits",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Decodes number of package ranks per DIMM
/// @param[in] i_target dimm target
/// @param[out] o_value number of package ranks per DIMM
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 12 (bits 5~3)
/// @note Item JC-45-2220.01x
/// @note Page 23
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::num_package_ranks_per_dimm(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_value)
{
    // =========================================================
    // Byte 12 maps
    // Item JC-45-2220.01x
    // Page 23
    // DDR4 SPD Document Release 3
    // Byte 12 (0x00C): Module Organization
    // =========================================================
    static const std::vector<std::pair<uint8_t, uint8_t> > NUM_PACKAGE_RANKS_MAP =
    {
        // {key byte, num of package ranks per DIMM (package ranks)}
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 5},
    };

    // Extracting desired bits
    constexpr size_t BYTE_INDEX = 12;
    uint8_t l_field_bits = extract_spd_field< BYTE_INDEX, PACKAGE_RANKS_START, PACKAGE_RANKS_LEN >(i_target, iv_spd_data);

    FAPI_INF("Field Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(NUM_PACKAGE_RANKS_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for Num Package Ranks Per DIMM") );

    FAPI_INF("%s. Num Package Ranks per DIMM: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes Rank Mix
/// @param[in] i_target dimm target
/// @param[out] o_value rank mix value from SPD
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 12 (bit 6)
/// @note Item JC-45-2220.01x
/// @note Page 23
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::rank_mix(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                    uint8_t& o_value)
{
    // For General Section rev 1.0 of the SPD,
    // Decodes SPD Byte 3 (bits 4~6) were reserved
    // and coded as zeros. There was no concept of rank_mix so this
    // is thus hard-wired to zero.
    o_value = 0x00;
    return fapi2::FAPI2_RC_SUCCESS;

}

///
/// @brief Decodes primary bus width
/// @param[in] i_target dimm target
/// @param[out] o_value primary bus width in bits
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 13 (bits 2~0)
/// @note Item JC-45-2220.01x
/// @note Page 27
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::prim_bus_width(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_value)
{
    // =========================================================
    // Byte 13 maps
    // Item JC-45-2220.01x
    // Page 27
    // DDR4 SPD Document Release 3
    // Byte 13 (0x00D): Module Memory Bus Width
    // =========================================================
    static const std::vector<std::pair<uint8_t, uint8_t> > BUS_WIDTH_MAP =
    {
        // {key byte, bus width (in bits)
        {0, 8},
        {1, 16},
        {2, 32},
        {3, 64}
        // All others reserved
    };

    // Extracting desired bits
    constexpr size_t BYTE_INDEX = 13;
    uint8_t l_field_bits = extract_spd_field< BYTE_INDEX, BUS_WIDTH_START, BUS_WIDTH_LEN >(i_target, iv_spd_data);

    FAPI_INF("Field Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(BUS_WIDTH_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for Primary Bus Width") );

    FAPI_INF("%s. Primary Bus Width: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes bus width extension
/// @param[in] i_target dimm target
/// @param[out] o_value bus width extension in bits
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 13 (bits 2~0)
/// @note Item JC-45-2220.01x
/// @note Page 28
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::bus_width_extension(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_value)
{
    // =========================================================
    // Byte 13 maps
    // Item JC-45-2220.01x
    // Page 27
    // DDR4 SPD Document Release 3
    // Byte 13 (0x00D): Module Memory Bus Width
    // =========================================================
    static const std::vector<std::pair<uint8_t, uint8_t> > BUS_WIDTH_EXT_MAP =
    {
        {0, 0},
        {1, 8}
        // All others reserved
    };

    // Extracting desired bits
    constexpr size_t BYTE_INDEX = 13;
    uint8_t l_field_bits = extract_spd_field< BYTE_INDEX, BUS_EXT_WIDTH_START, BUS_EXT_WIDTH_LEN >(i_target, iv_spd_data);

    FAPI_INF("Field Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(BUS_WIDTH_EXT_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for Bus Width Extension") );

    FAPI_INF("%s. Bus Width Extension (bits): %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Decode Module Thermal Sensor
/// @param[in] i_target dimm target
/// @param[out] o_value thermal sensor value from SPD
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 14 (bit 7)
/// @note Item JC-45-2220.01x
/// @note Page 28
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::thermal_sensor(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_value)
{
    // Extracting desired bits
    constexpr size_t BYTE_INDEX = 14;
    uint8_t l_field_bits = extract_spd_field< BYTE_INDEX, THERM_SENSOR_START, THERM_SENSOR_LEN >(i_target, iv_spd_data);

    FAPI_INF("Field Bits value: %d", l_field_bits);

    // Check for valid value
    constexpr size_t INVALID_VALUE = 2; // single bit value 0 or 1
    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_field_bits < INVALID_VALUE,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for Thermal Sensor") );

    // Update output after check passes
    o_value = l_field_bits;

    FAPI_INF("%s. Thermal Sensor: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decode Extended Base Module Type
/// @param[in] i_target dimm target
/// @param[out] o_value raw data from SPD
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 15 (bits 3~0)
/// @note Item JC-45-2220.01x
/// @note Page 28
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::extended_base_module_type(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_value)
{
    // Extracting desired bits
    constexpr size_t BYTE_INDEX = 15;
    uint8_t l_field_bits = extract_spd_field< BYTE_INDEX, EXT_MOD_TYPE_START, EXT_MOD_TYPE_LEN >(i_target, iv_spd_data);

    FAPI_INF("Field Bits value: %d", l_field_bits);

    // Check for valid value
    // Currently reserved to 0b000
    constexpr size_t RESERVED = 0;
    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_field_bits == RESERVED,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for Extended Base Module Type") );

    // Update output for check passes
    o_value = l_field_bits;

    FAPI_INF("%s. Extended Base Module Type: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Decode Fine Timebase
/// @param[in] i_target dimm target
/// @param[out] o_value fine_timebase from SPD in picoseconds
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 17 (bits 1~0)
/// @note Item JC-45-2220.01x
/// @note Page 29
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::fine_timebase(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    // =========================================================
    // Byte 17 maps
    // Item JC-45-2220.01x
    // Page 29
    // DDR4 SPD Document Release 3
    // Byte 17 (0x011): Timebases
    // =========================================================
    // Created a maps of a single value in case mapping expands to more values
    static const std::vector<std::pair<uint8_t, int64_t> > FINE_TIMEBASE_MAP =
    {
        // {key byte, fine timebase (in picoseconds)
        {0, 1}
        // All others reserved
    };

    // Extracting desired bits
    constexpr size_t BYTE_INDEX = 17;
    uint8_t l_field_bits = extract_spd_field< BYTE_INDEX, FINE_TIMEBASE_START, FINE_TIMEBASE_LEN >(i_target, iv_spd_data);

    FAPI_INF("Field Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(FINE_TIMEBASE_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for Fine Timebase") );

    FAPI_INF("%s. Fine Timebase: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decode Medium Timebase
/// @param[in] i_target dimm target
/// @param[out] o_value  medium timebase from SPD in picoseconds
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 17 (bits 3~2)
/// @note Item JC-45-2220.01x
/// @note Page 29
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::medium_timebase(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    // =========================================================
    // Byte 17 maps
    // Item JC-45-2220.01x
    // Page 29
    // DDR4 SPD Document Release 3
    // Byte 17 (0x011): Timebases
    // =========================================================
    // Created a maps of a single value in case mapping expands to more values
    static const std::vector<std::pair<uint8_t, int64_t> > MEDIUM_TIMEBASE_MAP =
    {
        // {key byte, medium timebase (in picoseconds)
        {0, 125}
        // All others reserved
    };

    // Extracting desired bits
    constexpr size_t BYTE_INDEX = 17;
    uint8_t l_field_bits = extract_spd_field< BYTE_INDEX, MED_TIMEBASE_START, MED_TIMEBASE_LEN >(i_target, iv_spd_data);

    FAPI_INF("Field Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(MEDIUM_TIMEBASE_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_is_val_found,
              BYTE_INDEX,
              l_field_bits,
              "Failed check for Medium Timebase") );

    FAPI_INF("%s. Medium Timebase: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Decodes SDRAM Minimum Cycle Time in MTB
/// @param[in] i_target dimm target
/// @param[out] o_value tCKmin in MTB units
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 18
/// @note Item JC-45-2220.01x
/// @note Page 31-32
/// @note DDR4 SPD Document Release 3
/// @warning If tCKmin cannot be divided evenly by the MTB,
/// this byte must be rounded up to the next larger
/// integer and the Fine Offset for tCKmin (SPD byte 125)
/// used for correction to get the actual value.
///
fapi2::ReturnCode decoder::min_cycle_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    // Explicit conversion
    constexpr size_t BYTE_INDEX = 18;
    int64_t l_timing_val = int64_t(iv_spd_data[BYTE_INDEX]);

    // Trace in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: %d.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_timing_val);

    // Check if value is valid
    constexpr int64_t TIMING_LOWER_BOUND = 1; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 255; // from JEDEC

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             BYTE_INDEX,
             l_timing_val,
             "Failed check on the min cycle time (tckmin) in MTB") );

    // Update output after check passes
    o_value = l_timing_val;

    FAPI_INF("%s. Minimum Cycle Time (tCKmin) in MTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes SDRAM Maximum Cycle Time in MTB
/// @param[in] i_target dimm target
/// @param[out] o_value tCKmax in MTB units
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 19
/// @note Item JC-45-2220.01x
/// @note Page 32
/// @note DDR4 SPD Document Release 3
/// @warning If tCKmax cannot be divided evenly by the MTB,
/// this byte must be rounded up to the next larger
/// integer and the Fine Offset for tCKmax (SPD byte 124)
/// used for correction to get the actual value.
///
fapi2::ReturnCode decoder::max_cycle_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    // Explicit conversion
    constexpr size_t BYTE_INDEX = 19;
    int64_t l_timing_val = int64_t(iv_spd_data[BYTE_INDEX]);

    // Trace in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: %d.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_timing_val);

    // Check for valid value
    constexpr int64_t TIMING_LOWER_BOUND = 1; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 255; // from JEDEC

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             BYTE_INDEX,
             l_timing_val,
             "Failed check on the max cycle time (tckmax) in MTB") );

    // Update output after check passes
    o_value = l_timing_val;

    FAPI_INF("%s. Maximum Cycle Time (tCKmax) in MTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Decode CAS Latencies Supported
/// @param[in] i_target dimm target
/// @param[out] o_value bitmap of supported CAS latencies
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Bytes 20-23
/// @note Item JC-45-2220.01x
/// @note Page 33-34
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::supported_cas_latencies(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint64_t& o_value)
{
    // Trace print in the front assists w/ debug
    constexpr size_t FIRST_BYTE = 20;
    uint8_t first_raw_byte = iv_spd_data[FIRST_BYTE];
    FAPI_INF("%s SPD data at Byte %d: 0x%llX.",
             c_str(i_target),
             FIRST_BYTE,
             first_raw_byte);

    constexpr size_t SEC_BYTE = 21;
    uint8_t sec_raw_byte = iv_spd_data[SEC_BYTE];
    FAPI_INF("%s SPD data at Byte %d: 0x%llX.",
             c_str(i_target),
             SEC_BYTE,
             sec_raw_byte);

    constexpr size_t THIRD_BYTE = 22;
    uint8_t third_raw_byte = iv_spd_data[THIRD_BYTE];
    FAPI_INF("%s SPD data at Byte %d: 0x%llX.",
             c_str(i_target),
             THIRD_BYTE,
             third_raw_byte);

    constexpr size_t FOURTH_BYTE = 23;
    uint8_t fourth_raw_byte = iv_spd_data[FOURTH_BYTE];
    FAPI_INF("%s SPD data at Byte %d: 0x%llX.",
             c_str(i_target),
             FOURTH_BYTE,
             fourth_raw_byte);

    // Buffers used for bit manipulation
    // Combine Bytes to create bitmap - right aligned
    fapi2::buffer<uint64_t> l_buffer;

    l_buffer.insertFromRight<CAS_BYTE_1_START, CAS_BYTE_1_LEN>(first_raw_byte)
    .insertFromRight<CAS_BYTE_2_START, CAS_BYTE_2_LEN>(sec_raw_byte)
    .insertFromRight<CAS_BYTE_3_START, CAS_BYTE_3_LEN>(third_raw_byte)
    .insertFromRight<CAS_BYTE_4_START, CAS_BYTE_4_LEN>(fourth_raw_byte);

    // According to the JEDEC spec:
    // Byte 22 (Bits 7~0) and Byte 23 are reserved and thus not supported
    constexpr size_t MAX_VALID_VAL = 0x3FFFF;

    // Check for a valid value
    uint64_t l_supported_cl = l_buffer;
    FAPI_TRY( mss::check::spd::fail_for_invalid_value(i_target,
              l_supported_cl <= MAX_VALID_VAL,
              FOURTH_BYTE,
              fourth_raw_byte,
              "Failed check on CAS latencies supported") );

    // Update output value only if range check passes
    o_value = l_supported_cl;

    FAPI_INF("%s. CAS latencies supported (bitmap): 0x%llX",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Decodes SDRAM Minimum CAS Latency Time in MTB
/// @param[in] i_target dimm target
/// @param[out] o_value tAAmin in MTB units
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 24
/// @note Item JC-45-2220.01x
/// @note Page 34
/// @note DDR4 SPD Document Release 3
/// @warning If tAAmin cannot be divided evenly by the MTB,
/// this byte must be rounded up to the next larger
/// integer and the Fine Offset for tAAmin (SPD byte 123)
/// used for correction to get the actual value.
///
fapi2::ReturnCode decoder::min_cas_latency_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    // Explicit conversion
    constexpr size_t BYTE_INDEX = 24;
    int64_t l_timing_val = int64_t(iv_spd_data[BYTE_INDEX]);

    // Trace in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_timing_val);

    // Check for valid value
    constexpr int64_t TIMING_LOWER_BOUND = 1; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 255; // from JEDEC

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             BYTE_INDEX,
             l_timing_val,
             "Failed check on the Minimum CAS Latency Time (tAAmin) in MTB") );

    // Only update output if it passes check
    o_value = l_timing_val;

    FAPI_INF("%s. Minimum CAS Latency Time (tAAmin) in MTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes SDRAM Minimum RAS to CAS Delay Time in MTB
/// @param[in] i_target dimm target
/// @param[out] o_value tRCDmin in MTB units
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 25
/// @note Item JC-45-2220.01x
/// @note Page 35
/// @note DDR4 SPD Document Release 3
/// @warning If tRCDmin cannot be divided evenly by the MTB,
/// this byte must be rounded up to the next larger
/// integer and the Fine Offset for tRCDmin (SPD byte 122)
/// used for correction to get the actual value
///
fapi2::ReturnCode decoder::min_ras_to_cas_delay_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,

        int64_t& o_value)
{
    // Explicit conversion
    constexpr size_t BYTE_INDEX = 25;
    int64_t l_timing_val = int64_t(iv_spd_data[BYTE_INDEX]);

    // Trace in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_timing_val);

    // Find valid value
    constexpr int64_t TIMING_LOWER_BOUND = 1; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 255; // from JEDEC

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             BYTE_INDEX,
             l_timing_val,
             "Failed check on the Minimum RAS to CAS Delay Time (tRCDmin) in MTB") );

    // Only update output if it passes check
    o_value = l_timing_val;

    FAPI_INF("%s. Minimum RAS to CAS Delay Time (tRCDmin) in MTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes SDRAM Minimum Row Precharge Delay Time in MTB
/// @param[in] i_target dimm target
/// @param[out] o_value tRPmin in MTB units
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 26
/// @note Item JC-45-2220.01x
/// @note Page 36-37
/// @note DDR4 SPD Document Release 3
/// @warning If tRPmin cannot be divided evenly by the MTB,
/// this byte must be rounded up to the next larger
/// integer and the Fine Offset for tRPmin (SPD byte 121)
/// used for correction to get the actual value
///
fapi2::ReturnCode decoder::min_row_precharge_delay_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    // Explicit conversion
    constexpr size_t BYTE_INDEX = 26;
    int64_t l_timing_val = int64_t(iv_spd_data[BYTE_INDEX]);

    // Trace in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             l_timing_val);

    // Check for valid value
    constexpr int64_t TIMING_LOWER_BOUND = 1; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 255; // from JEDEC

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             BYTE_INDEX,
             l_timing_val,
             "Failed check on the Minimum Row Precharge Delay Time (tRPmin) in MTB") );

    // Only update output if it passes check
    o_value = l_timing_val;

    FAPI_INF("%s. Minimum Row Precharge Delay Time (tRPmin) in MTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Decodes SDRAM Minimum Active to Precharge Delay Time in MTB
/// @param[in] i_target dimm target
/// @param[out] o_value tRASmin in MTB units
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 27 (bits 3~0) & Byte 28 (bits 7~0)
/// @note Item JC-45-2220.01x
/// @note Page 38
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::min_active_to_precharge_delay_time(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    constexpr size_t BYTE_INDEX_MSN = 27;
    uint8_t tRASmin_MSN = extract_spd_field< BYTE_INDEX_MSN, TRASMIN_MSN_START, TRASMIN_MSN_LEN >(i_target, iv_spd_data);

    constexpr size_t BYTE_INDEX_LSB = 28;
    uint8_t tRASmin_LSB = extract_spd_field< BYTE_INDEX_LSB, TRASMIN_LSB_START, TRASMIN_LSB_LEN >(i_target, iv_spd_data);

    // Combining bits to create timing value (in a buffer)
    constexpr size_t MSN_START = 52;
    constexpr size_t MSN_LEN = 4;
    constexpr size_t LSB_START = 56;
    constexpr size_t LSB_LEN = 8;

    fapi2::buffer<int64_t> l_buffer;

    l_buffer.insertFromRight<MSN_START, MSN_LEN>( tRASmin_MSN )
    .insertFromRight<LSB_START, LSB_LEN>( tRASmin_LSB );

    // Extract timing value from the buffer into an integral type
    int64_t l_timing_val = l_buffer;

    // JEDEC spec limits for this timing value
    constexpr int64_t TIMING_LOWER_BOUND = 1; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 4095; // from JEDEC

    // best we can do?
    // I had to combine parts from two different bytes.
    // But byte 28 of the JEDEC spec explains how to piece this together - AAM
    constexpr size_t ERROR_BYTE_INDEX = 28;

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             ERROR_BYTE_INDEX,
             l_timing_val,
             "Failed check on the Minimum Active to Precharge Delay Time (tRASmin) in MTB") );

    // Update output only after check passes
    o_value = l_timing_val;

    FAPI_INF("%s. Minimum Active to Precharge Delay Time (tRASmin) in MTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Decodes SDRAM Minimum Active to Active/Refresh Delay Time in MTB
/// @param[in] i_target dimm target
/// @param[out] o_value tRCmin in MTB units
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 27 (bits 7~4) & SPD Byte 29 (bits 7~0)
/// @note Item JC-45-2220.01x
/// @note Page 38
/// @note DDR4 SPD Document Release 3
/// @warning If tRCmin cannot be divided evenly by the MTB,
/// this byte must be rounded up to the next larger
/// integer and the Fine Offset for tRCmin (SPD byte 120)
/// used for correction to get the actual value.
///
fapi2::ReturnCode decoder::min_active_to_active_refresh_delay_time(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    constexpr size_t BYTE_INDEX_MSN = 27;
    uint8_t tRCmin_MSN = extract_spd_field< BYTE_INDEX_MSN, TRCMIN_MSN_START, TRCMIN_MSN_LEN >(i_target, iv_spd_data);

    constexpr size_t BYTE_INDEX_LSB = 29;
    uint8_t tRCmin_LSB = extract_spd_field< BYTE_INDEX_LSB, TRCMIN_LSB_START, TRCMIN_LSB_LEN >(i_target, iv_spd_data);

    // Combining bits to create timing value (in a buffer)
    constexpr size_t MSN_START = 52;
    constexpr size_t MSN_LEN = 4;
    constexpr size_t LSB_START = 56;
    constexpr size_t LSB_LEN = 8;

    fapi2::buffer<int64_t> l_buffer;

    l_buffer.insertFromRight<MSN_START, MSN_LEN>( tRCmin_MSN )
    .insertFromRight<LSB_START, LSB_LEN>( tRCmin_LSB );

    // Extract timing value from the buffer into an integral type
    int64_t l_timing_val = l_buffer;

    // JEDEC spec limits for this timing value
    constexpr int64_t TIMING_LOWER_BOUND = 1; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 4095; // from JEDEC

    // best we can do?
    // I had to combine parts from two different bytes.
    // But byte 29 of the JEDEC spec explains how to piece this together - AAM
    constexpr size_t ERROR_BYTE_INDEX = 29;

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             ERROR_BYTE_INDEX,
             l_timing_val,
             "Failed check on the Minimum Active to Active/Refresh Delay Time (tRCmin) in MTB") );

    // Update output only after check passes
    o_value = l_timing_val;

    FAPI_INF("%s. Minimum Active to Active/Refresh Delay Time (tRCmin) in MTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Decodes SDRAM Minimum Refresh Recovery Delay Time 1
/// @param[in] i_target dimm target
/// @param[out] o_value tRFC1min in MTB units
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 30 & Byte 31
/// @note Item JC-45-2220.01x
/// @note Page 39-40
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::min_refresh_recovery_delay_time_1(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    constexpr size_t BYTE_INDEX_MSB = 31;
    uint8_t tRFC1min_MSB = extract_spd_field< BYTE_INDEX_MSB, TRFC1MIN_MSB_START, TRFC1MIN_MSB_LEN >(i_target, iv_spd_data);

    constexpr size_t BYTE_INDEX_LSB = 30;
    uint8_t tRFC1min_LSB = extract_spd_field< BYTE_INDEX_LSB, TRFC1MIN_LSB_START, TRFC1MIN_LSB_LEN >(i_target, iv_spd_data);

    // Combining bits to create timing value (in a buffer)
    constexpr size_t MSB_START = 48;
    constexpr size_t MSB_LEN = 8;
    constexpr size_t LSB_START = 56;
    constexpr size_t LSB_LEN = 8;

    fapi2::buffer<int64_t> l_buffer;

    l_buffer.insertFromRight<MSB_START, MSB_LEN>( tRFC1min_MSB )
    .insertFromRight<LSB_START, LSB_LEN>( tRFC1min_LSB );

    // Extract timing value from the buffer into an integral type
    int64_t l_timing_val = l_buffer;

    // JEDEC spec limits for this timing value
    constexpr int64_t TIMING_LOWER_BOUND = 1; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 65535; // from JEDEC

    // best we can do?
    // I had to combine parts from two different bytes.
    // Chose one of them (byte 30) to for error printout of this decode
    constexpr size_t ERROR_BYTE_INDEX = 30;

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             ERROR_BYTE_INDEX,
             l_timing_val,
             "Failed check on the Minimum Refresh Recovery Delay Time 1 (tRFC1min) in MTB") );

    // Update output only after check passes
    o_value = l_timing_val;

    FAPI_INF("%s. Minimum Refresh Recovery Delay Time 1 (tRFC1min) in MTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes SDRAM Minimum Refresh Recovery Delay Time 2
/// @param[in] i_target dimm target
/// @param[out] o_value tRFC2min in MTB units
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 32 & Byte 33
/// @note Item JC-45-2220.01x
/// @note Page 40
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::min_refresh_recovery_delay_time_2(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    constexpr size_t BYTE_INDEX_MSB = 33;
    uint8_t tRFC2min_MSB = extract_spd_field< BYTE_INDEX_MSB, TRFC2MIN_MSB_START, TRFC2MIN_MSB_LEN>(i_target, iv_spd_data);

    constexpr size_t BYTE_INDEX_LSB = 32;
    uint8_t tRFC2min_LSB = extract_spd_field< BYTE_INDEX_LSB, TRFC2MIN_LSB_START, TRFC2MIN_LSB_LEN>(i_target, iv_spd_data);

    // Combining bits to create timing value (in a buffer)
    constexpr size_t MSB_START = 48;
    constexpr size_t MSB_LEN = 8;
    constexpr size_t LSB_START = 56;
    constexpr size_t LSB_LEN = 8;

    fapi2::buffer<int64_t> l_buffer;

    l_buffer.insertFromRight<MSB_START, MSB_LEN>( tRFC2min_MSB )
    .insertFromRight<LSB_START, LSB_LEN>( tRFC2min_LSB );

    // Extract timing value from the buffer into an integral type
    int64_t l_timing_val = l_buffer;

    // JEDEC spec limits for this timing value
    constexpr int64_t TIMING_LOWER_BOUND = 1; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 65535; // from JEDEC

    // best we can do?
    // I had to combine parts from two different bytes.
    // Chose one of them (byte 33) to for error printout of this decode
    constexpr size_t ERROR_BYTE_INDEX = 33;

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             ERROR_BYTE_INDEX,
             l_timing_val,
             "Failed check on the Minimum Refresh Recovery Delay Time 2 (tRFC2min) in MTB") );

    // Update output only after check passes
    o_value = l_timing_val;

    FAPI_INF("%s. Minimum Refresh Recovery Delay Time 2 (tRFC2min) in MTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes SDRAM Minimum Refresh Recovery Delay Time 4
/// @param[in] i_target dimm target
/// @param[out] o_value tRFC4min in MTB units
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 34 & Byte 35
/// @note Item JC-45-2220.01x
/// @note Page 40
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::min_refresh_recovery_delay_time_4(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    constexpr size_t BYTE_INDEX_MSB = 35;
    uint8_t tRFC4min_MSB = extract_spd_field< BYTE_INDEX_MSB, TRFC4MIN_MSB_START, TRFC4MIN_MSB_LEN>(i_target, iv_spd_data);

    constexpr size_t BYTE_INDEX_LSB = 34;
    uint8_t tRFC4min_LSB = extract_spd_field< BYTE_INDEX_LSB, TRFC4MIN_LSB_START, TRFC4MIN_LSB_LEN>(i_target, iv_spd_data);

    // Combining bits to create timing value (in a buffer)
    constexpr size_t MSB_START = 48;
    constexpr size_t MSB_LEN = 8;
    constexpr size_t LSB_START = 56;
    constexpr size_t LSB_LEN = 8;

    fapi2::buffer<int64_t> l_buffer;

    l_buffer.insertFromRight<MSB_START, MSB_LEN>( tRFC4min_MSB )
    .insertFromRight<LSB_START, LSB_LEN>( tRFC4min_LSB );

    // Extract timing value from the buffer into an integral type
    int64_t l_timing_val = l_buffer;

    // JEDEC spec limits for this timing value
    constexpr int64_t TIMING_LOWER_BOUND = 1; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 65535; // from JEDEC

    // best we can do?
    // I had to combine parts from two different bytes.
    // Chose one of them (byte 34) for error printout of this decode
    constexpr size_t ERROR_BYTE_INDEX = 34;

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             ERROR_BYTE_INDEX,
             l_timing_val,
             "Failed check on the Minimum Refresh Recovery Delay Time 4 (tRFC4min) in MTB") );

    // Update output only after check passes
    o_value = l_timing_val;

    FAPI_INF("%s. Minimum Refresh Recovery Delay Time 4 (tRFC4min) in MTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes SDRAM Minimum Four Activate Window Delay Time
/// @param[in] i_target dimm target
/// @param[out] o_value tFAWmin in MTB units
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 36 (bits 3~0) & Byte 37 (bits 7~0)
/// @note Item JC-45-2220.01x
/// @note Page 42
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::min_tfaw(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                    int64_t& o_value)
{
    constexpr size_t BYTE_INDEX_MSN = 36;
    uint8_t tFAWmin_MSN = extract_spd_field< BYTE_INDEX_MSN, TFAWMIN_MSN_START, TFAWMIN_MSN_LEN >(i_target, iv_spd_data);

    constexpr size_t BYTE_INDEX_LSB = 37;
    uint8_t tFAWmin_LSB = extract_spd_field< BYTE_INDEX_LSB, TFAWMIN_LSB_START, TFAWMIN_LSB_LEN >(i_target, iv_spd_data);

    // Combining bits to create timing value (in a buffer)
    constexpr size_t MSN_START = 52;
    constexpr size_t MSN_LEN = 4;
    constexpr size_t LSB_START = 56;
    constexpr size_t LSB_LEN = 8;

    fapi2::buffer<int64_t> l_buffer;

    l_buffer.insertFromRight<MSN_START, MSN_LEN>( tFAWmin_MSN ).
    insertFromRight<LSB_START, LSB_LEN>( tFAWmin_LSB );

    // Extract timing value from the buffer into an integral type
    int64_t l_timing_val = l_buffer;

    // JEDEC spec limits for this timing value
    constexpr int64_t TIMING_LOWER_BOUND = 1; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 65535; // from JEDEC

    // best we can do?
    // I had to combine parts from two different bytes.
    // Chose one of them (byte 37) to for error printout of this decode
    constexpr size_t ERROR_BYTE_INDEX = 37;

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             ERROR_BYTE_INDEX,
             l_timing_val,
             "Failed check on the Minimum Four Activate Window Delay Time (tFAWmin) in MTB") );

    // Update output only after check passes
    o_value = l_timing_val;

    FAPI_INF("%s. Minimum Four Activate Window Delay Time (tFAWmin) in MTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes Minimum Activate to Activate Delay Time - Different Bank Group
/// @param[in] i_target dimm target
/// @param[out] o_value tRRD_Smin MTB units
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 38
/// @note Item JC-45-2220.01x
/// @note Page 43
/// @note DDR4 SPD Document Release 3
/// @warning If tRRD_Smin cannot be divided evenly by the MTB,
/// this byte must be rounded up to the next larger
/// integer and the Fine Offset for tRRD_Smin (SPD byte 119)
/// used for correction to get the actual value.
///
fapi2::ReturnCode decoder::min_trrd_s(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                      int64_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 38;

    FAPI_INF("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             iv_spd_data[BYTE_INDEX]);

    // Retrieve Minimum Activate to Activate Delay Time - Different Bank Group
    // explicit conversion to int64_t
    int64_t l_timing_val = int64_t(iv_spd_data[BYTE_INDEX]);

    // Find valid value
    constexpr int64_t TIMING_LOWER_BOUND = 1; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 255; // from JEDEC

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             BYTE_INDEX,
             l_timing_val,
             "Failed check on Minimum Activate to Activate Delay Time - Different Bank Group (tRRD_Smin) in MTB") );

    // Update output value only if range check passes
    o_value = l_timing_val;

    FAPI_INF("%s. Minimum Activate to Activate Delay Time - Different Bank Group (tRRD_Smin) in MTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes Minimum Activate to Activate Delay Time - Same Bank Group
/// @param[in] i_target dimm target
/// @param[out] o_value tRRD_Lmin MTB units
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 39
/// @note Item JC-45-2220.01x
/// @note Page 43-44
/// @note DDR4 SPD Document Release 3
/// @warning If tRRD_Lmin cannot be divided evenly by the MTB,
/// this byte must be rounded up to the next larger
/// integer and the Fine Offset for tRRD_Lmin (SPD byte 118)
/// used for correction to get the actual value.
///
fapi2::ReturnCode decoder::min_trrd_l(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                      int64_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 39;

    FAPI_INF("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             iv_spd_data[BYTE_INDEX]);

    // Retrieve Minimum Activate to Activate Delay Time - Same Bank Group
    // explicit conversion to int64_t
    int64_t l_timing_val = int64_t(iv_spd_data[BYTE_INDEX]);

    // Find valid value
    constexpr int64_t TIMING_LOWER_BOUND = 1; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 255; // from JEDEC

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             BYTE_INDEX,
             l_timing_val,
             "Failed check on Minimum Activate to Activate Delay Time - Same Bank Group (tRRD_Lmin) in MTB") );

    // Update output value only if range check passes
    o_value = l_timing_val;

    FAPI_INF("%s. Minimum Activate to Activate Delay Time - Same Bank Group (tRRD_Lmin) in MTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes Minimum CAS to CAS Delay Time - Same Bank Group
/// @param[in] i_target dimm target
/// @param[out] o_value tCCD_Lmin MTB units
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 40
/// @note Item JC-45-2220.01x
/// @note Page 44-45
/// @note DDR4 SPD Document Release 3
/// @warning If tCCD_Lmin cannot be divided evenly by the MTB,
/// this byte must be rounded up to the next larger
/// integer and the Fine Offset for tCCD_Lmin (SPD byte 117)
/// used for correction to get the actual value.
///
fapi2::ReturnCode decoder::min_tccd_l(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                      int64_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 40;

    FAPI_INF("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             iv_spd_data[BYTE_INDEX]);

    // Retrieve Minimum CAS to CAS Delay Time - Same Bank Group
    // explicit conversion to int64_t
    int64_t l_timing_val = int64_t(iv_spd_data[BYTE_INDEX]);

    // Check for valid value
    constexpr int64_t TIMING_LOWER_BOUND = 1; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 255; // from JEDEC

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             BYTE_INDEX,
             l_timing_val,
             "Failed check on Minimum CAS to CAS Delay Time - Same Bank Group (tCCD_Lmin) in MTB") );

    // Update output value only if range check passes
    o_value = l_timing_val;

    FAPI_INF("%s. Minimum CAS to CAS Delay Time - Same Bank Group (tCCD_Lmin) in MTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes Minimum Write Recovery Time
/// @param[in] i_target dimm target
/// @param[out] o_value tWRmin in MTB units
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 41 (bits 3~0) & Byte 42 (bits 7~0)
/// @note Item JC-45-2220.01x
/// @note Page 40
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::min_write_recovery_time(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    // For General Section rev 1.0 of the SPD,
    // SPD Byte 41 (bits 3~0) & Byte 42 (bits 7~0) were reserved
    // and coded as zeros. There was no concept of
    // min write recovery time so this
    // is thus hard-wired to zero.
    o_value = 0x00;
    return fapi2::FAPI2_RC_SUCCESS;

}

///
/// @brief Decodes Minimum Write to Read Time - Different Bank Group
/// @param[in] i_target dimm target
/// @param[out] o_value tWRT_Smin in MTB units
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 43 (bits 3~0) & Byte 44 (bits 7~0)
/// @note Item JC-45-2220.01x
/// @note Page 40
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::min_twtr_s(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                      int64_t& o_value)
{
    // For General Section rev 1.0 of the SPD,
    // SPD Byte 43 (bits 3~0) & Byte 44 (bits 7~0) were reserved
    // and coded as zeros. There was no concept of twtr_s so this
    // is thus hard-wired to zero.
    o_value = 0x00;
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Decodes Minimum Write to Read Time - Same Bank Group
/// @param[in] i_target dimm target
/// @param[out] o_value tWRT_Lmin in MTB units
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 43 (bits 7~4) & Byte 45 (bits 7~0)
/// @note Item JC-45-2220.01x
/// @note Page 46
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::min_twtr_l(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
                                      int64_t& o_value)
{
    // For General Section rev 1.0 of the SPD,
    // SPD Byte 43 (bits 7~4) & Byte 45 (bits 7~0) were reserved
    // and coded as zeros. There was no concept of twtr_l so this
    // is thus hard-wired to zero.
    o_value = 0x00;
    return fapi2::FAPI2_RC_SUCCESS;

}

///
/// @brief Decodes Fine Offset for Minimum CAS to CAS Delay Time - Same Bank Group
/// @param[in] i_target dimm target
/// @param[out] o_value tCCD_Lmin offset in FTB units
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 117
/// @note Item JC-45-2220.01x
/// @note Page 52
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::fine_offset_min_tccd_l(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 117;

    FAPI_INF("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             iv_spd_data[BYTE_INDEX]);

    // Retrieve Fine Offset for Minimum CAS to CAS Delay Time
    // int8_t conversion - allows me to get a negative offset
    // then implicit conversion to int64_t
    int64_t l_timing_val = int8_t(iv_spd_data[BYTE_INDEX]);

    // Check for valid value
    constexpr int64_t TIMING_LOWER_BOUND = -128; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 127; // from JEDEC

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             BYTE_INDEX,
             l_timing_val,
             "Failed check on the fine offset for min RAS to CAS Delay Time (tCCD_Lmin)") );

    // Update output value only if range check passes
    o_value = l_timing_val;

    FAPI_INF("%s. Fine offset for Minimum RAS to CAS Delay Time (tCCD_Lmin) in FTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes Fine Offset for Minimum Activate to Activate Delay Time - Same Bank Group
/// @param[in] i_target dimm target
/// @param[out] o_value tRRD_Lmin offset in FTB units
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 118
/// @note Item JC-45-2220.01x
/// @note Page 52
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::fine_offset_min_trrd_l(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 118;

    FAPI_INF("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             iv_spd_data[BYTE_INDEX]);

    // Retrieve Fine Offset for Minimum Activate to Activate Delay Time
    // int8_t conversion - allows me to get a negative offset
    // then implicit conversion to int64_t
    int64_t l_timing_val = int8_t(iv_spd_data[BYTE_INDEX]);

    // Check for valid value
    constexpr int64_t TIMING_LOWER_BOUND = -128; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 127; // from JEDEC

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             BYTE_INDEX,
             l_timing_val,
             "Failed check on the fine offset for Minimum Activate to Activate Delay Time (tRRD_Lmin)") );

    // Update output value only if range check passes
    o_value = l_timing_val;

    FAPI_INF("%s. Fine offset for Minimum Activate to Activate Delay Time (tRRD_Lmin) in FTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes Fine Offset for Minimum Activate to Activate Delay Time - Different Bank Group
/// @param[in] i_target dimm target
/// @param[out] o_value tRRD_Smin offset in FTB units
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 119
/// @note Item JC-45-2220.01x
/// @note Page 52
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::fine_offset_min_trrd_s(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 119;

    FAPI_INF("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             iv_spd_data[BYTE_INDEX]);

    // Retrieve Fine Offset for Minimum Activate to Activate Delay Time - Different Bank Group
    // int8_t conversion - allows me to get a negative offset
    // then implicit conversion to int64_t
    int64_t l_timing_val = int8_t(iv_spd_data[BYTE_INDEX]);

    // Check for valid value
    constexpr int64_t TIMING_LOWER_BOUND = -128; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 127; // from JEDEC

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             BYTE_INDEX,
             l_timing_val,
             "Failed check on the fine offset for Minimum Activate to Activate Delay Time - Different Bank Group (tRRD_Smin)") );

    // Update output value only if range check passes
    o_value = l_timing_val;

    FAPI_INF("%s. Fine offset for Minimum Activate to Activate Delay Time - Different Bank Group (tRRD_Smin) in FTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes Fine Offset for Minimum Active to Active/Refresh Delay Time
/// @param[in] i_target dimm target
/// @param[out] o_value tRCmin offset in FTB units
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 120
/// @note Item JC-45-2220.01x
/// @note Page 52
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::fine_offset_min_trc(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 120;

    FAPI_INF("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             iv_spd_data[BYTE_INDEX]);

    // Retrieve Fine Offset for Minimum Active to Active/Refresh Delay Time
    // int8_t conversion - allows me to get a negative offset
    // then implicit conversion to int64_t
    int64_t l_timing_val = int8_t(iv_spd_data[BYTE_INDEX]);

    // Check for vali value
    constexpr int64_t TIMING_LOWER_BOUND = -128; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 127; // from JEDEC

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             BYTE_INDEX,
             l_timing_val,
             "Failed check on the fine offset for Minimum Active to Active/Refresh Delay Time (tRCmin)") );

    // Update output value only if range check passes
    o_value = l_timing_val;

    FAPI_INF("%s. Fine offset for Minimum Active to Active/Refresh Delay Time (tRCmin) in FTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes Fine Offset for Minimum Row Precharge Delay Time
/// @param[in] i_target dimm target
/// @param[out] o_value tRPmin offset in FTB units
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 121
/// @note Item JC-45-2220.01x
/// @note Page 52
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::fine_offset_min_trp(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 121;

    FAPI_INF("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             iv_spd_data[BYTE_INDEX]);

    // Retrieve Fine Offset for Minimum Row Precharge Delay Time
    // int8_t conversion - allows me to get a negative offset
    // then implicit conversion to int64_t
    int64_t l_timing_val = int8_t(iv_spd_data[BYTE_INDEX]);

    // Check for valid value
    constexpr int64_t TIMING_LOWER_BOUND = -128; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 127; // from JEDEC

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             BYTE_INDEX,
             l_timing_val,
             "Failed check on the fine offset for Minimum Row Precharge Delay Time (tRPmin)") );

    // Update output value only if range check passes
    o_value = l_timing_val;

    FAPI_INF("%s. Fine offset for Minimum Row Precharge Delay Time (tRPmin) in FTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}
///
/// @brief Decodes Fine Offset for SDRAM Minimum RAS to CAS Delay Time
/// @param[in] i_target dimm target
/// @param[out] o_value tRCDmin offset in FTB units
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 122
/// @note Item JC-45-2220.01x
/// @note Page 52
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::fine_offset_min_trcd(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 122;

    FAPI_INF("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             iv_spd_data[BYTE_INDEX]);

    // Retrieve Fine Offset for SDRAM Minimum RAS to CAS Delay Time
    // int8_t conversion - allows me to get a negative offset
    // then implicit conversion to int64_t
    int64_t l_timing_val = int8_t(iv_spd_data[BYTE_INDEX]);

    // Check for valid value
    constexpr int64_t TIMING_LOWER_BOUND = -128; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 127; // from JEDEC

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             BYTE_INDEX,
             l_timing_val,
             "Failed check on the fine offset for min RAS to CAS Delay Time (tRCDmin)") );

    // Update output value only if range check passes
    o_value = l_timing_val;

    FAPI_INF("%s. Fine offset for Minimum RAS to CAS Delay Time (tRCDmin) in FTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes Fine Offset for SDRAM Minimum CAS Latency Time
/// @param[in] i_target dimm target
/// @param[out] o_value tAAmin offset in FTB units
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 123
/// @note Item JC-45-2220.01x
/// @note Page 52
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::fine_offset_min_taa(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 123;

    FAPI_INF("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             iv_spd_data[BYTE_INDEX]);

    // Retrieve Fine Offset for SDRAM Minimum CAS Latency Time
    // int8_t conversion - allows me to get a negative offset
    // then implicit conversion to int64_t
    int64_t l_timing_val = int8_t(iv_spd_data[BYTE_INDEX]);

    // Check for valid value
    constexpr int64_t TIMING_LOWER_BOUND = -128; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 127; // from JEDEC

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             BYTE_INDEX,
             l_timing_val,
             "Failed check on the Fine offset for Minimum CAS Latency Time (tAAmin)") );

    // Update output value only if range check passes
    o_value = l_timing_val;

    FAPI_INF("%s. Fine offset for Minimum CAS Latency Time (tAAmin) in FTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes Fine Offset for SDRAM Maximum Cycle Time
/// @param[in] i_target dimm target
/// @param[out] o_value tCKmax offset in FTB units
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 124
/// @note Item JC-45-2220.01x
/// @note Page 52
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::fine_offset_max_tck(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 124;

    FAPI_INF("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             iv_spd_data[BYTE_INDEX]);

    // Retrieve Fine Offset for SDRAM Maximum Cycle Time
    // int8_t conversion - allows me to get a negative offset
    // then implicit conversion to int64_t
    int64_t l_timing_val = int8_t(iv_spd_data[BYTE_INDEX]);

    // Check for valid value
    constexpr int64_t TIMING_LOWER_BOUND = -128; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 127; // from JEDEC

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             BYTE_INDEX,
             l_timing_val,
             "Failed check on the fine offset for max cycle time (tckmax)") );

    // Update output value only if range check passes
    o_value = l_timing_val;

    FAPI_INF("%s. Fine offset for Maximum Cycle Time (tCKmax) in FTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Decodes Fine Offset for SDRAM Minimum Cycle Time
/// @param[in] i_target dimm target
/// @param[out] o_value tCKmin offset in FTB units
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 125
/// @note Item JC-45-2220.01x
/// @note Page 52
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::fine_offset_min_tck(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        int64_t& o_value)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 125;

    FAPI_INF("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             BYTE_INDEX,
             iv_spd_data[BYTE_INDEX]);

    // Retrieve Fine Offset for SDRAM Minimum Cycle Time
    // int8_t conversion - allows me to get a negative offset
    // then implicit conversion to int64_t
    int64_t l_timing_val = int8_t(iv_spd_data[BYTE_INDEX]);

    // Check for valid value
    constexpr int64_t TIMING_LOWER_BOUND = -128; // from JEDEC
    constexpr int64_t TIMING_UPPER_BOUND = 127; // from JEDEC

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(i_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             BYTE_INDEX,
             l_timing_val,
             "Failed check on the Fine offset for Minimum Cycle Time (tCKmin)") );

    // Update output value only if range check passes
    o_value = l_timing_val;

    FAPI_INF("%s. Fine offset for Minimum Cycle Time (tCKmin) in FTB units: %d",
             mss::c_str(i_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Decodes Cyclical Redundancy Code (CRC) for Base Configuration Section
/// @param[in] i_target dimm target
/// @param[out] o_value crc value from SPD
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 127 & Byte 126
/// @note Item JC-45-2220.01x
/// @note Page 53
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder::cyclical_redundancy_code(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        uint16_t& o_value)
{
    constexpr size_t BYTE_INDEX_MSB = 127;
    uint8_t crc_MSB = extract_spd_field< BYTE_INDEX_MSB, CRC_MSB_START, CRC_MSB_LEN >(i_target, iv_spd_data);

    constexpr size_t BYTE_INDEX_LSB = 126;
    uint8_t crc_LSB = extract_spd_field< BYTE_INDEX_LSB, CRC_LSB_START, CRC_LSB_LEN >(i_target, iv_spd_data);

    // Combining bits to create timing value (in a buffer)
    constexpr size_t MSN_START = 0;
    constexpr size_t MSN_LEN = 8;
    constexpr size_t LSB_START = 8;
    constexpr size_t LSB_LEN = 8;

    fapi2::buffer<uint16_t> l_buffer;
    l_buffer.insertFromRight<MSN_START, MSN_LEN>( crc_MSB )
    .insertFromRight<LSB_START, LSB_LEN>( crc_LSB );

    // This value isn't bounded in the SPD document
    o_value = l_buffer;

    FAPI_INF("%s. Cyclical Redundancy Code (CRC): %d",
             mss::c_str(i_target),
             o_value);

    // Returns "happy" until we can figure out a way to test this - AAM
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Returns Logical ranks in Primary SDRAM type
/// @param[in] i_target dimm target
/// @param[out] o_logical_ranks number of logical ranks
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode decoder::prim_sdram_logical_ranks(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_logical_ranks)
{
    uint8_t l_signal_loading = 0;
    uint8_t l_ranks_per_dimm = 0;

    FAPI_TRY( prim_sdram_signal_loading(i_target, l_signal_loading) );
    FAPI_TRY( num_package_ranks_per_dimm(i_target, l_ranks_per_dimm) );

    if(l_signal_loading == spd::SINGLE_LOAD_STACK)
    {
        //  For single-load-stack(3DS) the logical ranks per package ends up being the same as the die count.
        uint8_t l_die_count = 0;
        FAPI_TRY( prim_sdram_die_count(i_target, l_die_count) );

        o_logical_ranks = l_ranks_per_dimm * l_die_count;
    }
    else
    {
        // Covers case for MONOLITHIC & MULTI_LOAD_STACK
        // The die count isn't guaranteed to be 1 (e.g. SDP - 1 die package, DDP - 2 die package).
        // Value of 1 is used for calculation purposes as defined by the SPD spec.
        o_logical_ranks = l_ranks_per_dimm;
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Returns Logical ranks per DIMM
/// @param[in] i_target dimm target
/// @param[in] i_pDecoder shared pointer to the SPD decoder
/// @param[out] o_logical_ranks number of logical ranks
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode decoder::logical_ranks_per_dimm(const fapi2::Target<TARGET_TYPE_DIMM>& i_target,
        uint8_t& o_logical_rank_per_dimm)
{
    FAPI_TRY( prim_sdram_logical_ranks(i_target, o_logical_rank_per_dimm) );

fapi_try_exit:
    return fapi2::current_err;
}

}//spd
}// mss
