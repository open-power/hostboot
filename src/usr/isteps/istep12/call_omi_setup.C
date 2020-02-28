/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep12/call_omi_setup.C $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
 * @file    call_omi_setup.C
 *
 *  Contains the wrapper for Istep 12.6 exp_omi_setup
 *
 */

#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>
#include    <istepHelperFuncs.H>          // captureError

// Fapi Support
#include    <config.h>
#include    <fapi2/plat_hwp_invoker.H>

// HWP
#include    <exp_omi_setup.H>

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   ISTEPS_TRACE;

namespace ISTEP_12
{
void* call_omi_setup (void *io_pArgs)
{
    IStepError l_StepError;
    errlHndl_t l_err = nullptr;
    TRACDCOMP( g_trac_isteps_trace, "call_omi_setup entry" );

    // 12.6.a exp_omi_setup.C
    //        - Set any register (via I2C) on the Explorer before OMI is trained
    TargetHandleList l_ocmbTargetList;
    getAllChips(l_ocmbTargetList, TYPE_OCMB_CHIP);
    TRACFCOMP(g_trac_isteps_trace,
              "call_omi_setup: %d OCMBs found",
              l_ocmbTargetList.size());

    for (const auto & l_ocmb_target : l_ocmbTargetList)
    {
        //  call the HWP with each target
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_ocmb_target
            (l_ocmb_target);

        TRACFCOMP(g_trac_isteps_trace,
                "exp_omi_setup HWP target HUID 0x%.08x",
                get_huid(l_ocmb_target));

        FAPI_INVOKE_HWP(l_err, exp_omi_setup, l_fapi_ocmb_target);

        //  process return code
        if ( l_err )
        {
            TRACFCOMP(g_trac_isteps_trace,
                 "ERROR : call exp_omi_setup HWP(): failed on target 0x%08X. "
                 TRACE_ERR_FMT,
                 get_huid(l_ocmb_target),
                 TRACE_ERR_ARGS(l_err));

            // Capture error
            captureError(l_err, l_StepError, HWPF_COMP_ID, l_ocmb_target);
        }
    }

    // 12.6.b p10_omi_setup.C
    //        - File does not currently exist
    //        - TODO: RTC 248244

    TRACFCOMP(g_trac_isteps_trace, "call_omi_setup exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

};
