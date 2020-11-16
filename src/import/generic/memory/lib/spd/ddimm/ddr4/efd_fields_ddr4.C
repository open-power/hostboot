/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/spd/ddimm/ddr4/efd_fields_ddr4.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
/// @file efd_fields_ddr4.C
/// @brief EFD data fields forward declarations
///

// *HWP HWP Owner: Mark Pizzutillo <Mark.Pizzutillo@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP
// EKB-Mirror-To: hostboot

#include <generic/memory/lib/spd/ddimm/ddr4/efd_fields_ddr4.H>

namespace mss
{
namespace efd
{

using FT = fields<mss::spd::device_type::DDR4, mss::efd::id::DDR4_CUSTOM_MICROCHIP>;

// These "definitions" are needed to generate linkage for the static constexprs declared in the .H because of ODR-used

constexpr field_t<mss::endian::LITTLE> FT::CAC_DLY_A_0;
constexpr field_t<mss::endian::LITTLE> FT::CAC_DLY_A_1;
constexpr field_t<mss::endian::LITTLE> FT::CAC_DLY_A_2;
constexpr field_t<mss::endian::LITTLE> FT::CAC_DLY_A_3;
constexpr field_t<mss::endian::LITTLE> FT::CAC_DLY_A_4;
constexpr field_t<mss::endian::LITTLE> FT::CAC_DLY_A_5;
constexpr field_t<mss::endian::LITTLE> FT::CAC_DLY_A_6;
constexpr field_t<mss::endian::LITTLE> FT::CAC_DLY_A_7;
constexpr field_t<mss::endian::LITTLE> FT::CAC_DLY_B_0;
constexpr field_t<mss::endian::LITTLE> FT::CAC_DLY_B_1;
constexpr field_t<mss::endian::LITTLE> FT::CAC_DLY_B_2;
constexpr field_t<mss::endian::LITTLE> FT::CAC_DLY_B_3;
constexpr field_t<mss::endian::LITTLE> FT::CAC_DLY_B_4;
constexpr field_t<mss::endian::LITTLE> FT::CAC_DLY_B_5;
constexpr field_t<mss::endian::LITTLE> FT::CAC_DLY_B_6;
constexpr field_t<mss::endian::LITTLE> FT::CAC_DLY_B_7;
constexpr field_t<mss::endian::LITTLE> FT::WR_VREF_DQ_RANGE;
constexpr field_t<mss::endian::LITTLE> FT::WR_VREF_DQ_VALUE;
constexpr field_t<mss::endian::LITTLE> FT::INIT_PHY_VREF;
constexpr field_t<mss::endian::LITTLE> FT::RCD_DIC_1;
constexpr field_t<mss::endian::LITTLE> FT::RCD_DIC_0;
constexpr field_t<mss::endian::LITTLE> FT::RCD_VOLTAGE_CTRL_0;
constexpr field_t<mss::endian::LITTLE> FT::RCD_VOLTAGE_CTRL_1;
constexpr field_t<mss::endian::LITTLE> FT::RCD_IBT;
constexpr field_t<mss::endian::LITTLE> FT::RCD_DB_DIC;
constexpr field_t<mss::endian::LITTLE> FT::RCD_SLEW_RATE_CTRL_1;
constexpr field_t<mss::endian::LITTLE> FT::RCD_SLEW_RATE_CTRL_0;
constexpr field_t<mss::endian::LITTLE> FT::BIST_CA_LATENCY_MODE;
constexpr field_t<mss::endian::LITTLE> FT::BIST_CA_PL_MODE;
constexpr field_t<mss::endian::LITTLE> FT::DFIMRL_DDRCLK;
constexpr field_t<mss::endian::LITTLE> FT::PMIC0_SWA_OFFSET;
constexpr field_t<mss::endian::LITTLE> FT::PMIC0_SWA_OFFSET_DIRECTION;
constexpr field_t<mss::endian::LITTLE> FT::PMIC0_SWB_OFFSET;
constexpr field_t<mss::endian::LITTLE> FT::PMIC0_SWB_OFFSET_DIRECTION;
constexpr field_t<mss::endian::LITTLE> FT::PMIC0_SWC_OFFSET;
constexpr field_t<mss::endian::LITTLE> FT::PMIC0_SWC_OFFSET_DIRECTION;
constexpr field_t<mss::endian::LITTLE> FT::PMIC0_SWD_OFFSET;
constexpr field_t<mss::endian::LITTLE> FT::PMIC0_SWD_OFFSET_DIRECTION;
constexpr field_t<mss::endian::LITTLE> FT::PMIC1_SWA_OFFSET;
constexpr field_t<mss::endian::LITTLE> FT::PMIC1_SWA_OFFSET_DIRECTION;
constexpr field_t<mss::endian::LITTLE> FT::PMIC1_SWB_OFFSET;
constexpr field_t<mss::endian::LITTLE> FT::PMIC1_SWB_OFFSET_DIRECTION;
constexpr field_t<mss::endian::LITTLE> FT::PMIC1_SWC_OFFSET;
constexpr field_t<mss::endian::LITTLE> FT::PMIC1_SWC_OFFSET_DIRECTION;
constexpr field_t<mss::endian::LITTLE> FT::PMIC1_SWD_OFFSET;
constexpr field_t<mss::endian::LITTLE> FT::PMIC1_SWD_OFFSET_DIRECTION;
constexpr field_t<mss::endian::LITTLE> FT::PMIC0_SWA_CURRENT_WARNING;
constexpr field_t<mss::endian::LITTLE> FT::PMIC0_SWB_CURRENT_WARNING;
constexpr field_t<mss::endian::LITTLE> FT::PMIC0_SWC_CURRENT_WARNING;
constexpr field_t<mss::endian::LITTLE> FT::PMIC0_SWD_CURRENT_WARNING;
constexpr field_t<mss::endian::LITTLE> FT::PMIC1_SWA_CURRENT_WARNING;
constexpr field_t<mss::endian::LITTLE> FT::PMIC1_SWB_CURRENT_WARNING;
constexpr field_t<mss::endian::LITTLE> FT::PMIC1_SWC_CURRENT_WARNING;
constexpr field_t<mss::endian::LITTLE> FT::PMIC1_SWD_CURRENT_WARNING;
constexpr field_t<mss::endian::LITTLE> FT::PHY_ODT_IMPEDANCE;
constexpr field_t<mss::endian::LITTLE> FT::PHY_DRIVE_IMPEDANCE_PULL_UP;
constexpr field_t<mss::endian::LITTLE> FT::PHY_DRIVE_IMPEDANCE_PULL_DOWN;
constexpr field_t<mss::endian::LITTLE> FT::PHY_SLEW_RATE_DQ_DQS;
constexpr field_t<mss::endian::LITTLE> FT::ATX_IMPEDANCE;
constexpr field_t<mss::endian::LITTLE> FT::ATX_SLEW_RATE;
constexpr field_t<mss::endian::LITTLE> FT::CK_IMPEDANCE;
constexpr field_t<mss::endian::LITTLE> FT::CK_SLEW_RATE;
constexpr field_t<mss::endian::LITTLE> FT::ALERT_ODT_IMPEDANCE;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_NOM_RANK0;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_NOM_RANK1;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_NOM_RANK2;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_NOM_RANK3;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_WR_RANK0;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_WR_RANK1;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_WR_RANK2;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_WR_RANK3;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_PARK_RANK0;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_PARK_RANK1;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_PARK_RANK2;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_RTT_PARK_RANK3;
constexpr field_t<mss::endian::LITTLE> FT::READ_PREAMBLE;
constexpr field_t<mss::endian::LITTLE> FT::WRITE_PREAMBLE;
constexpr field_t<mss::endian::LITTLE> FT::PHY_EQUALIZATION;
constexpr field_t<mss::endian::LITTLE> FT::DRAM_DIC;
constexpr field_t<mss::endian::LITTLE> FT::ODT_WR_MAP_RANK0;
constexpr field_t<mss::endian::LITTLE> FT::ODT_WR_MAP_RANK1;
constexpr field_t<mss::endian::LITTLE> FT::ODT_WR_MAP_RANK2;
constexpr field_t<mss::endian::LITTLE> FT::ODT_WR_MAP_RANK3;
constexpr field_t<mss::endian::LITTLE> FT::ODT_RD_MAP_RANK0;
constexpr field_t<mss::endian::LITTLE> FT::ODT_RD_MAP_RANK1;
constexpr field_t<mss::endian::LITTLE> FT::ODT_RD_MAP_RANK2;
constexpr field_t<mss::endian::LITTLE> FT::ODT_RD_MAP_RANK3;
constexpr field_t<mss::endian::LITTLE> FT::GEARDOWN_DURING_TRAINING;
constexpr field_t<mss::endian::LITTLE> FT::F1RC1X;
constexpr field_t<mss::endian::LITTLE> FT::F1RC2X;
constexpr field_t<mss::endian::LITTLE> FT::F1RC3X;
constexpr field_t<mss::endian::LITTLE> FT::F1RC4X;
constexpr field_t<mss::endian::LITTLE> FT::F1RC5X;
constexpr field_t<mss::endian::LITTLE> FT::F1RC6X;
constexpr field_t<mss::endian::LITTLE> FT::F1RC7X;

} // efd
} // mss
