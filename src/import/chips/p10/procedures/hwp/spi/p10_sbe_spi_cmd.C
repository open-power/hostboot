/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/spi/p10_sbe_spi_cmd.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
 * @file: p10_sbe_spi_cmd.C
 *
 * @brief This file contains and handle for SPI operations
 *
 */

#include "p10_sbe_spi_cmd.H"
#include "endian.h"

// This is required for PPE-simics compile environment
#ifdef __PPE__
    #include "sbeutil.H"
#endif

// memcpy functionality
#if __PPE42__
    #include "ppe42_string.h"
#else
    #include <string.h>
#endif

#define SPI_SLAVE_WR_CMD  0x0200000000000000
#define SPI_SLAVE_RD_CMD  0x0300000000000000
#define SPI_SLAVE_RD_STAT 0x0500000000000000
#define SPI_SLAVE_WR_EN   0x0600000000000000
#define SPI_SLAVE_ID_CMD  0x9F00000000000000

// Timeout values so not stuck in wait loops forever
constexpr uint64_t SPI_TIMEOUT_MAX_WAIT_COUNT      = 10000;   // 10 seconds
constexpr uint64_t SPI_TIMEOUT_DELAY_NS            = 1000000; // 1 msec
constexpr uint64_t SPI_TIMEOUT_DELAY_NS_SIM_CYCLES = 1000000; // 1 msec

using namespace fapi2;

// TPM SPI command
// From Trusted Computing Group(TCG) 2.0 spec for SPI Bit Protocol
// https://trustedcomputinggroup.org/wp-content/uploads/PC-Client-Specific-Platform-TPM-Profile-for-TPM-2p0-v1p04_r0p37_pub-1.pdf
typedef union
{
    struct
    {
        uint32_t readNotWrite : 1;
        uint32_t reserved : 1;
        uint32_t len : 6;
        uint32_t addr : 24;
        uint32_t reserved2: 32;
    } cmd_bits;
    uint64_t val;
} tpmSpiCmd_t;

fapi2::ReturnCode p10_spi_clock_init (
    const SpiControlHandle& i_spiHandle)
{
    fapi2::buffer<uint64_t> data64 = 0;
    const uint32_t clockRegAddr = i_spiHandle.base_addr + SPIM_CLOCKCONFIGREG;
    FAPI_TRY(getScom(i_spiHandle.target_chip,
                     clockRegAddr, data64));

    // For now, just update FSI SPI clock divider and SCK receive delay if
    // applicable.  The SPI clock divider is a ratio of unit logic to SCK, with
    // a minimum value of 0x004.  Receive delay is given in units of unit clock
    // and is used to compensate for internal and external delays.
    if(!i_spiHandle.pibAccess) // i.e. FSI SPI engine
    {
        data64.insertFromRight(FSI_SPI_CLOCK_DIVIDER, SPI_CLOCK_DIVIDER_START_BIT,
                               SPI_CLOCK_DIVIDER_LEN_BITS);

        data64.insertFromRight(spiReceiveDelay(FSI_SPI_RECEIVE_DELAY_CYCLES),
                               SPI_CLOCK_RECEIVE_DELAY_START_BIT,
                               SPI_CLOCK_RECEIVE_DELAY_LEN_BITS);

        FAPI_TRY(putScom(i_spiHandle.target_chip,
                         clockRegAddr, data64));
    }
    else
    {
        // TODO RTC:260631 Support dynamic calculation of SPI TPM clock config
        // For PIB access of engine 4 (i.e. TPM), the following clock setup register is
        // known to work.
        if (i_spiHandle.engine == SPI_ENGINE_TPM)
        {
            // SCK_CLOCK_DIVIDER: 0x015
            //      PAU_freq = 0x0855 MHz in Denali MRW
            //      spi_clock_freq = 24 MHz
            //      PIB_frequency = PAU_freq / 2
            //      divider = ( PIB_frequency / (spi_clock_freq * 2) ) - 1
            // SCK_RECEIVE_DELAY: 0x40
            // SCK_ECC_SPIMM_ADDR_CORR_DIS: 0x1  no_ecc_address_correction
            // SCK_ECC_CONTROL: 0x01  transparent_read
            data64 = 0x0154000A00000000ULL;
            FAPI_TRY(putScom(i_spiHandle.target_chip, clockRegAddr, data64));
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

fapi2::ReturnCode
spi_master_lock(SpiControlHandle& i_handle, uint64_t i_pib_master_id)
{
    // The value written to the reg doesn't matter, only that bit zero is set
    fapi2::buffer<uint64_t> data64 = 0x8000000000000000ULL;

    FAPI_TRY(putScom( i_handle.target_chip,
                      i_handle.base_addr | SPIM_CONFIGREG1, data64));

fapi_try_exit:
    return fapi2::current_err;
}

fapi2::ReturnCode
spi_master_unlock(SpiControlHandle& i_handle, uint64_t i_pib_master_id)
{
    fapi2::buffer<uint64_t> data64 = 0;

    // Figure out who owns it now so we can take it away
    FAPI_TRY(getScom( i_handle.target_chip,
                      i_handle.base_addr | SPIM_CONFIGREG1, data64));

    // Clear the lock bit
    data64.clearBit(0);

    // Write it back
    FAPI_TRY(putScom( i_handle.target_chip,
                      i_handle.base_addr | SPIM_CONFIGREG1, data64) );

fapi_try_exit:
    return fapi2::current_err;
}

// ECC methods for SPI slave status reads
static fapi2::ReturnCode
is_ecc_on(SpiControlHandle& i_handle, bool& o_ecc)
{
    fapi2::buffer<uint64_t> l_data = 0;
    uint32_t l_ecc_cntl = 0;

    FAPI_TRY(getScom(i_handle.target_chip, i_handle.base_addr + SPIM_CLOCKCONFIGREG, l_data));

    l_data.extractToRight(l_ecc_cntl, 29, 2);

    if( l_ecc_cntl % 2 == 0)
    {
        o_ecc = true;
    }
    else
    {
        o_ecc = false;
    }

fapi_try_exit:
    return fapi2::current_err;
}

static fapi2::ReturnCode
spi_set_ecc_on(SpiControlHandle& i_handle)
{
    fapi2::buffer<uint64_t> l_data = 0;
    FAPI_TRY(getScom(i_handle.target_chip, i_handle.base_addr + SPIM_CLOCKCONFIGREG, l_data));

    l_data.clearBit<30>();

    FAPI_TRY(putScom(i_handle.target_chip, i_handle.base_addr + SPIM_CLOCKCONFIGREG, l_data));

fapi_try_exit:
    return fapi2::current_err;
}

static fapi2::ReturnCode
spi_set_ecc_off(SpiControlHandle& i_handle)
{
    fapi2::buffer<uint64_t> l_data = 0;
    FAPI_TRY(getScom(i_handle.target_chip, i_handle.base_addr + SPIM_CLOCKCONFIGREG, l_data));

    l_data.setBit<30>();

    FAPI_TRY(putScom(i_handle.target_chip, i_handle.base_addr + SPIM_CLOCKCONFIGREG, l_data));

fapi_try_exit:
    return fapi2::current_err;
}

//waits for transmit-data-register empty
static fapi2::ReturnCode
spi_wait_for_tdr_empty(SpiControlHandle& i_handle)
{
    fapi2::buffer<uint64_t> data64 = 0;

    uint64_t timeout = SPI_TIMEOUT_MAX_WAIT_COUNT;

    while(timeout)
    {
        FAPI_TRY(getScom( i_handle.target_chip,
                          i_handle.base_addr + SPIM_STATUSREG, data64));

        //checking for multiplexing error
        FAPI_ASSERT( (data64.getBit<50>() == 0),
#ifndef BOOTLOADER
                     fapi2::SBE_SPI_INVALID_PORT_MULTIPLEX_SET()
                     .set_CHIP_TARGET(i_handle.target_chip)
                     .set_BASE_ADDRESS(i_handle.base_addr + SPIM_STATUSREG)
                     .set_STATUS_REGISTER(data64),
                     "Port multiplexer setting error set in spi_wait_for_tdr_empty");
#else
                     RC_SBE_SPI_INVALID_PORT_MULTIPLEX_SET);
#endif

        if(!(data64.getBit<4>()))
        {
            break; //Wait until TX Buffer is empty
        }

#ifndef __PPE__
        fapi2::delay(SPI_TIMEOUT_DELAY_NS, SPI_TIMEOUT_DELAY_NS_SIM_CYCLES);
#endif
        --timeout;
    }

    FAPI_ASSERT( timeout != 0,
#ifndef BOOTLOADER
                 fapi2::SBE_SPI_HANG_TIMEOUT()
                 .set_CHIP_TARGET(i_handle.target_chip)
                 .set_BASE_ADDRESS(i_handle.base_addr + SPIM_STATUSREG)
                 .set_STATUS_REGISTER(data64)
                 .set_TIMEOUT_MSEC(SPI_TIMEOUT_MAX_WAIT_COUNT),
                 "spi_wait_for_tdr_empty wait timeout" );
#else
                 RC_SBE_SPI_HANG_TIMEOUT );
#endif

fapi_try_exit:
    return fapi2::current_err;
}

//waits for receive-data-register full
static fapi2::ReturnCode
spi_wait_for_rdr_full(SpiControlHandle& i_handle)
{
    fapi2::buffer<uint64_t> status_reg = 0;

    uint64_t timeout = SPI_TIMEOUT_MAX_WAIT_COUNT;

    while(timeout)
    {
        FAPI_TRY(getScom( i_handle.target_chip,
                          i_handle.base_addr + SPIM_STATUSREG, status_reg));

        //checking for multiplexing error
        FAPI_ASSERT( (status_reg.getBit<50>() == 0),
#ifndef BOOTLOADER
                     fapi2::SBE_SPI_INVALID_PORT_MULTIPLEX_SET()
                     .set_CHIP_TARGET(i_handle.target_chip)
                     .set_BASE_ADDRESS(i_handle.base_addr + SPIM_STATUSREG)
                     .set_STATUS_REGISTER(status_reg),
                     "Port multiplexer setting error set in spi_wait_for_rdr_full");
#else
                     RC_SBE_SPI_INVALID_PORT_MULTIPLEX_SET);
#endif

        if(status_reg.getBit<0>()) //Wait until RX Buffer is full
        {
            break;
        }

#ifndef __PPE__
        fapi2::delay(SPI_TIMEOUT_DELAY_NS, SPI_TIMEOUT_DELAY_NS_SIM_CYCLES);
#endif
        --timeout;
    }

    FAPI_ASSERT( timeout != 0,
#ifndef BOOTLOADER
                 fapi2::SBE_SPI_HANG_TIMEOUT()
                 .set_CHIP_TARGET(i_handle.target_chip)
                 .set_BASE_ADDRESS(i_handle.base_addr + SPIM_STATUSREG)
                 .set_STATUS_REGISTER(status_reg)
                 .set_TIMEOUT_MSEC(SPI_TIMEOUT_MAX_WAIT_COUNT),
                 "spi_wait_for_rdr_full wait timeout" );
#else
                 RC_SBE_SPI_HANG_TIMEOUT );
