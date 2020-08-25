/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/heapmgr.C $                                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2010,2020                        */
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

#ifdef HOSTBOOT_DEBUG
#define SMALL_HEAP_PAGES_TRACKED 64

// track pages allocated to smallheap
void * g_smallHeapPages[SMALL_HEAP_PAGES_TRACKED];

// If these stats are to be kept then they should be modified using
// atomic instructions
uint16_t g_bucket_counts[HeapManager::BUCKETS];
uint32_t g_smallheap_allocated = 0;  // sum of currently allocated
uint32_t g_smallheap_alloc_hw  = 0;  // allocated high water
uint32_t g_smallheap_count = 0;     // # of chunks allocated

#endif

const size_t HeapManager::cv_chunk_size[BUCKETS] =
{
    HeapManager::BUCKET_SIZE0,
    HeapManager::BUCKET_SIZE1,
    HeapManager::BUCKET_SIZE2,
    HeapManager::BUCKET_SIZE3,
    HeapManager::BUCKET_SIZE4,
    HeapManager::BUCKET_SIZE5,
    HeapManager::BUCKET_SIZE6,
    HeapManager::BUCKET_SIZE7,
    HeapManager::BUCKET_SIZE8,
    HeapManager::BUCKET_SIZE9,
    HeapManager::BUCKET_SIZE10,
    HeapManager::BUCKET_SIZE11
};

uint32_t HeapManager::cv_coalesce_count = 0;
uint32_t HeapManager::cv_free_bytes;
uint32_t HeapManager::cv_free_chunks;
uint32_t HeapManager::cv_smallheap_page_count = 0;
uint32_t HeapManager::cv_largeheap_page_count = 0;
uint32_t HeapManager::cv_largeheap_page_max = 0;
uint32_t HeapManager::cv_hugeblock_allocated = 0;

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
    crit_assert(pFence->begin == CHECK::BEGIN);
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
    HeapManager& hmgr = Singleton<HeapManager>::instance();
    size_t overhead = 0;

#ifdef CONFIG_MALLOC_FENCING
    overhead = offsetof(fence_t,data) + sizeof(CHECK::END);
#endif

    if( (i_sz + overhead > MAX_BIG_ALLOC_SIZE)
        && (i_sz + overhead <= HC_SLOT_SIZE) )
    {
        printkd("allocateHuge=%ld [%d]\n", i_sz, task_gettid());
        void* ptr = hmgr._allocateHuge(i_sz);
        if( ptr )
        {
            return ptr;
        }
        else
        {
            // default to using regular allocations if huge doesn't work
            return hmgr._allocateBig(i_sz);
        }
    }
    else if(i_sz + overhead > MAX_SMALL_ALLOC_SIZE)
    {
        return hmgr._allocateBig(i_sz);
    }

    void* result = hmgr._allocate(i_sz + overhead);

#ifdef CONFIG_MALLOC_FENCING
    result = _applySmallFence(result,i_sz);
#endif

    return result;
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
    Singleton<HeapManager>::instance()._coalesce();
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
#ifdef HOSTBOOT_DEBUG
        size_t alloc = bucketByteSize(chunk->bucket);
        __sync_add_and_fetch(&g_smallheap_count,1);
        __sync_add_and_fetch(&g_smallheap_allocated,alloc);
        if (g_smallheap_allocated > g_smallheap_alloc_hw)
            g_smallheap_alloc_hw = g_smallheap_allocated;
        // test_pages();
#endif
        crit_assert(chunk->free == 'F');

        // Use the size of this chunk get to the end.
        size_t size = bucketByteSize(chunk->bucket);

        // set the last byte of the chunk to 'V' => valid
        *(reinterpret_cast<uint8_t*>(chunk) + size - 1 ) = 'V';

        // mark chunk as allocated
        chunk->free = 'A';
        chunk->size = i_sz;
        chunk->allocator = task_gettid();

        return &chunk->next;
    }
}

