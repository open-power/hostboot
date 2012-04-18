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
 *  THIS FILE WAS GENERATED ON 2012-04-03:1952
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
#include    <targeting/common/commontargeting.H>

//  fapi support
#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>

//  --  prototype   includes    --
//  Add any customized routines that you don't want overwritten into
//      "start_clocks_on_nest_chiplets_custom.C" and include the prototypes here.
//  #include    "start_clocks_on_nest_chiplets_custom.H"
#include    "start_clocks_on_nest_chiplets.H"
#include    "proc_start_clocks_chiplets/proc_start_clocks_chiplets.H"

//  Uncomment these files as they become available:
// #include    "proc_a_x_pci_dmi_pll_setup/proc_a_x_pci_dmi_pll_setup.H"
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
    errlHndl_t          l_errl      =   NULL;  

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_proc_a_x_pci_dmi_pll_setup entry" );
        
#if 0
    // @@@@@    CUSTOM BLOCK:   @@@@@    
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)
    
    //  print call to hwp and dump physical path of the target(s)
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "=====  proc_a_x_pci_dmi_pll_setup HWP(? ? ? )",
                    ?
                    ?
                    ? );
    //  dump physical path to targets
    EntityPath l_path;
    l_path  =   l_@targetN_target->getAttr<ATTR_PHYS_PATH>();
    l_path.dump();
    TRACFCOMP( g_trac_mc_init, "===== " );   

    // cast OUR type of target to a FAPI type of target.                         
    const fapi::Target l_fapi_@targetN_target(
                    TARGET_TYPE_MEMBUF_CHIP,
                    reinterpret_cast<void *>
                        (const_cast<TARGETING::Target*>(l_@targetN_target)) );
                    
    //  call the HWP with each fapi::Target
    l_fapirc  =   proc_a_x_pci_dmi_pll_setup( ? , ?, ? );

    //  process return code.
    if ( l_fapirc== fapi::FAPI_RC_SUCCESS )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS :  proc_a_x_pci_dmi_pll_setup HWP(? ? ? )" );
    }
    else
    {
        /**
         * @todo fapi error - just print out for now...
         */
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR 0x%.8X:  proc_a_x_pci_dmi_pll_setup HWP(? ? ?) ",
                static_cast<uint32_t>(l_fapirc) );
    }
    // @@@@@    END CUSTOM BLOCK:   @@@@@    
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_proc_a_x_pci_dmi_pll_setup exit" );

    // end task, returning any errorlogs to IStepDisp 
    task_end2( l_errl );
}



//
//  Wrapper function to call 07.2 :
//      proc_startclock_chiplets
//
void    call_proc_startclock_chiplets( void    *io_pArgs )
{
    errlHndl_t l_err =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_proc_startclock_chiplets entry" );
        
    TARGETING::TargetService&   l_targetService = targetService();
    uint8_t l_cpuNum = 0;

    //  Use PredicateIsFunctional to filter only functional chips
    TARGETING::PredicateIsFunctional             l_isFunctional;
    //  filter for functional Proc Chips
    TARGETING::PredicateCTM         l_procChipFilter( CLASS_CHIP, TYPE_PROC );
    TARGETING::PredicatePostfixExpr l_functionalAndProcChipFilter;
    l_functionalAndProcChipFilter.push(&l_procChipFilter).push(&l_isFunctional).And();
    TARGETING::TargetRangeFilter    l_cpuFilter(
            l_targetService.begin(),
            l_targetService.end(),
            &l_functionalAndProcChipFilter );

    for ( l_cpuNum=0;   l_cpuFilter;    ++l_cpuFilter, l_cpuNum++ )
    {
        const TARGETING::Target*  l_cpu_target = *l_cpuFilter;
        const fapi::Target l_fapi_proc_target(
                TARGET_TYPE_PROC_CHIP,
                reinterpret_cast<void *>
                ( const_cast<TARGETING::Target*>(l_cpu_target) )
        );

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "Running proc_startclock_chiplets HWP on..." );
        //  dump physical path to targets
        EntityPath l_path;
        l_path  =   l_cpu_target->getAttr<ATTR_PHYS_PATH>();
        l_path.dump();

        //  call the HWP with each fapi::Target
        FAPI_INVOKE_HWP(l_err, proc_start_clocks_chiplets,
                        l_fapi_proc_target,
                        true,   // xbus
                        true,   // abus
                        true);  // pcie
        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "ERROR 0x%.8X : proc_startclock_chiplets HWP returns error",
                    l_err->reasonCode());
            break; // break out of cpuNum
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "SUCCESS :  proc_startclock_chiplets HWP( )" );
        }
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_proc_startclock_chiplets exit" );

    // end task, returning any errorlogs to IStepDisp 
    task_end2( l_err );
}


