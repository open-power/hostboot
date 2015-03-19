/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/i2c/tpmdd.H $                                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
#ifndef __TPMDD_H
#define __TPMDD_H

/**
 * @file tpmdd.H
 *
 * @brief Provides the interfaces for accessing TPMs within
 *      the system via the I2C device driver.
 */

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <i2c/tpmddif.H>
#include <errl/errlentry.H>

namespace TPMDD
{

/**
* @brief Enumerations to describe the type of devices to be accessed.
*/
enum tpm_addr_size_t
{
    ONE_BYTE_ADDR   = 1,
    TWO_BYTE_ADDR   = 2,
    LAST_DEVICE_TYPE
};

/// TPM Timeouts listed in ms
/// Timeout names and durations are as described in the TCG specification
enum tpm_timeouts
{
    TPM_TIMEOUT_A = 750, ///< 750ms
    TPM_TIMEOUT_B = 2000, ///< 2000ms
    TPM_TIMEOUT_C = 750, ///< 750ms
    TPM_TIMEOUT_D = 750, ///< 750ms
};

/// TPM Driver values
enum
{
    MAX_STSVALID_POLLS = 5, ///< Max poll of 50ms (5*10ms)
};

/**
 * @brief Structure of common parameters needed by different parts of
 *      the code.
 */
struct tpm_info_t
{
    tpm_op_types_t operation;    ///< TPM operation to perform
    uint64_t port;               ///< I2C Master port
    uint64_t engine;             ///< I2C Master engin
    tpm_addr_size_t addrSize;    ///< I2C Addr size
    TARGETING::EntityPath i2cMasterPath; ///< I2C Master path
    TARGETING::Target * i2cTarget; ///< I2C Target

    uint8_t  chip;               ///< Chip target, primary/backup
    uint8_t  tpmEnabled;         ///< Is this TPM available and functional?
    uint8_t  devAddr;            ///< I2C Address
    size_t offset;               ///< TPM Device register offset
};



#ifdef CONFIG_TPM_NUVOTON
#ifdef CONFIG_TPMDD_1_2
/**
 * @brief Nuvoton 1.2 TPM definitions
 */
enum nuvo_12_defs_t
{
    I2C_REG_STS        = 0x0,
    I2C_REG_BURSTCOUNT = 0x1,
    I2C_REG_WR_FIFO    = 0x20,
    I2C_REG_RD_FIFO    = 0x40,
    I2C_REG_VENDOR     = 0x60,

