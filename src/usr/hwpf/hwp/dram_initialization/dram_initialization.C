/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/dram_initialization/dram_initialization.C $
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
 *  @file dram_initialization.C
 *
 *  Support file for IStep: dram_initialization
 *   Dram Initialization
 *
 *  *****************************************************************
 *  THIS FILE WAS GENERATED ON 2012-04-11:1608
 *  *****************************************************************
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
#include    <diag/mdia/mdia.H>
#include    <diag/attn/attn.H>
#include    <initservice/isteps_trace.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/util.H>
#include    <targeting/common/utilFilter.H>

//  fapi support
#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>

#include    "dram_initialization.H"

//  Uncomment these files as they become available:
// #include    "host_startPRD_dram/host_startPRD_dram.H"
#include    "mss_extent_setup/mss_extent_setup.H"
// #include    "mss_memdiag/mss_memdiag.H"
// #include    "mss_scrub/mss_scrub.H"
// #include    "mss_thermal_init/mss_thermal_init.H"
#include    "proc_setup_bars/mss_setup_bars.H"
#include    "proc_setup_bars/proc_setup_bars.H"
// #include    "proc_pcie_config/proc_pcie_config.H"
#include    "proc_exit_cache_contained/proc_exit_cache_contained.H"
#include    <hwpf/plat/fapiPlatReasonCodes.H>
//remove these once memory setup workaround is removed
#include <devicefw/driverif.H>
#include <spd/spdenums.H>
#include <sys/time.h>
#include <sys/mm.h>


namespace   DRAM_INITIALIZATION
{

using   namespace   TARGETING;
using   namespace   fapi;



//
//  Wrapper function to call 14.1 :
//      host_startPRD_dram
//
void    call_host_startPRD_dram( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_startPRD_dram entry" );

#if 0
    // @@@@@    CUSTOM BLOCK:   @@@@@
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)

    //  dump physical path to targets
    EntityPath l_path;
    l_path  =   l_@targetN_target->getAttr<ATTR_PHYS_PATH>();
    l_path.dump();

    // cast OUR type of target to a FAPI type of target.
    const fapi::Target l_fapi_@targetN_target(
                    TARGET_TYPE_MEMBUF_CHIP,
                    reinterpret_cast<void *>
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

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_startPRD_dram exit" );

    // end task, returning any errorlogs to IStepDisp
    task_end2( l_errl );
}

//
//  Wrapper function to call 14.2 :
//      mss_extent_setup
//
void    call_mss_extent_setup( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_mss_extent_setup entry" );

    //  call the HWP
    FAPI_INVOKE_HWP( l_errl, mss_extent_setup );

    if ( l_errl )
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR : failed executing mss_extent_setup returning error" );
    }
    else
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS : mss_extent_setup completed ok" );
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_mss_extent_setup exit" );

    // end task, returning any errorlogs to IStepDisp
    task_end2( l_errl );
}

//
//  Wrapper function to call 14.3 :
//      mss_memdiag
//
void    call_mss_memdiag( void    *io_pArgs )
{
    using namespace MDIA;

    errlHndl_t  l_errl  =   NULL;

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
            TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "MDIA subStep failed");
            break;
        }

        l_errl = ATTN::stopService();

        if(l_errl)
        {
            break;
        }


    } while (0);

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_mss_memdiag exit" );

    // end task, returning any errorlogs to IStepDisp
    task_end2( l_errl );
}



//
//  Wrapper function to call 14.4 :
//      mss_scrub
//
void    call_mss_scrub( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_mss_scrub entry" );

#if 0
    // @@@@@    CUSTOM BLOCK:   @@@@@
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)

    //  dump physical path to targets
    EntityPath l_path;
    l_path  =   l_@targetN_target->getAttr<ATTR_PHYS_PATH>();
    l_path.dump();

    // cast OUR type of target to a FAPI type of target.
    const fapi::Target l_fapi_@targetN_target(
                    TARGET_TYPE_MEMBUF_CHIP,
                    reinterpret_cast<void *>
                        (const_cast<TARGETING::Target*>(l_@targetN_target)) );

    //  call the HWP with each fapi::Target
    FAPI_INVOKE_HWP( l_errl, mss_scrub, _args_...);
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

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_mss_scrub exit" );

    // end task, returning any errorlogs to IStepDisp
    task_end2( l_errl );
}



