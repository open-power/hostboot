/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/ddimm/ddr4/efd_fields_ddr4.H $ */
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
/// @file efd_fields_ddr4.H
/// @brief DDIMM Extended Functional Data (EFD) common fields
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _EFD_FIELDS_DDR4_H_
#define _EFD_FIELDS_DDR4_H_


#include <cstdint>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/mss_field.H>

namespace mss
{

namespace efd
{

///
/// @class Fields class - specialization for DDR4 custom_microchip_fields
/// @tparam D device type (DDR4, etc.)
/// @tparam E EFD type (ie custom EFD type 1)
///
template<mss::spd::device_type D, mss::efd::id E>
class fields;

///
/// @class Fields class - specialization for DDR4 custom_microchip_fields
/// @note Stores all field information for the custom microchip DDR4 DDIMM
///
template<>
class fields<mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>
{
    private:

        enum
        {

            // Byte 0: Host Speed Supported
            HOST_SPEED_SUPPORTED_BYTE = 0,
            HOST_SPEED_SUPPORTED_START = 1,
            HOST_SPEED_SUPPORTED_LEN = 7,

            // Byte 2: Master Ranks Supported
            MASTER_RANKS_SUPPORTED_BYTE = 2,
            MASTER_RANKS_SUPPORTED_START = 4,
            MASTER_RANKS_SUPPORTED_LEN = 4,

            // Byte 3: Channels supported byte0
            CHANNELS_SUPPORTED_BYTE0_BYTE = 3,
            CHANNELS_SUPPORTED_BYTE0_START = 0,
            CHANNELS_SUPPORTED_BYTE0_LEN = 8,

            // Byte 4: Channels supported byte1
            CHANNELS_SUPPORTED_BYTE1_BYTE = 4,
            CHANNELS_SUPPORTED_BYTE1_START = 0,
            CHANNELS_SUPPORTED_BYTE1_LEN = 8,

            // Byte 5: Channels supported byte2
            CHANNELS_SUPPORTED_BYTE2_BYTE = 5,
            CHANNELS_SUPPORTED_BYTE2_START = 0,
            CHANNELS_SUPPORTED_BYTE2_LEN = 8,

            // Byte 6: Channels supported byte3
            CHANNELS_SUPPORTED_BYTE3_BYTE = 6,
            CHANNELS_SUPPORTED_BYTE3_START = 0,
            CHANNELS_SUPPORTED_BYTE3_LEN = 8,

            // Byte 7: DIMMs supported
            DIMMS_SUPPORTED_BYTE = 7,
            DIMMS_SUPPORTED_START = 6,
            DIMMS_SUPPORTED_LEN = 2,

            // Byte 16: PHY ODT impedance
            PHY_ODT_IMPEDANCE_BYTE = 16,
            PHY_ODT_IMPEDANCE_START = 3,
            PHY_ODT_IMPEDANCE_LEN = 5,

            // Byte 17: PHY Drive impedance pull up
            PHY_DRIVE_IMPEDANCE_PULL_UP_BYTE = 17,
            PHY_DRIVE_IMPEDANCE_PULL_UP_START = 2,
            PHY_DRIVE_IMPEDANCE_PULL_UP_LEN = 6,

            // Byte 18: PHY Drive impedance pull down
            PHY_DRIVE_IMPEDANCE_PULL_DOWN_BYTE = 18,
            PHY_DRIVE_IMPEDANCE_PULL_DOWN_START = 2,
            PHY_DRIVE_IMPEDANCE_PULL_DOWN_LEN = 6,

            // Byte 19: PHY Drive Impedance
            PHY_DRIVE_IMPEDANCE_BYTE = 19,
            PHY_DRIVE_IMPEDANCE_START = 0,
            PHY_DRIVE_IMPEDANCE_LEN = 8,

            // Byte 20: PHY Slew Rate DQ_DQS
            PHY_SLEW_RATE_DQ_DQS_BYTE = 20,
            PHY_SLEW_RATE_DQ_DQS_START = 0,
            PHY_SLEW_RATE_DQ_DQS_LEN = 8,

            // Byte 21: ATX impedance
            ATX_IMPEDANCE_BYTE = 21,
            ATX_IMPEDANCE_START = 4,
            ATX_IMPEDANCE_LEN = 4,

            // Byte 22: ATX Slew rate
            ATX_SLEW_RATE_BYTE = 22,
            ATX_SLEW_RATE_START = 0,
            ATX_SLEW_RATE_LEN = 8,

            // Byte 23: CK Impedance
            CK_IMPEDANCE_BYTE = 23,
            CK_IMPEDANCE_START = 4,
            CK_IMPEDANCE_LEN = 4,

            // Byte 24: CK Slew rate
            CK_SLEW_RATE_BYTE = 24,
            CK_SLEW_RATE_START = 0,
            CK_SLEW_RATE_LEN = 8,

            // Byte 25: Alert ODT Impedance
            ALERT_ODT_IMPEDANCE_BYTE = 25,
            ALERT_ODT_IMPEDANCE_START = 4,
            ALERT_ODT_IMPEDANCE_LEN = 4,

            // Byte 26: DRAM RTT Nom
            DRAM_RTT_NOM_BYTE = 26,
            DRAM_RTT_NOM_START = 0,
            DRAM_RTT_NOM_LEN = 8,

            // Byte 27: DRAM RTT Nom rank0
            DRAM_RTT_NOM_RANK0_BYTE = 27,
            DRAM_RTT_NOM_RANK0_START = 4,
            DRAM_RTT_NOM_RANK0_LEN = 4,

            // Byte 28: DRAM RTT Nom rank1
            DRAM_RTT_NOM_RANK1_BYTE = 28,
            DRAM_RTT_NOM_RANK1_START = 4,
            DRAM_RTT_NOM_RANK1_LEN = 4,

            // Byte 29: DRAM RTT Nom rank2
            DRAM_RTT_NOM_RANK2_BYTE = 29,
            DRAM_RTT_NOM_RANK2_START = 4,
            DRAM_RTT_NOM_RANK2_LEN = 4,

            // Byte 30: DRAM RTT Nom rank3
            DRAM_RTT_NOM_RANK3_BYTE = 30,
            DRAM_RTT_NOM_RANK3_START = 4,
            DRAM_RTT_NOM_RANK3_LEN = 4,

            // Byte 31: DRAM RTT WR
            DRAM_RTT_WR_BYTE = 31,
            DRAM_RTT_WR_START = 0,
            DRAM_RTT_WR_LEN = 8,

            // Byte 32: DRAM RTT WR rank0
            DRAM_RTT_WR_RANK0_BYTE = 32,
            DRAM_RTT_WR_RANK0_START = 4,
            DRAM_RTT_WR_RANK0_LEN = 4,

