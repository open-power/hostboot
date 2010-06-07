#include <kernel/task.H>
#include <kernel/scheduler.H>
#include <kernel/taskmgr.H>

void Scheduler::addTask(task_t* t)
{
    if (iv_idleTask != t)
    {
	iv_taskList[iv_direction ? 0 : 1].push(t);
    }
}

void Scheduler::returnRunnable()
{
    this->addTask(TaskManager::getCurrentTask());
}

void Scheduler::setNextRunnable()
{
    task_t* t = NULL;

    bool direction = iv_direction;
    t = iv_taskList[direction ? 1 : 0].pop();

    if (NULL == t)
    {
	t = iv_taskList[direction ? 0 : 1].pop();
	__sync_bool_compare_and_swap(&iv_direction, direction, !direction);
    }

    if (NULL == t)
    {
	t = iv_idleTask;
    }
    
    TaskManager::setCurrentTask(t);
}
