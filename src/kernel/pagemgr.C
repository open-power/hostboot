/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/pagemgr.C $                                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2010,2022                        */
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

/**
 * @file pagemgr.C
 *
 * @brief Implementations of PageManagerCore class and functions;
 *        PageManagerCore manipulates memory pages.
 */

#include <limits.h>
#include <kernel/pagemgr.H>
#include <util/singleton.H>
#include <kernel/console.H>
#include <arch/ppc.H>
#include <arch/magic.H>
#include <util/locked/pqueue.H>
#include <kernel/task.H>
#include <kernel/taskmgr.H>
#include <kernel/vmmmgr.H>
#include <sys/task.h>
#include <kernel/misc.H>
#include <sys/syscall.h>
#include <assert.h>
#include <kernel/memstate.H>
#include <kernel/bltohbdatamgr.H>
#include <kernel/misc.H>
#include <usr/debugpointers.H>
#include <kernel/cpumgr.H>
#include <usr/vmmconst.h>
#include <kernel/spte.H>

size_t PageManager::cv_coalesce_count = 0;
size_t PageManager::cv_low_page_count = -1;
size_t PageManager::cv_alloc_coalesce_count = 0;

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

    // Only check range if coalesce is allowed
    if (iv_supports_coalesce)
    {
        // Update set of registered heap memory ranges to support heap coalescing.
        // It is a critical error for the last range to already be registered when
        // this API is invoked.
        kassert(!iv_ranges.back().first);
        for(auto& range : iv_ranges)
        {
            // Range value of 0 indicates a free range to use, since Hostboot cannot
            // ever start the heap at an address of 0.
            if(!range.first)
            {
                range.first=i_addr;
                range.second=i_pageCount*PAGE_SIZE;
                break;
            }

            // Can't ever start a range at/below that of an existing range.
            if (i_addr <= range.first)
            {
                printk("i_addr <= range.first 0x%lx <= 0x%lx\n", i_addr, (size_t)range.first);
            }
            kassert(i_addr > range.first);
        }
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
                     bucket_size - i_pageCount,true);
        }
    }

    return page;
}



void PageManagerCore::freePage(
    void*  i_page,
    size_t i_pageCount,
    bool   i_overAllocated)
{
    if ((NULL == i_page) || (0 == i_pageCount)) return;

    size_t which_bucket = ((sizeof(size_t)*8 - 1) -
                                __builtin_clzl(i_pageCount));
    size_t bucket_size = ((size_t)1) << which_bucket;

    push_bucket(
           (page_t*)(reinterpret_cast<uintptr_t>(i_page)
         + (i_overAllocated ? ((i_pageCount-bucket_size)*PAGESIZE) : 0)),
         which_bucket);

    // Update statistics.
    __sync_add_and_fetch(&iv_available, bucket_size);

    // Buckets are 2^k in size so if i_pageCount is not 2^k we have some
    // spare pages to free.  ie. the non-2^k portion of i_pageCount.
    if (bucket_size != i_pageCount)
    {
        freePage(
            reinterpret_cast<void*>(
                  reinterpret_cast<uintptr_t>(i_page)
                + (i_overAllocated ? 0 : (bucket_size*PAGESIZE))),
            i_pageCount - bucket_size, i_overAllocated);
    }

    return;
}



void PageManager::init()
{
    Singleton<PageManager>::instance();
}