            // Byte 33: DRAM RTT WR rank1
            DRAM_RTT_WR_RANK1_BYTE = 33,
            DRAM_RTT_WR_RANK1_START = 4,
            DRAM_RTT_WR_RANK1_LEN = 4,

            // Byte 34: DRAM RTT WR rank2
            DRAM_RTT_WR_RANK2_BYTE = 34,
            DRAM_RTT_WR_RANK2_START = 4,
            DRAM_RTT_WR_RANK2_LEN = 4,

            // Byte 35: DRAM RTT WR rank3
            DRAM_RTT_WR_RANK3_BYTE = 35,
            DRAM_RTT_WR_RANK3_START = 4,
            DRAM_RTT_WR_RANK3_LEN = 4,

            // Byte 36: DRAM RTT Park
            DRAM_RTT_PARK_BYTE = 36,
            DRAM_RTT_PARK_START = 0,
            DRAM_RTT_PARK_LEN = 8,

            // Byte 37: DRAM RTT Park rank0
            DRAM_RTT_PARK_RANK0_BYTE = 37,
            DRAM_RTT_PARK_RANK0_START = 4,
            DRAM_RTT_PARK_RANK0_LEN = 4,

            // Byte 38: DRAM RTT Park rank1
            DRAM_RTT_PARK_RANK1_BYTE = 38,
            DRAM_RTT_PARK_RANK1_START = 4,
            DRAM_RTT_PARK_RANK1_LEN = 4,

            // Byte 39: DRAM RTT Park rank2
            DRAM_RTT_PARK_RANK2_BYTE = 39,
            DRAM_RTT_PARK_RANK2_START = 4,
            DRAM_RTT_PARK_RANK2_LEN = 4,

            // Byte 40: DRAM RTT Park rank3
            DRAM_RTT_PARK_RANK3_BYTE = 40,
            DRAM_RTT_PARK_RANK3_START = 4,
            DRAM_RTT_PARK_RANK3_LEN = 4,

            // Byte 41: DRAM DIC
            DRAM_DIC_BYTE = 41,
            DRAM_DIC_START = 4,
            DRAM_DIC_LEN = 4,

            // Byte 42: DRAM Preamble
            DRAM_PREAMBLE_BYTE = 42,
            WRITE_PREAMBLE_START = 6,
            WRITE_PREAMBLE_LEN = 1,
            READ_PREAMBLE_START = 7,
            READ_PREAMBLE_LEN = 1,

            // Byte 43: PHY Equalization
            PHY_EQUALIZATION_BYTE = 43,
            PHY_EQUALIZATION_START = 6,
            PHY_EQUALIZATION_LEN = 2,

            // Byte 44: Initial WR VREF DQ setting
            INIT_VREF_DQ_BYTE = 44,
            WR_VREF_DQ_RANGE_START = 1,
            WR_VREF_DQ_RANGE_LEN = 1,
            WR_VREF_DQ_VALUE_START = 2,
            WR_VREF_DQ_VALUE_LEN = 6,

            // Byte 45: Host RD VREF DQ
            INIT_PHY_VREF_BYTE = 45,
            INIT_PHY_VREF_START = 1,
            INIT_PHY_VREF_LEN = 7,

            // Byte 46: ODT WR Map CS Byte1
            ODT_WR_MAP1_BYTE = 46,
            ODT_WR_MAP_RANK3_START = 0,
            ODT_WR_MAP_RANK3_LEN = 4,
            ODT_WR_MAP_RANK2_START = 4,
            ODT_WR_MAP_RANK2_LEN = 4,

            // Byte 47: ODT WR Map CS Byte0
            ODT_WR_MAP0_BYTE = 47,
            ODT_WR_MAP_RANK1_START = 0,
            ODT_WR_MAP_RANK1_LEN = 4,
            ODT_WR_MAP_RANK0_START = 4,
            ODT_WR_MAP_RANK0_LEN = 4,

            // Byte 48: ODT RD Map CS Byte1
            ODT_RD_MAP1_BYTE = 48,
            ODT_RD_MAP_RANK3_START = 0,
            ODT_RD_MAP_RANK3_LEN = 4,
            ODT_RD_MAP_RANK2_START = 4,
            ODT_RD_MAP_RANK2_LEN = 4,

            // Byte 49: ODT RD Map CS Byte0
            ODT_RD_MAP0_BYTE = 49,
            ODT_RD_MAP_RANK1_START = 0,
            ODT_RD_MAP_RANK1_LEN = 4,
            ODT_RD_MAP_RANK0_START = 4,
            ODT_RD_MAP_RANK0_LEN = 4,

            // Byte 50: Geardown during training
            GEARDOWN_DURING_TRAINING_BYTE = 50,
            GEARDOWN_DURING_TRAINING_START = 7,
            GEARDOWN_DURING_TRAINING_LEN = 1,

            // Byte 51: BIST CAL Mode
            BIST_CA_LATENCY_MODE_BYTE = 51,
            BIST_CA_LATENCY_MODE_START = 4,
            BIST_CA_LATENCY_MODE_LEN = 4,

            // Byte 52: BIST CA Parity Latency Mode
            BIST_CA_PL_MODE_BYTE = 52,
            BIST_CA_PL_MODE_START = 4,
            BIST_CA_PL_MODE_LEN = 4,

            // Byte 53: DFI Max RD Latency
            DFI_MAX_RD_LATENCY_BYTE = 53,
            DFIMRL_DDRCLK_START = 3,
            DFIMRL_DDRCLK_LEN = 5,

            // Byte 54: CAC Delay A side Group 0
            CAC_DELAY_A_SIDE_GROUP_0_BYTE = 54,
            CAC_DLY_A_0_START = 3,
            CAC_DLY_A_0_LEN = 5,

            // Byte 55: CAC Delay A side Group 1
            CAC_DELAY_A_SIDE_GROUP_1_BYTE = 55,
            CAC_DLY_A_1_START = 3,
            CAC_DLY_A_1_LEN = 5,

            // Byte 56: CAC Delay A side Group 2
            CAC_DELAY_A_SIDE_GROUP_2_BYTE = 56,
            CAC_DLY_A_2_START = 3,
            CAC_DLY_A_2_LEN = 5,

            // Byte 57: CAC Delay A side Group 3
            CAC_DELAY_A_SIDE_GROUP_3_BYTE = 57,
            CAC_DLY_A_3_START = 3,
            CAC_DLY_A_3_LEN = 5,

