/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_perv_1.H $       */
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

#ifndef __p10_scom_perv_1_H_
#define __p10_scom_perv_1_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif


static const uint64_t CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS = 0x00018317ull;

static const uint32_t CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE = 3;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW = 4;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW = 5;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_LOCK = 6;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR = 7;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN = 8;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD1 = 9;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD2 = 10;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_PRELOAD3 = 11;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN = 12;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_CHOP = 13;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_FSM_STATE = 14;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_FSM_STATE_LEN = 5;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE = 19;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE_LEN = 3;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE = 22;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR = 23;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG = 24;
static const uint32_t CLK_ADJ_00_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG_LEN = 8;
// perv/reg00002.H

static const uint64_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE = 0x00018327ull;

static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_ENABLE = 0;
static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_VALUE = 4;
static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_CACHE_OVERRIDE_VALUE_LEN = 4;
// perv/reg00002.H

static const uint64_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE = 0x00018322ull;

static const uint32_t CLK_ADJ_00_SKEW_WRAP_SKEWADJ_SET_ADJUST_MODE_SET_ADJUST_MD = 2;
// perv/reg00002.H

static const uint64_t CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE = 0x00014311ull;

static const uint32_t CLK_ADJ_01_DCADJ_WRAP_SET_MEASURE_ONLY_MODE_SET_MEASURE_ONLY_MD_SET1 = 4;
// perv/reg00002.H

static const uint64_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES = 0x00014336ull;

static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ORE_PDLY_STATE = 10;
static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ORE_PDLY_STATE_LEN = 6;
static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ACHE_PDLY_STATE = 26;
static const uint32_t CLK_ADJ_01_SKEW_WRAP_SKEWADJ_PDLY_FSM_STATES_ACHE_PDLY_STATE_LEN = 6;
// perv/reg00002.H

static const uint64_t CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE = 0x00012301ull;

static const uint32_t CLK_ADJ_02_DCADJ_WRAP_SET_HOLD_MODE_SET_HOLD_MD = 0;
// perv/reg00002.H

static const uint64_t CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS = 0x00012317ull;

static const uint32_t CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ONE_SHOT_STATE = 3;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_OVERFLOW = 4;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_UNDERFLOW = 5;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_LOCK = 6;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUST_ERR = 7;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCSENSE_IN = 8;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD1 = 9;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD2 = 10;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_PRELOAD3 = 11;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_WAIT_CNT_EN = 12;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_CHOP = 13;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_FSM_STATE = 14;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_FSM_STATE_LEN = 5;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE = 19;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_COMP_CYCLE_LEN = 3;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_INVERT_SENSE = 22;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_ADJUSTMENT_DIR = 23;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG = 24;
static const uint32_t CLK_ADJ_02_DCADJ_WRAP_STATUS_BITS_DCC_CONFIG_LEN = 8;
// perv/reg00002.H

static const uint64_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES = 0x0001233bull;

static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_0 = 2;
static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_0_LEN = 6;
static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_1 = 10;
static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_1_LEN = 6;
static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_2 = 18;
static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_2_LEN = 6;
static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_3 = 26;
static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_CACHE_PDLY_FSM_STATES_3_LEN = 6;
// perv/reg00002.H

static const uint64_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE = 0x00012333ull;

static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_STICK_CACHE_SYNC_DONE_CACHE_SYNC_DONE_STICK = 0;
// perv/reg00002.H

static const uint64_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC = 0x0001232full;

static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_SWAP_CACHE_INC_DEC_CACHE_INC_DEC_INVERT = 0;
// perv/reg00002.H

static const uint64_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT = 0x00012328ull;

static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT_WAIT_CNT_VALUE = 0;
static const uint32_t CLK_ADJ_02_SKEW_WRAP_SKEWADJ_SET_WAIT_CNT_WAIT_CNT_VALUE_LEN = 6;
// perv/reg00002.H

static const uint64_t CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG = 0x0001130cull;

static const uint32_t CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_INVERT_SENSE = 0;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_ADJUSTMENT_DIR = 1;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_OVR_PARATIY_ERROR = 2;
static const uint32_t CLK_ADJ_03_DCADJ_WRAP_SET_CONFIG_CHKSW_NO_DCC_CONFIG_VISIBLE = 3;
// perv/reg00002.H

