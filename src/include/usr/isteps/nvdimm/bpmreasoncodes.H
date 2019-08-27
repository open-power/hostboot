/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/nvdimm/bpmreasoncodes.H $              */
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
/**
 *  @file bpmreasoncode.H
 *
 *  @brief Reason codes and module ids for the BPM
 */
#ifndef __BPMREASONCODES_H
#define __BPMREASONCODES_H

#include <hbotcompid.H>

namespace BPM_RC
{

    enum bpmModuleId
    {
        BPM_ISSUE_COMMAND                   = 0x00,
        BPM_IN_UPDATE_MODE                  = 0x01,
        BPM_UPDATE_FIRMWARE                 = 0x02,
        BPM_ENTER_BSL_MODE                  = 0x03,
        BPM_SETUP_PAYLOAD                   = 0x04,
        BPM_DUMP_SEGMENT                    = 0x05,
        BPM_DISABLE_WRITE_PROTECTION        = 0x06,
        BPM_WRITE_MAGIC_REG                 = 0x07,
        BPM_GET_RESPONSE                    = 0x08,
        BPM_RETRY_BLOCK_WRITE               = 0x09,
        BPM_WAIT_FOR_CMD_BIT_RESET          = 0x0A,
        BPM_WAIT_FOR_BUSY_BIT_RESET         = 0x0B,
        BPM_CHECK_FIRMWARE_CRC              = 0x0C,
        BPM_VERIFY_GOOD_BPM_STATE           = 0x0D,
        BPM_RUN_FW_UPDATES                  = 0x0F,
        BPM_WRITE_VIA_SCAP                  = 0x10,
        BPM_BLOCK_WRITE                     = 0x11,
        BPM_RUN_UPDATE                      = 0x12,
        BPM_START_UPDATE                    = 0xFD,
        BPM_END_UPDATE                      = 0xFE,
        BPM_DUMMY_ERROR                     = 0xFF,
    };

    enum bpmReasonCode
    {
        BPM_INVALID_PAYLOAD_SIZE            = BPM_COMP_ID | 0x00,
        BPM_UPDATE_MODE_VERIFICATION_FAIL   = BPM_COMP_ID | 0x01,
        BPM_RESET_VECTOR_NEVER_RECEIVED     = BPM_COMP_ID | 0x02,
        BPM_FAILED_TO_ENTER_BSL_MODE        = BPM_COMP_ID | 0x03,
        BPM_INVALID_PAYLOAD_DATA_SIZE       = BPM_COMP_ID | 0x04,
        BPM_BSL_MODE_ENABLED                = BPM_COMP_ID | 0x05,
        BPM_DISABLE_WRITE_PROTECTION_FAILED = BPM_COMP_ID | 0x06,
        BPM_WRITE_TO_MAGIC_REG_FAILED       = BPM_COMP_ID | 0x07,
        BPM_RESPONSE_CRC_MISMATCH           = BPM_COMP_ID | 0x08,
        BPM_EXCEEDED_RETRY_LIMIT            = BPM_COMP_ID | 0x09,
        BPM_CMD_STATUS_ERROR_BIT_SET        = BPM_COMP_ID | 0x0A,
        BPM_FIRMWARE_CRC_VERIFY_FAILURE     = BPM_COMP_ID | 0x0B,
        BPM_VERSION_MISMATCH                = BPM_COMP_ID | 0x0C,
        BPM_EXCEEDED_RETRY_LIMIT_REG        = BPM_COMP_ID | 0x0D,
        BPM_EXCEEDED_RETRY_LIMIT_DATA       = BPM_COMP_ID | 0x0E,
        BPM_BAD_RESPONSE                    = BPM_COMP_ID | 0x0F,
        BPM_UPDATE_SUCCESSFUL               = BPM_COMP_ID | 0xFC,
        BPM_ENTER_UPDATE_MODE               = BPM_COMP_ID | 0xFD,
        BPM_EXIT_UPDATE_MODE                = BPM_COMP_ID | 0xFE,
        BPM_DUMMY_REASONCODE                = BPM_COMP_ID | 0xFF,
    };

};


#endif
