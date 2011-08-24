//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/kernel/scheduler.H $
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
