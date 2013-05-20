/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/lib/syscall_mm.C $                                        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#include <sys/syscall.h>
#include <sys/mm.h>
#include <arch/ppc.H>
#include <kernel/vmmmgr.H>
#include <kernel/task.H>


using namespace Systemcalls;

/**
 * System call to allocate a block of virtual memory within the base segment
 */
int mm_alloc_block(msg_q_t mq,void* va,uint64_t size)
{
    return (int64_t)_syscall3(MM_ALLOC_BLOCK, mq, va, (void*)size);
}

/**
 * System call to remove page(s) by a specified operation
 */
int mm_remove_pages(PAGE_REMOVAL_OPS i_op, void* i_vaddr, uint64_t i_size)
{
    return (int64_t)_syscall3(MM_REMOVE_PAGES, (void*)i_op, i_vaddr,
                              (void*)i_size);
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

    for(size_t i = 0; i < i_cpu_word_count; i += getCacheLineWords())
    {
        dcbst(dest);
        dest += getCacheLineWords();
    }

    lwsync();

    // According to core design team we only need to do a single icbi,
    // since the i-cache is kept coherent with the d-cache.  The single
    // icbi invalidates the "scoreboard" in the core which, in combination
    // with the isync, causes the core to go back out to l2-cache for any
    // instructions past this.
    icbi(reinterpret_cast<void*>(addr));
    isync();
}


/**
 * System call update permissions on a page for a given virtual address
 */
int mm_set_permission(void* va, uint64_t size, uint64_t access_type)
{
    return (int64_t)_syscall3(MM_SET_PERMISSION, va, (void*)size,  (void*)access_type);
}


/**
 * System call to return the physical address backing a virtual address
 */
uint64_t mm_virt_to_phys( void* i_vaddr )
{
    return (uint64_t) _syscall1(MM_VIRT_TO_PHYS,i_vaddr);
}

/**
 * System call to extend Memory to 32Meg.
 */
int mm_extend(MM_EXTEND_SIZE i_size)
{
    return (int64_t)_syscall1(MM_EXTEND, reinterpret_cast<void*>(i_size));
}


/**
 * System call to create a block of memory at a specific physical address
 */
int mm_linear_map(void *i_paddr, uint64_t i_size)
{
    return (int64_t)_syscall2(MM_LINEAR_MAP, i_paddr, (void*)i_size);
}

/**
 * mm_tolerate_ue.  Update task state and do appropriate synchronization.
 */
void mm_tolerate_ue(uint64_t i_state)
{
    // Get task structure.
    register task_t* task;
    asm volatile("mr %0, 13" : "=r"(task));

    // Update task state.
    task->tolerate_ue = (i_state != 0);

    // Note: We do not need any sort of synchronization instructions here
    //       because the state is only used by the local HW thread which
    //       might be handling the machine check due to memory UE.  Any
    //       exception is a context synchronizing event which ensures
    //       that all preceeding instructions have completed, so there
    //       are no visible effects of instruction reordering with respect
    //       to this state change.
}

/**
 * System call to map an arbitrary physical address into the VMM.
 */
void* mm_block_map(void* i_paddr, uint64_t i_size)
{
    return _syscall3(DEV_MAP, i_paddr, (void*)i_size, (void*)1);
}

/**
 * System call to unmap a previous mm_block_map.
 */
int mm_block_unmap(void* i_vaddr)
{
    return (int64_t) _syscall1(DEV_UNMAP, i_vaddr);
}