#endif

fapi_try_exit:
    return fapi2::current_err;
}

//waits for the fsm of the spi-master to be idle
static fapi2::ReturnCode
spi_wait_for_idle(SpiControlHandle& i_handle)
{
    fapi2::buffer<uint64_t> data64 = 0;

    uint64_t timeout = SPI_TIMEOUT_MAX_WAIT_COUNT;

    while(timeout)
    {
        FAPI_TRY(getScom( i_handle.target_chip,
                          i_handle.base_addr + SPIM_STATUSREG, data64));

        //checking for multiplexing error
        FAPI_ASSERT( (data64.getBit<50>() == 0),
#ifndef BOOTLOADER
                     fapi2::SBE_SPI_INVALID_PORT_MULTIPLEX_SET()
                     .set_CHIP_TARGET(i_handle.target_chip)
                     .set_BASE_ADDRESS(i_handle.base_addr + SPIM_STATUSREG)
                     .set_STATUS_REGISTER(data64),
                     "Port multiplexer setting error set in spi_wait_for_idle");
#else
                     RC_SBE_SPI_INVALID_PORT_MULTIPLEX_SET);
#endif

        if(data64.getBit<15>())  //seq fsm Idle
        {
            break;
        }

#ifndef __PPE__
        fapi2::delay(SPI_TIMEOUT_DELAY_NS, SPI_TIMEOUT_DELAY_NS_SIM_CYCLES);
#endif
        --timeout;
    }

    FAPI_ASSERT( timeout != 0,
#ifndef BOOTLOADER
                 fapi2::SBE_SPI_HANG_TIMEOUT()
                 .set_CHIP_TARGET(i_handle.target_chip)
                 .set_BASE_ADDRESS(i_handle.base_addr + SPIM_STATUSREG)
                 .set_STATUS_REGISTER(data64)
                 .set_TIMEOUT_MSEC(SPI_TIMEOUT_MAX_WAIT_COUNT),
                 "spi_wait_for_idle wait timeout" );
#else
                 RC_SBE_SPI_HANG_TIMEOUT );
#endif

fapi_try_exit:
    return fapi2::current_err;
}

//@nlandi Note: in order for SPI slave status reads to not cause an ECC error, ECC must be turned off for
//              the duration of the read
//waits for write complete flag of the spi-slave
static fapi2::ReturnCode
spi_wait_for_write_complete(SpiControlHandle& i_handle)
{
    fapi2::buffer<uint64_t> data64 = 0;
    fapi2::ReturnCode rc;
    bool l_ecc = false;

    is_ecc_on(i_handle, l_ecc);

    if (l_ecc)
    {
        spi_set_ecc_off(i_handle);
    }

    uint64_t SEQ = 0x1031411000000000ULL;
    SEQ |= ((uint64_t)((i_handle.slave)) << 56);
    FAPI_TRY(putScom(i_handle.target_chip, i_handle.base_addr + SPIM_SEQREG, SEQ));

    while(1)
    {
        //Send the read status register command(0x05)
        FAPI_TRY(putScom( i_handle.target_chip,
                          i_handle.base_addr + SPIM_TDR, SPI_SLAVE_RD_STAT));
        rc = spi_wait_for_rdr_full(i_handle);  //Wait for response

        if (rc)
        {
            FAPI_ERR("Error in spi_wait_for_rdr_full ");
            fapi2::current_err = rc;
            goto fapi_try_exit;
        }

        FAPI_TRY(getScom(i_handle.target_chip, i_handle.base_addr + SPIM_RDR, data64));

        if(!(data64.getBit<63>()))
        {
            break; //Check for  RDY/BSY bit in the slave status register
        }

        rc = spi_wait_for_idle(i_handle);

        if (rc)
        {
            FAPI_ERR("Multiplexing Error in spi_wait_for_idle ");
            fapi2::current_err = rc;
            goto fapi_try_exit;
        }
    }

    if(l_ecc)
    {
        spi_set_ecc_on(i_handle);
    }

fapi_try_exit:
    return fapi2::current_err;
}

