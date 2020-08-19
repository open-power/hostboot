/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/ddimm/ddr4/efd_traits_ddr4.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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

        static constexpr size_t COMPARISON_VAL = 0x0F;
        static constexpr const char* FIELD_STR = "PHY Slew Rate DQ_DQS";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
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

        static constexpr size_t COMPARISON_VAL = 0x0E;
        static constexpr const char* FIELD_STR = "ATX Slew rate";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
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

        static constexpr size_t COMPARISON_VAL = 0x0E;
        static constexpr const char* FIELD_STR = "CK Slew rate";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
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

        static constexpr size_t COMPARISON_VAL = 0x07;
        static constexpr const char* FIELD_STR = "DRAM RTT Nom";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
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

        static constexpr size_t COMPARISON_VAL = 0x04;
        static constexpr const char* FIELD_STR = "DRAM RTT WR";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
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

        static constexpr size_t COMPARISON_VAL = 0x07;
        static constexpr const char* FIELD_STR = "DRAM RTT Park";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
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
/// @note PHY_VREF_PERCENT field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::INIT_PHY_VREF, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x7f;
        static constexpr const char* FIELD_STR = "Host RD VREF DQ";

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
/// @note BIST_CA_LATENCY_MODE field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::BIST_CA_LATENCY_MODE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x08;
        static constexpr const char* FIELD_STR = "BIST Command address Latency Mode";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note BIST_CA_PL_MODE field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::BIST_CA_PL_MODE, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x08;
        static constexpr const char* FIELD_STR = "BIST CA Parity Latency Mode";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DFIMRL_DDRCLK field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::DFIMRL_DDRCLK, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x0f;
        static constexpr const char* FIELD_STR = "DFI Max RD Latency";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note CAC_DLY_A_0 field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::CAC_DLY_A_0, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x1f;
        static constexpr const char* FIELD_STR = "CAC Delay A side Group 0";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note CAC_DLY_A_1 field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::CAC_DLY_A_1, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x1f;
        static constexpr const char* FIELD_STR = "CAC Delay A side Group 1";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note CAC_DLY_A_2 field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::CAC_DLY_A_2, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x1f;
        static constexpr const char* FIELD_STR = "CAC Delay A side Group 2";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note CAC_DLY_A_3 field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::CAC_DLY_A_3, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x1f;
        static constexpr const char* FIELD_STR = "CAC Delay A side Group .";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note CAC_DLY_A_4 field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::CAC_DLY_A_4, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x1f;
        static constexpr const char* FIELD_STR = "CAC Delay A side Group 4";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note CAC_DLY_A_5 field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::CAC_DLY_A_5, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x1f;
        static constexpr const char* FIELD_STR = "CAC Delay A side Group 5";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note CAC_DLY_A_6 field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::CAC_DLY_A_6, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x1f;
        static constexpr const char* FIELD_STR = "CAC Delay A side Group 6";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note CAC_DLY_A_7 field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::CAC_DLY_A_7, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x1f;
        static constexpr const char* FIELD_STR = "CAC Delay A side Group 7";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note CAC_DLY_B_0 field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::CAC_DLY_B_0, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x1f;
        static constexpr const char* FIELD_STR = "CAC Delay B side Group 0";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note CAC_DLY_B_1 field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::CAC_DLY_B_1, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x1f;
        static constexpr const char* FIELD_STR = "CAC Delay B side Group 1";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note CAC_DLY_B_2 field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::CAC_DLY_B_2, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x1f;
        static constexpr const char* FIELD_STR = "CAC Delay B side Group 2";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note CAC_DLY_B_3 field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::CAC_DLY_B_3, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x1f;
        static constexpr const char* FIELD_STR = "CAC Delay B side Group 3";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note CAC_DLY_B_4 field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::CAC_DLY_B_4, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x1f;
        static constexpr const char* FIELD_STR = "CAC Delay B side Group 4";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note CAC_DLY_B_5 field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::CAC_DLY_B_5, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x1f;
        static constexpr const char* FIELD_STR = "CAC Delay B side Group 5";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note CAC_DLY_B_6 field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::CAC_DLY_B_6, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x1f;
        static constexpr const char* FIELD_STR = "CAC Delay B side Group 6";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note CAC_DLY_B_7 field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::CAC_DLY_B_7, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x1f;
        static constexpr const char* FIELD_STR = "CAC Delay B side Group 7";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC0_SWA_OFFSET field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC0_SWA_OFFSET, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x3f;
        static constexpr const char* FIELD_STR = "PMIC0 SWA Offset";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC0_SWA_OFFSET_DIRECTION field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC0_SWA_OFFSET_DIRECTION, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x01;
        static constexpr const char* FIELD_STR = "PMIC0 SWA Offset Direction";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC0_SWB_OFFSET field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC0_SWB_OFFSET, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x3f;
        static constexpr const char* FIELD_STR = "PMIC0 SWB Offset";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC0_SWB_OFFSET_DIRECTION field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC0_SWB_OFFSET_DIRECTION, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x01;
        static constexpr const char* FIELD_STR = "PMIC0 SWB Offset Direction";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC0_SWC_OFFSET field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC0_SWC_OFFSET, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x3f;
        static constexpr const char* FIELD_STR = "PMIC0 SWC Offset";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC0_SWC_OFFSET_DIRECTION field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC0_SWC_OFFSET_DIRECTION, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x01;
        static constexpr const char* FIELD_STR = "PMIC0 SWC Offset Direction";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC0_SWD_OFFSET field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC0_SWD_OFFSET, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x3f;
        static constexpr const char* FIELD_STR = "PMIC0 SWD Offset";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC0_SWD_OFFSET_DIRECTION field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC0_SWD_OFFSET_DIRECTION, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x01;
        static constexpr const char* FIELD_STR = "PMIC0 SWD Offset Direction";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC1_SWA_OFFSET field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC1_SWA_OFFSET, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x3f;
        static constexpr const char* FIELD_STR = "PMIC1 SWA Offset";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC1_SWA_OFFSET_DIRECTION field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC1_SWA_OFFSET_DIRECTION, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x01;
        static constexpr const char* FIELD_STR = "PMIC1 SWA Offset Direction";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC1_SWB_OFFSET field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC1_SWB_OFFSET, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x3f;
        static constexpr const char* FIELD_STR = "PMIC1 SWB Offset";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC1_SWB_OFFSET_DIRECTION field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC1_SWB_OFFSET_DIRECTION, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x01;
        static constexpr const char* FIELD_STR = "PMIC1 SWB Offset Direction";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC1_SWC_OFFSET field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC1_SWC_OFFSET, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x3f;
        static constexpr const char* FIELD_STR = "PMIC1 SWC Offset";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC1_SWC_OFFSET_DIRECTION field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC1_SWC_OFFSET_DIRECTION, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x01;
        static constexpr const char* FIELD_STR = "PMIC1 SWC Offset Direction";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC1_SWD_OFFSET field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC1_SWD_OFFSET, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x3f;
        static constexpr const char* FIELD_STR = "PMIC1 SWD Offset";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC1_SWD_OFFSET_DIRECTION field specialization
