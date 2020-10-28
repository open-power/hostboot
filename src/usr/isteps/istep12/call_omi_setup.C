/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep12/call_omi_setup.C $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>
#include    <istepHelperFuncs.H>          // captureError

// Fapi Support
#include    <config.h>
#include    <fapi2/plat_hwp_invoker.H>

// HWP
#include    <exp_omi_setup.H>
#include    <p10_omi_setup.H>

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   ISTEPS_TRACE;

namespace ISTEP_12
{
//
// @brief Mutex to prevent threads from adding details to the step
//        error log at the same time.
mutex_t g_stepErrorMutex = MUTEX_INITIALIZER;

/*******************************************************************************
 * @brief base work item class for isteps (used by thread pool)
 */
class IStepWorkItem
{
    public:
        virtual ~IStepWorkItem(){}
        virtual void operator()() = 0;
};

/*******************************************************************************
 * @brief Omic specific work item class
 */
class OmicWorkItem: public IStepWorkItem
{
    private:
        IStepError* iv_pStepError;
        const Target* iv_pOmic;

    public:
        /**
         * @brief task function, called by threadpool to run the HWP on the
         *        target
         */
         void operator()();

        /**
         * @brief ctor
         *
         * @param[in] i_Omic target Omic to operate on
         * @param[in] i_istepError error accumulator for this istep
         */
        OmicWorkItem(const Target& i_Omic,
                       IStepError& i_stepError):
            iv_pStepError(&i_stepError),
            iv_pOmic(&i_Omic) {}

        // delete default copy/move constructors and operators
        OmicWorkItem() = delete;
        OmicWorkItem(const OmicWorkItem& ) = delete;
        OmicWorkItem& operator=(const OmicWorkItem& ) = delete;
        OmicWorkItem(OmicWorkItem&&) = delete;
        OmicWorkItem& operator=(OmicWorkItem&&) = delete;

