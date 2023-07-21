/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep12/call_omi_pre_trainadv.C $              */
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
 * @file    call_omi_pre_trainadv.C
 *
 *  Support file for Istep 12.5 Debug routine for IO Characterization
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
#include    <hwpThread.H>
#include    <hwpThreadHelper.H>
#include    <ocmbupd_helpers.H>

#include    <fapi2/plat_hwp_invoker.H>

//HWP
#include    <chipids.H>
#include    <p10_io_omi_pre_trainadv.H>
#include    <ody_omi_hss_tx_zcal.H>
#include    <ody_omi_pretrain_adv.H>

#include    <sbeio/sbeioif.H>

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ISTEPS_TRACE;
using   namespace   TARGETING;
using   namespace   SBEIO;

#define CONTEXT call_omi_pre_trainadv

namespace ISTEP_12
{

void* call_omi_pre_trainadv (void *io_pArgs)
{
    IStepError l_StepError;

    do
    {

    // get RUN_ODY_HWP_FROM_HOST
    const auto l_runOdyHwpFromHost =
        TARGETING::UTIL::assertGetToplevelTarget()->getAttr<ATTR_RUN_ODY_HWP_FROM_HOST>();

    // 12.5.a ody_omi_hss_tx_zcal
    parallel_for_each<HwpWorkItem_OCMBUpdateCheck>(composable(getAllChips)(TYPE_OCMB_CHIP, true),
                                                   l_StepError,
                                                   "ody_omi_hss_tx_zcal",
                                                   [&](Target* const i_ocmb)
    {
        errlHndl_t errl = nullptr;

        if (UTIL::isOdysseyChip(i_ocmb))
        {

            if (l_runOdyHwpFromHost)
            {
                RUN_ODY_HWP(CONTEXT, l_StepError, errl, i_ocmb, ody_omi_hss_tx_zcal, { i_ocmb });
            }
            else
            {
                RUN_ODY_CHIPOP(CONTEXT, l_StepError, errl, i_ocmb, IO_ODY_OMI_HSS_TX_ZCAL);
            }
        }

    ERROR_EXIT: // label used by RUN_ODY_* above
        return errl;
    });

    if (HwpWorkItem::cv_encounteredHwpError)
    {
        TRACISTEP(INFO_MRK"call_omi_pre_trainadv exited early because ody_omi_hss_tx_zcal "
                  "had failures");
        break;
    }

    TargetHandleList l_procTargetList = composable(getAllChips)(TYPE_PROC, true);

    TRACISTEP(INFO_MRK"call_omi_pre_trainadv. %d PROCs found", l_procTargetList.size());

    // 12.5.b p10_io_omi_pre_trainadv.C
    //        - Debug routine for IO characterization
    for (const auto l_proc_target : l_procTargetList)
    {
        TRACISTEP(INFO_MRK"p10_io_omi_pre_trainadv HWP target HUID 0x%.8x ",
                  get_huid(l_proc_target));

        errlHndl_t errl = nullptr;
        FAPI_INVOKE_HWP(errl, p10_io_omi_pre_trainadv, { l_proc_target });

        if (errl)
        {
            TRACISTEP(ERR_MRK"call p10_io_omi_pre_trainadv HWP(): failed on "
                      "target 0x%08X. " TRACE_ERR_FMT,
                      get_huid(l_proc_target),
                      TRACE_ERR_ARGS(errl));

            captureError(errl, l_StepError, HWPF_COMP_ID, l_proc_target);
            break;
        }

        TRACISTEP(INFO_MRK"SUCCESS : p10_io_omi_pre_trainadv HWP ");
    }

    if (!l_StepError.isNull())
    {
        TRACISTEP(ERR_MRK"At least one call to p10_io_omi_pre_trainadv failed; skipping the rest of the IStep");
        break;
    }

    // 12.5.c ody_omi_pretrain_adv
    parallel_for_each<HwpWorkItem_OCMBUpdateCheck>(composable(getAllChips)(TYPE_OCMB_CHIP, true),
                                                   l_StepError,
                                                   "ody_omi_pretrain_adv",
                                                   [&](Target* const i_ocmb)
    {
        errlHndl_t errl = nullptr;

        if (UTIL::isOdysseyChip(i_ocmb))
        {

            if (l_runOdyHwpFromHost)
            {
                RUN_ODY_HWP(CONTEXT, l_StepError, errl, i_ocmb, ody_omi_pretrain_adv, { i_ocmb });
            }
            else
            {
                RUN_ODY_CHIPOP(CONTEXT, l_StepError, errl, i_ocmb, IO_ODY_OMI_PRETRAIN_ADV);
            }
        }

    ERROR_EXIT: // label used by RUN_ODY_* above
        return errl;
    });

    if (HwpWorkItem::cv_encounteredHwpError)
    {
        TRACISTEP(ERR_MRK"call_omi_pre_trainadv: ody_omi_pretrain_adv: error");
        break;
    }

    } while (false);

    TRACISTEP(EXIT_MRK"call_omi_pre_trainadv");

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

}