static const uint64_t DBG_CBS_CC = 0x00030013ull;

static const uint32_t DBG_CBS_CC_DBG_RESET_EP = 0;
static const uint32_t DBG_CBS_CC_DBG_OPCG_IP = 1;
static const uint32_t DBG_CBS_CC_DBG_VITL_CLKOFF = 2;
static const uint32_t DBG_CBS_CC_DBG_TEST_ENABLE = 3;
static const uint32_t DBG_CBS_CC_DBG_CBS_REQ = 4;
static const uint32_t DBG_CBS_CC_DBG_CBS_CMD = 5;
static const uint32_t DBG_CBS_CC_DBG_CBS_CMD_LEN = 3;
static const uint32_t DBG_CBS_CC_DBG_CBS_STATE = 8;
static const uint32_t DBG_CBS_CC_DBG_CBS_STATE_LEN = 5;
static const uint32_t DBG_CBS_CC_DBG_SECURITY_DEBUG_MODE = 13;
static const uint32_t DBG_CBS_CC_DBG_CBS_PROTOCOL_ERROR = 14;
static const uint32_t DBG_CBS_CC_DBG_PCB_IDLE = 15;
static const uint32_t DBG_CBS_CC_DBG_CURRENT_OPCG_MODE = 16;
static const uint32_t DBG_CBS_CC_DBG_CURRENT_OPCG_MODE_LEN = 4;
static const uint32_t DBG_CBS_CC_DBG_LAST_OPCG_MODE = 20;
static const uint32_t DBG_CBS_CC_DBG_LAST_OPCG_MODE_LEN = 4;
static const uint32_t DBG_CBS_CC_DBG_PCB_ERROR = 24;
static const uint32_t DBG_CBS_CC_DBG_PARITY_ERROR = 25;
static const uint32_t DBG_CBS_CC_DBG_CC_ERROR = 26;
static const uint32_t DBG_CBS_CC_DBG_CHIPLET_IS_ALIGNED = 27;
static const uint32_t DBG_CBS_CC_DBG_PCB_REQUEST_SINCE_RESET = 28;
static const uint32_t DBG_CBS_CC_DBG_PARANOIA_TEST_ENABLE_CHANGE = 29;
static const uint32_t DBG_CBS_CC_DBG_PARANOIA_VITL_CLKOFF_CHANGE = 30;
static const uint32_t DBG_CBS_CC_TP_TPFSI_CBS_ACK = 31;
// perv/reg00002.H

static const uint64_t EPS_PSC_ADDR_TRAP_REG = 0x00010003ull;

static const uint32_t EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR = 0;
static const uint32_t EPS_PSC_ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR_LEN = 16;
static const uint32_t EPS_PSC_ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR = 16;
static const uint32_t EPS_PSC_ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT = 17;
static const uint32_t EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR = 18;
static const uint32_t EPS_PSC_ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR_LEN = 13;
static const uint32_t EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY = 31;
static const uint32_t EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR = 32;
static const uint32_t EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION = 33;
static const uint32_t EPS_PSC_ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER = 34;
static const uint32_t EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID = 35;
static const uint32_t EPS_PSC_ADDR_TRAP_REG_LAST_MASTERID_LEN = 4;
// perv/reg00002.H

static const uint64_t EPS_PSC_PSCOM_MODE_REG = 0x00010000ull;

static const uint32_t EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_ADDR_PARITY_ERROR = 0;
static const uint32_t EPS_PSC_PSCOM_MODE_REG_ABORT_ON_PCB_WDATA_PARITY_ERROR = 1;
static const uint32_t EPS_PSC_PSCOM_MODE_REG_ABORT_ON_DL_RETURN_WDATA_PARITY_ERROR = 3;
static const uint32_t EPS_PSC_PSCOM_MODE_REG_WATCHDOG_ENABLE = 4;
static const uint32_t EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT = 5;
static const uint32_t EPS_PSC_PSCOM_MODE_REG_SCOM_HANG_LIMIT_LEN = 2;
static const uint32_t EPS_PSC_PSCOM_MODE_REG_FORCE_ALL_RINGS = 7;
static const uint32_t EPS_PSC_PSCOM_MODE_REG_FSM_SELFRESET_ON_STATEVEC_PARITYERROR_ENABLE = 8;
static const uint32_t EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT = 9;
static const uint32_t EPS_PSC_PSCOM_MODE_REG_RESERVED_PSCOM_MODE_LT_LEN = 3;
// perv/reg00002.H

