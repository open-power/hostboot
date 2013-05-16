/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/edi_ei_initialization/edi_ei_initialization.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

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

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <hwpisteperror.H>
#include    <errl/errludtarget.H>

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
#include    "io_restore_erepair.H"
// #include    "fabric_io_dccal/fabric_io_dccal.H"
// #include    "fabric_erepair/fabric_erepair.H"
// #include    "fabric_pre_trainadv/fabric_pre_trainadv.H"
#include    "fabric_io_run_training/fabric_io_run_training.H"
// #include    "fabric_post_trainadv/fabric_post_trainadv.H"
// #include    "host_startprd_pbus/host_startprd_pbus.H"
// #include    "host_attnlisten_proc/host_attnlisten_proc.H"
#include    "proc_fab_iovalid/proc_fab_iovalid.H"
#include    <diag/prdf/prdfMain.H>
#include    "fabric_io_dccal/fabric_io_dccal.H"

// eRepair Restore
#include <erepairAccessorHwpFuncs.H>

namespace   EDI_EI_INITIALIZATION
{


using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   fapi;


//
//  Wrapper function to call fabric_erepair
//
void*    call_fabric_erepair( void    *io_pArgs )
{
    ISTEP_ERROR::IStepError l_StepError;
    errlHndl_t l_errl = NULL;
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_fabric_erepair entry" );

    std::vector<uint8_t> l_endp1_txFaillanes;
    std::vector<uint8_t> l_endp1_rxFaillanes;
    std::vector<uint8_t> l_endp2_txFaillanes;
    std::vector<uint8_t> l_endp2_rxFaillanes;

    TargetPairs_t l_PbusConnections;
    const uint32_t MaxBusSet = 2;
    TYPE busSet[MaxBusSet] = { TYPE_ABUS, TYPE_XBUS };

    for (uint32_t i = 0; l_StepError.isNull() && (i < MaxBusSet); i++)
    {
        l_errl = PbusLinkSvc::getTheInstance().getPbusConnections(
                                            l_PbusConnections, busSet[i] );
        if ( l_errl )
        {
            /*@
             * @errortype
             * @reasoncode  ISTEP_GET_PBUS_CONNECTIONS_FAILED
             * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid    ISTEP_FABRIC_IO_RESTORE_EREPAIR
             * @userdata1   bytes 0-1: plid identifying first error
             *              bytes 2-3: reason code of first error
             * @userdata2   bytes 0-1: total number of elogs included
             *              bytes 2-3: N/A
             * @devdesc     call to fabric_io_run_training has failed
             *              see error log in the user details seciton for
             *              additional details.
             */
            l_StepError.addErrorDetails(ISTEP_GET_PBUS_CONNECTIONS_FAILED,
                                        ISTEP_FABRIC_IO_RESTORE_EREPAIR,
                                        l_errl );

            errlCommit( l_errl, HWPF_COMP_ID );
        }

        for (TargetPairs_t::const_iterator l_itr = l_PbusConnections.begin();
             (l_StepError.isNull()) && (l_itr != l_PbusConnections.end());
             ++l_itr)
        {
            const fapi::Target l_fapi_endp1_target(
                   (i ? TARGET_TYPE_XBUS_ENDPOINT : TARGET_TYPE_ABUS_ENDPOINT),
                   (const_cast<TARGETING::Target*>(l_itr->first)));
            const fapi::Target l_fapi_endp2_target(
                   (i ? TARGET_TYPE_XBUS_ENDPOINT : TARGET_TYPE_ABUS_ENDPOINT),
                   (const_cast<TARGETING::Target*>(l_itr->second)));

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "===== " );

            // Get the repair lanes from the VPD
            fapi::ReturnCode l_rc;
            l_rc = erepairGetRestoreLanes(l_fapi_endp1_target,
                                          l_endp1_txFaillanes,
                                          l_endp1_rxFaillanes,
                                          l_fapi_endp2_target,
                                          l_endp2_txFaillanes,
                                          l_endp2_rxFaillanes);

            if(l_rc)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "Unable to"
                          " retrieve fabric eRepair data from the VPD");

                // convert the FAPI return code to an err handle
                l_errl = fapiRcToErrl(l_rc);

                // capture the target data in the elog
                ErrlUserDetailsTarget(l_itr->first).addToLog( l_errl );
                ErrlUserDetailsTarget(l_itr->second).addToLog( l_errl );

                /*@
                 * @errortype
                 * @reasoncode  ISTEP_FABRIC_GET_RESTORE_LANES_FAILED
                 * @severity    ERRL_SEV_UNRECOVERABLE
                 * @moduleid    ISTEP_FABRIC_IO_RESTORE_EREPAIR
                 * @userdata1   None
                 * @userdata2   None
                 * @devdesc     call to io_restore_erepair has failed
                 */
                l_StepError.addErrorDetails(
                                        ISTEP_FABRIC_GET_RESTORE_LANES_FAILED,
                                        ISTEP_FABRIC_IO_RESTORE_EREPAIR,
                                        l_errl);

                errlCommit(l_errl, HWPF_COMP_ID);

                break;
            }

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                   "===== Call io_restore_erepair HWP"
                   "%cbus connection ", (i ? 'X' : 'A') );

            if(l_endp1_txFaillanes.size() || l_endp1_rxFaillanes.size())
            {
                // call the io_restore_erepair HWP to restore eRepair
                // lanes of endp1

                FAPI_INVOKE_HWP(l_errl,
                                io_restore_erepair,
                                l_fapi_endp1_target,
                                l_endp1_txFaillanes,
                                l_endp1_rxFaillanes);
            }

            if(l_errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "ERROR 0x%.8X :  io_restore_erepair HWP"
                        "%cbus connection ",
                        l_errl->reasonCode(), (i ? 'X' : 'A') );

                // capture the target data in the elog
                ErrlUserDetailsTarget(l_itr->first).addToLog( l_errl );
                ErrlUserDetailsTarget(l_itr->second).addToLog( l_errl );

                /*@
                 * @errortype
                 * @reasoncode  ISTEP_FABRIC_DRIVE_RESTORE_FAILED
                 * @severity    ERRL_SEV_UNRECOVERABLE
                 * @moduleid    ISTEP_FABRIC_IO_RESTORE_EREPAIR
                 * @userdata1   None
                 * @userdata2   None
                 * @devdesc     call to io_restore_erepair has failed
                 */
                l_StepError.addErrorDetails(ISTEP_FABRIC_DRIVE_RESTORE_FAILED,
                                           ISTEP_FABRIC_IO_RESTORE_EREPAIR,
                                           l_errl);

                errlCommit(l_errl, HWPF_COMP_ID);
                break;
            }

            if(l_endp2_txFaillanes.size() || l_endp2_rxFaillanes.size())
            {
                // call the io_restore_erepair HWP to restore eRepair
                // lanes of endp2

                FAPI_INVOKE_HWP(l_errl,
                                io_restore_erepair,
                                l_fapi_endp2_target,
                                l_endp2_txFaillanes,
                                l_endp2_rxFaillanes);
            }

            if (l_errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                            "ERROR 0x%.8X :  io_restore_erepair HWP"
                            "%cbus connection ",
                            l_errl->reasonCode(), (i ? 'X' : 'A') );

                // capture the target data in the elog
                ErrlUserDetailsTarget(l_itr->first).addToLog( l_errl );
                ErrlUserDetailsTarget(l_itr->second).addToLog( l_errl );

                /*@
                 * @errortype
                 * @reasoncode  ISTEP_FABRIC_RECEIVE_RESTORE_FAILED
                 * @severity    ERRL_SEV_UNRECOVERABLE
                 * @moduleid    ISTEP_FABRIC_IO_RESTORE_EREPAIR
                 * @userdata1   None
                 * @userdata2   None
                 * @devdesc     call to io_restore_erepair has failed
                 */
                l_StepError.addErrorDetails(
                                        ISTEP_FABRIC_RECEIVE_RESTORE_FAILED,
                                        ISTEP_FABRIC_IO_RESTORE_EREPAIR,
                                        l_errl);

                errlCommit(l_errl, HWPF_COMP_ID);
                break;
            }
        } // end for l_PbusConnections
    } // end for MaxBusSet

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_fabric_erepair exit" );

    return l_StepError.getErrorHandle();
}



