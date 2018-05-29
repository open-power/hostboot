/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/spd_traits_ddr4.H $         */
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

///
/// @file spd_traits_ddr4.H
/// @brief Assocated traits for reading DDR4 SPD fields
///

// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_SPD_TRAITS_DDR4_H_
#define _MSS_SPD_TRAITS_DDR4_H_

#include <cstdint>
#include <generic/memory/lib/spd/spd_fields_ddr4.H>
#include <generic/memory/lib/spd/spd_traits.H>

namespace mss
{
namespace spd
{

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note BYTES_USED field partial specialization
/// @note valid for all revisions
///
template<rev R>
class readerTraits < fields<DDR4, BASE_CNFG>::BYTES_USED, R>
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b0100; ///< Largest valid SPD encoding
        static constexpr const char* FIELD_STR = "SPD Bytes Used";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note TOTAL_BYTES field specialization
/// @note valid for all revisions
///
template<rev R>
class readerTraits < fields<DDR4, BASE_CNFG>::TOTAL_BYTES, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b010; ///< Largest valid SPD encoding
        static constexpr const char* FIELD_STR = "SPD Bytes Total";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note REVISION field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::REVISION, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFF;
        static constexpr const char* FIELD_STR = "Encoding Level";

        template <typename T>
        using COMPARISON_OP = std::less<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DEVICE_TYPE field specialization
/// @note rev 1.0 specialization
///
template<>
class readerTraits< fields<DDR4, BASE_CNFG>::DEVICE_TYPE, rev::V1_0 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xC; ///< Largest valid SPD encoding
        static constexpr const char* FIELD_STR = "DRAM Device Type";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DEVICE_TYPE field specialization
/// @note valid for rev >= 1.1
///
template< rev R >
class readerTraits< fields<DDR4, BASE_CNFG>::DEVICE_TYPE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x11; ///< Largest valid SPD encoding
        static constexpr const char* FIELD_STR = "DRAM Device Type";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note BASE_MODULE field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::BASE_MODULE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b1101;
        static constexpr const char* FIELD_STR = "Base Module";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note HYBRID field specialization
/// @note rev 1.0 specialization
///
template<>
class readerTraits< fields<DDR4, BASE_CNFG>::HYBRID, rev::V1_0 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0;
        static constexpr const char* FIELD_STR = "Hybrid";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note HYBRID field specialization
/// @note valid for rev >= 1.1 specialization
///
template< rev R >
class readerTraits< fields<DDR4, BASE_CNFG>::HYBRID, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x1;
        static constexpr const char* FIELD_STR = "Hybrid";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note HYBRID_MEDIA field specialization
/// @note rev 1.0 specialization
///
template<>
class readerTraits< fields<DDR4, BASE_CNFG>::HYBRID_MEDIA, rev::V1_0 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0;
        static constexpr const char* FIELD_STR = "Hybrid Media";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note HYBRID_MEDIA field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits< fields<DDR4, BASE_CNFG>::HYBRID_MEDIA, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x1;
        static constexpr const char* FIELD_STR = "Hybrid Media";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note BANK_GROUP_BITS field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::BANK_GROUP_BITS, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b10;
        static constexpr const char* FIELD_STR = "Bank Group";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note BANKS_ADDR_BITS field specialization
/// @note rev 1.0 specialization
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::BANKS_ADDR_BITS, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b01;
        static constexpr const char* FIELD_STR = "Bank Address Bits";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note SDRAM_CAPACITY field specialization
/// @note rev 1.0 specialization
///
template<>
class readerTraits< fields<DDR4, BASE_CNFG>::SDRAM_CAPACITY, rev::V1_0 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b0111;
        static constexpr const char* FIELD_STR = "SDRAM capacity";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note SDRAM_CAPACITY, field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits< fields<DDR4, BASE_CNFG>::SDRAM_CAPACITY, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b1001;
        static constexpr const char* FIELD_STR = "SDRAM Capacity";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note COL_ADDR_BITS field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::COL_ADDR_BITS, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b011;
        static constexpr const char* FIELD_STR = "Column Address Bits";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note ROW_ADDR_BITS field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::ROW_ADDR_BITS, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b110;
        static constexpr const char* FIELD_STR = "Row Address Bits";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PRIM_SIGNAL_LOADING field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::PRIM_SIGNAL_LOADING, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b10;
        static constexpr const char* FIELD_STR = "Primary Signal Loading";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PRIM_DIE_COUNT field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::PRIM_DIE_COUNT, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b111;
        static constexpr const char* FIELD_STR = "Primary Die Count";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PRIM_PACKAGE_TYPE field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits< fields<DDR4, BASE_CNFG>::PRIM_PACKAGE_TYPE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b1;
        static constexpr const char* FIELD_STR = "Primary Package Type";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note MAC field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::MAC, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b1000;
        static constexpr const char* FIELD_STR = "Maximum Activate Count (MAC)";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note TMAW field specialization
/// @note rev 1.0 specialization
///
template< rev R >
class readerTraits< fields<DDR4, BASE_CNFG>::TMAW, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b10;
        static constexpr const char* FIELD_STR = "Maximum Activate Window (TMAW)";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PPR field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::PPR, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b01;
        static constexpr const char* FIELD_STR = "Post package repair (PPR)";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note SOFT_PPR field specialization
/// @note valid for revs
///
template< rev R >
class readerTraits< fields<DDR4, BASE_CNFG>::SOFT_PPR, R >
{
    public:

