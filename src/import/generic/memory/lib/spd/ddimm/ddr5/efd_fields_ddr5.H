/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/ddimm/ddr5/efd_fields_ddr5.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2023                        */
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
/// @file efd_fields_ddr5.H
/// @brief DDIMM Extended Functional Data (EFD) common fields
///
// *HWP HWP Owner: Geetha Pisapati <Geetha.Pisapati@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP
// EKB-Mirror-To: hostboot

#ifndef _EFD_FIELDS_DDR5_H_
#define _EFD_FIELDS_DDR5_H_


#include <cstdint>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/mss_field.H>

namespace mss
{

namespace efd
{

///
/// @class Fields class - specialization for DDR5 custom_ibm_fields
/// @tparam D device type (DDR5, etc.)
/// @tparam E EFD type (ie custom EFD type 1)
///
template<mss::spd::device_type D, mss::efd::id E>
class fields;

///
/// @class Fields class - specialization for DDR5 custom_ibm_fields
/// @note Stores all field information for the custom IBM DDR5 DDIMM
///
template<>
class fields<mss::spd::device_type::DDR5, mss::efd::id::DDR5_CUSTOM_IBM>
{
    private:

        enum
        {

            // Byte 0: Host Speed Supported
            HOST_SPEED_SUPPORTED_BYTE = 0,
            HOST_SPEED_SUPPORTED_START = 5,
            HOST_SPEED_SUPPORTED_LEN = 3,

            // Byte 1: 2N Requirements
            MODE_2N_REQUIREMENTS_BYTE = 1,
            MODE_2N_REQUIREMENTS_25600_START = 7,
            MODE_2N_REQUIREMENTS_25600_LEN = 1,
            MODE_2N_REQUIREMENTS_32000_START = 6,
            MODE_2N_REQUIREMENTS_32000_LEN = 1,
            MODE_2N_REQUIREMENTS_38400_START = 5,
            MODE_2N_REQUIREMENTS_38400_LEN = 1,

            // Byte 2: Master Ranks and PHY Channels Supported
            MASTER_RANKS_PHY_CHA_SUPPORTED_BYTE = 2,
            MASTER_RANKS_SUPPORTED_START = 4,
            MASTER_RANKS_SUPPORTED_LEN = 4,
            PHY_CHANNEL_SUPPORTED_START = 0,
            PHY_CHANNEL_SUPPORTED_LEN = 4,

            // Byte 3: PHY0 Channels A0/B0 VRef
            PHY0_CHANNELS_VREF_BYTE = 3,
            PHY0_CHANNELS_VREF_START = 1,
            PHY0_CHANNELS_VREF_LEN = 7,

            // Byte 4: PHY1 Channels A1/B1 VRef
            PHY1_CHANNELS_VREF_BYTE = 4,
            PHY1_CHANNELS_VREF_START = 1,
            PHY1_CHANNELS_VREF_LEN = 7,

            // Byte 5: DRAM DIC
            DRAM_DIC_BYTE = 5,
            DRAM_DIC_PULLUP_START = 0,
            DRAM_DIC_PULLUP_LEN = 4,
            DRAM_DIC_PULLDOWN_START = 4,
            DRAM_DIC_PULLDOWN_LEN = 4,

            // Byte 9: DRAM Preamble and Postamble Settings
            DRAM_PREAMBLE_POSTAMBLE_BYTE = 9,
            WRITE_POSTAMBLE_START = 0,
            WRITE_POSTAMBLE_LEN = 1,
            READ_POSTAMBLE_START = 1,
            READ_POSTAMBLE_LEN = 1,
            WRITE_PREAMBLE_START = 3,
            WRITE_PREAMBLE_LEN = 2,
            READ_PREAMBLE_START = 5,
            READ_PREAMBLE_LEN = 3,

            // Byte 10-17: DRAM VREF DQ Setting
            DRAM_VREF_BYTE0_BYTE = 10,
            DRAM_VREF_BYTE0_START = 0,
            DRAM_VREF_BYTE0_LEN = 8,

            DRAM_VREF_BYTE1_BYTE = 11,
            DRAM_VREF_BYTE1_START = 0,
            DRAM_VREF_BYTE1_LEN = 8,

            DRAM_VREF_BYTE2_BYTE = 12,
            DRAM_VREF_BYTE2_START = 0,
            DRAM_VREF_BYTE2_LEN = 8,

            DRAM_VREF_BYTE3_BYTE = 13,
            DRAM_VREF_BYTE3_START = 0,
            DRAM_VREF_BYTE3_LEN = 8,

            DRAM_VREF_BYTE4_BYTE = 14,
            DRAM_VREF_BYTE4_START = 0,
            DRAM_VREF_BYTE4_LEN = 8,

            DRAM_VREF_BYTE5_BYTE = 15,
            DRAM_VREF_BYTE5_START = 0,
            DRAM_VREF_BYTE5_LEN = 8,

            DRAM_VREF_BYTE6_BYTE = 16,
            DRAM_VREF_BYTE6_START = 0,
            DRAM_VREF_BYTE6_LEN = 8,

            DRAM_VREF_BYTE7_BYTE = 17,
            DRAM_VREF_BYTE7_START = 0,
            DRAM_VREF_BYTE7_LEN = 8,

            // Byte 18: DRAM DFE Settings
            DRAM_DFE_BYTE = 18,
            DRAM_DFE_TAP4_START = 3,
            DRAM_DFE_TAP4_LEN = 1,
            DRAM_DFE_TAP3_START = 4,
            DRAM_DFE_TAP3_LEN = 1,
            DRAM_DFE_TAP2_START = 5,
            DRAM_DFE_TAP2_LEN = 1,
            DRAM_DFE_TAP1_START = 6,
            DRAM_DFE_TAP1_LEN = 1,
            DRAM_DFE_EN_START = 7,
            DRAM_DFE_EN_LEN = 1,

            // Byte 19-26: DRAM DFE Gain Bias
            DRAM_DFE_GAIN_BIAS_BYTE0_BYTE = 19,
            DRAM_DFE_GAIN_BIAS_BYTE0_START = 5,
            DRAM_DFE_GAIN_BIAS_BYTE0_LEN = 3,
            DRAM_DFE_GAIN_BIAS_BYTE0_SIGN_BIT_START = 4,
            DRAM_DFE_GAIN_BIAS_BYTE0_SIGN_BIT_LEN = 1,

            DRAM_DFE_GAIN_BIAS_BYTE1_BYTE = 20,
            DRAM_DFE_GAIN_BIAS_BYTE1_START = 5,
            DRAM_DFE_GAIN_BIAS_BYTE1_LEN = 3,
            DRAM_DFE_GAIN_BIAS_BYTE1_SIGN_BIT_START = 4,
            DRAM_DFE_GAIN_BIAS_BYTE1_SIGN_BIT_LEN = 1,

            DRAM_DFE_GAIN_BIAS_BYTE2_BYTE = 21,
            DRAM_DFE_GAIN_BIAS_BYTE2_START = 0,
            DRAM_DFE_GAIN_BIAS_BYTE2_LEN = 8,
            DRAM_DFE_GAIN_BIAS_BYTE2_SIGN_BIT_START = 4,
            DRAM_DFE_GAIN_BIAS_BYTE2_SIGN_BIT_LEN = 1,

            DRAM_DFE_GAIN_BIAS_BYTE3_BYTE = 22,
            DRAM_DFE_GAIN_BIAS_BYTE3_START = 0,
            DRAM_DFE_GAIN_BIAS_BYTE3_LEN = 8,
            DRAM_DFE_GAIN_BIAS_BYTE3_SIGN_BIT_START = 4,
            DRAM_DFE_GAIN_BIAS_BYTE3_SIGN_BIT_LEN = 1,

            DRAM_DFE_GAIN_BIAS_BYTE4_BYTE = 23,
            DRAM_DFE_GAIN_BIAS_BYTE4_START = 0,
            DRAM_DFE_GAIN_BIAS_BYTE4_LEN = 8,
            DRAM_DFE_GAIN_BIAS_BYTE4_SIGN_BIT_START = 4,
            DRAM_DFE_GAIN_BIAS_BYTE4_SIGN_BIT_LEN = 1,

            DRAM_DFE_GAIN_BIAS_BYTE5_BYTE = 24,
            DRAM_DFE_GAIN_BIAS_BYTE5_START = 0,
            DRAM_DFE_GAIN_BIAS_BYTE5_LEN = 8,
            DRAM_DFE_GAIN_BIAS_BYTE5_SIGN_BIT_START = 4,
            DRAM_DFE_GAIN_BIAS_BYTE5_SIGN_BIT_LEN = 1,

            DRAM_DFE_GAIN_BIAS_BYTE6_BYTE = 25,
            DRAM_DFE_GAIN_BIAS_BYTE6_START = 5,
            DRAM_DFE_GAIN_BIAS_BYTE6_LEN = 3,
            DRAM_DFE_GAIN_BIAS_BYTE6_SIGN_BIT_START = 4,
            DRAM_DFE_GAIN_BIAS_BYTE6_SIGN_BIT_LEN = 1,

            DRAM_DFE_GAIN_BIAS_BYTE7_BYTE = 26,
            DRAM_DFE_GAIN_BIAS_BYTE7_START = 5,
            DRAM_DFE_GAIN_BIAS_BYTE7_LEN = 3,
            DRAM_DFE_GAIN_BIAS_BYTE7_SIGN_BIT_START = 4,
            DRAM_DFE_GAIN_BIAS_BYTE7_SIGN_BIT_LEN = 1,

            // Byte 27: PHY ODT impedance
            PHY_ODT_IMPEDANCE_BYTE = 27,
            PHY_ODT_IMPEDANCE_START = 3,
            PHY_ODT_IMPEDANCE_LEN = 5,

            // Byte 28: PHY Drive impedance
            PHY_DRIVE_IMPEDANCE_CTRL0_BYTE = 28,
            PHY_DRIVE_IMPEDANCE_CTRL0_START = 3,
            PHY_DRIVE_IMPEDANCE_CTRL0_LEN = 5,

            // Byte 29: PHY Drive impedance
            PHY_DRIVE_IMPEDANCE_CTRL1_BYTE = 29,
            PHY_DRIVE_IMPEDANCE_CTRL1_START = 3,
            PHY_DRIVE_IMPEDANCE_CTRL1_LEN = 5,

            // Byte 30: PHY DRV impedance
            PHY_DRIVE_IMPEDANCE_CTRL2_BYTE = 30,
            PHY_DRIVE_IMPEDANCE_CTRL2_START = 3,
            PHY_DRIVE_IMPEDANCE_CTRL2_LEN = 5,

            // Byte 31: PHY Slew Rate DQ_DQS
            PHY_SLEW_RATE_DQ_DQS_BYTE = 31,
            PHY_SLEW_RATE_DQ_DQS_START = 4,
            PHY_SLEW_RATE_DQ_DQS_LEN = 4,

            // Byte 32: ATX impedance
            ATX_IMPEDANCE_BYTE = 32,
            ATX_IMPEDANCE_START = 4,
            ATX_IMPEDANCE_LEN = 4,

            // Byte 33-36: ATX Slew rise rate
            ATX_SLEW_RISE_RATE_BYTE0_BYTE = 33,
            ATX_SLEW_RISE_RATE_BYTE0_START = 0,
            ATX_SLEW_RISE_RATE_BYTE0_LEN = 8,

            ATX_SLEW_RISE_RATE_BYTE1_BYTE = 34,
            ATX_SLEW_RISE_RATE_BYTE1_START = 0,
            ATX_SLEW_RISE_RATE_BYTE1_LEN = 8,

            ATX_SLEW_RISE_RATE_BYTE2_BYTE = 35,
            ATX_SLEW_RISE_RATE_BYTE2_START = 0,
            ATX_SLEW_RISE_RATE_BYTE2_LEN = 8,

            ATX_SLEW_RISE_RATE_BYTE3_BYTE = 36,
            ATX_SLEW_RISE_RATE_BYTE3_START = 0,
            ATX_SLEW_RISE_RATE_BYTE3_LEN = 8,

            // Byte 37-40: ATX Slew rate fall
            ATX_SLEW_FALL_RATE_BYTE0_BYTE = 37,
            ATX_SLEW_FALL_RATE_BYTE0_START = 0,
            ATX_SLEW_FALL_RATE_BYTE0_LEN = 8,

            ATX_SLEW_FALL_RATE_BYTE1_BYTE = 38,
            ATX_SLEW_FALL_RATE_BYTE1_START = 0,
            ATX_SLEW_FALL_RATE_BYTE1_LEN = 8,

            ATX_SLEW_FALL_RATE_BYTE2_BYTE = 39,
            ATX_SLEW_FALL_RATE_BYTE2_START = 0,
            ATX_SLEW_FALL_RATE_BYTE2_LEN = 8,

            ATX_SLEW_FALL_RATE_BYTE3_BYTE = 40,
            ATX_SLEW_FALL_RATE_BYTE3_START = 0,
            ATX_SLEW_FALL_RATE_BYTE3_LEN = 8,

            // Byte 41-44: CK Slew rate rise
            CK_SLEW_RATE_RISE_BYTE0_BYTE = 41,
            CK_SLEW_RATE_RISE_BYTE0_START = 0,
            CK_SLEW_RATE_RISE_BYTE0_LEN = 8,

            CK_SLEW_RATE_RISE_BYTE1_BYTE = 42,
            CK_SLEW_RATE_RISE_BYTE1_START = 0,
            CK_SLEW_RATE_RISE_BYTE1_LEN = 8,

            CK_SLEW_RATE_RISE_BYTE2_BYTE = 43,
            CK_SLEW_RATE_RISE_BYTE2_START = 0,
            CK_SLEW_RATE_RISE_BYTE2_LEN = 8,

            CK_SLEW_RATE_RISE_BYTE3_BYTE = 44,
            CK_SLEW_RATE_RISE_BYTE3_START = 0,
            CK_SLEW_RATE_RISE_BYTE3_LEN = 8,

            // Byte 45-48: CK Slew rate fall
            CK_SLEW_RATE_FALL_BYTE0_BYTE = 45,
            CK_SLEW_RATE_FALL_BYTE0_START = 0,
            CK_SLEW_RATE_FALL_BYTE0_LEN = 8,

            CK_SLEW_RATE_FALL_BYTE1_BYTE = 46,
            CK_SLEW_RATE_FALL_BYTE1_START = 0,
            CK_SLEW_RATE_FALL_BYTE1_LEN = 8,

            CK_SLEW_RATE_FALL_BYTE2_BYTE = 47,
            CK_SLEW_RATE_FALL_BYTE2_START = 0,
            CK_SLEW_RATE_FALL_BYTE2_LEN = 8,

            CK_SLEW_RATE_FALL_BYTE3_BYTE = 48,
            CK_SLEW_RATE_FALL_BYTE3_START = 0,
            CK_SLEW_RATE_FALL_BYTE3_LEN = 8,

            // Byte 49-52: DQ Slew rate rise
            DQ_SLEW_RATE_RISE_BYTE0_BYTE = 49,
            DQ_SLEW_RATE_RISE_BYTE0_START = 0,
            DQ_SLEW_RATE_RISE_BYTE0_LEN = 8,

            DQ_SLEW_RATE_RISE_BYTE1_BYTE = 50,
            DQ_SLEW_RATE_RISE_BYTE1_START = 0,
            DQ_SLEW_RATE_RISE_BYTE1_LEN = 8,

            DQ_SLEW_RATE_RISE_BYTE2_BYTE = 51,
            DQ_SLEW_RATE_RISE_BYTE2_START = 0,
            DQ_SLEW_RATE_RISE_BYTE2_LEN = 8,

            DQ_SLEW_RATE_RISE_BYTE3_BYTE = 52,
            DQ_SLEW_RATE_RISE_BYTE3_START = 0,
            DQ_SLEW_RATE_RISE_BYTE3_LEN = 8,

            // Byte 53-56: DQ Slew rate fall
            DQ_SLEW_RATE_FALL_BYTE0_BYTE = 53,
            DQ_SLEW_RATE_FALL_BYTE0_START = 0,
            DQ_SLEW_RATE_FALL_BYTE0_LEN = 8,

            DQ_SLEW_RATE_FALL_BYTE1_BYTE = 54,
            DQ_SLEW_RATE_FALL_BYTE1_START = 0,
            DQ_SLEW_RATE_FALL_BYTE1_LEN = 8,

            DQ_SLEW_RATE_FALL_BYTE2_BYTE = 55,
            DQ_SLEW_RATE_FALL_BYTE2_START = 0,
            DQ_SLEW_RATE_FALL_BYTE2_LEN = 8,

            DQ_SLEW_RATE_FALL_BYTE3_BYTE = 56,
            DQ_SLEW_RATE_FALL_BYTE3_START = 0,
            DQ_SLEW_RATE_FALL_BYTE3_LEN = 8,

            // Byte 57: CK Impedance
            CK_IMPEDANCE_BYTE = 57,
            CK_IMPEDANCE_START = 4,
            CK_IMPEDANCE_LEN = 4,

            // Byte 58: CK Slew Rate
            CK_SLEW_RATE_BYTE = 58,
            CK_SLEW_RATE_START = 4,
            CK_SLEW_RATE_LEN = 4,

            // Byte 60-67: RTT PARK and WR
            // BYTE0: A0 RANK0
            // BYTE1: A0 RANK1
            // BYTE2: B0 RANK0
            // BYTE3: B0 RANK1
            // BYTE4: A1 RANK0
            // BYTE5: A1 RANK1
            // BYTE6: B2 RANK0
            // BYTE7: B2 RANK1
            DRAM_RTT_PARK_WR_BYTE0_BYTE = 60,
            DRAM_RTT_PARK_BYTE0_START = 5,
            DRAM_RTT_PARK_BYTE0_LEN = 3,
            DRAM_RTT_WR_BYTE0_START = 2,
            DRAM_RTT_WR_BYTE0_LEN = 3,

            DRAM_RTT_PARK_WR_BYTE1_BYTE = 61,
            DRAM_RTT_PARK_BYTE1_START = 5,
            DRAM_RTT_PARK_BYTE1_LEN = 3,
            DRAM_RTT_WR_BYTE1_START = 2,
            DRAM_RTT_WR_BYTE1_LEN = 3,

            DRAM_RTT_PARK_WR_BYTE2_BYTE = 62,
            DRAM_RTT_PARK_BYTE2_START = 5,
            DRAM_RTT_PARK_BYTE2_LEN = 3,
            DRAM_RTT_WR_BYTE2_START = 2,
            DRAM_RTT_WR_BYTE2_LEN = 3,

            DRAM_RTT_PARK_WR_BYTE3_BYTE = 63,
            DRAM_RTT_PARK_BYTE3_START = 5,
            DRAM_RTT_PARK_BYTE3_LEN = 3,
            DRAM_RTT_WR_BYTE3_START = 2,
            DRAM_RTT_WR_BYTE3_LEN = 3,

            DRAM_RTT_PARK_WR_BYTE4_BYTE = 64,
            DRAM_RTT_PARK_BYTE4_START = 5,
            DRAM_RTT_PARK_BYTE4_LEN = 3,
            DRAM_RTT_WR_BYTE4_START = 2,
            DRAM_RTT_WR_BYTE4_LEN = 3,

            DRAM_RTT_PARK_WR_BYTE5_BYTE = 65,
            DRAM_RTT_PARK_BYTE5_START = 5,
            DRAM_RTT_PARK_BYTE5_LEN = 3,
            DRAM_RTT_WR_BYTE5_START = 2,
            DRAM_RTT_WR_BYTE5_LEN = 3,

            DRAM_RTT_PARK_WR_BYTE6_BYTE = 66,
            DRAM_RTT_PARK_BYTE6_START = 5,
            DRAM_RTT_PARK_BYTE6_LEN = 3,
            DRAM_RTT_WR_BYTE6_START = 2,
            DRAM_RTT_WR_BYTE6_LEN = 3,

            DRAM_RTT_PARK_WR_BYTE7_BYTE = 67,
            DRAM_RTT_PARK_BYTE7_START = 5,
            DRAM_RTT_PARK_BYTE7_LEN = 3,
            DRAM_RTT_WR_BYTE7_START = 2,
            DRAM_RTT_WR_BYTE7_LEN = 3,


            // Byte 68-75: DRAM RTT Nom
            // BYTE0: A0 RANK0
            // BYTE1: A0 RANK1
            // BYTE2: B0 RANK0
            // BYTE3: B0 RANK1
            // BYTE4: A1 RANK0
            // BYTE5: A1 RANK1
            // BYTE6: B2 RANK0
            // BYTE7: B2 RANK1
            DRAM_RTT_NOM_BYTE0_BYTE = 68,
            DRAM_RTT_NOM_BYTE0_WR_START = 5,
            DRAM_RTT_NOM_BYTE0_WR_LEN = 3,
            DRAM_RTT_NOM_BYTE0_RD_START = 2,
            DRAM_RTT_NOM_BYTE0_RD_LEN = 3,

            DRAM_RTT_NOM_BYTE1_BYTE = 69,
            DRAM_RTT_NOM_BYTE1_WR_START = 5,
            DRAM_RTT_NOM_BYTE1_WR_LEN = 3,
            DRAM_RTT_NOM_BYTE1_RD_START = 2,
            DRAM_RTT_NOM_BYTE1_RD_LEN = 3,

            DRAM_RTT_NOM_BYTE2_BYTE = 70,
            DRAM_RTT_NOM_BYTE2_WR_START = 5,
            DRAM_RTT_NOM_BYTE2_WR_LEN = 3,
            DRAM_RTT_NOM_BYTE2_RD_START = 2,
            DRAM_RTT_NOM_BYTE2_RD_LEN = 3,

            DRAM_RTT_NOM_BYTE3_BYTE = 71,
            DRAM_RTT_NOM_BYTE3_WR_START = 5,
            DRAM_RTT_NOM_BYTE3_WR_LEN = 3,
            DRAM_RTT_NOM_BYTE3_RD_START = 2,
            DRAM_RTT_NOM_BYTE3_RD_LEN = 3,

            DRAM_RTT_NOM_BYTE4_BYTE = 72,
            DRAM_RTT_NOM_BYTE4_WR_START = 5,
            DRAM_RTT_NOM_BYTE4_WR_LEN = 3,
            DRAM_RTT_NOM_BYTE4_RD_START = 2,
            DRAM_RTT_NOM_BYTE4_RD_LEN = 3,

            DRAM_RTT_NOM_BYTE5_BYTE = 73,
            DRAM_RTT_NOM_BYTE5_WR_START = 5,
            DRAM_RTT_NOM_BYTE5_WR_LEN = 3,
            DRAM_RTT_NOM_BYTE5_RD_START = 2,
            DRAM_RTT_NOM_BYTE5_RD_LEN = 3,

            DRAM_RTT_NOM_BYTE6_BYTE = 74,
            DRAM_RTT_NOM_BYTE6_WR_START = 5,
            DRAM_RTT_NOM_BYTE6_WR_LEN = 3,
            DRAM_RTT_NOM_BYTE6_RD_START = 2,
            DRAM_RTT_NOM_BYTE6_RD_LEN = 3,

            DRAM_RTT_NOM_BYTE7_BYTE = 75,
            DRAM_RTT_NOM_BYTE7_WR_START = 5,
            DRAM_RTT_NOM_BYTE7_WR_LEN = 3,
            DRAM_RTT_NOM_BYTE7_RD_START = 2,
            DRAM_RTT_NOM_BYTE7_RD_LEN = 3,

            // Byte 76: PHY Equalization
            PHY_EQUALIZATION_BYTE = 76,
            PHY_EQUALIZATION_DFFE_START = 6,
            PHY_EQUALIZATION_DFFE_LEN = 1,
            PHY_EQUALIZATION_RDFE_START = 7,
            PHY_EQUALIZATION_RDFE_LEN = 1,

            // Byte 77: Non-Target ODT RD/WR
            NT_ODT_BYTE = 77,
            NT_ODT_RD_A0_B0_RANK0_START = 7,
            NT_ODT_RD_A0_B0_RANK0_LEN = 1,
            NT_ODT_WR_A0_B0_RANK0_START = 6,
            NT_ODT_WR_A0_B0_RANK0_LEN = 1,
            NT_ODT_RD_A1_B1_RANK0_START = 5,
            NT_ODT_RD_A1_B1_RANK0_LEN = 1,
            NT_ODT_WR_A1_B1_RANK0_START = 4,
            NT_ODT_WR_A1_B1_RANK0_LEN = 1,
            NT_ODT_RD_A0_B0_RANK1_START = 3,
            NT_ODT_RD_A0_B0_RANK1_LEN = 1,
            NT_ODT_WR_A0_B0_RANK1_START = 2,
            NT_ODT_WR_A0_B0_RANK1_LEN = 1,
            NT_ODT_RD_A1_B1_RANK1_START = 1,
            NT_ODT_RD_A1_B1_RANK1_LEN = 1,
            NT_ODT_WR_A1_B1_RANK1_START = 0,
            NT_ODT_WR_A1_B1_RANK1_LEN = 1,