            // Byte 58: CAC Delay A side Group 4
            CAC_DELAY_A_SIDE_GROUP_4_BYTE = 58,
            CAC_DLY_A_4_START = 3,
            CAC_DLY_A_4_LEN = 5,

            // Byte 59: CAC Delay A side Group 5
            CAC_DELAY_A_SIDE_GROUP_5_BYTE = 59,
            CAC_DLY_A_5_START = 3,
            CAC_DLY_A_5_LEN = 5,

            // Byte 60: CAC Delay A side Group 6
            CAC_DELAY_A_SIDE_GROUP_6_BYTE = 60,
            CAC_DLY_A_6_START = 3,
            CAC_DLY_A_6_LEN = 5,

            // Byte 61: CAC Delay A side Group 7
            CAC_DELAY_A_SIDE_GROUP_7_BYTE = 61,
            CAC_DLY_A_7_START = 3,
            CAC_DLY_A_7_LEN = 5,

            // Byte 62: CAC Delay B side Group 0
            CAC_DELAY_B_SIDE_GROUP_0_BYTE = 62,
            CAC_DLY_B_0_START = 3,
            CAC_DLY_B_0_LEN = 5,

            // Byte 63: CAC Delay B side Group 1
            CAC_DELAY_B_SIDE_GROUP_1_BYTE = 63,
            CAC_DLY_B_1_START = 3,
            CAC_DLY_B_1_LEN = 5,

            // Byte 64: CAC Delay B side Group 2
            CAC_DELAY_B_SIDE_GROUP_2_BYTE = 64,
            CAC_DLY_B_2_START = 3,
            CAC_DLY_B_2_LEN = 5,

            // Byte 65: CAC Delay B side Group 3
            CAC_DELAY_B_SIDE_GROUP_3_BYTE = 65,
            CAC_DLY_B_3_START = 3,
            CAC_DLY_B_3_LEN = 5,

            // Byte 66: CAC Delay B side Group 4
            CAC_DELAY_B_SIDE_GROUP_4_BYTE = 66,
            CAC_DLY_B_4_START = 3,
            CAC_DLY_B_4_LEN = 5,

            // Byte 67: CAC Delay B side Group 5
            CAC_DELAY_B_SIDE_GROUP_5_BYTE = 67,
            CAC_DLY_B_5_START = 3,
            CAC_DLY_B_5_LEN = 5,

            // Byte 68: CAC Delay B side Group 6
            CAC_DELAY_B_SIDE_GROUP_6_BYTE = 68,
            CAC_DLY_B_6_START = 3,
            CAC_DLY_B_6_LEN = 5,

            // Byte 69: CAC Delay B side Group 7
            CAC_DELAY_B_SIDE_GROUP_7_BYTE = 69,
            CAC_DLY_B_7_START = 3,
            CAC_DLY_B_7_LEN = 5,

            // Byte 70: PMIC0 SWA Volt
            PMIC0_SWA_BYTE = 70,
            PMIC0_SWA_OFFSET_START = 0,
            PMIC0_SWA_OFFSET_LEN = 7,
            PMIC0_SWA_OFFSET_DIRECTION_START = 7,
            PMIC0_SWA_OFFSET_DIRECTION_LEN = 1,

            // Byte 71: PMIC0 SWB Volt
            PMIC0_SWB_BYTE = 71,
            PMIC0_SWB_OFFSET_START = 0,
            PMIC0_SWB_OFFSET_LEN = 7,
            PMIC0_SWB_OFFSET_DIRECTION_START = 7,
            PMIC0_SWB_OFFSET_DIRECTION_LEN = 1,

            // Byte 72: PMIC0 SWC Volt
            PMIC0_SWC_BYTE = 72,
            PMIC0_SWC_OFFSET_START = 0,
            PMIC0_SWC_OFFSET_LEN = 7,
            PMIC0_SWC_OFFSET_DIRECTION_START = 7,
            PMIC0_SWC_OFFSET_DIRECTION_LEN = 1,

            // Byte 73: PMIC0 SWD Volt
            PMIC0_SWD_BYTE = 73,
            PMIC0_SWD_OFFSET_START = 0,
            PMIC0_SWD_OFFSET_LEN = 7,
            PMIC0_SWD_OFFSET_DIRECTION_START = 7,
            PMIC0_SWD_OFFSET_DIRECTION_LEN = 1,

            // Byte 74: PMIC1 SWA Volt
            PMIC1_SWA_BYTE = 74,
            PMIC1_SWA_OFFSET_START = 0,
            PMIC1_SWA_OFFSET_LEN = 7,
            PMIC1_SWA_OFFSET_DIRECTION_START = 7,
            PMIC1_SWA_OFFSET_DIRECTION_LEN = 1,

            // Byte 75: PMIC1 SWB Volt
            PMIC1_SWB_BYTE = 75,
            PMIC1_SWB_OFFSET_START = 0,
            PMIC1_SWB_OFFSET_LEN = 7,
            PMIC1_SWB_OFFSET_DIRECTION_START = 7,
            PMIC1_SWB_OFFSET_DIRECTION_LEN = 1,

            // Byte 76: PMIC1 SWC Volt
            PMIC1_SWC_BYTE = 76,
            PMIC1_SWC_OFFSET_START = 0,
            PMIC1_SWC_OFFSET_LEN = 7,
            PMIC1_SWC_OFFSET_DIRECTION_START = 7,
            PMIC1_SWC_OFFSET_DIRECTION_LEN = 1,

            // Byte 77: PMIC1 SWD Volt
            PMIC1_SWD_BYTE = 77,
            PMIC1_SWD_OFFSET_START = 0,
            PMIC1_SWD_OFFSET_LEN = 7,
            PMIC1_SWD_OFFSET_DIRECTION_START = 7,
            PMIC1_SWD_OFFSET_DIRECTION_LEN = 1,

            // Byte 78: PMIC0 SWA Current Consumption Warning Threshold
            // Note: These are pulled in including the two reserved bits [1:0], since this is
            // exactly how it will be written to the PMIC registers
            PMIC0_SWA_CURRENT_WARNING_BYTE = 78,
            PMIC0_SWA_CURRENT_WARNING_START = 0,
            PMIC0_SWA_CURRENT_WARNING_LEN = 8,

            // Byte 79: PMIC0 SWB Current Consumption Warning Threshold
            // Note: These are pulled in including the two reserved bits [1:0], since this is
            // exactly how it will be written to the PMIC registers
            PMIC0_SWB_CURRENT_WARNING_BYTE = 79,
            PMIC0_SWB_CURRENT_WARNING_START = 0,
            PMIC0_SWB_CURRENT_WARNING_LEN = 8,