static const uint64_t EPS_THERM_WSUB2_DTS_TRC_RESULT = 0x00050023ull;

static const uint32_t EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE = 0;
static const uint32_t EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_VALUE_LEN = 44;
static const uint32_t EPS_THERM_WSUB2_DTS_TRC_RESULT_TIMESTAMP_COUNTER_OVERFLOW_ERR = 44;
static const uint32_t EPS_THERM_WSUB2_DTS_TRC_RESULT_DTS_1_RESULT = 48;
static const uint32_t EPS_THERM_WSUB2_DTS_TRC_RESULT_DTS_1_RESULT_LEN = 16;
// perv/reg00002.H

static const uint64_t EPS_THERM_WSUB2_ERR_STATUS_REG = 0x00050033ull;

static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_SERIAL_SHIFTCNT_MODEREG_PARITY_ERR_HOLD = 0;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_THERM_MODEREG_PARITY_ERR_HOLD = 1;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_MODEREG_PARITY_ERR_HOLD = 2;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_FORCEREG_PARITY_ERR_HOLD = 3;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_SCAN_INIT_VERSION_REG_PARITY_ERR_HOLD = 4;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_VOLT_MODEREG_PARITY_ERR_HOLD = 5;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_SKITTER_CLKSRCREG_PARITY_ERR_HOLD = 6;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_ERR_HOLD = 7;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_ERR_HOLD = 8;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_STATE_ERR_HOLD = 9;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_THRES_THERM_OVERFLOW_ERR_HOLD = 10;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_PARITY_ERR_HOLD = 11;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFTER_VALID_ERR_HOLD = 12;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_TIMEOUT_ERR_HOLD = 13;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_F_SKITTER_ERR_HOLD = 14;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_PCB_ERR_HOLD_OUT = 15;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_LT = 40;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_COUNT_STATE_LT_LEN = 4;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_LT = 44;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_RUN_STATE_LT_LEN = 3;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_DTS_LT = 47;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_SHIFT_VOLT_LT = 48;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_READ_STATE_LT = 49;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_READ_STATE_LT_LEN = 2;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_STATE_LT = 51;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_STATE_LT_LEN = 4;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_SAMPLE_DTS_LT = 55;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_MEASURE_VOLT_LT = 56;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_READ_CPM_LT = 57;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_WRITE_CPM_LT = 58;
static const uint32_t EPS_THERM_WSUB2_ERR_STATUS_REG_UNUSED = 59;
// perv/reg00002.H

static const uint64_t EPS_THERM_WSUB2_SKITTER_DATA1 = 0x0005003aull;
// perv/reg00002.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M1A_DATA_AREA_15_FSI = 0x0000284full;
static const uint32_t FSXCOMP_FSXLOG_M1A_DATA_AREA_15_FSI_BYTE = 0x0000293cull;
static const uint32_t FSXCOMP_FSXLOG_M1A_DATA_AREA_15_RW = 0x0005004full;

static const uint32_t FSXCOMP_FSXLOG_M1A_DATA_AREA_15_MDA_M1A_DATA_AREA_15 = 0;
static const uint32_t FSXCOMP_FSXLOG_M1A_DATA_AREA_15_MDA_M1A_DATA_AREA_15_LEN = 32;
// perv/reg00002.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI = 0x00002842ull;
static const uint32_t FSXCOMP_FSXLOG_M1A_DATA_AREA_2_FSI_BYTE = 0x00002908ull;
static const uint32_t FSXCOMP_FSXLOG_M1A_DATA_AREA_2_RW = 0x00050042ull;

static const uint32_t FSXCOMP_FSXLOG_M1A_DATA_AREA_2_MDA_M1A_DATA_AREA_2 = 0;
static const uint32_t FSXCOMP_FSXLOG_M1A_DATA_AREA_2_MDA_M1A_DATA_AREA_2_LEN = 32;
// perv/reg00002.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI = 0x00002888ull;
static const uint32_t FSXCOMP_FSXLOG_M1B_DATA_AREA_8_FSI_BYTE = 0x00002a20ull;
static const uint32_t FSXCOMP_FSXLOG_M1B_DATA_AREA_8_RO = 0x00050088ull;