//
//  Wrapper function to call fabric_io_dccal
//
void*    call_fabric_io_dccal( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;
    IStepError  l_StepError;

    // We are not running this analog procedure in VPO
    if (TARGETING::is_vpo())
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Skip call_fabric_io_dccal in VPO!");
        return l_StepError.getErrorHandle();
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_fabric_io_dccal entry" );

    TargetPairs_t l_PbusConnections;
    TargetPairs_t::iterator l_itr;
    const uint32_t MaxBusSet = 2;
    TYPE busSet[MaxBusSet] = { TYPE_ABUS, TYPE_XBUS };

    // Note:
    // Due to lab tester board environment, HW procedure writer (Varkey) has
    // requested to send in one target of a time (we used to send in
    // both ends in one call). Even though they don't have to be
    // in order, we should keep the pair concept here in case we need to send
    // in a pair in the future again.
    for (uint32_t ii = 0; (!l_errl) && (ii < MaxBusSet); ii++)
    {
        l_errl = PbusLinkSvc::getTheInstance().getPbusConnections(
                                            l_PbusConnections, busSet[ii] );

        for (l_itr = l_PbusConnections.begin();
             l_itr != l_PbusConnections.end();
             ++l_itr)
        {
            const fapi::Target l_fapi_endp1_target(
                   (ii ? TARGET_TYPE_XBUS_ENDPOINT : TARGET_TYPE_ABUS_ENDPOINT),
                   (const_cast<TARGETING::Target*>(l_itr->first)));
            const fapi::Target l_fapi_endp2_target(
                   (ii ? TARGET_TYPE_XBUS_ENDPOINT : TARGET_TYPE_ABUS_ENDPOINT),
                   (const_cast<TARGETING::Target*>(l_itr->second)));

            //  call the HWP with each bus connection
            FAPI_INVOKE_HWP( l_errl, fabric_io_dccal, l_fapi_endp1_target );

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "%s : %cbus connection fabric_io_dccal. Target 0x%.8X",
                       (l_errl ? "ERROR" : "SUCCESS"), (ii ? 'X' : 'A'),
                        TARGETING::get_huid(l_itr->first) );
            if ( l_errl )
            {
                // capture the target data in the elog
                ErrlUserDetailsTarget(l_itr->first).addToLog( l_errl );

                /*@
                 * @errortype
                 * @reasoncode  ISTEP_FABRIC_IO_DCCAL_ENDPOINT1_FAILED
                 * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid    ISTEP_FABRIC_IO_DCCAL
                 * @userdata1   bytes 0-1: plid identifying first error
                 *              bytes 2-3: reason code of first error
                 * @userdata2   bytes 0-1: total number of elogs included
                 *              bytes 2-3: N/A
                 * @devdesc     call to fabric_io_run_training has failed
                 *              see error log in the user details section for
                 *              additional details.
                 */
                l_StepError.addErrorDetails(ISTEP_FABRIC_IO_DCCAL_ENDPOINT1_FAILED,
                                            ISTEP_FABRIC_IO_DCCAL,
                                            l_errl );

                errlCommit( l_errl, HWPF_COMP_ID );
                // We want to continue the training despite the error, so
                // no break
            }

            //  call the HWP with each bus connection
            FAPI_INVOKE_HWP( l_errl, fabric_io_dccal, l_fapi_endp2_target );

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "%s : %cbus connection fabric_io_dccal. Target 0x%.8X",
                       (l_errl ? "ERROR" : "SUCCESS"), (ii ? 'X' : 'A'),
                        TARGETING::get_huid(l_itr->second) );
            if ( l_errl )
            {
                // capture the target data in the elog
                ErrlUserDetailsTarget(l_itr->second).addToLog( l_errl );

                /*@
                 * @errortype
                 * @reasoncode  ISTEP_FABRIC_IO_DCCAL_ENDPOINT2_FAILED
                 * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid    ISTEP_FABRIC_IO_DCCAL
                 * @userdata1   bytes 0-1: plid identifying first error
                 *              bytes 2-3: reason code of first error
                 * @userdata2   bytes 0-1: total number of elogs included
                 *              bytes 2-3: N/A
                 * @devdesc     call to fabric_io_run_training has failed
                 *              see error log in the user details section for
                 *              additional details.
                 */
                l_StepError.addErrorDetails(ISTEP_FABRIC_IO_DCCAL_ENDPOINT2_FAILED,
                                            ISTEP_FABRIC_IO_DCCAL,
                                            l_errl );

                errlCommit( l_errl, HWPF_COMP_ID );
                // We want to continue the training despite the error, so
                // no break
            }
        }
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_fabric_io_dccal exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}



