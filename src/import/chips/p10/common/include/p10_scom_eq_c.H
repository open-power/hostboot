/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_eq_c.H $         */
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

#ifndef __p10_scom_eq_c_H_
#define __p10_scom_eq_c_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace eq
{
#endif


//>> [CPLT_CTRL2]
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
//<< [CPLT_CTRL2]
// eq/reg00012.H

//>> [CPLT_MASK0]
static const uint64_t CPLT_MASK0 = 0x20000101ull;

static const uint32_t CPLT_MASK0_ITR_MASK = 0;
static const uint32_t CPLT_MASK0_ITR_MASK_LEN = 32;
//<< [CPLT_MASK0]
// eq/reg00012.H

//>> [EPS_DBG_MODE_REG]
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
// eq/reg00012.H

//>> [PCB_OPCG_STOP]
static const uint64_t PCB_OPCG_STOP = 0x20030030ull;

static const uint32_t PCB_OPCG_STOP_PCB_OPCGSTOP = 0;
//<< [PCB_OPCG_STOP]
// eq/reg00012.H

//>> [QME_BCEBAR1]
static const uint64_t QME_BCEBAR1 = 0x200e0064ull;

static const uint32_t QME_BCEBAR1_BASE = 8;
static const uint32_t QME_BCEBAR1_BASE_LEN = 36;
static const uint32_t QME_BCEBAR1_SIZE = 61;
static const uint32_t QME_BCEBAR1_SIZE_LEN = 3;
//<< [QME_BCEBAR1]
// eq/reg00012.H

//>> [QME_FLAGS]
static const uint64_t QME_FLAGS_RW = 0x200e0120ull;
static const uint64_t QME_FLAGS_WO_CLEAR = 0x200e0123ull;
static const uint64_t QME_FLAGS_WO_OR = 0x200e0122ull;

static const uint32_t QME_FLAGS_DATA = 0;
static const uint32_t QME_FLAGS_DATA_LEN = 64;
//<< [QME_FLAGS]
// eq/reg00012.H

//>> [QME_PPEDBG]
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
static const uint32_t QME_PPEDBG_EN_MARK_TRACE = 12;
static const uint32_t QME_PPEDBG_EN_EE_TRACE = 13;
static const uint32_t QME_PPEDBG_TRACE_LOWER_SEL1 = 14;
static const uint32_t QME_PPEDBG_TRACE_LOWER_SEL1_LEN = 2;
static const uint32_t QME_PPEDBG_FIR_TRIGGER = 16;
static const uint32_t QME_PPEDBG_MIB_GPIO = 17;
static const uint32_t QME_PPEDBG_MIB_GPIO_LEN = 3;
static const uint32_t QME_PPEDBG_TRACE_DATA_SEL = 20;
static const uint32_t QME_PPEDBG_TRACE_DATA_SEL_LEN = 4;
static const uint32_t QME_PPEDBG_QHTM_TRACE_SEL = 25;
static const uint32_t QME_PPEDBG_TRACE_EXT_SEL0 = 26;
static const uint32_t QME_PPEDBG_TRACE_MODE_SEL1 = 27;
static const uint32_t QME_PPEDBG_TRACE_DATA_SEL1 = 28;
static const uint32_t QME_PPEDBG_TRACE_DATA_SEL1_LEN = 4;
//<< [QME_PPEDBG]
// eq/reg00012.H

//>> [QME_PTSR]
static const uint64_t QME_PTSR = 0x200e013cull;

static const uint32_t QME_PTSR_0_DATA = 0;
static const uint32_t QME_PTSR_0_DATA_LEN = 8;
static const uint32_t QME_PTSR_1_DATA = 8;
static const uint32_t QME_PTSR_1_DATA_LEN = 8;
static const uint32_t QME_PTSR_2_DATA = 16;
static const uint32_t QME_PTSR_2_DATA_LEN = 8;
static const uint32_t QME_PTSR_3_DATA = 24;
static const uint32_t QME_PTSR_3_DATA_LEN = 8;
static const uint32_t QME_PTSR_4_DATA = 32;
static const uint32_t QME_PTSR_4_DATA_LEN = 8;
static const uint32_t QME_PTSR_5_DATA = 40;
static const uint32_t QME_PTSR_5_DATA_LEN = 8;
static const uint32_t QME_PTSR_6_DATA = 48;
static const uint32_t QME_PTSR_6_DATA_LEN = 8;
static const uint32_t QME_PTSR_7_DATA = 56;
static const uint32_t QME_PTSR_7_DATA_LEN = 8;
//<< [QME_PTSR]
// eq/reg00012.H

//>> [QME_RCIMR]
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
//<< [QME_RCIMR]
// eq/reg00012.H

//>> [QME_RCTAR1]
static const uint64_t QME_RCTAR1 = 0x200e0194ull;

static const uint32_t QME_RCTAR1_DATA = 0;
static const uint32_t QME_RCTAR1_DATA_LEN = 64;
//<< [QME_RCTAR1]
// eq/reg00012.H

//>> [QME_SCOM_PBTXTR0]
static const uint64_t QME_SCOM_PBTXTR0 = 0x200e0040ull;

static const uint32_t QME_SCOM_PBTXTR0_VALID = 0;
static const uint32_t QME_SCOM_PBTXTR0_VALID_LEN = 8;
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
//<< [QME_SCOM_PBTXTR0]
// eq/reg00012.H

//>> [QME_SCOM_XIRAMDBG]
static const uint64_t QME_SCOM_XIRAMDBG = 0x200e020cull;

static const uint32_t QME_SCOM_XIRAMDBG_XSR_HS = 0;
static const uint32_t QME_SCOM_XIRAMDBG_XSR_HC = 1;
static const uint32_t QME_SCOM_XIRAMDBG_XSR_HC_LEN = 3;
static const uint32_t QME_SCOM_XIRAMDBG_XSR_HCP = 4;
static const uint32_t QME_SCOM_XIRAMDBG_XSR_RIP = 5;
static const uint32_t QME_SCOM_XIRAMDBG_XSR_SIP = 6;
static const uint32_t QME_SCOM_XIRAMDBG_XSR_TRAP = 7;
static const uint32_t QME_SCOM_XIRAMDBG_XSR_IAC = 8;
static const uint32_t QME_SCOM_XIRAMDBG_XSR_SIB = 9;
static const uint32_t QME_SCOM_XIRAMDBG_XSR_SIB_LEN = 3;
static const uint32_t QME_SCOM_XIRAMDBG_XSR_RDAC = 12;
static const uint32_t QME_SCOM_XIRAMDBG_XSR_WDAC = 13;
static const uint32_t QME_SCOM_XIRAMDBG_XSR_WS = 14;
static const uint32_t QME_SCOM_XIRAMDBG_XSR_TRH = 15;
static const uint32_t QME_SCOM_XIRAMDBG_XSR_SMS = 16;
static const uint32_t QME_SCOM_XIRAMDBG_XSR_SMS_LEN = 4;
static const uint32_t QME_SCOM_XIRAMDBG_XSR_LP = 20;
static const uint32_t QME_SCOM_XIRAMDBG_XSR_EP = 21;
static const uint32_t QME_SCOM_XIRAMDBG_XSR_PTR = 24;
static const uint32_t QME_SCOM_XIRAMDBG_XSR_ST = 25;
static const uint32_t QME_SCOM_XIRAMDBG_XSR_MFE = 28;
static const uint32_t QME_SCOM_XIRAMDBG_XSR_MCS = 29;
static const uint32_t QME_SCOM_XIRAMDBG_XSR_MCS_LEN = 3;
static const uint32_t QME_SCOM_XIRAMDBG_SPRG0 = 32;
static const uint32_t QME_SCOM_XIRAMDBG_SPRG0_LEN = 32;
//<< [QME_SCOM_XIRAMDBG]
// eq/reg00012.H

//>> [QME_SCOM_XIRAMGA]
static const uint64_t QME_SCOM_XIRAMGA = 0x200e0208ull;

static const uint32_t QME_SCOM_XIRAMGA_QME_SCOM_XIRAMEDR_IR = 0;
static const uint32_t QME_SCOM_XIRAMGA_QME_SCOM_XIRAMEDR_IR_LEN = 32;
static const uint32_t QME_SCOM_XIRAMGA_SPRG0 = 32;
static const uint32_t QME_SCOM_XIRAMGA_SPRG0_LEN = 32;
//<< [QME_SCOM_XIRAMGA]
// eq/reg00012.H

//>> [QME_SCOM_XISIB]
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
//<< [QME_SCOM_XISIB]
// eq/reg00012.H

//>> [SCAN64CONTSCAN]
static const uint64_t SCAN64CONTSCAN = 0x2003f000ull;

static const uint32_t SCAN64CONTSCAN_SCAN64CONTSCAN_REG = 0;
static const uint32_t SCAN64CONTSCAN_SCAN64CONTSCAN_REG_LEN = 64;
//<< [SCAN64CONTSCAN]
// eq/reg00012.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "eq/reg00012.H"
#endif
#endif
