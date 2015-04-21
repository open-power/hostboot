/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/hwp/chip_accessors/getTdpRdpCurrentFactor.H $ */
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
// $Id: getTdpRdpCurrentFactor.H,v 1.1 2015/06/01 18:30:12 whs Exp $
/**
 *  @file getTdpRdpCurrentFactor.H
 *
 *  @brief Accessor for providing the ATTR_TDP_RDP_CURRENT_FACTOR attribute
 */

#ifndef _HWP_GETTDPRDPCURRENTFACTOR_
#define _HWP_GETTDPRDPCURRENTFACTOR_

#include <fapi.H>

// function pointer typedef definition for HWP call support
typedef fapi::ReturnCode (*getTdpRdpCurrentFactor_FP_t)
    (const fapi::Target &, uint32_t &);

extern "C"
{
/**
 * @brief Get the ATTR_TDP_RDP_CURRENT_FACTOR FAPI attribute
 *
 * @param[in]  i_procTarget - Reference to processor chip target
 * @param[out] o_val        - Filled in with TDP RDP Current Factor
 *
 * @return fapi::ReturnCode FAPI_RC_SUCCESS if success, else error code
 */
fapi::ReturnCode getTdpRdpCurrentFactor(
    const fapi::Target & i_procTarget,
    uint32_t & o_val);
}

#endif
