//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/sys/time.h $
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
#ifndef __SYS_TIME_H
#define __SYS_TIME_H

#include <stdint.h>

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
