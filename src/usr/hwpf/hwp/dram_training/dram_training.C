/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_training/dram_training.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2016                        */
/* [+] Google Inc.                                                        */
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
 *  @file dram_training.C
 *
 *  Support file for IStep: dram_training
 *   Step 13 DRAM Training
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <initservice/isteps_trace.H>
#include    <util/threadpool.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/util.H>
#include    <targeting/common/utilFilter.H>

#include    <hwpisteperror.H>
#include    <errl/errludtarget.H>

//  fapi support
#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>

//hb vddr support
#include "platform_vddr.H"
#include <initservice/initserviceif.H>

// Run on all Centaurs/MBAs, but needs to keep this one handy in case we
// want to limit them in VPO
const uint8_t UNLIMITED_RUN = 0xFF;
const uint8_t VPO_NUM_OF_MBAS_TO_RUN = UNLIMITED_RUN;
const uint8_t VPO_NUM_OF_MEMBUF_TO_RUN = UNLIMITED_RUN;

//  --  prototype   includes    --
#include    "dram_training.H"

#include    "mem_pll_setup/cen_mem_pll_initf.H"
#include    "mem_pll_setup/cen_mem_pll_setup.H"
#include    "mem_startclocks/cen_mem_startclocks.H"
#include    "mss_scominit/mss_scominit.H"
#include    "mss_ddr_phy_reset/mss_ddr_phy_reset.H"
#include    "mss_draminit/mss_draminit.H"
#include    "mss_draminit_training/mss_draminit_training.H"
#include    "mss_draminit_trainadv/mss_draminit_training_advanced.H"
#include    "mss_draminit_mc/mss_draminit_mc.H"
#include    "proc_throttle_sync.H"
#include    "../mc_config/mc_config.H"


namespace   DRAM_TRAINING
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   fapi;

typedef fapi::ReturnCode (*mss_FP_t)(const fapi::Target& i_target);
typedef std::list<errlHndl_t> errList;

class draminitTask;

//Simple multithread task controller
class dramTPool
{
  public:

    /**
     * @brief ctor
     *
     */
    dramTPool()
    {
        iv_errList.clear();
        iv_taskNum = 0;
        mutex_init(&iv_mutex);
        sync_cond_init(&iv_condvar);
        iv_pool.start();
    }

    ~dramTPool()
    {
        iv_pool.shutdown();
    }

    /**
     * @brief addErr():Adds the passed errorlog hndl to the errorlist.
     *        Used by the task running on the thread to store the error
     *
     * @param[in] i_err error log to store
     */

    void addErr(errlHndl_t i_err)
    {
        mutex_lock(&iv_mutex);
        if(i_err)
        {
            iv_errList.push_back(i_err);
        }
        mutex_lock(&iv_mutex);
    }

    /**
     * @brief getErrors():Retrieve the list of errors.
     *        Used by the master thread to 
     *        get the errors generated from the dispatched task
     *
     * @param[inout] io_list Reference to list of err handles
     */

    void getErrors(std::list<errlHndl_t> & io_list)
    {
        io_list.clear();
        io_list = iv_errList;
        iv_errList.clear();
    }

    /**
     * @brief dispatch(): Dispatches the task to a worker thread
     *
     * @param[in] i_task task to be dispatched on thread
     */

    void dispatch(draminitTask * i_task)
    {
        mutex_lock(&iv_mutex);
        iv_taskNum++;
        iv_pool.insert(i_task);
        mutex_unlock(&iv_mutex);
    }

    /**
     * @brief notifyDone
     *        Notifies once the dispatched task is done.Outstanding
     *        task list is updated and signals other threads waiting
     *        on condition variable. Any error on running the thread
     *        will be pushed to error list
     *
     * @param[in] i_task task currently active 
     * @param[in] i_err any error while performing the task, 
     */


    void notifyDone(draminitTask & i_task, errlHndl_t i_err)
    {
        mutex_lock(&iv_mutex);

        //If there is an error, then save it away
        if(i_err)
        {
            iv_errList.push_back(i_err);
        }

        iv_taskNum--;
        sync_cond_signal(&iv_condvar);


        mutex_unlock(&iv_mutex);
    }

