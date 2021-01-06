/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/common/ddr4/spd_decoder_ddr4.H $ */
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

///
/// @file spd_decoder.H
/// @brief SPD decoder declarations
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_SPD_DECODER_H_
#define _MSS_SPD_DECODER_H_

// std lib
#include <cstdint>
#include <map>
#include <memory>

// fapi2
#include <fapi2.H>

// mss lib
#include <generic/memory/lib/spd/common/rcw_settings.H>
#include <generic/memory/lib/utils/mss_generic_check.H>
#include <generic/memory/lib/spd/spd_checker.H>
#include <generic/memory/lib/utils/mss_buffer_utils.H>

namespace mss
{

namespace spd
{

///
/// @brief sdram package types. Follows encodings in SPD
///
enum sdram_package_type : uint8_t
{
    // Package Type
    MONOLITHIC = 0,           ///< Monolithic DRAM device
    NON_MONOLITHIC = 1,       ///< NonMonolithic DRAM device (3DS, Dual/Quad Die, etc)

    // Signal loading
    UNSPECIFIED = MONOLITHIC, ///< Not specified
    MULTI_LOAD_STACK = 1,     ///< Multi laod stack
    SINGLE_LOAD_STACK = 2,    ///< Single load stack (3DS)
};

///
/// @brief module type DDR4 encoding
///
enum module_type
{
    NOT_HYBRID = 0,
    HYBRID = 1,
    NVDIMM_HYBRID = 1,
    MDS_HYBRID = 3
};

///
/// @brief enum for voltage information. Encoding comes from SPD
///
enum nominal_voltage : uint8_t
{
    NOT_OPERABLE = 0, ///< Not operable at 1.2V
    OPERABLE = 1,     ///< Operable at 1.2V

    NOT_ENDURANT = 0, ///< Not endurant at 1.2V
    ENDURANT = 1      ///< Endurant at 1.2 V
};

///
/// @brief Connector to SDRAM Bit Mapping field positions
/// @note Bytes 60 - 77 . Mapping to Package rank map and
/// nibble map starting and length positions for SPD field extraction.
///
enum connector_to_sdram
{
    PACKAGE_RANK_MAP_START = 0,
    PACKAGE_RANK_MAP_LEN = 2,

    NIBBLE_MAP_START = 2,
    NIBBLE_MAP_LEN = 6,
};

///
/// @brief Connector to SDRAM Bit Mapping fields
/// @note template selector for traits and function API
///
enum connector_field
{
    NIBBLE_MAP,
    PKG_RANK_MAP,
};

///
/// @brief Connector to SDRAM Bit Mapping connector bits
/// @note template selYYector for traits and function API.
/// DQ0_31 represnts DQ nibbles for DQ bits 0 - 31.
/// DQ32_63 represnts DQ nibbles for DQ bits 32 - 63.
/// CB0_7 represents DQ nibbles for DQ bits 64 - 71.
///
enum connector_bits
{
    DQ0_31,
    DQ32_63,
    CB0_7,
};

}// spd
}// mss

#endif //_MSS_SPD_DECODER_H_
