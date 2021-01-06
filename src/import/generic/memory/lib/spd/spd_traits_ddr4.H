/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/spd_traits_ddr4.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2021                        */
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

// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_SPD_TRAITS_DDR4_H_
#define _MSS_SPD_TRAITS_DDR4_H_

// Can be brought back if additional traits are needed
#if 0

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
template<>
class readerTraits< fields<DDR4, BASE_CNFG>::HYBRID_MEDIA, rev::V1_0 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x0;
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

        static constexpr size_t COMPARISON_VAL = 0x3;
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

}// spd
}// mss
#endif
#endif //_MSS_SPD_TRAITS_DDR4_H_
