/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep12/call_proc_dmi_scominit.C $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
#include    <errl/errlentry.H>
#include    <errl/errlmanager.H>
#include    <initservice/isteps_trace.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

//  targeting support.
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;

namespace ISTEP_12
{
void* call_proc_dmi_scominit (void *io_pArgs)
{
    errlHndl_t l_errl = NULL;
    IStepError l_StepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_proc_dmi_scominit entry" );

    // Get all functional MCS chiplets
    TARGETING::TargetHandleList l_mcsTargetList;
    getAllChiplets(l_mcsTargetList, TYPE_MCS);

    // Invoke dmi_scominit on each one
    for (TargetHandleList::const_iterator
            l_mcs_iter = l_mcsTargetList.begin();
            l_mcs_iter != l_mcsTargetList.end();
            ++l_mcs_iter)
    {
        const TARGETING::Target* l_pTarget = *l_mcs_iter;

        //@TODO RTC:133831
        /*
        const fapi::Target l_fapi_target( TARGET_TYPE_MCS_CHIPLET,
                (const_cast<TARGETING::Target*>(l_pTarget)));

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "Running proc_dmi_scominit HWP on "
                "target HUID %.8X", TARGETING::get_huid(l_pTarget));

        FAPI_INVOKE_HWP(l_errl, proc_dmi_scominit, l_fapi_target);
        */
        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "ERROR 0x%.8X : proc_dmi_scominit HWP returns error",
                        l_errl->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_pTarget).addToLog( l_errl );

            break;
        }
        else
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "SUCCESS :  proc_dmi_scominit HWP");
        }
    }

    if( l_errl )
    {

        // Create IStep error log and cross reference error that occurred
        l_StepError.addErrorDetails( l_errl);

        // Commit Error
        errlCommit( l_errl, HWPF_COMP_ID );
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_proc_dmi_scominit exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

};
