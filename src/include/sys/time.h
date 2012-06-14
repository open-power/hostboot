/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/include/sys/time.h $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2010-2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
#ifndef __SYS_TIME_H
#define __SYS_TIME_H

#include <stdint.h>
#include <kernel/timemgr.H>

//******************************************************************************
// Macros
//******************************************************************************

/**
 *  @brief Number of nanoseconds per second
 */
#define NS_PER_SEC (1000000000ull)

/**
 *  @brief Duration of one timeslice/context switch in nanoseconds 
 */
#define ONE_CTX_SWITCH_NS (NS_PER_SEC/TimeManager::TIMESLICE_PER_SEC)

/**
 *  @brief Duration of ten context switches, in nanoseconds; used by testcases 
 *     to guarantee a secondary testcase task/thread will execute
 */
#define TEN_CTX_SWITCHES_NS (ONE_CTX_SWITCH_NS * 10)

//******************************************************************************
// Interface
//******************************************************************************

#ifdef __cplusplus
extern "C"
{
#endif


/** @fn nanosleep()
 *  @brief Sleep for time duration given: seconds plus nanoseconds.
 *  @param[in] sec  - seconds
 *  @param[in] nsec - nanoseconds (billionths of a second)
 */
void nanosleep(uint64_t sec, uint64_t nsec);



#ifdef __cplusplus
}
#endif

#endif
