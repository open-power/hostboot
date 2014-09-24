/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/lpc/lpcdd.C $                                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
 *  @file lpcdd.C
 *
 *  @brief Implementation of the LPC Device Driver
 */

#include <sys/mmio.h>
#include <sys/task.h>
#include <sys/sync.h>
#include <string.h>
#include <devicefw/driverif.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <targeting/common/targetservice.H>
#include <errl/errlmanager.H>
#include "lpcdd.H"
#include <sys/time.h>
#include <lpc/lpc_reasoncodes.H>
#include <initservice/initserviceif.H>
#include <kernel/console.H> //@todo - RTC:97495 -- Resolve console access
#include <errl/errludlogregister.H>
#include <initservice/taskargs.H>
#include <config.h>


trace_desc_t* g_trac_lpc;
TRAC_INIT( & g_trac_lpc, LPC_COMP_NAME, 2*KILOBYTE, TRACE::BUFFER_SLOW);

// Set to enable LPC tracing.
//#define LPC_TRACING 1
#ifdef LPC_TRACING
#define LPC_TRACFCOMP(des,printf_string,args...) \
    TRACFCOMP(des,printf_string,##args)
#else
#define LPC_TRACFCOMP(args...)
#endif

// Device Drive instance used for alt-master access
static LpcDD* g_altLpcDD = NULL;

namespace LPC
{
/**
 * @brief Performs an LPC Read Operation
 *
 * @param[in]   i_opType        Operation type, see DeviceFW::OperationType
 *                              in driverif.H
 * @param[in]   i_target        LPC target
 * @param[in/out] io_buffer     Read: Pointer to output data storage
 *                              Write: Pointer to input data storage
 * @param[in/out] io_buflen     Input: size of io_buffer (in bytes)
 *                              Output:
 *                                  Read: Size of output data
 *                                  Write: Size of data written
 * @param[in]   i_accessType    DeviceFW::AccessType enum (usrif.H)
 * @param[in]   i_args          This is an argument list for DD framework.
 * @return  errlHndl_t
 */
errlHndl_t lpcRead(DeviceFW::OperationType i_opType,
                   TARGETING::Target* i_target,
                   void* io_buffer,
                   size_t& io_buflen,
                   int64_t i_accessType, va_list i_args)
{
    LPC::TransType l_type = static_cast<LPC::TransType>(
        va_arg(i_args,uint64_t) );
    uint64_t l_addr = va_arg(i_args,uint64_t);
    errlHndl_t l_err = NULL;

    assert( io_buflen == sizeof(uint8_t) ||
        io_buflen == sizeof(uint16_t) ||
        io_buflen == sizeof(uint32_t) );

    // if the request is for something besides the master sentinel
    //  then we have to use our special side copy of the driver
    if( i_target == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL )
    {
        l_err = Singleton<LpcDD>::instance().readLPC( l_type,
                                                      l_addr,
                                                      io_buffer,
                                                      io_buflen );
    }
    else
    {
        if( g_altLpcDD
            && (i_target == g_altLpcDD->getProc()) )
        {
            l_err = g_altLpcDD->readLPC( l_type,
                                         l_addr,
                                         io_buffer,
                                         io_buflen );
        }
        else
        {
            TRACFCOMP( g_trac_lpc, "Unexpected target for LPC read : i_target=%.8X", TARGETING::get_huid(i_target) );
            uint32_t alt_huid = 0;
            if( g_altLpcDD )
            {
                alt_huid = TARGETING::get_huid(g_altLpcDD->getProc());
            }
            /*@
             * @errortype
             * @moduleid     LPC::MOD_READLPC
             * @reasoncode   LPC::RC_BAD_TARGET
             * @userdata1[00:31]    Requested target
             * @userdata1[00:31]    Current alt target
             * @userdata2    Read address
             * @devdesc      readLPC> Unexpected target
             * @custdesc     Firmware error during boot flash diagnostics
             */
            l_err = new ERRORLOG::ErrlEntry(
                                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            LPC::MOD_READLPC,
                                            LPC::RC_BAD_TARGET,
                                            TWO_UINT32_TO_UINT64(
                                                TARGETING::get_huid(i_target),
                                                alt_huid ),
                                            l_addr,
                                            true /*SW error*/);
            l_err->collectTrace(PNOR_COMP_NAME);
            l_err->collectTrace(LPC_COMP_NAME);
        }
    }

    return l_err;
}

/**
 * @brief Performs a LPC Write Operation
 * This function performs a LPC Write operation. It follows a pre-defined
 * prototype functions in order to be registered with the device-driver
 * framework.
 *
 * @param[in]   i_opType        Operation type, see DeviceFW::OperationType
 *                              in driverif.H
 * @param[in]   i_target        LPC target
 * @param[in/out] io_buffer     Read: Pointer to output data storage
 *                              Write: Pointer to input data storage
 * @param[in/out] io_buflen     Input: size of io_buffer (in bytes)
 *                              Output:
 *                                  Read: Size of output data
 *                                  Write: Size of data written
 * @param[in]   i_accessType    DeviceFW::AccessType enum (usrif.H)
 * @param[in]   i_args          This is an argument list for DD framework.
 * @return  errlHndl_t
 */
errlHndl_t lpcWrite(DeviceFW::OperationType i_opType,
                    TARGETING::Target* i_target,
                    void* io_buffer,
                    size_t& io_buflen,
                    int64_t i_accessType, va_list i_args)
{
    LPC::TransType l_type = static_cast<LPC::TransType>(
        va_arg(i_args,uint64_t) );
    uint64_t l_addr = va_arg(i_args,uint64_t);
    errlHndl_t l_err = NULL;

    assert( io_buflen == sizeof(uint8_t) ||
        io_buflen == sizeof(uint16_t) ||
        io_buflen == sizeof(uint32_t) );

    // if the request is for something besides the master sentinel
    //  then we have to use our special side copy of the driver
    if( i_target == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL )
    {
        l_err = Singleton<LpcDD>::instance().writeLPC( l_type,
                                                       l_addr,
                                                       io_buffer,
                                                       io_buflen );
    }
    else
    {
        if( g_altLpcDD
            && (i_target == g_altLpcDD->getProc()) )
        {
            l_err = g_altLpcDD->writeLPC( l_type,
                                          l_addr,
                                          io_buffer,
                                          io_buflen );
        }
        else
        {
            TRACFCOMP( g_trac_lpc, "Unexpected target for LPC write : i_target=%.8X", TARGETING::get_huid(i_target) );
            uint32_t alt_huid = 0;
            if( g_altLpcDD )
            {
                alt_huid = TARGETING::get_huid(g_altLpcDD->getProc());
            }
            /*@
             * @errortype
             * @moduleid     LPC::MOD_WRITELPC
             * @reasoncode   LPC::RC_BAD_TARGET
             * @userdata1[00:31]    Requested target
             * @userdata1[00:31]    Current alt target
             * @userdata2    Write address
             * @devdesc      writeLPC> Unexpected target
             * @custdesc     Firmware error during boot flash diagnostics
             */
            l_err = new ERRORLOG::ErrlEntry(
                                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            LPC::MOD_WRITELPC,
                                            LPC::RC_BAD_TARGET,
                                            TWO_UINT32_TO_UINT64(
                                                TARGETING::get_huid(i_target),
                                                alt_huid ),
                                            l_addr,
                                            true /*SW error*/);
            l_err->collectTrace(PNOR_COMP_NAME);
            l_err->collectTrace(LPC_COMP_NAME);
        }
    }

    return l_err;

}

// Register LPC access functions to DD framework
DEVICE_REGISTER_ROUTE( DeviceFW::READ,
                       DeviceFW::LPC,
                       TARGETING::TYPE_PROC,
                       lpcRead );
DEVICE_REGISTER_ROUTE( DeviceFW::WRITE,
                       DeviceFW::LPC,
                       TARGETING::TYPE_PROC,
                       lpcWrite );


/**
 * @brief Create/delete software objects to support non-master access
 */
errlHndl_t create_altmaster_objects( bool i_create,
                                     TARGETING::Target* i_proc )
{
    TRACFCOMP(g_trac_lpc, "LPC::create_altmaster_objects> i_create=%d, i_proc=%.8X", i_create, TARGETING::get_huid(i_proc) );
    errlHndl_t l_err = NULL;

    do {
        if( i_create && g_altLpcDD )
        {
            TRACFCOMP(g_trac_lpc, "LPC::create_altmaster_objects> Alt-master object already exists");
            /*@
             * @errortype
             * @moduleid     LPC::MOD_CREATE_ALTMASTER
             * @reasoncode   LPC::RC_ALTMASTER_EXISTS
             * @userdata1    Requested proc
             * @userdata2    <unused>
             * @devdesc      create_altmaster_objects> Alt-master object
             *               already exists
             * @custdesc     Firmware error during boot flash diagnostics
             */
            l_err = new ERRORLOG::ErrlEntry(
                                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            LPC::MOD_CREATE_ALTMASTER,
                                            LPC::RC_ALTMASTER_EXISTS,
                                            TARGETING::get_huid(i_proc),
                                            0,
                                            true /*SW error*/);

            l_err->collectTrace(PNOR_COMP_NAME);
            l_err->collectTrace(LPC_COMP_NAME);
            break;
        }

        if( i_create )
        {
            if( i_proc == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL )
            {
                TRACFCOMP(g_trac_lpc, "LPC::create_altmaster_objects> Cannot create another object using master sentinel");
                /*@
                 * @errortype
                 * @moduleid     LPC::MOD_CREATE_ALTMASTER
                 * @reasoncode   LPC::RC_CANT_USE_SENTINEL
                 * @userdata1    <unused>
                 * @userdata2    <unused>
                 * @devdesc      create_altmaster_objects> Cannot create
                 *               another object using master sentinel
                 * @custdesc     Firmware error during boot flash diagnostics
                 */
                l_err = new ERRORLOG::ErrlEntry(
                                           ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           LPC::MOD_CREATE_ALTMASTER,
                                           LPC::RC_CANT_USE_SENTINEL,
                                           0,
                                           0,
                                           true /*SW error*/);

                l_err->collectTrace(PNOR_COMP_NAME);
                l_err->collectTrace(LPC_COMP_NAME);
                break;
            }

            // Check if input processor is MASTER
            TARGETING::ATTR_PROC_MASTER_TYPE_type type_enum =
              i_proc->getAttr<TARGETING::ATTR_PROC_MASTER_TYPE>();
            if ( type_enum == TARGETING::PROC_MASTER_TYPE_ACTING_MASTER )
            {
                TRACFCOMP(g_trac_lpc, "LPC::create_altmaster_objects> Cannot create another object using master proc");
                /*@
                 * @errortype
                 * @moduleid     LPC::MOD_CREATE_ALTMASTER
                 * @reasoncode   LPC::RC_CANT_USE_MASTER
                 * @userdata1    <unused>
                 * @userdata2    <unused>
                 * @devdesc      create_altmaster_objects> Cannot create
                 *               another object using master proc
                 * @custdesc     Firmware error during boot flash diagnostics
                 */
                l_err = new ERRORLOG::ErrlEntry(
                                           ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           LPC::MOD_CREATE_ALTMASTER,
                                           LPC::RC_CANT_USE_MASTER,
                                           0,
                                           0,
                                           true /*SW error*/);

                l_err->collectTrace(PNOR_COMP_NAME);
                l_err->collectTrace(LPC_COMP_NAME);
                break;
            }

            g_altLpcDD = new LpcDD( i_proc );
        }
        else
        {
            if( g_altLpcDD )
            {
                delete g_altLpcDD;
            }
            else
            {
                TRACFCOMP(g_trac_lpc,"LPC::create_altmaster_objects> Nothing to remove, but not a big deal");
            }
        }
    } while(0);

    return l_err;
}

}; //namespace LPC

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

mutex_t LpcDD::cv_mutex = MUTEX_INITIALIZER;

LpcDD::LpcDD( TARGETING::Target* i_proc )
: ivp_mutex(NULL)
,iv_proc(i_proc)
,iv_ffdcActive(false)
,iv_errorHandledCount(0)
,iv_errorRecoveryFailed(false)
,iv_resetActive(false)
{
    TRACFCOMP(g_trac_lpc, "LpcDD::LpcDD> " );

    mutex_init( &iv_mutex );

    if( i_proc == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL )
    {
        ivp_mutex = &cv_mutex;
    }
    else
    {
        // Master target could collide and cause deadlocks with singleton
        // used for ddRead/ddWrite with MASTER_PROCESSOR_CHIP_TARGET_SENTINEL
        TARGETING::Target* master = NULL;
        TARGETING::targetService().masterProcChipTargetHandle( master );
        assert( i_proc != master );

        // Just use the local mutex
        ivp_mutex = &iv_mutex;
    }

    // Initialize the hardware
    errlHndl_t l_errl = hwReset(LpcDD::RESET_INIT);
    if( l_errl )
    {
        TRACFCOMP( g_trac_lpc, "Errors initializing LPC logic... Beware! PLID=%.8X", l_errl->plid() );
        errlCommit(l_errl, LPC_COMP_ID);
    }
}

LpcDD::~LpcDD()
{
    mutex_destroy( &iv_mutex );
}

/**
 * @brief Reset hardware to get into clean state
 */
errlHndl_t LpcDD::hwReset( ResetLevels i_resetLevel )
{
    TRACFCOMP( g_trac_lpc, ENTER_MRK"LpcDD::hwReset(i_resetLevel=%d)>", i_resetLevel );
    errlHndl_t l_err = NULL;

    // check iv_resetActive to avoid infinite loops
    // and don't reset if in the middle of FFDC collection
    // and don't bother if we already failed the recovery once
    if ( ( iv_resetActive == false ) &&
         ( iv_ffdcActive == false  ) &&
         ( iv_errorRecoveryFailed == false) )
    {
        iv_resetActive = true;

        do {
            // always read/write 64 bits to SCOM
            uint64_t scom_data_64 = 0x0;
            size_t scom_size = sizeof(uint64_t);

            /***************************************/
            /* Handle the different reset levels   */
            /***************************************/
            switch(i_resetLevel)
            {
                case RESET_CLEAR:
                    {// Nothing to do here, so just break
                        break;
                    }

                case RESET_ECCB:
                    {
                        // Write Reset Register to reset FW Logic registers
                        TRACFCOMP(g_trac_lpc, "LpcDD::hwReset> Writing ECCB_RESET_REG to reset ECCB FW Logic");
                        scom_data_64 = 0x0;
                        l_err = deviceOp( DeviceFW::WRITE,
                                      iv_proc,
                                      &(scom_data_64),
                                      scom_size,
                                      DEVICE_SCOM_ADDRESS(ECCB_RESET_REG) );

                        break;
                    }

                case RESET_OPB_LPCHC_SOFT:
                    {
                        TRACFCOMP(g_trac_lpc, "LpcDD::hwReset> Writing OPB_MASTER_LS_CONTROL_REG to disable then enable First Error Data Capture");

                        size_t opsize = sizeof(uint32_t);

                        // First read OPB_MASTER_LS_CONTROL_REG
                        uint32_t lpc_data = 0x0;
                        l_err = _readLPC( LPC::TRANS_REG,
                                          OPB_MASTER_LS_CONTROL_REG,
                                          &lpc_data,
                                          opsize );

                        if (l_err) { break; }

                        // Disable 'First Error Data Capture'
                        // - set bit 29 to 0b1
                        lpc_data |= 0x00000004;

                        l_err = _writeLPC( LPC::TRANS_REG,
                                           OPB_MASTER_LS_CONTROL_REG,
                                           &lpc_data,
                                           opsize );
                        if (l_err) { break; }


                        // Enable 'First Error Data Capture' - set bit 29 to 0b0
                        // No wait-time needed
                        lpc_data &= 0xFFFFFFFB;

                        l_err = _writeLPC( LPC::TRANS_REG,
                                           OPB_MASTER_LS_CONTROL_REG,
                                           &lpc_data,
                                           opsize );

                        if (l_err) { break; }

                        // Clear FIR register
                        scom_data_64 = ~(OPB_LPCM_FIR_ERROR_MASK);
                        l_err = deviceOp(
                             DeviceFW::WRITE,
                             iv_proc,
                             &(scom_data_64),
                             scom_size,
                             DEVICE_SCOM_ADDRESS(OPB_LPCM_FIR_WOX_AND_REG) );
                        if (l_err) { break; }

                        break;
                    }

                case RESET_OPB_LPCHC_HARD:
                    {
                        TRACFCOMP(g_trac_lpc, "LpcDD::hwReset> Writing LPCHC_RESET_REG to reset LPCHC Logic");

                        size_t opsize = sizeof(uint32_t);
                        uint32_t lpc_data = 0x0;
                        l_err = _writeLPC( LPC::TRANS_REG,
                                           LPCHC_RESET_REG,
                                           &lpc_data,
                                           opsize );
                        if (l_err) { break; }

                        // sleep 1ms for LPCHC to execute internal
                        // reset+init sequence
                        nanosleep( 0, NS_PER_MSEC );

                        // Clear FIR register
                        scom_data_64 = ~(OPB_LPCM_FIR_ERROR_MASK);
                        l_err = deviceOp(
                             DeviceFW::WRITE,
                             iv_proc,
                             &(scom_data_64),
                             scom_size,
                             DEVICE_SCOM_ADDRESS(OPB_LPCM_FIR_WOX_AND_REG) );
                        if (l_err) { break; }

                        break;
                    }

                    // else - unsupported reset level
                default:
                    {

                        TRACFCOMP( g_trac_lpc, ERR_MRK"LpcDD::hwReset> Unsupported Reset Level Passed In: 0x%X", i_resetLevel);

                        /*@
                         * @errortype
                         * @moduleid     LPC::MOD_LPCDD_HWRESET
                         * @reasoncode   LPC::RC_UNSUPPORTED_OPERATION
                         * @userdata1    Unsupported Reset Level Parameter
                         * @userdata2    <unused>
                         * @devdesc      LpcDD::hwReset> Unsupported Reset Level
                         *               requested
                         */
                        l_err = new ERRORLOG::ErrlEntry(
                                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            LPC::MOD_LPCDD_HWRESET,
                                            LPC::RC_UNSUPPORTED_OPERATION,
                                            i_resetLevel,
                                            0,
                                            true /*SW error*/);

                        l_err->collectTrace(PNOR_COMP_NAME);
                        l_err->collectTrace(LPC_COMP_NAME);

                        break;
                    }
            }// end switch

            if ( l_err )
            {
                // Indicate that we weren't successful in resetting LPC
                iv_errorRecoveryFailed = true;
                TRACFCOMP( g_trac_lpc,ERR_MRK"LpcDD::hwReset> Fail doing LPC reset at level 0x%X (recovery count=%d): eid=0x%X", i_resetLevel, iv_errorHandledCount, l_err->eid());
            }
            else
            {
                // Successful, so increment recovery count
                if( i_resetLevel != RESET_CLEAR )
                {
                    iv_errorHandledCount++;
                }

                TRACFCOMP( g_trac_lpc,INFO_MRK"LpcDD::hwReset> Successful LPC reset at level 0x%X (recovery count=%d)", i_resetLevel, iv_errorHandledCount);
            }


        } while(0);

        // reset RESET active flag
        iv_resetActive = false;
    }

    TRACFCOMP( g_trac_lpc, EXIT_MRK"LpcDD::hwReset()=%.8X:%.4X", ERRL_GETEID_SAFE(l_err), ERRL_GETRC_SAFE(l_err) );
    return l_err;
}

/**
 * @brief Sanity check the input address for a LPC op and return
 *   full absolute address
 */
errlHndl_t LpcDD::checkAddr(LPC::TransType i_type,
                            uint32_t i_addr,
                            uint32_t *o_addr)
{
    bool invalid_address = false;
    switch ( i_type )
    {
        case LPC::TRANS_IO:
            if( i_addr >= 0x10000 )
            {
                invalid_address = true;
                break;
            }
            *o_addr = i_addr + LPCHC_IO_SPACE;
            break;
        case LPC::TRANS_MEM:
            if( i_addr >= 0x10000000 )
            {
                invalid_address = true;
                break;
            }
            *o_addr = i_addr + LPCHC_MEM_SPACE;
            break;
        case LPC::TRANS_FW:
            if( i_addr < LPCHC_FW_SPACE )
            {
                invalid_address = true;
                break;
            }
            *o_addr = i_addr;
            break;
        case LPC::TRANS_REG:
            if( i_addr >= 0x100 )
            {
                invalid_address = true;
                break;
            }
            *o_addr = i_addr + LPCHC_REG_SPACE;
            break;
        case LPC::TRANS_ABS:
            //Just use the address as given
            *o_addr = i_addr;
            break;
        default:
            invalid_address = true;
    }

    if( invalid_address )
    {
        /*@
         * @errortype
         * @moduleid     LPC::MOD_LPCDD_CHECKADDR
         * @reasoncode   LPC::RC_INVALID_ADDR
         * @userdata1[0:31]   LPC Address
         * @userdata1[32:63]  LPC Transaction Type
         * @devdesc      LpcDD> LPC invalid address
         * @custdesc     Firmware error accessing internal bus during IPL
         */
        return new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        LPC::MOD_LPCDD_CHECKADDR,
                                        LPC::RC_INVALID_ADDR,
                                        TWO_UINT32_TO_UINT64(
                                            i_addr, i_type),
                                        0,
                                        true/*SW Error*/);
    }

    return NULL;
}

