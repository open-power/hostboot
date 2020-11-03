/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_perv_a.H $       */
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

#ifndef __p10_scom_perv_a_H_
#define __p10_scom_perv_a_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif


//>> [CLOCK_STAT_SL]
static const uint64_t CLOCK_STAT_SL = 0x00030008ull;

static const uint32_t CLOCK_STAT_SL_PERV_SL = 4;
static const uint32_t CLOCK_STAT_SL_UNIT1_SL = 5;
static const uint32_t CLOCK_STAT_SL_UNIT2_SL = 6;
static const uint32_t CLOCK_STAT_SL_UNIT3_SL = 7;
static const uint32_t CLOCK_STAT_SL_UNIT4_SL = 8;
static const uint32_t CLOCK_STAT_SL_UNIT5_SL = 9;
static const uint32_t CLOCK_STAT_SL_UNIT6_SL = 10;
static const uint32_t CLOCK_STAT_SL_UNIT7_SL = 11;
static const uint32_t CLOCK_STAT_SL_UNIT8_SL = 12;
static const uint32_t CLOCK_STAT_SL_UNIT9_SL = 13;
static const uint32_t CLOCK_STAT_SL_UNIT10_SL = 14;
static const uint32_t CLOCK_STAT_SL_UNIT11_SL = 15;
static const uint32_t CLOCK_STAT_SL_UNIT12_SL = 16;
static const uint32_t CLOCK_STAT_SL_UNIT13_SL = 17;
static const uint32_t CLOCK_STAT_SL_UNIT14_SL = 18;
//<< [CLOCK_STAT_SL]
// perv/reg00020.H

//>> [CPLT_CTRL3]
static const uint64_t CPLT_CTRL3_RW = 0x00000003ull;
static const uint64_t CPLT_CTRL3_WO_CLEAR = 0x00000023ull;
static const uint64_t CPLT_CTRL3_WO_OR = 0x00000013ull;

static const uint32_t CPLT_CTRL3_0_PSCOM_EN = 4;
static const uint32_t CPLT_CTRL3_1_PSCOM_EN = 5;
static const uint32_t CPLT_CTRL3_2_PSCOM_EN = 6;
static const uint32_t CPLT_CTRL3_3_PSCOM_EN = 7;
static const uint32_t CPLT_CTRL3_4_PSCOM_EN = 8;
static const uint32_t CPLT_CTRL3_5_PSCOM_EN = 9;
static const uint32_t CPLT_CTRL3_6_PSCOM_EN = 10;
static const uint32_t CPLT_CTRL3_7_PSCOM_EN = 11;
static const uint32_t CPLT_CTRL3_8_PSCOM_EN = 12;
static const uint32_t CPLT_CTRL3_9_PSCOM_EN = 13;
static const uint32_t CPLT_CTRL3_10_PSCOM_EN = 14;
static const uint32_t CPLT_CTRL3_11_PSCOM_EN = 15;
static const uint32_t CPLT_CTRL3_12_PSCOM_EN = 16;
static const uint32_t CPLT_CTRL3_13_PSCOM_EN = 17;
static const uint32_t CPLT_CTRL3_14_PSCOM_EN = 18;
//<< [CPLT_CTRL3]
// perv/reg00020.H

//>> [FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI = 0x0000293bull;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_FSI_BYTE = 0x00002cecull;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_WO_CLEAR = 0x0005013bull;

static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_0_RESERVED = 0;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_DCC_BYPASS_EN_DC = 1;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_CHIPLET_CLK_PDLY_BYPASS_EN_DC = 2;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_3_15_RESERVED = 3;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_3_15_RESERVED_LEN = 13;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_SEC_BUF_DRV_STRENGTH_DC = 16;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_TP_SEC_BUF_DRV_STRENGTH_DC_LEN = 4;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_20_31_RESERVED = 20;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR_PERV_CTRL1_20_31_RESERVED_LEN = 12;
//<< [FSXCOMP_FSXLOG_PERV_CTRL1_CLEAR]
// perv/reg00020.H

//>> [FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI = 0x00002933ull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_FSI_BYTE = 0x00002cccull;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_WO_CLEAR = 0x00050133ull;

