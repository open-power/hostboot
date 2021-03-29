/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/exp_check_for_ready.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2021                        */
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
/// @file exp_check_for_ready.C
/// @brief FW polls I2C slave interface to determine when it is ready
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/shared/exp_defaults.H>
#include <exp_check_for_ready.H>
#include <lib/i2c/exp_i2c.H>
#include <generic/memory/mss_git_data_helper.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <mss_explorer_attribute_setters.H>
#include <mss_explorer_attribute_getters.H>
#include <mss_generic_system_attribute_getters.H>

extern "C"
{
///
/// @brief Checks if the explorer I2C is ready to receive commands
/// @param[in] i_target the controller
/// @return FAPI2_RC_SUCCESS iff ok
///
    fapi2::ReturnCode exp_check_for_ready(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
    {
        mss::display_git_commit_info("exp_check_for_ready");

        uint8_t l_sim = 0;
        FAPI_TRY(mss::attr::get_is_simulation(l_sim));

        if (l_sim)
        {
            FAPI_INF("Sim, skipping exp_check_for_ready %s", mss::c_str(i_target));
            return fapi2::FAPI2_RC_SUCCESS;
        }

        {
            fapi2::ATTR_MSS_CHECK_FOR_READY_TIMEOUT_Type l_poll_count = 0;
            FAPI_TRY(mss::attr::get_check_for_ready_timeout(i_target, l_poll_count));
            FAPI_TRY(mss::exp::i2c::exp_check_for_ready_helper(i_target, l_poll_count, mss::DELAY_1MS));
        }

        // Save our new communication state
        FAPI_TRY(mss::attr::set_exp_comm_state(i_target, fapi2::ENUM_ATTR_MSS_EXP_COMM_STATE_I2C_NO_SCOM));

    fapi_try_exit:
        return fapi2::current_err;

    }

}// extern C
