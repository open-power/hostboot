/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/hwpf/fapi2/include/target_types.H $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2022                        */
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

// Since the basic target types are one-hot bit masks let's define them
// by their log2 and then derive the bit masks by shifting.
enum LogTargetType : uint8_t
{
    LOG_TARGET_TYPE_SYSTEM              =  0, ///< System type
    LOG_TARGET_TYPE_DIMM                =  1, ///< DIMM type
    LOG_TARGET_TYPE_PROC_CHIP           =  2, ///< Processor type
    LOG_TARGET_TYPE_MEMBUF_CHIP         =  3, ///< Membuf type
    LOG_TARGET_TYPE_EX                  =  4, ///< EX - 2x Core, L2, L3 - can be deconfigured
    LOG_TARGET_TYPE_MBA                 =  5, ///< MBA type
    LOG_TARGET_TYPE_MCS                 =  6, ///< MCS type
    LOG_TARGET_TYPE_XBUS                =  7, ///< XBUS type
    LOG_TARGET_TYPE_ABUS                =  8, ///< ABUS type
    LOG_TARGET_TYPE_L4                  =  9, ///< L4 type
    LOG_TARGET_TYPE_CORE                = 10, ///< Core
    LOG_TARGET_TYPE_EQ                  = 11, ///< EQ - 4x core, 2x L2, 2x L3 - can be deconfigured
    LOG_TARGET_TYPE_MCA                 = 12, ///< MCA type
    LOG_TARGET_TYPE_MCBIST              = 13, ///< MCBIST type
    LOG_TARGET_TYPE_MI                  = 14, ///< MI Memory Interface (Cumulus)
    LOG_TARGET_TYPE_CAPP                = 15, ///< CAPP target
    LOG_TARGET_TYPE_DMI                 = 16, ///< DMI type
    LOG_TARGET_TYPE_OBUS                = 17, ///< OBUS type
    LOG_TARGET_TYPE_OBUS_BRICK          = 18, ///< OBUS BRICK type
    LOG_TARGET_TYPE_SBE                 = 19, ///< SBE type
    LOG_TARGET_TYPE_PPE                 = 20, ///< PPE type
    LOG_TARGET_TYPE_PERV                = 21, ///< Pervasive type
    LOG_TARGET_TYPE_PEC                 = 22, ///< PEC type
    LOG_TARGET_TYPE_PHB                 = 23, ///< PHB type
    LOG_TARGET_TYPE_MC                  = 24, ///< MC type
    LOG_TARGET_TYPE_OMI                 = 25, ///< OMI type
    LOG_TARGET_TYPE_OMIC                = 26, ///< OMIC type
    LOG_TARGET_TYPE_MCC                 = 27, ///< MCC type
    LOG_TARGET_TYPE_OCMB_CHIP           = 28, ///< OCMB type
    LOG_TARGET_TYPE_MEM_PORT            = 29, ///< MEM_PORT type
    LOG_TARGET_TYPE_NMMU                = 30, ///< NEST MMU type
    LOG_TARGET_TYPE_RESERVED            = 31, ///< Reserved for Cronus (Z)
    LOG_TARGET_TYPE_PAU                 = 32, ///< PAU type
    LOG_TARGET_TYPE_IOHS                = 33, ///< IOHS type
    LOG_TARGET_TYPE_FC                  = 34, ///< Fused Core type
    LOG_TARGET_TYPE_PMIC                = 35, ///< PMIC type
    LOG_TARGET_TYPE_PAUC                = 36, ///< PAUC type
    LOG_TARGET_TYPE_GENERICI2CRESPONDER = 37, ///< GENERICI2CRESPONDER type
    LOG_TARGET_TYPE_IOLINK              = 38, ///< IOLINK type
    LOG_TARGET_TYPE_MDS_CTLR            = 39, ///< MDS Media Controller type
    LOG_TARGET_TYPE_POWER_IC            = 54, ///< POWER_IC type
    LOG_TARGET_TYPE_TEMP_SENSOR         = 55, ///< TEMP_SENSOR type
    LOG_TARGET_TYPE_MULTICAST           = 63, ///< MULTICAST type
};

/// Target Kind
enum TargetType : uint64_t
{
    TARGET_TYPE_NONE                = 0x0000000000000000, ///< No type

