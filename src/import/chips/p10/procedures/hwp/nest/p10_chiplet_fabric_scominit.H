/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_chiplet_fabric_scominit.H $ */
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
/// @file p10_chiplet_fabric_scominit.H
/// @brief Apply fabric scom inits to prepare for xlink enablement
///
/// *HWP HW Maintainer: Jenny Huynh <jhuynh@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB
///

#ifndef _P10_CHIPLET_FABRIC_SCOMINIT_H_
#define _P10_CHIPLET_FABRIC_SCOMINIT_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------
const uint64_t PB_EQ0_MODE_REG                      = 0x301100Aull;
const uint64_t PB_CFG_HOP_MODE                      = 4;
const uint64_t PB_CFG_HOP_MODE_LEN                  = 1;
const uint64_t PB_CFG_PUMP_MODE                     = 5;
const uint64_t PB_CFG_PUMP_MODE_LEN                 = 1;
const uint64_t PB_CFG_SP_HW_MARK                    = 16;
const uint64_t PB_CFG_SP_HW_MARK_LEN                = 7;
const uint64_t PB_CFG_GP_HW_MARK                    = 23;
const uint64_t PB_CFG_GP_HW_MARK_LEN                = 7;
const uint64_t PB_CFG_TMGR_MAX_SLBI_TOKENS          = 59;
const uint64_t PB_CFG_TMGR_MAX_SLBI_TOKENS_LEN      = 4;
const uint64_t PB_CFG_TMGR_MAX_TLBI_TOKENS          = 55;
const uint64_t PB_CFG_TMGR_MAX_TLBI_TOKENS_LEN      = 4;
const uint64_t PB_CFG_TMGR_OP2_OVERLAP_DISABLE      = 52;
const uint64_t PB_CFG_TMGR_OP2_OVERLAP_DISABLE_LEN  = 1;
const uint64_t PB_CFG_TMGR_SERIES_ID_DISABLE        = 53;
const uint64_t PB_CFG_TMGR_SERIES_ID_DISABLE_LEN    = 1;
const uint64_t PB_CFG_TMGR_TOKEN_ID_RANGE           = 54;
const uint64_t PB_CFG_TMGR_TOKEN_ID_RANGE_LEN       = 1;

const uint64_t PB_EQ0_STATION_CFG1_REG              = 0x3011013ull;
const uint64_t PB_ES4_STATION_CFG1_REG              = 0x30113D3ull; //ax01
const uint64_t PB_EN4_STATION_CFG1_REG              = 0x30112D3ull; //ax23
const uint64_t PB_ES1_STATION_CFG1_REG              = 0x3011313ull; //ax45
const uint64_t PB_EN1_STATION_CFG1_REG              = 0x3011213ull; //ax67
const uint64_t PB_CFG_OC_EXPIRATION_TIME                 = 6;
const uint64_t PB_CFG_OC_EXPIRATION_TIME_LEN             = 6;
const uint64_t PB_CFG_DAT_LINK0_DON_PTL_VCINIT           = 32; //ax0246
const uint64_t PB_CFG_DAT_LINK0_DON_PTL_VCINIT_LEN       = 2;
const uint64_t PB_CFG_DAT_LINK1_DON_PTL_VCINIT           = 34; //ax1357
const uint64_t PB_CFG_DAT_LINK1_DON_PTL_VCINIT_LEN       = 2;
const uint64_t PB_CFG_DAT_LINK0_OUTBOUND_QUEUE_LIMIT     = 12; //ax0246
const uint64_t PB_CFG_DAT_LINK0_OUTBOUND_QUEUE_LIMIT_LEN = 5;
const uint64_t PB_CFG_DAT_LINK1_OUTBOUND_QUEUE_LIMIT     = 17; //ax1357
const uint64_t PB_CFG_DAT_LINK1_OUTBOUND_QUEUE_LIMIT_LEN = 5;
const uint64_t PB_CFG_DAT_LINK0_OUTBOUND_QUEUE_MAX       = 28; //ax0246
const uint64_t PB_CFG_DAT_LINK0_OUTBOUND_QUEUE_MAX_LEN   = 4;
const uint64_t PB_CFG_DAT_LINK1_OUTBOUND_QUEUE_MAX       = 60; //ax1357
const uint64_t PB_CFG_DAT_LINK1_OUTBOUND_QUEUE_MAX_LEN   = 4;
const uint64_t PB_CFG_DAT_LINK0_OUTBOUND_QUEUE_MIN       = 24; //ax0246
const uint64_t PB_CFG_DAT_LINK0_OUTBOUND_QUEUE_MIN_LEN   = 4;
const uint64_t PB_CFG_DAT_LINK1_OUTBOUND_QUEUE_MIN       = 56; //ax1357
const uint64_t PB_CFG_DAT_LINK1_OUTBOUND_QUEUE_MIN_LEN   = 4;
const uint64_t ENUM_DON_32_0                             = 0x0;

