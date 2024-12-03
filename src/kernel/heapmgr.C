/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/heapmgr.C $                                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2010,2024                        */
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
#include <sys/task.h>
#include <kernel/heapmgr.H>
#include <util/singleton.H>
#include <kernel/console.H>
#include <kernel/pagemgr.H>
#include <util/align.H>
#include <arch/ppc.H>
#include <usr/debugpointers.H>
#include <arch/magic.H>
#include <usr/vmmconst.h>
#include <kernel/misc.H>
#include <kernel/simpletrace.H>
#include <stdlib.h>

extern int g_istep;   // used in STRC_KMEM
extern int g_substep; // used in STRC_KMEM

#ifdef HOSTBOOT_DEBUG
#define SMALL_HEAP_PAGES_TRACKED 64

// track pages allocated to smallheap
void * g_smallHeapPages[SMALL_HEAP_PAGES_TRACKED];
#endif

/* @brief From the user data pointer, get the addr of the chunk_t struct
 */
#define chunk_ptr(_p) \
    (reinterpret_cast<chunk_t*>(reinterpret_cast<uint8_t*>(_p) - CHUNK_HDR_SZ))

/* @brief From the chunk_t pointer, get the addr of the user data
 */
#define chunk_data_ptr(_p) \
    (reinterpret_cast<chunk_t*>(reinterpret_cast<uint8_t*>(_p) + CHUNK_HDR_SZ))

/* @brief From the pointer of the chunk_t struct, get the addr of the last byte,
 *        which is a check byte set to ascii V
 */
#define chunk_V_ptr(_p,_s) (reinterpret_cast<uint8_t*>(_p) + _s - 1)

/* @brief Sizes in bytes for each bucket
 */

void HeapManager::init()
{
    Singleton<HeapManager>::instance();
}

void HeapManager::addDebugPointers()
{
    Singleton<HeapManager>::instance()._addDebugPointers();
}

#ifdef CONFIG_MALLOC_FENCING

/**
 *  @brief Types of check bytes used by small malloc fencing
 */
enum CHECK : uint32_t
{
    BEGIN = 0xBBBBBBBB,
    END   = 0xEEEEEEEE,
};

/**
 *  @brief Small alloc fencing structure.  For every small malloc, this
 *     structure is placed at the beginning of the allocation and written with
 *     check bytes and size information.  Check bytes are also placed at the
 *     end. On a free, if the check bytes are invalid, Hostboot raises a
 *     critical assert.
 */
struct fence_t
{
    CHECK begin;   // Beginning check byte
    uint32_t size; // Size of user's original allocation
    uint64_t pad;  // Unused pad bytes
    char data[];   // Offset of start of actual user data

} PACKED;

/**
 *  @brief Applies fencing check bytes to an allocation
 *
 *  @param[in] i_pAddr Address of the allocation returned by the heap manager
 *  @param[in] i_size  Size of the allocation as requested by the user
 *
 *  @retval void* Pointer giving the effective address for the user's allocation
 *     request (after the fencing)
 */
void* _applySmallFence(void* const i_pAddr,const size_t i_size)
{
    fence_t* const pFence=reinterpret_cast<fence_t*>(i_pAddr);
    pFence->begin=CHECK::BEGIN;
    pFence->size=static_cast<decltype(pFence->size)>(i_size);
    char* const end=(reinterpret_cast<char*>(&pFence->data[0])+i_size);
    const auto endVal=CHECK::END;
    memcpy(end,&endVal,sizeof(CHECK::END));
    return &pFence->data[0];
}

/**
 *  @brief Add/subtract value from a void*
 *
 *  @param[in] i_pAddr Original address
 *  @param[in] i_size  Amount to increment the address by
 *
 *  @return void* The original pointer, adjusted by the requested amount
 */
inline void* addToVoid(void* const i_pAddr,const ssize_t i_size)
{
    return
        reinterpret_cast<void*>(
            reinterpret_cast<char*>(i_pAddr) + i_size);
}

/**
 *  @brief Enforces fencing on an allocation.  On fence violation, the routine
 *      invokes a critical assert
 *
 *  @param[in] i_pAddr Effective user address (not original allocation from heap
 *      manager)
 *  @param[out] o_userSize Size of caller's original requested allocation
 *
 *  @return void* Indicating the start of the original heap manager allocation
 *
 */
void* _enforceSmallFence(
    void*   const i_pAddr,
    size_t&       o_userSize)
{
    void* pOrigAddr = addToVoid(i_pAddr,-offsetof(fence_t,data));
    auto * const pFence=reinterpret_cast<fence_t*>(pOrigAddr);
    if( pFence->begin != CHECK::BEGIN )
    {
        KTRC0("i=%p,o=%p\n",i_pAddr,pOrigAddr);
        crit_assert(pFence->begin == CHECK::BEGIN);
    }
    uint32_t endVal=0;
    memcpy(&endVal,&pFence->data[0]+pFence->size,sizeof(endVal));
    crit_assert(endVal==CHECK::END);
    o_userSize=pFence->size;
    return pOrigAddr;
}

/**
 *  @brief Returned whether the allocation at the given address is considered a
 *      small allocation or not.  All non-small allocations are page aligned.
 *
 *  @param[in] i_pAddr Requested address to check for allocation size
 *
 *  @return bool indicating whether the allocation was small or not
 */
inline bool isSmallAlloc(const void* const i_pAddr)
{
    return (ALIGN_PAGE(reinterpret_cast<uint64_t>(i_pAddr)) !=
       reinterpret_cast<uint64_t>(i_pAddr));
}

// For every big malloc, which always results in an integral number of pages
// allocated, create a fence page before and after the effective memory range
// given back to the user.
const size_t  BIG_MALLOC_EXTRA_PAGES=2;

// Sentinel value used to fill up the fence page preceding the effective memory
// range given back to the user.
const uint8_t BEGIN_CHECK_BYTE=0xBB;

// Sentinel value used to fill up the memory from the end of the effective
// memory range given back to the user, through the end of the final fence page.
const uint8_t END_CHECK_BYTE=0xEE;

