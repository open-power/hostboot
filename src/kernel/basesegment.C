#include <limits.h>
#include <util/singleton.H>

#include <kernel/basesegment.H>
#include <kernel/segmentmgr.H>
#include <kernel/block.H>
#include <kernel/vmmmgr.H>
#include <kernel/cpuid.H>

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
            iv_baseBlockSize = VmmManager::THREE_MEG;
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
