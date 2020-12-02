/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/bootloader/bl_tpm_spidd.H $                       */
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
#ifndef __BL_TPM_SPIDD_H
#define __BL_TPM_SPIDD_H

#include <stdint.h>
#include <hbblreasoncodes.H>
#include <spi/tpmdd_common.H>

/** @file bl_tpm_spidd.H
 *  @brief Provides interfaces for performing SPI TPM operations in HBBL
 */

/**
 * @brief Performs the SPI TPM read operation
 *
 * @param[in] i_offset The offset at which to read.
 * @param[out] o_buffer The buffer to place the retrieved data.
 * @param[in/out] io_buflen INPUT: The size of the data to read and place in the
 *                                 buffer.
 *                          OUTPUT: The size of the data actually read (could be
 *                                  less than amount requested; RC is returned
 *                                  in that case).
 *
 * @return 0 on success or error code on failure
 */
Bootloader::hbblReasonCode tpm_read(uint32_t i_offset, void* o_buffer, size_t& io_buflen);

/**
 * @brief Performs the SPI TPM write operation.
 *
 * @param[in] i_offset The offset at which to write.
 * @param[in] i_buffer The buffer containing the data to be written to the
 *                     target device.
 * @param[in/out] io_buflen INPUT: The size of data to write to the TPM
 *                          OUTPUT: The size of the data buffer actually written.
 *                          An RC is returned if actual written amount does not
 *                          match the input.
 *
 * @return 0 on success or error code on failure
 */
Bootloader::hbblReasonCode tpm_write(uint32_t i_offset, const void* i_buffer, size_t& io_buflen);

/**
 * @brief Sends the TPM Startup command to the TPM.
 *
 * @return 0 on success or error code on failure
 * @note The TPM locality needs to be set prior to calling this function
 */
Bootloader::hbblReasonCode tpmCmdStartup();

/**
 * @brief Calls the HWP to init SPI engine clock
 *
 * @return 0 on success or error code on failure
 */
Bootloader::hbblReasonCode tpm_init_spi_engine();
#endif
