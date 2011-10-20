//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/kernel/block.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
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

void Block::init(MessageQueue* i_msgQ)
{
    // Create a shadow PTE for each page.
    iv_ptes = new ShadowPTE[iv_size / PAGESIZE];
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

bool Block::handlePageFault(task_t* i_task, uint64_t i_addr)
{
    // Check containment, call down chain if address isn't in this block.
    if (!isContained(i_addr))
    {
        return (iv_nextBlock ?
                    iv_nextBlock->handlePageFault(i_task, i_addr) : false);
    }

    // Calculate page aligned virtual address.
    uint64_t l_addr_palign = (i_addr / PAGESIZE) * PAGESIZE;

    ShadowPTE* pte = getPTE(l_addr_palign);

    if (!pte->isPresent())
    {
        if (this->iv_readMsgHdlr != NULL)
        {
            void* l_page = reinterpret_cast<void*>(pte->getPageAddr());
            //If the page data is zero, create the page
            if (pte->getPage() == 0)
            {
                l_page = PageManager::allocatePage();
                //Add to ShadowPTE
                pte->setPageAddr(reinterpret_cast<uint64_t>(l_page));
                //TODO - Update to correct permissions requested
                pte->setExecutable(false);
                pte->setWritable(true);
            }
            //Send message to handler to read page
            this->iv_readMsgHdlr->sendMessage(MSG_MM_RP_READ,
                    reinterpret_cast<void*>(l_addr_palign),l_page,i_task);
            //Done(waiting for response)
            return true;
        }
        else if (pte->isAllocateFromZero())
        {
            void* l_page = PageManager::allocatePage();
            memset(l_page, '\0', PAGESIZE);

            pte->setPageAddr(reinterpret_cast<uint64_t>(l_page));
            pte->setPresent(true);
        }
        else
        {
            return false; //TODO - Swap kernel base block pages for user pages
        }
    }

    // Add page table entry.
    PageTableManager::addEntry(
            l_addr_palign,
            pte->getPage(),
            (pte->isExecutable() ? VmmManager::RO_EXE_ACCESS :
                (pte->isWritable() ? VmmManager::NORMAL_ACCESS :
                                     VmmManager::READ_O_ACCESS)));

    return true;

}

void Block::setPhysicalPage(uint64_t i_vAddr, uint64_t i_pAddr,
                            VmmManager::ACCESS_TYPES i_access)
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

    switch(i_access)
    {
        case VmmManager::READ_O_ACCESS:
            pte->setReadable(true);
            pte->setExecutable(false);
            pte->setWritable(false);
            break;

        case VmmManager::NORMAL_ACCESS:
            pte->setReadable(true);
            pte->setExecutable(false);
            pte->setWritable(true);
            break;

        case VmmManager::RO_EXE_ACCESS:
            pte->setReadable(true);
            pte->setExecutable(true);
            pte->setWritable(false);
            break;

        default:
            kassert(false);
            break;
    }
}

void Block::setIsPresent(void* i_vaddr)
{
    uint64_t l_vaddr = reinterpret_cast<uint64_t>(i_vaddr);
    ShadowPTE* l_pte = getPTE(l_vaddr);
    //Set present bit
    l_pte->setPresent(true);
}

void Block::addPTE(void* i_vaddr)
{
    uint64_t l_vaddr = reinterpret_cast<uint64_t>(i_vaddr);
    ShadowPTE* l_pte = getPTE(l_vaddr);
    //Add page table entry
    PageTableManager::addEntry((l_vaddr / PAGESIZE) * PAGESIZE,
                      l_pte->getPage(),
                      (l_pte->isExecutable() ? VmmManager::RO_EXE_ACCESS :
                      (l_pte->isWritable() ? VmmManager::NORMAL_ACCESS :
                       VmmManager::READ_O_ACCESS)));
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
    }

    return paddr;
}

void Block::setPageAllocateFromZero(uint64_t i_vAddr)
{
    // Check containment, call down chain if address isn't in this block.
    if (!isContained(i_vAddr))
    {
        if (iv_nextBlock)
        {
            iv_nextBlock->setPageAllocateFromZero(i_vAddr);
        }
        else
        {
            // No block owns this address.  Code bug.
            printk("setPageAllocateFromZero> i_vaddr=0x%.lX\n", i_vAddr );
            kassert(iv_nextBlock);
        }
        return;
    }

    // Set page to allocate-from-zero.
    ShadowPTE* pte = getPTE(i_vAddr);
    pte->setAllocateFromZero(true);
}

