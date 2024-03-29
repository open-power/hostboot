/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/builtins.h $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2019                        */
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
#include <stdint.h>

#ifndef _BUILTINS_H
#define _BUILTINS_H

#include <util/pp/for_each.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * This file should be the home of any use of gcc compiler builtins
 */

/**
 * Use of this macro will ensure that the functions object code never gets generated without being inlined
 */
#define ALWAYS_INLINE __attribute__((always_inline))

/**
 * Use of this macro will ensure that a function is never inlined.
 */
#define NEVER_INLINE __attribute__((noinline))

/**
 * Use of this macro will ensure a data structure is aligned on a cacheline boundary
 */
#define ALIGN_CACHELINE __attribute__((aligned (128)))

/**
 * Function declaration macro that tells the compiler to use printf format checking semantics
 *
 * TODO Could make this a function macro and pass in the 3 args rather than hard coding
 */
#define FORMAT_PRINTF __attribute__((format(printf, 1, 2)))

/**
 * Function delaration macro that tells the compiler that this function never returns.
 */
#define NO_RETURN __attribute__((noreturn))

/**
 * Function / variable declaration macro that tells the compiler what section this symbol should go into.
 */
#define SYMB_SECTION(x) __attribute__((section(#x)))

/**
 * Use of this macro will ensure a data structure is not padded
 */
#define PACKED __attribute__((packed))

/**
 * Variable/function declaration macro that causes a warning to be
 * emitted whenever it's used in source code. (We use the deprecated
 * attribute because it accomplishes the goal, even though
 * semantically it's meant for something else.)  */
#define DONOTUSE(MSG) __attribute__((deprecated(MSG)))

/**
 * Use of this macro will hide compile errors when a variable is not used,
 * usually because it is used in debug / assert statements only.
 */
#define SUPPRESS_UNUSED_VARIABLE(...) \
    PREPROCESSOR_FOR_EACH((void),##__VA_ARGS__)

/**
 * Compiler hint for branch conditions. "condition is likely to be true"
 */
#define likely(expr) __builtin_expect((expr),1)

/**
 * Compiler hint for branch conditions. "condition is likely to be false"
 */
#define unlikely(expr) __builtin_expect((expr),0)

/**
 * Get the value of the link register
 *
 * @return the value of the link register
 */
ALWAYS_INLINE
static inline void *linkRegister()
{
    return __builtin_return_address(0);
}

/**
 * Get the value of the stack-frame pointer
 *
 * @return The value of the frame pointer.
 */
ALWAYS_INLINE
static inline void *framePointer()
{
    return __builtin_frame_address(0);
}

/**
 * Counts leading zeros of a uint64_t value
 *
 * @param value to check
 *
 * @return the number of leading zeros
 */
ALWAYS_INLINE
static inline uint64_t cntlzd(uint64_t value)
{
    return __builtin_clzl(value);
}

/**
 * Counts trailing zeros of a uint64_t value
 *
 * @param value to check
 *
 * @return the number of trailing zeros
 */
ALWAYS_INLINE
static inline uint64_t cnttzd(uint64_t value)
{
    return __builtin_ctzl(value);
}

#ifdef __cplusplus
};
#endif


#endif
