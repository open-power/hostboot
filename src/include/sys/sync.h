/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/sys/sync.h $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2021                        */
/* [+] Google Inc.                                                        */
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
#ifndef __SYS_SYNC_H
#define __SYS_SYNC_H

#include <stdint.h>
#include <sys/task.h>

#ifdef __cplusplus
#include <memory>
#endif

/**
 * Mutex object type
 */
struct _futex_imp_t
{
    uint64_t iv_val;
    uint64_t iv_ownerLockCount;
    tid_t iv_owner;
    bool iv_recursive;

    _futex_imp_t (bool i_recursive = false) : iv_val(0), iv_ownerLockCount(0),
                      iv_owner(0), iv_recursive(i_recursive) {}
};

typedef _futex_imp_t mutex_t;

/**
 * Barrier object type
 */
struct _barrier_imp_t
{
    mutex_t iv_mutex;
    uint64_t iv_event;
    uint64_t iv_missing;
    uint64_t iv_count;
};

typedef _barrier_imp_t barrier_t;

#define MUTEX_INITIALIZER mutex_t()
#define MUTEX_RECURSIVE_INITIALIZER mutex_t(true)

/**
 * Conditional variable types
 */
struct _cond_imp_t
{
    mutex_t * mutex;
    uint64_t sequence;
};

typedef _cond_imp_t sync_cond_t;


#define COND_INITIALIZER {NULL, 0}

enum _FUTEX_OP
{
    FUTEX_WAIT,
    FUTEX_WAKE,
    FUTEX_REQUEUE
};

/**
 * @fn barrier_init
 * @brief Initialize a barrier object
 * @param[out] o_barrier The barrier
 * @param[in] i_count The number of tasks to wait on
 * @pre an uninitialized barrier object
 * @post a valid barrier object
 */
void barrier_init (barrier_t * o_barrier, uint64_t i_count);


/**
 * @fn barrier_destroy
 * @brief Destroy a barrier
 * @param[in] i_barrier  The barrier
 */
void barrier_destroy (barrier_t * i_barrier);


/**
 * @fn barrier_wait
 * @brief Wait on a barrier
 * This tasks will block until the barrier count is reached.
 * @param[in] i_barrier The barrier
 */
void barrier_wait (barrier_t * i_barrier);

/**
 * @fn mutex_init
 * @brief Initialize a non-recursive mutex object
 * @param[out] o_mutex the mutex
 * @pre an uninitialized mutex object
 * @post a valid non-recursive mutex object
 */
void mutex_init(mutex_t * o_mutex);

/**
 * @fn recursive_mutex_init
 * @brief Initialize a recursive mutex object
 * @param[out] o_mutex the mutex
 * @pre an uninitialized mutex object
 * @post a valid recursive mutex object
 */
void recursive_mutex_init(mutex_t * o_mutex);


/**
 * @fn mutex_destroy
 * @brief Destroy / uninitialize a non-recursive mutex object. Code will assert
 *        if a recursive mutex is passed in.
 * @param[in] i_mutex - the non-recursive mutex
 * @note This does not free the memory associated with the object if the mutex
 *       was allocated off the heap.
 */
void mutex_destroy(mutex_t * i_mutex);

/**
 * @fn recursive_mutex_destroy
 * @brief Destroy / uninitialize a recursive mutex object. Code will assert if a
 *        non-recursive mutex is passed in.
 * @param[in] i_mutex - the mutex
 * @note This does not free the memory associated with the object if the mutex
 *       was allocated off the heap.
 */
void recursive_mutex_destroy(mutex_t * i_mutex);

/**
 * @fn mutex_lock
 * @brief Obtain a lock on a mutex. If a recursive mutex is passed as the
 *        parameter the code will assert.
 * @param[in] i_mutex - The mutex
 * @post returns when this task has the lock
 */
void mutex_lock(mutex_t * i_mutex);

/**
 * @fn mutex_unlock
 * @brief Release a lock on a mutex. If a recursive mutex is passed as the
 *        parameter the code will assert.
 * @param[in] i_mutex - the mutex
 * @post mutex lock released
 */
void mutex_unlock(mutex_t * i_mutex);

#ifdef __cplusplus
using mutex_lock_t = std::unique_ptr<mutex_t, decltype(&mutex_unlock)>;

