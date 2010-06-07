#include <kernel/cpu.H>
#include <kernel/cpumgr.H>
#include <kernel/scheduler.H>
#include <kernel/taskmgr.H>
#include <kernel/task.H>
#include <kernel/syscalls.H>
#include <kernel/console.H>

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

    syscall syscalls[] =
	{
	    &TaskYield,
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

namespace Systemcalls
{
    void TaskYield(task_t* t)
    {
	Scheduler* s = t->cpu->scheduler;
	s->returnRunnable();
	s->setNextRunnable();
    }
};
