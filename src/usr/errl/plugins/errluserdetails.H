/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/plugins/errluserdetails.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
#ifndef ERRL_ERRLUSERDETAILS_H
#define ERRL_ERRLUSERDETAILS_H

/**
 *  @file errluserdetails.H
 *
 *  Defines the ErrlUserDetailsParser base class
 *
 *  For each class derived from ErrlUserDetails used to create user detail data,
 *  derive a class from ErrlUserDetailsParser to parse user detail data
 */
#include <stdint.h>

namespace ERRORLOG
{

/**
 * @struct UnalignedData
 * @brief Structure used for safe assigment from unaligned pointer, it forces
 *        the compiler to generate extra instructions and satisfy architectural
 *        alignment requirements.
 */
template<typename T> struct UnalignedData {
    T value;
} __attribute__ ((packed));

/**
 * @brief Read integral value from unaligned pointer.
 *
 * @param[in] i_pUint64 - Pointer to uint64_t value
 *
 * @return uint64_t value from specified pointer
 */
inline uint64_t UINT64_FROM_PTR(const void* i_pUint64)
{
    return reinterpret_cast<const UnalignedData<uint64_t>*>(i_pUint64)->value;
}

/**
 * @brief Read integral value from unaligned pointer.
 *
 * @param[in] i_pUint32 - Pointer to uint32_t value
 *
 * @return uint32_t value from specified pointer
 */
inline uint32_t UINT32_FROM_PTR(const void* i_pUint32)
{
    return reinterpret_cast<const UnalignedData<uint32_t>*>(i_pUint32)->value;
}

/**
 * @brief Read integral value from unaligned pointer.
 *
 * @param[in] i_pUint16 - Pointer to uint16_t value
 *
 * @return uint16_t value from specified pointer
 */
inline uint16_t UINT16_FROM_PTR(const void* i_pUint16)
{
    return reinterpret_cast<const UnalignedData<uint16_t>*>(i_pUint16)->value;
}

/**
 * @brief Read integral value from unaligned pointer.
 *
 * @param[in] i_pInt64 - Pointer to int64_t value
 *
 * @return int64_t value from specified pointer
 */
inline int64_t INT64_FROM_PTR(const void* i_pInt64)
{
    return reinterpret_cast<const UnalignedData<int64_t>*>(i_pInt64)->value;
}

/**
 * @brief Read integral value from unaligned pointer.
 *
 * @param[in] i_pInt32 - Pointer to int32_t value
 *
 * @return int32_t value from specified pointer
 */
inline int32_t INT32_FROM_PTR(const void* i_pInt32)
{
    return reinterpret_cast<const UnalignedData<int32_t>*>(i_pInt32)->value;
}

/**
 * @brief Read integral value from unaligned pointer.
 *
 * @param[in] i_pInt16 - Pointer to int16_t value
 *
 * @return int16_t value from specified pointer
 */
inline int16_t INT16_FROM_PTR(const void* i_pInt16)
{
    return reinterpret_cast<const UnalignedData<int16_t>*>(i_pInt16)->value;
}

/**
 *
 * @class ErrlUserDetailsParser
 *
 * This is an abstract base class that defines how user detail error log data
 * should be parsed. For every different format of user detail data, a
 * component should create a class that derives from this class.
 */
class ErrlUserDetailsParser
{
public:

    /**
     *  @brief Constructor
     *
     */
    ErrlUserDetailsParser()
    {
    }

    /**
     *  @brief Destructor
     *
     */
    virtual ~ErrlUserDetailsParser()
    {
    }

    /**
     *  @brief Parses user detail data from an error log
     *
     *  Parses the supplied user detail data and outputs info to i_parser. This
     *  is a pure virtual function that must be overridden by a concrete derived
     *  class that is specific to a particular component, version and subsection
     *
     *  @param  i_version
     *      Version of the data
     *
     *  @param  i_parse
     *      ErrlUsrParser object for outputting information
     *
     *  @param  i_pBuffer
     *      Pointer to buffer containing detail data
     *
     *  @param  i_buflen
     *      Length of the buffer
     *
     *  @return None
     *
     */
    virtual void parse(errlver_t i_version,
                       ErrlUsrParser & i_parser,
                       void * i_pBuffer,
                       const uint32_t i_buflen) const = 0;

private:

    // Disabled
    ErrlUserDetailsParser(const ErrlUserDetailsParser &);
    ErrlUserDetailsParser & operator=(const ErrlUserDetailsParser &);
};

}
#endif

