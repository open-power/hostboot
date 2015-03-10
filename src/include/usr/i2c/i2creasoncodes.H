/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/i2c/i2creasoncodes.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2015                        */
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
 * @file i2creasoncodes.H
 *
 * @brief Reason codes and module ids for the I2C device driver
 *
 */
#ifndef __I2CREASONCODES_H
#define __I2CREASONCODES_H
// -----------------------------------------------
// Includes
// -----------------------------------------------
#include <hbotcompid.H>

namespace I2C
{

/**
* @enum i2cModuleid
*
* @brief Module Ids used in created errorlogs.  Indicates which
*      functions an error log was created in.
*
*/
enum i2cModuleId
{
    I2C_INVALID_MODULE                  = 0x00,
    I2C_PERFORM_OP                      = 0x01,
    I2C_READ                            = 0x02,
    I2C_WRITE                           = 0x03,
    I2C_SETUP                           = 0x04,
    I2C_WAIT_FOR_CMD_COMP               = 0x05,
    I2C_READ_STATUS_REG                 = 0x06,
    I2C_CHECK_FOR_ERRORS                = 0x07,
    I2C_SETUP_MASTERS                   = 0x08,
    I2C_SEND_SLAVE_STOP                 = 0x09,
    I2C_PROCESS_ACTIVE_MASTERS          = 0x0A,
};


/**
 * @enum i2cReasonCode
 *
 * @brief Reasoncodes used to describe what errors are being indicated.
 *
 */
enum i2cReasonCode
{
    I2C_INVALID_REASONCODE              = I2C_COMP_ID | 0x00,   // Invalid Reasoncode
    I2C_INVALID_DATA_BUFFER             = I2C_COMP_ID | 0x01,   // Invalid Data Buffer pointer
    I2C_INVALID_OP_TYPE                 = I2C_COMP_ID | 0x02,   // Invalid Operation type
    I2C_FIFO_TIMEOUT                    = I2C_COMP_ID | 0x03,   // Timed out waiting on FIFO
    I2C_BUS_NOT_READY                   = I2C_COMP_ID | 0x04,   // Bus Not ready
    I2C_CMD_COMP_TIMEOUT                = I2C_COMP_ID | 0x05,   // Timeout waiting for Cmd Complete
    I2C_HW_ERROR_FOUND                  = I2C_COMP_ID | 0x06,   // Error found in status register
    I2C_MASTER_SENTINEL_TARGET          = I2C_COMP_ID | 0x07,   // Master Sentinel used as target
    I2C_NO_CENTAUR_FOUND                = I2C_COMP_ID | 0x08,   // No Centaur chip found
    I2C_NO_PROC_FOUND                   = I2C_COMP_ID | 0x09,   // No Processor chip found
    I2C_ATTRIBUTE_NOT_FOUND             = I2C_COMP_ID | 0x0A,   // Needed I2C-related Attribute not found
    I2C_NACK_ONLY_FOUND                 = I2C_COMP_ID | 0x0B,   // Only NACK found in status register
    I2C_ARBITRATION_LOST_ONLY_FOUND     = I2C_COMP_ID | 0x0C,   // Bus Arbi lost found in status reg
    I2C_RUNTIME_INTERFACE_ERR           = I2C_COMP_ID | 0x0D,   // Read/write unavailable at runtime
    I2C_RUNTIME_ERR                     = I2C_COMP_ID | 0x0E,   // Failed run-time operation
    I2C_RUNTIME_INVALID_OFFSET_LENGTH   = I2C_COMP_ID | 0x0F,   // Offset length of invalid size
};


enum UserDetailsTypes
{
        I2C_UDT_NO_FORMAT       = 0x0,
        I2C_UDT_PARAMETERS      = 0x1,
};

};  // end I2C

#endif