void* HeapManager::_realloc(void* i_ptr, size_t i_sz)
{
    void* new_ptr = _reallocHuge(i_ptr,i_sz);
    if(new_ptr) return new_ptr;

    new_ptr = _reallocBig(i_ptr,i_sz);
    if(new_ptr) return new_ptr;

    size_t overhead = 0;
    new_ptr = i_ptr;

#ifdef CONFIG_MALLOC_FENCING
    overhead = offsetof(fence_t,data) + sizeof(CHECK::END);
    size_t userSize=0;
    new_ptr = _enforceSmallFence(i_ptr,userSize);
#endif

    chunk_t* chunk = reinterpret_cast<chunk_t*>(((uint64_t*)new_ptr)-1);

    // take into account the 8 byte header and valid byte
    size_t asize = bucketByteSize(chunk->bucket) - CHUNK_HEADER_PLUS_RESERVED;
    if(asize < i_sz + overhead)
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

    return new_ptr;
}

void* HeapManager::_reallocBig(void* i_ptr, size_t i_sz)
{
    // Currently all large allocations fall on a page boundary,
    // but small allocatoins never do
    if(ALIGN_PAGE(reinterpret_cast<uint64_t>(i_ptr)) !=
       reinterpret_cast<uint64_t>(i_ptr))
    {
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

   return new_ptr;
}

void HeapManager::_free(void * i_ptr)
{
    if (nullptr == i_ptr) return;

    if(!_freeHuge(i_ptr) && !_freeBig(i_ptr))
    {

#ifdef CONFIG_MALLOC_FENCING
        size_t userSize=0;
        i_ptr = _enforceSmallFence(i_ptr,userSize);
#endif

        chunk_t* chunk = reinterpret_cast<chunk_t*>(((uint64_t*)i_ptr)-1);

#ifdef HOSTBOOT_DEBUG
        __sync_sub_and_fetch(&g_smallheap_count,1);
        __sync_sub_and_fetch(&g_smallheap_allocated,bucketByteSize(chunk->bucket));
#endif
        crit_assert(chunk->free != 'F');

        // Use the size of this chunk to find next chunk.
        size_t size = bucketByteSize(chunk->bucket);

        // make sure the next block is still valid
        if( *(reinterpret_cast<uint8_t*>(chunk) + size - 1 ) != 'V')
        {
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

    return c;
}


void HeapManager::push_bucket(chunk_t* i_chunk, size_t i_bucket)
{
    if (i_bucket >= BUCKETS) return;
    i_chunk->free  = 'F';
    i_chunk->size  = 0;
    i_chunk->allocator = 0;
    first_chunk[i_bucket].push(i_chunk);
}


void HeapManager::newPage()
{
    void* page = PageManager::allocatePage();
    chunk_t * c = reinterpret_cast<chunk_t*>(page);
    size_t remaining = PAGESIZE;

#ifdef HOSTBOOT_DEBUG
    uint32_t idx =
#endif
        __sync_fetch_and_add(&cv_smallheap_page_count,1);
#ifdef HOSTBOOT_DEBUG
    if(idx < SMALL_HEAP_PAGES_TRACKED)
        g_smallHeapPages[idx] = page;
#endif

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
    // but does not need the 96 byte cv_chunk_size array. Total 320 bytes
    //
    // This function is 120 bytes and it scales if more buckets are added
    // bucketByteSize() using the static array uses 96 bytes. Total = 216 bytes

    if(i_sz > cv_chunk_size[BUCKETS-1]) return BUCKETS;

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


// all other processes must be quiesced
void HeapManager::_coalesce()
{
    chunk_t* head = nullptr;
    chunk_t* chunk = nullptr;

    // make a chain out of all the free chunks
    for(size_t bucket = 0; bucket < BUCKETS; ++bucket)
    {
        chunk = nullptr;
        while(nullptr != (chunk = first_chunk[bucket].pop()))
        {
            kassert(chunk->free == 'F');

            chunk->next = head;
            chunk->coalesce = 'C';
            head = chunk;
        }
    }

    // Merge the chunks together until we fail to find a buddy.
    bool mergedChunks = false;
    do
    {
        mergedChunks = false;
        chunk = head;

        // Iterate through the chain.
        while(nullptr != chunk)
        {
            bool incrementChunk = true;

            do
            {
                // This chunk might already be combined with a chunk earlier
                // in the loop.
                if((chunk->coalesce != 'C') || (chunk->free != 'F'))
                {
                    break;
                }

                // Use the size of this chunk to find next chunk.
                size_t size = bucketByteSize(chunk->bucket);
                chunk_t* buddy = reinterpret_cast<chunk_t*>(
                        reinterpret_cast<uint64_t>(chunk) + size);

                // The two chunks have to be on the same page in order to
                // be considered for merge.
                if (ALIGN_PAGE_DOWN(reinterpret_cast<uint64_t>(buddy)) !=
                    ALIGN_PAGE_DOWN(reinterpret_cast<uint64_t>(chunk)))
                {
                    break;
                }

                // Cannot merge if buddy is not free.
                if ((buddy->free != 'F') || (buddy->coalesce != 'C'))
                {
                    break;
                }

                // Calculate the size of a combined chunk.
                size_t newSize = size + bucketByteSize(buddy->bucket);
                size_t newBucket = bucketIndex(newSize);

                // If the combined chunk is not a bucket size, cannot merge.
                if ((newBucket >= BUCKETS) ||
                    (bucketByteSize(newBucket) != newSize))
                {
                    break;
                }

                // Do merge.
                buddy->free = '\0'; buddy->coalesce = '\0';
                chunk->bucket = newBucket;
                incrementChunk = false;
                mergedChunks = true;

                cv_coalesce_count++;

            } while(0);

            if (incrementChunk)
            {
                chunk = chunk->next;
            }
        }

        // Remove all the non-free (merged) chunks from the list.
        chunk_t* newHead = nullptr;
        chunk = head;
        while (nullptr != chunk)
        {
            if ((chunk->free == 'F') && (chunk->coalesce == 'C'))
            {
                chunk_t* temp = chunk->next;
                chunk->next = newHead;
                newHead = chunk;

                chunk=temp;
            }
            else
            {
                chunk = chunk->next;
            }
        }

        head = newHead;

    } while(mergedChunks);


    // restore the free buckets
    cv_free_chunks = 0;
    cv_free_bytes = 0;
    chunk = head;
    while(chunk != nullptr)
    {
        chunk_t * temp = chunk->next;

        chunk->coalesce = '\0';
        push_bucket(chunk,chunk->bucket);

        ++cv_free_chunks;
        cv_free_bytes += bucketByteSize(chunk->bucket) - 8;

        chunk = temp;
    }
    printkd("HeapMgr coalesced total %d\n",cv_coalesce_count);
    test_pages();
}

void HeapManager::stats()
{
    coalesce();        // collects some  of the stats

    printkd("Memory Heap Stats:\n");
    printkd("  %d Large heap pages allocated.\n",cv_largeheap_page_count);
    printkd("  %d Large heap max allocated.\n",cv_largeheap_page_max);
    printkd("  %d Small heap pages.\n",cv_smallheap_page_count);
    printkd("  %d Small heap bytes max allocated\n",g_smallheap_alloc_hw);
    printkd("  %d Small heap bytes allocated in %d chunks\n",
           g_smallheap_allocated,g_smallheap_count);
    printkd("  %d Small heap free bytes in %d chunks\n",cv_free_bytes,cv_free_chunks);
    printkd("  %d Small heap total chunks coalesced\n",cv_coalesce_count);
    printkd("Small heap bucket profile:\n");
    for(size_t i = 0; i < BUCKETS; ++i)
    {
        printkd("  %d chunks of bytesize %ld\n",
               g_bucket_counts[i],
               cv_chunk_size[i]-8);
    }

    PageManager::coalesce();
}


void HeapManager::test_pages()
{
#ifdef HOSTBOOT_DEBUG
    for(size_t i = 0; i < BUCKETS; ++i)
        g_bucket_counts[i] = 0;

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
                ++g_bucket_counts[b];
            }
            else
            {
                printk("Heaptest: Corruption at %p on page %p."
                       " Owner of %p may have scribbled on it\n",
                       c,g_smallHeapPages[i],c_prev+8);
                sum = PAGESIZE;
                break;
            }
        }
        if(sum > PAGESIZE)
        {
            printk("Heaptest: Page %p failed consistancy test\n",g_smallHeapPages[i]);
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
        bc = new big_chunk_t(v,pages);
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
    if(ALIGN_PAGE(reinterpret_cast<uint64_t>(i_ptr)) !=
       reinterpret_cast<uint64_t>(i_ptr))
        return false;

#ifdef CONFIG_MALLOC_FENCING
    i_ptr=_enforceBigFence(i_ptr);
#endif

    bool result = false;
    big_chunk_t * bc = big_chunk_stack.first();
    while(bc)
    {
        if(bc->addr == i_ptr)
        {
            __sync_sub_and_fetch(&cv_largeheap_page_count,bc->page_count);

            size_t page_count = bc->page_count;
            bc->page_count = 0;
            bc->addr = nullptr;
            lwsync();

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
    crit_assert(result);

    return result;
}

void HeapManager::_addDebugPointers()
{
    DEBUG::add_debug_pointer(DEBUG::HEAPMANAGER,
                             this,
                             sizeof(HeapManager));
    DEBUG::add_debug_pointer(DEBUG::HEAPMANAGERLARGEPAGECOUNT,
                             &cv_largeheap_page_count,
                             sizeof(HeapManager::cv_largeheap_page_count));
    DEBUG::add_debug_pointer(DEBUG::HEAPMANAGERLARGEPAGEMAX,
                             &cv_largeheap_page_max,
                             sizeof(HeapManager::cv_largeheap_page_max));
    DEBUG::add_debug_pointer(DEBUG::HEAPMANAGERSMALLPAGECOUNT,
                             &cv_smallheap_page_count,
                             sizeof(HeapManager::cv_smallheap_page_count));
    DEBUG::add_debug_pointer(DEBUG::HEAPMANAGERCOALESCECOUNT,
                             &cv_coalesce_count,
                             sizeof(HeapManager::cv_coalesce_count));
    DEBUG::add_debug_pointer(DEBUG::HEAPMANAGERFREEBYTES,
                             &cv_free_bytes,
                             sizeof(HeapManager::cv_free_bytes));
    DEBUG::add_debug_pointer(DEBUG::HEAPMANAGERFREECHUNKS,
                             &cv_free_chunks,
                             sizeof(HeapManager::cv_free_chunks));
    DEBUG::add_debug_pointer(DEBUG::HUGEBLOCKALLOCATED,
                             &cv_hugeblock_allocated,
                             sizeof(HeapManager::cv_hugeblock_allocated));
}

void* HeapManager::_allocateHuge(size_t i_sz)
{
    size_t pages = ALIGN_PAGE(i_sz)/PAGESIZE;
    if( (pages*PAGESIZE) > HC_SLOT_SIZE )
    {
        printkd( "_allocateHuge> Request too large, bytes=%ld > HC_SLOT_SIZE=%d\n",
            i_sz, HC_SLOT_SIZE );
        return nullptr;
    }

    // Values for cv_hugeblock_allocated
    //  0=nothing done
    //  1=init in progress
    //  2=init complete
    // If nothing has been initialized yet, do it
    if( __sync_bool_compare_and_swap(&cv_hugeblock_allocated,0,1) )
    {
        int rc = mm_alloc_block( nullptr,
                                 reinterpret_cast<void*>(VMM_VADDR_MALLOC),
                                 HC_TOTAL_SIZE );
        if(rc != 0)
        {
            printk( "_allocateHuge> mm_alloc_block failed for %lX\n",
                    VMM_VADDR_MALLOC );
            return nullptr;
        }

        // Prepopulate list with the available addresses
        for( uint64_t addr = (VMM_VADDR_MALLOC+HC_TOTAL_SIZE);
             addr >= VMM_VADDR_MALLOC;
             addr -= HC_SLOT_SIZE )
        {
            huge_chunk_t* hc =
              new huge_chunk_t(reinterpret_cast<void*>(addr),0);
            huge_chunk_stack.push(hc);
        }

        cv_hugeblock_allocated = 2;
        sync();
    }
    else
    {
        // hold off any other threads until the init is done
        while( cv_hugeblock_allocated != 2 )
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
            printkd( "_allocateHuge> Found hole at %p pages=%ld i_sz=%ld\n", hc->addr, pages, i_sz);
        }

        // atomically set the page_count
        if(__sync_bool_compare_and_swap(&hc->page_count,0,pages))
        {
            break;
        }
        hc = reinterpret_cast<huge_chunk_t *> (reinterpret_cast<uint64_t>(hc->next) & 0x00000000FFFFFFFF);
    }
    if(!hc)
    {
        printk( "_allocateHuge> No chunks left for requested size=%ld!!\n", i_sz );
        MAGIC_INSTRUCTION(MAGIC_BREAK_ON_ERROR);
        return nullptr;
    }

    int rc = mm_set_permission(hc->addr,
                               pages*PAGESIZE,
                               WRITABLE | ALLOCATE_FROM_ZERO );
    if(rc != 0)
    {
        printk( "_allocateHuge> mm_set_permission failed for requested size=%ld!!\n", i_sz );
    }

    return hc->addr;
}


bool HeapManager::_freeHuge(void* i_ptr)
{
    // Huge allocations are within the allocated VMM space
    if( (reinterpret_cast<uint64_t>(i_ptr) < VMM_VADDR_MALLOC)
        || (reinterpret_cast<uint64_t>(i_ptr)
            >= (VMM_VADDR_MALLOC+VMM_MALLOC_SIZE)) )
    {
        return false;
    }
    printkd( "_freeHuge> free i_ptr=%p\n", i_ptr );

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
    if(!hc)
    {
        printk( "_freeHuge> Cannot find chunk for i_ptr=%p!!\n", i_ptr );
        return false;
    }

    int rc = 0;
    rc = mm_remove_pages(RELEASE,
                         i_ptr,
                         hc->page_count*PAGESIZE);
    if(rc != 0)
    {
        printk( "_freeHuge> mm_remove_pages failed for i_ptr=%p (hc->page_count=%ld)\n", i_ptr, hc->page_count);
        return false;
    }

    // Set permissions back to "no_access"
    rc = mm_set_permission(i_ptr,
                           hc->page_count*PAGESIZE,
                           NO_ACCESS | ALLOCATE_FROM_ZERO );
    if(rc != 0)
    {
        printk( "_freeHuge> mm_set_permission failed for i_ptr=%p (hc->page_count=%ld)\n", i_ptr, hc->page_count);
        return false;
    }

    // Zero it out so we can use it again
    hc->page_count = 0;

    return true;
}

void* HeapManager::_reallocHuge(void* i_ptr, size_t i_sz)
{
    // Huge allocations are within the allocated VMM space
    if( (reinterpret_cast<uint64_t>(i_ptr) < VMM_VADDR_MALLOC)
        || (reinterpret_cast<uint64_t>(i_ptr) >=
            (VMM_VADDR_MALLOC+VMM_MALLOC_SIZE)) )
    {
        return nullptr;
    }

    if( i_sz > HC_SLOT_SIZE )
    {
        printk( "_reallocHuge> Cannot do a realloc of %ld bytes, max is HC_SLOT_SIZE=%d", i_sz, HC_SLOT_SIZE );
        return nullptr;
    }

    // Find the chunk in question
    huge_chunk_t * hc = huge_chunk_stack.first();
    while(hc)
    {
        if( hc->addr == i_ptr )
        {
            hc->page_count = ALIGN_PAGE(i_sz)/PAGESIZE;
            int rc = mm_set_permission(hc->addr,
                              hc->page_count*PAGESIZE,
                              WRITABLE | ALLOCATE_FROM_ZERO );

            if(rc != 0)
            {
                printk( "_reallocHuge> mm_set_permission failed for i_ptr=%p (hc->page_count=%ld)\n", i_ptr, hc->page_count);
                return nullptr;
            }

            rc = mm_set_permission( (reinterpret_cast<char*>(hc->addr)+(hc->page_count*PAGESIZE)),
                              (HC_SLOT_SIZE - (hc->page_count*PAGESIZE)),
                              NO_ACCESS | ALLOCATE_FROM_ZERO );

            if(rc != 0)
            {
                printk( "_reallocHuge> mm_set_permission failed for i_ptr=%p (hc->page_count=%ld)\n", i_ptr, hc->page_count);
                return nullptr;
            }
            break;
        }
        hc = reinterpret_cast<huge_chunk_t *> (reinterpret_cast<uint64_t>(hc->next) & 0x00000000FFFFFFFF);
    }
    if(!hc)
    {
        printk( "_reallocHuge> No chunk for %p!!\n", i_ptr );
        MAGIC_INSTRUCTION(MAGIC_BREAK_ON_ERROR);
        return nullptr;
    }

    return i_ptr;
}

