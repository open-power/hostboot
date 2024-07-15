/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/block.C $                                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2024                        */
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
#include "arch/magic.H"
#include "sys/mm.h"
#include <limits.h>
#include <assert.h>
#include <string.h>
#include <errno.h>

#include <sys/msg.h>

#include <util/align.H>

#include <kernel/block.H>
#include <kernel/spte.H>
#include <kernel/vmmmgr.H>
#include <kernel/ptmgr.H>
#include <kernel/pagemgr.H>
#include <kernel/console.H>
#include <util/align.H>
#include <kernel/basesegment.H>
#include <arch/ppc.H>

#include <usr/vmmconst.h>

#include <usr/debugpointers.H>
#include <kernel/bltohbdatamgr.H>
#include <kernel/simpletrace.H>

uint64_t Block::cv_pages_allocated{0};
uint64_t Block::cv_pages_allocated_peak{0};
uint64_t Block::cv_pages_allocated_count{0};

// Track eviction requests due to aging pages
uint64_t Block::cv_ro_evict_req = 0;
uint64_t Block::cv_rw_evict_req = 0;

void Block::get_stats(struct kmem_trc_data &o_stats)
{
    o_stats.cv_pages_allocated       = cv_pages_allocated;
    o_stats.cv_pages_allocated_peak  = cv_pages_allocated_peak;
    o_stats.cv_pages_allocated_count = cv_pages_allocated_count;
    o_stats.cv_ro_evict_req          = cv_ro_evict_req;
    o_stats.cv_rw_evict_req          = cv_rw_evict_req;
}

Block::~Block()
{
    // Release shadow PTE array.
    delete[] iv_ptes;
    //Release message handlers
    delete iv_readMsgHdlr;
    delete iv_writeMsgHdlr;

    // Delete next block in the chain.
    if (iv_nextBlock)
    {
        delete iv_nextBlock;
    }
}

void Block::init(MessageQueue* i_msgQ, uint64_t *i_spteAddr)
{

    if (i_spteAddr == NULL)
    {
        // Create a shadow PTE for each page.
        iv_ptes = new ShadowPTE[iv_size / PAGESIZE]();
    }
    else // set the page table to reside at the address requested
    {
        // Doing a placement new to put the SPTE at the beginging
        // of the block we allocated.
        iv_ptes = new(i_spteAddr) ShadowPTE[iv_size / PAGESIZE];
    }

    if (i_msgQ != NULL)
    {
        //Create message handler to handle read operations for this block
        this->iv_readMsgHdlr =
                new BlockReadMsgHdlr(VmmManager::getLock(),i_msgQ,this);
        //Create message handler to handle write operations for this block
        this->iv_writeMsgHdlr =
                new BlockWriteMsgHdlr(VmmManager::getLock(),i_msgQ,this);
    }
}

ShadowPTE* Block::getPTE(uint64_t i_addr) const
{
    return &iv_ptes[(i_addr - iv_baseAddr) / PAGESIZE];
};


