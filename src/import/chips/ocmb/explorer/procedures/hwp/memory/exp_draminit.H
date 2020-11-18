/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/exp_draminit.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
/// @file exp_draminit.H
/// @brief Procedure declaration to initialize DRAM
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef __MSS_EXP_DRAMINIT__
#define __MSS_EXP_DRAMINIT__

#include <fapi2.H>

// Required for Cronus
typedef fapi2::ReturnCode (*exp_draminit_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&);

extern "C"
{

///
/// @brief Initializes DRAM
/// @param[in] i_target the controller
/// @return FAPI2_RC_SUCCESS iff ok
///
    fapi2::ReturnCode exp_draminit(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

}// extern C
#endif
