/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: $                                                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
 * @file buffer_parameters.H
 * @brief definitions for fapi2 buffer parameter types
 */

#ifndef __FAPI2_BUFFER_PARAM__
#define __FAPI2_BUFFER_PARAM__

#include <stdint.h>

namespace fapi2
{
    /// @cond
    /// @brief Traits of buffer parameters - things passed in
    /// @tparam T is the type of i_value (typically an integral type)
    template<typename T>
    class parameterTraits
    {
    public:
        enum
        {
            mask = T(~0),
            bit_length = sizeof(T) * 8,
            byte_length = sizeof(T),
        };

        template<typename U>
        inline static void write_element(void* i_data, T i_value, uint32_t i_offset)
        {
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
            T* ptr = (T*)i_data + (i_offset ^ ((sizeof(U) / sizeof(T)) - 1));
#else
            T* ptr = (T*)i_data + i_offset;
#endif
            *ptr = i_value;
        }
    };
    /// @endcond
};

#endif
