#include <kernel/cpumgr.H>
#include <kernel/task.H>
#include <kernel/cpu.H>
#include <kernel/scheduler.H>
#include <kernel/taskmgr.H>
#include <kernel/pagemgr.H>
#include <kernel/console.H>
#include <util/singleton.H>

CpuManager::CpuManager()
{
    for (int i = 0; i < MAXCPUS; i++)
	iv_cpus[i] = NULL;
}

cpu_t* CpuManager::getCurrentCPU()
{
    register task_t* current_task = NULL;
    asm volatile("mfsprg3 %0" : "=r" (current_task) );
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
	cpu->scheduler = new Scheduler();
	cpu->kernel_stack = PageManager::allocatePage(4);
	
	// Create idle task.
	task_t * idle_task = TaskManager::createIdleTask();
	idle_task->cpu = cpu;
	
	// Add to scheduler.
	cpu->scheduler->setIdleTask(idle_task);
    }

    if (currentCPU)
    {
	register task_t* idle_task = iv_cpus[i]->scheduler->getIdleTask();
	asm volatile("mtsprg3 %0" :: "r" (idle_task));
    }
    else
    {
	// TODO once we get to SMP.
    }
    
    printk("done\n");

    return;
}