    /**
     * @brief waitForCompletion
     *        Waits for the completion of dispatched tasks
     */

    void waitForCompletion()
    {
        mutex_lock(&iv_mutex);
        while(iv_taskNum)
        {
            sync_cond_wait(&iv_condvar, &iv_mutex);
        }
        mutex_unlock(&iv_mutex);
    }

  private:

    mutex_t iv_mutex;
    sync_cond_t iv_condvar;
    size_t iv_taskNum;
    errList iv_errList;
    Util::ThreadPool<draminitTask>  iv_pool;

    /**
     * @brief copy disabled
     */
    dramTPool(dramTPool &);

    /**
     * @brief assignment disabled
     */
    dramTPool & operator=(const dramTPool &);
};


/**
 * @brief draminit work item
 */
class draminitTask
{
  public:

    /**
     * @brief task function, called by threadpool
     */
    void operator()()
    {
        errlHndl_t l_err = NULL;

        //Do we need to iterate over MBA targets
        //This is necessary because the MBAs share a common CCS engine in HW
        if (iv_passMBAs)
        {
            // Get this centaurs MBA targets
            TARGETING::TargetHandleList l_mbaTargetList;
            getChildChiplets(l_mbaTargetList, iv_target, TYPE_MBA);

            for ( uint8_t l_mbaNum=0; l_mbaNum < l_mbaTargetList.size(); l_mbaNum++ )
            {
                //  make a local copy of the target for ease of use
                const TARGETING::Target*  l_mba_target = l_mbaTargetList[l_mbaNum];

                // Cast to a FAPI type of target.
                const fapi::Target l_fapi_mba_target( TARGET_TYPE_MBA_CHIPLET,
                                                      (const_cast<TARGETING::Target*>(l_mba_target)) );

                // Dump current run on target
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "Thread on MBA target HUID %.8X", TARGETING::get_huid(l_mba_target));


                FAPI_INVOKE_HWP(l_err, iv_func, l_fapi_mba_target);
                if(l_err)
                {
                    ErrlUserDetailsTarget(l_mba_target).addToLog(l_err );
                    iv_pool->addErr(l_err);
                    l_err = NULL;
                }
            }
        }
        else
        {
            // Cast to a FAPI type of target.
            const fapi::Target l_fapi_centaur( TARGET_TYPE_MEMBUF_CHIP,
                                               (const_cast<TARGETING::Target*>(iv_target)));

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "Thread on target HUID %.8X", TARGETING::get_huid(iv_target));

            FAPI_INVOKE_HWP(l_err, iv_func, l_fapi_centaur);

            if(l_err)
            {
                // capture the target data in the elog
                ErrlUserDetailsTarget(iv_target).addToLog(l_err );
            }
        }

        iv_pool->notifyDone(*this, l_err);
    }

    /**
     * @brief draminitTask
     *
     * draminit istep task creator that can be dispatched
     * to worker threads from threadpool
     *
     * @param[in] i_pool wrapper to util threadpool
     * @param[in] i_func fucntion pointer for the draminit task 
     * @param[in] i_target target input for draminit task
     * @param[in] i_targetMba Tells to parallelize per MBA (0/1)
     */
    draminitTask(dramTPool * i_pool, mss_FP_t i_func,
                 const TARGETING::Target *  i_target, bool i_targetMba):
      iv_pool(i_pool), iv_func(i_func), iv_target(i_target), iv_passMBAs(i_targetMba)
    {};

  private:

    dramTPool * iv_pool;
    mss_FP_t iv_func;
    const TARGETING::Target * iv_target;   // Always a Membuf
    bool iv_passMBAs;
};



