/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/fapi2/plat_vpd_access.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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
/// @file plat_vpd_access.H
///
/// @brief Platform vpd-access definitions
///

#ifndef _FAPI2_PLAT_VPDACCESS_H_
#define _FAPI2_PLAT_VPDACCESS_H_

#include <fapi2_vpd_access.H>

namespace fapi2
{

/// @brief Return a blob of memory VPD data associated with the input target
///
/// Platform specific getVPD implmentation for MCS target type
///
/// @param[in] i_target, a valid fapi2 MCS target
/// @param[in] io_vpd_info, fapi2::VPDInfo class that specifies which piece
///            of data to return. Types MR and MT supported.
/// @param[out] o_blob, the blob of raw data from the vpd
/// @return FAPI2_RC_SUCCESS if there's no problem
/// @note passing nullptr for o_blob will return the size of the keyword

fapi2::ReturnCode platGetVPD(
                    const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                    VPDInfo<fapi2::TARGET_TYPE_MCS>& io_vpd_info,
                    uint8_t* o_blob);

/// @brief Return a blob of memory VPD data associated with the input target
///        If looking for blob to match keyword EFD, then search criteria
///        frequency and master rank must be supplied.
///
/// Platform specific getVPD implmentation for OCMB_CHIP target type
///
/// @param[in] i_target, a valid fapi2 OCMB_CHIP target
/// @param[in] io_vpd_info, fapi2::VPDInfo class that specifies the criteria of
////           the desired data to be returned and meta data about returned data
///   @param[in]  io_vpd_info.iv_vpd_type, currently only keyword EFD supported
///   @param[in/out] io_vpd_info.iv_size, as in param - the size of the keyword
///                  as an out param - size of keyword if o_blob is a nullptr
///   @param[in]  io_vpd_info.iv_omi_freq_mhz, frequency of attached OMI bus
///   @param[in]  io_vpd_info.iv_rank_count, number of master ranks
///   @param[in]  io_vpd_info.iv_is_config_ffdc_enabled, flag to collect FFDC or not
///   @param[out] io_vpd_info.iv_efd_type, type of DDIMM SPD
///   @param[out] io_vpd_info.iv_dmb_mfg_id, buffer manufacturer
///   @param[out] io_vpd_info.iv_dmb_revision, buffer revision
///   @param[out] io_vpd_info.iv_ddr_mode, DDR4 or DDR5
/// @param[out] o_blob, the blob of raw data from the vpd
/// @return FAPI2_RC_SUCCESS if there's no problem
/// @note The size of returned data may be less than or equal to the initial value of iv_size.
///       The value of iv_size will be adjusted to match the actual size of the returned data.
/// @note If data is returned for o_blob (EFD), it will be in little endian
/// @note passing nullptr for o_blob will return the size of the keyword
fapi2::ReturnCode platGetVPD(
                    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                    VPDInfo<fapi2::TARGET_TYPE_OCMB_CHIP>& io_vpd_info,
                    uint8_t* o_blob);

};
#endif // _FAPI2_PLAT_VPDACCESS_H_
