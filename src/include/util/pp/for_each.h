/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/util/pp/for_each.h $                              */
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
#ifndef __UTIL_PP_FOR_EACH_H
#define __UTIL_PP_FOR_EACH_H

/** @file for_each.h
 *
 *  Macros to support a for-each preprocessor directive.
 *
 *  Ex. PREPROCESSOR_FOR_EACH( foo, a, b, c, 1, 2, 3) would expand to:
 *    foo(a); foo(b); foo(c); foo(1); foo(2); foo(3)
 */


// Recursive macros to expand the Nth parameter.
#define PREPROCESSOR_FOR_EACH_0(WHAT)
#define PREPROCESSOR_FOR_EACH_1(WHAT, VAL)  WHAT(VAL)
#define PREPROCESSOR_FOR_EACH_2(WHAT, VAL, ...) \
    WHAT(VAL); PREPROCESSOR_FOR_EACH_1(WHAT, __VA_ARGS__)
#define PREPROCESSOR_FOR_EACH_3(WHAT, VAL, ...) \
    WHAT(VAL); PREPROCESSOR_FOR_EACH_2(WHAT, __VA_ARGS__)
#define PREPROCESSOR_FOR_EACH_4(WHAT, VAL, ...) \
    WHAT(VAL); PREPROCESSOR_FOR_EACH_3(WHAT, __VA_ARGS__)
#define PREPROCESSOR_FOR_EACH_5(WHAT, VAL, ...) \
    WHAT(VAL); PREPROCESSOR_FOR_EACH_4(WHAT, __VA_ARGS__)
#define PREPROCESSOR_FOR_EACH_6(WHAT, VAL, ...) \
    WHAT(VAL); PREPROCESSOR_FOR_EACH_5(WHAT, __VA_ARGS__)
#define PREPROCESSOR_FOR_EACH_7(WHAT, VAL, ...) \
    WHAT(VAL); PREPROCESSOR_FOR_EACH_6(WHAT, __VA_ARGS__)
#define PREPROCESSOR_FOR_EACH_8(WHAT, VAL, ...) \
    WHAT(VAL); PREPROCESSOR_FOR_EACH_7(WHAT, __VA_ARGS__)
#define PREPROCESSOR_FOR_EACH_9(WHAT, VAL, ...) \
    WHAT(VAL); PREPROCESSOR_FOR_EACH_8(WHAT, __VA_ARGS__)
#define PREPROCESSOR_FOR_EACH_10(WHAT, VAL, ...) \
    WHAT(VAL); PREPROCESSOR_FOR_EACH_9(WHAT, __VA_ARGS__)
#define PREPROCESSOR_FOR_EACH_11(WHAT, VAL, ...) \
    WHAT(VAL); PREPROCESSOR_FOR_EACH_10(WHAT, __VA_ARGS__)
#define PREPROCESSOR_FOR_EACH_12(WHAT, VAL, ...) \
    WHAT(VAL); PREPROCESSOR_FOR_EACH_11(WHAT, __VA_ARGS__)
#define PREPROCESSOR_FOR_EACH_13(WHAT, VAL, ...) \
    WHAT(VAL); PREPROCESSOR_FOR_EACH_12(WHAT, __VA_ARGS__)
#define PREPROCESSOR_FOR_EACH_14(WHAT, VAL, ...) \
    WHAT(VAL); PREPROCESSOR_FOR_EACH_13(WHAT, __VA_ARGS__)
#define PREPROCESSOR_FOR_EACH_15(WHAT, VAL, ...) \
    WHAT(VAL); PREPROCESSOR_FOR_EACH_14(WHAT, __VA_ARGS__)
#define PREPROCESSOR_FOR_EACH_16(WHAT, VAL, ...) \
    WHAT(VAL); PREPROCESSOR_FOR_EACH_15(WHAT, __VA_ARGS__)
#define PREPROCESSOR_FOR_EACH_17(WHAT, VAL, ...) \
    WHAT(VAL); PREPROCESSOR_FOR_EACH_16(WHAT, __VA_ARGS__)
#define PREPROCESSOR_FOR_EACH_18(WHAT, VAL, ...) \
    WHAT(VAL); PREPROCESSOR_FOR_EACH_17(WHAT, __VA_ARGS__)
#define PREPROCESSOR_FOR_EACH_19(WHAT, VAL, ...) \
    WHAT(VAL); PREPROCESSOR_FOR_EACH_18(WHAT, __VA_ARGS__)
#define PREPROCESSOR_FOR_EACH_20(WHAT, VAL, ...) \
    WHAT(VAL); PREPROCESSOR_FOR_EACH_19(WHAT, __VA_ARGS__)
#define PREPROCESSOR_FOR_EACH_21(WHAT, VAL, ...) \
    WHAT(VAL); PREPROCESSOR_FOR_EACH_20(WHAT, __VA_ARGS__)
#define PREPROCESSOR_FOR_EACH_22(WHAT, VAL, ...) \
    WHAT(VAL); PREPROCESSOR_FOR_EACH_21(WHAT, __VA_ARGS__)
#define PREPROCESSOR_FOR_EACH_23(WHAT, VAL, ...) \
    WHAT(VAL); PREPROCESSOR_FOR_EACH_22(WHAT, __VA_ARGS__)
#define PREPROCESSOR_FOR_EACH_24(WHAT, VAL, ...) \
    WHAT(VAL); PREPROCESSOR_FOR_EACH_23(WHAT, __VA_ARGS__)