//
//  Wrapper function to call host_disable_vddr
//
void*    call_host_disable_vddr( void *io_pArgs )
{
    errlHndl_t l_err = NULL;
    IStepError l_StepError;

    TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              ENTER_MRK"call_host_disable_vddr");

    // This function has Compile-time binding for desired platform
    l_err = platform_disable_vddr();

    if(l_err)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "ERROR 0x%.8X: call_host_disable_vddr returns error",
                  l_err->reasonCode());
        // Create IStep error log and cross reference to error that occurred
        l_StepError.addErrorDetails( l_err );

        errlCommit( l_err, HWPF_COMP_ID );

    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               EXIT_MRK"call_host_disable_vddr");

    return l_StepError.getErrorHandle();
}


//
//  Wrapper function to call mem_pll_initf
//
void*    call_mem_pll_initf( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    IStepError l_StepError;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mem_pll_initf entry" );

    // Get all Centaur targets
    TARGETING::TargetHandleList l_membufTargetList;
    getAllChips(l_membufTargetList, TYPE_MEMBUF);

    for (TargetHandleList::const_iterator
            l_membuf_iter = l_membufTargetList.begin();
            l_membuf_iter != l_membufTargetList.end();
            ++l_membuf_iter)
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target* l_pCentaur = *l_membuf_iter;

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running cen_mem_pll_initf HWP on "
                "target HUID %.8X", TARGETING::get_huid(l_pCentaur));

        //  call cen_mem_pll_initf to do pll init
        draminitTask * l_task = new draminitTask(& Singleton<dramTPool>::instance(),
                                               cen_mem_pll_initf, l_pCentaur, false);
        Singleton<dramTPool>::instance().dispatch(l_task);
        
    }

    //Wait for completion
    Singleton<dramTPool>::instance().waitForCompletion();
    errList l_errors;
    Singleton<dramTPool>::instance().getErrors(l_errors);
    for(errList::const_iterator errItr= l_errors.begin();
        errItr != l_errors.end(); ++errItr)
    {
        l_err = *errItr;
    
        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X: cen_mem_pll_initf HWP returns error",
                      l_err->reasonCode());

            //Create IStep error log and cross reference to error that occurred
            l_StepError.addErrorDetails(l_err);

            // Commit Error
            errlCommit(l_err, HWPF_COMP_ID);
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "SUCCESS: cen_mem_pll_initf HWP( )" );
        }
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mem_pll_initf exit" );

    return l_StepError.getErrorHandle();
}


//
//  Wrapper function to call mem_pll_setup
//
void*    call_mem_pll_setup( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    IStepError l_StepError;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mem_pll_setup entry" );

    // Get all Centaur targets
    TARGETING::TargetHandleList l_membufTargetList;
    getAllChips(l_membufTargetList, TYPE_MEMBUF);

    for (TargetHandleList::const_iterator
            l_membuf_iter = l_membufTargetList.begin();
            l_membuf_iter != l_membufTargetList.end();
            ++l_membuf_iter)
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target* l_pCentaur = *l_membuf_iter;

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running mem_pll_setup HWP on "
                "target HUID %.8X", TARGETING::get_huid(l_pCentaur));

        // Cast to a FAPI type of target.
        const fapi::Target l_fapi_centaur( TARGET_TYPE_MEMBUF_CHIP,
                 (const_cast<TARGETING::Target*>(l_pCentaur)));

        //  call cen_mem_pll_setup to verify lock
        FAPI_INVOKE_HWP(l_err, cen_mem_pll_setup, l_fapi_centaur);

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X: mem_pll_setup HWP returns error",
                      l_err->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_pCentaur).addToLog(l_err);

            //Create IStep error log and cross reference to error that occurred
            l_StepError.addErrorDetails(l_err);

            // Commit Error
            errlCommit(l_err, HWPF_COMP_ID);
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "SUCCESS: mem_pll_setup HWP( )" );
        }
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mem_pll_setup exit" );

    return l_StepError.getErrorHandle();
}

