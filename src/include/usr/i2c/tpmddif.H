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


};  // end namespace TPMDD

#endif  // end __TPMDDIF_H

