/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_eq_c.H $         */
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

#ifndef __p10_scom_eq_c_H_
#define __p10_scom_eq_c_H_


namespace scomt
{
namespace eq
{


static const uint64_t CPLT_CTRL2_RW = 0x20000002ull;
static const uint64_t CPLT_CTRL2_WO_CLEAR = 0x20000022ull;
static const uint64_t CPLT_CTRL2_WO_OR = 0x20000012ull;

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
// eq/reg00012.H

static const uint64_t CPLT_MASK0 = 0x20000101ull;

static const uint32_t CPLT_MASK0_ITR_MASK = 0;
static const uint32_t CPLT_MASK0_ITR_MASK_LEN = 24;
// eq/reg00012.H

static const uint64_t CTRL_PROTECT_MODE_REG = 0x200003feull;

static const uint32_t CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE = 0;
static const uint32_t CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE = 1;
// eq/reg00012.H

static const uint64_t EPS_DBG_MODE_REG = 0x200183e0ull;

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
// eq/reg00012.H

static const uint64_t EPS_FIR_GXSTOP4_MASK_REG = 0x2004001bull;

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
// eq/reg00012.H

static const uint64_t L3TRA1_TR0_CONFIG_9 = 0x20018249ull;

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
// eq/reg00012.H

static const uint64_t L3TRA1_TR1_CONFIG_0 = 0x20018263ull;

static const uint32_t L3TRA1_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t L3TRA1_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// eq/reg00012.H

static const uint64_t L3TRA3_TR0_CONFIG_1 = 0x200182c4ull;

static const uint32_t L3TRA3_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t L3TRA3_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// eq/reg00012.H

static const uint64_t MULTICAST_GROUP_4 = 0x200f0004ull;

static const uint32_t MULTICAST_GROUP_4_MULTICAST4_GROUP = 3;
static const uint32_t MULTICAST_GROUP_4_MULTICAST4_GROUP_LEN = 3;
// eq/reg00012.H

static const uint64_t PCB_OPCG_STOP = 0x20030030ull;

static const uint32_t PCB_OPCG_STOP_PCB_OPCGSTOP = 0;
// eq/reg00012.H

static const uint64_t PRE_COUNTER_REG = 0x200f0028ull;

static const uint32_t PRE_COUNTER_REG_PRE_COUNTER = 0;
static const uint32_t PRE_COUNTER_REG_PRE_COUNTER_LEN = 8;
// eq/reg00012.H

static const uint64_t QME_BCEBAR1 = 0x200e0064ull;

static const uint32_t QME_BCEBAR1_BASE = 8;
static const uint32_t QME_BCEBAR1_BASE_LEN = 36;
static const uint32_t QME_BCEBAR1_SIZE = 61;
static const uint32_t QME_BCEBAR1_SIZE_LEN = 3;
// eq/reg00012.H

static const uint64_t QME_FLAGS_RW = 0x200e0120ull;
static const uint64_t QME_FLAGS_WO_CLEAR = 0x200e0123ull;
static const uint64_t QME_FLAGS_WO_OR = 0x200e0122ull;

static const uint32_t QME_FLAGS_QME_FLAGS_DATA = 0;
static const uint32_t QME_FLAGS_QME_FLAGS_DATA_LEN = 64;
// eq/reg00012.H

static const uint64_t QME_PPEDBG_RW = 0x200e0244ull;
static const uint64_t QME_PPEDBG_WO_CLEAR = 0x200e0247ull;
static const uint64_t QME_PPEDBG_WO_OR = 0x200e0246ull;

static const uint32_t QME_PPEDBG_EN_DBG = 0;
static const uint32_t QME_PPEDBG_HALT_ON_XSTOP = 1;
static const uint32_t QME_PPEDBG_HALT_ON_TRIG = 2;
static const uint32_t QME_PPEDBG_EN_COVERAGE_MODE = 3;
static const uint32_t QME_PPEDBG_EN_INTR_ADDR = 4;
static const uint32_t QME_PPEDBG_EN_TRACE_EXTRA = 5;
static const uint32_t QME_PPEDBG_EN_TRACE_STALL = 6;
static const uint32_t QME_PPEDBG_EN_WAIT_CYCLES = 7;
static const uint32_t QME_PPEDBG_EN_FULL_SPEED = 8;
static const uint32_t QME_PPEDBG_DIS_FLOW_CHANGE = 9;
static const uint32_t QME_PPEDBG_TRACE_MODE_SEL = 10;
static const uint32_t QME_PPEDBG_TRACE_MODE_SEL_LEN = 2;
static const uint32_t QME_PPEDBG_FIR_TRIGGER = 16;
static const uint32_t QME_PPEDBG_MIB_GPIO = 17;
static const uint32_t QME_PPEDBG_MIB_GPIO_LEN = 3;
static const uint32_t QME_PPEDBG_TRACE_DATA_SEL = 20;
static const uint32_t QME_PPEDBG_TRACE_DATA_SEL_LEN = 4;
// eq/reg00012.H

static const uint64_t QME_PTSR = 0x200e013cull;
// eq/reg00012.H

static const uint64_t QME_RCIMR = 0x200e018cull;

static const uint32_t QME_RCIMR_P0 = 0;
static const uint32_t QME_RCIMR_P0_LEN = 8;
static const uint32_t QME_RCIMR_X0 = 11;
static const uint32_t QME_RCIMR_X0_LEN = 5;
static const uint32_t QME_RCIMR_P1 = 16;
static const uint32_t QME_RCIMR_P1_LEN = 8;
static const uint32_t QME_RCIMR_X1 = 27;
static const uint32_t QME_RCIMR_X1_LEN = 5;
static const uint32_t QME_RCIMR_P2 = 32;
static const uint32_t QME_RCIMR_P2_LEN = 8;
static const uint32_t QME_RCIMR_X2 = 43;
static const uint32_t QME_RCIMR_X2_LEN = 5;
static const uint32_t QME_RCIMR_P3 = 48;
static const uint32_t QME_RCIMR_P3_LEN = 8;
static const uint32_t QME_RCIMR_X3 = 59;
static const uint32_t QME_RCIMR_X3_LEN = 5;
// eq/reg00012.H

static const uint64_t QME_RCTAR1 = 0x200e0194ull;

static const uint32_t QME_RCTAR1_QME_RCTAR1_DATA = 0;
static const uint32_t QME_RCTAR1_QME_RCTAR1_DATA_LEN = 64;
// eq/reg00012.H

static const uint64_t QME_SCOM_PBTXTR0 = 0x200e0040ull;

static const uint32_t QME_SCOM_PBTXTR0__VALID = 0;
static const uint32_t QME_SCOM_PBTXTR0__VALID_LEN = 8;
static const uint32_t QME_SCOM_PBTXTR0_0 = 8;
static const uint32_t QME_SCOM_PBTXTR0_0_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR0_1 = 12;
static const uint32_t QME_SCOM_PBTXTR0_1_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR0_2 = 16;
static const uint32_t QME_SCOM_PBTXTR0_2_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR0_3 = 20;
static const uint32_t QME_SCOM_PBTXTR0_3_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR0_4 = 24;
static const uint32_t QME_SCOM_PBTXTR0_4_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR0_5 = 28;
static const uint32_t QME_SCOM_PBTXTR0_5_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR0_6 = 32;
static const uint32_t QME_SCOM_PBTXTR0_6_LEN = 4;
static const uint32_t QME_SCOM_PBTXTR0_7 = 36;
static const uint32_t QME_SCOM_PBTXTR0_7_LEN = 4;
// eq/reg00012.H

static const uint64_t QME_SCOM_XIRAMDBG = 0x200e020cull;
// eq/reg00012.H

static const uint64_t QME_SCOM_XIRAMGA = 0x200e0208ull;

static const uint32_t QME_SCOM_XIRAMGA_QME_SCOM_XIRAMEDR_IR = 0;
static const uint32_t QME_SCOM_XIRAMGA_QME_SCOM_XIRAMEDR_IR_LEN = 32;
// eq/reg00012.H

static const uint64_t QME_SCOM_XISIB = 0x200e0218ull;

static const uint32_t QME_SCOM_XISIB_ADDR = 0;
static const uint32_t QME_SCOM_XISIB_ADDR_LEN = 32;
static const uint32_t QME_SCOM_XISIB_R_NW = 32;
static const uint32_t QME_SCOM_XISIB_BUSY = 33;
static const uint32_t QME_SCOM_XISIB_IMPRECISE_ERROR_PENDING = 34;
static const uint32_t QME_SCOM_XISIB_RSP_INFO = 49;
static const uint32_t QME_SCOM_XISIB_RSP_INFO_LEN = 3;
static const uint32_t QME_SCOM_XISIB_RESET_PENDING = 61;
static const uint32_t QME_SCOM_XISIB_IFETCH_PENDING = 62;
static const uint32_t QME_SCOM_XISIB_DATAOP_PENDING = 63;
// eq/reg00012.H

static const uint64_t XSTOP_INTERRUPT_REG = 0x200f001cull;
// eq/reg00012.H

}
}
#include "eq/reg00012.H"
#endif
