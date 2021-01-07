/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/threadpool.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
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
#include <util/threadpool.H>
#include <sys/task.h>
#include <sys/misc.h>
#include <util/util_reasoncodes.H>
#include <errl/errlmanager.H>
#include <errl/errludprintk.H>
#include <errl/errlentry.H>
#include <hbotcompid.H>

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

errlHndl_t Util::__Util_ThreadPool_Impl::ThreadPoolImpl::__shutdown()
{
    mutex_lock(&iv_mutex);

    int l_childRc = 0;
    void* l_childRetval = nullptr;
    errlHndl_t l_origError = nullptr;
    errlHndl_t l_errl = nullptr;

    // Set shutdown status and signal all children to release from their
    // condition variable.
    iv_shutdown = true;
    sync_cond_broadcast(&iv_condvar);

    // Join on all the children.
    while(!iv_children.empty())
    {
        tid_t child = iv_children.front();
        tid_t l_returnedTid = 0;
        iv_children.pop_front();

        mutex_unlock(&iv_mutex);
        l_returnedTid = task_wait_tid(child, &l_childRc, &l_childRetval);
        if(iv_checkChildRc &&
           ((l_returnedTid != child) ||
            (l_childRc != TASK_STATUS_EXITED_CLEAN)))
        {
            /*@
             * @errortype
             * @moduleid         Util::UTIL_MOD_TP_SHUTDOWN
             * @reasoncode       Util::UTIL_RC_CHILD_TASK_FAILED
             * @userdata1        The return code of the child thread
             * @userdata2[0:31]  The returned task ID of the child thread
             * @userdata2[32:63] The original task ID of the child thread
             * @devdesc          The child thread of a thread pool returned an
             *                   error
             * @custdesc         A failure occurred during the IPL of the system
             */
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                             UTIL_MOD_TP_SHUTDOWN,
                                             UTIL_RC_CHILD_TASK_FAILED,
                                             l_childRc,
                                             TWO_UINT32_TO_UINT64(l_returnedTid,
                                                                  child),
                                             ERRORLOG::ErrlEntry::ADD_SW_CALLOUT,
                                             ERRORLOG::ErrlEntry::FORCE_DUMP);
            l_errl->collectTrace(UTIL_COMP_NAME);
            ERRORLOG::ErrlUserDetailsPrintk().addToLog(l_errl);

            if(!l_origError)
            {
                l_origError = l_errl;
                l_errl = nullptr;
            }
            else
            {
                l_errl->plid(l_origError->plid());
                errlCommit(l_errl, UTIL_COMP_ID);
            }
        }
        mutex_lock(&iv_mutex);
    }

    mutex_unlock(&iv_mutex);
    return l_origError;
}

// Default thread count of one per HW thread.
size_t Util::ThreadPoolManager::cv_size = cpu_thread_count();
