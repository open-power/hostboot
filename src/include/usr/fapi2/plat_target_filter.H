/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/fapi2/plat_target_filter.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2018                        */
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
    // These values must contain only 1 bit 'on' so that they can be ORed
    // together as composite filters
    constexpr uint64_t PLAT_TARGET_FILTER_TP          = 0x4000000000000000;  // Pervasive 1
    constexpr uint64_t PLAT_TARGET_FILTER_NEST_NORTH  = 0x2000000000000000;  // Pervasive 2
    constexpr uint64_t PLAT_TARGET_FILTER_NEST_EAST   = 0x1000000000000000;  // Pervasive 3
    constexpr uint64_t PLAT_TARGET_FILTER_NEST_SOUTH  = 0x0800000000000000;  // Pervasive 4
    constexpr uint64_t PLAT_TARGET_FILTER_NEST_WEST   = 0x0400000000000000;  // Pervasive 5
    constexpr uint64_t PLAT_TARGET_FILTER_XBUS        = 0x0200000000000000;  // Pervasive 6
    constexpr uint64_t PLAT_TARGET_FILTER_MC_WEST     = 0x0100000000000000;  // Pervasive 7
    constexpr uint64_t PLAT_TARGET_FILTER_MC_EAST     = 0x0080000000000000;  // Pervasive 8
    constexpr uint64_t PLAT_TARGET_FILTER_OBUS0       = 0x0040000000000000;  // Pervasive 9
    constexpr uint64_t PLAT_TARGET_FILTER_OBUS1       = 0x0020000000000000;  // Pervasive 10
    constexpr uint64_t PLAT_TARGET_FILTER_OBUS2       = 0x0010000000000000;  // Pervasive 11
    constexpr uint64_t PLAT_TARGET_FILTER_OBUS3       = 0x0008000000000000;  // Pervasive 12
    constexpr uint64_t PLAT_TARGET_FILTER_PCI0        = 0x0004000000000000;  // Pervasive 13
    constexpr uint64_t PLAT_TARGET_FILTER_PCI1        = 0x0002000000000000;  // Pervasive 14
    constexpr uint64_t PLAT_TARGET_FILTER_PCI2        = 0x0001000000000000;  // Pervasive 15
    constexpr uint64_t PLAT_TARGET_FILTER_CACHE0      = 0x0000800000000000;  // Pervasive 16
    constexpr uint64_t PLAT_TARGET_FILTER_CACHE1      = 0x0000400000000000;  // Pervasive 17
    constexpr uint64_t PLAT_TARGET_FILTER_CACHE2      = 0x0000200000000000;  // Pervasive 18
    constexpr uint64_t PLAT_TARGET_FILTER_CACHE3      = 0x0000100000000000;  // Pervasive 19
    constexpr uint64_t PLAT_TARGET_FILTER_CACHE4      = 0x0000080000000000;  // Pervasive 20
    constexpr uint64_t PLAT_TARGET_FILTER_CACHE5      = 0x0000040000000000;  // Pervasive 21
    constexpr uint64_t PLAT_TARGET_FILTER_CORE0       = 0x0000000080000000;  // Pervasive 32
    constexpr uint64_t PLAT_TARGET_FILTER_CORE1       = 0x0000000040000000;  // Pervasive 33
    constexpr uint64_t PLAT_TARGET_FILTER_CORE2       = 0x0000000020000000;  // Pervasive 34
    constexpr uint64_t PLAT_TARGET_FILTER_CORE3       = 0x0000000010000000;  // Pervasive 35
    constexpr uint64_t PLAT_TARGET_FILTER_CORE4       = 0x0000000008000000;  // Pervasive 36
    constexpr uint64_t PLAT_TARGET_FILTER_CORE5       = 0x0000000004000000;  // Pervasive 37
    constexpr uint64_t PLAT_TARGET_FILTER_CORE6       = 0x0000000002000000;  // Pervasive 38
    constexpr uint64_t PLAT_TARGET_FILTER_CORE7       = 0x0000000001000000;  // Pervasive 39
    constexpr uint64_t PLAT_TARGET_FILTER_CORE8       = 0x0000000000800000;  // Pervasive 40
    constexpr uint64_t PLAT_TARGET_FILTER_CORE9       = 0x0000000000400000;  // Pervasive 41
    constexpr uint64_t PLAT_TARGET_FILTER_CORE10      = 0x0000000000200000;  // Pervasive 42
    constexpr uint64_t PLAT_TARGET_FILTER_CORE11      = 0x0000000000100000;  // Pervasive 43
    constexpr uint64_t PLAT_TARGET_FILTER_CORE12      = 0x0000000000080000;  // Pervasive 44
    constexpr uint64_t PLAT_TARGET_FILTER_CORE13      = 0x0000000000040000;  // Pervasive 45
    constexpr uint64_t PLAT_TARGET_FILTER_CORE14      = 0x0000000000020000;  // Pervasive 46
    constexpr uint64_t PLAT_TARGET_FILTER_CORE15      = 0x0000000000010000;  // Pervasive 47
    constexpr uint64_t PLAT_TARGET_FILTER_CORE16      = 0x0000000000008000;  // Pervasive 48
    constexpr uint64_t PLAT_TARGET_FILTER_CORE17      = 0x0000000000004000;  // Pervasive 49
    constexpr uint64_t PLAT_TARGET_FILTER_CORE18      = 0x0000000000002000;  // Pervasive 50
    constexpr uint64_t PLAT_TARGET_FILTER_CORE19      = 0x0000000000001000;  // Pervasive 51
    constexpr uint64_t PLAT_TARGET_FILTER_CORE20      = 0x0000000000000800;  // Pervasive 52
    constexpr uint64_t PLAT_TARGET_FILTER_CORE21      = 0x0000000000000400;  // Pervasive 53
    constexpr uint64_t PLAT_TARGET_FILTER_CORE22      = 0x0000000000000200;  // Pervasive 54
    constexpr uint64_t PLAT_TARGET_FILTER_CORE23      = 0x0000000000000100;  // Pervasive 55
