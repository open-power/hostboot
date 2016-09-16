/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/spd/common/spd_decoder.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
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
#include <lib/spd/common/dimm_module_decoder.H>
#include <lib/spd/common/raw_cards.H>
#include <lib/spd/rdimm/rdimm_decoder.H>
#include <lib/spd/lrdimm/lrdimm_decoder.H>
#include <lib/utils/c_str.H>

namespace mss
{
namespace spd
{

enum sdram_package_type : uint8_t
{
    // Signal loading
    MONOLITHIC = 0,
    NON_MONOLITHIC = 1,

    // Package Type
    UNSPECIFIED = MONOLITHIC,
    MULTI_LOAD_STACK = 1,
    SINGLE_LOAD_STACK = 2,
};

enum nominal_voltage : uint8_t
{
    NOT_OPERABLE = 0,
    OPERABLE = 1,

    NOT_ENDURANT = 0,
    ENDURANT = 1
};

enum factory_byte_extract
{
    // Byte 1
    ENCODING_LEVEL_START = 0,
    ENCODING_LEVEL_LEN = 4,

    ADDITIONS_LEVEL_START = 4,
    ADDITIONS_LEVEL_LEN = 4,

    // Byte 3
    BASE_MODULE_START = 4,
    BASE_MODULE_LEN = 4,
};

///
/// @brief Helper function to extract byte information
/// @tparam I Byte index
/// @tparam S Start bit
/// @tparam L Bit length
/// @param[in] i_target the dimm target
/// @param[in] i_spd_data the SPD data
/// @return extracted byte (right aligned)
///
template<size_t I, uint8_t S, uint8_t L>
inline uint8_t extract_spd_field(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                 const std::vector<uint8_t>& i_spd_data)
{
    //TODO - RTC:159477
    FAPI_INF("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             I,
             i_spd_data[I]);

    fapi2::buffer<uint8_t> l_buffer(i_spd_data[I]);

    // Extracting desired bits
    uint8_t l_field_bits = 0;
    l_buffer.extractToRight<S, L>(l_field_bits);

    return l_field_bits;
}

///
/// @brief Helper function to extract byte information
/// @tparam F the SPD field to extract
/// @param[in] i_target the dimm target
/// @param[in] i_spd_data the SPD data
/// @return extracted byte (right aligned)
///
template< const field_t& F >
inline uint8_t extract_spd_field(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                 const std::vector<uint8_t>& i_spd_data)
{
    FAPI_INF("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             F.iv_byte,
             i_spd_data[F.iv_byte]);

    fapi2::buffer<uint8_t> l_buffer(i_spd_data[F.iv_byte]);

    // Extracting desired bits
    uint8_t l_field_bits = 0;
    l_buffer.extractToRight<F.iv_start, F.iv_length>(l_field_bits);

    return l_field_bits;
}

///
/// @brief Helper function to extract byte information
/// @param[in] i_target the dimm target
/// @param[in] i_field the SPD field
/// @param[in] i_spd_data the SPD data
/// @return extracted byte (right aligned)
///
inline uint8_t extract_spd_field(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                 const field_t& i_field,
                                 const std::vector<uint8_t>& i_spd_data)
{
    FAPI_INF("%s SPD data at Byte %d: 0x%llX.",
             mss::c_str(i_target),
             i_field.iv_byte,
             i_spd_data[i_field.iv_byte]);

    fapi2::buffer<uint8_t> l_buffer(i_spd_data[i_field.iv_byte]);

    // Extracting desired bits
    uint8_t l_field_bits = 0;
    l_buffer.extractToRight( l_field_bits, i_field.iv_start, i_field.iv_length );

    return l_field_bits;
}

///
/// @class decoder
/// @brief Base SPD DRAM decoder
///
class decoder
{
    protected:
        enum
        {
            // Byte 0
            BYTES_USED_START = 4,
            BYTES_USED_LEN = 4,

            BYTES_TOTAL_START = 1,
            BYTES_TOTAL_LEN = 3,

            // Byte 1 - see factory byte enum
            // Byte 2 - Entire byte used

            // Byte 3
            HYBRID_MEDIA_START = 1,
            HYBRID_MEDIA_LEN = 3,

            HYBRID_START = 0,
            HYBRID_LEN = 1,

            // Byte 4
            SDRAM_CAPACITY_START = 4,
            SDRAM_CAPACITY_LEN = 4,

            SDRAM_BANKS_START = 2,
            SDRAM_BANKS_LEN = 2,

            BANK_GROUP_START = 0,
            BANK_GROUP_LEN = 2,

            // Byte 5
            COL_ADDRESS_START = 5,
            COL_ADDRESS_LEN = 3,

            ROW_ADDRESS_START = 2,
            ROW_ADDRESS_LEN = 3,

            ADDRESS_RESERVED_START = 0,
            ADDRESS_RESERVED_LEN = 2,

            // Byte 6
            PRIM_SIGNAL_LOAD_START = 6,
            PRIM_SIGNAL_LOAD_LEN = 2,

            PACKAGE_RESERVE_START = 4,
            PACKAGE_RESERVE_LEN = 2,

            PRIM_DIE_COUNT_START = 1,
            PRIM_DIE_COUNT_LEN = 3,

