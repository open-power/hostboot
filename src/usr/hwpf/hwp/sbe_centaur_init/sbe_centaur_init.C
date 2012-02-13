//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/hwp/sbe_centaur_init/sbe_centaur_init.C $
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
 *  @file sbe_centaur_init.C
 *
 *  Support file for IStep:
 *      sbe_centaur_init
 *
 *
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

#include    <targeting/targetservice.H>
#include    <targeting/iterators/rangefilter.H>
#include    <targeting/predicates/predicatectm.H>
#include    <targeting/predicates/predicatepostfixexpr.H>
#include    <targeting/predicates/predicateisfunctional.H>
#include    <fapi.H>

//  --  prototype   includes    --
#include    "sbe_centaur_init.H"
// #include    "<cen_sbe_arrayinit>/<cen_sbe_arrayinit>.H"

namespace   SBE_CENTAUR_INIT
{

using   namespace   TARGETING;
using   namespace   fapi;

//
//  Wrapper function to call 10.1 : cen_sbe_tp_chiplet_init1
//
void    call_cen_sbe_tp_chiplet_init1( void *io_pArgs )
{
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );
    fapi::ReturnCode    l_fapirc;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_cen_sbe_tp_chiplet_init1 entry" );


    //  figure out what targets we need
    //  ADD TARGET GENERATION STUFF HERE

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

    for (    ;   l_pMemBufs;    ++l_pMemBufs  )
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target*  l_membuf_target = *l_pMemBufs;

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "=====  cen_sbe_tp_chiplet_init1 HWP(? ? ? )" );
        EntityPath l_path;
        l_path  =   l_membuf_target->getAttr<ATTR_PHYS_PATH>();
        l_path.dump();
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "===== " );
#if 0
        // $$$$ Thi add your code here, pass it l_membuf_target
        //  call the HWP with each target   ( if parallel, spin off a task )
        l_fapirc  =   cen_sbe_tp_chiplet_init1( ? , ?, ? );
#endif

        //  process return code.
        if ( l_fapirc == fapi::FAPI_RC_SUCCESS )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "SUCCESS :  cen_sbe_tp_chiplet_init1 HWP(? ? ? )" );
        }
        else
        {
            /**
             * @todo fapi error - just print out for now...
             */
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR %d:  cen_sbe_tp_chiplet_init1 HWP(?,?,? ) ",
                    static_cast<uint32_t>(l_fapirc) );
        }
    }   // end for l_pMemBufs

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "cen_sbe_tp_chiplet_init1 exit" );

    //  wait here on the barrier, then end the task.
    pTaskArgs->waitChildSync();
    task_end();
}


//
//  Wrapper function to call 10.2 : cen_sbe_tp_arrayinit
//
void    call_cen_sbe_tp_arrayinit( void *io_pArgs )
{
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );
    fapi::ReturnCode    l_fapirc;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_cen_sbe_tp_arrayinit entry" );


    //  figure out what targets we need
    //  ADD TARGET CODE HERE
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "=====  cen_sbe_tp_arrayinit HWP(? ? ? )" );
#if 0
    //  call the HWP with each target   ( if parallel, spin off a task )
    l_fapirc  =   cen_sbe_tp_arrayinit( ? , ?, ? );
#endif

    //  process return code.
    if ( l_fapirc== fapi::FAPI_RC_SUCCESS )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS :  cen_sbe_tp_arrayinit HWP(? ? ? )" );
    }
    else
    {
        /**
         * @todo fapi error - just print out for now...
         */
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR %d:  cen_sbe_tp_arrayinit HWP(? ? ?) ",
                static_cast<uint32_t>(l_fapirc) );
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_cen_sbe_tp_arrayinit exit" );

    //  wait here on the barrier, then end the task.
    pTaskArgs->waitChildSync();
    task_end();
}

//
//  Wrapper function to call 10.3 : cen_sbe_tp_chiplet_init2
//
void    call_cen_sbe_tp_chiplet_init2( void *io_pArgs )
{
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );
    fapi::ReturnCode    l_fapirc;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_cen_sbe_tp_chiplet_init2 entry" );


    //  figure out what targets we need
    //  ADD TARGET CODE HERE
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "=====  cen_sbe_tp_chiplet_init2 HWP(? ? ? )" );
#if 0
    //  call the HWP with each target   ( if parallel, spin off a task )
    l_fapirc  =   cen_sbe_tp_chiplet_init2( ? , ?, ? );
#endif

    //  process return code.
    if ( l_fapirc== fapi::FAPI_RC_SUCCESS )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS :  cen_sbe_tp_chiplet_init2 HWP(? ? ? )" );
    }
    else
    {
        /**
         * @todo fapi error - just print out for now...
         */
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR %d:  cen_sbe_tp_chiplet_init2 HWP(? ? ?) ",
                static_cast<uint32_t>(l_fapirc) );
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_cen_sbe_tp_chiplet_init2 exit" );

    //  wait here on the barrier, then end the task.
    pTaskArgs->waitChildSync();
    task_end();
}