            // Byte 78: DFI Max Read Latency
            DFI_MAX_RD_LATENCY_BYTE = 78,
            DFIMRL_DDRCLK_START = 3,
            DFIMRL_DDRCLK_LEN = 5,

            // Byte 82-89: Group A CK/CS ODT and CA
            // BYTE0: A0 RANK0
            // BYTE1: A0 RANK1
            // BYTE2: B0 RANK0
            // BYTE3: B0 RANK1
            // BYTE4: A1 RANK0
            // BYTE5: A1 RANK1
            // BYTE6: B2 RANK0
            // BYTE7: B2 RANK1
            ODT_CA_GRPA_BYTE0_BYTE = 82,
            ODT_CA_GRPA_CK_BYTE0_START = 5,
            ODT_CA_GRPA_CK_BYTE0_LEN = 3,
            ODT_CA_GRPA_CS_BYTE0_START = 2,
            ODT_CA_GRPA_CS_BYTE0_LEN = 3,

            ODT_CA_GRPA_BYTE1_BYTE = 83,
            ODT_CA_GRPA_CK_BYTE1_START = 5,
            ODT_CA_GRPA_CK_BYTE1_LEN = 3,
            ODT_CA_GRPA_CS_BYTE1_START = 2,
            ODT_CA_GRPA_CS_BYTE1_LEN = 3,

            ODT_CA_GRPA_BYTE2_BYTE = 84,
            ODT_CA_GRPA_CK_BYTE2_START = 5,
            ODT_CA_GRPA_CK_BYTE2_LEN = 3,
            ODT_CA_GRPA_CS_BYTE2_START = 2,
            ODT_CA_GRPA_CS_BYTE2_LEN = 3,

            ODT_CA_GRPA_BYTE3_BYTE = 85,
            ODT_CA_GRPA_CK_BYTE3_START = 5,
            ODT_CA_GRPA_CK_BYTE3_LEN = 3,
            ODT_CA_GRPA_CS_BYTE3_START = 2,
            ODT_CA_GRPA_CS_BYTE3_LEN = 3,

            ODT_CA_GRPA_BYTE4_BYTE = 86,
            ODT_CA_GRPA_CK_BYTE4_START = 5,
            ODT_CA_GRPA_CK_BYTE4_LEN = 3,
            ODT_CA_GRPA_CS_BYTE4_START = 2,
            ODT_CA_GRPA_CS_BYTE4_LEN = 3,

            ODT_CA_GRPA_BYTE5_BYTE = 87,
            ODT_CA_GRPA_CK_BYTE5_START = 5,
            ODT_CA_GRPA_CK_BYTE5_LEN = 3,
            ODT_CA_GRPA_CS_BYTE5_START = 2,
            ODT_CA_GRPA_CS_BYTE5_LEN = 3,

            ODT_CA_GRPA_BYTE6_BYTE = 88,
            ODT_CA_GRPA_CK_BYTE6_START = 5,
            ODT_CA_GRPA_CK_BYTE6_LEN = 3,
            ODT_CA_GRPA_CS_BYTE6_START = 2,
            ODT_CA_GRPA_CS_BYTE6_LEN = 3,

            ODT_CA_GRPA_BYTE7_BYTE = 89,
            ODT_CA_GRPA_CK_BYTE7_START = 5,
            ODT_CA_GRPA_CK_BYTE7_LEN = 3,
            ODT_CA_GRPA_CS_BYTE7_START = 2,
            ODT_CA_GRPA_CS_BYTE7_LEN = 3,

            // Byte 90-97: Group B CK/CS ODT and CA
            // BYTE0: A0 RANK0
            // BYTE1: A0 RANK1
            // BYTE2: B0 RANK0
            // BYTE3: B0 RANK1
            // BYTE4: A1 RANK0
            // BYTE5: A1 RANK1
            // BYTE6: B1 RANK0
            // BYTE7: B1 RANK1
            ODT_CA_GRPB_BYTE0_BYTE = 90,
            ODT_CA_GRPB_CK_BYTE0_START = 5,
            ODT_CA_GRPB_CK_BYTE0_LEN = 3,
            ODT_CA_GRPB_CS_BYTE0_START = 2,
            ODT_CA_GRPB_CS_BYTE0_LEN = 3,

            ODT_CA_GRPB_BYTE1_BYTE = 91,
            ODT_CA_GRPB_CK_BYTE1_START = 5,
            ODT_CA_GRPB_CK_BYTE1_LEN = 3,
            ODT_CA_GRPB_CS_BYTE1_START = 2,
            ODT_CA_GRPB_CS_BYTE1_LEN = 3,

            ODT_CA_GRPB_BYTE2_BYTE = 92,
            ODT_CA_GRPB_CK_BYTE2_START = 5,
            ODT_CA_GRPB_CK_BYTE2_LEN = 3,
            ODT_CA_GRPB_CS_BYTE2_START = 2,
            ODT_CA_GRPB_CS_BYTE2_LEN = 3,

            ODT_CA_GRPB_BYTE3_BYTE = 93,
            ODT_CA_GRPB_CK_BYTE3_START = 5,
            ODT_CA_GRPB_CK_BYTE3_LEN = 3,
            ODT_CA_GRPB_CS_BYTE3_START = 2,
            ODT_CA_GRPB_CS_BYTE3_LEN = 3,

            ODT_CA_GRPB_BYTE4_BYTE = 94,
            ODT_CA_GRPB_CK_BYTE4_START = 5,
            ODT_CA_GRPB_CK_BYTE4_LEN = 3,
            ODT_CA_GRPB_CS_BYTE4_START = 2,
            ODT_CA_GRPB_CS_BYTE4_LEN = 3,

            ODT_CA_GRPB_BYTE5_BYTE = 95,
            ODT_CA_GRPB_CK_BYTE5_START = 5,
            ODT_CA_GRPB_CK_BYTE5_LEN = 3,
            ODT_CA_GRPB_CS_BYTE5_START = 2,
            ODT_CA_GRPB_CS_BYTE5_LEN = 3,

            ODT_CA_GRPB_BYTE6_BYTE = 96,
            ODT_CA_GRPB_CK_BYTE6_START = 5,
            ODT_CA_GRPB_CK_BYTE6_LEN = 3,
            ODT_CA_GRPB_CS_BYTE6_START = 2,
            ODT_CA_GRPB_CS_BYTE6_LEN = 3,

            ODT_CA_GRPB_BYTE7_BYTE = 97,
            ODT_CA_GRPB_CK_BYTE7_START = 5,
            ODT_CA_GRPB_CK_BYTE7_LEN = 3,
            ODT_CA_GRPB_CS_BYTE7_START = 2,
            ODT_CA_GRPB_CS_BYTE7_LEN = 3,

            // Byte 98-177: CK/CS ODT and CA per DRAM
            // Channel incr 20
            // Rank incr 10
            // DRAM incr 1
            // BYTE0-BYTE9  : A0 RANK0
            // BYTE10-BYTE19: A0 RANK1
            // BYTE20-BYTE29: B0 RANK0
            // BYTE30-BYTE39: B0 RANK1
            // BYTE40-BYTE49: A1 RANK0
            // BYTE50-BYTE59: A1 RANK1
            // BYTE60-BYTE69: B1 RANK0
            // BYTE70-BYTE79: B1 RANK1
            ODT_CA_BYTE0_BYTE = 98,
            ODT_CA_CK_BYTE0_START = 5,
            ODT_CA_CK_BYTE0_LEN = 3,
            ODT_CA_CS_BYTE0_START = 2,
            ODT_CA_CS_BYTE0_LEN = 3,
            ODT_CA_BYTE0_EXP_GRP_START = 1,
            ODT_CA_BYTE0_EXP_GRP_LEN = 1,

            // Byte 178-185: CA ODT and DQS for GROUPA
            // BYTE0: A0 RANK0
            // BYTE1: A0 RANK1
            // BYTE2: B0 RANK0
            // BYTE3: B0 RANK1
            // BYTE4: A1 RANK0
            // BYTE5: A1 RANK1
            // BYTE6: B2 RANK0
            // BYTE7: B2 RANK1
            CA_ODT_DQS_GRPA_BYTE0_BYTE = 178,
            CA_ODT_GRPA_BYTE0_START = 5,
            CA_ODT_GRPA_BYTE0_LEN = 3,
            DQS_RTT_PARK_GRPA_BYTE0_START = 2,
            DQS_RTT_PARK_GRPA_BYTE0_LEN = 3,

            CA_ODT_DQS_GRPA_BYTE1_BYTE = 179,
            CA_ODT_GRPA_BYTE1_START = 5,
            CA_ODT_GRPA_BYTE1_LEN = 3,
            DQS_RTT_PARK_GRPA_BYTE1_START = 2,
            DQS_RTT_PARK_GRPA_BYTE1_LEN = 3,

            CA_ODT_DQS_GRPA_BYTE2_BYTE = 180,
            CA_ODT_GRPA_BYTE2_START = 5,
            CA_ODT_GRPA_BYTE2_LEN = 3,
            DQS_RTT_PARK_GRPA_BYTE2_START = 2,
            DQS_RTT_PARK_GRPA_BYTE2_LEN = 3,

            CA_ODT_DQS_GRPA_BYTE3_BYTE = 181,
            CA_ODT_GRPA_BYTE3_START = 5,
            CA_ODT_GRPA_BYTE3_LEN = 3,
            DQS_RTT_PARK_GRPA_BYTE3_START = 2,
            DQS_RTT_PARK_GRPA_BYTE3_LEN = 3,

            CA_ODT_DQS_GRPA_BYTE4_BYTE = 182,
            CA_ODT_GRPA_BYTE4_START = 5,
            CA_ODT_GRPA_BYTE4_LEN = 3,
            DQS_RTT_PARK_GRPA_BYTE4_START = 2,
            DQS_RTT_PARK_GRPA_BYTE4_LEN = 3,

            CA_ODT_DQS_GRPA_BYTE5_BYTE = 183,
            CA_ODT_GRPA_BYTE5_START = 5,
            CA_ODT_GRPA_BYTE5_LEN = 3,
            DQS_RTT_PARK_GRPA_BYTE5_START = 2,
            DQS_RTT_PARK_GRPA_BYTE5_LEN = 3,

            CA_ODT_DQS_GRPA_BYTE6_BYTE = 184,
            CA_ODT_GRPA_BYTE6_START = 5,
            CA_ODT_GRPA_BYTE6_LEN = 3,
            DQS_RTT_PARK_GRPA_BYTE6_START = 2,
            DQS_RTT_PARK_GRPA_BYTE6_LEN = 3,

            CA_ODT_DQS_GRPA_BYTE7_BYTE = 185,
            CA_ODT_GRPA_BYTE7_START = 5,
            CA_ODT_GRPA_BYTE7_LEN = 3,
            DQS_RTT_PARK_GRPA_BYTE7_START = 2,
            DQS_RTT_PARK_GRPA_BYTE7_LEN = 3,

            // Byte 186-193: CA ODT and DQS for GROUPB
            // BYTE0: A0 RANK0
            // BYTE1: A0 RANK1
            // BYTE2: B0 RANK0
            // BYTE3: B0 RANK1
            // BYTE4: A1 RANK0
            // BYTE5: A1 RANK1
            // BYTE6: B2 RANK0
            // BYTE7: B2 RANK1
            CA_ODT_DQS_GRPB_BYTE0_BYTE = 186,
            CA_ODT_GRPB_BYTE0_START = 5,
            CA_ODT_GRPB_BYTE0_LEN = 3,
            DQS_RTT_PARK_GRPB_BYTE0_START = 2,
            DQS_RTT_PARK_GRPB_BYTE0_LEN = 3,

            CA_ODT_DQS_GRPB_BYTE1_BYTE = 187,
            CA_ODT_GRPB_BYTE1_START = 5,
            CA_ODT_GRPB_BYTE1_LEN = 3,
            DQS_RTT_PARK_GRPB_BYTE1_START = 2,
            DQS_RTT_PARK_GRPB_BYTE1_LEN = 3,

            CA_ODT_DQS_GRPB_BYTE2_BYTE = 188,
            CA_ODT_GRPB_BYTE2_START = 5,
            CA_ODT_GRPB_BYTE2_LEN = 3,
            DQS_RTT_PARK_GRPB_BYTE2_START = 2,
            DQS_RTT_PARK_GRPB_BYTE2_LEN = 3,

            CA_ODT_DQS_GRPB_BYTE3_BYTE = 189,
            CA_ODT_GRPB_BYTE3_START = 5,
            CA_ODT_GRPB_BYTE3_LEN = 3,
            DQS_RTT_PARK_GRPB_BYTE3_START = 2,
            DQS_RTT_PARK_GRPB_BYTE3_LEN = 3,

            CA_ODT_DQS_GRPB_BYTE4_BYTE = 190,
            CA_ODT_GRPB_BYTE4_START = 5,
            CA_ODT_GRPB_BYTE4_LEN = 3,
            DQS_RTT_PARK_GRPB_BYTE4_START = 2,
            DQS_RTT_PARK_GRPB_BYTE4_LEN = 3,

            CA_ODT_DQS_GRPB_BYTE5_BYTE = 191,
            CA_ODT_GRPB_BYTE5_START = 5,
            CA_ODT_GRPB_BYTE5_LEN = 3,
            DQS_RTT_PARK_GRPB_BYTE5_START = 2,
            DQS_RTT_PARK_GRPB_BYTE5_LEN = 3,

            CA_ODT_DQS_GRPB_BYTE6_BYTE = 192,
            CA_ODT_GRPB_BYTE6_START = 5,
            CA_ODT_GRPB_BYTE6_LEN = 3,
            DQS_RTT_PARK_GRPB_BYTE6_START = 2,
            DQS_RTT_PARK_GRPB_BYTE6_LEN = 3,

            CA_ODT_DQS_GRPB_BYTE7_BYTE = 193,
            CA_ODT_GRPB_BYTE7_START = 5,
            CA_ODT_GRPB_BYTE7_LEN = 3,
            DQS_RTT_PARK_GRPB_BYTE7_START = 2,
            DQS_RTT_PARK_GRPB_BYTE7_LEN = 3,

            // Byte 194-273: CA ODT and DQS per DRAM
            // BYTE0-BYTE9  : A0 RANK0
            // BYTE10-BYTE19: A0 RANK1
            // BYTE20-BYTE29: B0 RANK0
            // BYTE30-BYTE39: B0 RANK1
            // BYTE40-BYTE49: A1 RANK0
            // BYTE50-BYTE59: A1 RANK1
            // BYTE60-BYTE69: B1 RANK0
            // BYTE70-BYTE79: B1 RANK1
            CA_ODT_DQS_BYTE0_BYTE = 194,
            CA_ODT_BYTE0_START = 5,
            CA_ODT_BYTE0_LEN = 3,
            DQS_RTT_PARK_BYTE0_START = 2,
            DQS_RTT_PARK_BYTE0_LEN = 3,

            // Byte 274-281: ODTL Write Control Offset
            // BYTE0: A0 RANK0
            // BYTE1: A0 RANK1
            // BYTE2: B0 RANK0
            // BYTE3: B0 RANK1
            // BYTE4: A1 RANK0
            // BYTE5: A1 RANK1
            // BYTE6: B2 RANK0
            // BYTE7: B2 RANK1
            ODTL_WR_CNTRL_OFFSET_BYTE0_BYTE = 274,
            ODTL_WR_CNTRL_ON_OFFSET_BYTE0_START = 5,
            ODTL_WR_CNTRL_ON_OFFSET_BYTE0_LEN = 3,
            ODTL_WR_CNTRL_OFF_OFFSET_BYTE0_START = 2,
            ODTL_WR_CNTRL_OFF_OFFSET_BYTE0_LEN = 3,

            ODTL_WR_CNTRL_OFFSET_BYTE1_BYTE = 275,
            ODTL_WR_CNTRL_ON_OFFSET_BYTE1_START = 5,
            ODTL_WR_CNTRL_ON_OFFSET_BYTE1_LEN = 3,
            ODTL_WR_CNTRL_OFF_OFFSET_BYTE1_START = 2,
            ODTL_WR_CNTRL_OFF_OFFSET_BYTE1_LEN = 3,

            ODTL_WR_CNTRL_OFFSET_BYTE2_BYTE = 276,
            ODTL_WR_CNTRL_ON_OFFSET_BYTE2_START = 5,
            ODTL_WR_CNTRL_ON_OFFSET_BYTE2_LEN = 3,
            ODTL_WR_CNTRL_OFF_OFFSET_BYTE2_START = 2,
            ODTL_WR_CNTRL_OFF_OFFSET_BYTE2_LEN = 3,

            ODTL_WR_CNTRL_OFFSET_BYTE3_BYTE = 277,
            ODTL_WR_CNTRL_ON_OFFSET_BYTE3_START = 5,
            ODTL_WR_CNTRL_ON_OFFSET_BYTE3_LEN = 3,
            ODTL_WR_CNTRL_OFF_OFFSET_BYTE3_START = 2,
            ODTL_WR_CNTRL_OFF_OFFSET_BYTE3_LEN = 3,

            ODTL_WR_CNTRL_OFFSET_BYTE4_BYTE = 278,
            ODTL_WR_CNTRL_ON_OFFSET_BYTE4_START = 5,
            ODTL_WR_CNTRL_ON_OFFSET_BYTE4_LEN = 3,
            ODTL_WR_CNTRL_OFF_OFFSET_BYTE4_START = 2,
            ODTL_WR_CNTRL_OFF_OFFSET_BYTE4_LEN = 3,

            ODTL_WR_CNTRL_OFFSET_BYTE5_BYTE = 279,
            ODTL_WR_CNTRL_ON_OFFSET_BYTE5_START = 5,
            ODTL_WR_CNTRL_ON_OFFSET_BYTE5_LEN = 3,
            ODTL_WR_CNTRL_OFF_OFFSET_BYTE5_START = 2,
            ODTL_WR_CNTRL_OFF_OFFSET_BYTE5_LEN = 3,

            ODTL_WR_CNTRL_OFFSET_BYTE6_BYTE = 280,
            ODTL_WR_CNTRL_ON_OFFSET_BYTE6_START = 5,
            ODTL_WR_CNTRL_ON_OFFSET_BYTE6_LEN = 3,
            ODTL_WR_CNTRL_OFF_OFFSET_BYTE6_START = 2,
            ODTL_WR_CNTRL_OFF_OFFSET_BYTE6_LEN = 3,

            ODTL_WR_CNTRL_OFFSET_BYTE7_BYTE = 281,
            ODTL_WR_CNTRL_ON_OFFSET_BYTE7_START = 5,
            ODTL_WR_CNTRL_ON_OFFSET_BYTE7_LEN = 3,
            ODTL_WR_CNTRL_OFF_OFFSET_BYTE7_START = 2,
            ODTL_WR_CNTRL_OFF_OFFSET_BYTE7_LEN = 3,

            // Byte 282-289: ODTL NT Write Control Offset
            // BYTE0: A0 RANK0
            // BYTE1: A0 RANK1
            // BYTE2: B0 RANK0
            // BYTE3: B0 RANK1
            // BYTE4: A1 RANK0
            // BYTE5: A1 RANK1
            // BYTE6: B2 RANK0
            // BYTE7: B2 RANK1
            ODTL_NT_WR_CNTRL_OFFSET_BYTE0_BYTE = 282,
            ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE0_START = 5,
            ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE0_LEN = 3,
            ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE0_START = 2,
            ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE0_LEN = 3,

            ODTL_NT_WR_CNTRL_OFFSET_BYTE1_BYTE = 283,
            ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE1_START = 5,
            ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE1_LEN = 3,
            ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE1_START = 2,
            ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE1_LEN = 3,

            ODTL_NT_WR_CNTRL_OFFSET_BYTE2_BYTE = 284,
            ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE2_START = 5,
            ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE2_LEN = 3,
            ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE2_START = 2,
            ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE2_LEN = 3,

            ODTL_NT_WR_CNTRL_OFFSET_BYTE3_BYTE = 285,
            ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE3_START = 5,
            ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE3_LEN = 3,
            ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE3_START = 2,
            ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE3_LEN = 3,

            ODTL_NT_WR_CNTRL_OFFSET_BYTE4_BYTE = 286,
            ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE4_START = 5,
            ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE4_LEN = 3,
            ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE4_START = 2,
            ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE4_LEN = 3,

            ODTL_NT_WR_CNTRL_OFFSET_BYTE5_BYTE = 287,
            ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE5_START = 5,
            ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE5_LEN = 3,
            ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE5_START = 2,
            ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE5_LEN = 3,

            ODTL_NT_WR_CNTRL_OFFSET_BYTE6_BYTE = 288,
            ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE6_START = 5,
            ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE6_LEN = 3,
            ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE6_START = 2,
            ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE6_LEN = 3,

            ODTL_NT_WR_CNTRL_OFFSET_BYTE7_BYTE = 289,
            ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE7_START = 5,
            ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE7_LEN = 3,
            ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE7_START = 2,
            ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE7_LEN = 3,

            // Byte 290-297: ODTL NT Read Control Offset
            // BYTE0: A0 RANK0
            // BYTE1: A0 RANK1
            // BYTE2: B0 RANK0
            // BYTE3: B0 RANK1
            // BYTE4: A1 RANK0
            // BYTE5: A1 RANK1
            // BYTE6: B2 RANK0
            // BYTE7: B2 RANK1
            ODTL_NT_RD_CNTRL_OFFSET_BYTE0_BYTE = 290,
            ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE0_START = 5,
            ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE0_LEN = 3,
            ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE0_START = 2,
            ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE0_LEN = 3,

            ODTL_NT_RD_CNTRL_OFFSET_BYTE1_BYTE = 291,
            ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE1_START = 5,
            ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE1_LEN = 3,
            ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE1_START = 2,
            ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE1_LEN = 3,

            ODTL_NT_RD_CNTRL_OFFSET_BYTE2_BYTE = 292,
            ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE2_START = 5,
            ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE2_LEN = 3,
            ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE2_START = 2,
            ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE2_LEN = 3,

            ODTL_NT_RD_CNTRL_OFFSET_BYTE3_BYTE = 293,
            ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE3_START = 5,
            ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE3_LEN = 3,
            ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE3_START = 2,
            ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE3_LEN = 3,

            ODTL_NT_RD_CNTRL_OFFSET_BYTE4_BYTE = 294,
            ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE4_START = 5,
            ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE4_LEN = 3,
            ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE4_START = 2,
            ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE4_LEN = 3,

            ODTL_NT_RD_CNTRL_OFFSET_BYTE5_BYTE = 295,
            ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE5_START = 5,
            ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE5_LEN = 3,
            ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE5_START = 2,
            ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE5_LEN = 3,

            ODTL_NT_RD_CNTRL_OFFSET_BYTE6_BYTE = 296,
            ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE6_START = 5,
            ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE6_LEN = 3,
            ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE6_START = 2,
            ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE6_LEN = 3,

            ODTL_NT_RD_CNTRL_OFFSET_BYTE7_BYTE = 297,
            ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE7_START = 5,
            ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE7_LEN = 3,
            ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE7_START = 2,
            ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE7_LEN = 3,

            // Byte 306-313: Base Vref CA
            // BYTE0: A0 RANK0
            // BYTE1: A0 RANK1
            // BYTE2: B0 RANK0
            // BYTE3: B0 RANK1
            // BYTE4: A1 RANK0
            // BYTE5: A1 RANK1
            // BYTE6: B2 RANK0
            // BYTE7: B2 RANK1
            BASE_VREF_CA_BYTE0_BYTE = 306,
            BASE_VREF_CA_BYTE0_START = 1,
            BASE_VREF_CA_BYTE0_LEN = 7,

            BASE_VREF_CA_BYTE1_BYTE = 307,
            BASE_VREF_CA_BYTE1_START = 1,
            BASE_VREF_CA_BYTE1_LEN = 7,

            BASE_VREF_CA_BYTE2_BYTE = 308,
            BASE_VREF_CA_BYTE2_START = 1,
            BASE_VREF_CA_BYTE2_LEN = 7,

            BASE_VREF_CA_BYTE3_BYTE = 309,
            BASE_VREF_CA_BYTE3_START = 1,
            BASE_VREF_CA_BYTE3_LEN = 7,

            BASE_VREF_CA_BYTE4_BYTE = 310,
            BASE_VREF_CA_BYTE4_START = 1,
            BASE_VREF_CA_BYTE4_LEN = 7,

            BASE_VREF_CA_BYTE5_BYTE = 311,
            BASE_VREF_CA_BYTE5_START = 1,
            BASE_VREF_CA_BYTE5_LEN = 7,

            BASE_VREF_CA_BYTE6_BYTE = 312,
            BASE_VREF_CA_BYTE6_START = 1,
            BASE_VREF_CA_BYTE6_LEN = 7,

