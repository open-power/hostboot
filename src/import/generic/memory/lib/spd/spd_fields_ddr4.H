/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/spd_fields_ddr4.H $         */
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
/// @file spd_fields_ddr4.H
/// @brief SPD data fields
///

// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_SPD_FIELDS_DDR4_H_
#define _MSS_SPD_FIELDS_DDR4_H_

#include <generic/memory/lib/spd/spd_field.H>

namespace mss
{
namespace spd
{

///
/// @class fields
/// @brief DDR4 SPD General Section fields
/// @note DDR4, BASE_CNFG specialization
///
/// @note Since these fields are used as non-type template params,
/// they need have external linkage. Currently C++11 can achieve this
/// by making them static constexpr member variables.
///
template <>
class fields<DDR4, BASE_CNFG>
{
    private:

        enum
        {
            // Byte 0
            BYTES_USED_START = 4,
            BYTES_USED_LEN = 4,

            BYTES_TOTAL_START = 1,
            BYTES_TOTAL_LEN = 3,

            // Byte 1
            REVISION_START = 0,
            REVISION_LEN = 8,

            // Byte 2
            DEVICE_TYPE_START = 0,
            DEVICE_TYPE_LEN = 8,

            // Byte 3
            HYBRID_START = 0,
            HYBRID_LEN = 1,
            HYBRID_MEDIA_START = 1,
            HYBRID_MEDIA_LEN = 3,
            BASE_MODULE_START = 4,
            BASE_MODULE_LEN = 4,

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
            SEC_SIGNAL_LOAD_START = 6,
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

            // Byte 18
            TCK_MIN_START = 0,
            TCK_MIN_LEN = 8,

            // Byte 19
            TCK_MAX_START = 0,
            TCK_MAX_LEN = 8,

            // Byte 20-23
            CAS_BYTE_1_START = 0,
            CAS_BYTE_1_LEN = 8,
            CAS_BYTE_2_START = 0,
            CAS_BYTE_2_LEN = 8,
            CAS_BYTE_3_START = 0,
            CAS_BYTE_3_LEN = 8,
            CAS_BYTE_4_START = 0,
            CAS_BYTE_4_LEN = 8,

            // Byte 24
            TAA_MIN_START = 0,
            TAA_MIN_LEN = 8,

            // Byte 25
            TRCD_MIN_START = 0,
            TRCD_MIN_LEN = 8,

            // Byte 26
            TRP_MIN_START = 0,
            TRP_MIN_LEN = 8,

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

            // Byte 38
            TRRD_S_MIN_START = 0,
            TRRD_S_MIN_LEN = 8,

            // Byte 39
            TRRD_L_MIN_START = 0,
            TRRD_L_MIN_LEN = 8,

            // Byte 40
            TCCD_L_MIN_START = 0,
            TCCD_L_MIN_LEN = 8,

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

            // Bytes 78 - 116 - reserved

            // Bytes 117
            OFFSET_TCCD_L_MIN_START = 0,
            OFFSET_TCCD_L_MIN_LEN = 8,

            // Bytes 118
            OFFSET_TRRD_L_MIN_START = 0,
            OFFSET_TRRD_L_MIN_LEN = 8,

            // Bytes 119
            OFFSET_TRRD_S_MIN_START = 0,
            OFFSET_TRRD_S_MIN_LEN = 8,

            // Byte 120
            OFFSET_TRC_MIN_START = 0,
            OFFSET_TRC_MIN_LEN = 8,

            // Byte 121
            OFFSET_TRP_MIN_START = 0,
            OFFSET_TRP_MIN_LEN = 8,

            // Byte 122
            OFFSET_TRCD_MIN_START = 0,
            OFFSET_TRCD_MIN_LEN = 8,

            // Byte 123
            OFFSET_TAA_MIN_START = 0,
            OFFSET_TAA_MIN_LEN = 8,

            // Byte 124
            OFFSET_TCK_MAX_START = 0,
            OFFSET_TCK_MAX_LEN = 8,

            // Byte 125
            OFFSET_TCK_MIN_START = 0,
            OFFSET_TCK_MIN_LEN = 8,

            // Byte 126
            CRC_LSB_START = 0,
            CRC_LSB_LEN = 8,

            // Byte 127
            CRC_MSB_START = 0,
            CRC_MSB_LEN = 8,

            // Byte 130
            REF_RAW_CARD_START = 0,
            REF_RAW_CARD_LEN = 8,

            // Byte 320
            CONTINUATION_CODES_START = 0,
            CONTINUATION_CODES_LEN = 8,

            // Byte 321
            LAST_NON_ZERO_BYTE_START = 0,
            LAST_NON_ZERO_BYTE_LEN = 8,

            // Byte 322
            MODULE_MFG_LOC_START = 0,
            MODULE_MFG_LOC_LEN = 8,

            // Bytes 323-324
            MODULE_MFG_DATE_START = 0,
            MODULE_MFG_DATE_LEN = 8,

            // Bytes 325-328
            MODULE_SERIAL_NUM_START = 0,
            MODULE_SERIAL_NUM_LEN = 8,

            // Byte 349
            MODULE_REV_CODE_START = 0,
            MODULE_REV_CODE_LEN = 8,

            // Byte 350-351
            DRAM_MFR_ID_CODE_START = 0,
            DRAM_MFR_ID_CODE_LEN = 8,

            // Byte 352
            DRAM_STEPPING_START = 0,
            DRAM_STEPPING_LEN = 8,
        };

    public:

