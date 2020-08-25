/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/inband/exp_fw_log.C $ */
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
/// @file  exp_fw_log.C
///
/// @brief Helpers to access explorer firmware logs

//
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP FW Owner: Matt Derksen <mderkse1@us.ibm.com>
// *HWP Team:
// *HWP Level: 2
// *HWP Consumed by: HB

#include <exp_fw_log.H>
#include <fapi2.H>
#include <exp_inband.H>
#include <lib/shared/exp_consts.H>
#include <exp_data_structs.H>
#include <generic/memory/lib/utils/c_str.H>


namespace mss
{
namespace exp
{
namespace ib
{

///
/// @brief Response parameters of Explorer Log commands
///        This is found in the response_argument field
typedef struct
{
    uint8_t  op;          /**< Firmware error log sub-cmd operation */
    uint8_t  status;      /**< Operation status */
    uint32_t err_code;    /**< Specific error code if operation failed */
    uint32_t num_bytes_returned; /**< Number of bytes returned */
} exp_fw_log_rsp_parms_struct_t;

///
/// @brief Operation status values
///
enum
{
    STATUS_OP_FAILED     = 0x01,
    STATUS_OP_SUCCESSFUL = 0x00,
};

/// See header
void build_log_cmd( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                    const exp_log_sub_cmd_op i_sub_op,
                    host_fw_command_struct& o_cmd )
{
    // Issue EXP_FW_LOG cmd though EXP-FW REQ buffer
    o_cmd.cmd_id = mss::exp::omi::EXP_FW_LOG;
    o_cmd.cmd_flags = 0;

    // Host generated id number (returned in response packet)
    // @todo RTC 210371
    //uint32_t l_counter = 0;
    //FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OCMB_COUNTER, i_target, l_counter));
    o_cmd.request_identifier = 0xabcd;

    if (i_sub_op == SUB_CMD_READ_SAVED_LOG)
    {
        o_cmd.request_identifier = 0xabce;
    }

    o_cmd.cmd_length = 0;

    o_cmd.cmd_crc = 0xffffffff;
    o_cmd.host_work_area = 0;
    o_cmd.cmd_work_area = 0;
    memset(o_cmd.padding, 0, sizeof(o_cmd.padding));

    // Set the sub-command ID in the command argument field
    o_cmd.command_argument[0] = i_sub_op;
}

/// See header
fapi2::ReturnCode check_log_cmd_response(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const host_fw_response_struct& i_rsp )
{
    std::vector<uint8_t> resp_arg;
    uint32_t index = 0;
    exp_fw_log_rsp_parms_struct_t l_rsp_args;

    //copy response_argument field into a vector that can be
    //used by readCrctEndian()
    resp_arg.assign(i_rsp.response_argument,
                    i_rsp.response_argument + ARGUMENT_SIZE);

    //convert fields to native endianness
    FAPI_TRY(mss::exp::ib::readCrctEndian(resp_arg, index, l_rsp_args.op));
    FAPI_TRY(mss::exp::ib::readCrctEndian(resp_arg, index, l_rsp_args.status));
    FAPI_TRY(mss::exp::ib::readCrctEndian(resp_arg, index, l_rsp_args.err_code));
    FAPI_TRY(mss::exp::ib::readCrctEndian(resp_arg, index, l_rsp_args.num_bytes_returned));

    // check if command was successful
    FAPI_ASSERT(l_rsp_args.status == STATUS_OP_SUCCESSFUL,
                fapi2::MSS_EXP_RSP_ARG_FAILED().
                set_TARGET(i_target).
                set_RSP_ID(i_rsp.response_id).
                set_ERROR_CODE(l_rsp_args.err_code),
                "EXP_FW_LOG command 0x%02X failed for %s.  "
                "Status: 0x%02X, err_code 0x%04X, num_bytes_returned 0x%04X",
                l_rsp_args.op, mss::c_str(i_target), l_rsp_args.status,
                l_rsp_args.err_code, l_rsp_args.num_bytes_returned);

fapi_try_exit:
    return fapi2::current_err;
}

}//ib namespace
}//exp namespace
}//mss namespace
