/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_build_smp_fbc_ab.H $ */
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
/// @file p10_build_smp_fbc_ab.H
/// @brief Fabric configuration (hotplug, AB) functions.
///
/// *HWP HW Maintainer: Jenny Huynh <jhuynh@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB, FSP
///

#ifndef _P10_BUILD_SMP_FBC_AB_H_
#define _P10_BUILD_SMP_FBC_AB_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_build_smp.H>

//------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------

// @TODO FIXME HW468835 temporarily set scoms manually until figtree is updated
const uint64_t PB_EQ0_HP_MODE1_NEXT_REG             = 0x0301100Bull;
const uint64_t PB_EQ0_HP_MODE1_CURR_REG             = 0x0301100Cull;
const uint64_t PB_CFG_MASTER_CHIP_NEXT              = 0;
const uint64_t PB_CFG_MASTER_CHIP_NEXT_LEN          = 1;
const uint64_t PB_CFG_TM_MASTER_NEXT                = 1;
const uint64_t PB_CFG_TM_MASTER_NEXT_LEN            = 1;
const uint64_t PB_CFG_CHG_RATE_GP_MASTER_NEXT       = 2;
const uint64_t PB_CFG_CHG_RATE_GP_MASTER_NEXT_LEN   = 1;
const uint64_t PB_CFG_CHG_RATE_SP_MASTER_NEXT       = 3;
const uint64_t PB_CFG_CHG_RATE_SP_MASTER_NEXT_LEN   = 1;
const uint64_t PB_CFG_G_AGGREGATE_NEXT              = 16;
const uint64_t PB_CFG_G_AGGREGATE_NEXT_LEN          = 1;
const uint64_t PB_CFG_R_AGGREGATE_NEXT              = 32;
const uint64_t PB_CFG_R_AGGREGATE_NEXT_LEN          = 1;
const uint64_t PB_CFG_NP_CMD_RATE_NEXT              = 8;
const uint64_t PB_CFG_NP_CMD_RATE_NEXT_LEN          = 8;
const uint64_t PB_CFG_MIN_G_CMD_RATE_NEXT           = 24;
const uint64_t PB_CFG_MIN_G_CMD_RATE_NEXT_LEN       = 8;
const uint64_t PB_CFG_MIN_R_CMD_RATE_NEXT           = 40;
const uint64_t PB_CFG_MIN_R_CMD_RATE_NEXT_LEN       = 8;

const uint64_t PB_EQ0_HP_MODE2_NEXT_REG             = 0x0301100Dull;
const uint64_t PB_EQ0_HP_MODE2_CURR_REG             = 0x0301100Eull;
const uint64_t PB_CFG_LINK_AX_EN_NEXT_LEN           = 1;
const uint64_t PB_CFG_LINK_AX_ADDR_DIS_NEXT_LEN     = 1;
const uint64_t PB_CFG_LINK_AX_MODE_NEXT_LEN         = 1;
const uint64_t PB_CFG_LINK_AX_ID_NEXT_LEN           = 3;
const uint64_t PB_CFG_LINK_AX0_EN_NEXT              = 0;
const uint64_t PB_CFG_LINK_AX1_EN_NEXT              = 1;
const uint64_t PB_CFG_LINK_AX2_EN_NEXT              = 2;
const uint64_t PB_CFG_LINK_AX3_EN_NEXT              = 3;
const uint64_t PB_CFG_LINK_AX4_EN_NEXT              = 4;
const uint64_t PB_CFG_LINK_AX5_EN_NEXT              = 5;
const uint64_t PB_CFG_LINK_AX6_EN_NEXT              = 6;
const uint64_t PB_CFG_LINK_AX7_EN_NEXT              = 7;
const uint64_t PB_CFG_LINK_AX0_ADDR_DIS_NEXT        = 8;
const uint64_t PB_CFG_LINK_AX1_ADDR_DIS_NEXT        = 9;
const uint64_t PB_CFG_LINK_AX2_ADDR_DIS_NEXT        = 10;
const uint64_t PB_CFG_LINK_AX3_ADDR_DIS_NEXT        = 11;
const uint64_t PB_CFG_LINK_AX4_ADDR_DIS_NEXT        = 12;
const uint64_t PB_CFG_LINK_AX5_ADDR_DIS_NEXT        = 13;
const uint64_t PB_CFG_LINK_AX6_ADDR_DIS_NEXT        = 14;
const uint64_t PB_CFG_LINK_AX7_ADDR_DIS_NEXT        = 15;
const uint64_t PB_CFG_LINK_AX0_MODE_NEXT            = 16;
const uint64_t PB_CFG_LINK_AX1_MODE_NEXT            = 20;
const uint64_t PB_CFG_LINK_AX2_MODE_NEXT            = 24;
const uint64_t PB_CFG_LINK_AX3_MODE_NEXT            = 28;
const uint64_t PB_CFG_LINK_AX4_MODE_NEXT            = 32;
const uint64_t PB_CFG_LINK_AX5_MODE_NEXT            = 36;
const uint64_t PB_CFG_LINK_AX6_MODE_NEXT            = 40;
const uint64_t PB_CFG_LINK_AX7_MODE_NEXT            = 44;
const uint64_t PB_CFG_LINK_AX0_ID_NEXT              = 17;
const uint64_t PB_CFG_LINK_AX1_ID_NEXT              = 21;
const uint64_t PB_CFG_LINK_AX2_ID_NEXT              = 25;
const uint64_t PB_CFG_LINK_AX3_ID_NEXT              = 29;
const uint64_t PB_CFG_LINK_AX4_ID_NEXT              = 33;
const uint64_t PB_CFG_LINK_AX5_ID_NEXT              = 37;
const uint64_t PB_CFG_LINK_AX6_ID_NEXT              = 41;
const uint64_t PB_CFG_LINK_AX7_ID_NEXT              = 45;

