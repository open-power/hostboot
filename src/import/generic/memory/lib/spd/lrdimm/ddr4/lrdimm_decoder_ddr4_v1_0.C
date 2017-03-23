/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/lrdimm/ddr4/lrdimm_decoder_ddr4_v1_0.C $ */
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
/// @file lrdimm_decoder_v1_0.C
/// @brief LRDIMM module SPD decoder definitions for revision 1.0
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

// std lib
#include <vector>

// fapi2
#include <fapi2.H>

// mss lib
#include <generic/memory/lib/spd/lrdimm/ddr4/lrdimm_decoder_ddr4.H>
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
namespace lrdimm
{

/////////////////////////
// Non-member helper functions
// For LRDIMM module rev 1.0
/////////////////////////

/// @brief Helper function to find SPD byte based on freq
/// @param[in] i_dimm_speed DIMM speed in MT/s
/// @param[out] o_byte byte to extract spd from
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD spec sets encoding based on freq ranges such as, 1866 < data rate <= 2400,
/// But for Nimbus we can only be 1866, 2133, 2400, and 2666.  No intermediate values
/// so we use a simple case statement to get our results.
static fapi2::ReturnCode mdq_helper(const uint64_t i_dimm_speed, uint8_t& o_byte)
{
    switch(i_dimm_speed)
    {
        case fapi2::ENUM_ATTR_MSS_FREQ_MT1866:
            o_byte = 145;
            break;

        case fapi2::ENUM_ATTR_MSS_FREQ_MT2133:
        case fapi2::ENUM_ATTR_MSS_FREQ_MT2400:
            o_byte = 146;
            break;

        case fapi2::ENUM_ATTR_MSS_FREQ_MT2666:
            o_byte = 147;
            break;

        default:
            FAPI_ERR("Invalid dimm speed received: %d", i_dimm_speed);
            return fapi2::FAPI2_RC_INVALID_PARAMETER;
            break;
    }

    return fapi2::FAPI2_RC_SUCCESS;
};

/// @brief Helper function to find start bit based on freq
/// @param[in] i_dimm_speed DIMM speed in MT/s
/// @param[out] o_start_bit start bit to extract SPD from
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD spec sets encoding based on freq ranges such as, 1866 < data rate <= 2400,
/// But for Nimbus we can only be 1866, 2133, 2400, and 2666.  No intermediate values
/// so we use a simple case statement to get our results.
static fapi2::ReturnCode drive_strength_start_bit_finder(const uint64_t i_dimm_speed, size_t& o_start_bit)
{
    switch(i_dimm_speed)
    {
        case fapi2::ENUM_ATTR_MSS_FREQ_MT1866:
            o_start_bit = 6;
            break;

        case fapi2::ENUM_ATTR_MSS_FREQ_MT2133:
        case fapi2::ENUM_ATTR_MSS_FREQ_MT2400:
            o_start_bit = 4;
            break;

        case fapi2::ENUM_ATTR_MSS_FREQ_MT2666:
            o_start_bit = 2;
            break;

        default:
            FAPI_ERR("Invalid dimm speed received: %d", i_dimm_speed);
            return fapi2::FAPI2_RC_INVALID_PARAMETER;
            break;
    }

    return fapi2::FAPI2_RC_SUCCESS;
}

/// @brief Helper function to find SPD byte based on freq
/// @param[in] i_dimm_speed DIMM speed in MT/s
/// @param[out] o_byte byte to extract spd from
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD spec sets encoding based on freq ranges such as, 1866 < data rate <= 2400,
/// But for Nimbus we can only be 1866, 2133, 2400, and 2666.  No intermediate values
/// so we use a simple case statement to get our results.
static fapi2::ReturnCode rtt_wr_and_nom_byte_finder(const uint64_t i_dimm_speed, size_t& o_byte)
{
    switch(i_dimm_speed)
    {
        case fapi2::ENUM_ATTR_MSS_FREQ_MT1866:
            o_byte =  149;
            break;

        case fapi2::ENUM_ATTR_MSS_FREQ_MT2133:
        case fapi2::ENUM_ATTR_MSS_FREQ_MT2400:
            o_byte = 150;
            break;

        case fapi2::ENUM_ATTR_MSS_FREQ_MT2666:
            o_byte = 151;
            break;

        default:
            FAPI_ERR("Invalid dimm speed received: %d", i_dimm_speed);
            return fapi2::FAPI2_RC_INVALID_PARAMETER;
            break;
    }

    return fapi2::FAPI2_RC_SUCCESS;
}

/// @brief Helper function to find SPD byte based on freq
/// @param[in] i_dimm_speed DIMM speed in MT/s
/// @param[out] o_byte byte to extract spd from
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD spec sets encoding based on freq ranges such as, 1866 < data rate <= 2400,
/// But for Nimbus we can only be 1866, 2133, 2400, and 2666.  No intermediate values
/// so we use a simple case statement to get our results.
static fapi2::ReturnCode rtt_park_byte_finder(const uint64_t i_dimm_speed, size_t& o_byte)
{
    switch(i_dimm_speed)
    {
        case fapi2::ENUM_ATTR_MSS_FREQ_MT1866:
            o_byte = 152;
            break;

        case fapi2::ENUM_ATTR_MSS_FREQ_MT2133:
        case fapi2::ENUM_ATTR_MSS_FREQ_MT2400:
            o_byte = 153;
            break;

        case fapi2::ENUM_ATTR_MSS_FREQ_MT2666:
            o_byte = 154;
            break;

        default:
            FAPI_ERR("Invalid dimm speed received: %d", i_dimm_speed);
            return fapi2::FAPI2_RC_INVALID_PARAMETER;
            break;
    }

    return fapi2::FAPI2_RC_SUCCESS;
}

/////////////////////////
// Member Method implementation
// For LRDIMM module rev 1.0
/////////////////////////

///
/// @brief Decodes module nominal height max
/// @param[out] o_output height range encoding from SPD
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 128 (Bits 4~0)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 2
/// @note Page 4.1.2.12.2 - 55
///
fapi2::ReturnCode decoder_v1_0::max_module_nominal_height(uint8_t& o_output)
{
    uint8_t l_field_bits = extract_spd_field< MODULE_NOMINAL_HEIGHT >(iv_target, iv_spd_data);
    FAPI_INF("Field Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t MAX_VALID_VALUE = 0b11111;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits <= MAX_VALID_VALUE,
              MODULE_NOMINAL_HEIGHT.iv_byte,
              l_field_bits,
              "Failed bound check for module nominal height max") );

