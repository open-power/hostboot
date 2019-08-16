/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/inband/exp_fw_log.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
/// @file exp_fw_log.H
/// @brief Helpers to access explorer firmware logs
///        The Explorer firmware modules log pertinent data regarding
///        operations and errors, and the Host manages and accesses this
///        information by using the EXP_FW_LOG API command. The firmware
///        maintains the log in a circular buffer in RAM and in the event
///        of a processor exception, firmware assert, or other critical
///        condition the firmware saves the data in RAM to SPI flash.
///        Having the log stored in non-volatile memory allows post-analysis
///        of the log even if it requires a power-cycle to recover the system.
///
// *HWP HWP Owner: Matt Derksen <mderkse1@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef __MSS_EXP_FW_LOG__
#define __MSS_EXP_FW_LOG__

#include <fapi2.H>
#include <vector>
#include <exp_data_structs.H>

namespace mss
{
namespace exp
{
namespace ib
{
///
/// @brief Defines the sub-commands available for the
///        EXP_FW_LOG command
///
enum exp_log_sub_cmd_op
{
    // This is used to read log entries from the active
    // firmware logfile stored in Explorer RAM
    SUB_CMD_READ_ACTIVE_LOG             = 0x01,

    // This is used to read log entries from the saved
    // firmware logfile stored in Explorer SPI flash
    SUB_CMD_READ_SAVED_LOG              = 0x02,

    // This is used to clear the active logfile in Explorer RAM
    SUB_CMD_CLEAR_ACTIVE_LOG            = 0x03,

    // This is used to erase the saved logfile in Explorer SPI flash
    SUB_CMD_ERASE_SAVED_LOG             = 0x04,
};

///
/// @brief Sets the command_argument fields for EXP_FW_LOG command
///
/// @param[in] i_target - OCMB target
/// @param[in] i_sub_op - what sub-command of EXP_FW_LOG to use
/// @param[out] o_cmd   - command packet to update
///
void build_log_cmd(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                   const exp_log_sub_cmd_op i_sub_op,
                   host_fw_command_struct& o_cmd );


///
/// @brief Checks the response of the EXP_FW_LOG command
///
/// @param[in]  i_target - OCMB target
/// @param[in]  i_rsp    - response portion of EXP_FW_ERROR_LOG (from getRsp())
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode check_log_cmd_response(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const host_fw_response_struct& i_rsp );

}//exp
}//mss
}//ib

#endif
