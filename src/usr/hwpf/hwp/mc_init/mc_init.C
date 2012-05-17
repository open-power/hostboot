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
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

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
#include    "mss_eff_config/mss_eff_config.H"

namespace   MC_INIT
{

using   namespace   TARGETING;
using   namespace   fapi;



//
//  Wrapper function to call 12.1 : host_collect_dimm_spd
//
void    call_host_collect_dimm_spd( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

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
                "ERROR 0x%.8X:  host_collect_dimm_spd HWP(? ? ?) ",
                static_cast<uint32_t>(l_fapirc) );
    }
    // @@@@@    END CUSTOM BLOCK:   @@@@@
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_host_collect_dimm_spd exit" );

    task_end2( l_err );
}



//
//  Wrapper function to call 12.2 : mss_volt
//
void    call_mss_volt( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_volt entry" );

    TARGETING::TargetHandleList l_membufTargetList;
    getAllChips(l_membufTargetList, TYPE_MEMBUF);

    //  declare a vector of fapi targets to pass to mss_volt
    std::vector<fapi::Target> l_membufFapiTargets;

    //  fill in the vector
    for ( size_t i = 0; i < l_membufTargetList.size(); i++ )
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target*  l_membuf_target = l_membufTargetList[i];

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
    FAPI_INVOKE_HWP(l_err, mss_volt, l_membufFapiTargets);

    //  process return code.
    if ( l_err )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR 0x%.8X:  mss_volt HWP( ) ", l_err->reasonCode());
    }
    else
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS :  mss_volt HWP( )" );
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_volt exit" );

    task_end2( l_err );
}

//
//  Wrapper function to call 12.3 : mss_freq
//
void    call_mss_freq( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_freq entry" );

    TARGETING::TargetHandleList l_membufTargetList;
    getAllChips(l_membufTargetList, TYPE_MEMBUF);

    for ( size_t i = 0; i < l_membufTargetList.size(); i++ )
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target*  l_membuf_target = l_membufTargetList[i];

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "=====  mss_freq HWP( %d )", i );
        EntityPath l_path;
        l_path  =   l_membuf_target->getAttr<ATTR_PHYS_PATH>();
        l_path.dump();

        //  call the HWP with each target   ( if parallel, spin off a task )
        // $$const fapi::Target l_fapi_membuf_target(
        fapi::Target l_fapi_membuf_target(
                TARGET_TYPE_MEMBUF_CHIP,
                reinterpret_cast<void *>
        (const_cast<TARGETING::Target*>(l_membuf_target)) );

        FAPI_INVOKE_HWP(l_err, mss_freq, l_fapi_membuf_target);

        //  process return code.
        if ( l_err )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                     "ERROR 0x%.8X:  mss_freq HWP( %d ) ",
                     l_err->reasonCode(),
                     i );
            break; // break out memBuf loop
         }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                     "SUCCESS :  mss_freq HWP( %d )", i );
        }
    } // End memBuf loop

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_freq exit" );

    task_end2( NULL );
}

//
//  Wrapper function to call 12.4 : mss_eff_config
//
void    call_mss_eff_config( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_eff_config entry" );

    TARGETING::TargetHandleList l_mbaTargetList;
    getAllChiplets(l_mbaTargetList, TYPE_MBA);

    for ( size_t i = 0; i < l_mbaTargetList.size(); i++ )
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target*  l_mba_target = l_mbaTargetList[i];

        //  print call to hwp and dump physical path of the target(s)
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "=====  mss_eff_config HWP( mba %d )", i );
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
        FAPI_INVOKE_HWP(l_err, mss_eff_config, l_fapi_mba_target);

        //  process return code.
        if ( l_err )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%.8X:  mss_eff_config HWP( mba %d ) ",
                    l_err->reasonCode(), i );
            break; // break out mba loop
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                     "SUCCESS :  mss_eff_config HWP( mba %d )", i );
        }
    }   // endfor


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_eff_config exit" );

    task_end2( NULL );
}


};   // end namespace
