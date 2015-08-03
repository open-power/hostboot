/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/trusted/trustedboot.H $                    */
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
/**
 * @file trustedboot.H
 *
 * @brief Trustedboot TPM interfaces
 *
 */
#ifndef __TRUSTEDBOOT_H
#define __TRUSTEDBOOT_H
// -----------------------------------------------
// Includes
// -----------------------------------------------
#include <secureboot/trustedbootif.H>
#include <i2c/tpmddif.H>
#include "trustedTypes.H"

namespace TRUSTEDBOOT
{

enum
{
    BUFSIZE         = 256,
    MAX_TRANSMIT_SIZE = 1024, ///< Maximum send/receive transmit size
};

/**
 * @brief Initialize the targetted TPM
 * @param[in/out] io_target Current TPM target structure
 * @param[in] i_nodeTarget Node Target
 * @param[in] i_chip Chip to initialize
*/
void tpmInitialize(TRUSTEDBOOT::TpmTarget & io_target,
                   TARGETING::Target* i_nodeTarget,
                   TPMDD::tpm_chip_types_t i_chip);

/**
 * @brief Mark the TPM as non-functional and take required steps
 * @param[in/out] io_target Current TPM target structure
 */
void tpmMarkFailed(TRUSTEDBOOT::TpmTarget & io_target);

/**
 * @brief Transmit the command to the TPM and perform marshaling
 * @param[in/out] io_target Current TPM target structure
 * @param[in/out] io_buffer Input the command buffer to send, response on exit
 * @param[in] i_bufsize Size of io_buffer in bytes
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *       error log.
 */
errlHndl_t tpmTransmitCommand(TRUSTEDBOOT::TpmTarget & io_target,
                              uint8_t* io_buffer,
                              size_t i_bufsize );

/**
 * @brief Take structure pointed to by cmd and format for input into TPM
 * @param[in] i_cmd Prefilled command input structure
 * @param[out] o_outbuf Buffer to place marshalled data
 * @param[in] i_bufsize Size of o_outbuf in bytes
 * @param[out] o_cmdSize Byte size of io_outbuf data after marshal
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *       error log.
 */
errlHndl_t tpmMarshalCommandData(TRUSTEDBOOT::TPM2_BaseIn* i_cmd,
                                 uint8_t* o_outbuf,
                                 size_t i_bufsize,
                                 size_t & o_cmdSize);

/**
 * @brief Take structure pointed to by cmd and format for input into TPM
 * @param[in] i_commandCode Command code that was executed on the TPM
 * @param[in] i_respBuf Buffer with response data from TPM
 * @param[in] i_respBufSize Byte size of respBuf buffer from TPM
 * @param[out] o_outBuf Buffer to place formatted response data
 * @param[in] i_outBufSize Byte size of o_outBuf buffer
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *       error log.
 */
errlHndl_t tpmUnmarshalResponseData(uint32_t i_commandCode,
                                    uint8_t* i_respBuf,
                                    size_t i_respBufSize,
                                    TRUSTEDBOOT::TPM2_BaseOut* o_outBuf,
                                    size_t i_outBufSize);
/**
 * @brief Send the TPM_STARTUP command to the targetted TPM
 * @param[in/out] io_target Current TPM target structure
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *       error log.
*/
errlHndl_t tpmCmdStartup(TRUSTEDBOOT::TpmTarget & io_target);

/**
 * @brief Send the TPM_GETCAPABILITY command to read FW version from TPM
 * @param[in/out] io_target Current TPM target structure
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *       error log.
*/

errlHndl_t tpmCmdGetCapFwVersion(TRUSTEDBOOT::TpmTarget & io_target);


} // end TRUSTEDBOOT namespace
#endif
