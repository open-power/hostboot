/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/spd_fields_ddr5.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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

// EKB-Mirror-To: hostboot
///
/// @file spd_fields_ddr5.H
/// @brief DDR5 SPD data fields
///

// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_SPD_FIELDS_DDR5_H_
#define _MSS_SPD_FIELDS_DDR5_H_

#include <generic/memory/lib/spd/spd_field.H>

namespace mss
{
namespace spd
{

///
/// @class fields
/// @brief DDR5 SPD General Section fields
/// @note DDR5, BASE_CNFG specialization
///
/// @note Since these fields are used as non-type template params,
/// they need have external linkage. Currently C++11 can achieve this
/// by making them static constexpr member variables.
///
template <>
class fields<DDR5, BASE_CNFG>
{
    private:

        // Note: Spacing out bytes a bit to hopefully reduce merge conflicts
        enum
        {
            //////////////////////////////////////
            //// Bytes 0-18: prior to timings
            //////////////////////////////////////

            // Byte 3
            HYBRID_START = 0,
            HYBRID_LEN = 1,
            HYBRID_MEDIA_START = 1,
            HYBRID_MEDIA_LEN = 3,
            BASE_MODULE_START = 4,
            BASE_MODULE_LEN = 4,

            // Byte 4
            DIE_PER_PACKAGE_START = 0,
            DIE_PER_PACKAGE_LEN = 3,
            DENSITY_PER_DIE_START = 3,
            DENSITY_PER_DIE_LEN = 5,
            HEIGHT_3DS_START = 0,
            HEIGHT_3DS_LEN = 3,

            // Byte 5
            COL_ADDRESS_START = 0,
            COL_ADDRESS_LEN = 3,
            ROW_ADDRESS_START = 3,
            ROW_ADDRESS_LEN = 5,

            // Byte 6
            SDRAM_WIDTH_START = 0,
            SDRAM_WIDTH_LEN = 3,


            //Byte 16, 17, 18
            OPERABLE_START = 4,
            OPERABLE_LEN = 2,

            ENDURANT_START = 6,
            ENDURANT_LEN = 2,

            //////////////////////////////////////
            //// Bytes 19-93: timings
            //////////////////////////////////////
            // Byte 20
            TCK_MIN_LSB_START = 0,
            TCK_MIN_LSB_LEN   = 8,
            // Byte 21
            TCK_MIN_MSB_START = 0,
            TCK_MIN_MSB_LEN   = 8,
            // Byte 22
            TCK_MAX_LSB_START = 0,
            TCK_MAX_LSB_LEN   = 8,
            // Byte 23
            TCK_MAX_MSB_START = 0,
            TCK_MAX_MSB_LEN   = 8,

            // Byte 24-28
            CAS_BYTE_1_START = 0,
            CAS_BYTE_1_LEN = 8,
            CAS_BYTE_2_START = 0,
            CAS_BYTE_2_LEN = 8,
            CAS_BYTE_3_START = 0,
            CAS_BYTE_3_LEN = 8,
            CAS_BYTE_4_START = 0,
            CAS_BYTE_4_LEN = 8,
            CAS_BYTE_5_START = 0,
            CAS_BYTE_5_LEN = 8,

            // Byte 30
            TAA_MIN_LSB_START = 0,
            TAA_MIN_LSB_LEN   = 8,
            // Byte 31
            TAA_MIN_MSB_START = 0,
            TAA_MIN_MSB_LEN   = 8,
            // Byte 32
            TRCD_MIN_LSB_START = 0,
            TRCD_MIN_LSB_LEN   = 8,
            // Byte 33
            TRCD_MIN_MSB_START = 0,
            TRCD_MIN_MSB_LEN   = 8,

            //////////////////////////////////////
            //// Bytes 230-236: module information
            //////////////////////////////////////
            // Byte 234
            RANK_MIX_START = 1,
            RANK_MIX_LEN = 1,
            PACKAGE_RANKS_PER_CHANNEL_START = 2,
            PACKAGE_RANKS_PER_CHANNEL_LEN = 3,

            // Byte 235
            CHANNELS_PER_DIMM_START = 1,
            CHANNELS_PER_DIMM_LEN = 2,
            BUS_EXT_WIDTH_START = 3,
            BUS_EXT_WIDTH_LEN = 2,
            BUS_WIDTH_START = 5,
            BUS_WIDTH_LEN = 3,

            /////////////////////////////////////////////
            //// Bytes 512-637: manufacturing information
            /////////////////////////////////////////////
            // Byte 512
            CONTINUATION_CODES_START = 0,
            CONTINUATION_CODES_LEN = 8,

            // Byte 513
            LAST_NON_ZERO_BYTE_START = 0,
            LAST_NON_ZERO_BYTE_LEN = 8,

            // Byte 552-553
            DRAM_MFR_ID_CODE_START = 0,
            DRAM_MFR_ID_CODE_LEN = 8,
        };

    public:

