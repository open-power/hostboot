/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/bootloader/fapi2/plat_utils.C $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
/// @file plat_utils.C
///
/// @brief Implements the plat_utils.H utility functions.
///
/// Note that platform code must provide the implementation.
///

#include <plat_hw_access.H>
#include <return_code.H>
#include <hw_access_def.H>

namespace fapi2
{

// Define global current_err
ReturnCode current_err;

///
/// @brief Resets all HWP thread_local variables
///
void hwpResetGlobals(void)
{
    // Reset all HWP thread_local vars
    fapi2::current_err = fapi2::FAPI2_RC_SUCCESS;
    fapi2::opMode = fapi2::NORMAL;
}


} //end namespace