            // Byte 80: PMIC0 SWC Current Consumption Warning Threshold
            // Note: These are pulled in including the two reserved bits [1:0], since this is
            // exactly how it will be written to the PMIC registers
            PMIC0_SWC_CURRENT_WARNING_BYTE = 80,
            PMIC0_SWC_CURRENT_WARNING_START = 0,
            PMIC0_SWC_CURRENT_WARNING_LEN = 8,

            // Byte 80: PMIC0 SWD Current Consumption Warning Threshold
            // Note: These are pulled in including the two reserved bits [1:0], since this is
            // exactly how it will be written to the PMIC registers
            PMIC0_SWD_CURRENT_WARNING_BYTE = 81,
            PMIC0_SWD_CURRENT_WARNING_START = 0,
            PMIC0_SWD_CURRENT_WARNING_LEN = 8,

            // Byte 82: PMIC1 SWA Current Consumption Warning Threshold
            // Note: These are pulled in including the two reserved bits [1:0], since this is
            // exactly how it will be written to the PMIC registers
            PMIC1_SWA_CURRENT_WARNING_BYTE = 82,
            PMIC1_SWA_CURRENT_WARNING_START = 0,
            PMIC1_SWA_CURRENT_WARNING_LEN = 8,

            // Byte 83: PMIC1 SWB Current Consumption Warning Threshold
            // Note: These are pulled in including the two reserved bits [1:0], since this is
            // exactly how it will be written to the PMIC registers
            PMIC1_SWB_CURRENT_WARNING_BYTE = 83,
            PMIC1_SWB_CURRENT_WARNING_START = 0,
            PMIC1_SWB_CURRENT_WARNING_LEN = 8,

            // Byte 84: PMIC1 SWC Current Consumption Warning Threshold
            // Note: These are pulled in including the two reserved bits [1:0], since this is
            // exactly how it will be written to the PMIC registers
            PMIC1_SWC_CURRENT_WARNING_BYTE = 84,
            PMIC1_SWC_CURRENT_WARNING_START = 0,
            PMIC1_SWC_CURRENT_WARNING_LEN = 8,

            // Byte 85: PMIC1 SWD Current Consumption Warning Threshold
            // Note: These are pulled in including the two reserved bits [1:0], since this is
            // exactly how it will be written to the PMIC registers
            PMIC1_SWD_CURRENT_WARNING_BYTE = 85,
            PMIC1_SWD_CURRENT_WARNING_START = 0,
            PMIC1_SWD_CURRENT_WARNING_LEN = 8,

            // Byte 96: RCD driver impedance control Byte0
            RCD_DIC_0_BYTE = 96,
            RCD_DIC_0_START = 0,
            RCD_DIC_0_LEN = 8,

            // Byte 97: RCD driver impedance control Byte1
            RCD_DIC_1_BYTE = 97,
            RCD_DIC_1_START = 0,
            RCD_DIC_1_LEN = 8,

            // Byte 98: RCD voltage control Byte0
            RCD_VOLTAGE_CTRL_0_BYTE = 98,
            RCD_VOLTAGE_CTRL_0_START = 0,
            RCD_VOLTAGE_CTRL_0_LEN = 8,

            // Byte 99: RCD voltage control Byte1
            RCD_VOLTAGE_CTRL_1_BYTE = 99,
            RCD_VOLTAGE_CTRL_1_START = 0,
            RCD_VOLTAGE_CTRL_1_LEN = 8,

            // Byte 100: RCD Input Bus Termination
            RCD_IBT_BYTE = 100,
            RCD_IBT_START = 0,
            RCD_IBT_LEN = 8,

            // Byte 101: RCD data buffer driver impedance control
            RCD_DB_DIC_BYTE = 101,
            RCD_DB_DIC_START = 0,
            RCD_DB_DIC_LEN = 8,

            // Byte 102: RCD slew rate control Byte0
            RCD_SLEW_RATE_CTRL_0_BYTE = 102,
            RCD_SLEW_RATE_CTRL_0_START = 0,
            RCD_SLEW_RATE_CTRL_0_LEN = 8,

            // Byte 103: RCD slew rate control Byte1
            RCD_SLEW_RATE_CTRL_1_BYTE = 103,
            RCD_SLEW_RATE_CTRL_1_START = 0,
            RCD_SLEW_RATE_CTRL_1_LEN = 8,

            // Byte 104:  F1RC1X - QxCSn_n Output Delay Control Word
            F1RC1X_BYTE = 104,
            F1RC1X_START = 0,
            F1RC1X_LEN = 8,

            // Byte 105:  F1RC2X - QxCN Output Delay Control Word
            F1RC2X_BYTE = 105,
            F1RC2X_START = 0,
            F1RC2X_LEN = 8,

            // Byte 106:  F1RC3X - QxCKEn Output Delay Control Word
            F1RC3X_BYTE = 106,
            F1RC3X_START = 0,
            F1RC3X_LEN = 8,

            // Byte 107:  F1RC4X - QxODTn Output Delay Control Word
            F1RC4X_BYTE = 107,
            F1RC4X_START = 0,
            F1RC4X_LEN = 8,

            // Byte 108:  F1RC5X - QxCA Output Delay Control Word
            F1RC5X_BYTE = 108,
            F1RC5X_START = 0,
            F1RC5X_LEN = 8,

            // Byte 109:  F1RC6X – Y1/Y3 Output Delay Control Word
            F1RC6X_BYTE = 109,
            F1RC6X_START = 0,
            F1RC6X_LEN = 8,

            // Byte 110: F1RC7X – Y0/Y2 Output Delay Control Word
            F1RC7X_BYTE = 110,
            F1RC7X_START = 0,
            F1RC7X_LEN = 8,
        };

    public:
        // Syntatic sugar to make member variable declaration easier
        using field_t = mss::field_t<mss::endian::LITTLE>;

        // First field - SPD byte
        // Second field - start bit
        // Third field - bit length

        // Byte 0: Host Speed Supported
        static constexpr field_t HOST_SPEED_SUPPORTED{HOST_SPEED_SUPPORTED_BYTE, HOST_SPEED_SUPPORTED_START, HOST_SPEED_SUPPORTED_LEN};

        // Byte 2: Master Ranks Supported
        static constexpr field_t MASTER_RANKS_SUPPORTED{MASTER_RANKS_SUPPORTED_BYTE, MASTER_RANKS_SUPPORTED_START, MASTER_RANKS_SUPPORTED_LEN};

        // Byte 3: Channels supported byte0
        static constexpr field_t CHANNELS_SUPPORTED_BYTE0{CHANNELS_SUPPORTED_BYTE0_BYTE, CHANNELS_SUPPORTED_BYTE0_START, CHANNELS_SUPPORTED_BYTE0_LEN};

