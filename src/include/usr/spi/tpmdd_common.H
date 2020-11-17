/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/spi/tpmdd_common.H $                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
#ifndef __TPMDD_COMMON_H
#define __TPMDD_COMMON_H

/** @file tpmdd_common.H
 *  @brief TPM data structures and constants common between HBBL and HB
 */

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
    };
};

} // namespace TPMDD
#endif