        // 1st field: Byte number
        // 2nd field: Start bit
        // 3rd field: Bit length
        static constexpr mss::field_t<mss::endian::LITTLE> BYTES_USED{0, BYTES_USED_START, BYTES_USED_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> TOTAL_BYTES{0, BYTES_TOTAL_START, BYTES_TOTAL_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> REVISION{1, REVISION_START, REVISION_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> DEVICE_TYPE{2, DEVICE_TYPE_START, DEVICE_TYPE_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> BASE_MODULE{3, BASE_MODULE_START, BASE_MODULE_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> HYBRID{3, HYBRID_START, HYBRID_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> HYBRID_MEDIA{3, HYBRID_MEDIA_START, HYBRID_MEDIA_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> SDRAM_CAPACITY{4, SDRAM_CAPACITY_START, SDRAM_CAPACITY_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> BANKS_ADDR_BITS{4, SDRAM_BANKS_START, SDRAM_BANKS_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> BANK_GROUP_BITS{4, BANK_GROUP_START, BANK_GROUP_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> COL_ADDR_BITS{5, COL_ADDRESS_START, COL_ADDRESS_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> ROW_ADDR_BITS{5, ROW_ADDRESS_START, ROW_ADDRESS_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> PRIM_SIGNAL_LOADING{6, PRIM_SIGNAL_LOAD_START, PRIM_SIGNAL_LOAD_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> PRIM_DIE_COUNT{6, PRIM_DIE_COUNT_START, PRIM_DIE_COUNT_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> PRIM_PACKAGE_TYPE{6, PRIM_PACKAGE_TYPE_START, PRIM_PACKAGE_TYPE_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> MAC{7, MAC_START, MAC_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> TMAW{7, TMAW_START, TMAW_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> PPR{9, PPR_START, PPR_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> SOFT_PPR{9, SOFT_PPR_START, SOFT_PPR_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> SEC_SIGNAL_LOADING{10, SEC_SIGNAL_LOAD_START, SEC_SIGNAL_LOAD_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> SEC_DENSITY_RATIO{10, DENSITY_RATIO_START, DENSITY_RATIO_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> SEC_DIE_COUNT{10, SEC_DIE_COUNT_START, SEC_DIE_COUNT_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> SEC_PACKAGE_TYPE{10, SEC_PACKAGE_TYPE_START, SEC_PACKAGE_TYPE_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> OPERABLE_FLD{11, OPERABLE_START, OPERABLE_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> ENDURANT_FLD{11, ENDURANT_START, ENDURANT_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> SDRAM_WIDTH{12, SDRAM_WIDTH_START, SDRAM_WIDTH_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> RANK_MIX{12, RANK_MIX_START, RANK_MIX_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> PACKAGE_RANKS{12, PACKAGE_RANKS_START, PACKAGE_RANKS_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> BUS_WIDTH{13, BUS_WIDTH_START, BUS_WIDTH_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> BUS_EXT_WIDTH{13, BUS_EXT_WIDTH_START, BUS_EXT_WIDTH_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> THERM_SENSOR{14, THERM_SENSOR_START, THERM_SENSOR_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> EXTENDED_MODULE_TYPE{15, EXT_MOD_TYPE_START, EXT_MOD_TYPE_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> FINE_TIMEBASE{17, FINE_TIMEBASE_START, FINE_TIMEBASE_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> MEDIUM_TIMEBASE{17, MED_TIMEBASE_START, MED_TIMEBASE_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> TCK_MIN{18, TCK_MIN_START, TCK_MIN_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> TCK_MAX{19, TCK_MAX_START, TCK_MAX_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> CL_FIRST_BYTE{20, CAS_BYTE_1_START, CAS_BYTE_1_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> CL_SECOND_BYTE{21, CAS_BYTE_2_START, CAS_BYTE_2_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> CL_THIRD_BYTE{22, CAS_BYTE_3_START, CAS_BYTE_3_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> CL_FOURTH_BYTE{23, CAS_BYTE_4_START, CAS_BYTE_4_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> TAA_MIN{24, TAA_MIN_START, TAA_MIN_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> TRCD_MIN{25, TRCD_MIN_START, TRCD_MIN_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> TRP_MIN{26, TRP_MIN_START, TRP_MIN_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> TRASMIN_MSN{27, TRASMIN_MSN_START, TRASMIN_MSN_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> TRASMIN_LSB{28, TRASMIN_LSB_START, TRASMIN_LSB_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> TRCMIN_MSN{27, TRCMIN_MSN_START, TRCMIN_MSN_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> TRCMIN_LSB{29, TRCMIN_LSB_START, TRCMIN_LSB_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> TRFC1MIN_LSB{30, TRFC1MIN_LSB_START, TRFC1MIN_LSB_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> TRFC1MIN_MSB{31, TRFC1MIN_MSB_START, TRFC1MIN_MSB_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> TRFC2MIN_LSB{32, TRFC2MIN_LSB_START, TRFC2MIN_LSB_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> TRFC2MIN_MSB{33, TRFC2MIN_MSB_START, TRFC2MIN_MSB_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> TRFC4MIN_LSB{34, TRFC4MIN_LSB_START, TRFC4MIN_LSB_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> TRFC4MIN_MSB{35, TRFC4MIN_MSB_START, TRFC4MIN_MSB_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> TFAWMIN_MSN{36, TFAWMIN_MSN_START, TFAWMIN_MSN_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> TFAWMIN_LSB{37, TFAWMIN_LSB_START, TFAWMIN_LSB_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> TRRD_S_MIN{38, TRRD_S_MIN_START, TRRD_S_MIN_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> TRRD_L_MIN{39, TRRD_L_MIN_START, TRRD_L_MIN_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> TCCD_L_MIN{39, TCCD_L_MIN_START, TCCD_L_MIN_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> TWRMIN_MSN{41, TWRMIN_MSN_START, TWRMIN_MSN_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> TWRMIN_LSB{42, TWRMIN_LSB_START, TWRMIN_LSB_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> TWTRMIN_S_MSN{43, TWTRMIN_S_MSN_START, TWTRMIN_S_MSN_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> TWTRMIN_S_LSB{44, TWTRMIN_S_LSB_START, TWTRMIN_S_LSB_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> TWTRMIN_L_MSN{43, TWTRMIN_L_MSN_START, TWTRMIN_L_MSN_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> TWTRMIN_L_LSB{45, TWTRMIN_L_LSB_START, TWTRMIN_L_LSB_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> OFFSET_TCCD_L_MIN{117, OFFSET_TCCD_L_MIN_START, OFFSET_TCCD_L_MIN_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> OFFSET_TRRD_L_MIN{118, OFFSET_TRRD_L_MIN_START, OFFSET_TRRD_L_MIN_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> OFFSET_TRRD_S_MIN{119, OFFSET_TRRD_S_MIN_START, OFFSET_TRRD_S_MIN_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> OFFSET_TRC_MIN{120, OFFSET_TRC_MIN_START, OFFSET_TRC_MIN_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> OFFSET_TRP_MIN{121, OFFSET_TRP_MIN_START, OFFSET_TRP_MIN_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> OFFSET_TRCD_MIN{122, OFFSET_TRCD_MIN_START, OFFSET_TRCD_MIN_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> OFFSET_TAA_MIN{123, OFFSET_TAA_MIN_START, OFFSET_TAA_MIN_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> OFFSET_TCK_MAX{124, OFFSET_TCK_MAX_START, OFFSET_TCK_MAX_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> OFFSET_TCK_MIN{125, OFFSET_TCK_MIN_START, OFFSET_TCK_MIN_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> CRC_LSB{126, CRC_LSB_START, CRC_LSB_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> CRC_MSB{127, CRC_MSB_START, CRC_MSB_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> CONTINUATION_CODES{320, CONTINUATION_CODES_START, CONTINUATION_CODES_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> LAST_NON_ZERO_BYTE{321, LAST_NON_ZERO_BYTE_START, LAST_NON_ZERO_BYTE_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> MODULE_MFG_LOCATION{322, MODULE_MFG_LOC_START, MODULE_MFG_LOC_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> MODULE_MFG_DATE_LSB{323, MODULE_MFG_DATE_START, MODULE_MFG_DATE_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> MODULE_MFG_DATE_MSB{324, MODULE_MFG_DATE_START, MODULE_MFG_DATE_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> MODULE_SERIAL_NUM_BYTE1{325, MODULE_SERIAL_NUM_START, MODULE_SERIAL_NUM_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> MODULE_SERIAL_NUM_BYTE2{326, MODULE_SERIAL_NUM_START, MODULE_SERIAL_NUM_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> MODULE_SERIAL_NUM_BYTE3{327, MODULE_SERIAL_NUM_START, MODULE_SERIAL_NUM_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> MODULE_SERIAL_NUM_BYTE4{328, MODULE_SERIAL_NUM_START, MODULE_SERIAL_NUM_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> MODULE_REV_CODE{349, MODULE_REV_CODE_START, MODULE_REV_CODE_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> DRAM_MFR_ID_CODE_LSB{350, DRAM_MFR_ID_CODE_START, DRAM_MFR_ID_CODE_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> DRAM_MFR_ID_CODE_MSB{351, DRAM_MFR_ID_CODE_START, DRAM_MFR_ID_CODE_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> DRAM_STEPPING{352, DRAM_STEPPING_START, DRAM_STEPPING_LEN};
};

///
/// @class fields
/// @brief DDR4 RDIMM module SPD parameters
/// @note DDR4, RDIMM_MODULE specialization
///
template <>
class fields<DDR4, RDIMM_MODULE>
{
    private:

        enum
        {
            // Byte 128
            MODULE_NOM_HEIGHT_START = 3,
            MODULE_NOM_HEIGHT_LEN = 5,
            RAW_CARD_EXT_START = 0,
            RAW_CARD_EXT_LEN = 3,

            // Byte 129
            FRONT_MODULE_THICKNESS_START = 4,
            FRONT_MODULE_THICKNESS_LEN = 4,
            BACK_MODULE_THICKNESS_START = 0,
            BACK_MODULE_THICKNESS_LEN = 4,

            // Byte 130
            REF_RAW_CARD_START = 0,
            REF_RAW_CARD_LEN = 8,

            // Byte 131
            REGS_USED_START = 6,
            REGS_USED_LEN = 2,
            ROWS_OF_DRAMS_START = 4,
            ROWS_OF_DRAMS_LEN = 2,
            REGISTER_TYPE_START = 0,
            REGISTER_TYPE_LEN = 4,

            // Byte 132
            HEAT_SPREADER_CHAR_START = 1,
            HEAT_SPREADER_CHAR_LEN = 7,
            HEAT_SPREADER_SOL_START = 0,
            HEAT_SPREADER_SOL_LEN = 1,

            // Byte 133
            CONTINUATION_CODES_START = 0,
            CONTINUATION_CODES_LEN = 8,

            // Byte 134
            LAST_NON_ZERO_BYTE_START = 0,
            LAST_NON_ZERO_BYTE_LEN = 8,

            // Byte 135
            REGISTER_REV_START = 0,
            REGISTER_REV_LEN = 8,

            // Byte 136
            ADDR_MAPPING_START = 7,
            ADDR_MAPPING_LEN = 1,

            // Byte 137
            CKE_DRIVER_START = 6,
            CKE_DRIVER_LEN = 2,
            ODT_DRIVER_START = 4,
            ODT_DRIVER_LEN = 2,
            CA_DRIVER_START = 2,
            CA_DRIVER_LEN = 2,
            CS_DRIVER_START = 0,
            CS_DRIVER_LEN = 2,

            // Byte 138
            YO_Y2_DRIVER_START = 6,
            YO_Y2_DRIVER_LEN = 2,
            Y1_Y3_DRIVER_START = 4,
            Y1_Y3_DRIVER_LEN = 2,
        };

    public:

        // First field - SPD byte
        // Second field - start bit
        // Third field - bit length
        static constexpr mss::field_t<mss::endian::LITTLE> MODULE_NOMINAL_HEIGHT{128, MODULE_NOM_HEIGHT_START, MODULE_NOM_HEIGHT_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> RAW_CARD_EXTENSION{128, RAW_CARD_EXT_START, RAW_CARD_EXT_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> FRONT_MODULE_THICKNESS{129, FRONT_MODULE_THICKNESS_START, FRONT_MODULE_THICKNESS_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> BACK_MODULE_THICKNESS{129, BACK_MODULE_THICKNESS_START, BACK_MODULE_THICKNESS_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> REF_RAW_CARD{130, REF_RAW_CARD_START, REF_RAW_CARD_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> NUM_REGS_USED{131, REGS_USED_START, REGS_USED_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> ROWS_OF_DRAMS{131, ROWS_OF_DRAMS_START, ROWS_OF_DRAMS_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> REGISTER_TYPE{131, REGISTER_TYPE_START, REGISTER_TYPE_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> HEAT_SPREADER_CHAR{132, HEAT_SPREADER_CHAR_START, HEAT_SPREADER_CHAR_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> HEAT_SPREADER_SOL{132, HEAT_SPREADER_SOL_START, HEAT_SPREADER_SOL_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> CONTINUATION_CODES{133, CONTINUATION_CODES_START, CONTINUATION_CODES_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> LAST_NON_ZERO_BYTE{134, LAST_NON_ZERO_BYTE_START, LAST_NON_ZERO_BYTE_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> REGISTER_REV{135, REGISTER_REV_START, REGISTER_REV_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> ADDR_MAP_REG_TO_DRAM{136, ADDR_MAPPING_START, ADDR_MAPPING_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> CKE_DRIVER{137, CKE_DRIVER_START, CKE_DRIVER_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> ODT_DRIVER{137, ODT_DRIVER_START, ODT_DRIVER_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> CA_DRIVER{137, CA_DRIVER_START, CA_DRIVER_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> CS_DRIVER{137, CS_DRIVER_START, CS_DRIVER_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> YO_Y2_DRIVER{138, YO_Y2_DRIVER_START, YO_Y2_DRIVER_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> Y1_Y3_DRIVER{138, Y1_Y3_DRIVER_START, Y1_Y3_DRIVER_LEN};
};

///
/// @class fields
/// @brief DDR4 LRDIMM module SPD parameters
/// @note DDR4, LRDIMM_MODULE specialization
///
template <>
class fields<DDR4, LRDIMM_MODULE>
{
    private:

        enum
        {
            // Byte 128
            MODULE_NOM_HEIGHT_START = 3,
            MODULE_NOM_HEIGHT_LEN = 5,
            RAW_CARD_EXT_START = 0,
            RAW_CARD_EXT_LEN = 3,

            // Byte 129
            FRONT_MODULE_THICKNESS_START = 4,
            FRONT_MODULE_THICKNESS_LEN = 4,
            BACK_MODULE_THICKNESS_START = 0,
            BACK_MODULE_THICKNESS_LEN = 4,

            // Byte 130
            REF_RAW_CARD_START = 0,
            REF_RAW_CARD_LEN = 8,

            // Byte 131
            REGS_USED_START = 6,
            REGS_USED_LEN = 2,
            ROWS_OF_DRAMS_START = 4,
            ROWS_OF_DRAMS_LEN = 2,
            REGISTER_TYPE_START = 0,
            REGISTER_TYPE_LEN = 4,

            // Byte 132
            HEAT_SPREADER_CHAR_START = 1,
            HEAT_SPREADER_CHAR_LEN = 7,
            HEAT_SPREADER_SOL_START = 0,
            HEAT_SPREADER_SOL_LEN = 1,

            // Byte 133
            CONTINUATION_CODES_START = 0,
            CONTINUATION_CODES_LEN = 8,

            // Byte 134
            LAST_NON_ZERO_BYTE_START = 0,
            LAST_NON_ZERO_BYTE_LEN = 8,

            // Byte 135
            REGISTER_REV_START = 0,
            REGISTER_REV_LEN = 8,

            // Byte 136
            ADDR_MAPPING_START = 7,
            ADDR_MAPPING_LEN = 1,

            // Byte 137
            CKE_DRIVER_START = 6,
            CKE_DRIVER_LEN = 2,
            ODT_DRIVER_START = 4,
            ODT_DRIVER_LEN = 2,
            CA_DRIVER_START = 2,
            CA_DRIVER_LEN = 2,
            CS_DRIVER_START = 0,
            CS_DRIVER_LEN = 2,

            // Byte 138
            YO_Y2_DRIVER_START = 6,
            YO_Y2_DRIVER_LEN = 2,
            Y1_Y3_DRIVER_START = 4,
            Y1_Y3_DRIVER_LEN = 2,

            BCOM_BODT_BCKE_DRIVER_START = 3,
            BCOM_BODT_BCKE_DRIVER_LEN = 1,
            BCK_DRIVER_START = 2,
            BCK_DRIVER_LEN = 1,
            RCD_SLEW_CNTRL_START = 1,
            RCD_SLEW_CNTRL_LEN = 1,

            // Byte 139
            DB_REV_START = 0,
            DB_REV_LEN = 8,

            // Byte 140
            VREF_DQ_RANK0_START = 2,
            VREF_DQ_RANK0_LEN = 6,

            // Byte 141
            VREF_DQ_RANK1_START = 2,
            VREF_DQ_RANK1_LEN = 6,

            // Byte 142
            VREF_DQ_RANK2_START = 2,
            VREF_DQ_RANK2_LEN = 6,

            // Byte 143
            VREF_DQ_RANK3_START = 2,
            VREF_DQ_RANK3_LEN = 6,

            // Byte 144
            DB_VREF_DQ_START = 0,
            DB_VREF_DQ_LEN = 8,

            // Byte 145 - 147
            DB_MDQ_START = 1,
            DB_MDQ_LEN = 3,
            DB_MDQ_RTT_START = 5,
            DB_MDQ_RTT_LEN = 3,

            // Byte 148
            DRAM_DRIVE_1866_START = 6,
            DRAM_DRIVE_2400_START = 4,
            DRAM_DRIVE_3200_START = 2,
            DRAM_DRIVE_LEN = 2,

            // Byte 149 - 151
            DRAM_ODT_RTT_NOM_START = 5,
            DRAM_ODT_RTT_NOM_LEN = 3,
            DRAM_ODT_RTT_WR_START = 2,
            DRAM_ODT_RTT_WR_LEN = 3,

            // Bytes 152 - 154
            DRAM_ODT_RTT_PARK_R01_START = 5,
            DRAM_ODT_RTT_PARK_R01_LEN = 3,
            DRAM_ODT_RTT_PARK_R23_START = 2,
            DRAM_ODT_RTT_PARK_R23_LEN = 3,

            // Byte 155
            DRAM_VREF_DQ_RANGE_START = 4,
            DRAM_VREF_DQ_RANGE_LEN = 4,
            DB_VREF_DQ_RANGE_START = 3,
            DB_VREF_DQ_RANGE_LEN = 1,

            // Byte 156
            DB_GAIN_ADJUST_START = 7,
            DB_GAIN_ADJUST_LEN = 1,
            DB_DFE_START = 6,
            DB_DFE_LEN = 1,
        };

    public:

        // First field - SPD byte
        // Second field - start bit
        // Third field - bit length
        static constexpr mss::field_t<mss::endian::LITTLE> MODULE_NOMINAL_HEIGHT{128, MODULE_NOM_HEIGHT_START, MODULE_NOM_HEIGHT_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> RAW_CARD_EXT{128, RAW_CARD_EXT_START, RAW_CARD_EXT_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> FRONT_MODULE_THICKNESS{129, FRONT_MODULE_THICKNESS_START, FRONT_MODULE_THICKNESS_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> BACK_MODULE_THICKNESS{129, BACK_MODULE_THICKNESS_START, BACK_MODULE_THICKNESS_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> REF_RAW_CARD{130, REF_RAW_CARD_START, REF_RAW_CARD_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> NUM_REGS_USED{131, REGS_USED_START, REGS_USED_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> ROWS_OF_DRAMS{131, ROWS_OF_DRAMS_START, ROWS_OF_DRAMS_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> REGISTER_TYPE{131, REGISTER_TYPE_START, REGISTER_TYPE_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> HEAT_SPREADER_CHAR{132, HEAT_SPREADER_CHAR_START, HEAT_SPREADER_CHAR_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> HEAT_SPREADER_SOL{132, HEAT_SPREADER_SOL_START, HEAT_SPREADER_SOL_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> CONTINUATION_CODES{133, CONTINUATION_CODES_START, CONTINUATION_CODES_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> LAST_NON_ZERO_BYTE{134, LAST_NON_ZERO_BYTE_START, LAST_NON_ZERO_BYTE_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> REGISTER_REV{135, REGISTER_REV_START, REGISTER_REV_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> ADDR_MAP_REG_TO_DRAM{136, ADDR_MAPPING_START, ADDR_MAPPING_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> CKE_DRIVER{137, CKE_DRIVER_START, CKE_DRIVER_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> ODT_DRIVER{137, ODT_DRIVER_START, ODT_DRIVER_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> CA_DRIVER{137, CA_DRIVER_START, CA_DRIVER_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> CS_DRIVER{137, CS_DRIVER_START, CS_DRIVER_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> YO_Y2_DRIVER{138, YO_Y2_DRIVER_START, YO_Y2_DRIVER_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> Y1_Y3_DRIVER{138, Y1_Y3_DRIVER_START, Y1_Y3_DRIVER_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> DATA_BUFFER_REV{139, DB_REV_START, DB_REV_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> BCOM_BODT_BCKE_DRIVER{138, BCOM_BODT_BCKE_DRIVER_START, BCOM_BODT_BCKE_DRIVER_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> BCK_DRIVER{138, BCK_DRIVER_START, BCK_DRIVER_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> RCD_SLEW_CNTRL{138, RCD_SLEW_CNTRL_START, RCD_SLEW_CNTRL_LEN };
        static constexpr mss::field_t<mss::endian::LITTLE> VREF_DQ_RANK0{140, VREF_DQ_RANK0_START, VREF_DQ_RANK0_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> VREF_DQ_RANK1{141, VREF_DQ_RANK1_START, VREF_DQ_RANK1_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> VREF_DQ_RANK2{142, VREF_DQ_RANK2_START, VREF_DQ_RANK2_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> VREF_DQ_RANK3{143, VREF_DQ_RANK3_START, VREF_DQ_RANK3_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> DATA_BUFFER_VREF_DQ{144, DB_VREF_DQ_START, DB_VREF_DQ_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> DB_MDQ_LTE_1866{145, DB_MDQ_START, DB_MDQ_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> DB_MDQ_LTE_2400{146, DB_MDQ_START, DB_MDQ_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> DB_MDQ_LTE_3200{147, DB_MDQ_START, DB_MDQ_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> DB_MDQ_RTT_LTE_1866{145, DB_MDQ_RTT_START, DB_MDQ_RTT_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> DB_MDQ_RTT_LTE_2400{146, DB_MDQ_RTT_START, DB_MDQ_RTT_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> DB_MDQ_RTT_LTE_3200{147, DB_MDQ_RTT_START, DB_MDQ_RTT_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> DRAM_DRIVE_STRENGTH_LTE_1866{148, DRAM_DRIVE_1866_START, DRAM_DRIVE_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> DRAM_DRIVE_STRENGTH_LTE_2400{148, DRAM_DRIVE_2400_START, DRAM_DRIVE_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> DRAM_DRIVE_STRENGTH_LTE_3200{148, DRAM_DRIVE_3200_START, DRAM_DRIVE_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> DRAM_ODT_RTT_NOM_LTE_1866{149, DRAM_ODT_RTT_NOM_START, DRAM_ODT_RTT_NOM_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> DRAM_ODT_RTT_WR_LTE_1866{149, DRAM_ODT_RTT_WR_START, DRAM_ODT_RTT_WR_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> DRAM_ODT_RTT_NOM_LTE_2400{150, DRAM_ODT_RTT_NOM_START, DRAM_ODT_RTT_NOM_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> DRAM_ODT_RTT_WR_LTE_2400{150, DRAM_ODT_RTT_WR_START, DRAM_ODT_RTT_WR_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> DRAM_ODT_RTT_NOM_LTE_3200{151, DRAM_ODT_RTT_NOM_START, DRAM_ODT_RTT_NOM_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> DRAM_ODT_RTT_WR_LTE_3200{151, DRAM_ODT_RTT_WR_START, DRAM_ODT_RTT_WR_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> DRAM_ODT_RTT_PARK_R01_LTE_1866{152, DRAM_ODT_RTT_PARK_R01_START, DRAM_ODT_RTT_PARK_R01_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> DRAM_ODT_RTT_PARK_R23_LTE_1866{152, DRAM_ODT_RTT_PARK_R23_START, DRAM_ODT_RTT_PARK_R23_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> DRAM_ODT_RTT_PARK_R01_LTE_2400{153, DRAM_ODT_RTT_PARK_R01_START, DRAM_ODT_RTT_PARK_R01_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> DRAM_ODT_RTT_PARK_R23_LTE_2400{153, DRAM_ODT_RTT_PARK_R23_START, DRAM_ODT_RTT_PARK_R23_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> DRAM_ODT_RTT_PARK_R01_LTE_3200{154, DRAM_ODT_RTT_PARK_R01_START, DRAM_ODT_RTT_PARK_R01_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> DRAM_ODT_RTT_PARK_R23_LTE_3200{154, DRAM_ODT_RTT_PARK_R23_START, DRAM_ODT_RTT_PARK_R23_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> DRAM_VREF_DQ_RANGE{155, DRAM_VREF_DQ_RANGE_START, DRAM_VREF_DQ_RANGE_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> DATA_BUFFER_VREF_DQ_RANGE{155, DB_VREF_DQ_RANGE_START, DB_VREF_DQ_RANGE_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> DATA_BUFFER_GAIN_ADJUST{156, DB_GAIN_ADJUST_START, DB_GAIN_ADJUST_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> DATA_BUFFER_DFE{156, DB_DFE_START, DB_DFE_LEN};
};

///
/// @class fields
/// @brief DDR4 DDIMM module SPD parameters
/// @note DDR4, DDIMM_MODULE specialization
///
template <>
class fields<DDR4, DDIMM_MODULE>
{
    private:

        enum
        {

            // Byte 192: SPD Revision DDIMM Module Type (bytes 192->447)
            SPD_REV_DDIMM_MODULE_BYTE = 192,
            SPD_REV_DDIMM_MODULE_START = 0,
            SPD_REV_DDIMM_MODULE_LEN = 8,

            // Byte 193: Module Height
            MODULE_HEIGHT_BYTE = 193,
            MODULE_BASE_HEIGHT_START = 0,
            MODULE_BASE_HEIGHT_LEN = 3,
            MODULE_HEIGHT_MAX_START = 3,
            MODULE_HEIGHT_MAX_LEN = 5,

            // Byte 194: Module Maximum Thickness
            MODULE_THICKNESS_BYTE = 194,
            MAX_THICKNESS_BACK_START = 0,
            MAX_THICKNESS_BACK_LEN = 4,
            MAX_THICKNESS_FRONT_START = 4,
            MAX_THICKNESS_FRONT_LEN = 4,

            // Byte 195: Reference Raw Card used
            REF_RAW_CARD_BYTE = 195,
            DESIGN_REV_START = 0,
            DESIGN_REV_LEN = 8,

            // Byte 196: DIMM attributes
            DIMM_ATTR_BYTE = 196,
            NUM_ROWS_START = 4,
            NUM_ROWS_LEN = 2,
            NUM_BUFFERS_START = 6,
            NUM_BUFFERS_LEN = 2,

            // Byte 197: Thermal Heat Spreader Solution
            THERMAL_BYTE = 197,
            HEAT_SPREADER_SOL_START = 0,
            HEAT_SPREADER_SOL_LEN = 1,
            HEAT_SPREADER_CHAR_START = 1,
            HEAT_SPREADER_CHAR_LEN = 7,

            // Byte 198: DMB Manfacture ID code 1st byte
            DMB_MFG_CODE1_BYTE = 198,
            CONTINUATION_CODE_START = 0,
            CONTINUATION_CODE_LEN = 8,

            // Byte 199: DMB Manfacture ID code 2nd byte
            DMB_MFG_CODE2_BYTE = 199,
            LAST_NON_ZERO_START = 0,
            LAST_NON_ZERO_LEN = 8,

            // Byte 200: DMB Revision Number
            DMB_REV_BYTE = 200,
            DMB_REV_START = 0,
            DMB_REV_LEN = 8,

            // Byte 201: DIMM Module Oranization
            DIMM_ORG_BYTE_BYTE = 201,
            RANK_MIX_START = 1,
            RANK_MIX_LEN = 1,
            PACKAGE_RANK_START = 2,
            PACKAGE_RANK_LEN = 3,
            DATA_WIDTH_START = 5,
            DATA_WIDTH_LEN = 3,

            // Byte 202: Memory Channel Bus Width
            BUS_WIDTH_BYTE = 202,
            NUM_DIMM_CHANNELS_START = 0,
            NUM_DIMM_CHANNELS_LEN = 2,
            BUS_WIDTH_EXT_START = 2,
            BUS_WIDTH_EXT_LEN = 3,
            CHANNEL_DATA_WIDTH_START = 5,
            CHANNEL_DATA_WIDTH_LEN = 3,

            // Byte 203: Module Thermal Sensors
            THERMAL_SENSORS_BYTE = 203,
            MOD_THERMAL_SENSOR_START = 0,
            MOD_THERMAL_SENSOR_LEN = 3,

            // Byte 204: Host Interface Protocols
            PROTOCOL_SUPPORT_BYTE = 204,
            PROTOCOL_SUPPORT_START = 4,
            PROTOCOL_SUPPORT_LEN = 4,

            // Byte 205: Host Interface Speed Supported
            SPEED_SUPPORTED_LSB_BYTE = 205,
            SPEED_SUPPORTED_LSB_START = 1,
            SPEED_SUPPORTED_LSB_LEN = 7,

            // Byte 207: Address Mirroring
            ADDRESS_MIRROR_BYTE = 207,
            ADDRESS_MIRROR_START = 4,
            ADDRESS_MIRROR_LEN = 4,

            // Byte 208: Byte enables LSB
            BYTE_ENABLES_LSB_BYTE = 208,
            BYTE_ENABLES_LSB_START = 0,
            BYTE_ENABLES_LSB_LEN = 8,

            // Byte 209: Byte enables MSB
            BYTE_ENABLES_MSB_BYTE = 209,
            BYTE_ENABLES_MSB_START = 6,
            BYTE_ENABLES_MSB_LEN = 2,

            // Byte 210: Nibble enables LSB0
            NIBBLE_ENABLES_LSB0_BYTE = 210,
            NIBBLE_ENABLES_LSB0_START = 0,
            NIBBLE_ENABLES_LSB0_LEN = 8,

            // Byte 211: Nibble enables MSB0
            NIBBLE_ENABLES_MSB0_BYTE = 211,
            NIBBLE_ENABLES_MSB0_START = 0,
            NIBBLE_ENABLES_MSB0_LEN = 8,

            // Byte 212: Nibble enables LSB1
            NIBBLE_ENABLES_LSB1_BYTE = 212,
            NIBBLE_ENABLES_LSB1_START = 4,
            NIBBLE_ENABLES_LSB1_LEN = 4,

            // Byte 214: Four Rank Mode - DDP Compatibility - TSV 8 High Support - MRAM Support
            DDIMM_COMPAT_BYTE = 214,
            DDIMM_COMPAT_START = 4,
            DDIMM_COMPAT_LEN = 4,

            // Byte 215: Number of P-States
            NUM_P_STATES_BYTE = 215,
            NUM_P_STATES_START = 4,
            NUM_P_STATES_LEN = 4,

            // Byte 216: Spare Device Mapping LSB0
            SPARE_DEVICE_LSB0_BYTE = 216,
            SPARE_DEVICE_LSB0_START = 0,
            SPARE_DEVICE_LSB0_LEN = 8,

            // Byte 217: Spare Device Mapping MSB0
            SPARE_DEVICE_MSB0_BYTE = 217,
            SPARE_DEVICE_MSB0_START = 0,
            SPARE_DEVICE_MSB0_LEN = 8,

            // Byte 218: Spare Device Mapping LSB1
            SPARE_DEVICE_LSB1_BYTE = 218,
            SPARE_DEVICE_LSB1_START = 4,
            SPARE_DEVICE_LSB1_LEN = 4,

            // Byte 220: Host Interface Speed to DDR Interface Speed Ratio
            HI_DDR_SPEED_RATIO_BYTE = 220,
            HI_DDR_SPEED_RATIO_START = 4,
            HI_DDR_SPEED_RATIO_LEN = 4,

            // Byte 224: Voltage VIN_MTG Edge connector
            VIN_MGMT_BYTE = 224,
            VIN_MGMT_NOMINAL_START = 0,
            VIN_MGMT_NOMINAL_LEN = 4,
            VIN_MGMT_OPERABLE_START = 4,
            VIN_MGMT_OPERABLE_LEN = 2,
            VIN_MGMT_ENDURANT_START = 6,
            VIN_MGMT_ENDURANT_LEN = 2,

            // Byte 225: Voltage VIN_BULK Edge Connecto
            VIN_BULK_BYTE = 225,
            VIN_BULK_NOMINAL_START = 0,
            VIN_BULK_NOMINAL_LEN = 4,
            VIN_BULK_OPERABLE_START = 4,
            VIN_BULK_OPERABLE_LEN = 2,
            VIN_BULK_ENDURANT_START = 6,
            VIN_BULK_ENDURANT_LEN = 2,

            // Byte 226: PMIC0 Sequence
            PMIC0_SEQUENCE_BYTE = 226,
            PMIC0_SEQUENCE_START = 0,
            PMIC0_SEQUENCE_LEN = 8,

            // Byte 227: PMIC0 Manfacture ID code 1st byte
            PMIC0_MFG_CODE1_BYTE = 227,
            PMIC0_CONT_CODE_START = 0,
            PMIC0_CONT_CODE_LEN = 8,

            // Byte 228: PMIC0 Manfacture ID code 2nd byte
            PMIC0_MFG_CODE2_BYTE = 228,
            PMIC0_LAST_NON_ZERO_START = 0,
            PMIC0_LAST_NON_ZERO_LEN = 8,

            // Byte 229: PMIC0 Revision Number
            PMIC0_REV_BYTE = 229,
            PMIC0_REV_START = 0,
            PMIC0_REV_LEN = 8,

            // Byte 230: PMIC1 Sequence
            PMIC1_SEQUENCE_BYTE = 230,
            PMIC1_SEQUENCE_START = 0,
            PMIC1_SEQUENCE_LEN = 8,

            // Byte 231: PMIC1 Manfacture ID code 1st byte
            PMIC1_MFG_CODE1_BYTE = 231,
            PMIC1_CONT_CODE_START = 0,
            PMIC1_CONT_CODE_LEN = 8,

            // Byte 232: PMIC1 Manfacture ID code 2nd byte
            PMIC1_MFG_CODE2_BYTE = 232,
            PMIC1_LAST_NON_ZERO_START = 0,
            PMIC1_LAST_NON_ZERO_LEN = 8,

            // Byte 233: PMIC1 Revision Number
            PMIC1_REV_BYTE = 233,
            PMIC1_REV_START = 0,
            PMIC1_REV_LEN = 8,

            // Byte 234: PMIC0 SWA Voltage Setting
            PMIC0_SWA_VOLT_SET_BYTE = 234,
            PMIC0_SWA_VOLT_SET_START = 0,
            PMIC0_SWA_VOLT_SET_LEN = 7,
            PMIC0_SWA_RANGE_SELECT_START = 7,
            PMIC0_SWA_RANGE_SELECT_LEN = 1,

            // Byte 235: PMIC0 SWA Voltage Offset
            PMIC0_SWA_VOLT_OFF_BYTE = 235,
            PMIC0_SWA_VOLT_OFF_START = 0,
            PMIC0_SWA_VOLT_OFF_LEN = 7,
            PMIC0_SWA_OFF_DIRECTION_START = 7,
            PMIC0_SWA_OFF_DIRECTION_LEN = 1,

            // Byte 236: PMIC0 SWA Delay Sequence Order
            PMIC0_SWA_DELAY_BYTE = 236,
            PMIC0_SWA_DELAY_START = 0,
            PMIC0_SWA_DELAY_LEN = 4,
            PMIC0_SWA_ORDER_START = 4,
            PMIC0_SWA_ORDER_LEN = 4,

            // Byte 237: PMIC0 SWB Voltage Setting
            PMIC0_SWB_VOLT_SET_BYTE = 237,
            PMIC0_SWB_VOLT_SET_START = 0,
            PMIC0_SWB_VOLT_SET_LEN = 7,
            PMIC0_SWB_RANGE_SELECT_START = 7,
            PMIC0_SWB_RANGE_SELECT_LEN = 1,

            // Byte 238: PMIC0 SWB Voltage Offset
            PMIC0_SWB_VOLT_OFF_BYTE = 238,
            PMIC0_SWB_VOLT_OFF_START = 0,
            PMIC0_SWB_VOLT_OFF_LEN = 7,
            PMIC0_SWB_OFF_DIRECTION_START = 7,
            PMIC0_SWB_OFF_DIRECTION_LEN = 1,

            // Byte 239: PMIC0 SWB Delay Sequence Order
            PMIC0_SWB_DELAY_BYTE = 239,
            PMIC0_SWB_DELAY_START = 0,
            PMIC0_SWB_DELAY_LEN = 4,
            PMIC0_SWB_ORDER_START = 4,
            PMIC0_SWB_ORDER_LEN = 4,

            // Byte 240: PMIC0 SWC Voltage Setting
            PMIC0_SWC_VOLT_SET_BYTE = 240,
            PMIC0_SWC_VOLT_SET_START = 0,
            PMIC0_SWC_VOLT_SET_LEN = 7,
            PMIC0_SWC_RANGE_SELECT_START = 7,
            PMIC0_SWC_RANGE_SELECT_LEN = 1,

            // Byte 241: PMIC0 SWC Voltage Offset
            PMIC0_SWC_VOLT_OFF_BYTE = 241,
            PMIC0_SWC_VOLT_OFF_START = 0,
            PMIC0_SWC_VOLT_OFF_LEN = 7,
            PMIC0_SWC_OFF_DIRECTION_START = 7,
            PMIC0_SWC_OFF_DIRECTION_LEN = 1,

            // Byte 242: PMIC0 SWC Delay Sequence Order
            PMIC0_SWC_DELAY_BYTE = 242,
            PMIC0_SWC_DELAY_START = 0,
            PMIC0_SWC_DELAY_LEN = 4,
            PMIC0_SWC_ORDER_START = 4,
            PMIC0_SWC_ORDER_LEN = 4,

            // Byte 243: PMIC0 SWD Voltage Setting
            PMIC0_SWD_VOLT_SET_BYTE = 243,
            PMIC0_SWD_VOLT_SET_START = 0,
            PMIC0_SWD_VOLT_SET_LEN = 7,
            PMIC0_SWD_RANGE_SELECT_START = 7,
            PMIC0_SWD_RANGE_SELECT_LEN = 1,

            // Byte 244: PMIC0 SWD Voltage Offset
            PMIC0_SWD_VOLT_OFF_BYTE = 244,
            PMIC0_SWD_VOLT_OFF_START = 0,
            PMIC0_SWD_VOLT_OFF_LEN = 7,
            PMIC0_SWD_OFF_DIRECTION_START = 7,
            PMIC0_SWD_OFF_DIRECTION_LEN = 1,

            // Byte 245: PMIC0 SWD Delay Sequence Order
            PMIC0_SWD_DELAY_BYTE = 245,
            PMIC0_SWD_DELAY_START = 0,
            PMIC0_SWD_DELAY_LEN = 4,
            PMIC0_SWD_ORDER_START = 4,
            PMIC0_SWD_ORDER_LEN = 4,

            // Byte 246: PMIC0 Phase Combination and redundancy
            PMIC0_PHASE_COMBIN_BYTE = 246,
            PMIC0_REDUNDANCY_START = 0,
            PMIC0_REDUNDANCY_LEN = 1,
            PMIC0_PHASE_COMBIN_START = 4,
            PMIC0_PHASE_COMBIN_LEN = 4,

            // Byte 247: PMIC1 SWA Voltage Setting
            PMIC1_SWA_VOLT_SET_BYTE = 247,
            PMIC1_SWA_VOLT_SET_START = 0,
            PMIC1_SWA_VOLT_SET_LEN = 7,
            PMIC1_SWA_RANGE_SELECT_START = 7,
            PMIC1_SWA_RANGE_SELECT_LEN = 1,

            // Byte 248: PMIC1 SWA Voltage Offset
            PMIC1_SWA_VOLT_OFF_BYTE = 248,
            PMIC1_SWA_VOLT_OFF_START = 0,
            PMIC1_SWA_VOLT_OFF_LEN = 7,
            PMIC1_SWA_OFF_DIRECTION_START = 7,
            PMIC1_SWA_OFF_DIRECTION_LEN = 1,

            // Byte 249: PMIC1 SWA Delay Sequence Order
            PMIC1_SWA_DELAY_BYTE = 249,
            PMIC1_SWA_DELAY_START = 0,
            PMIC1_SWA_DELAY_LEN = 4,
            PMIC1_SWA_ORDER_START = 4,
            PMIC1_SWA_ORDER_LEN = 4,

            // Byte 250: PMIC1 SWB Voltage Setting
            PMIC1_SWB_VOLT_SET_BYTE = 250,
            PMIC1_SWB_VOLT_SET_START = 0,
            PMIC1_SWB_VOLT_SET_LEN = 7,
            PMIC1_SWB_RANGE_SELECT_START = 7,
            PMIC1_SWB_RANGE_SELECT_LEN = 1,

            // Byte 251: PMIC1 SWB Voltage Offset
            PMIC1_SWB_VOLT_OFF_BYTE = 251,
            PMIC1_SWB_VOLT_OFF_START = 0,
            PMIC1_SWB_VOLT_OFF_LEN = 7,
            PMIC1_SWB_OFF_DIRECTION_START = 7,
            PMIC1_SWB_OFF_DIRECTION_LEN = 1,

            // Byte 252: PMIC1 SWB Delay Sequence Order
            PMIC1_SWB_DELAY_BYTE = 252,
            PMIC1_SWB_DELAY_START = 0,
            PMIC1_SWB_DELAY_LEN = 4,
            PMIC1_SWB_ORDER_START = 4,
            PMIC1_SWB_ORDER_LEN = 4,

            // Byte 253: PMIC1 SWC Voltage Setting
            PMIC1_SWC_VOLT_SET_BYTE = 253,
            PMIC1_SWC_VOLT_SET_START = 0,
            PMIC1_SWC_VOLT_SET_LEN = 7,
            PMIC1_SWC_RANGE_SELECT_START = 7,
            PMIC1_SWC_RANGE_SELECT_LEN = 1,

            // Byte 254: PMIC1 SWC Voltage Offset
            PMIC1_SWC_VOLT_OFF_BYTE = 254,
            PMIC1_SWC_VOLT_OFF_START = 0,
            PMIC1_SWC_VOLT_OFF_LEN = 7,
            PMIC1_SWC_OFF_DIRECTION_START = 7,
            PMIC1_SWC_OFF_DIRECTION_LEN = 1,

            // Byte 255: PMIC1 SWC Delay Sequence Order
            PMIC1_SWC_DELAY_BYTE = 255,
            PMIC1_SWC_DELAY_START = 0,
            PMIC1_SWC_DELAY_LEN = 4,
            PMIC1_SWC_ORDER_START = 4,
            PMIC1_SWC_ORDER_LEN = 4,

            // Byte 256: PMIC1 SWD Voltage Setting
            PMIC1_SWD_VOLT_SET_BYTE = 256,
            PMIC1_SWD_VOLT_SET_START = 0,
            PMIC1_SWD_VOLT_SET_LEN = 7,
            PMIC1_SWD_RANGE_SELECT_START = 7,
            PMIC1_SWD_RANGE_SELECT_LEN = 1,

            // Byte 257: PMIC1 SWD Voltage Offset
            PMIC1_SWD_VOLT_OFF_BYTE = 257,
            PMIC1_SWD_VOLT_OFF_START = 0,
            PMIC1_SWD_VOLT_OFF_LEN = 7,
            PMIC1_SWD_OFF_DIRECTION_START = 7,
            PMIC1_SWD_OFF_DIRECTION_LEN = 1,

            // Byte 258: PMIC1 SWD Delay Sequence Order
            PMIC1_SWD_DELAY_BYTE = 258,
            PMIC1_SWD_DELAY_START = 0,
            PMIC1_SWD_DELAY_LEN = 4,
            PMIC1_SWD_ORDER_START = 4,
            PMIC1_SWD_ORDER_LEN = 4,

            // Byte 259: PMIC1 Phase Combination and Redundancy
            PMIC1_PHASE_COMBIN_BYTE = 259,
            PMIC1_REDUNDANCY_START = 0,
            PMIC1_REDUNDANCY_LEN = 1,
            PMIC1_PHASE_COMBIN_START = 4,
            PMIC1_PHASE_COMBIN_LEN = 4,

            // Byte 264
            MODULE_RCD_BYTE = 264,
            MODULE_RCD_START = 6,
            MODULE_RCD_LEN = 2,

            // Byte 268: Thermal Sensor 0 Profile
            THERM_SENSOR_0_PROFILE_BYTE = 268,
            THERM_SENSOR_0_AVAIL_START = 0,
            THERM_SENSOR_0_AVAIL_LEN = 1,
            THERM_SENSOR_0_TYPE_START = 1,
            THERM_SENSOR_0_TYPE_LEN = 4,
            THERM_SENSOR_0_USAGE_START = 5,
            THERM_SENSOR_0_USAGE_LEN = 3,

            // Byte 269: Thermal Sensor 0 I2C Address
            THERM_SENSOR_0_I2C_ADDRESS_BYTE = 269,
            THERM_SENSOR_0_I2C_ADDRESS_START = 0,
            THERM_SENSOR_0_I2C_ADDRESS_LEN = 8,

            // Byte 270: Thermal Sensor 1 Profile
            THERM_SENSOR_1_PROFILE_BYTE = 270,
            THERM_SENSOR_1_AVAIL_START = 0,
            THERM_SENSOR_1_AVAIL_LEN = 1,
            THERM_SENSOR_1_TYPE_START = 1,
            THERM_SENSOR_1_TYPE_LEN = 4,
            THERM_SENSOR_1_USAGE_START = 5,
            THERM_SENSOR_1_USAGE_LEN = 3,

            // Byte 271: Thermal Sensor 1 I2C Address
            THERM_SENSOR_1_I2C_ADDRESS_BYTE = 271,
            THERM_SENSOR_1_I2C_ADDRESS_START = 0,
            THERM_SENSOR_1_I2C_ADDRESS_LEN = 8,

            // Byte 272: Differential Buffer Thermal Sensor Profile
            THERM_SENSOR_DIFF_PROFILE_BYTE = 272,
            THERM_SENSOR_DIFF_AVAIL_START = 0,
            THERM_SENSOR_DIFF_AVAIL_LEN = 1,
            THERM_SENSOR_DIFF_TYPE_START = 1,
            THERM_SENSOR_DIFF_TYPE_LEN = 4,
            THERM_SENSOR_DIFF_USAGE_START = 5,
            THERM_SENSOR_DIFF_USAGE_LEN = 3,

            // Byte 273: Differential Buffer Thermal Sensor I2C Address
            THERM_SENSOR_DIFF_I2C_ADDRESS_BYTE = 273,
            THERM_SENSOR_DIFF_I2C_ADDRESS_START = 0,
            THERM_SENSOR_DIFF_I2C_ADDRESS_LEN = 8,

            // Byte 512-513
            MODULE_MFG_ID_CODE_LSB_BYTE = 512,
            MODULE_MFG_ID_CODE_MSB_BYTE = 513,
            MODULE_MFG_ID_CODE_START = 0,
            MODULE_MFG_ID_CODE_LEN = 8,

            // Byte 552-553
            DRAM_MFR_ID_CODE_LSB_BYTE = 552,
            DRAM_MFR_ID_CODE_MSB_BYTE = 553,
            DRAM_MFR_ID_CODE_START = 0,
            DRAM_MFR_ID_CODE_LEN = 8,
        };

    public:
        // Syntatic sugar to make member variable declaration easier
        using field_t = mss::field_t<mss::endian::LITTLE>;

        // First field - SPD byte
        // Second field - start bit
        // Third field - bit length

        // Byte 192: SPD Revision DDIMM Module Bytes (192->447)
        static constexpr field_t SPD_REV_DDIMM_MODULE{SPD_REV_DDIMM_MODULE_BYTE, SPD_REV_DDIMM_MODULE_START, SPD_REV_DDIMM_MODULE_LEN};

        // Byte 193: Module Height
        static constexpr field_t MODULE_BASE_HEIGHT{MODULE_HEIGHT_BYTE, MODULE_BASE_HEIGHT_START, MODULE_BASE_HEIGHT_LEN};
        static constexpr field_t MODULE_HEIGHT_MAX{MODULE_HEIGHT_BYTE, MODULE_HEIGHT_MAX_START, MODULE_HEIGHT_MAX_LEN};

        // Byte 194: Module Maximum Thickness
        static constexpr field_t MAX_THICKNESS_BACK{MODULE_THICKNESS_BYTE, MAX_THICKNESS_BACK_START, MAX_THICKNESS_BACK_LEN};
        static constexpr field_t MAX_THICKNESS_FRONT{MODULE_THICKNESS_BYTE, MAX_THICKNESS_FRONT_START, MAX_THICKNESS_FRONT_LEN};

        // Byte 195: Reference Raw Card used
        static constexpr field_t DESIGN_REV{REF_RAW_CARD_BYTE, DESIGN_REV_START, DESIGN_REV_LEN};

        // Byte 196: DIMM attributes
        static constexpr field_t NUM_ROWS{DIMM_ATTR_BYTE, NUM_ROWS_START, NUM_ROWS_LEN};
        static constexpr field_t NUM_BUFFERS{DIMM_ATTR_BYTE, NUM_BUFFERS_START, NUM_BUFFERS_LEN};

        // Byte 197: Thermal Heat Spreader Solution
        static constexpr field_t HEAT_SPREADER_SOL{THERMAL_BYTE, HEAT_SPREADER_SOL_START, HEAT_SPREADER_SOL_LEN};
        static constexpr field_t HEAT_SPREADER_CHAR{THERMAL_BYTE, HEAT_SPREADER_CHAR_START, HEAT_SPREADER_CHAR_LEN};

        // Byte 198: DMB Manfacture ID code 1st byte
        static constexpr field_t CONTINUATION_CODE{DMB_MFG_CODE1_BYTE, CONTINUATION_CODE_START, CONTINUATION_CODE_LEN};

        // Byte 199: DMB Manfacture ID code 2nd byte
        static constexpr field_t LAST_NON_ZERO{DMB_MFG_CODE2_BYTE, LAST_NON_ZERO_START, LAST_NON_ZERO_LEN};

        // Byte 200: DMB Revision Number
        static constexpr field_t DMB_REV{DMB_REV_BYTE, DMB_REV_START, DMB_REV_LEN};

        // Byte 201: DIMM Module Oranization
        static constexpr field_t RANK_MIX{DIMM_ORG_BYTE_BYTE, RANK_MIX_START, RANK_MIX_LEN};
        static constexpr field_t PACKAGE_RANK{DIMM_ORG_BYTE_BYTE, PACKAGE_RANK_START, PACKAGE_RANK_LEN};
        static constexpr field_t DATA_WIDTH{DIMM_ORG_BYTE_BYTE, DATA_WIDTH_START, DATA_WIDTH_LEN};

        // Byte 202: Memory Channel Bus Width
        static constexpr field_t NUM_DIMM_CHANNELS{BUS_WIDTH_BYTE, NUM_DIMM_CHANNELS_START, NUM_DIMM_CHANNELS_LEN};
        static constexpr field_t BUS_WIDTH_EXT{BUS_WIDTH_BYTE, BUS_WIDTH_EXT_START, BUS_WIDTH_EXT_LEN};
        static constexpr field_t CHANNEL_DATA_WIDTH{BUS_WIDTH_BYTE, CHANNEL_DATA_WIDTH_START, CHANNEL_DATA_WIDTH_LEN};

        // Byte 203: Module Thermal Sensors
        static constexpr field_t MOD_THERMAL_SENSOR{THERMAL_SENSORS_BYTE, MOD_THERMAL_SENSOR_START, MOD_THERMAL_SENSOR_LEN};

        // Byte 204: Host Interface Protocols
        static constexpr field_t PROTOCOL_SUPPORT{PROTOCOL_SUPPORT_BYTE, PROTOCOL_SUPPORT_START, PROTOCOL_SUPPORT_LEN};

        // Byte 205: Host Interface Speed Supported
        static constexpr field_t SPEED_SUPPORTED_LSB{SPEED_SUPPORTED_LSB_BYTE, SPEED_SUPPORTED_LSB_START, SPEED_SUPPORTED_LSB_LEN};

        // Byte 207: Address Mirroring
        static constexpr field_t ADDRESS_MIRROR{ADDRESS_MIRROR_BYTE, ADDRESS_MIRROR_START, ADDRESS_MIRROR_LEN};

        // Byte 208: Byte enables LSB
        static constexpr field_t BYTE_ENABLES_LSB{BYTE_ENABLES_LSB_BYTE, BYTE_ENABLES_LSB_START, BYTE_ENABLES_LSB_LEN};

        // Byte 209: Byte enables MSB
        static constexpr field_t BYTE_ENABLES_MSB{BYTE_ENABLES_MSB_BYTE, BYTE_ENABLES_MSB_START, BYTE_ENABLES_MSB_LEN};

        // Byte 210: Nibble enables LSB0
        static constexpr field_t NIBBLE_ENABLES_LSB0{NIBBLE_ENABLES_LSB0_BYTE, NIBBLE_ENABLES_LSB0_START, NIBBLE_ENABLES_LSB0_LEN};

        // Byte 211: Nibble enables MSB0
        static constexpr field_t NIBBLE_ENABLES_MSB0{NIBBLE_ENABLES_MSB0_BYTE, NIBBLE_ENABLES_MSB0_START, NIBBLE_ENABLES_MSB0_LEN};

        // Byte 212: Nibble enables LSB1
        static constexpr field_t NIBBLE_ENABLES_LSB1{NIBBLE_ENABLES_LSB1_BYTE, NIBBLE_ENABLES_LSB1_START, NIBBLE_ENABLES_LSB1_LEN};

        // Byte 214: Four Rank Mode - DDP Compatibility - TSV 8 High Support - MRAM Support
        static constexpr field_t DDIMM_COMPAT{DDIMM_COMPAT_BYTE, DDIMM_COMPAT_START, DDIMM_COMPAT_LEN};

        // Byte 215: Number of P-States
        static constexpr field_t NUM_P_STATES{NUM_P_STATES_BYTE, NUM_P_STATES_START, NUM_P_STATES_LEN};

        // Byte 216: Spare Device Mapping LSB0
        static constexpr field_t SPARE_DEVICE_LSB0{SPARE_DEVICE_LSB0_BYTE, SPARE_DEVICE_LSB0_START, SPARE_DEVICE_LSB0_LEN};

        // Byte 217: Spare Device Mapping MSB0
        static constexpr field_t SPARE_DEVICE_MSB0{SPARE_DEVICE_MSB0_BYTE, SPARE_DEVICE_MSB0_START, SPARE_DEVICE_MSB0_LEN};

        // Byte 218: Spare Device Mapping LSB1
        static constexpr field_t SPARE_DEVICE_LSB1{SPARE_DEVICE_LSB1_BYTE, SPARE_DEVICE_LSB1_START, SPARE_DEVICE_LSB1_LEN};

        // Byte 220: Host Interface Speed to DDR Interface Speed Ratio
        static constexpr field_t HI_DDR_SPEED_RATIO{HI_DDR_SPEED_RATIO_BYTE, HI_DDR_SPEED_RATIO_START, HI_DDR_SPEED_RATIO_LEN};

        // Byte 224: Voltage VIN_MTG Edge connector
        static constexpr field_t VIN_MGMT_NOMINAL{VIN_MGMT_BYTE, VIN_MGMT_NOMINAL_START, VIN_MGMT_NOMINAL_LEN};
        static constexpr field_t VIN_MGMT_OPERABLE{VIN_MGMT_BYTE, VIN_MGMT_OPERABLE_START, VIN_MGMT_OPERABLE_LEN};
        static constexpr field_t VIN_MGMT_ENDURANT{VIN_MGMT_BYTE, VIN_MGMT_ENDURANT_START, VIN_MGMT_ENDURANT_LEN};

        // Byte 225: Voltage VIN_BULK Edge Connecto
        static constexpr field_t VIN_BULK_NOMINAL{VIN_BULK_BYTE, VIN_BULK_NOMINAL_START, VIN_BULK_NOMINAL_LEN};
        static constexpr field_t VIN_BULK_OPERABLE{VIN_BULK_BYTE, VIN_BULK_OPERABLE_START, VIN_BULK_OPERABLE_LEN};
        static constexpr field_t VIN_BULK_ENDURANT{VIN_BULK_BYTE, VIN_BULK_ENDURANT_START, VIN_BULK_ENDURANT_LEN};

        // Byte 226: PMIC0 Sequence
        static constexpr field_t PMIC0_SEQUENCE{PMIC0_SEQUENCE_BYTE, PMIC0_SEQUENCE_START, PMIC0_SEQUENCE_LEN};

        // Byte 227: PMIC0 Manfacture ID code 1st byte
        static constexpr field_t PMIC0_CONT_CODE{PMIC0_MFG_CODE1_BYTE, PMIC0_CONT_CODE_START, PMIC0_CONT_CODE_LEN};

        // Byte 228: PMIC0 Manfacture ID code 2nd byte
        static constexpr field_t PMIC0_LAST_NON_ZERO{PMIC0_MFG_CODE2_BYTE, PMIC0_LAST_NON_ZERO_START, PMIC0_LAST_NON_ZERO_LEN};

        // Byte 229: PMIC0 Revision Number
        static constexpr field_t PMIC0_REV{PMIC0_REV_BYTE, PMIC0_REV_START, PMIC0_REV_LEN};

        // Byte 230: PMIC1 Sequence
        static constexpr field_t PMIC1_SEQUENCE{PMIC1_SEQUENCE_BYTE, PMIC1_SEQUENCE_START, PMIC1_SEQUENCE_LEN};

        // Byte 231: PMIC1 Manfacture ID code 1st byte
        static constexpr field_t PMIC1_CONT_CODE{PMIC1_MFG_CODE1_BYTE, PMIC1_CONT_CODE_START, PMIC1_CONT_CODE_LEN};

        // Byte 232: PMIC1 Manfacture ID code 2nd byte
        static constexpr field_t PMIC1_LAST_NON_ZERO{PMIC1_MFG_CODE2_BYTE, PMIC1_LAST_NON_ZERO_START, PMIC1_LAST_NON_ZERO_LEN};

        // Byte 233: PMIC1 Revision Number
        static constexpr field_t PMIC1_REV{PMIC1_REV_BYTE, PMIC1_REV_START, PMIC1_REV_LEN};

        // Byte 234: PMIC0 SWA Voltage Setting
        static constexpr field_t PMIC0_SWA_VOLT_SET{PMIC0_SWA_VOLT_SET_BYTE, PMIC0_SWA_VOLT_SET_START, PMIC0_SWA_VOLT_SET_LEN};
        static constexpr field_t PMIC0_SWA_RANGE_SELECT{PMIC0_SWA_VOLT_SET_BYTE, PMIC0_SWA_RANGE_SELECT_START, PMIC0_SWA_RANGE_SELECT_LEN};

        // Byte 235: PMIC0 SWA Voltage Offset
        static constexpr field_t PMIC0_SWA_VOLT_OFF{PMIC0_SWA_VOLT_OFF_BYTE, PMIC0_SWA_VOLT_OFF_START, PMIC0_SWA_VOLT_OFF_LEN};
        static constexpr field_t PMIC0_SWA_OFF_DIRECTION{PMIC0_SWA_VOLT_OFF_BYTE, PMIC0_SWA_OFF_DIRECTION_START, PMIC0_SWA_OFF_DIRECTION_LEN};

        // Byte 236: PMIC0 SWA Delay Sequence Order
        static constexpr field_t PMIC0_SWA_DELAY{PMIC0_SWA_DELAY_BYTE, PMIC0_SWA_DELAY_START, PMIC0_SWA_DELAY_LEN};
        static constexpr field_t PMIC0_SWA_ORDER{PMIC0_SWA_DELAY_BYTE, PMIC0_SWA_ORDER_START, PMIC0_SWA_ORDER_LEN};

        // Byte 237: PMIC0 SWB Voltage Setting
        static constexpr field_t PMIC0_SWB_VOLT_SET{PMIC0_SWB_VOLT_SET_BYTE, PMIC0_SWB_VOLT_SET_START, PMIC0_SWB_VOLT_SET_LEN};
        static constexpr field_t PMIC0_SWB_RANGE_SELECT{PMIC0_SWB_VOLT_SET_BYTE, PMIC0_SWB_RANGE_SELECT_START, PMIC0_SWB_RANGE_SELECT_LEN};

        // Byte 238: PMIC0 SWB Voltage Offset
        static constexpr field_t PMIC0_SWB_VOLT_OFF{PMIC0_SWB_VOLT_OFF_BYTE, PMIC0_SWB_VOLT_OFF_START, PMIC0_SWB_VOLT_OFF_LEN};
        static constexpr field_t PMIC0_SWB_OFF_DIRECTION{PMIC0_SWB_VOLT_OFF_BYTE, PMIC0_SWB_OFF_DIRECTION_START, PMIC0_SWB_OFF_DIRECTION_LEN};

        // Byte 239: PMIC0 SWB Delay Sequence Order
        static constexpr field_t PMIC0_SWB_DELAY{PMIC0_SWB_DELAY_BYTE, PMIC0_SWB_DELAY_START, PMIC0_SWB_DELAY_LEN};
        static constexpr field_t PMIC0_SWB_ORDER{PMIC0_SWB_DELAY_BYTE, PMIC0_SWB_ORDER_START, PMIC0_SWB_ORDER_LEN};

        // Byte 240: PMIC0 SWC Voltage Setting
        static constexpr field_t PMIC0_SWC_VOLT_SET{PMIC0_SWC_VOLT_SET_BYTE, PMIC0_SWC_VOLT_SET_START, PMIC0_SWC_VOLT_SET_LEN};
        static constexpr field_t PMIC0_SWC_RANGE_SELECT{PMIC0_SWC_VOLT_SET_BYTE, PMIC0_SWC_RANGE_SELECT_START, PMIC0_SWC_RANGE_SELECT_LEN};

        // Byte 241: PMIC0 SWC Voltage Offset
        static constexpr field_t PMIC0_SWC_VOLT_OFF{PMIC0_SWC_VOLT_OFF_BYTE, PMIC0_SWC_VOLT_OFF_START, PMIC0_SWC_VOLT_OFF_LEN};
        static constexpr field_t PMIC0_SWC_OFF_DIRECTION{PMIC0_SWC_VOLT_OFF_BYTE, PMIC0_SWC_OFF_DIRECTION_START, PMIC0_SWC_OFF_DIRECTION_LEN};

        // Byte 242: PMIC0 SWC Delay Sequence Order
        static constexpr field_t PMIC0_SWC_DELAY{PMIC0_SWC_DELAY_BYTE, PMIC0_SWC_DELAY_START, PMIC0_SWC_DELAY_LEN};
        static constexpr field_t PMIC0_SWC_ORDER{PMIC0_SWC_DELAY_BYTE, PMIC0_SWC_ORDER_START, PMIC0_SWC_ORDER_LEN};

        // Byte 243: PMIC0 SWD Voltage Setting
        static constexpr field_t PMIC0_SWD_VOLT_SET{PMIC0_SWD_VOLT_SET_BYTE, PMIC0_SWD_VOLT_SET_START, PMIC0_SWD_VOLT_SET_LEN};
        static constexpr field_t PMIC0_SWD_RANGE_SELECT{PMIC0_SWD_VOLT_SET_BYTE, PMIC0_SWD_RANGE_SELECT_START, PMIC0_SWD_RANGE_SELECT_LEN};

        // Byte 244: PMIC0 SWD Voltage Offset
        static constexpr field_t PMIC0_SWD_VOLT_OFF{PMIC0_SWD_VOLT_OFF_BYTE, PMIC0_SWD_VOLT_OFF_START, PMIC0_SWD_VOLT_OFF_LEN};
        static constexpr field_t PMIC0_SWD_OFF_DIRECTION{PMIC0_SWD_VOLT_OFF_BYTE, PMIC0_SWD_OFF_DIRECTION_START, PMIC0_SWD_OFF_DIRECTION_LEN};

        // Byte 245: PMIC0 SWD Delay Sequence Order
        static constexpr field_t PMIC0_SWD_DELAY{PMIC0_SWD_DELAY_BYTE, PMIC0_SWD_DELAY_START, PMIC0_SWD_DELAY_LEN};
        static constexpr field_t PMIC0_SWD_ORDER{PMIC0_SWD_DELAY_BYTE, PMIC0_SWD_ORDER_START, PMIC0_SWD_ORDER_LEN};

        // Byte 246: PMIC0 Phase Combination / Redundancy
        static constexpr field_t PMIC0_PHASE_COMBIN{PMIC0_PHASE_COMBIN_BYTE, PMIC0_PHASE_COMBIN_START, PMIC0_PHASE_COMBIN_LEN};
        static constexpr field_t PMIC0_REDUNDANCY{PMIC0_PHASE_COMBIN_BYTE, PMIC0_REDUNDANCY_START, PMIC0_REDUNDANCY_LEN};

        // Byte 247: PMIC1 SWA Voltage Setting
        static constexpr field_t PMIC1_SWA_VOLT_SET{PMIC1_SWA_VOLT_SET_BYTE, PMIC1_SWA_VOLT_SET_START, PMIC1_SWA_VOLT_SET_LEN};
        static constexpr field_t PMIC1_SWA_RANGE_SELECT{PMIC1_SWA_VOLT_SET_BYTE, PMIC1_SWA_RANGE_SELECT_START, PMIC1_SWA_RANGE_SELECT_LEN};

        // Byte 248: PMIC1 SWA Voltage Offset
        static constexpr field_t PMIC1_SWA_VOLT_OFF{PMIC1_SWA_VOLT_OFF_BYTE, PMIC1_SWA_VOLT_OFF_START, PMIC1_SWA_VOLT_OFF_LEN};
        static constexpr field_t PMIC1_SWA_OFF_DIRECTION{PMIC1_SWA_VOLT_OFF_BYTE, PMIC1_SWA_OFF_DIRECTION_START, PMIC1_SWA_OFF_DIRECTION_LEN};

        // Byte 249: PMIC1 SWA Delay Sequence Order
        static constexpr field_t PMIC1_SWA_DELAY{PMIC1_SWA_DELAY_BYTE, PMIC1_SWA_DELAY_START, PMIC1_SWA_DELAY_LEN};
        static constexpr field_t PMIC1_SWA_ORDER{PMIC1_SWA_DELAY_BYTE, PMIC1_SWA_ORDER_START, PMIC1_SWA_ORDER_LEN};

        // Byte 250: PMIC1 SWB Voltage Setting
        static constexpr field_t PMIC1_SWB_VOLT_SET{PMIC1_SWB_VOLT_SET_BYTE, PMIC1_SWB_VOLT_SET_START, PMIC1_SWB_VOLT_SET_LEN};
        static constexpr field_t PMIC1_SWB_RANGE_SELECT{PMIC1_SWB_VOLT_SET_BYTE, PMIC1_SWB_RANGE_SELECT_START, PMIC1_SWB_RANGE_SELECT_LEN};

        // Byte 251: PMIC1 SWB Voltage Offset
        static constexpr field_t PMIC1_SWB_VOLT_OFF{PMIC1_SWB_VOLT_OFF_BYTE, PMIC1_SWB_VOLT_OFF_START, PMIC1_SWB_VOLT_OFF_LEN};
        static constexpr field_t PMIC1_SWB_OFF_DIRECTION{PMIC1_SWB_VOLT_OFF_BYTE, PMIC1_SWB_OFF_DIRECTION_START, PMIC1_SWB_OFF_DIRECTION_LEN};

        // Byte 252: PMIC1 SWB Delay Sequence Order
        static constexpr field_t PMIC1_SWB_DELAY{PMIC1_SWB_DELAY_BYTE, PMIC1_SWB_DELAY_START, PMIC1_SWB_DELAY_LEN};
        static constexpr field_t PMIC1_SWB_ORDER{PMIC1_SWB_DELAY_BYTE, PMIC1_SWB_ORDER_START, PMIC1_SWB_ORDER_LEN};

        // Byte 253: PMIC1 SWC Voltage Setting
        static constexpr field_t PMIC1_SWC_VOLT_SET{PMIC1_SWC_VOLT_SET_BYTE, PMIC1_SWC_VOLT_SET_START, PMIC1_SWC_VOLT_SET_LEN};
        static constexpr field_t PMIC1_SWC_RANGE_SELECT{PMIC1_SWC_VOLT_SET_BYTE, PMIC1_SWC_RANGE_SELECT_START, PMIC1_SWC_RANGE_SELECT_LEN};

        // Byte 254: PMIC1 SWC Voltage Offset
        static constexpr field_t PMIC1_SWC_VOLT_OFF{PMIC1_SWC_VOLT_OFF_BYTE, PMIC1_SWC_VOLT_OFF_START, PMIC1_SWC_VOLT_OFF_LEN};
        static constexpr field_t PMIC1_SWC_OFF_DIRECTION{PMIC1_SWC_VOLT_OFF_BYTE, PMIC1_SWC_OFF_DIRECTION_START, PMIC1_SWC_OFF_DIRECTION_LEN};

        // Byte 255: PMIC1 SWC Delay Sequence Order
        static constexpr field_t PMIC1_SWC_DELAY{PMIC1_SWC_DELAY_BYTE, PMIC1_SWC_DELAY_START, PMIC1_SWC_DELAY_LEN};
        static constexpr field_t PMIC1_SWC_ORDER{PMIC1_SWC_DELAY_BYTE, PMIC1_SWC_ORDER_START, PMIC1_SWC_ORDER_LEN};

        // Byte 256: PMIC1 SWD Voltage Setting
        static constexpr field_t PMIC1_SWD_VOLT_SET{PMIC1_SWD_VOLT_SET_BYTE, PMIC1_SWD_VOLT_SET_START, PMIC1_SWD_VOLT_SET_LEN};
        static constexpr field_t PMIC1_SWD_RANGE_SELECT{PMIC1_SWD_VOLT_SET_BYTE, PMIC1_SWD_RANGE_SELECT_START, PMIC1_SWD_RANGE_SELECT_LEN};

        // Byte 257: PMIC1 SWD Voltage Offset
        static constexpr field_t PMIC1_SWD_VOLT_OFF{PMIC1_SWD_VOLT_OFF_BYTE, PMIC1_SWD_VOLT_OFF_START, PMIC1_SWD_VOLT_OFF_LEN};
        static constexpr field_t PMIC1_SWD_OFF_DIRECTION{PMIC1_SWD_VOLT_OFF_BYTE, PMIC1_SWD_OFF_DIRECTION_START, PMIC1_SWD_OFF_DIRECTION_LEN};

        // Byte 258: PMIC1 SWD Delay Sequence Order
        static constexpr field_t PMIC1_SWD_DELAY{PMIC1_SWD_DELAY_BYTE, PMIC1_SWD_DELAY_START, PMIC1_SWD_DELAY_LEN};
        static constexpr field_t PMIC1_SWD_ORDER{PMIC1_SWD_DELAY_BYTE, PMIC1_SWD_ORDER_START, PMIC1_SWD_ORDER_LEN};

        // Byte 259: PMIC1 Phase Combination
        static constexpr field_t PMIC1_PHASE_COMBIN{PMIC1_PHASE_COMBIN_BYTE, PMIC1_PHASE_COMBIN_START, PMIC1_PHASE_COMBIN_LEN};
        static constexpr field_t PMIC1_REDUNDANCY{PMIC1_PHASE_COMBIN_BYTE, PMIC1_REDUNDANCY_START, PMIC1_REDUNDANCY_LEN};

        // Byte 264: Registered Clock Drivers (RCD)
        static constexpr field_t MODULE_RCD{MODULE_RCD_BYTE, MODULE_RCD_START, MODULE_RCD_LEN};

        // Byte 268: Thermal Sensor 0 Profile
        static constexpr field_t THERM_SENSOR_0_AVAIL{THERM_SENSOR_0_PROFILE_BYTE, THERM_SENSOR_0_AVAIL_START, THERM_SENSOR_0_AVAIL_LEN};
        static constexpr field_t THERM_SENSOR_0_USAGE{THERM_SENSOR_0_PROFILE_BYTE, THERM_SENSOR_0_USAGE_START, THERM_SENSOR_0_USAGE_LEN};
        static constexpr field_t THERM_SENSOR_0_TYPE{THERM_SENSOR_0_PROFILE_BYTE, THERM_SENSOR_0_TYPE_START, THERM_SENSOR_0_TYPE_LEN};

        // Byte 269: Thermal Sensor 0 I2C Address
        static constexpr field_t THERM_SENSOR_0_I2C_ADDRESS{THERM_SENSOR_0_I2C_ADDRESS_BYTE, THERM_SENSOR_0_I2C_ADDRESS_START, THERM_SENSOR_0_I2C_ADDRESS_LEN};

        // Byte 271: Thermal Sensor 1 Profile
        static constexpr field_t THERM_SENSOR_1_AVAIL{THERM_SENSOR_1_PROFILE_BYTE, THERM_SENSOR_1_AVAIL_START, THERM_SENSOR_1_AVAIL_LEN};
        static constexpr field_t THERM_SENSOR_1_USAGE{THERM_SENSOR_1_PROFILE_BYTE, THERM_SENSOR_1_USAGE_START, THERM_SENSOR_1_USAGE_LEN};
        static constexpr field_t THERM_SENSOR_1_TYPE{THERM_SENSOR_1_PROFILE_BYTE, THERM_SENSOR_1_TYPE_START, THERM_SENSOR_1_TYPE_LEN};

        // Byte 271: Thermal Sensor 1 I2C Address
        static constexpr field_t THERM_SENSOR_1_I2C_ADDRESS{THERM_SENSOR_1_I2C_ADDRESS_BYTE, THERM_SENSOR_1_I2C_ADDRESS_START, THERM_SENSOR_1_I2C_ADDRESS_LEN};

        // Byte DIFF7DIFF: Differential Sensor Profile
        static constexpr field_t THERM_SENSOR_DIFF_AVAIL{THERM_SENSOR_DIFF_PROFILE_BYTE, THERM_SENSOR_DIFF_AVAIL_START, THERM_SENSOR_DIFF_AVAIL_LEN};
        static constexpr field_t THERM_SENSOR_DIFF_USAGE{THERM_SENSOR_DIFF_PROFILE_BYTE, THERM_SENSOR_DIFF_USAGE_START, THERM_SENSOR_DIFF_USAGE_LEN};
        static constexpr field_t THERM_SENSOR_DIFF_TYPE{THERM_SENSOR_DIFF_PROFILE_BYTE, THERM_SENSOR_DIFF_TYPE_START, THERM_SENSOR_DIFF_TYPE_LEN};

        // Byte 273: Differential Sensor I2C Address
        static constexpr field_t THERM_SENSOR_DIFF_I2C_ADDRESS{THERM_SENSOR_DIFF_I2C_ADDRESS_BYTE, THERM_SENSOR_DIFF_I2C_ADDRESS_START, THERM_SENSOR_DIFF_I2C_ADDRESS_LEN};

        // MANF Section:
        // Section is not standardized across dimm types, so these fields will live in the
        // ddimm specific section

        // Byte 512 and 513 Module MFG ID
        static constexpr field_t MODULE_MFG_ID_CODE_LSB{MODULE_MFG_ID_CODE_LSB_BYTE, MODULE_MFG_ID_CODE_START, MODULE_MFG_ID_CODE_LEN};
        static constexpr field_t MODULE_MFG_ID_CODE_MSB{MODULE_MFG_ID_CODE_MSB_BYTE, MODULE_MFG_ID_CODE_START, MODULE_MFG_ID_CODE_LEN};

        // Byte 552 and 553: DRAM manufacturing ID for DDIMMs
        static constexpr field_t DRAM_MFR_ID_CODE_LSB{DRAM_MFR_ID_CODE_LSB_BYTE, DRAM_MFR_ID_CODE_START, DRAM_MFR_ID_CODE_LEN};
        static constexpr field_t DRAM_MFR_ID_CODE_MSB{DRAM_MFR_ID_CODE_MSB_BYTE, DRAM_MFR_ID_CODE_START, DRAM_MFR_ID_CODE_LEN};
};

}// spd
}// mss

#endif // _MSS_SPD_FIELDS_DDR4_H_
