//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/kernel/devicesegment.C $
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
#include <util/singleton.H>
#include <limits.h>

#include <kernel/vmmmgr.H>
#include <kernel/ptmgr.H>
#include <kernel/devicesegment.H>
#include <kernel/segmentmgr.H>

#include <kernel/console.H>

/**
 * STATIC
 * @brief Add the device segment
 */
void DeviceSegment::init()
{
    Singleton<DeviceSegment>::instance()._init();
}

/**
 * @brief DEPRECATED
 */
void* DeviceSegment::mmioMap(void* ra, size_t pages)
{
    return Singleton<DeviceSegment>::instance()._mmioMap(ra, pages);
}

/**
 * @brief DEPRECATED
 */
int DeviceSegment::mmioUnmap(void* ea, size_t pages)
{
    return Singleton<DeviceSegment>::instance()._mmioUnmap(ea, pages);
}

/**
 * STATIC
 * @brief Map a device into the device segment(2TB)
 */
void* DeviceSegment::devMap(void *ra, uint64_t i_devDataSize)
{
    return Singleton<DeviceSegment>::instance()._devMap(ra,i_devDataSize);
}

/**
 * STATIC
 * @brief Unmap a device from the device segment(2TB)
 */
int DeviceSegment::devUnmap(void *ea)
{
    return Singleton<DeviceSegment>::instance()._devUnmap(ea);
}

/**
 * @brief Add the device segment
 */
void DeviceSegment::_init()
{
    SegmentManager::addSegment(this, SegmentManager::MMIO_SEGMENT_ID);
}

/**
 * @brief Handle a page fault for a device address access
 * @param i_task[in] - Task pointer to the task requiring the page
 * @param i_addr[in] - 64-bit address needed to be paged
 * @return bool - TRUE: Page added to page table
 *               FALSE: Not a valid address to be paged
 */
bool DeviceSegment::handlePageFault(task_t* i_task, uint64_t i_addr)
{
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

    if (0 == iv_mmioMap[idx].addr ||
        device_offset >= (uint64_t)iv_mmioMap[idx].size)
    {
        return false;
    }

    PageTableManager::addEntry((i_addr / PAGESIZE) * PAGESIZE,
                              (iv_mmioMap[idx].addr + device_offset) / PAGESIZE,
			       SegmentManager::CI_ACCESS);
    return true;
}

/**
 * @brief DEPRECATED
 */
void* DeviceSegment::_mmioMap(void* ra, size_t pages)
{
    for (size_t i = 0; i < MMIO_MAP_DEVICES; i++)
    {
        if (0 == iv_mmioMap[i].addr)
        {
            iv_mmioMap[i].size = THIRTYTWO_GB;
            iv_mmioMap[i].addr = reinterpret_cast<uint64_t>(ra);
            return reinterpret_cast<void*>(i *
                                      ((1ull << SLBE_s) / MMIO_MAP_DEVICES) +
                                      this->getBaseAddress());
        }
    }

    return NULL;
}

/**
 * @brief DEPRECATED
 */
int DeviceSegment::_mmioUnmap(void* ea, size_t pages)
{
    uint64_t segment_ea = reinterpret_cast<uint64_t>(ea) -
                          this->getBaseAddress();
    size_t idx = segment_ea / ((1ull << SLBE_s) / MMIO_MAP_DEVICES);
    if (0 != iv_mmioMap[idx].addr)
    {
        PageTableManager::delRangePN(iv_mmioMap[idx].addr / PAGESIZE,
                                     iv_mmioMap[idx].addr / PAGESIZE +
                                        pages);
        iv_mmioMap[idx].addr = 0;
        return 0;
    }

    return -EINVAL;
}

/**
 * @brief Map a device into the device segment(2TB)
 * @param ra[in] - Void pointer to real address to be mapped in
 * @param i_devDataSize[in] - Size of device segment block
 * @return void* - Pointer to beginning virtual address, NULL otherwise
 */
void *DeviceSegment::_devMap(void *ra, uint64_t i_devDataSize)
{
    void *segBlock = NULL;
    if (i_devDataSize <= THIRTYTWO_GB)
    {
        //TODO - Use segment block size if/when new device size needed
        for (size_t i = 0; i < MMIO_MAP_DEVICES; i++)
        {
            if (0 == iv_mmioMap[i].addr)
            {
                iv_mmioMap[i].size = i_devDataSize;
                iv_mmioMap[i].addr = reinterpret_cast<uint64_t>(ra);
                //TODO - Use segment block size if/when new device size needed
                segBlock = reinterpret_cast<void*>(i *
                        ((1ull << SLBE_s) / MMIO_MAP_DEVICES) +
                        this->getBaseAddress());
                break;
            }
        }
        if (segBlock == NULL)
        {
            printk("Unable to map device, no empty segment blocks found\n");
        }
    }
    else
    {
        printk("Unsupported device segment size(0x%lX), ",i_devDataSize);
        printk("for address 0x%lX\n",reinterpret_cast<uint64_t>(ra));
    }

    return segBlock;
}

/**
 * @brief Unmap a device from the device segment(2TB)
 * @param ea[in] - Void pointer to effective address
 * @return int - 0 for successful unmap, non-zero otherwise
 */
int DeviceSegment::_devUnmap(void *ea)
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
    //TODO - Calculate idx by segment block size if/when new device size needed
    size_t idx = segment_ea / ((1ull << SLBE_s) / MMIO_MAP_DEVICES);
    if (0 != iv_mmioMap[idx].addr)
    {
        //Remove all of the defined block's size (<= 32GB)
        PageTableManager::delRangePN(iv_mmioMap[idx].addr / PAGESIZE,
                (iv_mmioMap[idx].addr + iv_mmioMap[idx].size) / PAGESIZE);
        iv_mmioMap[idx].addr = 0;
        rc = 0;
    }

    return rc;
}
