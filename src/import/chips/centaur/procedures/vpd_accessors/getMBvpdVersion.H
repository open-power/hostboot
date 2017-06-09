/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/vpd_accessors/getMBvpdVersion.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
///  @file getMBvpdVersion.H
///  @brief MBVPD Accessor for providing the ATTR_VPD_VERSION attribute
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB

#ifndef _HWP_GETMBVPDVERSION_
#define _HWP_GETMBVPDVERSION_

#include <fapi2.H>

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*getMBvpdVersion_FP_t)
(const fapi2::Target<fapi2::TARGET_TYPE_MBA>&, uint32_t&);

extern "C"
{
///
/// @brief Get the ATTR_VPD_VERSION FAPI attribute
///
/// @note Return the VPD version from MBvpd record VINI keyword VZ.
///
/// The ATTR_VPD_VERSION attribute is associated with a DIMM. The platfrom must
/// get the associated MBA chip to be passed to this hwp accessor.
///
/// @param[in]  i_mbaTarget - Reference to mba Target
/// @param[out] o_val      - Filled in with vpd version
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code
///
    fapi2::ReturnCode getMBvpdVersion(
        const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_mbaTarget,
        uint32_t& o_val);
}

#endif
