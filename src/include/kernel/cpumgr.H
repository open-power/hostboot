/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/cpumgr.H $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2010,2020                        */
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
#ifndef __KERNEL_CPUMGR_H
#define __KERNEL_CPUMGR_H

#include <kernel/types.h>
#include <kernel/cpu.H>
#include <kernel/barrier.H>
#include <kernel/idebug.H>

/** Desired value for MSR after wakeup.
 *
 *  bit 0 - 64 bit mode.
 *  bit 3 - Hypervisor mode.
 *  bit 51 - Machine-check enable
 */
extern const uint64_t WAKEUP_MSR_VALUE;

/** Desired value for LPCR after wakeup.
 *
 *  bit 48 - Wake-up from hyp doorbell
 *  bit 49 - Wake-up from external interrupt.
 *  bit 50 - Wake-up from decrementer.
 *  bit 51 - Wake-up from machine check.
 *  bit 60 - LPES(0) = 1 (see ISA).
 *  bit 61 - LPES(1) = 0 (P8 RFC02204 forces to 0)
 *  bit 62 - HVICE - Hypervisor Virt Interrupt Conditionally Enable
 */
extern const uint64_t WAKEUP_LPCR_VALUE;

/** Desired value for RPR after wakeup.
 *
 *      Priority     Us    PHYP
 *      Very Low      0      0
 *      Low           1      1    <--- hostboot "low"
 *      Med Low       3      3
 *      Med          32      7    <--- hostboot "high"
 *      Med High     33     15
 *      High         34     31
 *      Very High    63     63
 */
extern const uint64_t WAKEUP_RPR_VALUE;

/** The mask to isolate SMF enabled value
 *
 * bit 41 - SMF (Ultravisor) enable
 *
 */
extern const uint64_t MSR_SMF_MASK;

class CpuManager
{
    public:
        enum
        {
#ifdef CONFIG_P9_VPO_COMPILE // VPO has constrained mem env -> check sooner
            CPU_PERIODIC_CHECK_MEMORY = 64,
#else
            CPU_PERIODIC_CHECK_MEMORY = 128,    // Is this even needed anymore?
#endif
            CPU_PERIODIC_FLUSH_PAGETABLE = 256,
            CPU_PERIODIC_DEFRAG = 200,  // TODO Any bigger than 400 not
                                        // currently hit
        };

        /** @fn getCurrentCPU
         *  Returns a pointer to the current CPU structure by using the
         *  task structure in SPRG3.
         */
        static cpu_t* getCurrentCPU()
        {
            size_t pir = getPIR();
            return cv_cpus[pir / KERNEL_MAX_SUPPORTED_CPUS_PER_NODE]
                          [pir % KERNEL_MAX_SUPPORTED_CPUS_PER_NODE];
        }
        static cpu_t* getCpu(size_t i)
        {
            cpu_t** c = cv_cpus[i / KERNEL_MAX_SUPPORTED_CPUS_PER_NODE];

            if (NULL == c)
            {
                return NULL;
            }
            else
            {
                return c[i % KERNEL_MAX_SUPPORTED_CPUS_PER_NODE];
            }
        }

        /** @brief Return pointer to master CPU object.
        */
        static cpu_t* getMasterCPU();

        static void init();
        static void init_slave_smp(cpu_t*);

        /** @fn requestShutdown
         *  Requests that all CPUs shutdown
         */
        static void requestShutdown(uint64_t i_status, uint32_t i_error_data=0);

        /** @fn isShutdownRequested
         *  Returns if a shutdown of all CPUs was requested
         */
        static bool isShutdownRequested() { return cv_shutdown_requested; }

        /** @fn getShutdownStatus
         *  Returns the status code that needs to be posted during shutdown
         */
        static uint32_t getShutdownStatus() { return cv_shutdown_status; }

        /** @fn executePeriodics
         * Perform periodic actions
         * @param[in] cpu_t the CPU
         */
        static void executePeriodics(cpu_t * i_cpu);

