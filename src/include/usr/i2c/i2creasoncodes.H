/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/i2c/i2creasoncodes.H $                        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
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
    I2C_SET_BUS_VARIABLES               = 0x09,
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
    I2C_HW_ERROR_FOUND                  = I2C_COMP_ID | 0x06,   // Error found in Status register
    I2C_MASTER_SENTINEL_TARGET          = I2C_COMP_ID | 0x07,   // Master Sentinel used as target
    I2C_NO_CENTAUR_FOUND                = I2C_COMP_ID | 0x08,   // No Centaur chip found
    I2C_NO_PROC_FOUND                   = I2C_COMP_ID | 0x09,   // No Processor chip found
    I2C_INVALID_BUS_SPEED_MODE          = I2C_COMP_ID | 0x0A,   // Invalid Bus Speed Mode
};

};  // end I2C

#endif
