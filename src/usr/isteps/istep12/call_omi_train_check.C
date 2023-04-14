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

namespace ISTEP_12
{

class WorkItem_exp_omi_train_check: public HwpWorkItem_OCMBUpdateCheck
{
  public:
    WorkItem_exp_omi_train_check( IStepError& i_stepError,
                                      Target& i_ocmb )
    : HwpWorkItem_OCMBUpdateCheck( i_stepError, i_ocmb, "exp_omi_train_check" ) {}

    virtual errlHndl_t run_hwp( void ) override
    {
        errlHndl_t l_err = nullptr;
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_target(iv_pTarget);
        FAPI_INVOKE_HWP(l_err, exp_omi_train_check, l_fapi_target);
        return l_err;
    }
};

class WorkItem_p10_omi_train_check: public HwpWorkItem_OCMBUpdateCheck
{
  public:
    WorkItem_p10_omi_train_check( IStepError& i_stepError,
                                      Target& i_omi )
    : HwpWorkItem_OCMBUpdateCheck( i_stepError, i_omi, "p10_omi_train_check" ) {}

    virtual errlHndl_t run_hwp( void ) override
    {
        errlHndl_t l_err = nullptr;
        fapi2::Target<fapi2::TARGET_TYPE_OMI> l_fapi_target(iv_pTarget);
        FAPI_INVOKE_HWP(l_err, p10_omi_train_check, l_fapi_target);
        return l_err;
    }
};

class Host_ody_omi_train_check: public HwpWorkItem_OCMBUpdateCheck
{
  public:
    Host_ody_omi_train_check( IStepError& i_stepError,
                                  Target& i_ocmb )
    : HwpWorkItem_OCMBUpdateCheck( i_stepError, i_ocmb, "ody_omi_train_check" ) {}

    virtual errlHndl_t run_hwp( void ) override
    {
        errlHndl_t l_err = nullptr;
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_target(iv_pTarget);
        FAPI_INVOKE_HWP(l_err, ody_omi_train_check, l_fapi_target);
        return l_err;
    }
};

class ChipOp_ody_omi_train_check: public HwpWorkItem_OCMBUpdateCheck
{
  public:
    ChipOp_ody_omi_train_check( IStepError& i_stepError,
                                    Target& i_ocmb )
    : HwpWorkItem_OCMBUpdateCheck( i_stepError, i_ocmb, "ody_omi_train_check" ) {}

    virtual errlHndl_t run_hwp( void ) override
    {
        errlHndl_t l_err = nullptr;
        l_err = sendExecHWPRequest(iv_pTarget, IO_ODY_OMI_TRAIN_CHECK);
        return l_err;
    }
};

void* call_omi_train_check (void *io_pArgs)
{
    IStepError l_StepError;
    Util::ThreadPool<HwpWorkItem> threadpool;
    TargetHandleList l_omiTargetList;

    TRACFCOMP( g_trac_isteps_trace, "call_omi_train_check entry");

    // get RUN_ODY_HWP_FROM_HOST
    const auto l_runOdyHwpFromHost =
       TARGETING::UTIL::assertGetToplevelTarget()->getAttr<ATTR_RUN_ODY_HWP_FROM_HOST>();

    // 12.8.a *_omi_train_check
    //        - Check for training errors

    // Find functional ocmb targets
    TargetHandleList l_OcmbChipList;
    getAllChips(l_OcmbChipList, TYPE_OCMB_CHIP, true);

    for (auto l_ocmb: l_OcmbChipList)
    {
        uint32_t chipId = l_ocmb->getAttr<ATTR_CHIP_ID>();

        //  Create a new WorkItem from this ocmb and feed it to the
        //  thread pool for processing.  Thread pool handles WorkItem
        //  cleanup.
        if (chipId == POWER_CHIPID::EXPLORER_16)
        {
            threadpool.insert(new WorkItem_exp_omi_train_check(l_StepError,
                                                               *l_ocmb));
        }
        else if (chipId == POWER_CHIPID::ODYSSEY_16)
        {
            TRACFCOMP( g_trac_isteps_trace,
                "call_omi_train_check: Run ODY HWPs on target HUID 0x%.8X l_runOdyHwpFromHost:%d",
                get_huid(l_ocmb), l_runOdyHwpFromHost);

            if (l_runOdyHwpFromHost)
            {
                threadpool.insert(new Host_ody_omi_train_check(l_StepError,*l_ocmb));
            }
            else
            {
                threadpool.insert(new ChipOp_ody_omi_train_check(l_StepError,*l_ocmb));
            }
        }
    } // OCMB loop

    HwpWorkItem::start_threads(threadpool, l_StepError, l_OcmbChipList.size());

    if (HwpWorkItem::cv_encounteredHwpError)
    {
        TRACFCOMP(g_trac_isteps_trace,
            ERR_MRK"call_omi_train_check: *_omi_train_check returned an error");
        goto ERROR_EXIT;
    }

    // 12.8.b p10_omi_train_check.C
    //        - Check for training errors

    // Find omi targets
    getAllChiplets(l_omiTargetList, TYPE_OMI);

    for (const auto l_omi_target : l_omiTargetList)
    {
        //  Create a new workitem from this ocmb and feed it to the
        //  thread pool for processing.  Thread pool handles workitem
        //  cleanup.
        threadpool.insert(new WorkItem_p10_omi_train_check(l_StepError,
                                                           *l_omi_target));
    } // OMI loop

    HwpWorkItem::start_threads(threadpool, l_StepError, l_omiTargetList.size());

    if (HwpWorkItem::cv_encounteredHwpError)
    {
        TRACFCOMP(g_trac_isteps_trace,
                  ERR_MRK"call_omi_train_check: error for p10_omi_train_check" );
        goto ERROR_EXIT;
    }

    ERROR_EXIT:

    // Beyond this point, scoms to the OCMBs should be working, so clear the
    // ATTR_ATTN_POLL_PLID attribute since attention won't need to check the
    // PRD_HWP_PLID attribute before scomming the OCMBs anymore.
    TargetHandle_t sys = nullptr;
    targetService().getTopLevelTarget(sys);
    assert(sys != nullptr);
    sys->setAttr<ATTR_ATTN_POLL_PLID>(0);

    TRACFCOMP( g_trac_isteps_trace, "call_omi_train_check exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

};
