/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/common/include/target_filters.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
 * @file target_filters.H
 * @brief definitions for P9 fapi2 target filters
 */

#ifndef __P9_FAPI2_TARGET_FILTERS__
#define __P9_FAPI2_TARGET_FILTERS__
#include <stdint.h>

// File that plat uses to assign values to TargetFilter enum
#include <plat_target_filter.H>

/// FAPI namespace
namespace fapi2
{

///
/// @brief Enumeration of chiplet filters
/// @note plat_target_filter.H assigns enum value using PlatTargetFilter namespace
///
enum TargetFilter : uint64_t
{
    TARGET_FILTER_NONE       = 0x0000000000000000,
    TARGET_FILTER_TP         = PlatTargetFilter::PLAT_TARGET_FILTER_TP,         // Pervasive 1
    TARGET_FILTER_NEST_NORTH = PlatTargetFilter::PLAT_TARGET_FILTER_NEST_NORTH, // Pervasive 2
    TARGET_FILTER_NEST_EAST  = PlatTargetFilter::PLAT_TARGET_FILTER_NEST_EAST,  // Pervasive 3
    TARGET_FILTER_NEST_SOUTH = PlatTargetFilter::PLAT_TARGET_FILTER_NEST_SOUTH, // Pervasive 4
    TARGET_FILTER_NEST_WEST  = PlatTargetFilter::PLAT_TARGET_FILTER_NEST_WEST,  // Pervasive 5
    TARGET_FILTER_XBUS       = PlatTargetFilter::PLAT_TARGET_FILTER_XBUS,       // Pervasive 6
    TARGET_FILTER_MC_WEST    = PlatTargetFilter::PLAT_TARGET_FILTER_MC_WEST,    // Pervasive 7
    TARGET_FILTER_MC_EAST    = PlatTargetFilter::PLAT_TARGET_FILTER_MC_EAST,    // Pervasive 8
    TARGET_FILTER_OBUS0      = PlatTargetFilter::PLAT_TARGET_FILTER_OBUS0,      // Pervasive 9
    TARGET_FILTER_OBUS1      = PlatTargetFilter::PLAT_TARGET_FILTER_OBUS1,      // Pervasive 10
    TARGET_FILTER_OBUS2      = PlatTargetFilter::PLAT_TARGET_FILTER_OBUS2,      // Pervasive 11
    TARGET_FILTER_OBUS3      = PlatTargetFilter::PLAT_TARGET_FILTER_OBUS3,      // Pervasive 12
    TARGET_FILTER_PCI0       = PlatTargetFilter::PLAT_TARGET_FILTER_PCI0,       // Pervasive 13
    TARGET_FILTER_PCI1       = PlatTargetFilter::PLAT_TARGET_FILTER_PCI1,       // Pervasive 14
    TARGET_FILTER_PCI2       = PlatTargetFilter::PLAT_TARGET_FILTER_PCI2,       // Pervasive 15
    TARGET_FILTER_CACHE0     = PlatTargetFilter::PLAT_TARGET_FILTER_CACHE0,     // Pervasive 16
    TARGET_FILTER_CACHE1     = PlatTargetFilter::PLAT_TARGET_FILTER_CACHE1,     // Pervasive 17
    TARGET_FILTER_CACHE2     = PlatTargetFilter::PLAT_TARGET_FILTER_CACHE2,     // Pervasive 18
    TARGET_FILTER_CACHE3     = PlatTargetFilter::PLAT_TARGET_FILTER_CACHE3,     // Pervasive 19
    TARGET_FILTER_CACHE4     = PlatTargetFilter::PLAT_TARGET_FILTER_CACHE4,     // Pervasive 20
    TARGET_FILTER_CACHE5     = PlatTargetFilter::PLAT_TARGET_FILTER_CACHE5,     // Pervasive 21
    TARGET_FILTER_CORE0      = PlatTargetFilter::PLAT_TARGET_FILTER_CORE0,      // Pervasive 32
    TARGET_FILTER_CORE1      = PlatTargetFilter::PLAT_TARGET_FILTER_CORE1,      // Pervasive 33
    TARGET_FILTER_CORE2      = PlatTargetFilter::PLAT_TARGET_FILTER_CORE2,      // Pervasive 34
    TARGET_FILTER_CORE3      = PlatTargetFilter::PLAT_TARGET_FILTER_CORE3,      // Pervasive 35
    TARGET_FILTER_CORE4      = PlatTargetFilter::PLAT_TARGET_FILTER_CORE4,      // Pervasive 36
    TARGET_FILTER_CORE5      = PlatTargetFilter::PLAT_TARGET_FILTER_CORE5,      // Pervasive 37
    TARGET_FILTER_CORE6      = PlatTargetFilter::PLAT_TARGET_FILTER_CORE6,      // Pervasive 38
    TARGET_FILTER_CORE7      = PlatTargetFilter::PLAT_TARGET_FILTER_CORE7,      // Pervasive 39
    TARGET_FILTER_CORE8      = PlatTargetFilter::PLAT_TARGET_FILTER_CORE8,      // Pervasive 20
    TARGET_FILTER_CORE9      = PlatTargetFilter::PLAT_TARGET_FILTER_CORE9,      // Pervasive 41
    TARGET_FILTER_CORE10     = PlatTargetFilter::PLAT_TARGET_FILTER_CORE10,     // Pervasive 42
    TARGET_FILTER_CORE11     = PlatTargetFilter::PLAT_TARGET_FILTER_CORE11,     // Pervasive 43
    TARGET_FILTER_CORE12     = PlatTargetFilter::PLAT_TARGET_FILTER_CORE12,     // Pervasive 44
    TARGET_FILTER_CORE13     = PlatTargetFilter::PLAT_TARGET_FILTER_CORE13,     // Pervasive 45
    TARGET_FILTER_CORE14     = PlatTargetFilter::PLAT_TARGET_FILTER_CORE14,     // Pervasive 46
    TARGET_FILTER_CORE15     = PlatTargetFilter::PLAT_TARGET_FILTER_CORE15,     // Pervasive 47
    TARGET_FILTER_CORE16     = PlatTargetFilter::PLAT_TARGET_FILTER_CORE16,     // Pervasive 48
    TARGET_FILTER_CORE17     = PlatTargetFilter::PLAT_TARGET_FILTER_CORE17,     // Pervasive 49
    TARGET_FILTER_CORE18     = PlatTargetFilter::PLAT_TARGET_FILTER_CORE18,     // Pervasive 50
    TARGET_FILTER_CORE19     = PlatTargetFilter::PLAT_TARGET_FILTER_CORE19,     // Pervasive 51
    TARGET_FILTER_CORE20     = PlatTargetFilter::PLAT_TARGET_FILTER_CORE20,     // Pervasive 52
    TARGET_FILTER_CORE21     = PlatTargetFilter::PLAT_TARGET_FILTER_CORE21,     // Pervasive 53
    TARGET_FILTER_CORE22     = PlatTargetFilter::PLAT_TARGET_FILTER_CORE22,     // Pervasive 54
    TARGET_FILTER_CORE23     = PlatTargetFilter::PLAT_TARGET_FILTER_CORE23,     // Pervasive 55

