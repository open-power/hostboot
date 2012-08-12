/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/dram_training/dram_training.C $
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
#include <targeting/common/utilFilter.H>

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
#include    "mss_scominit/mss_scominit.H"
#include    "mss_ddr_phy_reset/mss_ddr_phy_reset.H"
#include    "mss_draminit/mss_draminit.H"
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
    TARGETING::TargetHandleList l_membufTargetList;
    getAllChips(l_membufTargetList, TYPE_MEMBUF);

    for ( size_t i = 0; i < l_membufTargetList.size(); i++ )
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target*  l_pCentaur = l_membufTargetList[i];

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
//  Wrapper function to call 13.5 : mss_scominit
//
void    call_mss_scominit( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_scominit entry" );

    // TODO:  RTC 44947
    // This currently fails on Simics because cen_ddrphy.initfile accesses
    // indirect broadcast SCOM addresses.  When Simics have support for
    // indirect broadcast SCOM addresses than this HWP can be executed.
    // For now, just execute the HWP on VPO.
    TARGETING::Target * l_pSysTarget = NULL;
    TARGETING::targetService().getTopLevelTarget(l_pSysTarget);
    uint8_t l_vpoMode = l_pSysTarget->getAttr<TARGETING::ATTR_IS_SIMULATION>();
    if (!l_vpoMode)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
            "INFO : not executing mss_scominit in Simics until it supports "
            "indirect broadcast SCOM addresses");
    }
    else
    {
        // Get all Centaur targets
        TARGETING::TargetHandleList l_membufTargetList;
        getAllChips(l_membufTargetList, TYPE_MEMBUF);

        for ( size_t i = 0; i < l_membufTargetList.size(); i++ )
        {
            //  make a local copy of the target for ease of use
            const TARGETING::Target*  l_pCentaur = l_membufTargetList[i];

            // Dump current run on target
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "Running mss_scominit HWP on..." );
            
            EntityPath l_path;
            l_path  =   l_pCentaur->getAttr<ATTR_PHYS_PATH>();
            l_path.dump();

            // Cast to a FAPI type of target.
            const fapi::Target l_fapi_centaur(
                    TARGET_TYPE_MEMBUF_CHIP,
                    reinterpret_cast<void *>
                    (const_cast<TARGETING::Target*>(l_pCentaur)) );

            //  call the HWP with each fapi::Target
            FAPI_INVOKE_HWP(l_err, mss_scominit, l_fapi_centaur);

            if (l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "ERROR 0x%.8X: mss_scominit HWP returns error",
                          l_err->reasonCode());
                break;
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "SUCCESS :  mss_scominit HWP( )" );
            }
        }
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_scominit exit" );

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
    TARGETING::TargetHandleList l_mbaTargetList;
    getAllChiplets(l_mbaTargetList, TYPE_MBA);

    // Limit the number of MBAs to run in VPO environment to save time.
    uint8_t l_mbaLimit = UNLIMITED_RUN;
    if (TARGETING::is_vpo() )
    {
           l_mbaLimit = VPO_NUM_OF_MBAS_TO_RUN;
    }

    for (   uint8_t l_mbaNum=0 ;
            (l_mbaNum < l_mbaLimit) && (l_mbaNum < l_mbaTargetList.size()) ;
            l_mbaNum++   )
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target*  l_mba_target = l_mbaTargetList[l_mbaNum];

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
    TARGETING::TargetHandleList l_mbaTargetList;
    getAllChiplets(l_mbaTargetList, TYPE_MBA);

    // Limit the number of MBAs to run in VPO environment to save time.
    uint8_t l_mbaLimit = UNLIMITED_RUN;
    if (TARGETING::is_vpo() )
    {
           l_mbaLimit = VPO_NUM_OF_MBAS_TO_RUN;
    }

    for (   uint8_t l_mbaNum=0 ;
            (l_mbaNum < l_mbaLimit) && (l_mbaNum < l_mbaTargetList.size());
            l_mbaNum++   )
    {
        // Make a local copy of the target for ease of use
        const TARGETING::Target*  l_mba_target = l_mbaTargetList[l_mbaNum];

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
//  Wrapper function to call 13.8 : mss_draminit_training
//
void    call_mss_draminit_training( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_draminit_training entry" );

    // Get all MBA targets
    TARGETING::TargetHandleList l_mbaTargetList;
    getAllChiplets(l_mbaTargetList, TYPE_MBA);

    // Limit the number of MBAs to run in VPO environment to save time.
    uint8_t l_mbaLimit = UNLIMITED_RUN;
    if (TARGETING::is_vpo() )
    {
           l_mbaLimit = VPO_NUM_OF_MBAS_TO_RUN;
    }

    for (   uint8_t l_mbaNum=0 ;
            (l_mbaNum < l_mbaLimit) && (l_mbaNum < l_mbaTargetList.size());
            l_mbaNum++    )
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target*  l_mba_target = l_mbaTargetList[l_mbaNum];

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
//  Wrapper function to call 13.9 : mss_draminit_trainadv
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
//  Wrapper function to call 13.10 : mss_draminit_mc
//
void    call_mss_draminit_mc( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_draminit_mc entry" );

    // Get all centaur targets
    TARGETING::TargetHandleList l_mBufTargetList;
    getAllChips(l_mBufTargetList, TYPE_MEMBUF);

    // Limit the number of MBAs to run in VPO environment to save time.
    uint8_t l_memBufLimit = UNLIMITED_RUN;
    if (TARGETING::is_vpo() )
    {
        l_memBufLimit = VPO_NUM_OF_MEMBUF_TO_RUN ;
    }

    for (uint8_t l_mBufNum=0 ;
        (l_mBufNum < l_memBufLimit) && (l_mBufNum < l_mBufTargetList.size());
         l_mBufNum++)
    {

        const TARGETING::Target* l_membuf_target = l_mBufTargetList[l_mBufNum];

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
