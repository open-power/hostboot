#include <stdint.h>
#include <kernel/console.H>
#include <util/singleton.H>

class Kernel
{
    public:
	void cppBootstrap();	

    protected:
	Kernel() {};
};

int main()
{
    printk("Booting Chenoo kernel...\n");
    
    Kernel& kernel = Singleton<Kernel>::instance();
    kernel.cppBootstrap();

    while(1);
    return 0;
}

void Kernel::cppBootstrap()
{
    // Call default constructors for any static objects.
    extern void (*ctor_start)();
    extern void (*ctor_end)();
    void(**ctors)() = &ctor_start;
    while(ctors != &ctor_end)
    {
	(*ctors)();
	ctors++;
    }
}