    // Update output only if check passes
    o_output = l_field_bits;

    FAPI_INF("%s. Max module nominal height: %d",
             mss::c_str(iv_target),
             o_output);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes raw card extension
/// @param[out] o_output raw card rev. encoding from SPD
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 128 (Bits 7~5)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 2
/// @note Page 4.1.2.12.2 - 55
///
fapi2::ReturnCode decoder_v1_0::raw_card_extension(uint8_t& o_output)
{
    uint8_t l_field_bits = extract_spd_field< RAW_CARD_EXTENSION >(iv_target, iv_spd_data);
    FAPI_INF("Field Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t MAX_VALID_VALUE = 0b111;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits <= MAX_VALID_VALUE,
              RAW_CARD_EXTENSION.iv_byte,
              l_field_bits,
              "Failed bound check for raw card extension") );

    // Update output only if check passes
    o_output = l_field_bits;

    FAPI_INF("%s. Raw card extension: %d",
             mss::c_str(iv_target),
             o_output);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes front module maximum thickness max
/// @param[out] o_output encoding from SPD
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 129 (Bits 3~0)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 2
/// @note Page 4.1.2.12.2 - 55
///
fapi2::ReturnCode decoder_v1_0::front_module_max_thickness(uint8_t& o_output)
{
    // Extracting desired bits
    uint8_t l_field_bits = extract_spd_field< FRONT_MODULE_THICKNESS >(iv_target, iv_spd_data);

    FAPI_INF("Field Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t MAX_VALID_VALUE = 0b1111;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits <= MAX_VALID_VALUE,
              FRONT_MODULE_THICKNESS.iv_byte,
              l_field_bits,
              "Failed bound check for front module max thickness") );

    // Update output only if check passes
    o_output = l_field_bits;

    FAPI_INF("%s. Front module max thickness: %d",
             mss::c_str(iv_target),
             o_output);

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Decodes back module maximum thickness max
/// @param[out] o_output encoding from SPD
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 129 (Bits 7~4)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 2
/// @note Page 4.1.2.12.2 - 55
///
fapi2::ReturnCode decoder_v1_0::back_module_max_thickness(uint8_t& o_output)
{
    // Extracting desired bits
    uint8_t l_field_bits = extract_spd_field< BACK_MODULE_THICKNESS >(iv_target, iv_spd_data);
    FAPI_INF("Field Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t MAX_VALID_VALUE = 0b1111;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits <= MAX_VALID_VALUE,
              BACK_MODULE_THICKNESS.iv_byte,
              l_field_bits,
              "Failed bound check for back module max thickness") );

    // Update output only if check passes
    o_output = l_field_bits;

