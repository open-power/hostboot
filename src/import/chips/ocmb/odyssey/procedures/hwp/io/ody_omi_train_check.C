/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/io/ody_omi_train_check.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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
///------------------------------------------------------------------------------
/// @file ody_omi_train_check.C
/// @brief Check OMI training
///
/// *HWP HW Maintainer : Josh Chica <josh.chica@ibm.com>
/// *HWP FW Maintainer :
/// *HWP Consumed by: SBE
///------------------------------------------------------------------------------
#include <ody_omi_train_check.H>
#include <ody_io_ppe_common.H>
#include <ody_scom_omi.H>

SCOMT_OMI_USE_D_REG_DL0_STATUS

enum ody_omi_train_check_consts
{
    ODY_OMI_TRAINING_COMPLETE_STATE = 7,
    ODY_OMI_TRAINING_CYCLES = 100000000,
    ODY_OMI_TRAINING_NS = 10000,
    ODY_OMI_TRAINING_LOOPS = 20,
};

///
/// @brief Check OMI training
///
/// @param[in] i_target Chip target to start
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode ody_omi_train_check(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    FAPI_DBG("Starting ody_omi_train_check");

    using namespace scomt::omi;

    D_REG_DL0_STATUS_t l_dl0_status = 0;
    uint8_t l_state_machine = 0;
    int l_trys = ODY_OMI_TRAINING_LOOPS;

    while (l_trys > 0 && l_state_machine != ODY_OMI_TRAINING_COMPLETE_STATE)
    {
        FAPI_TRY(l_dl0_status.getScom(i_target));
        l_state_machine = l_dl0_status.get_TRAINING_STATE_MACHINE();
        l_trys--;

        FAPI_DBG("Training state: %x", l_state_machine);

        if (l_state_machine != ODY_OMI_TRAINING_COMPLETE_STATE && l_trys > 0)
        {
            FAPI_TRY(fapi2::delay(ODY_OMI_TRAINING_NS, ODY_OMI_TRAINING_CYCLES));
        }
    }

    FAPI_ASSERT(l_state_machine == ODY_OMI_TRAINING_COMPLETE_STATE,
                fapi2::OMI_TRAINING_DONE_POLL_FAILED()
                .set_TARGET(i_target),
                "OMI training done poll time-out" );

fapi_try_exit:
    FAPI_DBG("End ody_omi_train_check");
    return fapi2::current_err;
}
