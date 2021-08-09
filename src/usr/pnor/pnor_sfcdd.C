/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/pnor_sfcdd.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2021                        */
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
#include "pnor_sfcdd.H"
#include "pnor_common.H"
#include <pnor/pnorif.H>
#include <pnor/pnor_reasoncodes.H>
#include <sys/time.h>
#include <initservice/initserviceif.H>
#include <util/align.H>
#include <lpc/lpcif.H>
#include "sfcdd.H"

/*****************************************************************************/
// D e f i n e s
/*****************************************************************************/
#define PNORDD_MAX_RETRIES 1

// Initialized in pnorrp.C
extern trace_desc_t* g_trac_pnor;

namespace PNOR
{

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

        // The PNOR device driver interface is initialized with the
        // MASTER_PROCESSOR_CHIP_TARGET_SENTINEL.  Other target
        // access requires a separate PnorSfcDD class created
        assert( i_target == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL );

        // Read the flash
        l_err = Singleton<PnorSfcDD>::instance().readFlash(io_buffer,
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

        // The PNOR device driver interface is initialized with the
        // MASTER_PROCESSOR_CHIP_TARGET_SENTINEL.  Other target
        // access requires a separate PnorSfcDD class created
        assert( i_target == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL );

        // Write the flash
        l_err = Singleton<PnorSfcDD>::instance().writeFlash(io_buffer,
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
    return Singleton<PnorSfcDD>::instance().usingL3Cache();
}

/**
 * @brief Retrieve some information about the PNOR/SFC hardware
 */
void getPnorInfo( PnorInfo_t& o_pnorInfo )
{
    o_pnorInfo.mmioOffset = LPC_SFC_MMIO_OFFSET|LPC_FW_SPACE;
    o_pnorInfo.norWorkarounds =
      Singleton<PnorSfcDD>::instance().getNorWorkarounds();
    o_pnorInfo.flashSize =
      Singleton<PnorSfcDD>::instance().getNorSize();
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
errlHndl_t PnorSfcDD::readFlash(void* o_buffer,
                                size_t& io_buflen,
                                uint64_t i_address)
{
    //TRACDCOMP(g_trac_pnor, "PnorSfcDD::readFlash(i_address=0x%llx)> ", i_address);

    //mask off chip select for now, will probably break up fake PNOR into
    //multiple fake chips eventually
    uint64_t l_address = i_address & 0x00000000FFFFFFFF;

    mutex_lock(iv_mutex_ptr);
    errlHndl_t l_err = _readFlash( l_address, io_buflen, o_buffer );
    mutex_unlock(iv_mutex_ptr);

    return l_err;
}

/**
 * @brief Performs a PNOR Write Operation
 */
errlHndl_t PnorSfcDD::writeFlash(void* i_buffer,
                                 size_t& io_buflen,
                                 uint64_t i_address)
{
    TRACDCOMP(g_trac_pnor, ENTER_MRK"PnorSfcDD::writeFlash(i_address=0x%llx)> ", i_address);
    errlHndl_t l_err = NULL;

    do{
        TRACDCOMP(g_trac_pnor,"PNOR write %.8X", i_address);

        //mask off chip select for now, will probably break up fake PNOR into
        //multiple fake chips eventually
        uint64_t l_address = i_address & 0x00000000FFFFFFFF;

        // In NOR flash we can clear bits without an erase but we
        // cannot set them.  When we erase we have to erase an entire
        // block of data at a time.

        uint32_t cur_writeStart_addr = static_cast<uint32_t>(l_address);
        uint32_t cur_blkStart_addr = findEraseBlock(cur_writeStart_addr);
        uint32_t cur_blkEnd_addr = cur_blkStart_addr + iv_eraseSizeBytes;
        uint32_t write_bytes = iv_eraseSizeBytes;
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
                if( bytes_left > iv_eraseSizeBytes )
                {
                    write_bytes = iv_eraseSizeBytes;
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
            mutex_lock(iv_mutex_ptr);
            l_err = compareAndWriteBlock(
                              cur_blkStart_addr,
                              cur_writeStart_addr,
                              write_bytes,
                              (void*)((uint64_t)i_buffer +
                              ((uint64_t)cur_writeStart_addr-l_address)));

            mutex_unlock(iv_mutex_ptr);

            if( l_err ) { break; }

            //move start to end of current erase block
            cur_blkStart_addr = cur_blkEnd_addr;
            //increment end by erase block size.
            cur_blkEnd_addr += iv_eraseSizeBytes;
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
    TRACDCOMP(g_trac_pnor,EXIT_MRK"PnorSfcDD::writeFlash(i_address=0x%llx)> io_buflen=%.8X", i_address, io_buflen);

    return l_err;
}


/********************
 Private/Protected Methods
 ********************/
mutex_t PnorSfcDD::cv_mutex = MUTEX_INITIALIZER;

/**
 * @brief  Constructor
 */
PnorSfcDD::PnorSfcDD( TARGETING::Target* i_target )
: iv_eraseSizeBytes(ERASESIZE_BYTES_DEFAULT)
, iv_norChipId(0)
, iv_sfc(NULL)
, iv_constructorLog(nullptr)
{
    TRACFCOMP(g_trac_pnor, ENTER_MRK "PnorSfcDD::PnorSfcDD()" );
    errlHndl_t l_err = NULL;

    //Zero out erase counter
    memset(iv_erases, 0xff, sizeof(iv_erases));

    // Use i_target if all of these apply
    // 1) not NULL
    // 2) not MASTER_PROCESSOR_CHIP_TARGET_SENTINEL
    // 3) i_target does not correspond to Master processor (ie the
    //    same processor as MASTER_PROCESSOR_CHIP_TARGET_SENTINEL)
    // otherwise, use MASTER_PROCESSOR_CHIP_TARGET_SENTINEL
    // NOTE: i_target can only be used when targeting is loaded
    if ( ( i_target != NULL ) &&
         ( i_target != TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL ) )
    {

        iv_target = i_target;

        // Check if processor is MASTER
        TARGETING::ATTR_PROC_MASTER_TYPE_type type_enum =
                   iv_target->getAttr<TARGETING::ATTR_PROC_MASTER_TYPE>();

        // Master target could collide and cause deadlocks with PnorSfcDD singleton
        // used for ddRead/ddWrite with MASTER_PROCESSOR_CHIP_TARGET_SENTINEL
        assert( type_enum != TARGETING::PROC_MASTER_TYPE_ACTING_MASTER );

        // Initialize and use class-specific mutex
        iv_mutex_ptr = &iv_mutex;
        mutex_init(iv_mutex_ptr);
        TRACFCOMP(g_trac_pnor, "PnorSfcDD::PnorSfcDD()> Using i_target=0x%X (non-master) and iv_mutex_ptr", TARGETING::get_huid(i_target));
    }
    else
    {
        iv_target = TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;
        iv_mutex_ptr = &(cv_mutex);
    }

    do {
        //Instantiate the appropriate SFC object
        l_err = PNOR::create_SfcDD( iv_sfc,
                                    iv_target );
        if( l_err ) { break; }

        //Initialize the SFC hardware if needed
#ifndef BMC_DOES_SFC_INIT
        l_err = iv_sfc->hwInit();
        if( l_err ) { break; }
#endif

        //Figure out what kind of flash chip we have
        l_err = iv_sfc->getNORChipId(iv_norChipId);
        if( l_err ) { break; }

        //The LPC logic in the processor can return all zeroes with no
        // errors in the case where the SFC isn't physically installed.
        // If we ever hit an all-zero NOR we should fail out.
        if( iv_norChipId == 0 )
        {
            /*@
             * @errortype
             * @moduleid     PNOR::MOD_PNORDD_SFC_CONSTRUCTOR
             * @reasoncode   PNOR::RC_ZERO_NOR_CHIPID
             * @userdata1    Processor HUID
             * @userdata2    <unused>
             * @devdesc      PnorSfcDD::PnorSfcDD> Read zero for PNOR
             *               chipid, assuming SFC is bad or missing.
             * @custdesc     Error caused by missing hardware
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            PNOR::MOD_PNORDD_SFC_CONSTRUCTOR,
                                            PNOR::RC_ZERO_NOR_CHIPID,
                                            TARGETING::get_huid(iv_target),
                                            0 );
            l_err->collectTrace(PNOR_COMP_NAME);
            l_err->collectTrace(LPC_COMP_NAME);
            l_err->addPartCallout( iv_target,
                                   HWAS::PNOR_PART_TYPE,
                                   HWAS::SRCI_PRIORITY_HIGH );
            break;
        }

        //Keep track of the size of the erase block
        iv_eraseSizeBytes = iv_sfc->eraseSizeBytes();
        //We only support 4K erase blocks for now
        assert(iv_eraseSizeBytes == ERASESIZE_BYTES_DEFAULT);
    } while(0);

    if( l_err )
    {
        TRACFCOMP( g_trac_pnor, "Failure to initialize the PNOR logic :: RC=%.4X", ERRL_GETRC_SAFE(l_err) );
        l_err->collectTrace(PNOR_COMP_NAME);
        iv_constructorLog = l_err; //remember for later
        l_err = nullptr;

        //Only shutdown if this error occurs on the master proc
        if (TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL == iv_target)
        {
            TRACFCOMP( g_trac_pnor, "PNOR Error on Master Proc, shutting down");
            INITSERVICE::doShutdown( PNOR::RC_PNOR_INIT_FAILURE );
        }
    }

    TRACFCOMP(g_trac_pnor, EXIT_MRK "PnorSfcDD::PnorSfcDD()" );
}

/**
 * @brief  Destructor
 */
PnorSfcDD::~PnorSfcDD()
{
    if( iv_sfc )
    {
        delete iv_sfc;
    }

    // if we still have an unclaimed log, commit it as informational
    if( iv_constructorLog )
    {
        iv_constructorLog->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
        iv_constructorLog->collectTrace(PNOR_COMP_NAME);
        errlCommit(iv_constructorLog, PNOR_COMP_ID);
    }
}

/**
 * @brief Informs caller if PNORDD is using
 *        L3 Cache for fake PNOR or not.
 */
bool PnorSfcDD::usingL3Cache( void )
{
    return iv_sfc->usingL3Cache();
}

/**
 * @brief Compare the existing data in 1 erase block of the flash with
 *   the incoming data and write or erase as needed
 */
errlHndl_t PnorSfcDD::compareAndWriteBlock(uint32_t i_blockStart,
                                        uint32_t i_writeStart,
                                        size_t i_bytesToWrite,
                                        void* i_data)
{
    TRACDCOMP(g_trac_pnor,">>compareAndWriteBlock(0x%.8X,0x%.8X,0x%.8X)", i_blockStart, i_writeStart, i_bytesToWrite);
    errlHndl_t l_err = NULL;
    uint8_t* read_data = NULL;

    do {
        // remember any data we read so we don't have to reread it later
        read_data = new uint8_t[iv_eraseSizeBytes];

        // remember if we need to erase the block or not
        bool need_erase = false;
        bool need_write = false;

        //STEP 1: Read data in PNOR for compares (only read section we
        //   want to write)
        //read_start needs to be uint32* for bitwise word compares later
        uint32_t* read_start = (uint32_t*)(read_data
                                           + i_writeStart-i_blockStart);
        l_err = _readFlash( i_writeStart,
                            i_bytesToWrite,
                            (void*) read_start );
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
            TRACDCOMP(g_trac_pnor,"compareAndWriteBlock>  NO Write Needed! Exiting Function");
            break;
        }

        //STEP 3: If the need to erase was detected, read out the
        //  rest of the Erase block
        if(need_erase)
        {
            TRACDCOMP(g_trac_pnor,"compareAndWriteBlock> Need to perform Erase");
            //Get data before write section
            if(i_writeStart > i_blockStart)
            {
                TRACDCOMP(g_trac_pnor,"compareAndWriteBlock> Reading beginning data i_blockStart=0x%.8x, readLen=0x%.8x",
                          i_blockStart, i_writeStart-i_blockStart);
                l_err = _readFlash( i_blockStart,
                                    i_writeStart-i_blockStart,
                                    read_data );
                if( l_err ) { break; }
            }

            //Get data after write section
            if( (i_writeStart+i_bytesToWrite)
                < (i_blockStart + iv_eraseSizeBytes) )
            {
                uint32_t tail_length =
                  i_blockStart
                  + iv_eraseSizeBytes
                  - (i_writeStart+i_bytesToWrite);
                uint8_t* tail_buffer =
                  read_data
                  + i_writeStart-i_blockStart
                  + i_bytesToWrite;

                TRACDCOMP(g_trac_pnor,"compareAndWriteBlock> Reading tail data. addr=0x%.8x, tail_length=0x%.8x",
                          i_writeStart+i_bytesToWrite, tail_length);
                l_err = _readFlash( i_writeStart+i_bytesToWrite,
                                    tail_length,
                                    tail_buffer );
                if( l_err ) { break; }
            }

            // erase the flash
            TRACDCOMP(g_trac_pnor,"compareAndWriteBlock> Calling eraseFlash:. i_blockStart=0x%.8x", i_blockStart);
            l_err = _eraseFlash( i_blockStart );
            if( l_err ) { break; }

            //STEP 4: Write the data back out - need to write everything
            //  since we erased the block

            //re-write data before new data to write
            if(i_writeStart > i_blockStart)
            {
                TRACDCOMP(g_trac_pnor,"compareAndWriteBlock> Writing beginning data i_blockStart=0x%.8x, readLen=0x%.8x",
                          i_blockStart, i_writeStart-i_blockStart);
                l_err = _writeFlash(i_blockStart,
                                    i_writeStart-i_blockStart,
                                    read_data);
                if( l_err ) { break; }
            }

            //Write data after new data to write
            if( (i_writeStart+i_bytesToWrite)
                < (i_blockStart + iv_eraseSizeBytes) )
            {
                uint32_t tail_length =
                  i_blockStart
                  + iv_eraseSizeBytes
                  - (i_writeStart+i_bytesToWrite);
                uint8_t* tail_buffer =
                  read_data +
                  i_writeStart-i_blockStart
                  + i_bytesToWrite;

                TRACDCOMP(g_trac_pnor,"compareAndWriteBlock> Writing tail data. addr=0x%.8x, tail_length=0x%.8x", i_writeStart+i_bytesToWrite, tail_length);
                l_err = _writeFlash(i_writeStart+i_bytesToWrite,
                                    tail_length,
                                    tail_buffer);
                if( l_err ) { break; }
            }

            //Write the new data - always do this
            l_err = _writeFlash(i_writeStart,
                                i_bytesToWrite,
                                i_data);
            if( l_err ) { break; }
        }
        else //
        {
            //STEP 4 ALT: No erase needed, only write the parts that changed.
            TRACDCOMP(g_trac_pnor,"compareAndWriteBlock> No erase, just writing");

            for(uint32_t cword = 0; cword < wordsToWrite; cword++)
            {
                // look for any bits being changed (using XOR)
                if(read_start[cword] ^ i_dataWord[cword] )
                {
                    //Write the new data - always do this
                    l_err = _writeFlash(i_writeStart + (cword*4),
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

    TRACDCOMP(g_trac_pnor,"<<compareAndWriteBlock() Exit");


    return l_err;
}


/**
 * @brief Erase a block of flash
 */
errlHndl_t PnorSfcDD::eraseFlash(uint32_t i_address)
{
    errlHndl_t l_err = NULL;
    TRACDCOMP(g_trac_pnor, ">>PnorSfcDD::eraseFlash> Block 0x%.8X", i_address );

    do {
        if( findEraseBlock(i_address) != i_address )
        {
            /*@
             * @errortype
             * @moduleid     PNOR::MOD_PNORDD_ERASEFLASH
             * @reasoncode   PNOR::RC_INVALID_ADDRESS
             * @userdata1    Flash Address
             * @userdata2    Nearest Erase Boundary
             * @devdesc      PnorSfcDD::eraseFlash> Address not on erase boundary
             * @custdesc     Firmware error accessing flash during IPL
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            PNOR::MOD_PNORDD_ERASEFLASH,
                                            PNOR::RC_INVALID_ADDRESS,
                                            TWO_UINT32_TO_UINT64(0,i_address),
                                            findEraseBlock(i_address),
                                            true /*Add HB SW Callout*/ );
            l_err->collectTrace(PNOR_COMP_NAME);
            break;
        }

        for(uint32_t idx = 0; idx < ERASE_COUNT_MAX; idx++ )
        {
            if(iv_erases[idx].addr == i_address)
            {
                iv_erases[idx].count++;
                TRACFCOMP(g_trac_pnor,
                          "PnorSfcDD::eraseFlash> Block 0x%.8X has %d erasures",
                          i_address, iv_erases[idx].count );
                break;

            }
            //iv_erases is init to all 0xff,
            //  so can use ~0 to check for an unused position
            else if(iv_erases[idx].addr == ~0u)
            {
                iv_erases[idx].addr = i_address;
                iv_erases[idx].count = 1;
                TRACFCOMP(g_trac_pnor,
                          "PnorSfcDD::eraseFlash> Block 0x%.8X has %d erasures",
                          i_address, iv_erases[idx].count );
                break;
            }
            else if( idx == (ERASE_COUNT_MAX - 1))
            {
                TRACFCOMP(g_trac_pnor, "PnorSfcDD::eraseFlash> Erase counter full!  Block 0x%.8X Erased", i_address );
                break;
            }
        }

        // actually do the erase
        l_err = _eraseFlash(i_address);
        if(l_err) { break; }

    } while(0);

    return l_err;
}



/**
 * @brief Returns if an operation should be retried and handles
 *        the error logs
 */
bool PnorSfcDD::shouldRetry( RetryOp     i_op,
                             errlHndl_t& io_err,
                             errlHndl_t& io_original_err,
                             uint8_t&    io_retry_count   )
{
    TRACDCOMP(g_trac_pnor, ENTER_MRK"PnorSfcDD::shouldRetry(%d)", i_op);

    bool should_retry = false;

    if ( io_err == NULL )
    {
        // Operation was successful so don't retry
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

                TRACFCOMP(g_trac_pnor, ERR_MRK"PnorSfcDD::shouldRetry(%d)> Error rc=0x%X, eid=0x%X, retry/MAX=%d/%d. Save error and retry", i_op, io_original_err->reasonCode(), io_original_err->eid(), io_retry_count, PNORDD_MAX_RETRIES);

                io_original_err->collectTrace(PNOR_COMP_NAME);
            }
            else
            {
                // Add data to original error
                TRACFCOMP(g_trac_pnor, ERR_MRK"PnorSfcDD::shouldRetry(%d)> Another Error rc=0x%X, eid=0x%X, plid=%d, retry/MAX=%d/%d. Delete error and retry", i_op, io_err->reasonCode(), io_err->eid(), io_err->plid(), io_retry_count, PNORDD_MAX_RETRIES);

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

            TRACFCOMP(g_trac_pnor, ERR_MRK"PnorSfcDD::shouldRetry(%d)> Another Error rc=0x%X, eid=0x%X, No More Retries (retry/MAX=%d/%d). Returning Original Error (rc=0x%X, eid=0x%X)", i_op, io_err->reasonCode(), io_err->eid(), io_retry_count, PNORDD_MAX_RETRIES, io_original_err->reasonCode(), io_original_err->eid());

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
            TRACFCOMP(g_trac_pnor, ERR_MRK"PnorSfcDD::shouldRetry(%d)> Committing latest io_err eid=0x%X with plid of original err (eid=0x%X): plid=0x%X", i_op, io_err->eid(), io_original_err->plid(), io_err->plid());

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
            TRACFCOMP(g_trac_pnor, "PnorSfcDD::shouldRetry(%d)> Op successful, deleting saved err eid=0x%X, plid=0x%X", i_op, io_original_err->eid(), io_original_err->plid());

            delete io_original_err;
            io_original_err = NULL;
        }
    }

    TRACDCOMP(g_trac_pnor, EXIT_MRK"PnorSfcDD::shouldRetry(%d)> return %d (io_retry_count=%d)", i_op, should_retry, io_retry_count);

    return should_retry;
}

/**
 * @brief Calls the SFC to perform a PNOR Write Operation
 */
errlHndl_t PnorSfcDD::_writeFlash( uint32_t i_addr,
                                   size_t i_size,
                                   void* i_data )
{
    TRACDCOMP(g_trac_pnor, ENTER_MRK"PnorSfcDD::_writeFlash(i_addr=0x%.8X)> ", i_addr);
    errlHndl_t l_err = NULL;
    errlHndl_t original_err = NULL;
    uint8_t retry = 0;

    do
    {
        // Call over to the SFC code to do the actual write
        l_err = iv_sfc->writeFlash( i_addr, i_size, i_data );

        // end of operation - check for retry
    } while( shouldRetry(RETRY_writeFlash, l_err, original_err, retry) );

    if( l_err )
    {
        l_err->collectTrace(PNOR_COMP_NAME);
    }

    return l_err;
}

/**
 * @brief Calls the SFC to perform a PNOR Read Operation
 */
errlHndl_t PnorSfcDD::_readFlash( uint32_t i_addr,
                                  size_t i_size,
                                  void* o_data )
{
    //TRACDCOMP(g_trac_pnor, "PnorSfcDD::_readFlash(i_address=0x%.8X)> ", i_addr);
    errlHndl_t l_err = NULL;
    errlHndl_t original_err = NULL;
    uint8_t retry = 0;

    do{
        //Send command over to the flash controller to do the work
        l_err = iv_sfc->readFlash(i_addr, i_size, o_data);

        // end of operation - check for retry
    } while( shouldRetry(RETRY_readFlash, l_err, original_err, retry) );

    if( l_err )
    {
        l_err->collectTrace(PNOR_COMP_NAME);
    }

    return l_err;
}

/**
 * @brief Calls the SFC to perform a PNOR Read Operation
 */
errlHndl_t PnorSfcDD::_eraseFlash( uint32_t i_addr )
{
    TRACDCOMP(g_trac_pnor, "PnorSfcDD::_eraseFlash(i_address=0x%.8X)> ", i_addr);
    errlHndl_t l_err = NULL;
    errlHndl_t original_err = NULL;
    uint8_t retry = 0;

    do{
        //Send command over to the flash controller to do the work
        l_err = iv_sfc->eraseFlash(i_addr);

        // end of operation - check for retry
    } while( shouldRetry(RETRY_eraseFlash, l_err, original_err, retry) );

    if( l_err )
    {
        l_err->collectTrace(PNOR_COMP_NAME);
    }

    return l_err;
}

/**
 * @brief Retrieve bitstring of NOR workarounds
 */
uint32_t PnorSfcDD::getNorWorkarounds( void )
{
    return iv_sfc->getNorWorkarounds();
}

/**
 * @brief Retrieve size of NOR flash
 */
uint32_t PnorSfcDD::getNorSize( void )
{
#ifdef CONFIG_PNOR_IS_32MB
    return (32*MEGABYTE);
#else //default to 64MB
    return (64*MEGABYTE);
#endif
}