void Block::releaseAllPages()
{
    // Release all pages from page table.
    PageTableManager::delRangeVA(iv_baseAddr, iv_baseAddr + iv_size);

    // Free all pages back to page manager.
    for(uint64_t page = iv_baseAddr;
        page < (iv_baseAddr + iv_size);
        page += PAGESIZE)
    {
        ShadowPTE* pte = getPTE(page);
        if (pte->isPresent() && (0 != pte->getPageAddr()))
        {
            PageManager::freePage(reinterpret_cast<void*>(pte->getPageAddr()));
            pte->setPresent(false);
            pte->setPageAddr(NULL);
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

    // track the changed/dirty bit
    if (i_stats.C)
    {
        spte->setDirty( i_stats.C );
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

    // TODO We will eventually need to skip other blocks as well, such as
    // when the memory space grows.
    if(iv_baseAddr != 0) // Skip base area
    {
        size_t rw_constraint = 5;
        size_t ro_constraint = 3;

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
                //if(pte->isExecutable()) printk("x");
                //else if(pte->isWritable()) printk("w");
                //else printk("r");
                //printk("%d",(int)pte->getLRU());

                if(pte->isWritable())
                {
                    if(pte->getLRU() > rw_constraint && pte->isWriteTracked())
                    {
                        //'EVICT' single page
                        l_vaddr = reinterpret_cast<void*>(page);
                        this->removePages(VmmManager::EVICT,l_vaddr,
                                          PAGESIZE,NULL);
                        //printk("+");
                    }
                }
                else  // ro and/or executable
                {
                    if(pte->getLRU() > ro_constraint)
                    {
                        //'EVICT' single page
                        l_vaddr = reinterpret_cast<void*>(page);
                        this->removePages(VmmManager::EVICT,l_vaddr,
                                          PAGESIZE,NULL);
                    }
                }
            }
        }
    }
}

int Block::mmSetPermission(uint64_t i_va, uint64_t i_size,uint64_t i_access_type)
{
 int l_rc = 0;

 // Need to align the page address and the size on a page boundary. before I get the page.
 uint64_t l_aligned_va = ALIGN_PAGE_DOWN(i_va);
 uint64_t l_aligned_size = ALIGN_PAGE(i_size);
//printk("aligned VA = 0x%.lX aligned size = %ld\n", l_aligned_va, l_aligned_size);

 // if size is zero..we are only updating 1 page.. so need to increment the size to 1 page
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
//printk("aligned VA = 0x%.lX aligned size = %ld\n", l_aligned_va, l_aligned_size);
   ShadowPTE* spte = getPTE(cur_page_addr);

   // if the page present need to delete the hardware
   // page table entry before we set permissions.
   if (spte->isPresent())
   {
     // delete the hardware page table entry
      PageTableManager::delEntry(cur_page_addr);
   }

   // If read_only
   if ( i_access_type & READ_ONLY)
   {
     spte->setReadable(true);
     spte->setExecutable(false);
     spte->setWritable(false);

     // If the writable or executable access bits
     // are set.. invalid combination.. return error
     if ((i_access_type & WRITABLE) || (i_access_type & EXECUTABLE))
     { 
       return -EINVAL;
     }
   }
   // if writable
   else if ( i_access_type & WRITABLE)
   {
     spte->setReadable(true);
     spte->setWritable(true);
     spte->setExecutable(false);

     if (i_access_type & EXECUTABLE)
     {
       // error condition.. not valid to be
       // writable and executable
       return -EINVAL;
     }
   }
   // if executable
   else if ( i_access_type & EXECUTABLE)
   {
     spte->setReadable(true);
     spte->setExecutable(true);
     spte->setWritable(false);
   }

   // if write_tracked
   if ( i_access_type & WRITE_TRACKED)
   {
     spte->setWriteTracked(true);
   }
   else
   {
     spte->setWriteTracked(false);
   }

   // if Allocate from zero
   if ( i_access_type & ALLOCATE_FROM_ZERO)
   {
     spte->setAllocateFromZero(true);
   }
   // not allocated from zero
   else
   {
     spte->setAllocateFromZero(false);
   }

   // if no access
   if ( i_access_type & NO_ACCESS)
   {
     spte->setReadable(false);
     spte->setExecutable(false);
     spte->setWritable(false);
     spte->setAllocateFromZero(false);
     spte->setWriteTracked(false);
   }

 }
 return l_rc;
}

int Block::removePages(VmmManager::PAGE_REMOVAL_OPS i_op, void* i_vaddr,
                                 uint64_t i_size, task_t* i_task)
{
    uint64_t l_vaddr = reinterpret_cast<uint64_t>(i_vaddr);
    //Align virtual address & size to page boundary
    /*The given virtual address will be 'rounded' down to the nearest page
      boundary, along with the given size will be 'rounded' up to the
      nearest divisible page size.*/
    uint64_t l_aligned_va = ALIGN_PAGE_DOWN(l_vaddr);
    uint64_t l_aligned_size = ALIGN_PAGE(i_size);
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
                releasePTE(pte);
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
                releasePTE(pte);
                PageManager::freePage(reinterpret_cast<void*>(pageAddr));
            }
        }
    }
    return 0;
}

void Block::releasePTE(ShadowPTE* i_pte)
{
    i_pte->setDirty(false);
    i_pte->setPresent(false);
    i_pte->setPageAddr(NULL);
}
