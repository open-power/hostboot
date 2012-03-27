//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/diag/mdia/mdiamonitor.C $
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
#include <sys/time.h>
#include <targeting/common/util.H>
#include <targeting/common/target.H>
#include <vector>
#include <diag/mdia/mdiamevent.H>
#include "mdiamonitor.H"
#include "mdiasm.H"

using namespace TARGETING;

namespace MDIA
{

void CommandMonitor::startPolling(TargetHandle_t i_target)
{
#ifdef MDIA_DO_POLLING

    mutex_lock(&iv_mutex);

    iv_pollingList.push_back(i_target);

    mutex_unlock(&iv_mutex);
#endif
}

uint64_t CommandMonitor::addMonitor(uint64_t i_to)
{
    uint64_t monitor = 0;

    mutex_lock(&iv_mutex);

    monitor = ++iv_nextMonitor;

    // add a new monitor to our map

    iv_monitors[monitor] = i_to;

    mutex_unlock(&iv_mutex);

    return monitor;
}

void CommandMonitor::removeMonitor(uint64_t i_monitor)
{
    mutex_lock(&iv_mutex);

    // remove the specified monitor

    iv_monitors.erase(i_monitor);

    mutex_unlock(&iv_mutex);
}

tid_t CommandMonitor::getTID()
{
    tid_t tid = 0;

    mutex_lock(&iv_mutex);

    tid = iv_tid;

    mutex_unlock(&iv_mutex);

    return tid;
}

bool CommandMonitor::isShutdown()
{
    bool shutdown = false;

    mutex_lock(&iv_mutex);

    shutdown = iv_shutdown;

    mutex_unlock(&iv_mutex);

    return shutdown;
}

uint64_t CommandMonitor::getMonitorID()
{
    uint64_t monitor = 0;

    mutex_lock(&iv_mutex);

    monitor = iv_nextMonitor;

    mutex_unlock(&iv_mutex);

    return monitor;
}

uint64_t CommandMonitor::getMonitorMapTimeoutEntry(uint64_t i_monitor)
{
    uint64_t timeout = 0;

    mutex_lock(&iv_mutex);

    timeout = iv_monitors[i_monitor];

    mutex_unlock(&iv_mutex);

    return timeout;
}

void CommandMonitor::threadMain(StateMachine & i_sm)
{
    static const uint64_t singleStepPauseSecs = 0;
    static const uint64_t singleStepPauseNSecs = 10000000;
    static uint64_t wakeupIntervalNanoSecs = 0;

#ifdef MDIA_DO_POLLING
    TargetHandleList pollingList;
#endif

    // periodically wakeup and check for any command
    // timeouts

    if(TARGETING::is_vpo())
    {
        wakeupIntervalNanoSecs = TEN_CTX_SWITCHES_NS;
    }
    else
    {
        wakeupIntervalNanoSecs = singleStepPauseNSecs;
    }

    bool shutdown = false;
    std::vector<uint64_t> monitorsTimedout;

    while(true)
    {
        if( TARGETING::is_vpo() )
        {
            nanosleep(0, wakeupIntervalNanoSecs);
        }
        else
        {
            // sleep for 10 ms
            nanosleep(singleStepPauseSecs, wakeupIntervalNanoSecs);
        }

        mutex_lock(&iv_mutex);

        // check to see if the istep is finished

        shutdown = iv_shutdown;

        if(!shutdown)
        {
            // scan the monitor map and if any
            // timed out, inform the state machine

            iterator it = iv_monitors.begin();

            while(it != iv_monitors.end())
            {
                if(it->second >= wakeupIntervalNanoSecs)
                {
                    it->second -= wakeupIntervalNanoSecs;
                    it++;
                }

                else
                {
                    monitorsTimedout.push_back(it->first);

                    // remove the monitor

                    iv_monitors.erase(it++);
                }
            }

#ifdef MDIA_DO_POLLING
            swap(pollingList, iv_pollingList);
#endif
        }

        mutex_unlock(&iv_mutex);

        if(!monitorsTimedout.empty()) {
            i_sm.processCommandTimeout(monitorsTimedout);
            monitorsTimedout.clear();
        }

#ifdef MDIA_DO_POLLING
        // check for polling

        TargetHandleList::iterator pit = pollingList.begin();

        while(pit != pollingList.end())
        {
            MaintCommandEvent e;

            e.type = COMMAND_COMPLETE;
            e.target = *pit;
            i_sm.processMaintCommandEvent(e);
            pit = pollingList.erase(pit);
        }
#endif

        // istep finished...shutdown

        if(shutdown)
            break;
    }
}

namespace CommandMonitorImpl
{
struct ThreadArgs
{
    CommandMonitor * obj;
    StateMachine * sm;
};
}

void CommandMonitor::start(StateMachine & i_sm)
{
    using namespace CommandMonitorImpl;

    // start the monitor thread

    mutex_lock(&iv_mutex);

    // no-op if already started

    if(!iv_tid)
    {
        ThreadArgs * args = new ThreadArgs;
        if(NULL != args)
        {
            args->obj = this;
            args->sm = &i_sm;

            iv_shutdown = false;
            iv_tid = task_create(&CommandMonitor::staticMain, args);

        }
    }

    mutex_unlock(&iv_mutex);
}

void CommandMonitor::shutdown()
{
    mutex_lock(&iv_mutex);

    // instruct the monitor thread to shutdown

    iv_shutdown = true;

    // wait for it to exit
    // unless it was stopped already

    tid_t tid = iv_tid;
    iv_tid = 0;

    mutex_unlock(&iv_mutex);

    if(tid)
        task_wait_tid(tid, 0, 0);
}

void CommandMonitor::staticMain(void * i_args)
{
    using namespace CommandMonitorImpl;

    if(NULL != i_args)
    {
        ThreadArgs * args = static_cast<ThreadArgs *>(i_args);

        args->obj->threadMain(*args->sm);

        delete args;
        args = NULL;
    }
}

CommandMonitor::CommandMonitor() :
    iv_tid(0),
    iv_shutdown(false),
    iv_nextMonitor(0)
{
    mutex_init(&iv_mutex);
}

CommandMonitor::~CommandMonitor()
{
    shutdown();

    mutex_destroy(&iv_mutex);
}
}
