//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/util/threadpool.C $
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
#include <util/threadpool.H>
#include <sys/task.h>
#include <sys/misc.h>

void Util::__Util_ThreadPool_Impl::ThreadPoolImpl::__init()
{
    // Initialize all member variables.
    iv_worklist.clear();
    mutex_init(&iv_mutex);
    sync_cond_init(&iv_condvar);
    iv_children.clear();
    iv_shutdown = false;
}

void Util::__Util_ThreadPool_Impl::ThreadPoolImpl::__insert(void* i_workItem)
{
    mutex_lock(&iv_mutex);

    // Insert item on to the work list and signal any worker thread that may
    // be waiting.
    iv_worklist.push_back(i_workItem);
    sync_cond_signal(&iv_condvar);

    mutex_unlock(&iv_mutex);
}

void* Util::__Util_ThreadPool_Impl::ThreadPoolImpl::__remove(order_fn_t fn)
{
    void* val = NULL;

    mutex_lock(&iv_mutex);
    do
    {
        // Wait until the worklist is empty or told to shutdown.
        while(iv_worklist.empty() && !iv_shutdown)
        {
            sync_cond_wait(&iv_condvar, &iv_mutex);
        }

        // If told to shutdown and no work remains, end thread.
        if (iv_worklist.empty() && iv_shutdown)
        {
            break;
        }

        // Otherwise, obtain next item from worklist, using order function
        // passed to us.
        worklist_itr_t itr = fn(iv_worklist.begin(), iv_worklist.end());

        val = *itr;
        iv_worklist.erase(itr);

    } while(0);

    mutex_unlock(&iv_mutex);

    return val;
}

void Util::__Util_ThreadPool_Impl::ThreadPoolImpl::__start(
        Util::__Util_ThreadPool_Impl::ThreadPoolImpl::start_fn_t fn,
        void* instance)
{
    mutex_lock(&iv_mutex);

    size_t thread_count = Util::ThreadPoolManager::getThreadCount();
    while(thread_count--)
    {
        // Create children and add to a queue for later joining (during
        // shutdown)
        iv_children.push_back(task_create(fn, instance));
    }

    mutex_unlock(&iv_mutex);
}

void Util::__Util_ThreadPool_Impl::ThreadPoolImpl::__shutdown()
{
    mutex_lock(&iv_mutex);

    // Set shutdown status and signal all children to release from their
    // condition variable.
    iv_shutdown = true;
    sync_cond_broadcast(&iv_condvar);

    // Join on all the children.
    while(!iv_children.empty())
    {
        tid_t child = iv_children.front();
        iv_children.pop_front();

        mutex_unlock(&iv_mutex);
        task_wait_tid(child, NULL, NULL);  // Don't need status.
        mutex_lock(&iv_mutex);
    }

    mutex_unlock(&iv_mutex);
}

// Default thread count of one per HW thread.
size_t Util::ThreadPoolManager::cv_size = cpu_thread_count();
