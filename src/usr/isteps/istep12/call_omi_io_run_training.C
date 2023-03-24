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

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   ISTEPS_TRACE;

namespace ISTEP_12
{

class WorkItem_p10_omi_train: public HwpWorkItem_OCMBUpdateCheck
{
  public:
    WorkItem_p10_omi_train( IStepError& i_stepError,
                           const Target& i_omic )
    : HwpWorkItem_OCMBUpdateCheck( i_stepError, i_omic, "p10_omi_train" ) {}

    virtual errlHndl_t run_hwp( void ) override
    {
        errlHndl_t l_err = nullptr;
        fapi2::Target<fapi2::TARGET_TYPE_OMIC> l_fapi_target(iv_pTarget);
        FAPI_INVOKE_HWP(l_err, p10_omi_train, l_fapi_target);
        return l_err;
    }
};

class WorkItem_exp_omi_train: public HwpWorkItem_OCMBUpdateCheck
{
  public:
    WorkItem_exp_omi_train( IStepError& i_stepError,
                           const Target& i_ocmb )
             : HwpWorkItem_OCMBUpdateCheck( i_stepError, i_ocmb, "exp_omi_train" ) {}

    virtual errlHndl_t run_hwp( void ) override
    {
        errlHndl_t l_err = nullptr;
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_target(iv_pTarget);
        FAPI_INVOKE_HWP(l_err, exp_omi_train, l_fapi_target);
        return l_err;
    }
};

class WorkItem_ody_omi_train: public HwpWorkItem_OCMBUpdateCheck
{
  public:
    WorkItem_ody_omi_train( IStepError& i_stepError,
                           const Target& i_ocmb )
             : HwpWorkItem_OCMBUpdateCheck( i_stepError, i_ocmb, "ody_omi_train" ) {}

    virtual errlHndl_t run_hwp( void ) override
    {
        errlHndl_t l_err = nullptr;
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_target(iv_pTarget);
        FAPI_INVOKE_HWP(l_err, ody_omi_train, l_fapi_target);
        return l_err;
    }
};

void* call_omi_io_run_training (void *io_pArgs)
{
    IStepError l_StepError;
    TRACFCOMP( g_trac_isteps_trace, "call_omi_io_run_training entry" );
    Util::ThreadPool<HwpWorkItem> threadpool;
    TargetHandleList l_omicTargetList;

    // get RUN_ODY_HWP_FROM_HOST
    const auto l_runOdyHwpFromHost =
       TARGETING::UTIL::assertGetToplevelTarget()->getAttr<ATTR_RUN_ODY_HWP_FROM_HOST>();

    // Starting beginning at this istep, we may be unable to scom the OCMBs
    // until the next istep is complete, except in certain cases where the
    // hardware procedure fails. Set ATTR_ATTN_POLL_PLID so ATTN knows to
    // poll the PRD_HWP_PLID before scomming the OCMBs.
    TargetHandle_t sys = nullptr;
    targetService().getTopLevelTarget(sys);
    assert(sys != nullptr);
    sys->setAttr<ATTR_ATTN_POLL_PLID>(1);

    TargetHandleList l_ocmbTargetList;
    getAllChips(l_ocmbTargetList, TYPE_OCMB_CHIP);

    // 12.7.a *_omi_train.C
    for (const auto l_ocmb_target : l_ocmbTargetList)
    {
        //  call the HWP with each target
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_ocmb_target
            (l_ocmb_target);

        uint32_t chipId = l_ocmb_target->getAttr< ATTR_CHIP_ID>();

        //  Create a new workitem from this ocmb and feed it to the
        //  thread pool for processing.  Thread pool handles workitem
        //  cleanup.
        if (chipId == POWER_CHIPID::EXPLORER_16)
        {
            threadpool.insert(new WorkItem_exp_omi_train(l_StepError,
                                                         *l_ocmb_target));
        }
        else if (chipId == POWER_CHIPID::ODYSSEY_16)
        {
            if (l_runOdyHwpFromHost)
            {
                threadpool.insert(new WorkItem_ody_omi_train(l_StepError,
                                                             *l_ocmb_target));
            }
            else
            {
                //@todo JIRA:PFHB-412 Istep12 chipops for Odyssey on P10
            }
        }
        else // continue to the next chip
        {
            TRACFCOMP( g_trac_isteps_trace,
                "call_omi_io_run_training: Unknown chip ID 0x%X on target HUID 0x%.8X",
                chipId, get_huid(l_ocmb_target) );
        }
    }
    HwpWorkItem::start_threads(threadpool, l_StepError, l_ocmbTargetList.size());

    if (HwpWorkItem::cv_encounteredHwpError)
    {
        TRACFCOMP( g_trac_isteps_trace,
            INFO_MRK "call_omi_io_run_training exited early because *_omi_train had failures");
        goto ERROR_EXIT;
    }


    // 12.7.b p10_omi_train.C
    getAllChiplets(l_omicTargetList, TYPE_OMIC);

    for (const auto l_omic_target : l_omicTargetList)
    {
        //  Create a new workitem from this omic and feed it to the
        //  thread pool for processing.  Thread pool handles workitem
        //  cleanup.
        threadpool.insert(new WorkItem_p10_omi_train(l_StepError,
                                                     *l_omic_target));
    }
    HwpWorkItem::start_threads(threadpool, l_StepError, l_omicTargetList.size());

    if (HwpWorkItem::cv_encounteredHwpError)
    {
        TRACFCOMP(g_trac_isteps_trace,
                  ERR_MRK"call_omi_io_run_training: error for p10_omi_train" );
        goto ERROR_EXIT;
    }

    ERROR_EXIT:

    TRACFCOMP( g_trac_isteps_trace, "call_omi_io_run_training exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

};
