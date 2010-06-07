#ifndef __KERNEL_SCHEDULER_H
#define __KERNEL_SCHEDULER_H

#include <kernel/types.h>
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
		iv_direction(false), iv_idleTask(NULL), iv_cpu(cpu) {};
	~Scheduler() {};

	void setIdleTask(task_t* t) { iv_idleTask = t; };
	task_t* getIdleTask() { return iv_idleTask; };

    private:
	bool iv_direction;
	Util::Lockfree::Stack<task_t> iv_taskList[2];

	task_t* iv_idleTask;
	cpu_t* iv_cpu;
};

#endif
