/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/core/p10_sbe_instruct_start.H $ */
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
///----------------------------------------------------------------------------
///
/// @file p10_sbe_instruct_start.H
///
/// @brief Start instructions via p10_thread control
///        Use to start thread instruction execution as part of
//         istep proc_sbe_instruct_start / proc_exit_cache_contained
///
/// *HWP HW Maintainer: Nicholas Landi <nlandi@ibm.com>
/// *HWP FW Maintainer: Raja Das <rajadas2@in.ibm.com>
/// *HWP Consumed by  : SBE
///----------------------------------------------------------------------------

#ifndef _PROC_SBE_INSTRUCT_START_H_
#define _PROC_SBE_INSTRUCT_START_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi2.H>
#include <p10_thread_control.H>

typedef fapi2::ReturnCode (*p10_sbe_instruct_start_FP_t)(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>&,
    const ThreadSpecifier);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------
extern "C"
{
///
/// @brief Start instructions for specified threads on a single core
///
/// @param[in] i_target      Reference to core target
/// @param[in] i_thread_mask Threads to start
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code
///
    fapi2::ReturnCode p10_sbe_instruct_start(
        const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
        const ThreadSpecifier i_thread_mask);

} // extern "C"

#endif // _PROC_SBE_INSTRUCT_START_H_
