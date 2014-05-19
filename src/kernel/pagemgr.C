/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/pagemgr.C $                                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2010,2014              */
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
#include <kernel/pagemgr.H>
#include <util/singleton.H>
#include <kernel/console.H>
#include <arch/ppc.H>
#include <util/locked/pqueue.H>
#include <kernel/task.H>
#include <kernel/taskmgr.H>
#include <kernel/vmmmgr.H>
#include <sys/task.h>
#include <kernel/misc.H>
#include <sys/syscall.h>
#include <assert.h>
#include <kernel/memstate.H>


size_t PageManager::cv_coalesce_count = 0;
size_t PageManager::cv_low_page_count = -1;


void PageManagerCore::addMemory( size_t i_addr, size_t i_pageCount )
{
    size_t length = i_pageCount;
    page_t* page = reinterpret_cast<page_t *>(ALIGN_PAGE(i_addr));

    // Allocate pages to buckets.
    size_t page_length = BUCKETS-1;
    while(length > 0)
    {
        while (length < (size_t)(1 << page_length))
        {
            page_length--;
        }

        iv_heap[page_length].push(page);
        page = (page_t*)((uint64_t)page + (1 << page_length)*PAGESIZE);
        length -= (1 << page_length);
    }
    __sync_add_and_fetch(&iv_available, i_pageCount);
}



PageManagerCore::page_t * PageManagerCore::allocatePage( size_t i_pageCount )
{
    size_t which_bucket = ((sizeof(size_t)*8 - 1) -
                                __builtin_clzl(i_pageCount));
    size_t bucket_size = ((size_t)1) << which_bucket;

    if (bucket_size != i_pageCount)
    {
        ++which_bucket;
        bucket_size <<= 1;
    }

    page_t* page = (page_t*)NULL;
    int retries = 0;
    while ((page == NULL) && (retries < 6))
    {
        page = pop_bucket(which_bucket);
        retries++;
    }

    // Update statistics.
    if(page)
    {
        __sync_sub_and_fetch(&iv_available, bucket_size);

        // Buckets are 2^k in size so if i_pageCount is not 2^k we have some
        // extra pages allocated.  ie. the non-2^k portion of i_pageCount.
        // Return that portion by freeing.
        if (bucket_size != i_pageCount)
        {
            freePage(reinterpret_cast<void*>(
                            reinterpret_cast<uintptr_t>(page) +
                            (i_pageCount*PAGESIZE)),
                     bucket_size - i_pageCount);
        }
    }

    return page;
}



void PageManagerCore::freePage( void * i_page, size_t i_pageCount )
{
    if ((NULL == i_page) || (0 == i_pageCount)) return;

    size_t which_bucket = ((sizeof(size_t)*8 - 1) -
                                __builtin_clzl(i_pageCount));
    size_t bucket_size = ((size_t)1) << which_bucket;

    push_bucket((page_t*)i_page, which_bucket);

    // Update statistics.
    __sync_add_and_fetch(&iv_available, bucket_size);

    // Buckets are 2^k in size so if i_pageCount is not 2^k we have some
    // spare pages to free.  ie. the non-2^k portion of i_pageCount.
    if (bucket_size != i_pageCount)
    {
        freePage(reinterpret_cast<void*>(
                    reinterpret_cast<uintptr_t>(i_page) +
                    (bucket_size*PAGESIZE)),
                 i_pageCount - bucket_size);
    }

    return;
}



void PageManager::init()
{
    Singleton<PageManager>::instance();
}

void* PageManager::allocatePage(size_t n, bool userspace)
{
    void* page = NULL;

    // In non-kernel mode, make a system-call to allocate in kernel-mode.
    if (!KernelMisc::in_kernel_mode())
    {
        while (NULL == page)
        {
            page = _syscall1(Systemcalls::MM_ALLOC_PAGES,
                             reinterpret_cast<void*>(n));

            // Didn't successfully allocate, so yield in hopes that memory
            // will eventually free up (ex. VMM flushes).
            if (NULL == page)
            {
                task_yield();
            }
        }
    }
    else
    {
        // In kernel mode.  Do a normal call to the PageManager.
        PageManager& pmgr = Singleton<PageManager>::instance();
        page = pmgr._allocatePage(n, userspace);
    }

    return page;
}

void PageManager::freePage(void* p, size_t n)
{
    PageManager& pmgr = Singleton<PageManager>::instance();
    return pmgr._freePage(p, n);
}

uint64_t PageManager::queryAvail()
{
    return Singleton<PageManager>::instance()._queryAvail();
}

uint64_t PageManager::availPages()
{
    return Singleton<PageManager>::instance()._availPages();
}

PageManager::PageManager()
    : iv_pagesAvail(0), iv_pagesTotal(0), iv_lock()
{
    this->_initialize();
}

