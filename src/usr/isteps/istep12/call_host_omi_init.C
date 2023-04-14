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

//  targeting support.
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

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
void enableInbandScomsOCMB( TargetHandleList i_ocmbTargetList );

class WorkItem_exp_omi_init: public HwpWorkItem_OCMBUpdateCheck
{
  public:
    WorkItem_exp_omi_init( IStepError& i_stepError,
                               Target& i_ocmb )
      : HwpWorkItem_OCMBUpdateCheck( i_stepError, i_ocmb, "exp_omi_init" ) {}

    virtual errlHndl_t run_hwp( void ) override
    {
        errlHndl_t l_err = nullptr;
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_target(iv_pTarget);
        FAPI_INVOKE_HWP(l_err, exp_omi_init, l_fapi_target);
        return l_err;
    }
};

class Host_ody_omi_init: public HwpWorkItem_OCMBUpdateCheck
{
  public:
    Host_ody_omi_init( IStepError& i_stepError,
                           Target& i_ocmb )
      : HwpWorkItem_OCMBUpdateCheck( i_stepError, i_ocmb, "ody_omi_init" ) {}

    virtual errlHndl_t run_hwp( void ) override
    {
        errlHndl_t l_err = nullptr;
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_target(iv_pTarget);
        FAPI_INVOKE_HWP(l_err, ody_omi_init, l_fapi_target);
        return l_err;
    }
};

class WorkItem_p10_omi_init: public HwpWorkItem_OCMBUpdateCheck
{
  public:
    WorkItem_p10_omi_init( IStepError& i_stepError,
                               Target& i_mcc )
      : HwpWorkItem_OCMBUpdateCheck( i_stepError, i_mcc, "p10_omi_init" ) {}

    virtual errlHndl_t run_hwp( void )
    {
        errlHndl_t l_err = nullptr;
        fapi2::Target<fapi2::TARGET_TYPE_MCC> l_fapi_target(iv_pTarget);
        FAPI_INVOKE_HWP(l_err, p10_omi_init, l_fapi_target);
        return l_err;
    }

    virtual void run_after_success( void ) override
    {
        // Now that the OMI link is active, switch to using inband
        //  scoms for OCMB access
        TargetHandleList l_ocmbTargetList;
        getChildAffinityTargets(l_ocmbTargetList, iv_pTarget,
                                CLASS_CHIP, TYPE_OCMB_CHIP);
        enableInbandScomsOCMB(l_ocmbTargetList);
    }
};

void* call_host_omi_init (void *io_pArgs)
{
    IStepError l_StepError;
    TRACFCOMP( g_trac_isteps_trace, "call_host_omi_init entry" );
    Util::ThreadPool<HwpWorkItem> threadpool;
    TargetHandleList l_ocmbTargetList;
    TargetHandleList l_mccTargetList;

    // 12.11.a - Initialize config space on the Explorer/Odyssey
    getAllChips(l_ocmbTargetList, TYPE_OCMB_CHIP);
    TRACFCOMP(g_trac_isteps_trace,
              "call_host_omi_init: %d ocmb chips found",
              l_ocmbTargetList.size());

    for (auto l_ocmb_target : l_ocmbTargetList)
    {
        uint32_t chipId = l_ocmb_target->getAttr< ATTR_CHIP_ID>();

        //  Create a new workitem from this ocmb and feed it to the
        //  thread pool for processing.  Thread pool handles workitem
        //  cleanup.
        if (chipId == POWER_CHIPID::EXPLORER_16)
        {
            threadpool.insert(new WorkItem_exp_omi_init(l_StepError, *l_ocmb_target));
        }
        else if (chipId == POWER_CHIPID::ODYSSEY_16)
        {
            threadpool.insert(new Host_ody_omi_init(l_StepError, *l_ocmb_target));
        }
    }

    HwpWorkItem::start_threads(threadpool, l_StepError, l_ocmbTargetList.size());

    // Do not continue if an error was encountered
    if(HwpWorkItem::cv_encounteredHwpError)
    {
        TRACFCOMP( g_trac_isteps_trace,
            INFO_MRK "call_host_omi_init exited early because *_omi_init "
            "had failures");
        goto ERROR_EXIT;
    }

    // 12.11.b p10_omi_init.C - Finalize the OMI
    getAllChiplets(l_mccTargetList, TYPE_MCC);
    TRACFCOMP(g_trac_isteps_trace,
              "call_host_omi_init: %d MCCs found",
              l_mccTargetList.size());

    for (auto l_mcc_target : l_mccTargetList)
    {
        //  Create a new workitem from this mmcc and feed it to the
        //  thread pool for processing.  Thread pool handles workitem
        //  cleanup.
        threadpool.insert(new WorkItem_p10_omi_init(l_StepError, *l_mcc_target));
    }
    HwpWorkItem::start_threads(threadpool, l_StepError, l_mccTargetList.size());

    if (HwpWorkItem::cv_encounteredHwpError)
    {
        TRACFCOMP(g_trac_isteps_trace,
                  ERR_MRK"call_host_omi_init: error for p10_omi_init");
        goto ERROR_EXIT;
    }

    ERROR_EXIT:

    // Grab informational Explorer logs (early IPL = false)
    EXPSCOM::createExplorerLogs(l_ocmbTargetList, false);

    TRACFCOMP( g_trac_isteps_trace, "call_host_omi_init exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}


/**
 * @brief Enable Inband Scom for the OCMB targets
 * @param i_ocmbTargetList - OCMB targets
 */
void enableInbandScomsOCMB( TargetHandleList i_ocmbTargetList )
{
    mutex_t* l_mutex = nullptr;

    for ( const auto l_ocmb : i_ocmbTargetList )
    {
        //don't mess with attributes without the mutex (just to be safe)
        l_mutex = l_ocmb->getHbMutexAttr<ATTR_SCOM_ACCESS_MUTEX>();
        recursive_mutex_lock(l_mutex);

        ScomSwitches l_switches = l_ocmb->getAttr<ATTR_SCOM_SWITCHES>();
        l_switches.useI2cScom = 0;
        l_switches.useSbeScom = 0;
        l_switches.useInbandScom = 1;

        // Modify attribute
        l_ocmb->setAttr<ATTR_SCOM_SWITCHES>(l_switches);
        recursive_mutex_unlock(l_mutex);
    }
}

};
