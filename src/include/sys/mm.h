/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/sys/mm.h $                                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2015                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#ifndef __SYS_MM_H
#define __SYS_MM_H

#include <stdint.h>
#include <limits.h>
#include <sys/msg.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * Page removal operations
 *
 * RELEASE : Writes dirty&write-tracked pages out to a storage device
 *           and removes other pages
 * FLUSH   : Only writes dirty&write-tracked pages out to a storage
 *           device
 */
enum PAGE_REMOVAL_OPS
{
    RELEASE = 0,
    FLUSH = 1,
};

/**
 * Page permission types mapped to the same bits in the Shadow PTE
 */
enum PAGE_PERMISSIONS
{
  READ_ONLY = 0x00000001,
  WRITABLE = 0x000000002,
  EXECUTABLE = 0x00000004,
  WRITE_TRACKED = 0x00000008,
  ALLOCATE_FROM_ZERO = 0x00000010,
  NO_ALLOCATE_FROM_ZERO = 0x00000020,
  NO_ACCESS = 0x00000040,
  BYPASS_HRMOR = 0x00000080,
  GUARDED = 0x00000100,
};


/** @fn mm_alloc_block()
 *  @brief System call to allocate virtual memory block in the base segment
 *
 *  @param[in] mq - Message queue to be associated with the block
 *  @param[in] va - Page aligned base virtual address of the block
 *                  to be allocated
 *  @param[in] size - Requested virtual memory size of the block
 *
 *  @return int - 0 for successful block allocation, non-zero otherwise
 */
int mm_alloc_block(msg_q_t mq,void* va,uint64_t size);

/** @fn mm_remove_pages()
 *  @brief System call to remove pages by a specified operation
 *
 *  @param[in] i_op - Page removal operation to perform
 *  @param[in] i_vaddr - Virtual address associated to page(s)
 *  @param[in] size - Size of memory to perform page removal on
 *
 *  @return int - 0 for successful page removal, non-zero otherwise
 */
int mm_remove_pages(PAGE_REMOVAL_OPS i_op, void* i_vaddr, uint64_t i_size);

/** @fn mm_set_permission()
 *  @brief System call to set the page permissions
 *
 *  @param[in] va - virtual address of the pages(s) to update permission
 *  @param[in] size - requested size of memory in bytes
 *          if size = 0 then only a single page will be updated.
 *  @param[in] access_type - Type of permission to be given to the page(s)
 *
 *  @return int - 0 for successful update of permission, non-zero otherwise
 */
int mm_set_permission(void* va, uint64_t size, uint64_t access_type);

enum MM_EXTEND_SIZE
{
    MM_EXTEND_POST_SECUREBOOT, //< Extend memory to include bottom of cache.
    MM_EXTEND_FULL_CACHE,      //< Extend memory to include full cache (8mb).
    MM_EXTEND_REAL_MEMORY,     //< Extend memory into real mainstore.
};

/** @fn mm_extend()
 *  @brief System call to extend memory.
 *
 *  @param[in] i_size - Amount to extend memory by.
 *
 *  @return int - 0 for successful extension of memory, non-zero otherwise
 */
int mm_extend(MM_EXTEND_SIZE i_size = MM_EXTEND_REAL_MEMORY);

/** @fn mm_linear_map()
 *  @brief   Allocates a block of memory of the given size at a specified
 *           address (direct physical to virtual mapping)
 *  @param[in] i_paddr - physical address of the location for the block
 *  @param[in] size - size of the block requested
 *
 *  @return int - 0 for successful add, non-zero otherwise
 */
int mm_linear_map(void *i_paddr, uint64_t i_size);

/** @fn mm_block_map()
 *  @brief   Allocate an arbitrary physical address into the VMM.
 *  @param[in] i_paddr - Physical address of the memory to map.
 *  @param[in] i_size - Size of memory to map (in bytes).
 *
 *  @return Virtual address or NULL.
 */
void* mm_block_map(void* i_paddr, uint64_t i_size);

/** @fn mm_guarded_block_map()
 *  @brief   Allocate an arbitrary physical address into the VMM with guarded
 *    permissions to prevent out-of-order access to instructions and data.
 *  @note Use mm_block_unmap to unmap a region mapped using
 *    mm_guarded_block_map.
 *  @param[in] i_paddr - Physical address of the memory to map.
 *  @param[in] i_size - Size of memory to map (in bytes).
 *
 *  @return Virtual address or NULL.
 */
void* mm_guarded_block_map(void* i_paddr, uint64_t i_size);

/** @fn mm_block_unmap()
 *  @brief   Unallocate a block previously allocated with mm_block_map.
 *  @param[in] i_vaddr - Virtual address of the mapped block.
 *
 *  @return int - 0 for successful unmap, non-zero otherwise.
 */
int mm_block_unmap(void* i_vaddr);

/** @fs mm_icache_invalidate()
 *  @brief Invalidate the ICACHE for the given memory
 *
 *  @param[in] i_addr - Destination address
 *  @param[in] i_cpu_word_count - number of CPU_WORDs (uint64_t)
 */
void mm_icache_invalidate(void * i_addr, size_t i_cpu_word_count);

/** @fn mm_virt_to_phys()
 *  @brief System call to return the physical address backing a
 *      virtual address
 *
 *  @param[in] i_vaddr - Virtual address to translate
 *
 *  @return uint64_t - -EFAULT if there is no associated address,
 *      physical address otherwise
 */
uint64_t mm_virt_to_phys( void* i_vaddr );

/** @fn mm_tolerate_ue
 *  @brief Allows a task to tolerate a memory UE without being killed.
 *
 *  This should be used when copying content from memory of unknown quality,
 *  such as during a memory preserved IPL.  When a memory UE is consumed by
 *  the task, instead of killing the task, the kernel will replace the
 *  memory access by a special value of '0xdeadd47a'.
 *
 *  @param[in] i_state - Should the task tolerate memory UEs: 0 = no, 1 = yes.
 *
 *  Example usage:
 *      mm_tolerate_ue(1);
 *      memcpy(src, dest, size);
 *      mm_tolerate_ue(0);
 */
void mm_tolerate_ue(uint64_t i_state);
/** Value inserted into process when it encounters a UE, if mm_tolerate_ue is
 *  enabled. */
enum { MM_UE_MAGIC_VALUE = 0xdeadd47adeadd47aull };

#ifdef __cplusplus
}
#endif

#endif
