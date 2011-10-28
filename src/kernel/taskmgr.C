//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/kernel/taskmgr.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2010 - 2011
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
#include <util/singleton.H>
#include <kernel/taskmgr.H>
#include <kernel/task.H>
#include <kernel/pagemgr.H>
#include <kernel/cpumgr.H>
#include <kernel/stacksegment.H>
#include <kernel/stacksegment.H>
#include <kernel/cpu.H>
#include <kernel/scheduler.H>
#include <sys/task.h>
#include <arch/ppc.H>
#include <string.h>
#include <limits.h>
#include <assert.h>

extern "C" void userspace_task_entry();

void TaskManager::idleTaskLoop(void* unused)
{
    while(1)
    {
	setThreadPriorityLow();
    }
}

task_t* TaskManager::getCurrentTask()
{
    register task_t* current_task = (task_t*) getSPRG3();
    return current_task;
}

void TaskManager::setCurrentTask(task_t* t)
{
    t->cpu = CpuManager::getCurrentCPU();
    t->state = TASK_STATE_RUNNING;
    setSPRG3((uint64_t)t);
    return;
}

TaskManager::TaskManager() : iv_nextTid()
{
}

task_t* TaskManager::createIdleTask()
{
    return Singleton<TaskManager>::instance()._createIdleTask();
}

task_t* TaskManager::createTask(TaskManager::task_fn_t t, void* p)
{
    return Singleton<TaskManager>::instance()._createTask(t, p, true);
}

void TaskManager::endTask(task_t* t, void* retval, int status)
{
    Singleton<TaskManager>::instance()._endTask(t,retval,status);
}

void TaskManager::waitTask(task_t* t, int64_t tid, int* status, void** retval)
{
    Singleton<TaskManager>::instance()._waitTask(t,tid,status,retval);
}

task_t* TaskManager::_createIdleTask()
{
    return this->_createTask(&TaskManager::idleTaskLoop, NULL, false);
}

task_t* TaskManager::_createTask(TaskManager::task_fn_t t,
				 void* p, bool withStack)
{
    task_t* task = new task_t;
    memset(task, '\0', sizeof(task_t));

    task->tid = this->getNextTid();

    // Set NIP to be userspace_task_entry stub and GPR3 to be the
    // function pointer for the desired task entry point.
    task->context.nip = reinterpret_cast<void*>(&userspace_task_entry);
    task->context.gprs[4] = reinterpret_cast<uint64_t>(t);

    // Set up LR to be the entry point for task_end in case a task
    // 'returns' from its entry point.  By the Power ABI, the entry
    // point address is in (func_ptr)[0].
    task->context.lr = reinterpret_cast<uint64_t*>(&task_end)[0];

    // Set up GRP[13] as task structure reserved.
    task->context.gprs[13] = (uint64_t)task;

    // Set up argument.
    task->context.gprs[3] = (uint64_t) p;

    // Setup stack.
    if (withStack)
    {
        task->context.stack_ptr = StackSegment::createStack(task->tid);
        task->context.gprs[1] =
            reinterpret_cast<uint64_t>(task->context.stack_ptr);
    }
    else
    {
	task->context.stack_ptr = NULL;
        task->context.gprs[1] = NULL;
    }

    // Clear FP context (start with FP disabled on all tasks).
    task->fp_context = NULL;

    // Clear task state info.
    task->state = TASK_STATE_READY;
    task->state_info = NULL;

    // Create tracker instance for this task.
    task_tracking_t* tracker = new task_tracking_t;
    tracker->key = task->tid;
    tracker->task = task;
    tracker->status = -1;
    tracker->retval = NULL;
    tracker->wait_info = NULL;
    tracker->entry_point = reinterpret_cast<void*>(t);
    task->tracker = tracker;

    // Assign parent for tracker instance, add to task tree.
    iv_spinlock.lock();
    task_t* parent = getCurrentTask();
    if (NULL == parent)
    {
        tracker->parent = NULL;
        iv_taskList.insert(tracker);
    }
    else
    {
        tracker->parent = parent->tracker;
        parent->tracker->children.insert(tracker);
    }
    iv_spinlock.unlock();

    return task;
}


