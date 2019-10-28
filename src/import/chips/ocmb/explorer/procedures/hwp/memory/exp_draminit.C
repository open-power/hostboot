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

#include <lib/shared/exp_consts.H>
#include <lib/inband/exp_inband.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/mss_bad_bits.H>
#include <lib/exp_draminit_utils.H>
#include <lib/phy/exp_train_display.H>
#include <lib/phy/exp_train_handler.H>
#include <lib/shared/exp_consts.H>
#include <generic/memory/mss_git_data_helper.H>

extern "C"
{
    ///
    /// @brief Initializes DRAM
    /// @param[in] i_target the controller
    /// @return FAPI2_RC_SUCCESS if ok
    ///
    fapi2::ReturnCode exp_draminit(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
    {
        mss::display_git_commit_info("exp_draminit");

        uint32_t l_crc = 0;
        host_fw_command_struct l_cmd;

        user_input_msdg l_phy_params;
        uint8_t l_sim = 0;
        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(), l_sim) );

        FAPI_TRY(mss::exp::setup_phy_params(i_target, l_phy_params),
                 "Failed setup_phy_params() for %s", mss::c_str(i_target));

        // Copy the PHY initialization parameters into the internal buffer of Explorer
        FAPI_TRY( mss::exp::ib::putUserInputMsdg(i_target, l_phy_params, l_crc),
                  "Failed putUserInputMsdg() for %s", mss::c_str(i_target) );

        {
            // Issue full boot mode cmd though EXP-FW REQ buffer
            FAPI_TRY( mss::exp::setup_cmd_params(i_target,
                                                 l_crc,
                                                 sizeof(l_phy_params),
                                                 l_cmd) );
            FAPI_TRY( mss::exp::ib::putCMD(i_target, l_cmd),
                      "Failed putCMD() for  %s", mss::c_str(i_target) );
        }

        // Wait a bit for the command (and training) to complete
        // Value based on initial Explorer hardware in Cronus in i2c mode.
        // Training takes ~10ms with no trace, ~450ms with Explorer UART debug
        FAPI_TRY( fapi2::delay( (mss::DELAY_1MS * 8), 200) );

        // Read the response message from EXP-FW RESP buffer
        {
            host_fw_response_struct l_response;
            user_response_msdg l_train_response;

            std::vector<uint8_t> l_rsp_data;
            fapi2::ReturnCode l_rc(fapi2::FAPI2_RC_SUCCESS);

            FAPI_TRY( mss::exp::ib::getRSP(i_target, l_response, l_rsp_data),
                      "Failed getRSP() for  %s", mss::c_str(i_target) );

            if (!l_sim)
            {
                // Proccesses the response data
                FAPI_TRY( mss::exp::read_training_response(i_target, l_rsp_data, l_train_response),
                          "Failed read_training_response for %s", mss::c_str(i_target));

                // Displays the training response
                FAPI_TRY( mss::exp::train::display_info(i_target, l_train_response));

                // Check if cmd was successful
                l_rc = mss::exp::check::response(i_target, l_response, l_cmd);

                // If not, then we need to process the bad bitmap
                if(l_rc != fapi2::FAPI2_RC_SUCCESS)
                {
                    mss::exp::bad_bit_interface l_interface(l_train_response);

                    // Record bad bits should only fail if we have an attributes issue - that's a major issue
                    FAPI_TRY(mss::record_bad_bits<mss::mc_type::EXPLORER>(i_target, l_interface));

                    // Now, go to our true error handling procedure
                    FAPI_TRY(l_rc, "mss::exp::check::response failed for %s", mss::c_str(i_target));
                }
            }
        }

    fapi_try_exit:
        FAPI_INF("Draminit training - %s %s",
                 (fapi2::current_err == fapi2::FAPI2_RC_SUCCESS ? "success" : "errors reported - trying to blame FIR's"),
                 mss::c_str(i_target));

        // Due to the RAS/PRD requirements, we need to check for FIR's
        // If any FIR's have lit up, this draminit fail could have been caused by the FIR, rather than bad hardware
        // So, let PRD retrigger this step to see if we can resolve the issue
        return mss::check::fir_or_pll_fail<mss::mc_type::EXPLORER>(i_target, fapi2::current_err);
    }
}