    TPM_VENDORID       = 0x5010FE00,
    TPM_MAXBURSTSIZE   = 32,  ///< Max size to transfer in one i2c op
};
#endif
#endif

#ifdef CONFIG_TPMDD_1_2
/**
* @brief TPM STS register definition (TIS 1.2 Spec)
*/
union tpm_sts_reg_t
{
    uint8_t value;
    struct
    {
        uint8_t stsValid       : 1; // 00 // RO
        uint8_t isCommandReady : 1; // 01 // RW
        uint8_t tpmGo          : 1; // 02 // WO
        uint8_t dataAvail      : 1; // 03 // RO
        uint8_t expect         : 1; // 04 // RO
        uint8_t rsvd1          : 1; // 05 // RO
        uint8_t responseRetry  : 1; // 06 // WO
        uint8_t rsvd2          : 1; // 07 // RO
    } PACKED;
};
#endif



/**
*
* @brief Perform an TPM access operation.
*
* @param[in] i_opType Operation Type - See DeviceFW::OperationType in
*       driververif.H
*
* @param[in] i_target target node.
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
* @param [in] i_accessType Access Type - See DeviceFW::AccessType in
*       usrif.H
*
* @param [in] i_args This is an argument list for the device driver
*       framework.  This argument list consists of the chip number of
*       the TPM to access from the given I2C Master target and the
*       internal offset to use on the slave I2C device.
*
* @return errlHndl_t NULL if successful, otherwise a pointer to the
*       error log.
*
*/
errlHndl_t tpmPerformOp( DeviceFW::OperationType i_opType,
                         TARGETING::Target * i_target,
                         void * io_buffer,
                         size_t & io_buflen,
                         int64_t i_accessType,
                         va_list i_args );

/**
 * @brief This function peforms the sequencing to do a read of the
 *      TPM that is identified.
 *
 * @param[out] o_buffer The buffer that will return the data read
 *      from the TPM device.
 *
 * @param[in] i_buflen Number of bytes to read from the TPM device.
 *
 * @param[in] i_tpmInfo Structure of I2C parameters needed to execute
 *      the command to the I2C device driver.
 *
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t tpmRead ( void * o_buffer,
                     size_t i_buflen,
                     tpm_info_t i_tpmInfo );

/**
 * @brief This function peforms the sequencing to do a write of the
 *      TPM that is identified.
 *
 * @param[out] i_buffer The buffer containing data to write
 *      to the TPM device.
 *
 * @param[in] i_buflen Number of bytes to write to the TPM device.
 *
 * @param[in] i_tpmInfo Structure of I2C parameters needed to execute
 *      the command to the I2C device driver.
 *
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t tpmWrite ( void * i_buffer,
                      size_t i_buflen,
                      tpm_info_t i_tpmInfo );

/**
 * @brief This function peforms the sequencing to do a transmit of the
 *      TPM that is identified.
 *
 * @param[in/out] io_buffer Data buffer
 *       INPUT: Command to be written to the TPM
 *       OUTPUT: Response from the TPM
 *
 * @param[in/out] io_buflen Buffer Length
 *       INPUT: Full length of io_buffer allocated.
 *       OUTPUT: Length of the response read from TPM.
 *
 * @param[in] i_commandlen Length of command to send in bytes
 *
 * @param[in] i_tpmInfo Structure of I2C parameters needed to execute
 *      the command to the I2C device driver.
 *
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t tpmTransmit ( void * io_buffer,
                         size_t & io_buflen,
                         size_t i_commandlen,
                         tpm_info_t i_tpmInfo );

/**
 * @brief This function prepares the I2C byte address for adding to the
 *      existing buffer (for Writes), or as a separate write operation
 *      (for Reads).
 *
 * @param[in/out] io_buffer The buffer to be written as a byte address to
 *      the TPM device.  Must be pre-allocated to MAX_BYTE_ADDR size.
 *
 * @param[out] o_bufSize The size of the buffer to be written.
 *
 * @param[in] i_tpmInfo Structure of I2C parameters needed to execute
 *      the command to the I2C device driver.
 *
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t tpmPrepareAddress ( void * io_buffer,
                               size_t & o_bufSize,
                               tpm_info_t i_tpmInfo );

/**
 * @brief this function will read all of the associated attributes needed
 *      to access the intended TPM.  These attributes will be used to
 *      determine the type of I2C device as well as how to address it via
 *      the I2C device driver.
 *
 * @param[in] i_target target node.
 *
 * @param[in/out] io_tpmInfo The structure that will contain the attribute data
 *      read from the target device.
 *
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t tpmReadAttributes ( TARGETING::Target * i_target,
                               tpm_info_t & io_tpmInfo );

/**
 * @brief This function decides whether or not the target passed into the
 *      TPM device driver actually contains the I2C Master engines.  If
 *      not, it will then read the attribute of the target to get the path
 *      of the target which does contain the I2C Master engine.
 *
 * @param[in] i_target The current Target.
 *
 * @param[in/out] io_tpmInfo Structure of I2C parameters needed to execute
 *      the command to the I2C device driver.
 * *
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t tpmGetI2CMasterTarget ( TARGETING::Target * i_target,
                                   tpm_info_t & io_tpmInfo );



/**
 * @brief Write a Tpm Register
 *
 * @param[in] i_tpmInfo Structure of I2C parameters needed to execute
 *      the command to the I2C device driver.
 *
 * @param[in] i_offset TPM Register Offset
 *
 * @param[in] i_buflen Length of write
 *
 * @param[in] i_buffer Value to write into register
 *
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t tpmWriteReg ( tpm_info_t i_tpmInfo,
                         size_t i_offset,
                         size_t i_buflen,
                         void * i_buffer);

/**
 * @brief Read a Tpm Register
 *
 * @param[in] i_tpmInfo Structure of I2C parameters needed to execute
 *      the command to the I2C device driver.
 *
 * @param[in] i_offset TPM Register Offset
 *
 * @param[in] i_buflen Length of read
 *
 * @param[in] o_buffer Value read from the register
 *
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t tpmReadReg ( tpm_info_t i_tpmInfo,
                        size_t i_offset,
                        size_t i_buflen,
                        void * o_buffer);

/**
 * @brief Read the Tpm STS Register
 *
 * @param[in] i_tpmInfo Structure of I2C parameters needed to execute
 *      the command to the I2C device driver.
 *
 * @param[in] o_stsReg Value read from the register
 *
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t tpmReadSTSReg ( tpm_info_t i_tpmInfo,
                           tpm_sts_reg_t & o_stsReg);

/**
 * @brief Read the Tpm STS Register polling for stsValid
 *
 * @param[in] i_tpmInfo Structure of I2C parameters needed to execute
 *      the command to the I2C device driver.
 *
 * @param[in] o_stsReg Value read from the register
 *
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t tpmReadSTSRegValid ( tpm_info_t i_tpmInfo,
                                tpm_sts_reg_t & o_stsReg);

/**
 * @brief Check for command ready in STS reg
 *
 * @param[in] i_tpmInfo Structure of I2C parameters needed to execute
 *      the command to the I2C device driver.
 *
 * @param[out] o_isReady True if TPM in command ready state.
 *
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t tpmIsCommandReady( tpm_info_t i_tpmInfo,
                              bool & o_isReady);

/**
 * @brief Poll the Tpm waiting for it to enter command ready state
 *
 * @param[in] i_tpmInfo Structure of I2C parameters needed to execute
 *      the command to the I2C device driver.
 *
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t tpmPollForCommandReady( tpm_info_t i_tpmInfo);

/**
 * @brief Check for expecting state in TPM STS Register
 *
 * @param[in] i_tpmInfo Structure of I2C parameters needed to execute
 *      the command to the I2C device driver.
 *
 * @param[out] o_isExpecting True if TPM is expecting data
 *
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t tpmIsExpecting( tpm_info_t i_tpmInfo,
                           bool & o_isExpecting);

/**
 * @brief Check for data available state in Tpm STS register
 *
 * @param[in] i_tpmInfo Structure of I2C parameters needed to execute
 *      the command to the I2C device driver.
 *
 * @param[out] o_isDataAvail True if TPM data is available
 *
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t tpmIsDataAvail( tpm_info_t i_tpmInfo,
                           bool & o_isDataAvail);

/**
 * @brief Poll the Tpm waiting for data available state
 *
 * @param[in] i_tpmInfo Structure of I2C parameters needed to execute
 *      the command to the I2C device driver.
 *
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t tpmPollForDataAvail( tpm_info_t i_tpmInfo);

/**
 * @brief Read the current burst count value
 *
 * @param[in] i_tpmInfo Structure of I2C parameters needed to execute
 *      the command to the I2C device driver.
 *
 * @param[out] o_burstCount Current TPM burst count
 *
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t tpmReadBurstCount( tpm_info_t i_tpmInfo,
                              uint8_t & o_burstCount);

/**
 * @brief Write the command ready bit in the Tpm STS register
 *
 * @param[in] i_tpmInfo Structure of I2C parameters needed to execute
 *      the command to the I2C device driver.
 *
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t tpmWriteCommandReady( tpm_info_t i_tpmInfo);

/**
 * @brief Write the TpmGo bit in the STS register
 *
 * @param[in] i_tpmInfo Structure of I2C parameters needed to execute
 *      the command to the I2C device driver.
 *
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t tpmWriteTpmGo( tpm_info_t i_tpmInfo);

/**
 * @brief Write the response retry bit in the Tpm STS register
 *
 * @param[in] i_tpmInfo Structure of I2C parameters needed to execute
 *      the command to the I2C device driver.
 *
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t tpmWriteResponseRetry( tpm_info_t i_tpmInfo);


/**
 * @brief Write the buffer into the TPM's input FIFO
 *
 * @param[in] i_tpmInfo Structure of I2C parameters needed to execute
 *      the command to the I2C device driver.
 *
 * @param[in] i_buffer Input buffer to write to TPM
 *
 * @param[in] i_buflen Byte length of data to write
 *
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t tpmWriteFifo( tpm_info_t i_tpmInfo,
                         void * i_buffer,
                         size_t i_buflen);

/**
 * @brief Read from the TPM FIFO into the buffer
 *
 * @param[in] i_tpmInfo Structure of I2C parameters needed to execute
 *      the command to the I2C device driver.
 *
 * @param[in] o_buffer Output buffer
 *
 * @param[in] io_buflen Byte length of buffer
 *       INPUT: Full length of io_buffer allocated.
 *       OUTPUT: Length of the response read from TPM.
 *
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t tpmReadFifo( tpm_info_t i_tpmInfo,
                        void * o_buffer,
                        size_t & io_buflen);


}; // end TPMDD namespace

#endif  // __TPMDD_H