/**
 *  @brief Applies fencing bytes before and after a big memory allocation
 *
 *  @param[in] i_pAddr Starting address of the allocation, as given by
 *      _allocateBig
 *
 *  @param[in] i_size Size of caller's actual requested allocation (smaller than
 *      what _allocateBig allocated)
 *
 *  @return void* Pointer to effective memory address for caller to use
 */
void* _applyBigFence(void* const i_pAddr, const size_t i_size)
{
    auto pCursor=reinterpret_cast<char*>(i_pAddr);
    const auto beginCheckBytes=PAGESIZE-sizeof(i_size);
    memset(pCursor,BEGIN_CHECK_BYTE,beginCheckBytes);
    pCursor+=beginCheckBytes;
    memcpy(pCursor,&i_size,sizeof(i_size));
    pCursor+=sizeof(i_size);
    void* pEffAddr=pCursor;
    pCursor+=i_size;
    const auto endCheckBytes=
        ALIGN_PAGE(i_size)-i_size+PAGESIZE;
    memset(pCursor,END_CHECK_BYTE,endCheckBytes);
    return pEffAddr;
}

/**
 *  @brief Enforce that fence bytes from prior mallocs have not been disturbed
 *
 *  @param[in] i_pAddr Effective address of the original user allocation (one
 *      page after the actual allocation from _allocateBig or _reallocBig)
 *
 *  @return void* Pointer to actual memory address of the original allocation
 *      from _allocateBig or _reallocBig
 */
void* _enforceBigFence(void* const i_pAddr)
{
    auto pCursor=reinterpret_cast<char*>(i_pAddr);
    pCursor-=PAGESIZE;
    void* const pActAddr = pCursor;
    size_t origSize=0;
    const auto beginCheckBytes=PAGESIZE-sizeof(origSize);
    for(size_t i=0;i<beginCheckBytes;++i)
    {
        if(*(pCursor++) != BEGIN_CHECK_BYTE)
        {
            crit_assert(0);
        }
    }
    memcpy(&origSize,pCursor,sizeof(origSize));
    pCursor+=sizeof(origSize)+origSize;
    const size_t endCheckBytes=ALIGN_PAGE(origSize)-origSize+PAGESIZE;
    for(size_t i=0;i<endCheckBytes;++i)
    {
        if(*(pCursor++) != END_CHECK_BYTE)
        {
            crit_assert(0);
        }
    }
    return pActAddr;
}

#endif // End CONFIG_MALLOC_FENCING

void * HeapManager::allocate(size_t i_sz)
{
    HeapManager &hmgr = Singleton<HeapManager>::instance();
    size_t       overhead = 0;
    void        *ptr{nullptr};

#ifdef CONFIG_MALLOC_FENCING
    overhead = offsetof(fence_t,data) + sizeof(CHECK::END);
#endif
    // do not want huge allocations when in kernel mode (huge
    // allocations use mm_alloc_block); kernel memory accesses don't
    // go through page translation.
    if( (i_sz + overhead > MAX_BIG_ALLOC_SIZE)
        && (i_sz + overhead <= HC_SLOT_SIZE)
        && !(KernelMisc::in_kernel_mode()))
    {
        KTRC1("allocateHuge=%ld [%d]\n", i_sz, task_gettid());
        ptr = hmgr._allocateHuge(i_sz);
        if( ptr )
        {
            return ptr;
        }
        else
        {
            // default to using regular allocations if huge doesn't work
            ptr = hmgr._allocateBig(i_sz);
            if (unlikely(!ptr))
            {
                KTRC0("Insufficient memory for _allocateBig sz:%ld\n", i_sz);
                KTRC0("KMEM_STATS_ALLOC_BIG_KASSERT_1\n");
                STRC1_KMEM(KMEM_STATS_ALLOC_BIG_KASSERT_1, g_istep, g_substep, i_sz);
                crit_assert(ptr);
            }
            return ptr;
        }
    }
    else if(i_sz + overhead > MAX_SMALL_ALLOC_SIZE)
    {
        ptr = hmgr._allocateBig(i_sz);
        if (unlikely(!ptr))
        {
            KTRC0("Insufficient memory for _allocateBig sz:%ld\n", i_sz);
            KTRC0("KMEM_STATS_ALLOC_BIG_KASSERT_2\n");
            STRC1_KMEM(KMEM_STATS_ALLOC_BIG_KASSERT_2, g_istep, g_substep, i_sz);
            crit_assert(ptr);
        }
        return ptr;
    }

    ptr = hmgr._allocate(i_sz + overhead);

#ifdef CONFIG_MALLOC_FENCING
    ptr = _applySmallFence(ptr,i_sz);
#endif

    STRC1_KSHORT(KDBG_HM_ALLOC, PTR_TO_u32(chunk_ptr(ptr)), i_sz);

    crit_assert(ptr);

    return ptr;
}

void HeapManager::free(void * i_ptr)
{
    HeapManager& hmgr = Singleton<HeapManager>::instance();
    return hmgr._free(i_ptr);
}

void* HeapManager::realloc(void* i_ptr, size_t i_sz)
{
    return Singleton<HeapManager>::instance()._realloc(i_ptr,i_sz);
}

void HeapManager::coalesce( void )
{
    if (KernelMisc::in_kernel_mode())
    {
        Singleton<HeapManager>::instance()._coalesce();
        return;
    }
    // else, noop
}

