#include <sys/task.h>
#include <kernel/task.H>

using namespace Systemcalls;

void task_yield()
{
    _syscall0(TASK_YIELD);
    return;
}

int task_create(void(*fn)(void*), void* ptr)
{
    return (int64_t) _syscall2(TASK_START, (void*)fn, ptr);
}

void task_end()
{
    _syscall0(TASK_END); // no return.
    return;
}

uint64_t task_gettid()
{
    return (uint64_t)_syscall0(TASK_GETTID);
}
