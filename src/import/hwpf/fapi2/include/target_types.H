/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: hwpf/fapi2/include/target_types.H $                           */
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
/**
 * @file target_types.H
 * @brief definitions for fapi2 target types
 */

#ifndef __FAPI2_TARGET_TYPES__
#define __FAPI2_TARGET_TYPES__
#include <stdint.h>
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
enum TargetType
{
    TARGET_TYPE_NONE          = 0x00000000, ///< No type
    TARGET_TYPE_SYSTEM        = 0x00000001, ///< System type
    TARGET_TYPE_DIMM          = 0x00000002, ///< DIMM type
    TARGET_TYPE_PROC_CHIP     = 0x00000004, ///< Processor type
    TARGET_TYPE_MEMBUF_CHIP   = 0x00000008, ///< Membuf type
    TARGET_TYPE_EX            = 0x00000010, ///< EX - 2x Core, L2, L3 - can be deconfigured
    TARGET_TYPE_MBA           = 0x00000020, ///< MBA type
    TARGET_TYPE_MCS           = 0x00000040, ///< MCS type
    TARGET_TYPE_XBUS          = 0x00000080, ///< XBUS type
    TARGET_TYPE_ABUS          = 0x00000100, ///< ABUS type
    TARGET_TYPE_L4            = 0x00000200, ///< L4 type
    TARGET_TYPE_CORE          = 0x00000400, ///< Core - 4x threads(?) - can be deconfigured
    TARGET_TYPE_EQ            = 0x00000800, ///< EQ - 4x core, 2x L2, 2x L3 - can be deconfigured
    TARGET_TYPE_MCA           = 0x00001000, ///< MCA type
    TARGET_TYPE_MCBIST        = 0x00002000, ///< MCBIST type
    TARGET_TYPE_MI            = 0x00004000, ///< MI Memory Interface (Cumulus)
    TARGET_TYPE_CAPP          = 0x00008000, ///< CAPP target
    TARGET_TYPE_DMI           = 0x00010000, ///< DMI type
    TARGET_TYPE_OBUS          = 0x00020000, ///< OBUS type
    TARGET_TYPE_NV            = 0x00040000, ///< NV bus type
    TARGET_TYPE_SBE           = 0x00080000, ///< SBE type
    TARGET_TYPE_PPE           = 0x00100000, ///< PPE type
    TARGET_TYPE_PERV          = 0x00200000, ///< Pervasive type
    TARGET_TYPE_PEC           = 0x00400000, ///< PEC type
    TARGET_TYPE_PHB           = 0x00800000, ///< PHB type

    TARGET_TYPE_ALL           = 0xFFFFFFFF, ///< Any/All types

    // Compound target types
    TARGET_TYPE_CHIPS         = TARGET_TYPE_PROC_CHIP |
                                TARGET_TYPE_MEMBUF_CHIP,

    TARGET_TYPE_CHIPLETS      = TARGET_TYPE_EX     |
                                TARGET_TYPE_MBA    |
                                TARGET_TYPE_MCS    |
                                TARGET_TYPE_XBUS   |
                                TARGET_TYPE_ABUS   |
                                TARGET_TYPE_L4     |
                                TARGET_TYPE_CORE   |
                                TARGET_TYPE_EQ     |
                                TARGET_TYPE_MCA    |
                                TARGET_TYPE_MCBIST |
                                TARGET_TYPE_MI     |
                                TARGET_TYPE_DMI    |
                                TARGET_TYPE_OBUS   |
                                TARGET_TYPE_NV     |
                                TARGET_TYPE_SBE    |
                                TARGET_TYPE_PPE    |
                                TARGET_TYPE_PERV   |
                                TARGET_TYPE_PEC    |
                                TARGET_TYPE_PHB,

    // Mappings to target types found in the error xml files
    TARGET_TYPE_EX_CHIPLET    = TARGET_TYPE_EX,
    TARGET_TYPE_MBA_CHIPLET   = TARGET_TYPE_MBA,
    TARGET_TYPE_MCS_CHIPLET   = TARGET_TYPE_MCS,
    TARGET_TYPE_XBUS_ENDPOINT = TARGET_TYPE_XBUS,
    TARGET_TYPE_ABUS_ENDPOINT = TARGET_TYPE_ABUS,
};