    FAPI_INF("%s. Back module max thickness: %d",
             mss::c_str(iv_target),
             o_output);

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Decodes number of registers used on LRDIMM
/// @param[out] o_output encoding from SPD
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 131 (Bits 1~0)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 2
/// @note Page 4.1.2.12.2 - 57
///
fapi2::ReturnCode decoder_v1_0::num_registers_used(uint8_t& o_output)
{
    // Extracting desired bits
    uint8_t l_field_bits = extract_spd_field< NUM_REGISTERS_USED >(iv_target, iv_spd_data);
    FAPI_INF("Field Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t RESERVED = 0b10;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits < RESERVED,
              NUM_REGISTERS_USED.iv_byte,
              l_field_bits,
              "Failed bound check for number of registers used on RDIMM ") );

    // Update output only if check passes
    o_output = l_field_bits;

    FAPI_INF("%s. Number of registers used on LRDIMM : %d",
             mss::c_str(iv_target),
             o_output);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes number of rows of DRAMs on LRDIMM
/// @param[out] o_output encoding from SPD
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 131 (Bits 3~2)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 2
/// @note Page 4.1.2.12.2 - 57
///
fapi2::ReturnCode decoder_v1_0::num_rows_of_drams(uint8_t& o_output)
{
    // Extracting desired bits
    uint8_t l_field_bits = extract_spd_field< NUM_ROWS_OF_DRAMS >(iv_target, iv_spd_data);
    FAPI_INF("Field Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t RESERVED = 0b11;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits < RESERVED,
              NUM_REGISTERS_USED.iv_byte,
              l_field_bits,
              "Failed bound check for number of rows of DRAMs on LRDIMM ") );

    // Update output only if check passes
    o_output = l_field_bits;

    FAPI_INF("%s. Number of rows of DRAMs on LRDIMM : %d",
             mss::c_str(iv_target),
             o_output);

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Decodes heat spreader solution
/// @param[out] o_output drive strength encoding from SPD
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 132 (Bit 7)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 2
/// @note Page 4.1.2.12.2 - 58
///
fapi2::ReturnCode decoder_v1_0::heat_spreader_solution(uint8_t& o_output)
{
    // Extracting desired bits
    uint8_t l_field_bits = extract_spd_field< HEAT_SPREADER_SOLUTION >(iv_target, iv_spd_data);
    FAPI_INF("Field Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t MAX_VALID_VALUE = 1;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits <= MAX_VALID_VALUE,
              HEAT_SPREADER_SOLUTION.iv_byte,
              l_field_bits,
              "Failed bound check for heat spreader solution") );

    // Update output only if check passes
    o_output = l_field_bits;

    FAPI_INF("%s. Heat spreader solution: %d",
             mss::c_str(iv_target),
             o_output);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes number of continuation codes
/// @param[out] o_output encoding from SPD
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 133 (bit 6~0)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 2
/// @note Page 4.1.2.12.2 - 58
///
fapi2::ReturnCode decoder_v1_0::num_continuation_codes(uint8_t& o_output)
{
    // Extracting desired bits
    uint8_t l_field_bits = extract_spd_field< CONTINUATION_CODES >(iv_target, iv_spd_data);
    FAPI_INF("Field Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t MAX_VALID_VALUE = 10; // JEP106AS spec

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits <= MAX_VALID_VALUE,
              CONTINUATION_CODES.iv_byte,
              l_field_bits,
              "Failed bound check for number of continuation codes") );

    // Update output only if check passes
    o_output = l_field_bits;

    FAPI_INF("%s. Number of continuation codes: %d",
             mss::c_str(iv_target),
             o_output);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes register manufacturer ID code
/// @param[out] o_output drive strength encoding from SPD
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 134 (bit 7~0)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 2
/// @note Page 4.1.2.12.2 - 58
///
fapi2::ReturnCode decoder_v1_0::reg_manufacturer_id_code(uint8_t& o_output)
{
    constexpr size_t BYTE_INDEX = 134;
    uint8_t l_raw_byte = iv_spd_data[BYTE_INDEX];

    // Trace in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(iv_target),
             BYTE_INDEX,
             l_raw_byte);

    // All bits used for encoding, no bounds to check
    o_output = l_raw_byte;

    FAPI_INF("%s. Register revision number: %d",
             mss::c_str(iv_target),
             o_output);

    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Decodes register revision number
/// @param[out] o_output drive strength encoding from SPD
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 135 (bit 7~0)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 2
/// @note Page 4.1.2.12.2 - 58
///
fapi2::ReturnCode decoder_v1_0::register_rev_num(uint8_t& o_output)
{
    constexpr size_t BYTE_INDEX = 135;
    uint8_t l_raw_byte = iv_spd_data[BYTE_INDEX];

    // Trace in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(iv_target),
             BYTE_INDEX,
             l_raw_byte);

    // All bits used for encoding, no bounds to check
    o_output = l_raw_byte;

