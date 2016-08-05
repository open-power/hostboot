/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/utils/fake_vpd.H $ */
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

///
/// @file fake_vpd.H
/// @brief A tool to return fake (fixed) system VPD for testing, development
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP
#ifndef DOXYGEN

#ifndef _MSS_FAKE_SPD_H_
#define _MSS_FAKE_SPD_H_

#include <fapi2.H>
#include <vpd_access.H>

namespace mss
{

///
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
fapi2::ReturnCode getVPD(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                         fapi2::VPDInfo<fapi2::TARGET_TYPE_MCS>& io_vpd_info,
                         uint8_t* o_blob);

} // ns mss

#endif
#endif
