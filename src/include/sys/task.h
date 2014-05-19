/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/sys/task.h $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2010,2014              */
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
/** @file task.h
 *  @brief Contains the prototypes for system calls related to tasking.
 */
#ifndef __SYS_TASK_H
#define __SYS_TASK_H

#include <stdint.h>
#include <builtins.h>
#include <kernel/types.h>

#ifdef __cplusplus
extern "C"
{
#endif

/** @fn task_yield
 *  @brief Defer task if there are other ready-tasks available
 *
 *  See POSIX sched_yield.
 */
void task_yield();

/** @fn task_create
 *  @brief Create a new task.
 *
 *  @param[in] start_routine - Function pointer to start execution at.
 *  @param[in] arg - Pointer to pass to task as argument.
 *
 *  @return The task ID of the child.
 *
 *  See POSIX pthread_create.
 */
tid_t task_create(void*(*start_routine)(void*), void* arg);

/** @fn task_end
 *  @brief End the calling task.
 *
 *  See POSIX pthread_exit.
 *
 *  @note A task could call task_end when it wishes to exit. But it will likely 
 *        cause a memory leak. It is better for a task to 
 *        simply return from its entry point function, the kernel sets up
 *        the initial task structure with the link-register pointing to this
 *        function. The "NO_RETURN" does not call the destructors to clean up. 
 *        Might be used in case of task needing to be terminated due to 
 *        unknown cause.
 */
void task_end() NO_RETURN;

/** @fn task_end2
 *  @brief End the calling task with a return value.
 *        Will likely cause a memory leak. Better to return the value on the 
 *        return to the entry point. See comments on task_end. 
 *
 *  See POSIX pthread_exit.
 *
 *  @param[in] retval - A pointer to return to the task performing task_join /
 *                      task_wait on this task.
 */
void task_end2(void* retval) NO_RETURN;

/** @define task_crash
 *  @brief End the calling task as if it crashed.
 *
 */
#define task_crash() ((*(volatile char*)NULL) = 'F')

/** @fn task_gettid
 *  @brief Get task ID of calling task.
 *
 *  See Linux gettid.
 */
tid_t task_gettid();

/** @fn task_getcpuid
 *  @brief Get the CPU ID of the CPU currently executing this task.
 *
 *  This function is simply for debug / tracing purposes.  At the time this
 *  function call returns, or any time afterwards, a pre-emptive context
 *  switch could occur and the task could be migrated to another CPU when
 *  execution resumes.  Therefore there is no guarentee that the return
 *  value is valid at anytime after this function returns.
 */
cpuid_t task_getcpuid();

/** @fn task_exec
 *  @brief Requests the VFS to create a new task from a path string.
 *
 *  Calls the VFS process and looks up the module referenced in path and
 *  creates a new task from the _start function in that module.
 *
 *  @param[in] path - The module desired to start.
 *  @param[in] arg - A pointer passed to the child task as argument.
 *
 *  @return Task ID of the child task.
 *
 *  See POSIX fork + exec.
 */
tid_t task_exec(const char* path, void* arg);

/** @fn task_affinity_pin
 *  @brief Pins a task onto the CPU it is currently executing on.
 *
 *  This function may be called any number of times and each should be paired
 *  with a task_affinity_unpin call.  This is so that callers do not need to
 *  be concerned with affinity pinning desires of functions above and below in
 *  a call stack.
 *
 *  See Linux sched_setaffinity.
 */
void task_affinity_pin();

/** @fn task_affinity_unpin
 *  @brief Unpins a task from the CPU it is currently executing on.
 *
 *  This function should be called after a task_affinity_pin call to allow a
 *  task to migrate freely between CPUs.
 *
 *  See Linux sched_setaffinity.
 */
void task_affinity_unpin();

/** @fn task_affinity_migrate_to_master
 *  @brief Moves a task from the CPU it is on to the master core/thread.
 *
 *  Unless the affinity is pinned, the task could be migrated to another
 *  core at any point in time.  Suggestion is to use task_affinity_pin
 *  prior to this call.
 */
void task_affinity_migrate_to_master();

/** @enum task_status
 *  @brief Status of how a task exited.
 */
enum task_status
{
        /** Task called task_end cleanly. */
    TASK_STATUS_EXITED_CLEAN,
        /** Task crashed.  Ended by the kernel due to error. */
    TASK_STATUS_CRASHED,
};

/** @fn task_detach
 *  @brief Sets the calling task to the 'detached' state, meaning no parent
 *         may task_wait_tid on it.
 */
void task_detach();

/** @fn task_wait_tid
 *  @brief Block calling task until a requested child process exits.
 *
 *  See also: POSIX 'waitid' / Linux 'waitpid'.
 *
 *  @param[in] tid - Task to wait for completion.
 *
 *  @param[out] status - Optional address to write child status.
 *  @param[out] retval - Optional address to write return-value.
 *
 *  Status values come from task_status enumeration.
 *  Retval values come from child's 'task_end2' parameter.
 *
 *  @note All non-detached tasks must be waited on by their parent to ensure
 *        there are not kernel memory-leaks.
 *
 *  @note If a parent task ends prior to waiting on its children, the children
 *        become parented by their grand-parents, who must do the wait.
 *
 *  @return tid of child waited on or negative number on error.
 *
 *  @retval EDEADLK - Performing this wait would deadlock the caller such as
 *                    when it has no children.
 *  @retval EFAULT - Bad memory address given for status or retval parameter.
 */
tid_t task_wait_tid(tid_t tid, int* status, void** retval);

/** @fn task_wait
 *  @brief Block calling task until any child process exits.
 *
 *  See also: Linux 'wait'.
 *
 *  @param[out] status - Optional address to write child status.
 *  @param[out] retval - Optional address to write return-value.
 *
 *  Status values come from task_status enumeration.
 *  Retval values come from child's 'task_end2' parameter.
 *
 *  @note All non-detached tasks must be waited on by their parent to ensure
 *        there are not kernel memory-leaks.
 *
 *  @note If a parent task ends prior to waiting on its children, the children
 *        become parented by their grand-parents, who must do the wait.
 *
 *  @return tid of child waited on or negative number on error.
 *
 *  @retval EDEADLK - Performing this wait would deadlock the caller such as
 *                    when it has no children.
 *  @retval EFAULT - Bad memory address given for status or retval parameter.
 */
tid_t task_wait(int* status, void** retval);

#ifdef __cplusplus
}
#endif
#endif
