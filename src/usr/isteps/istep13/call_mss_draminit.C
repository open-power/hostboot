/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep13/call_mss_draminit.C $                  */
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

// Error Handling and Tracing Support
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <isteps/hwpisteperror.H>
#include <initservice/isteps_trace.H>
#include <initservice/initserviceif.H>

// Istep framework
#include <istepHelperFuncs.H>
#include <hwpThread.H>
#include <hwpThreadHelper.H>

// Generated files
#include  <config.h>

// Targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/util.H>
#include <targeting/common/utilFilter.H>

// fapi2 HWP invoker
#include  <fapi2.H>
#include  <fapi2/plat_hwp_invoker.H>
#include  <hwp_data_stream.H>

//From Import Directory (EKB Repository)
#include <chipids.H>
#include <exp_draminit.H>
#include <ody_load_imem.H>
#include <ody_load_dmem.H>
#include <ody_sppe_draminit.H>
#include <ody_load_pie.H>

using namespace ERRORLOG;
using namespace ISTEP;
using namespace ISTEP_ERROR;
using namespace ISTEPS_TRACE;
using namespace TARGETING;

#define CONTEXT call_mss_draminit

namespace ISTEP_13
{

class WorkItem_exp_draminit: public HwpWorkItem_OCMBUpdateCheck
{
  public:
    WorkItem_exp_draminit( IStepError& i_stepError,
                           const Target& i_ocmb )
    : HwpWorkItem_OCMBUpdateCheck( i_stepError, i_ocmb, "exp_draminit" ) {}

    virtual errlHndl_t run_hwp( void ) override
    {
        errlHndl_t l_err = nullptr;
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_target(iv_pTarget);
        FAPI_INVOKE_HWP(l_err, exp_draminit, l_fapi_target);
        return l_err;
    }
};

class WorkItem_ody_draminit: public HwpWorkItem_OCMBUpdateCheck
{
  public:
    WorkItem_ody_draminit( IStepError& i_stepError,
                           const Target& i_ocmb )
    : HwpWorkItem_OCMBUpdateCheck( i_stepError, i_ocmb, "ody_draminit" ) {}

    virtual errlHndl_t run_hwp( void ) override
    {
        errlHndl_t l_err = nullptr;
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_target(iv_pTarget);
        fapi2::hwp_data_unit writebuf[128] = {0};
        fapi2::hwp_array_ostream ostream(writebuf, std::size(writebuf));

        /*
         * @todo JIRA:PFHB-434 Odyssey chipop for ody_load_imem/ody_load_dmem
         *
        RUN_SUB_HWP(CALLER_CONTEXT, l_err, iv_pTarget,
                    ody_load_imem, l_fapi_target, ...);
         */

        /*
         * @todo JIRA:PFHB-434 Odyssey chipop for ody_load_imem/ody_load_dmem
         *
        RUN_SUB_HWP(CALLER_CONTEXT, l_err, iv_pTarget,
                    ody_load_dmem, l_fapi_target, ...);
         */

        RUN_SUB_HWP(CONTEXT, l_err, iv_pTarget, ody_sppe_draminit, l_fapi_target, ostream);

        /* @todo JIRA:PFHB-413 Istep13 Updates for Odyssey on P10
         *
         [HOST] ody_sppe_draminit
         *
         */

        RUN_SUB_HWP(CONTEXT, l_err, iv_pTarget, ody_load_pie, l_fapi_target);

        ERROR_EXIT:   // label is required by RUN_SUB_HWP
        return l_err;
    }
};

void* call_mss_draminit (void *io_pArgs)
{
    IStepError l_stepError;
    Util::ThreadPool<HwpWorkItem> threadpool;

    TRACFCOMP( g_trac_isteps_trace, ENTER_MRK"call_mss_draminit" );

    // get RUN_ODY_HWP_FROM_HOST
    const auto l_runOdyHwpFromHost =
       TARGETING::UTIL::assertGetToplevelTarget()->getAttr<ATTR_RUN_ODY_HWP_FROM_HOST>();

    // Get all functional OCMB targets
    TargetHandleList l_ocmbTargetList;
    getAllChips(l_ocmbTargetList, TYPE_OCMB_CHIP);

    for (const auto l_ocmb_target : l_ocmbTargetList)
    {
        // check EXPLORER first as this is most likely the configuration
        uint32_t chipId = l_ocmb_target->getAttr< ATTR_CHIP_ID>();
        if (chipId == POWER_CHIPID::EXPLORER_16)
        {
            //  Create a new workitem from this OCMB and feed it to the
            //  thread pool for processing.  Thread pool handles workitem
            //  cleanup.
            threadpool.insert(new WorkItem_exp_draminit(l_stepError,
                                                        *l_ocmb_target));
        }
        else if (chipId == POWER_CHIPID::ODYSSEY_16)
        {
            if (l_runOdyHwpFromHost)
            {
                //  Create a new workitem from this OCMB and feed it to the
                //  thread pool for processing.  Thread pool handles workitem
                //  cleanup.
                threadpool.insert(new WorkItem_ody_draminit(l_stepError,
                                                            *l_ocmb_target));
            }
            else
            {
                // @todo JIRA:PFHB-413 Istep13 Updates for Odyssey on P10
            }
        }
        else
        {
            TRACFCOMP( g_trac_isteps_trace,
                "Skipping *_draminit HWP on target HUID 0x%.8X, chipId 0x%.4X",
                get_huid(l_ocmb_target), chipId );
            continue;
        }
    }

    HwpWorkItem::start_threads( threadpool, l_stepError, l_ocmbTargetList.size());

    if (HwpWorkItem::cv_encounteredHwpError)
    {
        TRACFCOMP(g_trac_isteps_trace,
                  ERR_MRK"call_mss_draminit: *_draminit returned an error" );
    }

    TRACFCOMP( g_trac_isteps_trace, EXIT_MRK"call_mss_draminit" );

    return l_stepError.getErrorHandle();
}


};