void PageManager::_initialize()
{
    typedef PageManagerCore::page_t page_t;
    uint64_t totalPages = 0;

    page_t* startAddr = reinterpret_cast<page_t*>(firstPageAddr());
    page_t* endAddr = reinterpret_cast<page_t*>(VmmManager::INITIAL_MEM_SIZE);
    printk("Initializing PageManager starting at %p...", startAddr);

    // Calculate chunks along the top half of the L3 and erase them.
    uint64_t currentBlock = reinterpret_cast<uint64_t>(startAddr);
    do
    {
        if (currentBlock % (1*MEGABYTE) >= (512*KILOBYTE))
        {
            currentBlock = ALIGN_MEGABYTE(currentBlock);
            continue;
        }

        uint64_t endBlock = ALIGN_MEGABYTE_DOWN(currentBlock) + 512*KILOBYTE;

        // Adjust address to compensate for reserved hole and add to
        // heap...

        // Check if this block starts in the hole.
        if ((currentBlock >= VmmManager::FIRST_RESERVED_PAGE) &&
            (currentBlock < VmmManager::END_RESERVED_PAGE))
        {
            // End of the block is in the hole, skip.
            if (endBlock < VmmManager::END_RESERVED_PAGE)
            {
                currentBlock = ALIGN_MEGABYTE(endBlock);
                continue;
            }

            // Advance the current block past the hole.
            currentBlock = VmmManager::END_RESERVED_PAGE;
        }

        // Check if the block is has the hole in it.
        if ((endBlock >= VmmManager::FIRST_RESERVED_PAGE) &&
            (currentBlock < VmmManager::FIRST_RESERVED_PAGE))
        {
            // Hole is at the end of the block, shrink it down.
            if (endBlock < VmmManager::END_RESERVED_PAGE)
            {
                endBlock = VmmManager::FIRST_RESERVED_PAGE;
            }
            // Hole is in the middle... yuck.
            else
            {
                uint64_t hole_end =
                    (VmmManager::FIRST_RESERVED_PAGE - currentBlock);

                // Populate L3 for the first part of the chunk.
                KernelMisc::populate_cache_lines(
                    reinterpret_cast<uint64_t*>(currentBlock),
                    reinterpret_cast<uint64_t*>(hole_end));

                // Add it to the heap.
                iv_heap.addMemory(currentBlock, hole_end / PAGESIZE);
                totalPages += (hole_end / PAGESIZE);

                currentBlock = VmmManager::END_RESERVED_PAGE;
            }
        }

        // Populate L3 cache lines for this chunk.
        KernelMisc::populate_cache_lines(
            reinterpret_cast<uint64_t*>(currentBlock),
            reinterpret_cast<uint64_t*>(endBlock));

        uint64_t pages = (endBlock - currentBlock) / PAGESIZE;

        iv_heap.addMemory(currentBlock, pages);
        totalPages += pages;

        currentBlock = ALIGN_MEGABYTE(endBlock);

    } while (reinterpret_cast<page_t*>(currentBlock) != endAddr);

    // Ensure HW page table area is erased / populated.
    KernelMisc::populate_cache_lines(
        reinterpret_cast<uint64_t*>(VmmManager::INITIAL_PT_OFFSET),
        reinterpret_cast<uint64_t*>(VmmManager::INITIAL_PT_OFFSET +
                                    VmmManager::PTSIZE));

    printk("%ld pages.\n", totalPages);

    // Reserve pages for the kernel.
    iv_heapKernel.addMemory(reinterpret_cast<uint64_t>(
                              iv_heap.allocatePage(KERNEL_HEAP_RESERVED_PAGES)),
                            KERNEL_HEAP_RESERVED_PAGES);

    // Statistics
    iv_pagesTotal = totalPages;
    iv_pagesAvail = totalPages;
    cv_low_page_count = totalPages;

    KernelMemState::setMemScratchReg(KernelMemState::MEM_CONTAINED_L3,
                                     KernelMemState::PRE_SECURE_BOOT);
}

void* PageManager::_allocatePage(size_t n, bool userspace)
{
    // The allocator was designed to be lockless.  We have ran into a problem
    // in Brazos where all threads (over 256) were trying to allocate a page
    // at the same time.  This resulted in many of them trying to break a large
    // page chunk into smaller fragments.  The later threads ended up seeing
    // no chunks available and claimed we were out of memory.
    //
    // Simple solution is to just put a lock around the page allocation.  All
    // calls to this function are guarenteed, by PageManager::allocatePage, to
    // be from kernel space so we cannot run into any dead lock situations by
    // using a spinlock here.
    //
    // RTC: 98271
    iv_lock.lock();

    PageManagerCore::page_t* page = iv_heap.allocatePage(n);

    iv_lock.unlock();

    // If the allocation came from kernel-space and normal allocation
    // was unsuccessful, pull a page off the reserve heap.
    if ((NULL == page) && (!userspace))
    {
        printkd("PAGEMANAGER: kernel heap used\n");
        page = iv_heapKernel.allocatePage(n);
    }

    // If still not successful, we're out of memory.  Assert.
    if ((NULL == page) && (!userspace))
    {
        register task_t* t;
        asm volatile("mr %0, 13" : "=r"(t));
        printk("Insufficient memory for alloc %zd pages on tid=%d!\n",
               n, t->tid);
        printk("Pages available=%ld\n",iv_pagesAvail);
        kassert(false);
    }

    // Update statistics (only if we actually found a page).
    if( NULL != page )
    {
        __sync_sub_and_fetch(&iv_pagesAvail, n);
        if(iv_pagesAvail < cv_low_page_count)
        {
            cv_low_page_count = iv_pagesAvail;
        }
    }

    return page;
}

