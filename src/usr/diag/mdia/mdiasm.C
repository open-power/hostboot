/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/mdia/mdiasm.C $                                  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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
#include <mdia/mdiamevent.H>
#include <hbotcompid.H>
#include <fapi.H>
#include <fapiPlatHwpInvoker.H>
#include <diag/prdf/prdfMain.H>
#include <devicefw/userif.H>

using namespace TARGETING;
using namespace ERRORLOG;
using namespace std;
using namespace fapi;
using namespace DeviceFW;

namespace MDIA
{

void StateMachine::running(bool & o_running)
{
    mutex_lock(&iv_mutex);

    o_running = !(iv_done || iv_shutdown);

    mutex_unlock(&iv_mutex);
}

void StateMachine::processCommandTimeout(const MonitorIDs & i_monitorIDs)
{
    MDIA_FAST("sm: processCommandTimeout");
    WorkFlowProperties *wkflprop = NULL;
    errlHndl_t err = NULL;

    vector<mss_MaintCmd *> stopCmds;

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
                stopCmds.push_back(static_cast<mss_MaintCmd *>((*wit)->data));
                (*wit)->data = NULL;

                (*wit)->status = COMMAND_TIMED_OUT;
                wkflprop = *wit;

                // log a timeout event

                TargetHandle_t target = getTarget(**wit);

                MDIA_ERR("sm: command %p: %d timed out on: %p",
                        stopCmds.back(),
                        *((*wit)->workItem),
                        target);

                /*@
                 * @errortype
                 * @reasoncode       MDIA::MAINT_COMMAND_TIMED_OUT
                 * @severity         ERRORLOG::ERRL_SEV_INFORMATIONAL
                 * @moduleid         MDIA::PROCESS_COMMAND_TIMEOUT
                 * @userData1        Associated memory diag work item
                 * @devdesc          A maint command timed out
                 */
                err = new ErrlEntry(
                        ERRL_SEV_INFORMATIONAL,
                        PROCESS_COMMAND_TIMEOUT,
                        MAINT_COMMAND_TIMED_OUT,
                        *((*wit)->workItem), 0);

                err->addHwCallout(target,
                        HWAS::SRCI_PRIORITY_HIGH,
                        HWAS::DECONFIG,
                        HWAS::GARD_NULL);

                errlCommit(err, MDIA_COMP_ID);

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

    // try and stop the commands that timed out.

    for(vector<mss_MaintCmd *>::iterator cit = stopCmds.begin();
            cit != stopCmds.end();
            ++cit)
    {
        MDIA_FAST("sm: stopping command: %p", *cit);

        ReturnCode fapirc = (*cit)->stopCmd();
        err = fapiRcToErrl(fapirc);

        if(err)
        {
            MDIA_ERR("sm: mss_MaintCmd::stopCmd failed");
            errlCommit(err, MDIA_COMP_ID);
        }

        fapirc = (*cit)->cleanupCmd();

        err = fapiRcToErrl(fapirc);

        if(err)
        {
            MDIA_ERR("sm: mss_MaintCmd::cleanupCmd failed");
            errlCommit(err, MDIA_COMP_ID);
        }

        delete (*cit);
    }
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
            // TODO (component, actions, etc)
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

        p = new WorkFlowProperties;

        p->assoc = it;
        p->workItem = getWorkFlow(it).begin();
        p->status = IN_PROGRESS;
        p->log = 0;
        p->timer = 0;
        p->restartCommand = false;
        p->memSize = 0; // TODO
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
    // and see if all phases have completed sucessfully

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
        // the priority is the number of iterations
        // through the memory multiplied by the memory size

        // TODO - multiply by memory size
        uint64_t priority = getRemainingWorkItems(i_wfp);

        if(!iv_tp)
        {
            MDIA_FAST("Starting threadPool...");
            iv_tp = new Util::ThreadPool<WorkItem>;
            iv_tp->start();
        }

        MDIA_FAST("sm: dispatching work item %d for: %p, priority: %d",
                *i_wfp.workItem, getTarget(i_wfp), priority);

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

        MDIA_FAST("sm: executing work item %d for: %p",
                workItem, getTarget(*i_wfp));

        mutex_unlock(&iv_mutex);

        errlHndl_t err = 0;
        int32_t rc = 0;

        switch(workItem)
        {
            // do the appropriate thing based on the phase for this target

            case RESTORE_DRAM_REPAIRS:

                rc = PRDF::restoreDramRepairs(getTarget(*i_wfp));

                break;

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
    // uint64_t timeout = i_wfp.memSize / 1024; // TODO RTC 47590
    uint64_t timeout = 60000000000;
    errlHndl_t err = NULL;

    uint64_t stopCondition = mss_MaintCmd::STOP_ON_END_ADDRESS
        | mss_MaintCmd::ENABLE_CMD_COMPLETE_ATTENTION;

    uint64_t workItem;
    bool restart;
    TargetHandle_t targetMba;
    ecmdDataBufferBase startAddr(64), endAddr(64);
    mss_MaintCmd * cmd = NULL;

    mutex_lock(&iv_mutex);

    // starting a maint cmd ...  register a timeout monitor
    uint64_t monitorId = getMonitor().addMonitor(timeout);

    i_wfp.timer = monitorId;
    workItem = *i_wfp.workItem;
    restart = i_wfp.restartCommand;
    targetMba = getTarget(i_wfp);
    cmd = static_cast<mss_MaintCmd *>(i_wfp.data);

    mutex_unlock(&iv_mutex);

    fapi::Target fapiMba(TARGET_TYPE_MBA_CHIPLET, targetMba);

    do {

        // setup the address range.
        // assume the full range for now

        ReturnCode fapirc = mss_get_address_range(
                fapiMba,
                MSS_ALL_RANKS,
                startAddr,
                endAddr);
        err = fapiRcToErrl(fapirc);

        if(err)
        {
            MDIA_FAST("sm: get_address_range failed");
            break;
        }

        if(restart)
        {
            // bump the starting address if we are restarting
            // a command

            mss_IncrementAddress incrementCmd(fapiMba);

            MDIA_FAST("sm: increment address on: %p", targetMba);

            fapirc = incrementCmd.setupAndExecuteCmd();

            err = fapiRcToErrl(fapirc);

            if(err)
            {
                MDIA_FAST("sm: setupAndExecuteCmd failed");
                break;
            }

            // read the address out so it can be passed
            // to the command being restarted

            uint64_t address;
            size_t size = sizeof(address);

            err = deviceRead(
                    targetMba,
                    &address,
                    size,
                    DEVICE_SCOM_ADDRESS(MBA01_MBMACAQ));

            if(err)
            {
                MDIA_FAST("sm: reading address failed");

                break;
            }

            startAddr.setDoubleWord(0, address);
            startAddr.insert(static_cast<uint32_t>(0), 40, 24); // addr is 0:39

            switch(workItem)
            {
                case START_RANDOM_PATTERN:
                    static_cast<mss_SuperFastRandomInit *>(
                            cmd)->setStartAddr(startAddr);
                    break;
                case START_SCRUB:
                    static_cast<mss_SuperFastRead *>(
                            cmd)->setStartAddr(startAddr);
                    break;
                case START_PATTERN_0:
                case START_PATTERN_1:
                case START_PATTERN_2:
                case START_PATTERN_3:
                case START_PATTERN_4:
                case START_PATTERN_5:
                case START_PATTERN_6:
                case START_PATTERN_7:
                    static_cast<mss_SuperFastInit *>(
                            cmd)->setStartAddr(startAddr);
                    break;
                default:
                    MDIA_ERR("sm: unrecognized maint command type %d:",
                            workItem);
                    break;
            }
        }

        else
        {
            // new command...use the full range

            switch(workItem)
            {
                case START_RANDOM_PATTERN:
                    cmd = new mss_SuperFastRandomInit(
                            fapiMba,
                            startAddr,
                            endAddr,
                            mss_MaintCmd::PATTERN_RANDOM,
                            stopCondition,
                            false);

                    MDIA_FAST("sm: random init %p on: %p", cmd, targetMba);
                    break;

                case START_SCRUB:
                    cmd = new mss_SuperFastRead(
                            fapiMba,
                            startAddr,
                            endAddr,
                            stopCondition,
                            false);

                    MDIA_FAST("sm: scrub %p on: %p", cmd, targetMba);
                    break;

                case START_PATTERN_0:
                case START_PATTERN_1:
                case START_PATTERN_2:
                case START_PATTERN_3:
                case START_PATTERN_4:
                case START_PATTERN_5:
                case START_PATTERN_6:
                case START_PATTERN_7:

                    cmd = new mss_SuperFastInit(
                            fapiMba,
                            startAddr,
                            endAddr,
                            static_cast<mss_MaintCmd::PatternIndex>(workItem),
                            stopCondition,
                            false);

                    MDIA_FAST("sm: init %p on: %p", cmd, targetMba);
                    break;

                default:
                    break;
            }

            if(!cmd)
            {
                MDIA_ERR("unrecognized maint command type %d on: %p",
                        workItem, targetMba);
                break;
            }
        }

        mutex_lock(&iv_mutex);

        i_wfp.data = cmd;

        mutex_unlock(&iv_mutex);

        // Command and address configured.
        // Invoke the command.

        fapirc = cmd->setupAndExecuteCmd();
        err = fapiRcToErrl(fapirc);

        if(err)
        {
            MDIA_FAST("sm: setupAndExecuteCmd %p failed", cmd);
            break;
        }

    } while(0);

    mutex_lock(&iv_mutex);

    if(err)
    {
        MDIA_FAST("sm: Running Maint Cmd failed");

        getMonitor().removeMonitor(monitorId);

        i_wfp.data = NULL;
    }

    mutex_unlock(&iv_mutex);

    if(err && cmd)
    {
        delete cmd;
    }

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
    bool resume = true, dispatched = false;

    mss_MaintCmd * cmd = NULL;
    ReturnCode fapirc;
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
        MDIA_ERR("sm: did not find target");
    }

    // if a command finishes (just) after the
    // timeout and we haven't had a chance to stop the
    // command yet, it may end up here.  Ignore it
    // and let the timeout thread do its job.

    else if((**wit).status != COMMAND_TIMED_OUT)
    {
        WorkFlowProperties & wfp = **wit;

        // always unregister any existing maint cmd monitor

        getMonitor().removeMonitor(wfp.timer);

        MDIA_FAST("sm: processing %p event for: %p", wfp.data, getTarget(wfp));

        switch(i_event.type)
        {
            case COMMAND_COMPLETE:

                // command stopped or complete at end of last rank

                wfp.restartCommand = false;

                // move to the next command

                ++wfp.workItem;

                // done with this maint command

                cmd = static_cast<mss_MaintCmd *>(wfp.data);
                wfp.data = NULL;

                break;

            case COMMAND_STOPPED:

                // command stopped at end of some other rank

                wfp.restartCommand = true;

                break;

            case SKIP_MBA:

                // stop testing on this mba

                wfp.status = COMPLETE;

                // done with this maint command

                cmd = static_cast<mss_MaintCmd *>(wfp.data);
                wfp.data = NULL;

                MDIA_FAST("sm: stopping command: %p", cmd);

                fapirc = cmd->stopCmd();
                err = fapiRcToErrl(fapirc);

                if(err)
                {
                    MDIA_ERR("sm: mss_MaintCmd::stopCmd failed");
                    errlCommit(err, MDIA_COMP_ID);
                }

                break;

            case RESET_TIMER:

                // fall through
            default:

                resume = false;
                break;
        }

        if(cmd)
        {
            // restore any init settings that
            // may have been changed by the command

            fapirc = cmd->cleanupCmd();
            err = fapiRcToErrl(fapirc);
            if(err)
            {
                MDIA_ERR("sm: mss_MaintCmd::cleanupCmd failed");
                errlCommit(err, MDIA_COMP_ID);
            }
        }

        // schedule the next work item

        if(resume && !iv_shutdown)
            dispatched = scheduleWorkItem(wfp);
    }

    mutex_unlock(&iv_mutex);

    if(cmd)
    {
        delete cmd;
    }

    return dispatched;
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

void StateMachine::shutdown()
{
    mutex_lock(&iv_mutex);

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
        tp->shutdown();
        delete tp;
    }

    if(monitor)
    {
        MDIA_FAST("Stopping monitor...");
        monitor->shutdown();
        delete monitor;
    }

    MDIA_FAST("sm: ...shutdown complete");
}

StateMachine::~StateMachine()
{
    shutdown();

    sync_cond_destroy(&iv_cond);
    mutex_destroy(&iv_mutex);
}

StateMachine::StateMachine() : iv_monitor(0), iv_done(true), iv_shutdown(false),
    iv_tp(0)
{
    mutex_init(&iv_mutex);
    sync_cond_init(&iv_cond);
}
}
