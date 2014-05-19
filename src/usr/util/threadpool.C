/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/threadpool.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
