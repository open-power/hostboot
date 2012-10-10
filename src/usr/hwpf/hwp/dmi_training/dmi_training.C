/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/dmi_training/dmi_training.C $
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
 *  @file dmi_training.C
 *
 *  Support file for hardware procedure:
 *      DMI Training
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

/**
 * @note    "" comments denote lines that should be built from the HWP
 *          tag block.  See the preliminary design in dmi_training.H
 *          Please save.
 */


/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <initservice/isteps_trace.H>

//  targeting support.
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

//  fapi support
#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>

//  --  prototype   includes    --
#include    "dmi_training.H"
#include    "proc_cen_framelock.H"
#include    "dmi_io_run_training.H"
#include    "dmi_scominit.H"

namespace   DMI_TRAINING
{


using   namespace   TARGETING;
using   namespace   fapi;

//
//  Wrapper function to call 11.1   dmi_scominit
//
void*    call_dmi_scominit( void *io_pArgs )
{
    errlHndl_t l_errl = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_dmi_scominit entry" );
    uint8_t l_num = 0;
   
    // Get all functional MCS chiplets
    TARGETING::TargetHandleList l_mcsTargetList;
    getAllChiplets(l_mcsTargetList, TYPE_MCS);
   
    // Invoke dmi_scominit on each one
    for (l_num = 0; l_num < l_mcsTargetList.size(); l_num++)
    {
        const TARGETING::Target* l_pTarget = l_mcsTargetList[l_num];
        const fapi::Target l_fapi_target(
            TARGET_TYPE_MCS_CHIPLET,
            reinterpret_cast<void *>
                (const_cast<TARGETING::Target*>(l_pTarget)));

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "Running dmi_scominit HWP on...");
        EntityPath l_path;
        l_path = l_pTarget->getAttr<ATTR_PHYS_PATH>();
        l_path.dump();

        FAPI_INVOKE_HWP(l_errl, dmi_scominit, l_fapi_target);
        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "ERROR 0x%.8X : dmi_scominit HWP returns error",
                      l_errl->reasonCode());
            break;
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "SUCCESS :  dmi_scominit HWP");
        }
    }

    if (!l_errl)
    {
        // Get all functional membuf chips
        TARGETING::TargetHandleList l_membufTargetList;
        getAllChips(l_membufTargetList, TYPE_MEMBUF);

        // Invoke dmi_scominit on each one
        for (l_num = 0; l_num < l_membufTargetList.size(); l_num++)
        {
            const TARGETING::Target* l_pTarget = l_membufTargetList[l_num];
            const fapi::Target l_fapi_target(
                TARGET_TYPE_MEMBUF_CHIP,
                reinterpret_cast<void *>
                    (const_cast<TARGETING::Target*>(l_pTarget)));

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "Running dmi_scominit HWP on...");
            EntityPath l_path;
            l_path = l_pTarget->getAttr<ATTR_PHYS_PATH>();
            l_path.dump();

            FAPI_INVOKE_HWP(l_errl, dmi_scominit, l_fapi_target);
            if (l_errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "ERROR 0x%.8X : dmi_scominit HWP returns error",
                          l_errl->reasonCode());
                break;
            }
            else
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "SUCCESS :  dmi_scominit HWP");
            }
        }
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_dmi_scominit exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_errl;
}


//
//  Wrapper function to call 11.2 :  dmi_erepair
//
void*    call_dmi_erepair( void *io_pArgs )
{
    errlHndl_t l_err = NULL;
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_dmi_erepair entry" );


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_dmi_erepair exit" );

    return l_err;
}

//
//  Wrapper function to call 11.3 : dmi_io_dccal
//
void*    call_dmi_io_dccal( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_dmi_io_dccal entry" );


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_dmi_io_dccal exit" );

    return l_err;
}


//
//  Wrapper function to call 11.4 : dmi_pre_trainadv
//
void*    call_dmi_pre_trainadv( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_dmi_pre_trainadv entry" );


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_dmi_pre_trainadv exit" );

    return l_err;
}


