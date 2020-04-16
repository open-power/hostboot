/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/mvpd_accessors/getMBvpdMemoryDataVersion.H $ */
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
// $Id: getMBvpdMemoryDataVersion.H,v 1.2 2015/10/06 15:18:04 dcrowell Exp $
/**
 *  @file getMBvpdMemoryDataVersion.H
 *
 *  @brief MBVPD Accessor for providing the ATTR_VPD_VM_KEYWORD attribute
 */

#ifndef _HWP_GETMBVPDMEMDATAVERSION_
#define _HWP_GETMBVPDMEMDATAVERSION_

#include <fapi.H>

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*getMBvpdMemoryDataVersion_FP_t)
    (const fapi::Target &, uint32_t &);

extern "C"
{
/**
 * @brief Get the ATTR_VPD_VM_KEYWORD FAPI attribute
 *
 * Return the Memory Data version from MBvpd record SPDX keyword VM.
 *
 * The ATTR_VPD_VM_KEYWORD attribute is associated with a DIMM. The platfrom must
 * get the associated Membuff chip to be passed to this hwp accessor.
 *
 * @param[in]  i_mbTarget - Reference to membuf Target
 * @param[out] o_val      - Filled in with vpd version
 *
 * @return fapi::ReturnCode FAPI_RC_SUCCESS if success, else error code
 */
fapi::ReturnCode getMBvpdMemoryDataVersion(
    const fapi::Target & i_mbTarget,
    uint32_t & o_val);
}

#endif
