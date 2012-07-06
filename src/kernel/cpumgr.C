/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/kernel/cpumgr.C $
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
#include <assert.h>
#include <kernel/cpumgr.H>
#include <kernel/task.H>
#include <kernel/cpu.H>
#include <kernel/scheduler.H>
#include <kernel/taskmgr.H>
#include <kernel/pagemgr.H>
#include <kernel/console.H>
#include <util/singleton.H>
#include <arch/ppc.H>
#include <kernel/timemgr.H>
#include <sys/sync.h>
#include <kernel/cpuid.H>
#include <kernel/ptmgr.H>
#include <kernel/heapmgr.H>

cpu_t* CpuManager::cv_cpus[CpuManager::MAXCPUS] = { NULL };
bool CpuManager::cv_shutdown_requested = false;
uint64_t CpuManager::cv_shutdown_status = 0;
Barrier CpuManager::cv_barrier;
bool CpuManager::cv_defrag = false;
size_t CpuManager::cv_cpuCount = 0;
InteractiveDebug CpuManager::cv_interactive_debug;

CpuManager::CpuManager()
{
    for (int i = 0; i < MAXCPUS; i++)
	cv_cpus[i] = NULL;

    memset(&cv_interactive_debug, '\0', sizeof(cv_interactive_debug));
}

cpu_t* CpuManager::getCurrentCPU()
{
    return cv_cpus[getPIR()];
}

cpu_t* CpuManager::getMasterCPU()
{
    for (int i = 0; i < MAXCPUS; i++)
        if (cv_cpus[i] != NULL)
            if (cv_cpus[i]->master)
                return cv_cpus[i];
    return NULL;
}

void CpuManager::init()
{
    // For the initial boot we only want to set up CPU objects for the threads
    // on this core.  Otherwise we waste memory with kernel / idle task stacks.
    //
    // As long as the CPU object pointer is NULL, the start.S code won't
    // enter the kernel, so we skip initializing all the other CPUs for now.

    // Determine number of threads on this core.
    size_t threads = -1;
    switch (CpuID::getCpuType())
    {
        case CORE_POWER7:
        case CORE_POWER7_PLUS:
            threads = 4;
            break;

        case CORE_POWER8_VENICE:
        case CORE_POWER8_MURANO:
            threads = 8;
            break;

        case CORE_UNKNOWN:
        default:
            kassert(false);
            break;
    }

    // Create CPU objects starting at the thread-0 for this core.
    size_t baseCpu = getPIR() & ~(threads-1);
    for (size_t i = 0; i < threads; i++)
        Singleton<CpuManager>::instance().startCPU(i + baseCpu);
}

void CpuManager::init_slave_smp(cpu_t* cpu)
{
    Singleton<CpuManager>::instance().startSlaveCPU(cpu);
}

void CpuManager::requestShutdown(uint64_t i_status)
{
    cv_shutdown_status = i_status;
    __sync_synchronize();
    cv_shutdown_requested = true;
}

void CpuManager::startCPU(ssize_t i)
{
    bool currentCPU = false;
    if (i < 0)
    {
	i = getCpuId();
	currentCPU = true;
    }
    else if (getCpuId() == (uint64_t)i)
    {
	currentCPU = true;
    }

    // Initialize CPU structure.
    if (NULL == cv_cpus[i])
    {
	printk("Starting CPU %ld...", i);
	cpu_t* cpu = cv_cpus[i] = new cpu_t;

	// Initialize CPU.
	cpu->cpu = i;
        if (currentCPU)
        {
            cpu->master = true;
        }
        else
        {
            cpu->master = false;
        }
	cpu->scheduler = &Singleton<Scheduler>::instance();
        cpu->scheduler_extra = NULL;
	cpu->kernel_stack =
	    (void*) (((uint64_t)PageManager::allocatePage(4)) + 16320);
        cpu->xscom_mutex = (mutex_t)MUTEX_INITIALIZER;

	// Create idle task.
	cpu->idle_task = TaskManager::createIdleTask();
	cpu->idle_task->cpu = cpu;
        cpu->periodic_count = 0;

	printk("done\n");
    }

    if (currentCPU)
    {
        setDEC(TimeManager::getTimeSliceCount());
        activateCPU(cv_cpus[i]);
    }
    return;
}

void CpuManager::startSlaveCPU(cpu_t* cpu)
{
    setDEC(TimeManager::getTimeSliceCount());
    activateCPU(cpu);

    return;
}

void CpuManager::activateCPU(cpu_t * i_cpu)
{
    i_cpu->active = true;
    __sync_fetch_and_add(&cv_cpuCount, 1);
    lwsync();
}

void CpuManager::executePeriodics(cpu_t * i_cpu)
{
    if(i_cpu->master)
    {
        if (cv_interactive_debug.isReady())
        {
            cv_interactive_debug.startDebugTask();
        }

        ++(i_cpu->periodic_count);
        if(0 == (i_cpu->periodic_count % CPU_PERIODIC_CHECK_MEMORY))
        {
            uint64_t pcntAvail = PageManager::queryAvail();
            if(pcntAvail < PageManager::LOWMEM_NORM_LIMIT)
            {
                VmmManager::flushPageTable();
                ++(i_cpu->periodic_count);   // prevent another flush below
                if(pcntAvail < PageManager::LOWMEM_CRIT_LIMIT)
                {
                    VmmManager::castOutPages(VmmManager::CRITICAL);
                }
                else
                {
                    VmmManager::castOutPages(VmmManager::NORMAL);
                }
            }
        }
        if(0 == (i_cpu->periodic_count % CPU_PERIODIC_FLUSH_PAGETABLE))
        {
            VmmManager::flushPageTable();
        }
        if(0 == (i_cpu->periodic_count % CPU_PERIODIC_DEFRAG))
        {
            // set up barrier based on # cpus cv_barrier;
            // TODO whatif other cpus become active?
            isync(); // Ensure all instructions complete before this point, so
                     // we don't get a stale shutdown_requested.
            if(!cv_shutdown_requested)
            {
                cv_barrier.init(cv_cpuCount);
                lwsync();  // Ensure barrier init is globally visible before
                           // setting defrag = true.
                cv_defrag = true;
            }
        }
    }
    if(cv_defrag)
    {
        cv_barrier.wait();

        if(i_cpu->master)
        {
            HeapManager::coalesce();
            PageManager::coalesce();
            cv_defrag = false;
        }

        cv_barrier.wait();
    }
}

