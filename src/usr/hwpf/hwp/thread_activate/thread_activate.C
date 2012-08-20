/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/thread_activate/thread_activate.C $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
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
 *  @file thread_activate.C
 *
 *  Support file to start non-primary threads
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <devicefw/userif.H>
#include    <sys/misc.h>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

//  fapi support
#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>
#include    <hwpf/plat/fapiPlatReasonCodes.H>
#include    <hwpf/plat/fapiPlatTrace.H>


//@fixme - Patrick is adding this constant under 37009
#define MAGIC_SIMICS_CORESTATESAVE  10

namespace   THREAD_ACTIVATE
{


void activate_threads( errlHndl_t& io_rtaskRetErrl )
{
    errlHndl_t  l_errl  =   NULL;

    TRACFCOMP( g_fapiTd,
               "activate_threads entry" );

    // get the master processor target
    TARGETING::Target* l_masterProc = NULL;
    TARGETING::targetService().masterProcChipTargetHandle( l_masterProc );
    if( l_masterProc == NULL )
    {
        TRACFCOMP( g_fapiImpTd,
                   "Could not find master proc!!!" );
        assert(false);
    }

    // get the list of core targets for this proc chip
    TARGETING::TargetHandleList l_coreTargetList;
    TARGETING::getChildChiplets( l_coreTargetList,
                                 l_masterProc,
                                 TARGETING::TYPE_EX,
                                 false);

    // find the core/thread we're running on
    task_affinity_pin();
    task_affinity_migrate_to_master(); //just in case...
    uint64_t cpuid = task_getcpuid();
    task_affinity_unpin();

    //NNNCCCPPPPTTT
    uint64_t l_masterCoreID = (cpuid & 0x0078)>>3;
    uint64_t l_masterThreadID = (cpuid & 0x0007);

    TARGETING::Target* l_masterCore = NULL;
    for( TARGETING::TargetHandleList::iterator core_it
             = l_coreTargetList.begin();
         core_it != l_coreTargetList.end();
         ++core_it )
    {
        uint8_t l_coreId = (*core_it)->getAttr<TARGETING::ATTR_CHIP_UNIT>();
        if( l_coreId == l_masterCoreID )
        {
            l_masterCore = (*core_it);
            break;
        }
    }
    if( l_masterCore == NULL )
    {
        TRACFCOMP( g_fapiImpTd,
                   "Could not find a target for core %d",
                   l_masterCoreID );
        /*@
         * @errortype
         * @moduleid     fapi::MOD_THREAD_ACTIVATE
         * @reasoncode   fapi::RC_NO_MASTER_CORE_TARGET
         * @userdata1    Master cpu id (NNNCCCPPPPTTT)
         * @userdata2    Master processor chip huid
         * @devdesc      activate_threads> Could not find a target
         *               for the master core
         */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         fapi::MOD_THREAD_ACTIVATE,
                                         fapi::RC_NO_MASTER_CORE_TARGET,
                                         cpuid,
                                         TARGETING::get_huid(l_masterProc));
        l_errl->collectTrace("TARG",256);
        l_errl->collectTrace(FAPI_TRACE_NAME,256);
        l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);
        io_rtaskRetErrl = l_errl;
        return;
    }

    TRACFCOMP( g_fapiTd,
               "Master CPU : c%d t%d (HUID=%.8X)",
               l_masterCoreID, l_masterThreadID, TARGETING::get_huid(l_masterCore) );

    //  dump physical path to core target
    TARGETING::EntityPath l_path;
    l_path = l_masterCore->getAttr<TARGETING::ATTR_PHYS_PATH>();
    l_path.dump();

    // cast OUR type of target to a FAPI type of target.
    const fapi::Target l_fapiCore(
               fapi::TARGET_TYPE_EX_CHIPLET,
               reinterpret_cast<void *>
               (const_cast<TARGETING::Target*>(l_masterCore))
               );

    // loop around threads 0-6, SBE starts thread 7
    uint64_t max_threads = cpu_thread_count();
    for( uint64_t thread = 0; thread < max_threads; thread++ )
    {
        // Skip the thread that we're running on
        if( thread == l_masterThreadID )
        {
            continue;
        }

        // send a magic instruction for PHYP Simics to work...
        MAGIC_INSTRUCTION(MAGIC_SIMICS_CORESTATESAVE);

        //@todo - call the real proc_thread_control HWP  (RTC:42816)
#if 0
        // parameters: i_target   => core target
        //             i_thread   => thread (0..7)
        //             i_sreset   => initiate sreset thread command
        //             i_start    => initiate start thread command
        //             i_stop     => initiate stop thread command
        //             i_step     => initiate step thread command
        //             i_activate => initiate activate thread command
        //             i_query    => query and return thread state
        //                           return data in o_thread_state
        //             o_thread_state   => output: thread state
        uint8_t l_threadState = false;
        FAPI_INVOKE_HWP( l_errl, proc_thread_control,
                         l_fapiCore, //i_target
                         thread, //i_thread
                         true,   //i_sreset
                         false,  //i_start
                         false,  //i_stop
                         false,  //i_step
                         false,  //i_activate
                         false,  //i_query
                         l_threadState ); //o_thread_state
        if ( l_errl )
        {
            TRACFCOMP( g_fapiImpTd,
                       "ERROR: 0x%.8X :  proc_thread_control HWP( cpu %d, thread %d )",
                       l_errl->reasonCode(),
                       l_masterCoreID,
                       thread );
            // if 1 thread fails it is unlikely that other threads will work
            //   so we'll just jump out now
            break;
        }
        else
        {
            TRACFCOMP( g_fapiTd,
                       "SUCCESS: 0x%.8X :  proc_thread_control HWP( cpu %d, thread %d )",
                       l_errl->reasonCode(),
                       l_masterCoreID,
                       thread );
        }
#else
        //@todo - Temp version, just do the scoms manually (RTC:42816)
        size_t scom_size = sizeof(uint64_t);
        uint32_t directControlAddr = 0x10013000 + (thread << 4);
        uint32_t rasStatAddr = 0x10013002 + (thread << 4);

        // Check the initial state
        uint64_t statreg = 0;
        l_errl = deviceRead( l_masterCore,
                             &statreg,
                             scom_size,
                             DEVICE_SCOM_ADDRESS(rasStatAddr) );
        if( l_errl ) { break; }

        // Make sure the thread is in maintenance mode
        if( !(statreg & 0x0000040000000000) ) //21:PTC_RAS_STAT_MAINT
        {
            TRACFCOMP( g_fapiImpTd,
                       "ERROR: Thread c%d t%d is in the wrong state : Status=%.16X",
                       l_masterCoreID,
                       thread,
                       statreg );
            /*@
             * @errortype
             * @moduleid     fapi::MOD_THREAD_ACTIVATE
             * @reasoncode   fapi::RC_THREAD_IN_WRONG_STATE
             * @userdata1    Thread RAS Status Scom Addr
             * @userdata2    Thread RAS Status Data
             * @devdesc      activate_threads> Thread start attempted on
             *               thread that is not in maintenance mode
             */
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                             fapi::MOD_THREAD_ACTIVATE,
                                             fapi::RC_THREAD_IN_WRONG_STATE,
                                             rasStatAddr,
                                             statreg);
            l_errl->collectTrace(FAPI_TRACE_NAME,256);
            l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);
            break;

        }

        // Start the thread
        uint64_t ctlreg = 0x0000000000000008; //60:PTC_DIR_CTL_SP_SRESET
        l_errl = deviceWrite( l_masterCore,
                              &ctlreg,
                              scom_size,
                              DEVICE_SCOM_ADDRESS(directControlAddr) );
        if( l_errl ) { break; }

        // Make sure we really started
        l_errl = deviceRead( l_masterCore,
                             &statreg,
                             scom_size,
                             DEVICE_SCOM_ADDRESS(rasStatAddr) );
        if( l_errl ) { break; }

        if( !(statreg & 0x0008000000000000) ) //12:PTC_RAS_STAT_INST_COMP
        {
            TRACFCOMP( g_fapiImpTd,
                       "ERROR: Thread c%d t%d did not start : Status=%.16X",
                       l_masterCoreID,
                       thread,
                       statreg );
            /*@
             * @errortype
             * @moduleid     fapi::MOD_THREAD_ACTIVATE
             * @reasoncode   fapi::RC_THREAD_DID_NOT_START
             * @userdata1    Thread RAS Status Scom Addr
             * @userdata2    Thread RAS Status Data
             * @devdesc      activate_threads> Thread did not start
             */
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                             fapi::MOD_THREAD_ACTIVATE,
                                             fapi::RC_THREAD_DID_NOT_START,
                                             rasStatAddr,
                                             statreg);
            l_errl->collectTrace(FAPI_TRACE_NAME,256);
            l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);
            break;

        }
#endif

        TRACFCOMP( g_fapiTd,
                   "SUCCESS: Thread c%d t%d started",
                   l_masterCoreID,
                   thread );

    }

    TRACFCOMP( g_fapiTd,
               "activate_threads exit" );

    io_rtaskRetErrl = l_errl;
    return;
}

};   // end namespace

/**
 * @brief   set up _start() task entry procedure for PNOR daemon
 */
TASK_ENTRY_MACRO( THREAD_ACTIVATE::activate_threads );

