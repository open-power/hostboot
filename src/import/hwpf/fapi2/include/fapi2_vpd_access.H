/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/hwpf/fapi2/include/fapi2_vpd_access.H $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2018                        */
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
constexpr uint64_t VPD_INFO_INVALID  = 0xffffffffffffffff;

/// @brief  Specialized class representing required VPDInfo to be used
///         in collecting VPD for the MCS target type.
/// @tparam T fapi2::TARGET_TYPE_MCS
template<>
class VPDInfo<TARGET_TYPE_MCS>
{
    public:
        // @brief VPDInfo constructor
        VPDInfo( const fapi2::MemVpdData& i_vpd_type)
            : iv_vpd_type(i_vpd_type),
              iv_size(VPD_INFO_INVALID),
              iv_freq_mhz(VPD_INFO_INVALID),
              iv_rank_count_dimm_0(VPD_INFO_INVALID),
              iv_rank_count_dimm_1(VPD_INFO_INVALID),
              iv_is_config_ffdc_enabled(true)
        {};
        // type of vpd field to return
        fapi2::MemVpdData_t iv_vpd_type;

        // size of the vpd data
        size_t   iv_size;
        uint64_t iv_freq_mhz;
        uint64_t iv_rank_count_dimm_0;
        uint64_t iv_rank_count_dimm_1;
        bool     iv_is_config_ffdc_enabled;
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
template<TargetType T, typename V>
ReturnCode getVPD(const Target<T, V>& i_target,
                  VPDInfo<T>& io_vpd_info,
                  uint8_t* o_blob);

};
#endif