        // Some existing HW has a soft PPR value of 0b01 despite being rev 1.0
        // So we'll allow even thought it doesn't match the SPD spec....
        static constexpr size_t COMPARISON_VAL = 0b01;
        static constexpr const char* FIELD_STR = "Soft post package repair (SPPR)";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note SEC_SIGNAL_LOADING field specialization
/// @note rev 1.0 specialization
///
template<>
class readerTraits< fields<DDR4, BASE_CNFG>::SEC_SIGNAL_LOADING, rev::V1_0 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0;
        static constexpr const char* FIELD_STR = "Secondary Signal Loading";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note SEC_SIGNAL_LOADING field specialization
/// @note valid for rev >= 1.1
///
template< rev R >
class readerTraits< fields<DDR4, BASE_CNFG>::SEC_SIGNAL_LOADING, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b10;
        static constexpr const char* FIELD_STR = "Secondary Signal Loading";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note SEC_DENSITY_RATIO field specialization
/// @note rev 1.0 specialization
///
template<>
class readerTraits< fields<DDR4, BASE_CNFG>::SEC_DENSITY_RATIO, rev::V1_0 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0;
        static constexpr const char* FIELD_STR = "Secondary DRAM density ratio";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note SEC_DENSITY_RATIO field specialization
/// @note valid for rev >= 1.1
///
template< rev R >
class readerTraits< fields<DDR4, BASE_CNFG>::SEC_DENSITY_RATIO, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b10;
        static constexpr const char* FIELD_STR = "Secondary DRAM density ratio";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note SEC_DIE_COUNT field specialization
/// @note rev 1.0 specialization
///
template<>
class readerTraits< fields<DDR4, BASE_CNFG>::SEC_DIE_COUNT, rev::V1_0 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0;
        static constexpr const char* FIELD_STR = "Secondary Die Count";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note SEC_DIE_COUNT field specialization
/// @note valid for rev >= 1.1
///
template< rev R >
class readerTraits< fields<DDR4, BASE_CNFG>::SEC_DIE_COUNT, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b111;
        static constexpr const char* FIELD_STR = "Secondary Die Count";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note SEC_PACKAGE_TYPE field specialization
/// @note rev 1.0 specialization
///
template< >
class readerTraits< fields<DDR4, BASE_CNFG>::SEC_PACKAGE_TYPE, V1_0 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0;
        static constexpr const char* FIELD_STR = "Secondary Package Type";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note SEC_PACKAGE_TYPE field specialization
/// @note valid for rev >= 1.1
///
template< rev R >
class readerTraits< fields<DDR4, BASE_CNFG>::SEC_PACKAGE_TYPE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b1;
        static constexpr const char* FIELD_STR = "Secondary Package Type";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note OPERABLE_FLD field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::OPERABLE_FLD, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b1;
        static constexpr const char* FIELD_STR = "Operable nominal voltage";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note ENDURANT_FLD field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::ENDURANT_FLD, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b1;
        static constexpr const char* FIELD_STR = "Endurant nominal voltage";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note SDRAM_WIDTH field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::SDRAM_WIDTH, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b011;
        static constexpr const char* FIELD_STR = "Device Width";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note PACKAGE_RANKS field specialization
/// @note rev 1.0 specialization
///
template<>
class readerTraits< fields<DDR4, BASE_CNFG>::PACKAGE_RANKS, rev::V1_0 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b11;
        static constexpr const char* FIELD_STR = "Package Ranks per DIMM";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note PACKAGE_RANKS field specialization
/// @note valid for rev >= 1.1 specialization
///
template< rev R >
class readerTraits< fields<DDR4, BASE_CNFG>::PACKAGE_RANKS, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b111;
        static constexpr const char* FIELD_STR = "Package Ranks per DIMM";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note RANK_MIX field specialization
/// @note rev 1.0 specialization
///
template<>
class readerTraits< fields<DDR4, BASE_CNFG>::RANK_MIX, rev::V1_0 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0;
        static constexpr const char* FIELD_STR = "Rank Mix";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note RANK_MIX field specialization
/// @note rev 1.1 specialization
///
template< rev R >
class readerTraits< fields<DDR4, BASE_CNFG>::RANK_MIX, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b1;
        static constexpr const char* FIELD_STR = "Rank Mix";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note BUS_WIDTH field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::BUS_WIDTH, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b011;
        static constexpr const char* FIELD_STR = "Primary Bus Width";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note BUS_EXT_WIDTH field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::BUS_EXT_WIDTH, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b001;
        static constexpr const char* FIELD_STR = "Bus Width Extension (bits)";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note THERM_SENSOR field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::THERM_SENSOR, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b1;
        static constexpr const char* FIELD_STR = "Thermal Sensor";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note EXTENDED_MODULE_TYPE field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::EXTENDED_MODULE_TYPE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0;
        static constexpr const char* FIELD_STR = "Extended Base Module Type";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note MED_TIMEBASE field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::MEDIUM_TIMEBASE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0;
        static constexpr const char* FIELD_STR = "Medium Timebase";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note FINE_TIMEBASE field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::FINE_TIMEBASE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0;
        static constexpr const char* FIELD_STR = "Fine Timebase";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note TCK_MIN field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::TCK_MIN, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0;
        static constexpr const char* FIELD_STR = "tCKmin in MTB";

        template <typename T>
        using COMPARISON_OP = std::greater<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note TCK_MAX field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::TCK_MAX, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0;
        static constexpr const char* FIELD_STR = "tCKmax in MTB";

        template <typename T>
        using COMPARISON_OP = std::greater<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note CL_FIRST_BYTE field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::CL_FIRST_BYTE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFF;
        static constexpr const char* FIELD_STR = "CAS latencies supported - First byte";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};


///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note CL_SECOND_BYTE field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::CL_SECOND_BYTE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFF;
        static constexpr const char* FIELD_STR = "CAS latencies supported - Second byte";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note CL_THIRD_BYTE field specialization
/// @note rev 1.0 specialization
///
template<>
class readerTraits< fields<DDR4, BASE_CNFG>::CL_THIRD_BYTE, rev::V1_0 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x03;
        static constexpr const char* FIELD_STR = "CAS latencies supported - Third byte";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note CL_THIRD_BYTE field specialization
/// @note valid for rev >= 1.1
///
template< rev R >
class readerTraits< fields<DDR4, BASE_CNFG>::CL_THIRD_BYTE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFF;
        static constexpr const char* FIELD_STR = "CAS latencies supported - Third byte";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note CL_FOURTH_BYTE field specialization
/// @note rev 1.0 specialization
///
template<>
class readerTraits< fields<DDR4, BASE_CNFG>::CL_FOURTH_BYTE, rev::V1_0 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "CAS latencies supported - Fourth byte";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note CL_FOURTH_BYTE field specialization
/// @note valid for rev >= 1.1
///
template< rev R >
class readerTraits< fields<DDR4, BASE_CNFG>::CL_FOURTH_BYTE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xBF;
        static constexpr const char* FIELD_STR = "CAS latencies supported - Fourth byte";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note TAA_MIN field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::TAA_MIN, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "tAAmin in MTB";

