/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_initialization/dram_initialization.C $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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
 *  @file dram_initialization.C
 *
 *  Support file for IStep: dram_initialization
 *   Dram Initialization
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>
#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>
#include    <errl/errludtarget.H>
#include    <diag/mdia/mdia.H>
#include    <diag/attn/attn.H>
#include    <initservice/isteps_trace.H>
#include    <hwpisteperror.H>
#include    <errl/errludtarget.H>
#include    <intr/interrupt.H>    // for PIR_t structure

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/util.H>
#include    <targeting/common/utilFilter.H>

//  fapi support
#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>
#include    <hwpf/hwpf_reasoncodes.H>

#include    "dram_initialization.H"
#include    <pbusLinkSvc.H>

//  Uncomment these files as they become available:
// #include    "host_startPRD_dram/host_startPRD_dram.H"
#include    "host_mpipl_service/proc_mpipl_ex_cleanup.H"
#include    "host_mpipl_service/proc_mpipl_chip_cleanup.H"
#include    "mss_extent_setup/mss_extent_setup.H"
// #include    "mss_memdiag/mss_memdiag.H"
// #include    "mss_scrub/mss_scrub.H"
#include    "mss_thermal_init/mss_thermal_init.H"
#include    "proc_setup_bars/mss_setup_bars.H"
#include    "proc_setup_bars/proc_setup_bars.H"
#include    "proc_pcie_config/proc_pcie_config.H"
#include    "proc_exit_cache_contained/proc_exit_cache_contained.H"
#include    "mss_power_cleanup/mss_power_cleanup.H"
#include    "proc_throttle_sync/proc_throttle_sync.H"
//remove these once memory setup workaround is removed
#include <devicefw/driverif.H>
#include <vpd/spdenums.H>
#include <sys/time.h>
#include <sys/mm.h>
#include <dump/dumpif.H>
#include <vfs/vfs.H>

#ifdef CONFIG_IPLTIME_CHECKSTOP_ANALYSIS
    #include    <occ/occ_common.H>
#endif

namespace   DRAM_INITIALIZATION
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   EDI_EI_INITIALIZATION;
using   namespace   fapi;
using   namespace   ERRORLOG;

//
//  Wrapper function to call host_startprd_dram
//
void*    call_host_startprd_dram( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_startPRD_dram entry" );

#if 0
    // @@@@@    CUSTOM BLOCK:   @@@@@
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)

    //  write HUID of target
    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
            "target HUID %.8X", TARGETING::get_huid(l_@targetN_target));

    // cast OUR type of target to a FAPI type of target.
    const fapi::Target l_fapi_@targetN_target( TARGET_TYPE_MEMBUF_CHIP,
                        (const_cast<TARGETING::Target*>(l_@targetN_target)) );

    //  call the HWP with each fapi::Target
    FAPI_INVOKE_HWP( l_errl, host_startPRD_dram, _args_...);
    if ( l_errl )
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "ERROR : .........." );
        errlCommit( l_errl, HWPF_COMP_ID );
    }
    else
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "SUCCESS : .........." );
    }
    // @@@@@    END CUSTOM BLOCK:   @@@@@
#endif

#ifdef CONFIG_IPLTIME_CHECKSTOP_ANALYSIS
    // update firdata inputs for OCC
    TARGETING::Target* masterproc = NULL;
    TARGETING::targetService().masterProcChipTargetHandle(masterproc);
    l_errl = HBOCC::loadHostDataToSRAM(masterproc,
                                        PRDF::ALL_PROC_MEM_MASTER_CORE);
    if (l_errl)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "Error returned from call to HBOCC::loadHostDataToSRAM");
    }
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_startPRD_dram exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_errl;
}

//
//  Wrapper function to call mss_extent_setup
//
void*    call_mss_extent_setup( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    IStepError  l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_mss_extent_setup entry" );

    //  call the HWP
    FAPI_INVOKE_HWP( l_errl, mss_extent_setup );

    if ( l_errl )
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR : failed executing mss_extent_setup returning error" );

        // Create IStep error log and cross reference to error that occurred
        l_stepError.addErrorDetails( l_errl );

        // Commit Error
        errlCommit( l_errl, HWPF_COMP_ID );
    }
    else
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS : mss_extent_setup completed ok" );
    }


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_mss_extent_setup exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}