            BASE_VREF_CA_BYTE7_BYTE = 313,
            BASE_VREF_CA_BYTE7_START = 1,
            BASE_VREF_CA_BYTE7_LEN = 7,

            // Byte 314-322: Base Vref CS
            // BYTE0: A0 RANK0
            // BYTE1: A0 RANK1
            // BYTE2: B0 RANK0
            // BYTE3: B0 RANK1
            // BYTE4: A1 RANK0
            // BYTE5: A1 RANK1
            // BYTE6: B2 RANK0
            // BYTE7: B2 RANK1
            BASE_VREF_CS_BYTE0_BYTE = 314,
            BASE_VREF_CS_BYTE0_START = 1,
            BASE_VREF_CS_BYTE0_LEN = 7,

            BASE_VREF_CS_BYTE1_BYTE = 315,
            BASE_VREF_CS_BYTE1_START = 1,
            BASE_VREF_CS_BYTE1_LEN = 7,

            BASE_VREF_CS_BYTE2_BYTE = 316,
            BASE_VREF_CS_BYTE2_START = 1,
            BASE_VREF_CS_BYTE2_LEN = 7,

            BASE_VREF_CS_BYTE3_BYTE = 317,
            BASE_VREF_CS_BYTE3_START = 1,
            BASE_VREF_CS_BYTE3_LEN = 7,

            BASE_VREF_CS_BYTE4_BYTE = 318,
            BASE_VREF_CS_BYTE4_START = 1,
            BASE_VREF_CS_BYTE4_LEN = 7,

            BASE_VREF_CS_BYTE5_BYTE = 319,
            BASE_VREF_CS_BYTE5_START = 1,
            BASE_VREF_CS_BYTE5_LEN = 7,

            BASE_VREF_CS_BYTE6_BYTE = 320,
            BASE_VREF_CS_BYTE6_START = 1,
            BASE_VREF_CS_BYTE6_LEN = 7,

            BASE_VREF_CS_BYTE7_BYTE = 321,
            BASE_VREF_CS_BYTE7_START = 1,
            BASE_VREF_CS_BYTE7_LEN = 7,

            // Byte 322: Vref CA/CS Offset Multiplier
            VREF_OFFSET_MULT_BYTE = 322,
            VREF_CA_OFFSET_MULT_START = 5,
            VREF_CA_OFFSET_MULT_LEN = 3,

            VREF_CS_OFFSET_MULT_START = 1,
            VREF_CS_OFFSET_MULT_LEN = 3,

            // Byte 324-403: Vref CA/CS Offset
            // BYTE0-BYTE9  : A0 RANK0
            // BYTE9-BYTE19 : A0 RANK1
            // BYTE20-BYTE29: B0 RANK0
            // BYTE30-BYTE39: B0 RANK1
            // BYTE40-BYTE49: A1 RANK0
            // BYTE50-BYTE59: A1 RANK1
            // BYTE60-BYTE69: B2 RANK0
            // BYTE70-BYTE79: B2 RANK1
            VREF_OFFSET_MULT_BYTE0_BYTE = 324,
            VREF_CA_OFFSET_MULT_BYTE0_START = 5,
            VREF_CA_OFFSET_MULT_BYTE0_LEN = 3,
            VREF_CA_OFFSET_BYTE0_ADD_SUB_START = 4,
            VREF_CA_OFFSET_BYTE0_ADD_SUB_LEN = 1,
            VREF_CS_OFFSET_MULT_BYTE0_START = 1,
            VREF_CS_OFFSET_MULT_BYTE0_LEN = 3,
            VREF_CS_OFFSET_BYTE0_ADD_SUB_START = 0,
            VREF_CS_OFFSET_BYTE0_ADD_SUB_LEN = 1,


            VREF_OFFSET_MULT_BYTE10_BYTE = 334,
            VREF_CA_OFFSET_MULT_BYTE10_START = 5,
            VREF_CA_OFFSET_MULT_BYTE10_LEN = 3,
            VREF_CA_OFFSET_BYTE10_ADD_SUB_START = 4,
            VREF_CA_OFFSET_BYTE10_ADD_SUB_LEN = 1,
            VREF_CS_OFFSET_MULT_BYTE10_START = 1,
            VREF_CS_OFFSET_MULT_BYTE10_LEN = 3,
            VREF_CS_OFFSET_BYTE10_ADD_SUB_START = 0,
            VREF_CS_OFFSET_BYTE10_ADD_SUB_LEN = 1,

            VREF_OFFSET_MULT_BYTE20_BYTE = 344,
            VREF_CA_OFFSET_MULT_BYTE20_START = 5,
            VREF_CA_OFFSET_MULT_BYTE20_LEN = 3,
            VREF_CA_OFFSET_BYTE20_ADD_SUB_START = 4,
            VREF_CA_OFFSET_BYTE20_ADD_SUB_LEN = 1,
            VREF_CS_OFFSET_MULT_BYTE20_START = 1,
            VREF_CS_OFFSET_MULT_BYTE20_LEN = 3,
            VREF_CS_OFFSET_BYTE20_ADD_SUB_START = 0,
            VREF_CS_OFFSET_BYTE20_ADD_SUB_LEN = 1,

            VREF_OFFSET_MULT_BYTE30_BYTE = 354,
            VREF_CA_OFFSET_MULT_BYTE30_START = 5,
            VREF_CA_OFFSET_MULT_BYTE30_LEN = 3,
            VREF_CA_OFFSET_BYTE30_ADD_SUB_START = 4,
            VREF_CA_OFFSET_BYTE30_ADD_SUB_LEN = 1,
            VREF_CS_OFFSET_MULT_BYTE30_START = 1,
            VREF_CS_OFFSET_MULT_BYTE30_LEN = 3,
            VREF_CS_OFFSET_BYTE30_ADD_SUB_START = 0,
            VREF_CS_OFFSET_BYTE30_ADD_SUB_LEN = 1,

            VREF_OFFSET_MULT_BYTE40_BYTE = 364,
            VREF_CA_OFFSET_MULT_BYTE40_START = 5,
            VREF_CA_OFFSET_MULT_BYTE40_LEN = 3,
            VREF_CA_OFFSET_BYTE40_ADD_SUB_START = 4,
            VREF_CA_OFFSET_BYTE40_ADD_SUB_LEN = 1,
            VREF_CS_OFFSET_MULT_BYTE40_START = 1,
            VREF_CS_OFFSET_MULT_BYTE40_LEN = 3,
            VREF_CS_OFFSET_BYTE40_ADD_SUB_START = 0,
            VREF_CS_OFFSET_BYTE40_ADD_SUB_LEN = 1,

            VREF_OFFSET_MULT_BYTE50_BYTE = 374,
            VREF_CA_OFFSET_MULT_BYTE50_START = 5,
            VREF_CA_OFFSET_MULT_BYTE50_LEN = 3,
            VREF_CA_OFFSET_BYTE50_ADD_SUB_START = 4,
            VREF_CA_OFFSET_BYTE50_ADD_SUB_LEN = 1,
            VREF_CS_OFFSET_MULT_BYTE50_START = 1,
            VREF_CS_OFFSET_MULT_BYTE50_LEN = 3,
            VREF_CS_OFFSET_BYTE50_ADD_SUB_START = 0,
            VREF_CS_OFFSET_BYTE50_ADD_SUB_LEN = 1,

            VREF_OFFSET_MULT_BYTE60_BYTE = 384,
            VREF_CA_OFFSET_MULT_BYTE60_START = 5,
            VREF_CA_OFFSET_MULT_BYTE60_LEN = 3,
            VREF_CA_OFFSET_BYTE60_ADD_SUB_START = 4,
            VREF_CA_OFFSET_BYTE60_ADD_SUB_LEN = 1,
            VREF_CS_OFFSET_MULT_BYTE60_START = 1,
            VREF_CS_OFFSET_MULT_BYTE60_LEN = 3,
            VREF_CS_OFFSET_BYTE60_ADD_SUB_START = 0,
            VREF_CS_OFFSET_BYTE60_ADD_SUB_LEN = 1,

            VREF_OFFSET_MULT_BYTE70_BYTE = 394,
            VREF_CA_OFFSET_MULT_BYTE70_START = 5,
            VREF_CA_OFFSET_MULT_BYTE70_LEN = 3,
            VREF_CA_OFFSET_BYTE70_ADD_SUB_START = 4,
            VREF_CA_OFFSET_BYTE70_ADD_SUB_LEN = 1,
            VREF_CS_OFFSET_MULT_BYTE70_START = 1,
            VREF_CS_OFFSET_MULT_BYTE70_LEN = 3,
            VREF_CS_OFFSET_BYTE70_ADD_SUB_START = 0,
            VREF_CS_OFFSET_BYTE70_ADD_SUB_LEN = 1,

            // Byte 404-414: Command Address Delay for Port A0
            // Byte 415: Reserved
            CS_DELAYS_A0_0_A0_2_BYTE = 404,
            CS_DELAYS_A0_0_A0_2_FINE_START = 3,
            CS_DELAYS_A0_0_A0_2_FINE_LEN = 5,
            CS_DELAYS_A0_0_A0_2_COARSE_START = 1,
            CS_DELAYS_A0_0_A0_2_COARSE_LEN = 1,

            CS_DELAYS_A0_1_A0_3_BYTE = 405,
            CS_DELAYS_A0_1_A0_3_FINE_START = 3,
            CS_DELAYS_A0_1_A0_3_FINE_LEN = 5,
            CS_DELAYS_A0_1_A0_3_COARSE_START = 1,
            CS_DELAYS_A0_1_A0_3_COARSE_LEN = 1,

            CK_DELAYS_A0_0_A0_2_BYTE = 406,
            CK_DELAYS_A0_0_A0_2_FINE_START = 3,
            CK_DELAYS_A0_0_A0_2_FINE_LEN = 5,
            CK_DELAYS_A0_0_A0_2_COARSE_START = 1,
            CK_DELAYS_A0_0_A0_2_COARSE_LEN = 1,

            CK_DELAYS_A0_1_A0_3_BYTE = 407,
            CK_DELAYS_A0_1_A0_3_FINE_START = 3,
            CK_DELAYS_A0_1_A0_3_FINE_LEN = 5,
            CK_DELAYS_A0_1_A0_3_COARSE_START = 1,
            CK_DELAYS_A0_1_A0_3_COARSE_LEN = 1,

            CA_DELAYS_A0_0_A0_1_BYTE = 408,
            CA_DELAYS_A0_0_A0_1_FINE_START = 3,
            CA_DELAYS_A0_0_A0_1_FINE_LEN = 5,
            CA_DELAYS_A0_0_A0_1_COARSE_START = 1,
            CA_DELAYS_A0_0_A0_1_COARSE_LEN = 1,

            CA_DELAYS_A0_2_A0_3_BYTE = 409,
            CA_DELAYS_A0_2_A0_3_FINE_START = 3,
            CA_DELAYS_A0_2_A0_3_FINE_LEN = 5,
            CA_DELAYS_A0_2_A0_3_COARSE_START = 1,
            CA_DELAYS_A0_2_A0_3_COARSE_LEN = 1,

            CA_DELAYS_A0_4_A0_5_BYTE = 410,
            CA_DELAYS_A0_4_A0_5_FINE_START = 3,
            CA_DELAYS_A0_4_A0_5_FINE_LEN = 5,
            CA_DELAYS_A0_4_A0_5_COARSE_START = 1,
            CA_DELAYS_A0_4_A0_5_COARSE_LEN = 1,

            CA_DELAYS_A0_6_A0_7_BYTE = 411,
            CA_DELAYS_A0_6_A0_7_FINE_START = 3,
            CA_DELAYS_A0_6_A0_7_FINE_LEN = 5,
            CA_DELAYS_A0_6_A0_7_COARSE_START = 1,
            CA_DELAYS_A0_6_A0_7_COARSE_LEN = 1,

            CA_DELAYS_A0_8_A0_9_BYTE = 412,
            CA_DELAYS_A0_8_A0_9_FINE_START = 3,
            CA_DELAYS_A0_8_A0_9_FINE_LEN = 5,
            CA_DELAYS_A0_8_A0_9_COARSE_START = 1,
            CA_DELAYS_A0_8_A0_9_COARSE_LEN = 1,

            CA_DELAYS_A0_10_A0_11_BYTE = 413,
            CA_DELAYS_A0_10_A0_11_FINE_START = 3,
            CA_DELAYS_A0_10_A0_11_FINE_LEN = 5,
            CA_DELAYS_A0_10_A0_11_COARSE_START = 1,
            CA_DELAYS_A0_10_A0_11_COARSE_LEN = 1,

            CA_DELAYS_A0_12_A0_13_BYTE = 414,
            CA_DELAYS_A0_12_A0_13_FINE_START = 3,
            CA_DELAYS_A0_12_A0_13_FINE_LEN = 5,
            CA_DELAYS_A0_12_A0_13_COARSE_START = 1,
            CA_DELAYS_A0_12_A0_13_COARSE_LEN = 1,

            // Byte 416-426: Command Address Delay for Port B0
            // Byte 427: Reserved
            CS_DELAYS_B0_0_B0_2_BYTE = 416,
            CS_DELAYS_B0_0_B0_2_FINE_START = 3,
            CS_DELAYS_B0_0_B0_2_FINE_LEN = 5,
            CS_DELAYS_B0_0_B0_2_COARSE_START = 1,
            CS_DELAYS_B0_0_B0_2_COARSE_LEN = 1,

            CS_DELAYS_B0_1_B0_3_BYTE = 417,
            CS_DELAYS_B0_1_B0_3_FINE_START = 3,
            CS_DELAYS_B0_1_B0_3_FINE_LEN = 5,
            CS_DELAYS_B0_1_B0_3_COARSE_START = 1,
            CS_DELAYS_B0_1_B0_3_COARSE_LEN = 1,

            CK_DELAYS_B0_0_B0_2_BYTE = 418,
            CK_DELAYS_B0_0_B0_2_FINE_START = 3,
            CK_DELAYS_B0_0_B0_2_FINE_LEN = 5,
            CK_DELAYS_B0_0_B0_2_COARSE_START = 1,
            CK_DELAYS_B0_0_B0_2_COARSE_LEN = 1,

            CK_DELAYS_B0_1_B0_3_BYTE = 419,
            CK_DELAYS_B0_1_B0_3_FINE_START = 3,
            CK_DELAYS_B0_1_B0_3_FINE_LEN = 5,
            CK_DELAYS_B0_1_B0_3_COARSE_START = 1,
            CK_DELAYS_B0_1_B0_3_COARSE_LEN = 1,

            CA_DELAYS_B0_0_B0_1_BYTE = 420,
            CA_DELAYS_B0_0_B0_1_FINE_START = 3,
            CA_DELAYS_B0_0_B0_1_FINE_LEN = 5,
            CA_DELAYS_B0_0_B0_1_COARSE_START = 1,
            CA_DELAYS_B0_0_B0_1_COARSE_LEN = 1,

            CA_DELAYS_B0_2_B0_3_BYTE = 421,
            CA_DELAYS_B0_2_B0_3_FINE_START = 3,
            CA_DELAYS_B0_2_B0_3_FINE_LEN = 5,
            CA_DELAYS_B0_2_B0_3_COARSE_START = 1,
            CA_DELAYS_B0_2_B0_3_COARSE_LEN = 1,

            CA_DELAYS_B0_4_B0_5_BYTE = 422,
            CA_DELAYS_B0_4_B0_5_FINE_START = 3,
            CA_DELAYS_B0_4_B0_5_FINE_LEN = 5,
            CA_DELAYS_B0_4_B0_5_COARSE_START = 1,
            CA_DELAYS_B0_4_B0_5_COARSE_LEN = 1,

            CA_DELAYS_B0_6_B0_7_BYTE = 423,
            CA_DELAYS_B0_6_B0_7_FINE_START = 3,
            CA_DELAYS_B0_6_B0_7_FINE_LEN = 5,
            CA_DELAYS_B0_6_B0_7_COARSE_START = 1,
            CA_DELAYS_B0_6_B0_7_COARSE_LEN = 1,

            CA_DELAYS_B0_8_B0_9_BYTE = 424,
            CA_DELAYS_B0_8_B0_9_FINE_START = 3,
            CA_DELAYS_B0_8_B0_9_FINE_LEN = 5,
            CA_DELAYS_B0_8_B0_9_COARSE_START = 1,
            CA_DELAYS_B0_8_B0_9_COARSE_LEN = 1,

            CA_DELAYS_B0_10_B0_11_BYTE = 425,
            CA_DELAYS_B0_10_B0_11_FINE_START = 3,
            CA_DELAYS_B0_10_B0_11_FINE_LEN = 5,
            CA_DELAYS_B0_10_B0_11_COARSE_START = 1,
            CA_DELAYS_B0_10_B0_11_COARSE_LEN = 1,

            CA_DELAYS_B0_12_B0_13_BYTE = 426,
            CA_DELAYS_B0_12_B0_13_FINE_START = 3,
            CA_DELAYS_B0_12_B0_13_FINE_LEN = 5,
            CA_DELAYS_B0_12_B0_13_COARSE_START = 1,
            CA_DELAYS_B0_12_B0_13_COARSE_LEN = 1,

            // Byte 428-438: Command Address Delay for Port A1
            // Byte 439: Reserved
            CS_DELAYS_A1_0_A1_2_BYTE = 428,
            CS_DELAYS_A1_0_A1_2_FINE_START = 3,
            CS_DELAYS_A1_0_A1_2_FINE_LEN = 5,
            CS_DELAYS_A1_0_A1_2_COARSE_START = 1,
            CS_DELAYS_A1_0_A1_2_COARSE_LEN = 1,

            CS_DELAYS_A1_1_A1_3_BYTE = 429,
            CS_DELAYS_A1_1_A1_3_FINE_START = 3,
            CS_DELAYS_A1_1_A1_3_FINE_LEN = 5,
            CS_DELAYS_A1_1_A1_3_COARSE_START = 1,
            CS_DELAYS_A1_1_A1_3_COARSE_LEN = 1,

            CK_DELAYS_A1_0_A1_2_BYTE = 430,
            CK_DELAYS_A1_0_A1_2_FINE_START = 3,
            CK_DELAYS_A1_0_A1_2_FINE_LEN = 5,
            CK_DELAYS_A1_0_A1_2_COARSE_START = 1,
            CK_DELAYS_A1_0_A1_2_COARSE_LEN = 1,

            CK_DELAYS_A1_1_A1_3_BYTE = 431,
            CK_DELAYS_A1_1_A1_3_FINE_START = 3,
            CK_DELAYS_A1_1_A1_3_FINE_LEN = 5,
            CK_DELAYS_A1_1_A1_3_COARSE_START = 1,
            CK_DELAYS_A1_1_A1_3_COARSE_LEN = 1,

            CA_DELAYS_A1_0_A1_1_BYTE = 432,
            CA_DELAYS_A1_0_A1_1_FINE_START = 3,
            CA_DELAYS_A1_0_A1_1_FINE_LEN = 5,
            CA_DELAYS_A1_0_A1_1_COARSE_START = 1,
            CA_DELAYS_A1_0_A1_1_COARSE_LEN = 1,

            CA_DELAYS_A1_2_A1_3_BYTE = 433,
            CA_DELAYS_A1_2_A1_3_FINE_START = 3,
            CA_DELAYS_A1_2_A1_3_FINE_LEN = 5,
            CA_DELAYS_A1_2_A1_3_COARSE_START = 1,
            CA_DELAYS_A1_2_A1_3_COARSE_LEN = 1,

            CA_DELAYS_A1_4_A1_5_BYTE = 434,
            CA_DELAYS_A1_4_A1_5_FINE_START = 3,
            CA_DELAYS_A1_4_A1_5_FINE_LEN = 5,
            CA_DELAYS_A1_4_A1_5_COARSE_START = 1,
            CA_DELAYS_A1_4_A1_5_COARSE_LEN = 1,

            CA_DELAYS_A1_6_A1_7_BYTE = 435,
            CA_DELAYS_A1_6_A1_7_FINE_START = 3,
            CA_DELAYS_A1_6_A1_7_FINE_LEN = 5,
            CA_DELAYS_A1_6_A1_7_COARSE_START = 1,
            CA_DELAYS_A1_6_A1_7_COARSE_LEN = 1,

            CA_DELAYS_A1_8_A1_9_BYTE = 436,
            CA_DELAYS_A1_8_A1_9_FINE_START = 3,
            CA_DELAYS_A1_8_A1_9_FINE_LEN = 5,
            CA_DELAYS_A1_8_A1_9_COARSE_START = 1,
            CA_DELAYS_A1_8_A1_9_COARSE_LEN = 1,

            CA_DELAYS_A1_10_A1_11_BYTE = 437,
            CA_DELAYS_A1_10_A1_11_FINE_START = 3,
            CA_DELAYS_A1_10_A1_11_FINE_LEN = 5,
            CA_DELAYS_A1_10_A1_11_COARSE_START = 1,
            CA_DELAYS_A1_10_A1_11_COARSE_LEN = 1,

            CA_DELAYS_A1_12_A1_13_BYTE = 438,
            CA_DELAYS_A1_12_A1_13_FINE_START = 3,
            CA_DELAYS_A1_12_A1_13_FINE_LEN = 5,
            CA_DELAYS_A1_12_A1_13_COARSE_START = 1,
            CA_DELAYS_A1_12_A1_13_COARSE_LEN = 1,

            // Byte 440-450: Command Address Delay for Port B1
            // Byte 451: Reserved
            CS_DELAYS_B1_0_B1_2_BYTE = 440,
            CS_DELAYS_B1_0_B1_2_FINE_START = 3,
            CS_DELAYS_B1_0_B1_2_FINE_LEN = 5,
            CS_DELAYS_B1_0_B1_2_COARSE_START = 1,
            CS_DELAYS_B1_0_B1_2_COARSE_LEN = 1,

            CS_DELAYS_B1_1_B1_3_BYTE = 441,
            CS_DELAYS_B1_1_B1_3_FINE_START = 3,
            CS_DELAYS_B1_1_B1_3_FINE_LEN = 5,
            CS_DELAYS_B1_1_B1_3_COARSE_START = 1,
            CS_DELAYS_B1_1_B1_3_COARSE_LEN = 1,

            CK_DELAYS_B1_0_B1_2_BYTE = 442,
            CK_DELAYS_B1_0_B1_2_FINE_START = 3,
            CK_DELAYS_B1_0_B1_2_FINE_LEN = 5,
            CK_DELAYS_B1_0_B1_2_COARSE_START = 1,
            CK_DELAYS_B1_0_B1_2_COARSE_LEN = 1,

            CK_DELAYS_B1_1_B1_3_BYTE = 443,
            CK_DELAYS_B1_1_B1_3_FINE_START = 3,
            CK_DELAYS_B1_1_B1_3_FINE_LEN = 5,
            CK_DELAYS_B1_1_B1_3_COARSE_START = 1,
            CK_DELAYS_B1_1_B1_3_COARSE_LEN = 1,

            CA_DELAYS_B1_0_B1_1_BYTE = 444,
            CA_DELAYS_B1_0_B1_1_FINE_START = 3,
            CA_DELAYS_B1_0_B1_1_FINE_LEN = 5,
            CA_DELAYS_B1_0_B1_1_COARSE_START = 1,
            CA_DELAYS_B1_0_B1_1_COARSE_LEN = 1,

            CA_DELAYS_B1_2_B1_3_BYTE = 445,
            CA_DELAYS_B1_2_B1_3_FINE_START = 3,
            CA_DELAYS_B1_2_B1_3_FINE_LEN = 5,
            CA_DELAYS_B1_2_B1_3_COARSE_START = 1,
            CA_DELAYS_B1_2_B1_3_COARSE_LEN = 1,

            CA_DELAYS_B1_4_B1_5_BYTE = 446,
            CA_DELAYS_B1_4_B1_5_FINE_START = 3,
            CA_DELAYS_B1_4_B1_5_FINE_LEN = 5,
            CA_DELAYS_B1_4_B1_5_COARSE_START = 1,
            CA_DELAYS_B1_4_B1_5_COARSE_LEN = 1,

            CA_DELAYS_B1_6_B1_7_BYTE = 447,
            CA_DELAYS_B1_6_B1_7_FINE_START = 3,
            CA_DELAYS_B1_6_B1_7_FINE_LEN = 5,
            CA_DELAYS_B1_6_B1_7_COARSE_START = 1,
            CA_DELAYS_B1_6_B1_7_COARSE_LEN = 1,

            CA_DELAYS_B1_8_B1_9_BYTE = 448,
            CA_DELAYS_B1_8_B1_9_FINE_START = 3,
            CA_DELAYS_B1_8_B1_9_FINE_LEN = 5,
            CA_DELAYS_B1_8_B1_9_COARSE_START = 1,
            CA_DELAYS_B1_8_B1_9_COARSE_LEN = 1,