const uint64_t PB_ES4_STATION_CFG2_REG              = 0x30113D4ull; //ax01
const uint64_t PB_EN4_STATION_CFG2_REG              = 0x30112D4ull; //ax23
const uint64_t PB_ES1_STATION_CFG2_REG              = 0x3011314ull; //ax45
const uint64_t PB_EN1_STATION_CFG2_REG              = 0x3011214ull; //ax67
const uint64_t PB_CFG_DAT_LINK0_DOB_VC0_LIMIT       = 24; //ax0246
const uint64_t PB_CFG_DAT_LINK0_DOB_VC0_LIMIT_LEN   = 7;
const uint64_t PB_CFG_DAT_LINK0_DOB_VC1_LIMIT       = 31;
const uint64_t PB_CFG_DAT_LINK0_DOB_VC1_LIMIT_LEN   = 7;
const uint64_t PB_CFG_DAT_LINK1_DOB_VC0_LIMIT       = 38; //ax1357
const uint64_t PB_CFG_DAT_LINK1_DOB_VC0_LIMIT_LEN   = 7;
const uint64_t PB_CFG_DAT_LINK1_DOB_VC1_LIMIT       = 45;
const uint64_t PB_CFG_DAT_LINK1_DOB_VC1_LIMIT_LEN   = 7;

const uint64_t PB_EQ0_STATION_CFG3_REG              = 0x3011015ull;
const uint64_t PB_CFG_CHIP_TSNOOP_DELAY             = 0;
const uint64_t PB_CFG_CHIP_TSNOOP_DELAY_LEN         = 4;

const uint64_t PB_EQ0_SNOOPER_CFG1_REG              = 0x3011016ull;
const uint64_t PB_CFG_CHG_RATE_GP_CRESP_SAMPLE_TIME     = 0;
const uint64_t PB_CFG_CHG_RATE_GP_CRESP_SAMPLE_TIME_LEN = 12;
const uint64_t PB_CFG_CHG_RATE_GP_JUMP                  = 48;
const uint64_t PB_CFG_CHG_RATE_GP_JUMP_LEN              = 3;
const uint64_t PB_CFG_CHG_RATE_GP_REQ_SAMPLE_TIME       = 24;
const uint64_t PB_CFG_CHG_RATE_GP_REQ_SAMPLE_TIME_LEN   = 12;
const uint64_t PB_CFG_CHG_RATE_SP_CRESP_SAMPLE_TIME     = 12;
const uint64_t PB_CFG_CHG_RATE_SP_CRESP_SAMPLE_TIME_LEN = 12;
const uint64_t PB_CFG_CHG_RATE_SP_JUMP                  = 51;
const uint64_t PB_CFG_CHG_RATE_SP_JUMP_LEN              = 3;
const uint64_t PB_CFG_CHG_RATE_SP_REQ_SAMPLE_TIME       = 36;
const uint64_t PB_CFG_CHG_RATE_SP_REQ_SAMPLE_TIME_LEN   = 12;

const uint64_t PB_EQ0_SNOOPER_CFG2_REG              = 0x3011017ull;
const uint64_t PB_CFG_CHG_RATE_GP_RTY_THRESHOLD     = 0;
const uint64_t PB_CFG_CHG_RATE_GP_RTY_THRESHOLD_LEN = 10;
const uint64_t PB_CFG_CHG_RATE_SP_RTY_THRESHOLD     = 10;
const uint64_t PB_CFG_CHG_RATE_SP_RTY_THRESHOLD_LEN = 10;
const uint64_t PB_CFG_CPO_JUMP_LEVEL                = 20;
const uint64_t PB_CFG_CPO_JUMP_LEVEL_LEN            = 3;
const uint64_t PB_CFG_CPO_RTY_LEVEL                 = 23;
const uint64_t PB_CFG_CPO_RTY_LEVEL_LEN             = 6;

