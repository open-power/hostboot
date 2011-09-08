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
#include "fsidd.H"
#include <fsi/fsi_reasoncodes.H>
#include <devicefw/driverif.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <targeting/targetservice.H>
#include <errl/errlmanager.H>
#include <initservice/taskargs.H> 
#include <targeting/predicates/predicatectm.H>
#include <sys/time.h>
#include <string.h>
#include <algorithm>

//@todo : Create common id for master+type+port to use in error logs and traces


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

//@todo - remove this when attribute call is ready
FSI::FsiChipInfo_t temp_attr_call(TARGETING::Target* i_target)
{
    FSI::FsiChipInfo_t info;

    // just defaulting everything to the local master for now
    TARGETING::TargetService& targetService = TARGETING::targetService();
    targetService.masterProcChipTargetHandle( info.master );

    if( i_target->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_PROC )
    {
        info.type = FSI::MFSI_TYPE;
        info.port = 0;
    }
    else
    {
        info.type = FSI::CMFSI_TYPE;
        info.port = 0;
    }

    info.cascade = 0;
    info.attributes = 0;

    TRACUCOMP( g_trac_fsi, "temp_attr_call> i_target=%llX : type=%X, port=%X, cascade=%X, attributes=%llX", target_to_uint64(i_target), info.type, info.port, info.cascade, info.attributes );
    return info;
}


