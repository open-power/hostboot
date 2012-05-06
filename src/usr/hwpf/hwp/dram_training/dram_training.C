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
#include <targeting/common/commontargeting.H>
#include <targeting/common/util.H>

//  fapi support
#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>

// Run on all Centaurs/MBAs, but needs to keep this one handy in case we
// want to limit them in VPO
const uint8_t UNLIMITED_RUN = 0xFF;
const uint8_t VPO_NUM_OF_MBAS_TO_RUN = UNLIMITED_RUN;
const uint8_t VPO_NUM_OF_MEMBUF_TO_RUN = UNLIMITED_RUN;

//  --  prototype   includes    --
//  Add any customized routines that you don't want overwritten into
//      "dram_training_custom.C" and include the prototypes here.
//  #include    "dram_training_custom.H"

#include    "dram_training.H"

//  Un-comment these files as they become available:
// #include    "host_disable_vddr/host_disable_vddr.H"
// #include    "mc_pll_setup/mc_pll_setup.H"
#include    "mem_startclocks/cen_mem_startclocks.H"
// #include    "host_enable_vddr/host_enable_vddr.H"
// #include    "mss_initf/mss_initf.H"
#include    "mss_ddr_phy_reset/mss_ddr_phy_reset.H"
#include    "mss_draminit/mss_draminit.H"
// #include    "mss_restore_dram_repair/mss_restore_dram_repair.H"
#include    "mss_draminit_training/mss_draminit_training.H"
// #include    "mss_draminit_trainadv/mss_draminit_trainadv.H"
#include    "mss_draminit_mc/mss_draminit_mc.H"

namespace   DRAM_TRAINING
{

using   namespace   TARGETING;
using   namespace   fapi;

//
//  Wrapper function to call 13.1 : host_disable_vddr
//
void    call_host_disable_vddr( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_host_disable_vddr entry" );

#if 0
    // @@@@@    CUSTOM BLOCK:   @@@@@
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)

    //  print call to hwp and dump physical path of the target(s)
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
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
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS :  host_disable_vddr HWP(? ? ? )" );
    }
    else
    {
        /**
         * @todo fapi error - just print out for now...
         */
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR 0x%.8X:  host_disable_vddr HWP(? ? ?) ",
                static_cast<uint32_t>(l_fapirc) );
    }
    // @@@@@    END CUSTOM BLOCK:   @@@@@
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_host_disable_vddr exit" );

    task_end2( l_err );
}



//
//  Wrapper function to call 13.2 : mc_pll_setup
//
void    call_mc_pll_setup( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mc_pll_setup entry" );

#if 0
    // @@@@@    CUSTOM BLOCK:   @@@@@
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)

    //  print call to hwp and dump physical path of the target(s)
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
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
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS :  mc_pll_setup HWP(? ? ? )" );
    }
    else
    {
        /**
         * @todo fapi error - just print out for now...
         */
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR 0x%.8X:  mc_pll_setup HWP(? ? ?) ",
                static_cast<uint32_t>(l_fapirc) );
    }
    // @@@@@    END CUSTOM BLOCK:   @@@@@
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mc_pll_setup exit" );

    task_end2( l_err );
}



//
//  Wrapper function to call 13.3 : mem_startclocks
//
void    call_mem_startclocks( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mem_startclocks entry" );

    // Get all Centaur targets
    //  Use PredicateIsFunctional to filter only functional chips
    TARGETING::PredicateIsFunctional l_isFunctional;
    //  find all the Centaurs in the system
    TARGETING::PredicateCTM l_ctaurFilter(CLASS_CHIP, TYPE_MEMBUF);
    // declare a postfix expression widget
    TARGETING::PredicatePostfixExpr l_functionalAndCtaurFilter;
    //  is-a-membuf-chip  is-functional   AND
    l_functionalAndCtaurFilter.push(&l_ctaurFilter).push(&l_isFunctional).And();
    // loop through all the targets, applying the filter,  and put the results
    // in l_pMemBufs
    TARGETING::TargetRangeFilter    l_pMemBufs(
            TARGETING::targetService().begin(),
            TARGETING::targetService().end(),
            &l_functionalAndCtaurFilter );

    for ( ; l_pMemBufs ;  ++l_pMemBufs )
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target*  l_pCentaur = *l_pMemBufs;

        // Dump current run on target
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Running cen_mem_startclocks HWP on..." );
        EntityPath l_path;
        l_path  =   l_pCentaur->getAttr<ATTR_PHYS_PATH>();
        l_path.dump();

        // Cast to a FAPI type of target.
        const fapi::Target l_fapi_centaur(
                TARGET_TYPE_MEMBUF_CHIP,
                reinterpret_cast<void *>
                (const_cast<TARGETING::Target*>(l_pCentaur)) );

        //  call the HWP with each fapi::Target
        FAPI_INVOKE_HWP(l_err, cen_mem_startclocks, l_fapi_centaur);

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X: cen_mem_startclocks HWP returns error",
                      l_err->reasonCode());
            break;
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "SUCCESS :  cen_mem_startclocks HWP( )" );
        }
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mem_startclocks exit" );

    task_end2( l_err );
}



