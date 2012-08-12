/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/include/usr/targeting/common/pointer.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
#ifndef __TARGETING_COMMON_POINTER_H
#define __TARGETING_COMMON_POINTER_H

/**
 *  @file targeting/common/pointer.H
 *
 *  @brief Pointer abstraction that allows Hostboot and FSP to use pointers in
 *      a common way, while maintaining binary compatibility
 */

#include <builtins.h>

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
