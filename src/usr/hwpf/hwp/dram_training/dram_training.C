//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/hwp/dram_training/dram_training.C $
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
 *  @file dram_training.C                                                
 *
 *  Support file for IStep: dram_training                                                    
 *   Step 13 DRAM Training
 *
 *  *****************************************************************
 *  THIS FILE WAS GENERATED ON 2012-02-27:2142
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


//  --  prototype   includes    --
//  Add any customized routines that you don't want overwritten into
//      "dram_training_custom.C" and include the prototypes here.
//  #include    "dram_training_custom.H"

#include    "dram_training.H"          
                                  
//  Uncomment these files as they become available:
// #include    "host_disable_vddr/host_disable_vddr.H"
// #include    "mc_pll_setup/mc_pll_setup.H"
// #include    "mba_startclocks/mba_startclocks.H"
// #include    "host_enable_vddr/host_enable_vddr.H"
// #include    "mss_initf/mss_initf.H"
// #include    "mss_ddr_phy_reset/mss_ddr_phy_reset.H"
// #include    "mss_draminit/mss_draminit.H"
// #include    "mss_restore_dram_repair/mss_restore_dram_repair.H"
// #include    "mss_draminit_training/mss_draminit_training.H"
// #include    "mss_draminit_trainadv/mss_draminit_trainadv.H"
// #include    "mss_draminit_mc/mss_draminit_mc.H"

namespace   DRAM_TRAINING                                              
{

using   namespace   TARGETING;
using   namespace   fapi;



//
//  Wrapper function to call 13.1 : host_disable_vddr
//
void    call_host_disable_vddr( void *io_pArgs )
{
    //  @todo   remove when join() merged
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );
    fapi::ReturnCode    l_fapirc;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_host_disable_vddr entry" );
        
#if 0
    // @@@@@    CUSTOM BLOCK:   @@@@@    
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)
    
    //  print call to hwp and dump physical path of the target(s)
    TRACFCOMP( ISTEPS_TRACE::ISTEPS_TRACE::g_trac_isteps_traces_trace,
                    "=====  host_disable_vddr HWP(? ? ? )",
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
    l_fapirc  =   host_disable_vddr( ? , ?, ? );

    //  process return code.
    if ( l_fapirc== fapi::FAPI_RC_SUCCESS )
    {
        TRACFCOMP( ISTEPS_TRACE::ISTEPS_TRACE::g_trac_isteps_traces_trace,
                "SUCCESS :  host_disable_vddr HWP(? ? ? )" );
    }
    else
    {
        /**
         * @todo fapi error - just print out for now...
         */
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR %d:  host_disable_vddr HWP(? ? ?) ",
                static_cast<uint32_t>(l_fapirc) );
    }
    // @@@@@    END CUSTOM BLOCK:   @@@@@    
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_host_disable_vddr exit" );

    //  end the task.
    pTaskArgs->waitChildSync();     // @todo remove when join() merged
    task_end();
}



//
//  Wrapper function to call 13.2 : mc_pll_setup
//
void    call_mc_pll_setup( void *io_pArgs )
{
    //  @todo   remove when join() merged
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );
    fapi::ReturnCode    l_fapirc;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mc_pll_setup entry" );
        
#if 0
    // @@@@@    CUSTOM BLOCK:   @@@@@    
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)
    
    //  print call to hwp and dump physical path of the target(s)
    TRACFCOMP( ISTEPS_TRACE::ISTEPS_TRACE::g_trac_isteps_traces_trace,
                    "=====  mc_pll_setup HWP(? ? ? )",
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
    l_fapirc  =   mc_pll_setup( ? , ?, ? );

    //  process return code.
    if ( l_fapirc== fapi::FAPI_RC_SUCCESS )
    {
        TRACFCOMP( ISTEPS_TRACE::ISTEPS_TRACE::g_trac_isteps_traces_trace,
                "SUCCESS :  mc_pll_setup HWP(? ? ? )" );
    }
    else
    {
        /**
         * @todo fapi error - just print out for now...
         */
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR %d:  mc_pll_setup HWP(? ? ?) ",
                static_cast<uint32_t>(l_fapirc) );
    }
    // @@@@@    END CUSTOM BLOCK:   @@@@@    
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mc_pll_setup exit" );

    //  end the task.
    pTaskArgs->waitChildSync();     // @todo remove when join() merged
    task_end();
}



