/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/msghandler.C $                                     */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#include <assert.h>
#include <errno.h>
#include <util/locked/queue.H>
#include <kernel/msghandler.H>
#include <kernel/task.H>
#include <kernel/cpu.H>
#include <kernel/scheduler.H>
#include <kernel/taskmgr.H>
#include <kernel/console.H>

void MessageHandler::sendMessage(msg_sys_types_t i_type, void* i_key,
                                 void* i_data, task_t* i_task)
{
    // Task to switch to due to waiter being ready to handle message.
    task_t* ready_task = NULL;

    // Save pending info for when we get the response.
    MessageHandler_Pending* mhp = new MessageHandler_Pending();
    mhp->key = i_key;
    mhp->task = i_task;

    // Update block status for task.
    if (NULL != i_task)
    {
        i_task->state = TASK_STATE_BLOCK_USRSPACE;
        i_task->state_info = i_key;
    }

    // Send userspace message if one hasn't been sent for this key.
    if (!iv_pending.find(i_key))
    {
        // Create message.
        msg_t* m = new msg_t();
        m->type = i_type;
        m->data[0] = reinterpret_cast<uint64_t>(i_key);
        m->data[1] = reinterpret_cast<uint64_t>(i_data);
        m->extra_data = NULL;
        m->__reserved__async = 1;

        // Create pending response object.
        MessagePending* mp = new MessagePending();
        mp->key = m;
        mp->task = reinterpret_cast<task_t*>(this);

        // Send to userspace...
        iv_msgq->lock.lock();
        task_t* waiter = iv_msgq->waiting.remove();
        if (NULL == waiter) // No waiting task, queue for msg_wait call.
        {
            iv_msgq->messages.insert(mp);
        }
        else // Waiting task, set msg as return and release.
        {
            TASK_SETRTN(waiter, (uint64_t) m);
            iv_msgq->responses.insert(mp);
            ready_task = waiter;
        }
        iv_msgq->lock.unlock();
    }

    // Defer task while waiting for message response.
    if (NULL != i_task)
    {
        if (i_task == TaskManager::getCurrentTask())
        {
            // Switch to ready waiter, or pick a new task off the scheduler.
            if (ready_task)
            {
                TaskManager::setCurrentTask(ready_task);
                ready_task = NULL;
            }
            else
            {
                // Select next task off scheduler.
                i_task->cpu->scheduler->setNextRunnable();
            }
        }
    }

    // Switch to ready waiter.
    if (NULL != ready_task)
    {
        task_t* current = TaskManager::getCurrentTask();
        current->cpu->scheduler->addTask(current);
        TaskManager::setCurrentTask(ready_task);
        ready_task = NULL;
    }

    // Insert pending info into our queue until response is recv'd.
    iv_pending.insert(mhp);
}

int MessageHandler::recvMessage(msg_t* i_msg)
{
    // Verify userspace didn't give a non-kernel message type.
    if (i_msg->type < MSG_FIRST_SYS_TYPE)
    {
        printkd("MessageHandler::recvMessage> type=%d\n", i_msg->type);
        return -EINVAL;
    }

    // Lock subsystem spinlock.
    if (iv_lock) iv_lock->lock();

    // List of tasks to end due to errors.
    //     Ending the task must happen outside of the spinlock due to
    //     requirements of TaskManager::endTask.
    Util::Locked::Queue<task_t> endTaskList;

    // Get <key, rc> from response.
    MessageHandler_Pending::key_type key =
        reinterpret_cast<MessageHandler_Pending::key_type>(i_msg->data[0]);
    int msg_rc = static_cast<int>(i_msg->data[1]);

    // Handle all pending responses.
    bool restored_task = false;
    MessageHandler_Pending* mhp = NULL;
    while (NULL != (mhp = iv_pending.find(key)))
    {
        task_t* deferred_task = mhp->task;

        // Call 'handle response'.
        HandleResult rc = this->handleResponse(
                static_cast<msg_sys_types_t>(i_msg->type),
                key, mhp->task, msg_rc);

        // Remove pending information from outstanding queue.
        iv_pending.erase(mhp);
        delete mhp;

        // If there is no associated task then there is nothing to do, find
        // next pending response.
        if (!deferred_task) continue;

        // Handle action requested from 'handle response'.
        if ((SUCCESS == rc) || (!msg_rc && UNHANDLED_RC == rc))
        {
            // Successful response, resume task.

            if (!restored_task) // Immediately execute first deferred task.
            {
                restored_task = true;
                TaskManager::setCurrentTask(deferred_task);
            }
            else // Add other deferred tasks to scheduler ready queue.
            {
                deferred_task->cpu->scheduler->addTask(deferred_task);
            }
        }
        else if (UNHANDLED_RC == rc)
        {
            // Unsuccessful, unhandled response.  Kill task.
            printk("Unhandled msg rc %d for key %p on task %d @ %p\n",
                   msg_rc, key, deferred_task->tid, deferred_task->context.nip);
            endTaskList.insert(deferred_task);
        }
        else if (CONTINUE_DEFER == rc)
        {
            // Requested to continue deferring task.  Do nothing.
        }
        else
        {
            // Logic bug (new HandleResult?).  Shouldn't be here.
            kassert(false);
        }
    }

    // Finished handling the response, unlock subsystem.
    if (iv_lock) iv_lock->unlock();

    while(task_t* end_task = endTaskList.remove())
    {
        TaskManager::endTask(end_task, i_msg->extra_data, TASK_STATUS_CRASHED);
    }

    // Release memory for message (created from sendMsg).
    delete(i_msg);

    return 0;
}

MessageHandler::HandleResult MessageHandler::handleResponse(
        msg_sys_types_t i_type, void* i_key, task_t* i_task, int i_rc)
{
    // Indicate nothing specific has been done for this response.  Request
    // default behavior of resume/kill task based on rc.
    return UNHANDLED_RC;
}
