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
            NUM_PACKAGE_RANKS_CHAN1_START = 0,
            NUM_PACKAGE_RANKS_CHAN1_LEN = 3,
            NUM_PACKAGE_RANKS_CHAN0_START = 3,
            NUM_PACKAGE_RANKS_CHAN0_LEN = 3,
            SDRAM_DATA_WID_CHAN_START = 6,
            SDRAM_DATA_WID_CHAN_LEN = 2,


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
            DDIMM_COMPAT_START = 3,
            DDIMM_COMPAT_LEN = 5,

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

            // Byte 221: SPD Content Revision
            SPD_CONTENT_REVISION_BYTE = 221,
            SPD_CONTENT_REVISION_START = 0,
            SPD_CONTENT_REVISION_LEN = 8,

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
            PMIC0_SEQUENCE_START = 5,
            PMIC0_SEQUENCE_LEN = 3,

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
            PMIC1_SEQUENCE_START = 5,
            PMIC1_SEQUENCE_LEN = 3,

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

            // Byte 265-266: RCD MFG ID Code
            RCD_MFG_ID_LSB_BYTE = 265,
            RCD_MFG_ID_MSB_BYTE = 266,
            RCD_MFG_ID_START = 0,
            RCD_MFG_ID_LEN = 8,

            // Byte 268: Thermal Sensor 0 Profile
            THERM_SENSOR_0_PROFILE_BYTE = 268,
            THERM_SENSOR_0_AVAIL_START = 0,
            THERM_SENSOR_0_AVAIL_LEN = 1,
            THERM_SENSOR_0_SECOND_AVAIL_START = 1,
            THERM_SENSOR_0_SECOND_AVAIL_LEN = 1,
            THERM_SENSOR_0_TYPE_START = 2,
            THERM_SENSOR_0_TYPE_LEN = 3,
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
            THERM_SENSOR_1_SECOND_AVAIL_START = 1,
            THERM_SENSOR_1_SECOND_AVAIL_LEN = 1,
            THERM_SENSOR_1_TYPE_START = 2,
            THERM_SENSOR_1_TYPE_LEN = 3,
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

            // Byte 274: Secondary Thermal Sensor 0 I2C Address
            THERM_SENSOR_0_SECOND_I2C_ADDRESS_BYTE = 274,
            THERM_SENSOR_0_SECOND_I2C_ADDRESS_START = 0,
            THERM_SENSOR_0_SECOND_I2C_ADDRESS_LEN = 8,

            // Byte 275: Secondary Thermal Sensor 1 I2C Address
            THERM_SENSOR_1_SECOND_I2C_ADDRESS_BYTE = 275,
            THERM_SENSOR_1_SECOND_I2C_ADDRESS_START = 0,
            THERM_SENSOR_1_SECOND_I2C_ADDRESS_LEN = 8,

            // Byte 276: Thermal Sensor Locations
            THERM_SENSOR_LOCATIONS_BYTE = 276,
            THERM_SENSOR_1_SECOND_LOCATION_START = 0,
            THERM_SENSOR_1_SECOND_LOCATION_LEN = 2,
            THERM_SENSOR_0_SECOND_LOCATION_START = 2,
            THERM_SENSOR_0_SECOND_LOCATION_LEN = 2,
            THERM_SENSOR_1_LOCATION_START = 4,
            THERM_SENSOR_1_LOCATION_LEN = 2,
            THERM_SENSOR_0_LOCATION_START = 6,
            THERM_SENSOR_0_LOCATION_LEN = 2,

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
        static constexpr field_t NUM_PACKAGE_RANKS_CHAN1{DIMM_ORG_BYTE_BYTE, NUM_PACKAGE_RANKS_CHAN1_START, NUM_PACKAGE_RANKS_CHAN1_LEN};
        static constexpr field_t NUM_PACKAGE_RANKS_CHAN0{DIMM_ORG_BYTE_BYTE, NUM_PACKAGE_RANKS_CHAN0_START, NUM_PACKAGE_RANKS_CHAN0_LEN};
        static constexpr field_t DATA_WIDTH{DIMM_ORG_BYTE_BYTE, SDRAM_DATA_WID_CHAN_START, SDRAM_DATA_WID_CHAN_LEN};

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

        // Byte 265 and 266: RCD MFG ID
        static constexpr field_t RCD_MFG_ID_LSB{RCD_MFG_ID_LSB_BYTE, RCD_MFG_ID_START, RCD_MFG_ID_LEN};
        static constexpr field_t RCD_MFG_ID_MSB{RCD_MFG_ID_MSB_BYTE, RCD_MFG_ID_START, RCD_MFG_ID_LEN};

        // Byte 268: Thermal Sensor 0 Profile
        static constexpr field_t THERM_SENSOR_0_AVAIL{THERM_SENSOR_0_PROFILE_BYTE, THERM_SENSOR_0_AVAIL_START, THERM_SENSOR_0_AVAIL_LEN};
        static constexpr field_t THERM_SENSOR_0_SECOND_AVAIL{THERM_SENSOR_0_PROFILE_BYTE, THERM_SENSOR_0_SECOND_AVAIL_START, THERM_SENSOR_0_SECOND_AVAIL_LEN};
        static constexpr field_t THERM_SENSOR_0_USAGE{THERM_SENSOR_0_PROFILE_BYTE, THERM_SENSOR_0_USAGE_START, THERM_SENSOR_0_USAGE_LEN};
        static constexpr field_t THERM_SENSOR_0_TYPE{THERM_SENSOR_0_PROFILE_BYTE, THERM_SENSOR_0_TYPE_START, THERM_SENSOR_0_TYPE_LEN};

        // Byte 269: Thermal Sensor 0 I2C Address
        static constexpr field_t THERM_SENSOR_0_I2C_ADDRESS{THERM_SENSOR_0_I2C_ADDRESS_BYTE, THERM_SENSOR_0_I2C_ADDRESS_START, THERM_SENSOR_0_I2C_ADDRESS_LEN};

        // Byte 271: Thermal Sensor 1 Profile
        static constexpr field_t THERM_SENSOR_1_AVAIL{THERM_SENSOR_1_PROFILE_BYTE, THERM_SENSOR_1_AVAIL_START, THERM_SENSOR_1_AVAIL_LEN};
        static constexpr field_t THERM_SENSOR_1_SECOND_AVAIL{THERM_SENSOR_1_PROFILE_BYTE, THERM_SENSOR_1_SECOND_AVAIL_START, THERM_SENSOR_1_SECOND_AVAIL_LEN};
        static constexpr field_t THERM_SENSOR_1_USAGE{THERM_SENSOR_1_PROFILE_BYTE, THERM_SENSOR_1_USAGE_START, THERM_SENSOR_1_USAGE_LEN};
        static constexpr field_t THERM_SENSOR_1_TYPE{THERM_SENSOR_1_PROFILE_BYTE, THERM_SENSOR_1_TYPE_START, THERM_SENSOR_1_TYPE_LEN};

        // Byte 271: Thermal Sensor 1 I2C Address
        static constexpr field_t THERM_SENSOR_1_I2C_ADDRESS{THERM_SENSOR_1_I2C_ADDRESS_BYTE, THERM_SENSOR_1_I2C_ADDRESS_START, THERM_SENSOR_1_I2C_ADDRESS_LEN};

        // Byte 272: Differential Sensor Profile
        static constexpr field_t THERM_SENSOR_DIFF_AVAIL{THERM_SENSOR_DIFF_PROFILE_BYTE, THERM_SENSOR_DIFF_AVAIL_START, THERM_SENSOR_DIFF_AVAIL_LEN};
        static constexpr field_t THERM_SENSOR_DIFF_USAGE{THERM_SENSOR_DIFF_PROFILE_BYTE, THERM_SENSOR_DIFF_USAGE_START, THERM_SENSOR_DIFF_USAGE_LEN};
        static constexpr field_t THERM_SENSOR_DIFF_TYPE{THERM_SENSOR_DIFF_PROFILE_BYTE, THERM_SENSOR_DIFF_TYPE_START, THERM_SENSOR_DIFF_TYPE_LEN};

        // Byte 273: Differential Sensor I2C Address
        static constexpr field_t THERM_SENSOR_DIFF_I2C_ADDRESS{THERM_SENSOR_DIFF_I2C_ADDRESS_BYTE, THERM_SENSOR_DIFF_I2C_ADDRESS_START, THERM_SENSOR_DIFF_I2C_ADDRESS_LEN};

        // Byte 274: Secondary Thermal Sensor 0 I2C Address
        static constexpr field_t THERM_SENSOR_0_SECOND_I2C_ADDRESS{THERM_SENSOR_0_SECOND_I2C_ADDRESS_BYTE, THERM_SENSOR_0_SECOND_I2C_ADDRESS_START, THERM_SENSOR_0_SECOND_I2C_ADDRESS_LEN};

        // Byte 275: Secondary Thermal Sensor 1 I2C Address
        static constexpr field_t THERM_SENSOR_1_SECOND_I2C_ADDRESS{THERM_SENSOR_1_SECOND_I2C_ADDRESS_BYTE, THERM_SENSOR_1_SECOND_I2C_ADDRESS_START, THERM_SENSOR_1_SECOND_I2C_ADDRESS_LEN};

        // Byte 276: Thermal Sensor Locations
        static constexpr field_t THERM_SENSOR_1_SECOND_LOCATION{THERM_SENSOR_LOCATIONS_BYTE, THERM_SENSOR_1_SECOND_LOCATION_START, THERM_SENSOR_1_SECOND_LOCATION_LEN};
        static constexpr field_t THERM_SENSOR_0_SECOND_LOCATION{THERM_SENSOR_LOCATIONS_BYTE, THERM_SENSOR_0_SECOND_LOCATION_START, THERM_SENSOR_0_SECOND_LOCATION_LEN};
        static constexpr field_t THERM_SENSOR_1_LOCATION{THERM_SENSOR_LOCATIONS_BYTE, THERM_SENSOR_1_LOCATION_START, THERM_SENSOR_1_LOCATION_LEN};
        static constexpr field_t THERM_SENSOR_0_LOCATION{THERM_SENSOR_LOCATIONS_BYTE, THERM_SENSOR_0_LOCATION_START, THERM_SENSOR_0_LOCATION_LEN};

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
