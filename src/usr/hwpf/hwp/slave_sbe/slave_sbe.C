/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/slave_sbe/slave_sbe.C $                      */
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
 *  @file slave_sbe.C
 *
 *  Support file for IStep: slave_sbe
 *   Slave SBE
 *
 *  HWP_IGNORE_VERSION_CHECK
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include <stdint.h>

#include <trace/interface.H>
#include <initservice/taskargs.H>
#include <errl/errlentry.H>
#include <initservice/isteps_trace.H>

//  targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include    <targeting/namedtarget.H>
#include    <targeting/attrsync.H>

#include <hwpisteperror.H>
#include <errl/errludtarget.H>

//  fapi support
#include <fapi.H>
#include <fapiPlatHwpInvoker.H>

#include "slave_sbe.H"
#include "proc_revert_sbe_mcs_setup/proc_revert_sbe_mcs_setup.H"
#include "proc_check_slave_sbe_seeprom_complete.H"

using namespace ISTEP;
using namespace ISTEP_ERROR;
using namespace ERRORLOG;
using namespace TARGETING;

namespace SLAVE_SBE
{

//******************************************************************************
// call_proc_revert_sbe_mcs_setup function
//******************************************************************************
void* call_proc_revert_sbe_mcs_setup(void *io_pArgs)
{
    errlHndl_t  l_errl = NULL;
    IStepError  l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_revert_sbe_mcs_setup entry" );

    // Note: Even though Cronus trace shows this HWP runs on all proc,
    // this should be done only for Master chip per Dean.

    TARGETING::Target* l_pProcTarget = NULL;
    TARGETING::targetService().masterProcChipTargetHandle(l_pProcTarget);

    fapi::Target l_fapiProcTarget(fapi::TARGET_TYPE_PROC_CHIP, l_pProcTarget);

    // Invoke the HWP
    FAPI_INVOKE_HWP(l_errl, proc_revert_sbe_mcs_setup, l_fapiProcTarget);

    if (l_errl)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "ERROR : failed executing proc_revert_sbe_mcs_setup "
                  "returning error");

        // capture the target data in the elog
        ErrlUserDetailsTarget(l_pProcTarget).addToLog( l_errl );

        /*@
         * @errortype
         * @reasoncode  ISTEP_SLAVE_SBE_FAILED
         * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid    ISTEP_PROC_REVERT_SBE_MCS_SETUP
         * @userdata1   bytes 0-1: plid identifying first error
         *              bytes 2-3: reason code of first error
         * @userdata2   bytes 0-1: total number of elogs included
         *              bytes 2-3: N/A
         * @devdesc     call to proc_revert_sbe_mcs_setup returned an error
         *
         */
        l_stepError.addErrorDetails(ISTEP_SLAVE_SBE_FAILED,
                                    ISTEP_PROC_REVERT_SBE_MCS_SETUP,
                                    l_errl );

        errlCommit( l_errl, HWPF_COMP_ID );
    }
    else
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "SUCCESS : proc_revert_sbe_mcs_setup completed ok");
    }

    TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "call_proc_revert_sbe_mcs_setup exit");

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}


//******************************************************************************
// call_host_slave_sbe function
//******************************************************************************
void* call_host_slave_sbe_config(void *io_pArgs)
{
    errlHndl_t l_errl = NULL;
    IStepError  l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_slave_sbe_config entry" );

    // execute proc_read_nest_freq.C
    // execute proc_setup_sbe_config.C

    l_errl  =   NULL;       // assignment to make the compiler happy

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_slave_sbe_config exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();

}

//******************************************************************************
// call_host_sbe_start function
//******************************************************************************
void* call_host_sbe_start( void *io_pArgs )
{
    errlHndl_t  l_errl = NULL;
    IStepError  l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_host_sbe_start entry" );

    // call proc_sbe_start.C
    l_errl  =   NULL;       // assignment to make the compiler happy

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_host_sbe_start exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}


//******************************************************************************
// call_proc_check_slave_sbe_seeprom_complete function
//******************************************************************************
void* call_proc_check_slave_sbe_seeprom_complete( void *io_pArgs )
{
    errlHndl_t  l_errl = NULL;
    IStepError  l_stepError;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_check_slave_sbe_seeprom_complete entry" );

    //
    //  get the master Proc target, we want to IGNORE this one.
    //
    TARGETING::Target* l_pMasterProcTarget = NULL;
    TARGETING::targetService().masterProcChipTargetHandle(l_pMasterProcTarget);

    //
    //  get a list of all the procs in the system
    //
    TARGETING::TargetHandleList l_procTargetList;
    getAllChips(l_procTargetList, TYPE_PROC);

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
        "proc_check_slave_sbe_seeprom_complete: %d procs in the system.",
        l_procTargetList.size() );

    // loop thru all the cpu's
    for (TargetHandleList::const_iterator
            l_proc_iter = l_procTargetList.begin();
            l_proc_iter != l_procTargetList.end();
            ++l_proc_iter)
    {
        //  make a local copy of the Processor target
        TARGETING::Target* l_pProcTarget = *l_proc_iter;

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "target HUID %.8X", TARGETING::get_huid(l_pProcTarget));

        if ( l_pProcTarget  ==  l_pMasterProcTarget )
        {
            // we are just checking the Slave SBE's, skip the master
            continue;
        }

        fapi::Target l_fapiProcTarget( fapi::TARGET_TYPE_PROC_CHIP,
                                       l_pProcTarget    );

        // Invoke the HWP
        FAPI_INVOKE_HWP(l_errl,
                        proc_check_slave_sbe_seeprom_complete,
                        l_fapiProcTarget);

        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR : proc_check_slave_sbe_seeprom_complete",
                      "failed, returning errorlog" );

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_pProcTarget).addToLog( l_errl );

            /*@
             * @errortype
             * @reasoncode  ISTEP_SLAVE_SBE_FAILED
             * @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid    ISTEP_PROC_CHECK_SLAVE_SBE_SEEPROM_COMPLETE
             * @userdata1   bytes 0-1: plid identifying first error
             *              bytes 2-3: reason code of first error
             * @userdata2   bytes 0-1: total number of elogs included
             *              bytes 2-3: N/A
             * @devdesc     call to proc_check_slave_sbe_seeprom_complete
             *              returned an error
             *
             */
            l_stepError.addErrorDetails(
                            ISTEP_SLAVE_SBE_FAILED,
                            ISTEP_PROC_CHECK_SLAVE_SBE_SEEPROM_COMPLETE,
                            l_errl );

            errlCommit( l_errl, HWPF_COMP_ID );
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "SUCCESS : proc_check_slave_sbe_seeprom_complete",
                      "completed ok");

        }
    }   // endfor

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "call_proc_check_slave_sbe_seeprom_complete exit");

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}

//******************************************************************************
// call_proc_xmit_sbe
//******************************************************************************
void* call_proc_xmit_sbe(void *io_pArgs )
{
    errlHndl_t  l_errl = NULL;
    IStepError  l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_xmit_sbe entry" );

    // call proc_xmit_sbe.C
    l_errl  =   NULL;       // assignment to make the compiler happy

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_xmit_sbe exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}


}
