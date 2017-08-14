/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/p9_mss_draminit_training_adv.H $ */
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
/// @file p9_mss_draminit_trainingi_adv.H
/// @brief Train DRAM
///
// *HWP HWP Owner: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef __P9_MSS_DRAMINIT_TRAINING_ADV__
#define __P9_MSS_DRAMINIT_TRAINING_ADV__

#include <fapi2.H>

typedef fapi2::ReturnCode (*p9_mss_draminit_training_adv_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>&,
        const uint32_t,
        const uint8_t);

// Use a special sentinal to let you know you need to read the attribute (which is 1/0)
constexpr uint8_t CAL_ADV_ABORT_SENTINAL = 3;

extern "C"
{

    ///
    /// @brief Train dram, assumes effective config has run
    /// @param[in] i_target the McBIST of the ports of the dram you're training
    /// @param[in] i_special_training optional CAL_STEP_ENABLE override. Used in sim, debug
    /// @param[in] i_abort_on_error, optional CAL_ABORT_ON_ERROR override. Used in sim, debug
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode p9_mss_draminit_training_adv( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target,
            const uint32_t i_special_training = 0,
            const uint8_t i_abort_on_error = CAL_ADV_ABORT_SENTINAL);
}


#endif
