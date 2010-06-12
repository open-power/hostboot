#include <kernel/cpu.H>
#include <kernel/cpumgr.H>
#include <kernel/scheduler.H>
#include <kernel/taskmgr.H>
#include <kernel/task.H>
#include <kernel/syscalls.H>
#include <kernel/console.H>
#include <kernel/pagemgr.H>
#include <kernel/usermutex.H>

extern "C"
void kernel_execute_decrementer()
{
    Scheduler* s = CpuManager::getCurrentCPU()->scheduler;
    s->returnRunnable();
    s->setNextRunnable();

    // Resync decrementer.
    register uint64_t decrementer = 0x0f000000;
    asm volatile("mtdec %0" :: "r"(decrementer));
}

namespace Systemcalls
{
    typedef void(*syscall)(task_t*);
    void TaskYield(task_t*);
    void TaskStart(task_t*);
    void TaskEnd(task_t*);
    void TaskGettid(task_t*);
    void MutexCreate(task_t*);
    void MutexDestroy(task_t*);
    void MutexLockCont(task_t*);
    void MutexUnlockCont(task_t*);

    syscall syscalls[] =
	{
	    &TaskYield,
	    &TaskStart,
	    &TaskEnd,
	    &TaskGettid,

	    &MutexCreate,
	    &MutexDestroy,
	    &MutexLockCont,
	    &MutexUnlockCont,
	};
};

extern "C"
void kernel_execute_systemcall()
{
    using namespace Systemcalls;
    task_t* t = TaskManager::getCurrentTask();

    uint64_t syscall = t->context.gprs[3];
    if (syscall > SYSCALL_MAX)
    {
	// TODO : kill task.
	printk("Invalid syscall : %lld\n", syscall);
	while(1);
    }
    else
    {
	syscalls[syscall](t);
    }
}

#define TASK_GETARGN(t, n) (t->context.gprs[n+4])
#define TASK_GETARG0(t) (TASK_GETARGN(t,0))
#define TASK_GETARG1(t) (TASK_GETARGN(t,1))
#define TASK_GETARG2(t) (TASK_GETARGN(t,2))
#define TASK_GETARG3(t) (TASK_GETARGN(t,3))
#define TASK_GETARG4(t) (TASK_GETARGN(t,4))
#define TASK_GETARG5(t) (TASK_GETARGN(t,5))
#define TASK_GETARG6(t) (TASK_GETARGN(t,6))
#define TASK_GETARG7(t) (TASK_GETARGN(t,7))

#define TASK_SETRTN(t, n) (t->context.gprs[3] = (n))

namespace Systemcalls
{
    void TaskYield(task_t* t)
    {
	Scheduler* s = t->cpu->scheduler;
	s->returnRunnable();
	s->setNextRunnable();
    }

    void TaskStart(task_t* t)
    {
	task_t* newTask = 
	    TaskManager::createTask((TaskManager::task_fn_t)TASK_GETARG0(t),
				    (void*)TASK_GETARG1(t));
	newTask->cpu = t->cpu;
	t->cpu->scheduler->addTask(newTask);

	TASK_SETRTN(t, newTask->tid);
    }

    void TaskEnd(task_t* t)
    {
	// Make sure task pointers are updated before we delete this task.
	t->cpu->scheduler->setNextRunnable();
	
	// TODO: Deal with join.

	// Clean up task memory.
	PageManager::freePage(t->context.stack_ptr, TASK_DEFAULT_STACK_SIZE);
	delete t;
    }

    void TaskGettid(task_t* t)
    {
	TASK_SETRTN(t, t->tid);
    }

    void MutexCreate(task_t* t)
    {
	UserMutex * m = new UserMutex();
	TASK_SETRTN(t, (uint64_t)m);
    }

    void MutexDestroy(task_t* t)
    {
	// TODO: Extra verification of parameter and mutex state.

	delete (UserMutex*) TASK_GETARG0(t);
	TASK_SETRTN(t, 0);
    }

    void MutexLockCont(task_t* t)
    {
	// TODO: Extra verification of parameter and mutex state.
	
	UserMutex* m = (UserMutex*) TASK_GETARG0(t);
	m->lock.lock();
	if (m->unlock_pend) 
	{   
	    // We missed the unlock syscall, take lock and return to userspace.
	    m->unlock_pend = false;
	    m->lock.unlock();

	}
	else
	{
	    // Queue ourself to wait for unlock.
	    m->waiting.insert(TaskManager::getCurrentTask());
	    m->lock.unlock();
	    CpuManager::getCurrentCPU()->scheduler->setNextRunnable();
	}
	TASK_SETRTN(t, 0);	
    }

    void MutexUnlockCont(task_t* t)
    {
	// TODO: Extra verification of parameter and mutex state.

	UserMutex* m = (UserMutex*) TASK_GETARG0(t);
	m->lock.lock();
	task_t* wait_task = m->waiting.remove();
	if (NULL == wait_task)
	{
	    m->unlock_pend = true;
	}
	else
	{
	    wait_task->cpu->scheduler->addTask(wait_task);
	}
	m->lock.unlock();
	TASK_SETRTN(t, 0);
    }
};
