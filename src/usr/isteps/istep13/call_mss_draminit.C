/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep13/call_mss_draminit.C $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2024                        */
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
#include <ody_host_draminit.H>
#include <ody_load_pie.H>

#include <sbeio/sbeioif.H>
#include <arch/magic.H>

using namespace ERRORLOG;
using namespace ISTEP;
using namespace ISTEP_ERROR;
using namespace ISTEPS_TRACE;
using namespace TARGETING;
using namespace SBEIO;

#define CONTEXT call_mss_draminit

namespace ISTEP_13
{

void* call_mss_draminit (void *io_pArgs)
{
    IStepError l_stepError;

    TRACISTEP(ENTER_MRK"call_mss_draminit");

    const auto l_runOdyHwpFromHost =
       TARGETING::UTIL::assertGetToplevelTarget()->getAttr<ATTR_RUN_ODY_HWP_FROM_HOST>();

    parallel_for_each<HwpWorkItem_OCMBUpdateCheck>(composable(getAllChips)(TYPE_OCMB_CHIP, true),
                                                   l_stepError,
                                                   "exp/ody_draminit",
                                                   [&](Target* const i_ocmb)
    {
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_target(i_ocmb);
        errlHndl_t l_err = nullptr;

        if (UTIL::isOdysseyChip(i_ocmb))
        {
            if (l_runOdyHwpFromHost)
            {
                fapi2::hwp_data_unit writebuf[128] = {0};
                fapi2::hwp_array_ostream ostream(writebuf, std::size(writebuf));

                /*
                 * Requires local file access that Hostboot doesn't support.
                 *
                 RUN_ODY_HWP(CONTEXT, l_err, i_ocmb, ody_load_imem, l_fapi_target, ...);
                 RUN_ODY_HWP(CONTEXT, l_err, i_ocmb, ody_load_dmem, l_fapi_target, ...);
                */

                RUN_ODY_HWP(CONTEXT, l_stepError, l_err, i_ocmb, ody_sppe_draminit, l_fapi_target, ostream);
                RUN_ODY_HWP(CONTEXT, l_stepError, l_err, i_ocmb, ody_host_draminit, l_fapi_target);

                /*
                 * Requires local file access that Hostboot doesn't support.
                 *
                RUN_ODY_HWP(CONTEXT, l_stepError, l_err, i_ocmb, ody_load_pie, l_fapi_target, ...);
                */
            }
            else
            {
                RUN_ODY_CHIPOP(CONTEXT, l_stepError, l_err, i_ocmb, MEM_ODY_LOAD_IMEM);
                RUN_ODY_CHIPOP(CONTEXT, l_stepError, l_err, i_ocmb, MEM_ODY_LOAD_DMEM);
                // Set this attr ahead of the actual draminit chip-op so that if
                // that fails, the HWP failure processing code can fetch the data
                // for the failing draminit.
                i_ocmb->setAttr<TARGETING::ATTR_COLLECT_SBE_SCRATCH_DATA>(1);
                RUN_ODY_CHIPOP(CONTEXT, l_stepError, l_err, i_ocmb, MEM_ODY_SPPE_DRAMINIT);
                RUN_ODY_HWP   (CONTEXT, l_stepError, l_err, i_ocmb, ody_host_draminit, l_fapi_target);
                RUN_ODY_CHIPOP(CONTEXT, l_stepError, l_err, i_ocmb, MEM_ODY_LOAD_PIE);

                // Dump the scratch reg data if explicitly requested via attr override
                if(UTIL::assertGetToplevelTarget()->
                    getAttr<ATTR_FORCE_SBE_SCRATCH_DATA_COLLECTION>() == 1)
                {

                    errlHndl_t l_scratchErrls = nullptr;
                    l_err = getAndProcessScratchData(i_ocmb, l_scratchErrls);
                    if(l_err)
                    {
                        errlCommit(l_err, SBEIO_COMP_ID);
                    }
                    else if (l_scratchErrls)
                    {
                        errlCommit(l_scratchErrls, SBEIO_COMP_ID);
                    }
                }
            }
        }
        else
        {
            FAPI_INVOKE_HWP(l_err, exp_draminit, { i_ocmb });
        }

    ERROR_EXIT: // label is required by RUN_ODY_* above
        if (l_err)
        {
            TRACISTEP(ERR_MRK"call_mss_draminit");
        }

        return l_err;
    });

    if (HwpWorkItem::cv_encounteredHwpError)
    {
        TRACISTEP(ERR_MRK"call_mss_draminit: exp/ody_draminit returned an error");
    }

    TRACISTEP(EXIT_MRK"call_mss_draminit");

    return l_stepError.getErrorHandle();
}

}