            CA_DELAYS_B1_10_B1_11_BYTE = 449,
            CA_DELAYS_B1_10_B1_11_FINE_START = 3,
            CA_DELAYS_B1_10_B1_11_FINE_LEN = 5,
            CA_DELAYS_B1_10_B1_11_COARSE_START = 1,
            CA_DELAYS_B1_10_B1_11_COARSE_LEN = 1,

            CA_DELAYS_B1_12_B1_13_BYTE = 450,
            CA_DELAYS_B1_12_B1_13_FINE_START = 3,
            CA_DELAYS_B1_12_B1_13_FINE_LEN = 5,
            CA_DELAYS_B1_12_B1_13_COARSE_START = 1,
            CA_DELAYS_B1_12_B1_13_COARSE_LEN = 1,

            // Byte 478: PMIC0 SWA Voltage Offset
            PMIC0_SWA_VOLT_OFF_BYTE = 478,
            PMIC0_SWA_VOLT_OFF_START = 0,
            PMIC0_SWA_VOLT_OFF_LEN = 7,
            PMIC0_SWA_OFF_DIRECTION_START = 7,
            PMIC0_SWA_OFF_DIRECTION_LEN = 1,

            // Byte 479: PMIC0 SWB Voltage Offset
            PMIC0_SWB_VOLT_OFF_BYTE = 479,
            PMIC0_SWB_VOLT_OFF_START = 0,
            PMIC0_SWB_VOLT_OFF_LEN = 7,
            PMIC0_SWB_OFF_DIRECTION_START = 7,
            PMIC0_SWB_OFF_DIRECTION_LEN = 1,

            // Byte 480: PMIC0 SWC Voltage Offset
            PMIC0_SWC_VOLT_OFF_BYTE = 480,
            PMIC0_SWC_VOLT_OFF_START = 0,
            PMIC0_SWC_VOLT_OFF_LEN = 7,
            PMIC0_SWC_OFF_DIRECTION_START = 7,
            PMIC0_SWC_OFF_DIRECTION_LEN = 1,

            // Byte 481: PMIC0 SWD Voltage Offset
            PMIC0_SWD_VOLT_OFF_BYTE = 481,
            PMIC0_SWD_VOLT_OFF_START = 0,
            PMIC0_SWD_VOLT_OFF_LEN = 7,
            PMIC0_SWD_OFF_DIRECTION_START = 7,
            PMIC0_SWD_OFF_DIRECTION_LEN = 1,

            // Byte 482: PMIC1 SWA Voltage Offset
            PMIC1_SWA_VOLT_OFF_BYTE = 482,
            PMIC1_SWA_VOLT_OFF_START = 0,
            PMIC1_SWA_VOLT_OFF_LEN = 7,
            PMIC1_SWA_OFF_DIRECTION_START = 7,
            PMIC1_SWA_OFF_DIRECTION_LEN = 1,

            // Byte 483: PMIC1 SWB Voltage Offset
            PMIC1_SWB_VOLT_OFF_BYTE = 483,
            PMIC1_SWB_VOLT_OFF_START = 0,
            PMIC1_SWB_VOLT_OFF_LEN = 7,
            PMIC1_SWB_OFF_DIRECTION_START = 7,
            PMIC1_SWB_OFF_DIRECTION_LEN = 1,

            // Byte 484: PMIC1 SWC Voltage Offset
            PMIC1_SWC_VOLT_OFF_BYTE = 484,
            PMIC1_SWC_VOLT_OFF_START = 0,
            PMIC1_SWC_VOLT_OFF_LEN = 7,
            PMIC1_SWC_OFF_DIRECTION_START = 7,
            PMIC1_SWC_OFF_DIRECTION_LEN = 1,

            // Byte 485: PMIC1 SWD Voltage Offset
            PMIC1_SWD_VOLT_OFF_BYTE = 485,
            PMIC1_SWD_VOLT_OFF_START = 0,
            PMIC1_SWD_VOLT_OFF_LEN = 7,
            PMIC1_SWD_OFF_DIRECTION_START = 7,
            PMIC1_SWD_OFF_DIRECTION_LEN = 1,

            // Byte 486: PMIC2 SWA Voltage Offset
            PMIC2_SWA_VOLT_OFF_BYTE = 486,
            PMIC2_SWA_VOLT_OFF_START = 0,
            PMIC2_SWA_VOLT_OFF_LEN = 7,
            PMIC2_SWA_OFF_DIRECTION_START = 7,
            PMIC2_SWA_OFF_DIRECTION_LEN = 1,

            // Byte 487: PMIC2 SWB Voltage Offset
            PMIC2_SWB_VOLT_OFF_BYTE = 487,
            PMIC2_SWB_VOLT_OFF_START = 0,
            PMIC2_SWB_VOLT_OFF_LEN = 7,
            PMIC2_SWB_OFF_DIRECTION_START = 7,
            PMIC2_SWB_OFF_DIRECTION_LEN = 1,

            // Byte 488: PMIC2 SWC Voltage Offset
            PMIC2_SWC_VOLT_OFF_BYTE = 488,
            PMIC2_SWC_VOLT_OFF_START = 0,
            PMIC2_SWC_VOLT_OFF_LEN = 7,
            PMIC2_SWC_OFF_DIRECTION_START = 7,
            PMIC2_SWC_OFF_DIRECTION_LEN = 1,

            // Byte 489: PMIC2 SWD Voltage Offset
            PMIC2_SWD_VOLT_OFF_BYTE = 489,
            PMIC2_SWD_VOLT_OFF_START = 0,
            PMIC2_SWD_VOLT_OFF_LEN = 7,
            PMIC2_SWD_OFF_DIRECTION_START = 7,
            PMIC2_SWD_OFF_DIRECTION_LEN = 1,

            // Byte 490: PMIC3 SWA Voltage Offset
            PMIC3_SWA_VOLT_OFF_BYTE = 490,
            PMIC3_SWA_VOLT_OFF_START = 0,
            PMIC3_SWA_VOLT_OFF_LEN = 7,
            PMIC3_SWA_OFF_DIRECTION_START = 7,
            PMIC3_SWA_OFF_DIRECTION_LEN = 1,

            // Byte 491: PMIC3 SWB Voltage Offset
            PMIC3_SWB_VOLT_OFF_BYTE = 491,
            PMIC3_SWB_VOLT_OFF_START = 0,
            PMIC3_SWB_VOLT_OFF_LEN = 7,
            PMIC3_SWB_OFF_DIRECTION_START = 7,
            PMIC3_SWB_OFF_DIRECTION_LEN = 1,

            // Byte 492: PMIC3 SWC Voltage Offset
            PMIC3_SWC_VOLT_OFF_BYTE = 492,
            PMIC3_SWC_VOLT_OFF_START = 0,
            PMIC3_SWC_VOLT_OFF_LEN = 7,
            PMIC3_SWC_OFF_DIRECTION_START = 7,
            PMIC3_SWC_OFF_DIRECTION_LEN = 1,

            // Byte 493: PMIC3 SWD Voltage Offset
            PMIC3_SWD_VOLT_OFF_BYTE = 493,
            PMIC3_SWD_VOLT_OFF_START = 0,
            PMIC3_SWD_VOLT_OFF_LEN = 7,
            PMIC3_SWD_OFF_DIRECTION_START = 7,
            PMIC3_SWD_OFF_DIRECTION_LEN = 1,

            // Byte 494: PMIC0 SWA Recommended Current Consumption Warning and Threshold
            PMIC0_SWA_CURRENT_WARNING_BYTE = 494,
            PMIC0_SWA_CURRENT_WARNING_START = 0,
            PMIC0_SWA_CURRENT_WARNING_LEN = 6,

            // Byte 495: PMIC0 SWB Recommended Current Consumption Warning and Threshold
            PMIC0_SWB_CURRENT_WARNING_BYTE = 495,
            PMIC0_SWB_CURRENT_WARNING_START = 0,
            PMIC0_SWB_CURRENT_WARNING_LEN = 6,

            // Byte 496: PMIC0 SWC Recommended Current Consumption Warning and Threshold
            PMIC0_SWC_CURRENT_WARNING_BYTE = 496,
            PMIC0_SWC_CURRENT_WARNING_START = 0,
            PMIC0_SWC_CURRENT_WARNING_LEN = 6,

            // Byte 497: PMIC0 SWD Recommended Current Consumption Warning and Threshold
            PMIC0_SWD_CURRENT_WARNING_BYTE = 497,
            PMIC0_SWD_CURRENT_WARNING_START = 0,
            PMIC0_SWD_CURRENT_WARNING_LEN = 6,

            // Byte 498: PMIC1 SWA Recommended Current Consumption Warning and Threshold
            PMIC1_SWA_CURRENT_WARNING_BYTE = 498,
            PMIC1_SWA_CURRENT_WARNING_START = 0,
            PMIC1_SWA_CURRENT_WARNING_LEN = 6,

            // Byte 499: PMIC1 SWB Recommended Current Consumption Warning and Threshold
            PMIC1_SWB_CURRENT_WARNING_BYTE = 499,
            PMIC1_SWB_CURRENT_WARNING_START = 0,
            PMIC1_SWB_CURRENT_WARNING_LEN = 6,

            // Byte 500: PMIC1 SWC Recommended Current Consumption Warning and Threshold
            PMIC1_SWC_CURRENT_WARNING_BYTE = 500,
            PMIC1_SWC_CURRENT_WARNING_START = 0,
            PMIC1_SWC_CURRENT_WARNING_LEN = 6,

            // Byte 501: PMIC1 SWD Recommended Current Consumption Warning and Threshold
            PMIC1_SWD_CURRENT_WARNING_BYTE = 501,
            PMIC1_SWD_CURRENT_WARNING_START = 0,
            PMIC1_SWD_CURRENT_WARNING_LEN = 6,

            // Byte 502: PMIC2 SWA Recommended Current Consumption Warning and Threshold
            PMIC2_SWA_CURRENT_WARNING_BYTE = 502,
            PMIC2_SWA_CURRENT_WARNING_START = 0,
            PMIC2_SWA_CURRENT_WARNING_LEN = 6,

            // Byte 503: PMIC2 SWB Recommended Current Consumption Warning and Threshold
            PMIC2_SWB_CURRENT_WARNING_BYTE = 503,
            PMIC2_SWB_CURRENT_WARNING_START = 0,
            PMIC2_SWB_CURRENT_WARNING_LEN = 6,

            // Byte 504: PMIC2 SWC Recommended Current Consumption Warning and Threshold
            PMIC2_SWC_CURRENT_WARNING_BYTE = 504,
            PMIC2_SWC_CURRENT_WARNING_START = 0,
            PMIC2_SWC_CURRENT_WARNING_LEN = 6,

            // Byte 505: PMIC2 SWD Recommended Current Consumption Warning and Threshold
            PMIC2_SWD_CURRENT_WARNING_BYTE = 505,
            PMIC2_SWD_CURRENT_WARNING_START = 0,
            PMIC2_SWD_CURRENT_WARNING_LEN = 6,

            // Byte 506: PMIC3 SWA Recommended Current Consumption Warning and Threshold
            PMIC3_SWA_CURRENT_WARNING_BYTE = 506,
            PMIC3_SWA_CURRENT_WARNING_START = 0,
            PMIC3_SWA_CURRENT_WARNING_LEN = 6,

            // Byte 507: PMIC3 SWB Recommended Current Consumption Warning and Threshold
            PMIC3_SWB_CURRENT_WARNING_BYTE = 507,
            PMIC3_SWB_CURRENT_WARNING_START = 0,
            PMIC3_SWB_CURRENT_WARNING_LEN = 6,

            // Byte 508: PMIC3 SWC Recommended Current Consumption Warning and Threshold
            PMIC3_SWC_CURRENT_WARNING_BYTE = 508,
            PMIC3_SWC_CURRENT_WARNING_START = 0,
            PMIC3_SWC_CURRENT_WARNING_LEN = 6,

            // Byte 509: PMIC3 SWD Recommended Current Consumption Warning and Threshold
            PMIC3_SWD_CURRENT_WARNING_BYTE = 509,
            PMIC3_SWD_CURRENT_WARNING_START = 0,
            PMIC3_SWD_CURRENT_WARNING_LEN = 6,

        };

    public:
        // Syntatic sugar to make member variable declaration easier
        using field_t = mss::field_t<mss::endian::LITTLE>;

        // First field - SPD byte
        // Second field - start bit
        // Third field - bit length

        // Byte 0: Host Speed Supported
        static constexpr field_t HOST_SPEED_SUPPORTED{HOST_SPEED_SUPPORTED_BYTE, HOST_SPEED_SUPPORTED_START, HOST_SPEED_SUPPORTED_LEN};

        // Byte 1: 2N Requirements
        static constexpr field_t MODE_2N_REQUIREMENTS_25600{MODE_2N_REQUIREMENTS_BYTE, MODE_2N_REQUIREMENTS_25600_START, MODE_2N_REQUIREMENTS_25600_LEN};
        static constexpr field_t MODE_2N_REQUIREMENTS_32000{MODE_2N_REQUIREMENTS_BYTE, MODE_2N_REQUIREMENTS_32000_START, MODE_2N_REQUIREMENTS_32000_LEN};
        static constexpr field_t MODE_2N_REQUIREMENTS_38400{MODE_2N_REQUIREMENTS_BYTE, MODE_2N_REQUIREMENTS_38400_START, MODE_2N_REQUIREMENTS_38400_LEN};

        // Byte 2: Master Ranks and PHY Channels Supported
        static constexpr field_t MASTER_RANKS_SUPPORTED{MASTER_RANKS_PHY_CHA_SUPPORTED_BYTE, MASTER_RANKS_SUPPORTED_START, MASTER_RANKS_SUPPORTED_LEN};
        static constexpr field_t PHY_CHANNEL_SUPPORTED{MASTER_RANKS_PHY_CHA_SUPPORTED_BYTE, PHY_CHANNEL_SUPPORTED_START, PHY_CHANNEL_SUPPORTED_LEN};

        // Byte 3: PHY0 Channels A0/B0 Vref
        static constexpr field_t PHY0_CHANNELS_VREF{PHY0_CHANNELS_VREF_BYTE, PHY0_CHANNELS_VREF_START, PHY0_CHANNELS_VREF_LEN};

        // Byte 3: PHY1 Channels A1/B1 Vref
        static constexpr field_t PHY1_CHANNELS_VREF{PHY1_CHANNELS_VREF_BYTE, PHY1_CHANNELS_VREF_START, PHY1_CHANNELS_VREF_LEN};

        // Byte 5: DRAM DIC
        static constexpr field_t DRAM_DIC_PULLUP{DRAM_DIC_BYTE, DRAM_DIC_PULLUP_START, DRAM_DIC_PULLUP_LEN};
        static constexpr field_t DRAM_DIC_PULLDOWN{DRAM_DIC_BYTE, DRAM_DIC_PULLDOWN_START, DRAM_DIC_PULLDOWN_LEN};

        // Byte 9: DRAM Preamble and Postamble Settings
        static constexpr field_t DRAM_WR_POSTAMBLE{DRAM_PREAMBLE_POSTAMBLE_BYTE, WRITE_POSTAMBLE_START, WRITE_POSTAMBLE_LEN};
        static constexpr field_t DRAM_RD_POSTAMBLE{DRAM_PREAMBLE_POSTAMBLE_BYTE, READ_POSTAMBLE_START, READ_POSTAMBLE_LEN};
        static constexpr field_t DRAM_WR_PREAMBLE{DRAM_PREAMBLE_POSTAMBLE_BYTE, WRITE_PREAMBLE_START, WRITE_PREAMBLE_LEN};
        static constexpr field_t DRAM_RD_PREAMBLE{DRAM_PREAMBLE_POSTAMBLE_BYTE, READ_PREAMBLE_START, READ_PREAMBLE_LEN};

        // Byte 10-17: DRAM VREF DQ Setting
        static constexpr field_t DRAM_VREF_BYTE0{DRAM_VREF_BYTE0_BYTE, DRAM_VREF_BYTE0_START, DRAM_VREF_BYTE0_LEN};
        static constexpr field_t DRAM_VREF_BYTE1{DRAM_VREF_BYTE1_BYTE, DRAM_VREF_BYTE1_START, DRAM_VREF_BYTE1_LEN};
        static constexpr field_t DRAM_VREF_BYTE2{DRAM_VREF_BYTE2_BYTE, DRAM_VREF_BYTE2_START, DRAM_VREF_BYTE2_LEN};
        static constexpr field_t DRAM_VREF_BYTE3{DRAM_VREF_BYTE3_BYTE, DRAM_VREF_BYTE3_START, DRAM_VREF_BYTE3_LEN};
        static constexpr field_t DRAM_VREF_BYTE4{DRAM_VREF_BYTE4_BYTE, DRAM_VREF_BYTE4_START, DRAM_VREF_BYTE4_LEN};
        static constexpr field_t DRAM_VREF_BYTE5{DRAM_VREF_BYTE5_BYTE, DRAM_VREF_BYTE5_START, DRAM_VREF_BYTE5_LEN};
        static constexpr field_t DRAM_VREF_BYTE6{DRAM_VREF_BYTE6_BYTE, DRAM_VREF_BYTE6_START, DRAM_VREF_BYTE6_LEN};
        static constexpr field_t DRAM_VREF_BYTE7{DRAM_VREF_BYTE7_BYTE, DRAM_VREF_BYTE7_START, DRAM_VREF_BYTE7_LEN};

        // Byte 18: DRAM DFE Settings
        static constexpr field_t DRAM_DFE_TAP4{DRAM_DFE_BYTE, DRAM_DFE_TAP4_START, DRAM_DFE_TAP4_LEN};
        static constexpr field_t DRAM_DFE_TAP3{DRAM_DFE_BYTE, DRAM_DFE_TAP3_START, DRAM_DFE_TAP3_LEN};
        static constexpr field_t DRAM_DFE_TAP2{DRAM_DFE_BYTE, DRAM_DFE_TAP2_START, DRAM_DFE_TAP2_LEN};
        static constexpr field_t DRAM_DFE_TAP1{DRAM_DFE_BYTE, DRAM_DFE_TAP1_START, DRAM_DFE_TAP1_LEN};
        static constexpr field_t DRAM_DFE_EN{DRAM_DFE_BYTE, DRAM_DFE_EN_START, DRAM_DFE_EN_LEN};

        // Byte 19-26: DRAM DFE Gain Bias
        static constexpr field_t DRAM_DFE_GAIN_BIAS_BYTE0{DRAM_DFE_GAIN_BIAS_BYTE0_BYTE, DRAM_DFE_GAIN_BIAS_BYTE0_START, DRAM_DFE_GAIN_BIAS_BYTE0_LEN};
        static constexpr field_t DRAM_DFE_GAIN_BIAS_BYTE0_SIGN_BIT{DRAM_DFE_GAIN_BIAS_BYTE0_BYTE, DRAM_DFE_GAIN_BIAS_BYTE0_SIGN_BIT_START, DRAM_DFE_GAIN_BIAS_BYTE0_SIGN_BIT_LEN};

        static constexpr field_t DRAM_DFE_GAIN_BIAS_BYTE1{DRAM_DFE_GAIN_BIAS_BYTE1_BYTE, DRAM_DFE_GAIN_BIAS_BYTE1_START, DRAM_DFE_GAIN_BIAS_BYTE1_LEN};
        static constexpr field_t DRAM_DFE_GAIN_BIAS_BYTE1_SIGN_BIT{DRAM_DFE_GAIN_BIAS_BYTE1_BYTE, DRAM_DFE_GAIN_BIAS_BYTE1_SIGN_BIT_START, DRAM_DFE_GAIN_BIAS_BYTE1_SIGN_BIT_LEN};

        static constexpr field_t DRAM_DFE_GAIN_BIAS_BYTE2{DRAM_DFE_GAIN_BIAS_BYTE2_BYTE, DRAM_DFE_GAIN_BIAS_BYTE2_START, DRAM_DFE_GAIN_BIAS_BYTE2_LEN};
        static constexpr field_t DRAM_DFE_GAIN_BIAS_BYTE2_SIGN_BIT{DRAM_DFE_GAIN_BIAS_BYTE2_BYTE, DRAM_DFE_GAIN_BIAS_BYTE2_SIGN_BIT_START, DRAM_DFE_GAIN_BIAS_BYTE2_SIGN_BIT_LEN};

        static constexpr field_t DRAM_DFE_GAIN_BIAS_BYTE3{DRAM_DFE_GAIN_BIAS_BYTE3_BYTE, DRAM_DFE_GAIN_BIAS_BYTE3_START, DRAM_DFE_GAIN_BIAS_BYTE3_LEN};
        static constexpr field_t DRAM_DFE_GAIN_BIAS_BYTE3_SIGN_BIT{DRAM_DFE_GAIN_BIAS_BYTE3_BYTE, DRAM_DFE_GAIN_BIAS_BYTE3_SIGN_BIT_START, DRAM_DFE_GAIN_BIAS_BYTE3_SIGN_BIT_LEN};

        static constexpr field_t DRAM_DFE_GAIN_BIAS_BYTE4{DRAM_DFE_GAIN_BIAS_BYTE4_BYTE, DRAM_DFE_GAIN_BIAS_BYTE4_START, DRAM_DFE_GAIN_BIAS_BYTE4_LEN};
        static constexpr field_t DRAM_DFE_GAIN_BIAS_BYTE4_SIGN_BIT{DRAM_DFE_GAIN_BIAS_BYTE4_BYTE, DRAM_DFE_GAIN_BIAS_BYTE4_SIGN_BIT_START, DRAM_DFE_GAIN_BIAS_BYTE4_SIGN_BIT_LEN};

        static constexpr field_t DRAM_DFE_GAIN_BIAS_BYTE5{DRAM_DFE_GAIN_BIAS_BYTE5_BYTE, DRAM_DFE_GAIN_BIAS_BYTE5_START, DRAM_DFE_GAIN_BIAS_BYTE5_LEN};
        static constexpr field_t DRAM_DFE_GAIN_BIAS_BYTE5_SIGN_BIT{DRAM_DFE_GAIN_BIAS_BYTE5_BYTE, DRAM_DFE_GAIN_BIAS_BYTE5_SIGN_BIT_START, DRAM_DFE_GAIN_BIAS_BYTE5_SIGN_BIT_LEN};

        static constexpr field_t DRAM_DFE_GAIN_BIAS_BYTE6{DRAM_DFE_GAIN_BIAS_BYTE6_BYTE, DRAM_DFE_GAIN_BIAS_BYTE6_START, DRAM_DFE_GAIN_BIAS_BYTE6_LEN};
        static constexpr field_t DRAM_DFE_GAIN_BIAS_BYTE6_SIGN_BIT{DRAM_DFE_GAIN_BIAS_BYTE6_BYTE, DRAM_DFE_GAIN_BIAS_BYTE6_SIGN_BIT_START, DRAM_DFE_GAIN_BIAS_BYTE6_SIGN_BIT_LEN};

        static constexpr field_t DRAM_DFE_GAIN_BIAS_BYTE7{DRAM_DFE_GAIN_BIAS_BYTE7_BYTE, DRAM_DFE_GAIN_BIAS_BYTE7_START, DRAM_DFE_GAIN_BIAS_BYTE7_LEN};
        static constexpr field_t DRAM_DFE_GAIN_BIAS_BYTE7_SIGN_BIT{DRAM_DFE_GAIN_BIAS_BYTE7_BYTE, DRAM_DFE_GAIN_BIAS_BYTE7_SIGN_BIT_START, DRAM_DFE_GAIN_BIAS_BYTE7_SIGN_BIT_LEN};

        // Byte 27: PHY ODT Impedence
        static constexpr field_t PHY_ODT_IMPEDANCE{PHY_ODT_IMPEDANCE_BYTE, PHY_ODT_IMPEDANCE_START, PHY_ODT_IMPEDANCE_LEN};

        // Byte 28: PHY Drive impedance
        static constexpr field_t PHY_DRIVE_IMPEDANCE_CTRL0{PHY_DRIVE_IMPEDANCE_CTRL0_BYTE, PHY_DRIVE_IMPEDANCE_CTRL0_START, PHY_DRIVE_IMPEDANCE_CTRL0_LEN};

        // Byte 29: PHY Drive impedance
        static constexpr field_t PHY_DRIVE_IMPEDANCE_CTRL1{PHY_DRIVE_IMPEDANCE_CTRL1_BYTE, PHY_DRIVE_IMPEDANCE_CTRL1_START, PHY_DRIVE_IMPEDANCE_CTRL1_LEN};

        // Byte 30: PHY Drive impedance
        static constexpr field_t PHY_DRIVE_IMPEDANCE_CTRL2{PHY_DRIVE_IMPEDANCE_CTRL2_BYTE, PHY_DRIVE_IMPEDANCE_CTRL2_START, PHY_DRIVE_IMPEDANCE_CTRL2_LEN};