namespace FSI
{

//@todo - combine ddRead/ddWrite into a single function ?

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
        if( io_buflen != sizeof(uint32_t) )
        {
            TRACFCOMP( g_trac_fsi, "FsiDD::ddRead> Invalid data length : io_buflen=%d", io_buflen );
            /*@
             * @errortype
             * @moduleid     FSI::MOD_FSIDD_DDREAD
             * @reasoncode   FSI::RC_INVALID_LENGTH
             * @userdata1    FSI Address
             * @userdata2    Data Length
             * @devdesc      FsiDD::ddRead> Invalid data length
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            FSI::MOD_FSIDD_DDREAD,
                                            FSI::RC_INVALID_LENGTH,
                                            i_addr,
                                            TO_UINT64(io_buflen));
            break;
        }

        // default to the fail path
        io_buflen = 0;

        // do the read
        l_err = Singleton<FsiDD>::instance().read(i_target,
                                                  i_addr,
                                                  static_cast<uint32_t*>(io_buffer));
        if(l_err)
        {
            break;
        }
        io_buflen = sizeof(uint32_t);

    }while(0);

    return l_err;
}

/**
 * @brief Perform a FSI Write Operation
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
        if( io_buflen != sizeof(uint32_t) )
        {
            TRACFCOMP( g_trac_fsi, "FsiDD::ddWrite> Invalid data length : io_buflen=%d", io_buflen );
            /*@
             * @errortype
             * @moduleid     FSI::MOD_FSIDD_DDWRITE
             * @reasoncode   FSI::RC_INVALID_LENGTH
             * @userdata1    FSI Address
             * @userdata2    Data Length
             * @devdesc      FsiDD::ddWrite> Invalid data length
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            FSI::MOD_FSIDD_DDWRITE,
                                            FSI::RC_INVALID_LENGTH,
                                            i_addr,
                                            TO_UINT64(io_buflen));
            break;
        }

        // default to the fail path
        io_buflen = 0;

        // do the write
        l_err = Singleton<FsiDD>::instance().write(i_target,
                                                   i_addr,
                                                   static_cast<uint32_t*>(io_buffer));
        if(l_err)
        {
            break;
        }
        io_buflen = sizeof(uint32_t);

    }while(0);

    return l_err;
}

// Register fsidd access functions to DD framework
DEVICE_REGISTER_ROUTE(DeviceFW::READ,
                      DeviceFW::FSI, 
                      TARGETING::TYPE_PROC,
                      ddRead);
DEVICE_REGISTER_ROUTE(DeviceFW::READ,
                      DeviceFW::FSI, 
                      TARGETING::TYPE_MEMBUF,
                      ddRead);

// Register fsidd access functions to DD framework
DEVICE_REGISTER_ROUTE(DeviceFW::WRITE,
                      DeviceFW::FSI, 
                      TARGETING::TYPE_PROC,
                      ddWrite);
DEVICE_REGISTER_ROUTE(DeviceFW::WRITE,
                      DeviceFW::FSI, 
                      TARGETING::TYPE_MEMBUF,
                      ddWrite);


// Initialize all visible FSI masters
errlHndl_t initializeHardware( uint64_t& o_numPorts )
{
    return Singleton<FsiDD>::instance().initializeHardware(o_numPorts);
}


}; //end FSI namespace


/**
 * @brief   set up _start() task entry procedure for PNOR daemon
 */
TASK_ENTRY_MACRO( FsiDD::init );


/********************
 Public Methods
 ********************/

/**
 * STATIC
 * @brief Static Initializer
 */
void FsiDD::init( void* i_taskArgs )
{
    TRACFCOMP(g_trac_fsi, "FsiDD::init> " );
    // nothing to do here...
}




/**
 * @brief Performs an FSI Read Operation to a relative address
 */
errlHndl_t FsiDD::read(TARGETING::Target* i_target,
                       uint64_t i_address,
                       uint32_t* o_buffer)
{
    TRACDCOMP(g_trac_fsi, "FsiDD::read(i_target=%llX,i_address=0x%llX)> ", target_to_uint64(i_target), i_address);
    errlHndl_t l_err = NULL;

    do {
        // prefix the appropriate MFSI/cMFSI slave port offset
        uint64_t l_addr = genFullFsiAddr( i_target, i_address );

        // make sure we got a valid FSI address
        l_err = verifyAddressRange( l_addr );
        if(l_err)
        {
            break;
        }

        // perform the read operation
        l_err = read( l_addr, o_buffer );
        if(l_err)
        {
            break;
        }
    } while(0);

    return l_err;
}

/**
 * @brief Performs an FSI Write Operation to a relative address
 */
errlHndl_t FsiDD::write(TARGETING::Target* i_target,
                        uint64_t i_address,
                        uint32_t* i_buffer)
{
    TRACDCOMP(g_trac_fsi, "FsiDD::write(i_target=%llX,i_address=0x%llX)> ", target_to_uint64(i_target), i_address);
    errlHndl_t l_err = NULL;

    do {
        // prefix the appropriate MFSI/cMFSI slave port offset
        uint64_t l_addr = genFullFsiAddr( i_target, i_address );

        // make sure we got a valid FSI address
        l_err = verifyAddressRange( l_addr );
        if(l_err)
        {
            break;
        }

        // perform the write operation
        l_err = write( l_addr, i_buffer );
        if(l_err)
        {
            break;
        }
    } while(0);

    return l_err;
}

// local type used inside FsiDD::initializeHardware()
//  must be declared outside the function to make compiler happy
struct remote_info_t {
    TARGETING::Target* master;
    uint8_t slave_port;
};

/**
 * @brief Initialize the FSI hardware
 */
errlHndl_t FsiDD::initializeHardware( uint64_t& o_numPorts )
{
    errlHndl_t l_err = NULL;
    TRACUCOMP( g_trac_fsi, "FSI::initializeHardware>" );
    o_numPorts = 0;

    do{
        // list of ports off of local MFSI
        std::list<uint64_t> local_mfsi;

        // list of ports off of local cMFSI
        std::list<uint64_t> local_cmfsi;

        // list of ports off of remote cMFSI
        std::list<TARGETING::Target*> remote_masters;

        // list of ports off of remote cMFSI
        std::list<remote_info_t> remote_cmfsi;

        FSI::FsiChipInfo_t info;

        // loop through every CHIP target
        TARGETING::PredicateCTM l_chipClass(TARGETING::CLASS_CHIP,
                                            TARGETING::TYPE_NA,
                                            TARGETING::MODEL_NA);
        TARGETING::TargetService& targetService = TARGETING::targetService();
        TARGETING::TargetIterator t_itr = targetService.begin();
        while( t_itr != targetService.end() )
        {
            // Sorting into buckets because we must maintain the init order
            //  the MFSI port that goes out to a remove cMFSI driver
            //  must be initialized before we can deal with the cMFSI port
            if( l_chipClass(*t_itr) )
            {
                info = temp_attr_call(*t_itr);

                if( info.type == FSI::MFSI_TYPE )
                {
                    local_mfsi.push_back(info.port);
                }
                else if( info.type == FSI::CMFSI_TYPE )
                {
                      if( info.master == iv_master )
                      {
                          local_cmfsi.push_back(info.port);
                      }
                      else
                      {
                          // add all unique masters to the list
                          if( remote_masters.end() ==
                              std::find(remote_masters.begin(),
                                        remote_masters.end(),
                                        info.master) )
                          {
                              remote_masters.push_back( info.master );
                          }

                          remote_info_t tmp = {info.master,info.port};
                          remote_cmfsi.push_back( tmp );
                      }
                }
            }

            ++t_itr;
        }

        // setup the local master control regs for the MFSI
        l_err = initMasterControl(iv_master,FSI::MFSI_TYPE);
        if( l_err )
        {
            break;
        }

        // initialize all of the local MFSI ports
        for( std::list<uint64_t>::iterator itr = local_mfsi.begin();
             itr != local_mfsi.end();
             ++itr )
        {
            l_err = initPort( iv_master, FSI::MFSI_TYPE, *itr );
            if( l_err )
            {
                //@todo - append the actual slave target to FFDC
                // commit the log here so that we can move on to next port               
                errlCommit(l_err);
            }
            else
            {
                o_numPorts++;
            }
        }

        // setup the local master control regs for the cMFSI
        l_err = initMasterControl(iv_master,FSI::CMFSI_TYPE);
        if( l_err )
        {
            break;
        }

        // initialize all of the local cMFSI ports
        for( std::list<uint64_t>::iterator itr = local_cmfsi.begin();
             itr != local_cmfsi.end();
             ++itr )
        {
            l_err = initPort( iv_master, FSI::CMFSI_TYPE, *itr );
            if( l_err )
            {
                //@todo - append the actual slave target to FFDC
                // commit the log here so that we can move on to next port               
                errlCommit(l_err);
            }
            else
            {
                o_numPorts++;
            }
        }

        // initialize all of the remote cMFSI masters
        for( std::list<TARGETING::Target*>::iterator itr
             = remote_masters.begin();
             itr != remote_masters.end();
             ++itr )
        {
            l_err = initMasterControl(*itr,FSI::CMFSI_TYPE);
            if( l_err )
            {
                // commit the log here so that we can move on to next port               
                errlCommit(l_err);
            }
        }

        // initialize all of the remote cMFSI ports
        for( std::list<remote_info_t>::iterator itr = remote_cmfsi.begin();
             itr != remote_cmfsi.end();
             ++itr )
        {
            l_err = initPort( itr->master, FSI::CMFSI_TYPE, itr->slave_port );
            if( l_err )
            {
                //@todo - append the actual slave target to FFDC
                // commit the log here so that we can move on to next port               
                errlCommit(l_err);
            }
            else
            {
                o_numPorts++;
            }
        }

    } while(0);

    return l_err;
}


/********************
 Internal Methods
 ********************/

/**
 * @brief  Constructor
 */
FsiDD::FsiDD()
:iv_master(NULL)
{
    TRACFCOMP(g_trac_fsi, "FsiDD::FsiDD()>");

    mutex_init(&iv_fsiMutex);

    for( uint64_t x=0; x < (sizeof(iv_slaves)/sizeof(iv_slaves[0])); x++ )
    {
        iv_slaves[x] = 0;
    }

    // save away the master processor target
    TARGETING::TargetService& targetService = TARGETING::targetService();
    iv_master = NULL;
    targetService.masterProcChipTargetHandle( iv_master );
}

/**
 * @brief  Destructor
 */
FsiDD::~FsiDD()
{
    //nothing to do right now...
}


/**
 * @brief Performs an FSI Read Operation
 */
errlHndl_t FsiDD::read(uint64_t i_address,
                       uint32_t* o_buffer)
{
    TRACDCOMP(g_trac_fsi, "FsiDD::read(i_address=0x%llx)> ", i_address);
    errlHndl_t l_err = NULL;
    bool need_unlock = false;

    do {
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
                          iv_master,
                          &fsicmd,
                          scom_size,
                          DEVICE_XSCOM_ADDRESS(opbaddr) );
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

        // atomic section <<
        need_unlock = false;
        mutex_unlock(&iv_fsiMutex);

        TRACSCOMP(g_trac_fsi, "FSI READ  : %.6X = %.8X", i_address, *o_buffer );
    } while(0);

    if( need_unlock )
    {
        mutex_unlock(&iv_fsiMutex);
    }

    return l_err;
}

/**
 * @brief Write FSI Register
 */
errlHndl_t FsiDD::write(uint64_t i_address,
                        uint32_t* i_buffer)
{
    TRACDCOMP(g_trac_fsi, "FsiDD::write(i_address=0x%llx)> ", i_address);
    errlHndl_t l_err = NULL;
    bool need_unlock = false;

    do {
        TRACSCOMP(g_trac_fsi, "FSI WRITE : %.6X = %.8X", i_address, *i_buffer );

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
                          iv_master,
                          &fsicmd,
                          scom_size,
                          DEVICE_XSCOM_ADDRESS(opbaddr) );
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

        // atomic section <<
        need_unlock = false;
        mutex_unlock(&iv_fsiMutex);

    } while(0);