//
//  Wrapper function to call fabric_pre_trainadv
//
void*    call_fabric_pre_trainadv( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_fabric_pre_trainadv entry" );

#if 0
    // @@@@@    CUSTOM BLOCK:   @@@@@
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)

    //  write HUID of target
    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "target HUID %.8X", TARGETING::get_huid(l));

    // cast OUR type of target to a FAPI type of target.
    const fapi::Target l_fapi_@targetN_target( TARGET_TYPE_MEMBUF_CHIP,
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
    return l_errl;
}



//
//  Wrapper function to call fabric_io_run_training
//
void*    call_fabric_io_run_training( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    IStepError  l_StepError;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_fabric_io_run_training entry" );

    TargetPairs_t l_PbusConnections;
    const uint32_t MaxBusSet = 2;

    // Note: Run XBUS first to match with Cronus
    TYPE busSet[MaxBusSet] = { TYPE_XBUS, TYPE_ABUS };

    for (uint32_t i = 0; l_StepError.isNull() && (i < MaxBusSet); i++)
    {
        l_errl = PbusLinkSvc::getTheInstance().getPbusConnections(
                                            l_PbusConnections, busSet[i] );

        if ( l_errl )
        {
            /*@
             * @errortype
             * @reasoncode  ISTEP_GET_PBUS_CONNECTIONS_FAILED
             * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid    ISTEP_FABRIC_IO_RUN_TRAINING
             * @userdata1   bytes 0-1: plid identifying first error
             *              bytes 2-3: reason code of first error
             * @userdata2   bytes 0-1: total number of elogs included
             *              bytes 2-3: N/A
             * @devdesc     call to fabric_io_run_training has failed
             *              see error log in the user details seciton for
             *              additional details.
             */
            l_StepError.addErrorDetails(ISTEP_GET_PBUS_CONNECTIONS_FAILED,
                                        ISTEP_FABRIC_IO_RUN_TRAINING,
                                        l_errl );

            errlCommit( l_errl, HWPF_COMP_ID );
        }

        for (TargetPairs_t::const_iterator l_itr = l_PbusConnections.begin();
             (l_StepError.isNull()) && (l_itr != l_PbusConnections.end());
             ++l_itr)
        {
            const fapi::Target l_fapi_endp1_target(
                   (i ? TARGET_TYPE_ABUS_ENDPOINT : TARGET_TYPE_XBUS_ENDPOINT),
                   (const_cast<TARGETING::Target*>(l_itr->first)));
            const fapi::Target l_fapi_endp2_target(
                   (i ? TARGET_TYPE_ABUS_ENDPOINT : TARGET_TYPE_XBUS_ENDPOINT),
                   (const_cast<TARGETING::Target*>(l_itr->second)));

            //  call the HWP with each bus connection
            FAPI_INVOKE_HWP( l_errl, fabric_io_run_training,
                             l_fapi_endp1_target, l_fapi_endp2_target );

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "%s : %cbus connection io_run_training",
                       (l_errl ? "ERROR" : "SUCCESS"),
                       (i ? 'A' : 'X') );

            if ( l_errl )
            {
                // capture the target data in the elog
                ErrlUserDetailsTarget(l_itr->first).addToLog( l_errl );
                ErrlUserDetailsTarget(l_itr->second).addToLog( l_errl );

                /*@
                 * @errortype
                 * @reasoncode  ISTEP_EDI_EI_INITIALIZATION_FAILED
                 * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid    ISTEP_FABRIC_IO_RUN_TRAINING
                 * @userdata1   bytes 0-1: plid identifying first error
                 *              bytes 2-3: reason code of first error
                 * @userdata2   bytes 0-1: total number of elogs included
                 *              bytes 2-3: N/A
                 * @devdesc     call to fabric_io_run_training has failed
                 *              see error log in the user details seciton for
                 *              additional details.
                 */
                l_StepError.addErrorDetails(ISTEP_EDI_EI_INITIALIZATION_FAILED,
                                            ISTEP_FABRIC_IO_RUN_TRAINING,
                                            l_errl );

                errlCommit( l_errl, HWPF_COMP_ID );
            }
        }
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_fabric_io_run_training exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}



