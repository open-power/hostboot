#include <sys/task.h>
#include <sys/syscall.h>
#include <kernel/task.H>
#include <kernel/taskmgr.H>

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
    // Even though we have a syscall for GETTID, we can implement this as a 
    // direct access to SPRG3.  On processor that do not support unprivilaged
    // access to this SPR, we implement it as an emulated instruction in the
    // exception handler.

    return TaskManager::getCurrentTask()->tid;
    //return (tid_t)_syscall0(TASK_GETTID);
}