//
//  Wrapper function to call 13.4 : host_enable_vddr
//
void    call_host_enable_vddr( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_host_enable_vddr entry" );

#if 0
    // @@@@@    CUSTOM BLOCK:   @@@@@
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)

    //  print call to hwp and dump physical path of the target(s)
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
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
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS :  host_enable_vddr HWP(? ? ? )" );
    }
    else
    {
        /**
         * @todo fapi error - just print out for now...
         */
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR 0x%.8X:  host_enable_vddr HWP(? ? ?) ",
                static_cast<uint32_t>(l_fapirc) );
    }
    // @@@@@    END CUSTOM BLOCK:   @@@@@
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_host_enable_vddr exit" );

    task_end2( l_err );
}



//
//  Wrapper function to call 13.5 : mss_initf
//
void    call_mss_initf( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_initf entry" );

#if 0
    // @@@@@    CUSTOM BLOCK:   @@@@@
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)

    //  print call to hwp and dump physical path of the target(s)
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
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
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS :  mss_initf HWP(? ? ? )" );
    }
    else
    {
        /**
         * @todo fapi error - just print out for now...
         */
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR 0x%.8X:  mss_initf HWP(? ? ?) ",
                static_cast<uint32_t>(l_fapirc) );
    }
    // @@@@@    END CUSTOM BLOCK:   @@@@@
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_initf exit" );

    task_end2( l_err );
}

//
//  Wrapper function to call 13.6 : mss_ddr_phy_reset
//
void  call_mss_ddr_phy_reset( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_ddr_phy_reset entry" );

    // Get all MBA targets
    //  Use PredicateIsFunctional to filter only functional chips
    TARGETING::PredicateIsFunctional    l_isFunctional;
    //  find all the MBA's in the system
    TARGETING::PredicateCTM             l_mbaFilter(CLASS_UNIT, TYPE_MBA);
    // declare a postfix expression widget
    TARGETING::PredicatePostfixExpr l_functionalAndMbaFilter;
    //  is-a-membuf-chip  is-functional   AND
    l_functionalAndMbaFilter.push(&l_mbaFilter).push(&l_isFunctional).And();
    // loop through all the targets, applying the filter,  and put the results in l_pMemBufs
    TARGETING::TargetRangeFilter    l_pMbas(
            TARGETING::targetService().begin(),
            TARGETING::targetService().end(),
            &l_functionalAndMbaFilter );

    // Limit the number of MBAs to run in VPO environment to save time.
    uint8_t l_mbaLimit = UNLIMITED_RUN;
    if (TARGETING::is_vpo() )
    {
           l_mbaLimit = VPO_NUM_OF_MBAS_TO_RUN;
    }

    for (   uint8_t l_mbaNum=0 ;
            (l_mbaNum < l_mbaLimit) && l_pMbas ;
            l_mbaNum++, ++l_pMbas    )
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target*  l_mba_target = *l_pMbas;

        // Dump current run on target
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "Running call_mss_ddr_phy_reset HWP on..." );
        EntityPath l_path;
        l_path  =   l_mba_target->getAttr<ATTR_PHYS_PATH>();
        l_path.dump();

        // Cast to a FAPI type of target.
        const fapi::Target l_fapi_mba_target(
                TARGET_TYPE_MEMBUF_CHIP,
                reinterpret_cast<void *>
        (const_cast<TARGETING::Target*>(l_mba_target)) );

        //  call the HWP with each fapi::Target
        FAPI_INVOKE_HWP(l_err, mss_ddr_phy_reset, l_fapi_mba_target);

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "ERROR 0x%.8X: mss_ddr_phy_reset HWP returns error",
                    l_err->reasonCode());
            break; // break out of mba loop
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "SUCCESS :  call_mss_ddr_phy_reset HWP( )" );
        }
    } // end l_mbaNum loop

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_ddr_phy_reset exit" );

    task_end2( l_err );
}


