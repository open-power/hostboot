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
#include <generic/memory/lib/utils/endian_utils.H>

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
    STATUS_OP_SUCCESSFUL = 0x00,
    STATUS_OP_FAILED     = 0x01,
};

/// @brief Debug function to trace explorer fw log command
/// @param i_cmd - command to be sent to Explorer
void trace_cmd(const host_fw_command_struct& i_cmd)
{
    FAPI_DBG("cmd_id:    0x%02X", i_cmd.cmd_id);
    FAPI_DBG("cmd_flags: 0x%02X", i_cmd.cmd_flags);
    FAPI_DBG("request_identifier: 0x%04X", i_cmd.request_identifier);
    FAPI_DBG("cmd_length      : 0x%08X", i_cmd.cmd_length);
    FAPI_DBG("cmd_crc         : 0x%08X", i_cmd.cmd_crc);
    FAPI_DBG("host_work_area  : 0x%08X", i_cmd.host_work_area);
    FAPI_DBG("cmd_work_area   : 0x%08X", i_cmd.cmd_work_area);

    for (int i = 0; i < CMD_PADDING_SIZE; i++)
    {
        FAPI_DBG("padding[%d] : 0x%08X", i,  i_cmd.padding[i] ); //uint32_t padding[3];
    }

    // 28 bytes of command_argument data
    for (int i = 0; i < ARGUMENT_SIZE; i++)
    {
        FAPI_DBG("command_argument[%d]: 0x%02X", i, i_cmd.command_argument[i] );
    }

    FAPI_DBG("cmd_header_crc  : 0x%08X", i_cmd.cmd_header_crc    );   //uint32_t
}

/// @brief Debug function to trace explorer fw log response
/// @parm i_rsp - response from Explorer to Explorer FW log command
void trace_rsp(const host_fw_response_struct& i_rsp )
{
    FAPI_DBG("response_id          : 0x%02X",
             i_rsp.response_id            );           //uint8_t  response_id;             // Response ID - same as Command ID
    FAPI_DBG("response_flags       : 0x%02X",
             i_rsp.response_flags         );       //uint8_t  response_flags;          // Various flags associated with the response
    FAPI_DBG("request_identifier   : 0x%04X",
             i_rsp.request_identifier     );       //uint16_t request_identifier;      // The request identifier of this transport request
    FAPI_DBG("response_length      : 0x%08X",
             i_rsp.response_length        );       //uint32_t response_length;         // Number of bytes following the response header
    FAPI_DBG("response_crc         : 0x%08X",
             i_rsp.response_crc           );       //uint32_t response_crc;            // CRC of response data buffer, if used
    FAPI_DBG("host_work_area       : 0x%08X",
             i_rsp.host_work_area         );       //uint32_t host_work_area;          // Scratchpad area for Host, FW returns this value as a reponse

    for (int l_i = 0; l_i < RSP_PADDING_SIZE; l_i++)
    {
        FAPI_DBG("padding[%d]           : 0x%08X", l_i,
                 i_rsp.padding[l_i] );            //uint32_t padding[4];              // Fill up to the size of one cache line
    }

    for (int l_i = 0; l_i < ARGUMENT_SIZE; l_i++)
    {
        FAPI_DBG("response_argument[%d]: 0x%02X", l_i,
                 i_rsp.response_argument[l_i] ); //uint8_t  response_argument[28];   // Additional parameters associated with the response
    }

    FAPI_DBG("response_header_crc  : 0x%08X",
             i_rsp.response_header_crc    );   //uint32_t response_header_crc;     // CRC of 63 bytes of response header
}

/// See header
fapi2::ReturnCode build_log_cmd(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const exp_fw_log_cmd_parms_struct_t& i_cmd_parms,
    host_fw_command_struct& o_cmd )
{
    std::vector<uint8_t> l_data;

    memset(&o_cmd, 0, sizeof(host_fw_command_struct));

    // Issue EXP_FW_LOG cmd though EXP-FW REQ buffer
    o_cmd.cmd_id = mss::exp::omi::EXP_FW_LOG;

    // Host generated id number (returned in response packet)
    uint32_t l_counter = 0;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OCMB_COUNTER, i_target, l_counter));
    o_cmd.request_identifier = l_counter;
    o_cmd.cmd_crc = 0xffffffff; // no additional data in data buffer

    // Provide the command arguments
    // Copy i_cmd_params to command_argument data
    // NOTE: memcpy of i_cmd_params fails since params is in BE format
    o_cmd.command_argument[0] = i_cmd_parms.op;
    o_cmd.command_argument[1] = i_cmd_parms.image;

    // add offset argument in Explorer LE format
    FAPI_TRY(forceCrctEndian(i_cmd_parms.offset, l_data));
    memcpy(o_cmd.command_argument + 2, l_data.data(), sizeof(i_cmd_parms.offset));

    // add num_bytes argument in Explorer LE format
    l_data.clear(); // clear out previous data
    FAPI_TRY(forceCrctEndian(i_cmd_parms.num_bytes, l_data));
    memcpy(o_cmd.command_argument + (2 + sizeof(i_cmd_parms.offset)), l_data.data(), sizeof(i_cmd_parms.num_bytes));

    // trace command if debugging
    trace_cmd(o_cmd);

fapi_try_exit:
    return fapi2::current_err;
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

    // trace response if debugging
    trace_rsp(i_rsp);

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