void* HeapManager::_allocate(size_t i_sz)
{
    // 8 bytes book keeping, 1 byte validation
    size_t which_bucket = bucketIndex(i_sz + CHUNK_HEADER_PLUS_RESERVED);

    chunk_t* chunk = static_cast<chunk_t*>(nullptr);
    chunk = pop_bucket(which_bucket);
    if (nullptr == chunk)
    {
        newPage();
        return _allocate(i_sz);
    }
    else
    {
        size_t alloc = bucketByteSize(chunk->bucket);
        __sync_add_and_fetch(&cv_smallheap_allocated,alloc);
        __sync_add_and_fetch(&cv_smallheap_user_allocated,i_sz);
        __sync_add_and_fetch(&cv_inuse_bucket_counts[chunk->bucket],1);
        __sync_add_and_fetch(&cv_alloc_sizes[which_bucket],1);

        if (cv_smallheap_allocated > cv_smallheap_alloc_hw)
            cv_smallheap_alloc_hw = cv_smallheap_allocated;
        // test_pages();

        if (unlikely(chunk->free != 'F'))
        {
            STRC1_KSHORT(KDBG_HM_ALLOC_ASSERT_NOT_F, PTR_TO_u32(chunk), chunk->free);
            KTRC0("chunk->free is not F in HeapManager::_allocate\n");
            crit_assert(chunk->free == 'F');
        }

        // Use the size of this chunk get to the end.
        size_t size = bucketByteSize(chunk->bucket);

        // set the last byte of the chunk to 'V' => valid
        *(chunk_V_ptr(chunk, size)) = 'V';

        // mark chunk as allocated
        chunk->free = 'A';
        chunk->size = i_sz;
        chunk->allocator = task_gettid();

        return &chunk->next;
    }
}

void* HeapManager::_realloc(void* i_ptr, size_t i_sz)
{
    if (unlikely(!i_ptr || ! i_sz))
    {
        STRC1_KSHORT(KDBG_HM_REALLOC, PTR_TO_u32(i_ptr), i_sz);
        KTRC0("bad parms in HeapManager::_realloc i_ptr:%p i_sz:%ld\n", i_ptr,i_sz);
        crit_assert(i_ptr);
        crit_assert(i_sz);
    }

    // do some range checks
    //
    // Logic for all these are conditional on falling thru
    // from largest to smallest
    if (reinterpret_cast<uint64_t>(i_ptr) >= VMM_VADDR_MALLOC)
    {
        void* new_ptr = _reallocHuge(i_ptr,i_sz);
        crit_assert(new_ptr);
        return new_ptr;
    }

    void* new_ptr = _reallocBig(i_ptr,i_sz);
    if (new_ptr) return new_ptr;

    size_t overhead = 0;
    new_ptr = i_ptr;

#ifdef CONFIG_MALLOC_FENCING
    overhead = offsetof(fence_t,data) + sizeof(CHECK::END);
    size_t userSize=0;
    new_ptr = _enforceSmallFence(i_ptr,userSize);
#endif

    chunk_t* chunk = chunk_ptr(new_ptr);

    if (unlikely(chunk->free != 'A'))
    {
        STRC1_KSHORT(KDBG_HM_FREE_ASSERT_NOT_A, PTR_TO_u32(chunk), chunk->free);
        KTRC0("chunk->free is not A in HeapManager::_realloc\n");
        crit_assert(chunk->free == 'A');
    }

    // take into account the 8 byte header and valid byte
    size_t asize = bucketByteSize(chunk->bucket) - CHUNK_HEADER_PLUS_RESERVED;
    if(asize < i_sz + overhead) // i_ptr is too small, so get a new chunk
    {
        // fyi.. MAX_SMALL_ALLOCATION_SIZE = BUCKET11 - 9 bytes
        new_ptr = (i_sz + overhead > MAX_SMALL_ALLOC_SIZE) ?
            _allocateBig(i_sz) : _allocate(i_sz + overhead);

#ifdef CONFIG_MALLOC_FENCING
        if(!isSmallAlloc(new_ptr))
        {
            memcpy(new_ptr,i_ptr,userSize);
        }
        else
        {
            memcpy(addToVoid(new_ptr,offsetof(fence_t,data)),
                i_ptr,userSize);
        }
#else
        memcpy(new_ptr, i_ptr, asize);
#endif
        _free(i_ptr);
    }

#ifdef CONFIG_MALLOC_FENCING
    if(isSmallAlloc(new_ptr))
    {
        new_ptr = _applySmallFence(new_ptr,i_sz);
    }
#endif

    if (unlikely(new_ptr == nullptr))
    {
        KTRC0("new_ptr == nullptr in HeapManager::_realloc\n");
        crit_assert(0);
    }

    STRC1_KSHORT(KDBG_HM_REALLOC, PTR_TO_u32(chunk_ptr(i_ptr)),
                                  PTR_TO_u32(chunk_ptr(new_ptr)));
    return new_ptr;
}

void* HeapManager::_reallocBig(void* i_ptr, size_t i_sz)
{
    // Currently all large allocations fall on a page boundary,
    // but small allocatoins never do
    if(ALIGN_PAGE(reinterpret_cast<uint64_t>(i_ptr)) !=
       reinterpret_cast<uint64_t>(i_ptr))
    {
        KTRC4("_reallocBig: small heap i_ptr:%p\n", i_ptr);
        return nullptr;
    }

#ifdef CONFIG_MALLOC_FENCING
    i_ptr=_enforceBigFence(i_ptr);
#endif

    void* new_ptr = nullptr;
    big_chunk_t * bc = big_chunk_stack.first();
    while(bc)
    {
       if(bc->addr == i_ptr)
       {
           size_t new_size = ALIGN_PAGE(i_sz)/PAGESIZE;

#ifdef CONFIG_MALLOC_FENCING
           new_size+=BIG_MALLOC_EXTRA_PAGES;
#endif

           STRC1_KSHORT(KDBG_HM_REALLOC_BIG, PTR_TO_u32(i_ptr), bc->page_count);

           crit_assert(bc->page_count);

           if(new_size > bc->page_count)
           {
               __sync_add_and_fetch(&cv_largeheap_page_count,new_size-bc->page_count);
               if(cv_largeheap_page_max < cv_largeheap_page_count)
                   cv_largeheap_page_max = cv_largeheap_page_count;

               new_ptr = PageManager::allocatePage(new_size);

               memcpy(new_ptr,i_ptr,bc->page_count*PAGESIZE);

               size_t page_count = bc->page_count;
               bc->addr = new_ptr;
               bc->page_count = new_size;
               lwsync();

               PageManager::freePage(i_ptr,page_count);
           }
           new_ptr = bc->addr;

           break;
       }
       bc = (big_chunk_t*) (((uint64_t)bc->next) & 0x00000000FFFFFFFF);
   }

#ifdef CONFIG_MALLOC_FENCING
    new_ptr=_applyBigFence(new_ptr,i_sz);
#endif

    STRC1_KSHORT(KDBG_HM_REALLOC_BIG, PTR_TO_u32(i_ptr), PTR_TO_u32(new_ptr));

    crit_assert(new_ptr);

    return new_ptr;
}