            PRIM_PACKAGE_TYPE_START = 0,
            PRIM_PACKAGE_TYPE_LEN = 1,

            // Byte 7
            MAC_START = 4,
            MAC_LEN = 4,

            TMAW_START = 2,
            TMAW_LEN = 2,

            OPT_FEAT_RESERVED_START = 0,
            OPT_FEAT_RESERVED_LEN = 2,

            // Byte 8 reserved

            // Byte 9
            PPR_RESERVED_START = 3,
            PPR_RESERVED_LEN = 5,

            SOFT_PPR_START = 2,
            SOFT_PPR_LEN = 1,

            PPR_START = 0,
            PPR_LEN = 2,

            // Byte 10
            SEC_SIGNAL_LOAD_START = 5,
            SEC_SIGNAL_LOAD_LEN = 2,

            DENSITY_RATIO_START = 4,
            DENSITY_RATIO_LEN = 2,

            SEC_DIE_COUNT_START = 1,
            SEC_DIE_COUNT_LEN = 3,

            SEC_PACKAGE_TYPE_START = 0,
            SEC_PACKAGE_TYPE_LEN = 1,

            // Byte 11
            OPERABLE_START = 7,
            OPERABLE_LEN = 1,

            ENDURANT_START = 6,
            ENDURANT_LEN = 1,

            NOM_VOLT_START = 0,
            NOM_VOLT_LEN = 6,

            // Byte 12
            SDRAM_WIDTH_START = 5,
            SDRAM_WIDTH_LEN = 3,

            PACKAGE_RANKS_START = 2,
            PACKAGE_RANKS_LEN = 3,

            RANK_MIX_START = 1,
            RANK_MIX_LEN = 1,

            MODULE_ORG_RESERVED_START = 0,
            MODULE_ORG_RESERVED_LEN = 1,

            // Byte 13
            BUS_WIDTH_START = 5,
            BUS_WIDTH_LEN = 3,

            BUS_EXT_WIDTH_START = 3,
            BUS_EXT_WIDTH_LEN = 2,

            BUS_WIDTH_RESERVED_START = 0,
            BUS_WIDTH_RESERVED_LEN = 3,

            // Byte 14
            THERM_SENSOR_RESERV_START = 1,
            THERM_SENSOR_RESERV_LEN = 7,

            THERM_SENSOR_START = 0,
            THERM_SENSOR_LEN = 1,

            // Byte 15
            EXT_MOD_TYPE_START = 5,
            EXT_MOD_TYPE_LEN = 3,

            EXT_MOD_TYPE_RESERV_START = 0,
            EXT_MOD_TYPE_RESERV_LEN = 4,

            // Byte 16 - reserved

            // Byte 17
            FINE_TIMEBASE_START = 6,
            FINE_TIMEBASE_LEN = 2,

            MED_TIMEBASE_START = 4,
            MED_TIMEBASE_LEN = 2,

            TIMEBASE_RESERV_START = 0,
            TIMEBASE_RESERV_LEN = 4,

            // Byte 18 -  Entire byte used
            // Byte 19 -  Entire byte used

            // Byte 20-23
            CAS_BYTE_1_START = 56,
            CAS_BYTE_1_LEN = 8,
            CAS_BYTE_2_START = 48,
            CAS_BYTE_2_LEN = 8,
            CAS_BYTE_3_START = 40,
            CAS_BYTE_3_LEN = 8,
            CAS_BYTE_4_START = 32,
            CAS_BYTE_4_LEN = 8,

            // Byte 24 -  Entire byte used
            // Byte 25 -  Entire byte used
            // Byte 26 -  Entire byte used

            // Byte 27
            TRASMIN_MSN_START = 4, // MSN = most significant nibble
            TRASMIN_MSN_LEN = 4,

            TRCMIN_MSN_START = 0, // MSN = most significant nibble
            TRCMIN_MSN_LEN = 4,

            // Byte 28
            TRASMIN_LSB_START = 0, // LSB = least significant byte
            TRASMIN_LSB_LEN = 8,

            // Byte 29
            TRCMIN_LSB_START = 0, // LSB = least significant byte
            TRCMIN_LSB_LEN = 8,

            // Byte 30
            TRFC1MIN_LSB_START = 0,
            TRFC1MIN_LSB_LEN = 8,

            // Byte 31
            TRFC1MIN_MSB_START = 0,
            TRFC1MIN_MSB_LEN = 8,

            // Byte 32
            TRFC2MIN_LSB_START = 0,
            TRFC2MIN_LSB_LEN = 8,

            // Byte 33
            TRFC2MIN_MSB_START = 0,
            TRFC2MIN_MSB_LEN = 8,

            // Byte 34 & Byte 35
            TRFC4MIN_LSB_START = 0,
            TRFC4MIN_LSB_LEN = 8,

            TRFC4MIN_MSB_START = 0,
            TRFC4MIN_MSB_LEN = 8,

            // Byte 36
            TFAWMIN_MSN_START = 4,
            TFAWMIN_MSN_LEN = 4,

            // Byte 37
            TFAWMIN_LSB_START = 0,
            TFAWMIN_LSB_LEN = 8,

            // Byte 38 - Entire byte used
            // Byte 39 - Entire byte used
            // Byte 40 - Entire byte used

