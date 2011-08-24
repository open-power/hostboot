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
 * @fn barrier_init
 * @brief Initialize a barrier object
 * @param[out] o_barrier The barrier
 * @param[in] i_count The number of threads to wait on
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
 * This thread will block until the barrier count is reached.
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
 * @post returns when this thread has the lock
 */
void mutex_lock(mutex_t * i_mutex);

/**
 * @fn mutex_unlock
 * @brief Release a lock on a mutex
 * @param[in] i_mutex - the mutex
 * @post mutex lock released
 */
void mutex_unlock(mutex_t * i_mutex);

#endif