void HeapManager::_free(void * i_ptr)
{
    crit_assert(i_ptr);

    if(!_freeHuge(i_ptr) && !_freeBig(i_ptr))
    {
#ifdef CONFIG_MALLOC_FENCING
        size_t userSize=0;
        i_ptr = _enforceSmallFence(i_ptr,userSize);
#endif

        chunk_t* chunk = chunk_ptr(i_ptr);

        __sync_sub_and_fetch(&cv_smallheap_allocated,bucketByteSize(chunk->bucket));
        __sync_sub_and_fetch(&cv_smallheap_user_allocated, chunk->size);
        __sync_sub_and_fetch(&cv_inuse_bucket_counts[chunk->bucket],1);

        STRC1_KSHORT(KDBG_HM_FREE, PTR_TO_u32(chunk), chunk->size);

        if (unlikely(chunk->free != 'A'))
        {
            STRC1_KSHORT(KDBG_HM_FREE_ASSERT_NOT_A, PTR_TO_u32(chunk), chunk->free);
            KTRC0("chunk->free is not A in HeapManager::_free\n");
            crit_assert(chunk->free == 'A');
        }

        // Use the size of this chunk to find next chunk.
        size_t size = bucketByteSize(chunk->bucket);

        // make sure the next block is still valid
        if (unlikely(*(chunk_V_ptr(chunk, size)) != 'V'))
        {
            STRC1_KSHORT(KDBG_HM_FREE_CRASH_NOT_V, PTR_TO_u32(chunk),
                                                   *(chunk_V_ptr(chunk, size)));
            MAGIC_INSTRUCTION(MAGIC_BREAK_ON_ERROR);
            // force a storage exception
            task_crash();
        }

        push_bucket(chunk, chunk->bucket);
    }
}


HeapManager::chunk_t* HeapManager::pop_bucket(size_t i_bucket)
{
    if (i_bucket >= BUCKETS) return nullptr;

    chunk_t* c = first_chunk[i_bucket].pop();

    if (nullptr == c)
    {
        // Couldn't allocate from the correct size bucket, so split up an
        // item from the next sized bucket.
        c = pop_bucket(i_bucket+1);
        if (nullptr != c)
        {
            size_t c_size = bucketByteSize(i_bucket);
            size_t c1_size = bucketByteSize(c->bucket) - c_size;
            size_t c1_bucket = bucketIndex(c1_size);

            chunk_t* c1 = reinterpret_cast<chunk_t*>(((uint8_t*)c) + c_size);
            c1->bucket = c1_bucket;
            c->bucket = i_bucket;

            // c1_size should always be a valid size unless the FIB sequence is modified
            // then we could end up with an 8 byte piece of junk.
            if(c1_size >= MIN_BUCKET_SIZE)
            {
                push_bucket(c1, c1_bucket);
            }
        }
    }
    else
    {
        __sync_sub_and_fetch(&cv_free_bucket_counts[i_bucket],1);
    }
    return c;
}


void HeapManager::push_bucket(chunk_t* i_chunk, size_t i_bucket)
{
    if (i_bucket >= BUCKETS) return;
    i_chunk->free  = 'F';
    i_chunk->size  = 0;
    i_chunk->allocator = 0;
    first_chunk[i_bucket].push(i_chunk);
    __sync_add_and_fetch(&cv_free_bucket_counts[i_bucket],1);
}


void HeapManager::newPage()
{
    void* page = PageManager::allocatePage();
    __sync_add_and_fetch(&cv_smallheap_page_count,1);

    STRC1_KSHORT(KDBG_HM_NEW_PAGE, PTR_TO_u32(page), cv_smallheap_page_count);

    chunk_t * c = reinterpret_cast<chunk_t*>(page);
    size_t remaining = PAGESIZE;

    while(remaining >= MIN_BUCKET_SIZE)
    {
        size_t bucket = bucketIndex(remaining);

        // bucket might be one too big
        if(bucket == BUCKETS || bucketByteSize(bucket) > remaining)
        {
            --bucket;
        }
        c->bucket = bucket;
        push_bucket(c, bucket);

        size_t bsize = bucketByteSize(bucket);
        c = reinterpret_cast<chunk_t*>(((uint8_t*)c) + bsize);
        remaining -= bsize;
    }
    // Note: if the fibonacci series originally used is modified, there could
    // be a remainder.  Thow it away.
}

// find smallest bucket i_sz will fit into
size_t HeapManager::bucketIndex(size_t i_sz)
{

    // A simple linear search loop is unrolled by the compiler
    // and generates large asm code.
    //
    // A manual unrole of a binary search using "if" statements is 160 bytes
    // for this function and 160 bytes for the bucketByteSize() function
    // but does not need the 96 byte iv_chunk_size array. Total 320 bytes
    //
    // This function is 120 bytes and it scales if more buckets are added
    // bucketByteSize() using the static array uses 96 bytes. Total = 216 bytes

    if(i_sz > iv_chunk_size[BUCKETS-1]) return BUCKETS;

    // binary search
    int64_t high_idx = BUCKETS - 1;
    int64_t low_idx  = 0;
    size_t bucket = 0;
    while(low_idx <= high_idx)
    {
        bucket = (low_idx + high_idx) / 2;
        if( i_sz > bucketByteSize(bucket))
        {
            low_idx = bucket + 1;
        }
        else
        {
            high_idx = bucket - 1;
            if(i_sz > bucketByteSize(high_idx)) // high_idx would be too small
                break;
        }
    }
    return bucket;
}


