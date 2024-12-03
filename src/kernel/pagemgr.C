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
#include <vector>

extern int g_istep;   // used in STRC_KMEM, STRC_KALLOC
extern int g_substep; // used in STRC_KMEM, STRC_KALLOC

size_t get_bucket(size_t i_pageCount)
{
    // return the bucket number for i_pageCount

    // bucket 0 - memory of only 1 page
    // bucket 1 - memory of only 2 pages
    // bucket 2 - memory of 3..4   pages
    // bucket 3 - memory of 5..8   pages
    // bucket 4 - memory of 9..16  pages
    // etc
    // bucket 11 queues memory of 1025 pages or more
    if      (i_pageCount <= 1)      return 0;
    else if (i_pageCount == 2)      return 1;
    else if (i_pageCount <= 4)      return 2;
    else if (i_pageCount <= 8)      return 3;
    else if (i_pageCount <= 16)     return 4;
    else if (i_pageCount <= 32)     return 5;
    else if (i_pageCount <= 64)     return 6;
    else if (i_pageCount <= 128)    return 7;
    else if (i_pageCount <= 256)    return 8;
    else if (i_pageCount <= 512)    return 9;
    else if (i_pageCount <= 1024)   return 10;
    else                            return 11;
}

void PageManager::resetIStepStats()
{
    PageManager& pmgr = Singleton<PageManager>::instance();

    // reset these at the start of each IStep so they tell us the lowest page
    // count hit in each IStep
    pmgr.iv_heap.cv_low_page_count     = pmgr.iv_heap.cv_free_pages;
    pmgr.iv_reserved.cv_low_page_count = pmgr.iv_reserved.cv_free_pages;
}

void PageManager::get_stats(struct kmem_trc_data &o_stats)
{
    PageManager& pmgr = Singleton<PageManager>::instance();

    o_stats.cv_pagesTotal          = pmgr.cv_pagesTotal;
    o_stats.cv_pagesAvail_heap     = pmgr.iv_heap.cv_free_pages;
    o_stats.cv_low_page_count_heap = pmgr.iv_heap.cv_low_page_count;
    o_stats.cv_coalesce_state      = pmgr.iv_heap.cv_coalesce_state;
    o_stats.cv_coalesce_attempts   = pmgr.iv_heap.cv_coalesce_attempts;
    o_stats.cv_coalesce_count      = pmgr.iv_heap.cv_coalesce_count;
    for (int i=0; i<PageManagerCore::BUCKETS; i++)
    {
        o_stats.cv_free_bucket_count_heap[i] =
                    static_cast<uint32_t>(pmgr.iv_heap.cv_free_bucket_count[i]);
    }

    o_stats.cv_allocatePage_usr_wait = pmgr.cv_allocatePage_usr_wait;

    o_stats.cv_pagesAvail_res     = pmgr.iv_reserved.cv_free_pages;
    o_stats.cv_low_page_count_res = pmgr.iv_reserved.cv_low_page_count;

    for (int i=0; i<BUCKETS_RES; i++)
    {
        o_stats.cv_free_bucket_count_res[i] =
                static_cast<uint32_t>(pmgr.iv_reserved.cv_free_bucket_count[i]);
    }
}

void PageManagerCore::addMemory( size_t i_addr, size_t i_pageCount )
{
    size_t  align = ALIGN_PAGE(i_addr);
    page_t *page  = reinterpret_cast<page_t *>(align);

    if (i_pageCount == 0) {return;}        // dont add zero pages
    if (i_addr < align)   {--i_pageCount;} // we rounded up to align, so now its one less page
    if (i_pageCount == 0) {return;}        // dont add zero pages

    STRC1_KLONG(KDBG_PM_ADD_MEMORY, i_addr, i_pageCount);

    // Allocate pages to buckets.
    iv_spinlock.lock();
    push_bucket(page, i_pageCount);
    iv_spinlock.unlock();

    // Only check range if coalesce is allowed
    if (iv_supports_coalesce)
    {
        // Update set of registered heap memory ranges to support heap coalescing.
        // It is a critical error for the last range to already be registered when
        // this API is invoked.
        crit_assert(!iv_ranges.back().first);
        for(auto& range : iv_ranges)
        {
            // Range value of 0 indicates a free range to use, since Hostboot cannot
            // ever start the heap at an address of 0.
            if(!range.first)
            {
                range.first=align;
                range.second=i_pageCount*PAGE_SIZE;
                break;
            }

            // Can't ever start a range at/below that of an existing range.
            if (align <= range.first)
            {
                KTRC0("PageManagerCore::addMemory: ERROR i_addr <= range.first 0x%lx <= 0x%lx\n",
                        align, reinterpret_cast<size_t>(range.first));
            }
            crit_assert(align > range.first);
        }
    }
    __sync_add_and_fetch(&cv_free_pages, i_pageCount);
    return;
}