        // Byte 31: PHY Slew Rate DQ_DQS
        static constexpr field_t PHY_SLEW_RATE_DQ_DQS{PHY_SLEW_RATE_DQ_DQS_BYTE, PHY_SLEW_RATE_DQ_DQS_START, PHY_SLEW_RATE_DQ_DQS_LEN};

        // Byte 32: ATX impedance
        static constexpr field_t ATX_IMPEDANCE{ATX_IMPEDANCE_BYTE, ATX_IMPEDANCE_START, ATX_IMPEDANCE_LEN};

        // Byte 33-36: ATX Slew rise rate
        static constexpr field_t ATX_SLEW_RISE_RATE_BYTE0{ATX_SLEW_RISE_RATE_BYTE0_BYTE, ATX_SLEW_RISE_RATE_BYTE0_START, ATX_SLEW_RISE_RATE_BYTE0_LEN};
        static constexpr field_t ATX_SLEW_RISE_RATE_BYTE1{ATX_SLEW_RISE_RATE_BYTE1_BYTE, ATX_SLEW_RISE_RATE_BYTE1_START, ATX_SLEW_RISE_RATE_BYTE1_LEN};
        static constexpr field_t ATX_SLEW_RISE_RATE_BYTE2{ATX_SLEW_RISE_RATE_BYTE2_BYTE, ATX_SLEW_RISE_RATE_BYTE2_START, ATX_SLEW_RISE_RATE_BYTE2_LEN};
        static constexpr field_t ATX_SLEW_RISE_RATE_BYTE3{ATX_SLEW_RISE_RATE_BYTE3_BYTE, ATX_SLEW_RISE_RATE_BYTE3_START, ATX_SLEW_RISE_RATE_BYTE3_LEN};

        // Byte 37-40: ATX Slew fall rate
        static constexpr field_t ATX_SLEW_FALL_RATE_BYTE0{ATX_SLEW_FALL_RATE_BYTE0_BYTE, ATX_SLEW_FALL_RATE_BYTE0_START, ATX_SLEW_FALL_RATE_BYTE0_LEN};
        static constexpr field_t ATX_SLEW_FALL_RATE_BYTE1{ATX_SLEW_FALL_RATE_BYTE1_BYTE, ATX_SLEW_FALL_RATE_BYTE1_START, ATX_SLEW_FALL_RATE_BYTE1_LEN};
        static constexpr field_t ATX_SLEW_FALL_RATE_BYTE2{ATX_SLEW_FALL_RATE_BYTE2_BYTE, ATX_SLEW_FALL_RATE_BYTE2_START, ATX_SLEW_FALL_RATE_BYTE2_LEN};
        static constexpr field_t ATX_SLEW_FALL_RATE_BYTE3{ATX_SLEW_FALL_RATE_BYTE3_BYTE, ATX_SLEW_FALL_RATE_BYTE3_START, ATX_SLEW_FALL_RATE_BYTE3_LEN};

        // Byte 41-44: CK Slew rise rate
        static constexpr field_t CK_SLEW_RATE_RISE_BYTE0{CK_SLEW_RATE_RISE_BYTE0_BYTE, CK_SLEW_RATE_RISE_BYTE0_START, CK_SLEW_RATE_RISE_BYTE0_LEN};
        static constexpr field_t CK_SLEW_RATE_RISE_BYTE1{CK_SLEW_RATE_RISE_BYTE1_BYTE, CK_SLEW_RATE_RISE_BYTE1_START, CK_SLEW_RATE_RISE_BYTE1_LEN};
        static constexpr field_t CK_SLEW_RATE_RISE_BYTE2{CK_SLEW_RATE_RISE_BYTE2_BYTE, CK_SLEW_RATE_RISE_BYTE2_START, CK_SLEW_RATE_RISE_BYTE2_LEN};
        static constexpr field_t CK_SLEW_RATE_RISE_BYTE3{CK_SLEW_RATE_RISE_BYTE3_BYTE, CK_SLEW_RATE_RISE_BYTE3_START, CK_SLEW_RATE_RISE_BYTE3_LEN};

        // Byte 45-48: CK Slew fall rate
        static constexpr field_t CK_SLEW_RATE_FALL_BYTE0{CK_SLEW_RATE_FALL_BYTE0_BYTE, CK_SLEW_RATE_FALL_BYTE0_START, CK_SLEW_RATE_FALL_BYTE0_LEN};
        static constexpr field_t CK_SLEW_RATE_FALL_BYTE1{CK_SLEW_RATE_FALL_BYTE1_BYTE, CK_SLEW_RATE_FALL_BYTE1_START, CK_SLEW_RATE_FALL_BYTE1_LEN};
        static constexpr field_t CK_SLEW_RATE_FALL_BYTE2{CK_SLEW_RATE_FALL_BYTE2_BYTE, CK_SLEW_RATE_FALL_BYTE2_START, CK_SLEW_RATE_FALL_BYTE2_LEN};
        static constexpr field_t CK_SLEW_RATE_FALL_BYTE3{CK_SLEW_RATE_FALL_BYTE3_BYTE, CK_SLEW_RATE_FALL_BYTE3_START, CK_SLEW_RATE_FALL_BYTE3_LEN};

        // Byte 49-52: DQ Slew rate rise
        static constexpr field_t DQ_SLEW_RATE_RISE_BYTE0{DQ_SLEW_RATE_RISE_BYTE0_BYTE, DQ_SLEW_RATE_RISE_BYTE0_START, DQ_SLEW_RATE_RISE_BYTE0_LEN};
        static constexpr field_t DQ_SLEW_RATE_RISE_BYTE1{DQ_SLEW_RATE_RISE_BYTE1_BYTE, DQ_SLEW_RATE_RISE_BYTE1_START, DQ_SLEW_RATE_RISE_BYTE1_LEN};
        static constexpr field_t DQ_SLEW_RATE_RISE_BYTE2{DQ_SLEW_RATE_RISE_BYTE2_BYTE, DQ_SLEW_RATE_RISE_BYTE2_START, DQ_SLEW_RATE_RISE_BYTE2_LEN};
        static constexpr field_t DQ_SLEW_RATE_RISE_BYTE3{DQ_SLEW_RATE_RISE_BYTE3_BYTE, DQ_SLEW_RATE_RISE_BYTE3_START, DQ_SLEW_RATE_RISE_BYTE3_LEN};

        // Byte 53-56: DQ Slew fall rate
        static constexpr field_t DQ_SLEW_RATE_FALL_BYTE0{DQ_SLEW_RATE_FALL_BYTE0_BYTE, DQ_SLEW_RATE_FALL_BYTE0_START, DQ_SLEW_RATE_FALL_BYTE0_LEN};
        static constexpr field_t DQ_SLEW_RATE_FALL_BYTE1{DQ_SLEW_RATE_FALL_BYTE1_BYTE, DQ_SLEW_RATE_FALL_BYTE1_START, DQ_SLEW_RATE_FALL_BYTE1_LEN};
        static constexpr field_t DQ_SLEW_RATE_FALL_BYTE2{DQ_SLEW_RATE_FALL_BYTE2_BYTE, DQ_SLEW_RATE_FALL_BYTE2_START, DQ_SLEW_RATE_FALL_BYTE2_LEN};
        static constexpr field_t DQ_SLEW_RATE_FALL_BYTE3{DQ_SLEW_RATE_FALL_BYTE3_BYTE, DQ_SLEW_RATE_FALL_BYTE3_START, DQ_SLEW_RATE_FALL_BYTE3_LEN};

        // Byte 60-67: RTT PARK and WR
        // BYTE0: A0 RANK0
        static constexpr field_t DRAM_RTT_PARK_BYTE0{DRAM_RTT_PARK_WR_BYTE0_BYTE, DRAM_RTT_PARK_BYTE0_START, DRAM_RTT_PARK_BYTE0_LEN};
        static constexpr field_t DRAM_RTT_WR_BYTE0{DRAM_RTT_PARK_WR_BYTE0_BYTE, DRAM_RTT_WR_BYTE0_START, DRAM_RTT_WR_BYTE0_LEN};
        // BYTE1: A0 RANK1
        static constexpr field_t DRAM_RTT_PARK_BYTE1{DRAM_RTT_PARK_WR_BYTE1_BYTE, DRAM_RTT_PARK_BYTE1_START, DRAM_RTT_PARK_BYTE1_LEN};
        static constexpr field_t DRAM_RTT_WR_BYTE1{DRAM_RTT_PARK_WR_BYTE1_BYTE, DRAM_RTT_WR_BYTE1_START, DRAM_RTT_WR_BYTE1_LEN};
        // BYTE2: B0 RANK0
        static constexpr field_t DRAM_RTT_PARK_BYTE2{DRAM_RTT_PARK_WR_BYTE2_BYTE, DRAM_RTT_PARK_BYTE2_START, DRAM_RTT_PARK_BYTE2_LEN};
        static constexpr field_t DRAM_RTT_WR_BYTE2{DRAM_RTT_PARK_WR_BYTE2_BYTE, DRAM_RTT_WR_BYTE2_START, DRAM_RTT_WR_BYTE2_LEN};
        // BYTE3: B0 RANK1
        static constexpr field_t DRAM_RTT_PARK_BYTE3{DRAM_RTT_PARK_WR_BYTE3_BYTE, DRAM_RTT_PARK_BYTE3_START, DRAM_RTT_PARK_BYTE3_LEN};
        static constexpr field_t DRAM_RTT_WR_BYTE3{DRAM_RTT_PARK_WR_BYTE3_BYTE, DRAM_RTT_WR_BYTE3_START, DRAM_RTT_WR_BYTE3_LEN};
        // BYTE4: A1 RANK0
        static constexpr field_t DRAM_RTT_PARK_BYTE4{DRAM_RTT_PARK_WR_BYTE4_BYTE, DRAM_RTT_PARK_BYTE4_START, DRAM_RTT_PARK_BYTE4_LEN};
        static constexpr field_t DRAM_RTT_WR_BYTE4{DRAM_RTT_PARK_WR_BYTE4_BYTE, DRAM_RTT_WR_BYTE4_START, DRAM_RTT_WR_BYTE4_LEN};
        // BYTE5: A1 RANK1
        static constexpr field_t DRAM_RTT_PARK_BYTE5{DRAM_RTT_PARK_WR_BYTE5_BYTE, DRAM_RTT_PARK_BYTE5_START, DRAM_RTT_PARK_BYTE5_LEN};
        static constexpr field_t DRAM_RTT_WR_BYTE5{DRAM_RTT_PARK_WR_BYTE5_BYTE, DRAM_RTT_WR_BYTE5_START, DRAM_RTT_WR_BYTE5_LEN};
        // BYTE6: B2 RANK0
        static constexpr field_t DRAM_RTT_PARK_BYTE6{DRAM_RTT_PARK_WR_BYTE6_BYTE, DRAM_RTT_PARK_BYTE6_START, DRAM_RTT_PARK_BYTE6_LEN};
        static constexpr field_t DRAM_RTT_WR_BYTE6{DRAM_RTT_PARK_WR_BYTE6_BYTE, DRAM_RTT_WR_BYTE6_START, DRAM_RTT_WR_BYTE6_LEN};
        // BYTE7: B2 RANK1
        static constexpr field_t DRAM_RTT_PARK_BYTE7{DRAM_RTT_PARK_WR_BYTE7_BYTE, DRAM_RTT_PARK_BYTE7_START, DRAM_RTT_PARK_BYTE7_LEN};
        static constexpr field_t DRAM_RTT_WR_BYTE7{DRAM_RTT_PARK_WR_BYTE7_BYTE, DRAM_RTT_WR_BYTE7_START, DRAM_RTT_WR_BYTE7_LEN};

        // Byte 68-75: DRAM RTT Nom
        // BYTE0: A0 RANK0
        static constexpr field_t DRAM_RTT_NOM_BYTE0_RD{DRAM_RTT_NOM_BYTE0_BYTE, DRAM_RTT_NOM_BYTE0_RD_START, DRAM_RTT_NOM_BYTE0_RD_LEN};
        static constexpr field_t DRAM_RTT_NOM_BYTE0_WR{DRAM_RTT_NOM_BYTE0_BYTE, DRAM_RTT_NOM_BYTE0_WR_START, DRAM_RTT_NOM_BYTE0_WR_LEN};
        // BYTE1: A0 RANK1
        static constexpr field_t DRAM_RTT_NOM_BYTE1_RD{DRAM_RTT_NOM_BYTE1_BYTE, DRAM_RTT_NOM_BYTE1_RD_START, DRAM_RTT_NOM_BYTE1_RD_LEN};
        static constexpr field_t DRAM_RTT_NOM_BYTE1_WR{DRAM_RTT_NOM_BYTE1_BYTE, DRAM_RTT_NOM_BYTE1_WR_START, DRAM_RTT_NOM_BYTE1_WR_LEN};
        // BYTE2: B0 RANK0
        static constexpr field_t DRAM_RTT_NOM_BYTE2_RD{DRAM_RTT_NOM_BYTE2_BYTE, DRAM_RTT_NOM_BYTE2_RD_START, DRAM_RTT_NOM_BYTE2_RD_LEN};
        static constexpr field_t DRAM_RTT_NOM_BYTE2_WR{DRAM_RTT_NOM_BYTE2_BYTE, DRAM_RTT_NOM_BYTE2_WR_START, DRAM_RTT_NOM_BYTE2_WR_LEN};
        // BYTE3: B0 RANK1
        static constexpr field_t DRAM_RTT_NOM_BYTE3_RD{DRAM_RTT_NOM_BYTE3_BYTE, DRAM_RTT_NOM_BYTE3_RD_START, DRAM_RTT_NOM_BYTE3_RD_LEN};
        static constexpr field_t DRAM_RTT_NOM_BYTE3_WR{DRAM_RTT_NOM_BYTE3_BYTE, DRAM_RTT_NOM_BYTE3_WR_START, DRAM_RTT_NOM_BYTE3_WR_LEN};
        // BYTE4: A1 RANK0
        static constexpr field_t DRAM_RTT_NOM_BYTE4_RD{DRAM_RTT_NOM_BYTE4_BYTE, DRAM_RTT_NOM_BYTE4_RD_START, DRAM_RTT_NOM_BYTE4_RD_LEN};
        static constexpr field_t DRAM_RTT_NOM_BYTE4_WR{DRAM_RTT_NOM_BYTE4_BYTE, DRAM_RTT_NOM_BYTE4_WR_START, DRAM_RTT_NOM_BYTE4_WR_LEN};
        // BYTE5: A1 RANK1
        static constexpr field_t DRAM_RTT_NOM_BYTE5_RD{DRAM_RTT_NOM_BYTE5_BYTE, DRAM_RTT_NOM_BYTE5_RD_START, DRAM_RTT_NOM_BYTE5_RD_LEN};
        static constexpr field_t DRAM_RTT_NOM_BYTE5_WR{DRAM_RTT_NOM_BYTE5_BYTE, DRAM_RTT_NOM_BYTE5_WR_START, DRAM_RTT_NOM_BYTE5_WR_LEN};
        // BYTE6: B2 RANK0
        static constexpr field_t DRAM_RTT_NOM_BYTE6_RD{DRAM_RTT_NOM_BYTE6_BYTE, DRAM_RTT_NOM_BYTE6_RD_START, DRAM_RTT_NOM_BYTE6_RD_LEN};
        static constexpr field_t DRAM_RTT_NOM_BYTE6_WR{DRAM_RTT_NOM_BYTE6_BYTE, DRAM_RTT_NOM_BYTE6_WR_START, DRAM_RTT_NOM_BYTE6_WR_LEN};
        // BYTE7: B2 RANK1
        static constexpr field_t DRAM_RTT_NOM_BYTE7_RD{DRAM_RTT_NOM_BYTE7_BYTE, DRAM_RTT_NOM_BYTE7_RD_START, DRAM_RTT_NOM_BYTE7_RD_LEN};
        static constexpr field_t DRAM_RTT_NOM_BYTE7_WR{DRAM_RTT_NOM_BYTE7_BYTE, DRAM_RTT_NOM_BYTE7_WR_START, DRAM_RTT_NOM_BYTE7_WR_LEN};

        // Byte 76: PHY Equalization
        static constexpr field_t PHY_EQUALIZATION_DFFE{PHY_EQUALIZATION_BYTE, PHY_EQUALIZATION_DFFE_START, PHY_EQUALIZATION_DFFE_LEN};
        static constexpr field_t PHY_EQUALIZATION_RDFE{PHY_EQUALIZATION_BYTE, PHY_EQUALIZATION_RDFE_START, PHY_EQUALIZATION_RDFE_LEN};

        // Byte 77: Non-Target ODT RD/WR
        static constexpr field_t NT_ODT_RD_A0_B0_RANK0{NT_ODT_BYTE, NT_ODT_RD_A0_B0_RANK0_START, NT_ODT_RD_A0_B0_RANK0_LEN};
        static constexpr field_t NT_ODT_WR_A0_B0_RANK0{NT_ODT_BYTE, NT_ODT_WR_A0_B0_RANK0_START, NT_ODT_WR_A0_B0_RANK0_LEN};
        static constexpr field_t NT_ODT_RD_A1_B1_RANK0{NT_ODT_BYTE, NT_ODT_RD_A1_B1_RANK0_START, NT_ODT_RD_A1_B1_RANK0_LEN};
        static constexpr field_t NT_ODT_WR_A1_B1_RANK0{NT_ODT_BYTE, NT_ODT_WR_A1_B1_RANK0_START, NT_ODT_WR_A1_B1_RANK0_LEN};
        static constexpr field_t NT_ODT_RD_A0_B0_RANK1{NT_ODT_BYTE, NT_ODT_RD_A0_B0_RANK1_START, NT_ODT_RD_A0_B0_RANK1_LEN};
        static constexpr field_t NT_ODT_WR_A0_B0_RANK1{NT_ODT_BYTE, NT_ODT_WR_A0_B0_RANK1_START, NT_ODT_WR_A0_B0_RANK1_LEN};
        static constexpr field_t NT_ODT_RD_A1_B1_RANK1{NT_ODT_BYTE, NT_ODT_RD_A1_B1_RANK1_START, NT_ODT_RD_A1_B1_RANK1_LEN};
        static constexpr field_t NT_ODT_WR_A1_B1_RANK1{NT_ODT_BYTE, NT_ODT_WR_A1_B1_RANK1_START, NT_ODT_WR_A1_B1_RANK1_LEN};

        // Byte 78: DFI Max Read Latency
        static constexpr field_t DFIMRL_DDRCLK{DFI_MAX_RD_LATENCY_BYTE, DFIMRL_DDRCLK_START, DFIMRL_DDRCLK_LEN};

        // Byte 82-89: Group A CK/CS ODT and CA
        // BYTE0: A0 RANK0
        static constexpr field_t ODT_CA_GRPA_CK_BYTE0{ODT_CA_GRPA_BYTE0_BYTE, ODT_CA_GRPA_CK_BYTE0_START, ODT_CA_GRPA_CK_BYTE0_LEN};
        static constexpr field_t ODT_CA_GRPA_CS_BYTE0{ODT_CA_GRPA_BYTE0_BYTE, ODT_CA_GRPA_CS_BYTE0_START, ODT_CA_GRPA_CS_BYTE0_LEN};
        // BYTE1: A0 RANK1
        static constexpr field_t ODT_CA_GRPA_CK_BYTE1{ODT_CA_GRPA_BYTE1_BYTE, ODT_CA_GRPA_CK_BYTE1_START, ODT_CA_GRPA_CK_BYTE1_LEN};
        static constexpr field_t ODT_CA_GRPA_CS_BYTE1{ODT_CA_GRPA_BYTE1_BYTE, ODT_CA_GRPA_CS_BYTE1_START, ODT_CA_GRPA_CS_BYTE1_LEN};
        // BYTE2: B0 RANK0
        static constexpr field_t ODT_CA_GRPA_CK_BYTE2{ODT_CA_GRPA_BYTE2_BYTE, ODT_CA_GRPA_CK_BYTE2_START, ODT_CA_GRPA_CK_BYTE2_LEN};
        static constexpr field_t ODT_CA_GRPA_CS_BYTE2{ODT_CA_GRPA_BYTE2_BYTE, ODT_CA_GRPA_CS_BYTE2_START, ODT_CA_GRPA_CS_BYTE2_LEN};
        // BYTE3: B0 RANK1
        static constexpr field_t ODT_CA_GRPA_CK_BYTE3{ODT_CA_GRPA_BYTE3_BYTE, ODT_CA_GRPA_CK_BYTE3_START, ODT_CA_GRPA_CK_BYTE3_LEN};
        static constexpr field_t ODT_CA_GRPA_CS_BYTE3{ODT_CA_GRPA_BYTE3_BYTE, ODT_CA_GRPA_CS_BYTE3_START, ODT_CA_GRPA_CS_BYTE3_LEN};
        // BYTE4: A1 RANK0
        static constexpr field_t ODT_CA_GRPA_CK_BYTE4{ODT_CA_GRPA_BYTE4_BYTE, ODT_CA_GRPA_CK_BYTE4_START, ODT_CA_GRPA_CK_BYTE4_LEN};
        static constexpr field_t ODT_CA_GRPA_CS_BYTE4{ODT_CA_GRPA_BYTE4_BYTE, ODT_CA_GRPA_CS_BYTE4_START, ODT_CA_GRPA_CS_BYTE4_LEN};
        // BYTE5: A1 RANK1
        static constexpr field_t ODT_CA_GRPA_CK_BYTE5{ODT_CA_GRPA_BYTE5_BYTE, ODT_CA_GRPA_CK_BYTE5_START, ODT_CA_GRPA_CK_BYTE5_LEN};
        static constexpr field_t ODT_CA_GRPA_CS_BYTE5{ODT_CA_GRPA_BYTE5_BYTE, ODT_CA_GRPA_CS_BYTE5_START, ODT_CA_GRPA_CS_BYTE5_LEN};
        // BYTE6: B2 RANK0
        static constexpr field_t ODT_CA_GRPA_CK_BYTE6{ODT_CA_GRPA_BYTE6_BYTE, ODT_CA_GRPA_CK_BYTE6_START, ODT_CA_GRPA_CK_BYTE6_LEN};
        static constexpr field_t ODT_CA_GRPA_CS_BYTE6{ODT_CA_GRPA_BYTE6_BYTE, ODT_CA_GRPA_CS_BYTE6_START, ODT_CA_GRPA_CS_BYTE6_LEN};
        // BYTE7: B2 RANK1
        static constexpr field_t ODT_CA_GRPA_CK_BYTE7{ODT_CA_GRPA_BYTE7_BYTE, ODT_CA_GRPA_CK_BYTE7_START, ODT_CA_GRPA_CK_BYTE7_LEN};
        static constexpr field_t ODT_CA_GRPA_CS_BYTE7{ODT_CA_GRPA_BYTE7_BYTE, ODT_CA_GRPA_CS_BYTE7_START, ODT_CA_GRPA_CS_BYTE7_LEN};