/**
 * @brief Read an address from LPC space, assumes lock is already held
 */
errlHndl_t LpcDD::_readLPC(LPC::TransType i_type,
                           uint32_t i_addr,
                           void* o_buffer,
                           size_t& io_buflen)
{
    errlHndl_t l_err = NULL;
    uint32_t l_addr = 0;

    do {
        // Generate the full absolute LPC address
        l_err = checkAddr( i_type, i_addr, &l_addr );
        if( l_err ) { break; }

        // Execute command.
        ControlReg_t eccb_cmd;
        eccb_cmd.data_len = io_buflen;
        eccb_cmd.read_op = 1;
        eccb_cmd.addr_len = sizeof(l_addr);
        eccb_cmd.address = l_addr;
        size_t scom_size = sizeof(uint64_t);
        l_err = deviceOp( DeviceFW::WRITE,
                          iv_proc,
                          &(eccb_cmd.data64),
                          scom_size,
                          DEVICE_SCOM_ADDRESS(ECCB_CTL_REG) );
        if( l_err ) { break; }

        // Poll for completion
        StatusReg_t eccb_stat;
        l_err = pollComplete( eccb_cmd, eccb_stat );
        if( l_err ) { break; }

        // Copy data out to caller's buffer.
        if( io_buflen <= sizeof(uint32_t) )
        {
            uint32_t tmpbuf = eccb_stat.read_data;
            memcpy( o_buffer, &tmpbuf, io_buflen );
        }
        else
        {
            TRACFCOMP( g_trac_lpc, "readLPC> Unsupported buffer size : %d", io_buflen );
            /*@
             * @errortype
             * @moduleid     LPC::MOD_LPCDD_READLPC
             * @reasoncode   LPC::RC_BAD_ARG
             * @userdata1[0:31]   LPC Address
             * @userdata1[32:63]  LPC Transaction Type
             * @userdata2    Requested buffer size
             * @devdesc      LpcDD::_readLPC> Invalid buffer size requested
             *               (>4 bytes)
             * @custdesc     Firmware error accessing internal bus during IPL
             */
            l_err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                             LPC::MOD_LPCDD_READLPC,
                                             LPC::RC_BAD_ARG,
                                             TWO_UINT32_TO_UINT64(
                                                            i_addr, i_type),
                                             io_buflen,
                                             true/*SW Error*/);
            break;
        }

    } while(0);

    LPC_TRACFCOMP( g_trac_lpc, "readLPC> %08X[%d] = %08X", l_addr, io_buflen, *reinterpret_cast<uint32_t*>( o_buffer )  >> (8 * (4 - io_buflen)) );

    return l_err;
}