void PageManager::_freePage(void* p, size_t n)
{
    iv_heap.freePage(p,n);

    // Update statistics.
    __sync_add_and_fetch(&iv_pagesAvail, n);

    // Keep the reserved page count for the kernel full
    size_t ks = iv_heapKernel.getFreePageCount();
    if(ks < KERNEL_HEAP_RESERVED_PAGES)
    {
        ks = KERNEL_HEAP_RESERVED_PAGES - ks;
        PageManagerCore::page_t * page = iv_heap.allocatePage(ks);
        if(page)
        {
            iv_heapKernel.addMemory(reinterpret_cast<size_t>(page), ks);
        }
    }


    return;
}

PageManagerCore::page_t* PageManagerCore::pop_bucket(size_t i_n)
{
    if (i_n >= BUCKETS) return NULL;

    page_t* p = iv_heap[i_n].pop();

    if (NULL == p)
    {
        // Couldn't allocate from the correct size bucket, so split up an
        // item from the next sized bucket.
        p = pop_bucket(i_n+1);
        if (NULL != p)
        {
            push_bucket((page_t*) (((uint64_t)p) + (PAGESIZE * (1 << i_n))),
                        i_n);
        }
    }
    return p;
}

void PageManagerCore::push_bucket(page_t* i_p, size_t i_n)
{
    if (i_n >= BUCKETS) return;
    iv_heap[i_n].push(i_p);
}

void PageManager::coalesce( void )
{
    Singleton<PageManager>::instance()._coalesce();
}

void PageManager::_coalesce( void )
{
    iv_heap.coalesce();
}

// Coalsesce adjacent free memory blocks
void PageManagerCore::coalesce( void )
{
    // Look at all the "free buckets" and find blocks to merge
    // Since this is binary, all merges will be from the same free bucket
    // Each bucket is a stack of non-allocated memory blocks of the same size
    // Once two blocks are merged they become a single block twice the size.
    // The source blocks must be removed from the current bucket (stack) and
    // the new block needs to be pushed onto the next biggest stack.
    for(size_t bucket = 0; bucket < (BUCKETS-1); ++bucket)
    {
        // Move the this stack bucket into a priority queue
        // sorted by address, highest to lowest
        Util::Locked::PQueue<page_t,page_t*> pq;
        page_t * p = NULL;
        while(NULL != (p = iv_heap[bucket].pop()))
        {
            p->key = p;
            pq.insert(p);
        }

        while(NULL != (p = pq.remove()))
        {
            // p needs to be the even buddy to prevent merging of wrong block.
            // To determine this, get the index of the block as if the whole
            // page memory space were blocks of this size.
            uint64_t p_idx = (reinterpret_cast<uint64_t>(p) - firstPageAddr())/
                             ((1 << bucket)*PAGESIZE);
            if(0 != (p_idx % 2))  // odd index
            {
                iv_heap[bucket].push(p);  // can't merge
            }
            else // it's even
            {
                // If p can be merged then the next block in pq will be the
                // match.  The address of p also can't be greater than what's
                // in pq or something is really messed up, therefore if
                // pq.remove_if() returns something then it's a match.
                page_t * p_seek = (page_t*)((uint64_t)p +
                                            (1 << bucket)*PAGESIZE);
                page_t * p_next = pq.remove_if(p_seek);
                if(p_next == p_seek)
                {
                    // new block is twice the size and goes into the next
                    // bucket size
                    push_bucket(p,bucket+1);
                    ++PageManager::cv_coalesce_count;
                }
                else
                {
                    // Can't merge p
                    iv_heap[bucket].push(p);

                    if(p_next) // This should be null - if then overlaping mem
                    {
                        iv_heap[bucket].push(p_next);
                        printk("pagemgr::coalesce Expected %p, got %p\n",
                               p_seek, p_next);
                    }
                }
            }
        }
    }
    printkd("PAGEMGR coalesced total %ld\n", PageManager::cv_coalesce_count);
    printkd("PAGEMGR low page count %ld\n", PageManager::cv_low_page_count);
}

void PageManager::addMemory(size_t i_addr, size_t i_pageCount)
{
    PageManager& pmgr = Singleton<PageManager>::instance();
    return pmgr._addMemory(i_addr, i_pageCount);
}

// add memory to the heap
void PageManager::_addMemory(size_t i_addr, size_t i_pageCount)
{
    iv_heap.addMemory(i_addr,i_pageCount);

    // Update statistics.
    __sync_add_and_fetch(&iv_pagesAvail, i_pageCount);

    // Update statistics.
    __sync_add_and_fetch(&iv_pagesTotal, i_pageCount);

    return;
}
