/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_eff_mb_interleave.H $ */
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

/// @file p9c_mss_eff_mb_interleave.C
/// @brief checks the plugging rules for a centaur and works with interleaving within the centaur
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB



#ifndef __MSS_EFF_MB_INTERLEAVE_H
#define __MSS_EFF_MB_INTERLEAVE_H

#include <fapi2.H>

typedef fapi2::ReturnCode (*p9c_mss_eff_mb_interleave_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>&
        centaur );

extern "C"
{

    // This hardware procedure checks the plugging rules for a centaur and works with interleaving within the centaur
    // if various plug rules are violated at this level of the memory stack, error logs and deconfigures will happen
    // Many deconfig by assoication rules are not checked here.  Just 4.1 and 4.2 plus a required Interleaving check
    ///
    /// @brief checks the plugging rules for a centaur and works with interleaving within the centaur
    /// @param[in] i_cen_target
    /// @return fapi2::returnCode
    ///
    fapi2::ReturnCode p9c_mss_eff_mb_interleave(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_cen_target);



} // extern "C"

#endif
