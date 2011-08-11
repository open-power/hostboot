//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/fsi/fsidd.C $
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
 *  @file fsidd.C
 *
 *  @brief Implementation of the FSI Device Driver
 */

/*****************************************************************************/
// I n c l u d e s
/*****************************************************************************/
#include <string.h>
#include <devicefw/driverif.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <targeting/targetservice.H>
#include <errl/errlmanager.H>
#include <fsi/fsi_reasoncodes.H>
#include "fsidd.H"
#include <kernel/console.H>
#include <sys/time.h>
#include <algorithm>


// Trace definition
trace_desc_t* g_trac_fsi = NULL;
TRAC_INIT(&g_trac_fsi, "FSI", 4096); //4K

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)  


//@todo - These should come from the target/attribute code somewhere
uint64_t target_to_uint64(TARGETING::Target* i_target)
{
    uint64_t id = 0;
    if( i_target == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL )
    {
        id = 0xFFFFFFFFFFFFFFFF;
    }
    else
    {
        // class|type|model|number : 1 byte each
        id = (uint64_t)(i_target->getAttr<TARGETING::ATTR_CLASS>() & 0xFF) << 56;
        id |= (uint64_t)(i_target->getAttr<TARGETING::ATTR_TYPE>() & 0xFF) << 48;
        id |= (uint64_t)(i_target->getAttr<TARGETING::ATTR_MODEL>() & 0xFF) << 40;
        id |= 0ull << 32; //@todo-need a unit num
    }
    return id;
}

// Initialize static variables
mutex_t FsiDD::cv_mux = MUTEX_INITIALIZER;
std::vector<FsiDD*> FsiDD::cv_instances;

/**
 * @brief Select the instance for the given target
 */
FsiDD* FsiDD::getInstance( TARGETING::Target* i_target )
{
    FsiDD* inst = NULL;
    TRACUCOMP( g_trac_fsi, "FsiDD::getInstance> Looking for target : %llX", target_to_uint64(i_target) );

    mutex_lock(&cv_mux);

    for( std::vector<FsiDD*>::iterator dd = FsiDD::cv_instances.begin();
         dd != FsiDD::cv_instances.end();
         ++dd )
    {
        if( (*dd)->iv_target == i_target )
        {
            inst = *dd;
            break;
        }
    }

    // need to instantiate an object
    if( (inst == NULL)
        && (TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL != i_target) )
    {
        // only support processor targets
        //@todo - switch to PredicateCTM
        if( i_target->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_PROC )
        {
            TRACFCOMP( g_trac_fsi, "FsiDD::getInstance> Creating new instance for target : %llX", target_to_uint64(i_target) );
            inst = new FsiDD(i_target);
            FsiDD::cv_instances.push_back(inst);
        }
    }
    mutex_unlock(&cv_mux);

    return inst;
}


