#include <kernel/console.H>

extern "C" void __assert(bool expr, const char *exprStr, 
			 const char *file, int line)
{
    // TODO    
    printk("Assert in %s (%d): %s\n", file, line, exprStr);
    while (true);
}

