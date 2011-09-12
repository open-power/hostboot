//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/kernel/cpumgr.H $
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
#ifndef __KERNEL_CPUMGR_H
#define __KERNEL_CPUMGR_H

#include <kernel/types.h>
#include <kernel/cpu.H>

class CpuManager
{
    public:
	enum 
        { 
            MAXCPUS = KERNEL_MAX_SUPPORTED_CPUS,
            CPU_PERIODIC_CHECK_MEMORY = 64,
            CPU_PERIODIC_FLUSH_PAGETABLE = 1024,
        };

	/** @fn getCurrentCPU
	 *  Returns a pointer to the current CPU structure by using the
	 *  task structure in SPRG3.
	 */
	static cpu_t* getCurrentCPU();
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


    protected:
	CpuManager();
	~CpuManager() {}

	/** @fn startCPU
	 *  Starts the requested CPU. Default of -1 implies current CPU.
	 */
	void startCPU(ssize_t i = -1);
	void startSlaveCPU(cpu_t*);

    private:
	static cpu_t* cv_cpus[MAXCPUS]; // Need to be able to access this
					// from start.S to get initial stacks
					// of secondary cpus / threads.

    // If a shutdown of all CPUs is requested
    static bool cv_shutdown_requested;

    // The status code that needs to be posted during shutdown
    static uint64_t cv_shutdown_status;
};

#endif