namespace FSI
{

/**
 * @brief Performs a FSI Read Operation
 * This function performs a FSI Read operation. It follows a pre-defined
 * prototype functions in order to be registered with the device-driver
 * framework.
 *
 * @param[in]   i_opType        Operation type, see DeviceFW::OperationType
 *                              in driverif.H
 * @param[in]   i_target        FSI target
 * @param[in/out] io_buffer     Read: Pointer to output data storage
 *                              Write: Pointer to input data storage
 * @param[in/out] io_buflen     Input: size of io_buffer (in bytes)
 *                              Output:
 *                                  Read: Size of output data
 *                                  Write: Size of data written
 * @param[in]   i_accessType    DeviceFW::AccessType enum (usrif.H)
 * @param[in]   i_args          This is an argument list for DD framework.
 *                              In this function, there's only one argument,
 *                              containing the FSI address 
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
    uint64_t i_addr = va_arg(i_args,uint64_t);
    TRACUCOMP( g_trac_fsi, "FSI::ddRead> i_addr=%llX, target=%llX", i_addr, target_to_uint64(i_target) );

    do{
        FsiDD* driver = FsiDD::getInstance(i_target);
        if( driver )
        {            
            // prefix the appropriate MFSI/cMFSI slave port
            uint64_t l_addr = driver->genFullFsiAddr( i_target, i_addr );

            // do the read
            l_err = driver->read(l_addr,
                                 io_buflen,
                                 (uint32_t*)io_buffer);
            if(l_err)
            {
                break;
            }
        }
        else
        {
            TRACFCOMP( g_trac_fsi, "FSI::ddRead> Invalid target : %llX", target_to_uint64(i_target) );
            /*@
             * @errortype
             * @moduleid     FSI::MOD_FSIDD_DDREAD
             * @reasoncode   FSI::RC_INVALID_TARGET
             * @userdata1    Target Id 
             * @userdata2    FSI Address
             * @devdesc      FSI::ddRead> Invalid target
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            FSI::MOD_FSIDD_DDREAD,
                                            FSI::RC_INVALID_TARGET,
                                            target_to_uint64(i_target),
                                            i_addr);
            break;

        }

    }while(0);

    return l_err;
}

/**
 * @brief Performs a FSI Write Operation
 * This function performs a FSI Write operation. It follows a pre-defined
 * prototype functions in order to be registered with the device-driver
 * framework.
 *
 * @param[in]   i_opType        Operation type, see DeviceFW::OperationType
 *                              in driverif.H
 * @param[in]   i_target        FSI target
 * @param[in/out] io_buffer     Read: Pointer to output data storage
 *                              Write: Pointer to input data storage
 * @param[in/out] io_buflen     Input: size of io_buffer (in bytes)
 *                              Output:
 *                                  Read: Size of output data
 *                                  Write: Size of data written
 * @param[in]   i_accessType    DeviceFW::AccessType enum (usrif.H)
 * @param[in]   i_args          This is an argument list for DD framework.
 *                              In this function, there's only one argument,
 *                              containing the FSI address 
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
    uint64_t i_addr = va_arg(i_args,uint64_t);
    TRACUCOMP( g_trac_fsi, "FSI::ddWrite> i_addr=%llX, target=%llX", i_addr, target_to_uint64(i_target) );

    do{
        FsiDD* driver = FsiDD::getInstance(i_target);
        if( driver )
        {
            // prefix the appropriate MFSI/cMFSI slave port
            uint64_t l_addr = driver->genFullFsiAddr( i_target, i_addr );

            // do the write
            l_err = driver->write(l_addr,
                                  io_buflen,
                                  (uint32_t*)io_buffer);
            if(l_err)
            {
                break;
            }
        }
        else
        {
            TRACFCOMP( g_trac_fsi, "FSI::ddWrite> Invalid target : %llX", target_to_uint64(i_target) );
            /*@
             * @errortype
             * @moduleid     FSI::MOD_FSIDD_DDWRITE
             * @reasoncode   FSI::RC_INVALID_TARGET
             * @userdata1    Target Id 
             * @userdata2    FSI Address
             * @devdesc      FSI::ddWrite> Invalid target
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            FSI::MOD_FSIDD_DDWRITE,
                                            FSI::RC_INVALID_TARGET,
                                            target_to_uint64(i_target),
                                            i_addr);
            break;

        }

    }while(0);

    return l_err;
}

// Register fsidd access functions to DD framework
DEVICE_REGISTER_ROUTE(DeviceFW::READ,
                      DeviceFW::FSI, 
                      TARGETING::TYPE_PROC,
                      ddRead);

// Register fsidd access functions to DD framework
DEVICE_REGISTER_ROUTE(DeviceFW::WRITE,
                      DeviceFW::FSI, 
                      TARGETING::TYPE_PROC,
                      ddWrite);


}; //end FSI namespace





/**
 * @brief Read FSI Register
 */
errlHndl_t FsiDD::read(uint64_t i_address,
                       size_t& io_buflen,
                       uint32_t* o_buffer)
{
    TRACDCOMP(g_trac_fsi, "FsiDD::read(i_address=0x%llx)> ", i_address);
    errlHndl_t l_err = NULL;
    bool need_unlock = false;

    do {
        // make sure we got a valid FSI address
        l_err = verifyAddressRange( i_address, io_buflen );
        if(l_err)
        {
            break;
        }

        // setup the OPB command register
        uint64_t fsicmd = i_address | 0x60000000; // 011=Read Full Word
        fsicmd <<= 32; // Command is in the upper word

        // generate the proper OPB SCOM address
        uint64_t opbaddr = genOpbScomAddr(OPB_REG_CMD);

        // atomic section >>
        mutex_lock(&iv_fsiMutex);
        need_unlock = true;

        // always read/write 64 bits to SCOM
        size_t scom_size = sizeof(uint64_t);

        // write the OPB command register to trigger the read
        TRACUCOMP(g_trac_fsi, "FsiDD::read> ScomWRITE : opbaddr=%.16llX, data=%.16llX", opbaddr, fsicmd );
        l_err = deviceOp( DeviceFW::WRITE,
                          iv_target,
                          &fsicmd,
                          scom_size,
                          DEVICE_SCOM_ADDRESS(opbaddr) );
        if( l_err )
        {
            TRACFCOMP(g_trac_fsi, "FsiDD::read> Error from device 1 : RC=%X", l_err->reasonCode() );
            break;
        }

        // poll for complete and get the data back   
        l_err = pollForComplete( i_address, o_buffer );
        if( l_err )
        {
            break;
        }

        io_buflen = 4;

        // atomic section <<
        need_unlock = false;
        mutex_unlock(&iv_fsiMutex);

    } while(0);

    if( need_unlock )
    {
        mutex_unlock(&iv_fsiMutex);
    }

    if( l_err )
    {
        io_buflen = 0;
    }

    return l_err;
}

/**
 * @brief Write FSI Register
 */
errlHndl_t FsiDD::write(uint64_t i_address,
                        size_t& io_buflen,
                        uint32_t* i_buffer)
{
    TRACDCOMP(g_trac_fsi, "FsiDD::write(i_address=0x%llx)> ", i_address);
    errlHndl_t l_err = NULL;
    bool need_unlock = false;

    do {
        // make sure we got an FSI address
        l_err = verifyAddressRange( i_address, io_buflen );
        if(l_err)
        {
            break;
        }

        // pull out the data to write (length has been verified)
        uint32_t fsidata = *i_buffer;

        // setup the OPB command register
        uint64_t fsicmd = i_address | 0xE0000000; // 111=Write Full Word
        fsicmd <<= 32; // Command is in the upper 32-bits
        fsicmd |= fsidata; // Data is in the bottom 32-bits
        size_t scom_size = sizeof(uint64_t);

        // generate the proper OPB SCOM address
        uint64_t opbaddr = genOpbScomAddr(OPB_REG_CMD);

        // atomic section >>
        mutex_lock(&iv_fsiMutex);
        need_unlock = true;

        // write the OPB command register
        TRACUCOMP(g_trac_fsi, "FsiDD::write> ScomWRITE : opbaddr=%.16llX, data=%.16llX", opbaddr, fsicmd );
        l_err = deviceOp( DeviceFW::WRITE,
                          iv_target,
                          &fsicmd,
                          scom_size,
                          DEVICE_SCOM_ADDRESS(opbaddr) );
        if( l_err )
        {
            TRACFCOMP(g_trac_fsi, "FsiDD::write> Error from device : RC=%X", l_err->reasonCode() );
            break;
        }

        // poll for complete (no return data)
        l_err = pollForComplete( i_address, NULL );
        if( l_err )
        {
            break;
        }

        io_buflen = 4;

        // atomic section <<
        need_unlock = false;
        mutex_unlock(&iv_fsiMutex);

    } while(0);

    if( need_unlock )
    {
        mutex_unlock(&iv_fsiMutex);
    }

    if( l_err )
    {
        io_buflen = 0;
    }

    TRACDCOMP(g_trac_fsi, "< FsiDD::write() ", i_address);

    return l_err;
}


/**
 * @brief  Constructor
 */
FsiDD::FsiDD( TARGETING::Target* i_target )
:iv_target(i_target)
{
    TRACFCOMP(g_trac_fsi, "FsiDD::FsiDD()> target=%llX", target_to_uint64(i_target) );

    mutex_init(&iv_fsiMutex);
}

/**
 * @brief  Destructor
 */
FsiDD::~FsiDD()
{
    // remove this instance from the global list
    FsiDD::cv_instances.erase(
                              std::find(cv_instances.begin(),
                                        cv_instances.end(),
                                        this)
                              );
}

/**
 * @brief Verify Request is in appropriate address range
 */
errlHndl_t FsiDD::verifyAddressRange(uint64_t i_address,
                                     size_t i_length)
{
    errlHndl_t l_err = NULL;

    do{
        //@todo - add more address checks

        // no port specified
        if( (i_address & (MFSI_PORT_MASK|CMFSI_PORT_MASK|CONTROL_REG_MASK)) == 0 )
        {
            TRACFCOMP( g_trac_fsi, "FsiDD::verifyAddressRange> Invalid address : i_address=0x%X", i_address );
            /*@
             * @errortype
             * @moduleid     FSI::MOD_FSIDD_VERIFYADDRESSRANGE
             * @reasoncode   FSI::RC_INVALID_ADDRESS
             * @userdata1    FSI Address
             * @userdata2    Data Length
             * @devdesc      FsiDD::verifyAddressRange> Invalid address
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            FSI::MOD_FSIDD_VERIFYADDRESSRANGE,
                                            FSI::RC_INVALID_ADDRESS,
                                            i_address,
                                            TO_UINT64(i_length));
            break;
        }

        if( i_length != 4 )
        {
            TRACFCOMP( g_trac_fsi, "FsiDD::verifyAddressRange> Invalid data length : i_length=%d", i_length );
            /*@
             * @errortype
             * @moduleid     FSI::MOD_FSIDD_VERIFYADDRESSRANGE
             * @reasoncode   FSI::RC_INVALID_LENGTH
             * @userdata1    FSI Address
             * @userdata2    Data Length
             * @devdesc      FsiDD::verifyAddressRange> Invalid data length
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            FSI::MOD_FSIDD_VERIFYADDRESSRANGE,
                                            FSI::RC_INVALID_LENGTH,
                                            i_address,
                                            TO_UINT64(i_length));
            break;
        }


    }while(0);

    return l_err;
}


/**
 * @brief Analyze error bits and recover hardware as needed
 */
errlHndl_t FsiDD::handleOpbErrors(TARGETING::Target* i_target,
                                  uint64_t i_address,
                                  uint32_t i_opbStatReg)
{
    errlHndl_t l_err = NULL;

    if( (i_opbStatReg & OPB_STAT_ERR_ANY) 
        || (i_opbStatReg & OPB_STAT_BUSY) )
    {
        TRACFCOMP( g_trac_fsi, "FsiDD::handleOpbErrors> Error during FSI access : i_address=0x%X, OPB Status=0x%.8X", i_address, i_opbStatReg );


        /*@
         * @errortype
         * @moduleid     FSI::MOD_FSIDD_HANDLEOPBERRORS
         * @reasoncode   FSI::RC_OPB_ERROR
         * @userdata1    FSI Address
         * @userdata2    OPB Status Register
         * @devdesc      FsiDD::handleOpbErrors> Error during FSI access
         */
        l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        FSI::MOD_FSIDD_HANDLEOPBERRORS,
                                        FSI::RC_OPB_ERROR,
                                        i_address,
                                        TWO_UINT32_TO_UINT64(i_opbStatReg,0));
        //@todo - figure out best data to log

        //@todo - implement recovery and callout code

    }

    return l_err;
}

/**
 * @brief  Poll for completion of a FSI operation, return data on read
 */
errlHndl_t FsiDD::pollForComplete(uint64_t i_address,
                                  uint32_t* o_readData)
{
    errlHndl_t l_err = NULL;

    do {
        // poll for complete
        uint32_t read_data[2];
        size_t scom_size = sizeof(uint64_t);
        uint64_t opbaddr = genOpbScomAddr(OPB_REG_STAT);
        int attempts = 0;
        do
        {
            TRACUCOMP(g_trac_fsi, "FsiDD::pollForComplete> ScomREAD : opbaddr=%.16llX", opbaddr );
            l_err = deviceOp( DeviceFW::READ,
                              iv_target,
                              read_data,
                              scom_size,
                              DEVICE_SCOM_ADDRESS(opbaddr) );
            if( l_err )
            {
                TRACFCOMP(g_trac_fsi, "FsiDD::pollForComplete> Error from device 2 : RC=%X", l_err->reasonCode() );
                break;
            }

            //@fixme - Simics model is broken on writes, just assume completion
            if( !o_readData )
            {
                read_data[0] &= ~OPB_STAT_BUSY;
            }

            // check for completion or error
            TRACUCOMP(g_trac_fsi, "FsiDD::pollForComplete> ScomREAD : read_data[0]=%.8llX", read_data[0] );
            if( ((read_data[0] & OPB_STAT_BUSY) == 0)  //not busy
                || (read_data[0] & OPB_STAT_ERR_ANY) ) //error bits
            {
                break;
            }

            attempts++;
        } while( attempts < MAX_OPB_ATTEMPTS );
        if( l_err ) { break; }
        //@todo - hw has a 1ms watchdog, do I need to have a limit or just
        //        loop until we hit an error

        // check if we got an error
        l_err = handleOpbErrors( iv_target, i_address, read_data[0] );
        if( l_err )
        {
            break;
        }

        //@todo - is this possible?  Ask hw team
        // read valid isn't on
        if( o_readData )  // only check if we're doing a read
        {
            if( !(read_data[0] & OPB_STAT_READ_VALID) )
            {           
                TRACFCOMP( g_trac_fsi, "FsiDD::read> Read valid never came on : i_address=0x%X, OPB Status=0x%.8X", i_address, read_data[0] );
                //@todo - create error log
                break;
            }

            *o_readData = read_data[1];
        }

    } while(0);

    return l_err;
}

/**
 * @brief Generate a complete FSI address based on the target and the
 *    FSI offset within that target
 */
uint64_t FsiDD::genFullFsiAddr(TARGETING::Target* i_target,
                               uint64_t i_address)
{
    //@todo - fill this in, for now just return the address as-is
    return i_address;

    //target matches my target so the address is correct as-is
    if( i_target == iv_target )
    {
        return i_address;
    }
    //target is another proc so need to use the appropriate MFSI port
    else if( i_target->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_PROC )
    {
        //@todo - use attribute to figure out which MFSI_PORT_x to use
        TRACFCOMP( g_trac_fsi, "FsiDD::genFullFsiAddr> MFSI targets aren't supported yet : i_target=%llX", target_to_uint64(i_target) );
        assert(0);
    }
    //target is a centaur so need to use the appropriate cMFSI port
    else if( i_target->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_MEMBUF )
    {
        //@todo - use attribute to figure out which CMFSI_PORT_x to use
        TRACFCOMP( g_trac_fsi, "FsiDD::genFullFsiAddr> CMFSI targets aren't supported yet : i_target=%llX", target_to_uint64(i_target) );
        assert(0);
    }
    else
    {
        TRACFCOMP( g_trac_fsi, "FsiDD::genFullFsiAddr> Unknown target type : i_target=%llX", target_to_uint64(i_target) );
        assert(0);
    }
}

/**
 * @brief Generate a valid SCOM address to access the OPB, this will
 *    choosing the correct master
 */
uint64_t FsiDD::genOpbScomAddr(uint64_t i_opbOffset)
{
    //@todo: handle redundant FSI ports, always using zero for now
    uint64_t opbaddr = FSI2OPB_OFFSET_0 | i_opbOffset;
    return opbaddr;
}

//@todo - IGNORE THIS FOR NOW
/** 
 * @brief Initializes the FSI bus for the given slave 
 */
errlHndl_t FsiDD::initSlave(TARGETING::Target* i_target)
{
    errlHndl_t l_err = NULL;
    size_t regsize = sizeof(uint32_t);

    do {
        uint64_t masteroffset = MFSI_CONTROL_REG; //call some function to get this


        //figure out which port this target is on
        uint64_t port = 0; //getAttr<TYPE_FSI_SLAVE_PORT>?        
        uint32_t portbit = 0x80000000 >> port;

        //see if the slave is present
        uint32_t readbuf = 0;
        l_err = read( masteroffset|0x018, regsize, &readbuf );
        if( l_err ) { break; }

        if( !(readbuf & portbit) )
        {
            TRACFCOMP( g_trac_fsi, "FsiDD::initSlave> Target %llX is not present : Reg 0x018=%lX", target_to_uint64(i_target), readbuf );
            //@todo - create error log for non-present slave?
        }

        //choose clock ratio,delay selection        
        l_err = write( masteroffset|0x008, regsize, &portbit );
        if( l_err ) { break; }

        //enable the port
        l_err = write( masteroffset|0x018, regsize, &portbit );
        if( l_err ) { break; }

        //reset the port
        l_err = write( masteroffset|0x008, regsize, &portbit );
        if( l_err ) { break; }

    } while(0);

    return l_err;
}

//@todo - IGNORE THIS FOR NOW
/**
 * @brief Initializes the FSI master control registers
 *
 * @return errlHndl_t  NULL on success
 */
errlHndl_t FsiDD::initMaster()
{
    errlHndl_t l_err = NULL;

    do {
        //@todo - loop to hit MFSI_CONTROL_REG and CMFSI_CONTROL_REG range?

        // Mode Register
        //  1: Enable hardware error recovery
        //uint32_t clock_ratio0 = 100; //iv_target->getAttr<TARGETING::>()
        //uint32_t mode_reg = 0;

    } while(0);

    return l_err;
}