//
//  Wrapper function to call 11.5 : dmi_io_run_training
//
void*    call_dmi_io_run_training( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_dmi_io_run_training entry" );

    TARGETING::TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TYPE_PROC);

    for ( size_t i = 0; i < l_cpuTargetList.size(); i++ )
    {
        //  make a local copy of the CPU target
        const TARGETING::Target*  l_cpu_target = l_cpuTargetList[i];

        uint8_t l_cpuNum = l_cpu_target->getAttr<ATTR_POSITION>();

        // find all MCS chiplets of the proc
        TARGETING::TargetHandleList l_mcsTargetList;
        getChildChiplets( l_mcsTargetList, l_cpu_target, TYPE_MCS );

        for ( size_t j = 0; j < l_mcsTargetList.size(); j++ )
        {
            //  make a local copy of the MCS target
            const TARGETING::Target*  l_mcs_target = l_mcsTargetList[j];
            uint8_t l_mcsNum    =   l_mcs_target->getAttr<ATTR_CHIP_UNIT>();

            //  find all the Centaurs that are associated with this MCS
            TARGETING::TargetHandleList l_memTargetList;
            getAffinityChips(l_memTargetList, l_mcs_target, TYPE_MEMBUF);

            for ( size_t k = 0; k < l_memTargetList.size(); k++ )
            {
                //  make a local copy of the MEMBUF target
                const TARGETING::Target*  l_mem_target = l_memTargetList[k];

                //  struct containing custom parameters that is fed to HWP
                //  call the HWP with each target   ( if parallel, spin off a task )
                const fapi::Target l_fapi_master_target(
                        TARGET_TYPE_MCS_CHIPLET,
                        reinterpret_cast<void *>
                ( const_cast<TARGETING::Target*>(l_mcs_target) )
                );
                const fapi::Target l_fapi_slave_target(
                        TARGET_TYPE_MEMBUF_CHIP,
                        reinterpret_cast<void *>
                (const_cast<TARGETING::Target*>(l_mem_target))
                );

                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "===== Call dmi_io_run_training HWP( cpu 0x%x, mcs 0x%x, mem 0x%x ) : ",
                        l_cpuNum,
                        l_mcsNum,
                        k );

                EntityPath l_path;
                l_path = l_cpu_target->getAttr<ATTR_PHYS_PATH>();
                l_path.dump();
                l_path  =   l_mcs_target->getAttr<ATTR_PHYS_PATH>();
                l_path.dump();
                l_path  =   l_mem_target->getAttr<ATTR_PHYS_PATH>();
                l_path.dump();
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "===== " );
                FAPI_INVOKE_HWP(l_err, dmi_io_run_training,
                                l_fapi_master_target, l_fapi_slave_target);

                if (l_err)
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                            "ERROR 0x%.8X :  dmi_io_run_training HWP"
                            "( cpu 0x%x, mcs 0x%x, mem 0x%x ) ",
                            l_err->reasonCode(),
                            l_cpuNum,
                            l_mcsNum,
                            k );
                    break; // Break out mem target loop
                }
                else
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                            "SUCCESS :  dmi_io_run_training HWP"
                            "( cpu 0x%x, mcs 0x%x, mem 0x%x ) ",
                            l_cpuNum,
                            l_mcsNum,
                            k );
                }

            }  //end for l_mem_target

            if (l_err)
            {
                break; // Break out l_mcs_target
            }

        }   // end for l_mcs_target

        if (l_err)
        {
            break; // Break out l_cpu_target
        }

    }   // end for l_cpu_target


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_dmi_io_run_training exit" );

    return l_err;
}

//
//  Wrapper function to call 11.6 : dmi_post_trainadv
//
void*    call_dmi_post_trainadv( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_dmi_post_trainadv entry" );


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_dmi_post_trainadv exit" );

    return l_err;
}


//
//  Wrapper function to call 11.7 : proc_cen_framelock
//
void*    call_proc_cen_framelock( void *io_pArgs )
{
    errlHndl_t l_err = NULL;
    proc_cen_framelock_args     l_args;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_proc_cen_framework entry" );

    //  get the mcs chiplets
    TARGETING::TargetHandleList l_mcsTargetList;
    getAllChiplets(l_mcsTargetList, TYPE_MCS);

    for ( size_t i = 0; i < l_mcsTargetList.size() ; ++i  )
    {
        //  make a local copy of the MCS target
        const TARGETING::Target*  l_mcs_target = l_mcsTargetList[i];

        //  find all the Centaurs that are associated with this MCS
        TARGETING::TargetHandleList l_memTargetList;
        getAffinityChips(l_memTargetList, l_mcs_target, TYPE_MEMBUF);

        for ( uint8_t k = 0, l_memNum = 0; k < l_memTargetList.size();
                                                             k++, l_memNum++ )
        {
            //  make a local copy of the MEMBUF target
            const TARGETING::Target*  l_mem_target = l_memTargetList[k];

            // fill out the args struct.
            l_args.in_error_state       =   false;
            l_args.channel_init_timeout =   CHANNEL_INIT_TIMEOUT_NO_TIMEOUT;
            l_args.frtl_auto_not_manual =   true;
            l_args.frtl_manual_pu       =   0;
            l_args.frtl_manual_mem      =   0;

            fapi::Target l_fapiMcsTarget(
                    TARGET_TYPE_MCS_CHIPLET,
                    reinterpret_cast<void *>
                      ( const_cast<TARGETING::Target*>(l_mcs_target) )
                        );
            fapi::Target l_fapiMemTarget(
                    TARGET_TYPE_MEMBUF_CHIP,
                    reinterpret_cast<void *>
                        (const_cast<TARGETING::Target*>(l_mem_target))
                    );

            EntityPath l_path;
            l_path  =   l_mcs_target->getAttr<ATTR_PHYS_PATH>();
            l_path.dump();
            l_path  =   l_mem_target->getAttr<ATTR_PHYS_PATH>();
            l_path.dump();

            FAPI_INVOKE_HWP( l_err,
                             proc_cen_framelock,
                             l_fapiMcsTarget,
                             l_fapiMemTarget,
                             l_args  );
            if ( l_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                 "ERROR 0x%.8X : proc_cen_framelock HWP( mem %d )",
                l_err->reasonCode(), l_memNum );
                break; // break out of mem num loop
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "SUCCESS :  proc_cen_framelock HWP( mem %d ) ",
                        l_memNum );
            }

        }   // end mem

        if (l_err)
        {
            break; // break out of mcs loop
        }

    }   // end mcs

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_proc_cen_framework exit" );

    return l_err;
}

//
//  Wrapper function to call 11.8 : host_startPRD_dmi
//
void*    call_host_startPRD_dmi( void *io_pArgs )
{
    errlHndl_t l_err = NULL;
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_host_startPRD_dmi entry" );


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_host_startPRD_dmi exit" );

    return l_err;
}

//
//  Wrapper function to call 11.9 : host_attnlisten_cen
//
void*    call_host_attnlisten_cen( void *io_pArgs )
{

    errlHndl_t l_err = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_host_attnlisten_cen entry" );


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_host_attnlisten_cen exit" );

    return l_err;
}

//
//  Wrapper function to call 11.10 : cen_set_inband_addr
//
void*    call_cen_set_inband_addr( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_cen_set_inband_addr entry" );


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_cen_set_inband_addr exit" );

    return l_err;
}


};   // end namespace

