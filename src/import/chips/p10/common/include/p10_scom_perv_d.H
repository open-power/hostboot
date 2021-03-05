/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_perv_d.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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

#ifndef __p10_scom_perv_d_H_
#define __p10_scom_perv_d_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif


//>> [CTRL_ATOMIC_LOCK_REG]
static const uint64_t CTRL_ATOMIC_LOCK_REG = 0x000003ffull;

static const uint32_t CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE = 0;
static const uint32_t CTRL_ATOMIC_LOCK_REG_ID = 1;
static const uint32_t CTRL_ATOMIC_LOCK_REG_ID_LEN = 4;
static const uint32_t CTRL_ATOMIC_LOCK_REG_ACTIVITY = 8;
static const uint32_t CTRL_ATOMIC_LOCK_REG_ACTIVITY_LEN = 8;
//<< [CTRL_ATOMIC_LOCK_REG]
// perv/reg00026.H

//>> [P10_20_EPS_DBG_DEBUG_TRACE_CONTROL]
static const uint64_t EPS_DBG_DEBUG_TRACE_CONTROL = 0x000107d0ull; // p10:20,

static const uint32_t P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_START = 0;
static const uint32_t P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_STOP = 1;
static const uint32_t P10_20_EPS_DBG_DEBUG_TRACE_CONTROL_RESET = 2;
//<< [P10_20_EPS_DBG_DEBUG_TRACE_CONTROL]
// perv/reg00026.H

//>> [FSXCOMP_FSXLOG_ROOT_CTRL0_COPY]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI = 0x00002910ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_FSI_BYTE = 0x00002c40ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_RW = 0x00050110ull;

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_ROOT_CTRL0_COPY_REG = 0;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL0_COPY_ROOT_CTRL0_COPY_REG_LEN = 32;
//<< [FSXCOMP_FSXLOG_ROOT_CTRL0_COPY]
// perv/reg00026.H

//>> [FSXCOMP_FSXLOG_ROOT_CTRL5]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_FSI = 0x00002815ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_FSI_BYTE = 0x00002854ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_RW = 0x00050015ull;

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_RESET_DC = 0;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_BYPASS_DC = 1;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_FORCE_BYPASS_CLKSEL_DC = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_TPFSI_RCS_CLK_TEST_IN_DC = 3;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_SWO_FORCE_LOW = 4;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_BLOCK_SWO = 5;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_A = 6;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_CLEAR_CLK_ERROR_B = 7;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_SEL_DEL = 8;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_DESKEW = 9;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_DESKEW_LEN = 3;
static const uint32_t P10_20_FSXCOMP_FSXLOG_ROOT_CTRL5_RCS_CONTROL_10_8 = 9; // p10:20,
static const uint32_t P10_20_FSXCOMP_FSXLOG_ROOT_CTRL5_RCS_CONTROL_10_8_LEN = 3;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_FILT = 12;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_FILT_LEN = 4;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_PFD_PW_SEL = 16;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_FORCE_ERROR_HIGH = 17;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_EN = 18;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_SEL = 19;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_TESTOUT_SEL_LEN = 3;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_A = 22;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_EN_OVERRIDE_B = 23;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_OVRBIT = 24;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_OVRBIT_LEN = 6;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_EN_REFCLK = 30;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL5_EN_ASYNC_OUT = 31;
//<< [FSXCOMP_FSXLOG_ROOT_CTRL5]
// perv/reg00026.H

//>> [FSXCOMP_FSXLOG_SB_MSG]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_SB_MSG = 0x00050009ull;
static const uint32_t FSXCOMP_FSXLOG_SB_MSG_FSI = 0x00002809ull;
static const uint32_t FSXCOMP_FSXLOG_SB_MSG_FSI_BYTE = 0x00002824ull;
//<< [FSXCOMP_FSXLOG_SB_MSG]
// perv/reg00026.H

//>> [FSXCOMP_FSXLOG_SCRATCH_REGISTER_1]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI = 0x00002838ull;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI_BYTE = 0x000028e0ull;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_RW = 0x00050038ull;