/**
 * @brief Write an address from LPC space, assumes lock is already held
 */
errlHndl_t LpcDD::_writeLPC(LPC::TransType i_type,
                            uint32_t i_addr,
                            const void* i_buffer,
                            size_t& io_buflen)
{
    errlHndl_t l_err = NULL;
    uint32_t l_addr = 0;

    do {
        // Generate the full absolute LPC address
        l_err = checkAddr( i_type, i_addr, &l_addr );
        if( l_err ) { break; }

        uint64_t eccb_data = 0;
        // Left-justify user data into data register.
        switch ( io_buflen )
        {
            case 1:
                eccb_data = static_cast<uint64_t>(
                   *reinterpret_cast<const uint8_t*>( i_buffer ) ) << 56;
                break;
            case 2:
                eccb_data = static_cast<uint64_t>(
                   *reinterpret_cast<const uint16_t*>( i_buffer ) ) << 48;
                break;
            case 4:
                eccb_data = static_cast<uint64_t>(
                   *reinterpret_cast<const uint32_t*>( i_buffer ) ) << 32;
                break;
            default:
                TRACFCOMP( g_trac_lpc, "writeLPC> Unsupported buffer size : %d", io_buflen );
                assert( false );
                break;
        }

        LPC_TRACFCOMP(g_trac_lpc, "writeLPC> %08X[%d] = %08X", l_addr, io_buflen,
                      eccb_data >> (32 + 8 * (4 - io_buflen)));

        // Write data out
        size_t scom_size = sizeof(uint64_t);
        l_err = deviceOp( DeviceFW::WRITE,
                          iv_proc,
                          &eccb_data,
                          scom_size,
                          DEVICE_SCOM_ADDRESS(ECCB_DATA_REG) );
        if( l_err ) { break; }

        // Execute command.
        ControlReg_t eccb_cmd;
        eccb_cmd.data_len = io_buflen;
        eccb_cmd.read_op = 0;
        eccb_cmd.addr_len = sizeof(l_addr);
        eccb_cmd.address = l_addr;
        l_err = deviceOp( DeviceFW::WRITE,
                          iv_proc,
                          &(eccb_cmd.data64),
                          scom_size,
                          DEVICE_SCOM_ADDRESS(ECCB_CTL_REG) );
        if( l_err ) { break; }

        // Poll for completion
        StatusReg_t eccb_stat;
        l_err = pollComplete( eccb_cmd, eccb_stat );
        if( l_err ) { break; }

    } while(0);

    return l_err;
}

