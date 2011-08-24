//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/i2c/i2creasoncodes.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
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
    I2C_PERFORM_OP                          = 0x01,
};

/**
 * @enum i2cReasonCode
 *
 * @brief Reasoncodes used to describe what errors are being indicated.
 *
 */
enum i2cReasonCode
{
    I2C_INVALID_DATA_BUFFER                 = I2C_COMP_ID | 0x01,
    I2C_INVALID_OP_TYPE                     = I2C_COMP_ID | 0x02,

};

};  // end I2C

#endif
