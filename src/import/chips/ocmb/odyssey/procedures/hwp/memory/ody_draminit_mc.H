/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/ody_draminit_mc.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2022                        */
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

///
/// @file ody_draminit_mc.H
/// @brief Initialize the memory controller to take over the DRAM
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB

#ifndef _ODY_DRAMINIT_MC_H_
#define _ODY_DRAMINIT_MC_H_

#include <fapi2.H>

typedef fapi2::ReturnCode (*ody_draminit_mc_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&);

extern "C"
{

    ///
    /// @brief Initialize the MC now that DRAM is up
    /// @param[in] i_target the OCMB target to operate on
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode ody_draminit_mc(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);
}

#endif