    TARGET_TYPE_SYSTEM              = 1ULL << LOG_TARGET_TYPE_SYSTEM,              ///< System type
    TARGET_TYPE_DIMM                = 1ULL << LOG_TARGET_TYPE_DIMM,                ///< DIMM type
    TARGET_TYPE_PROC_CHIP           = 1ULL << LOG_TARGET_TYPE_PROC_CHIP,           ///< Processor type
    TARGET_TYPE_MEMBUF_CHIP         = 1ULL << LOG_TARGET_TYPE_MEMBUF_CHIP,         ///< Membuf type
    TARGET_TYPE_EX                  = 1ULL << LOG_TARGET_TYPE_EX,                  ///< EX - 2x Core, L2, L3 - can be deconfigured
    TARGET_TYPE_MBA                 = 1ULL << LOG_TARGET_TYPE_MBA,                 ///< MBA type
    TARGET_TYPE_MCS                 = 1ULL << LOG_TARGET_TYPE_MCS,                 ///< MCS type
    TARGET_TYPE_XBUS                = 1ULL << LOG_TARGET_TYPE_XBUS,                ///< XBUS type
    TARGET_TYPE_ABUS                = 1ULL << LOG_TARGET_TYPE_ABUS,                ///< ABUS type
    TARGET_TYPE_L4                  = 1ULL << LOG_TARGET_TYPE_L4,                  ///< L4 type
    TARGET_TYPE_CORE                = 1ULL << LOG_TARGET_TYPE_CORE,                ///< Core
    TARGET_TYPE_EQ                  = 1ULL << LOG_TARGET_TYPE_EQ,                  ///< EQ - 4x core, 2x L2, 2x L3 - can be deconfigured
    TARGET_TYPE_MCA                 = 1ULL << LOG_TARGET_TYPE_MCA,                 ///< MCA type
    TARGET_TYPE_MCBIST              = 1ULL << LOG_TARGET_TYPE_MCBIST,              ///< MCBIST type
    TARGET_TYPE_MI                  = 1ULL << LOG_TARGET_TYPE_MI,                  ///< MI Memory Interface (Cumulus)
    TARGET_TYPE_CAPP                = 1ULL << LOG_TARGET_TYPE_CAPP,                ///< CAPP target
    TARGET_TYPE_DMI                 = 1ULL << LOG_TARGET_TYPE_DMI,                 ///< DMI type
    TARGET_TYPE_OBUS                = 1ULL << LOG_TARGET_TYPE_OBUS,                ///< OBUS type
    TARGET_TYPE_OBUS_BRICK          = 1ULL << LOG_TARGET_TYPE_OBUS_BRICK,          ///< OBUS BRICK type
    TARGET_TYPE_SBE                 = 1ULL << LOG_TARGET_TYPE_SBE,                 ///< SBE type
    TARGET_TYPE_PPE                 = 1ULL << LOG_TARGET_TYPE_PPE,                 ///< PPE type
    TARGET_TYPE_PERV                = 1ULL << LOG_TARGET_TYPE_PERV,                ///< Pervasive type
    TARGET_TYPE_PEC                 = 1ULL << LOG_TARGET_TYPE_PEC,                 ///< PEC type
    TARGET_TYPE_PHB                 = 1ULL << LOG_TARGET_TYPE_PHB,                 ///< PHB type
    TARGET_TYPE_MC                  = 1ULL << LOG_TARGET_TYPE_MC,                  ///< MC type
    TARGET_TYPE_OMI                 = 1ULL << LOG_TARGET_TYPE_OMI,                 ///< OMI type
    TARGET_TYPE_OMIC                = 1ULL << LOG_TARGET_TYPE_OMIC,                ///< OMIC type
    TARGET_TYPE_MCC                 = 1ULL << LOG_TARGET_TYPE_MCC,                 ///< MCC type
    TARGET_TYPE_OCMB_CHIP           = 1ULL << LOG_TARGET_TYPE_OCMB_CHIP,           ///< OCMB type
    TARGET_TYPE_MEM_PORT            = 1ULL << LOG_TARGET_TYPE_MEM_PORT,            ///< MEM_PORT type
    TARGET_TYPE_NMMU                = 1ULL << LOG_TARGET_TYPE_NMMU,                ///< NEST MMU type
    TARGET_TYPE_RESERVED            = 1ULL << LOG_TARGET_TYPE_RESERVED,            ///< Reserved for Cronus (Z)
    TARGET_TYPE_PAU                 = 1ULL << LOG_TARGET_TYPE_PAU,                 ///< PAU type
    TARGET_TYPE_IOHS                = 1ULL << LOG_TARGET_TYPE_IOHS,                ///< IOHS type
    TARGET_TYPE_FC                  = 1ULL << LOG_TARGET_TYPE_FC,                  ///< Fused Core type
    TARGET_TYPE_PMIC                = 1ULL << LOG_TARGET_TYPE_PMIC,                ///< PMIC type
    TARGET_TYPE_PAUC                = 1ULL << LOG_TARGET_TYPE_PAUC,                ///< PAUC type
    TARGET_TYPE_GENERICI2CSLAVE     = 1ULL << LOG_TARGET_TYPE_GENERICI2CRESPONDER, ///< GENERICI2CSLAVE type
    TARGET_TYPE_GENERICI2CRESPONDER = 1ULL << LOG_TARGET_TYPE_GENERICI2CRESPONDER, ///< GENERICI2CRESPONDER type
    TARGET_TYPE_IOLINK              = 1ULL << LOG_TARGET_TYPE_IOLINK,              ///< IOLINK type
    TARGET_TYPE_MDS_CTLR            = 1ULL << LOG_TARGET_TYPE_MDS_CTLR,            ///< MDS Media Controller type
//RESERVED BIT FIELDS - DO NOT USE
    /*
        TARGET_TYPE_RESERVED      = 0x0000010000000000, ///< Reserved - DO NOT USE
        TARGET_TYPE_RESERVED      = 0x0000020000000000, ///< Reserved - DO NOT USE
        TARGET_TYPE_RESERVED      = 0x0000040000000000, ///< Reserved - DO NOT USE
        TARGET_TYPE_RESERVED      = 0x0000080000000000, ///< Reserved - DO NOT USE
        TARGET_TYPE_RESERVED      = 0x0000100000000000, ///< Reserved - DO NOT USE
        TARGET_TYPE_RESERVED      = 0x0000200000000000, ///< Reserved - DO NOT USE
        TARGET_TYPE_RESERVED      = 0x0000400000000000, ///< Reserved - DO NOT USE
        TARGET_TYPE_RESERVED      = 0x0000800000000000, ///< Reserved - DO NOT USE
        TARGET_TYPE_RESERVED      = 0x0001000000000000, ///< Reserved - DO NOT USE
        TARGET_TYPE_RESERVED      = 0x0002000000000000, ///< Reserved - DO NOT USE
        TARGET_TYPE_RESERVED      = 0x0004000000000000, ///< Reserved - DO NOT USE
        TARGET_TYPE_RESERVED      = 0x0008000000000000, ///< Reserved - DO NOT USE
        TARGET_TYPE_RESERVED      = 0x0010000000000000, ///< Reserved - DO NOT USE
        TARGET_TYPE_RESERVED      = 0x0020000000000000, ///< Reserved - DO NOT USE
    */
    TARGET_TYPE_POWER_IC            = 1ULL << LOG_TARGET_TYPE_POWER_IC,            ///< POWER_IC type
    TARGET_TYPE_TEMP_SENSOR         = 1ULL << LOG_TARGET_TYPE_TEMP_SENSOR,         ///< TEMP_SENSOR type
    TARGET_TYPE_MULTICAST           = 1ULL << LOG_TARGET_TYPE_MULTICAST,           ///< MULTICAST type

