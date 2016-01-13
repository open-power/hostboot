/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/cpu.H $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2010,2016                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/** @file cpu.H
 *  @brief Defines kernel information and functions about CPUs.
 *
 *  In this kernel the term CPU refers to a hardware thread (SMT), not core.
 */
#ifndef __KERNEL_CPU_H
#define __KERNEL_CPU_H

#include <kernel/types.h>
#include <kernel/workitem.H>
#include <arch/ppc.H>
#include <builtins.h>
#include <sys/sync.h>
#include <util/lockfree/stack.H>

// See BookIV PIR definition.
#define KERNEL_MAX_SUPPORTED_NODES 8
#define KERNEL_MAX_SUPPORTED_CPUS_PER_NODE (8 * 16 * 8) // Chip, core, thread.

class Scheduler;

/** @struct cpu_t
 *  @brief Stores per-CPU kernel information.
 *
 *  @note kernel_stack and master need to be at fixed locations in this
 *        structure due to usages in start.S (see ppcconsts.S).
 *
 *  - kernel_stack is a double-word at cpu_t[0 bytes].
 *  - master is a byte at cpu_t[12 bytes].
 */
struct cpu_t
{
    /** Stack to use while in kernel mode. */
    void* kernel_stack;

    /** Bottom of the kernel stack. */
    void* kernel_stack_bottom;

    /** ID of the CPU (PIR value) */
    cpuid_t cpu;

    struct
    {
        /** If the CPU is the master */
        bool master:1;

        /** If the CPU is active */
        bool active:1;

        /** If the CPU is winkled */
        bool winkled:1;

        /** Ensure alignment of master attribute for asm code. */
        uint64_t __reserved_master:29;
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
    mutex_t* xscom_mutex;

    /** counter for executePeriodics */
    size_t periodic_count;

    /** Sequence ID of CPU initialization. */
    uint64_t cpu_start_seqid;

    /** Stack of WorkItems to be executed during doorbell wakeup */
    Util::Lockfree::Stack<KernelWorkItem> doorbell_actions;
};

/** @fn getCpuId
 *  @brief Read the PIR value to determine the cpuid_t of this CPU.
 */
ALWAYS_INLINE
inline cpuid_t getCpuId()
{
    return getPIR();
}

#endif
