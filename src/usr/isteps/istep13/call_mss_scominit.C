/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep13/call_mss_scominit.C $                  */
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
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/util.H>
#include    <targeting/common/utilFilter.H>

// Istep framework
#include    <istepHelperFuncs.H>
#include    <hwpThread.H>
#include    <hwpThreadHelper.H>

// fapi2 HWP invoker
#include    <fapi2.H>
#include    <fapi2/plat_hwp_invoker.H>
#include    <config.h>

//From Import Directory (EKB Repository)
#include    <exp_scominit.H>
#include    <ody_scominit.H>
#include    <ody_ddrphyinit.H>
#include    <p10_throttle_sync.H>           // p10_throttle_sync
#include    <chipids.H> // for EXPLORER ID

#include    <sbeio/sbeioif.H>

using   namespace   ERRORLOG;
using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ISTEPS_TRACE;
using   namespace   TARGETING;
using   namespace   SBEIO;

#define CONTEXT call_mss_scominit

namespace ISTEP_13
{

/**
 * @brief Run Explorer/Odyssey Scominit on all functional
 *        OCMB Explorer/Odyssey Chip targets
 *
 * @param[in/out] io_iStepError - Container for errors if an error occurs
 * @return bool Success if true.
 *
 */
bool run_mss_scominit(IStepError& io_iStepError);

/**
 * @brief Run Processor Throttle Synchronization on all functional
 *        Processor Chip targets
 *
 * @param[in/out] io_iStepError - Container for errors if an error occurs
 *
 */
void run_proc_throttle_sync_13(IStepError& io_iStepError);

void* call_mss_scominit(void* io_pArgs)
{
    IStepError l_stepError;

    TRACISTEP(ENTER_MRK"call_mss_scominit");

    // Call HWP to execute scomints on all of the OCMB chips
    const bool success = run_mss_scominit(l_stepError);

    // Do not continue if the previous call encountered an error.
    // Breaking out here will make the reconfig loop happen sooner and
    // avoid running HWPs that we know will fail.
    if (!success)
    {
        TRACISTEP(ERR_MRK"call_mss_scominit exited early because run_exp_scominit had failures "
                  "or requested a reconfig loop");
    }
    else
    {
        run_proc_throttle_sync_13(l_stepError);
    }

    TRACISTEP(EXIT_MRK"call_mss_scominit");

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}

bool run_mss_scominit(IStepError& io_iStepError)
{
    bool success = true;

    const auto l_runOdyHwpFromHost =
       TARGETING::UTIL::assertGetToplevelTarget()->getAttr<ATTR_RUN_ODY_HWP_FROM_HOST>();

    parallel_for_each<HwpWorkItem_OCMBUpdateCheck>(composable(getAllChips)(TYPE_OCMB_CHIP, true),
                                                   io_iStepError,
                                                   "ody_mss_scominit",
                                                   [&](Target* const i_ocmb)
    {
        errlHndl_t l_err = nullptr;

        if (UTIL::isOdysseyChip(i_ocmb))
        {
            TRACISTEP("call_mss_scominit: Run ODY HWPs on target HUID 0x%.8X l_runOdyHwpFromHost:%d",
                      get_huid(i_ocmb), l_runOdyHwpFromHost);

            if (l_runOdyHwpFromHost)
            {
                RUN_ODY_HWP(CONTEXT, io_iStepError, l_err, i_ocmb, ody_scominit, { i_ocmb });
                RUN_ODY_HWP(CONTEXT, io_iStepError, l_err, i_ocmb, ody_ddrphyinit, { i_ocmb });
            }
            else
            {
                RUN_ODY_CHIPOP(CONTEXT, io_iStepError, l_err, i_ocmb, MEM_ODY_SCOMINIT);
                RUN_ODY_CHIPOP(CONTEXT, io_iStepError, l_err, i_ocmb, MEM_ODY_DDRPHYINIT);
            }
        }
        else
        {
            TRACISTEP("call_mss_scominit: Run EXP HWPs on target HUID 0x%.8X",
                      get_huid(i_ocmb));

            FAPI_INVOKE_HWP(l_err, exp_scominit, { i_ocmb });
        }

    ERROR_EXIT: // label is required by RUN_ODY_* above
        return l_err;
    });

    if (HwpWorkItem::cv_encounteredHwpError)
    {
        TRACISTEP(ERR_MRK"call_mss_scominit: hwp error for *_mss_scominit" );
        success = false;
    }

    return success;
}

/**
 * @brief Run Processor Throttle Synchronization on all functional
 *        Processor Chip targets
 */
void run_proc_throttle_sync_13(IStepError& io_iStepError)
{
    parallel_for_each<HwpWorkItem_OCMBUpdateCheck>(composable(getAllChips)(TYPE_PROC, true),
                                                   io_iStepError,
                                                   "p10_throttle_sync",
                                                   [](Target* const i_proc)
    {
        errlHndl_t l_err = nullptr;
        FAPI_INVOKE_HWP(l_err, p10_throttle_sync, { i_proc });
        return l_err;
    });

    if (HwpWorkItem::cv_encounteredHwpError)
    {
        TRACISTEP(ERR_MRK"call_mss_scominit: hwp error for p10_throttle_sync" );
    }
}

}