    if( need_unlock )
    {
        mutex_unlock(&iv_fsiMutex);
    }

    TRACDCOMP(g_trac_fsi, "< FsiDD::write() ", i_address);

    return l_err;
}


/**
 * @brief Verify Request is in appropriate address range
 */
errlHndl_t FsiDD::verifyAddressRange(uint64_t i_address)
{
    errlHndl_t l_err = NULL;

    do{
        //@fixme - is this needed at all???

        //for every target except the master, only access CFAM addresses

        // no port specified
        if( (i_address & (MFSI_PORT_MASK|CMFSI_PORT_MASK|CONTROL_REG_MASK)) == 0 )
        {
            TRACFCOMP( g_trac_fsi, "FsiDD::verifyAddressRange> Invalid address : i_address=0x%X", i_address );
            /*@
             * @errortype
             * @moduleid     FSI::MOD_FSIDD_VERIFYADDRESSRANGE
             * @reasoncode   FSI::RC_INVALID_ADDRESS
             * @userdata1    FSI Address
             * @userdata2    <unused>
             * @devdesc      FsiDD::verifyAddressRange> Invalid address
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            FSI::MOD_FSIDD_VERIFYADDRESSRANGE,
                                            FSI::RC_INVALID_ADDRESS,
                                            i_address,
                                            0);
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
                              iv_master,
                              read_data,
                              scom_size,
                              DEVICE_XSCOM_ADDRESS(opbaddr) );
            if( l_err )
            {
                TRACFCOMP(g_trac_fsi, "FsiDD::pollForComplete> Error from device 2 : RC=%X", l_err->reasonCode() );
                break;
            }

            //@fixme - Simics model is broken on writes, just assume completion
            //  see Defect SW101420
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

        // we should never timeout because the hardware should set an error
        assert( attempts < MAX_OPB_ATTEMPTS );

        // check if we got an error
        l_err = handleOpbErrors( iv_master, i_address, read_data[0] );
        if( l_err )
        {
            break;
        }

        // read valid isn't on
        if( o_readData )  // only check if we're doing a read
        {
            if( !(read_data[0] & OPB_STAT_READ_VALID) )
            {           
                TRACFCOMP( g_trac_fsi, "FsiDD::read> Read valid never came on : i_address=0x%X, OPB Status=0x%.8X", i_address, read_data[0] );
                /*@
                 * @errortype
                 * @moduleid     FSI::MOD_FSIDD_POLLFORCOMPLETE
                 * @reasoncode   FSI::RC_OPB_NO_READ_VALID
                 * @userdata1    FSI Address being read
                 * @userdata2    OPB Status Register
                 * @devdesc      FsiDD::handleOpbErrors> Error during FSI access
                 */
                l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                                FSI::MOD_FSIDD_POLLFORCOMPLETE,
                                                FSI::RC_OPB_NO_READ_VALID,
                                                i_address,
                                                TWO_UINT32_TO_UINT64(read_data[0],read_data[1]));
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
    //target matches master so the address is correct as-is
    if( i_target == iv_master )
    {
        return i_address;
    }

    uint64_t l_addr = i_address;

    //pull the FSI info out for this target
    FSI::FsiChipInfo_t fsi_info = temp_attr_call( i_target );

    //FSI master is the master proc, find the port
    if( fsi_info.master == iv_master )
    {
        //append the appropriate offset
        l_addr += getPortOffset(fsi_info.type,fsi_info.port);
    }
    //target is another proc 
    else 
    {
        //must be cMFSI or there are problems with system definition
        assert( FSI::CMFSI_TYPE == fsi_info.type );

        //append the CMFSI portion first
        l_addr += getPortOffset(fsi_info.type,fsi_info.port);

        //find this port's master and then get its port information
        FSI::FsiChipInfo_t mfsi_info = temp_attr_call(fsi_info.master);
        assert( mfsi_info.master == iv_master ); //invalid topology
        assert( FSI::MFSI_TYPE == fsi_info.type ); //invalid topology

        //append the MFSI port
        l_addr += getPortOffset(mfsi_info.type,mfsi_info.port);
    }

    return l_addr;
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

/** 
 * @brief Initializes the FSI link to allow slave access
 */
errlHndl_t FsiDD::initPort(TARGETING::Target* i_master,
                           FSI::MasterType i_type,
                           uint64_t i_port)
{
    errlHndl_t l_err = NULL;
    TRACFCOMP( g_trac_fsi, ENTER_MRK"FsiDD::initPort> Initializing %llX, port %llX", target_to_uint64(i_master), i_port );

    do {
        uint32_t databuf = 0;

        uint8_t portbit = 0x80 >> i_port;

        // need to add the extra MFSI port offset for a remote cMFSI
        uint64_t master_offset = 0;
        if( (FSI::CMFSI_TYPE == i_type) && (i_master != iv_master) )
        {
            // look up the FSI information for this target's master
            FSI::FsiChipInfo_t mfsi_info = temp_attr_call(i_master);

            // append the master's port offset to the slave's
            master_offset = getPortOffset( FSI::MFSI_TYPE, mfsi_info.port );
        }      

        // control register is determined by the type of port
        uint64_t master_ctl_reg = getControlReg(i_type);
        master_ctl_reg += master_offset;

        // slave offset is determined by which port it is on
        uint64_t slave_offset = getPortOffset( i_type, i_port );
        slave_offset += master_offset;


        //Make sure this port has something on it
        uint64_t slave_index = getSlaveEnableIndex(i_master,i_type);
        if( !(iv_slaves[slave_index] & portbit) )
        {
            TRACFCOMP( g_trac_fsi, "FsiDD::initPort> Target %llX is not present : sensebits=%.2X, portbit=%.2X", target_to_uint64(i_master), iv_slaves[slave_index], portbit );
            /*@
             * @errortype
             * @moduleid     FSI::MOD_FSIDD_INITPORT
             * @reasoncode   FSI::RC_INVALID_TARGET
             * @userdata1    Target Id of Master
             * @userdata2    Port bit | MLEVP0 from master
             * @devdesc      FsiDD::initPort> FSI slave port is not installed
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                       FSI::MOD_FSIDD_INITPORT,
                       FSI::RC_INVALID_TARGET,
                       target_to_uint64(i_master),
                       TWO_UINT32_TO_UINT64(TO_UINT32(portbit),TO_UINT32(iv_slaves[slave_index])));
            break;
        }


        //Write the port enable (enables clocks for FSI link)
        databuf = static_cast<uint32_t>(portbit) << 24;
        l_err = write( master_ctl_reg|FSI_MLEVP0_018, &databuf );
        if( l_err ) { break; }

        //Send the BREAK command to all slaves on this port (target slave0)
        //  part of FSI definition, write magic string into address zero
        databuf = 0xC0DE0000;
        l_err = write( slave_offset|0x00, &databuf );
        if( l_err ) { break; }

        //check for errors
        l_err = read( master_ctl_reg|FSI_MAEB_070, &databuf );
        if( l_err ) { break; }
        if( databuf != 0 )
        {
            TRACFCOMP( g_trac_fsi, "FsiDD::initPort> Error after break to port %d:%d off %llX, MAEB=%lX", i_type, i_port, target_to_uint64(i_master), databuf );
            /*@
             * @errortype
             * @moduleid     FSI::MOD_FSIDD_INITPORT
             * @reasoncode   FSI::RC_ERROR_ENABLING_SLAVE
             * @userdata1    Target Id of Master
             * @userdata2    Port | MAEB from master
             * @devdesc      FsiDD::initPort> Error after sending BREAK
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                       FSI::MOD_FSIDD_INITPORT,
                       FSI::RC_ERROR_ENABLING_SLAVE,
                       target_to_uint64(i_master),
                       TWO_UINT32_TO_UINT64(TO_UINT32(i_port),databuf));
            break;
        }

        // Note: need to write to 3rd slave spot because the BREAK
        //   resets everything to that window
        //@fixme - Simics doesn't agree with this...

        //Setup the FSI slave to enable HW recovery, lbus ratio 
        // 2= Enable HW error recovery (bit 2)
        // 6:7=	Slave ID: 3 (default) 
        // 8:11= Echo delay: 0xF (default) 
        // 12:15= Send delay cycles: 0xF
        // 20:23= Local bus ratio: 0x1  
        databuf = 0x23FF0100;
        l_err = write( slave_offset|FSIS_MODE_00, &databuf );
        if( l_err ) { break; }

        //Note - this is a separate write because we want to have HW recovery
        //  enabled when we switch the window
        //Set FSI slave ID to 0 (move slave to 1st 2MB address window)
        // 6:7=	Slave ID: 0 
        databuf = 0x20FF0100;
        l_err = write( slave_offset|FSIS_MODE_00, &databuf );
        if( l_err ) { break; }

        //Note : from here on use the real cascade offset


#if 0 // skipping the config space reading because we're hardcoding engines
        //Read the config space
        for( uint64_t config_addr = slave_offset|FSIS_CFG_TABLE;
             config_addr < (slave_offset|FSIS_PEEK_TABLE);
             config_addr += 4 )
        {
            // read the entry
            l_err = read( config_addr, &databuf );
            if( l_err ) { break; }

            // if bit0==0 then we're through all of the engines
            if( databuf & 0x80000000 )
            {
                break;
            }
        }
#endif

        // No support for slave cascades so we're done

    } while(0);

    TRACDCOMP( g_trac_fsi, EXIT_MRK"FsiDD::initPort" );
    return l_err;
}

/**
 * @brief Initializes the FSI master control registers
 */
errlHndl_t FsiDD::initMasterControl(TARGETING::Target* i_master,
                                    FSI::MasterType i_type)
{
    errlHndl_t l_err = NULL;
    TRACFCOMP( g_trac_fsi, ENTER_MRK"FsiDD::initMasterControl> Initializing %llX:%d", target_to_uint64(i_master), i_type );

    do {
        uint32_t databuf = 0;

        //find the full offset to the master control reg
        //  first get the address of the control reg to use
        uint64_t ctl_reg = getControlReg(i_type);
        //  append the master port offset to get to the remote master
        if( i_master != iv_master )
        {
            FSI::FsiChipInfo_t m_info = temp_attr_call(i_master);
            ctl_reg += getPortOffset(FSI::MFSI_TYPE,m_info.port);
        }


        //Clear fsi port errors and general reset on all ports
        for( uint32_t port = 0; port < MAX_SLAVE_PORTS; ++port )
        {
            // 2= General reset to all bridges
            // 3= General reset to all port controllers
            databuf = 0x30000000;
            l_err = write( ctl_reg|FSI_MRESP0_0D0|port, &databuf );
            if( l_err ) { break; }
        }
        if( l_err ) { break; }


        //Freeze FSI Port on FSI/OPB bridge error (global)
        // 18= Freeze FSI port on FSI/OPB bridge error
        databuf = 0x00002000;
        l_err = write( ctl_reg|FSI_MECTRL_2E0, &databuf );
        if( l_err ) { break; }


        //Set MMODE reg to enable HW recovery, parity checking, setup clock ratio
        // 1= Enable hardware error recovery
        // 3= Enable parity checking
        // 4:13= FSI clock ratio 0 is 1:1
        // 14:23= FSI clock ratio 1 is 4:1
        databuf = 0x50040400;
        l_err = write( ctl_reg|FSI_MMODE_000, &databuf );
        if( l_err ) { break; }


        //Determine which links are present 
        l_err = read( ctl_reg|FSI_MLEVP0_018, &databuf );
        if( l_err ) { break; }

        // Only looking at the top bits
        uint64_t slave_index = getSlaveEnableIndex(i_master,i_type);
        iv_slaves[slave_index] = (uint8_t)(databuf >> (32-MAX_SLAVE_PORTS));


        //Clear FSI Slave Interrupt on ports 0-7
        databuf = 0x00000000;
        l_err = write( ctl_reg|FSI_MSIEP0_030, &databuf );
        if( l_err ) { break; }


        //Set the delay rates
        // 0:3,8:11= Echo delay cycles is 15
        // 4:7,12:15= Send delay cycles is 15
        databuf = 0xFFFF0000;
        l_err = write( ctl_reg|FSI_MDLYR_004, &databuf );
        if( l_err ) { break; }


        //Enable IPOLL
        // 0= Enable IPOLL and DMA access
        // 1= Enable hardware error recovery
        // 3= Enable parity checking
        // 4:13= FSI clock ratio 0 is 1:1
        // 14:23= FSI clock ratio 1 is 4:1
        databuf = 0xD0040400;
        l_err = write( ctl_reg|FSI_MMODE_000, &databuf );
        if( l_err ) { break; }

    } while(0);

    if( l_err )
    {
        TRACFCOMP( g_trac_fsi, "FsiDD::initMaster> Error during initialization of Target %llX : RC=%llX", target_to_uint64(iv_master), l_err->reasonCode() );
    }

    TRACDCOMP( g_trac_fsi, EXIT_MRK"FsiDD::initMaster" );
    return l_err;
}


/**
 * @brief Compute a few useful FSI values based on the target of the
 *   FSI operation, this will look up some attributes under the covers.
 */
void FsiDD::getFsiInfo( TARGETING::Target* i_master,
                        FSI::MasterType i_type,
                        uint8_t i_port,
                        uint64_t& o_masterOffset,
                        uint64_t& o_slaveOffset,
                        uint32_t& o_portBit )
{
    o_portBit = 0x80000000 >> i_port;

    // slave offset is determined by which port it is on
    o_slaveOffset = getPortOffset( i_type, i_port );

    // need to add the extra MFSI port offset for a remote cMFSI
    if( (FSI::CMFSI_TYPE == i_type) && (i_master != iv_master) )
    {
        // look up the FSI information for this target's master
        FSI::FsiChipInfo_t mfsi_info = temp_attr_call(i_master); 

        // append the master's port offset to the slave's
        o_slaveOffset += getPortOffset( FSI::MFSI_TYPE, mfsi_info.port );
    }


    // master control regs are based on the type of master
    
    if( FSI::MFSI_TYPE == i_type )
    {
        o_masterOffset = MFSI_CONTROL_REG;
    }
    else 
    {
        o_masterOffset = CMFSI_CONTROL_REG;
    }


    TRACUCOMP( g_trac_fsi,
               "FsiDD::getFsiInfo> i_master=%llX, i_type=%d, i_port=%d",
               target_to_uint64(i_master), i_type, i_port );
    TRACUCOMP( g_trac_fsi,
               "o_masterOffset=%llX, o_slaveOffset=%llX, o_portBit=%lX",
               o_masterOffset, o_slaveOffset, o_portBit );
}


/**
 * @brief Convert a type/port pair into a FSI address offset
 */
uint64_t FsiDD::getPortOffset(FSI::MasterType i_type,
                              uint8_t i_port)
{
    uint64_t offset = 0;
    if( FSI::MFSI_TYPE == i_type )
    {
        switch(i_port)
        {
            case(0): offset = MFSI_PORT_0; break;
            case(1): offset = MFSI_PORT_1; break;
            case(2): offset = MFSI_PORT_2; break;
            case(3): offset = MFSI_PORT_3; break;
            case(4): offset = MFSI_PORT_4; break;
            case(5): offset = MFSI_PORT_5; break;
            case(6): offset = MFSI_PORT_6; break;
            case(7): offset = MFSI_PORT_7; break;
        }
    }
    else if( FSI::CMFSI_TYPE == i_type )
    {
        switch(i_port)
        {
            case(0): offset = CMFSI_PORT_0; break;
            case(1): offset = CMFSI_PORT_1; break;
            case(2): offset = CMFSI_PORT_2; break;
            case(3): offset = CMFSI_PORT_3; break;
            case(4): offset = CMFSI_PORT_4; break;
            case(5): offset = CMFSI_PORT_5; break;
            case(6): offset = CMFSI_PORT_6; break;
            case(7): offset = CMFSI_PORT_7; break;
        }
    }

    return offset;
}