        // Byte 90-97: Group B CK/CS ODT and CA
        // BYTE0: A0 RANK0
        static constexpr field_t ODT_CA_GRPB_CK_BYTE0{ODT_CA_GRPB_BYTE0_BYTE, ODT_CA_GRPB_CK_BYTE0_START, ODT_CA_GRPB_CK_BYTE0_LEN};
        static constexpr field_t ODT_CA_GRPB_CS_BYTE0{ODT_CA_GRPB_BYTE0_BYTE, ODT_CA_GRPB_CS_BYTE0_START, ODT_CA_GRPB_CS_BYTE0_LEN};
        // BYTE1: A0 RANK1
        static constexpr field_t ODT_CA_GRPB_CK_BYTE1{ODT_CA_GRPB_BYTE1_BYTE, ODT_CA_GRPB_CK_BYTE1_START, ODT_CA_GRPB_CK_BYTE1_LEN};
        static constexpr field_t ODT_CA_GRPB_CS_BYTE1{ODT_CA_GRPB_BYTE1_BYTE, ODT_CA_GRPB_CS_BYTE1_START, ODT_CA_GRPB_CS_BYTE1_LEN};
        // BYTE2: B0 RANK0
        static constexpr field_t ODT_CA_GRPB_CK_BYTE2{ODT_CA_GRPB_BYTE2_BYTE, ODT_CA_GRPB_CK_BYTE2_START, ODT_CA_GRPB_CK_BYTE2_LEN};
        static constexpr field_t ODT_CA_GRPB_CS_BYTE2{ODT_CA_GRPB_BYTE2_BYTE, ODT_CA_GRPB_CS_BYTE2_START, ODT_CA_GRPB_CS_BYTE2_LEN};
        // BYTE3: B0 RANK1
        static constexpr field_t ODT_CA_GRPB_CK_BYTE3{ODT_CA_GRPB_BYTE3_BYTE, ODT_CA_GRPB_CK_BYTE3_START, ODT_CA_GRPB_CK_BYTE3_LEN};
        static constexpr field_t ODT_CA_GRPB_CS_BYTE3{ODT_CA_GRPB_BYTE3_BYTE, ODT_CA_GRPB_CS_BYTE3_START, ODT_CA_GRPB_CS_BYTE3_LEN};
        // BYTE4: A1 RANK0
        static constexpr field_t ODT_CA_GRPB_CK_BYTE4{ODT_CA_GRPB_BYTE4_BYTE, ODT_CA_GRPB_CK_BYTE4_START, ODT_CA_GRPB_CK_BYTE4_LEN};
        static constexpr field_t ODT_CA_GRPB_CS_BYTE4{ODT_CA_GRPB_BYTE4_BYTE, ODT_CA_GRPB_CS_BYTE4_START, ODT_CA_GRPB_CS_BYTE4_LEN};
        // BYTE5: A1 RANK1
        static constexpr field_t ODT_CA_GRPB_CK_BYTE5{ODT_CA_GRPB_BYTE5_BYTE, ODT_CA_GRPB_CK_BYTE5_START, ODT_CA_GRPB_CK_BYTE5_LEN};
        static constexpr field_t ODT_CA_GRPB_CS_BYTE5{ODT_CA_GRPB_BYTE5_BYTE, ODT_CA_GRPB_CS_BYTE5_START, ODT_CA_GRPB_CS_BYTE5_LEN};
        // BYTE6: B2 RANK0
        static constexpr field_t ODT_CA_GRPB_CK_BYTE6{ODT_CA_GRPB_BYTE6_BYTE, ODT_CA_GRPB_CK_BYTE6_START, ODT_CA_GRPB_CK_BYTE6_LEN};
        static constexpr field_t ODT_CA_GRPB_CS_BYTE6{ODT_CA_GRPB_BYTE6_BYTE, ODT_CA_GRPB_CS_BYTE6_START, ODT_CA_GRPB_CS_BYTE6_LEN};
        // BYTE7: B2 RANK1
        static constexpr field_t ODT_CA_GRPB_CK_BYTE7{ODT_CA_GRPB_BYTE7_BYTE, ODT_CA_GRPB_CK_BYTE7_START, ODT_CA_GRPB_CK_BYTE7_LEN};
        static constexpr field_t ODT_CA_GRPB_CS_BYTE7{ODT_CA_GRPB_BYTE7_BYTE, ODT_CA_GRPB_CS_BYTE7_START, ODT_CA_GRPB_CS_BYTE7_LEN};

        // Byte 98-177: CK/CS ODT and CA per DRAM
        // BYTE0-BYTE9  : A0 RANK0
        static constexpr field_t ODT_CA_CK_BYTE0{ODT_CA_BYTE0_BYTE, ODT_CA_CK_BYTE0_START, ODT_CA_CK_BYTE0_LEN};
        static constexpr field_t ODT_CA_CS_BYTE0{ODT_CA_BYTE0_BYTE, ODT_CA_CS_BYTE0_START, ODT_CA_CS_BYTE0_LEN};
        static constexpr field_t ODT_CA_BYTE0_EXP_GRP{ODT_CA_BYTE0_BYTE, ODT_CA_BYTE0_EXP_GRP_START, ODT_CA_BYTE0_EXP_GRP_LEN};

        // Byte 178-185: CA ODT and DQS for GROUPA
        // BYTE0: A0 RANK0
        static constexpr field_t CA_ODT_DQS_GRPA_BYTE0{CA_ODT_DQS_GRPA_BYTE0_BYTE, CA_ODT_GRPA_BYTE0_START, CA_ODT_GRPA_BYTE0_LEN};
        static constexpr field_t DQS_RTT_PARK_GRPA_BYTE0{CA_ODT_DQS_GRPA_BYTE0_BYTE, DQS_RTT_PARK_GRPA_BYTE0_START, DQS_RTT_PARK_GRPA_BYTE0_LEN};
        // BYTE1: A0 RANK1
        static constexpr field_t CA_ODT_DQS_GRPA_BYTE1{CA_ODT_DQS_GRPA_BYTE1_BYTE, CA_ODT_GRPA_BYTE1_START, CA_ODT_GRPA_BYTE1_LEN};
        static constexpr field_t DQS_RTT_PARK_GRPA_BYTE1{CA_ODT_DQS_GRPA_BYTE1_BYTE, DQS_RTT_PARK_GRPA_BYTE1_START, DQS_RTT_PARK_GRPA_BYTE1_LEN};
        // BYTE2: B0 RANK0
        static constexpr field_t CA_ODT_DQS_GRPA_BYTE2{CA_ODT_DQS_GRPA_BYTE2_BYTE, CA_ODT_GRPA_BYTE2_START, CA_ODT_GRPA_BYTE2_LEN};
        static constexpr field_t DQS_RTT_PARK_GRPA_BYTE2{CA_ODT_DQS_GRPA_BYTE2_BYTE, DQS_RTT_PARK_GRPA_BYTE2_START, DQS_RTT_PARK_GRPA_BYTE2_LEN};
        // BYTE3: B0 RANK1
        static constexpr field_t CA_ODT_DQS_GRPA_BYTE3{CA_ODT_DQS_GRPA_BYTE3_BYTE, CA_ODT_GRPA_BYTE3_START, CA_ODT_GRPA_BYTE3_LEN};
        static constexpr field_t DQS_RTT_PARK_GRPA_BYTE3{CA_ODT_DQS_GRPA_BYTE3_BYTE, DQS_RTT_PARK_GRPA_BYTE3_START, DQS_RTT_PARK_GRPA_BYTE3_LEN};
        // BYTE4: A1 RANK0
        static constexpr field_t CA_ODT_DQS_GRPA_BYTE4{CA_ODT_DQS_GRPA_BYTE4_BYTE, CA_ODT_GRPA_BYTE4_START, CA_ODT_GRPA_BYTE4_LEN};
        static constexpr field_t DQS_RTT_PARK_GRPA_BYTE4{CA_ODT_DQS_GRPA_BYTE4_BYTE, DQS_RTT_PARK_GRPA_BYTE4_START, DQS_RTT_PARK_GRPA_BYTE4_LEN};
        // BYTE5: A1 RANK1
        static constexpr field_t CA_ODT_DQS_GRPA_BYTE5{CA_ODT_DQS_GRPA_BYTE5_BYTE, CA_ODT_GRPA_BYTE5_START, CA_ODT_GRPA_BYTE5_LEN};
        static constexpr field_t DQS_RTT_PARK_GRPA_BYTE5{CA_ODT_DQS_GRPA_BYTE5_BYTE, DQS_RTT_PARK_GRPA_BYTE5_START, DQS_RTT_PARK_GRPA_BYTE5_LEN};
        // BYTE6: B1 RANK0
        static constexpr field_t CA_ODT_DQS_GRPA_BYTE6{CA_ODT_DQS_GRPA_BYTE6_BYTE, CA_ODT_GRPA_BYTE6_START, CA_ODT_GRPA_BYTE6_LEN};
        static constexpr field_t DQS_RTT_PARK_GRPA_BYTE6{CA_ODT_DQS_GRPA_BYTE6_BYTE, DQS_RTT_PARK_GRPA_BYTE6_START, DQS_RTT_PARK_GRPA_BYTE6_LEN};
        // BYTE7: B1 RANK1
        static constexpr field_t CA_ODT_DQS_GRPA_BYTE7{CA_ODT_DQS_GRPA_BYTE7_BYTE, CA_ODT_GRPA_BYTE7_START, CA_ODT_GRPA_BYTE7_LEN};
        static constexpr field_t DQS_RTT_PARK_GRPA_BYTE7{CA_ODT_DQS_GRPA_BYTE7_BYTE, DQS_RTT_PARK_GRPA_BYTE7_START, DQS_RTT_PARK_GRPA_BYTE7_LEN};

        // Byte 186-193: CA ODT and DQS for GROUPB
        // BYTE0: A0 RANK0
        static constexpr field_t CA_ODT_DQS_GRPB_BYTE0{CA_ODT_DQS_GRPB_BYTE0_BYTE, CA_ODT_GRPB_BYTE0_START, CA_ODT_GRPB_BYTE0_LEN};
        static constexpr field_t DQS_RTT_PARK_GRPB_BYTE0{CA_ODT_DQS_GRPB_BYTE0_BYTE, DQS_RTT_PARK_GRPB_BYTE0_START, DQS_RTT_PARK_GRPB_BYTE0_LEN};
        // BYTE1: A0 RANK1
        static constexpr field_t CA_ODT_DQS_GRPB_BYTE1{CA_ODT_DQS_GRPB_BYTE1_BYTE, CA_ODT_GRPB_BYTE1_START, CA_ODT_GRPB_BYTE1_LEN};
        static constexpr field_t DQS_RTT_PARK_GRPB_BYTE1{CA_ODT_DQS_GRPB_BYTE1_BYTE, DQS_RTT_PARK_GRPB_BYTE1_START, DQS_RTT_PARK_GRPB_BYTE1_LEN};
        // BYTE2: B0 RANK0
        static constexpr field_t CA_ODT_DQS_GRPB_BYTE2{CA_ODT_DQS_GRPB_BYTE2_BYTE, CA_ODT_GRPB_BYTE2_START, CA_ODT_GRPB_BYTE2_LEN};
        static constexpr field_t DQS_RTT_PARK_GRPB_BYTE2{CA_ODT_DQS_GRPB_BYTE2_BYTE, DQS_RTT_PARK_GRPB_BYTE2_START, DQS_RTT_PARK_GRPB_BYTE2_LEN};
        // BYTE3: B0 RANK1
        static constexpr field_t CA_ODT_DQS_GRPB_BYTE3{CA_ODT_DQS_GRPB_BYTE3_BYTE, CA_ODT_GRPB_BYTE3_START, CA_ODT_GRPB_BYTE3_LEN};
        static constexpr field_t DQS_RTT_PARK_GRPB_BYTE3{CA_ODT_DQS_GRPB_BYTE3_BYTE, DQS_RTT_PARK_GRPB_BYTE3_START, DQS_RTT_PARK_GRPB_BYTE3_LEN};
        // BYTE4: A1 RANK0
        static constexpr field_t CA_ODT_DQS_GRPB_BYTE4{CA_ODT_DQS_GRPB_BYTE4_BYTE, CA_ODT_GRPB_BYTE4_START, CA_ODT_GRPB_BYTE4_LEN};
        static constexpr field_t DQS_RTT_PARK_GRPB_BYTE4{CA_ODT_DQS_GRPB_BYTE4_BYTE, DQS_RTT_PARK_GRPB_BYTE4_START, DQS_RTT_PARK_GRPB_BYTE4_LEN};
        // BYTE5: A1 RANK1
        static constexpr field_t CA_ODT_DQS_GRPB_BYTE5{CA_ODT_DQS_GRPB_BYTE5_BYTE, CA_ODT_GRPB_BYTE5_START, CA_ODT_GRPB_BYTE5_LEN};
        static constexpr field_t DQS_RTT_PARK_GRPB_BYTE5{CA_ODT_DQS_GRPB_BYTE5_BYTE, DQS_RTT_PARK_GRPB_BYTE5_START, DQS_RTT_PARK_GRPB_BYTE5_LEN};
        // BYTE6: B1 RANK0
        static constexpr field_t CA_ODT_DQS_GRPB_BYTE6{CA_ODT_DQS_GRPB_BYTE6_BYTE, CA_ODT_GRPB_BYTE6_START, CA_ODT_GRPB_BYTE6_LEN};
        static constexpr field_t DQS_RTT_PARK_GRPB_BYTE6{CA_ODT_DQS_GRPB_BYTE6_BYTE, DQS_RTT_PARK_GRPB_BYTE6_START, DQS_RTT_PARK_GRPB_BYTE6_LEN};
        // BYTE7: B1 RANK1
        static constexpr field_t CA_ODT_DQS_GRPB_BYTE7{CA_ODT_DQS_GRPB_BYTE7_BYTE, CA_ODT_GRPB_BYTE7_START, CA_ODT_GRPB_BYTE7_LEN};
        static constexpr field_t DQS_RTT_PARK_GRPB_BYTE7{CA_ODT_DQS_GRPB_BYTE7_BYTE, DQS_RTT_PARK_GRPB_BYTE7_START, DQS_RTT_PARK_GRPB_BYTE7_LEN};

        // Byte 194-273: CA ODT and DQS per DRAM
        // BYTE0-BYTE9  : A0 RANK0
        static constexpr field_t CA_ODT_BYTE0{CA_ODT_DQS_BYTE0_BYTE, CA_ODT_BYTE0_START, CA_ODT_BYTE0_LEN};
        static constexpr field_t DQS_RTT_PARK_BYTE0{CA_ODT_DQS_BYTE0_BYTE, DQS_RTT_PARK_BYTE0_START, DQS_RTT_PARK_BYTE0_LEN};

        // Byte 274-281: ODTL Write Control Offset
        // BYTE0: A0 RANK0
        static constexpr field_t ODTL_WR_CNTRL_ON_OFFSET_BYTE0{ODTL_WR_CNTRL_OFFSET_BYTE0_BYTE, ODTL_WR_CNTRL_ON_OFFSET_BYTE0_START, ODTL_WR_CNTRL_ON_OFFSET_BYTE0_LEN};
        static constexpr field_t ODTL_WR_CNTRL_OFF_OFFSET_BYTE0{ODTL_WR_CNTRL_OFFSET_BYTE0_BYTE, ODTL_WR_CNTRL_OFF_OFFSET_BYTE0_START, ODTL_WR_CNTRL_OFF_OFFSET_BYTE0_LEN};
        // BYTE1: A0 RANK1
        static constexpr field_t ODTL_WR_CNTRL_ON_OFFSET_BYTE1{ODTL_WR_CNTRL_OFFSET_BYTE1_BYTE, ODTL_WR_CNTRL_ON_OFFSET_BYTE1_START, ODTL_WR_CNTRL_ON_OFFSET_BYTE1_LEN};
        static constexpr field_t ODTL_WR_CNTRL_OFF_OFFSET_BYTE1{ODTL_WR_CNTRL_OFFSET_BYTE1_BYTE, ODTL_WR_CNTRL_OFF_OFFSET_BYTE1_START, ODTL_WR_CNTRL_OFF_OFFSET_BYTE1_LEN};
        // BYTE2: B0 RANK0
        static constexpr field_t ODTL_WR_CNTRL_ON_OFFSET_BYTE2{ODTL_WR_CNTRL_OFFSET_BYTE2_BYTE, ODTL_WR_CNTRL_ON_OFFSET_BYTE2_START, ODTL_WR_CNTRL_ON_OFFSET_BYTE2_LEN};
        static constexpr field_t ODTL_WR_CNTRL_OFF_OFFSET_BYTE2{ODTL_WR_CNTRL_OFFSET_BYTE2_BYTE, ODTL_WR_CNTRL_OFF_OFFSET_BYTE2_START, ODTL_WR_CNTRL_OFF_OFFSET_BYTE2_LEN};
        // BYTE3: B0 RANK1
        static constexpr field_t ODTL_WR_CNTRL_ON_OFFSET_BYTE3{ODTL_WR_CNTRL_OFFSET_BYTE3_BYTE, ODTL_WR_CNTRL_ON_OFFSET_BYTE3_START, ODTL_WR_CNTRL_ON_OFFSET_BYTE3_LEN};
        static constexpr field_t ODTL_WR_CNTRL_OFF_OFFSET_BYTE3{ODTL_WR_CNTRL_OFFSET_BYTE3_BYTE, ODTL_WR_CNTRL_OFF_OFFSET_BYTE3_START, ODTL_WR_CNTRL_OFF_OFFSET_BYTE3_LEN};
        // BYTE4: A1 RANK0
        static constexpr field_t ODTL_WR_CNTRL_ON_OFFSET_BYTE4{ODTL_WR_CNTRL_OFFSET_BYTE4_BYTE, ODTL_WR_CNTRL_ON_OFFSET_BYTE4_START, ODTL_WR_CNTRL_ON_OFFSET_BYTE4_LEN};
        static constexpr field_t ODTL_WR_CNTRL_OFF_OFFSET_BYTE4{ODTL_WR_CNTRL_OFFSET_BYTE4_BYTE, ODTL_WR_CNTRL_OFF_OFFSET_BYTE4_START, ODTL_WR_CNTRL_OFF_OFFSET_BYTE4_LEN};
        // BYTE5: A1 RANK1
        static constexpr field_t ODTL_WR_CNTRL_ON_OFFSET_BYTE5{ODTL_WR_CNTRL_OFFSET_BYTE5_BYTE, ODTL_WR_CNTRL_ON_OFFSET_BYTE5_START, ODTL_WR_CNTRL_ON_OFFSET_BYTE5_LEN};
        static constexpr field_t ODTL_WR_CNTRL_OFF_OFFSET_BYTE5{ODTL_WR_CNTRL_OFFSET_BYTE5_BYTE, ODTL_WR_CNTRL_OFF_OFFSET_BYTE5_START, ODTL_WR_CNTRL_OFF_OFFSET_BYTE5_LEN};
        // BYTE6: B1 RANK0
        static constexpr field_t ODTL_WR_CNTRL_ON_OFFSET_BYTE6{ODTL_WR_CNTRL_OFFSET_BYTE6_BYTE, ODTL_WR_CNTRL_ON_OFFSET_BYTE6_START, ODTL_WR_CNTRL_ON_OFFSET_BYTE6_LEN};
        static constexpr field_t ODTL_WR_CNTRL_OFF_OFFSET_BYTE6{ODTL_WR_CNTRL_OFFSET_BYTE6_BYTE, ODTL_WR_CNTRL_OFF_OFFSET_BYTE6_START, ODTL_WR_CNTRL_OFF_OFFSET_BYTE6_LEN};
        // BYTE7: B1 RANK1
        static constexpr field_t ODTL_WR_CNTRL_ON_OFFSET_BYTE7{ODTL_WR_CNTRL_OFFSET_BYTE7_BYTE, ODTL_WR_CNTRL_ON_OFFSET_BYTE7_START, ODTL_WR_CNTRL_ON_OFFSET_BYTE7_LEN};
        static constexpr field_t ODTL_WR_CNTRL_OFF_OFFSET_BYTE7{ODTL_WR_CNTRL_OFFSET_BYTE7_BYTE, ODTL_WR_CNTRL_OFF_OFFSET_BYTE7_START, ODTL_WR_CNTRL_OFF_OFFSET_BYTE7_LEN};

        // Byte 282-289: ODTL NT Write Control Offset
        // BYTE0: A0 RANK0
        static constexpr field_t ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE0{ODTL_NT_WR_CNTRL_OFFSET_BYTE0_BYTE, ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE0_START, ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE0_LEN};
        static constexpr field_t ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE0{ODTL_NT_WR_CNTRL_OFFSET_BYTE0_BYTE, ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE0_START, ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE0_LEN};
        // BYTE1: A0 RANK1
        static constexpr field_t ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE1{ODTL_NT_WR_CNTRL_OFFSET_BYTE1_BYTE, ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE1_START, ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE1_LEN};
        static constexpr field_t ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE1{ODTL_NT_WR_CNTRL_OFFSET_BYTE1_BYTE, ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE1_START, ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE1_LEN};
        // BYTE2: B0 RANK0
        static constexpr field_t ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE2{ODTL_NT_WR_CNTRL_OFFSET_BYTE2_BYTE, ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE2_START, ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE2_LEN};
        static constexpr field_t ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE2{ODTL_NT_WR_CNTRL_OFFSET_BYTE2_BYTE, ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE2_START, ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE2_LEN};
        // BYTE3: B0 RANK1
        static constexpr field_t ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE3{ODTL_NT_WR_CNTRL_OFFSET_BYTE3_BYTE, ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE3_START, ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE3_LEN};
        static constexpr field_t ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE3{ODTL_NT_WR_CNTRL_OFFSET_BYTE3_BYTE, ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE3_START, ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE3_LEN};
        // BYTE4: A1 RANK0
        static constexpr field_t ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE4{ODTL_NT_WR_CNTRL_OFFSET_BYTE4_BYTE, ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE4_START, ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE4_LEN};
        static constexpr field_t ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE4{ODTL_NT_WR_CNTRL_OFFSET_BYTE4_BYTE, ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE4_START, ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE4_LEN};
        // BYTE5: A1 RANK1
        static constexpr field_t ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE5{ODTL_NT_WR_CNTRL_OFFSET_BYTE5_BYTE, ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE5_START, ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE5_LEN};
        static constexpr field_t ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE5{ODTL_NT_WR_CNTRL_OFFSET_BYTE5_BYTE, ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE5_START, ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE5_LEN};
        // BYTE6: B1 RANK0
        static constexpr field_t ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE6{ODTL_NT_WR_CNTRL_OFFSET_BYTE6_BYTE, ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE6_START, ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE6_LEN};
        static constexpr field_t ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE6{ODTL_NT_WR_CNTRL_OFFSET_BYTE6_BYTE, ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE6_START, ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE6_LEN};
        // BYTE7: B1 RANK1
        static constexpr field_t ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE7{ODTL_NT_WR_CNTRL_OFFSET_BYTE7_BYTE, ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE7_START, ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE7_LEN};
        static constexpr field_t ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE7{ODTL_NT_WR_CNTRL_OFFSET_BYTE7_BYTE, ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE7_START, ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE7_LEN};

        // Byte 290-297: ODTL NT Read Control Offset
        // BYTE0: A0 RANK0
        static constexpr field_t ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE0{ODTL_NT_RD_CNTRL_OFFSET_BYTE0_BYTE, ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE0_START, ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE0_LEN};
        static constexpr field_t ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE0{ODTL_NT_RD_CNTRL_OFFSET_BYTE0_BYTE, ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE0_START, ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE0_LEN};
        // BYTE1: A0 RANK1
        static constexpr field_t ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE1{ODTL_NT_RD_CNTRL_OFFSET_BYTE1_BYTE, ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE1_START, ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE1_LEN};
        static constexpr field_t ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE1{ODTL_NT_RD_CNTRL_OFFSET_BYTE1_BYTE, ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE1_START, ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE1_LEN};
        // BYTE2: B0 RANK0
        static constexpr field_t ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE2{ODTL_NT_RD_CNTRL_OFFSET_BYTE2_BYTE, ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE2_START, ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE2_LEN};
        static constexpr field_t ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE2{ODTL_NT_RD_CNTRL_OFFSET_BYTE2_BYTE, ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE2_START, ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE2_LEN};
        // BYTE3: B0 RANK1
        static constexpr field_t ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE3{ODTL_NT_RD_CNTRL_OFFSET_BYTE3_BYTE, ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE3_START, ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE3_LEN};
        static constexpr field_t ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE3{ODTL_NT_RD_CNTRL_OFFSET_BYTE3_BYTE, ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE3_START, ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE3_LEN};
        // BYTE4: A1 RANK0
        static constexpr field_t ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE4{ODTL_NT_RD_CNTRL_OFFSET_BYTE4_BYTE, ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE4_START, ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE4_LEN};
        static constexpr field_t ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE4{ODTL_NT_RD_CNTRL_OFFSET_BYTE4_BYTE, ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE4_START, ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE4_LEN};
        // BYTE5: A1 RANK1
        static constexpr field_t ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE5{ODTL_NT_RD_CNTRL_OFFSET_BYTE5_BYTE, ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE5_START, ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE5_LEN};
        static constexpr field_t ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE5{ODTL_NT_RD_CNTRL_OFFSET_BYTE5_BYTE, ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE5_START, ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE5_LEN};
        // BYTE6: B1 RANK0
        static constexpr field_t ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE6{ODTL_NT_RD_CNTRL_OFFSET_BYTE6_BYTE, ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE6_START, ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE6_LEN};
        static constexpr field_t ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE6{ODTL_NT_RD_CNTRL_OFFSET_BYTE6_BYTE, ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE6_START, ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE6_LEN};
        // BYTE7: B1 RANK1
        static constexpr field_t ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE7{ODTL_NT_RD_CNTRL_OFFSET_BYTE7_BYTE, ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE7_START, ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE7_LEN};
        static constexpr field_t ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE7{ODTL_NT_RD_CNTRL_OFFSET_BYTE7_BYTE, ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE7_START, ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE7_LEN};

