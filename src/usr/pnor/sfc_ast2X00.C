/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/sfc_ast2X00.C $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
#include <sio/sio.H>
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
#include <errl/hberrltypes.H>
#include <lpc/lpcif.H>
#include "sfc_ast2X00.H"
#include "norflash.H"
#include <util/align.H>
#include "pnor_common.H"

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
/*errlHndl_t create_SfcDD( SfcDD*& o_sfc,
                         TARGETING::Target* i_proc )
{
    errlHndl_t l_err = NULL;
    TRACFCOMP( g_trac_pnor, "Creating SfcAST2X00 object" );
    o_sfc = new SfcAST2X00( l_err, i_proc );
    return l_err;
}
**/
};

/**
 * @brief Constructor
 */
SfcAST2X00::SfcAST2X00( errlHndl_t& o_err,
                        TARGETING::Target* i_proc )
: SfcDD(o_err,i_proc)
{
}

/**
 * @brief Read data from the flash
 */
errlHndl_t SfcAST2X00::readFlash( uint32_t i_addr,
                                  size_t i_size,
                                  void* o_data )
{
    errlHndl_t l_err = NULL;
    TRACDCOMP( g_trac_pnor, ENTER_MRK"SfcAST2X00::readFlash> i_addr=0x%.8x, i_size=0x%.8x",  i_addr, i_size );
    do
    {
        uint32_t* word_ptr = static_cast<uint32_t*>(o_data);
        uint32_t word_size = (ALIGN_4(i_size))/4;
        for( uint32_t words_read = 0;
             words_read < word_size;
             words_read ++ )
        {
            //Read directly from MMIO space
            uint32_t lpc_addr = PNOR::LPC_SFC_MMIO_OFFSET |
                                (i_addr + words_read*4);
            size_t reg_size = sizeof(uint32_t);

            l_err = deviceOp( DeviceFW::READ,
                              iv_proc,
                              &(word_ptr[words_read]),
                              reg_size,
                              DEVICE_LPC_ADDRESS(LPC::TRANS_FW,
                                                 lpc_addr) );
            if( l_err ) {  break; }
        }
        if( l_err ) { break; }
    } while(0);

    TRACDCOMP( g_trac_pnor, EXIT_MRK"SfcAST2X00::readFlash> err=%.8X", ERRL_GETEID_SAFE(l_err) );
    return l_err;
}


/**
 * @brief Write data into flash
 */
errlHndl_t SfcAST2X00::writeFlash( uint32_t i_addr,
                                   size_t i_size,
                                   void* i_data )
{
    TRACDCOMP( g_trac_pnor, ENTER_MRK"SfcAST2X00::writeFlash> i_addr=0x%.8x, i_size=0x%.8x", i_addr, i_size );
    errlHndl_t l_err = NULL;
    size_t l_bytes_left = i_size;
    size_t l_bytes_to_write = 0;
    uint32_t l_addr_to_write = i_addr;
    uint8_t* l_dataptr = reinterpret_cast<uint8_t*>(i_data);

    do {
        // Enable write mode
        l_err = enableWriteMode();
        if( l_err ) { break; }

        // Page Program (PP) command only supports 256 bytes at a time
        if( l_bytes_left <= PNOR::PAGE_PROGRAM_BYTES )
        {
            l_bytes_to_write = l_bytes_left;
            l_bytes_left = 0;
        }
        else
        {
            l_bytes_to_write = PNOR::PAGE_PROGRAM_BYTES;
            l_bytes_left -= PNOR::PAGE_PROGRAM_BYTES;
        }

        // Send in the Page Program command with the data to write
        uint8_t opcode = PNOR::SPI_JEDEC_PAGE_PROGRAM;
        l_err = sendSpiCmd( opcode, l_addr_to_write,
                            l_bytes_to_write,
                            l_dataptr,
                            0, NULL );
        if( l_err ) { break; }

        // Move to the next chunk
        l_addr_to_write += l_bytes_to_write;
        l_dataptr += l_bytes_to_write;

        // Wait for idle
        l_err = pollOpComplete();
        if( l_err ) { break; }

#ifdef CONFIG_ALLOW_MICRON_PNOR
        //check for special Micron Flag Status reg
        if(iv_flashWorkarounds & PNOR::HWWK_MICRON_WRT_ERASE)
        {
            l_err = PNOR::micronFlagStatus(this);
            if(l_err) { break; }
        }
#endif

    } while(l_bytes_left);

    TRACDCOMP( g_trac_pnor, EXIT_MRK"SfcAST2X00::writeFlash> err=%.8X", ERRL_GETEID_SAFE(l_err) );
    return l_err;
}


/**
 * @brief Erase a block of flash
 */
