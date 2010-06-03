#include <util/singleton.H>
#include <kernel/taskmgr.H>
#include <kernel/task.H>
#include <kernel/pagemgr.H>

void TaskManager::idleTaskLoop()
{
    while(1)
    {
    }
}

task_t* TaskManager::getCurrentTask()
{
    register task_t* current_task = NULL;
    asm volatile("mfsprg3 %0" : "=r" (current_task) );
    return current_task;
}

TaskManager::TaskManager() : iv_nextTid(0)
{
}

task_t* TaskManager::createIdleTask()
{
    return Singleton<TaskManager>::instance()._createIdleTask();
}

task_t* TaskManager::createTask(TaskManager::task_fn_t t)
{
    return Singleton<TaskManager>::instance()._createTask(t, true);
}

tid_t TaskManager::getNextTid()
{
    return __sync_fetch_and_add(&iv_nextTid, 1);
}

task_t* TaskManager::_createIdleTask()
{
    return this->_createTask(&TaskManager::idleTaskLoop, false);
}

task_t* TaskManager::_createTask(TaskManager::task_fn_t t, bool withStack)
{
    task_t* task = new task_t;
    task->tid = this->getNextTid();

    // Function pointer 't' is actually a TOC entry.  
    //     TOC[0] = function address
    //     TOC[1] = TOC base -> r2
    task->context.nip = (void*) ((uint64_t*) t)[0];
    task->context.gprs[2] = ((uint64_t*)t)[1];
    
    // Setup stack.
    if (withStack)
    {
	task->context.stack_ptr = PageManager::allocatePage(4);
	task->context.gprs[1] = ((uint64_t)task->context.stack_ptr) + 16320;
    }
    else
    {
	task->context.stack_ptr = NULL;
    }

    return task;
}

