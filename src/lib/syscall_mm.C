#include <sys/syscall.h>
#include <sys/mm.h>

using namespace Systemcalls;

/**
 * System call to allocate a block of virtual memory within the base segment
 */
int mm_alloc_block(msg_q_t mq,void* va,uint64_t size)
{
    return (int64_t)_syscall3(MM_ALLOC_BLOCK, mq, va, (void*)size);
}
