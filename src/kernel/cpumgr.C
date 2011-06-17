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

cpu_t* CpuManager::cv_cpus[CpuManager::MAXCPUS] = { NULL };

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
    for (int i = 0; i < KERNEL_MAX_SUPPORTED_CPUS; i++)
	Singleton<CpuManager>::instance().startCPU(i);
}

void CpuManager::init_slave_smp(cpu_t* cpu)
{
    Singleton<CpuManager>::instance().startSlaveCPU(cpu);
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