        /** @fn activateCPU
         * Activate a cpu to show it is running
         * @param[in] cpu_t the CPU
         * @post Active flag on in cpu_t structure
         */
        static void activateCPU(cpu_t * i_cpu);

        /** @fn deactivateCPU
         *  Deactivate a cpu to show it is not running.
         *  @param[in] cpu_t the CPU
         *  @post Active flag is off in cpu_t structure.
         */
        static void deactivateCPU(cpu_t * i_cpu);

        /** @fn getCpuCount
         *  Return the number of active CPUs.
         */
        static size_t getCpuCount() { return cv_cpuSeq & 0xFFFFFFFF; }

        /** @fn getCpuSeqId
         *  Return the current CPU start sequence ID.
         */
        static size_t getCpuSeqId() { return cv_cpuSeq >> 32; }

        /** @fn getCpuCountAndSeqId
         *  Atomically retrieve both the current active CPU count and
         *  sequence ID.
         *
         */
        static void getCpuCountAndSeqId(uint32_t& o_count, uint32_t& o_seq)
        {
            uint64_t cpuSeq = cv_cpuSeq;
            o_count = cpuSeq & 0xFFFFFFFF;
            o_seq = cpuSeq >> 32;
        }

        /** @fn getThreadCount
         *  Return the number of HW threads for this CPU core type.
         */
        static size_t getThreadCount();

        /** @fn startCore
         *  Create structures to support a core activating and start the core.
         *
         *  @param[in] pir - PIR value of first thread in core.
         *  @param[in] i_threads - Bitstring of threads to enable (left-justified).
         */
        static void startCore(uint64_t pir,uint64_t i_threads);


        /** @fn wakeupCore
         *  Start the core, can only be run after startCore.
         *
         *  @param[in] pir - PIR value of first thread in core.
         *  @param[in] i_threads - Bitstring of threads to enable (left-justified).
         */
        static void wakeupCore(uint64_t pir,uint64_t i_threads);


        /** @fn forceMemoryPeriodic()
         * Force the memory free / coalesce operations to be performed on the
         * next "periodic" interval.
         */
        static void forceMemoryPeriodic();


        /** @fn critAssert()
         * Functional call to force terminate immediate on all threads
         * @param[in] i_failAddr - Address from where the assert was called
         */
        static void critAssert(uint64_t i_failAddr);

        /** @fn startCPU
         *  Starts the requested CPU. Default of -1 implies current CPU.
         */
        void startCPU(ssize_t i = -1);

    protected:
        CpuManager();
        ~CpuManager() {}

        void startSlaveCPU(cpu_t*);

    private:
        /** Per-CPU kernel structures.
         *
         *  There is one entry per hardware thread and they are stored as
         *  a two dimensional array of (cpu_t*)s: cv_cpus[node][thread]
         *
         *  This needs to be a global variable rather than an instance
         *  variable of a singleton because it is needed within the kernel
         *  assembly code for interrupt / exception handling.  For instance,
         *  when secondary CPUs start they need to find their own stack from
         *  these structures.  Any changes to this structure needs to be
         *  kept in sync with the assembly code (ex. start.S).
         */
        static cpu_t** cv_cpus[KERNEL_MAX_SUPPORTED_NODES];


            /** Number of active CPUs.
             *  Stored as "(seqID << 32) | cpus"
             */
        static uint64_t cv_cpuSeq;

        static uint8_t cv_forcedMemPeriodic;       //!<  force free / coalesce.

        // If a shutdown of all CPUs is requested
        static bool cv_shutdown_requested;

        // The status code that needs to be posted during shutdown
        static uint64_t cv_shutdown_status;

        static InteractiveDebug cv_interactive_debug;

        /** Timebase of the master the last time a CPU was started.
         *
         *  This is used when slave CPUs activate to determine if the
         *  timebases need to be synchronized.
         */
        uint64_t iv_lastStartTimebase;

};

#endif
