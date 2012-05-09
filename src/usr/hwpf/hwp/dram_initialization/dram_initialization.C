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
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>
#include    <diag/mdia/mdia.H>
#include    <initservice/isteps_trace.H>

//  targeting support
#include    <targeting/common/commontargeting.H>

//  fapi support
#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>

#include    "dram_initialization.H"

//  Uncomment these files as they become available:
// #include    "host_startPRD_dram/host_startPRD_dram.H"
// #include    "mss_extent_setup/mss_extent_setup.H"
// #include    "mss_memdiag/mss_memdiag.H"
// #include    "mss_scrub/mss_scrub.H"
// #include    "mss_thermal_init/mss_thermal_init.H"
// #include    "proc_setup_bars/proc_setup_bars.H"
// #include    "proc_pbus_epsilon/proc_pbus_epsilon.H"
#include    "proc_exit_cache_contained/proc_exit_cache_contained.H"

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
    FAPI_INVOKE_HWP( l_errl, mss_extent_setup, _args_...);
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

    PredicateIsFunctional l_isFunctional;

    // To filter MBAs
    PredicateCTM l_mbaFilter(CLASS_UNIT, TYPE_MBA);

    // Filter functional MBAs
    PredicatePostfixExpr l_functionalAndMbaFilter;
    l_functionalAndMbaFilter.push(&l_mbaFilter).push(&l_isFunctional).And();

    TargetRangeFilter    l_pMbas(
        targetService().begin(),
        targetService().end(),
        &l_functionalAndMbaFilter );

    TargetHandleList l_mbaList;

    // populate MBA TargetHandlelist
    for(;l_pMbas;++l_pMbas)
    {
        l_mbaList.push_back(*l_pMbas);
    }

    errlHndl_t l_err = runStep(l_mbaList);
    if(NULL != l_err)
    {
        TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "MDIA subStep failed");
    }

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
    FAPI_INVOKE_HWP( l_errl, proc_setup_bars, _args_...);
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
               "call_proc_setup_bars exit" );

    // end task, returning any errorlogs to IStepDisp
    task_end2( l_errl );
}



//
//  Wrapper function to call 14.7 :
//      proc_pbus_epsilon
//
void    call_proc_pbus_epsilon( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_pbus_epsilon entry" );

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
    FAPI_INVOKE_HWP( l_errl, proc_pbus_epsilon, _args_...);
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
               "call_proc_pbus_epsilon exit" );

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
    // @@@@@    END CUSTOM BLOCK:   @@@@@

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_exit_cache_contained exit" );

    // end task, returning any errorlogs to IStepDisp
    task_end2( l_errl );
}


};   // end namespace