        template <typename T>
        using COMPARISON_OP = std::greater<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note TRCD_MIN field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::TRCD_MIN, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "tRCDmin in MTB";

        template <typename T>
        using COMPARISON_OP = std::greater<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note TRP_MIN field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::TRP_MIN, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "tRPmin in MTB";

        template <typename T>
        using COMPARISON_OP = std::greater<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note TRASMIN_MSN field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::TRASMIN_MSN, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "tRASmin (most significant nibble) in MTB";

        template <typename T>
        using COMPARISON_OP = std::greater_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note TRASMIN_LSB field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::TRASMIN_LSB, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "tRASmin (least significant byte) in MTB";

        template <typename T>
        using COMPARISON_OP = std::greater_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note TRCMIN_MSN field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::TRCMIN_MSN, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "tRCmin (most significant nibble) in MTB";

        template <typename T>
        using COMPARISON_OP = std::greater<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::TRCMIN_LSB, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "tRCmin (least significant byte) in MTB";

        template <typename T>
        using COMPARISON_OP = std::greater<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note TRFC1MIN_MSB field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::TRFC1MIN_MSB, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "tRFC1min (most significant byte) in MTB";

        template <typename T>
        using COMPARISON_OP = std::greater_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note TRFC1MIN_LSB field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::TRFC1MIN_LSB, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "tRFC1min (least significant byte) in MTB";

        template <typename T>
        using COMPARISON_OP = std::greater_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note TRFC2MIN_MSB field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::TRFC2MIN_MSB, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "tRFC2min (most significant byte) in MTB";

        template <typename T>
        using COMPARISON_OP = std::greater_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note TRFC2MIN_LSB field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::TRFC2MIN_LSB, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "tRFC2min (least significant byte) in MTB";

        template <typename T>
        using COMPARISON_OP = std::greater_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note TRFC4MIN_MSB field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::TRFC4MIN_MSB, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "tRFC4min (most significant byte) in MTB";


        template <typename T>
        using COMPARISON_OP = std::greater_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note TRFC4MIN_LSB field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::TRFC4MIN_LSB, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "tRFC4min (least significant byte) in MTB";

        template <typename T>
        using COMPARISON_OP = std::greater_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note TFAWMIN_MSN field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::TFAWMIN_MSN, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "Minimum Four Activate Window Delay Time (tFAWmin) in MTB";

        template <typename T>
        using COMPARISON_OP = std::greater_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note TFAWMIN_LSB field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::TFAWMIN_LSB, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "Minimum Four Activate Window Delay Time (tFAWmin) in MTB";

        template <typename T>
        using COMPARISON_OP = std::greater_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note TRRD_S_MIN field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::TRRD_S_MIN, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "tRRD_Smin in MTB";

        template <typename T>
        using COMPARISON_OP = std::greater<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note TRRD_L_MIN field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::TRRD_L_MIN, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "tRRD_Lmin in MTB";

        template <typename T>
        using COMPARISON_OP = std::greater<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note TCCD_L_MIN field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::TCCD_L_MIN, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "tCCD_Lmin in MTB";

        template <typename T>
        using COMPARISON_OP = std::greater<T>;

};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note TWRMIN_MSN field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::TWRMIN_MSN, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "tWRmin (most significant nibble) in MTB";

        template <typename T>
        using COMPARISON_OP = std::greater_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note TWRMIN_LSB field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::TWRMIN_LSB, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "tWRmin (least significant byte) in MTB";

        template <typename T>
        using COMPARISON_OP = std::greater_equal<T>;

};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note TWTRMIN_S_MSN field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::TWTRMIN_S_MSN, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "tWTR_Smin (most significant nibble) in MTB";

        template <typename T>
        using COMPARISON_OP = std::greater_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note TWTRMIN_S_LSB field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::TWTRMIN_S_LSB, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "tWTR_Smin (least significant byte) in MTB";

        template <typename T>
        using COMPARISON_OP = std::greater_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note TWTRMIN_L_MSN field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::TWTRMIN_L_MSN, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "tWTR_Lmin (most significant nibble) in MTB";

        template <typename T>
        using COMPARISON_OP = std::greater_equal<T>;

};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note TWTRMIN_L_LSB field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::TWTRMIN_L_LSB, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "tWTR_Lmin (least significant byte) in MTB";

        template <typename T>
        using COMPARISON_OP = std::greater_equal<T>;

};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note OFFSET_TCCD_L_MIN field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::OFFSET_TCCD_L_MIN, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFF;

        static constexpr const char* FIELD_STR = "Fine Offset tCCD_Lmin in MTB";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};


