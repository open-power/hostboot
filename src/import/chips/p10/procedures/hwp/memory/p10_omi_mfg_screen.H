/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/p10_omi_mfg_screen.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
/// @file p10_omi_mfg_screen.H
/// @brief Perform checks for the OMI manufacturing screen
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Mark Pizzutillo <Mark.Pizzutillo@ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _P10_OMI_MFG_SCREEN_H_
#define _P10_OMI_MFG_SCREEN_H_

#include <fapi2.H>

typedef fapi2::ReturnCode (*p10_omi_mfg_screen_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_OMIC>&);

extern "C"
{
    ///
    /// @brief Perform checks for the OMI manufacturing screen
    /// @param[in] i_target the OMIC target to operate on
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode p10_omi_mfg_screen( const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target );

} // extern "C"

#endif
