/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/i2c/eepromddreasoncodes.H $                   */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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
    EEPROM_DIMM_I2C_MASTER_PATH_ERROR       = EEPROM_COMP_ID | 0x05,
    EEPROM_TARGET_NULL                      = EEPROM_COMP_ID | 0x06,
    EEPROM_INVALID_ADDR_OFFSET_SIZE         = EEPROM_COMP_ID | 0x07,
    EEPROM_OVERFLOW_ERROR                   = EEPROM_COMP_ID | 0x08,
};

enum UserDetailsTypes
{
        EEPROM_UDT_NO_FORMAT       = 0x0,
        EEPROM_UDT_PARAMETERS      = 0x1,
};

};  // end EEPROM

#endif
