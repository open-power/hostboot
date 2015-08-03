/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/i2c/tpmddif.H $                               */
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
#ifndef __TPMDDIF_H
#define __TPMDDIF_H

namespace TPMDD
{

/**
 * @brief Enumerations to select TPM
*/
enum tpm_chip_types_t
{
  TPM_PRIMARY   = 0,
  TPM_BACKUP    = 1,
  LAST_CHIP_TYPE,
  FIRST_CHIP_TYPE = TPM_PRIMARY
};

/**
 * @brief TPM Operation to perform
*/
enum tpm_op_types_t
{
    TPM_OP_READVENDORID = 0,   ///< Read Vendor/Dev ID from device, max 4 bytes
    TPM_OP_TRANSMIT     = 1,   ///< Transmit/Receive command block to TPM
    TPM_OP_LASTOP,
    TPM_OP_FIRSTOP      = TPM_OP_READVENDORID
};

/**
* @brief Enumerations to describe the type of devices to be accessed.
*/
enum tpm_addr_size_t
{
    ONE_BYTE_ADDR   = 1,
    TWO_BYTE_ADDR   = 2,
    LAST_DEVICE_TYPE
};

/**
 * @brief Structure of common parameters needed by different parts of
 *      the code.
 */
struct tpm_info_t
{
    tpm_op_types_t operation;    ///< TPM operation to perform
    TARGETING::EntityPath i2cMasterPath; ///< I2C Master path
    TARGETING::Target * i2cTarget; ///< I2C Target

    uint8_t port;               ///< I2C Master port
    uint8_t engine;             ///< I2C Master engine
    uint8_t chip;               ///< Chip target, primary/backup
    uint8_t tpmEnabled;         ///< TPM attribute defined as available
    uint8_t devAddr;            ///< I2C Address
    size_t  offset;             ///< TPM Device register offset
    tpm_addr_size_t addrSize;   ///< I2C Addr size
};

/**
 *
 * @brief Determine if targeted TPM is present and enabled in the system
 *
 * @param[in] i_target Target node
 *
 * @param[in] i_chip Select primary vs secondary TPM
 *
 * @return true if device is present
 */
bool tpmPresence ( TARGETING::Target * i_target,
                   tpm_chip_types_t i_chip );

/**
 * @brief this function will read all of the associated attributes needed
 *      to access the intended TPM.  These attributes will be used to
 *      determine the type of I2C device as well as how to address it via
 *      the I2C device driver.
 *
 * @param[in] i_target target node.
 *
 * @param[in/out] io_tpmInfo The structure that will contain the attribute data
 *      read from the target device.  Chip field must be set
 *
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t tpmReadAttributes ( TARGETING::Target * i_target,
                               tpm_info_t & io_tpmInfo );


};  // end namespace TPMDD

#endif  // end __TPMDDIF_H

