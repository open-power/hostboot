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
#include <util/singleton.H>

#include <kernel/basesegment.H>
#include <kernel/segmentmgr.H>
#include <kernel/block.H>
#include <kernel/vmmmgr.H>
#include <kernel/cpuid.H>
//#include <kernel/console.H>

#define SLBE_s 40

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
    uint64_t iv_baseBlockSize = 0;
    switch (CpuID::getCpuType())
    {
        case CORE_POWER7:
        case CORE_POWER7_PLUS:
        case CORE_POWER8_VENICE:
            iv_baseBlockSize = VmmManager::EIGHT_MEG;
            break;

        case CORE_POWER8_SALERNO:
        default:
            iv_baseBlockSize = VmmManager::FOUR_MEG;
            break;
    }
    iv_block = new Block(0x0, iv_baseBlockSize);
    iv_block->setParent(this);

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
    if ((l_vaddr < this->getBaseAddress() ||
        l_vaddr >= (this->getBaseAddress() + (1ull << SLBE_s))) &&
        (l_blockSizeTotal+i_size <= (1ull << SLBE_s)))
    {
        return -1;
    }
    //TODO - Align i_size to page size
    Block* l_block = new Block(l_vaddr, i_size, i_mq);
    l_block->setParent(this);
    iv_block->appendBlock(l_block);
    return 0;
}