    FAPI_INF("%s. Register revision number: %d",
             mss::c_str(iv_target),
             o_output);

    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Decodes address mapping from register to dram
/// @param[out] o_output drive strength encoding from SPD
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 136 (bit 0)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 2
/// @note Page 4.1.2.12.2 - 59
///
fapi2::ReturnCode decoder_v1_0::register_to_dram_addr_mapping(uint8_t& o_output)
{
    // Extracting desired bits
    uint8_t l_field_bits = extract_spd_field< ADDR_MAPPING >(iv_target, iv_spd_data);
    FAPI_INF("Field Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t MAX_VALID_VAL = 1;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits <= MAX_VALID_VAL, // extract sanity check
              ADDR_MAPPING.iv_byte,
              l_field_bits,
              "Failed bound check for to register to dram addr mapping") );

    // Update output only if check passes
    o_output = l_field_bits;

    FAPI_INF("%s. Address mapping from register to dram: %d",
             mss::c_str(iv_target),
             o_output);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes register output drive strength for CKE signal
/// @param[out] o_output drive strength encoding from SPD
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 137 (bit 1~0)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 2
/// @note Page 4.1.2.12.2 - 60
///
fapi2::ReturnCode decoder_v1_0::cke_signal_output_driver(uint8_t& o_output)
{
    // Extracting desired bits
    uint8_t l_field_bits = extract_spd_field< CKE_DRIVE_STRENGTH >(iv_target, iv_spd_data);
    FAPI_INF("Field Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t RESERVED = 3;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits < RESERVED, // extract sanity check
              CKE_DRIVE_STRENGTH.iv_byte,
              l_field_bits,
              "Failed bounds check for Register Output Driver for CKE") );

    // Update output only if check passes
    o_output = l_field_bits;

    FAPI_INF("%s. Register Output Driver for CKE: %d",
             mss::c_str(iv_target),
             o_output);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes register output drive strength for ODT signal
/// @param[out] o_output drive strength encoding from SPD
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 137 (bit 3~2)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 2
/// @note Page 4.1.2.12.2 - 60
///
fapi2::ReturnCode decoder_v1_0::odt_signal_output_driver(uint8_t& o_output)
{
    // Extracting desired bits
    uint8_t l_field_bits = extract_spd_field< ODT_DRIVE_STRENGTH >(iv_target, iv_spd_data);
    FAPI_INF("Field Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t RESERVED = 3;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits < RESERVED, // extract sanity check
              ODT_DRIVE_STRENGTH.iv_byte,
              l_field_bits,
              "Failed bounds check for Register Output Driver for ODT") );

    // Update output only if check passes
    o_output = l_field_bits;

    FAPI_INF("%s. Register Output Driver for ODT: %d",
             mss::c_str(iv_target),
             o_output);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes register output drive strength for command/address (CA) signal
/// @param[out] o_output drive strength encoding from SPD
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 137 (bit 5~4)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 2
/// @note Page 4.1.2.12.2 - 60
///
fapi2::ReturnCode decoder_v1_0::ca_signal_output_driver(uint8_t& o_output)
{
    // Extracting desired bits
    uint8_t l_field_bits = extract_spd_field< CA_DRIVE_STRENGTH >(iv_target, iv_spd_data);
    FAPI_INF("Field Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t INVALID_VAL = 4;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits < INVALID_VAL, // extract sanity check
              CA_DRIVE_STRENGTH.iv_byte,
              l_field_bits,
              "Failed bounds check for Register Output Driver for CA") );

    // Update output only if check passes
    o_output = l_field_bits;

    FAPI_INF("%s. Register Output Driver for CA: %d",
             mss::c_str(iv_target),
             o_output);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes register output drive strength for control signal (CS) signal
/// @param[out] o_output drive strength encoding from SPD
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 137 (bit 6~7)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 2
/// @note Page 4.1.2.12.2 - 60
///
fapi2::ReturnCode decoder_v1_0::cs_signal_output_driver(uint8_t& o_output)
{
    // Extracting desired bits
    uint8_t l_field_bits = extract_spd_field< CS_DRIVE_STRENGTH >(iv_target, iv_spd_data);
    FAPI_INF("Field Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t RESERVED = 3;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits < RESERVED, // extract sanity check
              CS_DRIVE_STRENGTH.iv_byte,
              l_field_bits,
              "Failed bounds check for Register Output Driver for CS") );

    // Update output only if check passes
    o_output = l_field_bits;

