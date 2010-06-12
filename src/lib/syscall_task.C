#include <sys/task.h>
#include <sys/syscall.h>
#include <kernel/task.H>

using namespace Systemcalls;

void task_yield()
{
    _syscall0(TASK_YIELD);
    return;
}

tid_t task_create(void(*fn)(void*), void* ptr)
{
    return (tid_t) _syscall2(TASK_START, (void*)fn, ptr);
}

void task_end()
{
    _syscall0(TASK_END); // no return.
    return;
}

tid_t task_gettid()
{
    return (tid_t)_syscall0(TASK_GETTID);
}
