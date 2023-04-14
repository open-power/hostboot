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
class WorkItem_exp_scominit : public HwpWorkItem
{
  public:
    WorkItem_exp_scominit( IStepError& i_stepError,
                               Target& i_ocmb )
    : HwpWorkItem( i_stepError, i_ocmb, "exp_scominit" ) {}

    virtual errlHndl_t run_hwp( void ) override
    {
        errlHndl_t l_err = nullptr;
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_target(iv_pTarget);
        FAPI_INVOKE_HWP(l_err, exp_scominit, l_fapi_target);
        return l_err;
    }
};

class Host_ody_mss_scominit : public HwpWorkItem
{
  public:
    Host_ody_mss_scominit( IStepError& i_stepError,
                               Target& i_ocmb )
    : HwpWorkItem( i_stepError, i_ocmb, "ody_mss_scominit" ) {}

    virtual errlHndl_t run_hwp( void ) override
    {
        errlHndl_t l_err = nullptr;
        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_target(iv_pTarget);

        RUN_SUB_HWP(CONTEXT, l_err, iv_pTarget, ody_scominit,   l_fapi_target);
        RUN_SUB_HWP(CONTEXT, l_err, iv_pTarget, ody_ddrphyinit, l_fapi_target);

        ERROR_EXIT:   // label is required by RUN_SUB_HWP
        return l_err;
    }
};

class ChipOp_ody_mss_scominit : public HwpWorkItem
{
  public:
    ChipOp_ody_mss_scominit( IStepError& i_stepError,
                                 Target& i_ocmb )
    : HwpWorkItem( i_stepError, i_ocmb, "ody_mss_scominit" ) {}

    virtual errlHndl_t run_hwp( void ) override
    {
        errlHndl_t l_err = nullptr;

        RUN_SUB_CHIPOP(CONTEXT, l_err, iv_pTarget, MEM_ODY_SCOMINIT);
        RUN_SUB_CHIPOP(CONTEXT, l_err, iv_pTarget, MEM_ODY_DDRPHYINIT);

        ERROR_EXIT:   // label is required by RUN_SUB_HWP
        return l_err;
    }
};

class WorkItem_p10_throttle_sync : public HwpWorkItem
{
  public:
    WorkItem_p10_throttle_sync( IStepError& i_stepError,
                                    Target& i_proc )
    : HwpWorkItem( i_stepError, i_proc, "p10_throttle_sync" ) {}

    virtual errlHndl_t run_hwp( void ) override
    {
        errlHndl_t l_err = nullptr;
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_fapi_target(iv_pTarget);
        FAPI_INVOKE_HWP(l_err, p10_throttle_sync, l_fapi_target);
        return l_err;
    }
};

/**
 * @brief Run Explorer/Odyssey Scominit on all functional
 *        OCMB Explorer/Odyssey Chip targets
 *
 * param[in/out] io_iStepError - Container for errors if an error occurs
 *
 */
void run_mss_scominit(IStepError & io_iStepError);

/**
 * @brief Run Processor Throttle Synchronization on all functional
 *        Processor Chip targets
 *
 * param[in/out] io_iStepError - Container for errors if an error occurs
 *
 */
void run_proc_throttle_sync_13(IStepError & io_iStepError);


void* call_mss_scominit (void *io_pArgs)
{
    IStepError l_stepError;

    TRACFCOMP( g_trac_isteps_trace, ENTER_MRK"call_mss_scominit" );

    // Call HWP to execute scomints on all of the OCMB chips
    run_mss_scominit(l_stepError);

    // Do not continue if the previous call encountered an error.
    // Breaking out here will facilitate in the efficiency of the
    // reconfig loop and not cause confusion for the next HWP call.
    if ( !l_stepError.isNull() )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK
                   "ERROR: call_mss_scominit exited early because run_exp_scominit had failures" );
    }
    else
    {
        // If no prior error, then call HWP to processor throttle
        // synchronization on a list of PROC chips
        run_proc_throttle_sync_13(l_stepError);
    }

    TRACFCOMP( g_trac_isteps_trace, EXIT_MRK"call_mss_scominit" );

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();

}

void run_mss_scominit(IStepError & io_iStepError)
{
    Util::ThreadPool<HwpWorkItem> threadpool;

    // get RUN_ODY_HWP_FROM_HOST
    const auto l_runOdyHwpFromHost =
       TARGETING::UTIL::assertGetToplevelTarget()->getAttr<ATTR_RUN_ODY_HWP_FROM_HOST>();

    // Get all functional OCMB targets
    TargetHandleList l_ocmbTargetList;
    getAllChips(l_ocmbTargetList, TYPE_OCMB_CHIP);

    for (auto l_ocmb : l_ocmbTargetList)
    {
        // check EXPLORER first as this is most likely the configuration
        uint32_t chipId = l_ocmb->getAttr< ATTR_CHIP_ID>();

        //  Create a new workitem from this OCMB and feed it to the
        //  thread pool for processing.  Thread pool handles workitem
        //  cleanup.
        if (chipId == POWER_CHIPID::EXPLORER_16)
        {
            TRACFCOMP( g_trac_isteps_trace,
                "call_mss_scominit: Run EXP HWPs on target HUID 0x%.8X",get_huid(l_ocmb));

            threadpool.insert(new WorkItem_exp_scominit(io_iStepError,
                                                        *l_ocmb));
        }
        else if (chipId == POWER_CHIPID::ODYSSEY_16)
        {
            TRACFCOMP( g_trac_isteps_trace,
                "call_mss_scominit: Run ODY HWPs on target HUID 0x%.8X l_runOdyHwpFromHost:%d",
                get_huid(l_ocmb), l_runOdyHwpFromHost);

            if (l_runOdyHwpFromHost)
            {
                threadpool.insert(new Host_ody_mss_scominit(io_iStepError, *l_ocmb));
            }
            else
            {
                threadpool.insert(new ChipOp_ody_mss_scominit(io_iStepError, *l_ocmb));
            }
        }
    }
    HwpWorkItem::start_threads(threadpool, io_iStepError, l_ocmbTargetList.size());

    if (HwpWorkItem::cv_encounteredHwpError)
    {
        TRACFCOMP(g_trac_isteps_trace,
                  ERR_MRK"call_mss_scominit: hwp error for *_mss_scominit" );
    }
}

/**
 * @brief Run Processor Throttle Synchronization on all functional
 *        Processor Chip targets
 */
void run_proc_throttle_sync_13(IStepError & io_iStepError)
{
    Util::ThreadPool<HwpWorkItem> threadpool;

    // Get a list of all processors to run Throttle Synchronization on
    TARGETING::TargetHandleList l_procChips;
    getAllChips( l_procChips, TARGETING::TYPE_PROC );

    for (auto l_procChip: l_procChips)
    {
        //  Create a new workitem from this OCMB and feed it to the
        //  thread pool for processing.  Thread pool handles workitem
        //  cleanup.
        threadpool.insert(new WorkItem_p10_throttle_sync(io_iStepError,
                                                         *l_procChip));
    }
    HwpWorkItem::start_threads(threadpool, io_iStepError, l_procChips.size());

    if (HwpWorkItem::cv_encounteredHwpError)
    {
        TRACFCOMP(g_trac_isteps_trace,
                  ERR_MRK"call_mss_scominit: hwp error for p10_throttle_sync" );
    }
} // run_proc_throttle_sync

};
