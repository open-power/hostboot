//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/kernel/barrier.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
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
#include <kernel/barrier.H>
#include <arch/ppc.H>

void Barrier::wait()
{
    iv_spinlock.lock();
    --iv_missing;
    if(iv_missing > 0)
    {
        size_t l_event = iv_event;
        iv_spinlock.unlock();
        while(iv_event == l_event);
    }
    else
    {
        iv_missing = iv_count;
        ++iv_event;
        iv_spinlock.unlock();
    }
}