const uint64_t PB_EQ0_SNOOPER_CFG3_REG              = 0x3011018ull;
const uint64_t PB_CFG_GP_LVL0_CHGRATE_CLK_DIV       = 0;
const uint64_t PB_CFG_GP_LVL1_CHGRATE_CLK_DIV       = 3;
const uint64_t PB_CFG_GP_LVL2_CHGRATE_CLK_DIV       = 6;
const uint64_t PB_CFG_GP_LVL3_CHGRATE_CLK_DIV       = 9;
const uint64_t PB_CFG_GP_LVL4_CHGRATE_CLK_DIV       = 12;
const uint64_t PB_CFG_GP_LVL5_CHGRATE_CLK_DIV       = 15;
const uint64_t PB_CFG_GP_LVL6_CHGRATE_CLK_DIV       = 18;
const uint64_t PB_CFG_GP_LVL7_CHGRATE_CLK_DIV       = 21;
const uint64_t PB_CFG_GP_LVL_CHGRATE_CLK_DIV_LEN    = 3;
const uint64_t PB_CFG_SP_LVL0_CHGRATE_CLK_DIV       = 24;
const uint64_t PB_CFG_SP_LVL1_CHGRATE_CLK_DIV       = 27;
const uint64_t PB_CFG_SP_LVL2_CHGRATE_CLK_DIV       = 30;
const uint64_t PB_CFG_SP_LVL3_CHGRATE_CLK_DIV       = 33;
const uint64_t PB_CFG_SP_LVL4_CHGRATE_CLK_DIV       = 36;
const uint64_t PB_CFG_SP_LVL5_CHGRATE_CLK_DIV       = 39;
const uint64_t PB_CFG_SP_LVL6_CHGRATE_CLK_DIV       = 42;
const uint64_t PB_CFG_SP_LVL7_CHGRATE_CLK_DIV       = 45;
const uint64_t PB_CFG_SP_LVL_CHGRATE_CLK_DIV_LEN    = 3;

const uint64_t PB_EQ0_SNOOPER_CFG4_REG              = 0x3011019ull;
const uint64_t PB_CFG_HANG0_CMD_RATE                = 0;
const uint64_t PB_CFG_HANG1_CMD_RATE                = 5;
const uint64_t PB_CFG_HANG2_CMD_RATE                = 10;
const uint64_t PB_CFG_HANG3_CMD_RATE                = 15;
const uint64_t PB_CFG_HANG4_CMD_RATE                = 20;
const uint64_t PB_CFG_HANG5_CMD_RATE                = 25;
const uint64_t PB_CFG_HANG6_CMD_RATE                = 30;
const uint64_t PB_CFG_HANG_CMD_RATE_LEN             = 5;
const uint64_t PB_CFG_USE_SLOW_GO_RATE              = 35;
const uint64_t PB_CFG_USE_SLOW_GO_RATE_LEN          = 1;

const uint64_t PB_EQ0_GP_CMD_RATE_REG               = 0x301101Aull;
const uint64_t PB_CFG_G_CMD_RATE_LVL0               = 0;
const uint64_t PB_CFG_G_CMD_RATE_LVL1               = 8;
const uint64_t PB_CFG_G_CMD_RATE_LVL2               = 16;
const uint64_t PB_CFG_G_CMD_RATE_LVL3               = 24;
const uint64_t PB_CFG_G_CMD_RATE_LVL4               = 32;
const uint64_t PB_CFG_G_CMD_RATE_LVL5               = 40;
const uint64_t PB_CFG_G_CMD_RATE_LVL6               = 48;
const uint64_t PB_CFG_G_CMD_RATE_LVL7               = 56;
const uint64_t PB_CFG_G_CMD_RATE_LVL_LEN            = 8;

const uint64_t PB_EQ0_SP_CMD_RATE_REG               = 0x301101Bull;
const uint64_t PB_CFG_R_CMD_RATE_LVL0               = 0;
const uint64_t PB_CFG_R_CMD_RATE_LVL1               = 8;
const uint64_t PB_CFG_R_CMD_RATE_LVL2               = 16;
const uint64_t PB_CFG_R_CMD_RATE_LVL3               = 24;
const uint64_t PB_CFG_R_CMD_RATE_LVL4               = 32;
const uint64_t PB_CFG_R_CMD_RATE_LVL5               = 40;
const uint64_t PB_CFG_R_CMD_RATE_LVL6               = 48;
const uint64_t PB_CFG_R_CMD_RATE_LVL7               = 56;
const uint64_t PB_CFG_R_CMD_RATE_LVL_LEN            = 8;

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

typedef fapi2::ReturnCode (*p10_chiplet_fabric_scominit_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&);

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

/// @brief Apply fabric scom inits
///
/// @param[in] i_target         Reference to processor chip target
/// @return fapi2::ReturnCode   FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p10_chiplet_fabric_scominit(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

} // extern "C"

#endif // _P10_CHIPLET_FABRIC_SCOMINIT_H_
