/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/mvpd_accessors/getISDIMMTOC4DAttrs.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
// $ID: getISDIMMTOC4DAttrs.H, v 1.1 2014/9/25 04:38:00 eliner Exp $
/*
 * @file getISDIMMTOC4DAttrs.H
 *
 * @brief MBvpd accessor for the ATTR_VPD_ISDIMMTOC4DQ and DQS attributes
 */

#ifndef _HWP_MVPDGETISDIMMTOC4DATTRS_
#define _HWP_MVPDGETISDIMMTOC4DATTRS_

extern "C"
{
const uint32_t DQ_KEYWORD_SIZE = 96;

/*
 * @brief Utility function for the ATTR_VPD_ISDIMMTOC4DQ attribute
 *
 * Given the D0 information, return the correct DQ copy.
 *
 * @param[in] i_mbTarget  - Reference to mb Target
 * @param[in] i_whichCopy  - D0 information of which Q copy to get
 * @param[out] o_DQKeyword - Correct DQ information
 *
 * @return fapi::ReturnCode FAPI_RC_SUCCESS if success, else error code
 */

fapi::ReturnCode getDQAttribute(const fapi::Target &i_mbTarget,
           uint32_t i_whichCopy, uint8_t (&o_DQKeyword)[DQ_KEYWORD_SIZE]);

/*
 * @brief MBvpd accessor for the ATTR_VPD_ISDIMMTOC4DQ attribute
 *
 * Access the compressed DQ data in the MBvpd record SPDX, keyword Q1-Q9
 *
 * @param[in] i_mbTarget    - Reference to mb Target
 * @param[out] o_val[4][80] - Decoded Q data
 *
 * @return fapi::ReturnCode FAPI_RC_SUCCESS if success, else error code
 */

fapi::ReturnCode getDQAttrISDIMM(
                const fapi::Target &i_mbTarget,
                uint8_t (&o_val)[4][80]);

/*
 * @brief MBvpd accessor for the ATTR_VPD_ISDIMMTOC4DQS attribute
 *
 * Access the compressed DQS data in the MBvpd record, SPDX, keyword K1-K9
 *
 * @param[in] i_mbTarget    - Reference to mb Target
 * @param[out] o_val[4][20] - Decoded K data
 *
 * @return fapi::ReturnCode FAPI_RC_SUCCESS if success, else error code
 */

fapi::ReturnCode getDQSAttrISDIMM(
                const fapi::Target &i_mbTarget,
                uint8_t (&o_val)[4][20]);
}
#endif

