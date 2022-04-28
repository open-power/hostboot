/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/util/utiltime.H $                             */
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
 *  @file utiltime.H
 *
 *  @brief Definition of time related functions
 */
#ifndef UTILTIME_H
#define UTILTIME_H

#include <time.h>
#include <vector>

namespace Util
{
    /**
     * @brief Returns the current date/time.
     *
     * @return The current date/time
     */
    date_time_t getCurrentDateTime();

    /**
     * @brief Sets the member date/time structure to the date/time passed in.
     *        The timebase member of the structure is set to the current
     *        timebase at the time of the call of this function.
     *
     * @param[in] i_dateTime the current date/time value
     */
    void setBaseDateTime(const date_time_t& i_dateTime);

    /**
     * @brief Helper function to convert a uint8_t decimal to BCD (Binary Coded
     *        Decimal) format.
     *
     * @param[in] dec the uint8_t value to be converted to BCD format
     * @return The BCD-formatted input value
     */
    inline uint8_t dec2bcd8(uint8_t i_dec)
    {
        uint8_t bcd = (i_dec % 10) | ((i_dec / 10) << 4);
        return bcd;
    }

    /**
     * @brief Helper function to convert a uint16_t decimal to BCD (Binary Coded
     *        Decimal) format.
     *
     * @param[in] dec the uint16_t value to be converted to BCD format
     * @return The BCD-formatted input value
     */
    inline uint16_t dec2bcd16(uint16_t i_dec)
    {
        return dec2bcd8(i_dec % 100) | (dec2bcd8(i_dec / 100) << 8);
    }

    /**
     * @brief Helper function to convert a BCD (Binary Coded Decimal) input to
     *        uint8_t.
     *
     * @param[in] bcd the BCD value to be converted to uint8_t
     * @return The uint8_t value
     */
    inline uint8_t bcd2dec8(uint8_t i_bcd)
    {
        uint8_t dec = ((i_bcd >> 4) * 10) + (i_bcd & 0x0f);
        return dec;
    }

    /**
     * @brief Helper function to convert BCD (Binary Coded Decimal) input to
     *        uint16_t.
     *
     * @param[in] bcd the BCD value to be converted to uint16_t
     * @return The uint16_t value
     */
    inline uint16_t bcd2dec16(uint16_t i_bcd)
    {
        return (bcd2dec8(i_bcd >> 8) * 100) + bcd2dec8(i_bcd & 0xff);
    }

    /**
     * @brief Converts the input date/time structure to a raw BCD-formatted
     *        uint64_t value in the format: 0xYYYYMMDDHHMMSS00.
     *
     * @param[in] i_dateTime the input date/time structure to covert
     * @return The raw BCD-formatted date/time in the format:
     *         0xYYYYMMDDHHMMSS00
     */
    uint64_t dateTimeToRawBCD(const date_time_t& i_dateTime);

    /**
     * @brief Converts the input raw BCD-formatted time in format
     *        0xYYYYMMDDHHMMSS00 to a date_time_t structure. The function
     *        performs a conversion from BCD to decimal as part of the
     *        translation.
     *
     * @param[in] i_dateTimeBCD the input date/time in BCD format
     * @return The formatted date_time_t structure
     */
    date_time_t rawBCDToDateTime(uint64_t i_dateTimeBCD);

    /**
     * @brief Adds seconds to the provided date/time
     *
     * @param[in] i_dateTime the current date/time
     * @param[in] i_seconds the number of seconds to add to the date/time
     * @return The new date/time
     */
    date_time_t dateTimeAddSeconds(const date_time_t& i_dateTime,
                                   uint64_t i_seconds);

    /**
     * @brief Creates a string to represent the date+time of the format
     *        YYYY/MM/DD HH:MM:SS
     *
     * @param[in] i_dateTime the date/time value to convert
     * @return Vector of characters that contain the string
     */
    std::vector<char> dateToString( date_time_t i_dateTime );

};

#endif //UTILTIME_H
