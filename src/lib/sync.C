/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/lib/sync.C $                                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
#include <arch/ppc.H>
#include <sys/sync.h>
#include <sys/syscall.h>
#include <assert.h>
#include <errno.h>
#include <kernel/console.H>

using namespace Systemcalls;

//-----------------------------------------------------------------------------

int futex_wait(uint64_t * i_addr, uint64_t i_val)
{
    return (int64_t) _syscall5(SYS_FUTEX,
                               (void *)FUTEX_WAIT,
                               i_addr,
                               (void *)i_val,
                               NULL,
                               NULL);
}

//-----------------------------------------------------------------------------

int futex_wake(uint64_t * i_addr, uint64_t i_count)
{
    return (int64_t) _syscall5(SYS_FUTEX,
                               (void *)FUTEX_WAKE,
                               i_addr,
                               (void *)i_count,
                               NULL,
                               NULL);
}

//-----------------------------------------------------------------------------

int64_t futex_requeue(uint64_t * i_addr,
                      uint64_t i_count1,
                      uint64_t i_count2,
                      uint64_t * i_futex2)
{
    return (int64_t) _syscall5(SYS_FUTEX,
                               (void *)FUTEX_REQUEUE,
                               i_addr,
                               (void *)i_count1,
                               (void *)i_count2,
                               i_futex2);
}

//-----------------------------------------------------------------------------

void barrier_init (barrier_t * o_barrier, uint64_t i_count)
{
    mutex_init(&(o_barrier->iv_mutex));
    o_barrier->iv_event = 0;
    o_barrier->iv_count = i_count;
    o_barrier->iv_missing = i_count;
    return;
}

//-----------------------------------------------------------------------------

void barrier_destroy (barrier_t * i_barrier)
{
    crit_assert(i_barrier->iv_missing == i_barrier->iv_count);
    return;
}

//-----------------------------------------------------------------------------

void barrier_wait (barrier_t * i_barrier)
{
    mutex_lock(&(i_barrier->iv_mutex));
    --(i_barrier->iv_missing);
    if(i_barrier->iv_missing > 0)
    {
        uint64_t l_event = i_barrier->iv_event;
        mutex_unlock(&(i_barrier->iv_mutex));
        do
        {
            futex_wait(&(i_barrier->iv_event), l_event);
        } while (i_barrier->iv_event == l_event);
    }
    else
    {
        ++(i_barrier->iv_event);
        i_barrier->iv_missing = i_barrier->iv_count;

        // Wake em all up
        futex_wake(&(i_barrier->iv_event), UINT64_MAX);
        mutex_unlock(&(i_barrier->iv_mutex));
    }
    return;
}

//-----------------------------------------------------------------------------

void mutex_init(mutex_t * o_mutex)
{
    o_mutex->iv_val = 0;
    return;
}

//-----------------------------------------------------------------------------

void mutex_destroy(mutex_t * i_mutex)
{
    i_mutex->iv_val = ~0;
    return;
}

//-----------------------------------------------------------------------------

void mutex_lock(mutex_t * i_mutex)
{
    // Weak consistency notes:
    //     Since this is a lock, we do not need to ensure that all writes
    //     are globally visible prior to execution (lwsync) but we do need
    //     to ensure that all instructions finish completion prior to
    //     leaving (isync).  Both __sync_val_compare_and_swap and
    //     __sync_lock_test_and_set have an implied isync.

    uint64_t l_count = __sync_val_compare_and_swap(&(i_mutex->iv_val),0,1);

    if(unlikely(l_count != 0))
    {
        if (likely(l_count != 2))
        {
            l_count = __sync_lock_test_and_set(&(i_mutex->iv_val), 2);
        }

        while( l_count != 0 )
        {
            futex_wait( &(i_mutex->iv_val), 2);
            l_count = __sync_lock_test_and_set(&(i_mutex->iv_val),2);
            // if more than one task gets out - one continues while
            // the rest get blocked again.
        }
    }

    return;
}

//-----------------------------------------------------------------------------

void mutex_unlock(mutex_t * i_mutex)
{
    // Weak consistency notes:
    //     Since this is an unlock we need to ensure that all writes are
    //     globally visible prior to execution (lwsync).  The
    //     __sync_fetch_and_sub has an implied lwsync.  If we need to
    //     release a task, due to a contended mutex, the write to iv_val
    //     and futex_wake pair will appear globally ordered due to the
    //     context synchronizing nature of the 'sc' instruction.

    uint64_t l_count = __sync_fetch_and_sub(&(i_mutex->iv_val),1);
    if(unlikely(2 <= l_count))
    {
        i_mutex->iv_val = 0;
        futex_wake(&(i_mutex->iv_val), 1); // wake one task
    }

    return;
}

void sync_cond_init(sync_cond_t * i_cond)
{
    i_cond->mutex = NULL;
    i_cond->sequence = 0;
}

void sync_cond_destroy(sync_cond_t * i_cond)
{
    // don't need to do anything
}

int sync_cond_wait(sync_cond_t * i_cond, mutex_t * i_mutex)
{
    uint64_t seq = i_cond->sequence;
    if(i_cond->mutex != i_mutex)
    {
        if(i_cond->mutex) return EINVAL;

        // Atomically set mutex
        __sync_bool_compare_and_swap(&i_cond->mutex, NULL, i_mutex);
        if(i_cond->mutex != i_mutex) return EINVAL;
    }

    mutex_unlock(i_mutex);

    futex_wait( &(i_cond->sequence), seq);


    // Can't continue until i_mutex lock is obtained.
    // Note:
    //     mutex_lock(i_mutex);  <--- This does not work
    // We have to mark the mutex as contended '2' because there is a race
    // condition between this thread (eventually) calling mutex_unlock and
    // the kernel moving tasks from the condition futex to the mutex futex
    // during a sync_condition_broadcast.  By marking contended, we force the
    // subsequent mutex_unlock to call to the kernel which will obtain a
    // spinlock to ensure all tasks have been moved to the mutex_futex.
    while(0 != __sync_lock_test_and_set(&(i_mutex->iv_val), 2))
    {
        futex_wait(&(i_mutex->iv_val),2);
    }

    return 0;
}

void sync_cond_signal(sync_cond_t * i_cond)
{
    __sync_fetch_and_add(&(i_cond->sequence),1);
    // Wake up one
    futex_wake(&(i_cond->sequence), 1);
}

void sync_cond_broadcast(sync_cond_t * i_cond)
{
    mutex_t * m = i_cond->mutex;

    // no mutex means no waiters
    if(!m) return;

    // wake up all
    __sync_fetch_and_add(&(i_cond->sequence),1);

    // need to wake up one on the sequence and
    // re-queue the rest onto the mutex m;
    futex_requeue(&(i_cond->sequence),1,UINT64_MAX,&(m->iv_val));
}