/**
 * @brief Poll for completion of LPC operation
 */
errlHndl_t LpcDD::pollComplete(const ControlReg_t &i_ctrl,
                               StatusReg_t& o_stat)
{
    // Note: Caller must lock mutex before calling this function
    errlHndl_t l_err = NULL;
    ResetLevels l_resetLevel = RESET_CLEAR;

    do {
        uint64_t poll_time = 0;
        uint64_t loop = 0;
        do
        {
            size_t scom_size = sizeof(uint64_t);
            l_err = deviceOp( DeviceFW::READ,
                              iv_proc,
                              &(o_stat.data64),
                              scom_size,
                              DEVICE_SCOM_ADDRESS(ECCB_STAT_REG) );
            LPC_TRACFCOMP( g_trac_lpc, "writeLPC> Poll on ECCB Status, "
                           "poll_time=0x%.16x, stat=0x%.16x",
                           poll_time,
                           o_stat.data64 );
            if( l_err )
            {
                break;
            }

            if( o_stat.op_done )
            {
                break;
            }

            // want to start out incrementing by small numbers then get bigger
            //  to avoid a really tight loop in an error case so we'll increase
            //  the wait each time through
            nanosleep( 0, ECCB_POLL_INCR_NS*(++loop) );
            poll_time += ECCB_POLL_INCR_NS * loop;
        } while ( poll_time < ECCB_POLL_TIME_NS );

        // Check for hw errors or timeout if no previous logs
        if( (l_err == NULL) &&
            ((o_stat.data64 & ECCB_STAT_REG_ERROR_MASK)
             || (!o_stat.op_done)) )
        {
            TRACFCOMP( g_trac_lpc, "LpcDD::pollComplete> LPC error or timeout: "
                       "addr=0x%.8X, status=0x%.16X",
                       i_ctrl.address, o_stat.data64 );

            if( i_ctrl.read_op )
            {
                /*@
                 * @errortype
                 * @moduleid     LPC::MOD_LPCDD_READLPC
                 * @reasoncode   LPC::RC_ECCB_ERROR
                 * @userdata1[0:31]   LPC Address
                 * @userdata1[32:63]  Total poll time (ns)
                 * @userdata2    ECCB Status Register
                 * @devdesc      LpcDD::pollComplete> LPC error or timeout
                 * @custdesc     Hardware error accessing internal
                 *               bus during IPL
                 */
                l_err = new ERRORLOG::ErrlEntry(
                                          ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          LPC::MOD_LPCDD_READLPC,
                                          LPC::RC_ECCB_ERROR,
                                          TWO_UINT32_TO_UINT64(
                                                 i_ctrl.address, poll_time),
                                          o_stat.data64 );
            }
            else
            {
                /*@
                 * @errortype
                 * @moduleid     LPC::MOD_LPCDD_WRITELPC
                 * @reasoncode   LPC::RC_ECCB_ERROR
                 * @userdata1[0:31]   LPC Address
                 * @userdata1[32:63]  Total poll time (ns)
                 * @userdata2    ECCB Status Register
                 * @devdesc      LpcDD::pollComplete> LPC error or timeout
                 * @custdesc     Hardware error accessing internal
                 *               bus during IPL
                 */
                l_err = new ERRORLOG::ErrlEntry(
                                          ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          LPC::MOD_LPCDD_WRITELPC,
                                          LPC::RC_ECCB_ERROR,
                                          TWO_UINT32_TO_UINT64(
                                                 i_ctrl.address, poll_time),
                                          o_stat.data64 );
            }
            // Limited in callout: no LPC sub-target, so calling out processor
            l_err->addHwCallout( iv_proc,
                                 HWAS::SRCI_PRIORITY_HIGH,
                                 HWAS::NO_DECONFIG,
                                 HWAS::GARD_NULL );

            addFFDC(l_err);
            l_err->collectTrace(LPC_COMP_NAME);
            l_err->collectTrace(PNOR_COMP_NAME);
            l_err->collectTrace(XSCOM_COMP_NAME);

            // Reset ECCB - handled below
            l_resetLevel = RESET_ECCB;

            break;
        }

        // check for errors at OPB level
        l_err = checkForOpbErrors( l_resetLevel );
        if( l_err ) { break; }

    } while(0);

    // If we have an error that requires a reset, do that here
    if ( l_err && ( l_resetLevel != RESET_CLEAR ) )
    {
        errlHndl_t tmp_err = hwReset(l_resetLevel);

        if ( tmp_err )
        {
            // Commit reset error since we have original error l_err
            TRACFCOMP(g_trac_lpc, "LpcDD::pollComplete> Error from reset() after previous error eid=0x%X. Committing reset() error log eid=0x%X.", l_err->eid(), tmp_err->eid());

            tmp_err->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
            tmp_err->collectTrace(PNOR_COMP_NAME);
            tmp_err->collectTrace(LPC_COMP_NAME);
            tmp_err->plid(l_err->plid());
            errlCommit(tmp_err, LPC_COMP_ID);
        }
    }

    return l_err;
}