/// @note valid for all revs
///
template< mss::spd::rev R >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC1_SWD_OFFSET_DIRECTION, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x01;
        static constexpr const char* FIELD_STR = "PMIC1 SWD Offset Direction";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC0_SWA_CURRENT_WARNING field specialization
/// @note Valid for >= 0.4 revision
///
template< mss::spd::rev R >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC0_SWA_CURRENT_WARNING, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFC;
        static constexpr const char* FIELD_STR = "PMIC0 SWA Current Consumption Warning Threshold";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC0_SWA_CURRENT_WARNING field specialization
/// @note Revision 0.3
///
template<>
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC0_SWA_CURRENT_WARNING, mss::spd::rev::V0_3>
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "PMIC0 SWA Current Consumption Warning Threshold";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC0_SWB_CURRENT_WARNING field specialization
/// @note Valid for >= 0.4 revision
///
template< mss::spd::rev R >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC0_SWB_CURRENT_WARNING, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFC;
        static constexpr const char* FIELD_STR = "PMIC0 SWB Current Consumption Warning Threshold";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC0_SWB_CURRENT_WARNING field specialization
/// @note Revision 0.3
///
template<>
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC0_SWB_CURRENT_WARNING, mss::spd::rev::V0_3>
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "PMIC0 SWB Current Consumption Warning Threshold";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC0_SWC_CURRENT_WARNING field specialization
/// @note Valid for >= 0.4 revision
///
template< mss::spd::rev R >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC0_SWC_CURRENT_WARNING, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFC;
        static constexpr const char* FIELD_STR = "PMIC0 SWC Current Consumption Warning Threshold";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC0_SWC_CURRENT_WARNING field specialization
