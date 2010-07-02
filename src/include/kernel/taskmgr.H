#ifndef __KERNEL_TASKMGR_H
#define __KENREL_TASKMGR_H

#include <kernel/types.h>
#include <util/lockfree/counter.H>
#include <kernel/vmmmgr.H>

class TaskManager
{
    public:
	static task_t* getCurrentTask();
	static void setCurrentTask(task_t* t);
	
	typedef void(*task_fn_t)(void*);
	static task_t* createTask(task_fn_t, void*);

	friend class CpuManager;
    protected:
	TaskManager();
	~TaskManager() {};

	static task_t* createIdleTask();

    private:
	tid_t getNextTid() 
	    { return iv_nextTid.next() + VmmManager::FirstPid; };
	Util::Lockfree::Counter<tid_t> iv_nextTid;

	static void idleTaskLoop(void*);
	task_t* _createIdleTask();
	task_t* _createTask(task_fn_t, void*, bool);
};

#endif