PageManagerCore::page_t * PageManagerCore::allocatePage( size_t i_pageCount )
{
    size_t  which_bucket = get_bucket(i_pageCount);
    page_t *page;

    page = pop_bucket(i_pageCount);
    if (page)
    {
        __sync_sub_and_fetch(&cv_free_pages, i_pageCount);
        __sync_add_and_fetch(&cv_alloc_sizes[which_bucket], 1);
        if (cv_free_pages < cv_low_page_count)
        {
            cv_low_page_count = cv_free_pages;
        }
    }
    return page;
}

void PageManagerCore::freePage(void*  i_page,
                               size_t i_pageCount)
{
    STRC1_KSHORT(KDBG_PM_FREE_ENTER, PTR_TO_u32(i_page), i_pageCount);

    crit_assert(i_page);
    crit_assert(i_pageCount);

    size_t  which_bucket = get_bucket(i_pageCount);
    page_t *page = reinterpret_cast<page_t*>(i_page);

    page->set_key(i_pageCount); // set so PQueue can sort by size

    if (which_bucket < BUCKETS_LOWER)
    {
        iv_heap_lower[which_bucket].push(page);
    }
    else
    {
        iv_spinlock.lock();
        iv_heap_upper[which_bucket].insert(page);
        iv_spinlock.unlock();
    }

    // Update statistics.
    __sync_add_and_fetch(&cv_free_bucket_count[which_bucket],1);
    __sync_add_and_fetch(&cv_free_pages, i_pageCount);

    STRC1_KSHORT(KDBG_PM_FREE_EXIT, cv_free_pages, 0);
    return;
}

void PageManager::init()
{
    Singleton<PageManager>::instance();
}

void* PageManager::allocatePage_syscall(size_t n)
{
    return  Singleton<PageManager>::instance()._allocatePage(n, true, false);
}

void* PageManager::allocateReservedPage_syscall(size_t n)
{
    return  Singleton<PageManager>::instance().iv_reserved.allocatePage(n);
}

