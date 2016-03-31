/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/mvpd_accessors/getMBvpdDram2NModeEnabled.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2016                        */
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
// $Id: getMBvpdDram2NModeEnabled.H,v 1.2 2015/09/29 15:59:41 dcrowell Exp $
/**
 *  @file getMBvpdDram2NModeEnabled.H
 *
 *  @brief MBVPD Accessor for providing the ATTR_VPD_DRAM_2N_MODE_ENABLED
 *    attribute
 */

#ifndef _HWP_GETMBVPDDRAM2NMODEENABLED_
#define _HWP_GETMBVPDDRAM2NMODEENABLED_

#include <fapi.H>

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*getMBvpdDram2NModeEnabled_FP_t)
    (const fapi::Target &, uint8_t &);

extern "C"
{
/**
 * @brief Get the ATTR_DRAM_2N_MODE_ENABLED FAPI attribute
 *
 * Return whether Dram 2N Mode is enabled based on the MR keyword
 *   DRAM_2N_MODE value. The DRAM_2N_Mode values for both ports of the mba
 *   must be equal, otherwise an error is returned.
 *
 * @param[in]  i_mbaTarget - Reference to mba Target
 * @param[out] o_val  - ATTR_VPD_DRAM_2N_MODE_ENABLED enumeration value
 *
 * @return fapi::ReturnCode FAPI_RC_SUCCESS if success, else error code
 */
fapi::ReturnCode getMBvpdDram2NModeEnabled(
    const fapi::Target & i_mbaTarget,
    uint8_t & o_val);
}

#endif
