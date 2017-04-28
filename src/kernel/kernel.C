/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/kernel.C $                                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2010,2017                        */
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
#include <stdint.h>
#include <kernel/console.H>
#include <kernel/pagemgr.H>
#include <kernel/heapmgr.H>
#include <kernel/cpumgr.H>
#include <util/singleton.H>
#include <kernel/cpu.H>
#include <kernel/task.H>
#include <kernel/scheduler.H>
#include <kernel/taskmgr.H>
#include <kernel/vmmmgr.H>
#include <kernel/timemgr.H>
#include <sys/vfs.h>
#include <kernel/deferred.H>
#include <kernel/misc.H>
#include <util/align.H>
#include <securerom/sha512.H>
#include <kernel/bltohbdatamgr.H>
#include <kernel/cpuid.H>

#include <stdlib.h>

extern "C" void kernel_dispatch_task();
extern void* init_main(void* unused);
extern uint64_t kernel_other_thread_spinlock;


class Kernel
{
    public:
	void cppBootstrap();
	void memBootstrap();
	void cpuBootstrap();
	void inittaskBootstrap();

    protected:
	Kernel() {};
};

extern "C"
int main()
{
    printk("Booting %s kernel...\n\n", "Hostboot");
    printk("CPU=%s\n",
           ProcessorCoreTypeStrings[CpuID::getCpuType()]);

    // Erase task-pointer so that TaskManager::getCurrentTask() returns NULL.
    setSPRG3(NULL);

    Kernel& kernel = Singleton<Kernel>::instance();
    kernel.cppBootstrap();

    // Get pointer to BL and HB comm data
    const auto l_pBltoHbData = reinterpret_cast<const Bootloader::BlToHbData*>(
                                                        BLTOHB_COMM_DATA_ADDR);

    if ( Bootloader::BlToHbDataValid(l_pBltoHbData) )
    {
        printk("BL to HB comm valid\n");

        // Make copy of structure so to not modify original pointers
        auto l_blToHbDataCopy = *l_pBltoHbData;

        // Get destination location that will be preserved by the pagemgr
        auto l_pBltoHbDataStart = reinterpret_cast<uint8_t *>(
                                                 VmmManager::BLTOHB_DATA_START);
        // Copy in SecureRom
        memcpy(l_pBltoHbDataStart,
               l_blToHbDataCopy.secureRom,
               l_blToHbDataCopy.secureRomSize);
        // Change pointer to new location and increment
        l_blToHbDataCopy.secureRom = l_pBltoHbDataStart;
        l_pBltoHbDataStart += l_blToHbDataCopy.secureRomSize;

        // Copy in HW keys' Hash
        memcpy(l_pBltoHbDataStart,
               l_blToHbDataCopy.hwKeysHash,
               l_blToHbDataCopy.hwKeysHashSize);
        // Change pointer to new location and increment
        l_blToHbDataCopy.hwKeysHash = l_pBltoHbDataStart;
        l_pBltoHbDataStart += l_blToHbDataCopy.hwKeysHashSize;

        // Copy in HBB header
        memcpy(l_pBltoHbDataStart,
               l_blToHbDataCopy.hbbHeader,
               l_blToHbDataCopy.hbbHeaderSize);
        // Change pointer to new location
        l_blToHbDataCopy.hbbHeader = l_pBltoHbDataStart;

        // Initialize Secureboot Data class
        g_BlToHbDataManager.initValid(l_blToHbDataCopy);
    }
    else
    {
        printk("BL to HB commun invalid\n");
        // Force invalidation of securebootdata
        g_BlToHbDataManager.initInvalid();
    }

    kernel.memBootstrap();
    kernel.cpuBootstrap();

    // Let FSP/BMC know that Hostboot is now running
    KernelMisc::setHbScratchStatus(KernelMisc::HB_RUNNING);

    kernel.inittaskBootstrap();

    // Ready to let the other CPUs go.
    lwsync();
    kernel_other_thread_spinlock = 1;

    kernel_dispatch_task(); // no return.
    while(1);
    return 0;
}

extern "C"
int smp_slave_main(cpu_t* cpu)
{
    // Erase task-pointer so that TaskManager::getCurrentTask() returns NULL.
    setSPRG3(NULL);

    CpuManager::init_slave_smp(cpu);
    VmmManager::init_slb();
    cpu->scheduler->setNextRunnable();
    DeferredQueue::execute();
    kernel_dispatch_task();
    return 0;
}

void Kernel::cppBootstrap()
{
    // Call default constructors for any static objects.
    extern void (*ctor_start_address)();
    extern void (*ctor_end_address)();
    void(**ctors)() = &ctor_start_address;
    while(ctors != &ctor_end_address)
    {
        (*ctors)();
        ctors++;
    }
}

void Kernel::memBootstrap()
{
    PageManager::init();
    HeapManager::init();
    VmmManager::init();
}

void Kernel::cpuBootstrap()
{
    TimeManager::init();
    CpuManager::init();
}

void Kernel::inittaskBootstrap()
{
    task_t * t = TaskManager::createTask(&init_main, NULL, true);
    t->cpu = CpuManager::getCurrentCPU();
    TaskManager::setCurrentTask(t);
}