bool Block::handlePageFault(task_t* i_task, uint64_t i_addr, bool i_store, bool* o_oom)
{
    // Check containment, call down chain if address isn't in this block.
    if (!isContained(i_addr))
    {
        return (iv_nextBlock ?
                iv_nextBlock->handlePageFault(i_task, i_addr, i_store, o_oom) :
                false);
    }

    // Calculate page aligned virtual address.
    uint64_t l_addr_palign = (i_addr / PAGESIZE) * PAGESIZE;

    ShadowPTE* pte = getPTE(l_addr_palign);

    // If the page table entry has default permission settings
    if (getPermission(pte) == NO_ACCESS)
    {
      printkd("handle page fault.. Permission not set for addr =  0x%.lX\n",
              (uint64_t)l_addr_palign);
      // return false because permission have not been set.
      return false;
    }

    // Mark the page as dirty if this is a store to it.
    if (i_store)
    {
        if (pte->isWritable())
        {
            pte->setDirty(true);
        }
        else // Store to non-writable page!  This is a permission fault, so
             // return unhandled.
        {
            return false;
        }
    }

    const bool allowOom = o_oom != nullptr;

    if (!pte->isPresent())
    {
        if (this->iv_readMsgHdlr != NULL)
        {
            void* l_page = reinterpret_cast<void*>(pte->getPageAddr());
            //If the page data is zero, create the page
            if (pte->getPage() == 0)
            {
                l_page = PageManager::allocatePage(1, false, allowOom);

                if (l_page == nullptr)
                {
                    *o_oom = true;
                    return false;
                }
                __sync_add_and_fetch(&cv_pages_allocated,1);
                __sync_add_and_fetch(&cv_pages_allocated_count,1);
                if (cv_pages_allocated > cv_pages_allocated_peak)
                    cv_pages_allocated_peak = cv_pages_allocated;

                //Add to ShadowPTE
                pte->setPageAddr(reinterpret_cast<uint64_t>(l_page));
            }


            this->iv_readMsgHdlr->sendMessage(MSG_MM_RP_READ,
                    reinterpret_cast<void*>(l_addr_palign),l_page,i_task);
            //Done(waiting for response)
            return true;
        }
        else if (pte->isAllocateFromZero())
        {
            void* l_page = PageManager::allocatePage(1, false, allowOom);

            if (l_page == nullptr)
            {
                *o_oom = true;
                return false;
            }

            __sync_add_and_fetch(&cv_pages_allocated,1);
            __sync_add_and_fetch(&cv_pages_allocated_count,1);
            if (cv_pages_allocated > cv_pages_allocated_peak)
                cv_pages_allocated_peak = cv_pages_allocated;

            // set the permission of the physical address pte entry to
            // READ_ONLY now that we have handled the page fault and
            // have a SPTE entry for that VA.
            if (BaseSegment::mmSetPermission(reinterpret_cast<void*>(l_page),
                                             0, READ_ONLY))
            {
               // Did not set permission..
               printkd("handle page fault.. Set Permission failed for physical"
                       " addr =  0x%.lX\n", (uint64_t)l_page);
            }

            memset(l_page, '\0', PAGESIZE);

            pte->setPageAddr(reinterpret_cast<uint64_t>(l_page));
            pte->setPresent(true);

        }
        else
        {
            return false;
        }
    }

    // Determine access type.
    uint64_t l_access = (iv_mappedToPhysical ? BYPASS_HRMOR : 0);
    if (pte->isExecutable())
    {
        l_access |= EXECUTABLE;
    }
    else if (pte->isWritable() && pte->isDirty())
    {
        l_access |= WRITABLE;
    }
    else
    {
        l_access |= READ_ONLY;
    }

    PageTableManager::addEntry(
            l_addr_palign,
            pte->getPage(),
            l_access);

    return true;

}

void Block::setPhysicalPage(uint64_t i_vAddr, uint64_t i_pAddr,
                              uint64_t i_access)
{
    // Check containment, call down chain if address isn't in this block.
    if (!isContained(i_vAddr))
    {
        if (iv_nextBlock)
        {
            iv_nextBlock->setPhysicalPage(i_vAddr, i_pAddr, i_access);
        }
        else
        {
            // No block owns this address.  Code bug.
            kassert(iv_nextBlock);
        }
        return;
    }

    // Create virtual to physical mapping.
    ShadowPTE* pte = getPTE(i_vAddr);
    if (i_pAddr != 0)
    {
        pte->setPageAddr(i_pAddr);
        pte->setPresent(true);

        // Modified an SPTE, clear the HPTE.
        PageTableManager::delEntry(i_vAddr);
    }
    // If the page is already present, we might be changing permissions, so
    // clear the HPTE.
    else if (pte->isPresent())
    {
        PageTableManager::delEntry(i_vAddr);
    }


    // make a call that sets the permssions on a
    // shadow page table entry
    if (setPermSPTE(pte, i_access))
    {
        kassert(false);
    }

}

