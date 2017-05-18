/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/ffdc/p9_collect_ppe_state.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
/// @file  p9_collect_ppe_state.H
/// @brief FFDC procedure to dump a PPE engine's state to the return code
//         object passed by the user.
///
/// *HWP HW Owner        : Greg Still <stillgs@us.ibm.com>
/// *HWP HW Backup Owner : Brian Vanderpool <vanderp@us.ibm.com>
/// *HWP FW Owner        : Amit Tendolkar <amit.tendolkar@in.ibm.com>
/// *HWP Team            : PM
/// *HWP Level           : 3
/// *HWP Consumed by     : HB

#ifndef __P9_COLLECT_PPE_STATE_H__
#define __P9_COLLECT_PPE_STATE_H__

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <return_code.H>
#include <error_info_defs.H>

/// @typedef p9_collect_ppe_state_FP_t
/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_collect_ppe_state_FP_t) (
    const fapi2::ffdc_t&,
    const fapi2::ffdc_t&,
    const fapi2::ffdc_t&,
    fapi2::ReturnCode&
);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------
extern "C"
{

/// @brief HWP to collect PPE internal register (SPRs, XIRs and GPRs) state as
///        FFDC associated to the input ReturnCode object
/// @param [in] i_target           TARGET_TYPE_PROC_CHIP
/// @param [in] i_dumpMode         refer to PPE_DUMP_MODE in p9_ppe_utils.H
/// @param [in] i_v_ppe_addresses  Vector of addresses of PPEs, whose states
///                                are to be collected. See p9_ppe_defs.H
/// @param[out] io_rc               Return code to add FFDC data to
/// @return FAPI2_RC_SUCCESS       Always succeeds
    fapi2::ReturnCode
    p9_collect_ppe_state ( const fapi2::ffdc_t& i_target,
                           const fapi2::ffdc_t& i_mode,
                           const fapi2::ffdc_t& i_v_ppe_addresses,
                           fapi2::ReturnCode& io_rc );

} // extern C

#endif  // __P9_COLLECT_PPE_STATE_H___
