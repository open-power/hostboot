/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/common/include/cen_const_common.H $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2017                        */
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

#ifndef __CEN_CONST_COMMON_H
#define __CEN_CONST_COMMON_H

#ifndef RULL
    #define RULL(x) x##ull
#endif

#if defined __cplusplus

#include <stdint.h>

template <typename T, uint64_t IDX >
struct cen_fixup
{
    static const T value = T(0);
};

template <uint64_t IDX >
struct cen_fixfld
{
    static const uint8_t value = 255;
};

//Simplified for Centaur!  To fix a register or field just do:
//
//CEN_FIXREG32 (CEN_MBA_1_MAINT_BUFF1_DATA_ECC1_RO, RULL(0xDEADBEEF));
//


#define CEN_FIXREG8(name, newexpr) template<> struct cen_fixup<uint8_t,IDX_##name> { static const uint8_t value = newexpr; };
#define CEN_FIXREG32(name, newexpr) template<> struct cen_fixup<uint32_t,IDX_##name> { static const uint32_t value = newexpr; };
#define CEN_FIXREG64(name, newexpr) template<> struct cen_fixup<uint64_t,IDX_##name> { static const uint64_t value = newexpr; };

#define CEN_REG8(name, expr ) static const uint8_t name = cen_fixup<uint8_t,IDX_##name>::value ? cen_fixup<uint8_t,IDX_##name>::value : expr;
#define CEN_REG32(name, expr) static const uint32_t name = cen_fixup<uint32_t,IDX_##name>::value ? cen_fixup<uint32_t,IDX_##name>::value : expr;
#define CEN_REG64(name, expr) static const uint64_t name = cen_fixup<uint64_t,IDX_##name>::value ? cen_fixup<uint64_t,IDX_##name>::value : expr;

#define CEN_FIXFLD(name, newfld) template<> struct cen_fixfld<IDX_##name> { static const uint8_t value =  newfld; };

#define CEN_FLD(name, fld) static const uint8_t name = cen_fixfld<IDX_##name>::value != 255 ? cen_fixfld<IDX_##name>::value : fld;

#else // C code

// CONST_UINT[8,3,64]_T() can't be used in C code/headers; Use
//
//     #define <symbol> <value> [ or ULL(<value>) for 64-bit constants

#endif  // __cplusplus

#endif  // __CEN_CONST_COMMON_H
