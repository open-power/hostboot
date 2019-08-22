/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_perv_9.H $       */
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

#ifndef __p10_scom_perv_9_H_
#define __p10_scom_perv_9_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif


static const uint64_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES = 0x00018336ull;

static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ORE_PDLY_STATE = 10;
static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ORE_PDLY_STATE_LEN = 6;
static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ACHE_PDLY_STATE = 26;
static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ACHE_PDLY_STATE_LEN = 6;
// perv/reg00018.H

static const uint64_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA = 0x00018339ull;

static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_ORE_IS_LATE = 3;
static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_ACHE_IS_LATE = 7;
// perv/reg00018.H

static const uint64_t CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG = 0x0001430cull;

static const uint32_t CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE = 0;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR = 1;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR = 2;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE = 3;
// perv/reg00018.H

static const uint64_t CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS = 0x00014317ull;

static const uint32_t CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_MODE_FSM_STATE = 0;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_MODE_FSM_STATE_LEN = 3;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE = 3;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW = 4;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW = 5;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_LOCK = 6;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR = 7;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN = 8;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD1 = 9;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD2 = 10;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_PRELOAD3 = 11;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN = 12;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_CHOP = 13;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_FSM_STATE = 14;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_FSM_STATE_LEN = 5;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE = 19;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE_LEN = 3;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE = 22;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR = 23;
// perv/reg00018.H

static const uint64_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE = 0x00014322ull;
// perv/reg00018.H

static const uint64_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_INIT_MODE = 0x00014320ull;
// perv/reg00018.H

static const uint64_t CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT = 0x00012318ull;

static const uint32_t CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_1_VAL = 0;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_2_VAL = 1;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_2_VAL_LEN = 7;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_3_VAL = 8;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_4_VAL = 9;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_4_VAL_LEN = 7;
// perv/reg00018.H

static const uint64_t CLK_ADJ_02_DCADJ_WRAP_SET_DCC_TARGET = 0x00012308ull;

static const uint32_t CLK_ADJ_02_DCADJ_WRAP_SET_DCC_TARGET_TARGET_VALUE = 0;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_SET_DCC_TARGET_TARGET_VALUE_LEN = 7;
// perv/reg00018.H

static const uint64_t CLK_ADJ_02_DCADJ_WRAP_SET_MEASURE_ONLY_MODE = 0x00012311ull;
// perv/reg00018.H

static const uint64_t CLK_ADJ_03_DCADJ_WRAP_SET_COMP_DLY = 0x0001130bull;

static const uint32_t CLK_ADJ_03_DCADJ_WRAP_SET_COMP_DLY_COMP_DELAY_VALUE = 0;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_SET_COMP_DLY_COMP_DELAY_VALUE_LEN = 16;
// perv/reg00018.H

static const uint64_t CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS = 0x00011317ull;

static const uint32_t CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_MODE_FSM_STATE = 0;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_MODE_FSM_STATE_LEN = 3;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE = 3;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW = 4;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW = 5;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_LOCK = 6;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR = 7;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN = 8;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD1 = 9;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD2 = 10;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_PRELOAD3 = 11;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN = 12;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_CHOP = 13;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_FSM_STATE = 14;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_FSM_STATE_LEN = 5;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE = 19;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE_LEN = 3;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE = 22;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR = 23;
// perv/reg00018.H

static const uint64_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CACHE_PDLYS = 0x0001132dull;

static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CACHE_PDLYS_CACHE_PDLYS_INVERT = 0;
// perv/reg00018.H

static const uint64_t CPLT_CTRL4_RW = 0x00000004ull;
static const uint64_t CPLT_CTRL4_WO_CLEAR = 0x00000024ull;
static const uint64_t CPLT_CTRL4_WO_OR = 0x00000014ull;

