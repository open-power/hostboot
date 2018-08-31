/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/shared/exp_consts.H $ */
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
/// @file explorer_check_for_ready.H
/// @brief explorer_check_for_ready HWP declaration
///
// *HWP HWP Owner: Andre A. Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: CI

#ifndef EXP_CONSTS_H
#define EXP_CONSTS_H

namespace mss
{
namespace exp
{

///
/// @brief explorer ffdc codes
///
enum ffdc_codes
{
    EXP_I2C_GET_FIELD = 0x0000,
    EXP_I2C_SET_FIELD = 0x0001,
    READ_HOST_FW_RESPONSE_STRUCT = 0x0003,
};

namespace i2c
{

/// @brief List of explorer I2C commands
///
enum cmd_id : uint8_t
{
    FW_BOOT_CONFIG     = 0x01,
    FW_STATUS          = 0x02,
    FW_REG_ADDR_LATCH  = 0x03,
    FW_REG_READ        = 0x04,
    FW_REG_WRITE       = 0x05,
    FW_DOWNLOAD        = 0x06,
    FW_CONT_REG_READ   = 0x07,
    FW_CONT_REG_WRITE  = 0x08,
};

///
/// @brief common explorer sizes
///
enum sizes
{
    // 32-bit commands
    FW_BOOT_CONFIG_BYTE_LEN = 4,
    FW_STATUS_BYTE_LEN      = 4,

    // Largest R/W length for bytes of data
    MIN_DATA_BYTES_LEN = 1,
    MAX_DATA_BYTES_LEN = 32,
};

///
/// @brief General I2C status codes
/// @note Shared I2C status codes for EXP_FW_REG_READ, EXP_FW_REG_WRITE,
/// EXP_FW_CONT_REG_READ, and EXP_FW_CONT_REG_WRITE
///
enum status_codes
{
    SUCCESS              = 0x00,
    ADDRESS_OUT_OF_RANGE = 0x01,
    ADDRESS_PROHIBITED   = 0x02,
};

///
/// @brief status codes for FW_BOOT_CONFIG
///
enum fw_boot_cfg_status
{
    FW_BOOT_CFG_SUCCESS                 = status_codes::SUCCESS,

    // Loopback fail
    FW_BOOT_CFG_LB_FAIL                 = 0x01,
    // Transport layer fail
    FW_BOOT_CFG_UNSUPPORTED_TL          = 0x02,
    // DL (data link) layer fail
    FW_BOOT_CFG_UNSUPPORTED_DL          = 0x03,
    // SERDES (serializer/deserializer) FREQ fail
    FW_BOOT_CFG_UNSUPPORTED_SERDES_FREQ = 0x04,
};

///
/// @brief I2C boot stage options
/// @note certain cmds work in certain boot stages
///
enum boot_stages
{
    BOOT_ROM_STAGE  = 0x01,
    FW_UPGRADE_MODE = 0x02,
    RUNTIME_FW      = 0x03,
};
}// i2c
}// exp
}// mss

#endif
