//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/hwp/mc_init/mc_init.C $
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
 *  @file mc_init.C
 *
 *  Support file for IStep: mc_init
 *   Step 12 MC Init
 *
 *  *****************************************************************
 *  THIS FILE WAS GENERATED ON 2012-03-01:1032
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
#include    <targeting/predicates/predicates.H>

//  fapi support
#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>


//  --  prototype   includes    --
//  Add any customized routines that you don't want overwritten into
//      "mc_init_custom.C" and include the prototypes here.
//  #include    "mc_init_custom.H"

#include    "mc_init.H"

//  Uncomment these files as they become available:
// #include    "host_collect_dimm_spd/host_collect_dimm_spd.H"
#include    "mss_volt/mss_volt.H"
#include    "mss_freq/mss_freq.H"
#include    "mss_eff_config/mss_eff_config_sim.H"

namespace   MC_INIT
{

using   namespace   TARGETING;
using   namespace   fapi;



//
//  Wrapper function to call 12.1 : host_collect_dimm_spd
//
void    call_host_collect_dimm_spd( void *io_pArgs )
{
    //  @todo   remove when join() merged
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );
    fapi::ReturnCode    l_fapirc;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_host_collect_dimm_spd entry" );

#if 0
    // @@@@@    CUSTOM BLOCK:   @@@@@
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)

    //  print call to hwp and dump physical path of the target(s)
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "=====  host_collect_dimm_spd HWP(? ? ? )",
            ?
                    ?
                            ? );
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
    l_fapirc  =   host_collect_dimm_spd( ? , ?, ? );

    //  process return code.
    if ( l_fapirc== fapi::FAPI_RC_SUCCESS )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS :  host_collect_dimm_spd HWP(? ? ? )" );
    }
    else
    {
        /**
         * @todo fapi error - just print out for now...
         */
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR %d:  host_collect_dimm_spd HWP(? ? ?) ",
                static_cast<uint32_t>(l_fapirc) );
    }
    // @@@@@    END CUSTOM BLOCK:   @@@@@
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_host_collect_dimm_spd exit" );

    //  end the task.
    pTaskArgs->waitChildSync();     // @todo remove when join() merged
    task_end();
}



//
//  Wrapper function to call 12.2 : mss_volt
//
void    call_mss_volt( void *io_pArgs )
{
    //  @todo   remove when join() merged
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );
    fapi::ReturnCode    l_fapirc;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_volt entry" );

    //  figure out what targets we need
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

    //  declare a vector of fapi targets to pass to mss_volt
    std::vector<fapi::Target> l_membufFapiTargets;

    //  fill in the vector
    for ( uint8_t l_membufNum=0  ;   l_pMemBufs ; l_membufNum++,  ++l_pMemBufs )
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target*  l_membuf_target = *l_pMemBufs;

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "=====  add to fapi::Target vector..." );
        EntityPath l_path;
        l_path  =   l_membuf_target->getAttr<ATTR_PHYS_PATH>();
        l_path.dump();

        fapi::Target l_membuf_fapi_target(
                TARGET_TYPE_MEMBUF_CHIP,
                reinterpret_cast<void *>
        (const_cast<TARGETING::Target*>(l_membuf_target)) );

        l_membufFapiTargets.push_back( l_membuf_fapi_target );

    }   // endfor


    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "=====  mss_volt HWP( vector )" );
    //  call the HWP with each target   ( if parallel, spin off a task )
    l_fapirc  =   mss_volt( l_membufFapiTargets );

    //  process return code.
    if ( l_fapirc== fapi::FAPI_RC_SUCCESS )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS :  mss_volt HWP( )" );
    }
    else
    {
        /**
         * @todo fapi error - just print out for now...
         */
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR %d:  mss_volt HWP( ) ",
                static_cast<uint32_t>(l_fapirc) );
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_volt exit" );

    //  end the task.
    pTaskArgs->waitChildSync();     // @todo remove when join() merged
    task_end();
}

