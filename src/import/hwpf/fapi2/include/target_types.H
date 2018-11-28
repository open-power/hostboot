/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/hwpf/fapi2/include/target_types.H $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2019                        */
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
    TARGET_TYPE_NONE          = 0x0000000000000000, ///< No type
    TARGET_TYPE_SYSTEM        = 0x0000000000000001, ///< System type
    TARGET_TYPE_DIMM          = 0x0000000000000002, ///< DIMM type
    TARGET_TYPE_PROC_CHIP     = 0x0000000000000004, ///< Processor type
    TARGET_TYPE_MEMBUF_CHIP   = 0x0000000000000008, ///< Membuf type
    TARGET_TYPE_EX            = 0x0000000000000010, ///< EX - 2x Core, L2, L3 - can be deconfigured
    TARGET_TYPE_MBA           = 0x0000000000000020, ///< MBA type
    TARGET_TYPE_MCS           = 0x0000000000000040, ///< MCS type
    TARGET_TYPE_XBUS          = 0x0000000000000080, ///< XBUS type
    TARGET_TYPE_ABUS          = 0x0000000000000100, ///< ABUS type
    TARGET_TYPE_L4            = 0x0000000000000200, ///< L4 type
    TARGET_TYPE_CORE          = 0x0000000000000400, ///< Core
    TARGET_TYPE_EQ            = 0x0000000000000800, ///< EQ - 4x core, 2x L2, 2x L3 - can be deconfigured
    TARGET_TYPE_MCA           = 0x0000000000001000, ///< MCA type
    TARGET_TYPE_MCBIST        = 0x0000000000002000, ///< MCBIST type
    TARGET_TYPE_MI            = 0x0000000000004000, ///< MI Memory Interface (Cumulus)
    TARGET_TYPE_CAPP          = 0x0000000000008000, ///< CAPP target
    TARGET_TYPE_DMI           = 0x0000000000010000, ///< DMI type
    TARGET_TYPE_OBUS          = 0x0000000000020000, ///< OBUS type
    TARGET_TYPE_OBUS_BRICK    = 0x0000000000040000, ///< OBUS BRICK type
    TARGET_TYPE_SBE           = 0x0000000000080000, ///< SBE type
    TARGET_TYPE_PPE           = 0x0000000000100000, ///< PPE type
    TARGET_TYPE_PERV          = 0x0000000000200000, ///< Pervasive type
    TARGET_TYPE_PEC           = 0x0000000000400000, ///< PEC type
    TARGET_TYPE_PHB           = 0x0000000000800000, ///< PHB type
    TARGET_TYPE_MC            = 0x0000000001000000, ///< MC type
    TARGET_TYPE_OMI           = 0x0000000002000000, ///< OMI type
    TARGET_TYPE_OMIC          = 0x0000000004000000, ///< OMIC type
    TARGET_TYPE_MCC           = 0x0000000008000000, ///< MCC type
    TARGET_TYPE_OCMB_CHIP     = 0x0000000010000000, ///< OCMB type
    TARGET_TYPE_MEM_PORT      = 0x0000000020000000, ///< MEM_PORT type
    TARGET_TYPE_NMMU          = 0x0000000040000000, ///< NEST MMU type
    TARGET_TYPE_RESERVED      = 0x0000000080000000, ///< Reserved for Cronus (Z)
    TARGET_TYPE_PAU           = 0x0000000100000000, ///< PAU type
    TARGET_TYPE_IOHS          = 0x0000000200000000, ///< IOHS type
    TARGET_TYPE_FC            = 0x0000000400000000, ///< Fused Core type
    TARGET_TYPE_MULTICAST     = 0x8000000000000000, ///< MULTICAST type
    TARGET_TYPE_ALL           = 0x7FFFFFFFFFFFFFFF, ///< Any/All types
    TARGET_TYPE_ALL_MC        = 0xFFFFFFFFFFFFFFFF, ///< Any/All types + Multicast

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
                                TARGET_TYPE_FC,

    TARGET_TYPE_MULTICASTABLE = TARGET_TYPE_CORE   |
                                TARGET_TYPE_EQ     |
                                TARGET_TYPE_MCBIST |
                                TARGET_TYPE_OBUS   |
                                TARGET_TYPE_PERV   |
                                TARGET_TYPE_PEC,

    // Mappings to target types found in the error xml files
    TARGET_TYPE_EX_CHIPLET    = TARGET_TYPE_EX,
    TARGET_TYPE_MBA_CHIPLET   = TARGET_TYPE_MBA,
    TARGET_TYPE_MCS_CHIPLET   = TARGET_TYPE_MCS,
    TARGET_TYPE_XBUS_ENDPOINT = TARGET_TYPE_XBUS,
    TARGET_TYPE_ABUS_ENDPOINT = TARGET_TYPE_ABUS,
};

///
/// Target filter 64-bit
/// Declare the enumeration size so that target.H will compile without chip specific filter.
/// When users want to use an enumeration value then they can include the chip specific
/// target_filters.H, which would have the enumerator list of values.
///
enum TargetFilter : uint64_t;

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
