/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/i2c/i2creasoncodes.H $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2022                        */
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
    I2C_FORCE_RESET_AND_UNLOCK          = 0x0B,
    I2C_PAGE_SWITCH_OP                  = 0x0C,
    I2C_PAGE_UNLOCK_OP                  = 0x0D,
    I2C_CHOOSE_EEPROM_PAGE              = 0x0E,
    FAPI_I2C_PERFORM_OP                 = 0x0F,
    READ_I2C_ATTRIBUTES                 = 0x10,
    I2C_ACCESS_MUX                      = 0x11,
    I2C_GENERIC_PRES_DETECT             = 0x12,
    I2C_BAD_PEC_BYTE_ERROR              = 0x13,
    RT_I2C_PERFORM_OP                   = 0x14,
};

/**
 * @enum i2cReasonCode
 *
 * @brief Reasoncodes used to describe what errors are being indicated.
 *
 */
enum i2cReasonCode
{
    I2C_INVALID_REASONCODE                = I2C_COMP_ID | 0x00,   // Invalid Reasoncode
    I2C_INVALID_DATA_BUFFER               = I2C_COMP_ID | 0x01,   // Invalid Data Buffer pointer
    I2C_INVALID_OP_TYPE                   = I2C_COMP_ID | 0x02,   // Invalid Operation type
    I2C_FIFO_TIMEOUT                      = I2C_COMP_ID | 0x03,   // Timed out waiting on FIFO
    I2C_BUS_NOT_READY                     = I2C_COMP_ID | 0x04,   // Bus Not ready
    I2C_CMD_COMP_TIMEOUT                  = I2C_COMP_ID | 0x05,   // Timeout waiting for Cmd Complete
    I2C_HW_ERROR_FOUND                    = I2C_COMP_ID | 0x06,   // Error found in status register
    I2C_MASTER_SENTINEL_TARGET            = I2C_COMP_ID | 0x07,   // Master Sentinel used as target
    // 0x08 Unused
    I2C_NO_PROC_FOUND                     = I2C_COMP_ID | 0x09,   // No Processor chip found
    I2C_ATTRIBUTE_NOT_FOUND               = I2C_COMP_ID | 0x0A,   // Needed I2C-related Attribute not found
    I2C_NACK_ONLY_FOUND                   = I2C_COMP_ID | 0x0B,   // Only NACK found in status register
    I2C_ARBITRATION_LOST_ONLY_FOUND       = I2C_COMP_ID | 0x0C,   // Bus Arbi lost found in status reg
    I2C_RUNTIME_INTERFACE_ERR             = I2C_COMP_ID | 0x0D,   // Read/write unavailable at runtime
    I2C_RUNTIME_ERR                       = I2C_COMP_ID | 0x0E,   // Failed run-time operation
    I2C_RUNTIME_INVALID_OFFSET_LENGTH     = I2C_COMP_ID | 0x0F,   // Offset length of invalid size
    I2C_INVALID_EEPROM_PAGE_MUTEX         = I2C_COMP_ID | 0x10,   // Error getting page mutex for i2c engine.
    I2C_INVALID_EEPROM_PAGE_REQUEST       = I2C_COMP_ID | 0x11,   // Invalid EEPROM page request
    I2C_FAILURE_UNLOCKING_EEPROM_PAGE     = I2C_COMP_ID | 0x12,   // Error while attempting to unlock the eeprom page
    INVALID_MASTER_TARGET                 = I2C_COMP_ID | 0x13,   // Master I2C target not valid
    I2C_MUX_TARGET_NOT_FOUND              = I2C_COMP_ID | 0x14,   // The MUX target is not valid (null)
    I2C_MUX_TARGET_NON_FUNCTIONAL         = I2C_COMP_ID | 0x15,   // The MUX target is non functional
    I2C_INVALID_LENGTH                    = I2C_COMP_ID | 0x16,   // Invalid data buffer length passed to function
    I2C_NULL_MASTER_TARGET                = I2C_COMP_ID | 0x17,   // Target Service's toPath() returned nullptr for target
    I2C_INVALID_SEND_BYTE_LENGTH          = I2C_COMP_ID | 0x18,   // Invalid send byte length
    I2C_INVALID_WRITE_BYTE_OR_WORD_LENGTH = I2C_COMP_ID | 0x19,   // Invalid write byte/word length
    I2C_INVALID_BLOCK_WRITE_LENGTH        = I2C_COMP_ID | 0x1A,   // Invalid block write length
    I2C_INVALID_READ_BYTE_OR_WORD_LENGTH  = I2C_COMP_ID | 0x1B,   // Invalid read byte/word length
    I2C_INVALID_BLOCK_READ_LENGTH         = I2C_COMP_ID | 0x1C,   // Invalid block read length
    I2C_BAD_PEC_BYTE                      = I2C_COMP_ID | 0x1D,   // Bad PEC byte
    I2C_RUNTIME_INVALID_PAGE_OP_BUFFER    = I2C_COMP_ID | 0x1E,   // non-empty buffer when performing a page op at runtime
};


enum UserDetailsTypes
{
        I2C_UDT_NO_FORMAT       = 0x0,
        I2C_UDT_PARAMETERS      = 0x1,
};

};  // end I2C

//*****************************************************
// SRC Graveyard
// Contains error log descriptions for SRCs that were
// removed from the code but we need to still provide
// backward compatible parser logic for.

/*@
* @errortype
* @moduleid     I2C_PERFORM_OP
* @reasoncode   I2C_RUNTIME_INTERFACE_ERR
* @userdata1    0
* @userdata2    Op type
* @devdesc      I2C read/write interface not linked.
* @custdesc     An internal firmware error occurred
*/

/*@
* @errortype
* @moduleid     I2C_PERFORM_OP
* @reasoncode   I2C_RUNTIME_ERR
* @userdata1    Hypervisor return code
* @userdata2    Op type
* @devdesc      I2C access error
* @custdesc     Hardware access error
*/

#endif
