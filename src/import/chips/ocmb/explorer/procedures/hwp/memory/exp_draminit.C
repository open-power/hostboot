/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/exp_draminit.C $ */
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
/// @file exp_draminit.C
/// @brief Procedure definition to initialize DRAM
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <exp_inband.H>
#include <generic/memory/lib/utils/c_str.H>
#include <lib/exp_draminit_utils.H>

///
/// @brief Initializes DRAM
/// @param[in] i_target the controller
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode exp_draminit(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    uint32_t l_crc = 0;

    user_input_msdg l_phy_params;
    FAPI_TRY(mss::exp::setup_phy_params(i_target, l_phy_params),
             "Failed setup_phy_params() for %s", mss::c_str(i_target));

    // Copy the PHY initialization parameters into the internal buffer of Explorer
    FAPI_TRY( mss::exp::ib::putUserInputMsdg(i_target, l_phy_params, l_crc),
              "Failed putUserInputMsdg() for %s", mss::c_str(i_target) );

    // Issue full boot mode cmd though EXP-FW REQ buffer
    {
        host_fw_command_struct l_cmd;
        mss::exp::setup_cmd_params(l_crc, l_cmd);
        FAPI_TRY( mss::exp::ib::putCMD(i_target, l_cmd),
                  "Failed putCMD() for  %s", mss::c_str(i_target) );
    }

    // Read the response message from EXP-FW RESP buffer
    {
        host_fw_response_struct l_response;
        FAPI_TRY( mss::exp::ib::getRSP(i_target, l_response),
                  "Failed getRSP() for  %s", mss::c_str(i_target) );

        // Check if cmd was successful
        FAPI_TRY(mss::exp::check::response(i_target, l_response),
                 "Failed check::response() for  %s", mss::c_str(i_target) );
    }

fapi_try_exit:
    return fapi2::current_err;
}
