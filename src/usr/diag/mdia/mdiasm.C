/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/mdia/mdiasm.C $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
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
 * @file mdiasm.C
 * @brief mdia state machine implementation
 */

#include "mdiasm.H"
#include "mdiasmimpl.H"
#include "mdiatrace.H"
#include "mdiaworkitem.H"
#include "mdiamonitor.H"
#include <errl/errlmanager.H>
#include <stdio.h>
#include <hbotcompid.H>
#include <fapi2.H>
#include <plat_hwp_invoker.H>
#include <diag/prdf/prdfMain.H>
#include <devicefw/userif.H>
#include <targeting/common/utilFilter.H>
#include <errl/errludlogregister.H>
#include <initservice/istepdispatcherif.H>
#include <initservice/initserviceif.H>
#include <sys/time.h>
#include <sys/misc.h>

#include <exp_defaults.H>
#include <exp_rank.H>
#include <kind.H>
#include <hwp_wrappers.H>
#include <pldm/extended/pldm_watchdog.H>

#include <lib/mc/exp_port.H>
#include <generic/memory/lib/utils/fir/gen_mss_unmask.H>
#include <generic/memory/lib/utils/mc/gen_mss_port.H>


using namespace TARGETING;
using namespace ERRORLOG;
using namespace std;
using namespace DeviceFW;