//
//  Wrapper function to call mss_memdiag
//
void*   call_mss_memdiag( void    *io_pArgs )
{
    using namespace MDIA;

    errlHndl_t  l_errl  =   NULL;

    IStepError  l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_mss_memdiag entry" );

    TargetHandleList l_mbaList;
    getAllChiplets(l_mbaList, TYPE_MBA);

    do {

        l_errl = ATTN::startService();

        if(l_errl)
        {
            break;
        }

        l_errl = runStep(l_mbaList);
        if(NULL != l_errl)
        {
            TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,"MDIA subStep failed");
            break;
        }

        l_errl = ATTN::stopService();

        if(l_errl)
        {
            break;
        }


    } while (0);

    if( l_errl )
    {
        // Create IStep error log and cross reference to error that occurred
        l_stepError.addErrorDetails( l_errl );

        // Commit Error
        errlCommit( l_errl, HWPF_COMP_ID );
    }


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_mss_memdiag exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}

//
//  Wrapper function to call mss_thermal_init
//
void*    call_mss_thermal_init( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;
    IStepError  l_StepError;

    do
    {
        // Get all Centaur targets
        TARGETING::TargetHandleList l_memBufTargetList;
        getAllChips(l_memBufTargetList, TYPE_MEMBUF );

        //  --------------------------------------------------------------------
        //  run mss_thermal_init on all Centaurs
        //  --------------------------------------------------------------------
        for (TargetHandleList::const_iterator
                l_iter = l_memBufTargetList.begin();
                l_iter != l_memBufTargetList.end();
                ++l_iter)
        {
            //  make a local copy of the target for ease of use
            const TARGETING::Target*  l_pCentaur = *l_iter;

            //  write HUID of target
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "target HUID %.8X", TARGETING::get_huid(l_pCentaur));

            // cast OUR type of target to a FAPI type of target.
            const fapi::Target l_fapi_pCentaur( TARGET_TYPE_MEMBUF_CHIP,
                    (const_cast<TARGETING::Target*>(l_pCentaur)) );

            // Current run on target
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "Running call_mss_thermal_init HWP on "
                    "target HUID %.8X", TARGETING::get_huid(l_pCentaur));


            //  call the HWP with each fapi::Target
            FAPI_INVOKE_HWP( l_errl, mss_thermal_init, l_fapi_pCentaur );

            if ( l_errl )
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "ERROR 0x%.8X: mss_thermal_init HWP returns error",
                        l_errl->reasonCode());

                // capture the target data in the elog
                ErrlUserDetailsTarget(l_pCentaur).addToLog( l_errl );

                // Create IStep error log and cross reference to error that occurred
                l_StepError.addErrorDetails( l_errl );

                // Commit Error
                errlCommit( l_errl, HWPF_COMP_ID );

                break;
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "SUCCESS : mss_thermal_init HWP( )" );
            }
        }
        if (l_errl)
        {
            break;
        }

        // Run proc throttle sync
        // Get all functional proc chip targets
        TARGETING::TargetHandleList l_cpuTargetList;
        getAllChips(l_cpuTargetList, TYPE_PROC);

        for (TARGETING::TargetHandleList::const_iterator
             l_cpuIter = l_cpuTargetList.begin();
             l_cpuIter != l_cpuTargetList.end();
             ++l_cpuIter)
        {
            const TARGETING::Target* l_pTarget = *l_cpuIter;
            fapi::Target l_fapiproc_target( TARGET_TYPE_PROC_CHIP,
                 (const_cast<TARGETING::Target*>(l_pTarget)));

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "Running proc_throttle_sync HWP on "
                    "target HUID %.8X", TARGETING::get_huid(l_pTarget));

            // Call proc_throttle_sync
            FAPI_INVOKE_HWP( l_errl, proc_throttle_sync, l_fapiproc_target );

            if (l_errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "ERROR 0x%.8X: proc_throttle_sync HWP returns error",
                          l_errl->reasonCode());

                // Capture the target data in the elog
                ErrlUserDetailsTarget(l_pTarget).addToLog(l_errl);

                // Create IStep error log and cross reference to error that occurred
                l_StepError.addErrorDetails( l_errl );

                // Commit Error
                errlCommit( l_errl, HWPF_COMP_ID );

                break;
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "SUCCESS :  proc_throttle_sync HWP( )" );
            }
        }

    } while (0);


    if(l_StepError.isNull())
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "SUCCESS : call_mss_thermal_init" );
    }

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