        /**
         * @brief destructor
         */
        ~OmicWorkItem(){};
};

//******************************************************************************
void OmicWorkItem::operator()()
{
    errlHndl_t l_err = nullptr;

    // reset watchdog for each omic as this function can be very slow
    INITSERVICE::sendProgressCode();

    // call exp_omi_setup first with each target's associated OCMB
    // call p10_omi_setup second with each target
    fapi2::Target<fapi2::TARGET_TYPE_OMIC> l_fapi_omic_target
      (iv_pOmic);

    // each OMIC could have up to 2 child OMIs
    auto l_childOMIs =
        l_fapi_omic_target.getChildren<fapi2::TARGET_TYPE_OMI>();

    // Loop through the OMIs and find their child OCMB
    // Run exp_omi_setup with the OCMB
    for (auto omi : l_childOMIs)
    {
        // Get the OCMB from the OMI
        auto l_childOCMB =
            omi.getChildren<fapi2::TARGET_TYPE_OCMB_CHIP>();
        if (l_childOCMB.size() == 1)
        {
            auto ocmb = l_childOCMB[0];
            TARGETING::Target * l_ocmbTarget = ocmb.get();
            TRACFCOMP(g_trac_isteps_trace,
                INFO_MRK"exp_omi_setup HWP target HUID 0x%.08x ",
                get_huid(iv_pOmic));

            FAPI_INVOKE_HWP(l_err, exp_omi_setup, ocmb);

            //  process return code
            if ( l_err )
            {
                TRACFCOMP(g_trac_isteps_trace,
                  ERR_MRK"call exp_omi_setup HWP: failed on target 0x%08X. "
                  TRACE_ERR_FMT,
                  get_huid(l_ocmbTarget),
                  TRACE_ERR_ARGS(l_err));

                // addErrorDetails may not be thread-safe.  Protect with mutex.
                mutex_lock(&g_stepErrorMutex);

                // Capture error
                captureError(l_err, *iv_pStepError, HWPF_COMP_ID, l_ocmbTarget);

                mutex_unlock(&g_stepErrorMutex);
            }
            else
            {
                TRACFCOMP(g_trac_isteps_trace,
                   INFO_MRK"SUCCESS running exp_omi_setup HWP on target HUID %.8X. ",
                   get_huid(l_ocmbTarget));
            }
        }
    }

    // Any deconfigs happening above are delayed, so need to exit
    // early if istep errors out
    if (!iv_pStepError->isNull())
    {
        TRACFCOMP(g_trac_isteps_trace,
                INFO_MRK "call_omi_setup exited early because exp_omi_setup "
                "had failures");
    }
    else
    {
        // Run p10_omi_setup on the OMIC target
        TRACFCOMP(g_trac_isteps_trace,
            INFO_MRK"p10_omi_setup HWP target HUID 0x%.08x ",
            get_huid(iv_pOmic));

        FAPI_INVOKE_HWP(l_err, p10_omi_setup, l_fapi_omic_target);

        // process return code
        if (l_err)
        {
            TRACFCOMP(g_trac_isteps_trace,
                ERR_MRK"call p10_omi_setup HWP: failed on target 0x%08X. "
                TRACE_ERR_FMT,
                get_huid(iv_pOmic),
                TRACE_ERR_ARGS(l_err));

            // addErrorDetails may not be thread-safe. Proect with mutex.
            mutex_lock(&g_stepErrorMutex);

            // Capture error
            captureError(l_err, *iv_pStepError, HWPF_COMP_ID, iv_pOmic);

            mutex_unlock(&g_stepErrorMutex);
        }
        else
        {
            TRACFCOMP(g_trac_isteps_trace,
                INFO_MRK"SUCCESS running p10_omi_setup HWP on target HUID %.8X.",
                get_huid(iv_pOmic));
        }
    }
}


void* call_omi_setup (void *io_pArgs)
{
    IStepError l_StepError;
    errlHndl_t l_err = nullptr;
    TRACFCOMP( g_trac_isteps_trace, ENTER_MRK"call_omi_setup " );
    Util::ThreadPool<IStepWorkItem> threadpool;
    constexpr size_t MAX_OMIC_THREADS = 2;
    uint32_t l_numThreads = 0;

    do
    {
        // 12.6.a exp_omi_setup.C
        //        - Set any register (via I2C) on the Explorer before OMI is
        //          trained
        TargetHandleList l_omicTargetList;
        getAllChiplets(l_omicTargetList, TYPE_OMIC);
        TRACFCOMP(g_trac_isteps_trace,
                INFO_MRK"call_omi_setup: %d OMICs found ",
                l_omicTargetList.size());

        for (const auto & l_omic_target : l_omicTargetList)
        {
            //  Create a new workitem from this membuf and feed it to the
            //  thread pool for processing.  Thread pool handles workitem
            //  cleanup.
            threadpool.insert(new OmicWorkItem(*l_omic_target,
                                               l_StepError));
        }

        //Don't create more threads than we have targets
        size_t l_numTargets = l_omicTargetList.size();
        l_numThreads = std::min(MAX_OMIC_THREADS, l_numTargets);

        TRACFCOMP(g_trac_isteps_trace,
                  INFO_MRK"Starting %llu thread(s) to handle %llu OMIC target(s) ",
                   l_numThreads, l_numTargets);

        //Set the number of threads to use in the threadpool
        Util::ThreadPoolManager::setThreadCount(l_numThreads);

        //create and start worker threads
        threadpool.start();

        //wait for all workitems to complete, then clean up all threads.
        l_err = threadpool.shutdown();
        if(l_err)
        {
            TRACFCOMP(g_trac_isteps_trace,
                      ERR_MRK"call_omi_setup: thread pool returned an error "
                      TRACE_ERR_FMT,
                      TRACE_ERR_ARGS(l_err));

            // Capture error
            captureError(l_err, l_StepError, HWPF_COMP_ID, nullptr);
        }

        // Do not continue if an error was encountered
        if(!l_StepError.isNull())
        {
            TRACFCOMP( g_trac_isteps_trace,
                INFO_MRK "call_omi_setup exited early because exp_omi_setup "
                "had failures");
            break;
        }

    } while (0);

    // Set ATTR_ATTN_CHK_OCMBS to let ATTN know that we may now get attentions
    // from the OCMB, but interrupts from the OCMB are not enabled yet.
    TargetHandle_t sys = nullptr;
    targetService().getTopLevelTarget( sys );
    assert( sys != nullptr );
    sys->setAttr<ATTR_ATTN_CHK_OCMBS>(1);

    TRACFCOMP(g_trac_isteps_trace, EXIT_MRK"call_omi_setup ");

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

};
