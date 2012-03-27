//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/diag/mdia/mdiasm.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
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
#include <diag/mdia/mdiamevent.H>
#include <hbotcompid.H>

using namespace TARGETING;
using namespace std;

namespace MDIA
{

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

    WorkFlowPropertiesIterator wit;

    for(wit = iv_workFlowProperties.begin();
        wit != iv_workFlowProperties.end();
        ++wit)
    {
        if((*wit)->log)
        {
            errlCommit((*wit)->log, HBMDIA_COMP_ID);
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

    WorkFlowAssoc it;
    WorkFlowProperties * p = 0;

    for(it = i_list.begin(); it != i_list.end(); ++it)
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

    while(!iv_done)
    {
        sync_cond_wait(&iv_cond, &iv_mutex);
    }

    mutex_unlock(&iv_mutex);
}

void StateMachine::start()
{
    mutex_lock(&iv_mutex);

    MDIA_FAST("sm: starting up");

    // schedule the first work items for all target / workFlow associations

    WorkFlowPropertiesIterator wit = iv_workFlowProperties.begin();

    for(; wit != iv_workFlowProperties.end(); ++wit)
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

        if(!iv_tp) {

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

    bool async = workItemIsAsync(*i_wfp);

    WorkFlowPhase workItem = *i_wfp->workItem;

    MDIA_FAST("sm: executing work item %d for: %p",
            workItem, getTarget(*i_wfp));

    mutex_unlock(&iv_mutex);

    errlHndl_t err = 0;

    switch(workItem)
    {
        // TODO...
        // do the appropriate thing based on the phase for this target

        case START_PATTERN_0:
        case START_PATTERN_1:
        case START_PATTERN_2:
        case START_PATTERN_3:
        case START_PATTERN_4:
        case START_PATTERN_5:
        case START_PATTERN_6:
        case START_PATTERN_7:
        case START_PATTERN_8:
        case START_SCRUB:

            err = doMaintCommand(*i_wfp);

            break;

        default:
            break;
    }

    mutex_lock(&iv_mutex);

    if(err)
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

    mutex_unlock(&iv_mutex);

    return dispatched;
}

errlHndl_t StateMachine::doMaintCommand(WorkFlowProperties & i_wfp)
{
    mutex_lock(&iv_mutex);

    // starting a maint cmd ...  register a timeout monitor

    // select a timeout based on the size of the address range
    // the command is being run against

    // uint32_t timeout = i_wfp.memSize / 1024; // TODO
    uint32_t timeout = 100;
    i_wfp.timer = getMonitor().addMonitor(timeout);

    WorkFlowPhase workItem = *i_wfp.workItem;
    bool restart = i_wfp.restartCommand;

    mutex_unlock(&iv_mutex);

    switch (workItem) {

        case START_PATTERN_0:
        case START_PATTERN_1:
        case START_PATTERN_2:
        case START_PATTERN_3:
        case START_PATTERN_4:
        case START_PATTERN_5:
        case START_PATTERN_6:
        case START_PATTERN_7:
        case START_PATTERN_8:
        case START_SCRUB:

            mutex_lock(&iv_mutex);

            if(restart) {

                MDIA_FAST("sm: issuing increment address on: %p",
                            getTarget(i_wfp));
                // TODO...restart the command (increment address)
            }
            else {

                MDIA_FAST("sm: issuing maint command on: %p",
                            getTarget(i_wfp));
                // TODO...start a command
            }

#ifdef MDIA_DO_POLLING

            MDIA_FAST("sm: polling on: %p", getTarget(i_wfp));

            getMonitor().startPolling(getTarget(i_wfp));
#endif
            mutex_unlock(&iv_mutex);

            break;

        default:
            break;
    }

    return 0;
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
        // TODO ... target not found...commit a log

        MDIA_FAST("sm: did not find target");
        return false;
    }

    bool resume = true, dispatched = false;

    WorkFlowProperties & wfp = **wit;

    // always unregister any existing maint cmd monitor

    getMonitor().removeMonitor(wfp.timer);

    MDIA_FAST("sm: processing event for: %p", getTarget(wfp));

    switch(i_event.type) {

        case COMMAND_COMPLETE:

            // command stopped or complete at end of last rank

            wfp.restartCommand = false;

            // move to the next command

            ++wfp.workItem;

            break;

        case COMMAND_STOPPED:

            // command stopped at end of some other rank

            wfp.restartCommand = true;

            break;

        case SKIP_MBA:

            // stop testing on this mba

            wfp.status = COMPLETE;

            break;

        case RESET_TIMER:

            // fall through
        default:

            resume = false;
            break;
    }

    // schedule the next work item

    if(resume)
        dispatched = scheduleWorkItem(wfp);

    mutex_unlock(&iv_mutex);

    return dispatched;
}

bool StateMachine::allWorkFlowsComplete()
{
    // check to see if all workFlows are complete

    bool allWorkFlowsComplete = true;

    WorkFlowPropertiesIterator wit = iv_workFlowProperties.begin();

    for(; wit != iv_workFlowProperties.end(); ++wit)
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

    WorkFlowPropertiesIterator wit = iv_workFlowProperties.begin();

    for(; wit != iv_workFlowProperties.end(); ++wit)
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

    MDIA_FAST("sm: shutting down...");

    if(iv_tp)
    {
        MDIA_FAST("Stopping threadPool...");
        iv_tp->shutdown();
        delete iv_tp;
        iv_tp = 0;
    }

    if(iv_monitor)
    {
        MDIA_FAST("Stopping monitor...");
        iv_monitor->shutdown();
        delete iv_monitor;
        iv_monitor = 0;
    }

    mutex_unlock(&iv_mutex);

    reset();

    MDIA_FAST("sm: ...shutdown complete");
}

StateMachine::~StateMachine()
{
    shutdown();

    sync_cond_destroy(&iv_cond);
    mutex_destroy(&iv_mutex);
}

StateMachine::StateMachine() : iv_done(true), iv_tp(0), iv_monitor(0)
{
    mutex_init(&iv_mutex);
    sync_cond_init(&iv_cond);
}
}
