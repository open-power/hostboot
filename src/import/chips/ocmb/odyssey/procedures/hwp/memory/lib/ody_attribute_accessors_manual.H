/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/ody_attribute_accessors_manual.H $ */
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
// EKB-Mirror-To: hostboot

///
/// @file ody_attribute_accessors_manual.H
/// @brief Manually created attribute accessors.
/// Some attributes aren't in files we want to incorporate in to our automated
/// accessor generator. EC workarounds is one example - everytime someone creates
/// a work-around they'd be burdened with updating this file.
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory
#ifndef ODY_ATTR_ACCESS_MANUAL_H_
#define ODY_ATTR_ACCESS_MANUAL_H_
#include <fapi2.H>
#include <mss_generic_attribute_getters.H>

namespace mss
{
namespace ody
{

///
/// @brief Unit-testable half dimm mode helper function. Calculates half dimm mode based on input params
/// @param[in] i_target OCMB chip
/// @param[in] i_half_dimm_attr half dimm mode as obtained from attribute
/// @param[in] i_half_dimm_override_attr half dimm mode override from attribute
/// @param[out] o_is_half_dimm_mode resulting value for half dimm mode after calculations
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode half_dimm_mode_helper(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const uint8_t i_half_dimm_attr,
    const uint8_t i_half_dimm_override_attr,
    bool& o_is_half_dimm_mode );

///
/// @brief Gets whether the OCMB will be configured to half-DIMM mode
/// @param[in] i_target OCMB target on which to operate
/// @param[out] o_is_half_dimm_mode true if the part is in half-DIMM mode
/// @return fapi2::ReturnCode - FAPI2_RC_SUCCESS iff get is OK
///
fapi2::ReturnCode half_dimm_mode(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    bool& o_is_half_dimm_mode);

///
/// @brief Retrieves number of sub ranks per DIMM which is the number of total ranks divided by the number of master ranks
/// @param[in] i_target DIMM target
/// @param[in,out] io_num_sranks Count of sranks
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode get_srank_count(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
    uint8_t& io_num_sranks);

} // ns ody

} // ns mss

#endif
