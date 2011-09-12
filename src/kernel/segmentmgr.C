//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/kernel/segmentmgr.C $
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
#include <assert.h>
#include <errno.h>
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

uint64_t SegmentManager::findPhysicalAddress(uint64_t i_vaddr)
{
    return Singleton<SegmentManager>::instance()._findPhysicalAddress(i_vaddr);
}

void SegmentManager::updateRefCount( uint64_t i_vaddr,
				     PageTableManager::UsageStats_t i_stats )
{
    Singleton<SegmentManager>::instance()._updateRefCount(i_vaddr,i_stats);
}

bool SegmentManager::_handlePageFault(task_t* i_task, uint64_t i_addr)
{
    size_t segId = getSegmentIdFromAddress(i_addr);

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

uint64_t SegmentManager::_findPhysicalAddress(uint64_t i_vaddr) const
{
    uint64_t paddr = -EFAULT;
    size_t segId = getSegmentIdFromAddress(i_vaddr);

    if ((segId < MAX_SEGMENTS) && (NULL != iv_segments[segId]))
    {
        paddr = iv_segments[segId]->findPhysicalAddress(i_vaddr);
    }

    return paddr;
}

void SegmentManager::_updateRefCount( uint64_t i_vaddr,
				      PageTableManager::UsageStats_t i_stats )
{
    // Get segment ID from effective address.
    size_t segId = i_vaddr >> SLBE_s;

    // Call contained segment object to update the reference count
    if ((segId < MAX_SEGMENTS) && (NULL != iv_segments[segId]))
    {
        iv_segments[segId]->updateRefCount( i_vaddr, i_stats );
    }
}
