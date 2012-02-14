//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/util/traits/has_plusequals.H $
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

#ifndef __UTIL_TRAITS_HAS_PLUSEQUALS
#define __UTIL_TRAITS_HAS_PLUSEQUALS

/** @file has_plusequals.H
 *  Creates a template class has_plusequals<T> who's value variable will tell
 *  if T has a valid += operation.
 */

#define UTIL_COMPARISON_OPERATOR +=
#define UTIL_COMPARISON_OPERATOR_NAME plusequals

#include <util/traits/impl/has_comparison.H>

#undef UTIL_COMPARISON_OPERATOR
#undef UTIL_COMPARISON_OPERATOR_NAME

#endif