    // Composite filters follow

    // Pervasive 32-55 (all cores)
    TARGET_FILTER_ALL_CORES   = (TARGET_FILTER_CORE0 |
                                 TARGET_FILTER_CORE1 | TARGET_FILTER_CORE2 |
                                 TARGET_FILTER_CORE3 | TARGET_FILTER_CORE4 |
                                 TARGET_FILTER_CORE5 | TARGET_FILTER_CORE6 |
                                 TARGET_FILTER_CORE7 | TARGET_FILTER_CORE8 |
                                 TARGET_FILTER_CORE9 | TARGET_FILTER_CORE10 |
                                 TARGET_FILTER_CORE11 | TARGET_FILTER_CORE12 |
                                 TARGET_FILTER_CORE13 | TARGET_FILTER_CORE14 |
                                 TARGET_FILTER_CORE15 | TARGET_FILTER_CORE16 |
                                 TARGET_FILTER_CORE17 | TARGET_FILTER_CORE18 |
                                 TARGET_FILTER_CORE19 | TARGET_FILTER_CORE20 |
                                 TARGET_FILTER_CORE21 | TARGET_FILTER_CORE22 |
                                 TARGET_FILTER_CORE23),

    // Pervasive 16-21 (all caches)
    TARGET_FILTER_ALL_CACHES  = (TARGET_FILTER_CACHE0 |
                                 TARGET_FILTER_CACHE1 | TARGET_FILTER_CACHE2 |
                                 TARGET_FILTER_CACHE3 | TARGET_FILTER_CACHE4 |
                                 TARGET_FILTER_CACHE5),