//
//  Wrapper function to call 13.7 : mss_draminit
//
void    call_mss_draminit( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_draminit entry" );

    // Get all MBA targets
    //  Use PredicateIsFunctional to filter only functional chips
    TARGETING::PredicateIsFunctional    l_isFunctional;
    //  find all the MBA's in the system
    TARGETING::PredicateCTM             l_mbaFilter(CLASS_UNIT, TYPE_MBA);
    // declare a postfix expression widget
    TARGETING::PredicatePostfixExpr l_functionalAndMbaFilter;
    //  is-a-membuf-chip  is-functional   AND
    l_functionalAndMbaFilter.push(&l_mbaFilter).push(&l_isFunctional).And();
    // loop through all the targets, applying the filter,  and put the results in l_pMemBufs
    TARGETING::TargetRangeFilter    l_pMbas(
            TARGETING::targetService().begin(),
            TARGETING::targetService().end(),
            &l_functionalAndMbaFilter );

    // Limit the number of MBAs to run in VPO environment to save time.
    uint8_t l_mbaLimit = UNLIMITED_RUN;
    if (TARGETING::is_vpo() )
    {
           l_mbaLimit = VPO_NUM_OF_MBAS_TO_RUN;
    }

    for (   uint8_t l_mbaNum=0 ;
            (l_mbaNum < l_mbaLimit) && l_pMbas ;
            l_mbaNum++, ++l_pMbas    )
    {
        // Make a local copy of the target for ease of use
        const TARGETING::Target*  l_mba_target = *l_pMbas;

        // Dump current run on target
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "Running mss_draminit HWP on...");
        EntityPath l_path;
        l_path  =   l_mba_target->getAttr<ATTR_PHYS_PATH>();
        l_path.dump();

        // Cast to a FAPI type of target.
        const fapi::Target l_fapi_mba_target(
                TARGET_TYPE_MBA_CHIPLET,
                reinterpret_cast<void *>
                (const_cast<TARGETING::Target*>(l_mba_target)) );

        //  call the HWP with each fapi::Target
        FAPI_INVOKE_HWP(l_err, mss_draminit, l_fapi_mba_target);

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "ERROR 0x%.8X : mss_draminit HWP returns error",
                    l_err->reasonCode());
            break; // Break out of mba loop
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "SUCCESS :  mss_draminit HWP( )" );
        }

    }   // endfor   mba's

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_draminit exit" );

    task_end2( l_err );
}

//
//  Wrapper function to call 13.8 : mss_restore_dram_repair
//
void    call_mss_restore_dram_repair( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_restore_dram_repair entry" );

#if 0
    // @@@@@    CUSTOM BLOCK:   @@@@@
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)

    //  print call to hwp and dump physical path of the target(s)
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
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
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS :  mss_restore_dram_repair HWP(? ? ? )" );
    }
    else
    {
        /**
         * @todo fapi error - just print out for now...
         */
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR 0x%.8X:  mss_restore_dram_repair HWP(? ? ?) ",
                static_cast<uint32_t>(l_fapirc) );
    }
    // @@@@@    END CUSTOM BLOCK:   @@@@@
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_restore_dram_repair exit" );

    task_end2( l_err );
}



