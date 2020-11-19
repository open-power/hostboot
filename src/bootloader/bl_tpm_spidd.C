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
#include <bl_console.H>

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

/**
 * @brief Helper function to read the TPM status register
 *
 * @param[out] o_stsReg the value of the status register
 * @return 0 on success or error code on error
 */
Bootloader::hbblReasonCode tpmReadSTSReg(TPMDD::tpm_sts_reg_t& o_stsReg)
{
    size_t l_size = sizeof(o_stsReg);
    return tpm_read(TPMDD::TPM_REG_75x_STS, &o_stsReg, l_size);
}

/**
 * @brief Helper function to write a "command ready" status to TPM status reg
 *
 * @return 0 on success or error code on error
 */
Bootloader::hbblReasonCode tpmWriteCommandReady()
{
    TPMDD::tpm_sts_reg_t l_stsReg;
    l_stsReg.isCommandReady = 1;
    size_t l_size = sizeof(l_stsReg);

    return tpm_write(TPMDD::TPM_REG_75x_STS, &l_stsReg, l_size);
}

/**
 * @brief Helper function to check whether the TPM is ready for a command
 *
 * @param[out] o_isReady whether the command is ready
 * @return 0 on success or error code on error
 */
Bootloader::hbblReasonCode tpmIsCommandReady(bool& o_isReady)
{
    Bootloader::hbblReasonCode l_rc = Bootloader::RC_NO_ERROR;
    TPMDD::tpm_sts_reg_t l_stsReg;

    o_isReady = false;
    l_rc = tpmReadSTSReg(l_stsReg);

    o_isReady = (l_rc == Bootloader::RC_NO_ERROR && l_stsReg.isCommandReady);
    return l_rc;
}

/**
 * @brief Helper function to check for the command ready status in a retry loop
 *        until the TPM signals that command is ready or there is a timeout.
 *
 * @param[out] o_stsReg the value of the TPM status reg
 * @return 0 on success or error code on error
 */
Bootloader::hbblReasonCode tpmCheckCommandReadyStatus(bool& o_commandReady)
{
    Bootloader::hbblReasonCode l_rc = Bootloader::RC_NO_ERROR;
    for(size_t l_delay = 0; l_delay < TPMDD::TPM_TIMEOUT_B; l_delay += 10)
    {
        o_commandReady = false;
        l_rc = tpmIsCommandReady(o_commandReady);
        if(l_rc || o_commandReady)
        {
            break;
        }

        // Sleep for 10 ns
        bl_nanosleep(0, 10);
    }

    return l_rc;
}

/**
 * @brief Helper function to poll the TPM for command ready status. If the
 *        command is not ready the first time, we retry the command once more.
 *
 * @return 0 on success or error code on error
 */
Bootloader::hbblReasonCode tpmPollForCommandReady()
{
    Bootloader::hbblReasonCode l_rc = Bootloader::RC_NO_ERROR;
    bool l_commandReady = false;

    do {

    // First, poll for command ready status
    l_rc = tpmCheckCommandReadyStatus(l_commandReady);
    if(l_rc)
    {
        break;
    }

    if(!l_commandReady)
    {
        // The first write to command ready may have just aborted
        //   an outstanding command, we will write it again and poll once
        //   more
        l_rc = tpmWriteCommandReady();
        if(l_rc)
        {
            break;
        }

        // Poll again
        l_rc = tpmCheckCommandReadyStatus(l_commandReady);
        if(l_rc)
        {
            break;
        }
    }

    if(!l_rc && !l_commandReady)
    {
        // No RC reported but also the TPM is not ready for the command
        l_rc = Bootloader::RC_TPM_COMMAND_NOT_READY;
        break;
    }

    }while(0);

    return l_rc;
}
