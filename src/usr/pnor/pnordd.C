/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/pnordd.C $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2014                        */
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
/**
 *  @file pnordd.C
 *
 *  @brief Implementation of the PNOR Device Driver
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <sys/mmio.h>
#include <sys/task.h>
#include <sys/sync.h>
#include <sys/time.h>
#include <string.h>
#include <stdio.h>
#include <devicefw/driverif.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludlogregister.H>
#include <errl/errludstring.H>
#include <targeting/common/targetservice.H>
#include "pnordd.H"
#include <pnor/pnorif.H>
#include <pnor/pnor_reasoncodes.H>
#include <sys/time.h>
#include <initservice/initserviceif.H>
#include <util/align.H>
#include <config.h>


/*****************************************************************************/
// D e f i n e s
/*****************************************************************************/
#define PNORDD_MAX_RETRIES 1

extern trace_desc_t* g_trac_pnor;

namespace PNOR
{

    enum {
        VPO_MODE_MEMCPY = 0xFAC0FAC0FAC0FAC0,
        VPO_MODE_MMIO   = 0xDAB0DAB0DAB0DAB0,
    };

/**
 * @brief Performs an PNOR Read Operation
 * This function performs a PNOR Read operation. It follows a pre-defined
 * prototype functions in order to be registered with the device-driver
 * framework.
 *
 * @param[in]   i_opType        Operation type, see DeviceFW::OperationType
 *                              in driverif.H
 * @param[in]   i_target        PNOR target
 * @param[in/out] io_buffer     Read: Pointer to output data storage
 *                              Write: Pointer to input data storage
 * @param[in/out] io_buflen     Input: size of io_buffer (in bytes)
 *                              Output:
 *                                  Read: Size of output data
 *                                  Write: Size of data written
 * @param[in]   i_accessType    DeviceFW::AccessType enum (usrif.H)
 * @param[in]   i_args          This is an argument list for DD framework.
 *                              In this function, there's only one argument,
 *                              containing the PNOR address and chip select
 * @return  errlHndl_t
 */
errlHndl_t ddRead(DeviceFW::OperationType i_opType,
                  TARGETING::Target* i_target,
                  void* io_buffer,
                  size_t& io_buflen,
                  int64_t i_accessType,
                  va_list i_args)
{
    errlHndl_t l_err = NULL;
    uint64_t l_addr = va_arg(i_args,uint64_t);

    do{
        //@todo (RTC:36951) - add support for unaligned data
        // Ensure we are operating on a 32-bit (4-byte) boundary
        assert( reinterpret_cast<uint64_t>(io_buffer) % 4 == 0 );
        assert( io_buflen % 4 == 0 );

        // Read the flash
        l_err = Singleton<PnorDD>::instance().readFlash(io_buffer,
                                                        io_buflen,
                                                        l_addr);
        if(l_err)
        {
            break;
        }

    }while(0);

    return l_err;
}

/**
 * @brief Performs an PNOR Write Operation
 * This function performs a PNOR Write operation. It follows a pre-defined
 * prototype functions in order to be registered with the device-driver
 * framework.
 *
 * @param[in]   i_opType        Operation type, see DeviceFW::OperationType
 *                              in driverif.H
 * @param[in]   i_target        PNOR target
 * @param[in/out] io_buffer     Read: Pointer to output data storage
 *                              Write: Pointer to input data storage
 * @param[in/out] io_buflen     Input: size of io_buffer (in bytes)
 *                              Output:
 *                                  Read: Size of output data
 *                                  Write: Size of data written
 * @param[in]   i_accessType    DeviceFW::AccessType enum (usrif.H)
 * @param[in]   i_args          This is an argument list for DD framework.
 *                              In this function, there's only one argument,
 *                              containing the PNOR address and chip select
 * @return  errlHndl_t
 */
errlHndl_t ddWrite(DeviceFW::OperationType i_opType,
                   TARGETING::Target* i_target,
                  void* io_buffer,
                  size_t& io_buflen,
                  int64_t i_accessType,
                  va_list i_args)
{
    errlHndl_t l_err = NULL;
    uint64_t l_addr = va_arg(i_args,uint64_t);

    do{
        //@todo (RTC:36951) - add support for unaligned data
        // Ensure we are operating on a 32-bit (4-byte) boundary
        assert( reinterpret_cast<uint64_t>(io_buffer) % 4 == 0 );
        assert( io_buflen % 4 == 0 );

        // Write the flash
        l_err = Singleton<PnorDD>::instance().writeFlash(io_buffer,
                                                         io_buflen,
                                                         l_addr);
        if(l_err)
        {
           break;
        }

    }while(0);

    return l_err;
}

/**
 * @brief Informs caller if PNORDD is using
 *        L3 Cache for fake PNOR or not.
 *
 * @return Indicate state of fake PNOR
 *         true = PNOR DD is using L3 Cache for fake PNOR
 *         false = PNOR DD not using L3 Cache for fake PNOR
 */
bool usingL3Cache()
{
    return Singleton<PnorDD>::instance().usingL3Cache();
}


// Register PNORDD access functions to DD framework
DEVICE_REGISTER_ROUTE(DeviceFW::READ,
                      DeviceFW::PNOR,
                      TARGETING::TYPE_PROC,
                      ddRead);

DEVICE_REGISTER_ROUTE(DeviceFW::WRITE,
                      DeviceFW::PNOR,
                      TARGETING::TYPE_PROC,
                      ddWrite);

}; //namespace PNOR


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


/**
 * @brief Performs a PNOR Read Operation
 */
errlHndl_t PnorDD::readFlash(void* o_buffer,
                             size_t& io_buflen,
                             uint64_t i_address)
{
    //TRACDCOMP(g_trac_pnor, "PnorDD::readFlash(i_address=0x%llx)> ", i_address);
    errlHndl_t l_err = NULL;

    do{
        //mask off chip select for now, will probably break up fake PNOR into
        //multiple fake chips eventually
        uint64_t l_address = i_address & 0x00000000FFFFFFFF;

        // skip everything in MEMCPY mode
        if( MODEL_MEMCPY == iv_mode )
        {
            read_fake_pnor( l_address, o_buffer, io_buflen );
            break;
        }

        //If we get here we're doing either MODEL_LPC_MEM, MODEL_REAL_CMD, or MODEL_REAL_MMIO
        mutex_lock(&cv_mutex);
        l_err = bufferedSfcRead(i_address, io_buflen, o_buffer);
        mutex_unlock(&cv_mutex);

        if(l_err) { break;}

    }while(0);

    return l_err;
}

/**
 * @brief Performs a PNOR Write Operation
 */
errlHndl_t PnorDD::writeFlash(void* i_buffer,
                              size_t& io_buflen,
                              uint64_t i_address)
{
    TRACFCOMP(g_trac_pnor, ENTER_MRK"PnorDD::writeFlash(i_address=0x%llx)> ", i_address);
    errlHndl_t l_err = NULL;

    do{
        TRACDCOMP(g_trac_pnor,"PNOR write %.8X", i_address);

        //mask off chip select for now, will probably break up fake PNOR into
        //multiple fake chips eventually
        uint64_t l_address = i_address & 0x00000000FFFFFFFF;

        // skip everything in MEMCPY mode
        if( MODEL_MEMCPY == iv_mode )
        {
            write_fake_pnor( l_address, i_buffer, io_buflen );
            break;
        }

        //If we get here we're doing either MODEL_LPC_MEM, MODEL_REAL_CMD, or MODEL_REAL_MMIO

        //If we're in VPO, just do the write directly (no erases)
        if(0 != iv_vpoMode)
        {
            mutex_lock(&cv_mutex);
            l_err = bufferedSfcWrite(static_cast<uint32_t>(l_address),
                                     8,
                                     i_buffer);
            mutex_unlock(&cv_mutex);
            break;
        }


        // LPC is accessed 32-bits at a time, but SFC has a 256byte buffer
        //   but we also need to be smart about handling erases.  In NOR
        //   flash we can clear bits without an erase but we cannot set them.
        //   When we erase we have to erase an entire block of data at a time.

        uint32_t cur_writeStart_addr = static_cast<uint32_t>(l_address);
        uint32_t cur_blkStart_addr = findEraseBlock(cur_writeStart_addr);
        uint32_t cur_blkEnd_addr = cur_blkStart_addr + iv_erasesize_bytes;
        uint32_t write_bytes = iv_erasesize_bytes;
        uint64_t num_blocks = getNumAffectedBlocks(cur_writeStart_addr,io_buflen);
        uint64_t bytes_left = io_buflen;


        // loop through erase blocks until we've gotten through all
        //  affected blocks
        for( uint64_t block = 0;
             block < num_blocks;
             ++block )
        {
            TRACDCOMP(g_trac_pnor,"cur_writeStart_addr=%X, cur_blkStart_addr=%X, cur_blkEnd_addr=%X, bytes_left=%X", cur_writeStart_addr, cur_blkStart_addr, cur_blkEnd_addr, bytes_left );
            // writing at a block boundary, just write the whole thing
            if( cur_writeStart_addr == cur_blkStart_addr )
            {
                if( bytes_left > iv_erasesize_bytes )
                {
                    write_bytes = iv_erasesize_bytes;
                }
                else
                {
                    write_bytes = bytes_left;
                }
            }
            // writing the end of a block
            else //cur_writeStart_addr > cur_blkStart_addr
            {
                uint32_t bytes_tail = cur_blkEnd_addr - cur_writeStart_addr;
                if( bytes_left < bytes_tail )
                {
                    write_bytes = bytes_left;
                }
                else
                {
                    write_bytes = bytes_tail;
                }
            }
            //note that writestart < blkstart can never happen

            // write a single block of data out to flash efficiently
            mutex_lock(&cv_mutex);
            l_err = compareAndWriteBlock(
                              cur_blkStart_addr,
                              cur_writeStart_addr,
                              write_bytes,
                              (void*)((uint64_t)i_buffer +
                              ((uint64_t)cur_writeStart_addr-l_address)));

            mutex_unlock(&cv_mutex);

            if( l_err ) { break; }

            cur_blkStart_addr = cur_blkEnd_addr;  //move start to end of current erase block
            cur_blkEnd_addr   += iv_erasesize_bytes;; //increment end by erase block size.
            cur_writeStart_addr += write_bytes;
            bytes_left -= write_bytes;

        }
        if( l_err ) { break; }

    }while(0);

    // keeping track of every actual byte written is complicated and it can
    //  be misleading in the cases where we end up erasing and writing an
    //  entire block, instead just return zero for any failures
    if( l_err )
    {
        io_buflen = 0;
    }
    TRACFCOMP(g_trac_pnor,EXIT_MRK"PnorDD::writeFlash(i_address=0x%llx)> io_buflen=%.8X", i_address, io_buflen);

    return l_err;
}


/********************
 Private/Protected Methods
 ********************/
mutex_t PnorDD::cv_mutex = MUTEX_INITIALIZER;
uint64_t PnorDD::iv_vpoMode = 0;

//
// @note    fake pnor no longer needs to allow from for SLW
//          image so it is now 4MB.
//
#define FAKE_PNOR_START (4*MEGABYTE)
#define FAKE_PNOR_END (8*MEGABYTE)
#define FAKE_PNOR_SIZE (FAKE_PNOR_END-FAKE_PNOR_START)

/**
 * @brief  Constructor
 */
PnorDD::PnorDD( PnorMode_t i_mode,
                uint64_t i_fakeStart,
                uint64_t i_fakeSize )
: iv_mode(i_mode)
, iv_ffdc_active(false)
, iv_error_handled_count(0x0)
, iv_error_recovery_failed(false)
, iv_reset_active(false)
{
    iv_erasesize_bytes = ERASESIZE_BYTES_DEFAULT;

    //Zero out erase counter
    memset(iv_erases, 0xff, sizeof(iv_erases));

    //Use real PNOR for everything except VPO
    if(0 == iv_vpoMode)
    {
        iv_vpoMode =  mmio_scratch_read(MMIO_SCRATCH_PNOR_MODE);
    }
    //@fixme-RTC:95130
    //Force to not be in VPO mode
    iv_vpoMode = 0;

    //In the normal case we will choose the mode for the caller
    if( MODEL_UNKNOWN == iv_mode )
    {
        if(iv_vpoMode == PNOR::VPO_MODE_MEMCPY)
        {
            //VPO override set -- use fastest method -- memcpy
            TRACFCOMP(g_trac_pnor,"PNORDD: Running in MEMCPY mode for VPO");
            iv_mode = MODEL_MEMCPY;
        }
        else if(iv_vpoMode == PNOR::VPO_MODE_MMIO)
        {
            //VPO override set -- use MMIO mode
            TRACFCOMP(g_trac_pnor,"PNORDD: Running in VPO Mode, writes will not trigger erase attempts");
            iv_mode = MODEL_REAL_MMIO;
        }
        else
        {
            //Normal mode
            iv_mode = MODEL_REAL_MMIO;
        }
    }

    if( (MODEL_MEMCPY == iv_mode) ||
        (MODEL_LPC_MEM == iv_mode) )
    {
        //Only use input fake values if they are != zero
        iv_fakeStart = (i_fakeStart != 0) ? i_fakeStart : FAKE_PNOR_START;
        iv_fakeSize = (i_fakeSize != 0) ? i_fakeSize : FAKE_PNOR_SIZE;
    }

    if( (MODEL_REAL_CMD == iv_mode) ||
        (MODEL_REAL_MMIO == iv_mode) )
    {
        sfcInit( );
    }

    TRACFCOMP(g_trac_pnor, "PnorDD::PnorDD()> Using mode %d, vpo=%d", iv_mode, iv_vpoMode);
}

