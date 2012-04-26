//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/hwp/edi_ei_initialization/edi_ei_initialization.C $
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
 *  @file edi_ei_initialization.C
 *
 *  Support file for IStep: edi_ei_initialization
 *   EDI, EI Initialization
 *
 *  *****************************************************************
 *  THIS FILE WAS GENERATED ON 2012-04-11:1606
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

#include    "edi_ei_initialization.H"

//  Uncomment these files as they become available:
// #include    "fabric_erepair/fabric_erepair.H"
// #include    "fabric_io_dccal/fabric_io_dccal.H"
// #include    "fabric_io_run_training/fabric_io_run_training.H"
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
//      fabric_io_run_training
//
void    call_fabric_io_run_training( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
               "call_fabric_io_run_training entry" );

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
    FAPI_INVOKE_HWP( l_errl, fabric_io_run_training, _args_...);
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
               "call_fabric_io_run_training exit" );

    // end task, returning any errorlogs to IStepDisp 
    task_end2( l_errl );
}



//
//  Wrapper function to call 08.4 :
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
//  Wrapper function to call 08.5 :
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
//  Wrapper function to call 08.6 :
//      proc_fab_iovalid
//
void    call_proc_fab_iovalid( void    *io_pArgs )
{
    ReturnCode l_rc;
    errlHndl_t l_errl = NULL;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_fab_iovalid entry" );

    // Get all chip/chiplet targets
    //  Use PredicateIsFunctional to filter only functional chips/chiplets
    TARGETING::PredicateIsFunctional l_isFunctional;
    //  filter for functional Chips/Chiplets
    TARGETING::PredicateCTM l_Filter(CLASS_CHIP, TYPE_PROC);
    // declare a postfix expression widget
    TARGETING::PredicatePostfixExpr l_goodFilter;
    //  is-a--chip  is-functional   AND
    l_goodFilter.push(&l_Filter).push(&l_isFunctional).And();
    // apply the filter through all targets.
    TARGETING::TargetRangeFilter l_Procs(
            TARGETING::targetService().begin(),
            TARGETING::targetService().end(),
            &l_goodFilter );

    std::vector<proc_fab_smp_proc_chip *> l_smp;

    for ( ; l_Procs; ++l_Procs )
    {
        proc_fab_smp_proc_chip *l_proc = new proc_fab_smp_proc_chip();
        l_smp.push_back( l_proc );

        const TARGETING::Target * l_pTarget = *l_Procs;
        fapi::Target l_fapiproc_target( TARGET_TYPE_PROC_CHIP,
                       reinterpret_cast<void *>
                       (const_cast<TARGETING::Target*>(l_pTarget)) );

        l_proc->this_chip = l_fapiproc_target;

        std::vector<fapi::Target> l_abuses;
        l_rc = fapiGetChildChiplets( l_fapiproc_target,
                       fapi::TARGET_TYPE_ABUS_ENDPOINT, l_abuses);
        if (l_rc)
        {
            break;
        }

        std::vector<fapi::Target>::iterator l_abus;
        for (l_abus = l_abuses.begin(); l_abus != l_abuses.end(); ++l_abus)
        {
            fapi::Target & l_fapiTgt = *l_abus;
            TARGETING::Target * l_target = NULL;
            l_target = reinterpret_cast<TARGETING::Target*>(l_fapiTgt.get());
            uint8_t l_srcID = l_target->getAttr<ATTR_CHIP_UNIT>();
            TARGETING::Target *l_dstTgt = l_target->getAttr<ATTR_PEER_TARGET>();
            if (l_dstTgt)
            {
                fapi::Target l_fapiAbus( TARGET_TYPE_ABUS_ENDPOINT,
                                reinterpret_cast<void *>
                                (const_cast<TARGETING::Target*>(l_dstTgt)) );
                fapi::Target l_parent;
                l_rc = fapiGetParentChip( l_fapiAbus, l_parent );
                if (l_rc)
                {
                    break;
                }
                proc_fab_smp_a_bus *l_Abus = new proc_fab_smp_a_bus();
                l_proc->a_busses.push_back(l_Abus);
                l_Abus->src_chip_bus_id =
                                 static_cast<proc_fab_smp_a_bus_id>(l_srcID);
                l_Abus->dest_chip = new fapi::Target(l_parent);
                uint8_t l_destID = l_dstTgt->getAttr<ATTR_CHIP_UNIT>();
                l_Abus->dest_chip_bus_id =
                                  static_cast<proc_fab_smp_a_bus_id>(l_destID);
            }
        }

        if (l_rc)
        {
            break;
        }

        std::vector<fapi::Target> l_xbuses;
        l_rc = fapiGetChildChiplets( l_fapiproc_target,
                       fapi::TARGET_TYPE_XBUS_ENDPOINT, l_xbuses);

        if (l_rc)
        {
            break;
        }

        std::vector<fapi::Target>::iterator l_xbus;
        for (l_xbus = l_xbuses.begin(); l_xbus != l_xbuses.end(); ++l_xbus)
        {
            fapi::Target & l_fapiTgt = *l_xbus;
            TARGETING::Target * l_target = NULL;
            l_target = reinterpret_cast<TARGETING::Target*>(l_fapiTgt.get());
            uint8_t l_srcID = l_target->getAttr<ATTR_CHIP_UNIT>();
            TARGETING::Target *l_dstTgt = l_target->getAttr<ATTR_PEER_TARGET>();
            if (l_dstTgt)
            {
                fapi::Target l_fapiXbus( TARGET_TYPE_XBUS_ENDPOINT,
                                reinterpret_cast<void *>
                                (const_cast<TARGETING::Target*>(l_dstTgt)) );
                fapi::Target l_parent;
                l_rc = fapiGetParentChip( l_fapiXbus, l_parent );
                if (l_rc)
                {
                    break;
                }
                proc_fab_smp_x_bus *l_Xbus = new proc_fab_smp_x_bus();
                l_proc->x_busses.push_back(l_Xbus);
                l_Xbus->src_chip_bus_id =
                                 static_cast<proc_fab_smp_x_bus_id>(l_srcID);
                l_Xbus->dest_chip = new fapi::Target(l_parent);
                uint8_t l_destID = l_dstTgt->getAttr<ATTR_CHIP_UNIT>();
                l_Xbus->dest_chip_bus_id =
                                  static_cast<proc_fab_smp_x_bus_id>(l_destID);
            }
        }

        if (l_rc)
        {
            break;
        }
    }

    if (l_rc.ok())
    {
        FAPI_INVOKE_HWP( l_errl, proc_fab_iovalid, l_smp, true, true, true );

        if ( l_errl )
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, 
                      "ERROR : proc_fab_iovalid HWP fails");
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, 
                      "SUCCESS : proc_fab_iovalid HWP passes");
        }
    }
    else
    {
        l_errl = fapi::fapiRcToErrl(l_rc);
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, 
                   "ERROR : call_proc_fab_iovalid encountered an error");
    }

    std::vector<proc_fab_smp_proc_chip *>::iterator l_itr;
    for (l_itr = l_smp.begin(); l_itr != l_smp.end(); ++l_itr)
    {
        std::vector<proc_fab_smp_a_bus *>::iterator l_atr;
        for (l_atr = (*l_itr)->a_busses.begin();
             l_atr != (*l_itr)->a_busses.end(); ++l_atr)
        {
            delete ((*l_atr)->dest_chip);
            delete (*l_atr);
        }
        std::vector<proc_fab_smp_x_bus *>::iterator l_xtr;
        for (l_xtr = (*l_itr)->x_busses.begin();
             l_xtr != (*l_itr)->x_busses.end(); ++l_xtr)
        {
            delete ((*l_xtr)->dest_chip);
            delete (*l_xtr);
        }
        delete (*l_itr);
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_fab_iovalid exit" );

    // end task, returning any errorlogs to IStepDisp 
    task_end2( l_errl );
}


};   // end namespace