errlHndl_t SfcAST2X00::eraseFlash( uint32_t i_addr )
{
    TRACDCOMP(g_trac_pnor, ">>SfcAST2X00::eraseFlash> Block 0x%.8X", i_addr );
    errlHndl_t l_err = NULL;

    do {
        // Enable write mode
        l_err = enableWriteMode();
        if( l_err ) { break; }

        // Send erase command
        uint8_t opcode = PNOR::SPI_JEDEC_SECTOR_ERASE;
        l_err = sendSpiCmd( opcode, i_addr, 0, 0, 0, NULL );
        if( l_err ) { break; }

        // Wait for idle
        l_err = pollOpComplete();
        if( l_err ) { break; }

#ifdef CONFIG_ALLOW_MICRON_PNOR
        //check for special Micron Flag Status reg
        if(iv_flashWorkarounds & PNOR::HWWK_MICRON_WRT_ERASE)
        {
            l_err = PNOR::micronFlagStatus(this);
            if(l_err) { break; }
        }
#endif

    } while(0);

    TRACDCOMP( g_trac_pnor, EXIT_MRK"SfcAST2X00::eraseFlash> err=%.8X", ERRL_GETEID_SAFE(l_err) );
    return l_err;
}

//function to call SIO dd for ahb sio read
errlHndl_t SfcAST2X00::ahbSioReadWrapper(uint32_t i_ahb_sio_data,
                                         uint32_t i_lpc_addr)
{
    size_t l_ahb_sio_len = sizeof(i_ahb_sio_data);
    return deviceOp( DeviceFW::READ,
                     TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                     &(i_ahb_sio_data),
                     l_ahb_sio_len,
                     DEVICE_AHB_SIO_ADDRESS(i_lpc_addr));
}

//function to call SIO dd for ahb sio write
errlHndl_t SfcAST2X00::ahbSioWriteWrapper(uint32_t i_ahb_sio_data,
                                          uint32_t i_lpc_addr)
{
    size_t l_ahb_sio_len = sizeof(i_ahb_sio_data);
    return deviceOp( DeviceFW::WRITE,
                     TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                     &(i_ahb_sio_data),
                     l_ahb_sio_len,
                     DEVICE_AHB_SIO_ADDRESS(i_lpc_addr));
}

/**
 * @brief Send a SPI command
 */
