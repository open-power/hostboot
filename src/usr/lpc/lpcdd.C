/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/lpc/lpcdd.C $                                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2022                        */
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
#include <sys/mm.h>
#include <sys/task.h>
#include <sys/sync.h>
#include <string.h>
#include <devicefw/driverif.H>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <targeting/common/targetservice.H>
#include <errl/errlmanager.H>
#include "lpcxscom.H"
#include <lpc/lpc_const.H>
#include <sys/time.h>
#include <lpc/lpc_reasoncodes.H>
#include <initservice/initserviceif.H>
#include <kernel/console.H> //@todo - RTC:97495 -- Resolve console access
#include <kernel/bltohbdatamgr.H>
#include <errl/errludlogregister.H>
#include <initservice/taskargs.H>
#include <arch/memorymap.H>
#include <util/misc.H>
#include <errl/errlreasoncodes.H>

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
static LpcDD* g_altLpcDD = nullptr;

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

    // For speed, we support larger ops on FW space, otherwise
    // we are only able to do 1,2,4 byte LPC operations
    assert( (io_buflen == sizeof(uint8_t)) ||
            (io_buflen == sizeof(uint16_t)) ||
            (io_buflen == sizeof(uint32_t)) ||
                    (l_type == LPC::TRANS_FW) );

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
             * @errortype    ERRL_SEV_UNRECOVERABLE
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

    // For speed, we support larger ops on FW space, otherwise
    // we are only able to do 1,2,4 byte LPC operations
    assert( (io_buflen == sizeof(uint8_t)) ||
            (io_buflen == sizeof(uint16_t)) ||
            (io_buflen == sizeof(uint32_t)) ||
                    (l_type == LPC::TRANS_FW) );

    // if the request is for something besides the master sentinel
    //  then we have to use our special side copy of the driver
    if( i_target == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL )
    {
        l_err = Singleton<LpcDD>::instance().writeLPC(l_type,
                                                      l_addr,
                                                      io_buffer,
                                                      io_buflen);
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
             * @errortype    ERRL_SEV_UNRECOVERABLE
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
             * @errortype    ERRL_SEV_UNRECOVERABLE
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
                 * @errortype    ERRL_SEV_UNRECOVERABLE
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
                 * @errortype    ERRL_SEV_UNRECOVERABLE
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

            g_altLpcDD = new XscomLpc( i_proc );
        }
        else
        {
            if( g_altLpcDD )
            {
                delete g_altLpcDD;
                g_altLpcDD = nullptr;
            }
            else
            {
                TRACFCOMP(g_trac_lpc,"LPC::create_altmaster_objects> Nothing to remove, but not a big deal");
            }
        }
    } while(0);

    return l_err;
}

/**
 * @brief Return the value of the LPC BAR that the driver is using
 */
uint64_t get_lpc_bar( void )
{
    LpcDD l_LpcDD = Singleton<LpcDD>::instance();
    return mm_virt_to_phys( reinterpret_cast<void*>(
                            l_LpcDD.getLPCBaseAddr() )) -
                            l_LpcDD.getLPCStartAddr();
}

uint64_t get_lpc_virtual_bar( void )
{
    LpcDD l_LpcDD = Singleton<LpcDD>::instance();
    return (l_LpcDD.getLPCBaseAddr() - l_LpcDD.getLPCStartAddr());
}


/**
 * @brief Forces a checkstop when LPC Error(s) are seen such that PRD
 *        can appropriately handle the callout
 *
 * @return - void, since this function should theoretically not return
 */
