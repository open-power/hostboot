/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/hwpThread.H $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
#ifndef __ISTEPS_HWPTHREAD_H
#define __ISTEPS_HWPTHREAD_H

/**
 * @file    hwpThread.H
 *  Contains semi-generic structures to run a HWP-based istep in parallel
 */

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>
#include    <util/threadpool.H>
#include    <sys/task.h>
#include    <initservice/istepdispatcherif.H>
#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>
#include    <initservice/isteps_trace.H>
#include    <istepHelperFuncs.H>
#include    <fapi2/plat_hwp_invoker.H>
#include    <targeting/common/targetservice.H>
#include    <initservice/isteps_trace.H>

namespace ISTEP
{

/*******************************************************************************
 * @brief Base work item class for running a HWP-based istep in parallel
 */
class HwpWorkItem
{
  protected:
    // @brief Error accumulator for this istep
    ISTEP_ERROR::IStepError* iv_pStepError;

    // @brief Target to execute HWP against
    const TARGETING::Target* iv_pTarget;

    // Name of HWP being executed
    const char* iv_hwpName;

  public:
    // @brief This is where all of the work is done
    void operator()();

    // This must be customized per HWP due to unique types
    virtual errlHndl_t run_hwp( void ) = 0;
    /* Typical example implementation
    {
        fapi2::Target<FAPI_TARGET> l_fapi_target(iv_pTarget);
        FAPI_INVOKE_HWP(l_err, iv_hwpFunction, l_fapi_target);
    }
    */

    // Optional function to run something after the HWP succeeds
    virtual void run_after_success( void ) { };

    /**
     * @brief Executes if the HWP returns an error
     *   Default implementation captures the error, can be overriden
     *   to provide more extensive behavior.
     *
     * @param[in] i_err  Error returned from FAPI_INVOKE_HWP
     */
    virtual void run_after_failure( errlHndl_t& i_err )
    {
        // Capture error
        captureError(i_err, *iv_pStepError, ISTEP_COMP_ID, iv_pTarget);
    };

    /**
     * @brief Start all threads and wait for completion
     *
     * @param[in] i_threadPool  ThreadPool object to run against
     * @param[in] i_stepError  Error accumulator for this istep
     * @param[in] i_numTargets  Number of targets involved, affects number of threads
     * @return  true if an error was encountered
     */
    static bool start_threads( Util::ThreadPool<ISTEP::HwpWorkItem>& i_threadPool,
                               ISTEP_ERROR::IStepError& i_istepError,
                               size_t i_numTargets );

    /**
     * @brief ctor
     *
     * @param[in] i_stepError  Error accumulator for this istep
     * @param[in] i_target  Target to execute HWP against
     * @param[in] i_hwpName  Name of HWP being executed
     */
    HwpWorkItem( ISTEP_ERROR::IStepError& i_stepError,
                 const TARGETING::Target& i_target,
                 const char* i_hwpName ):
      iv_pStepError(&i_stepError),
      iv_pTarget(&i_target),
      iv_hwpName(i_hwpName) {};

    /**
     * @brief Return an upper bound for the number of threads
     *        to spawn based on how much memory we have available
     * @return Maximum number of threads to allocate
     */
    static size_t getMaxThreads( void );

    // Must define virtual destructor
    virtual ~HwpWorkItem() { };


    // delete default copy/move constructors and operators
    HwpWorkItem() = delete;
    HwpWorkItem(const HwpWorkItem& ) = delete;
    HwpWorkItem& operator=(const HwpWorkItem& ) = delete;
    HwpWorkItem(HwpWorkItem&&) = delete;
    HwpWorkItem& operator=(HwpWorkItem&&) = delete;

  private:
    //
    // @brief Mutex to prevent threads from adding details to the step
    //        error log at the same time.
    static mutex_t cv_stepErrorMutex;
};

}; //namespace ISTEP

#endif //__ISTEPS_HWPTHREAD_H
