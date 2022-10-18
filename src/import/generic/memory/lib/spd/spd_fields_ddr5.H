/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/spd_fields_ddr5.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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
            DESIGN_REV_LEN = 3,
            DESIGN_REF_CARD_START = 3,
            DESIGN_REF_CARD_LEN = 5,

            // Byte 196: DIMM attributes
            DIMM_ATTR_BYTE = 196,
            DIMM_ATTR_REGISTER_TYPE_START = 0,
            DIMM_ATTR_REGISTER_TYPE_LEN = 4,
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
            NUM_PACKAGE_RANKS_CHAN1_START = 0,
            NUM_PACKAGE_RANKS_CHAN1_LEN = 3,
            NUM_PACKAGE_RANKS_CHAN0_START = 3,
            NUM_PACKAGE_RANKS_CHAN0_LEN = 3,
            SDRAM_DATA_WID_CHAN_START = 6,
            SDRAM_DATA_WID_CHAN_LEN = 2,


            // Byte 202: Memory Channel Bus Width
            BUS_WIDTH_BYTE = 202,
            ENABLED_PHY_CHANNELS_START = 0,
            ENABLED_PHY_CHANNELS_LEN = 2,
            BUS_WIDTH_CHANNEL_A_START = 2,
            BUS_WIDTH_CHANNEL_A_LEN = 3,
            BUS_WIDTH_CHANNEL_B_START = 5,
            BUS_WIDTH_CHANNEL_B_LEN = 3,

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

            // TODO: Zen: MST-1843: New bytes need to be addedd to eff cnfg SPD

            // Byte 207: Address Mirroring
            ADDRESS_MIRROR_BYTE = 207,
            ADDRESS_MIRROR_START = 0,
            ADDRESS_MIRROR_LEN = 8,

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

            // Byte 213: Nibble enables MSB1
            // Reserved

            // Byte 214: REDUNDANT CHIP SELECT MODE
            // TODO: More updates on this byte by another commit
            DDIMM_COMPAT_BYTE = 214,
            DDIMM_REDUNDANT_CS_EN_START = 7,
            DDIMM_REDUNDANT_CS_EN_LEN = 1,

            // Byte 215: Number of P-States
            // Reserved

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

            // Byte 219: Spare Device Mapping MSB1
            // Reserved

            // Byte 220: Host Interface Speed to DDR Interface Speed Ratio
            HI_DDR_SPEED_RATIO_BYTE = 220,
            HI_DDR_SPEED_RATIO_START = 4,
            HI_DDR_SPEED_RATIO_LEN = 4,

            // Byte 221: SPD Content Revision
            SPD_CONTENT_REVISION_BYTE = 221,
            SPD_CONTENT_REVISION_START = 0,
            SPD_CONTENT_REVISION_LEN = 8,

            // TODO: Zen: MST-1843: New bytes need to be addedd to eff cnfg SPD

            // Byte 224: Voltage VIN_MTG Edge Connector
            VIN_MGMT_BYTE = 224,
            VIN_MGMT_NOMINAL_START = 0,
            VIN_MGMT_NOMINAL_LEN = 4,
            VIN_MGMT_OPERABLE_START = 4,
            VIN_MGMT_OPERABLE_LEN = 2,
            VIN_MGMT_ENDURANT_START = 6,
            VIN_MGMT_ENDURANT_LEN = 2,

            // Byte 225: Voltage VIN_BULK Edge Connector
            VIN_BULK_BYTE = 225,
            VIN_BULK_NOMINAL_START = 0,
            VIN_BULK_NOMINAL_LEN = 4,
            VIN_BULK_OPERABLE_START = 4,
            VIN_BULK_OPERABLE_LEN = 2,
            VIN_BULK_ENDURANT_START = 6,
            VIN_BULK_ENDURANT_LEN = 2,

            // Byte 226: PMIC0 Sequence
            PMIC0_SEQUENCE_BYTE = 226,
            PMIC0_SUPPLY_VOLTAGE_START = 0,
            PMIC0_SUPPLY_VOLTAGE_LEN = 5,
            PMIC0_SEQUENCE_START = 5,
            PMIC0_SEQUENCE_LEN = 3,

            // Byte 227: PMIC1 Sequence
            PMIC1_SEQUENCE_BYTE = 227,
            PMIC1_SUPPLY_VOLTAGE_START = 0,
            PMIC1_SUPPLY_VOLTAGE_LEN = 5,
            PMIC1_SEQUENCE_START = 5,
            PMIC1_SEQUENCE_LEN = 3,

            // Byte 228: PMIC2 Sequence
            PMIC2_SEQUENCE_BYTE = 228,
            PMIC2_SUPPLY_VOLTAGE_START = 0,
            PMIC2_SUPPLY_VOLTAGE_LEN = 5,
            PMIC2_SEQUENCE_START = 5,
            PMIC2_SEQUENCE_LEN = 3,

            // Byte 229: PMIC3 Sequence
            PMIC3_SEQUENCE_BYTE = 229,
            PMIC3_SUPPLY_VOLTAGE_START = 0,
            PMIC3_SUPPLY_VOLTAGE_LEN = 5,
            PMIC3_SEQUENCE_START = 5,
            PMIC3_SEQUENCE_LEN = 3,

            // Byte 230: PMIC0 Manfacture ID code 1st byte
            PMIC0_MFG_CODE1_BYTE = 230,
            PMIC0_CONT_CODE_START = 0,
            PMIC0_CONT_CODE_LEN = 8,

            // Byte 231: PMIC0 Manfacture ID code 2nd byte
            PMIC0_MFG_CODE2_BYTE = 231,
            PMIC0_LAST_NON_ZERO_START = 0,
            PMIC0_LAST_NON_ZERO_LEN = 8,

            // Byte 232: PMIC0 Revision Number
            PMIC0_REV_BYTE = 232,
            PMIC0_REV_START = 0,
            PMIC0_REV_LEN = 8,

            // Byte 233: PMIC1 Manfacture ID code 1st byte
            PMIC1_MFG_CODE1_BYTE = 233,
            PMIC1_CONT_CODE_START = 0,
            PMIC1_CONT_CODE_LEN = 8,

            // Byte 234: PMIC1 Manfacture ID code 2nd byte
            PMIC1_MFG_CODE2_BYTE = 234,
            PMIC1_LAST_NON_ZERO_START = 0,
            PMIC1_LAST_NON_ZERO_LEN = 8,

            // Byte 235: PMIC1 Revision Number
            PMIC1_REV_BYTE = 235,
            PMIC1_REV_START = 0,
            PMIC1_REV_LEN = 8,

            // Byte 236: PMIC2 Manfacture ID code 1st byte
            PMIC2_MFG_CODE1_BYTE = 236,
            PMIC2_CONT_CODE_START = 0,
            PMIC2_CONT_CODE_LEN = 8,

            // Byte 237: PMIC2 Manfacture ID code 2nd byte
            PMIC2_MFG_CODE2_BYTE = 237,
            PMIC2_LAST_NON_ZERO_START = 0,
            PMIC2_LAST_NON_ZERO_LEN = 8,

            // Byte 238: PMIC2 Revision Number
            PMIC2_REV_BYTE = 238,
            PMIC2_REV_START = 0,
            PMIC2_REV_LEN = 8,

            // Byte 239: PMIC3 Manfacture ID code 1st byte
            PMIC3_MFG_CODE1_BYTE = 239,
            PMIC3_CONT_CODE_START = 0,
            PMIC3_CONT_CODE_LEN = 8,

            // Byte 240: PMIC3 Manfacture ID code 2nd byte
            PMIC3_MFG_CODE2_BYTE = 240,
            PMIC3_LAST_NON_ZERO_START = 0,
            PMIC3_LAST_NON_ZERO_LEN = 8,

            // Byte 241: PMIC3 Revision Number
            PMIC3_REV_BYTE = 241,
            PMIC3_REV_START = 0,
            PMIC3_REV_LEN = 8,

            // Byte 242: PMIC0 SWA Voltage Setting
            PMIC0_SWA_VOLT_SET_BYTE = 242,
            PMIC0_SWA_VOLT_SET_START = 0,
            PMIC0_SWA_VOLT_SET_LEN = 7,
            PMIC0_SWA_RANGE_SELECT_START = 7,
            PMIC0_SWA_RANGE_SELECT_LEN = 1,

            // Byte 243: PMIC0 SWA Voltage Offset
            PMIC0_SWA_VOLT_OFF_BYTE = 243,
            PMIC0_SWA_VOLT_OFF_START = 0,
            PMIC0_SWA_VOLT_OFF_LEN = 7,
            PMIC0_SWA_OFF_DIRECTION_START = 7,
            PMIC0_SWA_OFF_DIRECTION_LEN = 1,

            // Byte 244: PMIC0 SWA Delay Sequence Order
            PMIC0_SWA_DELAY_BYTE = 244,
            PMIC0_SWA_DELAY_START = 0,
            PMIC0_SWA_DELAY_LEN = 4,
            PMIC0_SWA_ORDER_START = 4,
            PMIC0_SWA_ORDER_LEN = 4,

            // Byte 245: PMIC0 SWB Voltage Setting
            PMIC0_SWB_VOLT_SET_BYTE = 245,
            PMIC0_SWB_VOLT_SET_START = 0,
            PMIC0_SWB_VOLT_SET_LEN = 7,
            PMIC0_SWB_RANGE_SELECT_START = 7,
            PMIC0_SWB_RANGE_SELECT_LEN = 1,

            // Byte 246: PMIC0 SWB Voltage Offset
            PMIC0_SWB_VOLT_OFF_BYTE = 246,
            PMIC0_SWB_VOLT_OFF_START = 0,
            PMIC0_SWB_VOLT_OFF_LEN = 7,
            PMIC0_SWB_OFF_DIRECTION_START = 7,
            PMIC0_SWB_OFF_DIRECTION_LEN = 1,

            // Byte 247: PMIC0 SWB Delay Sequence Order
            PMIC0_SWB_DELAY_BYTE = 247,
            PMIC0_SWB_DELAY_START = 0,
            PMIC0_SWB_DELAY_LEN = 4,
            PMIC0_SWB_ORDER_START = 4,
            PMIC0_SWB_ORDER_LEN = 4,

            // Byte 248: PMIC0 SWC Voltage Setting
            PMIC0_SWC_VOLT_SET_BYTE = 248,
            PMIC0_SWC_VOLT_SET_START = 0,
            PMIC0_SWC_VOLT_SET_LEN = 7,
            PMIC0_SWC_RANGE_SELECT_START = 7,
            PMIC0_SWC_RANGE_SELECT_LEN = 1,

            // Byte 249: PMIC0 SWC Voltage Offset
            PMIC0_SWC_VOLT_OFF_BYTE = 249,
            PMIC0_SWC_VOLT_OFF_START = 0,
            PMIC0_SWC_VOLT_OFF_LEN = 7,
            PMIC0_SWC_OFF_DIRECTION_START = 7,
            PMIC0_SWC_OFF_DIRECTION_LEN = 1,

            // Byte 250: PMIC0 SWC Delay Sequence Order
            PMIC0_SWC_DELAY_BYTE = 250,
            PMIC0_SWC_DELAY_START = 0,
            PMIC0_SWC_DELAY_LEN = 4,
            PMIC0_SWC_ORDER_START = 4,
            PMIC0_SWC_ORDER_LEN = 4,

            // Byte 251: PMIC0 SWD Voltage Setting
            PMIC0_SWD_VOLT_SET_BYTE = 251,
            PMIC0_SWD_VOLT_SET_START = 0,
            PMIC0_SWD_VOLT_SET_LEN = 7,
            PMIC0_SWD_RANGE_SELECT_START = 7,
            PMIC0_SWD_RANGE_SELECT_LEN = 1,

            // Byte 252: PMIC0 SWD Voltage Offset
            PMIC0_SWD_VOLT_OFF_BYTE = 252,
            PMIC0_SWD_VOLT_OFF_START = 0,
            PMIC0_SWD_VOLT_OFF_LEN = 7,
            PMIC0_SWD_OFF_DIRECTION_START = 7,
            PMIC0_SWD_OFF_DIRECTION_LEN = 1,

            // Byte 253: PMIC0 SWD Delay Sequence Order
            PMIC0_SWD_DELAY_BYTE = 253,
            PMIC0_SWD_DELAY_START = 0,
            PMIC0_SWD_DELAY_LEN = 4,
            PMIC0_SWD_ORDER_START = 4,
            PMIC0_SWD_ORDER_LEN = 4,

            // Byte 254: PMIC0 Phase Combination and redundancy
            PMIC0_PHASE_COMBIN_BYTE = 254,
            PMIC0_REDUNDANCY_START = 0,
            PMIC0_REDUNDANCY_LEN = 1,
            PMIC0_PHASE_COMBIN_START = 4,
            PMIC0_PHASE_COMBIN_LEN = 4,

            // Byte 255: PMIC1 SWA Voltage Setting
            PMIC1_SWA_VOLT_SET_BYTE = 255,
            PMIC1_SWA_VOLT_SET_START = 0,
            PMIC1_SWA_VOLT_SET_LEN = 7,
            PMIC1_SWA_RANGE_SELECT_START = 7,
            PMIC1_SWA_RANGE_SELECT_LEN = 1,

            // Byte 256: PMIC1 SWA Voltage Offset
            PMIC1_SWA_VOLT_OFF_BYTE = 256,
            PMIC1_SWA_VOLT_OFF_START = 0,
            PMIC1_SWA_VOLT_OFF_LEN = 7,
            PMIC1_SWA_OFF_DIRECTION_START = 7,
            PMIC1_SWA_OFF_DIRECTION_LEN = 1,

            // Byte 257: PMIC1 SWA Delay Sequence Order
            PMIC1_SWA_DELAY_BYTE = 257,
            PMIC1_SWA_DELAY_START = 0,
            PMIC1_SWA_DELAY_LEN = 4,
            PMIC1_SWA_ORDER_START = 4,
            PMIC1_SWA_ORDER_LEN = 4,

            // Byte 258: PMIC1 SWB Voltage Setting
            PMIC1_SWB_VOLT_SET_BYTE = 258,
            PMIC1_SWB_VOLT_SET_START = 0,
            PMIC1_SWB_VOLT_SET_LEN = 7,
            PMIC1_SWB_RANGE_SELECT_START = 7,
            PMIC1_SWB_RANGE_SELECT_LEN = 1,

            // Byte 259: PMIC1 SWB Voltage Offset
            PMIC1_SWB_VOLT_OFF_BYTE = 259,
            PMIC1_SWB_VOLT_OFF_START = 0,
            PMIC1_SWB_VOLT_OFF_LEN = 7,
            PMIC1_SWB_OFF_DIRECTION_START = 7,
            PMIC1_SWB_OFF_DIRECTION_LEN = 1,

            // Byte 260: PMIC1 SWB Delay Sequence Order
            PMIC1_SWB_DELAY_BYTE = 260,
            PMIC1_SWB_DELAY_START = 0,
            PMIC1_SWB_DELAY_LEN = 4,
            PMIC1_SWB_ORDER_START = 4,
            PMIC1_SWB_ORDER_LEN = 4,

            // Byte 261: PMIC1 SWC Voltage Setting
            PMIC1_SWC_VOLT_SET_BYTE = 261,
            PMIC1_SWC_VOLT_SET_START = 0,
            PMIC1_SWC_VOLT_SET_LEN = 7,
            PMIC1_SWC_RANGE_SELECT_START = 7,
            PMIC1_SWC_RANGE_SELECT_LEN = 1,

            // Byte 262: PMIC1 SWC Voltage Offset
            PMIC1_SWC_VOLT_OFF_BYTE = 262,
            PMIC1_SWC_VOLT_OFF_START = 0,
            PMIC1_SWC_VOLT_OFF_LEN = 7,
            PMIC1_SWC_OFF_DIRECTION_START = 7,
            PMIC1_SWC_OFF_DIRECTION_LEN = 1,

            // Byte 263: PMIC1 SWC Delay Sequence Order
            PMIC1_SWC_DELAY_BYTE = 263,
            PMIC1_SWC_DELAY_START = 0,
            PMIC1_SWC_DELAY_LEN = 4,
            PMIC1_SWC_ORDER_START = 4,
            PMIC1_SWC_ORDER_LEN = 4,

            // Byte 264: PMIC1 SWD Voltage Setting
            PMIC1_SWD_VOLT_SET_BYTE = 264,
            PMIC1_SWD_VOLT_SET_START = 0,
            PMIC1_SWD_VOLT_SET_LEN = 7,
            PMIC1_SWD_RANGE_SELECT_START = 7,
            PMIC1_SWD_RANGE_SELECT_LEN = 1,

            // Byte 265: PMIC1 SWD Voltage Offset
            PMIC1_SWD_VOLT_OFF_BYTE = 265,
            PMIC1_SWD_VOLT_OFF_START = 0,
            PMIC1_SWD_VOLT_OFF_LEN = 7,
            PMIC1_SWD_OFF_DIRECTION_START = 7,
            PMIC1_SWD_OFF_DIRECTION_LEN = 1,

            // Byte 266: PMIC1 SWD Delay Sequence Order
            PMIC1_SWD_DELAY_BYTE = 266,
            PMIC1_SWD_DELAY_START = 0,
            PMIC1_SWD_DELAY_LEN = 4,
            PMIC1_SWD_ORDER_START = 4,
            PMIC1_SWD_ORDER_LEN = 4,

            // Byte 267: PMIC1 Phase Combination and Redundancy
            PMIC1_PHASE_COMBIN_BYTE = 267,
            PMIC1_REDUNDANCY_START = 0,
            PMIC1_REDUNDANCY_LEN = 1,
            PMIC1_PHASE_COMBIN_START = 4,
            PMIC1_PHASE_COMBIN_LEN = 4,

            // Byte 268: PMIC2 SWA Voltage Setting
            PMIC2_SWA_VOLT_SET_BYTE = 268,
            PMIC2_SWA_VOLT_SET_START = 0,
            PMIC2_SWA_VOLT_SET_LEN = 7,
            PMIC2_SWA_RANGE_SELECT_START = 7,
            PMIC2_SWA_RANGE_SELECT_LEN = 1,

            // Byte 269: PMIC2 SWA Voltage Offset
            PMIC2_SWA_VOLT_OFF_BYTE = 269,
            PMIC2_SWA_VOLT_OFF_START = 0,
            PMIC2_SWA_VOLT_OFF_LEN = 7,
            PMIC2_SWA_OFF_DIRECTION_START = 7,
            PMIC2_SWA_OFF_DIRECTION_LEN = 1,

            // Byte 270: PMIC2 SWA Delay Sequence Order
            PMIC2_SWA_DELAY_BYTE = 270,
            PMIC2_SWA_DELAY_START = 0,
            PMIC2_SWA_DELAY_LEN = 4,
            PMIC2_SWA_ORDER_START = 4,
            PMIC2_SWA_ORDER_LEN = 4,

            // Byte 271: PMIC2 SWB Voltage Setting
            PMIC2_SWB_VOLT_SET_BYTE = 271,
            PMIC2_SWB_VOLT_SET_START = 0,
            PMIC2_SWB_VOLT_SET_LEN = 7,
            PMIC2_SWB_RANGE_SELECT_START = 7,
            PMIC2_SWB_RANGE_SELECT_LEN = 1,

            // Byte 272: PMIC2 SWB Voltage Offset
            PMIC2_SWB_VOLT_OFF_BYTE = 272,
            PMIC2_SWB_VOLT_OFF_START = 0,
            PMIC2_SWB_VOLT_OFF_LEN = 7,
            PMIC2_SWB_OFF_DIRECTION_START = 7,
            PMIC2_SWB_OFF_DIRECTION_LEN = 1,

            // Byte 273: PMIC2 SWB Delay Sequence Order
            PMIC2_SWB_DELAY_BYTE = 273,
            PMIC2_SWB_DELAY_START = 0,
            PMIC2_SWB_DELAY_LEN = 4,
            PMIC2_SWB_ORDER_START = 4,
            PMIC2_SWB_ORDER_LEN = 4,

            // Byte 274: PMIC2 SWC Voltage Setting
            PMIC2_SWC_VOLT_SET_BYTE = 274,
            PMIC2_SWC_VOLT_SET_START = 0,
            PMIC2_SWC_VOLT_SET_LEN = 7,
            PMIC2_SWC_RANGE_SELECT_START = 7,
            PMIC2_SWC_RANGE_SELECT_LEN = 1,

            // Byte 275: PMIC2 SWC Voltage Offset
            PMIC2_SWC_VOLT_OFF_BYTE = 275,
            PMIC2_SWC_VOLT_OFF_START = 0,
            PMIC2_SWC_VOLT_OFF_LEN = 7,
            PMIC2_SWC_OFF_DIRECTION_START = 7,
            PMIC2_SWC_OFF_DIRECTION_LEN = 1,

            // Byte 276: PMIC2 SWC Delay Sequence Order
            PMIC2_SWC_DELAY_BYTE = 276,
            PMIC2_SWC_DELAY_START = 0,
            PMIC2_SWC_DELAY_LEN = 4,
            PMIC2_SWC_ORDER_START = 4,
            PMIC2_SWC_ORDER_LEN = 4,

            // Byte 277: PMIC2 SWD Voltage Setting
            PMIC2_SWD_VOLT_SET_BYTE = 277,
            PMIC2_SWD_VOLT_SET_START = 0,
            PMIC2_SWD_VOLT_SET_LEN = 7,
            PMIC2_SWD_RANGE_SELECT_START = 7,
            PMIC2_SWD_RANGE_SELECT_LEN = 1,

            // Byte 278: PMIC2 SWD Voltage Offset
            PMIC2_SWD_VOLT_OFF_BYTE = 278,
            PMIC2_SWD_VOLT_OFF_START = 0,
            PMIC2_SWD_VOLT_OFF_LEN = 7,
            PMIC2_SWD_OFF_DIRECTION_START = 7,
            PMIC2_SWD_OFF_DIRECTION_LEN = 1,

            // Byte 279: PMIC2 SWD Delay Sequence Order
            PMIC2_SWD_DELAY_BYTE = 279,
            PMIC2_SWD_DELAY_START = 0,
            PMIC2_SWD_DELAY_LEN = 4,
            PMIC2_SWD_ORDER_START = 4,
            PMIC2_SWD_ORDER_LEN = 4,

            // Byte 280: PMIC2 Phase Combination and Redundancy
            PMIC2_PHASE_COMBIN_BYTE = 280,
            PMIC2_REDUNDANCY_START = 0,
            PMIC2_REDUNDANCY_LEN = 1,
            PMIC2_PHASE_COMBIN_START = 4,
            PMIC2_PHASE_COMBIN_LEN = 4,

            // Byte 281: PMIC3 SWA Voltage Setting
            PMIC3_SWA_VOLT_SET_BYTE = 281,
            PMIC3_SWA_VOLT_SET_START = 0,
            PMIC3_SWA_VOLT_SET_LEN = 7,
            PMIC3_SWA_RANGE_SELECT_START = 7,
            PMIC3_SWA_RANGE_SELECT_LEN = 1,

            // Byte 282: PMIC3 SWA Voltage Offset
            PMIC3_SWA_VOLT_OFF_BYTE = 282,
            PMIC3_SWA_VOLT_OFF_START = 0,
            PMIC3_SWA_VOLT_OFF_LEN = 7,
            PMIC3_SWA_OFF_DIRECTION_START = 7,
            PMIC3_SWA_OFF_DIRECTION_LEN = 1,

            // Byte 283: PMIC3 SWA Delay Sequence Order
            PMIC3_SWA_DELAY_BYTE = 283,
            PMIC3_SWA_DELAY_START = 0,
            PMIC3_SWA_DELAY_LEN = 4,
            PMIC3_SWA_ORDER_START = 4,
            PMIC3_SWA_ORDER_LEN = 4,

            // Byte 284: PMIC2 SWB Voltage Setting
            PMIC3_SWB_VOLT_SET_BYTE = 284,
            PMIC3_SWB_VOLT_SET_START = 0,
            PMIC3_SWB_VOLT_SET_LEN = 7,
            PMIC3_SWB_RANGE_SELECT_START = 7,
            PMIC3_SWB_RANGE_SELECT_LEN = 1,

            // Byte 285: PMIC2 SWB Voltage Offset
            PMIC3_SWB_VOLT_OFF_BYTE = 285,
            PMIC3_SWB_VOLT_OFF_START = 0,
            PMIC3_SWB_VOLT_OFF_LEN = 7,
            PMIC3_SWB_OFF_DIRECTION_START = 7,
            PMIC3_SWB_OFF_DIRECTION_LEN = 1,

            // Byte 286: PMIC3 SWB Delay Sequence Order
            PMIC3_SWB_DELAY_BYTE = 286,
            PMIC3_SWB_DELAY_START = 0,
            PMIC3_SWB_DELAY_LEN = 4,
            PMIC3_SWB_ORDER_START = 4,
            PMIC3_SWB_ORDER_LEN = 4,

            // Byte 287: PMIC3 SWC Voltage Setting
            PMIC3_SWC_VOLT_SET_BYTE = 287,
            PMIC3_SWC_VOLT_SET_START = 0,
            PMIC3_SWC_VOLT_SET_LEN = 7,
            PMIC3_SWC_RANGE_SELECT_START = 7,
            PMIC3_SWC_RANGE_SELECT_LEN = 1,

            // Byte 288: PMIC3 SWC Voltage Offset
            PMIC3_SWC_VOLT_OFF_BYTE = 288,
            PMIC3_SWC_VOLT_OFF_START = 0,
            PMIC3_SWC_VOLT_OFF_LEN = 7,
            PMIC3_SWC_OFF_DIRECTION_START = 7,
            PMIC3_SWC_OFF_DIRECTION_LEN = 1,

            // Byte 289: PMIC3 SWC Delay Sequence Order
            PMIC3_SWC_DELAY_BYTE = 289,
            PMIC3_SWC_DELAY_START = 0,
            PMIC3_SWC_DELAY_LEN = 4,
            PMIC3_SWC_ORDER_START = 4,
            PMIC3_SWC_ORDER_LEN = 4,

            // Byte 290: PMIC3 SWD Voltage Setting
            PMIC3_SWD_VOLT_SET_BYTE = 290,
            PMIC3_SWD_VOLT_SET_START = 0,
            PMIC3_SWD_VOLT_SET_LEN = 7,
            PMIC3_SWD_RANGE_SELECT_START = 7,
            PMIC3_SWD_RANGE_SELECT_LEN = 1,

            // Byte 291: PMIC3 SWD Voltage Offset
            PMIC3_SWD_VOLT_OFF_BYTE = 291,
            PMIC3_SWD_VOLT_OFF_START = 0,
            PMIC3_SWD_VOLT_OFF_LEN = 7,
            PMIC3_SWD_OFF_DIRECTION_START = 7,
            PMIC3_SWD_OFF_DIRECTION_LEN = 1,

            // Byte 292: PMIC3 SWD Delay Sequence Order
            PMIC3_SWD_DELAY_BYTE = 292,
            PMIC3_SWD_DELAY_START = 0,
            PMIC3_SWD_DELAY_LEN = 4,
            PMIC3_SWD_ORDER_START = 4,
            PMIC3_SWD_ORDER_LEN = 4,

            // Byte 293: PMIC3 Phase Combination and Redundancy
            PMIC3_PHASE_COMBIN_BYTE = 293,
            PMIC3_REDUNDANCY_START = 0,
            PMIC3_REDUNDANCY_LEN = 1,
            PMIC3_PHASE_COMBIN_START = 4,
            PMIC3_PHASE_COMBIN_LEN = 4,

            // Byte 294: PMIC0 IIC Address
            PMIC0_IIC_ADDRESS_BYTE = 294,
            PMIC0_IIC_ADDRESS_START = 0,
            PMIC0_IIC_ADDRESS_LEN = 8,

            // Byte 295: PMIC1 IIC Address
            PMIC1_IIC_ADDRESS_BYTE = 295,
            PMIC1_IIC_ADDRESS_START = 0,
            PMIC1_IIC_ADDRESS_LEN = 8,

            // Byte 296: PMIC2 IIC Address
            PMIC2_IIC_ADDRESS_BYTE = 296,
            PMIC2_IIC_ADDRESS_START = 0,
            PMIC2_IIC_ADDRESS_LEN = 8,

            // Byte 297: PMIC3 IIC Address
            PMIC3_IIC_ADDRESS_BYTE = 297,
            PMIC3_IIC_ADDRESS_START = 0,
            PMIC3_IIC_ADDRESS_LEN = 8,

            // Byte 298
            MODULE_RCD_BYTE = 298,
            MODULE_RCD_MEDIA_CONTROLLER_TYPE_START = 0,
            MODULE_RCD_MEDIA_CONTROLLER_TYPE_LEN = 4,
            MODULE_RCD_JEDEC_COMPLIANT_START = 5,
            MODULE_RCD_JEDEC_COMPLIANT_LEN = 1,
            MODULE_RCD_START = 6,
            MODULE_RCD_LEN = 2,

            // Byte 299-300: RCD MFG ID Code
            RCD_MFG_ID_LSB_BYTE = 299,
            RCD_MFG_ID_MSB_BYTE = 300,
            RCD_MFG_ID_START = 0,
            RCD_MFG_ID_LEN = 8,

            // Byte 301: RCD Revision Nunber
            RCD_REV_NUM_BYTE = 301,
            RCD_REV_NUM_START = 0,
            RCD_REV_NUM_LEN = 8,

            // Byte 302: Thermal Sensor 0 Profile
            THERM_SENSOR_0_PROFILE_BYTE = 302,
            THERM_SENSOR_0_AVAIL_START = 0,
            THERM_SENSOR_0_AVAIL_LEN = 1,
            THERM_SENSOR_0_TYPE_START = 2,
            THERM_SENSOR_0_TYPE_LEN = 3,
            THERM_SENSOR_0_USAGE_START = 5,
            THERM_SENSOR_0_USAGE_LEN = 3,

            // Byte 303: Thermal Sensor 1 Profile
            THERM_SENSOR_1_PROFILE_BYTE = 303,
            THERM_SENSOR_1_AVAIL_START = 0,
            THERM_SENSOR_1_AVAIL_LEN = 1,
            THERM_SENSOR_1_TYPE_START = 2,
            THERM_SENSOR_1_TYPE_LEN = 3,
            THERM_SENSOR_1_USAGE_START = 5,
            THERM_SENSOR_1_USAGE_LEN = 3,

            // Byte 304: Thermal Sensor 2 Profile
            THERM_SENSOR_2_PROFILE_BYTE = 304,
            THERM_SENSOR_2_AVAIL_START = 0,
            THERM_SENSOR_2_AVAIL_LEN = 1,
            THERM_SENSOR_2_TYPE_START = 2,
            THERM_SENSOR_2_TYPE_LEN = 3,
            THERM_SENSOR_2_USAGE_START = 5,
            THERM_SENSOR_2_USAGE_LEN = 3,

            // Byte 305: Thermal Sensor 3 Profile
            THERM_SENSOR_3_PROFILE_BYTE = 305,
            THERM_SENSOR_3_AVAIL_START = 0,
            THERM_SENSOR_3_AVAIL_LEN = 1,
            THERM_SENSOR_3_TYPE_START = 2,
            THERM_SENSOR_3_TYPE_LEN = 3,
            THERM_SENSOR_3_USAGE_START = 5,
            THERM_SENSOR_3_USAGE_LEN = 3,

            // Byte 306: Thermal Sensor 0 I2C Address
            THERM_SENSOR_0_I2C_ADDRESS_BYTE = 306,
            THERM_SENSOR_0_I2C_ADDRESS_START = 0,
            THERM_SENSOR_0_I2C_ADDRESS_LEN = 8,

            // Byte 307: Thermal Sensor 1 I2C Address
            THERM_SENSOR_1_I2C_ADDRESS_BYTE = 307,
            THERM_SENSOR_1_I2C_ADDRESS_START = 0,
            THERM_SENSOR_1_I2C_ADDRESS_LEN = 8,

            // Byte 308: Thermal Sensor 2 I2C Address
            THERM_SENSOR_2_I2C_ADDRESS_BYTE = 308,
            THERM_SENSOR_2_I2C_ADDRESS_START = 0,
            THERM_SENSOR_2_I2C_ADDRESS_LEN = 8,

            // Byte 309: Thermal Sensor 3 I2C Address
            THERM_SENSOR_3_I2C_ADDRESS_BYTE = 309,
            THERM_SENSOR_3_I2C_ADDRESS_START = 0,
            THERM_SENSOR_3_I2C_ADDRESS_LEN = 8,

            // Byte 310: Thermal Sensor Locations
            THERM_SENSOR_LOCATIONS_BYTE = 310,
            THERM_SENSOR_3_LOCATION_START = 0,
            THERM_SENSOR_3_LOCATION_LEN = 2,
            THERM_SENSOR_2_LOCATION_START = 2,
            THERM_SENSOR_2_LOCATION_LEN = 2,
            THERM_SENSOR_1_LOCATION_START = 4,
            THERM_SENSOR_1_LOCATION_LEN = 2,
            THERM_SENSOR_0_LOCATION_START = 6,
            THERM_SENSOR_0_LOCATION_LEN = 2,

            // Byte 311: Differential Buffer Thermal Sensor Profile
            THERM_SENSOR_DIFF_PROFILE_BYTE = 311,
            THERM_SENSOR_DIFF_AVAIL_START = 0,
            THERM_SENSOR_DIFF_AVAIL_LEN = 1,
            THERM_SENSOR_DIFF_TYPE_START = 1,
            THERM_SENSOR_DIFF_TYPE_LEN = 4,
            THERM_SENSOR_DIFF_USAGE_START = 5,
            THERM_SENSOR_DIFF_USAGE_LEN = 3,

            // Byte 312: Differential Buffer Thermal Sensor I2C Address
            THERM_SENSOR_DIFF_I2C_ADDRESS_BYTE = 312,
            THERM_SENSOR_DIFF_I2C_ADDRESS_START = 0,
            THERM_SENSOR_DIFF_I2C_ADDRESS_LEN = 8,

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

        // Byte 193: Module Height
        static constexpr field_t MODULE_BASE_HEIGHT{MODULE_HEIGHT_BYTE, MODULE_BASE_HEIGHT_START, MODULE_BASE_HEIGHT_LEN};
        static constexpr field_t MODULE_HEIGHT_MAX{MODULE_HEIGHT_BYTE, MODULE_HEIGHT_MAX_START, MODULE_HEIGHT_MAX_LEN};

        // Byte 194: Module Maximum Thickness
        static constexpr field_t MAX_THICKNESS_BACK{MODULE_THICKNESS_BYTE, MAX_THICKNESS_BACK_START, MAX_THICKNESS_BACK_LEN};
        static constexpr field_t MAX_THICKNESS_FRONT{MODULE_THICKNESS_BYTE, MAX_THICKNESS_FRONT_START, MAX_THICKNESS_FRONT_LEN};

        // Byte 195: Reference Raw Card used
        static constexpr field_t DESIGN_REV{REF_RAW_CARD_BYTE, DESIGN_REV_START, DESIGN_REV_LEN};
        static constexpr field_t DESIGN_REF_CARD{REF_RAW_CARD_BYTE, DESIGN_REF_CARD_START, DESIGN_REF_CARD_LEN};

        // Byte 196: DIMM attributes
        static constexpr field_t REGISTER_TYPE{DIMM_ATTR_BYTE, DIMM_ATTR_REGISTER_TYPE_START, DIMM_ATTR_REGISTER_TYPE_LEN};
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

        // Byte 201: DIMM Module Organization
        static constexpr field_t NUM_PACKAGE_RANKS_CHAN1{DIMM_ORG_BYTE_BYTE, NUM_PACKAGE_RANKS_CHAN1_START, NUM_PACKAGE_RANKS_CHAN1_LEN};
        static constexpr field_t NUM_PACKAGE_RANKS_CHAN0{DIMM_ORG_BYTE_BYTE, NUM_PACKAGE_RANKS_CHAN0_START, NUM_PACKAGE_RANKS_CHAN0_LEN};
        static constexpr field_t DATA_WIDTH{DIMM_ORG_BYTE_BYTE, SDRAM_DATA_WID_CHAN_START, SDRAM_DATA_WID_CHAN_LEN};

        // Byte 202: Memory Channel Bus Width
        static constexpr field_t ENABLED_PHY_CH{BUS_WIDTH_BYTE, ENABLED_PHY_CHANNELS_START, ENABLED_PHY_CHANNELS_LEN};
        static constexpr field_t BUS_WIDTH_CH_A{BUS_WIDTH_BYTE, BUS_WIDTH_CHANNEL_A_START, BUS_WIDTH_CHANNEL_A_LEN};
        static constexpr field_t BUS_WIDTH_CH_B{BUS_WIDTH_BYTE, BUS_WIDTH_CHANNEL_B_START, BUS_WIDTH_CHANNEL_B_LEN};

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

        // Byte 213: Nibble enables MSB1
        // Reserved

        // Byte 214: REDUNDANT CHIP SELECT MODE
        static constexpr field_t DDIMM_COMPAT{DDIMM_COMPAT_BYTE, DDIMM_REDUNDANT_CS_EN_START, DDIMM_REDUNDANT_CS_EN_LEN};

        // Byte 216: Spare Device Mapping LSB0
        static constexpr field_t SPARE_DEVICE_LSB0{SPARE_DEVICE_LSB0_BYTE, SPARE_DEVICE_LSB0_START, SPARE_DEVICE_LSB0_LEN};

        // Byte 217: Spare Device Mapping MSB0
        static constexpr field_t SPARE_DEVICE_MSB0{SPARE_DEVICE_MSB0_BYTE, SPARE_DEVICE_MSB0_START, SPARE_DEVICE_MSB0_LEN};

        // Byte 218: Spare Device Mapping LSB1
        static constexpr field_t SPARE_DEVICE_LSB1{SPARE_DEVICE_LSB1_BYTE, SPARE_DEVICE_LSB1_START, SPARE_DEVICE_LSB1_LEN};

        // Byte 220: Host Interface Speed to DDR Interface Speed Ratio
        static constexpr field_t HI_DDR_SPEED_RATIO{HI_DDR_SPEED_RATIO_BYTE, HI_DDR_SPEED_RATIO_START, HI_DDR_SPEED_RATIO_LEN};

        // Byte 221: SPD Content Revision
        static constexpr field_t SPD_CONTENT_REVISION{SPD_CONTENT_REVISION_BYTE, SPD_CONTENT_REVISION_START, SPD_CONTENT_REVISION_LEN};

        // Byte 224: Voltage VIN_MTG Edge connector
        static constexpr field_t VIN_MGMT_NOMINAL{VIN_MGMT_BYTE, VIN_MGMT_NOMINAL_START, VIN_MGMT_NOMINAL_LEN};
        static constexpr field_t VIN_MGMT_OPERABLE{VIN_MGMT_BYTE, VIN_MGMT_OPERABLE_START, VIN_MGMT_OPERABLE_LEN};
        static constexpr field_t VIN_MGMT_ENDURANT{VIN_MGMT_BYTE, VIN_MGMT_ENDURANT_START, VIN_MGMT_ENDURANT_LEN};

        // Byte 225: Voltage VIN_BULK Edge Connecto
        static constexpr field_t VIN_BULK_NOMINAL{VIN_BULK_BYTE, VIN_BULK_NOMINAL_START, VIN_BULK_NOMINAL_LEN};
        static constexpr field_t VIN_BULK_OPERABLE{VIN_BULK_BYTE, VIN_BULK_OPERABLE_START, VIN_BULK_OPERABLE_LEN};
        static constexpr field_t VIN_BULK_ENDURANT{VIN_BULK_BYTE, VIN_BULK_ENDURANT_START, VIN_BULK_ENDURANT_LEN};

        // Byte 226: PMIC0 Voltage and Sequence
        static constexpr field_t PMIC0_SUPPLY_VOLTAGE{PMIC0_SEQUENCE_BYTE, PMIC0_SUPPLY_VOLTAGE_START, PMIC0_SUPPLY_VOLTAGE_LEN};
        static constexpr field_t PMIC0_SEQUENCE{PMIC0_SEQUENCE_BYTE, PMIC0_SEQUENCE_START, PMIC0_SEQUENCE_LEN};

        // Byte 227: PMIC1 Voltage and Sequence
        static constexpr field_t PMIC1_SUPPLY_VOLTAGE{PMIC1_SEQUENCE_BYTE, PMIC1_SUPPLY_VOLTAGE_START, PMIC1_SUPPLY_VOLTAGE_LEN};
        static constexpr field_t PMIC1_SEQUENCE{PMIC1_SEQUENCE_BYTE, PMIC1_SEQUENCE_START, PMIC1_SEQUENCE_LEN};

        // Byte 228: PMIC2 Voltage and Sequence
        static constexpr field_t PMIC2_SUPPLY_VOLTAGE{PMIC2_SEQUENCE_BYTE, PMIC2_SUPPLY_VOLTAGE_START, PMIC2_SUPPLY_VOLTAGE_LEN};
        static constexpr field_t PMIC2_SEQUENCE{PMIC2_SEQUENCE_BYTE, PMIC2_SEQUENCE_START, PMIC2_SEQUENCE_LEN};

        // Byte 229: PMIC3 Voltage and Sequence
        static constexpr field_t PMIC3_SUPPLY_VOLTAGE{PMIC3_SEQUENCE_BYTE, PMIC3_SUPPLY_VOLTAGE_START, PMIC3_SUPPLY_VOLTAGE_LEN};
        static constexpr field_t PMIC3_SEQUENCE{PMIC3_SEQUENCE_BYTE, PMIC3_SEQUENCE_START, PMIC3_SEQUENCE_LEN};

        // Byte 230: PMIC0 Manfacture ID code 1st byte
        static constexpr field_t PMIC0_CONT_CODE{PMIC0_MFG_CODE1_BYTE, PMIC0_CONT_CODE_START, PMIC0_CONT_CODE_LEN};

        // Byte 231: PMIC0 Manfacture ID code 2nd byte
        static constexpr field_t PMIC0_LAST_NON_ZERO{PMIC0_MFG_CODE2_BYTE, PMIC0_LAST_NON_ZERO_START, PMIC0_LAST_NON_ZERO_LEN};

        // Byte 232: PMIC0 Revision Number
        static constexpr field_t PMIC0_REV{PMIC0_REV_BYTE, PMIC0_REV_START, PMIC0_REV_LEN};

        // Byte 233: PMIC1 Manfacture ID code 1st byte
        static constexpr field_t PMIC1_CONT_CODE{PMIC1_MFG_CODE1_BYTE, PMIC1_CONT_CODE_START, PMIC1_CONT_CODE_LEN};

        // Byte 234 PMIC1 Manfacture ID code 2nd byte
        static constexpr field_t PMIC1_LAST_NON_ZERO{PMIC1_MFG_CODE2_BYTE, PMIC1_LAST_NON_ZERO_START, PMIC1_LAST_NON_ZERO_LEN};

        // Byte 235: PMIC1 Revision Number
        static constexpr field_t PMIC1_REV{PMIC1_REV_BYTE, PMIC1_REV_START, PMIC1_REV_LEN};

        // Byte 236: PMIC2 Manfacture ID code 1st byte
        static constexpr field_t PMIC2_CONT_CODE{PMIC2_MFG_CODE1_BYTE, PMIC2_CONT_CODE_START, PMIC2_CONT_CODE_LEN};

        // Byte 237 PMIC2 Manfacture ID code 2nd byte
        static constexpr field_t PMIC2_LAST_NON_ZERO{PMIC2_MFG_CODE2_BYTE, PMIC2_LAST_NON_ZERO_START, PMIC2_LAST_NON_ZERO_LEN};

        // Byte 238: PMIC2 Revision Number
        static constexpr field_t PMIC2_REV{PMIC2_REV_BYTE, PMIC2_REV_START, PMIC2_REV_LEN};

        // Byte 239: PMIC3 Manfacture ID code 1st byte
        static constexpr field_t PMIC3_CONT_CODE{PMIC3_MFG_CODE1_BYTE, PMIC3_CONT_CODE_START, PMIC3_CONT_CODE_LEN};

        // Byte 240: PMIC3 Manfacture ID code 2nd byte
        static constexpr field_t PMIC3_LAST_NON_ZERO{PMIC3_MFG_CODE2_BYTE, PMIC3_LAST_NON_ZERO_START, PMIC3_LAST_NON_ZERO_LEN};

        // Byte 241: PMIC3 Revision Number
        static constexpr field_t PMIC3_REV{PMIC3_REV_BYTE, PMIC3_REV_START, PMIC3_REV_LEN};

        // Byte 242: PMIC0 SWA Voltage Setting
        static constexpr field_t PMIC0_SWA_VOLT_SET{PMIC0_SWA_VOLT_SET_BYTE, PMIC0_SWA_VOLT_SET_START, PMIC0_SWA_VOLT_SET_LEN};
        static constexpr field_t PMIC0_SWA_RANGE_SELECT{PMIC0_SWA_VOLT_SET_BYTE, PMIC0_SWA_RANGE_SELECT_START, PMIC0_SWA_RANGE_SELECT_LEN};

        // Byte 243: PMIC0 SWA Voltage Offset
        static constexpr field_t PMIC0_SWA_VOLT_OFF{PMIC0_SWA_VOLT_OFF_BYTE, PMIC0_SWA_VOLT_OFF_START, PMIC0_SWA_VOLT_OFF_LEN};
        static constexpr field_t PMIC0_SWA_OFF_DIRECTION{PMIC0_SWA_VOLT_OFF_BYTE, PMIC0_SWA_OFF_DIRECTION_START, PMIC0_SWA_OFF_DIRECTION_LEN};

        // Byte 244: PMIC0 SWA Delay Sequence Order
        static constexpr field_t PMIC0_SWA_DELAY{PMIC0_SWA_DELAY_BYTE, PMIC0_SWA_DELAY_START, PMIC0_SWA_DELAY_LEN};
        static constexpr field_t PMIC0_SWA_ORDER{PMIC0_SWA_DELAY_BYTE, PMIC0_SWA_ORDER_START, PMIC0_SWA_ORDER_LEN};

        // Byte 245: PMIC0 SWB Voltage Setting
        static constexpr field_t PMIC0_SWB_VOLT_SET{PMIC0_SWB_VOLT_SET_BYTE, PMIC0_SWB_VOLT_SET_START, PMIC0_SWB_VOLT_SET_LEN};
        static constexpr field_t PMIC0_SWB_RANGE_SELECT{PMIC0_SWB_VOLT_SET_BYTE, PMIC0_SWB_RANGE_SELECT_START, PMIC0_SWB_RANGE_SELECT_LEN};

        // Byte 246: PMIC0 SWB Voltage Offset
        static constexpr field_t PMIC0_SWB_VOLT_OFF{PMIC0_SWB_VOLT_OFF_BYTE, PMIC0_SWB_VOLT_OFF_START, PMIC0_SWB_VOLT_OFF_LEN};
        static constexpr field_t PMIC0_SWB_OFF_DIRECTION{PMIC0_SWB_VOLT_OFF_BYTE, PMIC0_SWB_OFF_DIRECTION_START, PMIC0_SWB_OFF_DIRECTION_LEN};

        // Byte 247: PMIC0 SWB Delay Sequence Order
        static constexpr field_t PMIC0_SWB_DELAY{PMIC0_SWB_DELAY_BYTE, PMIC0_SWB_DELAY_START, PMIC0_SWB_DELAY_LEN};
        static constexpr field_t PMIC0_SWB_ORDER{PMIC0_SWB_DELAY_BYTE, PMIC0_SWB_ORDER_START, PMIC0_SWB_ORDER_LEN};

        // Byte 248: PMIC0 SWC Voltage Setting
        static constexpr field_t PMIC0_SWC_VOLT_SET{PMIC0_SWC_VOLT_SET_BYTE, PMIC0_SWC_VOLT_SET_START, PMIC0_SWC_VOLT_SET_LEN};
        static constexpr field_t PMIC0_SWC_RANGE_SELECT{PMIC0_SWC_VOLT_SET_BYTE, PMIC0_SWC_RANGE_SELECT_START, PMIC0_SWC_RANGE_SELECT_LEN};

        // Byte 249: PMIC0 SWC Voltage Offset
        static constexpr field_t PMIC0_SWC_VOLT_OFF{PMIC0_SWC_VOLT_OFF_BYTE, PMIC0_SWC_VOLT_OFF_START, PMIC0_SWC_VOLT_OFF_LEN};
        static constexpr field_t PMIC0_SWC_OFF_DIRECTION{PMIC0_SWC_VOLT_OFF_BYTE, PMIC0_SWC_OFF_DIRECTION_START, PMIC0_SWC_OFF_DIRECTION_LEN};

        // Byte 250: PMIC0 SWC Delay Sequence Order
        static constexpr field_t PMIC0_SWC_DELAY{PMIC0_SWC_DELAY_BYTE, PMIC0_SWC_DELAY_START, PMIC0_SWC_DELAY_LEN};
        static constexpr field_t PMIC0_SWC_ORDER{PMIC0_SWC_DELAY_BYTE, PMIC0_SWC_ORDER_START, PMIC0_SWC_ORDER_LEN};

        // Byte 251: PMIC0 SWD Voltage Setting
        static constexpr field_t PMIC0_SWD_VOLT_SET{PMIC0_SWD_VOLT_SET_BYTE, PMIC0_SWD_VOLT_SET_START, PMIC0_SWD_VOLT_SET_LEN};
        static constexpr field_t PMIC0_SWD_RANGE_SELECT{PMIC0_SWD_VOLT_SET_BYTE, PMIC0_SWD_RANGE_SELECT_START, PMIC0_SWD_RANGE_SELECT_LEN};

        // Byte 252: PMIC0 SWD Voltage Offset
        static constexpr field_t PMIC0_SWD_VOLT_OFF{PMIC0_SWD_VOLT_OFF_BYTE, PMIC0_SWD_VOLT_OFF_START, PMIC0_SWD_VOLT_OFF_LEN};
        static constexpr field_t PMIC0_SWD_OFF_DIRECTION{PMIC0_SWD_VOLT_OFF_BYTE, PMIC0_SWD_OFF_DIRECTION_START, PMIC0_SWD_OFF_DIRECTION_LEN};

        // Byte 253: PMIC0 SWD Delay Sequence Order
        static constexpr field_t PMIC0_SWD_DELAY{PMIC0_SWD_DELAY_BYTE, PMIC0_SWD_DELAY_START, PMIC0_SWD_DELAY_LEN};
        static constexpr field_t PMIC0_SWD_ORDER{PMIC0_SWD_DELAY_BYTE, PMIC0_SWD_ORDER_START, PMIC0_SWD_ORDER_LEN};

        // Byte 254: PMIC0 Phase Combination / Redundancy
        static constexpr field_t PMIC0_PHASE_COMBIN{PMIC0_PHASE_COMBIN_BYTE, PMIC0_PHASE_COMBIN_START, PMIC0_PHASE_COMBIN_LEN};
        static constexpr field_t PMIC0_REDUNDANCY{PMIC0_PHASE_COMBIN_BYTE, PMIC0_REDUNDANCY_START, PMIC0_REDUNDANCY_LEN};

        // Byte 255: PMIC1 SWA Voltage Setting
        static constexpr field_t PMIC1_SWA_VOLT_SET{PMIC1_SWA_VOLT_SET_BYTE, PMIC1_SWA_VOLT_SET_START, PMIC1_SWA_VOLT_SET_LEN};
        static constexpr field_t PMIC1_SWA_RANGE_SELECT{PMIC1_SWA_VOLT_SET_BYTE, PMIC1_SWA_RANGE_SELECT_START, PMIC1_SWA_RANGE_SELECT_LEN};

        // Byte 256: PMIC1 SWA Voltage Offset
        static constexpr field_t PMIC1_SWA_VOLT_OFF{PMIC1_SWA_VOLT_OFF_BYTE, PMIC1_SWA_VOLT_OFF_START, PMIC1_SWA_VOLT_OFF_LEN};
        static constexpr field_t PMIC1_SWA_OFF_DIRECTION{PMIC1_SWA_VOLT_OFF_BYTE, PMIC1_SWA_OFF_DIRECTION_START, PMIC1_SWA_OFF_DIRECTION_LEN};

        // Byte 257: PMIC1 SWA Delay Sequence Order
        static constexpr field_t PMIC1_SWA_DELAY{PMIC1_SWA_DELAY_BYTE, PMIC1_SWA_DELAY_START, PMIC1_SWA_DELAY_LEN};
        static constexpr field_t PMIC1_SWA_ORDER{PMIC1_SWA_DELAY_BYTE, PMIC1_SWA_ORDER_START, PMIC1_SWA_ORDER_LEN};

        // Byte 258: PMIC1 SWB Voltage Setting
        static constexpr field_t PMIC1_SWB_VOLT_SET{PMIC1_SWB_VOLT_SET_BYTE, PMIC1_SWB_VOLT_SET_START, PMIC1_SWB_VOLT_SET_LEN};
        static constexpr field_t PMIC1_SWB_RANGE_SELECT{PMIC1_SWB_VOLT_SET_BYTE, PMIC1_SWB_RANGE_SELECT_START, PMIC1_SWB_RANGE_SELECT_LEN};

        // Byte 259: PMIC1 SWB Voltage Offset
        static constexpr field_t PMIC1_SWB_VOLT_OFF{PMIC1_SWB_VOLT_OFF_BYTE, PMIC1_SWB_VOLT_OFF_START, PMIC1_SWB_VOLT_OFF_LEN};
        static constexpr field_t PMIC1_SWB_OFF_DIRECTION{PMIC1_SWB_VOLT_OFF_BYTE, PMIC1_SWB_OFF_DIRECTION_START, PMIC1_SWB_OFF_DIRECTION_LEN};

        // Byte 260: PMIC1 SWB Delay Sequence Order
        static constexpr field_t PMIC1_SWB_DELAY{PMIC1_SWB_DELAY_BYTE, PMIC1_SWB_DELAY_START, PMIC1_SWB_DELAY_LEN};
        static constexpr field_t PMIC1_SWB_ORDER{PMIC1_SWB_DELAY_BYTE, PMIC1_SWB_ORDER_START, PMIC1_SWB_ORDER_LEN};

        // Byte 261: PMIC1 SWC Voltage Setting
        static constexpr field_t PMIC1_SWC_VOLT_SET{PMIC1_SWC_VOLT_SET_BYTE, PMIC1_SWC_VOLT_SET_START, PMIC1_SWC_VOLT_SET_LEN};
        static constexpr field_t PMIC1_SWC_RANGE_SELECT{PMIC1_SWC_VOLT_SET_BYTE, PMIC1_SWC_RANGE_SELECT_START, PMIC1_SWC_RANGE_SELECT_LEN};

        // Byte 262: PMIC1 SWC Voltage Offset
        static constexpr field_t PMIC1_SWC_VOLT_OFF{PMIC1_SWC_VOLT_OFF_BYTE, PMIC1_SWC_VOLT_OFF_START, PMIC1_SWC_VOLT_OFF_LEN};
        static constexpr field_t PMIC1_SWC_OFF_DIRECTION{PMIC1_SWC_VOLT_OFF_BYTE, PMIC1_SWC_OFF_DIRECTION_START, PMIC1_SWC_OFF_DIRECTION_LEN};

        // Byte 263: PMIC1 SWC Delay Sequence Order
        static constexpr field_t PMIC1_SWC_DELAY{PMIC1_SWC_DELAY_BYTE, PMIC1_SWC_DELAY_START, PMIC1_SWC_DELAY_LEN};
        static constexpr field_t PMIC1_SWC_ORDER{PMIC1_SWC_DELAY_BYTE, PMIC1_SWC_ORDER_START, PMIC1_SWC_ORDER_LEN};

        // Byte 264: PMIC1 SWD Voltage Setting
        static constexpr field_t PMIC1_SWD_VOLT_SET{PMIC1_SWD_VOLT_SET_BYTE, PMIC1_SWD_VOLT_SET_START, PMIC1_SWD_VOLT_SET_LEN};
        static constexpr field_t PMIC1_SWD_RANGE_SELECT{PMIC1_SWD_VOLT_SET_BYTE, PMIC1_SWD_RANGE_SELECT_START, PMIC1_SWD_RANGE_SELECT_LEN};

        // Byte 265: PMIC1 SWD Voltage Offset
        static constexpr field_t PMIC1_SWD_VOLT_OFF{PMIC1_SWD_VOLT_OFF_BYTE, PMIC1_SWD_VOLT_OFF_START, PMIC1_SWD_VOLT_OFF_LEN};
        static constexpr field_t PMIC1_SWD_OFF_DIRECTION{PMIC1_SWD_VOLT_OFF_BYTE, PMIC1_SWD_OFF_DIRECTION_START, PMIC1_SWD_OFF_DIRECTION_LEN};

        // Byte 266: PMIC1 SWD Delay Sequence Order
        static constexpr field_t PMIC1_SWD_DELAY{PMIC1_SWD_DELAY_BYTE, PMIC1_SWD_DELAY_START, PMIC1_SWD_DELAY_LEN};
        static constexpr field_t PMIC1_SWD_ORDER{PMIC1_SWD_DELAY_BYTE, PMIC1_SWD_ORDER_START, PMIC1_SWD_ORDER_LEN};

        // Byte 267: PMIC1 Phase Combination / Redundancy
        static constexpr field_t PMIC1_PHASE_COMBIN{PMIC1_PHASE_COMBIN_BYTE, PMIC1_PHASE_COMBIN_START, PMIC1_PHASE_COMBIN_LEN};
        static constexpr field_t PMIC1_REDUNDANCY{PMIC1_PHASE_COMBIN_BYTE, PMIC1_REDUNDANCY_START, PMIC1_REDUNDANCY_LEN};

        // Byte 268: PMIC2 SWA Voltage Setting
        static constexpr field_t PMIC2_SWA_VOLT_SET{PMIC2_SWA_VOLT_SET_BYTE, PMIC2_SWA_VOLT_SET_START, PMIC2_SWA_VOLT_SET_LEN};
        static constexpr field_t PMIC2_SWA_RANGE_SELECT{PMIC2_SWA_VOLT_SET_BYTE, PMIC2_SWA_RANGE_SELECT_START, PMIC2_SWA_RANGE_SELECT_LEN};

        // Byte 269: PMIC2 SWA Voltage Offset
        static constexpr field_t PMIC2_SWA_VOLT_OFF{PMIC2_SWA_VOLT_OFF_BYTE, PMIC2_SWA_VOLT_OFF_START, PMIC2_SWA_VOLT_OFF_LEN};
        static constexpr field_t PMIC2_SWA_OFF_DIRECTION{PMIC2_SWA_VOLT_OFF_BYTE, PMIC2_SWA_OFF_DIRECTION_START, PMIC2_SWA_OFF_DIRECTION_LEN};

        // Byte 270: PMIC2 SWA Delay Sequence Order
        static constexpr field_t PMIC2_SWA_DELAY{PMIC2_SWA_DELAY_BYTE, PMIC2_SWA_DELAY_START, PMIC2_SWA_DELAY_LEN};
        static constexpr field_t PMIC2_SWA_ORDER{PMIC2_SWA_DELAY_BYTE, PMIC2_SWA_ORDER_START, PMIC2_SWA_ORDER_LEN};

        // Byte 271: PMIC2 SWB Voltage Setting
        static constexpr field_t PMIC2_SWB_VOLT_SET{PMIC2_SWB_VOLT_SET_BYTE, PMIC2_SWB_VOLT_SET_START, PMIC2_SWB_VOLT_SET_LEN};
        static constexpr field_t PMIC2_SWB_RANGE_SELECT{PMIC2_SWB_VOLT_SET_BYTE, PMIC2_SWB_RANGE_SELECT_START, PMIC2_SWB_RANGE_SELECT_LEN};

        // Byte 272: PMIC2 SWB Voltage Offset
        static constexpr field_t PMIC2_SWB_VOLT_OFF{PMIC2_SWB_VOLT_OFF_BYTE, PMIC2_SWB_VOLT_OFF_START, PMIC2_SWB_VOLT_OFF_LEN};
        static constexpr field_t PMIC2_SWB_OFF_DIRECTION{PMIC2_SWB_VOLT_OFF_BYTE, PMIC2_SWB_OFF_DIRECTION_START, PMIC2_SWB_OFF_DIRECTION_LEN};

        // Byte 273: PMIC2 SWB Delay Sequence Order
        static constexpr field_t PMIC2_SWB_DELAY{PMIC2_SWB_DELAY_BYTE, PMIC2_SWB_DELAY_START, PMIC2_SWB_DELAY_LEN};
        static constexpr field_t PMIC2_SWB_ORDER{PMIC2_SWB_DELAY_BYTE, PMIC2_SWB_ORDER_START, PMIC2_SWB_ORDER_LEN};

        // Byte 274: PMIC2 SWC Voltage Setting
        static constexpr field_t PMIC2_SWC_VOLT_SET{PMIC2_SWC_VOLT_SET_BYTE, PMIC2_SWC_VOLT_SET_START, PMIC2_SWC_VOLT_SET_LEN};
        static constexpr field_t PMIC2_SWC_RANGE_SELECT{PMIC2_SWC_VOLT_SET_BYTE, PMIC2_SWC_RANGE_SELECT_START, PMIC2_SWC_RANGE_SELECT_LEN};

        // Byte 275: PMIC2 SWC Voltage Offset
        static constexpr field_t PMIC2_SWC_VOLT_OFF{PMIC2_SWC_VOLT_OFF_BYTE, PMIC2_SWC_VOLT_OFF_START, PMIC2_SWC_VOLT_OFF_LEN};
        static constexpr field_t PMIC2_SWC_OFF_DIRECTION{PMIC2_SWC_VOLT_OFF_BYTE, PMIC2_SWC_OFF_DIRECTION_START, PMIC2_SWC_OFF_DIRECTION_LEN};

        // Byte 276: PMIC2 SWC Delay Sequence Order
        static constexpr field_t PMIC2_SWC_DELAY{PMIC2_SWC_DELAY_BYTE, PMIC2_SWC_DELAY_START, PMIC2_SWC_DELAY_LEN};
        static constexpr field_t PMIC2_SWC_ORDER{PMIC2_SWC_DELAY_BYTE, PMIC2_SWC_ORDER_START, PMIC2_SWC_ORDER_LEN};

        // Byte 277: PMIC2 SWD Voltage Setting
        static constexpr field_t PMIC2_SWD_VOLT_SET{PMIC2_SWD_VOLT_SET_BYTE, PMIC2_SWD_VOLT_SET_START, PMIC2_SWD_VOLT_SET_LEN};
        static constexpr field_t PMIC2_SWD_RANGE_SELECT{PMIC2_SWD_VOLT_SET_BYTE, PMIC2_SWD_RANGE_SELECT_START, PMIC2_SWD_RANGE_SELECT_LEN};

        // Byte 278: PMIC2 SWD Voltage Offset
        static constexpr field_t PMIC2_SWD_VOLT_OFF{PMIC2_SWD_VOLT_OFF_BYTE, PMIC2_SWD_VOLT_OFF_START, PMIC2_SWD_VOLT_OFF_LEN};
        static constexpr field_t PMIC2_SWD_OFF_DIRECTION{PMIC2_SWD_VOLT_OFF_BYTE, PMIC2_SWD_OFF_DIRECTION_START, PMIC2_SWD_OFF_DIRECTION_LEN};

        // Byte 279: PMIC2 SWD Delay Sequence Order
        static constexpr field_t PMIC2_SWD_DELAY{PMIC2_SWD_DELAY_BYTE, PMIC2_SWD_DELAY_START, PMIC2_SWD_DELAY_LEN};
        static constexpr field_t PMIC2_SWD_ORDER{PMIC2_SWD_DELAY_BYTE, PMIC2_SWD_ORDER_START, PMIC2_SWD_ORDER_LEN};

        // Byte 280: PMIC2 Phase Combination / Redundancy
        static constexpr field_t PMIC2_PHASE_COMBIN{PMIC2_PHASE_COMBIN_BYTE, PMIC2_PHASE_COMBIN_START, PMIC2_PHASE_COMBIN_LEN};
        static constexpr field_t PMIC2_REDUNDANCY{PMIC2_PHASE_COMBIN_BYTE, PMIC2_REDUNDANCY_START, PMIC2_REDUNDANCY_LEN};

        // Byte 281: PMIC3 SWA Voltage Setting
        static constexpr field_t PMIC3_SWA_VOLT_SET{PMIC3_SWA_VOLT_SET_BYTE, PMIC3_SWA_VOLT_SET_START, PMIC3_SWA_VOLT_SET_LEN};
        static constexpr field_t PMIC3_SWA_RANGE_SELECT{PMIC3_SWA_VOLT_SET_BYTE, PMIC3_SWA_RANGE_SELECT_START, PMIC3_SWA_RANGE_SELECT_LEN};

        // Byte 282: PMIC3 SWA Voltage Offset
        static constexpr field_t PMIC3_SWA_VOLT_OFF{PMIC3_SWA_VOLT_OFF_BYTE, PMIC3_SWA_VOLT_OFF_START, PMIC3_SWA_VOLT_OFF_LEN};
        static constexpr field_t PMIC3_SWA_OFF_DIRECTION{PMIC3_SWA_VOLT_OFF_BYTE, PMIC3_SWA_OFF_DIRECTION_START, PMIC3_SWA_OFF_DIRECTION_LEN};

        // Byte 283: PMIC3 SWA Delay Sequence Order
        static constexpr field_t PMIC3_SWA_DELAY{PMIC3_SWA_DELAY_BYTE, PMIC3_SWA_DELAY_START, PMIC3_SWA_DELAY_LEN};
        static constexpr field_t PMIC3_SWA_ORDER{PMIC3_SWA_DELAY_BYTE, PMIC3_SWA_ORDER_START, PMIC3_SWA_ORDER_LEN};

        // Byte 284: PMIC3 SWB Voltage Setting
        static constexpr field_t PMIC3_SWB_VOLT_SET{PMIC3_SWB_VOLT_SET_BYTE, PMIC3_SWB_VOLT_SET_START, PMIC3_SWB_VOLT_SET_LEN};
        static constexpr field_t PMIC3_SWB_RANGE_SELECT{PMIC3_SWB_VOLT_SET_BYTE, PMIC3_SWB_RANGE_SELECT_START, PMIC3_SWB_RANGE_SELECT_LEN};

        // Byte 285: PMIC3 SWB Voltage Offset
        static constexpr field_t PMIC3_SWB_VOLT_OFF{PMIC3_SWB_VOLT_OFF_BYTE, PMIC3_SWB_VOLT_OFF_START, PMIC3_SWB_VOLT_OFF_LEN};
        static constexpr field_t PMIC3_SWB_OFF_DIRECTION{PMIC3_SWB_VOLT_OFF_BYTE, PMIC3_SWB_OFF_DIRECTION_START, PMIC3_SWB_OFF_DIRECTION_LEN};

        // Byte 286: PMIC3 SWB Delay Sequence Order
        static constexpr field_t PMIC3_SWB_DELAY{PMIC3_SWB_DELAY_BYTE, PMIC3_SWB_DELAY_START, PMIC3_SWB_DELAY_LEN};
        static constexpr field_t PMIC3_SWB_ORDER{PMIC3_SWB_DELAY_BYTE, PMIC3_SWB_ORDER_START, PMIC3_SWB_ORDER_LEN};

        // Byte 287: PMIC3 SWC Voltage Setting
        static constexpr field_t PMIC3_SWC_VOLT_SET{PMIC3_SWC_VOLT_SET_BYTE, PMIC3_SWC_VOLT_SET_START, PMIC3_SWC_VOLT_SET_LEN};
        static constexpr field_t PMIC3_SWC_RANGE_SELECT{PMIC3_SWC_VOLT_SET_BYTE, PMIC3_SWC_RANGE_SELECT_START, PMIC3_SWC_RANGE_SELECT_LEN};

        // Byte 288: PMIC3 SWC Voltage Offset
        static constexpr field_t PMIC3_SWC_VOLT_OFF{PMIC3_SWC_VOLT_OFF_BYTE, PMIC3_SWC_VOLT_OFF_START, PMIC3_SWC_VOLT_OFF_LEN};
        static constexpr field_t PMIC3_SWC_OFF_DIRECTION{PMIC3_SWC_VOLT_OFF_BYTE, PMIC3_SWC_OFF_DIRECTION_START, PMIC3_SWC_OFF_DIRECTION_LEN};

        // Byte 289: PMIC3 SWC Delay Sequence Order
        static constexpr field_t PMIC3_SWC_DELAY{PMIC3_SWC_DELAY_BYTE, PMIC3_SWC_DELAY_START, PMIC3_SWC_DELAY_LEN};
        static constexpr field_t PMIC3_SWC_ORDER{PMIC3_SWC_DELAY_BYTE, PMIC3_SWC_ORDER_START, PMIC3_SWC_ORDER_LEN};

        // Byte 290: PMIC3 SWD Voltage Setting
        static constexpr field_t PMIC3_SWD_VOLT_SET{PMIC3_SWD_VOLT_SET_BYTE, PMIC3_SWD_VOLT_SET_START, PMIC3_SWD_VOLT_SET_LEN};
        static constexpr field_t PMIC3_SWD_RANGE_SELECT{PMIC3_SWD_VOLT_SET_BYTE, PMIC3_SWD_RANGE_SELECT_START, PMIC3_SWD_RANGE_SELECT_LEN};

        // Byte 291: PMIC3 SWD Voltage Offset
        static constexpr field_t PMIC3_SWD_VOLT_OFF{PMIC3_SWD_VOLT_OFF_BYTE, PMIC3_SWD_VOLT_OFF_START, PMIC3_SWD_VOLT_OFF_LEN};
        static constexpr field_t PMIC3_SWD_OFF_DIRECTION{PMIC3_SWD_VOLT_OFF_BYTE, PMIC3_SWD_OFF_DIRECTION_START, PMIC3_SWD_OFF_DIRECTION_LEN};

        // Byte 292: PMIC3 SWD Delay Sequence Order
        static constexpr field_t PMIC3_SWD_DELAY{PMIC3_SWD_DELAY_BYTE, PMIC3_SWD_DELAY_START, PMIC3_SWD_DELAY_LEN};
        static constexpr field_t PMIC3_SWD_ORDER{PMIC3_SWD_DELAY_BYTE, PMIC3_SWD_ORDER_START, PMIC3_SWD_ORDER_LEN};

        // Byte 293: PMIC3 Phase Combination / Redundancy
        static constexpr field_t PMIC3_PHASE_COMBIN{PMIC3_PHASE_COMBIN_BYTE, PMIC3_PHASE_COMBIN_START, PMIC3_PHASE_COMBIN_LEN};
        static constexpr field_t PMIC3_REDUNDANCY{PMIC3_PHASE_COMBIN_BYTE, PMIC3_REDUNDANCY_START, PMIC3_REDUNDANCY_LEN};

        // Byte 294: PMIC0 IIC Address
        static constexpr field_t PMIC0_IIC_ADDRESS{PMIC0_IIC_ADDRESS_BYTE, PMIC0_IIC_ADDRESS_START, PMIC0_IIC_ADDRESS_LEN};

        // Byte 295: PMIC1 IIC Address
        static constexpr field_t PMIC1_IIC_ADDRESS{PMIC1_IIC_ADDRESS_BYTE, PMIC1_IIC_ADDRESS_START, PMIC1_IIC_ADDRESS_LEN};

        // Byte 296: PMIC2 IIC Address
        static constexpr field_t PMIC2_IIC_ADDRESS{PMIC2_IIC_ADDRESS_BYTE, PMIC2_IIC_ADDRESS_START, PMIC2_IIC_ADDRESS_LEN};

        // Byte 297: PMIC3 IIC Address
        static constexpr field_t PMIC3_IIC_ADDRESS{PMIC3_IIC_ADDRESS_BYTE, PMIC3_IIC_ADDRESS_START, PMIC3_IIC_ADDRESS_LEN};

        // Byte 298: Registered Clock Drivers (RCD)
        static constexpr field_t MODULE_RCD_MEDIA_CONTROLLER_TYPE{MODULE_RCD_BYTE, MODULE_RCD_MEDIA_CONTROLLER_TYPE_START, MODULE_RCD_MEDIA_CONTROLLER_TYPE_LEN};
        static constexpr field_t MODULE_RCD_MEDIA_JEDEC_COMPLIANT{MODULE_RCD_BYTE, MODULE_RCD_JEDEC_COMPLIANT_START, MODULE_RCD_JEDEC_COMPLIANT_LEN};
        static constexpr field_t MODULE_RCD{MODULE_RCD_BYTE, MODULE_RCD_START, MODULE_RCD_LEN};

        // Byte 299 and 300: RCD MFG ID
        static constexpr field_t RCD_MFG_ID_LSB{RCD_MFG_ID_LSB_BYTE, RCD_MFG_ID_START, RCD_MFG_ID_LEN};
        static constexpr field_t RCD_MFG_ID_MSB{RCD_MFG_ID_MSB_BYTE, RCD_MFG_ID_START, RCD_MFG_ID_LEN};

        // Byte 302: Thermal Sensor 0 Profile
        static constexpr field_t THERM_SENSOR_0_AVAIL{THERM_SENSOR_0_PROFILE_BYTE, THERM_SENSOR_0_AVAIL_START, THERM_SENSOR_0_AVAIL_LEN};
        static constexpr field_t THERM_SENSOR_0_USAGE{THERM_SENSOR_0_PROFILE_BYTE, THERM_SENSOR_0_USAGE_START, THERM_SENSOR_0_USAGE_LEN};
        static constexpr field_t THERM_SENSOR_0_TYPE{THERM_SENSOR_0_PROFILE_BYTE, THERM_SENSOR_0_TYPE_START, THERM_SENSOR_0_TYPE_LEN};

        // Byte 303: Thermal Sensor 1 Profile
        static constexpr field_t THERM_SENSOR_1_AVAIL{THERM_SENSOR_1_PROFILE_BYTE, THERM_SENSOR_1_AVAIL_START, THERM_SENSOR_1_AVAIL_LEN};
        static constexpr field_t THERM_SENSOR_1_USAGE{THERM_SENSOR_1_PROFILE_BYTE, THERM_SENSOR_1_USAGE_START, THERM_SENSOR_1_USAGE_LEN};
        static constexpr field_t THERM_SENSOR_1_TYPE{THERM_SENSOR_1_PROFILE_BYTE, THERM_SENSOR_1_TYPE_START, THERM_SENSOR_1_TYPE_LEN};

        // Byte 304: Thermal Sensor 2 Profile
        static constexpr field_t THERM_SENSOR_2_AVAIL{THERM_SENSOR_2_PROFILE_BYTE, THERM_SENSOR_2_AVAIL_START, THERM_SENSOR_2_AVAIL_LEN};
        static constexpr field_t THERM_SENSOR_2_USAGE{THERM_SENSOR_2_PROFILE_BYTE, THERM_SENSOR_2_USAGE_START, THERM_SENSOR_2_USAGE_LEN};
        static constexpr field_t THERM_SENSOR_2_TYPE{THERM_SENSOR_2_PROFILE_BYTE, THERM_SENSOR_2_TYPE_START, THERM_SENSOR_2_TYPE_LEN};

        // Byte 305: Thermal Sensor 3 Profile
        static constexpr field_t THERM_SENSOR_3_AVAIL{THERM_SENSOR_3_PROFILE_BYTE, THERM_SENSOR_3_AVAIL_START, THERM_SENSOR_3_AVAIL_LEN};
        static constexpr field_t THERM_SENSOR_3_USAGE{THERM_SENSOR_3_PROFILE_BYTE, THERM_SENSOR_3_USAGE_START, THERM_SENSOR_3_USAGE_LEN};
        static constexpr field_t THERM_SENSOR_3_TYPE{THERM_SENSOR_3_PROFILE_BYTE, THERM_SENSOR_3_TYPE_START, THERM_SENSOR_3_TYPE_LEN};

        // Byte 306: Thermal Sensor 0 I2C Address
        static constexpr field_t THERM_SENSOR_0_I2C_ADDRESS{THERM_SENSOR_0_I2C_ADDRESS_BYTE, THERM_SENSOR_0_I2C_ADDRESS_START, THERM_SENSOR_0_I2C_ADDRESS_LEN};

        // Byte 307: Thermal Sensor 1 I2C Address
        static constexpr field_t THERM_SENSOR_1_I2C_ADDRESS{THERM_SENSOR_1_I2C_ADDRESS_BYTE, THERM_SENSOR_1_I2C_ADDRESS_START, THERM_SENSOR_1_I2C_ADDRESS_LEN};

        // Byte 308: Thermal Sensor 2 I2C Address
        static constexpr field_t THERM_SENSOR_2_I2C_ADDRESS{THERM_SENSOR_2_I2C_ADDRESS_BYTE, THERM_SENSOR_2_I2C_ADDRESS_START, THERM_SENSOR_2_I2C_ADDRESS_LEN};

        // Byte 309: Thermal Sensor 3 I2C Address
        static constexpr field_t THERM_SENSOR_3_I2C_ADDRESS{THERM_SENSOR_3_I2C_ADDRESS_BYTE, THERM_SENSOR_3_I2C_ADDRESS_START, THERM_SENSOR_3_I2C_ADDRESS_LEN};

        // Byte 310: Thermal Sensor Locations
        static constexpr field_t THERM_SENSOR_3_LOCATION{THERM_SENSOR_LOCATIONS_BYTE, THERM_SENSOR_3_LOCATION_START, THERM_SENSOR_3_LOCATION_LEN};
        static constexpr field_t THERM_SENSOR_2_LOCATION{THERM_SENSOR_LOCATIONS_BYTE, THERM_SENSOR_2_LOCATION_START, THERM_SENSOR_2_LOCATION_LEN};
        static constexpr field_t THERM_SENSOR_1_LOCATION{THERM_SENSOR_LOCATIONS_BYTE, THERM_SENSOR_1_LOCATION_START, THERM_SENSOR_1_LOCATION_LEN};
        static constexpr field_t THERM_SENSOR_0_LOCATION{THERM_SENSOR_LOCATIONS_BYTE, THERM_SENSOR_0_LOCATION_START, THERM_SENSOR_0_LOCATION_LEN};

        // Byte 311: Differential Sensor Profile
        static constexpr field_t THERM_SENSOR_DIFF_AVAIL{THERM_SENSOR_DIFF_PROFILE_BYTE, THERM_SENSOR_DIFF_AVAIL_START, THERM_SENSOR_DIFF_AVAIL_LEN};
        static constexpr field_t THERM_SENSOR_DIFF_USAGE{THERM_SENSOR_DIFF_PROFILE_BYTE, THERM_SENSOR_DIFF_USAGE_START, THERM_SENSOR_DIFF_USAGE_LEN};
        static constexpr field_t THERM_SENSOR_DIFF_TYPE{THERM_SENSOR_DIFF_PROFILE_BYTE, THERM_SENSOR_DIFF_TYPE_START, THERM_SENSOR_DIFF_TYPE_LEN};

        // Byte 312: Differential Sensor I2C Address
        static constexpr field_t THERM_SENSOR_DIFF_I2C_ADDRESS{THERM_SENSOR_DIFF_I2C_ADDRESS_BYTE, THERM_SENSOR_DIFF_I2C_ADDRESS_START, THERM_SENSOR_DIFF_I2C_ADDRESS_LEN};

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
