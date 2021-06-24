/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/sfc_ibm.C $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2021                        */
/* [+] Google Inc.                                                        */
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
/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <sys/mmio.h>
#include <sys/task.h>
#include <sys/sync.h>
#include <string.h>
#include <devicefw/driverif.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludlogregister.H>
#include <targeting/common/targetservice.H>
#include <pnor/pnor_reasoncodes.H>
#include <sys/time.h>
#include <util/align.H>
#include <lpc/lpcif.H>
#include "sfc_ibm.H"
#include "norflash.H"
using namespace PNOR;

/*****************************************************************************/
// C o n s t a n t s
/*****************************************************************************/



/*****************************************************************************/
// G l o b a l s
/*****************************************************************************/

// Initialized in pnorrp.C
extern trace_desc_t* g_trac_pnor;

/*****************************************************************************/
// M e t h o d s
/*****************************************************************************/

namespace PNOR {
/**
 * @brief Wrapper for device driver constructor
 */
errlHndl_t create_SfcDD( SfcDD*& o_sfc,
                         TARGETING::Target* i_proc )
{
    errlHndl_t l_err = NULL;
    TRACFCOMP( g_trac_pnor, "Creating SfcIBM object" );
    o_sfc = new SfcIBM( l_err, i_proc );
    return l_err;
}

};

/**
 * @brief Constructor
 */
SfcIBM::SfcIBM( errlHndl_t& o_err,
                TARGETING::Target* i_proc )
: SfcDD(o_err,i_proc)
,iv_ffdcActive(false)
,iv_errorHandledCount(0)
,iv_resetActive(false)
{
}


/**
 * @brief Write a SFC Register
 */
errlHndl_t SfcIBM::writeReg( SfcRange i_range,
                             uint32_t i_addr,
                             uint32_t i_data )
{
    errlHndl_t l_err = NULL;
    uint32_t lpc_addr = i_addr;
    LPC::TransType lpc_range = LPC::TRANS_LAST;

    // Find the appropriate LPC parms
    sfc2lpc( i_range, i_addr, lpc_range, lpc_addr );

    TRACDCOMP( g_trac_pnor, "SfcIBM::writeReg> SFC::%d-%.8X, LPC::%d-%.8X, i_data=0x%.8x", i_range, i_addr, lpc_range, lpc_addr, i_data );
    size_t reg_size = sizeof(uint32_t);
    l_err = deviceOp( DeviceFW::WRITE,
                      iv_proc,
                      &i_data,
                      reg_size,
                      DEVICE_LPC_ADDRESS(lpc_range,lpc_addr) );

    return l_err;
}


/**
 * @brief Read a SFC Register
 */
errlHndl_t SfcIBM::readReg( SfcRange i_range,
                            uint32_t i_addr,
                            uint32_t& o_data )
{
    errlHndl_t l_err = NULL;
    uint32_t lpc_addr = i_addr;
    LPC::TransType lpc_range = LPC::TRANS_LAST;

    // Find the appropriate LPC parms
    sfc2lpc( i_range, i_addr, lpc_range, lpc_addr );

    size_t reg_size = sizeof(uint32_t);
    l_err = deviceOp( DeviceFW::READ,
                      iv_proc,
                      &o_data,
                      reg_size,
                      DEVICE_LPC_ADDRESS(lpc_range,lpc_addr) );
    TRACDCOMP( g_trac_pnor, "SfcIBM::readReg> SFC::%d-%.8X, LPC::%d-%.8X, o_data=0x%.8x", i_range, i_addr, lpc_range, lpc_addr, o_data );

    return l_err;
}


/**
 * @brief Poll for SFC operation to complete and look for errors
 */