// Poll SPI slave to see if a write has been enabled yet
static fapi2::ReturnCode
spi_check_write_enable(SpiControlHandle& i_handle)
{
    fapi2::buffer<uint64_t> data64 = 0;
    fapi2::ReturnCode rc = fapi2::FAPI2_RC_SUCCESS;
    uint64_t SEQ = 0x1031411000000000ULL;
    SEQ |= ((uint64_t)((i_handle.slave)) << 56);
    bool l_ecc;

    FAPI_TRY(putScom(i_handle.target_chip, i_handle.base_addr + SPIM_SEQREG, SEQ));

    is_ecc_on(i_handle, l_ecc);

    if (l_ecc)
    {
        spi_set_ecc_off(i_handle);
    }

    while(1)
    {
        //Send the read status register command
        FAPI_TRY(putScom(i_handle.target_chip,
                         i_handle.base_addr + SPIM_TDR, SPI_SLAVE_RD_STAT));
        rc = spi_wait_for_rdr_full(i_handle);

        if (rc)
        {
            FAPI_ERR("Error in spi_wait_for_rdr_full");
            fapi2::current_err = rc;
            goto fapi_try_exit;
        }

        FAPI_TRY(getScom(i_handle.target_chip, i_handle.base_addr + SPIM_RDR, data64));

        if(data64.getBit<62>())
        {
            break; //Check for write enable latch bit
        }

        rc = spi_wait_for_idle(i_handle);

        if (rc)
        {
            FAPI_ERR("Multiplexing Error in spi_wait_for_idle ");
            fapi2::current_err = rc;
            goto fapi_try_exit;
        }
    }

    if(l_ecc)
    {
        spi_set_ecc_on(i_handle);
    }

fapi_try_exit:
    return fapi2::current_err;
}

//enables SPI-slave write
static fapi2::ReturnCode
spi_set_write_enable(SpiControlHandle& i_handle)
{
    fapi2::ReturnCode rc = fapi2::FAPI2_RC_SUCCESS;
    uint64_t SEQ = 0x1031100000000000ULL;
    SEQ |= ((uint64_t)((i_handle.slave)) << 56);
    uint64_t TDR = SPI_SLAVE_WR_EN;

    FAPI_TRY(putScom(i_handle.target_chip, i_handle.base_addr + SPIM_SEQREG, SEQ));
    FAPI_TRY(putScom(i_handle.target_chip, i_handle.base_addr + SPIM_TDR, TDR));

    rc = spi_wait_for_tdr_empty(i_handle);

    if (rc)
    {
        FAPI_ERR("Error in spi_wait_for_tdr_empty ");
        fapi2::current_err = rc;
        goto fapi_try_exit;
    }

    rc = spi_wait_for_idle(i_handle);

    if (rc)
    {
        FAPI_ERR("Multiplexing Error in spi_wait_for_idle ");
        fapi2::current_err = rc;
        goto fapi_try_exit;
    }

    rc = spi_check_write_enable(i_handle);

    if (rc)
    {
        FAPI_ERR("Error in spi_check_write_enable");
        fapi2::current_err = rc;
        goto fapi_try_exit;
    }

fapi_try_exit:
    return fapi2::current_err;
}

//Check the h/w is in the expected state
static fapi2::ReturnCode
spi_precheck(SpiControlHandle& i_handle)
{
    fapi2::buffer<uint64_t> status_reg = 0;
    uint64_t temp, flags;

    FAPI_TRY(getScom(i_handle.target_chip,
                     i_handle.base_addr + SPIM_STATUSREG, status_reg));
    status_reg.extract<0, 64>(temp);
    flags = SPI_RDR_FULL | SPI_RDR_OVERRUN |
            SPI_RDR_UNDERRUN | SPI_TDR_FULL |
            SPI_TDR_OVERRUN /*| SPI_TDR_UNDERRUN*/;

    // Check the h/w is in the expected state
    FAPI_ASSERT( !(temp & flags),
#ifndef BOOTLOADER
                 fapi2::SBE_SPI_CMD_STATUS_REG_UNSUPPORTED_STATE()
                 .set_CHIP_TARGET(i_handle.target_chip)
                 .set_BASE_ADDRESS(i_handle.base_addr + SPIM_STATUSREG)
                 .set_STATUS_REGISTER(temp)
                 .set_CHECK_FLAGS(flags),
                 "SPI status register state bits check validation failed.");
#else
                 RC_SBE_SPI_CMD_STATUS_REG_UNSUPPORTED_STATE);
#endif
fapi_try_exit:
    return fapi2::current_err;
}

/**
 * @brief Wait for sequence index to be executed
 *        Read the STATUSREG and check that the status indicates
 *        it has passed index
 *
 * @param[in]  i_handle - handle for SPI operations
 * @param[in]  i_index - SEQ index to check has executed
 * @return     Error RC if timeout or multiplexing error detected
 */
static fapi2::ReturnCode
spi_wait_for_seq_index_pass(SpiControlHandle& i_handle, const uint32_t i_index)
{
    fapi2::buffer<uint64_t> status_reg = 0;

    uint64_t timeout = SPI_TIMEOUT_MAX_WAIT_COUNT;

    while(timeout--)
    {
        FAPI_TRY(getScom( i_handle.target_chip,
                          i_handle.base_addr + SPIM_STATUSREG, status_reg));

        //checking for multiplexing error
        FAPI_ASSERT( (status_reg.getBit<50>() == 0),
#ifndef BOOTLOADER
                     fapi2::SBE_SPI_INVALID_PORT_MULTIPLEX_SET()
                     .set_CHIP_TARGET(i_handle.target_chip)
                     .set_BASE_ADDRESS(i_handle.base_addr + SPIM_STATUSREG)
                     .set_STATUS_REGISTER(status_reg),
                     "Port multiplexer setting error set in wait_for_seq_index_pass");
#else
                     RC_SBE_SPI_INVALID_PORT_MULTIPLEX_SET);
#endif

        // 28 to 31 Sequencer index - Sequence index currently being executed
        status_reg = (status_reg >> 32) & 0x000000000000000FULL;

        if(status_reg > i_index)
        {
            break;
        }

#ifndef __PPE__
        fapi2::delay(SPI_TIMEOUT_DELAY_NS, SPI_TIMEOUT_DELAY_NS_SIM_CYCLES);
#endif
    }

    FAPI_DBG("wait_for_seq_index_pass(%d) timeout %lld msec", i_index, timeout);
    FAPI_ASSERT( timeout != 0,
#ifndef BOOTLOADER
                 fapi2::SBE_SPI_HANG_TIMEOUT()
                 .set_CHIP_TARGET(i_handle.target_chip)
                 .set_BASE_ADDRESS(i_handle.base_addr + SPIM_STATUSREG)
                 .set_STATUS_REGISTER(status_reg)
                 .set_TIMEOUT_MSEC(SPI_TIMEOUT_MAX_WAIT_COUNT),
                 "wait_for_seq_index_pass(%d) wait timeout", i_index);
