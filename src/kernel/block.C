#include <limits.h>
#include <assert.h>

#include <kernel/block.H>
#include <kernel/spte.H>
#include <kernel/vmmmgr.H>
#include <kernel/ptmgr.H>

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

void Block::init()
{
    // Create a shadow PTE for each page.
    iv_ptes = new ShadowPTE[iv_size / PAGESIZE];
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
                    false : iv_nextBlock->handlePageFault(i_task, i_addr));
    }

    ShadowPTE* pte = getPTE(i_addr);

    if (!pte->isPresent())
    {
        // TODO.  Needs swapping support.
        return false;
    }

    if (pte->getPage() == 0)
    {
        return false;
    }

    // Add page table entry.
    PageTableManager::addEntry(
            (i_addr / PAGESIZE) * PAGESIZE,
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
