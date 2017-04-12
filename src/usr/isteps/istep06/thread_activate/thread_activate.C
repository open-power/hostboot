/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep06/thread_activate/thread_activate.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2017                        */
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
#include    <sys/mmio.h>
#include    <p9_thread_control.H>
#include    <arch/pirformat.H>
#include    <arch/pvrformat.H>

//  targeting support
#include    <targeting/common/target.H>
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/common/util.H>

//  fapi support
#include    <fapi2.H>
#include    <fapi2_target.H>
#include    <fapi2_hw_access.H>
#include    <plat_hwp_invoker.H>
#include    <istep_reasoncodes.H>
#include    <p9_cpu_special_wakeup.H>

#include    <pnor/pnorif.H>
#include    <vpd/mvpdenums.H>
#include    <vfs/vfs.H>

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
    //the x in LPRx is the EQ number.
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
        case 0x00:
        case 0x01:
        case 0x02:
        case 0x03:
            theRecord = MVPD::LRP0;
            break;
        case 0x04:
        case 0x05:
        case 0x06:
        case 0x07:
            theRecord = MVPD::LRP1;
            break;
        case 0x08:
        case 0x09:
        case 0x0A:
        case 0x0B:
            theRecord = MVPD::LRP2;
            break;
        case 0x0C:
        case 0x0D:
        case 0x0E:
        case 0x0F:
            theRecord = MVPD::LRP3;
            break;
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x13:
            theRecord = MVPD::LRP4;
            break;
        case 0x14:
        case 0x15:
        case 0x16:
        case 0x17:
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

        if (l_errl) { break; }

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
        //Not worth taking the system down, just assume
        //we only have half the cache available.
        errlCommit(l_errl,ISTEP_COMP_ID);
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
    bool l_wakeup_lib_loaded = false;

    TRACFCOMP( g_fapiTd,
               "activate_threads entry" );

    do
    {
        // get the sys target
        TARGETING::Target* sys = NULL;
        TARGETING::targetService().getTopLevelTarget(sys);
        assert( sys != NULL );

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

        // set the fused core mode attribute
        bool l_smt8 = false;
        PVR_t l_pvr( mmio_pvr_read() & 0xFFFFFFFF );
        if( l_pvr.isNimbusDD1() )
        {
            sys->setAttr<TARGETING::ATTR_FUSED_CORE_MODE_HB>
                    (TARGETING::FUSED_CORE_MODE_HB_SMT4_DEFAULT);
        }
        else
        {
            if( l_pvr.smt == PVR_t::SMT4_MODE )
            {
                sys->setAttr<TARGETING::ATTR_FUSED_CORE_MODE_HB>
                        (TARGETING::FUSED_CORE_MODE_HB_SMT4_ONLY);
            }
            else // SMT8_MODE
            {
                sys->setAttr<TARGETING::ATTR_FUSED_CORE_MODE_HB>
                        (TARGETING::FUSED_CORE_MODE_HB_SMT8_ONLY);
                l_smt8 = true;
            }
        }

        // -----------------------------------
        // Activate threads on the master core
        // -----------------------------------

        // find the core/thread we're running on
        task_affinity_pin();
        task_affinity_migrate_to_master(); //just in case...
        uint64_t cpuid = task_getcpuid();
        task_affinity_unpin();

        uint64_t l_masterCoreID = PIR_t::coreFromPir(cpuid);
        uint64_t l_masterThreadID = PIR_t::threadFromPir(cpuid);

        // find the master core
        const TARGETING::Target* l_masterCore = NULL;
        for( const auto & l_core:l_coreTargetList)
        {
            TARGETING::ATTR_CHIP_UNIT_type l_coreId =
                    (l_core)->getAttr<TARGETING::ATTR_CHIP_UNIT>();
            if( l_coreId == l_masterCoreID )
            {
                l_masterCore = (l_core);
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
        const fapi2::Target<fapi2::TARGET_TYPE_CORE>& l_fapiCore0 =
              (const_cast<TARGETING::Target*>(l_masterCore));

        // --------------------------------------------------------------------
        //Enable the special wake-up on master core
        FAPI_INF("Enable special wake-up on master core");

        //Need to explicitly load the library that has the wakeup HWP in it
        if( !VFS::module_is_loaded( "libp9_cpuWkup.so" ) )
        {
            l_errl = VFS::module_load( "libp9_cpuWkup.so" );
            if ( l_errl )
            {
                //  load module returned with errl set
                TRACFCOMP( g_fapiTd,ERR_MRK"activate_threads: Could not load libp9_cpuWkup module" );
                // break from do loop if error occured
                break;
            }
            l_wakeup_lib_loaded = true;
        }

        FAPI_INVOKE_HWP(l_errl, p9_cpu_special_wakeup_core,
                        l_fapiCore0,
                        p9specialWakeup::SPCWKUP_ENABLE,
                        p9specialWakeup::HOST);
        if(l_errl)
        {
            TRACFCOMP( g_fapiImpTd,
                "ERROR: 0x%.8X : p9_cpu_special_wakeup_core set HWP(cpu %d)",
                l_errl->reasonCode(),
                l_masterCoreID);
            break;
        }

        //  AVPs might enable a subset of the available threads
        uint64_t max_threads = cpu_thread_count();
        uint64_t en_threads, en_threads_master;
        en_threads = en_threads_master =
                    sys->getAttr<TARGETING::ATTR_ENABLED_THREADS>();

        // Core0_thread:  0 1 2 3  Core1_thread: 0 1 2 3
        //   NORMAL(SMT4) - E E E                - - - -
        //   FUSED (SMT8) - E - -                E E - -
        // * E=enable, Core0_t0=master already enabled
        const uint64_t SMT8_ENABLE_THREADS_MASK = 0xC000000000000000;
        const uint64_t SMT8_FUSE0_THREADS_MASK  = 0xA000000000000000;
        const uint64_t SMT8_FUSE1_THREADS_MASK  = 0x5000000000000000;
        if( l_smt8 )
        {
            // First capture if threads 0,2 are enabled.  Then eliminate
            // odd threads and compress to bits 0,1
            uint64_t threads = en_threads & SMT8_FUSE0_THREADS_MASK;
            en_threads_master = threads & SMT8_ENABLE_THREADS_MASK;  //T0
            en_threads_master |= (threads << 1) & SMT8_ENABLE_THREADS_MASK;//T2
        }

        TRACFCOMP( g_fapiTd,
                   "activate_threads max_threads=%d, en_threads_master=0x%016X",
                   max_threads, en_threads_master );

        // Set the start-threads bitset (4 bits)
        // Mask off the master thread that is already running
        const uint32_t ENABLE_THREADS_SHIFT = 60;
        uint8_t thread_bitset = fapi2::thread_id2bitset(l_masterThreadID);
        thread_bitset = ~(thread_bitset) &
                            (en_threads_master >> ENABLE_THREADS_SHIFT);

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
                         l_fapiCore0,     //i_target
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

        // -----------------------------------------
        // Activate threads on the master-fused core
        // -----------------------------------------

        if( l_smt8 )
        {
            uint64_t l_fusedCoreID = l_masterCoreID + 1;

            // find the master-fused core
            const TARGETING::Target* l_fusedCore = NULL;
            for( const auto & l_core:l_coreTargetList)
            {
                TARGETING::ATTR_CHIP_UNIT_type l_coreId =
                        (l_core)->getAttr<TARGETING::ATTR_CHIP_UNIT>();
                if( l_coreId == l_fusedCoreID )
                {
                    l_fusedCore = (l_core);
                    break;
                }
            }

            if( l_fusedCore == NULL )
            {
                TRACFCOMP( g_fapiImpTd,
                        "Could not find a target for core %d",
                        l_fusedCoreID );
                /*@
                * @errortype
                * @moduleid     ISTEP::MOD_THREAD_ACTIVATE
                * @reasoncode   ISTEP::RC_NO_FUSED_CORE_TARGET
                * @userdata1    Master-fused core id
                * @userdata2    Master-fused processor chip huid
                * @devdesc      activate_threads> Could not find a target
                *               for the master-fused core
                * @custdesc     A problem occurred during the IPL
                *               of the system.
                */
                l_errl = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    ISTEP::MOD_THREAD_ACTIVATE,
                                    ISTEP::RC_NO_FUSED_CORE_TARGET,
                                    l_fusedCoreID,
                                    TARGETING::get_huid(l_masterProc));
                l_errl->collectTrace("TARG",256);
                l_errl->collectTrace(FAPI_TRACE_NAME,256);
                l_errl->collectTrace(FAPI_IMP_TRACE_NAME,256);

                break;
            }

            TRACFCOMP( g_fapiTd,
                       "Master-Fused CPU : c%d (HUID=%.8X)",
                       l_fusedCoreID, TARGETING::get_huid(l_fusedCore) );

            // cast OUR type of target to a FAPI type of target.
            const fapi2::Target<fapi2::TARGET_TYPE_CORE>& l_fapiCore1 =
                (const_cast<TARGETING::Target*>(l_fusedCore));

            // -------------------------------------------------------------
            //Enable the special wake-up on master-fused core
            FAPI_INF("Enable special wake-up on master-fused core");

            FAPI_INVOKE_HWP(l_errl, p9_cpu_special_wakeup_core,
                            l_fapiCore1,
                            p9specialWakeup::SPCWKUP_ENABLE,
                            p9specialWakeup::HOST);
            if(l_errl)
            {
                TRACFCOMP( g_fapiImpTd,
                    "ERROR: 0x%.8X : "
                    "p9_cpu_special_wakeup_core set HWP(cpu %d)",
                    l_errl->reasonCode(),
                    l_masterCoreID);
                break;
            }

            // First capture if threads 1,3 are enabled.  Then eliminate
            // even threads and compress to bits 0,1
            uint64_t en_threads_c1;
            uint64_t threads = en_threads & SMT8_FUSE1_THREADS_MASK;
            en_threads_c1 = (threads << 1) & SMT8_ENABLE_THREADS_MASK; //T1
            en_threads_c1 |= (threads << 2) & SMT8_ENABLE_THREADS_MASK;//T3


            TRACFCOMP( g_fapiTd,
                    "activate_threads max_threads=%d, en_threads_c1=0x%016X",
                    max_threads, en_threads_c1 );

            // Set the start-threads bitset (4 bits)
            thread_bitset = en_threads_c1 >> ENABLE_THREADS_SHIFT;

            // see HWP call above for parameter definitions
            l_rasStatus = 0;
            l_threadState = 0;
            FAPI_INVOKE_HWP( l_errl, p9_thread_control,
                            l_fapiCore1,     //i_target
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

        }  // end if( l_smt8 )


        //Check if we are in MPIPL
        uint8_t is_mpipl = 0;
        sys->tryGetAttr<TARGETING::ATTR_IS_MPIPL_HB>(is_mpipl);

        if(is_mpipl)
        {
            TRACFCOMP( g_fapiTd,
                    "activate_threads: We are in MPIPL, extending cache to be real memory" );
            mm_extend(MM_EXTEND_REAL_MEMORY);
        }
        // Reclaim remainder of L3 cache if available.
        else if ((!PNOR::usingL3Cache()) &&
            (!getCacheDeconfig(l_masterCoreID)))
        {
            // Get EX
            TARGETING::Target* l_ex =
                (TARGETING::Target*)getExChiplet(l_masterCore);
            assert(l_ex != NULL);

            // Check SCOM 0x1001181B for reduced cache mode
            uint64_t l_reducedCacheMode = 0;
            size_t l_size = sizeof(l_reducedCacheMode);
            l_errl = deviceRead(l_ex,
                                reinterpret_cast<void*>(&l_reducedCacheMode),
                                l_size,
                                DEVICE_SCOM_ADDRESS(
                                    EX_L3_EDRAM_BANK_FAIL_SCOM_RD));

            if(l_errl)
            {
                TRACFCOMP( g_fapiTd,
                           ERR_MRK"activate_threads: Could not get "
                           "SCOM 0x%.8X, reason code 0x%.8X, EX HUID=%.8X",
                           EX_L3_EDRAM_BANK_FAIL_SCOM_RD,
                           l_errl->reasonCode(),
                           TARGETING::get_huid(l_ex) );
                break;
            }


            if(l_reducedCacheMode)
            {
                TRACFCOMP( g_fapiTd,
                           "activate_threads: Extending cache to 8MB" );
                mm_extend(MM_EXTEND_REDUCED_CACHE);
            }
            else
            {
                TRACFCOMP( g_fapiTd,
                           "activate_threads: Extending cache to 10MB" );
                mm_extend(MM_EXTEND_FULL_CACHE);
            }

        }

    } while(0);

    //make sure we always unload the module if we loaded it
    if( l_wakeup_lib_loaded )
    {
        errlHndl_t l_tmpErrl =
          VFS::module_unload( "libp9_cpuWkup.so" );
        if ( l_tmpErrl )
        {
            TRACFCOMP( g_fapiTd,ERR_MRK"thread_activate: Error unloading libp9_cpuWkup module" );
            if(l_errl)
            {
                errlCommit( l_tmpErrl, ISTEP_COMP_ID );
            }
            else
            {
                l_errl = l_tmpErrl;
            }
        }
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