static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_SR_SCRATCH_REGISTER_1 = 0;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_SR_SCRATCH_REGISTER_1_LEN = 32;
//<< [FSXCOMP_FSXLOG_SCRATCH_REGISTER_1]
// perv/reg00026.H

//>> [OPCG_CAPT1]
static const uint64_t OPCG_CAPT1 = 0x00030010ull;

static const uint32_t OPCG_CAPT1_COUNT = 0;
static const uint32_t OPCG_CAPT1_COUNT_LEN = 4;
static const uint32_t OPCG_CAPT1_SEQ_01 = 4;
static const uint32_t OPCG_CAPT1_SEQ_01_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_02 = 9;
static const uint32_t OPCG_CAPT1_SEQ_02_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_03 = 14;
static const uint32_t OPCG_CAPT1_SEQ_03_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_04 = 19;
static const uint32_t OPCG_CAPT1_SEQ_04_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_05 = 24;
static const uint32_t OPCG_CAPT1_SEQ_05_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_06 = 29;
static const uint32_t OPCG_CAPT1_SEQ_06_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_07 = 34;
static const uint32_t OPCG_CAPT1_SEQ_07_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_08 = 39;
static const uint32_t OPCG_CAPT1_SEQ_08_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_09 = 44;
static const uint32_t OPCG_CAPT1_SEQ_09_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_10 = 49;
static const uint32_t OPCG_CAPT1_SEQ_10_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_11 = 54;
static const uint32_t OPCG_CAPT1_SEQ_11_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_12 = 59;
static const uint32_t OPCG_CAPT1_SEQ_12_LEN = 5;
//<< [OPCG_CAPT1]
// perv/reg00026.H

//>> [RECOV_MASK]
static const uint64_t RECOV_MASK_RW = 0x00040041ull;
static const uint64_t RECOV_MASK_WO_CLEAR = 0x00040061ull;
static const uint64_t RECOV_MASK_WO_OR = 0x00040051ull;

static const uint32_t RECOV_MASK_1 = 1;
static const uint32_t RECOV_MASK_2 = 2;
static const uint32_t RECOV_MASK_3 = 3;
static const uint32_t RECOV_MASK_4 = 4;
static const uint32_t RECOV_MASK_5 = 5;
static const uint32_t RECOV_MASK_6 = 6;
static const uint32_t RECOV_MASK_7 = 7;
static const uint32_t RECOV_MASK_8 = 8;
static const uint32_t RECOV_MASK_9 = 9;
static const uint32_t RECOV_MASK_10 = 10;
static const uint32_t RECOV_MASK_11 = 11;
static const uint32_t RECOV_MASK_12 = 12;
static const uint32_t RECOV_MASK_13 = 13;
static const uint32_t RECOV_MASK_14 = 14;
static const uint32_t RECOV_MASK_15 = 15;
static const uint32_t RECOV_MASK_16 = 16;
static const uint32_t RECOV_MASK_17 = 17;
static const uint32_t RECOV_MASK_18 = 18;
static const uint32_t RECOV_MASK_19 = 19;
static const uint32_t RECOV_MASK_20 = 20;
static const uint32_t RECOV_MASK_21 = 21;
static const uint32_t RECOV_MASK_22 = 22;
static const uint32_t RECOV_MASK_23 = 23;
static const uint32_t RECOV_MASK_24 = 24;
static const uint32_t RECOV_MASK_25 = 25;
static const uint32_t RECOV_MASK_26 = 26;
static const uint32_t RECOV_MASK_27 = 27;
static const uint32_t RECOV_MASK_28 = 28;
static const uint32_t RECOV_MASK_29 = 29;
static const uint32_t RECOV_MASK_30 = 30;
static const uint32_t RECOV_MASK_31 = 31;
static const uint32_t RECOV_MASK_32 = 32;
static const uint32_t RECOV_MASK_33 = 33;
static const uint32_t RECOV_MASK_34 = 34;
static const uint32_t RECOV_MASK_35 = 35;
static const uint32_t RECOV_MASK_36 = 36;
static const uint32_t RECOV_MASK_37 = 37;
static const uint32_t RECOV_MASK_38 = 38;
static const uint32_t RECOV_MASK_39 = 39;
static const uint32_t RECOV_MASK_40 = 40;
static const uint32_t RECOV_MASK_41 = 41;
static const uint32_t RECOV_MASK_42 = 42;
static const uint32_t RECOV_MASK_43 = 43;
static const uint32_t RECOV_MASK_44 = 44;
static const uint32_t RECOV_MASK_45 = 45;
static const uint32_t RECOV_MASK_46 = 46;
static const uint32_t RECOV_MASK_47 = 47;
static const uint32_t RECOV_MASK_48 = 48;
static const uint32_t RECOV_MASK_49 = 49;
static const uint32_t RECOV_MASK_50 = 50;
static const uint32_t RECOV_MASK_51 = 51;
static const uint32_t RECOV_MASK_52 = 52;
static const uint32_t RECOV_MASK_53 = 53;
//<< [RECOV_MASK]
// perv/reg00026.H

