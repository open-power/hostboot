/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/devicesegment.C $                                  */
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
#include <util/singleton.H>
#include <limits.h>
#include <assert.h>

#include <kernel/vmmmgr.H>
#include <kernel/ptmgr.H>
#include <kernel/devicesegment.H>
#include <kernel/segmentmgr.H>

#include <kernel/console.H>

/**
 * @brief Add the device segment to the SegmentManager.
 */
void DeviceSegment::init(size_t segId)
{
    kassert((segId >= SegmentManager::MMIO_FIRST_SEGMENT_ID) &&
            (segId <= SegmentManager::MMIO_LAST_SEGMENT_ID));

    SegmentManager::addSegment(this, segId);
}

bool DeviceSegment::handlePageFault(task_t* i_task, uint64_t i_addr,
                                    bool i_store, bool* o_oom)
{
    (void)o_oom; // unused

    //Verify input address falls within this segment's address range
    if (i_addr < this->getBaseAddress() ||
        i_addr >= (this->getBaseAddress() + (1ull << SLBE_s)))
    {
        return false;
    }

    //Verify the device is mapped
    uint64_t segment_ea = i_addr - this->getBaseAddress();
    size_t idx = segment_ea / ((1ull << SLBE_s) / MMIO_MAP_DEVICES);
    uint64_t device_offset = segment_ea -
                                (idx * (1ull << SLBE_s) / MMIO_MAP_DEVICES);

    if (device_offset >= (uint64_t)iv_mmioMap[idx].size)
    {
        return false;
    }

    PageTableManager::addEntry((i_addr / PAGESIZE) * PAGESIZE,
                              (iv_mmioMap[idx].addr + device_offset) / PAGESIZE,
                              (iv_mmioMap[idx].no_ci ?
                                    (BYPASS_HRMOR | WRITABLE |
                                    ( iv_mmioMap[idx].guarded ? GUARDED : 0) ) :
                                    SegmentManager::CI_ACCESS)
                              );
    return true;
}


/**
 * @brief Map a device into the device segment.
 * @param ra[in] - Void pointer to real address to be mapped in
 * @param i_devDataSize[in] - Size of device segment block
 * @param i_nonCI[in] - Device should be mapped cacheable instead of CI
 * @param i_guarded[in] - Whether to prevent out-of-order acces to
 *     instructions or data in the segment.  Ignored if CI.
 * @return void* - Pointer to beginning virtual address, NULL otherwise
 */
void *DeviceSegment::devMap(void *ra, uint64_t i_devDataSize, bool i_nonCI,
    bool i_guarded)
{
    void *segBlock = NULL;
    if (i_devDataSize <= THIRTYTWO_GB)
    {
        for (size_t i = 0; i < MMIO_MAP_DEVICES; i++)
        {
            if ((0 == iv_mmioMap[i].addr) && (0 == iv_mmioMap[i].size))
            {
                iv_mmioMap[i].no_ci = i_nonCI;
                iv_mmioMap[i].guarded = i_guarded;
                iv_mmioMap[i].size = i_devDataSize;
                iv_mmioMap[i].addr = reinterpret_cast<uint64_t>(ra);

                segBlock = reinterpret_cast<void*>(i *
                        ((1ull << SLBE_s) / MMIO_MAP_DEVICES) +
                        this->getBaseAddress());
                break;
            }
        }
    }
    else
    {
        printk("Unsupported device segment size(0x%lX), ",i_devDataSize);
        printk("for address 0x%lX\n",reinterpret_cast<uint64_t>(ra));
    }

    return segBlock;
}

int DeviceSegment::devUnmap(void *ea)
{
    int rc = -EINVAL;
    uint64_t segment_ea = reinterpret_cast<uint64_t>(ea);
    //Verify input address falls within this segment's address range
    if (segment_ea < this->getBaseAddress() ||
        segment_ea >= (this->getBaseAddress() + (1ull << SLBE_s)))
    {
        return rc;
    }
    segment_ea = segment_ea - this->getBaseAddress();

    size_t idx = segment_ea / ((1ull << SLBE_s) / MMIO_MAP_DEVICES);
    if ((0 != iv_mmioMap[idx].addr) || (0 != iv_mmioMap[idx].size))
    {
        //Remove all of the defined block's size (<= 32GB)
        PageTableManager::delRangePN(iv_mmioMap[idx].addr / PAGESIZE,
                (iv_mmioMap[idx].addr + iv_mmioMap[idx].size) / PAGESIZE,
                 false);
        iv_mmioMap[idx].addr = 0;
        iv_mmioMap[idx].size = 0;
        iv_mmioMap[idx].guarded = 0;
        rc = 0;
    }

    return rc;
}

/**
 * Locate the physical address of the given virtual address
 */
uint64_t DeviceSegment::findPhysicalAddress(uint64_t i_vaddr) const
{
    uint64_t rc = -EFAULT;
    uint64_t segment_ea = i_vaddr;
    //Verify input address falls within this segment's address range
    if (segment_ea < this->getBaseAddress() ||
        segment_ea >= (this->getBaseAddress() + (1ull << SLBE_s)))
    {
        return rc;
    }
    segment_ea = segment_ea - this->getBaseAddress();

    size_t idx = segment_ea / ((1ull << SLBE_s) / MMIO_MAP_DEVICES);
    if ((0 != iv_mmioMap[idx].addr) || (0 != iv_mmioMap[idx].size))
    {
        //memory offset within this device's window
        uint64_t offset = segment_ea -
                          idx*((1ull << SLBE_s) / MMIO_MAP_DEVICES);
        return (iv_mmioMap[idx].addr + offset);
    }

    return rc;
}