static const uint32_t FSXCOMP_FSXLOG_M1B_DATA_AREA_8_MDA_M1B_DATA_AREA_8 = 0;
static const uint32_t FSXCOMP_FSXLOG_M1B_DATA_AREA_8_MDA_M1B_DATA_AREA_8_LEN = 32;
// perv/reg00002.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M2A_DATA_AREA_11_FSI = 0x000028cbull;
static const uint32_t FSXCOMP_FSXLOG_M2A_DATA_AREA_11_FSI_BYTE = 0x00002b2cull;
static const uint32_t FSXCOMP_FSXLOG_M2A_DATA_AREA_11_RW = 0x000500cbull;

static const uint32_t FSXCOMP_FSXLOG_M2A_DATA_AREA_11_MDA_M2A_DATA_AREA_11 = 0;
static const uint32_t FSXCOMP_FSXLOG_M2A_DATA_AREA_11_MDA_M2A_DATA_AREA_11_LEN = 32;
// perv/reg00002.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI = 0x00002904ull;
static const uint32_t FSXCOMP_FSXLOG_M2B_DATA_AREA_4_FSI_BYTE = 0x00002c10ull;
static const uint32_t FSXCOMP_FSXLOG_M2B_DATA_AREA_4_RO = 0x00050104ull;

static const uint32_t FSXCOMP_FSXLOG_M2B_DATA_AREA_4_MDA_M2B_DATA_AREA_4 = 0;
static const uint32_t FSXCOMP_FSXLOG_M2B_DATA_AREA_4_MDA_M2B_DATA_AREA_4_LEN = 32;
// perv/reg00002.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_FSI = 0x00002822ull;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_FSI_BYTE = 0x00002888ull;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_RW = 0x00050022ull;

static const uint32_t FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_M1HC1A_MAILBOX_1_HEADER_COMMAND_A = 0;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_1_HEADER_COMMAND_A_M1HC1A_MAILBOX_1_HEADER_COMMAND_A_LEN = 32;
// perv/reg00002.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_FSI = 0x0000282eull;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_FSI_BYTE = 0x000028b8ull;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_RO = 0x0005002eull;

static const uint32_t FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_M2HC1B_MAILBOX_2_HEADER_COMMAND_1_B = 0;
static const uint32_t FSXCOMP_FSXLOG_MAILBOX_2_HEADER_COMMAND_1_B_M2HC1B_MAILBOX_2_HEADER_COMMAND_1_B_LEN = 32;
// perv/reg00002.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_FSI = 0x00002817ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_FSI_BYTE = 0x0000285cull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_RW = 0x00050017ull;

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC = 0;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC = 1;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC = 3;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC = 4;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC = 5;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC = 6;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC = 7;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC = 8;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC = 9;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC = 10;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC = 11;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC = 12;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC = 13;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC = 14;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC = 15;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC = 16;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC = 17;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC = 18;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC = 19;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC = 20;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC = 21;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC = 22;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC = 23;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL = 24;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL = 25;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL = 26;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL = 27;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL = 28;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL = 29;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL = 30;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL = 31;
// perv/reg00002.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI = 0x0000283aull;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI_BYTE = 0x000028e8ull;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_RW = 0x0005003aull;

static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_SR_SCRATCH_REGISTER_3 = 0;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_SR_SCRATCH_REGISTER_3_LEN = 32;
// perv/reg00002.H

static const uint64_t HEARTBEAT_REG = 0x000f0018ull;

static const uint32_t HEARTBEAT_REG_HEARTBEAT_DEAD = 0;
// perv/reg00002.H

static const uint64_t L3TRA0_TR1_CONFIG_2 = 0x00018225ull;

static const uint32_t L3TRA0_TR1_CONFIG_2_A = 0;
static const uint32_t L3TRA0_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t L3TRA0_TR1_CONFIG_2_B = 24;
static const uint32_t L3TRA0_TR1_CONFIG_2_B_LEN = 24;
// perv/reg00002.H

static const uint64_t L3TRA1_TR0_CONFIG_4 = 0x00018247ull;

