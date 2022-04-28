/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/utiltime_common.C $                              */
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
 *  @file utiltime_common.C
 *
 *  @brief Time related functions for both IPL and Runtime code
 */

#include <util/utiltime.H>
#include <stdio.h>

namespace Util
{

date_time_t dateTimeAddSeconds(const date_time_t& i_dateTime,
                               const uint64_t i_seconds)
{
    date_time_t l_result{};
    const uint32_t SECONDS_IN_HOUR = 3600;
    const uint8_t SECONDS_IN_MINUTE = 60;
    const uint8_t MINUTES_IN_HOUR  = 60;
    const uint8_t HOURS_IN_DAY = 24;
    const uint8_t DAYS_IN_MONTH[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const uint8_t MONTH_OF_FEB = 2;
    const uint8_t MONTHS_IN_YEAR = 12;

    uint8_t l_hours = i_seconds / SECONDS_IN_HOUR;
    uint8_t l_minutes = (i_seconds - (l_hours * SECONDS_IN_HOUR)) /
                        SECONDS_IN_MINUTE;
    uint8_t l_seconds = i_seconds - (l_hours * SECONDS_IN_HOUR) -
                                    (l_minutes * SECONDS_IN_MINUTE);

    l_result.format.second = l_seconds + i_dateTime.format.second;
    if(l_result.format.second >= SECONDS_IN_MINUTE)
    {
        l_minutes++;
        l_result.format.second -= SECONDS_IN_MINUTE;
    }

    l_result.format.minute = l_minutes + i_dateTime.format.minute;
    if(l_result.format.minute >= MINUTES_IN_HOUR)
    {
        l_hours++;
        l_result.format.minute -= MINUTES_IN_HOUR;
    }

    l_result.format.hour = l_hours + i_dateTime.format.hour;
    if(l_result.format.hour >= HOURS_IN_DAY)
    {
        l_result.format.day = (i_dateTime.format.day +
                             (l_result.format.hour / HOURS_IN_DAY));
        l_result.format.hour -= ((l_result.format.hour / HOURS_IN_DAY) *
                                 HOURS_IN_DAY);
        l_result.format.month = i_dateTime.format.month;
        l_result.format.year = i_dateTime.format.year;

        uint8_t l_daysInMonth = DAYS_IN_MONTH[i_dateTime.format.month - 1];

        // Take leap years into account
        if((l_result.format.month == MONTH_OF_FEB) &&
            ((l_result.format.year % 4 == 0 && l_result.format.year % 100 != 0) ||
             (l_result.format.year % 400 == 0)))
        {
            l_daysInMonth++;
        }

        if(l_result.format.day > l_daysInMonth)
        {
            l_result.format.day -= l_daysInMonth;
            l_result.format.month = i_dateTime.format.month + 1;
            if(l_result.format.month > MONTHS_IN_YEAR)
            {
                l_result.format.year = i_dateTime.format.year + 1;
                l_result.format.month -= MONTHS_IN_YEAR;
            }
        }
    }
    else
    {
        l_result.format.day = i_dateTime.format.day;
        l_result.format.month = i_dateTime.format.month;
        l_result.format.year = i_dateTime.format.year;
    }
    return l_result;
}

uint64_t dateTimeToRawBCD(const date_time_t& i_dateTime)
{
    uint64_t l_result = 0;

    uint64_t l_year = dec2bcd16(i_dateTime.format.year);
    uint64_t l_month = dec2bcd8(i_dateTime.format.month);
    uint64_t l_day = dec2bcd8(i_dateTime.format.day);
    uint64_t l_hour = dec2bcd8(i_dateTime.format.hour);
    uint64_t l_minute = dec2bcd8(i_dateTime.format.minute);
    uint64_t l_second = dec2bcd8(i_dateTime.format.second);

    l_result = (l_year << 48) | (l_month << 40) | (l_day << 32) |
                 (l_hour << 24) | (l_minute << 16) | (l_second << 8);

    return l_result;
}

date_time_t rawBCDToDateTime(const uint64_t i_dateTimeBCD)
{
    date_time_t l_result {};
    l_result.format.year = bcd2dec16(i_dateTimeBCD >> 48);
    l_result.format.month = bcd2dec8((i_dateTimeBCD & 0x0000FF0000000000) >> 40);
    l_result.format.day = bcd2dec8((i_dateTimeBCD & 0x000000FF00000000) >> 32);
    l_result.format.hour = bcd2dec8((i_dateTimeBCD & 0x00000000FF000000) >> 24);
    l_result.format.minute = bcd2dec8((i_dateTimeBCD & 0x0000000000FF0000) >> 16);
    l_result.format.second = bcd2dec8((i_dateTimeBCD & 0x000000000000FF00) >> 8);
    return l_result;
}

std::vector<char> dateToString( date_time_t i_dateTime )
{
    // YYYY/MM/DD HH:MM:SS
    constexpr size_t STRING_SIZE = 20;
    std::vector<char> thestring(STRING_SIZE);
    snprintf(thestring.data(), STRING_SIZE,
             "%.04d/%.02d/%.02d %.02d:%.02d:%.02d",
             i_dateTime.format.year,
             i_dateTime.format.month,
             i_dateTime.format.day,
             i_dateTime.format.hour,
             i_dateTime.format.minute,
             i_dateTime.format.second);
    return thestring;    
}

};
