//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/hwp/start_clocks_on_nest_chiplets/start_clocks_on_nest_chiplets.C $
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
 *  @file start_clocks_on_nest_chiplets.C
 *
 *  Support file for IStep: start_clocks_on_nest_chiplets
 *   Start Clocks On Nest Chiplets
 *
 *  *****************************************************************
 *  THIS FILE WAS GENERATED ON 2012-04-11:1605
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

#include    "start_clocks_on_nest_chiplets.H"

//  Uncomment these files as they become available:
// #include    "proc_a_x_pci_dmi_pll_setup/proc_a_x_pci_dmi_pll_setup.H"
// #include    "proc_startclock_chiplets/proc_startclock_chiplets.H"
// #include    "proc_chiplet_scominit/proc_chiplet_scominit.H"
// #include    "proc_scomoverride_chiplets/proc_scomoverride_chiplets.H"

namespace   START_CLOCKS_ON_NEST_CHIPLETS
{

using   namespace   TARGETING;
using   namespace   fapi;



//
//  Wrapper function to call 07.1 :
//      proc_a_x_pci_dmi_pll_setup
//
void    call_proc_a_x_pci_dmi_pll_setup( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
               "call_proc_a_x_pci_dmi_pll_setup entry" );

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
    FAPI_INVOKE_HWP( l_errl, proc_a_x_pci_dmi_pll_setup, _args_...);
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
               "call_proc_a_x_pci_dmi_pll_setup exit" );

    // end task, returning any errorlogs to IStepDisp 
    task_end2( l_errl );
}



//
//  Wrapper function to call 07.2 :
//      proc_startclock_chiplets
//
void    call_proc_startclock_chiplets( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
               "call_proc_startclock_chiplets entry" );

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
    FAPI_INVOKE_HWP( l_errl, proc_startclock_chiplets, _args_...);
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
               "call_proc_startclock_chiplets exit" );

    // end task, returning any errorlogs to IStepDisp 
    task_end2( l_errl );
}



//
//  Wrapper function to call 07.3 :
//      proc_chiplet_scominit
//
void    call_proc_chiplet_scominit( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
               "call_proc_chiplet_scominit entry" );

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
    FAPI_INVOKE_HWP( l_errl, proc_chiplet_scominit, _args_...);
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
               "call_proc_chiplet_scominit exit" );

    // end task, returning any errorlogs to IStepDisp 
    task_end2( l_errl );
}



//
//  Wrapper function to call 07.4 :
//      proc_scomoverride_chiplets
//
void    call_proc_scomoverride_chiplets( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
               "call_proc_scomoverride_chiplets entry" );

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
    FAPI_INVOKE_HWP( l_errl, proc_scomoverride_chiplets, _args_...);
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
               "call_proc_scomoverride_chiplets exit" );

    // end task, returning any errorlogs to IStepDisp 
    task_end2( l_errl );
}


};   // end namespace
