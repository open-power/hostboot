/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pldm/base/pldm_msg_timeout.C $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2022                        */
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
/**
 * @file pldm_msg_timeout.C
 * @brief Source code for the class that handles timeouts for pldm msgs.
 *        During pldm_base_init a singleton of the pldmMsgTimeout class has its
 *        init() function called which launches a task which will loop on the
 *        timeoutMsgList
 */
#include "pldm_msg_timeout.H"

#include <pldm/pldm_trace.H>
#include <util/singleton.H>
#include <sys/task.h>
#include <sys/msg.h>
#include <sys/time.h>
#include <time.h>
#include <vector>
#include <kernel/console.H> // printk DEBUG


// Static function used to launch task calling message_timeout_monitor on
// the pldmMsgTimeout singleton
static void * handle_timer_messages_task(void*)
{
    PLDM_INF("Starting task to handle pldm timeout timer");
    task_detach();
    Singleton<pldmMsgTimeout>::instance().message_timeout_monitor_thread();
    return nullptr;
}

pldmMsgTimeout::pldmMsgTimeout(void)
{
    mutex_init(&iv_mutex);
    sync_cond_init(&iv_cv);
    iv_timeoutMsgList.clear();
}

void pldmMsgTimeout::init(void)
{
    PLDM_ENTER("pldmMsgTimeout::_init entry");

    task_create(handle_timer_messages_task, nullptr);

    PLDM_EXIT("pldmMsgTimeout::_init exit");

    return;
}


void pldmMsgTimeout::message_timeout_monitor_thread(void)
{
    PLDM_ENTER("pldmMsgTimeout::message_timeout_monitor_thread");
    int msgSendRc = 0;
    while (true)
    {
        mutex_lock(&iv_mutex);
        while ((iv_timeoutMsgList.size() == 0))
        {
            sync_cond_wait(&iv_cv, &iv_mutex);
        }

        for ( auto& timeoutMsgNode : iv_timeoutMsgList)
        {
            if ((timeoutMsgNode.waitTimeLeft_msec == 0) &&
                (timeoutMsgNode.state == TIMEOUT_STATE_RUNNING))
            {
                // sending back the timeout msg to queue that was waiting for a response
                // indicating that the BMC did NOT respond in allocated time
                msgSendRc = msg_send(timeoutMsgNode.queue, timeoutMsgNode.waiter_done_msg);

                // If msg_send fails, then _pldm_wait_timeout will get stuck waiting
                // This is a basic function that needs to work, so crit_assert on failure
                if (msgSendRc != 0)
                {
                    printk("E>pldmMsgTimeout: unable to send time done msg to %p queue, rc = 0x%x",
                           timeoutMsgNode.queue, msgSendRc );
                    crit_assert(0);
                }

                // this is the only place where the state is set to REAL_TIMEOUT
                // this setting indicates that the waiter_done_msg was sent to queue
                timeoutMsgNode.state = TIMEOUT_STATE_REAL_TIMEOUT;
            }
            else if (timeoutMsgNode.state == TIMEOUT_STATE_RUNNING)
            {
                // this msec decrement is for the 1 msec nanosleep below
                timeoutMsgNode.waitTimeLeft_msec--;
            }
            // else (do nothing, have already sent timeout msg)
        }
        mutex_unlock(&iv_mutex);
        nanosleep(0, NS_PER_MSEC);  // sleep 1ms
    }
}

TIMEOUT_STATE pldmMsgTimeout::stop_pldm_timer(msg_q_t i_queue)
{
    TIMEOUT_STATE l_state = TIMEOUT_STATE_RUNNING;
    mutex_lock(&iv_mutex);
    std::list<TimerMsgData_t>::iterator iter;
    for (iter = iv_timeoutMsgList.begin(); iter != iv_timeoutMsgList.end(); iter++)
    {
        // pldm msgs are syncronous for each queue (ie one msg completes before next is sent)
        if (iter->queue == i_queue)
        {
            l_state = iter->state;
            iv_timeoutMsgList.erase(iter);
            break;
        }
    }
    mutex_unlock(&iv_mutex);
    return l_state;
}