static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_RESET_DC = 0;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_BYPASS_EN_DC = 1;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_TEST_EN_DC = 2;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW1_ALTREFCLK_SEL_DC = 3;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_RESET_DC = 4;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_BYPASS_EN_DC = 5;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_TEST_EN_DC = 6;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLCLKSW2_ALTREFCLK_SEL_DC = 7;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_RESET_DC = 8;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_BYPASS_EN_DC = 9;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLTODFLT_TEST_EN_DC = 10;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLTODFLT = 11;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_RESET_DC = 12;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_BYPASS_EN_DC = 13;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLNESTFLT_TEST_EN_DC = 14;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLNESTFLT = 15;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_RESET_DC = 16;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_BYPASS_EN_DC = 17;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOFLT_TEST_EN_DC = 18;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOFLT = 19;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_RESET_DC = 20;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_BYPASS_EN_DC = 21;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PLLIOSSFLT_TEST_EN_DC = 22;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_SPARE_PLLIOSSFLT = 23;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_RESET_DC = 24;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_BYPASS_EN_DC = 25;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_TEST_EN_DC = 26;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_PAU_DPLL_FUNC_CLKSEL_DC = 27;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_RESET_DC = 28;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_BYPASS_EN_DC = 29;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_TEST_EN_DC = 30;
static const uint32_t FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR_TP_NEST_DPLL_FUNC_CLKSEL_DC = 31;
//<< [FSXCOMP_FSXLOG_ROOT_CTRL3_CLEAR]
// perv/reg00020.H

//>> [FSXCOMP_FSXLOG_SB_CS]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_SB_CS = 0x00050008ull;
static const uint32_t FSXCOMP_FSXLOG_SB_CS_FSI = 0x00002808ull;
static const uint32_t FSXCOMP_FSXLOG_SB_CS_FSI_BYTE = 0x00002820ull;

static const uint32_t FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE = 0;
static const uint32_t FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0 = 12;
static const uint32_t FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1 = 13;
static const uint32_t FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0 = 14;
static const uint32_t FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1 = 15;
static const uint32_t FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM = 16;
static const uint32_t FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM = 17;
static const uint32_t FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_MEAS_SEEPROM = 18;
//<< [FSXCOMP_FSXLOG_SB_CS]
// perv/reg00020.H

//>> [FSXCOMP_FSXLOG_SCRATCH_REGISTER_10]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI = 0x00002981ull;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI_BYTE = 0x00002e04ull;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_RW = 0x00050181ull;

static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_SR_SCRATCH_REGISTER_10 = 0;
static const uint32_t FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_SR_SCRATCH_REGISTER_10_LEN = 32;
//<< [FSXCOMP_FSXLOG_SCRATCH_REGISTER_10]
// perv/reg00020.H

//>> [REC_ERR_MST14_REG0]
static const uint64_t REC_ERR_MST14_REG0 = 0x000f0078ull;

static const uint32_t REC_ERR_MST14_REG0_MASTER_MST14_RESPONSE_BIT = 0;
static const uint32_t REC_ERR_MST14_REG0_MASTER_MST14_ERROR_CODE = 1;
static const uint32_t REC_ERR_MST14_REG0_MASTER_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG0_SLAVE1_MST14_RESPONSE_BIT = 4;
static const uint32_t REC_ERR_MST14_REG0_SLAVE1_MST14_ERROR_CODE = 5;
static const uint32_t REC_ERR_MST14_REG0_SLAVE1_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG0_SLAVE2_MST14_RESPONSE_BIT = 8;
static const uint32_t REC_ERR_MST14_REG0_SLAVE2_MST14_ERROR_CODE = 9;
static const uint32_t REC_ERR_MST14_REG0_SLAVE2_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG0_SLAVE3_MST14_RESPONSE_BIT = 12;
static const uint32_t REC_ERR_MST14_REG0_SLAVE3_MST14_ERROR_CODE = 13;
static const uint32_t REC_ERR_MST14_REG0_SLAVE3_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG0_SLAVE4_MST14_RESPONSE_BIT = 16;
static const uint32_t REC_ERR_MST14_REG0_SLAVE4_MST14_ERROR_CODE = 17;
static const uint32_t REC_ERR_MST14_REG0_SLAVE4_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG0_SLAVE5_MST14_RESPONSE_BIT = 20;
static const uint32_t REC_ERR_MST14_REG0_SLAVE5_MST14_ERROR_CODE = 21;
static const uint32_t REC_ERR_MST14_REG0_SLAVE5_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG0_SLAVE6_MST14_RESPONSE_BIT = 24;
static const uint32_t REC_ERR_MST14_REG0_SLAVE6_MST14_ERROR_CODE = 25;
static const uint32_t REC_ERR_MST14_REG0_SLAVE6_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG0_SLAVE7_MST14_RESPONSE_BIT = 28;
static const uint32_t REC_ERR_MST14_REG0_SLAVE7_MST14_ERROR_CODE = 29;
static const uint32_t REC_ERR_MST14_REG0_SLAVE7_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG0_SLAVE8_MST14_RESPONSE_BIT = 32;
static const uint32_t REC_ERR_MST14_REG0_SLAVE8_MST14_ERROR_CODE = 33;
static const uint32_t REC_ERR_MST14_REG0_SLAVE8_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG0_SLAVE9_MST14_RESPONSE_BIT = 36;
static const uint32_t REC_ERR_MST14_REG0_SLAVE9_MST14_ERROR_CODE = 37;
static const uint32_t REC_ERR_MST14_REG0_SLAVE9_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG0_SLAVE10_MST14_RESPONSE_BIT = 40;
static const uint32_t REC_ERR_MST14_REG0_SLAVE10_MST14_ERROR_CODE = 41;
static const uint32_t REC_ERR_MST14_REG0_SLAVE10_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG0_SLAVE11_MST14_RESPONSE_BIT = 44;
static const uint32_t REC_ERR_MST14_REG0_SLAVE11_MST14_ERROR_CODE = 45;
static const uint32_t REC_ERR_MST14_REG0_SLAVE11_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG0_SLAVE12_MST14_RESPONSE_BIT = 48;
static const uint32_t REC_ERR_MST14_REG0_SLAVE12_MST14_ERROR_CODE = 49;
static const uint32_t REC_ERR_MST14_REG0_SLAVE12_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG0_SLAVE13_MST14_RESPONSE_BIT = 52;
static const uint32_t REC_ERR_MST14_REG0_SLAVE13_MST14_ERROR_CODE = 53;
static const uint32_t REC_ERR_MST14_REG0_SLAVE13_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG0_SLAVE14_MST14_RESPONSE_BIT = 56;
static const uint32_t REC_ERR_MST14_REG0_SLAVE14_MST14_ERROR_CODE = 57;
static const uint32_t REC_ERR_MST14_REG0_SLAVE14_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG0_SLAVE15_MST14_RESPONSE_BIT = 60;
static const uint32_t REC_ERR_MST14_REG0_SLAVE15_MST14_ERROR_CODE = 61;
static const uint32_t REC_ERR_MST14_REG0_SLAVE15_MST14_ERROR_CODE_LEN = 3;
//<< [REC_ERR_MST14_REG0]
// perv/reg00020.H

