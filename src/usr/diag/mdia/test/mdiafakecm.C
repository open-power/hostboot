/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/mdia/test/mdiafakecm.C $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
