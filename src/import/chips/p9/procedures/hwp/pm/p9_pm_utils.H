/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_utils.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file p9_pm_utils.H
/// @brief Utility functions for PM FAPIs
///

// *HWP HWP Owner       : Amit Kumar <akumar3@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Prem Jha <premjha2@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 1
// *HWP Consumed by     : HS

#ifndef _P9_PM_UTILS_H_
#define _P9_PM_UTILS_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Common macros
//------------------------------------------------------------------------------

uint16_t revle16(const uint16_t i_x);
uint32_t revle32(const uint32_t i_x);
uint64_t revle64(const uint64_t i_x);

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------

///
/// @brief Trace a set of FIRs (Globals and select Locals)
/// @param[in] i_target Chip target
/// @param[in] i_msg String to put out in the trace
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p9_pm_glob_fir_trace(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const char* i_msg);

///
/// @brief Sets or clears special wake-up on all configured EX on a target
/// @param[in] i_target Chip target
/// @param[in] i_enable true = enable. false = disable.
/// @return FAPI2_RC_SUCCESS If the special wake-up is successful,
///         else error code.
///
fapi2::ReturnCode special_wakeup_all(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    bool i_enable);

#endif // _P9_PM_UTILS_H_
