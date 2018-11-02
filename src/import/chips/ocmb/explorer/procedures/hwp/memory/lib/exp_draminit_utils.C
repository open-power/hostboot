/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/exp_draminit_utils.C $ */
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
/// @file exp_draminit_utils.C
/// @brief Procedure definition to initialize DRAM
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <generic/memory/lib/utils/c_str.H>
#include <lib/exp_draminit_utils.H>

namespace mss
{
namespace exp
{

///
/// @brief host_fw_command_struct structure setup
/// @param[in] i_cmd_data_crc the command data CRC
/// @param[out] o_cmd the command parameters to set
///
void setup_cmd_params(const uint32_t i_cmd_data_crc, host_fw_command_struct& o_cmd)
{
    // Issue full boot mode cmd though EXP-FW REQ buffer
    o_cmd.cmd_id = mss::exp::omi::FW_SPD_DATA_SET;
    o_cmd.cmd_flags = 0;

    // TK - Fabricated value need to figure out if we'll be creating req_id tables
    o_cmd.request_identifier = 0xBB;
    o_cmd.cmd_length = 0;
    o_cmd.cmd_crc = i_cmd_data_crc;
    o_cmd.host_work_area = 0;
    o_cmd.cmd_work_area = 0;
    memset(o_cmd.padding, 0, sizeof(o_cmd.padding));
}

namespace check
{

///
/// @brief Checks explorer response argument for a successful command
/// @param[in] i_target OCMB target
/// @param[in] i_rsp response command
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode response(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                           const host_fw_response_struct& i_rsp)
{
    // Check if cmd was successful
    FAPI_ASSERT(i_rsp.response_argument[0] == omi::response_arg::SUCCESS,
                fapi2::MSS_EXP_RSP_ARG_FAILED().
                set_TARGET(i_target).
                set_RSP_ID(i_rsp.response_id).
                set_ERROR_CODE(i_rsp.response_argument[1]),
                "Failed to initialize the PHY for %s", mss::c_str(i_target));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

}//check

}// exp
}// mss