void* PageManager::allocatePage(size_t n, bool userspace, bool kAllowOom)
{
    PageManager &l_pmgr = Singleton<PageManager>::instance();
    void        *page{nullptr};

    if (KernelMisc::in_kernel_mode())
    {
        if (!userspace)
        {
            STRC1_KSHORT(KDBG_PM_ALLOC_KER_ENTER, n, 0);
        }
        page = l_pmgr._allocatePage(n, userspace, kAllowOom);
        if (!userspace)
        {
            STRC1_KSHORT(KDBG_PM_ALLOC_KER_EXIT, (uintptr_t)page, n);
        }
        return page;
    }

    // This section is for requests originating in userspace and running in usr-mode

    STRC1_KSHORT(KDBG_PM_ALLOC_USR_ENTER, n, 0);

    // syscall to run allocatePage in kernel-mode
    page = _syscall1(Systemcalls::MM_ALLOC_PAGES, reinterpret_cast<void*>(n));

    if (NULL == page)
    {
        // The _allocatePage syscall failed, so loop and retry the syscall
        //  until success or until timeoutSecs.
        //
        // At reserveSecs,  one-time:           try iv_reserved, forceMemoryPeriodic
        // At criticalSecs, repeat at interval: try iv_reserved, forceMemoryPeriodic
        // At timeoutSecs,  fail:               assert
        //
        // forceMemoryPeriodic
        //   -does flushPageTable, castOutPages, and PageMgr/HeapMgr coalesce

        const uint64_t reserveSecs  = USR_ALLOC_WAIT_RESERVED;
        const uint64_t criticalSecs = USR_ALLOC_CRIT_PERIODIC;
        const uint64_t timeoutSecs  = USR_ALLOC_WAIT_TIMEOUT;

        uint64_t reserveTicks  = 0;   // ticks to first try the iv_reserved
        uint64_t criticalTicks = 0;   // ticks interval to try the iv_reserved
        uint64_t timeoutTicks  = 0;   // ticks for the timeout

        timeoutTicks  = getTB() + TimeManager::convertSecToTicks(timeoutSecs,0);
        criticalTicks = getTB() + TimeManager::convertSecToTicks(criticalSecs,0);
        reserveTicks  = getTB() + TimeManager::convertSecToTicks(reserveSecs,0);

        // remember each time an allocatePage had to wait
        __sync_add_and_fetch(&l_pmgr.cv_allocatePage_usr_wait, 1);

        // NORMAL PERIODIC
        // we can call this as many times as we like, because this function
        // limits how many periodics are actually run to one per time period
        CpuManager::forceMemoryPeriodic(VmmManager::NORMAL);

        while (NULL == page) // usr-mode wait loop
        {
            // Didn't successfully allocate, so yield in hopes that memory
            // will eventually free up
            task_yield();

            // GET RESERVE
            // One-time attempt shortly after entering the wait loop.
            // Try the iv_reserved and if it fails then send a Critical Periodic
            if (getTB() > reserveTicks)
            {
                page = _syscall1(Systemcalls::MM_ALLOC_RESERVED_PAGES,
                                 reinterpret_cast<void*>(n));
                if (page)
                {
                    STRC1_KALLOC(K_ALLOC_USR_GET_RES, g_istep, g_substep, n);
                    return page;
                }
                STRC1_KLONG(KDBG_PM_USR_GET_RES_FAIL, n, availPages());
                CpuManager::forceMemoryPeriodic(VmmManager::CRITICAL);
                // add timeoutSecs so this section does not run again in the loop
                reserveTicks += TimeManager::convertSecToTicks(timeoutSecs,0);
            }
            // CRITICAL PERIODIC
            // Run this every few seconds
            // Try the iv_reserved and if it fails then send a Critical Periodic
            if (getTB() > criticalTicks)
            {
                STRC1_KLONG(KDBG_PM_PERIODIC_RES_INTERVAL, n, availPages());
                page = _syscall1(Systemcalls::MM_ALLOC_RESERVED_PAGES,
                                 reinterpret_cast<void*>(n));
                if (page)
                {
                    STRC1_KALLOC(K_ALLOC_USR_GET_RES, g_istep, g_substep, n);
                    return page;
                }
                STRC1_KMEM(KMEM_STATS_ALLOC_PG_USR_GET_RES_FAIL, g_istep, g_substep, n);
                CpuManager::forceMemoryPeriodic(VmmManager::CRITICAL);
                // set to run at the next time interval
                criticalTicks += TimeManager::convertSecToTicks(criticalSecs,0);
            }
            // TIMEOUT
            // Check the maximum time allowed for retry
            if (getTB() > timeoutTicks)
            {
                KTRC0("KMEM_STATS_ALLOC_PG_USR_TIMEOUT_ASSERT size: %ld tid:%d\n",
                        n, task_gettid());
                STRC1_KMEM(KMEM_STATS_ALLOC_PG_USR_TIMEOUT_ASSERT,
                           g_istep, g_substep, n);
                MAGIC_INSTRUCTION(MAGIC_BREAK_ON_ERROR);
                KernelMisc::printkBacktrace(nullptr);
                crit_assert(0);
            }

            //  syscall to run allocatePage in kernel-mode
            page = _syscall1(Systemcalls::MM_ALLOC_PAGES, reinterpret_cast<void*>(n));
        }
    }

    STRC1_KSHORT(KDBG_PM_ALLOC_USR_EXIT, (uintptr_t)page, n);
    crit_assert(page); // only do this check in usr-mode
    return page;
}

