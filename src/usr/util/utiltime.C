/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/utiltime.C $                                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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
/**
 *  @file utiltime.C
 *
 *  @brief Time related functions for IPL code
 */

#include <util/utiltime.H>
#include <arch/ppc.H>
#include <kernel/timemgr.H>
#include <console/consoleif.H>

namespace ERRORLOG
{
// using errl's trace so we can run this very early
extern trace_desc_t* g_trac_errl;
};

namespace Util
{

// The base/reference date/time taken when we fetch the data from the BMC.
// This will be set once and then subsequent calls will use it to compute
// the current time using timebase math.
base_time_t cv_baseDateTime = {0};
base_time_t getBaseDateTime()
{
    return cv_baseDateTime;
}

void setBaseDateTime(const date_time_t& i_dateTime)
{
    cv_baseDateTime.date_time.value = i_dateTime.value;
    cv_baseDateTime.timebase = getTB();
    TRACFCOMP(ERRORLOG::g_trac_errl,"Current time (Y/M/D H:M:S) : %.04d/%.02d/%.02d %.02d:%.02d:%.02d @TB=%lld",
              cv_baseDateTime.date_time.format.year,
              cv_baseDateTime.date_time.format.month,
              cv_baseDateTime.date_time.format.day,
              cv_baseDateTime.date_time.format.hour,
              cv_baseDateTime.date_time.format.minute,
              cv_baseDateTime.date_time.format.second,
              cv_baseDateTime.timebase);
    CONSOLE::displayf(CONSOLE::VUART1, NULL,
                      "Current time (Y/M/D H:M:S) : %.04d/%.02d/%.02d %.02d:%.02d:%.02d @TB=%lld",
                      cv_baseDateTime.date_time.format.year,
                      cv_baseDateTime.date_time.format.month,
                      cv_baseDateTime.date_time.format.day,
                      cv_baseDateTime.date_time.format.hour,
                      cv_baseDateTime.date_time.format.minute,
                      cv_baseDateTime.date_time.format.second,
                      cv_baseDateTime.timebase);
}


date_time_t getCurrentDateTime()
{
    base_time_t l_baseTime = getBaseDateTime();
    uint64_t l_currentTimebase = getTB();

    uint64_t l_secondsElapsed = 0;
    uint64_t l_nsElapsed = 0;
    TimeManager::convertTicksToSec(l_currentTimebase - l_baseTime.timebase,
                                   l_secondsElapsed, l_nsElapsed);
    date_time_t l_currentDateTime = dateTimeAddSeconds(l_baseTime.date_time,
                                                       l_secondsElapsed);

    return l_currentDateTime;
}

};

