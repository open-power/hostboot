/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/trusted/trustedbootUtils.H $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
 * @file trustedbootUtils.H
 *
 * @brief Trustedboot TPM utilities that must be implemented for each
 *  unique implementation
 *
 */

/////////////////////////////////////////////////////////////////
// NOTE: This file is exportable as TSS-Lite for skiboot/PHYP  //
/////////////////////////////////////////////////////////////////

#ifndef __TRUSTEDBOOTUTILS_H
#define __TRUSTEDBOOTUTILS_H
// -----------------------------------------------
// Includes
// -----------------------------------------------
#ifdef __HOSTBOOT_MODULE
#include <spi/tpmddif.H>
using namespace TPMDD;
#endif
#include "trustedTypes.H"

#ifdef __cplusplus
namespace TRUSTEDBOOT
{
#endif

/**
 * @brief Transmit the command to the TPM
 * @param[in/out] io_target Current TPM target structure
 * @param[in/out] io_buffer Input the command buffer to send, response on exit
 * @param[in] i_cmdSize Size of provided command in bytes
 * @param[in] i_bufsize Size of io_buffer in bytes
 * @param[in] i_locality TPM locality to use
 * @return errlHndl_t NULL if successful, otherwise a pointer to the
 *       error log.
 */
errlHndl_t tpmTransmit(TpmTarget * io_target,
                       uint8_t* io_buffer,
                       size_t i_cmdSize,
                       size_t i_bufsize,
                       tpm_locality_t i_locality);

/**
 *  @brief Create an error log entry for potential logging
 *
 *  @param[in] i_modId Code Module ID
 *  @param[in] i_reasonCode Error Reason Code
 *  @param[in] i_user1 User data 1
 *  @param[in] i_user2 User data 2
 *  @param[in] i_addSwCallout Whether to add a high priority Hostboot software
 *      callout to the error log or not (default: true)
 *
 *  @return errlHndl_t Handle to newly created error log
 */
errlHndl_t tpmCreateErrorLog(
    uint8_t  i_modId,
    uint16_t i_reasonCode,
    uint64_t i_user1,
    uint64_t i_user2,
    bool     i_addSwCallout = ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);


#ifdef __cplusplus
} // end TRUSTEDBOOT namespace
#endif

#endif