//
//  Wrapper function to call mem_startclocks
//
void*    call_mem_startclocks( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    IStepError l_StepError;

    TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,"call_mem_startclocks entry" );

    // Get all Centaur targets
    TARGETING::TargetHandleList l_membufTargetList;
    getAllChips(l_membufTargetList, TYPE_MEMBUF);

    for (TargetHandleList::const_iterator
            l_membuf_iter = l_membufTargetList.begin();
            l_membuf_iter != l_membufTargetList.end();
            ++l_membuf_iter)
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target* l_pCentaur = *l_membuf_iter;

        // Dump current run on target
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running cen_mem_startclocks HWP on "
                "target HUID %.8X", TARGETING::get_huid(l_pCentaur));

        // Cast to a FAPI type of target.
        const fapi::Target l_fapi_centaur( TARGET_TYPE_MEMBUF_CHIP,
                (const_cast<TARGETING::Target*>(l_pCentaur)) );

        //  call the HWP with each fapi::Target
        FAPI_INVOKE_HWP(l_err, cen_mem_startclocks, l_fapi_centaur);

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X: cen_mem_startclocks HWP returns error",
                      l_err->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_pCentaur).addToLog(l_err);

            //Create IStep error log and cross reference to error that occurred
            l_StepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );

        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "SUCCESS :  cen_mem_startclocks HWP( )" );
        }
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_mem_startclocks exit" );

    return l_StepError.getErrorHandle();
}



//
//  Wrapper function to call host_enable_vddr
//
void*    call_host_enable_vddr( void *io_pArgs )
{
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            ENTER_MRK"call_host_enable_vddr" );

    errlHndl_t l_err = NULL;
    IStepError l_StepError;

    // This fuction has compile-time binding for different platforms
    l_err = platform_enable_vddr();

    if( l_err )
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "ERROR 0x%.8X: call_host_enable_vddr returns error",
                  l_err->reasonCode());

        l_StepError.addErrorDetails( l_err );

        // Create IStep error log and cross reference to error that occurred
        l_StepError.addErrorDetails( l_err );

        // Commit Error
        errlCommit( l_err, HWPF_COMP_ID );
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               EXIT_MRK"call_host_enable_vddr" );

    return l_StepError.getErrorHandle();
}



//
//  Wrapper function to call mss_scominit
//
void*    call_mss_scominit( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    IStepError l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_scominit entry" );

    do
    {
        // Get all Centaur targets
        TARGETING::TargetHandleList l_membufTargetList;
        getAllChips(l_membufTargetList, TYPE_MEMBUF);

        for (TargetHandleList::const_iterator
                l_membuf_iter = l_membufTargetList.begin();
                l_membuf_iter != l_membufTargetList.end();
                ++l_membuf_iter)
        {
            //  make a local copy of the target for ease of use
            const TARGETING::Target* l_pCentaur = *l_membuf_iter;

            // Dump current run on target
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "Running mss_scominit HWP on "
                    "target HUID %.8X", TARGETING::get_huid(l_pCentaur));

            // Cast to a FAPI type of target.
            const fapi::Target l_fapi_centaur( TARGET_TYPE_MEMBUF_CHIP,
                    (const_cast<TARGETING::Target*>(l_pCentaur)) );

            //  call the HWP with each fapi::Target
            FAPI_INVOKE_HWP(l_err, mss_scominit, l_fapi_centaur);

            if (l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "ERROR 0x%.8X: mss_scominit HWP returns error",
                          l_err->reasonCode());

                // capture the target data in the elog
                ErrlUserDetailsTarget(l_pCentaur).addToLog(l_err);

                // Create IStep error log and cross reference to error that
                // occurred
                l_stepError.addErrorDetails( l_err );

                // Commit Error
                errlCommit( l_err, HWPF_COMP_ID );
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "SUCCESS :  mss_scominit HWP( )" );
            }
        }
        if (!l_stepError.isNull())
        {
            break;
        }

        // Run proc throttle sync
        // Get all functional proc chip targets
        TARGETING::TargetHandleList l_cpuTargetList;
        getAllChips(l_cpuTargetList, TYPE_PROC);

        for (TARGETING::TargetHandleList::const_iterator
             l_cpuIter = l_cpuTargetList.begin();
             l_cpuIter != l_cpuTargetList.end();
             ++l_cpuIter)
        {
            const TARGETING::Target* l_pTarget = *l_cpuIter;
            fapi::Target l_fapiproc_target( TARGET_TYPE_PROC_CHIP,
                 (const_cast<TARGETING::Target*>(l_pTarget)));

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "Running proc_throttle_sync HWP on "
                    "target HUID %.8X", TARGETING::get_huid(l_pTarget));

            // Call proc_throttle_sync
            FAPI_INVOKE_HWP( l_err, proc_throttle_sync, l_fapiproc_target );

            if (l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "ERROR 0x%.8X: proc_throttle_sync HWP returns error",
                          l_err->reasonCode());

                // Capture the target data in the elog
                ErrlUserDetailsTarget(l_pTarget).addToLog(l_err);

                // Create IStep error log and cross reference to error that occurred
                l_stepError.addErrorDetails( l_err );

                // Commit Error
                errlCommit( l_err, HWPF_COMP_ID );
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "SUCCESS :  proc_throttle_sync HWP( )" );
            }
        }

    } while (0);

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_scominit exit" );

    return l_stepError.getErrorHandle();
}

