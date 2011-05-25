#include <sys/syscall.h>
#include <sys/mmio.h>

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