///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note OFFSET_TRRD_L_MIN field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::OFFSET_TRRD_L_MIN, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFF;

        static constexpr const char* FIELD_STR = "Fine Offset for tRRD_Lmin in MTB";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note OFFSET_TRRD_S_MIN field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::OFFSET_TRRD_S_MIN, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFF;

        static constexpr const char* FIELD_STR = "Fine Offset for tRRD_Smin in MTB";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note OFFSET_TRC_MIN field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::OFFSET_TRC_MIN, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFF;
        static constexpr const char* FIELD_STR = "Fine Offset for tRCmin (least significant byte) in MTB";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note OFFSET_TRP_MIN field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::OFFSET_TRP_MIN, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFF;

        static constexpr const char* FIELD_STR = "Fine Offset for tRPmin in MTB";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note OFFSET_TAA_MIN field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::OFFSET_TAA_MIN, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFF;
        static constexpr const char* FIELD_STR = "Fine Offset for tAAmin in MTB";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note OFFSET_TRCD_MIN field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::OFFSET_TRCD_MIN, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFF;
        static constexpr const char* FIELD_STR = "Fine Offset for tRCDmin in MTB";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note OFFSET_TCK_MIN field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::OFFSET_TCK_MIN, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFF;
        static constexpr const char* FIELD_STR = "Fine Offset for tCKmin in MTB";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note OFFSET_TCK_MAX field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::OFFSET_TCK_MAX, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFF;
        static constexpr const char* FIELD_STR = "Fine Offset for tCKmax in MTB";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note CRC_MSB field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::CRC_MSB, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0;
        static constexpr const char* FIELD_STR = "CRC (most significant byte) for base config";

        template <typename T>
        using COMPARISON_OP = std::greater_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note CRC_LSB field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::CRC_LSB, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0;
        static constexpr const char* FIELD_STR = "CRC (least significant byte) for base config";

        template <typename T>
        using COMPARISON_OP = std::greater_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note CONTINUATION_CODES field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::CONTINUATION_CODES, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x89;
        static constexpr const char* FIELD_STR = "Number of continuation codes, module manufacturer";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note LAST_NON_ZERO_BYTE field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::LAST_NON_ZERO_BYTE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFF;
        static constexpr const char* FIELD_STR = "Last non-zero byte";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note MODULE_MFG_LOCATION field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::MODULE_MFG_LOCATION, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFF;
        static constexpr const char* FIELD_STR = "Module Manufacturing Location";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note MODULE_MFG_DATE_LSB field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::MODULE_MFG_DATE_LSB, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFF;
        static constexpr const char* FIELD_STR = "Odd parity for num of continuation codes, module manufacturer";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note MODULE_MFG_DATE_MSB field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::MODULE_MFG_DATE_MSB, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFF;
        static constexpr const char* FIELD_STR = "Odd parity for num of continuation codes, module manufacturer";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note MODULE_SERIAL_NUM_BYTE1 field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::MODULE_SERIAL_NUM_BYTE1, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFF;
        static constexpr const char* FIELD_STR = "Module Serial Number byte 1";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note MODULE_SERIAL_NUM_BYTE2 field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::MODULE_SERIAL_NUM_BYTE2, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFF;
        static constexpr const char* FIELD_STR = "Module Serial Number byte 2";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note MODULE_SERIAL_NUM_BYTE3 field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::MODULE_SERIAL_NUM_BYTE3, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFF;
        static constexpr const char* FIELD_STR = "Module Serial Number byte 3";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note MODULE_SERIAL_NUM_BYTE4 field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::MODULE_SERIAL_NUM_BYTE4, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFF;
        static constexpr const char* FIELD_STR = "Module Serial Number byte 4";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note MODULE_REV_CODE field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::MODULE_REV_CODE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFF;
        static constexpr const char* FIELD_STR = "Module Revision Code";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DRAM_MFR_ID_CODE_LSB field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::DRAM_MFR_ID_CODE_LSB, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x89;
        static constexpr const char* FIELD_STR = "DRAM manufacturer ID code, LSB";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DRAM_MFR_ID_CODE_MSB field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::DRAM_MFR_ID_CODE_MSB, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "DRAM manufacturer ID code, MSB";

        template <typename T>
        using COMPARISON_OP = std::not_equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DRAM_STEPPING field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, BASE_CNFG>::DRAM_STEPPING, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFF;
        static constexpr const char* FIELD_STR = "DRAM stepping";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note MODULE_NOMINAL_HEIGHT field specialization
/// @note valid for all revisionsRDIMM_MAX (largest decoded rev)
///
template< rev R >
class readerTraits < fields<DDR4, RDIMM_MODULE>::MODULE_NOMINAL_HEIGHT, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b11111;

        static constexpr const char* FIELD_STR = "Module Nominal Height";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note FRONT_MODULE_THICKNESS field specialization
/// @note valid for all revisionsRDIMM_MAX (largest decoded rev)
///
template< rev R >
class readerTraits < fields<DDR4, RDIMM_MODULE>::FRONT_MODULE_THICKNESS, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b1111;

        static constexpr const char* FIELD_STR = "Front Module Max Thickness";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note BACK_MODULE_THICKNESS field specialization
/// @note valid for all revisionsRDIMM_MAX (largest decoded rev)
///
template< rev R >
class readerTraits < fields<DDR4, RDIMM_MODULE>::BACK_MODULE_THICKNESS, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b1111;
        static constexpr const char* FIELD_STR = "Back Module Max Thickness";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note REF_RAW_CARD field specialization
/// @note valid for all revisionsRDIMM_MAX (largest decoded rev)
///
template< rev R >
class readerTraits < fields<DDR4, RDIMM_MODULE>::REF_RAW_CARD, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFF;
        static constexpr const char* FIELD_STR = "Reference Raw Card";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note NUM_REGS_USED field specialization
/// @note valid for all revisionsRDIMM_MAX (largest decoded rev)
///
template< rev R >
class readerTraits < fields<DDR4, RDIMM_MODULE>::NUM_REGS_USED, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b11;
        static constexpr const char* FIELD_STR = "Number of registers used";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note ROWS_OF_DRAMS field specialization
/// @note valid for all revisionsRDIMM_MAX (largest decoded rev)
///
template< rev R >
class readerTraits < fields<DDR4, RDIMM_MODULE>::ROWS_OF_DRAMS, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b11;
        static constexpr const char* FIELD_STR = "Number of rows of DRAMs";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note REGISTER_TYPE field specialization
