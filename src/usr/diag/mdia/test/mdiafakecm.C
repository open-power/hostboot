/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/diag/mdia/test/mdiafakecm.C $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
#include "mdiafakecm.H"
#include "../mdiasm.H"
#include "../mdiasmimpl.H"
#include "../mdiafwd.H"
#include "../mdiatrace.H"
#include <sys/time.h>

namespace MDIA
{
void FakeCommandMonitor::threadMain(StateMachine & i_sm)
{
    MDIA_DBG("FakeCommandMonitor: threadMain");
    static const uint64_t singleStepPauseSecs = 0;
    static const uint64_t singleStepPauseNSecs = 10000000;
    static uint64_t wakeupIntervalNanoSecs = 0;

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
    MonitorIDs monitorsTimedout;

    while(true)
    {
        if( TARGETING::is_vpo() )
        {
            nanosleep(0, wakeupIntervalNanoSecs);
        }
        else
        {
            nanosleep(singleStepPauseSecs, wakeupIntervalNanoSecs);
        }

        mutex_lock(&iv_mutex);
        // check to see if the istep is finished
        shutdown = iv_shutdown;

        if(!shutdown)
        {
            // scan the monitor map and if any
            // timed out, inform the state machine
            monitorMapIterator it = iv_monitors.begin();

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
                    //remove the monitor
                    iv_monitors.erase(it++);
                }
            }
        }

        mutex_unlock(&iv_mutex);

        if(!monitorsTimedout.empty()) {
            i_sm.processCommandTimeout(monitorsTimedout);
            monitorsTimedout.clear();
        }

        if(shutdown)
        {
            break;
        }
    }
}
};