//
//  Wrapper function to call fabric_post_trainadv
//
void*    call_fabric_post_trainadv( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_fabric_post_trainadv entry" );

#if 0
    // @@@@@    CUSTOM BLOCK:   @@@@@
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)

    //  write HUID of target
    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "target HUID %.8X", TARGETING::get_huid(l));

    // cast OUR type of target to a FAPI type of target.
    const fapi::Target l_fapi_@targetN_target( TARGET_TYPE_MEMBUF_CHIP,
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
    return l_errl;
}



//
//  Wrapper function to call host_startprd_pbus
//
void*    call_host_startprd_pbus( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_startprd_pbus entry" );

    l_errl = PRDF::initialize();

    if (l_errl)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "Error returned from call to PRDF::initialize");
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_startprd_pbus exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_errl;
}



//
//  Wrapper function to call host_attnlisten_proc
//
void*    call_host_attnlisten_proc( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_attnlisten_proc entry" );

#if 0
    // @@@@@    CUSTOM BLOCK:   @@@@@
    //  figure out what targets we need
    //  customize any other inputs
    //  set up loops to go through all targets (if parallel, spin off a task)

    //  write HUID of target
    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "target HUID %.8X", TARGETING::get_huid(l));

    // cast OUR type of target to a FAPI type of target.
    const fapi::Target l_fapi_@targetN_target( TARGET_TYPE_MEMBUF_CHIP,
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
    return l_errl;
}



