/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/thread_activate/thread_activate.C $          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
 *  @file thread_activate.C
 *
 *  Support file to start non-primary threads
 *
 *  HWP_IGNORE_VERSION_CHECK
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
#include    <sys/mm.h>
#include    <proc_thread_control.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

//  fapi support
#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>
#include    <hwpf/plat/fapiPlatReasonCodes.H>
#include    <hwpf/plat/fapiPlatTrace.H>

#include    <pnor/pnorif.H>
#include    <vpd/mvpdenums.H>

namespace   THREAD_ACTIVATE
{

/**
 * @brief This function will query MVPD and figure out if the master
 *        core has a fully configured cache or not..
 *
 * @param[in] i_masterCoreId - Core number of the core we're running on.
 *
 *
 * @return bool - Indicates if half of cache is deconfigured or not.
 *                true - half cache deconfigured, only 4MB available
 *                false -> No Cache deconfigured, 8MB available.
*/
bool getCacheDeconfig(uint64_t i_masterCoreId)
{
    TRACFCOMP( g_fapiImpTd,
               "Entering getCacheDeconfig, i_masterCoreId=0x%.8X",
               i_masterCoreId);

    //CH Keyword in LPRx Record of MVPD contains the Cache Deconfig State
    //the x in LPRx is the core number.

    errlHndl_t  l_errl  =   NULL;
    bool cacheDeconfig = true;
    uint64_t theRecord = 0x0;
    uint64_t theKeyword = MVPD::CH;
    uint8_t * theData = NULL;
    size_t theSize = 0;
    TARGETING::Target* l_procTarget = NULL;

    do {
        // Target: Find the Master processor
        TARGETING::targetService().masterProcChipTargetHandle(l_procTarget);
        assert(l_procTarget != NULL);

        //Convert core number to LPRx Record ID.
        //TODO: use a common utility function for conversion. RTC: 60552
        switch (i_masterCoreId)
        {
        case 0x0:
            theRecord = MVPD::LRP0;
            break;
        case 0x1:
            theRecord = MVPD::LRP1;
            break;
        case 0x2:
            theRecord = MVPD::LRP2;
            break;
        case 0x3:
            theRecord = MVPD::LRP3;
            break;
        case 0x4:
            theRecord = MVPD::LRP4;
            break;
        case 0x5:
            theRecord = MVPD::LRP5;
            break;
        case 0x6:
            theRecord = MVPD::LRP6;
            break;
        case 0x7:
            theRecord = MVPD::LRP7;
            break;
        case 0x8:
            theRecord = MVPD::LRP8;
            break;
        case 0x9:
            theRecord = MVPD::LRP9;
            break;
        case 0xA:
            theRecord = MVPD::LRPA;
            break;
        case 0xB:
            theRecord = MVPD::LRPB;
            break;
        case 0xC:
            theRecord = MVPD::LRPC;
            break;
        case 0xD:
            theRecord = MVPD::LRPE;
            break;
        case 0xE:
            theRecord = MVPD::LRPE;
            break;
        default:
            TRACFCOMP( g_fapiImpTd,
                       "getCacheDeconfig: No MVPD Record for core 0x%.8X",
                       i_masterCoreId);
            /*@
             * @errortype
             * @moduleid     fapi::MOD_GET_CACHE_DECONFIG
             * @reasoncode   fapi::RC_INVALID_RECORD
             * @userdata1    Master Core Number
             * @userdata2    Master processor chip huid
             * @devdesc      getCacheDeconfig> Master core is not mapped
             *               to a LRPx Module VPD Record.
             */
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                             fapi::MOD_GET_CACHE_DECONFIG,
                                             fapi::RC_INVALID_RECORD,
                                             i_masterCoreId,
                                             TARGETING::get_huid(l_procTarget));
            break;
        }

        //First call is just to get the Record size.
        l_errl = deviceRead(l_procTarget,
                          NULL,
                          theSize,
                          DEVICE_MVPD_ADDRESS( theRecord,
                                               theKeyword ) );
        if( l_errl ) { break; }

        if(theSize != 1)
        {
            /*@
             * @errortype
             * @moduleid     fapi::MOD_GET_CACHE_DECONFIG
             * @reasoncode   fapi::RC_INCORRECT_KEWORD_SIZE
             * @userdata1    Master Core Number
             * @userdata2    CH Keyword Size
             * @devdesc      getCacheDeconfig> LRPx Record, CH keyword
             *               is incorrect size
             */
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                             fapi::MOD_GET_CACHE_DECONFIG,
                                             fapi::RC_INCORRECT_KEWORD_SIZE,
                                             i_masterCoreId,
                                             theSize);
            break;
        }