    TARGET_TYPE_ALL                 = 0x7FFFFFFFFFFFFFFF,                          ///< Any/All types
    TARGET_TYPE_ALL_MC              = 0xFFFFFFFFFFFFFFFF,                          ///< Any/All types + Multicast
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

    TARGET_TYPE_MULTICAST_CHIP = TARGET_TYPE_PROC_CHIP  |
                                 TARGET_TYPE_OCMB_CHIP,

    TARGET_TYPE_ANY_POZ_CHIP  = TARGET_TYPE_PROC_CHIP |
                                TARGET_TYPE_OCMB_CHIP,

    // Mappings to target types found in the error xml files
    TARGET_TYPE_EX_CHIPLET    = TARGET_TYPE_EX,
    TARGET_TYPE_MBA_CHIPLET   = TARGET_TYPE_MBA,
    TARGET_TYPE_MCS_CHIPLET   = TARGET_TYPE_MCS,
    TARGET_TYPE_XBUS_ENDPOINT = TARGET_TYPE_XBUS,
    TARGET_TYPE_ABUS_ENDPOINT = TARGET_TYPE_ABUS,
};

// The fsp x86 compiler is too old to support the full C++11 standard and
// they have not been able to upgrade to a later compiler yet due to a
// requirement to run tools on LCB machines which are still running RHEL6
// which doesn't have the necessary runtime support for executables compiled
// with the newer compiler versions.
//
// Don't compile this forward declaration unless c++11 or greater is being
// used.
//
#if(__GNUC__ && (__cplusplus >= 201103L))
///
/// Target filter 64-bit
/// Declare the enumeration size so that target.H will compile without chip specific filter.
/// When users want to use an enumeration value then they can include the chip specific
/// target_filters.H, which would have the enumerator list of values.
///
enum TargetFilter : uint64_t;
#endif

// attributeOverride tool requires x86.nfp compile
#ifndef CONTEXT_x86_nfp
/// @cond
    constexpr TargetType operator|(TargetType x, TargetType y)
{
    return static_cast<TargetType>(static_cast<uint64_t>(x) |
                                   static_cast<uint64_t>(y));
}

constexpr TargetType operator&(TargetType x, TargetType y)
{
    return static_cast<TargetType>(static_cast<uint64_t>(x) &
                                   static_cast<uint64_t>(y));
}

constexpr TargetType operator~(TargetType x)
{
    return static_cast<TargetType>(~static_cast<uint64_t>(x));
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
