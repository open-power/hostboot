/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/accessors/ddimm_get_efd.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2023                        */
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
/// @file ddimm_get_efd.H
/// @brief Return the DDIMMs EFD based on VPDInfo
///
/// *HWP HW Maintainer: Roland Veloz <rveloz@us.ibm.com>
/// *HWP FW Maintainer: Christian Geddes <crgeddes@us.ibm.com>
/// *HWP Consumed by: Cronus, FSP, HB

#ifndef _GET_DDR_EFD_H_
#define _GET_DDR_EFD_H_

#include <fapi2.H>
#include <fapi2_vpd_access.H>    // VPDInfo<TARGET_TYPE_OCMB_CHIP>

namespace fapi2
{

}

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*ddimm_get_efd_FP_t)(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&,
    fapi2::VPDInfo<fapi2::TARGET_TYPE_OCMB_CHIP>&,
    uint8_t* const,
    const uint8_t* const,
    const size_t);
extern "C"
{
/// @brief Return the DDR4/5's EFD based on VPDInfo
///        This procedure explicitly returns the EFD data, associated with a
///        DDR4 or DDR5, that matches given frequency and master rank criteria.
///
/// @param[in]  i_ocmbFapi2Target, a valid fapi2 OCMB_CHIP target
/// @param[in]  io_vpdInfo, @see ddimm_get_efd
/// @param[out] o_efdData, @see ddimm_get_efd
/// @param[in]  i_spdBuffer, pointer to the SPD data
/// @param[in]  i_spdBufferSize, size of the SPD data
/// @param[in]  i_dram_gen, DRAM generation (4 or 5) of the SPD
/// @note The size of blob may be less than io_vpdInfo.iv_size
/// @note If data is returned for o_efdData, it will be in little endian
/// @note Caller is responsible for allocating the buffers of o_efdData and
///       i_spdBuffer.  This procedure will NOT manage these buffers. This
///       procedure will only read/write to buffers, not allocate.
/// @return FAPI2_RC_SUCCESS iff ok
    fapi2::ReturnCode ddr4_ddr5_get_efd(
        const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&  i_ocmbFapi2Target,
        fapi2::VPDInfo<fapi2::TARGET_TYPE_OCMB_CHIP>& io_vpdInfo, // Can modify data
        uint8_t* const o_efdData,    // Don't change pointer but can modify data
        const uint8_t* const i_spdBuffer,// Don't change pointer nor modify data
        size_t   i_spdBufferSize,    // Don't modify
        const uint8_t i_dram_gen);   // Don't modify


/// @brief Return the DDIMMs EFD based on VPDInfo
///        This procedure returns the EFD data that matches given
///        frequency and master rank criteria.
///
/// @param[in] i_ocmbFapi2Target, a valid fapi2 OCMB_CHIP target
/// @param[in] io_vpdInfo,fapi2::VPDInfo class that specifies the criteria of
///            the desired data to be returned and meta data about returned data
///   @param[in]  io_vpd_info.iv_vpd_type, keyword EFD
///   @param[in/out] io_vpd_info.iv_size, as in param - the size of the keyword
///                  as an out param - size of keyword if o_blob is a nullptr
///   @param[in]  io_vpd_info.iv_omi_freq_mhz, frequency of attached OMI bus
///   @param[in]  io_vpd_info.iv_rank_count, number of master ranks,
///   @param[in]  io_vpd_info.iv_is_config_ffdc_enabled, flag to collect FFDC or not
///   @param[out] io_vpd_info.iv_efd_type, type of DDIMM SPD
///   @param[out] io_vpd_info.iv_dmb_mfg_id, buffer manufacturer
///   @param[out] io_vpd_info.iv_dmb_revision, buffer revision
///   @param[out] io_vpd_info.iv_ddr_mode, DDR4 or DDR5
/// @param[in]  i_spdBuffer, pointer to the DDR's SPD data
/// @param[in]  i_spdBufferSize, size of DDR's SPD data
/// @param[out] o_efdData, this is a pointer to pre-allocated memory that
///               will have the contents of the EFD sought after (if found)
///               or will contain 0, if not found or error occurred.
/// @note The size of blob may be less than io_vpd_info.iv_size
/// @note If data is returned for o_efdData, it will be in little endian
/// @note Caller is responsible for allocating the buffers of o_efdData and
///       i_spdBuffer.  This procedure will NOT manage these buffers. This
///       procedure will only read/write to buffers, not allocate.
/// @pre i_spdBuffer cannot be NULL and i_spdBufferSize cannot be 0 but must
///      be size of i_spdBuffer
/// @return FAPI2_RC_SUCCESS iff ok
    fapi2::ReturnCode ddimm_get_efd(
        const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&  i_ocmbFapi2Target,
        fapi2::VPDInfo<fapi2::TARGET_TYPE_OCMB_CHIP>& io_vpdInfo,
        uint8_t*  const o_efdData,   // Don't change pointer but can modify data
        const uint8_t*  const i_spdBuffer, // Don't change pointer nor modify data
        const size_t    i_spdBufferSize);  // Don't modify
}

#endif
