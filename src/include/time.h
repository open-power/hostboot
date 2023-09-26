/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/time.h $                                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2023                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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
#ifndef __TIME_H
#define __TIME_H

#include <sys/time.h>
#include <stdint.h>

// POSIX structure for time (sec / nsec pairs).
struct timespec
{
    uint64_t tv_sec;
    uint64_t tv_nsec;
};
typedef struct timespec timespec_t;

// POSIX clock IDs.
typedef enum
{
    CLOCK_REALTIME = 0,
    CLOCK_MONOTONIC = 1
} clockid_t;

// A union representing the date/time timestamps.
union date_time_t
{
    uint64_t value;
    struct
    {
        uint64_t year      : 16;
        uint64_t day       : 8;
        uint64_t month     : 8;
        uint64_t hour      : 8;
        uint64_t minute    : 8;
        uint64_t second    : 8;
        uint64_t hundredth : 8;
    } format;
};

// A struct containing the initial date/time values. date_time
// represents the absolute time, and timebase is the initial
// tick value reported by the system (used to calculate the
// difference in time).
struct base_time_t
{
    date_time_t date_time;
    uint64_t    timebase;
};

/** @fn clock_gettime
 *  @brief Reads the clock value from a POSIX clock.
 *
 *  @note Currently, we only support CLOCK_MONOTONIC.
 *        CLOCK_REALTIME requires synchronization of the timebase with the FSP
 *        RTC.
 *
 *  @param[in] clk_id - The clock ID to read.
 *  @param[out] tp - The timespec struct to store the clock value in.
 *
 *  @return 0 or -(errno).
 *  @retval 0 - SUCCESS.
 *  @retval -EINVAL - Invalid clock requested.
 *  @retval -EFAULT - NULL ptr given for timespec struct.
 *
 */
int clock_gettime(clockid_t clk_id, timespec_t* tp);

#ifdef __cplusplus

namespace hbstd
{

enum class timeout_t
{
    STOP,
    CONTINUE
};

/**
 * @brief Run a function once per interval for a given duration of time at most.
 *
 * @tparam    F                    Type of the given functor.
 * @param[in] seconds_timeout      The maximum time to run the function for.
 * @param[in] nanoseconds_timeout  Nanoseconds to add to seconds_timeout.
 * @param[in] seconds_between      The number of seconds between function invocations.
 * @param[in] nanoseconds_between  Nanoseconds to add to seconds_between.
 * @param[in] functor              The code to run.
 * @return    bool                 True if this function halted because the timeout
 *                                 duration expired, false if it halted because the
 *                                 functor asked the loop to stop.
 * @note                           The function will always be invoked at least once.
 * @note                           If the function returns timeout_t::CONTINUE, the timer
 *                                 will continue to count down and the function may be
 *                                 invoked again. If the function returns timeout_t::STOP,
 *                                 the timer will halt and with_timeout will immediately
 *                                 return false.
 */
template<typename F>
bool with_timeout(const uint64_t seconds_timeout,
                  const uint64_t nanoseconds_timeout,
                  const uint64_t seconds_between,
                  const uint64_t nanoseconds_between,
                  F&& functor)
{
    timespec_t start_time { }, current_time { };
    clock_gettime(CLOCK_MONOTONIC, &start_time);

    const timespec_t end_time
    {
        .tv_sec = start_time.tv_sec + seconds_timeout + (nanoseconds_timeout / NS_PER_SEC),
        .tv_nsec = start_time.tv_nsec + (nanoseconds_timeout % NS_PER_SEC)
    };

    while (true)
    {
        const timeout_t action = functor();

        if (action == timeout_t::STOP)
        {
            return false;
        }

        clock_gettime(CLOCK_MONOTONIC, &current_time);

        if (current_time.tv_sec > end_time.tv_sec
            || (current_time.tv_sec == end_time.tv_sec
                && (current_time.tv_nsec >= end_time.tv_nsec)))
        {
            break;
        }

        nanosleep(seconds_between, nanoseconds_between);
    }

    return true;
}

}

#endif

#endif