#define PREPROCESSOR_FOR_EACH_25(WHAT, VAL, ...) \
    WHAT(VAL); PREPROCESSOR_FOR_EACH_24(WHAT, __VA_ARGS__)
#define PREPROCESSOR_FOR_EACH_26(WHAT, VAL, ...) \
    WHAT(VAL); PREPROCESSOR_FOR_EACH_25(WHAT, __VA_ARGS__)
#define PREPROCESSOR_FOR_EACH_27(WHAT, VAL, ...) \
    WHAT(VAL); PREPROCESSOR_FOR_EACH_26(WHAT, __VA_ARGS__)
#define PREPROCESSOR_FOR_EACH_28(WHAT, VAL, ...) \
    WHAT(VAL); PREPROCESSOR_FOR_EACH_27(WHAT, __VA_ARGS__)
#define PREPROCESSOR_FOR_EACH_29(WHAT, VAL, ...) \
    WHAT(VAL); PREPROCESSOR_FOR_EACH_28(WHAT, __VA_ARGS__)
#define PREPROCESSOR_FOR_EACH_30(WHAT, VAL, ...) \
    WHAT(VAL); PREPROCESSOR_FOR_EACH_29(WHAT, __VA_ARGS__)
#define PREPROCESSOR_FOR_EACH_31(WHAT, VAL, ...) \
    WHAT(VAL); PREPROCESSOR_FOR_EACH_30(WHAT, __VA_ARGS__)
#define PREPROCESSOR_FOR_EACH_32(WHAT, VAL, ...) \
    WHAT(VAL); PREPROCESSOR_FOR_EACH_31(WHAT, __VA_ARGS__)
#define PREPROCESSOR_FOR_EACH_33(WHAT, VAL, ...) \
    WHAT(VAL); PREPROCESSOR_FOR_EACH_32(WHAT, __VA_ARGS__)
#define PREPROCESSOR_FOR_EACH_34(WHAT, VAL, ...) \
    WHAT(VAL); PREPROCESSOR_FOR_EACH_33(WHAT, __VA_ARGS__)
#define PREPROCESSOR_FOR_EACH_35(WHAT, VAL, ...) \
    WHAT(VAL); PREPROCESSOR_FOR_EACH_34(WHAT, __VA_ARGS__)
#define PREPROCESSOR_FOR_EACH_36(WHAT, VAL, ...) \
    WHAT(VAL); PREPROCESSOR_FOR_EACH_35(WHAT, __VA_ARGS__)
#define PREPROCESSOR_FOR_EACH_37(WHAT, VAL, ...) \
    WHAT(VAL); PREPROCESSOR_FOR_EACH_36(WHAT, __VA_ARGS__)
#define PREPROCESSOR_FOR_EACH_38(WHAT, VAL, ...) \
    WHAT(VAL); PREPROCESSOR_FOR_EACH_37(WHAT, __VA_ARGS__)
#define PREPROCESSOR_FOR_EACH_39(WHAT, VAL, ...) \
    WHAT(VAL); PREPROCESSOR_FOR_EACH_38(WHAT, __VA_ARGS__)
#define PREPROCESSOR_FOR_EACH_40(WHAT, VAL, ...) \
    WHAT(VAL); PREPROCESSOR_FOR_EACH_39(WHAT, __VA_ARGS__)

/** A list of _N tags in reversed order.
 *
 * This is used to count the number of va-arg parameters to the for-each.
 */
#define PREPROCESSOR_REVERSE_LIST_40 \
    _40, _39, _38, _37, _36, _35, _34, _33, _32, _31, \
    _30, _29, _28, _27, _26, _25, _24, _23, _22, _21, \
    _20, _19, _18, _17, _16, _15, _14, _13, _12, _11, \
    _10, _9, _8, _7, _6, _5, _4, _3, _2, _1, _0

/** Count the number of va_arg macros.
 *
 *  Returns a tag from PREPROCESSOR_REVERSE_LIST_40, like _10, based on how
 *  many va-args there are.
 */
#define PREPROCESSOR_COUNT_N_(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, \
                             _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, \
                             _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, \
                             _31, _32, _33, _34, _35, _36, _37, _38, _39, _40, \
                              WHICH, ...)   WHICH
/** Preprocessor redirection to PREPROCESSOR_COUNT_N_ */
#define PREPROCESSOR_COUNT_N(...) PREPROCESSOR_COUNT_N_(__VA_ARGS__)

/** Concatenates two keywords together to make a preprocessor tag */
#define PREPROCESSOR_FOR_EACH_CAT(FN, COUNT) FN ## COUNT

/* Preprocessor redirection to the proper FOR_EACH_N macro. */
#define PREPROCESSOR_FOR_EACH_(FN, COUNT, WHAT, ...) \
    PREPROCESSOR_FOR_EACH_CAT(FN, COUNT)(WHAT,##__VA_ARGS__)

/** Perform a preprocessor for-each operation.
 *
 *  @param WHAT - Action to perform on each variable.
 *  @param ...  - Variable arguments to perform actions on.
 *
 */
#define PREPROCESSOR_FOR_EACH(WHAT, ...) \
    PREPROCESSOR_FOR_EACH_(PREPROCESSOR_FOR_EACH, \
                           PREPROCESSOR_COUNT_N(0, ##__VA_ARGS__ , \
                                                PREPROCESSOR_REVERSE_LIST_40), \
                           WHAT,##__VA_ARGS__)

#endif