static const uint32_t CPLT_CTRL4_0_FLUSHMODE_INH = 4;
static const uint32_t CPLT_CTRL4_1_FLUSHMODE_INH = 5;
static const uint32_t CPLT_CTRL4_2_FLUSHMODE_INH = 6;
static const uint32_t CPLT_CTRL4_3_FLUSHMODE_INH = 7;
static const uint32_t CPLT_CTRL4_4_FLUSHMODE_INH = 8;
static const uint32_t CPLT_CTRL4_5_FLUSHMODE_INH = 9;
static const uint32_t CPLT_CTRL4_6_FLUSHMODE_INH = 10;
static const uint32_t CPLT_CTRL4_7_FLUSHMODE_INH = 11;
static const uint32_t CPLT_CTRL4_8_FLUSHMODE_INH = 12;
static const uint32_t CPLT_CTRL4_9_FLUSHMODE_INH = 13;
static const uint32_t CPLT_CTRL4_10_FLUSHMODE_INH = 14;
static const uint32_t CPLT_CTRL4_11_FLUSHMODE_INH = 15;
static const uint32_t CPLT_CTRL4_12_FLUSHMODE_INH = 16;
static const uint32_t CPLT_CTRL4_13_FLUSHMODE_INH = 17;
static const uint32_t CPLT_CTRL4_14_FLUSHMODE_INH = 18;
// perv/reg00018.H

static const uint64_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3 = 0x00040083ull;

static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_XSTOP_ERR = 0;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_RECOV_ERR = 1;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SPATTN_ERR = 2;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_LXSTOP_ERR = 3;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_HOSTATTN_ERR = 4;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_ERR = 5;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_SYS_XSTOP_STAGED_ERR = 6;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_DBG_TRIG_ERR = 7;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP01 = 12;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP02 = 13;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP03 = 14;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP04 = 15;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP05 = 16;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP06 = 17;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP07 = 18;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP08 = 19;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP09 = 20;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP010 = 21;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP011 = 22;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP012 = 23;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP013 = 24;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP014 = 25;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3_UNIT_TC_FIR_LOCAL_XSTOP015 = 26;
// perv/reg00018.H

static const uint64_t EPS_THERM_WSUB_DTS_RESULT1 = 0x00050001ull;

static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_4_RESULT = 0;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_4_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_5_RESULT = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_5_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_6_RESULT = 32;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_6_RESULT_LEN = 16;
// perv/reg00018.H

static const uint64_t EPS_THERM_WSUB_SKITTER_DATA2 = 0x0005001bull;
// perv/reg00018.H

static const uint64_t EPS_THERM_WSUB_SKITTER_FORCE_REG = 0x00050014ull;

static const uint32_t EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ = 0;
// perv/reg00018.H

static const uint64_t EPS_THERM_WSUB2_SKITTER_FORCE_REG = 0x00050034ull;

static const uint32_t EPS_THERM_WSUB2_SKITTER_FORCE_REG_F_SKITTER_READ = 0;
// perv/reg00018.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI = 0x00002804ull;
static const uint32_t FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_BYTE = 0x00002810ull;
static const uint32_t FSXCOMP_FSXLOG_CBS_ENVSTAT_RO = 0x00050004ull;

static const uint32_t FSXCOMP_FSXLOG_CBS_ENVSTAT_TEST_ENABLE = 0;
static const uint32_t FSXCOMP_FSXLOG_CBS_ENVSTAT_CARD_TEST_BSC = 1;
static const uint32_t FSXCOMP_FSXLOG_CBS_ENVSTAT_VDN_GPOOD = 2;
static const uint32_t FSXCOMP_FSXLOG_CBS_ENVSTAT_FSI_IN_ENA = 3;
static const uint32_t FSXCOMP_FSXLOG_CBS_ENVSTAT_CHIP_MASTER = 4;
static const uint32_t FSXCOMP_FSXLOG_CBS_ENVSTAT_SMD = 5;
static const uint32_t FSXCOMP_FSXLOG_CBS_ENVSTAT_JTAG_TMS = 6;
// perv/reg00018.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M1A_DATA_AREA_9_FSI = 0x00002849ull;
static const uint32_t FSXCOMP_FSXLOG_M1A_DATA_AREA_9_FSI_BYTE = 0x00002924ull;
static const uint32_t FSXCOMP_FSXLOG_M1A_DATA_AREA_9_RW = 0x00050049ull;
// perv/reg00018.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M1B_DATA_AREA_12_FSI = 0x0000288cull;
static const uint32_t FSXCOMP_FSXLOG_M1B_DATA_AREA_12_FSI_BYTE = 0x00002a30ull;
static const uint32_t FSXCOMP_FSXLOG_M1B_DATA_AREA_12_RW = 0x0005008cull;
// perv/reg00018.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M1B_DATA_AREA_3_FSI = 0x00002883ull;
static const uint32_t FSXCOMP_FSXLOG_M1B_DATA_AREA_3_FSI_BYTE = 0x00002a0cull;
static const uint32_t FSXCOMP_FSXLOG_M1B_DATA_AREA_3_RW = 0x00050083ull;
// perv/reg00018.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M2A_DATA_AREA_5_FSI = 0x000028c5ull;
static const uint32_t FSXCOMP_FSXLOG_M2A_DATA_AREA_5_FSI_BYTE = 0x00002b14ull;
static const uint32_t FSXCOMP_FSXLOG_M2A_DATA_AREA_5_RW = 0x000500c5ull;
// perv/reg00018.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI = 0x00002832ull;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_FSI_BYTE = 0x000028c8ull;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_RW_WCLEAR = 0x00050032ull;

