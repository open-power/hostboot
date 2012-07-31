/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/include/kernel/cpumgr.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2010-2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
#ifndef __KERNEL_CPUMGR_H
#define __KERNEL_CPUMGR_H

#include <kernel/types.h>
#include <kernel/cpu.H>
#include <kernel/barrier.H>
#include <kernel/idebug.H>

class CpuManager
{
    public:
        enum
        {
            MAXCPUS = KERNEL_MAX_SUPPORTED_CPUS,
            CPU_PERIODIC_CHECK_MEMORY = 128,    // Is this even needed anymore?
            CPU_PERIODIC_FLUSH_PAGETABLE = 256,
            CPU_PERIODIC_DEFRAG = 949,  // TODO Any bigger not currently hit
        };

        /** @fn getCurrentCPU
         *  Returns a pointer to the current CPU structure by using the
         *  task structure in SPRG3.
         */
        static cpu_t* getCurrentCPU() { return cv_cpus[getPIR()]; }
        static cpu_t* getCpu(size_t i) { return cv_cpus[i]; }

        /** @brief Return pointer to master CPU object.
        */
        static cpu_t* getMasterCPU();

        static void init();
        static void init_slave_smp(cpu_t*);

        /** @fn requestShutdown
         *  Requests that all CPUs shutdown
         */
        static void requestShutdown(uint64_t i_status);

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
         */
        static int startCore(uint64_t pir);


        /** @fn forceMemoryPeriodic()
         * Force the memory free / coalesce operations to be performed on the
         * next "periodic" interval.
         */
        static void forceMemoryPeriodic();

        /** Desired value for MSR after wakeup.
         *
         *  bit 0 - 64 bit mode.
         *  bit 3 - Hypervisor mode.
         */
        static const uint64_t WAKEUP_MSR_VALUE =    0x9000000000000000;

        /** Desired value for LPCR after wakeup.
         *
         *  bit 49 - Wake-up from external interrupt.
         *  bit 50 - Wake-up from decrementer.
         *  bit 51 - Wake-up from machine check.
         *  bit 60, 61 - LPES(0,1) = 1 (see ISA).
         */
        static const uint64_t WAKEUP_LPCR_VALUE =   0x000000000000700C;

    protected:
        CpuManager();
        ~CpuManager() {}

        /** @fn startCPU
         *  Starts the requested CPU. Default of -1 implies current CPU.
         */
        void startCPU(ssize_t i = -1);
        void startSlaveCPU(cpu_t*);

    private:
        static cpu_t** cv_cpus; // Need to be able to access this
                                        // from start.S to get initial stacks
                                        // of secondary cpus / threads.

            /** Number of active CPUs.
             *  Stored as "(seqID << 32) | cpus"
             */
        static uint64_t cv_cpuSeq;

        static bool cv_forcedMemPeriodic;       //!<  force free / coalesce.

        // If a shutdown of all CPUs is requested
        static bool cv_shutdown_requested;

        // The status code that needs to be posted during shutdown
        static uint64_t cv_shutdown_status;

        static InteractiveDebug cv_interactive_debug;

};

#endif