            // Byte 41
            TWRMIN_MSN_START = 4, // MSN = most significant nibble
            TWRMIN_MSN_LEN = 4,

            // Byte 42
            TWRMIN_LSB_START = 0, // LSB = least significant nibble
            TWRMIN_LSB_LEN = 8,

            // Byte 43
            TWTRMIN_L_MSN_START = 0, // MSN = most significant nibble
            TWTRMIN_L_MSN_LEN = 4,

            TWTRMIN_S_MSN_START = 4, // MSN = most significant nibble
            TWTRMIN_S_MSN_LEN = 4,

            // Byte 44
            TWTRMIN_S_LSB_START = 0, // LSB = least significant byte
            TWTRMIN_S_LSB_LEN = 8,

            // Byte 45
            TWTRMIN_L_LSB_START = 0,
            TWTRMIN_L_LSB_LEN = 8,

            // Bytes 46 - 59 - reserved

            // Bytes 60 - 77 - Connector to SDRAM Bit Mapping ??

            // Bytes 78 - 116 - reserved

            // Bytes 117 - 125 : Entire byte used

            // Byte 126
            CRC_LSB_START = 0,
            CRC_LSB_LEN = 8,

            // Byte 127
            CRC_MSB_START = 0,
            CRC_MSB_LEN = 8,

            // Byte 320
            // Skip SPD most signigicant bit, so our 0
            MOD_MFG_LSB_START = 0,
            MOD_MFG_LSB_LEN = 8,

            // Byte 321
            MOD_MFG_MSB_START = 0,
            MOD_MFG_MSB_LEN = 8,

        };

    public:
        std::shared_ptr<dimm_module_decoder> iv_module_decoder;
        std::vector<uint8_t> iv_spd_data;
        rcd01::raw_card_t iv_raw_card;

        // Default constructor deleted
        decoder() = delete;

        ///
        /// @brief ctor
        /// @param[in] i_target dimm target
        /// @param[in] i_spd_data SPD data vector
        /// @param[in] i_module_decoder shared_ptr to dimm module decoder
        /// @param[in] i_raw_card raw pointer to rcd data
        ///
        decoder(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                const std::vector<uint8_t>& i_spd_data,
                const std::shared_ptr<dimm_module_decoder>& i_module_decoder,
                const rcd01::raw_card_t& i_raw_card);

        ///
        /// @brief Default dtor
        ///
        virtual ~decoder() = default;

        /////////////////////////
        // Member Methods
        /////////////////////////

