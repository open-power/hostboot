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
#include <exp_check_for_ready.H>
#include <lib/i2c/exp_i2c.H>
#include <generic/memory/lib/utils/poll.H>

extern "C"
{
///
/// @brief Checks if the explorer I2C is ready to receive commands
/// @param[in] i_target the controller
/// @return FAPI2_RC_SUCCESS iff ok
///
    fapi2::ReturnCode exp_check_for_ready(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
    {
        // Using default parameters
        mss::poll_parameters l_poll_params;

        // From MSCC explorer firmware arch spec
        // 4.1.5: After power-up, the Explorer Chip will respond with NACK to all incoming I2C requests
        // from the HOST until the I2C slave interface is ready to receive commands.
        FAPI_ASSERT( mss::poll(i_target, l_poll_params, [i_target]()->bool
        {
            return mss::exp::i2c::is_ready(i_target) == fapi2::FAPI2_RC_SUCCESS;
        }),
        fapi2::MSS_EXP_I2C_POLLING_TIMEOUT().
        set_TARGET(i_target),
        "Failed to see an ACK from I2C -- polling timeout on %s",
        mss::c_str(i_target) );

        // We send the EXP_FW_STATUS command as a sanity check to see if it returns SUCCESS
        FAPI_ASSERT( mss::poll(i_target, l_poll_params, [i_target]()->bool
        {
            return mss::exp::i2c::fw_status(i_target) == fapi2::FAPI2_RC_SUCCESS;
        }),
        fapi2::MSS_EXP_STATUS_POLLING_TIMEOUT().
        set_TARGET(i_target),
        "Failled to see a successful return code -- polling timeout on %s",
        mss::c_str(i_target) );

        return fapi2::FAPI2_RC_SUCCESS;

    fapi_try_exit:
        return fapi2::current_err;
    }

}// extern C
