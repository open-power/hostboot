/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/target_filters.H $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2022                        */
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
 * @brief definitions for P10 fapi2 target filters
 */

#ifndef __P10_FAPI2_TARGET_FILTERS__
#define __P10_FAPI2_TARGET_FILTERS__
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
    TARGET_FILTER_NEST_SOUTH = PlatTargetFilter::PLAT_TARGET_FILTER_NEST_SOUTH, // Pervasive 3
    TARGET_FILTER_PCI0       = PlatTargetFilter::PLAT_TARGET_FILTER_PCI0,       // Pervasive 8
    TARGET_FILTER_PCI1       = PlatTargetFilter::PLAT_TARGET_FILTER_PCI1,       // Pervasive 9
    TARGET_FILTER_MC0        = PlatTargetFilter::PLAT_TARGET_FILTER_MC0,        // Pervasive 12
    TARGET_FILTER_MC1        = PlatTargetFilter::PLAT_TARGET_FILTER_MC1,        // Pervasive 13
    TARGET_FILTER_MC2        = PlatTargetFilter::PLAT_TARGET_FILTER_MC2,        // Pervasive 14
    TARGET_FILTER_MC3        = PlatTargetFilter::PLAT_TARGET_FILTER_MC3,        // Pervasive 15
    TARGET_FILTER_PAU0       = PlatTargetFilter::PLAT_TARGET_FILTER_PAU0,       // Pervasive 16
    TARGET_FILTER_PAU1       = PlatTargetFilter::PLAT_TARGET_FILTER_PAU1,       // Pervasive 17
    TARGET_FILTER_PAU2       = PlatTargetFilter::PLAT_TARGET_FILTER_PAU2,       // Pervasive 18
    TARGET_FILTER_PAU3       = PlatTargetFilter::PLAT_TARGET_FILTER_PAU3,       // Pervasive 19
    TARGET_FILTER_IOHS0      = PlatTargetFilter::PLAT_TARGET_FILTER_IOHS0,      // Pervasive 24
    TARGET_FILTER_IOHS1      = PlatTargetFilter::PLAT_TARGET_FILTER_IOHS1,      // Pervasive 25
    TARGET_FILTER_IOHS2      = PlatTargetFilter::PLAT_TARGET_FILTER_IOHS2,      // Pervasive 26
    TARGET_FILTER_IOHS3      = PlatTargetFilter::PLAT_TARGET_FILTER_IOHS3,      // Pervasive 27
    TARGET_FILTER_IOHS4      = PlatTargetFilter::PLAT_TARGET_FILTER_IOHS4,      // Pervasive 28
    TARGET_FILTER_IOHS5      = PlatTargetFilter::PLAT_TARGET_FILTER_IOHS5,      // Pervasive 29
    TARGET_FILTER_IOHS6      = PlatTargetFilter::PLAT_TARGET_FILTER_IOHS6,      // Pervasive 30
    TARGET_FILTER_IOHS7      = PlatTargetFilter::PLAT_TARGET_FILTER_IOHS7,      // Pervasive 31
    TARGET_FILTER_EQ0        = PlatTargetFilter::PLAT_TARGET_FILTER_EQ0,        // Pervasive 32
    TARGET_FILTER_EQ1        = PlatTargetFilter::PLAT_TARGET_FILTER_EQ1,        // Pervasive 33
    TARGET_FILTER_EQ2        = PlatTargetFilter::PLAT_TARGET_FILTER_EQ2,        // Pervasive 34
    TARGET_FILTER_EQ3        = PlatTargetFilter::PLAT_TARGET_FILTER_EQ3,        // Pervasive 35
    TARGET_FILTER_EQ4        = PlatTargetFilter::PLAT_TARGET_FILTER_EQ4,        // Pervasive 36
    TARGET_FILTER_EQ5        = PlatTargetFilter::PLAT_TARGET_FILTER_EQ5,        // Pervasive 37
    TARGET_FILTER_EQ6        = PlatTargetFilter::PLAT_TARGET_FILTER_EQ6,        // Pervasive 38
    TARGET_FILTER_EQ7        = PlatTargetFilter::PLAT_TARGET_FILTER_EQ7,        // Pervasive 39
    TARGET_FILTER_MC         = PlatTargetFilter::PLAT_TARGET_FILTER_MC,

    // -----------------
    // Composite filters
    // -----------------

    // Pervasive 2-3 (eg N0-N1)
    TARGET_FILTER_ALL_NEST    = (TARGET_FILTER_NEST_NORTH | TARGET_FILTER_NEST_SOUTH),

    // Pervasive 8-9 (eg PCI0-PCI1)
    TARGET_FILTER_ALL_PCI     = (TARGET_FILTER_PCI0 | TARGET_FILTER_PCI1),

    // Pervasive 12-15 (eg MC0-MC3)
    TARGET_FILTER_ALL_MC      = (TARGET_FILTER_MC0 | TARGET_FILTER_MC1 |
                                 TARGET_FILTER_MC2 | TARGET_FILTER_MC3),

    // Pervasive 16-19 (eg PAU0-PAU3)
    TARGET_FILTER_ALL_PAU     = (TARGET_FILTER_PAU0 | TARGET_FILTER_PAU1 |
                                 TARGET_FILTER_PAU2 | TARGET_FILTER_PAU3),

    // IOHS (eg IOHS0-IOHS7)
    TARGET_FILTER_ALL_IOHS    = (TARGET_FILTER_IOHS0 | TARGET_FILTER_IOHS1 |
                                 TARGET_FILTER_IOHS2 | TARGET_FILTER_IOHS3 |
                                 TARGET_FILTER_IOHS4 | TARGET_FILTER_IOHS5 |
                                 TARGET_FILTER_IOHS6 | TARGET_FILTER_IOHS7),

    // Pervasive 32-39 (eg EQ0-EQ7)
    TARGET_FILTER_ALL_EQ      = (TARGET_FILTER_EQ0 | TARGET_FILTER_EQ1 |
                                 TARGET_FILTER_EQ2 | TARGET_FILTER_EQ3 |
                                 TARGET_FILTER_EQ4 | TARGET_FILTER_EQ5 |
                                 TARGET_FILTER_EQ6 | TARGET_FILTER_EQ7),

    // Chiplet type NORTH (eg MC2-MC3)
    TARGET_FILTER_MC_NORTH    = (TARGET_FILTER_MC2   | TARGET_FILTER_MC3),
    TARGET_FILTER_IOHS_NORTH  = (TARGET_FILTER_IOHS2 | TARGET_FILTER_IOHS3 |
                                 TARGET_FILTER_IOHS6 | TARGET_FILTER_IOHS7),
    TARGET_FILTER_PAU_NORTH   = (TARGET_FILTER_PAU1  | TARGET_FILTER_PAU3),

    TARGET_FILTER_PCI_NORTH   =  TARGET_FILTER_PCI1,

    // Chiplet type SOUTH (eg MC0-MC1)
    TARGET_FILTER_MC_SOUTH    = (TARGET_FILTER_MC0   | TARGET_FILTER_MC1),
    TARGET_FILTER_IOHS_SOUTH  = (TARGET_FILTER_IOHS0 | TARGET_FILTER_IOHS1 |
                                 TARGET_FILTER_IOHS4 | TARGET_FILTER_IOHS5),
    TARGET_FILTER_PAU_SOUTH   = (TARGET_FILTER_PAU0  | TARGET_FILTER_PAU2),

    TARGET_FILTER_PCI_SOUTH   = TARGET_FILTER_PCI0,
};

}

#endif