static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_2 = 21;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_2 = 22;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_2 = 23;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_DOORBELL_ERROR_MAILBOX_1 = 29;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_XUP_MAILBOX_1 = 30;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_SLAVE_A_DOORBELL_INTERRUPT_PIB_SLAVE_A_PENDING_MAILBOX_1 = 31;
// perv/reg00018.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_COPY_FSI = 0x0000291bull;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_COPY_FSI_BYTE = 0x00002c6cull;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_COPY_RW = 0x0005011bull;
// perv/reg00018.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI = 0x00002937ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_FSI_BYTE = 0x00002cdcull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_WO_CLEAR = 0x00050137ull;

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM0_REFCLK_DRVR_EN_DC = 0;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM1_REFCLK_DRVR_EN_DC = 1;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM2_REFCLK_DRVR_EN_DC = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM3_REFCLK_DRVR_EN_DC = 3;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM4_REFCLK_DRVR_EN_DC = 4;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM5_REFCLK_DRVR_EN_DC = 5;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM6_REFCLK_DRVR_EN_DC = 6;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM7_REFCLK_DRVR_EN_DC = 7;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM8_REFCLK_DRVR_EN_DC = 8;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEM9_REFCLK_DRVR_EN_DC = 9;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMA_REFCLK_DRVR_EN_DC = 10;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMB_REFCLK_DRVR_EN_DC = 11;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMC_REFCLK_DRVR_EN_DC = 12;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMD_REFCLK_DRVR_EN_DC = 13;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEME_REFCLK_DRVR_EN_DC = 14;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_MEMF_REFCLK_DRVR_EN_DC = 15;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0A_REFCLK_DRVR_EN_DC = 16;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP0B_REFCLK_DRVR_EN_DC = 17;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3A_REFCLK_DRVR_EN_DC = 18;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP3B_REFCLK_DRVR_EN_DC = 19;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP4_REFCLK_DRVR_EN_DC = 20;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP5_REFCLK_DRVR_EN_DC = 21;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP6_REFCLK_DRVR_EN_DC = 22;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_TP_OP7_REFCLK_DRVR_EN_DC = 23;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL = 24;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL = 25;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL = 26;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL = 27;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL = 28;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL = 29;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL = 30;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_CLEAR_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL = 31;
// perv/reg00018.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_FSI = 0x0000283full;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_FSI_BYTE = 0x000028fcull;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_RW = 0x0005003full;

static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_SR_SCRATCH_REGISTER_8 = 0;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_SR_SCRATCH_REGISTER_8_LEN = 32;
// perv/reg00018.H

static const uint64_t IGNORE_PAR_REG = 0x000f001cull;

static const uint32_t IGNORE_PAR_REG_IGNORE_PARITY_REG = 0;
static const uint32_t IGNORE_PAR_REG_DISABLE_ECC_CORRECTION = 1;
static const uint32_t IGNORE_PAR_REG_ECC_S_BIT_ERROR = 2;
static const uint32_t IGNORE_PAR_REG_ENABLE_BNDY_LATS = 3;
static const uint32_t IGNORE_PAR_REG_ENABLE_EXTENDED_RSP = 4;
// perv/reg00018.H

static const uint64_t L3TRA0_TR0_CONFIG_0 = 0x00018203ull;

static const uint32_t L3TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t L3TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// perv/reg00018.H

static const uint64_t L3TRA0_TR1_CONFIG_9 = 0x00018229ull;

static const uint32_t L3TRA0_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t L3TRA0_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t L3TRA0_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t L3TRA0_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t L3TRA0_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t L3TRA0_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t L3TRA0_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t L3TRA0_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t L3TRA0_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t L3TRA0_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t L3TRA0_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t L3TRA0_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t L3TRA0_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t L3TRA0_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t L3TRA0_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t L3TRA0_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t L3TRA0_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t L3TRA0_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t L3TRA0_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t L3TRA0_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t L3TRA0_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t L3TRA0_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t L3TRA0_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t L3TRA0_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t L3TRA0_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t L3TRA0_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t L3TRA0_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// perv/reg00018.H

