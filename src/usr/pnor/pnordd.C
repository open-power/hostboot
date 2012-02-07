//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/pnor/pnordd.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
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
#include <string.h>
#include <devicefw/driverif.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <targeting/targetservice.H>
#include <errl/errlmanager.H>
#include "pnordd.H"
#include <pnor/pnorif.H>
#include <pnor/pnor_reasoncodes.H>
#include <sys/time.h>

// Uncomment this to enable smart writing
//#define SMART_WRITE

// These are used to cheat and use a chunk of our cache as a PNOR
//   iv_mode == MODEL_MEMCPY,MODEL_LPC_MEM
void write_fake_pnor( uint64_t i_pnorAddr, void* i_buffer, size_t i_size );
void read_fake_pnor( uint64_t i_pnorAddr, void* o_buffer, size_t i_size );
void erase_fake_pnor( uint64_t i_pnorAddr, size_t i_size );

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
        //@todo (RTC:34763) - add support for unaligned data
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
        //@todo (RTC:34763) - add support for unaligned data
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

        l_err = verifyFlashAddressRange(l_address, io_buflen);
        if(l_err)
        {
            io_buflen = 0;
            break;
        }

        // skip everything in MEMCPY mode
        if( MODEL_MEMCPY == iv_mode )
        {
            read_fake_pnor( l_address, o_buffer, io_buflen );
            break;
        }

        // LPC is accessed 32-bits at a time...
        uint32_t* word_ptr = static_cast<uint32_t*>(o_buffer);
        uint64_t words_read = 0;
        for( uint32_t addr = i_address;
             addr < (i_address+io_buflen);
             addr += sizeof(uint32_t) )
        {
            // flash is mapped directly in the FW space
            l_err = readLPC( addr + LPCHC_FW_SPACE,
                             word_ptr[words_read] );
            if( l_err ) { break; }

            words_read++;           
        }
        io_buflen = words_read*sizeof(uint32_t);
        if( l_err ) { break; }
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
    //TRACDCOMP(g_trac_pnor, "PnorDD::writeFlash(i_address=0x%llx)> ", i_address);
    errlHndl_t l_err = NULL;

    do{        
        TRACDCOMP(g_trac_pnor,"PNOR write %.8X", i_address);

        //mask off chip select for now, will probably break up fake PNOR into
        //multiple fake chips eventually
        uint64_t l_address = i_address & 0x00000000FFFFFFFF;

        // make sure this is a valid address
        l_err = verifyFlashAddressRange(l_address, io_buflen);
        if(l_err) { break; }

        // skip everything in MEMCPY mode
        if( MODEL_MEMCPY == iv_mode )
        {
            write_fake_pnor( l_address, i_buffer, io_buflen );
            break;
        }

        // LPC is accessed 32-bits at a time, but we also need to be
        //   smart about handling erases.  In NOR flash we can set bits
        //   without an erase but we cannot clear them.  When we erase
        //   we have to erase an entire block of data at a time.
        uint32_t* word_ptr = static_cast<uint32_t*>(i_buffer);
        uint32_t cur_addr = static_cast<uint32_t>(l_address);
        uint64_t num_blocks = getNumAffectedBlocks(cur_addr,io_buflen);
        uint64_t bytes_left = io_buflen;

        // loop through erase blocks until we've gotten through all
        //  affected blocks
        for( uint64_t block = 0;
             block < num_blocks;
             ++block )
        {
            TRACDCOMP( g_trac_pnor, "Block %d: bytes_left=%d, cur_addr=0x%.8X", block, bytes_left, cur_addr );

            // write a single block of data out to flash efficiently
            l_err = compareAndWriteBlock( cur_addr,
                                          (bytes_left-1)/sizeof(uint32_t)+1,
                                          word_ptr );
            if( l_err ) { break; }
            //@todo (RTC:37744) - How should we handle PNOR errors?

            // move on to the next block
            if( bytes_left > ERASESIZE_BYTES )
            {
                bytes_left -= ERASESIZE_BYTES;
                cur_addr += ERASESIZE_BYTES;
            }
            else
            {
                // final block of partial data
                //   align cur_addr to the beginning of the block
                cur_addr = findEraseBlock(cur_addr+bytes_left);
                //   figure out the remaining data in the last block
                bytes_left = (l_address + io_buflen - cur_addr);
            }
            word_ptr += ((bytes_left-1)/sizeof(uint32_t))+1;
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

    return l_err;
}


/********************
 Private/Protected Methods
 ********************/

/**
 * @brief  Constructor
 */
PnorDD::PnorDD( PnorMode_t i_mode )
: iv_mode(i_mode)
{
    mutex_init(&iv_mutex);

    for( uint64_t x=0; x < (PNORSIZE/ERASESIZE_BYTES); x++ )
    {
        iv_erases[x] = 0;
    }

    //In the normal case we will choose the mode for the caller
    if( MODEL_UNKNOWN == iv_mode )
    {
        //Use ECCB scoms to drive LPC, flat memory map behind ECCB, no SPI
        //iv_mode = MODEL_FLAT_ECCB;

        //Break into 32-bit LPC ops but use memcpy into cache area
        iv_mode = MODEL_LPC_MEM;

        //Override for VPO, use flat model for performance
        //@fixme - how?? I can't use targetting yet to tell I'm in VPO...
    }

    TRACFCOMP(g_trac_pnor, "PnorDD::PnorDD()> Using mode %d", iv_mode);
}

/**
 * @brief  Destructor
 */
PnorDD::~PnorDD()
{

    //Nothing to do for now
}

/**
 * @brief Verify flash request is in appropriate address range
 */
errlHndl_t PnorDD::verifyFlashAddressRange(uint64_t i_address,
                                           size_t& i_length)
{
    errlHndl_t l_err = NULL;

    do{
        //@todo - Do we really need any checking here?
        //  if so we should be getting the size told to us by the PNOR RP
        //   based on the TOC or global data

        if((i_address+i_length) > PNORSIZE)
        {
            TRACFCOMP( g_trac_pnor, "PnorDD::verifyAddressRange> Invalid Address Requested : i_address=%d", i_address );
            /*@
             * @errortype
             * @moduleid     PNOR::MOD_PNORDD_VERIFYADDRESSRANGE
             * @reasoncode   PNOR::RC_INVALID_ADDRESS
             * @userdata1    Requested Address
             * @userdata2    Requested Length
             * @devdesc      PnorDD::verifyAddressRange> Invalid Address requested
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            PNOR::MOD_PNORDD_VERIFYADDRESSRANGE,
                                            PNOR::RC_INVALID_ADDRESS,
                                            TO_UINT64(i_address),
                                            TO_UINT64(i_length));
            break;
        }

    }while(0);

    return l_err;
}

/**
 * @brief Read a LPC Host Controller Register
 */
errlHndl_t PnorDD::readRegLPC(LpcRegAddr i_addr,
                              uint32_t& o_data)
{
    errlHndl_t l_err = NULL;

    // add the offset into the LPC register space
    uint32_t lpc_addr = i_addr + LPCHC_REG_SPACE;

    // call the generic LPC function
    l_err = readLPC( lpc_addr, o_data );
    return l_err;
}

/**
 * @brief Write a LPC Host Controller Register
 */
errlHndl_t PnorDD::writeRegLPC(LpcRegAddr i_addr,
                               uint32_t i_data)
{
    errlHndl_t l_err = NULL;

    // add the offset into the LPC register space
    uint32_t lpc_addr = i_addr + LPCHC_REG_SPACE;

    // call the generic LPC function
    l_err = writeLPC( lpc_addr, i_data );
    return l_err;
}

/**
 * @brief Read a SPI Register
 */
errlHndl_t PnorDD::readRegSPI(SpiRegAddr i_addr,
                              uint32_t& o_data)
{
    //@todo (RTC:35728) - SPI Support
    TRACFCOMP( g_trac_pnor, "PnorDD::readRegSPI> Unsupported Operation : i_addr=%d", i_addr );
    /*@
     * @errortype
     * @moduleid     PNOR::MOD_PNORDD_READREGSPI
     * @reasoncode   PNOR::RC_UNSUPPORTED_OPERATION
     * @userdata1    Requested Address
     * @userdata2    <unused>
     * @devdesc      PnorDD::readRegSPI> Unsupported Operation
     */
    return new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                   PNOR::MOD_PNORDD_READREGSPI,
                                   PNOR::RC_UNSUPPORTED_OPERATION,
                                   TO_UINT64(i_addr),
                                   0);

    /* Anything more than this??

     // add the offset into the LPC register space
     uint32_t lpc_addr = i_addr + LPC_SPI_REG_OFFSET;

     // call the generic LPC function
     l_err = readLPC( lpc_addr, o_data );

     */
}

/**
 * @brief Write a SPI Register
 */
errlHndl_t PnorDD::writeRegSPI(SpiRegAddr i_addr,
                               uint32_t i_data)
{
    //@todo (RTC:35728) - SPI Support
    TRACFCOMP( g_trac_pnor, "PnorDD::writeRegSPI> Unsupported Operation : i_addr=%d", i_addr );
    /*@
     * @errortype
     * @moduleid     PNOR::MOD_PNORDD_WRITEREGSPI
     * @reasoncode   PNOR::RC_UNSUPPORTED_OPERATION
     * @userdata1    Requested Address
     * @userdata2    <unused>
     * @devdesc      PnorDD::writeRegSPI> Unsupported Operation
     */
    return new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                   PNOR::MOD_PNORDD_WRITEREGSPI,
                                   PNOR::RC_UNSUPPORTED_OPERATION,
                                   TO_UINT64(i_addr),
                                   0);

    /* Anything more than this??

     // add the offset into the LPC register space
     uint32_t lpc_addr = i_addr + LPC_SPI_REG_OFFSET;

     // call the generic LPC function
     l_err = writeLPC( lpc_addr, i_data );

     */
    
}


/**
 * @brief Read an address from LPC space
 */
errlHndl_t PnorDD::readLPC(uint32_t i_addr,
                           uint32_t& o_data)
{
    errlHndl_t l_err = NULL;
    bool need_unlock = false;

    do {
        if( MODEL_LPC_MEM == iv_mode )
        {
            read_fake_pnor( i_addr - LPCHC_FW_SPACE,
                            static_cast<void*>(&o_data),
                            sizeof(uint32_t) );
            break;
        }

        // Note: If we got here then iv_mode is
        //  either MODEL_FLAT_ECCB or MODEL_REAL

        //@todo (RTC:36950) - add non-master support  
        TARGETING::Target* scom_target =
          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;

        // always read/write 64 bits to SCOM
        size_t scom_size = sizeof(uint64_t);

        // atomic section >>
        mutex_lock(&iv_mutex);
        need_unlock = true;

        // write command register with LPC address to read
        ControlReg_t eccb_cmd;
        eccb_cmd.read_op = 1;
        eccb_cmd.address = i_addr;
        l_err = deviceOp( DeviceFW::WRITE,
                          scom_target,
                          &(eccb_cmd.data64),
                          scom_size,
                          DEVICE_SCOM_ADDRESS(ECCB_CTL_REG) );
        if( l_err ) { break; }

        // poll for complete and get the data back
        StatusReg_t eccb_stat;
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
            nanosleep( 0, ECCB_POLL_INCR_NS*(++loop) );
            poll_time += ECCB_POLL_INCR_NS*loop;
        }
        if( l_err ) { break; }

        // check for errors or timeout
        if( (eccb_stat.data64 & LPC_STAT_REG_ERROR_MASK)
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
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            PNOR::MOD_PNORDD_READLPC,
                                            PNOR::RC_LPC_ERROR,
                                            TWO_UINT32_TO_UINT64(i_addr,poll_time),
                                            eccb_stat.data64);
            l_err->collectTrace("PNOR");
            l_err->collectTrace("XSCOM");
            //@todo (RTC:37744) - Any cleanup or recovery needed?
            break;
        }


        // atomic section <<
        mutex_unlock(&iv_mutex);
        need_unlock = false;

        // copy data out to caller's buffer
        o_data = eccb_stat.read_data;

    } while(0);

    if( need_unlock )
    {
        mutex_unlock(&iv_mutex);
        need_unlock = false;
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
    bool need_unlock = false;
   
    //TRACFCOMP(g_trac_pnor, "writeLPC> %.8X = %.8X", i_addr, i_data );

    do {
        if( MODEL_LPC_MEM == iv_mode )
        {
            write_fake_pnor( i_addr - LPCHC_FW_SPACE,
                             static_cast<void*>(&i_data),
                             sizeof(uint32_t) );
            break;
        }

        // Note: If we got here then iv_mode is
        //  either MODEL_FLAT_ECCB or MODEL_REAL

        //@todo (RTC:36950) - add non-master support  
        TARGETING::Target* scom_target =
          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;

        // always read/write 64 bits to SCOM
        size_t scom_size = sizeof(uint64_t);

        // atomic section >>
        mutex_lock(&iv_mutex);
        need_unlock = true;

        // write data register 
        uint64_t eccb_data = static_cast<uint64_t>(i_data);
        eccb_data = eccb_data << 32; //left-justify my data
        l_err = deviceOp( DeviceFW::WRITE,
                          scom_target,
                          &eccb_data,
                          scom_size,
                          DEVICE_SCOM_ADDRESS(ECCB_DATA_REG) );
        if( l_err ) { break; }

        // write command register with LPC address to write
        ControlReg_t eccb_cmd;
        eccb_cmd.read_op = 0;
        eccb_cmd.address = i_addr;
        l_err = deviceOp( DeviceFW::WRITE,
                          scom_target,
                          &(eccb_cmd.data64),
                          scom_size,
                          DEVICE_SCOM_ADDRESS(ECCB_CTL_REG) );
        if( l_err ) { break; }

        // poll for complete
        StatusReg_t eccb_stat;
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
            nanosleep( 0, ECCB_POLL_INCR_NS*(++loop) );
            poll_time += ECCB_POLL_INCR_NS*loop;
        }
        if( l_err ) { break; }

        // check for errors
        if( (eccb_stat.data64 & LPC_STAT_REG_ERROR_MASK)
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
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            PNOR::MOD_PNORDD_WRITELPC,
                                            PNOR::RC_LPC_ERROR,
                                            TWO_UINT32_TO_UINT64(0,i_addr),
                                            eccb_stat.data64);
            l_err->collectTrace("PNOR");
            l_err->collectTrace("XSCOM");
            //@todo (RTC:37744) - Any cleanup or recovery needed?
            break;
        }

        // atomic section <<
        mutex_unlock(&iv_mutex);
        need_unlock = false;

    } while(0);

    if( need_unlock )
    {
        mutex_unlock(&iv_mutex);
        need_unlock = false;
    }

    return l_err;
}

