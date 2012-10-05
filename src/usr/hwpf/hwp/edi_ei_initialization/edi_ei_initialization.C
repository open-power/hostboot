/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/edi_ei_initialization/edi_ei_initialization.C $
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
 *  @file edi_ei_initialization.C
 *
 *  Support file for IStep: edi_ei_initialization
 *   EDI, EI Initialization
 *
 *  *****************************************************************
 *  THIS FILE WAS GENERATED ON 2012-04-11:1606
 *  *****************************************************************
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>
#include    <map>
#include    <hwpf/plat/fapiPlatReasonCodes.H>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <initservice/isteps_trace.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/common/trace.H>

//  fapi support
#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>

#include    "edi_ei_initialization.H"
#include    <pbusLinkSvc.H>

//  Uncomment these files as they become available:
// #include    "fabric_erepair/fabric_erepair.H"
// #include    "fabric_io_dccal/fabric_io_dccal.H"
// #include    "fabric_pre_trainadv/fabric_pre_trainadv.H"
#include    "fabric_io_run_training/fabric_io_run_training.H"
// #include    "fabric_post_trainadv/fabric_post_trainadv.H"
// #include    "host_startPRD_pbus/host_startPRD_pbus.H"
// #include    "host_attnlisten_proc/host_attnlisten_proc.H"
#include    "proc_fab_iovalid/proc_fab_iovalid.H"

namespace   EDI_EI_INITIALIZATION
{


using   namespace   TARGETING;
using   namespace   fapi;


//
//  Wrapper function to call 08.1 :
//      fabric_erepair
//
void    call_fabric_erepair( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_fabric_erepair entry" );

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
    FAPI_INVOKE_HWP( l_errl, fabric_erepair, _args_...);
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
               "call_fabric_erepair exit" );

    // end task, returning any errorlogs to IStepDisp
    task_end2( l_errl );
}



//
//  Wrapper function to call 08.2 :
//      fabric_io_dccal
//
void    call_fabric_io_dccal( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_fabric_io_dccal entry" );

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
    FAPI_INVOKE_HWP( l_errl, fabric_io_dccal, _args_...);
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
               "call_fabric_io_dccal exit" );

    // end task, returning any errorlogs to IStepDisp
    task_end2( l_errl );
}



//
//  Wrapper function to call 08.3 :
//      fabric_pre_trainadv
//
void    call_fabric_pre_trainadv( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_fabric_pre_trainadv entry" );

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
    FAPI_INVOKE_HWP( l_errl, fabric_pre_trainadv, _args_...);
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
               "call_fabric_pre_trainadv exit" );

    // end task, returning any errorlogs to IStepDisp
    task_end2( l_errl );
}



//
//  Wrapper function to call 08.4 :
//      fabric_io_run_training
//
void    call_fabric_io_run_training( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_fabric_io_run_training entry" );

    TargetPairs_t l_PbusConnections;
    TargetPairs_t::iterator l_itr;
    const uint32_t MaxBusSet = 2;
    TYPE busSet[MaxBusSet] = { TYPE_ABUS, TYPE_XBUS };

    for (uint32_t i = 0; (!l_errl) && (i < MaxBusSet); i++)
    {
        l_errl = PbusLinkSvc::getTheInstance().getPbusConnections(
                                            l_PbusConnections, busSet[i] );

        for (l_itr = l_PbusConnections.begin();
             (!l_errl) && (l_itr != l_PbusConnections.end()); ++l_itr)
        {
            const fapi::Target l_fapi_endp1_target(
                   (i ? TARGET_TYPE_XBUS_ENDPOINT : TARGET_TYPE_ABUS_ENDPOINT),
                   reinterpret_cast<void *>
                   (const_cast<TARGETING::Target*>(l_itr->first)));
            const fapi::Target l_fapi_endp2_target(
                   (i ? TARGET_TYPE_XBUS_ENDPOINT : TARGET_TYPE_ABUS_ENDPOINT),
                   reinterpret_cast<void *>
                   (const_cast<TARGETING::Target*>(l_itr->second)));

            EntityPath l_path;
            l_path  =   l_itr->first->getAttr<ATTR_PHYS_PATH>();
            l_path.dump();
            l_path  =   l_itr->second->getAttr<ATTR_PHYS_PATH>();
            l_path.dump();

            //  call the HWP with each bus connection
            FAPI_INVOKE_HWP( l_errl, fabric_io_run_training,
                             l_fapi_endp1_target, l_fapi_endp2_target );

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "%s : %cbus connection io_run_training",
                       (l_errl ? "ERROR" : "SUCCESS"),
                       (i ? 'X' : 'A') );
        }
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_fabric_io_run_training exit" );

    // end task, returning any errorlogs to IStepDisp
    task_end2( l_errl );
}



