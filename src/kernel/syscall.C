#include <kernel/console.H>

extern "C"
void kernel_execute_decrementer()
{
    //printk("Decrementer.\n");
    
    // Resync decrementer.
    register uint64_t decrementer = 0x0f000000;
    asm volatile("mtdec %0" :: "r"(decrementer));
}

extern "C"
void kernel_execute_systemcall()
{
    //printk("Syscall.\n");
}
