#include <util/singleton.H>
#include <kernel/taskmgr.H>
#include <kernel/task.H>
#include <kernel/pagemgr.H>
#include <kernel/cpumgr.H>
#include <sys/task.h>
#include <arch/ppc.H>
#include <string.h>
#include <limits.h>

extern "C" void userspace_task_entry();

void TaskManager::idleTaskLoop(void* unused)
{
    while(1)
    {
	setThreadPriorityLow();
    }
}

task_t* TaskManager::getCurrentTask()
{
    register task_t* current_task = (task_t*) getSPRG3();
    return current_task;
}

void TaskManager::setCurrentTask(task_t* t)
{
    t->cpu = CpuManager::getCurrentCPU();
    setSPRG3((uint64_t)t);
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
    memset(task, '\0', sizeof(task_t));

    task->tid = this->getNextTid();
    
    // Set NIP to be userspace_task_entry stub and GPR3 to be the 
    // function pointer for the desired task entry point.
    task->context.nip = reinterpret_cast<void*>(&userspace_task_entry);
    task->context.gprs[4] = reinterpret_cast<uint64_t>(t);

    // Set up LR to be the entry point for task_end in case a task 
    // 'returns' from its entry point.  By the Power ABI, the entry
    // point address is in (func_ptr)[0].
    task->context.lr = reinterpret_cast<uint64_t*>(&task_end)[0];

    // Set up GRP[13] as task structure reserved.
    task->context.gprs[13] = (uint64_t)task;

    // Set up argument.
    task->context.gprs[3] = (uint64_t) p;
    
    // Setup stack.
    if (withStack)
    {
	task->context.stack_ptr = 
	    PageManager::allocatePage(TASK_DEFAULT_STACK_SIZE);
        memset(task->context.stack_ptr, '\0', 
               TASK_DEFAULT_STACK_SIZE * PAGESIZE);
	task->context.gprs[1] = ((uint64_t)task->context.stack_ptr) + 16320;
    }
    else
    {
	task->context.stack_ptr = NULL;
    }

    return task;
}

