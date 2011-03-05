#include <stdint.h>

#ifndef _BUILTINS_H
#define _BUILTINS_H

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
 * Get the value of the link register
 *
 * @return the value of the link register
 */
ALWAYS_INLINE
static inline void *linkRegister()
{
    return __builtin_return_address(1);
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