void TaskManager::_endTask(task_t* t, void* retval, int status)
{
    // Update task state.
    t->state = TASK_STATE_ENDED;

    // Make sure task pointers are updated before we delete this task.
    if (getCurrentTask() == t)
        t->cpu->scheduler->setNextRunnable();

    iv_spinlock.lock();

    // Update status in tracker.
    t->tracker->status = status;
    t->tracker->retval = retval;
    t->tracker->task = NULL; // NULL signifies task is complete for now.

    if (t->detached) // If detached, just clean up the tracker.
    {
        removeTracker(t->tracker);
    }
    else // If not detached, do join.
    {
        if (t->tracker->parent && t->tracker->parent->wait_info)
        {
            task_tracking_t* parent = t->tracker->parent;

            if ((parent->wait_info->tid < 0) ||
                (parent->wait_info->tid == t->tid))
            {
                if (parent->wait_info->status)
                {
                    *(parent->wait_info->status) = status;
                }
                if (parent->wait_info->retval)
                {
                    *(parent->wait_info->retval) = retval;
                }
                delete parent->wait_info;
                parent->wait_info = NULL;
                lwsync(); // Ensure status is pushed to memory before parent
                          // task begins execution.

                TASK_SETRTN(parent->task, t->tid);
                removeTracker(t->tracker);
                parent->task->cpu->scheduler->addTask(parent->task);
            }
        }
        else if (!t->tracker->parent) // Parented by kernel.
        {
            if (status == TASK_STATUS_CRASHED)
            {
                printk("Critical: Parentless task %d crashed.\n",
                       t->tid);
                kassert(status != TASK_STATUS_CRASHED);
            }
            else
            {
                removeTracker(t->tracker);
            }
        }
    }
    iv_spinlock.unlock();

    // Clean up task memory.
    // Delete FP context.
    if (t->fp_context)
        delete t->fp_context;
    // Delete stack.
    StackSegment::deleteStack(t->tid);
    // Delete task struct.
    delete t;
}

void TaskManager::_waitTask(task_t* t, int64_t tid, int* status, void** retval)
{
    iv_spinlock.lock();

    do
    {
        // Search for a candidate completed child task.
        task_tracking_t* child_task = NULL;

        if (tid < 0) // -1 => Look for any task.
        {
            task_tracking_t* children = t->tracker->children.begin();
            if (!children)
            {
                // No children at all, this is a deadlock.
                TASK_SETRTN(t, -EDEADLK);
                break;
            }
            while(children)
            {
                if (!children->task)
                {
                    child_task = children;
                    children = NULL;
                }
                else
                {
                    children = children->next;
                }
            }
        }
        else // Look for a specific task.
        {
            // This copy is needed to create a reference of the appropriate
            // type to pass into the 'find' function.  Otherwise, you get
            // type-punned reference errors.
            task_tracking_t::key_type _tid = tid;

            child_task = t->tracker->children.find(_tid);

            // Check that we aren't asking to wait on a task that isn't our
            // child, potential deadlock.
            if (NULL == child_task)
            {
                TASK_SETRTN(t, -EDEADLK);
                break;
            }
        }

        // If there was a finished task found return information to caller.
        if (child_task && (child_task->task == NULL))
        {
            TASK_SETRTN(t, child_task->key);
            if (status)
            {
                *status = child_task->status;
            }
            if (retval)
            {
                *retval = child_task->retval;
            }
            removeTracker(child_task);
        }
        else // Otherwise, create wait-info to defer task.
        {
            task_wait_t* tj = t->tracker->wait_info = new task_wait_t;
            tj->tid = tid;
            tj->status = status;
            tj->retval = retval;

            t->state = TASK_STATE_BLOCK_JOIN;
            t->state_info = reinterpret_cast<void*>(tid);

            t->cpu->scheduler->setNextRunnable();
        }

    } while(0);

    iv_spinlock.unlock();

    return;
}

void TaskManager::removeTracker(task_tracking_t* t)
{
    task_tracking_list_t* trackingList = NULL;

    task_tracking_t* parent = NULL;

    if (t->parent)
    {
        trackingList = &t->parent->children;
        parent = t->parent;
    }
    else // Parent is kernel.
    {
        trackingList = &iv_taskList;
    }

    // Remove tracker from parent list.
    trackingList->erase(t);

    // Add children to parent.
    while(task_tracking_t* child = t->children.remove())
    {
        child->parent = parent;
        if ((!parent) && (!child->task)) // Deal with finished children
                                         // becoming parented by the kernel.
        {
            if (child->status == TASK_STATUS_CRASHED)
            {
                trackingList->insert(child); // Insert into kernel list so it
                                             // is there for debug.

                printk("Critical: Parentless task %d crashed.\n",
                       child->key);
                kassert(child->status != TASK_STATUS_CRASHED);
            }
            else
            {
                removeTracker(child);
            }
        }
        else
        {
            trackingList->insert(child);
        }
    }

    // Delete tracker object.
    delete t;
}
