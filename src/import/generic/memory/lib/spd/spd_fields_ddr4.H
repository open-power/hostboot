/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/spd_fields_ddr4.H $         */
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

}// spd
}// mss

#endif // _MSS_SPD_FIELDS_DDR4_H_