        // Byte 306-313: Base Vref CA
        // BYTE0: A0 RANK0
        static constexpr field_t BASE_VREF_CA_BYTE0{BASE_VREF_CA_BYTE0_BYTE, BASE_VREF_CA_BYTE0_START, BASE_VREF_CA_BYTE0_LEN};
        // BYTE1: A0 RANK1
        static constexpr field_t BASE_VREF_CA_BYTE1{BASE_VREF_CA_BYTE1_BYTE, BASE_VREF_CA_BYTE1_START, BASE_VREF_CA_BYTE1_LEN};
        // BYTE2: B0 RANK0
        static constexpr field_t BASE_VREF_CA_BYTE2{BASE_VREF_CA_BYTE2_BYTE, BASE_VREF_CA_BYTE2_START, BASE_VREF_CA_BYTE2_LEN};
        // BYTE3: B0 RANK1
        static constexpr field_t BASE_VREF_CA_BYTE3{BASE_VREF_CA_BYTE3_BYTE, BASE_VREF_CA_BYTE3_START, BASE_VREF_CA_BYTE3_LEN};
        // BYTE4: A1 RANK0
        static constexpr field_t BASE_VREF_CA_BYTE4{BASE_VREF_CA_BYTE4_BYTE, BASE_VREF_CA_BYTE4_START, BASE_VREF_CA_BYTE4_LEN};
        // BYTE5: A1 RANK1
        static constexpr field_t BASE_VREF_CA_BYTE5{BASE_VREF_CA_BYTE5_BYTE, BASE_VREF_CA_BYTE5_START, BASE_VREF_CA_BYTE5_LEN};
        // BYTE6: B2 RANK0
        static constexpr field_t BASE_VREF_CA_BYTE6{BASE_VREF_CA_BYTE6_BYTE, BASE_VREF_CA_BYTE6_START, BASE_VREF_CA_BYTE6_LEN};
        // BYTE7: B2 RANK1
        static constexpr field_t BASE_VREF_CA_BYTE7{BASE_VREF_CA_BYTE7_BYTE, BASE_VREF_CA_BYTE7_START, BASE_VREF_CA_BYTE7_LEN};

        // Byte 314-322: Base Vref CS
        // BYTE0: A0 RANK0
        static constexpr field_t BASE_VREF_CS_BYTE0{BASE_VREF_CS_BYTE0_BYTE, BASE_VREF_CS_BYTE0_START, BASE_VREF_CS_BYTE0_LEN};
        // BYTE1: A0 RANK1
        static constexpr field_t BASE_VREF_CS_BYTE1{BASE_VREF_CS_BYTE1_BYTE, BASE_VREF_CS_BYTE1_START, BASE_VREF_CS_BYTE1_LEN};
        // BYTE2: B0 RANK0
        static constexpr field_t BASE_VREF_CS_BYTE2{BASE_VREF_CS_BYTE2_BYTE, BASE_VREF_CS_BYTE2_START, BASE_VREF_CS_BYTE2_LEN};
        // BYTE3: B0 RANK1
        static constexpr field_t BASE_VREF_CS_BYTE3{BASE_VREF_CS_BYTE3_BYTE, BASE_VREF_CS_BYTE3_START, BASE_VREF_CS_BYTE3_LEN};
        // BYTE4: A1 RANK0
        static constexpr field_t BASE_VREF_CS_BYTE4{BASE_VREF_CS_BYTE4_BYTE, BASE_VREF_CS_BYTE4_START, BASE_VREF_CS_BYTE4_LEN};
        // BYTE5: A1 RANK1
        static constexpr field_t BASE_VREF_CS_BYTE5{BASE_VREF_CS_BYTE5_BYTE, BASE_VREF_CS_BYTE5_START, BASE_VREF_CS_BYTE5_LEN};
        // BYTE6: B2 RANK0
        static constexpr field_t BASE_VREF_CS_BYTE6{BASE_VREF_CS_BYTE6_BYTE, BASE_VREF_CS_BYTE6_START, BASE_VREF_CS_BYTE6_LEN};
        // BYTE7: B2 RANK1
        static constexpr field_t BASE_VREF_CS_BYTE7{BASE_VREF_CS_BYTE7_BYTE, BASE_VREF_CS_BYTE7_START, BASE_VREF_CS_BYTE7_LEN};

        // Byte 322: Vref CA/CS Offset Multiplier
        static constexpr field_t VREF_CA_OFFSET_MULT{VREF_OFFSET_MULT_BYTE, VREF_CA_OFFSET_MULT_START, VREF_CA_OFFSET_MULT_LEN};

        // Byte 324-403: Vref CA/CS Offset
        // BYTE0-BYTE9  : A0 RANK0
        static constexpr field_t VREF_CA_OFFSET_MULT_BYTE0{VREF_OFFSET_MULT_BYTE0_BYTE, VREF_CA_OFFSET_MULT_BYTE0_START, VREF_CA_OFFSET_MULT_BYTE0_LEN };
        static constexpr field_t VREF_CS_OFFSET_MULT_BYTE0{VREF_OFFSET_MULT_BYTE0_BYTE, VREF_CS_OFFSET_MULT_BYTE0_START, VREF_CS_OFFSET_MULT_BYTE0_LEN};
        static constexpr field_t VREF_CA_OFFSET_BYTE0_ADD_SUB{VREF_OFFSET_MULT_BYTE0_BYTE, VREF_CA_OFFSET_BYTE0_ADD_SUB_START, VREF_CA_OFFSET_BYTE0_ADD_SUB_LEN};
        static constexpr field_t VREF_CS_OFFSET_BYTE0_ADD_SUB{VREF_OFFSET_MULT_BYTE0_BYTE, VREF_CS_OFFSET_BYTE0_ADD_SUB_START, VREF_CS_OFFSET_BYTE0_ADD_SUB_LEN};
        // BYTE9-BYTE19 : A0 RANK1
        static constexpr field_t VREF_CA_OFFSET_MULT_BYTE10{VREF_OFFSET_MULT_BYTE10_BYTE, VREF_CA_OFFSET_MULT_BYTE10_START, VREF_CA_OFFSET_MULT_BYTE10_LEN };
        static constexpr field_t VREF_CS_OFFSET_MULT_BYTE10{VREF_OFFSET_MULT_BYTE10_BYTE, VREF_CS_OFFSET_MULT_BYTE10_START, VREF_CS_OFFSET_MULT_BYTE10_LEN};
        static constexpr field_t VREF_CA_OFFSET_BYTE10_ADD_SUB{VREF_OFFSET_MULT_BYTE10_BYTE, VREF_CA_OFFSET_BYTE10_ADD_SUB_START, VREF_CA_OFFSET_BYTE10_ADD_SUB_LEN};
        static constexpr field_t VREF_CS_OFFSET_BYTE10_ADD_SUB{VREF_OFFSET_MULT_BYTE10_BYTE, VREF_CS_OFFSET_BYTE10_ADD_SUB_START, VREF_CS_OFFSET_BYTE10_ADD_SUB_LEN};
        // BYTE20-BYTE29: B0 RANK0
        static constexpr field_t VREF_CA_OFFSET_MULT_BYTE20{VREF_OFFSET_MULT_BYTE20_BYTE, VREF_CA_OFFSET_MULT_BYTE20_START, VREF_CA_OFFSET_MULT_BYTE20_LEN };
        static constexpr field_t VREF_CS_OFFSET_MULT_BYTE20{VREF_OFFSET_MULT_BYTE20_BYTE, VREF_CS_OFFSET_MULT_BYTE20_START, VREF_CS_OFFSET_MULT_BYTE20_LEN};
        static constexpr field_t VREF_CA_OFFSET_BYTE20_ADD_SUB{VREF_OFFSET_MULT_BYTE20_BYTE, VREF_CA_OFFSET_BYTE20_ADD_SUB_START, VREF_CA_OFFSET_BYTE20_ADD_SUB_LEN};
        static constexpr field_t VREF_CS_OFFSET_BYTE20_ADD_SUB{VREF_OFFSET_MULT_BYTE20_BYTE, VREF_CS_OFFSET_BYTE20_ADD_SUB_START, VREF_CS_OFFSET_BYTE20_ADD_SUB_LEN};
        // BYTE30-BYTE39: B0 RANK1
        static constexpr field_t VREF_CA_OFFSET_MULT_BYTE30{VREF_OFFSET_MULT_BYTE30_BYTE, VREF_CA_OFFSET_MULT_BYTE30_START, VREF_CA_OFFSET_MULT_BYTE30_LEN };
        static constexpr field_t VREF_CS_OFFSET_MULT_BYTE30{VREF_OFFSET_MULT_BYTE30_BYTE, VREF_CS_OFFSET_MULT_BYTE30_START, VREF_CS_OFFSET_MULT_BYTE30_LEN};
        static constexpr field_t VREF_CA_OFFSET_BYTE30_ADD_SUB{VREF_OFFSET_MULT_BYTE30_BYTE, VREF_CA_OFFSET_BYTE30_ADD_SUB_START, VREF_CA_OFFSET_BYTE30_ADD_SUB_LEN};
        static constexpr field_t VREF_CS_OFFSET_BYTE30_ADD_SUB{VREF_OFFSET_MULT_BYTE30_BYTE, VREF_CS_OFFSET_BYTE30_ADD_SUB_START, VREF_CS_OFFSET_BYTE30_ADD_SUB_LEN};
        // BYTE40-BYTE49: A1 RANK0
        static constexpr field_t VREF_CA_OFFSET_MULT_BYTE40{VREF_OFFSET_MULT_BYTE30_BYTE, VREF_CA_OFFSET_MULT_BYTE40_START, VREF_CA_OFFSET_MULT_BYTE40_LEN };
        static constexpr field_t VREF_CS_OFFSET_MULT_BYTE40{VREF_OFFSET_MULT_BYTE30_BYTE, VREF_CS_OFFSET_MULT_BYTE40_START, VREF_CS_OFFSET_MULT_BYTE40_LEN};
        static constexpr field_t VREF_CA_OFFSET_BYTE40_ADD_SUB{VREF_OFFSET_MULT_BYTE40_BYTE, VREF_CA_OFFSET_BYTE40_ADD_SUB_START, VREF_CA_OFFSET_BYTE40_ADD_SUB_LEN};
        static constexpr field_t VREF_CS_OFFSET_BYTE40_ADD_SUB{VREF_OFFSET_MULT_BYTE40_BYTE, VREF_CS_OFFSET_BYTE40_ADD_SUB_START, VREF_CS_OFFSET_BYTE40_ADD_SUB_LEN};
        // BYTE50-BYTE59: A1 RANK1
        static constexpr field_t VREF_CA_OFFSET_MULT_BYTE50{VREF_OFFSET_MULT_BYTE50_BYTE, VREF_CA_OFFSET_MULT_BYTE50_START, VREF_CA_OFFSET_MULT_BYTE50_LEN };
        static constexpr field_t VREF_CS_OFFSET_MULT_BYTE50{VREF_OFFSET_MULT_BYTE50_BYTE, VREF_CS_OFFSET_MULT_BYTE50_START, VREF_CS_OFFSET_MULT_BYTE50_LEN};
        static constexpr field_t VREF_CA_OFFSET_BYTE50_ADD_SUB{VREF_OFFSET_MULT_BYTE50_BYTE, VREF_CA_OFFSET_BYTE50_ADD_SUB_START, VREF_CA_OFFSET_BYTE50_ADD_SUB_LEN};
        static constexpr field_t VREF_CS_OFFSET_BYTE50_ADD_SUB{VREF_OFFSET_MULT_BYTE50_BYTE, VREF_CS_OFFSET_BYTE50_ADD_SUB_START, VREF_CS_OFFSET_BYTE50_ADD_SUB_LEN};
        // BYTE60-BYTE69: B2 RANK0
        static constexpr field_t VREF_CA_OFFSET_MULT_BYTE60{VREF_OFFSET_MULT_BYTE60_BYTE, VREF_CA_OFFSET_MULT_BYTE60_START, VREF_CA_OFFSET_MULT_BYTE60_LEN };
        static constexpr field_t VREF_CS_OFFSET_MULT_BYTE60{VREF_OFFSET_MULT_BYTE60_BYTE, VREF_CS_OFFSET_MULT_BYTE60_START, VREF_CS_OFFSET_MULT_BYTE60_LEN};
        static constexpr field_t VREF_CA_OFFSET_BYTE60_ADD_SUB{VREF_OFFSET_MULT_BYTE60_BYTE, VREF_CA_OFFSET_BYTE60_ADD_SUB_START, VREF_CA_OFFSET_BYTE60_ADD_SUB_LEN};
        static constexpr field_t VREF_CS_OFFSET_BYTE60_ADD_SUB{VREF_OFFSET_MULT_BYTE60_BYTE, VREF_CS_OFFSET_BYTE60_ADD_SUB_START, VREF_CS_OFFSET_BYTE60_ADD_SUB_LEN};
        // BYTE70-BYTE79: B2 RANK1
        static constexpr field_t VREF_CA_OFFSET_MULT_BYTE70{VREF_OFFSET_MULT_BYTE70_BYTE, VREF_CA_OFFSET_MULT_BYTE70_START, VREF_CA_OFFSET_MULT_BYTE70_LEN };
        static constexpr field_t VREF_CS_OFFSET_MULT_BYTE70{VREF_OFFSET_MULT_BYTE70_BYTE, VREF_CS_OFFSET_MULT_BYTE70_START, VREF_CS_OFFSET_MULT_BYTE70_LEN};
        static constexpr field_t VREF_CA_OFFSET_BYTE70_ADD_SUB{VREF_OFFSET_MULT_BYTE70_BYTE, VREF_CA_OFFSET_BYTE70_ADD_SUB_START, VREF_CA_OFFSET_BYTE70_ADD_SUB_LEN};
        static constexpr field_t VREF_CS_OFFSET_BYTE70_ADD_SUB{VREF_OFFSET_MULT_BYTE70_BYTE, VREF_CS_OFFSET_BYTE70_ADD_SUB_START, VREF_CS_OFFSET_BYTE70_ADD_SUB_LEN};

        // Byte 404-414: Command Address Delay for Port A0
        // Byte 415: Reserved
        static constexpr field_t CS_DELAYS_A0_0_A0_2_FINE{CS_DELAYS_A0_0_A0_2_BYTE, CS_DELAYS_A0_0_A0_2_FINE_START, CS_DELAYS_A0_0_A0_2_FINE_LEN};
        static constexpr field_t CS_DELAYS_A0_0_A0_2_COARSE{CS_DELAYS_A0_0_A0_2_BYTE, CS_DELAYS_A0_0_A0_2_COARSE_START, CS_DELAYS_A0_0_A0_2_COARSE_LEN};

        static constexpr field_t CS_DELAYS_A0_1_A0_3_FINE{CS_DELAYS_A0_1_A0_3_BYTE, CS_DELAYS_A0_1_A0_3_FINE_START, CS_DELAYS_A0_1_A0_3_FINE_LEN};
        static constexpr field_t CS_DELAYS_A0_1_A0_3_COARSE{CS_DELAYS_A0_1_A0_3_BYTE, CS_DELAYS_A0_1_A0_3_COARSE_START, CS_DELAYS_A0_1_A0_3_COARSE_LEN};

        static constexpr field_t CK_DELAYS_A0_0_A0_2_FINE{CK_DELAYS_A0_0_A0_2_BYTE, CK_DELAYS_A0_0_A0_2_FINE_START, CK_DELAYS_A0_0_A0_2_FINE_LEN};
        static constexpr field_t CK_DELAYS_A0_0_A0_2_COARSE{CK_DELAYS_A0_0_A0_2_BYTE, CK_DELAYS_A0_0_A0_2_COARSE_START, CK_DELAYS_A0_0_A0_2_COARSE_LEN};

        static constexpr field_t CK_DELAYS_A0_1_A0_3_FINE{CK_DELAYS_A0_1_A0_3_BYTE, CK_DELAYS_A0_1_A0_3_FINE_START, CK_DELAYS_A0_1_A0_3_FINE_LEN};
        static constexpr field_t CK_DELAYS_A0_1_A0_3_COARSE{CK_DELAYS_A0_1_A0_3_BYTE, CK_DELAYS_A0_1_A0_3_COARSE_START, CK_DELAYS_A0_1_A0_3_COARSE_LEN};

        static constexpr field_t CA_DELAYS_A0_0_A0_1_FINE{CA_DELAYS_A0_0_A0_1_BYTE, CA_DELAYS_A0_0_A0_1_FINE_START, CA_DELAYS_A0_0_A0_1_FINE_LEN};
        static constexpr field_t CA_DELAYS_A0_0_A0_1_COARSE{CA_DELAYS_A0_0_A0_1_BYTE, CA_DELAYS_A0_0_A0_1_COARSE_START, CA_DELAYS_A0_0_A0_1_COARSE_LEN};

        static constexpr field_t CA_DELAYS_A0_2_A0_3_FINE{CA_DELAYS_A0_2_A0_3_BYTE, CA_DELAYS_A0_2_A0_3_FINE_START, CA_DELAYS_A0_2_A0_3_FINE_LEN};
        static constexpr field_t CA_DELAYS_A0_2_A0_3_COARSE{CA_DELAYS_A0_2_A0_3_BYTE, CA_DELAYS_A0_2_A0_3_COARSE_START, CA_DELAYS_A0_2_A0_3_COARSE_LEN};

        static constexpr field_t CA_DELAYS_A0_4_A0_5_FINE{CA_DELAYS_A0_4_A0_5_BYTE, CA_DELAYS_A0_4_A0_5_FINE_START, CA_DELAYS_A0_4_A0_5_FINE_LEN};
        static constexpr field_t CA_DELAYS_A0_4_A0_5_COARSE{CA_DELAYS_A0_4_A0_5_BYTE, CA_DELAYS_A0_4_A0_5_COARSE_START, CA_DELAYS_A0_4_A0_5_COARSE_LEN};

        static constexpr field_t CA_DELAYS_A0_6_A0_7_FINE{CA_DELAYS_A0_6_A0_7_BYTE, CA_DELAYS_A0_6_A0_7_FINE_START, CA_DELAYS_A0_6_A0_7_FINE_LEN};
        static constexpr field_t CA_DELAYS_A0_6_A0_7_COARSE{CA_DELAYS_A0_6_A0_7_BYTE, CA_DELAYS_A0_6_A0_7_COARSE_START, CA_DELAYS_A0_6_A0_7_COARSE_LEN};

        static constexpr field_t CA_DELAYS_A0_8_A0_9_FINE{CA_DELAYS_A0_8_A0_9_BYTE, CA_DELAYS_A0_8_A0_9_FINE_START, CA_DELAYS_A0_8_A0_9_FINE_LEN};
        static constexpr field_t CA_DELAYS_A0_8_A0_9_COARSE{CA_DELAYS_A0_8_A0_9_BYTE, CA_DELAYS_A0_8_A0_9_COARSE_START, CA_DELAYS_A0_8_A0_9_COARSE_LEN};

        static constexpr field_t CA_DELAYS_A0_10_A0_11_FINE{CA_DELAYS_A0_10_A0_11_BYTE, CA_DELAYS_A0_10_A0_11_FINE_START, CA_DELAYS_A0_10_A0_11_FINE_LEN};
        static constexpr field_t CA_DELAYS_A0_10_A0_11_COARSE{CA_DELAYS_A0_10_A0_11_BYTE, CA_DELAYS_A0_10_A0_11_COARSE_START, CA_DELAYS_A0_10_A0_11_COARSE_LEN};

        static constexpr field_t CA_DELAYS_A0_12_A0_13_FINE{CA_DELAYS_A0_12_A0_13_BYTE, CA_DELAYS_A0_12_A0_13_FINE_START, CA_DELAYS_A0_12_A0_13_FINE_LEN};
        static constexpr field_t CA_DELAYS_A0_12_A0_13_COARSE{CA_DELAYS_A0_12_A0_13_BYTE, CA_DELAYS_A0_12_A0_13_COARSE_START, CA_DELAYS_A0_12_A0_13_COARSE_LEN};


        // Byte 416-426: Command Address Delay for Port B0
        // Byte 427: Reserved
        static constexpr field_t CS_DELAYS_B0_0_B0_2_FINE{CS_DELAYS_B0_0_B0_2_BYTE, CS_DELAYS_B0_0_B0_2_FINE_START, CS_DELAYS_B0_0_B0_2_FINE_LEN};
        static constexpr field_t CS_DELAYS_B0_0_B0_2_COARSE{CS_DELAYS_B0_0_B0_2_BYTE, CS_DELAYS_B0_0_B0_2_COARSE_START, CS_DELAYS_B0_0_B0_2_COARSE_LEN};

        static constexpr field_t CS_DELAYS_B0_1_B0_3_FINE{CS_DELAYS_B0_1_B0_3_BYTE, CS_DELAYS_B0_1_B0_3_FINE_START, CS_DELAYS_B0_1_B0_3_FINE_LEN};
        static constexpr field_t CS_DELAYS_B0_1_B0_3_COARSE{CS_DELAYS_B0_1_B0_3_BYTE, CS_DELAYS_B0_1_B0_3_COARSE_START, CS_DELAYS_B0_1_B0_3_COARSE_LEN};

        static constexpr field_t CK_DELAYS_B0_0_B0_2_FINE{CK_DELAYS_B0_0_B0_2_BYTE, CK_DELAYS_B0_0_B0_2_FINE_START, CK_DELAYS_B0_0_B0_2_FINE_LEN};
        static constexpr field_t CK_DELAYS_B0_0_B0_2_COARSE{CK_DELAYS_B0_0_B0_2_BYTE, CK_DELAYS_B0_0_B0_2_COARSE_START, CK_DELAYS_B0_0_B0_2_COARSE_LEN};

        static constexpr field_t CK_DELAYS_B0_1_B0_3_FINE{CK_DELAYS_B0_1_B0_3_BYTE, CK_DELAYS_B0_1_B0_3_FINE_START, CK_DELAYS_B0_1_B0_3_FINE_LEN};
        static constexpr field_t CK_DELAYS_B0_1_B0_3_COARSE{CK_DELAYS_B0_1_B0_3_BYTE, CK_DELAYS_B0_1_B0_3_COARSE_START, CK_DELAYS_B0_1_B0_3_COARSE_LEN};

        static constexpr field_t CA_DELAYS_B0_0_B0_1_FINE{CA_DELAYS_B0_0_B0_1_BYTE, CA_DELAYS_B0_0_B0_1_FINE_START, CA_DELAYS_B0_0_B0_1_FINE_LEN};
        static constexpr field_t CA_DELAYS_B0_0_B0_1_COARSE{CA_DELAYS_B0_0_B0_1_BYTE, CA_DELAYS_B0_0_B0_1_COARSE_START, CA_DELAYS_B0_0_B0_1_COARSE_LEN};

        static constexpr field_t CA_DELAYS_B0_2_B0_3_FINE{CA_DELAYS_B0_2_B0_3_BYTE, CA_DELAYS_B0_2_B0_3_FINE_START, CA_DELAYS_B0_2_B0_3_FINE_LEN};
        static constexpr field_t CA_DELAYS_B0_2_B0_3_COARSE{CA_DELAYS_B0_2_B0_3_BYTE, CA_DELAYS_B0_2_B0_3_COARSE_START, CA_DELAYS_B0_2_B0_3_COARSE_LEN};

        static constexpr field_t CA_DELAYS_B0_4_B0_5_FINE{CA_DELAYS_B0_4_B0_5_BYTE, CA_DELAYS_B0_4_B0_5_FINE_START, CA_DELAYS_B0_4_B0_5_FINE_LEN};
        static constexpr field_t CA_DELAYS_B0_4_B0_5_COARSE{CA_DELAYS_B0_4_B0_5_BYTE, CA_DELAYS_B0_4_B0_5_COARSE_START, CA_DELAYS_B0_4_B0_5_COARSE_LEN};

        static constexpr field_t CA_DELAYS_B0_6_B0_7_FINE{CA_DELAYS_B0_6_B0_7_BYTE, CA_DELAYS_B0_6_B0_7_FINE_START, CA_DELAYS_B0_6_B0_7_FINE_LEN};
        static constexpr field_t CA_DELAYS_B0_6_B0_7_COARSE{CA_DELAYS_B0_6_B0_7_BYTE, CA_DELAYS_B0_6_B0_7_COARSE_START, CA_DELAYS_B0_6_B0_7_COARSE_LEN};

        static constexpr field_t CA_DELAYS_B0_8_B0_9_FINE{CA_DELAYS_B0_8_B0_9_BYTE, CA_DELAYS_B0_8_B0_9_FINE_START, CA_DELAYS_B0_8_B0_9_FINE_LEN};
        static constexpr field_t CA_DELAYS_B0_8_B0_9_COARSE{CA_DELAYS_B0_8_B0_9_BYTE, CA_DELAYS_B0_8_B0_9_COARSE_START, CA_DELAYS_B0_8_B0_9_COARSE_LEN};

