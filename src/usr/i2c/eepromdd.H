/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/eepromdd.H $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2016                        */
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
    ZERO_BYTE_ADDR             = 0,
    ONE_BYTE_ADDR_PAGESELECT   = 1,  // page select
    TWO_BYTE_ADDR              = 2,
    ONE_BYTE_ADDR              = 3,
    LAST_DEVICE_TYPE
} eeprom_addr_size_t;

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
    eeprom_addr_size_t addrSize;
    TARGETING::EntityPath i2cMasterPath;
    uint64_t writePageSize;  // in bytes
    uint64_t devSize_KB;     // in kilobytes
    uint64_t writeCycleTime;  // in milliseconds
} eeprom_addr_t;

/*
 * @brief Miscellaneous enums for EEPROM
 */
enum
{
    EEPROM_PAGE_SIZE = 0x100
};

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
 *
 * @brief Perform operations to lock and unlock the page mutex
 *
 * @param[in] i_target - the target to lock the page for
 * @param[in] i_switchPage - bool to tell the function whether we are
 *      trying to switch pages/locking vs unlocking the page
 * @param[in] i_lockMutex - bool to inform call chain whether we want
 *              to actually lock the page mutex or not. When false,
 *              the function assumes the appropriate mutex has already
 *              been locked and skips the call to mutex_lock
 * @param[in/out] i_pageLocked - bool to tell the caller if the page
 *      was successfully locked.
 * @param[in] i_desiredPage - The page we want to switch to
 * @param[in] i_args - This is an argument list for the device driver
 *      framework.  This argument list consists of the chip number of
 *      the EEPROM to access from the given I2C Master target and the
 *      internal offset to use on the slave I2C device.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t eepromPageOp( TARGETING::Target * i_target,
                         bool i_switchPage,
                         bool i_lockMutex,
                         bool & io_pageLocked,
                         uint8_t i_desiredPage,
                         eeprom_addr_t i_i2cInfo );


/*
 * @brief This utility function determines if a read/write straddles
 *        the boundary between EEPROM pages and if so, returns the
 *        parameters to perform 2 operations, one for each page.
 *
 * @param[in] i_originalOffset - The requested read/write offset into
 *          the EEPROM.
 * @param[in] i_originalLen - The requested length of the data.
 * @param[in/out] io_newLen - The length of the data to retrieve
 * @param[out] o_pageTwoBuflen - The length of data requested that
 *          crossed over into the second EEPROM page.
 * @param[in] i_i2cInfo - Structure of I2C parameters needed to determine
 *             if we run the body of this function.

 * @return bool - True if the requested data straddles the EEPROM page
 *          boundary, False otherwise. If False, io_newLen == i_originalLen.
 */
bool crossesEepromPageBoundary( uint64_t i_originalOffset,
                                 size_t i_originalLen,
                                 size_t & io_newLen,
                                 size_t & o_pageTwoBuflen,
                                 eeprom_addr_t i_i2cInfo );


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
 * @brief This function actually performs the i2c operations to read data from
 *        the EEPROM
 *
 * @param[in] i_target - Target device
 *
 * @param[out] o_buffer - the buffer that will return the data read from
 *                    the eeprom device
 *
 * @param[in] i_buflen - Number of bytes read from the EEPROM device
 *
 * @param[in] i_byteAddress - the offset into the EEPROM device
 *
 * @param[in] i_byteAddressSize - the size of the byte address (1 or 2 bytes)
 *
 * @param[in] i_i2cInfo - Structure of I2C parameters needed to execute the
 *      command to the I2C device driver
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the
 *       error log.
 */
errlHndl_t eepromReadData( TARGETING::Target * i_target,
                           void * o_buffer,
                           size_t i_buflen,
                           void * i_byteAddress,
                           size_t i_byteAddressSize,
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
                         size_t & io_buflen,
                         eeprom_addr_t i_i2cInfo );



/**
 * @brief This function actually writes data into the devices EEPROM
 *
 * @param[in] i_target - Target device.
 * @param[in] i_dataToWrite - The data to be written into the device.
 * @param[in] i_dataLen - The length of the data to be written.
 * @param[in] i_byteAddress - the offset into the devices EEPROM.
 * @param[in] i_byteAddressSize - the size of byte address varable.
 * @param[in] i_i2cInfo - Structure of I2C parameters needed to execute
 *      the command to the I2C device driver.
 */
errlHndl_t eepromWriteData( TARGETING::Target * i_target,
                            void * i_dataToWrite,
                            size_t i_dataLen,
                            void * i_byteAddress,
                            size_t i_byteAddressSize,
                            eeprom_addr_t i_i2cInfo );


/**
 * @brief This function prepares the I2C byte address for adding to the
 *      existing buffer (for Writes), or as a separate write operation
 *      (for Reads).
 *
 * @param[in] i_target - the target to prepare the addressing for.
 *
 * @param[in/out] io_buffer - The buffer to be written as a byte address to
 *      the EEPROM device.  Must be pre-allocated to MAX_BYTE_ADDR size.
 *
 * @param[out] o_bufSize - The size of the buffer to be written.
 *
 * @param[out] o_desiredPage - The page we want to switch to.
 *
 * @param[in] i_i2cInfo - Structure of I2C parameters needed to execute
 *      the command to the I2C device driver.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t eepromPrepareAddress ( TARGETING::Target * i_target,
                                  void * io_buffer,
                                  size_t & o_bufSize,
                                  uint8_t & o_desiredPage,
                                  eeprom_addr_t i_i2cInfo);

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
