/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/spd/lrdimm/lrdimm_decoder_v1_1.C $ */
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
/// @file lrdimm_decoder_v1_1.C
/// @brief LRDIMM module SPD decoder definitions for revision 1.1
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
#include <lib/spd/lrdimm/lrdimm_decoder.H>
#include <lib/spd/common/spd_decoder.H>
#include <lib/utils/checker.H>
#include <c_str.H>
#include <lib/utils/find.H>

using fapi2::TARGET_TYPE_MCA;
using fapi2::TARGET_TYPE_MCS;
using fapi2::TARGET_TYPE_DIMM;

namespace mss
{
namespace spd
{
namespace lrdimm
{

///
/// @brief Decodes register and data buffer types
/// @param[out] o_output encoding from SPD
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 131 (Bits 7~4)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 3
/// @note Page 4.1.2.12.3 - 63
///
fapi2::ReturnCode decoder_v1_1::register_and_buffer_type(uint8_t& o_output)
{
    // Extracting desired bits
    uint8_t l_field_bits = extract_spd_field< REGISTER_TYPE >(iv_target, iv_spd_data);
    FAPI_INF("Field Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t RESERVED = 2;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits < RESERVED, // extract sanity check
              REGISTER_TYPE.iv_byte,
              l_field_bits,
              "Failed bounds check for Register and Data Buffer Types") );

    // Update output only if check passes
    o_output = l_field_bits;

    FAPI_INF("%s. Register and Data Buffer Types: %d",
             mss::c_str(iv_target),
             o_output);

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Decodes register output drive strength for CKE signal
/// @param[out] o_output encoding from SPD
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 137 (Bits 1~0)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 3
/// @note Page 4.1.2.12.3 - 65
///
fapi2::ReturnCode decoder_v1_1::cke_signal_output_driver(uint8_t& o_output)
{
    // Extracting desired bits
    uint8_t l_field_bits = extract_spd_field< CKE_DRIVE_STRENGTH >(iv_target, iv_spd_data);
    FAPI_INF("Field Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t MAX_VALID_VAL = 3;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits <= MAX_VALID_VAL, // extract sanity check
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
/// @param[out] o_output encoding from SPD
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 137 (Bits 3~2)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 3
/// @note Page 4.1.2.12.3 - 65
///
fapi2::ReturnCode decoder_v1_1::odt_signal_output_driver(uint8_t& o_output)
{
    // Extracting desired bits
    uint8_t l_field_bits = extract_spd_field< ODT_DRIVE_STRENGTH >(iv_target, iv_spd_data);
    FAPI_INF("Field Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t MAX_VALID_VAL = 3;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits <= MAX_VALID_VAL, // extract sanity check
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
/// @brief Decodes register output drive strength for chip select (CS) signal
/// @param[out] o_output encoding from SPD
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 137 (Bits 6~7)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 3
/// @note Page 4.1.2.12.3 - 65
///
fapi2::ReturnCode decoder_v1_1::cs_signal_output_driver(uint8_t& o_output)
{
    // Extracting desired bits
    uint8_t l_field_bits = extract_spd_field< CS_DRIVE_STRENGTH >(iv_target, iv_spd_data);
    FAPI_INF("Field Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t MAX_VALID_VAL = 3;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits <= MAX_VALID_VAL, // extract sanity check
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
/// @note SPD Byte 138 (Bits 1~0)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 3
/// @note Page 4.1.2.12.3 - 66
///
fapi2::ReturnCode decoder_v1_1::b_side_clk_output_driver(uint8_t& o_output)
{
    // Extracting desired bits
    uint8_t l_field_bits = extract_spd_field< B_SIDE_DRIVE_STRENGTH >(iv_target, iv_spd_data);
    FAPI_INF("Field Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t MAX_VALID_VAL = 3;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits <= MAX_VALID_VAL, // extract sanity check
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
/// @note SPD Byte 138 (Bits 3~2)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 3
/// @note Page 4.1.2.12.3 - 66
///
fapi2::ReturnCode decoder_v1_1::a_side_clk_output_driver(uint8_t& o_output)
{
    // Extracting desired bits
    uint8_t l_field_bits = extract_spd_field< A_SIDE_DRIVE_STRENGTH >(iv_target, iv_spd_data);
    FAPI_INF("Field Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t MAX_VALID_VAL = 3;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits <= MAX_VALID_VAL,
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

}// lrdimm
}// spd
}// mss
