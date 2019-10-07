/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/fapi2/plat_target_filter.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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
/**
 * @file plat_target_filter.H
 * @brief platform bit-mask definitions for fapi2 TargetFilter enum
 */

#ifndef __FAPI2_PLAT_TARGET_FILTER__
#define __FAPI2_PLAT_TARGET_FILTER__

#include <stdint.h>

//
// Define TargetFilter enum values for the platform
//
namespace fapi2
{
namespace PlatTargetFilter
{

// overrideAttribute x86.nfp requires this file to not be in C++11 format
#ifndef CONTEXT_x86_nfp
#define CONSTEXPR constexpr
#else
#define CONSTEXPR const
#endif

// These values must contain only 1 bit 'on' so that they can be ORed
// together as composite filters

CONSTEXPR uint64_t PLAT_TARGET_FILTER_TP          = 0x8000000000000000;  // Pervasive 1
CONSTEXPR uint64_t PLAT_TARGET_FILTER_NEST_NORTH  = 0x4000000000000000;  // Pervasive 2
CONSTEXPR uint64_t PLAT_TARGET_FILTER_NEST_SOUTH  = 0x2000000000000000;  // Pervasive 3
CONSTEXPR uint64_t PLAT_TARGET_FILTER_PCI0        = 0x1000000000000000;  // Pervasive 8
CONSTEXPR uint64_t PLAT_TARGET_FILTER_PCI1        = 0x0800000000000000;  // Pervasive 9
CONSTEXPR uint64_t PLAT_TARGET_FILTER_MC0         = 0x0400000000000000;  // Pervasive 12
CONSTEXPR uint64_t PLAT_TARGET_FILTER_MC1         = 0x0200000000000000;  // Pervasive 13
CONSTEXPR uint64_t PLAT_TARGET_FILTER_MC2         = 0x0100000000000000;  // Pervasive 14
CONSTEXPR uint64_t PLAT_TARGET_FILTER_MC3         = 0x0080000000000000;  // Pervasive 15
CONSTEXPR uint64_t PLAT_TARGET_FILTER_PAU0        = 0x0040000000000000;  // Pervasive 16
CONSTEXPR uint64_t PLAT_TARGET_FILTER_PAU1        = 0x0020000000000000;  // Pervasive 17
CONSTEXPR uint64_t PLAT_TARGET_FILTER_PAU2        = 0x0010000000000000;  // Pervasive 18
CONSTEXPR uint64_t PLAT_TARGET_FILTER_PAU3        = 0x0008000000000000;  // Pervasive 19
CONSTEXPR uint64_t PLAT_TARGET_FILTER_IOHS0       = 0x0004000000000000;  // Pervasive 24
CONSTEXPR uint64_t PLAT_TARGET_FILTER_IOHS1       = 0x0002000000000000;  // Pervasive 25
CONSTEXPR uint64_t PLAT_TARGET_FILTER_IOHS2       = 0x0001000000000000;  // Pervasive 26
CONSTEXPR uint64_t PLAT_TARGET_FILTER_IOHS3       = 0x0000800000000000;  // Pervasive 27
CONSTEXPR uint64_t PLAT_TARGET_FILTER_IOHS4       = 0x0000400000000000;  // Pervasive 28
CONSTEXPR uint64_t PLAT_TARGET_FILTER_IOHS5       = 0x0000200000000000;  // Pervasive 29
CONSTEXPR uint64_t PLAT_TARGET_FILTER_IOHS6       = 0x0000100000000000;  // Pervasive 30
CONSTEXPR uint64_t PLAT_TARGET_FILTER_IOHS7       = 0x0000080000000000;  // Pervasive 31
CONSTEXPR uint64_t PLAT_TARGET_FILTER_EQ0         = 0x0000040000000000;  // Pervasive 32
CONSTEXPR uint64_t PLAT_TARGET_FILTER_EQ1         = 0x0000020000000000;  // Pervasive 33
CONSTEXPR uint64_t PLAT_TARGET_FILTER_EQ2         = 0x0000010000000000;  // Pervasive 34
CONSTEXPR uint64_t PLAT_TARGET_FILTER_EQ3         = 0x0000008000000000;  // Pervasive 35
CONSTEXPR uint64_t PLAT_TARGET_FILTER_EQ4         = 0x0000004000000000;  // Pervasive 36
CONSTEXPR uint64_t PLAT_TARGET_FILTER_EQ5         = 0x0000002000000000;  // Pervasive 37
CONSTEXPR uint64_t PLAT_TARGET_FILTER_EQ6         = 0x0000001000000000;  // Pervasive 38
CONSTEXPR uint64_t PLAT_TARGET_FILTER_EQ7         = 0x0000000800000000;  // Pervasive 39

#undef CONSTEXPR

} // namespace PlatTargetFilter

} // namespace fapi2

#endif