    FAPI_INF("%s. Register Output Driver for CS: %d",
             mss::c_str(iv_target),
             o_output);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes register output drive strength for clock (B side)
/// @param[out] o_output drive strength encoding from SPD
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 138 (bit 1~0)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 2
/// @note Page 4.1.2.12.2 - 60
///
fapi2::ReturnCode decoder_v1_0::b_side_clk_output_driver(uint8_t& o_output)
{
    // Extracting desired bits
    uint8_t l_field_bits = extract_spd_field< B_SIDE_DRIVE_STRENGTH >(iv_target, iv_spd_data);
    FAPI_INF("Field Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t RESERVED = 3;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits < RESERVED, // extract sanity check
              B_SIDE_DRIVE_STRENGTH.iv_byte,
              l_field_bits,
              "Failed bounds check for Register Output Driver for clock (Y0,Y2)") );

    // Update output only if check passes
    o_output = l_field_bits;

    FAPI_INF("%s. Register Output Driver for clock (Y0,Y2): %d",
             mss::c_str(iv_target),
             o_output);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes register output drive strength for clock (A side)
/// @param[out] o_output drive strength encoding from SPD
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 138 (bit 3~2)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 2
/// @note Page 4.1.2.12.2 - 60
///
fapi2::ReturnCode decoder_v1_0::a_side_clk_output_driver(uint8_t& o_output)
{
    // Extracting desired bits
    uint8_t l_field_bits = extract_spd_field< A_SIDE_DRIVE_STRENGTH >(iv_target, iv_spd_data);
    FAPI_INF("Field Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t RESERVED = 3;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits < RESERVED,
              A_SIDE_DRIVE_STRENGTH.iv_byte,
              l_field_bits,
              "Failed bounds check for Register Output Driver for clock (Y1,Y3)") );

    // Update output only if check passes
    o_output = l_field_bits;

    FAPI_INF("%s. Register Output Driver for clock (Y1,Y3): %d",
             mss::c_str(iv_target),
             o_output);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes data buffer revision number
/// @param[out] o_output revision number
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 139 (Bits 7~0)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 2
/// @note Page 4.1.2.12.2 - 60
///
fapi2::ReturnCode decoder_v1_0::data_buffer_rev(uint8_t& o_output)
{
    // Extracting desired bits
    constexpr size_t BYTE_INDEX = 139;
    const uint8_t l_raw_byte = iv_spd_data[BYTE_INDEX];

    // Trace in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(iv_target),
             BYTE_INDEX,
             l_raw_byte);

    // This checks JEDEC range is met
    constexpr size_t UNDEFINED = 0xFF;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_raw_byte != UNDEFINED,
              BYTE_INDEX,
              l_raw_byte,
              "Failed bounds check for data buffer revision number") );

    // Update output only if check passes
    o_output = l_raw_byte;

    FAPI_INF("%s. Data buffer rev: %d",
             mss::c_str(iv_target),
             o_output);

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Decodes DRAM VrefDQ for Package Rank 0
/// @param[out] o_output encoding of MR6 A5:A0 in JESD790-4 spec
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 140 (Bits 5~0)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 2
/// @note Page 4.1.2.12.2 - 61
///
fapi2::ReturnCode decoder_v1_0::dram_vref_dq_rank0(uint8_t& o_output)
{
    // Extracting desired bits
    uint8_t l_field_bits = extract_spd_field< VREF_DQ_RANK0 >(iv_target, iv_spd_data);
    FAPI_INF("Field Bits value: %d", l_field_bits);

    // JESD79-4 specification
    constexpr size_t RESERVED = 0b110011;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits < RESERVED,
              VREF_DQ_RANK0.iv_byte,
              l_field_bits,
              "Failed bounds check for DRAM VrefDQ for Package Rank 0") );

    // Update output only if check passes
    o_output = l_field_bits;

    FAPI_INF("%s. DRAM VrefDQ for Package Rank 0: %d",
             mss::c_str(iv_target),
             o_output);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes DRAM VrefDQ for Package Rank 1
/// @param[out] o_output encoding of MR6 A5:A0 in JESD790-4 spec
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 141 (Bits 5~0)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 2
/// @note Page 4.1.2.12.2 - 61
///
fapi2::ReturnCode decoder_v1_0::dram_vref_dq_rank1(uint8_t& o_output)
{
    // Extracting desired bits
    uint8_t l_field_bits = extract_spd_field< VREF_DQ_RANK1 >(iv_target, iv_spd_data);
    FAPI_INF("Field Bits value: %d", l_field_bits);

    // JESD79-4 specification
    constexpr size_t RESERVED = 0b110011;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits < RESERVED,
              VREF_DQ_RANK1.iv_byte,
              l_field_bits,
              "Failed bounds check for DRAM VrefDQ for Package Rank 1") );

    // Update output only if check passes
    o_output = l_field_bits;

    FAPI_INF("%s. DRAM VrefDQ for Package Rank 1: %d",
             mss::c_str(iv_target),
             o_output);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes DRAM VrefDQ for Package Rank 2