/// @note valid for all revisionsRDIMM_MAX (largest decoded rev)
///
template< rev R >
class readerTraits < fields<DDR4, RDIMM_MODULE>::REGISTER_TYPE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b0001;
        static constexpr const char* FIELD_STR = "Register Type";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note HEAT_SPREADER_CHAR field specialization
/// @note valid for all revisionsRDIMM_MAX (largest decoded rev)
///
template< rev R >
class readerTraits < fields<DDR4, RDIMM_MODULE>::HEAT_SPREADER_CHAR, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b1;
        static constexpr const char* FIELD_STR = "Heat spreader thermal characteristics";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note HEAT_SPREADER_SOL field specialization
/// @note valid for all revisionsRDIMM_MAX (largest decoded rev)
///
template< rev R >
class readerTraits < fields<DDR4, RDIMM_MODULE>::HEAT_SPREADER_SOL, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b1;
        static constexpr const char* FIELD_STR = "Heat spreader solution";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note CONTINUATION_CODES field specialization
/// @note valid for all revisionsRDIMM_MAX (largest decoded rev)
///
template< rev R >
class readerTraits < fields<DDR4, RDIMM_MODULE>::CONTINUATION_CODES, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x89; // JEP106AS
        static constexpr const char* FIELD_STR = "Number of continuation codes";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note LAST_NON_ZERO_BYTE field specialization
/// @note valid for all revisionsRDIMM_MAX (largest decoded rev)
///
template< rev R >
class readerTraits < fields<DDR4, RDIMM_MODULE>::LAST_NON_ZERO_BYTE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFF;
        static constexpr const char* FIELD_STR = "Last non-zero byte";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note REGISTER_REV field specialization
/// @note valid for all revisionsRDIMM_MAX (largest decoded rev)
///
template< rev R >
class readerTraits < fields<DDR4, RDIMM_MODULE>::REGISTER_REV, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFF;
        static constexpr const char* FIELD_STR = "Register revision number";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note ADDR_MAP_REG_TO_DRAM field specialization
/// @note valid for all revisionsRDIMM_MAX (largest decoded rev)
///
template< rev R >
class readerTraits < fields<DDR4, RDIMM_MODULE>::ADDR_MAP_REG_TO_DRAM, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b1;
        static constexpr const char* FIELD_STR = "Address mapping from register to DRAM";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note CKE_DRIVER field specialization
/// @note valid for all revisionsRDIMM_MAX (largest decoded rev)
///
template<>
class readerTraits< fields<DDR4, RDIMM_MODULE>::CKE_DRIVER, rev::V1_0 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b10;
        static constexpr const char* FIELD_STR = "Register Output Driver for CKE";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note CKE_DRIVER field specialization
/// @note valid for all revisionsRDIMM_MAX (largest decoded rev)
///
template< rev R >
class readerTraits < fields<DDR4, RDIMM_MODULE>::CKE_DRIVER, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b11;
        static constexpr const char* FIELD_STR = "Register Output Driver for CKE";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note ODT_DRIVER field specialization
/// @note valid for all revisionsRDIMM_MAX (largest decoded rev)
///
template<>
class readerTraits< fields<DDR4, RDIMM_MODULE>::ODT_DRIVER, rev::V1_0 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b10;
        static constexpr const char* FIELD_STR = "Register Output Driver for ODT";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note ODT_DRIVER field specialization
/// @note valid for all revisionsRDIMM_MAX (largest decoded rev)
///
template< rev R >
class readerTraits < fields<DDR4, RDIMM_MODULE>::ODT_DRIVER, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b11;
        static constexpr const char* FIELD_STR = "Register Output Driver for ODT";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note CA_DRIVER field specialization
/// @note valid for all revisionsRDIMM_MAX (largest decoded rev)
///
template< rev R >
class readerTraits < fields<DDR4, RDIMM_MODULE>::CA_DRIVER, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b11;
        static constexpr const char* FIELD_STR = "Register Output Driver for command/address (CA)";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note CS_DRIVER field specialization
/// @note rev 1.0 specialization
///
template<>
class readerTraits< fields<DDR4, RDIMM_MODULE>::CS_DRIVER, rev::V1_0 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b10;
        static constexpr const char* FIELD_STR = "Register Output Driver for Chip Select (CS)";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note CS_DRIVER field specialization
/// @note valid for rev >= 1.1
///
template< rev R >
class readerTraits< fields<DDR4, RDIMM_MODULE>::CS_DRIVER, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b11;
        static constexpr const char* FIELD_STR = "Register Output Driver for Chip Select (CS)";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note YO_Y2_DRIVER field specialization
/// @note rev 1.0 specialization
///
template<>
class readerTraits< fields<DDR4, RDIMM_MODULE>::YO_Y2_DRIVER, rev::V1_0 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b10;
        static constexpr const char* FIELD_STR = "Register Output Driver for clock (Y0,Y2)";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note YO_Y2_DRIVER field specialization
/// @note rev 1.1 specialization
///
template< rev R >
class readerTraits< fields<DDR4, RDIMM_MODULE>::YO_Y2_DRIVER, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b11;
        static constexpr const char* FIELD_STR = "Register Output Driver for clock (Y0,Y2)";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note Y1_Y3_DRIVER field specialization
/// @note rev 1.0 specialization
///
template<>
class readerTraits< fields<DDR4, RDIMM_MODULE>::Y1_Y3_DRIVER, rev::V1_0 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b10;
        static constexpr const char* FIELD_STR = "Register Output Driver for clock (Y1,Y3)";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note Y1_Y3_DRIVER field specialization