//
//  Wrapper function to call mss_ddr_phy_reset
//
void*  call_mss_ddr_phy_reset( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    IStepError l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                          "call_mss_ddr_phy_reset entry" );

    // Get all MBA targets
    TARGETING::TargetHandleList l_mbaTargetList;
    getAllChiplets(l_mbaTargetList, TYPE_MBA);

    // Limit the number of MBAs to run in VPO environment to save time.
    uint8_t l_mbaLimit = l_mbaTargetList.size();
    if (TARGETING::is_vpo() && (VPO_NUM_OF_MBAS_TO_RUN < l_mbaLimit))
    {
        l_mbaLimit = VPO_NUM_OF_MBAS_TO_RUN;
    }

    for ( uint8_t l_mbaNum=0; l_mbaNum < l_mbaLimit; l_mbaNum++ )
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target*  l_mba_target = l_mbaTargetList[l_mbaNum];

        // Dump current run on target
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running call_mss_ddr_phy_reset HWP on "
                "target HUID %.8X", TARGETING::get_huid(l_mba_target));

        // Cast to a FAPI type of target.
        const fapi::Target l_fapi_mba_target( TARGET_TYPE_MBA_CHIPLET,
                        (const_cast<TARGETING::Target*>(l_mba_target)) );

        //  call the HWP with each fapi::Target
        FAPI_INVOKE_HWP(l_err, mss_ddr_phy_reset, l_fapi_mba_target);

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%.8X: mss_ddr_phy_reset HWP returns error",
                    l_err->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_mba_target).addToLog( l_err );

            // Create IStep error log and cross reference to error that occurred
            l_stepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "SUCCESS :  call_mss_ddr_phy_reset HWP( )" );
        }
    } // end l_mbaNum loop

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_mss_ddr_phy_reset exit" );

    return l_stepError.getErrorHandle();
}

//
//  Wrapper function to call mss_post_draminit
//
void   mss_post_draminit( IStepError & l_stepError )
{
    errlHndl_t l_err = NULL;
    bool rerun_vddr = false;

    do {

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "mss_post_draminit entry" );

    set_eff_config_attrs_helper(MC_CONFIG::POST_DRAM_INIT, rerun_vddr);

    if ( rerun_vddr == false )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "mss_post_draminit: nothing to do" );
        break;
    }

    // Call mss_volt_vddr_offset to recalculate VDDR voltage

    l_err = MC_CONFIG::setMemoryVoltageDomainOffsetVoltage<
        TARGETING::ATTR_MSS_VOLT_VDDR_OFFSET_DISABLE,
        TARGETING::ATTR_MEM_VDDR_OFFSET_MILLIVOLTS,
        TARGETING::ATTR_VMEM_ID>();
    if(l_err)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "mss_post_draminit: "
            "ERROR 0x%08X: setMemoryVoltageDomainOffsetVoltage for VDDR domain",
            l_err->reasonCode());
        l_stepError.addErrorDetails(l_err);
        errlCommit(l_err,HWPF_COMP_ID);
        break;
    }
    else
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "mss_post_draminit: mss_volt_vddr_offset(): SUCCESS");
    }

    // Call HWSV to call POWR code
    // This fuction has compile-time binding for different platforms
    l_err = platform_adjust_vddr_post_dram_init();

    if( l_err )
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "ERROR 0x%.8X: mss_post_draminit: "
                  "platform_adjust_vddr_post_dram_init() returns error",
                  l_err->reasonCode());

        // Create IStep error log and cross reference to error that occurred
        l_stepError.addErrorDetails( l_err );

        // Commit Error
        errlCommit( l_err, HWPF_COMP_ID );
    }

    } while(0);

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "mss_post_draminit exit" );

    return;
}