void lpcForceCheckstopOnLpcErrors()
{
    // When LPC Error(s) are seen force a checkstop with this signature:
    // "EQ_L2_FIR[13] - NCU timed out waiting for powerbus to return data"
    // PRD running on the BMC (or the FSP) will then recognize this specific checkstop and handle
    // the callout appropriately

    TRACFCOMP(g_trac_lpc,"LPC::lpcForceCheckstopOnLpcErrors() Setting L2 FIR MASK to only "
              "allow bit13 through; setting ACTION0 and ACTION1 to all zeroes; then setting "
              "bit 13 in L3 FIR to force a checkstop");

    errlHndl_t l_err = nullptr;

    // Assume this function is called before targeting is up so use SENTINEL
    // (if targeting is already up, the LPC Xscom method should be used)
    TARGETING::Target* l_proc = TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL;

    const uint64_t data_all_clear    = 0x0000000000000000ull;
    const uint64_t data_all_set      = 0xFFFFFFFFFFFFFFFFull;
    const uint64_t data_clear_bit_13 = 0xFFFBFFFFFFFFFFFFull;
    const uint64_t data_set_bit_13   = 0x0004000000000000ull;

    // Using multicast scoms since we (1) have the processor target showing this fail
    // and (2) we can set this up on all cores, rather than just the boot core
    const uint64_t L2_FIR_MASK_REG_MULTICAST_SCOM_WOR  = 0x6E02F005ull;
    const uint64_t L2_FIR_MASK_REG_MULTICAST_SCOM_WAND = 0x6E02F004ull;
    const uint64_t L2_FIR_ACTION0_REG_MULTICAST_SCOM   = 0x6E02F006ull;
    const uint64_t L2_FIR_ACTION1_REG_MULTICAST_SCOM   = 0x6E02F007ull;
    const uint64_t L2_FIR_REG_MULTICAST_SCOM_WOR       = 0x6E02F002ull;


    // 1) write-OR L2 FIR MASK to disable everything
    uint64_t data = 0;
    size_t scomSize = sizeof(data);

    data = data_all_set;
    l_err = DeviceFW::deviceWrite(
                 l_proc,
                 &data,
                 scomSize,
                 DEVICE_SCOM_ADDRESS(L2_FIR_MASK_REG_MULTICAST_SCOM_WOR));
    if (l_err)
    {
        // Set the error to predictive, add trace, commit the log, but keep going in the
        // hope that we can still properly cause the checkstop
        l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
        l_err->collectTrace(LPC_COMP_NAME);
        ERRORLOG::errlCommit(l_err, LPC_COMP_ID);
    }

    // Steps 2 and 3 will set ACTION0 and ACTION1 registers such that the EQ_L2_FIR[13]
    // FIR bit will cause a checkstop
    // 2) write ACTION0 to zero (thus clearing bit 13)
    data = data_all_clear;
    l_err = DeviceFW::deviceWrite(
                 l_proc,
                 &data,
                 scomSize,
                 DEVICE_SCOM_ADDRESS(L2_FIR_ACTION0_REG_MULTICAST_SCOM));
    if (l_err)
    {
        // Set the error to predictive, add trace, commit the log, but keep going in the
        // hope that we can still properly cause the checkstop
        l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
        l_err->collectTrace(LPC_COMP_NAME);
        ERRORLOG::errlCommit(l_err, LPC_COMP_ID);
    }

    // 3) write ACTION1 to zero (this clearing bit 13)
    data = data_all_clear;
    l_err = DeviceFW::deviceWrite(
                 l_proc,
                 &data,
                 scomSize,
                 DEVICE_SCOM_ADDRESS(L2_FIR_ACTION1_REG_MULTICAST_SCOM));
    if (l_err)
    {
        // Set the error to predictive, add trace, commit the log, but keep going in the
        // hope that we can still properly cause the checkstop
        l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
        l_err->collectTrace(LPC_COMP_NAME);
        ERRORLOG::errlCommit(l_err, LPC_COMP_ID);
    }

    // 4) write-AND L2 FIR MASK to clear bit 13 to just allow this 1 attention through
    data = data_clear_bit_13;
    l_err = DeviceFW::deviceWrite(
                 l_proc,
                 &data,
                 scomSize,
                 DEVICE_SCOM_ADDRESS(L2_FIR_MASK_REG_MULTICAST_SCOM_WAND));
    if (l_err)
    {
        // Set the error to predictive, add trace, commit the log, but keep going in the
        // hope that we can still properly cause the checkstop
        l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
        l_err->collectTrace(LPC_COMP_NAME);
        ERRORLOG::errlCommit(l_err, LPC_COMP_ID);
    }

    // 5) write-OR FIR bit 13 to trigger checkstop
    data = data_set_bit_13;
    l_err = DeviceFW::deviceWrite(
                 l_proc,
                 &data,
                 scomSize,
                 DEVICE_SCOM_ADDRESS(L2_FIR_REG_MULTICAST_SCOM_WOR));
    if (l_err)
    {
        // Set the error to predictive, add trace, commit the log, but keep going in the
        // hope that we can still properly cause the checkstop
        l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
        l_err->collectTrace(LPC_COMP_NAME);
        ERRORLOG::errlCommit(l_err, LPC_COMP_ID);
    }

    // At this point the system should checkstop, but just return back
    // into the existing fail path if it doesn't
    return;
}



}; //namespace LPC

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

mutex_t LpcDD::cv_mutex = MUTEX_INITIALIZER;

LpcDD::LpcDD( TARGETING::Target* i_proc )
: iv_proc(i_proc)
,iv_ffdcActive(false)
,iv_resetActive(false)
,iv_errorRecoveryFailed(false)
,iv_errorHandledCount(0)
,ivp_mutex(nullptr)
{
    TRACFCOMP(g_trac_lpc, ENTER_MRK "LpcDD::LpcDD" );
    mutex_init( &iv_mutex );
    LPCBase_t baseAddr = 0;

    if( i_proc == TARGETING::MASTER_PROCESSOR_CHIP_TARGET_SENTINEL )
    {
        ivp_mutex = &cv_mutex;

        //Retrieve the LPC phys base from the bootloader/hostboot data manager
        baseAddr = g_BlToHbDataManager.getLpcBAR() + LPC_ADDR_START;
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

        //Correct LPC_BUS address attribute should be correct for alt_lpcdd
        baseAddr =   i_proc->getAttr<TARGETING::ATTR_LPC_BUS_ADDR>() + LPC_ADDR_START;
    }

    setLPCBaseAddr( static_cast<uint64_t *>(
                  mmio_dev_map(reinterpret_cast<void *>(baseAddr),
                               LPC_SPACE_SIZE )));

    /*  @todo RTC:126644
    Initialize the hardware
    errlHndl_t l_errl = hwReset(LpcDD::RESET_INIT);
    if( l_errl )
    {
        TRACFCOMP( g_trac_lpc, "Errors initializing LPC logic... Beware! PLID=%.8X", l_errl->plid() );
        errlCommit(l_errl, LPC_COMP_ID);
    }
    **/
    TRACFCOMP(g_trac_lpc, EXIT_MRK "LpcDD::LpcDD");
}

