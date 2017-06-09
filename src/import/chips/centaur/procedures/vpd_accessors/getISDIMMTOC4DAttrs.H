/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/vpd_accessors/getISDIMMTOC4DAttrs.H $ */
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
/// @file getISDIMMTOC4DAttrs.H
/// @brief MBvpd accessor for the ATTR_VPD_ISDIMMTOC4DQ and DQS attributes
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB

#ifndef _HWP_MVPDGETISDIMMTOC4DATTRS_
#define _HWP_MVPDGETISDIMMTOC4DATTRS_

extern "C"
{
    const uint32_t DQ_KEYWORD_SIZE = 96;

///
/// @brief Utility function for the ATTR_VPD_ISDIMMTOC4DQ attribute
/// @note Given the D0 information, return the correct DQ copy.
/// @param[in] i_mbTarget  - Reference to mb Target
/// @param[in] i_whichCopy  - D0 information of which Q copy to get
/// @param[out] o_DQKeyword - Correct DQ information
/// @return fapi::ReturnCode FAPI_RC_SUCCESS if success, else error code
///
    fapi2::ReturnCode getDQAttribute(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_mbTarget,
                                     uint32_t i_whichCopy, uint8_t (&o_DQKeyword)[DQ_KEYWORD_SIZE]);

}
#endif

