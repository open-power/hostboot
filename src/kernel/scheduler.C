#include <kernel/task.H>
#include <kernel/scheduler.H>
#include <kernel/taskmgr.H>
#include <kernel/cpu.H>
#include <kernel/cpumgr.H>
#include <kernel/console.H>

void Scheduler::addTask(task_t* t)
{
    if (t->cpu->idle_task != t)
    {
	iv_taskList.insert(t);
    }
}

void Scheduler::returnRunnable()
{
    this->addTask(TaskManager::getCurrentTask());
}

void Scheduler::setNextRunnable()
{
    task_t* t = iv_taskList.remove();

    if (NULL == t)
    {
	t = CpuManager::getCurrentCPU()->idle_task;
	// Set short decrementer.
	register uint64_t decrementer = 0x000f0000;
	asm volatile("mtdec %0" :: "r"(decrementer));
    }
    
    TaskManager::setCurrentTask(t);
}
