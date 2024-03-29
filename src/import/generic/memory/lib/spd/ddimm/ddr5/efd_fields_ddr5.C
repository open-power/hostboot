/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/ddimm/ddr5/efd_fields_ddr5.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2023                        */
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
/// @file efd_fields_ddr5.C
/// @brief EFD data fields forward declarations
///

// *HWP HWP Owner: Geetha Pisapati <Geetha.Pisapati@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP
// EKB-Mirror-To: hostboot

#include <generic/memory/lib/spd/ddimm/ddr5/efd_fields_ddr5.H>

namespace mss
{
namespace efd
{

using FT = fields<mss::spd::device_type::DDR5, mss::efd::id::DDR5_CUSTOM_IBM>;

// These "definitions" are needed to generate linkage for the static constexprs declared in the .H because of ODR-used
#ifndef __PPE__
    constexpr field_t<mss::endian::LITTLE> FT::HOST_SPEED_SUPPORTED;
#endif
constexpr field_t<mss::endian::LITTLE> FT::MODE_2N_REQUIREMENTS_25600;
#ifndef __PPE__
    constexpr field_t<mss::endian::LITTLE> FT::MODE_2N_REQUIREMENTS_32000;
    constexpr field_t<mss::endian::LITTLE> FT::MODE_2N_REQUIREMENTS_38400;
    constexpr field_t<mss::endian::LITTLE> FT::MASTER_RANKS_SUPPORTED;
    constexpr field_t<mss::endian::LITTLE> FT::PHY_CHANNEL_SUPPORTED;
#endif
constexpr field_t<mss::endian::LITTLE> FT::PHY0_CHANNELS_VREF;
constexpr field_t<mss::endian::LITTLE> FT::PHY1_CHANNELS_VREF;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_DIC_PULLUP;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_DIC_PULLDOWN;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_WR_POSTAMBLE;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RD_POSTAMBLE;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_WR_PREAMBLE;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RD_PREAMBLE;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_VREF_BYTE0;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_VREF_BYTE1;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_VREF_BYTE2;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_VREF_BYTE3;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_VREF_BYTE4;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_VREF_BYTE5;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_VREF_BYTE6;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_VREF_BYTE7;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_DFE_TAP4;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_DFE_TAP3;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_DFE_TAP2;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_DFE_TAP1;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_DFE_EN;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_DFE_GAIN_BIAS_BYTE0;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_DFE_GAIN_BIAS_BYTE0_SIGN_BIT;
#ifndef __PPE__
    constexpr field_t<mss::endian::LITTLE> FT::DRAM_DFE_GAIN_BIAS_BYTE1;
    constexpr field_t<mss::endian::LITTLE> FT::DRAM_DFE_GAIN_BIAS_BYTE1_SIGN_BIT;
    constexpr field_t<mss::endian::LITTLE> FT::DRAM_DFE_GAIN_BIAS_BYTE2;
    constexpr field_t<mss::endian::LITTLE> FT::DRAM_DFE_GAIN_BIAS_BYTE2_SIGN_BIT;
    constexpr field_t<mss::endian::LITTLE> FT::DRAM_DFE_GAIN_BIAS_BYTE3;
    constexpr field_t<mss::endian::LITTLE> FT::DRAM_DFE_GAIN_BIAS_BYTE3_SIGN_BIT;
    constexpr field_t<mss::endian::LITTLE> FT::DRAM_DFE_GAIN_BIAS_BYTE4;
    constexpr field_t<mss::endian::LITTLE> FT::DRAM_DFE_GAIN_BIAS_BYTE4_SIGN_BIT;
    constexpr field_t<mss::endian::LITTLE> FT::DRAM_DFE_GAIN_BIAS_BYTE5;
    constexpr field_t<mss::endian::LITTLE> FT::DRAM_DFE_GAIN_BIAS_BYTE5_SIGN_BIT;
    constexpr field_t<mss::endian::LITTLE> FT::DRAM_DFE_GAIN_BIAS_BYTE6;
    constexpr field_t<mss::endian::LITTLE> FT::DRAM_DFE_GAIN_BIAS_BYTE6_SIGN_BIT;
    constexpr field_t<mss::endian::LITTLE> FT::DRAM_DFE_GAIN_BIAS_BYTE7;
    constexpr field_t<mss::endian::LITTLE> FT::DRAM_DFE_GAIN_BIAS_BYTE7_SIGN_BIT;
#endif
constexpr field_t<mss::endian::LITTLE> FT::PHY_ODT_IMPEDANCE;
constexpr field_t<mss::endian::LITTLE> FT::PHY_DRIVE_IMPEDANCE_CTRL0;
constexpr field_t<mss::endian::LITTLE> FT::PHY_DRIVE_IMPEDANCE_CTRL1;
constexpr field_t<mss::endian::LITTLE> FT::PHY_DRIVE_IMPEDANCE_CTRL2;
#ifndef __PPE__
    constexpr field_t<mss::endian::LITTLE> FT::PHY_SLEW_RATE_DQ_DQS;
#endif
constexpr field_t<mss::endian::LITTLE> FT::ATX_IMPEDANCE;
constexpr field_t<mss::endian::LITTLE> FT::ATX_SLEW_RISE_RATE_BYTE0;
constexpr field_t<mss::endian::LITTLE> FT::ATX_SLEW_RISE_RATE_BYTE1;
constexpr field_t<mss::endian::LITTLE> FT::ATX_SLEW_FALL_RATE_BYTE0;
constexpr field_t<mss::endian::LITTLE> FT::ATX_SLEW_FALL_RATE_BYTE1;
constexpr field_t<mss::endian::LITTLE> FT::CK_SLEW_RATE_RISE_BYTE0;
constexpr field_t<mss::endian::LITTLE> FT::CK_SLEW_RATE_RISE_BYTE1;
#ifndef __PPE__
    constexpr field_t<mss::endian::LITTLE> FT::DQ_SLEW_RATE_RISE_BYTE0;
    constexpr field_t<mss::endian::LITTLE> FT::DQ_SLEW_RATE_RISE_BYTE1;
#endif
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_PARK_BYTE0;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_WR_BYTE0;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_PARK_BYTE1;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_WR_BYTE1;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_PARK_BYTE2;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_WR_BYTE2;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_PARK_BYTE3;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_WR_BYTE3;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_PARK_BYTE4;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_WR_BYTE4;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_PARK_BYTE5;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_WR_BYTE5;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_PARK_BYTE6;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_WR_BYTE6;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_PARK_BYTE7;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_WR_BYTE7;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_NOM_BYTE0_RD;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_NOM_BYTE0_WR;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_NOM_BYTE1_RD;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_NOM_BYTE1_WR;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_NOM_BYTE2_RD;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_NOM_BYTE2_WR;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_NOM_BYTE3_RD;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_NOM_BYTE3_WR;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_NOM_BYTE4_RD;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_NOM_BYTE4_WR;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_NOM_BYTE5_RD;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_NOM_BYTE5_WR;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_NOM_BYTE6_RD;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_NOM_BYTE6_WR;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_NOM_BYTE7_RD;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_NOM_BYTE7_WR;
#ifndef __PPE__
    constexpr field_t<mss::endian::LITTLE> FT::PHY_EQUALIZATION_DFFE;
    constexpr field_t<mss::endian::LITTLE> FT::PHY_EQUALIZATION_RDFE;
#endif
constexpr field_t<mss::endian::LITTLE> FT::NT_ODT_RD_A0_B0_RANK0;
constexpr field_t<mss::endian::LITTLE> FT::NT_ODT_WR_A0_B0_RANK0;
constexpr field_t<mss::endian::LITTLE> FT::NT_ODT_RD_A1_B1_RANK0;
constexpr field_t<mss::endian::LITTLE> FT::NT_ODT_WR_A1_B1_RANK0;
constexpr field_t<mss::endian::LITTLE> FT::NT_ODT_RD_A0_B0_RANK1;
constexpr field_t<mss::endian::LITTLE> FT::NT_ODT_WR_A0_B0_RANK1;
constexpr field_t<mss::endian::LITTLE> FT::NT_ODT_RD_A1_B1_RANK1;
constexpr field_t<mss::endian::LITTLE> FT::NT_ODT_WR_A1_B1_RANK1;
#ifndef __PPE__
    constexpr field_t<mss::endian::LITTLE> FT::DFIMRL_DDRCLK;
#endif
constexpr field_t<mss::endian::LITTLE> FT::ODT_CA_GRPA_CK_BYTE0;
constexpr field_t<mss::endian::LITTLE> FT::ODT_CA_GRPA_CS_BYTE0;
constexpr field_t<mss::endian::LITTLE> FT::ODT_CA_GRPA_CK_BYTE1;
constexpr field_t<mss::endian::LITTLE> FT::ODT_CA_GRPA_CS_BYTE1;
#ifndef __PPE__
    constexpr field_t<mss::endian::LITTLE> FT::ODT_CA_GRPA_CK_BYTE2;
    constexpr field_t<mss::endian::LITTLE> FT::ODT_CA_GRPA_CS_BYTE2;
    constexpr field_t<mss::endian::LITTLE> FT::ODT_CA_GRPA_CK_BYTE3;
    constexpr field_t<mss::endian::LITTLE> FT::ODT_CA_GRPA_CS_BYTE3;
#endif
constexpr field_t<mss::endian::LITTLE> FT::ODT_CA_GRPA_CK_BYTE4;
constexpr field_t<mss::endian::LITTLE> FT::ODT_CA_GRPA_CS_BYTE4;
constexpr field_t<mss::endian::LITTLE> FT::ODT_CA_GRPA_CK_BYTE5;
constexpr field_t<mss::endian::LITTLE> FT::ODT_CA_GRPA_CS_BYTE5;
#ifndef __PPE__
    constexpr field_t<mss::endian::LITTLE> FT::ODT_CA_GRPA_CK_BYTE6;
    constexpr field_t<mss::endian::LITTLE> FT::ODT_CA_GRPA_CS_BYTE6;
    constexpr field_t<mss::endian::LITTLE> FT::ODT_CA_GRPA_CK_BYTE7;
    constexpr field_t<mss::endian::LITTLE> FT::ODT_CA_GRPA_CS_BYTE7;
#endif
constexpr field_t<mss::endian::LITTLE> FT::ODT_CA_GRPB_CK_BYTE0;
constexpr field_t<mss::endian::LITTLE> FT::ODT_CA_GRPB_CS_BYTE0;
constexpr field_t<mss::endian::LITTLE> FT::ODT_CA_GRPB_CK_BYTE1;
constexpr field_t<mss::endian::LITTLE> FT::ODT_CA_GRPB_CS_BYTE1;
#ifndef __PPE__
    constexpr field_t<mss::endian::LITTLE> FT::ODT_CA_GRPB_CK_BYTE2;
    constexpr field_t<mss::endian::LITTLE> FT::ODT_CA_GRPB_CS_BYTE2;
    constexpr field_t<mss::endian::LITTLE> FT::ODT_CA_GRPB_CK_BYTE3;
    constexpr field_t<mss::endian::LITTLE> FT::ODT_CA_GRPB_CS_BYTE3;
#endif
constexpr field_t<mss::endian::LITTLE> FT::ODT_CA_GRPB_CK_BYTE4;
constexpr field_t<mss::endian::LITTLE> FT::ODT_CA_GRPB_CS_BYTE4;
constexpr field_t<mss::endian::LITTLE> FT::ODT_CA_GRPB_CK_BYTE5;
constexpr field_t<mss::endian::LITTLE> FT::ODT_CA_GRPB_CS_BYTE5;
#ifndef __PPE__
    constexpr field_t<mss::endian::LITTLE> FT::ODT_CA_GRPB_CK_BYTE6;
    constexpr field_t<mss::endian::LITTLE> FT::ODT_CA_GRPB_CS_BYTE6;
    constexpr field_t<mss::endian::LITTLE> FT::ODT_CA_GRPB_CK_BYTE7;
    constexpr field_t<mss::endian::LITTLE> FT::ODT_CA_GRPB_CS_BYTE7;
#endif
constexpr field_t<mss::endian::LITTLE> FT::ODT_CA_CK_BYTE0;
constexpr field_t<mss::endian::LITTLE> FT::ODT_CA_CS_BYTE0;
#ifndef __PPE__
    constexpr field_t<mss::endian::LITTLE> FT::ODT_CA_BYTE0_EXP_GRP;
#endif
constexpr field_t<mss::endian::LITTLE> FT::CA_ODT_DQS_GRPA_BYTE0;
constexpr field_t<mss::endian::LITTLE> FT::DQS_RTT_PARK_GRPA_BYTE0;
constexpr field_t<mss::endian::LITTLE> FT::CA_ODT_DQS_GRPA_BYTE1;
constexpr field_t<mss::endian::LITTLE> FT::DQS_RTT_PARK_GRPA_BYTE1;
#ifndef __PPE__
    constexpr field_t<mss::endian::LITTLE> FT::CA_ODT_DQS_GRPA_BYTE2;
    constexpr field_t<mss::endian::LITTLE> FT::DQS_RTT_PARK_GRPA_BYTE2;
    constexpr field_t<mss::endian::LITTLE> FT::CA_ODT_DQS_GRPA_BYTE3;
    constexpr field_t<mss::endian::LITTLE> FT::DQS_RTT_PARK_GRPA_BYTE3;
#endif
constexpr field_t<mss::endian::LITTLE> FT::CA_ODT_DQS_GRPA_BYTE4;
constexpr field_t<mss::endian::LITTLE> FT::DQS_RTT_PARK_GRPA_BYTE4;
constexpr field_t<mss::endian::LITTLE> FT::CA_ODT_DQS_GRPA_BYTE5;
constexpr field_t<mss::endian::LITTLE> FT::DQS_RTT_PARK_GRPA_BYTE5;
#ifndef __PPE__
    constexpr field_t<mss::endian::LITTLE> FT::CA_ODT_DQS_GRPA_BYTE6;
    constexpr field_t<mss::endian::LITTLE> FT::DQS_RTT_PARK_GRPA_BYTE6;
    constexpr field_t<mss::endian::LITTLE> FT::CA_ODT_DQS_GRPA_BYTE7;
    constexpr field_t<mss::endian::LITTLE> FT::DQS_RTT_PARK_GRPA_BYTE7;
#endif
constexpr field_t<mss::endian::LITTLE> FT::CA_ODT_DQS_GRPB_BYTE0;
constexpr field_t<mss::endian::LITTLE> FT::DQS_RTT_PARK_GRPB_BYTE0;
constexpr field_t<mss::endian::LITTLE> FT::CA_ODT_DQS_GRPB_BYTE1;
constexpr field_t<mss::endian::LITTLE> FT::DQS_RTT_PARK_GRPB_BYTE1;
#ifndef __PPE__
    constexpr field_t<mss::endian::LITTLE> FT::CA_ODT_DQS_GRPB_BYTE2;
    constexpr field_t<mss::endian::LITTLE> FT::DQS_RTT_PARK_GRPB_BYTE2;
    constexpr field_t<mss::endian::LITTLE> FT::CA_ODT_DQS_GRPB_BYTE3;
    constexpr field_t<mss::endian::LITTLE> FT::DQS_RTT_PARK_GRPB_BYTE3;
#endif
constexpr field_t<mss::endian::LITTLE> FT::CA_ODT_DQS_GRPB_BYTE4;
constexpr field_t<mss::endian::LITTLE> FT::DQS_RTT_PARK_GRPB_BYTE4;
constexpr field_t<mss::endian::LITTLE> FT::CA_ODT_DQS_GRPB_BYTE5;
constexpr field_t<mss::endian::LITTLE> FT::DQS_RTT_PARK_GRPB_BYTE5;
#ifndef __PPE__
    constexpr field_t<mss::endian::LITTLE> FT::CA_ODT_DQS_GRPB_BYTE6;
    constexpr field_t<mss::endian::LITTLE> FT::DQS_RTT_PARK_GRPB_BYTE6;
    constexpr field_t<mss::endian::LITTLE> FT::CA_ODT_DQS_GRPB_BYTE7;
    constexpr field_t<mss::endian::LITTLE> FT::DQS_RTT_PARK_GRPB_BYTE7;
#endif
constexpr field_t<mss::endian::LITTLE> FT::CA_ODT_BYTE0;
constexpr field_t<mss::endian::LITTLE> FT::DQS_RTT_PARK_BYTE0;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_WR_CNTRL_ON_OFFSET_BYTE0;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_WR_CNTRL_OFF_OFFSET_BYTE0;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_WR_CNTRL_ON_OFFSET_BYTE1;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_WR_CNTRL_OFF_OFFSET_BYTE1;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_WR_CNTRL_ON_OFFSET_BYTE2;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_WR_CNTRL_OFF_OFFSET_BYTE2;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_WR_CNTRL_ON_OFFSET_BYTE3;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_WR_CNTRL_OFF_OFFSET_BYTE3;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_WR_CNTRL_ON_OFFSET_BYTE4;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_WR_CNTRL_OFF_OFFSET_BYTE4;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_WR_CNTRL_ON_OFFSET_BYTE5;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_WR_CNTRL_OFF_OFFSET_BYTE5;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_WR_CNTRL_ON_OFFSET_BYTE6;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_WR_CNTRL_OFF_OFFSET_BYTE6;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_WR_CNTRL_ON_OFFSET_BYTE7;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_WR_CNTRL_OFF_OFFSET_BYTE7;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_WR_CNTRL_ON_OFFSET[FT::MAX_CHANNELS][FT::MAX_PORTS][FT::MAX_RANKS];
constexpr field_t<mss::endian::LITTLE> FT::ODTL_WR_CNTRL_OFF_OFFSET[FT::MAX_CHANNELS][FT::MAX_PORTS][FT::MAX_RANKS];
constexpr field_t<mss::endian::LITTLE> FT::ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE0;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE0;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE1;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE1;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE2;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE2;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE3;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE3;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE4;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE4;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE5;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE5;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE6;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE6;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_NT_WR_CNTRL_ON_OFFSET_BYTE7;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_NT_WR_CNTRL_OFF_OFFSET_BYTE7;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_NT_WR_CNTRL_ON_OFFSET[FT::MAX_CHANNELS][FT::MAX_PORTS][FT::MAX_RANKS];
constexpr field_t<mss::endian::LITTLE> FT::ODTL_NT_WR_CNTRL_OFF_OFFSET[FT::MAX_CHANNELS][FT::MAX_PORTS][FT::MAX_RANKS];
constexpr field_t<mss::endian::LITTLE> FT::ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE0;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE0;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE1;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE1;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE2;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE2;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE3;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE3;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE4;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE4;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE5;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE5;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE6;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE6;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_NT_RD_CNTRL_ON_OFFSET_BYTE7;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_NT_RD_CNTRL_OFF_OFFSET_BYTE7;
constexpr field_t<mss::endian::LITTLE> FT::ODTL_NT_RD_CNTRL_ON_OFFSET[FT::MAX_CHANNELS][FT::MAX_PORTS][FT::MAX_RANKS];
constexpr field_t<mss::endian::LITTLE> FT::ODTL_NT_RD_CNTRL_OFF_OFFSET[FT::MAX_CHANNELS][FT::MAX_PORTS][FT::MAX_RANKS];
constexpr field_t<mss::endian::LITTLE> FT::BASE_VREF_CA_BYTE0;
constexpr field_t<mss::endian::LITTLE> FT::BASE_VREF_CA_BYTE1;
constexpr field_t<mss::endian::LITTLE> FT::BASE_VREF_CA_BYTE2;
constexpr field_t<mss::endian::LITTLE> FT::BASE_VREF_CA_BYTE3;
constexpr field_t<mss::endian::LITTLE> FT::BASE_VREF_CA_BYTE4;
constexpr field_t<mss::endian::LITTLE> FT::BASE_VREF_CA_BYTE5;
constexpr field_t<mss::endian::LITTLE> FT::BASE_VREF_CA_BYTE6;
constexpr field_t<mss::endian::LITTLE> FT::BASE_VREF_CA_BYTE7;
constexpr field_t<mss::endian::LITTLE> FT::BASE_VREF_CS_BYTE0;
constexpr field_t<mss::endian::LITTLE> FT::BASE_VREF_CS_BYTE1;
constexpr field_t<mss::endian::LITTLE> FT::BASE_VREF_CS_BYTE2;
constexpr field_t<mss::endian::LITTLE> FT::BASE_VREF_CS_BYTE3;
constexpr field_t<mss::endian::LITTLE> FT::BASE_VREF_CS_BYTE4;
constexpr field_t<mss::endian::LITTLE> FT::BASE_VREF_CS_BYTE5;
constexpr field_t<mss::endian::LITTLE> FT::BASE_VREF_CS_BYTE6;
constexpr field_t<mss::endian::LITTLE> FT::BASE_VREF_CS_BYTE7;
constexpr field_t<mss::endian::LITTLE> FT::VREF_CA_OFFSET_MULT;
constexpr field_t<mss::endian::LITTLE> FT::VREF_CS_OFFSET_MULT;
constexpr field_t<mss::endian::LITTLE> FT::VREF_CA_OFFSET_STEP_BYTE0;
constexpr field_t<mss::endian::LITTLE> FT::VREF_CS_OFFSET_STEP_BYTE0;
constexpr field_t<mss::endian::LITTLE> FT::VREF_CA_OFFSET_BYTE0_ADD_SUB;
constexpr field_t<mss::endian::LITTLE> FT::VREF_CS_OFFSET_BYTE0_ADD_SUB;
#ifndef __PPE__
    constexpr field_t<mss::endian::LITTLE> FT::VREF_CA_OFFSET_STEP_BYTE10;
    constexpr field_t<mss::endian::LITTLE> FT::VREF_CS_OFFSET_STEP_BYTE10;
    constexpr field_t<mss::endian::LITTLE> FT::VREF_CA_OFFSET_BYTE10_ADD_SUB;
    constexpr field_t<mss::endian::LITTLE> FT::VREF_CS_OFFSET_BYTE10_ADD_SUB;
    constexpr field_t<mss::endian::LITTLE> FT::VREF_CA_OFFSET_STEP_BYTE20;
    constexpr field_t<mss::endian::LITTLE> FT::VREF_CS_OFFSET_STEP_BYTE20;
    constexpr field_t<mss::endian::LITTLE> FT::VREF_CA_OFFSET_BYTE20_ADD_SUB;
    constexpr field_t<mss::endian::LITTLE> FT::VREF_CS_OFFSET_BYTE20_ADD_SUB;
    constexpr field_t<mss::endian::LITTLE> FT::VREF_CA_OFFSET_STEP_BYTE30;
    constexpr field_t<mss::endian::LITTLE> FT::VREF_CS_OFFSET_STEP_BYTE30;
    constexpr field_t<mss::endian::LITTLE> FT::VREF_CA_OFFSET_BYTE30_ADD_SUB;
    constexpr field_t<mss::endian::LITTLE> FT::VREF_CS_OFFSET_BYTE30_ADD_SUB;
    constexpr field_t<mss::endian::LITTLE> FT::VREF_CA_OFFSET_STEP_BYTE40;
    constexpr field_t<mss::endian::LITTLE> FT::VREF_CS_OFFSET_STEP_BYTE40;
    constexpr field_t<mss::endian::LITTLE> FT::VREF_CA_OFFSET_BYTE40_ADD_SUB;
    constexpr field_t<mss::endian::LITTLE> FT::VREF_CS_OFFSET_BYTE40_ADD_SUB;
    constexpr field_t<mss::endian::LITTLE> FT::VREF_CA_OFFSET_STEP_BYTE50;
    constexpr field_t<mss::endian::LITTLE> FT::VREF_CS_OFFSET_STEP_BYTE50;
    constexpr field_t<mss::endian::LITTLE> FT::VREF_CA_OFFSET_BYTE50_ADD_SUB;
    constexpr field_t<mss::endian::LITTLE> FT::VREF_CS_OFFSET_BYTE50_ADD_SUB;
    constexpr field_t<mss::endian::LITTLE> FT::VREF_CA_OFFSET_STEP_BYTE60;
    constexpr field_t<mss::endian::LITTLE> FT::VREF_CS_OFFSET_STEP_BYTE60;
    constexpr field_t<mss::endian::LITTLE> FT::VREF_CA_OFFSET_BYTE60_ADD_SUB;
    constexpr field_t<mss::endian::LITTLE> FT::VREF_CS_OFFSET_BYTE60_ADD_SUB;
    constexpr field_t<mss::endian::LITTLE> FT::VREF_CA_OFFSET_STEP_BYTE70;
    constexpr field_t<mss::endian::LITTLE> FT::VREF_CS_OFFSET_STEP_BYTE70;
    constexpr field_t<mss::endian::LITTLE> FT::VREF_CA_OFFSET_BYTE70_ADD_SUB;
    constexpr field_t<mss::endian::LITTLE> FT::VREF_CS_OFFSET_BYTE70_ADD_SUB;
    constexpr field_t<mss::endian::LITTLE> FT::CS_DELAYS_A0_0_A0_2_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CS_DELAYS_A0_0_A0_2_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CS_DELAYS_A0_1_A0_3_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CS_DELAYS_A0_1_A0_3_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CK_DELAYS_A0_0_A0_2_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CK_DELAYS_A0_0_A0_2_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CK_DELAYS_A0_1_A0_3_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CK_DELAYS_A0_1_A0_3_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_A0_0_A0_1_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_A0_0_A0_1_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_A0_2_A0_3_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_A0_2_A0_3_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_A0_4_A0_5_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_A0_4_A0_5_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_A0_6_A0_7_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_A0_6_A0_7_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_A0_8_A0_9_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_A0_8_A0_9_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_A0_10_A0_11_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_A0_10_A0_11_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_A0_12_A0_13_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_A0_12_A0_13_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CS_DELAYS_B0_0_B0_2_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CS_DELAYS_B0_0_B0_2_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CS_DELAYS_B0_1_B0_3_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CS_DELAYS_B0_1_B0_3_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CK_DELAYS_B0_0_B0_2_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CK_DELAYS_B0_0_B0_2_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CK_DELAYS_B0_1_B0_3_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CK_DELAYS_B0_1_B0_3_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_B0_0_B0_1_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_B0_0_B0_1_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_B0_2_B0_3_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_B0_2_B0_3_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_B0_4_B0_5_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_B0_4_B0_5_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_B0_6_B0_7_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_B0_6_B0_7_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_B0_8_B0_9_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_B0_8_B0_9_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_B0_10_B0_11_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_B0_10_B0_11_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_B0_12_B0_13_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_B0_12_B0_13_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CS_DELAYS_A1_0_A1_2_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CS_DELAYS_A1_0_A1_2_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CS_DELAYS_A1_1_A1_3_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CS_DELAYS_A1_1_A1_3_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CK_DELAYS_A1_0_A1_2_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CK_DELAYS_A1_0_A1_2_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CK_DELAYS_A1_1_A1_3_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CK_DELAYS_A1_1_A1_3_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_A1_0_A1_1_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_A1_0_A1_1_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_A1_2_A1_3_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_A1_2_A1_3_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_A1_4_A1_5_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_A1_4_A1_5_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_A1_6_A1_7_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_A1_6_A1_7_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_A1_8_A1_9_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_A1_8_A1_9_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_A1_10_A1_11_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_A1_10_A1_11_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_A1_12_A1_13_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_A1_12_A1_13_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CS_DELAYS_B1_0_B1_2_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CS_DELAYS_B1_0_B1_2_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CS_DELAYS_B1_1_B1_3_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CS_DELAYS_B1_1_B1_3_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CK_DELAYS_B1_0_B1_2_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CK_DELAYS_B1_0_B1_2_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CK_DELAYS_B1_1_B1_3_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CK_DELAYS_B1_1_B1_3_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_B1_0_B1_1_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_B1_0_B1_1_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_B1_2_B1_3_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_B1_2_B1_3_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_B1_4_B1_5_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_B1_4_B1_5_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_B1_6_B1_7_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_B1_6_B1_7_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_B1_8_B1_9_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_B1_8_B1_9_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_B1_10_B1_11_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_B1_10_B1_11_COARSE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_B1_12_B1_13_FINE;
    constexpr field_t<mss::endian::LITTLE> FT::CA_DELAYS_B1_12_B1_13_COARSE;
#endif
constexpr field_t<mss::endian::LITTLE> FT::PMIC0_SWA_VOLT_OFF;
constexpr field_t<mss::endian::LITTLE> FT::PMIC0_SWA_OFF_DIRECTION;
constexpr field_t<mss::endian::LITTLE> FT::PMIC0_SWB_VOLT_OFF;
constexpr field_t<mss::endian::LITTLE> FT::PMIC0_SWB_OFF_DIRECTION;
constexpr field_t<mss::endian::LITTLE> FT::PMIC0_SWC_VOLT_OFF;
constexpr field_t<mss::endian::LITTLE> FT::PMIC0_SWC_OFF_DIRECTION;
constexpr field_t<mss::endian::LITTLE> FT::PMIC0_SWD_VOLT_OFF;
constexpr field_t<mss::endian::LITTLE> FT::PMIC0_SWD_OFF_DIRECTION;
constexpr field_t<mss::endian::LITTLE> FT::PMIC1_SWA_VOLT_OFF;
constexpr field_t<mss::endian::LITTLE> FT::PMIC1_SWA_OFF_DIRECTION;
constexpr field_t<mss::endian::LITTLE> FT::PMIC1_SWB_VOLT_OFF;
constexpr field_t<mss::endian::LITTLE> FT::PMIC1_SWB_OFF_DIRECTION;
constexpr field_t<mss::endian::LITTLE> FT::PMIC1_SWC_VOLT_OFF;
constexpr field_t<mss::endian::LITTLE> FT::PMIC1_SWC_OFF_DIRECTION;
constexpr field_t<mss::endian::LITTLE> FT::PMIC1_SWD_VOLT_OFF;
constexpr field_t<mss::endian::LITTLE> FT::PMIC1_SWD_OFF_DIRECTION;
constexpr field_t<mss::endian::LITTLE> FT::PMIC2_SWA_VOLT_OFF;
constexpr field_t<mss::endian::LITTLE> FT::PMIC2_SWA_OFF_DIRECTION;
constexpr field_t<mss::endian::LITTLE> FT::PMIC2_SWB_VOLT_OFF;
constexpr field_t<mss::endian::LITTLE> FT::PMIC2_SWB_OFF_DIRECTION;
constexpr field_t<mss::endian::LITTLE> FT::PMIC2_SWC_VOLT_OFF;
constexpr field_t<mss::endian::LITTLE> FT::PMIC2_SWC_OFF_DIRECTION;
constexpr field_t<mss::endian::LITTLE> FT::PMIC2_SWD_VOLT_OFF;
constexpr field_t<mss::endian::LITTLE> FT::PMIC2_SWD_OFF_DIRECTION;
constexpr field_t<mss::endian::LITTLE> FT::PMIC3_SWA_VOLT_OFF;
constexpr field_t<mss::endian::LITTLE> FT::PMIC3_SWA_OFF_DIRECTION;
constexpr field_t<mss::endian::LITTLE> FT::PMIC3_SWB_VOLT_OFF;
constexpr field_t<mss::endian::LITTLE> FT::PMIC3_SWB_OFF_DIRECTION;
constexpr field_t<mss::endian::LITTLE> FT::PMIC3_SWC_VOLT_OFF;
constexpr field_t<mss::endian::LITTLE> FT::PMIC3_SWC_OFF_DIRECTION;
constexpr field_t<mss::endian::LITTLE> FT::PMIC3_SWD_VOLT_OFF;
constexpr field_t<mss::endian::LITTLE> FT::PMIC3_SWD_OFF_DIRECTION;
constexpr field_t<mss::endian::LITTLE> FT::PMIC0_SWA_CURRENT_WARNING;
constexpr field_t<mss::endian::LITTLE> FT::PMIC0_SWB_CURRENT_WARNING;
constexpr field_t<mss::endian::LITTLE> FT::PMIC0_SWC_CURRENT_WARNING;
constexpr field_t<mss::endian::LITTLE> FT::PMIC0_SWD_CURRENT_WARNING;
constexpr field_t<mss::endian::LITTLE> FT::PMIC1_SWA_CURRENT_WARNING;
constexpr field_t<mss::endian::LITTLE> FT::PMIC1_SWB_CURRENT_WARNING;
constexpr field_t<mss::endian::LITTLE> FT::PMIC1_SWC_CURRENT_WARNING;
constexpr field_t<mss::endian::LITTLE> FT::PMIC1_SWD_CURRENT_WARNING;
constexpr field_t<mss::endian::LITTLE> FT::PMIC2_SWA_CURRENT_WARNING;
constexpr field_t<mss::endian::LITTLE> FT::PMIC2_SWB_CURRENT_WARNING;
constexpr field_t<mss::endian::LITTLE> FT::PMIC2_SWC_CURRENT_WARNING;
constexpr field_t<mss::endian::LITTLE> FT::PMIC2_SWD_CURRENT_WARNING;
constexpr field_t<mss::endian::LITTLE> FT::PMIC3_SWA_CURRENT_WARNING;
constexpr field_t<mss::endian::LITTLE> FT::PMIC3_SWB_CURRENT_WARNING;
constexpr field_t<mss::endian::LITTLE> FT::PMIC3_SWC_CURRENT_WARNING;
constexpr field_t<mss::endian::LITTLE> FT::PMIC3_SWD_CURRENT_WARNING;

} // efd
} // mss
