/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mc_c.H $         */
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

#ifndef __PPE_HCODE__
    #include "proc_scomt.H"
#endif

#ifndef __p10_scom_mc_c_H_
#define __p10_scom_mc_c_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace mc
{
#endif


//>> [CPLT_CTRL2]
static const uint64_t CPLT_CTRL2_RW = 0x0c000002ull;
static const uint64_t CPLT_CTRL2_WO_CLEAR = 0x0c000022ull;
static const uint64_t CPLT_CTRL2_WO_OR = 0x0c000012ull;

static const uint32_t CPLT_CTRL2_0_PGOOD = 4;
static const uint32_t CPLT_CTRL2_1_PGOOD = 5;
static const uint32_t CPLT_CTRL2_2_PGOOD = 6;
static const uint32_t CPLT_CTRL2_3_PGOOD = 7;
static const uint32_t CPLT_CTRL2_4_PGOOD = 8;
static const uint32_t CPLT_CTRL2_5_PGOOD = 9;
static const uint32_t CPLT_CTRL2_6_PGOOD = 10;
static const uint32_t CPLT_CTRL2_7_PGOOD = 11;
static const uint32_t CPLT_CTRL2_8_PGOOD = 12;
static const uint32_t CPLT_CTRL2_9_PGOOD = 13;
static const uint32_t CPLT_CTRL2_10_PGOOD = 14;
static const uint32_t CPLT_CTRL2_11_PGOOD = 15;
static const uint32_t CPLT_CTRL2_12_PGOOD = 16;
static const uint32_t CPLT_CTRL2_13_PGOOD = 17;
static const uint32_t CPLT_CTRL2_14_PGOOD = 18;
//<< [CPLT_CTRL2]
// mc/reg00012.H

//>> [CPLT_MASK0]
static const uint64_t CPLT_MASK0 = 0x0c000101ull;

static const uint32_t CPLT_MASK0_ITR_MASK = 0;
static const uint32_t CPLT_MASK0_ITR_MASK_LEN = 32;
//<< [CPLT_MASK0]
// mc/reg00012.H

//>> [EPS_DBG_MODE_REG]
static const uint64_t EPS_DBG_MODE_REG = 0x0c0107c0ull;

static const uint32_t EPS_DBG_MODE_REG_GLB_BRCST_MODE = 0;
static const uint32_t EPS_DBG_MODE_REG_GLB_BRCST_MODE_LEN = 3;
static const uint32_t EPS_DBG_MODE_REG_TRACE_SEL_MODE = 3;
static const uint32_t EPS_DBG_MODE_REG_TRACE_SEL_MODE_LEN = 3;
static const uint32_t EPS_DBG_MODE_REG_TRIG_SEL_MODE = 6;
static const uint32_t EPS_DBG_MODE_REG_TRIG_SEL_MODE_LEN = 2;
static const uint32_t EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION = 8;
static const uint32_t EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION = 9;
static const uint32_t EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION = 10;
static const uint32_t EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION = 11;
static const uint32_t EPS_DBG_MODE_REG_FREEZE_SEL_MODE = 12;
static const uint32_t EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE = 13;
static const uint32_t EPS_DBG_MODE_REG_TRACE_RUN_ON = 16;
static const uint32_t EPS_DBG_MODE_REG_TRACE_RUN_STATUS = 17;
static const uint32_t EPS_DBG_MODE_REG_TRACE_RUN_STATUS_LEN = 2;
static const uint32_t EPS_DBG_MODE_REG_IS_FROZEN_STATUS = 19;
static const uint32_t EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS = 20;
static const uint32_t EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS_LEN = 3;
static const uint32_t EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS = 23;
static const uint32_t EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS_LEN = 3;
static const uint32_t EPS_DBG_MODE_REG_UNUSED = 26;
static const uint32_t EPS_DBG_MODE_REG_UNUSED_LEN = 6;
//<< [EPS_DBG_MODE_REG]
// mc/reg00012.H

//>> [PCB_OPCG_STOP]
static const uint64_t PCB_OPCG_STOP = 0x0c030030ull;

static const uint32_t PCB_OPCG_STOP_PCB_OPCGSTOP = 0;
//<< [PCB_OPCG_STOP]
// mc/reg00012.H

//>> [SCAN64CONTSCAN]
static const uint64_t SCAN64CONTSCAN = 0x0c03f000ull;

static const uint32_t SCAN64CONTSCAN_SCAN64CONTSCAN_REG = 0;
static const uint32_t SCAN64CONTSCAN_SCAN64CONTSCAN_REG_LEN = 64;
//<< [SCAN64CONTSCAN]
// mc/reg00012.H

//>> [SCOMFIR_MCFIRACT0]
static const uint64_t SCOMFIR_MCFIRACT0 = 0x0c010c06ull;

static const uint32_t SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0 = 0;
static const uint32_t SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0_LEN = 24;
//<< [SCOMFIR_MCFIRACT0]
// mc/reg00012.H

//>> [SCOMFIR_MCMODE0]
static const uint64_t SCOMFIR_MCMODE0 = 0x0c010c11ull;

static const uint32_t SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND = 0;
static const uint32_t SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND = 1;
static const uint32_t SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND = 2;
static const uint32_t SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START = 3;
static const uint32_t SCOMFIR_MCMODE0_RESERVED_4 = 4;
static const uint32_t SCOMFIR_MCMODE0_USE_BIT14_AS_DSADDR = 4; // p10:20,
static const uint32_t SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID = 5;
static const uint32_t SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE = 6;
static const uint32_t SCOMFIR_MCMODE0_RESERVED_7 = 7;
static const uint32_t SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE = 8;
static const uint32_t SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND = 9;
static const uint32_t SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND = 10;
static const uint32_t SCOMFIR_MCMODE0_RESERVED_11 = 11;
static const uint32_t SCOMFIR_MCMODE0_HWFM_PERMANENT = 11; // p10:20,
static const uint32_t SCOMFIR_MCMODE0_DISABLE_MC_SYNC = 12;
static const uint32_t SCOMFIR_MCMODE0_RESERVED_13 = 13;
static const uint32_t SCOMFIR_MCMODE0_64B_WR_IS_PWRT = 14;
static const uint32_t SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE = 15;
static const uint32_t SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE_LEN = 10;
static const uint32_t SCOMFIR_MCMODE0_RESERVED_25_31 = 25;
static const uint32_t SCOMFIR_MCMODE0_RESERVED_25_31_LEN = 7;
static const uint32_t SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY = 32;
static const uint32_t SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY_LEN = 4;
static const uint32_t SCOMFIR_MCMODE0_MEM_MAP_MODE = 36;
static const uint32_t SCOMFIR_MCMODE0_RESERVED_37 = 37;
static const uint32_t SCOMFIR_MCMODE0_ADD_HASH_BITS = 38;
static const uint32_t SCOMFIR_MCMODE0_ADD_HASH_BITS_LEN = 2;
static const uint32_t SCOMFIR_MCMODE0_ENABLE_ADD_HASH = 40;
static const uint32_t SCOMFIR_MCMODE0_RESERVED_41_63 = 41;
static const uint32_t SCOMFIR_MCMODE0_RESERVED_41_63_LEN = 23;
//<< [SCOMFIR_MCMODE0]
// mc/reg00012.H

//>> [SCOMFIR_MCPERF1]
static const uint64_t SCOMFIR_MCPERF1 = 0x0c010c10ull;

static const uint32_t SCOMFIR_MCPERF1_DISABLE_FASTPATH = 0;
static const uint32_t SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_GROUP_PUMP_LOCAL = 1;
static const uint32_t SCOMFIR_MCPERF1_ENABLE_DISABLE_SPEC_READ_FOR_NONDMA_SYSTEM_PUMP_LOCAL = 2;
static const uint32_t SCOMFIR_MCPERF1_DISABLE_FASTPATH_QOS = 3;
static const uint32_t SCOMFIR_MCPERF1_DISABLE_CHARB_BYPASS = 4;
static const uint32_t SCOMFIR_MCPERF1_DISABLE_SPEC_HINT_BIT = 5;
static const uint32_t SCOMFIR_MCPERF1_CONFIDENCE_LEVEL_MASK = 6;
static const uint32_t SCOMFIR_MCPERF1_CONFIDENCE_LEVEL_MASK_LEN = 4;
static const uint32_t SCOMFIR_MCPERF1_PF_DROP_CNT_THRESH = 10;
static const uint32_t SCOMFIR_MCPERF1_PF_DROP_CNT_THRESH_LEN = 7;
static const uint32_t SCOMFIR_MCPERF1_MERGE_CAPACITY_LIMIT = 17;
static const uint32_t SCOMFIR_MCPERF1_MERGE_CAPACITY_LIMIT_LEN = 4;
static const uint32_t SCOMFIR_MCPERF1_ENABLE_PF_DROP_CMDLIST = 21;
static const uint32_t SCOMFIR_MCPERF1_ENABLE_PREFETCH_PROMOTE = 22;
static const uint32_t SCOMFIR_MCPERF1_VG_SPEC_DIS_THRESH = 23;
static const uint32_t SCOMFIR_MCPERF1_VG_SPEC_DIS_THRESH_LEN = 7;
static const uint32_t SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_CONFIDENCE = 30;
static const uint32_t SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_CONFIDENCE_LEN = 2;
static const uint32_t SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_SCOPE = 32;
static const uint32_t SCOMFIR_MCPERF1_PLUS_ONE_PREFETCH_SCOPE_LEN = 5;
static const uint32_t SCOMFIR_MCPERF1_EDATA_ON_CI_PR_RD = 37;
static const uint32_t SCOMFIR_MCPERF1_WBIT_SCOPE_ENABLE = 38;
static const uint32_t SCOMFIR_MCPERF1_WBIT_SCOPE_ENABLE_LEN = 5;
static const uint32_t SCOMFIR_MCPERF1_EN_NONSPEC_EDATA = 43;
static const uint32_t SCOMFIR_MCPERF1_EN_SPEC_EDATA = 44;
static const uint32_t SCOMFIR_MCPERF1_DIS_CHANNEL_FAIL_FORCE_MIRROR = 45;
static const uint32_t SCOMFIR_MCPERF1_EN_VG_SPECDIS = 46;
static const uint32_t SCOMFIR_MCPERF1_RESERVED_47_63 = 47;
static const uint32_t SCOMFIR_MCPERF1_RESERVED_47_63_LEN = 17;
//<< [SCOMFIR_MCPERF1]
// mc/reg00012.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "mc/reg00012.H"
#endif
#endif
