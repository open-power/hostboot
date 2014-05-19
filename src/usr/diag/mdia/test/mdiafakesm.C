/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/mdia/test/mdiafakesm.C $                         */
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
#include "mdiafakesm.H"
#include "mdiafakecm.H"
#include "../mdiatrace.H"
#include "../mdiasmimpl.H"

namespace MDIA
{

void FakeStateMachine1::processCommandTimeout(
                        const std::vector<uint64_t> & i_monitorIDs)
{
    //Holds a collection of i_monitorIDs that timedout
    static std::vector<uint64_t> monitorIDs;
    std::vector<uint64_t>::const_iterator monIter;

    for(monIter = i_monitorIDs.begin();
        monIter != i_monitorIDs.end();
        monIter++)
    {
        monitorIDs.push_back(*monIter);
    }

    //Only process Timeout if CommandMonitor has detected
    //expected number(iv_totalExpectedMons)of monitorIDs to timeout
    if(monitorIDs.size() == iv_totalExpectedMons)
    {
        if(true != isEqual(monitorIDs))
        {
            MDIA_FAST("Contents of iv_processedMonitors of size %d is not euqal"
                      "to content of iv_expectedMonitors of size %d",
                       monitorIDs.size(), iv_expectedMonitors.size());
            for(monIter = monitorIDs.begin();
                monIter != monitorIDs.end();
                monIter++)
            {
                MDIA_FAST("monitorIDs: %d", *monIter);
            }

            for(monIter = iv_expectedMonitors.begin();
                monIter != iv_expectedMonitors.end();
                monIter++)
            {
                MDIA_FAST("iv_expectedMonitors: %d", *monIter);
            }
        }
        else
            iv_contentsEqual = true;
    }

    //Expected number of monitorIDs have timedout.
    //Clear the vector before the next list timesout
    monitorIDs.clear();

    //Processed expected number of timeouts.
    //Ready to continue testing
    mutex_lock(iv_mutex);
    iv_processedTimeout = true;
    sync_cond_signal(iv_cond);
    mutex_unlock(iv_mutex);

}

void FakeStateMachine1::addMonitor(uint64_t i_mon)
{
    iv_expectedMonitors.push_back(i_mon);
}

void FakeStateMachine1::removeMonitor(const uint64_t i_position)
{
    iv_expectedMonitors.erase(iv_expectedMonitors.begin() + i_position);
}

bool FakeStateMachine1::isTimeoutProcessed() const
{
    return iv_processedTimeout;
}

bool FakeStateMachine1::isContentsEqual() const
{
    return iv_contentsEqual;
}

void FakeStateMachine1::setTotalExpectedMons(const uint64_t i_count)
{
    iv_totalExpectedMons = i_count;
}

void FakeStateMachine1::setSyncVars(mutex_t *i_mutex, sync_cond_t *i_cond)
{
    iv_mutex = i_mutex;
    iv_cond = i_cond;
}

FakeStateMachine1::FakeStateMachine1() : iv_processedTimeout(false),
                                         iv_contentsEqual(false),
                                         iv_totalExpectedMons(0)
{}

bool FakeStateMachine1::isEqual(
              const std::vector<uint64_t> & i_monitorIDs) const
{

    bool isEqual = true;
    if(i_monitorIDs.size() == iv_expectedMonitors.size())
    {
        std::vector<uint64_t>::const_iterator iterProc =
                                                i_monitorIDs.begin();
        std::vector<uint64_t>::const_iterator iterExpect =
                                                iv_expectedMonitors.begin();
        while(iterProc != i_monitorIDs.end())
        {
            if(*iterProc == *iterExpect)
            {
                iterProc++;
                iterExpect++;
            }
            else
            {
                isEqual = false;
                break;
            }
        }
    }
    else
    {
        isEqual = false;
    }

    return isEqual;
}
}
