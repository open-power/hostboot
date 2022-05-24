/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/taskmgr.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2010,2022                        */
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
#ifndef __KERNEL_TASKMGR_H
#define __KERNEL_TASKMGR_H

#include <kernel/types.h>
#include <util/lockfree/counter.H>
#include <kernel/vmmmgr.H>
#include <sys/task.h>
#include <util/locked/list.H>
#include <kernel/spinlock.H>

    // Forward declaration.
struct task_tracking_t;
struct task_wait_t;
    /** Typedef for a list of task_tracking_t's. */
typedef Util::Locked::List<task_tracking_t, tid_t> task_tracking_list_t;

/** @struct task_tracking_t
 *  Stores the parent/child relationships and join information for tasks.
 *
 *  The task_tracking_t's become a tree so that we can create a ps-like
 *  debug output and so that a task can do a wait() on all of its children.
 */
struct task_tracking_t
{
    typedef tid_t key_type;

        /** previous pointer for list. */
    task_tracking_t* prev;
        /** next pointer for list. */
    task_tracking_t* next;

        /** pointer to parent's tracking info. */
    task_tracking_t* parent;
        /** list of all children. */
    task_tracking_list_t children;

        /** tid as a key for list. */
    key_type key;
        /** Pointer to task structure if it is still running. */
    task_t* task;

        /** Crash/clean-exit status if task has ended. */
    int status;
        /** Return-value to task_end2() if task has ended. */
    void* retval;
        /** Task-wait state object. */
    task_wait_t* wait_info;

        /** Record the original entry point of the thread for debug purpose. */
    void* entry_point;
};

/** @struct task_wait_t
 *  Stores the parameters for the task_wait syscall for a task which is
 *  deferred due to the syscall.
 */
struct task_wait_t
{
        /** Tid waiting on (or -1 for any). */
    int64_t tid;
        /** Address to return the child status. */
    int*    status;
        /** Address to return the child return-value. */
    void**  retval;
};

/** @class TaskManager
 *  Kernel management class to deal with task creation / exit.
 */
class TaskManager
{
    public:
        /** @brief Returns a pointer to the currently running task on this
         *         CPU.
         *
         *  @retval NULL - Kernel has never started running any tasks.
         *  @retval non-NULL - The task most recently running and/or will be
         *                     running when kernel returns to user-space.
         */
	static task_t* getCurrentTask();

        /** @brief Sets the current task pointer in this CPU object.
         *
         *  @param[in] t - The task to assign on this CPU.
         */
	static void setCurrentTask(task_t* t);

            /** Typedef for task entry points. */
	typedef void* (*task_fn_t)(void*);

        /** @brief Create a new task object.
         *
         *  @param[in] t - The entry point to start the task at.
         *  @param[in] p - An argument pointer to pass to the task.
         *  @param[in] kernelParent - Should the kernel be assigned the parent
         *                            of the new task.
         */
	static task_t* createTask(task_fn_t t, void* p,
                                  bool kernelParent = false);

        /** @brief End / destroy a task object.
         *
         *  @param[in] t - The task to end.
         *  @param[in] retval - Return value from the task.
         *  @param[in] status - TASK_STATUS_* enumeration of how the task ended.
         *
         *  @note This function obtains the VMM-subsystem spinlock as part of
         *        releasing the task stack.
         */
        static void endTask(task_t* t, void* retval, int status);

        /** @brief Perform the 'task_wait' for a task.
         *
         *  Returns the child information if the requested child has already
         *  ended or defers the task if the child requested is still running.
         *
         *  @param[in] t - The task requesting the wait.
         *  @param[in] tid - The child task requested to wait on or -1 for any.
         *  @param[out] status - The address to write the child status.
         *  @param[out] retval - The address to write the child retval.
         */
        static void waitTask(task_t* t, int64_t tid,
                             int* status, void** retval);

        /**
         * Add pointers to the global debug area
         */
        static void addDebugPointers();

        friend class CpuManager;
        friend class PageTableManager;

    protected:
	TaskManager();
	~TaskManager() {};

            /** Create a new task where the entry point is idleTaskLoop. */
	static task_t* createIdleTask();

    private:
            /** Get the next TID in the task sequence. */
	tid_t getNextTid() { return iv_nextTid.next(); };

            /** Run the idle task loop */
	static void* idleTaskLoop(void*);

            // Internal implementations of non-static / non-_ functions.
	task_t* _createIdleTask();
	task_t* _createTask(task_fn_t, void*, bool, bool);
        void _endTask(task_t*, void*, int);
        void _waitTask(task_t*, int64_t, int*, void**);

        /** Remove a tracker from the tracker-tree and delete it.
         *
         *  @param[in] t - The tracker to remove.
         *  @note Spinlock-locking of the tracker-tree is the
         *        responsibility of the caller.
         */
        void removeTracker(task_tracking_t* t);

        /**
         * Add pointers to the global debug area
         */
        void _addDebugPointers();

            /** Atomic monotonically increasing counter to use for TIDs. */
        Util::Lockfree::Counter<tid_t> iv_nextTid;

            /** Task-tracking tree spinlock. */
        Spinlock iv_spinlock;
            /** Task-tracking tree. */
        task_tracking_list_t iv_taskList;

};

#endif