//
//  Wrapper function to call proc_pcie_config
//
void*    call_proc_pcie_config( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    IStepError  l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_pcie_config entry" );

    TARGETING::TargetHandleList l_procTargetList;
    getAllChips(l_procTargetList, TYPE_PROC );

    for ( TargetHandleList::const_iterator
          l_iter = l_procTargetList.begin();
          l_iter != l_procTargetList.end();
          ++l_iter )
    {
        const TARGETING::Target* l_pTarget = *l_iter;

        //  write HUID of target
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "target HUID %.8X", TARGETING::get_huid(l_pTarget));

        // build a FAPI type of target.
        const fapi::Target l_fapi_pTarget( TARGET_TYPE_PROC_CHIP,
                          (const_cast<TARGETING::Target*>(l_pTarget)) );

        //  call the HWP with each fapi::Target
        FAPI_INVOKE_HWP( l_errl, proc_pcie_config, l_fapi_pTarget );

        if ( l_errl )
        {
            // capture the target data in the elog
            ErrlUserDetailsTarget(l_pTarget).addToLog( l_errl );

            // Create IStep error log and cross reference to error that occurred
            l_stepError.addErrorDetails( l_errl );

            // Commit Error
            errlCommit( l_errl, HWPF_COMP_ID );

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR : proc_pcie_config" );

            break;
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "SUCCESS : proc_pcie_config" );
        }
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_pcie_config exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}


//
//  Wrapper function to call mss_power_cleanup
//
void*    call_mss_power_cleanup( void    *io_pArgs )
{
    errlHndl_t  l_err  =   NULL;
    IStepError  l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_mss_power_cleanup entry" );

    // Get a list of all present Centaurs
    TargetHandleList l_presCentaurs;
    getChipResources(l_presCentaurs, TYPE_MEMBUF, UTIL_FILTER_PRESENT);

    // For each present Centaur
    for (TargetHandleList::const_iterator
            l_cenIter = l_presCentaurs.begin();
            l_cenIter != l_presCentaurs.end();
            ++l_cenIter)
    {
        // Make a local copy of the target for ease of use
        TARGETING::Target * l_pCentaur = *l_cenIter;
        // Retrieve HUID of current Centaur
        TARGETING::ATTR_HUID_type l_currCentaurHuid =
            TARGETING::get_huid(l_pCentaur);

        // Find all present MBAs associated with this Centaur
        TARGETING::TargetHandleList l_presMbas;
        getChildAffinityTargetsByState(l_presMbas,
                                       l_pCentaur,
                                       CLASS_UNIT,
                                       TYPE_MBA,
                                       UTIL_FILTER_PRESENT);

        // If not at least two MBAs found
        if (l_presMbas.size() < 2)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "Not enough MBAs found for Centaur target HUID %.8X, "
              "skipping this Centaur.",
               l_currCentaurHuid);
            continue;
        }

        // Cache current MBA HUIDs for tracing
        TARGETING::ATTR_HUID_type l_currMBA0Huid =
                    TARGETING::get_huid(l_presMbas[0]);
        TARGETING::ATTR_HUID_type l_currMBA1Huid =
                    TARGETING::get_huid(l_presMbas[1]);

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "Running mss_power_cleanup HWP on "
                "Centaur HUID %.8X, MBA0 HUID %.8X, "
                "MBA1 HUID %.8X, ", l_currCentaurHuid,
                        l_currMBA0Huid, l_currMBA1Huid);

        // Create FAPI Targets.
        const fapi::Target l_fapiCentaurTarget(TARGET_TYPE_MEMBUF_CHIP,
                (const_cast<TARGETING::Target*>(l_pCentaur)));
        const fapi::Target l_fapiMba0Target(TARGET_TYPE_MBA_CHIPLET,
                (const_cast<TARGETING::Target*>(l_presMbas[0])));
        const fapi::Target l_fapiMba1Target(TARGET_TYPE_MBA_CHIPLET,
                (const_cast<TARGETING::Target*>(l_presMbas[1])));

        //  Call the HWP with each fapi::Target
        FAPI_INVOKE_HWP(l_err, mss_power_cleanup, l_fapiCentaurTarget,
                        l_fapiMba0Target, l_fapiMba1Target);

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "mss_power_cleanup HWP failed to perform"
                      " cleanup on centaur: 0x%.8X HWP_ERROR: 0x%.8X",
                      l_currCentaurHuid,l_err->reasonCode());
            // Capture the target data in the error log
            ErrlUserDetailsTarget(l_pCentaur).addToLog(l_err);
            // Create IStep error log and cross reference error that occurred
            l_stepError.addErrorDetails(l_err);
            // Commit error
            errlCommit(l_err, HWPF_COMP_ID);
        }
        else
        {
            // Success
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "Successfully ran mss_power_cleanup HWP on "
                    "Centaur HUID %.8X, MBA0 HUID %.8X, "
                    "MBA1 HUID %.8X, ", l_currCentaurHuid,
                           l_currMBA0Huid, l_currMBA1Huid);
        }
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_mss_power_cleanup exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}