//>> [TOD_FSM_REG]
static const uint64_t TOD_FSM_REG = 0x00040024ull;

static const uint32_t TOD_FSM_REG_I_PATH_FSM_STATE = 0;
static const uint32_t TOD_FSM_REG_I_PATH_FSM_STATE_LEN = 4;
static const uint32_t TOD_FSM_REG_TOD_IS_RUNNING = 4;
static const uint32_t TOD_FSM_REG_REG_0X24_SPARE_05_07 = 5;
static const uint32_t TOD_FSM_REG_REG_0X24_SPARE_05_07_LEN = 3;
//<< [TOD_FSM_REG]
// perv/reg00026.H

//>> [TOD_PSS_MSS_STATUS_REG]
static const uint64_t TOD_PSS_MSS_STATUS_REG = 0x00040008ull;

static const uint32_t TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT = 0;
static const uint32_t TOD_PSS_MSS_STATUS_REG_PRI_SEC_SELECT_LEN = 3;
static const uint32_t TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_03 = 3;
static const uint32_t TOD_PSS_MSS_STATUS_REG_M_PATH_0_OSC_NOT_VALID_STATUS = 4;
static const uint32_t TOD_PSS_MSS_STATUS_REG_M_PATH_1_OSC_NOT_VALID_STATUS = 5;
static const uint32_t TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_CHECK_VALID = 6;
static const uint32_t TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_CHECK_VALID = 7;
static const uint32_t TOD_PSS_MSS_STATUS_REG_S_PATH_0_STEP_CHECK_VALID = 8;
static const uint32_t TOD_PSS_MSS_STATUS_REG_I_PATH_STEP_CHECK_VALID = 9;
static const uint32_t TOD_PSS_MSS_STATUS_REG_S_PATH_1_STEP_CHECK_VALID = 10;
static const uint32_t TOD_PSS_MSS_STATUS_REG_IS_SPECIAL_STATUS = 11;
static const uint32_t TOD_PSS_MSS_STATUS_REG_PRI_M_PATH_SELECT_STATUS = 12;
static const uint32_t TOD_PSS_MSS_STATUS_REG_PRI_M_S_TOD_SELECT_STATUS = 13;
static const uint32_t TOD_PSS_MSS_STATUS_REG_PRI_M_S_DRAWER_SELECT_STATUS = 14;
static const uint32_t TOD_PSS_MSS_STATUS_REG_PRI_S_PATH_SELECT_STATUS = 15;
static const uint32_t TOD_PSS_MSS_STATUS_REG_SEC_M_PATH_SELECT_STATUS = 16;
static const uint32_t TOD_PSS_MSS_STATUS_REG_SEC_M_S_TOD_SELECT_STATUS = 17;
static const uint32_t TOD_PSS_MSS_STATUS_REG_SEC_M_S_DRAWER_SELECT_STATUS = 18;
static const uint32_t TOD_PSS_MSS_STATUS_REG_SEC_S_PATH_SELECT_STATUS = 19;
static const uint32_t TOD_PSS_MSS_STATUS_REG_IS_RUNNING = 20;
static const uint32_t TOD_PSS_MSS_STATUS_REG_IS_PRIMARY = 21;
static const uint32_t TOD_PSS_MSS_STATUS_REG_IS_SECONDARY = 22;
static const uint32_t TOD_PSS_MSS_STATUS_REG_IS_ACTIVE_MASTER = 23;
static const uint32_t TOD_PSS_MSS_STATUS_REG_IS_BACKUP_MASTER = 24;
static const uint32_t TOD_PSS_MSS_STATUS_REG_IS_SLAVE = 25;
static const uint32_t TOD_PSS_MSS_STATUS_REG_M_PATH_SELECT = 26;
static const uint32_t TOD_PSS_MSS_STATUS_REG_S_PATH_SELECT = 27;
static const uint32_t TOD_PSS_MSS_STATUS_REG_M_PATH_0_STEP_ALIGN_VALID_SWITCH = 28;
static const uint32_t TOD_PSS_MSS_STATUS_REG_M_PATH_1_STEP_ALIGN_VALID_SWITCH = 29;
static const uint32_t TOD_PSS_MSS_STATUS_REG_REG_0X08_SPARE_30 = 30;
static const uint32_t TOD_PSS_MSS_STATUS_REG_M_PATH_SWITCH_TRIGGER = 31;
//<< [TOD_PSS_MSS_STATUS_REG]
// perv/reg00027.H

