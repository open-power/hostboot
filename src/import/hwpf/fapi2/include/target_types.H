/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/hwpf/fapi2/include/target_types.H $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
 * @file target_types.H
 * @brief definitions for fapi2 target types
 */

#ifndef __FAPI2_TARGET_TYPES__
#define __FAPI2_TARGET_TYPES__
#include <stdint.h>

// File that plat uses to assign values to TargetFilter enum
#include <plat_target_filter.H>


/// FAPI namespace
namespace fapi2
{
///
/// @enum fapi::TargetType
/// @brief Types, kinds, of targets
/// @note TYPE_NONE is used to represent empty/NULL targets in lists
/// or tables. TYPE_ALL is used to pass targets to methods which
/// can act generally on any type of target
///

/// Target Kind
enum TargetType : uint64_t
{
    TARGET_TYPE_NONE            = 0x0000000000000000, ///< No type
    TARGET_TYPE_SYSTEM          = 0x0000000000000001, ///< System type
    TARGET_TYPE_DIMM            = 0x0000000000000002, ///< DIMM type
    TARGET_TYPE_PROC_CHIP       = 0x0000000000000004, ///< Processor type
    TARGET_TYPE_MEMBUF_CHIP     = 0x0000000000000008, ///< Membuf type
    TARGET_TYPE_EX              = 0x0000000000000010, ///< EX - 2x Core, L2, L3 - can be deconfigured
    TARGET_TYPE_MBA             = 0x0000000000000020, ///< MBA type
    TARGET_TYPE_MCS             = 0x0000000000000040, ///< MCS type
    TARGET_TYPE_XBUS            = 0x0000000000000080, ///< XBUS type
    TARGET_TYPE_ABUS            = 0x0000000000000100, ///< ABUS type
    TARGET_TYPE_L4              = 0x0000000000000200, ///< L4 type
    TARGET_TYPE_CORE            = 0x0000000000000400, ///< Core
    TARGET_TYPE_EQ              = 0x0000000000000800, ///< EQ - 4x core, 2x L2, 2x L3 - can be deconfigured
    TARGET_TYPE_MCA             = 0x0000000000001000, ///< MCA type
    TARGET_TYPE_MCBIST          = 0x0000000000002000, ///< MCBIST type
    TARGET_TYPE_MI              = 0x0000000000004000, ///< MI Memory Interface (Cumulus)
    TARGET_TYPE_CAPP            = 0x0000000000008000, ///< CAPP target
    TARGET_TYPE_DMI             = 0x0000000000010000, ///< DMI type
    TARGET_TYPE_OBUS            = 0x0000000000020000, ///< OBUS type
    TARGET_TYPE_OBUS_BRICK      = 0x0000000000040000, ///< OBUS BRICK type
    TARGET_TYPE_SBE             = 0x0000000000080000, ///< SBE type
    TARGET_TYPE_PPE             = 0x0000000000100000, ///< PPE type
    TARGET_TYPE_PERV            = 0x0000000000200000, ///< Pervasive type
    TARGET_TYPE_PEC             = 0x0000000000400000, ///< PEC type
    TARGET_TYPE_PHB             = 0x0000000000800000, ///< PHB type
    TARGET_TYPE_MC              = 0x0000000001000000, ///< MC type
    TARGET_TYPE_OMI             = 0x0000000002000000, ///< OMI type
    TARGET_TYPE_OMIC            = 0x0000000004000000, ///< OMIC type
    TARGET_TYPE_MCC             = 0x0000000008000000, ///< MCC type
    TARGET_TYPE_OCMB_CHIP       = 0x0000000010000000, ///< OCMB type
    TARGET_TYPE_MEM_PORT        = 0x0000000020000000, ///< MEM_PORT type
    TARGET_TYPE_NMMU            = 0x0000000040000000, ///< NEST MMU type
    TARGET_TYPE_RESERVED        = 0x0000000080000000, ///< Reserved for Cronus (Z)
    TARGET_TYPE_PAU             = 0x0000000100000000, ///< PAU type
    TARGET_TYPE_IOHS            = 0x0000000200000000, ///< IOHS type
    TARGET_TYPE_FC              = 0x0000000400000000, ///< Fused Core type
    TARGET_TYPE_PMIC            = 0x0000000800000000, ///< PMIC type
    TARGET_TYPE_PAUC            = 0x0000001000000000, ///< PAUC type
    TARGET_TYPE_GENERICI2CSLAVE = 0x0000002000000000, ///< GENERICI2CSLAVE type
    TARGET_TYPE_IOLINK          = 0x0000004000000000, ///< IOLINK type
    TARGET_TYPE_MULTICAST       = 0x8000000000000000, ///< MULTICAST type
    TARGET_TYPE_ALL             = 0x7FFFFFFFFFFFFFFF, ///< Any/All types
    TARGET_TYPE_ALL_MC          = 0xFFFFFFFFFFFFFFFF, ///< Any/All types + Multicast

