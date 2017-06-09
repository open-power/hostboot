/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/vpd_accessors/getMBvpdDram2NModeEnabled.H $ */
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
///  @file getMBvpdDram2NModeEnabled.H
///  @brief MBVPD Accessor for providing the ATTR_VPD_DRAM_2N_MODE_ENABLED attribute
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB

#ifndef _HWP_GETMBVPDDRAM2NMODEENABLED_
#define _HWP_GETMBVPDDRAM2NMODEENABLED_

#include <fapi2.H>

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*getMBvpdDram2NModeEnabled_FP_t)
(const fapi2::Target<fapi2::TARGET_TYPE_MBA>&, uint8_t&);

extern "C"
{
///
/// @brief Get the ATTR_DRAM_2N_MODE_ENABLED FAPI attribute
///
/// Return whether Dram 2N Mode is enabled based on the MR keyword
///   DRAM_2N_MODE value. The DRAM_2N_Mode values for both ports of the mba
///   must be equal, otherwise an error is returned.
///
/// @param[in]  i_mbaTarget - Reference to mba Target
/// @param[out] o_val  - ATTR_VPD_DRAM_2N_MODE_ENABLED enumeration value
/// @return fapi::ReturnCode FAPI_RC_SUCCESS if success, else error code
///
    fapi2::ReturnCode getMBvpdDram2NModeEnabled(
        const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_mbaTarget,
        uint8_t& o_val);
}

#endif
