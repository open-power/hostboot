/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/testcore/tlsmod/nontrivialctor.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2022                        */
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

#ifndef __TLSMOD_NONTRIVIALCTOR_H
#define __TLSMOD_NONTRIVIALCTOR_H

#include <string.h>

namespace __tls_test
{

class NonTrivialCtor
{
    char* bytes;

  public:

    static constexpr const char* const INIT_VALUE = "0123456789ABCDE";
    static constexpr const char* const POST_VALUE = "1123456789ABCDE";
    static constexpr const size_t NULL_SIZE = 1;

    /**
     *  @brief Build an object that allocates heap memory
     */
    NonTrivialCtor()
    {
        bytes = new char[strlen(INIT_VALUE)+NULL_SIZE]();
        strcpy(bytes,INIT_VALUE);
    }

    /**
     *  @brief Return the object's string storage, allowing updates to it
     *
     *  @return char* Pointer to the internal string
     */
    char* c_str() const
    {
        return bytes;
    }

    /**
     *  @brief Destructor
     */
    ~NonTrivialCtor()
    {
        delete[] bytes;
        bytes = nullptr;
    }

    // Delete the copy/assignment (and move equivalents) constructors/operators
    NonTrivialCtor(const NonTrivialCtor&) = delete;
    NonTrivialCtor& operator=(const NonTrivialCtor&) = delete;
    NonTrivialCtor(NonTrivialCtor&&) = delete;
    NonTrivialCtor& operator=(NonTrivialCtor&&) = delete;
};

}; // End __tls_test namespace

#endif // __TLSMOD_NONTRIVIALCTOR_H
