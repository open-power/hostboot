/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/scheduler.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2010,2014              */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
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
        void addTaskMasterCPU(task_t*);

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
