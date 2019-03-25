/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/gemini/procedures/hwp/memory/lib/gem_draminit_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
/// @file gem_draminit_utils.H
/// @brief Procedure definition to initialize DRAM
///
// *HWP HWP Owner: Mark Pizzutillo <aamarin@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef __MSS_GEM_DRAMINIT_UTILS__
#define __MSS_GEM_DRAMINIT_UTILS__

#include <fapi2.H>

namespace mss
{
namespace gem
{

///
/// @brief Checks that DIMM sizes are 32GB
/// @param[in] i_target the controller
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode gem_draminit_check_memory_size(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

///
/// @brief Polls DRAM calibration register to check for complete
/// @param[in] i_target the controller
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode gem_draminit_poll_check_calibration(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

}// exp
}// mss

#endif
