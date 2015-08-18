/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/common/include/const_common.H $                      */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2012,2015                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */


/*! \brief These are macros used for the scom_addresses.H
 *
 *  Provides macro defintions for defining scom constants
 *  for assembly and C
 *
 */

// - HWP metadata

///
/// @file const_common.H
/// @brief These are macros used for the scom_addresses.H
///
// *HWP HWP Owner: Ben Gass <bgass@us.ibm.com>
// *HWP FW Owner: ? <?>
// *HWP Team: SoA
// *HWP Level: 1
// *HWP Consumed by: XX:XX


#ifndef __CONST_COMMON_H
#define __CONST_COMMON_H

#if defined __ASSEMBLER__

//This probably won't work :(
//  Not sure you can do .set for the same name.
//  If so, it probably takes the last one, which would be the incorrect one
//#define FIXREG8(name, expr, unit, meth, newexpr) .set name, (newexpr)
//#define FIXREG32(name, expr, unit, meth, newexpr) .set name, (newexpr)
//#define FIXREG64(name, expr, unit, meth, newexpr) .set name, (newexpr)
//
//#define CONST_UINT8_T(name, expr, unit, meth) .set name, (expr)
//#define CONST_UINT32_T(name, expr, unit, meth) .set name, (expr)
//#define CONST_UINT64_T(name, expr, unit, meth) .set name, (expr)

#define RULL(x) x

#elif defined __cplusplus

#include <stdint.h>

template <typename T, uint64_t UNIT, uint64_t METH, T REG >
struct has_fixup
{
    static const T value = T(0);
};

template <typename T, uint64_t UNIT, uint64_t METH, T REG, uint64_t FLD >
struct has_fixfld
{
    static const uint8_t value = 255;
};


#define FIXREG8(name, expr, unit, meth, newexpr) template<> struct has_fixup<uint8_t,unit,meth,expr> { static const uint8_t value = newexpr; };
#define FIXREG32(name, expr, unit, meth, newexpr) template<> struct has_fixup<uint32_t,unit,meth,expr> { static const uint32_t value = newexpr; };
#define FIXREG64(name, expr, unit, meth, newexpr) template<> struct has_fixup<uint64_t,unit,meth,expr> { static const uint64_t value = newexpr; };

#define REG8(name, expr, unit, meth) static const uint8_t name = has_fixup<uint8_t,unit,meth,expr>::value ? has_fixup<uint8_t,unit,meth,expr>::value : expr;
#define REG32(name, expr, unit, meth) static const uint32_t name = has_fixup<uint32_t,unit,meth,expr>::value ? has_fixup<uint32_t,unit,meth,expr>::value : expr;
#define REG64(name, expr, unit, meth) static const uint64_t name = has_fixup<uint64_t,unit,meth,expr>::value ? has_fixup<uint64_t,unit,meth,expr>::value : expr;

#define FIXREG8_FLD(name, expr, unit, meth, fld, newexpr) template<> struct has_fixfld<uint8_t,unit,meth,expr,fld> { static const uint8_t value = newexpr; };
#define FIXREG32_FLD(name, expr, unit, meth, fld, newexpr) template<> struct has_fixfld<uint32_t,unit,meth,expr,fld> { static const uint32_t value = newexpr; };
#define FIXREG64_FLD(name, expr, unit, meth, fld, newexpr) template<> struct has_fixfld<uint64_t,unit,meth,expr,fld> { static const uint64_t value = newexpr; };

#define REG8_FLD(name, expr, unit, meth, fld) static const uint8_t name = has_fixfld<uint8_t,unit,meth,expr,fld>::value != 255 ? has_fixfld<uint8_t,unit,meth,expr,fld>::value : expr;
#define REG32_FLD(name, expr, unit, meth, fld) static const uint8_t name = has_fixfld<uint32_t,unit,meth,expr,fld>::value != 255 ? has_fixfld<uint32_t,unit,meth,expr,fld>::value : expr;
#define REG64_FLD(name, expr, unit, meth, fld) static const uint8_t name = has_fixfld<uint64_t,unit,meth,expr,fld>::value != 255 ? has_fixfld<uint64_t,unit,meth,expr,fld>::value : expr;

#define RULL(x) x##ull

#else // C code

// CONST_UINT[8,3,64]_T() can't be used in C code/headers; Use
//
//     #define <symbol> <value> [ or ULL(<value>) for 64-bit constants

#define RULL(x) x##ull

#endif  // __ASSEMBLER__

#endif  // __CONST_COMMON_H
