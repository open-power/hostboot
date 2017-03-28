/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/common/ddr4/spd_decoder_ddr4_v1_1.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file spd_decoder_v1_1.C
/// @brief SPD decoder definitions
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

// fapi2
#include <fapi2.H>

// mss lib
#include <generic/memory/lib/spd/common/ddr4/spd_decoder_ddr4.H>
#include <generic/memory/lib/spd/spd_checker.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/find.H>

using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_DIMM;

namespace mss
{
namespace spd
{
namespace ddr4
{

/////////////////////////
// Member method definitions
/////////////////////////

///
/// @brief ctor
/// @param[in] i_target dimm target
/// @param[in] i_spd_data SPD data vector
/// @param[in] i_module_decoder shared_ptr to dimm module decoder
/// @param[in] i_raw_card raw card data structure
///
decoder_v1_1::decoder_v1_1(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                           const std::vector<uint8_t>& i_spd_data,
                           const std::shared_ptr<dimm_module_decoder>& i_module_decoder,
                           const rcw_settings& i_raw_card)
    : decoder_v1_0(i_target, i_spd_data, i_module_decoder, i_raw_card)
{}

///
/// @brief Decodes SDRAM density from SPD
/// @param[out] o_value SDRAM density in GBs
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 4 (bits 0~3)
/// @note Item JC-45-2220.01x
/// @note Page 18
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder_v1_1::sdram_density( uint8_t& o_value )
{
    // =========================================================
    // Byte 4 maps
    // Item JC-45-2220.01x
    // Page 18
    // DDR4 SPD Document Release 3
    // Byte 4 (0x004): SDRAM Density and Banks
    // =========================================================
    static const std::vector<std::pair<uint8_t, uint8_t> > SDRAM_DENSITY_MAP =
    {
        // {key byte, capacity in GBs}
        {2, 1},
        {3, 2},
        {4, 4},
        {5, 8},
        {6, 16},
        {7, 32},
        {8, 12},
        {12, 24}
    };

    // Extracting desired biits
    const uint8_t l_field_bits = extract_spd_field< SDRAM_CAPACITY >(iv_target, iv_spd_data);
    FAPI_DBG("Field Bits value: %d", l_field_bits);

    // Check to assure SPD DRAM capacity (map) wont be at invalid values
    bool l_is_val_found = mss::find_value_from_key(SDRAM_DENSITY_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_is_val_found,
              SDRAM_CAPACITY.iv_byte,
              l_field_bits,
              "Failed check for SPD DRAM capacity") );

