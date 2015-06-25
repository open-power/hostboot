/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/futexmgr.C $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2016                        */
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
 * @file futexmgr.C
 * @brief Definition for kernel side futex management
 */
#include <assert.h>
#include <errno.h>
#include <kernel/task.H>
#include <kernel/cpumgr.H>
#include <kernel/scheduler.H>
#include <kernel/futexmgr.H>
#include <util/singleton.H>
#include <kernel/doorbell.H>

//-----------------------------------------------------------------------------

uint64_t FutexManager::wait(task_t* i_task, uint64_t * i_addr, uint64_t i_val)
{
    return Singleton<FutexManager>::instance()._wait(i_task, i_addr, i_val);
}

//-----------------------------------------------------------------------------

uint64_t FutexManager::wake(uint64_t * i_futex1, uint64_t i_count1,
                            uint64_t * i_futex2, uint64_t i_count2)
{
    return Singleton<FutexManager>::instance()._wake(i_futex1, i_count1,
                                                     i_futex2, i_count2);
}

//-----------------------------------------------------------------------------

uint64_t FutexManager::_wait(task_t* i_task, uint64_t * i_addr, uint64_t i_val)
{
    uint64_t rc = 0;

    iv_lock.lock();

    if(unlikely(*i_addr != i_val))
    {
        // some other task has modified the futex
        // bail-out retry required.
        iv_lock.unlock();
        rc = EWOULDBLOCK;
    }
    else
    {
        _FutexWait_t * waiter = new _FutexWait_t();
        waiter->key = i_addr;
        waiter->task = i_task;

        // Set blocked state.
        i_task->state = TASK_STATE_BLOCK_FUTEX;
        i_task->state_info = i_addr;

        // Now add the futex/task it to the wait queue
        iv_list.insert(waiter);
        iv_lock.unlock();
        CpuManager::getCurrentCPU()->scheduler->setNextRunnable();
    }

    return rc;
}


//  Wake processes. Any number of processes in excess of count1 are not
// woken up but moved to futex2.  the number of processes to move
// is capped by count2.
uint64_t FutexManager::_wake(uint64_t * i_futex1, uint64_t i_count1,
                             uint64_t * i_futex2, uint64_t i_count2
                            )
{
    uint64_t started = 0;

    iv_lock.lock();

    // First start up to i_count1 task(s)
    while(started < i_count1)
    {
        _FutexWait_t * waiter = iv_list.find(i_futex1);
        if(waiter == NULL)
        {
            break;
        }

        task_t * wait_task = waiter->task;
        iv_list.erase(waiter);
        delete waiter;

        // This means we had a waiter in the queue, but that waiter had
        // a Null task assigned to it.  This should NEVER happen
        kassert(wait_task != NULL);

        wait_task->cpu->scheduler->addTask(wait_task);
        ++started;
    }

    if(i_futex2 && i_count2)
    {
        uint64_t moved = 0;

        // Move up to i_count2 tasks to futex2
        while(moved < i_count2)
        {
            // Note: i_futex2 could be modified by this point due to tasks
            //       released from i_count1.  Userspace has to handle this
            //       appropriately (currently only in sync_cond_wait).
            _FutexWait_t * waiter = iv_list.find(i_futex1);
            if(waiter == NULL)
            {
                break;
            }

            task_t * wait_task = waiter->task;
            iv_list.erase(waiter);

            kassert(wait_task != NULL); // should never happen, but...

            waiter->key = i_futex2;
            wait_task->state_info = i_futex2;

            iv_list.insert(waiter);
            ++moved;
        }
    }

    if(started)
    {
        doorbell_broadcast();
    }

    iv_lock.unlock();

    return started;
}
