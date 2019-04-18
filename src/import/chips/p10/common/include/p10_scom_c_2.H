/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_c_2.H $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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

#include "proc_scomt.H"

#ifndef __p10_scom_c_2_H_
#define __p10_scom_c_2_H_


namespace scomt
{
namespace c
{


static const uint64_t EC_PC_SCR4 = 0x2002048aull;
// c/reg00002.H

static const uint64_t EC_PC_THRCTL_TCTLCOM_HOLD_OUT = 0x20020455ull;
// c/reg00002.H

static const uint64_t EC_PC_TOD_SYNC010 = 0x200204a3ull;

static const uint32_t EC_PC_TOD_SYNC010_CHIP_TOD_STATUS = 60;
static const uint32_t EC_PC_TOD_SYNC010_CHIP_TOD_STATUS_LEN = 4;
// c/reg00002.H

static const uint64_t EC_PC_TOD_SYNC101 = 0x200204a3ull;

static const uint32_t EC_PC_TOD_SYNC101_CHIP_TOD_STATUS = 60;
static const uint32_t EC_PC_TOD_SYNC101_CHIP_TOD_STATUS_LEN = 4;
// c/reg00002.H

static const uint64_t EC_PC_TRACE1_TR0_TRACE_LO_DATA_REG = 0x20020a41ull;

static const uint32_t EC_PC_TRACE1_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t EC_PC_TRACE1_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t EC_PC_TRACE1_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t EC_PC_TRACE1_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t EC_PC_TRACE1_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t EC_PC_TRACE1_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t EC_PC_TRACE1_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t EC_PC_TRACE1_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t EC_PC_TRACE1_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t EC_PC_TRACE1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t EC_PC_TRACE1_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00002.H

static const uint64_t L2_L2MISC_L2CERRS_ERR_RPT0 = 0x20020012ull;

static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RCCO_FSM_PARITY_ERR = 0;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_RLD_BARRIER_ERR = 1;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SNP_ERR = 2;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_TLBIE_ACK_ERR = 3;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_SYNC_ERR = 4;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_NCCTL_VSYNC_ERR = 5;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_TMCTL_TIDX_TEND_LDST_SEQ_ERR = 6;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RVCTL_ERR = 7;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL0_BAD_HPC_ERR = 8;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL1_BAD_HPC_ERR = 9;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL2_BAD_HPC_ERR = 10;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_SRCTL3_BAD_HPC_ERR = 11;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_FSM_REQ_OVERFLOW_ERR = 12;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_PBARB_TRASHMODE_PB_REQ_ERR = 13;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_L3PF_MACH_DONE_ERR = 14;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_TTAG_PERR = 15;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_TTAG_PERR = 16;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_TTAG_PERR = 17;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_TTAG_PERR = 18;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_TTAG_PERR = 19;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_CR0_ATAG_PERR = 20;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_TTAG_PERR = 21;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_CR1_ATAG_PERR = 22;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_TTAG_PERR = 23;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_CR2_ATAG_PERR = 24;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_TTAG_PERR = 25;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_CR3_ATAG_PERR = 26;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD0_ADDR_PERR = 27;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD1_ADDR_PERR = 28;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD2_ADDR_PERR = 29;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RCMD3_ADDR_PERR = 30;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE3_TIMEOUT = 31;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_SAME_ERR = 32;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE4_RCCO_DISP_FAIL = 33;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_9_PEC_PHASE5_TIMEOUT = 34;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_B01_BOTH_ACTIVE = 35;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_PHANTOM_B01_REQ = 36;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_F2_DATA_ERR = 37;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RC_UNEXP_PURG_HIT_ERR = 38;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PBL3_DATA_ERR = 39;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_RCX_UNEXP_IDLE_PB_CRESP_ERR = 40;
static const uint32_t L2_L2MISC_L2CERRS_ERR_RPT0_14_COX_UNEXP_IDLE_PB_CRESP_ERR = 41;
// c/reg00002.H

static const uint64_t L2_L2MISC_L2CERRS_MODE_REG1 = 0x2002000bull;

static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_CE_UE_SUE_ERR_DET_DIS = 0;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_CFG_ECCCK_UE_SUE_DET_DIS = 1;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_CFG_DYN_TRACE_MODE = 2;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_CFG_DYN_TRACE_MODE_LEN = 2;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_HANG_POLL_PULSE_DIV = 4;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_HANG_POLL_PULSE_DIV_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_DATA_POLL_PULSE_DIV = 8;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_DATA_POLL_PULSE_DIV_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_PM_SMT_MODE_ROTATION_EN = 16;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_PM_TID_ROTATE_PLS_RATE = 20;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_PM_TID_ROTATE_PLS_RATE_LEN = 3;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_CFG_MASTER_RTY_BACKOFF_EN = 23;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_EN = 25;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_NUM = 26;
static const uint32_t L2_L2MISC_L2CERRS_MODE_REG1_PM_L23_EVENT_TID_SEL_NUM_LEN = 2;
// c/reg00002.H

static const uint64_t L2_L2MISC_L2CERRS_TOPOTABLE3 = 0x20020017ull;

static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_24_VAL = 0;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_25_VAL = 1;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_26_VAL = 2;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_27_VAL = 3;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_28_VAL = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_29_VAL = 5;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_30_VAL = 6;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_31_VAL = 7;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_24 = 8;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_24_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_25 = 12;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_25_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_26 = 16;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_26_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_27 = 20;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_27_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_28 = 24;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_28_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_29 = 28;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_29_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_30 = 32;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_30_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_31 = 36;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE3_31_LEN = 4;
// c/reg00002.H

static const uint64_t L2TRA_TR1_TRACE_HI_DATA_REG = 0x20020080ull;

static const uint32_t L2TRA_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t L2TRA_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00002.H

static const uint64_t L2TRA_TR1_CONFIG_2 = 0x20020085ull;

static const uint32_t L2TRA_TR1_CONFIG_2_A = 0;
static const uint32_t L2TRA_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t L2TRA_TR1_CONFIG_2_B = 24;
static const uint32_t L2TRA_TR1_CONFIG_2_B_LEN = 24;
// c/reg00002.H

static const uint64_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD = 0x20010625ull;

static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_VALID = 0;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_VALID = 1;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_VALID = 2;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_VALID = 3;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_VALID = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_VALID = 5;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_VALID = 6;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_VALID = 7;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0 = 8;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_0_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1 = 12;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_1_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2 = 16;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_2_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3 = 20;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_3_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4 = 24;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_4_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5 = 28;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_5_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6 = 32;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_6_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7 = 36;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL0_SCOM_RD_7_LEN = 4;
// c/reg00002.H

static const uint64_t NC_NCCHTM_NCCHTSC_HTM_MODE = 0x20010680ull;

static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_HTM_ENABLE = 0;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_CONTENT_SEL = 1;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_CONTENT_SEL_LEN = 2;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE0 = 3;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_CAPTURE = 4;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_CAPTURE_LEN = 6;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_DD1EQUIV = 10;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE_1TO2 = 11;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_SPARE_1TO2_LEN = 2;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_WRAP = 13;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_TSTAMP = 14;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_SINGLE_TSTAMP = 15;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_STALL = 16;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_MARKERS_ONLY = 17;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_GROUP = 18;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_SPARES = 19;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_SPARES_LEN = 5;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_VGTARGET = 24;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MODE_VGTARGET_LEN = 8;
// c/reg00002.H

static const uint64_t NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG = 0x20010650ull;

static const uint32_t NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_EN = 0;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_256K = 1;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_ADDR = 12;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SPEC_BAR_REG_ADDR_LEN = 38;
// c/reg00002.H

}
}
#include "c/reg00002.H"
#endif
