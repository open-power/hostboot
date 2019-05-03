/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_nmmu_e.H $       */
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

#ifndef __p10_scom_nmmu_e_H_
#define __p10_scom_nmmu_e_H_


namespace scomt
{
namespace nmmu
{


static const uint64_t FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE = 0x02010c1dull;

static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL = 0;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_CNT_VAL_LEN = 12;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_DIV_VAL = 12;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_1_DIV_VAL_LEN = 4;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL = 16;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_CNT_VAL_LEN = 12;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_DIV_VAL = 28;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_WR_EPSILON_TIER_2_DIV_VAL_LEN = 4;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_MM_EPSILON_COUNTER_VALUE_EPSILON_DISABLE = 32;
// nmmu/reg00014.H

static const uint64_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG = 0x02010c26ull;

static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_ENABLE = 0;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_ENABLE = 1;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_ENABLE = 2;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_ENABLE = 3;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_PRESCALER_SEL = 4;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_PRESCALER_SEL_LEN = 3;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_POSEDGE_SEL = 7;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_POSEDGE_SEL = 8;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_POSEDGE_SEL = 9;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_POSEDGE_SEL = 10;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_RESET = 11;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_EVENT_SEL = 12;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_EVENT_SEL_LEN = 2;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_BIT_PAIR_SEL = 14;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_BIT_PAIR_SEL_LEN = 2;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_EVENT_SEL = 16;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_EVENT_SEL_LEN = 2;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_BIT_PAIR_SEL = 18;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_BIT_PAIR_SEL_LEN = 2;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_EVENT_SEL = 20;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_EVENT_SEL_LEN = 2;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_BIT_PAIR_SEL = 22;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_BIT_PAIR_SEL_LEN = 2;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_EVENT_SEL = 24;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_EVENT_SEL_LEN = 2;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_BIT_PAIR_SEL = 26;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_BIT_PAIR_SEL_LEN = 2;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_PORT_SEL = 28;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_PORT_SEL_LEN = 2;
// nmmu/reg00014.H

static const uint64_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG = 0x02010c27ull;

static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_0 = 0;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_0_LEN = 16;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_1 = 16;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_1_LEN = 16;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_2 = 32;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_2_LEN = 16;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_3 = 48;
static const uint32_t FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_3_LEN = 16;
// nmmu/reg00014.H

static const uint64_t NMMU_DBG_MODE = 0x02010c59ull;

static const uint32_t NMMU_DBG_MODE_EN = 0;
static const uint32_t NMMU_DBG_MODE_PRV_BUS0_STG2_SEL = 1;
static const uint32_t NMMU_DBG_MODE_PRV_BUS1_STG2_SEL = 2;
static const uint32_t NMMU_DBG_MODE_FBC_BUS0_STG2_SEL = 3;
static const uint32_t NMMU_DBG_MODE_FBC_BUS1_STG2_SEL = 4;
static const uint32_t NMMU_DBG_MODE_MSC_BUS0_STG2_SEL = 5;
static const uint32_t NMMU_DBG_MODE_MSC_BUS1_STG2_SEL = 6;
static const uint32_t NMMU_DBG_MODE_SLB_BUS0_STG2_SEL = 7;
static const uint32_t NMMU_DBG_MODE_SLB_BUS1_STG2_SEL = 8;
static const uint32_t NMMU_DBG_MODE_TW_BUS0_STG2_SEL = 9;
static const uint32_t NMMU_DBG_MODE_TW_BUS1_STG2_SEL = 10;
static const uint32_t NMMU_DBG_MODE_RDX_BUS0_STG2_SEL = 11;
static const uint32_t NMMU_DBG_MODE_RDX_BUS1_STG2_SEL = 12;
static const uint32_t NMMU_DBG_MODE_TLB_BUS0_STG2_SEL = 13;
static const uint32_t NMMU_DBG_MODE_TLB_BUS1_STG2_SEL = 14;
static const uint32_t NMMU_DBG_MODE_FBC_BUS0_STG1_SEL = 15;
static const uint32_t NMMU_DBG_MODE_FBC_BUS1_STG1_SEL = 16;
static const uint32_t NMMU_DBG_MODE_MSC_BUS0_STG1_SEL = 17;
static const uint32_t NMMU_DBG_MODE_MSC_BUS1_STG1_SEL = 18;
static const uint32_t NMMU_DBG_MODE_SLB_BUS0_STG1_SEL = 19;
static const uint32_t NMMU_DBG_MODE_SLB_BUS1_STG1_SEL = 20;
static const uint32_t NMMU_DBG_MODE_TW_BUS0_STG1_SEL = 21;
static const uint32_t NMMU_DBG_MODE_TW_BUS1_STG1_SEL = 22;
static const uint32_t NMMU_DBG_MODE_RDX_BUS0_STG1_SEL = 23;
static const uint32_t NMMU_DBG_MODE_RDX_BUS1_STG1_SEL = 24;
static const uint32_t NMMU_DBG_MODE_TLB_BUS0_STG1_SEL = 25;
static const uint32_t NMMU_DBG_MODE_TLB_BUS1_STG1_SEL = 26;
static const uint32_t NMMU_DBG_MODE_FBC_BUS0_STG0_SEL = 32;
static const uint32_t NMMU_DBG_MODE_FBC_BUS0_STG0_SEL_LEN = 4;
static const uint32_t NMMU_DBG_MODE_FBC_BUS1_STG0_SEL = 36;
static const uint32_t NMMU_DBG_MODE_FBC_BUS1_STG0_SEL_LEN = 4;
static const uint32_t NMMU_DBG_MODE_MSC_BUS0_STG0_SEL = 40;
static const uint32_t NMMU_DBG_MODE_MSC_BUS0_STG0_SEL_LEN = 4;
static const uint32_t NMMU_DBG_MODE_MSC_BUS1_STG0_SEL = 44;
static const uint32_t NMMU_DBG_MODE_MSC_BUS1_STG0_SEL_LEN = 4;
static const uint32_t NMMU_DBG_MODE_TW_BUS0_STG0_SEL = 48;
static const uint32_t NMMU_DBG_MODE_TW_BUS0_STG0_SEL_LEN = 6;
static const uint32_t NMMU_DBG_MODE_TW_BUS1_STG0_SEL = 54;
static const uint32_t NMMU_DBG_MODE_TW_BUS1_STG0_SEL_LEN = 6;
static const uint32_t NMMU_DBG_MODE_RDX_BUS0_STG0_SEL = 60;
static const uint32_t NMMU_DBG_MODE_RDX_BUS0_STG0_SEL_LEN = 2;
static const uint32_t NMMU_DBG_MODE_RDX_BUS1_STG0_SEL = 62;
static const uint32_t NMMU_DBG_MODE_RDX_BUS1_STG0_SEL_LEN = 2;
// nmmu/reg00014.H

static const uint64_t NMMU_FLT_STAT_REG = 0x02010c51ull;

static const uint32_t NMMU_FLT_STAT_REG_MM_FLT_STAT = 0;
static const uint32_t NMMU_FLT_STAT_REG_MM_FLT_STAT_LEN = 16;
// nmmu/reg00014.H

static const uint64_t NMMU_PMU1_CTL_REG = 0x02010c4eull;

static const uint32_t NMMU_PMU1_CTL_REG_MM_PMU1_CTL = 0;
static const uint32_t NMMU_PMU1_CTL_REG_MM_PMU1_CTL_LEN = 64;
// nmmu/reg00014.H

}
}
#include "nmmu/reg00014.H"
#endif