    FAPI_INF("%s. SDRAM density: %d Gb",
             mss::c_str(iv_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes hybrid media field from SPD
/// @param[in] iv_target
/// @param[out] o_value enum representing hybrid memory type
/// @return FAPI2_RC_SUCCESS if okay
/// @note Decodes SPD Byte 3 (bits 4~6)
/// @note Item JC-45-2220.01x
/// @note Page 17
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder_v1_1::hybrid_media( uint8_t& o_value )
{
    // =========================================================
    // Byte 3 maps
    // Item JC-45-2220.01x
    // Page 17
    // DDR4 SPD Document Release 3
    // Byte 3 (0x003): Key Byte / Module Type
    // =========================================================
    static const std::vector<std::pair<uint8_t, uint8_t> > HYBRID_MEDIA_MAP =
    {
        //{key, value}
        {0, fapi2::ENUM_ATTR_EFF_HYBRID_MEMORY_TYPE_NONE},
        {1, fapi2::ENUM_ATTR_EFF_HYBRID_MEMORY_TYPE_NVDIMM}
    };

    // Extracting desired bits
    const uint8_t l_field_bits = extract_spd_field< HYBRID_MEDIA >(iv_target, iv_spd_data);
    FAPI_DBG("Field Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(HYBRID_MEDIA_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_is_val_found,
              HYBRID_MEDIA.iv_byte,
              l_field_bits,
              "Failed check on Hybrid Media type") );

    FAPI_INF("%s. Hybrid Media: %d",
             mss::c_str(iv_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes hybrid field from SPD
/// @param[out] o_value enum representing if module is hybrid
/// @return fapi2::FAPI2_RC_SUCCESS if okay
/// @note Decodes SPD Byte 3 (bit 7)
/// @note Item JC-45-2220.01x
/// @note Page 17
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder_v1_1::hybrid( uint8_t& o_value )
{
    // =========================================================
    // Byte 3 maps
    // Item JC-45-2220.01x
    // Page 17
    // DDR4 SPD Document Release 3
    // Byte 3 (0x003): Key Byte / Module Type
    // =========================================================
    static const std::vector<std::pair<uint8_t, uint8_t> > HYBRID_MAP =
    {
        //{key byte, value}
        {0, fapi2::ENUM_ATTR_EFF_HYBRID_NOT_HYBRID},
        {1, fapi2::ENUM_ATTR_EFF_HYBRID_IS_HYBRID}
    };

    // Extracting desired bits
    const uint8_t l_field_bits = extract_spd_field< HYBRID >(iv_target, iv_spd_data);
    FAPI_INF("Field_Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(HYBRID_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_is_val_found,
              HYBRID.iv_byte,
              l_field_bits,
              "Failed check on hybrid field") );

    FAPI_INF("%s. Hybrid: %d",
             mss::c_str(iv_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes Secondary SDRAM signal loading
/// @param[out] o_value enum representing signal loading type
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 10 (bits 1~0)
/// @note Item JC-45-2220.01x
/// @note Page 22
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder_v1_1::sec_sdram_signal_loading( uint8_t& o_value )
{
    // =========================================================
    // Byte 10 maps
    // Item JC-45-2220.01x
    // Page 21-22
    // DDR4 SPD Document Release 3
    // Byte 10 (0x00A): Secondary SDRAM Package Type
    // =========================================================
    static const std::vector<std::pair<uint8_t, uint8_t> > SEC_SIGNAL_LOADING_MAP =
    {
        // {key byte, signal loading}
        {0, UNSPECIFIED},
        {1, MULTI_LOAD_STACK},
        {2, SINGLE_LOAD_STACK}
    };

    // Extracting desired bits
    const uint8_t l_field_bits = extract_spd_field< SEC_SIGNAL_LOADING >(iv_target, iv_spd_data);
    FAPI_DBG("Field Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(SEC_SIGNAL_LOADING_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_is_val_found,
              SEC_SIGNAL_LOADING.iv_byte,
              l_field_bits,
              "Failed check for Secondary SDRAM Signal Loading") );

    FAPI_INF("%s. Secondary SDRAM Signal Loading: %d",
             mss::c_str(iv_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decode Soft post package repair (soft PPR)
/// @param[out] o_value enum representing if soft PPR is supported
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 9 (bit 5)
/// @note Item JC-45-2220.01x
/// @note Page 21
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder_v1_1::soft_post_package_repair( uint8_t& o_value )
{
    // =========================================================
    // Byte 9 maps
    // Item JC-45-2220.01x
    // Page 21
    // DDR4 SPD Document Release 3
    // Byte 9 (0x009): Other SDRAM Optional Features
    // =========================================================
    static const std::vector<std::pair<uint8_t, uint8_t> > SOFT_PPR_MAP =
    {
        // {key byte, value }
        {0, fapi2::ENUM_ATTR_EFF_DRAM_SOFT_PPR_NOT_SUPPORTED},
        {1, fapi2::ENUM_ATTR_EFF_DRAM_SOFT_PPR_SUPPORTED}
    };

    // Extracting desired bits
    const uint8_t l_field_bits = extract_spd_field< SOFT_PPR >(iv_target, iv_spd_data);
    FAPI_DBG("Field Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(SOFT_PPR_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd:: fail_for_invalid_value(iv_target,
              l_is_val_found,
              SOFT_PPR.iv_byte,
              l_field_bits,
              "Failed check for Soft PPR") );

    FAPI_INF("%s. Soft Post Package Repair (Soft PPR): %d",
             mss::c_str(iv_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes Secondary DRAM Density Ratio
/// @param[out] o_value raw bits from SPD
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 10 (bits 3~2)
/// @note Item JC-45-2220.01x
/// @note Page 22
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder_v1_1::sec_dram_density_ratio( uint8_t& o_value )
{
    // Extracting desired bits
    const uint8_t l_field_bits = extract_spd_field< SEC_DENSITY_RATIO >(iv_target, iv_spd_data);
    FAPI_DBG("Field Bits value: %d", l_field_bits);

    // Find map value
    constexpr size_t UNDEFINED = 3; // JEDEC map doesn't go beyond 3

    FAPI_TRY( mss::check::spd:: fail_for_invalid_value(iv_target,
              l_field_bits < UNDEFINED,
              SEC_DENSITY_RATIO.iv_byte,
              l_field_bits,
              "Failed check for DRAM Density Ratio") );

    FAPI_INF("%s. DRAM Density Ratio: %d",
             mss::c_str(iv_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Decodes Secondary SDRAM die count
/// @param[out] o_value die count
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 10 (bits 6~4)
/// @note Item JC-45-2220.01x
/// @note Page 22
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder_v1_1::sec_sdram_die_count( uint8_t& o_value )
{
    // =========================================================
    // Byte 10 maps
    // Item JC-45-2220.01x
    // Page 21-22
    // DDR4 SPD Document Release 3
    // Byte 10 (0x00A): Secondary SDRAM Package Type
    // =========================================================
    static const std::vector<std::pair<uint8_t, uint8_t> > SEC_DIE_COUNT_MAP =
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
    const uint8_t l_field_bits = extract_spd_field< SEC_DIE_COUNT >(iv_target, iv_spd_data);
    FAPI_DBG("Field Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(SEC_DIE_COUNT_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_is_val_found,
              SEC_DIE_COUNT.iv_byte,
              l_field_bits,
              "Failed check for Secondary Die Count") );

    FAPI_INF("%s. Secondary Die Count: %d",
             mss::c_str(iv_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes Secondary SDRAM package type
/// @param[out] o_value  enum representing package type
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 10 (bit 7)
/// @note Item JC-45-2220.01x
/// @note Page 22
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder_v1_1::sec_sdram_package_type( uint8_t& o_value )
{
    // =========================================================
    // Byte 10 maps
    // Item JC-45-2220.01x
    // Page 21-22
    // DDR4 SPD Document Release 3
    // Byte 10 (0x00A): Secondary SDRAM Package Type
    // =========================================================

    static const std::vector<std::pair<uint8_t, uint8_t> > SEC_PACKAGE_TYPE_MAP =
    {
        // {key byte, value }
        {0, MONOLITHIC},
        {1, NON_MONOLITHIC}
    };

    // Extracting desired bits
    const uint8_t l_field_bits = extract_spd_field< SEC_PACKAGE_TYPE >(iv_target, iv_spd_data);
    FAPI_DBG("Field Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(SEC_PACKAGE_TYPE_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_is_val_found,
              SEC_PACKAGE_TYPE.iv_byte,
              l_field_bits,
              "Failed check for Secondary Package Type") );

    FAPI_INF("%s. Secondary Package Type: %d",
             mss::c_str(iv_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes number of package ranks per DIMM
/// @param[out] o_value number of package ranks per DIMM
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 12 (bits 5~3)
/// @note Item JC-45-2220.01x
/// @note Page 23
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder_v1_1::num_package_ranks_per_dimm( uint8_t& o_value )
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
        {5, 6},
        {6, 7},
        {7, 8},
    };

    // Extracting desired bits
    const uint8_t l_field_bits = extract_spd_field< PACKAGE_RANKS >(iv_target, iv_spd_data);
    FAPI_DBG("Field Bits value: %d", l_field_bits);

    // Find map value
    bool l_is_val_found = mss::find_value_from_key(NUM_PACKAGE_RANKS_MAP, l_field_bits, o_value);

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_is_val_found,
              PACKAGE_RANKS.iv_byte,
              l_field_bits,
              "Failed check for Num Package Ranks Per DIMM") );

    FAPI_INF("%s. Num Package Ranks per DIMM: %d",
             mss::c_str(iv_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes Rank Mix
/// @param[out] o_value rank mix value from SPD
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 12 (bit 6)
/// @note Item JC-45-2220.01x
/// @note Page 23
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder_v1_1::rank_mix( uint8_t& o_value )
{
    // Extracting desired bits
    const uint8_t l_field_bits = extract_spd_field< RANK_MIX >(iv_target, iv_spd_data);
    FAPI_DBG("Field Bits value: %d", l_field_bits);

    // Find map value
    constexpr size_t INVALID_VALUE = 2;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              (l_field_bits < INVALID_VALUE),
              RANK_MIX.iv_byte,
              l_field_bits,
              "Failed check for Rank Mix") );

    // Update output after check passes
    o_value = l_field_bits;

    FAPI_INF("%s. Rank Mix: %d",
             mss::c_str(iv_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decode CAS Latencies Supported
/// @param[out] o_value bitmap of supported CAS latencies
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Bytes 20-23
/// @note Item JC-45-2220.01x
/// @note Page 33-34
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder_v1_1::supported_cas_latencies( uint64_t& o_value )
{
    // Trace print in the front assists w/ debug
    constexpr size_t FIRST_BYTE = 20;
    uint8_t first_raw_byte = iv_spd_data[FIRST_BYTE];
    FAPI_INF("%s SPD data at Byte %d: 0x%llX.",
             c_str(iv_target),
             FIRST_BYTE,
             first_raw_byte);

    constexpr size_t SEC_BYTE = 21;
    uint8_t sec_raw_byte = iv_spd_data[SEC_BYTE];
    FAPI_INF("%s SPD data at Byte %d: 0x%llX.",
             c_str(iv_target),
             SEC_BYTE,
             sec_raw_byte);

    constexpr size_t THIRD_BYTE = 22;
    uint8_t third_raw_byte = iv_spd_data[THIRD_BYTE];
    FAPI_INF("%s SPD data at Byte %d: 0x%llX.",
             c_str(iv_target),
             THIRD_BYTE,
             third_raw_byte);

    constexpr size_t FOURTH_BYTE = 23;
    uint8_t fourth_raw_byte = iv_spd_data[FOURTH_BYTE];
    FAPI_INF("%s SPD data at Byte %d: 0x%llX.",
             c_str(iv_target),
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
    // Byte 23 bit 6 is reserved and must be coded as 0.
    // Should we warn instead of fail because in last revision this was a reserved byte coded as 0x00
    constexpr size_t BIT_START = 33; // relative position of bit 6 in byte 23 relative to uint64_t
    constexpr size_t BIT_LEN = 1;

    // Check for a valid value
    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              !(l_buffer.getBit<BIT_START, BIT_LEN>()),
              FOURTH_BYTE,
              fourth_raw_byte,
              "Failed check on CAS latencies supported") );

    // Update output value only if range check passes
    o_value = l_buffer;

    FAPI_INF("%s. CAS latencies supported (bitmap): 0x%llX",
             mss::c_str(iv_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes Minimum Write Recovery Time
/// @param[out] o_value tWRmin in MTB units
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 41 (bits 3~0) & Byte 42 (bits 7~0)
/// @note Item JC-45-2220.01x
/// @note Page 40
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder_v1_1::min_twr( int64_t& o_value )
{
    uint8_t tWRmin_MSN = extract_spd_field< TWRMIN_MSN >(iv_target, iv_spd_data);
    FAPI_INF("MSN Field Bits value: %lu", tWRmin_MSN);

    uint8_t tWRmin_LSB = extract_spd_field< TWRMIN_LSB >(iv_target, iv_spd_data);
    FAPI_INF("LSB Field Bits value: %lu", tWRmin_LSB);

    // Combining bits to create timing value (in a buffer)
    constexpr size_t MSN_START = 52;
    constexpr size_t MSN_LEN = 4;
    constexpr size_t LSB_START = 56;
    constexpr size_t LSB_LEN = 8;

    fapi2::buffer<int64_t> l_buffer;
    l_buffer.insertFromRight<MSN_START, MSN_LEN>( tWRmin_MSN ).
    insertFromRight<LSB_START, LSB_LEN>( tWRmin_LSB );

    // Extract timing value from the buffer into an integral type
    int64_t l_timing_val = l_buffer;

    // JEDEC spec limits for this timing value
    // This value used to be reserved to 0 - before spec update
    // constexpr int64_t TIMING_LOWER_BOUND = 1; // from JEDEC

    constexpr int64_t TIMING_LOWER_BOUND = 0;
    constexpr int64_t TIMING_UPPER_BOUND = 4095; // from JEDEC

    // best we can do?
    // I had to combine parts from two different bytes.
    // Chose one of them (byte 42) to for error printout of this decode
    constexpr size_t ERROR_BYTE_INDEX = 42;

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(iv_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             ERROR_BYTE_INDEX,
             l_timing_val,
             "Failed check on the Minimum Write Recovery Time (tWRmin) in MTB") );

    // Update output only after check passes
    o_value = l_timing_val;

    FAPI_INF("%s. Minimum Write Recovery Time (tWRmin) in MTB units: %d",
             mss::c_str(iv_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Decodes Minimum Write to Read Time - Different Bank Group
/// @param[out] o_value tWTR_Smin in MTB units
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 43 (bits 3~0) & Byte 44 (bits 7~0)
/// @note Item JC-45-2220.01x
/// @note Page 40
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder_v1_1::min_twtr_s( int64_t& o_value )
{
    uint8_t tWTR_Smin_MSN = extract_spd_field< TWTRMIN_S_MSN >(iv_target, iv_spd_data);
    FAPI_INF("MSN Field Bits value: %lu", tWTR_Smin_MSN);

    uint8_t tWTR_Smin_LSB = extract_spd_field< TWTRMIN_S_LSB >(iv_target, iv_spd_data);
    FAPI_INF("LSB Field Bits value: %lu", tWTR_Smin_LSB);

    // Combining bits to create timing value (in a buffer)
    constexpr size_t MSN_START = 52;
    constexpr size_t MSN_LEN = 4;
    constexpr size_t LSB_START = 56;
    constexpr size_t LSB_LEN = 8;

    fapi2::buffer<int64_t> l_buffer;

    l_buffer.insertFromRight<MSN_START, MSN_LEN>( tWTR_Smin_MSN )
    .insertFromRight<LSB_START, LSB_LEN>( tWTR_Smin_LSB );

    // Extract timing value from the buffer into an integral type
    int64_t l_timing_val = l_buffer;

    // JEDEC spec limits for this timing value

    // This value used to be reserved to 0 - before spec update - AAM
    // constexpr int64_t TIMING_LOWER_BOUND = 1; // from JEDEC
    constexpr int64_t TIMING_LOWER_BOUND = 0;
    constexpr int64_t TIMING_UPPER_BOUND = 4095; // from JEDEC

    // best we can do?
    // I had to combine parts from two different bytes.
    // Chose one of them (byte 44) to for error printout of this decode
    constexpr size_t ERROR_BYTE_INDEX = 44;

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(iv_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             ERROR_BYTE_INDEX,
             l_timing_val,
             "Failed check on the Minimum Write to Read Time - Different Bank Group (tWTR_Smin) in MTB") );

    // Update output only after check passes
    o_value = l_timing_val;

    FAPI_INF("%s. Minimum Write to Read Time - Different Bank Group (tWTR_Smin) in MTB units: %d",
             mss::c_str(iv_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes Minimum Write to Read Time - Same Bank Group
/// @param[out] o_value tWTR_Lmin in MTB units
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 43 (bits 7~4) & Byte 45 (bits 7~0)
/// @note Item JC-45-2220.01x
/// @note Page 46
/// @note DDR4 SPD Document Release 3
///
fapi2::ReturnCode decoder_v1_1::min_twtr_l( int64_t& o_value )
{
    // Extracting desired bits
    uint8_t tWTR_Lmin_MSN = extract_spd_field< TWTRMIN_L_MSN >(iv_target, iv_spd_data);
    FAPI_INF("MSN Field Bits value: %lu", tWTR_Lmin_MSN);

    uint8_t tWTR_Lmin_LSB = extract_spd_field< TWTRMIN_L_LSB >(iv_target, iv_spd_data);
    FAPI_INF("LSB Field Bits value: %lu", tWTR_Lmin_LSB);

    // Combining bits to create timing value (in a buffer)
    constexpr size_t MSN_START = 52;
    constexpr size_t MSN_LEN = 4;
    constexpr size_t LSB_START = 56;
    constexpr size_t LSB_LEN = 8;

    fapi2::buffer<int64_t> l_buffer;

    l_buffer.insertFromRight<MSN_START, MSN_LEN>( tWTR_Lmin_MSN )
    .insertFromRight<LSB_START, LSB_LEN>( tWTR_Lmin_LSB );

    // Extract timing value from the buffer into an integral type
    int64_t l_timing_val = l_buffer;

    // JEDEC spec limits for this timing value
    // This value used to be reserved to 0 - before spec update
    //constexpr int64_t TIMING_LOWER_BOUND = 1  // from JEDEC
    constexpr int64_t TIMING_LOWER_BOUND = 0;
    constexpr int64_t TIMING_UPPER_BOUND = 4095; // from JEDEC

    // best we can do?
    // I had to combine parts from two different bytes.
    // Chose one of them (byte 45) to for error printout of this decode
    constexpr size_t ERROR_BYTE_INDEX = 45;

    FAPI_TRY(mss::check::spd::fail_for_invalid_value(iv_target,
             (l_timing_val <= TIMING_UPPER_BOUND) &&
             (l_timing_val >= TIMING_LOWER_BOUND),
             ERROR_BYTE_INDEX,
             l_timing_val,
             "Failed check on the Minimum Write to Read Time - Same Bank Group (tWTR_Lmin) in MTB") );

    // Update output only after check passes
    o_value = l_timing_val;

    FAPI_INF("%s. Minimum Write to Read Time - Same Bank Group (tWTR_Lmin) in MTB units: %d",
             mss::c_str(iv_target),
             o_value);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function that returns Logical ranks in SDRAM type
/// @param[out] o_logical_ranks number of logical ranks
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode decoder_v1_1::sec_sdram_logical_ranks( uint8_t& o_logical_ranks )
{
    uint8_t l_signal_loading = 0;
    uint8_t l_ranks_per_dimm = 0;

    FAPI_TRY( sec_sdram_signal_loading(l_signal_loading) );
    FAPI_TRY( num_package_ranks_per_dimm(l_ranks_per_dimm) );

    if(l_signal_loading == spd::SINGLE_LOAD_STACK)
    {
        //  For single-load-stack(3DS) the logical ranks per package ends up being the same as the die count.
        uint8_t l_die_count = 0;
        FAPI_TRY( sec_sdram_die_count(l_die_count) );

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
/// @param[out] o_logical_ranks number of logical ranks
/// @return fapi2::FAPI2_RC_SUCCESS if okay
///
fapi2::ReturnCode decoder_v1_1::logical_ranks_per_dimm( uint8_t& o_logical_rank_per_dimm )
{
    uint8_t l_rank_mix = 0;

    FAPI_TRY( rank_mix(l_rank_mix) );

    if(l_rank_mix == fapi2::ENUM_ATTR_EFF_DRAM_RANK_MIX_SYMMETRICAL)
    {
        FAPI_TRY( prim_sdram_logical_ranks(o_logical_rank_per_dimm) );
    }
    else
    {
        // Rank mix is ASYMMETRICAL
        uint8_t l_prim_logical_rank_per_dimm = 0;
        uint8_t l_sec_logical_rank_per_dimm = 0;

        FAPI_TRY( prim_sdram_logical_ranks(l_prim_logical_rank_per_dimm) );
        FAPI_TRY( sec_sdram_logical_ranks(l_sec_logical_rank_per_dimm) );

        o_logical_rank_per_dimm = l_prim_logical_rank_per_dimm + l_sec_logical_rank_per_dimm;
    }

fapi_try_exit:
    return fapi2::current_err;
}

}// ddr4
}// spd
}// mss