/* @brief Locks a mutex and returns an object which owns the lock. The object
 *        will automatically unlock the mutex when it is destroyed. The object
 *        can be moved to transfer ownership of the lock.
 *
 * @param[in] i_mutex  Mutex to lock
 * @return mutex_lock_t  Lock object
 */
inline mutex_lock_t scoped_mutex_lock(mutex_t& i_mutex)
{
    mutex_lock(&i_mutex);
    return { &i_mutex, mutex_unlock };
}
#endif

/**
 * @fn recursive_mutex_lock
 * @brief Obtain a lock on a recursive mutex. If a non-recursive mutex is passed
 *        as the parameter the code will assert.
 * @param[in] i_mutex - The mutex
 * @post returns when this task has the lock
 */
void recursive_mutex_lock(mutex_t * i_mutex);

/**
 * @fn recursive_mutex_unlock
 * @brief Release a lock on a recursive mutex. If a non-recursive mutex is
 *        passed as the parameter the code will assert.
 * @param[in] i_mutex - A recursive mutex
 * @post mutex lock released or mutex iv_ownerLockCount decremented.
 */
void recursive_mutex_unlock(mutex_t * i_mutex);

/**
 * @fn sync_cond_init
 * @brief Initialize a condtional variable
 * @param i_cond, The conditional variable
 * @post
 */
void sync_cond_init(sync_cond_t * i_cond);

/**
 * @fn sync_cond_destroy
 * @brief Destroy a conditional variable
 * @param i_cond, The conditional variable
 */
void sync_cond_destroy(sync_cond_t * i_cond);

/**
 * @fn sync_cond_wait
 * @brief Block the calling task until the specified condition is signaled
 * @param i_cond, The condition variable
 * @param i_mutex, A mutex for which this task has the lock
 * @pre This task must have the mutex lock
 * @post This task will have the mutex lock
 * @note i_mutex will be unlocked while this task is in the wait state.
 * @note failing to lock the mutex before calling this function may cause it
 * not to block
 */
int sync_cond_wait(sync_cond_t * i_cond, mutex_t * i_mutex);

/**
 * @fn sync_cond_signal
 * @brief Signal to wake a task waiting on the condition varible.
 * @param i_cond, The condition variable
 * @pre This task must hold the lock on the mutex used in sync_cond_wait()
 * @pre sync_cond_wait() must have been called for conditional variable
 * @note failing to unlock the mutex after this call may cause the waiting
 * task to remain blocked. If there is more than one task waiting on the
 * conditional variable then sync_cond_broadcast() should be used instead.
 */
void sync_cond_signal(sync_cond_t * i_cond);

/**
 * @fn sync_cond_broadcast
 * @brief Signal to wake all tasks waiting on the condition variable
 * @param i_cond, The conditional variable
 * @note same restrictions as sync_cond_signal() except this function should
 * be used if there is more than one task waiting on the conditional variable.
 * There is no guarantee on which waiting task will get the mutex lock first
 * when this task unlocks the mutex.
 */
void sync_cond_broadcast(sync_cond_t * i_cond);

/** @fn futex_wait
 *  @brief Perform a futex-wait operation.
 *
 *  This system call is modeled after 'futex' under Linux.
 *
 *  Will block the user space application until an address is signaled
 *  for waking.  In order to prevent deadlock conditions where the address
 *  has already changed while the system-call is being processed, the
 *  address is checked against the currently known value.  If the value has
 *  already changed then the function immediately returns.
 *
 *  @param[in] i_addr - Address to wait for signal on.
 *  @param[in] i_val - Current value at that address.
 *
 *  @return SUCCESS or EWOULDBLOCK.
 *
 *  A return of EWOULDBLOCK indicates that *i_addr != i_val.
 */
int futex_wait(uint64_t * i_addr, uint64_t i_val);

/** @fn futex_wake
 *  @brief Peform a futex-wake operation.
 *
 *  This system call is modeled after 'futex' under Linux.
 *
 *  Will awaken a number of tasks currently waiting to be signalled for an
 *  address.
 *
 *  @param[in] i_addr - The address to signal.
 *  @param[in] i_count - The maximum number of tasks to awaken.
 *
 *  @return SUCCESS.
 *
 *  If less tasks than i_count are currently blocked, all blocked tasks will
 *  be awoken.
 */
int futex_wake(uint64_t * i_addr, uint64_t i_count);

#endif