errlHndl_t SfcAST2X00::sendSpiCmd( uint8_t i_opCode,
                                   uint32_t i_address,
                                   size_t i_writeCnt,
                                   const uint8_t* i_writeData,
                                   size_t i_readCnt,
                                   uint8_t* o_readData )
{
    errlHndl_t l_err = NULL;
    size_t opsize = 0;
    TRACDCOMP( g_trac_pnor, ENTER_MRK"SfcAST2X00::sendSpiCmd> i_opCode=%.2X, i_address=%.8X, i_writeCnt=0x%X, i_writeData=%p, i_readCnt=0x%X, o_readData=%p", i_opCode, i_address, i_writeCnt, i_writeData, i_readCnt, o_readData );

    do {
#ifdef CONFIG_ALLOW_MICRON_PNOR
        //Do a read of flash address zero to workaround
        // a micron bug with extended reads
        if( (PNOR::HWWK_MICRON_EXT_READ & iv_flashWorkarounds)
            && (i_readCnt > 4) )
        {
            uint32_t ignored = 0;
            l_err = readFlash( 0, 1, &ignored );
            if(l_err) { break; }
        }
#endif

        // Put controller into command mode (instead of read mode)
        l_err = commandMode( true );
        if( l_err ) { break; }

        // Write command to the beginning of the flash space
        opsize = sizeof(i_opCode);
        l_err = deviceOp( DeviceFW::WRITE,
                          iv_proc,
                          &i_opCode,
                          opsize, //just send opcode
                          DEVICE_LPC_ADDRESS(LPC::TRANS_FW,
                                             PNOR::LPC_SFC_MMIO_OFFSET) );
        if( l_err ) { break; }

        // Send address if there is one
        if( i_address != NO_ADDRESS )
        {
            // Write address to the beginning of the flash space
            opsize = sizeof(i_address);
            l_err = deviceOp( DeviceFW::WRITE,
                              iv_proc,
                              &i_address,
                              opsize, //only supporting 4-byte addresses
                              DEVICE_LPC_ADDRESS(LPC::TRANS_FW,
                                                 PNOR::LPC_SFC_MMIO_OFFSET) );
            if( l_err ) { break; }
        }

        // Send in the rest of the write data
        if( i_writeCnt && i_writeData )
        {
            size_t bytes_left = i_writeCnt;
            uint8_t* curptr = const_cast<uint8_t*>(i_writeData);
            while( bytes_left )
            {
                // Write the last partial word if there is one
                if( bytes_left < 4 )
                {
                    opsize = bytes_left;
                    l_err = deviceOp( DeviceFW::WRITE,
                                      iv_proc,
                                      curptr,
                                      opsize,
                                      DEVICE_LPC_ADDRESS(LPC::TRANS_FW,
                                                   PNOR::LPC_SFC_MMIO_OFFSET) );
                    break;
                }

                // Write data into the beginning of the flash space,
                //  in command mode this doesn't write the flash
                //  but instead is a pass-through to the area we
                //  really want to write
                opsize = sizeof(uint32_t);
                l_err = deviceOp( DeviceFW::WRITE,
                                  iv_proc,
                                  curptr,
                                  opsize,
                                  DEVICE_LPC_ADDRESS(LPC::TRANS_FW,
                                                   PNOR::LPC_SFC_MMIO_OFFSET));
                if( l_err ) { break; }

                curptr += 4;
                bytes_left -= 4;
            }
            if( l_err ) { break; }
        }

        // Read back the results
        if( i_readCnt && o_readData )
        {
            size_t bytes_left = i_readCnt;
            uint8_t* curptr = o_readData;
            while( bytes_left )
            {
                // Grab the last partial word if there is one
                if( bytes_left < 4 )
                {
                    opsize = bytes_left;
                    l_err = deviceOp( DeviceFW::READ,
                                      iv_proc,
                                      curptr,
                                      opsize,
                                      DEVICE_LPC_ADDRESS(LPC::TRANS_FW,
                                                   PNOR::LPC_SFC_MMIO_OFFSET) );
                    break;
                }

                // Read data from the beginning of the flash space,
                //  in command mode this doesn't read the flash
                //  but instead is a pass-through to the data we
                //  really want
                opsize = sizeof(uint32_t);
                l_err = deviceOp( DeviceFW::READ,
                                  iv_proc,
                                  curptr,
                                  opsize,
                                  DEVICE_LPC_ADDRESS(LPC::TRANS_FW,
                                                    PNOR::LPC_SFC_MMIO_OFFSET));
                if( l_err ) { break; }

                curptr += 4;
                bytes_left -= 4;
            }
            if( l_err ) { break; }
        }
    } while(0);

    // No matter what, put the logic back into read mode
    errlHndl_t tmp_err = commandMode( false );
    if( tmp_err )
    {
        if( l_err )
        {
            // Keep the original error, commit this one as info
            tmp_err->plid(l_err->plid());
            tmp_err->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
            ERRORLOG::errlCommit(tmp_err,PNOR_COMP_ID);
        }
        else
        {
            l_err = tmp_err;
        }
    }

    TRACDCOMP( g_trac_pnor, EXIT_MRK"SfcAST2X00::sendSpiCmd> o_readData=%.2X, err=%.8X", o_readData == NULL ? 0 : o_readData[0], ERRL_GETEID_SAFE(l_err) );
    return l_err;
}

/**
 * @brief Enable write mode
 */
errlHndl_t SfcAST2X00::enableWriteMode( void )
{
    errlHndl_t l_err = NULL;
    TRACDCOMP( g_trac_pnor, ENTER_MRK"SfcAST2X00::enableWriteMode>" );

    /* Some flashes need it to be hammered */
    PNOR::NorStatusReg_t status;
    size_t i = 0;
    for( i = 0; i < 10; i++ )
    {
        // Send the command to enable writes
        uint8_t opcode = PNOR::SPI_JEDEC_WRITE_ENABLE;
        l_err = sendSpiCmd( opcode, NO_ADDRESS, 0, NULL, 0, NULL );
        if( l_err ) { break; }

        // Check to see if it worked
        opcode = PNOR::SPI_JEDEC_READ_STATUS;
        l_err = sendSpiCmd( opcode, NO_ADDRESS, 0, NULL, 1, &(status.data8) );
        if( l_err ) { break; }

        if( status.writeEnable )
        {
            break;
        }
    }

    if( !l_err && !status.writeEnable )
    {
        /*@
         * @errortype
         * @moduleid     PNOR::MOD_SFCAST2X00_ENABLEWRITEMODE
         * @reasoncode   PNOR::RC_CANNOT_ENABLE_WRITES
         * @userdata1[24:31]   Output from RDSR
         * @userdata1[32:63]   NOR chip id
         * @userdata2    <unused>
         * @devdesc      SfcAST2X00::enableWriteMode> Unable to enable
         *               write mode on the PNOR flash
         * @custdesc     Firmware error accessing flash during IPL
         */
        l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                              PNOR::MOD_SFCAST2X00_ENABLEWRITEMODE,
                              PNOR::RC_CANNOT_ENABLE_WRITES,
                              TWO_UINT32_TO_UINT64( TO_UINT32(status.data8),
                                                    iv_norChipId),
                              0);
        // Limited in callout: no flash sub-target, so calling out processor
        l_err->addHwCallout( iv_proc,
                             HWAS::SRCI_PRIORITY_HIGH,
                             HWAS::NO_DECONFIG,
                             HWAS::GARD_NULL );
        addFFDC(l_err);
        l_err->collectTrace(PNOR_COMP_NAME);
    }

    TRACDCOMP( g_trac_pnor, EXIT_MRK"SfcAST2X00::enableWriteMode> err=%.8X", ERRL_GETEID_SAFE(l_err) );
    return l_err;
}