void HeapManager::_coalesce()
{
    // ensure that only one thread is running a coalesce
    int l_zero = __sync_bool_compare_and_swap(&cv_smallheap_coalesce_state,0,1);
    if (!l_zero)
    {
        return; // another thread is running a coallesce
    }
    __sync_add_and_fetch(&cv_smallheap_coalesce_attempts,1);

    STRC1_KSHORT(KDBG_HM_COALESCE, cv_smallheap_coalesce_attempts, 0);

    chunk_list_t main_list;
    chunk_list_t restore_list;
    chunk_t     *chunk{nullptr};
    chunk_t     *cur{nullptr};

    // remove all the chunks from the free buckets, and put them into main_list
    for (size_t bucket = 0; bucket < BUCKETS; ++bucket)
    {
        while ((chunk = first_chunk[bucket].pop()))
        {
            __sync_sub_and_fetch(&cv_free_bucket_counts[chunk->bucket],1);

            if (unlikely(chunk->free != 'F'))
            {
                STRC1_KSHORT(KDBG_HM_COALESCE_ASSERT_NOT_F, PTR_TO_u32(chunk), chunk->free);
                KTRC0("chunk->free is not F in HeapManager::coalesce\n");
                crit_assert(chunk->free == 'F'); // ensure all chunks in the free buckets
                                                 // are marked free
            }

            chunk->coalesce = 'C';
            main_list.push(chunk);
        }
    }

    // On each iteration
    //   -remove a chunk from main_list
    //   -search main_list for other chunks in the same 4k page and try to merge them
    //   -those chunks remaining after each 4k page merge are saved into restore_list
    // When we are finished processing main_list, then put the chunks in restore_list
    //  back into the free buckets

    while ((chunk = main_list.pop()))
    {
        chunk_list_t page_list;
        page_list.push(chunk);   // use the 4k page for this chunk in this iteration

        chunk_t *candidate = main_list.get_head();
        chunk_t *prev      = &main_list.head;  // used to delete each candidate from main_list

        // loop through the rest of main_list looking for candidate chunks in the same
        // 4k page as the first chunk pushed onto page_list above
        while (candidate)
        {
            if (ALIGN_PAGE_DOWN(reinterpret_cast<uint64_t>(candidate)) !=
                ALIGN_PAGE_DOWN(reinterpret_cast<uint64_t>(chunk)))
            {
                prev      = candidate;       // not in same page, move to next
                candidate = candidate->next;
                continue;
            }
            prev->next = candidate->next; // remove candidate from the main_list
            page_list.push(candidate);    // save, since its in the same 4k page
            candidate = prev->next;       // look at the next chunk in main_list
        }

        // add the sizes of the chunks in page_list
        size_t sum{0};
        cur = page_list.get_head();
        while (cur)
        {
            sum += bucketByteSize(cur->bucket);
            cur = cur->next;
        }
        if (sum == PAGESIZE) // the chunks in page_list are a full 4k page
        {
            void *page = (void*)(ALIGN_PAGE_DOWN(reinterpret_cast<uint64_t>(chunk)));
            PageManager::freePage(page,1);  // return this page to PageManager
            __sync_sub_and_fetch(&cv_smallheap_page_count,1);
            __sync_add_and_fetch(&cv_smallheap_coalesce_page,1);
            __sync_add_and_fetch(&cv_smallheap_coalesce_count,page_list.size);
            continue; // the chunks in page_list are discarded, go process the next
                      // chunk in the main_list
        }

        // loop through the chunks in page_list and attempt to coalesce
        chunk_t *page_chunk = page_list.get_head();
        while (page_chunk)
        {
            // calculate the addr of what the buddy chunk must be if page_chunk
            //  is to be merged with its buddy.
            // Each bucket has a specific size, so
            //  buddy_addr = addr_of_page_chunk + bucket_size_of_page_chunk
            // Search in page_list for buddy_addr, and if found then do a merge.
            size_t   chunk_size = bucketByteSize(page_chunk->bucket);
            uint64_t buddy_addr = reinterpret_cast<uint64_t>(page_chunk) + chunk_size;
            chunk_t* buddy      = reinterpret_cast<chunk_t*>(buddy_addr);
            chunk_t *cur        = page_list.get_head();
            bool     any_merged{false};

            prev = &page_list.head; // setup in case we need to delete a chunk

            // search in page_list for buddy
            while (cur)
            {
                if (cur != buddy)
                {
                    // cur is not the addr following page_chunk
                    prev = cur;
                    cur  = cur->next;
                    continue;
                }
                // we found buddy and we can try to merge with page_chunk

                // Calculate the size of page_chunk + buddy
                size_t newSize   = chunk_size + bucketByteSize(buddy->bucket);
                size_t newBucket = bucketIndex(newSize);

                if ((newBucket >= BUCKETS) || (bucketByteSize(newBucket) != newSize))
                {
                    // combined chunk is not a bucket size, cannot merge
                    prev = buddy;
                    cur  = buddy->next;
                    continue;
                }
                // page_chunk and buddy CAN be merged

                __sync_add_and_fetch(&cv_smallheap_coalesce_count,1);

                // update page_chunk and buddy as merged
                buddy->free        = '\0';
                buddy->coalesce    = '\0';
                page_chunk->bucket = newBucket;
                chunk_size         = bucketByteSize(newBucket);
                any_merged         = true;

                prev->next = buddy->next; // remove buddy from page_list
                cur        = buddy->next;
            }

            if (any_merged)
            {
                // we merged page_chunk and buddy
                // look for another chunk in page_list to merge with page_chunk
                //   go calc a new buddy addr and search for it in page_list
                continue;
            }
            // we are done attempting to merge the current page_chunk
            // move to the next page_chunk and try to merge it with any chunk in page_list
            page_chunk = page_chunk->next;
        }

        // we are done merging page_list
        // move the remaining chunks in page_list to restore_list
        while ((cur = page_list.pop()))
        {
            restore_list.push(cur);
        }
    }

    // move the chunks in the restore_list back to the free buckets
    while ((chunk = restore_list.pop()))
    {
        if (unlikely(chunk->free != 'F'))
        {
            STRC1_KSHORT(KDBG_HM_COALESCE_ASSERT_NOT_F, PTR_TO_u32(chunk), chunk->free);
            KTRC0("chunk->free is not F in HeapManager::coalesce\n");
            crit_assert(chunk->free == 'F'); // ensure its still marked free
        }
        if (unlikely(chunk->coalesce != 'C'))
        {
            STRC1_KSHORT(KDBG_HM_COALESCE_ASSERT_NOT_C, PTR_TO_u32(chunk), chunk->coalesce);
            KTRC0("chunk->coalesce is not C in HeapManager::coalesce\n");
            crit_assert(chunk->coalesce == 'C'); // ensure its still marked coalesce
        }
        chunk->coalesce = '\0';
        chunk->free  = 'F';
        chunk->size  = 0;
        chunk->allocator = 0;
        first_chunk[chunk->bucket].push(chunk);
        __sync_add_and_fetch(&cv_free_bucket_counts[chunk->bucket],1);
    }

    test_pages();

    __sync_sub_and_fetch(&cv_smallheap_coalesce_state, 1);
}

