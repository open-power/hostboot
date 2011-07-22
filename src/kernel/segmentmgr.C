#include <assert.h>
#include <arch/ppc.H>
#include <util/singleton.H>

#include <kernel/segmentmgr.H>
#include <kernel/segment.H>

bool SegmentManager::handlePageFault(task_t* i_task, uint64_t i_addr)
{
    return Singleton<SegmentManager>::instance().
                _handlePageFault(i_task, i_addr);
}

void SegmentManager::addSegment(Segment* i_segment, size_t i_segId)
{
    Singleton<SegmentManager>::instance()._addSegment(i_segment, i_segId);
}

void SegmentManager::initSLB()
{
    Singleton<SegmentManager>::instance()._initSLB();
}

bool SegmentManager::_handlePageFault(task_t* i_task, uint64_t i_addr)
{
    // This constant should come from page manager.  Segment size.
    const size_t SLBE_s = 40;

    // Get segment ID from effective address.
    size_t segId = i_addr >> SLBE_s;

    // Call contained segment object to handle page fault.
    if ((segId < MAX_SEGMENTS) && (NULL != iv_segments[segId]))
    {
        return iv_segments[segId]->handlePageFault(i_task, i_addr);
    }

    return false;
}

void SegmentManager::_addSegment(Segment* i_segment, size_t i_segId)
{
    kassert(i_segId < MAX_SEGMENTS);
    iv_segments[i_segId] = i_segment;
}

void SegmentManager::_initSLB()
{
    // Flush SLB.
    asm volatile("slbia" ::: "memory");
    isync(); // Ensure slbia completes prior to slbmtes.

    register uint64_t slbRS, slbRB;

    // Default segment descriptors.
    // ESID = 0, V = 1, Index = 1.
    slbRB = 0x0000000008000001;
    // B = 01 (1TB), VSID = 0, Ks = 0, Kp = 1, NLCLP = 0
    slbRS = 0x4000000000000400;

    // Add all segments to SLB.
    for (size_t i = 0; i < MAX_SEGMENTS; i++)
    {
        // Add segment to SLB.
        if (NULL != iv_segments[i])
        {
            asm volatile("slbmte %0, %1" :: "r"(slbRS), "r"(slbRB) : "memory");
        }

        // Increment ESID, VSID, Index.
        slbRB += 0x0000010000000001;
        slbRS += 0x0000000001000000;
    }

    isync(); // Ensure slbmtes complete prior to continuing on.
}
