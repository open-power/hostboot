/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mc_c.H $         */
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

#ifndef __p10_scom_mc_c_H_
#define __p10_scom_mc_c_H_


namespace scomt
{
namespace mc
{


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
// mc/reg00012.H

static const uint64_t CPLT_MASK0 = 0x0c000101ull;

static const uint32_t CPLT_MASK0_ITR_MASK = 0;
static const uint32_t CPLT_MASK0_ITR_MASK_LEN = 32;
// mc/reg00012.H

static const uint64_t CTRL_PROTECT_MODE_REG = 0x0c0003feull;

static const uint32_t CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE = 0;
static const uint32_t CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE = 1;
// mc/reg00012.H

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
static const uint32_t EPS_DBG_MODE_REG_TRACE_RUN_STATUS = 17;
static const uint32_t EPS_DBG_MODE_REG_TRACE_RUN_STATUS_LEN = 2;
static const uint32_t EPS_DBG_MODE_REG_IS_FROZEN_STATUS = 19;
static const uint32_t EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS = 20;
static const uint32_t EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS_LEN = 3;
static const uint32_t EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS = 23;
static const uint32_t EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS_LEN = 3;
// mc/reg00012.H

static const uint64_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5 = 0x0c040085ull;

static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_XSTOP_ERR = 0;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_RECOV_ERR = 1;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SPATTN_ERR = 2;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_LXSTOP_ERR = 3;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_HOSTATTN_ERR = 4;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_ERR = 5;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_OOB1_ERR = 6;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_TRIG_ERR = 7;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01 = 12;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02 = 13;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03 = 14;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04 = 15;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05 = 16;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06 = 17;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07 = 18;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08 = 19;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09 = 20;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10 = 21;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11 = 22;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12 = 23;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13 = 24;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14 = 25;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15 = 26;
// mc/reg00012.H

static const uint64_t EPS_PSC_WRITE_PROTECT_ENABLE_REG = 0x0c010005ull;

static const uint32_t EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING = 0;
static const uint32_t EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING = 1;
// mc/reg00012.H

static const uint64_t HOSTATTN_UNMASKED = 0x0c040014ull;

static const uint32_t HOSTATTN_UNMASKED_HOSTATTN_UNMASKED_IN = 1;
static const uint32_t HOSTATTN_UNMASKED_HOSTATTN_UNMASKED_IN_LEN = 53;
// mc/reg00012.H

static const uint64_t MBA_SCOMFIR_DBG1_SCOM0Q = 0x0c010f96ull;

static const uint32_t MBA_SCOMFIR_DBG1_SCOM0Q_DBG1_SCOM0Q_DEBUG_BUS_0_63 = 0;
static const uint32_t MBA_SCOMFIR_DBG1_SCOM0Q_DBG1_SCOM0Q_DEBUG_BUS_0_63_LEN = 64;
// mc/reg00012.H

static const uint64_t MBA_SCOMFIR_MCWATDATA8 = 0x0c010fa2ull;

static const uint32_t MBA_SCOMFIR_MCWATDATA8_PATTERN_B = 0;
static const uint32_t MBA_SCOMFIR_MCWATDATA8_PATTERN_B_LEN = 22;
static const uint32_t MBA_SCOMFIR_MCWATDATA8_MASK_B = 22;
static const uint32_t MBA_SCOMFIR_MCWATDATA8_MASK_B_LEN = 22;
// mc/reg00012.H

static const uint64_t MBA_SCOMFIR_WATCFG0AQ = 0x0c010f80ull;

static const uint32_t MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL = 0;
static const uint32_t MBA_SCOMFIR_WATCFG0AQ_WATCFG0AQ_CFG_WAT_EVENT_SEL_LEN = 48;
// mc/reg00012.H

static const uint64_t MULTICAST_GROUP_4 = 0x0c0f0004ull;

static const uint32_t MULTICAST_GROUP_4_MULTICAST4_GROUP = 3;
static const uint32_t MULTICAST_GROUP_4_MULTICAST4_GROUP_LEN = 3;
// mc/reg00012.H

static const uint64_t PCB_OPCG_STOP = 0x0c030030ull;

static const uint32_t PCB_OPCG_STOP_PCB_OPCGSTOP = 0;
// mc/reg00012.H

static const uint64_t PRE_COUNTER_REG = 0x0c0f0028ull;

static const uint32_t PRE_COUNTER_REG_PRE_COUNTER = 0;
static const uint32_t PRE_COUNTER_REG_PRE_COUNTER_LEN = 8;
// mc/reg00012.H

static const uint64_t SCAN64CONTSCAN = 0x0c03f000ull;
// mc/reg00012.H

static const uint64_t SCOMFIR_MCFIRACT0 = 0x0c010c06ull;

static const uint32_t SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0 = 0;
static const uint32_t SCOMFIR_MCFIRACT0_MCFIRACT0_ACTION_0_LEN = 24;
// mc/reg00012.H

static const uint64_t SCOMFIR_MCMODE0 = 0x0c010c11ull;

static const uint32_t SCOMFIR_MCMODE0_SCOM_PERFMON_START_COMMAND = 0;
static const uint32_t SCOMFIR_MCMODE0_SCOM_PERFMON_STOP_COMMAND = 1;
static const uint32_t SCOMFIR_MCMODE0_ENABLE_CENTAUR_PERFMON_COMMAND = 2;
static const uint32_t SCOMFIR_MCMODE0_DISABLE_PERFMON_RESET_ON_START = 3;
static const uint32_t SCOMFIR_MCMODE0_RESERVED_4 = 4;
static const uint32_t SCOMFIR_MCMODE0_FORCE_COMMANDLIST_VALID = 5;
static const uint32_t SCOMFIR_MCMODE0_FORCE_ANY_BAR_ACTIVE = 6;
static const uint32_t SCOMFIR_MCMODE0_RESERVED_7 = 7;
static const uint32_t SCOMFIR_MCMODE0_ENABLE_EMERGENCY_THROTTLE = 8;
static const uint32_t SCOMFIR_MCMODE0_ENABLE_CENTAUR_CHECKSTOP_COMMAND = 9;
static const uint32_t SCOMFIR_MCMODE0_ENABLE_CENTAUR_TRACESTOP_COMMAND = 10;
static const uint32_t SCOMFIR_MCMODE0_RESERVED_11 = 11;
static const uint32_t SCOMFIR_MCMODE0_DISABLE_MC_SYNC = 12;
static const uint32_t SCOMFIR_MCMODE0_RESERVED_13 = 13;
static const uint32_t SCOMFIR_MCMODE0_64B_WR_IS_PWRT = 14;
static const uint32_t SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE = 15;
static const uint32_t SCOMFIR_MCMODE0_CL_GLOBAL_DISABLE_LEN = 10;
static const uint32_t SCOMFIR_MCMODE0_CL_FINE_DISABLE = 25;
static const uint32_t SCOMFIR_MCMODE0_CL_FINE_DISABLE_LEN = 7;
static const uint32_t SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY = 32;
static const uint32_t SCOMFIR_MCMODE0_GROUP_ADDRESS_INTERLEAVE_GRANULARITY_LEN = 4;
static const uint32_t SCOMFIR_MCMODE0_MEM_MAP_MODE = 36;
static const uint32_t SCOMFIR_MCMODE0_ADD_HASH_BITS = 37;
static const uint32_t SCOMFIR_MCMODE0_ADD_HASH_BITS_LEN = 3;
static const uint32_t SCOMFIR_MCMODE0_ENABLE_ADD_HASH = 40;
static const uint32_t SCOMFIR_MCMODE0_RESERVED_41_63 = 41;
static const uint32_t SCOMFIR_MCMODE0_RESERVED_41_63_LEN = 23;
// mc/reg00012.H

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
// mc/reg00012.H

static const uint64_t SCOMFIR_MCWATACT = 0x0c010c18ull;

static const uint32_t SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_ALL_SPECULATION = 0;
static const uint32_t SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_ALL_SPECULATION = 1;
static const uint32_t SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_ALL_SPECULATION = 2;
static const uint32_t SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_ALL_SPECULATION = 3;
static const uint32_t SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_READ_BYPASS = 4;
static const uint32_t SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_READ_BYPASS = 5;
static const uint32_t SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_READ_BYPASS = 6;
static const uint32_t SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_READ_BYPASS = 7;
static const uint32_t SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_PREFETCH = 8;
static const uint32_t SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_PREFETCH = 9;
static const uint32_t SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_PREFETCH = 10;
static const uint32_t SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_PREFETCH = 11;
static const uint32_t SCOMFIR_MCWATACT_EVENT_0_WAT_DISABLE_FASTPATH = 12;
static const uint32_t SCOMFIR_MCWATACT_EVENT_1_WAT_DISABLE_FASTPATH = 13;
static const uint32_t SCOMFIR_MCWATACT_EVENT_2_WAT_DISABLE_FASTPATH = 14;
static const uint32_t SCOMFIR_MCWATACT_EVENT_3_WAT_DISABLE_FASTPATH = 15;
static const uint32_t SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_SFSTAT = 16;
static const uint32_t SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_SFSTAT = 17;
static const uint32_t SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_SFSTAT = 18;
static const uint32_t SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_SFSTAT = 19;
static const uint32_t SCOMFIR_MCWATACT_EVENT_0_WAT_FORCE_MDI1 = 20;
static const uint32_t SCOMFIR_MCWATACT_EVENT_1_WAT_FORCE_MDI1 = 21;
static const uint32_t SCOMFIR_MCWATACT_EVENT_2_WAT_FORCE_MDI1 = 22;
static const uint32_t SCOMFIR_MCWATACT_EVENT_3_WAT_FORCE_MDI1 = 23;
static const uint32_t SCOMFIR_MCWATACT_RESERVED_36_47 = 24;
static const uint32_t SCOMFIR_MCWATACT_RESERVED_36_47_LEN = 16;
// mc/reg00012.H

static const uint64_t TRA1_TR0_CONFIG_9 = 0x0c010449ull;

static const uint32_t TRA1_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TRA1_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TRA1_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TRA1_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TRA1_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TRA1_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TRA1_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TRA1_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TRA1_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TRA1_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TRA1_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TRA1_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TRA1_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TRA1_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TRA1_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// mc/reg00012.H

static const uint64_t XSTOP_INTERRUPT_REG = 0x0c0f001cull;
// mc/reg00012.H

}
}
#ifndef __PPE_HCODE__
    #include "mc/reg00012.H"
#endif
#endif
