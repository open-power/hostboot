#include <kernel/console.H>
#include <kernel/cpu.H>
#include <kernel/cpumgr.H>
#include <kernel/scheduler.H>

extern "C"
void kernel_execute_decrementer()
{
    //printk("Decrementer.\n");

    Scheduler* s = CpuManager::getCurrentCPU()->scheduler;
    s->returnRunnable();
    s->setNextRunnable();

    // Resync decrementer.
    register uint64_t decrementer = 0x0f000000;
    asm volatile("mtdec %0" :: "r"(decrementer));
}

extern "C"
void kernel_execute_systemcall()
{
    //printk("Syscall.\n");
}
