/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/segmentmgr.C $                                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2020                        */
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
#include <assert.h>
#include <errno.h>
#include <arch/ppc.H>
#include <util/singleton.H>
#include <kernel/console.H>

#include <kernel/segmentmgr.H>
#include <kernel/segment.H>
#include <kernel/devicesegment.H>
#include <usr/debugpointers.H>

bool SegmentManager::handlePageFault(task_t* i_task, uint64_t i_addr,
                                     bool i_store, bool* o_oom)
{
    return Singleton<SegmentManager>::instance().
        _handlePageFault(i_task, i_addr, i_store, o_oom);
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

void SegmentManager::castOutPages(uint64_t i_type)
{
    Singleton<SegmentManager>::instance()._castOutPages(i_type);
}

void* SegmentManager::devMap(void* ra, uint64_t i_devDataSize, bool i_nonCI,
    bool i_guarded)
{
    return Singleton<SegmentManager>::instance()._devMap(ra, i_devDataSize,
                                                         i_nonCI, i_guarded);
}

int SegmentManager::devUnmap(void* ea)
{
    return Singleton<SegmentManager>::instance()._devUnmap(ea);
}

void SegmentManager::addDebugPointers()
{
    Singleton<SegmentManager>::instance()._addDebugPointers();
}

bool SegmentManager::_handlePageFault(task_t* i_task, uint64_t i_addr,
                                      bool i_store, bool* o_oom)
{
    size_t segId = getSegmentIdFromAddress(i_addr);

    // Call contained segment object to handle page fault.
    if ((segId < MAX_SEGMENTS) && (NULL != iv_segments[segId]))
    {
        return iv_segments[segId]->handlePageFault(i_task, i_addr, i_store, o_oom);
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
    size_t segId = getSegmentIdFromAddress(i_vaddr);

    // Call contained segment object to update the reference count
    if ((segId < MAX_SEGMENTS) && (NULL != iv_segments[segId]))
    {
        iv_segments[segId]->updateRefCount( i_vaddr, i_stats );
    }
}

void SegmentManager::_castOutPages(uint64_t i_type)
{
    for (size_t i = 0; i < MAX_SEGMENTS; i++)
    {
        if (NULL != iv_segments[i])
        {
            iv_segments[i]->castOutPages(i_type);
        }
    }
}

void* SegmentManager::_devMap(void* ra, uint64_t i_devDataSize, bool i_nonCI,
    bool i_guarded)
{
    void* ea = NULL;
    for (size_t i = MMIO_FIRST_SEGMENT_ID; i <= MMIO_LAST_SEGMENT_ID; i++)
    {
        if (NULL == iv_segments[i]) continue;

        ea = reinterpret_cast<DeviceSegment*>(iv_segments[i])->
                devMap(ra, i_devDataSize, i_nonCI, i_guarded);

        if (ea != NULL) break;
    }

    if (ea == NULL)
    {
        printk("SegmentManager: Ran out of device segment blocks.\n");
    }

    return ea;
}

int SegmentManager::_devUnmap(void* ea)
{
    size_t segId = getSegmentIdFromAddress(reinterpret_cast<uint64_t>(ea));
    if ((segId < MMIO_FIRST_SEGMENT_ID) ||
        (segId > MMIO_LAST_SEGMENT_ID) ||
        (NULL == iv_segments[segId]))
    {
        return -EINVAL;
    }

    return reinterpret_cast<DeviceSegment*>(iv_segments[segId])->devUnmap(ea);
}

void SegmentManager::_addDebugPointers()
{
    DEBUG::add_debug_pointer(DEBUG::SEGMENTMANAGER,
                             this,
                             sizeof(SegmentManager));
}
