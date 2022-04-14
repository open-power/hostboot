/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/hwpf/fapi2/include/fapi2_vpd_access.H $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2022                        */
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
/// @file fapi2_vpd_access.H
/// @brief Common file that defines the vpd access functions that
/// platform code must implement.
///
//

#ifndef _FAPI2_VPDACCESS_H_
#define _FAPI2_VPDACCESS_H_

#include <return_code.H>
#include <target_types.H>
#include <vpd_access_defs.H>
#include <plat_vpd_access.H>

namespace fapi2
{

/// constants for VPD Info
constexpr uint64_t VPD_INFO_INVALID_64  = 0xffffffffffffffff;
constexpr uint64_t VPD_INFO_INVALID_16  = 0xffff;
constexpr uint64_t VPD_INFO_INVALID_8   = 0xff;

/// @brief  Specialized class representing required VPDInfo to be used
///         in collecting VPD for the MCS target type.
/// @tparam T fapi2::TARGET_TYPE_MCS
template<>
class VPDInfo<TARGET_TYPE_MCS>
{
    public:
        /// @brief VPDInfo constructor
        /// @param[in] i_vpd_type Type of VPD data to return
        VPDInfo( const fapi2::MemVpdData& i_vpd_type)
            : iv_vpd_type(i_vpd_type),
              iv_size(VPD_INFO_INVALID_64),
              iv_freq_mhz(VPD_INFO_INVALID_64),
              iv_rank_count_dimm_0(VPD_INFO_INVALID_64),
              iv_rank_count_dimm_1(VPD_INFO_INVALID_64),
              iv_is_config_ffdc_enabled(true)
        {};
        // type of vpd field to return
        fapi2::MemVpdData_t iv_vpd_type;

        // size of the vpd data
        size_t   iv_size;

        // frequency of memory bus
        uint64_t iv_freq_mhz;

        // number of ranks per dimm position
        uint64_t iv_rank_count_dimm_0;
        uint64_t iv_rank_count_dimm_1;

        // set to false to avoid collecting a real ReturnCode
        bool     iv_is_config_ffdc_enabled;
};

/// @brief  Specialized class representing required VPDInfo to be used
///         in collecting VPD for the OCMB_CHIP target type.
/// @tparam T fapi2::TARGET_TYPE_OCMB_CHIP
template<>
class VPDInfo<TARGET_TYPE_OCMB_CHIP>
{
    public:
        /// @brief VPDInfo constructor
        /// @param[in] i_vpd_type Type of VPD data to return
        VPDInfo( const fapi2::MemVpdData& i_vpd_type)
            : iv_vpd_type(i_vpd_type),
              iv_size(VPD_INFO_INVALID_64),
              iv_omi_freq_mhz(VPD_INFO_INVALID_64),
              iv_rank(VPD_INFO_INVALID_64),
              iv_is_config_ffdc_enabled(true),
              iv_efd_type(VPD_INFO_INVALID_8),
              iv_dmb_mfg_id(VPD_INFO_INVALID_16),
              iv_dmb_revision(VPD_INFO_INVALID_8),
              iv_ddr_mode(VPD_INFO_INVALID_8),
              iv_dimm_count(VPD_INFO_INVALID_64),
              iv_total_ranks_dimm0(VPD_INFO_INVALID_64),
              iv_total_ranks_dimm1(VPD_INFO_INVALID_64),
              iv_dimm_type(VPD_INFO_INVALID_64)
        {};

        // *** INPUT DATA ***

        // type of vpd field to return
        fapi2::MemVpdData_t iv_vpd_type;

        // size of the vpd data in bytes
        size_t   iv_size;

        // frequency of attached OMI bus
        uint64_t iv_omi_freq_mhz;

        // rank for which settings are valid
        uint64_t iv_rank;

        // set to false to avoid collecting a real ReturnCode
        bool     iv_is_config_ffdc_enabled;


        // *** OUTPUT DATA ***

        // metadata describing the EFD data that was returned
        uint8_t iv_efd_type;     // e.g. byte 288 of DDIMM SPD
        uint16_t iv_dmb_mfg_id;  // buffer manufacturer
        uint8_t iv_dmb_revision; // buffer revision
        uint8_t iv_ddr_mode;     // DDR4 or DDR5

        // *** NEW INPUT DATA FOR PLANAR EFD ***
        // Note: these fields only need to be set in planar applications
        // and are at the end of this class for backward compatibility

        // total number of DIMMs attached
        uint64_t iv_dimm_count;

        // total number of ranks on each of the DIMMs attached
        uint64_t iv_total_ranks_dimm0;
        uint64_t iv_total_ranks_dimm1;

        // DIMM type encoding, matches 'DIMMs Supported' byte 7 in EFD:
        // (bits numbered right to left)
        // bit7: reserved, code as 0
        // bit6: '1' if the DIMM is 3DS
        // bit5: '1' if the DIMM supports DDP
        // bit4: '1' if the DIMM supports quad rank mode
        // bits3,2: b00 for UDIMM, b01 for RDIMM
        // bit1: '1' for DIMM in slot 1
        // bit0: '1' for DIMM in slot 0
        uint64_t iv_dimm_type;
};


/// @brief Return a blob of memory VPD data associated with the input target
/// @param[in] i_target     a valid fapi2 target
/// @param[in] io_vpd_info  fapi2::VPDInfo class that specifies which piece of data to return
/// @param[out] o_blob      the blob of raw data from the vpd
/// @return FAPI2_RC_SUCCESS if there's no problem
/// @note passing nullptr for o_blob will return the size of the keyword
///
/// Example:
/// fapi2::VPDInfo<fapi2::TARGET_TYPE_MCS> vpdInfo(MR_keyword);
/// vpdInfo.iv_freq = 2667;
///
/// uint8_t * blob = NULL;
///
/// FAPI_TRY(getVPD( mcs, vpdInfo, blob ));
/// blob = static_cast<uint8_t *>(malloc(vpdInfo.iv_size));
/// FAPI_TRY(getVPD( mcs, vpdInfo, blob ));
/// blob now contains the VPD data for the MCS.
///
template<TargetType T, MulticastType M, typename V>
ReturnCode getVPD(const Target<T, M, V>& i_target,
                  VPDInfo<T>& io_vpd_info,
                  uint8_t* o_blob);

};
#endif
