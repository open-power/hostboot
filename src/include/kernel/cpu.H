/** @file cpu.H
 *  @brief Defines kernel information and functions about CPUs.
 *  
 *  In this kernel the term CPU refers to a hardware thread (SMT), not core.
 */
#ifndef __KERNEL_CPU_H
#define __KERNEL_CPU_H

#include <kernel/types.h>
#include <arch/ppc.H>
#include <builtins.h>
#include <sys/sync.h>

// Thread ID support only, Power7 (4 threads).
#define KERNEL_MAX_SUPPORTED_CPUS (4 * 8 * 4) // Sockets, cores, threads.

class Scheduler;

/** @struct cpu_t
 *  @brief Stores per-CPU kernel information.
 */
struct cpu_t
{
        /** Stack to use while in kernel mode. */
    void* kernel_stack;
        /** ID of the CPU (PIR value) */
    cpuid_t cpu;
        
        /** Pointer to the scheduler for this CPU (may not be unique) */
    Scheduler* scheduler;
        /** Location for scheduler to store per-CPU data, currently used
         *  for the local run-queue for processor affinity.
         */
    void* scheduler_extra;
        /** Pointer to the idle task for this CPU */
    task_t* idle_task;

        /** XSCOM mutex to serialize access per CPU */
    mutex_t * xscom_mutex;
};

/** @fn getCpuId
 *  @brief Read the PIR value to determine the cpuid_t of this CPU.
 */
ALWAYS_INLINE
inline cpuid_t getCpuId()
{
    return getPIR() & (KERNEL_MAX_SUPPORTED_CPUS - 1);
}

#endif
