/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_c_1.H $          */
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

#ifndef __p10_scom_c_1_H_
#define __p10_scom_c_1_H_


namespace scomt
{
namespace c
{


static const uint64_t EC_PC_COMMON_SPR_SPATTN_MASK = 0x2002049aull;
// c/reg00001.H

static const uint64_t EC_PC_SCR3 = 0x20020489ull;
// c/reg00001.H

static const uint64_t EC_PC_TRACE1_TR0_CONFIG = 0x20020a42ull;

static const uint32_t EC_PC_TRACE1_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
// c/reg00001.H

static const uint64_t EC_PC_TRACE2_TR0_CONFIG_1 = 0x20020a84ull;

static const uint32_t EC_PC_TRACE2_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00001.H

static const uint64_t EC_SD_SDP_SDCR_UNIT_HOLD_OUT0 = 0x20020640ull;
// c/reg00001.H

static const uint64_t L2TRA_TR1_CONFIG = 0x20020082ull;

static const uint32_t L2TRA_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t L2TRA_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t L2TRA_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t L2TRA_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t L2TRA_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t L2TRA_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t L2TRA_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t L2TRA_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t L2TRA_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t L2TRA_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t L2TRA_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t L2TRA_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t L2TRA_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t L2TRA_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
// c/reg00001.H

static const uint64_t L2TRA_TR1_CONFIG_5 = 0x20020088ull;

static const uint32_t L2TRA_TR1_CONFIG_5_C = 0;
static const uint32_t L2TRA_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t L2TRA_TR1_CONFIG_5_D = 24;
static const uint32_t L2TRA_TR1_CONFIG_5_D_LEN = 24;
// c/reg00001.H

static const uint64_t L3_MISC_L3CERRS_FIR_REG_RWX = 0x20010600ull;
static const uint64_t L3_MISC_L3CERRS_FIR_REG_WOX_AND = 0x20010601ull;
static const uint64_t L3_MISC_L3CERRS_FIR_REG_WOX_OR = 0x20010602ull;

static const uint32_t L3_MISC_L3CERRS_FIR_REG_RDDSP_SEGR_MODE_ALL_MEM_UNAVAIL_ERR = 0;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_CHIP_CONTAINED_ERR = 1;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_FIR_SPARE2 = 2;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_DRAM_POS_WORDLINE_FAIL = 3;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_CAC_RD_CE_DET_NOT_LINDEL_REQ = 4;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_CAC_RD_UE_DET = 5;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_CAC_RD_SUE_DET = 6;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_CAC_WR_DATA_CE_FROM_PB = 7;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_CAC_WR_DATA_UE_FROM_PB = 8;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_CAC_WR_DATA_SUE_FROM_PB = 9;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_CAC_WR_DATA_CE_FROM_L2 = 10;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_CAC_WR_DATA_UE_FROM_L2 = 11;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_CAC_WR_DATA_SUE_FROM_L2_OR_WIHPC = 12;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_DIR_RD_CE_DET = 13;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_DIR_RD_UE_DET = 14;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_DIR_RD_PHANTOM_ERROR = 15;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ADDR_ERR = 16;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ADDR_ERR = 17;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_ADDR_HANG_DETECTED = 18;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_LRU_INVAL_CNT = 19;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_FIR_SPARE20 = 20;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_FIR_SPARE21 = 21;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_FIR_SPARE22 = 22;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_MACH_HANG_DETECTED = 23;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_HW_CONTROL_ERR = 24;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_SNP_CACHE_INHIBIT_ERR = 25;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_LINE_DEL_CE_DONE = 26;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_LRU_ERROR = 28;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_ALL_MEMBERS_DELETED_ERROR = 29;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_PB_MAST_WR_ACK_DEAD = 31;
static const uint32_t L3_MISC_L3CERRS_FIR_REG_PB_MAST_RD_ACK_DEAD = 32;
// c/reg00001.H

static const uint64_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD = 0x20010626ull;

static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08_VALID = 0;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09_VALID = 1;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10_VALID = 2;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11_VALID = 3;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12_VALID = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13_VALID = 5;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14_VALID = 6;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15_VALID = 7;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08 = 8;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_08_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09 = 12;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_09_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10 = 16;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_10_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11 = 20;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_11_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12 = 24;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_12_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13 = 28;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_13_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14 = 32;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_14_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15 = 36;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL1_SCOM_RD_15_LEN = 4;
// c/reg00001.H

static const uint64_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2 = 0x20010656ull;

static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16_VAL = 0;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17_VAL = 1;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18_VAL = 2;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19_VAL = 3;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20_VAL = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21_VAL = 5;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22_VAL = 6;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23_VAL = 7;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16 = 8;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_16_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17 = 12;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_17_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18 = 16;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_18_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19 = 20;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_19_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20 = 24;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_20_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21 = 28;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_21_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22 = 32;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_22_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23 = 36;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG2_23_LEN = 4;
// c/reg00001.H

static const uint64_t QME_DCSR = 0x200e0870ull;

static const uint32_t QME_DCSR_PLS_T0 = 0;
static const uint32_t QME_DCSR_PLS_T0_LEN = 4;
static const uint32_t QME_DCSR_PLS_T1 = 4;
static const uint32_t QME_DCSR_PLS_T1_LEN = 4;
static const uint32_t QME_DCSR_PLS_T2 = 8;
static const uint32_t QME_DCSR_PLS_T2_LEN = 4;
static const uint32_t QME_DCSR_PLS_T3 = 12;
static const uint32_t QME_DCSR_PLS_T3_LEN = 4;
static const uint32_t QME_DCSR_SL_T0 = 16;
static const uint32_t QME_DCSR_SL_T0_LEN = 2;
static const uint32_t QME_DCSR_SL_T1 = 18;
static const uint32_t QME_DCSR_SL_T1_LEN = 2;
static const uint32_t QME_DCSR_SL_T2 = 20;
static const uint32_t QME_DCSR_SL_T2_LEN = 2;
static const uint32_t QME_DCSR_SL_T3 = 22;
static const uint32_t QME_DCSR_SL_T3_LEN = 2;
static const uint32_t QME_DCSR_SRESET_MSR_S = 24;
// c/reg00001.H

static const uint64_t QME_PMCRS = 0x200e0860ull;

static const uint32_t QME_PMCRS_QME_PMCRS_DATA = 0;
static const uint32_t QME_PMCRS_QME_PMCRS_DATA_LEN = 64;
// c/reg00001.H

static const uint64_t QME_PMSRS = 0x200e0864ull;

static const uint32_t QME_PMSRS_QME_PMSRS_DATA = 0;
static const uint32_t QME_PMSRS_QME_PMSRS_DATA_LEN = 64;
// c/reg00001.H

static const uint64_t QME_PSCRS2 = 0x200e0858ull;

static const uint32_t QME_PSCRS2_DPDES_EXIT_ENABLE = 0;
static const uint32_t QME_PSCRS2_SD = 1;
static const uint32_t QME_PSCRS2_ESL = 2;
static const uint32_t QME_PSCRS2_EC = 3;
static const uint32_t QME_PSCRS2_PSLL = 4;
static const uint32_t QME_PSCRS2_PSLL_LEN = 4;
static const uint32_t QME_PSCRS2_HYP_VIRT_EXIT_ENABLE = 8;
static const uint32_t QME_PSCRS2_UV_DB_EXIT_ENABLE = 9;
static const uint32_t QME_PSCRS2_HYP_DB_EXIT_ENABLE = 10;
static const uint32_t QME_PSCRS2_EXT_EXIT_ENABLE = 11;
static const uint32_t QME_PSCRS2_DEC_EXIT_ENABLE = 12;
static const uint32_t QME_PSCRS2_HMI_EXIT_ENABLE = 13;
static const uint32_t QME_PSCRS2_ = 14;
static const uint32_t QME_PSCRS2__LEN = 2;
static const uint32_t QME_PSCRS2_MTL = 16;
static const uint32_t QME_PSCRS2_MTL_LEN = 4;
static const uint32_t QME_PSCRS2_RL = 20;
static const uint32_t QME_PSCRS2_RL_LEN = 4;
static const uint32_t QME_PSCRS2_PLS = 24;
static const uint32_t QME_PSCRS2_PLS_LEN = 4;
// c/reg00001.H

}
}
#include "c/reg00001.H"
#endif