        // Note: Spacing out bytes a bit to hopefully reduce merge conflicts
        // 1st field: Byte number
        // 2nd field: Start bit
        // 3rd field: Bit length
        //////////////////////////////////////
        //// Bytes 0-18: prior to timings
        //////////////////////////////////////
        static constexpr mss::field_t<mss::endian::LITTLE> HYBRID{3, HYBRID_START, HYBRID_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> HYBRID_MEDIA{3, HYBRID_MEDIA_START, HYBRID_MEDIA_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> BASE_MODULE{3, BASE_MODULE_START, BASE_MODULE_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> DIE_PER_PACKAGE{4, DIE_PER_PACKAGE_START, DIE_PER_PACKAGE_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> DENSITY_PER_DIE{4, DENSITY_PER_DIE_START, DENSITY_PER_DIE_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> HEIGHT_3DS{4, HEIGHT_3DS_START, HEIGHT_3DS_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> COL_ADDR_BITS{5, COL_ADDRESS_START, COL_ADDRESS_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> ROW_ADDR_BITS{5, ROW_ADDRESS_START, ROW_ADDRESS_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> SDRAM_WIDTH{6, SDRAM_WIDTH_START, SDRAM_WIDTH_LEN};

        static constexpr mss::field_t<mss::endian::LITTLE> OPERABLE_VDD_FLD{16, OPERABLE_START, OPERABLE_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> ENDURANT_VDD_FLD{16, ENDURANT_START, ENDURANT_LEN};

        static constexpr mss::field_t<mss::endian::LITTLE> OPERABLE_VDDQ_FLD{17, OPERABLE_START, OPERABLE_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> ENDURANT_VDDQ_FLD{17, ENDURANT_START, ENDURANT_LEN};

        static constexpr mss::field_t<mss::endian::LITTLE> OPERABLE_VPP_FLD{18, OPERABLE_START, OPERABLE_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> ENDURANT_VPP_FLD{18, ENDURANT_START, ENDURANT_LEN};

        //////////////////////////////////////
        //// Bytes 19-93: timings
        //////////////////////////////////////
        static constexpr mss::field_t<mss::endian::LITTLE> TCK_MIN_LSB{20, TCK_MIN_LSB_START, TCK_MIN_LSB_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> TCK_MIN_MSB{21, TCK_MIN_MSB_START, TCK_MIN_MSB_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> TCK_MAX_LSB{22, TCK_MAX_LSB_START, TCK_MAX_LSB_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> TCK_MAX_MSB{23, TCK_MAX_MSB_START, TCK_MAX_MSB_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> CL_FIRST_BYTE{24, CAS_BYTE_1_START, CAS_BYTE_1_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> CL_SECOND_BYTE{25, CAS_BYTE_2_START, CAS_BYTE_2_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> CL_THIRD_BYTE{26, CAS_BYTE_3_START, CAS_BYTE_3_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> CL_FOURTH_BYTE{27, CAS_BYTE_4_START, CAS_BYTE_4_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> CL_FIFTH_BYTE{28, CAS_BYTE_5_START, CAS_BYTE_5_LEN};

        static constexpr mss::field_t<mss::endian::LITTLE> TAA_MIN_LSB{30, TAA_MIN_LSB_START, TAA_MIN_LSB_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> TAA_MIN_MSB{31, TAA_MIN_MSB_START, TAA_MIN_MSB_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> TRCD_MIN_LSB{32, TRCD_MIN_LSB_START, TRCD_MIN_LSB_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> TRCD_MIN_MSB{33, TRCD_MIN_MSB_START, TRCD_MIN_MSB_LEN};

        //////////////////////////////////////
        //// Bytes 230-236: module information
        //////////////////////////////////////
        static constexpr mss::field_t<mss::endian::LITTLE> RANK_MIX{234, RANK_MIX_START, RANK_MIX_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> PACKAGE_RANKS_PER_CHANNEL{234, PACKAGE_RANKS_PER_CHANNEL_START, PACKAGE_RANKS_PER_CHANNEL_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> BUS_WIDTH{235, BUS_WIDTH_START, BUS_WIDTH_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> BUS_EXT_WIDTH{235, BUS_EXT_WIDTH_START, BUS_EXT_WIDTH_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> CHANNELS_PER_DIMM{235, CHANNELS_PER_DIMM_START, CHANNELS_PER_DIMM_LEN};

        //////////////////////////////////////
        //// Bytes 512-513: module information
        //////////////////////////////////////
        static constexpr mss::field_t<mss::endian::LITTLE> CONTINUATION_CODES{512, CONTINUATION_CODES_START, CONTINUATION_CODES_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> LAST_NON_ZERO_BYTE{513, LAST_NON_ZERO_BYTE_START, LAST_NON_ZERO_BYTE_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> DRAM_MFR_ID_CODE_LSB{552, DRAM_MFR_ID_CODE_START, DRAM_MFR_ID_CODE_LEN};
        static constexpr mss::field_t<mss::endian::LITTLE> DRAM_MFR_ID_CODE_MSB{553, DRAM_MFR_ID_CODE_START, DRAM_MFR_ID_CODE_LEN};
};

///
/// @class fields
/// @brief DDR5 DDIMM module SPD parameters
/// @note DDR5, DDIMM_MODULE specialization
///
template <>
class fields<DDR5, DDIMM_MODULE>
{
    public:
        // Note: these need to be used directly, so they need to be declared as public
        static constexpr uint64_t SERIAL_NUMBER_LEN = 26;
        static constexpr uint64_t SERIAL_NUMBER_BYTE0 = 416;
        static constexpr uint64_t SERIAL_NUMBER_LAST_VALID_BYTE = SERIAL_NUMBER_BYTE0 + SERIAL_NUMBER_LEN - 1;

    private:

        enum
        {

            // Byte 192: SPD Revision DDIMM Module Type (bytes 192->447)
            SPD_REV_DDIMM_MODULE_BYTE = 192,
            SPD_REV_DDIMM_MODULE_START = 0,
            SPD_REV_DDIMM_MODULE_LEN = 8,

            // Byte 193: Hashing Sequence
            HASH_SEQ_BYTE = 193,
            HASH_SEQ_SERIAL_NUMBER_START = 5,
            HASH_SEQ_SERIAL_NUMBER_LEN = 3,

            // Byte 194: SPD MANF ID CODE, First Byte
            SPD_MANF_ID_FIRST_BYTE = 194,
            SPD_MANF_ID_FIRST_BYTE_START = 0,
            SPD_MANF_ID_FIRST_BYTE_LEN = 8,

            // Byte 195: SPD MANF ID CODE, Second Byte
            SPD_MANF_ID_SECOND_BYTE = 195,
            SPD_MANF_ID_SECOND_BYTE_START = 0,
            SPD_MANF_ID_SECOND_BYTE_LEN = 8,

            // Byte 196: SPD Device Type
            SPD_DEVICE_TYPE_BYTE = 196,
            SPD_DEVICE_TYPE_START = 0,
            SPD_DEVICE_TYPE_LEN = 8,

            // Byte 197: SPD Device Revision Number
            SPD_DEVICE_REV_NUM_BYTE = 197,
            SPD_DEVICE_REV_NUM_START = 0,
            SPD_DEVICE_REV_NUM_LEN = 8,

            // Byte 198: PMIC0 Manf ID Code, 1st Byte
            PMIC0_MFG_CODE_FIRST_BYTE = 198,
            PMIC0_MFG_CODE_FIRST_BYTE_START = 0,
            PMIC0_MFG_CODE_FIRST_BYTE_LEN = 8,

            // Byte 199: PMIC0 Manfacture ID code 2nd byte
            PMIC0_MFG_CODE_SECOND_BYTE = 199,
            PMIC0_MFG_CODE_SECOND_BYTE_START = 0,
            PMIC0_MFG_CODE_SECOND_BYTE_LEN = 8,

            // Byte 200: PMIC0 Device Type
            PMIC0_DEVICE_TYPE_BYTE = 200,
            PMIC0_DEVICE_TYPE_START = 0,
            PMIC0_DEVICE_TYPE_LEN = 8,

            // Byte 201: PMIC0 Device Revision Number
            PMIC0_DEVICE_REV_NUM_BYTE = 201,
            PMIC0_DEVICE_REV_NUM_START = 0,
            PMIC0_DEVICE_REV_NUM_LEN = 8,

            // Byte 202: PMIC1 Manf ID Code, 1st Byte
            PMIC1_MFG_CODE_FIRST_BYTE = 202,
            PMIC1_MFG_CODE_FIRST_BYTE_START = 0,
            PMIC1_MFG_CODE_FIRST_BYTE_LEN = 8,

            // Byte 203: PMIC1 Manfacture ID code 2nd byte
            PMIC1_MFG_CODE_SECOND_BYTE = 203,
            PMIC1_MFG_CODE_SECOND_BYTE_START = 0,
            PMIC1_MFG_CODE_SECOND_BYTE_LEN = 8,

            // Byte 204: PMIC1 Device Type
            PMIC1_DEVICE_TYPE_BYTE = 204,
            PMIC1_DEVICE_TYPE_START = 0,
            PMIC1_DEVICE_TYPE_LEN = 8,

            // Byte 205: PMIC1 Device Revision Number
            PMIC1_DEVICE_REV_NUM_BYTE = 205,
            PMIC1_DEVICE_REV_NUM_START = 0,
            PMIC1_DEVICE_REV_NUM_LEN = 8,

            // Byte 206: PMIC2 Manf ID Code, 1st Byte
            PMIC2_MFG_CODE_FIRST_BYTE = 206,
            PMIC2_MFG_CODE_FIRST_START = 0,
            PMIC2_MFG_CODE_FIRST_LEN = 8,

            // Byte 207: PMIC2 Manfacture ID code 2nd byte
            PMIC2_MFG_CODE_SECOND_BYTE = 207,
            PMIC2_MFG_CODE_SECOND_START = 0,
            PMIC2_MFG_CODE_SECOND_LEN = 8,

            // Byte 208: PMIC2 Device Type
            PMIC2_DEVICE_TYPE_BYTE = 208,
            PMIC2_DEVICE_TYPE_START = 0,
            PMIC2_DEVICE_TYPE_LEN = 8,

            // Byte 209: PMIC2 Device Revision Number
            PMIC2_DEVICE_REV_NUM_BYTE = 209,
            PMIC2_DEVICE_REV_NUM_START = 0,
            PMIC2_DEVICE_REV_NUM_LEN = 8,

            // Byte 210: Thermal Sensor0 Manufacturing ID Code, First Byte
            THERMAL_SENSOR0_MANF_ID_CODE_FIRST_BYTE = 210,
            THERMAL_SENSOR0_MANF_ID_CODE_FIRST_START = 0,
            THERMAL_SENSOR0_MANF_ID_CODE_FIRST_LEN = 8,

            // Byte 211: Thermal Sensor0 Manufacturing ID Code, Second Byte
            THERMAL_SENSOR0_MANF_ID_CODE_SECOND_BYTE = 211,
            THERMAL_SENSOR0_MANF_ID_CODE_SECOND_START = 0,
            THERMAL_SENSOR0_MANF_ID_CODE_SECOND_LEN = 8,

            // Byte 212: Thermal Sensor0 Device Type
            THERMAL_SENSOR0_DEVICE_TYPE_BYTE = 212,
            THERMAL_SENSOR0_DEVICE_TYPE_START = 0,
            THERMAL_SENSOR0_DEVICE_TYPE_LEN = 8,

            // Byte 213: Thermal Sensor0 Revision Number
            THERMAL_SENSOR0_REV_NUM_BYTE = 213,
            THERMAL_SENSOR0_REV_NUM_START = 0,
            THERMAL_SENSOR0_REV_NUM_LEN = 8,

            // Byte 214: DRAM Specification Level
            DRAM_SPEC_LEVEL_BYTE = 214,
            DRAM_SPEC_LEVEL_START = 0,
            DRAM_SPEC_LEVEL_LEN = 8,

            // Byte 215: SPD Specification Level
            SPD_SPEC_LEVEL_BYTE = 215,
            SPD_SPEC_LEVEL_START = 0,
            SPD_SPEC_LEVEL_LEN = 8,

            // Byte 216: PMIC0 Spec Level
            PMIC0_SPEC_LEVEL_BYTE = 216,
            PMIC0_SPEC_LEVEL_START = 0,
            PMIC0_SPEC_LEVEL_LEN = 8,


            // Byte 217: PMIC1 Spec Level
            PMIC1_SPEC_LEVEL_BYTE = 217,
            PMIC1_SPEC_LEVEL_START = 0,
            PMIC1_SPEC_LEVEL_LEN = 8,

            // Byte 218: PMIC2 Spec Level
            PMIC2_SPEC_LEVEL_BYTE = 218,
            PMIC2_SPEC_LEVEL_START = 0,
            PMIC2_SPEC_LEVEL_LEN = 8,

            // Byte 219: THERMAL_SENSOR0 Spec Level
            THERMAL_SENSOR0_SPEC_LEVEL_BYTE = 219,
            THERMAL_SENSOR0_SPEC_LEVEL_START = 0,
            THERMAL_SENSOR0_SPEC_LEVEL_LEN = 8,

            // Byte 230: Module Nominal Height
            MODULE_HEIGHT_BYTE = 230,
            MODULE_BASE_HEIGHT_START = 0,
            MODULE_BASE_HEIGHT_LEN = 3,
            MODULE_HEIGHT_MAX_START = 3,
            MODULE_HEIGHT_MAX_LEN = 5,

            // Byte 231: Module Nominal Thickness
            MODULE_THICKNESS_BYTE = 231,
            MAX_THICKNESS_BACK_START = 0,
            MAX_THICKNESS_BACK_LEN = 4,
            MAX_THICKNESS_FRONT_START = 4,
            MAX_THICKNESS_FRONT_LEN = 4,

            // Byte 232: Reference Raw Card used
            REF_RAW_CARD_BYTE = 232,
            DESIGN_REV_START = 0,
            DESIGN_REV_LEN = 3,
            DESIGN_REF_CARD_START = 3,
            DESIGN_REF_CARD_LEN = 5,

            // Byte 233: DIMM attributes
            DIMM_ATTR_BYTE = 233,
            DIMM_ATTR_REGISTER_TYPE_START = 0,
            DIMM_ATTR_REGISTER_TYPE_LEN = 4,
            NUM_BUFFERS_START = 6,
            NUM_BUFFERS_LEN = 2,

            // Byte 234: DIMM Module Oranization
            DIMM_ORG_BYTE_BYTE = 234,
            NUM_PACKAGE_RANKS_CHAN1_START = 0,
            NUM_PACKAGE_RANKS_CHAN1_LEN = 3,
            NUM_PACKAGE_RANKS_CHAN0_START = 3,
            NUM_PACKAGE_RANKS_CHAN0_LEN = 3,
            SDRAM_DATA_WID_CHAN_START = 6,
            SDRAM_DATA_WID_CHAN_LEN = 2,


            // Byte 235: Memory Channel Bus Width
            BUS_WIDTH_BYTE = 235,
            ENABLED_PHY_CHANNELS_START = 0,
            ENABLED_PHY_CHANNELS_LEN = 2,
            BUS_WIDTH_CHANNEL_A_START = 2,
            BUS_WIDTH_CHANNEL_A_LEN = 3,
            BUS_WIDTH_CHANNEL_B_START = 5,
            BUS_WIDTH_CHANNEL_B_LEN = 3,

            // Byte 240: PMIC3 Manufacturing ID Code, First Byte
            PMIC3_MFG_CODE_FIRST_BYTE = 240,
            PMIC3_MFG_CODE_FIRST_START = 0,
            PMIC3_MFG_CODE_FIRST_LEN = 8,

            // Byte 241: PMIC3 Manfacture ID code 2nd byte
            PMIC3_MFG_CODE_SECOND_BYTE = 241,
            PMIC3_MFG_CODE_SECOND_START = 0,
            PMIC3_MFG_CODE_SECOND_LEN = 8,

            // Byte 242: PMIC3 Device Type
            PMIC3_DEVICE_TYPE_BYTE = 242,
            PMIC3_DEVICE_TYPE_START = 0,
            PMIC3_DEVICE_TYPE_LEN = 8,

            // Byte 243: PMIC3 Device Revision Number
            PMIC3_DEVICE_REV_NUM_BYTE = 243,
            PMIC3_DEVICE_REV_NUM_START = 0,
            PMIC3_DEVICE_REV_NUM_LEN = 8,

            // Byte 244: PMIC3 Spec Level
            PMIC3_SPEC_LEVEL_BYTE = 244,
            PMIC3_SPEC_LEVEL_START = 0,
            PMIC3_SPEC_LEVEL_LEN = 8,

            // Byte 245: Thermal Sensor1 Manufacturing ID Code, First Byte
            THERMAL_SENSOR1_MANF_ID_CODE_FIRST_BYTE = 245,
            THERMAL_SENSOR1_MANF_ID_CODE_FIRST_START = 0,
            THERMAL_SENSOR1_MANF_ID_CODE_FIRST_LEN = 8,

            // Byte 246: Thermal Sensor1 Manufacturing ID Code, Second Byte
            THERMAL_SENSOR1_MANF_ID_CODE_SECOND_BYTE = 246,
            THERMAL_SENSOR1_MANF_ID_CODE_SECOND_START = 0,
            THERMAL_SENSOR1_MANF_ID_CODE_SECOND_LEN = 8,

            // Byte 247: Thermal Sensor1 Device Type
            THERMAL_SENSOR1_DEVICE_TYPE_BYTE = 247,
            THERMAL_SENSOR1_DEVICE_TYPE_START = 0,
            THERMAL_SENSOR1_DEVICE_TYPE_LEN = 8,

            // Byte 248: Thermal Sensor1 Revision Number
            THERMAL_SENSOR1_REV_NUM_BYTE = 248,
            THERMAL_SENSOR1_REV_NUM_START = 0,
            THERMAL_SENSOR1_REV_NUM_LEN = 8,

            // Byte 249: Thermal Sensor1 Spec Level
            THERMAL_SENSOR1_SPEC_LEVEL_BYTE = 249,
            THERMAL_SENSOR1_SPEC_LEVEL_START = 0,
            THERMAL_SENSOR1_SPEC_LEVEL_LEN = 8,

            // Byte 250: Thermal Sensor2 Manufacturing ID Code, First Byte
            THERMAL_SENSOR2_MANF_ID_CODE_FIRST_BYTE = 250,
            THERMAL_SENSOR2_MANF_ID_CODE_FIRST_START = 0,
            THERMAL_SENSOR2_MANF_ID_CODE_FIRST_LEN = 8,

            // Byte 251: Thermal Sensor2 Manufacturing ID Code, Second Byte
            THERMAL_SENSOR2_MANF_ID_CODE_SECOND_BYTE = 251,
            THERMAL_SENSOR2_MANF_ID_CODE_SECOND_START = 0,
            THERMAL_SENSOR2_MANF_ID_CODE_SECOND_LEN = 8,

            // Byte 252: Thermal Sensor2 Device Type
            THERMAL_SENSOR2_DEVICE_TYPE_BYTE = 252,
            THERMAL_SENSOR2_DEVICE_TYPE_START = 0,
            THERMAL_SENSOR2_DEVICE_TYPE_LEN = 8,

            // Byte 253: Thermal Sensor2 Revision Number
            THERMAL_SENSOR2_REV_NUM_BYTE = 253,
            THERMAL_SENSOR2_REV_NUM_START = 0,
            THERMAL_SENSOR2_REV_NUM_LEN = 8,

            // Byte 254: Thermal Sensor2 Spec Level
            THERMAL_SENSOR2_SPEC_LEVEL_BYTE = 254,
            THERMAL_SENSOR2_SPEC_LEVEL_START = 0,
            THERMAL_SENSOR2_SPEC_LEVEL_LEN = 8,

            // Byte 255: Thermal Sensor3 Manufacturing ID Code, First Byte
            THERMAL_SENSOR3_MANF_ID_CODE_FIRST_BYTE = 255,
            THERMAL_SENSOR3_MANF_ID_CODE_FIRST_START = 0,
            THERMAL_SENSOR3_MANF_ID_CODE_FIRST_LEN = 8,

            // Byte 256: Thermal Sensor3 Manufacturing ID Code, Second Byte
            THERMAL_SENSOR3_MANF_ID_CODE_SECOND_BYTE = 256,
            THERMAL_SENSOR3_MANF_ID_CODE_SECOND_START = 0,
            THERMAL_SENSOR3_MANF_ID_CODE_SECOND_LEN = 8,

            // Byte 257: Thermal Sensor3 Device Type
            THERMAL_SENSOR3_DEVICE_TYPE_BYTE = 257,
            THERMAL_SENSOR3_DEVICE_TYPE_START = 0,
            THERMAL_SENSOR3_DEVICE_TYPE_LEN = 8,

            // Byte 258: Thermal Sensor3 Revision Number
            THERMAL_SENSOR3_REV_NUM_BYTE = 258,
            THERMAL_SENSOR3_REV_NUM_START = 0,
            THERMAL_SENSOR3_REV_NUM_LEN = 8,

            // Byte 259: Thermal Sensor3 Spec Level
            THERMAL_SENSOR3_SPEC_LEVEL_BYTE = 259,
            THERMAL_SENSOR3_SPEC_LEVEL_START = 0,
            THERMAL_SENSOR3_SPEC_LEVEL_LEN = 8,

            // Byte 260: Thermal Sensor Locations
            THERMAL_SENSOR_LOCATIONS_BYTE = 260,
            THERMAL_SENSOR_3_LOCATION_START = 0,
            THERMAL_SENSOR_3_LOCATION_LEN = 2,
            THERMAL_SENSOR_2_LOCATION_START = 2,
            THERMAL_SENSOR_2_LOCATION_LEN = 2,
            THERMAL_SENSOR_1_LOCATION_START = 4,
            THERMAL_SENSOR_1_LOCATION_LEN = 2,
            THERMAL_SENSOR_0_LOCATION_START = 6,
            THERMAL_SENSOR_0_LOCATION_LEN = 2,

            // Byte 261: Thermal Sensor 0 Profile
            THERMAL_SENSOR_0_PROFILE_BYTE = 261,
            THERMAL_SENSOR_0_AVAIL_START = 0,
            THERMAL_SENSOR_0_AVAIL_LEN = 1,
            THERMAL_SENSOR_0_TYPE_START = 2,
            THERMAL_SENSOR_0_TYPE_LEN = 3,
            THERMAL_SENSOR_0_USAGE_START = 5,
            THERMAL_SENSOR_0_USAGE_LEN = 3,

            // Byte 262: Thermal Sensor 1 Profile
            THERMAL_SENSOR_1_PROFILE_BYTE = 262,
            THERMAL_SENSOR_1_AVAIL_START = 0,
            THERMAL_SENSOR_1_AVAIL_LEN = 1,
            THERMAL_SENSOR_1_TYPE_START = 2,
            THERMAL_SENSOR_1_TYPE_LEN = 3,
            THERMAL_SENSOR_1_USAGE_START = 5,
            THERMAL_SENSOR_1_USAGE_LEN = 3,

            // Byte 263: Thermal Sensor 2 Profile
            THERMAL_SENSOR_2_PROFILE_BYTE = 263,
            THERMAL_SENSOR_2_AVAIL_START = 0,
            THERMAL_SENSOR_2_AVAIL_LEN = 1,
            THERMAL_SENSOR_2_TYPE_START = 2,
            THERMAL_SENSOR_2_TYPE_LEN = 3,
            THERMAL_SENSOR_2_USAGE_START = 5,
            THERMAL_SENSOR_2_USAGE_LEN = 3,

            // Byte 264: Thermal Sensor 3 Profile
            THERMAL_SENSOR_3_PROFILE_BYTE = 264,
            THERMAL_SENSOR_3_AVAIL_START = 0,
            THERMAL_SENSOR_3_AVAIL_LEN = 1,
            THERMAL_SENSOR_3_TYPE_START = 2,
            THERMAL_SENSOR_3_TYPE_LEN = 3,
            THERMAL_SENSOR_3_USAGE_START = 5,
            THERMAL_SENSOR_3_USAGE_LEN = 3,

            // Byte 265: Thermal Sensor 0 I2C Address
            THERMAL_SENSOR_0_I2C_ADDRESS_BYTE = 265,
            THERMAL_SENSOR_0_I2C_ADDRESS_START = 0,
            THERMAL_SENSOR_0_I2C_ADDRESS_LEN = 8,

            // Byte 266: Thermal Sensor 1 I2C Address
            THERMAL_SENSOR_1_I2C_ADDRESS_BYTE = 266,
            THERMAL_SENSOR_1_I2C_ADDRESS_START = 0,
            THERMAL_SENSOR_1_I2C_ADDRESS_LEN = 8,

            // Byte 267: Thermal Sensor 2 I2C Address
            THERMAL_SENSOR_2_I2C_ADDRESS_BYTE = 267,
            THERMAL_SENSOR_2_I2C_ADDRESS_START = 0,
            THERMAL_SENSOR_2_I2C_ADDRESS_LEN = 8,

            // Byte 268: Thermal Sensor 3 I2C Address
            THERMAL_SENSOR_3_I2C_ADDRESS_BYTE = 268,
            THERMAL_SENSOR_3_I2C_ADDRESS_START = 0,
            THERMAL_SENSOR_3_I2C_ADDRESS_LEN = 8,

            // Byte 269: Differential Buffer Thermal Sensor Profile
            THERMAL_SENSOR_DIFF_PROFILE_BYTE = 269,
            THERMAL_SENSOR_DIFF_AVAIL_START = 0,
            THERMAL_SENSOR_DIFF_AVAIL_LEN = 1,
            THERMAL_SENSOR_DIFF_TYPE_START = 1,
            THERMAL_SENSOR_DIFF_TYPE_LEN = 4,
            THERMAL_SENSOR_DIFF_USAGE_START = 5,
            THERMAL_SENSOR_DIFF_USAGE_LEN = 3,

            // Byte 270: Differential Buffer Thermal Sensor I2C Address
            THERMAL_SENSOR_DIFF_I2C_ADDRESS_BYTE = 270,
            THERMAL_SENSOR_DIFF_I2C_ADDRESS_START = 0,
            THERMAL_SENSOR_DIFF_I2C_ADDRESS_LEN = 8,

            // Byte 271: Registered Clock Drivers (RCD)
            MODULE_RCD_BYTE = 271,
            MODULE_RCD_MEDIA_CONTROLLER_TYPE_START = 0,
            MODULE_RCD_MEDIA_CONTROLLER_TYPE_LEN = 4,
            MODULE_RCD_JEDEC_COMPLIANT_START = 5,
            MODULE_RCD_JEDEC_COMPLIANT_LEN = 1,
            MODULE_RCD_START = 6,
            MODULE_RCD_LEN = 2,

            // Byte 272-273: RCD MFG ID Code
            RCD_MFG_ID_LSB_BYTE = 272,
            RCD_MFG_ID_LSB_START = 0,
            RCD_MFG_ID_LSB_LEN = 8,
            RCD_MFG_ID_MSB_BYTE = 273,
            RCD_MFG_ID_MSB_START = 0,
            RCD_MFG_ID_MSB_LEN = 8,

            // Byte 274: RCD Revision Nunber
            RCD_REV_NUM_BYTE = 274,
            RCD_REV_NUM_START = 0,
            RCD_REV_NUM_LEN = 8,

            // Byte 275: RCD0 I2C Address
            RCD0_I2C_ADDR_BYTE = 275,
            RCD0_I2C_ADDR_START = 0,
            RCD0_I2C_ADDR_LEN = 8,

            // Byte 276: RCD1 I2C Address
            RCD1_I2C_ADDR_BYTE = 276,
            RCD1_I2C_ADDR_START = 0,
            RCD1_I2C_ADDR_LEN = 8,

            // Byte 277: SPD Content Revision
            SPD_CONTENT_REVISION_BYTE = 277,
            SPD_CONTENT_REVISION_START = 0,
            SPD_CONTENT_REVISION_LEN = 8,

            // Byte 278: SPD REDUNDANCY
            SPD_REDUNDANCY_BYTE = 286,
            SPD_REDUNDANCY_START = 0,
            SPD_REDUNDANCY_LEN = 1,

            // Byte 279: SPD I2C Address
            SPD_REDUNDANCY_I2C_ADDR_BYTE = 286,
            SPD_REDUNDANCY_I2C_ADDR_START = 0,
            SPD_REDUNDANCY_I2C_ADDR_LEN = 8,

            // Byte 280: ORing MOSFET Vendors
            ORING_MOSFET_BYTE = 280,
            ORING_MOSFET_SMALL_START = 3,
            ORING_MOSFET_SMALL_LEN = 4,
            ORING_MOSFET_BIG_START = 4,
            ORING_MOSFET_BIG_LEN = 4,

            // Byte 281: DMB I2C Address
            DMB_I2C_ADDRESS_BYTE = 281,
            DMB_I2C_ADDRESS_START = 0,
            DMB_I2C_ADDRESS_LEN = 8,

            // Byte 282: DMB Manfacture ID code 1st byte
            DMB_MFG_CODE1_BYTE = 282,
            CONTINUATION_CODE_START = 0,
            CONTINUATION_CODE_LEN = 8,

            // Byte 283: DMB Manfacture ID code 2nd byte
            DMB_MFG_CODE2_BYTE = 283,
            LAST_NON_ZERO_START = 0,
            LAST_NON_ZERO_LEN = 8,

            // Byte 284: DMB Revision Number
            DMB_REV_BYTE = 284,
            DMB_REV_START = 0,
            DMB_REV_LEN = 8,

            // Byte 286: ADC I2C Address
            ADC_I2C_ADDRESS_BYTE = 286,
            ADC_I2C_ADDRESS_START = 0,
            ADC_I2C_ADDRESS_LEN = 8,

            // Byte 287: PMIC Status Mask 0
            PMIC_STATUS_MASK0_BYTE = 287,
            PMIC_STATUS_MASK0_START = 0,
            PMIC_STATUS_MASK0_LEN = 8,

            // Byte 288: PMIC Status Mask 1
            PMIC_STATUS_MASK1_BYTE = 288,
            PMIC_STATUS_MASK1_START = 0,
            PMIC_STATUS_MASK1_LEN = 8,

            // Byte 289: PMIC PF Threshold 1
            PMIC_PF_THRESHOLD_BYTE = 289,
            PMIC_PF_THRESHOLD_START = 0,
            PMIC_PF_THRESHOLD_LEN = 8,

            // Byte 290: PMIC0 IIC Address
            PMIC0_IIC_ADDRESS_BYTE = 290,
            PMIC0_IIC_ADDRESS_START = 0,
            PMIC0_IIC_ADDRESS_LEN = 8,

            // Byte 291: PMIC1 IIC Address
            PMIC1_IIC_ADDRESS_BYTE = 291,
            PMIC1_IIC_ADDRESS_START = 0,
            PMIC1_IIC_ADDRESS_LEN = 8,

            // Byte 292: PMIC2 IIC Address
            PMIC2_IIC_ADDRESS_BYTE = 292,
            PMIC2_IIC_ADDRESS_START = 0,
            PMIC2_IIC_ADDRESS_LEN = 8,

            // Byte 293: PMIC3 IIC Address
            PMIC3_IIC_ADDRESS_BYTE = 293,
            PMIC3_IIC_ADDRESS_START = 0,
            PMIC3_IIC_ADDRESS_LEN = 8,

            // Byte 294: PMIC0 Sequence
            PMIC0_SEQUENCE_BYTE = 294,
            PMIC0_SUPPLY_VOLTAGE_START = 0,
            PMIC0_SUPPLY_VOLTAGE_LEN = 5,
            PMIC0_SEQUENCE_START = 5,
            PMIC0_SEQUENCE_LEN = 3,

            // Byte 295: PMIC1 Sequence
            PMIC1_SEQUENCE_BYTE = 295,
            PMIC1_SUPPLY_VOLTAGE_START = 0,
            PMIC1_SUPPLY_VOLTAGE_LEN = 5,
            PMIC1_SEQUENCE_START = 5,
            PMIC1_SEQUENCE_LEN = 3,

            // Byte 296: PMIC2 Sequence
            PMIC2_SEQUENCE_BYTE = 296,
            PMIC2_SUPPLY_VOLTAGE_START = 0,
            PMIC2_SUPPLY_VOLTAGE_LEN = 5,
            PMIC2_SEQUENCE_START = 5,
            PMIC2_SEQUENCE_LEN = 3,

            // Byte 297: PMIC3 Sequence
            PMIC3_SEQUENCE_BYTE = 297,
            PMIC3_SUPPLY_VOLTAGE_START = 0,
            PMIC3_SUPPLY_VOLTAGE_LEN = 5,
            PMIC3_SEQUENCE_START = 5,
            PMIC3_SEQUENCE_LEN = 3,

            // Byte 298: PMIC0 Voltage Range Offsets
            PMIC0_VOLT_RANGE_OFFSET_BYTE = 298,
            PMIC0_VOLT_RANGE_OFFSET_SWA_START = 6,
            PMIC0_VOLT_RANGE_OFFSET_SWA_LEN = 2,
            PMIC0_VOLT_RANGE_OFFSET_SWB_START = 4,
            PMIC0_VOLT_RANGE_OFFSET_SWB_LEN = 2,
            PMIC0_VOLT_RANGE_OFFSET_SWC_START = 2,
            PMIC0_VOLT_RANGE_OFFSET_SWC_LEN = 2,
            PMIC0_VOLT_RANGE_OFFSET_SWD_START = 0,
            PMIC0_VOLT_RANGE_OFFSET_SWD_LEN = 2,

            // Byte 299: PMIC1 Voltage Range Offsets
            PMIC1_VOLT_RANGE_OFFSET_BYTE = 299,
            PMIC1_VOLT_RANGE_OFFSET_SWA_START = 6,
            PMIC1_VOLT_RANGE_OFFSET_SWA_LEN = 2,
            PMIC1_VOLT_RANGE_OFFSET_SWB_START = 4,
            PMIC1_VOLT_RANGE_OFFSET_SWB_LEN = 2,
            PMIC1_VOLT_RANGE_OFFSET_SWC_START = 2,
            PMIC1_VOLT_RANGE_OFFSET_SWC_LEN = 2,
            PMIC1_VOLT_RANGE_OFFSET_SWD_START = 0,
            PMIC1_VOLT_RANGE_OFFSET_SWD_LEN = 2,

            // Byte 300: PMIC2 Voltage Range Offsets
            PMIC2_VOLT_RANGE_OFFSET_BYTE = 300,
            PMIC2_VOLT_RANGE_OFFSET_SWA_START = 6,
            PMIC2_VOLT_RANGE_OFFSET_SWA_LEN = 2,
            PMIC2_VOLT_RANGE_OFFSET_SWB_START = 4,
            PMIC2_VOLT_RANGE_OFFSET_SWB_LEN = 2,
            PMIC2_VOLT_RANGE_OFFSET_SWC_START = 2,
            PMIC2_VOLT_RANGE_OFFSET_SWC_LEN = 2,
            PMIC2_VOLT_RANGE_OFFSET_SWD_START = 0,
            PMIC2_VOLT_RANGE_OFFSET_SWD_LEN = 2,

            // Byte 301: PMIC3 Voltage Range Offsets
            PMIC3_VOLT_RANGE_OFFSET_BYTE = 301,
            PMIC3_VOLT_RANGE_OFFSET_SWA_START = 6,
            PMIC3_VOLT_RANGE_OFFSET_SWA_LEN = 2,
            PMIC3_VOLT_RANGE_OFFSET_SWB_START = 4,
            PMIC3_VOLT_RANGE_OFFSET_SWB_LEN = 2,
            PMIC3_VOLT_RANGE_OFFSET_SWC_START = 2,
            PMIC3_VOLT_RANGE_OFFSET_SWC_LEN = 2,
            PMIC3_VOLT_RANGE_OFFSET_SWD_START = 0,
            PMIC3_VOLT_RANGE_OFFSET_SWD_LEN = 2,

            // Byte 302: PMIC0 Voltage Domains
            PMIC0_VOLT_DOMAINS_BYTE = 302,
            PMIC0_VOLT_DOMAINS_SWA_START = 6,
            PMIC0_VOLT_DOMAINS_SWA_LEN = 2,
            PMIC0_VOLT_DOMAINS_SWB_START = 4,
            PMIC0_VOLT_DOMAINS_SWB_LEN = 2,
            PMIC0_VOLT_DOMAINS_SWC_START = 2,
            PMIC0_VOLT_DOMAINS_SWC_LEN = 2,
            PMIC0_VOLT_DOMAINS_SWD_START = 0,
            PMIC0_VOLT_DOMAINS_SWD_LEN = 2,

            // Byte 303: PMIC1 Voltage Domains
            PMIC1_VOLT_DOMAINS_BYTE = 303,
            PMIC1_VOLT_DOMAINS_SWA_START = 6,
            PMIC1_VOLT_DOMAINS_SWA_LEN = 2,
            PMIC1_VOLT_DOMAINS_SWB_START = 4,
            PMIC1_VOLT_DOMAINS_SWB_LEN = 2,
            PMIC1_VOLT_DOMAINS_SWC_START = 2,
            PMIC1_VOLT_DOMAINS_SWC_LEN = 2,
            PMIC1_VOLT_DOMAINS_SWD_START = 0,
            PMIC1_VOLT_DOMAINS_SWD_LEN = 2,

            // Byte 304: PMIC2 Voltage Domains
            PMIC2_VOLT_DOMAINS_BYTE = 304,
            PMIC2_VOLT_DOMAINS_SWA_START = 6,
            PMIC2_VOLT_DOMAINS_SWA_LEN = 2,
            PMIC2_VOLT_DOMAINS_SWB_START = 4,
            PMIC2_VOLT_DOMAINS_SWB_LEN = 2,
            PMIC2_VOLT_DOMAINS_SWC_START = 2,
            PMIC2_VOLT_DOMAINS_SWC_LEN = 2,
            PMIC2_VOLT_DOMAINS_SWD_START = 0,
            PMIC2_VOLT_DOMAINS_SWD_LEN = 2,

            // Byte 305: PMIC3 Voltage Domains
            PMIC3_VOLT_DOMAINS_BYTE = 305,
            PMIC3_VOLT_DOMAINS_SWA_START = 6,
            PMIC3_VOLT_DOMAINS_SWA_LEN = 2,
            PMIC3_VOLT_DOMAINS_SWB_START = 4,
            PMIC3_VOLT_DOMAINS_SWB_LEN = 2,
            PMIC3_VOLT_DOMAINS_SWC_START = 2,
            PMIC3_VOLT_DOMAINS_SWC_LEN = 2,
            PMIC3_VOLT_DOMAINS_SWD_START = 0,
            PMIC3_VOLT_DOMAINS_SWD_LEN = 2,

            // Byte 306: PMIC0 SWA Voltage Setting
            PMIC0_SWA_VOLT_SET_BYTE = 306,
            PMIC0_SWA_VOLT_SET_START = 0,
            PMIC0_SWA_VOLT_SET_LEN = 7,
            PMIC0_SWA_RANGE_SELECT_START = 7,
            PMIC0_SWA_RANGE_SELECT_LEN = 1,

            // Byte 307: PMIC0 SWA Voltage Offset
            PMIC0_SWA_VOLT_OFF_BYTE = 307,
            PMIC0_SWA_VOLT_OFF_START = 0,
            PMIC0_SWA_VOLT_OFF_LEN = 7,
            PMIC0_SWA_OFF_DIRECTION_START = 7,
            PMIC0_SWA_OFF_DIRECTION_LEN = 1,

            // Byte 308: PMIC0 SWA Delay Sequence Order
            PMIC0_SWA_DELAY_BYTE = 308,
            PMIC0_SWA_DELAY_START = 0,
            PMIC0_SWA_DELAY_LEN = 4,
            PMIC0_SWA_ORDER_START = 4,
            PMIC0_SWA_ORDER_LEN = 4,

            // Byte 309: PMIC0 SWB Voltage Setting
            PMIC0_SWB_VOLT_SET_BYTE = 309,
            PMIC0_SWB_VOLT_SET_START = 0,
            PMIC0_SWB_VOLT_SET_LEN = 7,
            PMIC0_SWB_RANGE_SELECT_START = 7,
            PMIC0_SWB_RANGE_SELECT_LEN = 1,

            // Byte 310: PMIC0 SWB Voltage Offset
            PMIC0_SWB_VOLT_OFF_BYTE = 310,
            PMIC0_SWB_VOLT_OFF_START = 0,
            PMIC0_SWB_VOLT_OFF_LEN = 7,
            PMIC0_SWB_OFF_DIRECTION_START = 7,
            PMIC0_SWB_OFF_DIRECTION_LEN = 1,

            // Byte 311: PMIC0 SWB Delay Sequence Order
            PMIC0_SWB_DELAY_BYTE = 311,
            PMIC0_SWB_DELAY_START = 0,
            PMIC0_SWB_DELAY_LEN = 4,
            PMIC0_SWB_ORDER_START = 4,
            PMIC0_SWB_ORDER_LEN = 4,

            // Byte 312: PMIC0 SWC Voltage Setting
            PMIC0_SWC_VOLT_SET_BYTE = 312,
            PMIC0_SWC_VOLT_SET_START = 0,
            PMIC0_SWC_VOLT_SET_LEN = 7,
            PMIC0_SWC_RANGE_SELECT_START = 7,
            PMIC0_SWC_RANGE_SELECT_LEN = 1,

            // Byte 313: PMIC0 SWC Voltage Offset
            PMIC0_SWC_VOLT_OFF_BYTE = 313,
            PMIC0_SWC_VOLT_OFF_START = 0,
            PMIC0_SWC_VOLT_OFF_LEN = 7,
            PMIC0_SWC_OFF_DIRECTION_START = 7,
            PMIC0_SWC_OFF_DIRECTION_LEN = 1,

            // Byte 314: PMIC0 SWC Delay Sequence Order
            PMIC0_SWC_DELAY_BYTE = 314,
            PMIC0_SWC_DELAY_START = 0,
            PMIC0_SWC_DELAY_LEN = 4,
            PMIC0_SWC_ORDER_START = 4,
            PMIC0_SWC_ORDER_LEN = 4,

            // Byte 315: PMIC0 SWD Voltage Setting
            PMIC0_SWD_VOLT_SET_BYTE = 315,
            PMIC0_SWD_VOLT_SET_START = 0,
            PMIC0_SWD_VOLT_SET_LEN = 7,
            PMIC0_SWD_RANGE_SELECT_START = 7,
            PMIC0_SWD_RANGE_SELECT_LEN = 1,

            // Byte 316: PMIC0 SWD Voltage Offset
            PMIC0_SWD_VOLT_OFF_BYTE = 316,
            PMIC0_SWD_VOLT_OFF_START = 0,
            PMIC0_SWD_VOLT_OFF_LEN = 7,
            PMIC0_SWD_OFF_DIRECTION_START = 7,
            PMIC0_SWD_OFF_DIRECTION_LEN = 1,

            // Byte 317: PMIC0 SWD Delay Sequence Order
            PMIC0_SWD_DELAY_BYTE = 317,
            PMIC0_SWD_DELAY_START = 0,
            PMIC0_SWD_DELAY_LEN = 4,
            PMIC0_SWD_ORDER_START = 4,
            PMIC0_SWD_ORDER_LEN = 4,

            // Byte 318: PMIC0 Phase Combination and redundancy
            PMIC0_PHASE_COMBIN_BYTE = 318,
            PMIC0_REDUNDANCY_START = 0,
            PMIC0_REDUNDANCY_LEN = 1,
            PMIC0_PHASE_COMBIN_START = 4,
            PMIC0_PHASE_COMBIN_LEN = 4,

            // Byte 319: PMIC1 SWA Voltage Setting
            PMIC1_SWA_VOLT_SET_BYTE = 319,
            PMIC1_SWA_VOLT_SET_START = 0,
            PMIC1_SWA_VOLT_SET_LEN = 7,
            PMIC1_SWA_RANGE_SELECT_START = 7,
            PMIC1_SWA_RANGE_SELECT_LEN = 1,

            // Byte 320: PMIC1 SWA Voltage Offset
            PMIC1_SWA_VOLT_OFF_BYTE = 320,
            PMIC1_SWA_VOLT_OFF_START = 0,
            PMIC1_SWA_VOLT_OFF_LEN = 7,
            PMIC1_SWA_OFF_DIRECTION_START = 7,
            PMIC1_SWA_OFF_DIRECTION_LEN = 1,

            // Byte 321: PMIC1 SWA Delay Sequence Order
            PMIC1_SWA_DELAY_BYTE = 321,
            PMIC1_SWA_DELAY_START = 0,
            PMIC1_SWA_DELAY_LEN = 4,
            PMIC1_SWA_ORDER_START = 4,
            PMIC1_SWA_ORDER_LEN = 4,

            // Byte 322: PMIC1 SWB Voltage Setting
            PMIC1_SWB_VOLT_SET_BYTE = 322,
            PMIC1_SWB_VOLT_SET_START = 0,
            PMIC1_SWB_VOLT_SET_LEN = 7,
            PMIC1_SWB_RANGE_SELECT_START = 7,
            PMIC1_SWB_RANGE_SELECT_LEN = 1,

            // Byte 323: PMIC1 SWB Voltage Offset
            PMIC1_SWB_VOLT_OFF_BYTE = 323,
            PMIC1_SWB_VOLT_OFF_START = 0,
            PMIC1_SWB_VOLT_OFF_LEN = 7,
            PMIC1_SWB_OFF_DIRECTION_START = 7,
            PMIC1_SWB_OFF_DIRECTION_LEN = 1,

            // Byte 324: PMIC1 SWB Delay Sequence Order
            PMIC1_SWB_DELAY_BYTE = 324,
            PMIC1_SWB_DELAY_START = 0,
            PMIC1_SWB_DELAY_LEN = 4,
            PMIC1_SWB_ORDER_START = 4,
            PMIC1_SWB_ORDER_LEN = 4,

            // Byte 325: PMIC1 SWC Voltage Setting
            PMIC1_SWC_VOLT_SET_BYTE = 325,
            PMIC1_SWC_VOLT_SET_START = 0,
            PMIC1_SWC_VOLT_SET_LEN = 7,
            PMIC1_SWC_RANGE_SELECT_START = 7,
            PMIC1_SWC_RANGE_SELECT_LEN = 1,

            // Byte 326: PMIC1 SWC Voltage Offset
            PMIC1_SWC_VOLT_OFF_BYTE = 326,
            PMIC1_SWC_VOLT_OFF_START = 0,
            PMIC1_SWC_VOLT_OFF_LEN = 7,
            PMIC1_SWC_OFF_DIRECTION_START = 7,
            PMIC1_SWC_OFF_DIRECTION_LEN = 1,

            // Byte 327: PMIC1 SWC Delay Sequence Order
            PMIC1_SWC_DELAY_BYTE = 327,
            PMIC1_SWC_DELAY_START = 0,
            PMIC1_SWC_DELAY_LEN = 4,
            PMIC1_SWC_ORDER_START = 4,
            PMIC1_SWC_ORDER_LEN = 4,

            // Byte 328: PMIC1 SWD Voltage Setting
            PMIC1_SWD_VOLT_SET_BYTE = 328,
            PMIC1_SWD_VOLT_SET_START = 0,
            PMIC1_SWD_VOLT_SET_LEN = 7,
            PMIC1_SWD_RANGE_SELECT_START = 7,
            PMIC1_SWD_RANGE_SELECT_LEN = 1,

            // Byte 329: PMIC1 SWD Voltage Offset
            PMIC1_SWD_VOLT_OFF_BYTE = 329,
            PMIC1_SWD_VOLT_OFF_START = 0,
            PMIC1_SWD_VOLT_OFF_LEN = 7,
            PMIC1_SWD_OFF_DIRECTION_START = 7,
            PMIC1_SWD_OFF_DIRECTION_LEN = 1,

            // Byte 330: PMIC1 SWD Delay Sequence Order
            PMIC1_SWD_DELAY_BYTE = 330,
            PMIC1_SWD_DELAY_START = 0,
            PMIC1_SWD_DELAY_LEN = 4,
            PMIC1_SWD_ORDER_START = 4,
            PMIC1_SWD_ORDER_LEN = 4,

            // Byte 331: PMIC1 Phase Combination and Redundancy
            PMIC1_PHASE_COMBIN_BYTE = 331,
            PMIC1_REDUNDANCY_START = 0,
            PMIC1_REDUNDANCY_LEN = 1,
            PMIC1_PHASE_COMBIN_START = 4,
            PMIC1_PHASE_COMBIN_LEN = 4,

            // Byte 332: PMIC2 SWA Voltage Setting
            PMIC2_SWA_VOLT_SET_BYTE = 332,
            PMIC2_SWA_VOLT_SET_START = 0,
            PMIC2_SWA_VOLT_SET_LEN = 7,
            PMIC2_SWA_RANGE_SELECT_START = 7,
            PMIC2_SWA_RANGE_SELECT_LEN = 1,

            // Byte 333: PMIC2 SWA Voltage Offset
            PMIC2_SWA_VOLT_OFF_BYTE = 333,
            PMIC2_SWA_VOLT_OFF_START = 0,
            PMIC2_SWA_VOLT_OFF_LEN = 7,
            PMIC2_SWA_OFF_DIRECTION_START = 7,
            PMIC2_SWA_OFF_DIRECTION_LEN = 1,

            // Byte 334: PMIC2 SWA Delay Sequence Order
            PMIC2_SWA_DELAY_BYTE = 334,
            PMIC2_SWA_DELAY_START = 0,
            PMIC2_SWA_DELAY_LEN = 4,
            PMIC2_SWA_ORDER_START = 4,
            PMIC2_SWA_ORDER_LEN = 4,

            // Byte 335: PMIC2 SWB Voltage Setting
            PMIC2_SWB_VOLT_SET_BYTE = 335,
            PMIC2_SWB_VOLT_SET_START = 0,
            PMIC2_SWB_VOLT_SET_LEN = 7,
            PMIC2_SWB_RANGE_SELECT_START = 7,
            PMIC2_SWB_RANGE_SELECT_LEN = 1,

            // Byte 336: PMIC2 SWB Voltage Offset
            PMIC2_SWB_VOLT_OFF_BYTE = 336,
            PMIC2_SWB_VOLT_OFF_START = 0,
            PMIC2_SWB_VOLT_OFF_LEN = 7,
            PMIC2_SWB_OFF_DIRECTION_START = 7,
            PMIC2_SWB_OFF_DIRECTION_LEN = 1,

            // Byte 337: PMIC2 SWB Delay Sequence Order
            PMIC2_SWB_DELAY_BYTE = 337,
            PMIC2_SWB_DELAY_START = 0,
            PMIC2_SWB_DELAY_LEN = 4,
            PMIC2_SWB_ORDER_START = 4,
            PMIC2_SWB_ORDER_LEN = 4,

            // Byte 338: PMIC2 SWC Voltage Setting
            PMIC2_SWC_VOLT_SET_BYTE = 338,
            PMIC2_SWC_VOLT_SET_START = 0,
            PMIC2_SWC_VOLT_SET_LEN = 7,
            PMIC2_SWC_RANGE_SELECT_START = 7,
            PMIC2_SWC_RANGE_SELECT_LEN = 1,

            // Byte 339: PMIC2 SWC Voltage Offset
            PMIC2_SWC_VOLT_OFF_BYTE = 339,
            PMIC2_SWC_VOLT_OFF_START = 0,
            PMIC2_SWC_VOLT_OFF_LEN = 7,
            PMIC2_SWC_OFF_DIRECTION_START = 7,
            PMIC2_SWC_OFF_DIRECTION_LEN = 1,

            // Byte 340: PMIC2 SWC Delay Sequence Order
            PMIC2_SWC_DELAY_BYTE = 340,
            PMIC2_SWC_DELAY_START = 0,
            PMIC2_SWC_DELAY_LEN = 4,
            PMIC2_SWC_ORDER_START = 4,
            PMIC2_SWC_ORDER_LEN = 4,

            // Byte 341: PMIC2 SWD Voltage Setting
            PMIC2_SWD_VOLT_SET_BYTE = 341,
            PMIC2_SWD_VOLT_SET_START = 0,
            PMIC2_SWD_VOLT_SET_LEN = 7,
            PMIC2_SWD_RANGE_SELECT_START = 7,
            PMIC2_SWD_RANGE_SELECT_LEN = 1,

            // Byte 342: PMIC2 SWD Voltage Offset
            PMIC2_SWD_VOLT_OFF_BYTE = 342,
            PMIC2_SWD_VOLT_OFF_START = 0,
            PMIC2_SWD_VOLT_OFF_LEN = 7,
            PMIC2_SWD_OFF_DIRECTION_START = 7,
            PMIC2_SWD_OFF_DIRECTION_LEN = 1,

            // Byte 343: PMIC2 SWD Delay Sequence Order
            PMIC2_SWD_DELAY_BYTE = 343,
            PMIC2_SWD_DELAY_START = 0,
            PMIC2_SWD_DELAY_LEN = 4,
            PMIC2_SWD_ORDER_START = 4,
            PMIC2_SWD_ORDER_LEN = 4,

            // Byte 344: PMIC2 Phase Combination and Redundancy
            PMIC2_PHASE_COMBIN_BYTE = 344,
            PMIC2_REDUNDANCY_START = 0,
            PMIC2_REDUNDANCY_LEN = 1,
            PMIC2_PHASE_COMBIN_START = 4,
            PMIC2_PHASE_COMBIN_LEN = 4,

            // Byte 345: PMIC3 SWA Voltage Setting
            PMIC3_SWA_VOLT_SET_BYTE = 345,
            PMIC3_SWA_VOLT_SET_START = 0,
            PMIC3_SWA_VOLT_SET_LEN = 7,
            PMIC3_SWA_RANGE_SELECT_START = 7,
            PMIC3_SWA_RANGE_SELECT_LEN = 1,

            // Byte 346: PMIC3 SWA Voltage Offset
            PMIC3_SWA_VOLT_OFF_BYTE = 346,
            PMIC3_SWA_VOLT_OFF_START = 0,
            PMIC3_SWA_VOLT_OFF_LEN = 7,
            PMIC3_SWA_OFF_DIRECTION_START = 7,
            PMIC3_SWA_OFF_DIRECTION_LEN = 1,

            // Byte 347: PMIC3 SWA Delay Sequence Order
            PMIC3_SWA_DELAY_BYTE = 347,
            PMIC3_SWA_DELAY_START = 0,
            PMIC3_SWA_DELAY_LEN = 4,
            PMIC3_SWA_ORDER_START = 4,
            PMIC3_SWA_ORDER_LEN = 4,

            // Byte 348: PMIC3 SWB Voltage Setting
            PMIC3_SWB_VOLT_SET_BYTE = 348,
            PMIC3_SWB_VOLT_SET_START = 0,
            PMIC3_SWB_VOLT_SET_LEN = 7,
            PMIC3_SWB_RANGE_SELECT_START = 7,
            PMIC3_SWB_RANGE_SELECT_LEN = 1,

            // Byte 349: PMIC3 SWB Voltage Offset
            PMIC3_SWB_VOLT_OFF_BYTE = 349,
            PMIC3_SWB_VOLT_OFF_START = 0,
            PMIC3_SWB_VOLT_OFF_LEN = 7,
            PMIC3_SWB_OFF_DIRECTION_START = 7,
            PMIC3_SWB_OFF_DIRECTION_LEN = 1,

            // Byte 350: PMIC3 SWB Delay Sequence Order
            PMIC3_SWB_DELAY_BYTE = 350,
            PMIC3_SWB_DELAY_START = 0,
            PMIC3_SWB_DELAY_LEN = 4,
            PMIC3_SWB_ORDER_START = 4,
            PMIC3_SWB_ORDER_LEN = 4,

            // Byte 351: PMIC3 SWC Voltage Setting
            PMIC3_SWC_VOLT_SET_BYTE = 351,
            PMIC3_SWC_VOLT_SET_START = 0,
            PMIC3_SWC_VOLT_SET_LEN = 7,
            PMIC3_SWC_RANGE_SELECT_START = 7,
            PMIC3_SWC_RANGE_SELECT_LEN = 1,

            // Byte 352: PMIC3 SWC Voltage Offset
            PMIC3_SWC_VOLT_OFF_BYTE = 352,
            PMIC3_SWC_VOLT_OFF_START = 0,
            PMIC3_SWC_VOLT_OFF_LEN = 7,
            PMIC3_SWC_OFF_DIRECTION_START = 7,
            PMIC3_SWC_OFF_DIRECTION_LEN = 1,

            // Byte 353: PMIC3 SWC Delay Sequence Order
            PMIC3_SWC_DELAY_BYTE = 353,
            PMIC3_SWC_DELAY_START = 0,
            PMIC3_SWC_DELAY_LEN = 4,
            PMIC3_SWC_ORDER_START = 4,
            PMIC3_SWC_ORDER_LEN = 4,

            // Byte 354: PMIC3 SWD Voltage Setting
            PMIC3_SWD_VOLT_SET_BYTE = 354,
            PMIC3_SWD_VOLT_SET_START = 0,
            PMIC3_SWD_VOLT_SET_LEN = 7,
            PMIC3_SWD_RANGE_SELECT_START = 7,
            PMIC3_SWD_RANGE_SELECT_LEN = 1,

            // Byte 355: PMIC3 SWD Voltage Offset
            PMIC3_SWD_VOLT_OFF_BYTE = 355,
            PMIC3_SWD_VOLT_OFF_START = 0,
            PMIC3_SWD_VOLT_OFF_LEN = 7,
            PMIC3_SWD_OFF_DIRECTION_START = 7,
            PMIC3_SWD_OFF_DIRECTION_LEN = 1,

            // Byte 356: PMIC3 SWD Delay Sequence Order
            PMIC3_SWD_DELAY_BYTE = 356,
            PMIC3_SWD_DELAY_START = 0,
            PMIC3_SWD_DELAY_LEN = 4,
            PMIC3_SWD_ORDER_START = 4,
            PMIC3_SWD_ORDER_LEN = 4,

            // Byte 357: PMIC3 Phase Combination and Redundancy
            PMIC3_PHASE_COMBIN_BYTE = 357,
            PMIC3_REDUNDANCY_START = 0,
            PMIC3_REDUNDANCY_LEN = 1,
            PMIC3_PHASE_COMBIN_START = 4,
            PMIC3_PHASE_COMBIN_LEN = 4,

            // Byte 358: Voltage VIN_MTG Edge Connector
            VIN_MGMT_BYTE = 358,
            VIN_MGMT_NOMINAL_START = 0,
            VIN_MGMT_NOMINAL_LEN = 4,
            VIN_MGMT_OPERABLE_START = 4,
            VIN_MGMT_OPERABLE_LEN = 2,
            VIN_MGMT_ENDURANT_START = 6,
            VIN_MGMT_ENDURANT_LEN = 2,

            // Byte 359: Voltage VIN_BULK Edge Connector
            VIN_BULK_BYTE = 359,
            VIN_BULK_NOMINAL_START = 0,
            VIN_BULK_NOMINAL_LEN = 4,
            VIN_BULK_OPERABLE_START = 4,
            VIN_BULK_OPERABLE_LEN = 2,
            VIN_BULK_ENDURANT_START = 6,
            VIN_BULK_ENDURANT_LEN = 2,

            // Byte 360: Thermal Heat Spreader Solution
            THERMAL_BYTE = 360,
            HEAT_SPREADER_SOL_START = 0,
            HEAT_SPREADER_SOL_LEN = 1,
            HEAT_SPREADER_CHAR_START = 1,
            HEAT_SPREADER_CHAR_LEN = 7,

            // Byte 361: Module Thermal Sensors
            THERMAL_SENSORS_BYTE = 361,
            MOD_THERMAL_SENSOR_START = 0,
            MOD_THERMAL_SENSOR_LEN = 3,

            // Byte 362: Host Interface Protocols
            PROTOCOL_SUPPORT_BYTE = 362,
            PROTOCOL_SUPPORT_START = 4,
            PROTOCOL_SUPPORT_LEN = 4,

            // Byte 363: Host Interface Speed Supported
            SPEED_SUPPORTED_LSB_BYTE = 363,
            SPEED_SUPPORTED_LSB_START = 1,
            SPEED_SUPPORTED_LSB_LEN = 7,

            // Byte 364: Mem Alert Enable and Pull-Up
            MEM_ALERT_EN_PULL_UP_BYTE = 364,
            PHY_A0_B0_MEM_ALERT_PULL_UP_VALUE_START = 5,
            PHY_A0_B0_MEM_ALERT_PULL_UP_VALUE_LEN = 3,
            PHY_A1_B1_MEM_ALERT_PULL_UP_VALUE_START = 2,
            PHY_A1_B1_MEM_ALERT_PULL_UP_VALUE_LEN = 3,
            PHY_A0_B0_MEM_ALERT_START = 1,
            PHY_A0_B0_MEM_ALERT_LEN = 1,
            PHY_A1_B1_MEM_ALERT_START = 0,
            PHY_A1_B1_MEM_ALERT_LEN = 1,

            // Byte 365: Address Mirroring
            ADDRESS_MIRROR_BYTE = 365,
            ADDRESS_MIRROR_START = 0,
            ADDRESS_MIRROR_LEN = 8,

            // Byte 366: Byte enables LSB
            BYTE_ENABLES_LSB_BYTE = 366,
            BYTE_ENABLES_LSB_START = 0,
            BYTE_ENABLES_LSB_LEN = 8,

            // Byte 367: Byte enables MSB
            BYTE_ENABLES_MSB_BYTE = 367,
            BYTE_ENABLES_MSB_START = 6,
            BYTE_ENABLES_MSB_LEN = 2,

            // Byte 368: Nibble enables LSB0
            NIBBLE_ENABLES_LSB0_BYTE = 368,
            NIBBLE_ENABLES_LSB0_START = 0,
            NIBBLE_ENABLES_LSB0_LEN = 8,

            // Byte 369: Nibble enables MSB0
            NIBBLE_ENABLES_MSB0_BYTE = 369,
            NIBBLE_ENABLES_MSB0_START = 0,
            NIBBLE_ENABLES_MSB0_LEN = 8,

            // Byte 370: Nibble enables LSB1
            NIBBLE_ENABLES_LSB1_BYTE = 370,
            NIBBLE_ENABLES_LSB1_START = 4,
            NIBBLE_ENABLES_LSB1_LEN = 4,

            // Byte 371: Nibble enables MSB1
            // Reserved

            // Byte 372: Memory Channel Enable and Redundant Chip
            MEMORY_CHANNEL_EN_REDUNDANT_CHIP_BYTE = 372,
            REDUNDANT_CS_EN_CHA0_START = 7,
            REDUNDANT_CS_EN_CHA0_LEN = 1,
            REDUNDANT_CS_EN_CHB0_START = 6,
            REDUNDANT_CS_EN_CHB0_LEN = 1,
            REDUNDANT_CS_EN_CHA1_START = 5,
            REDUNDANT_CS_EN_CHA1_LEN = 1,
            REDUNDANT_CS_EN_CHB1_START = 4,
            REDUNDANT_CS_EN_CHB1_LEN = 1,
            MEMORY_CHA0_EXIST_START = 3,
            MEMORY_CHA0_EXIST_LEN = 1,
            MEMORY_CHB0_EXIST_START = 2,
            MEMORY_CHB0_EXIST_LEN = 1,
            MEMORY_CHA1_EXIST_START = 1,
            MEMORY_CHA1_EXIST_LEN = 1,
            MEMORY_CHB1_EXIST_START = 0,
            MEMORY_CHB1_EXIST_LEN = 1,

            // Byte 373: Spare Device Mapping LSB0
            SPARE_DEVICE_LSB0_BYTE = 373,
            SPARE_DEVICE_LSB0_START = 0,
            SPARE_DEVICE_LSB0_LEN = 8,

            // Byte 374: Spare Device Mapping MSB0
            SPARE_DEVICE_MSB0_BYTE = 374,
            SPARE_DEVICE_MSB0_START = 0,
            SPARE_DEVICE_MSB0_LEN = 8,

            // Byte 375: Spare Device Mapping LSB1
            SPARE_DEVICE_LSB1_BYTE = 375,
            SPARE_DEVICE_LSB1_START = 4,
            SPARE_DEVICE_LSB1_LEN = 4,

            // Byte 377: Host Interface Speed to DDR Interface Speed Ratio
            HI_DDR_SPEED_RATIO_BYTE = 377,
            HI_DDR_SPEED_RATIO_START = 4,
            HI_DDR_SPEED_RATIO_LEN = 4,

            // Byte 378: External PHY Calibration Resistor Value
            EXT_PHY_CAL_RESISTOR_VALUE_BYTE = 378,
            PHY_A0_B0_CAL_RESISTOR_START = 5,
            PHY_A0_B0_CAL_RESISTOR_LEN = 3,
            PHY_A1_B1_CAL_RESISTOR_START = 2,
            PHY_A1_B1_CAL_RESISTOR_LEN = 3,

            // Byte 410: Doubletop Manufacturer Product ID
            DOUBLETOP_MANF_PROD_ID_BYTE = 410,
            DOUBLETOP_MANF_PROD_ID_START = 0,
            DOUBLETOP_MANF_PROD_ID_LEN = 8,

            // Byte 411: Doubletop Revision
            DOUBLETOP_REVISION_BYTE = 411,
            DOUBLETOP_REVISION_START = 0,
            DOUBLETOP_REVISION_LEN = 8,

            // Byte 412: Power Control 0 I2C Address
            POWER_CNTL_0_I2C_ADDRESS_BYTE = 412,
            POWER_CNTL_0_I2C_ADDRESS_START = 0,
            POWER_CNTL_0_I2C_ADDRESS_LEN = 8,

            // Byte 413:
            POWER_CNTL_1_I2C_ADDRESS_BYTE = 413,
            POWER_CNTL_1_I2C_ADDRESS_START = 0,
            POWER_CNTL_1_I2C_ADDRESS_LEN = 8,

            // Byte 414:
            POWER_CNTL_2_I2C_ADDRESS_BYTE = 414,
            POWER_CNTL_2_I2C_ADDRESS_START = 0,
            POWER_CNTL_2_I2C_ADDRESS_LEN = 8,

            // Byte 415:
            POWER_CNTL_3_I2C_ADDRESS_BYTE = 415,
            POWER_CNTL_3_I2C_ADDRESS_START = 0,
            POWER_CNTL_3_I2C_ADDRESS_LEN = 8,

            // Byte 416-441
            SERIAL_NUMBER_FIELD_START = 0,
            SERIAL_NUMBER_FIELD_LEN = 8,

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

        // Byte 193: Hashing Sequence
        static constexpr field_t HASH_SEQ_SERIAL_NUMBER{HASH_SEQ_BYTE, HASH_SEQ_SERIAL_NUMBER_START, HASH_SEQ_SERIAL_NUMBER_LEN};

        // Byte 194: SPD MANF ID CODE, First Byte
        static constexpr field_t SPD_MANF_ID_FIRST{SPD_MANF_ID_FIRST_BYTE, SPD_MANF_ID_FIRST_BYTE_START, SPD_MANF_ID_FIRST_BYTE_LEN};

        // Byte 195: SPD MANF ID CODE, Second Byte
        static constexpr field_t SPD_MANF_ID_SECOND{SPD_MANF_ID_SECOND_BYTE, SPD_MANF_ID_SECOND_BYTE_START, SPD_MANF_ID_SECOND_BYTE_LEN};

        // Byte 196: SPD Device Type
        static constexpr field_t SPD_DEVICE_TYPE{SPD_DEVICE_TYPE_BYTE, SPD_DEVICE_TYPE_START, SPD_DEVICE_TYPE_LEN};

        // Byte 197: SPD Device Revision Number
        static constexpr field_t SPD_DEVICE_REV_NUM{SPD_DEVICE_REV_NUM_BYTE, SPD_DEVICE_REV_NUM_START, SPD_DEVICE_REV_NUM_LEN};

        // Byte 198: PMIC0 Manf ID Code, 1st Byte
        static constexpr field_t PMIC0_MFG_CODE_FIRST{PMIC0_MFG_CODE_FIRST_BYTE, PMIC0_MFG_CODE_FIRST_BYTE_START, PMIC0_MFG_CODE_FIRST_BYTE_LEN};

        // Byte 199: PMIC0 Manfacture ID code 2nd byte
        static constexpr field_t PMIC0_MFG_CODE_SECOND{PMIC0_MFG_CODE_SECOND_BYTE, PMIC0_MFG_CODE_SECOND_BYTE_START, PMIC0_MFG_CODE_SECOND_BYTE_LEN};

        // Byte 200: PMIC0 Device Type
        static constexpr field_t PMIC0_DEVICE_TYPE{PMIC0_DEVICE_TYPE_BYTE, PMIC0_DEVICE_TYPE_START, PMIC0_DEVICE_TYPE_LEN};

        // Byte 201: PMIC0 Device Revision Number
        static constexpr field_t PMIC0_DEVICE_REV_NUM{PMIC0_DEVICE_REV_NUM_BYTE, PMIC0_DEVICE_REV_NUM_START, PMIC0_DEVICE_REV_NUM_LEN};

        // Byte 202: PMIC1 Manf ID Code, 1st Byte
        static constexpr field_t PMIC1_MFG_CODE_FIRST{PMIC1_MFG_CODE_FIRST_BYTE, PMIC1_MFG_CODE_FIRST_BYTE_START, PMIC1_MFG_CODE_FIRST_BYTE_LEN};

        // Byte 203: PMIC1 Manfacture ID code 2nd byte
        static constexpr field_t PMIC1_MFG_CODE_SECOND{PMIC1_MFG_CODE_SECOND_BYTE, PMIC1_MFG_CODE_SECOND_BYTE_START, PMIC1_MFG_CODE_SECOND_BYTE_LEN};

        // Byte 204: PMIC1 Device Type
        static constexpr field_t PMIC1_DEVICE_TYPE{PMIC1_DEVICE_TYPE_BYTE, PMIC1_DEVICE_TYPE_START, PMIC1_DEVICE_TYPE_LEN};

        // Byte 205: PMIC1 Device Revision Number
        static constexpr field_t PMIC1_DEVICE_REV_NUM{PMIC1_DEVICE_REV_NUM_BYTE, PMIC1_DEVICE_REV_NUM_START, PMIC1_DEVICE_REV_NUM_LEN};

        // Byte 206: PMIC2 Manf ID Code, 1st Byte
        static constexpr field_t PMIC2_MFG_CODE_FIRST{PMIC2_MFG_CODE_FIRST_BYTE, PMIC2_MFG_CODE_FIRST_START, PMIC2_MFG_CODE_FIRST_LEN};

        // Byte 207: PMIC2 Manfacture ID code 2nd byte
        static constexpr field_t PMIC2_MFG_CODE_SECOND{PMIC2_MFG_CODE_SECOND_BYTE, PMIC2_MFG_CODE_SECOND_START, PMIC2_MFG_CODE_SECOND_LEN};

        // Byte 208: PMIC2 Device Type
        static constexpr field_t PMIC2_DEVICE_TYPE{PMIC2_DEVICE_TYPE_BYTE, PMIC2_DEVICE_TYPE_START, PMIC2_DEVICE_TYPE_LEN};

        // Byte 209: PMIC2 Device Revision Number
        static constexpr field_t PMIC2_DEVICE_REV_NUM{PMIC2_DEVICE_REV_NUM_BYTE, PMIC2_DEVICE_REV_NUM_START, PMIC2_DEVICE_REV_NUM_LEN};

        // Byte 210: Thermal Sensor0 Manufacturing ID Code, First Byte
        static constexpr field_t THERMAL_SENSOR0_MANF_ID_CODE_FIRST{THERMAL_SENSOR0_MANF_ID_CODE_FIRST_BYTE, THERMAL_SENSOR0_MANF_ID_CODE_FIRST_START, THERMAL_SENSOR0_MANF_ID_CODE_FIRST_LEN};

        // Byte 211: Thermal Sensor0 Manufacturing ID Code, Second Byte
        static constexpr field_t THERMAL_SENSOR0_MANF_ID_CODE_SECOND{THERMAL_SENSOR0_MANF_ID_CODE_SECOND_BYTE, THERMAL_SENSOR0_MANF_ID_CODE_SECOND_START, THERMAL_SENSOR0_MANF_ID_CODE_SECOND_LEN};

        // Byte 212: Thermal Sensor0 Device Type
        static constexpr field_t THERMAL_SENSOR0_DEVICE_TYPE{ THERMAL_SENSOR0_DEVICE_TYPE_BYTE,  THERMAL_SENSOR0_DEVICE_TYPE_START,  THERMAL_SENSOR0_DEVICE_TYPE_LEN};

        // Byte 213: Thermal Sensor0 Revision Number
        static constexpr field_t THERMAL_SENSOR0_REV_NUM{THERMAL_SENSOR0_REV_NUM_BYTE, THERMAL_SENSOR0_REV_NUM_START, THERMAL_SENSOR0_REV_NUM_LEN};

        // Byte 214: DRAM Specification Level
        static constexpr field_t DRAM_SPEC_LEVEL{DRAM_SPEC_LEVEL_BYTE, DRAM_SPEC_LEVEL_START, DRAM_SPEC_LEVEL_LEN};

        // Byte 215: SPD Specification Level
        static constexpr field_t SPD_SPEC_LEVEL{SPD_SPEC_LEVEL_BYTE, SPD_SPEC_LEVEL_START, SPD_SPEC_LEVEL_LEN};

        // Byte 216: PMIC0 Spec Level
        static constexpr field_t PMIC0_SPEC_LEVEL{PMIC0_SPEC_LEVEL_BYTE, PMIC0_SPEC_LEVEL_START, PMIC0_SPEC_LEVEL_LEN};

        // Byte 217: PMIC1 Spec Level
        static constexpr field_t PMIC1_SPEC_LEVEL{PMIC1_SPEC_LEVEL_BYTE, PMIC1_SPEC_LEVEL_START, PMIC1_SPEC_LEVEL_LEN};

        // Byte 218: PMIC2 Spec Level
        static constexpr field_t PMIC2_SPEC_LEVEL{PMIC2_SPEC_LEVEL_BYTE, PMIC2_SPEC_LEVEL_START, PMIC2_SPEC_LEVEL_LEN};

        // Byte 219: Thermal Sensor0 Spec Level
        static constexpr field_t THERMAL_SENSOR0_SPEC{THERMAL_SENSOR0_SPEC_LEVEL_BYTE, THERMAL_SENSOR0_SPEC_LEVEL_START, THERMAL_SENSOR0_SPEC_LEVEL_LEN};

        // Byte 230: Module Height
        static constexpr field_t MODULE_BASE_HEIGHT{MODULE_HEIGHT_BYTE, MODULE_BASE_HEIGHT_START, MODULE_BASE_HEIGHT_LEN};
        static constexpr field_t MODULE_HEIGHT_MAX{MODULE_HEIGHT_BYTE, MODULE_HEIGHT_MAX_START, MODULE_HEIGHT_MAX_LEN};

        // Byte 231: Module Maximum Thickness
        static constexpr field_t MAX_THICKNESS_BACK{MODULE_THICKNESS_BYTE, MAX_THICKNESS_BACK_START, MAX_THICKNESS_BACK_LEN};
        static constexpr field_t MAX_THICKNESS_FRONT{MODULE_THICKNESS_BYTE, MAX_THICKNESS_FRONT_START, MAX_THICKNESS_FRONT_LEN};

        // Byte 232: Reference Raw Card used
        static constexpr field_t DESIGN_REV{REF_RAW_CARD_BYTE, DESIGN_REV_START, DESIGN_REV_LEN};
        static constexpr field_t DESIGN_REF_CARD{REF_RAW_CARD_BYTE, DESIGN_REF_CARD_START, DESIGN_REF_CARD_LEN};

        // Byte 233: DIMM attributes
        static constexpr field_t REGISTER_TYPE{DIMM_ATTR_BYTE, DIMM_ATTR_REGISTER_TYPE_START, DIMM_ATTR_REGISTER_TYPE_LEN};
        static constexpr field_t NUM_BUFFERS{DIMM_ATTR_BYTE, NUM_BUFFERS_START, NUM_BUFFERS_LEN};

        // Byte 234: DIMM Module Organization
        static constexpr field_t NUM_PACKAGE_RANKS_CHAN1{DIMM_ORG_BYTE_BYTE, NUM_PACKAGE_RANKS_CHAN1_START, NUM_PACKAGE_RANKS_CHAN1_LEN};
        static constexpr field_t NUM_PACKAGE_RANKS_CHAN0{DIMM_ORG_BYTE_BYTE, NUM_PACKAGE_RANKS_CHAN0_START, NUM_PACKAGE_RANKS_CHAN0_LEN};
        static constexpr field_t DATA_WIDTH{DIMM_ORG_BYTE_BYTE, SDRAM_DATA_WID_CHAN_START, SDRAM_DATA_WID_CHAN_LEN};

        // Byte 235: Memory Channel Bus Width
        static constexpr field_t ENABLED_PHY_CH{BUS_WIDTH_BYTE, ENABLED_PHY_CHANNELS_START, ENABLED_PHY_CHANNELS_LEN};
        static constexpr field_t BUS_WIDTH_CH_A{BUS_WIDTH_BYTE, BUS_WIDTH_CHANNEL_A_START, BUS_WIDTH_CHANNEL_A_LEN};
        static constexpr field_t BUS_WIDTH_CH_B{BUS_WIDTH_BYTE, BUS_WIDTH_CHANNEL_B_START, BUS_WIDTH_CHANNEL_B_LEN};

        // Byte 240: PMIC3 Manufacturing ID Code, 1st Byte
        static constexpr field_t PMIC3_MFG_CODE_FIRST{PMIC3_MFG_CODE_FIRST_BYTE, PMIC3_MFG_CODE_FIRST_START, PMIC3_MFG_CODE_FIRST_LEN};

        // Byte 241: PMIC3 Manfacture ID code 2nd byte
        static constexpr field_t PMIC3_MFG_CODE_SECOND{PMIC3_MFG_CODE_SECOND_BYTE, PMIC3_MFG_CODE_SECOND_START, PMIC3_MFG_CODE_SECOND_LEN};

        // Byte 242: PMIC3 Device Type
        static constexpr field_t PMIC3_DEVICE_TYPE{PMIC3_DEVICE_TYPE_BYTE, PMIC3_DEVICE_TYPE_START, PMIC3_DEVICE_TYPE_LEN};

        // Byte 243: PMIC3 Device Revision Number
        static constexpr field_t PMIC3_DEVICE_REV_NUM{PMIC3_DEVICE_REV_NUM_BYTE, PMIC3_DEVICE_REV_NUM_START, PMIC3_DEVICE_REV_NUM_LEN};

        // Byte 244: PMIC3 Spec Level
        static constexpr field_t PMIC3_SPEC_LEVEL{PMIC3_SPEC_LEVEL_BYTE, PMIC3_SPEC_LEVEL_START, PMIC3_SPEC_LEVEL_LEN};

        // Byte 245: Thermal Sensor1 Manufacturing ID Code, First Byte
        static constexpr field_t THERMAL_SENSOR1_MANF_ID_CODE_FIRST{THERMAL_SENSOR1_MANF_ID_CODE_FIRST_BYTE, THERMAL_SENSOR1_MANF_ID_CODE_FIRST_START, THERMAL_SENSOR1_MANF_ID_CODE_FIRST_LEN};

        // Byte 246: Thermal Sensor1 Manufacturing ID Code, Second Byte
        static constexpr field_t THERMAL_SENSOR1_MANF_ID_CODE_SECOND{THERMAL_SENSOR1_MANF_ID_CODE_SECOND_BYTE, THERMAL_SENSOR1_MANF_ID_CODE_SECOND_START, THERMAL_SENSOR1_MANF_ID_CODE_SECOND_LEN};

        // Byte 247: Thermal Sensor1 Device Type
        static constexpr field_t THERMAL_SENSOR1_DEVICE_TYPE{THERMAL_SENSOR1_DEVICE_TYPE_BYTE, THERMAL_SENSOR1_DEVICE_TYPE_START, THERMAL_SENSOR1_DEVICE_TYPE_LEN};

        // Byte 248: Thermal Sensor1 Revision Number
        static constexpr field_t THERMAL_SENSOR1_REV_NUM{THERMAL_SENSOR1_REV_NUM_BYTE, THERMAL_SENSOR1_REV_NUM_START, THERMAL_SENSOR1_REV_NUM_LEN};

        // Byte 249: Thermal Sensor1 Spec Level
        static constexpr field_t THERMAL_SENSOR1_SPEC_LEVEL{THERMAL_SENSOR1_SPEC_LEVEL_BYTE, THERMAL_SENSOR1_SPEC_LEVEL_START, THERMAL_SENSOR1_SPEC_LEVEL_LEN};

        // Byte 250: Thermal Sensor2 Manufacturing ID Code, First Byte
        static constexpr field_t THERMAL_SENSOR2_MANF_ID_CODE_FIRST{THERMAL_SENSOR2_MANF_ID_CODE_FIRST_BYTE, THERMAL_SENSOR2_MANF_ID_CODE_FIRST_START, THERMAL_SENSOR2_MANF_ID_CODE_FIRST_LEN};

        // Byte 251: Thermal Sensor2 Manufacturing ID Code, Second Byte
        static constexpr field_t THERMAL_SENSOR2_MANF_ID_CODE_SECOND{THERMAL_SENSOR2_MANF_ID_CODE_SECOND_BYTE, THERMAL_SENSOR2_MANF_ID_CODE_SECOND_START, THERMAL_SENSOR2_MANF_ID_CODE_SECOND_LEN};

        // Byte 252: Thermal Sensor2 Device Type
        static constexpr field_t THERMAL_SENSOR2_DEVICE_TYPE{THERMAL_SENSOR2_DEVICE_TYPE_BYTE, THERMAL_SENSOR2_DEVICE_TYPE_START, THERMAL_SENSOR2_DEVICE_TYPE_LEN};

        // Byte 253: Thermal Sensor2 Revision Number
        static constexpr field_t THERMAL_SENSOR2_REV_NUM{THERMAL_SENSOR2_REV_NUM_BYTE, THERMAL_SENSOR2_REV_NUM_START, THERMAL_SENSOR2_REV_NUM_LEN};

        // Byte 254: Thermal Sensor2 Spec Level
        static constexpr field_t THERMAL_SENSOR2_SPEC_LEVEL{THERMAL_SENSOR2_SPEC_LEVEL_BYTE, THERMAL_SENSOR2_SPEC_LEVEL_START, THERMAL_SENSOR2_SPEC_LEVEL_LEN};

        // Byte 255: Thermal Sensor3 Manufacturing ID Code, First Byte
        static constexpr field_t THERMAL_SENSOR3_MANF_ID_CODE_FIRST{THERMAL_SENSOR3_MANF_ID_CODE_FIRST_BYTE, THERMAL_SENSOR3_MANF_ID_CODE_FIRST_START, THERMAL_SENSOR3_MANF_ID_CODE_FIRST_LEN};

        // Byte 256: Thermal Sensor3 Manufacturing ID Code, Second Byte
        static constexpr field_t THERMAL_SENSOR3_MANF_ID_CODE_SECOND{THERMAL_SENSOR3_MANF_ID_CODE_SECOND_BYTE, THERMAL_SENSOR3_MANF_ID_CODE_SECOND_START, THERMAL_SENSOR3_MANF_ID_CODE_SECOND_LEN};

        // Byte 257: Thermal Sensor3 Device Type
        static constexpr field_t THERMAL_SENSOR3_DEVICE_TYPE{THERMAL_SENSOR3_DEVICE_TYPE_BYTE, THERMAL_SENSOR3_DEVICE_TYPE_START, THERMAL_SENSOR3_DEVICE_TYPE_LEN};

        // Byte 258: Thermal Sensor3 Revision Number
        static constexpr field_t THERMAL_SENSOR3_REV_NUM{THERMAL_SENSOR3_REV_NUM_BYTE, THERMAL_SENSOR3_REV_NUM_START, THERMAL_SENSOR3_REV_NUM_LEN};

        // Byte 259: Thermal Sensor3 Spec Level
        static constexpr field_t THERMAL_SENSOR3_SPEC_LEVEL{THERMAL_SENSOR3_SPEC_LEVEL_BYTE, THERMAL_SENSOR3_SPEC_LEVEL_START, THERMAL_SENSOR3_SPEC_LEVEL_LEN};

        // Byte 260: Thermal Sensor Locations
        static constexpr field_t THERMAL_SENSOR_3_LOCATION{THERMAL_SENSOR_LOCATIONS_BYTE, THERMAL_SENSOR_3_LOCATION_START, THERMAL_SENSOR_3_LOCATION_LEN};
        static constexpr field_t THERMAL_SENSOR_2_LOCATION{THERMAL_SENSOR_LOCATIONS_BYTE, THERMAL_SENSOR_2_LOCATION_START, THERMAL_SENSOR_2_LOCATION_LEN};
        static constexpr field_t THERMAL_SENSOR_1_LOCATION{THERMAL_SENSOR_LOCATIONS_BYTE, THERMAL_SENSOR_1_LOCATION_START, THERMAL_SENSOR_1_LOCATION_LEN};
        static constexpr field_t THERMAL_SENSOR_0_LOCATION{THERMAL_SENSOR_LOCATIONS_BYTE, THERMAL_SENSOR_0_LOCATION_START, THERMAL_SENSOR_0_LOCATION_LEN};

        // Byte 261: Thermal Sensor 0 Profile
        static constexpr field_t THERMAL_SENSOR_0_AVAIL{THERMAL_SENSOR_0_PROFILE_BYTE, THERMAL_SENSOR_0_AVAIL_START, THERMAL_SENSOR_0_AVAIL_LEN};
        static constexpr field_t THERMAL_SENSOR_0_TYPE{THERMAL_SENSOR_0_PROFILE_BYTE, THERMAL_SENSOR_0_TYPE_START, THERMAL_SENSOR_0_TYPE_LEN};
        static constexpr field_t THERMAL_SENSOR_0_USAGE{THERMAL_SENSOR_0_PROFILE_BYTE, THERMAL_SENSOR_0_USAGE_START, THERMAL_SENSOR_0_USAGE_LEN};

        // Byte 262: Thermal Sensor 1 Profile
        static constexpr field_t THERMAL_SENSOR_1_AVAIL{THERMAL_SENSOR_1_PROFILE_BYTE, THERMAL_SENSOR_1_AVAIL_START, THERMAL_SENSOR_1_AVAIL_LEN};
        static constexpr field_t THERMAL_SENSOR_1_TYPE{THERMAL_SENSOR_1_PROFILE_BYTE, THERMAL_SENSOR_1_TYPE_START, THERMAL_SENSOR_1_TYPE_LEN};
        static constexpr field_t THERMAL_SENSOR_1_USAGE{THERMAL_SENSOR_1_PROFILE_BYTE, THERMAL_SENSOR_1_USAGE_START, THERMAL_SENSOR_1_USAGE_LEN};

        // Byte 263: Thermal Sensor 2 Profile
        static constexpr field_t THERMAL_SENSOR_2_AVAIL{THERMAL_SENSOR_2_PROFILE_BYTE, THERMAL_SENSOR_2_AVAIL_START, THERMAL_SENSOR_2_AVAIL_LEN};
        static constexpr field_t THERMAL_SENSOR_2_TYPE{THERMAL_SENSOR_2_PROFILE_BYTE, THERMAL_SENSOR_2_TYPE_START, THERMAL_SENSOR_2_TYPE_LEN};
        static constexpr field_t THERMAL_SENSOR_2_USAGE{THERMAL_SENSOR_2_PROFILE_BYTE, THERMAL_SENSOR_2_USAGE_START, THERMAL_SENSOR_2_USAGE_LEN};

        // Byte 264: Thermal Sensor 3 Profile
        static constexpr field_t THERMAL_SENSOR_3_AVAIL{THERMAL_SENSOR_3_PROFILE_BYTE, THERMAL_SENSOR_3_AVAIL_START, THERMAL_SENSOR_3_AVAIL_LEN};
        static constexpr field_t THERMAL_SENSOR_3_TYPE{THERMAL_SENSOR_3_PROFILE_BYTE, THERMAL_SENSOR_3_TYPE_START, THERMAL_SENSOR_3_TYPE_LEN};
        static constexpr field_t THERMAL_SENSOR_3_USAGE{THERMAL_SENSOR_3_PROFILE_BYTE, THERMAL_SENSOR_3_USAGE_START, THERMAL_SENSOR_3_USAGE_LEN};

        // Byte 265: Thermal Sensor 0 I2C Address
        static constexpr field_t THERMAL_SENSOR_0_I2C_ADDRESS{THERMAL_SENSOR_0_I2C_ADDRESS_BYTE, THERMAL_SENSOR_0_I2C_ADDRESS_START, THERMAL_SENSOR_0_I2C_ADDRESS_LEN};

        // Byte 266: Thermal Sensor 1 I2C Address
        static constexpr field_t THERMAL_SENSOR_1_I2C_ADDRESS{THERMAL_SENSOR_1_I2C_ADDRESS_BYTE, THERMAL_SENSOR_1_I2C_ADDRESS_START, THERMAL_SENSOR_1_I2C_ADDRESS_LEN};

        // Byte 267: Thermal Sensor 2 I2C Address
        static constexpr field_t THERMAL_SENSOR_2_I2C_ADDRESS{THERMAL_SENSOR_2_I2C_ADDRESS_BYTE, THERMAL_SENSOR_2_I2C_ADDRESS_START, THERMAL_SENSOR_2_I2C_ADDRESS_LEN};

        // Byte 268: Thermal Sensor 3 I2C Address
        static constexpr field_t THERMAL_SENSOR_3_I2C_ADDRESS{THERMAL_SENSOR_3_I2C_ADDRESS_BYTE, THERMAL_SENSOR_3_I2C_ADDRESS_START, THERMAL_SENSOR_3_I2C_ADDRESS_LEN};

        // Byte 269: Differential Buffer Thermal Sensor Profile
        static constexpr field_t THERMAL_SENSOR_DIFF_AVAIL{THERMAL_SENSOR_DIFF_PROFILE_BYTE, THERMAL_SENSOR_DIFF_AVAIL_START, THERMAL_SENSOR_DIFF_AVAIL_LEN};
        static constexpr field_t THERMAL_SENSOR_DIFF_TYPE{THERMAL_SENSOR_DIFF_PROFILE_BYTE, THERMAL_SENSOR_DIFF_TYPE_START, THERMAL_SENSOR_DIFF_TYPE_LEN};
        static constexpr field_t THERMAL_SENSOR_DIFF_USAGE{THERMAL_SENSOR_DIFF_PROFILE_BYTE, THERMAL_SENSOR_DIFF_USAGE_START, THERMAL_SENSOR_DIFF_USAGE_LEN};

        // Byte 270: Differential Buffer Thermal Sensor I2C Address
        static constexpr field_t THERMAL_SENSOR_DIFF_I2C_ADDRESS{THERMAL_SENSOR_DIFF_I2C_ADDRESS_BYTE, THERMAL_SENSOR_DIFF_I2C_ADDRESS_START, THERMAL_SENSOR_DIFF_I2C_ADDRESS_LEN};

        // Byte 271: Registered Clock Drivers (RCD)
        static constexpr field_t MODULE_RCD_MEDIA_CONTROLLER_TYPE{MODULE_RCD_BYTE, MODULE_RCD_MEDIA_CONTROLLER_TYPE_START, MODULE_RCD_MEDIA_CONTROLLER_TYPE_LEN};
        static constexpr field_t MODULE_RCD_JEDEC_COMPLIANT{MODULE_RCD_BYTE, MODULE_RCD_JEDEC_COMPLIANT_START, MODULE_RCD_JEDEC_COMPLIANT_LEN};
        static constexpr field_t MODULE_RCD{MODULE_RCD_BYTE, MODULE_RCD_START, MODULE_RCD_LEN};

        // Byte 272-273: RCD MFG ID Code
        static constexpr field_t RCD_MFG_ID_LSB{RCD_MFG_ID_LSB_BYTE, RCD_MFG_ID_LSB_START, RCD_MFG_ID_LSB_LEN};
        static constexpr field_t RCD_MFG_ID_MSB{RCD_MFG_ID_MSB_BYTE, RCD_MFG_ID_MSB_START, RCD_MFG_ID_MSB_LEN};

        // Byte 274: RCD Revision Nunber
        static constexpr field_t RCD_REV_NUM{RCD_REV_NUM_BYTE, RCD_REV_NUM_START, RCD_REV_NUM_LEN};

        // Byte 275: RCD0 I2C Address
        static constexpr field_t RCD0_I2C_ADDR{RCD0_I2C_ADDR_BYTE, RCD0_I2C_ADDR_START, RCD0_I2C_ADDR_LEN};

        // Byte 276: RCD1 I2C Address
        static constexpr field_t RCD1_I2C_ADDR{RCD1_I2C_ADDR_BYTE, RCD1_I2C_ADDR_START, RCD1_I2C_ADDR_LEN};

        // Byte 277: SPD Content Revision
        static constexpr field_t SPD_CONTENT_REVISION{SPD_CONTENT_REVISION_BYTE, SPD_CONTENT_REVISION_START, SPD_CONTENT_REVISION_LEN};

        // Byte 278: SPD REDUNDANCY
        static constexpr field_t SPD_REDUNDANCY{SPD_REDUNDANCY_BYTE, SPD_REDUNDANCY_START, SPD_REDUNDANCY_LEN};

        // Byte 279: SPD I2C Address
        static constexpr field_t SPD_REDUNDANCY_I2C_ADDR{SPD_REDUNDANCY_I2C_ADDR_BYTE, SPD_REDUNDANCY_I2C_ADDR_START, SPD_REDUNDANCY_I2C_ADDR_LEN};

        // Byte 280: ORing MOSFET Vendors
        static constexpr field_t ORING_MOSFET_SMALL{ORING_MOSFET_BYTE, ORING_MOSFET_SMALL_START, ORING_MOSFET_SMALL_LEN};
        static constexpr field_t ORING_MOSFET_BIG{ORING_MOSFET_BYTE, ORING_MOSFET_BIG_START, ORING_MOSFET_BIG_LEN};

        // Byte 281: DMB I2C Address
        static constexpr field_t DMB_I2C_ADDRESS{DMB_I2C_ADDRESS_BYTE, DMB_I2C_ADDRESS_START, DMB_I2C_ADDRESS_LEN};

        // Byte 282: DMB Manfacture ID code 1st byte
        static constexpr field_t DMB_MFG_CODE1_CONT_CODE{DMB_MFG_CODE1_BYTE, CONTINUATION_CODE_START, CONTINUATION_CODE_LEN};

        // Byte 283: DMB Manfacture ID code 2nd byte
        static constexpr field_t DMB_MFG_CODE2_LAST_NON_ZERO{DMB_MFG_CODE2_BYTE, LAST_NON_ZERO_START, LAST_NON_ZERO_LEN};

        // Byte 284: DMB Revision Number
        static constexpr field_t DMB_REV{DMB_REV_BYTE, DMB_REV_START, DMB_REV_LEN};

        // Byte 286: ADC I2C Address
        static constexpr field_t ADC_I2C_ADDRESS{ADC_I2C_ADDRESS_BYTE, ADC_I2C_ADDRESS_START, ADC_I2C_ADDRESS_LEN};

        // Byte 287: PMIC Status Mask 0
        static constexpr field_t PMIC_STATUS_MASK0{PMIC_STATUS_MASK0_BYTE, PMIC_STATUS_MASK0_START, PMIC_STATUS_MASK0_LEN};

        // Byte 288: PMIC Status Mask 1
        static constexpr field_t PMIC_STATUS_MASK1{PMIC_STATUS_MASK1_BYTE, PMIC_STATUS_MASK1_START, PMIC_STATUS_MASK1_LEN};

        // Byte 289: PMIC PF Threshold 1
        static constexpr field_t PMIC_PF_THRESHOLD{PMIC_PF_THRESHOLD_BYTE, PMIC_PF_THRESHOLD_START, PMIC_PF_THRESHOLD_LEN};

        // Byte 290: PMIC0 IIC Address
        static constexpr field_t PMIC0_IIC_ADDRESS{PMIC0_IIC_ADDRESS_BYTE, PMIC0_IIC_ADDRESS_START, PMIC0_IIC_ADDRESS_LEN};

        // Byte 291: PMIC1 IIC Address
        static constexpr field_t PMIC1_IIC_ADDRESS{PMIC1_IIC_ADDRESS_BYTE, PMIC1_IIC_ADDRESS_START, PMIC1_IIC_ADDRESS_LEN};

        // Byte 292: PMIC2 IIC Address
        static constexpr field_t PMIC2_IIC_ADDRESS{PMIC2_IIC_ADDRESS_BYTE, PMIC2_IIC_ADDRESS_START, PMIC2_IIC_ADDRESS_LEN};

        // Byte 293: PMIC3 IIC Address
        static constexpr field_t PMIC3_IIC_ADDRESS{PMIC3_IIC_ADDRESS_BYTE, PMIC3_IIC_ADDRESS_START, PMIC3_IIC_ADDRESS_LEN};

        // Byte 294: PMIC0 Sequence
        static constexpr field_t PMIC0_SUPPLY_VOLTAGE{PMIC0_SEQUENCE_BYTE, PMIC0_SUPPLY_VOLTAGE_START, PMIC0_SUPPLY_VOLTAGE_LEN};
        static constexpr field_t PMIC0_SEQUENCE{PMIC0_SEQUENCE_BYTE, PMIC0_SEQUENCE_START, PMIC0_SEQUENCE_LEN};

        // Byte 295: PMIC1 Sequence
        static constexpr field_t PMIC1_SUPPLY_VOLTAGE{PMIC1_SEQUENCE_BYTE, PMIC1_SUPPLY_VOLTAGE_START, PMIC1_SUPPLY_VOLTAGE_LEN};
        static constexpr field_t PMIC1_SEQUENCE{PMIC1_SEQUENCE_BYTE, PMIC1_SEQUENCE_START, PMIC1_SEQUENCE_LEN};

        // Byte 296: PMIC2 Sequence
        static constexpr field_t PMIC2_SUPPLY_VOLTAGE{PMIC2_SEQUENCE_BYTE, PMIC2_SUPPLY_VOLTAGE_START, PMIC2_SUPPLY_VOLTAGE_LEN};
        static constexpr field_t PMIC2_SEQUENCE{PMIC2_SEQUENCE_BYTE, PMIC2_SEQUENCE_START, PMIC2_SEQUENCE_LEN};

        // Byte 297: PMIC3 Sequence
        static constexpr field_t PMIC3_SUPPLY_VOLTAGE{PMIC3_SEQUENCE_BYTE, PMIC3_SUPPLY_VOLTAGE_START, PMIC3_SUPPLY_VOLTAGE_LEN};
        static constexpr field_t PMIC3_SEQUENCE{PMIC3_SEQUENCE_BYTE, PMIC3_SEQUENCE_START, PMIC3_SEQUENCE_LEN};

        // Byte 298: PMIC0 Voltage Range Offsets
        static constexpr field_t PMIC0_VOLT_RANGE_OFFSET_SWA{PMIC0_VOLT_RANGE_OFFSET_BYTE, PMIC0_VOLT_RANGE_OFFSET_SWA_START, PMIC0_VOLT_RANGE_OFFSET_SWA_LEN};
        static constexpr field_t PMIC0_VOLT_RANGE_OFFSET_SWB{PMIC0_VOLT_RANGE_OFFSET_BYTE, PMIC0_VOLT_RANGE_OFFSET_SWB_START, PMIC0_VOLT_RANGE_OFFSET_SWB_LEN};
        static constexpr field_t PMIC0_VOLT_RANGE_OFFSET_SWC{PMIC0_VOLT_RANGE_OFFSET_BYTE, PMIC0_VOLT_RANGE_OFFSET_SWC_START, PMIC0_VOLT_RANGE_OFFSET_SWC_LEN};
        static constexpr field_t PMIC0_VOLT_RANGE_OFFSET_SWD{PMIC0_VOLT_RANGE_OFFSET_BYTE, PMIC0_VOLT_RANGE_OFFSET_SWD_START, PMIC0_VOLT_RANGE_OFFSET_SWD_LEN};

        // Byte 299: PMIC1 Voltage Range Offsets
        static constexpr field_t PMIC1_VOLT_RANGE_OFFSET_SWA{PMIC1_VOLT_RANGE_OFFSET_BYTE, PMIC1_VOLT_RANGE_OFFSET_SWA_START, PMIC1_VOLT_RANGE_OFFSET_SWA_LEN};
        static constexpr field_t PMIC1_VOLT_RANGE_OFFSET_SWB{PMIC1_VOLT_RANGE_OFFSET_BYTE, PMIC1_VOLT_RANGE_OFFSET_SWB_START, PMIC1_VOLT_RANGE_OFFSET_SWB_LEN};
        static constexpr field_t PMIC1_VOLT_RANGE_OFFSET_SWC{PMIC1_VOLT_RANGE_OFFSET_BYTE, PMIC1_VOLT_RANGE_OFFSET_SWC_START, PMIC1_VOLT_RANGE_OFFSET_SWC_LEN};
        static constexpr field_t PMIC1_VOLT_RANGE_OFFSET_SWD{PMIC1_VOLT_RANGE_OFFSET_BYTE, PMIC1_VOLT_RANGE_OFFSET_SWD_START, PMIC1_VOLT_RANGE_OFFSET_SWD_LEN};

        // Byte 300: PMIC2 Voltage Range Offsets
        static constexpr field_t PMIC2_VOLT_RANGE_OFFSET_SWA{PMIC2_VOLT_RANGE_OFFSET_BYTE, PMIC2_VOLT_RANGE_OFFSET_SWA_START, PMIC2_VOLT_RANGE_OFFSET_SWA_LEN};
        static constexpr field_t PMIC2_VOLT_RANGE_OFFSET_SWB{PMIC2_VOLT_RANGE_OFFSET_BYTE, PMIC2_VOLT_RANGE_OFFSET_SWB_START, PMIC2_VOLT_RANGE_OFFSET_SWB_LEN};
        static constexpr field_t PMIC2_VOLT_RANGE_OFFSET_SWC{PMIC2_VOLT_RANGE_OFFSET_BYTE, PMIC2_VOLT_RANGE_OFFSET_SWC_START, PMIC2_VOLT_RANGE_OFFSET_SWC_LEN};
        static constexpr field_t PMIC2_VOLT_RANGE_OFFSET_SWD{PMIC2_VOLT_RANGE_OFFSET_BYTE, PMIC2_VOLT_RANGE_OFFSET_SWD_START, PMIC2_VOLT_RANGE_OFFSET_SWD_LEN};

        // Byte 301: PMIC3 Voltage Range Offsets
        static constexpr field_t PMIC3_VOLT_RANGE_OFFSET_SWA{PMIC3_VOLT_RANGE_OFFSET_BYTE, PMIC3_VOLT_RANGE_OFFSET_SWA_START, PMIC3_VOLT_RANGE_OFFSET_SWA_LEN};
        static constexpr field_t PMIC3_VOLT_RANGE_OFFSET_SWB{PMIC3_VOLT_RANGE_OFFSET_BYTE, PMIC3_VOLT_RANGE_OFFSET_SWB_START, PMIC3_VOLT_RANGE_OFFSET_SWB_LEN};
        static constexpr field_t PMIC3_VOLT_RANGE_OFFSET_SWC{PMIC3_VOLT_RANGE_OFFSET_BYTE, PMIC3_VOLT_RANGE_OFFSET_SWC_START, PMIC3_VOLT_RANGE_OFFSET_SWC_LEN};
        static constexpr field_t PMIC3_VOLT_RANGE_OFFSET_SWD{PMIC3_VOLT_RANGE_OFFSET_BYTE, PMIC3_VOLT_RANGE_OFFSET_SWD_START, PMIC3_VOLT_RANGE_OFFSET_SWD_LEN};

        // Byte 302: PMIC0 Voltage Domains
        static constexpr field_t PMIC0_VOLT_DOMAINS_SWA{PMIC0_VOLT_DOMAINS_BYTE, PMIC0_VOLT_DOMAINS_SWA_START, PMIC0_VOLT_DOMAINS_SWA_LEN};
        static constexpr field_t PMIC0_VOLT_DOMAINS_SWB{PMIC0_VOLT_DOMAINS_BYTE, PMIC0_VOLT_DOMAINS_SWB_START, PMIC0_VOLT_DOMAINS_SWB_LEN};
        static constexpr field_t PMIC0_VOLT_DOMAINS_SWC{PMIC0_VOLT_DOMAINS_BYTE, PMIC0_VOLT_DOMAINS_SWC_START, PMIC0_VOLT_DOMAINS_SWC_LEN};
        static constexpr field_t PMIC0_VOLT_DOMAINS_SWD{PMIC0_VOLT_DOMAINS_BYTE, PMIC0_VOLT_DOMAINS_SWD_START, PMIC0_VOLT_DOMAINS_SWD_LEN};

        // Byte 303: PMIC1 Voltage Domains
        static constexpr field_t PMIC1_VOLT_DOMAINS_SWA{PMIC1_VOLT_DOMAINS_BYTE, PMIC1_VOLT_DOMAINS_SWA_START, PMIC1_VOLT_DOMAINS_SWA_LEN};
        static constexpr field_t PMIC1_VOLT_DOMAINS_SWB{PMIC1_VOLT_DOMAINS_BYTE, PMIC1_VOLT_DOMAINS_SWB_START, PMIC1_VOLT_DOMAINS_SWB_LEN};
        static constexpr field_t PMIC1_VOLT_DOMAINS_SWC{PMIC1_VOLT_DOMAINS_BYTE, PMIC1_VOLT_DOMAINS_SWC_START, PMIC1_VOLT_DOMAINS_SWC_LEN};
        static constexpr field_t PMIC1_VOLT_DOMAINS_SWD{PMIC1_VOLT_DOMAINS_BYTE, PMIC1_VOLT_DOMAINS_SWD_START, PMIC1_VOLT_DOMAINS_SWD_LEN};

        // Byte 304: PMIC2 Voltage Domains
        static constexpr field_t PMIC2_VOLT_DOMAINS_SWA{PMIC2_VOLT_DOMAINS_BYTE, PMIC2_VOLT_DOMAINS_SWA_START, PMIC2_VOLT_DOMAINS_SWA_LEN};
        static constexpr field_t PMIC2_VOLT_DOMAINS_SWB{PMIC2_VOLT_DOMAINS_BYTE, PMIC2_VOLT_DOMAINS_SWB_START, PMIC2_VOLT_DOMAINS_SWB_LEN};
        static constexpr field_t PMIC2_VOLT_DOMAINS_SWC{PMIC2_VOLT_DOMAINS_BYTE, PMIC2_VOLT_DOMAINS_SWC_START, PMIC2_VOLT_DOMAINS_SWC_LEN};
        static constexpr field_t PMIC2_VOLT_DOMAINS_SWD{PMIC2_VOLT_DOMAINS_BYTE, PMIC2_VOLT_DOMAINS_SWD_START, PMIC2_VOLT_DOMAINS_SWD_LEN};

        // Byte 305: PMIC3 Voltage Domains
        static constexpr field_t PMIC3_VOLT_DOMAINS_SWA{PMIC3_VOLT_DOMAINS_BYTE, PMIC3_VOLT_DOMAINS_SWA_START, PMIC3_VOLT_DOMAINS_SWA_LEN};
        static constexpr field_t PMIC3_VOLT_DOMAINS_SWB{PMIC3_VOLT_DOMAINS_BYTE, PMIC3_VOLT_DOMAINS_SWB_START, PMIC3_VOLT_DOMAINS_SWB_LEN};
        static constexpr field_t PMIC3_VOLT_DOMAINS_SWC{PMIC3_VOLT_DOMAINS_BYTE, PMIC3_VOLT_DOMAINS_SWC_START, PMIC3_VOLT_DOMAINS_SWC_LEN};
        static constexpr field_t PMIC3_VOLT_DOMAINS_SWD{PMIC3_VOLT_DOMAINS_BYTE, PMIC3_VOLT_DOMAINS_SWD_START, PMIC3_VOLT_DOMAINS_SWD_LEN};

        // Byte 306: PMIC0 SWA Voltage Setting
        static constexpr field_t PMIC0_SWA_VOLT_SET{PMIC0_SWA_VOLT_SET_BYTE, PMIC0_SWA_VOLT_SET_START, PMIC0_SWA_VOLT_SET_LEN};
        static constexpr field_t PMIC0_SWA_RANGE_SELECT{PMIC0_SWA_VOLT_SET_BYTE, PMIC0_SWA_RANGE_SELECT_START, PMIC0_SWA_RANGE_SELECT_LEN};

        // Byte 307: PMIC0 SWA Voltage Offset
        static constexpr field_t PMIC0_SWA_VOLT_OFF{PMIC0_SWA_VOLT_OFF_BYTE, PMIC0_SWA_VOLT_OFF_START, PMIC0_SWA_VOLT_OFF_LEN};
        static constexpr field_t PMIC0_SWA_OFF_DIRECTION{PMIC0_SWA_VOLT_OFF_BYTE, PMIC0_SWA_OFF_DIRECTION_START, PMIC0_SWA_OFF_DIRECTION_LEN};

        // Byte 308: PMIC0 SWA Delay Sequence Order
        static constexpr field_t PMIC0_SWA_DELAY{PMIC0_SWA_DELAY_BYTE, PMIC0_SWA_DELAY_START, PMIC0_SWA_DELAY_LEN};
        static constexpr field_t PMIC0_SWA_ORDER{PMIC0_SWA_DELAY_BYTE, PMIC0_SWA_ORDER_START, PMIC0_SWA_ORDER_LEN};

        // Byte 309: PMIC0 SWB Voltage Setting
        static constexpr field_t PMIC0_SWB_VOLT_SET{PMIC0_SWB_VOLT_SET_BYTE, PMIC0_SWB_VOLT_SET_START, PMIC0_SWB_VOLT_SET_LEN};
        static constexpr field_t PMIC0_SWB_RANGE_SELECT{PMIC0_SWB_VOLT_SET_BYTE, PMIC0_SWB_RANGE_SELECT_START, PMIC0_SWB_RANGE_SELECT_LEN};

        // Byte 310: PMIC0 SWB Voltage Offset
        static constexpr field_t PMIC0_SWB_VOLT_OFF{PMIC0_SWB_VOLT_OFF_BYTE, PMIC0_SWB_VOLT_OFF_START, PMIC0_SWB_VOLT_OFF_LEN};
        static constexpr field_t PMIC0_SWB_OFF_DIRECTION{PMIC0_SWB_VOLT_OFF_BYTE, PMIC0_SWB_OFF_DIRECTION_START, PMIC0_SWB_OFF_DIRECTION_LEN};

        // Byte 311: PMIC0 SWB Delay Sequence Order
        static constexpr field_t PMIC0_SWB_DELAY{PMIC0_SWB_DELAY_BYTE, PMIC0_SWB_DELAY_START, PMIC0_SWB_DELAY_LEN};
        static constexpr field_t PMIC0_SWB_ORDER{PMIC0_SWB_DELAY_BYTE, PMIC0_SWB_ORDER_START, PMIC0_SWB_ORDER_LEN};

        // Byte 312: PMIC0 SWC Voltage Setting
        static constexpr field_t PMIC0_SWC_VOLT_SET{PMIC0_SWC_VOLT_SET_BYTE, PMIC0_SWC_VOLT_SET_START, PMIC0_SWC_VOLT_SET_LEN};
        static constexpr field_t PMIC0_SWC_RANGE_SELECT{PMIC0_SWC_VOLT_SET_BYTE, PMIC0_SWC_RANGE_SELECT_START, PMIC0_SWC_RANGE_SELECT_LEN};

        // Byte 313: PMIC0 SWC Voltage Offset
        static constexpr field_t PMIC0_SWC_VOLT_OFF{PMIC0_SWC_VOLT_OFF_BYTE, PMIC0_SWC_VOLT_OFF_START, PMIC0_SWC_VOLT_OFF_LEN};
        static constexpr field_t PMIC0_SWC_OFF_DIRECTION{PMIC0_SWC_VOLT_OFF_BYTE, PMIC0_SWC_OFF_DIRECTION_START, PMIC0_SWC_OFF_DIRECTION_LEN};

        // Byte 314: PMIC0 SWC Delay Sequence Order
        static constexpr field_t PMIC0_SWC_DELAY{PMIC0_SWC_DELAY_BYTE, PMIC0_SWC_DELAY_START, PMIC0_SWC_DELAY_LEN};
        static constexpr field_t PMIC0_SWC_ORDER{PMIC0_SWC_DELAY_BYTE, PMIC0_SWC_ORDER_START, PMIC0_SWC_ORDER_LEN};

        // Byte 315: PMIC0 SWD Voltage Setting
        static constexpr field_t PMIC0_SWD_VOLT_SET{PMIC0_SWD_VOLT_SET_BYTE, PMIC0_SWD_VOLT_SET_START, PMIC0_SWD_VOLT_SET_LEN};
        static constexpr field_t PMIC0_SWD_RANGE_SELECT{PMIC0_SWD_VOLT_SET_BYTE, PMIC0_SWD_RANGE_SELECT_START, PMIC0_SWD_RANGE_SELECT_LEN};

        // Byte 316: PMIC0 SWD Voltage Offset
        static constexpr field_t PMIC0_SWD_VOLT_OFF{PMIC0_SWD_VOLT_OFF_BYTE, PMIC0_SWD_VOLT_OFF_START, PMIC0_SWD_VOLT_OFF_LEN};
        static constexpr field_t PMIC0_SWD_OFF_DIRECTION{PMIC0_SWD_VOLT_OFF_BYTE, PMIC0_SWD_OFF_DIRECTION_START, PMIC0_SWD_OFF_DIRECTION_LEN};

        // Byte 317: PMIC0 SWD Delay Sequence Order
        static constexpr field_t PMIC0_SWD_DELAY{PMIC0_SWD_DELAY_BYTE, PMIC0_SWD_DELAY_START, PMIC0_SWD_DELAY_LEN};
        static constexpr field_t PMIC0_SWD_ORDER{PMIC0_SWD_DELAY_BYTE, PMIC0_SWD_ORDER_START, PMIC0_SWD_ORDER_LEN};

        // Byte 318: PMIC0 Phase Combination and redundancy
        static constexpr field_t PMIC0_REDUNDANCY{PMIC0_PHASE_COMBIN_BYTE, PMIC0_REDUNDANCY_START, PMIC0_REDUNDANCY_LEN};
        static constexpr field_t PMIC0_PHASE_COMBIN{PMIC0_PHASE_COMBIN_BYTE, PMIC0_PHASE_COMBIN_START, PMIC0_PHASE_COMBIN_LEN};

        // Byte 319: PMIC1 SWA Voltage Setting
        static constexpr field_t PMIC1_SWA_VOLT_SET{PMIC1_SWA_VOLT_SET_BYTE, PMIC1_SWA_VOLT_SET_START, PMIC1_SWA_VOLT_SET_LEN};
        static constexpr field_t PMIC1_SWA_RANGE_SELECT{PMIC1_SWA_VOLT_SET_BYTE, PMIC1_SWA_RANGE_SELECT_START, PMIC1_SWA_RANGE_SELECT_LEN};

        // Byte 320: PMIC1 SWA Voltage Offset
        static constexpr field_t PMIC1_SWA_VOLT_OFF{PMIC1_SWA_VOLT_OFF_BYTE, PMIC1_SWA_VOLT_OFF_START, PMIC1_SWA_VOLT_OFF_LEN};
        static constexpr field_t PMIC1_SWA_OFF_DIRECTION{PMIC1_SWA_VOLT_OFF_BYTE, PMIC1_SWA_OFF_DIRECTION_START, PMIC1_SWA_OFF_DIRECTION_LEN};

        // Byte 321: PMIC1 SWA Delay Sequence Order
        static constexpr field_t PMIC1_SWA_DELAY{PMIC1_SWA_DELAY_BYTE, PMIC1_SWA_DELAY_START, PMIC1_SWA_DELAY_LEN};
        static constexpr field_t PMIC1_SWA_ORDER{PMIC1_SWA_DELAY_BYTE, PMIC1_SWA_ORDER_START, PMIC1_SWA_ORDER_LEN};

        // Byte 322: PMIC1 SWB Voltage Setting
        static constexpr field_t PMIC1_SWB_VOLT_SET{PMIC1_SWB_VOLT_SET_BYTE, PMIC1_SWB_VOLT_SET_START, PMIC1_SWB_VOLT_SET_LEN};
        static constexpr field_t PMIC1_SWB_RANGE_SELECT{PMIC1_SWB_VOLT_SET_BYTE, PMIC1_SWB_RANGE_SELECT_START, PMIC1_SWB_RANGE_SELECT_LEN};

        // Byte 323: PMIC1 SWB Voltage Offset
        static constexpr field_t PMIC1_SWB_VOLT_OFF{PMIC1_SWB_VOLT_OFF_BYTE, PMIC1_SWB_VOLT_OFF_START, PMIC1_SWB_VOLT_OFF_LEN};
        static constexpr field_t PMIC1_SWB_OFF_DIRECTION{PMIC1_SWB_VOLT_OFF_BYTE, PMIC1_SWB_OFF_DIRECTION_START, PMIC1_SWB_OFF_DIRECTION_LEN};

        // Byte 324: PMIC1 SWB Delay Sequence Order
        static constexpr field_t PMIC1_SWB_DELAY{PMIC1_SWB_DELAY_BYTE, PMIC1_SWB_DELAY_START, PMIC1_SWB_DELAY_LEN};
        static constexpr field_t PMIC1_SWB_ORDER{PMIC1_SWB_DELAY_BYTE, PMIC1_SWB_ORDER_START, PMIC1_SWB_ORDER_LEN};

        // Byte 325: PMIC1 SWC Voltage Setting
        static constexpr field_t PMIC1_SWC_VOLT_SET{PMIC1_SWC_VOLT_SET_BYTE, PMIC1_SWC_VOLT_SET_START, PMIC1_SWC_VOLT_SET_LEN};
        static constexpr field_t PMIC1_SWC_RANGE_SELECT{PMIC1_SWC_VOLT_SET_BYTE, PMIC1_SWC_RANGE_SELECT_START, PMIC1_SWC_RANGE_SELECT_LEN};

        // Byte 326: PMIC1 SWC Voltage Offset
        static constexpr field_t PMIC1_SWC_VOLT_OFF{PMIC1_SWC_VOLT_OFF_BYTE, PMIC1_SWC_VOLT_OFF_START, PMIC1_SWC_VOLT_OFF_LEN};
        static constexpr field_t PMIC1_SWC_OFF_DIRECTION{PMIC1_SWC_VOLT_OFF_BYTE, PMIC1_SWC_OFF_DIRECTION_START, PMIC1_SWC_OFF_DIRECTION_LEN};

        // Byte 327: PMIC1 SWC Delay Sequence Order
        static constexpr field_t PMIC1_SWC_DELAY{PMIC1_SWC_DELAY_BYTE, PMIC1_SWC_DELAY_START, PMIC1_SWC_DELAY_LEN};
        static constexpr field_t PMIC1_SWC_ORDER{PMIC1_SWC_DELAY_BYTE, PMIC1_SWC_ORDER_START, PMIC1_SWC_ORDER_LEN};

        // Byte 328: PMIC1 SWD Voltage Setting
        static constexpr field_t PMIC1_SWD_VOLT_SET{PMIC1_SWD_VOLT_SET_BYTE, PMIC1_SWD_VOLT_SET_START, PMIC1_SWD_VOLT_SET_LEN};
        static constexpr field_t PMIC1_SWD_RANGE_SELECT{PMIC1_SWD_VOLT_SET_BYTE, PMIC1_SWD_RANGE_SELECT_START, PMIC1_SWD_RANGE_SELECT_LEN};

        // Byte 329: PMIC1 SWD Voltage Offset
        static constexpr field_t PMIC1_SWD_VOLT_OFF{PMIC1_SWD_VOLT_OFF_BYTE, PMIC1_SWD_VOLT_OFF_START, PMIC1_SWD_VOLT_OFF_LEN};
        static constexpr field_t PMIC1_SWD_OFF_DIRECTION{PMIC1_SWD_VOLT_OFF_BYTE, PMIC1_SWD_OFF_DIRECTION_START, PMIC1_SWD_OFF_DIRECTION_LEN};

        // Byte 330: PMIC1 SWD Delay Sequence Order
        static constexpr field_t PMIC1_SWD_DELAY{PMIC1_SWD_DELAY_BYTE, PMIC1_SWD_DELAY_START, PMIC1_SWD_DELAY_LEN};
        static constexpr field_t PMIC1_SWD_ORDER{PMIC1_SWD_DELAY_BYTE, PMIC1_SWD_ORDER_START, PMIC1_SWD_ORDER_LEN};

        // Byte 331: PMIC1 Phase Combination and redundancy
        static constexpr field_t PMIC1_REDUNDANCY{PMIC1_PHASE_COMBIN_BYTE, PMIC1_REDUNDANCY_START, PMIC1_REDUNDANCY_LEN};
        static constexpr field_t PMIC1_PHASE_COMBIN{PMIC1_PHASE_COMBIN_BYTE, PMIC1_PHASE_COMBIN_START, PMIC1_PHASE_COMBIN_LEN};

        // Byte 332: PMIC2 SWA Voltage Setting
        static constexpr field_t PMIC2_SWA_VOLT_SET{PMIC2_SWA_VOLT_SET_BYTE, PMIC2_SWA_VOLT_SET_START, PMIC2_SWA_VOLT_SET_LEN};
        static constexpr field_t PMIC2_SWA_RANGE_SELECT{PMIC2_SWA_VOLT_SET_BYTE, PMIC2_SWA_RANGE_SELECT_START, PMIC2_SWA_RANGE_SELECT_LEN};

        // Byte 333: PMIC2 SWA Voltage Offset
        static constexpr field_t PMIC2_SWA_VOLT_OFF{PMIC2_SWA_VOLT_OFF_BYTE, PMIC2_SWA_VOLT_OFF_START, PMIC2_SWA_VOLT_OFF_LEN};
        static constexpr field_t PMIC2_SWA_OFF_DIRECTION{PMIC2_SWA_VOLT_OFF_BYTE, PMIC2_SWA_OFF_DIRECTION_START, PMIC2_SWA_OFF_DIRECTION_LEN};

        // Byte 334: PMIC2 SWA Delay Sequence Order
        static constexpr field_t PMIC2_SWA_DELAY{PMIC2_SWA_DELAY_BYTE, PMIC2_SWA_DELAY_START, PMIC2_SWA_DELAY_LEN};
        static constexpr field_t PMIC2_SWA_ORDER{PMIC2_SWA_DELAY_BYTE, PMIC2_SWA_ORDER_START, PMIC2_SWA_ORDER_LEN};

        // Byte 335: PMIC2 SWB Voltage Setting
        static constexpr field_t PMIC2_SWB_VOLT_SET{PMIC2_SWB_VOLT_SET_BYTE, PMIC2_SWB_VOLT_SET_START, PMIC2_SWB_VOLT_SET_LEN};
        static constexpr field_t PMIC2_SWB_RANGE_SELECT{PMIC2_SWB_VOLT_SET_BYTE, PMIC2_SWB_RANGE_SELECT_START, PMIC2_SWB_RANGE_SELECT_LEN};

        // Byte 336: PMIC2 SWB Voltage Offset
        static constexpr field_t PMIC2_SWB_VOLT_OFF{PMIC2_SWB_VOLT_OFF_BYTE, PMIC2_SWB_VOLT_OFF_START, PMIC2_SWB_VOLT_OFF_LEN};
        static constexpr field_t PMIC2_SWB_OFF_DIRECTION{PMIC2_SWB_VOLT_OFF_BYTE, PMIC2_SWB_OFF_DIRECTION_START, PMIC2_SWB_OFF_DIRECTION_LEN};

        // Byte 337: PMIC2 SWB Delay Sequence Order
        static constexpr field_t PMIC2_SWB_DELAY{PMIC2_SWB_DELAY_BYTE, PMIC2_SWB_DELAY_START, PMIC2_SWB_DELAY_LEN};
        static constexpr field_t PMIC2_SWB_ORDER{PMIC2_SWB_DELAY_BYTE, PMIC2_SWB_ORDER_START, PMIC2_SWB_ORDER_LEN};

        // Byte 338: PMIC2 SWC Voltage Setting
        static constexpr field_t PMIC2_SWC_VOLT_SET{PMIC2_SWC_VOLT_SET_BYTE, PMIC2_SWC_VOLT_SET_START, PMIC2_SWC_VOLT_SET_LEN};
        static constexpr field_t PMIC2_SWC_RANGE_SELECT{PMIC2_SWC_VOLT_SET_BYTE, PMIC2_SWC_RANGE_SELECT_START, PMIC2_SWC_RANGE_SELECT_LEN};

        // Byte 339: PMIC2 SWC Voltage Offset
        static constexpr field_t PMIC2_SWC_VOLT_OFF{PMIC2_SWC_VOLT_OFF_BYTE, PMIC2_SWC_VOLT_OFF_START, PMIC2_SWC_VOLT_OFF_LEN};
        static constexpr field_t PMIC2_SWC_OFF_DIRECTION{PMIC2_SWC_VOLT_OFF_BYTE, PMIC2_SWC_OFF_DIRECTION_START, PMIC2_SWC_OFF_DIRECTION_LEN};

        // Byte 340: PMIC2 SWC Delay Sequence Order
        static constexpr field_t PMIC2_SWC_DELAY{PMIC2_SWC_DELAY_BYTE, PMIC2_SWC_DELAY_START, PMIC2_SWC_DELAY_LEN};
        static constexpr field_t PMIC2_SWC_ORDER{PMIC2_SWC_DELAY_BYTE, PMIC2_SWC_ORDER_START, PMIC2_SWC_ORDER_LEN};

        // Byte 341: PMIC2 SWD Voltage Setting
        static constexpr field_t PMIC2_SWD_VOLT_SET{PMIC2_SWD_VOLT_SET_BYTE, PMIC2_SWD_VOLT_SET_START, PMIC2_SWD_VOLT_SET_LEN};
        static constexpr field_t PMIC2_SWD_RANGE_SELECT{PMIC2_SWD_VOLT_SET_BYTE, PMIC2_SWD_RANGE_SELECT_START, PMIC2_SWD_RANGE_SELECT_LEN};

        // Byte 342: PMIC2 SWD Voltage Offset
        static constexpr field_t PMIC2_SWD_VOLT_OFF{PMIC2_SWD_VOLT_OFF_BYTE, PMIC2_SWD_VOLT_OFF_START, PMIC2_SWD_VOLT_OFF_LEN};
        static constexpr field_t PMIC2_SWD_OFF_DIRECTION{PMIC2_SWD_VOLT_OFF_BYTE, PMIC2_SWD_OFF_DIRECTION_START, PMIC2_SWD_OFF_DIRECTION_LEN};

        // Byte 343: PMIC2 SWD Delay Sequence Order
        static constexpr field_t PMIC2_SWD_DELAY{PMIC2_SWD_DELAY_BYTE, PMIC2_SWD_DELAY_START, PMIC2_SWD_DELAY_LEN};
        static constexpr field_t PMIC2_SWD_ORDER{PMIC2_SWD_DELAY_BYTE, PMIC2_SWD_ORDER_START, PMIC2_SWD_ORDER_LEN};

        // Byte 344: PMIC2 Phase Combination and redundancy
        static constexpr field_t PMIC2_REDUNDANCY{PMIC2_PHASE_COMBIN_BYTE, PMIC2_REDUNDANCY_START, PMIC2_REDUNDANCY_LEN};
        static constexpr field_t PMIC2_PHASE_COMBIN{PMIC2_PHASE_COMBIN_BYTE, PMIC2_PHASE_COMBIN_START, PMIC2_PHASE_COMBIN_LEN};

        // Byte 345: PMIC3 SWA Voltage Setting
        static constexpr field_t PMIC3_SWA_VOLT_SET{PMIC3_SWA_VOLT_SET_BYTE, PMIC3_SWA_VOLT_SET_START, PMIC3_SWA_VOLT_SET_LEN};
        static constexpr field_t PMIC3_SWA_RANGE_SELECT{PMIC3_SWA_VOLT_SET_BYTE, PMIC3_SWA_RANGE_SELECT_START, PMIC3_SWA_RANGE_SELECT_LEN};

        // Byte 346: PMIC3 SWA Voltage Offset
        static constexpr field_t PMIC3_SWA_VOLT_OFF{PMIC3_SWA_VOLT_OFF_BYTE, PMIC3_SWA_VOLT_OFF_START, PMIC3_SWA_VOLT_OFF_LEN};
        static constexpr field_t PMIC3_SWA_OFF_DIRECTION{PMIC3_SWA_VOLT_OFF_BYTE, PMIC3_SWA_OFF_DIRECTION_START, PMIC3_SWA_OFF_DIRECTION_LEN};

        // Byte 347: PMIC3 SWA Delay Sequence Order
        static constexpr field_t PMIC3_SWA_DELAY{PMIC3_SWA_DELAY_BYTE, PMIC3_SWA_DELAY_START, PMIC3_SWA_DELAY_LEN};
        static constexpr field_t PMIC3_SWA_ORDER{PMIC3_SWA_DELAY_BYTE, PMIC3_SWA_ORDER_START, PMIC3_SWA_ORDER_LEN};

        // Byte 348: PMIC3 SWB Voltage Setting
        static constexpr field_t PMIC3_SWB_VOLT_SET{PMIC3_SWB_VOLT_SET_BYTE, PMIC3_SWB_VOLT_SET_START, PMIC3_SWB_VOLT_SET_LEN};
        static constexpr field_t PMIC3_SWB_RANGE_SELECT{PMIC3_SWB_VOLT_SET_BYTE, PMIC3_SWB_RANGE_SELECT_START, PMIC3_SWB_RANGE_SELECT_LEN};

        // Byte 349: PMIC3 SWB Voltage Offset
        static constexpr field_t PMIC3_SWB_VOLT_OFF{PMIC3_SWB_VOLT_OFF_BYTE, PMIC3_SWB_VOLT_OFF_START, PMIC3_SWB_VOLT_OFF_LEN};
        static constexpr field_t PMIC3_SWB_OFF_DIRECTION{PMIC3_SWB_VOLT_OFF_BYTE, PMIC3_SWB_OFF_DIRECTION_START, PMIC3_SWB_OFF_DIRECTION_LEN};

        // Byte 350: PMIC3 SWB Delay Sequence Order
        static constexpr field_t PMIC3_SWB_DELAY{PMIC3_SWB_DELAY_BYTE, PMIC3_SWB_DELAY_START, PMIC3_SWB_DELAY_LEN};
        static constexpr field_t PMIC3_SWB_ORDER{PMIC3_SWB_DELAY_BYTE, PMIC3_SWB_ORDER_START, PMIC3_SWB_ORDER_LEN};

        // Byte 351: PMIC3 SWC Voltage Setting
        static constexpr field_t PMIC3_SWC_VOLT_SET{PMIC3_SWC_VOLT_SET_BYTE, PMIC3_SWC_VOLT_SET_START, PMIC3_SWC_VOLT_SET_LEN};
        static constexpr field_t PMIC3_SWC_RANGE_SELECT{PMIC3_SWC_VOLT_SET_BYTE, PMIC3_SWC_RANGE_SELECT_START, PMIC3_SWC_RANGE_SELECT_LEN};

        // Byte 352: PMIC3 SWC Voltage Offset
        static constexpr field_t PMIC3_SWC_VOLT_OFF{PMIC3_SWC_VOLT_OFF_BYTE, PMIC3_SWC_VOLT_OFF_START, PMIC3_SWC_VOLT_OFF_LEN};
        static constexpr field_t PMIC3_SWC_OFF_DIRECTION{PMIC3_SWC_VOLT_OFF_BYTE, PMIC3_SWC_OFF_DIRECTION_START, PMIC3_SWC_OFF_DIRECTION_LEN};

        // Byte 353: PMIC3 SWC Delay Sequence Order
        static constexpr field_t PMIC3_SWC_DELAY{PMIC3_SWC_DELAY_BYTE, PMIC3_SWC_DELAY_START, PMIC3_SWC_DELAY_LEN};
        static constexpr field_t PMIC3_SWC_ORDER{PMIC3_SWC_DELAY_BYTE, PMIC3_SWC_ORDER_START, PMIC3_SWC_ORDER_LEN};

        // Byte 354: PMIC3 SWD Voltage Setting
        static constexpr field_t PMIC3_SWD_VOLT_SET{PMIC3_SWD_VOLT_SET_BYTE, PMIC3_SWD_VOLT_SET_START, PMIC3_SWD_VOLT_SET_LEN};
        static constexpr field_t PMIC3_SWD_RANGE_SELECT{PMIC3_SWD_VOLT_SET_BYTE, PMIC3_SWD_RANGE_SELECT_START, PMIC3_SWD_RANGE_SELECT_LEN};

        // Byte 355: PMIC3 SWD Voltage Offset
        static constexpr field_t PMIC3_SWD_VOLT_OFF{PMIC3_SWD_VOLT_OFF_BYTE, PMIC3_SWD_VOLT_OFF_START, PMIC3_SWD_VOLT_OFF_LEN};
        static constexpr field_t PMIC3_SWD_OFF_DIRECTION{PMIC3_SWD_VOLT_OFF_BYTE, PMIC3_SWD_OFF_DIRECTION_START, PMIC3_SWD_OFF_DIRECTION_LEN};

        // Byte 356: PMIC3 SWD Delay Sequence Order
        static constexpr field_t PMIC3_SWD_DELAY{PMIC3_SWD_DELAY_BYTE, PMIC3_SWD_DELAY_START, PMIC3_SWD_DELAY_LEN};
        static constexpr field_t PMIC3_SWD_ORDER{PMIC3_SWD_DELAY_BYTE, PMIC3_SWD_ORDER_START, PMIC3_SWD_ORDER_LEN};

        // Byte 357: PMIC3 Phase Combination and redundancy
        static constexpr field_t PMIC3_REDUNDANCY{PMIC3_PHASE_COMBIN_BYTE, PMIC3_REDUNDANCY_START, PMIC3_REDUNDANCY_LEN};
        static constexpr field_t PMIC3_PHASE_COMBIN{PMIC3_PHASE_COMBIN_BYTE, PMIC3_PHASE_COMBIN_START, PMIC3_PHASE_COMBIN_LEN};

        // Byte 358: Voltage VIN_MTG Edge connector
        static constexpr field_t VIN_MGMT_NOMINAL{VIN_MGMT_BYTE, VIN_MGMT_NOMINAL_START, VIN_MGMT_NOMINAL_LEN};
        static constexpr field_t VIN_MGMT_OPERABLE{VIN_MGMT_BYTE, VIN_MGMT_OPERABLE_START, VIN_MGMT_OPERABLE_LEN};
        static constexpr field_t VIN_MGMT_ENDURANT{VIN_MGMT_BYTE, VIN_MGMT_ENDURANT_START, VIN_MGMT_ENDURANT_LEN};

        // Byte 359: Voltage VIN_BULK Edge Connecto
        static constexpr field_t VIN_BULK_NOMINAL{VIN_BULK_BYTE, VIN_BULK_NOMINAL_START, VIN_BULK_NOMINAL_LEN};
        static constexpr field_t VIN_BULK_OPERABLE{VIN_BULK_BYTE, VIN_BULK_OPERABLE_START, VIN_BULK_OPERABLE_LEN};
        static constexpr field_t VIN_BULK_ENDURANT{VIN_BULK_BYTE, VIN_BULK_ENDURANT_START, VIN_BULK_ENDURANT_LEN};

        // Byte 360: Thermal Heat Spreader Solution
        static constexpr field_t HEAT_SPREADER_SOL{THERMAL_BYTE, HEAT_SPREADER_SOL_START, HEAT_SPREADER_SOL_LEN};
        static constexpr field_t HEAT_SPREADER_CHAR{THERMAL_BYTE, HEAT_SPREADER_CHAR_START, HEAT_SPREADER_CHAR_LEN};

        // Byte 361: Module Thermal Sensors
        static constexpr field_t MOD_THERMAL_SENSOR{THERMAL_SENSORS_BYTE, MOD_THERMAL_SENSOR_START, MOD_THERMAL_SENSOR_LEN};

        // Byte 362: Host Interface Protocols
        static constexpr field_t PROTOCOL_SUPPORT{PROTOCOL_SUPPORT_BYTE, PROTOCOL_SUPPORT_START, PROTOCOL_SUPPORT_LEN};

        // Byte 363: Host Interface Speed Supported
        static constexpr field_t SPEED_SUPPORTED_LSB{SPEED_SUPPORTED_LSB_BYTE, SPEED_SUPPORTED_LSB_START, SPEED_SUPPORTED_LSB_LEN};

        // Byte 364: Mem Alert Enable and Pull-Up
        static constexpr field_t PHY_A0_B0_MEM_ALERT_PULL_UP_VALUE{MEM_ALERT_EN_PULL_UP_BYTE, PHY_A0_B0_MEM_ALERT_PULL_UP_VALUE_START, PHY_A0_B0_MEM_ALERT_PULL_UP_VALUE_LEN};
        static constexpr field_t PHY_A1_B1_MEM_ALERT_PULL_UP_VALUE{MEM_ALERT_EN_PULL_UP_BYTE, PHY_A1_B1_MEM_ALERT_PULL_UP_VALUE_START, PHY_A1_B1_MEM_ALERT_PULL_UP_VALUE_LEN};
        static constexpr field_t PHY_A0_B0_MEM_ALERT{MEM_ALERT_EN_PULL_UP_BYTE, PHY_A0_B0_MEM_ALERT_START, PHY_A0_B0_MEM_ALERT_LEN};
        static constexpr field_t PHY_A1_B1_MEM_ALERT{MEM_ALERT_EN_PULL_UP_BYTE, PHY_A1_B1_MEM_ALERT_START, PHY_A1_B1_MEM_ALERT_LEN};

        // Byte 365: Address Mirroring
        static constexpr field_t ADDRESS_MIRROR{ADDRESS_MIRROR_BYTE, ADDRESS_MIRROR_START, ADDRESS_MIRROR_LEN};

        // Byte 366: Byte enables LSB
        static constexpr field_t BYTE_ENABLES_LSB{BYTE_ENABLES_LSB_BYTE, BYTE_ENABLES_LSB_START, BYTE_ENABLES_LSB_LEN};

        // Byte 367: Byte enables MSB
        static constexpr field_t BYTE_ENABLES_MSB{BYTE_ENABLES_MSB_BYTE, BYTE_ENABLES_MSB_START, BYTE_ENABLES_MSB_LEN};

        // Byte 368: Nibble enables LSB0
        static constexpr field_t NIBBLE_ENABLES_LSB0{NIBBLE_ENABLES_LSB0_BYTE, NIBBLE_ENABLES_LSB0_START, NIBBLE_ENABLES_LSB0_LEN};

        // Byte 369: Nibble enables MSB0
        static constexpr field_t NIBBLE_ENABLES_MSB0{NIBBLE_ENABLES_MSB0_BYTE, NIBBLE_ENABLES_MSB0_START, NIBBLE_ENABLES_MSB0_LEN};

        // Byte 370: Nibble enables LSB1
        static constexpr field_t NIBBLE_ENABLES_LSB1{NIBBLE_ENABLES_LSB1_BYTE, NIBBLE_ENABLES_LSB1_START, NIBBLE_ENABLES_LSB1_LEN};

        // Byte 372: REDUNDANT CHIP SELECT MODE
        static constexpr field_t REDUNDANT_CS_EN_CHA0{MEMORY_CHANNEL_EN_REDUNDANT_CHIP_BYTE, REDUNDANT_CS_EN_CHA0_START, REDUNDANT_CS_EN_CHA0_LEN};
        static constexpr field_t REDUNDANT_CS_EN_CHB0{MEMORY_CHANNEL_EN_REDUNDANT_CHIP_BYTE, REDUNDANT_CS_EN_CHB0_START, REDUNDANT_CS_EN_CHB0_LEN};
        static constexpr field_t REDUNDANT_CS_EN_CHA1{MEMORY_CHANNEL_EN_REDUNDANT_CHIP_BYTE, REDUNDANT_CS_EN_CHA1_START, REDUNDANT_CS_EN_CHA1_LEN};
        static constexpr field_t REDUNDANT_CS_EN_CHB1{MEMORY_CHANNEL_EN_REDUNDANT_CHIP_BYTE, REDUNDANT_CS_EN_CHB1_START, REDUNDANT_CS_EN_CHB1_LEN};
        static constexpr field_t MEMORY_CHA0_EXIST{MEMORY_CHANNEL_EN_REDUNDANT_CHIP_BYTE, MEMORY_CHA0_EXIST_START, MEMORY_CHA0_EXIST_START};
        static constexpr field_t MEMORY_CHB0_EXIST{MEMORY_CHANNEL_EN_REDUNDANT_CHIP_BYTE, MEMORY_CHB0_EXIST_START, MEMORY_CHB0_EXIST_START};
        static constexpr field_t MEMORY_CHA1_EXIST{MEMORY_CHANNEL_EN_REDUNDANT_CHIP_BYTE, MEMORY_CHA1_EXIST_START, MEMORY_CHA1_EXIST_START};
        static constexpr field_t MEMORY_CHB1_EXIST{MEMORY_CHANNEL_EN_REDUNDANT_CHIP_BYTE, MEMORY_CHB1_EXIST_START, MEMORY_CHB1_EXIST_START};

        // Byte 373: Spare Device Mapping LSB0
        static constexpr field_t SPARE_DEVICE_LSB0{SPARE_DEVICE_LSB0_BYTE, SPARE_DEVICE_LSB0_START, SPARE_DEVICE_LSB0_LEN};

        // Byte 374: Spare Device Mapping MSB0
        static constexpr field_t SPARE_DEVICE_MSB0{SPARE_DEVICE_MSB0_BYTE, SPARE_DEVICE_MSB0_START, SPARE_DEVICE_MSB0_LEN};

        // Byte 375: Spare Device Mapping LSB1
        static constexpr field_t SPARE_DEVICE_LSB1{SPARE_DEVICE_LSB1_BYTE, SPARE_DEVICE_LSB1_START, SPARE_DEVICE_LSB1_LEN};

        // Byte 377: Host Interface Speed to DDR Interface Speed Ratio
        static constexpr field_t HI_DDR_SPEED_RATIO{HI_DDR_SPEED_RATIO_BYTE, HI_DDR_SPEED_RATIO_START, HI_DDR_SPEED_RATIO_LEN};

        // Byte 378: External PHY Calibration Resistor Value
        static constexpr field_t PHY_A0_B0_CAL_RESISTOR{EXT_PHY_CAL_RESISTOR_VALUE_BYTE, PHY_A0_B0_CAL_RESISTOR_START, PHY_A0_B0_CAL_RESISTOR_LEN};
        static constexpr field_t PHY_A1_B1_CAL_RESISTOR{EXT_PHY_CAL_RESISTOR_VALUE_BYTE, PHY_A1_B1_CAL_RESISTOR_START, PHY_A1_B1_CAL_RESISTOR_LEN};

        // Byte 410: Doubletop Manufacturer Product ID
        static constexpr field_t DOUBLETOP_MANF_PROD_ID{DOUBLETOP_MANF_PROD_ID_BYTE, DOUBLETOP_MANF_PROD_ID_START, DOUBLETOP_MANF_PROD_ID_LEN};

        // Byte 411: Doubletop Revision
        static constexpr field_t DOUBLETOP_REVISION{DOUBLETOP_REVISION_BYTE, DOUBLETOP_REVISION_START, DOUBLETOP_REVISION_LEN};

        // Byte 412: Power Control 0 I2C Address
        static constexpr field_t POWER_CNTL_0_I2C_ADDRESS{POWER_CNTL_0_I2C_ADDRESS_BYTE, POWER_CNTL_0_I2C_ADDRESS_START, POWER_CNTL_0_I2C_ADDRESS_LEN};

        // Byte 413: Power Control 0 I2C Address
        static constexpr field_t POWER_CNTL_1_I2C_ADDRESS{POWER_CNTL_1_I2C_ADDRESS_BYTE, POWER_CNTL_1_I2C_ADDRESS_START, POWER_CNTL_1_I2C_ADDRESS_LEN};

        // Byte 414: Power Control 0 I2C Address
        static constexpr field_t POWER_CNTL_2_I2C_ADDRESS{POWER_CNTL_0_I2C_ADDRESS_BYTE, POWER_CNTL_2_I2C_ADDRESS_START, POWER_CNTL_2_I2C_ADDRESS_LEN};

        // Byte 415: Power Control 0 I2C Address
        static constexpr field_t POWER_CNTL_3_I2C_ADDRESS{POWER_CNTL_0_I2C_ADDRESS_BYTE, POWER_CNTL_3_I2C_ADDRESS_START, POWER_CNTL_3_I2C_ADDRESS_LEN};

        // MANF Section:
        // Section is not standardized across dimm types, so these fields will live in the
        // ddimm specific section
        static constexpr field_t SERIAL_NUMBER_LAST_BYTE{SERIAL_NUMBER_LAST_VALID_BYTE, SERIAL_NUMBER_FIELD_START, SERIAL_NUMBER_FIELD_LEN};

        // Byte 512 and 513 Module MFG ID
        static constexpr field_t MODULE_MFG_ID_CODE_LSB{MODULE_MFG_ID_CODE_LSB_BYTE, MODULE_MFG_ID_CODE_START, MODULE_MFG_ID_CODE_LEN};
        static constexpr field_t MODULE_MFG_ID_CODE_MSB{MODULE_MFG_ID_CODE_MSB_BYTE, MODULE_MFG_ID_CODE_START, MODULE_MFG_ID_CODE_LEN};

        // Byte 552 and 553: DRAM manufacturing ID for DDIMMs
        static constexpr field_t DRAM_MFR_ID_CODE_LSB{DRAM_MFR_ID_CODE_LSB_BYTE, DRAM_MFR_ID_CODE_START, DRAM_MFR_ID_CODE_LEN};
        static constexpr field_t DRAM_MFR_ID_CODE_MSB{DRAM_MFR_ID_CODE_MSB_BYTE, DRAM_MFR_ID_CODE_START, DRAM_MFR_ID_CODE_LEN};
};

}// spd
}// mss

#endif // _MSS_SPD_FIELDS_DDR5_H_
