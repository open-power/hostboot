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
 *  Support file for IStep:
 *      mc_init

 */


/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

// #include    <kernel/console.H>
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
#include    "mc_init.H"
//  #include    "mss_volt/mss_volt.H"
#include    "mss_freq/mss_freq.H"

namespace  MC_INIT
{

using   namespace   TARGETING;
using   namespace   fapi;

//
//  Wrapper function to call 12.1 : mss_volt
//
void    call_host_collect_dimm_spd( void *io_pArgs )
{
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );
    fapi::ReturnCode    l_fapirc;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_host_collect_dimm_spd" );


    //  figure out what targets we need
    //  ADD TARGET CODE HERE
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "=====  host_collect_dimm_spd(? ? ? )" );
#if 0
    //  call the HWP with each target   ( if parallel, spin off a task )
    l_fapirc  =   host_collect_dimm_spd( ? , ?, ? );
#endif

    //  process return code.
    if ( l_fapirc== fapi::FAPI_RC_SUCCESS )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS :  host_collect_dimm_spd(? ? ? )" );
    }
    else
    {
        /**
         * @todo fapi error - just print out for now...
         */
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR %d:  host_collect_dimm_spd(? ? ?) ",
                static_cast<uint32_t>(l_fapirc) );
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_collect_dimm_spd" );

    //  wait here on the barrier, then end the task.
    pTaskArgs->waitChildSync();
    task_end();
}

//
//  Wrapper function to call 12.2 : mss_volt
//
void    call_mss_volt( void *io_pArgs )
{
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );
    fapi::ReturnCode    l_fapirc;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_volt entry" );


    //  figure out what targets we need
    //  ADD TARGET CODE HERE

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "=====  mss_volt HWP(? ? ? )" );
#if 0
    //  call the HWP with each target   ( if parallel, spin off a task )
    l_fapirc  =   mss_volt( ? , ?, ? );
#endif

    //  process return code.
    if ( l_fapirc== fapi::FAPI_RC_SUCCESS )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS :  mss_volt HWP(? ? ? )" );
    }
    else
    {
        /**
         * @todo fapi error - just print out for now...
         */
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR %d:  mss_volt HWP(? ? ?) ",
                static_cast<uint32_t>(l_fapirc) );
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "mss_volt exit" );

    //  wait here on the barrier, then end the task.
    pTaskArgs->waitChildSync();
    task_end();
}

//
//  Wrapper function to call 12.3 : mss_freq
//
void    call_mss_freq( void *io_pArgs )
{
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
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "===== " );

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

    //  wait here on the barrier, then end the task.
    pTaskArgs->waitChildSync();
    task_end();
}


//
//  Wrapper function to call 12.4 : mss_eff_config
//
void    call_mss_eff_config( void *io_pArgs )
{
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );
    fapi::ReturnCode    l_fapirc;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_eff_config" );


    //  figure out what targets we need
    //  ADD TARGET CODE HERE

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "=====  mss_eff_config HWP(? ? ? )" );
#if 0
    //  call the HWP with each target   ( if parallel, spin off a task )
    l_fapirc  =   mss_eff_config( ? , ?, ? );
#endif

    //  process return code.
    if ( l_fapirc== fapi::FAPI_RC_SUCCESS )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS :  mss_eff_config HWP(? ? ? )" );
    }
    else
    {
        /**
         * @todo fapi error - just print out for now...
         */
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR %d:  mss_eff_config HWP(? ? ?) ",
                static_cast<uint32_t>(l_fapirc) );
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_eff_config exit" );

    //  wait here on the barrier, then end the task.
    pTaskArgs->waitChildSync();
    task_end();
}


};   // end namespace

