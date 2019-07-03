/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_c_b.H $          */
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

#ifndef __PPE_HCODE__
    #include "proc_scomt.H"
#endif

#ifndef __p10_scom_c_b_H_
#define __p10_scom_c_b_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


static const uint64_t CPMS_DHDR = 0x200e0e58ull;

static const uint32_t CPMS_DHDR_DPLL_ENCODED_DATA = 32;
static const uint32_t CPMS_DHDR_DPLL_ENCODED_DATA_LEN = 3;
static const uint32_t CPMS_DHDR_DDS_DATA = 35;
static const uint32_t CPMS_DHDR_DDS_DATA_LEN = 5;
static const uint32_t CPMS_DHDR_STOP_STATE_ACTIVE = 60;
static const uint32_t CPMS_DHDR_CORE_SAMPLE_DISABLED = 61;
// c/reg00011.H

static const uint64_t CPMS_L3_PFETSTAT = 0x200e0e24ull;

static const uint32_t CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE = 0;
static const uint32_t CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE = 1;
static const uint32_t CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE = 2;
static const uint32_t CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE = 3;
static const uint32_t CPMS_L3_PFETSTAT_VDD_PFET_ENABLE_ACTUAL = 16;
static const uint32_t CPMS_L3_PFETSTAT_VDD_PFET_ENABLE_ACTUAL_LEN = 8;
static const uint32_t CPMS_L3_PFETSTAT_VCS_PFET_ENABLE_ACTUAL = 24;
static const uint32_t CPMS_L3_PFETSTAT_VCS_PFET_ENABLE_ACTUAL_LEN = 8;
static const uint32_t CPMS_L3_PFETSTAT_SRAM_ENABLE_ACTUAL = 63;
// c/reg00011.H

static const uint64_t EC_LS_LSU_HOLD_OUT_REG2 = 0x200206c2ull;
// c/reg00011.H

static const uint64_t EC_PC_COMMON_SPR_SPATTN_RW = 0x20020499ull;
static const uint64_t EC_PC_COMMON_SPR_SPATTN_WO_AND = 0x20020498ull;
static const uint64_t EC_PC_COMMON_SPR_SPATTN_WO_OR = 0x20020497ull;
// c/reg00011.H

static const uint64_t EC_PC_FIR_CORE_ACTION0 = 0x20020446ull;
// c/reg00011.H

static const uint64_t EC_PC_PMU_SPRCOR_SCOMC = 0x20020408ull;
// c/reg00011.H

static const uint64_t EC_PC_SCR0 = 0x20020486ull;
// c/reg00011.H

static const uint64_t EC_PC_SPURR_FREQ_DETECT_CYC_CNT = 0x2002049full;

static const uint32_t EC_PC_SPURR_FREQ_DETECT_CYC_CNT_CYCLE_COUNT = 0;
static const uint32_t EC_PC_SPURR_FREQ_DETECT_CYC_CNT_CYCLE_COUNT_LEN = 8;
// c/reg00011.H

static const uint64_t EC_PC_TRACE1_TR0_CONFIG_9 = 0x20020a49ull;

static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// c/reg00011.H

static const uint64_t EC_PC_TRACE2_TR0_CONFIG_2 = 0x20020a85ull;

static const uint32_t EC_PC_TRACE2_TR0_CONFIG_2_A = 0;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_2_B = 24;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_2_B_LEN = 24;
// c/reg00011.H

static const uint64_t L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG = 0x2002000dull;

static const uint32_t L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_TRIG = 0;
static const uint32_t L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_DONE = 1;
static const uint32_t L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_SPARE = 2;
static const uint32_t L2_L2MISC_L2CERRS_LINEDEL_TRIG_REG_SPARE_LEN = 2;
// c/reg00011.H

static const uint64_t L3_MISC_L3CERRS_RD_EPSILON_CFG_REG = 0x20010629ull;

static const uint32_t L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER0_EPS_VAL = 0;
static const uint32_t L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER0_EPS_VAL_LEN = 12;
static const uint32_t L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER1_EPS_VAL = 12;
static const uint32_t L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER1_EPS_VAL_LEN = 12;
static const uint32_t L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER2_EPS_VAL = 24;
static const uint32_t L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_WT4CR_RD_TIER2_EPS_VAL_LEN = 12;
static const uint32_t L3_MISC_L3CERRS_RD_EPSILON_CFG_REG_RD_EPS_MODE_SEL_CFG = 36;
// c/reg00011.H

static const uint64_t NC_NCCHTM_NCCHTSC_HTM_MEM = 0x20010681ull;

static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MEM_ALLOC = 0;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MEM_SCOPE = 1;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MEM_SCOPE_LEN = 3;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MEM_PRIORITY = 4;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE_SMALL = 5;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MEM_SPARE = 6;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MEM_SPARE_LEN = 6;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MEM_BASE = 12;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MEM_BASE_LEN = 28;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE = 40;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_MEM_SIZE_LEN = 9;
// c/reg00011.H

static const uint64_t NC_NCCHTM_NCCHTSC_MEM_OP_CTR = 0x20010688ull;
// c/reg00011.H

static const uint64_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1 = 0x20010655ull;

static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08_VAL = 0;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09_VAL = 1;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10_VAL = 2;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11_VAL = 3;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12_VAL = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13_VAL = 5;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14_VAL = 6;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15_VAL = 7;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08 = 8;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09 = 12;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10 = 16;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11 = 20;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12 = 24;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13 = 28;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14 = 32;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15 = 36;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15_LEN = 4;
// c/reg00011.H

static const uint64_t QME_PSCRS1 = 0x200e0854ull;

static const uint32_t QME_PSCRS1_DPDES_EXIT_ENABLE = 0;
static const uint32_t QME_PSCRS1_SD = 1;
static const uint32_t QME_PSCRS1_ESL = 2;
static const uint32_t QME_PSCRS1_EC = 3;
static const uint32_t QME_PSCRS1_PSLL = 4;
static const uint32_t QME_PSCRS1_PSLL_LEN = 4;
static const uint32_t QME_PSCRS1_HYP_VIRT_EXIT_ENABLE = 8;
static const uint32_t QME_PSCRS1_UV_DB_EXIT_ENABLE = 9;
static const uint32_t QME_PSCRS1_HYP_DB_EXIT_ENABLE = 10;
static const uint32_t QME_PSCRS1_EXT_EXIT_ENABLE = 11;
static const uint32_t QME_PSCRS1_DEC_EXIT_ENABLE = 12;
static const uint32_t QME_PSCRS1_HMI_EXIT_ENABLE = 13;
static const uint32_t QME_PSCRS1_ = 14;
static const uint32_t QME_PSCRS1__LEN = 2;
static const uint32_t QME_PSCRS1_MTL = 16;
static const uint32_t QME_PSCRS1_MTL_LEN = 4;
static const uint32_t QME_PSCRS1_RL = 20;
static const uint32_t QME_PSCRS1_RL_LEN = 4;
static const uint32_t QME_PSCRS1_PLS = 24;
static const uint32_t QME_PSCRS1_PLS_LEN = 4;
// c/reg00011.H

static const uint64_t RING_FENCE_MASK_LATCH_REG = 0x20010008ull;

static const uint32_t RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK = 1;
static const uint32_t RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK_LEN = 31;
// c/reg00011.H

#ifndef __PPE_HCODE__
}
}
#include "c/reg00011.H"
#endif
#endif
