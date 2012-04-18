//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/targeting/iterators/rangefilter.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END

#ifndef __TARGETING_COMMON_RANGEFILTER_H
#define __TARGETING_COMMON_RANGEFILTER_H

/**
 *  @file targeting/common/iterators/rangefilter.H
 *
 *  @brief Interface describing an object which takes an iterator range and 
 *      allows caller to iterate through the elements which match a supplied
 *      predicate (filter)
 */

//******************************************************************************
// Includes
//******************************************************************************

// STD

// Other Host Boot Components

// Targeting Component
#include <targeting/common/target.H>
#include <targeting/common/predicates/predicatebase.H>
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

#define TARG_CLASS "RangeFilter<IteratorType>::"

/**
 *  @brief Templated class which which takes an iterator range of arbitrary type
 *      and allows caller to iterate through the elements which match a supplied
 *      predicate (filter)
 */
template<typename IteratorType>
class RangeFilter
{
    public:

        /**
         *  @var Forward the type of iterated elements to help build the 
         *      class generically
         */
        typedef typename IteratorType::value_type value_type;

        /**
         *  @var fake_bool is a pointer to a member function of RangeFilter
         *      which takes no arguments and returns void.
         *      Used to implement ability to check if range iterator is valid 
         */ 
        typedef void (RangeFilter::*fake_bool)() const;

        /**
         *  @brief Create a range object and locate first item in the range that
         *      matches the predicate (or the first if no predicate)
         *
         *  @param[in] i_begin Iterator pointing to first item in range
         *  @param[in] i_end Iterator pointing to last item in range
         *  @param[in] i_pPredicate Predicate evaluated against each pointed to
         *      item
         *
         *  @note Begin iterator must point to element prior to end iterator, 
         *      otherwise result is undefined
         */  
        RangeFilter(
            const IteratorType&  i_begin,
            const IteratorType&  i_end,
            const PredicateBase* i_pPredicate = NULL);

        /**
         *  @brief Destroy a range object (nothing to do)
         */
        ~RangeFilter()
        {
        }

        /**
         *  @brief Dummy function used to implement ability to check if range 
         *      iterator is valid 
         */ 
        operator fake_bool() const;

        /**
         *  @brief Pre-increment operator which advances the range's iterator
         *      to point to the next valid element
         *  
         *  @return Reference to this range filter
         */ 
        RangeFilter& operator++();

        /**
         *  @brief Dereference the range filter, returning the element pointed
         *
         *  @return The element pointed to by the range filter
         */ 
        value_type operator*() const
        {
            return *iv_current;
        }

        /**
         *  @brief Dereference the range filter, returning the element pointed
         *      for use by the dereference and call member operator
         *
         *  @return The element pointed to by the range filter
         */ 
        value_type operator->() const
        {
            return *iv_current;
        }

        /**
         *  @brief Reset the range's internal iterator to point to the first
         *      item in the range that matches the predicate (or the first if no
         *      predicate)
         */ 
        void reset();

        /**
         *  @brief Set the range's predicate filter
         *
         *  @param[in] i_pPredicate Predicate to evaluate against elements 
         *      pointed to by the range
         */  
        void setPredicate(
            const PredicateBase* i_pPredicate);

        /**
         *  @brief Assignment operator; assign one range filter to another
         *
         *  @param[in] i_rhs Range filter to assign
         */  
        RangeFilter& operator=(
            const RangeFilter& i_rhs);

        /**
         *  @brief Copy constructor; create range filter using another range
         *      filter as a prototype for it
         *
         *  @param[in] i_rhs Range filter to assign on create
         */ 
        RangeFilter(
            const RangeFilter& i_rhs);

    private:

        /**
         *  @brief Update internal cursor to point to the next element of the 
         *      underlying range
         *
         *  @note If the internal cursor is at the end of the range, then do 
         *      nothing
         */  
        void advance();

