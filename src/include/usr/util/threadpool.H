//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/util/threadpool.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
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
#ifndef __UTIL_THREADPOOL_H
#define __UTIL_THREADPOOL_H

/** @file threadpool.H
 *  @brief Defines the interfaces for a thread-pool.
 *
 *  Provides two classes, one of which is templatized: ThreadPool and
 *  ThreadPoolManager.
 *
 *  ThreadPool is an implementation of a thread-pool.  It accepts a template
 *  parameter of the class describing the work that can be done by this
 *  thread-pool.  The only requirement is that this class provides an
 *  operator().
 *
 *  The default behavior of the ThreadPool is to be a FIFO.  If the desire is
 *  for the ThreadPool to operate in a non-FIFO manner then the work item
 *  class must support less-than comparison.  The pool will then execute the
 *  oldest work item (a) such that all other work items (b) have:
 *      (false == (b < a))
 *
 *  Work Item Prototypes:
 *      void operator()() { ... execute work ... }
 *      bool operator<(const WorkItem& rhs);
 *
 *  ThreadPoolManager can be used to globally control the number of threads
 *  started when a new thread pool is started.  The intent of this class is
 *  that the maximum number of threads will be adjusted by an the IPL step
 *  management based on the phase of the IPL we are in.  When we are cache
 *  contained the number should be kept lower and when we exit cache contained
 *  we can allow much more parallelism.
 *
 */

#include <stdint.h>
#include <util/traits/has_lessthan.H>
#include <util/impl/threadpool.H>

namespace Util
{

/**
 * @brief Definition of the thread pool.
 *
 * @param[in] WorkItem - The class to accept as the work.
 *
 * The thread-pool will execute the operator() on WorkItems.  Work will be done
 * in a FIFO manner unless the < comparison works on the WorkItems, in which
 * case the oldest WorkItem for which all other work items fail (b<a) will be
 * processed.
 *
 * The thread-pool will only create worker threads once the 'start' operation
 * has been called.  When the 'shutdown' operation is called, the thread-pool
 * will complete its outstanding work and destroy all children worker threads.
 *
 * @note The thread-safety of this object ensures that it is self-consistent
 *       between insert and worker-thread operations but does not protect
 *       against multiple threads calling the start / shutdown operations.
 *       Multiple threads may insert safely but only one thread should be
 *       responsible for the state management.
 */
template <typename WorkItem>
class ThreadPool : public Util::__Util_ThreadPool_Impl::ThreadPoolImpl
{
    public:
            /** Basic Constructor.  Initialize ThreadPool. */
        ThreadPool() : Util::__Util_ThreadPool_Impl::ThreadPoolImpl() { };
            /** Basic Destructor.  Ensures pool is properly shut down. */
        ~ThreadPool() { shutdown(); };

            /** @brief Creates worker threads and begins processing work.
             */
        void start()
            {
                __start(reinterpret_cast<start_fn_t>(&run), this);
            };
            /** @brief Completes outstanding work and destroys worker threads.
             *
             *  @note This function will block until all work is completed and
             *        worker threads are destroyed.
             */
        void shutdown()
            { __shutdown(); };

            /** @brief Insert a work item onto the thread-pool's queue.
             *
             *  Ownership of the object is transfered to the thread-pool.
             *  After completing the work, the thread-pool will delete the
             *  work item.
             *
             *  @param[in] i_workItem - A work item to process.
             */
        void insert(WorkItem* i_workitem)
            { __insert(i_workitem); };

    private:
            /** Entry point for worker thread. */
        static void run(ThreadPool*);
            /** Useful constant to determine FIFO vs non-FIFO behavior. */
        static const bool has_comparison =
                Util::Traits::has_lessthan<WorkItem>::value;
};

/**
 * @brief Manager of the thread pools.
 *
 * When new thread-pools are created, they query the manager to determine
 * how many worker threads to create.  This should be manipulated by some
 * higher level service that understands the resources available to
 * thread-pools and sets the value to balance memory usage and efficiency.
 */
class ThreadPoolManager
{
    public:
        /** Query the desired worker-thread count. */
        static size_t getThreadCount()
            { return cv_size; };
        /** Set the desired worker-thread count. */
        static void setThreadCount(size_t i_size)
            { cv_size = i_size; };
    private:
        static size_t cv_size;
};

// Implementation of the worker-thread run function.
template <typename WorkItem>
void ThreadPool<WorkItem>::run(
        ThreadPool<WorkItem>* self)
{
    while(1)
    {
        // Obtain next work item from queue.
        WorkItem* wi =
            static_cast<WorkItem*>(
                self->__remove(
                    reinterpret_cast<order_fn_t>(
                        &Util::__Util_ThreadPool_Impl::ThreadPoolWorklistSearch
                            <WorkItem, has_comparison>::search
                    )
                )
            );

        if (wi) // Work was given, do it.
        {
            (*wi)();
            delete wi;
        }
        else // No work item was given, we must be done.
        {
            return; // task_end() called automatically by returning.
        }
    }
}

};

#endif
