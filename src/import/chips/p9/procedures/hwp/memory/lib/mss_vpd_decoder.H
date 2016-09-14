/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/mss_vpd_decoder.H $ */
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
// mss_vpd_decoder.H
#ifndef MSS_VPD_ACCESS_H_
#define MSS_VPD_ACCESS_H_

#include <endian.h>

#include <fapi2.H>

#include <mss.H>
#include <lib/shared/mss_const.H>
#include <lib/mss_utils.H>

namespace mss
{
namespace decoder
{

// VPD Keyword Version Byte: 00
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
    uint8_t l_value;

    memcpy(&l_value, i_blobs[0] + 0, 1);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_0_VERSION_LAYOUT, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_0_VERSION_LAYOUT start: 0, len: 1");

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
    uint8_t l_value;

    memcpy(&l_value, i_blobs[0] + 1, 1);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_1_VERSION_DATA, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_1_VERSION_DATA start: 1, len: 1");

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
    uint32_t l_value;

    memcpy(&l_value, i_blobs[0] + 2, 4);
    l_value = be32toh(l_value);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_2_SIGNATURE_HASH, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_2_SIGNATURE_HASH start: 2, len: 4");

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

    uint8_t l_value[2][2];
    constexpr uint64_t l_length = 4 / mss::PORTS_PER_MCS;

