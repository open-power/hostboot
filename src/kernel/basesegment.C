/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/basesegment.C $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
#include <errno.h>
#include <util/singleton.H>
#include <util/align.H>

#include <kernel/basesegment.H>
#include <kernel/segmentmgr.H>
#include <kernel/block.H>
#include <kernel/cpuid.H>
#include <kernel/console.H>
#include <kernel/pagemgr.H>
#include <kernel/spte.H>
#include <kernel/memstate.H>

BaseSegment::~BaseSegment()
{
    delete iv_block;
}

void BaseSegment::init()
{
    Singleton<BaseSegment>::instance()._init();
}

void BaseSegment::_init()
{
    // Assign segment to segment manager.
    SegmentManager::addSegment(this, SegmentManager::BASE_SEGMENT_ID);

    // Create initial static 3 or 8MB block.
    switch (CpuID::getCpuType())
    {
        case CORE_POWER8_MURANO:
        case CORE_POWER8_VENICE:
        default:
            iv_physMemSize = VMM_BASE_BLOCK_SIZE;
            break;
    }
    // Base block is L3 cache physical memory size
    iv_block = new Block(0x0, iv_physMemSize);
    iv_block->setParent(this);

    // Set default page permissions on block.
    for (uint64_t i = 0; i < VMM_BASE_BLOCK_SIZE; i += PAGESIZE)
    {
        // External address filled in by linker as start of kernel's
        // data pages.
        extern void* data_load_address;

        // Don't map in the 0 (NULL) page.
        if (i == 0) continue;

        // Set pages in kernel text section to be read-only / executable.
        if ((ALIGN_PAGE_DOWN((uint64_t)&data_load_address)) > i)
        {
            // Set the Text section to Excutable (implies read)
            iv_block->setPhysicalPage(i, i, EXECUTABLE);
        }
        // Set all other pages to initially be read/write.  VFS will set
        // permissions on pages outside kernel.
        else
        {
            iv_block->setPhysicalPage(i, i, WRITABLE);
        }
    }
}

bool BaseSegment::handlePageFault(task_t* i_task, uint64_t i_addr, bool i_store)
{
    // Tail recursion to block chain.
    return iv_block->handlePageFault(i_task, i_addr, i_store);
}

/**
 * STATIC
 * Allocates a block of virtual memory of the given size
 */
int BaseSegment::mmAllocBlock(MessageQueue* i_mq,void* i_va,uint64_t i_size,
                                bool i_mappedToPhy, uint64_t *i_SPTEaddr)
{
    return Singleton<BaseSegment>::instance()._mmAllocBlock(i_mq,i_va,i_size,
                                                            i_mappedToPhy,
                                                            i_SPTEaddr);

}

/**
 * Allocates a block of virtual memory of the given size
 */
int BaseSegment::_mmAllocBlock(MessageQueue* i_mq,void* i_va,uint64_t i_size,
                                bool i_mappedToPhy, uint64_t *i_SPTEaddr)

{
    uint64_t l_vaddr = reinterpret_cast<uint64_t>(i_va);
    uint64_t l_blockSizeTotal = 0;
    iv_block->totalBlocksAlloc(l_blockSizeTotal);

    //Verify input address and size falls within this segment's address range
    if (l_vaddr < this->getBaseAddress() ||
        l_vaddr >= (this->getBaseAddress() + (1ull << SLBE_s)) ||
        (l_blockSizeTotal + ALIGN_PAGE(i_size)) >= (1ull << SLBE_s) ||
        (l_vaddr != ALIGN_PAGE_DOWN(l_vaddr)))
    {
        printkd("_mmAllocBlock: Address %lX is not part of BaseSegment : baseaddr=%lX, totalblocks=%ld\n", l_vaddr, this->getBaseAddress(), l_blockSizeTotal);
        return -EINVAL;
    }

    // Verify that the block we are adding is not already contained within
    // another block in the base segment
    Block* temp_block = iv_block;
    while (temp_block != NULL)
    {
        // Checking to see if the l_vaddr is already contained in another
        // block.. if so return error
        if  (temp_block->isContained(l_vaddr))
        {
            printkd("_mmAllocBlock Address = %lx is already in a block\n",l_vaddr);
            return -EALREADY;
        }

        temp_block = temp_block->iv_nextBlock;
    }

    Block* l_block = new Block(l_vaddr, ALIGN_PAGE(i_size), i_mq,i_mappedToPhy,
                               i_SPTEaddr );

    l_block->setParent(this);
    iv_block->appendBlock(l_block);
    return 0;
}

uint64_t BaseSegment::findPhysicalAddress(uint64_t i_vaddr) const
{
    if(i_vaddr < iv_physMemSize)
    {
        // Anything in the physical address size is valid (and linear mapped)
        // except NULL.
        if (i_vaddr >= PAGE_SIZE)
            return (i_vaddr | getHRMOR());
        else return -EFAULT;
    }
    return (iv_block ? iv_block->findPhysicalAddress(i_vaddr) : -EFAULT);
}

void BaseSegment::updateRefCount( uint64_t i_vaddr,
				  PageTableManager::UsageStats_t i_stats )
{
    // Just call over to block chain
    iv_block->updateRefCount(i_vaddr, i_stats);
}