/**
 * @brief Poll for completion of SPI operation
 */
errlHndl_t SfcAST2X00::pollOpComplete( void )
{
    errlHndl_t l_err = NULL;
    TRACDCOMP( g_trac_pnor, ENTER_MRK"SfcAST2X00::pollOpComplete>" );

    do {
        // Send RDSR command until write-in-progress clears
        PNOR::NorStatusReg_t status;
        uint64_t poll_time = 0;
        uint64_t loop = 0;
        while( poll_time < MAX_WRITE_TIME_NS )
        {
            uint8_t opcode = PNOR::SPI_JEDEC_READ_STATUS;
            l_err = sendSpiCmd( opcode,
                                NO_ADDRESS,
                                0, NULL,
                                1, &(status.data8) );
            if( l_err ) { break; }

            // check if any op is still going
            if( !status.writeInProgress )
            {
                break;
            }

            // want to start out incrementing by small numbers then get bigger
            //  to avoid a really tight loop in an error case so we'll increase
            //  the wait each time through
            ++loop;
            nanosleep( 0, 100*loop );
            poll_time += 100*loop;
        }
        if( l_err ) { break; }

        TRACDCOMP(g_trac_pnor,"SfcAST2X00::pollOpComplete> command took %d ns", poll_time);

        // No status regs to check so just look for timeout
        if( status.writeInProgress )
        {
            TRACFCOMP( g_trac_pnor, "SfcAST2X00::pollOpComplete> Timeout during write or erase" );

            /*@
             * @errortype
             * @moduleid     PNOR::MOD_SFCAST2X00_POLLOPCOMPLETE
             * @reasoncode   PNOR::RC_SFC_TIMEOUT
             * @userdata1[0:31]   NOR Flash Chip ID
             * @userdata1[32:63]  Total poll time (ns)
             * @userdata2[56:63]  Output of RDSR command
             * @devdesc      SfcAST2X00::pollOpComplete> Timeout during
             *               write or erase operation
             * @custdesc     Hardware error accessing flash during IPL
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            PNOR::MOD_SFCAST2X00_POLLOPCOMPLETE,
                                            PNOR::RC_SFC_TIMEOUT,
                                            TWO_UINT32_TO_UINT64(iv_norChipId,
                                                                 poll_time),
                                            status.data8);

            // Limited in callout: no PNOR target, so calling out processor
            l_err->addHwCallout(
                        iv_proc,
                        HWAS::SRCI_PRIORITY_HIGH,
                        HWAS::NO_DECONFIG,
                        HWAS::GARD_NULL );

            addFFDC(l_err);
            l_err->collectTrace(PNOR_COMP_NAME);
            break;
        }
    } while(0);

    TRACDCOMP( g_trac_pnor, EXIT_MRK"SfcAST2X00::pollOpComplete> err=%.8X", ERRL_GETEID_SAFE(l_err) );
    return l_err;
}

/**
 * @brief Add error registers to an existing Error Log
 */
void SfcAST2X00::addFFDC( errlHndl_t& io_errhdl )
{
    TRACDCOMP( g_trac_pnor, ENTER_MRK"SfcAST2X00::addFFDC>" );
    //@fixme-RTC:115212 - Create userdetails that includes chipid and SFDP data

    errlHndl_t l_err = NULL;

    //Read SFDP for FFDC
    uint32_t outdata[4];
    l_err = sendSpiCmd( PNOR::SPI_JEDEC_READ_SFDP,
                        0,
                        0, NULL,
                        16, reinterpret_cast<uint8_t*>(outdata) );
    if( l_err )
    {
        delete l_err;
    }
    else
    {
        //Loop around and grab all 16 bytes
        for( size_t x=0; x<4; x++ )
        {
            TRACFCOMP( g_trac_pnor, "SFDP[%d]=%.8X", x, outdata[x] );
        }
    }

    TRACDCOMP( g_trac_pnor, EXIT_MRK"SfcAST2X00::addFFDC>" );
}