void Block::attachSPTE(void *i_vaddr)
{

    uint64_t l_vaddr = reinterpret_cast<uint64_t>(i_vaddr);
    ShadowPTE* l_pte = getPTE(l_vaddr);

    //Set the present bit for the address associated with this block
    l_pte->setPresent(true);

    // Determine access type.
    uint64_t l_access = (iv_mappedToPhysical ? BYPASS_HRMOR : 0);
    if (l_pte->isExecutable())
    {
        l_access |= EXECUTABLE;
    }
    else if (l_pte->isWritable() && l_pte->isDirty())
    {
        l_access |= WRITABLE;
    }
    else
    {
        l_access |= READ_ONLY;
    }

    //Add page table entry
    PageTableManager::addEntry((l_vaddr / PAGESIZE) * PAGESIZE,
                                l_pte->getPage(),
                                l_access);

    // update permission for the page that corresponds to the physical page
    // addr now that we have handled the page fault.
    if (BaseSegment::mmSetPermission(
            reinterpret_cast<void*>(l_pte->getPageAddr()), 0, READ_ONLY))
    {
       printkd("Got an error trying to set permissions in handle Response "
               "msg handler \n");
    }

}



uint64_t Block::findPhysicalAddress(uint64_t i_vaddr) const
{
    uint64_t paddr = -EFAULT;

    if(!isContained(i_vaddr))
    {
        return (iv_nextBlock ?
                iv_nextBlock->findPhysicalAddress(i_vaddr) : paddr);
    }

    ShadowPTE* pte = getPTE(i_vaddr);

    if (pte->isPresent() && pte->getPage() != 0)
    {
        paddr = pte->getPageAddr();
        paddr += i_vaddr % PAGESIZE;

        // If not a physically mapped block then add HRMOR
        if (!iv_mappedToPhysical)
        {
            paddr |= getHRMOR();
        }
    }

    return paddr;
}


void Block::releaseAllPages()
{
    // Free all pages back to page manager.
    for(uint64_t page = iv_baseAddr;
        page < (iv_baseAddr + iv_size);
        page += PAGESIZE)
    {
        ShadowPTE* pte = getPTE(page);
        if (pte->isPresent())
        {
            PageTableManager::delEntry(page);
            uint64_t addr = pte->getPageAddr();
            if (0 != addr)
            {
                releaseSPTE(pte);
                PageManager::freePage(reinterpret_cast<void*>(addr));
                __sync_sub_and_fetch(&cv_pages_allocated,1);
            }
        }
    }
}

void Block::updateRefCount( uint64_t i_vaddr,
                            PageTableManager::UsageStats_t i_stats )
{
    // Check containment, call down chain if address isn't in this block.
    if (!isContained(i_vaddr))
    {
        if (iv_nextBlock)
        {
            iv_nextBlock->updateRefCount(i_vaddr, i_stats);
        }
        else
        {
            // No block owns this address.  Code bug.
            printk("updateRefCount> i_vaddr=0x%.lX\n", i_vaddr );
            kassert(iv_nextBlock);
        }
        return;
    }

    ShadowPTE* spte = getPTE(i_vaddr);

    // Adjust the LRU statistics
    if( i_stats.R )
    {
        spte->zeroLRU();
    }
    else
    {
        spte->incLRU();
    }
}


