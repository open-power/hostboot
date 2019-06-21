/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/io/p10_omi_train_check.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file p10_omi_train_check.C
/// @brief Wait until omi training is complete or timeout with error
//------------------------------------------------------------------------------
/// *HW HW Maintainer: Chris Steffen <cwsteffen@us.ibm.com>
/// *HW FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HW Consumed by  : HB
//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_omi_train_check.H>
#include <p10_scom_omi.H>
#include <p10_io_lib.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode
p10_omi_train_check(
    const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_target)
{
    using namespace scomt::omi;
    FAPI_DBG("Start");

    // Const
    constexpr uint8_t STATE_MACHINE_SUCCESS = 0b111;  // This value is from Lonny Lambrecht
    constexpr uint8_t MAX_LOOP_COUNT = 20;  // Retry times

    // Declares variables
    fapi2::buffer<uint64_t> l_omi_status;
    fapi2::buffer<uint64_t> l_omi_training_status;
    uint64_t l_state_machine_state = 0;
    uint8_t l_tries = 0;

    FAPI_TRY(GET_STATUS(i_target, l_omi_status));
    GET_STATUS_TRAINING_STATE_MACHINE(l_omi_status, l_state_machine_state);

    while (l_tries < MAX_LOOP_COUNT && l_state_machine_state != STATE_MACHINE_SUCCESS)
    {
        // Delay
        fapi2::delay(100, 50000000);

        // Check OMI training status
        FAPI_TRY(GET_STATUS(i_target, l_omi_status));
        GET_STATUS_TRAINING_STATE_MACHINE(l_omi_status, l_state_machine_state);

        // Note: this is very useful debug information while trying to debug training during polling
        FAPI_TRY(GET_TRAINING_STATUS(i_target, l_omi_training_status));
        l_tries++;
    }

    FAPI_ASSERT(l_state_machine_state == STATE_MACHINE_SUCCESS,
                fapi2::P10_OMI_TRAIN_ERR()
                .set_TARGET(i_target)
                .set_EXPECTED_SM_STATE(STATE_MACHINE_SUCCESS)
                .set_ACTUAL_SM_STATE(l_state_machine_state)
                .set_DL0_STATUS(l_omi_status)
                .set_DL0_TRAINING_STATUS(l_omi_training_status),
                "OMI Training Failure, expected state:%d/actual state:%d",
                STATE_MACHINE_SUCCESS,
                l_state_machine_state
               );

    FAPI_INF("End p10_omi_train_check, expected state:%d/actual state:%d, DL0_STATUS:0x%016llx, DL0_TRAINING_STATUS:0x%016llx",
             STATE_MACHINE_SUCCESS,
             l_state_machine_state,
             l_omi_status,
             l_omi_training_status);

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
