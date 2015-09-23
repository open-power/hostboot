/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_exit_cache_contained.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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
/// @file p9_exit_cache_contained.C
/// @brief  Placeholder for overrides needed to step the core from cache-contained execution to expand to memory
///
// *HWP HWP Owner: Michael Dye <dyem@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Nest
// *HWP Level: 1
// *HWP Consumed by: HB


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_exit_cache_contained.H>

extern "C"
{
///
/// p9_exit_cache_contained HWP entry point (Defined in .H file)
///
    fapi2::ReturnCode p9_exit_cache_contained(const
            fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
            & i_target)
    {
        fapi2::ReturnCode rc;

        //Mark Entry
        FAPI_INF("Entering ...");

        //Mark Exit
        FAPI_INF("Exiting ...");

        return rc;
    }
} // extern "C"
/* End: */
