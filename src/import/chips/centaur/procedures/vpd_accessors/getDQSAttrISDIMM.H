/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/vpd_accessors/getDQSAttrISDIMM.H $ */
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
/// @file getDQSAttrISDIMM.H
/// @brief MBvpd accessor for the ATTR_VPD_ISDIMMTOC4DQS attribute
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB

#ifndef _HWP_MVPDGETDQSATTRISDIMM_
#define _HWP_MVPDGETDQSATTRISDIMM_
#include <dimmConsts.H>

typedef fapi2::ReturnCode (*getDQSAttrISDIMM_FP_t)
(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>&,
 uint8_t (&)[MAX_PORTS_PER_CEN][DIMM_TO_C4_DQS_ENTRIES]);

extern "C"
{
    ///
    /// @brief MBvpd accessor for the ATTR_VPD_ISDIMMTOC4DQS attribute
    /// @note Access the compressed DQS data in the MBvpd record, SPDX, keyword K1-K9
    /// @param[in] i_mbTarget    - Reference to mb Target
    /// @param[out] o_val[4][20] - Decoded K data
    /// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if success, else error code
    ///
    fapi2::ReturnCode getDQSAttrISDIMM(
        const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_mbTarget,
        uint8_t (&o_val)[MAX_PORTS_PER_CEN][DIMM_TO_C4_DQS_ENTRIES]);
}

#endif
