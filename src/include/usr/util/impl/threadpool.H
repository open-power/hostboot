//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/util/impl/threadpool.H $
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
#ifndef __UTIL_IMPL_THREADPOOL_H
#define __UTIL_IMPL_THREADPOOL_H

/** @file threadpool.H
 *
 *  Contains the (mostly) untemplatized implementation details of the
 *  threadpool.
 *
 *  The idea is that Util::ThreadPool is a templatized class to give the
 *  user flexibility but most of the details are implemented in a
 *  non-templatized way to conserve space.  When Util::ThreadPool<T> is
 *  instantiated there is only a small amount of code that is unique to T.
 */

#include <list>
#include <algorithm>
#include <sys/sync.h>
#include <sys/task.h>

namespace Util
{

namespace __Util_ThreadPool_Impl
{
    /**
     *  Export the container types used in the internal ThreadPool
     *  implementation.
     *
     *  The ThreadPoolImpl here is going to operate on a container of void*'s,
     *  but the templatized code is going to assume it is operating on a
     *  container of T*'s.  Since an iterator<void*> and iterator<T*> have the
     *  same behavior, we provide this template here so that the real
     *  ThreadPool can use the same iterators by typename without knowing if
     *  they are stored in a list, vector, etc.
     */
    template <typename _T>
    struct ThreadPoolImplContainer
    {
        typedef std::list<_T*> worklist_t;
        typedef typename std::list<_T*>::iterator worklist_itr_t;
    };

    /**
     *  Internal implementation of the thread pool.
     */
    class ThreadPoolImpl
    {
        public:
                /** Worklist container type. */
            typedef ThreadPoolImplContainer<void>::worklist_t worklist_t;
                /** Worklist container iterator type. */
            typedef ThreadPoolImplContainer<void>::worklist_itr_t
                        worklist_itr_t;

                /** Typedef of function pointer passed to "start". */
            typedef void(*start_fn_t)(void*);
                /** Typedef of function poitner passed to "remove". */
            typedef
                worklist_itr_t(*order_fn_t)(worklist_itr_t, worklist_itr_t);

                /** Simple constructor, call __init to avoid the in-charge and
                 *  not-in-charge construction costs. */
            ThreadPoolImpl() { __init(); };

        protected:
                /** Initialize the object. */
            void __init();
                /** Insert a work-item onto the work-queue. */
            void __insert(void*);
                /** Remove the next work item from the work-queue.
                 *
                 *  Called by worker threads to find the next piece of work.
                 *
                 *  @param[in] fn - Function to use to order the work by
                 *                  priority.
                 */
            void* __remove(order_fn_t fn);

                /** Start the thread-pool.
                 *
                 *  @param[in] fn - Function to use as the thread entry-point.
                 *  @param[in] instance - "this" to pass to worker threads.
                 */
            void __start(start_fn_t fn, void* instance);
                /** Stop the thread-pool. */
            void __shutdown();

                /** Outstanding work-list. */
            worklist_t iv_worklist;
                /** Mutex to protect insert / remove. */
            mutex_t iv_mutex;
                /** Condition variable to block on empty. */
            sync_cond_t iv_condvar;

                /** List of worker threads created, to use for joining on
                 *  shutdown */
            std::list<tid_t> iv_children;
                /** State of object. */
            bool iv_shutdown;

    };

        /** Prototype of 'search' functor against a threadpool. */
    template <typename _T, bool nonfifo> struct ThreadPoolWorklistSearch;

    /**
     *  Template specialization of the threadpool search functor for FIFO order.
     */
    template <typename _T>
    struct ThreadPoolWorklistSearch<_T, false>
    {
        /**
         * Returns the next workitem out of a threadpool list.
         *
         * Since this is the FIFO specialization, this should just return
         * the next item in the list.
         *
         * @param[in] begin - Iterator to the beginning of the list.
         * @param[in] end - Iterator to the end of the list.
         *
         * @return begin
         */
        static typename ThreadPoolImplContainer<_T>::worklist_itr_t
            search(typename ThreadPoolImplContainer<_T>::worklist_itr_t begin,
                   typename ThreadPoolImplContainer<_T>::worklist_itr_t end)
        {
            return begin;
        }
    };

    /**
     * Functor which performs (*a < *b).
     *
     * Since the items in a worklist are (WorkItem*)'s, they need to be
     * dereferenced prior to comparison.  This functor performs the
     * dereference and comparison operation.
     */
    template <typename _T>
    struct DerefLessCompare
    {
        bool operator()(_T* a, _T* b)
        {
            return ((*a) < (*b));
        }
    };

    /**
     *  Template specialiation of the threadpool search functor for non-FIFO
     *  order.
     */
    template <typename _T>
    struct ThreadPoolWorklistSearch<_T, true>
    {
        /**
         * Returns the next workitem out of a threadpool list.
         *
         * Since this is the non-FIFO specialization, this should return the
         * minimum workitem.
         *
         * @param[in] begin - Iterator to the beginning of the list.
         * @param[in] end - Iterator to the end of the list.
         *
         * @return Iterator pointing to the minimum entry in the list.
         */
        static typename ThreadPoolImplContainer<_T>::worklist_itr_t
            search(typename ThreadPoolImplContainer<_T>::worklist_itr_t begin,
                   typename ThreadPoolImplContainer<_T>::worklist_itr_t end)
        {
            return std::min_element(begin,end,
                                    DerefLessCompare<_T>());
        }
    };

};


};


#endif
