/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/lib/stdlib.C $                                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2010,2023                        */
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
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <kernel/heapmgr.H>
#include <kernel/pagemgr.H>
#include <kernel/vmmmgr.H>
#include <kernel/console.H>
#include <kernel/misc.H>
#include <usr/vmmconst.h>
#include <assert.h>
#include <errno.h>

#ifdef HOSTBOOT_MEMORY_LEAKS
#include <arch/ppc.H>

/** Memory allocation function type
 *
 *  These are used as parameters to the magic instruction so that the debug
 *  tools can determine what memory allocation function was being called.
 */
enum MemoryLeak_FunctionType
{
    MEMORYLEAK_MALLOC = 0,
    MEMORYLEAK_REALLOC = 1,
    MEMORYLEAK_FREE = 2
};

/** @fn memoryleak_magic_instruction
 *  @brief Triggers the simics memoryleak analysis magic hap-handler.
 *
 *  Arranges the memory allocation parameters into registers according to the
 *  Power ABI and triggers the magic instruction.  The ABI puts parameter 0-3
 *  into registers r3-r6.
 *
 *  Function attribute of "noinline" is required to ensure that the compiler
 *  treats this as a real function instead of attempting to inline it.  If it
 *  were to inline it then the parameters wouldn't end up in the right register.
 */
static void memoryleak_magic_instruction(MemoryLeak_FunctionType func,
                                         size_t size,
                                         void* ptr,
                                         void* ptr2) __attribute__((noinline));

static void memoryleak_magic_instruction(MemoryLeak_FunctionType func,
                                         size_t size,
                                         void* ptr,
                                         void* ptr2)
{
    // Newer GCC seems to optimize out the parameter placement unless we
    // fake them going into an assembly instruction.
    asm volatile("" :: "r"(func), "r"(size), "r"(ptr), "r"(ptr2));

    MAGIC_INSTRUCTION(MAGIC_MEMORYLEAK_FUNCTION);
    return;
}
#endif

#ifdef MEM_ALLOC_PROFILE
// alloc profile
uint16_t g_0 = 0;
uint16_t g_8 = 0;
uint16_t g_16 = 0;
uint16_t g_32 = 0;
uint16_t g_64 = 0;
uint16_t g_128 = 0;
uint16_t g_256 = 0;
uint16_t g_512 = 0;
uint16_t g_1k = 0;
uint16_t g_2k = 0;
uint16_t g_big = 0;
#endif


#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief Metadata structure for malloc heap allocations
 */
struct block{
  int32_t is_free;      /* Set to 0x1231 to mean "free" or "0x1230" to
                         * mean "occupied." */
  uint32_t size;        /* size of associated allocation*/
  block *next;          /* pointer to next allocation block*/
  block *prev;          /* pointer to prev allocation block*/
};

#define BLOCK_IS_FREE 0x1231
#define BLOCK_IS_OCCUPIED 0x1230

// The size of allocation metadata.
#define METASIZE sizeof(block)

 /**
  * @brief prints memory stats for discontiguous malloc heap for debugging
  */
void mallocDebug();

mutex_t malloc_mutex = MUTEX_INITIALIZER;


void *g_heap_start = reinterpret_cast<void*>(VMM_VADDR_MALLOC_VIRT);  /* pointer to beginning of discontiguous malloc heap*/
void *g_heap_currPos = g_heap_start;                                    /* points to begininng of next free block in discontiguous malloc heap */
void *g_heap_prevBlock = NULL;                                        /* points to previous allocation in discontiguous malloc heap for setting up list */
void* (*g_active_alloc)(size_t) = &contiguous_malloc;                   /* function pointer switches to discontiguous malloc in switch_malloc */

block* g_alloc_search = nullptr; /* Used for searching for a previously-freed block that can hold a new allocation. This variable points
                                  to the block that the previous search left off at, to make searches more efficient. */

//stats for debug
uint64_t g_num_allocated_bytes = 0;
uint64_t g_num_freed_bytes = 0;
uint64_t g_num_bytes_removed = 0;


void* malloc(size_t size)
{
    if (KernelMisc::in_kernel_mode())
    {
        return (contiguous_malloc(size));
    }

    return (g_active_alloc(size));
}

void mallocDebug()
{
    printk("currPos in malloc %p\n", g_heap_currPos);
    printk("pages available before free %ld\n",PageManager::availPages());

    for (auto i = static_cast<block*>(g_heap_start); i; i = i->next)
    {
        // A means "allocation"
        printk("A %p %x %d -> %p\n", i, i->is_free, i->size, i->next);
    }
}

