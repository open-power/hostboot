#include <util/singleton.H>
#include <limits.h>

#include <kernel/vmmmgr.H>
#include <kernel/ptmgr.H>
#include <kernel/devicesegment.H>
#include <kernel/segmentmgr.H>

#define SLBE_s 40

#include <kernel/console.H>

void DeviceSegment::init()
{
    Singleton<DeviceSegment>::instance()._init();
}

void* DeviceSegment::mmioMap(void* ra, size_t pages)
{
    return Singleton<DeviceSegment>::instance()._mmioMap(ra, pages);
}

int DeviceSegment::mmioUnmap(void* ea, size_t pages)
{
    return Singleton<DeviceSegment>::instance()._mmioUnmap(ea, pages);
}

void DeviceSegment::_init()
{
    SegmentManager::addSegment(this, SegmentManager::MMIO_SEGMENT_ID);
}

bool DeviceSegment::handlePageFault(task_t* i_task, uint64_t i_addr)
{
    // Check address range.
    if (i_addr < this->getBaseAddress() ||
        i_addr >= (this->getBaseAddress() + 0x010000000000ull))
    {
        return false;
    }

    // Check valid device.
    uint64_t segment_ea = i_addr - this->getBaseAddress();
    size_t idx = segment_ea / ((1ull << SLBE_s) / MMIO_MAP_DEVICES);
    uint64_t device_offset = segment_ea - 
                                (idx * (1ull << SLBE_s) / MMIO_MAP_DEVICES);
    
    if (0 == iv_mmioMap[idx])
    {
        return false;
    }

    PageTableManager::addEntry((i_addr / PAGESIZE) * PAGESIZE,
                               (iv_mmioMap[idx] + device_offset) / PAGESIZE,
                               VmmManager::CI_ACCESS);
    return true;
}

void* DeviceSegment::_mmioMap(void* ra, size_t pages)
{
    for (size_t i = 0; i < MMIO_MAP_DEVICES; i++)
    {
        if (0 == iv_mmioMap[i])
        {
            iv_mmioMap[i] = reinterpret_cast<uint64_t>(ra);
            return reinterpret_cast<void*>(i * 
                                      ((1ull << SLBE_s) / MMIO_MAP_DEVICES) +
                                      this->getBaseAddress());
        }
    }

    return NULL;
}

int DeviceSegment::_mmioUnmap(void* ea, size_t pages)
{
    uint64_t segment_ea = reinterpret_cast<uint64_t>(ea) - 
                          this->getBaseAddress();
    size_t idx = segment_ea / ((1ull << SLBE_s) / MMIO_MAP_DEVICES);
    if (0 != iv_mmioMap[idx])
    {
        PageTableManager::delRangePN(iv_mmioMap[idx] / PAGESIZE,
                                     iv_mmioMap[idx] / PAGESIZE +
                                        pages);
        iv_mmioMap[idx] = 0;        
        return 0;
    }

    return -1;
}