static const uint64_t L3TRA2_TR1_CONFIG_1 = 0x000182a4ull;

static const uint32_t L3TRA2_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t L3TRA2_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// perv/reg00018.H

static const uint64_t MULTICAST_GROUP_2 = 0x000f0002ull;

static const uint32_t MULTICAST_GROUP_2_MULTICAST2_GROUP = 3;
static const uint32_t MULTICAST_GROUP_2_MULTICAST2_GROUP_LEN = 3;
// perv/reg00018.H

static const uint64_t OTPC_M_DATA_REGISTER = 0x00010003ull;

static const uint32_t OTPC_M_DATA_REGISTER_OTP_DATA_REGISTER = 0;
static const uint32_t OTPC_M_DATA_REGISTER_OTP_DATA_REGISTER_LEN = 64;
// perv/reg00018.H

static const uint64_t OTPC_M_MEASURE_REG12 = 0x0001001cull;

static const uint32_t OTPC_M_MEASURE_REG12_SEEPROM_MEASUREMENT12_DATA = 0;
static const uint32_t OTPC_M_MEASURE_REG12_SEEPROM_MEASUREMENT12_DATA_LEN = 64;
// perv/reg00018.H

static const uint64_t OTPC_M_MEASURE_REG9 = 0x00010019ull;

static const uint32_t OTPC_M_MEASURE_REG9_SEEPROM_MEASUREMENT9_DATA = 0;
static const uint32_t OTPC_M_MEASURE_REG9_SEEPROM_MEASUREMENT9_DATA_LEN = 64;
// perv/reg00018.H

static const uint64_t REC_ERR_MST3_REG1 = 0x000f004dull;

static const uint32_t REC_ERR_MST3_REG1_16_MST3_RESPONSE_BIT = 0;
static const uint32_t REC_ERR_MST3_REG1_16_MST3_ERROR_CODE = 1;
static const uint32_t REC_ERR_MST3_REG1_16_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG1_17_MST3_RESPONSE_BIT = 4;
static const uint32_t REC_ERR_MST3_REG1_17_MST3_ERROR_CODE = 5;
static const uint32_t REC_ERR_MST3_REG1_17_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG1_18_MST3_RESPONSE_BIT = 8;
static const uint32_t REC_ERR_MST3_REG1_18_MST3_ERROR_CODE = 9;
static const uint32_t REC_ERR_MST3_REG1_18_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG1_19_MST3_RESPONSE_BIT = 12;
static const uint32_t REC_ERR_MST3_REG1_19_MST3_ERROR_CODE = 13;
static const uint32_t REC_ERR_MST3_REG1_19_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG1_20_MST3_RESPONSE_BIT = 16;
static const uint32_t REC_ERR_MST3_REG1_20_MST3_ERROR_CODE = 17;
static const uint32_t REC_ERR_MST3_REG1_20_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG1_21_MST3_RESPONSE_BIT = 20;
static const uint32_t REC_ERR_MST3_REG1_21_MST3_ERROR_CODE = 21;
static const uint32_t REC_ERR_MST3_REG1_21_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG1_22_MST3_RESPONSE_BIT = 24;
static const uint32_t REC_ERR_MST3_REG1_22_MST3_ERROR_CODE = 25;
static const uint32_t REC_ERR_MST3_REG1_22_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG1_23_MST3_RESPONSE_BIT = 28;
static const uint32_t REC_ERR_MST3_REG1_23_MST3_ERROR_CODE = 29;
static const uint32_t REC_ERR_MST3_REG1_23_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG1_24_MST3_RESPONSE_BIT = 32;
static const uint32_t REC_ERR_MST3_REG1_24_MST3_ERROR_CODE = 33;
static const uint32_t REC_ERR_MST3_REG1_24_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG1_25_MST3_RESPONSE_BIT = 36;
static const uint32_t REC_ERR_MST3_REG1_25_MST3_ERROR_CODE = 37;
static const uint32_t REC_ERR_MST3_REG1_25_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG1_26_MST3_RESPONSE_BIT = 40;
static const uint32_t REC_ERR_MST3_REG1_26_MST3_ERROR_CODE = 41;
static const uint32_t REC_ERR_MST3_REG1_26_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG1_27_MST3_RESPONSE_BIT = 44;
static const uint32_t REC_ERR_MST3_REG1_27_MST3_ERROR_CODE = 45;
static const uint32_t REC_ERR_MST3_REG1_27_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG1_28_MST3_RESPONSE_BIT = 48;
static const uint32_t REC_ERR_MST3_REG1_28_MST3_ERROR_CODE = 49;
static const uint32_t REC_ERR_MST3_REG1_28_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG1_29_MST3_RESPONSE_BIT = 52;
static const uint32_t REC_ERR_MST3_REG1_29_MST3_ERROR_CODE = 53;
static const uint32_t REC_ERR_MST3_REG1_29_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG1_30_MST3_RESPONSE_BIT = 56;
static const uint32_t REC_ERR_MST3_REG1_30_MST3_ERROR_CODE = 57;
static const uint32_t REC_ERR_MST3_REG1_30_MST3_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST3_REG1_31_MST3_RESPONSE_BIT = 60;
static const uint32_t REC_ERR_MST3_REG1_31_MST3_ERROR_CODE = 61;
static const uint32_t REC_ERR_MST3_REG1_31_MST3_ERROR_CODE_LEN = 3;
// perv/reg00018.H

