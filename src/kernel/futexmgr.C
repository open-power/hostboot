//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/kernel/futexmgr.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
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


//-----------------------------------------------------------------------------

uint64_t FutexManager::wait(task_t* i_task, uint64_t * i_addr, uint64_t i_val)
{
    return Singleton<FutexManager>::instance()._wait(i_task, i_addr, i_val);
}

//-----------------------------------------------------------------------------

uint64_t FutexManager::wake(uint64_t * i_addr, uint64_t i_count)
{
    return Singleton<FutexManager>::instance()._wake(i_addr, i_count);
}

//-----------------------------------------------------------------------------

uint64_t FutexManager::_wait(task_t* i_task, uint64_t * i_addr, uint64_t i_val)
{
    uint64_t rc = 0;

    iv_lock.lock();

    if(unlikely(*i_addr != i_val))
    {
        // some other thread has modified the futex
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

//-----------------------------------------------------------------------------

uint64_t FutexManager::_wake(uint64_t * i_addr, uint64_t i_count)
{
    uint64_t started = 0;

    // Remove task(s) from futex queue
    // Put it/them on the run queue
    iv_lock.lock();
    while(started < i_count)
    {
        _FutexWait_t * waiter = iv_list.find(i_addr);
        if(waiter == NULL)
        {
            break;
        }

        task_t * wait_task = waiter->task;
        iv_list.erase(waiter);

        // This means we had a waiter in the queue, but that waiter had
        // a Null task assigned to it.  This should NEVER happen
        kassert(wait_task != NULL);

        wait_task->cpu->scheduler->addTask(wait_task);
        ++started;
    }
    iv_lock.unlock();

    return started;
}