//
//  Wrapper function to call proc_fab_iovalid
//
void*    call_proc_fab_iovalid( void    *io_pArgs )
{
    errlHndl_t l_errl = NULL;

    IStepError l_StepError;

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

    if ( l_errl )
    {
        /*@
         * @errortype
         * @reasoncode  ISTEP_GET_PBUS_CONNECTIONS_FAILED
         * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid    ISTEP_PROC_FAB_IOVALID
         * @userdata1   bytes 0-1: plid identifying first error
         *              bytes 2-3: reason code of first error
         * @userdata2   bytes 0-1: total number of elogs included
         *              bytes 2-3: N/A
         * @devdesc     call to fabric_io_run_training has failed
         *              see error log in the user details seciton for
         *              additional details.
         */
        l_StepError.addErrorDetails(ISTEP_GET_PBUS_CONNECTIONS_FAILED,
                                    ISTEP_PROC_FAB_IOVALID,
                                    l_errl );

        errlCommit( l_errl, HWPF_COMP_ID );
    }

    std::vector<proc_fab_iovalid_proc_chip> l_smp;

    for (TargetHandleList::const_iterator l_cpu_iter = l_cpuTargetList.begin();
         l_StepError.isNull() && (l_cpu_iter != l_cpuTargetList.end());
         ++l_cpu_iter)
    {
        proc_fab_iovalid_proc_chip l_procEntry;

        TARGETING::TargetHandle_t l_pTarget = *l_cpu_iter;
        fapi::Target l_fapiproc_target( TARGET_TYPE_PROC_CHIP, l_pTarget);

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

        for (TargetHandleList::const_iterator l_abus_iter = l_abuses.begin();
            l_abus_iter != l_abuses.end();
            ++l_abus_iter)
        {
            TARGETING::TargetHandle_t l_target = *l_abus_iter;
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

        for (TargetHandleList::const_iterator l_xbus_iter = l_xbuses.begin();
            l_xbus_iter != l_xbuses.end();
            ++l_xbus_iter)
        {
            TARGETING::TargetHandle_t l_target = *l_xbus_iter;
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

    if (!l_errl)
    {
        FAPI_INVOKE_HWP( l_errl, proc_fab_iovalid, l_smp, true );

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "%s : proc_fab_iovalid HWP.",
                (l_errl ? "ERROR" : "SUCCESS"));
    }

    if (l_errl)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR : call_proc_fab_iovalid encountered an error");
        /*@
         * @errortype
         * @reasoncode       ISTEP_EDI_EI_INITIALIZATION_FAILED
         * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid         ISTEP_PROC_FAB_IOVALID
         * @userdata1        bytes 0-1: plid identifying first error
         *                   bytes 2-3: reason code of first error
         * @userdata2        bytes 0-1: total number of elogs included
         *                   bytes 2-3: N/A
         * @devdesc          call to proc_fab_iovalid has failed
         */
        l_StepError.addErrorDetails(ISTEP_EDI_EI_INITIALIZATION_FAILED,
                                    ISTEP_PROC_FAB_IOVALID,
                                    l_errl );

        errlCommit( l_errl, HWPF_COMP_ID );

    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_fab_iovalid exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

//
//  function to unfence inter-enclosure abus links
//
errlHndl_t  smp_unfencing_inter_enclosure_abus_links()
{
    errlHndl_t l_errl = NULL;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "smp_unfencing_inter_enclosure_abus_links entry" );

    // Get all chip/chiplet targets
    TARGETING::TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TYPE_PROC);

    std::vector<proc_fab_iovalid_proc_chip> l_smp;

    for (TargetHandleList::const_iterator l_cpu_iter = l_cpuTargetList.begin();
         l_cpu_iter != l_cpuTargetList.end();
         ++l_cpu_iter)
    {
        proc_fab_iovalid_proc_chip l_procEntry;

        TARGETING::TargetHandle_t l_pTarget = *l_cpu_iter;
        fapi::Target l_fapiproc_target(TARGET_TYPE_PROC_CHIP, l_pTarget);

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

        for (TargetHandleList::const_iterator l_abus_iter = l_abuses.begin();
            l_abus_iter != l_abuses.end();
            ++l_abus_iter)
        {
            TARGETING::TargetHandle_t l_pAbusTarget = *l_abus_iter;
            ATTR_CHIP_UNIT_type l_srcID;
            ATTR_IS_INTER_ENCLOSURE_BUS_type l_flag;
            l_srcID = l_pAbusTarget->getAttr<ATTR_CHIP_UNIT>();
            l_flag = l_pAbusTarget->getAttr<ATTR_IS_INTER_ENCLOSURE_BUS>();
            switch (l_srcID)
            {
                case 0: l_procEntry.a0 = l_flag ? true : false; break;
                case 1: l_procEntry.a1 = l_flag ? true : false; break;
                case 2: l_procEntry.a2 = l_flag ? true : false; break;
               default: break;
            }
        }

        l_smp.push_back(l_procEntry);
    }

    FAPI_INVOKE_HWP( l_errl, proc_fab_iovalid, l_smp, true );

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "%s : proc_fab_iovalid HWP.",
                (l_errl ? "ERROR" : "SUCCESS"));

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "smp_unfencing_inter_enclosure_abus_links exit" );

    return l_errl;
}

};   // end namespace
