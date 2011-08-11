#include <assert.h>
#include <errno.h>
#include <kernel/msghandler.H>
#include <kernel/task.H>
#include <kernel/cpu.H>
#include <kernel/scheduler.H>
#include <kernel/taskmgr.H>
#include <kernel/console.H>

namespace Systemcalls { void TaskEnd(task_t*); };

void MessageHandler::sendMessage(msg_sys_types_t i_type, void* i_key,
                                 void* i_data, task_t* i_task)
{
    // Save pending info for when we get the response.
    MessageHandler_Pending* mp = new MessageHandler_Pending;
    mp->key = i_key;
    mp->task = i_task;

    // Send userspace message if one hasn't been sent for this key.
    if (!iv_pending.find(i_key))
    {
        // Create message.
        msg_t* m = new msg_t;
        m->type = i_type;
        m->data[0] = reinterpret_cast<uint64_t>(i_key);
        m->data[1] = reinterpret_cast<uint64_t>(i_data);
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
            waiter->cpu = i_task->cpu;
            TaskManager::setCurrentTask(waiter);
        }
        iv_msgq->lock.unlock();
    }

    // Defer task while waiting for message response.
    if ((NULL != i_task) && (TaskManager::getCurrentTask() == i_task))
    {
        i_task->cpu->scheduler->setNextRunnable();
    }

    // Insert pending info into our queue until response is recv'd.
    iv_pending.insert(mp);
}

int MessageHandler::recvMessage(msg_t* i_msg)
{
    // Verify userspace didn't give a non-kernel message type.
    if (i_msg->type < MSG_FIRST_SYS_TYPE)
    {
        return -EINVAL;
    }

    // Lock subsystem spinlock.
    if (iv_lock) iv_lock->lock();

    // Get <key, rc> from response.
    MessageHandler_Pending::key_type key =
        reinterpret_cast<MessageHandler_Pending::key_type>(i_msg->data[0]);
    int msg_rc = static_cast<int>(i_msg->data[1]);

    // Handle all pending responses.
    bool restored_task = false;
    MessageHandler_Pending* mp = NULL;
    while (NULL != (mp = iv_pending.find(key)))
    {
        // Call 'handle response'.
        HandleResult rc = this->handleResponse(
                static_cast<msg_sys_types_t>(i_msg->type),
                key, mp->task, msg_rc);

        // Remove pending information from outstanding queue.
        iv_pending.erase(mp);
        delete mp;

        // If there is no associated task then there is nothing to do, find
        // next pending response.
        if (!mp->task) continue;

        // Handle action requested from 'handle response'.
        if ((SUCCESS == rc) || (!msg_rc && UNHANDLED_RC == rc))
        {
            // Successful response, resume task.

            if (!restored_task) // Immediately execute first deferred task.
            {
                restored_task = true;
                TaskManager::setCurrentTask(mp->task);
            }
            else // Add other deferred tasks to scheduler ready queue.
            {
                mp->task->cpu->scheduler->addTask(mp->task);
            }
        }
        else if (UNHANDLED_RC == rc)
        {
            // Unsuccessful, unhandled response.  Kill task.
            printk("Unhandled msg rc %d for key %p on task %d @ %p\n",
                   msg_rc, key, mp->task->tid, mp->task->context.nip);
            Systemcalls::TaskEnd(mp->task);
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

    return 0;
}

MessageHandler::HandleResult MessageHandler::handleResponse(
        msg_sys_types_t i_type, void* i_key, task_t* i_task, int i_rc)
{
    // Indicate nothing specific has been done for this response.  Request
    // default behavior of resume/kill task based on rc.
    return UNHANDLED_RC;
}
