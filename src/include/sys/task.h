/** @file task.h
 *  @brief Contains the prototypes for system calls related to tasking.
 */
#ifndef __SYS_TASK_H
#define __SYS_TASK_H

#include <stdint.h>
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
tid_t task_create(void(*start_routine)(void*), void* arg);

/** @fn task_end
 *  @brief End the calling task.
 *
 *  See POSIX pthread_exit.
 *
 *  @note A task must call task_end when it wishes to exit.  If a task were
 *        to simply return from its entry point function, the kernel sets up
 *        the initial task structure with the link-register pointing to this
 *        function.  Therefore, returning from the entry point function will
 *        also cause the task to end cleanly using this function.
 */
void task_end();

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

#ifdef __cplusplus
}
#endif
#endif