/// @param[out] o_output encoding of MR6 A5:A0 in JESD790-4 spec
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 142 (Bits 5~0)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 2
/// @note Page 4.1.2.12.2 - 61
///
fapi2::ReturnCode decoder_v1_0::dram_vref_dq_rank2(uint8_t& o_output)
{
    // Extracting desired bits
    uint8_t l_field_bits = extract_spd_field< VREF_DQ_RANK2  >(iv_target, iv_spd_data);
    FAPI_INF("Field Bits value: %d", l_field_bits);

    // JESD79-4 specification
    constexpr size_t RESERVED = 0b110011;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits < RESERVED,
              VREF_DQ_RANK2.iv_byte,
              l_field_bits,
              "Failed bounds check for DRAM VrefDQ for Package Rank 2") );

    // Update output only if check passes
    o_output = l_field_bits;

    FAPI_INF("%s. DRAM VrefDQ for Package Rank 2: %d",
             mss::c_str(iv_target),
             o_output);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes DRAM VrefDQ for Package Rank 3
/// @param[out] o_output encoding of MR6 A5:A0 in JESD790-4 spec
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 143 (Bits 5~0)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 4
/// @note Page 4.1.2.12.2 - 61
///
fapi2::ReturnCode decoder_v1_0::dram_vref_dq_rank3(uint8_t& o_output)
{
    // Extracting desired bits
    uint8_t l_field_bits = extract_spd_field< VREF_DQ_RANK3 >(iv_target, iv_spd_data);
    FAPI_INF("Field Bits value: %d", l_field_bits);

    // JESD79-4 specification
    constexpr size_t RESERVED = 0b110011;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits < RESERVED,
              VREF_DQ_RANK3.iv_byte,
              l_field_bits,
              "Failed bounds check for DRAM VrefDQ for Package Rank 3") );

    // Update output only if check passes
    o_output = l_field_bits;

    FAPI_INF("%s. DRAM VrefDQ for Package Rank 3: %d",
             mss::c_str(iv_target),
             o_output);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes data buffer VrefDQ for DRAM interface
/// @param[out] o_output encoding of F5BC6x in DDR4DB01 spec
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 144 (Bits 5~0)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 2
/// @note Page 4.1.2.12.2 - 61
///
fapi2::ReturnCode decoder_v1_0::data_buffer_vref_dq(uint8_t& o_output)
{
    constexpr size_t BYTE_INDEX = 144;
    uint8_t l_raw_data = iv_spd_data[BYTE_INDEX];

    // Trace in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(iv_target),
             BYTE_INDEX,
             l_raw_data);

    // DDR4DB01 spec
    constexpr size_t RESERVED = 0b00110011;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_raw_data < RESERVED,
              BYTE_INDEX,
              l_raw_data,
              "Failed bounds check for data buffer VrefDQ for DRAM interface") );

    // Update output only if check passes
    o_output = l_raw_data;

    FAPI_INF("%s. Data buffer VrefDQ for DRAM interface: %d",
             mss::c_str(iv_target),
             o_output);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes DRAM interface MDQ Drive Strenth
/// of the data buffer component for a particular dimm speed
/// @param[in] i_dimm_speed the dimm speed in MT/s
/// @param[out] o_output encoding of F5BC6x in
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 145 - 147 (Bits 6~4)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 2
/// @note Page 4.1.2.12.2 - 62
///
fapi2::ReturnCode decoder_v1_0::data_buffer_mdq_drive_strength(const uint64_t i_dimm_speed, uint8_t& o_output)
{
    uint8_t l_byte = 0;
    uint8_t l_field_bits = 0;

    FAPI_TRY( mdq_helper(i_dimm_speed, l_byte) );

    {
        constexpr size_t START = 1;
        constexpr size_t LEN = 3;
        const field_t MDQ_DRIVE_STRENGTH(l_byte, START, LEN);

        l_field_bits = extract_spd_field( iv_target, MDQ_DRIVE_STRENGTH, iv_spd_data );
        FAPI_INF("Field Bits value: %d", l_field_bits);

        // Lets make sure we aren't being set to a reserved field
        bool is_reserved_bit = false;

        switch(l_field_bits)
        {
            case 0b011:
            case 0b100:
            case 0b110:
            case 0b111:
                is_reserved_bit = true;
                break;

            default:
                is_reserved_bit = false;
                break;
        }

        // This checks my extracting params returns a value within bound
        constexpr size_t MAX_VALID_VALUE = 7;

        FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
                  (l_field_bits <= MAX_VALID_VALUE) &&
                  (is_reserved_bit != true),
                  l_byte,
                  l_field_bits,
                  "Failed bounds check for DRAM interface MDQ Drive Strenth") );

        // Update output only if check passes
        o_output = l_field_bits;

        FAPI_INF("%s. DRAM interface MDQ Drive Strenth: %d",
                 mss::c_str(iv_target),
                 o_output);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes DRAM interface MDQ read termination strength