static const uint32_t L3TRA1_TR0_CONFIG_4_A = 0;
static const uint32_t L3TRA1_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t L3TRA1_TR0_CONFIG_4_B = 24;
static const uint32_t L3TRA1_TR0_CONFIG_4_B_LEN = 24;
// perv/reg00002.H

static const uint64_t L3TRA2_TR0_CONFIG_3 = 0x00018286ull;

static const uint32_t L3TRA2_TR0_CONFIG_3_C = 0;
static const uint32_t L3TRA2_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t L3TRA2_TR0_CONFIG_3_D = 24;
static const uint32_t L3TRA2_TR0_CONFIG_3_D_LEN = 24;
// perv/reg00002.H

static const uint64_t L3TRA3_TR1_CONFIG_5 = 0x000182e8ull;

static const uint32_t L3TRA3_TR1_CONFIG_5_C = 0;
static const uint32_t L3TRA3_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t L3TRA3_TR1_CONFIG_5_D = 24;
static const uint32_t L3TRA3_TR1_CONFIG_5_D_LEN = 24;
// perv/reg00002.H

static const uint64_t OPCG_CAPT3 = 0x00030012ull;

static const uint32_t OPCG_CAPT3_07EVEN = 4;
static const uint32_t OPCG_CAPT3_07EVEN_LEN = 5;
static const uint32_t OPCG_CAPT3_07ODD = 9;
static const uint32_t OPCG_CAPT3_07ODD_LEN = 5;
static const uint32_t OPCG_CAPT3_08EVEN = 14;
static const uint32_t OPCG_CAPT3_08EVEN_LEN = 5;
static const uint32_t OPCG_CAPT3_08ODD = 19;
static const uint32_t OPCG_CAPT3_08ODD_LEN = 5;
static const uint32_t OPCG_CAPT3_09EVEN = 24;
static const uint32_t OPCG_CAPT3_09EVEN_LEN = 5;
static const uint32_t OPCG_CAPT3_09ODD = 29;
static const uint32_t OPCG_CAPT3_09ODD_LEN = 5;
static const uint32_t OPCG_CAPT3_10EVEN = 34;
static const uint32_t OPCG_CAPT3_10EVEN_LEN = 5;
static const uint32_t OPCG_CAPT3_10ODD = 39;
static const uint32_t OPCG_CAPT3_10ODD_LEN = 5;
static const uint32_t OPCG_CAPT3_11EVEN = 44;
static const uint32_t OPCG_CAPT3_11EVEN_LEN = 5;
static const uint32_t OPCG_CAPT3_11ODD = 49;
static const uint32_t OPCG_CAPT3_11ODD_LEN = 5;
static const uint32_t OPCG_CAPT3_12EVEN = 54;
static const uint32_t OPCG_CAPT3_12EVEN_LEN = 5;
static const uint32_t OPCG_CAPT3_12ODD = 59;
static const uint32_t OPCG_CAPT3_12ODD_LEN = 5;
// perv/reg00002.H

static const uint64_t OTPC_M_MEASURE_REG2 = 0x00010012ull;

static const uint32_t OTPC_M_MEASURE_REG2_SEEPROM_MEASUREMENT2_DATA = 0;
static const uint32_t OTPC_M_MEASURE_REG2_SEEPROM_MEASUREMENT2_DATA_LEN = 64;
// perv/reg00002.H

static const uint64_t QMETRA0_TR0_CONFIG_2 = 0x00018405ull;

static const uint32_t QMETRA0_TR0_CONFIG_2_A = 0;
static const uint32_t QMETRA0_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t QMETRA0_TR0_CONFIG_2_B = 24;
static const uint32_t QMETRA0_TR0_CONFIG_2_B_LEN = 24;
// perv/reg00002.H

static const uint64_t RECOV_INTERRUPT_REG = 0x000f001bull;

static const uint32_t RECOV_INTERRUPT_REG_RECOV = 0;
// perv/reg00002.H

static const uint64_t REC_ERR_MST4_REG1 = 0x000f0051ull;