//
//  Wrapper function to call 13.3 : mba_startclocks
//
void    call_mba_startclocks( void *io_pArgs )
{
    //  @todo   remove when join() merged
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );
    fapi::ReturnCode    l_fapirc;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mba_startclocks entry" );
        
#if 0
    // @@@@@    CUSTOM BLOCK:   @@@@@    
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)
    
    //  print call to hwp and dump physical path of the target(s)
    TRACFCOMP( ISTEPS_TRACE::ISTEPS_TRACE::g_trac_isteps_traces_trace,
                    "=====  mba_startclocks HWP(? ? ? )",
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
    l_fapirc  =   mba_startclocks( ? , ?, ? );

    //  process return code.
    if ( l_fapirc== fapi::FAPI_RC_SUCCESS )
    {
        TRACFCOMP( ISTEPS_TRACE::ISTEPS_TRACE::g_trac_isteps_traces_trace,
                "SUCCESS :  mba_startclocks HWP(? ? ? )" );
    }
    else
    {
        /**
         * @todo fapi error - just print out for now...
         */
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR %d:  mba_startclocks HWP(? ? ?) ",
                static_cast<uint32_t>(l_fapirc) );
    }
    // @@@@@    END CUSTOM BLOCK:   @@@@@    
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mba_startclocks exit" );

    //  end the task.
    pTaskArgs->waitChildSync();     // @todo remove when join() merged
    task_end();
}



//
//  Wrapper function to call 13.4 : host_enable_vddr
//
void    call_host_enable_vddr( void *io_pArgs )
{
    //  @todo   remove when join() merged
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );
    fapi::ReturnCode    l_fapirc;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_host_enable_vddr entry" );
        
#if 0
    // @@@@@    CUSTOM BLOCK:   @@@@@    
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)
    
    //  print call to hwp and dump physical path of the target(s)
    TRACFCOMP( ISTEPS_TRACE::ISTEPS_TRACE::g_trac_isteps_traces_trace,
                    "=====  host_enable_vddr HWP(? ? ? )",
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
    l_fapirc  =   host_enable_vddr( ? , ?, ? );

    //  process return code.
    if ( l_fapirc== fapi::FAPI_RC_SUCCESS )
    {
        TRACFCOMP( ISTEPS_TRACE::ISTEPS_TRACE::g_trac_isteps_traces_trace,
                "SUCCESS :  host_enable_vddr HWP(? ? ? )" );
    }
    else
    {
        /**
         * @todo fapi error - just print out for now...
         */
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR %d:  host_enable_vddr HWP(? ? ?) ",
                static_cast<uint32_t>(l_fapirc) );
    }
    // @@@@@    END CUSTOM BLOCK:   @@@@@    
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_host_enable_vddr exit" );

    //  end the task.
    pTaskArgs->waitChildSync();     // @todo remove when join() merged
    task_end();
}



//
//  Wrapper function to call 13.5 : mss_initf
//
void    call_mss_initf( void *io_pArgs )
{
    //  @todo   remove when join() merged
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );
    fapi::ReturnCode    l_fapirc;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_initf entry" );
        
#if 0
    // @@@@@    CUSTOM BLOCK:   @@@@@    
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)
    
    //  print call to hwp and dump physical path of the target(s)
    TRACFCOMP( ISTEPS_TRACE::ISTEPS_TRACE::g_trac_isteps_traces_trace,
                    "=====  mss_initf HWP(? ? ? )",
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
    l_fapirc  =   mss_initf( ? , ?, ? );

    //  process return code.
    if ( l_fapirc== fapi::FAPI_RC_SUCCESS )
    {
        TRACFCOMP( ISTEPS_TRACE::ISTEPS_TRACE::g_trac_isteps_traces_trace,
                "SUCCESS :  mss_initf HWP(? ? ? )" );
    }
    else
    {
        /**
         * @todo fapi error - just print out for now...
         */
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR %d:  mss_initf HWP(? ? ?) ",
                static_cast<uint32_t>(l_fapirc) );
    }
    // @@@@@    END CUSTOM BLOCK:   @@@@@    
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_initf exit" );

    //  end the task.
    pTaskArgs->waitChildSync();     // @todo remove when join() merged
    task_end();
}