/**
 * @brief  Destructor
 */
PnorDD::~PnorDD()
{

}

bool PnorDD::cv_sfcInitDone = false;  //Static flag to ensure we only init the SFC one time.
uint32_t PnorDD::cv_nor_chipid = 0;  //Detected NOR Flash Type
uint32_t PnorDD::cv_hw_workaround = 0;  //Hardware Workaround flags

/**
 * STATIC
 * @brief Static Initializer
 */
void PnorDD::sfcInit( )
{
    TRACFCOMP(g_trac_pnor, "PnorDD::sfcInit> iv_mode=0x%.8x", iv_mode );
    errlHndl_t  l_err  =   NULL;

    mutex_lock(&cv_mutex);

    do {
#ifdef CONFIG_SFC_IS_AST2400
        TRACFCOMP( g_trac_pnor, "PnorDD::sfcInit> Nothing to do yet for AST2400" );
        break;
        //@todo RTC:106881 - Fix up to support erase/write later
#endif //CONFIG_SFC_IS_AST2400

        if(!cv_sfcInitDone)
        {
#ifdef CONFIG_BMC_DOES_SFC_INIT

            // Set OPB LPCM FIR Mask - hostboot will monitor these FIR bits
            //@todo (RTC:36950) - add non-master support
            TARGETING::Target* scom_target =
                       TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;
            size_t scom_size = sizeof(uint64_t);
            uint64_t fir_mask_data = OPB_LPCM_FIR_ERROR_MASK;

            // Read FIR Register
            l_err = deviceOp( DeviceFW::WRITE,
                              scom_target,
                              &(fir_mask_data),
                              scom_size,
                              DEVICE_SCOM_ADDRESS(OPB_LPCM_FIR_MASK_WO_OR_REG));
            if( l_err ) { break; }

            //Determine NOR Flash type - triggers vendor specific workarounds
            //We also use the chipID in some FFDC situations.
            l_err = getNORChipId(cv_nor_chipid);
            if(l_err) { break; }
            TRACFCOMP(g_trac_pnor,
                      "PnorDD::sfcInit: cv_nor_chipid=0x%.8x> ",
                      cv_nor_chipid );

            // Re-initialize internal erase size cached value.
            l_err = readRegSfc(SFC_CMD_SPACE,
                               SFC_REG_ERASMS,
                               iv_erasesize_bytes);
            if(l_err) { break; }
            TRACFCOMP(g_trac_pnor,"PnorDD::sfcInit: iv_erasesize_bytes=%X",iv_erasesize_bytes);

#else //==!CONFIG_BMC_DOES_SFC_INIT

            TRACFCOMP( g_trac_pnor, INFO_MRK "Initializing SFC registers -- unsupported!!!" );
            //@todo RTC:97493 - Add SFC initialization from Host
            INITSERVICE::doShutdown( PNOR::RC_UNSUPPORTED_MODE);

#endif //CONFIG_BMC_DOES_SFC_INIT

            cv_sfcInitDone = true;
        }

    }while(0);

    mutex_unlock(&cv_mutex);

    if( l_err )
    {
        TRACFCOMP( g_trac_pnor,  ERR_MRK
                   "PnorDD::sfcInit> Committing error log");
        errlCommit(l_err,PNOR_COMP_ID);
    }

    TRACFCOMP(g_trac_pnor, "< PnorDD::sfcInit" );
}