//>> [TOD_S_PATH_STATUS_REG]
static const uint64_t TOD_S_PATH_STATUS_REG = 0x0004000aull;

static const uint32_t TOD_S_PATH_STATUS_REG_M_PATH_0_STEP_ALIGN_FSM_STATE = 0;
static const uint32_t TOD_S_PATH_STATUS_REG_M_PATH_0_STEP_ALIGN_FSM_STATE_LEN = 4;
static const uint32_t TOD_S_PATH_STATUS_REG_M_PATH_1_STEP_ALIGN_FSM_STATE = 4;
static const uint32_t TOD_S_PATH_STATUS_REG_M_PATH_1_STEP_ALIGN_FSM_STATE_LEN = 4;
static const uint32_t TOD_S_PATH_STATUS_REG_I_PATH_DELAY_ADJUST_RATIO = 8;
static const uint32_t TOD_S_PATH_STATUS_REG_I_PATH_DELAY_ADJUST_RATIO_LEN = 5;
static const uint32_t TOD_S_PATH_STATUS_REG_REG_0X0A_SPARE_13_15 = 13;
static const uint32_t TOD_S_PATH_STATUS_REG_REG_0X0A_SPARE_13_15_LEN = 3;
static const uint32_t TOD_S_PATH_STATUS_REG_S_PATH_0_CPS = 16;
static const uint32_t TOD_S_PATH_STATUS_REG_S_PATH_0_CPS_LEN = 8;
static const uint32_t TOD_S_PATH_STATUS_REG_S_PATH_1_CPS = 24;
static const uint32_t TOD_S_PATH_STATUS_REG_S_PATH_1_CPS_LEN = 8;
static const uint32_t TOD_S_PATH_STATUS_REG_S_PATH_0_REMOTE_SYNC_LATE_COUNT = 32;
static const uint32_t TOD_S_PATH_STATUS_REG_S_PATH_0_REMOTE_SYNC_LATE_COUNT_LEN = 8;
static const uint32_t TOD_S_PATH_STATUS_REG_S_PATH_1_REMOTE_SYNC_LATE_COUNT = 40;
static const uint32_t TOD_S_PATH_STATUS_REG_S_PATH_1_REMOTE_SYNC_LATE_COUNT_LEN = 8;
//<< [TOD_S_PATH_STATUS_REG]
// perv/reg00027.H

