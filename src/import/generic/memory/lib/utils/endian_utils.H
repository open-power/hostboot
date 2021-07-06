/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/endian_utils.H $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2021                        */
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

///
/// @file endian_utils.H
/// @brief Util functions to help with endianess
///

// *HWP HWP Owner: Ben Gass <bgass@us.ibm.com>
// *HWP HWP Backup: Christian Geddes <crgeddes@us.ibm.com>
// *HWP Team:
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _ENDIAN_UTILS_H_
#define _ENDIAN_UTILS_H_

#include <vector>

#ifdef __PPE__
    #include <mss_generic_consts.H>
#else
    #include <cstdint>
    #include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#endif

namespace mss
{

///
/// @brief Forces native data into LE order
/// @tparam T the data type to process
/// @param[in] i_input inputted data to process
/// @param[in,out] io_data vector to append data to
///
template < typename T >
void forceLE(const T& i_input, std::vector<uint8_t>& io_data)
{
    // Temporary variable to process - we'll be doing bit shifts below
    T l_temp = i_input;

    for(size_t i = 0; i < sizeof(i_input); i++)
    {
        // Grab the lowest order byte and add it to the back of the vector
        const uint8_t l_byte = l_temp & 0xFF;
        io_data.push_back(l_byte);

        // Shift higher byte value into lowest no matter existing endianness
        l_temp >>= BITS_PER_BYTE;
    }
}

#ifndef __PPE__
///
/// @brief Forces native data into LE order for an array
/// @tparam T the data type to process
/// @param[in] i_input inputted data to process
/// @param[in] i_size size of the array
/// @param[in,out] io_data vector to append data to
///
template < typename T >
inline void forceLEArray(const T* i_input, const uint64_t i_size, std::vector<uint8_t>& io_data)
{
    for(size_t i = 0; i < i_size; i++)
    {
        forceLE(i_input[i], io_data);
    }
}
#endif
///
/// @brief Forces native data into BE order
/// @tparam T the data type to process
/// @param[in] i_input inputted data to process
/// @param[in,out] io_data vector to append data to
///
template < typename T >
void forceBE(const T& i_input, std::vector<uint8_t>& io_data)
{
    // Temporary variable to process - we'll be doing bit shifts below
    T l_temp = i_input;

    std::vector<uint8_t> l_tempBuffer;

    // This loop will put i_input into l_tempBuffer in BE order

    for(size_t i = sizeof(i_input); i > 0; i--)
    {
        // Grab the lowest order byte and add it to the front of the vector
        const uint8_t l_byte = l_temp & 0xFF;
        l_tempBuffer.push_back(l_byte);

        // Shift higher byte value into lowest no matter existing endianness
        l_temp >>= BITS_PER_BYTE;
    }

    // Put the new BE formatted data at the end of the input buffer

    std::vector<uint8_t>::iterator it = l_tempBuffer.end();
    --it; //Move iterator to the last element.

    for(uint8_t i = l_tempBuffer.size(); i > 0; --i)
    {
        io_data.push_back(*it);
        --it;
    }

}

#ifndef __PPE__
///
/// @brief Forces native data into BE order for an array
/// @tparam T the data type to process
/// @param[in] i_input inputted data to process
/// @param[in] i_size size of the array
/// @param[in,out] io_data vector to append data to
///
template < typename T >
inline void forceBEArray(const T* i_input, const uint64_t i_size, std::vector<uint8_t>& io_data)
{
    for(size_t i = 0; i < i_size; i++)
    {
        forceBE(i_input[i], io_data);
    }
}
#endif

///
/// @brief Converts LE data into native order
/// @tparam T the data type to output to
/// @param[in] i_input inputted data to process
/// @param[in,out] io_idx current index
/// @param[out] o_data data that has been converted into native endianness
/// @return bool true if passing false if failing
/// @note Real FFDC will be handled outside
///
template < typename T >
bool readLE(const std::vector<uint8_t>& i_input, uint32_t& io_idx, T& o_data)
{
    const uint32_t l_sz = static_cast<uint32_t>(sizeof(o_data));
    io_idx = l_sz + io_idx;

    // Checks that our final index is within the data range
    // Note: we decrement the index prior, so equal to is ok
    if(io_idx > i_input.size())
    {
        return false;
    }

    uint64_t l_idx = io_idx;

    o_data = 0;

    for(uint64_t i = 0; i < l_sz; i++)
    {
        l_idx--;
        uint8_t v = i_input[l_idx];
        o_data <<= BITS_PER_BYTE;
        o_data |= v;
    }

    return true;
}

#ifndef __PPE__
///
/// @brief Converts LE data into native order
/// @tparam T the data type to output to
/// @param[in] i_input inputted data to process
/// @param[in] i_size size of the array
/// @param[in,out] io_idx current index
/// @param[out] o_data data that has been converted into native endianness
/// @return bool true if passing false if failing
/// @note Real FFDC will be handled outside
///
template < typename T >
bool readLEArray(const std::vector<uint8_t>& i_input, const uint32_t i_size, uint32_t& io_idx, T* o_data)
{
    // Loop while the readLE is still passing and we haven't looped through the array's boundaries
    bool l_passing = true;

    for(uint32_t i = 0; i < i_size && l_passing; ++i)
    {
        l_passing = readLE(i_input, io_idx, o_data[i]);
    }

    return l_passing;
}
#endif

///
/// @brief Converts BE data into native order
/// @tparam T the data type to output to
/// @param[in] i_input inputted data to process
/// @param[in,out] io_idx current index
/// @param[out] o_data data that has been converted into native endianness
/// @return bool true if passing false if failing
/// @note Real FFDC will be handled outside
///
template < typename T >
bool readBE(const std::vector<uint8_t>& i_input, uint32_t& io_idx, T& o_data)
{
    const uint32_t l_sz = static_cast<uint32_t>(sizeof(o_data));
    uint64_t l_idx = io_idx;
    io_idx = l_sz + io_idx;

    // Checks that our final index is within the data range
    // Note: we decrement the index prior, so equal to is ok
    if(io_idx > i_input.size())
    {
        return false;
    }

    o_data = 0;

    for(uint64_t i = 0; i < l_sz; i++)
    {
        uint8_t v = i_input[l_idx];
        o_data <<= BITS_PER_BYTE;
        o_data |= v;
        l_idx++;
    }

    return true;
}

#ifndef __PPE__
///
/// @brief Converts BE data into native order
/// @tparam T the data type to output to
/// @param[in] i_input inputted data to process
/// @param[in] i_size size of the array
/// @param[in,out] io_idx current index
/// @param[out] o_data data that has been converted into native endianness
/// @return bool true if passing false if failing
/// @note Real FFDC will be handled outside
///
template < typename T >
bool readBEArray(const std::vector<uint8_t>& i_input, const uint32_t i_size, uint32_t& io_idx, T* o_data)
{
    // Loop while the readLE is still passing and we haven't looped through the array's boundaries
    bool l_passing = true;

    for(uint32_t i = 0; i < i_size && l_passing; ++i)
    {
        l_passing = readBE(i_input, io_idx, o_data[i]);
    }

    return l_passing;
}
#endif

}

#endif