//
//  Wrapper function to call proc_setup_bars
//
void*    call_proc_setup_bars( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    IStepError  l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_setup_bars entry" );


    // @@@@@    CUSTOM BLOCK:   @@@@@
    // Get all Centaur targets
    TARGETING::TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TYPE_PROC );

    //  --------------------------------------------------------------------
    //  run mss_setup_bars on all CPUs.
    //  --------------------------------------------------------------------
    for (TargetHandleList::const_iterator
            l_cpu_iter = l_cpuTargetList.begin();
            l_cpu_iter != l_cpuTargetList.end();
            ++l_cpu_iter)
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target* l_pCpuTarget = *l_cpu_iter;

        //  write HUID of target
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "mss_setup_bars: proc "
                "target HUID %.8X", TARGETING::get_huid(l_pCpuTarget));

        // cast OUR type of target to a FAPI type of target.
        const fapi::Target l_fapi_pCpuTarget( TARGET_TYPE_PROC_CHIP,
                           (const_cast<TARGETING::Target*> (l_pCpuTarget)) );

        TARGETING::TargetHandleList l_membufsList;
        getChildAffinityTargets(l_membufsList, l_pCpuTarget,
                                CLASS_CHIP, TYPE_MEMBUF);
        std::vector<fapi::Target> l_associated_centaurs;

        for (TargetHandleList::const_iterator
                l_membuf_iter = l_membufsList.begin();
                l_membuf_iter != l_membufsList.end();
                ++l_membuf_iter)
        {
            //  make a local copy of the target for ease of use
            const TARGETING::Target* l_pTarget = *l_membuf_iter;

            // cast OUR type of target to a FAPI type of target.
            const fapi::Target l_fapi_centaur_target(fapi::TARGET_TYPE_MEMBUF_CHIP,
            (const_cast<TARGETING::Target*>(l_pTarget)) );

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
            "target HUID %.8X", TARGETING::get_huid(l_pTarget));

            l_associated_centaurs.push_back(l_fapi_centaur_target);
        }

        //  call the HWP with each fapi::Target
        FAPI_INVOKE_HWP(l_errl,
                        mss_setup_bars,
                        l_fapi_pCpuTarget, l_associated_centaurs );

        if ( l_errl )
        {
            // capture the target data in the elog
            ErrlUserDetailsTarget(l_pCpuTarget).addToLog( l_errl );

            // Create IStep error log and cross reference to error that occurred
            l_stepError.addErrorDetails( l_errl );

            // Commit Error
            errlCommit( l_errl, HWPF_COMP_ID );

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR : mss_setup_bars" );
            // break and return with error
            break;
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "SUCCESS : mss_setup-bars" );
        }
    }   // endfor


    if ( l_stepError.isNull() )
    {
        //----------------------------------------------------------------------
        //  run proc_setup_bars on all CPUs
        //----------------------------------------------------------------------
        std::vector<proc_setup_bars_proc_chip> l_proc_chips;

        TargetPairs_t l_abusLinks;
        l_errl = PbusLinkSvc::getTheInstance().getPbusConnections(
                                    l_abusLinks, TYPE_ABUS, false );

        for (TargetHandleList::const_iterator
                l_cpu_iter = l_cpuTargetList.begin();
                l_cpu_iter != l_cpuTargetList.end() && !l_errl;
                ++l_cpu_iter)
        {
            //  make a local copy of the target for ease of use
            const TARGETING::Target* l_pCpuTarget = *l_cpu_iter;

            // cast OUR type of target to a FAPI type of target.
            const fapi::Target l_fapi_pCpuTarget( TARGET_TYPE_PROC_CHIP,
                        (const_cast<TARGETING::Target*> (l_pCpuTarget)) );

            proc_setup_bars_proc_chip l_proc_chip ;
            l_proc_chip.this_chip  = l_fapi_pCpuTarget;
            l_proc_chip.process_f0 = true;
            l_proc_chip.process_f1 = true;

            TARGETING::TargetHandleList l_abuses;
            getChildChiplets( l_abuses, l_pCpuTarget, TYPE_ABUS );

            for (TargetHandleList::const_iterator
                    l_abus_iter = l_abuses.begin();
                    l_abus_iter != l_abuses.end();
                    ++l_abus_iter)
            {
                const TARGETING::Target* l_target = *l_abus_iter;
                uint8_t l_srcID = l_target->getAttr<ATTR_CHIP_UNIT>();
                TargetPairs_t::iterator l_itr = l_abusLinks.find(l_target);
                if ( l_itr == l_abusLinks.end() )
                {
                    continue;
                }

                const TARGETING::Target *l_pParent = NULL;
                l_pParent = getParentChip(
                              (const_cast<TARGETING::Target*>(l_itr->second)));
                fapi::Target l_fapiproc_parent( TARGET_TYPE_PROC_CHIP,
                                             (void *)l_pParent );

                switch (l_srcID)
                {
                    case 0: l_proc_chip.a0_chip = l_fapiproc_parent; break;
                    case 1: l_proc_chip.a1_chip = l_fapiproc_parent; break;
                    case 2: l_proc_chip.a2_chip = l_fapiproc_parent; break;
                   default: break;
                }
            }

            l_proc_chips.push_back( l_proc_chip );

        }   // endfor

        if (!l_errl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "call proc_setup_bars");

            //  call the HWP with each fapi::Target
            FAPI_INVOKE_HWP( l_errl, proc_setup_bars, l_proc_chips, true );

            if ( l_errl )
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "ERROR : proc_setup_bars" );
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "SUCCESS : proc_setup_bars" );
            }
        }
    }   // end if !l_errl

    // @@@@@    END CUSTOM BLOCK:   @@@@@

    if ( l_errl )
    {

        // Create IStep error log and cross reference to error that occurred
        l_stepError.addErrorDetails( l_errl);

        // Commit Error
        errlCommit( l_errl, HWPF_COMP_ID );
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_setup_bars exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}


