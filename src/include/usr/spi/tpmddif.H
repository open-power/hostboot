/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/spi/tpmddif.H $                               */
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
#ifndef __TPMDDIF_H
#define __TPMDDIF_H


namespace TPMDD
{

/**
 * @brief TPM Operation to perform
*/
enum tpm_op_types_t
{
    TPM_OP_READVENDORID = 0,   ///< Read Vendor/Dev ID from device, max 4 bytes
    TPM_OP_TRANSMIT     = 1,   ///< Transmit/Receive command block to TPM
    TPM_OP_LASTOP       = 2,
    TPM_OP_FIRSTOP      = TPM_OP_READVENDORID
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
 * @brief TPM Models that are supported
 *
 * @note  Must stay in sync with TPM_MODEL in attribute_types_hb.xml and
 *        the attribute usage in processMrw.pl.
 * @note  Not using Attribute Enums since FSP does not currently support
 *        overriding enum values
 */
enum tpm_model_t : uint8_t
{
    TPM_MODEL_UNDETERMINED = 0x00,
    TPM_MODEL_65x          = 0x01,
    TPM_MODEL_75x          = 0x02,
};


/**
 * @brief Structure of common parameters needed by different parts of
 *      the code.
 */
struct tpm_info_t
{
    tpm_op_types_t operation;    ///< TPM operation to perform
    TARGETING::EntityPath spiControllerPath; ///< SPI Controller path
    TARGETING::Target * spiTarget; ///< SPI Controller Target
    TARGETING::Target * tpmTarget; ///< TPM Target
    uint8_t spiEngine;          ///< SPI Controller engine for TPM
    size_t  offset;             ///< TPM Device register offset
    tpm_locality_t locality;    ///< TPM locality for SPI access
    uint8_t tpmEnabled;         ///< TPM attribute defined as available
    uint8_t model;              ///< TPM Model
    uint8_t sts;                ///< STS
    uint8_t burstCount;         ///< burstCount
    uint8_t tpmHash;            ///< TPM Hash
    uint8_t wrFifo;             ///< Write FIFO
    uint8_t rdFifo;             ///< Read FIFO
    uint16_t vendorIdOffset;    ///< Vendor ID Offset
    uint32_t vendorId;          ///< Vendor ID

    /**
     *  @brief Construct a default tpm_info_t
     */
    tpm_info_t()
        : operation(TPM_OP_LASTOP),
          spiControllerPath(),
          spiTarget(nullptr),
          tpmTarget(nullptr),
          spiEngine(0),
          offset(0),
          locality(TPM_LOCALITY_0),
          tpmEnabled(0),
          model(TPM_MODEL_UNDETERMINED),
          sts(0),
          burstCount(0),
          tpmHash(0),
          wrFifo(0),
          rdFifo(0),
          vendorIdOffset(0),
          vendorId(0)
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
 *      determine the type of SPI device as well as how to address it via
 *      the SPI device driver.
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
                               tpm_locality_t i_locality );

};  // end namespace TPMDD

#endif  // end __TPMDDIF_H
