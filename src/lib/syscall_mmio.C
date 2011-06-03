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
    assert(task->affinity_pinned);

    // Get mutex from cpu structure.
    mutex_t * mutex = task->cpu->xscom_mutex;

    // Create mutex if not created.
    if (NULL == mutex)
    {
        mutex = mutex_create();

        // Atomically update xscom_mutex with new mutex.
        if (!__sync_bool_compare_and_swap(&task->cpu->xscom_mutex, NULL, mutex))
        {
            // Failed, some other thread beat us to it.

            // Destroy mutex and get one created by other thread in the
            // meantime.
            mutex_destroy(mutex);
            mutex = task->cpu->xscom_mutex;
        }
    }

    return mutex;
}