void Block::castOutPages(uint64_t i_type)
{
    void* l_vaddr = NULL;
    // drill down
    if(iv_nextBlock)
    {
        iv_nextBlock->castOutPages(i_type);
    }

    if((iv_baseAddr != VMM_ADDR_BASE_BLOCK) && // Skip base area
       (iv_baseAddr != (VMM_ADDR_BASE_BLOCK + g_BlToHbDataManager.getHbCacheSizeBytes()))) // Skip extended memory
    {
        /*
        
        Declare LRU-based eviction minimums for read-write pages and read-only pages.
        These constraints determine (along with some other checks) if we should kick
        out a page or not.

        If not using aggressive LRU (99% of the time), the expressions for rw_constraint
        and ro_constraint can be toyed with to see if you get any performance improvements.
        The current constant values are defined in spte.H - the math works out to roughly match
        the following:
                        RW limit / RO limit
        3 bits of LRU:      2       3       (pretty aggressive)
        4 bits of LRU:      6       7
        5 bits of LRU:      14      15

        These values are a little under half of the maximum LRU counter value. You can modify
        it to be 3/4, 1/3, 2/3, etc. Currently, 1/2 is a nice number that provides good results.

        */
#ifdef CONFIG_AGGRESSIVE_LRU
        size_t rw_constraint = 2;
        size_t ro_constraint = 1;
#else
        size_t rw_constraint = ShadowPTE::LRU_RW_LIMIT/2;
        size_t ro_constraint = ShadowPTE::LRU_RO_LIMIT/2;
#endif

        // Counter for how many times we're requesting to throw out an
        // executable page
        static uint64_t executablePageCount = 0;

        if(i_type == VmmManager::CRITICAL)
        {
            rw_constraint = 2;
            ro_constraint = 1;
        }
        //printk("Block = %p:%ld\n",(void*)iv_baseAddr,iv_size / PAGESIZE);
        for(uint64_t page = iv_baseAddr;
            page < (iv_baseAddr + iv_size);
            page += PAGESIZE)
        {
            ShadowPTE* pte = getPTE(page);
            if (pte->isPresent() && (0 != pte->getPageAddr()))
            {
                if(pte->isWritable())
                {
                    if(pte->getLRU() > rw_constraint && pte->isWriteTracked())
                    {
                        //'EVICT' single page
                        l_vaddr = reinterpret_cast<void*>(page);
                        this->removePages(VmmManager::EVICT,l_vaddr,
                                          PAGESIZE,NULL);
                        ++cv_rw_evict_req;
                    }
                }
                else  // ro and/or executable
                {
                    if(pte->getLRU() > ro_constraint)
                    {
                        bool isCode = pte->isExecutable();
                        constexpr uint32_t BOUNDARY = 20;
                        /*
                        If the page is executable, we don't want to try and cast it out immediately.
                        Keep a counter of how many times we've tried to throw out a code page -
                        once the counter reaches a threshold, start throwing code pages out.
                        Until then, we can throw out data pages, that's okay.
                        If we DO end up throwing code pages out, keep doing so until
                        we receive a request to remove a data page, then reset our counter.

                        The boundary value of 20 was determined through some trial and error testing,
                        stepping between the values 5...50 in steps of 5. It's a nice number in the middle
                        that provides lower eviction rates than extreme ends of the spectrum for the value.

                        This boundary value can likely be modified to be dynamic with regards to time,
                        possibly through the current istep time (if we can read that data) and updating
                        the boundary based on how many eviction reqs we're getting in a certain timestep.
                        */
                        if (isCode && executablePageCount < BOUNDARY) {
                            executablePageCount++;
                        } else {
                            if (pte->isReadable() && isCode) {
                                executablePageCount = 0;
                            }
                            //'EVICT' single page
                            l_vaddr = reinterpret_cast<void*>(page);
                            this->removePages(VmmManager::EVICT,l_vaddr,
                                            PAGESIZE,NULL);
                            ++cv_ro_evict_req;

                            // =================================================
                            // Simics debugging information (noop'd in hardware)
                            if (isCode) {
                                MAGIC_INSTRUCTION(MAGIC_PRINT_EVICT_CODE);
                            }
                            // =================================================
                        }
                    }
                }
                // Simics debug for how many evictions per istep
                // Future improvement - include page as extra data to track
                MAGIC_INSTRUCTION(MAGIC_PRINT_PAGE_EVICTIONS);
            }
        }
    }
}

int Block::mmSetPermission(uint64_t i_va, uint64_t i_size,
                           uint64_t i_access_type)
{
    int l_rc = 0;

    // Need to align the page address and the size on a page boundary.
    uint64_t l_aligned_va = ALIGN_PAGE_DOWN(i_va);
    uint64_t l_aligned_size = ALIGN_PAGE(i_size);


    if(!isContained(l_aligned_va))
    {
        return (iv_nextBlock ?
                iv_nextBlock->mmSetPermission(i_va,i_size,i_access_type) :
                -EINVAL);
    }

    //printk("\n             aligned VA = 0x%.lX aligned size = %ld access_type = 0x%.lX\n", l_aligned_va,	l_aligned_size, i_access_type);

    // if i_size is zero we are only updating 1 page; increment the size to
    // one page.
    if (i_size == 0)
    {
        l_aligned_size+=PAGESIZE;
    }

    // loop through all the pages asked for based on passed aligned
    // Virtual address and passed in aligned size.
    for(uint64_t cur_page_addr = l_aligned_va;
        cur_page_addr < (l_aligned_va + l_aligned_size);
        cur_page_addr += PAGESIZE)
    {

        ShadowPTE* spte = getPTE(cur_page_addr);

        // if the page present need to delete the hardware
        // page table entry before we set permissions.
        if (spte->isPresent())
        {
            // delete the hardware page table entry
            PageTableManager::delEntry(cur_page_addr);
        }

        if (setPermSPTE(spte, i_access_type))
        {
            printkd("               SET PERMISSIONS.. FAILED \n");
            return -EINVAL;
        }
    }

    return l_rc;
}

