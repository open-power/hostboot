/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/time.h $                                          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
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

// A union representing the BCD (Binary-Coded Decimal) format of
// date/time timestamps.
union BCD_time8_t
{
    uint64_t value;
    struct
    {
        uint64_t year   : 16;
        uint64_t day    : 8;
        uint64_t month  : 8;
        uint64_t hour   : 8;
        uint64_t minute : 8;
        uint64_t second : 8;
        uint64_t unused : 8;
    } format;
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

#endif