//
//  Wrapper function to call 13.6 : mss_ddr_phy_reset
//
void    call_mss_ddr_phy_reset( void *io_pArgs )
{
    //  @todo   remove when join() merged
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );
    fapi::ReturnCode    l_fapirc;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_ddr_phy_reset entry" );
        
#if 0
    // @@@@@    CUSTOM BLOCK:   @@@@@    
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)
    
    //  print call to hwp and dump physical path of the target(s)
    TRACFCOMP( ISTEPS_TRACE::ISTEPS_TRACE::g_trac_isteps_traces_trace,
                    "=====  mss_ddr_phy_reset HWP(? ? ? )",
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
    l_fapirc  =   mss_ddr_phy_reset( ? , ?, ? );

    //  process return code.
    if ( l_fapirc== fapi::FAPI_RC_SUCCESS )
    {
        TRACFCOMP( ISTEPS_TRACE::ISTEPS_TRACE::g_trac_isteps_traces_trace,
                "SUCCESS :  mss_ddr_phy_reset HWP(? ? ? )" );
    }
    else
    {
        /**
         * @todo fapi error - just print out for now...
         */
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR %d:  mss_ddr_phy_reset HWP(? ? ?) ",
                static_cast<uint32_t>(l_fapirc) );
    }
    // @@@@@    END CUSTOM BLOCK:   @@@@@    
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_ddr_phy_reset exit" );

    //  end the task.
    pTaskArgs->waitChildSync();     // @todo remove when join() merged
    task_end();
}



//
//  Wrapper function to call 13.7 : mss_draminit
//
void    call_mss_draminit( void *io_pArgs )
{
    //  @todo   remove when join() merged
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );
    fapi::ReturnCode    l_fapirc;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_draminit entry" );
        
#if 0
    // @@@@@    CUSTOM BLOCK:   @@@@@    
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)
    
    //  print call to hwp and dump physical path of the target(s)
    TRACFCOMP( ISTEPS_TRACE::ISTEPS_TRACE::g_trac_isteps_traces_trace,
                    "=====  mss_draminit HWP(? ? ? )",
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
    l_fapirc  =   mss_draminit( ? , ?, ? );

    //  process return code.
    if ( l_fapirc== fapi::FAPI_RC_SUCCESS )
    {
        TRACFCOMP( ISTEPS_TRACE::ISTEPS_TRACE::g_trac_isteps_traces_trace,
                "SUCCESS :  mss_draminit HWP(? ? ? )" );
    }
    else
    {
        /**
         * @todo fapi error - just print out for now...
         */
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR %d:  mss_draminit HWP(? ? ?) ",
                static_cast<uint32_t>(l_fapirc) );
    }
    // @@@@@    END CUSTOM BLOCK:   @@@@@    
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_draminit exit" );

    //  end the task.
    pTaskArgs->waitChildSync();     // @todo remove when join() merged
    task_end();
}



//
//  Wrapper function to call 13.8 : mss_restore_dram_repair
//
void    call_mss_restore_dram_repair( void *io_pArgs )
{
    //  @todo   remove when join() merged
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );
    fapi::ReturnCode    l_fapirc;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_restore_dram_repair entry" );
        
#if 0
    // @@@@@    CUSTOM BLOCK:   @@@@@    
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)
    
    //  print call to hwp and dump physical path of the target(s)
    TRACFCOMP( ISTEPS_TRACE::ISTEPS_TRACE::g_trac_isteps_traces_trace,
                    "=====  mss_restore_dram_repair HWP(? ? ? )",
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
    l_fapirc  =   mss_restore_dram_repair( ? , ?, ? );

    //  process return code.
    if ( l_fapirc== fapi::FAPI_RC_SUCCESS )
    {
        TRACFCOMP( ISTEPS_TRACE::ISTEPS_TRACE::g_trac_isteps_traces_trace,
                "SUCCESS :  mss_restore_dram_repair HWP(? ? ? )" );
    }
    else
    {
        /**
         * @todo fapi error - just print out for now...
         */
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR %d:  mss_restore_dram_repair HWP(? ? ?) ",
                static_cast<uint32_t>(l_fapirc) );
    }
    // @@@@@    END CUSTOM BLOCK:   @@@@@    
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_restore_dram_repair exit" );

    //  end the task.
    pTaskArgs->waitChildSync();     // @todo remove when join() merged
    task_end();
}