        // Byte 4: Channels supported byte1
        static constexpr field_t CHANNELS_SUPPORTED_BYTE1{CHANNELS_SUPPORTED_BYTE1_BYTE, CHANNELS_SUPPORTED_BYTE1_START, CHANNELS_SUPPORTED_BYTE1_LEN};

        // Byte 5: Channels supported byte2
        static constexpr field_t CHANNELS_SUPPORTED_BYTE2{CHANNELS_SUPPORTED_BYTE2_BYTE, CHANNELS_SUPPORTED_BYTE2_START, CHANNELS_SUPPORTED_BYTE2_LEN};

        // Byte 6: Channels supported byte3
        static constexpr field_t CHANNELS_SUPPORTED_BYTE3{CHANNELS_SUPPORTED_BYTE3_BYTE, CHANNELS_SUPPORTED_BYTE3_START, CHANNELS_SUPPORTED_BYTE3_LEN};

        // Byte 7: DIMMs supported
        static constexpr field_t DIMMS_SUPPORTED{DIMMS_SUPPORTED_BYTE, DIMMS_SUPPORTED_START, DIMMS_SUPPORTED_LEN};

        // Byte 16: PHY ODT impedance
        static constexpr field_t PHY_ODT_IMPEDANCE{PHY_ODT_IMPEDANCE_BYTE, PHY_ODT_IMPEDANCE_START, PHY_ODT_IMPEDANCE_LEN};

        // Byte 17: PHY Drive impedance pull up
        static constexpr field_t PHY_DRIVE_IMPEDANCE_PULL_UP{PHY_DRIVE_IMPEDANCE_PULL_UP_BYTE, PHY_DRIVE_IMPEDANCE_PULL_UP_START, PHY_DRIVE_IMPEDANCE_PULL_UP_LEN};

        // Byte 18: PHY Drive impedance pull down
        static constexpr field_t PHY_DRIVE_IMPEDANCE_PULL_DOWN{PHY_DRIVE_IMPEDANCE_PULL_DOWN_BYTE, PHY_DRIVE_IMPEDANCE_PULL_DOWN_START, PHY_DRIVE_IMPEDANCE_PULL_DOWN_LEN};

        // Byte 19: PHY Drive Impedance
        static constexpr field_t PHY_DRIVE_IMPEDANCE{PHY_DRIVE_IMPEDANCE_BYTE, PHY_DRIVE_IMPEDANCE_START, PHY_DRIVE_IMPEDANCE_LEN};

        // Byte 20: PHY Slew Rate DQ_DQS
        static constexpr field_t PHY_SLEW_RATE_DQ_DQS{PHY_SLEW_RATE_DQ_DQS_BYTE, PHY_SLEW_RATE_DQ_DQS_START, PHY_SLEW_RATE_DQ_DQS_LEN};

        // Byte 21: ATX impedance
        static constexpr field_t ATX_IMPEDANCE{ATX_IMPEDANCE_BYTE, ATX_IMPEDANCE_START, ATX_IMPEDANCE_LEN};

        // Byte 22: ATX Slew rate
        static constexpr field_t ATX_SLEW_RATE{ATX_SLEW_RATE_BYTE, ATX_SLEW_RATE_START, ATX_SLEW_RATE_LEN};

        // Byte 23: CK Impedance
        static constexpr field_t CK_IMPEDANCE{CK_IMPEDANCE_BYTE, CK_IMPEDANCE_START, CK_IMPEDANCE_LEN};

        // Byte 24: CK Slew rate
        static constexpr field_t CK_SLEW_RATE{CK_SLEW_RATE_BYTE, CK_SLEW_RATE_START, CK_SLEW_RATE_LEN};

        // Byte 25: Alert ODT Impedance
        static constexpr field_t ALERT_ODT_IMPEDANCE{ALERT_ODT_IMPEDANCE_BYTE, ALERT_ODT_IMPEDANCE_START, ALERT_ODT_IMPEDANCE_LEN};

        // Byte 26: DRAM RTT Nom
        static constexpr field_t DRAM_RTT_NOM{DRAM_RTT_NOM_BYTE, DRAM_RTT_NOM_START, DRAM_RTT_NOM_LEN};

        // Byte 27: DRAM RTT Nom rank0
        static constexpr field_t DRAM_RTT_NOM_RANK0{DRAM_RTT_NOM_RANK0_BYTE, DRAM_RTT_NOM_RANK0_START, DRAM_RTT_NOM_RANK0_LEN};

        // Byte 28: DRAM RTT Nom rank1
        static constexpr field_t DRAM_RTT_NOM_RANK1{DRAM_RTT_NOM_RANK1_BYTE, DRAM_RTT_NOM_RANK1_START, DRAM_RTT_NOM_RANK1_LEN};

        // Byte 29: DRAM RTT Nom rank2
        static constexpr field_t DRAM_RTT_NOM_RANK2{DRAM_RTT_NOM_RANK2_BYTE, DRAM_RTT_NOM_RANK2_START, DRAM_RTT_NOM_RANK2_LEN};

        // Byte 30: DRAM RTT Nom rank3
        static constexpr field_t DRAM_RTT_NOM_RANK3{DRAM_RTT_NOM_RANK3_BYTE, DRAM_RTT_NOM_RANK3_START, DRAM_RTT_NOM_RANK3_LEN};

        // Byte 31: DRAM RTT WR
        static constexpr field_t DRAM_RTT_WR{DRAM_RTT_WR_BYTE, DRAM_RTT_WR_START, DRAM_RTT_WR_LEN};

        // Byte 32: DRAM RTT WR rank0
        static constexpr field_t DRAM_RTT_WR_RANK0{DRAM_RTT_WR_RANK0_BYTE, DRAM_RTT_WR_RANK0_START, DRAM_RTT_WR_RANK0_LEN};

        // Byte 33: DRAM RTT WR rank1
        static constexpr field_t DRAM_RTT_WR_RANK1{DRAM_RTT_WR_RANK1_BYTE, DRAM_RTT_WR_RANK1_START, DRAM_RTT_WR_RANK1_LEN};

        // Byte 34: DRAM RTT WR rank2
        static constexpr field_t DRAM_RTT_WR_RANK2{DRAM_RTT_WR_RANK2_BYTE, DRAM_RTT_WR_RANK2_START, DRAM_RTT_WR_RANK2_LEN};

        // Byte 35: DRAM RTT WR rank3
        static constexpr field_t DRAM_RTT_WR_RANK3{DRAM_RTT_WR_RANK3_BYTE, DRAM_RTT_WR_RANK3_START, DRAM_RTT_WR_RANK3_LEN};

