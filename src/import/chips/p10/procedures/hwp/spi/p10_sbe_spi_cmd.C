/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/spi/p10_sbe_spi_cmd.C $   */
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

#define SPI_SLAVE_WR_CMD  0x0200000000000000
#define SPI_SLAVE_RD_CMD  0x0300000000000000
#define SPI_SLAVE_RD_STAT 0x0500000000000000
#define SPI_SLAVE_WR_EN   0x0600000000000000

using namespace fapi2;

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

    while(1)
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

    }

fapi_try_exit:
    return fapi2::current_err;
}

//waits for receive-data-register full
static fapi2::ReturnCode
spi_wait_for_rdr_full(SpiControlHandle& i_handle)
{
    fapi2::buffer<uint64_t> status_reg = 0;

    while(1)
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
    }

fapi_try_exit:
    return fapi2::current_err;
}

//waits for the fsm of the spi-master to be idle
static fapi2::ReturnCode
spi_wait_for_idle(SpiControlHandle& i_handle)
{
    fapi2::buffer<uint64_t> data64 = 0;

    while(1)
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
    }

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
