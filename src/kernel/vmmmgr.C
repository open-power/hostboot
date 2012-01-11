//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/kernel/vmmmgr.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2010 - 2011
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
#include <kernel/vmmmgr.H>
#include <kernel/console.H>
#include <arch/ppc.H>
#include <kernel/ptmgr.H>
#include <kernel/segmentmgr.H>
#include <kernel/basesegment.H>
#include <kernel/stacksegment.H>
#include <kernel/devicesegment.H>

extern void* data_load_address;

VmmManager::VmmManager() : lock()
{
}

void VmmManager::init()
{
    printk("Starting VMM...\n");

    VmmManager& v = Singleton<VmmManager>::instance();

    BaseSegment::init();
    StackSegment::init();
    for (size_t i = SegmentManager::MMIO_FIRST_SEGMENT_ID;
                i < SegmentManager::MMIO_LAST_SEGMENT_ID; ++i)
    {
        new DeviceSegment(i); // Self-registers with SegmentManager.
    }
    SegmentManager::initSLB();

    v.initPTEs();
    v.initSDR1(); /*no effect*/ // BEAM Fix.

    printk("...done.\n");
};

void VmmManager::init_slb()
{
    VmmManager& v = Singleton<VmmManager>::instance();
    SegmentManager::initSLB();

    v.initSDR1(); /*no effect*/ // BEAM Fix.
}

bool VmmManager::pteMiss(task_t* t, uint64_t effAddr)
{
    return Singleton<VmmManager>::instance()._pteMiss(t, effAddr);
}

uint64_t VmmManager::findPhysicalAddress(uint64_t i_vaddr)
{
    return Singleton<VmmManager>::instance()._findPhysicalAddress(i_vaddr);
}

void VmmManager::castOutPages(VmmManager::castout_t i_ct)
{
    Singleton<VmmManager>::instance()._castOutPages(i_ct);
}

void VmmManager::flushPageTable( void )
{
    Singleton<VmmManager>::instance()._flushPageTable();
}

void* VmmManager::devMap(void* ra, uint64_t i_devDataSize)
{
    return Singleton<VmmManager>::instance()._devMap(ra, i_devDataSize);
}

int VmmManager::devUnmap(void* ea)
{
    return Singleton<VmmManager>::instance()._devUnmap(ea);
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

int VmmManager::mmAllocBlock(MessageQueue* i_mq,void* i_va,uint64_t i_size)
{
    return Singleton<VmmManager>::instance()._mmAllocBlock(i_mq,i_va,i_size);
}

int VmmManager::_mmAllocBlock(MessageQueue* i_mq,void* i_va,uint64_t i_size)
{
    lock.lock();
    int rc = BaseSegment::mmAllocBlock(i_mq,i_va,i_size);
    lock.unlock();
    return rc;
}

Spinlock* VmmManager::getLock()
{
    return &Singleton<VmmManager>::instance().lock;
}

uint64_t VmmManager::_findPhysicalAddress(uint64_t i_vaddr)
{
    uint64_t paddr = 0;

    lock.lock();

    paddr = SegmentManager::findPhysicalAddress(i_vaddr);

    lock.unlock();

    return paddr;
}

int VmmManager::mmRemovePages(VmmManager::PAGE_REMOVAL_OPS i_op, void* i_vaddr,
                              uint64_t i_size, task_t* i_task)
{
    return Singleton<VmmManager>::instance()._mmRemovePages(i_op,i_vaddr,
                                                            i_size,i_task);
}

int VmmManager::_mmRemovePages(VmmManager::PAGE_REMOVAL_OPS i_op,void* i_vaddr,
                               uint64_t i_size,task_t* i_task)
{
    lock.lock();
    int rc = BaseSegment::mmRemovePages(i_op,i_vaddr,i_size,i_task);
    lock.unlock();
    return rc;
}

int VmmManager::mmSetPermission(void* i_va, uint64_t i_size, uint64_t i_access_type)
{
    return Singleton<VmmManager>::instance()._mmSetPermission(i_va, i_size, i_access_type);
}


int VmmManager::_mmSetPermission(void* i_va, uint64_t i_size, uint64_t i_access_type)
{
    int rc = 1;

    lock.lock();

    rc = BaseSegment::mmSetPermission(i_va, i_size, i_access_type);

    lock.unlock();

    return rc;
}

void VmmManager::_castOutPages(VmmManager::castout_t i_ct)
{
    lock.lock();

    SegmentManager::castOutPages((uint64_t)i_ct);

    lock.unlock();
}

void VmmManager::_flushPageTable( void )
{
    lock.lock();

    PageTableManager::flush();

    lock.unlock();
}

void* VmmManager::_devMap(void* ra, uint64_t i_devDataSize)
{
    void* ea = NULL;

    lock.lock();
    ea = SegmentManager::devMap(ra, i_devDataSize);
    lock.unlock();

    return ea;
}

int VmmManager::_devUnmap(void* ea)
{
    int rc = 0;

    lock.lock();
    rc = SegmentManager::devUnmap(ea);
    lock.unlock();

    return rc;
}