const uint64_t PB_EQ0_HP_MODE3_NEXT_REG             = 0x0301100Full;
const uint64_t PB_EQ0_HP_MODE3_CURR_REG             = 0x03011010ull;
const uint64_t PB_CFG_TID_ENTRY_VALID_NEXT_LEN      = 1;
const uint64_t PB_CFG_TID_ENTRY_AX_NUM_NEXT_LEN     = 3;
const uint64_t PB_CFG_TID_ENTRY0_VALID_NEXT         = 0;
const uint64_t PB_CFG_TID_ENTRY1_VALID_NEXT         = 1;
const uint64_t PB_CFG_TID_ENTRY2_VALID_NEXT         = 2;
const uint64_t PB_CFG_TID_ENTRY3_VALID_NEXT         = 3;
const uint64_t PB_CFG_TID_ENTRY4_VALID_NEXT         = 4;
const uint64_t PB_CFG_TID_ENTRY5_VALID_NEXT         = 5;
const uint64_t PB_CFG_TID_ENTRY6_VALID_NEXT         = 6;
const uint64_t PB_CFG_TID_ENTRY7_VALID_NEXT         = 7;
const uint64_t PB_CFG_TID_ENTRY8_VALID_NEXT         = 8;
const uint64_t PB_CFG_TID_ENTRY9_VALID_NEXT         = 9;
const uint64_t PB_CFG_TID_ENTRY10_VALID_NEXT        = 10;
const uint64_t PB_CFG_TID_ENTRY11_VALID_NEXT        = 11;
const uint64_t PB_CFG_TID_ENTRY12_VALID_NEXT        = 12;
const uint64_t PB_CFG_TID_ENTRY13_VALID_NEXT        = 13;
const uint64_t PB_CFG_TID_ENTRY14_VALID_NEXT        = 14;
const uint64_t PB_CFG_TID_ENTRY15_VALID_NEXT        = 15;
const uint64_t PB_CFG_TID_ENTRY0_AX_NUM_NEXT        = 16;
const uint64_t PB_CFG_TID_ENTRY1_AX_NUM_NEXT        = 19;
const uint64_t PB_CFG_TID_ENTRY2_AX_NUM_NEXT        = 22;
const uint64_t PB_CFG_TID_ENTRY3_AX_NUM_NEXT        = 25;
const uint64_t PB_CFG_TID_ENTRY4_AX_NUM_NEXT        = 28;
const uint64_t PB_CFG_TID_ENTRY5_AX_NUM_NEXT        = 31;
const uint64_t PB_CFG_TID_ENTRY6_AX_NUM_NEXT        = 34;
const uint64_t PB_CFG_TID_ENTRY7_AX_NUM_NEXT        = 37;
const uint64_t PB_CFG_TID_ENTRY8_AX_NUM_NEXT        = 40;
const uint64_t PB_CFG_TID_ENTRY9_AX_NUM_NEXT        = 43;
const uint64_t PB_CFG_TID_ENTRY10_AX_NUM_NEXT       = 46;
const uint64_t PB_CFG_TID_ENTRY11_AX_NUM_NEXT       = 49;
const uint64_t PB_CFG_TID_ENTRY12_AX_NUM_NEXT       = 52;
const uint64_t PB_CFG_TID_ENTRY13_AX_NUM_NEXT       = 55;
const uint64_t PB_CFG_TID_ENTRY14_AX_NUM_NEXT       = 58;
const uint64_t PB_CFG_TID_ENTRY15_AX_NUM_NEXT       = 61;

