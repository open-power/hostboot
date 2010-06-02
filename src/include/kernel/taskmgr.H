#ifndef __KERNEL_TASKMGR_H
#define __KENREL_TASKMGR_H

#include <kernel/types.h>

class TaskManager
{
    public:
	static task_t* getCurrentTask();
	
	typedef void(*task_fn_t)();

	friend class CpuManager;
    protected:
	TaskManager();
	~TaskManager() {};

	static task_t* createIdleTask();
	static task_t* createTask(task_fn_t);

    private:
	tid_t getNextTid();

	tid_t iv_nextTid;

	static void idleTaskLoop();
	task_t* _createIdleTask();
	task_t* _createTask(task_fn_t, bool);
};

#endif
