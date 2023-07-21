/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep12/call_omi_post_trainadv.C $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2023                        */
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
#include    <targeting/odyutil.H>
#include    <ocmbupd/ocmbupd.H>

#include    <initservice/isteps_trace.H>
#include    <istepHelperFuncs.H>          // captureError
#include    <hwpThreadHelper.H>

#include    <fapi2/plat_hwp_invoker.H>

//HWP
#include    <p10_io_omi_post_trainadv.H>

#include    <chipids.H>                     // POWER_CHIPID::ODYSSEY_16

#include    <sbeio/sbeioif.H>

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ISTEPS_TRACE;
using   namespace   TARGETING;
using   namespace   SBEIO;

namespace ISTEP_12
{

void* call_omi_post_trainadv (void *io_pArgs)
{
    IStepError l_StepError;
    errlHndl_t l_err = nullptr;
    bool err_occurred = false;

    TargetHandleList l_procTargetList;
    getAllChips(l_procTargetList, TYPE_PROC);
    TRACISTEP("call_omi_post_trainadv entry. %d PROCs found", l_procTargetList.size());

    const auto l_runOdyHwpFromHost =
       TARGETING::UTIL::assertGetToplevelTarget()->getAttr<ATTR_RUN_ODY_HWP_FROM_HOST>();

    do
    {

    // 12.9.a p10_io_omi_post_trainadv.C
    //        - Debug routine for IO characterization
    for (const auto l_proc_target : l_procTargetList)
    {
        TRACISTEP("p10_io_omi_post_trainadv HWP target HUID 0x%.8x",
                  get_huid(l_proc_target));

        //  call the HWP with each target
        fapi2::Target <fapi2::TARGET_TYPE_PROC_CHIP> l_fapi_proc_target
                (l_proc_target);

        FAPI_INVOKE_HWP(l_err, p10_io_omi_post_trainadv, l_fapi_proc_target);

        if ( l_err )
        {
            TRACISTEP("ERROR : call p10_io_omi_post_trainadv HWP(): failed on "
                      "target 0x%08X. "
                      TRACE_ERR_FMT,
                      get_huid(l_proc_target),
                      TRACE_ERR_ARGS(l_err));

            err_occurred = true; // break out of the istep early below
                                 // after processing the rest of the
                                 // targets
            ocmbupd::captureErrorOcmbUpdateCheck(l_err, l_StepError, HWPF_COMP_ID, l_proc_target);
        }
        else
        {
            TRACISTEP("SUCCESS : p10_io_omi_post_trainadv HWP");
        }
    }

    if (err_occurred)
    {
        break;
    }

    // 12.9.b ody_io_omi_post_trainadv.C
    //        - Debug routine for IO characterization
    for (const auto l_proc_target : l_procTargetList)
    {
        TRACISTEP("ody_io_omi_post_trainadv processor 0x%.8x",
                  get_huid(l_proc_target));

        for (const auto ocmb : composable(getChildAffinityTargets)(l_proc_target, CLASS_NA, TYPE_OCMB_CHIP, true))
        {
            if (!UTIL::isOdysseyChip(ocmb))
            {
                continue;
            }

            if (l_runOdyHwpFromHost)
            {
                /* This is not invoked, nor is it in plan.
                   RUN_ODY_HWP(call_omi_post_trainadv, l_StepError, l_err, ocmb,  ody_io_omi_post_trainadv, { ocmb });
                */
            }
            else
            {
                RUN_ODY_CHIPOP(call_omi_post_trainadv, l_StepError, l_err, ocmb, IO_ODY_OMI_POSTTRAIN_ADV);
            }

        ERROR_EXIT: // used by RUN_ODY_* above
            if (l_err)
            {
                HANDLE_ODY_HWP_ERROR(call_omi_post_trainadv, IO_ODY_OMI_POSTTRAIN_ADV, l_StepError, ocmb, l_err);
            }
        }
    }

    } while (false);

    TRACISTEP("call_omi_post_trainadv exit");

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

}
