/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep12/call_omi_setup.C $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2023                        */
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
 * @file    call_omi_setup.C
 *
 *  Contains the wrapper for Istep 12.6
 *      exp_omi_setup
 *      p10_omi_setup
 */

#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>
#include    <util/threadpool.H>
#include    <sys/task.h>
#include    <initservice/istepdispatcherif.H>
#include    <hwpThread.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>
#include    <istepHelperFuncs.H>          // captureError

#include    <expupd/expupd.H> // i2c update check

// Fapi Support
#include    <config.h>

// HWP
#include    <exp_omi_setup.H>
#include    <p10_omi_setup.H>
#include    <ody_omi_setup.H>

#include    <sbeio/sbeioif.H>

#include    <chipids.H>

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   ISTEPS_TRACE;
using   namespace   SBEIO;

namespace ISTEP_12
{
class WorkItem_omi_setup: public HwpWorkItem
{
  public:
    WorkItem_omi_setup(IStepError& i_stepError,
                           Target& i_omic )
      : HwpWorkItem( i_stepError, i_omic, "omi_setup" ) {}

    virtual errlHndl_t run_hwp( void ) override
    {
        errlHndl_t l_err = nullptr;

        // reset watchdog for each omic as this function can be very slow
        INITSERVICE::sendProgressCode();

        // get RUN_ODY_HWP_FROM_HOST
        const auto l_runOdyHwpFromHost =
           TARGETING::UTIL::assertGetToplevelTarget()->getAttr<ATTR_RUN_ODY_HWP_FROM_HOST>();

        // call exp_omi_setup first with each target's associated OCMB
        // call p10_omi_setup second with each target
        fapi2::Target<fapi2::TARGET_TYPE_OMIC> l_fapi_omic_target(iv_pTarget);

        // each OMIC could have up to 2 child OMIs
        auto l_childOMIs = l_fapi_omic_target.getChildren<fapi2::TARGET_TYPE_OMI>();

        // Loop through the OMIs and find their child OCMB
        // Run exp_omi_setup with the OCMB
        for (auto omi : l_childOMIs)
        {
            // Get the OCMB from the OMI
            auto l_childOCMB = omi.getChildren<fapi2::TARGET_TYPE_OCMB_CHIP>();
            if (l_childOCMB.size() != 1)
            {
                continue;
            }

            auto ocmb = l_childOCMB[0];
            TARGETING::Target * l_ocmbTarget = ocmb.get();

            fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_ocmb_target(l_ocmbTarget);
            uint32_t chipId = l_ocmbTarget->getAttr< ATTR_CHIP_ID>();

            if (chipId == POWER_CHIPID::EXPLORER_16)
            {
                TRACFCOMP(g_trac_isteps_trace,
                    INFO_MRK"exp_omi_setup HWP target HUID 0x%.08x ",
                    get_huid(l_ocmbTarget));

                FAPI_INVOKE_HWP(l_err, exp_omi_setup, ocmb);

                //  process return code
                if ( l_err )
                {
                    TRACFCOMP(g_trac_isteps_trace,
                      ERR_MRK"exp_omi_setup HWP: failed on target 0x%08X. "
                      TRACE_ERR_FMT,
                      get_huid(l_ocmbTarget),
                      TRACE_ERR_ARGS(l_err));
                    mutex_lock(&cv_stepErrorMutex);
                    captureError(l_err, *iv_pStepError, ISTEP_COMP_ID, l_ocmbTarget);
                    mutex_unlock(&cv_stepErrorMutex);
                    continue;
                }

                TRACFCOMP(g_trac_isteps_trace,
                     INFO_MRK"SUCCESS running exp_omi_setup HWP on target HUID %.8X. ",
                     get_huid(l_ocmbTarget));
            }
            else if (chipId == POWER_CHIPID::ODYSSEY_16)
            {
                TRACFCOMP(g_trac_isteps_trace,
                    INFO_MRK"ody_omi_setup HWP target HUID 0x%.08x l_runOdyHwpFromHost:%d",
                    get_huid(l_ocmbTarget), l_runOdyHwpFromHost);

                if (l_runOdyHwpFromHost)
                {
                    FAPI_INVOKE_HWP(l_err, ody_omi_setup, ocmb);
                }
                else
                {
                    l_err = sendExecHWPRequest(l_ocmbTarget, IO_ODY_OMI_SETUP);
                }

                //  process return code
                if ( l_err )
                {
                    TRACFCOMP(g_trac_isteps_trace,
                      ERR_MRK"call ody_omi_setup HWP: failed on target 0x%08X. "
                      TRACE_ERR_FMT,
                      get_huid(l_ocmbTarget),
                      TRACE_ERR_ARGS(l_err));
                    mutex_lock(&cv_stepErrorMutex);
                    captureError(l_err, *iv_pStepError, ISTEP_COMP_ID, l_ocmbTarget);
                    mutex_unlock(&cv_stepErrorMutex);
                    continue;
                }

                TRACFCOMP(g_trac_isteps_trace,
                   INFO_MRK"SUCCESS running ody_omi_setup HWP on target HUID %.8X. ",
                   get_huid(l_ocmbTarget));
            }
        }

        // Any deconfigs happening above are delayed, so need to exit
        // early if istep errors out
        if( !iv_pStepError->isNull() )
        {
            TRACFCOMP(g_trac_isteps_trace,
                    INFO_MRK "call_omi_setup exited early because exp_omi_setup "
                    "had failures");
            goto ERROR_EXIT;
        }

        // Run p10_omi_setup on the OMIC target
        TRACFCOMP(g_trac_isteps_trace,
            INFO_MRK"p10_omi_setup HWP target HUID 0x%.08x ",
            get_huid(iv_pTarget));

        FAPI_INVOKE_HWP(l_err, p10_omi_setup, l_fapi_omic_target);

        // process return code
        if (l_err)
        {
            TRACFCOMP(g_trac_isteps_trace,
                ERR_MRK"call p10_omi_setup HWP: failed on target 0x%08X. "
                TRACE_ERR_FMT,
                get_huid(iv_pTarget),
                TRACE_ERR_ARGS(l_err));
            goto ERROR_EXIT;
        }

        TRACFCOMP(g_trac_isteps_trace,
                INFO_MRK"SUCCESS running p10_omi_setup HWP on target HUID %.8X.",
                get_huid(iv_pTarget));

        ERROR_EXIT:
        return l_err;
    }
};

void* call_omi_setup (void *io_pArgs)
{
    IStepError l_StepError;
    Util::ThreadPool<HwpWorkItem> threadpool;

    TRACFCOMP( g_trac_isteps_trace, ENTER_MRK"call_omi_setup " );

    // 12.6.a exp_omi_setup.C
    //        - Set any register (via I2C) on the Explorer before OMI is
    //          trained
    TargetHandleList l_omicTargetList;
    getAllChiplets(l_omicTargetList, TYPE_OMIC);
    TRACFCOMP(g_trac_isteps_trace,
            INFO_MRK"call_omi_setup: %d OMICs found ",
            l_omicTargetList.size());

    for (auto l_omic_target : l_omicTargetList)
    {
        //  Create a new workitem from this membuf and feed it to the
        //  thread pool for processing.  Thread pool handles workitem
        //  cleanup.
        threadpool.insert(new WorkItem_omi_setup(l_StepError, *l_omic_target));
    }

    HwpWorkItem::start_threads(threadpool, l_StepError, l_omicTargetList.size());

    if (HwpWorkItem::cv_encounteredHwpError)
    {
        TRACFCOMP(g_trac_isteps_trace,
                  ERR_MRK"call_omi_setup: omi_setup error");
    }

    TargetHandle_t sys = UTIL::assertGetToplevelTarget();

    // Check explorer FW levels and do an i2c update if needed.
    // The update will fail before step 12.6 because the inbound doorbell
    // register (along with many other parts of the scommable logic) in Explorer
    // isn't clocked before we run the FW_BOOT_CONFIG0 command.
    // This prevents all inband commands from working, even using the i2c
    // interface, until after exp_omi_setup runs.
    if (l_StepError.isNull())
    {
        // Check if explorer chips need an update (skipped on MPIPL)
        if (sys->getAttr<ATTR_IS_MPIPL_HB>())
        {
            TRACFCOMP( g_trac_isteps_trace,
                   "skipping ocmbFwI2cUpdateStatusCheck() due to MPIPL");
        }
        else
        {
            expupd::ocmbFwI2cUpdateStatusCheck(l_StepError);
        }
    }

    // Set ATTR_ATTN_CHK_OCMBS to let ATTN know that we may now get attentions
    // from Explorer, but interrupts from the OCMB are not enabled yet.
    TargetHandleList l_allOCMBs;
    getAllChips(l_allOCMBs, TYPE_OCMB_CHIP, true);
    for (const auto & l_ocmb : l_allOCMBs)
    {
        uint32_t l_chipId = l_ocmb->getAttr<TARGETING::ATTR_CHIP_ID>();
        if (l_chipId == POWER_CHIPID::EXPLORER_16)
        {
            TRACFCOMP(g_trac_isteps_trace,
                      "Enable attention processing for Explorer OCMBs");
            sys->setAttr<ATTR_ATTN_CHK_OCMBS>(1);
        }
        // There can be no mixing of OCMB types so only need to check one
        break;
    }

    TRACFCOMP(g_trac_isteps_trace, EXIT_MRK"call_omi_setup ");

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

};
