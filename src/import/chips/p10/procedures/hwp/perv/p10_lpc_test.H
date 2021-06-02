/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_lpc_test.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
//------------------------------------------------------------------------------
/// @file  p10_lpc_test.H
///
/// @brief procedure to test whether the LPC logic is hung (HW570899)
//------------------------------------------------------------------------------
// *HWP HW Maintainer : Joachim Fenkes (fenkes@de.ibm.com)
// *HWP FW Maintainer : Raja Das    (rajadas2@in.ibm.com)
// *HWP Consumed by   : Hostboot
//------------------------------------------------------------------------------
// EKB-Mirror-To: hostboot
#ifndef _P10_SBE_LPC_INIT_H_
#define _P10_SBE_LPC_INIT_H_

#include <fapi2.H>

typedef fapi2::ReturnCode (*p10_lpc_test_t)(const
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&);

extern "C"
{
    /// @brief Test whether the LPC logic is hung
    ///
    /// Attempt to read data from the LPC OPB Master Status register, return an
    /// error in case that times out because the logic is stuck.
    ///
    /// @param[in]     i_target_chip   Reference to TARGET_TYPE_PROC_CHIP target
    /// @return  FAPI2_RC_SUCCESS      if LPC is alive
    ///          RC_LPC_ACCESS_TIMEOUT if LPC is stuck
    fapi2::ReturnCode p10_lpc_test(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip)
}

#endif
