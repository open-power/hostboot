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

#include <stdlib.h>

extern "C" void kernel_dispatch_task();
extern void init_main(void* unused);

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

int main()
{
    printk("Booting %s kernel...\n\n", "Chenoo");
    
    Kernel& kernel = Singleton<Kernel>::instance();
    kernel.cppBootstrap();
    kernel.memBootstrap(); 
    kernel.cpuBootstrap();

    kernel.inittaskBootstrap();

    kernel_dispatch_task(); // no return.    
    while(1);
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
}

void Kernel::cpuBootstrap()
{
    CpuManager::init();
}

void Kernel::inittaskBootstrap()
{
    task_t * t = TaskManager::createTask(&init_main, NULL);
    t->cpu = CpuManager::getCurrentCPU();
    TaskManager::setCurrentTask(t);

}

