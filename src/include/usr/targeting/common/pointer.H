/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/common/pointer.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
#ifndef __TARGETING_COMMON_POINTER_H
#define __TARGETING_COMMON_POINTER_H

/**
 *  @file targeting/common/pointer.H
 *
 *  @brief Pointer abstraction that allows Hostboot and FSP to use pointers in
 *      a common way, while maintaining binary compatibility
 */

#include <builtins.h>
#include <endian.h>

namespace TARGETING
{

/**
 *  @brief Type (union) which implements a common pointer type between Hostboot
 *      and FSP
 */
template<typename T>
union AbstractPointer
{
    uint64_t raw; ///< Raw value of the container

    /**
     *  @brief Specialized address format to support encoding address of
     *      a target/etc. outside a given node.  This is used by platforms with
     *      address translation to traverse associations, and presumes that
     *      byte 0 of any virtual address is never set.
     */
#if __BYTE_ORDER == __LITTLE_ENDIAN
    struct {
        uint64_t ptr : 56;   ///< Node ID indexed to 1.  Value of 0
                             ///< indicates node ID should not be used
                             ///< for address translation
        uint64_t nodeId : 8; ///< Address to translate

    } TranslationEncoded;
#else
    struct {
        uint64_t nodeId : 8; ///< Node ID indexed to 1.  Value of 0
                             ///< indicates node ID should not be used
                             ///< for address translation
        uint64_t ptr : 56;   ///< Address to translate

    } TranslationEncoded;
#endif
    /**
     *  @brief Returns the AbstractPointer as a platform specific pointer
     *
     *  @return Platform specific pointer whose type matches the underlying
     *      template type
     */
    operator T*() const
    { 
        return reinterpret_cast<T*>(raw); 
    }

    /**
     *  @brief Returns the AbstractPointer as a platform specific pointer
     *      incremented by the specified amount.  Note that the pointer
     *      will increment differently, based on the underlying type.
     *
     *  @return Incremented, platform specific pointer whose type matches the
     *      underlying template type
     */
    T* inc(const size_t i_inc) const
    {
        return reinterpret_cast<T*>(raw) + i_inc;
    }

    /**
     *  @brief Returns the AbstractPointer as a uint64_t, which has the same
     *      value as a platform specific pointer converted to a uint64_t
     *
     *  @return uint64_t value of the converted platform specific pointer
     */
    operator uint64_t() const
    { 
        return reinterpret_cast<uint64_t>(reinterpret_cast<T*>(raw)); 
    }
};
  
/**
 *  @brief Macro which accepts an AbstractPointer<T> and returns a pointer
 *      customized to the platform
 *
 *  @param[in] __PTR__
 *      AbstractPointer<T> containing the platform neutral pointer
 *
 *  @return T* pointer customized to the platform
 */
#define TARG_TO_PLAT_PTR(__PTR__) \
    ((__PTR__))


/**
 *  @biref Macro which accepts an AbstractPointer<T>, customizes the pointer to
 *    the platform, then increments the pointer the specified number of times
 *    and returns it
 *
 *  @param[in] __PTR__
 *      AbstractPointer<T> containing the platform neutral pointer
 *
 *  @param[in] __NUM_INCS__
 *      Number of times to increment the platform specific pointer
 *
 *  @return T* pointer customized to the platform, incremented the specified
 *      number of times
 */
#define TARG_TO_PLAT_PTR_AND_INC(__PTR__,__NUM_INCS__) \
    ((__PTR__).inc( __NUM_INCS__))

} // End namespace Targeting

#endif // __TARGETING_COMMON_POINTER_H
