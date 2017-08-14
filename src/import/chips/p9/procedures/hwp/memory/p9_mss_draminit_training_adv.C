/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/p9_mss_draminit_training_adv.C $ */
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
/// @file p9_mss_draminit_training_adv.C
/// @brief Train dram
///
// *HWP HWP Owner: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <mss.H>
#include <vector>

#include <p9_mss_draminit_training.H>
#include <lib/utils/count_dimm.H>
#include <lib/shared/mss_const.H>
#include <lib/workarounds/dp16_workarounds.H>
#include <lib/workarounds/dqs_align_workarounds.H>
#include <lib/fir/unmask.H>
#include <lib/dimm/ddr4/zqcal.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCA;

extern "C"
{
    ///
    /// @brief Train dram
    /// @param[in] i_target, the McBIST of the ports of the dram you're training
    /// @param[in] i_special_training, optional CAL_STEP_ENABLE override. Used in sim, debug
    /// @param[in] i_abort_on_error, optional CAL_ABORT_ON_ERROR override. Used in sim, debug
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode p9_mss_draminit_training_adv( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target,
            const uint32_t i_special_training,
            const uint8_t i_abort_on_error)
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }
}
