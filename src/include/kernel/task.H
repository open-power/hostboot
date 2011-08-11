/** @file task.H
 *  @brief Defines kernel information about tasks.
 */
#ifndef __KERNEL_TASK_H
#define __KERNEL_TASK_H

#include <kernel/types.h>

/** @struct context_t
 *  @brief Defines the save-restore context for the task.
 *
 *  See PowerISA for information on registers listed.
 */
struct context_t
{
    void* stack_ptr;
    void* nip;
    uint64_t gprs[32];
    uint64_t lr;
    uint64_t cr;
    uint64_t ctr;
    uint64_t xer;
};

/** @struct task_t
 *  @brief The kernel-level task structure.
 */
struct task_t
{
        /** Pointer to the CPU this task is assigned to. */
    cpu_t* cpu;
        /** Context information.  This MUST stay here due to
         *  save-restore asm code. */
    context_t context;

        /** Task ID */
    tid_t tid;
        /** Determines if user-space would like this task pinned to a CPU.
         *  This value is considered a count of the number of times the pinned
         *  as been requested, so pinning can be used recursively. */
    uint64_t affinity_pinned;

        // Pointers for queue containers.
    task_t* prev;
    task_t* next;
};

enum { TASK_DEFAULT_STACK_SIZE = 4 };

// Macros for manipulating task's saved contexts.
#define TASK_GETARGN(t, n) (t->context.gprs[n+4])
#define TASK_GETARG0(t) (TASK_GETARGN(t,0))
#define TASK_GETARG1(t) (TASK_GETARGN(t,1))
#define TASK_GETARG2(t) (TASK_GETARGN(t,2))
#define TASK_GETARG3(t) (TASK_GETARGN(t,3))
#define TASK_GETARG4(t) (TASK_GETARGN(t,4))
#define TASK_GETARG5(t) (TASK_GETARGN(t,5))
#define TASK_GETARG6(t) (TASK_GETARGN(t,6))
#define TASK_GETARG7(t) (TASK_GETARGN(t,7))
#define TASK_SETRTN(t, n) (t->context.gprs[3] = (n))


#endif