/// @note Revision 0.3
///
template<>
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC0_SWC_CURRENT_WARNING, mss::spd::rev::V0_3>
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "PMIC0 SWC Current Consumption Warning Threshold";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC0_SWD_CURRENT_WARNING field specialization
/// @note Valid for >= 0.4 revision
///
template< mss::spd::rev R >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC0_SWD_CURRENT_WARNING, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFC;
        static constexpr const char* FIELD_STR = "PMIC0 SWD Current Consumption Warning Threshold";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC0_SWD_CURRENT_WARNING field specialization
/// @note Revision 0.3
///
template<>
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC0_SWD_CURRENT_WARNING, mss::spd::rev::V0_3>
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "PMIC0 SWD Current Consumption Warning Threshold";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC1_SWA_CURRENT_WARNING field specialization
/// @note Valid for >= 0.4 revision
///
template< mss::spd::rev R >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC1_SWA_CURRENT_WARNING, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFC;
        static constexpr const char* FIELD_STR = "PMIC1 SWA Current Consumption Warning Threshold";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC1_SWA_CURRENT_WARNING field specialization
/// @note Revision 0.3
///
template<>
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC1_SWA_CURRENT_WARNING, mss::spd::rev::V0_3>
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "PMIC1 SWA Current Consumption Warning Threshold";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC1_SWB_CURRENT_WARNING field specialization
/// @note Valid for >= 0.4 revision
///
template< mss::spd::rev R >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC1_SWB_CURRENT_WARNING, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFC;
        static constexpr const char* FIELD_STR = "PMIC1 SWB Current Consumption Warning Threshold";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC1_SWB_CURRENT_WARNING field specialization
/// @note Revision 0.3
///
template<>
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC1_SWB_CURRENT_WARNING, mss::spd::rev::V0_3>
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "PMIC1 SWB Current Consumption Warning Threshold";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC1_SWC_CURRENT_WARNING field specialization
/// @note Valid for >= 0.4 revision
///
template< mss::spd::rev R >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC1_SWC_CURRENT_WARNING, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFC;
        static constexpr const char* FIELD_STR = "PMIC1 SWC Current Consumption Warning Threshold";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC1_SWC_CURRENT_WARNING field specialization
/// @note Revision 0.3
///
template<>
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC1_SWC_CURRENT_WARNING, mss::spd::rev::V0_3>
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "PMIC1 SWC Current Consumption Warning Threshold";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC1_SWD_CURRENT_WARNING field specialization
/// @note Valid for >= 0.4 revision
///
template< mss::spd::rev R >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC1_SWD_CURRENT_WARNING, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFC;
        static constexpr const char* FIELD_STR = "PMIC1 SWD Current Consumption Warning Threshold";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note PMIC1_SWD_CURRENT_WARNING field specialization