        // Byte 36: DRAM RTT Park
        static constexpr field_t DRAM_RTT_PARK{DRAM_RTT_PARK_BYTE, DRAM_RTT_PARK_START, DRAM_RTT_PARK_LEN};

        // Byte 37: DRAM RTT Park rank0
        static constexpr field_t DRAM_RTT_PARK_RANK0{DRAM_RTT_PARK_RANK0_BYTE, DRAM_RTT_PARK_RANK0_START, DRAM_RTT_PARK_RANK0_LEN};

        // Byte 38: DRAM RTT Park rank1
        static constexpr field_t DRAM_RTT_PARK_RANK1{DRAM_RTT_PARK_RANK1_BYTE, DRAM_RTT_PARK_RANK1_START, DRAM_RTT_PARK_RANK1_LEN};

        // Byte 39: DRAM RTT Park rank2
        static constexpr field_t DRAM_RTT_PARK_RANK2{DRAM_RTT_PARK_RANK2_BYTE, DRAM_RTT_PARK_RANK2_START, DRAM_RTT_PARK_RANK2_LEN};

        // Byte 40: DRAM RTT Park rank3
        static constexpr field_t DRAM_RTT_PARK_RANK3{DRAM_RTT_PARK_RANK3_BYTE, DRAM_RTT_PARK_RANK3_START, DRAM_RTT_PARK_RANK3_LEN};

        // Byte 41: DRAM DIC
        static constexpr field_t DRAM_DIC{DRAM_DIC_BYTE, DRAM_DIC_START, DRAM_DIC_LEN};

        // Byte 42: DRAM Preamble
        static constexpr field_t WRITE_PREAMBLE{DRAM_PREAMBLE_BYTE, WRITE_PREAMBLE_START, WRITE_PREAMBLE_LEN};
        static constexpr field_t READ_PREAMBLE{DRAM_PREAMBLE_BYTE, READ_PREAMBLE_START, READ_PREAMBLE_LEN};

        // Byte 43: PHY Equalization
        static constexpr field_t PHY_EQUALIZATION{PHY_EQUALIZATION_BYTE, PHY_EQUALIZATION_START, PHY_EQUALIZATION_LEN};

        // Byte 44: Initial VREF DQ setting
        static constexpr field_t WR_VREF_DQ_RANGE{INIT_VREF_DQ_BYTE, WR_VREF_DQ_RANGE_START, WR_VREF_DQ_RANGE_LEN};
        static constexpr field_t WR_VREF_DQ_VALUE{INIT_VREF_DQ_BYTE, WR_VREF_DQ_VALUE_START, WR_VREF_DQ_VALUE_LEN};

        // Byte 45: Initial PHY VREF setting
        static constexpr field_t INIT_PHY_VREF{INIT_PHY_VREF_BYTE, INIT_PHY_VREF_START, INIT_PHY_VREF_LEN};

        // Byte 46: ODT WR Map CS Byte1
        static constexpr field_t ODT_WR_MAP_RANK3{ODT_WR_MAP1_BYTE, ODT_WR_MAP_RANK3_START, ODT_WR_MAP_RANK3_LEN};
        static constexpr field_t ODT_WR_MAP_RANK2{ODT_WR_MAP1_BYTE, ODT_WR_MAP_RANK2_START, ODT_WR_MAP_RANK2_LEN};

        // Byte 47: ODT WR Map CS Byte0
        static constexpr field_t ODT_WR_MAP_RANK1{ODT_WR_MAP0_BYTE, ODT_WR_MAP_RANK1_START, ODT_WR_MAP_RANK1_LEN};
        static constexpr field_t ODT_WR_MAP_RANK0{ODT_WR_MAP0_BYTE, ODT_WR_MAP_RANK0_START, ODT_WR_MAP_RANK0_LEN};

        // Byte 48: ODT RD Map CS Byte1
        static constexpr field_t ODT_RD_MAP_RANK3{ODT_RD_MAP1_BYTE, ODT_RD_MAP_RANK3_START, ODT_RD_MAP_RANK3_LEN};
        static constexpr field_t ODT_RD_MAP_RANK2{ODT_RD_MAP1_BYTE, ODT_RD_MAP_RANK2_START, ODT_RD_MAP_RANK2_LEN};

        // Byte 49: ODT RD Map CS Byte0
        static constexpr field_t ODT_RD_MAP_RANK1{ODT_RD_MAP0_BYTE, ODT_RD_MAP_RANK1_START, ODT_RD_MAP_RANK1_LEN};
        static constexpr field_t ODT_RD_MAP_RANK0{ODT_RD_MAP0_BYTE, ODT_RD_MAP_RANK0_START, ODT_RD_MAP_RANK0_LEN};

        // Byte 50: Geardown during training
        static constexpr field_t GEARDOWN_DURING_TRAINING{GEARDOWN_DURING_TRAINING_BYTE, GEARDOWN_DURING_TRAINING_START, GEARDOWN_DURING_TRAINING_LEN};

        // Byte 51: BIST CAL Mode
        static constexpr field_t BIST_CA_LATENCY_MODE{BIST_CA_LATENCY_MODE_BYTE, BIST_CA_LATENCY_MODE_START, BIST_CA_LATENCY_MODE_LEN};

        // Byte 52: BIST CA Parity Latency Mode
        static constexpr field_t BIST_CA_PL_MODE{BIST_CA_PL_MODE_BYTE, BIST_CA_PL_MODE_START, BIST_CA_PL_MODE_LEN};

        // Byte 53: DFI Max RD Latency
        static constexpr field_t DFIMRL_DDRCLK{DFI_MAX_RD_LATENCY_BYTE, DFIMRL_DDRCLK_START, DFIMRL_DDRCLK_LEN};

        // Byte 54: CAC Delay A side Group 0
        static constexpr field_t CAC_DLY_A_0{CAC_DELAY_A_SIDE_GROUP_0_BYTE, CAC_DLY_A_0_START, CAC_DLY_A_0_LEN};

        // Byte 55: CAC Delay A side Group 1
        static constexpr field_t CAC_DLY_A_1{CAC_DELAY_A_SIDE_GROUP_1_BYTE, CAC_DLY_A_1_START, CAC_DLY_A_1_LEN};

        // Byte 56: CAC Delay A side Group 2
        static constexpr field_t CAC_DLY_A_2{CAC_DELAY_A_SIDE_GROUP_2_BYTE, CAC_DLY_A_2_START, CAC_DLY_A_2_LEN};

