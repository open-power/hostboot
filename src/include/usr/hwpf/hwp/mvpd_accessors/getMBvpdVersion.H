/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/mvpd_accessors/getMBvpdVersion.H $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
// $Id: getMBvpdVersion.H,v 1.1 2013/10/30 21:04:08 whs Exp $
/**
 *  @file getMBvpdVersion.H
 *
 *  @brief MBVPD Accessor for providing the ATTR_VPD_VERSION attribute
 */

#ifndef _HWP_GETMBVPDVERSION_
#define _HWP_GETMBVPDVERSION_

#include <fapi.H>

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*getMBvpdVersion_FP_t)
    (const fapi::Target &, uint32_t &);

extern "C"
{
/**
 * @brief Get the ATTR_VPD_VERSION FAPI attribute
 *
 * Return the VPD version from MBvpd record VINI keyword VZ.
 *
 * The ATTR_VPD_VERSION attribute is associated with a DIMM. The platfrom must
 * get the associated MBA chip to be passed to this hwp accessor.
 *
 * @param[in]  i_mbaTarget - Reference to mba Target
 * @param[out] o_val      - Filled in with vpd version
 *
 * @return fapi::ReturnCode FAPI_RC_SUCCESS if success, else error code
 */
fapi::ReturnCode getMBvpdVersion(
    const fapi::Target & i_mbaTarget,
    uint32_t & o_val);
}

#endif