/**
 * @brief Compare the existing data in 1 erase block of the flash with
 *   the incoming data and write or erase as needed
 */
errlHndl_t PnorDD::compareAndWriteBlock(uint32_t i_targetAddr,
                                        uint32_t i_wordsToWrite,
                                        uint32_t* i_data)
{
    TRACFCOMP(g_trac_pnor,"compareAndWriteBlock(0x%.8X,%d,%p)", i_targetAddr, i_wordsToWrite, i_data);
    errlHndl_t l_err = NULL;

    // remember any data we read so we don't have to reread it later
    typedef struct
    {
        uint32_t data;
        bool wasRead;
        bool diff;
    } readflag_t;
    readflag_t* read_data = NULL;

    do {
        // skip the erase block logic if we're in a memcpy mode
        if( (MODEL_MEMCPY == iv_mode) || (MODEL_LPC_MEM == iv_mode) )
        {
            // LPC is accessed 32-bits at a time...
            uint64_t words_written = 0;
            for( uint32_t addr = i_targetAddr;
                 addr < (i_targetAddr+i_wordsToWrite*sizeof(uint32_t));
                 addr += sizeof(uint32_t) )
            {
                // flash is mapped directly in the FW space
                l_err = writeLPC( addr + LPCHC_FW_SPACE,
                                  i_data[words_written] );
                if( l_err ) { break; }

                words_written++;
            }
            if( l_err ) { break; }

            // all done
            break;
        }


        // remember any data we read so we don't have to reread it later
        read_data = new readflag_t[ERASESIZE_WORD32];
        for( size_t x = 0; x < ERASESIZE_WORD32; x++ )
        {
            read_data[x].wasRead = false;
            read_data[x].diff = false;
        }

        // remember if we need to erase the block or not
        bool need_erase = false;

        // walk through every word of data to see what changed
        const uint32_t block_addr = findEraseBlock(i_targetAddr);
        for( uint64_t bword = 0; bword < ERASESIZE_WORD32; bword++ )
        {
            // note: bword is the offset into the flash block
            read_data[bword].diff = false;

            // no need to check data before where the write starts
            if( (block_addr + bword*sizeof(uint32_t)) < i_targetAddr )
            {
                continue;
            }
            // no need to check data after where the write ends
            else if( (block_addr + bword*sizeof(uint32_t)) >=
                     (i_targetAddr + i_wordsToWrite*sizeof(uint32_t)) ) 
            {
                // done looking now
                break;
            }
            // otherwise we need to compare our data with what is in flash now
            else
            {                
                l_err = readLPC( block_addr + bword*sizeof(uint32_t)
                                 + LPCHC_FW_SPACE,
                                 read_data[bword].data );
                if( l_err ) { break; }

                read_data[bword].wasRead = true;

                // dword is the offset into the input data
                uint64_t dword = (block_addr + bword*sizeof(uint32_t));
                dword -= i_targetAddr; //offset into user data
                dword = dword / sizeof(uint32_t); //convert bytes to words

                // look for any bits being changed (using XOR)
                if( read_data[bword].data ^ i_data[dword] )
                {
                    read_data[bword].diff = true;

                    // look for any bits that go from 1->0
                    if( read_data[bword].data & ~(i_data[dword]) )
                    {
                        need_erase = true;                   

                        // push the user data into the read buffer
                        //  to get written later
                        read_data[bword].data = i_data[dword];

                        // skip comparing the rest of the block,
                        //   just start writing it
                        break;
                    }

                    // push the user data into the read buffer
                    //  to get written later
                    read_data[bword].data = i_data[dword];
                }                                 
            }
        }
        if( l_err ) { break; }

        // erase the block if we need to
        if( need_erase )
        {
            // first we need to save off any data we didn't read yet
            //  that is not part of the data we are writing
            for( uint64_t bword = 0; bword < ERASESIZE_WORD32; bword++ )
            {
                // mark the word as different to force a write below
                read_data[bword].diff = true;

                // skip what we already read
                if( read_data[bword].wasRead )
                {
                    continue;
                }

                // dword is the offset into the input data
                uint64_t dword = (block_addr + bword*sizeof(uint32_t));
                dword -= i_targetAddr; //offset into user data
                dword = dword / sizeof(uint32_t); //convert bytes to words

                // restore the data before the write section
                if( (block_addr + bword*sizeof(uint32_t)) < i_targetAddr )
                {
                    l_err = readLPC( block_addr + bword*sizeof(uint32_t)
                                     + LPCHC_FW_SPACE,
                                     read_data[bword].data );
                    if( l_err ) { break; }
                }
                // restore the data after the write section
                else if( (block_addr + bword*sizeof(uint32_t)) >=
                         (i_targetAddr + i_wordsToWrite*sizeof(uint32_t)) ) 
                {
                    l_err = readLPC( block_addr + bword*sizeof(uint32_t)
                                     + LPCHC_FW_SPACE,
                                     read_data[bword].data );
                    if( l_err ) { break; }
                }
                // otherwise we will use the write data directly
                else
                {
                    read_data[bword].data = i_data[dword];
                }
            }
            if( l_err ) { break; }

            // erase the flash
            l_err = eraseFlash( block_addr );
            if( l_err ) { break; }
        }

        // walk through every word again to write the data back out
        uint64_t bword_written = 0;
        for( bword_written = 0;
             bword_written < ERASESIZE_WORD32;
             bword_written++ )
        {
            // only write what we have to
            if( !(read_data[bword_written].diff) )
            {
                continue;
            }

            // write the word out to the flash
            l_err = writeLPC( block_addr + bword_written*sizeof(uint32_t)
                              + LPCHC_FW_SPACE,
                              read_data[bword_written].data );
            if( l_err ) { break; }
            //@todo (RTC:37744) - How should we handle PNOR errors?
        }
        if( l_err ) { break; }

    } while(0);

    if( read_data )
    {
        delete[] read_data;
    }

    return l_err;
}

