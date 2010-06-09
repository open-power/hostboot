#ifndef __KERNEL_SCHEDULER_H
#define __KERNEL_SCHEDULER_H

#include <kernel/types.h>
#include <kernel/spinlock.H>
#include <util/locked/queue.H>

#include <util/lockfree/stack.H>

class Scheduler
{
    public:
	friend class CpuManager;

	void addTask(task_t*);

	void returnRunnable();
	void setNextRunnable();

    protected:
	Scheduler(cpu_t* cpu) : 
		iv_taskList(), iv_idleTask(NULL), iv_cpu(cpu) {};
	~Scheduler() {};

	void setIdleTask(task_t* t) { iv_idleTask = t; };
	task_t* getIdleTask() { return iv_idleTask; };

    private:
	Util::Locked::Queue<task_t, true, Spinlock> iv_taskList;

	task_t* iv_idleTask;
	cpu_t* iv_cpu;
};

#endif
