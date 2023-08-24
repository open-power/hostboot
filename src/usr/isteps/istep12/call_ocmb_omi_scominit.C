/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep12/call_ocmb_omi_scominit.C $             */
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
 * @file    call_ocmb_omi_scominit.C
 *
 *  Support file for Istep 12.4 Explorer specific inits
 *
 */
#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>
#include    <hwpThread.H>
#include    <hwpThreadHelper.H>
#include    <ocmbupd_helpers.H>

//  targeting support.
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

//Fapi Support
#include    <config.h>
#include    <fapi2.H>

#include    <sbeio/sbeioif.H>

#include    <chipids.H>

#include    <ody_omi_hss_ppe_load.H>
#include    <ody_omi_hss_config.H>
#include    <ody_omi_hss_ppe_start.H>
#include    <ody_omi_hss_bist_init.H>
#include    <ody_omi_hss_bist_start.H>
#include    <ody_omi_hss_bist_poll.H>
#include    <ody_omi_hss_bist_cleanup.H>
#include    <ody_omi_hss_init.H>
#include    <ody_omi_hss_dccal_start.H>
#include    <ody_omi_hss_dccal_poll.H>

#include    <isteps/istepmasterlist.H>

using   namespace   ISTEP;
using   namespace   ISTEPS_TRACE;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   SBEIO;

#define CONTEXT call_ocmb_omi_scominit

