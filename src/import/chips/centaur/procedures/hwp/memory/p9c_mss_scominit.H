/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_scominit.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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

/// @file p9c_mss_scominit.H
/// @brief Calls the various memory initfiles
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB


#ifndef MSS_SCOMINIT_H_
#define MSS_SCOMINIT_H_

//----------------------------------------------------------------------
//  Includes
//----------------------------------------------------------------------
#include <fapi2.H>

typedef fapi2::ReturnCode (*p9c_mss_scominit_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target);

extern "C" {

    /// @brief p9c_mss_scominit procedure: Calls the vaious memory initfiles
    /// @param[in] i_target [Reference to target, expecting centaur(MEMBUF) target]
    /// @return ReturnCode
    fapi2::ReturnCode p9c_mss_scominit(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target);

}

#endif // MSS_SCOMINIT_H_
