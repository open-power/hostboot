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

//  fapi support
#include <fapi.H>
#include <fapiPlatHwpInvoker.H>

#include "slave_sbe.H"
#include "proc_revert_sbe_mcs_setup/proc_revert_sbe_mcs_setup.H"

namespace SLAVE_SBE
{
//
//  Wrapper function to call 6.8 :
//      proc_revert_sbe_mcs_setup
//
void call_proc_revert_sbe_mcs_setup(void *io_pArgs)
{
    errlHndl_t  l_errl = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_revert_sbe_mcs_setup entry" );

    // TODO
    // This currently fails on Simics because this touches a Murano chip
    // register that doesn't exist in the Venice chip. When Simcs supports
    // a Murano chip, this HWP can be executed. For now, just execute the
    // HWP on VPO
    TARGETING::Target * l_pSysTarget = NULL;
    TARGETING::targetService().getTopLevelTarget(l_pSysTarget);
    uint8_t l_vpoMode = l_pSysTarget->getAttr<TARGETING::ATTR_IS_SIMULATION>();
    if (!l_vpoMode)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "INFO : not executing proc_revert_sbe_mcs_setup until murano chip in Simics");
    }
    else
    {
        TARGETING::Target* l_pProcTarget = NULL;
        TARGETING::targetService().masterProcChipTargetHandle(l_pProcTarget);

        fapi::Target l_fapiProcTarget(fapi::TARGET_TYPE_PROC_CHIP, l_pProcTarget);

        // Invoke the HWP
        FAPI_INVOKE_HWP(l_errl, proc_revert_sbe_mcs_setup, l_fapiProcTarget);

        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR : failed executing proc_revert_sbe_mcs_setup returning error");
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "SUCCESS : proc_revert_sbe_mcs_setup completed ok");
        }
    }

    TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "call_proc_revert_sbe_mcs_setup exit");

    // end task, returning any errorlogs to IStepDisp
    task_end2(l_errl);
}

}
