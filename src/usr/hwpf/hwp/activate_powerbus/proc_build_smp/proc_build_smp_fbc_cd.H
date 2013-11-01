/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/activate_powerbus/proc_build_smp/proc_build_smp_fbc_cd.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: proc_build_smp_fbc_cd.H,v 1.11 2013/09/26 18:01:39 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_build_smp_fbc_cd.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_build_smp_fbc_cd.H
// *! DESCRIPTION : Fabric configuration (hotplug, CD) functions (FAPI)
// *!
// *! OWNER NAME  : Joe McGill    Email: jmcgill@us.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_BUILD_SMP_FBC_CD_H_
#define _PROC_BUILD_SMP_FBC_CD_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "proc_build_smp.H"
#include "p8_scom_addresses.H"

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

const uint32_t PB_SCONFIG_C4_GP_LO_RTY_THRESHOLD = 0x8;
const uint32_t PB_SCONFIG_C4_GP_HI_RTY_THRESHOLD = 0x6;
const uint32_t PB_SCONFIG_C4_RGP_LO_RTY_THRESHOLD = 0x8;
const uint32_t PB_SCONFIG_C4_RGP_HI_RTY_THRESHOLD = 0x6;
const uint32_t PB_SCONFIG_C4_SP_LO_RTY_THRESHOLD = 0x8;


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

const uint32_t PB_SCONFIG_C5_SP_HI_RTY_THRESHOLD = 0x6;
const uint32_t PB_SCONFIG_C5_GP_CRESP_SAMPLE_TIME = 256;
const uint32_t PB_SCONFIG_C5_RGP_CRESP_SAMPLE_TIME = 256;
const uint32_t PB_SCONFIG_C5_SP_CRESP_SAMPLE_TIME = 256;


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

const proc_build_smp_sconfig_def PB_SCONFIG_C8_DEF = { 0x8, 37, false, { false, true, false } };

const uint32_t PB_SCONFIG_C8_HANG_CMD_RATE_START_BIT[PB_SCONFIG_NUM_HANG_LEVELS] = { 27, 31, 35, 39, 43, 47, 51 };
const uint32_t PB_SCONFIG_C8_HANG_CMD_RATE_END_BIT[PB_SCONFIG_NUM_HANG_LEVELS]   = { 30, 34, 38, 42, 46, 50, 54 };
const uint32_t PB_SCONFIG_C8_CPO_JUMP_LEVEL_START_BIT = 55;
const uint32_t PB_SCONFIG_C8_CPO_JUMP_LEVEL_END_BIT = 57;
const uint32_t PB_SCONFIG_C8_CPO_RTY_LEVEL_START_BIT = 58;
const uint32_t PB_SCONFIG_C8_CPO_RTY_LEVEL_END_BIT = 63;

const uint8_t  PB_SCONFIG_C8_HANG_CMD_RATE[PB_SCONFIG_NUM_HANG_LEVELS] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
const uint32_t PB_SCONFIG_C8_CPO_JUMP_LEVEL = 0x3;
const uint32_t PB_SCONFIG_C8_CPO_RTY_LEVEL = 0xF;


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

const uint8_t PB_SCONFIG_C9_CP_STARVE_LIMIT  = 0x80;
const uint8_t PB_SCONFIG_C9_GP_STARVE_LIMIT  = 0x80;
const uint8_t PB_SCONFIG_C9_RGP_STARVE_LIMIT = 0x80;
const uint8_t PB_SCONFIG_C9_SP_STARVE_LIMIT  = 0x80;
const uint8_t PB_SCONFIG_C9_FP_STARVE_LIMIT  = 0x80;
const uint8_t PB_SCONFIG_C9_UX_SCOPE_ARB_MODE = 0x0; // LFSR_ONLY
const uint8_t PB_SCONFIG_C9_UX_LOCAL_ARB_MODE = 0x2; // LFSR_ON_STARVATION_ELSE_RR


//
// PBH_CMD_CENTRAL_ARB (center, chain #10) field/bit definitions
//

const proc_build_smp_sconfig_def PB_SCONFIG_C10_DEF = { 0xA, 20, false, { false, true, false } };

const uint32_t PB_SCONFIG_C10_CMD_CPU_RATIO_START_BIT[PB_SCONFIG_NUM_CPU_RATIOS] = { 59, 54, 49, 44 };
const uint32_t PB_SCONFIG_C10_CMD_CPU_RATIO_END_BIT[PB_SCONFIG_NUM_CPU_RATIOS]   = { 63, 58, 53, 48 };

const uint8_t PB_SCONFIG_C10_CMD_CPU_RATIO[PB_SCONFIG_NUM_CPU_RATIOS] = { 3, 7, 11, 15 };


//
// PBH_RSP_CRESP_ARB (center, chain #11) field/bit definitions
//

const proc_build_smp_sconfig_def PB_SCONFIG_C11_DEF = { 0xB, 20, false, { false, true, false } };

const uint32_t PB_SCONFIG_C11_RSP_CPU_RATIO_START_BIT[PB_SCONFIG_NUM_CPU_RATIOS] = { 59, 54, 49, 44 };
const uint32_t PB_SCONFIG_C11_RSP_CPU_RATIO_END_BIT[PB_SCONFIG_NUM_CPU_RATIOS]   = { 63, 58, 53, 48 };

const uint8_t PB_SCONFIG_C11_RSP_CPU_RATIO[PB_SCONFIG_NUM_CPU_RATIOS] = { 4, 8, 12, 16 };


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
const uint32_t PB_SCONFIG_WE0_CPU_RATIO_TABLE_FULL_START_BIT = 54;
const uint32_t PB_SCONFIG_WE0_CPU_RATIO_TABLE_FULL_END_BIT = 58;
const uint32_t PB_SCONFIG_WE0_CPU_RATIO_TABLE_NOM_START_BIT  = 59;
const uint32_t PB_SCONFIG_WE0_CPU_RATIO_TABLE_NOM_END_BIT = 63;

const uint8_t  PB_SCONFIG_WE0_CMD_C2I_LATE_RD_MODE = true;             // on
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
const uint32_t PB_SCONFIG_WE0_CPU_RATIO_TABLE_FULL = 0x0E;             // 14
const uint32_t PB_SCONFIG_WE0_CPU_RATIO_TABLE_NOM = 0x12;              // 18


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
const uint8_t PB_SCONFIG_WE5_A_LINK_TOK_IND_THRESHOLD = 0x0;         // cnt_0
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

extern "C"
{

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// function: program fabric configuration register (hotplug, C/D set)
// parameters: i_smp => structure encapsulating SMP topology
// returns: FAPI_RC_SUCCESS if register reads are successful and all shadow
//               registers are equivalent,
//          RC_PROC_BUILD_SMP_CORE_FLOOR_RATIO_ERR if cache/nest frequency
//              ratio is unsupported,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_set_fbc_cd(
    proc_build_smp_system& i_smp);


} // extern "C"

#endif // _PROC_BUILD_SMP_FBC_CD_H_
