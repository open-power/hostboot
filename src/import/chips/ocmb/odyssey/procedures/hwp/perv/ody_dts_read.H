/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/perv/ody_dts_read.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2022                        */
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
// EKB-Mirror-To: hostboot

//------------------------------------------------------------------------------
/// @file  ody_dts_read.H
/// @brief Read the (single) DTS on Odyssey and return a calibrated temp value
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Joachim Fenkes <fenkes@de.ibm.com>
// *HWP FW Maintainer   : Raja Das (rajadas2@in.ibm.com)
//------------------------------------------------------------------------------

#pragma once

#include <fapi2.H>

/// @brief a structure to hold the DTS coefficients P, M and B
struct ody_dts_calib_coeffs
{
    int p, m, b;
};

/// @brief Encode a P/M/B structure into a 64bit fuse value
/// @param[in] i_coeffs The coefficients to encode
/// @return    the encoded fuse value
static inline uint64_t ody_dts_encode_calib_coeffs(
    const ody_dts_calib_coeffs& i_coeffs)
{
    const uint32_t l_shifted = ((i_coeffs.p & 0x3F) << 24) | ((i_coeffs.m & 0x7F) << 16) | (i_coeffs.b & 0x1FF);
    return static_cast<uint64_t>(l_shifted) << 32;
}

/// @brief Decode a fuse value back into P/M/B coefficients
/// @param[in]  i_fulse_value The fuse value to decode
/// @param[out] o_coeffs      A structure to store the decoded coefficients
static inline void ody_dts_decode_calib_coeffs(
    const uint64_t i_fuse_value, ody_dts_calib_coeffs& o_coeffs)
{
    // The P and M coefficients are unsigned, nothing tricky here
    o_coeffs.p = (i_fuse_value >> 56) & 0x3F;
    o_coeffs.m = (i_fuse_value >> 48) & 0x7F;

    // Shift the signed B coefficient to the leftmost end,
    // then convert to signed and arithmetic shift right
    // to properly preserve the signedness.
    o_coeffs.b = static_cast<int64_t>(i_fuse_value << (32 - 9)) >> (64 - 9);
}

/// @brief Given a raw reading and a set of P/M/B coefficients, determine the calibrated temperature
/// @param[in]  i_raw_value  The raw DTS reading value
/// @param[in]  i_coeffs     The calibration coefficients
/// @return     The calibrated temperature value, in 1/16th degrees C
static inline int ody_dts_get_calibrated_temp(
    const uint32_t i_raw_value, const ody_dts_calib_coeffs& i_coeffs)
{
    //                                P*x^2   M*x
    // The basic formula is result =  ----- + --- + B*2^4
    //                                2^18    2^7
    //
    // We pull the division by 2^18 out of the sum for accuracy:
    //   result = (P*x^2 + M*x*2^11 + B*2^22) / 2^18

    const uint32_t p_term = i_raw_value * i_raw_value * i_coeffs.p;
    const uint32_t m_term = i_raw_value * i_coeffs.m;
    const int32_t result_shifted = static_cast<int32_t>(p_term + (m_term << 11))
                                   + (static_cast<int32_t>(i_coeffs.b) << 22);
    return result_shifted >> 18;
}

typedef fapi2::ReturnCode (*ody_dts_read_FP_t)(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&,
    int16_t& o_temperature);

/// @brief Read the (single) DTS on Odyssey and return a calibrated temp value
///
/// @param[in]   i_target        Odyssey chip to read out
/// @param[out]  o_temperature   Calibrated temperature reading
///
/// @return  FAPI2_RC_SUCCESS if success, else error code.
extern "C"
{
    fapi2::ReturnCode ody_dts_read(
        const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        int16_t& o_temperature);
}
