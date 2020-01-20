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

using namespace fapi2;

fapi2::ReturnCode
spi_master_lock(SpiControlHandle& i_handle, uint64_t i_pib_master_id)
{
    uint32_t base_addr = (i_pib_master_id << 20) + i_handle.base_addr;
    fapi2::buffer<uint64_t> data64 =
        0x0800000000000000ULL + (i_pib_master_id << 60);

    FAPI_TRY(putScom( i_handle.target_chip,
                      base_addr + SPIM_CONFIGREG1, data64));

fapi_try_exit:
    return fapi2::current_err;
}

fapi2::ReturnCode
spi_master_unlock(SpiControlHandle& i_handle, uint64_t i_pib_master_id)
{
    uint32_t base_addr = (i_pib_master_id << 20) + i_handle.base_addr;
    fapi2::buffer<uint64_t> data64 = (i_pib_master_id << 60) + 0x00000000;

    FAPI_TRY(putScom( i_handle.target_chip,
                      base_addr + SPIM_CONFIGREG1, data64) );

fapi_try_exit:
    return fapi2::current_err;
}


//waits for transmit-data-register empty
static fapi2::ReturnCode
spi_wait_for_tdr_empty(SpiControlHandle& i_handle)
{
    uint32_t base_addr = i_handle.base_addr;
    fapi2::buffer<uint64_t> data64 = 0;

    while(1)
    {
        FAPI_TRY(getScom( i_handle.target_chip,
                          base_addr + SPIM_STATUSREG, data64));

        //checking for multiplexing error
        FAPI_ASSERT( (data64.getBit<50>() == 0),
                     fapi2::SBE_SPI_INVALID_PORT_MULTIPLEX_SET()
                     .set_CHIP_TARGET(i_handle.target_chip)
                     .set_BASE_ADDRESS(base_addr + SPIM_STATUSREG)
                     .set_STATUS_REGISTER(data64),
                     "Port multiplexer setting error set in spi_wait_for_tdr_empty");

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
    uint32_t base_addr = i_handle.base_addr;
    fapi2::buffer<uint64_t> status_reg = 0;

    while(1)
    {
        FAPI_TRY(getScom( i_handle.target_chip,
                          base_addr + SPIM_STATUSREG, status_reg));

        //checking for multiplexing error
        FAPI_ASSERT( (status_reg.getBit<50>() == 0),
                     fapi2::SBE_SPI_INVALID_PORT_MULTIPLEX_SET()
                     .set_CHIP_TARGET(i_handle.target_chip)
                     .set_BASE_ADDRESS(base_addr + SPIM_STATUSREG)
                     .set_STATUS_REGISTER(status_reg),
                     "Port multiplexer setting error set in spi_wait_for_rdr_full");

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
    uint32_t base_addr = i_handle.base_addr;
    fapi2::buffer<uint64_t> data64 = 0;

    while(1)
    {
        FAPI_TRY(getScom( i_handle.target_chip,
                          base_addr + SPIM_STATUSREG, data64));

        //checking for multiplexing error
        FAPI_ASSERT( (data64.getBit<50>() == 0),
                     fapi2::SBE_SPI_INVALID_PORT_MULTIPLEX_SET()
                     .set_CHIP_TARGET(i_handle.target_chip)
                     .set_BASE_ADDRESS(base_addr + SPIM_STATUSREG)
                     .set_STATUS_REGISTER(data64),
                     "Port multiplexer setting error set in spi_wait_for_idle");

        if(data64.getBit<15>())  //seq fsm Idle
        {
            break;
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

//waits for write complete flag of the spi-slave
static fapi2::ReturnCode
spi_wait_for_write_complete(SpiControlHandle& i_handle)
{
    uint32_t base_addr = i_handle.base_addr;
    fapi2::buffer<uint64_t> data64 = 0;
    fapi2::ReturnCode rc;

    //SEQ to send 1 byte command and read two byte response
    uint64_t SEQ = 0x1031421000000000ULL | ((uint64_t)i_handle.slave << 56);
    FAPI_TRY(putScom(i_handle.target_chip, base_addr + SPIM_SEQREG, SEQ));

    while(1)
    {
        //Send the read status register command(0x05)
        FAPI_TRY(putScom( i_handle.target_chip,
                          base_addr + SPIM_TDR, 0x0500000000000000ULL));
        rc = spi_wait_for_rdr_full(i_handle);  //Wait for response

        if (rc)
        {
            FAPI_ERR("Error in spi_wait_for_rdr_full ");
            fapi2::current_err = rc;
            goto fapi_try_exit;
        }

        FAPI_TRY(getScom(i_handle.target_chip, base_addr + SPIM_RDR, data64));

        if(!(data64.getBit<55>()))
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

fapi_try_exit:
    return fapi2::current_err;
}


//enables spi-slave write
static fapi2::ReturnCode
spi_set_write_enable(SpiControlHandle& i_handle)
{
    uint32_t base_addr = i_handle.base_addr;
    fapi2::buffer<uint64_t> data64 = 0;
    fapi2::ReturnCode rc = fapi2::FAPI2_RC_SUCCESS;
    uint64_t SEQ = 0x1031100000000000ULL | ((uint64_t)i_handle.slave << 56);
    uint64_t TDR = 0x0600000000000000ULL; //Write Enable command

    FAPI_TRY(putScom(i_handle.target_chip, base_addr + SPIM_SEQREG, SEQ));
    FAPI_TRY(putScom(i_handle.target_chip, base_addr + SPIM_TDR, TDR));

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

    //Seq to send 1byte command and receive 2 byte response
    SEQ = 0x1031421000000000ULL | ((uint64_t)i_handle.slave << 56);
    FAPI_TRY(putScom(i_handle.target_chip, base_addr + SPIM_SEQREG, SEQ));

    while(1)
    {
        //Send the read status register command
        FAPI_TRY(putScom( i_handle.target_chip,
                          base_addr + SPIM_TDR, 0x0500000000000000ULL));
        rc = spi_wait_for_rdr_full(i_handle);

        if (rc)
        {
            FAPI_ERR("Error in spi_wait_for_rdr_full");
            fapi2::current_err = rc;
            goto fapi_try_exit;
        }

        FAPI_TRY(getScom(i_handle.target_chip, base_addr + SPIM_RDR, data64));

        if(data64.getBit<54>())
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

fapi_try_exit:
    return fapi2::current_err;
}

//Check the h/w is in the expected state
static fapi2::ReturnCode
spi_precheck(SpiControlHandle& i_handle)
{
    uint32_t base_addr = i_handle.base_addr;
    fapi2::buffer<uint64_t> status_reg = 0;
    uint64_t temp, flags;

    FAPI_TRY(getScom(i_handle.target_chip,
                     base_addr + SPIM_STATUSREG, status_reg));
    status_reg.extract<0, 64>(temp);
    flags = SPI_RDR_FULL | SPI_RDR_OVERRUN |
            SPI_RDR_UNDERRUN | SPI_TDR_FULL |
            SPI_TDR_OVERRUN | SPI_TDR_UNDERRUN;

    // Check the h/w is in the expected state
    FAPI_ASSERT( !(temp & flags),
                 fapi2::SBE_SPI_CMD_STATUS_REG_UNSUPPORTED_STATE()
                 .set_CHIP_TARGET(i_handle.target_chip)
                 .set_BASE_ADDRESS(base_addr + SPIM_STATUSREG)
                 .set_STATUS_REGISTER(temp)
                 .set_CHECK_FLAGS(flags),
                 "SPI status register state bits check validation failed.");
fapi_try_exit:
    return fapi2::current_err;
}

//Reads data. For this implementation of one time use to counter,
//we can read at max of MAX_LENGTH_TRNS.
//Length should be multiple of 8
//if datawithecc = true, then driver will not discard ecc and it will be part of data.
//if datawithecc = false, then we expect app doesn't need ecc
/* Steps to read the seeprom.
 * 1. Send the READ command along with the address.
 * 2. SEEPROM will start sending the data from that offset
 *    continuously.
 * 3. Read the data. Use the loop mode if more than 8 byte reads
 * 4. Deselect the slave to stop it from sending any more data
 *
 */


static fapi2::ReturnCode
spi_read_internal(SpiControlHandle& i_handle, uint32_t i_address, uint32_t i_length,
                  uint8_t* o_buffer, SPI_ECC_CONTROL_STATUS i_eccStatus)
{
    uint32_t base_addr = i_handle.base_addr;
    fapi2::buffer<uint64_t> data64;
    uint64_t temp;
    uint64_t SEQ;
    fapi2::ReturnCode rc = fapi2::FAPI2_RC_SUCCESS;

    if ((i_length > MAX_LENGTH_TRNS) || (i_length % 8))
    {
        return fapi2::FAPI2_RC_INVALID_PARAMETER;
    }

    if( (i_eccStatus == STANDARD_ECC_ACCESS) ||
        (i_eccStatus == DISCARD_ECC_ACCESS) )
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

        /*
         * address = address*9/8 = address*8/8 + address/8
         *                       = address + address/8
         */
        i_address = i_address + (i_address >> 3);
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

    SEQ = SEQ | ((uint64_t)i_handle.slave << 56);

    //Check the state of the h/w
    rc = spi_precheck(i_handle);

    if (rc != fapi2::FAPI2_RC_SUCCESS)
    {
        return rc;
    }

    /*Read command (0x3)|| address in TDR to be sent to the slave*/
    uint64_t TDR = 0x0300000000000000ULL | ((uint64_t)i_address << 32);

    FAPI_TRY(putScom(i_handle.target_chip, base_addr + SPIM_SEQREG, SEQ));

    if (i_length > 8)
    {
        /*Generate the loop counter value*/
        uint64_t CNT = ((uint64_t)(((i_length + 7) / 8) - 1) << 32);
        //Use counter reload N2 to avoid RDR overflows
        CNT = CNT | ((uint64_t)(0xf) << 8);
        FAPI_TRY(putScom(i_handle.target_chip,
                         base_addr + SPIM_COUNTERREG, CNT));
    }

    FAPI_TRY(putScom(i_handle.target_chip, base_addr + SPIM_TDR, TDR));
    rc = spi_wait_for_tdr_empty(i_handle);

    if (rc)
    {
        FAPI_ERR("Error in spi_wait_for_tdr_empty ");
        fapi2::current_err = rc;
        goto fapi_try_exit;
    }

#ifdef __PPE__

    //one time zeros to trigger read. reload mode start with write to TDR
    if(!SBE::isSimicsRunning())
    {
        //simics doesn't support this mode.
        FAPI_TRY(putScom(i_handle.target_chip, base_addr + SPIM_TDR, 0x0ULL));
    }

#endif

    for (uint32_t i = 0; i < i_length; i += 8)
    {
        rc = spi_wait_for_rdr_full(i_handle);

        if (rc)
        {
            FAPI_ERR("Error in spi_wait_for_rdr_full");
            fapi2::current_err = rc;
            goto fapi_try_exit;
        }

        FAPI_TRY(getScom(i_handle.target_chip, base_addr + SPIM_RDR, data64));
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

    /*Restore the default sdeq used by the side band path*/
    FAPI_TRY(putScom(i_handle.target_chip,
                     base_addr + SPIM_SEQREG, SPI_DEFAULT_SEQ));

fapi_try_exit:
    return fapi2::current_err;
}

fapi2::ReturnCode
spi_read( SpiControlHandle& i_handle, uint32_t i_address, uint32_t i_length,
          SPI_ECC_CONTROL_STATUS i_eccStatus, uint8_t* o_buffer )
{
    fapi2::ReturnCode rc  = fapi2::FAPI2_RC_SUCCESS;
    uint32_t readlen = 0, i;

    if (i_length <= MAX_LENGTH_TRNS)
    {
        return spi_read_internal( i_handle, i_address,
                                  i_length, o_buffer, i_eccStatus );
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
            return rc;
        }

        i_address += readlen;
        o_buffer = (uint8_t*)(reinterpret_cast<uint64_t>(o_buffer) + readlen);
    }

    return rc;
}

fapi2::ReturnCode
spi_write(SpiControlHandle& i_handle, uint32_t i_address,
          uint32_t i_length,  uint8_t* i_buffer)
{
    uint32_t base_addr = i_handle.base_addr;
    uint64_t SEQ;
    uint32_t cur_address, cur_offset_buf, remaining_len;
    fapi2::ReturnCode rc = fapi2::FAPI2_RC_SUCCESS;

    if ((i_address % 8 != 0) || (i_length % 8 != 0) || (i_length == 0))
    {
        return fapi2::FAPI2_RC_INVALID_PARAMETER;
    }

    //Check the state of the h/w
    rc = spi_precheck(i_handle);

    if (rc != fapi2::FAPI2_RC_SUCCESS)
    {
        return rc;
    }

    cur_address = i_address;
    cur_offset_buf = 0;
    remaining_len = i_length;

    do
    {
        uint64_t TDR = 0x0200000000000000ULL |
                       (((uint64_t)cur_address << 32) & 0x00ffffffffffffffULL);
        uint32_t page_offset, write_len;
        /* Write command can write only within a page, where page
         * is 256bytes long. So the max write len will be only
         * till the end of the page.
         */
        page_offset = cur_address & (SEEPROM_PAGE_SIZE - 1);

        //How much can we write in this loop?
        write_len = ((SEEPROM_PAGE_SIZE - page_offset) < remaining_len)
                    ? (SEEPROM_PAGE_SIZE - page_offset) : remaining_len;

        if (write_len == 8)
        {
            SEQ = 0x1034381000000000ULL;
        }
        else
        {
            SEQ = 0x103438E210000000ULL;
        }

        SEQ = SEQ | ((uint64_t)(i_handle.slave & 0xF ) << 56);

        rc = spi_set_write_enable(i_handle);

        if (rc)
        {
            FAPI_ERR("Error from spi_set_write_enable");
            fapi2::current_err = rc;
            goto fapi_try_exit;
        }

        //If the write len is more than 8, we will need the loop count.
        //Branch back is done if count is none zero and internally
        //the hw decrements the counter.
        //eg: for 16bytes, we need to branch back once. len/8 -1
        if (write_len > 8)
        {
            uint64_t CNT;
            uint64_t loopcount;
            loopcount = (write_len >> 3) - 1;
            CNT = loopcount << 32;
            FAPI_TRY(putScom( i_handle.target_chip,
                              base_addr + SPIM_COUNTERREG, CNT) );
        }

        FAPI_TRY(putScom(i_handle.target_chip, base_addr + SPIM_SEQREG, SEQ));
        FAPI_TRY(putScom(i_handle.target_chip, base_addr + SPIM_TDR, TDR));

        for(uint32_t i = 0; i < write_len; i += 8)
        {
            uint64_t temp = ((uint64_t*)i_buffer)[cur_offset_buf / 8];
#ifndef _BIG_ENDIAN
            fapi2::endian_swap(temp);
#endif
            cur_offset_buf += 8;
            cur_address += 8;
            rc = spi_wait_for_tdr_empty(i_handle); //Wait for previous TDR to be sent

            if (rc)
            {
                FAPI_ERR("Multiplexing Error in spi_wait_for_tdr_empty");
                fapi2::current_err = rc;
                goto fapi_try_exit;
            }

            FAPI_TRY(putScom(i_handle.target_chip, base_addr + SPIM_TDR, temp));
        }

        //Wait for the last data to be completely sent
        rc = spi_wait_for_tdr_empty(i_handle);

        if (rc)
        {
            FAPI_ERR("Multiplexing Error in spi_wait_for_tdr_empty");
            fapi2::current_err = rc;
            goto fapi_try_exit;
        }

        remaining_len = remaining_len - write_len;
        rc = spi_wait_for_idle(i_handle);

        if (rc)
        {
            FAPI_ERR("Multiplexing Error in spi_wait_for_idle ");
            fapi2::current_err = rc;
            goto fapi_try_exit;
        }

        //We need to ensure that the seeprom has written the write buffer content to
        //storage before starting again
        rc = spi_wait_for_write_complete(i_handle);

        if (rc)
        {
            FAPI_ERR("Error in spi_wait_for_write_complete ");
            fapi2::current_err = rc;
            goto fapi_try_exit;
        }
    }
    while(remaining_len > 0);

    rc = spi_wait_for_idle(i_handle);

    if (rc)
    {
        FAPI_ERR("Multiplexing Error in spi_wait_for_idle ");
        fapi2::current_err = rc;
        goto fapi_try_exit;
    }

    /*Restore the default sdeq used by the side band path*/
    FAPI_TRY(putScom( i_handle.target_chip,
                      base_addr + SPIM_SEQREG, SPI_DEFAULT_SEQ) );

fapi_try_exit:
    return fapi2::current_err;
}
