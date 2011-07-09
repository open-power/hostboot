#include <limits.h>
#include <util/singleton.H>
#include <kernel/vmmmgr.H>
#include <kernel/console.H>
#include <arch/ppc.H>
#include <kernel/ptmgr.H>
#include <kernel/segmentmgr.H>
#include <kernel/devicesegment.H>
#include <kernel/basesegment.H>

extern void* data_load_address;

VmmManager::VmmManager() : lock()
{
}

void VmmManager::init()
{
    printk("Starting VMM...\n");

    VmmManager& v = Singleton<VmmManager>::instance();

    BaseSegment::init();
    DeviceSegment::init();
    SegmentManager::initSLB();

    v.initPTEs();
    v.initSDR1();

    printk("...done.\n");
};

void VmmManager::init_slb()
{
    VmmManager& v = Singleton<VmmManager>::instance();
    SegmentManager::initSLB();

    v.initSDR1();
}

bool VmmManager::pteMiss(task_t* t, uint64_t effAddr)
{
    return Singleton<VmmManager>::instance()._pteMiss(t, effAddr);
}

void* VmmManager::mmioMap(void* ra, size_t pages)
{
    return DeviceSegment::mmioMap(ra, pages);
}

int VmmManager::mmioUnmap(void* ea, size_t pages)
{
    return DeviceSegment::mmioUnmap(ea, pages);
}

void VmmManager::initPTEs()
{
    // Initialize and invalidate the page table
    PageTableManager::init();

    // There is no need to add PTE entries because the PTE-miss page fault
    // handler will add as-needed.
}

void VmmManager::initSDR1()
{
    // HTABORG, HTABSIZE = 0 (11 bits, 256k table)
    register uint64_t sdr1 = (uint64_t)HTABORG;
    asm volatile("mtsdr1 %0" :: "r"(sdr1) : "memory");
}

bool VmmManager::_pteMiss(task_t* t, uint64_t effAddr)
{
    lock.lock();

    bool rc = SegmentManager::handlePageFault(t, effAddr);

    lock.unlock();

    return rc;
}


