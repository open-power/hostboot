/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/heapmgr.C $                                        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2010,2013              */
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
#include <limits.h>
#include <kernel/heapmgr.H>
#include <util/singleton.H>
#include <kernel/console.H>
#include <kernel/pagemgr.H>
#include <util/align.H>
#include <arch/ppc.H>

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


void HeapManager::init()
{
    Singleton<HeapManager>::instance();
}

void * HeapManager::allocate(size_t i_sz)
{
    HeapManager& hmgr = Singleton<HeapManager>::instance();
    if(i_sz > MAX_SMALL_ALLOC_SIZE)
    {
        return hmgr._allocateBig(i_sz);
    }
    return hmgr._allocate(i_sz);
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
    size_t which_bucket = bucketIndex(i_sz+8);

    chunk_t* chunk = reinterpret_cast<chunk_t*>(NULL);
    chunk = pop_bucket(which_bucket);
    if (NULL == chunk)
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
        crit_assert(chunk->free);
        chunk->free = false;
        return &chunk->next;
    }
}


void* HeapManager::_realloc(void* i_ptr, size_t i_sz)
{
    void* new_ptr = _reallocBig(i_ptr,i_sz);
    if(new_ptr) return new_ptr;

    new_ptr = i_ptr;
    chunk_t* chunk = reinterpret_cast<chunk_t*>(((size_t*)i_ptr)-1);
    size_t asize = bucketByteSize(chunk->bucket)-8;
    if(asize < i_sz)
    {
        new_ptr = _allocate(i_sz);
        memcpy(new_ptr, i_ptr, asize);
        _free(i_ptr);
    }
    return new_ptr;
}

void* HeapManager::_reallocBig(void* i_ptr, size_t i_sz)
{
    // Currently all large allocations fall on a page boundry,
    // but small allocatoins never do
    if(ALIGN_PAGE(reinterpret_cast<uint64_t>(i_ptr)) !=
       reinterpret_cast<uint64_t>(i_ptr))
    {
        return NULL;
    }

    void* new_ptr = NULL;
    big_chunk_t * bc = big_chunk_stack.first();
    while(bc)
   {
       if(bc->addr == i_ptr)
       {
           size_t new_size = ALIGN_PAGE(i_sz)/PAGESIZE;
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
   return new_ptr;
}

void HeapManager::_free(void * i_ptr)
{
    if (NULL == i_ptr) return;

    if(!_freeBig(i_ptr))
    {
        chunk_t* chunk = reinterpret_cast<chunk_t*>(((size_t*)i_ptr)-1);
#ifdef HOSTBOOT_DEBUG
        __sync_sub_and_fetch(&g_smallheap_count,1);
        __sync_sub_and_fetch(&g_smallheap_allocated,bucketByteSize(chunk->bucket));
#endif
        crit_assert(!chunk->free);
        push_bucket(chunk, chunk->bucket);
    }
}


HeapManager::chunk_t* HeapManager::pop_bucket(size_t i_bucket)
{
    if (i_bucket >= BUCKETS) return NULL;

    chunk_t* c = first_chunk[i_bucket].pop();

    if (NULL == c)
    {
        // Couldn't allocate from the correct size bucket, so split up an
        // item from the next sized bucket.
        c = pop_bucket(i_bucket+1);
        if (NULL != c)
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
    i_chunk->free = true;
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
    chunk_t* head = NULL;
    chunk_t* chunk = NULL;

    // make a chain out of all the free chunks
    for(size_t bucket = 0; bucket < BUCKETS; ++bucket)
    {
        chunk = NULL;
        while(NULL != (chunk = first_chunk[bucket].pop()))
        {
            chunk->next = head;
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
        while(NULL != chunk)
        {
            bool incrementChunk = true;

            do
            {
                // This chunk might already be combined with a chunk earlier
                // in the loop.
                if(!chunk->free)
                {
                    break;
                }

                // Use the size of this chunk to find next chunk.
                size_t size = bucketByteSize(chunk->bucket);
                chunk_t* buddy = reinterpret_cast<chunk_t*>(
                        reinterpret_cast<size_t>(chunk) + size);

                // The two chunks have to be on the same page in order to
                // be considered for merge.
                if (ALIGN_PAGE_DOWN(reinterpret_cast<uint64_t>(buddy)) !=
                    ALIGN_PAGE_DOWN(reinterpret_cast<uint64_t>(chunk)))
                {
                    break;
                }

                // Cannot merge if buddy is not free.
                if (!buddy->free)
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
                buddy->free = false;
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
        chunk_t* newHead = NULL;
        chunk = head;
        while (NULL != chunk)
        {
            if (chunk->free)
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
    while(chunk != NULL)
    {
        chunk_t * temp = chunk->next;

        push_bucket(chunk,chunk->bucket);

        ++cv_free_chunks;
        cv_free_bytes += bucketByteSize(chunk->bucket) - 8;

        chunk = temp;
    }
    printkd("HeapMgr coalesced total %d\n",cv_coalesce_count);
    test_pages(); /*no effect*/ // BEAM fix.
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
            if(__sync_bool_compare_and_swap(&bc->addr,NULL,v))
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

    return v;
}

bool HeapManager::_freeBig(void* i_ptr)
{
    // Currently all large allocations fall on a page boundry,
    // but small allocations never do
    if(ALIGN_PAGE(reinterpret_cast<uint64_t>(i_ptr)) !=
       reinterpret_cast<uint64_t>(i_ptr))
        return false;

    bool result = false;
    big_chunk_t * bc = big_chunk_stack.first();
    while(bc)
    {
        if(bc->addr == i_ptr)
        {
            __sync_sub_and_fetch(&cv_largeheap_page_count,bc->page_count);

            size_t page_count = bc->page_count;
            bc->page_count = 0;
            bc->addr = NULL;
            lwsync();

            PageManager::freePage(i_ptr,page_count);

            // no way to safely remove object from chain so leave it

            result = true;
            break;
        }
        bc = (big_chunk_t*) (((uint64_t)bc->next) & 0x00000000FFFFFFFF);
    }
    return result;
}