static const uint64_t REC_ERR_MST7_REG0 = 0x000f005cull;

static const uint32_t REC_ERR_MST7_REG0_MASTER_MST7_RESPONSE_BIT = 0;
static const uint32_t REC_ERR_MST7_REG0_MASTER_MST7_ERROR_CODE = 1;
static const uint32_t REC_ERR_MST7_REG0_MASTER_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG0_SLAVE1_MST7_RESPONSE_BIT = 4;
static const uint32_t REC_ERR_MST7_REG0_SLAVE1_MST7_ERROR_CODE = 5;
static const uint32_t REC_ERR_MST7_REG0_SLAVE1_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG0_SLAVE2_MST7_RESPONSE_BIT = 8;
static const uint32_t REC_ERR_MST7_REG0_SLAVE2_MST7_ERROR_CODE = 9;
static const uint32_t REC_ERR_MST7_REG0_SLAVE2_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG0_SLAVE3_MST7_RESPONSE_BIT = 12;
static const uint32_t REC_ERR_MST7_REG0_SLAVE3_MST7_ERROR_CODE = 13;
static const uint32_t REC_ERR_MST7_REG0_SLAVE3_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG0_SLAVE4_MST7_RESPONSE_BIT = 16;
static const uint32_t REC_ERR_MST7_REG0_SLAVE4_MST7_ERROR_CODE = 17;
static const uint32_t REC_ERR_MST7_REG0_SLAVE4_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG0_SLAVE5_MST7_RESPONSE_BIT = 20;
static const uint32_t REC_ERR_MST7_REG0_SLAVE5_MST7_ERROR_CODE = 21;
static const uint32_t REC_ERR_MST7_REG0_SLAVE5_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG0_SLAVE6_MST7_RESPONSE_BIT = 24;
static const uint32_t REC_ERR_MST7_REG0_SLAVE6_MST7_ERROR_CODE = 25;
static const uint32_t REC_ERR_MST7_REG0_SLAVE6_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG0_SLAVE7_MST7_RESPONSE_BIT = 28;
static const uint32_t REC_ERR_MST7_REG0_SLAVE7_MST7_ERROR_CODE = 29;
static const uint32_t REC_ERR_MST7_REG0_SLAVE7_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG0_SLAVE8_MST7_RESPONSE_BIT = 32;
static const uint32_t REC_ERR_MST7_REG0_SLAVE8_MST7_ERROR_CODE = 33;
static const uint32_t REC_ERR_MST7_REG0_SLAVE8_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG0_SLAVE9_MST7_RESPONSE_BIT = 36;
static const uint32_t REC_ERR_MST7_REG0_SLAVE9_MST7_ERROR_CODE = 37;
static const uint32_t REC_ERR_MST7_REG0_SLAVE9_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG0_SLAVE10_MST7_RESPONSE_BIT = 40;
static const uint32_t REC_ERR_MST7_REG0_SLAVE10_MST7_ERROR_CODE = 41;
static const uint32_t REC_ERR_MST7_REG0_SLAVE10_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG0_SLAVE11_MST7_RESPONSE_BIT = 44;
static const uint32_t REC_ERR_MST7_REG0_SLAVE11_MST7_ERROR_CODE = 45;
static const uint32_t REC_ERR_MST7_REG0_SLAVE11_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG0_SLAVE12_MST7_RESPONSE_BIT = 48;
static const uint32_t REC_ERR_MST7_REG0_SLAVE12_MST7_ERROR_CODE = 49;
static const uint32_t REC_ERR_MST7_REG0_SLAVE12_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG0_SLAVE13_MST7_RESPONSE_BIT = 52;
static const uint32_t REC_ERR_MST7_REG0_SLAVE13_MST7_ERROR_CODE = 53;
static const uint32_t REC_ERR_MST7_REG0_SLAVE13_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG0_SLAVE14_MST7_RESPONSE_BIT = 56;
static const uint32_t REC_ERR_MST7_REG0_SLAVE14_MST7_ERROR_CODE = 57;
static const uint32_t REC_ERR_MST7_REG0_SLAVE14_MST7_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST7_REG0_SLAVE15_MST7_RESPONSE_BIT = 60;
static const uint32_t REC_ERR_MST7_REG0_SLAVE15_MST7_ERROR_CODE = 61;
static const uint32_t REC_ERR_MST7_REG0_SLAVE15_MST7_ERROR_CODE_LEN = 3;
// perv/reg00018.H