///
/// @brief Enumeration of chiplet filters
///
enum TargetFilter
{
    TARGET_FILTER_TP          = 0x8000000000000000,  // Pervasive 1
    TARGET_FILTER_NEST_NORTH  = 0x4000000000000000,  // Pervasive 2
    TARGET_FILTER_NEST_SOUTH  = 0x2000000000000000,  // Pervasive 3
    TARGET_FILTER_NEST_EAST   = 0x1000000000000000,  // Pervasive 4
    TARGET_FILTER_NEST_WEST   = 0x0800000000000000,  // Pervasive 5
    TARGET_FILTER_XBUS        = 0x0400000000000000,  // Pervasive 6
    TARGET_FILTER_MC_WEST     = 0x0200000000000000,  // Pervasive 7
    TARGET_FILTER_MC_EAST     = 0x0100000000000000,  // Pervasive 8
    TARGET_FILTER_OBUS0       = 0x0080000000000000,  // Pervasive 9
    TARGET_FILTER_OBUS1       = 0x0040000000000000,  // Pervasive 10
    TARGET_FILTER_OBUS2       = 0x0020000000000000,  // Pervasive 11
    TARGET_FILTER_OBUS3       = 0x0010000000000000,  // Pervasive 12
    TARGET_FILTER_PCI0        = 0x0008000000000000,  // Pervasive 13
    TARGET_FILTER_PCI1        = 0x0004000000000000,  // Pervasive 14
    TARGET_FILTER_PCI2        = 0x0002000000000000,  // Pervasive 15
    TARGET_FILTER_CACHE0      = 0x0001000000000000,  // Pervasive 16
    TARGET_FILTER_CACHE1      = 0x0000800000000000,  // Pervasive 17
    TARGET_FILTER_CACHE2      = 0x0000400000000000,  // Pervasive 18
    TARGET_FILTER_CACHE3      = 0x0000200000000000,  // Pervasive 19
    TARGET_FILTER_CACHE4      = 0x0000100000000000,  // Pervasive 20
    TARGET_FILTER_CACHE5      = 0x0000080000000000,  // Pervasive 21
    TARGET_FILTER_CORE0       = 0x0000040000000000,  // Pervasive 32
    TARGET_FILTER_CORE1       = 0x0000020000000000,  // Pervasive 33
    TARGET_FILTER_CORE2       = 0x0000010000000000,  // Pervasive 34
    TARGET_FILTER_CORE3       = 0x0000008000000000,  // Pervasive 35
    TARGET_FILTER_CORE4       = 0x0000004000000000,  // Pervasive 36
    TARGET_FILTER_CORE5       = 0x0000002000000000,  // Pervasive 37
    TARGET_FILTER_CORE6       = 0x0000001000000000,  // Pervasive 38
    TARGET_FILTER_CORE7       = 0x0000000800000000,  // Pervasive 39
    TARGET_FILTER_CORE8       = 0x0000000400000000,  // Pervasive 40
    TARGET_FILTER_CORE9       = 0x0000000200000000,  // Pervasive 41
    TARGET_FILTER_CORE10      = 0x0000000100000000,  // Pervasive 42
    TARGET_FILTER_CORE11      = 0x0000000080000000,  // Pervasive 43
    TARGET_FILTER_CORE12      = 0x0000000040000000,  // Pervasive 44
    TARGET_FILTER_CORE13      = 0x0000000020000000,  // Pervasive 45
    TARGET_FILTER_CORE14      = 0x0000000010000000,  // Pervasive 46
    TARGET_FILTER_CORE15      = 0x0000000008000000,  // Pervasive 47
    TARGET_FILTER_CORE16      = 0x0000000004000000,  // Pervasive 48
    TARGET_FILTER_CORE17      = 0x0000000002000000,  // Pervasive 49
    TARGET_FILTER_CORE18      = 0x0000000001000000,  // Pervasive 50
    TARGET_FILTER_CORE19      = 0x0000000000800000,  // Pervasive 51
    TARGET_FILTER_CORE20      = 0x0000000000400000,  // Pervasive 52
    TARGET_FILTER_CORE21      = 0x0000000000200000,  // Pervasive 53
    TARGET_FILTER_CORE22      = 0x0000000000100000,  // Pervasive 54
    TARGET_FILTER_CORE23      = 0x0000000000080000,  // Pervasive 55

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


/// @cond
constexpr TargetType operator|(TargetType x, TargetType y)
{
    return static_cast<TargetType>(static_cast<int>(x) |
                                   static_cast<int>(y));
}

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
