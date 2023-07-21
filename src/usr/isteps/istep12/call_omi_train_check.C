/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep12/call_omi_train_check.C $               */
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
 * @file    call_omi_train_check.C
 *
 *  Contains the HWP wrapper for Istep 12.8
 *      exp_omi_train_check
 *      p10_omi_train_check
 */
#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>
#include    <istepHelperFuncs.H>    // captureError
#include    <hwpThread.H>
#include    <hwpThreadHelper.H>

#include    <util/misc.H>           // isSimicsRunning()

//Fapi Support
#include    <config.h>
#include    <fapi2.H>
#include    <fapi2/plat_hwp_invoker.H>

//HWP
#include    <p10_omi_train_check.H>
#include    <exp_omi_train_check.H>
#include    <ody_omi_train_check.H>
#include    <chipids.H>             // for EXPLORER ID

#include    <sbeio/sbeioif.H>

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   ISTEPS_TRACE;
using   namespace   SBEIO;

#define CONTEXT call_omi_train_check

namespace ISTEP_12
{

void* call_omi_train_check (void *io_pArgs)
{
    IStepError l_StepError;
    const auto sys = UTIL::assertGetToplevelTarget();

    TRACISTEP(ENTER_MRK"call_omi_train_check entry");

    do
    {

    // get RUN_ODY_HWP_FROM_HOST
    const auto l_runOdyHwpFromHost = sys->getAttr<ATTR_RUN_ODY_HWP_FROM_HOST>();

    // 12.8.a *_omi_train_check
    //        - Check for training errors
    parallel_for_each<HwpWorkItem_OCMBUpdateCheck>(composable(getAllChips)(TYPE_OCMB_CHIP, true),
                                                   l_StepError,
                                                   "exp/ody_omi_train_check",
                                                   [&](Target* const i_ocmb)
    {
        errlHndl_t l_err = nullptr;

        if (UTIL::isOdysseyChip(i_ocmb))
        {
            TRACISTEP("call_omi_train_check: Run ODY HWPs on target HUID 0x%.8X l_runOdyHwpFromHost:%d",
                      get_huid(i_ocmb), l_runOdyHwpFromHost);

            if (l_runOdyHwpFromHost)
            {
                RUN_ODY_HWP(CONTEXT, l_StepError, l_err, i_ocmb, ody_omi_train_check, { i_ocmb });
            }
            else
            {
                RUN_ODY_CHIPOP(CONTEXT, l_StepError, l_err, i_ocmb, IO_ODY_OMI_TRAIN_CHECK);
            }
        }
        else
        {
            FAPI_INVOKE_HWP(l_err, exp_omi_train_check, { i_ocmb });
        }

    ERROR_EXIT: // label is required by RUN_ODY_* above
        return l_err;
    });

    if (HwpWorkItem::cv_encounteredHwpError)
    {
        TRACISTEP(ERR_MRK"call_omi_train_check: *_omi_train_check returned an error");
        break;
    }

    // 12.8.b p10_omi_train_check.C
    //        - Check for training errors
    parallel_for_each<HwpWorkItem_OCMBUpdateCheck>(composable(getAllChiplets)(TYPE_OMI, true),
                                                   l_StepError,
                                                   "p10_omi_train_check",
                                                   [&](Target* const i_omi)
    {
        errlHndl_t l_err = nullptr;
        FAPI_INVOKE_HWP(l_err, p10_omi_train_check, { i_omi });
        return l_err;
    });

    if (HwpWorkItem::cv_encounteredHwpError)
    {
        TRACISTEP(ERR_MRK"call_omi_train_check: error for p10_omi_train_check");
        break;
    }

    } while (false);

    // Beyond this point, scoms to the OCMBs should be working, so clear the
    // ATTR_ATTN_POLL_PLID attribute since attention won't need to check the
    // PRD_HWP_PLID attribute before scomming the OCMBs anymore.
    sys->setAttr<ATTR_ATTN_POLL_PLID>(0);

    TRACISTEP(EXIT_MRK"call_omi_train_check exit");

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

}