/// of the data buffer component for a particular dimm speed
/// @param[in] i_dimm_speed the dimm speed in MT/s
/// @param[out] o_output encoding of F5BC6x in
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 145 - 147 (Bits 2~0)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 2
/// @note Page 4.1.2.12.2 - 62
///
fapi2::ReturnCode decoder_v1_0::data_buffer_mdq_rtt(const uint64_t i_dimm_speed, uint8_t& o_output)
{
    uint8_t l_byte = 0;
    uint8_t l_field_bits = 0;

    FAPI_TRY( mdq_helper(i_dimm_speed, l_byte) );

    {
        constexpr size_t START = 1;
        constexpr size_t LEN = 3;
        const field_t DATA_BUFFER_MDQ_RTT(l_byte, START, LEN);

        l_field_bits = extract_spd_field( iv_target, DATA_BUFFER_MDQ_RTT, iv_spd_data );
        FAPI_INF("Field Bits value: %d", l_field_bits);

        // This checks my extracting params returns a value within bound
        constexpr size_t MAX_VALID_VALUE = 7;

        FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
                  l_field_bits <= MAX_VALID_VALUE,
                  l_byte,
                  l_field_bits,
                  "Failed bounds check for DRAM interface MDQ RTT:") );

        // Update output only if check passes
        o_output = l_field_bits;

        FAPI_INF("%s. DRAM interface MDQ RTT: %d",
                 mss::c_str(iv_target),
                 o_output);
    }
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes DRAM drive strenth
/// for a particular dimm speed
/// @param[in] i_dimm_speed the dimm speed in MT/s
/// @param[out] o_output DRAM drive strength (encoding)
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 148 (Bits 5~0)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 2
/// @note Page 4.1.2.12.2 - 63
///
fapi2::ReturnCode decoder_v1_0::dram_drive_strength(const uint64_t i_dimm_speed, uint8_t& o_output)
{
    size_t l_start = 0;
    FAPI_TRY( drive_strength_start_bit_finder(i_dimm_speed, l_start) );

    {
        constexpr size_t BYTE_INDEX = 148;
        constexpr size_t LEN = 2;
        const field_t DRAM_DRIVE_STRENGTH(BYTE_INDEX, l_start, LEN);

        uint8_t l_field_bits = extract_spd_field( iv_target, DRAM_DRIVE_STRENGTH, iv_spd_data );
        FAPI_INF("Field Bits value: %d", l_field_bits);

        // SPD JEDEC specification
        constexpr size_t RESERVED = 0b11;

        FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
                  l_field_bits < RESERVED,
                  BYTE_INDEX,
                  l_field_bits,
                  "Failed bounds check for DRAM VrefDQ for Package Rank 3") );

        // Update output only if check passes
        o_output = l_field_bits;

        FAPI_INF("%s. DRAM drive strenth: %d",
                 mss::c_str(iv_target),
                 o_output);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes DRAM ODT for RTT_NOM
/// for a particular dimm speed
/// @param[in] i_dimm_speed the dimm speed in MT/s
/// @param[out] o_output ODT termination strength (encoding)
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 149 - 151 (Bits 2~0)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 2
/// @note Page 4.1.2.12.2 - (64 - 65)
///
fapi2::ReturnCode decoder_v1_0::dram_rtt_nom(const uint64_t i_dimm_speed, uint8_t& o_output)
{
    size_t l_byte = 0;
    FAPI_TRY( rtt_wr_and_nom_byte_finder(i_dimm_speed, l_byte) );

    {
        constexpr size_t START = 5;
        constexpr size_t LEN = 3;
        const field_t DRAM_RTT_NOM(l_byte, START, LEN);

        uint8_t l_field_bits = extract_spd_field(iv_target,  DRAM_RTT_NOM, iv_spd_data);
        FAPI_INF("Field Bits value: %d", l_field_bits);

        // This checks my extracting params returns a value within bound
        constexpr size_t MAX_VALID_VALUE = 7;

        FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
                  l_field_bits <= MAX_VALID_VALUE,
                  l_byte,
                  l_field_bits,
                  "Failed bounds check for DRAM RTT_NOM") );

        // Update output only if check passes
        o_output = l_field_bits;

        FAPI_INF("%s. DRAM RTT_NOM: %d",
                 mss::c_str(iv_target),
                 o_output);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes DRAM ODT for RTT_WR