void HeapManager::get_stats(kmem_trc_data_t &o_stats)
{
    HeapManager& hmgr = Singleton<HeapManager>::instance();

    uint32_t l_free_chunks = 0;
    uint32_t l_free_bytes  = 0;
    for (size_t i=0; i<BUCKETS; ++i)
    {
        l_free_chunks += hmgr.cv_free_bucket_counts[i];
        l_free_bytes  += hmgr.cv_free_bucket_counts[i] * hmgr.iv_chunk_size[i];
    }
    uint32_t l_inuse_chunks = 0;
    uint32_t l_inuse_bytes  = 0;
    for (size_t i=0; i<BUCKETS; ++i)
    {
        l_inuse_chunks += hmgr.cv_inuse_bucket_counts[i];
        l_inuse_bytes  += hmgr.cv_inuse_bucket_counts[i] * hmgr.iv_chunk_size[i];
    }

    o_stats.cv_free_chunks                 = l_free_chunks;
    o_stats.cv_free_bytes                  = l_free_bytes;
    o_stats.cv_inuse_chunks                = l_inuse_chunks;
    o_stats.cv_inuse_bytes                 = l_inuse_bytes;
    o_stats.cv_smallheap_coalesce_attempts = hmgr.cv_smallheap_coalesce_attempts;
    o_stats.cv_smallheap_coalesce_count    = hmgr.cv_smallheap_coalesce_count;
    o_stats.cv_smallheap_coalesce_page     = hmgr.cv_smallheap_coalesce_page;
    o_stats.cv_smallheap_page_count        = hmgr.cv_smallheap_page_count;
    o_stats.cv_largeheap_page_count        = hmgr.cv_largeheap_page_count;
    o_stats.cv_largeheap_page_max          = hmgr.cv_largeheap_page_max;
    o_stats.iv_hugeblock_allocated         = hmgr.iv_hugeblock_allocated;
    o_stats.cv_hugeblock_page_count        = hmgr.cv_hugeblock_page_count;
    o_stats.cv_hugeblock_page_max          = hmgr.cv_hugeblock_page_max;
    o_stats.cv_smallheap_user_allocated    = hmgr.cv_smallheap_user_allocated;
    o_stats.cv_smallheap_allocated         = hmgr.cv_smallheap_allocated;
    o_stats.cv_smallheap_alloc_hw          = hmgr.cv_smallheap_alloc_hw;
    for (int i=0; i<BUCKETS; i++)
    {
        o_stats.cv_free_bucket_counts[i] = static_cast<uint32_t>(hmgr.cv_free_bucket_counts[i]);
    }
}

void HeapManager::test_pages()
{
#ifdef HOSTBOOT_DEBUG
    for(size_t i = 0; i < BUCKETS; ++i)
        cv_free_bucket_counts[i] = 0;

    size_t max_idx = cv_smallheap_page_count;
    if(max_idx > SMALL_HEAP_PAGES_TRACKED) max_idx = SMALL_HEAP_PAGES_TRACKED;
    for(size_t i = 0; i < max_idx; ++i)
    {
        chunk_t* c = reinterpret_cast<chunk_t*>(g_smallHeapPages[i]);
        uint8_t* c_prev = reinterpret_cast<uint8_t*>(c);
        size_t sum = 0;
        while(sum <= (PAGESIZE-MIN_BUCKET_SIZE))
        {
            size_t b = c->bucket;
            if(b < BUCKETS)
            {
                size_t s = bucketByteSize(b);
                c_prev = reinterpret_cast<uint8_t*>(c);
                c = reinterpret_cast<chunk_t*>(((uint8_t*)c) + s);
                sum += s;
                ++cv_free_bucket_counts[b];
            }
            else
            {
                KTRC0("Heaptest: Corruption at %p on page %p."
                       " Owner of %p may have scribbled on it\n",
                       c,g_smallHeapPages[i],c_prev+8);
                sum = PAGESIZE;
                break;
            }
        }
        if(sum > PAGESIZE)
        {
            KTRC0("Heaptest: Page %p failed consistancy test\n",g_smallHeapPages[i]);
        }
    }
#endif
}

