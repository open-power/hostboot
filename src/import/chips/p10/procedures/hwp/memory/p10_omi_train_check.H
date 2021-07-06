/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/p10_omi_train_check.H $ */
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

///
/// @file p10_omi_train_check.H
/// @brief Poll for omi training completion / failure
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _P10_OMI_TRAIN_CHECK_H_
#define _P10_OMI_TRAIN_CHECK_H_

#include <fapi2.H>

typedef fapi2::ReturnCode (*p10_omi_train_check_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_OMI>&);

extern "C"
{
    ///
    /// @brief Check training state of OMI
    /// @param[in] i_target Reference to OMI endpoint target
    /// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
    ///
    fapi2::ReturnCode p10_omi_train_check(const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_target);

} // extern "C"

#endif // _P10_OMI_TRAIN_CHECK_H_
