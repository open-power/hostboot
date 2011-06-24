#include <sys/syscall.h>
#include <sys/mmio.h>
#include <assert.h>
#include <kernel/task.H>
#include <kernel/cpu.H>

using namespace Systemcalls;

void* mmio_map(void* ra, size_t pages)
{
    return _syscall2(MMIO_MAP, ra, (void*)pages);
}

int mmio_unmap(void* ea, size_t pages)
{
    return (int64_t) _syscall2(MMIO_UNMAP, ea, (void*)pages);
}

uint64_t mmio_hmer_read()
{
    return (uint64_t) _syscall0(MMIO_HMER_READ);
}

int mmio_hmer_write(uint64_t value)
{
    return (int)(int64_t)_syscall1(MMIO_HMER_WRITE, (void*)value);
}

mutex_t * mmio_xscom_mutex()
{
    // Get task structure.
    register task_t* task;
    asm volatile("mr %0, 13" : "=r"(task));

    // Ensure task is pinned.
    crit_assert(task->affinity_pinned);
    
    // Return mutex from cpu structure.
    return &task->cpu->xscom_mutex;
}