void* HeapManager::_allocateBig(size_t i_sz)
{
    size_t pages = ALIGN_PAGE(i_sz)/PAGESIZE;

#ifdef CONFIG_MALLOC_FENCING
    pages+=BIG_MALLOC_EXTRA_PAGES;
#endif

    void* v = PageManager::allocatePage(pages);
    crit_assert(v);

    STRC1_KSHORT(KDBG_HM_ALLOC_BIG, PTR_TO_u32(v), pages);

    __sync_add_and_fetch(&cv_largeheap_page_count,pages);
    if(cv_largeheap_page_max < cv_largeheap_page_count)
        cv_largeheap_page_max = cv_largeheap_page_count;

    // If already have unused big_chunk_t object available then use it
    // otherwise create a new one.
    big_chunk_t * bc = big_chunk_stack.first();
    while(bc)
    {
        if(bc->page_count == 0)
        {
            if(__sync_bool_compare_and_swap(&bc->addr,nullptr,v))
            {
                bc->page_count = pages;
                break;
            }
        }
        bc = (big_chunk_t*) (((uint64_t)bc->next) & 0x00000000FFFFFFFF);
    }
    if(!bc)
    {
        bc = (big_chunk_t*) contiguous_malloc(sizeof(big_chunk_t));
        bc = new (bc) big_chunk_t(v,pages);
        big_chunk_stack.push(bc);
    }

#ifdef CONFIG_MALLOC_FENCING
    v=_applyBigFence(v,i_sz);
#endif

    return v;
}

bool HeapManager::_freeBig(void* i_ptr)
{
    // Currently all large allocations fall on a page boundary,
    // but small allocations never do
    if (unlikely( ALIGN_PAGE(reinterpret_cast<uint64_t>(i_ptr)) !=
                  reinterpret_cast<uint64_t>(i_ptr))
       )
    {
        return false;
    }

#ifdef CONFIG_MALLOC_FENCING
    i_ptr=_enforceBigFence(i_ptr);
#endif

    size_t page_count{0};
    bool result = false;
    big_chunk_t * bc = big_chunk_stack.first();
    while(bc)
    {
        if(bc->addr == i_ptr)
        {
            __sync_sub_and_fetch(&cv_largeheap_page_count,bc->page_count);

            page_count = bc->page_count;
            bc->page_count = 0;
            bc->addr = nullptr;
            lwsync();

            STRC1_KSHORT(KDBG_HM_FREE_BIG, PTR_TO_u32(i_ptr), page_count);

            PageManager::freePage(i_ptr,page_count);

            // no way to safely remove object from chain so leave it

            result = true;
            break;
        }
        bc = (big_chunk_t*) (((uint64_t)bc->next) & 0x00000000FFFFFFFF);
    }

    // Small allocations are always aligned, hence we exited out at the
    // beginning of the function.  Large allocations are always aligned.
    // If we did not find a large allocation in the list (result == false)
    // then either we have a double-free or someone trying to free something
    // that doesn't belong on the heap.
    if (unlikely(!result))
    {
        STRC1_KSHORT(KDBG_HM_FREE_BIG_ASSERT, PTR_TO_u32(i_ptr), page_count);
        KTRC0("bad result in HeapManager::_freeBig\n");
        crit_assert(result);
    }

    return result;
}

void HeapManager::_addDebugPointers()
{
    DEBUG::add_debug_pointer(DEBUG::HEAPMANAGERINSTANCE,
                             this,
                             sizeof(HeapManager));
}

void* HeapManager::_allocateHuge(size_t i_sz)
{
    size_t pages = ALIGN_PAGE(i_sz)/PAGESIZE;

    if (unlikely((pages*PAGESIZE) > HC_SLOT_SIZE))
    {
        KTRC0( "_allocateHuge> Request too large, bytes=%ld > HC_SLOT_SIZE=%d\n",
            i_sz, HC_SLOT_SIZE );
        crit_assert(0);
    }

    crit_assert(pages);

    // Values for iv_hugeblock_allocated
    //  0=nothing done
    //  1=init in progress
    //  2=init complete
    // If nothing has been initialized yet, do it
    if( __sync_bool_compare_and_swap(&iv_hugeblock_allocated,0,1) )
    {
        int rc = mm_alloc_block( nullptr,
                                 reinterpret_cast<void*>(VMM_VADDR_MALLOC),
                                 HC_TOTAL_SIZE );
        if (unlikely(rc))
        {
            STRC1_KSHORT(KDBG_HM_HUGE_ALLOC_BLOCK_ERROR, pages, 0);
            KTRC0( "_allocateHuge> mm_alloc_block failed for %lX\n",
                    VMM_VADDR_MALLOC );
            // return nullptr to allocatePage() and it will retry using allocateBig()
            return nullptr;
        }

        // Prepopulate list with the available addresses
        for( uint64_t addr = (VMM_VADDR_MALLOC+HC_TOTAL_SIZE);
             addr >= VMM_VADDR_MALLOC;
             addr -= HC_SLOT_SIZE )
        {
            auto hc = static_cast<huge_chunk_t*>(contiguous_malloc(sizeof(huge_chunk_t)));
            hc = new (hc) huge_chunk_t(reinterpret_cast<void*>(addr),0);
            huge_chunk_stack.push(hc);
        }

        iv_hugeblock_allocated = 2;
        sync();
    }
    else
    {
        // hold off any other threads until the init is done
        while( iv_hugeblock_allocated != 2 )
        {
            task_yield();
        }
    }

    // Find an unused chunk
    huge_chunk_t * hc = huge_chunk_stack.first();
    while(hc)
    {
        if( hc->page_count == 0 )
        {
            KTRC1( "_allocateHuge> Found hole at %p pages=%ld i_sz=%ld\n", hc->addr, pages, i_sz);
        }

        // atomically set the page_count
        if(__sync_bool_compare_and_swap(&hc->page_count,0,pages))
        {
            // found an unused chunk, atomically set the page_count
            break;
        }
        hc = reinterpret_cast<huge_chunk_t *> (reinterpret_cast<uint64_t>(hc->next) & 0x00000000FFFFFFFF);
    }
    if (unlikely(!hc))
    {
        STRC1_KSHORT(KDBG_HM_ALLOC_HUGE_NO_CHUNKS, pages, 0);
        KTRC0( "_allocateHuge> No huge_chunk_t left for requested size=%ld!!\n", pages );
        MAGIC_INSTRUCTION(MAGIC_BREAK_ON_ERROR);
        // return nullptr to allocatePage() and it will retry using allocateBig()
        return nullptr;
    }

    int rc = mm_set_permission(hc->addr,
                               pages*PAGESIZE,
                               WRITABLE | ALLOCATE_FROM_ZERO );
    if (unlikely(rc))
    {
        STRC1_KSHORT(KDBG_HM_HUGE_SETPERM_ERROR, PTR_TO_u32(hc->addr), pages);
        KTRC0("_allocateHuge: mm_set_permission failed! addr:%p pages=%ld\n", hc->addr, pages);
        hc->page_count = 0; // Zero it out to free it
        // return nullptr to allocatePage() and it will retry using allocateBig()
        return nullptr;
    }

    __sync_add_and_fetch(&cv_hugeblock_page_count,pages);
    if (cv_hugeblock_page_max < cv_hugeblock_page_count)
    {
        cv_hugeblock_page_max = cv_hugeblock_page_count;
    }

    STRC1_KSHORT(KDBG_HM_ALLOC_HUGE, PTR_TO_u32(hc->addr), pages);

    crit_assert(hc->addr);

    return hc->addr;
}


