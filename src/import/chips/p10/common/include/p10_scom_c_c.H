/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_c_c.H $          */
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

#ifndef __p10_scom_c_c_H_
#define __p10_scom_c_c_H_


namespace scomt
{
namespace c
{


static const uint64_t CPMS_CGCSR = 0x200e0e00ull;
static const uint64_t CPMS_CGCSR_WO_CLEAR = 0x200e0e02ull;
static const uint64_t CPMS_CGCSR_WO_OR = 0x200e0e03ull;

static const uint32_t CPMS_CGCSR_L3_CLK_SYNC_ENABLE = 0;
static const uint32_t CPMS_CGCSR_CL2_CLK_SYNC_ENABLE = 1;
static const uint32_t CPMS_CGCSR_RESERVED_2_3 = 2;
static const uint32_t CPMS_CGCSR_RESERVED_2_3_LEN = 2;
static const uint32_t CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET = 4;
static const uint32_t CPMS_CGCSR_L3_CLKGLM_SEL = 7;
static const uint32_t CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET = 8;
static const uint32_t CPMS_CGCSR_CL2_CLKGLM_SEL = 11;
static const uint32_t CPMS_CGCSR_L3_CACHE_SB_CTRL = 12;
static const uint32_t CPMS_CGCSR_L3_CACHE_SB_CTRL_LEN = 4;
static const uint32_t CPMS_CGCSR_L3_CLK_SYNC_DONE = 32;
static const uint32_t CPMS_CGCSR_CL2_CLK_SYNC_DONE = 33;
// c/reg00012.H

static const uint64_t EC_IFU_IFRE_IFCER_UNIT_HOLD_OUT0 = 0x20020600ull;
// c/reg00012.H

static const uint64_t EC_PC_COMMON_SPR_SCOMC = 0x20020480ull;

static const uint32_t EC_PC_COMMON_SPR_SCOMC_MODE_CX_SCOMC = 54;
static const uint32_t EC_PC_COMMON_SPR_SCOMC_MODE_CX_SCOMC_LEN = 7;
// c/reg00012.H

static const uint64_t EC_PC_PMU_PMUC_SRC_MASK = 0x20020407ull;
// c/reg00012.H

static const uint64_t EC_PC_SPURR_FREQ_SCALE = 0x200204a0ull;

static const uint32_t EC_PC_SPURR_FREQ_SCALE_OVERRIDE_EN = 0;
static const uint32_t EC_PC_SPURR_FREQ_SCALE_FACTOR = 1;
static const uint32_t EC_PC_SPURR_FREQ_SCALE_FACTOR_LEN = 7;
// c/reg00012.H

static const uint64_t EC_PC_THRCTL_TCTLCOM_RAS_STATUS = 0x20020454ull;
// c/reg00012.H

static const uint64_t L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG = 0x2002000full;

static const uint32_t L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER = 0;
static const uint32_t L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TYPE = 1;
static const uint32_t L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TYPE_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY = 9;
static const uint32_t L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS = 10;
static const uint32_t L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY = 11;
static const uint32_t L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_MEM = 16;
static const uint32_t L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_MEM_LEN = 3;
static const uint32_t L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_CGC = 19;
static const uint32_t L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_CGC_LEN = 9;
static const uint32_t L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK = 28;
static const uint32_t L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR = 29;
// c/reg00012.H

static const uint64_t L2_L2MISC_L2CERRS_WR_EPS_REG = 0x20020011ull;

static const uint32_t L2_L2MISC_L2CERRS_WR_EPS_REG_TIER1_WR_EPS_VALUE = 0;
static const uint32_t L2_L2MISC_L2CERRS_WR_EPS_REG_TIER1_WR_EPS_VALUE_LEN = 12;
static const uint32_t L2_L2MISC_L2CERRS_WR_EPS_REG_TIER2_WR_EPS_VALUE = 12;
static const uint32_t L2_L2MISC_L2CERRS_WR_EPS_REG_TIER2_WR_EPS_VALUE_LEN = 12;
static const uint32_t L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_DIVIDER_MODE = 24;
static const uint32_t L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_DIVIDER_MODE_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_MODE_SEL = 28;
static const uint32_t L2_L2MISC_L2CERRS_WR_EPS_REG_EPS_CNT_USE_L2_DIVIDER_EN = 29;
static const uint32_t L2_L2MISC_L2CERRS_WR_EPS_REG_L2_EPS_STEP_MODE = 30;
static const uint32_t L2_L2MISC_L2CERRS_WR_EPS_REG_L2_EPS_STEP_MODE_LEN = 4;
// c/reg00012.H

static const uint64_t L2TRA_TR0_CONFIG_1 = 0x20020044ull;

static const uint32_t L2TRA_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t L2TRA_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00012.H

static const uint64_t NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG = 0x20010651ull;

static const uint32_t NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN = 0;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_ADDR = 12;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_ADDR_LEN = 40;
// c/reg00012.H

}
}
#include "c/reg00012.H"
#endif
