#include <stdint.h>
#include <kernel/console.H>
#include <kernel/pagemgr.H>
#include <kernel/heapmgr.H>
#include <kernel/cpumgr.H>
#include <util/singleton.H>

#include <stdlib.h>

class Kernel
{
    public:
	void cppBootstrap();	
	void memBootstrap();
	void cpuBootstrap();

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