void PageManager::freePage(void* p, size_t n)
{
    crit_assert(n);
    crit_assert(p);

    if (KernelMisc::in_kernel_mode() || n <= 2)
    {
        // In kernel mode OR p is going into a lower bucket
        // so, its ok to just call and free the page
        Singleton<PageManager>::instance()._freePage(p, n);
        return;
    }
    // In non-kernel mode, make a system-call to freePage in kernel-mode.
    // Do freePage in kernel-mode because it needs iv_spinlock for iv_heap_upper.
    // Do not grab the iv_spinlock in usr space, to avoid deadlock situations
    _syscall2(Systemcalls::MM_FREE_PAGES, p, reinterpret_cast<void*>(n));
}

uint64_t PageManager::queryAvail()
{
    return Singleton<PageManager>::instance()._queryAvail();
}

uint64_t PageManager::availPages()
{
    return Singleton<PageManager>::instance()._availPages();
}

uint64_t PageManager::availPagesRes()
{
    return Singleton<PageManager>::instance()._availPagesRes();
}

uint64_t PageManager::lowPageCount()
{
    return Singleton<PageManager>::instance()._lowPageCount();
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
    DEBUG::add_debug_pointer(DEBUG::PAGEMANAGERINSTANCE,
                             this,
                             sizeof(PageManager));
}

PageManager::PageManager()
{
    this->_initialize();
}

void PageManager::_initialize()
{
    KTRC0("Hostboot base image ends at 0x%lX...\n", firstPageAddr());

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

    KTRC0("PageManager end of preserved area at 0X%lX\n", l_endPreservedArea);
    KTRC0("PageManager page table offset at 0X%lX\n", l_pageTableOffset);
#ifdef CONFIG_AGGRESSIVE_LRU
    KTRC0("CastOutPages AGGRESSIVE LRU\n");
#else
    KTRC0("CastOutPages NORMAL LRU\n");
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

    // Statistics
    cv_pagesTotal             = totalPages;
    iv_heap.cv_low_page_count = iv_heap.cv_free_pages;

    // allocate pages to iv_reserved
    PageManagerCore::page_t *page = iv_heap.allocatePage(HEAP_RESERVED);
    iv_reserved.freePage(page, HEAP_RESERVED); // add pages into iv_reserved
    iv_reserved.cv_low_page_count = iv_reserved.cv_free_pages;

    KTRC0("Total Pages:       %ld\n"
          "iv_heap Pages:     %ld\n"
          "iv_reserved Pages: %ld\n",
            cv_pagesTotal,
            iv_heap.cv_free_pages,
            iv_reserved.cv_free_pages);

    KernelMemState::setMemScratchReg(KernelMemState::MEM_CONTAINED_L3,
                                     g_BlToHbDataManager.getHbCacheSizeMb());
}