const uint64_t PB_EQ0_HP_MODE4_NEXT_REG             = 0x03011011ull;
const uint64_t PB_EQ0_HP_MODE4_CURR_REG             = 0x03011012ull;
const uint64_t PB_CFG_TID_ENTRY16_VALID_NEXT        = 0;
const uint64_t PB_CFG_TID_ENTRY17_VALID_NEXT        = 1;
const uint64_t PB_CFG_TID_ENTRY18_VALID_NEXT        = 2;
const uint64_t PB_CFG_TID_ENTRY19_VALID_NEXT        = 3;
const uint64_t PB_CFG_TID_ENTRY20_VALID_NEXT        = 4;
const uint64_t PB_CFG_TID_ENTRY21_VALID_NEXT        = 5;
const uint64_t PB_CFG_TID_ENTRY22_VALID_NEXT        = 6;
const uint64_t PB_CFG_TID_ENTRY23_VALID_NEXT        = 7;
const uint64_t PB_CFG_TID_ENTRY24_VALID_NEXT        = 8;
const uint64_t PB_CFG_TID_ENTRY25_VALID_NEXT        = 9;
const uint64_t PB_CFG_TID_ENTRY26_VALID_NEXT        = 10;
const uint64_t PB_CFG_TID_ENTRY27_VALID_NEXT        = 11;
const uint64_t PB_CFG_TID_ENTRY28_VALID_NEXT        = 12;
const uint64_t PB_CFG_TID_ENTRY29_VALID_NEXT        = 13;
const uint64_t PB_CFG_TID_ENTRY30_VALID_NEXT        = 14;
const uint64_t PB_CFG_TID_ENTRY31_VALID_NEXT        = 15;
const uint64_t PB_CFG_TID_ENTRY16_AX_NUM_NEXT       = 16;
const uint64_t PB_CFG_TID_ENTRY17_AX_NUM_NEXT       = 19;
const uint64_t PB_CFG_TID_ENTRY18_AX_NUM_NEXT       = 22;
const uint64_t PB_CFG_TID_ENTRY19_AX_NUM_NEXT       = 25;
const uint64_t PB_CFG_TID_ENTRY20_AX_NUM_NEXT       = 28;
const uint64_t PB_CFG_TID_ENTRY21_AX_NUM_NEXT       = 31;
const uint64_t PB_CFG_TID_ENTRY22_AX_NUM_NEXT       = 34;
const uint64_t PB_CFG_TID_ENTRY23_AX_NUM_NEXT       = 37;
const uint64_t PB_CFG_TID_ENTRY24_AX_NUM_NEXT       = 40;
const uint64_t PB_CFG_TID_ENTRY25_AX_NUM_NEXT       = 43;
const uint64_t PB_CFG_TID_ENTRY26_AX_NUM_NEXT       = 46;
const uint64_t PB_CFG_TID_ENTRY27_AX_NUM_NEXT       = 49;
const uint64_t PB_CFG_TID_ENTRY28_AX_NUM_NEXT       = 52;
const uint64_t PB_CFG_TID_ENTRY29_AX_NUM_NEXT       = 55;
const uint64_t PB_CFG_TID_ENTRY30_AX_NUM_NEXT       = 58;
const uint64_t PB_CFG_TID_ENTRY31_AX_NUM_NEXT       = 61;

const uint64_t ENUM_OFF                             = 0;
const uint64_t ENUM_ON                              = 1;
const uint64_t ENUM_RBUS                            = 1;

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

///
/// @brief Program fabric configuration register (hotplug, A/B set)
///
/// @param[in] i_smp    Structure encapsulating SMP topology
/// @param[in] i_op     Enumerated type representing SMP build phase
///
/// @return fapi2::ReturnCode  FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p10_build_smp_set_fbc_ab(
        p10_build_smp_system& i_smp,
        const p10_build_smp_operation i_op);

} // extern "C"

#endif // _P10_BUILD_SMP_FBC_AB_H_