static const uint64_t REC_ERR_MST9_REG0 = 0x000f0064ull;

static const uint32_t REC_ERR_MST9_REG0_MASTER_MST9_RESPONSE_BIT = 0;
static const uint32_t REC_ERR_MST9_REG0_MASTER_MST9_ERROR_CODE = 1;
static const uint32_t REC_ERR_MST9_REG0_MASTER_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG0_SLAVE1_MST9_RESPONSE_BIT = 4;
static const uint32_t REC_ERR_MST9_REG0_SLAVE1_MST9_ERROR_CODE = 5;
static const uint32_t REC_ERR_MST9_REG0_SLAVE1_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG0_SLAVE2_MST9_RESPONSE_BIT = 8;
static const uint32_t REC_ERR_MST9_REG0_SLAVE2_MST9_ERROR_CODE = 9;
static const uint32_t REC_ERR_MST9_REG0_SLAVE2_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG0_SLAVE3_MST9_RESPONSE_BIT = 12;
static const uint32_t REC_ERR_MST9_REG0_SLAVE3_MST9_ERROR_CODE = 13;
static const uint32_t REC_ERR_MST9_REG0_SLAVE3_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG0_SLAVE4_MST9_RESPONSE_BIT = 16;
static const uint32_t REC_ERR_MST9_REG0_SLAVE4_MST9_ERROR_CODE = 17;
static const uint32_t REC_ERR_MST9_REG0_SLAVE4_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG0_SLAVE5_MST9_RESPONSE_BIT = 20;
static const uint32_t REC_ERR_MST9_REG0_SLAVE5_MST9_ERROR_CODE = 21;
static const uint32_t REC_ERR_MST9_REG0_SLAVE5_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG0_SLAVE6_MST9_RESPONSE_BIT = 24;
static const uint32_t REC_ERR_MST9_REG0_SLAVE6_MST9_ERROR_CODE = 25;
static const uint32_t REC_ERR_MST9_REG0_SLAVE6_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG0_SLAVE7_MST9_RESPONSE_BIT = 28;
static const uint32_t REC_ERR_MST9_REG0_SLAVE7_MST9_ERROR_CODE = 29;
static const uint32_t REC_ERR_MST9_REG0_SLAVE7_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG0_SLAVE8_MST9_RESPONSE_BIT = 32;
static const uint32_t REC_ERR_MST9_REG0_SLAVE8_MST9_ERROR_CODE = 33;
static const uint32_t REC_ERR_MST9_REG0_SLAVE8_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG0_SLAVE9_MST9_RESPONSE_BIT = 36;
static const uint32_t REC_ERR_MST9_REG0_SLAVE9_MST9_ERROR_CODE = 37;
static const uint32_t REC_ERR_MST9_REG0_SLAVE9_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG0_SLAVE10_MST9_RESPONSE_BIT = 40;
static const uint32_t REC_ERR_MST9_REG0_SLAVE10_MST9_ERROR_CODE = 41;
static const uint32_t REC_ERR_MST9_REG0_SLAVE10_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG0_SLAVE11_MST9_RESPONSE_BIT = 44;
static const uint32_t REC_ERR_MST9_REG0_SLAVE11_MST9_ERROR_CODE = 45;
static const uint32_t REC_ERR_MST9_REG0_SLAVE11_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG0_SLAVE12_MST9_RESPONSE_BIT = 48;
static const uint32_t REC_ERR_MST9_REG0_SLAVE12_MST9_ERROR_CODE = 49;
static const uint32_t REC_ERR_MST9_REG0_SLAVE12_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG0_SLAVE13_MST9_RESPONSE_BIT = 52;
static const uint32_t REC_ERR_MST9_REG0_SLAVE13_MST9_ERROR_CODE = 53;
static const uint32_t REC_ERR_MST9_REG0_SLAVE13_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG0_SLAVE14_MST9_RESPONSE_BIT = 56;
static const uint32_t REC_ERR_MST9_REG0_SLAVE14_MST9_ERROR_CODE = 57;
static const uint32_t REC_ERR_MST9_REG0_SLAVE14_MST9_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST9_REG0_SLAVE15_MST9_RESPONSE_BIT = 60;
static const uint32_t REC_ERR_MST9_REG0_SLAVE15_MST9_ERROR_CODE = 61;
static const uint32_t REC_ERR_MST9_REG0_SLAVE15_MST9_ERROR_CODE_LEN = 3;
// perv/reg00018.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG114 = 0x00018072ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG114_REGISTER114 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG114_REGISTER114_LEN = 64;
// perv/reg00018.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG123 = 0x0001807bull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG123_REGISTER123 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG123_REGISTER123_LEN = 64;
// perv/reg00018.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG32 = 0x00018020ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG32_REGISTER32 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG32_REGISTER32_LEN = 64;
// perv/reg00018.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG53 = 0x00018035ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG53_REGISTER53 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG53_REGISTER53_LEN = 64;
// perv/reg00018.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG64 = 0x00018040ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG64_REGISTER64 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG64_REGISTER64_LEN = 64;
// perv/reg00018.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG91 = 0x0001805bull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG91_REGISTER91 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG91_REGISTER91_LEN = 64;
// perv/reg00018.H

