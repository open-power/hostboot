/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/xip/fapi_sbe_common.H $                              */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

/// \file fapi_sbe_common.H
/// \brief provides several preprocessor macros used functions in fixed secion.
///
/// Several preprocessor macros are required to have different definitions in
/// C, C++ and SBE assembly procedures.  These common forms are collected here.

#ifndef __FAPI_SBE_COMMON_H
#define __FAPI_SBE_COMMON_H

/// Several preprocessor macros are required to have different definitions in
/// C, C++ and SBE assembly procedures.  These common forms are collected here.

#if defined __ASSEMBLER__

    #define CONST_UINT8_T(name, expr) .set name, (expr)
    #define CONST_UINT32_T(name, expr) .set name, (expr)
    #define CONST_UINT64_T(name, expr) .set name, (expr)

    #define ULL(x) x

#elif defined __cplusplus

    #include <stdint.h>

    #define CONST_UINT8_T(name, expr) const uint8_t name = (expr);
    #define CONST_UINT32_T(name, expr) const uint32_t name = (expr);
    #define CONST_UINT64_T(name, expr) const uint64_t name = (expr);

    #define ULL(x) x##ull

#else // C code

    // CONST_UINT[8,3,64]_T() can't be used in C code/headers; Use
    //
    //     #define <symbol> <value> [ or ULL(<value>) for 64-bit constants

    #define ULL(x) x##ull

#endif  // __ASSEMBLER__

#endif  // __FAPI_SBE_COMMON_H
