/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/lib/syscall_time.C $                                      */
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
#include <time.h>
#include <sys/time.h>
#include <sys/syscall.h>
#include <errno.h>
#include <kernel/timemgr.H>

using namespace Systemcalls;

void nanosleep(uint64_t sec, uint64_t nsec)
{
    // If the delay is short then simpleDelay() will perform the delay
    if(unlikely(!TimeManager::simpleDelay(sec, nsec)))
    {
        _syscall2(TIME_NANOSLEEP, (void*)sec, (void*)nsec);
    }
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
