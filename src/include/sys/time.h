/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/sys/time.h $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2010,2021                        */
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
#ifndef __SYS_TIME_H
#define __SYS_TIME_H

#include <stdint.h>

#ifndef __HOSTBOOT_RUNTIME
#include <kernel/timemgr.H>
#endif

//******************************************************************************
// Macros
//******************************************************************************


/**
 *  @brief number of milliseconds per second
 */
#define MS_PER_SEC (1000)

/**
 *  @brief Number of nanoseconds per second
 */
#define NS_PER_SEC (1000000000ull)

/**
 *  @brief Number of nanoseconds per milisecond
 */
#define NS_PER_MSEC (1000000ull)


/**
 *  @brief Duration of one timeslice/context switch in nanoseconds 
 */
#define ONE_CTX_SWITCH_NS (NS_PER_SEC/TimeManager::getTimeSlicePerSec())

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
