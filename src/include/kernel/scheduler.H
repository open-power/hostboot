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
	Scheduler() : 
		iv_taskList() {};
	~Scheduler() {};

    private:
        typedef Util::Locked::Queue<task_t, true, Spinlock> Runqueue_t;
        Runqueue_t iv_taskList;
};

#endif
