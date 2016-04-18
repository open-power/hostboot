/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep13/call_mem_pll_setup.C $                 */
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
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <isteps/hwpisteperror.H>
#include <initservice/isteps_trace.H>

//HWP Invoker
#include    <fapi2/plat_hwp_invoker.H>

//  targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/util.H>
#include <targeting/common/utilFilter.H>
#include <fapi2/target.H>

//From Import Directory (EKB Repository)
#include    <p9_mem_pll_setup.H>


using   namespace   ERRORLOG;
using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   TARGETING;

namespace ISTEP_13
{
void* call_mem_pll_setup (void *io_pArgs)
{
    errlHndl_t l_err = NULL;

    IStepError l_StepError;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mem_pll_setup entry" );

    // Get all Proc targets
    TARGETING::TargetHandleList l_procTargetList;
    getAllChips(l_procTargetList, TYPE_PROC);

    for (const auto & l_procChip: l_procTargetList)
    {

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "Running p9_mem_pll_setup HWP on "
            "target HUID %.8X", TARGETING::get_huid(l_procChip));

        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
          l_fapi2_procChip( l_procChip);
//@TODO RTC:152210 Enable Istep 13 HWPs that are waiting on mirrored files
        //call cen_mem_pll_setup to verify lock
//         FAPI_INVOKE_HWP(l_err, p9_mem_pll_setup, l_fapi2_procChip);

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X: p9_mem_pll_setup HWP returns error",
                      l_err->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_procChip).addToLog(l_err);

            //Create IStep error log and cross reference to error that occurred
            l_StepError.addErrorDetails(l_err);

            // Commit Error
            errlCommit(l_err, HWPF_COMP_ID);
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "SUCCESS: p9_mem_pll_setup HWP( )" );
        }
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mem_pll_setup exit" );

    return l_StepError.getErrorHandle();
}

};
