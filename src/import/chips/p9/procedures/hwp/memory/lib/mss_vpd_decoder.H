/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/mss_vpd_decoder.H $ */
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
// mss_vpd_decoder.H
#ifndef MSS_VPD_ACCESS_H_
#define MSS_VPD_ACCESS_H_

#include <endian.h>

#include <fapi2.H>

#include <lib/shared/mss_const.H>
#include <lib/mss_utils.H>
#include <lib/mss_attribute_accessors.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/index.H>

namespace mss
{
namespace decoder
{
///
/// @brief Helper function to select a valid MT blob
/// @param[in] i_blobs a std::vector of pointers to VPD blobs for this MCS's MCAs
/// @param[out] o_blob returns a valid blob of data for the MCS for MT decoding
///
inline void select_mt_blob(const std::vector<uint8_t*>& i_blobs, uint8_t** o_blob)
{
    constexpr uint64_t EQUAL_MEM_CONTENTS = 0;

    if( i_blobs.size() != mss::PORTS_PER_MCS )
    {
        // Asserting out instead of collecting FFDC since this is a
        // programming bug that shouldn't occur.
        FAPI_ERR("Invalid blob size received %d, expected: %d",
                 i_blobs.size(), mss::PORTS_PER_MCS);

        fapi2::Assert(false);
    }

    // We are looking for cases where one of the blobs is filled with zeros,
    // in this case we start with blob index 0, usually due to a deconfigured port.
    // We want to select the non-zero blob so that our VPD "header" information is
    // correct for version layout, signature hash, and version data.
    constexpr uint8_t l_zero_array[mss::VPD_KEYWORD_MAX] = {};

    if( memcmp(i_blobs[0], l_zero_array, mss::VPD_KEYWORD_MAX) == EQUAL_MEM_CONTENTS )
    {
        *o_blob = i_blobs[1];
        return;
    }

    // If we are here than there are three possible reasons:
    // 1)
    // i_blobs[0] and i_blobs[1] are equivalent and
    // the array contents of each index are 0, in which will give the VPD contents
    // 0 values...which is OK. Or that the DIMMs are the same (they have the same
    // rank config per port).
    //
    // 2)
    // i_blobs[0] and i_blobs[1] are NOT equivalent but neither has a 0 filled blob
    // and that they have rank config that differs per port.  But to set our version
    // layout, signature hash, or version data correctly, any blob will do since
    // this data doesn't change per port.
    //
    //  For the two cases above we just select to return an arbitrary blob,
    //  in which i_blobs[0] will suffice.
    //
    // 3)
    // i_blob[1] is filled with zeros so we end up selecting i_blob[0] which will
    // be our non-zero filled VPD blob.
    *o_blob = i_blobs[0];
    return;
}
///
/// @brief ATTR_MSS_VPD_MT_0_VERSION_LAYOUT decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blobs a std::vector of pointers to VPD blobs for this MCS's MCAs
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  MT Keyword Layout Version Number.  Increases when attributes are added, removed, or redefined.  Does not reset.
///
inline fapi2::ReturnCode vpd_mt_0_version_layout(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const std::vector<uint8_t*>& i_blobs)
{
    uint8_t l_value = 0;
    constexpr uint64_t l_num_bytes_to_copy = 1;
    constexpr uint64_t l_offset = 0;

    uint8_t* l_blob = nullptr;
    select_mt_blob(i_blobs, &l_blob);
    memcpy(&l_value, l_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_0_VERSION_LAYOUT, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_0_VERSION_LAYOUT start: %d, len: %d for %s", l_offset, l_num_bytes_to_copy,
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_1_VERSION_DATA decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blobs a std::vector of pointers to VPD blobs for this MCS's MCAs
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  MT Keyword Data Version Number.  Increases when data changes with the above layout version.  Resets when layout version number increments.
///
inline fapi2::ReturnCode vpd_mt_1_version_data(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const std::vector<uint8_t*>& i_blobs)
{
    uint8_t l_value = 0;
    constexpr uint64_t l_num_bytes_to_copy = 1;
    constexpr uint64_t l_offset = 1;

    uint8_t* l_blob = nullptr;
    select_mt_blob(i_blobs, &l_blob);
    memcpy(&l_value, l_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_1_VERSION_DATA, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_1_VERSION_DATA start: %d, len: %d for %s", l_offset, l_num_bytes_to_copy,
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_2_SIGNATURE_HASH decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blobs a std::vector of pointers to VPD blobs for this MCS's MCAs
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Hash Signature for the MT Keyword. The hash signature is 32bits for 256 bytes of data.
///
inline fapi2::ReturnCode vpd_mt_2_signature_hash(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const std::vector<uint8_t*>& i_blobs)
{
    uint32_t l_value = 0;
    constexpr uint64_t l_num_bytes_to_copy = 4;
    constexpr uint64_t l_offset = 2;

    uint8_t* l_blob = nullptr;
    select_mt_blob(i_blobs, &l_blob);
    memcpy(&l_value, l_blob + l_offset, l_num_bytes_to_copy);
    l_value = be32toh(l_value);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_2_SIGNATURE_HASH, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_2_SIGNATURE_HASH start: %d, len: %d for %s", l_offset, l_num_bytes_to_copy,
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_DIMM_RCD_IBT_CA decode and set (array)
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blobs a std::vector of pointers to VPD blobs for this MCS's MCAs
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Register Clock Driver, Input Bus Termination for Command/Address in tens of Ohms.
///
inline fapi2::ReturnCode vpd_mt_dimm_rcd_ibt_ca(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const std::vector<uint8_t*>& i_blobs)
{
    if (i_blobs.size() != mss::PORTS_PER_MCS)
    {
        FAPI_ERR("%s found vpd blob vector with incorrect number of elements %d", mss::c_str(i_target), i_blobs.size());
        fapi2::Assert(false);
    }

    uint8_t l_value[2][2] = {};
    constexpr uint64_t l_start = 6;
    constexpr uint64_t l_length = 4;

    constexpr uint64_t l_num_bytes_to_copy = l_length / mss::PORTS_PER_MCS;

    for (const auto& p : mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target))
    {
        const auto l_index = mss::index(p);
        const uint8_t* l_blob = i_blobs[l_index];
        const uint64_t l_offset = l_start + (l_index * l_num_bytes_to_copy);

        memcpy(&(l_value[l_index][0]), l_blob + l_offset, l_num_bytes_to_copy);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_DIMM_RCD_IBT_CA, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_DIMM_RCD_IBT_CA start: %d, len: %d for %s", l_start, l_length,
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_DIMM_RCD_IBT_CKE decode and set (array)
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blobs a std::vector of pointers to VPD blobs for this MCS's MCAs
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Register Clock Driver, Input Bus Termination for Clock Enable in tens of Ohms.
///
inline fapi2::ReturnCode vpd_mt_dimm_rcd_ibt_cke(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const std::vector<uint8_t*>& i_blobs)
{
    if (i_blobs.size() != mss::PORTS_PER_MCS)
    {
        FAPI_ERR("%s found vpd blob vector with incorrect number of elements %d", mss::c_str(i_target), i_blobs.size());
        fapi2::Assert(false);
    }

    uint8_t l_value[2][2] = {};
    constexpr uint64_t l_start = 10;
    constexpr uint64_t l_length = 4;

    constexpr uint64_t l_num_bytes_to_copy = l_length / mss::PORTS_PER_MCS;

    for (const auto& p : mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target))
    {
        const auto l_index = mss::index(p);
        const uint8_t* l_blob = i_blobs[l_index];
        const uint64_t l_offset = l_start + (l_index * l_num_bytes_to_copy);

        memcpy(&(l_value[l_index][0]), l_blob + l_offset, l_num_bytes_to_copy);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_DIMM_RCD_IBT_CKE, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_DIMM_RCD_IBT_CKE start: %d, len: %d for %s", l_start, l_length,
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_DIMM_RCD_IBT_CS decode and set (array)
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blobs a std::vector of pointers to VPD blobs for this MCS's MCAs
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Register Clock Driver, Input Bus Termination for Chip Select in tens of Ohms.
///
inline fapi2::ReturnCode vpd_mt_dimm_rcd_ibt_cs(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const std::vector<uint8_t*>& i_blobs)
{
    if (i_blobs.size() != mss::PORTS_PER_MCS)
    {
        FAPI_ERR("%s found vpd blob vector with incorrect number of elements %d", mss::c_str(i_target), i_blobs.size());
        fapi2::Assert(false);
    }

    uint8_t l_value[2][2] = {};
    constexpr uint64_t l_start = 14;
    constexpr uint64_t l_length = 4;

    constexpr uint64_t l_num_bytes_to_copy = l_length / mss::PORTS_PER_MCS;

    for (const auto& p : mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target))
    {
        const auto l_index = mss::index(p);
        const uint8_t* l_blob = i_blobs[l_index];
        const uint64_t l_offset = l_start + (l_index * l_num_bytes_to_copy);

        memcpy(&(l_value[l_index][0]), l_blob + l_offset, l_num_bytes_to_copy);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_DIMM_RCD_IBT_CS, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_DIMM_RCD_IBT_CS start: %d, len: %d for %s", l_start, l_length,
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_DIMM_RCD_IBT_ODT decode and set (array)
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blobs a std::vector of pointers to VPD blobs for this MCS's MCAs
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Register Clock Driver, Input Bus Termination for On Die Termination in tens of Ohms.
///
inline fapi2::ReturnCode vpd_mt_dimm_rcd_ibt_odt(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const std::vector<uint8_t*>& i_blobs)
{
    if (i_blobs.size() != mss::PORTS_PER_MCS)
    {
        FAPI_ERR("%s found vpd blob vector with incorrect number of elements %d", mss::c_str(i_target), i_blobs.size());
        fapi2::Assert(false);
    }

    uint8_t l_value[2][2] = {};
    constexpr uint64_t l_start = 18;
    constexpr uint64_t l_length = 4;

    constexpr uint64_t l_num_bytes_to_copy = l_length / mss::PORTS_PER_MCS;

    for (const auto& p : mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target))
    {
        const auto l_index = mss::index(p);
        const uint8_t* l_blob = i_blobs[l_index];
        const uint64_t l_offset = l_start + (l_index * l_num_bytes_to_copy);

        memcpy(&(l_value[l_index][0]), l_blob + l_offset, l_num_bytes_to_copy);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_DIMM_RCD_IBT_ODT, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_DIMM_RCD_IBT_ODT start: %d, len: %d for %s", l_start, l_length,
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_DRAM_DRV_IMP_DQ_DQS decode and set (array)
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blobs a std::vector of pointers to VPD blobs for this MCS's MCAs
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  DQ and DQS Drive Impedance for [Port][DIMM][RANK].
///
inline fapi2::ReturnCode vpd_mt_dram_drv_imp_dq_dqs(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const std::vector<uint8_t*>& i_blobs)
{
    if (i_blobs.size() != mss::PORTS_PER_MCS)
    {
        FAPI_ERR("%s found vpd blob vector with incorrect number of elements %d", mss::c_str(i_target), i_blobs.size());
        fapi2::Assert(false);
    }

    uint8_t l_value[2][2][4] = {};
    constexpr uint64_t l_start = 22;
    constexpr uint64_t l_length = 16;

    constexpr uint64_t l_num_bytes_to_copy = l_length / mss::PORTS_PER_MCS;

    for (const auto& p : mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target))
    {
        const auto l_index = mss::index(p);
        const uint8_t* l_blob = i_blobs[l_index];
        const uint64_t l_offset = l_start + (l_index * l_num_bytes_to_copy);

        memcpy(&(l_value[l_index][0][0]), l_blob + l_offset, l_num_bytes_to_copy);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_DRAM_DRV_IMP_DQ_DQS, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_DRAM_DRV_IMP_DQ_DQS start: %d, len: %d for %s", l_start, l_length,
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_DRAM_RTT_NOM decode and set (array)
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blobs a std::vector of pointers to VPD blobs for this MCS's MCAs
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  DRAM side Nominal Termination Resistance in Ohms.
///
inline fapi2::ReturnCode vpd_mt_dram_rtt_nom(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const std::vector<uint8_t*>& i_blobs)
{
    if (i_blobs.size() != mss::PORTS_PER_MCS)
    {
        FAPI_ERR("%s found vpd blob vector with incorrect number of elements %d", mss::c_str(i_target), i_blobs.size());
        fapi2::Assert(false);
    }

    uint8_t l_value[2][2][4] = {};
    constexpr uint64_t l_start = 38;
    constexpr uint64_t l_length = 16;

    constexpr uint64_t l_num_bytes_to_copy = l_length / mss::PORTS_PER_MCS;

    for (const auto& p : mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target))
    {
        const auto l_index = mss::index(p);
        const uint8_t* l_blob = i_blobs[l_index];
        const uint64_t l_offset = l_start + (l_index * l_num_bytes_to_copy);

        memcpy(&(l_value[l_index][0][0]), l_blob + l_offset, l_num_bytes_to_copy);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_DRAM_RTT_NOM, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_DRAM_RTT_NOM start: %d, len: %d for %s", l_start, l_length,
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_DRAM_RTT_PARK decode and set (array)
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blobs a std::vector of pointers to VPD blobs for this MCS's MCAs
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  DRAM side Park Termination Resistance in Ohms.
///
inline fapi2::ReturnCode vpd_mt_dram_rtt_park(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const std::vector<uint8_t*>& i_blobs)
{
    if (i_blobs.size() != mss::PORTS_PER_MCS)
    {
        FAPI_ERR("%s found vpd blob vector with incorrect number of elements %d", mss::c_str(i_target), i_blobs.size());
        fapi2::Assert(false);
    }

    uint8_t l_value[2][2][4] = {};
    constexpr uint64_t l_start = 54;
    constexpr uint64_t l_length = 16;

    constexpr uint64_t l_num_bytes_to_copy = l_length / mss::PORTS_PER_MCS;

    for (const auto& p : mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target))
    {
        const auto l_index = mss::index(p);
        const uint8_t* l_blob = i_blobs[l_index];
        const uint64_t l_offset = l_start + (l_index * l_num_bytes_to_copy);

        memcpy(&(l_value[l_index][0][0]), l_blob + l_offset, l_num_bytes_to_copy);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_DRAM_RTT_PARK, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_DRAM_RTT_PARK start: %d, len: %d for %s", l_start, l_length,
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_DRAM_RTT_WR decode and set (array)
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blobs a std::vector of pointers to VPD blobs for this MCS's MCAs
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  DRAM side Write Termination Resistance in Ohms.
///
inline fapi2::ReturnCode vpd_mt_dram_rtt_wr(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const std::vector<uint8_t*>& i_blobs)
{
    if (i_blobs.size() != mss::PORTS_PER_MCS)
    {
        FAPI_ERR("%s found vpd blob vector with incorrect number of elements %d", mss::c_str(i_target), i_blobs.size());
        fapi2::Assert(false);
    }

    uint8_t l_value[2][2][4] = {};
    constexpr uint64_t l_start = 70;
    constexpr uint64_t l_length = 16;

    constexpr uint64_t l_num_bytes_to_copy = l_length / mss::PORTS_PER_MCS;

    for (const auto& p : mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target))
    {
        const auto l_index = mss::index(p);
        const uint8_t* l_blob = i_blobs[l_index];
        const uint64_t l_offset = l_start + (l_index * l_num_bytes_to_copy);

        memcpy(&(l_value[l_index][0][0]), l_blob + l_offset, l_num_bytes_to_copy);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_DRAM_RTT_WR, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_DRAM_RTT_WR start: %d, len: %d for %s", l_start, l_length,
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_MC_BIAS_TRIM decode and set (array)
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blobs a std::vector of pointers to VPD blobs for this MCS's MCAs
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Adjusts the receiver internal current bias. ONLY set range 0-7. Default value is 3.
/// [VPD Value] = [Binary bit value set in register]
/// 0 = 110 (Minimal power)
/// 1 = 010
/// 2 = 100
/// 3 = 000 (Default)
/// 4 = 111
/// 5 = 011
/// 6 = 101
/// 7 = 001 (Maximum power)
///
inline fapi2::ReturnCode vpd_mt_mc_bias_trim(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const std::vector<uint8_t*>& i_blobs)
{
    if (i_blobs.size() != mss::PORTS_PER_MCS)
    {
        FAPI_ERR("%s found vpd blob vector with incorrect number of elements %d", mss::c_str(i_target), i_blobs.size());
        fapi2::Assert(false);
    }

    uint8_t l_value[2] = {};
    constexpr uint64_t l_max_layout_version = 1;

    uint8_t l_layer_version = 0;
    FAPI_TRY( mss::vpd_mt_0_version_layout(i_target, l_layer_version));

    for (const auto& p : mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target))
    {
        const auto l_index = mss::index(p);
        constexpr uint64_t l_offset = 86;
        constexpr uint64_t l_num_bytes_to_copy = 2;
        constexpr uint64_t l_length = l_num_bytes_to_copy / mss::PORTS_PER_MCS;

        if( l_layer_version == l_max_layout_version)
        {
            const uint8_t* l_blob = i_blobs[l_index];
            const uint64_t l_start = l_offset + (l_index * l_length);
            memcpy(&(l_value[l_index]), l_blob + l_start, l_length);
        }
        else
        {
            // setting this to default value from VPD template
            constexpr uint64_t l_prev_layout_val = 0x03;
            l_value[l_index] = l_prev_layout_val;
        }
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_MC_BIAS_TRIM, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_MC_BIAS_TRIM for %s", mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_MC_DQ_ACBOOST_RD_UP decode and set (array)
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blobs a std::vector of pointers to VPD blobs for this MCS's MCAs
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Selects the number of enabled pullup branches during READ mode. ONLY set range 0-7. Eg. 0x02 = b010 (1 branch selected), 0x06 = b110 (2 branches selected)
/// Bit 0-2   = DP16 Block 0 (DQ Bits 0-7)
/// Bit 3-5   = DP16 Block 0 (DQ Bits 8-15)
/// Bit 6-8   = DP16 Block 1 (DQ Bits 0-7)
/// Bit 9-11  = DP16 Block 1 (DQ Bits 8-15)
/// Bit 12-14 = DP16 Block 2 (DQ Bits 0-7)
/// Bit 15-17 = DP16 Block 2 (DQ Bits 8-15)
/// Bit 18-20 = DP16 Block 3 (DQ Bits 0-7)
/// Bit 21-23 = DP16 Block 3 (DQ Bits 8-15)
/// Bit 24-26 = DP16 Block 4 (DQ Bits 0-7)
/// Bit 27-29 = DP16 Block 4 (DQ Bits 8-15)
///
inline fapi2::ReturnCode vpd_mt_mc_dq_acboost_rd_up(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const std::vector<uint8_t*>& i_blobs)
{
    if (i_blobs.size() != mss::PORTS_PER_MCS)
    {
        FAPI_ERR("%s found vpd blob vector with incorrect number of elements %d", mss::c_str(i_target), i_blobs.size());
        fapi2::Assert(false);
    }

    uint32_t l_value[2] = {};
    uint64_t l_num_bytes_to_copy = 0;
    uint64_t l_offset = 0;

    uint8_t l_layer_version = 0;
    FAPI_TRY( mss::vpd_mt_0_version_layout(i_target, l_layer_version) );

    switch(l_layer_version)
    {
        case 0:
            l_offset = 86;
            l_num_bytes_to_copy = 8;
            break;

        case 1:
            l_offset = 88;
            l_num_bytes_to_copy = 8;
            break;

        default:
            FAPI_ERR("Invalid layer version received: %d for %s", l_layer_version, mss::c_str(i_target));
            fapi2::Assert(false);
            break;

    };

    {
        const uint64_t l_length = l_num_bytes_to_copy / mss::PORTS_PER_MCS;

        for (const auto& p : mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target))
        {
            const auto l_index = mss::index(p);
            const uint8_t* l_blob = i_blobs[l_index];
            const uint64_t l_start = l_offset + (l_index * l_length);
            memcpy(&(l_value[l_index]), l_blob + l_start, l_length);
        }

    }

    for (size_t i = 0; i < 2; ++i)
    {
        l_value[i] = be32toh(l_value[i]);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_MC_DQ_ACBOOST_RD_UP, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_MC_DQ_ACBOOST_RD_UP start: %d, len: %d for %s", l_offset, l_num_bytes_to_copy,
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_MC_DQ_ACBOOST_WR_DOWN decode and set (array)
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blobs a std::vector of pointers to VPD blobs for this MCS's MCAs
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Selects the number of enabled pulldown branches during WRITE mode. ONLY set range 0-7. Eg. 0x02 = b010 (1 branch selected), 0x06 = b110 (2 branches selected)
/// Bit 0-2   = DP16 Block 0 (DQ Bits 0-7)
/// Bit 3-5   = DP16 Block 0 (DQ Bits 8-15)
/// Bit 6-8   = DP16 Block 1 (DQ Bits 0-7)
/// Bit 9-11  = DP16 Block 1 (DQ Bits 8-15)
/// Bit 12-14 = DP16 Block 2 (DQ Bits 0-7)
/// Bit 15-17 = DP16 Block 2 (DQ Bits 8-15)
/// Bit 18-20 = DP16 Block 3 (DQ Bits 0-7)
/// Bit 21-23 = DP16 Block 3 (DQ Bits 8-15)
/// Bit 24-26 = DP16 Block 4 (DQ Bits 0-7)
/// Bit 27-29 = DP16 Block 4 (DQ Bits 8-15)
///
inline fapi2::ReturnCode vpd_mt_mc_dq_acboost_wr_down(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const std::vector<uint8_t*>& i_blobs)
{
    if (i_blobs.size() != mss::PORTS_PER_MCS)
    {
        FAPI_ERR("%s found vpd blob vector with incorrect number of elements %d", mss::c_str(i_target), i_blobs.size());
        fapi2::Assert(false);
    }

    uint32_t l_value[2] = {};
    uint64_t l_num_bytes_to_copy = 0;
    uint64_t l_offset = 0;

    uint8_t l_layer_version = 0;
    FAPI_TRY( mss::vpd_mt_0_version_layout(i_target, l_layer_version) );

    switch(l_layer_version)
    {
        case 0:
            l_offset = 94;
            l_num_bytes_to_copy = 8;
            break;

        case 1:
            l_offset = 96;
            l_num_bytes_to_copy = 8;
            break;

        default:
            FAPI_ERR("Invalid layer version received: %d for %s", l_layer_version, mss::c_str(i_target));
            fapi2::Assert(false);
            break;

    };

    {
        const uint64_t l_length = l_num_bytes_to_copy / mss::PORTS_PER_MCS;

        for (const auto& p : mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target))
        {
            const auto l_index = mss::index(p);
            const uint8_t* l_blob = i_blobs[l_index];
            const uint64_t l_start = l_offset + (l_index * l_length);
            memcpy(&(l_value[l_index]), l_blob + l_start, l_length);
        }

    }

    for (size_t i = 0; i < 2; ++i)
    {
        l_value[i] = be32toh(l_value[i]);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_MC_DQ_ACBOOST_WR_DOWN, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_MC_DQ_ACBOOST_WR_DOWN start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_MC_DQ_ACBOOST_WR_UP decode and set (array)
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blobs a std::vector of pointers to VPD blobs for this MCS's MCAs
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Selects the number of enabled pullup branches during WRITE mode. ONLY set range 0-7. Eg. 0x02 = b010 (1 branch selected), 0x06 = b110 (2 branches selected)
/// Bit 0-2   = DP16 Block 0 (DQ Bits 0-7)
/// Bit 3-5   = DP16 Block 0 (DQ Bits 8-15)
/// Bit 6-8   = DP16 Block 1 (DQ Bits 0-7)
/// Bit 9-11  = DP16 Block 1 (DQ Bits 8-15)
/// Bit 12-14 = DP16 Block 2 (DQ Bits 0-7)
/// Bit 15-17 = DP16 Block 2 (DQ Bits 8-15)
/// Bit 18-20 = DP16 Block 3 (DQ Bits 0-7)
/// Bit 21-23 = DP16 Block 3 (DQ Bits 8-15)
/// Bit 24-26 = DP16 Block 4 (DQ Bits 0-7)
/// Bit 27-29 = DP16 Block 4 (DQ Bits 8-15)
///
inline fapi2::ReturnCode vpd_mt_mc_dq_acboost_wr_up(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const std::vector<uint8_t*>& i_blobs)
{
    if (i_blobs.size() != mss::PORTS_PER_MCS)
    {
        FAPI_ERR("%s found vpd blob vector with incorrect number of elements %d", mss::c_str(i_target), i_blobs.size());
        fapi2::Assert(false);
    }

    uint32_t l_value[2] = {};
    uint64_t l_num_bytes_to_copy = 0;
    uint64_t l_offset = 0;

    uint8_t l_layer_version = 0;
    FAPI_TRY( mss::vpd_mt_0_version_layout(i_target, l_layer_version) );

    switch(l_layer_version)
    {
        case 0:
            l_offset = 102;
            l_num_bytes_to_copy = 8;
            break;

        case 1:
            l_offset = 104;
            l_num_bytes_to_copy = 8;
            break;

        default:
            FAPI_ERR("Invalid layer version received: %d for %s", l_layer_version, mss::c_str(i_target));
            fapi2::Assert(false);
            break;

    };

    {
        const uint64_t l_length = l_num_bytes_to_copy / mss::PORTS_PER_MCS;

        for (const auto& p : mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target))
        {
            const auto l_index = mss::index(p);
            const uint8_t* l_blob = i_blobs[l_index];
            const uint64_t l_start = l_offset + (l_index * l_length);
            memcpy(&(l_value[l_index]), l_blob + l_start, l_length);
        }

    }

    for (size_t i = 0; i < 2; ++i)
    {
        l_value[i] = be32toh(l_value[i]);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_MC_DQ_ACBOOST_WR_UP, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_MC_DQ_ACBOOST_WR_UP start: %d, len: %d for %s", l_offset, l_num_bytes_to_copy,
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_MC_DQ_CTLE_CAP decode and set (array)
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blobs a std::vector of pointers to VPD blobs for this MCS's MCAs
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Sets the capacitance value in the RC source degeneration. ONLY set range 0-3. (b00 = No capacitor selected, b01 = more caps selected, b10 = even more caps selected, b11 = maximum capacitors selected)
/// Bit 0-1   = DP16 Block 0 Nibble 0     Bit 16-17 = DP16 Block 2 Nibble 0     Bit 32-33 = DP16 Block 4 Nibble 0
/// Bit 2-3   = DP16 Block 0 Nibble 1     Bit 18-19 = DP16 Block 2 Nibble 1     Bit 34-35 = DP16 Block 4 Nibble 1
/// Bit 4-5   = DP16 Block 0 Nibble 2     Bit 20-21 = DP16 Block 2 Nibble 2     Bit 36-37 = DP16 Block 4 Nibble 2
/// Bit 6-7   = DP16 Block 0 Nibble 3     Bit 22-23 = DP16 Block 2 Nibble 3     Bit 38-39 = DP16 Block 4 Nibble 3
/// Bit 8-9   = DP16 Block 1 Nibble 0     Bit 24-25 = DP16 Block 3 Nibble 0
/// Bit 10-11 = DP16 Block 1 Nibble 1     Bit 26-27 = DP16 Block 3 Nibble 1
/// Bit 12-13 = DP16 Block 1 Nibble 2     Bit 28-29 = DP16 Block 3 Nibble 2
/// Bit 14-15 = DP16 Block 1 Nibble 3     Bit 30-31 = DP16 Block 3 Nibble 3
///
inline fapi2::ReturnCode vpd_mt_mc_dq_ctle_cap(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const std::vector<uint8_t*>& i_blobs)
{
    if (i_blobs.size() != mss::PORTS_PER_MCS)
    {
        FAPI_ERR("%s found vpd blob vector with incorrect number of elements %d", mss::c_str(i_target), i_blobs.size());
        fapi2::Assert(false);
    }

    uint64_t l_value[2] = {};
    uint64_t l_num_bytes_to_copy = 0;
    uint64_t l_offset = 0;

    uint8_t l_layer_version = 0;
    FAPI_TRY( mss::vpd_mt_0_version_layout(i_target, l_layer_version) );

    switch(l_layer_version)
    {
        case 0:
            l_offset = 110;
            l_num_bytes_to_copy = 16;
            break;

        case 1:
            l_offset = 112;
            l_num_bytes_to_copy = 16;
            break;

        default:
            FAPI_ERR("Invalid layer version received: %d for %s", l_layer_version, mss::c_str(i_target));
            fapi2::Assert(false);
            break;

    };

    {
        const uint64_t l_length = l_num_bytes_to_copy / mss::PORTS_PER_MCS;

        for (const auto& p : mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target))
        {
            const auto l_index = mss::index(p);
            const uint8_t* l_blob = i_blobs[l_index];
            const uint64_t l_start = l_offset + (l_index * l_length);
            memcpy(&(l_value[l_index]), l_blob + l_start, l_length);
        }

    }

    for (size_t i = 0; i < 2; ++i)
    {
        l_value[i] = be64toh(l_value[i]);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_MC_DQ_CTLE_CAP, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_MC_DQ_CTLE_CAP start: %d, len: %d for %s", l_offset, l_num_bytes_to_copy,
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_MC_DQ_CTLE_RES decode and set (array)
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blobs a std::vector of pointers to VPD blobs for this MCS's MCAs
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Sets the resistance value in the RC source degeneration. Also defines the CTLE's DC Gain. ONLY set range 0-7. (b000 = max resistance, b001 to b110 = decreasing resistance, b111 = min resistance)
/// Bit 0-2   = DP16 Block 0 Nibble 0     Bit 24-26 = DP16 Block 2 Nibble 0     Bit 48-50 = DP16 Block 4 Nibble 0
/// Bit 3-5   = DP16 Block 0 Nibble 1     Bit 27-29 = DP16 Block 2 Nibble 1     Bit 51-53 = DP16 Block 4 Nibble 1
/// Bit 6-8   = DP16 Block 0 Nibble 2     Bit 30-32 = DP16 Block 2 Nibble 2     Bit 54-56 = DP16 Block 4 Nibble 2
/// Bit 9-11  = DP16 Block 0 Nibble 3     Bit 33-35 = DP16 Block 2 Nibble 3     Bit 57-59 = DP16 Block 4 Nibble 3
/// Bit 12-14 = DP16 Block 1 Nibble 0     Bit 36-38 = DP16 Block 3 Nibble 0
/// Bit 15-17 = DP16 Block 1 Nibble 1     Bit 39-41 = DP16 Block 3 Nibble 1
/// Bit 18-20 = DP16 Block 1 Nibble 2     Bit 42-44 = DP16 Block 3 Nibble 2
/// Bit 21-23 = DP16 Block 1 Nibble 3     Bit 45-47 = DP16 Block 3 Nibble 3
///
inline fapi2::ReturnCode vpd_mt_mc_dq_ctle_res(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const std::vector<uint8_t*>& i_blobs)
{
    if (i_blobs.size() != mss::PORTS_PER_MCS)
    {
        FAPI_ERR("%s found vpd blob vector with incorrect number of elements %d", mss::c_str(i_target), i_blobs.size());
        fapi2::Assert(false);
    }

    uint64_t l_value[2] = {};
    uint64_t l_num_bytes_to_copy = 0;
    uint64_t l_offset = 0;

    uint8_t l_layer_version = 0;
    FAPI_TRY( mss::vpd_mt_0_version_layout(i_target, l_layer_version) );

    switch(l_layer_version)
    {
        case 0:
            l_offset = 126;
            l_num_bytes_to_copy = 16;
            break;

        case 1:
            l_offset = 128;
            l_num_bytes_to_copy = 16;
            break;

        default:
            FAPI_ERR("Invalid layer version received: %d for %s", l_layer_version, mss::c_str(i_target));
            fapi2::Assert(false);
            break;

    };

    {
        const uint64_t l_length = l_num_bytes_to_copy / mss::PORTS_PER_MCS;

        for (const auto& p : mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target))
        {
            const auto l_index = mss::index(p);
            const uint8_t* l_blob = i_blobs[l_index];
            const uint64_t l_start = l_offset + (l_index * l_length);
            memcpy(&(l_value[l_index]), l_blob + l_start, l_length);
        }

    }

    for (size_t i = 0; i < 2; ++i)
    {
        l_value[i] = be64toh(l_value[i]);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_MC_DQ_CTLE_RES, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_MC_DQ_CTLE_RES start: %d, len: %d for %s", l_offset, l_num_bytes_to_copy,
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_MC_DRV_IMP_CLK decode and set (array)
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blobs a std::vector of pointers to VPD blobs for this MCS's MCAs
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Memory Controller side Drive Impedance for Clock in Ohms.
///
inline fapi2::ReturnCode vpd_mt_mc_drv_imp_clk(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const std::vector<uint8_t*>& i_blobs)
{
    if (i_blobs.size() != mss::PORTS_PER_MCS)
    {
        FAPI_ERR("%s found vpd blob vector with incorrect number of elements %d", mss::c_str(i_target), i_blobs.size());
        fapi2::Assert(false);
    }

    uint8_t l_value[2] = {};
    uint64_t l_num_bytes_to_copy = 0;
    uint64_t l_offset = 0;

    uint8_t l_layer_version = 0;
    FAPI_TRY( mss::vpd_mt_0_version_layout(i_target, l_layer_version) );

    switch(l_layer_version)
    {
        case 0:
            l_offset = 142;
            l_num_bytes_to_copy = 2;
            break;

        case 1:
            l_offset = 144;
            l_num_bytes_to_copy = 2;
            break;

        default:
            FAPI_ERR("Invalid layer version received: %d for %s", l_layer_version, mss::c_str(i_target));
            fapi2::Assert(false);
            break;

    };

    {
        const uint64_t l_length = l_num_bytes_to_copy / mss::PORTS_PER_MCS;

        for (const auto& p : mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target))
        {
            const auto l_index = mss::index(p);
            const uint8_t* l_blob = i_blobs[l_index];
            const uint64_t l_start = l_offset + (l_index * l_length);
            memcpy(&(l_value[l_index]), l_blob + l_start, l_length);
        }

    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_MC_DRV_IMP_CLK, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_MC_DRV_IMP_CLK start: %d, len: %d for %s", l_offset, l_num_bytes_to_copy,
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_MC_DRV_IMP_CMD_ADDR decode and set (array)
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blobs a std::vector of pointers to VPD blobs for this MCS's MCAs
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Memory Controller side Drive Impedance for Address, Bank Address, Bank Group and Activate Lines in Ohms.
///
inline fapi2::ReturnCode vpd_mt_mc_drv_imp_cmd_addr(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const std::vector<uint8_t*>& i_blobs)
{
    if (i_blobs.size() != mss::PORTS_PER_MCS)
    {
        FAPI_ERR("%s found vpd blob vector with incorrect number of elements %d", mss::c_str(i_target), i_blobs.size());
        fapi2::Assert(false);
    }

    uint8_t l_value[2] = {};
    uint64_t l_num_bytes_to_copy = 0;
    uint64_t l_offset = 0;

    uint8_t l_layer_version = 0;
    FAPI_TRY( mss::vpd_mt_0_version_layout(i_target, l_layer_version) );

    switch(l_layer_version)
    {
        case 0:
            l_offset = 144;
            l_num_bytes_to_copy = 2;
            break;

        case 1:
            l_offset = 146;
            l_num_bytes_to_copy = 2;
            break;

        default:
            FAPI_ERR("Invalid layer version received: %d for %s", l_layer_version, mss::c_str(i_target));
            fapi2::Assert(false);
            break;

    };

    {
        const uint64_t l_length = l_num_bytes_to_copy / mss::PORTS_PER_MCS;

        for (const auto& p : mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target))
        {
            const auto l_index = mss::index(p);
            const uint8_t* l_blob = i_blobs[l_index];
            const uint64_t l_start = l_offset + (l_index * l_length);
            memcpy(&(l_value[l_index]), l_blob + l_start, l_length);
        }

    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_MC_DRV_IMP_CMD_ADDR, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_MC_DRV_IMP_CMD_ADDR start: %d, len: %d for %s", l_offset, l_num_bytes_to_copy,
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_MC_DRV_IMP_CNTL decode and set (array)
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blobs a std::vector of pointers to VPD blobs for this MCS's MCAs
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Memory Controller side Drive Impedance for Clock Enable, ODT, Parity, and Reset Lines in Ohms.
///
inline fapi2::ReturnCode vpd_mt_mc_drv_imp_cntl(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const std::vector<uint8_t*>& i_blobs)
{
    if (i_blobs.size() != mss::PORTS_PER_MCS)
    {
        FAPI_ERR("%s found vpd blob vector with incorrect number of elements %d", mss::c_str(i_target), i_blobs.size());
        fapi2::Assert(false);
    }

    uint8_t l_value[2] = {};
    uint64_t l_num_bytes_to_copy = 0;
    uint64_t l_offset = 0;

    uint8_t l_layer_version = 0;
    FAPI_TRY( mss::vpd_mt_0_version_layout(i_target, l_layer_version) );

    switch(l_layer_version)
    {
        case 0:
            l_offset = 146;
            l_num_bytes_to_copy = 2;
            break;

        case 1:
            l_offset = 148;
            l_num_bytes_to_copy = 2;
            break;

        default:
            FAPI_ERR("Invalid layer version received: %d for %s", l_layer_version, mss::c_str(i_target));
            fapi2::Assert(false);
            break;

    };

    {
        const uint64_t l_length = l_num_bytes_to_copy / mss::PORTS_PER_MCS;

        for (const auto& p : mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target))
        {
            const auto l_index = mss::index(p);
            const uint8_t* l_blob = i_blobs[l_index];
            const uint64_t l_start = l_offset + (l_index * l_length);
            memcpy(&(l_value[l_index]), l_blob + l_start, l_length);
        }

    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_MC_DRV_IMP_CNTL, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_MC_DRV_IMP_CNTL start: %d, len: %d for %s", l_offset, l_num_bytes_to_copy,
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_MC_DRV_IMP_CSCID decode and set (array)
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blobs a std::vector of pointers to VPD blobs for this MCS's MCAs
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Memory Controller side Drive Impedance for Chip Select and Chip ID Lines in Ohms.
///
inline fapi2::ReturnCode vpd_mt_mc_drv_imp_cscid(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const std::vector<uint8_t*>& i_blobs)
{
    if (i_blobs.size() != mss::PORTS_PER_MCS)
    {
        FAPI_ERR("%s found vpd blob vector with incorrect number of elements %d", mss::c_str(i_target), i_blobs.size());
        fapi2::Assert(false);
    }

    uint8_t l_value[2] = {};
    uint64_t l_num_bytes_to_copy = 0;
    uint64_t l_offset = 0;

    uint8_t l_layer_version = 0;
    FAPI_TRY( mss::vpd_mt_0_version_layout(i_target, l_layer_version) );

    switch(l_layer_version)
    {
        case 0:
            l_offset = 148;
            l_num_bytes_to_copy = 2;
            break;

        case 1:
            l_offset = 150;
            l_num_bytes_to_copy = 2;
            break;

        default:
            FAPI_ERR("Invalid layer version received: %d for %s", l_layer_version, mss::c_str(i_target));
            fapi2::Assert(false);
            break;

    };

    {
        const uint64_t l_length = l_num_bytes_to_copy / mss::PORTS_PER_MCS;

        for (const auto& p : mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target))
        {
            const auto l_index = mss::index(p);
            const uint8_t* l_blob = i_blobs[l_index];
            const uint64_t l_start = l_offset + (l_index * l_length);
            memcpy(&(l_value[l_index]), l_blob + l_start, l_length);
        }

    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_MC_DRV_IMP_CSCID, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_MC_DRV_IMP_CSCID start: %d, len: %d for %s", l_offset, l_num_bytes_to_copy,
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_MC_DRV_IMP_DQ_DQS decode and set (array)
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blobs a std::vector of pointers to VPD blobs for this MCS's MCAs
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Memory Controller side Drive Impedance for [PORT][DP16] Data and Data Strobe Lines in Ohms.
///
inline fapi2::ReturnCode vpd_mt_mc_drv_imp_dq_dqs(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const std::vector<uint8_t*>& i_blobs)
{
    if (i_blobs.size() != mss::PORTS_PER_MCS)
    {
        FAPI_ERR("%s found vpd blob vector with incorrect number of elements %d", mss::c_str(i_target), i_blobs.size());
        fapi2::Assert(false);
    }

    uint8_t l_value[2][5] = {};
    uint64_t l_num_bytes_to_copy = 0;
    uint64_t l_offset = 0;

    uint8_t l_layer_version = 0;
    FAPI_TRY( mss::vpd_mt_0_version_layout(i_target, l_layer_version) );

    switch(l_layer_version)
    {
        case 0:
            l_offset = 150;
            l_num_bytes_to_copy = 10;
            break;

        case 1:
            l_offset = 152;
            l_num_bytes_to_copy = 10;
            break;

        default:
            FAPI_ERR("Invalid layer version received: %d for %s", l_layer_version, mss::c_str(i_target));
            fapi2::Assert(false);
            break;

    };

    {
        const uint64_t l_length = l_num_bytes_to_copy / mss::PORTS_PER_MCS;

        for (const auto& p : mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target))
        {
            const auto l_index = mss::index(p);
            const uint8_t* l_blob = i_blobs[l_index];
            const uint64_t l_start = l_offset + (l_index * l_length);
            memcpy(&(l_value[l_index][0]), l_blob + l_start, l_length);
        }

    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_MC_DRV_IMP_DQ_DQS, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_MC_DRV_IMP_DQ_DQS start: %d, len: %d for %s", l_offset, l_num_bytes_to_copy,
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_MC_RCV_IMP_DQ_DQS decode and set (array)
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blobs a std::vector of pointers to VPD blobs for this MCS's MCAs
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Memory Controller side Receiver Impedance for [PORT][DP16] Data and Data Strobe Lines in Ohms.
///
inline fapi2::ReturnCode vpd_mt_mc_rcv_imp_dq_dqs(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const std::vector<uint8_t*>& i_blobs)
{
    if (i_blobs.size() != mss::PORTS_PER_MCS)
    {
        FAPI_ERR("%s found vpd blob vector with incorrect number of elements %d", mss::c_str(i_target), i_blobs.size());
        fapi2::Assert(false);
    }

    uint8_t l_value[2][5] = {};
    uint64_t l_num_bytes_to_copy = 0;
    uint64_t l_offset = 0;

    uint8_t l_layer_version = 0;
    FAPI_TRY( mss::vpd_mt_0_version_layout(i_target, l_layer_version) );

    switch(l_layer_version)
    {
        case 0:
            l_offset = 160;
            l_num_bytes_to_copy = 10;
            break;

        case 1:
            l_offset = 162;
            l_num_bytes_to_copy = 10;
            break;

        default:
            FAPI_ERR("Invalid layer version received: %d for %s", l_layer_version, mss::c_str(i_target));
            fapi2::Assert(false);
            break;

    };

    {
        const uint64_t l_length = l_num_bytes_to_copy / mss::PORTS_PER_MCS;

        for (const auto& p : mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target))
        {
            const auto l_index = mss::index(p);
            const uint8_t* l_blob = i_blobs[l_index];
            const uint64_t l_start = l_offset + (l_index * l_length);
            memcpy(&(l_value[l_index][0]), l_blob + l_start, l_length);
        }

    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_MC_RCV_IMP_DQ_DQS, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_MC_RCV_IMP_DQ_DQS start: %d, len: %d for %s", l_offset, l_num_bytes_to_copy,
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_ODT_RD decode and set (array)
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blobs a std::vector of pointers to VPD blobs for this MCS's MCAs
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  READ, On Die Termination triggering bitmap. Use bitmap to determine which ODT to fire for the designated rank.
/// The bits in 8 bit field are [Dimm0 ODT0][Dimm0 ODT1][N/A][N/A][Dimm1 ODT0][Dimm1 ODT1][N/A][N/A]
///
inline fapi2::ReturnCode vpd_mt_odt_rd(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                                       const std::vector<uint8_t*>& i_blobs)
{
    if (i_blobs.size() != mss::PORTS_PER_MCS)
    {
        FAPI_ERR("%s found vpd blob vector with incorrect number of elements %d", mss::c_str(i_target), i_blobs.size());
        fapi2::Assert(false);
    }

    uint8_t l_value[2][2][4] = {};
    uint64_t l_num_bytes_to_copy = 0;
    uint64_t l_offset = 0;

    uint8_t l_layer_version = 0;
    FAPI_TRY( mss::vpd_mt_0_version_layout(i_target, l_layer_version) );

    switch(l_layer_version)
    {
        case 0:
            l_offset = 170;
            l_num_bytes_to_copy = 16;
            break;

        case 1:
            l_offset = 172;
            l_num_bytes_to_copy = 16;
            break;

        default:
            FAPI_ERR("Invalid layer version received: %d for %s", l_layer_version, mss::c_str(i_target));
            fapi2::Assert(false);
            break;

    };

    {
        const uint64_t l_length = l_num_bytes_to_copy / mss::PORTS_PER_MCS;

        for (const auto& p : mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target))
        {
            const auto l_index = mss::index(p);
            const uint8_t* l_blob = i_blobs[l_index];
            const uint64_t l_start = l_offset + (l_index * l_length);
            memcpy(&(l_value[l_index][0][0]), l_blob + l_start, l_length);
        }

    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_ODT_RD, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_ODT_RD start: %d, len: %d for %s", l_offset, l_num_bytes_to_copy,
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_ODT_WR decode and set (array)
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blobs a std::vector of pointers to VPD blobs for this MCS's MCAs
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  WRITE, On Die Termination triggering bitmap. Use bitmap to determine which ODT to fire for the designated rank.
/// The bits in 8 bit field are [Dimm0 ODT0][Dimm0 ODT1][N/A][N/A][Dimm1 ODT0][Dimm1 ODT1][N/A][N/A]
///
inline fapi2::ReturnCode vpd_mt_odt_wr(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                                       const std::vector<uint8_t*>& i_blobs)
{
    if (i_blobs.size() != mss::PORTS_PER_MCS)
    {
        FAPI_ERR("%s found vpd blob vector with incorrect number of elements %d", mss::c_str(i_target), i_blobs.size());
        fapi2::Assert(false);
    }

    uint8_t l_value[2][2][4] = {};
    uint64_t l_num_bytes_to_copy = 0;
    uint64_t l_offset = 0;

    uint8_t l_layer_version = 0;
    FAPI_TRY( mss::vpd_mt_0_version_layout(i_target, l_layer_version) );

    switch(l_layer_version)
    {
        case 0:
            l_offset = 186;
            l_num_bytes_to_copy = 16;
            break;

        case 1:
            l_offset = 188;
            l_num_bytes_to_copy = 16;
            break;

        default:
            FAPI_ERR("Invalid layer version received: %d for %s", l_layer_version, mss::c_str(i_target));
            fapi2::Assert(false);
            break;

    };

    {
        const uint64_t l_length = l_num_bytes_to_copy / mss::PORTS_PER_MCS;

        for (const auto& p : mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target))
        {
            const auto l_index = mss::index(p);
            const uint8_t* l_blob = i_blobs[l_index];
            const uint64_t l_start = l_offset + (l_index * l_length);
            memcpy(&(l_value[l_index][0][0]), l_blob + l_start, l_length);
        }

    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_ODT_WR, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_ODT_WR start: %d, len: %d for %s", l_offset, l_num_bytes_to_copy,
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_PREAMBLE decode and set (array)
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blobs a std::vector of pointers to VPD blobs for this MCS's MCAs
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Number of clocks used for read/write preamble. Calibration only uses 1 nCK preamble (DEFAULT). Mainline has both 1 nCK and 2 nCK preamble option.
/// The value of "0" means 1 nCK preamble, the value of "1" means 2 nCK preamble. Bit 3 for READ preamble, and Bit 7 for WRITE preamble.
/// E.g. 0b00010001 means 2 nCK preamble for both READ and WRITE
///
inline fapi2::ReturnCode vpd_mt_preamble(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const std::vector<uint8_t*>& i_blobs)
{
    if (i_blobs.size() != mss::PORTS_PER_MCS)
    {
        FAPI_ERR("%s found vpd blob vector with incorrect number of elements %d", mss::c_str(i_target), i_blobs.size());
        fapi2::Assert(false);
    }

    uint8_t l_value[2] = {};
    uint64_t l_num_bytes_to_copy = 0;
    uint64_t l_offset = 0;

    uint8_t l_layer_version = 0;
    FAPI_TRY( mss::vpd_mt_0_version_layout(i_target, l_layer_version) );

    switch(l_layer_version)
    {
        case 0:
            l_offset = 202;
            l_num_bytes_to_copy = 2;
            break;

        case 1:
            l_offset = 204;
            l_num_bytes_to_copy = 2;
            break;

        default:
            FAPI_ERR("Invalid layer version received: %d for %s", l_layer_version, mss::c_str(i_target));
            fapi2::Assert(false);
            break;

    };

    {
        const uint64_t l_length = l_num_bytes_to_copy / mss::PORTS_PER_MCS;

        for (const auto& p : mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target))
        {
            const auto l_index = mss::index(p);
            const uint8_t* l_blob = i_blobs[l_index];
            const uint64_t l_start = l_offset + (l_index * l_length);
            memcpy(&(l_value[l_index]), l_blob + l_start, l_length);
        }

    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_PREAMBLE, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_PREAMBLE start: %d, len: %d for %s", l_offset, l_num_bytes_to_copy,
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_VREF_DRAM_WR decode and set (array)
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blobs a std::vector of pointers to VPD blobs for this MCS's MCAs
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  DRAM side Write Vref setting for DDR4. Bit encode is 01234567. Bit 0 is unused. Bit 1 is the Range. Bits 2-7 is the Value. Refer to the VrefDQ Training Table in JEDEC.
///
inline fapi2::ReturnCode vpd_mt_vref_dram_wr(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const std::vector<uint8_t*>& i_blobs)
{
    if (i_blobs.size() != mss::PORTS_PER_MCS)
    {
        FAPI_ERR("%s found vpd blob vector with incorrect number of elements %d", mss::c_str(i_target), i_blobs.size());
        fapi2::Assert(false);
    }

    uint8_t l_value[2] = {};
    uint64_t l_num_bytes_to_copy = 0;
    uint64_t l_offset = 0;

    uint8_t l_layer_version = 0;
    FAPI_TRY( mss::vpd_mt_0_version_layout(i_target, l_layer_version) );

    switch(l_layer_version)
    {
        case 0:
            l_offset = 204;
            l_num_bytes_to_copy = 2;
            break;

        case 1:
            l_offset = 206;
            l_num_bytes_to_copy = 2;
            break;

        default:
            FAPI_ERR("Invalid layer version received: %d for %s", l_layer_version, mss::c_str(i_target));
            fapi2::Assert(false);
            break;

    };

    {
        const uint64_t l_length = l_num_bytes_to_copy / mss::PORTS_PER_MCS;

        for (const auto& p : mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target))
        {
            const auto l_index = mss::index(p);
            const uint8_t* l_blob = i_blobs[l_index];
            const uint64_t l_start = l_offset + (l_index * l_length);
            memcpy(&(l_value[l_index]), l_blob + l_start, l_length);
        }

    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_VREF_DRAM_WR, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_VREF_DRAM_WR start: %d, len: %d for %s", l_offset, l_num_bytes_to_copy,
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_VREF_MC_RD decode and set (array)
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blobs a std::vector of pointers to VPD blobs for this MCS's MCAs
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Memory Controller side Read Vref setting. Dividing by 1000 gives you percentage of Vdd
///
inline fapi2::ReturnCode vpd_mt_vref_mc_rd(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const std::vector<uint8_t*>& i_blobs)
{
    if (i_blobs.size() != mss::PORTS_PER_MCS)
    {
        FAPI_ERR("%s found vpd blob vector with incorrect number of elements %d", mss::c_str(i_target), i_blobs.size());
        fapi2::Assert(false);
    }

    uint32_t l_value[2] = {};
    uint64_t l_num_bytes_to_copy = 0;
    uint64_t l_offset = 0;

    uint8_t l_layer_version = 0;
    FAPI_TRY( mss::vpd_mt_0_version_layout(i_target, l_layer_version) );

    switch(l_layer_version)
    {
        case 0:
            l_offset = 206;
            l_num_bytes_to_copy = 8;
            break;

        case 1:
            l_offset = 208;
            l_num_bytes_to_copy = 8;
            break;

        default:
            FAPI_ERR("Invalid layer version received: %d for %s", l_layer_version, mss::c_str(i_target));
            fapi2::Assert(false);
            break;

    };

    {
        const uint64_t l_length = l_num_bytes_to_copy / mss::PORTS_PER_MCS;

        for (const auto& p : mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target))
        {
            const auto l_index = mss::index(p);
            const uint8_t* l_blob = i_blobs[l_index];
            const uint64_t l_start = l_offset + (l_index * l_length);
            memcpy(&(l_value[l_index]), l_blob + l_start, l_length);
        }

    }

    for (size_t i = 0; i < 2; ++i)
    {
        l_value[i] = be32toh(l_value[i]);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_VREF_MC_RD, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_VREF_MC_RD start: %d, len: %d for %s", l_offset, l_num_bytes_to_copy,
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_WINDAGE_RD_CTR decode and set (array)
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blobs a std::vector of pointers to VPD blobs for this MCS's MCAs
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Derived from calibration/characterization of read centering. Number of windage offset in units of pico-seconds[ps]. Default is 0
/// Specification of the value in this file is 2's compliment hex
///
inline fapi2::ReturnCode vpd_mt_windage_rd_ctr(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const std::vector<uint8_t*>& i_blobs)
{
    if (i_blobs.size() != mss::PORTS_PER_MCS)
    {
        FAPI_ERR("%s found vpd blob vector with incorrect number of elements %d", mss::c_str(i_target), i_blobs.size());
        fapi2::Assert(false);
    }

    int16_t l_value[2] = {};
    uint64_t l_num_bytes_to_copy = 0;
    uint64_t l_offset = 0;

    uint8_t l_layer_version = 0;
    FAPI_TRY( mss::vpd_mt_0_version_layout(i_target, l_layer_version) );

    switch(l_layer_version)
    {
        case 0:
            l_offset = 214;
            l_num_bytes_to_copy = 4;
            break;

        case 1:
            l_offset = 216;
            l_num_bytes_to_copy = 4;
            break;

        default:
            FAPI_ERR("Invalid layer version received: %d for %s", l_layer_version, mss::c_str(i_target));
            fapi2::Assert(false);
            break;

    };

    {
        const uint64_t l_length = l_num_bytes_to_copy / mss::PORTS_PER_MCS;

        for (const auto& p : mss::find_targets<fapi2::TARGET_TYPE_MCA>(i_target))
        {
            const auto l_index = mss::index(p);
            const uint8_t* l_blob = i_blobs[l_index];
            const uint64_t l_start = l_offset + (l_index * l_length);
            memcpy(&(l_value[l_index]), l_blob + l_start, l_length);
        }

    }

    for (size_t i = 0; i < 2; ++i)
    {
        l_value[i] = be16toh(l_value[i]);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_WINDAGE_RD_CTR, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_WINDAGE_RD_CTR start: %d, len: %d for %s", l_offset, l_num_bytes_to_copy,
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_CKE_MAP decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  The Memory Clock Enable MAP is a bit map describing the Memory Clock Enable signal to its respective rank.
/// There are 8 bits, but only 4 are currently used
/// [DIMM0 CKE0][DIMM0 CKE1][N/A][N/A][DIMM1 CKE0][DIMM1 CKE1][N/A][N/A]
/// E.g. 0x80 -> 0b10000000, which means DIMM0 CKE0 is mapped to that rank.
///
inline fapi2::ReturnCode vpd_cke_map(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target, const uint8_t* i_blob)
{
    uint8_t l_value[2][2][4] = {};
    constexpr uint64_t l_num_bytes_to_copy = 16;
    constexpr uint64_t l_offset = 0;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_CKE_MAP, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_CKE_MAP start: %d, len: %d for %s", l_offset, l_num_bytes_to_copy,
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_DQ_MAP decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  [PORT][Dimm DQ PIN]  The map from the Dual Inline Memory Module (DIMM) Data (DQ) Pin to the Module Package Data (DQ) Pinout
///
inline fapi2::ReturnCode vpd_dq_map(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target, const uint8_t* i_blob)
{
    uint8_t l_value[2][72] = {};
    constexpr uint64_t l_num_bytes_to_copy = 144;
    constexpr uint64_t l_offset = 0;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_DQ_MAP, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_DQ_MAP start: %d, len: %d for %s", l_offset, l_num_bytes_to_copy,
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_0_VERSION_LAYOUT decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  MR Keyword Layout Version Number.  Increases when attributes are added, removed, or redefined.  Does not reset.
///
inline fapi2::ReturnCode vpd_mr_0_version_layout(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value = 0;
    constexpr uint64_t l_num_bytes_to_copy = 1;
    constexpr uint64_t l_offset = 0;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_0_VERSION_LAYOUT, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_0_VERSION_LAYOUT start: %d, len: %d for %s", l_offset, l_num_bytes_to_copy,
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_1_VERSION_DATA decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  MR Keyword Data Version Number.  Increases when data changes with the above layout version.  Resets when layout version number increments.
///
inline fapi2::ReturnCode vpd_mr_1_version_data(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value = 0;
    constexpr uint64_t l_num_bytes_to_copy = 1;
    constexpr uint64_t l_offset = 1;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_1_VERSION_DATA, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_1_VERSION_DATA start: %d, len: %d for %s", l_offset, l_num_bytes_to_copy,
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_2_SIGNATURE_HASH decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Hash Signature for the MT Keyword. The hash signature is 32bits for 256 bytes of data.
///
inline fapi2::ReturnCode vpd_mr_2_signature_hash(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint32_t l_value = 0;
    constexpr uint64_t l_num_bytes_to_copy = 4;
    constexpr uint64_t l_offset = 2;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);
    l_value = be32toh(l_value);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_2_SIGNATURE_HASH, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_2_SIGNATURE_HASH start: %d, len: %d for %s", l_offset, l_num_bytes_to_copy,
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_DPHY_GPO decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Global phy offset in number of clocks
///
inline fapi2::ReturnCode vpd_mr_dphy_gpo(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target, const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 6;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_DPHY_GPO, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_DPHY_GPO start: %d, len: %d for %s", l_offset, l_num_bytes_to_copy,
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_DPHY_RLO decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Read latency offset in number of clocks
///
inline fapi2::ReturnCode vpd_mr_dphy_rlo(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target, const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 8;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_DPHY_RLO, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_DPHY_RLO start: %d, len: %d for %s", l_offset, l_num_bytes_to_copy,
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_DPHY_WLO decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Write latency offset in number of clocks
///
inline fapi2::ReturnCode vpd_mr_dphy_wlo(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target, const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 10;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_DPHY_WLO, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_DPHY_WLO start: %d, len: %d for %s", l_offset, l_num_bytes_to_copy,
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_2N_MODE_AUTOSET decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Default value for 2N Mode from Signal Integrity.
/// 0x01 = 1N Mode , 0x02 = 2N Mode
///
inline fapi2::ReturnCode vpd_mr_mc_2n_mode_autoset(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value = 0;
    constexpr uint64_t l_num_bytes_to_copy = 1;
    constexpr uint64_t l_offset = 98;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_2N_MODE_AUTOSET, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_2N_MODE_AUTOSET start: %d, len: %d for %s", l_offset, l_num_bytes_to_copy,
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A00 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of command/address of A## in ticks. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_a00(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 12;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A00, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A00 start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A01 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of command/address of A## in ticks. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_a01(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 14;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A01, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A01 start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A02 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of command/address of A## in ticks. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_a02(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 16;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A02, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A02 start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A03 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of command/address of A## in ticks. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_a03(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 18;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A03, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A03 start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A04 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of command/address of A## in ticks. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_a04(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 20;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A04, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A04 start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A05 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of command/address of A## in ticks. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_a05(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 22;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A05, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A05 start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A06 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of command/address of A## in ticks. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_a06(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 24;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A06, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A06 start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A07 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of command/address of A## in ticks. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_a07(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 26;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A07, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A07 start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A08 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of command/address of A## in ticks. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_a08(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 28;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A08, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A08 start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A09 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of command/address of A## in ticks. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_a09(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 30;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A09, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A09 start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A10 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of command/address of A## in ticks. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_a10(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 32;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A10, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A10 start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A11 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of command/address of A## in ticks. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_a11(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 34;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A11, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A11 start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A12 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of command/address of A## in ticks. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_a12(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 36;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A12, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A12 start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A13 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of command/address of A## in ticks. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_a13(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 38;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A13, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A13 start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A17 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of command/address of A## in ticks. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_a17(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 40;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A17, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A17 start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_BA0 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Bank Address of BA# in ticks. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_ba0(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 42;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_BA0, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_BA0 start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_BA1 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Bank Address of BA# in ticks. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_ba1(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 44;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_BA1, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_BA1 start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_BG0 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Bank Group of BG# in ticks. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_bg0(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 46;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_BG0, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_BG0 start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_BG1 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Bank Group of BA# in ticks. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_bg1(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 48;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_BG1, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_BG1 start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_C0 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Chip ID of C# in ticks. Only used in TSV Dimms. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_c0(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 50;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_C0, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_C0 start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_C1 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Chip ID of C# in ticks. Only used in TSV Dimms. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_c1(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 52;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_C1, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_C1 start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_C2 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Chip ID of C# in ticks. Only used in TSV Dimms. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_addr_c2(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 54;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_C2, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_C2 start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_CMD_ACTN decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Activate for ACTN in ticks. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_cmd_actn(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 64;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CMD_ACTN, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CMD_ACTN start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_CMD_ADDR_CASN_A15 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Column Access Strobe for CASN in ticks. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_cmd_addr_casn_a15(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 66;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CMD_ADDR_CASN_A15, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CMD_ADDR_CASN_A15 start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_CMD_ADDR_RASN_A16 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Row Access Strobe for RASN in ticks. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_cmd_addr_rasn_a16(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 68;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CMD_ADDR_RASN_A16, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CMD_ADDR_RASN_A16 start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_CMD_ADDR_WEN_A14 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Write Enable for WEN in ticks. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_cmd_addr_wen_a14(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 70;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CMD_ADDR_WEN_A14, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CMD_ADDR_WEN_A14 start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_CMD_PAR decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of the Parity Input for PAR in ticks. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_cmd_par(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 72;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CMD_PAR, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CMD_PAR start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_CKE0 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Clock Enable for Dimm#_CKE# in ticks. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_cntl_d0_cke0(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 74;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_CKE0, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_CKE0 start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_CKE1 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Clock Enable for Dimm#_CKE# in ticks. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_cntl_d0_cke1(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 76;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_CKE1, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_CKE1 start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_CSN0 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Chip Select for Dimm#_CSN# in ticks. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_cntl_d0_csn0(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 82;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_CSN0, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_CSN0 start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_CSN1 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Chip Select for Dimm#_CSN# in ticks. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_cntl_d0_csn1(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 84;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_CSN1, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_CSN1 start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_ODT0 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of On Die Termination for Dimm#_ODT# in ticks. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_cntl_d0_odt0(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 90;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_ODT0, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_ODT0 start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_ODT1 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of On Die Termination for Dimm#_ODT# in ticks. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_cntl_d0_odt1(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 92;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_ODT1, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_ODT1 start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_CKE0 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Clock Enable for Dimm#_CKE# in ticks. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_cntl_d1_cke0(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 78;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_CKE0, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_CKE0 start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_CKE1 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Clock Enable for Dimm#_CKE# in ticks. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_cntl_d1_cke1(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 80;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_CKE1, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_CKE1 start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_CSN0 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Chip Select for Dimm#_CSN# in ticks. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_cntl_d1_csn0(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 86;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_CSN0, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_CSN0 start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_CSN1 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Chip Select for Dimm#_CSN# in ticks. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_cntl_d1_csn1(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 88;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_CSN1, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_CSN1 start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_ODT0 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of On Die Termination for Dimm#_ODT# in ticks. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_cntl_d1_odt0(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 94;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_ODT0, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_ODT0 start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_ODT1 decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of On Die Termination for Dimm#_ODT# in ticks. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_cntl_d1_odt1(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 96;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_ODT1, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_ODT1 start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_D0_CLKN decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Clock for Dimm#_CLK# in ticks. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_d0_clkn(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 58;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_D0_CLKN, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_D0_CLKN start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_D0_CLKP decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Clock for Dimm#_CLK# in ticks. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_d0_clkp(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 56;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_D0_CLKP, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_D0_CLKP start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_D1_CLKN decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Clock for Dimm#_CLK# in ticks. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_d1_clkn(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 62;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_D1_CLKN, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_D1_CLKN start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_MC_PHASE_ROT_D1_CLKP decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Phase rotator delay value of Clock for Dimm#_CLK# in ticks. Ticks are 1/128 of one cycle of clock.
///
inline fapi2::ReturnCode vpd_mr_mc_phase_rot_d1_clkp(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const uint8_t* i_blob)
{
    uint8_t l_value[2] = {};
    constexpr uint64_t l_num_bytes_to_copy = 2;
    constexpr uint64_t l_offset = 60;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_D1_CLKP, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_D1_CLKP start: %d, len: %d for %s", l_offset,
              l_num_bytes_to_copy, mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_TSYS_ADR decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  ADR WRClk Phase Rotator Offset Value in ticks. Ticks are 1/128 of one cycle of clock.
/// Phase Rotator Static Offset value used to determine the Phase of the WrClk with respect to SysClk.
/// For zero delay simulations, or simulations where the delay of the SysClk tree and the WrClk tree are equal,
/// Set this field to 60h
///
inline fapi2::ReturnCode vpd_mr_tsys_adr(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target, const uint8_t* i_blob)
{
    uint8_t l_value = 0;
    constexpr uint64_t l_num_bytes_to_copy = 1;
    constexpr uint64_t l_offset = 99;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_TSYS_ADR, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_TSYS_ADR start: %d, len: %d for %s", l_offset, l_num_bytes_to_copy,
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MR_TSYS_DATA decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  DP16 WrClk Phase Rotator Offset Value in ticks. Ticks are 1/128 of one cycle of clock.
/// Phase Rotator Static Offset value used to determine the Phase of the WrClk with respect to SysClk.
/// For zero delay simulations, or simulations where the delay of the SysClk tree and the WrClk tree are equal,
/// Set this field to 60h
///
inline fapi2::ReturnCode vpd_mr_tsys_data(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target, const uint8_t* i_blob)
{
    uint8_t l_value = 0;
    constexpr uint64_t l_num_bytes_to_copy = 1;
    constexpr uint64_t l_offset = 100;

    memcpy(&l_value, i_blob + l_offset, l_num_bytes_to_copy);

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_TSYS_DATA, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_TSYS_DATA start: %d, len: %d for %s", l_offset, l_num_bytes_to_copy,
              mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

}; // close decoder ns

///
/// @brief eff_decode
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_mt_blobs std::vector of pointers to the the MT VPD blobs for this MCS's MCA
/// @param[in] i_mr_blob the MR VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note Decodes the blobs and sets all the attributes.
///
inline fapi2::ReturnCode eff_decode(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                                    const std::vector<uint8_t*>& i_mt_blob,
                                    const uint8_t* i_mr_blob,
                                    const uint8_t* i_cke_blob,
                                    const uint8_t* i_dq_blob)
{
    FAPI_TRY (decoder::vpd_mt_0_version_layout(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_1_version_data(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_2_signature_hash(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_dimm_rcd_ibt_ca(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_dimm_rcd_ibt_cke(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_dimm_rcd_ibt_cs(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_dimm_rcd_ibt_odt(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_dram_drv_imp_dq_dqs(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_dram_rtt_nom(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_dram_rtt_park(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_dram_rtt_wr(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_mc_bias_trim(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_mc_dq_acboost_rd_up(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_mc_dq_acboost_wr_down(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_mc_dq_acboost_wr_up(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_mc_dq_ctle_cap(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_mc_dq_ctle_res(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_mc_drv_imp_clk(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_mc_drv_imp_cmd_addr(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_mc_drv_imp_cntl(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_mc_drv_imp_cscid(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_mc_drv_imp_dq_dqs(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_mc_rcv_imp_dq_dqs(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_odt_rd(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_odt_wr(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_preamble(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_vref_dram_wr(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_vref_mc_rd(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_mt_windage_rd_ctr(i_target, i_mt_blob) );
    FAPI_TRY (decoder::vpd_cke_map(i_target, i_cke_blob) );
    FAPI_TRY (decoder::vpd_dq_map(i_target, i_dq_blob) );
    FAPI_TRY (decoder::vpd_mr_0_version_layout(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_1_version_data(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_2_signature_hash(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_dphy_gpo(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_dphy_rlo(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_dphy_wlo(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_2n_mode_autoset(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_a00(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_a01(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_a02(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_a03(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_a04(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_a05(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_a06(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_a07(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_a08(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_a09(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_a10(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_a11(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_a12(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_a13(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_a17(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_ba0(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_ba1(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_bg0(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_bg1(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_c0(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_c1(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_addr_c2(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cmd_actn(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cmd_addr_casn_a15(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cmd_addr_rasn_a16(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cmd_addr_wen_a14(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cmd_par(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cntl_d0_cke0(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cntl_d0_cke1(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cntl_d0_csn0(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cntl_d0_csn1(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cntl_d0_odt0(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cntl_d0_odt1(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cntl_d1_cke0(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cntl_d1_cke1(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cntl_d1_csn0(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cntl_d1_csn1(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cntl_d1_odt0(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cntl_d1_odt1(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_d0_clkn(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_d0_clkp(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_d1_clkn(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_d1_clkp(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_tsys_adr(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_tsys_data(i_target, i_mr_blob) );

fapi_try_exit:
    return fapi2::current_err;
}


} // close ns mss
#endif