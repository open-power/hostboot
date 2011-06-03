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
 * Initialize a barrier object
 * @param[out] o_barrier The barrier
 * @param[in] i_count The number of threads to wait on
 * @pre an unitiailized barrier object
 * @post a valid barrier object
 */
void barrier_init (barrier_t * o_barrier, uint64_t i_count);

/**
 * Destroy a barrier
 * @param[in] i_barrier  The barrier
 */
void barrier_destroy (barrier_t * i_barrier);

/**
 * Wait on a barrier
 * @param[in] i_barrier The barrier
 * @post this thread will be blocked until the barrier count is reached.
 */
void barrier_wait (barrier_t * i_barrier);

/**
 * Create a mutex and initialize a mutex
 * @returns a pointer to the mutex
 */
mutex_t * mutex_create();

/**
 * Initialize a mutex object
 * @param[out] o_mutex the mutex
 * @pre an uninitialized mutex object
 * @post a valid mutex object
 */
void mutex_init(mutex_t * o_mutex);

/**
 * Destroy a mutex
 * @param[in/out] i_mutex The mutex
 * @pre mutex must have been created with mutex_create()
 */
void mutex_destroy(mutex_t *& io_mutex);

/**
 * Obtain a lock on a mutex
 * @param[in] i_mutex The mutex
 * @post returns when this thread has the lock
 */
void mutex_lock(mutex_t * i_mutex);

/**
 * Release a lock on a mutex
 * @param[in] i_mutex the mutex
 * @returns non zero on error
 * @post mutex lock release
 */
void mutex_unlock(mutex_t * i_mutex);

#endif
