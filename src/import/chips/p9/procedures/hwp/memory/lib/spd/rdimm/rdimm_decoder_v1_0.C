/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/spd/rdimm/rdimm_decoder_v1_0.C $ */
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
/// @file rdimm_decoder.C
/// @brief RDIMM module specific SPD decoder definitions
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
#include <lib/spd/rdimm/rdimm_decoder.H>
#include <lib/spd/common/spd_decoder.H>
#include <lib/utils/checker.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/find.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_DIMM;


namespace mss
{
namespace spd
{

/////////////////////////
// Member Method implementation
// For RDIMM module rev 1.0
/////////////////////////

///
/// @brief Decodes module nominal height max, in mm
/// @param[out] o_output height range encoding from SPD
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 128 (Bits 4~0)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 2
/// @note Page 4.1.2.12 - 48
///
fapi2::ReturnCode rdimm_decoder_v1_0::max_module_nominal_height(uint8_t& o_output)
{
    constexpr size_t BYTE_INDEX = 128;
    uint8_t l_field_bits = extract_spd_field<BYTE_INDEX, MODULE_NOM_HEIGHT_START, MODULE_NOM_HEIGHT_LEN>(iv_target,
                           iv_spd_data);

    FAPI_INF("Field_Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t MAX_VALID_VALUE = 0b11111;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits <= MAX_VALID_VALUE,
              BYTE_INDEX,
              l_field_bits,
              "Failed bound check for module nominal height max") );

    o_output = l_field_bits;

    FAPI_INF("%s. Max module nominal height: %d",
             mss::c_str(iv_target),
             o_output);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes front module maximum thickness max, in mm
/// @param[out] o_output encoding from SPD
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 129 (Bits 3~0)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 2
/// @note Page 4.1.2.12 - 48
///
fapi2::ReturnCode rdimm_decoder_v1_0::front_module_max_thickness(uint8_t& o_output)
{
    // Extracting desired bits
    constexpr size_t BYTE_INDEX = 129;
    uint8_t l_field_bits = extract_spd_field<BYTE_INDEX, FRONT_MODULE_THICKNESS_START, FRONT_MODULE_THICKNESS_LEN>
                           (iv_target, iv_spd_data);

    FAPI_INF("Field_Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t MAX_VALID_VALUE = 0b1111;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits <= MAX_VALID_VALUE,
              BYTE_INDEX,
              l_field_bits,
              "Failed bound check for front module max thickness") );

    o_output = l_field_bits;

    FAPI_INF("%s. Front module max thickness: %d",
             mss::c_str(iv_target),
             o_output);

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Decodes back module maximum thickness max, in mm
/// @param[out] o_output encoding from SPD
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 129 (Bits 7~4)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 2
/// @note Page 4.1.2.12 - 48
///
fapi2::ReturnCode rdimm_decoder_v1_0::back_module_max_thickness(uint8_t& o_output)
{
    // Extracting desired bits
    constexpr size_t BYTE_INDEX = 129;
    uint8_t l_field_bits = extract_spd_field<BYTE_INDEX, BACK_MODULE_THICKNESS_START, BACK_MODULE_THICKNESS_LEN>(iv_target,
                           iv_spd_data);
    FAPI_INF("Field_Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t MAX_VALID_VALUE = 0b1111;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits <= MAX_VALID_VALUE,
              BYTE_INDEX,
              l_field_bits,
              "Failed bound check for back module max thickness") );

    o_output = l_field_bits;

    FAPI_INF("%s. Back module max thickness: %d",
             mss::c_str(iv_target),
             o_output);

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Decodes number of registers used on RDIMM
/// @param[out] o_output encoding from SPD
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 131 (Bits 1~0)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 2
/// @note Page 4.1.2.12 - 50
///
fapi2::ReturnCode rdimm_decoder_v1_0::num_registers_used(uint8_t& o_output)
{
    // Extracting desired bits
    constexpr size_t BYTE_INDEX = 131;
    uint8_t l_field_bits = extract_spd_field<BYTE_INDEX, REGS_USED_START, REGS_USED_LEN>(iv_target, iv_spd_data);

    FAPI_INF("Field_Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t MAX_VALID_VALUE = 0b11;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits <= MAX_VALID_VALUE,
              BYTE_INDEX,
              l_field_bits,
              "Failed bound check for number of registers used on RDIMM ") );

    o_output = l_field_bits;

