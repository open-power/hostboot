#include <sys/task.h>
#include <sys/syscall.h>
#include <kernel/task.H>
#include <kernel/taskmgr.H>
#include <kernel/cpu.H>

using namespace Systemcalls;

void task_yield()
{
    _syscall0(TASK_YIELD);
    return;
}

tid_t task_create(void(*fn)(void*), void* ptr)
{
    return (tid_t)(uint64_t) _syscall2(TASK_START, (void*)fn, ptr);
}

void task_end()
{
    _syscall0(TASK_END); // no return.
    return;
}

tid_t task_gettid()
{
    // Even though we have a syscall for GETTID, we also have the task in 
    // GRP13.

    register task_t* task;
    asm volatile("addi %0, 13, 0" : "=r"(task));
    return task->tid;
    //return (tid_t)_syscall0(TASK_GETTID);
}

cpuid_t task_getcpuid()
{
    register task_t* task;
    asm volatile("addi %0, 13, 0" : "=r"(task));
    return task->cpu->cpu;
}
