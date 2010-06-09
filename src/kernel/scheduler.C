#include <kernel/task.H>
#include <kernel/scheduler.H>
#include <kernel/taskmgr.H>

void Scheduler::addTask(task_t* t)
{
    if (iv_idleTask != t)
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
	t = iv_idleTask;
    }
    
    TaskManager::setCurrentTask(t);
}