/**
 *  STATIC
 * Sets the Page Permissions for a given page via virtual address
 */
int BaseSegment::mmSetPermission(void* i_va, uint64_t i_size, uint64_t i_access_type)
{
  return Singleton<BaseSegment>::instance()._mmSetPermission(i_va,i_size,i_access_type);
}


/**
 * Sets the Page Permissions for a given page via virtual address
 */
int BaseSegment::_mmSetPermission(void* i_va, uint64_t i_size, uint64_t i_access_type)
{
    Block *l_block = iv_block;
    uint64_t l_va = reinterpret_cast<uint64_t>(i_va);

    return (l_block->mmSetPermission(l_va, i_size, i_access_type));
}

void BaseSegment::castOutPages(uint64_t i_type)
{
    iv_block->castOutPages(i_type);
}
/**
 * STATIC
 * Remove pages by a specified operation of the given size
 */
int BaseSegment::mmRemovePages(VmmManager::PAGE_REMOVAL_OPS i_op,
                               void* i_vaddr, uint64_t i_size, task_t* i_task)
{
    return Singleton<BaseSegment>::instance()._mmRemovePages(i_op,i_vaddr,
                                                             i_size,i_task);
}

/**
 * Remove pages by a specified operation of the given size
 */
int BaseSegment::_mmRemovePages(VmmManager::PAGE_REMOVAL_OPS i_op,
                                void* i_vaddr, uint64_t i_size, task_t* i_task)
{
    //Don't allow removal of pages for base block
    return (iv_block->iv_nextBlock ?
            iv_block->iv_nextBlock->removePages(i_op,i_vaddr,i_size,i_task):
            -EINVAL);
}


/**
 * STATIC
 * Allocates a block of virtual memory to extend the VMM
 */
int BaseSegment::mmExtend(void)
{
    return Singleton<BaseSegment>::instance()._mmExtend();
}

/**
 * Allocates a block of virtual memory of the given size
 * to extend the VMM to 32MEG in size in mainstore
 */
int BaseSegment::_mmExtend(void)
{
    // The base address of the extended memory is 8Mg.. The first x pages is
    // for the SPTE.. The remaining pages from 8MG + SPTE to 32MEG is added to
    // the HEAP..

    uint64_t l_vaddr = VMM_ADDR_EXTEND_BLOCK; // 8MEG
    uint64_t l_size = VMM_EXTEND_BLOCK_SIZE;  // 32MEG - 8MB (base block)

    // Call to allocate a block passing in the requested address of where the
    // SPTEs should be created
    int rc =  _mmAllocBlock(NULL, reinterpret_cast<void *>(l_vaddr), l_size,
                            false, reinterpret_cast<uint64_t *>(l_vaddr));

    if (rc)
    {
        printk("Got an error in mmAllocBlock\n");
        return rc;
    }

    // Set default page permissions on block.
    for (uint64_t i = l_vaddr; i < l_vaddr + l_size; i += PAGESIZE)
    {
        iv_block->setPhysicalPage(i, i, WRITABLE);
    }

    // Now need to take the pages past the SPTE and add them to the heap.

    //get the number of pages needed to hold the SPTE entries.
    uint64_t spte_pages = (ALIGN_PAGE(l_size)/PAGESIZE *
                           sizeof(ShadowPTE))/PAGESIZE;

    printkd("Number of SPTE pages %ld\n", spte_pages);

    // Need to setup the starting address of the memory we need to add to the
    // heap to be the address of the block + the number of pages that are being
    // used for the SPTE.

    // Call Add Memory with the starting address , size.. it will put the pages
    // on the heap call this with the address being the first page past the
    // SPTE.
    PageManager::addMemory(l_vaddr + (spte_pages*PAGESIZE),
                           l_size/PAGESIZE - spte_pages);

    // Update the physical Memory size to now be 32MEG. by adding the extended
    // block size to the physical mem size.
    iv_physMemSize += VMM_EXTEND_BLOCK_SIZE;


    // Call to set the Hostboot MemSize and location needed for DUMP.
    KernelMemState::setMemScratchReg(KernelMemState::MEM_CONTAINED_MS,
                                     KernelMemState::MS_32MEG);

    return 0;
}

/**
 * Allocates a block of virtual memory of the given size
 * to at a specified physical address.
 */
int BaseSegment::mmLinearMap(void *i_paddr, uint64_t i_size)
{
    return Singleton<BaseSegment>::instance()._mmLinearMap(i_paddr, i_size);
}

/**
 * Allocates a block of virtual memory of the given size
 * to at a specified physical address
 */
int BaseSegment::_mmLinearMap(void *i_paddr, uint64_t i_size)
{

    int rc = _mmAllocBlock(NULL, i_paddr, i_size, true);

    if (rc)
    {
        printk("Got an error in mmAllocBlock\n");
        return rc;
    }

    uint64_t l_addr = reinterpret_cast<uint64_t>(i_paddr);

    // set the default permissions and the va-pa mapping in the SPTE
    for (uint64_t i = l_addr; i < l_addr + i_size; i += PAGESIZE)
    {
        iv_block->setPhysicalPage(i, i, WRITABLE);
    }

    return 0;

}
