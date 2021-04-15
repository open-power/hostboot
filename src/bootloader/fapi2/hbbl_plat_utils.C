/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/bootloader/fapi2/hbbl_plat_utils.C $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
/// @file hbbl_plat_utils.C
///
/// @brief Implements the plat_utils.H utility functions.
///
/// Note that platform code must provide the implementation.
///

#include <plat_hw_access.H>
#include <return_code.H>
#include <hw_access_def.H>
#include <bl_console.H>

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

///
/// @brief HBBL's implementation of delay
///
/// @param[in] i_nanoSeconds the amount of ns to wait
/// @param[in] i_simCycles unused
/// @param[in] i_fixed unused
///
/// @return Always returns success
ReturnCode delay(const uint64_t i_nanoSeconds,
                 const uint64_t i_simCycles,
                 const bool i_fixed)
{
    bl_nanosleep(0, i_nanoSeconds);
    return FAPI2_RC_SUCCESS;
}
} //end namespace