void activate_discontiguous_malloc_heap()
{
    // @TODO: Make this work.
    return;

    auto lock = scoped_mutex_lock(malloc_mutex);

    mm_virt_to_phys(reinterpret_cast<void*>(VMM_VADDR_MALLOC_VIRT));

    int rc = mm_alloc_block(nullptr,
                            reinterpret_cast<void*>(VMM_VADDR_MALLOC_VIRT),
                            VMM_MALLOC_VIRT_SIZE );
    if(rc != 0)
    {
        printk( "<switch_malloc> mm_alloc_block failed for %lX\n using contiguous allocator to allocate memory",
                VMM_VADDR_MALLOC_VIRT );
        return;
    }

    rc = mm_set_permission(reinterpret_cast<void*>(VMM_VADDR_MALLOC_VIRT),VMM_MALLOC_VIRT_SIZE,WRITABLE|ALLOCATE_FROM_ZERO);
    if(rc != 0)
    {
        printk( "<malloc> mm_set_permissions failed for %lX\n using contiguous allocator to allocate memory",
                VMM_VADDR_MALLOC_VIRT );
        return;
    }
    g_active_alloc = &discontiguous_malloc;
}


void deactivate_discontiguous_malloc_heap()
{
    if(g_active_alloc ==  &contiguous_malloc)
    {
        printk( "<extend_malloc_heap> failed because switch to discontiguous malloc was previously unsuccesful\n");
        return;
    }

    auto lock = scoped_mutex_lock(malloc_mutex);
    g_active_alloc = contiguous_malloc;

    return; // we are not growing the malloc heap here currently

    int rc = mm_alloc_block(nullptr,
                            reinterpret_cast<void*>(VMM_VADDR_MALLOC_VIRT + VMM_MALLOC_VIRT_SIZE),
                            VMM_MALLOC_EXTENDED_SIZE);
    if(rc != 0)
    {
        printk( "<extend_malloc_heap> mm_alloc_block failed for %lX\n",
                (VMM_VADDR_MALLOC_VIRT + VMM_MALLOC_VIRT_SIZE));
        return;
    }

    rc = mm_set_permission(reinterpret_cast<void*>(VMM_VADDR_MALLOC_VIRT + VMM_MALLOC_VIRT_SIZE),VMM_MALLOC_EXTENDED_SIZE,WRITABLE|ALLOCATE_FROM_ZERO);
    if(rc != 0)
    {
        printk( "<extend_malloc_heap> mm_set_permissions failed for %lX\n",
                (VMM_VADDR_MALLOC_VIRT + VMM_MALLOC_VIRT_SIZE));
        return;
    }
}

/** @brief Find a free block big enough to fit the given size,
 *  starting at startnode, stopping after max_steps of not finding a
 *  fit, and populating next_time_start with the node the search ended
 *  with.
 */
block* find_big_enough_block(uint32_t aligned_size,
                             block* startnode,
                             int max_steps,
                             block*& next_time_start)
{
    if (!g_heap_prevBlock)
    {
        return nullptr;
    }

    if (!startnode)
    {
        startnode = static_cast<block*>(g_heap_prevBlock);
    }

    block* i = nullptr;
    bool looped = false;

    for (i = static_cast<block*>(startnode); max_steps-- >= 0; i = static_cast<block*>(i)->prev)
    {
        if (!i)
        {
            if (looped)
            {
                break;
            }

            looped = true;
            i = static_cast<block*>(g_heap_prevBlock);
        }

        if (i->is_free == BLOCK_IS_FREE && i->size > (aligned_size + METASIZE))
        {
            auto oldsize = i->size;
            auto oldnext = i->next;

            i->is_free = BLOCK_IS_OCCUPIED;
            i->size = aligned_size;
            i->next = reinterpret_cast<block*>(reinterpret_cast<char*>(i+1) + aligned_size);

            i->next->is_free = BLOCK_IS_FREE;
            i->next->size = oldsize - aligned_size - METASIZE;
            i->next->next = oldnext;
            i->next->prev = i;

            if (i->next->next)
            {
                i->next->next->prev = i->next;
            }
            else
            {
                g_heap_prevBlock = i->next;
            }

            break;
        }
    }

    if (i)
    {
        next_time_start = i->next;
    }
    else
    {
        next_time_start = nullptr;
    }

    return nullptr;
}

