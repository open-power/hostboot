/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep09/call_proc_fab_iovalid.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/**
 *  @file call_proc_fab_iovalid.C
 *
 *  Support file for IStep: edi_ei_initialization
 *   EDI, EI Initialization
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

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>

#include    <hwas/common/deconfigGard.H>
#include    <hwas/common/hwasCommon.H>

#include    <sbe/sbeif.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/common/trace.H>

#include <fapi2/target.H>
#include <fapi2/plat_hwp_invoker.H>
#include <errl/errlmanager.H>

// HWP
#include <p9_fab_iovalid.H>

namespace   ISTEP_09
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   HWAS;
//
//  Wrapper function to call proc_fab_iovalid
//
void*    call_proc_fab_iovalid( void    *io_pArgs )
{
    IStepError l_StepError;
    errlHndl_t l_errl = NULL;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_fab_iovalid entry" );

    //
    //  get a list of all the procs in the system
    //
    TARGETING::TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TYPE_PROC);

    // Loop through all processors including master
    for (const auto & l_cpu_target: l_cpuTargetList)
    {
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>l_fapi2_proc_target(
                  l_cpu_target);

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                 "Running p9_fab_iovalid HWP on processor target %.8X",
                 TARGETING::get_huid(l_cpu_target) );

        FAPI_INVOKE_HWP(l_errl, p9_fab_iovalid, l_fapi2_proc_target, true);
        if(l_errl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                     "ERROR 0x%.8X : p9_fab_iovalid "
                     "HWP returns error for HUID %.8X",
                     l_errl->reasonCode(),
                     TARGETING::get_huid(l_cpu_target) );

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_cpu_target).addToLog( l_errl );

            l_StepError.addErrorDetails(l_errl);
            errlCommit(l_errl, HWPF_COMP_ID);
            l_errl = NULL;
        }
    } // end of going through all processors//

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_fab_iovalid exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}
};   // end namespace
