/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/exp_check_for_ready.C $ */
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
/// @file exp_check_for_ready.C
/// @brief FW polls I2C slave interface to determine when it is ready
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <lib/shared/exp_defaults.H>
#include <exp_check_for_ready.H>
#include <lib/i2c/exp_i2c.H>
#include <generic/memory/mss_git_data_helper.H>

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
        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_sim) );

        if (!l_sim)
        {
            FAPI_TRY(mss::exp::i2c::exp_check_for_ready_helper(i_target));
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

}// extern C