        // Byte 57: CAC Delay A side Group 3
        static constexpr field_t CAC_DLY_A_3{CAC_DELAY_A_SIDE_GROUP_3_BYTE, CAC_DLY_A_3_START, CAC_DLY_A_3_LEN};

        // Byte 58: CAC Delay A side Group 4
        static constexpr field_t CAC_DLY_A_4{CAC_DELAY_A_SIDE_GROUP_4_BYTE, CAC_DLY_A_4_START, CAC_DLY_A_4_LEN};

        // Byte 59: CAC Delay A side Group 5
        static constexpr field_t CAC_DLY_A_5{CAC_DELAY_A_SIDE_GROUP_5_BYTE, CAC_DLY_A_5_START, CAC_DLY_A_5_LEN};

        // Byte 60: CAC Delay A side Group 6
        static constexpr field_t CAC_DLY_A_6{CAC_DELAY_A_SIDE_GROUP_6_BYTE, CAC_DLY_A_6_START, CAC_DLY_A_6_LEN};

        // Byte 61: CAC Delay A side Group 7
        static constexpr field_t CAC_DLY_A_7{CAC_DELAY_A_SIDE_GROUP_7_BYTE, CAC_DLY_A_7_START, CAC_DLY_A_7_LEN};

        // Byte 62: CAC Delay B side Group 0
        static constexpr field_t CAC_DLY_B_0{CAC_DELAY_B_SIDE_GROUP_0_BYTE, CAC_DLY_B_0_START, CAC_DLY_B_0_LEN};

        // Byte 63: CAC Delay B side Group 1
        static constexpr field_t CAC_DLY_B_1{CAC_DELAY_B_SIDE_GROUP_1_BYTE, CAC_DLY_B_1_START, CAC_DLY_B_1_LEN};

        // Byte 64: CAC Delay B side Group 2
        static constexpr field_t CAC_DLY_B_2{CAC_DELAY_B_SIDE_GROUP_2_BYTE, CAC_DLY_B_2_START, CAC_DLY_B_2_LEN};

        // Byte 65: CAC Delay B side Group 3
        static constexpr field_t CAC_DLY_B_3{CAC_DELAY_B_SIDE_GROUP_3_BYTE, CAC_DLY_B_3_START, CAC_DLY_B_3_LEN};

        // Byte 66: CAC Delay B side Group 4
        static constexpr field_t CAC_DLY_B_4{CAC_DELAY_B_SIDE_GROUP_4_BYTE, CAC_DLY_B_4_START, CAC_DLY_B_4_LEN};

        // Byte 67: CAC Delay B side Group 5
        static constexpr field_t CAC_DLY_B_5{CAC_DELAY_B_SIDE_GROUP_5_BYTE, CAC_DLY_B_5_START, CAC_DLY_B_5_LEN};

        // Byte 68: CAC Delay B side Group 6
        static constexpr field_t CAC_DLY_B_6{CAC_DELAY_B_SIDE_GROUP_6_BYTE, CAC_DLY_B_6_START, CAC_DLY_B_6_LEN};

        // Byte 69: CAC Delay B side Group 7
        static constexpr field_t CAC_DLY_B_7{CAC_DELAY_B_SIDE_GROUP_7_BYTE, CAC_DLY_B_7_START, CAC_DLY_B_7_LEN};

        // Byte 70: PMIC0 SWA Volt
        static constexpr field_t PMIC0_SWA_OFFSET{PMIC0_SWA_BYTE, PMIC0_SWA_OFFSET_START, PMIC0_SWA_OFFSET_LEN};
        static constexpr field_t PMIC0_SWA_OFFSET_DIRECTION{PMIC0_SWA_BYTE, PMIC0_SWA_OFFSET_DIRECTION_START, PMIC0_SWA_OFFSET_DIRECTION_LEN};

        // Byte 71: PMIC0 SWB Volt
        static constexpr field_t PMIC0_SWB_OFFSET{PMIC0_SWB_BYTE, PMIC0_SWB_OFFSET_START, PMIC0_SWB_OFFSET_LEN};
        static constexpr field_t PMIC0_SWB_OFFSET_DIRECTION{PMIC0_SWB_BYTE, PMIC0_SWB_OFFSET_DIRECTION_START, PMIC0_SWB_OFFSET_DIRECTION_LEN};

        // Byte 72: PMIC0 SWC Volt
        static constexpr field_t PMIC0_SWC_OFFSET{PMIC0_SWC_BYTE, PMIC0_SWC_OFFSET_START, PMIC0_SWC_OFFSET_LEN};
        static constexpr field_t PMIC0_SWC_OFFSET_DIRECTION{PMIC0_SWC_BYTE, PMIC0_SWC_OFFSET_DIRECTION_START, PMIC0_SWC_OFFSET_DIRECTION_LEN};

        // Byte 73: PMIC0 SWD Volt
        static constexpr field_t PMIC0_SWD_OFFSET{PMIC0_SWD_BYTE, PMIC0_SWD_OFFSET_START, PMIC0_SWD_OFFSET_LEN};
        static constexpr field_t PMIC0_SWD_OFFSET_DIRECTION{PMIC0_SWD_BYTE, PMIC0_SWD_OFFSET_DIRECTION_START, PMIC0_SWD_OFFSET_DIRECTION_LEN};

        // Byte 74: PMIC1 SWA Volt
        static constexpr field_t PMIC1_SWA_OFFSET{PMIC1_SWA_BYTE, PMIC1_SWA_OFFSET_START, PMIC1_SWA_OFFSET_LEN};
        static constexpr field_t PMIC1_SWA_OFFSET_DIRECTION{PMIC1_SWA_BYTE, PMIC1_SWA_OFFSET_DIRECTION_START, PMIC1_SWA_OFFSET_DIRECTION_LEN};

        // Byte 75: PMIC1 SWB Volt
        static constexpr field_t PMIC1_SWB_OFFSET{PMIC1_SWB_BYTE, PMIC1_SWB_OFFSET_START, PMIC1_SWB_OFFSET_LEN};
        static constexpr field_t PMIC1_SWB_OFFSET_DIRECTION{PMIC1_SWB_BYTE, PMIC1_SWB_OFFSET_DIRECTION_START, PMIC1_SWB_OFFSET_DIRECTION_LEN};

        // Byte 76: PMIC1 SWC Volt
        static constexpr field_t PMIC1_SWC_OFFSET{PMIC1_SWC_BYTE, PMIC1_SWC_OFFSET_START, PMIC1_SWC_OFFSET_LEN};
        static constexpr field_t PMIC1_SWC_OFFSET_DIRECTION{PMIC1_SWC_BYTE, PMIC1_SWC_OFFSET_DIRECTION_START, PMIC1_SWC_OFFSET_DIRECTION_LEN};

