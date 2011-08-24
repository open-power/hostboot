//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/kernel/timemgr.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2010 - 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
#ifndef __KERNEL_TIMEMGR_H
#define __KERNEL_TIMEMGR_H

#include <kernel/types.h>
#include <kernel/cpu.H>
#include <arch/ppc.H>

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
		return getTB();
	    };

	static uint64_t convertSecToTicks(uint64_t i_sec, uint64_t i_nsec);

	static void delayTask(task_t* t, uint64_t i_sec, uint64_t i_nsec);
	static void checkReleaseTasks(Scheduler* s);

    protected:
	TimeManager() {};
	~TimeManager() {};

    private:
	void _init();
	void _delayTask(task_t* t, uint64_t i_sec, uint64_t i_nsec);
	void _checkReleaseTasks(Scheduler* s);
	    
	Util::Locked::PQueue<_TimeManager_Delay_t, uint64_t>
			iv_taskList[KERNEL_MAX_SUPPORTED_CPUS];
	static uint64_t iv_timebaseFreq;
};

#endif
