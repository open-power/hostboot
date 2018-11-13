/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9a/procedures/hwp/memory/p9a_omi_train.C $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
/// @file p9a_omi_train.C
/// @brief Check the omi status
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory

#include <p9a_omi_train.H>

#include <fapi2.H>
#include <p9a_mc_scom_addresses.H>
#include <p9a_mc_scom_addresses_fld.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/scom.H>
#include <generic/memory/lib/utils/buffer_ops.H>


extern "C"
{

    ///
    /// @brief Check the omi status in Axone side
    /// @param[in] i_target the OMIC target to operate on
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode p9a_omi_train( const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_target)
    {
        FAPI_INF("%s Start p9a_omi_train", mss::c_str(i_target));

        // Const
        constexpr uint8_t STATE_MACHINE_SUCCESS = 0b111;  // This value is from Lonny Lambrecht

        // Declares variables
        fapi2::buffer<uint64_t> l_omi_status;
        fapi2::buffer<uint64_t> l_omi_training_status;
        uint8_t l_state_machine_state = 0;

        // Check OMI training status
        FAPI_TRY(mss::getScom(i_target, P9A_OMI_REG0_DL0_STATUS, l_omi_status));
        FAPI_TRY(mss::getScom(i_target, P9A_OMI_REG0_DL0_TRAINING_STATUS, l_omi_training_status));

        l_omi_status.extractToRight<P9A_OMI_REG0_DL0_STATUS_STS_TRAINING_STATE_MACHINE, P9A_OMI_REG0_DL0_STATUS_STS_TRAINING_STATE_MACHINE_LEN>
        (l_state_machine_state);

        FAPI_ASSERT(l_state_machine_state == STATE_MACHINE_SUCCESS,
                    fapi2::P9A_OMI_TRAIN_ERR()
                    .set_TARGET(i_target)
                    .set_EXPECTED_SM_STATE(STATE_MACHINE_SUCCESS)
                    .set_ACTUAL_SM_STATE(l_state_machine_state)
                    .set_DL0_STATUS(l_omi_status)
                    .set_DL0_TRAINING_STATUS(l_omi_training_status),
                    "%s OMI Training Failure, expected state:%d/actual state:%d",
                    mss::c_str(i_target),
                    STATE_MACHINE_SUCCESS,
                    l_state_machine_state
                   );

        FAPI_INF("%s End p9a_omi_train, expected state:%d/actual state:%d, DL0_STATUS:%d, DL0_TRAINING_STATUS:%d",
                 mss::c_str(i_target),
                 STATE_MACHINE_SUCCESS,
                 l_state_machine_state,
                 l_omi_status,
                 l_omi_training_status);
        return fapi2::FAPI2_RC_SUCCESS;

    fapi_try_exit:
        return fapi2::current_err;

    }// p9a_omi_train
}// extern C