        theData = static_cast<uint8_t*>(malloc( theSize ));

        //2nd call is to get the actual data.
        l_errl = deviceRead(l_procTarget,
                          theData,
                          theSize,
                          DEVICE_MVPD_ADDRESS( theRecord,
                                               theKeyword ) );
        if( l_errl ) { break; }

        
        if(0 == theData[0])
        {
            cacheDeconfig = false;
        }

    } while(0);

    if(NULL != theData)
    {
        free(theData);
    }

    if(NULL != l_errl)
    {
        //TODO: We may not be able to run with only 4MB
        // in the long run so need to revist this after
        // we no longer have to deal with parital good
        // bringup chips.  RTC: 60620

        //Not worth taking the system down, just assume
        //we only have half the cache available.
        errlCommit(l_errl,HWPF_COMP_ID);
        cacheDeconfig = true;
    }

    return cacheDeconfig;
}


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

        // parameters: i_target   => core target
        //             i_thread   => thread (0..7)
        //             i_command  =>
        //               PTC_CMD_SRESET => initiate sreset thread command
        //               PTC_CMD_START  => initiate start thread command
        //               PTC_CMD_STOP   => initiate stop thread command
        //               PTC_CMD_STEP   => initiate step thread command
        //               PTC_CMD_QUERY  => query and return thread state
        //                                 return data in o_ras_status
        //             i_warncheck => convert pre/post checks errors to warnings
        //             o_ras_status  => output: complete RAS status register
        //             o_state       => output: thread state info
        //                               see proc_thread_control.H
        //                               for bit enumerations:
        //                               THREAD_STATE_*
        ecmdDataBufferBase l_ras_status;
        uint64_t l_thread_state;
        FAPI_INVOKE_HWP( l_errl, proc_thread_control,
                         l_fapiCore,      //i_target
                         thread,          //i_thread
                         PTC_CMD_SRESET,  //i_command
                         false,           //i_warncheck
                         l_ras_status,    //o_ras_status
                         l_thread_state); //o_state

        if ( l_errl != NULL )
        {
            TRACFCOMP( g_fapiImpTd,
                       "ERROR: 0x%.8X :  proc_thread_control HWP( cpu %d, thread %d, "
                       "ras status 0x%.16X, thread state 0x%.16X )",
                       l_errl->reasonCode(),
                       l_masterCoreID,
                       thread,
                       l_ras_status.getDoubleWord(0),
                       l_thread_state );
            l_errl->collectTrace(FAPI_TRACE_NAME,256);
            l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);

            // if 1 thread fails it is unlikely that other threads will work
            //   so we'll just jump out now
            break;
        }
        else
        {
            TRACFCOMP( g_fapiTd,
                       "SUCCESS: proc_thread_control HWP( cpu %d, thread %d, "
                       "ras status 0x%.16X,thread state 0x%.16X )",
                       l_masterCoreID,
                       thread,
                       l_ras_status.getDoubleWord(0),
                       l_thread_state );
        }

        TRACFCOMP( g_fapiTd,
                   "SUCCESS: Thread c%d t%d started",
                   l_masterCoreID,
                   thread );

    }

    // Reclaim remainder of L3 cache if available.
    if ((!PNOR::usingL3Cache()) &&
        (!getCacheDeconfig(l_masterCoreID)))
    {
        TRACFCOMP( g_fapiTd,
                   "activate_threads: Extending cache to 8MB" );
        mm_extend(MM_EXTEND_FULL_CACHE);
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

