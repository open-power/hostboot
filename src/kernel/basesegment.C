//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/kernel/basesegment.C $
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
#include <errno.h>
#include <util/singleton.H>
#include <util/align.H>

#include <kernel/basesegment.H>
#include <kernel/segmentmgr.H>
#include <kernel/block.H>
#include <kernel/cpuid.H>
#include <kernel/console.H>


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
        case CORE_POWER7:
        case CORE_POWER7_PLUS:
        case CORE_POWER8_VENICE:
            iv_physMemSize = (8*MEGABYTE);
            break;

        case CORE_POWER8_SALERNO:
        default:
            iv_physMemSize = (4*MEGABYTE);
            break;
    }
    // Base block is L3 cache physical memory size
    iv_block = new Block(0x0, iv_physMemSize);
    iv_block->setParent(this);

    // TODO iv_physMemSize needs to be recalculated when DIMM memory is avail.

    // Set default page permissions on block.
    for (uint64_t i = 0; i < 0x800000; i += PAGESIZE)
    {
            // External address filled in by linker as start of kernel's
            // data pages.
        extern void* data_load_address;

        // Don't map in the 0 (NULL) page.
        if (i == 0) continue;

        // Set pages in kernel text section to be read-only / executable.
        if (((uint64_t)&data_load_address) > i)
        {
            iv_block->setPhysicalPage(i, i, VmmManager::RO_EXE_ACCESS);
        }
        // Set all other pages to initially be read/write.  VFS will set
        // permissions on pages outside kernel.
        // (@TODO: Future Sprint, for now keep NORMAL_ACCESS as RWX, not RW.)
        else
        {
            iv_block->setPhysicalPage(i, i, VmmManager::NORMAL_ACCESS);
        }
    }
}

bool BaseSegment::handlePageFault(task_t* i_task, uint64_t i_addr)
{
    // Tail recursion to block chain.
    return iv_block->handlePageFault(i_task, i_addr);
}

/**
 * STATIC
 * Allocates a block of virtual memory of the given size
 */
int BaseSegment::mmAllocBlock(MessageQueue* i_mq,void* i_va,uint64_t i_size)
{
    return Singleton<BaseSegment>::instance()._mmAllocBlock(i_mq,i_va,i_size);
}

/**
 * Allocates a block of virtual memory of the given size
 */
int BaseSegment::_mmAllocBlock(MessageQueue* i_mq,void* i_va,uint64_t i_size)
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
        return -EINVAL;
    }
    Block* l_block = new Block(l_vaddr, ALIGN_PAGE(i_size), i_mq);
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
            return i_vaddr;
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
  int l_rc = 0;
  Block *l_block = iv_block;
  uint64_t l_va = reinterpret_cast<uint64_t>(i_va);


  do
  {
    // If the va is not part of this block
    if (!(l_block->isContained(l_va)))
    {
      // Check to see if there is a next block
      if (l_block->iv_nextBlock)
      {
	// set local block to the next block
	l_block = l_block->iv_nextBlock;
      }
      else
      {
	// address passed in does not fall into a block
	return -EINVAL;
      }
    }
    // The virtual address falls within this block
    else
    {
        // Set the permission on the the current block.
       return(l_block->mmSetPermission(l_va, i_size, i_access_type));

    }
  } while (l_block);

  return l_rc;

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
