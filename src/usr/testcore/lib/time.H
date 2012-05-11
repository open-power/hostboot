//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/testcore/lib/time.H $
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

#ifndef __TESTCORE_LIB_TIME_H
#define __TESTCORE_LIB_TIME_H

#include <time.h>
#include <sys/time.h>
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