    // Compound target types
    TARGET_TYPE_CHIPS         = TARGET_TYPE_PROC_CHIP |
                                TARGET_TYPE_MEMBUF_CHIP |
                                TARGET_TYPE_OCMB_CHIP,

    TARGET_TYPE_CHIPLETS      = TARGET_TYPE_EX            |
                                TARGET_TYPE_MBA           |
                                TARGET_TYPE_MCS           |
                                TARGET_TYPE_XBUS          |
                                TARGET_TYPE_ABUS          |
                                TARGET_TYPE_L4            |
                                TARGET_TYPE_CORE          |
                                TARGET_TYPE_EQ            |
                                TARGET_TYPE_MCA           |
                                TARGET_TYPE_MCBIST        |
                                TARGET_TYPE_MI            |
                                TARGET_TYPE_DMI           |
                                TARGET_TYPE_OBUS          |
                                TARGET_TYPE_OBUS_BRICK    |
                                TARGET_TYPE_SBE           |
                                TARGET_TYPE_PPE           |
                                TARGET_TYPE_PERV          |
                                TARGET_TYPE_PEC           |
                                TARGET_TYPE_PHB           |
                                TARGET_TYPE_MC            |
                                TARGET_TYPE_OMI           |
                                TARGET_TYPE_OMIC          |
                                TARGET_TYPE_MCC           |
                                TARGET_TYPE_MEM_PORT      |
                                TARGET_TYPE_NMMU          |
                                TARGET_TYPE_PAU           |
                                TARGET_TYPE_IOHS          |
                                TARGET_TYPE_FC            |
                                TARGET_TYPE_PAUC          |
                                TARGET_TYPE_IOLINK,

    TARGET_TYPE_MULTICASTABLE = TARGET_TYPE_CORE   |
                                TARGET_TYPE_EQ     |
                                TARGET_TYPE_IOHS   |
                                TARGET_TYPE_MC     |
                                TARGET_TYPE_PAUC   |
                                TARGET_TYPE_PEC    |
                                TARGET_TYPE_PERV,

    // Mappings to target types found in the error xml files
    TARGET_TYPE_EX_CHIPLET    = TARGET_TYPE_EX,
    TARGET_TYPE_MBA_CHIPLET   = TARGET_TYPE_MBA,
    TARGET_TYPE_MCS_CHIPLET   = TARGET_TYPE_MCS,
    TARGET_TYPE_XBUS_ENDPOINT = TARGET_TYPE_XBUS,
    TARGET_TYPE_ABUS_ENDPOINT = TARGET_TYPE_ABUS,
};

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


// attributeOverride tool requires x86.nfp compile
#ifndef CONTEXT_x86_nfp
/// @cond
constexpr TargetType operator|(TargetType x, TargetType y)
{
    return static_cast<TargetType>(static_cast<uint64_t>(x) |
                                   static_cast<uint64_t>(y));
}
#endif

template<uint64_t V>
class bitCount
{
    public:
        // Don't use enums, too hard to compare
        static const uint8_t count = bitCount < (V >> 1) >::count + (V & 1);
};

template<>
class bitCount<0>
{
    public:
        static const uint8_t count = 0;
};
/// @endcond

}

#endif
