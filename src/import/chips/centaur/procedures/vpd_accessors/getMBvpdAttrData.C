/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/vpd_accessors/getMBvpdAttrData.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
// $Id: getMBvpdAttrData.C,v 1.9 2015/11/02 21:42:23 sglancy Exp $
/**
 *  @file getMBvpdAttrData.C
 *
 *  @brief get Attribute Data from MBvpd
 *
 */
#include    <stdint.h>

//  fapi2 support
#include    <fapi2.H>
#include    <getMBvpdAttr.H>

using   namespace   fapi2;
using   namespace   getAttrData;

namespace fapi2
{
namespace getAttrData
{

// ----------------------------------------------------------------------------
// Attribute definition table
// ----------------------------------------------------------------------------

const MBvpdAttrDef g_MBVPD_ATTR_DEF_array [] =
{

//----------------------------------------------------------------------------------
// Attribute exceptions to use with SPDX or VSPD VM keyword
// Note: Ideally, all new exception will be in this section and be for both
//       ISDIMMs and CDIMMMs
//----------------------------------------------------------------------------------
    {fapi2::ATTR_CEN_VPD_MR_VERSION_BYTE, DimmType::ALL_DIMM, VM_01, MBVPD_KEYWORD_MR, 0, UINT8, 0},
    {fapi2::ATTR_CEN_VPD_MR_DATA_CONTROL_BYTE, DimmType::ALL_DIMM, VM_01, MBVPD_KEYWORD_MR, 1, UINT8, 0},
    {fapi2::ATTR_CEN_VPD_MT_VERSION_BYTE, DimmType::ALL_DIMM, VM_01, MBVPD_KEYWORD_MT, 0, UINT8, 0},
    {fapi2::ATTR_CEN_VPD_MT_DATA_CONTROL_BYTE, DimmType::ALL_DIMM, VM_01, MBVPD_KEYWORD_MT, 1, UINT8, 0},
    {fapi2::ATTR_CEN_VPD_PERIODIC_MEMCAL_MODE_OPTIONS, DimmType::ALL_DIMM, VM_01, MBVPD_KEYWORD_MR, 50, UINT32_BY2 | UINT16_DATA, 0},
    {fapi2::ATTR_CEN_VPD_DRAM_RTT_PARK, DimmType::ALL_DIMM, VM_01, MBVPD_KEYWORD_MT, 56, UINT8_BY2_BY2_BY4 | XLATE_RTT_PARK, 0},
    {fapi2::ATTR_CEN_VPD_RD_CTR_WINDAGE_OFFSET, DimmType::ALL_DIMM, VM_01, MBVPD_KEYWORD_MT, 64, UINT32_BY2 | UINT16_DATA, 0},

    {fapi2::ATTR_CEN_VPD_DIMM_RCD_OUTPUT_TIMING, DimmType::ISDIMM, VM_01, MBVPD_KEYWORD_MT, 68, UINT8_BY2_BY2 | BOTH_DIMMS, 0},
    {fapi2::ATTR_CEN_VPD_DIMM_RCD_IBT, DimmType::ISDIMM, VM_01, MBVPD_KEYWORD_MT, 66, UINT32_BY2_BY2 | UINT8_DATA, 0},
    {fapi2::ATTR_CEN_VPD_DIMM_RCD_OUTPUT_TIMING, DimmType::CDIMM, VM_01, MBVPD_KEYWORD_MT, 68, UINT8_BY2_BY2 | DEFAULT_VALUE, 0},
    {fapi2::ATTR_CEN_VPD_DIMM_RCD_IBT, DimmType::CDIMM, VM_01, MBVPD_KEYWORD_MT, 66, UINT32_BY2_BY2 | DEFAULT_VALUE, 0},
    {fapi2::ATTR_CEN_VPD_RD_VREF, DimmType::ALL_DIMM, VM_01, MBVPD_KEYWORD_MT, 34, UINT32_BY2 | UINT8_DATA | XLATE_RD_VREF, 0},
    {fapi2::ATTR_CEN_VPD_DRAM_WR_VREF, DimmType::ALL_DIMM, VM_01, MBVPD_KEYWORD_MT, 35, UINT32_BY2 | UINT8_DATA | XLATE_WR_VREF, 0},
    {fapi2::ATTR_CEN_VPD_DRAM_WRDDR4_VREF, DimmType::ALL_DIMM, VM_01, MBVPD_KEYWORD_MT, 36, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_RCV_IMP_DQ_DQS, DimmType::ALL_DIMM, VM_01, MBVPD_KEYWORD_MT, 37, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_DRV_IMP_DQ_DQS, DimmType::ALL_DIMM, VM_01, MBVPD_KEYWORD_MT, 38, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_DRV_IMP_CNTL, DimmType::ALL_DIMM, VM_01, MBVPD_KEYWORD_MT, 39, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_DRV_IMP_ADDR, DimmType::ALL_DIMM, VM_01, MBVPD_KEYWORD_MT, 40, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_DRV_IMP_CLK, DimmType::ALL_DIMM, VM_01, MBVPD_KEYWORD_MT, 41, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_DRV_IMP_SPCKE, DimmType::ALL_DIMM, VM_01, MBVPD_KEYWORD_MT, 42, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_SLEW_RATE_DQ_DQS, DimmType::ALL_DIMM, VM_01, MBVPD_KEYWORD_MT, 43, UINT8_BY2 | XLATE_SLEW, 0},
    {fapi2::ATTR_CEN_VPD_SLEW_RATE_CNTL, DimmType::ALL_DIMM, VM_01, MBVPD_KEYWORD_MT, 44, UINT8_BY2 | XLATE_SLEW, 0},
    {fapi2::ATTR_CEN_VPD_SLEW_RATE_ADDR, DimmType::ALL_DIMM, VM_01, MBVPD_KEYWORD_MT, 45, UINT8_BY2 | XLATE_SLEW, 0},
    {fapi2::ATTR_CEN_VPD_SLEW_RATE_CLK, DimmType::ALL_DIMM, VM_01, MBVPD_KEYWORD_MT, 46, UINT8_BY2 | XLATE_SLEW, 0},
    {fapi2::ATTR_CEN_VPD_SLEW_RATE_SPCKE, DimmType::ALL_DIMM, VM_01, MBVPD_KEYWORD_MT, 47, UINT8_BY2 | XLATE_SLEW, 0},
    {fapi2::ATTR_CEN_VPD_CKE_PRI_MAP, DimmType::ALL_DIMM, VM_01, MBVPD_KEYWORD_MT, 48, UINT32_BY2 | UINT16_DATA, 0},
    {fapi2::ATTR_CEN_VPD_CKE_PWR_MAP, DimmType::ALL_DIMM, VM_01, MBVPD_KEYWORD_MT, 50, UINT64 | MERGE, 0},
    {fapi2::ATTR_CEN_VPD_RLO, DimmType::ALL_DIMM, VM_01, MBVPD_KEYWORD_MT, 54, UINT8_BY2 | LOW_NIBBLE, 0},
    {fapi2::ATTR_CEN_VPD_WLO, DimmType::ALL_DIMM, VM_01, MBVPD_KEYWORD_MT, 54, UINT8_BY2 | HIGH_NIBBLE, 0},
    {fapi2::ATTR_CEN_VPD_GPO, DimmType::ALL_DIMM, VM_01, MBVPD_KEYWORD_MT, 55, UINT8_BY2, 0},

//----------------------------------------------------------------------------------
// Attribute exceptions to use with SPDX or VSPD VD keyword
// Note: Ideally, all new exception will be in this section and be for both
//       ISDIMMs and CDIMMMs
//----------------------------------------------------------------------------------
    {fapi2::ATTR_CEN_VPD_DIMM_RCD_IBT, DimmType::ALL_DIMM, VD_01, MBVPD_KEYWORD_MT, 34, UINT32_BY2_BY2 | UINT8_DATA, 0},
    {fapi2::ATTR_CEN_VPD_DIMM_RCD_OUTPUT_TIMING, DimmType::ALL_DIMM, VD_01, MBVPD_KEYWORD_MT, 36, UINT8_BY2_BY2 | BOTH_DIMMS, 0},
    {fapi2::ATTR_CEN_VPD_DRAM_WR_VREF, DimmType::ALL_DIMM, VD_01, MBVPD_KEYWORD_MT, 38, UINT32_BY2 | UINT8_DATA | XLATE_WR_VREF, 0},

//----------------------------------------------------------------------------------
// Attribute exceptions to use with VINI VZ keyword
// All entries should select either ISDIMM or CDIMM since both used the VZ keyword
// Note: Ideally, there will be no more additions in this section as all future
//       DIMMs will use the VD keword
//----------------------------------------------------------------------------------

// Planar ISDIMM changes
// Need to include these exceptions to support early Palmetto and Habanero without the VD keyword & VZ=13
    {fapi2::ATTR_CEN_VPD_DIMM_RCD_IBT, DimmType::ISDIMM, VZ_13, MBVPD_KEYWORD_MT, 34, UINT32_BY2_BY2 | UINT8_DATA, 0},
    {fapi2::ATTR_CEN_VPD_DIMM_RCD_OUTPUT_TIMING, DimmType::ISDIMM, VZ_13, MBVPD_KEYWORD_MT, 36, UINT8_BY2_BY2 | BOTH_DIMMS, 0},
    // Create 3 reserved bytes in V13
    {fapi2::ATTR_CEN_VPD_DRAM_WR_VREF, DimmType::ISDIMM, VZ_13, MBVPD_KEYWORD_MT, 38, UINT32_BY2 | UINT8_DATA | XLATE_WR_VREF, 0},
// Need to include these exceptions to support early Palmetto and Habanero with VZ=11 and 10
    {fapi2::ATTR_CEN_VPD_DIMM_RCD_IBT, DimmType::ISDIMM, ALL_VZ, MBVPD_KEYWORD_MT, 34, UINT32_BY2_BY2 | DEFAULT_VALUE, 0x64},
    {fapi2::ATTR_CEN_VPD_DIMM_RCD_OUTPUT_TIMING, DimmType::ISDIMM, ALL_VZ, MBVPD_KEYWORD_MT, 35, UINT8_BY2_BY2 | DEFAULT_VALUE, 1},

// CDIMM changes in V60 (ascii 10)
// Need to include these exceptions to support pre DD 2.0 centaurs
    {fapi2::ATTR_CEN_VPD_TSYS_ADR, DimmType::CDIMM, VZ_10, MBVPD_KEYWORD_MR, 49, UINT8_BY2 | PORT00, 0},
    {fapi2::ATTR_CEN_VPD_TSYS_ADR, DimmType::CDIMM, ALL_VZ, MBVPD_KEYWORD_MR, 51, UINT8_BY2 | PORT00, 0},

    {fapi2::ATTR_CEN_VPD_TSYS_DP18, DimmType::CDIMM, VZ_10, MBVPD_KEYWORD_MR, 49, UINT8_BY2 | PORT11, 0},
    {fapi2::ATTR_CEN_VPD_TSYS_DP18, DimmType::CDIMM, ALL_VZ, MBVPD_KEYWORD_MR, 51, UINT8_BY2 | PORT11, 0},

    {fapi2::ATTR_CEN_VPD_RLO, DimmType::CDIMM, VZ_10, MBVPD_KEYWORD_MT, 60, UINT8_BY2 | LOW_NIBBLE, 0},
    {fapi2::ATTR_CEN_VPD_RLO, DimmType::CDIMM, ALL_VZ, MBVPD_KEYWORD_MR, 49, UINT8_BY2 | LOW_NIBBLE, 0},

    {fapi2::ATTR_CEN_VPD_WLO, DimmType::CDIMM, VZ_10, MBVPD_KEYWORD_MT, 60, UINT8_BY2 | HIGH_NIBBLE, 0},
    {fapi2::ATTR_CEN_VPD_WLO, DimmType::CDIMM, ALL_VZ, MBVPD_KEYWORD_MR, 49, UINT8_BY2 | HIGH_NIBBLE, 0},

    {fapi2::ATTR_CEN_VPD_GPO, DimmType::CDIMM, VZ_10, MBVPD_KEYWORD_MT, 61, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_GPO, DimmType::CDIMM, ALL_VZ, MBVPD_KEYWORD_MR, 50, UINT8_BY2, 0},

//----------------------------------------------------------------------------------
// Base Term Data definitions to be used if no other version exceptions
// All entries to be ALL_DIMM ALL_VER
// Note: No changes are expected in this section
//----------------------------------------------------------------------------------
// Base Term Data definitions to be used if no version exceptions
    {fapi2::ATTR_CEN_VPD_DRAM_RON, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MT, 0, UINT8_BY2_BY2 | XLATE_DRAM_RON, 0},
    {fapi2::ATTR_CEN_VPD_DRAM_RTT_NOM, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MT, 2, UINT8_BY2_BY2_BY4 | XLATE_RTT_NOM, 0},
    {fapi2::ATTR_CEN_VPD_DRAM_RTT_WR, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MT, 10, UINT8_BY2_BY2_BY4 | XLATE_RTT_WR, 0},
    {fapi2::ATTR_CEN_VPD_ODT_RD, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MT, 18, UINT8_BY2_BY2_BY4, 0},
    {fapi2::ATTR_CEN_VPD_ODT_WR, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MT, 26, UINT8_BY2_BY2_BY4, 0},
    {fapi2::ATTR_CEN_VPD_DIMM_RCD_OUTPUT_TIMING, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MT, 36, UINT8_BY2_BY2 | DEFAULT_VALUE, 0},
    {fapi2::ATTR_CEN_VPD_DIMM_RCD_IBT, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MT, 34, UINT32_BY2_BY2 | DEFAULT_VALUE, 0},
    {fapi2::ATTR_CEN_VPD_RD_VREF, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MT, 37, UINT32_BY2 | UINT8_DATA | XLATE_RD_VREF, 0},
    {fapi2::ATTR_CEN_VPD_DRAM_WR_VREF, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MT, 38, UINT32_BY2 | XLATE_WR_VREF, 0},
    {fapi2::ATTR_CEN_VPD_DRAM_WRDDR4_VREF, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MT, 42, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_RCV_IMP_DQ_DQS, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MT, 43, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_DRV_IMP_DQ_DQS, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MT, 44, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_DRV_IMP_CNTL, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MT, 45, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_DRV_IMP_ADDR, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MT, 46, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_DRV_IMP_CLK, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MT, 47, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_DRV_IMP_SPCKE, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MT, 48, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_SLEW_RATE_DQ_DQS, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MT, 49, UINT8_BY2 | XLATE_SLEW, 0},
    {fapi2::ATTR_CEN_VPD_SLEW_RATE_CNTL, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MT, 50, UINT8_BY2 | XLATE_SLEW, 0},
    {fapi2::ATTR_CEN_VPD_SLEW_RATE_ADDR, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MT, 51, UINT8_BY2 | XLATE_SLEW, 0},
    {fapi2::ATTR_CEN_VPD_SLEW_RATE_CLK, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MT, 52, UINT8_BY2 | XLATE_SLEW, 0},
    {fapi2::ATTR_CEN_VPD_SLEW_RATE_SPCKE, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MT, 53, UINT8_BY2 | XLATE_SLEW, 0},
    {fapi2::ATTR_CEN_VPD_CKE_PRI_MAP, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MT, 54, UINT32_BY2 | UINT16_DATA, 0},
    {fapi2::ATTR_CEN_VPD_CKE_PWR_MAP, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MT, 56, UINT64 | MERGE, 0},
    {fapi2::ATTR_CEN_VPD_RLO, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MT, 60, UINT8_BY2 | LOW_NIBBLE, 0},
    {fapi2::ATTR_CEN_VPD_WLO, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MT, 60, UINT8_BY2 | HIGH_NIBBLE, 0},
    {fapi2::ATTR_CEN_VPD_GPO, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MT, 61, UINT8_BY2, 0},

// Base Phase Rotator definitions to be used if no version exceptions
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CLK_P0, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 0, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CLK_P1, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 1, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CLK_P0, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 2, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CLK_P1, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 3, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A0, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 4, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A1, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 5, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A2, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 6, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A3, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 7, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A4, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 8, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A5, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 9, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A6, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 10, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A7, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 11, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A8, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 12, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A9, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 13, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A10, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 14, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A11, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 15, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A12, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 16, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A13, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 17, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A14, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 18, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_A15, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 19, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_BA0, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 20, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_BA1, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 21, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_BA2, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 22, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_CASN, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 23, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_RASN, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 24, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M_CMD_WEN, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 25, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M_PAR, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 26, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M_ACTN, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 27, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE0, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 28, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE1, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 29, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE2, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 30, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CKE3, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 31, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN0, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 32, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN1, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 33, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN2, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 34, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_CSN3, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 35, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_ODT0, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 36, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M0_CNTL_ODT1, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 37, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE0, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 38, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE1, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 39, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE2, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 40, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CKE3, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 41, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN0, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 42, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN1, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 43, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN2, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 44, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_CSN3, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 45, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_ODT0, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 46, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_PHASE_ROT_M1_CNTL_ODT1, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 47, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_DRAM_2N_MODE_ENABLED, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 48, UINT8_BY2, 0},
    {fapi2::ATTR_CEN_VPD_TSYS_ADR, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 49, UINT8_BY2 | PORT00, 0},
    {fapi2::ATTR_CEN_VPD_TSYS_DP18, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 49, UINT8_BY2 | PORT11, 0},

// Membuf-level data that is stored within MR
    {fapi2::ATTR_CEN_VPD_POWER_CONTROL_CAPABLE, DimmType::ALL_DIMM, ALL_VER, MBVPD_KEYWORD_MR, 253, UINT8, 0},
};

const uint32_t g_MBVPD_ATTR_DEF_array_size =
    sizeof(g_MBVPD_ATTR_DEF_array) /
    sizeof(MBvpdAttrDef);

}   // namespace getAttrData
}   // namespace fapi2
