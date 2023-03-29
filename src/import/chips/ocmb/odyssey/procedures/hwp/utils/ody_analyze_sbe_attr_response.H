/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/utils/ody_analyze_sbe_attr_response.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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

/// @file ody_analyze_sbe_attr_response.H
/// @brief Parse the response received from the SBE for the attribute update request
///
// *HWP HWP Owner: P Rajees <rajerpp1@in.ibm.com>
// *HWP HWP Backup: T Rajeswaran <rajeswgo@in.ibm.com>
// *HWP Team: SBE
// *HWP Consumed by: Cronus:HB

#ifndef _ODY_ANALYZE_SBE_ATTR_RESPONSE_
#define _ODY_ANALYZE_SBE_ATTR_RESPONSE_

#include <fapi2.H>
#include <sbe_attribute_utils.H>

// Required for Cronus
typedef fapi2::ReturnCode (*ody_analyze_sbe_attr_response_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&, uint8_t*, uint16_t,
    std::vector<sbeutil::AttrError_t>&);

extern "C"
{
//
//  @brief Parse the response received from the SBE for the attributes update request.
//
//  @param[in]  i_ocmb_targ  The chip target corresponding to the target SBE
//
//  @param[in] i_buf         The input buffer containing the response
//
//  @param[in] i_buf_size    The size of the input buffer
//
//  @param[out] o_errors     The output after parsing the response from the
//                           sbe for the attribute update chipop.
//
//  @return FAPI2_RC_SUCCESS if ok
    fapi2::ReturnCode ody_analyze_sbe_attr_response(
        const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb_targ,
        uint8_t* i_buf, uint16_t i_buf_size, std::vector<sbeutil::AttrError_t>& o_errors);

}// extern C

#endif