//
//  Wrapper function to call 12.3 : mss_freq
//
void    call_mss_freq( void *io_pArgs )
{
    //  @todo   remove when join() merged
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );
    fapi::ReturnCode    l_fapirc;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_freq entry" );


    //  figure out what targets we need
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

    for ( uint8_t l_memBufNum=0 ;
            l_pMemBufs ;
            l_memBufNum++, ++l_pMemBufs
    )
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target*  l_membuf_target = *l_pMemBufs;

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "=====  mss_freq HWP( %d )",
                l_memBufNum );
        EntityPath l_path;
        l_path  =   l_membuf_target->getAttr<ATTR_PHYS_PATH>();
        l_path.dump();

        //  call the HWP with each target   ( if parallel, spin off a task )
        // $$const fapi::Target l_fapi_membuf_target(
        fapi::Target l_fapi_membuf_target(
                TARGET_TYPE_MEMBUF_CHIP,
                reinterpret_cast<void *>
        (const_cast<TARGETING::Target*>(l_membuf_target)) );

        l_fapirc  =   mss_freq( l_fapi_membuf_target );

        //  process return code.
        if ( l_fapirc== fapi::FAPI_RC_SUCCESS )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "SUCCESS :  mss_freq HWP( %d )", l_memBufNum );
        }
        else
        {
            /**
             * @todo fapi error - just print out for now...
             */
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR %d:  mss_freq HWP( %d ) ",
                    static_cast<uint32_t>(l_fapirc),
                    l_memBufNum );
        }
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_freq exit" );

    //  end the task.
    pTaskArgs->waitChildSync();     // @todo remove when join() merged
    task_end();
}



//
//  Wrapper function to call 12.4 : mss_eff_config
//
void    call_mss_eff_config( void *io_pArgs )
{
    //  @todo   remove when join() merged
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );
    fapi::ReturnCode    l_fapirc;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_eff_config entry" );


    //  Use PredicateIsFunctional to filter only functional chips
    TARGETING::PredicateIsFunctional             l_isFunctional;
    //  filter for functional Centaur Chips
    TARGETING::PredicateCTM l_mbaFilter(CLASS_UNIT, TYPE_MBA);
    // declare a postfix expression widget
    TARGETING::PredicatePostfixExpr l_functionalAndMbaFilter;
    //  is-a-membuf-chip  is-functional   AND
    l_functionalAndMbaFilter.push(&l_mbaFilter).push(&l_isFunctional).And();
    // loop through all the targets, applying the filter,  and put the results in l_pMemBufs
    TARGETING::TargetRangeFilter    l_pMbas(
            TARGETING::targetService().begin(),
            TARGETING::targetService().end(),
            &l_functionalAndMbaFilter );

    for ( uint8_t l_mbaNum=0 ;
            l_pMbas ;
            l_mbaNum++, ++l_pMbas
    )
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target*  l_mba_target = *l_pMbas;

        //  print call to hwp and dump physical path of the target(s)
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "=====  mss_eff_config HWP( mba %d )",
                l_mbaNum );
        //  dump physical path to targets
        EntityPath l_path;
        l_path  =   l_mba_target->getAttr<ATTR_PHYS_PATH>();
        l_path.dump();


        // cast OUR type of target to a FAPI type of target.
        const fapi::Target l_fapi_mba_target(
                TARGET_TYPE_MBA_CHIPLET,
                reinterpret_cast<void *>
        (const_cast<TARGETING::Target*>(l_mba_target)) );

        //  call the HWP with each fapi::Target
        l_fapirc  =   mss_eff_config_sim( l_fapi_mba_target );

        //  process return code.
        if ( l_fapirc== fapi::FAPI_RC_SUCCESS )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "SUCCESS :  mss_eff_config HWP( mba %d )",
                    l_mbaNum );
        }
        else
        {
            /**
             * @todo fapi error - just print out for now...
             */
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR %d:  mss_eff_config HWP( mba %d ) ",
                    static_cast<uint32_t>(l_fapirc),
                    l_mbaNum );
        }
    }   // endfor


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_eff_config exit" );

    //  end the task.
    pTaskArgs->waitChildSync();     // @todo remove when join() merged
    task_end();
}


};   // end namespace
