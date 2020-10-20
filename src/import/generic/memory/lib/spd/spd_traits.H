/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/spd_traits.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
/// @file spd_traits.H
/// @brief Declaration for assocated traits to reading SPD
///

// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_SPD_READER_TRAITS_H_
#define _MSS_SPD_READER_TRAITS_H_

#include <cstdint>
#include <functional>
#include <generic/memory/lib/spd/spd_field.H>

namespace mss
{
namespace spd
{

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam F holds SPD field info
/// @tparam R the revision of the SPD field
///
template< const field_t<endian::LITTLE>& F, rev R >
class readerTraits;

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note REVISION field specialization
/// @note valid for all revs
///
template< rev R >
class readerTraits < init_fields::REVISION, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 0xFF;
        static constexpr const char* FIELD_STR = "SPD Revision";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @tparam R the revision of the SPD field
/// @note DEVICE_TYPE field specialization
/// @note valid for all revs
///
template< rev R >
class readerTraits< init_fields::DEVICE_TYPE, R >
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
/// @note valid for all revs
///
template< rev R >
class readerTraits < init_fields::BASE_MODULE, R >
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
/// @note valid for all revs
///
template< rev R >
class readerTraits< init_fields::HYBRID, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 1;
        static constexpr const char* FIELD_STR = "Hybrid";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

///
/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note HYBRID_MEDIA field specialization
/// @note valid for all revs
///
template< rev R >
class readerTraits< init_fields::HYBRID_MEDIA, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 3;
        static constexpr const char* FIELD_STR = "Hybrid Media";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

/// @class readerTraits
/// @brief trait structure to hold static SPD information
/// @note REF_RAW_CARD field specialization
/// @note valid for all revs
///
template< rev R >
class readerTraits< init_fields::REF_RAW_CARD, R >
{
    public:

        static constexpr size_t COMPARISON_VAL = 1;
        static constexpr const char* FIELD_STR = "Reference Raw Card";

        template <typename T>
        using COMPARISON_OP = std::less_equal<T>;
};

}// spd
}// mss

#endif //_MSS_SPD_READER_TRAITS_H_
