/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/conversions.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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

#ifndef __CONVERSIONS_H
#define __CONVERSIONS_H

/**
 *
 * @file conversions.H
 *
 * @brief Provides constants for numerical conversions.
 *
 */

namespace CONVERSIONS
{

/* These constants are used to convert between values in different units. */
enum frequency : size_t
{
    HZ_PER_KHZ  = 1000,
    KHZ_PER_MHZ = 1000,
    HZ_PER_MHZ  = KHZ_PER_MHZ * HZ_PER_KHZ,
};

enum bytesize : size_t
{
    BYTES_PER_KB = 1024
};

// Enum indicating number of bits in certain quantities
enum bitsize : size_t
{
    BITS_PER_BYTE = 8
};

}

#endif
