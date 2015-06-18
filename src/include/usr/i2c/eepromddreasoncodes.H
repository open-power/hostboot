/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/i2c/eepromddreasoncodes.H $                   */
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
 * @file eepromddreasoncodes.H
 *
 * @brief Reason codes and module ids for the EEPROM device driver
 *
 */
#ifndef __EEPROMDDREASONCODES_H
#define __EEPROMDDREASONCODES_H
// -----------------------------------------------
// Includes
// -----------------------------------------------
#include <hbotcompid.H>

namespace EEPROM
{

/**
* @enum eepromModuleid
*
* @brief Module Ids used in created errorlogs.  Indicates which
*      functions an error log was created in.
*
*/
enum eepromModuleId
{
    EEPROM_INVALID_MODULE                   = 0x00,     // Invalid Module Id
    EEPROM_PERFORM_OP                       = 0x01,
    EEPROM_READ                             = 0x02,
    EEPROM_WRITE                            = 0x03,
    EEPROM_PREPAREADDRESS                   = 0x04,
    EEPROM_READATTRIBUTES                   = 0x05,
    EEPROM_GETI2CMASTERTARGET               = 0x06,
};

/**
 * @enum eepromReasonCode
 *
 * @brief Reasoncodes used to describe what errors are being indicated.
 *
 */
enum eepromReasonCode
{
    EEPROM_INVALID_REASONCODE               = EEPROM_COMP_ID | 0x00,   // Invalid Reasoncode
    EEPROM_INVALID_OPERATION                = EEPROM_COMP_ID | 0x01,
    EEPROM_INVALID_DEVICE_TYPE              = EEPROM_COMP_ID | 0x02,
    EEPROM_ATTR_INFO_NOT_FOUND              = EEPROM_COMP_ID | 0x03,
    EEPROM_INVALID_CHIP                     = EEPROM_COMP_ID | 0x04,
    EEPROM_I2C_MASTER_PATH_ERROR            = EEPROM_COMP_ID | 0x05,
    EEPROM_TARGET_NULL                      = EEPROM_COMP_ID | 0x06,
    EEPROM_INVALID_ADDR_OFFSET_SIZE         = EEPROM_COMP_ID | 0x07,
    EEPROM_OVERFLOW_ERROR                   = EEPROM_COMP_ID | 0x08,
    EEPROM_I2C_WRITE_PAGE_SIZE_ZERO         = EEPROM_COMP_ID | 0x09,
};

enum UserDetailsTypes
{
        EEPROM_UDT_NO_FORMAT       = 0x0,
        EEPROM_UDT_PARAMETERS      = 0x1,
};

};  // end EEPROM

#endif