#else
                 RC_SBE_SPI_HANG_TIMEOUT);
#endif

fapi_try_exit:
    return fapi2::current_err;
}

fapi2::ReturnCode spi_tpm_write_with_wait( SpiControlHandle& i_handle,
        const uint32_t i_locality,
        const uint32_t i_address,
        const uint8_t i_length,
        const uint8_t* i_buffer )
{
    uint64_t SEQ = 0;
    uint64_t CNT = 0;
    fapi2::buffer<uint64_t> data64 = 0;

    // Trusted Computing Group (TCG) standard requires
    // 3-byte addressing for SPI TPM operations
    // Change into TPM address on SPI ( D4_[locality]xxxh )
    uint32_t l_address = 0x00D40000 + (i_locality << 12) + (i_address & 0x0FFF);
    fapi2::ReturnCode rc = fapi2::FAPI2_RC_SUCCESS;
    tpmSpiCmd_t startWriteCmd = {0};

    // Looking for last byte being a 0x01 which indicates end of wait period
    uint64_t memory_mapping_reg = 0x00000000FF01FF00;

    if(i_length <= 8)
    {
        // Sequencer Basic Operations
        //    0x1X = Select_Slave X -Select slave X (X = handle.slave)
        //        34 = Shift_N1 - M = 4 bytes of data being sent in TDR
        //          41 = Shift_N2 - M = 1 byte to receive
        //            62 = Branch if Not Equal RDR   -- use memory_mapping_reg
        //              3M = Shift_N1 - M = i_length bytes of data to send
        //                10 = select_slave 0 - deselect any slave
        //                  00 = STOP
        SEQ = 0x1034416230100000ULL | (static_cast<uint64_t>(i_length) << 24) |
              (static_cast<uint64_t>(i_handle.slave) << 56);
        CNT = ((0x65) << 8);
    }
    else if((i_length % 8) == 0)
    {
        // Sequencer Basic Operations
        //    0x1X = Select_Slave X -Select slave X (X = handle.slave)
        //        34 = Shift_N1 - M = 4 bytes of data being sent in TDR
        //          41 = Shift_N2 - M = 1 byte to receive
        //            62 = Branch if Not Equal RDR   -- use memory_mapping_reg
        //              38 = Shift_N1 - M = 8 bytes of data to sendg
        //                E4 = Branch to index 4 if not Equal and increment loop counter
        //                  10 = select_slave 0 - deselect any slave
        //                    00 = STOP
        SEQ = 0x1034416238E41000ULL | (static_cast<uint64_t>(i_handle.slave) << 56);
        CNT = (static_cast<uint64_t>((i_length / 8) - 1) << 32) | ((0x65) << 8);
    }
    else
    {
        // Sequencer Basic Operations
        //    0x1X = Select_Slave X -Select slave X (X = handle.slave)
        //        34 = Shift_N1 - M = 4 bytes of data being sent in TDR
        //          41 = Shift_N2 - M = 1 byte to receive
        //            62 = Branch if Not Equal RDR   -- use memory_mapping_reg
        //              38 = Shift_N1 - M = 8 bytes of data to send
        //                E4 = Branch to index 4 if not Equal and increment loop counter
        //                  3M = Shift_N1 - M = i_length%8 of remaining data sent in TDR
        //                    10 = select_slave 0 - deselect any slave
        SEQ = 0x1034416238E43010ULL | (static_cast<uint64_t>((i_length) % 8) << 8) |
              (static_cast<uint64_t>(i_handle.slave) << 56);
        CNT = (static_cast<uint64_t>((i_length / 8) - 1) << 32) | ((0x65) << 8);
    }

    // Initial TDR command
    startWriteCmd.cmd_bits.readNotWrite = 0;
    startWriteCmd.cmd_bits.len = ((i_length - 1) & 0x3F);
    startWriteCmd.cmd_bits.addr = l_address;


    FAPI_DBG("Address: 0x%08X, SEQ: 0x%016X", i_handle.base_addr + SPIM_SEQREG, SEQ);
    FAPI_TRY(putScom(i_handle.target_chip, i_handle.base_addr + SPIM_SEQREG, SEQ));
    FAPI_DBG("Address: 0x%08X, MEMORY_MAPPING_REG: 0x%016X", i_handle.base_addr + SPIM_MMSPISMREG, memory_mapping_reg);
    FAPI_TRY(putScom(i_handle.target_chip, i_handle.base_addr + SPIM_MMSPISMREG, memory_mapping_reg));
    FAPI_DBG("Address: 0x%08X, CNT: 0x%016X", i_handle.base_addr + SPIM_COUNTERREG, CNT);
    FAPI_TRY(putScom(i_handle.target_chip, i_handle.base_addr + SPIM_COUNTERREG, CNT));
    FAPI_DBG("Address: 0x%08X, TDR: 0x%016X", i_handle.base_addr + SPIM_TDR, startWriteCmd.val);
    FAPI_TRY(putScom(i_handle.target_chip, i_handle.base_addr + SPIM_TDR, startWriteCmd.val));


    // wait until sequence index 3 has executed
    rc = spi_wait_for_seq_index_pass(i_handle, 3);

    if (rc)
    {
        FAPI_ERR("Error in wait_for_seq_index_pass, rc: 0x%08X", static_cast<uint32_t>(rc));
        fapi2::current_err = rc;
        goto fapi_try_exit;
    }

    data64 = 0;

    // break data up into 8-byte sections
    for(int i = 0; i < i_length; i++)
    {
        data64 = (data64 << 8) | ((uint8_t)i_buffer[i]);

        if( ((i % 8) == 7) || (i == (i_length - 1)) )
        {
            // left-justify data if not full 8-bytes added
            if ( (i_length < 8) ||
                 ((i == (i_length - 1)) && ((i_length % 8) != 0)) )
            {
                data64 = data64 << (8 * (8 - i_length % 8));
            }

            rc = spi_wait_for_tdr_empty(i_handle);

            if (rc)
            {
                FAPI_ERR("Error in spi_wait_for_tdr_empty ");
                fapi2::current_err = rc;
                goto fapi_try_exit;
            }

            FAPI_DBG("tpm_write() TDR: 0x%016X", data64);
            FAPI_TRY(putScom(i_handle.target_chip, i_handle.base_addr + SPIM_TDR, data64));
        }
    }

    rc = spi_wait_for_idle(i_handle);

    if (rc)
    {
        FAPI_ERR("Multiplexing error or timeout from spi_wait_for_idle ");
        fapi2::current_err = rc;
        goto fapi_try_exit;
    }

fapi_try_exit:
    FAPI_DBG("spi_tpm_write_with_wait() exit. RC: 0x%08X", static_cast<uint32_t>(rc));
    return rc;
}


