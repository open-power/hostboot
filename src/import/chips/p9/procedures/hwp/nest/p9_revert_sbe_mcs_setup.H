/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_revert_sbe_mcs_setup.H $ */
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
/// @file p9_revert_sbe_mcs_setup.H
/// @brief Revert MC configuration applied by SBE (FAPI2)
///
/// Reset memory controller configuration written by SBE in order to
/// enable initial phase of hostboot execution (providing lpc_ack for dcbz
/// prior to initialization of memory).  Registers touched by SBE will
/// be reset to flush state by this procedure.
///
/// @author Joe McGill <jmcgill@us.ibm.com>
///

//
// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Nest
// *HWP Level: 3
// *HWP Consumed by: HB
//

#ifndef _P9_REVERT_SBE_MCS_SETUP_H_
#define _P9_REVERT_SBE_MCS_SETUP_H_


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_revert_sbe_mcs_setup_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    bool);


//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

///
/// @brief Disable MC configuration written by SBE to enable initial phase
/// of hostboot execution
///
/// @param[in] i_target Reference to processor chip target
/// @param[in] i_maskPervSBEFirs tell func whether to mask SBE related pervasive fir bits
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_revert_sbe_mcs_setup(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        bool i_maskPervSbeFirs);

} // extern "C"

#endif // _P9_REVERT_SBE_MCS_SETUP_H_
