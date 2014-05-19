/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/common/iterators/rawtargetiterator.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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

#ifndef __RAW_TARGETING_COMMON_TARGETITERATOR_H
#define __RAW_TARGETING_COMMON_TARGETITERATOR_H

/**
 *  @file targeting/common/iterators/rawtargetiterator.H
 *
 *  @brief Interface describing rawiterator/const rawiterator used to iterate
 *      through all target service targets
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD
#include <stddef.h>

// Other Host Boot Components
#include <builtins.h>

// Targeting Component
#include <targeting/common/iterators/targetiterator.H>

//******************************************************************************
// Macros
//******************************************************************************

#undef TARG_NAMESPACE
#undef TARG_CLASS
#undef TARG_FUNC

//******************************************************************************
// Interface
//******************************************************************************

namespace TARGETING
{

#define TARG_NAMESPACE "TARGETING::"

#define TARG_CLASS "_TargetRawIterator<T>::"

class Target;

/**
 *  @brief Class which iterates through targets managed by the target service.
 *      Provides "Target*" and "const Target*" versions via templates
 */
template<typename T>
class _TargetRawIterator : public _TargetIterator<T>
{
    public:

        /**
         *  @brief Maps type of iterated element to common alias (Target* or
         *      const Target*)
         */
        typedef T iterator;
        typedef T value_type;

        /**
         *  @brief Create an iterator to a (const/non-const) target handle.
         *      Defaults to end()
         */
        ALWAYS_INLINE
        _TargetRawIterator()
            : _TargetIterator<T>(NULL)
        {
        }

        /**
         *  @brief Create an iterator to a (const/non-const) target handle
         *
         *  @param[in] i_pTarget Target handle (pointer or const pointer
         *      depending on flavor) the iterator should reference
         */
        ALWAYS_INLINE
        explicit _TargetRawIterator(T i_pTarget)
            : _TargetIterator<T>(i_pTarget)
        {
        }

        /**
         *  @brief Pre-increment the iterator
         *
         *  @return The reference to the same iterator after advancing it
         */
        ALWAYS_INLINE
        _TargetRawIterator& operator++();

        /**
         *  @brief Post-increment the iterator
         *
         *  @param[in] UNNAMED Dummy parameter used to distinguish
         *      this interface from pre-increment
         *
         *  @return Copy of the original iterator before it advanced
         */
        ALWAYS_INLINE
        _TargetRawIterator operator++(int);

        /**
         *  @brief Destroy an iterator to a (const/non-const) target handle
         *
         *  @note Iterator does not own any resources to destroy
         */
        ALWAYS_INLINE
        ~_TargetRawIterator()
        {
        }

        /**
         *  @brief Copy constructor; assign iterator to a new iterator (such
         *      that they logically point to same entity)
         *
         *  @param[in] i_rhs The iterator to assign
         */
        ALWAYS_INLINE
        _TargetRawIterator(const _TargetRawIterator& i_rhs)
            : _TargetIterator<T>(i_rhs)
        {
        }

    private:

        /**
         *  @brief Advance the iterator to point to the next item maintained by
         *      the target service (or end() if end of list)
         */
        void advance();
};

/**
 *  @brief Type aliases to simplify user code
 */
typedef _TargetRawIterator<Target*> TargetRawIterator;
typedef _TargetRawIterator<const Target*> ConstTargetRawIterator;

//******************************************************************************
// _TargetRawIterator::operator++ (postincrement)
//******************************************************************************

template<typename T>
_TargetRawIterator<T> _TargetRawIterator<T>::operator++(int)
{
    _TargetRawIterator l_originalIterator(*this);
    advance();
    return l_originalIterator;
}

//******************************************************************************
// _TargetRawIterator::operator++ (preincrement)
//******************************************************************************

template<typename T>
_TargetRawIterator<T>& _TargetRawIterator<T>::operator++()
{
    advance();
    return *this;
}

#undef TARG_CLASS
#undef TARG_NAMESPACE

} // End namespace TARGETING

#endif // __RAW_TARGETING_COMMON_TARGETITERATOR_H

