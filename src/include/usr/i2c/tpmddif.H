/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/i2c/tpmddif.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2018                        */
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

#include "usr/devicefw/driverif.H"  // I2C_MUX::NOT_APPLICABLE

namespace TPMDD
{

/**
 * @brief TPM Operation to perform
*/
enum tpm_op_types_t
{
    TPM_OP_READVENDORID = 0,   ///< Read Vendor/Dev ID from device, max 4 bytes
    TPM_OP_TRANSMIT     = 1,   ///< Transmit/Receive command block to TPM
    TPM_OP_DRTMRESET    = 2,   ///< Perform a DRTM PCR reset
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
 * @brief TPM Locality to address for operation
 */
enum tpm_locality_t
{
    TPM_LOCALITY_0 = 0,
    TPM_LOCALITY_2 = 2,
    TPM_LOCALITY_4 = 4,
};

/**
 * @brief Structure of common parameters needed by different parts of
 *      the code.
 */
struct tpm_info_t
{
    tpm_op_types_t operation;    ///< TPM operation to perform
    TARGETING::EntityPath i2cMasterPath; ///< I2C Master path
    TARGETING::Target * i2cTarget; ///< I2C Master Target
    TARGETING::Target * tpmTarget; ///< TPM Target

    uint64_t busFreq;           ///< Bus speed in Hz
    uint8_t port;               ///< I2C Master port
    uint8_t engine;             ///< I2C Master engine
    uint8_t tpmEnabled;         ///< TPM attribute defined as available
    uint8_t devAddr;            ///< I2C Address
    size_t  offset;             ///< TPM Device register offset
    tpm_addr_size_t addrSize;   ///< I2C Addr size

    uint8_t i2cMuxBusSelector;  ///< The Selector for the I2C MUX
    TARGETING::EntityPath i2cMuxPath;  ///< I2C MUX path

    /**
     *  @brief Construct a default tpm_info_t
     */
    tpm_info_t()
        : operation(TPM_OP_LASTOP),
          i2cMasterPath(),
          i2cTarget(nullptr),
          tpmTarget(nullptr),
          busFreq(0),
          port(0),
          engine(0),
          tpmEnabled(false),
          devAddr(0),
          offset(0),
          addrSize(LAST_DEVICE_TYPE),
          i2cMuxBusSelector(I2C_MUX::NOT_APPLICABLE),
          i2cMuxPath()
    {
    }
};

/**
 * @brief Determine if requested TPM is present and enabled in the system
 *
 * @par Detailed Description:
 *     Determines if requested TPM is present and enabled in the system.  If the
 *     "TPM Required" policy is set to "TPM Required" and a blueprint TPM (which
 *     is specified as enabled in the object model) is not detected properly,
 *     the function will throw error logs to help diagnose the problem.
 *
 * @param[in] i_pTpm TPM target; must be of TPM type and must not be nullptr
 *
 * @return bool Whether device is present (true) or not (false)
 */
bool tpmPresence (TARGETING::Target* i_pTpm);

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
 * @param[in] i_locality TPM locality to address
 *
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *      error log.
 */
errlHndl_t tpmReadAttributes ( TARGETING::Target * i_target,
                               tpm_info_t & io_tpmInfo,
                               tpm_locality_t i_locality);


};  // end namespace TPMDD

#endif  // end __TPMDDIF_H