    for (size_t l_index = 0; l_index < mss::PORTS_PER_MCS; ++l_index)
    {
        const uint8_t* l_blob = i_blobs[l_index];
        const uint64_t l_start = 6 + (l_index * l_length);
        memcpy(&(l_value[l_index][0]), l_blob + l_start, l_length);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_DIMM_RCD_IBT_CA, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_DIMM_RCD_IBT_CA start: 6, len: 4");

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

    uint8_t l_value[2][2];
    constexpr uint64_t l_length = 4 / mss::PORTS_PER_MCS;

    for (size_t l_index = 0; l_index < mss::PORTS_PER_MCS; ++l_index)
    {
        const uint8_t* l_blob = i_blobs[l_index];
        const uint64_t l_start = 10 + (l_index * l_length);
        memcpy(&(l_value[l_index][0]), l_blob + l_start, l_length);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_DIMM_RCD_IBT_CKE, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_DIMM_RCD_IBT_CKE start: 10, len: 4");

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

    uint8_t l_value[2][2];
    constexpr uint64_t l_length = 4 / mss::PORTS_PER_MCS;

    for (size_t l_index = 0; l_index < mss::PORTS_PER_MCS; ++l_index)
    {
        const uint8_t* l_blob = i_blobs[l_index];
        const uint64_t l_start = 14 + (l_index * l_length);
        memcpy(&(l_value[l_index][0]), l_blob + l_start, l_length);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_DIMM_RCD_IBT_CS, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_DIMM_RCD_IBT_CS start: 14, len: 4");

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

    uint8_t l_value[2][2];
    constexpr uint64_t l_length = 4 / mss::PORTS_PER_MCS;

    for (size_t l_index = 0; l_index < mss::PORTS_PER_MCS; ++l_index)
    {
        const uint8_t* l_blob = i_blobs[l_index];
        const uint64_t l_start = 18 + (l_index * l_length);
        memcpy(&(l_value[l_index][0]), l_blob + l_start, l_length);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_DIMM_RCD_IBT_ODT, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_DIMM_RCD_IBT_ODT start: 18, len: 4");

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

    uint8_t l_value[2][2][4];
    constexpr uint64_t l_length = 16 / mss::PORTS_PER_MCS;

    for (size_t l_index = 0; l_index < mss::PORTS_PER_MCS; ++l_index)
    {
        const uint8_t* l_blob = i_blobs[l_index];
        const uint64_t l_start = 22 + (l_index * l_length);
        memcpy(&(l_value[l_index][0][0]), l_blob + l_start, l_length);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_DRAM_DRV_IMP_DQ_DQS, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_DRAM_DRV_IMP_DQ_DQS start: 22, len: 16");

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

    uint8_t l_value[2][2][4];
    constexpr uint64_t l_length = 16 / mss::PORTS_PER_MCS;

    for (size_t l_index = 0; l_index < mss::PORTS_PER_MCS; ++l_index)
    {
        const uint8_t* l_blob = i_blobs[l_index];
        const uint64_t l_start = 38 + (l_index * l_length);
        memcpy(&(l_value[l_index][0][0]), l_blob + l_start, l_length);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_DRAM_RTT_NOM, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_DRAM_RTT_NOM start: 38, len: 16");

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

    uint8_t l_value[2][2][4];
    constexpr uint64_t l_length = 16 / mss::PORTS_PER_MCS;

    for (size_t l_index = 0; l_index < mss::PORTS_PER_MCS; ++l_index)
    {
        const uint8_t* l_blob = i_blobs[l_index];
        const uint64_t l_start = 54 + (l_index * l_length);
        memcpy(&(l_value[l_index][0][0]), l_blob + l_start, l_length);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_DRAM_RTT_PARK, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_DRAM_RTT_PARK start: 54, len: 16");

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

    uint8_t l_value[2][2][4];
    constexpr uint64_t l_length = 16 / mss::PORTS_PER_MCS;

    for (size_t l_index = 0; l_index < mss::PORTS_PER_MCS; ++l_index)
    {
        const uint8_t* l_blob = i_blobs[l_index];
        const uint64_t l_start = 70 + (l_index * l_length);
        memcpy(&(l_value[l_index][0][0]), l_blob + l_start, l_length);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_DRAM_RTT_WR, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_DRAM_RTT_WR start: 70, len: 16");

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

    uint32_t l_value[2];
    constexpr uint64_t l_length = 8 / mss::PORTS_PER_MCS;

    for (size_t l_index = 0; l_index < mss::PORTS_PER_MCS; ++l_index)
    {
        const uint8_t* l_blob = i_blobs[l_index];
        const uint64_t l_start = 86 + (l_index * l_length);
        memcpy(&(l_value[l_index]), l_blob + l_start, l_length);
    }

    for (size_t i = 0; i < 2; ++i)
    {
        l_value[i] = be32toh(l_value[i]);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_MC_DQ_ACBOOST_RD_UP, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_MC_DQ_ACBOOST_RD_UP start: 86, len: 8");

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

    uint32_t l_value[2];
    constexpr uint64_t l_length = 8 / mss::PORTS_PER_MCS;

    for (size_t l_index = 0; l_index < mss::PORTS_PER_MCS; ++l_index)
    {
        const uint8_t* l_blob = i_blobs[l_index];
        const uint64_t l_start = 94 + (l_index * l_length);
        memcpy(&(l_value[l_index]), l_blob + l_start, l_length);
    }

    for (size_t i = 0; i < 2; ++i)
    {
        l_value[i] = be32toh(l_value[i]);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_MC_DQ_ACBOOST_WR_DOWN, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_MC_DQ_ACBOOST_WR_DOWN start: 94, len: 8");

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

    uint32_t l_value[2];
    constexpr uint64_t l_length = 8 / mss::PORTS_PER_MCS;

    for (size_t l_index = 0; l_index < mss::PORTS_PER_MCS; ++l_index)
    {
        const uint8_t* l_blob = i_blobs[l_index];
        const uint64_t l_start = 102 + (l_index * l_length);
        memcpy(&(l_value[l_index]), l_blob + l_start, l_length);
    }

    for (size_t i = 0; i < 2; ++i)
    {
        l_value[i] = be32toh(l_value[i]);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_MC_DQ_ACBOOST_WR_UP, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_MC_DQ_ACBOOST_WR_UP start: 102, len: 8");

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

    uint64_t l_value[2];
    constexpr uint64_t l_length = 16 / mss::PORTS_PER_MCS;

    for (size_t l_index = 0; l_index < mss::PORTS_PER_MCS; ++l_index)
    {
        const uint8_t* l_blob = i_blobs[l_index];
        const uint64_t l_start = 110 + (l_index * l_length);
        memcpy(&(l_value[l_index]), l_blob + l_start, l_length);
    }

    for (size_t i = 0; i < 2; ++i)
    {
        l_value[i] = be64toh(l_value[i]);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_MC_DQ_CTLE_CAP, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_MC_DQ_CTLE_CAP start: 110, len: 16");

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

    uint64_t l_value[2];
    constexpr uint64_t l_length = 16 / mss::PORTS_PER_MCS;

    for (size_t l_index = 0; l_index < mss::PORTS_PER_MCS; ++l_index)
    {
        const uint8_t* l_blob = i_blobs[l_index];
        const uint64_t l_start = 126 + (l_index * l_length);
        memcpy(&(l_value[l_index]), l_blob + l_start, l_length);
    }

    for (size_t i = 0; i < 2; ++i)
    {
        l_value[i] = be64toh(l_value[i]);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_MC_DQ_CTLE_RES, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_MC_DQ_CTLE_RES start: 126, len: 16");

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

    uint8_t l_value[2];
    constexpr uint64_t l_length = 2 / mss::PORTS_PER_MCS;

    for (size_t l_index = 0; l_index < mss::PORTS_PER_MCS; ++l_index)
    {
        const uint8_t* l_blob = i_blobs[l_index];
        const uint64_t l_start = 142 + (l_index * l_length);
        memcpy(&(l_value[l_index]), l_blob + l_start, l_length);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_MC_DRV_IMP_CLK, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_MC_DRV_IMP_CLK start: 142, len: 2");

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

    uint8_t l_value[2];
    constexpr uint64_t l_length = 2 / mss::PORTS_PER_MCS;

    for (size_t l_index = 0; l_index < mss::PORTS_PER_MCS; ++l_index)
    {
        const uint8_t* l_blob = i_blobs[l_index];
        const uint64_t l_start = 144 + (l_index * l_length);
        memcpy(&(l_value[l_index]), l_blob + l_start, l_length);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_MC_DRV_IMP_CMD_ADDR, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_MC_DRV_IMP_CMD_ADDR start: 144, len: 2");

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

    uint8_t l_value[2];
    constexpr uint64_t l_length = 2 / mss::PORTS_PER_MCS;

    for (size_t l_index = 0; l_index < mss::PORTS_PER_MCS; ++l_index)
    {
        const uint8_t* l_blob = i_blobs[l_index];
        const uint64_t l_start = 146 + (l_index * l_length);
        memcpy(&(l_value[l_index]), l_blob + l_start, l_length);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_MC_DRV_IMP_CNTL, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_MC_DRV_IMP_CNTL start: 146, len: 2");

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

    uint8_t l_value[2];
    constexpr uint64_t l_length = 2 / mss::PORTS_PER_MCS;

    for (size_t l_index = 0; l_index < mss::PORTS_PER_MCS; ++l_index)
    {
        const uint8_t* l_blob = i_blobs[l_index];
        const uint64_t l_start = 148 + (l_index * l_length);
        memcpy(&(l_value[l_index]), l_blob + l_start, l_length);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_MC_DRV_IMP_CSCID, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_MC_DRV_IMP_CSCID start: 148, len: 2");

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

    uint8_t l_value[2][5];
    constexpr uint64_t l_length = 10 / mss::PORTS_PER_MCS;

    for (size_t l_index = 0; l_index < mss::PORTS_PER_MCS; ++l_index)
    {
        const uint8_t* l_blob = i_blobs[l_index];
        const uint64_t l_start = 150 + (l_index * l_length);
        memcpy(&(l_value[l_index][0]), l_blob + l_start, l_length);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_MC_DRV_IMP_DQ_DQS, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_MC_DRV_IMP_DQ_DQS start: 150, len: 10");

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

    uint8_t l_value[2][5];
    constexpr uint64_t l_length = 10 / mss::PORTS_PER_MCS;

    for (size_t l_index = 0; l_index < mss::PORTS_PER_MCS; ++l_index)
    {
        const uint8_t* l_blob = i_blobs[l_index];
        const uint64_t l_start = 160 + (l_index * l_length);
        memcpy(&(l_value[l_index][0]), l_blob + l_start, l_length);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_MC_RCV_IMP_DQ_DQS, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_MC_RCV_IMP_DQ_DQS start: 160, len: 10");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_ODT_RD decode and set (array)
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blobs a std::vector of pointers to VPD blobs for this MCS's MCAs
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  READ, On Die Termination triggering bitmap.
///
inline fapi2::ReturnCode vpd_mt_odt_rd(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                                       const std::vector<uint8_t*>& i_blobs)
{
    if (i_blobs.size() != mss::PORTS_PER_MCS)
    {
        FAPI_ERR("%s found vpd blob vector with incorrect number of elements %d", mss::c_str(i_target), i_blobs.size());
        fapi2::Assert(false);
    }

    uint8_t l_value[2][2][4];
    constexpr uint64_t l_length = 16 / mss::PORTS_PER_MCS;

    for (size_t l_index = 0; l_index < mss::PORTS_PER_MCS; ++l_index)
    {
        const uint8_t* l_blob = i_blobs[l_index];
        const uint64_t l_start = 170 + (l_index * l_length);
        memcpy(&(l_value[l_index][0][0]), l_blob + l_start, l_length);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_ODT_RD, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_ODT_RD start: 170, len: 16");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_ODT_WR decode and set (array)
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blobs a std::vector of pointers to VPD blobs for this MCS's MCAs
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  WRITE, On Die Termination triggering bitmap.
///
inline fapi2::ReturnCode vpd_mt_odt_wr(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                                       const std::vector<uint8_t*>& i_blobs)
{
    if (i_blobs.size() != mss::PORTS_PER_MCS)
    {
        FAPI_ERR("%s found vpd blob vector with incorrect number of elements %d", mss::c_str(i_target), i_blobs.size());
        fapi2::Assert(false);
    }

    uint8_t l_value[2][2][4];
    constexpr uint64_t l_length = 16 / mss::PORTS_PER_MCS;

    for (size_t l_index = 0; l_index < mss::PORTS_PER_MCS; ++l_index)
    {
        const uint8_t* l_blob = i_blobs[l_index];
        const uint64_t l_start = 186 + (l_index * l_length);
        memcpy(&(l_value[l_index][0][0]), l_blob + l_start, l_length);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_ODT_WR, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_ODT_WR start: 186, len: 16");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_PREAMBLE decode and set (array)
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blobs a std::vector of pointers to VPD blobs for this MCS's MCAs
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Number of clocks used for read/write preamble. Calibration only uses 1 nCK preamble (DEFAULT). Mainline has both 1 nCK and 2 nCK preamble option.
/// "0" means 1 nCK preamble, "1" means 2 nCK preamble. Bit 3 for READ preamble, and Bit 7 for WRITE preamble. E.g. 0b 00010001
///
inline fapi2::ReturnCode vpd_mt_preamble(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const std::vector<uint8_t*>& i_blobs)
{
    if (i_blobs.size() != mss::PORTS_PER_MCS)
    {
        FAPI_ERR("%s found vpd blob vector with incorrect number of elements %d", mss::c_str(i_target), i_blobs.size());
        fapi2::Assert(false);
    }

    uint8_t l_value[2];
    constexpr uint64_t l_length = 2 / mss::PORTS_PER_MCS;

    for (size_t l_index = 0; l_index < mss::PORTS_PER_MCS; ++l_index)
    {
        const uint8_t* l_blob = i_blobs[l_index];
        const uint64_t l_start = 202 + (l_index * l_length);
        memcpy(&(l_value[l_index]), l_blob + l_start, l_length);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_PREAMBLE, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_PREAMBLE start: 202, len: 2");

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

    uint8_t l_value[2];
    constexpr uint64_t l_length = 2 / mss::PORTS_PER_MCS;

    for (size_t l_index = 0; l_index < mss::PORTS_PER_MCS; ++l_index)
    {
        const uint8_t* l_blob = i_blobs[l_index];
        const uint64_t l_start = 204 + (l_index * l_length);
        memcpy(&(l_value[l_index]), l_blob + l_start, l_length);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_VREF_DRAM_WR, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_VREF_DRAM_WR start: 204, len: 2");

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

    uint32_t l_value[2];
    constexpr uint64_t l_length = 8 / mss::PORTS_PER_MCS;

    for (size_t l_index = 0; l_index < mss::PORTS_PER_MCS; ++l_index)
    {
        const uint8_t* l_blob = i_blobs[l_index];
        const uint64_t l_start = 206 + (l_index * l_length);
        memcpy(&(l_value[l_index]), l_blob + l_start, l_length);
    }

    for (size_t i = 0; i < 2; ++i)
    {
        l_value[i] = be32toh(l_value[i]);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_VREF_MC_RD, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_VREF_MC_RD start: 206, len: 8");

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief ATTR_MSS_VPD_MT_WINDAGE_RD_CTR decode and set (array)
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blobs a std::vector of pointers to VPD blobs for this MCS's MCAs
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  Derived from calibration/characterization of read centering. Number of windage offset in units of pico-seconds[ps]. If this is enabled, disable periodic rd_ctr in draminit_mc. Default is 0
///
inline fapi2::ReturnCode vpd_mt_windage_rd_ctr(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
        const std::vector<uint8_t*>& i_blobs)
{
    if (i_blobs.size() != mss::PORTS_PER_MCS)
    {
        FAPI_ERR("%s found vpd blob vector with incorrect number of elements %d", mss::c_str(i_target), i_blobs.size());
        fapi2::Assert(false);
    }

    int16_t l_value[2];
    constexpr uint64_t l_length = 4 / mss::PORTS_PER_MCS;

    for (size_t l_index = 0; l_index < mss::PORTS_PER_MCS; ++l_index)
    {
        const uint8_t* l_blob = i_blobs[l_index];
        const uint64_t l_start = 214 + (l_index * l_length);
        memcpy(&(l_value[l_index]), l_blob + l_start, l_length);
    }

    for (size_t i = 0; i < 2; ++i)
    {
        l_value[i] = be16toh(l_value[i]);
    }

    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MT_WINDAGE_RD_CTR, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MT_WINDAGE_RD_CTR start: 214, len: 4");

fapi_try_exit:
    return fapi2::current_err;
}


// VPD Keyword Version Byte: 00
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
    uint8_t l_value;

    memcpy(&l_value, i_blob + 0, 1);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_0_VERSION_LAYOUT, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_0_VERSION_LAYOUT start: 0, len: 1");

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
    uint8_t l_value;

    memcpy(&l_value, i_blob + 1, 1);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_1_VERSION_DATA, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_1_VERSION_DATA start: 1, len: 1");

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
    uint32_t l_value;

    memcpy(&l_value, i_blob + 2, 4);
    l_value = be32toh(l_value);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_2_SIGNATURE_HASH, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_2_SIGNATURE_HASH start: 2, len: 4");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 6, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_DPHY_GPO, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_DPHY_GPO start: 6, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 8, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_DPHY_RLO, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_DPHY_RLO start: 8, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 10, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_DPHY_WLO, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_DPHY_WLO start: 10, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 12, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A00, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A00 start: 12, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 14, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A01, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A01 start: 14, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 16, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A02, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A02 start: 16, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 18, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A03, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A03 start: 18, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 20, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A04, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A04 start: 20, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 22, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A05, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A05 start: 22, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 24, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A06, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A06 start: 24, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 26, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A07, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A07 start: 26, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 28, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A08, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A08 start: 28, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 30, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A09, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A09 start: 30, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 32, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A10, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A10 start: 32, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 34, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A11, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A11 start: 34, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 36, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A12, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A12 start: 36, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 38, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A13, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A13 start: 38, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 40, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A17, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_A17 start: 40, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 42, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_BA0, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_BA0 start: 42, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 44, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_BA1, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_BA1 start: 44, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 46, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_BG0, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_BG0 start: 46, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 48, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_BG1, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_BG1 start: 48, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 50, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_C0, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_C0 start: 50, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 52, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_C1, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_C1 start: 52, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 54, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_C2, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_ADDR_C2 start: 54, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 56, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_D0_CLKP, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_D0_CLKP start: 56, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 58, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_D0_CLKN, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_D0_CLKN start: 58, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 60, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_D1_CLKP, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_D1_CLKP start: 60, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 62, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_D1_CLKN, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_D1_CLKN start: 62, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 64, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CMD_ACTN, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CMD_ACTN start: 64, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 66, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CMD_ADDR_CASN_A15, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CMD_ADDR_CASN_A15 start: 66, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 68, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CMD_ADDR_RASN_A16, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CMD_ADDR_RASN_A16 start: 68, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 70, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CMD_ADDR_WEN_A14, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CMD_ADDR_WEN_A14 start: 70, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 72, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CMD_PAR, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CMD_PAR start: 72, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 74, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_CKE0, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_CKE0 start: 74, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 76, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_CKE1, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_CKE1 start: 76, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 78, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_CKE0, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_CKE0 start: 78, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 80, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_CKE1, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_CKE1 start: 80, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 82, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_CSN0, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_CSN0 start: 82, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 84, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_CSN1, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_CSN1 start: 84, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 86, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_CSN0, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_CSN0 start: 86, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 88, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_CSN1, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_CSN1 start: 88, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 90, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_ODT0, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_ODT0 start: 90, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 92, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_ODT1, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D0_ODT1 start: 92, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 94, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_ODT0, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_ODT0 start: 94, len: 2");

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
    uint8_t l_value[2];

    memcpy(&l_value, i_blob + 96, 2);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_ODT1, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_PHASE_ROT_CNTL_D1_ODT1 start: 96, len: 2");

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
    uint8_t l_value;

    memcpy(&l_value, i_blob + 98, 1);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_MC_2N_MODE_AUTOSET, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_MC_2N_MODE_AUTOSET start: 98, len: 1");

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
    uint8_t l_value;

    memcpy(&l_value, i_blob + 99, 1);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_TSYS_ADR, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_TSYS_ADR start: 99, len: 1");

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
    uint8_t l_value;

    memcpy(&l_value, i_blob + 100, 1);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_MR_TSYS_DATA, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_MR_TSYS_DATA start: 100, len: 1");

fapi_try_exit:
    return fapi2::current_err;
}


// VPD Keyword Version Byte: map
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
    uint8_t l_value[2][2][4];

    memcpy(&l_value, i_blob + 0, 16);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_CKE_MAP, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_CKE_MAP start: 0, len: 16");

fapi_try_exit:
    return fapi2::current_err;
}


// VPD Keyword Version Byte: map
///
/// @brief ATTR_MSS_VPD_DQ_MAP decode and set
/// @param[in] i_target fapi2::Target<fapi2::TARGET_TYPE_MCS>
/// @param[in] i_blob the VPD blob for this MCS
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff set is OK
/// @note  [PORT][Dimm DQ PIN]  The map from the Dual Inline Memory Module (DIMM) Data (DQ) Pin to the Module Package Data (DQ) Pinout
///
inline fapi2::ReturnCode vpd_dq_map(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target, const uint8_t* i_blob)
{
    uint8_t l_value[2][72];

    memcpy(&l_value, i_blob + 0, 144);
    FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_VPD_DQ_MAP, i_target, l_value),
              "Unable to decode and set ATTR_MSS_VPD_DQ_MAP start: 0, len: 144");

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
                                    const std::vector<uint8_t*>& i_mt_blob, const uint8_t* i_mr_blob, const uint8_t* i_cke_blob, const uint8_t* i_dq_blob)
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
    FAPI_TRY (decoder::vpd_mr_0_version_layout(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_1_version_data(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_2_signature_hash(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_dphy_gpo(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_dphy_rlo(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_dphy_wlo(i_target, i_mr_blob) );
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
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_d0_clkp(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_d0_clkn(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_d1_clkp(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_d1_clkn(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cmd_actn(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cmd_addr_casn_a15(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cmd_addr_rasn_a16(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cmd_addr_wen_a14(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cmd_par(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cntl_d0_cke0(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cntl_d0_cke1(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cntl_d1_cke0(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cntl_d1_cke1(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cntl_d0_csn0(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cntl_d0_csn1(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cntl_d1_csn0(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cntl_d1_csn1(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cntl_d0_odt0(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cntl_d0_odt1(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cntl_d1_odt0(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_phase_rot_cntl_d1_odt1(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_mc_2n_mode_autoset(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_tsys_adr(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_mr_tsys_data(i_target, i_mr_blob) );
    FAPI_TRY (decoder::vpd_cke_map(i_target, i_cke_blob) );
    FAPI_TRY (decoder::vpd_dq_map(i_target, i_dq_blob) );

fapi_try_exit:
    return fapi2::current_err;
}


} // close ns mss
#endif