void* PageManager::_allocatePage(size_t n, bool userspace, bool allowOom)
{
    PageManagerCore::page_t* page = iv_heap.allocatePage(n);
    if (page)
    {
        return page;
    }

    if (!userspace) // this request originated in kernel-space
    {
        // we are nearly OOM, so do Critical-level Periodics
        //  (flushPageTable, castOutPages, PageMgr/HeapMgr coalesce)
        STRC1_KLONG(KDBG_PM_PERIODIC_KER_MISS, n, availPages());
        CpuManager::forceMemoryPeriodic(VmmManager::CRITICAL);

        // Enter a retry loop and hope the periodics free some memory

        uint64_t timeoutTicks = 0; // tick count when the timeout hits

        timeoutTicks = getTB() + TimeManager::convertSecToTicks(0,KER_ALLOC_WAIT_RESERVED);

        while (getTB() < timeoutTicks) // retry enough times for the Periodics to help
        {
            page = iv_heap.allocatePage(n);
            if (page)
            {
                return page;
            }
        }

        // normal allocation failed, so pull a page off the reserve heap
        page = iv_reserved.allocatePage(n);
        if (page)
        {
            STRC1_KALLOC(K_ALLOC_KER_GET_RES, g_istep, g_substep, n);
            return page;
        }

        // still not successful, we're out of memory.  Assert as long as the
        // caller doesn't want to allow OOM (_pteMiss uses this to avoid deadlocks).
        STRC1_KMEM(KMEM_STATS_ALLOC_PG_KER_GET_RES_FAIL, g_istep, g_substep, n);

        if (!allowOom)
        {
            register task_t* t;
            asm volatile("mr %0, 13" : "=r"(t));
            KTRC0("Insufficient memory for alloc %zd pages on tid=%d!\n", n, t->tid);
            KTRC0("Pages available=%ld\n", iv_heap.cv_free_pages);
            KTRC0("KMEM_STATS_ALLOC_PG_KER_KASSERT size: %ld tid:%d\n", n, t->tid);
            STRC1_KMEM(KMEM_STATS_ALLOC_PG_KER_KASSERT, g_istep, g_substep, n);
            crit_assert(0);
        }
    }

    return page;
}

void PageManager::_freePage(void* p, size_t n)
{
    if (iv_reserved.cv_free_pages < HEAP_RESERVED_LOW_MARK/2) // iv_reserved is VERY low
    {
        // add any sized p to iv_reserved, because we must have some pages
        // reserved to satisfy a PTE miss.
        // AND, if the pages are in iv_reserved rather than the free buckets,
        //  then each allocatePage adds a delay to help survive an OOM.
        iv_reserved.freePage(p,n);  // add p to iv_reserved
        return;
    }

    if (iv_heap.cv_free_pages < HEAP_RESERVED) // iv_heap is very low
    {
        iv_heap.freePage(p,n); // very low memory in the free buckets,
        return;                // so put p in the free buckets before iv_reserved
    }

    if (iv_reserved.cv_free_pages < HEAP_RESERVED)  // iv_reserved needs pages
    {
        if (n >= HEAP_RESERVED_MIN_SIZE) // p is a larger size
        {
            iv_reserved.freePage(p,n); // add p to iv_reserved
            return;
        }
        if (iv_reserved.cv_free_pages < HEAP_RESERVED_LOW_MARK) // iv_reserved is low
        {
            // add any sized p to iv_reserved, because we must have some pages
            // reserved to satisfy a PTE miss.
            iv_reserved.freePage(p,n); // add p to iv_reserved
            return;
        }
    }

    iv_heap.freePage(p,n); // otherwise add p to a free bucket

    return;
}

PageManagerCore::page_t* PageManagerCore::pop_bucket(size_t i_pageCount)
{
    size_t  which_bucket = get_bucket(i_pageCount);
    page_t *p{nullptr};

    if (which_bucket < BUCKETS_LOWER)
    {
        p = pop_bucket_lower(i_pageCount);
    }
    if (!p)
    {
        // Either no page exists for i_pageCount in bucket 0 or 1,
        // or i_pageCount is larger than 2,
        // Go search the buckets under a lock
        // Use a lock to prevent fragmentation, caused when multiple threads
        //  simultaneously pull memory from the upper buckets and split it
        //  into smaller pieces.
        p = pop_bucket_upper(i_pageCount);
    }
    return p;
}

// Note: caller must hold iv_spinlock, if i_pageCount is in an upper bucket
void PageManagerCore::push_bucket(page_t* i_p, size_t i_pageCount)
{
    size_t which_bucket = get_bucket(i_pageCount);

    i_p->set_key(i_pageCount); // set key to the size so PQueue will sort by size

    if (which_bucket < BUCKETS_LOWER)
    {
        iv_heap_lower[which_bucket].push(i_p);
    }
    else
    {
        iv_heap_upper[which_bucket].insert(i_p);
    }
    __sync_add_and_fetch(&cv_free_bucket_count[which_bucket],1);
}