namespace ISTEP_12
{

errlHndl_t run_ocmb_omi_scominit( istep_12_4_ody_omi_hss_hwp i_hwpNumber )
{
    IStepError l_StepError;

    const auto l_runOdyHwpFromHost =
       TARGETING::UTIL::assertGetToplevelTarget()->getAttr<ATTR_RUN_ODY_HWP_FROM_HOST>();

    parallel_for_each<HwpWorkItem_OCMBUpdateCheck>(composable(getAllChips)(TYPE_OCMB_CHIP, true),
                                                   l_StepError,
                                                   "exp/ody_omi_scominit",
                                                   [&](Target* const i_ocmb)
    {
        errlHndl_t l_err = nullptr;
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_target(i_ocmb);

        if (UTIL::isOdysseyChip(i_ocmb))
        {
            TRACISTEP("run_ocmb_omi_scominit: Run ODY HWPs on target HUID 0x%.8X "
                      "l_runOdyHwpFromHost:%d",
                      get_huid(i_ocmb), l_runOdyHwpFromHost);

            if (l_runOdyHwpFromHost)
            {
                /*
                 * @TODO JIRA: PFHB-418 This requires additional parameters to the hwp
                 *
                 if (i_hwpNumber & ODY_OMI_HSS_LOAD_PPE)
                 {
                 uint8_t *i_img_data;
                 uint32_t i_img_size;
                 uint32_t i_offset;
                 IO_PPE_Image_Type_t i_type;

                 RUN_SUB_HWP(CONTEXT,
                             l_StepError,
                             l_err,
                             i_ocmb,
                             ody_omi_hss_ppe_load,
                             l_fapi_target,
                             i_img_data,
                             i_img_size,
                             i_offset,
                             i_type);
                 }
                */
                if (i_hwpNumber & ODY_OMI_HSS_CONFIG)
                {
                    RUN_ODY_HWP(CONTEXT, l_StepError, l_err, i_ocmb, ody_omi_hss_config, l_fapi_target);
                }
                if (i_hwpNumber & ODY_OMI_HSS_START_PPE)
                {
                    RUN_ODY_HWP(CONTEXT, l_StepError, l_err, i_ocmb, ody_omi_hss_ppe_start, l_fapi_target);
                }
                if (i_hwpNumber & ODY_OMI_HSS_BIST_INIT)
                {
                    RUN_ODY_HWP(CONTEXT, l_StepError, l_err, i_ocmb, ody_omi_hss_bist_init, l_fapi_target);
                }
                if (i_hwpNumber & ODY_OMI_HSS_BIST_START)
                {
                    RUN_ODY_HWP(CONTEXT, l_StepError, l_err, i_ocmb, ody_omi_hss_bist_start, l_fapi_target);
                }
                if (i_hwpNumber & ODY_OMI_HSS_BIST_POLL)
                {
                    RUN_ODY_HWP(CONTEXT, l_StepError, l_err, i_ocmb, ody_omi_hss_bist_poll, l_fapi_target);
                }
                if (i_hwpNumber & ODY_OMI_HSS_BIST_CLEANUP)
                {
                    RUN_ODY_HWP(CONTEXT, l_StepError, l_err, i_ocmb, ody_omi_hss_bist_cleanup, l_fapi_target);
                }
                if (i_hwpNumber & ODY_OMI_HSS_INIT)
                {
                    RUN_ODY_HWP(CONTEXT, l_StepError, l_err, i_ocmb, ody_omi_hss_init, l_fapi_target);
                }
                if (i_hwpNumber & ODY_OMI_HSS_DCCAL_START)
                {
                    RUN_ODY_HWP(CONTEXT, l_StepError, l_err, i_ocmb, ody_omi_hss_dccal_start, l_fapi_target);
                }
                if (i_hwpNumber & ODY_OMI_HSS_DCCAL_POLL)
                {
                    RUN_ODY_HWP(CONTEXT, l_StepError, l_err, i_ocmb, ody_omi_hss_dccal_poll, l_fapi_target);
                }
            }
            else
            {
                if (i_hwpNumber & ODY_OMI_HSS_LOAD_PPE)
                {
                    RUN_ODY_CHIPOP(CONTEXT, l_StepError, l_err, i_ocmb, IO_ODY_OMI_HSS_LOAD_PPE);
                }
                if (i_hwpNumber & ODY_OMI_HSS_CONFIG)
                {
                    RUN_ODY_CHIPOP(CONTEXT, l_StepError, l_err, i_ocmb, IO_ODY_OMI_HSS_CONFIG);
                }
                if (i_hwpNumber & ODY_OMI_HSS_START_PPE)
                {
                    RUN_ODY_CHIPOP(CONTEXT, l_StepError, l_err, i_ocmb, IO_ODY_OMI_HSS_START_PPE);
                }
                if (i_hwpNumber & ODY_OMI_HSS_BIST_INIT)
                {
                    RUN_ODY_CHIPOP(CONTEXT, l_StepError, l_err, i_ocmb, IO_ODY_OMI_HSS_BIST_INIT);
                }
                if (i_hwpNumber & ODY_OMI_HSS_BIST_START)
                {
                    RUN_ODY_CHIPOP(CONTEXT, l_StepError, l_err, i_ocmb, IO_ODY_OMI_HSS_BIST_START);
                }
                if (i_hwpNumber & ODY_OMI_HSS_BIST_POLL)
                {
                    RUN_ODY_CHIPOP(CONTEXT, l_StepError, l_err, i_ocmb, IO_ODY_OMI_HSS_BIST_POLL);
                }
                if (i_hwpNumber & ODY_OMI_HSS_BIST_CLEANUP)
                {
                    RUN_ODY_CHIPOP(CONTEXT, l_StepError, l_err, i_ocmb, IO_ODY_OMI_HSS_BIST_CLEANUP);
                }
                if (i_hwpNumber & ODY_OMI_HSS_INIT)
                {
                    RUN_ODY_CHIPOP(CONTEXT, l_StepError, l_err, i_ocmb, IO_ODY_OMI_HSS_INIT);
                }
                if (i_hwpNumber & ODY_OMI_HSS_DCCAL_START)
                {
                    RUN_ODY_CHIPOP(CONTEXT, l_StepError, l_err, i_ocmb, IO_ODY_OMI_HSS_DCCAL_START);
                }
                if (i_hwpNumber & ODY_OMI_HSS_DCCAL_POLL)
                {
                    RUN_ODY_CHIPOP(CONTEXT, l_StepError, l_err, i_ocmb, IO_ODY_OMI_HSS_DCCAL_POLL);
                }
            }
        }
        else
        {
            TRACISTEP("run_ocmb_omi_scominit: No-op for EXP on target HUID 0x%.8X "
                      "l_runOdyHwpFromHost:%d",
                      get_huid(i_ocmb), l_runOdyHwpFromHost);
        }

    ERROR_EXIT: // required by RUN_ODY_HWP/CHIPOP
        return l_err;
    });

    if (HwpWorkItem::cv_encounteredHwpError)
    {
        TRACISTEP(ERR_MRK"run_ocmb_omi_scominit: *_omi_scominit error");
    }

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}


void* call_ocmb_omi_scominit (void *io_pArgs)
{
    TRACISTEP(ENTER_MRK"call_ocmb_omi_scominit");

    errlHndl_t l_err = nullptr;

    // Run all of the HWPs
    l_err = run_ocmb_omi_scominit(ODY_OMI_HSS_ALL_HWPS);

    TRACISTEP(EXIT_MRK"call_ocmb_omi_scominit");

    return l_err;
}

};
