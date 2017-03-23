/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/rdimm/ddr4/rdimm_decoder_ddr4_v1_1.C $ */
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

// std lib
#include <vector>

// fapi2
#include <fapi2.H>

// mss lib
#include <generic/memory/lib/spd/rdimm/ddr4/rdimm_decoder_ddr4.H>
#include <generic/memory/lib/spd/common/ddr4/spd_decoder_ddr4.H>
#include <generic/memory/lib/spd/spd_checker.H>
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
// For RDIMM module rev 1.1
/////////////////////////

///
/// @brief Decodes register type
/// @param[out] o_output encoding from SPD
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 131 (Bits 7~4)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 3
/// @note Page 4.1.2.12.3 - 63
///
fapi2::ReturnCode rdimm_decoder_v1_1::register_and_buffer_type(uint8_t& o_output)
{
    constexpr size_t BYTE = 131;
    // Extracting desired bits
    uint8_t l_field_bits = extract_spd_field<BYTE, REGISTER_TYPE_START, REGISTER_TYPE_LEN>(iv_target, iv_spd_data);
    FAPI_INF("Field Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t RESERVED = 2;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              (l_field_bits < RESERVED), // extract sanity check
              BYTE,
              l_field_bits,
              "Failed bounds check for Register and Data Buffer Types") );

    // Update output only if check passes
    o_output = l_field_bits;

    FAPI_INF("%s. Register Types: %d",
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
/// @note Item JC-45-2220.01x
/// @note Page 76
/// @note DDR4 SPD Document Release 4
///
fapi2::ReturnCode rdimm_decoder_v1_1::cke_signal_output_driver(uint8_t& o_output)
{
    // Extracting desired bits
    constexpr size_t BYTE = 137;
    uint8_t l_field_bits = extract_spd_field<BYTE, CKE_DRIVER_START, CKE_DRIVER_LEN>(iv_target, iv_spd_data);

    FAPI_INF("Field_Bits value: %d", l_field_bits);

    // This really just checks my extract gives me a valid value
    constexpr size_t MAX_VALID_VALUE = 0b11;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              (l_field_bits <= MAX_VALID_VALUE), // extract sanity check
              BYTE,
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
/// @note Item JC-45-2220.01x
/// @note Page 76
/// @note DDR4 SPD Document Release 4
///
fapi2::ReturnCode rdimm_decoder_v1_1::odt_signal_output_driver(uint8_t& o_output)
{
    // Extracting desired bits
    constexpr size_t BYTE = 137;
    uint8_t l_field_bits = extract_spd_field<BYTE, ODT_DRIVER_START, ODT_DRIVER_LEN>(iv_target, iv_spd_data);

    FAPI_INF("Field_Bits value: %d", l_field_bits);

    // This really just checks my extract gives me a valid value
    constexpr size_t MAX_VALID_VALUE = 0b11;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              (l_field_bits <= MAX_VALID_VALUE), // extract sanity check
              BYTE,
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
/// @brief Decodes register output drive strength for control signal (CS) signal
/// @param[out] o_output drive strength encoding from SPD
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 137 (bit 6~7)
/// @note Item JC-45-2220.01x
/// @note Page 76
/// @note DDR4 SPD Document Release 4
///
fapi2::ReturnCode rdimm_decoder_v1_1::cs_signal_output_driver(uint8_t& o_output)
{
    // Extracting desired bits
    constexpr size_t BYTE = 137;
    uint8_t l_field_bits = extract_spd_field<BYTE, CS_DRIVER_START, CS_DRIVER_LEN>(iv_target, iv_spd_data);

    FAPI_INF("Field_Bits value: %d", l_field_bits);

    // This really just checks my extract gives me a valid value
    constexpr size_t MAX_VALID_VALUE = 0b11;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              (l_field_bits <= MAX_VALID_VALUE), // extract sanity check
              BYTE,
              l_field_bits,
              "Failed bounds check for Register Output Driver for chip select") );

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
/// @note Item JC-45-2220.01x
/// @note Page 76
/// @note DDR4 SPD Document Release 4
///
fapi2::ReturnCode rdimm_decoder_v1_1::b_side_clk_output_driver(uint8_t& o_output)
{
    // Extracting desired bits
    constexpr size_t BYTE = 138;
    uint8_t l_field_bits = extract_spd_field<BYTE, YO_Y2_DRIVER_START, YO_Y2_DRIVER_LEN>(iv_target, iv_spd_data);

    FAPI_INF("Field_Bits value: %d", l_field_bits);

    // This really just checks my extract gives me a valid value
    constexpr size_t MAX_VALID_VAL = 2;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              (l_field_bits <= MAX_VALID_VAL), // extract sanity check
              BYTE,
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
/// @note Item JC-45-2220.01x
/// @note Page 76
/// @note DDR4 SPD Document Release 4
///
fapi2::ReturnCode rdimm_decoder_v1_1::a_side_clk_output_driver(uint8_t& o_output)
{
    // Extracting desired bits
    constexpr size_t BYTE = 138;
    uint8_t l_field_bits = extract_spd_field<BYTE, Y1_Y3_DRIVER_START, Y1_Y3_DRIVER_LEN>(iv_target, iv_spd_data);

    FAPI_INF("Field_Bits value: %d", l_field_bits);

    // This really just checks my extract gives me a valid value
    constexpr size_t MAX_VALID_VAL = 2;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              (l_field_bits <= MAX_VALID_VAL), // extract sanity check
              BYTE,
              l_field_bits,
              "Failed bounds check for Register Output Driver for clock (Y1,Y3)") );

    o_output = l_field_bits;

    FAPI_INF("%s. Register Output Driver for clock (Y1,Y3): %d",
             mss::c_str(iv_target),
             o_output);

fapi_try_exit:
    return fapi2::current_err;
}

}//spd
}// mss