//
//  Wrapper function to call 10.4 : cen_sbe_tp_chiplet_init3
//
void    call_cen_sbe_tp_chiplet_init3( void *io_pArgs )
{
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );
    fapi::ReturnCode    l_fapirc;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_cen_sbe_tp_chiplet_init3 entry" );


    //  figure out what targets we need
    //  ADD TARGET CODE HERE
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "=====  cen_sbe_tp_chiplet_init3 HWP(? ? ? )" );
#if 0
    //  call the HWP with each target   ( if parallel, spin off a task )
    l_fapirc  =   cen_sbe_tp_chiplet_init3( ? , ?, ? );
#endif

    //  process return code.
    if ( l_fapirc== fapi::FAPI_RC_SUCCESS )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS :  cen_sbe_tp_chiplet_init3 HWP(? ? ? )" );
    }
    else
    {
        /**
         * @todo fapi error - just print out for now...
         */
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR %d:  cen_sbe_tp_chiplet_init3 HWP(? ? ?) ",
                static_cast<uint32_t>(l_fapirc) );
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_cen_sbe_tp_chiplet_init3 exit" );

    //  wait here on the barrier, then end the task.
    pTaskArgs->waitChildSync();
    task_end();
}


//
//  Wrapper function to call 10.5 : cen_sbe_chiplet_init
//
void    call_cen_sbe_chiplet_init( void *io_pArgs )
{
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );
    fapi::ReturnCode    l_fapirc;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_cen_sbe_chiplet_init entry" );


    //  figure out what targets we need
    //  ADD TARGET CODE HERE
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "=====  cen_sbe_chiplet_init HWP(? ? ? )" );
#if 0
    //  call the HWP with each target   ( if parallel, spin off a task )
    l_fapirc  =   cen_sbe_chiplet_init( ? , ?, ? );
#endif

    //  process return code.
    if ( l_fapirc== fapi::FAPI_RC_SUCCESS )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS :  cen_sbe_chiplet_init HWP(? ? ? )" );
    }
    else
    {
        /**
         * @todo fapi error - just print out for now...
         */
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR %d:  cen_sbe_chiplet_init HWP(? ? ?) ",
                static_cast<uint32_t>(l_fapirc) );
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_cen_sbe_chiplet_init exit" );

    //  wait here on the barrier, then end the task.
    pTaskArgs->waitChildSync();
    task_end();
}


//
//  Wrapper function to call 10.6 : cen_sbe_arrayinit
//
void    call_cen_sbe_arrayinit( void *io_pArgs )
{
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );
    fapi::ReturnCode    l_fapirc;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_cen_sbe_arrayinit entry" );


    //  figure out what targets we need
    //  ADD TARGET CODE HERE
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "=====  cen_sbe_arrayinit HWP(? ? ? )" );
#if 0
    //  call the HWP with each target   ( if parallel, spin off a task )
    l_fapirc  =   cen_sbe_arrayinit( ? , ?, ? );
#endif

    //  process return code.
    if ( l_fapirc== fapi::FAPI_RC_SUCCESS )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS :  cen_sbe_arrayinit HWP(? ? ? )" );
    }
    else
    {
        /**
         * @todo fapi error - just print out for now...
         */
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR %d:  cen_sbe_arrayinit HWP(? ? ?) ",
                static_cast<uint32_t>(l_fapirc) );
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_cen_sbe_arrayinit exit" );

    //  wait here on the barrier, then end the task.
    pTaskArgs->waitChildSync();
    task_end();
}


//
//  Wrapper function to call 10.7 : cen_sbe_pll_initf
//
void    call_cen_sbe_pll_initf( void *io_pArgs )
{
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );
    fapi::ReturnCode    l_fapirc;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_cen_sbe_pll_initf entry" );


    //  figure out what targets we need
    //  ADD TARGET CODE HERE
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "=====  cen_sbe_pll_initf HWP(? ? ? )" );

#if 0
    //  call the HWP with each target   ( if parallel, spin off a task )
    l_fapirc  =   cen_sbe_pll_initf( ? , ?, ? );
#endif

    //  process return code.
    if ( l_fapirc== fapi::FAPI_RC_SUCCESS )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS :  cen_sbe_pll_initf HWP(? ? ? )" );
    }
    else
    {
        /**
         * @todo fapi error - just print out for now...
         */
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR %d:  cen_sbe_pll_initf HWP(? ? ?) ",
                static_cast<uint32_t>(l_fapirc) );
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_cen_sbe_pll_initf exit" );

    //  wait here on the barrier, then end the task.
    pTaskArgs->waitChildSync();
    task_end();
}


//
//  Wrapper function to call 10.8 : cen_sbe_dts_init
//
void    call_cen_sbe_dts_init( void *io_pArgs )
{
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );
    fapi::ReturnCode    l_fapirc;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_cen_sbe_dts_init entry" );


    //  figure out what targets we need
    //  ADD TARGET CODE HERE
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "=====  cen_sbe_dts_init HWP(? ? ? )" );
#if 0
    //  call the HWP with each target   ( if parallel, spin off a task )
    l_fapirc  =   cen_sbe_dts_init( ? , ?, ? );
