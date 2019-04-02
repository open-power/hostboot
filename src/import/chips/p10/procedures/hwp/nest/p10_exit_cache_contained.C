/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_exit_cache_contained.C $ */
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
/// @file p10_exit_cache_contained.C
/// @brief Placeholder to apply inits needed prior to HB expansion from L3
/// cache to main memory (FAPI2)
///
/// @author Joe McGill <jmcgill@us.ibm.com>
///

//
// *HW HW Maintainer: Nicholas Landi <nlandi@ibm.com>
// *HW FW Maintainer: Christian Geddes <crgeddes@us.ibm.com>
// *HW Consumed by  : HB
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_exit_cache_contained.H>


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode
p10_exit_cache_contained(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_INF("Start");
    FAPI_INF("End");
    return fapi2::FAPI2_RC_SUCCESS;
}