        static constexpr field_t CA_DELAYS_B0_10_B0_11_FINE{CA_DELAYS_B0_10_B0_11_BYTE, CA_DELAYS_B0_10_B0_11_FINE_START, CA_DELAYS_B0_10_B0_11_FINE_LEN};
        static constexpr field_t CA_DELAYS_B0_10_B0_11_COARSE{CA_DELAYS_B0_10_B0_11_BYTE, CA_DELAYS_B0_10_B0_11_COARSE_START, CA_DELAYS_B0_10_B0_11_COARSE_LEN};

        static constexpr field_t CA_DELAYS_B0_12_B0_13_FINE{CA_DELAYS_B0_12_B0_13_BYTE, CA_DELAYS_B0_12_B0_13_FINE_START, CA_DELAYS_B0_12_B0_13_FINE_LEN};
        static constexpr field_t CA_DELAYS_B0_12_B0_13_COARSE{CA_DELAYS_B0_12_B0_13_BYTE, CA_DELAYS_B0_12_B0_13_COARSE_START, CA_DELAYS_B0_12_B0_13_COARSE_LEN};


        // Byte 428-438: Command Address Delay for Port A1
        // Byte 439: Reserved
        static constexpr field_t CS_DELAYS_A1_0_A1_2_FINE{CS_DELAYS_A1_0_A1_2_BYTE, CS_DELAYS_A1_0_A1_2_FINE_START, CS_DELAYS_A1_0_A1_2_FINE_LEN};
        static constexpr field_t CS_DELAYS_A1_0_A1_2_COARSE{CS_DELAYS_A1_0_A1_2_BYTE, CS_DELAYS_A1_0_A1_2_COARSE_START, CS_DELAYS_A1_0_A1_2_COARSE_LEN};

        static constexpr field_t CS_DELAYS_A1_1_A1_3_FINE{CS_DELAYS_A1_1_A1_3_BYTE, CS_DELAYS_A1_1_A1_3_FINE_START, CS_DELAYS_A1_1_A1_3_FINE_LEN};
        static constexpr field_t CS_DELAYS_A1_1_A1_3_COARSE{CS_DELAYS_A1_1_A1_3_BYTE, CS_DELAYS_A1_1_A1_3_COARSE_START, CS_DELAYS_A1_1_A1_3_COARSE_LEN};

        static constexpr field_t CK_DELAYS_A1_0_A1_2_FINE{CK_DELAYS_A1_0_A1_2_BYTE, CK_DELAYS_A1_0_A1_2_FINE_START, CK_DELAYS_A1_0_A1_2_FINE_LEN};
        static constexpr field_t CK_DELAYS_A1_0_A1_2_COARSE{CK_DELAYS_A1_0_A1_2_BYTE, CK_DELAYS_A1_0_A1_2_COARSE_START, CK_DELAYS_A1_0_A1_2_COARSE_LEN};

        static constexpr field_t CK_DELAYS_A1_1_A1_3_FINE{CK_DELAYS_A1_1_A1_3_BYTE, CK_DELAYS_A1_1_A1_3_FINE_START, CK_DELAYS_A1_1_A1_3_FINE_LEN};
        static constexpr field_t CK_DELAYS_A1_1_A1_3_COARSE{CK_DELAYS_A1_1_A1_3_BYTE, CK_DELAYS_A1_1_A1_3_COARSE_START, CK_DELAYS_A1_1_A1_3_COARSE_LEN};

        static constexpr field_t CA_DELAYS_A1_0_A1_1_FINE{CA_DELAYS_A1_0_A1_1_BYTE, CA_DELAYS_A1_0_A1_1_FINE_START, CA_DELAYS_A1_0_A1_1_FINE_LEN};
        static constexpr field_t CA_DELAYS_A1_0_A1_1_COARSE{CA_DELAYS_A1_0_A1_1_BYTE, CA_DELAYS_A1_0_A1_1_COARSE_START, CA_DELAYS_A1_0_A1_1_COARSE_LEN};

        static constexpr field_t CA_DELAYS_A1_2_A1_3_FINE{CA_DELAYS_A1_2_A1_3_BYTE, CA_DELAYS_A1_2_A1_3_FINE_START, CA_DELAYS_A1_2_A1_3_FINE_LEN};
        static constexpr field_t CA_DELAYS_A1_2_A1_3_COARSE{CA_DELAYS_A1_2_A1_3_BYTE, CA_DELAYS_A1_2_A1_3_COARSE_START, CA_DELAYS_A1_2_A1_3_COARSE_LEN};

        static constexpr field_t CA_DELAYS_A1_4_A1_5_FINE{CA_DELAYS_A1_4_A1_5_BYTE, CA_DELAYS_A1_4_A1_5_FINE_START, CA_DELAYS_A1_4_A1_5_FINE_LEN};
        static constexpr field_t CA_DELAYS_A1_4_A1_5_COARSE{CA_DELAYS_A1_4_A1_5_BYTE, CA_DELAYS_A1_4_A1_5_COARSE_START, CA_DELAYS_A1_4_A1_5_COARSE_LEN};

        static constexpr field_t CA_DELAYS_A1_6_A1_7_FINE{CA_DELAYS_A1_6_A1_7_BYTE, CA_DELAYS_A1_6_A1_7_FINE_START, CA_DELAYS_A1_6_A1_7_FINE_LEN};
        static constexpr field_t CA_DELAYS_A1_6_A1_7_COARSE{CA_DELAYS_A1_6_A1_7_BYTE, CA_DELAYS_A1_6_A1_7_COARSE_START, CA_DELAYS_A1_6_A1_7_COARSE_LEN};

        static constexpr field_t CA_DELAYS_A1_8_A1_9_FINE{CA_DELAYS_A1_8_A1_9_BYTE, CA_DELAYS_A1_8_A1_9_FINE_START, CA_DELAYS_A1_8_A1_9_FINE_LEN};
        static constexpr field_t CA_DELAYS_A1_8_A1_9_COARSE{CA_DELAYS_A1_8_A1_9_BYTE, CA_DELAYS_A1_8_A1_9_COARSE_START, CA_DELAYS_A1_8_A1_9_COARSE_LEN};

        static constexpr field_t CA_DELAYS_A1_10_A1_11_FINE{CA_DELAYS_A1_10_A1_11_BYTE, CA_DELAYS_A1_10_A1_11_FINE_START, CA_DELAYS_A1_10_A1_11_FINE_LEN};
        static constexpr field_t CA_DELAYS_A1_10_A1_11_COARSE{CA_DELAYS_A1_10_A1_11_BYTE, CA_DELAYS_A1_10_A1_11_COARSE_START, CA_DELAYS_A1_10_A1_11_COARSE_LEN};

        static constexpr field_t CA_DELAYS_A1_12_A1_13_FINE{CA_DELAYS_A1_12_A1_13_BYTE, CA_DELAYS_A1_12_A1_13_FINE_START, CA_DELAYS_A1_12_A1_13_FINE_LEN};
        static constexpr field_t CA_DELAYS_A1_12_A1_13_COARSE{CA_DELAYS_A1_12_A1_13_BYTE, CA_DELAYS_A1_12_A1_13_COARSE_START, CA_DELAYS_A1_12_A1_13_COARSE_LEN};

        // Byte 440-450: Command Address Delay for Port B1
        // Byte 451: Reserved
        static constexpr field_t CS_DELAYS_B1_0_B1_2_FINE{CS_DELAYS_B1_0_B1_2_BYTE, CS_DELAYS_B1_0_B1_2_FINE_START, CS_DELAYS_B1_0_B1_2_FINE_LEN};
        static constexpr field_t CS_DELAYS_B1_0_B1_2_COARSE{CS_DELAYS_B1_0_B1_2_BYTE, CS_DELAYS_B1_0_B1_2_COARSE_START, CS_DELAYS_B1_0_B1_2_COARSE_LEN};

        static constexpr field_t CS_DELAYS_B1_1_B1_3_FINE{CS_DELAYS_B1_1_B1_3_BYTE, CS_DELAYS_B1_1_B1_3_FINE_START, CS_DELAYS_B1_1_B1_3_FINE_LEN};
        static constexpr field_t CS_DELAYS_B1_1_B1_3_COARSE{CS_DELAYS_B1_1_B1_3_BYTE, CS_DELAYS_B1_1_B1_3_COARSE_START, CS_DELAYS_B1_1_B1_3_COARSE_LEN};

        static constexpr field_t CK_DELAYS_B1_0_B1_2_FINE{CK_DELAYS_B1_0_B1_2_BYTE, CK_DELAYS_B1_0_B1_2_FINE_START, CK_DELAYS_B1_0_B1_2_FINE_LEN};
        static constexpr field_t CK_DELAYS_B1_0_B1_2_COARSE{CK_DELAYS_B1_0_B1_2_BYTE, CK_DELAYS_B1_0_B1_2_COARSE_START, CK_DELAYS_B1_0_B1_2_COARSE_LEN};

        static constexpr field_t CK_DELAYS_B1_1_B1_3_FINE{CK_DELAYS_B1_1_B1_3_BYTE, CK_DELAYS_B1_1_B1_3_FINE_START, CK_DELAYS_B1_1_B1_3_FINE_LEN};
        static constexpr field_t CK_DELAYS_B1_1_B1_3_COARSE{CK_DELAYS_B1_1_B1_3_BYTE, CK_DELAYS_B1_1_B1_3_COARSE_START, CK_DELAYS_B1_1_B1_3_COARSE_LEN};

        static constexpr field_t CA_DELAYS_B1_0_B1_1_FINE{CA_DELAYS_B1_0_B1_1_BYTE, CA_DELAYS_B1_0_B1_1_FINE_START, CA_DELAYS_B1_0_B1_1_FINE_LEN};
        static constexpr field_t CA_DELAYS_B1_0_B1_1_COARSE{CA_DELAYS_B1_0_B1_1_BYTE, CA_DELAYS_B1_0_B1_1_COARSE_START, CA_DELAYS_B1_0_B1_1_COARSE_LEN};

        static constexpr field_t CA_DELAYS_B1_2_B1_3_FINE{CA_DELAYS_B1_2_B1_3_BYTE, CA_DELAYS_B1_2_B1_3_FINE_START, CA_DELAYS_B1_2_B1_3_FINE_LEN};
        static constexpr field_t CA_DELAYS_B1_2_B1_3_COARSE{CA_DELAYS_B1_2_B1_3_BYTE, CA_DELAYS_B1_2_B1_3_COARSE_START, CA_DELAYS_B1_2_B1_3_COARSE_LEN};

        static constexpr field_t CA_DELAYS_B1_4_B1_5_FINE{CA_DELAYS_B1_4_B1_5_BYTE, CA_DELAYS_B1_4_B1_5_FINE_START, CA_DELAYS_B1_4_B1_5_FINE_LEN};
        static constexpr field_t CA_DELAYS_B1_4_B1_5_COARSE{CA_DELAYS_B1_4_B1_5_BYTE, CA_DELAYS_B1_4_B1_5_COARSE_START, CA_DELAYS_B1_4_B1_5_COARSE_LEN};

        static constexpr field_t CA_DELAYS_B1_6_B1_7_FINE{CA_DELAYS_B1_6_B1_7_BYTE, CA_DELAYS_B1_6_B1_7_FINE_START, CA_DELAYS_B1_6_B1_7_FINE_LEN};
        static constexpr field_t CA_DELAYS_B1_6_B1_7_COARSE{CA_DELAYS_B1_6_B1_7_BYTE, CA_DELAYS_B1_6_B1_7_COARSE_START, CA_DELAYS_B1_6_B1_7_COARSE_LEN};

        static constexpr field_t CA_DELAYS_B1_8_B1_9_FINE{CA_DELAYS_B1_8_B1_9_BYTE, CA_DELAYS_B1_8_B1_9_FINE_START, CA_DELAYS_B1_8_B1_9_FINE_LEN};
        static constexpr field_t CA_DELAYS_B1_8_B1_9_COARSE{CA_DELAYS_B1_8_B1_9_BYTE, CA_DELAYS_B1_8_B1_9_COARSE_START, CA_DELAYS_B1_8_B1_9_COARSE_LEN};

        static constexpr field_t CA_DELAYS_B1_10_B1_11_FINE{CA_DELAYS_B1_10_B1_11_BYTE, CA_DELAYS_B1_10_B1_11_FINE_START, CA_DELAYS_B1_10_B1_11_FINE_LEN};
        static constexpr field_t CA_DELAYS_B1_10_B1_11_COARSE{CA_DELAYS_B1_10_B1_11_BYTE, CA_DELAYS_B1_10_B1_11_COARSE_START, CA_DELAYS_B1_10_B1_11_COARSE_LEN};

        static constexpr field_t CA_DELAYS_B1_12_B1_13_FINE{CA_DELAYS_B1_12_B1_13_BYTE, CA_DELAYS_B1_12_B1_13_FINE_START, CA_DELAYS_B1_12_B1_13_FINE_LEN};
        static constexpr field_t CA_DELAYS_B1_12_B1_13_COARSE{CA_DELAYS_B1_12_B1_13_BYTE, CA_DELAYS_B1_12_B1_13_COARSE_START, CA_DELAYS_B1_12_B1_13_COARSE_LEN};

        static constexpr field_t PMIC0_SWA_VOLT_OFF{PMIC0_SWA_VOLT_OFF_BYTE, PMIC0_SWA_VOLT_OFF_START, PMIC0_SWA_VOLT_OFF_LEN};
        static constexpr field_t PMIC0_SWA_OFF_DIRECTION{PMIC0_SWA_VOLT_OFF_BYTE, PMIC0_SWA_OFF_DIRECTION_START, PMIC0_SWA_OFF_DIRECTION_LEN};

        static constexpr field_t PMIC0_SWB_VOLT_OFF{PMIC0_SWB_VOLT_OFF_BYTE, PMIC0_SWB_VOLT_OFF_START, PMIC0_SWB_VOLT_OFF_LEN};
        static constexpr field_t PMIC0_SWB_OFF_DIRECTION{PMIC0_SWB_VOLT_OFF_BYTE, PMIC0_SWB_OFF_DIRECTION_START, PMIC0_SWB_OFF_DIRECTION_LEN};

        static constexpr field_t PMIC0_SWC_VOLT_OFF{PMIC0_SWC_VOLT_OFF_BYTE, PMIC0_SWC_VOLT_OFF_START, PMIC0_SWC_VOLT_OFF_LEN};
        static constexpr field_t PMIC0_SWC_OFF_DIRECTION{PMIC0_SWC_VOLT_OFF_BYTE, PMIC0_SWC_OFF_DIRECTION_START, PMIC0_SWC_OFF_DIRECTION_LEN};

        static constexpr field_t PMIC0_SWD_VOLT_OFF{PMIC0_SWD_VOLT_OFF_BYTE, PMIC0_SWD_VOLT_OFF_START, PMIC0_SWD_VOLT_OFF_LEN};
        static constexpr field_t PMIC0_SWD_OFF_DIRECTION{PMIC0_SWD_VOLT_OFF_BYTE, PMIC0_SWD_OFF_DIRECTION_START, PMIC0_SWD_OFF_DIRECTION_LEN};

        static constexpr field_t PMIC1_SWA_VOLT_OFF{PMIC1_SWA_VOLT_OFF_BYTE, PMIC1_SWA_VOLT_OFF_START, PMIC1_SWA_VOLT_OFF_LEN};
        static constexpr field_t PMIC1_SWA_OFF_DIRECTION{PMIC1_SWA_VOLT_OFF_BYTE, PMIC1_SWA_OFF_DIRECTION_START, PMIC1_SWA_OFF_DIRECTION_LEN};

        static constexpr field_t PMIC1_SWB_VOLT_OFF{PMIC1_SWB_VOLT_OFF_BYTE, PMIC1_SWB_VOLT_OFF_START, PMIC1_SWB_VOLT_OFF_LEN};
        static constexpr field_t PMIC1_SWB_OFF_DIRECTION{PMIC1_SWB_VOLT_OFF_BYTE, PMIC1_SWB_OFF_DIRECTION_START, PMIC1_SWB_OFF_DIRECTION_LEN};

        static constexpr field_t PMIC1_SWC_VOLT_OFF{PMIC1_SWC_VOLT_OFF_BYTE, PMIC1_SWC_VOLT_OFF_START, PMIC1_SWC_VOLT_OFF_LEN};
        static constexpr field_t PMIC1_SWC_OFF_DIRECTION{PMIC1_SWC_VOLT_OFF_BYTE, PMIC1_SWC_OFF_DIRECTION_START, PMIC1_SWC_OFF_DIRECTION_LEN};

        static constexpr field_t PMIC1_SWD_VOLT_OFF{PMIC1_SWD_VOLT_OFF_BYTE, PMIC1_SWD_VOLT_OFF_START, PMIC1_SWD_VOLT_OFF_LEN};
        static constexpr field_t PMIC1_SWD_OFF_DIRECTION{PMIC1_SWD_VOLT_OFF_BYTE, PMIC1_SWD_OFF_DIRECTION_START, PMIC1_SWD_OFF_DIRECTION_LEN};

        static constexpr field_t PMIC2_SWA_VOLT_OFF{PMIC2_SWA_VOLT_OFF_BYTE, PMIC2_SWA_VOLT_OFF_START, PMIC2_SWA_VOLT_OFF_LEN};
        static constexpr field_t PMIC2_SWA_OFF_DIRECTION{PMIC2_SWA_VOLT_OFF_BYTE, PMIC2_SWA_OFF_DIRECTION_START, PMIC2_SWA_OFF_DIRECTION_LEN};

        static constexpr field_t PMIC2_SWB_VOLT_OFF{PMIC2_SWB_VOLT_OFF_BYTE, PMIC2_SWB_VOLT_OFF_START, PMIC2_SWB_VOLT_OFF_LEN};
        static constexpr field_t PMIC2_SWB_OFF_DIRECTION{PMIC2_SWB_VOLT_OFF_BYTE, PMIC2_SWB_OFF_DIRECTION_START, PMIC2_SWB_OFF_DIRECTION_LEN};

        static constexpr field_t PMIC2_SWC_VOLT_OFF{PMIC2_SWC_VOLT_OFF_BYTE, PMIC2_SWC_VOLT_OFF_START, PMIC2_SWC_VOLT_OFF_LEN};
        static constexpr field_t PMIC2_SWC_OFF_DIRECTION{PMIC2_SWC_VOLT_OFF_BYTE, PMIC2_SWC_OFF_DIRECTION_START, PMIC2_SWC_OFF_DIRECTION_LEN};

        static constexpr field_t PMIC2_SWD_VOLT_OFF{PMIC2_SWD_VOLT_OFF_BYTE, PMIC2_SWD_VOLT_OFF_START, PMIC2_SWD_VOLT_OFF_LEN};
        static constexpr field_t PMIC2_SWD_OFF_DIRECTION{PMIC2_SWD_VOLT_OFF_BYTE, PMIC2_SWD_OFF_DIRECTION_START, PMIC2_SWD_OFF_DIRECTION_LEN};

        static constexpr field_t PMIC3_SWA_VOLT_OFF{PMIC3_SWA_VOLT_OFF_BYTE, PMIC3_SWA_VOLT_OFF_START, PMIC3_SWA_VOLT_OFF_LEN};
        static constexpr field_t PMIC3_SWA_OFF_DIRECTION{PMIC3_SWA_VOLT_OFF_BYTE, PMIC3_SWA_OFF_DIRECTION_START, PMIC3_SWA_OFF_DIRECTION_LEN};

        static constexpr field_t PMIC3_SWB_VOLT_OFF{PMIC3_SWB_VOLT_OFF_BYTE, PMIC3_SWB_VOLT_OFF_START, PMIC3_SWB_VOLT_OFF_LEN};
        static constexpr field_t PMIC3_SWB_OFF_DIRECTION{PMIC3_SWB_VOLT_OFF_BYTE, PMIC3_SWB_OFF_DIRECTION_START, PMIC3_SWB_OFF_DIRECTION_LEN};

        static constexpr field_t PMIC3_SWC_VOLT_OFF{PMIC3_SWC_VOLT_OFF_BYTE, PMIC3_SWC_VOLT_OFF_START, PMIC3_SWC_VOLT_OFF_LEN};
        static constexpr field_t PMIC3_SWC_OFF_DIRECTION{PMIC3_SWC_VOLT_OFF_BYTE, PMIC3_SWC_OFF_DIRECTION_START, PMIC3_SWC_OFF_DIRECTION_LEN};

        static constexpr field_t PMIC3_SWD_VOLT_OFF{PMIC3_SWD_VOLT_OFF_BYTE, PMIC3_SWD_VOLT_OFF_START, PMIC3_SWD_VOLT_OFF_LEN};
        static constexpr field_t PMIC3_SWD_OFF_DIRECTION{PMIC3_SWD_VOLT_OFF_BYTE, PMIC3_SWD_OFF_DIRECTION_START, PMIC3_SWD_OFF_DIRECTION_LEN};

        static constexpr field_t PMIC0_SWA_CURRENT_WARNING{PMIC0_SWA_CURRENT_WARNING_BYTE, PMIC0_SWA_CURRENT_WARNING_START, PMIC0_SWA_CURRENT_WARNING_LEN};
        static constexpr field_t PMIC0_SWB_CURRENT_WARNING{PMIC0_SWB_CURRENT_WARNING_BYTE, PMIC0_SWB_CURRENT_WARNING_START, PMIC0_SWB_CURRENT_WARNING_LEN};
        static constexpr field_t PMIC0_SWC_CURRENT_WARNING{PMIC0_SWC_CURRENT_WARNING_BYTE, PMIC0_SWC_CURRENT_WARNING_START, PMIC0_SWC_CURRENT_WARNING_LEN};
        static constexpr field_t PMIC0_SWD_CURRENT_WARNING{PMIC0_SWD_CURRENT_WARNING_BYTE, PMIC0_SWD_CURRENT_WARNING_START, PMIC0_SWD_CURRENT_WARNING_LEN};

        static constexpr field_t PMIC1_SWA_CURRENT_WARNING{PMIC1_SWA_CURRENT_WARNING_BYTE, PMIC1_SWA_CURRENT_WARNING_START, PMIC1_SWA_CURRENT_WARNING_LEN};
        static constexpr field_t PMIC1_SWB_CURRENT_WARNING{PMIC1_SWB_CURRENT_WARNING_BYTE, PMIC1_SWB_CURRENT_WARNING_START, PMIC1_SWB_CURRENT_WARNING_LEN};
        static constexpr field_t PMIC1_SWC_CURRENT_WARNING{PMIC1_SWC_CURRENT_WARNING_BYTE, PMIC1_SWC_CURRENT_WARNING_START, PMIC1_SWC_CURRENT_WARNING_LEN};
        static constexpr field_t PMIC1_SWD_CURRENT_WARNING{PMIC1_SWD_CURRENT_WARNING_BYTE, PMIC1_SWD_CURRENT_WARNING_START, PMIC1_SWD_CURRENT_WARNING_LEN};

        static constexpr field_t PMIC2_SWA_CURRENT_WARNING{PMIC2_SWA_CURRENT_WARNING_BYTE, PMIC2_SWA_CURRENT_WARNING_START, PMIC2_SWA_CURRENT_WARNING_LEN};
        static constexpr field_t PMIC2_SWB_CURRENT_WARNING{PMIC2_SWB_CURRENT_WARNING_BYTE, PMIC2_SWB_CURRENT_WARNING_START, PMIC2_SWB_CURRENT_WARNING_LEN};
        static constexpr field_t PMIC2_SWC_CURRENT_WARNING{PMIC2_SWC_CURRENT_WARNING_BYTE, PMIC2_SWC_CURRENT_WARNING_START, PMIC2_SWC_CURRENT_WARNING_LEN};
        static constexpr field_t PMIC2_SWD_CURRENT_WARNING{PMIC2_SWD_CURRENT_WARNING_BYTE, PMIC2_SWD_CURRENT_WARNING_START, PMIC2_SWD_CURRENT_WARNING_LEN};

        static constexpr field_t PMIC3_SWA_CURRENT_WARNING{PMIC3_SWA_CURRENT_WARNING_BYTE, PMIC3_SWA_CURRENT_WARNING_START, PMIC3_SWA_CURRENT_WARNING_LEN};
        static constexpr field_t PMIC3_SWB_CURRENT_WARNING{PMIC3_SWB_CURRENT_WARNING_BYTE, PMIC3_SWB_CURRENT_WARNING_START, PMIC3_SWB_CURRENT_WARNING_LEN};
        static constexpr field_t PMIC3_SWC_CURRENT_WARNING{PMIC3_SWC_CURRENT_WARNING_BYTE, PMIC3_SWC_CURRENT_WARNING_START, PMIC3_SWC_CURRENT_WARNING_LEN};
        static constexpr field_t PMIC3_SWD_CURRENT_WARNING{PMIC3_SWD_CURRENT_WARNING_BYTE, PMIC3_SWD_CURRENT_WARNING_START, PMIC3_SWD_CURRENT_WARNING_LEN};

};

} // ns efd
} // ns mss
#endif
