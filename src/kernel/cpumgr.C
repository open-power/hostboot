#include <kernel/cpumgr.H>
#include <kernel/task.H>
#include <kernel/cpu.H>
#include <kernel/scheduler.H>
#include <kernel/taskmgr.H>
#include <kernel/pagemgr.H>
#include <kernel/console.H>
#include <util/singleton.H>
#include <kernel/ppcarch.H>
#include <kernel/timemgr.H>

cpu_t* CpuManager::cv_cpus[CpuManager::MAXCPUS] = { NULL };

CpuManager::CpuManager()
{
    for (int i = 0; i < MAXCPUS; i++)
	cv_cpus[i] = NULL;
}

cpu_t* CpuManager::getCurrentCPU()
{
    register task_t* current_task = (task_t*) ppc_getSPRG3();
    return current_task->cpu;
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
	printk("Starting CPU %d...", i);    
	cpu_t* cpu = cv_cpus[i] = new cpu_t;
	
	// Initialize CPU.
	cpu->cpu = i;
	cpu->scheduler = &Singleton<Scheduler>::instance();
	cpu->kernel_stack = 
	    (void*) (((uint64_t)PageManager::allocatePage(4)) + 16320);
	
	// Create idle task.
	cpu->idle_task = TaskManager::createIdleTask();
	cpu->idle_task->cpu = cpu;
	
	printk("done\n");
    }

    if (currentCPU)
    {
	ppc_setSPRG3((uint64_t) cv_cpus[i]->idle_task);

	register uint64_t decrementer = TimeManager::getTimeSliceCount();
	asm volatile("mtdec %0" :: "r"(decrementer));
    }
    return;
}

void CpuManager::startSlaveCPU(cpu_t* cpu)
{
    ppc_setSPRG3((uint64_t) cpu->idle_task);
    
    register uint64_t decrementer = TimeManager::getTimeSliceCount();
    asm volatile("mtdec %0" :: "r"(decrementer));

    return;
}

uint64_t isCPU0()
{
    return (0 == getCpuId());
}