static const uint32_t REC_ERR_MST4_REG1_16_MST4_RESPONSE_BIT = 0;
static const uint32_t REC_ERR_MST4_REG1_16_MST4_ERROR_CODE = 1;
static const uint32_t REC_ERR_MST4_REG1_16_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG1_17_MST4_RESPONSE_BIT = 4;
static const uint32_t REC_ERR_MST4_REG1_17_MST4_ERROR_CODE = 5;
static const uint32_t REC_ERR_MST4_REG1_17_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG1_18_MST4_RESPONSE_BIT = 8;
static const uint32_t REC_ERR_MST4_REG1_18_MST4_ERROR_CODE = 9;
static const uint32_t REC_ERR_MST4_REG1_18_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG1_19_MST4_RESPONSE_BIT = 12;
static const uint32_t REC_ERR_MST4_REG1_19_MST4_ERROR_CODE = 13;
static const uint32_t REC_ERR_MST4_REG1_19_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG1_20_MST4_RESPONSE_BIT = 16;
static const uint32_t REC_ERR_MST4_REG1_20_MST4_ERROR_CODE = 17;
static const uint32_t REC_ERR_MST4_REG1_20_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG1_21_MST4_RESPONSE_BIT = 20;
static const uint32_t REC_ERR_MST4_REG1_21_MST4_ERROR_CODE = 21;
static const uint32_t REC_ERR_MST4_REG1_21_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG1_22_MST4_RESPONSE_BIT = 24;
static const uint32_t REC_ERR_MST4_REG1_22_MST4_ERROR_CODE = 25;
static const uint32_t REC_ERR_MST4_REG1_22_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG1_23_MST4_RESPONSE_BIT = 28;
static const uint32_t REC_ERR_MST4_REG1_23_MST4_ERROR_CODE = 29;
static const uint32_t REC_ERR_MST4_REG1_23_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG1_24_MST4_RESPONSE_BIT = 32;
static const uint32_t REC_ERR_MST4_REG1_24_MST4_ERROR_CODE = 33;
static const uint32_t REC_ERR_MST4_REG1_24_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG1_25_MST4_RESPONSE_BIT = 36;
static const uint32_t REC_ERR_MST4_REG1_25_MST4_ERROR_CODE = 37;
static const uint32_t REC_ERR_MST4_REG1_25_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG1_26_MST4_RESPONSE_BIT = 40;
static const uint32_t REC_ERR_MST4_REG1_26_MST4_ERROR_CODE = 41;
static const uint32_t REC_ERR_MST4_REG1_26_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG1_27_MST4_RESPONSE_BIT = 44;
static const uint32_t REC_ERR_MST4_REG1_27_MST4_ERROR_CODE = 45;
static const uint32_t REC_ERR_MST4_REG1_27_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG1_28_MST4_RESPONSE_BIT = 48;
static const uint32_t REC_ERR_MST4_REG1_28_MST4_ERROR_CODE = 49;
static const uint32_t REC_ERR_MST4_REG1_28_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG1_29_MST4_RESPONSE_BIT = 52;
static const uint32_t REC_ERR_MST4_REG1_29_MST4_ERROR_CODE = 53;
static const uint32_t REC_ERR_MST4_REG1_29_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG1_30_MST4_RESPONSE_BIT = 56;
static const uint32_t REC_ERR_MST4_REG1_30_MST4_ERROR_CODE = 57;
static const uint32_t REC_ERR_MST4_REG1_30_MST4_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST4_REG1_31_MST4_RESPONSE_BIT = 60;
static const uint32_t REC_ERR_MST4_REG1_31_MST4_ERROR_CODE = 61;
static const uint32_t REC_ERR_MST4_REG1_31_MST4_ERROR_CODE_LEN = 3;
// perv/reg00002.H

static const uint64_t SCAN32 = 0x00038000ull;

static const uint32_t SCAN32_SCAN32_REG = 0;
static const uint32_t SCAN32_SCAN32_REG_LEN = 32;
// perv/reg00002.H

static const uint64_t SCAN64 = 0x0003e000ull;

