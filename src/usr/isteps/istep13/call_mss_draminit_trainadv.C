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

/* FIXME RTC: 210975
#include    <fapi2.H>
#include    <fapi2/plat_hwp_invoker.H>
#include    <p9_mss_draminit_training_adv.H>
*/

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
}


//******************************************************************************
void* call_mss_draminit_trainadv (void *io_pArgs)
{
    IStepError l_stepError;
/* FIXME RTC: 210975
    errlHndl_t l_err = nullptr;
    Util::ThreadPool<IStepWorkItem> tp;

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

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                                "call_mss_draminit_trainingadv exit" );

*/
    return l_stepError.getErrorHandle();
}

};