int Block::setPermSPTE( ShadowPTE* i_spte, uint64_t i_access_type)
{

    // If read_only
    if ( i_access_type & READ_ONLY)
    {
        // If the writable, executable, write_tracked
        // or allocate from zero access bits are set
        // we have an invalid combination.. return error
        if ((i_access_type & WRITABLE) ||
            (i_access_type & EXECUTABLE) ||
            (i_access_type & WRITE_TRACKED) ||
            (i_access_type & ALLOCATE_FROM_ZERO))
        {
            return -EINVAL;
        }

        // Set the bits after we have verified
        // the valid combinations so if we are setting
        // permissions on a range only the first page would
        // get set to READ_ONLY before we fail.
        i_spte->setReadable(true);
        i_spte->setExecutable(false);
        i_spte->setWritable(false);
    }
    // if writable
    else if ( i_access_type & WRITABLE)
    {
        if (i_access_type & EXECUTABLE)
        {
            return -EINVAL;
        }

        i_spte->setReadable(true);
        i_spte->setWritable(true);
        i_spte->setExecutable(false);
    }
    // if executable
    else if ( i_access_type & EXECUTABLE)
    {
        i_spte->setReadable(true);
        i_spte->setExecutable(true);
        i_spte->setWritable(false);
    }

    // if write_tracked
    if ( i_access_type & WRITE_TRACKED)
    {
        // If the page is already READ_ONLY
        // you cannot set to WRITE_TRACKED
        if (getPermission(i_spte) == READ_ONLY)
        {
            return -EINVAL;
        }
        else if (NULL == iv_writeMsgHdlr)
        {
            return -EINVAL;
        }

        i_spte->setWriteTracked(true);
    }
    else
    {
        i_spte->setWriteTracked(false);
    }

    // if Allocate from zero
    if ( i_access_type & ALLOCATE_FROM_ZERO)
    {
        // If the page is already READ_ONLY
        // you cannot set to ALLOCATE_FROM_ZERO
        if (getPermission(i_spte) == READ_ONLY)
        {
            return -EINVAL;
        }

        i_spte->setAllocateFromZero(true);
    }
    // not allocated from zero
    else
    {
        i_spte->setAllocateFromZero(false);
    }

    // if no access
    if ( i_access_type & NO_ACCESS)
    {
        i_spte->setReadable(false);
        i_spte->setExecutable(false);
        i_spte->setWritable(false);
        i_spte->setAllocateFromZero(false);
        i_spte->setWriteTracked(false);
    }

    return 0;
}

uint64_t Block::getPermission( ShadowPTE* i_spte)
{

    uint64_t l_accessType = 0;

    if ((!i_spte->isReadable())&&
        (!i_spte->isExecutable())&&
        (!i_spte->isWritable())&&
        (!i_spte->isAllocateFromZero())&&
        (!i_spte->isWriteTracked()))
    {
        return NO_ACCESS;
    }

    if (i_spte->isReadable()&&
        (!i_spte->isExecutable())&&
        (!i_spte->isWritable()))
    {
        return READ_ONLY;
    }

    if (i_spte->isWritable())
    {
        l_accessType |= WRITABLE;
    }

    if (i_spte->isExecutable())
    {
        l_accessType |= EXECUTABLE;
    }

    if (i_spte->isWriteTracked())
    {
        l_accessType |= WRITE_TRACKED;
    }

    if (i_spte->isAllocateFromZero())
    {
        l_accessType |= ALLOCATE_FROM_ZERO;
    }

    return l_accessType;
}



