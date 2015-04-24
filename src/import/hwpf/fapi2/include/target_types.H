/**
 * @file target_types.H
 * @brief definitions for fapi2 target types
 */

#ifndef __FAPI2_TARGET_TYPES__
#define __FAPI2_TARGET_TYPES__

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
//      Can be recycled           = 0x00008000, ///<
        TARGET_TYPE_DMI           = 0x00010000, ///< DMI type
        TARGET_TYPE_OBUS          = 0x00020000, ///< OBUS type
        TARGET_TYPE_NV            = 0x00040000, ///< NV bus type
        TARGET_TYPE_SBE           = 0x00080000, ///< SBE type
        TARGET_TYPE_PPE           = 0x00100000, ///< PPE type
        TARGET_TYPE_PERV          = 0x00200000, ///< Pervasive type
        TARGET_TYPE_PEC           = 0x00400000, ///< PEC type
        TARGET_TYPE_PHB           = 0x00800000, ///< PHB type

        TARGET_TYPE_ALL           = 0xFFFFFFFF, ///< Any/All types

        // Mappings to target types found in the error xml files
        TARGET_TYPE_EX_CHIPLET    = TARGET_TYPE_EX,
        TARGET_TYPE_MBA_CHIPLET   = TARGET_TYPE_MBA,
        TARGET_TYPE_MCS_CHIPLET   = TARGET_TYPE_MCS,
        TARGET_TYPE_XBUS_ENDPOINT = TARGET_TYPE_XBUS,
        TARGET_TYPE_ABUS_ENDPOINT = TARGET_TYPE_ABUS,
    };

    /// @cond
    constexpr TargetType operator|(TargetType x, TargetType y)
    {
        return static_cast<TargetType>(static_cast<int>(x) |
                                       static_cast<int>(y));
    }

    template<uint64_t V>
    class bitCount {
    public:
        // Don't use enums, too hard to compare
        static const uint8_t count = bitCount<(V >> 1)>::count + (V & 1);
    };

    template<>
    class bitCount<0> {
    public:
        static const uint8_t count = 0;
    };
    /// @endcond

}

#endif
