/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep12/call_proc_dmi_scominit.C $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>

//  targeting support.
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

//Fapi Support
#include    <config.h>
#include    <fapi2.H>
#include    <fapi2/plat_hwp_invoker.H>
#include    <util/utilmbox_scratch.H>

// HWP
#include    <p9_io_dmi_scominit.H>

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;


namespace ISTEP_12
{
void* call_proc_dmi_scominit (void *io_pArgs)
{
    IStepError l_StepError;
    errlHndl_t l_err = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_proc_dmi_scominit entry" );

    TARGETING::TargetHandleList l_dmiTargetList;
    getAllChiplets(l_dmiTargetList, TYPE_DMI);

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "call_proc_dmi_scominit: %d DMIs found",
            l_dmiTargetList.size());

    for (const auto & l_dmi_target : l_dmiTargetList)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "p9_io_dmi_scominit HWP target HUID %.8x",
            TARGETING::get_huid(l_dmi_target));

        //  call the HWP with each DMI target
        fapi2::Target<fapi2::TARGET_TYPE_DMI> l_fapi_dmi_target
            (l_dmi_target);

        FAPI_INVOKE_HWP(l_err, p9_io_dmi_scominit, l_fapi_dmi_target);

        //  process return code.
        if ( l_err )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR 0x%.8X:  p9_io_dmi_scominit HWP on target HUID %.8x",
                l_err->reasonCode(), TARGETING::get_huid(l_dmi_target) );

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_dmi_target).addToLog( l_err );

            // Create IStep error log and cross reference to error that occurred
            l_StepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, ISTEP_COMP_ID );
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                     "SUCCESS :  p9_io_dmi_scominit HWP");
        }

    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_proc_dmi_scominit exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

};
