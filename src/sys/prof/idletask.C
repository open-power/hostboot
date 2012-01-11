//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/sys/prof/idletask.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
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

/** @file idletask.C
 *  @brief Code for the kernel idle-loop.
 *
 *  This code exists here under the sys/prof directory to ensure that it does
 *  not get instrumented with code coverage.  The idle threads run stack-less
 *  and bad things happen if they have been instrumented.
 */

#include <kernel/taskmgr.H>
#include <arch/ppc.H>

void TaskManager::idleTaskLoop(void* unused)
{
    while(1)
    {
	setThreadPriorityLow();
    }
}