/**
  * @brief  Internal read TPM with wait
  *         Secure TPM reads will call this with i_length <= 8
  *         Non-secure TPM reads can call this with i_length > 8
  *
  * @param[in] i_handle   Reference to SPI control handle
  * @param[in] i_address  TPM address on SPI in the form of: 0xD4_[locality]xxxh
  * @param[in] i_length   Length in bytes to read
  * @param[out]o_buffer   Buffer where the data read will be copied into
  *
  * @return FAPI2_RC_SUCCESS if the spi read completes successfully,
  *         else error code.
  */
fapi2::ReturnCode spi_tpm_read_internal_with_wait( SpiControlHandle& i_handle,
        const uint32_t i_address,
        uint8_t i_length,
        uint8_t* o_buffer )
{
    uint64_t SEQ;
    uint64_t CNT;
    fapi2::buffer<uint64_t> data64 = 0;
    uint64_t temp = 0;
    fapi2::ReturnCode rc = fapi2::FAPI2_RC_SUCCESS;
    tpmSpiCmd_t startReadCmd = {0};

    // Looking for last byte being a 0x01 which indicates end of wait period
    uint64_t memory_mapping_reg = 0x00000000FF01FF00;

    if(i_length <= 8)
    {
        // Sequencer Basic Operations
        //    0x1X = Select_Slave X -Select slave X (X = handle.slave)
        //        34 = Shift_N1 - M = 4 bytes of data being sent in TDR
        //          41 = Shift_N2 - M = 1 byte to receive
        //            62 = Branch if Not Equal RDR   -- use memory_mapping_reg
        //              4X = Shift_N2 - X bytes to receive (X=length)
        //                10 = select_slave 0 - deselect any slave
        //                  00 = STOP
        // Shift out 4 bytes of TDR (the read/write bit, the size, the address),
        // then switch to reading and if the next bytes is not 1, then go to
        // sequence opcode (2), and keep doing that until the data is 0x1.
        // (that covers the flow control), then start reading the actual # of
        // bytes the TPM is trying to send back
        SEQ = 0x1034416240100000ULL | (static_cast<uint64_t>(i_length) << 24) |
              (static_cast<uint64_t>(i_handle.slave) << 56);
        CNT = ((0x6F) << 8);
    }
    else if((i_length % 8) == 0)
    {
        // NON-SECURE OPERATION - 0xEx cmd op not allowed
        // Sequencer Basic Operations
        //    0x1X = Select_Slave X -Select slave X (X = handle.slave)
        //        34 = Shift_N1 - M = 4 bytes of data being sent in TDR
        //          41 = Shift_N2 - M = 1 byte to receive
        //            62 = Branch if Not Equal RDR   -- use memory_mapping_reg
        //              48 = Shift_N2 - 8 bytes to receive
        //                E4 = Branch if Not Equal and Increment - SEQ opcode (4)
        //                  10 = select_slave 0 - deselect any slave
        //                    00 = STOP
        SEQ = 0x1034416248E41000ULL | (static_cast<uint64_t>(i_handle.slave) << 56);
        CNT = (static_cast<uint64_t>((i_length / 8) - 1) << 32) | ((0x6F) << 8);
    }
    else
    {
        // NON-SECURE OPERATION - 0xEx cmd op not allowed
        // Sequencer Basic Operations
        //    0x1X = Select_Slave X -Select slave X (X = handle.slave)
        //        34 = Shift_N1 - M = 4 bytes of data being sent in TDR
        //          41 = Shift_N2 - M = 1 byte to receive
        //            62 = Branch if Not Equal RDR   -- use memory_mapping_reg
        //              48 = Shift_N2 - 8 bytes to receive
        //                E4 = Branch if Not Equal and Increment - SEQ opcode (4)
        //                  40 = Shift_N2 - 0 bytes to receive
        //                    10 = select_slave 0 - deselect any slave
        //                      00 = STOP
        SEQ = 0x1034416248E44010ULL | (static_cast<uint64_t>((i_length) % 8) << 8)
              | (static_cast<uint64_t>(i_handle.slave) << 56);
        CNT = (static_cast<uint64_t>((i_length / 8) - 1) << 32) | ((0x6F) << 8);
    }

    // Initial TDR command
    startReadCmd.cmd_bits.readNotWrite = 1;
    startReadCmd.cmd_bits.len = ((i_length - 1) & 0x3F);
    startReadCmd.cmd_bits.addr = i_address;

    FAPI_DBG("Address: 0x%08X, SEQ: 0x%016X", i_handle.base_addr + SPIM_SEQREG, SEQ);
    FAPI_TRY(putScom(i_handle.target_chip, i_handle.base_addr + SPIM_SEQREG, SEQ));
    FAPI_DBG("Address: 0x%08X, MMSPIMREG: 0x%016X", i_handle.base_addr + SPIM_MMSPISMREG, memory_mapping_reg);
    FAPI_TRY(putScom(i_handle.target_chip, i_handle.base_addr + SPIM_MMSPISMREG, memory_mapping_reg));
    FAPI_DBG("Address: 0x%08X, COUNTERREG: 0x%016X", i_handle.base_addr + SPIM_COUNTERREG, CNT);
    FAPI_TRY(putScom(i_handle.target_chip, i_handle.base_addr + SPIM_COUNTERREG, CNT));
    FAPI_DBG("Address: 0x%08X, TDR: 0x%016X", i_handle.base_addr + SPIM_TDR, startReadCmd.val);
    FAPI_TRY(putScom(i_handle.target_chip, i_handle.base_addr + SPIM_TDR, startReadCmd.val));
    FAPI_DBG("spi_wait_for_tdr_empty()");
    rc = spi_wait_for_tdr_empty(i_handle);

    if (rc)
    {
        FAPI_ERR("Error in spi_wait_for_tdr_empty");
        fapi2::current_err = rc;
        goto fapi_try_exit;
    }

    FAPI_DBG("spi_wait_for_tdr_empty() done, TDR 0");
    FAPI_TRY(putScom(i_handle.target_chip, i_handle.base_addr + SPIM_TDR, 0x0ULL));
    FAPI_DBG("TDR 0 done");

    //receive data
    if(i_length <= 8)
    {
        rc = spi_wait_for_rdr_full(i_handle);  //Wait for response

        if (rc)
        {
            FAPI_ERR("Error in spi_wait_for_rdr_full");
            fapi2::current_err = rc;
            goto fapi_try_exit;
        }

        FAPI_TRY(getScom(i_handle.target_chip, i_handle.base_addr + SPIM_RDR, data64));
        data64.extract<0, 64>(temp);

        FAPI_DBG("spi_wait_for_rdr_full finished, data read from rdr: 0x%016X", temp);

        // The value read from this RDR register is right-aligned.
        // Only copy the requested bytes of data
        temp = temp << ((8 - i_length) * 8);
#ifndef __PPE__
        memcpy(o_buffer, &temp, i_length);
#else
        uint8_t* tempPtr = (uint8_t*)&temp;

        for(uint32_t i = 0; i < i_length; i++)
        {
            *(o_buffer + i) = *(tempPtr + i);
            FAPI_DBG("Output buffer is 0x%02X", *(o_buffer + i));
        }

#endif
    }
    else
    {

        for (uint32_t i = 0; i < static_cast<uint32_t>(i_length - 7); i += 8)
        {
            rc = spi_wait_for_rdr_full(i_handle);  //Wait for response

            if (rc)
            {
                FAPI_ERR("Error in spi_wait_for_rdr_full");
                fapi2::current_err = rc;
                goto fapi_try_exit;
            }

            FAPI_TRY(getScom(i_handle.target_chip, i_handle.base_addr + SPIM_RDR, data64));
            data64.extract<0, 64>(temp);
            FAPI_DBG("%d) spi_wait_for_rdr_full finished, data read from rdr: 0x%016X", i, temp);

            // add the full 8 bytes to buffer
            reinterpret_cast<uint64_t*>(o_buffer)[i / 8] = temp;
        }

        if ((i_length % 8 != 0) && (i_length > 8))
        {
            rc = spi_wait_for_rdr_full(i_handle);  //Wait for response

            if (rc)
            {
                FAPI_ERR("Error in spi_wait_for_rdr_full");
                fapi2::current_err = rc;
                goto fapi_try_exit;
            }

            FAPI_TRY(getScom(i_handle.target_chip, i_handle.base_addr + SPIM_RDR, data64));
            data64.extract<0, 64>(temp);
            FAPI_DBG("Read RDR data: 0x%016X", temp);

            // The value read from this RDR register is right-aligned.
            // Only copy the remaining requested bytes of data
            temp = temp << ((8 - (i_length % 8)) * 8);
            FAPI_DBG("Copy %d bytes of right-aligned shifted RDR: 0x%016X",
                     i_length % 8, temp);
#ifndef __PPE__
            memcpy(&o_buffer[i_length - (i_length % 8)], &temp, i_length % 8);
#else
            uint8_t* tempPtr = (uint8_t*)&temp;

            for(uint32_t i = 0; i < (i_length % 8); i++)
            {
                *(o_buffer + i_length - (i_length % 8) + i) = *(tempPtr + i);
                FAPI_DBG("Output buffer is 0x%02X", *(o_buffer + i));
            }

#endif
        }
    }

    FAPI_DBG("spi_tpm_read_with_wait: spi_wait_for_idle");
    rc = spi_wait_for_idle(i_handle);
    FAPI_DBG("spi_tpm_read_with_wait: spi_wait_for_idle done");

    if (rc)
    {
        FAPI_ERR("Multiplexing error in spi_wait_for_idle");
        fapi2::current_err = rc;
        goto fapi_try_exit;
    }

fapi_try_exit:
    FAPI_DBG("spi_tpm_read_with_wait() exit. RC: 0x%02X", static_cast<int>(rc));
    return rc;
}