/// @note Revision 0.3
///
template<>
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::PMIC1_SWD_CURRENT_WARNING, mss::spd::rev::V0_3>
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "PMIC1 SWD Current Consumption Warning Threshold";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note RCD_DIC_0 field specialization
/// @note rev 0.3 specialization
///
template< >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::RCD_DIC_0, mss::spd::rev::V0_3 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "RCD driver impedance control Byte0";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note RCD_DIC_0 field specialization
/// @note valid for rev >= 0.4
///
template< mss::spd::rev R >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::RCD_DIC_0, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFF;
        static constexpr const char* FIELD_STR = "RCD driver impedance control Byte0";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note RCD_DIC_1 field specialization
/// @note rev 0.3 specialization
///
template< >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::RCD_DIC_1, mss::spd::rev::V0_3 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "RCD driver impedance control Byte1";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note RCD_DIC_1 field specialization
/// @note valid for rev >= 0.4
///
template< mss::spd::rev R >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::RCD_DIC_1, R >
{
    public:

        // Bits 7-4 in this byte are reserved
        static constexpr size_t COMPARISON_VAL = 0x0F;
        static constexpr const char* FIELD_STR = "RCD driver impedance control Byte1";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note RCD_VOLTAGE_CTRL_0 field specialization
/// @note rev 0.3 specialization
///
template< >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::RCD_VOLTAGE_CTRL_0, mss::spd::rev::V0_3 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "RCD voltage control Byte0";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note RCD_VOLTAGE_CTRL_0 field specialization
/// @note valid for rev >= 0.4
///
template< mss::spd::rev R >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::RCD_VOLTAGE_CTRL_0, R >
{
    public:

        // Bits 7-4 in this byte are reserved
        static constexpr size_t COMPARISON_VAL = 0x0F;
        static constexpr const char* FIELD_STR = "RCD voltage control Byte0";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note RCD_VOLTAGE_CTRL_1 field specialization
/// @note rev 0.3 specialization
///
template< >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::RCD_VOLTAGE_CTRL_1, mss::spd::rev::V0_3 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "RCD voltage control Byte1";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note RCD_VOLTAGE_CTRL_1 field specialization
/// @note valid for rev >= 0.4
///
template< mss::spd::rev R >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::RCD_VOLTAGE_CTRL_1, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFF;
        static constexpr const char* FIELD_STR = "RCD voltage control Byte1";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note RCD_IBT field specialization
/// @note rev 0.3 specialization
///
template< >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::RCD_IBT, mss::spd::rev::V0_3 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "RCD Input Bus Termination";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note RCD_IBT field specialization
/// @note valid for rev >= 0.4
///
template< mss::spd::rev R >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::RCD_IBT, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFF;
        static constexpr const char* FIELD_STR = "RCD Input Bus Termination";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note RCD_DB_DIC field specialization
/// @note rev 0.3 specialization
///
template< >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::RCD_DB_DIC, mss::spd::rev::V0_3 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "RCD data buffer driver impedance control";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note RCD_DB_DIC field specialization
/// @note valid for rev >= 0.4
///
template< mss::spd::rev R >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::RCD_DB_DIC, R >
{
    public:

        // Bits 7-3 and 1 in this byte are reserved
        static constexpr size_t COMPARISON_VAL = 0x05;
        static constexpr const char* FIELD_STR = "RCD data buffer driver impedance control";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note RCD_SLEW_RATE_CTRL_0 field specialization
/// @note rev 0.3 specialization
///
template< >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::RCD_SLEW_RATE_CTRL_0, mss::spd::rev::V0_3 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "RCD slew rate control Byte 0";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note RCD_SLEW_RATE_CTRL_0 field specialization
/// @note valid for rev >= 0.4
///
template< mss::spd::rev R >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::RCD_SLEW_RATE_CTRL_0, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFF;
        static constexpr const char* FIELD_STR = "RCD slew rate control Byte 0";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note RCD_SLEW_RATE_CTRL_1 field specialization
/// @note rev 0.3 specialization
///
template< >
class readerTraits
    < fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::RCD_SLEW_RATE_CTRL_1, mss::spd::rev::V0_3 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x00;
        static constexpr const char* FIELD_STR = "RCD slew rate control Byte 1";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note RCD_SLEW_RATE_CTRL_1 field specialization
/// @note valid for rev >= 0.4
///
template< mss::spd::rev R >
class readerTraits< fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::RCD_SLEW_RATE_CTRL_1, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFF;
        static constexpr const char* FIELD_STR = "RCD slew rate control Byte 1";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note F1RC1X field specialization
/// @note valid for rev = 0.3
///
template< >
class readerTraits< fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::F1RC1X, mss::spd::rev::V0_3 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0;
        static constexpr const char* FIELD_STR = "QxCSn_n Output Delay Control Word (F1RC1X)";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note F1RC1X field specialization
/// @note valid for rev >= 0.4
///
template< mss::spd::rev R >
class readerTraits< fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::F1RC1X, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x9F;
        static constexpr const char* FIELD_STR = "QxCSn_n Output Delay Control Word (F1RC1X)";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note F1RC3X field specialization
/// @note valid for rev = 0.3
///
template< >
class readerTraits< fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::F1RC3X, mss::spd::rev::V0_3 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0;
        static constexpr const char* FIELD_STR = "QxCKEn Output Delay Control Word (F1RC3X)";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note F1RC3X field specialization
/// @note valid for rev >= 0.4
///
template< mss::spd::rev R >
class readerTraits< fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::F1RC3X, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x9F;
        static constexpr const char* FIELD_STR = "QxCKEn Output Delay Control Word (F1RC3X)";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note F1RC4X field specialization
/// @note valid for rev = 0.3
///
template< >
class readerTraits< fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::F1RC4X, mss::spd::rev::V0_3 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0;
        static constexpr const char* FIELD_STR = "QxODTn Output Delay Control Word (F1RC4X)";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note F1RC4X field specialization
/// @note valid for rev >= 0.4
///
template< mss::spd::rev R >
class readerTraits< fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::F1RC4X, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x9F;
        static constexpr const char* FIELD_STR = "QxODTn Output Delay Control Word (F1RC4X)";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note F1RC5X field specialization
/// @note valid for rev = 0.3
///
template< >
class readerTraits< fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::F1RC5X, mss::spd::rev::V0_3 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0;
        static constexpr const char* FIELD_STR = "QxCA Output Delay Control Word (F1RC5X)";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note F1RC5X field specialization
/// @note valid for rev >= 0.4
///
template< mss::spd::rev R >
class readerTraits< fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::F1RC5X, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0x9F;
        static constexpr const char* FIELD_STR = "QxCA Output Delay Control Word (F1RC5X)";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note F1RC6X field specialization
/// @note valid for rev = 0.3
///
template< >
class readerTraits< fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::F1RC6X, mss::spd::rev::V0_3 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0;
        static constexpr const char* FIELD_STR = "Y1/Y3 Output Delay Control Word (F1RC6X)";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note F1RC6X field specialization
/// @note valid for rev >= 0.4
///
template< mss::spd::rev R >
class readerTraits< fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::F1RC6X, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xBF;
        static constexpr const char* FIELD_STR = "Y1/Y3 Output Delay Control Word (F1RC6X)";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note F1RC7X field specialization
/// @note valid for rev = 0.3
///
template< >
class readerTraits< fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::F1RC7X, mss::spd::rev::V0_3 >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0;
        static constexpr const char* FIELD_STR = "Y0/Y2 Output Delay Control Word (F1RC7X)";

        template <typename T>
        using COMPARISON_OP = std::equal_to<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note F1RC7X field specialization
/// @note valid for rev >= 0.4
///
template< mss::spd::rev R >
class readerTraits< fields< mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>::F1RC7X, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xBF;
        static constexpr const char* FIELD_STR = "Y0/Y2 Output Delay Control Word (F1RC7X)";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

} // ns efd
} // ns mss
#endif
