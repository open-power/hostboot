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
        // If task is pinned to this CPU, add to the per-CPU queue.
        if (0 != t->affinity_pinned)
        {
            // Allocate a per-CPU queue if this is the first pinning CPU.
            if (NULL == t->cpu->scheduler_extra)
            {
                t->cpu->scheduler_extra = new Runqueue_t();
            }
            // Insert into queue.
            static_cast<Runqueue_t*>(t->cpu->scheduler_extra)->insert(t);
        }
        // Not pinned, add to global run-queue.
        else
        {
	    iv_taskList.insert(t);
        }
    }
}

void Scheduler::returnRunnable()
{
    this->addTask(TaskManager::getCurrentTask());
}

void Scheduler::setNextRunnable()
{
    task_t* t = NULL;
    cpu_t* cpu = CpuManager::getCurrentCPU();
    
    // Check for ready task in local run-queue, if it exists.
    if (NULL != cpu->scheduler_extra)
    {
        t = static_cast<Runqueue_t*>(cpu->scheduler_extra)->remove();
    }
    
    // Check for ready task in global run-queue.
    if (NULL == t)
    {
        t = iv_taskList.remove();
    }

    // Choose idle task if no other ready task is available.
    if (NULL == t)
    {
	t = cpu->idle_task;
	// TODO: Set short decrementer.
        setDEC(TimeManager::getTimeSliceCount());
    }
    else // Set normal timeslice to decrementer.
    {
        setDEC(TimeManager::getTimeSliceCount());
    }
   
    TaskManager::setCurrentTask(t);
}
