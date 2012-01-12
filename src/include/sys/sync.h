//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/sys/sync.h $
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
#ifndef SYNC
#define SYNC

#include <stdint.h>

/**
 * Mutex object type
 */
struct _futex_imp_t
{
    uint64_t iv_val;
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

#define MUTEX_INITIALIZER {0}

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
 * @brief Initialize a mutex object
 * @param[out] o_mutex the mutex
 * @pre an uninitialized mutex object
 * @post a valid mutex object
 */
void mutex_init(mutex_t * o_mutex);

/**
 * @fn mutex_destroy
 * @brief Destroy / uninitialize a mutex object.
 * @param[in] i_mutex - the mutex
 * @note This does not free the memory associated with the object if the mutex
 *       was allocated off the heap.
 */
void mutex_destroy(mutex_t * i_mutex);

/**
 * @fn mutex_lock
 * @brief Obtain a lock on a mutex
 * @param[in] i_mutex - The mutex
 * @post returns when this task has the lock
 */
void mutex_lock(mutex_t * i_mutex);

/**
 * @fn mutex_unlock
 * @brief Release a lock on a mutex
 * @param[in] i_mutex - the mutex
 * @post mutex lock released
 */
void mutex_unlock(mutex_t * i_mutex);

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

#endif