void* discontiguous_malloc(size_t size)
{
    if (size <= PAGE_SIZE || size >= 32*PAGESIZE)
    { // Don't use the discontiguous allocator for things less than a
      // page size (discontiguous pages don't help much in that case)
      // or for greater than 32 pages (we want a separate allocated
      // region for those, don't waste our heap space).
        return contiguous_malloc(size);
    }

    auto lock = scoped_mutex_lock(malloc_mutex);

    uint32_t aligned_size = ALIGN_8(size);
    if(g_heap_currPos == g_heap_start)
    {
        //g_heap_prevBlock = NULL;
    }

    block *prev_block = static_cast<block*>(g_heap_prevBlock);
    block *new_block = static_cast<block*>(g_heap_currPos);

    if ((uint64_t)new_block + METASIZE + aligned_size > VMM_VADDR_MALLOC_VIRT + VMM_MALLOC_VIRT_SIZE)
    {
        // TODO: call contiguous malloc here
        printk("Discontiguous malloc region is full!\n");
        crit_assert(false);
    }

    if (aligned_size <= 0)
    {
        return NULL;
    }

    g_num_allocated_bytes += aligned_size;

    /*
    if (auto reused_block = find_big_enough_block(aligned_size, g_alloc_search, 8, g_alloc_search))
    {
        return reused_block + 1;
    }

    block* recent_reused_block = nullptr;
    if (auto reused_block = find_big_enough_block(aligned_size, static_cast<block*>(g_heap_prevBlock), 8, recent_reused_block))
    {
        if (recent_reused_block && recent_reused_block->size > g_alloc_search->size)
        {
            g_alloc_search = recent_reused_block;
        }
        return reused_block + 1;
    }
    */

    //allocate at new block
    new_block->is_free = BLOCK_IS_OCCUPIED;
    new_block->size = aligned_size;
    new_block->next = NULL;
    new_block->prev = prev_block;

    if(new_block->prev)
    {
        prev_block->next = new_block;
    }

    g_heap_currPos = static_cast<void*>(static_cast<char*>(g_heap_currPos) + (aligned_size + METASIZE));
    g_heap_prevBlock = new_block;

    //return pointer to new block
    return (new_block + 1);
}