namespace MDIA
{

// HW timeout value (in seconds).
//    Nimbus can support 256 GB DIMMs and the super fast commands do about 8 GB
//    per second. So on a dual drop port that is 64 seconds per port. That's not
//    bad for broadcast mode, however, we also have to support port-by-port
//    mode. So with 4 ports that 256 seconds per command. Marc recommended we
//    bump this up to a full 5 minutes to give us some wiggle room. Of course
//    this is the ultimate worst case and not the average case, but we don't
//    need to keep mucking with this value every time hardware takes longer
//    than expected.
static const uint64_t MAINT_CMD_HW_TIMEOUT = 300;

// Nimbus DD1.0 has a workaround that will likely cause the command to exceed
// the normal timout value. In test 110 seconds was not enough on ZZ systems.
// Bumping up to 300 seconds.
static const uint64_t MAINT_CMD_HW_TIMEOUT_DD10 = 300;

// When continuous traces are enabled, Hostboot will likely be throttled because
// of the sheer amount traces that need to be processed. 30 minutes seems to be
// working so far.
static const uint64_t MAINT_CMD_HW_TIMEOUT_LONG = 1800;

// The software timeout will be 10 minutes. Note that we will use the hardware
// timeout and commit informational error logs each time that expires until it
// eventually reaches the software threshold. This value contains the threshold.
//
// Potential improvement:
//   Since the HW timeout is quite a bit higher then expected, we are going to
//   get a lot fewer of these informational logs. We could change the design for
//   both HW and SW timeouts so that we always get an error log every 30 seconds
//   until either of the timeout thresholds is reached, but that is not required
//   at this time.
static const uint64_t MAINT_CMD_SW_TIMEOUT_TH = 600 / MAINT_CMD_HW_TIMEOUT;

void StateMachine::running(bool & o_running)
{
    mutex_lock(&iv_mutex);

    o_running = !(iv_done || iv_shutdown);

    mutex_unlock(&iv_mutex);
}

void addTimeoutFFDC(TargetHandle_t i_target, errlHndl_t & io_log)
{

    const uint64_t mccRegs[] = {
        DSTLFIR,
        DSTLFIR_MASK,
        DSTLFIR_ACT0,
        DSTLFIR_ACT1,
        DSTLCFG2,
    };

    const uint64_t ocmbRegs[] = {
        OCMB_MCBIST_FIR,
        OCMB_MCBIST_FIR_MASK,
        OCMB_MCBIST_FIR_ACT0,
        OCMB_MCBIST_FIR_ACT1,
        OMIDLFIR,
        OMIDLFIR_MASK,
        OMIDLFIR_ACT0,
        OMIDLFIR_ACT1,
    };

    const uint64_t procRegs[] = {
        IPOLL_MASK,
        IPOLL_STATUS,
        GLOBAL_CS_FIR,
        GLOBAL_RE_FIR,
        GLOBAL_UCS_FIR,
        GLOBAL_HA_FIR,
        MC0_CHIPLET_HA_FIR,
        MC0_CHIPLET_HA_FIR_MASK,
        MC1_CHIPLET_HA_FIR,
        MC1_CHIPLET_HA_FIR_MASK,
        MC2_CHIPLET_HA_FIR,
        MC2_CHIPLET_HA_FIR_MASK,
        MC3_CHIPLET_HA_FIR,
        MC3_CHIPLET_HA_FIR_MASK,
    };

    // Get the parent OMI
    TargetHandleList targetList;
    getParentAffinityTargets( targetList, i_target, CLASS_UNIT, TYPE_OMI );

    assert( targetList.size() == 1, "[MDIA] addTimeoutFFDC: Multiple parent"
            " OMIs found for OCMB i_target: 0x%08x", get_huid(i_target) );

    TargetHandle_t omi = targetList[0];

    // Get the parent proc
    ConstTargetHandle_t proc = getParentChip(omi);

    assert( nullptr != proc, "[MDIA] addTimeoutFFDC: Unable to get the "
            "parent proc from omi: 0x%08x", get_huid(omi) );

    // Get the parent MCC
    TargetHandleList mccList;
    getParentAffinityTargets( mccList, omi, CLASS_UNIT, TYPE_MCC );

    assert( mccList.size() == 1, "[MDIA] addTimeoutFFDC: Multiple parent"
            " MCCs found for OMI: 0x%08x", get_huid(omi) );

    TargetHandle_t mcc = mccList[0];

    const struct Entry
    {
        TARGETING::ConstTargetHandle_t target;
        const uint64_t * begin;
        const uint64_t * end;
    } tables[] = {
        {i_target, ocmbRegs, ocmbRegs + sizeof(ocmbRegs)/sizeof(*ocmbRegs)},
        {proc, procRegs, procRegs + sizeof(procRegs)/sizeof(*procRegs)},
        {mcc, mccRegs, mccRegs + sizeof(mccRegs)/sizeof(*mccRegs)},
    };

    for(const Entry * tableIt = tables;
            tableIt != tables + sizeof(tables)/sizeof(*tables);
            ++tableIt)
    {
        if(!tableIt->target)
        {
            continue;
        }

        for(const uint64_t * regIt = tableIt->begin;
                regIt != tableIt->end;
                ++regIt)
        {
            ErrlUserDetailsLogRegister udLogRegister(
                    tableIt->target,
                    DEVICE_SCOM_ADDRESS(*regIt));
            udLogRegister.addToLog(io_log);
        }
    }

    // collect these traces for timeout debugging
    io_log->collectTrace("MDIA_FAST",512);
    io_log->collectTrace(PRDF_COMP_NAME,512);
    io_log->collectTrace(FAPI_TRACE_NAME,512);
    io_log->collectTrace(FAPI_IMP_TRACE_NAME,512);

}

// Returns the calculated timeout value in nanoseconds.
uint64_t getTimeoutValue()
{
    // Out maintenance command timeout value will differ depending on a few
    // conditions. This function will find the timeout value we need and
    // return it.

    // Start with the default timeout value.
    uint64_t timeout = MAINT_CMD_HW_TIMEOUT; // in seconds

    // If continuous tracing is enabled.
    if ( timeout < MAINT_CMD_HW_TIMEOUT_LONG )
    {
        TargetHandle_t sys = nullptr;
        targetService().getTopLevelTarget(sys);
        HbSettings hbSettings = sys->getAttr<ATTR_HB_SETTINGS>();

        if ( hbSettings.traceContinuous )
        {
            timeout = MAINT_CMD_HW_TIMEOUT_LONG;
        }
    }

#ifdef CONFIG_PLDM
    // Ensure that the timeout is less than the watchdog timer.
    // NOTE: This should only be done on BMC based machines. The watch dog timer
    // is not checked on FSP based machines.
    if (timeout >= PLDM::g_pldmWatchdogPeriodSec)
    {
        // If the watchdog timer for some reason happens to be 10 seconds or
        // less, just set the MDIA timeout to the watchdog timeout. Otherwise,
        // set it to ten seconds less than the watchdog timer.
        timeout = ( PLDM::g_pldmWatchdogPeriodSec <= 10 )
                      ? PLDM::g_pldmWatchdogPeriodSec
                      : PLDM::g_pldmWatchdogPeriodSec - 10;
    }
#endif

    return timeout * NS_PER_SEC;
}

void StateMachine::processCommandTimeout(const MonitorIDs & i_monitorIDs)
{
    MDIA_FAST("sm: processCommandTimeout");

    WorkFlowProperties *wkflprop = NULL;
    errlHndl_t err = nullptr;

    mutex_lock(&iv_mutex);

    for(MonitorIDs::const_iterator monitorIt = i_monitorIDs.begin();
            monitorIt != i_monitorIDs.end();
            ++monitorIt)
    {
        for(WorkFlowPropertiesIterator wit = iv_workFlowProperties.begin();
                wit != iv_workFlowProperties.end();
                ++wit)
        {
            if((*wit)->timer == *monitorIt)
            {
                TargetHandle_t target   = getTarget(**wit);

                uint64_t firData = 0;
                uint64_t mskData = 0;
                size_t sz_uint64 = sizeof(uint64_t);

                uint64_t firAddr    = OCMB_MCBIST_FIR;
                uint64_t firAndAddr = OCMB_MCBIST_FIR_AND;
                uint64_t mskAddr    = OCMB_MCBIST_FIR_MASK;
                uint64_t bitMask    = 0x0020000000000000; // bit 10


                // Check for command complete. If set, don't time out.
                err = deviceRead( target, &firData, sz_uint64,
                                  DEVICE_SCOM_ADDRESS(firAddr) );

                if ( nullptr != err )
                {
                    MDIA_FAST("sm: deviceRead on 0x%08X failed HUID:0x%08X",
                              firAddr, get_huid(target));
                    //commit locally and let it timeout
                    errlCommit(err, MDIA_COMP_ID);
                }
                else
                {
                    firData &= bitMask;
                }

                if ( 0 != firData )
                {
                    err = deviceRead( target, &mskData, sz_uint64,
                                      DEVICE_SCOM_ADDRESS(mskAddr) );
                    if ( nullptr != err )
                    {
                        mskData = 0;
                        MDIA_FAST("sm: deviceRead on 0x%08X failed "
                                  "HUID:0x%08X",
                                  mskAddr, get_huid(target));
                        //commit locally and let it timeout
                        errlCommit(err, MDIA_COMP_ID);
                    }
                }

                // Pending maint cmd complete, reset timer
                if(firData & ~mskData)
                {
                    // Committing an info log to help debug SW timeout
                    if((*wit)->timeoutCnt >= MAINT_CMD_SW_TIMEOUT_TH)
                    {
                        MDIA_FAST("sm: committing a SW timeout info log "
                                  "for HUID:0x%08X", get_huid(target));

                        /*@
                         * @errortype
                         * @reasoncode       MDIA::MAINT_COMMAND_SW_TIMED_OUT
                         * @severity         ERRORLOG::ERRL_SEV_INFORMATIONAL
                         * @moduleid         MDIA::PROCESS_COMMAND_TIMEOUT
                         * @userData1        Associated memory diag work item
                         * @userData2        Target HUID
                         * @devdesc          A maint command SW timed out
                         */
                        err = new ErrlEntry(ERRL_SEV_INFORMATIONAL,
                                            PROCESS_COMMAND_TIMEOUT,
                                            MAINT_COMMAND_SW_TIMED_OUT,
                                            *((*wit)->workItem),
                                            get_huid(target));

                        // collect ffdc
                        addTimeoutFFDC(target, err);

                        errlCommit(err, MDIA_COMP_ID);

                        // reset for the next logging
                        (*wit)->timeoutCnt = 0;
                    }
                    else
                    {
                        // advance timeout counter
                        (*wit)->timeoutCnt++;
                    }

                    MDIA_FAST("sm: work item %d reset SW timed out on "
                              "HUID:0x%08X, timeoutCnt: %d",
                              *((*wit)->workItem), get_huid(target),
                              (*wit)->timeoutCnt);
                    // register a new timeout monitor
                    uint64_t monitorId =
                        getMonitor().addMonitor( getTimeoutValue() );
                    (*wit)->timer = monitorId;

                    break;
                }

                /*@
                 * @errortype
                 * @reasoncode       MDIA::MAINT_COMMAND_HW_TIMED_OUT
                 * @severity         ERRORLOG::ERRL_SEV_UNRECOVERABLE
                 * @moduleid         MDIA::PROCESS_COMMAND_TIMEOUT
                 * @userData1        Associated memory diag work item
                 * @userData2        Target HUID
                 * @devdesc          A maint command HW timed out
                 */
                errlHndl_t timeoutErrl = new ErrlEntry(
                        ERRL_SEV_UNRECOVERABLE,
                        PROCESS_COMMAND_TIMEOUT,
                        MAINT_COMMAND_HW_TIMED_OUT,
                        *((*wit)->workItem),
                        get_huid(target));

                // collect ffdc

                addTimeoutFFDC(target, timeoutErrl);

                timeoutErrl->addHwCallout(target,
                        HWAS::SRCI_PRIORITY_HIGH,
                        HWAS::DELAYED_DECONFIG,
                        HWAS::GARD_NULL);

                // If maint cmd complete bit is not on, time out
                MDIA_FAST("sm: stopping command HUID:0x%08X", get_huid(target));

                fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> fapiOcmb(target);
                FAPI_INVOKE_HWP( err, exp_stop, fapiOcmb );
                if ( nullptr != err )
                {
                    MDIA_ERR("sm: exp_stop failed");
                    errlCommit(err, MDIA_COMP_ID);
                }

                // exp_stop will set the command complete
                // attention so we need to clear those
                bitMask = ~bitMask;

                err = deviceWrite( target, &bitMask, sz_uint64,
                                   DEVICE_SCOM_ADDRESS(firAndAddr) );

                if ( nullptr != err )
                {
                    MDIA_FAST( "sm: deviceWrite on 0x%08X failed, HUID: "
                               "0x%08X", firAddr, get_huid(target) );
                    errlCommit( err, MDIA_COMP_ID );
                }


                (*wit)->data = NULL;

                (*wit)->status = COMMAND_TIMED_OUT;
                wkflprop = *wit;

                // log a timeout event
                MDIA_ERR( "sm: workItem %d HW timeout on HUID:0x%08X",
                          *((*wit)->workItem), get_huid(target) );

                errlCommit(timeoutErrl, MDIA_COMP_ID);

                break;
            }
        }

        // if this is the very last command(s), schedule must be called
        // so the waiting istep thread is signaled that we are done.

        // If no match is found (wkflprop), all the attentions came
        // in before the timeout(s) could be processed.  the prd thread
        // will have already started the next command(s), if any.

        if(wkflprop)
        {
            scheduleWorkItem(*wkflprop);
        }
    }

    mutex_unlock(&iv_mutex);
}

errlHndl_t StateMachine::run(const WorkFlowAssocMap & i_list)
{
    // load the workflow properties

    setup(i_list);

    // start work items

    start();

    // wait for all work items to finish

    wait();

    // act on workFlow errors

    mutex_lock(&iv_mutex);

    for(WorkFlowPropertiesIterator wit = iv_workFlowProperties.begin();
        wit != iv_workFlowProperties.end();
        ++wit)
    {
        if((*wit)->log)
        {
            errlCommit((*wit)->log, MDIA_COMP_ID);
        }
    }

    mutex_unlock(&iv_mutex);

    return 0;
}

void StateMachine::setup(const WorkFlowAssocMap & i_list)
{
    // clear out any properties from a previous run

    reset();

    mutex_lock(&iv_mutex);

    WorkFlowProperties * p = 0;

    for(WorkFlowAssoc it = i_list.begin(); it != i_list.end(); ++it)
    {
        // for each target / workFlow assoc,
        // initialize the workFlow progress indicator
        // to indicate that no work has been done yet
        // for the target

        p = new WorkFlowProperties();

        p->assoc = it;
        p->workItem = getWorkFlow(it).begin();
        p->status = IN_PROGRESS;
        p->log = 0;
        p->timer = 0;
        p->timeoutCnt = 0;

        p->data = NULL;

        iv_workFlowProperties.push_back(p);
    }

    if(iv_workFlowProperties.empty())
    {
        iv_done = true;
    }
    else
    {
        iv_done = false;
    }

    MDIA_FAST("sm: setup complete: target(s): %d, status: %d",
            iv_workFlowProperties.size(), iv_done);

    mutex_unlock(&iv_mutex);
}

void StateMachine::wait()
{
    mutex_lock(&iv_mutex);

    MDIA_FAST("sm: waiting for completion of %d target(s), status: %d",
            iv_workFlowProperties.size(), iv_done);

    // wait for everything to finish

    while(!iv_done && !iv_shutdown)
    {
        sync_cond_wait(&iv_cond, &iv_mutex);
    }

    mutex_unlock(&iv_mutex);
}

void StateMachine::start()
{
    mutex_lock(&iv_mutex);

    MDIA_FAST("sm: starting up");

    iv_shutdown = false;

    // schedule the first work items for all target / workFlow associations

    for(WorkFlowPropertiesIterator wit = iv_workFlowProperties.begin();
        wit != iv_workFlowProperties.end();
        ++wit)
    {
        scheduleWorkItem(**wit);
    }

    mutex_unlock(&iv_mutex);
}

bool StateMachine::scheduleWorkItem(WorkFlowProperties & i_wfp)
{
    // schedule work items for execution in the thread pool

    // see if the workFlow for this target is complete
    // and see if all phases have completed successfully

    if(i_wfp.workItem == getWorkFlow(i_wfp).end())
    {
        i_wfp.status = COMPLETE;
    }

    // see if the workFlow for this target is done...for better or worse
    // (failed or successful)
    // if it is, also check to see if all workFlows for all targets
    // are complete

    if(i_wfp.status != IN_PROGRESS && allWorkFlowsComplete())
    {
        // Clear BAD_DQ_BIT_SET bit
        TargetHandle_t top = NULL;
        targetService().getTopLevelTarget(top);
        ATTR_RECONFIGURE_LOOP_type reconfigAttr =
            top->getAttr<TARGETING::ATTR_RECONFIGURE_LOOP>();
        reconfigAttr &= ~RECONFIGURE_LOOP_BAD_DQ_BIT_SET;
        top->setAttr<TARGETING::ATTR_RECONFIGURE_LOOP>(reconfigAttr);

        // all workFlows are finished
        // release the init service dispatcher
        // thread waiting for completion

        MDIA_FAST("sm: all workflows finished");

        iv_done = true;
        sync_cond_broadcast(&iv_cond);
    }

    else if(i_wfp.status == IN_PROGRESS)
    {
        // still work left for this target

        // 1 - get the phase for the target,
        // 2 - create the work item
        // 3 - schedule it

        // determine the priority for the work item to be scheduled
        // the priority is the number of iterations through the memory
        uint64_t priority = getRemainingWorkItems(i_wfp);

        if(!iv_tp)
        {
            //create same number of tasks in the pool as there are cpu threads
            const size_t l_num_tasks = cpu_thread_count();
            Util::ThreadPoolManager::setThreadCount(l_num_tasks);
            MDIA_FAST("Starting threadPool with %u tasks...", l_num_tasks);
            iv_tp = new Util::ThreadPool<WorkItem>();
            iv_tp->start();
        }

        TargetHandle_t target = getTarget(i_wfp);

        MDIA_FAST( "sm: dispatching work item %d for: 0x%08x, priority: %d, ",
                   *i_wfp.workItem,
                   get_huid(target),
                   priority );

        iv_tp->insert(new WorkItem(*this, &i_wfp, priority));

        return true;
    }

    return false;
}

bool StateMachine::workItemIsAsync(WorkFlowProperties & i_wfp)
{
    bool async = true;

    switch (*i_wfp.workItem)
    {
        case RESTORE_DRAM_REPAIRS:
        case DUMMY_SYNC_PHASE:
        case CLEAR_HW_CHANGED_STATE:
        case ANALYZE_IPL_MNFG_CE_STATS:
        case POST_MEMDIAGS_HWPS:

            // no attention associated with these so
            // schedule the next work item now

            async = false;
            break;

        default:

            async = true;
            break;
    }

    return async;
}

/**
 * @brief Run post memdiags hardware procedures
 *
 * @param[in] i_trgt input ocmb target
 * @return nullptr on success; non-nullptr on error
 *
 */
errlHndl_t __runPostMemdiagsHwps( TargetHandle_t i_trgt )
{
    // The workflow is complete on this target. Trigger the hardware
    // procedures that need to be run on the target after memdiags.
    errlHndl_t err = nullptr;
    fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> fapiTrgt( i_trgt );

    do
    {
        // Calling after_memdiags on target, trace out stating so
        MDIA_FAST( "Running mss::unmask::after_memdiags HWP call on OCMB "
                   "target HUID 0x%08X.", get_huid(i_trgt));

        // Unmask mainline FIRs.
        FAPI_INVOKE_HWP( err, mss::unmask::after_memdiags, fapiTrgt );

        if ( err )
        {
            MDIA_FAST( "ERROR: mss::unmask::after_memdiags HWP call on OCMB "
                       "target HUID 0x%08x failed.", get_huid(i_trgt) );
            break;
        }
        else
        {
            MDIA_FAST( "SUCCESS: mss::unmask::after_memdiags HWP call on OCMB "
                       "target HUID 0x%08x.", get_huid(i_trgt) );
        }

        // Calling reset_reorder_queue_settings on target, trace out stating so
        MDIA_FAST( "Running mss::reset_reorder_queue_settings HWP call on OCMB "
                   "target HUID 0x%08X.", get_huid(i_trgt) );

        // Turn off FIFO mode to improve performance.
        FAPI_INVOKE_HWP( err, mss::reset_reorder_queue_settings, fapiTrgt );
        if ( err )
        {
            MDIA_FAST( "ERROR: mss::reset_reorder_queue_settings HWP call on "
                       "OCMB target HUID 0x%08x failed.", get_huid(i_trgt) );
            break;
        }
        else
        {
            MDIA_FAST( "SUCCESS: mss::reset_reorder_queue_settings HWP call "
                       "on OCMB target HUID 0x%08x.", get_huid(i_trgt) );
        }

    }while(0);

    return err;
}

bool StateMachine::executeWorkItem(WorkFlowProperties * i_wfp)
{
    bool dispatched = false;

    // thread pool work item entry point

    mutex_lock(&iv_mutex);

    // ensure this thread sees the most recent state

    if(!iv_shutdown)
    {
        bool async = workItemIsAsync(*i_wfp);

        uint64_t workItem = *i_wfp->workItem;

        MDIA_FAST("sm: executing work item %d for: 0x%08x",
                workItem, get_huid(getTarget(*i_wfp)));

        mutex_unlock(&iv_mutex);

        errlHndl_t err = 0;
        int32_t rc = 0;

        switch(workItem)
        {
            // do the appropriate thing based on the phase for this target

            case RESTORE_DRAM_REPAIRS:
            {
                TargetHandle_t target = getTarget( *i_wfp );
                rc = PRDF::restoreDramRepairs<TYPE_OCMB_CHIP>( target );
                break;
            }
            case START_PATTERN_0:
            case START_PATTERN_1:
            case START_PATTERN_2:
            case START_PATTERN_3:
            case START_PATTERN_4:
            case START_PATTERN_5:
            case START_PATTERN_6:
            case START_PATTERN_7:
            case START_RANDOM_PATTERN:
            case START_SCRUB:

                err = doMaintCommand(*i_wfp);

                break;

            case CLEAR_HW_CHANGED_STATE:

                mutex_lock(&iv_mutex);

                clearHWStateChanged(getTarget(*i_wfp));

                mutex_unlock(&iv_mutex);

                break;

            case ANALYZE_IPL_MNFG_CE_STATS:
            {
                MDIA_FAST("Executing analyzeIplCEStats");
                bool calloutMade = false;
                TargetHandle_t target = getTarget( *i_wfp );
                rc = PRDF::analyzeIplCEStats( target,
                                              calloutMade );
                if( rc )
                {
                    MDIA_FAST("executeWorkItem: PRDF::analyzeIplCEStats failed "
                      "rc:%d HUID:0x%08X", rc, get_huid(target));
                }
                if( calloutMade )
                {
                    // There is no reason to update HCDB as we are doing
                    // deferred deconfig. HCDB will be updated at end of istep
                    // during deferred deconfig only. Just adding information
                    // message here.
                    MDIA_FAST("PRD performed HW callouts during"
                              "analyzeIplCEStats");
                }

            }
                break;

            case POST_MEMDIAGS_HWPS:

                mutex_lock(&iv_mutex);

                err = __runPostMemdiagsHwps( getTarget( *i_wfp ) );

                mutex_unlock(&iv_mutex);

                break;

            default:
                break;
        }

        mutex_lock(&iv_mutex);

        if(err || rc)
        {
            // stop the workFlow for this target

            i_wfp->status = FAILED;
            i_wfp->log = err;
        }

        else if(!async)
        {
            // sync work item -
            // move the workFlow pointer to the next phase
            ++i_wfp->workItem;
        }

        if(err || !async)
        {
            // check to see if this was the last workFlow
            // in progress (if there was an error), or for sync
            // work items, schedule the next work item
            dispatched = scheduleWorkItem(*i_wfp);
        }
    }
    mutex_unlock(&iv_mutex);

    return dispatched;
}

errlHndl_t StateMachine::doMaintCommand(WorkFlowProperties & i_wfp)
{
    errlHndl_t err = nullptr;
    uint64_t workItem;

    TargetHandle_t target;

    // starting a maint cmd ...  register a timeout monitor
    uint64_t maintCmdTO = getTimeoutValue();

    mutex_lock(&iv_mutex);

    uint64_t monitorId = CommandMonitor::INVALID_MONITOR_ID;
    i_wfp.timeoutCnt = 0; // reset for new work item
    workItem = *i_wfp.workItem;

    target = getTarget(i_wfp);

    mutex_unlock(&iv_mutex);

    do
    {
        // new command...use the full range

        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> fapiOcmb(target);
        mss::mcbist::stop_conditions<mss::mc_type::EXPLORER> stopCond;

        switch(workItem)
        {
            case START_RANDOM_PATTERN:

                FAPI_INVOKE_HWP( err, exp_sf_init, fapiOcmb,
                                 mss::mcbist::PATTERN_RANDOM );
                MDIA_FAST( "sm: random init %p on: 0x%08x", fapiOcmb,
                           get_huid(target) );
                break;

            case START_SCRUB:

                // set stop conditions
                stopCond.set_pause_on_mpe(mss::ON);
                stopCond.set_pause_on_ue( mss::ON);
                stopCond.set_pause_on_aue(mss::ON);
                stopCond.set_nce_inter_symbol_count_enable(mss::ON);
                stopCond.set_nce_soft_symbol_count_enable( mss::ON);
                stopCond.set_nce_hard_symbol_count_enable( mss::ON);
                if ( iv_globals.queryMnfgIplCeChecking() )
                {
                    stopCond.set_pause_on_nce_hard(mss::ON);
                }

                FAPI_INVOKE_HWP( err, exp_sf_read, fapiOcmb,
                                 stopCond );
                MDIA_FAST( "sm: scrub %p on: 0x%08x", fapiOcmb,
                           get_huid(target) );
                break;

            case START_PATTERN_0:
            case START_PATTERN_1:
            case START_PATTERN_2:
            case START_PATTERN_3:
            case START_PATTERN_4:
            case START_PATTERN_5:
            case START_PATTERN_6:
            case START_PATTERN_7:

                FAPI_INVOKE_HWP( err, exp_sf_init, fapiOcmb,
                                 workItem );
                MDIA_FAST( "sm: init %p on: 0x%08x", fapiOcmb,
                           get_huid(target) );
                break;

            default:
                MDIA_ERR( "unrecognized work item type %d on: 0x%08x",
                          workItem, get_huid(target) );
                break;
        }
        if( nullptr != err )
        {
            MDIA_FAST( "sm: Running Maint Cmd failed" );
            i_wfp.data = nullptr;
        }

        if ( nullptr == err )
        {
            // Start a timeout monitor
            mutex_lock(&iv_mutex);

            monitorId = getMonitor().addMonitor(maintCmdTO);
            i_wfp.timer = monitorId;

            mutex_unlock(&iv_mutex);
        }

    } while(0);



    return err;
}

CommandMonitor & StateMachine::getMonitor()
{
    if(!iv_monitor)
    {
        MDIA_FAST("Starting monitor...");

        iv_monitor = new CommandMonitor();
        iv_monitor->start(*this);
    }

    return *iv_monitor;
}

bool StateMachine::processMaintCommandEvent(const MaintCommandEvent & i_event)
{
    MDIA_FAST("sm: processMaintCommandEvent");

    enum
    {
        CLEANUP_CMD = 0x8,
        DELETE_CMD = 0x4,
        STOP_CMD = 0x2,
        START_NEXT_CMD = 0x1,
        DISPATCHED = 0x80,
    };

    uint64_t flags = 0;

    TargetHandle_t target = NULL;
    errlHndl_t err = NULL;

    mutex_lock(&iv_mutex);

    WorkFlowPropertiesIterator wit = iv_workFlowProperties.begin();

    for(; wit != iv_workFlowProperties.end(); ++wit)
    {
        if(getTarget(**wit) == i_event.target)
        {
            break;
        }
    }

    if(wit == iv_workFlowProperties.end())
    {
        MDIA_ERR("sm: did not find target: 0x%08x",
                 get_huid(i_event.target));
    }

    // if a command finishes (just) after the
    // timeout and we haven't had a chance to stop the
    // command yet, it may end up here.  Ignore it
    // and let the timeout thread do its job.
    // Also ignore when it is in failed state.

    else if(((**wit).status != COMMAND_TIMED_OUT) &&
            ((**wit).status != FAILED))
    {
        WorkFlowProperties & wfp = **wit;

        // always unregister any existing maint cmd monitor

        getMonitor().removeMonitor(wfp.timer);

        target = getTarget(**wit);

        MDIA_FAST("sm: processing event for: 0x%08x, target: 0x%08x, type: %x",
                  get_huid(getTarget(wfp)), get_huid(target), i_event.type);

        MaintCommandEventType eventType = i_event.type;

        // If shutdown is requested and we're not doing explicitly specified
        // pattern testing, skip testing on all targets.
        if ( INITSERVICE::isShutdownRequested() &&
             (COMMAND_COMPLETE == eventType) &&
             !iv_globals.querySpecialPatternTesting() )
        {
            MDIA_FAST("sm: shutdown requested, overrding event "
                      "for: 0x%08x, target: %p, type: 0x%x, policy: %d",
                      get_huid(getTarget(wfp)), target, i_event.type,
                      iv_globals.querySpecialPatternTesting());

            eventType = STOP_TESTING;
        }

        // Reset the watchdog timer after running each pattern
        INITSERVICE::sendProgressCode();

        switch(eventType)
        {
            case COMMAND_COMPLETE:

                // command stopped or complete at end of last rank
                // move to the next command
                ++wfp.workItem;

                // done with this maint command
                flags = DELETE_CMD | START_NEXT_CMD;
                break;

            case STOP_TESTING:

                // stop testing on this target
                wfp.status = COMPLETE;

                // done with this command
                flags = DELETE_CMD | STOP_CMD | START_NEXT_CMD;

                break;

            case CHNL_FAILED:

                // Stop testing on this target
                wfp.status = COMPLETE;

                // Done with this command. Note: since the channel has failed,
                // putscoms to the target may not work, as such we cannot stop
                // the mcbist command. We make the assertion that since the
                // channel has failed, nothing else is happening on that
                // channel afterwards and we do not need to stop the command.
                flags = DELETE_CMD | START_NEXT_CMD;
                break;

            case RESET_TIMER:
                flags = CLEANUP_CMD | DELETE_CMD;
                break;

            default:
                assert( false, "processMaintCommandEvent: unsupported event "
                        "type" );
                break;
        }

        if(flags & STOP_CMD)
        {
            MDIA_FAST("sm: stopping command: %p", target);
            fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> fapiOcmb(target);
            FAPI_INVOKE_HWP( err, exp_stop, fapiOcmb );

            if(nullptr != err)
            {
                MDIA_ERR("sm: exp_stop failed");
                errlCommit(err, MDIA_COMP_ID);
            }
        }

        // schedule the next work item
        if((flags & START_NEXT_CMD) && !iv_shutdown)
        {
            if(scheduleWorkItem(wfp))
            {
                flags |= DISPATCHED;
            }
        }
    }

    mutex_unlock(&iv_mutex);

    return (flags & DISPATCHED);
}

bool StateMachine::allWorkFlowsComplete()
{
    // check to see if all workFlows are complete

    bool allWorkFlowsComplete = true;

    for(WorkFlowPropertiesIterator wit = iv_workFlowProperties.begin();
        wit != iv_workFlowProperties.end();
        ++wit)
    {
        if((*wit)->status == IN_PROGRESS)
        {
            allWorkFlowsComplete = false;
            break;
        }
    }

    return allWorkFlowsComplete;
}

void StateMachine::reset()
{
    mutex_lock(&iv_mutex);

    for(WorkFlowPropertiesIterator wit = iv_workFlowProperties.begin();
        wit != iv_workFlowProperties.end();
        ++wit)
    {
        if((**wit).log)
        {
            delete (**wit).log;
        }

        delete *wit;
    }

    iv_workFlowProperties.clear();

    mutex_unlock(&iv_mutex);
}

errlHndl_t StateMachine::shutdown()
{
    mutex_lock(&iv_mutex);

    errlHndl_t l_errl = nullptr;

    Util::ThreadPool<WorkItem> * tp = iv_tp;
    CommandMonitor * monitor = iv_monitor;

    iv_tp = 0;
    iv_monitor = 0;

    iv_shutdown = true;

    mutex_unlock(&iv_mutex);

    MDIA_FAST("sm: shutting down...");

    if(tp)
    {
        MDIA_FAST("Stopping threadPool...");
        l_errl = tp->shutdown();
        delete tp;
    }

    if(monitor)
    {
        MDIA_FAST("Stopping monitor...");
        monitor->shutdown();
        delete monitor;
    }

    MDIA_FAST("sm: ...shutdown complete");
    return l_errl;
}

StateMachine::~StateMachine()
{
    errlHndl_t l_errl = shutdown();
    if(l_errl)
    {
        errlCommit(l_errl, MDIA_COMP_ID);
    }

    sync_cond_destroy(&iv_cond);
    mutex_destroy(&iv_mutex);
}

StateMachine::StateMachine() : iv_monitor(0), iv_done(true), iv_shutdown(false),
    iv_tp(0), iv_globals()
{
    mutex_init(&iv_mutex);
    sync_cond_init(&iv_cond);
}

void StateMachine::setGlobals(Globals & i_globals)
{
    mutex_lock(&iv_mutex);

    iv_globals = i_globals;

    mutex_unlock(&iv_mutex);
}

}
