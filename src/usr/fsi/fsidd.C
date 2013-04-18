/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fsi/fsidd.C $                                         */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
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
#include <fsi/fsiif.H>
#include <devicefw/driverif.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludlogregister.H>
#include <errl/errludtarget.H>
#include <initservice/taskargs.H>
#include <sys/time.h>
#include <string.h>
#include <algorithm>
#include <targeting/common/commontargeting.H>

// FSI : General driver traces
trace_desc_t* g_trac_fsi = NULL;
TRAC_INIT(&g_trac_fsi, "FSI", KILOBYTE); //1K

// FSIR : Register reads and writes (should always use TRACS)
trace_desc_t* g_trac_fsir = NULL;
TRAC_INIT(&g_trac_fsir, "FSIR", KILOBYTE); //1K

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)


namespace FSI
{

/**
 * @brief Performs a FSI Operation
 * This function performs a FSI Read/Write operation. It follows a pre-defined
 * prototype functions in order to be registered with the device-driver
 * framework.
 *
 * @param[in]   i_opType        Operation type, see DeviceFW::OperationType
 *                              in driverif.H
 * @param[in]   i_target        FSI target
 * @param[in/out] io_buffer     Read: Pointer to output data storage
 *                              Write: Pointer to input data storage
 * @param[in/out] io_buflen     Input: size of io_buffer (in bytes, always 4)
 *                              Output: Success = 4, Failure = 0
 * @param[in]   i_accessType    DeviceFW::AccessType enum (userif.H)
 * @param[in]   i_args          This is an argument list for DD framework.
 *                              In this function, there's only one argument,
 *                              containing the FSI address
 * @return  errlHndl_t
 */
errlHndl_t ddOp(DeviceFW::OperationType i_opType,
                TARGETING::Target* i_target,
                void* io_buffer,
                size_t& io_buflen,
                int64_t i_accessType,
                va_list i_args)
{
    errlHndl_t l_err = NULL;
    uint64_t i_addr = va_arg(i_args,uint64_t);
    TRACUCOMP( g_trac_fsi, "FSI::ddOp> i_addr=%llX, target=%.8X", i_addr, TARGETING::get_huid(i_target) );

    do{
        if (unlikely(io_buflen < sizeof(uint32_t)))
        {
            TRACFCOMP( g_trac_fsi, ERR_MRK "FSI::ddOp> Invalid data length : io_buflen=%d", io_buflen );
            /*@
             * @errortype
             * @moduleid     FSI::MOD_FSIDD_DDOP
             * @reasoncode   FSI::RC_INVALID_LENGTH
             * @userdata1    FSI Address
             * @userdata2    Data Length
             * @devdesc      FsiDD::ddOp> Invalid data length (!= 4 bytes)
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            FSI::MOD_FSIDD_DDOP,
                                            FSI::RC_INVALID_LENGTH,
                                            i_addr,
                                            TO_UINT64(io_buflen));
            l_err->collectTrace("FSI",1024);
            break;
        }

        // default to the fail path
        io_buflen = 0;

        // look for NULL
        if( NULL == i_target )
        {
            TRACFCOMP( g_trac_fsi, ERR_MRK "FSI::ddOp> Target is NULL" );
            /*@
             * @errortype
             * @moduleid     FSI::MOD_FSIDD_DDOP
             * @reasoncode   FSI::RC_NULL_TARGET
             * @userdata1    FSI Address
             * @userdata2    Operation Type (i_opType) : 0=READ, 1=WRITE
             * @devdesc      FsiDD::ddOp> Target is NULL
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            FSI::MOD_FSIDD_DDOP,
                                            FSI::RC_NULL_TARGET,
                                            i_addr,
                                            TO_UINT64(i_opType));
            l_err->collectTrace("FSI",1024);
            break;
        }
        // check target for sentinel
        else if( TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL == i_target )
        {
            TRACFCOMP( g_trac_fsi, ERR_MRK "FSI::ddOp> Target is Master Sentinel" );
            /*@
             * @errortype
             * @moduleid     FSI::MOD_FSIDD_DDOP
             * @reasoncode   FSI::RC_MASTER_TARGET
             * @userdata1    FSI Address
             * @userdata2    Operation Type (i_opType) : 0=READ, 1=WRITE
             * @devdesc      FsiDD::ddOp> Target is unsupported Master Sentinel
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            FSI::MOD_FSIDD_DDOP,
                                            FSI::RC_MASTER_TARGET,
                                            i_addr,
                                            TO_UINT64(i_opType));
            l_err->collectTrace("FSI",1024);
            break;
        }

        // do the read
        if( DeviceFW::READ == i_opType )
        {
            l_err = Singleton<FsiDD>::instance().read(i_target,
                                        i_addr,
                                        static_cast<uint32_t*>(io_buffer));
            if(l_err)
            {
                break;
            }
            io_buflen = sizeof(uint32_t);
        }
        // do the write
        else if( DeviceFW::WRITE == i_opType )
        {
            l_err = Singleton<FsiDD>::instance().write(i_target,
                                        i_addr,
                                        static_cast<uint32_t*>(io_buffer));
            if(l_err)
            {
                break;
            }
            io_buflen = sizeof(uint32_t);
        }
        else
        {
            TRACFCOMP( g_trac_fsi, ERR_MRK "FSI::ddOp> Invalid Op Type = %d", i_opType );
            /*@
             * @errortype
             * @moduleid     FSI::MOD_FSIDD_DDOP
             * @reasoncode   FSI::RC_INVALID_OPERATION
             * @userdata1    FSI Address
             * @userdata2    Operation Type (i_opType)
             * @devdesc      FsiDD::ddOp> Invalid operation type
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            FSI::MOD_FSIDD_DDOP,
                                            FSI::RC_INVALID_OPERATION,
                                            i_addr,
                                            TO_UINT64(i_opType));
            l_err->collectTrace("FSI",1024);
            break;
        }

    }while(0);

    return l_err;
}


// Register fsidd access functions to DD framework
DEVICE_REGISTER_ROUTE(DeviceFW::READ,
                      DeviceFW::FSI,
                      TARGETING::TYPE_PROC,
                      ddOp);
DEVICE_REGISTER_ROUTE(DeviceFW::READ,
                      DeviceFW::FSI,
                      TARGETING::TYPE_MEMBUF,
                      ddOp);

// Register fsidd access functions to DD framework
DEVICE_REGISTER_ROUTE(DeviceFW::WRITE,
                      DeviceFW::FSI,
                      TARGETING::TYPE_PROC,
                      ddOp);
DEVICE_REGISTER_ROUTE(DeviceFW::WRITE,
                      DeviceFW::FSI,
                      TARGETING::TYPE_MEMBUF,
                      ddOp);


/**
 * @brief Initialize the FSI hardware
 */
errlHndl_t initializeHardware()
{
    return Singleton<FsiDD>::instance().initializeHardware();
}

/**
 * @brief Retrieves the status of a given port
 */
bool isSlavePresent( TARGETING::Target* i_fsiMaster,
                     TARGETING::FSI_MASTER_TYPE i_type,
                     uint8_t i_port )
{
    if( i_fsiMaster == NULL )
    {
        // NULL target means it isn't present
        return false;
    }
    else
    {
        return Singleton<FsiDD>::instance().isSlavePresent(i_fsiMaster,
                                                           i_type,
                                                           i_port);
    }
}

/**
 * @brief Retrieves the FSI status of a given chip
 */
bool isSlavePresent( TARGETING::Target* i_target )
{
    if( i_target == NULL )
    {
        // NULL target means it isn't present
        return false;
    }
    else
    {
        return Singleton<FsiDD>::instance().isSlavePresent(i_target);
    }
}


/**
 * @brief Add FFDC for the target to an error log
 */
void getFsiFFDC(FSI::fsiFFDCType_t i_ffdc_type, errlHndl_t &i_log,
                TARGETING::Target*  i_target)
{
    if ( (i_target == NULL) || (i_log == NULL) )
    {
        // NULL target or error log - can't collect data
        return;
    }
    else
    {
        Singleton<FsiDD>::instance().getFsiFFDC(i_ffdc_type,
                                                i_log, i_target);
    }
}


}; //end FSI namespace



/********************
 Public Methods
 ********************/


/**
 * @brief Performs an FSI Read Operation to a relative address
 */
errlHndl_t FsiDD::read(TARGETING::Target* i_target,
                       uint64_t i_address,
                       uint32_t* o_buffer)
{
    TRACDCOMP(g_trac_fsi, "FsiDD::read(i_target=%.8X,i_address=0x%llX)> ", TARGETING::get_huid(i_target), i_address);
    errlHndl_t l_err = NULL;

    do {
        // verify slave is present before doing anything
        if( !isSlavePresent(i_target) && (i_target != iv_master) )
        {
            TRACFCOMP( g_trac_fsi, "FsiDD::read> Requested target was never detected during FSI Init : i_target=%.8X, i_address=%.llX", TARGETING::get_huid(i_target), i_address  );

            /*@
             * @errortype
             * @moduleid     FSI::MOD_FSIDD_READ
             * @reasoncode   FSI::RC_TARGET_NEVER_DETECTED
             * @userdata1    Relative FSI Address
             * @userdata2[0:31]   HUID of FSI Target
             * @userdata2[32:63]  HUID of FSI Master
             * @devdesc      FsiDD::read> Target was never detected during FSI Init
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            FSI::MOD_FSIDD_READ,
                                            FSI::RC_TARGET_NEVER_DETECTED,
                                            i_address,
                                            TWO_UINT32_TO_UINT64(
                                               TARGETING::get_huid(i_target),
                                               TARGETING::get_huid(iv_master)));
            l_err->collectTrace("FSI",1024);
            break;
        }

        // prefix the appropriate MFSI/cMFSI slave port offset
        FsiAddrInfo_t addr_info( i_target, i_address );
        l_err = genFullFsiAddr( addr_info );
        if(l_err)
        {
            break;
        }

        // perform the read operation
        l_err = read( addr_info, o_buffer );
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
                        uint32_t* o_buffer)
{
    TRACDCOMP(g_trac_fsi, "FsiDD::write(i_target=%.8X,i_address=0x%llX)> ", TARGETING::get_huid(i_target), i_address);
    errlHndl_t l_err = NULL;

    do {
        // verify slave is present before doing anything
        if( !isSlavePresent(i_target) && (i_target != iv_master) )
        {
            TRACFCOMP( g_trac_fsi, "FsiDD::write> Requested target was never detected during FSI Init : i_target=%.8X, i_address=%.llX", TARGETING::get_huid(i_target), i_address  );

            /*@
             * @errortype
             * @moduleid     FSI::MOD_FSIDD_WRITE
             * @reasoncode   FSI::RC_TARGET_NEVER_DETECTED
             * @userdata1    Relative FSI Address
             * @userdata2[0:31]   HUID of FSI Target
             * @userdata2[32:63]  HUID of FSI Master
             * @devdesc      FsiDD::read> Target was never detected during FSI Init
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            FSI::MOD_FSIDD_WRITE,
                                            FSI::RC_TARGET_NEVER_DETECTED,
                                            i_address,
                                            TWO_UINT32_TO_UINT64(
                                              TARGETING::get_huid(i_target),
                                              TARGETING::get_huid(iv_master)));
            l_err->collectTrace("FSI",1024);
            break;
        }

        // prefix the appropriate MFSI/cMFSI slave port offset
        FsiAddrInfo_t addr_info( i_target, i_address );
        l_err = genFullFsiAddr( addr_info );
        if(l_err)
        {
            break;
        }

        // perform the write operation
        l_err = write( addr_info, o_buffer );
        if(l_err)
        {
            break;
        }
    } while(0);

    return l_err;
}



/********************
 Internal Methods
 ********************/

/**
 * @brief Initialize the FSI hardware
 */
errlHndl_t FsiDD::initializeHardware()
{
    errlHndl_t l_err = NULL;
    TRACFCOMP( g_trac_fsi, "FSI::initializeHardware>" );

    do{
        typedef struct {
            TARGETING::Target* targ;
            FsiDD::FsiChipInfo_t info;
        } target_chipInfo_t ;

        // list of ports off of local MFSI
        target_chipInfo_t local_mfsi[MAX_SLAVE_PORTS] = {};

        // list of possible ports off of local cMFSI
        target_chipInfo_t local_cmfsi[MAX_SLAVE_PORTS] = {};

        // array of possible ports to initialize : [mfsi port][cmfsi port]
        target_chipInfo_t remote_cmfsi[MAX_SLAVE_PORTS][MAX_SLAVE_PORTS] = {};

        FsiChipInfo_t info;

        // loop through every CHIP target
        TARGETING::PredicateCTM l_chipClass(TARGETING::CLASS_CHIP,
                                            TARGETING::TYPE_NA,
                                            TARGETING::MODEL_NA);
        TARGETING::TargetService& targetService = TARGETING::targetService();
        TARGETING::TargetIterator t_itr = targetService.begin();
        while( t_itr != targetService.end() )
        {
            // Sorting into buckets because we must maintain the init order
            //  the MFSI port that goes out to a remote cMFSI driver
            //  must be initialized before we can deal with the cMFSI port
            if( l_chipClass(*t_itr) )
            {
                info = getFsiInfo(*t_itr);

                if( info.type == TARGETING::FSI_MASTER_TYPE_MFSI )
                {
                    local_mfsi[info.port].targ = *t_itr;
                    local_mfsi[info.port].info = info;
                }
                else if( info.type == TARGETING::FSI_MASTER_TYPE_CMFSI )
                {
                    if( info.master == iv_master )
                    {
                        local_cmfsi[info.port].targ = *t_itr;
                        local_cmfsi[info.port].info = info;
                    }
                    else
                    {
                        FsiChipInfo_t info2 = getFsiInfo(info.master);
                        remote_cmfsi[info2.port][info.port].info = info;
                        remote_cmfsi[info2.port][info.port].targ = *t_itr;
                    }
                }
            }

            ++t_itr;
        }

        // setup the local master control regs for the MFSI
        l_err = initMasterControl(iv_master,TARGETING::FSI_MASTER_TYPE_MFSI);
        if( l_err )
        {
            errlCommit(l_err,FSI_COMP_ID);
        }
        else
        {
            // initialize all of the local MFSI ports
            for( uint8_t mfsi=0; mfsi<MAX_SLAVE_PORTS; mfsi++ )
            {
                bool slave_present = false;
                l_err = initPort( local_mfsi[mfsi].info,
                                  slave_present );
                if( l_err )
                {
                    // append the actual slave target to FFDC
                    ERRORLOG::ErrlUserDetailsTarget(
                            local_mfsi[mfsi].targ
                        ).addToLog(l_err);

                    // commit the log here so that we can move on to next port
                    errlCommit(l_err,FSI_COMP_ID);

                    //if this fails then some of the slaves below won't init,
                    //  but that is okay because the detected ports will be
                    //  zero which will cause the initPort call to be a NOOP
                    continue;
                }

                // the slave wasn't present so we can't do anything with the
                //   downstream ports

                if( !slave_present )
                {
                    continue;
                }

                // initialize all of the remote cMFSI ports off the master
                //   we just initialized
                bool master_init_done = false;
                for( uint8_t cmfsi=0; cmfsi<MAX_SLAVE_PORTS; cmfsi++ )
                {
                    // skip ports that have no possible slaves
                    if( remote_cmfsi[mfsi][cmfsi].targ == NULL )
                    {
                        continue;
                    }

                    if( !master_init_done )
                    {
                        // init the remote cMFSI master on this MFSI slave
                        l_err = initMasterControl( local_mfsi[mfsi].targ,
                                          TARGETING::FSI_MASTER_TYPE_CMFSI );
                        if( l_err )
                        {
                            // commit the log here so that we can move on
                            //  to the next port
                            errlCommit(l_err,FSI_COMP_ID);
                            break;
                        }

                        // only init the master once
                        master_init_done = true;
                    }

                    // initialize the port/slave
                    l_err = initPort( remote_cmfsi[mfsi][cmfsi].info,
                                      slave_present );
                    if( l_err )
                    {
                        // append the actual slave target to FFDC
                        ERRORLOG::ErrlUserDetailsTarget(
                                remote_cmfsi[mfsi][cmfsi].targ
                            ).addToLog(l_err);

                        // commit the log here so that we can move on to next port
                        errlCommit(l_err,FSI_COMP_ID);
                    }
                }

            }
        }

        // setup the local master control regs for the cMFSI
        l_err = initMasterControl(iv_master,TARGETING::FSI_MASTER_TYPE_CMFSI);
        if( l_err )
        {
            errlCommit(l_err,FSI_COMP_ID);
        }
        else
        {
            // initialize all of the local cMFSI ports
            for( uint8_t cmfsi=0; cmfsi<MAX_SLAVE_PORTS; cmfsi++ )
            {
                // skip ports that have no possible slaves
                if( local_cmfsi[cmfsi].targ == NULL )
                {
                    continue;
                }

                bool slave_present = false;
                l_err = initPort( local_cmfsi[cmfsi].info,
                                  slave_present );
                if( l_err )
                {
                    // append the actual slave target to FFDC
                    ERRORLOG::ErrlUserDetailsTarget(
                            local_cmfsi[cmfsi].targ
                        ).addToLog(l_err);

                    // commit the log here so that we can move on to next port
                    errlCommit(l_err,FSI_COMP_ID);
                }
            }
        }

    } while(0);

    return l_err;
}

/**
 * @brief Add FFDC for the target to an error log
 */
void FsiDD::getFsiFFDC(FSI::fsiFFDCType_t i_ffdc_type, errlHndl_t &io_log,
                       TARGETING::Target*  i_target)
{
    TRACDCOMP( g_trac_fsi, "FSI::getFFDC>" );

    // Local Variables
    uint8_t * i_data_ptr = NULL;
    uint32_t i_ffdc_byte_len = 0;
    bool i_merge = false;
    uint64_t l_slaveEnableIndex=0;
    uint64_t l_byte_index = 0;

    // Check Type -- Not doing anything unique right now
    if ( ! (i_ffdc_type == FSI::FSI_FFDC_PRESENCE_FAIL ) ||
           (i_ffdc_type == FSI::FSI_FFDC_READWRITE_FAIL) )
    {
        // Unsupported FSI FFDC type, so don't add FFDC section
        TRACFCOMP( g_trac_fsi, "FSI::getFFDC> Incorect i_ffdc_type (%d) "
                               "Not Adding FFDC section!",
                               i_ffdc_type);

        return;
    }

    // Add target to error log
    if (i_target != NULL)
    {
        ERRORLOG::ErrlUserDetailsTarget(i_target).addToLog(io_log);
    }

    // Add Master Target to Log
    if (iv_master != NULL)
    {
        ERRORLOG::ErrlUserDetailsTarget(iv_master).addToLog(io_log);
    }

    //  Information to capture
    //  1) FsiChipInfo_t associated with this target
    //  2) Size of iv_slaves[]
    //  3) iv_slaves[]
    //  4) uint64_t -- slave enable Index
    i_ffdc_byte_len = sizeof(FsiChipInfo_t) +
                      sizeof(uint32_t)      +
                      sizeof(iv_slaves)     +
                      sizeof(uint64_t);

    i_data_ptr = static_cast<uint8_t*>(malloc(i_ffdc_byte_len));


    // Collect the data
    FsiChipInfo_t l_fsi_chip_info = getFsiInfo(i_target);

    l_slaveEnableIndex = getSlaveEnableIndex (l_fsi_chip_info.master,
                                              l_fsi_chip_info.type);


    TRACFCOMP( g_trac_fsi,
               "FSI::getFFDC> i_ffdc_byte_len =%d, i_data_ptr=%p,"
               " sizeof: FsiChipInfo_t=%d, iv_slaves=%d, u32=%d "
               "u64=%d, l_slaveEnableIndex=0x%x", i_ffdc_byte_len,
               i_data_ptr, sizeof(FsiChipInfo_t), sizeof(iv_slaves),
               sizeof(uint32_t), sizeof(uint64_t), l_slaveEnableIndex);


    // Copy Data into memory bloack
    l_byte_index = 0;

    // FsiChipInfo_t
    memcpy(reinterpret_cast<void*>(i_data_ptr + l_byte_index),
           &l_fsi_chip_info, sizeof(FsiChipInfo_t));

    l_byte_index += sizeof(FsiChipInfo_t);


    // Size of iv_slaves[]
    const uint32_t l_so_iv_slaves   = sizeof(iv_slaves);
    memcpy(reinterpret_cast<void*>(i_data_ptr + l_byte_index),
           &l_so_iv_slaves, sizeof(uint32_t));

    l_byte_index += sizeof(uint32_t);


    // iv_slaves[]
    memcpy(reinterpret_cast<void*>(i_data_ptr + l_byte_index),
           &iv_slaves, sizeof(iv_slaves));

    l_byte_index += sizeof(iv_slaves);


    // getSlaveEnable Index
    memcpy(reinterpret_cast<void*>(i_data_ptr + l_byte_index),
           &l_slaveEnableIndex, sizeof(uint64_t));

    l_byte_index += sizeof(uint64_t);


    // Check we didn't go too far or too short
    if (l_byte_index !=  i_ffdc_byte_len)
    {
        TRACFCOMP( g_trac_fsi, "FSI::getFFDC> Byte Length Mismatch: "
                               "Not Adding FFDC section!"
                               "l_byte_index=%d, i_ffdc_byte_len=%d",
                               l_byte_index, i_ffdc_byte_len);

        // Free malloc'ed memory
        if (i_data_ptr != NULL)
        {
            free(i_data_ptr);
        }

        return;
    }

    // Actual call to log the data
    ERRORLOG::ErrlUD * l_pUD = (io_log)->addFFDC(FSI_COMP_ID,
                                              i_data_ptr,
                                              i_ffdc_byte_len,
                                              FsiFFDC_Ver1,
                                              FsiFFDC_CapData_1,
                                              i_merge);

    // Check for success
    if (l_pUD == NULL)
    {
        // Failure to add FFDC section
        TRACFCOMP( g_trac_fsi, "FSI::getFFDC> FAILURE TO ADD FFDC" );

        // Add errl trace
        (io_log)->collectTrace("ERR");
    }
    else
    {
        TRACFCOMP( g_trac_fsi, "FSI::getFFDC> FFDC Successfully added "
                               "(%d bytes)", i_ffdc_byte_len );
    }

    return;

}

/********************
 Internal Methods
 ********************/

/**
 * @brief  Constructor
 */
FsiDD::FsiDD()
:iv_master(NULL)
,iv_ffdcTask(0)
{
    TRACFCOMP(g_trac_fsi, "FsiDD::FsiDD()>");

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
 * @brief Performs an FSI Read Operation to an absolute address
 *   using the master processor chip to drive it
 */
errlHndl_t FsiDD::read(uint64_t i_address,
                       uint32_t* o_buffer)
{
    TRACDCOMP(g_trac_fsi, "FsiDD::read(i_address=0x%llx)> ", i_address);

    // generate a set of address info for this manual operation
    //  note that relAddr==absAddr in this case
    FsiAddrInfo_t addr_info( iv_master, i_address );
    addr_info.opbTarg = iv_master;
    addr_info.absAddr = i_address;

    // call to low-level read function
    errlHndl_t l_err = read( addr_info, o_buffer );

    return l_err;
}


/**
 * @brief Performs an FSI Write Operation to an absolute address
 *   using the master processor chip to drive it
 */
errlHndl_t FsiDD::write(uint64_t i_address,
                        uint32_t* i_buffer)
{
    TRACDCOMP(g_trac_fsi, "FsiDD::write(i_address=0x%llx)> ", i_address);

    // generate a set of address info for this manual operation
    //  note that relAddr==absAddr in this case
    FsiAddrInfo_t addr_info( iv_master, i_address );
    addr_info.opbTarg = iv_master;
    addr_info.absAddr = i_address;

    // call to low-level write function
    errlHndl_t l_err = write( addr_info, i_buffer );

    return l_err;
}


/**
 * @brief Performs an FSI Read Operation
 */
errlHndl_t FsiDD::read(FsiAddrInfo_t& i_addrInfo,
                       uint32_t* o_buffer)
{
    TRACDCOMP(g_trac_fsi, "FsiDD::read(relAddr=0x%llx,absAddr=0x%11x)> ", i_addrInfo.relAddr, i_addrInfo.absAddr );
    errlHndl_t l_err = NULL;
    bool need_unlock = false;
    mutex_t* l_mutex = NULL;

    do {
        // setup the OPB command register
        uint64_t fsicmd = i_addrInfo.absAddr | 0x60000000; // 011=Read Full Word
        fsicmd <<= 32; // Command is in the upper word

        // generate the proper OPB SCOM address
        uint64_t opbaddr = genOpbScomAddr(i_addrInfo,OPB_REG_CMD);

        // atomic section >>
        l_mutex
          = (i_addrInfo.opbTarg)->getHbMutexAttr<TARGETING::ATTR_FSI_MASTER_MUTEX>();

        if( (iv_ffdcTask == 0)  // performance hack for typical case
            || (iv_ffdcTask != task_gettid()) )
        {
            mutex_lock(l_mutex);
            need_unlock = true;
        }

        // always read/write 64 bits to SCOM
        size_t scom_size = sizeof(uint64_t);

        // write the OPB command register to trigger the read
        TRACUCOMP(g_trac_fsi, "FsiDD::read> ScomWRITE : opbaddr=%.16llX, data=%.16llX", opbaddr, fsicmd );
        l_err = deviceOp( DeviceFW::WRITE,
                          i_addrInfo.opbTarg,
                          &fsicmd,
                          scom_size,
                          DEVICE_XSCOM_ADDRESS(opbaddr) );
        if( l_err )
        {
            TRACFCOMP(g_trac_fsi, "FsiDD::read> Error from device %.8X : RC=%X", TARGETING::get_huid(i_addrInfo.opbTarg), l_err->reasonCode() );
            break;
        }

        // poll for complete and get the data back
        l_err = pollForComplete( i_addrInfo, o_buffer );
        if( l_err )
        {
            break;
        }

        //@todo - need to check for FSI errors (Story 35287)

        // atomic section <<

        TRACDCOMP(g_trac_fsir, "FSI READ  : %.6X = %.8X", i_addrInfo.absAddr, *o_buffer );
    } while(0);

    if( need_unlock )
    {
        mutex_unlock(l_mutex);
    }

    return l_err;
}


/**
 * @brief Write FSI Register
 */
errlHndl_t FsiDD::write(FsiAddrInfo_t& i_addrInfo,
                        uint32_t* i_buffer)
{
    TRACDCOMP(g_trac_fsi, "FsiDD::write(relAddr=0x%.llX,absAddr=0x%.11X)> ", i_addrInfo.relAddr, i_addrInfo.absAddr );
    errlHndl_t l_err = NULL;
    bool need_unlock = false;
    mutex_t* l_mutex = NULL;

    do {
        TRACDCOMP(g_trac_fsir, "FSI WRITE : %.6X = %.8X", i_addrInfo.absAddr, *i_buffer );

        // pull out the data to write (length has been verified)
        uint32_t fsidata = *i_buffer;

        // setup the OPB command register
        uint64_t fsicmd = i_addrInfo.absAddr | 0xE0000000; // 111=Write Full Word
        fsicmd <<= 32; // Command is in the upper 32-bits
        fsicmd |= fsidata; // Data is in the bottom 32-bits
        size_t scom_size = sizeof(uint64_t);

        // generate the proper OPB SCOM address
        uint64_t opbaddr = genOpbScomAddr(i_addrInfo,OPB_REG_CMD);

        // atomic section >>
        l_mutex
            = (i_addrInfo.opbTarg)->getHbMutexAttr<TARGETING::ATTR_FSI_MASTER_MUTEX>();

        if( (iv_ffdcTask == 0)  // performance hack for typical case
            || (iv_ffdcTask != task_gettid()) )
        {
            mutex_lock(l_mutex);
            need_unlock = true;
        }

        // write the OPB command register
        TRACUCOMP(g_trac_fsi, "FsiDD::write> ScomWRITE : opbaddr=%.16llX, data=%.16llX", opbaddr, fsicmd );
        l_err = deviceOp( DeviceFW::WRITE,
                          i_addrInfo.opbTarg,
                          &fsicmd,
                          scom_size,
                          DEVICE_XSCOM_ADDRESS(opbaddr) );
        if( l_err )
        {
            TRACFCOMP(g_trac_fsi, "FsiDD::write> Error from device %.8X : RC=%X", TARGETING::get_huid(i_addrInfo.opbTarg), l_err->reasonCode() );
            break;
        }

        // poll for complete (no return data)
        l_err = pollForComplete( i_addrInfo, NULL );
        if( l_err )
        {
            break;
        }

        //@todo - need to check for FSI errors (Story 35287)

        // atomic section <<

    } while(0);

    if( need_unlock )
    {
        mutex_unlock(l_mutex);
    }

    TRACDCOMP(g_trac_fsi, "< FsiDD::write() " );

    return l_err;
}


/**
 * @brief Analyze error bits and recover hardware as needed
 */
errlHndl_t FsiDD::handleOpbErrors(FsiAddrInfo_t& i_addrInfo,
                                  uint32_t i_opbStatReg)
{
    errlHndl_t l_err = NULL;

    if( (i_opbStatReg & OPB_STAT_ERR_ANY)
        || (i_opbStatReg & OPB_STAT_BUSY) )
    {
        TRACFCOMP( g_trac_fsi, "FsiDD::handleOpbErrors> Error during FSI access : relAddr=0x%X, absAddr=0x%X, OPB Status=0x%.8X", i_addrInfo.relAddr, i_addrInfo.absAddr, i_opbStatReg );
        /*@
         * @errortype
         * @moduleid     FSI::MOD_FSIDD_HANDLEOPBERRORS
         * @reasoncode   FSI::RC_OPB_ERROR
         * @userdata1[0:31]  Relative FSI Address
         * @userdata1[32:63]  Absolute FSI Address
         * @userdata2    OPB Status Register
         * @devdesc      FsiDD::handleOpbErrors> Error during FSI access
         */
        l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        FSI::MOD_FSIDD_HANDLEOPBERRORS,
                                        FSI::RC_OPB_ERROR,
                                        TWO_UINT32_TO_UINT64(
                                            i_addrInfo.relAddr,
                                            i_addrInfo.absAddr),
                                        TWO_UINT32_TO_UINT64(i_opbStatReg,0));

        // Collect some FFDC but avoid an infinite loop
        if( iv_ffdcTask == 0 )
        {
            iv_ffdcTask = task_gettid();

            uint32_t data = 0;
            errlHndl_t l_err2 = NULL;

            // Add data to main error log 'l_err' where possible
            size_t l_data_size = sizeof(data);
            ERRORLOG::ErrlUserDetailsLogRegister
                    l_eud_fsiT(i_addrInfo.fsiTarg);

            l_err2 = read( 0x31D0, &data );
            if( l_err2 )
            {
                delete l_err2;
            }
            else
            {
                TRACFCOMP( g_trac_fsi, "MESRB0(1D0) = %.8X", data );
                l_eud_fsiT.addDataBuffer(&data, l_data_size,
                                         DEVICE_FSI_ADDRESS(0x31D0ull));

            }

            l_err2 = read( 0x31D4, &data );
            if( l_err2 )
            {
                delete l_err2;
            }
            else
            {
                TRACFCOMP( g_trac_fsi, "MCSCSB0(1D4) = %.8X", data );
                l_eud_fsiT.addDataBuffer(&data, l_data_size,
                                         DEVICE_FSI_ADDRESS(0x31D4ull));
            }

            l_err2 = read( 0x31D8, &data );
            if( l_err2 )
            {
                delete l_err2;
            }
            else
            {
                TRACFCOMP( g_trac_fsi, "MATRB0(1D8) = %.8X", data );
                l_eud_fsiT.addDataBuffer(&data, l_data_size,
                                         DEVICE_FSI_ADDRESS(0x31D8ull));
            }

            l_err2 = read( 0x31DC, &data );
            if( l_err2 )
            {
                delete l_err2;
            }
            else
            {
                TRACFCOMP( g_trac_fsi, "MDTRB0(1DC) = %.8X", data );
                l_eud_fsiT.addDataBuffer(&data, l_data_size,
                                         DEVICE_FSI_ADDRESS(0x31DCull));
            }

            // Push details to error log
            l_eud_fsiT.addToLog(l_err);

            //MAGIC_INSTRUCTION(MAGIC_BREAK);

            iv_ffdcTask = 0;
        }


        // Add opbTarg to original error log
        ERRORLOG::ErrlUserDetailsTarget(i_addrInfo.opbTarg).addToLog(l_err);

        l_err->collectTrace("FSI");
        l_err->collectTrace("FSIR");

        //@todo - implement recovery and callout code (Story 35287)

    }

    return l_err;
}

/**
 * @brief  Poll for completion of a FSI operation, return data on read
 */
errlHndl_t FsiDD::pollForComplete(FsiAddrInfo_t& i_addrInfo,
                                  uint32_t* o_readData)
{
    errlHndl_t l_err = NULL;
    enum { MAX_OPB_TIMEOUT_NS = 1000000 }; //=1ms

    do {
        // poll for complete
        uint32_t read_data[2];
        size_t scom_size = sizeof(uint64_t);
        uint64_t opbaddr = genOpbScomAddr(i_addrInfo,OPB_REG_STAT);

        uint64_t elapsed_time_ns = 0;
        do
        {
            TRACUCOMP(g_trac_fsi, "FsiDD::pollForComplete> ScomREAD : opbaddr=%.16llX", opbaddr );
            l_err = deviceOp( DeviceFW::READ,
                              i_addrInfo.opbTarg,
                              read_data,
                              scom_size,
                              DEVICE_XSCOM_ADDRESS(opbaddr) );
            if( l_err )
            {
                TRACFCOMP(g_trac_fsi, "FsiDD::pollForComplete> Error from device 2 : RC=%X", l_err->reasonCode() );
                // Save both targets in i_addrInfo to error log
                ERRORLOG::ErrlUserDetailsTarget(
                        i_addrInfo.fsiTarg
                    ).addToLog(l_err);
                ERRORLOG::ErrlUserDetailsTarget(
                        i_addrInfo.opbTarg
                    ).addToLog(l_err);

               break;
            }

            // check for completion or error
            TRACUCOMP(g_trac_fsi, "FsiDD::pollForComplete> ScomREAD : read_data[0]=%.8llX", read_data[0] );
            if( ((read_data[0] & OPB_STAT_BUSY) == 0)  //not busy
                || (read_data[0] & OPB_STAT_ERR_ANY) ) //error bits
            {
                break;
            }

            //TODO tmp remove for VPO, need better polling strategy -- RTC43738
            //nanosleep( 0, 10,000 ); //sleep for 10,000 ns
            elapsed_time_ns += 10000;
        } while( elapsed_time_ns <= MAX_OPB_TIMEOUT_NS ); // hardware has 1ms limit
        if( l_err ) { break; }


        // we should never timeout because the hardware should set an error
        if( elapsed_time_ns > MAX_OPB_TIMEOUT_NS )
        {
            TRACFCOMP( g_trac_fsi, "FsiDD::pollForComplete> Never got complete or error on OPB operation : absAddr=0x%X, OPB Status=0x%.8X", i_addrInfo.absAddr, read_data[0] );
            /*@
             * @errortype
             * @moduleid     FSI::MOD_FSIDD_POLLFORCOMPLETE
             * @reasoncode   FSI::RC_OPB_TIMEOUT
             * @userdata1[0:31]  Relative FSI Address
             * @userdata1[32:63]  Absolute FSI Address
             * @userdata2    OPB Status Register
             * @devdesc      FsiDD::pollForComplete> Error during FSI access
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            FSI::MOD_FSIDD_POLLFORCOMPLETE,
                                            FSI::RC_OPB_TIMEOUT,
                                            TWO_UINT32_TO_UINT64(
                                                i_addrInfo.relAddr,
                                                i_addrInfo.absAddr),
                                            TWO_UINT32_TO_UINT64(
                                                read_data[0],
                                                read_data[1]) );

            // Save both targets in i_addrInfo to error log
            ERRORLOG::ErrlUserDetailsTarget(
                    i_addrInfo.fsiTarg
                ).addToLog(l_err);
            ERRORLOG::ErrlUserDetailsTarget(
                    i_addrInfo.opbTarg
                ).addToLog(l_err);

            l_err->collectTrace("FSI");
            l_err->collectTrace("FSIR");
            break;
        }

        // check if we got an error from the OPB
        l_err = handleOpbErrors( i_addrInfo, read_data[0] );
        if( l_err )
        {
            break;
        }

        // read valid isn't on
        if( o_readData )  // only check if we're doing a read
        {
            if( !(read_data[0] & OPB_STAT_READ_VALID) )
            {
                TRACFCOMP( g_trac_fsi, "FsiDD::pollForComplete> Read valid never came on : absAddr=0x%X, OPB Status=0x%.8X", i_addrInfo.absAddr, read_data[0] );
                /*@
                 * @errortype
                 * @moduleid     FSI::MOD_FSIDD_POLLFORCOMPLETE
                 * @reasoncode   FSI::RC_OPB_NO_READ_VALID
                 * @userdata1[0:31]  Relative FSI Address
                 * @userdata1[32:63]  Absolute FSI Address
                 * @userdata2    OPB Status Register
                 * @devdesc      FsiDD::pollForComplete> Read valid never came on
                 */
                l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                                FSI::MOD_FSIDD_POLLFORCOMPLETE,
                                                FSI::RC_OPB_NO_READ_VALID,
                                                TWO_UINT32_TO_UINT64(
                                                    i_addrInfo.relAddr,
                                                    i_addrInfo.absAddr),
                                                TWO_UINT32_TO_UINT64(
                                                    read_data[0],
                                                    read_data[1]) );

                // Save both targets in i_addrInfo to error log
                ERRORLOG::ErrlUserDetailsTarget(
                        i_addrInfo.fsiTarg
                    ).addToLog(l_err);
                ERRORLOG::ErrlUserDetailsTarget(
                        i_addrInfo.opbTarg
                    ).addToLog(l_err);

                l_err->collectTrace("FSI");
                l_err->collectTrace("FSIR");
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
errlHndl_t FsiDD::genFullFsiAddr(FsiAddrInfo_t& io_addrInfo)
{
    errlHndl_t l_err = NULL;

    //default to using the master chip for OPB XSCOM ops
    io_addrInfo.opbTarg = iv_master;

    //start off with the addresses being the same
    io_addrInfo.absAddr = io_addrInfo.relAddr;

    //target matches master so the address is correct as-is
    if( io_addrInfo.fsiTarg == iv_master )
    {
        return NULL;
    }

    //pull the FSI info out for this target
    FsiChipInfo_t fsi_info = getFsiInfo( io_addrInfo.fsiTarg );

    TRACUCOMP( g_trac_fsi, "target=%.8X : Link Id=%.8X", TARGETING::get_huid(io_addrInfo.fsiTarg), fsi_info.linkid.id );

    //FSI master is the master proc, find the port
    if( fsi_info.master == iv_master )
    {
        //append the appropriate offset
        io_addrInfo.absAddr += getPortOffset(fsi_info.type,fsi_info.port);
    }
    //verify this target has a valid FSI master
    else if( TARGETING::FSI_MASTER_TYPE_CMFSI != fsi_info.type )
    {
        TRACFCOMP( g_trac_fsi, "target=%.8X : Master Type is not supported = %d", TARGETING::get_huid(io_addrInfo.fsiTarg), fsi_info.type );
        /*@
         * @errortype
         * @moduleid     FSI::MOD_FSIDD_GENFULLFSIADDR
         * @reasoncode   FSI::RC_FSI_NOT_SUPPORTED
         * @userdata1    Target of FSI Operation
         * @userdata2[32:39]  Physical Node of FSI Master processor
         * @userdata2[40:47]  Physical Position of FSI Master processor
         * @userdata2[48:55]  FSI Master type (0=MFSI,1=CMFSI,2=NO_MASTER)
         * @userdata2[56:63]  Slave link/port number
         * @devdesc      FsiDD::genFullFsiAddr> Master Type is not supported
         */
        l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                     FSI::MOD_FSIDD_GENFULLFSIADDR,
                                     FSI::RC_FSI_NOT_SUPPORTED,
                                     TARGETING::get_huid(io_addrInfo.fsiTarg),
                                     fsi_info.linkid.id );
        l_err->collectTrace("FSI",1024);
        return l_err;
    }
    //target is behind another proc
    else
    {
        //append the CMFSI portion first
        io_addrInfo.absAddr += getPortOffset(fsi_info.type,fsi_info.port);

        //find this port's master and then get its port information
        FsiChipInfo_t mfsi_info = getFsiInfo(fsi_info.master);

        //check for invalid topology
        if( mfsi_info.master != iv_master )
        {
            TRACFCOMP( g_trac_fsi, "target=%.8X : master=%.8X : master's master=%.8X : Cannot chain 2 masters", TARGETING::get_huid(io_addrInfo.fsiTarg), TARGETING::get_huid(fsi_info.master), TARGETING::get_huid(mfsi_info.master), fsi_info.type );
            /*@
             * @errortype
             * @moduleid     FSI::MOD_FSIDD_GENFULLFSIADDR
             * @reasoncode   FSI::RC_INVALID_FSI_PATH_1
             * @userdata1[0:31]   Target of FSI Operation
             * @userdata1[32:63]  Target's FSI Master Chip
             * @userdata2[0:7]    Physical Node of FSI Master processor  [target's master]
             * @userdata2[8:15]   Physical Position of FSI Master processor  [target's master]
             * @userdata2[16:23]  FSI Master type (0=MFSI,1=CMFSI,2=NO_MASTER)  [target's master]
             * @userdata2[24:31]  Slave link/port number  [target's master]
             * @userdata2[32:39]  Physical Node of FSI Master processor  [master's master]
             * @userdata2[40:47]  Physical Position of FSI Master processor  [master's master]
             * @userdata2[48:55]  FSI Master type (0=MFSI,1=CMFSI,2=NO_MASTER)  [master's master]
             * @userdata2[56:63]  Slave link/port number  [master's master]
             * @devdesc      FsiDD::genFullFsiAddr> Cannot chain 2 masters
             */
            l_err = new ERRORLOG::ErrlEntry(
                              ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                              FSI::MOD_FSIDD_GENFULLFSIADDR,
                              FSI::RC_INVALID_FSI_PATH_1,
                              TWO_UINT32_TO_UINT64(
                                  TARGETING::get_huid(io_addrInfo.fsiTarg),
                                  TARGETING::get_huid(fsi_info.master)),
                              TWO_UINT32_TO_UINT64(
                                  fsi_info.linkid.id,
                                  mfsi_info.linkid.id) );
            l_err->collectTrace("FSI",1024);
            return l_err;
        }
        else if( TARGETING::FSI_MASTER_TYPE_MFSI != mfsi_info.type )
        {
            TRACFCOMP( g_trac_fsi, "target=%.8X : master=%.8X, type=%d, port=%d", TARGETING::get_huid(io_addrInfo.fsiTarg), TARGETING::get_huid(fsi_info.master), fsi_info.type, fsi_info.port );
            TRACFCOMP( g_trac_fsi, "Master: target=%.8X : master=%.8X, type=%d, port=%d", TARGETING::get_huid(fsi_info.master), TARGETING::get_huid(mfsi_info.master), mfsi_info.type, mfsi_info.port );
            /*@
             * @errortype
             * @moduleid     FSI::MOD_FSIDD_GENFULLFSIADDR
             * @reasoncode   FSI::RC_INVALID_FSI_PATH_2
             * @userdata1[0:31]   Target of FSI Operation
             * @userdata1[32:63]  Target's FSI Master Chip
             * @userdata2[0:7]    Physical Node of FSI Master processor  [target's master]
             * @userdata2[8:15]   Physical Position of FSI Master processor  [target's master]
             * @userdata2[16:23]  FSI Master type (0=MFSI,1=CMFSI,2=NO_MASTER)  [target's master]
             * @userdata2[24:31]  Slave link/port number  [target's master]
             * @userdata2[32:39]  Physical Node of FSI Master processor  [master's master]
             * @userdata2[40:47]  Physical Position of FSI Master processor  [master's master]
             * @userdata2[48:55]  FSI Master type (0=MFSI,1=CMFSI,2=NO_MASTER)  [master's master]
             * @userdata2[56:63]  Slave link/port number  [master's master]
             * @devdesc      FsiDD::genFullFsiAddr> Invalid master type for the target's master
             */
            l_err = new ERRORLOG::ErrlEntry(
                              ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                              FSI::MOD_FSIDD_GENFULLFSIADDR,
                              FSI::RC_INVALID_FSI_PATH_2,
                              TWO_UINT32_TO_UINT64(
                                  TARGETING::get_huid(io_addrInfo.fsiTarg),
                                  TARGETING::get_huid(fsi_info.master)),
                              TWO_UINT32_TO_UINT64(
                                  fsi_info.linkid.id,
                                  mfsi_info.linkid.id) );
            l_err->collectTrace("FSI",1024);
            return l_err;
        }

        //powerbus is alive
        if( (fsi_info.master)->getAttr<TARGETING::ATTR_SCOM_SWITCHES>().useXscom )
        {
            io_addrInfo.opbTarg = fsi_info.master;
            // Note: no need to append the MFSI port since it is now local
        }
        else
        {
            //using the master chip so we need to append the MFSI port
            io_addrInfo.absAddr += getPortOffset(mfsi_info.type,mfsi_info.port);
        }
    }

    return NULL;
}

/**
 * @brief Generate a valid SCOM address to access the OPB, this will
 *    choose the correct master
 */
uint64_t FsiDD::genOpbScomAddr(FsiAddrInfo_t& i_addrInfo,
                               uint64_t i_opbOffset)
{
    //@todo: handle redundant FSI ports, always using zero for now (Story 35041)
    //       this might be needed to handle multi-chip config in simics because
    //       proc2 is connected to port B
    uint64_t opbaddr = FSI2OPB_OFFSET_0 | i_opbOffset;
    return opbaddr;
}

/**
 * @brief Initializes the FSI link to allow slave access
 */
errlHndl_t FsiDD::initPort(FsiChipInfo_t i_fsiInfo,
                           bool& o_enabled)
{
    errlHndl_t l_err = NULL;
    TRACFCOMP( g_trac_fsi, ENTER_MRK"FsiDD::initPort> Initializing %.8X", i_fsiInfo.linkid.id );
    o_enabled = false;

    do {
        uint32_t databuf = 0;

        uint8_t portbit = 0x80 >> i_fsiInfo.port;

        // need to add the extra MFSI port offset for a remote cMFSI
        uint64_t master_offset = 0;
        if( (TARGETING::FSI_MASTER_TYPE_CMFSI == i_fsiInfo.type)
            && (i_fsiInfo.master != iv_master) )
        {
            // look up the FSI information for this target's master
            FsiChipInfo_t mfsi_info = getFsiInfo(i_fsiInfo.master);

            // append the master's port offset to the slave's
            master_offset = getPortOffset( TARGETING::FSI_MASTER_TYPE_MFSI, mfsi_info.port );
        }

        // control register is determined by the type of port
        uint64_t master_ctl_reg = getControlReg(i_fsiInfo.type);
        master_ctl_reg += master_offset;

        // slave offset is determined by which port it is on
        uint64_t slave_offset = getPortOffset( i_fsiInfo.type, i_fsiInfo.port );
        slave_offset += master_offset;

        // nothing was detected on this port so this is just a NOOP
        if( !isSlavePresent(i_fsiInfo.master,i_fsiInfo.type,i_fsiInfo.port) )
        {
            TRACDCOMP( g_trac_fsi, "FsiDD::initPort> Slave %.8X is not present", i_fsiInfo.linkid.id );
#ifdef HOSTBOOT_DEBUG
            uint64_t slave_index = getSlaveEnableIndex(i_fsiInfo.master,i_fsiInfo.type);
            if( slave_index != INVALID_SLAVE_INDEX )
            {
                TRACDCOMP( g_trac_fsi, " : sensebits=%.2X, portbit=%.2X", iv_slaves[slave_index], portbit );
            }
#endif
            break;
        }
        TRACFCOMP( g_trac_fsi, "FsiDD::initPort> Slave %.8X is present", i_fsiInfo.linkid.id );

        // Do not initialize slaves because they are already done
        //  before we run
        TARGETING::Target * sys = NULL;
        TARGETING::targetService().getTopLevelTarget( sys );
        TARGETING::SpFunctions spfuncs;
        if( sys
            && sys->tryGetAttr<TARGETING::ATTR_SP_FUNCTIONS>(spfuncs)
            && spfuncs.fsiSlaveInit )
        {
            TRACFCOMP( g_trac_fsi, "FsiDD::initPort> Skipping Slave Init because SP did it" );
            o_enabled = true;
            break;
        }

        // Do not do any hardware initialization in mpipl
        uint8_t is_mpipl = 0;
        if( sys
            && sys->tryGetAttr<TARGETING::ATTR_IS_MPIPL_HB>(is_mpipl)
            && is_mpipl )
        {
            TRACFCOMP( g_trac_fsi, "FsiDD::initPort> Skipping Slave Init in MPIPL" );
            o_enabled = true;
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
            TRACFCOMP( g_trac_fsi, "FsiDD::initPort> Error after break to port %.8X, MAEB=%lX", i_fsiInfo.linkid.id, databuf );
            /*@
             * @errortype
             * @moduleid     FSI::MOD_FSIDD_INITPORT
             * @reasoncode   FSI::RC_ERROR_ENABLING_SLAVE
             * @userdata1[0:7]    Physical Node of FSI Master processor
             * @userdata1[8:15]   Physical Position of FSI Master processor
             * @userdata1[16:23]  FSI Master type (0=MFSI,1=CMFSI)
             * @userdata1[24:31]  Slave link/port number
             * @userdata2    MAEB from master
             * @devdesc      FsiDD::initPort> Error after sending BREAK
             */
            l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            FSI::MOD_FSIDD_INITPORT,
                                            FSI::RC_ERROR_ENABLING_SLAVE,
                                            i_fsiInfo.linkid.id,
                                            databuf);
            l_err->collectTrace("FSI");
            l_err->collectTrace("FSIR");
            break;
        }

        // Note: need to write to 3rd slave spot because the BREAK
        //   resets everything to that window
        if( TARGETING::FSI_MASTER_TYPE_CMFSI == i_fsiInfo.type )
        {
            slave_offset |= CMFSI_SLAVE_3;
        }
        else if( TARGETING::FSI_MASTER_TYPE_MFSI == i_fsiInfo.type )
        {
            slave_offset |= MFSI_SLAVE_3;
        }

        //Setup the FSI slave to enable HW recovery, lbus ratio
        // 2= Enable HW error recovery (bit 2)
        // 6:7=	Slave ID: 3 (default)
        // 8:11= Echo delay: 0xF (default)
        // 12:15= Send delay cycles: 0xF
        // 20:23= Local bus ratio: 0x1
        databuf = 0x23FF0100;
        l_err = write( slave_offset|FSI::SLAVE_MODE_00, &databuf );
        if( l_err ) { break; }

        //Note - this is a separate write because we want to have HW recovery
        //  enabled when we switch the window
        //Set FSI slave ID to 0 (move slave to 1st 2MB address window)
        // 6:7=	Slave ID: 0
        databuf = 0x20FF0100;
        l_err = write( slave_offset|FSI::SLAVE_MODE_00, &databuf );
        if( l_err ) { break; }

        //Note : from here on use the real cascade offset

#if 0 // skipping the config space reading because we're hardcoding engines
        //Read the config space
        for( uint64_t config_addr = slave_offset|FSI::SLAVE_CFG_TABLE;
             config_addr < (slave_offset|FSI::SLAVE_PEEK_TABLE);
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
        o_enabled = true;

    } while(0);

    TRACDCOMP( g_trac_fsi, EXIT_MRK"FsiDD::initPort" );
    return l_err;
}

/**
 * @brief Initializes the FSI master control registers
 */
errlHndl_t FsiDD::initMasterControl(TARGETING::Target* i_master,
                                    TARGETING::FSI_MASTER_TYPE i_type)
{
    errlHndl_t l_err = NULL;
    TRACFCOMP( g_trac_fsi, ENTER_MRK"FsiDD::initMasterControl> Initializing Master %.8X:%d", TARGETING::get_huid(i_master), i_type );

    do {
        // Do not initialize the masters because they are already
        //  working before we run
        bool fsp_master_init = false;
        TARGETING::Target * sys = NULL;
        TARGETING::targetService().getTopLevelTarget( sys );
        TARGETING::SpFunctions spfuncs = TARGETING::SpFunctions();
        if( sys
            && sys->tryGetAttr<TARGETING::ATTR_SP_FUNCTIONS>(spfuncs)
            && spfuncs.fsiMasterInit )
        {
            TRACFCOMP( g_trac_fsi, "FsiDD::initMasterControl> Skipping Master Init because SP did it" );
            fsp_master_init = true;
        }

        // Do not do any hardware initialization in mpipl
        uint8_t is_mpipl = 0;
        if( sys
            && sys->tryGetAttr<TARGETING::ATTR_IS_MPIPL_HB>(is_mpipl)
            && is_mpipl )
        {
            TRACFCOMP( g_trac_fsi, "FsiDD::initMasterControl> Skipping Master Init in MPIPL" );
        }

        uint32_t databuf = 0;

        //find the full offset to the master control reg
        //  first get the address of the control reg to use
        uint64_t ctl_reg = getControlReg(i_type);
        //  append the master port offset to get to the remote master
        if( i_master != iv_master )
        {
            FsiChipInfo_t m_info = getFsiInfo(i_master);
            ctl_reg += getPortOffset(TARGETING::FSI_MASTER_TYPE_MFSI,m_info.port);
        }

        if( !fsp_master_init && !is_mpipl )
        {
            //Clear fsi port errors and general reset on all ports
            for( uint32_t port = 0; port < MAX_SLAVE_PORTS; ++port )
            {
                // 2= General reset to all bridges
                // 3= General reset to all port controllers
                databuf = 0x30000000;
                l_err = write( ctl_reg|FSI_MRESP0_0D0|(port*4), &databuf );
                if( l_err ) { break; }
            }
            if( l_err ) { break; }

            //Freeze FSI Port on FSI/OPB bridge error (global)
            // 18= Freeze FSI port on FSI/OPB bridge error
            databuf = 0x00002000;
            l_err = write( ctl_reg|FSI_MECTRL_2E0, &databuf );
            if( l_err ) { break; }


            //Set MMODE reg to enable HW recovery, parity checking,
            //  setup clock ratio
            // 1= Enable hardware error recovery
            // 3= Enable parity checking
            // 4:13= FSI clock ratio 0 is 1:1
            // 14:23= FSI clock ratio 1 is 4:1
            databuf = 0x50040400;
            //Hardware Bug HW204566 on Murano DD1.0 requires legacy
            //  mode to be enabled
            if( (i_master->getAttr<TARGETING::ATTR_MODEL>()
                                      == TARGETING::MODEL_MURANO) )
            {
                uint32_t ec_level = 0x00;
                uint32_t idec = 0;
                if( i_master != iv_master )
                {
                    // get the data via FSI (scom engine)
                    FsiAddrInfo_t addr_info( i_master, 0x1028 );
                    l_err = genFullFsiAddr( addr_info );
                    if( l_err ) { break; }

                    // perform the read operation
                    l_err = read( addr_info, &idec );
                    if( l_err ) { break; }
                    TRACFCOMP( g_trac_fsi, "FSI=%X", idec );
                }
                else
                {
                    // have to use the scom version on the master chip
                    uint32_t scom_data[2];
                    size_t scom_size = sizeof(scom_data);
                    l_err = deviceOp( DeviceFW::READ,
                                      TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL,
                                      scom_data,
                                      scom_size,
                                      DEVICE_XSCOM_ADDRESS(0x000F000F) );
                    if( l_err ) { break; }

                    scom_data[0] = 0x1f0fffff;
                    idec = scom_data[0];
                }
                ec_level = (idec & 0xF0000000) >> 24;
                ec_level |= ((idec & 0x00F00000) >> 20);

                TRACFCOMP( g_trac_fsi, "%.8X: EC=%X", TARGETING::get_huid(i_master), ec_level );
                if( ec_level == 0x10 )
                {
                    // 25=clock/4 mode
                    databuf |= 0x00000040;
                }
            }
            l_err = write( ctl_reg|FSI_MMODE_000, &databuf );
            if( l_err ) { break; }
        }

        //NOTE: Need to do slave detection even in non-init cases
        //  because we cache this data up to use later

        //Determine which links are present
        l_err = read( ctl_reg|FSI_MLEVP0_018, &databuf );
        if( l_err ) { break; }

        //Read what FSP actually enabled as well if they initialized it
        if( spfuncs.fsiSlaveInit )
        {
            uint32_t databuf2 = 0;
            l_err = read( ctl_reg|FSI_MENP0_010, &databuf2 );
            if( l_err ) { break; }

            //Only use slaves that we sense and FSP has enabled
            databuf = databuf & databuf2;
        }

        // Only looking at the top bits
        uint64_t slave_index = getSlaveEnableIndex(i_master,i_type);
        iv_slaves[slave_index] = (uint8_t)(databuf >> (32-MAX_SLAVE_PORTS));
        TRACFCOMP( g_trac_fsi, "FsiDD::initMasterControl> %.8X:%d : Slave Detect = %.8X", TARGETING::get_huid(i_master), i_type, databuf );

        if( fsp_master_init || is_mpipl )
        {
            break; //all done
        }

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
        TRACFCOMP( g_trac_fsi, "FsiDD::initMasterControl> Error during initialization of Target %.8X : RC=%llX", TARGETING::get_huid(i_master), l_err->reasonCode() );
        uint64_t slave_index = getSlaveEnableIndex(i_master,i_type);
        iv_slaves[slave_index] = 0;
    }

    TRACDCOMP( g_trac_fsi, EXIT_MRK"FsiDD::initMasterControl" );
    return l_err;
}


/**
 * @brief Convert a type/port pair into a FSI address offset
 */
uint64_t FsiDD::getPortOffset(TARGETING::FSI_MASTER_TYPE i_type,
                              uint8_t i_port)
{
    uint64_t offset = 0;
    if( TARGETING::FSI_MASTER_TYPE_MFSI == i_type )
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
    else if( TARGETING::FSI_MASTER_TYPE_CMFSI == i_type )
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

/**
 * @brief Retrieve the slave enable index
 */
uint64_t FsiDD::getSlaveEnableIndex( TARGETING::Target* i_master,
                                     TARGETING::FSI_MASTER_TYPE i_type )
{
    if( i_master == NULL )
    {
        return INVALID_SLAVE_INDEX;
    }

    //default to local slave ports
    uint64_t slave_index = MAX_SLAVE_PORTS+i_type;
    if( i_master != iv_master )
    {
        FsiChipInfo_t m_info = getFsiInfo(i_master);
        if( m_info.type == TARGETING::FSI_MASTER_TYPE_NO_MASTER )
        {
            slave_index = INVALID_SLAVE_INDEX;
        }
        else
        {
            slave_index = m_info.port;
        }
    }
    return slave_index;
};

/**
 * @brief Retrieve the connection information needed to access FSI
 *        registers within the given chip target
 */
FsiDD::FsiChipInfo_t FsiDD::getFsiInfo( TARGETING::Target* i_target )
{
    FsiChipInfo_t info;
    info.master = NULL;
    info.type = TARGETING::FSI_MASTER_TYPE_NO_MASTER;
    info.port = 0;
    info.cascade = 0;
    info.flags = 0;
    info.linkid.id = 0;

    using namespace TARGETING;

    EntityPath epath;

    if( (i_target != NULL) &&
        i_target->tryGetAttr<ATTR_FSI_MASTER_TYPE>(info.type) )
    {
        if( info.type != FSI_MASTER_TYPE_NO_MASTER )
        {
            if( i_target->tryGetAttr<ATTR_FSI_MASTER_CHIP>(epath) )
            {
                info.master = targetService().toTarget(epath);

                if( i_target->tryGetAttr<ATTR_FSI_MASTER_PORT>(info.port) )
                {
                    if( i_target->tryGetAttr<ATTR_FSI_SLAVE_CASCADE>(info.cascade) )
                    {
                        if( !i_target->tryGetAttr<ATTR_FSI_OPTION_FLAGS>(info.flags) )
                        {
                            info.master = NULL;
                        }
                    }
                    else
                    {
                        info.master = NULL;
                    }
                }
                else
                {
                    info.master = NULL;
                }
            }
            else
            {
                info.master = NULL;
            }
        }
    }


    if( (info.master == NULL) || (info.type == FSI_MASTER_TYPE_NO_MASTER) )
    {
        info.master = NULL;
        info.type = FSI_MASTER_TYPE_NO_MASTER;
        info.port = 0;
        info.cascade = 0;
        info.flags = 0;
        info.linkid.id = 0;
    }
    else
    {
        TARGETING::EntityPath epath;
        if( info.master->tryGetAttr<TARGETING::ATTR_PHYS_PATH>(epath) )
        {
            info.linkid.node =
              epath.pathElementOfType(TARGETING::TYPE_NODE).instance;
            info.linkid.proc =
              epath.pathElementOfType(TARGETING::TYPE_PROC).instance;
            info.linkid.type = static_cast<uint8_t>(info.type);
            info.linkid.port = info.port;
        }
    }

    TRACUCOMP( g_trac_fsi, "getFsiInfo> i_target=%.8X : master=%.8X, type=%X", TARGETING::get_huid(i_target), TARGETING::get_huid(info.master), info.type );
    TRACUCOMP( g_trac_fsi, "getFsiInfo> port=%X, cascade=%X, flags=%X, linkid=%.8X", info.port, info.cascade, info.flags, info.port );
    return info;
}

/**
 * @brief Retrieves the status of a given port
 */
bool FsiDD::isSlavePresent( TARGETING::Target* i_fsiMaster,
                            TARGETING::FSI_MASTER_TYPE i_type,
                            uint8_t i_port )
{
    if( (i_port < MAX_SLAVE_PORTS)
        && (TARGETING::FSI_MASTER_TYPE_NO_MASTER != i_type)
        && (NULL != i_fsiMaster) )
    {
        uint64_t slave_index = getSlaveEnableIndex(i_fsiMaster,i_type);
        if( INVALID_SLAVE_INDEX == slave_index )
        {
            return false;
        }
        else
        {
            return ( iv_slaves[slave_index] & (0x80 >> i_port) );
        }
    }
    else
    {
        return false;
    }
}

/**
 * @brief Retrieves the FSI status of a given chip
 */
bool FsiDD::isSlavePresent( TARGETING::Target* i_target )
{
    // look up the FSI information for this target
    FsiChipInfo_t info = getFsiInfo(i_target);
    return isSlavePresent( info.master, info.type, info.port );
}