#endif

    //  process return code.
    if ( l_fapirc== fapi::FAPI_RC_SUCCESS )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS :  cen_sbe_dts_init HWP(? ? ? )" );
    }
    else
    {
        /**
         * @todo fapi error - just print out for now...
         */
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR %d:  cen_sbe_dts_init HWP(? ? ?) ",
                static_cast<uint32_t>(l_fapirc) );
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_cen_sbe_dts_init exit" );

    //  wait here on the barrier, then end the task.
    pTaskArgs->waitChildSync();
    task_end();
}


//
//  Wrapper function to call 10.9 : cen_sbe_initf
//
void    call_cen_sbe_initf( void *io_pArgs )
{
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );
    fapi::ReturnCode    l_fapirc;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_cen_sbe_initf entry" );


    //  figure out what targets we need
    //  ADD TARGET CODE HERE
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "=====  cen_sbe_initf HWP(? ? ? )" );
#if 0
    //  call the HWP with each target   ( if parallel, spin off a task )
    l_fapirc  =   cen_sbe_initf( ? , ?, ? );
#endif

    //  process return code.
    if ( l_fapirc== fapi::FAPI_RC_SUCCESS )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS :  cen_sbe_initf HWP(? ? ? )" );
    }
    else
    {
        /**
         * @todo fapi error - just print out for now...
         */
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR %d:  cen_sbe_initf HWP(? ? ?) ",
                static_cast<uint32_t>(l_fapirc) );
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_cen_sbe_initf exit" );

    //  wait here on the barrier, then end the task.
    pTaskArgs->waitChildSync();
    task_end();
}


//
//  Wrapper function to call 10.10 : cen_sbe_do_manual_inits
//
void    call_cen_sbe_do_manual_inits( void *io_pArgs )
{
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );
    fapi::ReturnCode    l_fapirc;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_cen_sbe_do_manual_inits entry" );


    //  figure out what targets we need
    //  ADD TARGET CODE HERE
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "=====  cen_sbe_do_manual_inits HWP(? ? ? )" );
#if 0
    //  call the HWP with each target   ( if parallel, spin off a task )
    l_fapirc  =   cen_sbe_do_manual_inits( ? , ?, ? );
#endif

    //  process return code.
    if ( l_fapirc== fapi::FAPI_RC_SUCCESS )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS :  cen_sbe_do_manual_inits HWP(? ? ? )" );
    }
    else
    {
        /**
         * @todo fapi error - just print out for now...
         */
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR %d:  cen_sbe_do_manual_inits HWP(? ? ?) ",
                static_cast<uint32_t>(l_fapirc) );
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_cen_sbe_do_manual_inits exit" );

    //  wait here on the barrier, then end the task.
    pTaskArgs->waitChildSync();
    task_end();
}


//
//  Wrapper function to call 10.11 : cen_sbe_startclocks
//
void    call_cen_sbe_startclocks( void *io_pArgs )
{
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );
    fapi::ReturnCode    l_fapirc;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_cen_sbe_startclocks entry" );


    //  figure out what targets we need
    //  ADD TARGET CODE HERE
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "=====  cen_sbe_startclocks HWP(? ? ? )" );
#if 0
    //  call the HWP with each target   ( if parallel, spin off a task )
    l_fapirc  =   cen_sbe_startclocks( ? , ?, ? );
#endif

    //  process return code.
    if ( l_fapirc== fapi::FAPI_RC_SUCCESS )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS :  cen_sbe_startclocks HWP(? ? ? )" );
    }
    else
    {
        /**
         * @todo fapi error - just print out for now...
         */
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR %d:  cen_sbe_startclocks HWP(? ? ?) ",
                static_cast<uint32_t>(l_fapirc) );
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_cen_sbe_startclocks exit" );

    //  wait here on the barrier, then end the task.
    pTaskArgs->waitChildSync();
    task_end();
}


//
//  Wrapper function to call 10.12 : cen_sbe_scominits
//
void    call_cen_sbe_scominits( void *io_pArgs )
{
    INITSERVICE::TaskArgs *pTaskArgs =
            static_cast<INITSERVICE::TaskArgs *>( io_pArgs );
    fapi::ReturnCode    l_fapirc;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_cen_sbe_scominits entry" );


    //  figure out what targets we need
    //  ADD TARGET CODE HERE
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "=====  cen_sbe_scominits HWP(? ? ? )" );
#if 0
    //  call the HWP with each target   ( if parallel, spin off a task )
    l_fapirc  =   cen_sbe_scominits( ? , ?, ? );
#endif

    //  process return code.
    if ( l_fapirc== fapi::FAPI_RC_SUCCESS )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS :  cen_sbe_scominits HWP(? ? ? )" );
    }
    else
    {
        /**
         * @todo fapi error - just print out for now...
         */
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR %d:  cen_sbe_scominits HWP(? ? ?) ",
                static_cast<uint32_t>(l_fapirc) );
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_cen_sbe_scominits exit" );

    //  wait here on the barrier, then end the task.
    pTaskArgs->waitChildSync();
    task_end();
}

};   // end namespace