//
//  Wrapper function to call 13.9 : mss_draminit_training
//
void    call_mss_draminit_training( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_draminit_training entry" );

    // Get all MBA targets
    //  Use PredicateIsFunctional to filter only functional chips
    TARGETING::PredicateIsFunctional    l_isFunctional;
    //  find all the MBA's in the system
    TARGETING::PredicateCTM             l_mbaFilter(CLASS_UNIT, TYPE_MBA);
    // declare a postfix expression widget
    TARGETING::PredicatePostfixExpr l_functionalAndMbaFilter;
    //  is-a-membuf-chip  is-functional   AND
    l_functionalAndMbaFilter.push(&l_mbaFilter).push(&l_isFunctional).And();
    // loop through all the targets, applying the filter,  and put the results in l_pMemBufs
    TARGETING::TargetRangeFilter    l_pMbas(
            TARGETING::targetService().begin(),
            TARGETING::targetService().end(),
            &l_functionalAndMbaFilter );

    // Limit the number of MBAs to run in VPO environment to save time.
    uint8_t l_mbaLimit = UNLIMITED_RUN;
    if (TARGETING::is_vpo() )
    {
           l_mbaLimit = VPO_NUM_OF_MBAS_TO_RUN;
    }

    for (   uint8_t l_mbaNum=0 ;
            (l_mbaNum < l_mbaLimit) && l_pMbas ;
            l_mbaNum++, ++l_pMbas    )
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target*  l_mba_target = *l_pMbas;

        // Dump current run on target
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "Running mss_draminit_training HWP on..." );
        EntityPath l_path;
        l_path  =   l_mba_target->getAttr<ATTR_PHYS_PATH>();
        l_path.dump();

        // Cast to a FAPI type of target.
        const fapi::Target l_fapi_mba_target(
                TARGET_TYPE_MEMBUF_CHIP,
                reinterpret_cast<void *>
        (const_cast<TARGETING::Target*>(l_mba_target)) );


        //  call the HWP with each fapi::Target
        FAPI_INVOKE_HWP(l_err, mss_draminit_training, l_fapi_mba_target);

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "ERROR 0x%.8X : mss_draminit_training HWP returns error",
                    l_err->reasonCode());
            break; // break out of mba loop
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "SUCCESS :  mss_draminit_training HWP( )" );
        }

    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_draminit_training exit" );

    task_end2( l_err );
}

//
//  Wrapper function to call 13.10 : mss_draminit_trainadv
//
void    call_mss_draminit_trainadv( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_draminit_trainadv entry" );

#if 0
    // @@@@@    CUSTOM BLOCK:   @@@@@
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)

    //  print call to hwp and dump physical path of the target(s)
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
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
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS :  mss_draminit_trainadv HWP(? ? ? )" );
    }
    else
    {
        /**
         * @todo fapi error - just print out for now...
         */
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR 0x%.8X:  mss_draminit_trainadv HWP(? ? ?) ",
                static_cast<uint32_t>(l_fapirc) );
    }
    // @@@@@    END CUSTOM BLOCK:   @@@@@
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_draminit_trainadv exit" );

    task_end2( l_err );
}

//
//  Wrapper function to call 13.11 : mss_draminit_mc
//
void    call_mss_draminit_mc( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_draminit_mc entry" );

    // Get all centaur targets
    //  Use PredicateIsFunctional to filter only functional chips
    TARGETING::PredicateIsFunctional             l_isFunctional;
    //  filter for functional Centaur Chips
    TARGETING::PredicateCTM l_membufChipFilter(CLASS_CHIP, TYPE_MEMBUF);
    // declare a postfix expression widget
    TARGETING::PredicatePostfixExpr l_functionalAndMembufChipFilter;
    //  is-a-membuf-chip  is-functional   AND
    l_functionalAndMembufChipFilter.push(&l_membufChipFilter).push(&l_isFunctional).And();
    // loop through all the targets, applying the filter,  and put the results in l_pMemBufs
    TARGETING::TargetRangeFilter    l_pMemBufs(
            TARGETING::targetService().begin(),
            TARGETING::targetService().end(),
            &l_functionalAndMembufChipFilter );

    // Limit the number of MBAs to run in VPO environment to save time.
    uint8_t l_memBufLimit = UNLIMITED_RUN;
    if (TARGETING::is_vpo() )
    {
        l_memBufLimit = VPO_NUM_OF_MEMBUF_TO_RUN ;
    }

    for (uint8_t l_memBufNum=0 ;
            (l_memBufNum < l_memBufLimit) && l_pMemBufs ;
            l_memBufNum++, ++l_pMemBufs)
    {

        const TARGETING::Target*  l_membuf_target = *l_pMemBufs;

        // Dump current run on target
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "Running mss_draminit_mc HWP on..." );
        EntityPath l_path;
        l_path  =   l_membuf_target->getAttr<ATTR_PHYS_PATH>();
        l_path.dump();

        // Cast to a fapi target
        fapi::Target l_fapi_membuf_target(
                TARGET_TYPE_MEMBUF_CHIP,
                reinterpret_cast<void *>
                (const_cast<TARGETING::Target*>(l_membuf_target)) );

        //  call the HWP with each fapi::Target
        FAPI_INVOKE_HWP(l_err, mss_draminit_mc, l_fapi_membuf_target);

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "ERROR 0x%.8X : mss_draminit_mc HWP returns error",
                    l_err->reasonCode());
            break; // break out of memBuf loop
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "SUCCESS :  mss_draminit_mc HWP( )" );
        }

    } // End memBuf loop

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_draminit_mc exit" );

    task_end2( l_err );
}


};   // end namespace