void* PageManager::allocatePage(size_t n, bool userspace, bool kAllowOom)
{
    void* page = NULL;

    // In non-kernel mode, make a system-call to allocate in kernel-mode.
    if (!KernelMisc::in_kernel_mode())
    {
        size_t l_attempts = 0;
        while (NULL == page)
        {
            page = _syscall1(Systemcalls::MM_ALLOC_PAGES,
                             reinterpret_cast<void*>(n));

            // Didn't successfully allocate, so yield in hopes that memory
            // will eventually free up (ex. VMM flushes).
            constexpr size_t MAX_ATTEMPTS = 10000;
            if (NULL == page)
            {
                l_attempts++;
                if( l_attempts == MAX_ATTEMPTS )
                {
                    printk( "Cannot allocate %ld pages to %d!\n",
                            n, task_gettid() );
                    MAGIC_INSTRUCTION(MAGIC_BREAK_ON_ERROR);
                    KernelMisc::printkBacktrace(nullptr);
                    crit_assert(0);
                }

                task_yield();

                // Force a defrag of the memory 10 times
                if( l_attempts % (MAX_ATTEMPTS/10) == 0 )
                {
                    printkd( "Forcing coalesce to allocate %ld pages to %d!\n",
                             n, task_gettid() );
                    coalesce();
                    ++PageManager::cv_alloc_coalesce_count;
                }

                // Try to evict some pages once
                if( l_attempts == MAX_ATTEMPTS/2 )
                {
                    printkd( "Forcing periodics to allocate %ld pages to %d!\n",
                             n, task_gettid() );
                    CpuManager::forceMemoryPeriodic();
                }
            }
        }
    }
    else
    {
        // In kernel mode.  Do a normal call to the PageManager.
        PageManager& pmgr = Singleton<PageManager>::instance();
        page = pmgr._allocatePage(n, userspace, kAllowOom);
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

bool PageManager::isSmallMemEnv()
{
    return Singleton<PageManager>::instance()._isSmallMemEnv();
}

void PageManager::addDebugPointers()
{
    return Singleton<PageManager>::instance()._addDebugPointers();
}

PageManager::PageManager()
    : iv_pagesAvail(0), iv_pagesTotal(0), iv_lock()
{
    this->_initialize();
}

void PageManager::_initialize()
{
    printk("Hostboot base image ends at 0x%lX...\n", firstPageAddr());

    uint64_t totalPages = 0;
    // Extend memory footprint
    // There is a preserved area after the base image and boot loader to HB
    // communication area. The page table must be 256KB aligned, so it is
    // likely to not be flush against the preserved area end.
    // Example:
    //      [HBB max size][BlToHBData][8 byte aligned]
    //      [128 byte aligned Preserved-area][256K aligned Page Table]
    uint64_t l_endPreservedArea = VmmManager::endPreservedOffset();
    uint64_t l_endInitCache = VmmManager::SINGLE_CACHE_SIZE_BYTES;
    uint64_t l_pageTableOffset = VmmManager::pageTableOffset();
    uint64_t l_endPageTable = l_pageTableOffset + VmmManager::PTSIZE;

    printk("PageManager end of preserved area at 0X%lX\n", l_endPreservedArea);
    printk("PageManager page table offset at 0X%lX\n", l_pageTableOffset);
#ifdef CONFIG_AGGRESSIVE_LRU
    printk("CastOutPages AGGRESSIVE LRU\n");
#else
    printk("CastOutPages NORMAL LRU\n");
#endif

    // Populate half the cache after the preserved area
    KernelMisc::populate_cache_lines(
                                reinterpret_cast<uint64_t*>(l_endPreservedArea),
                                reinterpret_cast<uint64_t*>(l_endInitCache));

    // Allocate heap memory between end of preserved area and start of page
    // table, if necessary
    uint64_t pages = 0;
    if ( (l_pageTableOffset - l_endPreservedArea) > 0 )
    {
        pages = (l_pageTableOffset - l_endPreservedArea) / PAGESIZE;
        iv_heap.addMemory(l_endPreservedArea, pages);
        totalPages += pages;
    }
    // After the Page table
    pages = (l_endInitCache - l_endPageTable) / PAGESIZE;
    iv_heap.addMemory(l_endPageTable, pages);
    totalPages += pages;

#ifndef CONFIG_VPO_COMPILE // In VPO, the size of the cache is 4MB; trying to
                           // execute this code (that attempts to zero out 0
                           // amount of memory) causes crashes
    KernelMisc::populate_cache_lines(
        reinterpret_cast<uint64_t*>(l_endInitCache),
        reinterpret_cast<uint64_t*>(g_BlToHbDataManager.getHbCacheSizeBytes()));

    // Reserve enough memory to fit the OCC BL at 4MB into the cache. For more
    // details, see src/usr/isteps/pm/occCheckstop.C::loadOCCImageDuringIpl()
    l_endInitCache += VMM_OCC_BOOTLOADER_SIZE; // Skip enough to fit OCC BL
    pages = (g_BlToHbDataManager.getHbCacheSizeBytes() - l_endInitCache) /
            PAGESIZE;
    iv_heap.addMemory(l_endInitCache, pages);
    totalPages += pages;
#endif

    printk("%ld pages.\n", totalPages);

    // Statistics
    iv_pagesTotal = totalPages;
    iv_pagesAvail = totalPages;
    cv_low_page_count = totalPages;

    // Reserve pages for the kernel.
    iv_heapKernel.addMemory(reinterpret_cast<uint64_t>(
                              iv_heap.allocatePage(KERNEL_HEAP_RESERVED_PAGES)),
                            KERNEL_HEAP_RESERVED_PAGES);

    KernelMemState::setMemScratchReg(KernelMemState::MEM_CONTAINED_L3,
                                     g_BlToHbDataManager.getHbCacheSizeMb());
}

void* PageManager::_allocatePage(size_t n, bool userspace, bool allowOom)
{
    // The allocator was designed to be lockless.  We have ran into a problem
    // in Brazos where all threads (over 256) were trying to allocate a page
    // at the same time.  This resulted in many of them trying to break a large
    // page chunk into smaller fragments.  The later threads ended up seeing
    // no chunks available and claimed we were out of memory.
    //
    // Simple solution is to just put a lock around the page allocation.  All
    // calls to this function are guaranteed, by PageManager::allocatePage, to
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

        // Any time we dip into the kernel heap we should start
        //  evicting user pages
        CpuManager::forceMemoryPeriodic();
    }

    // If still not successful, we're out of memory.  Assert as long as the
    // caller doesn't want to allow OOM (_pteMiss uses this to avoid deadlocks).
    if ((NULL == page) && (!userspace))
    {
        register task_t* t;
        asm volatile("mr %0, 13" : "=r"(t));
        printk("Insufficient memory for alloc %zd pages on tid=%d!\n",
               n, t->tid);
        printk("Pages available=%ld\n",iv_pagesAvail);

        if (!allowOom)
        {
            kassert(false);
        }
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
        // Only request single page at a time to assure
        // page is reclaimed, if too many pages requested
        // the proper bucket size may not have availability
        // during high pressure memory demands
        ks = 1;
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
    if (!iv_supports_coalesce)
    {
        printkd("PAGEMGRCORE coalesce not supported for this instance\n");
        return;
    }

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
            // p needs to be the even buddy to prevent merging of wrong blocks.
            // To determine this, get the index of the block as if the whole
            // page memory space were blocks of this size.  Note: have to
            // take into account the page manager "hole" in the middle of the
            // initial memory allocation.  Also have to ignore the OCC
            // bootloader page at the start of the third memory range (which
            // accounts for the rest of the initial cache), and the SPTE entries
            // at the start of the 4th memory range (which accounts for the rest
            // of the Hostboot memory footprint).
            uint64_t p_idx = 0;
            const auto addr = reinterpret_cast<uint64_t>(p);
            bool found=false;
            for(const auto& range : iv_ranges)
            {
                if(   (addr >= range.first)
                   && (addr < (range.first + range.second)) )
                {
                    p_idx = (addr - range.first) / ((1 << bucket)*PAGESIZE);
                    found=true;
                    break;
                }
            }
            // Critical error if we didn't map into a known/registered address
            // range.
            kassert(found);

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

void PageManager::_addDebugPointers()
{
    DEBUG::add_debug_pointer(DEBUG::PAGEMANAGER,
                             this,
                             sizeof(PageManager));
    DEBUG::add_debug_pointer(DEBUG::PAGEMANAGERLOWPAGECOUNT,
                             &PageManager::cv_low_page_count,
                             sizeof(PageManager::cv_low_page_count));
    DEBUG::add_debug_pointer(DEBUG::PAGEMANAGERCOALESCECOUNT,
                             &PageManager::cv_coalesce_count,
                             sizeof(PageManager::cv_coalesce_count));
    DEBUG::add_debug_pointer(DEBUG::PAGEMANAGERALLOCCOUNT,
                             &PageManager::cv_alloc_coalesce_count,
                             sizeof(PageManager::cv_alloc_coalesce_count));
}
