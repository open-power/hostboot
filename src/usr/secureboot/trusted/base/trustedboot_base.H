/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/trusted/base/trustedboot_base.H $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
 * @file trustedboot_base.H
 *
 * @brief Trustedboot TPM interfaces in HB base
 *
 */
#ifndef __TRUSTEDBOOT_BASE_H
#define __TRUSTEDBOOT_BASE_H
// -----------------------------------------------
// Includes
// -----------------------------------------------
#include <secureboot/trustedbootif.H>
#include "../trustedTypes.H"

namespace TRUSTEDBOOT
{


/**
 * @brief Verify a functional TPM still exists in the system
 * @return errlHndl_t NULL if TPM available, otherwise a pointer to the
 *       error log.
*/
errlHndl_t tpmVerifyFunctionalTpmExists();

/**
 * @brief Extend a measurement into a TPM and log
 * @param[in/out] io_target Current TPM target structure
 * @param[in] i_pcr PCR to write to
 * @param[in] i_digest Digest value to write to PCR
 * @param[in] i_digestSize Byte size of i_digest data
 * @param[in] i_logMsg Null terminated log message
 */
void pcrExtendSingleTpm(TpmTarget & io_target,
                        TPM_Pcr i_pcr,
                        TPM_Alg_Id i_algId,
                        uint8_t* i_digest,
                        size_t  i_digestSize,
                        const char* i_logMsg);


} // end TRUSTEDBOOT namespace
#endif
