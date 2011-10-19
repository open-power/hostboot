//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/kernel/heapmgr.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2010 - 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
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
uint32_t g_smallheap_pages = 0;  // total bytes high water (pages used)
uint32_t g_smallheap_count = 0;     // # of chunks allocated

uint32_t g_big_chunks = 0;
uint32_t g_bigheap_highwater = 0;
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

size_t HeapManager::cv_coalesce_count = 0;
size_t HeapManager::cv_free_bytes;
size_t HeapManager::cv_free_chunks;


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
#ifdef HOSTBOOT_DEBUG
               __sync_add_and_fetch(&g_big_chunks,new_size-bc->page_count);
               if(g_bigheap_highwater < g_big_chunks)
                   g_bigheap_highwater = g_big_chunks;
#endif
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
       bc = bc->next;
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
    uint32_t idx = __sync_fetch_and_add(&g_smallheap_pages,1);
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
    // Clean up the smaller heap
    bool merged_one = false;
    chunk_t head; head.next = NULL;
    chunk_t * c = NULL;

    // make a chain out of all the free chunks
    // OPTION: A priority queue sorted by address could be used.
    // This would improve performance when searching for chunks to coalesce, but
    // would require a minimum bucket size of 32 bytes.
    // TODO: sort by address
    for(size_t bucket = 0; bucket < BUCKETS; ++bucket)
    {
        while(NULL != (c = first_chunk[bucket].pop()))
        {
            c->next = head.next;
            head.next = c;
        }
    }

    do
    {
        merged_one = false;
        // look for chunks to coalesce
        for(c = head.next; c!=NULL; c = c->next)
        {
            size_t s = bucketByteSize(c->bucket);
            chunk_t * c_find = reinterpret_cast<chunk_t*>(((uint8_t*)c) + s);

            // c_find must be in same page
            if(reinterpret_cast<uint64_t>(c_find) <
               ALIGN_PAGE(reinterpret_cast<uint64_t>(c)))
            {
                if(c_find->free)
                {
                    // is combinable?
                    size_t ns = s + bucketByteSize(c_find->bucket);
                    size_t n_bucket = bucketIndex(ns);
                    if(n_bucket < BUCKETS && bucketByteSize(n_bucket) == ns)
                    {
                        // find c_find in the free chain and remove it
                        chunk_t * c_prev = &head;
                        chunk_t * c_seek = head.next;
                        while(c_seek != NULL)
                        {
                            if(c_find == c_seek) // found it -> merge
                            {
                                // new bigger chunk
                                c->bucket = n_bucket;
                                merged_one = true;
                                ++cv_coalesce_count;

                                // remove found elment from the chain
                                c_prev->next = c_find->next;

                                break;
                            }
                            c_prev = c_seek;
                            c_seek = c_seek->next;
                        }
                    }
                }
            }
        }
    } while(merged_one); // repeat until nothing can be merged

    // restore the free buckets
    cv_free_chunks = 0;
    cv_free_bytes = 0;
    c = head.next;
    while(c != NULL)
    {
        chunk_t * c_next = c->next;
        push_bucket(c,c->bucket);
        ++cv_free_chunks;
        cv_free_bytes += bucketByteSize(c->bucket) - 8;
        c = c_next;
    }
    printkd("HeapMgr coalesced total %ld\n",cv_coalesce_count);
    test_pages(); /*no effect*/ // BEAM fix.
}

void HeapManager::stats()
{
    coalesce();        // collects some  of the stats

    printkd("Memory Heap Stats:\n");
    printkd("  %d Large heap pages allocated.\n",g_big_chunks);
    printkd("  %d Large heap max allocated.\n",g_bigheap_highwater);
    printkd("  %d Small heap pages.\n",g_smallheap_pages);
    printkd("  %d Small heap bytes max allocated\n",g_smallheap_alloc_hw);
    printkd("  %d Small heap bytes allocated in %d chunks\n",
           g_smallheap_allocated,g_smallheap_count);
    printkd("  %ld Small heap free bytes in %ld chunks\n",cv_free_bytes,cv_free_chunks);
    printkd("  %ld Small heap total chunks coalesced\n",cv_coalesce_count);
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

    size_t max_idx = g_smallheap_pages;
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
#ifdef HOSTBOOT_DEBUG
    //printk("HEAPAB %p:%ld:%ld wasted %ld\n",v,pages,i_sz, pages*PAGESIZE - i_sz);
    __sync_add_and_fetch(&g_big_chunks,pages);
    if(g_bigheap_highwater < g_big_chunks)
        g_bigheap_highwater = g_big_chunks;
#endif

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
        bc = bc->next;
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
#ifdef HOSTBOOT_DEBUG
            __sync_sub_and_fetch(&g_big_chunks,bc->page_count);
#endif
            size_t page_count = bc->page_count;
            bc->page_count = 0;
            bc->addr = NULL;
            lwsync();

            PageManager::freePage(i_ptr,page_count);

            // no way to safely remove object from chain so leave it

            result = true;
            break;
        }
        bc = bc->next;
    }
    return result;
}