    // Pervasive 2-5 (eg N0-N3) < req'd
    TARGET_FILTER_ALL_NEST    = (TARGET_FILTER_NEST_NORTH |
                                 TARGET_FILTER_NEST_SOUTH | TARGET_FILTER_NEST_EAST |
                                 TARGET_FILTER_NEST_WEST),

    // Pervasive 2-4 (eg N0-N2) < req'd
    TARGET_FILTER_NEST_SLAVES =
        (TARGET_FILTER_NEST_NORTH | TARGET_FILTER_NEST_SOUTH |
         TARGET_FILTER_NEST_EAST),

    // Pervasive 5 (eg N32) < req'd
    TARGET_FILTER_NEST_MASTER = TARGET_FILTER_NEST_WEST,

    // Pervasive 7-8 (eg MC0-MC1)
    TARGET_FILTER_ALL_MC      =
        (TARGET_FILTER_MC_WEST | TARGET_FILTER_MC_EAST),

    // Pervasive 9-12 (OB0-OB3)
    TARGET_FILTER_ALL_OBUS    =
        (TARGET_FILTER_OBUS0 | TARGET_FILTER_OBUS1 | TARGET_FILTER_OBUS2 |
         TARGET_FILTER_OBUS3),

    // Pervasive 13-15 (PCI0-PCI2)
    TARGET_FILTER_ALL_PCI =
        (TARGET_FILTER_PCI0 | TARGET_FILTER_PCI1 | TARGET_FILTER_PCI2),

    // Sync mode filter = All NEST + All MCS
    TARGET_FILTER_SYNC_MODE_NEST =
        (TARGET_FILTER_ALL_NEST | TARGET_FILTER_ALL_MC),

    // All IO Targets except NEST
    TARGET_FILTER_ALL_IO_EXCEPT_NEST =
        (TARGET_FILTER_XBUS | TARGET_FILTER_ALL_PCI | TARGET_FILTER_ALL_OBUS),

    // All sync mode IO except NEST
    TARGET_FILTER_SYNC_MODE_ALL_IO_EXCEPT_NEST =
        (TARGET_FILTER_ALL_MC | TARGET_FILTER_XBUS | TARGET_FILTER_ALL_PCI |
         TARGET_FILTER_ALL_OBUS),

    // All sync mode NEST slaves
    TARGET_FILTER_SYNC_MODE_NEST_SLAVES =
        (TARGET_FILTER_ALL_MC | TARGET_FILTER_NEST_SLAVES),

    // All sync mode IO
    TARGET_FILTER_SYNC_MODE_ALL_IO =
        (TARGET_FILTER_ALL_MC | TARGET_FILTER_ALL_NEST |
         TARGET_FILTER_ALL_OBUS | TARGET_FILTER_ALL_PCI |
         TARGET_FILTER_XBUS),

    // All IO
    TARGET_FILTER_ALL_IO = (TARGET_FILTER_ALL_NEST |
                            TARGET_FILTER_ALL_OBUS | TARGET_FILTER_ALL_PCI |
                            TARGET_FILTER_XBUS),

    // All sync mode except TP
    TARGET_FILTER_SYNC_MODE_ALL_EXCEPT_TP =
        (TARGET_FILTER_ALL_MC | TARGET_FILTER_ALL_NEST |
         TARGET_FILTER_ALL_OBUS | TARGET_FILTER_ALL_PCI |
         TARGET_FILTER_XBUS | TARGET_FILTER_ALL_CORES |
         TARGET_FILTER_ALL_CACHES),
};

}

#endif
