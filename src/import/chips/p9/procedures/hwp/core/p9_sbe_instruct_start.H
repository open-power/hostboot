/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/core/p9_sbe_instruct_start.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
/// @file p9_sbe_instruct_start.C
/// @brief  Placeholder for overrides needed to step the core from cache-contained execution to expand to memory
///
// *HWP HWP Owner: Nick Klazynski <jklazyns@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Nest
// *HWP Level: 2
// *HWP Consumed by: HB

#ifndef _PROC_SBE_INSTRUCT_START_H_
#define _PROC_SBE_INSTRUCT_START_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi2.H>
#include <p9_thread_control.H>

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode
(*p9_sbe_instruct_start_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_CORE>&);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------
extern "C"
{
//------------------------------------------------------------------------------
// Hardware Procedure
//------------------------------------------------------------------------------
///
/// @brief Calls thread_control to start instruction on thread 0.
///        This is to be called during IPL (istep 5.2)
///
/// @param[in] i_target   Reference to core target
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code
///
    fapi2::ReturnCode p9_sbe_instruct_start(
        const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target);

} // extern "C"

#endif // _PROC_SBE_INSTRUCT_START_H_
