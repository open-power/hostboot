/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/pagemgr.C $                                        */
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

/**
 * @file pagemgr.C
 *
 * @brief Implementations of PageManagerCore class and functions;
 *        PageManagerCore manipulates memory pages.
 */

#include <limits.h>
#include <kernel/pagemgr.H>
#include <kernel/heapmgr.H>
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
#include <kernel/timemgr.H>
#include <kernel/simpletrace.H>

uint64_t PageManager::cv_reserved_pages_available{0};
uint64_t PageManager::cv_pagesTotal{0};
uint64_t PageManager::cv_pagesAvail{0};
uint64_t PageManager::cv_coalesce_state{0};
uint64_t PageManager::cv_coalesce_attempts{0};
uint64_t PageManager::cv_coalesce_count = 0;
uint64_t PageManager::cv_low_page_count = -1;
uint64_t PageManager::cv_allocatePage_coalesce_wait = 0;
uint64_t PageManager::cv_free_bucket_count[PageManagerCore::BUCKETS]=
                                              {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void PageManager::get_stats(struct kmem_trc_data &o_stats)
{
    o_stats.cv_pagesTotal                 = cv_pagesTotal;
    o_stats.cv_pagesAvail                 = cv_pagesAvail;
    o_stats.cv_coalesce_attempts          = cv_coalesce_attempts;
    o_stats.cv_coalesce_count             = cv_coalesce_count;
    o_stats.cv_low_page_count             = cv_low_page_count;
    o_stats.cv_allocatePage_coalesce_wait = cv_allocatePage_coalesce_wait;
    o_stats.cv_reserved_pages_available   = cv_reserved_pages_available;
    for (int i=0; i<PageManagerCore::BUCKETS; i++)
    {
        o_stats.cv_free_bucket_count[i] = static_cast<uint32_t>(cv_free_bucket_count[i]);
    }
}

void PageManagerCore::addMemory( size_t i_addr, size_t i_pageCount )
{
    size_t length = i_pageCount;
    page_t* page = reinterpret_cast<page_t *>(ALIGN_PAGE(i_addr));

    KTRC1("PageManagerCore::addMemory: i_addr:%lx i_pageCount:%ld\n",
            i_addr, i_pageCount);

    // Allocate pages to buckets.
    size_t page_length = BUCKETS-1;
    while(length > 0)
    {
        while (length < (size_t)(1 << page_length))
        {
            page_length--;
        }

        __sync_add_and_fetch(&PageManager::cv_free_bucket_count[page_length],1);

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
    else
    {
        if (i_pageCount > 1)
        {
            kalloc_trc_data_t l_data{0};
            l_data.bucket_size    = bucket_size;
            l_data.which_bucket   = which_bucket;
            l_data.page_count     = i_pageCount;
            l_data.stats_count    = PageManager::cv_free_bucket_count[which_bucket];
            l_data.coalesce_state = PageManager::cv_coalesce_state;
            l_data.first          = iv_heap[which_bucket].first();
            STRC_KALLOC(K_ALLOC_PAGES_FAIL, l_data);
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

    STRC_KMEM_INIT   (KMEMSTATS_SIZE, BASE_FORMAT);
    STRC_KALLOC_INIT (KALLOC_SIZE,    BASE_FORMAT);
}

void* PageManager::allocatePage(size_t n, bool userspace, bool kAllowOom)
{
    void* page = NULL;

    // In non-kernel mode, make a system-call to allocate in kernel-mode.
    if (!KernelMisc::in_kernel_mode())
    {
        page = _syscall1(Systemcalls::MM_ALLOC_PAGES,
                         reinterpret_cast<void*>(n));
        if (NULL == page)
        {
            KTRC1("PageManager::allocatePage: WAIT size:%ld tid:%d\n", n, task_gettid());

            // The alloc pages syscall failed, so loop and retry the syscall
            // until success or until timeoutSecs.
            // At every coalesceSecs, do a coalesce.
            // At every evictSecs, do a forceMemoryPeriodic.

            uint64_t timeoutSecs   = 180; // total seconds to retry
            uint64_t coalesceSecs  = 5;   // interval to invoke a coalesce
            uint64_t evictSecs     = 20;  // interval to invoke an evict
            uint64_t curTicks      = 0;   // ticks taken at every loop iteration
            uint64_t timeoutTicks  = 0;   // tick count when the timeout hits
            uint64_t coalesceTicks = 0;   // tick count when a coalesce is invoked
            uint64_t evictTicks    = 0;   // tick count when an evict is invoked

            curTicks      = getTB();
            timeoutTicks  = curTicks + TimeManager::convertSecToTicks(timeoutSecs,0);
            coalesceTicks = curTicks + TimeManager::convertSecToTicks(coalesceSecs,0);
            evictTicks    = curTicks + TimeManager::convertSecToTicks(evictSecs,0);

            while (NULL == page)
            {
                // Didn't successfully allocate, so yield in hopes that memory
                // will eventually free up (ex. VMM flushes).
                task_yield();

                curTicks = getTB();

                // TIMEOUT
                // Check the maximum time allowed for retry
                if (curTicks > timeoutTicks)
                {
                    KTRC0( "PageManager::allocatePage: TIMEOUT size:%ld tid:%d\n",
                            n, task_gettid() );
                    STRC_KMEM(STRC_L0, KMEM_STATS_ALLOC_PAGE_OOM_TIMEOUT, n);
                    MAGIC_INSTRUCTION(MAGIC_BREAK_ON_ERROR);
                    KernelMisc::printkBacktrace(nullptr);
                    crit_assert(0);
                }
                // DEFRAG
                // Check to force a defrag of the memory
                if (curTicks > coalesceTicks)
                {
                    KTRC0( "PageManager::allocatePage: COALESCE size:%ld tid:%d\n",
                             n, task_gettid() );
                    coalesce();
                    ++PageManager::cv_allocatePage_coalesce_wait;
                    coalesceTicks += TimeManager::convertSecToTicks(coalesceSecs,0);
                    STRC_KMEM(STRC_L1, KMEM_STATS_ALLOC_PAGE_OOM_COALESCE, n);
                }
                // EVICT
                // Check to evict some pages
                if (curTicks > evictTicks)
                {
                    KTRC0( "PageManager::allocatePage: PERIODICS size:%ld tid:%d!\n",
                             n, task_gettid() );
                    CpuManager::forceMemoryPeriodic();
                    evictTicks += TimeManager::convertSecToTicks(evictSecs,0);
                    STRC_KMEM(STRC_L1, KMEM_STATS_ALLOC_PAGE_OOM_DEFRAG, n);
                }

                page = _syscall1(Systemcalls::MM_ALLOC_PAGES,
                                 reinterpret_cast<void*>(n));
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
    PageManager& pmgr = Singleton<PageManager>::instance();
    pmgr._addDebugPointers();
}

void PageManager::_addDebugPointers()
{
    DEBUG::add_debug_pointer(DEBUG::PAGEMANAGERBUCKETS,
                             &this->iv_heap,
                             sizeof(this->iv_heap));
    DEBUG::add_debug_pointer(DEBUG::PAGEMANAGERKERNRESAVAIL,
                             &PageManager::cv_reserved_pages_available,
                             sizeof(PageManager::cv_reserved_pages_available));
    DEBUG::add_debug_pointer(DEBUG::PAGEMANAGERPAGESTOTAL,
                             &PageManager::cv_pagesTotal,
                             sizeof(PageManager::cv_pagesTotal));
    DEBUG::add_debug_pointer(DEBUG::PAGEMANAGERPAGESAVAIL,
                             &PageManager::cv_pagesAvail,
                             sizeof(PageManager::cv_pagesAvail));
    DEBUG::add_debug_pointer(DEBUG::PAGEMANAGERLOWPAGECOUNT,
                             &PageManager::cv_low_page_count,
                             sizeof(PageManager::cv_low_page_count));
    DEBUG::add_debug_pointer(DEBUG::PAGEMANAGERCOALSTATE,
                             &PageManager::cv_coalesce_state,
                             sizeof(PageManager::cv_coalesce_state));
    DEBUG::add_debug_pointer(DEBUG::PAGEMANAGERCOALATTEMPTS,
                             &PageManager::cv_coalesce_attempts,
                             sizeof(PageManager::cv_coalesce_attempts));
    DEBUG::add_debug_pointer(DEBUG::PAGEMANAGERCOALESCECOUNT,
                             &PageManager::cv_coalesce_count,
                             sizeof(PageManager::cv_coalesce_count));
    DEBUG::add_debug_pointer(DEBUG::PAGEMANAGERALLOCCOUNT,
                             &PageManager::cv_allocatePage_coalesce_wait,
                             sizeof(PageManager::cv_allocatePage_coalesce_wait));
    DEBUG::add_debug_pointer(DEBUG::PAGEMANAGERFREEBUCKETS,
                             PageManager::cv_free_bucket_count,
                             sizeof(PageManager::cv_free_bucket_count));
}

PageManager::PageManager() : iv_lock()
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

    // Reserve pages for the kernel.
    iv_heapKernel.addMemory(reinterpret_cast<uint64_t>(
                            iv_heap.allocatePage(KERNEL_HEAP_RESERVED_PAGES)),
                            KERNEL_HEAP_RESERVED_PAGES);
    cv_reserved_pages_available = KERNEL_HEAP_RESERVED_PAGES;

    // Statistics
    cv_pagesTotal     = totalPages;
    cv_pagesAvail     = totalPages - KERNEL_HEAP_RESERVED_PAGES;
    cv_low_page_count = cv_pagesAvail;

    printk("%ld pages.\n", totalPages);

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

    if (page)
    {
        // Update statistics
        __sync_sub_and_fetch(&cv_pagesAvail, n);
        if(cv_pagesAvail < cv_low_page_count)
        {
            cv_low_page_count = cv_pagesAvail;
        }
    }

    // If the allocation came from kernel-space and normal allocation
    // was unsuccessful, pull a page off the reserve heap.
    if ((NULL == page) && (!userspace))
    {
        STRC_KMEM(STRC_L0, KMEM_STATS_ALLOC_PAGE_OOM_FIRST_FAIL, n);
        printkd("PAGEMANAGER: kernel heap used\n");
        page = iv_heapKernel.allocatePage(n);
        if (page)
        {
            __sync_sub_and_fetch(&cv_reserved_pages_available, n);
        }
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
        printk("Pages available=%ld\n",cv_pagesAvail);

        STRC_KMEM(STRC_L0, KMEM_STATS_ALLOC_PAGE_OOM_SECOND_FAIL, n);

        if (!allowOom)
        {
            STRC_KMEM(STRC_L0, KMEM_STATS_ALLOC_PAGE_OOM_KASSERT, n);
            kassert(false);
        }
    }

    return page;
}

void PageManager::_freePage(void* p, size_t n)
{
    iv_heap.freePage(p,n);

    // Keep the reserved page count for the kernel full
    size_t ks = cv_reserved_pages_available;
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
            __sync_add_and_fetch(&cv_reserved_pages_available, ks);
        }
    }
    else
    {
        // Update statistics.
        __sync_add_and_fetch(&cv_pagesAvail, n);
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
    else
    {
        __sync_sub_and_fetch(&PageManager::cv_free_bucket_count[i_n],1);
    }
    return p;
}

void PageManagerCore::push_bucket(page_t* i_p, size_t i_n)
{
    if (i_n >= BUCKETS) return;
    __sync_add_and_fetch(&PageManager::cv_free_bucket_count[i_n],1);

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
        KTRC1("PageManagerCore::coalesce: not supported for this instance\n");
        return;
    }
    __sync_add_and_fetch(&PageManager::cv_coalesce_state, 1);
    __sync_add_and_fetch(&PageManager::cv_coalesce_attempts, 1);
    KTRC1("PageManagerCore: RUN COALESCE\n");

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

            __sync_sub_and_fetch(&PageManager::cv_free_bucket_count[bucket],1);
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
                push_bucket(p,bucket);
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
                    push_bucket(p,bucket);

                    if(p_next) // This should be null - if then overlaping mem
                    {
                        iv_heap[bucket].push(p_next);
                        KTRC0("pagemgr::coalesce Expected %p, got %p\n",
                               p_seek, p_next);
                    }
                }
            }
        }
    }
    __sync_sub_and_fetch(&PageManager::cv_coalesce_state, 1);
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
    __sync_add_and_fetch(&cv_pagesAvail, i_pageCount);

    // Update statistics.
    __sync_add_and_fetch(&cv_pagesTotal, i_pageCount);

    return;
}

