/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_rcs_transient_check.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
// EKB-Mirror-To: hostboot
///
/// @file p10_rcs_transient_check.H
/// @brief RCS Functions
///-----------------------------------------------------------------------------
/// *HW HW Maintainer: Chris Steffen <cwsteffen@us.ibm.com>
/// *HW FW Maintainer: Ryan Miller <ryan.miller@ibm.com>
/// *HW Consumed by  : HB
///-----------------------------------------------------------------------------

#include <fapi2.H>

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

/// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_rcs_transient_check_FP_t)(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    const int32_t,
    bool&);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{
/// @brief Check to see if RCS errors are hard fails or transient fails
/// @param[in] i_target_chip        chip target
/// @param[in] i_side               which side we want to check for a transient error (Aside=0, Bside=1)
/// @param[out] o_status            Status of the net (True=transient, False=hard error)
/// @return FAPI_RC_SUCCESS if arguments are valid
    fapi2::ReturnCode p10_rcs_transient_check(const
            fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
            const uint32_t i_side,
            bool& o_status);

} // extern "C"
