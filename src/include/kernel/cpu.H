#ifndef __KERNEL_CPU_H
#define __KERNEL_CPU_H

#include <kernel/types.h>
#include <arch/ppc.H>
#include <builtins.h>

// Thread ID support only, Power7 (4 threads).
#define KERNEL_MAX_SUPPORTED_CPUS 4

class Scheduler;

struct cpu_t
{
    void* kernel_stack;
    cpuid_t cpu;

    Scheduler* scheduler;
    task_t* idle_task;
};

ALWAYS_INLINE
inline uint64_t getCpuId()
{
    return getPIR() & (KERNEL_MAX_SUPPORTED_CPUS - 1);
}

#endif
