/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_perv_c.H $       */
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

#ifndef __p10_scom_perv_c_H_
#define __p10_scom_perv_c_H_


namespace scomt
{
namespace perv
{


static const uint64_t CPLT_CTRL2_RW = 0x00000002ull;
static const uint64_t CPLT_CTRL2_WO_CLEAR = 0x00000022ull;
static const uint64_t CPLT_CTRL2_WO_OR = 0x00000012ull;

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
// perv/reg00012.H

static const uint64_t CPLT_MASK0 = 0x00000101ull;

static const uint32_t CPLT_MASK0_ITR_MASK = 0;
static const uint32_t CPLT_MASK0_ITR_MASK_LEN = 24;
// perv/reg00012.H

static const uint64_t CTRL_PROTECT_MODE_REG = 0x000003feull;

static const uint32_t CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE = 0;
static const uint32_t CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE = 1;
// perv/reg00012.H

static const uint64_t DPLL_CNTL_NEST_REGS_TESTSEL = 0x00000159ull;

static const uint32_t DPLL_CNTL_NEST_REGS_TESTSEL_DPLL_TESTSEL_TEST_SEL = 0;
static const uint32_t DPLL_CNTL_NEST_REGS_TESTSEL_DPLL_TESTSEL_TEST_SEL_LEN = 8;
// perv/reg00012.H

static const uint64_t DPLL_CNTL_PAU_REGS_FREQ = 0x00000051ull;

static const uint32_t DPLL_CNTL_PAU_REGS_FREQ_FMAX = 1;
static const uint32_t DPLL_CNTL_PAU_REGS_FREQ_FMAX_LEN = 11;
static const uint32_t DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMAX = 12;
static const uint32_t DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMAX_LEN = 4;
static const uint32_t DPLL_CNTL_PAU_REGS_FREQ_FF_MAX_MULT_FRAC7 = 16;
static const uint32_t DPLL_CNTL_PAU_REGS_FREQ_FMULT = 17;
static const uint32_t DPLL_CNTL_PAU_REGS_FREQ_FMULT_LEN = 11;
static const uint32_t DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMULT = 28;
static const uint32_t DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMULT_LEN = 4;
static const uint32_t DPLL_CNTL_PAU_REGS_FREQ_MULT_FRAC7 = 32;
static const uint32_t DPLL_CNTL_PAU_REGS_FREQ_FMIN = 33;
static const uint32_t DPLL_CNTL_PAU_REGS_FREQ_FMIN_LEN = 11;
static const uint32_t DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMIN = 44;
static const uint32_t DPLL_CNTL_PAU_REGS_FREQ_HIRES_FMIN_LEN = 4;
static const uint32_t DPLL_CNTL_PAU_REGS_FREQ_FF_MIN_MULT_FRAC7 = 48;
// perv/reg00012.H

static const uint64_t EPS_DBG_MODE_REG = 0x000107c0ull;

static const uint32_t EPS_DBG_MODE_REG_GLB_BRCST_MODE = 0;
static const uint32_t EPS_DBG_MODE_REG_GLB_BRCST_MODE_LEN = 3;
static const uint32_t EPS_DBG_MODE_REG_TRACE_SEL_MODE = 3;
static const uint32_t EPS_DBG_MODE_REG_TRACE_SEL_MODE_LEN = 3;
static const uint32_t EPS_DBG_MODE_REG_TRIG_SEL_MODE = 6;
static const uint32_t EPS_DBG_MODE_REG_TRIG_SEL_MODE_LEN = 2;
static const uint32_t EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION = 8;
static const uint32_t EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION = 9;
static const uint32_t EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION = 10;
static const uint32_t EPS_DBG_MODE_REG_FREEZE_SEL_MODE = 11;
static const uint32_t EPS_DBG_MODE_REG_TRACE_RUN_STATUS = 17;
static const uint32_t EPS_DBG_MODE_REG_TRACE_RUN_STATUS_LEN = 2;
static const uint32_t EPS_DBG_MODE_REG_IS_FROZEN_STATUS = 19;
static const uint32_t EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS = 20;
static const uint32_t EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS_LEN = 3;
static const uint32_t EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS = 23;
static const uint32_t EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS_LEN = 3;
// perv/reg00012.H

static const uint64_t EPS_FIR_GXSTOP4_MASK_REG = 0x0004001bull;

static const uint32_t EPS_FIR_GXSTOP4_MASK_REG_SUM_XSTOP = 0;
static const uint32_t EPS_FIR_GXSTOP4_MASK_REG_SUM_RECOV = 1;
static const uint32_t EPS_FIR_GXSTOP4_MASK_REG_SUM_SPATTN = 2;
static const uint32_t EPS_FIR_GXSTOP4_MASK_REG_SUM_LOCAL_XSTOP = 3;
static const uint32_t EPS_FIR_GXSTOP4_MASK_REG_SUM_TYPE4 = 4;
static const uint32_t EPS_FIR_GXSTOP4_MASK_REG_SYSTEM_XSTOP = 5;
static const uint32_t EPS_FIR_GXSTOP4_MASK_REG_OOB1 = 6;
static const uint32_t EPS_FIR_GXSTOP4_MASK_REG_DBG_FIR_XSTOP_ON_TRIG = 7;
static const uint32_t EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 = 12;
static const uint32_t EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 = 13;
static const uint32_t EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 = 14;
static const uint32_t EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 = 15;
static const uint32_t EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 = 16;
static const uint32_t EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 = 17;
static const uint32_t EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 = 18;
static const uint32_t EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 = 19;
static const uint32_t EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 = 20;
static const uint32_t EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 = 21;
static const uint32_t EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 = 22;
static const uint32_t EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 = 23;
static const uint32_t EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 = 24;
static const uint32_t EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 = 25;
static const uint32_t EPS_FIR_GXSTOP4_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 = 26;
// perv/reg00012.H

static const uint64_t EPS_PSC_WRITE_PROTECT_ENABLE_REG = 0x00010005ull;

static const uint32_t EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING = 0;
static const uint32_t EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING = 1;
// perv/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA1_TR0_CONFIG_9 = 0x00018249ull;

static const uint32_t L3TRA1_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t L3TRA1_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t L3TRA1_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t L3TRA1_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t L3TRA1_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t L3TRA1_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t L3TRA1_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t L3TRA1_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t L3TRA1_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t L3TRA1_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t L3TRA1_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t L3TRA1_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t L3TRA1_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t L3TRA1_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t L3TRA1_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t L3TRA1_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t L3TRA1_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t L3TRA1_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t L3TRA1_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t L3TRA1_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t L3TRA1_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t L3TRA1_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t L3TRA1_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t L3TRA1_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t L3TRA1_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t L3TRA1_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t L3TRA1_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// perv/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA1_TR1_CONFIG_0 = 0x00018263ull;

static const uint32_t L3TRA1_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t L3TRA1_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// perv/reg00012.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA3_TR0_CONFIG_1 = 0x000182c4ull;

static const uint32_t L3TRA3_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t L3TRA3_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// perv/reg00012.H

static const uint64_t MULTICAST_GROUP_4 = 0x000f0004ull;

static const uint32_t MULTICAST_GROUP_4_MULTICAST4_GROUP = 3;
static const uint32_t MULTICAST_GROUP_4_MULTICAST4_GROUP_LEN = 3;
// perv/reg00012.H

static const uint64_t PCB_OPCG_STOP = 0x00030030ull;

static const uint32_t PCB_OPCG_STOP_PCB_OPCGSTOP = 0;
// perv/reg00012.H

static const uint64_t PRE_COUNTER_REG = 0x000f0028ull;

static const uint32_t PRE_COUNTER_REG_PRE_COUNTER = 0;
static const uint32_t PRE_COUNTER_REG_PRE_COUNTER_LEN = 8;
// perv/reg00012.H

static const uint64_t TRA0_TR1_TRACE_LO_DATA_REG = 0x00010441ull;

static const uint32_t TRA0_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TRA0_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TRA0_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TRA0_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TRA0_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TRA0_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TRA0_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TRA0_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// perv/reg00012.H

static const uint64_t TRA1_TR0_CONFIG_9 = 0x00010489ull;

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
// perv/reg00012.H

static const uint64_t TRA1_TR1_CONFIG_0 = 0x000104c3ull;

static const uint32_t TRA1_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TRA1_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// perv/reg00012.H

static const uint64_t TRA3_TR0_TRACE_HI_DATA_REG = 0x00010580ull;

static const uint32_t TRA3_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TRA3_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// perv/reg00012.H

static const uint64_t TRA3_TR0_CONFIG_1 = 0x00010584ull;

static const uint32_t TRA3_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TRA3_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// perv/reg00012.H

static const uint64_t TRA4_TR0_CONFIG_0 = 0x00010603ull;

static const uint32_t TRA4_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TRA4_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// perv/reg00012.H

static const uint64_t TRA4_TR1_CONFIG_9 = 0x00010649ull;

static const uint32_t TRA4_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TRA4_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TRA4_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TRA4_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TRA4_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TRA4_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TRA4_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TRA4_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TRA4_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TRA4_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TRA4_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TRA4_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TRA4_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TRA4_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TRA4_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TRA4_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TRA4_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TRA4_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TRA4_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TRA4_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TRA4_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TRA4_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TRA4_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TRA4_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TRA4_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TRA4_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TRA4_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// perv/reg00012.H

static const uint64_t TRA6_TR1_CONFIG_1 = 0x00010744ull;

static const uint32_t TRA6_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TRA6_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// perv/reg00012.H

static const uint64_t XSTOP_INTERRUPT_REG = 0x000f001cull;
// perv/reg00012.H

}
}
#include "perv/reg00012.H"
#endif
