/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/testcore/lib/time.H $                                 */
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
#ifndef __TESTCORE_LIB_TIME_H
#define __TESTCORE_LIB_TIME_H

#include <time.h>
#include <sys/time.h>
#include <sys/task.h>
#include <errno.h>

/** @file time.H
 *  @brief Test cases for the time / sleep sub-system.
 */

class TimeTest : public CxxTest::TestSuite
{
    public:
        /**
         * Tests for the clock_gettime POSIX function.
         */
        void testClockGetTime()
        {
            timespec_t first, second;

            if (-EINVAL != clock_gettime(CLOCK_REALTIME, &first))
            {
                TS_FAIL("CLOCK_REALTIME not implemented, but no EINVAL");
            }

            if (0 != clock_gettime(CLOCK_MONOTONIC, &first))
            {
                TS_FAIL("Unable to read monotonic clock");
            }

            nanosleep(0,1);

            if (0 != clock_gettime(CLOCK_MONOTONIC, &second))
            {
                TS_FAIL("Unable to read monotonic clock");
            }

            if ((second.tv_sec <= first.tv_sec) &&
                (second.tv_nsec <= first.tv_nsec))
            {
                TS_FAIL("Monotonic clock is not increasing.");
            }
        }
};

#endif