    FAPI_INF("%s. Number of registers used on RDIMM : %d",
             mss::c_str(iv_target),
             o_output);

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Decodes number of rows of DRAMs on RDIMM
/// @param[out] o_output encoding from SPD
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 131 (Bits 3~2)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 2
/// @note Page 4.1.2.12 - 50
///
fapi2::ReturnCode rdimm_decoder_v1_0::num_rows_of_drams(uint8_t& o_output)
{
    // Extracting desired bits
    constexpr size_t BYTE_INDEX = 131;
    uint8_t l_field_bits = extract_spd_field<BYTE_INDEX, ROWS_OF_DRAMS_START, ROWS_OF_DRAMS_LEN>(iv_target, iv_spd_data);

    FAPI_INF("Field_Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t MAX_VALID_VALUE = 0b11;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits <= MAX_VALID_VALUE,
              BYTE_INDEX,
              l_field_bits,
              "Failed bound check for number of rows of DRAMs on RDIMM ") );

    o_output = l_field_bits;

    FAPI_INF("%s. Number of rows of DRAMs on RDIMM : %d",
             mss::c_str(iv_target),
             o_output);

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Decodes heat spreader thermal characteristics
/// @param[out] o_output drive strength encoding from SPD
/// @return FAPI2_RC_SUCCEawSS if okay
/// @note SPD Byte 132 (Bits 6~0)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 2
/// @note Page 4.1.2.12 - 51
///
fapi2::ReturnCode rdimm_decoder_v1_0::heat_spreader_thermal_char(uint8_t& o_output)
{
    // Extracting desired bits
    constexpr size_t BYTE_INDEX = 132;
    uint8_t l_field_bits = extract_spd_field<BYTE_INDEX, HEAT_SPREADER_CHAR_START, HEAT_SPREADER_CHAR_LEN>(iv_target,
                           iv_spd_data);
    FAPI_INF("Field_Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t MAX_VALID_VALUE = 1;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits <= MAX_VALID_VALUE,
              BYTE_INDEX,
              l_field_bits,
              "Failed bound check for heat spreader thermal characteristics") );

    o_output = l_field_bits;