void discontiguous_free(void *ptr)
{
    if(!ptr)
    {
        return;
    }

    auto lock = scoped_mutex_lock(malloc_mutex);

    block *meta_data = static_cast<block*>(ptr) - 1;

    if (meta_data->is_free != BLOCK_IS_OCCUPIED)
    {
        printk("meta_data->is_free != BLOCK_IS_OCCUPIED %p 0x%x",
               meta_data, meta_data->is_free);
        crit_assert(false);
    }

    const auto freed_size = meta_data->size;

    //update stats for debug
    g_num_freed_bytes += freed_size;

    meta_data->is_free = BLOCK_IS_FREE;

    block *next = meta_data->next;
    block *prev = meta_data->prev;

    //check if next block is free and combine
    if((next) && (next->is_free == BLOCK_IS_FREE))
    {
        if (!((void*)meta_data->next == (void*)(meta_data->size + METASIZE + (char*)meta_data)))
        {
            printk("Discontiguous heap block 'next' pointer doesn't point to the end of block: %p 0x%08X %p ; %p 0x%08X %p ; %p 0x%08X %p\n",
                   meta_data, meta_data->size, meta_data->next,
                   prev, prev ? prev->size : 0, prev ? prev->next : nullptr,
                   next, next->size, next->next);

            crit_assert(false);
        }

        meta_data->size = meta_data->size + METASIZE + next->size;
        meta_data->next = next->next;
        if(next->next)
        {
            next->next->prev = meta_data;
        }
    }

    next = meta_data->next;


    //check if prev block is free and update
    if((prev) && (prev->is_free == BLOCK_IS_FREE))
    {
        if (!((void*)meta_data == (void*)(prev->size + METASIZE + (char*)prev)))
        {
            printk("IS BAD: %p 0x%08X %p ; %p 0x%08X %p ; %p 0x%08X %p\n",
                   meta_data, meta_data->size, meta_data->next,
                   prev, prev->size, prev->next,
                   next, next ? next->size : 0, next ? next->next : nullptr);

            crit_assert(false);
        }

        prev->size = prev->size + METASIZE + meta_data->size;
        prev->next = next;
        meta_data = prev;
        if(next)
        {
            next->prev = meta_data;
        }
    }

    prev = meta_data->prev;

    if(!next)
    {
        g_heap_prevBlock = meta_data;
    }
    if(!prev)
    {
        g_heap_start = meta_data;
    }

    uint64_t pgUp = ALIGN_PAGE((uint64_t)meta_data + METASIZE);
    uint64_t pgDown = ALIGN_PAGE_DOWN((uint64_t)((char*)meta_data + METASIZE + meta_data->size));

    int rc = 0;

    //free page if free block occupies a >= PAGESIZE
    if(pgUp < pgDown)
    {
        /*
        if(!next && !prev)
        {
          g_heap_prevBlock = NULL;
          g_heap_start = g_heap_currPos;
        }
        if(prev)
        {
            prev->next = next;
        }
        else if (!prev && next)
        {
            if(!(next->next))
            {
                //g_heap_prevBlock = next;
            }
            g_heap_start = next;
        }

        if(next)
        {
            next->prev = prev;
        }
        else if(!next)
        {
            g_heap_prevBlock  = prev;
        }
        */

        // Set permissions before removing pages, so that a concurrent
        // memory access doesn't re-page anything in between the two
        // calls.
        rc = mm_set_permission((void*)pgUp, (pgDown-pgUp), NO_ACCESS);

        if(rc != 0)
        {
            printk( "new_free> mm_set_permission failed for ptr=%p (size=%ld)\n", (void*)pgUp, (pgDown-pgUp));
            crit_assert(0);
            return;
        }

        /* If we're freeing the block that contains g_alloc_search,
           update it to point to a valid block nearby, so that it's
           not dangling. */
        if (!g_alloc_search
            || ((char*)g_alloc_search >= (char*)meta_data
                && (char*)g_alloc_search < (char*)meta_data + METASIZE + meta_data->size)
            || g_alloc_search->size < meta_data->size)
        {
            g_alloc_search = meta_data;
        }

        for (auto init = pgUp; init < pgDown; init += PAGE_SIZE)
        {
            if (-mm_virt_to_phys((void*)init) != EFAULT)
            {
                g_num_bytes_removed += PAGE_SIZE;
            }
        }

        const auto END_FIRST_VMM_REGION = VMM_VADDR_MALLOC_VIRT + VMM_MALLOC_VIRT_SIZE;

        if (pgUp < END_FIRST_VMM_REGION
            && pgDown > END_FIRST_VMM_REGION)
        {
            rc = mm_remove_pages(RELEASE,
                                 (void*)pgUp,
                                 END_FIRST_VMM_REGION - pgUp);

            if(rc != 0)
            {
                printk( "new_free> mm_remove_pages 1 failed for ptr=%p (size=%ld)\n", (void*)pgUp, (pgDown-pgUp));
                crit_assert(0);
                return;
            }

            rc = mm_remove_pages(RELEASE,
                                 (void*)END_FIRST_VMM_REGION,
                                 pgDown - END_FIRST_VMM_REGION);

            if(rc != 0)
            {
                printk( "new_free> mm_remove_pages 2 failed for ptr=%p (size=%ld)\n", (void*)pgUp, (pgDown-pgUp));
                crit_assert(0);
                return;
            }
        }
        else
        {
            rc = mm_remove_pages(RELEASE, (void*)pgUp, (pgDown-pgUp));

            if(rc != 0)
            {
                printk( "new_free> mm_remove_pages 3 failed for ptr=%p (size=%ld)\n", (void*)pgUp, (pgDown-pgUp));
                crit_assert(0);
                return;
            }
        }
    }
    else
    {
        /*
        if (!g_alloc_search
            || ((char*)g_alloc_search >= (char*)meta_data
                && (char*)g_alloc_search < (char*)meta_data + METASIZE + meta_data->size))
        {
            g_alloc_search = meta_data;
        }
        */
    }

    g_alloc_search = nullptr;
}

extern "C"
void* contiguous_malloc(size_t s)
{
#ifdef MEM_ALLOC_PROFILE
    if(s == 0) ++g_0;
    else if (s <= 8) ++g_8;
    else if (s <= 16) ++g_16;
    else if (s <= 32) ++g_32;
    else if (s <= 64) ++g_64;
    else if (s <= 128) ++g_128;
    else if (s <= 256) ++g_256;
    else if (s <= 512) ++g_512;
    else if (s <= 1024) ++g_1k;
    else if (s <= 2048) ++g_2k;
    else ++g_big;
#endif
    void* result = HeapManager::allocate(s);

#ifdef HOSTBOOT_MEMORY_LEAKS
    memoryleak_magic_instruction(MEMORYLEAK_MALLOC, s, result, NULL);
#endif

    return result;
}

void contiguous_free(void* p)
{
    if (nullptr == p)
    {
        return;
    }

#ifdef HOSTBOOT_MEMORY_LEAKS
    memoryleak_magic_instruction(MEMORYLEAK_FREE, 0, p, NULL);
#endif

    HeapManager::free(p);
}

