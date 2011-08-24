//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/kernel/spinlock.C $
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
#include <kernel/spinlock.H>
#include <arch/ppc.H>

void Spinlock::lock()
{
    uint64_t reservation = __sync_fetch_and_add(&iv_reserve, 1);
    if (iv_ready != reservation)
    {
	do
	{
	    setThreadPriorityLow();
	}
	while(iv_ready != reservation);
	setThreadPriorityHigh();
    }
    isync();
}

void Spinlock::unlock()
{
    __sync_add_and_fetch(&iv_ready, 1);
}