errlHndl_t SfcIBM::pollOpComplete( void )
{
    TRACDCOMP( g_trac_pnor, "SfcIBM::pollOpComplete>" );
    errlHndl_t l_err = NULL;
    ResetLevels l_resetLevel = RESET_CLEAR;

    do {
        //Poll for complete status
        SfcStatReg_t sfc_stat;
        uint64_t poll_time = 0;
        uint64_t loop = 0;
        while( poll_time < SFC_POLL_TIME_NS )
        {
            l_err = readReg(SFC_CMD_SPACE,
                            SFC_REG_STATUS,
                            sfc_stat.data32);
            if(l_err) { break; }

            if( ( sfc_stat.done == 1 ) ||
                ( sfc_stat.timeout == 1 ) ||
                ( sfc_stat.illegal == 1 ) )
            {
                break;
            }

            // want to start out incrementing by small numbers then get bigger
            //  to avoid a really tight loop in an error case so we'll increase
            //  the wait each time through
            ++loop;
            nanosleep( 0, SFC_POLL_INCR_NS*loop );
            poll_time += SFC_POLL_INCR_NS*loop;
        }
        if( l_err ) { break; }

        // Look for errors, regardless of how we exited the loop
        l_err = checkForErrors(l_resetLevel);
        if( l_err ) { break; }

        // If no errors AND done bit not set, call out undefined error
        if( sfc_stat.done == 0 )
        {
            TRACFCOMP(g_trac_pnor, "SfcIBM::pollOpComplete> Error or timeout from SFC Status Register" );

            /*@
             * @errortype
             * @moduleid     PNOR::MOD_SFCIBM_POLLOPCOMPLETE
             * @reasoncode   PNOR::RC_SFC_TIMEOUT
             * @userdata1[0:31]   NOR Flash Chip ID
             * @userdata1[32:63]  Total poll time (ns)
             * @userdata2[0:31]    SFC Status Register
             * @devdesc      SfcIBM::pollOpComplete> Error or timeout from
             *               SFC Status Register
             * @custdesc     Hardware error accessing flash during IPL
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    PNOR::MOD_SFCIBM_POLLOPCOMPLETE,
                                    PNOR::RC_SFC_TIMEOUT,
                                    TWO_UINT32_TO_UINT64(iv_norChipId,
                                                         poll_time),
                                    TWO_UINT32_TO_UINT64(sfc_stat.data32,0));

            // Limited in callout: no PNOR target, so calling out processor
            l_err->addHwCallout(
                           TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                           HWAS::SRCI_PRIORITY_HIGH,
                           HWAS::NO_DECONFIG,
                           HWAS::GARD_NULL );

            addFFDC(l_err);
            l_err->collectTrace(PNOR_COMP_NAME);
            l_err->collectTrace(XSCOM_COMP_NAME);

            // Reset LPC Slave since it appears to be hung - handled below
            l_resetLevel = RESET_LPC_SLAVE;

            break;
        }
        TRACDCOMP(g_trac_pnor,"SfcIBM::pollOpComplete> command took %d ns", poll_time);

    }while(0);

    // If we have an error that requires a reset, do that here
    if ( l_err && ( l_resetLevel != RESET_CLEAR ) )
    {
        errlHndl_t tmp_err = NULL;
        tmp_err = hwReset(l_resetLevel);

        if ( tmp_err )
        {
            // Commit reset error as informational since we have
            // original error l_err
            TRACFCOMP(g_trac_pnor, "SfcIBM::pollOpComplete> Error from resetPnor() after previous error eid=0x%X. Committing resetPnor() error log eid=0x%X.",
            l_err->eid(), tmp_err->eid());
            tmp_err->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
            tmp_err->collectTrace(PNOR_COMP_NAME);
            tmp_err->plid(l_err->plid());
            errlCommit(tmp_err, PNOR_COMP_ID);
        }
    }


    return l_err;
}


/**
 * @brief Load SFC command buffer with data from PNOR
 */
errlHndl_t SfcIBM::loadSfcBuf(uint32_t i_addr,
                              size_t i_size)
{
    errlHndl_t l_err = NULL;
    TRACDCOMP( g_trac_pnor, "SfcIBM::loadSfcBuf> i_addr=0x%.8x, i_size=0x%.8x",
               i_addr, i_size );

    do {
        //Write flash address to ADR reg
        l_err = writeReg(SFC_CMD_SPACE,
                         SFC_REG_ADR,
                         i_addr);
        if(l_err) { break; }

        //Issue ReadRaw command with size to read
        SfcCmdReg_t sfc_cmd;
        sfc_cmd.opcode = SFC_OP_READRAW;
        sfc_cmd.length = i_size;
        l_err = writeReg(SFC_CMD_SPACE,
                         SFC_REG_CMD,
                         sfc_cmd.data32);
        if(l_err) { break; }

        //Poll for complete status
        l_err = pollOpComplete();
        if(l_err) { break; }

    }while(0);

    return l_err;

}


/**
 * @brief Flush SFC command buffer data out to PNOR Flash
 */
errlHndl_t SfcIBM::flushSfcBuf( uint32_t i_addr,
                                size_t i_size )
{
    errlHndl_t l_err = NULL;
    TRACDCOMP( g_trac_pnor,
               "SfcIBM::flushSfcBuf> i_addr=0x%.8x, i_size=0x%.8x",
               i_addr, i_size );

    do {
        //Write flash address to ADR reg
        l_err = writeReg(SFC_CMD_SPACE,
                         SFC_REG_ADR,
                         i_addr);
        if(l_err) { break; }

        //Issue WriteRaw command + size to write
        SfcCmdReg_t sfc_cmd;
        sfc_cmd.opcode = SFC_OP_WRITERAW;
        sfc_cmd.length = i_size;
        l_err = writeReg(SFC_CMD_SPACE,
                         SFC_REG_CMD,
                         sfc_cmd.data32);
        if(l_err) { break; }

        //Poll for complete status
        l_err = pollOpComplete();
        if(l_err) { break; }

#ifdef CONFIG_ALLOW_MICRON_PNOR
        //check for special Micron Flag Status reg
        if(iv_flashWorkarounds & HWWK_MICRON_WRT_ERASE)
        {
            l_err = PNOR::micronFlagStatus(this);
            if(l_err) { break; }
        }
#endif

    }while(0);

    return l_err;

}


/**
 * @brief Read data from the flash
 */
errlHndl_t SfcIBM::readFlash( uint32_t i_addr,
                              size_t i_size,
                              void* o_data )
{
    errlHndl_t l_err = NULL;
    TRACDCOMP( g_trac_pnor, "SfcIBM::readFlash> i_addr=0x%.8x, i_size=0x%.8x",
               i_addr, i_size );

    do{
        //Read directly from MMIO space
        uint32_t* word_ptr = static_cast<uint32_t*>(o_data);
        uint32_t word_size = (ALIGN_4(i_size))/4;
        for( uint32_t words_read = 0;
             words_read < word_size;
             words_read ++ )
        {
            l_err = readReg(SFC_MMIO_SPACE,
                            i_addr+words_read*4, //MMIO Address offset
                            word_ptr[words_read]);
            if( l_err ) {  break; }
        }
        if( l_err ) {  break; }
    }while(0);

    return l_err;
}


/**
 * @brief Write data into flash
 */
errlHndl_t SfcIBM::writeFlash( uint32_t i_addr,
                               size_t i_size,
                               void* i_data )
{
    TRACDCOMP( g_trac_pnor, "SfcIBM::writeFlash> i_addr=0x%.8x, i_size=0x%.8x",
               i_addr, i_size );

    errlHndl_t l_err = NULL;

    do{
        // Command based reads are buffered 256 bytes at a time.
        uint32_t chunk_size = 0;
        uint64_t addr = i_addr;
        uint64_t end_addr = i_addr + i_size;

        while(addr < end_addr)
        {
            // Flash devices "wrap" writes at 256 byte page boundaries.
            // Adjust the write length so we don't write across a page
            // when starting from an unaligned offset.
            chunk_size = SFC_CMDBUF_SIZE - (addr & 0xff);
            if( (addr + chunk_size) > end_addr)
            {
                chunk_size = end_addr - addr;
            }

            //write data to SFC CMD Buffer via MMIO
            l_err = writeIntoBuffer(chunk_size,
                                    (void*)((uint64_t)i_data + (addr-i_addr)));
            if(l_err) { break;}

            //Push data from buffer out to flash
            l_err = flushSfcBuf(addr, chunk_size);
            if(l_err) { break;}

            addr += chunk_size;
        }
        if(l_err) { break;}

    } while(0);

    return l_err;
}


/**
 * @brief Read data from SFC Command buffer
 */
errlHndl_t SfcIBM::readFromBuffer( size_t i_size,
                                   void* o_data )
{
    errlHndl_t l_err = NULL;
    TRACDCOMP( g_trac_pnor, "SfcIBM::readFromBuffer> i_size=0x%.8x",
               i_size );

    // SFC Command Buffer is accessed 32-bits at a time
    uint32_t* word_ptr = static_cast<uint32_t*>(o_data);
    uint32_t word_size = (ALIGN_4(i_size))/4;
    for( uint32_t words_read = 0;
         words_read < word_size;
         words_read ++ )
    {
        l_err = readReg(SFC_CMDBUF_SPACE,
                        words_read*4, //Offset into CMD BUFF space in bytes
                        word_ptr[words_read]);
        TRACDCOMP( g_trac_pnor, "SfcIBM::readFromBuffer: Read offset=0x%.8x, data_read=0x%.8x",  words_read*4, word_ptr[words_read] );

        if( l_err ) {  break; }
    }

    return l_err;
}

/**
 * @brief Write data into SFC Command buffer
 */
errlHndl_t SfcIBM::writeIntoBuffer( size_t i_size,
                                    void* i_data )
{
    errlHndl_t l_err = NULL;
    TRACDCOMP( g_trac_pnor, "SfcIBM::writeIntoBuffer> i_size=0x%.8x",
               i_size );

    // SFC Command Buffer is accessed 32-bits at a time
    uint32_t* word_ptr = static_cast<uint32_t*>(i_data);
    uint32_t word_size = i_size/4;
    for( uint32_t words_read = 0;
         words_read < word_size;
         words_read ++ )
    {
        l_err = writeReg(SFC_CMDBUF_SPACE,
                         words_read*4, //Offset into CMD BUFF space in bytes
                         word_ptr[words_read]);
        if( l_err ) { break; }
    }

    return l_err;
}

/**
 * @brief Erase a block of flash
 */
errlHndl_t SfcIBM::eraseFlash(uint32_t i_address)
{
    errlHndl_t l_err = NULL;
    TRACFCOMP(g_trac_pnor, ">>SfcIBM::eraseFlash> Block 0x%.8X", i_address );

    do {
        if( i_address%iv_eraseSizeBytes != 0 )
        {
            /*@
             * @errortype
             * @moduleid     PNOR::MOD_SFCIBM_ERASEFLASH
             * @reasoncode   PNOR::RC_INVALID_ADDRESS
             * @userdata1    Flash address being erased
             * @userdata2    Nearest Erase Boundary
             * @devdesc      PnorDD::eraseFlash> Address not on erase boundary
             * @custdesc     Firmware error accessing flash during IPL
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            PNOR::MOD_SFCIBM_ERASEFLASH,
                                            PNOR::RC_INVALID_ADDRESS,
                                            TWO_UINT32_TO_UINT64(0,i_address),
                                            i_address
                                            - i_address%iv_eraseSizeBytes,
                                            true /*Add HB SW Callout*/ );
            l_err->collectTrace(PNOR_COMP_NAME);
            break;
        }

        //Write erase address to ADR reg
        l_err = writeReg(SFC_CMD_SPACE,
                         SFC_REG_ADR,
                         i_address);
        if(l_err) { break; }

        //Issue Erase command
        SfcCmdReg_t sfc_cmd;
        sfc_cmd.opcode = SFC_OP_ERASM;
        sfc_cmd.length = 0;  //Not used for erase
        l_err = writeReg(SFC_CMD_SPACE,
                         SFC_REG_CMD,
                         sfc_cmd.data32);
        if(l_err) { break; }

        //Poll for complete status
        l_err = pollOpComplete();
        if(l_err) { break; }

#ifdef CONFIG_ALLOW_MICRON_PNOR
        //check for special Micron Flag Status reg
        if(iv_flashWorkarounds & HWWK_MICRON_WRT_ERASE)
        {
            l_err = PNOR::micronFlagStatus(this);
            if(l_err) { break; }
        }
#endif
    } while(0);

    return l_err;
}


/**
 * @brief Initialize and configure the SFC hardware
 */
errlHndl_t SfcIBM::hwInit( )
{
    TRACFCOMP(g_trac_pnor, "SfcIBM::hwInit>" );
    errlHndl_t l_err = NULL;

    do {
        //Determine NOR Flash type - triggers vendor specific workarounds
        //We also use the chipID in some FFDC situations.
        l_err = getNORChipId(iv_norChipId);
        if(l_err) { break; }
        TRACFCOMP(g_trac_pnor,
                  "SfcIBM::hwInit: iv_norChipId=0x%.8x> ",
                  iv_norChipId );

#ifndef CONFIG_BMC_DOES_SFC_INIT
        TRACFCOMP( g_trac_pnor, INFO_MRK "Initializing SFC registers" );

        static struct
        {
            // Chip id to match or UNKNOWN_NOR_ID for all chips.
            uint32_t chip_id;
            // SFC register to set.
            uint8_t reg;
            // Value which is set in register.
            uint32_t val;
        } sfc_init_regs[] = {
            //*** Direct access window and basic SFC settings.
            //Set MMIO/Direct window to start at 64MB
            { PNOR::UNKNOWN_NOR_ID, SFC_REG_OADRNB, 0x0C000000 },
            //Set the MMIO/Direct window size to 64MB
            { PNOR::UNKNOWN_NOR_ID, SFC_REG_OADRNS, 0x0000000F },
            //Set the flash index to 0
            { PNOR::UNKNOWN_NOR_ID, SFC_REG_ADRCBF, 0x00000000 },
            //Set the flash size to 64MB
            { PNOR::UNKNOWN_NOR_ID, SFC_REG_ADRCMF, 0x0000000F },
#ifdef CONFIG_RHESUS
            //Enable Direct Access Cache, disable large reload
            { PNOR::UNKNOWN_NOR_ID, SFC_REG_CONF, 0x00000000 },
#else
            //Enable Direct Access Cache
            { PNOR::UNKNOWN_NOR_ID, SFC_REG_CONF, 0x00000001 },
#endif

#ifdef CONFIG_ALLOW_MICRON_PNOR
            //*** Micron 512mb chip specific settings.
            { PNOR::MICRON_NOR_ID, SFC_REG_SPICLK,
            0 << SFC_REG_SPICLK_OUTDLY_SHFT |
            0 << SFC_REG_SPICLK_INSAMPDLY_SHFT |
            1 << SFC_REG_SPICLK_CLKHI_SHFT |
            1 << SFC_REG_SPICLK_CLKLO_SHFT
            },
            //TODO RTC:187447 figure out why these break newer systems
            //{ PNOR::MICRON_NOR_ID, SFC_REG_CONF8,
            //6 << SFC_REG_CONF8_CSINACTIVEREAD_SHFT |
            //15 << SFC_REG_CONF8_DUMMY_SHFT |
            //SPI_JEDEC_FAST_READ << SFC_REG_CONF8_READOP_SHFT
            //},
            { PNOR::MICRON_NOR_ID, SFC_REG_CONF4, SPI_JEDEC_SECTOR_ERASE },
            { PNOR::MICRON_NOR_ID, SFC_REG_CONF5, 4096 },
            //*** End Micron
#endif

#ifdef CONFIG_ALLOW_MACRONIX_PNOR
            //*** Macronix 512mb chip specific settings.
            { PNOR::MACRONIX64_NOR_ID, SFC_REG_SPICLK,
            0 << SFC_REG_SPICLK_OUTDLY_SHFT |
            0 << SFC_REG_SPICLK_INSAMPDLY_SHFT |
            0 << SFC_REG_SPICLK_CLKHI_SHFT |
            0 << SFC_REG_SPICLK_CLKLO_SHFT
            },
            { PNOR::MACRONIX64_NOR_ID, SFC_REG_CONF8,
            2 << SFC_REG_CONF8_CSINACTIVEREAD_SHFT |
            8 << SFC_REG_CONF8_DUMMY_SHFT |
            SPI_JEDEC_FAST_READ << SFC_REG_CONF8_READOP_SHFT
            },
            { PNOR::MACRONIX64_NOR_ID, SFC_REG_CONF4, SPI_JEDEC_SECTOR_ERASE },
            { PNOR::MACRONIX64_NOR_ID, SFC_REG_CONF5, 4096 },
            //*** End Macronix
#endif
        };

        for ( size_t i = 0;
              i < sizeof(sfc_init_regs) / sizeof(sfc_init_regs[0]);
              ++i )
        {
            if( (sfc_init_regs[i].chip_id == PNOR::UNKNOWN_NOR_ID) ||
                (sfc_init_regs[i].chip_id == iv_norChipId) )
            {
                TRACDCOMP( g_trac_pnor, INFO_MRK " SFC reg %02x = %08x",
                           sfc_init_regs[i].reg,
                           sfc_init_regs[i].val );
                l_err = writeReg( SFC_CMD_SPACE,
                                  sfc_init_regs[i].reg,
                                  sfc_init_regs[i].val );
                if( l_err ) { break; }
            }
        }
        if( l_err ) { break; }

#ifdef CONFIG_PNOR_INIT_FOUR_BYTE_ADDR
        // Enable 4 byte addressing.  This is safe even if 4BA is already
        // enabled by the BMC/FSP/etc.
        SfcCmdReg_t sfc_cmd;
        sfc_cmd.opcode = SFC_OP_START4BA;
        sfc_cmd.length = 0;
        l_err = writeReg(SFC_CMD_SPACE,
                         SFC_REG_CMD,
                         sfc_cmd.data32);
        if(l_err) { break; }

        //Poll for complete status
        l_err = pollOpComplete();
        if(l_err) { break; }
#endif

#endif //!CONFIG_BMC_DOES_SFC_INIT

        //Query the configured size of the erase block
        l_err = readReg(SFC_CMD_SPACE,
                        SFC_REG_ERASMS,
                        iv_eraseSizeBytes);
        if(l_err) { break; }
        TRACFCOMP(g_trac_pnor,"iv_eraseSizeBytes=0x%X",iv_eraseSizeBytes);

#ifdef CONFIG_ALLOW_MICRON_PNOR
        if( iv_norChipId == PNOR::MICRON_NOR_ID )
        {
            l_err = PNOR::micronCheckForWorkarounds( this,
                                                     iv_flashWorkarounds );
            if(l_err) { break; }
        }
#endif //CONFIG_ALLOW_MICRON_PNOR

    }while(0);

    TRACFCOMP(g_trac_pnor, "< SfcIBM::hwInit :: RC=%.4X", ERRL_GETRC_SAFE(l_err) );
    return l_err;
}

/**
 * @brief Convert a SFC address to a LPC address
 */
void SfcIBM::sfc2lpc( SfcRange i_sfcRange,
                      uint32_t i_sfcAddr,
                      LPC::TransType& o_lpcRange,
                      uint32_t& o_lpcAddr )
{
    switch(i_sfcRange)
    {
        case SFC_MMIO_SPACE:
            o_lpcRange = LPC::TRANS_FW;
            o_lpcAddr = i_sfcAddr | SFC_MMIO_OFFSET;
            break;
        case SFC_CMD_SPACE:
            o_lpcRange = LPC::TRANS_FW;
            o_lpcAddr = i_sfcAddr | SFC_CMDREG_OFFSET;
            break;
        case SFC_CMDBUF_SPACE:
            o_lpcRange = LPC::TRANS_FW;
            o_lpcAddr = i_sfcAddr | SFC_CMDBUF_OFFSET;
            break;
        case SFC_LPC_SPACE:
            o_lpcRange = LPC::TRANS_FW;
            o_lpcAddr = i_sfcAddr;
            break;
    } //end switch
}


/**
 * @brief Check For Errors in SFC Status Registers
 */
errlHndl_t SfcIBM::checkForErrors( ResetLevels &o_resetLevel )
{
    errlHndl_t l_err = NULL;
    bool errorFound = false;

    // Used to set Reset Levels, if necessary
    o_resetLevel = RESET_CLEAR;

    // Default status values in case we fail in reading the registers
    LpcSlaveStatReg_t lpc_slave_stat;
    lpc_slave_stat.data32 = 0xDEADBEEF;
    SfcStatReg_t sfc_stat;
    sfc_stat.data32 = 0xDEADBEEF;

    do {

        // First Read LPC Slave Status Register
        l_err = readReg( SFC_LPC_SPACE,
                         LPC_SLAVE_REG_STATUS,
                         lpc_slave_stat.data32 );

        // If we can't read status register, exit out
        if( l_err ) { break; }

        TRACDCOMP( g_trac_pnor, INFO_MRK"SfcIBM::checkForErrors> LPC Slave status reg: 0x%08llx",
                   lpc_slave_stat.data32);

        // Start with lighter reset level
        if( 1 == lpc_slave_stat.lbusparityerror )
        {
            errorFound = true;
            o_resetLevel = RESET_LPC_SLAVE_ERRS;
            TRACFCOMP( g_trac_pnor, ERR_MRK"SfcIBM::checkForErrors> LPC Slave Local Bus Parity Error: status reg: 0x%08llx, ResetLevel=%d",
                       lpc_slave_stat.data32, o_resetLevel);
        }

        // Check for more stronger reset level
        if( 0 != lpc_slave_stat.lbus2opberr )
        {
            errorFound = true;
            // All of these errors require the SFC Local Bus Reset
            o_resetLevel = RESET_SFC_LOCAL_BUS;

            if ( LBUS2OPB_ADDR_PARITY_ERR == lpc_slave_stat.lbus2opberr )
            {
                // This error also requires LPC Slave Errors to be Cleared
                o_resetLevel = RESET_SFCBUS_LPCSLAVE_ERRS;
                TRACFCOMP( g_trac_pnor, ERR_MRK"SfcIBM::checkForErrors> LBUS2OPB Address Parity Error: LPC Slave status reg: 0x%08llx, ResetLevel=%d",
                           lpc_slave_stat.data32, o_resetLevel);

            }

            else if ( LBUS2OPB_INVALID_SELECT_ERR == lpc_slave_stat.lbus2opberr)
            {
                TRACFCOMP( g_trac_pnor, ERR_MRK"SfcIBM::checkForErrors> LBUS2OPB Invalid Select Error: LPC Slave status reg: 0x%08llx, ResetLevel=%d",
                           lpc_slave_stat.data32, o_resetLevel);

            }
            else if ( LBUS2OPB_DATA_PARITY_ERR == lpc_slave_stat.lbus2opberr )
            {
                // This error also requires LPC Slave Errors to be Cleared
                o_resetLevel = RESET_SFCBUS_LPCSLAVE_ERRS;
                TRACFCOMP( g_trac_pnor, ERR_MRK"SfcIBM::checkForErrors> LBUS2OPB Data Parity Error: LPC Slave status reg: 0x%08llx, ResetLevel=%d",
                           lpc_slave_stat.data32, o_resetLevel);

            }
            else if ( LBUS2OPB_MONITOR_ERR == lpc_slave_stat.lbus2opberr )
            {
                TRACFCOMP( g_trac_pnor, ERR_MRK"SfcIBM::checkForErrors> LBUS2OPB Monitor Error: LPC Slave status reg: 0x%08llx, ResetLevel=%d",
                           lpc_slave_stat.data32, o_resetLevel);

            }

            else if ( LBUS2OPB_TIMEOUT_ERR == lpc_slave_stat.lbus2opberr )
            {
                TRACFCOMP( g_trac_pnor, ERR_MRK"SfcIBM::checkForErrors> LBUS2OPB Timeout Error: LPC Slave status reg: 0x%08llx, ResetLevel=%d",
                           lpc_slave_stat.data32, o_resetLevel);

            }
            else
            {
                // Just in case, clear LPC Slave Errors
                o_resetLevel = RESET_LPC_SLAVE_ERRS;
                TRACFCOMP( g_trac_pnor, ERR_MRK"SfcIBM::checkForErrors> LBUS2OPB UNKNOWN Error: LPC Slave status reg: 0x%08llx, ResetLevel=%d",
                           lpc_slave_stat.data32, o_resetLevel);
            }

        }

        // Second Read SFC and check for error bits
        l_err = readReg(SFC_CMD_SPACE,
                        SFC_REG_STATUS,
                        sfc_stat.data32);

        // If we can't read status register, exit out
        if( l_err ) { break; }

        TRACDCOMP( g_trac_pnor, INFO_MRK"SfcIBM::checkForErrors> SFC status reg(0x%X): 0x%08llx",
                   SFC_CMD_SPACE|SFC_REG_STATUS,sfc_stat.data32);

        // No resets needed for these errors
        if( 1 == sfc_stat.eccerrcntr )
        {
            errorFound = true;
            TRACFCOMP( g_trac_pnor, ERR_MRK"SfcIBM::checkForErrors> Threshold of SRAM ECC Errors Reached: SFC status reg: 0x%08llx, ResetLevel=%d",
                       sfc_stat.data32, o_resetLevel);
        }

        if( 1 == sfc_stat.eccues )
        {
            errorFound = true;
            TRACFCOMP( g_trac_pnor, ERR_MRK"SfcIBM::checkForErrors> SRAM Command Uncorrectable ECC Error: SFC status reg: 0x%08llx, ResetLevel=%d",
                       sfc_stat.data32, o_resetLevel);
        }

        if( 1 == sfc_stat.illegal )
        {
            errorFound = true;
            TRACFCOMP( g_trac_pnor, ERR_MRK"SfcIBM::checkForErrors> Previous Operation was Illegal: SFC status reg: 0x%08llx, ResetLevel=%d",
                       sfc_stat.data32, o_resetLevel);
        }

        if( 1 == sfc_stat.eccerrcntn )
        {
            errorFound = true;
            TRACFCOMP( g_trac_pnor, ERR_MRK"SfcIBM::checkForErrors> Threshold for Flash ECC Errors Reached: SFC status reg: 0x%08llx, ResetLevel=%d",

                       sfc_stat.data32, o_resetLevel);
        }

        if( 1 == sfc_stat.eccuen )
        {
            errorFound = true;
            TRACFCOMP( g_trac_pnor, ERR_MRK"SfcIBM::checkForErrors> Flash Command Uncorrectable ECC Error: SFC status reg: 0x%08llx, ResetLevel=%d",
                       sfc_stat.data32, o_resetLevel);
        }

        if( 1 == sfc_stat.timeout )
        {
            errorFound = true;
            TRACFCOMP( g_trac_pnor, ERR_MRK"SfcIBM::checkForErrors> Timeout: SFC status reg: 0x%08llx, ResetLevel=%d",
                       sfc_stat.data32, o_resetLevel);
        }

    }while(0);


    // If there is any error create an error log
    if ( errorFound )
    {
        // If we failed on a register read above, but still found an error,
        // delete register read error log and create an original error log
        // for the found error
        if ( l_err )
        {
            TRACFCOMP( g_trac_pnor, ERR_MRK"SfcIBM::checkForErrors> Deleting register read error. Returning error created for the found error");
            delete l_err;
            l_err = nullptr;
        }


        /*@
         * @errortype
         * @moduleid     PNOR::MOD_SFCIBM_CHECKFORERRORS
         * @reasoncode   PNOR::RC_ERROR_IN_STATUS_REG
         * @userdata1[0:31]  SFC Status Register
         * @userdata1[32:63] LPC Slave Status Register
         * @userdata2    Reset Level
         * @devdesc      SfcIBM::checkForErrors> Error(s) found in SFC
         *               and/or LPC Slave Status Registers
         * @custdesc    A problem occurred while accessing the boot flash.
         */
        l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        PNOR::MOD_SFCIBM_CHECKFORERRORS,
                                        PNOR::RC_ERROR_IN_STATUS_REG,
                                        TWO_UINT32_TO_UINT64(
                                                   sfc_stat.data32,
                                                   lpc_slave_stat.data32),
                                        o_resetLevel );

        // Limited in callout: no PNOR target, so calling out processor
        l_err->addHwCallout(
                        TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                        HWAS::SRCI_PRIORITY_HIGH,
                        HWAS::NO_DECONFIG,
                        HWAS::GARD_NULL );

        addFFDC(l_err);
        l_err->collectTrace(PNOR_COMP_NAME);
    }

    return l_err;

}

/**
 * @brief Add FFDC Error Registers to an existing Error Log
 */
void SfcIBM::addFFDC(errlHndl_t & io_errl)
{
    errlHndl_t tmp_err = NULL;
    uint32_t data32 = 0;
    size_t size32 = sizeof(data32);

    // check iv_ffdcActive to avoid infinite loops
    if ( iv_ffdcActive == false )
    {
        iv_ffdcActive = true;

        TRACFCOMP( g_trac_pnor, ENTER_MRK"SfcIBM::addFFDC> adding FFDC to Error Log EID=0x%X, PLID=0x%X", io_errl->eid(), io_errl->plid() );

        ERRORLOG::ErrlUserDetailsLogRegister l_eud(iv_proc);

        // Add LPC Slave Status Register
        LpcSlaveStatReg_t lpc_slave_stat;
        tmp_err = readReg(SFC_LPC_SPACE,
                          LPC_SLAVE_REG_STATUS,
                          lpc_slave_stat.data32);
        if ( tmp_err )
        {
            delete tmp_err;
            TRACFCOMP( g_trac_pnor, "SfcIBM::addFFDC> Fail reading LPC Slave Status Register");
        }
        else
        {
            LPC::TransType lpc_range;
            uint32_t lpc_addr;
            sfc2lpc( SFC_LPC_SPACE, LPC_SLAVE_REG_STATUS,
                     lpc_range, lpc_addr );
            l_eud.addDataBuffer(&lpc_slave_stat.data32, size32,
                                DEVICE_LPC_ADDRESS( lpc_range,
                                                    lpc_addr ) );
        }

        // Add SFC Registers
        uint32_t sfc_regs[] = {
            SFC_REG_STATUS,
            SFC_REG_CONF,
            SFC_REG_CMD,
            SFC_REG_ADR,
            SFC_REG_ERASMS,
            SFC_REG_ERASLGS,
            SFC_REG_CONF4,
            SFC_REG_CONF5,
            SFC_REG_ADRCBF,
            SFC_REG_ADRCMF,
            SFC_REG_OADRNB,
            SFC_REG_OADRNS,
            SFC_REG_CHIPIDCONF,
            SFC_REG_ERRCONF,
            SFC_REG_ERRTAG,
            SFC_REG_ERROFF,
            SFC_REG_ERRSYN,
            SFC_REG_ERRDATH,
            SFC_REG_ERRDATL,
            SFC_REG_ERRCNT,
            SFC_REG_CLRCNT,
            SFC_REG_ERRINJ,
            SFC_REG_PROTA,
            SFC_REG_PROTM,
            SFC_REG_ECCADDR,
            SFC_REG_ECCRNG,
            SFC_REG_ERRORS,
            SFC_REG_INTMSK,
            SFC_REG_INTENM,
            SFC_REG_CONF2,
            SFC_REG_CONF3
        };


        for( size_t x=0; x<(sizeof(sfc_regs)/sizeof(sfc_regs[0])); x++ )
        {
            tmp_err = readReg( SFC_CMD_SPACE,
                               sfc_regs[x],
                               data32 );

            if( tmp_err )
            {
                delete tmp_err;
            }
            else
            {
                LPC::TransType lpc_range;
                uint32_t lpc_addr;
                sfc2lpc( SFC_CMD_SPACE, sfc_regs[x],
                         lpc_range, lpc_addr );
                l_eud.addDataBuffer(&data32, size32,
                                    DEVICE_LPC_ADDRESS(lpc_range,lpc_addr));
            }
        }

        l_eud.addToLog(io_errl);

        TRACFCOMP( g_trac_pnor, EXIT_MRK"SfcIBM::addFFDC> Information added to error log");

        // reset FFDC active flag
        iv_ffdcActive = false;
    }

    return;
}


/**
 * @brief Send a user-defined SPI command
 */
errlHndl_t SfcIBM::sendSpiCmd( uint8_t i_opCode,
                               uint32_t i_address,
                               size_t i_writeCnt,
                               const uint8_t* i_writeData,
                               size_t i_readCnt,
                               uint8_t* o_readData )
{
    errlHndl_t errhdl = NULL;

    do {
#ifdef CONFIG_ALLOW_MICRON_PNOR
        //Do a read of flash address zero to workaround
        // a micron bug with extended reads
        if( (PNOR::HWWK_MICRON_EXT_READ & iv_flashWorkarounds)
            && (i_readCnt > 4) )
        {
            uint32_t ignored = 0;
            errhdl = readFlash( 0, 1, &ignored );
            if(errhdl) { break; }
        }
#endif

        //Configure the custom command definition
        SfcCustomReg_t confreg;
        confreg.opcode = i_opCode;
        confreg.length = i_writeCnt;
        confreg.write = 1;
        if( i_readCnt > 0 )
        {
            confreg.length = i_readCnt;
            confreg.read = 1;
            confreg.write = 0;
        }

        //Setup the address if needed
        if( i_address != NO_ADDRESS )
        {
            confreg.needaddr = 1;
            errhdl = writeReg(SFC_CMD_SPACE,
                              SFC_REG_ADR,
                              i_address);
            if( errhdl ) { break; }
        }

        //@fixme-RTC:109860 - handle write data someday (no current need)
        assert( i_writeCnt == 0 );

        //Setup the custom command reg
        errhdl = writeReg(SFC_CMD_SPACE,
                          SFC_REG_CHIPIDCONF,
                          confreg.data32);
        if( errhdl ) { break; }

        //Issue Get Chip ID command
        SfcCmdReg_t sfc_cmd;
        sfc_cmd.opcode = SFC_OP_CHIPID;
        sfc_cmd.length = 0;
        errhdl = writeReg(SFC_CMD_SPACE,
                          SFC_REG_CMD,
                          sfc_cmd.data32);
        if( errhdl ) { break; }

        //Poll for complete status
        errhdl = pollOpComplete();
        if( errhdl ) { break; }

        //Return the data if this is a read
        if( i_readCnt > 0 )
        {
            //Read the Status from the Command Buffer
            errhdl = readFromBuffer( i_readCnt, o_readData );
            if(errhdl) { break; }
        }
    } while(0);


    return errhdl;
}

/**
 * @brief Return first 3 bytes of NOR chip id
 * @return Error from operation
 */
errlHndl_t SfcIBM::getNORChipId( uint32_t& o_chipId )
{
    errlHndl_t l_err = NULL;
    TRACFCOMP( g_trac_pnor, "SfcIBM::getNORChipId>" );

    do {
        if( iv_norChipId != PNOR::UNKNOWN_NOR_ID )
        {
            o_chipId = iv_norChipId;
            break;
        }

        //Configure Get Chip ID opcode
        uint32_t confData = SPI_JEDEC_CHIPID << 24;
        confData |= 0x00800003;  // 8-> read, 3->3 bytes
        TRACDCOMP( g_trac_pnor, "SfcIBM::getNORChipId> confData=0x%.8x",
                   confData );
        l_err = writeReg(SFC_CMD_SPACE,
                         SFC_REG_CHIPIDCONF,
                         confData);
        if(l_err) { break; }

        //Issue Get Chip ID command
        SfcCmdReg_t sfc_cmd;
        sfc_cmd.opcode = SFC_OP_CHIPID;
        sfc_cmd.length = 0;

        l_err = writeReg(SFC_CMD_SPACE,
                         SFC_REG_CMD,
                         sfc_cmd.data32);
        if(l_err) { break; }

        //Poll for complete status
        l_err = pollOpComplete();
        if(l_err) { break; }

        //Read the ChipID from the Command Buffer
        l_err = readReg(SFC_CMDBUF_SPACE,
                        0, //Offset into CMD BUFF space in bytes
                        o_chipId);
        if(l_err) { break; }

        // Only look at a portion of the data that is returned
        o_chipId &= ID_MASK;
        iv_norChipId = o_chipId;
    } while(0);

    return l_err;

}


/**
 * @brief Reset hardware to get into clean state
 */
errlHndl_t SfcIBM::hwReset( ResetLevels i_resetLevel )
{
    errlHndl_t l_err = NULL;

    // @todo RTC 109999 - Skipping because SFC resets can
    // cause problems on subsequent reads and writes
    TRACFCOMP(g_trac_pnor, "SfcIBM::hwReset> Skipping reset");
#if 0

    // check iv_reset_active to avoid infinite loops
    // and don't reset if in the middle of FFDC collection
    if ( ( iv_resetActive == false ) &&
         ( iv_ffdcActive == false  ) )
    {
        iv_resetActive = true;

        TRACFCOMP(g_trac_pnor, "SfcIBM::hwReset> i_pnorResetLevel=0x%.8X", i_resetLevel);

        do {
            // 32 bits for address and data for LPC operations
            uint32_t lpc_data=0;
            size_t reg_size = sizeof(uint32_t);

            /***************************************/
            /* Handle the different reset levels   */
            /***************************************/
            switch(i_resetLevel)
            {
                case RESET_CLEAR:
                    {// Nothing to do here, so just break
                        break;
                    }

                case RESET_LPC_SLAVE:
                    {
                        TRACFCOMP(g_trac_pnor, "SfcIBM::hwReset> Writing bit0 of LPC_SLAVE_REG_RESET to reset LPC Slave Logic");
                        lpc_data = 0x80000000;
                        l_err = deviceOp( DeviceFW::WRITE,
                                    iv_proc,
                                    &lpc_data,
                                    reg_size,
                                    DEVICE_LPC_ADDRESS(LPC::TRANS_REG,
                                                       LPC_SLAVE_REG_RESET) );
                        break;
                    }

                case RESET_LPC_SLAVE_ERRS:
                    {
                        TRACFCOMP(g_trac_pnor, "SfcIBM::hwReset> Writing bit1 of LPC_SLAVE_REG_RESET to reset LPC Slave Errors");
                        lpc_data = 0x40000000;
                        l_err = deviceOp( DeviceFW::WRITE,
                                    iv_proc,
                                    &lpc_data,
                                    reg_size,
                                    DEVICE_LPC_ADDRESS(LPC::TRANS_REG,
                                                       LPC_SLAVE_REG_RESET) );
                        break;
                    }

                case RESET_SFC_LOCAL_BUS:
                    {
                        TRACFCOMP(g_trac_pnor, "SfcIBM::hwReset> Writing bit2 of LPC_SLAVE_REG_RESET to reset Local SFC Bus. Requires PNOR reinitialization");
                        lpc_data = 0x20000000;
                        l_err = deviceOp( DeviceFW::WRITE,
                                    iv_proc,
                                    &lpc_data,
                                    reg_size,
                                    DEVICE_LPC_ADDRESS(LPC::TRANS_REG,
                                                       LPC_SLAVE_REG_RESET) );
                        if (l_err) { break; }

                        l_err = hwInit();
                        break;
                    }

                case RESET_SFCBUS_LPCSLAVE_ERRS:
                    {
                        // Must handle both errors
                        TRACFCOMP(g_trac_pnor, "SfcIBM::hwReset> Writing bits1,2 of LPC_SLAVE_REG_RESET to reset LPC Slave Errors and Local SFC Bus. Requires PNOR reinitialization");
                        lpc_data = 0x60000000;
                        l_err = deviceOp( DeviceFW::WRITE,
                                    iv_proc,
                                    &lpc_data,
                                    reg_size,
                                    DEVICE_LPC_ADDRESS(LPC::TRANS_REG,
                                                       LPC_SLAVE_REG_RESET) );
                        if (l_err) { break; }

                        l_err = hwInit();
                        break;
                    }

                    // else - unsupported reset level
                default:
                    {

                        TRACFCOMP( g_trac_pnor, ERR_MRK"SfcIBM::hwReset> Unsupported Reset Level Passed In: 0x%X", i_resetLevel);

                        /*@
                         * @errortype
                         * @moduleid     PNOR::MOD_SFCIBM_HWRESET
                         * @reasoncode   PNOR::RC_UNSUPPORTED_OPERATION
                         * @userdata1    Unsupported Reset Level Parameter
                         * @userdata2    <unused>
                         * @devdesc      SfcIBM::hwReset> Unsupported Reset
                         *               Level requested
                         * @custdesc     An internal firmware error occurred.
                         */
                        l_err = new ERRORLOG::ErrlEntry(
                                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            PNOR::MOD_SFCIBM_HWRESET,
                                            PNOR::RC_UNSUPPORTED_OPERATION,
                                            i_resetLevel,
                                            0,
                                            true /*SW error*/);

                        l_err->collectTrace(PNOR_COMP_NAME);
                        break;
                    }
            }// end switch

            if ( l_err )
            {
                // Indicate that we weren't successful in resetting PNOR
                TRACFCOMP( g_trac_pnor,ERR_MRK"SfcIBM::hwReset>> Fail doing PNOR reset at level 0x%X (recovery count=%d): eid=0x%X", i_resetLevel, iv_errorHandledCount, l_err->eid());
            }
            else
            {
                // Successful, so increment recovery count
                iv_errorHandledCount++;

                TRACFCOMP( g_trac_pnor,INFO_MRK"SfcIBM::hwReset>> Successful PNOR reset at level 0x%X (recovery count=%d)", i_resetLevel, iv_errorHandledCount);
            }


        } while(0);

        // reset RESET active flag
        iv_resetActive = false;
    }

#endif

    return l_err;
}

