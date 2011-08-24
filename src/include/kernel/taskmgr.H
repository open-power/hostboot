//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/kernel/taskmgr.H $
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
	    { return iv_nextTid.next(); };
	Util::Lockfree::Counter<tid_t> iv_nextTid;

	static void idleTaskLoop(void*);
	task_t* _createIdleTask();
	task_t* _createTask(task_fn_t, void*, bool);
};

#endif
