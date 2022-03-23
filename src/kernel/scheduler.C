/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/scheduler.C $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2010,2022                        */
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
#include <kernel/task.H>
#include <kernel/scheduler.H>
#include <kernel/taskmgr.H>
#include <kernel/cpu.H>
#include <kernel/cpumgr.H>
#include <kernel/console.H>
#include <kernel/timemgr.H>
#include <util/lockfree/atomic_construct.H>

void Scheduler::addTask(task_t* t)
{
    t->state = TASK_STATE_READY;

    if (t->cpu->idle_task != t)
    {
        // If task is pinned to this CPU, add to the per-CPU queue.
        if (0 != t->affinity_pinned)
        {
            // Allocate a per-CPU queue if this is the first pinning to CPU.
            Util::Lockfree::atomic_construct
                (reinterpret_cast<Runqueue_t**>(&t->cpu->scheduler_extra));

            // Insert into queue.
            static_cast<Runqueue_t*>(t->cpu->scheduler_extra)->insert(t);
        }
        // Not pinned, add to global run-queue.
        else
        {
            iv_taskList.insert(t);
        }
    }
}

void Scheduler::addTaskMasterCPU(task_t* t)
{
    t->state = TASK_STATE_READY;

    if (t->cpu->idle_task != t)
    {
        cpu_t* master = CpuManager::getMasterCPU();

        // Allocate a per-CPU queue if this is the first pinning to CPU.
        Util::Lockfree::atomic_construct(
                reinterpret_cast<Runqueue_t**>(&master->scheduler_extra));

        // Insert into queue.
        static_cast<Runqueue_t*>(master->scheduler_extra)->insert(t);

    }
}

void Scheduler::returnRunnable()
{
    this->addTask(TaskManager::getCurrentTask());
}

void Scheduler::setNextRunnable()
{
    task_t* t = NULL;
    cpu_t* cpu = CpuManager::getCurrentCPU();

    // Check for ready task in local run-queue, if it exists.
    if (NULL != cpu->scheduler_extra)
    {
        t = static_cast<Runqueue_t*>(cpu->scheduler_extra)->remove();
    }

    // Check for ready task in global run-queue.  Only try the remove
    // if there is something in the queue to prevent excessive lock
    // contention
    if ((NULL == t) && iv_taskList.size())
    {
        t = iv_taskList.remove();
    }

    // Choose idle task if no other ready task is available.
    if (NULL == t)
    {
        t = cpu->idle_task;
        setDEC(TimeManager::getIdleTimeSliceCount());
    }
    else // Set normal timeslice to decrementer.
    {
        setDEC(TimeManager::getTimeSliceCount());
    }

    TaskManager::setCurrentTask(t);
}
