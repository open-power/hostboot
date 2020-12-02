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
#include <endian.h>
#include <sys/time.h>

/** @file bl_tpm_spidd.C
 *  @brief Implementations for interfaces for TPM SPI operations in HBBL
 */

// TPM lives on SPI engine 4
#define TPM_SPI_ENGINE 4
// Max SPI transmit size
#define TPM_MAX_SPI_TRANSMIT_SIZE 64
// The length of the TPM startup command
#define TPM_STARTUP_CMD_LEN 0xC

/**
 * @brief Base response from the TPM (used to get the RC)
 */
struct TPM_BaseOut
{
    uint16_t tag;
    uint32_t responseSize; ///< Total # out bytes incl paramSize & tag
    uint32_t responseCode; ///< The return code of the operation
} PACKED;

// TPM polling timeout in NS
#define TPM_POLLING_TIMEOUT_NS 10 * NS_PER_MSEC

Bootloader::hbblReasonCode tpm_init_spi_engine()
{
    Bootloader::hbblReasonCode l_rc = Bootloader::RC_NO_ERROR;

    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_target_chip;
    SpiControlHandle l_spi_handle(l_target_chip,
                                  TPM_SPI_ENGINE,
                                  1, // i_slave
                                  true); // i_pib_access

    fapi2::ReturnCode l_fapi_rc = fapi2::FAPI2_RC_SUCCESS;
    FAPI_CALL_HWP(l_fapi_rc,
                  p10_spi_clock_init,
                  l_spi_handle);
    if(l_fapi_rc)
    {
        l_rc = Bootloader::RC_SPI_CLK_INIT_FAIL;
    }

    return l_rc;
}

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

Bootloader::hbblReasonCode tpm_write(const uint32_t i_offset, const void* i_buffer, size_t& io_buflen)
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
                  reinterpret_cast<const uint8_t*>(i_buffer));
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
    o_stsReg = 0;
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
 * @brief Helper function to check if TPM is expecting more data
 *
 * @param[out] o_isExpecting whether TPM is expecting more data
 * @return 0 on success or error code on error
 */