    FAPI_INF("%s. Heat spreader thermal characteristics: %d",
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
/// @note Page 4.1.2.12 - 51
///
fapi2::ReturnCode rdimm_decoder_v1_0::heat_spreader_solution(uint8_t& o_output)
{
    // Extracting desired bits
    constexpr size_t BYTE_INDEX = 132;
    uint8_t l_field_bits = extract_spd_field<BYTE_INDEX, HEAT_SPREADER_SOL_START, HEAT_SPREADER_SOL_LEN>(iv_target,
                           iv_spd_data);

    FAPI_INF("Field_Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t MAX_VALID_VALUE = 1;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits <= MAX_VALID_VALUE,
              BYTE_INDEX,
              l_field_bits,
              "Failed bound check for heat spreader solution") );

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
/// @note Page 4.1.2.12 - 51
///
fapi2::ReturnCode rdimm_decoder_v1_0::num_continuation_codes(uint8_t& o_output)
{
    // Extracting desired bits
    constexpr size_t BYTE_INDEX = 133;
    uint8_t l_field_bits = extract_spd_field<BYTE_INDEX, CONTINUATION_CODES_START, CONTINUATION_CODES_LEN>(iv_target,
                           iv_spd_data);

    FAPI_INF("Field_Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t MAX_VALID_VALUE = 10; // JEP106AS

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits <= MAX_VALID_VALUE,
              BYTE_INDEX,
              l_field_bits,
              "Failed bound check for number of continuation codes") );

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
/// @note Page 4.1.2.12 - 51
///
fapi2::ReturnCode rdimm_decoder_v1_0::reg_manufacturer_id_code(uint8_t& o_output)
{
    constexpr size_t BYTE_INDEX = 134;
    uint8_t l_raw_byte = iv_spd_data[BYTE_INDEX];

    // Trace in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(iv_target),
             BYTE_INDEX,
             l_raw_byte);

    o_output = l_raw_byte;

    FAPI_INF("%s. Manufacturer ID code: %d",
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
/// @note Page 4.1.2.12 - 51
///
fapi2::ReturnCode rdimm_decoder_v1_0::register_rev_num(uint8_t& o_output)
{
    constexpr size_t BYTE_INDEX = 135;
    uint8_t l_raw_byte = iv_spd_data[BYTE_INDEX];

    // Trace in the front assists w/ debug
    FAPI_INF("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(iv_target),
             BYTE_INDEX,
             l_raw_byte);

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
/// @note Page 4.1.2.12 - 52
///
fapi2::ReturnCode rdimm_decoder_v1_0::register_to_dram_addr_mapping(uint8_t& o_output)
{
    // Extracting desired bits
    constexpr size_t BYTE_INDEX = 136;
    uint8_t l_field_bits = extract_spd_field<BYTE_INDEX, ADDR_MAPPING_START, ADDR_MAPPING_LEN>(iv_target, iv_spd_data);

    FAPI_INF("Field_Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t RESERVED = 0b11;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits < RESERVED, // extract sanity check
              BYTE_INDEX,
              l_field_bits,
              "Failed bound check for to register to dram addr mapping") );

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
/// @note Page 4.1.2.12 - 53
///
fapi2::ReturnCode rdimm_decoder_v1_0::cke_signal_output_driver(uint8_t& o_output)
{
    // Extracting desired bits
    constexpr size_t BYTE_INDEX = 137;
    uint8_t l_field_bits = extract_spd_field<BYTE_INDEX, CKE_DRIVER_START, CKE_DRIVER_LEN>(iv_target, iv_spd_data);

    FAPI_INF("Field_Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t RESERVED = 2;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits < RESERVED, // extract sanity check
              BYTE_INDEX,
              l_field_bits,
              "Failed bounds check for Register Output Driver for CKE") );

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
/// @note Page 4.1.2.12 - 53
///
fapi2::ReturnCode rdimm_decoder_v1_0::odt_signal_output_driver(uint8_t& o_output)
{
    // Extracting desired bits
    constexpr size_t BYTE_INDEX = 137;
    uint8_t l_field_bits = extract_spd_field<BYTE_INDEX, ODT_DRIVER_START, ODT_DRIVER_LEN>(iv_target, iv_spd_data);

    FAPI_INF("Field_Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t RESERVED = 2;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits < RESERVED, // extract sanity check
              BYTE_INDEX,
              l_field_bits,
              "Failed bounds check for Register Output Driver for ODT") );

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
/// @note Page 4.1.2.12 - 53
///
fapi2::ReturnCode rdimm_decoder_v1_0::ca_signal_output_driver(uint8_t& o_output)
{
    // Extracting desired bits
    constexpr size_t BYTE_INDEX = 137;
    uint8_t l_field_bits = extract_spd_field<BYTE_INDEX, CA_DRIVER_START, CA_DRIVER_LEN>(iv_target, iv_spd_data);

    FAPI_INF("Field_Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t INVALID_VAL = 3;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits < INVALID_VAL, // extract sanity check
              BYTE_INDEX,
              l_field_bits,
              "Failed bounds check for Register Output Driver for CA") );

    o_output = l_field_bits;

    FAPI_INF("%s. Register Output Driver for CA: %d",
             mss::c_str(iv_target),
             o_output);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes register output drive strength for chip select (CS) signal
/// @param[out] o_output drive strength encoding from SPD
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 137 (bit 6~7)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 2
/// @note Page 4.1.2.12 - 53
///
fapi2::ReturnCode rdimm_decoder_v1_0::cs_signal_output_driver(uint8_t& o_output)
{
    // Extracting desired bits
    constexpr size_t BYTE_INDEX = 137;
    uint8_t l_field_bits = extract_spd_field<BYTE_INDEX, CS_DRIVER_START, CS_DRIVER_LEN>(iv_target, iv_spd_data);

    FAPI_INF("Field_Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t RESERVED = 2;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits < RESERVED, // extract sanity check
              BYTE_INDEX,
              l_field_bits,
              "Failed bounds check for Register Output Driver for CS") );

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
/// @note Page 4.1.2.12 - 53
///
fapi2::ReturnCode rdimm_decoder_v1_0::b_side_clk_output_driver(uint8_t& o_output)
{
    // Extracting desired bits
    constexpr size_t BYTE_INDEX = 138;
    uint8_t l_field_bits = extract_spd_field<BYTE_INDEX, YO_Y2_DRIVER_START, YO_Y2_DRIVER_LEN>(iv_target, iv_spd_data);

    // This checks my extracting params returns a value within bound
    constexpr size_t RESERVED = 2;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits < RESERVED, // extract sanity check
              BYTE_INDEX,
              l_field_bits,
              "Failed bounds check for Register Output Driver for clock (Y0,Y2)") );

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
/// @note Page 4.1.2.12 - 53
///
fapi2::ReturnCode rdimm_decoder_v1_0::a_side_clk_output_driver(uint8_t& o_output)
{
    // Trace in the front assists w/ debug
    constexpr size_t BYTE_INDEX = 138;

    // Extracting desired bits
    uint8_t l_field_bits = extract_spd_field<BYTE_INDEX, Y1_Y3_DRIVER_START, Y1_Y3_DRIVER_LEN>(iv_target, iv_spd_data);

    FAPI_INF("Field_Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t RESERVED = 2;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits < RESERVED,
              BYTE_INDEX,
              l_field_bits,
              "Failed bounds check for Register Output Driver for clock (Y1,Y3)") );

    o_output = l_field_bits;

    FAPI_INF("%s. Register Output Driver for clock (Y1,Y3): %d",
             mss::c_str(iv_target),
             o_output);

fapi_try_exit:
    return fapi2::current_err;
}

}//spd namespace
}// mss namespace