/**
 * @brief Erase a block of flash
 */
errlHndl_t PnorDD::eraseFlash(uint32_t i_address)
{
    errlHndl_t l_err = NULL;

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
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            PNOR::MOD_PNORDD_ERASEFLASH,
                                            PNOR::RC_LPC_ERROR,
                                            TWO_UINT32_TO_UINT64(0,i_address),
                                            findEraseBlock(i_address));
            break;
        }

        // log the erase of this block
        iv_erases[i_address/ERASESIZE_BYTES]++;
        TRACFCOMP(g_trac_pnor, "PnorDD::eraseFlash> Block 0x%.8X has %d erasures", i_address, iv_erases[i_address/ERASESIZE_BYTES] );

        if( MODEL_REAL != iv_mode )
        {
            erase_fake_pnor( i_address, ERASESIZE_BYTES );
            break; //all done
        }

        //@todo (RTC:35728) - issue some LPC/SPI commands to erase the block 
        /*@
         * @errortype
         * @moduleid     PNOR::MOD_PNORDD_ERASEFLASH
         * @reasoncode   PNOR::RC_UNSUPPORTED_OPERATION
         * @userdata1    Model mode
         * @userdata2    LPC Address to erase
         * @devdesc      PnorDD::eraseFlash> No support for MODEL_REAL yet
         */
        l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        PNOR::MOD_PNORDD_ERASEFLASH,
                                        PNOR::RC_UNSUPPORTED_OPERATION,
                                        static_cast<uint64_t>(iv_mode),
                                        i_address);
    } while(0);

    return l_err;
}



/*
 This code is used in the MODEL_MEMCPY and MODEL_LPC_MEM modes
*/

#define FAKE_PNOR_START 5*MEGABYTE
#define FAKE_PNOR_END 8*MEGABYTE
#define FAKE_PNOR_SIZE 3*MEGABYTE
void write_fake_pnor( uint64_t i_pnorAddr, void* i_buffer, size_t i_size )
{
    //create a pointer to the offset start.
    char * destPtr = (char *)(FAKE_PNOR_START+i_pnorAddr);

    //copy data from memory into the buffer.
    memcpy(destPtr, i_buffer, i_size);
}
void read_fake_pnor( uint64_t i_pnorAddr, void* o_buffer, size_t i_size )
{
    //create a pointer to the offset start.
    char * srcPtr = (char *)(FAKE_PNOR_START+i_pnorAddr);

    //copy data from memory into the buffer.
    memcpy(o_buffer, srcPtr, i_size);
}
void erase_fake_pnor( uint64_t i_pnorAddr, size_t i_size )
{
    //create a pointer to the offset start.
    char * srcPtr = (char *)(FAKE_PNOR_START+i_pnorAddr);

    //copy data from memory into the buffer.
    memset( srcPtr, 0, i_size );
}


