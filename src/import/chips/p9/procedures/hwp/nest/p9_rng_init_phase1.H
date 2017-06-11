/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_rng_init_phase1.H $ */
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
/// @file p9_rng_init_phase1.H
/// @brief Perform NX RNG Phase 1 initialization (FAPI2)
///
/// Phase1 RNG hostboot initialization flow:
///
/// NX RNG HW POR state:
/// - HW RNG is running with FIFO write and self tests disabled (rng_enable = 0)
///   at POR
/// - HW RNG conditioner startup test will run automatically
///
/// Phase 1 HWP:
/// 1. Check for successful conditioner startup test (RNG unusable if failed)
/// 2. Programs window sizes, pace, self test enables/parameters, and read delay
///    parameters
/// 3. Check self test hard fail status
///    RNG considered unusable if failed
///      ELSE
///    Set rng_enable = 1
///
/// @author Chen Qian <qianqc@cn.ibm.com>
///

//
// *HWP HWP Owner: Chen Qian <qianqc@cn.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Nest
// *HWP Level: 3
// *HWP Consumed by: HB
//

#ifndef _P9_RNG_INIT_PHASE1_H_
#define _P9_RNG_INIT_PHASE1_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_rng_init_phase1_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

///
/// @brief Perform NX RNG Phase 1 initialization -- check for successful
/// conditioner startup test & engage HW init sequence
///
/// @param[in] i_target Reference to processor chip target
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_rng_init_phase1(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

} // extern "C"

#endif // _P9_RNG_INIT_PHASE1_H_