bool HeapManager::_freeHuge(void* i_ptr)
{
    // Huge allocations are within the allocated VMM space
    if (unlikely(
            (reinterpret_cast<uint64_t>(i_ptr) < VMM_VADDR_MALLOC) ||
            (reinterpret_cast<uint64_t>(i_ptr) >= (VMM_VADDR_MALLOC+VMM_MALLOC_SIZE)) )
       )
    {
        return false;
    }
    STRC1_KSHORT(KDBG_HM_FREE_HUGE, PTR_TO_u32(i_ptr), 0);

    // Find the relevant chunk
    huge_chunk_t * hc = huge_chunk_stack.first();
    while(hc)
    {
        if( hc->addr == i_ptr )
        {
            break;
        }
        hc = reinterpret_cast<huge_chunk_t *> (reinterpret_cast<uint64_t>(hc->next) & 0x00000000FFFFFFFF);
    }
    if (unlikely(!hc))
    {
        KTRC0( "_freeHuge> Cannot find chunk for i_ptr=%p!!\n", i_ptr );
        return false;
    }

    int rc = 0;
    rc = mm_remove_pages(RELEASE,
                         i_ptr,
                         hc->page_count*PAGESIZE);
    if (unlikely(rc))
    {
        KTRC0( "_freeHuge> mm_remove_pages failed for i_ptr=%p (hc->page_count=%ld)\n",
                i_ptr, hc->page_count);
        crit_assert(0);
    }

    // Set permissions back to "no_access"
    rc = mm_set_permission(i_ptr,
                           hc->page_count*PAGESIZE,
                           NO_ACCESS | ALLOCATE_FROM_ZERO );
    if (unlikely(rc))
    {
        KTRC0( "_freeHuge> mm_set_permission failed for i_ptr=%p (hc->page_count=%ld)\n",
                i_ptr, hc->page_count);
        crit_assert(0);
    }

    __sync_sub_and_fetch(&cv_hugeblock_page_count,hc->page_count);

    // Zero it out so we can use it again
    hc->page_count = 0;

    return true;
}

void* HeapManager::_reallocHuge(void* i_ptr, size_t i_sz)
{
    // Huge allocations are within the allocated VMM space
    if (unlikely(
            (reinterpret_cast<uint64_t>(i_ptr) < VMM_VADDR_MALLOC) ||
            (reinterpret_cast<uint64_t>(i_ptr) >= (VMM_VADDR_MALLOC+VMM_MALLOC_SIZE)) )
       )
    {
        KTRC0("_reallocHuge RANGE CHECK i_ptr=%p i_sz=%ld\n", i_ptr, i_sz);
        crit_assert(0);
    }

    if (unlikely( i_sz > HC_SLOT_SIZE ))
    {
        KTRC0("_reallocHuge i_sz > HC_SLOT_SIZE i_ptr=%p i_sz=%ld\n", i_ptr, i_sz);
        crit_assert(0);
    }

    size_t new_size = ALIGN_PAGE(i_sz)/PAGESIZE;

    // Find the chunk in question
    huge_chunk_t * hc = huge_chunk_stack.first();
    while(hc)
    {
        if( hc->addr == i_ptr )
        {
            __sync_add_and_fetch(&cv_hugeblock_page_count, new_size-hc->page_count);
            if (cv_hugeblock_page_max < cv_hugeblock_page_count)
            {
                cv_hugeblock_page_max = cv_hugeblock_page_count;
            }
            hc->page_count = new_size;
            int rc = mm_set_permission(hc->addr,
                              hc->page_count*PAGESIZE,
                              WRITABLE | ALLOCATE_FROM_ZERO );
            if (unlikely(rc))
            {
                KTRC0( "_reallocHuge> mm_set_permission failed for i_ptr=%p (hc->page_count=%ld)\n",
                        i_ptr, hc->page_count);
                crit_assert(0);
            }

            rc = mm_set_permission( (reinterpret_cast<char*>(hc->addr)+(hc->page_count*PAGESIZE)),
                              (HC_SLOT_SIZE - (hc->page_count*PAGESIZE)),
                              NO_ACCESS | ALLOCATE_FROM_ZERO );
            if (unlikely(rc))
            {
                KTRC0( "_reallocHuge> mm_set_permission failed for i_ptr=%p (hc->page_count=%ld)\n",
                        i_ptr, hc->page_count);
                crit_assert(0);
            }
            break;
        }
        hc = reinterpret_cast<huge_chunk_t *> (reinterpret_cast<uint64_t>(hc->next) & 0x00000000FFFFFFFF);
    }
    if (unlikely(!hc))
    {
        KTRC0( "_reallocHuge> No chunk for %p!!\n", i_ptr );
        MAGIC_INSTRUCTION(MAGIC_BREAK_ON_ERROR);
        crit_assert(0);
    }

    STRC1_KSHORT(KDBG_HM_REALLOC_HUGE, PTR_TO_u32(i_ptr), new_size);

    crit_assert(i_ptr);

    return i_ptr;
}
