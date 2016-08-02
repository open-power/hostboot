/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_rng_init_phase2.H $ */
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
/// @file p9_rng_init_phase2.H
/// @brief Perform NX RNG Phase 2 initialization (FAPI2)
///
/// Phase2 RNG hostboot initialization flow:
///
/// - HW RNG is expected to have completed init sequence based on programmed
///   parameters (FW must ensure sufficient delay to complete between Phase1
///   HWP exit & Phase2 HWP start)
/// - Check RNG fail bits
///     RNG considered unusable if failed, else
///     Map RNG BARs, mark programming complete to close access to RNG SCOM
///     registers for security
///
/// @author Qian Chen <qianqc@cn.ibm.com>
///

//
// *HWP HWP Owner: Chen Qian <qianqc@cn.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Nest
// *HWP Level: 2
// *HWP Consumed by: HB
//

#ifndef _P9_RNG_INIT_PHASE2_H_
#define _P9_RNG_INIT_PHASE2_H_


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_rng_init_phase2_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&);


//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

///
/// @brief Perform NX RNG Phase 2 initialization -- check for successful
/// init sequence & enable RNG for secure use
///
/// @param[in] i_target Reference to processor chip target
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_rng_init_phase2(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

} // extern "C"

#endif // _P9_RNG_INIT_PHASE2_H_

