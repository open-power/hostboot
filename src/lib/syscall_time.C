//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/lib/syscall_time.C $
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
#include <time.h>
#include <sys/time.h>
#include <sys/syscall.h>
#include <errno.h>
#include <kernel/timemgr.H>

using namespace Systemcalls;

void nanosleep(uint64_t sec, uint64_t nsec)
{
    _syscall2(TIME_NANOSLEEP, (void*)sec, (void*)nsec);
}

int clock_gettime(clockid_t clk_id, timespec_t* tp)
{
    if (unlikely(NULL == tp)) { return -EFAULT; }

    int rc = 0;

    switch(clk_id)
    {
        case CLOCK_REALTIME: // TODO: Need a message to the FSP to get the
                             //       real-time.
            rc = -EINVAL;
            break;

        case CLOCK_MONOTONIC:
            TimeManager::convertTicksToSec(getTB(), tp->tv_sec, tp->tv_nsec);
            break;

        default:
            rc = -EINVAL;
            break;
    }

    return rc;
}
