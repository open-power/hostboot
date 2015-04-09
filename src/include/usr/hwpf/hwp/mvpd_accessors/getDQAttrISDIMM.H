/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/mvpd_accessors/getDQAttrISDIMM.H $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
// $ID: getDQAttrISDIMM.H, v 1.1 2014/9/25 04:38:00 eliner Exp $
/*
 * @file getDQAttrISDIMM.H
 *
 * @brief MBvpd accessor for the ATTR_VPD_ISDIMMTOC4DQ attribute
 */

#ifndef _HWP_MVPDGETDQATTRISDIMM_
#define _HWP_MVPDGETDQATTRISDIMM_

typedef fapi::ReturnCode (*getDQAttrISDIMM_FP_t)
     (const fapi::Target &,
      uint8_t (&)[4][80]);

extern "C"
{

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

}
#endif