#else
    const uint64_t PLAT_TARGET_FILTER_TP          = 0x4000000000000000ULL;  // Pervasive 1
    const uint64_t PLAT_TARGET_FILTER_NEST_NORTH  = 0x2000000000000000ULL;  // Pervasive 2
    const uint64_t PLAT_TARGET_FILTER_NEST_EAST   = 0x1000000000000000ULL;  // Pervasive 3
    const uint64_t PLAT_TARGET_FILTER_NEST_SOUTH  = 0x0800000000000000ULL;  // Pervasive 4
    const uint64_t PLAT_TARGET_FILTER_NEST_WEST   = 0x0400000000000000ULL;  // Pervasive 5
    const uint64_t PLAT_TARGET_FILTER_XBUS        = 0x0200000000000000ULL;  // Pervasive 6
    const uint64_t PLAT_TARGET_FILTER_MC_WEST     = 0x0100000000000000ULL;  // Pervasive 7
    const uint64_t PLAT_TARGET_FILTER_MC_EAST     = 0x0080000000000000ULL;  // Pervasive 8
    const uint64_t PLAT_TARGET_FILTER_OBUS0       = 0x0040000000000000ULL;  // Pervasive 9
    const uint64_t PLAT_TARGET_FILTER_OBUS1       = 0x0020000000000000ULL;  // Pervasive 10
    const uint64_t PLAT_TARGET_FILTER_OBUS2       = 0x0010000000000000ULL;  // Pervasive 11
    const uint64_t PLAT_TARGET_FILTER_OBUS3       = 0x0008000000000000ULL;  // Pervasive 12
    const uint64_t PLAT_TARGET_FILTER_PCI0        = 0x0004000000000000ULL;  // Pervasive 13
    const uint64_t PLAT_TARGET_FILTER_PCI1        = 0x0002000000000000ULL;  // Pervasive 14
    const uint64_t PLAT_TARGET_FILTER_PCI2        = 0x0001000000000000ULL;  // Pervasive 15
    const uint64_t PLAT_TARGET_FILTER_CACHE0      = 0x0000800000000000ULL;  // Pervasive 16
    const uint64_t PLAT_TARGET_FILTER_CACHE1      = 0x0000400000000000ULL;  // Pervasive 17
    const uint64_t PLAT_TARGET_FILTER_CACHE2      = 0x0000200000000000ULL;  // Pervasive 18
    const uint64_t PLAT_TARGET_FILTER_CACHE3      = 0x0000100000000000ULL;  // Pervasive 19
    const uint64_t PLAT_TARGET_FILTER_CACHE4      = 0x0000080000000000ULL;  // Pervasive 20
    const uint64_t PLAT_TARGET_FILTER_CACHE5      = 0x0000040000000000ULL;  // Pervasive 21
    const uint64_t PLAT_TARGET_FILTER_CORE0       = 0x0000000080000000ULL;  // Pervasive 32
    const uint64_t PLAT_TARGET_FILTER_CORE1       = 0x0000000040000000ULL;  // Pervasive 33
    const uint64_t PLAT_TARGET_FILTER_CORE2       = 0x0000000020000000ULL;  // Pervasive 34
    const uint64_t PLAT_TARGET_FILTER_CORE3       = 0x0000000010000000ULL;  // Pervasive 35
    const uint64_t PLAT_TARGET_FILTER_CORE4       = 0x0000000008000000ULL;  // Pervasive 36
    const uint64_t PLAT_TARGET_FILTER_CORE5       = 0x0000000004000000ULL;  // Pervasive 37
    const uint64_t PLAT_TARGET_FILTER_CORE6       = 0x0000000002000000ULL;  // Pervasive 38
    const uint64_t PLAT_TARGET_FILTER_CORE7       = 0x0000000001000000ULL;  // Pervasive 39
    const uint64_t PLAT_TARGET_FILTER_CORE8       = 0x0000000000800000ULL;  // Pervasive 40
    const uint64_t PLAT_TARGET_FILTER_CORE9       = 0x0000000000400000ULL;  // Pervasive 41
    const uint64_t PLAT_TARGET_FILTER_CORE10      = 0x0000000000200000ULL;  // Pervasive 42
    const uint64_t PLAT_TARGET_FILTER_CORE11      = 0x0000000000100000ULL;  // Pervasive 43
    const uint64_t PLAT_TARGET_FILTER_CORE12      = 0x0000000000080000ULL;  // Pervasive 44
    const uint64_t PLAT_TARGET_FILTER_CORE13      = 0x0000000000040000ULL;  // Pervasive 45
    const uint64_t PLAT_TARGET_FILTER_CORE14      = 0x0000000000020000ULL;  // Pervasive 46
    const uint64_t PLAT_TARGET_FILTER_CORE15      = 0x0000000000010000ULL;  // Pervasive 47
    const uint64_t PLAT_TARGET_FILTER_CORE16      = 0x0000000000008000ULL;  // Pervasive 48
    const uint64_t PLAT_TARGET_FILTER_CORE17      = 0x0000000000004000ULL;  // Pervasive 49
    const uint64_t PLAT_TARGET_FILTER_CORE18      = 0x0000000000002000ULL;  // Pervasive 50
    const uint64_t PLAT_TARGET_FILTER_CORE19      = 0x0000000000001000ULL;  // Pervasive 51
    const uint64_t PLAT_TARGET_FILTER_CORE20      = 0x0000000000000800ULL;  // Pervasive 52
    const uint64_t PLAT_TARGET_FILTER_CORE21      = 0x0000000000000400ULL;  // Pervasive 53
    const uint64_t PLAT_TARGET_FILTER_CORE22      = 0x0000000000000200ULL;  // Pervasive 54
    const uint64_t PLAT_TARGET_FILTER_CORE23      = 0x0000000000000100ULL;  // Pervasive 55
#endif
  } // namespace PlatTargetFilter

} // namespace fapi2

#endif
