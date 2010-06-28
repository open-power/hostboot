#include <kernel/cpumgr.H>
#include <kernel/task.H>
#include <kernel/cpu.H>
#include <kernel/scheduler.H>
#include <kernel/taskmgr.H>
#include <kernel/pagemgr.H>
#include <kernel/console.H>
#include <util/singleton.H>
#include <kernel/ppcarch.H>

CpuManager::CpuManager()
{
    for (int i = 0; i < MAXCPUS; i++)
	iv_cpus[i] = NULL;
}

cpu_t* CpuManager::getCurrentCPU()
{
    register task_t* current_task = (task_t*) ppc_getSPRG3();
    return current_task->cpu;
}

void CpuManager::init()
{
    Singleton<CpuManager>::instance().startCPU();
}

void CpuManager::startCPU(ssize_t i)
{
    bool currentCPU = false;
    if (i < 0)
    {
	// TODO: Determine position of this CPU, somehow.
	i = 0;

	currentCPU = true;
    }

    printk("Starting CPU %d...", i);    

    // Initialize CPU structure.
    if (NULL == iv_cpus[i])
    {
	cpu_t* cpu = iv_cpus[i] = new cpu_t;
	
	// Initialize CPU.
	cpu->cpu = i;
	cpu->scheduler = new Scheduler(cpu);
	cpu->kernel_stack = 
	    (void*) (((uint64_t)PageManager::allocatePage(4)) + 16320);
	
	// Create idle task.
	task_t * idle_task = TaskManager::createIdleTask();
	idle_task->cpu = cpu;
	
	// Add to scheduler.
	cpu->scheduler->setIdleTask(idle_task);
    }

    if (currentCPU)
    {
	ppc_setSPRG3((uint64_t) iv_cpus[i]->scheduler->getIdleTask());

	// TODO: Set up decrementer properly.
	register uint64_t decrementer = 0x0f000000;
	asm volatile("mtdec %0" :: "r"(decrementer));

    }
    else
    {
	// TODO once we get to SMP.
    }
    
    printk("done\n");

    return;
}
