/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep12/call_omi_io_run_training.C $           */
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
 * @file    call_omi_io_run_training.C
 *
 *  Contains the HWP wrapper for Istep 12.7
 *      exp_omi_train
 *      p10_omi_train
 */
#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>
#include    <istepHelperFuncs.H>        // captureError
#include    <hwpThread.H>
#include    <hwpThreadHelper.H>

//Fapi Support
#include    <config.h>
#include    <fapi2.H>
#include    <fapi2/plat_hwp_invoker.H>

//HWP
#include    <ody_omi_train.H>
#include    <exp_omi_train.H>
#include    <p10_omi_train.H>
#include    <chipids.H>                 // for EXPLORER ID

#include    <sbeio/sbeioif.H>

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   ISTEPS_TRACE;
using   namespace   SBEIO;

namespace ISTEP_12
{

#define CONTEXT call_omi_io_run_training

void* call_omi_io_run_training (void *io_pArgs)
{
    IStepError l_StepError;
    TRACISTEP(ENTER_MRK"call_omi_io_run_training");

    do
    {

    const auto l_runOdyHwpFromHost =
        UTIL::assertGetToplevelTarget()->getAttr<ATTR_RUN_ODY_HWP_FROM_HOST>();

    // Starting beginning at this istep, we may be unable to scom the OCMBs
    // until the next istep is complete, except in certain cases where the
    // hardware procedure fails. Set ATTR_ATTN_POLL_PLID so ATTN knows to
    // poll the PRD_HWP_PLID before scomming the OCMBs.
    UTIL::assertGetToplevelTarget()->setAttr<ATTR_ATTN_POLL_PLID>(1);

    // 12.7.a *_omi_train.C
    parallel_for_each<HwpWorkItem_OCMBUpdateCheck>(composable(getAllChips)(TYPE_OCMB_CHIP, true),
                                                   l_StepError,
                                                   "exp/ody_omi_train",
                                                   [&](Target* const i_ocmb)
    {
        errlHndl_t l_err = nullptr;

        if (UTIL::isOdysseyChip(i_ocmb))
        {
            if (l_runOdyHwpFromHost)
            {
                RUN_ODY_HWP(CONTEXT, l_StepError, l_err, i_ocmb, ody_omi_train, { i_ocmb });
            }
            else
            {
                RUN_ODY_CHIPOP(CONTEXT, l_StepError, l_err, i_ocmb, IO_ODY_OMI_TRAIN);
            }
        }
        else
        {
            FAPI_INVOKE_HWP(l_err, exp_omi_train, { i_ocmb });
        }

    ERROR_EXIT: // used by RUN_ODY_* above
        return l_err;
    });

    if (HwpWorkItem::cv_encounteredHwpError)
    {
        TRACISTEP(INFO_MRK"call_omi_io_run_training exited early because *_omi_train had failures");
        break;
    }

    // 12.7.b p10_omi_train.C
    parallel_for_each<HwpWorkItem_OCMBUpdateCheck>(composable(getAllChiplets)(TYPE_OMIC, true),
                                                   l_StepError,
                                                   "p10_omi_train",
                                                   [&](Target* const i_omic)
    {
        errlHndl_t l_err = nullptr;
        FAPI_INVOKE_HWP(l_err, p10_omi_train, { i_omic });
        return l_err;
    });

    if (HwpWorkItem::cv_encounteredHwpError)
    {
        TRACISTEP(ERR_MRK"call_omi_io_run_training: error for p10_omi_train");
        break;
    }

    } while (false);

    TRACISTEP(EXIT_MRK"call_omi_io_run_training");

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

}
