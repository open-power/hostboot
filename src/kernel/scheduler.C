#include <kernel/task.H>
#include <kernel/scheduler.H>
#include <kernel/taskmgr.H>
#include <kernel/cpu.H>
#include <kernel/cpumgr.H>
#include <kernel/console.H>
#include <kernel/timemgr.H>

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
	// TODO: Set short decrementer.
        setDEC(TimeManager::getTimeSliceCount());
    }
    else // Set normal timeslice to decrementer.
    {
        setDEC(TimeManager::getTimeSliceCount());
    }
    
    TaskManager::setCurrentTask(t);
}