//
//  Wrapper function to call 13.9 : mss_draminit_training
//
void    call_mss_draminit_training( void *io_pArgs )
{
    //  @todo   remove when join() merged
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );
    fapi::ReturnCode    l_fapirc;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_draminit_training entry" );
        
#if 0
    // @@@@@    CUSTOM BLOCK:   @@@@@    
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)
    
    //  print call to hwp and dump physical path of the target(s)
    TRACFCOMP( ISTEPS_TRACE::ISTEPS_TRACE::g_trac_isteps_traces_trace,
                    "=====  mss_draminit_training HWP(? ? ? )",
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
    l_fapirc  =   mss_draminit_training( ? , ?, ? );

    //  process return code.
    if ( l_fapirc== fapi::FAPI_RC_SUCCESS )
    {
        TRACFCOMP( ISTEPS_TRACE::ISTEPS_TRACE::g_trac_isteps_traces_trace,
                "SUCCESS :  mss_draminit_training HWP(? ? ? )" );
    }
    else
    {
        /**
         * @todo fapi error - just print out for now...
         */
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR %d:  mss_draminit_training HWP(? ? ?) ",
                static_cast<uint32_t>(l_fapirc) );
    }
    // @@@@@    END CUSTOM BLOCK:   @@@@@    
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_draminit_training exit" );

    //  end the task.
    pTaskArgs->waitChildSync();     // @todo remove when join() merged
    task_end();
}



//
//  Wrapper function to call 13.10 : mss_draminit_trainadv
//
void    call_mss_draminit_trainadv( void *io_pArgs )
{
    //  @todo   remove when join() merged
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );
    fapi::ReturnCode    l_fapirc;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_draminit_trainadv entry" );
        
#if 0
    // @@@@@    CUSTOM BLOCK:   @@@@@    
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)
    
    //  print call to hwp and dump physical path of the target(s)
    TRACFCOMP( ISTEPS_TRACE::ISTEPS_TRACE::g_trac_isteps_traces_trace,
                    "=====  mss_draminit_trainadv HWP(? ? ? )",
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
    l_fapirc  =   mss_draminit_trainadv( ? , ?, ? );

    //  process return code.
    if ( l_fapirc== fapi::FAPI_RC_SUCCESS )
    {
        TRACFCOMP( ISTEPS_TRACE::ISTEPS_TRACE::g_trac_isteps_traces_trace,
                "SUCCESS :  mss_draminit_trainadv HWP(? ? ? )" );
    }
    else
    {
        /**
         * @todo fapi error - just print out for now...
         */
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR %d:  mss_draminit_trainadv HWP(? ? ?) ",
                static_cast<uint32_t>(l_fapirc) );
    }
    // @@@@@    END CUSTOM BLOCK:   @@@@@    
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_draminit_trainadv exit" );

    //  end the task.
    pTaskArgs->waitChildSync();     // @todo remove when join() merged
    task_end();
}



//
//  Wrapper function to call 13.11 : mss_draminit_mc
//
void    call_mss_draminit_mc( void *io_pArgs )
{
    //  @todo   remove when join() merged
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );
    fapi::ReturnCode    l_fapirc;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_draminit_mc entry" );
        
#if 0
    // @@@@@    CUSTOM BLOCK:   @@@@@    
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)
    
    //  print call to hwp and dump physical path of the target(s)
    TRACFCOMP( ISTEPS_TRACE::ISTEPS_TRACE::g_trac_isteps_traces_trace,
                    "=====  mss_draminit_mc HWP(? ? ? )",
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
    l_fapirc  =   mss_draminit_mc( ? , ?, ? );

    //  process return code.
    if ( l_fapirc== fapi::FAPI_RC_SUCCESS )
    {
        TRACFCOMP( ISTEPS_TRACE::ISTEPS_TRACE::g_trac_isteps_traces_trace,
                "SUCCESS :  mss_draminit_mc HWP(? ? ? )" );
    }
    else
    {
        /**
         * @todo fapi error - just print out for now...
         */
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR %d:  mss_draminit_mc HWP(? ? ?) ",
                static_cast<uint32_t>(l_fapirc) );
    }
    // @@@@@    END CUSTOM BLOCK:   @@@@@    
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_draminit_mc exit" );

    //  end the task.
    pTaskArgs->waitChildSync();     // @todo remove when join() merged
    task_end();
}


};   // end namespace