/// for a particular dimm speed
/// @param[in] i_dimm_speed the dimm speed in MT/s
/// @param[out] o_output ODT termination strength (encoding)
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 149 - 151 (Bits 5~3)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 2
/// @note Page 4.1.2.12.2 - (64 - 65)
///
fapi2::ReturnCode decoder_v1_0::dram_rtt_wr(const uint64_t i_dimm_speed, uint8_t& o_output)
{
    size_t l_byte = 0;
    FAPI_TRY( rtt_wr_and_nom_byte_finder(i_dimm_speed, l_byte) );

    {
        constexpr size_t START = 2;
        constexpr size_t LEN = 3;
        const field_t DRAM_RTT_WR(l_byte, START, LEN);

        uint8_t l_field_bits = extract_spd_field(iv_target, DRAM_RTT_WR, iv_spd_data);
        FAPI_INF("Field Bits value: %d", l_field_bits);

        // Lets make sure we aren't being set to a reserved field
        bool is_reserved_bit = false;

        switch(l_field_bits)
        {
            case 0b101:
            case 0b110:
            case 0b111:
                is_reserved_bit = true;
                break;

            default:
                is_reserved_bit = false;
                break;
        }

        // This checks my extracting params returns a value within bound
        constexpr size_t MAX_VALID_VALUE = 7;

        FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
                  (l_field_bits <= MAX_VALID_VALUE) &&
                  (is_reserved_bit != true),
                  l_byte,
                  l_field_bits,
                  "Failed bounds check for DRAM RTT_WR") );

        // Update output only if check passes
        o_output = l_field_bits;

        FAPI_INF("%s. DRAM_RTT_WR: %d",
                 mss::c_str(iv_target),
                 o_output);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes DRAM ODT for RTT_PARK, package ranks 0 & 1
/// for a particular dimm speed
/// @param[in] i_dimm_speed the dimm speed in MT/s
/// @param[out] o_output ODT termination strength (encoding)
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 152 - 154 (Bits 2~0)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 2
/// @note Page 4.1.2.12.2 - 65
///
fapi2::ReturnCode decoder_v1_0::dram_rtt_park_ranks0_1(const uint64_t i_dimm_speed, uint8_t& o_output)
{
    size_t l_byte = 0;
    FAPI_TRY( rtt_park_byte_finder(i_dimm_speed, l_byte) );

    {
        constexpr size_t START = 5;
        constexpr size_t LEN = 3;
        const field_t DRAM_RTT_PARK(l_byte, START, LEN);

        uint8_t l_field_bits = extract_spd_field(iv_target, DRAM_RTT_PARK, iv_spd_data);
        FAPI_INF("Field Bits value: %d", l_field_bits);

        // This checks my extracting params returns a value within bound
        constexpr size_t MAX_VALID_VALUE = 7;

        FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
                  l_field_bits <= MAX_VALID_VALUE,
                  l_byte,
                  l_field_bits,
                  "Failed bounds check for DRAM RTT_PARK (package ranks 0,1)") );

        // Update output only if check passes
        o_output = l_field_bits;

        FAPI_INF("%s. DRAM RTT_PARK (package ranks 0,1): %d",
                 mss::c_str(iv_target),
                 o_output);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes DRAM ODT for RTT_PARK, package ranks 2 & 3
/// for a particular dimm speed
/// @param[in] i_dimm_speed the dimm speed in MT/s
/// @param[out] o_output ODT termination strength (encoding)
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 152 - 154 (Bits 5~3)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 2
/// @note Page 4.1.2.12.2 - 65
///
fapi2::ReturnCode decoder_v1_0::dram_rtt_park_ranks2_3(const uint64_t i_dimm_speed, uint8_t& o_output)
{
    size_t l_byte = 0;
    FAPI_TRY( rtt_park_byte_finder(i_dimm_speed, l_byte) );

    {
        constexpr size_t START = 2;
        constexpr size_t LEN = 3;
        const field_t DRAM_RTT_PARK(l_byte, START, LEN);

        uint8_t l_field_bits = extract_spd_field(iv_target, DRAM_RTT_PARK, iv_spd_data);
        FAPI_INF("Field Bits value: %d", l_field_bits);

        // This checks my extracting params returns a value within bound
        constexpr size_t MAX_VALID_VALUE = 7;

        FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
                  l_field_bits <= MAX_VALID_VALUE,
                  l_byte,
                  l_field_bits,
                  "Failed bounds check for DRAM RTT_PARK (package ranks 2,3)") );

        // Update output only if check passes
        o_output = l_field_bits;

        FAPI_INF("%s. DRAM RTT_PARK (package ranks 2,3): %d",
                 mss::c_str(iv_target),
                 o_output);
    }

fapi_try_exit:
    return fapi2::current_err;
}

}// lrdimm
}//spd
}// mss
