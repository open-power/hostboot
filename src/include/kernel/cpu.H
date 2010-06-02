#ifndef __KERNEL_CPU_H
#define __KERNEL_CPU_H

#include <kernel/types.h>

class Scheduler;

struct cpu_t
{
    cpuid_t cpu;

    Scheduler* scheduler;
    void* kernel_stack;
};

#endif