fapi2::ReturnCode spi_tpm_read_secure( SpiControlHandle& i_handle,
                                       const uint32_t i_locality,
                                       const uint32_t i_address,
                                       const uint8_t i_length,
                                       uint8_t* o_buffer )
{
    fapi2::ReturnCode rc = fapi2::FAPI2_RC_SUCCESS;
    uint8_t readlen = i_length;  // try to read full length if possible

    // Trusted Computing Group (TCG) standard requires
    // 3-byte addressing for SPI TPM operations
    // Change into TPM address on SPI ( D4_[locality]xxxh )
    uint32_t l_address = 0x00D40000 + (i_locality << 12) + (i_address & 0x0FFF);

    // 0xEX Op code is not allowed in secure mode so need to split
    // read into multiple transactions of TPM_SECURE_READ_TRNS max size
    do
    {
        if (i_length <= TPM_SECURE_READ_TRNS)
        {
            rc = spi_tpm_read_internal_with_wait( i_handle, l_address, readlen, o_buffer );
            break;
        }

        for(uint8_t i = 0; i < i_length; i += TPM_SECURE_READ_TRNS)
        {
            readlen = (i_length - i) < TPM_SECURE_READ_TRNS ?
                      (i_length - i) : TPM_SECURE_READ_TRNS;

            if (readlen == 0)
            {
                break;
            }

            rc = spi_tpm_read_internal_with_wait( i_handle, l_address, readlen, o_buffer );

            if (rc != fapi2::FAPI2_RC_SUCCESS)
            {
                FAPI_ERR( "spi_tpm_read_secure: "
                          "Failed address 0x%04X read at %d bytes out of %d total",
                          l_address, i, i_length);
                break;
            }

            o_buffer += readlen;
        }
    }
    while(0);

    return rc;
}

fapi2::ReturnCode spi_read_manufacturer_id(SpiControlHandle& i_handle, uint8_t* o_buffer)
{
    fapi2::buffer<uint64_t> data64;
    uint64_t temp = 0;
    // The sequence that will write the op code and then read five bytes of manufacturer id.
    uint64_t SEQ = 0x1031451000000000ULL | ((uint64_t)((i_handle.slave)) << 56);
    // Ensure the Counter Config Reg is cleared as this function doesn't require loop logic and default settings
    // will be sufficient enough.
    uint64_t CNT = 0x0ULL;
    // The value to write into the TDR, this is just the op code that requests the manufacturer id
    // from the slave device.
    uint64_t TDR = SPI_SLAVE_ID_CMD;

    fapi2::ReturnCode rc = fapi2::FAPI2_RC_SUCCESS;

    // If ECC is on then it will need to be off to avoid errors.
    bool l_ecc = false;
    is_ecc_on(i_handle, l_ecc);

    if (l_ecc)
    {
        spi_set_ecc_off(i_handle);
    }

    // Check the state of the h/w
    rc = spi_precheck(i_handle);

    if (rc != fapi2::FAPI2_RC_SUCCESS)
    {
        return rc;
    }

    // Set the sequence
    FAPI_TRY(putScom(i_handle.target_chip, i_handle.base_addr + SPIM_SEQREG, SEQ));

    // Clear the Counter Config Reg
    FAPI_TRY(putScom(i_handle.target_chip, i_handle.base_addr + SPIM_COUNTERREG, CNT));

    // Write the op code to the TDR, this executes the sequence.
    FAPI_TRY(putScom(i_handle.target_chip, i_handle.base_addr + SPIM_TDR, TDR));

    // Wait for the RDR to be full
    rc = spi_wait_for_rdr_full(i_handle);

    if (rc)
    {
        FAPI_ERR("Error in spi_wait_for_rdr_full");
        fapi2::current_err = rc;
        goto fapi_try_exit;
    }

    // Read the manufacturer id from the RDR.
    FAPI_TRY(getScom(i_handle.target_chip, i_handle.base_addr + SPIM_RDR, data64));

    // Since this read was less than 8 bytes, there are 3 bytes of "don't care" in the RDR.
    // So, just extract off the data we care about and return that.
    // RDR is a right aligned reg, so use the right aligned extract since caller expects right
    // aligned return data per the spec.
    data64.extractToRight<24, 40>(temp);
#ifndef _BIG_ENDIAN
    fapi2::endian_swap(temp);
#endif

    *((uint64_t*)o_buffer) = temp;

    rc = spi_wait_for_idle(i_handle);

    if (rc)
    {
        FAPI_ERR("Multiplexing Error in spi_wait_for_idle ");
        fapi2::current_err = rc;
        goto fapi_try_exit;
    }

    // Restore the default counter and seq used by the side band path
    FAPI_TRY(putScom(i_handle.target_chip,
                     i_handle.base_addr + SPIM_SEQREG, SPI_DEFAULT_SEQ));

    if (l_ecc)
    {
        spi_set_ecc_on(i_handle);
    }

fapi_try_exit:
    return fapi2::current_err;
}


