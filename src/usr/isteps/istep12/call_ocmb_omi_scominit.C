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

//  targeting support.
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

//Fapi Support
#include    <config.h>
#include    <fapi2.H>

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

using   namespace   ISTEP;
using   namespace   ISTEPS_TRACE;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;

#define CONTEXT call_ocmb_omi_scominit

namespace ISTEP_12
{
class WorkItem_ody_omi_scominit: public HwpWorkItem
{
  public:
    WorkItem_ody_omi_scominit( IStepError& i_stepError,
                             const Target& i_ocmb)
    : HwpWorkItem( i_stepError, i_ocmb, "ody_omi_scominit" ) {}

    virtual errlHndl_t run_hwp( void ) override
    {
        errlHndl_t l_err = nullptr;
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_target(iv_pTarget);

        /*
         * @todo JIRA:PFHB-418 This requires additional parameters to the hwp
         *
        uint8_t *i_img_data;
        uint32_t i_img_size;
        uint32_t i_offset;
        IO_PPE_Image_Type_t i_type;

        RUN_SUB_HWP(CALLER_CONTEXT,
                    l_err,
                    iv_pTarget,
                    ody_omi_hss_ppe_load,
                    l_fapi_target,
                    i_img_data,
                    i_img_size,
                    i_offset,
                    i_type);
*/
        RUN_SUB_HWP(CONTEXT, l_err, iv_pTarget, ody_omi_hss_config,       l_fapi_target);
        RUN_SUB_HWP(CONTEXT, l_err, iv_pTarget, ody_omi_hss_ppe_start,    l_fapi_target);
        RUN_SUB_HWP(CONTEXT, l_err, iv_pTarget, ody_omi_hss_bist_init,    l_fapi_target);
        RUN_SUB_HWP(CONTEXT, l_err, iv_pTarget, ody_omi_hss_bist_start,   l_fapi_target);
        RUN_SUB_HWP(CONTEXT, l_err, iv_pTarget, ody_omi_hss_bist_poll,    l_fapi_target);
        RUN_SUB_HWP(CONTEXT, l_err, iv_pTarget, ody_omi_hss_bist_cleanup, l_fapi_target);
        RUN_SUB_HWP(CONTEXT, l_err, iv_pTarget, ody_omi_hss_init,         l_fapi_target);
        RUN_SUB_HWP(CONTEXT, l_err, iv_pTarget, ody_omi_hss_dccal_start,  l_fapi_target);
        RUN_SUB_HWP(CONTEXT, l_err, iv_pTarget, ody_omi_hss_dccal_poll,   l_fapi_target);

        ERROR_EXIT:   // label is required by RUN_SUB_HWP
        return l_err;
    }
};

void* call_ocmb_omi_scominit (void *io_pArgs)
{
    IStepError l_StepError;
    Util::ThreadPool<HwpWorkItem> threadpool;

    TRACDCOMP(g_trac_isteps_trace, "call_ocmb_omi_scominit entry");

    // get RUN_ODY_HWP_FROM_HOST
    const auto l_runOdyHwpFromHost =
       TARGETING::UTIL::assertGetToplevelTarget()->getAttr<ATTR_RUN_ODY_HWP_FROM_HOST>();

    // Get all OCMB targets
    TargetHandleList l_ocmbTargetList;
    getAllChips(l_ocmbTargetList, TYPE_OCMB_CHIP);

    for (const auto l_ocmb_target : l_ocmbTargetList)
    {
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_ocmb_target(l_ocmb_target);
        uint32_t chipId = l_ocmb_target->getAttr< ATTR_CHIP_ID>();

        if (chipId == POWER_CHIPID::EXPLORER_16)
        {
            TRACFCOMP( g_trac_isteps_trace,
                "call_ocmb_omi_scominit: No-op for EXP on target HUID 0x%.8X "
                "l_runOdyHwpFromHost:%d",
                get_huid(l_ocmb_target), l_runOdyHwpFromHost);
        }
        else if (chipId == POWER_CHIPID::ODYSSEY_16)
        {
            TRACFCOMP( g_trac_isteps_trace,
                "call_ocmb_omi_scominit: Run ODY HWPs on target HUID 0x%.8X "
                "l_runOdyHwpFromHost:%d",
                get_huid(l_ocmb_target), l_runOdyHwpFromHost);

            if (l_runOdyHwpFromHost)
            {
                //  Create a new WorkItem from this ocmb and feed it to the
                //  thread pool for processing.  Thread pool handles WorkItem
                //  cleanup.
                threadpool.insert(new WorkItem_ody_omi_scominit(l_StepError,*l_ocmb_target) );
            }
            else
            {
                //@todo JIRA:PFHB-412 Istep12 chipops for Odyssey on P10
            }
        }
        else // continue to the next chip
        {
            TRACFCOMP( g_trac_isteps_trace,
                "call_ocmb_omi_scominit: Unknown chip ID 0x%X on target HUID 0x%.8X",
                chipId, get_huid(l_ocmb_target) );
        }
    } // OCMB loop

    HwpWorkItem::start_threads(threadpool, l_StepError, l_ocmbTargetList.size());

    if (HwpWorkItem::cv_encounteredHwpError)
    {
        TRACFCOMP(g_trac_isteps_trace,
                  ERR_MRK"call_ocmb_omi_scominit: *_omi_scominit error");
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_ocmb_omi_scominit exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

};
