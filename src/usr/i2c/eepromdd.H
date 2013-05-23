/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/eepromdd.H $                                      */
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
#ifndef __EEPROM_H
#define __EEPROM_H

/**
 * @file eepromdd.H
 *
 * @brief Provides the interfaces for accessing EEPROMs within
 *      the system via the I2C device driver.
 */

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <i2c/eepromif.H>
#include <errl/errlentry.H>

namespace EEPROM
{

/**
* @brief Enumerations to describe the type of devices to be accessed.
*/
typedef enum
{
    TWO_BYTE_ADDR,
    ONE_BYTE_ADDR,
    LAST_DEVICE_TYPE
} eeprom_device_t;

/**
 * @brief Structure of common parameters needed by different parts of
 *      the code.
 */
typedef struct
{
    uint64_t port;
    uint64_t engine;
    uint64_t devAddr;
    int64_t  chip;
    uint64_t offset;
    eeprom_device_t deviceType;
    TARGETING::EntityPath i2cMasterPath;
    uint64_t writePageSize;  // in bytes
    eeprom_chip_types_t chipTypeEnum;
} eeprom_addr_t;

/**
*
* @brief Perform an EEPROM access operation.
*
* @param[in] i_opType - Operation Type - See DeviceFW::OperationType in
*       driververif.H
*
* @param[in] i_target - Target device.
*
* @param[in/out] io_buffer
*       INPUT: Pointer to the data that will be  written to the target
*           device.
*       OUTPUT: Pointer to the data that was read from the target device.
*
* @param[in/out] io_buflen
*       INPUT: Length of the buffer to be written to target device.
*       OUTPUT: Length of buffer that was written, or length of buffer
*           to be read from target device.
*
* @param [in] i_accessType - Access Type - See DeviceFW::AccessType in
*       usrif.H
*
* @param [in] i_args - This is an argument list for the device driver
*       framework.  This argument list consists of the chip number of
*       the EEPROM to access from the given I2C Master target and the
*       internal offset to use on the slave I2C device.
*
* @return errlHndl_t - NULL if successful, otherwise a pointer to the
*       error log.
*
*/
errlHndl_t eepromPerformOp( DeviceFW::OperationType i_opType,
                            TARGETING::Target * i_target,
                            void * io_buffer,
                            size_t & io_buflen,
                            int64_t i_accessType,
                            va_list i_args );

/**
 * @brief This function peforms the sequencing to do a read of the
 *      EEPROM that is identified.
 *
 * @param[in] i_target - Target device.
 *
 * @param[out] o_buffer - The buffer that will return the data read
 *      from the EEPROM device.
 *
 * @param[in] i_buflen - Number of bytes to read from the EEPROM device.
 *
 * @param[in] i_i2cInfo - Structure of I2C parameters needed to execute
 *      the command to the I2C device driver.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t eepromRead ( TARGETING::Target * i_target,
                        void * o_buffer,
                        size_t i_buflen,
                        eeprom_addr_t i_i2cInfo );

/**
 * @brief This function peforms the sequencing to do a write of the
 *      EEPROM that is identified.
 *
 * @param[in] i_target - Target device.
 *
 * @param[in] io_buffer - The buffer that contains the data to be written
 *      to the EEPROM device.
 *
 * @param[in/out] io_buflen
*       INPUT: Length of the buffer to be written to target device.
*       OUTPUT: Length of buffer that was written, or length of buffer
*           to be read from target device.
 *
 * @param[in] i_i2cInfo - Structure of I2C parameters needed to execute
 *      the command to the I2C device driver.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t eepromWrite ( TARGETING::Target * i_target,
                         void * io_buffer,
                         size_t io_buflen,
                         eeprom_addr_t i_i2cInfo );

/**
 * @brief This function prepares the I2C byte address for adding to the
 *      existing buffer (for Writes), or as a separate write operation
 *      (for Reads).
 *
 * @param[out] o_buffer - The buffer to be written as a byte address to
 *      the EEPROM device.
 *
 * @param[out] o_bufSize - The size of the buffer to be written.
 *
 * @param[in] i_i2cInfo - Structure of I2C parameters needed to execute
 *      the command to the I2C device driver.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t eepromPrepareAddress ( void * o_buffer,
                                  size_t & o_bufSize,
                                  eeprom_addr_t i_i2cInfo );

/**
 * @brief this function will read all of the associated attributes needed
 *      to access the intended EEPROM.  These attributes will be used to
 *      determine the type of I2C device as well as how to address it via
 *      the I2C device driver.
 *
 * @param[in] i_target - Target device.
 *
 * @param[out] o_i2cInfo - The structure that will contain the attribute data
 *      read from the target device.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t eepromReadAttributes ( TARGETING::Target * i_target,
                                  eeprom_addr_t & o_i2cInfo );

/**
 * @brief This function decides whether or not the target passed into the
 *      EEPROM device driver actually contains the I2C Master engines.  If
 *      not, it will then read the attribute of the target to get the path
 *      of the target which does contain the I2C Master engine.
 *
 * @param[in] i_target - The current Target.
 *
 * @param[in] i_i2cInfo - Structure of I2C parameters needed to execute
 *      the command to the I2C device driver.
 *
 * @param[out] o_target - The "new" target that will be used for all operations
 *      from this point on.  It may be == to i_target, or a completely different
 *      target.  BUT, this target will contain the I2C Master engine that will
 *      allow operations to the target EEPROM.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t eepromGetI2CMasterTarget ( TARGETING::Target * i_target,
                                      eeprom_addr_t i_i2cInfo,
                                      TARGETING::Target * &o_target );

}; // end EEPROM namespace

#endif  // __EEPROM_H