static const uint32_t SCAN64_SCAN64_REG = 0;
static const uint32_t SCAN64_SCAN64_REG_LEN = 64;
// perv/reg00002.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG1 = 0x00018001ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG1_REGISTER1 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG1_REGISTER1_LEN = 64;
// perv/reg00002.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG100 = 0x00018064ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG100_REGISTER100 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG100_REGISTER100_LEN = 64;
// perv/reg00002.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG11 = 0x0001800bull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG11_REGISTER11 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG11_REGISTER11_LEN = 64;
// perv/reg00002.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG26 = 0x0001801aull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG26_REGISTER26 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG26_REGISTER26_LEN = 64;
// perv/reg00002.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG39 = 0x00018027ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG39_REGISTER39 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG39_REGISTER39_LEN = 64;
// perv/reg00002.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG47 = 0x0001802full;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG47_REGISTER47 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG47_REGISTER47_LEN = 64;
// perv/reg00002.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG58 = 0x0001803aull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG58_REGISTER58 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG58_REGISTER58_LEN = 64;
// perv/reg00002.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG70 = 0x00018046ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG70_REGISTER70 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG70_REGISTER70_LEN = 64;
// perv/reg00002.H

static const uint64_t SINGLE_OTP_ROM_OTPROM_REG85 = 0x00018055ull;

static const uint32_t SINGLE_OTP_ROM_OTPROM_REG85_REGISTER85 = 0;
static const uint32_t SINGLE_OTP_ROM_OTPROM_REG85_REGISTER85_LEN = 64;
// perv/reg00002.H

static const uint64_t TRA0_TR0_TRACE_HI_DATA_REG = 0x00010400ull;

static const uint32_t TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TRA0_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// perv/reg00002.H

static const uint64_t TRA0_TR1_CONFIG_2 = 0x00010445ull;

static const uint32_t TRA0_TR1_CONFIG_2_A = 0;
static const uint32_t TRA0_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TRA0_TR1_CONFIG_2_B = 24;
static const uint32_t TRA0_TR1_CONFIG_2_B_LEN = 24;
// perv/reg00002.H

static const uint64_t TRA1_TR0_CONFIG_4 = 0x00010487ull;

static const uint32_t TRA1_TR0_CONFIG_4_A = 0;
static const uint32_t TRA1_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TRA1_TR0_CONFIG_4_B = 24;
static const uint32_t TRA1_TR0_CONFIG_4_B_LEN = 24;
// perv/reg00003.H

static const uint64_t TRA2_TR0_CONFIG_3 = 0x00010506ull;

static const uint32_t TRA2_TR0_CONFIG_3_C = 0;
static const uint32_t TRA2_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TRA2_TR0_CONFIG_3_D = 24;
static const uint32_t TRA2_TR0_CONFIG_3_D_LEN = 24;
// perv/reg00003.H

static const uint64_t TRA3_TR1_TRACE_LO_DATA_REG = 0x000105c1ull;

static const uint32_t TRA3_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TRA3_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TRA3_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TRA3_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TRA3_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TRA3_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TRA3_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TRA3_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TRA3_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TRA3_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TRA3_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// perv/reg00003.H

static const uint64_t TRA3_TR1_CONFIG_5 = 0x000105c8ull;

static const uint32_t TRA3_TR1_CONFIG_5_C = 0;
static const uint32_t TRA3_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TRA3_TR1_CONFIG_5_D = 24;
static const uint32_t TRA3_TR1_CONFIG_5_D_LEN = 24;
// perv/reg00003.H

static const uint64_t TRA4_TR1_CONFIG_4 = 0x00010647ull;

static const uint32_t TRA4_TR1_CONFIG_4_A = 0;
static const uint32_t TRA4_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t TRA4_TR1_CONFIG_4_B = 24;
static const uint32_t TRA4_TR1_CONFIG_4_B_LEN = 24;
// perv/reg00003.H

static const uint64_t TRA5_TR0_CONFIG_2 = 0x00010685ull;

static const uint32_t TRA5_TR0_CONFIG_2_A = 0;
static const uint32_t TRA5_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TRA5_TR0_CONFIG_2_B = 24;
static const uint32_t TRA5_TR0_CONFIG_2_B_LEN = 24;
// perv/reg00003.H

static const uint64_t TRA6_TR0_CONFIG_5 = 0x00010708ull;

static const uint32_t TRA6_TR0_CONFIG_5_C = 0;
static const uint32_t TRA6_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TRA6_TR0_CONFIG_5_D = 24;
static const uint32_t TRA6_TR0_CONFIG_5_D_LEN = 24;
// perv/reg00003.H

#ifndef __PPE_HCODE__
}
}
#include "perv/reg00002.H"
#include "perv/reg00003.H"
#endif
#endif
