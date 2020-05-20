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
 * @brief Ocmb specific work item class
 */
class OcmbWorkItem: public IStepWorkItem
{
    private:
        IStepError* iv_pStepError;
        const TARGETING::Target* iv_pOcmb;

    public:
        /**
         * @brief task function, called by threadpool to run the HWP on the
         *        target
         */
         void operator()();

        /**
         * @brief ctor
         *
         * @param[in] i_Ocmb target Ocmb to operate on
         * @param[in] i_istepError error accumulator for this istep
         */
        OcmbWorkItem(const TARGETING::Target& i_Ocmb,
                       IStepError& i_stepError):
            iv_pStepError(&i_stepError),
            iv_pOcmb(&i_Ocmb) {}

        // delete default copy/move constructors and operators
        OcmbWorkItem() = delete;
        OcmbWorkItem(const OcmbWorkItem& ) = delete;
        OcmbWorkItem& operator=(const OcmbWorkItem& ) = delete;
        OcmbWorkItem(OcmbWorkItem&&) = delete;
        OcmbWorkItem& operator=(OcmbWorkItem&&) = delete;

        /**
         * @brief destructor
         */
        ~OcmbWorkItem(){};
};

//******************************************************************************
void OcmbWorkItem::operator()()
{
    errlHndl_t l_err = nullptr;

    // reset watchdog for each ocmb as this function can be very slow
    INITSERVICE::sendProgressCode();

    //  call the HWP with each target
    fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_ocmb_target
      (iv_pOcmb);

    TRACFCOMP(g_trac_isteps_trace,
              "exp_omi_setup HWP target HUID 0x%.08x",
              get_huid(iv_pOcmb));

    FAPI_INVOKE_HWP(l_err, exp_omi_setup, l_fapi_ocmb_target);

    //  process return code
    if ( l_err )
    {
        TRACFCOMP(g_trac_isteps_trace,
                  "ERROR : call exp_omi_setup HWP: failed on target 0x%08X. "
                  TRACE_ERR_FMT,
                  get_huid(iv_pOcmb),
                  TRACE_ERR_ARGS(l_err));

        //addErrorDetails may not be thread-safe.  Protect with mutex.
        mutex_lock(&g_stepErrorMutex);

        // Capture error
        captureError(l_err, *iv_pStepError, HWPF_COMP_ID, iv_pOcmb);

        mutex_unlock(&g_stepErrorMutex);
    }
    else
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "SUCCESS running exp_omi_setup HWP on target HUID %.8X.",
                   TARGETING::get_huid(iv_pOcmb));
    }
}


void* call_omi_setup (void *io_pArgs)
{
    IStepError l_StepError;
    errlHndl_t l_err = nullptr;
    TRACFCOMP( g_trac_isteps_trace, "call_omi_setup entry" );
    Util::ThreadPool<IStepWorkItem> threadpool;
    constexpr size_t MAX_OCMB_THREADS = 4;
    uint32_t l_numThreads = 0;

    do
    {
        // 12.6.a exp_omi_setup.C
        //        - Set any register (via I2C) on the Explorer before OMI is
        //          trained
        TargetHandleList l_ocmbTargetList;
        getAllChips(l_ocmbTargetList, TYPE_OCMB_CHIP);
        TRACFCOMP(g_trac_isteps_trace,
                "call_omi_setup: %d OCMBs found",
                l_ocmbTargetList.size());

        for (const auto & l_ocmb_target : l_ocmbTargetList)
        {
            //  Create a new workitem from this membuf and feed it to the
            //  thread pool for processing.  Thread pool handles workitem
            //  cleanup.
            threadpool.insert(new OcmbWorkItem(*l_ocmb_target,
                                               l_StepError));
        }

        //Don't create more threads than we have targets
        size_t l_numTargets = l_ocmbTargetList.size();
        l_numThreads = std::min(MAX_OCMB_THREADS, l_numTargets);

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                  "Starting %llu thread(s) to handle %llu OCMB target(s)",
                   l_numThreads, l_numTargets);

        //Set the number of threads to use in the threadpool
        Util::ThreadPoolManager::setThreadCount(l_numThreads);

        //create and start worker threads
        threadpool.start();

        //wait for all workitems to complete, then clean up all threads.
        l_err = threadpool.shutdown();
        if(l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      ERR_MRK"call_omi_setup: thread pool returned an error"
                      TRACE_ERR_FMT,
                      TRACE_ERR_ARGS(l_err));

            //addErrorDetails may not be thread-safe.  Protect with mutex.
            mutex_lock(&g_stepErrorMutex);

            // Capture error
            captureError(l_err, l_StepError, HWPF_COMP_ID, nullptr);

            mutex_unlock(&g_stepErrorMutex);
        }

        // Do not continue if an error was encountered
        if(!l_StepError.isNull())
        {
            TRACFCOMP( g_trac_isteps_trace,
                INFO_MRK "call_omi_setup exited early because exp_omi_setup "
                "had failures" );
            break;
        }

        // 12.6.b p10_omi_setup.C
        //        - File does not currently exist
        //        - TODO: RTC 248244

    } while (0);

    TRACFCOMP(g_trac_isteps_trace, "call_omi_setup exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

};
