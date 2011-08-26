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

#include <kernel/block.H>
#include <kernel/spte.H>
#include <kernel/vmmmgr.H>
#include <kernel/ptmgr.H>
#include <kernel/pagemgr.H>
//#include <kernel/console.H>

Block::~Block()
{
    // Release shadow PTE array.
    delete[] iv_ptes;

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
    this->iv_msgHdlr = NULL;
    if (i_msgQ != NULL)
    {
        //Create message handler attribute for this block with this msgq
        this->iv_msgHdlr = new BlockMsgHdlr(VmmManager::getLock(),i_msgQ,this);
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
        if (this->iv_msgHdlr != NULL)
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
            this->iv_msgHdlr->sendMessage(MSG_MM_RP_READ,
                    reinterpret_cast<void*>(l_addr_palign),l_page,i_task);
            //Done(waiting for response)
            return true;
        }
        else if (pte->allocate_from_zero)
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
    pte->setPageAddr(i_pAddr);
    pte->setPresent(true);
    switch(i_access)
    {
        case VmmManager::READ_O_ACCESS:
            pte->setExecutable(false);
            pte->setWritable(false);
            break;

        case VmmManager::NORMAL_ACCESS:
            pte->setExecutable(false);
            pte->setWritable(true);
            break;

        case VmmManager::RO_EXE_ACCESS:
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