//
//  Wrapper function to call mss_draminit
//
void*    call_mss_draminit( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    IStepError l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_draminit entry" );

    // Get all MBA targets
    TARGETING::TargetHandleList l_mbaTargetList;
    getAllChiplets(l_mbaTargetList, TYPE_MBA);

    // Limit the number of MBAs to run in VPO environment to save time.
    uint8_t l_mbaLimit = l_mbaTargetList.size();
    if (TARGETING::is_vpo() && (VPO_NUM_OF_MBAS_TO_RUN < l_mbaLimit))
    {
        l_mbaLimit = VPO_NUM_OF_MBAS_TO_RUN;
    }

    for ( uint8_t l_mbaNum=0; l_mbaNum < l_mbaLimit; l_mbaNum++ )
    {
        // Make a local copy of the target for ease of use
        const TARGETING::Target*  l_mba_target = l_mbaTargetList[l_mbaNum];

        // Dump current run on target
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running mss_draminit HWP on "
                "target HUID %.8X", TARGETING::get_huid(l_mba_target));

        // Cast to a FAPI type of target.
        const fapi::Target l_fapi_mba_target( TARGET_TYPE_MBA_CHIPLET,
                (const_cast<TARGETING::Target*>(l_mba_target)) );

        //  call the HWP with each fapi::Target
        FAPI_INVOKE_HWP(l_err, mss_draminit, l_fapi_mba_target);

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%.8X : mss_draminit HWP returns error",
                    l_err->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_mba_target).addToLog(l_err);

            // Create IStep error log and cross reference to error that occurred
            l_stepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "SUCCESS :  mss_draminit HWP( )" );
        }

    }   // endfor   mba's

    // call POST_DRAM_INIT function
    if(INITSERVICE::spBaseServicesEnabled())
    {
        mss_post_draminit(l_stepError);
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_draminit exit" );

    return l_stepError.getErrorHandle();
}


//
//  Wrapper function to call mss_draminit_training
//
void*    call_mss_draminit_training( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    IStepError l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "call_mss_draminit_training entry" );

    // Get all Centaur targets
    TARGETING::TargetHandleList l_membufTargetList;
    getAllChips(l_membufTargetList, TYPE_MEMBUF);

    for (TargetHandleList::const_iterator
         l_membuf_iter = l_membufTargetList.begin();
         l_membuf_iter != l_membufTargetList.end();
         ++l_membuf_iter)
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target* l_pCentaur = *l_membuf_iter;

        // Dump current run on target
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Running mss_draminit_training HWP on "
                   "target HUID %.8X", TARGETING::get_huid(l_pCentaur));

        draminitTask * l_task = new draminitTask(& Singleton<dramTPool>::instance(),
                                                 mss_draminit_training,
                                                 l_pCentaur, true);
        Singleton<dramTPool>::instance().dispatch(l_task);
    }

    //Wait for completion
    Singleton<dramTPool>::instance().waitForCompletion();
    errList l_errors;
    Singleton<dramTPool>::instance().getErrors(l_errors);
    for(errList::const_iterator errItr= l_errors.begin();
        errItr != l_errors.end(); ++errItr)
    {
        l_err = *errItr;

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%.8X : mss_draminit_training HWP returns error",
                    l_err->reasonCode());

            // Create IStep error log and cross reference to error that occurred
            l_stepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "SUCCESS :  mss_draminit_training HWP( )" );
        }

    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_mss_draminit_training exit" );

    return l_stepError.getErrorHandle();
}

