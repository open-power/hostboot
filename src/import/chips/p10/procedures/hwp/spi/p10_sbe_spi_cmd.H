/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/spi/p10_sbe_spi_cmd.H $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/*
 * sbe_spi_cmd.H
 *
 *  Created on: 1 Apr 2019
 *      Author: HolgerNeuhaus, Shajith Chandran, Srikantha Meesala
 */
#ifndef P10_SBE_SPI_CMD_H_
#define P10_SBE_SPI_CMD_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "fapi2.H"

//------------------------------------------------------------------------------
//       Important Status register bits used in the code
//------------------------------------------------------------------------------
#define SPI_RDR_FULL        0x8000000000000000ULL
#define SPI_RDR_OVERRUN     0x4000000000000000ULL
#define SPI_RDR_UNDERRUN    0x2000000000000000ULL
#define SPI_TDR_FULL        0x0800000000000000ULL
#define SPI_TDR_OVERRUN     0x0400000000000000ULL
#define SPI_TDR_UNDERRUN    0x0200000000000000ULL

//The default seq register opcode, which is used on
//memory mapped access path. This is the opcode used
//by the h/w on the sideband path
#define SPI_DEFAULT_SEQ 0x1134491000000000ULL

//The counter reg is 8 bits and with each seq with 8byte transfer.
//For the purposes of security, we're using 8-byte transfers, since
//8-byte transfers don't use the restricted 0xEX op code.
#define MAX_LENGTH_TRNS 8

//Secure reads via TPM require not using 0xEX command
#define TPM_SECURE_READ_TRNS 8

//Each page in the seeprom is 256 bytes in size
#define SEEPROM_PAGE_SIZE 256

//Base address and offset for various registers in the SPI Master
const uint32_t SPIM_BASEADDRESS_PIB      = 0xc0000;
const uint32_t SPIM_BASEADDRESS_FSI      = 0x70000;
const uint32_t SPIM_ENGINEOFFSET         = 0x20;
const uint32_t SPIM_COUNTERREG           = 1;
const uint32_t SPIM_CONFIGREG1           = 2;
const uint32_t SPIM_CLOCKCONFIGREG       = 3;
const uint32_t SPIM_MMSPISMREG           = 4;
const uint32_t SPIM_TDR                  = 5;
const uint32_t SPIM_RDR                  = 6;
const uint32_t SPIM_SEQREG               = 7;
const uint32_t SPIM_STATUSREG            = 8;

// SPI clock control register information and defaults
enum  SPI_CLOCK_CONTROL_REG_INFO : size_t
{
    // Known good FSI SPI clock control values
    FSI_SPI_CLOCK_DIVIDER = 0x013,
    FSI_SPI_RECEIVE_DELAY_CYCLES = 0,

    // SPI clock control field start locations and lengths in bits
    SPI_CLOCK_DIVIDER_START_BIT = 0,
    SPI_CLOCK_DIVIDER_LEN_BITS = 12,
    SPI_CLOCK_RECEIVE_DELAY_START_BIT = 12,
    SPI_CLOCK_RECEIVE_DELAY_LEN_BITS = 8,
};

// Information om part that each SPI engine drives
enum  SPI_ENGINE_PART : size_t
{
    SPI_ENGINE_PRIMARY_BOOT_SEEPROM = 0,
    SPI_ENGINE_BACKUP_BOOT_SEEPROM  = 1,
    SPI_ENGINE_PRIMARY_MVPD_SEEPROM = 2,
    SPI_ENGINE_BACKUP_MVPD_SEEPROM  = 3,
    SPI_ENGINE_TPM                  = 4,
};

/**
 *  @brief Calculates SPI receive delay value, given an input number of delay
 *      cycles, to program into the SPI clock control register.  A value of
 *      >= 8 will disable receive clocking entirely.
 *
 *  @param[in] i_delayCycles Number of SPI controller unit clocks to delay
 *
 *  @retval uint8_t Receive delay value to program into SPI clock control
 *      register, translated from the input delay cycle value.
 */
inline uint8_t spiReceiveDelay(const size_t i_delayCycles)
{
    // 0x80 per the pervasive spec represents 0 delay cycles.  This 0x80 value
    // must be shifted one more bit to the right for each additional delay
    // cycle desired. 0x00 implies receive clocking disabled.
    return 0x80 >> i_delayCycles;
}


