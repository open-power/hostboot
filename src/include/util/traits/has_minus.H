/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/util/traits/has_minus.H $                         */
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

#ifndef __UTIL_TRAITS_HAS_MINUS
#define __UTIL_TRAITS_HAS_MINUS

/** @file has_minus.H
 *  Creates a template class has_minus<T> who's value variable will tell
 *  if T has a valid - operation.
 */

#define UTIL_COMPARISON_OPERATOR -
#define UTIL_COMPARISON_OPERATOR_NAME minus

#include <util/traits/impl/has_comparison.H>

#undef UTIL_COMPARISON_OPERATOR
#undef UTIL_COMPARISON_OPERATOR_NAME

#endif