LpcDD::~LpcDD()
{
    TRACFCOMP(g_trac_lpc, ENTER_MRK "LpcDD::~LpcDD");
    mutex_destroy( &iv_mutex );
    TRACFCOMP(g_trac_lpc, EXIT_MRK "LpcDD::~LpcDD");
}

/**
 * @brief Reset hardware to get into clean state
 */
errlHndl_t LpcDD::hwReset( ResetLevels i_resetLevel )
{
    errlHndl_t l_err = NULL;
    uint32_t i_addr = 0;
    uint64_t l_addr = 0;

    TRACFCOMP( g_trac_lpc, ENTER_MRK"LpcDD::hwReset(i_resetLevel=%d)>", i_resetLevel );

    // check iv_resetActive to avoid infinite loops
    // and don't reset if in the middle of FFDC collection
    // and don't bother if we already failed the recovery once
    if ( ( iv_resetActive == false ) &&
         ( iv_ffdcActive == false  ) &&
         ( iv_errorRecoveryFailed == false) )
    {
        iv_resetActive = true;

        do {
            /***************************************/
            /* Handle the different reset levels   */
            /***************************************/
            switch(i_resetLevel)
            {
                case RESET_CLEAR:
                    {// Nothing to do here, so just break
                        break;
                    }

/*   @todo - RTC:179179
                  case RESET_INIT:
                    {
                        // Set OPB LPCM FIR Mask
                        //  hostboot will monitor these FIR bits
                        size_t scom_size = sizeof(uint64_t);
                        uint64_t fir_mask_data = OPB_LPCM_FIR_ERROR_MASK;
                        // Write FIR Register
                        l_err = deviceOp( DeviceFW::WRITE,
                                      iv_proc,
                                      &(fir_mask_data),
                                      scom_size,
                                      DEVICE_SCOM_ADDRESS(
                                         OPB_LPCM_FIR_MASK_WO_OR_REG));
                        if( l_err ) { break; }
                    }
**/

                case RESET_OPB_LPCHC_HARD:
                    {
                        TRACFCOMP(g_trac_lpc, "LpcDD::hwReset> Writing OPB_MASTER_LS_CONTROL_REG to disable then enable First Error Data Capture");

                        //Clear all error indicators in LPCM OPB Master Actual
                        //      Status Reg
                        i_addr = OPBM_STATUS_REG;
                        l_err = checkAddr( LPC::TRANS_ERR, i_addr, &l_addr );
                        if (l_err) { break; }
                        uint32_t * l_status_ptr
                               = reinterpret_cast<uint32_t*>(l_addr);
                        //Clear under mask - aka write 1 clears
                        *l_status_ptr = LPC::OPB_ERROR_MASK;
                        eieio();

                        //Clear related bits in the LPCM OPB Master Accumulated
                        //   Status Reg
                        i_addr = OPBM_ACCUM_STATUS_REG;
                        l_err = checkAddr( LPC::TRANS_ERR, i_addr, &l_addr );
                        if (l_err) { break; }
                        uint32_t * l_accum_status_ptr
                                = reinterpret_cast<uint32_t*>(l_addr);
                        //Clear under mask - aka write 1 clears
                        *l_accum_status_ptr = LPC::OPB_ERROR_MASK;
                        eieio();

                        //Reset LPCHC Logic
                        TRACFCOMP(g_trac_lpc, "LpcDD::hwReset> Writing LPCHC_RESET_REG to reset LPCHC Logic");
                        i_addr = LPCHC_RESET_REG;
                        l_err = checkAddr( LPC::TRANS_ERR, i_addr, &l_addr );
                        if (l_err) { break; }
                        uint32_t * l_reset_ptr
                                = reinterpret_cast<uint32_t*>(l_addr);
                        //The spec states the act of a write is all that matters
                        //The data itself doesn't matter, so using an arbitrary
                        //value
                        *l_reset_ptr = 0x12345678;
                        eieio();

                        //Issue LPC Abort
                        i_addr = LPCHC_LPC_BUS_ABORT_REG;
                        l_err = checkAddr( LPC::TRANS_ERR, i_addr, &l_addr );
                        if (l_err) { break; }
                        uint32_t * l_abort_ptr
                                = reinterpret_cast<uint32_t*>(l_addr);
                        //The spec states the act of a write is all that matters
                        //The data itself doesn't matter, so using an arbitrary
                        //value
                        *l_abort_ptr = 0x12345678;
                        eieio();

/*   @todo - RTC:179179 - Re-enable FEDC
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
**/
                        break;
                    }

/*   @todo - RTC:179179 - Properly categorize errors into SOFT/HARD errors and
                        update this implementation based on results
                case RESET_OPB_LPCHC_SOFT:
                    {
                        break;
                    }
**/

                    // else - unsupported reset level
                default:
                    {
                        TRACFCOMP( g_trac_lpc, ERR_MRK"LpcDD::hwReset> Unsupported Reset Level Passed In: 0x%X", i_resetLevel);

                        /*@
                         * @errortype    ERRL_SEV_UNRECOVERABLE
                         * @moduleid     LPC::MOD_LPCDD_HWRESET
                         * @reasoncode   LPC::RC_UNSUPPORTED_OPERATION
                         * @userdata1    Unsupported Reset Level Parameter
                         * @userdata2    <unused>
                         * @devdesc      LpcDD::hwReset> Unsupported Reset Level
                         *               requested
                         * @custdesc     Unsupported Reset Level requested
                         */
                        l_err = new ERRORLOG::ErrlEntry(
                                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                            LPC::MOD_LPCDD_HWRESET,
                                            LPC::RC_UNSUPPORTED_OPERATION,
                                            i_resetLevel,
                                            0,
                                            true /*SW error*/);

                        l_err->collectTrace(LPC_COMP_NAME);

                        break;
                    }
            }// end switch

            if ( l_err )
            {
                // Indicate that we weren't successful in resetting
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
                            uint64_t *o_addr)
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
            *o_addr =
            getLPCBaseAddr()+ i_addr+ LPC::LPCHC_IO_SPACE- LPC_ADDR_START;
            break;
        case LPC::TRANS_MEM:
            if( i_addr >= 0x10000000 )
            {
                invalid_address = true;
                break;
            }
            *o_addr =
            getLPCBaseAddr()+ i_addr+ LPC::LPCHC_MEM_SPACE- LPC_ADDR_START;
            break;
        case LPC::TRANS_FW:
            if( i_addr >= 0x10000000 )
            {
                invalid_address = true;
                break;
            }
            *o_addr =
            getLPCBaseAddr()+ i_addr + LPC::LPCHC_FW_SPACE- LPC_ADDR_START;
            break;
        case LPC::TRANS_REG:
          if( i_addr >= 0x100 )
            {
                invalid_address = true;
                break;
            }
            *o_addr =
            getLPCBaseAddr()+ i_addr + LPC::LPCHC_INT_REG_SPACE- LPC_ADDR_START;
            break;
        case LPC::TRANS_ERR:
          if( i_addr >= 0x10000 )
            {
                invalid_address = true;
                break;
            }
            *o_addr =
            getLPCBaseAddr()+ i_addr + LPC::LPCHC_ERR_SPACE- LPC_ADDR_START;
            break;
        case LPC::TRANS_ABS:
            //Just use the address as given
            *o_addr = getLPCBaseAddr() + i_addr;
            break;
        default:
            invalid_address = true;
    }

    if( invalid_address )
    {
        TRACFCOMP( g_trac_lpc, "LpcDD::checkAddr() Invalid address : i_type=%d, i_addr=%X", i_type, i_addr );
        /*@
         * @errortype    ERRL_SEV_UNRECOVERABLE
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

// @TODO RTC 248971
// MCTP support requires some MMIO reads/writes from/to LPC FW space to be 4-byte aligned,
// whereas the Hostboot memcpy implementation only supports 8 or 1 byte alignment.  Temporarily
// switch to 4-byte alignment to allow this case to work.  The referenced work item should
// implement an intelligent copy that optimizes the sequences of 1,2,4,8 byte MMIOs to achieve
// the desired transfer, while taking into account alignment requirements.

#if !(CONFIG_SFC_IS_AST2400 || CONFIG_SFC_IS_AST2500)

/**
 *  @brief Copy four bytes at a time to or from LPC FW space memory until
 *      less than four bytes remain, then copy one byte at a time for the
 *      remaining data.
 *
 *  @param[in] i_pDest Pointer to destination buffer (must not be nullptr
 *      or assertion will fire).
 *
 *  @param[in] i_pSrc  Pointer to source buffer (must not be nullptr or
 *      assertion will fire).
 *
 *  @param[in] i_len Number of bytes to copy
 *
 *  @return Pointer to destination buffer
 */
static void* lpc_fw_memcpy(
          void* const i_pDest,
    const void* const i_pSrc,
          size_t      i_len)
{
    assert(i_pDest,"Destination pointer was nullptr");
    assert(i_pSrc,"Source pointer was nullptr");

    uint32_t* pLdest = reinterpret_cast<uint32_t*>(i_pDest);
    const uint32_t* pLsrc = reinterpret_cast<const uint32_t*>(i_pSrc);

    while (i_len >= sizeof(uint32_t))
    {
        *pLdest++ = *pLsrc++;
        i_len -= sizeof(uint32_t);
    }

    uint8_t* pBdest = reinterpret_cast<uint8_t*>(pLdest);
    const uint8_t* pBsrc = reinterpret_cast<const uint8_t*>(pLsrc);

    while (i_len >= sizeof(uint8_t))
    {
        *pBdest++ = *pBsrc++;
        i_len -= sizeof(uint8_t);
    }

    return i_pDest;
}
#endif

/**
 * @brief Read an address from LPC space, assumes lock is already held
 */
errlHndl_t LpcDD::_readLPC(LPC::TransType i_type,
                           uint32_t i_addr,
                           void* o_buffer,
                           size_t& io_buflen)
{
    errlHndl_t l_err = NULL;
    uint64_t l_addr = 0;

    do {
        // Generate the full absolute LPC address
        l_err = checkAddr( i_type, i_addr, &l_addr );
        if( l_err ) { break; }

//TODO CQ:SW328950 to work around Simics AST2400 bug
#if CONFIG_SFC_IS_AST2400 || CONFIG_SFC_IS_AST2500
        if( io_buflen <= sizeof(uint32_t) )
        {
            memcpy( o_buffer, reinterpret_cast<void*>(l_addr), io_buflen );
        }
#else
        // Copy data out to caller's buffer.
        if( io_buflen == sizeof(uint8_t) )
        {
            uint8_t * l_ptr = reinterpret_cast<uint8_t*>(l_addr);
            uint8_t * o_ptr = reinterpret_cast<uint8_t*>(o_buffer);
            *o_ptr = *l_ptr;
        }
        else if( io_buflen == sizeof(uint16_t) )
        {
            uint16_t * l_ptr = reinterpret_cast<uint16_t*>(l_addr);
            uint16_t * o_ptr = reinterpret_cast<uint16_t*>(o_buffer);
            *o_ptr = *l_ptr;
        }
        else if ( io_buflen == sizeof(uint32_t) )
        {
            uint32_t * l_ptr = reinterpret_cast<uint32_t*>(l_addr);
            uint32_t * o_ptr = reinterpret_cast<uint32_t*>(o_buffer);
            *o_ptr = *l_ptr;
        }
        else if ( i_type == LPC::TRANS_FW
                  && (i_addr + io_buflen) <= LPC::FW_WINDOW_SIZE)
        {
            lpc_fw_memcpy( o_buffer, reinterpret_cast<void*>(l_addr), io_buflen );
        }
#endif
        else
        {
            TRACFCOMP( g_trac_lpc, "readLPC> Unsupported buffer size : %d", io_buflen );
            /*@
             * @errortype    ERRL_SEV_UNRECOVERABLE
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

        //Sync the IO op
        eieio();

        // Check Error bits
        l_err = checkForLpcErrors();

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
    uint64_t l_addr = 0;

    do {
        // Generate the full absolute LPC address
        l_err = checkAddr( i_type, i_addr, &l_addr );
        if( l_err ) { break; }

//TODO CQ:SW328950 to work around Simics AST2400 bug
#if CONFIG_SFC_IS_AST2400 || CONFIG_SFC_IS_AST2500
        memcpy(reinterpret_cast<void*>(l_addr), i_buffer, io_buflen);
#else
        if( io_buflen == sizeof(uint8_t) )
        {
            uint8_t * l_ptr = reinterpret_cast<uint8_t*>(l_addr);
            const uint8_t * i_ptr =reinterpret_cast<const uint8_t*>(i_buffer);
            *l_ptr = *i_ptr;
        }
        else if( io_buflen == sizeof(uint16_t) )
        {
            uint16_t * l_ptr = reinterpret_cast<uint16_t*>(l_addr);
            const uint16_t * i_ptr =reinterpret_cast<const uint16_t*>(i_buffer);
            *l_ptr = *i_ptr;
        }
        else if ( io_buflen == sizeof(uint32_t) )
        {
            uint32_t * l_ptr = reinterpret_cast<uint32_t*>(l_addr);
            const uint32_t * i_ptr =reinterpret_cast<const uint32_t*>(i_buffer);
            *l_ptr = *i_ptr;
        }
        else if ( i_type == LPC::TRANS_FW
                                 && (i_addr + io_buflen) < LPC::FW_WINDOW_SIZE)
        {
            lpc_fw_memcpy(reinterpret_cast<void*>(l_addr),i_buffer,io_buflen );
        }
        eieio();
#endif

        // Check Error bits
        l_err = checkForLpcErrors();

    } while(0);

    return l_err;
}

bool LpcDD::opbArbiterRange(const uint64_t i_addr) const
{
    return (   (i_addr >= 0x1000)
            && (i_addr <= 0x1FFF) );
}

bool LpcDD::opbMasterRange(const uint64_t i_addr) const
{
    return (   (i_addr >= 0x0000)
            && (i_addr <= 0x0FFC) );
}

bool LpcDD::lpchcRange(const uint64_t i_addr) const
{
    return (   (i_addr >= 0x2000)
            && (i_addr <= 0x2FFC) );
}

/**
 * @brief Add Error Registers to an existing Error Log
 */
void LpcDD::addFFDC(errlHndl_t & io_errl)
{
    errlHndl_t l_err = nullptr;
    uint32_t i_addr = 0;
    uint64_t l_addr = 0;
    uint32_t lpcAddr_buffer;
    size_t l_buflen = sizeof(uint32_t);

    // check iv_ffdcActive to avoid infinite loops
    do{

        if ( iv_ffdcActive == false )
        {
            iv_ffdcActive = true;

            TRACFCOMP( g_trac_lpc, "LpcDD::addFFDC> adding FFDC to Error Log EID=0x%X, PLID=0x%X",
                       io_errl->eid(), io_errl->plid() );

            i_addr = LPCHC_ERROR_ADDR_REG;
            l_err = checkAddr( LPC::TRANS_ERR, i_addr, &l_addr );
            if (l_err)
            {
                // Additional FFDC is not necessary, just delete error and break
                delete l_err;
                l_err = nullptr;
                break;
            }

            memcpy(&lpcAddr_buffer, reinterpret_cast<void*>(l_addr), l_buflen);
            eieio();

            io_errl->addFFDC(LPC_COMP_ID,
                           &lpcAddr_buffer,
                           l_buflen,
                           0,                             // version
                           ERRORLOG::ERRL_UDT_NOFORMAT,   // parser ignores data
                           false);

            // reset FFDC active flag
            iv_ffdcActive = false;
        }

    }while(0);

    return;
}

/**
 * @brief Compute error severity from OPBM Status Register
 */
void LpcDD::computeOpbmErrSev(OpbmErrReg_t i_opbmErrData,
                              ResetLevels &o_resetLevel)
{
    o_resetLevel = RESET_CLEAR;

    // First check the soft errors
    /*   @todo - RTC:179179 Revisit below Reset Levels **/
    if( i_opbmErrData.rxits )
    {
        o_resetLevel = RESET_OPB_LPCHC_SOFT;
        TRACFCOMP( g_trac_lpc, ERR_MRK"LpcDD::computeOpbmErrSev> Invalid Transfer Size Error: OPBM Status Reg =0x%8X, ResetLevel=%d",
                   i_opbmErrData, o_resetLevel);
    }
    if( i_opbmErrData.rxicmd )
    {
        o_resetLevel = RESET_OPB_LPCHC_SOFT;
        TRACFCOMP( g_trac_lpc, ERR_MRK"LpcDD::computeOpbmErrSev> Invalid Command Error: OPBM Status Reg =0x%8X, ResetLevel=%d",
                   i_opbmErrData, o_resetLevel);
    }
    if( i_opbmErrData.rxiaa )
    {
        o_resetLevel = RESET_OPB_LPCHC_SOFT;
        TRACFCOMP( g_trac_lpc, ERR_MRK"LpcDD::computeOpbmErrSev> Invalid Address Alignment Error: OPBM Status Reg =0x%8X, ResetLevel=%d",
                   i_opbmErrData, o_resetLevel);
    }
    if( i_opbmErrData.rxopbe )
    {
        o_resetLevel = RESET_OPB_LPCHC_SOFT;
        TRACFCOMP( g_trac_lpc, ERR_MRK"LpcDD::computeOpbmErrSev> OPB Error Acknowledged: OPBM Status Reg =0x%8X, ResetLevel=%d",
                   i_opbmErrData, o_resetLevel);
    }
    if( i_opbmErrData.rxicmdb )
    {
        o_resetLevel = RESET_OPB_LPCHC_SOFT;
        TRACFCOMP( g_trac_lpc, ERR_MRK"LpcDD::computeOpbmErrSev> OPB Master Command Buffer Parity Error: OPBM Status Reg =0x%8X, ResetLevel=%d",
                   i_opbmErrData, o_resetLevel);
    }
    if( i_opbmErrData.rxidatab )
    {
        o_resetLevel = RESET_OPB_LPCHC_SOFT;
        TRACFCOMP( g_trac_lpc, ERR_MRK"LpcDD::computeOpbmErrSev> OPM Master Data Buffer Parity Error: OPBM Status Reg =0x%8X, ResetLevel=%d",
                   i_opbmErrData, o_resetLevel);
    }

    // Now look for HARD errors that will override SOFT errors reset Level
    if( i_opbmErrData.rxopbt )
    {
        o_resetLevel = RESET_OPB_LPCHC_HARD;
        TRACFCOMP( g_trac_lpc, ERR_MRK"LpcDD::computeOpbmErrSev> OPM Timeout Error: OPBM Status Reg =0x%8X, ResetLevel=%d",
                   i_opbmErrData, o_resetLevel);
    }
    if( i_opbmErrData.rxiaddr )
    {
        o_resetLevel = RESET_OPB_LPCHC_HARD;
        TRACFCOMP( g_trac_lpc, ERR_MRK"LpcDD::computeOpbmErrSev> Invalid Address Error: OPBM Status Reg =0x%8X, ResetLevel=%d",
                   i_opbmErrData, o_resetLevel);
    }
    if( i_opbmErrData.rxctgtel )
    {
        o_resetLevel = RESET_OPB_LPCHC_HARD;
        TRACFCOMP( g_trac_lpc, ERR_MRK"LpcDD::computeOpbmErrSev> OPB Master Timeout: OPBM Status Reg =0x%8X, ResetLevel=%d",
                   i_opbmErrData, o_resetLevel);
    }
}

/**
 * @brief Compute error severity from LPCHC Status Register
 */
void LpcDD::computeLpchcErrSev(LpchcErrReg_t i_lpchcErrData,
                               ResetLevels &o_resetLevel)
{
    o_resetLevel = RESET_CLEAR;

    // First check the soft errors
    // All of these errors are set from bad LPC end points. Setting all to soft
    /*   @todo - RTC:179179 Revisit below Reset Levels **/
    if( i_lpchcErrData.lreset )
    {
        o_resetLevel = RESET_OPB_LPCHC_SOFT;
        TRACFCOMP( g_trac_lpc, ERR_MRK"LpcDD::computeLpchcErrSev> Lreset Event: LPCHC Status Reg =0x%8X, ResetLevel=%d",
                   i_lpchcErrData, o_resetLevel);
    }
    if( i_lpchcErrData.syncab )
    {
        o_resetLevel = RESET_OPB_LPCHC_SOFT;
        TRACFCOMP( g_trac_lpc, ERR_MRK"LpcDD::computeLpchcErrSev> Sync Abnormal Error: LPCHC Status Reg =0x%8X, ResetLevel=%d",
                   i_lpchcErrData, o_resetLevel);
    }
    if( i_lpchcErrData.syncnr )
    {
        o_resetLevel = RESET_OPB_LPCHC_SOFT;
        TRACFCOMP( g_trac_lpc, ERR_MRK"LpcDD::computeLpchcErrSev> Sync No Response Error: LPCHC Status Reg =0x%8X, ResetLevel=%d",
                  i_lpchcErrData, o_resetLevel);
    }
    if( i_lpchcErrData.syncne )
    {
        o_resetLevel = RESET_OPB_LPCHC_SOFT;
        TRACFCOMP( g_trac_lpc, ERR_MRK"LpcDD::computeLpchcErrSev> Sync Normal Error: LPCHC Status Reg =0x%8X, ResetLevel=%d",
                   i_lpchcErrData, o_resetLevel);
    }
    if( i_lpchcErrData.syncto )
    {
        o_resetLevel = RESET_OPB_LPCHC_SOFT;
        TRACFCOMP( g_trac_lpc, ERR_MRK"LpcDD::computeLpchcErrSev> Sync Timeout Error: LPCHC Status Reg =0x%8X, ResetLevel=%d",
                   i_lpchcErrData, o_resetLevel);
    }
    if( i_lpchcErrData.tctar )
    {
        o_resetLevel = RESET_OPB_LPCHC_SOFT;
        TRACFCOMP( g_trac_lpc, ERR_MRK"LpcDD::computeLpchcErrSev> Target Cycle TAR Error: LPCHC Status Reg =0x%8X, ResetLevel=%d",
                   i_lpchcErrData, o_resetLevel);
    }
    if( i_lpchcErrData.mctar )
    {
        o_resetLevel = RESET_OPB_LPCHC_SOFT;
        TRACFCOMP( g_trac_lpc, ERR_MRK"LpcDD::computeLpchcErrSev> LPC Bus Master Cycle TAR Error: LPCHC Status Reg =0x%8X, ResetLevel=%d",
                   i_lpchcErrData, o_resetLevel);
    }

}

/**
 * @brief Check For Errors in OPB and LPCHC Status Registers
 */
errlHndl_t LpcDD::checkForLpcErrors()
{
    errlHndl_t l_err = NULL;

    uint32_t i_addr = 0;
    uint64_t l_addr = 0;
    uint32_t opbm_buffer;
    uint32_t lpchc_buffer;
    size_t l_buflen = sizeof(uint32_t);
    ResetLevels l_opbmResetLevel = RESET_CLEAR;
    ResetLevels l_lpchcResetLevel = RESET_CLEAR;

    OpbmErrReg_t opbm_err_union;
    opbm_err_union.data32 = 0x0;

    LpchcErrReg_t lpchc_err_union;
    lpchc_err_union.data32 = 0x0;

    do {
        // LPC error registers are not modeled in FSP simics.
        // Skip if we are running simics.
        if (Util::isSimicsRunning())
        { break; }

        // Read OPBM Status Register via MMIO
        i_addr = OPBM_ACCUM_STATUS_REG;
        l_err = checkAddr( LPC::TRANS_ERR, i_addr, &l_addr );
        if (l_err) { break; }

        memcpy( &opbm_buffer, reinterpret_cast<void*>(l_addr), l_buflen );
        eieio();

        // Read LPC Host Controller Status register via MMIO
        i_addr = LPCHC_REG;
        l_err = checkAddr( LPC::TRANS_ERR, i_addr, &l_addr );
        if (l_err) { break; }

        memcpy( &lpchc_buffer, reinterpret_cast<void*>(l_addr), l_buflen );
        eieio();

        // Mask error bits
        opbm_err_union.data32 = (opbm_buffer & LPC::OPB_ERROR_MASK);
        lpchc_err_union.data32 = (lpchc_buffer & LPCHC_ERROR_MASK);

        // First look for errors in the OPBM bit mask
        if (opbm_err_union.data32 != 0)
        {
            TRACFCOMP( g_trac_lpc, ERR_MRK"LpcDD::checkForLpcErrors> Error found in OPB Master Status Register: 0x%8X",opbm_err_union.data32);
            computeOpbmErrSev(opbm_err_union, l_opbmResetLevel);

            // New priority is to force a specific checkstop so that PRD can
            // handle the callout
            LPC::lpcForceCheckstopOnLpcErrors();

            // Shouldn't return back from forcing a checkstop, but if so, just
            // follow the previous error path here

            if(l_opbmResetLevel != RESET_CLEAR)
            {
                /*@
                 * @errortype    ERRL_SEV_UNRECOVERABLE
                 * @moduleid     LPC::MOD_LPCDD_CHECKFORLPCERRORS
                 * @reasoncode   LPC::RC_OPB_ERROR
                 * @userdata1    OPBM Error Status Register
                 * @userdata2    Reset Level
                 * @devdesc      LpcDD::checkLpcErrors> Error(s) found in OPB
                 *               Status Register
                 * @custdesc     Error(s) found in OPB Status Register
                 */
                l_err = new ERRORLOG::ErrlEntry(
                                              ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                              LPC::MOD_LPCDD_CHECKFORLPCERRORS,
                                              LPC::RC_OPB_ERROR,
                                              opbm_buffer,
                                              l_opbmResetLevel);

                // Gather additional ffdc data
                addFFDC(l_err);
                l_err->addHwCallout( iv_proc,
                                     HWAS::SRCI_PRIORITY_NONE,
                                     HWAS::NO_DECONFIG,
                                     HWAS::GARD_NULL );

                /*   @todo - RTC:179179 Use l_opbmResetLevel **/
                hwReset(RESET_OPB_LPCHC_HARD);
            }
        }
        // Check the LPC host controller bit mask, only if there are no errors
        //    from the OPBM bit mask
        if (lpchc_err_union.data32 != 0 && l_err == NULL)
        {
            TRACFCOMP( g_trac_lpc, ERR_MRK"LpcDD::checkForLpcErrors> Error found in LPC Host Controller Status Register: 0x%8X",lpchc_err_union.data32);
            computeLpchcErrSev(lpchc_err_union, l_lpchcResetLevel);

            if(l_lpchcResetLevel != RESET_CLEAR)
            {
                /*@
                 * @errortype    ERRL_SEV_UNRECOVERABLE
                 * @moduleid     LPC::MOD_LPCDD_CHECKFORLPCERRORS
                 * @reasoncode   LPC::RC_LPCHC_ERROR
                 * @userdata1    LPCHC Error Status Register
                 * @userdata2    Reset Level
                 * @devdesc      LpcDD::checkForLpcErrors> Error(s) found in LPCHC
                 *  Status Register
                 * @custdesc     Error(s) found in LPCHC Status Register
                 */
                l_err = new ERRORLOG::ErrlEntry(
                                               ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               LPC::MOD_LPCDD_CHECKFORLPCERRORS,
                                               LPC::RC_LPCHC_ERROR,
                                               lpchc_buffer,
                                               l_lpchcResetLevel);

                l_err->addHwCallout( iv_proc,
                                     HWAS::SRCI_PRIORITY_NONE,
                                     HWAS::NO_DECONFIG,
                                     HWAS::GARD_NULL );

                // Gather addtional ffdc data
                addFFDC(l_err);
                l_err->collectTrace(LPC_COMP_NAME);
                /*   @todo - RTC:179179 Use l_opbmResetLevel **/
                hwReset(RESET_OPB_LPCHC_HARD);
            }
        }

    }while(0);

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

    //First check/clear the LPC bus of errors and commit any errors found
    errlHndl_t l_err_precheck = checkForLpcErrors();
    if (l_err_precheck)
    {
        l_err_precheck->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
    }

    // Now do the operation
    errlHndl_t l_err_op = _readLPC( i_type, i_addr, o_buffer, io_buflen );

    // If this op failed and there was something wrong before we started,
    //  attach the logs together to aid debug
    if( l_err_op && l_err_precheck )
    {
        l_err_precheck->plid(l_err_op->plid());
        //Note-ideally we would up the severity of l_err_precheck here
        // as well so that it would be visible everywhere, but we can't
        // because that breaks the scenario where the caller might want
        // to delete the log they get back (see SIO).  We don't want
        // any visible logs in that case.
    }

    // Always just commit the log for any errors that were present
    if( l_err_precheck )
    {
        errlCommit(l_err_precheck, LPC_COMP_ID);
    }

    mutex_unlock(ivp_mutex);

    return l_err_op;
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

    //First check/clear the LPC bus of errors and commit any errors found
    errlHndl_t l_err_precheck = checkForLpcErrors();
    if (l_err_precheck)
    {
        l_err_precheck->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
    }

    // Now do the operation
    errlHndl_t l_err_op = _writeLPC( i_type, i_addr, i_buffer, io_buflen );

    // If this op failed and there was something wrong before we started,
    //  attach the logs together to aid debug
    if( l_err_op && l_err_precheck )
    {
        l_err_precheck->plid(l_err_op->plid());
        //Note-ideally we would up the severity of l_err_precheck here
        // as well so that it would be visible everywhere, but we can't
        // because that breaks the scenario where the caller might want
        // to delete the log they get back (see SIO).  We don't want
        // any visible logs in that case.
    }

    // Always just commit the log for any errors that were present
    if( l_err_precheck )
    {
        errlCommit(l_err_precheck, LPC_COMP_ID);
    }

    mutex_unlock(ivp_mutex);

    return l_err_op;
}