//
//  Wrapper function to call 08.5 :
//      fabric_post_trainadv
//
void    call_fabric_post_trainadv( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_fabric_post_trainadv entry" );

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
    FAPI_INVOKE_HWP( l_errl, fabric_post_trainadv, _args_...);
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
               "call_fabric_post_trainadv exit" );

    // end task, returning any errorlogs to IStepDisp
    task_end2( l_errl );
}



//
//  Wrapper function to call 08.6 :
//      host_startPRD_pbus
//
void    call_host_startPRD_pbus( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_startPRD_pbus entry" );

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
    FAPI_INVOKE_HWP( l_errl, host_startPRD_pbus, _args_...);
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
               "call_host_startPRD_pbus exit" );

    // end task, returning any errorlogs to IStepDisp
    task_end2( l_errl );
}



//
//  Wrapper function to call 08.7 :
//      host_attnlisten_proc
//
void    call_host_attnlisten_proc( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_attnlisten_proc entry" );

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
    FAPI_INVOKE_HWP( l_errl, host_attnlisten_proc, _args_...);
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
               "call_host_attnlisten_proc exit" );

    // end task, returning any errorlogs to IStepDisp
    task_end2( l_errl );
}



//
//  Wrapper function to call 08.8 :
//      proc_fab_iovalid
//
void    call_proc_fab_iovalid( void    *io_pArgs )
{
    ReturnCode l_rc;
    errlHndl_t l_errl = NULL;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_fab_iovalid entry" );

    // Get all chip/chiplet targets
    TARGETING::TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TYPE_PROC);

    TargetPairs_t l_abusConnections;
    TargetPairs_t l_xbusConnections;
    l_errl = PbusLinkSvc::getTheInstance().getPbusConnections(
                                 l_abusConnections, TYPE_ABUS, false );
    if (!l_errl)
    {
        l_errl = PbusLinkSvc::getTheInstance().getPbusConnections(
                                 l_xbusConnections, TYPE_XBUS, false );
    }

    std::vector<proc_fab_iovalid_proc_chip> l_smp;

    for ( size_t i = 0; (!l_errl) && (i < l_cpuTargetList.size()); i++ )
    {
        proc_fab_iovalid_proc_chip l_procEntry;

        const TARGETING::Target * l_pTarget = l_cpuTargetList[i];
        fapi::Target l_fapiproc_target( TARGET_TYPE_PROC_CHIP,
                       reinterpret_cast<void *>
                       (const_cast<TARGETING::Target*>(l_pTarget)) );

        l_procEntry.this_chip = l_fapiproc_target;
        l_procEntry.a0 = false;
        l_procEntry.a1 = false;
        l_procEntry.a2 = false;
        l_procEntry.x0 = false;
        l_procEntry.x1 = false;
        l_procEntry.x2 = false;
        l_procEntry.x3 = false;

        TARGETING::TargetHandleList l_abuses;
        getChildChiplets( l_abuses, l_pTarget, TYPE_ABUS );

        for (size_t j = 0; j < l_abuses.size(); j++)
        {
            TARGETING::Target * l_target = l_abuses[j];
            uint8_t l_srcID = l_target->getAttr<ATTR_CHIP_UNIT>();
            TargetPairs_t::iterator l_itr = l_abusConnections.find(l_target);
            if ( l_itr == l_abusConnections.end() )
            {
                continue;
            }
            switch (l_srcID)
            {
                case 0: l_procEntry.a0 = true; break;
                case 1: l_procEntry.a1 = true; break;
                case 2: l_procEntry.a2 = true; break;
               default: break;
            }
        }

        TARGETING::TargetHandleList l_xbuses;
        getChildChiplets( l_xbuses, l_pTarget, TYPE_XBUS );

        for (size_t j = 0; j < l_xbuses.size(); j++)
        {
            TARGETING::Target * l_target = l_xbuses[j];
            uint8_t l_srcID = l_target->getAttr<ATTR_CHIP_UNIT>();
            TargetPairs_t::iterator l_itr = l_xbusConnections.find(l_target);
            if ( l_itr == l_xbusConnections.end() )
            {
                continue;
            }
            switch (l_srcID)
            {
                case 0: l_procEntry.x0 = true; break;
                case 1: l_procEntry.x1 = true; break;
                case 2: l_procEntry.x2 = true; break;
                case 3: l_procEntry.x3 = true; break;
               default: break;
            }
        }

        l_smp.push_back(l_procEntry);
    }

    if (l_errl)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "ERROR : call_proc_fab_iovalid encountered an error");
    }
    else
    {
        FAPI_INVOKE_HWP( l_errl, proc_fab_iovalid, l_smp, true );

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "%s : proc_fab_iovalid HWP.",
                  (l_errl ? "ERROR" : "SUCCESS"));
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_fab_iovalid exit" );

    // end task, returning any errorlogs to IStepDisp
    task_end2( l_errl );
}


};   // end namespace
