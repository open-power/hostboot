/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/mvpd_accessors/getMBvpdVoltageSettingData.H $ */
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
// $Id: getMBvpdVoltageSettingData.H,v 1.1 2015/09/29 16:25:05 dcrowell Exp $
/**
 *  @file getMBvpdVoltageSettingData.H
 *
 *  @brief MBVPD Accessor for providing the ATTR_VPD_DW_KEYWORD attribute
 */

#ifndef _HWP_GETMBVPDDWDATA_
#define _HWP_GETMBVPDDWDATA_

#include <fapi.H>
#define DW_KEYWORD_DEFAULT_VALUE 0x0109
// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*getMBvpdVoltageSettingData_FP_t)
    (const fapi::Target &, uint32_t &);

extern "C"
{
/**
 * @brief Get the ATTR_VPD_DW_KEYWORD FAPI attribute
 *
 * Return the voltage setting data from MBvpd record SPDX keyword DW.
 *
 * The ATTR_VPD_DW_KEYWORD attribute is associated with a DIMM. The platfrom must
 * get the associated MemBuff chip to be passed to this hwp accessor.
 *
 * @param[in]  i_mbTarget - Reference to membuff Target
 * @param[out] o_val      - Filled in with vpd version
 *
 * @return fapi::ReturnCode FAPI_RC_SUCCESS if success, else error code
 */
fapi::ReturnCode getMBvpdVoltageSettingData(
    const fapi::Target & i_mbTarget,
    uint32_t & o_val);
}

#endif