//
//  Wrapper function to call 14.5 :
//      mss_thermal_init
//
void    call_mss_thermal_init( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_mss_thermal_init entry" );

#if 0
    // @@@@@    CUSTOM BLOCK:   @@@@@
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)

    //  dump physical path to targets
    EntityPath l_path;
    l_path  =   l_@targetN_target->getAttr<ATTR_PHYS_PATH>();
    l_path.dump();

    // cast OUR type of target to a FAPI type of target.
    const fapi::Target l_fapi_@targetN_target(
                    TARGET_TYPE_MEMBUF_CHIP,
                    reinterpret_cast<void *>
                        (const_cast<TARGETING::Target*>(l_@targetN_target)) );

    //  call the HWP with each fapi::Target
    FAPI_INVOKE_HWP( l_errl, mss_thermal_init, _args_...);
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

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_mss_thermal_init exit" );

    // end task, returning any errorlogs to IStepDisp
    task_end2( l_errl );
}



//
//  Wrapper function to call 14.6 :
//      proc_setup_bars
//
void    call_proc_setup_bars( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_setup_bars entry" );


    // @@@@@    CUSTOM BLOCK:   @@@@@
    // Get all Centaur targets
    TARGETING::TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TYPE_PROC );


    //  -----------------------------------------------------------------------
    //  run mss_setup_bars on all CPUs.
    //  -----------------------------------------------------------------------
    for ( size_t i = 0; i < l_cpuTargetList.size(); i++ )
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target*  l_pCpuTarget = l_cpuTargetList[i];

        TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "mss_setup_bars: proc %d", i );
        //  dump physical path to targets
        EntityPath l_path;
        l_path  =   l_pCpuTarget->getAttr<ATTR_PHYS_PATH>();
        l_path.dump();

        // cast OUR type of target to a FAPI type of target.
        const fapi::Target l_fapi_pCpuTarget(
                                            TARGET_TYPE_PROC_CHIP,
                                            reinterpret_cast<void *>
                                            (const_cast<TARGETING::Target*>
                                             (l_pCpuTarget)) );

        //  call the HWP with each fapi::Target
        FAPI_INVOKE_HWP( l_errl,
                         mss_setup_bars,
                         l_fapi_pCpuTarget );

        if ( l_errl )
        {
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



    //  ----------------------------------------------------------------------
    // @@@@@    TEMPORARY SIMICS HACK for PHYP 6/1 milestone @@@@@
    //  ----------------------------------------------------------------------
    if ( !TARGETING::is_vpo() )
    {
        //Now need to scom the L3 bar on my EX to trigger Simics cache contained exit
        if (!l_errl)
        {
            TARGETING::Target* procTarget = NULL;
            TARGETING::targetService().masterProcChipTargetHandle( procTarget );

            //Base scom address is 0x1001080b, need to place core id from cpuid
            //EX chiplet is bits 4:7 of scom addr, EX unit in cpuid is bits 25:28
            uint32_t scom_addr = 0x1001080b | (((task_getcpuid()) & 0x78) << 21);
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "EX L3 BAR1 addr [%08x]", scom_addr);

            uint64_t scom_data = 0x0; //data doesn't matter, just the write
            size_t size = sizeof(scom_data);

            l_errl = deviceWrite( procTarget,
                                  &scom_data,
                                  size,
                                  DEVICE_SCOM_ADDRESS(scom_addr) );
            if (l_errl)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "Failed to write EX %08x addr\n", scom_addr);
            }
        }
        // @@@@@    end TEMPORARY SIMICS HACK for PHYP 6/1 milestone @@@@@
    }

    if ( ! l_errl )
    {
        //  -----------------------------------------------------------------------
        //  run proc_setup_bars on all CPUs
        //  -----------------------------------------------------------------------
        std::vector<proc_setup_bars_proc_chip> l_proc_chips;

        for ( size_t i = 0; i < l_cpuTargetList.size(); i++ )
        {
            //  make a local copy of the target for ease of use
            const TARGETING::Target*  l_pCpuTarget = l_cpuTargetList[i];

            TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "proc_setup_bars: proc %d", i );
            //  dump physical path to targets
            EntityPath l_path;
            l_path  =   l_pCpuTarget->getAttr<ATTR_PHYS_PATH>();
            l_path.dump();

            // cast OUR type of target to a FAPI type of target.
            const fapi::Target l_fapi_pCpuTarget(
                                                TARGET_TYPE_MEMBUF_CHIP,
                                                reinterpret_cast<void *>
                                                (const_cast<TARGETING::Target*>
                                                 (l_pCpuTarget)) );
            //  @todo Create dummy aX targets
            const fapi::Target  l_a0_chip;
            const fapi::Target  l_a1_chip;
            const fapi::Target  l_a2_chip;


            proc_setup_bars_proc_chip l_proc_chip ;
            l_proc_chip.this_chip  =   l_fapi_pCpuTarget;
            l_proc_chip.a0_chip    =    l_a0_chip;
            l_proc_chip.a1_chip    =    l_a1_chip;
            l_proc_chip.a2_chip    =    l_a2_chip;
            l_proc_chip.process_f0 =    true;
            l_proc_chip.process_f1 =    true;

            l_proc_chips.push_back( l_proc_chip );

            //  call the HWP with each fapi::Target
            FAPI_INVOKE_HWP( l_errl,
                             proc_setup_bars,
                             l_proc_chips,
                             true );

            if ( l_errl )
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "ERROR : proc_setup_bars" );
                //  break out with error
                break;
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "SUCCESS : proc_setup-bars" );
            }
        }   // endfor
    }   // end if !l_errl

    // @@@@@    END CUSTOM BLOCK:   @@@@@

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_setup_bars exit" );

    // end task, returning any errorlogs to IStepDisp
    task_end2( l_errl );
}



