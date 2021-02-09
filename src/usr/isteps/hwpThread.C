/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/hwpThread.C $                                  */
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
#include <hwpThread.H>

namespace ISTEP
{

mutex_t HwpWorkItem::cv_stepErrorMutex = MUTEX_INITIALIZER;

// Generically run a single HWP against the given target
void HwpWorkItem::operator()()
{
    errlHndl_t l_err = nullptr;

    // reset watchdog for each omic as this function can be very slow
    INITSERVICE::sendProgressCode();

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "Start %s on target HUID 0x%.8X",
               iv_hwpName,
               get_huid(iv_pTarget) );

    // Call HWP-specific function
    l_err = run_hwp();

    //  process return code
    if ( l_err )
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  ERR_MRK"call %s HWP: failed on target 0x%08X. "
                  TRACE_ERR_FMT,
                  iv_hwpName,
                  get_huid(iv_pTarget),
                  TRACE_ERR_ARGS(l_err));

        // addErrorDetails may not be thread-safe.  Protect with mutex.
        mutex_lock(&cv_stepErrorMutex);

        // Capture the error by default
        //  can be override by specific classes to do more
        run_after_failure(l_err);

        mutex_unlock(&cv_stepErrorMutex);
    }
    else
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  INFO_MRK"SUCCESS running %s HWP on target HUID %.8X. ",
                  iv_hwpName,
                  get_huid(iv_pTarget));

        // Optional function to run something after the HWP succeeds
        run_after_success();
    }
}


/**
 * @brief Return an upper bound for the number of threads
 *        to spawn based on system constraints
 */
size_t HwpWorkItem::getMaxThreads( void )
{
    // Default to no artificial limit
    size_t l_maxThreads = 128;

    // This is where we could put any kind of limitations based on
    //  our current memory footprint.  For now, assume we don't
    //  need one

    // If forced to, only allow a single thread.  This results in
    //  a completely serialized istep.  This can be useful for debug
    //  scenarios in the lab.
    auto l_forceSerial = TARGETING::UTIL::assertGetToplevelTarget()->
      getAttr<TARGETING::ATTR_FORCE_SERIAL_ISTEPS>();
    if( l_forceSerial != 0 )
    {
        l_maxThreads = 1;
    }

    return l_maxThreads;
}

/**
 * @brief Start all threads and wait for completion
 */
bool HwpWorkItem::start_threads( Util::ThreadPool<ISTEP::HwpWorkItem>& i_threadPool,
                                 ISTEP_ERROR::IStepError& i_istepError,
                                 size_t i_numTargets )
{
    bool l_error = false;

    //Don't create more threads than we have targets
    auto l_numThreads = std::min(ISTEP::HwpWorkItem::getMaxThreads(),
                                 i_numTargets);

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              INFO_MRK"Starting %llu thread(s) to handle %llu target(s) ",
              l_numThreads, i_numTargets);

    //Set the number of threads to use in the threadpool
    Util::ThreadPoolManager::setThreadCount(l_numThreads);

    //create and start worker threads
    i_threadPool.start();

    //wait for all workitems to complete, then clean up all threads.
    errlHndl_t l_err = i_threadPool.shutdown();
    if(l_err)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  ERR_MRK"thread pool returned an error "
                  TRACE_ERR_FMT,
                  TRACE_ERR_ARGS(l_err));

        // Capture error
        captureError(l_err, i_istepError, ISTEP_COMP_ID, nullptr);
        l_error = true;
    }
    return l_error;
};

}; //namespace ISTEP