void PageManager::coalesce( void )
{
    if (KernelMisc::in_kernel_mode())
    {
        Singleton<PageManager>::instance()._coalesce();
        return;
    }
    // else, noop
}

void PageManager::_coalesce( void )
{
    iv_heap.coalesce();
}

// Note: caller must hold iv_spinlock to protect iv_heap_upper
void PageManagerCore::do_coalesce(Util::Locked::Queue<page_t> q)
{
    // q contains pages in an iv_range to be merged
    // The page_t addrs in q are sorted, so it is simple to check the sequential
    //  elements in q and see if they can be merged

    // foreach p in q
    //   pull off a buddy from q
    //   if p and buddy can be merged
    //     merge them
    //   if p was not merged OR q is empty
    //     put p into a free bucket
    //     p = q.remove()
    //
    //   else, p was merged with buddy, try to merge p with the next page in q
    page_t   *p;
    page_t   *p_seek;  // start addr of the memory following p
    page_t   *p_buddy; // addr we pulled off q, comparing to p_seek
    size_t    which_bucket;
    uintptr_t addr{0};
    bool      merged{false};
    p = q.remove();
    while (p)
    {
        merged = false;
        addr   = reinterpret_cast<uintptr_t>(p);
        addr  += p->size * PAGESIZE;
        p_seek = reinterpret_cast<page_t*>(addr);
        p_buddy = q.front();
        if ( (p_buddy) && (p_buddy == p_seek) )
        {
            // merge p and buddy
            p->size = p->size + p_buddy->size;
            p->key  = p->size;
            q.remove(); // remove merged buddy
            merged = true;
            __sync_add_and_fetch(&cv_coalesce_count,1);
        }

        if ( (!merged) || (q.size() == 0) )
        {
            // p could not be merged OR we are done merging,
            // so place p into a free bucket

            which_bucket = get_bucket(p->size);
            p->key       = p->size; // set key to size so PQueue can sort by size

            if (which_bucket < BUCKETS_LOWER)
            {
                iv_heap_lower[which_bucket].push(p);
            }
            else
            {
                iv_heap_upper[which_bucket].insert(p);
            }
            __sync_add_and_fetch(&cv_free_bucket_count[which_bucket],1);
            p = q.remove();
        }
    }
}

void PageManagerCore::coalesce( void )
{
    if (!iv_supports_coalesce)
    {
        return;
    }

    STRC1_KSHORT(KDBG_PM_COALESCE_ENTER, cv_coalesce_attempts, cv_coalesce_state);

    if (cv_free_pages <= 1) {return;}

    if (!KernelMisc::in_kernel_mode())
    {
        return;
    }

    int l_running = __sync_val_compare_and_swap(&cv_coalesce_state,0,1);
    if (l_running)
    {
        // a coalesce is already running,
        //  so rather than queueing up another thread to run another coalesce
        //  after the one in progress, kick this thread out
        return;
    }

    // Calculate the ending addrs of the ranges
    // Do this before we grab the iv_spinlock, because vector will allocate
    // from the heap and cause a deadlock
    std::vector<uint64_t> ranges;
    for (auto &range : iv_ranges)
    {
        if (!range.first) continue;
        ranges.push_back(range.first+range.second-1);
    }
    std::sort(ranges.begin(), ranges.end());

    // grab lock
    // move all free memory from lower buckets to pq
    // move all free memory from upper buckets to pq
    // foreach range in iv_range
    //   pull off memory from pq in the addr range and insert into q_range
    //   call do_coalesce to merge the memory in q_range
    // free lock

    iv_spinlock.lock(); // mutex with allocatePage

    STRC1_KSHORT(KDBG_PM_COALESCE_START, cv_coalesce_attempts, cv_coalesce_count);

    __sync_add_and_fetch(&cv_coalesce_attempts, 1);

    Util::Locked::PQueue<page_t,uint64_t> pq;
    page_t *p;
    size_t bucket{0};
    do // put lower bucket pages into q
    {
        while ((p=iv_heap_lower[bucket].pop()))
        {
            // set key and size differently for the coalesce
            // pqueue does the sort using key, so move size from key and set key to addr of p
            p->size = p->key;  // move the size from key to size
            p->set_key(p);     // set key to addr of p, so pqueue sorts by addr
            pq.insert(p);      // insert and sort by key
            __sync_sub_and_fetch(&cv_free_bucket_count[bucket],1);
        }
    } while (++bucket < BUCKETS_LOWER);
    do // put upper bucket pages into q
    {
        while ((p=iv_heap_upper[bucket].remove()))
        {
            // set key and size differently for the coalesce
            // pqueue does the sort using key, so move size from key and set key to addr of p
            p->size = p->key;  // move the size from key to size
            p->set_key(p);     // set key to addr of p, so pqueue sorts by addr
            pq.insert(p);      // insert and sort by key
            __sync_sub_and_fetch(&cv_free_bucket_count[bucket],1);
        }
    } while (++bucket < BUCKETS_UPPER);

    // colaesce the different ranges separately
    for (auto &range : ranges)
    {
        Util::Locked::Queue<page_t> q_range; // dont need a PQueue to sort again, already sorted
        while ((p=pq.remove_if(range)))      // remove tail if less than range,
        {                                    // which means the page is inside this iv_range
            q_range.insert(p);
        }
        do_coalesce(q_range);
    }

    STRC1_KSHORT(KDBG_PM_COALESCE_EXIT, cv_coalesce_attempts, cv_coalesce_count);

    iv_spinlock.unlock();
    __sync_sub_and_fetch(&cv_coalesce_state, 1);
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
    __sync_add_and_fetch(&cv_pagesTotal, i_pageCount);

    return;
}