//>> [XSTOP5]
static const uint64_t XSTOP5 = 0x00030015ull;

static const uint32_t XSTOP5_ENABLE = 0;
static const uint32_t XSTOP5_WAIT_SNOPA = 1;
static const uint32_t XSTOP5_TRIGGER_OPCG_GO = 2;
static const uint32_t XSTOP5_WAIT_ALWAYS = 3;
static const uint32_t XSTOP5_REGION_PERV = 4;
static const uint32_t XSTOP5_REGION_UNIT1 = 5;
static const uint32_t XSTOP5_REGION_UNIT2 = 6;
static const uint32_t XSTOP5_REGION_UNIT3 = 7;
static const uint32_t XSTOP5_REGION_UNIT4 = 8;
static const uint32_t XSTOP5_REGION_UNIT5 = 9;
static const uint32_t XSTOP5_REGION_UNIT6 = 10;
static const uint32_t XSTOP5_REGION_UNIT7 = 11;
static const uint32_t XSTOP5_REGION_UNIT8 = 12;
static const uint32_t XSTOP5_REGION_UNIT9 = 13;
static const uint32_t XSTOP5_REGION_UNIT10 = 14;
static const uint32_t XSTOP5_REGION_UNIT11 = 15;
static const uint32_t XSTOP5_REGION_UNIT12 = 16;
static const uint32_t XSTOP5_REGION_UNIT13 = 17;
static const uint32_t XSTOP5_REGION_UNIT14 = 18;
static const uint32_t XSTOP5_WAIT_CYCLES = 48;
static const uint32_t XSTOP5_WAIT_CYCLES_LEN = 12;
//<< [XSTOP5]
// perv/reg00027.H

//>> [FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_FSI = 0x00002936ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_FSI_BYTE = 0x00002cd8ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_WO_CLEAR = 0x00050136ull;

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_TP_AN_SYS0_RX_REFCLK_TERM = 0;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_TP_AN_SYS0_RX_REFCLK_TERM_LEN = 2;
static const uint32_t P10_20_FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_ROOT_CTRL6_0_3 = 0; // p10:20,
static const uint32_t P10_20_FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_ROOT_CTRL6_0_3_LEN = 4;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_TP_AN_SYS1_RX_REFCLK_TERM = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_TP_AN_SYS1_RX_REFCLK_TERM_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_TP_AN_PCI0_RX_REFCLK_TERM = 4;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_TP_AN_PCI0_RX_REFCLK_TERM_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_TP_AN_PCI1_RX_REFCLK_TERM = 6;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_TP_AN_PCI1_RX_REFCLK_TERM_LEN = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_ROOT_CTRL6_8_31 = 8;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_ROOT_CTRL6_8_31_LEN = 24;
static const uint32_t P10_20_FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_CHKSW_DD1_HW547515_RCS_EVENTLOG = 8; // p10:20,
static const uint32_t P10_20_FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_ROOT_CTRL6_9_15 = 9; // p10:20,
static const uint32_t P10_20_FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_ROOT_CTRL6_9_15_LEN = 7;
static const uint32_t P10_20_FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_DESKEW_SEL_A = 16; // p10:20,
static const uint32_t P10_20_FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_DESKEW_SEL_A_LEN = 4;
static const uint32_t P10_20_FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_DESKEW_SEL_B = 20; // p10:20,
static const uint32_t P10_20_FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_DESKEW_SEL_B_LEN = 4;
static const uint32_t P10_20_FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_RCS_CONTROL_7_0 = 24; // p10:20,
static const uint32_t P10_20_FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR_RCS_CONTROL_7_0_LEN = 8;
//<< [FSXCOMP_FSXLOG_ROOT_CTRL6_CLEAR]
// perv/reg00026.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "perv/reg00026.H"
#include "perv/reg00027.H"
#endif
#endif
