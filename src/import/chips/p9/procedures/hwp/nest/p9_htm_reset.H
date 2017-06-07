/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_htm_reset.H $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// ----------------------------------------------------------------------------
/// @file  p9_htm_reset.H
///
/// @brief Reset the HTM engines on a processor chip
///
/// ----------------------------------------------------------------------------
/// *HWP HWP Owner   : Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Owner    : Thi Tran <thi@us.ibm.com>
/// *HWP Team        : Nest
/// *HWP Level       : 3
/// *HWP Consumed by : HB
/// ----------------------------------------------------------------------------

#ifndef _P9_HTM_RESET_H_
#define _P9_HTM_RESET_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

// Function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_htm_reset_FP_t)(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------
///
/// @brief p9_htm_reset procedure
///
/// This HWP is to reset the HTM engines.
///
/// @param[in]    i_target   Reference to TARGET_TYPE_PROC_CHIP target
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
extern "C"
{
    fapi2::ReturnCode p9_htm_reset(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

} // extern "C"

#endif  // _P9_HTM_RESET_H_
