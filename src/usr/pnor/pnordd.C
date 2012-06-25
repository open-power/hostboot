/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/pnor/pnordd.C $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2011-2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
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
#include <targeting/common/targetservice.H>
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

    enum {
        VPO_MODE_OVERRIDE = 0xFAC0FAC0FAC0FAC0
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

/**
 * @brief Used for VPO testing via istep hack.  Will be removed once VPO Bringup is done.
 *    TODO (RTC:42487: Remove this once VPO PNOR bringup is done.
 */
void testRealPnor(void *io_pArgs)
{
    //        TARGETING::Target* l_testTarget =
    //          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;
    size_t l_size = sizeof(uint64_t);
    errlHndl_t l_err = NULL;
    uint64_t fails = 0;
    uint64_t total = 0;

    TRACFCOMP(g_trac_pnor, "PNOR::testRealPnor> starting" );

    PnorDD* pnordd = NULL;
    pnordd = new PnorDD(PnorDD::MODEL_REAL_CMD);


    // Perform PnorDD read
    const uint64_t l_address = 0x4;
    uint64_t l_readData = 0;
    l_size = sizeof(uint64_t);
    l_err = pnordd->readFlash(&l_readData,
                              l_size,
                              l_address);
    total++;
    if (l_err)
    {
        TRACFCOMP(g_trac_pnor, "E>PnorDdTest::testRealPnor: PNORDD read 1: readFlash() failed! Error committed.");
        errlCommit(l_err,PNOR_COMP_ID);
        fails++;
    }
    total++;

    TRACFCOMP(g_trac_pnor, "PNOR::testRealPnor> l_readData=0x%.16x", l_readData );
    TRACFCOMP(g_trac_pnor, "PNOR::testRealPnor> Try writing data" );

    uint64_t l_writeData = 0x12345678FEEDB0B0;
    l_size = sizeof(uint64_t);
    l_err = pnordd->writeFlash(&l_writeData,
                               l_size,
                               l_address);

    total++;
    if (l_err)
    {
        TRACFCOMP(g_trac_pnor, "E>PNOR::testRealPnor: PNORDD write 1: writeFlash() failed! Error committed.");
        errlCommit(l_err,PNOR_COMP_ID);
        fails++;
    }
    total++;

    // Perform PnorDD read
    l_readData = 0;
    l_size = sizeof(uint64_t);
    l_err = pnordd->readFlash(&l_readData,
                              l_size,
                              l_address);
    total++;
    if (l_err)
    {
        TRACFCOMP(g_trac_pnor, "E>PNOR::testRealPnor: PNORDD read 2: readFlash() failed! Error committed.");
        errlCommit(l_err,PNOR_COMP_ID);
        fails++;
    }
    total++;

    TRACFCOMP(g_trac_pnor, "PNOR::testRealPnor>  PNORDD read 2: l_readData=0x%.16x", l_readData );

    TRACFCOMP(g_trac_pnor, "PNOR::testRealPnor> %d/%d fails", fails, total );
    if( pnordd )
    {
        delete pnordd;
    }
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

        //If we get here we're doing either MODEL_LPC_MEM or MODEL_REAL_CMD
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

        //If we get here we're doing either MODEL_LPC_MEM or MODEL_REAL_CMD

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
            write_bytes = iv_erasesize_bytes;
            if(bytes_left < iv_erasesize_bytes )
            {
                uint32_t end_waste = 0;
                //deduct any unused space at the end of the erase block
                if( cur_blkEnd_addr > (cur_writeStart_addr + bytes_left))
                {
                    end_waste = cur_blkEnd_addr - (cur_writeStart_addr + bytes_left);
                    write_bytes -= end_waste;
                }

                //deduct any unused space at the beginning of the erase block
                write_bytes = write_bytes - (cur_writeStart_addr - cur_blkStart_addr);
            }

            // write a single block of data out to flash efficiently
            mutex_lock(&cv_mutex);
            l_err = compareAndWriteBlock(cur_blkStart_addr,
                                         cur_writeStart_addr,
                                         write_bytes,
                                         (void*)((uint64_t)i_buffer + ((uint64_t)cur_writeStart_addr-l_address)));
            mutex_unlock(&cv_mutex);

            if( l_err ) { break; }
            //@todo (RTC:37744) - How should we handle PNOR errors?

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

    return l_err;
}


/********************
 Private/Protected Methods
 ********************/
mutex_t PnorDD::cv_mutex = MUTEX_INITIALIZER;

/**
 * @brief  Constructor
 */
PnorDD::PnorDD( PnorMode_t i_mode )
: iv_mode(i_mode)
{
    iv_erasesize_bytes = ERASESIZE_BYTES_DEFAULT;
    iv_erases = NULL;

    //In the normal case we will choose the mode for the caller
    if( MODEL_UNKNOWN == iv_mode )
    {
        //Use real PNOR for everything except VPO
        uint64_t vpo_override = mmio_scratch_read(MMIO_SCRATCH_PNOR_MODE);
        if(vpo_override == PNOR::VPO_MODE_OVERRIDE)
        {
            //VPO override set -- use fastest method -- memcpy
            iv_mode = MODEL_MEMCPY;
        }
        else
        {
            //Normal mode
            iv_mode = MODEL_REAL_CMD;
        }
    }

    if( MODEL_REAL_CMD == iv_mode )
    {
        sfcInit( );
    }

    TRACFCOMP(g_trac_pnor, "PnorDD::PnorDD()> Using mode %d", iv_mode);
}

/**
 * @brief  Destructor
 */
PnorDD::~PnorDD()
{
    if(iv_erases)
    {
        delete iv_erases;
    }
}

bool PnorDD::cv_sfcInitDone = false;  //Static flag to ensure we only init the SFC one time.
uint32_t PnorDD::cv_nor_chipid = 0;  //Detected NOR Flash Type

/**
 * STATIC
 * @brief Static Initializer
 */
void PnorDD::sfcInit( )
{
    TRACDCOMP(g_trac_pnor, "PnorDD::sfcInit> iv_mode=0x%.8x", iv_mode );
    errlHndl_t  l_err  =   NULL;

    //Initial configuration settings for SFC:
    #define oadrnb_init 0x04000000  //Set MMIO/Direct window to start at 64MB
    #define oadrns_init 0x0000000F  //Set the MMIO/Direct window size to 64MB
    #define adrcbf_init 0x00000000  //Set the flash index to 0
    #define adrcmf_init 0x0000000F  //Set the flash size to 64MB
    #define conf_init 0x00000002  //Disable Direct Access Cache

    do {
        mutex_lock(&cv_mutex);

        if(!cv_sfcInitDone)
        {
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

            cv_sfcInitDone = true;

            //Determine NOR Flash type, configure SFC and PNOR DD as needed
            l_err = getNORChipId(cv_nor_chipid);
            TRACFCOMP(g_trac_pnor, "PnorDD::sfcInit: cv_nor_chipid=0x%.8x> ", cv_nor_chipid );

            //TODO: Need to add support for VPO (RTC: 42325), Spansion NOR (RTC: 42326),
            //      Micron NOR (RTC: 42328), Macronix (RTC: 42330), and Simics (RTC: 42331)
            //      There will probably be some overlap between those stories, but keeping them
            //      all separate for now to ensure everything is covered.
            if(SIMICS_NOR_ID == cv_nor_chipid)
            {
                TRACFCOMP(g_trac_pnor, "PnorDD::sfcInit: Configuring SFC for SIMICS NOR> " );
                uint32_t sm_erase_op = SPI_SIM_SM_ERASE_OP;
                iv_erasesize_bytes = SPI_SIM_SM_ERASE_SZ;

                /*Simics model doesn't currently support this*/
                l_err = writeRegSfc(SFC_CMD_SPACE,
                                    SFC_REG_CONF4,
                                    sm_erase_op);
                if(l_err) { break; }


                l_err = writeRegSfc(SFC_CMD_SPACE,
                                    SFC_REG_CONF5,
                                    iv_erasesize_bytes);
                if(l_err) { break; }

                //create array to count erases.
                iv_erases = new uint8_t[PNORSIZE/iv_erasesize_bytes];
                for( uint64_t x=0; x < (PNORSIZE/iv_erasesize_bytes); x++ )
                {
                    iv_erases[x] = 0;
                }

                if(l_err) { break; }


            }
            else
            {
                TRACFCOMP( g_trac_pnor, "PnorDD::sfcInit> Unsupported NOR type detected : cv_nor_chipid=%d", cv_nor_chipid );
                /*@
                 * @errortype
                 * @moduleid     PNOR::MOD_PNORDD_SFCINIT
                 * @reasoncode   PNOR::RC_UNSUPORTED_HARDWARE
                 * @userdata1    NOR Flash Chip ID
                 * @userdata2    <not used>
                 * @devdesc      PnorDD::sfcInit>
                 */
                l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                                PNOR::MOD_PNORDD_SFCINIT,
                                                PNOR::RC_UNSUPORTED_HARDWARE,
                                                TO_UINT64(cv_nor_chipid));

                //Set chip ID back to zero to avoid later chip specific logic.
                cv_nor_chipid = 0;
            }

        }

    }while(0);

    mutex_unlock(&cv_mutex);

    if( l_err )
    {
        errlCommit(l_err,PNOR_COMP_ID);
    }


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
 * @brief Write a SFC Register
 */
errlHndl_t PnorDD::writeRegSfc(SfcRange i_range,
                               uint32_t i_addr,
                               uint32_t i_data)
{
    errlHndl_t l_err = NULL;
    uint32_t lpc_addr;

    if(SFC_CMD_SPACE == i_range)
    {
        lpc_addr = LPC_SFC_CMDREG_OFFSET | i_addr;
    } else {
        lpc_addr = LPC_SFC_CMDBUF_OFFSET | i_addr;
    }

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
    uint32_t lpc_addr;

    if(SFC_CMD_SPACE == i_range)
    {
        lpc_addr = LPC_SFC_CMDREG_OFFSET | i_addr;
    } else {
        lpc_addr = LPC_SFC_CMDBUF_OFFSET | i_addr;
    }

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

            if( sfc_stat.done == 1 )
            {
                break;
            }

            // want to start out incrementing by small numbers then get bigger
            //  to avoid a really tight loop in an error case so we'll increase
            //  the wait each time through
            //TODO tmp remove for VPO, need better polling strategy -- RTC43738
            //nanosleep( 0, SFC_POLL_INCR_NS*(++loop) );
            poll_time += SFC_POLL_INCR_NS*loop;
        }
        if( l_err ) { break; }

        // check for errors or timeout
        // TODO: What errors do we check?
        if( (sfc_stat.done == 0) )
        {
            TRACFCOMP(g_trac_pnor, "PnorDD::pollSfcOpComplete> Error or timeout from LPC Status Register" );

            /*@
             * @errortype
             * @moduleid     PNOR::MOD_PNORDD_POLLSFCOPCOMPLETE
             * @reasoncode   PNOR::RC_LPC_ERROR
             * @userdata1[0:31]   NOR Flash Chip ID
             * @userdata1[32:63]  Total poll time (ns)
             * @userdata2[0:31]    ECCB Status Register
             * @devdesc      PnorDD::readLPC> Error or timeout from
             *               LPC Status Register
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            PNOR::MOD_PNORDD_POLLSFCOPCOMPLETE,
                                            PNOR::RC_LPC_ERROR,
                                            TWO_UINT32_TO_UINT64(cv_nor_chipid,poll_time),
                                            TWO_UINT32_TO_UINT64(sfc_stat.data32,0));

            l_err->collectTrace("PNOR");
            l_err->collectTrace("XSCOM");
            //@todo (RTC:37744) - Any cleanup or recovery needed?
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
    TRACDCOMP( g_trac_pnor, "PnorDD::getNORChipId> i_spiOpcode=0x%.8x",
               i_spiOpcode );

    do {

        //Issue Get Chip ID command
        SfcCmdReg_t sfc_cmd;
        sfc_cmd.opcode = i_spiOpcode;
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
        if(l_err) {
            break;
        }

    }while(0);

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
    TRACDCOMP( g_trac_pnor, "PnorDD::flushSfcBuf> i_addr=0x%.8x, i_size=0x%.8x",
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
    errlHndl_t l_err = NULL;
    TRACDCOMP( g_trac_pnor, "PnorDD::bufferedSfcRead> i_addr=0x%.8x, i_size=0x%.8x",
               i_addr, i_size );

    do{

        if( MODEL_LPC_MEM == iv_mode )
        {
            read_fake_pnor( i_addr,
                            o_data,
                            i_size );
            break;
        }

        // Note: If we got here then iv_mode is MODEL_REAL_CMD

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
            l_err = readSfcBuffer(chunk_size,
                                  (void*)((uint64_t)o_data + (addr-i_addr)));
            if(l_err) { break;}

            addr += chunk_size;
        }
    }while(0);

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

    do{
        if( MODEL_LPC_MEM == iv_mode )
        {
            write_fake_pnor( i_addr,
                             i_data,
                             i_size );
            break;
        }

        // Note: If we got here then iv_mode is MODEL_REAL_CMD

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
    }while(0);

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
    uint32_t word_size = i_size/4;
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

    do {

        //@todo (RTC:36950) - add non-master support
        TARGETING::Target* scom_target =
          TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;

        // always read/write 64 bits to SCOM
        size_t scom_size = sizeof(uint64_t);

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
            //TODO tmp remove for VPO, need better polling strategy -- RTC43738
            //nanosleep( 0, ECCB_POLL_INCR_NS*(++loop) );
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



        // copy data out to caller's buffer
        o_data = eccb_stat.read_data;

    } while(0);

    return l_err;
}

/**
 * @brief Write an address from LPC space
 */
errlHndl_t PnorDD::writeLPC(uint32_t i_addr,
                            uint32_t i_data)
{
    errlHndl_t l_err = NULL;

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
        ControlReg_t eccb_cmd;
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


    } while(0);


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
            TRACDCOMP(g_trac_pnor,"compareAndWriteBlock>  NO Write Needed! Exiting FUnction");
            break;
        }

        //STEP 3: If the need to erase was detected, read out the rest of the Erase block
        if(need_erase)
        {
            TRACDCOMP(g_trac_pnor,"compareAndWriteBlock> Need to perform Erase");
            //Get data before write section
            if(i_writeStart > i_blockStart)
            {
                TRACDCOMP(g_trac_pnor,"compareAndWriteBlock> Reading beginning data i_blockStart=0x%.8x, readLen=0x%.8x",
                          i_blockStart, i_writeStart-i_blockStart);
                l_err = bufferedSfcRead(i_blockStart,
                                        i_writeStart-i_blockStart,
                                        read_data);
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
                if( l_err )
                {
                    break; }
            }

            // erase the flash
            TRACDCOMP(g_trac_pnor,"compareAndWriteBlock> Calling eraseFlash:. i_blockStart=0x%.8x", i_blockStart);
            l_err = eraseFlash( i_blockStart );
            if( l_err ) { break; }

            //STEP 4: Write the data back out - need to write everything since we erased the block

           //re-write data before new data to write
            if(i_writeStart > i_blockStart)
            {
                TRACDCOMP(g_trac_pnor,"compareAndWriteBlock> Writing beginning data i_blockStart=0x%.8x, readLen=0x%.8x",
                          i_blockStart, i_writeStart-i_blockStart);
                l_err = bufferedSfcWrite(i_blockStart,
                                         i_writeStart-i_blockStart,
                                         read_data);
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

    TRACDCOMP(g_trac_pnor,"<<compareAndWriteBlock() Exit");


    return l_err;
}

/**
 * @brief Erase a block of flash
 */
errlHndl_t PnorDD::eraseFlash(uint32_t i_address)
{
    errlHndl_t l_err = NULL;
    TRACDCOMP(g_trac_pnor, ">>PnorDD::eraseFlash> Block 0x%.8X", i_address );

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

        if(iv_erases)
        {
            // log the erase of this block
            iv_erases[i_address/iv_erasesize_bytes]++;
            TRACFCOMP(g_trac_pnor, "PnorDD::eraseFlash> Block 0x%.8X has %d erasures", i_address, iv_erases[i_address/iv_erasesize_bytes] );
        }

        if( (MODEL_MEMCPY == iv_mode) ||  (MODEL_LPC_MEM == iv_mode))
        {
            erase_fake_pnor( i_address, iv_erasesize_bytes );
            break; //all done
        }

        if(cv_nor_chipid != 0)
        {
            TRACDCOMP(g_trac_pnor, "PnorDD::eraseFlash> Erasing flash for cv_nor_chipid=0x%.8x, iv_mode=0x%.8x", cv_nor_chipid, iv_mode);
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

        }
        else
        {
            TRACFCOMP(g_trac_pnor, "PnorDD::eraseFlash> Erase not supported for cv_nor_chipid=%d", cv_nor_chipid );

            /*@
             * @errortype
             * @moduleid     PNOR::MOD_PNORDD_ERASEFLASH
             * @reasoncode   PNOR::RC_UNSUPPORTED_OPERATION
             * @userdata1    NOR Chip ID
             * @userdata2    LPC Address to erase
             * @devdesc      PnorDD::eraseFlash> No support for MODEL_REAL yet
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            PNOR::MOD_PNORDD_ERASEFLASH,
                                            PNOR::RC_UNSUPPORTED_OPERATION,
                                            static_cast<uint64_t>(cv_nor_chipid),
                                            i_address);
        }
    } while(0);

    return l_err;
}



/*
 This code is used in the MODEL_MEMCPY and MODEL_LPC_MEM modes
*/

#define FAKE_PNOR_START 4*MEGABYTE
#define FAKE_PNOR_END 8*MEGABYTE
#define FAKE_PNOR_SIZE 4*MEGABYTE
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


