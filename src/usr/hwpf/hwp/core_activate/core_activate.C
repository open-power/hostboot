//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/hwp/core_activate/core_activate.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END

/**
 *  @file core_activate.C
 *
 *  Support file for IStep: core_activate
 *   Core Activate
 *
 *  *****************************************************************
 *  THIS FILE WAS GENERATED ON 2012-04-11:1609
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

#include    <initservice/isteps_trace.H>

//  targeting support
#include    <targeting/attributes.H>
#include    <targeting/entitypath.H>
#include    <targeting/target.H>
#include    <targeting/targetservice.H>
#include    <targeting/iterators/rangefilter.H>
#include    <targeting/predicates/predicatectm.H>
#include    <targeting/predicates/predicatepostfixexpr.H>
#include    <targeting/predicates/predicateisfunctional.H>

//  fapi support
#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>

#include    "core_activate.H"

//  Uncomment these files as they become available:
// #include    "host_activate_master/host_activate_master.H"
// #include    "host_activate_slave_cores/host_activate_slave_cores.H"
// #include    "host_ipl_complete/host_ipl_complete.H"

namespace   CORE_ACTIVATE
{

using   namespace   TARGETING;
using   namespace   fapi;



//
//  Wrapper function to call 16.1 :
//      host_activate_master
//
void    call_host_activate_master( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
               "call_host_activate_master entry" );

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
    FAPI_INVOKE_HWP( l_errl, host_activate_master, _args_...);
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
               "call_host_activate_master exit" );

    // end task, returning any errorlogs to IStepDisp 
    task_end2( l_errl );
}



//
//  Wrapper function to call 16.2 :
//      host_activate_slave_cores
//
void    call_host_activate_slave_cores( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
               "call_host_activate_slave_cores entry" );

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
    FAPI_INVOKE_HWP( l_errl, host_activate_slave_cores, _args_...);
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
               "call_host_activate_slave_cores exit" );

    // end task, returning any errorlogs to IStepDisp 
    task_end2( l_errl );
}



//
//  Wrapper function to call 16.3 :
//      host_ipl_complete
//
void    call_host_ipl_complete( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
               "call_host_ipl_complete entry" );

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
    FAPI_INVOKE_HWP( l_errl, host_ipl_complete, _args_...);
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
               "call_host_ipl_complete exit" );

    // end task, returning any errorlogs to IStepDisp 
    task_end2( l_errl );
}


};   // end namespace