//
//  Wrapper function to call 14.7 :
//      proc_pcie_config
//
void    call_proc_pcie_config( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_pcie_config entry" );

#if 0
    // @@@@@    CUSTOM BLOCK:   @@@@@
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)

    //  dump physical path to targets
    EntityPath l_path;
    l_path  =   l_@targetN_target->getAttr<ATTR_PHYS_PATH>();
    l_path.dump();

    // cast OUR type of target to a FAPI type of target.
    const fapi::Target l_fapi_@targetN_target(
                    TARGET_TYPE_MEMBUF_CHIP,
                    reinterpret_cast<void *>
                        (const_cast<TARGETING::Target*>(l_@targetN_target)) );

    //  call the HWP with each fapi::Target
    FAPI_INVOKE_HWP( l_errl, proc_pcie_config, _args_...);
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

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_pcie_config exit" );

    // end task, returning any errorlogs to IStepDisp
    task_end2( l_errl );
}



//
//  Wrapper function to call 14.8 :
//      proc_exit_cache_contained
//
void    call_proc_exit_cache_contained( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_exit_cache_contained entry" );

    // @@@@@    CUSTOM BLOCK:   @@@@@
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)
    //  extend the memory space from 8MEG to 32Meg

    //  call the HWP with each fapi::Target
    FAPI_INVOKE_HWP( l_errl,
                     proc_exit_cache_contained
                     );
    if ( l_errl )
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "ERROR : call_proc_exit_cache_contained, errorlog PLID=0x%x",
                  l_errl->plid() );
    }
    else
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "SUCCESS : call_proc_exit_cache_contained" );
    }


    // Call the function to extend VMM to 32MEG
    int rc = mm_extend();

    if (rc!=0)
    {
        /*@
         * @errortype
         * @moduleid     fapi::MOD_EXIT_CACHE_CONTAINED
         * @reasoncode   fapi::RC_MM_EXTEND_FAILED
         *   @userdata1  rc from mm_extend
         *   @userdata2        <UNUSED>
         *
         *   @devdesc  Failure extending memory to 32MEG after
         *        exiting cache contained mode.
         */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         fapi::MOD_EXIT_CACHE_CONTAINED,
                                         fapi::RC_MM_EXTEND_FAILED,
                                         rc,
                                         0);

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "ERROR : call_proc_exit_cache_contained - extendVMM, rc=0x%x",
                  rc );
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_exit_cache_contained exit" );

    // @@@@@    END CUSTOM BLOCK:   @@@@@

    // end task, returning any errorlogs to IStepDisp
    task_end2( l_errl );
}


};   // end namespace
