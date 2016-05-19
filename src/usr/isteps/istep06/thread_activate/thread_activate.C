/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep06/thread_activate/thread_activate.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2016                        */
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
#include    <p9_thread_control.H>
#include    <arch/pirformat.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

//  fapi support
#include    <fapi2.H>
#include    <fapi2_target.H>
#include    <plat_hwp_invoker.H>
#include    <istep_reasoncodes.H>
#include    <p9_cpu_special_wakeup.H>

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
        default:
            TRACFCOMP( g_fapiImpTd,
                       "getCacheDeconfig: No MVPD Record for core 0x%.8X",
                       i_masterCoreId);
            /*@
             * @errortype
             * @moduleid     ISTEP::MOD_GET_CACHE_DECONFIG
             * @reasoncode   ISTEP::RC_INVALID_RECORD
             * @userdata1    Master Core Number
             * @userdata2    Master processor chip huid
             * @devdesc      getCacheDeconfig> Master core is not mapped
             *               to a LRPx Module VPD Record.
             * @custdesc     A problem occurred during the IPL
             *               of the system.
             */
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                             ISTEP::MOD_GET_CACHE_DECONFIG,
                                             ISTEP::RC_INVALID_RECORD,
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

        if(theSize != 1)
        {
            /*@
             * @errortype
             * @moduleid     ISTEP::MOD_GET_CACHE_DECONFIG
             * @reasoncode   ISTEP::RC_INCORRECT_KEWORD_SIZE
             * @userdata1    Master Core Number
             * @userdata2    CH Keyword Size
             * @devdesc      getCacheDeconfig> LRPx Record, CH keyword
             *               is incorrect size
             * @custdesc     A problem occurred during the IPL
             *               of the system.
             */
            TRACFCOMP( g_fapiImpTd,
                       ERR_MRK, "getCacheDeconfig: CH Keyword Size != 1."
                       " Size is instead: 0x%x for record 0x%x",
                       theSize, theRecord );
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                             ISTEP::MOD_GET_CACHE_DECONFIG,
                                             ISTEP::RC_INCORRECT_KEWORD_SIZE,
                                             i_masterCoreId,
                                             theSize);
            break;
        }

        //2nd call is to get the actual data.
        theData = static_cast<uint8_t*>(malloc( theSize ));
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
        // We may not be able to run with only 4MB
        // in the long run so need to revist this after
        // we no longer have to deal with parital good
        // bringup chips.  TODO: RTC: 60620

        //Not worth taking the system down, just assume
        //we only have half the cache available.
        errlCommit(l_errl,HWPF_COMP_ID);
        cacheDeconfig = true;
    }

    TRACFCOMP( g_fapiImpTd,
               "Exiting getCacheDeconfig, cacheDeconfig=%d",
               cacheDeconfig);
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
                                 TARGETING::TYPE_CORE,
                                 false);

    // find the core/thread we're running on
    task_affinity_pin();
    task_affinity_migrate_to_master(); //just in case...
    uint64_t cpuid = task_getcpuid();
    task_affinity_unpin();

    uint64_t l_masterCoreID = PIR_t::coreFromPir(cpuid);
    uint64_t l_masterThreadID = PIR_t::threadFromPir(cpuid);

    const TARGETING::Target* l_masterCore = NULL;
    for( TARGETING::TargetHandleList::const_iterator
         core_it = l_coreTargetList.begin();
         core_it != l_coreTargetList.end();
         ++core_it )
    {
        TARGETING::ATTR_CHIP_UNIT_type l_coreId =
                (*core_it)->getAttr<TARGETING::ATTR_CHIP_UNIT>();
        if( l_coreId == l_masterCoreID )
        {
            l_masterCore = (*core_it);
            break;
        }
    }

    do
    {
        if( l_masterCore == NULL )
        {
            TRACFCOMP( g_fapiImpTd,
                       "Could not find a target for core %d",
                       l_masterCoreID );
            /*@
             * @errortype
             * @moduleid     ISTEP::MOD_THREAD_ACTIVATE
             * @reasoncode   ISTEP::RC_NO_MASTER_CORE_TARGET
             * @userdata1    Master cpu id
             * @userdata2    Master processor chip huid
             * @devdesc      activate_threads> Could not find a target
             *               for the master core
             * @custdesc     A problem occurred during the IPL
             *               of the system.
             */
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                             ISTEP::MOD_THREAD_ACTIVATE,
                                             ISTEP::RC_NO_MASTER_CORE_TARGET,
                                             cpuid,
                                             TARGETING::get_huid(l_masterProc));
            l_errl->collectTrace("TARG",256);
            l_errl->collectTrace(FAPI_TRACE_NAME,256);
            l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);

            break;
        }

        TRACFCOMP( g_fapiTd,
                   "Master CPU : c%d t%d (HUID=%.8X)",
                   l_masterCoreID, l_masterThreadID,
                   TARGETING::get_huid(l_masterCore) );

        // cast OUR type of target to a FAPI type of target.
        const fapi2::Target<fapi2::TARGET_TYPE_CORE>& l_fapiCore =
              (const_cast<TARGETING::Target*>(l_masterCore));

        //  AVPs might enable a subset of the available threads
        uint64_t max_threads = cpu_thread_count();
        TARGETING::Target* sys = NULL;
        TARGETING::targetService().getTopLevelTarget(sys);
        assert( sys != NULL );
        uint64_t en_threads = sys->getAttr<TARGETING::ATTR_ENABLED_THREADS>();


        // --------------------------------------------------------------------
        //Enable the special wake-up on master core
        FAPI_INF("\tEnable special wake-up on master core");

        FAPI_INVOKE_HWP(l_errl, p9_cpu_special_wakeup,
                        l_fapiCore,
                        p9specialWakeup::SPCWKUP_ENABLE,
                        p9specialWakeup::HOST);

        if(l_errl)
        {
            TRACFCOMP( g_fapiImpTd,
                       "ERROR: 0x%.8X : p9_cpu_special_wakeup set HWP(cpu %d)",
                       l_errl->reasonCode(),
                       l_masterCoreID);

            l_errl->collectTrace(FAPI_TRACE_NAME,256);
            l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);
            break;
        }

        TRACDCOMP( g_fapiTd,
                   "activate_threads max_threads=%d, en_threads=0x%016X",
                   max_threads, en_threads );

        uint8_t thread_bitset = 0;
        for( uint64_t thread = 0; thread < max_threads; thread++ )
        {
            // Skip the thread that we're running on
            if( thread == l_masterThreadID )
            {
                TRACDCOMP( g_fapiTd,
                           "activate_threads skip master thread=%d", thread );

                continue;
            }

            // Skip threads that we shouldn't be starting
            if(!(en_threads & (0x8000000000000000>>thread)))
            {
                TRACDCOMP( g_fapiTd,
                           "activate_threads skipping thread=%d", thread );

                continue;
            }
            else
            {
                TRACFCOMP( g_fapiTd,
                           "activate_threads enabling thread=%d", thread );

                thread_bitset |= fapi2::thread_id2bitset(thread);

            }
        }

        // send a magic instruction for PHYP Simics to work...
        MAGIC_INSTRUCTION(MAGIC_SIMICS_CORESTATESAVE);

        // parameters: i_target   => core target
        //             i_threads  => thread bitset (0b0000..0b1111)
        //             i_command  =>
        //               PTC_CMD_SRESET => initiate sreset thread command
        //               PTC_CMD_START  => initiate start thread command
        //               PTC_CMD_STOP   => initiate stop thread command
        //               PTC_CMD_STEP   => initiate step thread command
        //               PTC_CMD_QUERY  => query and return thread state
        //                                 return data in o_ras_status
        //             i_warncheck => convert pre/post checks errors to
        //                            warnings
        //             o_rasStatusReg => Complete RAS status reg 64-bit buffer
        //             o_state        => N/A - Output state not used for
        //                               PTC_CMD_SRESET command
        //
        fapi2::buffer<uint64_t> l_rasStatus = 0;
        uint64_t l_threadState = 0;
        FAPI_INVOKE_HWP( l_errl, p9_thread_control,
                         l_fapiCore,      //i_target
                         thread_bitset,   //i_threads
                         PTC_CMD_SRESET,  //i_command
                         false,           //i_warncheck
                         l_rasStatus,     //o_rasStatusReg
                         l_threadState);  //o_state

        if ( l_errl != NULL )
        {
            TRACFCOMP( g_fapiImpTd,
                       "ERROR: 0x%.8X :  proc_thread_control HWP"
                       "( cpu %d, thread_bitset 0x%02X, "
                       "l_rasStatus 0x%lx )",
                       l_errl->reasonCode(),
                       l_masterCoreID,
                       thread_bitset,
                       l_rasStatus );

            l_errl->collectTrace(FAPI_TRACE_NAME,256);
            l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);
        }
        else
        {
            TRACFCOMP(g_fapiTd,
                      "SUCCESS: p9_thread_control HWP"
                      "( cpu %d, thread_bitset 0x%02X )",
                      l_masterCoreID,
                      thread_bitset );
        }

        if(l_errl)
        {
            break;
        }

        // Reclaim remainder of L3 cache if available.
        if ((!PNOR::usingL3Cache()) &&
            (!getCacheDeconfig(l_masterCoreID)))
        {
            TRACFCOMP( g_fapiTd,
                       "activate_threads: Extending cache to 8MB" );
            mm_extend(MM_EXTEND_FULL_CACHE);
        }

    } while(0);

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

