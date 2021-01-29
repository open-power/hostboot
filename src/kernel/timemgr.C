/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/timemgr.C $                                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2010,2021                        */
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
#include <kernel/timemgr.H>
#include <kernel/scheduler.H>
#include <util/singleton.H>
#include <kernel/task.H>
#include <kernel/cpumgr.H>
#include <util/misc.H>
#include <kernel/misc.H>
#include <sys/task.h>
#include <kernel/doorbell.H>

uint64_t TimeManager::iv_timebaseFreq = 0xFFFFFFFF;
uint64_t TimeManager::iv_timeslicePerSec = DEFAULT_TIMESLICE_PER_SEC;

bool TimeManager::cv_isSimicsRunning = Util::isSimicsRunning();

void TimeManager::init()
{
    Singleton<TimeManager>::instance()._init();
}

void TimeManager::_init()
{
    iv_timebaseFreq = 512000000ULL;
}

void TimeManager::init_cpu(cpu_t* cpu)
{
    Singleton<TimeManager>::instance()._init_cpu(cpu);
}

void TimeManager::_init_cpu(cpu_t* cpu)
{
    cpu->delay_list = new delaylist_t();
}

uint64_t TimeManager::convertSecToTicks(uint64_t i_sec, uint64_t i_nsec)
{
    // This code will handle times almost up to a year without overflowing a
    // uint64.  This should be more than sufficient for our purposes.

    // Result = ((sec * 10^9 + nsec) * tb) / 10^9.
    uint64_t result = ((i_sec * 1000000000ULL) + i_nsec);
    result *= (iv_timebaseFreq / 1000000);
    result /= 1000;
    return result;
}

void TimeManager::convertTicksToSec(uint64_t i_ticks,
                                    uint64_t& o_sec, uint64_t& o_nsec)
{
    o_sec = i_ticks / iv_timebaseFreq;

    o_nsec = (i_ticks - (o_sec * iv_timebaseFreq)) * 1000;
    o_nsec /= (iv_timebaseFreq / 1000000);
}

void TimeManager::delayTask(task_t* t, uint64_t i_sec, uint64_t i_nsec)
{
    Singleton<TimeManager>::instance()._delayTask(t,i_sec,i_nsec);
}

void TimeManager::_delayTask(task_t* t, uint64_t i_sec, uint64_t i_nsec)
{
    _TimeManager_Delay_t* node = new _TimeManager_Delay_t();

    node->key = this->getCurrentTimeBase() +
                this->convertSecToTicks(i_sec, i_nsec);
    node->task = t;

    t->state = TASK_STATE_BLOCK_SLEEP;
    t->state_info = (void*)node->key;

    _get_delaylist()->insert(node);
}

void TimeManager::checkReleaseTasks(Scheduler* s)
{
    Singleton<TimeManager>::instance()._checkReleaseTasks(s);
}

void TimeManager::_checkReleaseTasks(Scheduler* s)
{
    uint64_t l_currentTime = getCurrentTimeBase();
    _TimeManager_Delay_t* node = NULL;

    while(NULL != (node = _get_delaylist()->remove_if(l_currentTime)))
    {
        s->addTask(node->task);
        delete node;
        doorbell_broadcast();
    }
}

TimeManager::delaylist_t* TimeManager::_get_delaylist()
{
    return static_cast<delaylist_t*>(CpuManager::getCurrentCPU()->delay_list);
}

uint64_t TimeManager::getIdleTimeSliceCount()
{
    uint64_t sliceCount = getTimeSliceCount();

    // In Simics we want to idle longer to improve overall performance.  Set
    // the idle baseline at 10x normal idle frequency.
    if (cv_isSimicsRunning)
    {
        sliceCount *= 10;
    }

    // Get a delayed task, if there is one
    _TimeManager_Delay_t* node = _get_delaylist()->front();

    if(node)
    {
        uint64_t currentTime = getCurrentTimeBase();
        if(currentTime < node->key)
        {
            uint64_t diffTime = node->key - currentTime;
            if(diffTime < sliceCount)
            {
                sliceCount = diffTime;
            }
        }
        else  // ready to run now! Minimum delay
        {
            sliceCount = 1;
        }
    }

    return sliceCount;
}

bool TimeManager::simpleDelay(uint64_t i_sec, uint64_t i_nsec)
{
    bool result = false;

    uint64_t threshold = getTimeSliceCount()/YIELD_THRESHOLD_PER_SLICE;
    uint64_t delay = convertSecToTicks(i_sec, i_nsec);

    bool isUserspace = !KernelMisc::in_kernel_mode();

    // TB is not synchronized between cores, so if we're doing a poll we need
    // to pin the task to the current cpu.  Otherwise the getTB can get a
    // drifted answer after a task migration.
    if (isUserspace)
    {
        task_affinity_pin();
    }

    // Do polling delay.
    if(delay < threshold)
    {
        uint64_t expire = getCurrentTimeBase() + delay;
        while(getCurrentTimeBase() < expire)
        {
            setThreadPriorityLow();
        }
        setThreadPriorityHigh();
        result = true;
    }

    if (isUserspace)
    {
        task_affinity_unpin();
    }

    return result;
}