//Reads data. For this implementation of one time use to counter,
//we can read at max of MAX_LENGTH_TRNS.
//Length should be multiple of 8
/* Steps to read the seeprom.
 * 1. Send the READ command along with the address.
 * 2. Configure count control
 * 3. SEEPROM will start sending the data from that offset
 *    continuously.
 * 4. Read the data. Use the loop mode if more than 8 byte reads
 * 5. Deselect the slave to stop it from sending any more data
 *
 */
static fapi2::ReturnCode
spi_read_internal(SpiControlHandle& i_handle, uint32_t i_address, uint32_t i_length,
                  uint8_t* o_buffer, SPI_ECC_CONTROL_STATUS i_eccStatus)
{
    fapi2::buffer<uint64_t> data64;
    uint64_t temp;
    uint64_t SEQ;
    uint64_t CNT = 0;
    uint64_t TDR;
    fapi2::ReturnCode rc = fapi2::FAPI2_RC_SUCCESS;

    if ((i_length > MAX_LENGTH_TRNS) || (i_length % 8))
    {
        return fapi2::FAPI2_RC_INVALID_PARAMETER;
    }


    if((i_eccStatus == STANDARD_ECC_ACCESS) ||
       (i_eccStatus == DISCARD_ECC_ACCESS)   )
    {
        if (i_address % 8) //Address should be aligned for ecc
        {
            return fapi2::FAPI2_RC_INVALID_PARAMETER;
        }

        if (i_length == 8)
        {
            SEQ = 0x1034491000000000ULL;
        }
        else
        {
            SEQ = 0x103449E210000000ULL;
        }

        i_address = i_address * 9 / 8;
    }
    else
    {
        if (i_length == 8)
        {
            SEQ = 0x1034481000000000ULL;
        }
        else
        {
            SEQ = 0x103448E210000000ULL;
        }
    }

    SEQ |= ((uint64_t)((i_handle.slave)) << 56);

    //Check the state of the h/w
    rc = spi_precheck(i_handle);

    if (rc != fapi2::FAPI2_RC_SUCCESS)
    {
        return rc;
    }

    /*Read command (0x3)|| address in TDR to be sent to the slave*/
    TDR = SPI_SLAVE_RD_CMD | ((uint64_t)i_address << 32);

    FAPI_TRY(putScom(i_handle.target_chip, i_handle.base_addr + SPIM_SEQREG, SEQ));

    /*Generate the loop counter value*/
    if (i_length > 8)
    {
        CNT = ((uint64_t)(((i_length + 7) / 8) - 1) << 32);
        //Use counter reload N2 to avoid RDR overflows
    }

    CNT = CNT | ((uint64_t)(0xF) << 8);
    FAPI_TRY(putScom(i_handle.target_chip,
                     i_handle.base_addr + SPIM_COUNTERREG, CNT));


    FAPI_TRY(putScom(i_handle.target_chip, i_handle.base_addr + SPIM_TDR, TDR));
    rc = spi_wait_for_tdr_empty(i_handle);

    if (rc)
    {
        FAPI_ERR("Error in spi_wait_for_tdr_empty ");
        fapi2::current_err = rc;
        goto fapi_try_exit;
    }

    FAPI_TRY(putScom(i_handle.target_chip, i_handle.base_addr + SPIM_TDR, 0x0ULL));

    for (uint32_t i = 0; i < i_length; i += 8)
    {
        rc = spi_wait_for_rdr_full(i_handle);

        if (rc)
        {
            FAPI_ERR("Error in spi_wait_for_rdr_full");
            fapi2::current_err = rc;
            goto fapi_try_exit;
        }

        FAPI_TRY(getScom(i_handle.target_chip, i_handle.base_addr + SPIM_RDR, data64));
        data64.extract<0, 64>(temp);
#ifndef _BIG_ENDIAN
        fapi2::endian_swap(temp);
#endif
        ((uint64_t*)o_buffer)[i / 8] = temp;
    }

    rc = spi_wait_for_idle(i_handle);

    if (rc)
    {
        FAPI_ERR("Multiplexing Error in spi_wait_for_idle ");
        fapi2::current_err = rc;
        goto fapi_try_exit;
    }

    /*Restore the default counter and seq used by the side band path*/
    FAPI_TRY(putScom(i_handle.target_chip, i_handle.base_addr + SPIM_COUNTERREG, 0x0ULL));
    FAPI_TRY(putScom(i_handle.target_chip,
                     i_handle.base_addr + SPIM_SEQREG, SPI_DEFAULT_SEQ));

fapi_try_exit:
    return fapi2::current_err;
}

fapi2::ReturnCode
spi_read( SpiControlHandle& i_handle, uint32_t i_address, uint32_t i_length,
          SPI_ECC_CONTROL_STATUS i_eccStatus, uint8_t* o_buffer )
{
    fapi2::ReturnCode rc  = fapi2::FAPI2_RC_SUCCESS;
    uint32_t readlen = 0, i;
    bool l_ecc = false;
    is_ecc_on(i_handle, l_ecc);

    if ((i_eccStatus == RAW_BYTE_ACCESS) && (l_ecc))
    {
        spi_set_ecc_off(i_handle);
    }

    do
    {

        if (i_length <= MAX_LENGTH_TRNS)
        {
            rc = spi_read_internal( i_handle, i_address,
                                    i_length, o_buffer, i_eccStatus );
            break;
        }

        for(i = 0; i < i_length; i += MAX_LENGTH_TRNS)
        {
            readlen = (i_length - i) < MAX_LENGTH_TRNS ?
                      (i_length - i) : MAX_LENGTH_TRNS;

            if (readlen == 0)
            {
                break;
            }

            rc = spi_read_internal( i_handle, i_address,
                                    readlen, o_buffer, i_eccStatus );

            if (rc != fapi2::FAPI2_RC_SUCCESS)
            {
                break;
            }

            i_address += readlen;
            o_buffer = (uint8_t*)(reinterpret_cast<uint64_t>(o_buffer) + readlen);
        }

    }
    while(0);

    // Restore ECC setting, if necessary
    if ((i_eccStatus == RAW_BYTE_ACCESS) && (l_ecc))
    {
        spi_set_ecc_on(i_handle);
    }

    return rc;
}

fapi2::ReturnCode
spi_write_prep_seq(SpiControlHandle& i_handle, uint64_t address, uint32_t length, uint64_t SEQ)
{
    uint32_t rc = fapi2::FAPI2_RC_SUCCESS;
    uint64_t TDR = 0;
    uint64_t CNT = ((uint64_t)(length / 8 - (length % 8 > 0 ? 0 : 1)) << 32);

    rc = spi_set_write_enable(i_handle);

    if (rc)
    {
        FAPI_ERR("Error from spi_set_write_enable");
        fapi2::current_err = rc;
        goto fapi_try_exit;
    }

    TDR = SPI_SLAVE_WR_CMD |
          (((uint64_t)address << 32) & 0x00ffffffffffffffULL);

    // Place sequence and send write command
    FAPI_TRY(putScom(i_handle.target_chip, i_handle.base_addr + SPIM_SEQREG, SEQ));
    FAPI_TRY(putScom(i_handle.target_chip, i_handle.base_addr + SPIM_COUNTERREG, CNT));
    FAPI_TRY(putScom(i_handle.target_chip, i_handle.base_addr + SPIM_TDR, TDR));

    rc = spi_wait_for_tdr_empty(i_handle); //Wait for previous TDR to be sent

    if (rc)
    {
        FAPI_ERR("Multiplexing Error in spi_wait_for_tdr_empty");
        fapi2::current_err = rc;
        goto fapi_try_exit;
    }

fapi_try_exit:
    return rc;
}

