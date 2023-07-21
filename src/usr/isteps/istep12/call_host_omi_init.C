/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep12/call_host_omi_init.C $                 */
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
 * @file    call_host_omi_init.C
 *
 *  Contains the HWP wrapper for Istep 12.11
 *      exp_omi_init
 *      p10_omi_init
 */
#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <hwpThread.H>
#include    <hwpThreadHelper.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>
#include    <istepHelperFuncs.H>          // captureError

#include <sbeio/sbeioif.H>

//  targeting support.
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/odyutil.H>

//Fapi Support
#include    <config.h>
#include    <fapi2.H>
#include    <fapi2/plat_hwp_invoker.H>

#include    <chipids.H>

//HWP
#include    <exp_omi_init.H>
#include    <ody_omi_init.H>
#include    <p10_omi_init.H>
#include    <p10_disable_ocmb_i2c.H>

// Explorer error logs
#include    <expscom/expscom_errlog.H>

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   ISTEPS_TRACE;

namespace ISTEP_12
{
/**
 * @brief Enable Inband Scom for the OCMB targets
 * @param i_ocmbTargetList - OCMB targets
 */
void enableInbandScomsOCMB(const TargetHandleList& i_ocmbTargetList);

/**
 * @brief Enable the PIPE FIFO for the OCMB targets
 * @param i_ocmbTargetList - OCMB targets
 */
void enablePipeFifoOCMB( const TargetHandleList& i_ocmbTargetList );

#define CONTEXT call_host_omi_init

void* call_host_omi_init (void *io_pArgs)
{
    IStepError l_StepError;

    TRACISTEP(ENTER_MRK"call_host_omi_init entry");

    const auto ocmbs = composable(getAllChips)(TYPE_OCMB_CHIP, true);

    TRACISTEP("call_host_omi_init: %d ocmb chips found",
              ocmbs.size());

    do
    {

    // 12.11.a - Initialize config space on the Explorer/Odyssey
    parallel_for_each<HwpWorkItem_OCMBUpdateCheck>(ocmbs,
                                                   l_StepError,
                                                   "exp/ody_omi_init",
                                                   [&](Target* const i_ocmb)
    {
        errlHndl_t l_err = nullptr;

        if (UTIL::isOdysseyChip(i_ocmb))
        {
            RUN_ODY_HWP(CONTEXT, l_StepError, l_err, i_ocmb, ody_omi_init, { i_ocmb });
        }
        else
        {
            FAPI_INVOKE_HWP(l_err, exp_omi_init, { i_ocmb });
        }

    ERROR_EXIT: // label used by RUN_ODY_* above
        return l_err;
    });

    if (HwpWorkItem::cv_encounteredHwpError)
    {
        TRACISTEP(INFO_MRK"call_host_omi_init exited early because *_omi_init "
                  "had failures");
        break;
    }

    // 12.11.b p10_omi_init.C - Finalize the OMI
    const auto mccs = composable(getAllChiplets)(TYPE_MCC, true);

    TRACISTEP("call_host_omi_init: %d MCCs found",
              mccs.size());

    parallel_for_each<HwpWorkItem_OCMBUpdateCheck>(mccs,
                                                   l_StepError,
                                                   "p10_omi_init",
                                                   [&](Target* const i_mcc)
    {
        errlHndl_t l_err = nullptr;
        FAPI_INVOKE_HWP(l_err, p10_omi_init, { i_mcc });

        if (!l_err)
        {
            const auto ocmbs = composable(getChildAffinityTargets)(i_mcc, CLASS_NA, TYPE_OCMB_CHIP, true);
            enableInbandScomsOCMB(ocmbs);
            enablePipeFifoOCMB(ocmbs);
        }

        return l_err;
    });

    if (HwpWorkItem::cv_encounteredHwpError)
    {
        TRACISTEP(ERR_MRK"call_host_omi_init: error for p10_omi_init");
        break;
    }

    } while (false);

    // Grab informational Explorer logs (early IPL = false)
    EXPSCOM::createExplorerLogs(ocmbs, false);

    TRACISTEP("call_host_omi_init exit");

    return l_StepError.getErrorHandle();
}

void enableInbandScomsOCMB(const TargetHandleList& i_ocmbTargetList )
{
    mutex_t* l_mutex = nullptr;

    for (const auto l_ocmb : i_ocmbTargetList)
    {
        //don't mess with attributes without the mutex (just to be safe)
        l_mutex = l_ocmb->getHbMutexAttr<ATTR_SCOM_ACCESS_MUTEX>();
        const auto lock = scoped_recursive_mutex_lock(*l_mutex);

        ScomSwitches l_switches = l_ocmb->getAttr<ATTR_SCOM_SWITCHES>();
        l_switches.useI2cScom = 0;
        l_switches.useSbeScom = 0;
        l_switches.useInbandScom = 1;

        // Modify attribute
        l_ocmb->setAttr<ATTR_SCOM_SWITCHES>(l_switches);
    }
}

void enablePipeFifoOCMB( const TargetHandleList& i_ocmbTargetList )
{
    errlHndl_t l_errl  = nullptr;
    mutex_t   *l_mutex = nullptr;

    for (const auto l_ocmb : i_ocmbTargetList)
    {
        // don't mess with attributes without the mutex (just to be safe)
        l_mutex = l_ocmb->getHbMutexAttr<ATTR_SBE_FIFO_MUTEX>();
        const auto lock = scoped_mutex_lock(*l_mutex);

        if (TARGETING::UTIL::isOdysseyChip(l_ocmb))
        {
            l_errl = SBEIO::doSetupPipeAccess(l_ocmb);
            if (l_errl)
            {
                ERRORLOG::errlCommit(l_errl, ISTEP_COMP_ID);
            }
            else
            {
                l_ocmb->setAttr<ATTR_USE_PIPE_FIFO>(1);
            }
        }
    }
}

}