static const uint64_t TOD_TRACE_DATA_1_REG = 0x0004001dull;

static const uint32_t TOD_TRACE_DATA_1_REG_TRACE_DATA_SET_1 = 0;
static const uint32_t TOD_TRACE_DATA_1_REG_TRACE_DATA_SET_1_LEN = 64;
// perv/reg00018.H

static const uint64_t TOD_TRACE_DATA_2_REG = 0x0004001eull;

static const uint32_t TOD_TRACE_DATA_2_REG_TRACE_DATA_SET_2 = 0;
static const uint32_t TOD_TRACE_DATA_2_REG_TRACE_DATA_SET_2_LEN = 64;
// perv/reg00018.H

static const uint64_t TOD_TRACE_DATA_3_REG = 0x0004001full;

static const uint32_t TOD_TRACE_DATA_3_REG_TRACE_DATA_SET_3 = 0;
static const uint32_t TOD_TRACE_DATA_3_REG_TRACE_DATA_SET_3_LEN = 64;
// perv/reg00018.H

static const uint64_t TRA0_TR0_CONFIG_0 = 0x00010403ull;

static const uint32_t TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// perv/reg00018.H

static const uint64_t TRA0_TR1_TRACE_HI_DATA_REG = 0x00010440ull;

static const uint32_t TRA0_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TRA0_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// perv/reg00018.H

static const uint64_t TRA0_TR1_CONFIG_9 = 0x00010449ull;

static const uint32_t TRA0_TR1_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TRA0_TR1_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TRA0_TR1_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TRA0_TR1_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TRA0_TR1_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TRA0_TR1_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TRA0_TR1_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TRA0_TR1_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TRA0_TR1_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TRA0_TR1_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TRA0_TR1_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TRA0_TR1_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TRA0_TR1_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TRA0_TR1_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TRA0_TR1_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TRA0_TR1_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TRA0_TR1_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TRA0_TR1_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TRA0_TR1_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TRA0_TR1_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TRA0_TR1_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TRA0_TR1_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TRA0_TR1_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TRA0_TR1_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TRA0_TR1_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TRA0_TR1_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TRA0_TR1_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// perv/reg00018.H

static const uint64_t TRA2_TR1_CONFIG_1 = 0x00010544ull;

static const uint32_t TRA2_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TRA2_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// perv/reg00019.H

static const uint64_t TRA3_TR0_TRACE_LO_DATA_REG = 0x00010581ull;