/// @note valid for rev >= 1.1
///
template< rev R >
class readerTraits< fields<DDR4, RDIMM_MODULE>::Y1_Y3_DRIVER, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b11;
        static constexpr const char* FIELD_STR = "Register Output Driver for clock (Y1,Y3)";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note MODULE_NOMINAL_HEIGHT field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::MODULE_NOMINAL_HEIGHT, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b11111;
        static constexpr const char* FIELD_STR = "Module Nominal Height";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note RAW_CARD_EXT field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::RAW_CARD_EXT, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b111;
        static constexpr const char* FIELD_STR = "Raw Card Extension";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note FRONT_MODULE_THICKNESS field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::FRONT_MODULE_THICKNESS, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b1111;
        static constexpr const char* FIELD_STR = "Front Module Max Thickness";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note BACK_MODULE_THICKNESS field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::BACK_MODULE_THICKNESS, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b1111;
        static constexpr const char* FIELD_STR = "Back Module Max Thickness";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note REF_RAW_CARD field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::REF_RAW_CARD, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFF;
        static constexpr const char* FIELD_STR = "Reference Raw Card";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note NUM_REGS_USED field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::NUM_REGS_USED, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b01;
        static constexpr const char* FIELD_STR = "Number of registers used";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note ROWS_OF_DRAMS field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::ROWS_OF_DRAMS, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b10;
        static constexpr const char* FIELD_STR = "Number of rows of DRAMs";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note REGISTER_TYPE field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::REGISTER_TYPE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b0001;
        static constexpr const char* FIELD_STR = "Register Type";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note HEAT_SPREADER_SOL field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::HEAT_SPREADER_SOL, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b1;
        static constexpr const char* FIELD_STR = "Heat spreader solution";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note CONTINUATION_CODES field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::CONTINUATION_CODES, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x89; // JEP106AS
        static constexpr const char* FIELD_STR = "Number of continuation codes";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note LAST_NON_ZERO_BYTE field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::LAST_NON_ZERO_BYTE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFF;
        static constexpr const char* FIELD_STR = "Last non-zero byte";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note REGISTER_REV field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::REGISTER_REV, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFF;
        static constexpr const char* FIELD_STR = "Register revision number";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note ADDR_MAP_REG_TO_DRAM field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::ADDR_MAP_REG_TO_DRAM, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b1;
        static constexpr const char* FIELD_STR = "Address mapping from register to DRAM";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note CKE_DRIVER field specialization
/// @note rev 1.0 specialization
///
template<>
class readerTraits< fields<DDR4, LRDIMM_MODULE>::CKE_DRIVER, rev::V1_0 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b10;

        static constexpr const char* FIELD_STR = "Register Output Driver for CKE";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note CKE_DRIVER field specialization
/// @note valid for rev >= 1.1 specialization
///
template< rev R >
class readerTraits< fields<DDR4, LRDIMM_MODULE>::CKE_DRIVER, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b11;
        static constexpr const char* FIELD_STR = "Register Output Driver for CKE";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note ODT_DRIVER field specialization
/// @note rev 1.0 specialization
///
template<>
class readerTraits< fields<DDR4, LRDIMM_MODULE>::ODT_DRIVER, rev::V1_0 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b10;
        static constexpr const char* FIELD_STR = "Register Output Driver for ODT";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note ODT_DRIVER field specialization
/// @note valid for rev >= 1.1 specialization
///
template< rev R >
class readerTraits< fields<DDR4, LRDIMM_MODULE>::ODT_DRIVER, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b11;
        static constexpr const char* FIELD_STR = "Register Output Driver for ODT";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note CA_DRIVER field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::CA_DRIVER, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b11;
        static constexpr const char* FIELD_STR = "Register Output Driver for command/address (CA)";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note CS_DRIVER field specialization
/// @note rev 1.0 specialization
///
template<>
class readerTraits< fields<DDR4, LRDIMM_MODULE>::CS_DRIVER, rev::V1_0 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b10;
        static constexpr const char* FIELD_STR = "Register Output Driver for Chip Select (CS)";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note CS_DRIVER field specialization
/// @note valid for rev >= 1.1 specialization
///
template< rev R >
class readerTraits< fields<DDR4, LRDIMM_MODULE>::CS_DRIVER, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b11;

        static constexpr const char* FIELD_STR = "Register Output Driver for Chip Select (CS)";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note YO_Y2_DRIVER field specialization
/// @note rev 1.0 specialization
///
template<>
class readerTraits< fields<DDR4, LRDIMM_MODULE>::YO_Y2_DRIVER, rev::V1_0 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b10;
        static constexpr const char* FIELD_STR = "Register Output Driver for clock (Y0,Y2)";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note YO_Y2_DRIVER field specialization
/// @note valid for rev >= 1.1 specialization
///
template< rev R >
class readerTraits< fields<DDR4, LRDIMM_MODULE>::YO_Y2_DRIVER, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b11;
        static constexpr const char* FIELD_STR = "Register Output Driver for clock (Y0,Y2)";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note Y1_Y3_DRIVER field specialization
/// @note rev 1.0 specialization
///
template<>
class readerTraits< fields<DDR4, LRDIMM_MODULE>::Y1_Y3_DRIVER, rev::V1_0 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b10;
        static constexpr const char* FIELD_STR = "Register Output Driver for clock (Y1,Y3)";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note Y1_Y3_DRIVER field specialization
/// @note valid for rev >= 1.1
///
template< rev R >
class readerTraits< fields<DDR4, LRDIMM_MODULE>::Y1_Y3_DRIVER, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b11;
        static constexpr const char* FIELD_STR = "Register Output Driver for clock (Y1,Y3)";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note BCOM_BODT_BCKE_DRIVER, field specialization
/// @note rev 1.0 specialization
///
template<>
class readerTraits< fields<DDR4, LRDIMM_MODULE>::BCOM_BODT_BCKE_DRIVER, rev::V1_0 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0;
        static constexpr const char* FIELD_STR = "Register Output Driver for data buffer control (BCOM, BODT, BCKE)";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note BCOM_BODT_BCKE_DRIVER, field specialization
/// @note valid for rev >= 1.1 specialization
///
template< rev R >
class readerTraits< fields<DDR4, LRDIMM_MODULE>::BCOM_BODT_BCKE_DRIVER, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 1;
        static constexpr const char* FIELD_STR = "Register Output Driver for data buffer control (BCOM, BODT, BCKE)";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note BCK_DRIVER field specialization
