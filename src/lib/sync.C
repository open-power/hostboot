#include <arch/ppc.H>
#include <sys/sync.h>
#include <sys/syscall.h>
#include <assert.h>

using namespace Systemcalls;

//-----------------------------------------------------------------------------

uint64_t futex_wait(uint64_t * i_addr, uint64_t i_val)
{
    return (uint64_t) _syscall2(FUTEX_WAIT,i_addr, (void *)i_val);
}

//-----------------------------------------------------------------------------

uint64_t futex_wake(uint64_t * i_addr, uint64_t i_count)
{
    return (uint64_t) _syscall2(FUTEX_WAKE, i_addr, (void *)i_count);
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

void mutex_destroy(mutex_t *& i_mutex)
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
            // if more than one thread gets out - one continues while
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
        futex_wake(&(i_mutex->iv_val), 1); // wake one thread
    }

    return;
}


