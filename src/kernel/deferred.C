/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/deferred.C $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
#include <kernel/deferred.H>
#include <kernel/cpumgr.H>
#include <util/singleton.H>
#include <assert.h>
#include <arch/ppc.H>

/** Extract the DeferredWork pointer part of a iv_cpus_and_next instance var. */
#define DEFERRED_QUEUE_GET_NEXT_PTR(item) \
    reinterpret_cast<DeferredWork*>((item)->iv_cpus_and_next & 0xFFFFFFFF)

/** Set the DeferredWork pointer part of a iv_cpus_and_next instance var. */
#define DEFERRED_QUEUE_SET_NEXT_PTR(tail,item) \
    { \
        uint64_t old_value = 0; \
        uint64_t new_value = 0; \
        do \
        { \
            old_value = (tail)->iv_cpus_and_next; \
            new_value = (old_value & 0xFFFFFFFF00000000ull) | \
                        reinterpret_cast<uint64_t>(item); \
        } \
        while (!__sync_bool_compare_and_swap(&(tail)->iv_cpus_and_next, \
                                             old_value, \
                                             new_value)); \
    }

/** Extract the CPU count portion of a iv_cpus_and_next instance var. */
#define DEFERRED_QUEUE_GET_CPU_COUNT(item) (item)->iv_cpus_and_next >> 32

// Initialize the work queue.
DeferredQueue::DeferredQueue() : lock(), iv_cpus_and_next(0) {}

DeferredQueue::~DeferredQueue()
{
    // Ensure that all work is completed.
    kassert(0 == iv_cpus_and_next);
}

void DeferredQueue::insert(DeferredWork* i_work)
{
    // Call singleton insert.
    Singleton<DeferredQueue>::instance()._insert(i_work);
}

void DeferredQueue::execute()
{
    // Call singleton execute.
    Singleton<DeferredQueue>::instance()._execute();
}

void DeferredQueue::_insert(DeferredWork* i_work)
{
    lock.lock();

    // NULL pointer implies empty, so just add work item.
    if (0 == iv_cpus_and_next)
    {
        iv_cpus_and_next = reinterpret_cast<uint64_t>(i_work);
    }
    else
    {
        // Follow linked list to last work item.
        DeferredWork* tail = DEFERRED_QUEUE_GET_NEXT_PTR(this);
        while (NULL != DEFERRED_QUEUE_GET_NEXT_PTR(tail))
        {
            tail = DEFERRED_QUEUE_GET_NEXT_PTR(tail);
        }

        // Add work item to the end of the list.
        DEFERRED_QUEUE_SET_NEXT_PTR(tail, i_work);
    }

    lock.unlock();
}

void DeferredQueue::_execute()
{
    uint64_t cpus_and_next = 0;

    // Increment the CPU count for pointer references.
    do
    {
        cpus_and_next = iv_cpus_and_next;

        if (0 == cpus_and_next) // No work to execute.
        {
            return;
        }

    } while(!__sync_bool_compare_and_swap(&iv_cpus_and_next,
                                          cpus_and_next,
                                          cpus_and_next + (1ull << 32)));

    // Extract the item pointer.
    DeferredWork* item =
            reinterpret_cast<DeferredWork*>(cpus_and_next & 0xFFFFFFFF);

    // Execute the extracted item.
    item->start();
}

void DeferredQueue::_complete(DeferredWork* i_work)
{
    lock.lock();

    // Update list-head to pop item off.
    uint64_t new_ptr =
            reinterpret_cast<uint64_t>(DEFERRED_QUEUE_GET_NEXT_PTR(i_work));
    uint64_t old_ptr = 0;

    do
    {
        old_ptr = iv_cpus_and_next;
    } while(!__sync_bool_compare_and_swap(&iv_cpus_and_next, old_ptr, new_ptr));

    // Clean up our own queue pointer.
    DEFERRED_QUEUE_SET_NEXT_PTR(i_work, (DeferredWork*)NULL);

    // Get the CPU count from the old object pointer and wait until those
    // CPUs get into i_work.
    old_ptr >>= 32;
    while (DEFERRED_QUEUE_GET_CPU_COUNT(i_work) != old_ptr)
    {
        setThreadPriorityLow();
    }
    setThreadPriorityHigh();

    lock.unlock();
}

DeferredWork::DeferredWork() : iv_barrier(), iv_cpus_and_next(0),
                               iv_activeSeqId(0),
                               iv_releasePre(false), iv_releasePost(false)
{
    uint32_t cpuCount;

    // Read the current CPU count and sequence number.
    CpuManager::getCpuCountAndSeqId(cpuCount, iv_activeSeqId);
    // Initialize the barrier with the number of active CPUs.
    iv_barrier.init(cpuCount);
}

DeferredWork::~DeferredWork()
{
    // Ensure the work item was removed from the queue chain and no
    // CPUs are still inside it.
    kassert(0 == iv_cpus_and_next);
}

void DeferredWork::start()
{
    // Increment object reference count.
    __sync_add_and_fetch(&iv_cpus_and_next, 1ull << 32);

    // Get our CPU object and determine if we were active when the item
    // was created. (Our sequence # being less or equal work item sequence #)
    cpu_t* cpu = CpuManager::getCurrentCPU();
    bool active = cpu->cpu_start_seqid <= iv_activeSeqId;

    // Synchronize active CPUs.
    if (active)
    {
        _waitForCpus();
    }

    // Call masterPre step.
    if (cpu->master)
    {
        _masterPre();
    }
    else
    {
        _waitAtPre();
    }

    // Call MainWork step.
    if (active)
    {
        activeMainWork();
        _waitForCpus();
    }
    else
    {
        nonactiveMainWork();
    }

    // Call masterPost step.
    if (cpu->master)
    {
        _masterPost();
    }
    else
    {
        _waitAtPost();
    }

    // Release reference to this object.
    _cleanup();
}

void DeferredWork::_waitForCpus()
{
    iv_barrier.wait();
}

void DeferredWork::_masterPre()
{
    masterPreWork();

    // Ensure memory ops are globally visible before releasing all CPUs.
    lwsync();
    iv_releasePre = true;
}

void DeferredWork::_waitAtPre()
{
    while(!iv_releasePre)
    {
        setThreadPriorityLow();
    }
    isync();  // Prevent spec. execution past this point until released.
    setThreadPriorityHigh();
}

void DeferredWork::_masterPost()
{
    masterPostWork();

    // Remove ourself from the queue chain now.
    Singleton<DeferredQueue>::instance()._complete(this);

    // Ensure memory ops are globally visible before releasing all CPUs.
    lwsync();
    iv_releasePost = true;
}

void DeferredWork::_waitAtPost()
{
    while(!iv_releasePost)
    {
        setThreadPriorityLow();
    }
    isync();  // Prevent spec. execution past this point until released.
    setThreadPriorityHigh();
}

void DeferredWork::_cleanup()
{
    // Decrement reference count.
    uint64_t cpu_count =
        __sync_sub_and_fetch(&iv_cpus_and_next, 1ull << 32) >> 32;

    // If the last object, delete this work item.
    if (0 == cpu_count)
    {
        delete this;
    }
}
