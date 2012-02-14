//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/util/traits/impl/has_comparison.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
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

/** @file has_comparison.H
 *
 *  Defines the guts of a has_foo<T> template where 'foo' is a binary
 *  comparison operator on a type T.  This template can be used for
 *  template meta-programming purposes.
 *
 *  The macros UTIL_COMPARISON_OPERATOR and UTIL_COMPARISON_OPERATOR_NAME
 *  can be defined to create a template. For instance (<, lessthan) will
 *  create a template has_lessthan that allows determination to be made on
 *  if T has a valid < operator.
 *
 *  This file purposefully omits an include-guard to allow multiple templates
 *  to be defined for all the various comparison operators.
 *
 *  Notice that a heavy dose of SFINAE techniques follow.
 */

// Ensure UTIL_COMPARISON_OPERATOR has been defined.
#ifndef UTIL_COMPARISON_OPERATOR
    #error Comparison operator is not defined.
#endif

// Ensure UTIL_COMPARISON_OPERATOR_NAME has been defined.
#ifndef UTIL_COMPARISON_OPERATOR_NAME
    #error Comparison operator name is not defined.
#endif

// Macro magic to make well-formed variable names from existing #defines.
#define __UTIL_TRAIT_COMPARISON_MAKENAME(X,Y)   X ## Y
#define _UTIL_TRAIT_COMPARISON_MAKENAME(X,Y)    \
                __UTIL_TRAIT_COMPARISON_MAKENAME(X,Y)
#define UTIL_TRAIT_COMPARISON_MAKENAME(X) \
                _UTIL_TRAIT_COMPARISON_MAKENAME(X,\
                                                UTIL_COMPARISON_OPERATOR_NAME)

namespace Util
{

// Creates a namespace of the form Util::__Util_Trait_Impl_OPERATOR_NAME to
// hide the template implementation in.
namespace UTIL_TRAIT_COMPARISON_MAKENAME(__Util_Trait_Impl_)
{
    // If "T op S" is valid, it is going to return some type (likely bool).  If
    // it is not valid, we still need it to compile cleanly.  So what we do is
    // create a type (convert_from_any_type) that causes implicit type
    // conversion from any other type.  We ensure that the operator against
    // convert_from_any_type returns a special type (bad_type).
    //
    // If "T op S" is valid then the implicit type conversion to
    // convert_from_any_type will not happen because the native "T op S" takes
    // precidence.  So "T op S" has type not equal to bad_type.  If "T op S"
    // is invalid then the implicit type conversion will cause "T op S" to have
    // type bad_type.

    struct bad_type {};
    struct convert_from_any_type
    {
        template <class C> convert_from_any_type(C const&);
    };
    bad_type operator UTIL_COMPARISON_OPERATOR (const convert_from_any_type&,
                                                const convert_from_any_type&);


    // Now, "T op T" is going to return either bad_type or something else.  We
    // define a function 'has_comparison' that returns a character array of
    // different size based on the input parameter type.  Then the "sizeof"
    // can be used to tell if "T op S" returns bad_type or something else.
    //
    // The only additional oddity is the get_instance function.  Since some
    // classes cannot be directly constructed, this is a level of indirection
    // to get a type of T and S to apply the operator against.
    template <typename _T, typename _S>
    struct UTIL_TRAIT_COMPARISON_MAKENAME(has_)
    {
        typedef char yes[1];
        typedef char no[2];

        static no& has_comparison(bad_type);
        static yes& has_comparison(...);

        template <typename C> static C& get_instance();

        static const bool value =
            sizeof(has_comparison(get_instance<_T>() UTIL_COMPARISON_OPERATOR
                                  get_instance<_S>())) == sizeof(yes);
    };

};


// Since the implementation was hidden in a __Util_Trait_Impl_OPERATOR_NAME
// namespace, we expose just the main comparison class (with the value variable)
// by defining a class in the Traits namespace that inherits from the one in
// the __Util_Trait_Impl_OPERATOR_NAME namespace.
namespace Traits
{
    template <typename _T, typename _S = _T>
    struct UTIL_TRAIT_COMPARISON_MAKENAME(has_) :
        public UTIL_TRAIT_COMPARISON_MAKENAME(Util::__Util_Trait_Impl_)::
               UTIL_TRAIT_COMPARISON_MAKENAME(has_)<_T,_S>
    {};
};

};

#undef __UTIL_TRAIT_COMPARISON_MAKENAME
#undef _UTIL_TRAIT_COMPARISON_MAKENAME
#undef UTIL_TRAIT_COMPARISON_MAKENAME

