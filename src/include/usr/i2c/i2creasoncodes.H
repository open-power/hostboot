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
