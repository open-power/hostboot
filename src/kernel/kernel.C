//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/kernel/kernel.C $
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

#include <stdlib.h>

extern "C" void kernel_dispatch_task();
extern void init_main(void* unused);
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
    
    Kernel& kernel = Singleton<Kernel>::instance();
    kernel.cppBootstrap();
    kernel.memBootstrap(); 
    kernel.cpuBootstrap();

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
    CpuManager::init_slave_smp(cpu);
    VmmManager::init_slb();
    cpu->scheduler->setNextRunnable();
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
    task_t * t = TaskManager::createTask(&init_main, NULL);
    t->cpu = CpuManager::getCurrentCPU();
    TaskManager::setCurrentTask(t);
}

