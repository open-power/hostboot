#include <util/singleton.H>
#include <kernel/taskmgr.H>
#include <kernel/task.H>
#include <kernel/pagemgr.H>
#include <kernel/ppcarch.H>

void TaskManager::idleTaskLoop(void* unused)
{
    while(1)
    {
    }
}

task_t* TaskManager::getCurrentTask()
{
    register task_t* current_task = (task_t*) ppc_getSPRG3();
    return current_task;
}

void TaskManager::setCurrentTask(task_t* t)
{
    t->cpu = getCurrentTask()->cpu;
    ppc_setSPRG3((uint64_t)t);
    return;
}

TaskManager::TaskManager() : iv_nextTid()
{
}

task_t* TaskManager::createIdleTask()
{
    return Singleton<TaskManager>::instance()._createIdleTask();
}

task_t* TaskManager::createTask(TaskManager::task_fn_t t, void* p)
{
    return Singleton<TaskManager>::instance()._createTask(t, p, true);
}

task_t* TaskManager::_createIdleTask()
{
    return this->_createTask(&TaskManager::idleTaskLoop, NULL, false);
}

task_t* TaskManager::_createTask(TaskManager::task_fn_t t, 
				 void* p, bool withStack)
{
    task_t* task = new task_t;
    task->tid = this->getNextTid();

    // Function pointer 't' is actually a TOC entry.  
    //     TOC[0] = function address
    //     TOC[1] = TOC base -> r2
    task->context.nip = (void*) ((uint64_t*) t)[0];
    task->context.gprs[2] = ((uint64_t*)t)[1];

    // Set up GRP[13] as task structure reserved.
    task->context.gprs[13] = (uint64_t)task;

    // Set up argument.
    task->context.gprs[3] = (uint64_t) p;
    
    // Setup stack.
    if (withStack)
    {
	task->context.stack_ptr = 
	    PageManager::allocatePage(TASK_DEFAULT_STACK_SIZE);
	task->context.gprs[1] = ((uint64_t)task->context.stack_ptr) + 16320;
    }
    else
    {
	task->context.stack_ptr = NULL;
    }

    return task;
}

