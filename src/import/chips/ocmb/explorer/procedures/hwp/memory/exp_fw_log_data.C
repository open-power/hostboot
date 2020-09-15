/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/exp_fw_log_data.C $ */
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
/// @file  exp_fw_log_data.C
///
/// @brief Collects Explorer firmware log data
// ----------------------------------------
// *HWP HWP Owner: Matt Derksen <mderkse1@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB
// ----------------------------------------
#include <exp_fw_log_data.H>
#include <fapi2.H>
#include <lib/inband/exp_inband.H>
#include <lib/inband/exp_fw_log.H>
#include <lib/shared/exp_consts.H>
#include <exp_data_structs.H>
#include <generic/memory/lib/utils/c_str.H>


extern "C"
{
    /// See header
    fapi2::ReturnCode exp_active_log(
        const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmbTarget,
        std::vector<uint8_t>& o_data)
    {
        host_fw_command_struct l_active_errl_cmd;
        host_fw_response_struct l_response;

        // common interface (SUB_CMD_READ_ACTIVE_LOG ignores image and offset)
        mss::exp::ib::exp_fw_log_cmd_parms_struct_t l_cmd_parms =
        {
            mss::exp::ib::SUB_CMD_READ_ACTIVE_LOG,
            mss::exp::ib::EXP_IMAGE_A,
            0,
            static_cast<uint32_t>(o_data.size())
        };

        // Set up the command packet
        FAPI_TRY(mss::exp::ib::build_log_cmd(i_ocmbTarget,
                                             l_cmd_parms,
                                             l_active_errl_cmd),
                 "exp_active_log: Failed build_log_cmd() for %s!",
                 mss::c_str(i_ocmbTarget));

        // Send the command packet
        FAPI_TRY(mss::exp::ib::putCMD(i_ocmbTarget, l_active_errl_cmd),
                 "exp_active_log: Failed putCMD() for %s!",
                 mss::c_str(i_ocmbTarget));

        // Get the response
        FAPI_TRY(mss::exp::ib::getRSP(i_ocmbTarget, l_response, o_data),
                 "exp_active_log: Failed getRSP() cmd for %s!",
                 mss::c_str(i_ocmbTarget));

        // Check if cmd was successful
        FAPI_TRY(mss::exp::ib::check_log_cmd_response(i_ocmbTarget, l_response),
                 "exp_active_log: Failed check_log_cmd_response() for %s!",
                 mss::c_str(i_ocmbTarget));

    fapi_try_exit:
        return fapi2::current_err;
    }


    /// See header
    fapi2::ReturnCode exp_saved_log(
        const mss::exp::ib::exp_image i_image,
        const uint32_t i_offset,
        const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmbTarget,
        std::vector<uint8_t>& io_data)
    {
        host_fw_command_struct l_saved_log_cmd;
        host_fw_response_struct l_response;

        mss::exp::ib::exp_fw_log_cmd_parms_struct_t l_cmd_parms =
        {
            mss::exp::ib::SUB_CMD_READ_SAVED_LOG,
            i_image,
            i_offset,
            static_cast<uint32_t>(io_data.size())
        };

        // Set up the command packet
        FAPI_TRY(mss::exp::ib::build_log_cmd(i_ocmbTarget,
                                             l_cmd_parms,
                                             l_saved_log_cmd),
                 "exp_saved_log: Failed build_log_cmd() for %s!",
                 mss::c_str(i_ocmbTarget));

        // Send the command packet
        FAPI_TRY(mss::exp::ib::putCMD(i_ocmbTarget, l_saved_log_cmd),
                 "exp_saved_log: Failed putCMD() for %s!",
                 mss::c_str(i_ocmbTarget));

        // Get the response
        FAPI_TRY(mss::exp::ib::getRSP(i_ocmbTarget, l_response, io_data),
                 "exp_saved_log: Failed getRSP() for %s!",
                 mss::c_str(i_ocmbTarget));

        // Check if cmd was successful
        FAPI_TRY(mss::exp::ib::check_log_cmd_response(i_ocmbTarget, l_response),
                 "exp_saved_log: Failed check_log_cmd_response()"
                 " for %s!", mss::c_str(i_ocmbTarget));
    fapi_try_exit:
        return fapi2::current_err;
    }
}