//
//  Wrapper function to call mss_draminit_trainadv
//
void*    call_mss_draminit_trainadv( void *io_pArgs )
{
    errlHndl_t l_err = NULL;
    IStepError l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_mss_draminit_trainadv entry" );

    // Get all Centaur targets
    TARGETING::TargetHandleList l_membufTargetList;
    getAllChips(l_membufTargetList, TYPE_MEMBUF);

    for (TargetHandleList::const_iterator
         l_membuf_iter = l_membufTargetList.begin();
         l_membuf_iter != l_membufTargetList.end();
         ++l_membuf_iter)
    {
        //  make a local copy of the target for ease of use
        const TARGETING::Target* l_pCentaur = *l_membuf_iter;

        // Dump current run on target
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Running mss_draminit_training_advanced HWP on "
                   "target HUID %.8X", TARGETING::get_huid(l_pCentaur));

        draminitTask * l_task = new draminitTask(& Singleton<dramTPool>::instance(),
                                                 mss_draminit_training_advanced,
                                                 l_pCentaur, true);
        Singleton<dramTPool>::instance().dispatch(l_task);
    }

    //Wait for completion
    Singleton<dramTPool>::instance().waitForCompletion();
    errList l_errors;
    Singleton<dramTPool>::instance().getErrors(l_errors);
    for(errList::const_iterator errItr= l_errors.begin();
        errItr != l_errors.end(); ++errItr)
    {
        l_err = *errItr;

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "ERROR 0x%.8X : mss_draminit_training_advanced HWP returns error",
                l_err->reasonCode());

            // Create IStep error log and cross reference to error that occurred
            l_stepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );
        }

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "SUCCESS :  mss_draminit_training_advanced HWP( )" );
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                                "call_mss_draminit_trainadv exit" );

    return l_stepError.getErrorHandle();
}

//
//  Wrapper function to call mss_draminit_mc
//
void*    call_mss_draminit_mc( void *io_pArgs )
{
    errlHndl_t l_err = NULL;

    IStepError l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,"call_mss_draminit_mc entry" );

    // Get all centaur targets
    TARGETING::TargetHandleList l_mBufTargetList;
    getAllChips(l_mBufTargetList, TYPE_MEMBUF);

    // Limit the number of MBAs to run in VPO environment to save time.
    uint8_t l_memBufLimit = l_mBufTargetList.size();
    if (TARGETING::is_vpo() && (VPO_NUM_OF_MEMBUF_TO_RUN < l_memBufLimit))
    {
        l_memBufLimit = VPO_NUM_OF_MEMBUF_TO_RUN;
    }

    for ( uint8_t l_mBufNum=0; l_mBufNum < l_memBufLimit; l_mBufNum++ )
    {
        const TARGETING::Target* l_membuf_target = l_mBufTargetList[l_mBufNum];

        // Dump current run on target
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running mss_draminit_mc HWP on "
                "target HUID %.8X", TARGETING::get_huid(l_membuf_target));

        // Cast to a fapi target
        fapi::Target l_fapi_membuf_target( TARGET_TYPE_MEMBUF_CHIP,
                (const_cast<TARGETING::Target*>(l_membuf_target)) );

        //  call the HWP with each fapi::Target
        FAPI_INVOKE_HWP(l_err, mss_draminit_mc, l_fapi_membuf_target);

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%.8X : mss_draminit_mc HWP returns error",
                    l_err->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_membuf_target).addToLog( l_err );

            // Create IStep error log and cross reference to error that occurred
            l_stepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "SUCCESS :  mss_draminit_mc HWP( )" );
        }

    } // End; memBuf loop

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_draminit_mc exit" );

    return l_stepError.getErrorHandle();
}

//
//  Wrapper function to call mss_dimm_power_test
//
void*    call_mss_dimm_power_test( void *io_pArgs )
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_mss_dimm_power_test entry" );

//  This istep is a place holder

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_mss_dimm_power_test exit" );

    return NULL;
}

};   // end namespace