bool pldmMsgTimeout::start_pldm_timer(msg_q_t i_queue, uint64_t i_timeout_ms, msg_t * i_timeout_msg)
{
    bool l_startTimer = true;
    TimerMsgData_t timerMsg = { };
    timerMsg.queue = i_queue;
    timerMsg.waitTimeLeft_msec = i_timeout_ms;
    timerMsg.waiter_done_msg = i_timeout_msg;

    mutex_lock(&iv_mutex);

    // safety check to ensure queue is unique
    for (const auto & timeoutMsgNode : iv_timeoutMsgList)
    {
        if (timeoutMsgNode.queue == i_queue)
        {
            PLDM_ERR("pldmMsgTimeout::start_pldm_timer() trying to monitor multiple msgs on same queue (%p)", i_queue);
            PLDM_INF("Currently waiting on: 0x%llX waitTimeLeft_msec and %d state", timeoutMsgNode.waitTimeLeft_msec, timeoutMsgNode.state);
            l_startTimer = false;
            break;
        }
    }

    if (l_startTimer)
    {
        // just add to the monitored list (note: queue must be unique)
        iv_timeoutMsgList.push_back(timerMsg);

        if (iv_timeoutMsgList.size() == 1)
        {
            sync_cond_signal(&iv_cv);
        }
    }
    mutex_unlock(&iv_mutex);
    return l_startTimer;
}

// main function to call for timeout monitoring
std::vector<msg_t*> pldmMsgTimeout::pldm_wait_timeout(const msg_q_t i_msgq, uint64_t & io_milliseconds)
{
    return Singleton<pldmMsgTimeout>::instance()._pldm_wait_timeout(i_msgq, io_milliseconds);
}

std::vector<msg_t*> pldmMsgTimeout::_pldm_wait_timeout(const msg_q_t i_msgq, uint64_t & io_milliseconds)
{
    std::vector<msg_t*> results;
    msg_t * timeout_msg = msg_allocate();
    bool timerStarted = start_pldm_timer(i_msgq, io_milliseconds, timeout_msg);
    TIMEOUT_STATE l_msg_state = TIMEOUT_STATE_RUNNING;

    timespec_t start = {};
    timespec_t finish = {};
    clock_gettime(CLOCK_MONOTONIC, &start);

    while (timerStarted)
    {
        msg_t * const msg = msg_wait(i_msgq);
        if (msg == timeout_msg)
        {
            if (l_msg_state == TIMEOUT_STATE_RUNNING)
            {
                l_msg_state = stop_pldm_timer(i_msgq);
            }
            break;
        }
        results.push_back(msg);
        if (l_msg_state == TIMEOUT_STATE_RUNNING)
        {
            l_msg_state = stop_pldm_timer(i_msgq);

            // REAL_TIMEOUT means a timeout msg has been sent to the queue
            // Any other response means we finished early
            if (l_msg_state != TIMEOUT_STATE_REAL_TIMEOUT)
            {
                // stopped before the timer finished
                break;
            }
            // else (l_msg_state = TIMEOUT_STATE_REAL_TIMEOUT) and
            // we want to do the loop again to remove the timeout msg that was sent to i_msgq
        }
    }
    if (l_msg_state == TIMEOUT_STATE_REAL_TIMEOUT)
    {
        io_milliseconds = 0;
    }
    else
    {
        clock_gettime(CLOCK_MONOTONIC, &finish);

        // calculate if any time is left after waiting
        uint64_t start_time_ns = (NS_PER_SEC * start.tv_sec) + start.tv_nsec;
        uint64_t finish_time_ns = (NS_PER_SEC * finish.tv_sec) + finish.tv_nsec;
        if (finish_time_ns > start_time_ns)
        {
            // return the milliseconds remaining of total wait time
            io_milliseconds -= ((finish_time_ns - start_time_ns) / NS_PER_MSEC);
        }
        else
        {
            io_milliseconds = 0;
        }
    }
    msg_free(timeout_msg);
    timeout_msg = nullptr;

    return results;
}