/**
 * @brief Add Error Registers to an existing Error Log
 */
void LpcDD::addFFDC(errlHndl_t & io_errl)
{
    // check iv_ffdcActive to avoid infinite loops
    if ( iv_ffdcActive == false )
    {
        iv_ffdcActive = true;

        TRACFCOMP( g_trac_lpc, "LpcDD::addFFDC> adding FFDC to Error Log EID=0x%X, PLID=0x%X",
                   io_errl->eid(), io_errl->plid() );

        ERRORLOG::ErrlUserDetailsLogRegister l_eud(iv_proc);

        do {
            // Add ECCB Status Register
            l_eud.addData(DEVICE_SCOM_ADDRESS(ECCB_STAT_REG));

            // Add OPB LPC Master FIR
            l_eud.addData(DEVICE_SCOM_ADDRESS(OPB_LPCM_FIR_REG));

            //@todo - add more LPC regs RTC:37744
            //LPCIRQ_STATUS = 0x38
            //SYS_ERR_ADDR = 0x40

        } while(0);


        l_eud.addToLog(io_errl);

        // reset FFDC active flag
        iv_ffdcActive = false;
    }

    return;
}

/**
 * @brief Check For Errors in OPB and LPCHC Status Registers
 */
errlHndl_t LpcDD::checkForOpbErrors( ResetLevels &o_resetLevel )
{
    errlHndl_t l_err = NULL;
    bool errorFound = false;

    // Used to set Reset Levels, if necessary
    o_resetLevel = RESET_CLEAR;

    // Default status values in case we fail in reading the registers
    OpbLpcmFirReg_t fir_reg;
    fir_reg.data64 = 0xDEADBEEFDEADBEEF;
    uint64_t fir_data = 0x0;

    // always read/write 64 bits to SCOM
    size_t scom_size = sizeof(uint64_t);

    do {
        // Read FIR Register
        l_err = deviceOp( DeviceFW::READ,
                          iv_proc,
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
            o_resetLevel = RESET_OPB_LPCHC_SOFT;
            TRACFCOMP( g_trac_lpc, ERR_MRK"LpcDD::checkForOpbErrors> Invalid Transfer Size: OPB_LPCM_FIR_REG=0x%.16X, ResetLevel=%d",
                       fir_reg.data64, o_resetLevel);
        }

        if( 1 == fir_reg.rxicmd )
        {
            errorFound = true;
            o_resetLevel = RESET_OPB_LPCHC_SOFT;
            TRACFCOMP( g_trac_lpc, ERR_MRK"LpcDD::checkForOpbErrors> Invalid Command: OPB_LPCM_FIR_REG=0x%.16X, ResetLevel=%d",
                       fir_reg.data64, o_resetLevel);
        }

        if( 1 == fir_reg.rxiaa )
        {
            errorFound = true;
            o_resetLevel = RESET_OPB_LPCHC_SOFT;
            TRACFCOMP( g_trac_lpc, ERR_MRK"LpcDD::checkForOpbErrors> Invalid Address Alignment: OPB_LPCM_FIR_REG=0x%.16X, ResetLevel=%d",
                       fir_reg.data64, o_resetLevel);
        }

        if( 1 == fir_reg.rxcbpe )
        {
            errorFound = true;
            o_resetLevel = RESET_OPB_LPCHC_SOFT;
            TRACFCOMP( g_trac_lpc, ERR_MRK"LpcDD::checkForOpbErrors> Command Buffer Parity Error: OPB_LPCM_FIR_REG=0x%.16X, ResetLevel=%d",
                       fir_reg.data64, o_resetLevel);
        }

        if( 1 == fir_reg.rxdbpe )
        {
            errorFound = true;
            o_resetLevel = RESET_OPB_LPCHC_SOFT;
            TRACFCOMP( g_trac_lpc, ERR_MRK"LpcDD::checkForOpbErrors> Data Buffer Parity Error: OPB_LPCM_FIR_REG=0x%.16X, ResetLevel=%d",
                       fir_reg.data64, o_resetLevel);
        }


        // Now look for HARD errors that will override SOFT errors reset Level
        if( 1 == fir_reg.rxhopbe )
        {
            errorFound = true;
            o_resetLevel = RESET_OPB_LPCHC_HARD;
            TRACFCOMP( g_trac_lpc, ERR_MRK"LpcDD::checkForOpbErrors> OPB Bus Error: OPB_LPCM_FIR_REG=0x%.16X, ResetLevel=%d",
                       fir_reg.data64, o_resetLevel);
        }

        if( 1 == fir_reg.rxhopbt )
        {
            errorFound = true;
            o_resetLevel = RESET_OPB_LPCHC_HARD;
            TRACFCOMP( g_trac_lpc, ERR_MRK"LpcDD::checkForOpbErrors> OPB Bus Timeout: OPB_LPCM_FIR_REG=0x%.16X, ResetLevel=%d",
                       fir_reg.data64, o_resetLevel);
        }

        if( 1 == fir_reg.rxctgtel )
        {
            errorFound = true;
            o_resetLevel = RESET_OPB_LPCHC_HARD;
            TRACFCOMP( g_trac_lpc, ERR_MRK"LpcDD::checkForOpbErrors> CI Load/CI Store/OPB Master Hang Timeout: OPB_LPCM_FIR_REG=0x%.16X, ResetLevel=%d",
                       fir_reg.data64, o_resetLevel);
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
            TRACFCOMP( g_trac_lpc, ERR_MRK"LpcDD::checkForOpbErrors> Deleting register read error. Returning error created for the found error");
            delete l_err;
        }

        /*@
         * @errortype
         * @moduleid     LPC::MOD_LPCDD_CHECKFOROPBERRORS
         * @reasoncode   LPC::RC_OPB_ERROR
         * @userdata1    OPB FIR Register Data
         * @userdata2    Reset Level
         * @devdesc      LpcDD::checkForOpbErrors> Error(s) found in OPB
         *               and/or LPCHC Status Register
         */
        l_err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                        LPC::MOD_LPCDD_CHECKFOROPBERRORS,
                                        LPC::RC_OPB_ERROR,
                                        fir_reg.data64,
                                        o_resetLevel );

        // Limited in callout: no PNOR target, so calling out processor
        l_err->addHwCallout( iv_proc,
                             HWAS::SRCI_PRIORITY_HIGH,
                             HWAS::NO_DECONFIG,
                             HWAS::GARD_NULL );


        // Log FIR Register Data
        ERRORLOG::ErrlUserDetailsLogRegister l_eud(iv_proc);

        l_eud.addDataBuffer(&fir_data, scom_size,
                            DEVICE_SCOM_ADDRESS(OPB_LPCM_FIR_REG));

        l_eud.addToLog(l_err);

        addFFDC(l_err);
        l_err->collectTrace(PNOR_COMP_NAME);
        l_err->collectTrace(LPC_COMP_NAME);

    }

    return l_err;

}


/**
 * @brief Read an address from LPC space
 */
errlHndl_t LpcDD::readLPC(LPC::TransType i_type,
                          uint32_t i_addr,
                          void* o_buffer,
                          size_t& io_buflen)
{
    // Grab the lock and call the internal function
    mutex_lock(ivp_mutex);
    errlHndl_t l_err = _readLPC( i_type, i_addr, o_buffer, io_buflen );
    mutex_unlock(ivp_mutex);
    return l_err;
}

/**
 * @brief Write an address to LPC space
 */
errlHndl_t LpcDD::writeLPC(LPC::TransType i_type,
                           uint32_t i_addr,
                           const void* i_buffer,
                           size_t& io_buflen)
{
    // Grab the lock and call the internal function
    mutex_lock(ivp_mutex);
    errlHndl_t l_err = _writeLPC( i_type, i_addr, i_buffer, io_buflen );
    mutex_unlock(ivp_mutex);
    return l_err;
}