//
//  Wrapper function to call proc_exit_cache_contained
//
void*    call_proc_exit_cache_contained( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    IStepError  l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_exit_cache_contained entry" );

    // @@@@@    CUSTOM BLOCK:   @@@@@
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)
    //  extend the memory space from 8MEG to 32Meg

    //if mirrored then check that there is going to be memory at that location.
    //For sapphire with mirrored location flipped and at zero,
    //this also insures there is memory available to 'exit_cache' to.
    //Also set ATTR_PAYLOAD_BASE here.
    TARGETING::Target* l_sys = NULL;
    targetService().getTopLevelTarget(l_sys);
    assert( l_sys != NULL );

    uint8_t l_mpipl = l_sys->getAttr<ATTR_IS_MPIPL_HB>();
    ATTR_PAYLOAD_BASE_type payloadBase = 0;

    if(!l_mpipl)
    {
        ATTR_PAYLOAD_IN_MIRROR_MEM_type l_mirrored = false;

        // In Sapphire mode disable mirroring for now - @todo-RTC:108314
        // and force payload to zero
        if(!is_sapphire_load())
        {
            payloadBase = l_sys->getAttr<ATTR_PAYLOAD_BASE>();
            l_mirrored = l_sys->getAttr<ATTR_PAYLOAD_IN_MIRROR_MEM>();
        }

        if(l_mirrored)
        {
            ATTR_MIRROR_BASE_ADDRESS_type l_mirrorBaseAddr = 0;
            if(!is_sapphire_load())
            {
                uint64_t hrmor_base =
                    l_sys->getAttr<TARGETING::ATTR_HB_HRMOR_NODAL_BASE>();

                l_mirrorBaseAddr =
                    l_sys->getAttr<TARGETING::ATTR_MIRROR_BASE_ADDRESS>();

                // For single-node systems, the non-master processors can be
                // in a different logical (powerbus) node.
                // Need to migrate task to master.
                task_affinity_pin();
                task_affinity_migrate_to_master();
                uint64_t this_node = INTR::PIR_t(task_getcpuid()).nodeId;
                task_affinity_unpin();

                l_mirrorBaseAddr += (this_node * hrmor_base)/2;

            }

            // Verify there is memory at the mirrored location
            bool mirroredMemExists = false;
            TARGETING::TargetHandleList l_procList;
            getAllChips(l_procList, TYPE_PROC);

            for (TargetHandleList::const_iterator proc = l_procList.begin();
                 proc != l_procList.end() && !mirroredMemExists;
                 ++proc)
            {
                uint64_t mirrorBase[4];
                uint64_t mirrorSize[4];
                bool rc = (*proc)->
                    tryGetAttr<TARGETING::ATTR_PROC_MIRROR_BASES>(mirrorBase);
                if(false == rc)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                              "Failed to get ATTR_PROC_MIRROR_BASES");
                    assert(0);
                }

                rc = (*proc)->
                    tryGetAttr<TARGETING::ATTR_PROC_MIRROR_SIZES>(mirrorSize);
                if(false == rc)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                              "Failed to get ATTR_PROC_MIRROR_SIZES");
                    assert(0);
                }

                for(uint64_t i = 0; i < 4 && !mirroredMemExists; ++i)
                {
                    if(mirrorSize[i] != 0 &&
                       l_mirrorBaseAddr >= mirrorBase[i] &&
                       l_mirrorBaseAddr < (mirrorBase[i] + mirrorSize[i]))
                    {
                        mirroredMemExists = true;
                    }
                }
            }

            if (mirroredMemExists)
            {
                // ATTR_PAYLOAD_BASE is in MB
                payloadBase += l_mirrorBaseAddr/MEGABYTE;
            }
            else
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK
                          "Request to load payload into mirrored memory,"
                          " but no memory exists at address 0x%016lx",
                          l_mirrorBaseAddr);

                /*@
                 *  @errortype      ERRL_SEV_CRITICAL_SYS_TERM
                 *  @moduleid       fapi::MOD_EXIT_CACHE_CONTAINED,
                 *  @reasoncode     fapi::RC_NO_MIRRORED_MEMORY,
                 *  @userdata1      Mirrored Memory Address
                 *  @userdata2      0
                 *
                 *  @devdesc        Request given to load payload into mirrored
                 *                  memory, but no mirrored memory exists at
                 *                  that location.
                 */
                l_errl = new ERRORLOG::ErrlEntry
                    (
                     ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                     fapi::MOD_EXIT_CACHE_CONTAINED,
                     fapi::RC_NO_MIRRORED_MEMORY,
                     l_mirrorBaseAddr,
                     0,
                     true); // callout firmware
            }
        }
        // If we're not mirrored, payloadBase is the lowest mem_base.
        // Note that if we are mirrored, finding the correct mirror
        // base yields the proper payloadBase. This should also work
        // for sapphire as a single (working) node will return 0 for
        // bottom_mem_addr.
        else {
            payloadBase += get_bottom_mem_addr()/MEGABYTE;
        }
    }

    if(!l_errl)
    {
        if(!l_mpipl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "Payload base address is 0x%016lx",
                      payloadBase * MEGABYTE);

            l_sys->setAttr<ATTR_PAYLOAD_BASE>(payloadBase);
        }

        //  call the HWP with each fapi::Target
        FAPI_INVOKE_HWP( l_errl,
                         proc_exit_cache_contained
                       );



        if ( l_errl )
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR : call_proc_exit_cache_contained, "
                      "errorlog PLID=0x%x",
                      l_errl->plid() );
        }
        // no errors so extend VMM.
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "SUCCESS : call_proc_exit_cache_contained" );



            // Call the function to extend VMM to 32MEG
            int rc = mm_extend();

            if (rc!=0)
            {
                /*@
                 * @errortype
                 * @moduleid     fapi::MOD_EXIT_CACHE_CONTAINED
                 * @reasoncode   fapi::RC_MM_EXTEND_FAILED
                 * @userdata1    rc from mm_extend
                 * @userdata2    <UNUSED>
                 *
                 *   @devdesc  Failure extending memory to 32MEG after
                 *        exiting cache contained mode.
                 */
                l_errl = new ERRORLOG::ErrlEntry
                    (ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                     fapi::MOD_EXIT_CACHE_CONTAINED,
                     fapi::RC_MM_EXTEND_FAILED,
                     rc,
                     0);

                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "ERROR : call_proc_exit_cache_contained"
                          " - extendVMM, rc=0x%x",
                          rc );
            }
            else
            {
                // trace out the extend VMM was successful
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "SUCCESS : call_proc_exit_cache_contained"
                          " - extendVMM");
            }
        }
    }
    if ( l_errl )
    {
        // Create IStep error log and cross reference to error that occurred
        l_stepError.addErrorDetails( l_errl );

        // Commit Error
        errlCommit( l_errl, HWPF_COMP_ID );
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_exit_cache_contained exit" );

    // @@@@@    END CUSTOM BLOCK:   @@@@@

    // end task, returning any errorlogs to IStepDisp
   return l_stepError.getErrorHandle();
}