/// @note rev 1.0 specialization
///
template<>
class readerTraits< fields<DDR4, LRDIMM_MODULE>::BCK_DRIVER, rev::V1_0 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0;
        static constexpr const char* FIELD_STR = "Register Output Driver for data buffer control (BCK)";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note BCK_DRIVER field specialization
/// @note valid for rev >= 1.1
///
template< rev R >
class readerTraits< fields<DDR4, LRDIMM_MODULE>::BCK_DRIVER, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 1;
        static constexpr const char* FIELD_STR = "Register Output Driver for data buffer control (BCK)";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note RCD_SLEW_CNTRL field specialization
/// @note rev 1.0 specialization
///
template< >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::RCD_SLEW_CNTRL, rev::V1_0 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0;
        static constexpr const char* FIELD_STR = "RCD output slew rate control";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note RCD_SLEW_CNTRL field specialization
/// @note rev 1.1 specialization
///
template< >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::RCD_SLEW_CNTRL, rev::V1_1 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0;
        static constexpr const char* FIELD_STR = "RCD output slew rate control";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note RCD_SLEW_CNTRL field specialization
/// @note valid for rev >= 1.2
///
template< rev R >
class readerTraits< fields<DDR4, LRDIMM_MODULE>::RCD_SLEW_CNTRL, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 1;
        static constexpr const char* FIELD_STR = "RCD output slew rate control";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DATA_BUFFER_REV field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::DATA_BUFFER_REV, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFF;
        static constexpr const char* FIELD_STR = "Data buffer revision";

        template <typename T>
        using COMPARISON_OP = std::less<T>;
};
///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note VREF_DQ_RANK0 field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::VREF_DQ_RANK0, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b110010;
        static constexpr const char* FIELD_STR = "DRAM VrefDQ for Package Rank 0";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note VREF_DQ_RANK1 field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::VREF_DQ_RANK1, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b110010;
        static constexpr const char* FIELD_STR = "DRAM VrefDQ for Package Rank 1";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note VREF_DQ_RANK2 field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::VREF_DQ_RANK2, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b110010;
        static constexpr const char* FIELD_STR = "DRAM VrefDQ for Package Rank 2";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note VREF_DQ_RANK3 field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::VREF_DQ_RANK3, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b110010;
        static constexpr const char* FIELD_STR = "DRAM VrefDQ for Package Rank 3";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DATA_BUFFER_VREF_DQ field specialization
/// @note rev 1.0 specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::DATA_BUFFER_VREF_DQ, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b110010;
        static constexpr const char* FIELD_STR = "Data Buffer VrefDQ for DRAM Interface";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DB_MDQ_LTE_1866 field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::DB_MDQ_LTE_1866, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b111;
        static constexpr const char* FIELD_STR = "Data Buffer MDQ Drive Strength for data rate <= 1866";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DB_MDQ_LTE_2400 field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::DB_MDQ_LTE_2400, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b111;
        static constexpr const char* FIELD_STR = "Data Buffer MDQ Drive Strength for 1866 < data rate <= 2400";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DB_MDQ_LTE_3200 field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::DB_MDQ_LTE_3200, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b111;
        static constexpr const char* FIELD_STR = "Data Buffer MDQ Drive Strength for 2400 < data rate <=3200";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DB_MDQ_RTT_LTE_1866 field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::DB_MDQ_RTT_LTE_1866, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b111;
        static constexpr const char* FIELD_STR = "Data Buffer MDQ RTT for data rate <= 1866";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DB_MDQ_RTT_LTE_2400 field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::DB_MDQ_RTT_LTE_2400, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b111;
        static constexpr const char* FIELD_STR = "Data Buffer MDQ RTT for 1866 < data rate <= 2400";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DB_MDQ_RTT_LTE_3200 field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::DB_MDQ_RTT_LTE_3200, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b111;
        static constexpr const char* FIELD_STR = "Data Buffer MDQ RTT for 2400 < data rate <=3200";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DRAM_DRIVE_STRENGTH_LTE_1866 field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::DRAM_DRIVE_STRENGTH_LTE_1866, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b01;
        static constexpr const char* FIELD_STR = "DRAM Drive Strength for data rates <= 1866";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DRAM_DRIVE_STRENGTH_LTE_2400 field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::DRAM_DRIVE_STRENGTH_LTE_2400, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b01;
        static constexpr const char* FIELD_STR = "DRAM Drive Strength for 1866 < data rates <= 2400";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DRAM_DRIVE_STRENGTH_LTE_3200 field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::DRAM_DRIVE_STRENGTH_LTE_3200, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b01;
        static constexpr const char* FIELD_STR = "DRAM Drive Strength for 2400 < data rates <= 3200";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DRAM_ODT_RTT_NOM_LTE_1866 field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::DRAM_ODT_RTT_NOM_LTE_1866, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b111;
        static constexpr const char* FIELD_STR = "DRAM ODT RTT_NOM for data rates <= 1866";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DRAM_ODT_RTT_NOM_LTE_2400 field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::DRAM_ODT_RTT_NOM_LTE_2400, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b111;
        static constexpr const char* FIELD_STR = "DRAM ODT RTT_NOM for 1866 < data rates <= 2400";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DRAM_ODT_RTT_NOM_LTE_3200 field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::DRAM_ODT_RTT_NOM_LTE_3200, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b111;
        static constexpr const char* FIELD_STR = "DRAM ODT RTT_NOM for 2400 < data rates <= 3200";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DRAM_ODT_RTT_WR_LTE_1866 field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::DRAM_ODT_RTT_WR_LTE_1866, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b100;
        static constexpr const char* FIELD_STR = "DRAM ODT RTT_WR for data rates <= 1866";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DRAM_ODT_RTT_WR_LTE_2400 field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::DRAM_ODT_RTT_WR_LTE_2400, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b100;
        static constexpr const char* FIELD_STR = "DRAM ODT RTT_WR for 1866 < data rates <= 2400";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DRAM_ODT_RTT_WR_LTE_3200 field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::DRAM_ODT_RTT_WR_LTE_3200, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b100;
        static constexpr const char* FIELD_STR = "DRAM ODT RTT_WR for 2400 < data rates <= 3200";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DRAM_ODT_RTT_PARK_R01_LTE_1866 field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::DRAM_ODT_RTT_PARK_R01_LTE_1866, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b01;
        static constexpr const char* FIELD_STR = "DRAM ODT RTT_PARK, package rank 0, 1 for data rates <= 1866";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DRAM_ODT_RTT_PARK_R01_LTE_2400 field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::DRAM_ODT_RTT_PARK_R01_LTE_2400, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b01;
        static constexpr const char* FIELD_STR = "DRAM ODT RTT_PARK, package rank 0, 1 for 1866 < data rates <= 2400";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DRAM_ODT_RTT_PARK_R01_LTE_3200 field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::DRAM_ODT_RTT_PARK_R01_LTE_3200, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b01;
        static constexpr const char* FIELD_STR = "DRAM ODT RTT_PARK, package rank 0, 1 for 2400 < data rates <= 3200";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DRAM_ODT_RTT_PARK_R23_LTE_1866 field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::DRAM_ODT_RTT_PARK_R23_LTE_1866, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b01;
        static constexpr const char* FIELD_STR = "DRAM ODT RTT_PARK, package rank 2, 3 for data rates <= 1866";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DRAM_ODT_RTT_PARK_R23_LTE_2400 field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::DRAM_ODT_RTT_PARK_R23_LTE_2400, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b01;
        static constexpr const char* FIELD_STR = "DRAM ODT RTT_PARK, package rank 2, 3 for 1866 < data rates <= 2400";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DRAM_ODT_RTT_PARK_R23_LTE_3200 field specialization
