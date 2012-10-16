/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/slave_sbe/slave_sbe.C $
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

#include <hwpisteperror.H>
#include <errl/errludtarget.H>

//  fapi support
#include <fapi.H>
#include <fapiPlatHwpInvoker.H>

#include "slave_sbe.H"
#include "proc_revert_sbe_mcs_setup/proc_revert_sbe_mcs_setup.H"

using namespace ISTEP;
using namespace ISTEP_ERROR;
using namespace ERRORLOG;

namespace SLAVE_SBE
{
//
//  Wrapper function to call 6.8 :
//      proc_revert_sbe_mcs_setup
//
void* call_proc_revert_sbe_mcs_setup(void *io_pArgs)
{
    errlHndl_t  l_errl = NULL;

    IStepError  l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_revert_sbe_mcs_setup entry" );

    TARGETING::Target* l_pProcTarget = NULL;
    TARGETING::targetService().masterProcChipTargetHandle(l_pProcTarget);

    fapi::Target l_fapiProcTarget(fapi::TARGET_TYPE_PROC_CHIP, l_pProcTarget);

    // Invoke the HWP
    FAPI_INVOKE_HWP(l_errl, proc_revert_sbe_mcs_setup, l_fapiProcTarget);

    if (l_errl)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "ERROR : failed executing proc_revert_sbe_mcs_setup \
                   returning error");

        ErrlUserDetailsTarget myDetails(l_pProcTarget);

        // capture the target data in the elog
        myDetails.addToLog( l_errl );

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

}
