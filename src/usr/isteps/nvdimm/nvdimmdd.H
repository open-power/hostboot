/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/nvdimm/nvdimmdd.H $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
#ifndef __NVDIMMDD_H
#define __NVDIMMDD_H

/**
 * @file nvdimmdd.H
 *
 * @brief Provides the interfaces for accessing NVDIMMs within
 *      the system via the I2C device driver.
 */

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <errl/errlentry.H>
#include <usr/devicefw/driverif.H>  // I2C_MUX::NOT_APPLICABLE

namespace NVDIMM
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
} nvdimm_addr_size_t;

/**
 * @brief Structure of common parameters needed by different parts of
 *      the code.
 */
struct nvdimm_addr_t
{
    uint64_t port;
    uint64_t engine;
    uint64_t devAddr;
    uint64_t offset;
    nvdimm_addr_size_t addrSize;
    TARGETING::EntityPath i2cMasterPath;
    uint64_t writePageSize;  // in bytes
    uint64_t devSize_KB;     // in kilobytes
    uint64_t chipCount;      // number of chips making up nvdimm device
    uint64_t writeCycleTime;  // in milliseconds
    uint8_t  i2cMuxBusSelector;
    TARGETING::EntityPath i2cMuxPath;

    /**
     *  @brief Construct a default nvdimm_addr_t
     */
    nvdimm_addr_t()
        : port(0),
          engine(0),
          devAddr(0),
          offset(0),
          addrSize(LAST_DEVICE_TYPE),
          i2cMasterPath(),
          writePageSize(0),
          devSize_KB(0),
          chipCount(0),
          writeCycleTime(0),
          i2cMuxBusSelector(I2C_MUX::NOT_APPLICABLE),
          i2cMuxPath()
    {
    }
};

/*
 * @brief Miscellaneous enums for NVDIMM
 */
enum
{
    NVDIMM_PAGE_SIZE = 0x100,
    NVDIMM_DEVADDR_INC = 2
};

/**
*
* @brief Perform an NVDIMM access operation.
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
*       framework.  This argument list consists of the internal offset
*       to use on the slave I2C device.
*
* @return errlHndl_t - NULL if successful, otherwise a pointer to the
*       error log.
*
*/
errlHndl_t nvdimmPerformOp( DeviceFW::OperationType i_opType,
                            TARGETING::Target * i_target,
                            void * io_buffer,
                            size_t & io_buflen,
                            int64_t i_accessType,
                            va_list i_args );

/*
 * @brief On the NV Controller, the page is selected by writing to offset
 *        0x00 with the page you would like to switch too. e.g. to activate
 *        page 1, write 0x01 to offset 0x00. The user will need to select
 *        the page as appropriate.
 *        Each page contains 256 offsets (0xFF). This function checks if
 *        the offset is outside of 0xFF boundary.
 *
 * @param[in] i_offset - The requested read/write offset to the NVDIMM.
 *          crossed over into the second NVDIMM page.
 * @param[in] i_buflen - The requested length of the data.
 *
 * @return bool - True if the requested data straddles the NVDIMM page
 *          boundary, False otherwise. If False, io_newLen == i_originalLen.
 */
errlHndl_t crossesNvdimmPageBoundary( uint64_t i_offset,
                                      size_t i_buflen );


/**
 * @brief This function peforms the sequencing to do a read of the
 *      NVDIMM that is identified.
 *
 * @param[in] i_target - Target device.
 *
 * @param[out] o_buffer - The buffer that will return the data read
 *      from the NVDIMM device.
 *
 * @param[in] i_buflen - Number of bytes to read from the NVDIMM device.
 *
 * @param[in] i_i2cInfo - Structure of I2C parameters needed to execute
 *      the command to the I2C device driver.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t nvdimmRead ( TARGETING::Target * i_target,
                        void * o_buffer,
                        size_t i_buflen,
                        nvdimm_addr_t i_i2cInfo );


/**
 * @brief This function actually performs the i2c operations to read data from
 *        the NVDIMM
 *
 * @param[in] i_target - Target device
 *
 * @param[out] o_buffer - the buffer that will return the data read from
 *                    the nvdimm device
 *
 * @param[in] i_buflen - Number of bytes read from the NVDIMM device
 *
 * @param[in] i_byteAddress - the offset into the NVDIMM device
 *
 * @param[in] i_byteAddressSize - the size of the byte address (1 or 2 bytes)
 *
 * @param[in] i_i2cInfo - Structure of I2C parameters needed to execute the
 *      command to the I2C device driver
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the
 *       error log.
 */
errlHndl_t nvdimmReadData( TARGETING::Target * i_target,
                           void * o_buffer,
                           size_t i_buflen,
                           void * i_byteAddress,
                           size_t i_byteAddressSize,
                           nvdimm_addr_t i_i2cInfo );



/**
 * @brief This function peforms the sequencing to do a write of the
 *      NVDIMM that is identified.
 *
 * @param[in] i_target - Target device.
 *
 * @param[in] io_buffer - The buffer that contains the data to be written
 *      to the NVDIMM device.
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
errlHndl_t nvdimmWrite ( TARGETING::Target * i_target,
                         void * io_buffer,
                         size_t & io_buflen,
                         nvdimm_addr_t i_i2cInfo );



/**
 * @brief This function actually writes data into the devices NVDIMM
 *
 * @param[in] i_target - Target device.
 * @param[in] i_dataToWrite - The data to be written into the device.
 * @param[in] i_dataLen - The length of the data to be written.
 * @param[in] i_byteAddress - the offset into the devices NVDIMM.
 * @param[in] i_byteAddressSize - the size of byte address varable.
 * @param[in] i_i2cInfo - Structure of I2C parameters needed to execute
 *      the command to the I2C device driver.
 */
errlHndl_t nvdimmWriteData( TARGETING::Target * i_target,
                            void * i_dataToWrite,
                            size_t i_dataLen,
                            void * i_byteAddress,
                            size_t i_byteAddressSize,
                            nvdimm_addr_t i_i2cInfo );


/**
 * @brief This function prepares the I2C byte address for adding to the
 *      existing buffer (for Writes), or as a separate write operation
 *      (for Reads).
 *
 * @param[in] i_target - the target to prepare the addressing for.
 *
 * @param[in/out] io_buffer - The buffer to be written as a byte address to
 *      the NVDIMM device.  Must be pre-allocated to MAX_BYTE_ADDR size.
 *
 * @param[out] o_bufSize - The size of the buffer to be written.
 *
 * @param[in] i_i2cInfo - Structure of I2C parameters needed to execute
 *      the command to the I2C device driver.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t nvdimmPrepareAddress ( TARGETING::Target * i_target,
                                  void * io_buffer,
                                  size_t & o_bufSize,
                                  nvdimm_addr_t i_i2cInfo);

/**
 * @brief this function will read all of the associated attributes needed
 *      to access the intended NVDIMM.  These attributes will be used to
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
errlHndl_t nvdimmReadAttributes ( TARGETING::Target * i_target,
                                  nvdimm_addr_t & o_i2cInfo );

/**
 * @brief This function decides whether or not the target passed into the
 *      NVDIMM device driver actually contains the I2C Master engines.  If
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
 *      allow operations to the target NVDIMM.
 *
 * @return errlHndl_t - NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t nvdimmGetI2CMasterTarget ( TARGETING::Target * i_target,
                                      nvdimm_addr_t i_i2cInfo,
                                      TARGETING::Target * &o_target );

}; // end NVDIMM namespace

#endif  // __NVDIMMDD_H