//>> [TOD_ERROR_REG]
static const uint64_t TOD_ERROR_REG = 0x00040030ull;

static const uint32_t TOD_ERROR_REG_REG_0X00_DATA_PARITY_ERROR = 0;
static const uint32_t TOD_ERROR_REG_M_PATH_0_PARITY_ERROR = 1;
static const uint32_t TOD_ERROR_REG_M_PATH_1_PARITY_ERROR = 2;
static const uint32_t TOD_ERROR_REG_REG_0X01_DATA_PARITY_ERROR = 3;
static const uint32_t TOD_ERROR_REG_REG_0X02_DATA_PARITY_ERROR = 4;
static const uint32_t TOD_ERROR_REG_REG_0X03_DATA_PARITY_ERROR = 5;
static const uint32_t TOD_ERROR_REG_REG_0X04_DATA_PARITY_ERROR = 6;
static const uint32_t TOD_ERROR_REG_REG_0X05_DATA_PARITY_ERROR = 7;
static const uint32_t TOD_ERROR_REG_REG_0X06_DATA_PARITY_ERROR = 8;
static const uint32_t TOD_ERROR_REG_REG_0X07_DATA_PARITY_ERROR = 9;
static const uint32_t TOD_ERROR_REG_S_PATH_0_PARITY_ERROR = 10;
static const uint32_t TOD_ERROR_REG_REG_0X08_DATA_PARITY_ERROR = 11;
static const uint32_t TOD_ERROR_REG_REG_0X09_DATA_PARITY_ERROR = 12;
static const uint32_t TOD_ERROR_REG_REG_0X0A_DATA_PARITY_ERROR = 13;
static const uint32_t TOD_ERROR_REG_M_PATH_0_STEP_CHECK_ERROR = 14;
static const uint32_t TOD_ERROR_REG_M_PATH_1_STEP_CHECK_ERROR = 15;
static const uint32_t TOD_ERROR_REG_S_PATH_0_STEP_CHECK_ERROR = 16;
static const uint32_t TOD_ERROR_REG_I_PATH_STEP_CHECK_ERROR = 17;
static const uint32_t TOD_ERROR_REG_PSS_HAM = 18;
static const uint32_t TOD_ERROR_REG_REG_0X0B_DATA_PARITY_ERROR = 19;
static const uint32_t TOD_ERROR_REG_S_PATH_1_PARITY_ERROR = 20;
static const uint32_t TOD_ERROR_REG_S_PATH_1_STEP_CHECK_ERROR = 21;
static const uint32_t TOD_ERROR_REG_I_PATH_DELAY_STEP_CHECK_PARITY_ERROR = 22;
static const uint32_t TOD_ERROR_REG_REG_0X0C_DATA_PARITY_ERROR = 23;
static const uint32_t TOD_ERROR_REG_REG_0X11_0X12_0X13_0X14_0X15_0X16_DATA_PARITY_ERROR = 24;
static const uint32_t TOD_ERROR_REG_REG_0X17_0X18_0X21_0X22_DATA_PARITY_ERROR = 25;
static const uint32_t TOD_ERROR_REG_REG_0X1D_0X1E_0X1F_DATA_PARITY_ERROR = 26;
static const uint32_t TOD_ERROR_REG_REG_0X20_DATA_PARITY_ERROR = 27;
static const uint32_t TOD_ERROR_REG_REG_0X23_DATA_PARITY_ERROR = 28;
static const uint32_t TOD_ERROR_REG_REG_0X24_DATA_PARITY_ERROR = 29;
static const uint32_t TOD_ERROR_REG_REG_0X29_DATA_PARITY_ERROR = 30;
static const uint32_t TOD_ERROR_REG_REG_0X30_0X31_0X32_0X33_DATA_PARITY_ERROR = 31;
static const uint32_t TOD_ERROR_REG_REG_0X10_DATA_PARITY_ERROR = 32;
static const uint32_t TOD_ERROR_REG_I_PATH_SYNC_CHECK_ERROR = 33;
static const uint32_t TOD_ERROR_REG_I_PATH_FSM_STATE_PARITY_ERROR = 34;
static const uint32_t TOD_ERROR_REG_I_PATH_TIME_REG_PARITY_ERROR = 35;
static const uint32_t TOD_ERROR_REG_I_PATH_TIME_REG_OVERFLOW = 36;
static const uint32_t TOD_ERROR_REG_WOF_LOW_ORDER_STEP_COUNTER_PARITY_ERROR = 37;
static const uint32_t TOD_ERROR_REG_RX_TTYPE_0 = 38;
static const uint32_t TOD_ERROR_REG_RX_TTYPE_1 = 39;
static const uint32_t TOD_ERROR_REG_RX_TTYPE_2 = 40;
static const uint32_t TOD_ERROR_REG_RX_TTYPE_3 = 41;
static const uint32_t TOD_ERROR_REG_RX_TTYPE_4 = 42;
static const uint32_t TOD_ERROR_REG_RX_TTYPE_5 = 43;
static const uint32_t TOD_ERROR_REG_PIB_SLAVE_ADDR_INVALID_ERROR = 44;
static const uint32_t TOD_ERROR_REG_PIB_SLAVE_WRITE_INVALID_ERROR = 45;
static const uint32_t TOD_ERROR_REG_PIB_SLAVE_READ_INVALID_ERROR = 46;
static const uint32_t TOD_ERROR_REG_PIB_SLAVE_ADDR_PARITY_ERROR = 47;
static const uint32_t TOD_ERROR_REG_PIB_SLAVE_DATA_PARITY_ERROR = 48;
static const uint32_t TOD_ERROR_REG_REG_0X27_DATA_PARITY_ERROR = 49;
static const uint32_t TOD_ERROR_REG_PIB_MASTER_RSP_INFO_ERROR = 50;
static const uint32_t TOD_ERROR_REG_PIB_MASTER_RSP_INFO_ERROR_LEN = 3;
static const uint32_t TOD_ERROR_REG_RX_TTYPE_INVALID_ERROR = 53;
static const uint32_t TOD_ERROR_REG_RX_TTYPE_4_DATA_PARITY_ERROR = 54;
static const uint32_t TOD_ERROR_REG_PIB_MASTER_REQUEST_ERROR = 55;
static const uint32_t TOD_ERROR_REG_PIB_RESET_DURING_ACCESS_ERROR = 56;
static const uint32_t TOD_ERROR_REG_EXTERNAL_XSTOP_ERROR = 57;
static const uint32_t TOD_ERROR_REG_SPARE_ERROR_58 = 58;
static const uint32_t TOD_ERROR_REG_SPARE_ERROR_59 = 59;
static const uint32_t TOD_ERROR_REG_SPARE_ERROR_60 = 60;
static const uint32_t TOD_ERROR_REG_SPARE_ERROR_61 = 61;
static const uint32_t TOD_ERROR_REG_OSCSWITCH_INTERRUPT = 62;
static const uint32_t TOD_ERROR_REG_SPARE_ERROR_63 = 63;
//<< [TOD_ERROR_REG]
// perv/reg00020.H

//>> [TOD_VALUE_REG]
static const uint64_t TOD_VALUE_REG = 0x00040020ull;

static const uint32_t TOD_VALUE_REG_TOD_VALUE = 0;
static const uint32_t TOD_VALUE_REG_TOD_VALUE_LEN = 60;
static const uint32_t TOD_VALUE_REG_WOF_COUNTER_VALUE = 60;
static const uint32_t TOD_VALUE_REG_WOF_COUNTER_VALUE_LEN = 4;
//<< [TOD_VALUE_REG]
// perv/reg00021.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "perv/reg00020.H"
#include "perv/reg00021.H"
#endif
#endif
