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

void* call_mss_draminit_mc (void *io_pArgs)
{
    IStepError l_StepError;

    TRACISTEP(ENTER_MRK"call_mss_draminit_mc");

    const auto l_runOdyHwpFromHost =
       TARGETING::UTIL::assertGetToplevelTarget()->getAttr<ATTR_RUN_ODY_HWP_FROM_HOST>();

    parallel_for_each<HwpWorkItem_OCMBUpdateCheck>(composable(getAllChips)(TYPE_OCMB_CHIP, true),
                                                   l_StepError,
                                                   "exp/ody_draminit_mc",
                                                   [&](Target* const i_ocmb)
    {
        errlHndl_t l_err = nullptr;
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_target(i_ocmb);

        if (UTIL::isOdysseyChip(i_ocmb))
        {
            if (l_runOdyHwpFromHost)
            {
                RUN_ODY_HWP(CONTEXT, l_StepError, l_err, i_ocmb, ody_draminit_mc, l_fapi_target);
                RUN_ODY_HWP(CONTEXT, l_StepError, l_err, i_ocmb, ody_enable_ecc,  l_fapi_target);
            }
            else
            {
                RUN_ODY_CHIPOP(CONTEXT, l_StepError, l_err, i_ocmb, MEM_ODY_DRAMINIT_MC);

                l_err = SBEIO::sendAttrListRequest(i_ocmb);

                if (l_err)
                {
                    goto ERROR_EXIT;
                }

                RUN_ODY_CHIPOP(CONTEXT, l_StepError, l_err, i_ocmb, MEM_ODY_ENABLE_ECC);
            }
        }
        else
        {
            FAPI_INVOKE_HWP(l_err, exp_draminit_mc, { i_ocmb });
        }

    ERROR_EXIT: // label is required by RUN_ODY_*
        return l_err;
    });

    if (HwpWorkItem::cv_encounteredHwpError)
    {
        TRACISTEP(ERR_MRK"call_mss_draminit_mc: exp/ody_draminit_mc error");
    }

    TRACISTEP(EXIT_MRK"call_mss_draminit_mc");

    return l_StepError.getErrorHandle();
}

}
