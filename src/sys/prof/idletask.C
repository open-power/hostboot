/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/sys/prof/idletask.C $                                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
/** @file idletask.C
 *  @brief Code for the kernel idle-loop.
 *
 *  This code exists here under the sys/prof directory to ensure that it does
 *  not get instrumented with code coverage.  The idle threads run stack-less
 *  and bad things happen if they have been instrumented.
 */

#include <kernel/taskmgr.H>
#include <arch/ppc.H>
#include <sys/syscall.h>

using namespace Systemcalls;

void* TaskManager::idleTaskLoop(void* unused)
{
    while(1)
    {
	// Lower priority (and yield simics thread).
        setThreadPriorityLow();

        // Request privilege escalation for nap.
        asm volatile("li 3, %0; sc" :: "K" (MISC_CPUNAP) : "r3", "cc");

        // Execute nap.
        nap();
    }
   return NULL;
}