void free(void* p)
{
    //frees block from discontiguous allocation if present in discontiguous malloc heap
    if(((uint64_t)p >= VMM_VADDR_MALLOC_VIRT)
       && ((uint64_t)p < (VMM_VADDR_MALLOC_VIRT + VMM_MALLOC_VIRT_SIZE + VMM_MALLOC_EXTENDED_SIZE)))
    {
        discontiguous_free(p);
    }

    //else frees allocation from contiguous malloc heap
    else{
        contiguous_free(p);
    }
}

void* realloc(void* p, size_t s)
{
    void* result;
    if (nullptr == p)
    {
        return malloc(s);
    }

    // reallocates in discontiguous heap if original allocation lives
    // within discontiguous heap
    if (((uint64_t)p >= VMM_VADDR_MALLOC_VIRT)
        && ((uint64_t)p < (VMM_VADDR_MALLOC_VIRT + VMM_MALLOC_VIRT_SIZE + VMM_MALLOC_EXTENDED_SIZE)))
    {
        block* src = static_cast<block*>(p) - 1;
        result = discontiguous_malloc(s);
        memcpy(result,p,std::min((size_t)src->size,(size_t)s));
        free(p);
    }
    //else reallocates memory in contiguous heap
    else
    {
        result = HeapManager::realloc(p,s);
    }

#ifdef HOSTBOOT_MEMORY_LEAKS
    memoryleak_magic_instruction(MEMORYLEAK_REALLOC, s, result, p);
#endif

    return result;
}

void* calloc(size_t num, size_t size)
{
    // Allocate a block of memory for an array of 'num' elements, each of them
    // 'size' bytes long and initialize to zero
    size_t total_size = num * size;
    void* mem = NULL;

    if (total_size)
    {
        mem = malloc(total_size);
        memset(mem, 0, total_size);
    }

    return mem;
}

/**
 * Note: strtoul is also defined in runtime/rt_stdlib.C,
 *       any changes to this function should be mirrored there
 */
uint64_t strtoul(const char *nptr, char **endptr, int base)
{
    uint64_t l_data = 0;
    size_t i = 0;

    crit_assert((base == 10) || (base == 16));

    do
    {
        // Decimal
        if (base == 10)
        {
            while (nptr[i] != '\0')
            {
                // not dec then stop
                if (!isdigit(nptr[i]))
                {
                    break;
                }

                if (i > 0)
                {
                    l_data *= base;
                }

                l_data += nptr[i] - '0';

                i++;
            }
        } // base == 10

        // Hexadecimal
        else if (base == 16)
        {
            // handle the 'x' or '0x' first
            if ( (nptr[i] == 'x') ||
                 (nptr[i] == 'X') )
            {
                i++;
            }
            else if ( (nptr[i] == '0') &&
                    ( (nptr[i+1] == 'x') ||
                      (nptr[i+1] == 'X') ) )
            {
                i+=2;
            }

            while( nptr[i] != '\0' )
            {
                // not hex then stop
                if (!isxdigit(nptr[i]))
                {
                    break;
                }

                uint64_t l_nib = 0;
                switch(nptr[i])
                {
                    case('0'): l_nib = 0; break;
                    case('1'): l_nib = 1; break;
                    case('2'): l_nib = 2; break;
                    case('3'): l_nib = 3; break;
                    case('4'): l_nib = 4; break;
                    case('5'): l_nib = 5; break;
                    case('6'): l_nib = 6; break;
                    case('7'): l_nib = 7; break;
                    case('8'): l_nib = 8; break;
                    case('9'): l_nib = 9; break;
                    case('A'): case('a'): l_nib = 0xA; break;
                    case('B'): case('b'): l_nib = 0xB; break;
                    case('C'): case('c'): l_nib = 0xC; break;
                    case('D'): case('d'): l_nib = 0xD; break;
                    case('E'): case('e'): l_nib = 0xE; break;
                    case('F'): case('f'): l_nib = 0xF; break;
                    default: break; // should never get here
                }

                l_data <<= 4;
                l_data |= l_nib;

                i++;
            }
        } // base == 16
    } while(0);

    if (endptr != nullptr)
    {
        *endptr = const_cast<char*>(nptr) + i;
    }

    return l_data;
}


/**
 * @brief Returns the absolute value of parameter n ( /n/ )
 * See C spec for details
 */
int abs(int n)
{
    return( (n < 0) ? -n : n );
}

#ifdef __cplusplus
};
#endif