fapi2::ReturnCode
spi_write_post_seq(SpiControlHandle& i_handle)
{
    uint32_t rc = fapi2::FAPI2_RC_SUCCESS;
    rc = spi_wait_for_tdr_empty(i_handle); //Wait for previous TDR to be sent

    if (rc)
    {
        FAPI_ERR("Multiplexing Error in spi_wait_for_tdr_empty");
        fapi2::current_err = rc;
        goto fapi_try_exit;
    }

    // Wait until machine is no longer executing
    rc = spi_wait_for_idle(i_handle);

    if (rc)
    {
        FAPI_ERR("Multiplexing Error in spi_wait_for_idle ");
        fapi2::current_err = rc;
        goto fapi_try_exit;
    }

    rc = spi_wait_for_write_complete(i_handle);

    if (rc)
    {
        FAPI_ERR("Error in spi_wait_for_write_complete ");
        fapi2::current_err = rc;
        goto fapi_try_exit;
    }

fapi_try_exit:
    return rc;
}

fapi2::ReturnCode
spi_write_data(SpiControlHandle& i_handle, uint32_t address, uint8_t* i_data, uint32_t i_length)
{
    uint32_t rc = fapi2::FAPI2_RC_SUCCESS;

    do
    {
        uint64_t SEQ = 0;

        if (i_length == 8)
        {
            SEQ = 0x1034381000000000ULL;
        }
        else
        {
            SEQ = 0x103438E210000000ULL;
        }

        SEQ |= ((uint64_t)((i_handle.slave)) << 56);
        fapi2::buffer<uint64_t> TDR = 0;
        uint64_t l_temp = 0;

        rc = spi_write_prep_seq(i_handle, address, i_length, SEQ);

        if (rc)
        {
            FAPI_ERR("Error while preparing for SPI write");
            goto fapi_try_exit;
        }

        for (uint32_t i = 0; i < i_length; i += 8)
        {
            l_temp = ((uint64_t*)i_data)[i / 8];

#ifndef _BIG_ENDIAN
            fapi2::endian_swap(l_temp);
#endif
            TDR = l_temp;

            FAPI_TRY(putScom(i_handle.target_chip, i_handle.base_addr + SPIM_TDR, TDR));
            spi_wait_for_tdr_empty(i_handle);
            l_temp = 0;
        }

        rc = spi_write_post_seq(i_handle);

        if (rc)
        {
            FAPI_ERR("Error while executing post write checking");
            goto fapi_try_exit;
        }
    }
    while(0);

fapi_try_exit:
    return rc;
}

fapi2::ReturnCode
spi_write(SpiControlHandle& i_handle, uint32_t i_address,
          uint32_t i_length,  uint8_t* i_buffer)
{
    uint32_t cur_address = i_address;
    uint32_t cur_buf_byte = 0;
    uint32_t remaining_len = i_length;
    uint32_t page_offset = 0;
    uint32_t write_len;
    fapi2::ReturnCode rc = fapi2::FAPI2_RC_SUCCESS;

    if ((i_address % 8 != 0) || (i_length % 8 != 0) || (i_length == 0))
    {
        FAPI_ERR("The write requested is not byte aligned, exiting");
        return fapi2::FAPI2_RC_INVALID_PARAMETER;
    }

    rc = spi_precheck(i_handle);

    if (rc != fapi2::FAPI2_RC_SUCCESS)
    {
        return rc;
    }

    do
    {
        // Write length is determined either by:
        // (1) number of bytes left to write ;
        // (2) place in the current page of SEEPROM
        // (3) SEEPROM_PAGE_SIZE
        // The smallest of these three is written
        write_len = (remaining_len > SEEPROM_PAGE_SIZE) ? SEEPROM_PAGE_SIZE : remaining_len;
        page_offset = (cur_address & (SEEPROM_PAGE_SIZE - 1));
        write_len = ((SEEPROM_PAGE_SIZE - page_offset) < remaining_len) ? (SEEPROM_PAGE_SIZE - page_offset) : write_len;

        rc = spi_write_data(i_handle, cur_address, &i_buffer[cur_buf_byte], write_len);

        if (rc)
        {
            FAPI_ERR("Error writing data via SPI");
            fapi2::current_err = rc;
            goto fapi_try_exit;
        }

        cur_address += write_len;
        remaining_len -=  write_len;
        cur_buf_byte += write_len;
    }
    while(remaining_len > 0);

    rc = spi_wait_for_idle(i_handle);

    if (rc)
    {
        FAPI_ERR("Multiplexing Error in spi_wait_for_idle ");
        fapi2::current_err = rc;
        goto fapi_try_exit;
    }

    /*Restore the default counter and sdeq used by the side band path*/
    FAPI_TRY(putScom(i_handle.target_chip, i_handle.base_addr + SPIM_COUNTERREG, 0x0ULL));
    FAPI_TRY(putScom( i_handle.target_chip,
                      i_handle.base_addr + SPIM_SEQREG, SPI_DEFAULT_SEQ) );

fapi_try_exit:
    return fapi2::current_err;
}

fapi2::ReturnCode spi_master_reset(SpiControlHandle i_handle)
{
    fapi2::buffer<uint64_t> buffer = 0;

    // The pervasive spec says that to reset the SPI master and its internal sequencer we must
    // write 0x5 followed by 0xA to the clock configuration register in the 24-27 bit field. The
    // SPI master will then be reset unconditionally and any pending or running operation is
    // discontinued.
    //
    // However, the configuration register values are not changed, the status register is not reset,
    // and the SPI data registers are not reset. The reset also doesn't have any affect on attached
    // slaves.

    // Get the contents of the clock config register
    FAPI_TRY(getScom(i_handle.target_chip, i_handle.base_addr + SPIM_CLOCKCONFIGREG, buffer));
    FAPI_DBG("Clock Configuration Buffer Contents - Initial Read: 0x%.16X", buffer());

    // Write 0x5 to reset control bit field
    buffer.clearBit<24>().setBit<25>().clearBit<26>().setBit<27>();

    // Write the first portion of the reset sequence to the register.
    FAPI_TRY(putScom(i_handle.target_chip, i_handle.base_addr + SPIM_CLOCKCONFIGREG, buffer));

    // Read back the contents of the register.
    FAPI_TRY(getScom(i_handle.target_chip, i_handle.base_addr + SPIM_CLOCKCONFIGREG, buffer));
    FAPI_DBG("Clock Configuration Buffer Contents - 0x5 written: 0x%.16X", buffer());

    // Write 0xA to reset control bit field
    buffer.setBit<24>().clearBit<25>().setBit<26>().clearBit<27>();

    // Finish the reset request sequence by writing the final portion of the reset sequence.
    FAPI_TRY(putScom(i_handle.target_chip, i_handle.base_addr + SPIM_CLOCKCONFIGREG, buffer));

fapi_try_exit:
    FAPI_INF("spi_master_reset: exiting...");
    return fapi2::current_err;
}