        ///
        /// @brief Decodes number of used SPD bytes
        /// @param[in] i_target dimm target
        /// @param[out] o_value number of SPD bytes used
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note Decodes SPD Byte 0 (3~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 14
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode number_of_used_bytes(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint16_t& o_value);

        ///
        /// @brief Decodes total number of SPD bytes
        /// @param[in] i_target dimm target
        /// @param[out] o_value number of total SPD bytes
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note Decodes SPD Byte 0 (bits 6~4)
        /// @note Item JC-45-2220.01x
        /// @note Page 14
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode number_of_total_bytes(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint16_t& o_value);

        ///
        /// @brief Decodes hybrid media field from SPD
        /// @param[in] i_target
        /// @param[out] o_value
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note Decodes SPD Byte 3 (bits 6~4)
        /// @note Item JC-45-2220.01x
        /// @note Page 17
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode hybrid_media(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                               uint8_t& o_value);

        ///
        /// @brief Decodes hybrid field from SPD
        /// @param[in] i_target
        /// @param[out] o_value
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note Decodes SPD Byte 3 (bit 7)
        /// @note Item JC-45-2220.01x
        /// @note Page 17
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode hybrid(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                         uint8_t& o_value);

        ///
        /// @brief Decodes SDRAM density from SPD
        /// @param[in] i_target dimm target
        /// @param[out] o_value SDRAM density in GBs
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 4 (bits 3~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 18
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode sdram_density(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                                uint8_t& o_value);

        ///
        /// @brief Decodes number of SDRAM banks bits from SPD
        /// @param[in] i_target dimm target
        /// @param[out] o_value Number of SDRAM bank bits
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 4 (bits 5~4)
        /// @note Item JC-45-2220.01x
        /// @note Page 18
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode bank_bits(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                            uint8_t& o_value);

        ///
        /// @brief Decodes number of SDRAM bank groups bits from SPD
        /// @param[in] i_target dimm target
        /// @param[out] o_value Number of SDRAM bank groups bits
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 4 (bits 7~6)
        /// @note Item JC-45-2220.01x
        /// @note Page 18
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode bank_group_bits(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value);

        ///
        /// @brief Decodes number of SDRAM column address bits
        /// @param[in] i_target dimm target
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 5 (bits 2~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 18
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode column_address_bits(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value);

        ///
        /// @brief Decodes number of SDRAM row address bits
        /// @param[in] i_target dimm target
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 5 (bits 5~3)
        /// @note Item JC-45-2220.01x
        /// @note Page 18
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode row_address_bits(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value);

        ///
        /// @brief Decodes Primary SDRAM signal loading
        /// @param[in] i_target dimm target
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 6 (bits 1~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 19
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode prim_sdram_signal_loading(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value);

        ///
        /// @brief Decodes Primary SDRAM die count
        /// @param[in] i_target dimm target
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 6 (bits 6~4)
        /// @note Item JC-45-2220.01x
        /// @note Page 19
        /// @note DDR4 SPD Document Release 3
        ///
        virtual  fapi2::ReturnCode prim_sdram_die_count(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value);

        ///
        /// @brief Decodes Primary SDRAM package type
        /// @param[in] i_target dimm target
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 6 (bit 7)
        /// @note Item JC-45-2220.01x
        /// @note Page 19
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode prim_sdram_package_type(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value);

        ///
        /// @brief Decode SDRAM Maximum activate count
        /// @param[in] i_target dimm target
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 7 (bits 3~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 20
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode maximum_activate_count(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint32_t& o_value);

        ///
        /// @brief Decode SDRAM Maximum activate window (multiplier), tREFI uknown at this point
        /// @param[in] i_target
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 7 (bits 3~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 20
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode maximum_activate_window_multiplier(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint32_t& o_value);

        ///
        /// @brief Decode Post package repair (PPR)
        /// @param[in] i_target dimm target
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 9 (bits 7~6)
        /// @note Item JC-45-2220.01x
        /// @note Page 21
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode post_package_repair(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value);

        ///
        /// @brief Decode Soft post package repair (soft PPR)
        /// @param[in] i_target dimm target
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 9 (bit 5)
        /// @note Item JC-45-2220.01x
        /// @note Page 21
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode soft_post_package_repair(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value);

        ///
        /// @brief Decodes Secondary SDRAM signal loading
        /// @param[in] i_target dimm target
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 10 (bits 1~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 22
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode sec_sdram_signal_loading(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value);

        ///
        /// @brief Decodes Secondary DRAM Density Ratio
        /// @param[in] i_target dimm target
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 10 (bits 3~2)
        /// @note Item JC-45-2220.01x
        /// @note Page 22
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode sec_dram_density_ratio(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value);

        ///
        /// @brief Decodes Secondary SDRAM die count
        /// @param[in] i_target dimm target
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 10 (bits 6~4)
        /// @note Item JC-45-2220.01x
        /// @note Page 22
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode sec_sdram_die_count(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value);

        ///
        /// @brief Decodes Secondary SDRAM package type
        /// @param[in] i_target dimm target
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 10 (bit 7)
        /// @note Item JC-45-2220.01x
        /// @note Page 22
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode sec_sdram_package_type(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value);

        ///
        /// @brief Decode Module Nominal Voltage, VDD
        /// @param[in] i_target dimm target
        /// @param[out] o_value enum representing if 1.2V is operable
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 11 (bit 0)
        /// @note Item JC-45-2220.01x
        /// @note Page 23
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode operable_nominal_voltage(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value);

        ///
        /// @brief Decode Module Nominal Voltage, VDD
        /// @param[in] i_target dimm target
        /// @param[out] o_value enum representing if 1.2V is endurant
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 11 (bit 1)
        /// @note Item JC-45-2220.01x
        /// @note Page 23
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode endurant_nominal_voltage(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value);
        ///
        /// @brief Decodes SDRAM device width
        /// @param[in] i_target dimm target
        /// @param[out] o_value device width in bits
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 12 (bits 2~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 23
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode device_width(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                               uint8_t& o_value);

        ///
        /// @brief Decodes number of package ranks per DIMM
        /// @param[in] i_target dimm target
        /// @param[out] o_value number of package ranks per DIMM
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 12 (bits 5~3)
        /// @note Item JC-45-2220.01x
        /// @note Page 23
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode num_package_ranks_per_dimm(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value);

        ///
        /// @brief Decodes Rank Mix
        /// @param[in] i_target dimm target
        /// @param[out] o_value rank mix value from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 12 (bit 6)
        /// @note Item JC-45-2220.01x
        /// @note Page 23
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode rank_mix(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                           uint8_t& o_value);

        ///
        /// @brief Decodes primary bus width
        /// @param[in] i_target dimm target
        /// @param[out] o_value primary bus width in bits
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 13 (bits 2~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 27
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode prim_bus_width(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value);

        ///
        /// @brief Decodes bus width extension
        /// @param[in] i_target dimm target
        /// @param[out] o_value bus width extension in bits
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 13 (bits 4~3)
        /// @note Item JC-45-2220.01x
        /// @note Page 27
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode bus_width_extension(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value);

        ///
        /// @brief Decode Module Thermal Sensor
        /// @param[in] i_target dimm target
        /// @param[out] o_value thermal sensor value from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 14 (bit 7)
        /// @note Item JC-45-2220.01x
        /// @note Page 28
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode thermal_sensor(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value);

        ///
        /// @brief Decode Extended Base Module Type
        /// @param[in] i_target dimm target
        /// @param[out] o_value extended base module type value from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 15 (bits 3~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 28
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode extended_base_module_type(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value);

        ///
        /// @brief Decode Fine Timebase
        /// @param[in] i_target dimm target
        /// @param[out] o_value fine_timebase from SPD in picoseconds
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 17 (bits 1~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 29
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode fine_timebase(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                                int64_t& o_value);

        ///
        /// @brief Decode Medium Timebase
        /// @param[in] i_target dimm target
        /// @param[out] o_value fine_timebase from SPD in picoseconds
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 17 (bits 3~2)
        /// @note Item JC-45-2220.01x
        /// @note Page 29
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode medium_timebase(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);

        ///
        ///
        /// @brief Decodes SDRAM Minimum Cycle Time in MTB
        /// @param[in] i_target dimm target
        /// @param[out] o_value tCKmin in MTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 18
        /// @note Item JC-45-2220.01x
        /// @note Page 31-32
        /// @note DDR4 SPD Document Release 3
        /// @warning If tCKmin cannot be divided evenly by the MTB,
        /// this byte must be rounded up to the next larger
        /// integer and the Fine Offset for tCKmin (SPD byte 125)
        /// used for correction to get the actual value.
        ///
        virtual fapi2::ReturnCode min_cycle_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);

        ///
        /// @brief Decodes SDRAM Maximum Cycle Time in MTB
        /// @param[in] i_target dimm target
        /// @param[out] o_value tCKmax in MTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 19
        /// @note Item JC-45-2220.01x
        /// @note Page 32
        /// @note DDR4 SPD Document Release 3
        /// @warning If tCKmax cannot be divided evenly by the MTB,
        /// this byte must be rounded up to the next larger
        /// integer and the Fine Offset for tCKmax (SPD byte 124)
        /// used for correction to get the actual value.
        ///
        virtual fapi2::ReturnCode max_cycle_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);

        ///
        /// @brief Decode CAS Latencies Supported
        /// @param[in] i_target dimm target
        /// @param[out] o_value bitmap of supported CAS latencies
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Bytes 20-23
        /// @note Item JC-45-2220.01x
        /// @note Page 33-34
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode supported_cas_latencies(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint64_t& o_value);

        ///
        /// @brief Decodes SDRAM Minimum CAS Latency Time in MTB
        /// @param[in] i_target dimm target
        /// @param[out] o_value tAAmin in MTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 24
        /// @note Item JC-45-2220.01x
        /// @note Page 34
        /// @note DDR4 SPD Document Release 3
        /// @warning If tAAmin cannot be divided evenly by the MTB,
        /// this byte must be rounded up to the next larger
        /// integer and the Fine Offset for tAAmin (SPD byte 123)
        /// used for correction to get the actual value.
        ///
        virtual fapi2::ReturnCode min_cas_latency_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);

        ///
        /// @brief Decodes SDRAM Minimum RAS to CAS Delay Time in MTB
        /// @param[in] i_target dimm target
        /// @param[out] o_value tRCDmin in MTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 25
        /// @note Item JC-45-2220.01x
        /// @note Page 35
        /// @note DDR4 SPD Document Release 3
        /// @warning If tRCDmin cannot be divided evenly by the MTB,
        /// this byte must be rounded up to the next larger
        /// integer and the Fine Offset for tRCDmin (SPD byte 122)
        /// used for correction to get the actual value
        ///
        virtual fapi2::ReturnCode min_ras_to_cas_delay_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);

        ///
        /// @brief Decodes SDRAM Minimum Row Precharge Delay Time in MTB
        /// @param[in] i_target dimm target
        /// @param[out] o_value tRPmin in MTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 26
        /// @note Item JC-45-2220.01x
        /// @note Page 36-37
        /// @note DDR4 SPD Document Release 3
        /// @warning If tRPmin cannot be divided evenly by the MTB,
        /// this byte must be rounded up to the next larger
        /// integer and the Fine Offset for tRPmin (SPD byte 121)
        /// used for correction to get the actual value
        ///
        virtual fapi2::ReturnCode min_row_precharge_delay_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);

        ///
        /// @brief Decodes SDRAM Minimum Active to Precharge Delay Time in MTB
        /// @param[in] i_target dimm target
        /// @param[out] o_value tRASmin in MTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 28 (bits 7~4) & SPD Byte 27 (bits 3~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 38
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode min_active_to_precharge_delay_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);

        ///
        /// @brief Decodes SDRAM Minimum Active to Active/Refresh Delay Time in MTB
        /// @param[in] i_target dimm target
        /// @param[out] o_value tRCmin in MTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 27 (bits 7~4) & SPD Byte 29 (bits 7~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 38
        /// @note DDR4 SPD Document Release 3
        /// @warning If tRCmin cannot be divided evenly by the MTB,
        /// this byte must be rounded up to the next larger
        /// integer and the Fine Offset for tRCmin (SPD byte 120)
        /// used for correction to get the actual value.
        ///
        virtual
        fapi2::ReturnCode min_active_to_active_refresh_delay_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);

        ///
        /// @brief Decodes SDRAM Minimum Refresh Recovery Delay Time 1
        /// @param[in] i_target dimm target
        /// @param[out] o_value tRFC1min in MTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 30 & Byte 31
        /// @note Item JC-45-2220.01x
        /// @note Page 39-40
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode min_refresh_recovery_delay_time_1(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);

        ///
        /// @brief Decodes SDRAM Minimum Refresh Recovery Delay Time 2
        /// @param[in] i_target dimm target
        /// @param[out] o_value tRFC2min in MTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 32 & Byte 33
        /// @note Item JC-45-2220.01x
        /// @note Page 40
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode min_refresh_recovery_delay_time_2(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);

        ///
        /// @brief Decodes SDRAM Minimum Refresh Recovery Delay Time 4
        /// @param[in] i_target dimm target
        /// @param[out] o_value tRFC4min in MTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 34 & Byte 35
        /// @note Item JC-45-2220.01x
        /// @note Page 40
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode min_refresh_recovery_delay_time_4(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);

        ///
        /// @brief Decodes SDRAM Minimum Four Activate Window Delay Time
        /// @param[in] i_target dimm target
        /// @param[out] o_value tFAWmin in MTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 36 (bits 3~0) & Byte 37 (bits 7~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 42
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode min_tfaw(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                           int64_t& o_value);

        ///
        /// @brief Decodes Minimum Activate to Activate Delay Time - Different Bank Group
        /// @param[in] i_target dimm target
        /// @param[out] o_value tRRD_Smin MTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 38
        /// @note Item JC-45-2220.01x
        /// @note Page 43
        /// @note DDR4 SPD Document Release 3
        /// @warning If tRRD_Smin cannot be divided evenly by the MTB,
        /// this byte must be rounded up to the next larger
        /// integer and the Fine Offset for tRRD_Smin (SPD byte 119)
        /// used for correction to get the actual value.
        ///
        virtual fapi2::ReturnCode min_trrd_s(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                             int64_t& o_value);

        ///
        /// @brief Decodes Minimum Activate to Activate Delay Time - Same Bank Group
        /// @param[in] i_target dimm target
        /// @param[out] o_value tRRD_Lmin MTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 39
        /// @note Item JC-45-2220.01x
        /// @note Page 43-44
        /// @note DDR4 SPD Document Release 3
        /// @warning If tRRD_Lmin cannot be divided evenly by the MTB,
        /// this byte must be rounded up to the next larger
        /// integer and the Fine Offset for tRRD_Lmin (SPD byte 118)
        /// used for correction to get the actual value.
        ///
        virtual fapi2::ReturnCode min_trrd_l(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                             int64_t& o_value);

        ///
        /// @brief Decodes Minimum CAS to CAS Delay Time - Same Bank Group
        /// @param[in] i_target dimm target
        /// @param[out] o_value tCCD_Lmin MTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 40
        /// @note Item JC-45-2220.01x
        /// @note Page 44-45
        /// @note DDR4 SPD Document Release 3
        /// @warning If tCCD_Lmin cannot be divided evenly by the MTB,
        /// this byte must be rounded up to the next larger
        /// integer and the Fine Offset for tCCD_Lmin (SPD byte 117)
        /// used for correction to get the actual value.
        ///
        virtual fapi2::ReturnCode min_tccd_l(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                             int64_t& o_value);

        ///
        /// @brief Decodes Minimum Write Recovery Time
        /// @param[in] i_target dimm target
        /// @param[out] o_value tWRmin in MTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 41 (bits 3~0) & Byte 42 (bits 7~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 40
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode min_write_recovery_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);

        ///
        /// @brief Decodes Minimum Write to Read Time - Different Bank Group
        /// @param[in] i_target dimm target
        /// @param[out] o_value tWRT_Smin in MTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 43 (bits 3~0) & Byte 44 (bits 7~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 40
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode min_twtr_s(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                             int64_t& o_value);

        ///
        /// @brief Decodes Minimum Write to Read Time - Same Bank Group
        /// @param[in] i_target dimm target
        /// @param[out] o_value tWRT_Lmin in MTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 43 (bits 7~4) & Byte 45 (bits 7~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 46
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode min_twtr_l(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                             int64_t& o_value);

        ///
        /// @brief Decodes Fine Offset for Minimum CAS to CAS Delay Time - Same Bank Group
        /// @param[in] i_target dimm target
        /// @param[out] o_value tCCD_Lmin offset in FTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 117
        /// @note Item JC-45-2220.01x
        /// @note Page 52
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode fine_offset_min_tccd_l(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);

        ///
        /// @brief Decodes Fine Offset for Minimum Activate to Activate Delay Time - Same Bank Group
        /// @param[in] i_target dimm target
        /// @param[out] o_value tRRD_Lmin offset in FTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 118
        /// @note Item JC-45-2220.01x
        /// @note Page 52
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode fine_offset_min_trrd_l(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);

        ///
        /// @brief Decodes Fine Offset for Minimum Activate to Activate Delay Time - Different Bank Group
        /// @param[in] i_target dimm target
        /// @param[out] o_value tRRD_Smin offset in FTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 119
        /// @note Item JC-45-2220.01x
        /// @note Page 52
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode fine_offset_min_trrd_s(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);

        ///
        /// @brief Decodes Fine Offset for Minimum Active to Active/Refresh Delay Time
        /// @param[in] i_target dimm target
        /// @param[out] o_value tRCmin offset in FTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 120
        /// @note Item JC-45-2220.01x
        /// @note Page 52
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode fine_offset_min_trc(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);

        ///
        /// @brief Decodes Fine Offset for Minimum Row Precharge Delay Time
        /// @param[in] i_target dimm target
        /// @param[out] o_value tRPmin offset in FTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 121
        /// @note Item JC-45-2220.01x
        /// @note Page 52
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode fine_offset_min_trp(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);

        ///
        /// @brief Decodes Fine Offset for SDRAM Minimum RAS to CAS Delay Time
        /// @param[in] i_target dimm target
        /// @param[out] o_value tRCDmin offset in FTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 122
        /// @note Item JC-45-2220.01x
        /// @note Page 52
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode fine_offset_min_trcd(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);

        ///
        /// @brief Decodes Fine Offset for SDRAM Minimum CAS Latency Time
        /// @param[in] i_target dimm target
        /// @param[out] o_value tAAmin offset in FTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 123
        /// @note Item JC-45-2220.01x
        /// @note Page 52
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode fine_offset_min_taa(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);

        ///
        /// @brief Decodes Fine Offset for SDRAM Maximum Cycle Time
        /// @param[in] i_target dimm target
        /// @param[out] o_value tCKmax offset in FTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 124
        /// @note Item JC-45-2220.01x
        /// @note Page 52
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode fine_offset_max_tck(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);

        ///
        /// @brief Decodes Fine Offset for SDRAM Minimum Cycle Time
        /// @param[in] i_target dimm target
        /// @param[out] o_value tCKmin offset in FTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 125
        /// @note Item JC-45-2220.01x
        /// @note Page 52
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode fine_offset_min_tck(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value);

        ///
        /// @brief Decodes Cyclical Redundancy Code (CRC) for Base Configuration Section
        /// @param[in] i_target dimm target
        /// @param[out] o_value crc value from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 127 & Byte 126
        /// @note Item JC-45-2220.01x
        /// @note Page 53
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode cyclical_redundancy_code(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint16_t& o_value);

        ///
        /// @brief Decodes module manufacturer ID code
        /// @param[in] i_target TARGET_TYPE_DIMM
        /// @param[out] o_output module manufacturing id code
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 320 (bit 7~0), 321 (6~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 3
        /// @note Page 4.1.2.12 - 54
        ///
        virtual fapi2::ReturnCode module_manufacturer_id_code(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint16_t& o_value);
        ///
        /// @brief Decodes Module Manufacturing Location
        /// @param[in] i_target dimm target
        /// @param[out] o_value uint8_t identifier for manufacturing location of memory module
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 322
        /// @note Item JC-45-2220.01x
        /// @note Page 55
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode module_manufacturing_location(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value);
        ///
        /// @brief Decodesmodule manufacturing date
        /// @param[in] i_target TARGET_TYPE_DIMM
        /// @param[out] o_output the 2 byte date of manufacturing in BCD format
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 323 & 324
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 54
        /// @note in Binary Coded Decimal (BCD)
        /// @note MSB = year, LSB = week
        ///
        virtual fapi2::ReturnCode module_manufacturing_date(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint16_t& o_output);

        ///
        /// @brief Decodes module's unique serial number
        /// @param[in] i_target TARGET_TYPE_DIMM
        /// @param[out] o_output
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 325-328
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 54
        ///
        virtual fapi2::ReturnCode module_serial_number(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint32_t& o_output);
        ///
        /// @brief Decodes Module Revision Code
        /// @param[in] i_target dimm target
        /// @param[out] o_value uint8_t identifier for revision code
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 349
        /// @note Item JC-45-2220.01x
        /// @note Page 55
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode module_revision_code(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value);
        ///
        /// @brief Decodes DRAM Manufacturer ID code
        /// @param[in] i_target TARGET_TYPE_DIMM
        /// @param[out] o_output dram manufacturing id code
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 350 - 351
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 54
        ///
        virtual fapi2::ReturnCode dram_manufacturer_id_code(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint16_t& o_output);
        ///
        /// @brief Decodes DRAM Stepping
        /// @param[in] i_target dimm target
        /// @param[out] o_value uint8_t DRAM Stepping val
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 352
        /// @note Item JC-45-2220.01x
        /// @note Page 56
        /// @note DDR4 SPD Document Release 3
        /// @note also called die revision level
        ///
        virtual fapi2::ReturnCode dram_stepping(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                                uint8_t& o_value);

        ///
        /// @brief Returns Logical ranks per DIMM
        /// @param[in] i_target dimm target
        /// @param[out] o_logical_ranks number of logical ranks
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode logical_ranks_per_dimm(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_logical_rank_per_dimm);

    protected:
        // TODO RTC:159362
        const fapi2::Target<fapi2::TARGET_TYPE_DIMM> iv_target;

        ///
        /// @brief Helper function that turns Logical ranks in Primary SDRAM type
        /// @param[in] i_target dimm target
        /// @param[out] o_logical_ranks number of logical ranks
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode prim_sdram_logical_ranks(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_logical_ranks);

};// decoder

///
/// @class decoder_v1_1
/// @brief Base SPD DRAM decoder, 1st addition to general section
///
class decoder_v1_1 : public decoder
{
    protected:

        ///
        /// @brief Helper functions that returns Logical ranks in Secondary SDRAM type
        /// @param[in] i_target dimm target
        /// @param[out] o_logical_ranks number of logical ranks
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode sec_sdram_logical_ranks(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_logical_ranks);

    public:
        ///
        /// @brief Default constructor
        ///
        decoder_v1_1() = default;

        ///
        /// @brief ctor
        /// @param[in] i_target dimm target
        /// @param[in] i_spd_data SPD data vector
        /// @param[in] i_module_decoder shared_ptr to dimm module decoder
        /// @param[in] i_raw_card raw pointer to rcd data
        ///
        decoder_v1_1(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                     const std::vector<uint8_t>& i_spd_data,
                     const std::shared_ptr<dimm_module_decoder>& i_module_decoder,
                     const rcd01::raw_card_t& i_raw_card);

        ///
        /// @brief Default dtor
        ///
        virtual ~decoder_v1_1() = default;

        /////////////////////////
        // Member Methods
        /////////////////////////

        ///
        /// @brief Decodes hybrid media field from SPD
        /// @param[in] i_target
        /// @param[out] o_value
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note Decodes SPD Byte 3 (bits 6~4)
        /// @note Item JC-45-2220.01x
        /// @note Page 17
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode hybrid_media(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                               uint8_t& o_value) override;

        ///
        /// @brief Decodes hybrid field from SPD
        /// @param[in] i_target
        /// @param[out] o_value
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note Decodes SPD Byte 3 (bit 7)
        /// @note Item JC-45-2220.01x
        /// @note Page 17
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode hybrid(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                         uint8_t& o_value) override;

        ///
        /// @brief Decodes SDRAM density from SPD
        /// @param[in] i_target dimm target
        /// @param[out] o_value SDRAM density in GBs
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 4 (bits 3~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 18
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode sdram_density(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                                uint8_t& o_value) override;

        ///
        /// @brief Decode Soft post package repair (soft PPR)
        /// @param[in] i_target dimm target
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 9 (bit 5)
        /// @note Item JC-45-2220.01x
        /// @note Page 21
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode soft_post_package_repair(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value) override;

        ///
        /// @brief Decodes Secondary SDRAM signal loading
        /// @param[in] i_target dimm target
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 10 (bits 1~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 22
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode sec_sdram_signal_loading(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value) override;

        ///
        /// @brief Decodes Secondary DRAM Density Ratio
        /// @param[in] i_target dimm target
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 10 (bits 3~2)
        /// @note Item JC-45-2220.01x
        /// @note Page 22
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode sec_dram_density_ratio(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value) override;

        ///
        /// @brief Decodes Secondary SDRAM die count
        /// @param[in] i_target dimm target
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 10 (bits 6~4)
        /// @note Item JC-45-2220.01x
        /// @note Page 22
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode sec_sdram_die_count(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value) override;

        ///
        /// @brief Decodes Secondary SDRAM package type
        /// @param[in] i_target dimm target
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 10 (bit 7)
        /// @note Item JC-45-2220.01x
        /// @note Page 22
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode sec_sdram_package_type(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value) override;

        ///
        /// @brief Decodes number of package ranks per DIMM
        /// @param[in] i_target dimm target
        /// @param[out] o_value number of package ranks per DIMM
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 12 (bits 5~3)
        /// @note Item JC-45-2220.01x
        /// @note Page 23
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode num_package_ranks_per_dimm(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_value) override;

        ///
        /// @brief Decodes Rank Mix
        /// @param[in] i_target dimm target
        /// @param[out] o_value rank mix value from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 12 (bit 6)
        /// @note Item JC-45-2220.01x
        /// @note Page 23
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode rank_mix(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                           uint8_t& o_value) override;

        ///
        /// @brief Decode CAS Latencies Supported
        /// @param[in] i_target dimm target
        /// @param[out] o_value bitmap of supported CAS latencies
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Bytes 20-23
        /// @note Item JC-45-2220.01x
        /// @note Page 33-34
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode supported_cas_latencies(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint64_t& o_value) override;

        ///
        /// @brief Decodes Minimum Write Recovery Time
        /// @param[in] i_target dimm target
        /// @param[out] o_value tWRmin in MTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 41 (bits 3~0) & Byte 42 (bits 7~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 40
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode min_write_recovery_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                int64_t& o_value) override;

        ///
        /// @brief Decodes Minimum Write to Read Time - Different Bank Group
        /// @param[in] i_target dimm target
        /// @param[out] o_value tWRT_Smin in MTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 43 (bits 3~0) & Byte 44 (bits 7~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 40
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode min_twtr_s(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                             int64_t& o_value) override;

        ///
        /// @brief Decodes Minimum Write to Read Time - Same Bank Group
        /// @param[in] i_target dimm target
        /// @param[out] o_value tWRT_Lmin in MTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 43 (bits 7~4) & Byte 45 (bits 7~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 46
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode min_twtr_l(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                             int64_t& o_value) override;

        ///
        /// @brief Returns Logical ranks per DIMM
        /// @param[in] i_target dimm target
        /// @param[out] o_logical_ranks number of logical ranks
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode logical_ranks_per_dimm(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                uint8_t& o_logical_rank_per_dimm) override;

};// spd_decoder_v1_1

}// spd
}// mss

#endif //_MSSS_PD_DECODER_H_