//
//  Wrapper function to call 07.3 :
//      proc_chiplet_scominit
//
void    call_proc_chiplet_scominit( void    *io_pArgs )
{
    errlHndl_t          l_errl      =   NULL;  

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_proc_chiplet_scominit entry" );
        
#if 0
    // @@@@@    CUSTOM BLOCK:   @@@@@    
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)
    
    //  print call to hwp and dump physical path of the target(s)
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "=====  proc_chiplet_scominit HWP(? ? ? )",
                    ?
                    ?
                    ? );
    //  dump physical path to targets
    EntityPath l_path;
    l_path  =   l_@targetN_target->getAttr<ATTR_PHYS_PATH>();
    l_path.dump();
    TRACFCOMP( g_trac_mc_init, "===== " );   

    // cast OUR type of target to a FAPI type of target.                         
    const fapi::Target l_fapi_@targetN_target(
                    TARGET_TYPE_MEMBUF_CHIP,
                    reinterpret_cast<void *>
                        (const_cast<TARGETING::Target*>(l_@targetN_target)) );
                    
    //  call the HWP with each fapi::Target
    l_fapirc  =   proc_chiplet_scominit( ? , ?, ? );

    //  process return code.
    if ( l_fapirc== fapi::FAPI_RC_SUCCESS )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS :  proc_chiplet_scominit HWP(? ? ? )" );
    }
    else
    {
        /**
         * @todo fapi error - just print out for now...
         */
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR 0x%.8X:  proc_chiplet_scominit HWP(? ? ?) ",
                static_cast<uint32_t>(l_fapirc) );
    }
    // @@@@@    END CUSTOM BLOCK:   @@@@@    
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_proc_chiplet_scominit exit" );

    // end task, returning any errorlogs to IStepDisp 
    task_end2( l_errl );
}



//
//  Wrapper function to call 07.4 :
//      proc_scomoverride_chiplets
//
void    call_proc_scomoverride_chiplets( void    *io_pArgs )
{
    errlHndl_t          l_errl      =   NULL;  

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_proc_scomoverride_chiplets entry" );
        
#if 0
    // @@@@@    CUSTOM BLOCK:   @@@@@    
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)
    
    //  print call to hwp and dump physical path of the target(s)
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "=====  proc_scomoverride_chiplets HWP(? ? ? )",
                    ?
                    ?
                    ? );
    //  dump physical path to targets
    EntityPath l_path;
    l_path  =   l_@targetN_target->getAttr<ATTR_PHYS_PATH>();
    l_path.dump();
    TRACFCOMP( g_trac_mc_init, "===== " );   

    // cast OUR type of target to a FAPI type of target.                         
    const fapi::Target l_fapi_@targetN_target(
                    TARGET_TYPE_MEMBUF_CHIP,
                    reinterpret_cast<void *>
                        (const_cast<TARGETING::Target*>(l_@targetN_target)) );
                    
    //  call the HWP with each fapi::Target
    l_fapirc  =   proc_scomoverride_chiplets( ? , ?, ? );

    //  process return code.
    if ( l_fapirc== fapi::FAPI_RC_SUCCESS )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS :  proc_scomoverride_chiplets HWP(? ? ? )" );
    }
    else
    {
        /**
         * @todo fapi error - just print out for now...
         */
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR 0x%.8X:  proc_scomoverride_chiplets HWP(? ? ?) ",
                static_cast<uint32_t>(l_fapirc) );
    }
    // @@@@@    END CUSTOM BLOCK:   @@@@@    
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_proc_scomoverride_chiplets exit" );

    // end task, returning any errorlogs to IStepDisp 
    task_end2( l_errl );
}


};   // end namespace