static const uint32_t TRA3_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TRA3_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TRA3_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TRA3_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TRA3_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TRA3_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TRA3_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TRA3_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TRA3_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TRA3_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TRA3_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// perv/reg00019.H

static const uint64_t TRA5_TR0_CONFIG_9 = 0x00010689ull;

static const uint32_t TRA5_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TRA5_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TRA5_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TRA5_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TRA5_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TRA5_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TRA5_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TRA5_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TRA5_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TRA5_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TRA5_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TRA5_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TRA5_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TRA5_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TRA5_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TRA5_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TRA5_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TRA5_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TRA5_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TRA5_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TRA5_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TRA5_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TRA5_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TRA5_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TRA5_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TRA5_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TRA5_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// perv/reg00019.H

static const uint64_t TRA5_TR1_CONFIG_0 = 0x000106c3ull;

static const uint32_t TRA5_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TRA5_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// perv/reg00019.H

static const uint64_t TRA7_TR0_CONFIG_1 = 0x00010784ull;

static const uint32_t TRA7_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TRA7_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// perv/reg00019.H

static const uint64_t XSTOP = 0x00040000ull;

static const uint32_t XSTOP_ANY_XSTOP = 0;
static const uint32_t XSTOP_SYSTEM_XSTOP = 1;
static const uint32_t XSTOP_ANY_SPATTN = 2;
static const uint32_t XSTOP_DBG_FIR_XSTOP_ON_TRIG = 3;
static const uint32_t XSTOP_PERV = 4;
static const uint32_t XSTOP_IN05 = 5;
static const uint32_t XSTOP_IN06 = 6;
static const uint32_t XSTOP_IN07 = 7;
static const uint32_t XSTOP_IN08 = 8;
static const uint32_t XSTOP_IN09 = 9;
static const uint32_t XSTOP_IN10 = 10;
static const uint32_t XSTOP_IN11 = 11;
static const uint32_t XSTOP_IN12 = 12;
static const uint32_t XSTOP_IN13 = 13;
static const uint32_t XSTOP_IN14 = 14;
static const uint32_t XSTOP_IN15 = 15;
static const uint32_t XSTOP_IN16 = 16;
static const uint32_t XSTOP_IN17 = 17;
static const uint32_t XSTOP_IN18 = 18;
static const uint32_t XSTOP_IN19 = 19;
static const uint32_t XSTOP_IN20 = 20;
static const uint32_t XSTOP_IN21 = 21;
static const uint32_t XSTOP_IN22 = 22;
static const uint32_t XSTOP_IN23 = 23;
static const uint32_t XSTOP_IN24 = 24;
static const uint32_t XSTOP_IN25 = 25;
static const uint32_t XSTOP_IN26 = 26;
static const uint32_t XSTOP_IN27 = 27;
static const uint32_t XSTOP_IN28 = 28;
static const uint32_t XSTOP_IN29 = 29;
static const uint32_t XSTOP_IN30 = 30;
static const uint32_t XSTOP_IN31 = 31;
static const uint32_t XSTOP_IN32 = 32;
static const uint32_t XSTOP_IN33 = 33;
static const uint32_t XSTOP_IN34 = 34;
static const uint32_t XSTOP_IN35 = 35;
static const uint32_t XSTOP_IN36 = 36;
static const uint32_t XSTOP_IN37 = 37;
static const uint32_t XSTOP_IN38 = 38;
static const uint32_t XSTOP_IN39 = 39;
static const uint32_t XSTOP_IN40 = 40;
static const uint32_t XSTOP_IN41 = 41;
static const uint32_t XSTOP_IN42 = 42;
static const uint32_t XSTOP_IN43 = 43;
static const uint32_t XSTOP_IN44 = 44;
static const uint32_t XSTOP_IN45 = 45;
static const uint32_t XSTOP_IN46 = 46;
static const uint32_t XSTOP_IN47 = 47;
static const uint32_t XSTOP_IN48 = 48;
static const uint32_t XSTOP_IN49 = 49;
static const uint32_t XSTOP_IN50 = 50;
static const uint32_t XSTOP_IN51 = 51;
static const uint32_t XSTOP_IN52 = 52;
static const uint32_t XSTOP_IN53 = 53;
// perv/reg00019.H

#ifndef __PPE_HCODE__
}
}
#include "perv/reg00018.H"
#include "perv/reg00019.H"
#endif
#endif
