/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/targeting/common/iterators/rawtargetiterator.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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
            : iv_pCurrent(NULL)
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
            : iv_pCurrent(i_pTarget)
        {
        }

        /**
         *  @brief Destroy an iterator to a (const/non-const) target handle
         *
         *  @note Iterator does not own any resources to destroy
         */
        ALWAYS_INLINE
        ~_TargetRawIterator()
        {
        }


    private:

        /**
         *  @brief Advance the iterator to point to the next item maintained by
         *      the target service (or end() if end of list)
         */
        void advance();

        T iv_pCurrent; // Pointer to current target
};

/**
 *  @brief Type aliases to simplify user code
 */
typedef _TargetRawIterator<Target*> TargetRawIterator;
typedef _TargetRawIterator<const Target*> ConstTargetRawIterator;

#undef TARG_CLASS
#undef TARG_NAMESPACE

} // End namespace TARGETING

#endif // __RAW_TARGETING_COMMON_TARGETITERATOR_H