        /**
         *  @brief Update internal cursor to point to the next element of the 
         *      underlying range only if not past the end of the range and the
         *      predicate doesn't match the current item
         *
         *  @note If the internal cursor is at the end of the range, then do 
         *      nothing
         */   
        void advanceIfNoMatch();

        /**
         *  @brief Dummy function used to implement ability to check if range 
         *      iterator is valid 
         */
        void notComparable() const 
        { 
        }

        IteratorType         iv_current;    ///< Iterator pointing to the
                                            ///< current element
        IteratorType         iv_begin;      ///< Iterator pointing to first
                                            ///< element in range
        IteratorType         iv_end;        ///< Iterator to past the end
                                            ///< element in range
        const PredicateBase* iv_pPredicate; ///< Range filter
};

typedef RangeFilter<TargetIterator>      TargetRangeFilter;
typedef RangeFilter<ConstTargetIterator> ConstTargetRangeFilter;

//******************************************************************************
// RangeFilter::RangeFilter 
//******************************************************************************

template<typename IteratorType>
RangeFilter<IteratorType>::RangeFilter(
    const IteratorType&        i_begin,
    const IteratorType&        i_end,
    const PredicateBase* const i_pPredicate)
: iv_current(i_begin),
  iv_begin(i_begin), 
  iv_end(i_end),
  iv_pPredicate(i_pPredicate)
{
    advanceIfNoMatch();
}

//******************************************************************************
// RangeFilter::operator= 
//******************************************************************************

template<typename IteratorType>
RangeFilter<IteratorType>& RangeFilter<IteratorType>::operator=(
    const RangeFilter& i_rhs)
{
    iv_current = i_rhs.iv_current;
    iv_begin = i_rhs.iv_begin;
    iv_end = i_rhs.iv_end;
    iv_pPredicate = i_rhs.iv_pPredicate;
}

//******************************************************************************
// RangeFilter::RangeFilter (copy constructor)
//******************************************************************************

template<typename IteratorType>
RangeFilter<IteratorType>::RangeFilter(
    const RangeFilter& i_rhs)
: iv_current(i_rhs.iv_current),
  iv_begin(i_rhs.iv_begin),
  iv_end(i_rhs.iv_end),
  iv_pPredicate(i_rhs.iv_pPredicate)
{
}

//******************************************************************************
// RangeFilter::setPredicate
//******************************************************************************

template<typename IteratorType>
void RangeFilter<IteratorType>::setPredicate(
    const PredicateBase* const i_pPredicate)
{
    iv_pPredicate = i_pPredicate;
    advanceIfNoMatch();
}

//******************************************************************************
// RangeFilter::reset
//******************************************************************************

template<typename IteratorType>
void RangeFilter<IteratorType>::reset()
{
    iv_current = iv_begin;
    advanceIfNoMatch();
}

//******************************************************************************
// RangeFilter::operator++
//******************************************************************************

template<typename IteratorType>
RangeFilter<IteratorType>& RangeFilter<IteratorType>::operator++()
{
    advance();
    return *this;
}

/**
 *  @brief Disable meaningless "bool" comparisons that can occur when 
 *      evaluating a range as a bool by forcing a compilation failure.
 *      Function interfaces not documented since they are not used. 
 */
template <typename T> 
bool operator!=(const TargetRangeFilter& i_lhs, const T& i_rhs) 
{
    i_lhs.notComparable();
    return false;
} 

template <typename T>
bool operator==(const TargetRangeFilter& i_lhs, const T& i_rhs) 
{
    i_lhs.notComparable();
    return false;
}

template <typename T> 
bool operator!=(const ConstTargetRangeFilter& i_lhs, const T& i_rhs) 
{
    i_lhs.notComparable();
    return false;
} 

template <typename T>
bool operator==(const ConstTargetRangeFilter& i_lhs, const T& i_rhs) 
{
    i_lhs.notComparable();
    return false;
}

#undef TARG_CLASS
#undef TARG_NAMESPACE

} // End namespace TARGETING

#endif // __TARGETING_COMMON_RANGEFILTER

