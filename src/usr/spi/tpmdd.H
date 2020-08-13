/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/spi/tpmdd.H $                                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
 *      the system via the SPI device driver.
 */

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <spi/tpmddif.H>
#include <errl/errlentry.H>

namespace TPMDD
{


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




#ifdef CONFIG_TPM_NUVOTON
/**
 * @brief Nuvoton 2.0 TPM definitions
 */
enum nuvo_20_defs_t
{
    // Values for Nuvoton 75x Support
    TPM_REG_75x_TPM_ACCESS       = 0x00,
    TPM_REG_75x_STS              = 0x18,
    TPM_REG_75x_BURSTCOUNT       = 0x19,
    TPM_REG_75x_TPM_HASH         = 0x4,
    TPM_REG_75x_WR_FIFO          = 0x24,
    TPM_REG_75x_RD_FIFO          = 0x24,
    TPM_REG_75x_VENDOR_ID_OFFSET = 0xF00, // old i2c offset 0x48
    TPM_VENDORID_75x             = 0x5010FC00,

    // Common values
    TPM_VENDORID_MASK  = 0xFFFFFF00,
};

/// TPM_REG_75x_TPM_ACCESS data for requesting locality use
const uint8_t TPM_ACCESS_REQUEST_LOCALITY_USE = 0x02;

#endif


/**
* @brief TPM STS register definition (PTP 2.0 Spec)
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
        uint8_t selfTestDone   : 1; // 05 // RO
        uint8_t responseRetry  : 1; // 06 // WO
        uint8_t rsvd2          : 1; // 07 // RO
    } PACKED;
};

/**
*
* @brief Perform a TPM access operation.
*
* @param[in] i_opType Operation Type - See DeviceFW::OperationType in
*       driverif.H
*
* @param[in] i_target TPM target node
*
* @param[in/out] io_buffer
*       INPUT: Pointer to the data that will be written to the target
*           device.
*       OUTPUT: Pointer to the data that was read from the target device.
*
* @param[in/out] io_buflen
*       INPUT: Length of the buffer to be written to target device.
*       OUTPUT: Length of buffer that was written, or length of buffer
*           to be read from target device.
*
* @param [in] i_accessType Access Type - See DeviceFW::AccessType in
*       userif.H
*
* @param [in] i_args This is an argument list for the device driver
*       framework.  This argument list consists of specific TPM operation,
*       commandSize for tpmTransmit op, and TPM locality
*
* @return errlHndl_t nullptr if successful, otherwise a pointer to the
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
 * @param[in] i_tpmInfo Structure of SPI parameters needed to execute
 *      the command to the SPI device driver.
 *
 * @param[in] i_silent Don't log any error logs on failure
 *
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t tpmRead ( void * o_buffer,
                     size_t i_buflen,
                     const tpm_info_t & i_tpmInfo,
                     bool i_silent = false);
/**
 * @brief This function peforms the sequencing to do a write of the
 *      TPM that is identified.
 *
 * @param[out] i_buffer The buffer containing data to write
 *      to the TPM device.
 *
 * @param[in] i_buflen Number of bytes to write to the TPM device.
 *
 * @param[in] i_tpmInfo Structure of SPI parameters needed to execute
 *      the command to the SPI device driver.
 *
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t tpmWrite ( void * i_buffer,
                      size_t i_buflen,
                      const tpm_info_t & i_tpmInfo);

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
 * @param[in] i_tpmInfo Structure of SPI parameters needed to execute
 *      the command to the SPI device driver.
 *
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t tpmTransmit ( void * io_buffer,
                         size_t & io_buflen,
                         size_t i_commandlen,
                         const tpm_info_t & i_tpmInfo );


/**
 * @brief This converts the io_tpmInfo.spiControllerPath into a valid
 *        Target pointer assigned to io_tpmInfo.spiTarget
 *
 * @param[in] i_target The current TPM Target.
 *
 * @param[in/out] io_tpmInfo Structure of SPI parameters,
 *                [in] - Require two fields:
 *                       io_tpmInfo.spiControllerPath
 *                       io_tpmInfo.tpmTarget (error case handling)
 *                [out] - io_tpmInfo.spiTarget assigned
 *
 * @return errlHndl_t nullptr if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t tpmGetSPIControllerTarget( TARGETING::Target * i_target,
                                      tpm_info_t & io_tpmInfo );

/**
 * @brief Write a Tpm Register
 *
 * @param[in] i_tpmInfo Structure of SPI parameters needed to execute
 *      the command to the SPI device driver.
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
 * @param[in] i_tpmInfo Structure of SPI parameters needed to execute
 *      the command to the SPI device driver.
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
 * @param[in] i_tpmInfo Structure of SPI parameters needed to execute
 *      the command to the SPI device driver.
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
 * @param[in] i_tpmInfo Structure of SPI parameters needed to execute
 *      the command to the SPI device driver.
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
 * @param[in] i_tpmInfo Structure of SPI parameters needed to execute
 *      the command to the SPI device driver.
 *
 * @param[out] o_isReady True if TPM in command ready state.
 *
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t tpmIsCommandReady( const tpm_info_t & i_tpmInfo,
                              bool & o_isReady);

/**
 * @brief Poll the Tpm waiting for it to enter command ready state
 *
 * @param[in] i_tpmInfo Structure of SPI parameters needed to execute
 *      the command to the SPI device driver.
 *
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t tpmPollForCommandReady( const tpm_info_t & i_tpmInfo);

/**
 * @brief Check for expecting state in TPM STS Register
 *
 * @param[in] i_tpmInfo Structure of SPI parameters needed to execute
 *      the command to the SPI device driver.
 *
 * @param[out] o_isExpecting True if TPM is expecting data
 *
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t tpmIsExpecting( const tpm_info_t & i_tpmInfo,
                           bool & o_isExpecting);

/**
 * @brief Check for data available state in Tpm STS register
 *
 * @param[in] i_tpmInfo Structure of SPI parameters needed to execute
 *      the command to the SPI device driver.
 *
 * @param[out] o_isDataAvail True if TPM data is available
 *
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t tpmIsDataAvail( const tpm_info_t & i_tpmInfo,
                           bool & o_isDataAvail);

/**
 * @brief Poll the Tpm waiting for data available state
 *
 * @param[in] i_tpmInfo Structure of SPI parameters needed to execute
 *      the command to the SPI device driver.
 *
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t tpmPollForDataAvail( const tpm_info_t & i_tpmInfo);

/**
 * @brief Read the current burst count value
 *
 * @param[in] i_tpmInfo Structure of SPI parameters needed to execute
 *      the command to the SPI device driver.
 *
 * @param[out] o_burstCount Current TPM burst count
 *
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t tpmReadBurstCount( const tpm_info_t & i_tpmInfo,
                              uint16_t & o_burstCount);

/**
 * @brief Write the command ready bit in the Tpm STS register
 *
 * @param[in] i_tpmInfo Structure of SPI parameters needed to execute
 *      the command to the SPI device driver.
 *
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t tpmWriteCommandReady( const tpm_info_t & i_tpmInfo);

/**
 * @brief Write the TpmGo bit in the STS register
 *
 * @param[in] i_tpmInfo Structure of SPI parameters needed to execute
 *      the command to the SPI device driver.
 *
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t tpmWriteTpmGo( const tpm_info_t & i_tpmInfo);

/**
 * @brief Write the response retry bit in the Tpm STS register
 *
 * @param[in] i_tpmInfo Structure of SPI parameters needed to execute
 *      the command to the SPI device driver.
 *
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t tpmWriteResponseRetry( const tpm_info_t & i_tpmInfo);


/**
 * @brief Write the buffer into the TPM's input FIFO
 *
 * @param[in] i_tpmInfo Structure of SPI parameters needed to execute
 *      the command to the SPI device driver.
 *
 * @param[in] i_buffer Input buffer to write to TPM
 *
 * @param[in] i_buflen Byte length of data to write
 *
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t tpmWriteFifo( const tpm_info_t & i_tpmInfo,
                         void * i_buffer,
                         size_t i_buflen);

/**
 * @brief Read from the TPM FIFO into the buffer
 *
 * @param[in] i_tpmInfo Structure of SPI parameters needed to execute
 *      the command to the SPI device driver.
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
errlHndl_t tpmReadFifo( const tpm_info_t & i_tpmInfo,
                        void * o_buffer,
                        size_t & io_buflen);
/**
 * @brief Performs a presence detect operation on a TPM Chip.
 *  This is used for the discoverTargets path and called TPMDD::tpmPresence
 *
 * @param[in]   i_opType        Operation type, see DeviceFW::OperationType
 *                              in driverif.H
 * @param[in]   i_target        Presence detect target
 * @param[in/out] io_buffer     Read: Pointer to output data storage
 *                              Write: Pointer to input data storage
 * @param[in/out] io_buflen     Input: size of io_buffer (in bytes, always 1)
 *                              Output: Success = 1, Failure = 0
 * @param[in]   i_accessType    DeviceFW::AccessType enum (userif.H)
 * @param[in]   i_args          This is an argument list for DD framework.
 *                              In this function, there are no arguments.
 * @return  errlHndl_t
 */
errlHndl_t tpmPresenceDetect(DeviceFW::OperationType i_opType,
                             TARGETING::Target* i_target,
                             void* io_buffer,
                             size_t& io_buflen,
                             int64_t i_accessType,
                             va_list i_args);

}; // end TPMDD namespace

#endif  // __TPMDD_H
