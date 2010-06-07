#include <kernel/cpu.H>
#include <kernel/cpumgr.H>
#include <kernel/scheduler.H>
#include <kernel/taskmgr.H>
#include <kernel/task.H>
#include <kernel/syscalls.H>
#include <kernel/console.H>
#include <kernel/pagemgr.H>

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

    syscall syscalls[] =
	{
	    &TaskYield,
	    &TaskStart,
	    &TaskEnd,
	    &TaskGettid,
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
};