int Block::removePages(VmmManager::PAGE_REMOVAL_OPS i_op, void* i_vaddr,
                                 uint64_t i_size, task_t* i_task)
{
    uint64_t l_vaddr = reinterpret_cast<uint64_t>(i_vaddr);
    //Align virtual address & size to page boundary
    /*The given virtual address will be 'rounded' down to the nearest page
      boundary, along with the given size will be 'rounded' up such that
      the request range is removed, plus the remainder to access a full
      page..*/
    uint64_t l_aligned_va = ALIGN_PAGE_DOWN(l_vaddr);
    uint64_t l_aligned_size = ALIGN_PAGE(i_size+(l_vaddr%PAGESIZE));
    //Find block containing virtual address
    if(!this->isContained(l_aligned_va))
    {
        return (iv_nextBlock ?
                iv_nextBlock->removePages(i_op,i_vaddr,i_size,i_task):-EINVAL);
    }
    else if ((l_aligned_va+l_aligned_size) > (this->iv_baseAddr+this->iv_size))
    {
        return -EINVAL;
    }

    //Perform requested page removal operation
    for (l_vaddr = l_aligned_va;l_vaddr < (l_aligned_va+l_aligned_size);
         l_vaddr+= PAGESIZE)
    {
        ShadowPTE* pte = getPTE(l_vaddr);
        uint64_t pageAddr = pte->getPageAddr();
        if (pte->isPresent() && (0 != pageAddr))
        {
            //Delete from HW page table immediately
            PageTableManager::delEntry(l_vaddr);
            if (pte->isDirty() && pte->isWriteTracked() &&
                this->iv_writeMsgHdlr != NULL)
            {
                releaseSPTE(pte);
                //Send write msg with the page address
                if (i_task != NULL)
                {
                    this->iv_writeMsgHdlr->incMsgCount(i_task);
                }

                this->iv_writeMsgHdlr->addVirtAddr(
                        reinterpret_cast<void*>(l_vaddr),pageAddr);
                this->iv_writeMsgHdlr->sendMessage(MSG_MM_RP_WRITE,
                        reinterpret_cast<void*>(l_vaddr),
                        reinterpret_cast<void*>(pageAddr),i_task);
            }
            else if (pte->isDirty() && !pte->isWriteTracked() &&
                     i_op == VmmManager::EVICT)
            {
                //Skip page
            }
            else if (i_op != VmmManager::FLUSH)
            {
                //'Release' page entry
                releaseSPTE(pte);
                PageManager::freePage(reinterpret_cast<void*>(pageAddr));
                __sync_sub_and_fetch(&cv_pages_allocated,1);
            }
        }
    }
    return 0;
}

void Block::releaseSPTE(ShadowPTE* i_pte)
{
    i_pte->setDirty(false);
    i_pte->setPresent(false);

    // set the permission of the physical address pte entry back to writable
    // now that the associated VA Spte has been released.
    if (BaseSegment::mmSetPermission(
            reinterpret_cast<void*>(i_pte->getPageAddr()),
            0, WRITABLE))
    {
        printkd("Got an error setting permission during Flush\n");
    }

    i_pte->setPageAddr(NULL);
}

void Block::addDebugPointers()
{
    DEBUG::add_debug_pointer(DEBUG::BLOCKPAGESALLOC,
                             &cv_pages_allocated,
                             sizeof(cv_pages_allocated));
    DEBUG::add_debug_pointer(DEBUG::BLOCKPAGESALLOCPEAK,
                             &cv_pages_allocated_peak,
                             sizeof(cv_pages_allocated_peak));
    DEBUG::add_debug_pointer(DEBUG::BLOCKPAGESALLOCCOUNT,
                             &cv_pages_allocated_count,
                             sizeof(cv_pages_allocated_count));
    DEBUG::add_debug_pointer(DEBUG::BLOCKREADONLYEVICT,
                             &cv_ro_evict_req,
                             sizeof(cv_ro_evict_req));
    DEBUG::add_debug_pointer(DEBUG::BLOCKREADWRITEEVICT,
                             &cv_rw_evict_req,
                             sizeof(cv_rw_evict_req));
}
