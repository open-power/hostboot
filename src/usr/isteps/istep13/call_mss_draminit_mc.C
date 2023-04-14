/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep13/call_mss_draminit_mc.C $               */
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

//Error handling and tracing
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <isteps/hwpisteperror.H>
#include <initservice/isteps_trace.H>

//  targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/util.H>
#include <targeting/common/utilFilter.H>

// Istep framework
#include <istepHelperFuncs.H>
#include <hwpThread.H>
#include <hwpThreadHelper.H>

// fapi2 HWP invoker
#include  <fapi2.H>
#include  <fapi2/plat_hwp_invoker.H>

//From Import Directory (EKB Repository)
#include  <config.h>

#include  <exp_draminit_mc.H>
#include  <ody_draminit_mc.H>
#include  <ody_enable_ecc.H>
#include  <chipids.H> // for EXPLORER ID

#include <sbeio/sbeioif.H>

using namespace ERRORLOG;
using namespace ISTEP;
using namespace ISTEP_ERROR;
using namespace TARGETING;
using namespace ISTEPS_TRACE;
using namespace SBEIO;

#define CONTEXT call_mss_draminit_mc

namespace ISTEP_13
{
class WorkItem_exp_draminit_mc: public HwpWorkItem_OCMBUpdateCheck
{
  public:
    WorkItem_exp_draminit_mc( IStepError& i_stepError,
                                  Target& i_ocmb )
    : HwpWorkItem_OCMBUpdateCheck( i_stepError, i_ocmb, "exp_draminit_mc" ) {}

    virtual errlHndl_t run_hwp( void ) override
    {
        errlHndl_t l_err = nullptr;
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_target(iv_pTarget);
        FAPI_INVOKE_HWP(l_err, exp_draminit_mc, l_fapi_target);
        return l_err;
    }
};

class Host_ody_draminit_mc: public HwpWorkItem_OCMBUpdateCheck
{
  public:
    Host_ody_draminit_mc( IStepError& i_stepError,
                              Target& i_ocmb )
    : HwpWorkItem_OCMBUpdateCheck( i_stepError, i_ocmb, "ody_draminit_mc" ) {}

    virtual errlHndl_t run_hwp( void ) override
    {
        errlHndl_t l_err = nullptr;
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_target(iv_pTarget);

        RUN_SUB_HWP(CONTEXT, l_err, iv_pTarget, ody_draminit_mc, l_fapi_target);
        RUN_SUB_HWP(CONTEXT, l_err, iv_pTarget, ody_enable_ecc,  l_fapi_target);

        ERROR_EXIT:   // label is required by RUN_SUB_HWP
        return l_err;
    }
};

class ChipOp_ody_draminit_mc: public HwpWorkItem_OCMBUpdateCheck
{
  public:
    ChipOp_ody_draminit_mc( IStepError& i_stepError,
                                Target& i_ocmb )
    : HwpWorkItem_OCMBUpdateCheck( i_stepError, i_ocmb, "ody_draminit_mc" ) {}

    virtual errlHndl_t run_hwp( void ) override
    {
        errlHndl_t l_err = nullptr;
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_target(iv_pTarget);

        RUN_SUB_CHIPOP(CONTEXT, l_err, iv_pTarget, MEM_ODY_DRAMINIT_MC);

        /* @todo JIRA:PFHB-258 - for ody_apply_sbe_attribute_data
         *
        RUN_SUB_HWP   (CONTEXT, l_err, iv_pTarget, ody_apply_sbe_attribute_data, l_fapi_target);
         */

        RUN_SUB_CHIPOP(CONTEXT, l_err, iv_pTarget, MEM_ODY_ENABLE_ECC);

        ERROR_EXIT:   // label is required by RUN_SUB_HWP
        return l_err;
    }
};

void* call_mss_draminit_mc (void *io_pArgs)
{
    IStepError l_StepError;
    Util::ThreadPool<HwpWorkItem> threadpool;

    TRACFCOMP( g_trac_isteps_trace, ENTER_MRK"call_mss_draminit_mc" );

    // get RUN_ODY_HWP_FROM_HOST
    const auto l_runOdyHwpFromHost =
       TARGETING::UTIL::assertGetToplevelTarget()->getAttr<ATTR_RUN_ODY_HWP_FROM_HOST>();

    // Get all functional OCMB targets
    TargetHandleList l_ocmbTargetList;
    getAllChips(l_ocmbTargetList, TYPE_OCMB_CHIP);

    for (auto l_ocmb_target : l_ocmbTargetList)
    {
        //  call the HWP with each target
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_ocmb_target(l_ocmb_target);

        uint32_t chipId = l_ocmb_target->getAttr< ATTR_CHIP_ID>();

        //  Create a new workitem from this ocmb and feed it to the
        //  thread pool for processing.  Thread pool handles workitem
        //  cleanup.
        if (chipId == POWER_CHIPID::EXPLORER_16)
        {
            threadpool.insert(new WorkItem_exp_draminit_mc(l_StepError, *l_ocmb_target));
        }
        else if (chipId == POWER_CHIPID::ODYSSEY_16)
        {
            if (l_runOdyHwpFromHost)
            {
                threadpool.insert(new Host_ody_draminit_mc(l_StepError, *l_ocmb_target));
            }
            else
            {
                threadpool.insert(new ChipOp_ody_draminit_mc(l_StepError, *l_ocmb_target));
            }
        }
    }

    HwpWorkItem::start_threads( threadpool, l_StepError, l_ocmbTargetList.size());

    if (HwpWorkItem::cv_encounteredHwpError)
    {
        TRACFCOMP(g_trac_isteps_trace,
                  ERR_MRK"call_mss_draminit_mc: *_draminit_mc error" );
    }

    TRACFCOMP( g_trac_isteps_trace, EXIT_MRK"call_mss_draminit_mc" );

    return l_StepError.getErrorHandle();
}

};