//
//  Wrapper function to call call_host_mpipl_service
//
void*   call_host_mpipl_service( void *io_pArgs )
{

    IStepError l_StepError;

    errlHndl_t l_err = NULL;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_mpipl_service entry" );

    // call proc_mpipl_chip_cleanup.C
    TARGETING::TargetHandleList l_procTargetList;
    getAllChips(l_procTargetList, TYPE_PROC );

    //  ---------------------------------------------------------------
    //  run proc_mpipl_chip_cleanup.C on all proc chips
    //  ---------------------------------------------------------------
    for (TargetHandleList::const_iterator
         l_iter = l_procTargetList.begin();
         l_iter != l_procTargetList.end();
         ++l_iter)
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target*  l_pProcTarget = *l_iter;

        //  write HUID of target
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "target HUID %.8X", TARGETING::get_huid(l_pProcTarget));

        // cast OUR type of target to a FAPI type of target.
        const fapi::Target l_fapi_pProcTarget( TARGET_TYPE_PROC_CHIP,
                           (const_cast<TARGETING::Target*> (l_pProcTarget)) );

        //  call the HWP with each fapi::Target
        FAPI_INVOKE_HWP(l_err, proc_mpipl_chip_cleanup,
                        l_fapi_pProcTarget );

        if ( l_err )
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR : returned from proc_mpipl_chip_cleanup" );

            // capture the target data in the elog
            ERRORLOG::ErrlUserDetailsTarget(l_pProcTarget).addToLog( l_err );

            // since we are doing an mpipl break out, the mpipl has failed
            break;
        }

        //  ---------------------------------------------------------------
        //  run proc_mpipl_ex_cleanup.C on all proc chips
        //  ---------------------------------------------------------------
        //  call the HWP with each fapi::Target
        FAPI_INVOKE_HWP(l_err,
                        proc_mpipl_ex_cleanup,
                        l_fapi_pProcTarget );

        if ( l_err )
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR : returned from proc_mpipl_ex_cleanup" );

            // capture the target data in the elog
            ERRORLOG::ErrlUserDetailsTarget(l_pProcTarget).addToLog( l_err );

            // since we are doing an mpipl break out, the mpipl has failed
            break;
        }
    }

    //Determine if we should perform dump ops
    //Note that this is only called in MPIPL context, so don't
    //have to check MPIPL
    bool collect_dump = false;
    TARGETING::Target * sys = NULL;
    TARGETING::targetService().getTopLevelTarget( sys );
    TARGETING::CecIplType type;
    if(sys &&
       sys->tryGetAttr<TARGETING::ATTR_CEC_IPL_TYPE>(type) &&
       type.PostDump)
    {
        collect_dump = true;
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "Ready to collect dump -- yes/no [%d]", collect_dump);

    // No error on the procedure.. proceed to collect the dump.
    if (!l_err && collect_dump)
    {

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "SUCCESS : proc_mpipl_ex_cleanup" );

        // currently according to Adriana, the dump calls should only cause an
        // istep failure when the dump collect portion of this step fails..  We
        // will not fail the istep on any mbox message failures. instead we will
        // simply commit the errorlog and continue.

        errlHndl_t l_errMsg = NULL;

        // Dump relies upon the runtime module
        // Not declaring in istep DEP list cause if we load it
        // we want it to stay loaded
        if (  !VFS::module_is_loaded( "libruntime.so" ) )
        {
            l_err = VFS::module_load( "libruntime.so" );

            if ( l_err )
            {
                //  load module returned with errl set
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "Could not load runtime module" );
            }
        }

        // If dump module successfull loaded then continue with DumpCollect and
        // messaging
        if (!l_err)
        {
            do
            {
                // send the start message
                l_errMsg = DUMP::sendMboxMsg(DUMP::DUMP_MSG_START_MSG_TYPE);

                // If error, commit and send error message.
                if (l_errMsg)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                       "ERROR : returned from DUMP::sendMboxMsg - dump start" );

                    errlCommit( l_errMsg, HWPF_COMP_ID );

                    // don't break in this case because we not want to fail the
                    // istep on the dump collect so we will continue after we
                    // log the errhandle that we can't send a message.
                }

                // Call the dump collect
                l_err = DUMP::doDumpCollect();

                // Got a Dump Collect error.. Commit the dumpCollect
                // errorlog and then send an dump Error mbox message
                // and FSP will decide what to do.
                // We do not want dump Collect failures to terminate the istep.
                if (l_err)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "ERROR : returned from DUMP::HbDumpCopySrcToDest" );

                    break;
                }

            } while(0);

            DUMP::DUMP_MSG_TYPE msgType = DUMP::DUMP_MSG_END_MSG_TYPE;

            // Send dumpCollect success trace
            if (!l_err)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "SUCCESS : doDumpCollect" );
            }
            // got an error that we need to send a ERROR message to FSP
            // and commit the errorlog from dumpCollect.
            else
            {
                msgType = DUMP::DUMP_MSG_ERROR_MSG_TYPE;

                // Commit the dumpCollect errorlog from above as
                // we dont want dump collect to kill the istep
                errlCommit( l_err, HWPF_COMP_ID );

            }

            // Send an Error mbox msg to FSP (either end or error)
            l_errMsg = DUMP::sendMboxMsg(msgType);

            if (l_errMsg)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "ERROR : returned from DUMP::sendMboxMsg" );

                errlCommit( l_errMsg, HWPF_COMP_ID );
            }


            // Need to unload the dump module regardless of whether we have
            // an error or not.
            errlHndl_t l_errUnLoad = VFS::module_unload( "libdump.so" );

            if (l_errUnLoad)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                     "ERROR : returned from VFS::module_unload (libdump.so)" );

                errlCommit( l_errUnLoad, HWPF_COMP_ID );
            }

        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR : returned from VFS::module_load (libdump.so)" );
        }
    }

    // If got an error in the procedure or collection of the dump kill the istep
    if( l_err )
    {
        // Create IStep error log and cross reference to error that occurred
        l_StepError.addErrorDetails( l_err );

        // Commit Error
        errlCommit( l_err, HWPF_COMP_ID );
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_mpipl_service exit" );

    return l_StepError.getErrorHandle();
}

};   // end namespace
