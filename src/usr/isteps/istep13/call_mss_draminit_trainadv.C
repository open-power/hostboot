/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep13/call_mss_draminit_trainadv.C $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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
#include <algorithm>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <isteps/hwpisteperror.H>
#include <initservice/isteps_trace.H>
#include <initservice/istepdispatcherif.H>
#include <util/threadpool.H>
#include <sys/task.h>

//  targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/util.H>
#include <targeting/common/utilFilter.H>
#include "istep13consts.H"
#include <util/misc.H>

#include    <fapi2.H>
#include    <fapi2/plat_hwp_invoker.H>
#include    <p9_mss_draminit_training_adv.H>
#include    <p9c_mss_draminit_training_advanced.H>

using   namespace   ERRORLOG;
using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   TARGETING;

namespace ISTEP_13
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
 * @brief Membuf specific work item class
 */
class MembufWorkItem: public IStepWorkItem
{
    private:
        IStepError* iv_pStepError;
        const TARGETING::Target* iv_pMembuf;

    public:
        /**
         * @brief task function, called by threadpool to run the HWP on the
         *        target
         */
         void operator()();

        /**
         * @brief ctor
         *
         * @param[in] i_membuf target membuf to operate on
         * @param[in] i_istepError error accumulator for this istep
         */
        MembufWorkItem(const TARGETING::Target& i_membuf,
                       IStepError& i_stepError):
            iv_pStepError(&i_stepError),
            iv_pMembuf(&i_membuf) {}

        // delete default copy/move constructors and operators
        MembufWorkItem() = delete;
        MembufWorkItem(const MembufWorkItem& ) = delete;
        MembufWorkItem& operator=(const MembufWorkItem& ) = delete;
        MembufWorkItem(MembufWorkItem&&) = delete;
        MembufWorkItem& operator=(MembufWorkItem&&) = delete;

        /**
         * @brief destructor
         */
        ~MembufWorkItem(){};
};

//******************************************************************************
void MembufWorkItem::operator()()
{
    errlHndl_t l_err = nullptr;

    // reset watchdog for each memb as this function can be very slow
    INITSERVICE::sendProgressCode();

    TARGETING::TargetHandleList l_mbaTargetList;
    getChildChiplets(l_mbaTargetList,
                    iv_pMembuf,
                    TYPE_MBA);

    for (auto l_mbaTarget : l_mbaTargetList)
    {
        // Dump current run on target
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "Running p9c_mss_draminit_training_advanced HWP on target HUID %.8X.",
            TARGETING::get_huid(l_mbaTarget));

        //  call the HWP with each target
        fapi2::Target <fapi2::TARGET_TYPE_MBA_CHIPLET>
                            l_fapi_mba_target(l_mbaTarget);

        FAPI_INVOKE_HWP(l_err,
                       p9c_mss_draminit_training_advanced,
                       l_fapi_mba_target);

        //  process return code.
        if ( l_err )
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR 0x%.8X : p9c_mss_draminit_training_advanced HWP returns error.",
                l_err->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_mbaTarget).addToLog(l_err);

            //addErrorDetails may not be thread-safe.  Protect with mutex.
            mutex_lock(&g_stepErrorMutex);

            // Create IStep error log and cross reference to error that occurred
            iv_pStepError->addErrorDetails( l_err );

            mutex_unlock(&g_stepErrorMutex);

            // Commit Error
            errlCommit( l_err, ISTEP_COMP_ID );

            break;
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "SUCCESS running p9c_mss_draminit_training_advanced HWP on target HUID %.8X.",
                   TARGETING::get_huid(l_mbaTarget));
        }
    }
}


//******************************************************************************
void* call_mss_draminit_trainadv (void *io_pArgs)
{
    errlHndl_t l_err = nullptr;
    IStepError l_stepError;
    Util::ThreadPool<IStepWorkItem> tp;
    uint32_t l_maxThreads = ISTEP13_MAX_THREADS;
    uint32_t l_numThreads = 0;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_mss_draminit_trainingadv entry");

    // Get all MCBIST targets
    TARGETING::TargetHandleList l_mcbistTargetList;
    getAllChiplets(l_mcbistTargetList, TYPE_MCBIST);

    for (const auto & l_mcbist_target : l_mcbistTargetList)
    {
        // Dump current run on target
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running p9_mss_draminit_training_adv HWP on "
                "target HUID %.8X", TARGETING::get_huid(l_mcbist_target));

        const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>
          l_fapi_mbcbist_target( l_mcbist_target);

         FAPI_INVOKE_HWP(l_err, p9_mss_draminit_training_adv,
                        l_fapi_mbcbist_target);

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "ERROR 0x%.8X : p9_mss_draminit_trainingadv HWP returns error",
                l_err->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_mcbist_target).addToLog( l_err );

            // Create IStep error log and cross reference to error that occurred
            l_stepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, ISTEP_COMP_ID );
        }

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "SUCCESS :  p9_mss_draminit_trainingadv HWP( )" );
    }

    // This step takes an obscene amount of time to run in Simics,
    //  going to skip it for now
    if( Util::isSimicsRunning() )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Skipping p9c_mss_draminit_training_advanced HWP in Simics");
    }
    else if(l_stepError.getErrorHandle() == nullptr)
    {
        // Get all Centaur targets
        TARGETING::TargetHandleList l_membufTargetList;
        getAllChips(l_membufTargetList, TYPE_MEMBUF);

        for (const auto & l_membuf : l_membufTargetList)
        {
            //  Create a new workitem from this membuf and feed it to the
            //  thread pool for processing.  Thread pool handles workitem
            //  cleanup.
            tp.insert(new MembufWorkItem(*l_membuf, l_stepError));
        }

        //Don't create more threads than we have targets
        size_t l_numTargets = l_membufTargetList.size();
        l_numThreads = std::min((size_t)l_maxThreads, l_numTargets);

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                  "Starting %u thread(s) to handle %u membuf target(s)", l_numThreads, l_numTargets);

        //Set the number of threads to use in the threadpool
        Util::ThreadPoolManager::setThreadCount(l_numThreads);

        //create and start worker threads
        tp.start();

        //wait for all workitems to complete, then clean up all threads.
        l_err = tp.shutdown();
        if(l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      ERR_MRK"call_mss_draminit_trainadv: thread pool returned an error");
            l_stepError.addErrorDetails(l_err);
            errlCommit(l_err, ISTEP_COMP_ID);
        }
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                                "call_mss_draminit_trainingadv exit" );

    return l_stepError.getErrorHandle();
}

};
