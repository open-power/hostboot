#include <sys/syscall.h>
#include <sys/mm.h>
#include <arch/ppc.H>

using namespace Systemcalls;

/**
 * System call to allocate a block of virtual memory within the base segment
 */
int mm_alloc_block(msg_q_t mq,void* va,uint64_t size)
{
    return (int64_t)_syscall3(MM_ALLOC_BLOCK, mq, va, (void*)size);
}


/*
 * Call to flush out the instruction cache
 * From the PowerPC ISA book II, section 1.8 
 *     Instruction Storage
 */
void mm_icache_invalidate(void * i_addr, size_t i_cpu_word_count)
{
    // Make sure 8 byte boundary
    uint64_t addr = (uint64_t)i_addr  & ~0x7ull;
    uint64_t * dest = (uint64_t*)addr;

    for(size_t i = 0; i < i_cpu_word_count; ++i)
    {
        dcbst(dest);
        ++dest;
    }

    lwsync();

    dest = (uint64_t*)addr;
    for(size_t i = 0; i < i_cpu_word_count; ++i)
    {
        icbi(dest);
        ++dest;
    }

    isync();
}
        