bool PnorDD::usingL3Cache( )
{
    TRACDCOMP(g_trac_pnor,
              "PnorDD::usingL3Cache> iv_mode=0x%.8x", iv_mode );

    //If we are in one of the fake PNOR modes,
    //than we are using L3 CAche
    if( (MODEL_MEMCPY == iv_mode) ||
        (MODEL_LPC_MEM == iv_mode) )
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief Write a SFC Register
 */
errlHndl_t PnorDD::writeRegSfc(SfcRange i_range,
                               uint32_t i_addr,
                               uint32_t i_data)
{
    errlHndl_t l_err = NULL;
    uint32_t lpc_addr = 0;

    switch(i_range)
    {
    case SFC_MMIO_SPACE:
        {
            lpc_addr = LPC_SFC_MMIO_OFFSET | i_addr;
            break;
        }
    case SFC_CMD_SPACE:
        {
            lpc_addr = LPC_SFC_CMDREG_OFFSET | i_addr;
            break;
        }
    case SFC_CMDBUF_SPACE:
        {
            lpc_addr = LPC_SFC_CMDBUF_OFFSET | i_addr;
            break;
        }
    case SFC_LPC_SPACE:
        {
            lpc_addr = LPCHC_FW_SPACE | i_addr;
            break;
        }
    default:
        {
            TRACFCOMP(g_trac_pnor, ERR_MRK"PnorDD::writeRegSfc> Unsupported SFC Address Range: i_range=0x%.16X, i_addr=0x%.8X. Calling doShutdown(PNOR::RC_UNSUPPORTED_SFCRANGE)",
                      i_range, i_addr);

            //Can't function without PNOR, initiate shutdown.
            INITSERVICE::doShutdown( PNOR::RC_UNSUPPORTED_SFCRANGE);
            break;
        }
    } //end switch

    TRACDCOMP( g_trac_pnor, "PnorDD::writeRegSfc> lpc_addr=0x%.8x, i_data=0x%.8x",
               lpc_addr, i_data );
    l_err = writeLPC(lpc_addr, i_data);

    return l_err;
}

/**
 * @brief Read a SFC Register
 */
errlHndl_t PnorDD::readRegSfc(SfcRange i_range,
                              uint32_t i_addr,
                              uint32_t& o_data)
{
    errlHndl_t l_err = NULL;
    uint32_t lpc_addr = 0;

    switch(i_range)
    {
    case SFC_MMIO_SPACE:
        {
            lpc_addr = LPC_SFC_MMIO_OFFSET | i_addr;
            break;
        }
    case SFC_CMD_SPACE:
        {
            lpc_addr = LPC_SFC_CMDREG_OFFSET | i_addr;
            break;
        }
    case SFC_CMDBUF_SPACE:
        {
            lpc_addr = LPC_SFC_CMDBUF_OFFSET | i_addr;
            break;
        }
    case SFC_LPC_SPACE:
        {
            lpc_addr = LPCHC_FW_SPACE | i_addr;
            break;
        }
    default:
        {
            TRACFCOMP(g_trac_pnor, ERR_MRK"PnorDD::readRegSfc> Unsupported SFC Address Range: i_range=0x%.16X, i_addr=0x%.8X. Calling doShutdown(PNOR::RC_UNSUPPORTED_SFCRANGE)",
                      i_range, i_addr);

            //Can't function without PNOR, initiate shutdown.
            INITSERVICE::doShutdown( PNOR::RC_UNSUPPORTED_SFCRANGE);
            break;
        }
    } //end switch

    l_err = readLPC(lpc_addr, o_data);
    TRACDCOMP( g_trac_pnor, "PnorDD::readRegSfc> lpc_addr=0x%.8x, o_data=0x%.8x",
               lpc_addr, o_data );

    return l_err;
}


/**
 * @brief Poll for SFC Op Complete
 */
errlHndl_t PnorDD::pollSfcOpComplete(uint64_t i_pollTime)
{
    errlHndl_t l_err = NULL;
    ResetLevels pnorResetLevel = RESET_CLEAR;

    TRACDCOMP( g_trac_pnor, "PnorDD::pollSfcOpComplete> i_pollTime=0x%.8x",
               i_pollTime );

    do {
        //Poll for complete status
        SfcStatReg_t sfc_stat;
        uint64_t poll_time = 0;
        uint64_t loop = 0;
        while( poll_time < i_pollTime )
        {
            l_err = readRegSfc(SFC_CMD_SPACE,
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

        l_err = checkForSfcErrors( pnorResetLevel );
        if( l_err ) { break; }

        // If no errors AND done bit not set, call out undefined error
        if( (sfc_stat.done == 0) )
        {
            TRACFCOMP(g_trac_pnor,
                      "PnorDD::pollSfcOpComplete> Error or timeout from SFC Status Register"
                      );

            /*@
             * @errortype
             * @moduleid     PNOR::MOD_PNORDD_POLLSFCOPCOMPLETE
             * @reasoncode   PNOR::RC_LPC_ERROR
             * @userdata1[0:31]   NOR Flash Chip ID
             * @userdata1[32:63]  Total poll time (ns)
             * @userdata2[0:31]    ECCB Status Register
             * @devdesc      PnorDD::pollSfcOpComplete> Error or timeout from
             *               SFC Status Register
             * @custdesc    A problem occurred while accessing the boot flash.
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            PNOR::MOD_PNORDD_POLLSFCOPCOMPLETE,
                                            PNOR::RC_LPC_ERROR,
                                            TWO_UINT32_TO_UINT64(cv_nor_chipid,
                                                                 poll_time),
                                            TWO_UINT32_TO_UINT64(sfc_stat.data32,0));

            // Limited in callout: no PNOR target, so calling out processor
            l_err->addHwCallout(
                            TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                            HWAS::SRCI_PRIORITY_HIGH,
                            HWAS::NO_DECONFIG,
                            HWAS::GARD_NULL );

            addFFDCRegisters(l_err);
            l_err->collectTrace(PNOR_COMP_NAME);
            l_err->collectTrace(XSCOM_COMP_NAME);

            // Reset LPC Slave since it appears to be hung - handled below
            pnorResetLevel = RESET_LPC_SLAVE;

            break;
        }
        TRACDCOMP(g_trac_pnor,"pollSfcOpComplete> command took %d ns", poll_time);

    }while(0);

    // If we have an error that requires a reset, do that here
    if ( l_err && ( pnorResetLevel != RESET_CLEAR ) )
    {
        errlHndl_t tmp_err = NULL;
        tmp_err = resetPnor(pnorResetLevel);

        if ( tmp_err )
        {
            // Commit reset error as informational since we have
            // original error l_err
            TRACFCOMP(g_trac_pnor, "PnorDD::pollSfcOpComplete> Error from resetPnor() after previous error eid=0x%X. Committing resetPnor() error log eid=0x%X.",
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
 * @brief Check For Errors in SFC Status Registers
 */
errlHndl_t PnorDD::checkForSfcErrors( ResetLevels &o_pnorResetLevel )
{
    errlHndl_t l_err = NULL;
    bool errorFound = false;

    // Used to set Reset Levels, if necessary
    o_pnorResetLevel = RESET_CLEAR;

    // Default status values in case we fail in reading the registers
    LpcSlaveStatReg_t lpc_slave_stat;
    lpc_slave_stat.data32 = 0xDEADBEEF;
    SfcStatReg_t sfc_stat;
    sfc_stat.data32 = 0xDEADBEEF;

    do {

        // First Read LPC Slave Status Register
        l_err = readRegSfc(SFC_LPC_SPACE,
                           LPC_SLAVE_REG_STATUS,
                           lpc_slave_stat.data32);

        // If we can't read status register, exit out
        if( l_err ) { break; }

        TRACDCOMP( g_trac_pnor, INFO_MRK"PnorDD::checkForSfcErrors> LPC Slave status reg: 0x%08llx",
                   lpc_slave_stat.data32);

        // Start with lighter reset level
        if( 1 == lpc_slave_stat.lbusparityerror )
        {
            errorFound = true;
            o_pnorResetLevel = RESET_LPC_SLAVE_ERRS;
            TRACFCOMP( g_trac_pnor, ERR_MRK"PnorDD::checkForSfcErrors> LPC Slave Local Bus Parity Error: status reg: 0x%08llx, ResetLevel=%d",
                       lpc_slave_stat.data32, o_pnorResetLevel);
        }

        // Check for more stronger reset level
        if( 0 != lpc_slave_stat.lbus2opberr )
        {
            errorFound = true;
            // All of these errors require the SFC Local Bus Reset
            o_pnorResetLevel = RESET_SFC_LOCAL_BUS;

            if ( LBUS2OPB_ADDR_PARITY_ERR == lpc_slave_stat.lbus2opberr )
            {
                // This error also requires LPC Slave Errors to be Cleared
                o_pnorResetLevel = RESET_SFCBUS_LPCSLAVE_ERRS;
                TRACFCOMP( g_trac_pnor, ERR_MRK"PnorDD::checkForSfcErrors> LBUS2OPB Address Parity Error: LPC Slave status reg: 0x%08llx, ResetLevel=%d",
                           lpc_slave_stat.data32, o_pnorResetLevel);

            }

            else if ( LBUS2OPB_INVALID_SELECT_ERR == lpc_slave_stat.lbus2opberr)
            {
                TRACFCOMP( g_trac_pnor, ERR_MRK"PnorDD::checkForSfcErrors> LBUS2OPB Invalid Select Error: LPC Slave status reg: 0x%08llx, ResetLevel=%d",
                           lpc_slave_stat.data32, o_pnorResetLevel);

            }
            else if ( LBUS2OPB_DATA_PARITY_ERR == lpc_slave_stat.lbus2opberr )
            {
                // This error also requires LPC Slave Errors to be Cleared
                o_pnorResetLevel = RESET_SFCBUS_LPCSLAVE_ERRS;
                TRACFCOMP( g_trac_pnor, ERR_MRK"PnorDD::checkForSfcErrors> LBUS2OPB Data Parity Error: LPC Slave status reg: 0x%08llx, ResetLevel=%d",
                           lpc_slave_stat.data32, o_pnorResetLevel);

            }
            else if ( LBUS2OPB_MONITOR_ERR == lpc_slave_stat.lbus2opberr )
            {
                TRACFCOMP( g_trac_pnor, ERR_MRK"PnorDD::checkForSfcErrors> LBUS2OPB Monitor Error: LPC Slave status reg: 0x%08llx, ResetLevel=%d",
                           lpc_slave_stat.data32, o_pnorResetLevel);

            }

            else if ( LBUS2OPB_TIMEOUT_ERR == lpc_slave_stat.lbus2opberr )
            {
                TRACFCOMP( g_trac_pnor, ERR_MRK"PnorDD::checkForSfcErrors> LBUS2OPB Timeout Error: LPC Slave status reg: 0x%08llx, ResetLevel=%d",
                           lpc_slave_stat.data32, o_pnorResetLevel);

            }
            else
            {
                // Just in case, clear LPC Slave Errors
                o_pnorResetLevel = RESET_LPC_SLAVE_ERRS;
                TRACFCOMP( g_trac_pnor, ERR_MRK"PnorDD::checkForSfcErrors> LBUS2OPB UNKNOWN Error: LPC Slave status reg: 0x%08llx, ResetLevel=%d",
                           lpc_slave_stat.data32, o_pnorResetLevel);
            }

        }

        // Second Read SFC and check for error bits
        l_err = readRegSfc(SFC_CMD_SPACE,
                           SFC_REG_STATUS,
                           sfc_stat.data32);

        // If we can't read status register, exit out
        if( l_err ) { break; }

        TRACDCOMP( g_trac_pnor, INFO_MRK"PnorDD::checkForSfcErrors> SFC status reg(0x%X): 0x%08llx",
                   SFC_CMD_SPACE|SFC_REG_STATUS,sfc_stat.data32);

        // No resets needed for these errors
        if( 1 == sfc_stat.eccerrcntr )
        {
            errorFound = true;
            TRACFCOMP( g_trac_pnor, ERR_MRK"PnorDD::checkForSfcErrors> Threshold of SRAM ECC Errors Reached: SFC status reg: 0x%08llx, ResetLevel=%d",
                       sfc_stat.data32, o_pnorResetLevel);
        }

        if( 1 == sfc_stat.eccues )
        {
            errorFound = true;
            TRACFCOMP( g_trac_pnor, ERR_MRK"PnorDD::checkForSfcErrors> SRAM Command Uncorrectable ECC Error: SFC status reg: 0x%08llx, ResetLevel=%d",
                       sfc_stat.data32, o_pnorResetLevel);
        }

        if( 1 == sfc_stat.illegal )
        {
            errorFound = true;
            TRACFCOMP( g_trac_pnor, ERR_MRK"PnorDD::checkForSfcErrors> Previous Operation was Illegal: SFC status reg: 0x%08llx, ResetLevel=%d",
                       sfc_stat.data32, o_pnorResetLevel);
        }

        if( 1 == sfc_stat.eccerrcntn )
        {
            errorFound = true;
            TRACFCOMP( g_trac_pnor, ERR_MRK"PnorDD::checkForSfcErrors> Threshold for Flash ECC Errors Reached: SFC status reg: 0x%08llx, ResetLevel=%d",

                       sfc_stat.data32, o_pnorResetLevel);
        }

        if( 1 == sfc_stat.eccuen )
        {
            errorFound = true;
            TRACFCOMP( g_trac_pnor, ERR_MRK"PnorDD::checkForSfcErrors> Flash Command Uncorrectable ECC Error: SFC status reg: 0x%08llx, ResetLevel=%d",
                       sfc_stat.data32, o_pnorResetLevel);
        }

        if( 1 == sfc_stat.timeout )
        {
            errorFound = true;
            TRACFCOMP( g_trac_pnor, ERR_MRK"PnorDD::checkForSfcErrors> Timeout: SFC status reg: 0x%08llx, ResetLevel=%d",
                       sfc_stat.data32, o_pnorResetLevel);
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
            TRACFCOMP( g_trac_pnor, ERR_MRK"PnorDD::checkForSfcErrors> Deleting register read error. Returning error created for the found error");
            delete l_err;
        }


        /*@
         * @errortype
         * @moduleid     PNOR::MOD_PNORDD_CHECKFORSFCERRORS
         * @reasoncode   PNOR::RC_ERROR_IN_STATUS_REG
         * @userdata1[0:31]  SFC Status Register
         * @userdata1[32:63] LPC Slave Status Register
         * @userdata2    Reset Level
         * @devdesc      PnorDD::checkForSfcErrors> Error(s) found in SFC
         *               and/or LPC Slave Status Registers
         * @custdesc    A problem occurred while accessing the boot flash.
         */
        l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        PNOR::MOD_PNORDD_CHECKFORSFCERRORS,
                                        PNOR::RC_ERROR_IN_STATUS_REG,
                                        TWO_UINT32_TO_UINT64(
                                                   sfc_stat.data32,
                                                   lpc_slave_stat.data32),
                                        o_pnorResetLevel );

        // Limited in callout: no PNOR target, so calling out processor
        l_err->addHwCallout(
                        TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                        HWAS::SRCI_PRIORITY_HIGH,
                        HWAS::NO_DECONFIG,
                        HWAS::GARD_NULL );

        addFFDCRegisters(l_err);
        l_err->collectTrace(PNOR_COMP_NAME);
    }

    return l_err;

}

/**
 * @brief Check For Errors in OPB and LPCHC Status Registers
 */
errlHndl_t PnorDD::checkForOpbErrors( ResetLevels &o_pnorResetLevel )
{
    errlHndl_t l_err = NULL;
    bool errorFound = false;

    // Used to set Reset Levels, if necessary
    o_pnorResetLevel = RESET_CLEAR;

    // Default status values in case we fail in reading the registers
    OpbLpcmFirReg_t fir_reg;
    fir_reg.data64 = 0xDEADBEEFDEADBEEF;
    uint64_t fir_data = 0x0;

    // always read/write 64 bits to SCOM
    size_t scom_size = sizeof(uint64_t);

    do {

        //@todo (RTC:36950) - add non-master support
        TARGETING::Target* scom_target =
          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;

        // Read FIR Register
        l_err = deviceOp( DeviceFW::READ,
                          scom_target,
                          &(fir_data),
                          scom_size,
                          DEVICE_SCOM_ADDRESS(OPB_LPCM_FIR_REG) );
        if( l_err ) { break; }


        // Mask data to just the FIR bits we care about
        fir_reg.data64 = fir_data & OPB_LPCM_FIR_ERROR_MASK;

        // First look for SOFT errors
        if( 1 == fir_reg.rxits )
        {
            errorFound = true;
            o_pnorResetLevel = RESET_OPB_LPCHC_SOFT;
            TRACFCOMP( g_trac_pnor, ERR_MRK"PnorDD::checkForOpbErrors> Invalid Transfer Size: OPB_LPCM_FIR_REG=0x%.16X, ResetLevel=%d",
                       fir_reg.data64, o_pnorResetLevel);
        }

        if( 1 == fir_reg.rxicmd )
        {
            errorFound = true;
            o_pnorResetLevel = RESET_OPB_LPCHC_SOFT;
            TRACFCOMP( g_trac_pnor, ERR_MRK"PnorDD::checkForOpbErrors> Invalid Command: OPB_LPCM_FIR_REG=0x%.16X, ResetLevel=%d",
                       fir_reg.data64, o_pnorResetLevel);
        }

        if( 1 == fir_reg.rxiaa )
        {
            errorFound = true;
            o_pnorResetLevel = RESET_OPB_LPCHC_SOFT;
            TRACFCOMP( g_trac_pnor, ERR_MRK"PnorDD::checkForOpbErrors> Invalid Address Alignment: OPB_LPCM_FIR_REG=0x%.16X, ResetLevel=%d",
                       fir_reg.data64, o_pnorResetLevel);
        }

        if( 1 == fir_reg.rxcbpe )
        {
            errorFound = true;
            o_pnorResetLevel = RESET_OPB_LPCHC_SOFT;
            TRACFCOMP( g_trac_pnor, ERR_MRK"PnorDD::checkForOpbErrors> Command Buffer Parity Error: OPB_LPCM_FIR_REG=0x%.16X, ResetLevel=%d",
                       fir_reg.data64, o_pnorResetLevel);
        }

        if( 1 == fir_reg.rxdbpe )
        {
            errorFound = true;
            o_pnorResetLevel = RESET_OPB_LPCHC_SOFT;
            TRACFCOMP( g_trac_pnor, ERR_MRK"PnorDD::checkForOpbErrors> Data Buffer Parity Error: OPB_LPCM_FIR_REG=0x%.16X, ResetLevel=%d",
                       fir_reg.data64, o_pnorResetLevel);
        }


        // Now look for HARD errors that will override SOFT errors reset Level
        if( 1 == fir_reg.rxhopbe )
        {
            errorFound = true;
            o_pnorResetLevel = RESET_OPB_LPCHC_HARD;
            TRACFCOMP( g_trac_pnor, ERR_MRK"PnorDD::checkForOpbErrors> OPB Bus Error: OPB_LPCM_FIR_REG=0x%.16X, ResetLevel=%d",
                       fir_reg.data64, o_pnorResetLevel);
        }

        if( 1 == fir_reg.rxhopbt )
        {
            errorFound = true;
            o_pnorResetLevel = RESET_OPB_LPCHC_HARD;
            TRACFCOMP( g_trac_pnor, ERR_MRK"PnorDD::checkForOpbErrors> OPB Bus Timeout: OPB_LPCM_FIR_REG=0x%.16X, ResetLevel=%d",
                       fir_reg.data64, o_pnorResetLevel);
        }

        if( 1 == fir_reg.rxctgtel )
        {
            errorFound = true;
            o_pnorResetLevel = RESET_OPB_LPCHC_HARD;
            TRACFCOMP( g_trac_pnor, ERR_MRK"PnorDD::checkForOpbErrors> CI Load/CI Store/OPB Master Hang Timeout: OPB_LPCM_FIR_REG=0x%.16X, ResetLevel=%d",
                       fir_reg.data64, o_pnorResetLevel);
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
            TRACFCOMP( g_trac_pnor, ERR_MRK"PnorDD::checkForOpbErrors> Deleting register read error. Returning error created for the found error");
            delete l_err;
        }

        /*@
         * @errortype
         * @moduleid     PNOR::MOD_PNORDD_CHECKFOROPBERRORS
         * @reasoncode   PNOR::RC_ERROR_IN_STATUS_REG
         * @userdata1    OPB FIR Register Data
         * @userdata2    Reset Level
         * @devdesc      PnorDD::checkForOpbErrors> Error(s) found in OPB
         *               and/or LPCHC Status Register
         */
        l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        PNOR::MOD_PNORDD_CHECKFORSFCERRORS,
                                        PNOR::RC_ERROR_IN_STATUS_REG,
                                        fir_reg.data64,
                                        o_pnorResetLevel );

        // Limited in callout: no PNOR target, so calling out processor
        l_err->addHwCallout(
                        TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                        HWAS::SRCI_PRIORITY_HIGH,
                        HWAS::NO_DECONFIG,
                        HWAS::GARD_NULL );


        // Log FIR Register Data
        ERRORLOG::ErrlUserDetailsLogRegister
                  l_eud(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL);

        l_eud.addDataBuffer(&fir_data, scom_size,
                            DEVICE_SCOM_ADDRESS(OPB_LPCM_FIR_REG));

        l_eud.addToLog(l_err);

        addFFDCRegisters(l_err);
        l_err->collectTrace(PNOR_COMP_NAME);

    }

    return l_err;

}



/**
 * @brief Add Error Registers to an existing Error Log
 */
void PnorDD::addFFDCRegisters(errlHndl_t & io_errl)
{

    errlHndl_t tmp_err = NULL;
    uint32_t data32 = 0;
    uint64_t data64 = 0;
    size_t size64 = sizeof(data64);
    size_t size32 = sizeof(data32);

    // check iv_ffdc_active to avoid infinite loops
    if ( iv_ffdc_active == false )
    {
        iv_ffdc_active = true;

        TRACFCOMP( g_trac_pnor, ENTER_MRK"PnorDD::addFFDCRegisters> adding FFDC to Error Log EID=0x%X, PLID=0x%X",
                   io_errl->eid(), io_errl->plid() );

        ERRORLOG::ErrlUserDetailsLogRegister
                  l_eud(TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL);

        do {

            // Add ECCB Status Register
            TARGETING::Target* scom_target =
                TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;

            tmp_err = deviceOp( DeviceFW::READ,
                                scom_target,
                                &(data64),
                                size64,
                                DEVICE_SCOM_ADDRESS(ECCB_STAT_REG) );

            if( tmp_err )
            {
                delete tmp_err;
                TRACFCOMP( g_trac_pnor, "PnorDD::addFFDCRegisters> Fail reading ECCB_STAT_REG");
            }
            else
            {
                l_eud.addDataBuffer(&data64, size64,
                                    DEVICE_SCOM_ADDRESS(ECCB_STAT_REG));
            }

            // Add OPB Fir Register
            tmp_err = deviceOp( DeviceFW::READ,
                                scom_target,
                                &(data64),
                                size64,
                                DEVICE_SCOM_ADDRESS(OPB_LPCM_FIR_REG) );

            if( tmp_err )
            {
                delete tmp_err;
                TRACFCOMP( g_trac_pnor, "PnorDD::addFFDCRegisters> Fail reading OPB_LPCM_FIR_REG");
            }
            else
            {
                l_eud.addDataBuffer(&data64, size64,
                                    DEVICE_SCOM_ADDRESS(OPB_LPCM_FIR_REG));
            }

            // Add LPC Slave Status Register
            LpcSlaveStatReg_t lpc_slave_stat;

            tmp_err = readRegSfc(SFC_LPC_SPACE,
                                 LPC_SLAVE_REG_STATUS,
                                 lpc_slave_stat.data32);

            if ( tmp_err )
            {
                delete tmp_err;
                TRACFCOMP( g_trac_pnor, "PnorDD::addFFDCRegisters> Fail reading LPC Slave Status Register");
            }
            else
            {
                l_eud.addDataBuffer(&lpc_slave_stat.data32, size32,
                      DEVICE_SCOM_ADDRESS( LPCHC_FW_SPACE |
                                           LPC_SLAVE_REG_STATUS));
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
                tmp_err = readRegSfc( SFC_CMD_SPACE,
                                      sfc_regs[x],
                                      data32 );

                if( tmp_err )
                {
                    delete tmp_err;
                }
                else
                {
                    l_eud.addDataBuffer(&data32, size32,
                          DEVICE_SCOM_ADDRESS(LPC_SFC_CMDREG_OFFSET
                                              | sfc_regs[x]));
                }
            }

        }while(0);

        l_eud.addToLog(io_errl);

        TRACFCOMP( g_trac_pnor, EXIT_MRK"PnorDD::addFFDCRegisters> Information added to error log");

        // reset FFDC active flag
        iv_ffdc_active = false;
    }

    return;
}


/**
 * @brief Check flag status bit on Micron NOR chips
 *        The current version of Micron parts require the Flag
 *        Status register be read after a write or erase operation,
 *        otherwise all future operations won't work..
 */
errlHndl_t PnorDD::micronFlagStatus(uint64_t i_pollTime)
{
    errlHndl_t l_err = NULL;
    TRACDCOMP( g_trac_pnor, "PnorDD::micronFlagStatus> i_pollTime=0x%.8x",
               i_pollTime );

    do {

        //Configure Get "Chip ID" command in SFC to check special
        //Micron 'flag status' register
        SfcCustomReg_t readflag_cmd;
        readflag_cmd.data32 = 0;
        readflag_cmd.opcode = SPI_MICRON_FLAG_STAT;
        readflag_cmd.read = 1;
        readflag_cmd.length = 1;
        l_err = writeRegSfc(SFC_CMD_SPACE,
                            SFC_REG_CHIPIDCONF,
                            readflag_cmd.data32);
        if(l_err) { break; }


        //Check flag status bit.
        uint32_t opStatus = 0;
        uint64_t poll_time = 0;
        uint64_t loop = 0;
        while( poll_time < i_pollTime )
        {
            //Issue Get Chip ID command (reading flag status)
            SfcCmdReg_t sfc_cmd;
            sfc_cmd.opcode = SFC_OP_CHIPID;
            sfc_cmd.length = 0;

            l_err = writeRegSfc(SFC_CMD_SPACE,
                                SFC_REG_CMD,
                                sfc_cmd.data32);
            if(l_err) { break; }

            //Poll for complete status
            l_err = pollSfcOpComplete();
            if(l_err) { break; }

            //Read the Status from the Command Buffer
            l_err = readRegSfc(SFC_CMDBUF_SPACE,
                               0, //Offset into CMD BUFF space in bytes
                               opStatus);
            if(l_err) { break; }

            //check for complete or error
            // bit 0 = ready, bit 2=erase fail, bit 3=Program (Write) failure
            if( (opStatus & 0xB0000000))
            {
                break;
            }

            // want to start out incrementing by small numbers then get bigger
            //  to avoid a really tight loop in an error case so we'll increase
            //  the wait each time through
            //TODO tmp remove for VPO, need better polling strategy -- RTC43738
            //nanosleep( 0, SFC_POLL_INCR_NS*(++loop) );
            ++loop;
            poll_time += SFC_POLL_INCR_NS*loop;
        }
        if( l_err ) { break; }

        TRACDCOMP(g_trac_pnor,
                  "PnorDD::micronFlagStatus> (0x%.8X)",
                  opStatus);

        // check for ready and no errors
        // bit 0 = ready, bit 2=erase fail, bit 3=Program (Write) failure
        if( (opStatus & 0xB0000000) != 0x80000000)
        {
            TRACFCOMP(g_trac_pnor,
                      "PnorDD::micronFlagStatus> Error or timeout from Micron Flag Status Register (0x%.8X)",
                      opStatus);

            //Read SFDP
            uint32_t outdata[4];
            SfcCustomReg_t new_cmd;
            new_cmd.data32 = 0;
            new_cmd.opcode = SPI_MICRON_READ_SFDP;
            new_cmd.read = 1;
            new_cmd.needaddr = 1;
            new_cmd.clocks = 8;
            new_cmd.length = 16;
            l_err = readRegFlash( new_cmd,
                                  outdata,
                                  0 );
            if(l_err) { break; }

            //Loop around and grab all 16 bytes
            for( size_t x=0; x<4; x++ )
            {
                TRACFCOMP( g_trac_pnor, "SFDP[%d]=%.8X", x, outdata[x] );
            }

            /*@
             * @errortype
             * @moduleid     PNOR::MOD_PNORDD_MICRONFLAGSTATUS
             * @reasoncode   PNOR::RC_MICRON_INCOMPLETE
             * @userdata1[0:31]   NOR Flash Chip ID
             * @userdata1[32:63]  Total poll time (ns)
             * @userdata2[0:31]   Micron Flag status register
             * @devdesc      PnorDD::micronFlagStatus> Error or timeout from
             *               Micron Flag Status Register
             * @custdesc    A problem occurred while accessing the boot flash.
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            PNOR::MOD_PNORDD_MICRONFLAGSTATUS,
                                            PNOR::RC_MICRON_INCOMPLETE,
                                            TWO_UINT32_TO_UINT64(cv_nor_chipid,
                                                                 poll_time),
                                            TWO_UINT32_TO_UINT64(opStatus,0));

            // Limited in callout: no PNOR target, so calling out processor
            l_err->addHwCallout(
                            TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                            HWAS::SRCI_PRIORITY_HIGH,
                            HWAS::NO_DECONFIG,
                            HWAS::GARD_NULL );

            addFFDCRegisters(l_err);

            //Erase & Program error bits are sticky, so they need to be cleared.

            //Configure Get "Chip ID" command in SFC to clear special
            //Micron 'flag status' register. remaining bits are all zero
            //  since we just need to issue the SPI command.
            uint32_t confData = SPI_MICRON_CLRFLAG_STAT << 24;
            TRACDCOMP( g_trac_pnor, "PnorDD::micronFlagStatus> confData=0x%.8x",
                       confData );
            errlHndl_t tmp_err = NULL;
            tmp_err = writeRegSfc(SFC_CMD_SPACE,
                                  SFC_REG_CHIPIDCONF,
                                  confData);
            if(tmp_err)
            {
                //commit this error and return the original
                tmp_err->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                tmp_err->plid(l_err->plid());
                ERRORLOG::errlCommit(tmp_err,PNOR_COMP_ID);
            }

            //Issue Get Chip ID command (clearing flag status)
            SfcCmdReg_t sfc_cmd;
            sfc_cmd.opcode = SFC_OP_CHIPID;
            sfc_cmd.length = 0;
            tmp_err = writeRegSfc(SFC_CMD_SPACE,
                                  SFC_REG_CMD,
                                  sfc_cmd.data32);
            if(tmp_err)
            {
                //commit this error and return the original
                tmp_err->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                tmp_err->plid(l_err->plid());
                ERRORLOG::errlCommit(tmp_err,PNOR_COMP_ID);
            }

            //Poll for complete status
            tmp_err = pollSfcOpComplete();
            if(tmp_err)
            {
                delete tmp_err;
            }

            l_err->collectTrace(PNOR_COMP_NAME);
            l_err->collectTrace(XSCOM_COMP_NAME);

            break;
        }


    }while(0);

    return l_err;

}

/**
 * @brief Read the NOR FLash ChipID
 */
errlHndl_t PnorDD::getNORChipId(uint32_t& o_chipId,
                                uint32_t i_spiOpcode)
{
    errlHndl_t l_err = NULL;
    errlHndl_t original_err = NULL;
    uint8_t retry = 0;

    TRACFCOMP( g_trac_pnor, "PnorDD::getNORChipId> i_spiOpcode=0x%.8x",
               i_spiOpcode );


    // reset class variable since we're starting a new operation
    iv_error_recovery_failed = false;

    /***********************************************************/
    /* This do-while loop supports retries                     */
    /***********************************************************/
    do {

        // group this block together with do-while
        do{
            //Configure Get Chip ID opcode
            uint32_t confData = i_spiOpcode << 24;
            confData |= 0x00800003;  // 8-> read, 3->3 bytes
            TRACDCOMP( g_trac_pnor, "PnorDD::getNORChipId> confData=0x%.8x",
                       confData );
            l_err = writeRegSfc(SFC_CMD_SPACE,
                                SFC_REG_CHIPIDCONF,
                                confData);
            if(l_err) { break; }

            //Issue Get Chip ID command
            SfcCmdReg_t sfc_cmd;
            sfc_cmd.opcode = SFC_OP_CHIPID;
            sfc_cmd.length = 0;

            l_err = writeRegSfc(SFC_CMD_SPACE,
                                SFC_REG_CMD,
                                sfc_cmd.data32);
            if(l_err) { break; }

            //Poll for complete status
            l_err = pollSfcOpComplete();
            if(l_err) { break; }

            //Read the ChipID from the Command Buffer
            l_err = readRegSfc(SFC_CMDBUF_SPACE,
                               0, //Offset into CMD BUFF space in bytes
                               o_chipId);
            if(l_err) { break; }

            // Only look at a portion of the data that is returned
            o_chipId &= ID_MASK;

            //Some micron chips require a special workaround required
            //so need to set a flag for later use
            //We can't read all 6 bytes above because not all MFG
            //support that operation.
            if( o_chipId == MICRON_NOR_ID )
            {
                // Assume all Micron chips have this bug
                cv_hw_workaround |= HWWK_MICRON_EXT_READ;

                uint32_t outdata[4];

                //Change ChipID command to read back 6 bytes.
                SfcCustomReg_t new_cmd;
                new_cmd.opcode = SPI_GET_CHIPID_OP;
                new_cmd.read = 1;
                new_cmd.length = 6;
                l_err = readRegFlash( new_cmd,
                                      outdata );
                if(l_err) { break; }

                //If bit 1 is set in 2nd word of cmd buffer data, then
                //We must do the workaround.
                //Ex: CCCCCCLL 40000000
                //    CCCCCC -> Industry Standard Chip ID
                //    LL -> Length of Micron extended data
                //    4 -> Bit to indicate we must do erase/write workaround
                TRACFCOMP( g_trac_pnor, "PnorDD::getNORChipId> ExtId = %.8X %.8X", outdata[0], outdata[1] );
                if((outdata[1] & 0x40000000) == 0x00000000)
                {
                    TRACFCOMP( g_trac_pnor,"PnorDD::getNORChipId> Setting Micron workaround flag");
                    //Set Micron workaround flag
                    cv_hw_workaround |= HWWK_MICRON_WRT_ERASE;
                }


                //Read SFDP for FFDC
                new_cmd.data32 = 0;
                new_cmd.opcode = SPI_MICRON_READ_SFDP;
                new_cmd.read = 1;
                new_cmd.needaddr = 1;
                new_cmd.clocks = 8;
                new_cmd.length = 16;
                l_err = readRegFlash( new_cmd,
                                      outdata,
                                      0 );
                if(l_err) { break; }

                //Loop around and grab all 16 bytes
                for( size_t x=0; x<4; x++ )
                {
                    TRACFCOMP( g_trac_pnor, "SFDP[%d]=%.8X", x, outdata[x] );
                }

                //Prove this works
                l_err = micronFlagStatus();
                if(l_err) { delete l_err; }
            }

        }while(0); // group of commands

    // end of operation - check for retry
    } while ( shouldRetry(RETRY_getNORChipId, l_err, original_err, retry) );

    return l_err;
}


/**
 * @brief Load SFC command buffer with data from PNOR
 */
errlHndl_t PnorDD::loadSfcBuf(uint32_t i_addr,
                              size_t i_size)
{
    errlHndl_t l_err = NULL;
    TRACDCOMP( g_trac_pnor, "PnorDD::loadSfcBuf> i_addr=0x%.8x, i_size=0x%.8x",
               i_addr, i_size );

    do {
        //Write flash address to ADR reg
        l_err = writeRegSfc(SFC_CMD_SPACE,
                            SFC_REG_ADR,
                            i_addr);
        if(l_err) { break; }

        //Issue ReadRaw command with size to read
        SfcCmdReg_t sfc_cmd;
        sfc_cmd.opcode = SFC_OP_READRAW;
        sfc_cmd.length = i_size;

        l_err = writeRegSfc(SFC_CMD_SPACE,
                            SFC_REG_CMD,
                            sfc_cmd.data32);
        if(l_err) { break; }

        //Poll for complete status
        l_err = pollSfcOpComplete();
        if(l_err) { break; }

    }while(0);

    return l_err;

}

/**
 * @brief Flush SFC command buffer data to PNOR Flash
 */
errlHndl_t PnorDD::flushSfcBuf(uint32_t i_addr,
                          size_t i_size)
{
    errlHndl_t l_err = NULL;
    TRACDCOMP( g_trac_pnor,
               "PnorDD::flushSfcBuf> i_addr=0x%.8x, i_size=0x%.8x",
               i_addr, i_size );

    do {
        //Write flash address to ADR reg
        l_err = writeRegSfc(SFC_CMD_SPACE,
                            SFC_REG_ADR,
                            i_addr);
        if(l_err) { break; }

        //Issue WriteRaw command + size to write
        SfcCmdReg_t sfc_cmd;
        sfc_cmd.opcode = SFC_OP_WRITERAW;
        sfc_cmd.length = i_size;

        l_err = writeRegSfc(SFC_CMD_SPACE,
                            SFC_REG_CMD,
                            sfc_cmd.data32);
        if(l_err) { break; }

        //Poll for complete status
        l_err = pollSfcOpComplete();
        if(l_err) { break; }

        //check for special Micron Flag Status reg
        if(cv_hw_workaround & HWWK_MICRON_WRT_ERASE)
        {
            l_err = micronFlagStatus();
            if(l_err) { break; }
        }

    }while(0);

    return l_err;

}

/**
 * @brief Perform command based read of PNOR, maximizing use of
 *        SFC Command buffer..
 */
errlHndl_t PnorDD::bufferedSfcRead(uint32_t i_addr,
                                     size_t i_size,
                                     void* o_data)
{
    TRACDCOMP( g_trac_pnor, "PnorDD::bufferedSfcRead> i_addr=0x%.8x, i_size=0x%.8x",
               i_addr, i_size );

    errlHndl_t l_err = NULL;
    errlHndl_t original_err = NULL;
    uint8_t retry = 0;

    // reset class variable since we're starting a new operation
    iv_error_recovery_failed = false;

    /***********************************************************/
    /* This do-while loop supports retries                     */
    /***********************************************************/
    do {

        switch(iv_mode)
        {
        case MODEL_REAL_MMIO:
                {
                //Read directly from MMIO space
                uint32_t* word_ptr = static_cast<uint32_t*>(o_data);
                uint32_t word_size = i_size/4;
                for( uint32_t words_read = 0;
                     words_read < word_size;
                     words_read ++ )
                {
                    l_err = readRegSfc(
                                SFC_MMIO_SPACE,
                                i_addr+words_read*4, //MMIO Address offset
                                word_ptr[words_read]);
                    if( l_err ) {  break; }
                }

                break;
            }
        case MODEL_REAL_CMD:
            {

                // Command based reads are buffered 256 bytes at a time.
                uint32_t chunk_size = 0;
                uint64_t addr = i_addr;
                uint64_t end_addr = i_addr + i_size;

                while(addr < end_addr)
                {
                    chunk_size = SFC_CMDBUF_SIZE;
                    if( (addr + SFC_CMDBUF_SIZE) > end_addr)
                    {
                        chunk_size = end_addr - addr;
                    }

                    //Read data via SFC CMD Buffer
                    l_err = loadSfcBuf(addr, chunk_size);
                    if(l_err) { break;}

                    //read SFC CMD Buffer via MMIO
                    l_err = readSfcBuffer(
                                chunk_size,
                                (void*)((uint64_t)o_data + (addr-i_addr)));
                    if(l_err) { break;}

                    addr += chunk_size;
                }
                break;
            }
        case MODEL_LPC_MEM:
            {
                read_fake_pnor( i_addr,
                                o_data,
                                i_size );
                break;
            }
        default:
            {
                TRACFCOMP(g_trac_pnor, ERR_MRK"PnorDD::bufferedSfcRead> Unsupported mode: iv_mode=0x%.16X, i_addr=0x%.8X. Calling doShutdown(PNOR::RC_UNSUPPORTED_MODE)",
                          iv_mode, i_addr);

                //Can't function without PNOR, initiate shutdown.
                INITSERVICE::doShutdown( PNOR::RC_UNSUPPORTED_MODE);
                break;
            }
        } //end switch

    // end of operation - check for retry
    } while ( shouldRetry(RETRY_bufferedSfcRead, l_err, original_err, retry) );

    return l_err;

}


/**
 * @brief Perform command based write of PNOR, maximizing use of
 *        SFC Command buffer..
 */
errlHndl_t PnorDD::bufferedSfcWrite(uint32_t i_addr,
                                     size_t i_size,
                                     void* i_data)
{
    TRACDCOMP( g_trac_pnor, "PnorDD::bufferedSfcWrite> i_addr=0x%.8x, i_size=0x%.8x",
               i_addr, i_size );

    errlHndl_t l_err = NULL;
    errlHndl_t original_err = NULL;
    uint8_t retry = 0;

    // reset class variable since we're starting a new operation
    iv_error_recovery_failed = false;

    /***********************************************************/
    /* This do-while loop supports retries                     */
    /***********************************************************/
    do {
        switch(iv_mode)
        {
        case MODEL_REAL_CMD:
        case MODEL_REAL_MMIO:
            {
                // Note: MODEL_REAL_CMD or MODEL_REAL_MMIO both used command
                //     based writes, thus the common code path here

                // Command based reads are buffered 256 bytes at a time.
                uint32_t chunk_size = 0;
                uint64_t addr = i_addr;
                uint64_t end_addr = i_addr + i_size;

                while(addr < end_addr)
                {
                    chunk_size = SFC_CMDBUF_SIZE;
                    if( (addr + SFC_CMDBUF_SIZE) > end_addr)
                    {
                        chunk_size = end_addr - addr;
                    }

                    //write data to SFC CMD Buffer via MMIO
                    l_err = writeSfcBuffer(chunk_size,
                                 (void*)((uint64_t)i_data + (addr-i_addr)));
                    if(l_err) { break;}

                    //Fetch bits into SFC CMD Buffer
                    l_err = flushSfcBuf(addr, chunk_size);
                    if(l_err) { break;}

                    addr += chunk_size;
                }
                break;
            }
        case MODEL_LPC_MEM:
            {
                write_fake_pnor( i_addr,
                                 i_data,
                                 i_size );
                break;
            }
        default:
            {
                TRACFCOMP(g_trac_pnor, ERR_MRK"PnorDD::bufferedSfcWrite> Unsupported mode: iv_mode=0x%.16X, i_addr=0x%.8X. Calling doShutdown(PNOR::RC_UNSUPPORTED_MODE)",
                          iv_mode, i_addr);

                //Can't function without PNOR, initiate shutdown.
                INITSERVICE::doShutdown( PNOR::RC_UNSUPPORTED_MODE);
            }
        } // end of switch statement

    // end of operation - check for retry
    } while ( shouldRetry(RETRY_bufferedSfcWrite, l_err, original_err, retry) );

    return l_err;
}


/**
 * @brief Read data in SFC Command buffer and put into buffer
 */
errlHndl_t PnorDD::readSfcBuffer(size_t i_size,
                                 void* o_data)
{
    errlHndl_t l_err = NULL;
    TRACDCOMP( g_trac_pnor, "PnorDD::readSfcBuffer> i_size=0x%.8x",
               i_size );

    // SFC Command Buffer is accessed 32-bits at a time
    uint32_t* word_ptr = static_cast<uint32_t*>(o_data);
    uint32_t word_size = (ALIGN_4(i_size))/4;
    for( uint32_t words_read = 0;
         words_read < word_size;
         words_read ++ )
    {
        l_err = readRegSfc(SFC_CMDBUF_SPACE,
                           words_read*4, //Offset into CMD BUFF space in bytes
                           word_ptr[words_read]);
        TRACDCOMP( g_trac_pnor, "PnorDD::readSfcBuffer: Read offset=0x%.8x, data_read=0x%.8x",
                   words_read*4, word_ptr[words_read] );

        if( l_err ) {  break; }
    }

    return l_err;
}

/**
 * @brief Write data to SFC Command buffer
 */
errlHndl_t PnorDD::writeSfcBuffer(size_t i_size,
                                 void* i_data)
{
    errlHndl_t l_err = NULL;
    TRACDCOMP( g_trac_pnor, "PnorDD::writeSfcBuffer> i_size=0x%.8x",
               i_size );

    // SFC Command Buffer is accessed 32-bits at a time
    uint32_t* word_ptr = static_cast<uint32_t*>(i_data);
    uint32_t word_size = i_size/4;
    for( uint32_t words_read = 0;
         words_read < word_size;
         words_read ++ )
    {
        l_err = writeRegSfc(SFC_CMDBUF_SPACE,
                           words_read*4, //Offset into CMD BUFF space in bytes
                           word_ptr[words_read]);
        if( l_err ) { break; }
    }

    return l_err;
}

/**
 * @brief Read an address from LPC space
 */
errlHndl_t PnorDD::readLPC(uint32_t i_addr,
                           uint32_t& o_data)
{
    errlHndl_t l_err = NULL;
    ResetLevels pnorResetLevel = RESET_CLEAR;

    do {

        //@todo (RTC:36950) - add non-master support
        TARGETING::Target* scom_target =
          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;

        // always read/write 64 bits to SCOM
        size_t scom_size = sizeof(uint64_t);

        // write command register with LPC address to read
        EccbControlReg_t eccb_cmd;
        eccb_cmd.read_op = 1;
        eccb_cmd.address = i_addr;
        l_err = deviceOp( DeviceFW::WRITE,
                          scom_target,
                          &(eccb_cmd.data64),
                          scom_size,
                          DEVICE_SCOM_ADDRESS(ECCB_CTL_REG) );
        if( l_err ) { break; }

        // poll for complete and get the data back
        EccbStatusReg_t eccb_stat;
        uint64_t poll_time = 0;
        uint64_t loop = 0;

        while( poll_time < ECCB_POLL_TIME_NS )
        {
            l_err = deviceOp( DeviceFW::READ,
                              scom_target,
                              &(eccb_stat.data64),
                              scom_size,
                              DEVICE_SCOM_ADDRESS(ECCB_STAT_REG) );
            if( l_err ) { break; }

            if( eccb_stat.op_done == 1 )
            {
                break;
            }

            // want to start out incrementing by small numbers then get bigger
            //  to avoid a really tight loop in an error case so we'll increase
            //  the wait each time through
            //TODO tmp remove for VPO, need better polling strategy -- RTC43738
            //nanosleep( 0, ECCB_POLL_INCR_NS*(++loop) );
            poll_time += ECCB_POLL_INCR_NS*++loop;
        }
        if( l_err ) { break; }

        // check for errors or timeout at ECCB level
        if( (eccb_stat.data64 & ECCB_LPC_STAT_REG_ERROR_MASK)
            || (eccb_stat.op_done == 0) )
        {
            TRACFCOMP(g_trac_pnor, "PnorDD::readLPC> Error or timeout from LPC Status Register : i_addr=0x%.8X, status=0x%.16X", i_addr, eccb_stat.data64 );

            /*@
             * @errortype
             * @moduleid     PNOR::MOD_PNORDD_READLPC
             * @reasoncode   PNOR::RC_LPC_ERROR
             * @userdata1[0:31]   LPC Address
             * @userdata1[32:63]  Total poll time (ns)
             * @userdata2    ECCB Status Register
             * @devdesc      PnorDD::readLPC> Error or timeout from
             *               LPC Status Register
             * @custdesc    A problem occurred while accessing the boot flash.
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            PNOR::MOD_PNORDD_READLPC,
                                            PNOR::RC_LPC_ERROR,
                                            TWO_UINT32_TO_UINT64(i_addr,poll_time),
                                            eccb_stat.data64);

            // Limited in callout: no PNOR target, so calling out processor
            l_err->addHwCallout(
                            TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                            HWAS::SRCI_PRIORITY_HIGH,
                            HWAS::NO_DECONFIG,
                            HWAS::GARD_NULL );

            addFFDCRegisters(l_err);
            l_err->collectTrace(PNOR_COMP_NAME);
            l_err->collectTrace(XSCOM_COMP_NAME);

            // Reset ECCB - handled below
            pnorResetLevel = RESET_ECCB;

            break;
        }

        // check for errors at OPB level
        l_err = checkForOpbErrors( pnorResetLevel );

        if( l_err ) { break; }

        // copy data out to caller's buffer
        o_data = eccb_stat.read_data;

    } while(0);


    // If we have an error that requires a reset, do that here
    if ( l_err && ( pnorResetLevel != RESET_CLEAR ) )
    {
        errlHndl_t tmp_err = NULL;
        tmp_err = resetPnor(pnorResetLevel);

        if ( tmp_err )
        {
            // Commit reset error since we have original error l_err
            TRACFCOMP(g_trac_pnor, "PnorDD::readLPC Error from resetPnor() after previous error eid=0x%X. Committing resetPnor() error log eid=0x%X.",
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
 * @brief Write an address from LPC space
 */
errlHndl_t PnorDD::writeLPC(uint32_t i_addr,
                            uint32_t i_data)
{
    errlHndl_t l_err = NULL;
    ResetLevels pnorResetLevel = RESET_CLEAR;


    TRACDCOMP(g_trac_pnor, "writeLPC> %.8X = %.8X", i_addr, i_data );

    do {

        //@todo (RTC:36950) - add non-master support
        TARGETING::Target* scom_target =
          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;

        // always read/write 64 bits to SCOM
        size_t scom_size = sizeof(uint64_t);

        // write data register
        TRACDCOMP(g_trac_pnor, "writeLPC> Write ECCB data register");

        uint64_t eccb_data = static_cast<uint64_t>(i_data);
        eccb_data = eccb_data << 32; //left-justify my data
        l_err = deviceOp( DeviceFW::WRITE,
                          scom_target,
                          &eccb_data,
                          scom_size,
                          DEVICE_SCOM_ADDRESS(ECCB_DATA_REG) );
        if( l_err ) { break; }

        // write command register with LPC address to write
        EccbControlReg_t eccb_cmd;
        eccb_cmd.read_op = 0;
        eccb_cmd.address = i_addr;
        TRACDCOMP(g_trac_pnor, "writeLPC> Write ECCB command register, cmd=0x%.16x", eccb_cmd.data64 );
        l_err = deviceOp( DeviceFW::WRITE,
                          scom_target,
                          &(eccb_cmd.data64),
                          scom_size,
                          DEVICE_SCOM_ADDRESS(ECCB_CTL_REG) );
        if( l_err ) { break; }


        // poll for complete
        EccbStatusReg_t eccb_stat;
        uint64_t poll_time = 0;
        uint64_t loop = 0;
        while( poll_time < ECCB_POLL_TIME_NS )
        {
            l_err = deviceOp( DeviceFW::READ,
                              scom_target,
                              &(eccb_stat.data64),
                              scom_size,
                              DEVICE_SCOM_ADDRESS(ECCB_STAT_REG) );
            TRACDCOMP(g_trac_pnor, "writeLPC> Poll on ECCB Status, poll_time=0x%.16x, stat=0x%.16x", eccb_stat.data64,  poll_time );

            if( l_err ) { break; }

            if( eccb_stat.op_done == 1 )
            {
                break;
            }

            // want to start out incrementing by small numbers then get bigger
            //  to avoid a really tight loop in an error case so we'll increase
            //  the wait each time through
            //TODO tmp remove for VPO, need better polling strategy -- RTC43738
            //nanosleep( 0, ECCB_POLL_INCR_NS*(++loop) );
            poll_time += ECCB_POLL_INCR_NS*++loop;
        }
        if( l_err ) { break; }

        // check for errors at ECCB level
        if( (eccb_stat.data64 & ECCB_LPC_STAT_REG_ERROR_MASK)
            || (eccb_stat.op_done == 0) )
        {
            TRACFCOMP(g_trac_pnor, "PnorDD::writeLPC> Error or timeout from LPC Status Register : i_addr=0x%.8X, status=0x%.16X", i_addr, eccb_stat.data64 );

            /*@
             * @errortype
             * @moduleid     PNOR::MOD_PNORDD_WRITELPC
             * @reasoncode   PNOR::RC_LPC_ERROR
             * @userdata1    LPC Address
             * @userdata2    ECCB Status Register
             * @devdesc      PnorDD::writeLPC> Error or timeout from
             *               LPC Status Register
             * @custdesc    A problem occurred while accessing the boot flash.
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            PNOR::MOD_PNORDD_WRITELPC,
                                            PNOR::RC_LPC_ERROR,
                                            TWO_UINT32_TO_UINT64(0,i_addr),
                                            eccb_stat.data64);
            // Limited in callout: no PNOR target, so calling out processor
            l_err->addHwCallout(
                            TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                            HWAS::SRCI_PRIORITY_HIGH,
                            HWAS::NO_DECONFIG,
                            HWAS::GARD_NULL );

            addFFDCRegisters(l_err);
            l_err->collectTrace(PNOR_COMP_NAME);
            l_err->collectTrace(XSCOM_COMP_NAME);

            // Reset ECCB - handled below
            pnorResetLevel = RESET_ECCB;

            break;
        }

        // check for errors at OPB level
        l_err = checkForOpbErrors( pnorResetLevel );

        if( l_err ) { break; }

    } while(0);

    // If we have an error that requires a reset, do that here
    if ( l_err && ( pnorResetLevel != RESET_CLEAR ) )
    {
        errlHndl_t tmp_err = NULL;
        tmp_err = resetPnor(pnorResetLevel);

        if ( tmp_err )
        {
            // Commit reset error since we have original error l_err
            TRACFCOMP(g_trac_pnor, "PnorDD::writeLPC Error from resetPnor() after previous error eid=0x%X. Committing resetPnor() error log eid=0x%X.",
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
 * @brief Compare the existing data in 1 erase block of the flash with
 *   the incoming data and write or erase as needed
 */
errlHndl_t PnorDD::compareAndWriteBlock(uint32_t i_blockStart,
                                        uint32_t i_writeStart,
                                        size_t i_bytesToWrite,
                                        void* i_data)
{
    TRACDCOMP(g_trac_pnor,">>compareAndWriteBlock(0x%.8X,0x%.8X,0x%.8X)", i_blockStart, i_writeStart, i_bytesToWrite);
    errlHndl_t l_err = NULL;
    uint8_t* read_data = NULL;

    do {

        // remember any data we read so we don't have to reread it later
        read_data = new uint8_t[iv_erasesize_bytes];

        // remember if we need to erase the block or not
        bool need_erase = false;
        bool need_write = false;

        //STEP 1: Read data in PNOR for compares (only read section we want to write)
        //read_start needs to be uint32* for bitwise word compares later
        uint32_t* read_start = (uint32_t*)(read_data + i_writeStart-i_blockStart);
        l_err =  bufferedSfcRead(i_writeStart,
                                 i_bytesToWrite,
                                 (void*) read_start);
        if( l_err ) { break; }

        //STEP 2: walk through the write data to see if we need to do an erase
        const uint32_t wordsToWrite = i_bytesToWrite/4;
        uint32_t* i_dataWord = (uint32_t*) i_data;

        for(uint32_t cword = 0; cword < wordsToWrite; cword++)
        {
            // look for any bits being changed (using XOR)
            if(read_start[cword] ^ i_dataWord[cword] )
            {
                need_write = true;

                //Can only write zeros to NOR, see if any bits changed from 0->1
                if( (~(read_start[cword])) & (i_dataWord[cword]) )
                {
                    need_erase = true;

                    // skip comparing the rest of the block,
                    //   just start writing it
                    break;
                }
            }
        }

        if(need_write == false)
        {
            //No write actually needed, break out here
            TRACFCOMP(g_trac_pnor,"compareAndWriteBlock>  NO Write Needed! Exiting FUnction");
            break;
        }


        //STEP 3: If the need to erase was detected, read out the rest of the Erase block
        if(need_erase)
        {
            TRACFCOMP(g_trac_pnor,"compareAndWriteBlock> Need to perform Erase");
            //Get data before write section
            if(i_writeStart > i_blockStart)
            {
                TRACDCOMP(g_trac_pnor,"compareAndWriteBlock> Reading beginning data i_blockStart=0x%.8x, readLen=0x%.8x",
                          i_blockStart, i_writeStart-i_blockStart);
                l_err = bufferedSfcRead(i_blockStart,
                                        i_writeStart-i_blockStart,
                                        read_data);
                if( l_err ) { break; }
            }

            //Get data after write section
            if((i_writeStart+i_bytesToWrite) < (i_blockStart + iv_erasesize_bytes))
            {
                uint32_t tail_length = i_blockStart + iv_erasesize_bytes - (i_writeStart+i_bytesToWrite);
                uint8_t* tail_buffer = read_data + i_writeStart-i_blockStart + i_bytesToWrite;

                TRACDCOMP(g_trac_pnor,"compareAndWriteBlock> Reading tail data. addr=0x%.8x, tail_length=0x%.8x",
                          i_writeStart+i_bytesToWrite, tail_length);
                l_err =  bufferedSfcRead(i_writeStart+i_bytesToWrite,
                                           tail_length,
                                           tail_buffer);
                if( l_err ) { break; }
            }

            // erase the flash
            TRACDCOMP(g_trac_pnor,"compareAndWriteBlock> Calling eraseFlash:. i_blockStart=0x%.8x", i_blockStart);
            l_err = eraseFlash( i_blockStart );
            if( l_err ) { break; }


            //STEP 4: Write the data back out -
            //        need to write everything since we erased the block
            //        re-write data before new data to write
            if(i_writeStart > i_blockStart)
            {
                TRACDCOMP(g_trac_pnor,"compareAndWriteBlock> Writing beginning data i_blockStart=0x%.8x, readLen=0x%.8x",
                          i_blockStart, i_writeStart-i_blockStart);
                l_err = bufferedSfcWrite(i_blockStart,
                                         i_writeStart-i_blockStart,
                                         read_data);
                if( l_err ) { break; }
            }

            //Write data after new data to write
            if((i_writeStart+i_bytesToWrite) < (i_blockStart + iv_erasesize_bytes))
            {
                uint32_t tail_length = i_blockStart + iv_erasesize_bytes - (i_writeStart+i_bytesToWrite);
                uint8_t* tail_buffer = read_data + i_writeStart-i_blockStart + i_bytesToWrite;

                TRACDCOMP(g_trac_pnor,"compareAndWriteBlock> Writing tail data. addr=0x%.8x, tail_length=0x%.8x",
                          i_writeStart+i_bytesToWrite, tail_length);
                l_err =  bufferedSfcWrite(i_writeStart+i_bytesToWrite,
                                          tail_length,
                                          tail_buffer);
                if( l_err ) { break; }
            }

            //Write the new data - always do this
            l_err =  bufferedSfcWrite(i_writeStart,
                                      i_bytesToWrite,
                                      i_data);
            if( l_err ) { break; }
        }
        else //
        {
            //STEP 4 ALT: No erase needed, only write the parts that changed.
            TRACFCOMP(g_trac_pnor,"compareAndWriteBlock> No erase, just writing");

            for(uint32_t cword = 0; cword < wordsToWrite; cword++)
            {
                // look for any bits being changed (using XOR)
                if(read_start[cword] ^ i_dataWord[cword] )
                {
                    //Write the new data - always do this
                    l_err =  bufferedSfcWrite(i_writeStart + (cword*4),
                                              4,
                                              &i_dataWord[cword]);
                    if( l_err ) { break; }
                }
                if( l_err ) { break; }

            }
        }

    } while(0);

    if( read_data )
    {
        delete[] read_data;
    }

    TRACFCOMP(g_trac_pnor,"<<compareAndWriteBlock() Exit");


    return l_err;
}

/**
 * @brief Erase a block of flash
 */
errlHndl_t PnorDD::eraseFlash(uint32_t i_address)
{
    TRACFCOMP(g_trac_pnor, ">>PnorDD::eraseFlash> Block 0x%.8X", i_address );

    errlHndl_t l_err = NULL;
    errlHndl_t original_err = NULL;
    uint8_t retry = 0;

    do {
        if( findEraseBlock(i_address) != i_address )
        {
            /*@
             * @errortype
             * @moduleid     PNOR::MOD_PNORDD_ERASEFLASH
             * @reasoncode   PNOR::RC_LPC_ERROR
             * @userdata1    LPC Address
             * @userdata2    Nearest Erase Boundary
             * @devdesc      PnorDD::eraseFlash> Address not on erase boundary
             * @custdesc    A problem occurred while accessing the boot flash.
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            PNOR::MOD_PNORDD_ERASEFLASH,
                                            PNOR::RC_LPC_ERROR,
                                            TWO_UINT32_TO_UINT64(0,i_address),
                                            findEraseBlock(i_address),
                                            true /*Add HB SW Callout*/ );
            l_err->collectTrace(PNOR_COMP_NAME);
            break;
        }

        /***********************************************************/
        /* Attempt erase multiple times                            */
        /***********************************************************/
        // reset class variable since we're starting a new operation
        iv_error_recovery_failed = false;


        // This do-while loop supports retries
        do {

            for(uint32_t idx = 0; idx < ERASE_COUNT_MAX; idx++ )
            {
                if(iv_erases[idx].addr == i_address)
                {
                    iv_erases[idx].count++;
                    TRACFCOMP(g_trac_pnor,"PnorDD::eraseFlash> Block 0x%.8X has %d erasures",
                              i_address, iv_erases[idx].count );
                    break;

                }
                //iv_erases is init to all 0xff,
                //  so can use ~0 to check for an unused position
                else if(iv_erases[idx].addr == ~0u)
                {
                    iv_erases[idx].addr = i_address;
                    iv_erases[idx].count = 1;
                    TRACFCOMP(g_trac_pnor,"PnorDD::eraseFlash> Block 0x%.8X has %d erasures",
                              i_address, iv_erases[idx].count );
                    break;
                }
                else if( idx == (ERASE_COUNT_MAX - 1))
                {
                    TRACFCOMP(g_trac_pnor,"PnorDD::eraseFlash> Erase counter full!  Block 0x%.8X Erased",
                          i_address );
                    break;
                }
            }

            if( (MODEL_MEMCPY == iv_mode) ||  (MODEL_LPC_MEM == iv_mode))
            {
                erase_fake_pnor( i_address, iv_erasesize_bytes );
                break; //all done
            }

            else if(cv_nor_chipid != 0)
            {

                // group this block together with do-while
                do{
                    TRACDCOMP(g_trac_pnor, "PnorDD::eraseFlash> Erasing flash for cv_nor_chipid=0x%.8x, iv_mode=0x%.8x",
                              cv_nor_chipid, iv_mode);

                    //Write erase address to ADR reg
                    l_err = writeRegSfc(SFC_CMD_SPACE,
                                        SFC_REG_ADR,
                                        i_address);

                    if(l_err) { break; }

                    //Issue Erase command
                    SfcCmdReg_t sfc_cmd;
                    sfc_cmd.opcode = SFC_OP_ERASM;
                    sfc_cmd.length = 0;  //Not used for erase

                    l_err = writeRegSfc(SFC_CMD_SPACE,
                                        SFC_REG_CMD,
                                        sfc_cmd.data32);
                    if(l_err) { break; }

                    //Poll for complete status
                    l_err = pollSfcOpComplete();
                    if(l_err) { break; }

                    //check for special Micron Flag Status reg
                    if(cv_hw_workaround & HWWK_MICRON_WRT_ERASE)
                    {
                        l_err = micronFlagStatus();
                        if(l_err) { break; }
                    }

                }while(0); // group of commands

            }
            else
            {
                TRACFCOMP(g_trac_pnor,"PnorDD::eraseFlash> Erase not supported for cv_nor_chipid=%d",
                          cv_nor_chipid );

                /*@
                 * @errortype
                 * @moduleid     PNOR::MOD_PNORDD_ERASEFLASH
                 * @reasoncode   PNOR::RC_UNSUPPORTED_OPERATION
                 * @userdata1    NOR Chip ID
                 * @userdata2    LPC Address to erase
                 * @devdesc      PnorDD::eraseFlash> No support for MODEL_REAL
                 */
                l_err = new ERRORLOG::ErrlEntry(
                                      ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                      PNOR::MOD_PNORDD_ERASEFLASH,
                                      PNOR::RC_UNSUPPORTED_OPERATION,
                                      static_cast<uint64_t>(cv_nor_chipid),
                                      i_address,
                                      true /*Add HB SW Callout*/ );
                l_err->collectTrace(PNOR_COMP_NAME);

                // this error can't be fixed with a retry, so just break
                if(l_err) { break; }

            }

        // end of operation - check for retry
        } while ( shouldRetry(RETRY_eraseFlash, l_err, original_err, retry) );

        if(l_err) { break;}

    } while(0);

    return l_err;
}

/**
 * @brief Read a user-defined Flash Register
 */
errlHndl_t PnorDD::readRegFlash( SfcCustomReg_t i_cmd,
                                 uint32_t* o_data,
                                 uint32_t i_addr )
{
    errlHndl_t l_err = NULL;

    do
    {
        //Do a read of flash address zero to workaround
        // a micron bug with extended reads
        if( (HWWK_MICRON_EXT_READ & cv_hw_workaround)
            && (i_cmd.length > 4) )
        {
            l_err = loadSfcBuf( 0, 1 );
            if(l_err) { break; }
        }

        //Change ChipID command
        l_err = writeRegSfc(SFC_CMD_SPACE,
                            SFC_REG_CHIPIDCONF,
                            i_cmd.data32);
        if(l_err) { break; }

        //Setup the address (ADR) if needed
        if( i_cmd.needaddr )
        {
            l_err = writeRegSfc(SFC_CMD_SPACE,
                                SFC_REG_ADR,
                                i_addr);
            if(l_err) { break; }
        }

        //Issue (new) Get Chip ID command
        SfcCmdReg_t sfc_cmd;
        sfc_cmd.opcode = SFC_OP_CHIPID;
        sfc_cmd.length = i_cmd.length;
        l_err = writeRegSfc(SFC_CMD_SPACE,
                            SFC_REG_CMD,
                            sfc_cmd.data32);
        if(l_err) { break; }

        //Poll for complete status
        l_err = pollSfcOpComplete();
        if(l_err) { break; }

        //Go get the data
        l_err = readSfcBuffer( i_cmd.length,
                               o_data );
        if(l_err) { break; }

    } while(0);

    return l_err;
}


/*
 This code is used in the MODEL_MEMCPY and MODEL_LPC_MEM modes
*/
/**
 * @brief Write to fake PNOR
 */
void PnorDD::write_fake_pnor( uint64_t i_pnorAddr,
                              void* i_buffer,
                              size_t i_size )
{
    //create a pointer to the offset start.
    char * destPtr = (char *)(iv_fakeStart+i_pnorAddr);

    if( (i_pnorAddr+i_size) > iv_fakeSize )
    {
        TRACFCOMP(g_trac_pnor,
                  "PnorDD write_fake_pnor> Write goes past end of fake-PNOR, skipping write. i_pnorAddr=0x%X, i_size=0x%X",
                  i_pnorAddr, i_size );
    }
    else
    {
        //copy data from memory into the buffer.
        memcpy(destPtr, i_buffer, i_size);
    }
}

/**
 * @brief Read from fake PNOR
 */
void PnorDD::read_fake_pnor( uint64_t i_pnorAddr,
                             void* o_buffer,
                             size_t i_size )
{
    //create a pointer to the offset start.
    char * srcPtr = (char *)(iv_fakeStart+i_pnorAddr);

    if( (i_pnorAddr+i_size) > iv_fakeSize )
    {
        TRACFCOMP(g_trac_pnor,
                  "PnorDD read_fake_pnor> Read goes past end of fake-PNOR, skipping read. i_pnorAddr=0x%X, i_size=0x%X",
                  i_pnorAddr, i_size );
    }
    else
    {
        //copy data from memory into the buffer.
        memcpy(o_buffer, srcPtr, i_size);
    }

}

/**
 * @brief Erase chunk of fake PNOR
 */
void PnorDD::erase_fake_pnor( uint64_t i_pnorAddr,
                              size_t i_size )
{
    //create a pointer to the offset start.
    char * srcPtr = (char *)(iv_fakeStart+i_pnorAddr);

    if( (i_pnorAddr+i_size) > iv_fakeSize )
    {
        TRACFCOMP(g_trac_pnor,
                  "PnorDD erase_fake_pnor> Erase goes past end of fake-PNOR, skipping erase. i_pnorAddr=0x%X, i_size=0x%X",
                  i_pnorAddr, i_size );
    }
    else
    {
        //Zero out memory
        memset( srcPtr, 0, i_size );
    }
}



errlHndl_t PnorDD::resetPnor( ResetLevels i_pnorResetLevel )
{
    errlHndl_t l_err = NULL;

    // check iv_reset_active to avoid infinite loops
    // and don't reset if in the middle of FFDC collection
    if ( ( iv_reset_active == false ) &&
         ( iv_ffdc_active == false  ) )
    {
        iv_reset_active = true;

        TRACFCOMP(g_trac_pnor, "PnorDD::resetPnor> i_pnorResetLevel=0x%.8X", i_pnorResetLevel);

        do {

            // Setup common scom target
            //@todo (RTC:36950) - add non-master support
            TARGETING::Target* scom_target =
            TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;

            // always read/write 64 bits to SCOM
            uint64_t scom_data_64 = 0x0;
            size_t scom_size = sizeof(uint64_t);

            // 32 bits for address and data for LPC operations
            uint32_t lpc_addr=0;
            uint32_t lpc_data=0;


            // To Avoid Infinite Loop - skip recovery if it already failed
            if ( iv_error_recovery_failed == true )
            {
                TRACFCOMP(g_trac_pnor, "PnorDD::resetPnor> Recovery Previously Failed (%d).  Skipping reset to avoid infinite loop", iv_error_recovery_failed);
                break;
            }

            /***************************************/
            /* Handle the different reset levels   */
            /***************************************/
            switch(i_pnorResetLevel)
            {
            case RESET_CLEAR:
                {// Nothing to do here, so just break
                    break;
                }

            case RESET_ECCB:
                {
                    // Write Reset Register to reset FW Logic registers
                    TRACFCOMP(g_trac_pnor, "PnorDD::resetPnor> Writing ECCB_RESET_REG to reset ECCB FW Logic");
                    scom_data_64 = 0x0;
                    l_err = deviceOp( DeviceFW::WRITE,
                                      scom_target,
                                      &(scom_data_64),
                                      scom_size,
                                      DEVICE_SCOM_ADDRESS(ECCB_RESET_REG) );

                    break;
                }

            case RESET_OPB_LPCHC_SOFT:
                {
                    TRACFCOMP(g_trac_pnor, "PnorDD::resetPnor> Writing OPB_MASTER_LS_CONTROL_REG to disable then enable First Error Data Capture");

                    // First read OPB_MASTER_LS_CONTROL_REG
                    lpc_addr = OPB_MASTER_LS_CONTROL_REG;
                    lpc_data = 0x0;

                    l_err = readLPC(lpc_addr, lpc_data);

                    if (l_err) { break; }

                    // Disable 'First Error Data Capture' - set bit 29 to 0b1
                    lpc_data |= 0x00000004;

                    l_err = writeLPC(lpc_addr, lpc_data);

                    if (l_err) { break; }


                    // Enable 'First Error Data Capture' - set bit 29 to 0b0
                    // No wait-time needed
                    lpc_data &= 0xFFFFFFFB;

                    l_err = writeLPC(lpc_addr, lpc_data);

                    if (l_err) { break; }

                    // Clear FIR register
                    scom_data_64 = ~(OPB_LPCM_FIR_ERROR_MASK);
                    l_err = deviceOp(
                              DeviceFW::WRITE,
                              scom_target,
                              &(scom_data_64),
                              scom_size,
                              DEVICE_SCOM_ADDRESS(OPB_LPCM_FIR_WOX_AND_REG) );
                    break;
                }

            case RESET_OPB_LPCHC_HARD:
                {
                    TRACFCOMP(g_trac_pnor, "PnorDD::resetPnor> Writing LPCHC_RESET_REG to reset LPCHC Logic");
                    lpc_addr = LPCHC_RESET_REG;
                    lpc_data = 0x0;

                    l_err = writeLPC(lpc_addr, lpc_data);

                    // sleep 1ms for LPCHC to execute internal
                    // reset+init sequence
                    nanosleep( 0, NS_PER_MSEC );

                    if (l_err) { break; }

                    // Clear FIR register
                    scom_data_64 = ~(OPB_LPCM_FIR_ERROR_MASK);
                    l_err = deviceOp(
                              DeviceFW::WRITE,
                              scom_target,
                               &(scom_data_64),
                              scom_size,
                              DEVICE_SCOM_ADDRESS(OPB_LPCM_FIR_WOX_AND_REG) );

                    break;
                }

            case RESET_LPC_SLAVE:
                {
                    // @todo RTC 109999 - Skipping because SFC resets can
                    // cause problems on subsequent reads and writes
                    TRACFCOMP(g_trac_pnor, "PnorDD::resetPnor> Skipping RESET_LPC_SLAVE");

#if 0
                    TRACFCOMP(g_trac_pnor, "PnorDD::resetPnor> Writing bit0 of LPC_SLAVE_REG_RESET to reset LPC Slave Logic");
                    lpc_addr = LPC_SLAVE_REG_RESET;
                    lpc_data = 0x80000000;

                    l_err = writeLPC(lpc_addr, lpc_data);
#endif
                    break;
                }

            case RESET_LPC_SLAVE_ERRS:
                {
                    // @todo RTC 109999 - Skipping because SFC resets can
                    // cause problems on subsequent reads and writes
                    TRACFCOMP(g_trac_pnor, "PnorDD::resetPnor> Skipping RESET_LPC_SLAVE_ERRS");
#if 0
                    TRACFCOMP(g_trac_pnor, "PnorDD::resetPnor> Writing bit1 of LPC_SLAVE_REG_RESET to reset LPC Slave Errors");
                    lpc_addr = LPC_SLAVE_REG_RESET;
                    lpc_data = 0x40000000;

                    l_err = writeLPC(lpc_addr, lpc_data);
#endif
                    break;
                }


            case RESET_SFC_LOCAL_BUS:
                {
                    // @todo RTC 109999 - Skipping because SFC resets can
                    // cause problems on subsequent reads and writes
                    TRACFCOMP(g_trac_pnor, "PnorDD::resetPnor> Skipping RESET_SFC_LPC_LOCAL_BUS");
#if 0
                    TRACFCOMP(g_trac_pnor, "PnorDD::resetPnor> Writing bit2 of LPC_SLAVE_REG_RESET to reset Local SFC Bus. Requires PNOR reinitialization");
                    lpc_addr = LPC_SLAVE_REG_RESET;
                    lpc_data = 0x20000000;

                    l_err = writeLPC(lpc_addr, lpc_data);

                    if (l_err) { break; }

                    l_err = PnorDD::reinitializeSfc();
#endif
                    break;
                }

            case RESET_SFCBUS_LPCSLAVE_ERRS:
                {
                    // @todo RTC 109999 - Skipping because SFC resets can
                    // cause problems on subsequent reads and writes
                    TRACFCOMP(g_trac_pnor, "PnorDD::resetPnor> Skipping RESET_SFCBUS_LPCSLAVE_ERRS");
#if 0
                    // Must handle both errors
                    TRACFCOMP(g_trac_pnor, "PnorDD::resetPnor> Writing bits1,2 of LPC_SLAVE_REG_RESET to reset LPC Slave Errors and Local SFC Bus. Requires PNOR reinitialization");
                    lpc_addr = LPC_SLAVE_REG_RESET;
                    lpc_data = 0x60000000;

                    l_err = writeLPC(lpc_addr, lpc_data);

                    if (l_err) { break; }

                    l_err = PnorDD::reinitializeSfc();
#endif
                    break;
                }

            // else - unsupported reset level
            default:
                {

                    TRACFCOMP( g_trac_pnor, ERR_MRK"PnorDD::resetPnor> Unsupported Reset Level Passed In: 0x%X", i_pnorResetLevel);

                   /*@
                     * @errortype
                     * @moduleid     PNOR::MOD_PNORDD_RESETPNOR
                     * @reasoncode   PNOR::RC_UNSUPPORTED_OPERATION
                     * @userdata1    Unsupported Reset Level Parameter
                     * @userdata2    <unused>
                     * @devdesc      PnorDD::resetPnor> Unsupported Reset Level
                     *               requested
                     */
                    l_err = new ERRORLOG::ErrlEntry(
                                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            PNOR::MOD_PNORDD_RESETPNOR,
                                            PNOR::RC_UNSUPPORTED_OPERATION,
                                            i_pnorResetLevel,
                                            0,
                                            true /*SW error*/);

                    l_err->collectTrace(PNOR_COMP_NAME);
                    break;
                }
            }// end switch

            if ( l_err )
            {
                // Indicate that we weren't successful in resetting PNOR
                iv_error_recovery_failed = true;
                TRACFCOMP( g_trac_pnor,ERR_MRK"PnorDD::resetPnor>> Fail doing PNOR reset at level 0x%X (recovery count=%d): eid=0x%X", i_pnorResetLevel, iv_error_handled_count, l_err->eid());
            }
            else
            {
                // Successful, so increment recovery count
                iv_error_handled_count++;

                TRACFCOMP( g_trac_pnor,INFO_MRK"PnorDD::resetPnor>> Successful PNOR reset at level 0x%X (recovery count=%d)", i_pnorResetLevel, iv_error_handled_count);
            }


        } while(0);

        // reset RESET active flag
        iv_reset_active = false;
    }

    return l_err;
}



errlHndl_t PnorDD::reinitializeSfc( void )
{
    TRACFCOMP(g_trac_pnor, "PnorDD::reinitializeSfc>");

    errlHndl_t l_err = NULL;

    //Initial configuration settings for SFC:
    #define oadrnb_init 0x0C000000  //Set MMIO/Direct window to start at 64MB
    #define oadrns_init 0x0000000F  //Set the MMIO/Direct window size to 64MB
    #define adrcbf_init 0x00000000  //Set the flash index to 0
    #define adrcmf_init 0x0000000F  //Set the flash size to 64MB
    #define conf_init 0x00000002  //Disable Direct Access Cache

    do {

#ifdef PNORDD_FSPATTACHED

        TRACFCOMP( g_trac_pnor,  ERR_MRK"PnorDD::reinitializeSfc> Need to Re-Initialize SFC. Calling doShutdown(PNOR::RC_REINITIALIZE_SFC)");

        l_err = NULL; // to avoid compiler warnings

        //Shutdown if SFC needs to be re-initialized
        INITSERVICE::doShutdown( PNOR::RC_REINITIALIZE_SFC);

#else


        // Clear member variable in case we don't successfully
        // reinitialize PNOR
        cv_sfcInitDone = false;

        l_err = writeRegSfc(SFC_CMD_SPACE,
                            SFC_REG_OADRNB,
                            oadrnb_init);
        if(l_err) { break; }

        l_err = writeRegSfc(SFC_CMD_SPACE,
                            SFC_REG_OADRNS,
                            oadrns_init);
        if(l_err) { break; }

        l_err = writeRegSfc(SFC_CMD_SPACE,
                            SFC_REG_ADRCBF,
                            adrcbf_init);
        if(l_err) { break; }

        l_err = writeRegSfc(SFC_CMD_SPACE,
                            SFC_REG_ADRCMF,
                            adrcmf_init);
        if(l_err) { break; }

        l_err = writeRegSfc(SFC_CMD_SPACE,
                            SFC_REG_CONF,
                            conf_init);
        if(l_err) { break; }


        //Determine NOR Flash type - triggers vendor specific workarounds
        //We also use the chipID in some FFDC situations.
        l_err = getNORChipId(cv_nor_chipid);
        if(l_err) { break; }

        TRACFCOMP(g_trac_pnor,
                  "PnorDD::reinitializeSfc> cv_nor_chipid=0x%.8x> ",
                  cv_nor_chipid );

        l_err = readRegSfc(SFC_CMD_SPACE,
                           SFC_REG_ERASMS,
                           iv_erasesize_bytes);
        if(l_err) { break; }

        // Good path if you made it here: reset class variable
        cv_sfcInitDone = true;

#endif

    } while(0);

    if (l_err)
    {
        TRACFCOMP( g_trac_pnor,INFO_MRK"PnorDD::reinitializeSfc> SFC reinitialization FAILED - l_err  rc=0x%X, eid=%d", l_err->reasonCode(), l_err->eid());
        iv_error_recovery_failed = true;

    }

    return l_err;
}


bool PnorDD::shouldRetry( RetryOp     i_op,
                          errlHndl_t& io_err,
                          errlHndl_t& io_original_err,
                          uint8_t&    io_retry_count   )
{
    TRACDCOMP(g_trac_pnor, ENTER_MRK"PnorDD::shouldRetry(%d)", i_op);

    bool should_retry = false;

    if ( ( io_err == NULL ) || ( iv_error_recovery_failed == true ) )
    {
        // Either Operation was successful OR error recovery failed -
        // either way don't retry
        should_retry = false;

        // Error logs handled below
    }
    else
    {
        // Operation failed
        // If op will be attempted again: save log and continue
        if ( io_retry_count < PNORDD_MAX_RETRIES )
        {
            // Save original error - and only original error
            if ( io_original_err == NULL )
            {
                io_original_err = io_err;
                io_err = NULL;

                TRACFCOMP(g_trac_pnor, ERR_MRK"PnorDD::shouldRetry(%d)> Error rc=0x%X, eid=0x%X, retry/MAX=%d/%d. Save error and retry", i_op, io_original_err->reasonCode(), io_original_err->eid(), io_retry_count, PNORDD_MAX_RETRIES);

                io_original_err->collectTrace(PNOR_COMP_NAME);
            }
            else
            {
                // Add data to original error
                TRACFCOMP(g_trac_pnor, ERR_MRK"PnorDD::shouldRetry(%d)> Another Error rc=0x%X, eid=0x%X, plid=%d, retry/MAX=%d/%d. Delete error and retry", i_op, io_err->reasonCode(), io_err->eid(), io_err->plid(), io_retry_count, PNORDD_MAX_RETRIES);

                char err_str[80];
                snprintf(err_str, sizeof(err_str), "Another fail: Deleted "
                         "Retried Error Log rc=0x%.8X eid=0x%.8X",
                         io_err->reasonCode(), io_err->eid());

                ERRORLOG::ErrlUserDetailsString(err_str)
                          .addToLog(io_original_err);

                // Delete this new error
                delete io_err;
                io_err = NULL;
            }

            should_retry = true;
            io_retry_count++;

        }
        else // no more retries: trace and break
        {
            should_retry = false;

            TRACFCOMP(g_trac_pnor, ERR_MRK"PnorDD::shouldRetry(%d)> Another Error rc=0x%X, eid=0x%X, No More Retries (retry/MAX=%d/%d). Returning Original Error (rc=0x%X, eid=0x%X)", i_op, io_err->reasonCode(), io_err->eid(), io_retry_count, PNORDD_MAX_RETRIES, io_original_err->reasonCode(), io_original_err->eid());

            // error logs handled below
        }
    }

    // Handle saved error if we're not retrying
    if ( ( io_original_err != NULL) && ( should_retry == false ) )
    {
        if (io_err)
        {
            // commit l_err with original error PLID as informational
            io_err->plid(io_original_err->plid());
            io_err->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
            TRACFCOMP(g_trac_pnor, ERR_MRK"PnorDD::shouldRetry(%d)> Committing latest io_err eid=0x%X with plid of original err (eid=0x%X): plid=0x%X", i_op, io_err->eid(), io_original_err->plid(), io_err->plid());

            io_err->collectTrace(PNOR_COMP_NAME);

            errlCommit(io_err, PNOR_COMP_ID);

            // return original error
            io_err = io_original_err;

            // set io_original_err to NULL to avoid dual references
            io_original_err = NULL;
        }
        else
        {
            // Since we eventually succeeded, delete original error
            TRACFCOMP(g_trac_pnor, "PnorDD::shouldRetry(%d)> Op successful, deleting saved err eid=0x%X, plid=0x%X", i_op, io_original_err->eid(), io_original_err->plid());

            delete io_original_err;
            io_original_err = NULL;
        }
    }

    TRACDCOMP(g_trac_pnor, EXIT_MRK"PnorDD::shouldRetry(%d)> return %d (io_retry_count=%d)", i_op, should_retry, io_retry_count);

    return should_retry;
}