/// @note valid for all revisions
///
template< rev R >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::DRAM_ODT_RTT_PARK_R23_LTE_3200, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b01;
        static constexpr const char* FIELD_STR = "DRAM ODT RTT_PARK, package rank 2, 3 for 2400 < data rates <= 3200";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note DRAM_VREF_DQ_RANGE field specialization
/// @note rev 1.0 specialization
///
template< >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::DRAM_VREF_DQ_RANGE, rev::V1_0 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b1111;
        static constexpr const char* FIELD_STR = "VrefDQ range for DRAM interface range";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note DRAM_VREF_DQ_RANGE field specialization
/// @note rev 1.1 specialization
///
template< >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::DRAM_VREF_DQ_RANGE, rev::V1_1 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b1111;
        static constexpr const char* FIELD_STR = "VrefDQ range for DRAM interface range";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note DRAM_VREF_DQ_RANGE field specialization
/// @note rev 1.2+ specialization
///
template< rev R >
class readerTraits< fields<DDR4, LRDIMM_MODULE>::DRAM_VREF_DQ_RANGE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b1111;
        static constexpr const char* FIELD_STR = "VrefDQ range for DRAM interface range";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note DATA_BUFFER_VREF_DQ field specialization
/// @note rev 1.0 specialization
///
template< >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::DATA_BUFFER_VREF_DQ_RANGE, rev::V1_0 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0;
        static constexpr const char* FIELD_STR = "Data Buffer VrefDQ range for DRAM interface range";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note DATA_BUFFER_VREF_DQ field specialization
/// @note rev 1.1 specialization
///
template< >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::DATA_BUFFER_VREF_DQ_RANGE, rev::V1_1 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0;
        static constexpr const char* FIELD_STR = "Data Buffer VrefDQ range for DRAM interface range";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note DATA_BUFFER_VREF_DQ field specialization
/// @note rev 1.2+ specialization
///
template< rev R >
class readerTraits< fields<DDR4, LRDIMM_MODULE>::DATA_BUFFER_VREF_DQ_RANGE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b1;
        static constexpr const char* FIELD_STR = "Data Buffer VrefDQ range for DRAM interface range";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note DATA_BUFFER_DFE field specialization
/// @note rev 1.0 & 1.1 specialization
///
template< >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::DATA_BUFFER_DFE, rev::V1_0 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0;
        static constexpr const char* FIELD_STR = "Data Buffer DFE";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note DATA_BUFFER_DFE field specialization
/// @note rev 1.1 specialization
///
template< >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::DATA_BUFFER_DFE, rev::V1_1 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0;
        static constexpr const char* FIELD_STR = "Data Buffer DFE";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note DATA_BUFFER_DFE field specialization
/// @note rev 1.2+ specialization
///
template< rev R >
class readerTraits< fields<DDR4, LRDIMM_MODULE>::DATA_BUFFER_DFE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0b01;
        static constexpr const char* FIELD_STR = "Data Buffer DFE";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note DATA_BUFFER_GAIN_ADJUST field specialization
/// @note rev 1.0 specialization
///
template< >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::DATA_BUFFER_GAIN_ADJUST, rev::V1_0 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 1;
        static constexpr const char* FIELD_STR = "Data Buffer Gain Adjust";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note DATA_BUFFER_GAIN_ADJUST field specialization
/// @note rev 1.1 specialization
///
template< >
class readerTraits < fields<DDR4, LRDIMM_MODULE>::DATA_BUFFER_GAIN_ADJUST, rev::V1_1 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 1;
        static constexpr const char* FIELD_STR = "Data Buffer Gain Adjust";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note DATA_BUFFER_GAIN_ADJUST field specialization
/// @note rev 1.2+ specialization
///
template< rev R >
class readerTraits< fields<DDR4, LRDIMM_MODULE>::DATA_BUFFER_GAIN_ADJUST, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 1;
        static constexpr const char* FIELD_STR = "Data Buffer Gain Adjust";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

}// spd
}// mss

#endif //_MSS_SPD_TRAITS_DDR4_H_
