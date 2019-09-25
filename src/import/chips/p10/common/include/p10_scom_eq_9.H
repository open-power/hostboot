/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_eq_9.H $         */
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

#ifndef __p10_scom_eq_9_H_
#define __p10_scom_eq_9_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace eq
{
#endif


static const uint64_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES = 0x20018336ull;

static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ORE_PDLY_STATE = 10;
static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ORE_PDLY_STATE_LEN = 6;
static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ACHE_PDLY_STATE = 26;
static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ACHE_PDLY_STATE_LEN = 6;
// eq/reg00009.H

static const uint64_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA = 0x20018339ull;

static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_IS_LATE = 3;
static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_IS_LATE_HIST = 4;
static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_IS_LATE_HIST_LEN = 4;
static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_IS_LATE = 11;
static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_IS_LATE_HIST = 12;
static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_IS_LATE_HIST_LEN = 4;
static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_PDLY_CONFIG = 16;
static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CORE_PDLY_CONFIG_LEN = 4;
static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_PDLY_CONFIG = 20;
static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SENSOR_DATA_CACHE_PDLY_CONFIG_LEN = 4;
// eq/reg00009.H

static const uint64_t CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG = 0x2001430cull;

static const uint32_t CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE = 0;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR = 1;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR = 2;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE = 3;
// eq/reg00009.H

static const uint64_t CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS = 0x20014317ull;

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
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG = 24;
static const uint32_t CLK_ADJ_01_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG_LEN = 8;
// eq/reg00009.H

static const uint64_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE = 0x20014322ull;
// eq/reg00009.H

static const uint64_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_SET_INIT_MODE = 0x20014320ull;
// eq/reg00009.H

static const uint64_t CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT = 0x20012318ull;

static const uint32_t CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_1_VAL = 0;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_2_VAL = 1;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_2_VAL_LEN = 7;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_3_VAL = 8;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_4_VAL = 9;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_PHASE_MEASUREMENT_4_VAL_LEN = 7;
// eq/reg00009.H

static const uint64_t CLK_ADJ_02_DCADJ_WRAP_SET_DCC_TARGET = 0x20012308ull;

static const uint32_t CLK_ADJ_02_DCADJ_WRAP_SET_DCC_TARGET_TARGET_VALUE = 0;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_SET_DCC_TARGET_TARGET_VALUE_LEN = 7;
// eq/reg00009.H

static const uint64_t CLK_ADJ_02_DCADJ_WRAP_SET_MEASURE_ONLY_MODE = 0x20012311ull;
// eq/reg00009.H

static const uint64_t CLK_ADJ_03_DCADJ_WRAP_SET_COMP_DLY = 0x2001130bull;

static const uint32_t CLK_ADJ_03_DCADJ_WRAP_SET_COMP_DLY_COMP_DELAY_VALUE = 0;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_SET_COMP_DLY_COMP_DELAY_VALUE_LEN = 16;
// eq/reg00009.H

static const uint64_t CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS = 0x20011317ull;

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
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG = 24;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG_LEN = 8;
// eq/reg00009.H

static const uint64_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CACHE_PDLYS = 0x2001132dull;

static const uint32_t CLK_ADJ_03_SKEW_WRAP_SKEWADJ_SET_INVERT_CACHE_PDLYS_CACHE_PDLYS_INVERT = 0;
// eq/reg00009.H

static const uint64_t CPLT_CTRL4_RW = 0x20000004ull;
static const uint64_t CPLT_CTRL4_WO_CLEAR = 0x20000024ull;
static const uint64_t CPLT_CTRL4_WO_OR = 0x20000014ull;

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
// eq/reg00009.H

static const uint64_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK3 = 0x20040083ull;

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
// eq/reg00009.H

static const uint64_t EPS_THERM_WSUB_DTS_RESULT1 = 0x20050001ull;

static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_4_RESULT = 0;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_4_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_5_RESULT = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_5_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_6_RESULT = 32;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT1_6_RESULT_LEN = 16;
// eq/reg00009.H

static const uint64_t EPS_THERM_WSUB_SKITTER_DATA2 = 0x2005001bull;
// eq/reg00009.H

static const uint64_t EPS_THERM_WSUB_SKITTER_FORCE_REG = 0x20050014ull;

static const uint32_t EPS_THERM_WSUB_SKITTER_FORCE_REG_F_SKITTER_READ = 0;
// eq/reg00009.H

static const uint64_t EPS_THERM_WSUB2_SKITTER_FORCE_REG = 0x20050034ull;

static const uint32_t EPS_THERM_WSUB2_SKITTER_FORCE_REG_F_SKITTER_READ = 0;
// eq/reg00009.H

static const uint64_t L3TRA0_TR0_CONFIG_0 = 0x20018203ull;

static const uint32_t L3TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t L3TRA0_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// eq/reg00009.H

static const uint64_t L3TRA0_TR1_CONFIG_9 = 0x20018229ull;

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
static const uint32_t L3TRA0_TR1_CONFIG_9_SPARE_LT = 37;
// eq/reg00009.H

static const uint64_t L3TRA2_TR1_CONFIG_1 = 0x200182a4ull;

static const uint32_t L3TRA2_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t L3TRA2_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// eq/reg00009.H

static const uint64_t MULTICAST_GROUP_2 = 0x200f0002ull;

static const uint32_t MULTICAST_GROUP_2_MULTICAST2_GROUP = 3;
static const uint32_t MULTICAST_GROUP_2_MULTICAST2_GROUP_LEN = 3;
// eq/reg00009.H

static const uint64_t QMETRA0_TR0_CONFIG_9 = 0x20018409ull;

static const uint32_t QMETRA0_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t QMETRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t QMETRA0_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t QMETRA0_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t QMETRA0_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t QMETRA0_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t QMETRA0_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t QMETRA0_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t QMETRA0_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t QMETRA0_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t QMETRA0_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t QMETRA0_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t QMETRA0_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t QMETRA0_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t QMETRA0_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t QMETRA0_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t QMETRA0_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t QMETRA0_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t QMETRA0_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t QMETRA0_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t QMETRA0_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t QMETRA0_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t QMETRA0_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t QMETRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t QMETRA0_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t QMETRA0_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t QMETRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
static const uint32_t QMETRA0_TR0_CONFIG_9_SPARE_LT = 37;
// eq/reg00009.H

static const uint64_t QMETRA0_TR1_CONFIG_0 = 0x20018423ull;

static const uint32_t QMETRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t QMETRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// eq/reg00009.H

static const uint64_t QME_DB2 = 0x200e0108ull;

static const uint32_t QME_DB2_MESSAGE_NUMBER = 0;
static const uint32_t QME_DB2_MESSAGE_NUMBER_LEN = 8;
// eq/reg00009.H

static const uint64_t QME_PSSUM = 0x200e0134ull;

static const uint32_t QME_PSSUM_PSTATE_REQ_C0 = 0;
static const uint32_t QME_PSSUM_PSTATE_REQ_C0_LEN = 8;
static const uint32_t QME_PSSUM_PSTATE_REQ_C1 = 8;
static const uint32_t QME_PSSUM_PSTATE_REQ_C1_LEN = 8;
static const uint32_t QME_PSSUM_PSTATE_REQ_C2 = 16;
static const uint32_t QME_PSSUM_PSTATE_REQ_C2_LEN = 8;
static const uint32_t QME_PSSUM_PSTATE_REQ_C3 = 24;
static const uint32_t QME_PSSUM_PSTATE_REQ_C3_LEN = 8;
static const uint32_t QME_PSSUM_PSTATE_REQ_QUAD = 32;
static const uint32_t QME_PSSUM_PSTATE_REQ_QUAD_LEN = 8;
static const uint32_t QME_PSSUM_RECENT_CORE_NUM = 42;
static const uint32_t QME_PSSUM_RECENT_CORE_NUM_LEN = 2;
static const uint32_t QME_PSSUM_QME_QMCR_CORE_PARTIAL_GOOD = 48;
static const uint32_t QME_PSSUM_QME_QMCR_CORE_PARTIAL_GOOD_LEN = 4;
static const uint32_t QME_PSSUM_QME_QMCR_AUTO_PMCR_UPDATE = 52;
static const uint32_t QME_PSSUM_QME_QMCR_PMCR_RECENT_MODE = 53;
static const uint32_t QME_PSSUM_PMCR_PIG_PENDING = 55;
// eq/reg00009.H

static const uint64_t XSTOP = 0x20040000ull;

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
// eq/reg00009.H

#ifndef __PPE_HCODE__
}
}
#include "eq/reg00009.H"
#endif
#endif
