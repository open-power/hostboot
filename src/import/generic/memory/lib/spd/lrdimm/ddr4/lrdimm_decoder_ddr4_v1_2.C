/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/lrdimm/ddr4/lrdimm_decoder_ddr4_v1_2.C $ */
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
/// @file lrdimm_decoder_v1_2.C
/// @brief LRDIMM module SPD decoder definitions for revision 1.2
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
namespace ddr4
{
namespace lrdimm
{

///
/// @brief Decodes register output drive strength for data buffer control (BCOM, BODT, BKCE)
/// @param[out] o_output encoded drive strength
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 138 (Bit 4)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 4
/// @note Page 4.1.2.12.3 - 76
///
fapi2::ReturnCode decoder_v1_2::bcom_bcke_bodt_drive_strength(uint8_t& o_output) const
{
    // Extracting desired bits
    uint8_t l_field_bits = extract_spd_field< BCOM_BODT_BCKE_DRIVE_STRENGTH >(iv_target, iv_spd_data);
    FAPI_INF("Field Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t MAX_VALID_VAL = 1;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits <= MAX_VALID_VAL,
              BCOM_BODT_BCKE_DRIVE_STRENGTH.iv_byte,
              l_field_bits,
              "Failed bounds check for Register Output Driver for data buffer control (BCOM, BODT, BCKE)") );

    // Update output only if check passes
    o_output = l_field_bits;

    FAPI_INF("%s. Register Output Driver for data buffer control (BCOM, BODT, BCKE): %d",
             mss::c_str(iv_target),
             o_output);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes register output drive strength for data buffer control (BCK)
/// @param[out] o_output encoded drive strength
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 138 (Bit 5)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 4
/// @note Page 4.1.2.12.3 - 76
///
fapi2::ReturnCode decoder_v1_2::bck_output_drive_strength(uint8_t& o_output) const
{
    // Extracting desired bits
    uint8_t l_field_bits = extract_spd_field< BCK_DRIVE_STRENGTH >(iv_target, iv_spd_data);
    FAPI_INF("Field Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t MAX_VALID_VAL = 1;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits <= MAX_VALID_VAL,
              BCK_DRIVE_STRENGTH.iv_byte,
              l_field_bits,
              "Failed bounds check for Register Output Driver for data buffer control (BCK)") );

    // Update output only if check passes
    o_output = l_field_bits;

    FAPI_INF("%s. Register Output Driver for data buffer control (BCK): %d",
             mss::c_str(iv_target),
             o_output);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes RCD output slew rate control
/// @param[out] o_output encoded drive strength
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 138 (Bit 6)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 4
/// @note Page 4.1.2.L-4 - 76
///
fapi2::ReturnCode decoder_v1_2::slew_rate_control(uint8_t& o_output) const
{
    // Extracting desired bits
    uint8_t l_field_bits = extract_spd_field< RCD_SLEW_CNTRL >(iv_target, iv_spd_data);
    FAPI_INF("Field Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t MAX_VALID_VAL = 0b1;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits <= MAX_VALID_VAL, // extract sanity check
              RCD_SLEW_CNTRL.iv_byte,
              l_field_bits,
              "Failed bound check for RCD output slew rate control") );

    // Update output only if check passes
    o_output = l_field_bits;

    FAPI_INF("%s. RCD output slew rate control: %d",
             mss::c_str(iv_target),
             o_output);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes VrefDQ range for DRAM interface range
/// @param[out] o_output spd encoding
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 155 (Bits 3~0)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 4
/// @note Page 4.1.2.L-4 - 76
///
fapi2::ReturnCode decoder_v1_2::dram_vref_dq_range(uint8_t& o_output) const
{
    // Extracting desired bits
    uint8_t l_field_bits = extract_spd_field< DRAM_VREF_DQ_RANGE >(iv_target, iv_spd_data);
    FAPI_INF("Field Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t MAX_VALID_VAL = 0b1111;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits <= MAX_VALID_VAL, // extract sanity check
              DRAM_VREF_DQ_RANGE.iv_byte,
              l_field_bits,
              "Failed bound check for VrefDQ range for DRAM interface range ") );

    // Update output only if check passes
    o_output = l_field_bits;

    FAPI_INF("%s. VrefDQ range for DRAM interface range: %d",
             mss::c_str(iv_target),
             o_output);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes data buffer VrefDQ range for DRAM interface range
/// @param[out] o_output spd encoding
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 155 (Bit 4)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 4
/// @note Page 4.1.2.L-4 - 76
///
fapi2::ReturnCode decoder_v1_2::data_buffer_vref_dq_range(uint8_t& o_output) const
{
    // Extracting desired bits
    uint8_t l_field_bits = extract_spd_field< DATA_BUFFER_VREF_DQ >(iv_target, iv_spd_data);
    FAPI_INF("Field Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t MAX_VALID_VAL = 1;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits <= MAX_VALID_VAL, // extract sanity check
              DATA_BUFFER_VREF_DQ.iv_byte,
              l_field_bits,
              "Failed bound check for data buffer VrefDQ range for DRAM interface range") );

    // Update output only if check passes
    o_output = l_field_bits;

    FAPI_INF("%s. Data buffer VrefDQ range for DRAM interface range: %d",
             mss::c_str(iv_target),
             o_output);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes data buffer gain adjustment
/// @param[out] o_output spd encoding
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 156 (Bit 0)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 4
/// @note Page 4.1.2.L-4 - 77
///
fapi2::ReturnCode decoder_v1_2::data_buffer_gain_adjustment(uint8_t& o_output) const
{
    // Extracting desired bits
    uint8_t l_field_bits = extract_spd_field< DATA_BUFFER_GAIN_ADJUST >(iv_target, iv_spd_data);
    FAPI_INF("Field Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t MAX_VALID_VAL = 1;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits <= MAX_VALID_VAL, // extract sanity check
              DATA_BUFFER_GAIN_ADJUST.iv_byte,
              l_field_bits,
              "Failed bound check for data buffer gain adjustment") );

    // Update output only if check passes
    o_output = l_field_bits;

    FAPI_INF("%s. Data buffer gain adjustment: %d",
             mss::c_str(iv_target),
             o_output);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Decodes data buffer Decision Feedback Equalization (DFE)
/// @param[out] o_output spd encoding
/// @return FAPI2_RC_SUCCESS if okay
/// @note SPD Byte 156 (Bit 1)
/// @note Item JEDEC Standard No. 21-C
/// @note DDR4 SPD Document Release 4
/// @note Page 4.1.2.L-4 - 77
///
fapi2::ReturnCode decoder_v1_2::data_buffer_dfe(uint8_t& o_output) const
{
    // Extracting desired bits
    uint8_t l_field_bits = extract_spd_field< DATA_BUFFER_DFE >(iv_target, iv_spd_data);
    FAPI_INF("Field Bits value: %d", l_field_bits);

    // This checks my extracting params returns a value within bound
    constexpr size_t MAX_VALID_VAL = 1;

    FAPI_TRY( mss::check::spd::fail_for_invalid_value(iv_target,
              l_field_bits <= MAX_VALID_VAL, // extract sanity check
              DATA_BUFFER_DFE.iv_byte,
              l_field_bits,
              "Failed bound check for data buffer Decision Feedback Equalization (DFE)") );

    // Update output only if check passes
    o_output = l_field_bits;

    FAPI_INF("%s. Data buffer Decision Feedback Equalization (DFE): %d",
             mss::c_str(iv_target),
             o_output);

fapi_try_exit:
    return fapi2::current_err;
}

}// lrdimm
}// ddr4
}// spd
}// mss
