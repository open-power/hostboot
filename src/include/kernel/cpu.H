//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/kernel/cpu.H $
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

// Thread ID support only, Power8 (8 threads).
#define KERNEL_MAX_SUPPORTED_CPUS (8 * 16 * 8) // Sockets, cores, threads.

class Scheduler;

/** @struct cpu_t
 *  @brief Stores per-CPU kernel information.
 *
 *  @note kernel_stack and master need to be at fixed locations in this
 *        structure due to usages in start.S.
 *
 *  - kernel_stack is a double-word at cpu_t[0 bytes].
 *  - master is a byte at cpu_t[12 bytes].
 */
struct cpu_t
{
    /** Stack to use while in kernel mode. */
    void* kernel_stack;

    /** ID of the CPU (PIR value) */
    cpuid_t cpu;

    struct
    {
        /** If the CPU is the master */
        bool master:1;

        /** If the CPU is active */
        bool active:1;

        /** Ensure alignment of master attribute for asm code. */
        uint64_t __reserved_master:30;
    } PACKED;

    /** Pointer to the scheduler for this CPU (may not be unique) */
    Scheduler* scheduler;

    /** Location for scheduler to store per-CPU data, currently used
     *  for the local run-queue for processor affinity.
     */
    void* scheduler_extra;

    /** Location for task delay-list, managed by TimeManager. */
    void* delay_list;

    /** Pointer to the idle task for this CPU */
    task_t* idle_task;

    /** XSCOM mutex to serialize access per CPU */
    mutex_t xscom_mutex;

    /** counter for executePeriodics */
    size_t periodic_count;
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
