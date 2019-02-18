/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/testcore/tlsmod/trivialctor.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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

#ifndef __TLSMOD_TRIVIALCTOR_H
#define __TLSMOD_TRIVIALCTOR_H

#include <stdint.h>

namespace __tls_test
{

// @note: src/usr/testcore/lib/tls.H for interface
void spawnTasks(
        const char* const i_pFnName,
              void*(*i_pFn)(void*));

class TrivialCtor
{
    size_t value;

  public:

    static constexpr const size_t TRIVIAL_CTOR_INIT_VALUE = 0xBADDEED5;
    static constexpr const size_t TRIVIAL_CTOR_POST_VALUE = 0xBADDEED6;

    /**
     *  @brief Constructor; establishes initial value
     */
    TrivialCtor()
      : value(TRIVIAL_CTOR_INIT_VALUE)
    {
    }

    /**
     *  @brief Return internal value
     *
     *  @return size_t Internal value
     */
    size_t getValue() const
    {
        return value;
    }

    /**
     *  @brief Set internal value
     *
     *  @param[in] i_val Value to set
     */
    void setValue(const size_t i_val)
    {
        value = i_val;
    }
};

}; // End __tls_test namespace

#endif // __TLSMOD_TRIVIALCTOR_H
