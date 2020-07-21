/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep12/call_omi_post_trainadv.C $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
 * @file    call_omi_post_trainadv.C
 *
 *  Support file for Istep 12.9 OMI post train routines
 *      p10_io_omi_post_trainadv
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

#include    <fapi2/plat_hwp_invoker.H>

//HWP
#include    <p10_io_omi_post_trainadv.H>


using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ISTEPS_TRACE;
using   namespace   TARGETING;

namespace ISTEP_12
{

void* call_omi_post_trainadv (void *io_pArgs)
{
    IStepError l_StepError;
    errlHndl_t l_err = nullptr;

    TargetHandleList l_procTargetList;
    getAllChips(l_procTargetList, TYPE_PROC);
    TRACFCOMP( g_trac_isteps_trace, "call_omi_post_trainadv entry. "
        "%d PROCs found", l_procTargetList.size());

    // 12.9.a p10_io_omi_post_trainadv.C
    //        - Debug routine for IO characterization
    for (const auto & l_proc_target : l_procTargetList)
    {
        TRACFCOMP( g_trac_isteps_trace,
            "p10_io_omi_post_trainadv HWP target HUID 0x%.8x",
            get_huid(l_proc_target));

        //  call the HWP with each target
        fapi2::Target <fapi2::TARGET_TYPE_PROC_CHIP> l_fapi_proc_target
                (l_proc_target);

        FAPI_INVOKE_HWP(l_err, p10_io_omi_post_trainadv, l_fapi_proc_target);

        //  process return code.
        if ( l_err )
        {
            TRACFCOMP( g_trac_isteps_trace,
                "ERROR : call p10_io_omi_post_trainadv HWP(): failed on "
                "target 0x%08X. " TRACE_ERR_FMT,
                get_huid(l_proc_target),
                TRACE_ERR_ARGS(l_err));

            // Capture error
            captureError(l_err, l_StepError, HWPF_COMP_ID, l_proc_target);
        }
        else
        {
            TRACFCOMP( g_trac_isteps_trace,
                     "SUCCESS : p10_io_omi_post_trainadv HWP");
        }
    }

    // Beyond this point, scoms to the OCMBs should be working, so clear the
    // ATTR_ATTN_POLL_PLID attribute since attention won't need to check the
    // PRD_HWP_PLID attribute before scomming the OCMBs anymore.
    TargetHandle_t sys = nullptr;
    targetService().getTopLevelTarget(sys);
    assert(sys != nullptr);
    sys->setAttr<ATTR_ATTN_POLL_PLID>(0);

    TRACFCOMP( g_trac_isteps_trace, "call_omi_post_trainadv exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

};
