/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/bootloader/bl_tpm_spidd.C $                               */
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
#include <bl_tpm_spidd.H>
#include <plat_hwp_invoker.H>
#include <p10_sbe_spi_cmd.H>

/** @file bl_tpm_spidd.C
 *  @brief Implementations for interfaces for TPM SPI operations in HBBL
 */

// TPM lives on SPI engine 4
#define TPM_SPI_ENGINE 4

Bootloader::hbblReasonCode tpm_read(const uint32_t i_offset, void* o_buffer, size_t& io_buflen)
{
    Bootloader::hbblReasonCode l_rc = Bootloader::RC_NO_ERROR;
    size_t l_origSize = io_buflen;

    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_target_chip;
    SpiControlHandle l_spi_handle(l_target_chip,
                                  TPM_SPI_ENGINE,
                                  1, // i_slave
                                  true); // i_pib_access

    fapi2::ReturnCode l_fapi_rc = fapi2::FAPI2_RC_SUCCESS;

    FAPI_CALL_HWP(l_fapi_rc,
                  spi_tpm_read_secure,
                  l_spi_handle,
                  0, // iv_locality
                  i_offset,
                  io_buflen,
                  reinterpret_cast<uint8_t*>(o_buffer));

    if(l_fapi_rc)
    {
        l_rc = Bootloader::RC_SPI_TPM_READ_FAIL;
    }
    else if(l_origSize != io_buflen)
    {
        // We read out more or less than we wanted
        l_rc = Bootloader::RC_TPM_INVALID_READ_SIZE;
    }

    return l_rc;
}

Bootloader::hbblReasonCode tpm_write(const uint32_t i_offset, void* i_buffer, size_t& io_buflen)
{
    Bootloader::hbblReasonCode l_rc = Bootloader::RC_NO_ERROR;
    size_t l_origSize = io_buflen;

    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_target_chip;
    SpiControlHandle l_spi_handle(l_target_chip,
                                  TPM_SPI_ENGINE,
                                  1, // i_slave
                                  true); // i_pib_access

    fapi2::ReturnCode l_fapi_rc = fapi2::FAPI2_RC_SUCCESS;

    FAPI_CALL_HWP(l_fapi_rc,
                  spi_tpm_write_with_wait,
                  l_spi_handle,
                  0, // iv_locality
                  i_offset,
                  io_buflen,
                  reinterpret_cast<uint8_t*>(i_buffer));
    if(l_fapi_rc)
    {
        l_rc = Bootloader::RC_SPI_TPM_WRITE_FAIL;
    }
    else if(l_origSize != io_buflen)
    {
        // We wrote more or less than we wanted
        l_rc = Bootloader::RC_TPM_INVALID_WRITE_SIZE;
    }

    return l_rc;
}
