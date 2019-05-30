/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/ddimm/ddr4/efd_traits_ddr4.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
/// @file efd_traits_ddr4.H
/// @brief Declaration for assocated traits to reading EFD
///

// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _EFD_TRAITS_DDR4_H_
#define _EFD_TRAITS_DDR4_H_


#include <cstdint>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/spd/ddimm/ddr4/efd_fields_ddr4.H>

namespace mss
{

namespace efd
{

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam F holds EFD field info
/// @tparam R the revision of the SPD field
///
template< const field_t<endian::LITTLE>& F, mss::spd::rev R >
class readerTraits;

//////////////////////////////////////////////////////////////////////
/// COMMON TRAITS START HERE
//////////////////////////////////////////////////////////////////////

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note HOST_SPEED_SUPPORTED field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::HOST_SPEED_SUPPORTED, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x7f;
        static constexpr const char* FIELD_STR = "Host Speed Supported";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note MASTER_RANKS_SUPPORTED field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::MASTER_RANKS_SUPPORTED, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x0f;
        static constexpr const char* FIELD_STR = "Master Ranks Supported";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note CHANNELS_SUPPORTED_BYTE0 field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::CHANNELS_SUPPORTED_BYTE0, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xff;
        static constexpr const char* FIELD_STR = "Channels supported byte0";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note CHANNELS_SUPPORTED_BYTE1 field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::CHANNELS_SUPPORTED_BYTE1, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xff;
        static constexpr const char* FIELD_STR = "Channels supported byte1";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note CHANNELS_SUPPORTED_BYTE2 field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::CHANNELS_SUPPORTED_BYTE2, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xff;
        static constexpr const char* FIELD_STR = "Channels supported byte2";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note CHANNELS_SUPPORTED_BYTE3 field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::CHANNELS_SUPPORTED_BYTE3, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xff;
        static constexpr const char* FIELD_STR = "Channels supported byte3";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DIMMS_SUPPORTED field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::DIMMS_SUPPORTED, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x03;
        static constexpr const char* FIELD_STR = "DIMMs supported";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

//////////////////////////////////////////////////////////////////////
/// CUSTOM MICROCHIP SPECIFIC TRAITS START HERE
//////////////////////////////////////////////////////////////////////

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PHY_ODT_IMPEDANCE field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PHY_ODT_IMPEDANCE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x05;
        static constexpr const char* FIELD_STR = "PHY ODT impedance";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PHY_DRIVE_IMPEDANCE_PULL_UP field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PHY_DRIVE_IMPEDANCE_PULL_UP, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x11;
        static constexpr const char* FIELD_STR = "PHY ODT impedance Pull up";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PHY_DRIVE_IMPEDANCE_PULL_DOWN field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PHY_DRIVE_IMPEDANCE_PULL_DOWN, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x11;
        static constexpr const char* FIELD_STR = "PHY ODT impedance Pull up";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PHY_DRIVE_IMPEDANCE field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PHY_DRIVE_IMPEDANCE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "PHY Drive Impedance";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PHY_SLEW_RATE_DQ_DQS field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PHY_SLEW_RATE_DQ_DQS, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "PHY Slew Rate DQ_DQS";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note ATX_IMPEDANCE field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::ATX_IMPEDANCE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x06;
        static constexpr const char* FIELD_STR = "ATX impedance";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note ATX_SLEW_RATE field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::ATX_SLEW_RATE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "ATX Slew rate";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note CK_IMPEDANCE field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::CK_IMPEDANCE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x06;
        static constexpr const char* FIELD_STR = "CK Impedance";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note CK_SLEW_RATE field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::CK_SLEW_RATE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "CK Slew rate";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note ALERT_ODT_IMPEDANCE field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::ALERT_ODT_IMPEDANCE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x06;
        static constexpr const char* FIELD_STR = "Alert ODT Impedance";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DRAM_RTT_NOM field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::DRAM_RTT_NOM, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "DRAM RTT Nom";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DRAM_RTT_NOM_RANK0 field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::DRAM_RTT_NOM_RANK0, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x07;
        static constexpr const char* FIELD_STR = "DRAM RTT Nom rank0";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DRAM_RTT_NOM_RANK1 field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::DRAM_RTT_NOM_RANK1, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x07;
        static constexpr const char* FIELD_STR = "DRAM RTT Nom rank1";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DRAM_RTT_NOM_RANK2 field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::DRAM_RTT_NOM_RANK2, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x07;
        static constexpr const char* FIELD_STR = "DRAM RTT Nom rank2";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DRAM_RTT_NOM_RANK3 field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::DRAM_RTT_NOM_RANK3, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x07;
        static constexpr const char* FIELD_STR = "DRAM RTT Nom rank3";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DRAM_RTT_WR field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::DRAM_RTT_WR, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "DRAM RTT WR";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DRAM_RTT_WR_RANK0 field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::DRAM_RTT_WR_RANK0, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x04;
        static constexpr const char* FIELD_STR = "DRAM RTT WR rank0";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DRAM_RTT_WR_RANK1 field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::DRAM_RTT_WR_RANK1, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x04;
        static constexpr const char* FIELD_STR = "DRAM RTT WR rank1";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DRAM_RTT_WR_RANK2 field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::DRAM_RTT_WR_RANK2, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x04;
        static constexpr const char* FIELD_STR = "DRAM RTT WR rank2";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DRAM_RTT_WR_RANK3 field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::DRAM_RTT_WR_RANK3, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x04;
        static constexpr const char* FIELD_STR = "DRAM RTT WR rank3";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DRAM_RTT_PARK field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::DRAM_RTT_PARK, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "DRAM RTT Park";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DRAM_RTT_PARK_RANK0 field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::DRAM_RTT_PARK_RANK0, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x07;
        static constexpr const char* FIELD_STR = "DRAM RTT Park rank0";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DRAM_RTT_PARK_RANK1 field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::DRAM_RTT_PARK_RANK1, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x07;
        static constexpr const char* FIELD_STR = "DRAM RTT Park rank1";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DRAM_RTT_PARK_RANK2 field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::DRAM_RTT_PARK_RANK2, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x07;
        static constexpr const char* FIELD_STR = "DRAM RTT Park rank2";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DRAM_RTT_PARK_RANK3 field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::DRAM_RTT_PARK_RANK3, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x07;
        static constexpr const char* FIELD_STR = "DRAM RTT Park rank3";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DRAM_DIC field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::DRAM_DIC, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x02;
        static constexpr const char* FIELD_STR = "DRAM DIC";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note WRITE_PREAMBLE field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::WRITE_PREAMBLE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x01;
        static constexpr const char* FIELD_STR = "Write Preamble";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note READ_PREAMBLE field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::READ_PREAMBLE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x01;
        static constexpr const char* FIELD_STR = "Read Preamble";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PHY_EQUALIZATION field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PHY_EQUALIZATION, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x03;
        static constexpr const char* FIELD_STR = "PHY Equalization";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note WR_VREF_DQ_RANGE field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::WR_VREF_DQ_RANGE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x01;
        static constexpr const char* FIELD_STR = "Initial WR VREF DQ Range";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note WR_VREF_DQ_VALUE field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::WR_VREF_DQ_VALUE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x32;
        static constexpr const char* FIELD_STR = "Initial WR VREF DQ Value";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note ODT_WR_MAP_RANK3 field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::ODT_WR_MAP_RANK3, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x0f;
        static constexpr const char* FIELD_STR = "ODT WR Map Rank3";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note ODT_WR_MAP_RANK2 field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::ODT_WR_MAP_RANK2, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x0f;
        static constexpr const char* FIELD_STR = "ODT WR Map Rank2";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note ODT_WR_MAP_RANK1 field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::ODT_WR_MAP_RANK1, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x0f;
        static constexpr const char* FIELD_STR = "ODT WR Map Rank1";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note ODT_WR_MAP_RANK0 field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::ODT_WR_MAP_RANK0, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x0f;
        static constexpr const char* FIELD_STR = "ODT WR Map Rank0";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note ODT_RD_MAP_RANK3 field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::ODT_RD_MAP_RANK3, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x0f;
        static constexpr const char* FIELD_STR = "ODT RD Map Rank3";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note ODT_RD_MAP_RANK2 field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::ODT_RD_MAP_RANK2, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x0f;
        static constexpr const char* FIELD_STR = "ODT RD Map Rank2";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note ODT_RD_MAP_RANK1 field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::ODT_RD_MAP_RANK1, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x0f;
        static constexpr const char* FIELD_STR = "ODT RD Map Rank1";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note ODT_RD_MAP_RANK0 field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::ODT_RD_MAP_RANK0, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x0f;
        static constexpr const char* FIELD_STR = "ODT RD Map Rank0";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note GEARDOWN_DURING_TRAINING field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::GEARDOWN_DURING_TRAINING, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x01;
        static constexpr const char* FIELD_STR = "Geardown during training";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC0_SWA_SETTING field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC0_SWA_SETTING, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x3f;
        static constexpr const char* FIELD_STR = "PMIC0 SWA Setting";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC0_SWA_RANGE field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC0_SWA_RANGE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x01;
        static constexpr const char* FIELD_STR = "PMIC0 SWA Range";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC0_SWB_SETTING field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC0_SWB_SETTING, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x3f;
        static constexpr const char* FIELD_STR = "PMIC0 SWB Setting";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC0_SWB_RANGE field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC0_SWB_RANGE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x01;
        static constexpr const char* FIELD_STR = "PMIC0 SWB Range";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC0_SWC_SETTING field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC0_SWC_SETTING, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x3f;
        static constexpr const char* FIELD_STR = "PMIC0 SWC Setting";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC0_SWC_RANGE field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC0_SWC_RANGE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x01;
        static constexpr const char* FIELD_STR = "PMIC0 SWC Range";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC0_SWD_SETTING field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC0_SWD_SETTING, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x3f;
        static constexpr const char* FIELD_STR = "PMIC0 SWD Setting";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC0_SWD_RANGE field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC0_SWD_RANGE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x01;
        static constexpr const char* FIELD_STR = "PMIC0 SWD Range";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC1_SWA_SETTING field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC1_SWA_SETTING, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x3f;
        static constexpr const char* FIELD_STR = "PMIC1 SWA Setting";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC1_SWA_RANGE field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC1_SWA_RANGE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x01;
        static constexpr const char* FIELD_STR = "PMIC1 SWA Range";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC1_SWB_SETTING field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC1_SWB_SETTING, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x3f;
        static constexpr const char* FIELD_STR = "PMIC1 SWB Setting";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC1_SWB_RANGE field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC1_SWB_RANGE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x01;
        static constexpr const char* FIELD_STR = "PMIC1 SWB Range";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC1_SWC_SETTING field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC1_SWC_SETTING, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x3f;
        static constexpr const char* FIELD_STR = "PMIC1 SWC Setting";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC1_SWC_RANGE field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC1_SWC_RANGE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x01;
        static constexpr const char* FIELD_STR = "PMIC1 SWC Range";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC1_SWD_SETTING field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC1_SWD_SETTING, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x3f;
        static constexpr const char* FIELD_STR = "PMIC1 SWD Setting";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC1_SWD_RANGE field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC1_SWD_RANGE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x01;
        static constexpr const char* FIELD_STR = "PMIC1 SWD Range";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

} // ns efd
} // ns mss
#endif
