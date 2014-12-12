/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/activate_powerbus/proc_build_smp/proc_build_smp_fbc_cd.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
// $Id: proc_build_smp_fbc_cd.C,v 1.17 2014/11/16 23:23:37 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_build_smp_fbc_cd.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *|
// *! TITLE       : proc_build_smp_fbc_cd.C
// *! DESCRIPTION : Fabric configuration (hotplug, CD) functions (FAPI)
// *!
// *! OWNER NAME  : Joe McGill    Email: jmcgill@us.ibm.com
// *!
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <proc_build_smp_fbc_cd.H>
#include <proc_build_smp_adu.H>

extern "C" {


//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// structure encapsulating serial configuration load programming
struct proc_build_smp_sconfig_def
{
    uint8_t select;                               // ID/select for chain
    uint8_t length;                               // number of bits to load
    bool use_slow_clock;                          // use 16:1 slow clock? (EX)
    bool use_shadow[PROC_BUILD_SMP_NUM_SHADOWS];  // define which shadows to set
};


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

//
// PB Serial Configuration Load register field/bit definitions
//

// hang level constants
const uint8_t PB_SCONFIG_NUM_HANG_LEVELS = 7;

// CPU ratio constants
const uint8_t PB_SCONFIG_NUM_CPU_RATIOS = 4;


const uint32_t PB_SCONFIG_LOAD[PROC_BUILD_SMP_NUM_SHADOWS] =
{
    PB_SCONFIG_LOAD_WEST_0x02010C16,
    PB_SCONFIG_LOAD_CENT_0x02010C6D,
    PB_SCONFIG_LOAD_EAST_0x02010C96
};

const uint32_t PB_SCONFIG_LOAD_START_BIT = 0;
const uint32_t PB_SCONFIG_LOAD_SLOW_BIT = 1;
const uint32_t PB_SCONFIG_SHIFT_COUNT_START_BIT = 2;
const uint32_t PB_SCONFIG_SHIFT_COUNT_END_BIT = 7;
const uint32_t PB_SCONFIG_SELECT_START_BIT = 8;
const uint32_t PB_SCONFIG_SELECT_END_BIT = 11;
const uint32_t PB_SCONFIG_SHIFT_DATA_START_BIT = 12;
const uint32_t PB_SCONFIG_SHIFT_DATA_END_BIT = 63;


//
// PBH_CMD_SNOOPER (center, chain #4) field/bit definitions
//

const proc_build_smp_sconfig_def PB_SCONFIG_C4_DEF = { 0x4, 50, false, { false, true, false} };

const uint32_t PB_SCONFIG_C4_GP_LO_RTY_THRESHOLD_START_BIT = 14;
const uint32_t PB_SCONFIG_C4_GP_LO_RTY_THRESHOLD_END_BIT = 23;
const uint32_t PB_SCONFIG_C4_GP_HI_RTY_THRESHOLD_START_BIT = 24;
const uint32_t PB_SCONFIG_C4_GP_HI_RTY_THRESHOLD_END_BIT = 33;
const uint32_t PB_SCONFIG_C4_RGP_LO_RTY_THRESHOLD_START_BIT = 34;
const uint32_t PB_SCONFIG_C4_RGP_LO_RTY_THRESHOLD_END_BIT = 43;
const uint32_t PB_SCONFIG_C4_RGP_HI_RTY_THRESHOLD_START_BIT = 44;
const uint32_t PB_SCONFIG_C4_RGP_HI_RTY_THRESHOLD_END_BIT = 53;
const uint32_t PB_SCONFIG_C4_SP_LO_RTY_THRESHOLD_START_BIT = 54;
const uint32_t PB_SCONFIG_C4_SP_LO_RTY_THRESHOLD_END_BIT = 63;

const uint32_t PB_SCONFIG_C4_GP_LO_RTY_THRESHOLD = 0x7;
const uint32_t PB_SCONFIG_C4_GP_HI_RTY_THRESHOLD = 0x5;
const uint32_t PB_SCONFIG_C4_RGP_LO_RTY_THRESHOLD = 0x5;
const uint32_t PB_SCONFIG_C4_RGP_HI_RTY_THRESHOLD = 0x4;
const uint32_t PB_SCONFIG_C4_SP_LO_RTY_THRESHOLD = 0x5;


//
// PBH_CMD_SNOOPER (center, chain #5) field/bit definitions
//

const proc_build_smp_sconfig_def PB_SCONFIG_C5_DEF = { 0x5, 46, false, { false, true, false} };

const uint32_t PB_SCONFIG_C5_SP_HI_RTY_THRESHOLD_START_BIT = 18;
const uint32_t PB_SCONFIG_C5_SP_HI_RTY_THRESHOLD_END_BIT = 27;
const uint32_t PB_SCONFIG_C5_GP_CRESP_SAMPLE_TIME_START_BIT = 28;
const uint32_t PB_SCONFIG_C5_GP_CRESP_SAMPLE_TIME_END_BIT = 39;
const uint32_t PB_SCONFIG_C5_RGP_CRESP_SAMPLE_TIME_START_BIT = 40;
const uint32_t PB_SCONFIG_C5_RGP_CRESP_SAMPLE_TIME_END_BIT = 51;
const uint32_t PB_SCONFIG_C5_SP_CRESP_SAMPLE_TIME_START_BIT = 52;
const uint32_t PB_SCONFIG_C5_SP_CRESP_SAMPLE_TIME_END_BIT = 63;

const uint32_t PB_SCONFIG_C5_SP_HI_RTY_THRESHOLD = 0x4;
const uint32_t PB_SCONFIG_C5_GP_CRESP_SAMPLE_TIME = 321;
const uint32_t PB_SCONFIG_C5_RGP_CRESP_SAMPLE_TIME = 539;
const uint32_t PB_SCONFIG_C5_SP_CRESP_SAMPLE_TIME = 781;


//
// PBH_CMD_SNOOPER (center, chain #6) field/bit definitions
//

const proc_build_smp_sconfig_def PB_SCONFIG_C6_DEF = { 0x6, 42, false, { false, true, false} };

const uint32_t PB_SCONFIG_C6_GP_REQ_SAMPLE_TIME_START_BIT = 22;
const uint32_t PB_SCONFIG_C6_GP_REQ_SAMPLE_TIME_END_BIT = 33;
const uint32_t PB_SCONFIG_C6_SP_REQ_SAMPLE_TIME_START_BIT = 34;
const uint32_t PB_SCONFIG_C6_SP_REQ_SAMPLE_TIME_END_BIT = 45;
const uint32_t PB_SCONFIG_C6_GP_LO_JUMP_START_BIT = 46;
const uint32_t PB_SCONFIG_C6_GP_LO_JUMP_END_BIT = 48;
const uint32_t PB_SCONFIG_C6_GP_HI_JUMP_START_BIT = 49;
const uint32_t PB_SCONFIG_C6_GP_HI_JUMP_END_BIT = 51;
const uint32_t PB_SCONFIG_C6_SP_LO_JUMP_START_BIT = 52;
const uint32_t PB_SCONFIG_C6_SP_LO_JUMP_END_BIT = 54;
const uint32_t PB_SCONFIG_C6_SP_HI_JUMP_START_BIT = 55;
const uint32_t PB_SCONFIG_C6_SP_HI_JUMP_END_BIT = 57;
const uint32_t PB_SCONFIG_C6_RGP_LO_JUMP_START_BIT = 58;
const uint32_t PB_SCONFIG_C6_RGP_LO_JUMP_END_BIT = 60;
const uint32_t PB_SCONFIG_C6_RGP_HI_JUMP_START_BIT = 61;
const uint32_t PB_SCONFIG_C6_RGP_HI_JUMP_END_BIT = 63;

const uint32_t PB_SCONFIG_C6_GP_REQ_SAMPLE_TIME = 1024;
const uint32_t PB_SCONFIG_C6_SP_REQ_SAMPLE_TIME = 1024;
const uint32_t PB_SCONFIG_C6_GP_LO_JUMP = 0x2;
const uint32_t PB_SCONFIG_C6_GP_HI_JUMP = 0x2;
const uint32_t PB_SCONFIG_C6_SP_LO_JUMP = 0x2;
const uint32_t PB_SCONFIG_C6_SP_HI_JUMP = 0x2;
const uint32_t PB_SCONFIG_C6_RGP_LO_JUMP = 0x2;
const uint32_t PB_SCONFIG_C6_RGP_HI_JUMP = 0x2;


//
// PBH_CMD_SNOOPER (center, chain #7) field/bit definitions
//

const proc_build_smp_sconfig_def PB_SCONFIG_C7_DEF = { 0x7, 36, false, { false, true, false } };

const uint32_t PB_SCONFIG_C7_HANG_CMD_RATE_START_BIT[PB_SCONFIG_NUM_HANG_LEVELS] = { 28, 33, 38, 43, 48, 53, 58 };
const uint32_t PB_SCONFIG_C7_HANG_CMD_RATE_END_BIT[PB_SCONFIG_NUM_HANG_LEVELS]   = { 32, 37, 42, 47, 52, 57, 62 };
const uint32_t PB_SCONFIG_C7_SLOW_GO_RATE_BIT = 63;

// PB_CFG_HANG0_CMD_RATE = 0x00 = 127/128
// PB_CFG_HANG1_CMD_RATE = 0x06 = 1/2
// PB_CFG_HANG2_CMD_RATE = 0x0D = 1/512
// PB_CFG_HANG3_CMD_RATE = 0x00 = 127/128
// PB_CFG_HANG4_CMD_RATE = 0x1E = 1/4096 (toad mode)
// PB_CFG_HANG5_CMD_RATE = 0x19 = 1/8 (toad mode)
// PB_CFG_HANG6_CMD_RATE = 0x00 = 127/128
const uint8_t PB_SCONFIG_C7_HANG_CMD_RATE[PB_SCONFIG_NUM_HANG_LEVELS] = { 0x00, 0x06, 0x0D, 0x00, 0x1E, 0x19, 0x00 };
const bool    PB_SCONFIG_C7_SLOW_GO_RATE = true;


//
// PBH_CMD_SNOOPER (center, chain #8) field/bit definitions
//

const proc_build_smp_sconfig_def PB_SCONFIG_C8_DEF_VER1 = { 0x8, 37, false, { false, true, false } };
const proc_build_smp_sconfig_def PB_SCONFIG_C8_DEF_VER2 = { 0x8, 39, false, { false, true, false } };
const proc_build_smp_sconfig_def PB_SCONFIG_C8_DEF_VER3 = { 0x8, 43, false, { false, true, false } };

const uint32_t PB_SCONFIG_C8_HANG_CMD_RATE_START_BIT_VER1[PB_SCONFIG_NUM_HANG_LEVELS] = { 27, 31, 35, 39, 43, 47, 51 };
const uint32_t PB_SCONFIG_C8_HANG_CMD_RATE_END_BIT_VER1[PB_SCONFIG_NUM_HANG_LEVELS]   = { 30, 34, 38, 42, 46, 50, 54 };
const uint32_t PB_SCONFIG_C8_CPO_JUMP_LEVEL_START_BIT_VER1 = 55;
const uint32_t PB_SCONFIG_C8_CPO_JUMP_LEVEL_END_BIT_VER1 = 57;
const uint32_t PB_SCONFIG_C8_CPO_RTY_LEVEL_START_BIT_VER1 = 58;
const uint32_t PB_SCONFIG_C8_CPO_RTY_LEVEL_END_BIT_VER1 = 63;

const uint32_t PB_SCONFIG_C8_HANG_CMD_RATE_START_BIT_VER2[PB_SCONFIG_NUM_HANG_LEVELS] = { 25, 29, 33, 37, 41, 45, 49 };
const uint32_t PB_SCONFIG_C8_HANG_CMD_RATE_END_BIT_VER2[PB_SCONFIG_NUM_HANG_LEVELS]   = { 28, 32, 36, 40, 44, 48, 52 };
const uint32_t PB_SCONFIG_C8_CPO_JUMP_LEVEL_START_BIT_VER2 = 53;
const uint32_t PB_SCONFIG_C8_CPO_JUMP_LEVEL_END_BIT_VER2 = 55;
const uint32_t PB_SCONFIG_C8_CPO_RTY_LEVEL_START_BIT_VER2 = 56;
const uint32_t PB_SCONFIG_C8_CPO_RTY_LEVEL_END_BIT_VER2 = 61;
const uint32_t PB_SCONFIG_C8_P7_SLEEP_BACKOFF_START_BIT_VER2 = 62;
const uint32_t PB_SCONFIG_C8_P7_SLEEP_BACKOFF_END_BIT_VER2 = 63;

const uint32_t PB_SCONFIG_C8_HANG_CMD_RATE_START_BIT_VER3[PB_SCONFIG_NUM_HANG_LEVELS] = { 21, 25, 29, 33, 37, 41, 45 };
const uint32_t PB_SCONFIG_C8_HANG_CMD_RATE_END_BIT_VER3[PB_SCONFIG_NUM_HANG_LEVELS]   = { 24, 28, 32, 36, 40, 44, 48 };
const uint32_t PB_SCONFIG_C8_CPO_JUMP_LEVEL_START_BIT_VER3 = 49;
const uint32_t PB_SCONFIG_C8_CPO_JUMP_LEVEL_END_BIT_VER3 = 51;
const uint32_t PB_SCONFIG_C8_CPO_RTY_LEVEL_START_BIT_VER3 = 52;
const uint32_t PB_SCONFIG_C8_CPO_RTY_LEVEL_END_BIT_VER3 = 57;
const uint32_t PB_SCONFIG_C8_P7_SLEEP_BACKOFF_START_BIT_VER3 = 58;
const uint32_t PB_SCONFIG_C8_P7_SLEEP_BACKOFF_END_BIT_VER3 = 59;
const uint32_t PB_SCONFIG_C8_RTY_PERCENTAGE_START_BIT_VER3 = 60;
const uint32_t PB_SCONFIG_C8_RTY_PERCENTAGE_END_BIT_VER3 = 62;
const uint32_t PB_SCONFIG_C8_INCLUDE_LPC_RTY_BIT_VER3 = 63;

const uint8_t PB_SCONFIG_C8_HANG_CMD_RATE[PB_SCONFIG_NUM_HANG_LEVELS] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
const uint8_t PB_SCONFIG_C8_CPO_JUMP_LEVEL = 0x7;
const uint8_t PB_SCONFIG_C8_CPO_RTY_LEVEL = 0x4;

const uint8_t PB_SCONFIG_C8_P7_SLEEP_BACKOFF = 0x2; // backoff_1k

const uint8_t PB_SCONFIG_C8_RTY_PERCENTAGE  = 0x0;  // 000
const uint8_t PB_SCONFIG_C8_INCLUDE_LPC_RTY = 0x0;  // off

//
// PBH_CMD_CENTRAL_ARB (center, chain #9) field/bit definitions
//

const proc_build_smp_sconfig_def PB_SCONFIG_C9_DEF = { 0x9, 44, false, { false, true, false } };

const uint32_t PB_SCONFIG_C9_CP_STARVE_LIMIT_START_BIT = 20;
const uint32_t PB_SCONFIG_C9_CP_STARVE_LIMIT_END_BIT = 27;
const uint32_t PB_SCONFIG_C9_GP_STARVE_LIMIT_START_BIT = 28;
const uint32_t PB_SCONFIG_C9_GP_STARVE_LIMIT_END_BIT = 35;
const uint32_t PB_SCONFIG_C9_RGP_STARVE_LIMIT_START_BIT = 36;
const uint32_t PB_SCONFIG_C9_RGP_STARVE_LIMIT_END_BIT = 43;
const uint32_t PB_SCONFIG_C9_SP_STARVE_LIMIT_START_BIT = 44;
const uint32_t PB_SCONFIG_C9_SP_STARVE_LIMIT_END_BIT = 51;
const uint32_t PB_SCONFIG_C9_FP_STARVE_LIMIT_START_BIT = 52;
const uint32_t PB_SCONFIG_C9_FP_STARVE_LIMIT_END_BIT = 59;
const uint32_t PB_SCONFIG_C9_UX_SCOPE_ARB_MODE_START_BIT = 60;
const uint32_t PB_SCONFIG_C9_UX_SCOPE_ARB_MODE_END_BIT = 61;
const uint32_t PB_SCONFIG_C9_UX_LOCAL_ARB_MODE_START_BIT = 62;
const uint32_t PB_SCONFIG_C9_UX_LOCAL_ARB_MODE_END_BIT = 63;

const uint8_t PB_SCONFIG_C9_CP_STARVE_LIMIT  = 0x10;
const uint8_t PB_SCONFIG_C9_GP_STARVE_LIMIT  = 0x10;
const uint8_t PB_SCONFIG_C9_RGP_STARVE_LIMIT = 0x10;
const uint8_t PB_SCONFIG_C9_SP_STARVE_LIMIT  = 0x10;
const uint8_t PB_SCONFIG_C9_FP_STARVE_LIMIT  = 0x10;
const uint8_t PB_SCONFIG_C9_UX_SCOPE_ARB_MODE_LFSR = 0x0;                       // LFSR_ONLY
const uint8_t PB_SCONFIG_C9_UX_SCOPE_ARB_MODE_RR = 0x1;                         // RR_ONLY
const uint8_t PB_SCONFIG_C9_UX_SCOPE_ARB_MODE_LFSR_ON_STARVATION_ELSE_RR = 0x2; // LFSR_ON_STARVATION_ELSE_RR
const uint8_t PB_SCONFIG_C9_UX_SCOPE_ARB_MODE_RR_ON_STARVATION_ELSE_LFSR = 0x3; // RR_ON_STARVATION_ELSE_LFSR
const uint8_t PB_SCONFIG_C9_UX_LOCAL_ARB_MODE_LFSR = 0x0;                       // LFSR_ONLY
const uint8_t PB_SCONFIG_C9_UX_LOCAL_ARB_MODE_RR = 0x1;                         // RR_ONLY
const uint8_t PB_SCONFIG_C9_UX_LOCAL_ARB_MODE_LFSR_ON_STARVATION_ELSE_RR = 0x2; // LFSR_ON_STARVATION_ELSE_RR
const uint8_t PB_SCONFIG_C9_UX_LOCAL_ARB_MODE_RR_ON_STARVATION_ELSE_LFSR = 0x3; // RR_ON_STARVATION_ELSE_LFSR


//
// PBH_CMD_CENTRAL_ARB (center, chain #10) field/bit definitions
//

const proc_build_smp_sconfig_def PB_SCONFIG_C10_DEF_VER1 = { 0xA, 20, false, { false, true, false } };
const proc_build_smp_sconfig_def PB_SCONFIG_C10_DEF_VER2 = { 0xA, 23, false, { false, true, false } };

const uint32_t PB_SCONFIG_C10_CMD_CPU_RATIO_START_BIT_VER1[PB_SCONFIG_NUM_CPU_RATIOS] = { 59, 54, 49, 44 };
const uint32_t PB_SCONFIG_C10_CMD_CPU_RATIO_END_BIT_VER1[PB_SCONFIG_NUM_CPU_RATIOS]   = { 63, 58, 53, 48 };

const uint32_t PB_SCONFIG_C10_CMD_CPU_RATIO_START_BIT_VER2[PB_SCONFIG_NUM_CPU_RATIOS] = { 56, 51, 46, 41 };
const uint32_t PB_SCONFIG_C10_CMD_CPU_RATIO_END_BIT_VER2[PB_SCONFIG_NUM_CPU_RATIOS]   = { 60, 55, 50, 45 };
const uint32_t PB_SCONFIG_C10_DAT_X_LINK_HOLDOFF_ENABLE_BIT_VER2 = 61;
const uint32_t PB_SCONFIG_C10_DAT_A_LINK_HOLDOFF_ENABLE_BIT_VER2 = 62;
const uint32_t PB_SCONFIG_C10_DAT_LINK_HOLDOFF_MULTIPLIER_BIT_VER2 = 63;

const uint8_t PB_SCONFIG_C10_CMD_CPU_RATIO_TABLE[PROC_BUILD_SMP_CPU_DELAY_NUM_SETPOINTS] = { 15, 14, 13, 12, 11, 11, 10, 10,  9,  9,  8,  8,  7 };

const uint8_t PB_SCONFIG_C10_CMD_CPU_RATIO_QUARTER = 3;
const uint8_t PB_SCONFIG_C10_CMD_CPU_RATIO_HALF    = 7;
const uint8_t PB_SCONFIG_C10_DAT_X_LINK_HOLDOFF_ENABLE   = 0x0; // disable
const uint8_t PB_SCONFIG_C10_DAT_A_LINK_HOLDOFF_ENABLE   = 0x0; // disable
const uint8_t PB_SCONFIG_C10_DAT_LINK_HOLDOFF_MULTIPLIER = 0x0; // x2


//
// PBH_RSP_CRESP_ARB (center, chain #11) field/bit definitions
//

const proc_build_smp_sconfig_def PB_SCONFIG_C11_DEF = { 0xB, 20, false, { false, true, false } };

const uint32_t PB_SCONFIG_C11_RSP_CPU_RATIO_START_BIT[PB_SCONFIG_NUM_CPU_RATIOS] = { 59, 54, 49, 44 };
const uint32_t PB_SCONFIG_C11_RSP_CPU_RATIO_END_BIT[PB_SCONFIG_NUM_CPU_RATIOS]   = { 63, 58, 53, 48 };

const uint8_t PB_SCONFIG_C11_RSP_CPU_RATIO_TABLE[PROC_BUILD_SMP_CPU_DELAY_NUM_SETPOINTS] = { 16, 15, 14, 13, 12, 12, 11, 11, 10, 10,  9,  9,  8 };

const uint8_t PB_SCONFIG_C11_RSP_CPU_RATIO_QUARTER = 4;
const uint8_t PB_SCONFIG_C11_RSP_CPU_RATIO_HALF    = 8;

//
// PBH_PBIEX_EH (east/west, chain #0) field/bit definitions
//

const proc_build_smp_sconfig_def PB_SCONFIG_WE0_DEF = { 0x0, 52, false, { true, false, true } };

const uint32_t PB_SCONFIG_WE0_CMD_C2I_DONE_LAUNCH_START_BIT = 12;
const uint32_t PB_SCONFIG_WE0_CMD_C2I_DONE_LAUNCH_END_BIT = 14;
const uint32_t PB_SCONFIG_WE0_CMD_C2I_LATE_RD_MODE_BIT = 15;
const uint32_t PB_SCONFIG_WE0_CMD_C2I_DELAY_SP_RD_START_BIT = 16;
const uint32_t PB_SCONFIG_WE0_CMD_C2I_DELAY_SP_RD_END_BIT = 17;
const uint32_t PB_SCONFIG_WE0_CMD_C2I_SPARE_MODE_BIT = 18;
const uint32_t PB_SCONFIG_WE0_PRSP_C2I_DONE_LAUNCH_BIT = 19;
const uint32_t PB_SCONFIG_WE0_PRSP_C2I_HW070772_DIS_BIT = 20;
const uint32_t PB_SCONFIG_WE0_PRSP_C2I_NOP_MODE_START_BIT = 21;
const uint32_t PB_SCONFIG_WE0_PRSP_C2I_NOP_MODE_END_BIT = 22;
const uint32_t PB_SCONFIG_WE0_PRSP_C2I_SPARE_MODE_BIT = 23;
const uint32_t PB_SCONFIG_WE0_CRSP_I2C_DVAL_LAUNCH_START_BIT = 24;
const uint32_t PB_SCONFIG_WE0_CRSP_I2C_DVAL_LAUNCH_END_BIT = 25;
const uint32_t PB_SCONFIG_WE0_CRSP_I2C_HSHAKE_BIT = 26;
const uint32_t PB_SCONFIG_WE0_CRSP_I2C_SPARE_MODE_BIT = 27;
const uint32_t PB_SCONFIG_WE0_DATA_I2C_DVAL_LAUNCH_START_BIT = 28;
const uint32_t PB_SCONFIG_WE0_DATA_I2C_DVAL_LAUNCH_END_BIT = 29;
const uint32_t PB_SCONFIG_WE0_DATA_I2C_SPARE_MODE_BIT = 30;
const uint32_t PB_SCONFIG_WE0_DATA_I2C_FORCE_FA_ALLOC_BIT = 31;
const uint32_t PB_SCONFIG_WE0_DATA_C2I_DONE_LAUNCH_START_BIT = 32;
const uint32_t PB_SCONFIG_WE0_DATA_C2I_DONE_LAUNCH_END_BIT = 33;
const uint32_t PB_SCONFIG_WE0_DATA_C2I_INITIAL_REQ_DLY_START_BIT = 34;
const uint32_t PB_SCONFIG_WE0_DATA_C2I_INITIAL_REQ_DLY_END_BIT = 36;
const uint32_t PB_SCONFIG_WE0_DATA_C2I_DCTR_LAUNCH_START_BIT = 37;
const uint32_t PB_SCONFIG_WE0_DATA_C2I_DCTR_LAUNCH_END_BIT = 38;
const uint32_t PB_SCONFIG_WE0_DATA_C2I_OUTSTANDING_REQ_COUNT_BIT = 39;
const uint32_t PB_SCONFIG_WE0_DATA_C2I_REQ_ID_ASSIGNMENT_MODE_BIT = 40;
const uint32_t PB_SCONFIG_WE0_DATA_C2I_ALLOW_FRAGMENTATION_BIT = 41;
const uint32_t PB_SCONFIG_WE0_DATA_C2I_SERIAL_DREQ_ID_BIT = 42;
const uint32_t PB_SCONFIG_WE0_DATA_C2I_SPARE_MODE_BIT = 43;
const uint32_t PB_SCONFIG_WE0_RCMD_I2C_DVAL_LAUNCH_START_BIT = 44;
const uint32_t PB_SCONFIG_WE0_RCMD_I2C_DVAL_LAUNCH_END_BIT = 45;
const uint32_t PB_SCONFIG_WE0_RCMD_I2C_HSHAKE_BIT = 46;
const uint32_t PB_SCONFIG_WE0_RCMD_I2C_SPARE_MODE_BIT = 47;
const uint32_t PB_SCONFIG_WE0_FP_I2C_DVAL_LAUNCH_START_BIT = 48;
const uint32_t PB_SCONFIG_WE0_FP_I2C_DVAL_LAUNCH_END_BIT = 49;
const uint32_t PB_SCONFIG_WE0_FP_I2C_HSHAKE_BIT = 50;
const uint32_t PB_SCONFIG_WE0_FP_I2C_SPARE_MODE_BIT  = 51;
const uint32_t PB_SCONFIG_WE0_FP_C2I_DONE_LAUNCH_BIT = 52;
const uint32_t PB_SCONFIG_WE0_FP_C2I_SPARE_MODE_BIT = 53;
const uint32_t PB_SCONFIG_WE0_CPU_DELAY_FULL_START_BIT = 54;
const uint32_t PB_SCONFIG_WE0_CPU_DELAY_FULL_END_BIT = 58;
const uint32_t PB_SCONFIG_WE0_CPU_DELAY_NOM_START_BIT  = 59;
const uint32_t PB_SCONFIG_WE0_CPU_DELAY_NOM_END_BIT = 63;

const bool     PB_SCONFIG_WE0_CMD_C2I_LATE_RD_MODE = true;             // on
const uint8_t  PB_SCONFIG_WE0_CMD_C2I_DELAY_SP_RD = 0x0;               // rc_p1
const bool     PB_SCONFIG_WE0_CMD_C2I_SPARE_MODE = false;              // spare
const uint8_t  PB_SCONFIG_WE0_PRSP_C2I_DONE_LAUNCH = 0x0;              // rc_p1
const bool     PB_SCONFIG_WE0_PRSP_C2I_HW070772_DIS = true;            // on
const uint8_t  PB_SCONFIG_WE0_PRSP_C2I_NOP_MODE = 0x0;                 // 16c
const bool     PB_SCONFIG_WE0_PRSP_C2I_SPARE_MODE = false;             // spare
const bool     PB_SCONFIG_WE0_CRSP_I2C_HSHAKE = false;                 // off
const bool     PB_SCONFIG_WE0_CRSP_I2C_SPARE_MODE = false;             // spare
const bool     PB_SCONFIG_WE0_DATA_I2C_SPARE_MODE = false;             // spare
const bool     PB_SCONFIG_WE0_DATA_I2C_FORCE_FA_ALLOC = false;         // off
const uint8_t  PB_SCONFIG_WE0_DATA_C2I_INITIAL_REQ_DLY = 0x7;          // 7c
const bool     PB_SCONFIG_WE0_DATA_C2I_OUTSTANDING_REQ_COUNT = false;  // 8
const bool     PB_SCONFIG_WE0_DATA_C2I_REQ_ID_ASSIGNMENT_MODE = false; // FA
const bool     PB_SCONFIG_WE0_DATA_C2I_ALLOW_FRAGMENTATION = true;     // on
const bool     PB_SCONFIG_WE0_DATA_C2I_SERIAL_DREQ_ID = true;          // on
const bool     PB_SCONFIG_WE0_DATA_C2I_SPARE_MODE = false;             // spare
const bool     PB_SCONFIG_WE0_RCMD_I2C_HSHAKE = false;                 // off
const bool     PB_SCONFIG_WE0_RCMD_I2C_SPARE_MODE = false;             // spare
const uint8_t  PB_SCONFIG_WE0_FP_I2C_DVAL_LAUNCH = 0x0;                // wc_p1
const uint8_t  PB_SCONFIG_WE0_FP_I2C_HSHAKE = false;                   // off
const bool     PB_SCONFIG_WE0_FP_I2C_SPARE_MODE = false;               // spare
const uint8_t  PB_SCONFIG_WE0_FP_C2I_DONE_LAUNCH = 0x0;                // rc_p1
const bool     PB_SCONFIG_WE0_FP_C2I_SPARE_MODE = false;               // spare

const uint8_t PB_SCONFIG_WE0_CPU_DELAY_TABLE[PROC_BUILD_SMP_CPU_DELAY_NUM_SETPOINTS] = { 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26 };


//
// PBH_PBIEX_EX (east/west, chain #1) field/bit definitions
//

const proc_build_smp_sconfig_def PB_SCONFIG_WE1_DEF = { 0x1, 38, true, { true, false, true } };

const uint32_t PB_SCONFIG_WE1_CMD_C2I_DVAL_LAUNCH_START_BIT = 26;
const uint32_t PB_SCONFIG_WE1_CMD_C2I_DVAL_LAUNCH_END_BIT = 27;
const uint32_t PB_SCONFIG_WE1_CMD_C2I_EARLY_REQ_MODE_BIT = 28;
const uint32_t PB_SCONFIG_WE1_CMD_C2I_SPARE_BIT = 29;
const uint32_t PB_SCONFIG_WE1_CMD_C2I_SPARE_MODE_BIT = 30;
const uint32_t PB_SCONFIG_WE1_PRSP_C2I_DVAL_LAUNCH_START_BIT = 31;
const uint32_t PB_SCONFIG_WE1_PRSP_C2I_DVAL_LAUNCH_END_BIT = 32;
const uint32_t PB_SCONFIG_WE1_PRSP_C2I_HSHAKE_BIT = 33;
const uint32_t PB_SCONFIG_WE1_PRSP_C2I_SPARE_MODE_BIT = 34;
const uint32_t PB_SCONFIG_WE1_CRSP_I2C_DONE_LAUNCH_BIT = 35;
const uint32_t PB_SCONFIG_WE1_CRSP_I2C_PTY_RD_CAPTURE_START_BIT = 36;
const uint32_t PB_SCONFIG_WE1_CRSP_I2C_PTY_RD_CAPTURE_END_BIT = 37;
const uint32_t PB_SCONFIG_WE1_CRSP_I2C_SPARE_MODE_BIT = 38;
const uint32_t PB_SCONFIG_WE1_DATA_I2C_DONE_LAUNCH_START_BIT = 39;
const uint32_t PB_SCONFIG_WE1_DATA_I2C_DONE_LAUNCH_END_BIT = 40;
const uint32_t PB_SCONFIG_WE1_DATA_I2C_DCTR_LAUNCH_START_BIT = 41;
const uint32_t PB_SCONFIG_WE1_DATA_I2C_DCTR_LAUNCH_END_BIT = 42;
const uint32_t PB_SCONFIG_WE1_DATA_I2C_SPARE_MODE_BIT = 43;
const uint32_t PB_SCONFIG_WE1_DATA_C2I_DVAL_LAUNCH_START_BIT = 44;
const uint32_t PB_SCONFIG_WE1_DATA_C2I_DVAL_LAUNCH_END_BIT = 45;
const uint32_t PB_SCONFIG_WE1_DATA_C2I_DREQ_LAUNCH_START_BIT = 46;
const uint32_t PB_SCONFIG_WE1_DATA_C2I_DREQ_LAUNCH_END_BIT = 47;
const uint32_t PB_SCONFIG_WE1_DATA_C2I_SPARE_MODE_BIT = 48;
const uint32_t PB_SCONFIG_WE1_RCMD_I2C_DONE_LAUNCH_BIT = 49;
const uint32_t PB_SCONFIG_WE1_RCMD_I2C_L3_NOT_USE_DCBFL_BIT = 50;
const uint32_t PB_SCONFIG_WE1_RCMD_I2C_PTY_RD_CAPTURE_START_BIT = 51;
const uint32_t PB_SCONFIG_WE1_RCMD_I2C_PTY_RD_CAPTURE_END_BIT = 52;
const uint32_t PB_SCONFIG_WE1_RCMD_I2C_PTY_INJECT_BIT = 53;
const uint32_t PB_SCONFIG_WE1_RCMD_I2C_SPARE_MODE_BIT = 54;
const uint32_t PB_SCONFIG_WE1_FP_I2C_DONE_LAUNCH_BIT = 55;
const uint32_t PB_SCONFIG_WE1_FP_I2C_SPARE_BIT = 56;
const uint32_t PB_SCONFIG_WE1_FP_I2C_PTY_RD_CAPTURE_START_BIT = 57;
const uint32_t PB_SCONFIG_WE1_FP_I2C_PTY_RD_CAPTURE_END_BIT = 58;
const uint32_t PB_SCONFIG_WE1_FP_I2C_SPARE_MODE_BIT = 59;
const uint32_t PB_SCONFIG_WE1_FP_C2I_DVAL_LAUNCH_START_BIT = 60;
const uint32_t PB_SCONFIG_WE1_FP_C2I_DVAL_LAUNCH_END_BIT = 61;
const uint32_t PB_SCONFIG_WE1_FP_C2I_HSHAKE_BIT = 62;
const uint32_t PB_SCONFIG_WE1_FP_C2I_SPARE_MODE_BIT = 63;

const bool    PB_SCONFIG_WE1_CMD_C2I_EARLY_REQ_MODE = false;           // off
const bool    PB_SCONFIG_WE1_CMD_C2I_SPARE = false;                    // spare
const bool    PB_SCONFIG_WE1_CMD_C2I_SPARE_MODE = false;               // spare
const uint8_t PB_SCONFIG_WE1_PRSP_C2I_DVAL_LAUNCH = 0x0;               // rc_p1
const bool    PB_SCONFIG_WE1_PRSP_C2I_HSHAKE = false;                  // off
const bool    PB_SCONFIG_WE1_PRSP_C2I_SPARE_MODE = false;              // spare
const bool    PB_SCONFIG_WE1_CRSP_I2C_SPARE_MODE = false;              // spare
const bool    PB_SCONFIG_WE1_DATA_I2C_SPARE_MODE = false;              // spare
const uint8_t PB_SCONFIG_WE1_DATA_C2I_DREQ_LAUNCH = 0x0;               // rc_d3
const bool    PB_SCONFIG_WE1_DATA_C2I_SPARE_MODE = false;              // off
const bool    PB_SCONFIG_WE1_RCMD_I2C_L3_NOT_USE_DCBFL = false;        // off
const bool    PB_SCONFIG_WE1_RCMD_I2C_PTY_INJECT = false;              // off
const bool    PB_SCONFIG_WE1_RCMD_I2C_SPARE_MODE = false;              // off
const bool    PB_SCONFIG_WE1_FP_I2C_DONE_LAUNCH = false;               // rc_p1
const bool    PB_SCONFIG_WE1_FP_I2C_SPARE = false;                     // spare
const uint8_t PB_SCONFIG_WE1_FP_I2C_PTY_RD_CAPTURE = 0x0;              // rc
const bool    PB_SCONFIG_WE1_FP_I2C_SPARE_MODE = false;                // off
const uint8_t PB_SCONFIG_WE1_FP_C2I_DVAL_LAUNCH = 0x0;                 // wc_p1
const bool    PB_SCONFIG_WE1_FP_C2I_HSHAKE = false;                    // off
const bool    PB_SCONFIG_WE1_FP_C2I_SPARE_MODE = false;                // spare


//
// PBH_DAT_ARB_EM (east/west, chain #5) field/bit definitions
//

const proc_build_smp_sconfig_def PB_SCONFIG_WE5_DEF_VER1 = { 0x5, 51, false, { true, false, true } };
const proc_build_smp_sconfig_def PB_SCONFIG_WE5_DEF_VER2 = { 0x5, 52, false, { true, false, true } };

const uint32_t PB_SCONFIG_WE5_LOCK_ON_LINKS_BIT_VER1 = 13;
const uint32_t PB_SCONFIG_WE5_X_ON_LINK_TOK_AGG_THRESHOLD_START_BIT_VER1 = 14;
const uint32_t PB_SCONFIG_WE5_X_ON_LINK_TOK_AGG_THRESHOLD_END_BIT_VER1 = 17;
const uint32_t PB_SCONFIG_WE5_X_OFF_LINK_TOK_AGG_THRESHOLD_START_BIT_VER1 = 18;
const uint32_t PB_SCONFIG_WE5_X_OFF_LINK_TOK_AGG_THRESHOLD_END_BIT_VER1 = 21;
const uint32_t PB_SCONFIG_WE5_A_LINK_TOK_AGG_THRESHOLD_START_BIT_VER1 = 22;
const uint32_t PB_SCONFIG_WE5_A_LINK_TOK_AGG_THRESHOLD_END_BIT_VER1 = 25;
const uint32_t PB_SCONFIG_WE5_F_LINK_TOK_AGG_THRESHOLD_START_BIT_VER1 = 26;
const uint32_t PB_SCONFIG_WE5_F_LINK_TOK_AGG_THRESHOLD_END_BIT_VER1 = 29;
const uint32_t PB_SCONFIG_WE5_A_LINK_TOK_IND_THRESHOLD_START_BIT_VER1 = 30;
const uint32_t PB_SCONFIG_WE5_A_LINK_TOK_IND_THRESHOLD_END_BIT_VER1 = 33;
const uint32_t PB_SCONFIG_WE5_PASSTHRU_ENABLE_BIT_VER1 = 34;
const uint32_t PB_SCONFIG_WE5_PASSTHRU_X_PRIORITY_START_BIT_VER1 = 35;
const uint32_t PB_SCONFIG_WE5_PASSTHRU_X_PRIORITY_END_BIT_VER1 = 42;
const uint32_t PB_SCONFIG_WE5_PASSTHRU_A_PRIORITY_START_BIT_VER1 = 43;
const uint32_t PB_SCONFIG_WE5_PASSTHRU_A_PRIORITY_END_BIT_VER1 = 50;
const uint32_t PB_SCONFIG_WE5_A_TOK_INIT_START_BIT_VER1 = 51;
const uint32_t PB_SCONFIG_WE5_A_TOK_INIT_END_BIT_VER1 = 54;
const uint32_t PB_SCONFIG_WE5_F_TOK_INIT_START_BIT_VER1 = 55;
const uint32_t PB_SCONFIG_WE5_F_TOK_INIT_END_BIT_VER1 = 58;
const uint32_t PB_SCONFIG_WE5_EM_FP_ENABLE_BIT_VER1 = 59;
const uint32_t PB_SCONFIG_WE5_SPARE_START_BIT_VER1 = 60;
const uint32_t PB_SCONFIG_WE5_SPARE_END_BIT_VER1 = 61;
const uint32_t PB_SCONFIG_WE5_MEM_STV_PRIORITY_START_BIT_VER1 = 62;
const uint32_t PB_SCONFIG_WE5_MEM_STV_PRIORITY_END_BIT_VER1 = 63;

const uint32_t PB_SCONFIG_WE5_LOCK_ON_LINKS_BIT_VER2 = 12;
const uint32_t PB_SCONFIG_WE5_X_ON_LINK_TOK_AGG_THRESHOLD_START_BIT_VER2 = 13;
const uint32_t PB_SCONFIG_WE5_X_ON_LINK_TOK_AGG_THRESHOLD_END_BIT_VER2 = 16;
const uint32_t PB_SCONFIG_WE5_X_OFF_LINK_TOK_AGG_THRESHOLD_START_BIT_VER2 = 17;
const uint32_t PB_SCONFIG_WE5_X_OFF_LINK_TOK_AGG_THRESHOLD_END_BIT_VER2 = 20;
const uint32_t PB_SCONFIG_WE5_A_LINK_TOK_AGG_THRESHOLD_START_BIT_VER2 = 21;
const uint32_t PB_SCONFIG_WE5_A_LINK_TOK_AGG_THRESHOLD_END_BIT_VER2 = 24;
const uint32_t PB_SCONFIG_WE5_F_LINK_TOK_AGG_THRESHOLD_START_BIT_VER2 = 25;
const uint32_t PB_SCONFIG_WE5_F_LINK_TOK_AGG_THRESHOLD_END_BIT_VER2 = 28;
const uint32_t PB_SCONFIG_WE5_A_LINK_TOK_IND_THRESHOLD_START_BIT_VER2 = 29;
const uint32_t PB_SCONFIG_WE5_A_LINK_TOK_IND_THRESHOLD_END_BIT_VER2 = 32;
const uint32_t PB_SCONFIG_WE5_PASSTHRU_ENABLE_BIT_VER2 = 33;
const uint32_t PB_SCONFIG_WE5_PASSTHRU_X_PRIORITY_START_BIT_VER2 = 34;
const uint32_t PB_SCONFIG_WE5_PASSTHRU_X_PRIORITY_END_BIT_VER2 = 41;
const uint32_t PB_SCONFIG_WE5_PASSTHRU_A_PRIORITY_START_BIT_VER2 = 42;
const uint32_t PB_SCONFIG_WE5_PASSTHRU_A_PRIORITY_END_BIT_VER2 = 49;
const uint32_t PB_SCONFIG_WE5_A_TOK_INIT_START_BIT_VER2 = 50;
const uint32_t PB_SCONFIG_WE5_A_TOK_INIT_END_BIT_VER2 = 53;
const uint32_t PB_SCONFIG_WE5_F_TOK_INIT_START_BIT_VER2 = 54;
const uint32_t PB_SCONFIG_WE5_F_TOK_INIT_END_BIT_VER2 = 57;
const uint32_t PB_SCONFIG_WE5_EM_FP_ENABLE_BIT_VER2 = 58;
const uint32_t PB_SCONFIG_WE5_SPARE_START_BIT_VER2 = 59;
const uint32_t PB_SCONFIG_WE5_SPARE_END_BIT_VER2 = 59;
const uint32_t PB_SCONFIG_WE5_A_IND_THRESHOLD_BIT_VER2 = 60;
const uint32_t PB_SCONFIG_WE5_MEM_STV_PRIORITY_START_BIT_VER2 = 61;
const uint32_t PB_SCONFIG_WE5_MEM_STV_PRIORITY_END_BIT_VER2 = 62;
const uint32_t PB_SCONFIG_WE5_X_OFF_SEL_BIT_VER2 = 63;

const bool    PB_SCONFIG_WE5_LOCK_ON_LINKS = true;                   // lock
const uint8_t PB_SCONFIG_WE5_X_ON_LINK_TOK_AGG_THRESHOLD = 0x4;      // cnt_4
const uint8_t PB_SCONFIG_WE5_X_OFF_LINK_TOK_AGG_THRESHOLD = 0x4;     // cnt_4
const uint8_t PB_SCONFIG_WE5_A_LINK_TOK_AGG_THRESHOLD = 0x4;         // cnt_4
const uint8_t PB_SCONFIG_WE5_F_LINK_TOK_AGG_THRESHOLD = 0x0;         // cnt_0
const uint8_t PB_SCONFIG_WE5_A_LINK_TOK_IND_THRESHOLD = 0x2;         // cnt_2
const bool    PB_SCONFIG_WE5_PASSTHRU_ENABLE = true;                 // enable
const uint8_t PB_SCONFIG_WE5_PASSTHRU_X_PRIORITY = 0xFE;             // cnt_7to1
const uint8_t PB_SCONFIG_WE5_PASSTHRU_A_PRIORITY = 0xFE;             // cnt_7to1
const uint8_t PB_SCONFIG_WE5_A_TOK_INIT = 0x8;                       // cnt_8
const uint8_t PB_SCONFIG_WE5_F_TOK_INIT = 0x4;                       // cnt_4
const bool    PB_SCONFIG_WE5_EM_FP_ENABLE = true;                    // enable
const uint8_t PB_SCONFIG_WE5_SPARE = 0x0;                            // spare
const uint8_t PB_SCONFIG_WE5_MEM_STV_PRIORITY = 0x2;                 // stv

const uint8_t PB_SCONFIG_WE5_A_IND_THRESHOLD = 0x0;                  // gt4
const uint8_t PB_SCONFIG_WE5_X_OFF_SEL = 0x0;                        // disable


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// function: utility function to program PB serial SCOM chain
// parameters: i_smp_chip    => structure encapsulating SMP chip
//             i_sconfig_def => structure defining properties of chain
//                              to be written
//             i_chain_data  => data buffer containing chain write data
// returns: FAPI_RC_SUCCESS if register programming is successful,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_set_sconfig(
    const proc_build_smp_chip& i_smp_chip,
    const proc_build_smp_sconfig_def & i_sconfig_def,
    const ecmdDataBufferBase& i_chain_data)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0x0;
    ecmdDataBufferBase data(64);

    // mark function entry
    FAPI_DBG("proc_build_smp_set_sconfig: Start");

    do
    {
        // pb_cfg_sconfig_load
        rc_ecmd |= data.setBit(PB_SCONFIG_LOAD_START_BIT);

        // pb_cfg_sconfig_slow
        if (i_sconfig_def.use_slow_clock)
        {
            rc_ecmd |= data.setBit(PB_SCONFIG_LOAD_SLOW_BIT);
        }

        // pb_cfg_sconfig_shift_count
        rc_ecmd |= data.insertFromRight(
            i_sconfig_def.length,
            PB_SCONFIG_SHIFT_COUNT_START_BIT,
            (PB_SCONFIG_SHIFT_COUNT_END_BIT-
             PB_SCONFIG_SHIFT_COUNT_START_BIT+1));

        // pb_cfg_sconfig_shift_select
        rc_ecmd |= data.insertFromRight(
            i_sconfig_def.select,
            PB_SCONFIG_SELECT_START_BIT,
            (PB_SCONFIG_SELECT_END_BIT-
             PB_SCONFIG_SELECT_START_BIT+1));

        // pb_cfg_sconfig_shift_data
        rc_ecmd |= i_chain_data.extractPreserve(
            data,
            PB_SCONFIG_SHIFT_DATA_START_BIT,
            (PB_SCONFIG_SHIFT_DATA_END_BIT-
             PB_SCONFIG_SHIFT_DATA_START_BIT+1),
            PB_SCONFIG_SHIFT_DATA_START_BIT);

        if (rc_ecmd)
        {
            FAPI_ERR("proc_build_smp_set_sconfig: Error 0x%x setting up PB Serial Configuration load register data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // write specified register copies
        for (uint8_t r = 0; r < PROC_BUILD_SMP_NUM_SHADOWS; r++)
        {
            if (i_sconfig_def.use_shadow[r])
            {
                // write register
                rc = fapiPutScom(i_smp_chip.chip->this_chip,
                                 PB_SCONFIG_LOAD[r],
                                 data);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_build_smp_set_sconfig: fapiPutScom error (%08X)",
                             PB_SCONFIG_LOAD[r]);
                    break;
                }
            }
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_build_smp_set_sconfig: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: program PB serial SCOM chain (center #4)
// parameters: i_smp_chip => structure encapsulating SMP chip
// returns: FAPI_RC_SUCCESS if register programming is successful,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_set_sconfig_c4(
    const proc_build_smp_chip& i_smp_chip)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0x0;
    ecmdDataBufferBase data(64);

    // mark function entry
    FAPI_DBG("proc_build_smp_set_sconfig_c4: Start");

    do
    {
        // build register content
        // gp_lo_rty_threshold
        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_C4_GP_LO_RTY_THRESHOLD,
            PB_SCONFIG_C4_GP_LO_RTY_THRESHOLD_START_BIT,
            (PB_SCONFIG_C4_GP_LO_RTY_THRESHOLD_END_BIT-
             PB_SCONFIG_C4_GP_LO_RTY_THRESHOLD_START_BIT+1));

        // gp_hi_rty_threshold
        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_C4_GP_HI_RTY_THRESHOLD,
            PB_SCONFIG_C4_GP_HI_RTY_THRESHOLD_START_BIT,
            (PB_SCONFIG_C4_GP_HI_RTY_THRESHOLD_END_BIT-
             PB_SCONFIG_C4_GP_HI_RTY_THRESHOLD_START_BIT+1));

        // rgp_lo_rty_threshold
        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_C4_RGP_LO_RTY_THRESHOLD,
            PB_SCONFIG_C4_RGP_LO_RTY_THRESHOLD_START_BIT,
            (PB_SCONFIG_C4_RGP_LO_RTY_THRESHOLD_END_BIT-
             PB_SCONFIG_C4_RGP_LO_RTY_THRESHOLD_START_BIT+1));

        // rgp_hi_rty_threshold
        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_C4_RGP_HI_RTY_THRESHOLD,
            PB_SCONFIG_C4_RGP_HI_RTY_THRESHOLD_START_BIT,
            (PB_SCONFIG_C4_RGP_HI_RTY_THRESHOLD_END_BIT-
             PB_SCONFIG_C4_RGP_HI_RTY_THRESHOLD_START_BIT+1));

        // sp_lo_rty_threshold
        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_C4_SP_LO_RTY_THRESHOLD,
            PB_SCONFIG_C4_SP_LO_RTY_THRESHOLD_START_BIT,
            (PB_SCONFIG_C4_SP_LO_RTY_THRESHOLD_END_BIT-
             PB_SCONFIG_C4_SP_LO_RTY_THRESHOLD_START_BIT+1));

        if (rc_ecmd)
        {
            FAPI_ERR("proc_build_smp_set_sconfig_c4: Error 0x%x setting up PB Serial Configuration load register data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // call common routine to program chain
        rc = proc_build_smp_set_sconfig(i_smp_chip, PB_SCONFIG_C4_DEF, data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_sconfig_c4: Error from proc_build_smp_set_sconfig");
            break;
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_build_smp_set_sconfig_c4: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: program PB serial SCOM chain (center #5)
// parameters: i_smp_chip => structure encapsulating SMP chip
// returns: FAPI_RC_SUCCESS if register programming is successful,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_set_sconfig_c5(
    const proc_build_smp_chip& i_smp_chip)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0x0;
    ecmdDataBufferBase data(64);

    // mark function entry
    FAPI_DBG("proc_build_smp_set_sconfig_c5: Start");

    do
    {
        // build register content
        // sp_hi_rty_threshold
        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_C5_SP_HI_RTY_THRESHOLD,
            PB_SCONFIG_C5_SP_HI_RTY_THRESHOLD_START_BIT,
            (PB_SCONFIG_C5_SP_HI_RTY_THRESHOLD_END_BIT-
             PB_SCONFIG_C5_SP_HI_RTY_THRESHOLD_START_BIT+1));

        // gp_cresp_sample_time
        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_C5_GP_CRESP_SAMPLE_TIME,
            PB_SCONFIG_C5_GP_CRESP_SAMPLE_TIME_START_BIT,
            (PB_SCONFIG_C5_GP_CRESP_SAMPLE_TIME_END_BIT-
             PB_SCONFIG_C5_GP_CRESP_SAMPLE_TIME_START_BIT+1));

        // rgp_cresp_sample_time
        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_C5_RGP_CRESP_SAMPLE_TIME,
            PB_SCONFIG_C5_RGP_CRESP_SAMPLE_TIME_START_BIT,
            (PB_SCONFIG_C5_RGP_CRESP_SAMPLE_TIME_END_BIT-
             PB_SCONFIG_C5_RGP_CRESP_SAMPLE_TIME_START_BIT+1));

        // sp_cresp_sample_time
        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_C5_SP_CRESP_SAMPLE_TIME,
            PB_SCONFIG_C5_SP_CRESP_SAMPLE_TIME_START_BIT,
            (PB_SCONFIG_C5_SP_CRESP_SAMPLE_TIME_END_BIT-
             PB_SCONFIG_C5_SP_CRESP_SAMPLE_TIME_START_BIT+1));

        if (rc_ecmd)
        {
            FAPI_ERR("proc_build_smp_set_sconfig_c5: Error 0x%x setting up PB Serial Configuration load register data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // call common routine to program chain
        rc = proc_build_smp_set_sconfig(i_smp_chip, PB_SCONFIG_C5_DEF, data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_sconfig_c5: Error from proc_build_smp_set_sconfig");
            break;
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_build_smp_set_sconfig_c5: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: program PB serial SCOM chain (center #6)
// parameters: i_smp_chip => structure encapsulating SMP chip
// returns: FAPI_RC_SUCCESS if register programming is successful,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_set_sconfig_c6(
    const proc_build_smp_chip& i_smp_chip)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0x0;
    ecmdDataBufferBase data(64);

    // mark function entry
    FAPI_DBG("proc_build_smp_set_sconfig_c6: Start");

    do
    {
        // build register content
        // gp_req_sample_time
        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_C6_GP_REQ_SAMPLE_TIME,
            PB_SCONFIG_C6_GP_REQ_SAMPLE_TIME_START_BIT,
            (PB_SCONFIG_C6_GP_REQ_SAMPLE_TIME_END_BIT-
             PB_SCONFIG_C6_GP_REQ_SAMPLE_TIME_START_BIT+1));

        // sp_req_sample_time
        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_C6_SP_REQ_SAMPLE_TIME,
            PB_SCONFIG_C6_SP_REQ_SAMPLE_TIME_START_BIT,
            (PB_SCONFIG_C6_SP_REQ_SAMPLE_TIME_END_BIT-
             PB_SCONFIG_C6_SP_REQ_SAMPLE_TIME_START_BIT+1));

        // gp_lo_jump
        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_C6_GP_LO_JUMP,
            PB_SCONFIG_C6_GP_LO_JUMP_START_BIT,
            (PB_SCONFIG_C6_GP_LO_JUMP_END_BIT-
             PB_SCONFIG_C6_GP_LO_JUMP_START_BIT+1));

        // gp_hi_jump
        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_C6_GP_HI_JUMP,
            PB_SCONFIG_C6_GP_HI_JUMP_START_BIT,
            (PB_SCONFIG_C6_GP_HI_JUMP_END_BIT-
             PB_SCONFIG_C6_GP_HI_JUMP_START_BIT+1));

        // sp_lo_jump
        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_C6_SP_LO_JUMP,
            PB_SCONFIG_C6_SP_LO_JUMP_START_BIT,
            (PB_SCONFIG_C6_SP_LO_JUMP_END_BIT-
             PB_SCONFIG_C6_SP_LO_JUMP_START_BIT+1));

        // sp_hi_jump
        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_C6_SP_HI_JUMP,
            PB_SCONFIG_C6_SP_HI_JUMP_START_BIT,
            (PB_SCONFIG_C6_SP_HI_JUMP_END_BIT-
             PB_SCONFIG_C6_SP_HI_JUMP_START_BIT+1));

        // rgp_lo_jump
        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_C6_RGP_LO_JUMP,
            PB_SCONFIG_C6_RGP_LO_JUMP_START_BIT,
            (PB_SCONFIG_C6_RGP_LO_JUMP_END_BIT-
             PB_SCONFIG_C6_RGP_LO_JUMP_START_BIT+1));

        // rgp_hi_jump
        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_C6_RGP_HI_JUMP,
            PB_SCONFIG_C6_RGP_HI_JUMP_START_BIT,
            (PB_SCONFIG_C6_RGP_HI_JUMP_END_BIT-
             PB_SCONFIG_C6_RGP_HI_JUMP_START_BIT+1));

        if (rc_ecmd)
        {
            FAPI_ERR("proc_build_smp_set_sconfig_c6: Error 0x%x setting up PB Serial Configuration load register data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // call common routine to program chain
        rc = proc_build_smp_set_sconfig(i_smp_chip, PB_SCONFIG_C6_DEF, data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_sconfig_c6: Error from proc_build_smp_set_sconfig");
            break;
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_build_smp_set_sconfig_c6: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: program PB serial SCOM chain (center #7)
// parameters: i_smp_chip => structure encapsulating SMP chip
// returns: FAPI_RC_SUCCESS if register programming is successful,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_set_sconfig_c7(
    const proc_build_smp_chip& i_smp_chip)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0x0;
    ecmdDataBufferBase data(64);

    // mark function entry
    FAPI_DBG("proc_build_smp_set_sconfig_c7: Start");

    do
    {
        // build register content
        // program hang command rates
        for (uint8_t l = 0; l < PB_SCONFIG_NUM_HANG_LEVELS; l++)
        {
            rc_ecmd |= data.insertFromRight(
                PB_SCONFIG_C7_HANG_CMD_RATE[l],
                PB_SCONFIG_C7_HANG_CMD_RATE_START_BIT[l],
                (PB_SCONFIG_C7_HANG_CMD_RATE_END_BIT[l]-
                 PB_SCONFIG_C7_HANG_CMD_RATE_START_BIT[l]+1));
        }

        // slow_go_mode
        rc_ecmd |= data.writeBit(
            PB_SCONFIG_C7_SLOW_GO_RATE_BIT,
            PB_SCONFIG_C7_SLOW_GO_RATE?1:0);

        if (rc_ecmd)
        {
            FAPI_ERR("proc_build_smp_set_sconfig_c7: Error 0x%x setting up PB Serial Configuration load register data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // call common routine to program chain
        rc = proc_build_smp_set_sconfig(i_smp_chip, PB_SCONFIG_C7_DEF, data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_sconfig_c7: Error from proc_build_smp_set_sconfig");
            break;
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_build_smp_set_sconfig_c7: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: program PB serial SCOM chain (center #8)
// parameters: i_smp_chip => structure encapsulating SMP chip
// returns: FAPI_RC_SUCCESS if register programming is successful,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_set_sconfig_c8(
    const proc_build_smp_chip& i_smp_chip)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0x0;
    ecmdDataBufferBase data(64);
    uint8_t ver2 = 0x0;
    uint8_t ver3 = 0x0;
    uint32_t PB_SCONFIG_C8_HANG_CMD_RATE_START_BIT[PB_SCONFIG_NUM_HANG_LEVELS];
    uint32_t PB_SCONFIG_C8_HANG_CMD_RATE_END_BIT[PB_SCONFIG_NUM_HANG_LEVELS];
    uint32_t PB_SCONFIG_C8_CPO_JUMP_LEVEL_START_BIT;
    uint32_t PB_SCONFIG_C8_CPO_JUMP_LEVEL_END_BIT;
    uint32_t PB_SCONFIG_C8_CPO_RTY_LEVEL_START_BIT;
    uint32_t PB_SCONFIG_C8_CPO_RTY_LEVEL_END_BIT;
    uint32_t PB_SCONFIG_C8_P7_SLEEP_BACKOFF_START_BIT;
    uint32_t PB_SCONFIG_C8_P7_SLEEP_BACKOFF_END_BIT;
    uint32_t PB_SCONFIG_C8_RTY_PERCENTAGE_START_BIT;
    uint32_t PB_SCONFIG_C8_RTY_PERCENTAGE_END_BIT;
    uint32_t PB_SCONFIG_C8_INCLUDE_LPC_RTY_BIT;
    proc_build_smp_sconfig_def pb_sconfig_c8_def;

    // mark function entry
    FAPI_DBG("proc_build_smp_set_sconfig_c8: Start");

    do
    {
        rc = FAPI_ATTR_GET(ATTR_CHIP_EC_FEATURE_FBC_SERIAL_SCOM_C8_VER2,
                           &(i_smp_chip.chip->this_chip),
                           ver2);
        if (!rc.ok())
        {
            FAPI_ERR("Error querying Chip EC feature: ATTR_CHIP_EC_FEATURE_FBC_SERIAL_SCOM_C8_VER2");
            break;
        }

        rc = FAPI_ATTR_GET(ATTR_CHIP_EC_FEATURE_FBC_SERIAL_SCOM_C8_VER3,
                           &(i_smp_chip.chip->this_chip),
                           ver3);
        if (!rc.ok())
        {
            FAPI_ERR("Error querying Chip EC feature: ATTR_CHIP_EC_FEATURE_FBC_SERIAL_SCOM_C8_VER3");
            break;
        }

        if (ver3)
        {
            for (uint8_t l = 0; l < PB_SCONFIG_NUM_HANG_LEVELS; l++)
            {
                PB_SCONFIG_C8_HANG_CMD_RATE_START_BIT[l] = PB_SCONFIG_C8_HANG_CMD_RATE_START_BIT_VER3[l];
                PB_SCONFIG_C8_HANG_CMD_RATE_END_BIT[l]   = PB_SCONFIG_C8_HANG_CMD_RATE_END_BIT_VER3[l];
            }
            PB_SCONFIG_C8_CPO_JUMP_LEVEL_START_BIT   = PB_SCONFIG_C8_CPO_JUMP_LEVEL_START_BIT_VER3;
            PB_SCONFIG_C8_CPO_JUMP_LEVEL_END_BIT     = PB_SCONFIG_C8_CPO_JUMP_LEVEL_END_BIT_VER3;
            PB_SCONFIG_C8_CPO_RTY_LEVEL_START_BIT    = PB_SCONFIG_C8_CPO_RTY_LEVEL_START_BIT_VER3;
            PB_SCONFIG_C8_CPO_RTY_LEVEL_END_BIT      = PB_SCONFIG_C8_CPO_RTY_LEVEL_END_BIT_VER3;
            PB_SCONFIG_C8_P7_SLEEP_BACKOFF_START_BIT = PB_SCONFIG_C8_P7_SLEEP_BACKOFF_START_BIT_VER3;
            PB_SCONFIG_C8_P7_SLEEP_BACKOFF_END_BIT   = PB_SCONFIG_C8_P7_SLEEP_BACKOFF_END_BIT_VER3;
            PB_SCONFIG_C8_RTY_PERCENTAGE_START_BIT   = PB_SCONFIG_C8_RTY_PERCENTAGE_START_BIT_VER3;
            PB_SCONFIG_C8_RTY_PERCENTAGE_END_BIT     = PB_SCONFIG_C8_RTY_PERCENTAGE_END_BIT_VER3;
            PB_SCONFIG_C8_INCLUDE_LPC_RTY_BIT        = PB_SCONFIG_C8_INCLUDE_LPC_RTY_BIT_VER3;
            pb_sconfig_c8_def                        = PB_SCONFIG_C8_DEF_VER3;
        }
        else if (ver2)
        {
            for (uint8_t l = 0; l < PB_SCONFIG_NUM_HANG_LEVELS; l++)
            {
                PB_SCONFIG_C8_HANG_CMD_RATE_START_BIT[l] = PB_SCONFIG_C8_HANG_CMD_RATE_START_BIT_VER2[l];
                PB_SCONFIG_C8_HANG_CMD_RATE_END_BIT[l]   = PB_SCONFIG_C8_HANG_CMD_RATE_END_BIT_VER2[l];
            }
            PB_SCONFIG_C8_CPO_JUMP_LEVEL_START_BIT   = PB_SCONFIG_C8_CPO_JUMP_LEVEL_START_BIT_VER2;
            PB_SCONFIG_C8_CPO_JUMP_LEVEL_END_BIT     = PB_SCONFIG_C8_CPO_JUMP_LEVEL_END_BIT_VER2;
            PB_SCONFIG_C8_CPO_RTY_LEVEL_START_BIT    = PB_SCONFIG_C8_CPO_RTY_LEVEL_START_BIT_VER2;
            PB_SCONFIG_C8_CPO_RTY_LEVEL_END_BIT      = PB_SCONFIG_C8_CPO_RTY_LEVEL_END_BIT_VER2;
            PB_SCONFIG_C8_P7_SLEEP_BACKOFF_START_BIT = PB_SCONFIG_C8_P7_SLEEP_BACKOFF_START_BIT_VER2;
            PB_SCONFIG_C8_P7_SLEEP_BACKOFF_END_BIT   = PB_SCONFIG_C8_P7_SLEEP_BACKOFF_END_BIT_VER2;
            PB_SCONFIG_C8_RTY_PERCENTAGE_START_BIT   = 0xFF;
            PB_SCONFIG_C8_RTY_PERCENTAGE_END_BIT     = 0xFF;
            PB_SCONFIG_C8_INCLUDE_LPC_RTY_BIT        = 0xFF;
            pb_sconfig_c8_def                        = PB_SCONFIG_C8_DEF_VER2;
        }
        else
        {
            for (uint8_t l = 0; l < PB_SCONFIG_NUM_HANG_LEVELS; l++)
            {
                PB_SCONFIG_C8_HANG_CMD_RATE_START_BIT[l] = PB_SCONFIG_C8_HANG_CMD_RATE_START_BIT_VER1[l];
                PB_SCONFIG_C8_HANG_CMD_RATE_END_BIT[l]   = PB_SCONFIG_C8_HANG_CMD_RATE_END_BIT_VER1[l];
            }
            PB_SCONFIG_C8_CPO_JUMP_LEVEL_START_BIT   = PB_SCONFIG_C8_CPO_JUMP_LEVEL_START_BIT_VER1;
            PB_SCONFIG_C8_CPO_JUMP_LEVEL_END_BIT     = PB_SCONFIG_C8_CPO_JUMP_LEVEL_END_BIT_VER1;
            PB_SCONFIG_C8_CPO_RTY_LEVEL_START_BIT    = PB_SCONFIG_C8_CPO_RTY_LEVEL_START_BIT_VER1;
            PB_SCONFIG_C8_CPO_RTY_LEVEL_END_BIT      = PB_SCONFIG_C8_CPO_RTY_LEVEL_END_BIT_VER1;
            PB_SCONFIG_C8_P7_SLEEP_BACKOFF_START_BIT = 0xFF;
            PB_SCONFIG_C8_P7_SLEEP_BACKOFF_END_BIT   = 0xFF;
            PB_SCONFIG_C8_RTY_PERCENTAGE_START_BIT   = 0xFF;
            PB_SCONFIG_C8_RTY_PERCENTAGE_END_BIT     = 0xFF;
            PB_SCONFIG_C8_INCLUDE_LPC_RTY_BIT        = 0xFF;
            pb_sconfig_c8_def                        = PB_SCONFIG_C8_DEF_VER1;
        }

        // build register content
        // program hang command rates
        for (uint8_t l = 0; l < PB_SCONFIG_NUM_HANG_LEVELS; l++)
        {
            rc_ecmd |= data.insertFromRight(
                PB_SCONFIG_C8_HANG_CMD_RATE[l],
                PB_SCONFIG_C8_HANG_CMD_RATE_START_BIT[l],
                (PB_SCONFIG_C8_HANG_CMD_RATE_END_BIT[l]-
                 PB_SCONFIG_C8_HANG_CMD_RATE_START_BIT[l]+1));
        }

        // cpo_jump_level
        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_C8_CPO_JUMP_LEVEL,
            PB_SCONFIG_C8_CPO_JUMP_LEVEL_START_BIT,
            (PB_SCONFIG_C8_CPO_JUMP_LEVEL_END_BIT-
             PB_SCONFIG_C8_CPO_JUMP_LEVEL_START_BIT+1));

        // cpo_rty_level
        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_C8_CPO_RTY_LEVEL,
            PB_SCONFIG_C8_CPO_RTY_LEVEL_START_BIT,
            (PB_SCONFIG_C8_CPO_RTY_LEVEL_END_BIT-
             PB_SCONFIG_C8_CPO_RTY_LEVEL_START_BIT+1));

        // p7_sleep_backoff
        if (ver2 || ver3)
        {
            rc_ecmd |= data.insertFromRight(
                PB_SCONFIG_C8_P7_SLEEP_BACKOFF,
                PB_SCONFIG_C8_P7_SLEEP_BACKOFF_START_BIT,
                (PB_SCONFIG_C8_P7_SLEEP_BACKOFF_END_BIT-
                 PB_SCONFIG_C8_P7_SLEEP_BACKOFF_START_BIT+1));
        }

        // rty_percentage
        // include_lpc_rty
        if (ver3)
        {
            rc_ecmd |= data.insertFromRight(
                PB_SCONFIG_C8_RTY_PERCENTAGE,
                PB_SCONFIG_C8_RTY_PERCENTAGE_START_BIT,
                (PB_SCONFIG_C8_RTY_PERCENTAGE_END_BIT-
                 PB_SCONFIG_C8_RTY_PERCENTAGE_START_BIT+1));

            rc_ecmd |= data.writeBit(
                PB_SCONFIG_C8_INCLUDE_LPC_RTY_BIT,
                PB_SCONFIG_C8_INCLUDE_LPC_RTY?1:0);
        }

        if (rc_ecmd)
        {
            FAPI_ERR("proc_build_smp_set_sconfig_c8: Error 0x%x setting up PB Serial Configuration load register data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // call common routine to program chain
        rc = proc_build_smp_set_sconfig(
            i_smp_chip,
            pb_sconfig_c8_def,
            data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_sconfig_c8: Error from proc_build_smp_set_sconfig");
            break;
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_build_smp_set_sconfig_c8: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: program PB serial SCOM chain (center #9)
// parameters: i_smp_chip => structure encapsulating SMP chip
// returns: FAPI_RC_SUCCESS if register programming is successful,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_set_sconfig_c9(
    const proc_build_smp_chip& i_smp_chip)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0x0;
    ecmdDataBufferBase data(64);
    uint8_t ux_scope_arb_mode_lfsr_on_starvation_else_rr = 0;
    uint8_t ux_scope_arb_mode_rr = 0;
    uint8_t ux_scope_arb_mode;
    uint8_t ux_local_arb_mode_rr = 0;
    uint8_t ux_local_arb_mode;

    // mark function entry
    FAPI_DBG("proc_build_smp_set_sconfig_c9: Start");

    do
    {
        // build register content
        // cp_starve_limit
        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_C9_CP_STARVE_LIMIT,
            PB_SCONFIG_C9_CP_STARVE_LIMIT_START_BIT,
            (PB_SCONFIG_C9_CP_STARVE_LIMIT_END_BIT-
             PB_SCONFIG_C9_CP_STARVE_LIMIT_START_BIT+1));

        // gp_starve_limit
        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_C9_GP_STARVE_LIMIT,
            PB_SCONFIG_C9_GP_STARVE_LIMIT_START_BIT,
            (PB_SCONFIG_C9_GP_STARVE_LIMIT_END_BIT-
             PB_SCONFIG_C9_GP_STARVE_LIMIT_START_BIT+1));

        // rgp_starve_limit
        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_C9_RGP_STARVE_LIMIT,
            PB_SCONFIG_C9_RGP_STARVE_LIMIT_START_BIT,
            (PB_SCONFIG_C9_RGP_STARVE_LIMIT_END_BIT-
             PB_SCONFIG_C9_RGP_STARVE_LIMIT_START_BIT+1));

        // sp_starve_limit
        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_C9_SP_STARVE_LIMIT,
            PB_SCONFIG_C9_SP_STARVE_LIMIT_START_BIT,
            (PB_SCONFIG_C9_SP_STARVE_LIMIT_END_BIT-
             PB_SCONFIG_C9_SP_STARVE_LIMIT_START_BIT+1));

        // fp_starve_limit
        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_C9_FP_STARVE_LIMIT,
            PB_SCONFIG_C9_FP_STARVE_LIMIT_START_BIT,
            (PB_SCONFIG_C9_FP_STARVE_LIMIT_END_BIT-
             PB_SCONFIG_C9_FP_STARVE_LIMIT_START_BIT+1));

        // ux_scope_arb_mode
        rc = FAPI_ATTR_GET(ATTR_CHIP_EC_FEATURE_FBC_UX_SCOPE_ARB_LFSR_ON_STARVATION_ELSE_RR,
                           &(i_smp_chip.chip->this_chip),
                           ux_scope_arb_mode_lfsr_on_starvation_else_rr);
        if (!rc.ok())
        {
            FAPI_ERR("Error querying Chip EC feature: ATTR_CHIP_EC_FEATURE_FBC_UX_SCOPE_ARB_LFSR_ON_STARVATION_ELSE_RR");
            break;
        }

        rc = FAPI_ATTR_GET(ATTR_CHIP_EC_FEATURE_FBC_UX_SCOPE_ARB_RR,
                           &(i_smp_chip.chip->this_chip),
                           ux_scope_arb_mode_rr);
        if (!rc.ok())
        {
            FAPI_ERR("Error querying Chip EC feature: ATTR_CHIP_EC_FEATURE_FBC_UX_SCOPE_ARB_RR");
            break;
        }

        if (ux_scope_arb_mode_lfsr_on_starvation_else_rr)
        {
            ux_scope_arb_mode = PB_SCONFIG_C9_UX_SCOPE_ARB_MODE_LFSR_ON_STARVATION_ELSE_RR;
        }
        else if (ux_scope_arb_mode_rr)
        {
            ux_scope_arb_mode = PB_SCONFIG_C9_UX_SCOPE_ARB_MODE_RR;
        }
        else
        {
            ux_scope_arb_mode = PB_SCONFIG_C9_UX_SCOPE_ARB_MODE_LFSR;
        }

        rc_ecmd |= data.insertFromRight(
            ux_scope_arb_mode,
            PB_SCONFIG_C9_UX_SCOPE_ARB_MODE_START_BIT,
            (PB_SCONFIG_C9_UX_SCOPE_ARB_MODE_END_BIT-
             PB_SCONFIG_C9_UX_SCOPE_ARB_MODE_START_BIT+1));

        // ux_local_arb_mode
        rc = FAPI_ATTR_GET(ATTR_CHIP_EC_FEATURE_FBC_UX_LOCAL_ARB_RR,
                           &(i_smp_chip.chip->this_chip),
                           ux_local_arb_mode_rr);
        if (!rc.ok())
        {
            FAPI_ERR("Error querying Chip EC feature: ATTR_CHIP_EC_FEATURE_FBC_UX_LOCAL_ARB_RR");
            break;
        }

        if (ux_local_arb_mode_rr)
        {
            ux_local_arb_mode = PB_SCONFIG_C9_UX_LOCAL_ARB_MODE_RR;
        }
        else
        {
            ux_local_arb_mode = PB_SCONFIG_C9_UX_LOCAL_ARB_MODE_LFSR_ON_STARVATION_ELSE_RR;
        }

        rc_ecmd |= data.insertFromRight(
            ux_local_arb_mode,
            PB_SCONFIG_C9_UX_LOCAL_ARB_MODE_START_BIT,
            (PB_SCONFIG_C9_UX_LOCAL_ARB_MODE_END_BIT-
             PB_SCONFIG_C9_UX_LOCAL_ARB_MODE_START_BIT+1));

        if (rc_ecmd)
        {
            FAPI_ERR("proc_build_smp_set_sconfig_c9: Error 0x%x setting up PB Serial Configuration load register data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // call common routine to program chain
        rc = proc_build_smp_set_sconfig(i_smp_chip, PB_SCONFIG_C9_DEF, data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_sconfig_c9: Error from proc_build_smp_set_sconfig");
            break;
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_build_smp_set_sconfig_c9: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: program PB serial SCOM chain (center #10)
// parameters: i_smp_chip => structure encapsulating SMP chip
//             i_smp      => structure encapsulating SMP
// returns: FAPI_RC_SUCCESS if register programming is successful,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_set_sconfig_c10(
    const proc_build_smp_chip& i_smp_chip,
    const proc_build_smp_system& i_smp)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0x0;
    ecmdDataBufferBase data(64);
    uint8_t ver2;
    uint32_t PB_SCONFIG_C10_CMD_CPU_RATIO_START_BIT[PB_SCONFIG_NUM_CPU_RATIOS];
    uint32_t PB_SCONFIG_C10_CMD_CPU_RATIO_END_BIT[PB_SCONFIG_NUM_CPU_RATIOS];
    uint32_t PB_SCONFIG_C10_DAT_X_LINK_HOLDOFF_ENABLE_BIT;
    uint32_t PB_SCONFIG_C10_DAT_A_LINK_HOLDOFF_ENABLE_BIT;
    uint32_t PB_SCONFIG_C10_DAT_LINK_HOLDOFF_MULTIPLIER_BIT;
    proc_build_smp_sconfig_def pb_sconfig_c10_def;

    // mark function entry
    FAPI_DBG("proc_build_smp_set_sconfig_c10: Start");

    do
    {
        rc = FAPI_ATTR_GET(ATTR_CHIP_EC_FEATURE_FBC_SERIAL_SCOM_C10_VER2,
                           &(i_smp_chip.chip->this_chip),
                           ver2);
        if (!rc.ok())
        {
            FAPI_ERR("Error querying Chip EC feature: ATTR_CHIP_EC_FEATURE_FBC_SERIAL_SCOM_C10_VER2");
            break;
        }

        if (ver2)
        {
            for (uint8_t l = 0; l < PB_SCONFIG_NUM_CPU_RATIOS; l++)
            {
                PB_SCONFIG_C10_CMD_CPU_RATIO_START_BIT[l] = PB_SCONFIG_C10_CMD_CPU_RATIO_START_BIT_VER2[l];
                PB_SCONFIG_C10_CMD_CPU_RATIO_END_BIT[l]   = PB_SCONFIG_C10_CMD_CPU_RATIO_END_BIT_VER2[l];
            }
            PB_SCONFIG_C10_DAT_X_LINK_HOLDOFF_ENABLE_BIT   = PB_SCONFIG_C10_DAT_X_LINK_HOLDOFF_ENABLE_BIT_VER2;
            PB_SCONFIG_C10_DAT_A_LINK_HOLDOFF_ENABLE_BIT   = PB_SCONFIG_C10_DAT_A_LINK_HOLDOFF_ENABLE_BIT_VER2;
            PB_SCONFIG_C10_DAT_LINK_HOLDOFF_MULTIPLIER_BIT = PB_SCONFIG_C10_DAT_LINK_HOLDOFF_MULTIPLIER_BIT_VER2;
            pb_sconfig_c10_def = PB_SCONFIG_C10_DEF_VER2;
        }
        else
        {
            for (uint8_t l = 0; l < PB_SCONFIG_NUM_CPU_RATIOS; l++)
            {
                PB_SCONFIG_C10_CMD_CPU_RATIO_START_BIT[l] = PB_SCONFIG_C10_CMD_CPU_RATIO_START_BIT_VER1[l];
                PB_SCONFIG_C10_CMD_CPU_RATIO_END_BIT[l]   = PB_SCONFIG_C10_CMD_CPU_RATIO_END_BIT_VER1[l];
            }
            PB_SCONFIG_C10_DAT_X_LINK_HOLDOFF_ENABLE_BIT   = 0xFF;
            PB_SCONFIG_C10_DAT_A_LINK_HOLDOFF_ENABLE_BIT   = 0xFF;
            PB_SCONFIG_C10_DAT_LINK_HOLDOFF_MULTIPLIER_BIT = 0xFF;
            pb_sconfig_c10_def = PB_SCONFIG_C10_DEF_VER1;
        }

        // build register content
        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_C10_CMD_CPU_RATIO_QUARTER,
            PB_SCONFIG_C10_CMD_CPU_RATIO_START_BIT[0],
            (PB_SCONFIG_C10_CMD_CPU_RATIO_END_BIT[0]-
             PB_SCONFIG_C10_CMD_CPU_RATIO_START_BIT[0]+1));

        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_C10_CMD_CPU_RATIO_HALF,
            PB_SCONFIG_C10_CMD_CPU_RATIO_START_BIT[1],
            (PB_SCONFIG_C10_CMD_CPU_RATIO_END_BIT[1]-
             PB_SCONFIG_C10_CMD_CPU_RATIO_START_BIT[1]+1));

        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_C10_CMD_CPU_RATIO_TABLE[i_smp.nom_cpu_delay],
            PB_SCONFIG_C10_CMD_CPU_RATIO_START_BIT[2],
            (PB_SCONFIG_C10_CMD_CPU_RATIO_END_BIT[2]-
             PB_SCONFIG_C10_CMD_CPU_RATIO_START_BIT[2]+1));

        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_C10_CMD_CPU_RATIO_TABLE[i_smp.full_cpu_delay],
            PB_SCONFIG_C10_CMD_CPU_RATIO_START_BIT[3],
            (PB_SCONFIG_C10_CMD_CPU_RATIO_END_BIT[3]-
             PB_SCONFIG_C10_CMD_CPU_RATIO_START_BIT[3]+1));

        // x_link_holdoff_enable
        // a_link_holdoff_enable
        // link_holdoff_mutlipler
        if (ver2)
        {
            rc_ecmd |= data.writeBit(
                PB_SCONFIG_C10_DAT_X_LINK_HOLDOFF_ENABLE_BIT,
                PB_SCONFIG_C10_DAT_X_LINK_HOLDOFF_ENABLE);

            rc_ecmd |= data.writeBit(
                PB_SCONFIG_C10_DAT_A_LINK_HOLDOFF_ENABLE_BIT,
                PB_SCONFIG_C10_DAT_A_LINK_HOLDOFF_ENABLE);

            rc_ecmd |= data.writeBit(
                PB_SCONFIG_C10_DAT_LINK_HOLDOFF_MULTIPLIER_BIT,
                PB_SCONFIG_C10_DAT_LINK_HOLDOFF_MULTIPLIER);
        }

        if (rc_ecmd)
        {
            FAPI_ERR("proc_build_smp_set_sconfig_c10: Error 0x%x setting up PB Serial Configuration load register data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // call common routine to program chain
        rc = proc_build_smp_set_sconfig(i_smp_chip, pb_sconfig_c10_def, data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_sconfig_c10: Error from proc_build_smp_set_sconfig");
            break;
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_build_smp_set_sconfig_c10: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: program PB serial SCOM chain (center #11)
// parameters: i_smp_chip => structure encapsulating SMP chip
//             i_smp      => structure encapsulating SMP
// returns: FAPI_RC_SUCCESS if register programming is successful,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_set_sconfig_c11(
    const proc_build_smp_chip& i_smp_chip,
    const proc_build_smp_system& i_smp)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0x0;
    ecmdDataBufferBase data(64);

    // mark function entry
    FAPI_DBG("proc_build_smp_set_sconfig_c11: Start");

    do
    {
        // build register content
        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_C11_RSP_CPU_RATIO_QUARTER,
            PB_SCONFIG_C11_RSP_CPU_RATIO_START_BIT[0],
            (PB_SCONFIG_C11_RSP_CPU_RATIO_END_BIT[0]-
             PB_SCONFIG_C11_RSP_CPU_RATIO_START_BIT[0]+1));

        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_C11_RSP_CPU_RATIO_HALF,
            PB_SCONFIG_C11_RSP_CPU_RATIO_START_BIT[1],
            (PB_SCONFIG_C11_RSP_CPU_RATIO_END_BIT[1]-
             PB_SCONFIG_C11_RSP_CPU_RATIO_START_BIT[1]+1));

        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_C11_RSP_CPU_RATIO_TABLE[i_smp.nom_cpu_delay],
            PB_SCONFIG_C11_RSP_CPU_RATIO_START_BIT[2],
            (PB_SCONFIG_C11_RSP_CPU_RATIO_END_BIT[2]-
             PB_SCONFIG_C11_RSP_CPU_RATIO_START_BIT[2]+1));

        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_C11_RSP_CPU_RATIO_TABLE[i_smp.full_cpu_delay],
            PB_SCONFIG_C11_RSP_CPU_RATIO_START_BIT[3],
            (PB_SCONFIG_C11_RSP_CPU_RATIO_END_BIT[3]-
             PB_SCONFIG_C11_RSP_CPU_RATIO_START_BIT[3]+1));

        if (rc_ecmd)
        {
            FAPI_ERR("proc_build_smp_set_sconfig_c11: Error 0x%x setting up PB Serial Configuration load register data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // call common routine to program chain
        rc = proc_build_smp_set_sconfig(i_smp_chip, PB_SCONFIG_C11_DEF, data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_sconfig_c11: Error from proc_build_smp_set_sconfig");
            break;
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_build_smp_set_sconfig_c11: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: program PB serial SCOM chain (west/east #0)
// parameters: i_smp_chip => structure encapsulating SMP chip
//             i_smp      => structure encapsulating SMP
// returns: FAPI_RC_SUCCESS if register programming is successful,
//          RC_PROC_BUILD_SMP_CORE_CEILING_RATIO_ERR if cache/nest frequency
//              ratio is unsupported,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_set_sconfig_we0(
    const proc_build_smp_chip& i_smp_chip,
    const proc_build_smp_system& i_smp)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0x0;
    ecmdDataBufferBase data(64);

    // mark function entry
    FAPI_DBG("proc_build_smp_set_sconfig_we0: Start");

    // set "safe" mode defaults
    uint8_t cmd_c2i_done_launch  = 0x0;              // rc_p1
    uint8_t crsp_i2c_dval_launch = 0x0;              // wc_p1
    uint8_t data_i2c_dval_launch = 0x0;              // wc_p1
    uint8_t data_c2i_done_launch = 0x0;              // rc_p1
    uint8_t data_c2i_dctr_launch = 0x0;              // rc_p1
    uint8_t rcmd_i2c_dval_launch = 0x0;              // wc_p1

    do
    {
        // build register content
        if (!i_smp.async_safe_mode)
        {
            // "performance" mode settings
            cmd_c2i_done_launch  = 0x6;              // rc_m1
            crsp_i2c_dval_launch = 0x3;              // wc
            data_i2c_dval_launch = 0x2;              // wc_m1
            data_c2i_done_launch = 0x3;              // rc
            data_c2i_dctr_launch = 0x3;              // rc
            rcmd_i2c_dval_launch = 0x3;              // wc

            switch (i_smp.core_ceiling_ratio)
            {
                // dial back if ceiling is over 2x
                case PROC_BUILD_SMP_CORE_RATIO_8_8:
                    if (i_smp.freq_core_ceiling > (2 * i_smp.freq_pb))
                    {
                        FAPI_DBG("proc_build_smp_set_sconfig_we0: Clamping CRSP/RCMD/DATA i2c dval to safe mode based on ceiling frequency");
                        crsp_i2c_dval_launch = 0x0;  // rc_p1
                        rcmd_i2c_dval_launch = 0x0;  // rc_p1
                        data_i2c_dval_launch = 0x3;  // wc
                    }
                    break;
                case PROC_BUILD_SMP_CORE_RATIO_7_8:
                case PROC_BUILD_SMP_CORE_RATIO_6_8:
                case PROC_BUILD_SMP_CORE_RATIO_5_8:
                case PROC_BUILD_SMP_CORE_RATIO_4_8:
                case PROC_BUILD_SMP_CORE_RATIO_2_8:
                    break;
                default:
                    FAPI_ERR("proc_build_smp_set_sconfig_we0: Unsupported core ceiling frequency ratio enum (%d)",
                             i_smp.core_ceiling_ratio);
                    const uint32_t& FREQ_PB = i_smp.freq_pb;
                    const uint32_t& FREQ_CORE_CEILING = i_smp.freq_core_ceiling;
                    const uint32_t& CORE_CEILING_RATIO = i_smp.core_ceiling_ratio;
                    FAPI_SET_HWP_ERROR(rc,
                        RC_PROC_BUILD_SMP_CORE_CEILING_RATIO_ERR);
                    break;
            }
        }
        if (rc)
        {
            break;
        }

        // cmd_c2i_done_launch
        rc_ecmd |= data.insertFromRight(
            cmd_c2i_done_launch,
            PB_SCONFIG_WE0_CMD_C2I_DONE_LAUNCH_START_BIT,
            (PB_SCONFIG_WE0_CMD_C2I_DONE_LAUNCH_END_BIT-
             PB_SCONFIG_WE0_CMD_C2I_DONE_LAUNCH_START_BIT+1));

        // cmd_c2i_late_rd_mode
        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE0_CMD_C2I_LATE_RD_MODE_BIT,
            PB_SCONFIG_WE0_CMD_C2I_LATE_RD_MODE?1:0);

        // cmd_c2i_delay_sp_rd
        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_WE0_CMD_C2I_DELAY_SP_RD,
            PB_SCONFIG_WE0_CMD_C2I_DELAY_SP_RD_START_BIT,
            (PB_SCONFIG_WE0_CMD_C2I_DELAY_SP_RD_END_BIT-
             PB_SCONFIG_WE0_CMD_C2I_DELAY_SP_RD_START_BIT+1));

        // cmd_c2i_spare_mode
        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE0_CMD_C2I_SPARE_MODE_BIT,
            PB_SCONFIG_WE0_CMD_C2I_SPARE_MODE?1:0);

        // prsp_c2i_done_launch
        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE0_PRSP_C2I_DONE_LAUNCH_BIT,
            PB_SCONFIG_WE0_PRSP_C2I_DONE_LAUNCH);

        // prsp_c2i_hw070772_dis
        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE0_PRSP_C2I_HW070772_DIS_BIT,
            PB_SCONFIG_WE0_PRSP_C2I_HW070772_DIS?1:0);

        // prsp_c2i_nop_mode
        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_WE0_PRSP_C2I_NOP_MODE,
            PB_SCONFIG_WE0_PRSP_C2I_NOP_MODE_START_BIT,
            (PB_SCONFIG_WE0_PRSP_C2I_NOP_MODE_END_BIT-
             PB_SCONFIG_WE0_PRSP_C2I_NOP_MODE_START_BIT+1));

        // prsp_c2i_spare_mode
        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE0_PRSP_C2I_SPARE_MODE_BIT,
            PB_SCONFIG_WE0_PRSP_C2I_SPARE_MODE?1:0);

        // crsp_i2c_dval_launch
        rc_ecmd |= data.insertFromRight(
            crsp_i2c_dval_launch,
            PB_SCONFIG_WE0_CRSP_I2C_DVAL_LAUNCH_START_BIT,
            (PB_SCONFIG_WE0_CRSP_I2C_DVAL_LAUNCH_END_BIT-
             PB_SCONFIG_WE0_CRSP_I2C_DVAL_LAUNCH_START_BIT+1));

        // crsp_i2c_hshake
        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE0_CRSP_I2C_HSHAKE_BIT,
            PB_SCONFIG_WE0_CRSP_I2C_HSHAKE?1:0);

        // crsp_i2c_spare_mode
        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE0_CRSP_I2C_SPARE_MODE_BIT,
            PB_SCONFIG_WE0_CRSP_I2C_SPARE_MODE?1:0);

        // data_i2c_dval_launch
        rc_ecmd |= data.insertFromRight(
            data_i2c_dval_launch,
            PB_SCONFIG_WE0_DATA_I2C_DVAL_LAUNCH_START_BIT,
            (PB_SCONFIG_WE0_DATA_I2C_DVAL_LAUNCH_END_BIT-
             PB_SCONFIG_WE0_DATA_I2C_DVAL_LAUNCH_START_BIT+1));

        // data_i2c_spare_mode
        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE0_DATA_I2C_SPARE_MODE_BIT,
            PB_SCONFIG_WE0_DATA_I2C_SPARE_MODE?1:0);

        // data_i2c_force_fa_alloc
        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE0_DATA_I2C_FORCE_FA_ALLOC_BIT,
            PB_SCONFIG_WE0_DATA_I2C_FORCE_FA_ALLOC?1:0);

        // data_c2i_done_launch
        rc_ecmd |= data.insertFromRight(
            data_c2i_done_launch,
            PB_SCONFIG_WE0_DATA_C2I_DONE_LAUNCH_START_BIT,
            (PB_SCONFIG_WE0_DATA_C2I_DONE_LAUNCH_END_BIT-
             PB_SCONFIG_WE0_DATA_C2I_DONE_LAUNCH_START_BIT+1));

        // data_c2i_initial_req_dly_launch
        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_WE0_DATA_C2I_INITIAL_REQ_DLY,
            PB_SCONFIG_WE0_DATA_C2I_INITIAL_REQ_DLY_START_BIT,
            (PB_SCONFIG_WE0_DATA_C2I_INITIAL_REQ_DLY_END_BIT-
             PB_SCONFIG_WE0_DATA_C2I_INITIAL_REQ_DLY_START_BIT+1));

        // data_c2i_dctr_launch
        rc_ecmd |= data.insertFromRight(
            data_c2i_dctr_launch,
            PB_SCONFIG_WE0_DATA_C2I_DCTR_LAUNCH_START_BIT,
            (PB_SCONFIG_WE0_DATA_C2I_DCTR_LAUNCH_END_BIT-
             PB_SCONFIG_WE0_DATA_C2I_DCTR_LAUNCH_START_BIT+1));

        // data_c2i_outstanding_req_count
        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE0_DATA_C2I_OUTSTANDING_REQ_COUNT_BIT,
            PB_SCONFIG_WE0_DATA_C2I_OUTSTANDING_REQ_COUNT?1:0);

        // data_c2i_req_id_assignment_mode
        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE0_DATA_C2I_REQ_ID_ASSIGNMENT_MODE_BIT,
            PB_SCONFIG_WE0_DATA_C2I_REQ_ID_ASSIGNMENT_MODE?1:0);

        // data_c2i_allow_fragmentation_mode
        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE0_DATA_C2I_ALLOW_FRAGMENTATION_BIT,
            PB_SCONFIG_WE0_DATA_C2I_ALLOW_FRAGMENTATION?1:0);

        // data_c2i_serial_dreq_id_mode
        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE0_DATA_C2I_SERIAL_DREQ_ID_BIT,
            PB_SCONFIG_WE0_DATA_C2I_SERIAL_DREQ_ID?1:0);

        // data_c2i_spare_mode
        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE0_DATA_C2I_SPARE_MODE_BIT,
            PB_SCONFIG_WE0_DATA_C2I_SPARE_MODE?1:0);

        // rcmd_i2c_dval_launch
        rc_ecmd |= data.insertFromRight(
            rcmd_i2c_dval_launch,
            PB_SCONFIG_WE0_RCMD_I2C_DVAL_LAUNCH_START_BIT,
            (PB_SCONFIG_WE0_RCMD_I2C_DVAL_LAUNCH_END_BIT-
             PB_SCONFIG_WE0_RCMD_I2C_DVAL_LAUNCH_START_BIT+1));

        // rcmd_i2c_hshake
        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE0_RCMD_I2C_HSHAKE_BIT,
            PB_SCONFIG_WE0_RCMD_I2C_HSHAKE?1:0);

        // rcmd_i2c_spare_mode
        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE0_RCMD_I2C_SPARE_MODE_BIT,
            PB_SCONFIG_WE0_RCMD_I2C_SPARE_MODE?1:0);

        // fp_i2c_dval_launch
        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_WE0_FP_I2C_DVAL_LAUNCH,
            PB_SCONFIG_WE0_FP_I2C_DVAL_LAUNCH_START_BIT,
            (PB_SCONFIG_WE0_FP_I2C_DVAL_LAUNCH_END_BIT-
             PB_SCONFIG_WE0_FP_I2C_DVAL_LAUNCH_START_BIT+1));

        // fp_i2c_hshake
        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE0_FP_I2C_HSHAKE_BIT,
            PB_SCONFIG_WE0_FP_I2C_HSHAKE?1:0);

        // fp_i2c_spare_mode
        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE0_FP_I2C_SPARE_MODE_BIT,
            PB_SCONFIG_WE0_FP_I2C_SPARE_MODE?1:0);

        // fp_c2i_done_launch
        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE0_FP_C2I_DONE_LAUNCH_BIT,
            PB_SCONFIG_WE0_FP_C2I_DONE_LAUNCH);

        // fp_c2i_spare_mode
        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE0_FP_C2I_SPARE_MODE_BIT,
            PB_SCONFIG_WE0_FP_C2I_SPARE_MODE?1:0);

        // cpu_delay_full
        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_WE0_CPU_DELAY_TABLE[i_smp.full_cpu_delay],
            PB_SCONFIG_WE0_CPU_DELAY_FULL_START_BIT,
            (PB_SCONFIG_WE0_CPU_DELAY_FULL_END_BIT-
             PB_SCONFIG_WE0_CPU_DELAY_FULL_START_BIT+1));

        // cpu_delay_nom
        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_WE0_CPU_DELAY_TABLE[i_smp.nom_cpu_delay],
            PB_SCONFIG_WE0_CPU_DELAY_NOM_START_BIT,
            (PB_SCONFIG_WE0_CPU_DELAY_NOM_END_BIT-
             PB_SCONFIG_WE0_CPU_DELAY_NOM_START_BIT+1));

        if (rc_ecmd)
        {
            FAPI_ERR("proc_build_smp_set_sconfig_we0: Error 0x%x setting up PB Serial Configuration load register data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // call common routine to program chain
        rc = proc_build_smp_set_sconfig(i_smp_chip, PB_SCONFIG_WE0_DEF, data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_sconfig_we0: Error from proc_build_smp_set_sconfig");
            break;
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_build_smp_set_sconfig_we0: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: program PB serial SCOM chain (west/east #1)
// parameters: i_smp_chip => structure encapsulating SMP chip
//             i_smp      => structure encapsulating SMP
// returns: FAPI_RC_SUCCESS if register programming is successful,
//          RC_PROC_BUILD_SMP_CORE_FLOOR_RATIO_ERR if cache/nest frequency
//              ratio is unsupported,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_set_sconfig_we1(
    const proc_build_smp_chip& i_smp_chip,
    const proc_build_smp_system& i_smp)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0x0;
    ecmdDataBufferBase data(64);


    // mark function entry
    FAPI_DBG("proc_build_smp_set_sconfig_we1: Start");

    // set "safe" mode defaults
    uint8_t cmd_c2i_dval_launch = 0x0;               // wc_p1
    uint8_t crsp_i2c_done_launch = 0x0;              // rc_p1
    uint8_t crsp_i2c_pty_rd_capture = 0x0;           // rc
    uint8_t data_i2c_done_launch = 0x0;              // rc_p1
    uint8_t data_i2c_dctr_launch = 0x0;              // rc_p1
    uint8_t data_c2i_dval_launch = 0x0;              // wc_p1
    uint8_t rcmd_i2c_done_launch = 0x0;              // rc_p1
    uint8_t rcmd_i2c_pty_rd_capture = 0x0;           // rc
    uint8_t attr_proc_pbiex_async_sel = fapi::ENUM_ATTR_PROC_PBIEX_ASYNC_SEL_SEL0;

    do
    {
        // build register content
        if (!i_smp.async_safe_mode)
        {
            // "performance" mode settings
            crsp_i2c_done_launch = 0x1;              // rc
            crsp_i2c_pty_rd_capture = 0x1;           // rc_p1
            data_i2c_done_launch = 0x2;              // rc_m1
            rcmd_i2c_done_launch = 0x1;              // rc
            rcmd_i2c_pty_rd_capture = 0x1;           // rc_p1

            switch (i_smp.core_floor_ratio)
            {
                case PROC_BUILD_SMP_CORE_RATIO_8_8:
                case PROC_BUILD_SMP_CORE_RATIO_7_8:
                case PROC_BUILD_SMP_CORE_RATIO_6_8:
                case PROC_BUILD_SMP_CORE_RATIO_5_8:
                    cmd_c2i_dval_launch = 0x3;       // wc
                    data_i2c_dctr_launch = 0x1;      // rc_m2
                    data_c2i_dval_launch = 0x2;      // wc_m1
                    attr_proc_pbiex_async_sel = fapi::ENUM_ATTR_PROC_PBIEX_ASYNC_SEL_SEL0;
                    break;
                case PROC_BUILD_SMP_CORE_RATIO_4_8:
                    cmd_c2i_dval_launch = 0x3;       // wc
                    data_i2c_dctr_launch = 0x2;      // rc_m1
                    data_c2i_dval_launch = 0x3;      // wc
                    attr_proc_pbiex_async_sel = fapi::ENUM_ATTR_PROC_PBIEX_ASYNC_SEL_SEL1;
                    break;
                case PROC_BUILD_SMP_CORE_RATIO_2_8:
                    cmd_c2i_dval_launch = 0x0;       // wc_p1
                    data_i2c_dctr_launch = 0x3;      // rc
                    data_c2i_dval_launch = 0x0;      // wc_p1
                    attr_proc_pbiex_async_sel = fapi::ENUM_ATTR_PROC_PBIEX_ASYNC_SEL_SEL2;
                    break;
                default:
                    FAPI_ERR("proc_build_smp_set_sconfig_we1: Unsupported core floor frequency ratio enum (%d)",
                             i_smp.core_floor_ratio);
                    const uint32_t& FREQ_PB = i_smp.freq_pb;
                    const uint32_t& FREQ_CORE_FLOOR = i_smp.freq_core_floor;
                    const uint32_t& CORE_FLOOR_RATIO = i_smp.core_floor_ratio;
                    FAPI_SET_HWP_ERROR(rc,
                        RC_PROC_BUILD_SMP_CORE_FLOOR_RATIO_ERR);
                    break;
            }
        }
        if (rc)
        {
            break;
        }

        // write async select attribute
        rc = FAPI_ATTR_SET(ATTR_PROC_PBIEX_ASYNC_SEL,
                           NULL,
                           attr_proc_pbiex_async_sel);
        if (rc)
        {
            FAPI_ERR("proc_build_smp_set_sconfig_we1: Error writing ATTR_PROC_PBIEX_ASYNC_SEL");
            break;
        }

        // cmd_c2i_dval_launch
        rc_ecmd |= data.insertFromRight(
            cmd_c2i_dval_launch,
            PB_SCONFIG_WE1_CMD_C2I_DVAL_LAUNCH_START_BIT,
            (PB_SCONFIG_WE1_CMD_C2I_DVAL_LAUNCH_END_BIT-
             PB_SCONFIG_WE1_CMD_C2I_DVAL_LAUNCH_START_BIT+1));

        // cmd_c2i_early_req_mode
        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE1_CMD_C2I_EARLY_REQ_MODE_BIT,
            PB_SCONFIG_WE1_CMD_C2I_EARLY_REQ_MODE?1:0);

        // cmd_c2i_spare_bit
        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE1_CMD_C2I_SPARE_BIT,
            PB_SCONFIG_WE1_CMD_C2I_SPARE?1:0);

        // cmd_c2i_spare_mode_bit
        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE1_CMD_C2I_SPARE_MODE_BIT,
            PB_SCONFIG_WE1_CMD_C2I_SPARE_MODE?1:0);

        // prsp_c2i_dval_launch
        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_WE1_PRSP_C2I_DVAL_LAUNCH,
            PB_SCONFIG_WE1_PRSP_C2I_DVAL_LAUNCH_START_BIT,
            (PB_SCONFIG_WE1_PRSP_C2I_DVAL_LAUNCH_END_BIT-
             PB_SCONFIG_WE1_PRSP_C2I_DVAL_LAUNCH_START_BIT+1));

        // prsp_c2i_hshake
        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE1_PRSP_C2I_HSHAKE_BIT,
            PB_SCONFIG_WE1_PRSP_C2I_HSHAKE?1:0);

        // prsp_c2i_spare mode
        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE1_PRSP_C2I_SPARE_MODE_BIT,
            PB_SCONFIG_WE1_PRSP_C2I_SPARE_MODE?1:0);

        // crsp_i2c_done_launch
        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE1_CRSP_I2C_DONE_LAUNCH_BIT,
            crsp_i2c_done_launch);

        // crsp_i2c_pty_rd_capture
        rc_ecmd |= data.insertFromRight(
            crsp_i2c_pty_rd_capture,
            PB_SCONFIG_WE1_CRSP_I2C_PTY_RD_CAPTURE_START_BIT,
            (PB_SCONFIG_WE1_CRSP_I2C_PTY_RD_CAPTURE_END_BIT-
             PB_SCONFIG_WE1_CRSP_I2C_PTY_RD_CAPTURE_START_BIT+1));

        // crsp_i2c_spare mode
        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE1_CRSP_I2C_SPARE_MODE_BIT,
            PB_SCONFIG_WE1_CRSP_I2C_SPARE_MODE?1:0);

        // data_i2c_done_launch
        rc_ecmd |= data.insertFromRight(
            data_i2c_done_launch,
            PB_SCONFIG_WE1_DATA_I2C_DONE_LAUNCH_START_BIT,
            (PB_SCONFIG_WE1_DATA_I2C_DONE_LAUNCH_END_BIT-
             PB_SCONFIG_WE1_DATA_I2C_DONE_LAUNCH_START_BIT+1));

        // data_i2c_dctr_launch
        rc_ecmd |= data.insertFromRight(
            data_i2c_dctr_launch,
            PB_SCONFIG_WE1_DATA_I2C_DCTR_LAUNCH_START_BIT,
            (PB_SCONFIG_WE1_DATA_I2C_DCTR_LAUNCH_END_BIT-
             PB_SCONFIG_WE1_DATA_I2C_DCTR_LAUNCH_START_BIT+1));

        // data_i2c_spare mode
        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE1_DATA_I2C_SPARE_MODE_BIT,
            PB_SCONFIG_WE1_DATA_I2C_SPARE_MODE?1:0);

        // data_c2i_dval_launch
        rc_ecmd |= data.insertFromRight(
            data_c2i_dval_launch,
            PB_SCONFIG_WE1_DATA_C2I_DVAL_LAUNCH_START_BIT,
            (PB_SCONFIG_WE1_DATA_C2I_DVAL_LAUNCH_END_BIT-
             PB_SCONFIG_WE1_DATA_C2I_DVAL_LAUNCH_START_BIT+1));

        // data_c2i_dreq_launch
        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_WE1_DATA_C2I_DREQ_LAUNCH,
            PB_SCONFIG_WE1_DATA_C2I_DREQ_LAUNCH_START_BIT,
            (PB_SCONFIG_WE1_DATA_C2I_DREQ_LAUNCH_END_BIT-
             PB_SCONFIG_WE1_DATA_C2I_DREQ_LAUNCH_START_BIT+1));

        // data_c2i_spare mode
        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE1_DATA_C2I_SPARE_MODE_BIT,
            PB_SCONFIG_WE1_DATA_C2I_SPARE_MODE?1:0);

        // rcmd_i2c_done_launch
        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE1_RCMD_I2C_DONE_LAUNCH_BIT,
            rcmd_i2c_done_launch);

        // rcmd_i2c_l3_not_use_dcbfl
        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE1_RCMD_I2C_L3_NOT_USE_DCBFL_BIT,
            PB_SCONFIG_WE1_RCMD_I2C_L3_NOT_USE_DCBFL?1:0);

        // rcmd_i2c_pty_rd_capture_launch
        rc_ecmd |= data.insertFromRight(
            rcmd_i2c_pty_rd_capture,
            PB_SCONFIG_WE1_RCMD_I2C_PTY_RD_CAPTURE_START_BIT,
            (PB_SCONFIG_WE1_RCMD_I2C_PTY_RD_CAPTURE_END_BIT-
             PB_SCONFIG_WE1_RCMD_I2C_PTY_RD_CAPTURE_START_BIT+1));

        // rcmd_i2c_pty_inject
        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE1_RCMD_I2C_PTY_INJECT_BIT,
            PB_SCONFIG_WE1_RCMD_I2C_PTY_INJECT?1:0);

        // rcmd_i2c_spare_mode
        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE1_RCMD_I2C_SPARE_MODE_BIT,
            PB_SCONFIG_WE1_RCMD_I2C_SPARE_MODE?1:0);

        // fp_i2c_done_launch
        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE1_FP_I2C_DONE_LAUNCH_BIT,
            PB_SCONFIG_WE1_FP_I2C_DONE_LAUNCH?1:0);

        // fp_i2c_spare
        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE1_FP_I2C_SPARE_BIT,
            PB_SCONFIG_WE1_FP_I2C_SPARE?1:0);

        // fp_i2c_pty_rd_capture_launch
        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_WE1_FP_I2C_PTY_RD_CAPTURE,
            PB_SCONFIG_WE1_FP_I2C_PTY_RD_CAPTURE_START_BIT,
            (PB_SCONFIG_WE1_FP_I2C_PTY_RD_CAPTURE_END_BIT-
             PB_SCONFIG_WE1_FP_I2C_PTY_RD_CAPTURE_START_BIT+1));

        // fp_i2c_spare_mode
        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE1_FP_I2C_SPARE_MODE_BIT,
            PB_SCONFIG_WE1_FP_I2C_SPARE_MODE?1:0);

        // fp_c2i_dval_launch
        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_WE1_FP_C2I_DVAL_LAUNCH,
            PB_SCONFIG_WE1_FP_C2I_DVAL_LAUNCH_START_BIT,
            (PB_SCONFIG_WE1_FP_C2I_DVAL_LAUNCH_END_BIT-
             PB_SCONFIG_WE1_FP_C2I_DVAL_LAUNCH_START_BIT+1));

        // fp_c2i_hshake
        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE1_FP_C2I_HSHAKE_BIT,
            PB_SCONFIG_WE1_FP_C2I_HSHAKE?1:0);

        // fp_c2i_spare_mode
        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE1_FP_C2I_SPARE_MODE_BIT,
            PB_SCONFIG_WE1_FP_C2I_SPARE_MODE?1:0);

        if (rc_ecmd)
        {
            FAPI_ERR("proc_build_smp_set_sconfig_we1: Error 0x%x setting up PB Serial Configuration load register data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // call common routine to program chain
        rc = proc_build_smp_set_sconfig(i_smp_chip, PB_SCONFIG_WE1_DEF, data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_sconfig_we1: Error from proc_build_smp_set_sconfig");
            break;
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_build_smp_set_sconfig_we1: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: program PB serial SCOM chain (west/east #5)
// parameters: i_smp_chip => structure encapsulating SMP chip
//             i_smp      => structure encapsulating SMP
// returns: FAPI_RC_SUCCESS if register programming is successful,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_set_sconfig_we5(
    const proc_build_smp_chip& i_smp_chip,
    const proc_build_smp_system& i_smp)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0x0;
    ecmdDataBufferBase data(64);
    uint8_t ver2 = 0x0;

    // mark function entry
    FAPI_DBG("proc_build_smp_set_sconfig_we5: Start");

    do
    {
        rc = FAPI_ATTR_GET(ATTR_CHIP_EC_FEATURE_FBC_SERIAL_SCOM_WE5_VER2,
                           &(i_smp_chip.chip->this_chip),
                           ver2);
        if (!rc.ok())
        {
            FAPI_ERR("Error querying Chip EC feature: ATTR_CHIP_EC_FEATURE_FBC_SERIAL_SCOM_WE5_VER2");
            break;
        }

        // build register content
        // pb_cfg_lock_on_links
        uint32_t PB_SCONFIG_WE5_LOCK_ON_LINKS_BIT =
            (ver2)?
            (PB_SCONFIG_WE5_LOCK_ON_LINKS_BIT_VER2):
            (PB_SCONFIG_WE5_LOCK_ON_LINKS_BIT_VER1);

        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE5_LOCK_ON_LINKS_BIT,
            PB_SCONFIG_WE5_LOCK_ON_LINKS?1:0);

        // pb_cfg_x_on_link_tok_agg_threshold
        uint32_t PB_SCONFIG_WE5_X_ON_LINK_TOK_AGG_THRESHOLD_START_BIT =
            (ver2)?
            (PB_SCONFIG_WE5_X_ON_LINK_TOK_AGG_THRESHOLD_START_BIT_VER2):
            (PB_SCONFIG_WE5_X_ON_LINK_TOK_AGG_THRESHOLD_START_BIT_VER1);

        uint32_t PB_SCONFIG_WE5_X_ON_LINK_TOK_AGG_THRESHOLD_END_BIT =
            (ver2)?
            (PB_SCONFIG_WE5_X_ON_LINK_TOK_AGG_THRESHOLD_END_BIT_VER2):
            (PB_SCONFIG_WE5_X_ON_LINK_TOK_AGG_THRESHOLD_END_BIT_VER1);

        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_WE5_X_ON_LINK_TOK_AGG_THRESHOLD,
            PB_SCONFIG_WE5_X_ON_LINK_TOK_AGG_THRESHOLD_START_BIT,
            (PB_SCONFIG_WE5_X_ON_LINK_TOK_AGG_THRESHOLD_END_BIT-
             PB_SCONFIG_WE5_X_ON_LINK_TOK_AGG_THRESHOLD_START_BIT+1));

        // pb_cfg_x_off_link_tok_agg_threshold
        uint32_t PB_SCONFIG_WE5_X_OFF_LINK_TOK_AGG_THRESHOLD_START_BIT =
            (ver2)?
            (PB_SCONFIG_WE5_X_OFF_LINK_TOK_AGG_THRESHOLD_START_BIT_VER2):
            (PB_SCONFIG_WE5_X_OFF_LINK_TOK_AGG_THRESHOLD_START_BIT_VER1);

        uint32_t PB_SCONFIG_WE5_X_OFF_LINK_TOK_AGG_THRESHOLD_END_BIT =
            (ver2)?
            (PB_SCONFIG_WE5_X_OFF_LINK_TOK_AGG_THRESHOLD_END_BIT_VER2):
            (PB_SCONFIG_WE5_X_OFF_LINK_TOK_AGG_THRESHOLD_END_BIT_VER1);

        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_WE5_X_OFF_LINK_TOK_AGG_THRESHOLD,
            PB_SCONFIG_WE5_X_OFF_LINK_TOK_AGG_THRESHOLD_START_BIT,
            (PB_SCONFIG_WE5_X_OFF_LINK_TOK_AGG_THRESHOLD_END_BIT-
             PB_SCONFIG_WE5_X_OFF_LINK_TOK_AGG_THRESHOLD_START_BIT+1));

        // pb_cfg_x_a_link_tok_agg_threshold
        uint32_t PB_SCONFIG_WE5_A_LINK_TOK_AGG_THRESHOLD_START_BIT =
            (ver2)?
            (PB_SCONFIG_WE5_A_LINK_TOK_AGG_THRESHOLD_START_BIT_VER2):
            (PB_SCONFIG_WE5_A_LINK_TOK_AGG_THRESHOLD_START_BIT_VER1);

        uint32_t PB_SCONFIG_WE5_A_LINK_TOK_AGG_THRESHOLD_END_BIT =
            (ver2)?
            (PB_SCONFIG_WE5_A_LINK_TOK_AGG_THRESHOLD_END_BIT_VER2):
            (PB_SCONFIG_WE5_A_LINK_TOK_AGG_THRESHOLD_END_BIT_VER1);

        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_WE5_A_LINK_TOK_AGG_THRESHOLD,
            PB_SCONFIG_WE5_A_LINK_TOK_AGG_THRESHOLD_START_BIT,
            (PB_SCONFIG_WE5_A_LINK_TOK_AGG_THRESHOLD_END_BIT-
             PB_SCONFIG_WE5_A_LINK_TOK_AGG_THRESHOLD_START_BIT+1));

        // pb_cfg_x_f_link_tok_agg_threshold
        uint32_t PB_SCONFIG_WE5_F_LINK_TOK_AGG_THRESHOLD_START_BIT =
            (ver2)?
            (PB_SCONFIG_WE5_F_LINK_TOK_AGG_THRESHOLD_START_BIT_VER2):
            (PB_SCONFIG_WE5_F_LINK_TOK_AGG_THRESHOLD_START_BIT_VER1);

        uint32_t PB_SCONFIG_WE5_F_LINK_TOK_AGG_THRESHOLD_END_BIT =
            (ver2)?
            (PB_SCONFIG_WE5_F_LINK_TOK_AGG_THRESHOLD_END_BIT_VER2):
            (PB_SCONFIG_WE5_F_LINK_TOK_AGG_THRESHOLD_END_BIT_VER1);

        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_WE5_F_LINK_TOK_AGG_THRESHOLD,
            PB_SCONFIG_WE5_F_LINK_TOK_AGG_THRESHOLD_START_BIT,
            (PB_SCONFIG_WE5_F_LINK_TOK_AGG_THRESHOLD_END_BIT-
             PB_SCONFIG_WE5_F_LINK_TOK_AGG_THRESHOLD_START_BIT+1));

        // pb_cfg_x_a_link_tok_ind_threshold
        uint32_t PB_SCONFIG_WE5_A_LINK_TOK_IND_THRESHOLD_START_BIT =
            (ver2)?
            (PB_SCONFIG_WE5_A_LINK_TOK_IND_THRESHOLD_START_BIT_VER2):
            (PB_SCONFIG_WE5_A_LINK_TOK_IND_THRESHOLD_START_BIT_VER1);

        uint32_t PB_SCONFIG_WE5_A_LINK_TOK_IND_THRESHOLD_END_BIT =
            (ver2)?
            (PB_SCONFIG_WE5_A_LINK_TOK_IND_THRESHOLD_END_BIT_VER2):
            (PB_SCONFIG_WE5_A_LINK_TOK_IND_THRESHOLD_END_BIT_VER1);

        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_WE5_A_LINK_TOK_IND_THRESHOLD,
            PB_SCONFIG_WE5_A_LINK_TOK_IND_THRESHOLD_START_BIT,
            (PB_SCONFIG_WE5_A_LINK_TOK_IND_THRESHOLD_END_BIT-
             PB_SCONFIG_WE5_A_LINK_TOK_IND_THRESHOLD_START_BIT+1));

        // pb_cfg_passthru_enable
        uint32_t PB_SCONFIG_WE5_PASSTHRU_ENABLE_BIT =
            (ver2)?
            (PB_SCONFIG_WE5_PASSTHRU_ENABLE_BIT_VER2):
            (PB_SCONFIG_WE5_PASSTHRU_ENABLE_BIT_VER1);

        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE5_PASSTHRU_ENABLE_BIT,
            PB_SCONFIG_WE5_PASSTHRU_ENABLE?1:0);

        // pb_cfg_passthru_x_priority
        uint32_t PB_SCONFIG_WE5_PASSTHRU_X_PRIORITY_START_BIT =
            (ver2)?
            (PB_SCONFIG_WE5_PASSTHRU_X_PRIORITY_START_BIT_VER2):
            (PB_SCONFIG_WE5_PASSTHRU_X_PRIORITY_START_BIT_VER1);

        uint32_t PB_SCONFIG_WE5_PASSTHRU_X_PRIORITY_END_BIT =
            (ver2)?
            (PB_SCONFIG_WE5_PASSTHRU_X_PRIORITY_END_BIT_VER2):
            (PB_SCONFIG_WE5_PASSTHRU_X_PRIORITY_END_BIT_VER1);

        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_WE5_PASSTHRU_X_PRIORITY,
            PB_SCONFIG_WE5_PASSTHRU_X_PRIORITY_START_BIT,
            (PB_SCONFIG_WE5_PASSTHRU_X_PRIORITY_END_BIT-
             PB_SCONFIG_WE5_PASSTHRU_X_PRIORITY_START_BIT+1));

        // pb_cfg_passthru_a_priority
        uint32_t PB_SCONFIG_WE5_PASSTHRU_A_PRIORITY_START_BIT =
            (ver2)?
            (PB_SCONFIG_WE5_PASSTHRU_A_PRIORITY_START_BIT_VER2):
            (PB_SCONFIG_WE5_PASSTHRU_A_PRIORITY_START_BIT_VER1);

        uint32_t PB_SCONFIG_WE5_PASSTHRU_A_PRIORITY_END_BIT =
            (ver2)?
            (PB_SCONFIG_WE5_PASSTHRU_A_PRIORITY_END_BIT_VER2):
            (PB_SCONFIG_WE5_PASSTHRU_A_PRIORITY_END_BIT_VER1);

        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_WE5_PASSTHRU_A_PRIORITY,
            PB_SCONFIG_WE5_PASSTHRU_A_PRIORITY_START_BIT,
            (PB_SCONFIG_WE5_PASSTHRU_A_PRIORITY_END_BIT-
             PB_SCONFIG_WE5_PASSTHRU_A_PRIORITY_START_BIT+1));

        // pb_cfg_a_tok_init
        uint32_t PB_SCONFIG_WE5_A_TOK_INIT_START_BIT =
            (ver2)?
            (PB_SCONFIG_WE5_A_TOK_INIT_START_BIT_VER2):
            (PB_SCONFIG_WE5_A_TOK_INIT_START_BIT_VER1);

        uint32_t PB_SCONFIG_WE5_A_TOK_INIT_END_BIT =
            (ver2)?
            (PB_SCONFIG_WE5_A_TOK_INIT_END_BIT_VER2):
            (PB_SCONFIG_WE5_A_TOK_INIT_END_BIT_VER1);

        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_WE5_A_TOK_INIT,
            PB_SCONFIG_WE5_A_TOK_INIT_START_BIT,
            (PB_SCONFIG_WE5_A_TOK_INIT_END_BIT-
             PB_SCONFIG_WE5_A_TOK_INIT_START_BIT+1));

        // pb_cfg_f_tok_init
        uint32_t PB_SCONFIG_WE5_F_TOK_INIT_START_BIT =
            (ver2)?
            (PB_SCONFIG_WE5_F_TOK_INIT_START_BIT_VER2):
            (PB_SCONFIG_WE5_F_TOK_INIT_START_BIT_VER1);

        uint32_t PB_SCONFIG_WE5_F_TOK_INIT_END_BIT =
            (ver2)?
            (PB_SCONFIG_WE5_F_TOK_INIT_END_BIT_VER2):
            (PB_SCONFIG_WE5_F_TOK_INIT_END_BIT_VER1);
        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_WE5_F_TOK_INIT,
            PB_SCONFIG_WE5_F_TOK_INIT_START_BIT,
            (PB_SCONFIG_WE5_F_TOK_INIT_END_BIT-
             PB_SCONFIG_WE5_F_TOK_INIT_START_BIT+1));

        // pb_cfg_em_fp_enable
        uint32_t PB_SCONFIG_WE5_EM_FP_ENABLE_BIT =
            (ver2)?
            (PB_SCONFIG_WE5_EM_FP_ENABLE_BIT_VER2):
            (PB_SCONFIG_WE5_EM_FP_ENABLE_BIT_VER1);

        rc_ecmd |= data.writeBit(
            PB_SCONFIG_WE5_EM_FP_ENABLE_BIT,
            PB_SCONFIG_WE5_EM_FP_ENABLE?1:0);

        // spare
        uint32_t PB_SCONFIG_WE5_SPARE_START_BIT =
            (ver2)?
            (PB_SCONFIG_WE5_SPARE_START_BIT_VER2):
            (PB_SCONFIG_WE5_SPARE_START_BIT_VER1);

        uint32_t PB_SCONFIG_WE5_SPARE_END_BIT =
            (ver2)?
            (PB_SCONFIG_WE5_SPARE_END_BIT_VER2):
            (PB_SCONFIG_WE5_SPARE_END_BIT_VER1);

        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_WE5_SPARE,
            PB_SCONFIG_WE5_SPARE_START_BIT,
            (PB_SCONFIG_WE5_SPARE_END_BIT-
             PB_SCONFIG_WE5_SPARE_START_BIT+1));

        // pb_cfg_a_ind_threshold
        if (ver2)
        {
            rc_ecmd |= data.writeBit(
                PB_SCONFIG_WE5_A_IND_THRESHOLD_BIT_VER2,
                PB_SCONFIG_WE5_A_IND_THRESHOLD?1:0);
        }

        // pb_cfg_mem_stv_priority
        uint32_t PB_SCONFIG_WE5_MEM_STV_PRIORITY_START_BIT =
            (ver2)?
            (PB_SCONFIG_WE5_MEM_STV_PRIORITY_START_BIT_VER2):
            (PB_SCONFIG_WE5_MEM_STV_PRIORITY_START_BIT_VER1);

        uint32_t PB_SCONFIG_WE5_MEM_STV_PRIORITY_END_BIT =
            (ver2)?
            (PB_SCONFIG_WE5_MEM_STV_PRIORITY_END_BIT_VER2):
            (PB_SCONFIG_WE5_MEM_STV_PRIORITY_END_BIT_VER1);

        rc_ecmd |= data.insertFromRight(
            PB_SCONFIG_WE5_MEM_STV_PRIORITY,
            PB_SCONFIG_WE5_MEM_STV_PRIORITY_START_BIT,
            (PB_SCONFIG_WE5_MEM_STV_PRIORITY_END_BIT-
             PB_SCONFIG_WE5_MEM_STV_PRIORITY_START_BIT+1));

        // pb_cfg_x_off_set
        if (ver2)
        {
            rc_ecmd |= data.writeBit(
                PB_SCONFIG_WE5_X_OFF_SEL_BIT_VER2,
                PB_SCONFIG_WE5_X_OFF_SEL?1:0);
        }

        if (rc_ecmd)
        {
            FAPI_ERR("proc_build_smp_set_sconfig_we5: Error 0x%x setting up PB Serial Configuration load register data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // call common routine to program chain
        rc = proc_build_smp_set_sconfig(
            i_smp_chip,
            (ver2)?(PB_SCONFIG_WE5_DEF_VER2):(PB_SCONFIG_WE5_DEF_VER1),
            data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_sconfig_we5: Error from proc_build_smp_set_sconfig");
            break;
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_build_smp_set_sconfig_we5: End");
    return rc;
}


// NOTE: see comments above function prototype in header
fapi::ReturnCode proc_build_smp_set_fbc_cd(
    proc_build_smp_system& i_smp)
{
    fapi::ReturnCode rc;
    std::map<proc_fab_smp_node_id, proc_build_smp_node>::iterator n_iter;
    std::map<proc_fab_smp_chip_id, proc_build_smp_chip>::iterator p_iter;

    // mark function entry
    FAPI_DBG("proc_build_smp_set_fbc_cd: Start");

    for (n_iter = i_smp.nodes.begin();
         (n_iter != i_smp.nodes.end()) && (rc.ok());
         n_iter++)
    {
        for (p_iter = n_iter->second.chips.begin();
             (p_iter != n_iter->second.chips.end()) && (rc.ok());
             p_iter++)
        {
            // program center chains
            rc = proc_build_smp_set_sconfig_c4(p_iter->second);
            if (!rc.ok())
            {
                FAPI_ERR("proc_build_smp_set_fbc_cd: Error from proc_build_smp_set_sconfig_c4");
                break;
            }

            rc = proc_build_smp_set_sconfig_c5(p_iter->second);
            if (!rc.ok())
            {
                FAPI_ERR("proc_build_smp_set_fbc_cd: Error from proc_build_smp_set_sconfig_c5");
                break;
            }

            rc = proc_build_smp_set_sconfig_c6(p_iter->second);
            if (!rc.ok())
            {
                FAPI_ERR("proc_build_smp_set_fbc_cd: Error from proc_build_smp_set_sconfig_c6");
                break;
            }

            rc = proc_build_smp_set_sconfig_c7(p_iter->second);
            if (!rc.ok())
            {
                FAPI_ERR("proc_build_smp_set_fbc_cd: Error from proc_build_smp_set_sconfig_c7");
                break;
            }

            rc = proc_build_smp_set_sconfig_c8(p_iter->second);
            if (!rc.ok())
            {
                FAPI_ERR("proc_build_smp_set_fbc_cd: Error from proc_build_smp_set_sconfig_c8");
                break;
            }

            rc = proc_build_smp_set_sconfig_c9(p_iter->second);
            if (!rc.ok())
            {
                FAPI_ERR("proc_build_smp_set_fbc_cd: Error from proc_build_smp_set_sconfig_c9");
                break;
            }

            rc = proc_build_smp_set_sconfig_c10(p_iter->second, i_smp);
            if (!rc.ok())
            {
                FAPI_ERR("proc_build_smp_set_fbc_cd: Error from proc_build_smp_set_sconfig_c10");
                break;
            }

            rc = proc_build_smp_set_sconfig_c11(p_iter->second, i_smp);
            if (!rc.ok())
            {
                FAPI_ERR("proc_build_smp_set_fbc_cd: Error from proc_build_smp_set_sconfig_c11");
                break;
            }

            // program east/west chains
            rc = proc_build_smp_set_sconfig_we0(p_iter->second, i_smp);
            if (!rc.ok())
            {
                FAPI_ERR("proc_build_smp_set_fbc_cd: Error from proc_build_smp_set_sconfig_we0");
                break;
            }

            rc = proc_build_smp_set_sconfig_we1(p_iter->second, i_smp);
            if (!rc.ok())
            {
                FAPI_ERR("proc_build_smp_set_fbc_cd: Error from proc_build_smp_set_sconfig_we1");
                break;
            }

            rc = proc_build_smp_set_sconfig_we5(p_iter->second, i_smp);
            if (!rc.ok())
            {
                FAPI_ERR("proc_build_smp_set_fbc_cd: Error from proc_build_smp_set_sconfig_we5");
                break;
            }

            // issue single switch CD to force all updates to occur
            rc = proc_build_smp_switch_cd(p_iter->second, i_smp);
            if (!rc.ok())
            {
                FAPI_ERR("proc_build_smp_set_fbc_cd: Error from proc_build_smp_switch_cd");
                break;
            }
        }
    }

    // mark function exit
    FAPI_DBG("proc_build_smp_set_fbc_cd: End");
    return rc;
}


} // extern "C"
