#ifndef __KERNEL_TIMEMGR_H
#define __KERNEL_TIMEMGR_H

#include <kernel/types.h>
#include <kernel/ppcarch.H>

#include <util/locked/pqueue.H>
#include <kernel/spinlock.H>

class Scheduler;

struct _TimeManager_Delay_t
{
    _TimeManager_Delay_t * next;
    _TimeManager_Delay_t * prev;    
    uint64_t key;
    task_t* task;
};

class TimeManager
{
    public:
	enum
	    {
		TIMESLICE_PER_SEC = 1000,
	    };

	static void init();
	static uint64_t getTimeSliceCount()
	    {
		return iv_timebaseFreq / TIMESLICE_PER_SEC;
	    };

	static uint64_t getCurrentTimeBase()
	    {
		return ppc_getTB();
	    };

	static uint64_t convertSecToTicks(uint64_t i_sec, uint64_t i_nsec);

	static void delayTask(task_t* t, uint64_t i_sec, uint64_t i_nsec);
	static void checkReleaseTasks(Scheduler* s);

    protected:
	TimeManager() : 
	    iv_taskList() {};
	~TimeManager() {};

    private:
	void _init();
	void _delayTask(task_t* t, uint64_t i_sec, uint64_t i_nsec);
	void _checkReleaseTasks(Scheduler* s);
	    
	Util::Locked::PQueue<_TimeManager_Delay_t, uint64_t, 
			     true, Spinlock> iv_taskList;
	static uint64_t iv_timebaseFreq;
};

#endif
