/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/scom/errlud_cache.H $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2018                        */
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

#ifndef ERRLUD_CACHE_H
#define ERRLUD_CACHE_H

/**
 *  @file errlud_cache.H
 *
 *  Defines the classes that log Centaur SCOM register cache failures
 */

#include <errl/errluserdetails.H>

namespace SECUREBOOT
{

namespace CENTAUR_SECURITY
{

/**
 * @class UdCentaurCacheMismatch
 *
 * @brief Adds Centaur SCOM register cache mismatch FFDC to an error
 *     log
 */
class UdCentaurCacheMismatch : public ERRORLOG::ErrlUserDetails
{
  public:

    /**
     *  @brief Constructor
     *  @param[in] i_registerAddr Register that registered a cache mismatch
     *  @param[in] i_unmaskedExpectedValue Value read from the cache
     *  @param[in] i_unmaskedActualValue Value read from the hardware
     *  @param[in] i_mask Mask of bits to compare between the two values
     */
    UdCentaurCacheMismatch(
        uint64_t i_registerAddr,
        uint64_t i_unmaskedExpectedValue,
        uint64_t i_unmaskedActualValue,
        uint64_t i_mask);

    /**
     *  @brief Destructor
     */
    virtual ~UdCentaurCacheMismatch()
    {
    }

    /**
     * Delete Copy Constructor
     */
    UdCentaurCacheMismatch(const UdCentaurCacheMismatch&) = delete;

    /**
     * Delete Copy Assignment
     */
    UdCentaurCacheMismatch& operator= (const UdCentaurCacheMismatch&) = delete;

    /**
     * Delete Move Constructor
     */
    UdCentaurCacheMismatch (UdCentaurCacheMismatch&&) = delete;

    /**
     * Delete Move Assignment
     */
    UdCentaurCacheMismatch& operator = (UdCentaurCacheMismatch&&) = delete;
};

} // End CENTAUR_SECURITY namespace

} // End SECUREBOOT namespace

#endif