Bootloader::hbblReasonCode tpmIsExpecting(bool& o_isExpecting)
{
    Bootloader::hbblReasonCode l_rc = Bootloader::RC_NO_ERROR;
    TPMDD::tpm_sts_reg_t l_stsReg;

    o_isExpecting = false;
    l_rc = tpmReadSTSReg(l_stsReg);

    o_isExpecting = (l_rc == Bootloader::RC_NO_ERROR && l_stsReg.expect);
    return l_rc;
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
 * @brief Helper function to read the TPM burst count reg that indicates how
 *        many bytes the TPM can read/write.
 *
 * @param[out] o_burstCount the burst count as indicated by the TPM reg
 * @return 0 on success or error code on error
 */
Bootloader::hbblReasonCode tpmReadBurstCount(uint16_t& o_burstCount)
{
    Bootloader::hbblReasonCode l_rc = Bootloader::RC_NO_ERROR;
    o_burstCount = 0;

    uint16_t l_burstCnt = 0;
    size_t l_size = sizeof(l_burstCnt);
    l_rc = tpm_read(TPMDD::TPM_REG_75x_BURSTCOUNT, &l_burstCnt, l_size);
    if(!l_rc)
    {
        o_burstCount = le16toh(l_burstCnt);
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

/**
 * @brief Helper function to read the status valid bit from the TPM status reg
 *
 * @param[out] o_stsReg the value of the status reg
 * @return 0 on success or error code on error
 */
Bootloader::hbblReasonCode tpmReadSTSRegValid(TPMDD::tpm_sts_reg_t& o_stsReg)
{
    Bootloader::hbblReasonCode l_rc = Bootloader::RC_NO_ERROR;
    size_t l_polls = 0;

    do
    {
        l_rc = tpmReadSTSReg(o_stsReg);
        if(l_rc)
        {
            break;
        }

        if(l_polls > TPMDD::MAX_STSVALID_POLLS && !(o_stsReg.stsValid))
        {
            l_rc = Bootloader::RC_TPM_STS_TIMEOUT;
            break;
        }
        else if(!o_stsReg.stsValid)
        {
            bl_nanosleep(0, TPM_POLLING_TIMEOUT_NS); // 10 ms
            ++l_polls;
        }
    }while(!o_stsReg.stsValid);

    return l_rc;
}

/**
 * @brief Helper function to check if there is more data available from TPM
 *
 * @param[out] o_isDataAvail whether more data is available from TPM
 * @return 0 on success or error code on error
 */
Bootloader::hbblReasonCode tpmIsDataAvail(bool& o_isDataAvail)
{
    Bootloader::hbblReasonCode l_rc = Bootloader::RC_NO_ERROR;
    TPMDD::tpm_sts_reg_t l_stsReg;
    l_rc = tpmReadSTSRegValid(l_stsReg);
    o_isDataAvail = false;

    if(!l_rc && l_stsReg.dataAvail)
    {
        o_isDataAvail = true;
    }
    return l_rc;
}

/**
 * @brief Helper function to poll TPM for data available status
 *
 * @return 0 on success or error code on error
 */
Bootloader::hbblReasonCode tpmPollForDataAvail()
{
    TPMDD::tpm_sts_reg_t l_stsReg;
    Bootloader::hbblReasonCode l_rc = Bootloader::RC_NO_ERROR;
    size_t l_delay_ms = 0;

    // Use the longer timeout B here since some of the TPM commands may take
    // more than timeout A to complete
    for (l_delay_ms = 0; l_delay_ms < TPMDD::TPM_TIMEOUT_B; l_delay_ms += 10)
    {
        l_rc = tpmReadSTSRegValid(l_stsReg);
        if (l_rc == Bootloader::RC_TPM_STS_TIMEOUT)
        {
            // Polling loop within tpmReadSTSRegValid timed out, delete error and try again.
            l_rc = Bootloader::RC_NO_ERROR;
            // Ensure that dataAvail is 0, since we didn't get a good status
            l_stsReg.dataAvail = 0;
        }

        if ((!l_rc && l_stsReg.dataAvail) ||
            (l_rc))
        {
            break;
        }
        // Sleep 10ms before attempting another read
        bl_nanosleep(0, TPM_POLLING_TIMEOUT_NS);

    }

    if(l_delay_ms >= TPMDD::TPM_TIMEOUT_B)
    {
        l_rc = Bootloader::RC_TPM_TIMEOUT_B;
    }

    return l_rc;
}

/**
 * @brief Helper function to write the tpmGo bit to TPM status reg
 *
 * @return 0 on success or error code on error
 */
Bootloader::hbblReasonCode tpmWriteTpmGo()
{
    Bootloader::hbblReasonCode l_rc = Bootloader::RC_NO_ERROR;
    TPMDD::tpm_sts_reg_t l_stsReg;
    l_stsReg.tpmGo = 1;

    size_t l_size = sizeof(l_stsReg);

    l_rc = tpm_write(TPMDD::TPM_REG_75x_STS, &l_stsReg, l_size);
    return l_rc;
}

/**
 * @brief Helper function to read the TPM FIFO
 *
 * @param[out] o_buffer the buffer read from TPM FIFO
 * @param[in/out] io_buflen the amount of data to read/amount actually read
 * @return 0 on success or error code on error
 */
Bootloader::hbblReasonCode tpmReadFifo(void* o_buffer, size_t& io_buflen)
{
    Bootloader::hbblReasonCode l_rc = Bootloader::RC_NO_ERROR;
    size_t l_delay_ms = 0;
    size_t l_curByte = 0;
    bool l_firstRead = true;
    uint32_t l_dataLeft = io_buflen;

    // all command responses are at least 10 bytes of data
    // 2 byte tag + 4 byte response size + 4 byte response code
    const uint32_t MIN_COMMAND_RESPONSE_SIZE = 10;

    do {
    // Verify the TPM has data waiting for us
    l_rc = tpmPollForDataAvail();
    if(l_rc)
    {
        break;
    }

    do
    {
        size_t l_dataLen = 0;
        bool l_dataAvail = false;
        uint32_t l_responseSize = 0;
        uint8_t* l_bytePtr = static_cast<uint8_t*>(o_buffer);
        uint16_t l_burstCount = 0;

        l_rc = tpmReadBurstCount(l_burstCount);
        if(l_rc)
        {
            break;
        }
        else if(0 == l_burstCount)
        {
            // Need to delay to allow the TPM time
            bl_nanosleep(0, TPM_POLLING_TIMEOUT_NS); // 10ms
            l_delay_ms += 10;
            continue;
        }

        // Read some data
        if (l_firstRead)
        {
            l_dataLen = MIN_COMMAND_RESPONSE_SIZE;
        }
        else if (l_burstCount < l_dataLeft)
        {
            l_dataLen = l_burstCount;
        }
        else
        {
            l_dataLen = l_dataLeft;
        }

        if(l_curByte + l_dataLen > io_buflen)
        {
            // TPM is expecting more data even though we think we are done
            l_rc = Bootloader::RC_TPM_OVERFLOW;
            break;
        }

        l_delay_ms = 0;
        uint8_t* l_curBytePtr = &(l_bytePtr[l_curByte]);
        l_rc = tpm_read(TPMDD::TPM_REG_75x_RD_FIFO, l_curBytePtr, l_dataLen);
        if(l_rc)
        {
            break;
        }

        if(l_firstRead)
        {
            l_responseSize = *(reinterpret_cast<uint32_t*>((l_curBytePtr + 2)));
            l_dataLeft = l_responseSize;
            l_firstRead = false;
        }

        l_curByte += l_dataLen;
        l_dataLeft -= l_dataLen;

        l_rc = tpmIsDataAvail(l_dataAvail);
        if(l_rc || !l_dataAvail)
        {
            break;
        }
        if((l_dataLeft == 0) && l_dataAvail)
        {
            // Either the available STS is wrong or
            // responseSize in firstRead response was wrong
            l_rc = Bootloader::RC_TPM_EXTRA_DATA_AVAIL;
            break;
        }

    // Operation TIMEOUT_D defined by TCG spec for FIFO availability
    } while(l_delay_ms < TPMDD::TPM_TIMEOUT_D);
    if(l_rc)
    {
        break;
    }
    else if(l_delay_ms >= TPMDD::TPM_TIMEOUT_D)
    {
        l_rc = Bootloader::RC_TPM_READ_TIMEOUT;
        break;
    }
    else
    {
        io_buflen = l_curByte;
    }

    } while(0);

    if(l_rc)
    {
        io_buflen = 0;
    }
    return l_rc;
}

/**
 * @brief Helper function to write to TPM FIFO
 *
 * @param[in] i_buffer the buffer to write to FIFO
 * @param[in] i_buflen the size of the input buffer
 * @return 0 on success or error code on error
 */
Bootloader::hbblReasonCode tpmWriteFifo(const void* i_buffer, size_t i_buflen)
{
    Bootloader::hbblReasonCode l_rc = Bootloader::RC_NO_ERROR;
    size_t l_delay_ms = 0;
    size_t l_curByte = 0;
    const uint8_t* l_bytePtr = static_cast<const uint8_t*>(i_buffer);
    const uint8_t* l_curBytePtr = nullptr;
    uint16_t l_burstCount = 0;
    bool l_expecting = false;
    // We will transfer the command except for the last byte
    //  that will be transfered separately to allow for
    //  overflow checking
    const size_t l_length = i_buflen - 1;
    size_t l_tx_len = 0;

    do {

    do
    {
        l_rc = tpmReadBurstCount(l_burstCount);
        if(l_rc)
        {
            break;
        }
        else if (0 == l_burstCount)
        {
            // Need to delay to allow the TPM time
            bl_nanosleep(0, TPM_POLLING_TIMEOUT_NS); // 10ms
            l_delay_ms += 10;
            continue;
        }

        // Single operations are limited to TPM SPI transmit size
        if(l_burstCount > TPM_MAX_SPI_TRANSMIT_SIZE)
        {
            l_burstCount = TPM_MAX_SPI_TRANSMIT_SIZE;
        }

        // Send in some data
        l_delay_ms = 0;
        l_curBytePtr = &(l_bytePtr[l_curByte]);
        l_tx_len = (l_curByte + l_burstCount > l_length ?
                    (l_length - l_curByte) :
                    l_burstCount);
        l_rc = tpm_write(TPMDD::TPM_REG_75x_WR_FIFO, l_curBytePtr, l_tx_len);

        if(l_rc)
        {
            break;
        }
        l_curByte += l_tx_len;

        // TPM should be expecting more data from the command
        l_rc = tpmIsExpecting(l_expecting);
        if(l_rc)
        {
            break;
        }
        else if(!l_expecting)
        {
            l_rc = Bootloader::RC_TPM_NOT_EXPECTING;
            break;
        }

        // Everything but the last byte sent?
        if (l_curByte >= l_length)
        {
            break;
        }

    } while(l_delay_ms < TPMDD::TPM_TIMEOUT_D);
    if(l_rc)
    {
        break;
    }

    if(l_delay_ms >= TPMDD::TPM_TIMEOUT_D)
    {
        l_rc = Bootloader::RC_TPM_TIMEOUT_D_1;
        break;
    }

    l_delay_ms = 0;

    // Send the final byte
    do
    {
        l_rc = tpmReadBurstCount(l_burstCount);
        if(l_rc)
        {
            break;
        }
        else if(0 == l_burstCount)
        {
            // Need to delay to allow the TPM time
            bl_nanosleep(0, TPM_POLLING_TIMEOUT_NS); // 10ms
            l_delay_ms += 10;
            continue;
        }

        // Send in some data
        l_delay_ms = 0;
        l_curBytePtr = &(l_bytePtr[l_curByte]);
        l_tx_len = 1; // One last byte
        l_rc = tpm_write(TPMDD::TPM_REG_75x_WR_FIFO, l_curBytePtr, l_tx_len);
        break; // Done after writing the last byte

    } while(l_delay_ms < TPMDD::TPM_TIMEOUT_D);
    if(l_rc)
    {
        break;
    }

    if(l_delay_ms >= TPMDD::TPM_TIMEOUT_D)
    {
        l_rc = Bootloader::RC_TPM_TIMEOUT_D_2;
        break;
    }

    // The TPM should not be expecting any more data
    l_rc = tpmIsExpecting(l_expecting);
    if(l_rc)
    {
        break;
    }

    if(l_expecting)
    {
        l_rc = Bootloader::RC_TPM_IS_EXPECTING;
        break;
    }

    } while (0);
    return l_rc;
}

/**
 * @brief Helper function to transmit a command to the TPM
 *
 * @param[in/out] io_buffer the buffer containing the TPM command/TPM response
 * @param[in/out] io_buflen the size of the buffer
 * @param[in] i_commandlen the length of the TPM command
 * @return 0 on success or error code on error
 */
Bootloader::hbblReasonCode tpmTransmit(void* io_buffer,
                                              size_t& io_buflen,
                                              const size_t i_commandlen)
{
    Bootloader::hbblReasonCode l_rc = Bootloader::RC_NO_ERROR;
    bool l_isReady = false;

    do {
    // Verify the TPM is ready to receive our command
    l_rc = tpmIsCommandReady(l_isReady);
    if(l_rc)
    {
        break;
    }

    if(!l_isReady)
    {
        // set TPM into command ready state
        l_rc = tpmWriteCommandReady();
        if(l_rc)
        {
            break;
        }

        // Verify the TPM is now ready to receive our command
        l_rc = tpmPollForCommandReady();
        if(l_rc)
        {
            break;
        }
    }

    // Write the command into the TPM FIFO
    l_rc = tpmWriteFifo(io_buffer, i_commandlen);
    if(l_rc)
    {
        break;
    }

    l_rc = tpmWriteTpmGo();
    if(l_rc)
    {
        break;
    }

    // Read the response from the TPM FIFO
    l_rc = tpmReadFifo(io_buffer, io_buflen);
    if(l_rc)
    {
        break;
    }

    l_rc = tpmWriteCommandReady();
    if(l_rc)
    {
        break;
    }
    } while(0);

    return l_rc;
}

Bootloader::hbblReasonCode tpmCmdStartup()
{
    Bootloader::hbblReasonCode l_rc = Bootloader::RC_NO_ERROR;
    uint32_t l_cmdData[] = { 0x80010000, // Header and some TPM-specific params
                             0x000C0000, // TPM-specific params cont.
                             0x01440000 }; // 144 is the TPM startup command
    size_t l_cmdLen = TPM_STARTUP_CMD_LEN;

    // l_cmdData will be reused for the TPM response
    l_rc = tpmTransmit(l_cmdData,
                       l_cmdLen,
                       l_cmdLen);
    if(!l_rc)
    {
        TPM_BaseOut* l_resp = reinterpret_cast<TPM_BaseOut*>(l_cmdData);
        if(l_resp->responseCode == Bootloader::RC_NO_ERROR)
        {
            bl_console::putString("Successfully started TPM (SBE has NOT started the TPM before)\r\n");
        }
        else if(l_resp->responseCode == Bootloader::RC_TPM_INITIALIZE)
        {
            bl_console::putString("Successfully started TPM (SBE started the TPM)\r\n");
        }
        else
        {
            bl_console::putString("TPM Init fail! TPM RC: 0x");
            bl_console::displayHex(reinterpret_cast<unsigned char*>(&l_resp->responseCode), sizeof(l_resp->responseCode));
            bl_console::putString("\r\n");
            l_rc = Bootloader::RC_TPM_INIT_FAIL;
        }
    }
    return l_rc;
}

