/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/spd/common/spd_decoder.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
#include <lib/spd/common/rcw_settings.H>
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
        const fapi2::Target<fapi2::TARGET_TYPE_DIMM> iv_target;

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

            // Byte 6
            PRIM_SIGNAL_LOAD_START = 6,
            PRIM_SIGNAL_LOAD_LEN = 2,

            PRIM_DIE_COUNT_START = 1,
            PRIM_DIE_COUNT_LEN = 3,

            PRIM_PACKAGE_TYPE_START = 0,
            PRIM_PACKAGE_TYPE_LEN = 1,

            // Byte 7
            MAC_START = 4,
            MAC_LEN = 4,

            TMAW_START = 2,
            TMAW_LEN = 2,

            // Byte 8 reserved

            // Byte 9
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

            // Byte 13
            BUS_WIDTH_START = 5,
            BUS_WIDTH_LEN = 3,

            BUS_EXT_WIDTH_START = 3,
            BUS_EXT_WIDTH_LEN = 2,

            // Byte 14
            THERM_SENSOR_RESERV_START = 1,
            THERM_SENSOR_RESERV_LEN = 7,

            THERM_SENSOR_START = 0,
            THERM_SENSOR_LEN = 1,

            // Byte 15
            EXT_MOD_TYPE_START = 5,
            EXT_MOD_TYPE_LEN = 3,

            // Byte 16 - reserved

            // Byte 17
            FINE_TIMEBASE_START = 6,
            FINE_TIMEBASE_LEN = 2,

            MED_TIMEBASE_START = 4,
            MED_TIMEBASE_LEN = 2,

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

        // First field is byte index
        // Second field is the decoding start bit
        // Third field is the decoding bit length
        static constexpr field_t BYTES_USED{0, BYTES_USED_START, BYTES_USED_LEN};
        static constexpr field_t TOTAL_BYTES_USED{0, BYTES_TOTAL_START, BYTES_TOTAL_LEN};
        static constexpr field_t HYBRID_MEDIA{3, HYBRID_MEDIA_START, HYBRID_MEDIA_LEN};
        static constexpr field_t HYBRID{3, HYBRID_START, HYBRID_LEN};
        static constexpr field_t SDRAM_CAPACITY{4, SDRAM_CAPACITY_START, SDRAM_CAPACITY_LEN};
        static constexpr field_t SDRAM_BANKS{4, SDRAM_BANKS_START, SDRAM_BANKS_LEN};
        static constexpr field_t BANK_GROUP{4, BANK_GROUP_START, BANK_GROUP_LEN};
        static constexpr field_t COL_ADDRESS{5, COL_ADDRESS_START, COL_ADDRESS_LEN};
        static constexpr field_t ROW_ADDRESS{5, ROW_ADDRESS_START, ROW_ADDRESS_LEN};
        static constexpr field_t PRIM_SIGNAL_LOADING{6, PRIM_SIGNAL_LOAD_START, PRIM_SIGNAL_LOAD_LEN};
        static constexpr field_t PRIM_DIE_COUNT{6, PRIM_DIE_COUNT_START, PRIM_DIE_COUNT_LEN};
        static constexpr field_t PRIM_PACKAGE_TYPE{6, PRIM_PACKAGE_TYPE_START, PRIM_PACKAGE_TYPE_LEN};
        static constexpr field_t MAC{7, MAC_START, MAC_LEN};
        static constexpr field_t TMAW{7, TMAW_START, TMAW_LEN};
        static constexpr field_t PPR{9, PPR_START, PPR_LEN};
        static constexpr field_t SOFT_PPR{9, SOFT_PPR_START, SOFT_PPR_LEN};
        static constexpr field_t SEC_SIGNAL_LOADING{10, SEC_SIGNAL_LOAD_START, SEC_SIGNAL_LOAD_LEN};
        static constexpr field_t SEC_DENSITY_RATIO{10, DENSITY_RATIO_START, DENSITY_RATIO_LEN};
        static constexpr field_t SEC_DIE_COUNT{10, SEC_DIE_COUNT_START, SEC_DIE_COUNT_LEN};
        static constexpr field_t SEC_PACKAGE_TYPE{10, SEC_PACKAGE_TYPE_START, SEC_PACKAGE_TYPE_LEN};
        static constexpr field_t OPERABLE_FLD{11, OPERABLE_START, OPERABLE_LEN};
        static constexpr field_t ENDURANT_FLD{11, ENDURANT_START, ENDURANT_LEN};
        static constexpr field_t SDRAM_WIDTH{12, SDRAM_WIDTH_START, SDRAM_WIDTH_LEN};
        static constexpr field_t RANK_MIX{12, RANK_MIX_START, RANK_MIX_LEN};
        static constexpr field_t PACKAGE_RANKS{12, PACKAGE_RANKS_START, PACKAGE_RANKS_LEN};
        static constexpr field_t BUS_WIDTH{13, BUS_WIDTH_START, BUS_WIDTH_LEN};
        static constexpr field_t BUS_EXT_WIDTH{13, BUS_EXT_WIDTH_START, BUS_EXT_WIDTH_LEN};
        static constexpr field_t THERM_SENSOR{14, THERM_SENSOR_START, THERM_SENSOR_LEN};
        static constexpr field_t EXTENDED_MODULE_TYPE{15, EXT_MOD_TYPE_START, EXT_MOD_TYPE_LEN};
        static constexpr field_t FINE_TIMEBASE{17, FINE_TIMEBASE_START, FINE_TIMEBASE_LEN};
        static constexpr field_t MEDIUM_TIMEBASE{17, MED_TIMEBASE_START, MED_TIMEBASE_LEN};
        static constexpr field_t TRASMIN_MSN{27, TRASMIN_MSN_START, TRASMIN_MSN_LEN};
        static constexpr field_t TRASMIN_LSB{28, TRASMIN_LSB_START, TRASMIN_LSB_LEN};
        static constexpr field_t TRCMIN_MSN{27, TRCMIN_MSN_START, TRCMIN_MSN_LEN};
        static constexpr field_t TRCMIN_LSB{29, TRCMIN_LSB_START, TRCMIN_LSB_LEN};
        static constexpr field_t TRFC1MIN_MSB{31, TRFC1MIN_MSB_START, TRFC1MIN_MSB_LEN};
        static constexpr field_t TRFC1MIN_LSB{30, TRFC1MIN_LSB_START, TRFC1MIN_LSB_LEN};
        static constexpr field_t TRFC2MIN_MSB{33, TRFC2MIN_MSB_START, TRFC2MIN_MSB_LEN};
        static constexpr field_t TRFC2MIN_LSB{32, TRFC2MIN_LSB_START, TRFC2MIN_LSB_LEN};
        static constexpr field_t TRFC4MIN_MSB{35, TRFC4MIN_MSB_START, TRFC4MIN_MSB_LEN};
        static constexpr field_t TRFC4MIN_LSB{34, TRFC4MIN_LSB_START, TRFC4MIN_LSB_LEN};
        static constexpr field_t TFAWMIN_MSN{36, TFAWMIN_MSN_START, TFAWMIN_MSN_LEN};
        static constexpr field_t TFAWMIN_LSB{37, TFAWMIN_LSB_START, TFAWMIN_LSB_LEN};
        static constexpr field_t TWRMIN_MSN{41, TWRMIN_MSN_START, TWRMIN_MSN_LEN};
        static constexpr field_t TWRMIN_LSB{42, TWRMIN_LSB_START, TWRMIN_LSB_LEN};
        static constexpr field_t TWTRMIN_S_MSN{43, TWTRMIN_S_MSN_START, TWTRMIN_S_MSN_LEN};
        static constexpr field_t TWTRMIN_S_LSB{44, TWTRMIN_S_LSB_START, TWTRMIN_S_LSB_LEN};
        static constexpr field_t TWTRMIN_L_MSN{43, TWTRMIN_L_MSN_START, TWTRMIN_L_MSN_LEN};
        static constexpr field_t TWTRMIN_L_LSB{45, TWTRMIN_L_LSB_START, TWTRMIN_L_LSB_LEN};
        static constexpr field_t CRC_MSB{127, CRC_MSB_START, CRC_MSB_LEN};
        static constexpr field_t CRC_LSB{126, CRC_LSB_START, CRC_LSB_LEN};

        ///
        /// @brief Helper function that turns Logical ranks in Primary SDRAM type
        /// @param[out] o_logical_ranks number of logical ranks
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode prim_sdram_logical_ranks( uint8_t& o_logical_ranks );

    public:
        std::shared_ptr<dimm_module_decoder> iv_module_decoder;
        std::vector<uint8_t> iv_spd_data;
        rcw_settings iv_raw_card;

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
                const rcw_settings& i_raw_card);

        ///
        /// @brief Default dtor
        ///
        virtual ~decoder() = default;

        /////////////////////////
        // Member Methods
        /////////////////////////

        ///
        /// @brief Decodes number of used SPD bytes
        /// @param[out] o_value number of SPD bytes used
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note Decodes SPD Byte 0 (3~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 14
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode number_of_used_bytes( uint16_t& o_value );

        ///
        /// @brief Decodes total number of SPD bytes
        /// @param[out] o_value number of total SPD bytes
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note Decodes SPD Byte 0 (bits 6~4)
        /// @note Item JC-45-2220.01x
        /// @note Page 14
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode number_of_total_bytes( uint16_t& o_value );

        ///
        /// @brief Decodes hybrid media field from SPD
        /// @param[out] o_value
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note Decodes SPD Byte 3 (bits 6~4)
        /// @note Item JC-45-2220.01x
        /// @note Page 17
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode hybrid_media( uint8_t& o_value );

        ///
        /// @brief Decodes hybrid field from SPD
        /// @param[out] o_value
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note Decodes SPD Byte 3 (bit 7)
        /// @note Item JC-45-2220.01x
        /// @note Page 17
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode hybrid( uint8_t& o_value );

        ///
        /// @brief Decodes SDRAM density from SPD
        /// @param[out] o_value SDRAM density in GBs
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 4 (bits 3~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 18
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode sdram_density( uint8_t& o_value );

        ///
        /// @brief Decodes number of SDRAM banks bits from SPD
        /// @param[out] o_value Number of SDRAM bank bits
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 4 (bits 5~4)
        /// @note Item JC-45-2220.01x
        /// @note Page 18
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode bank_bits( uint8_t& o_value );

        ///
        /// @brief Decodes number of SDRAM bank groups bits from SPD
        /// @param[out] o_value Number of SDRAM bank groups bits
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 4 (bits 7~6)
        /// @note Item JC-45-2220.01x
        /// @note Page 18
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode bank_group_bits( uint8_t& o_value );

        ///
        /// @brief Decodes number of SDRAM column address bits
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 5 (bits 2~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 18
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode column_address_bits( uint8_t& o_value );

        ///
        /// @brief Decodes number of SDRAM row address bits
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 5 (bits 5~3)
        /// @note Item JC-45-2220.01x
        /// @note Page 18
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode row_address_bits( uint8_t& o_value );

        ///
        /// @brief Decodes Primary SDRAM signal loading
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 6 (bits 1~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 19
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode prim_sdram_signal_loading( uint8_t& o_value );

        ///
        /// @brief Decodes Primary SDRAM die count
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 6 (bits 6~4)
        /// @note Item JC-45-2220.01x
        /// @note Page 19
        /// @note DDR4 SPD Document Release 3
        ///
        virtual  fapi2::ReturnCode prim_sdram_die_count( uint8_t& o_value );

        ///
        /// @brief Decodes Primary SDRAM package type
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 6 (bit 7)
        /// @note Item JC-45-2220.01x
        /// @note Page 19
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode prim_sdram_package_type( uint8_t& o_value );

        ///
        /// @brief Decode SDRAM Maximum activate count
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 7 (bits 3~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 20
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode maximum_activate_count( uint32_t& o_value );

        ///
        /// @brief Decode SDRAM Maximum activate window (multiplier), tREFI uknown at this point
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 7 (bits 3~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 20
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode maximum_activate_window_multiplier( uint32_t& o_value );

        ///
        /// @brief Decode Post package repair (PPR)
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 9 (bits 7~6)
        /// @note Item JC-45-2220.01x
        /// @note Page 21
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode post_package_repair( uint8_t& o_value );

        ///
        /// @brief Decode Soft post package repair (soft PPR)
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 9 (bit 5)
        /// @note Item JC-45-2220.01x
        /// @note Page 21
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode soft_post_package_repair( uint8_t& o_value );

        ///
        /// @brief Decodes Secondary SDRAM signal loading
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 10 (bits 1~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 22
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode sec_sdram_signal_loading( uint8_t& o_value );

        ///
        /// @brief Decodes Secondary DRAM Density Ratio
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 10 (bits 3~2)
        /// @note Item JC-45-2220.01x
        /// @note Page 22
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode sec_dram_density_ratio( uint8_t& o_value );

        ///
        /// @brief Decodes Secondary SDRAM die count
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 10 (bits 6~4)
        /// @note Item JC-45-2220.01x
        /// @note Page 22
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode sec_sdram_die_count( uint8_t& o_value );

        ///
        /// @brief Decodes Secondary SDRAM package type
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 10 (bit 7)
        /// @note Item JC-45-2220.01x
        /// @note Page 22
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode sec_sdram_package_type( uint8_t& o_value );

        ///
        /// @brief Decode Module Nominal Voltage, VDD
        /// @param[out] o_value enum representing if 1.2V is operable
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 11 (bit 0)
        /// @note Item JC-45-2220.01x
        /// @note Page 23
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode operable_nominal_voltage( uint8_t& o_value );

        ///
        /// @brief Decode Module Nominal Voltage, VDD
        /// @param[out] o_value enum representing if 1.2V is endurant
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 11 (bit 1)
        /// @note Item JC-45-2220.01x
        /// @note Page 23
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode endurant_nominal_voltage( uint8_t& o_value );
        ///
        /// @brief Decodes SDRAM device width
        /// @param[out] o_value device width in bits
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 12 (bits 2~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 23
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode device_width( uint8_t& o_value );

        ///
        /// @brief Decodes number of package ranks per DIMM
        /// @param[out] o_value number of package ranks per DIMM
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 12 (bits 5~3)
        /// @note Item JC-45-2220.01x
        /// @note Page 23
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode num_package_ranks_per_dimm( uint8_t& o_value );

        ///
        /// @brief Decodes Rank Mix
        /// @param[out] o_value rank mix value from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 12 (bit 6)
        /// @note Item JC-45-2220.01x
        /// @note Page 23
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode rank_mix( uint8_t& o_value );

        ///
        /// @brief Decodes primary bus width
        /// @param[out] o_value primary bus width in bits
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 13 (bits 2~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 27
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode prim_bus_width( uint8_t& o_value );

        ///
        /// @brief Decodes bus width extension
        /// @param[out] o_value bus width extension in bits
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 13 (bits 4~3)
        /// @note Item JC-45-2220.01x
        /// @note Page 27
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode bus_width_extension( uint8_t& o_value );

        ///
        /// @brief Decode Module Thermal Sensor
        /// @param[out] o_value thermal sensor value from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 14 (bit 7)
        /// @note Item JC-45-2220.01x
        /// @note Page 28
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode thermal_sensor( uint8_t& o_value );

        ///
        /// @brief Decode Extended Base Module Type
        /// @param[out] o_value extended base module type value from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 15 (bits 3~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 28
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode extended_base_module_type( uint8_t& o_value );

        ///
        /// @brief Decode Fine Timebase
        /// @param[out] o_value fine_timebase from SPD in picoseconds
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 17 (bits 1~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 29
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode fine_timebase( int64_t& o_value );

        ///
        /// @brief Decode Medium Timebase
        /// @param[out] o_value fine_timebase from SPD in picoseconds
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 17 (bits 3~2)
        /// @note Item JC-45-2220.01x
        /// @note Page 29
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode medium_timebase( int64_t& o_value );

        ///
        ///
        /// @brief Decodes SDRAM Minimum Cycle Time in MTB
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
        virtual fapi2::ReturnCode min_cycle_time( int64_t& o_value );

        ///
        /// @brief Decodes SDRAM Maximum Cycle Time in MTB
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
        virtual fapi2::ReturnCode max_cycle_time( int64_t& o_value );

        ///
        /// @brief Decode CAS Latencies Supported
        /// @param[out] o_value bitmap of supported CAS latencies
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Bytes 20-23
        /// @note Item JC-45-2220.01x
        /// @note Page 33-34
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode supported_cas_latencies( uint64_t& o_value );

        ///
        /// @brief Decodes SDRAM Minimum CAS Latency Time in MTB
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
        virtual fapi2::ReturnCode min_cas_latency_time( int64_t& o_value );

        ///
        /// @brief Decodes SDRAM Minimum RAS to CAS Delay Time in MTB
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
        virtual fapi2::ReturnCode min_ras_to_cas_delay_time( int64_t& o_value );

        ///
        /// @brief Decodes SDRAM Minimum Row Precharge Delay Time in MTB
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
        virtual fapi2::ReturnCode min_row_precharge_delay_time( int64_t& o_value );

        ///
        /// @brief Decodes SDRAM Minimum Active to Precharge Delay Time in MTB
        /// @param[out] o_value tRASmin in MTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 28 (bits 7~4) & SPD Byte 27 (bits 3~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 38
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode min_active_to_precharge_delay_time( int64_t& o_value );

        ///
        /// @brief Decodes SDRAM Minimum Active to Active/Refresh Delay Time in MTB
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
        fapi2::ReturnCode min_active_to_active_refresh_delay_time( int64_t& o_value );

        ///
        /// @brief Decodes SDRAM Minimum Refresh Recovery Delay Time 1
        /// @param[out] o_value tRFC1min in MTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 30 & Byte 31
        /// @note Item JC-45-2220.01x
        /// @note Page 39-40
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode min_refresh_recovery_delay_time_1( int64_t& o_value );

        ///
        /// @brief Decodes SDRAM Minimum Refresh Recovery Delay Time 2
        /// @param[out] o_value tRFC2min in MTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 32 & Byte 33
        /// @note Item JC-45-2220.01x
        /// @note Page 40
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode min_refresh_recovery_delay_time_2( int64_t& o_value );

        ///
        /// @brief Decodes SDRAM Minimum Refresh Recovery Delay Time 4
        /// @param[out] o_value tRFC4min in MTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 34 & Byte 35
        /// @note Item JC-45-2220.01x
        /// @note Page 40
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode min_refresh_recovery_delay_time_4( int64_t& o_value );

        ///
        /// @brief Decodes SDRAM Minimum Four Activate Window Delay Time
        /// @param[out] o_value tFAWmin in MTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 36 (bits 3~0) & Byte 37 (bits 7~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 42
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode min_tfaw( int64_t& o_value );

        ///
        /// @brief Decodes Minimum Activate to Activate Delay Time - Different Bank Group
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
        virtual fapi2::ReturnCode min_trrd_s( int64_t& o_value );

        ///
        /// @brief Decodes Minimum Activate to Activate Delay Time - Same Bank Group
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
        virtual fapi2::ReturnCode min_trrd_l( int64_t& o_value );

        ///
        /// @brief Decodes Minimum CAS to CAS Delay Time - Same Bank Group
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
        virtual fapi2::ReturnCode min_tccd_l( int64_t& o_value );

        ///
        /// @brief Decodes Minimum Write Recovery Time
        /// @param[out] o_value tWRmin in MTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 41 (bits 3~0) & Byte 42 (bits 7~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 40
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode min_write_recovery_time( int64_t& o_value );

        ///
        /// @brief Decodes Minimum Write to Read Time - Different Bank Group
        /// @param[out] o_value tWRT_Smin in MTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 43 (bits 3~0) & Byte 44 (bits 7~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 40
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode min_twtr_s( int64_t& o_value );

        ///
        /// @brief Decodes Minimum Write to Read Time - Same Bank Group
        /// @param[out] o_value tWRT_Lmin in MTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 43 (bits 7~4) & Byte 45 (bits 7~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 46
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode min_twtr_l( int64_t& o_value );

        ///
        /// @brief Decodes Fine Offset for Minimum CAS to CAS Delay Time - Same Bank Group
        /// @param[out] o_value tCCD_Lmin offset in FTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 117
        /// @note Item JC-45-2220.01x
        /// @note Page 52
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode fine_offset_min_tccd_l( int64_t& o_value );

        ///
        /// @brief Decodes Fine Offset for Minimum Activate to Activate Delay Time - Same Bank Group
        /// @param[out] o_value tRRD_Lmin offset in FTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 118
        /// @note Item JC-45-2220.01x
        /// @note Page 52
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode fine_offset_min_trrd_l( int64_t& o_value );

        ///
        /// @brief Decodes Fine Offset for Minimum Activate to Activate Delay Time - Different Bank Group
        /// @param[out] o_value tRRD_Smin offset in FTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 119
        /// @note Item JC-45-2220.01x
        /// @note Page 52
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode fine_offset_min_trrd_s( int64_t& o_value );

        ///
        /// @brief Decodes Fine Offset for Minimum Active to Active/Refresh Delay Time
        /// @param[out] o_value tRCmin offset in FTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 120
        /// @note Item JC-45-2220.01x
        /// @note Page 52
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode fine_offset_min_trc( int64_t& o_value );

        ///
        /// @brief Decodes Fine Offset for Minimum Row Precharge Delay Time
        /// @param[out] o_value tRPmin offset in FTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 121
        /// @note Item JC-45-2220.01x
        /// @note Page 52
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode fine_offset_min_trp( int64_t& o_value );

        ///
        /// @brief Decodes Fine Offset for SDRAM Minimum RAS to CAS Delay Time
        /// @param[out] o_value tRCDmin offset in FTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 122
        /// @note Item JC-45-2220.01x
        /// @note Page 52
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode fine_offset_min_trcd( int64_t& o_value );

        ///
        /// @brief Decodes Fine Offset for SDRAM Minimum CAS Latency Time
        /// @param[out] o_value tAAmin offset in FTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 123
        /// @note Item JC-45-2220.01x
        /// @note Page 52
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode fine_offset_min_taa( int64_t& o_value );

        ///
        /// @brief Decodes Fine Offset for SDRAM Maximum Cycle Time
        /// @param[out] o_value tCKmax offset in FTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 124
        /// @note Item JC-45-2220.01x
        /// @note Page 52
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode fine_offset_max_tck( int64_t& o_value );

        ///
        /// @brief Decodes Fine Offset for SDRAM Minimum Cycle Time
        /// @param[out] o_value tCKmin offset in FTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 125
        /// @note Item JC-45-2220.01x
        /// @note Page 52
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode fine_offset_min_tck( int64_t& o_value );

        ///
        /// @brief Decodes Cyclical Redundancy Code (CRC) for Base Configuration Section
        /// @param[out] o_value crc value from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 127 & Byte 126
        /// @note Item JC-45-2220.01x
        /// @note Page 53
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode cyclical_redundancy_code( uint16_t& o_value );

        ///
        /// @brief Decodes module manufacturer ID code
        /// @param[out] o_output module manufacturing id code
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 320 (bit 7~0), 321 (6~0)
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 3
        /// @note Page 4.1.2.12 - 54
        ///
        virtual fapi2::ReturnCode module_manufacturer_id_code( uint16_t& o_value );

        ///
        /// @brief Decodes Module Manufacturing Location
        /// @param[out] o_value uint8_t identifier for manufacturing location of memory module
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 322
        /// @note Item JC-45-2220.01x
        /// @note Page 55
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode module_manufacturing_location( uint8_t& o_value );
        ///
        /// @brief Decodesmodule manufacturing date
        /// @param[out] o_output the 2 byte date of manufacturing in BCD format
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 323 & 324
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 54
        /// @note in Binary Coded Decimal (BCD)
        /// @note MSB = year, LSB = week
        ///
        virtual fapi2::ReturnCode module_manufacturing_date( uint16_t& o_output );

        ///
        /// @brief Decodes module's unique serial number
        /// @param[out] o_output
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 325-328
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 54
        ///
        virtual fapi2::ReturnCode module_serial_number( uint32_t& o_output );

        ///
        /// @brief Decodes Module Revision Code
        /// @param[out] o_value uint8_t identifier for revision code
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 349
        /// @note Item JC-45-2220.01x
        /// @note Page 55
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode module_revision_code( uint8_t& o_value );

        ///
        /// @brief Decodes DRAM Manufacturer ID code
        /// @param[out] o_output dram manufacturing id code
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 350 - 351
        /// @note Item JEDEC Standard No. 21-C
        /// @note DDR4 SPD Document Release 2
        /// @note Page 4.1.2.12 - 54
        ///
        virtual fapi2::ReturnCode dram_manufacturer_id_code( uint16_t& o_output );
        ///
        /// @brief Decodes DRAM Stepping
        /// @param[out] o_value uint8_t DRAM Stepping val
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 352
        /// @note Item JC-45-2220.01x
        /// @note Page 56
        /// @note DDR4 SPD Document Release 3
        /// @note also called die revision level
        ///
        virtual fapi2::ReturnCode dram_stepping( uint8_t& o_value );

        ///
        /// @brief Returns Logical ranks per DIMM
        /// @param[out] o_logical_ranks number of logical ranks
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode logical_ranks_per_dimm( uint8_t& o_logical_rank_per_dimm );

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
        /// @param[out] o_logical_ranks number of logical ranks
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode sec_sdram_logical_ranks( uint8_t& o_logical_ranks );

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
                     const rcw_settings& i_raw_card);

        ///
        /// @brief Default dtor
        ///
        virtual ~decoder_v1_1() = default;

        /////////////////////////
        // Member Methods
        /////////////////////////

        ///
        /// @brief Decodes hybrid media field from SPD
        /// @param[out] o_value
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note Decodes SPD Byte 3 (bits 6~4)
        /// @note Item JC-45-2220.01x
        /// @note Page 17
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode hybrid_media( uint8_t& o_value) override;

        ///
        /// @brief Decodes hybrid field from SPD
        /// @param[out] o_value
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note Decodes SPD Byte 3 (bit 7)
        /// @note Item JC-45-2220.01x
        /// @note Page 17
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode hybrid( uint8_t& o_value ) override;

        ///
        /// @brief Decodes SDRAM density from SPD
        /// @param[out] o_value SDRAM density in GBs
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 4 (bits 3~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 18
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode sdram_density( uint8_t& o_value ) override;

        ///
        /// @brief Decode Soft post package repair (soft PPR)
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 9 (bit 5)
        /// @note Item JC-45-2220.01x
        /// @note Page 21
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode soft_post_package_repair( uint8_t& o_value ) override;

        ///
        /// @brief Decodes Secondary SDRAM signal loading
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 10 (bits 1~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 22
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode sec_sdram_signal_loading( uint8_t& o_value ) override;

        ///
        /// @brief Decodes Secondary DRAM Density Ratio
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 10 (bits 3~2)
        /// @note Item JC-45-2220.01x
        /// @note Page 22
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode sec_dram_density_ratio( uint8_t& o_value ) override;

        ///
        /// @brief Decodes Secondary SDRAM die count
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 10 (bits 6~4)
        /// @note Item JC-45-2220.01x
        /// @note Page 22
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode sec_sdram_die_count( uint8_t& o_value ) override;

        ///
        /// @brief Decodes Secondary SDRAM package type
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 10 (bit 7)
        /// @note Item JC-45-2220.01x
        /// @note Page 22
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode sec_sdram_package_type( uint8_t& o_value ) override;

        ///
        /// @brief Decodes number of package ranks per DIMM
        /// @param[out] o_value number of package ranks per DIMM
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 12 (bits 5~3)
        /// @note Item JC-45-2220.01x
        /// @note Page 23
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode num_package_ranks_per_dimm( uint8_t& o_value ) override;

        ///
        /// @brief Decodes Rank Mix
        /// @param[out] o_value rank mix value from SPD
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 12 (bit 6)
        /// @note Item JC-45-2220.01x
        /// @note Page 23
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode rank_mix( uint8_t& o_value ) override;

        ///
        /// @brief Decode CAS Latencies Supported
        /// @param[out] o_value bitmap of supported CAS latencies
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Bytes 20-23
        /// @note Item JC-45-2220.01x
        /// @note Page 33-34
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode supported_cas_latencies( uint64_t& o_value) override;

        ///
        /// @brief Decodes Minimum Write Recovery Time
        /// @param[out] o_value tWRmin in MTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 41 (bits 3~0) & Byte 42 (bits 7~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 40
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode min_write_recovery_time( int64_t& o_value ) override;

        ///
        /// @brief Decodes Minimum Write to Read Time - Different Bank Group
        /// @param[out] o_value tWRT_Smin in MTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 43 (bits 3~0) & Byte 44 (bits 7~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 40
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode min_twtr_s( int64_t& o_value ) override;

        ///
        /// @brief Decodes Minimum Write to Read Time - Same Bank Group
        /// @param[out] o_value tWRT_Lmin in MTB units
        /// @return FAPI2_RC_SUCCESS if okay
        /// @note SPD Byte 43 (bits 7~4) & Byte 45 (bits 7~0)
        /// @note Item JC-45-2220.01x
        /// @note Page 46
        /// @note DDR4 SPD Document Release 3
        ///
        virtual fapi2::ReturnCode min_twtr_l( int64_t& o_value ) override;

        ///
        /// @brief Returns Logical ranks per DIMM
        /// @param[out] o_logical_ranks number of logical ranks
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        virtual fapi2::ReturnCode logical_ranks_per_dimm( uint8_t& o_logical_rank_per_dimm ) override;

};// spd_decoder_v1_1

}// spd
}// mss

#endif //_MSSS_PD_DECODER_H_
