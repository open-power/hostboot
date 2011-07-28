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

cpu_t* CpuManager::cv_cpus[CpuManager::MAXCPUS] = { NULL };
bool CpuManager::cv_shutdown_requested = false;
uint64_t CpuManager::cv_shutdown_status = 0;

CpuManager::CpuManager()
{
    for (int i = 0; i < MAXCPUS; i++)
	cv_cpus[i] = NULL;
}

cpu_t* CpuManager::getCurrentCPU()
{
    return cv_cpus[getPIR()];
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
        case CORE_POWER8_SALERNO:
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
    cv_shutdown_requested = true;
    cv_shutdown_status = i_status;
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

	printk("done\n");
    }

    if (currentCPU)
    {
	setSPRG3((uint64_t) cv_cpus[i]->idle_task);
        setDEC(TimeManager::getTimeSliceCount());
    }
    return;
}

void CpuManager::startSlaveCPU(cpu_t* cpu)
{
    setSPRG3((uint64_t) cpu->idle_task);
    setDEC(TimeManager::getTimeSliceCount());

    return;
}