extern "C"
{

    enum SPI_ECC_CONTROL_STATUS
    {
        STANDARD_ECC_ACCESS = 0x00, // The data is used with standard ECC byte
        RAW_BYTE_ACCESS = 0x01,     // The data is used as raw bytes, no ECC logic is
        // applied and all data is returned
        DISCARD_ECC_ACCESS = 0x02   // Ignore ECC and access data without ECC byte
    };

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------
    struct SpiControlHandle
    {
        public:
            SpiControlHandle (
                const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
                const uint8_t i_engine, const uint16_t i_slave = 1,
                const bool i_pib_access = true):
                target_chip(i_target_chip),
                engine(i_engine),
                slave(i_slave),
                base_addr(i_pib_access ?
                          SPIM_BASEADDRESS_PIB + this->engine * SPIM_ENGINEOFFSET :
                          SPIM_BASEADDRESS_FSI + this->engine * SPIM_ENGINEOFFSET ),
                pibAccess(i_pib_access)

            {
            }
            const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> target_chip;
            const uint8_t engine;
            const uint16_t slave;
            const uint32_t base_addr;
            const bool pibAccess;     // 1 if using PIB engine, else 0 (FSI)
    };

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

///
/// @brief  API to configure the SPI clock control register indicated by the
///     input SPI control handle
///
/// @param[in] i_spiHandle Reference to the SPI control handle
///
/// @return FAPI_RC_SUCCESS if the SPI clock control register was configured
///     successfully, otherwise error code.
///
    fapi2::ReturnCode p10_spi_clock_init (const SpiControlHandle& i_spiHandle);

///
/// @brief  API to lock the SPI h/w. SPI Lock should be acquired by the caller
///         before performing any operations on the SPI hardware
///
/// @param[in] i_handle          Reference to SPI Control Handle
/// @param[in] i_pib_master_id   PIB master id for operations
///
/// @return FAPI_RC_SUCCESS if the spi master lock completes successfully, else
///         error code.
///
    fapi2::ReturnCode spi_master_lock(
        SpiControlHandle& i_handle,
        uint64_t i_pib_master_id );

///
/// @brief  API to unlock the SPI h/w. SPI Unlock should be performed by
///         the caller after all required operations on the SPI hardware
///         is completed
///
/// @param[in] i_handle          Reference to SPI Control Handle
/// @param[in] i_pib_master_id   PIB master id for operations
///
/// @return FAPI_RC_SUCCESS if the spi master unlock completes successfully,
///         else error code.
///
    fapi2::ReturnCode spi_master_unlock(
        SpiControlHandle& i_handle,
        uint64_t i_pib_master_id );

///
/// @brief  API to read the seeprom using SPI
///
/// @param[in] i_handle     Reference to SPI Control Handle
/// @param[in] i_address    The address the seeprom from where the read will
///                         start. Should be 8 byte aligned as per SPI_ECC_CONTROL_STATUS
/// @param[in] i_length     Length in bytes to be read.
/// @param[in] i_eccStatus  Data to be read/returned used with standard ECC byte then set STANDARD_ECC_ACCESS.
///                         The data only used as raw bytes without ECC byte then set RAW_BYTE_ACCESS.
///                         Ignore ECC and access data without ECC byte then set DISCARD_ECC_ACCESS.
///
/// @param[out] o_buffer  Buffer where the data will be copied to
///
/// @return FAPI_RC_SUCCESS if the spi master read completes successfully,
///         else error code.
///

    fapi2::ReturnCode spi_read(
        SpiControlHandle& i_handle,
        uint32_t i_address,
        uint32_t i_length,
        SPI_ECC_CONTROL_STATUS i_eccStatus,
        uint8_t* o_buffer);

///
/// @brief  API to read from the TPM using SPI
///         Secure reading requires no 0xEX command,
///         so this read may be broken into multiple TPM reads
///
/// @param[in] i_handle   Reference to SPI control handle
/// @param[in] i_locality TPM locality (0-4)
/// @param[in] i_address  The relative address to read from the TPM
///                       The last three nibbles of TPM address on SPI
///                       0xD4_[locality]xxxh
/// @param[in] i_length   Length in bytes to read
/// @param[out]o_buffer   Buffer where the data read will be copied into
///
/// @return FAPI2_RC_SUCCESS if the spi read completes successfully,
///         else error code.
///
    fapi2::ReturnCode spi_tpm_read_secure( SpiControlHandle& i_handle,
                                           const uint32_t i_locality,
                                           const uint32_t i_address,
                                           const uint8_t i_length,
                                           uint8_t* o_buffer );


///
/// @brief  API to write to the TPM using SPI
///
/// @param[in] i_handle   Reference to SPI control handle
/// @param[in] i_locality TPM locality (0-4)
/// @param[in] i_address  The relative address to write to the TPM
///                       The last three nibbles of TPM address on SPI
///                       0xD4_[locality]xxxh
/// @param[in] i_length   Length in bytes to write
/// @param[in] i_buffer   Data buffer to write
///
/// @return FAPI2_RC_SUCCESS if the spi write completes successfully,
///         else error code.
///
    fapi2::ReturnCode spi_tpm_write_with_wait( SpiControlHandle& i_handle,
            const uint32_t i_locality,
            const uint32_t i_address,
            const uint8_t i_length,
            const uint8_t* i_buffer );

///
/// @brief  API to write the seeprom using SPI
///
/// @param[in] i_handle     Reference to SPI Control Handle
/// @param[in] i_address    The address the seeprom from where the write
///                         will start.
/// @param[in] i_length     Length in bytes to be written.
/// @param[out] i_buffer    Buffer data to write into
///
/// @return FAPI_RC_SUCCESS if the spi master read completes successfully,
///         else error code.
///
    fapi2::ReturnCode spi_write(
        SpiControlHandle& i_handle,
        uint32_t i_address,
        uint32_t i_length,
        uint8_t* i_buffer );

} //extern "C"

#endif /* P10_SBE_SPI_CMD_H_ */
