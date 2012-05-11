//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/time.h $
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