// Note: caller must hold iv_spinlock, if size_remaining is in an upper bucket
void PageManagerCore::check_remain(page_t *i_page, size_t i_pageCount)
{
    size_t size_of_page = i_page->key;
    if (size_of_page > i_pageCount)
    {
        // there are extra pages, so chop them off and add into a free bucket
        uintptr_t addr = reinterpret_cast<uintptr_t>(i_page);
        addr += i_pageCount * PAGESIZE;
        page_t *page_remaining = reinterpret_cast<page_t*>(addr);
        size_t  size_remaining = size_of_page - i_pageCount;
        push_bucket(page_remaining, size_remaining);
    }
}

PageManagerCore::page_t* PageManagerCore::pop_bucket_lower(size_t i_pageCount)
{
    size_t  which_bucket = get_bucket(i_pageCount);
    page_t *page{nullptr};

    while ( (!page) && (which_bucket < BUCKETS_LOWER) )
    {
        page = iv_heap_lower[which_bucket].pop();
        if (!page)
        {
            ++which_bucket;
        }
    }
    if (page)
    {
        __sync_sub_and_fetch(&cv_free_bucket_count[which_bucket],1);
        check_remain(page, i_pageCount);
        page->set_key(i_pageCount); // ensure size is correct, in case there was extra
    }
    return page;
}

PageManagerCore::page_t* PageManagerCore::pop_bucket_upper(size_t i_pageCount)
{
    size_t  which_bucket = get_bucket(i_pageCount);
    page_t *page{nullptr};

    iv_spinlock.lock();

    if (which_bucket < BUCKETS_LOWER)
    {
        // retry the lower buckets, since the initial attempt in pop_bucket() could
        // have found the lower buckets empty, but now memory might be there
        page = pop_bucket_lower(i_pageCount);
    }

    while (!page && which_bucket < BUCKETS_UPPER)
    {
        // Either no page exists for i_pageCount in bucket 0 or 1,
        // or i_pageCount is larger than 2,
        // Search the upper buckets
        page = iv_heap_upper[which_bucket].remove_match(i_pageCount);
        if (page)
        {
            __sync_sub_and_fetch(&cv_free_bucket_count[which_bucket],1);
        }
        ++which_bucket;
    }

    if (page)
    {
        check_remain(page, i_pageCount);
        page->set_key(i_pageCount); // ensure size is correct, in case there was extra
    }

    iv_spinlock.unlock();
    return page;
}