        // Byte 77: PMIC1 SWD Volt
        static constexpr field_t PMIC1_SWD_OFFSET{PMIC1_SWD_BYTE, PMIC1_SWD_OFFSET_START, PMIC1_SWD_OFFSET_LEN};
        static constexpr field_t PMIC1_SWD_OFFSET_DIRECTION{PMIC1_SWD_BYTE, PMIC1_SWD_OFFSET_DIRECTION_START, PMIC1_SWD_OFFSET_DIRECTION_LEN};

        // Byte 78: PMIC0 SWA Current Warning Threshold
        static constexpr field_t PMIC0_SWA_CURRENT_WARNING{PMIC0_SWA_CURRENT_WARNING_BYTE, PMIC0_SWA_CURRENT_WARNING_START, PMIC0_SWA_CURRENT_WARNING_LEN};

        // Byte 79: PMIC0 SWB Current Warning Threshold
        static constexpr field_t PMIC0_SWB_CURRENT_WARNING{PMIC0_SWB_CURRENT_WARNING_BYTE, PMIC0_SWB_CURRENT_WARNING_START, PMIC0_SWB_CURRENT_WARNING_LEN};

        // Byte 80: PMIC0 SWC Current Warning Threshold
        static constexpr field_t PMIC0_SWC_CURRENT_WARNING{PMIC0_SWC_CURRENT_WARNING_BYTE, PMIC0_SWC_CURRENT_WARNING_START, PMIC0_SWC_CURRENT_WARNING_LEN};

        // Byte 81: PMIC0 SWD Current Warning Threshold
        static constexpr field_t PMIC0_SWD_CURRENT_WARNING{PMIC0_SWD_CURRENT_WARNING_BYTE, PMIC0_SWD_CURRENT_WARNING_START, PMIC0_SWD_CURRENT_WARNING_LEN};

        // Byte 82: PMIC1 SWA Current Warning Threshold
        static constexpr field_t PMIC1_SWA_CURRENT_WARNING{PMIC1_SWA_CURRENT_WARNING_BYTE, PMIC1_SWA_CURRENT_WARNING_START, PMIC1_SWA_CURRENT_WARNING_LEN};

        // Byte 83: PMIC1 SWB Current Warning Threshold
        static constexpr field_t PMIC1_SWB_CURRENT_WARNING{PMIC1_SWB_CURRENT_WARNING_BYTE, PMIC1_SWB_CURRENT_WARNING_START, PMIC1_SWB_CURRENT_WARNING_LEN};

        // Byte 84: PMIC1 SWC Current Warning Threshold
        static constexpr field_t PMIC1_SWC_CURRENT_WARNING{PMIC1_SWC_CURRENT_WARNING_BYTE, PMIC1_SWC_CURRENT_WARNING_START, PMIC1_SWC_CURRENT_WARNING_LEN};

        // Byte 85: PMIC1 SWD Current Warning Threshold
        static constexpr field_t PMIC1_SWD_CURRENT_WARNING{PMIC1_SWD_CURRENT_WARNING_BYTE, PMIC1_SWD_CURRENT_WARNING_START, PMIC1_SWD_CURRENT_WARNING_LEN};

        // Byte 96: RCD driver impedance control Byte0
        static constexpr field_t RCD_DIC_0{RCD_DIC_0_BYTE, RCD_DIC_0_START, RCD_DIC_0_LEN};

        // Byte 97: RCD driver impedance control Byte1
        static constexpr field_t RCD_DIC_1{RCD_DIC_1_BYTE, RCD_DIC_1_START, RCD_DIC_1_LEN};

        // Byte 98: RCD voltage control Byte0
        static constexpr field_t RCD_VOLTAGE_CTRL_0{RCD_VOLTAGE_CTRL_0_BYTE, RCD_VOLTAGE_CTRL_0_START, RCD_VOLTAGE_CTRL_0_LEN};

        // Byte 99: RCD voltage control Byte1
        static constexpr field_t RCD_VOLTAGE_CTRL_1{RCD_VOLTAGE_CTRL_1_BYTE, RCD_VOLTAGE_CTRL_1_START, RCD_VOLTAGE_CTRL_1_LEN};

        // Byte 100: RCD Input Bus Termination
        static constexpr field_t RCD_IBT{RCD_IBT_BYTE, RCD_IBT_START, RCD_IBT_LEN};

        // Byte 101: RCD data buffer driver impedance control
        static constexpr field_t RCD_DB_DIC{RCD_DB_DIC_BYTE, RCD_DB_DIC_START, RCD_DB_DIC_LEN};

        // Byte 102: RCD slew rate control Byte0
        static constexpr field_t RCD_SLEW_RATE_CTRL_0{RCD_SLEW_RATE_CTRL_0_BYTE, RCD_SLEW_RATE_CTRL_0_START, RCD_SLEW_RATE_CTRL_0_LEN};

        // Byte 103: RCD slew rate control Byte1
        static constexpr field_t RCD_SLEW_RATE_CTRL_1{RCD_SLEW_RATE_CTRL_1_BYTE, RCD_SLEW_RATE_CTRL_1_START, RCD_SLEW_RATE_CTRL_1_LEN};

        // Byte 104:  F1RC1X - QxCSn_n Output Delay Control Word
        static constexpr field_t F1RC1X{F1RC1X_BYTE, F1RC1X_START, F1RC1X_LEN};

        // Byte 105:  F1RC2X - QxCN Output Delay Control Word
        static constexpr field_t F1RC2X{F1RC2X_BYTE, F1RC2X_START, F1RC2X_LEN};

        // Byte 106:  F1RC3X - QxCKEn Output Delay Control Word
        static constexpr field_t F1RC3X{F1RC3X_BYTE, F1RC3X_START, F1RC3X_LEN};

        // Byte 107:  F1RC4X - QxODTn Output Delay Control Word
        static constexpr field_t F1RC4X{F1RC4X_BYTE, F1RC4X_START, F1RC4X_LEN};

        // Byte 108:  F1RC5X - QxCA Output Delay Control Word
        static constexpr field_t F1RC5X{F1RC5X_BYTE, F1RC5X_START, F1RC5X_LEN};

        // Byte 109:  F1RC6X – Y1/Y3 Output Delay Control Word
        static constexpr field_t F1RC6X{F1RC6X_BYTE, F1RC6X_START, F1RC6X_LEN};

        // Byte 110: F1RC7X – Y0/Y2 Output Delay Control Word
        static constexpr field_t F1RC7X{F1RC7X_BYTE, F1RC7X_START, F1RC7X_LEN};
};

} // ns efd
} // ns mss
#endif
