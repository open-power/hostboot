/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/vmmmgr.C $                                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2010,2020                        */
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
#include <kernel/bltohbdatamgr.H>
#include <util/align.H>


extern void* data_load_address;
uint64_t VmmManager::g_patb[2];

VmmManager::VmmManager() : lock()
{
    printk("HRMOR = %lX\n", getHRMOR());
}

void VmmManager::init()
{

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

#ifdef CONFIG_P9_PAGE_TABLE
    v.initPartitionTable();
#else
    v.initSDR1();
#endif
};

void VmmManager::init_slb()
{
    VmmManager& v = Singleton<VmmManager>::instance();
    SegmentManager::initSLB();

#ifdef CONFIG_P9_PAGE_TABLE
    v.initPartitionTable();
#else
    v.initSDR1();
#endif
}

bool VmmManager::pteMiss(task_t* t, uint64_t effAddr, bool store)
{
    return Singleton<VmmManager>::instance()._pteMiss(t, effAddr, store);
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

void* VmmManager::devMap(void* ra, uint64_t i_devDataSize, bool i_nonCI,
    bool i_guarded)
{
    return Singleton<VmmManager>::instance()._devMap(ra, i_devDataSize,
                                                     i_nonCI, i_guarded);
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

void VmmManager::initPartitionTable()
{
    // Use SLB, not In-Memory Segment Tables (Process Table)
    // Set LPCR[41] (UPRT) = 0
    setLPCR(getLPCR() & (~0x0000000000400000));

    // Set the first partition table entry (PATE)
    // HTABORG, HTABSIZE = 0 (11 bits, 256k table)
    g_patb[0] = HTABORG();
    g_patb[1] = 0x0;

    // Init the PTCR reg
    // PATB, PATS = 0 (4k table)
    // PATB, PATS = 4 (64k table)
    setPTCR( reinterpret_cast<uint64_t>(g_patb) + getHRMOR() + 4 );
}

void VmmManager::initSDR1()
{
    // HTABORG, HTABSIZE = 0 (11 bits, 256k table)
    register uint64_t sdr1 = HTABORG();
    asm volatile("mtsdr1 %0" :: "r"(sdr1) : "memory");
}

bool VmmManager::_pteMiss(task_t* t, uint64_t effAddr, bool store)
{
    lock.lock();

    /* Allow out-of-memory conditions to pass without pageAllocate() calling
     * kassert. That way we can detect the error, unlock our spinlock, and
     * kassert ourselves without crossing paths with
     * printkBacktrace/findPhysicalAddress and deadlocking. */
    bool oom = false;

    bool rc = SegmentManager::handlePageFault(t, effAddr, store, &oom);

    lock.unlock();

    if (oom)
    {
        printk("_pteMiss failed due to OOM\n");
        kassert(false);
    }

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


int VmmManager::mmExtend(void)
{
    return Singleton<VmmManager>::instance()._mmExtend();
}

int VmmManager::_mmExtend(void)
{
    lock.lock();
    int rc = BaseSegment::mmExtend();
    lock.unlock();
    return rc;
}

void* VmmManager::_devMap(void* ra, uint64_t i_devDataSize, bool i_nonCI,
    bool i_guarded)
{
    void* ea = NULL;

    lock.lock();
    ea = SegmentManager::devMap(ra, i_devDataSize, i_nonCI, i_guarded);
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

uint64_t VmmManager::HTABORG()
{
    return static_cast<uint32_t>(pageTableOffset()) + getHRMOR();
}

uint64_t VmmManager::findKernelAddress(uint64_t i_vaddr)
{
    //in hypervisor mode the HRMOR is automatically ORed onto
    // the address so we need to tell the hardware to ignore it
    uint64_t phys = VmmManager::findPhysicalAddress(i_vaddr);
    if( static_cast<uint64_t>(-EFAULT) != phys )
    {
        phys |= FORCE_PHYS_ADDR;
    }
    return phys;
}

int VmmManager::mmLinearMap(void *i_paddr, uint64_t i_size)
{
    return Singleton<VmmManager>::instance()._mmLinearMap(i_paddr, i_size);
}

int VmmManager::_mmLinearMap(void *i_paddr, uint64_t i_size)
{
    lock.lock();
    int rc = BaseSegment::mmLinearMap(i_paddr, i_size);
    lock.unlock();
    return rc;
}

uint64_t VmmManager::pageTableOffset()
{
    return Singleton<VmmManager>::instance()._pageTableOffset();
}

uint64_t VmmManager::_pageTableOffset() const
{
    return ALIGN_X(_endPreservedOffset(), PT_ALIGNMENT);
}

uint64_t VmmManager::BlToHbPreserveDataOffset()
{
    return Singleton<VmmManager>::instance()._BlToHbPreserveDataOffset();
}

uint64_t VmmManager::_BlToHbPreserveDataOffset() const
{
    return  ALIGN_8(MAX_HBB_SIZE + g_BlToHbDataManager.getBlToHbDataSize());
}

uint64_t VmmManager::endPreservedOffset()
{
    return Singleton<VmmManager>::instance()._endPreservedOffset();
}

uint64_t VmmManager::_endPreservedOffset() const
{
    return ALIGN_PAGE(_BlToHbPreserveDataOffset() +
                      g_BlToHbDataManager.getPreservedSize());
}
