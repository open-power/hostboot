/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_perv_c.H $       */
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

#ifndef __p10_scom_perv_c_H_
#define __p10_scom_perv_c_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace perv
{
#endif


//>> [CPLT_CTRL2]
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
//<< [CPLT_CTRL2]
// perv/reg00024.H

//>> [CPLT_MASK0]
static const uint64_t CPLT_MASK0 = 0x00000101ull;

static const uint32_t CPLT_MASK0_ITR_MASK = 0;
static const uint32_t CPLT_MASK0_ITR_MASK_LEN = 32;
//<< [CPLT_MASK0]
// perv/reg00024.H

//>> [P10_20_EPS_DBG_MODE_REG]
static const uint64_t EPS_DBG_MODE_REG = 0x000107c0ull; // p10:20,

static const uint32_t P10_20_EPS_DBG_MODE_REG_GLB_BRCST_MODE = 0;
static const uint32_t P10_20_EPS_DBG_MODE_REG_GLB_BRCST_MODE_LEN = 3;
static const uint32_t P10_20_EPS_DBG_MODE_REG_TRACE_SEL_MODE = 3;
static const uint32_t P10_20_EPS_DBG_MODE_REG_TRACE_SEL_MODE_LEN = 3;
static const uint32_t P10_20_EPS_DBG_MODE_REG_TRIG_SEL_MODE = 6;
static const uint32_t P10_20_EPS_DBG_MODE_REG_TRIG_SEL_MODE_LEN = 2;
static const uint32_t P10_20_EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION = 8;
static const uint32_t P10_20_EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION = 9;
static const uint32_t P10_20_EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION = 10;
static const uint32_t P10_20_EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION = 11;
static const uint32_t P10_20_EPS_DBG_MODE_REG_FREEZE_SEL_MODE = 12;
static const uint32_t P10_20_EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE = 13;
static const uint32_t P10_20_EPS_DBG_MODE_REG_TRACE_RUN_ON = 16;
static const uint32_t P10_20_EPS_DBG_MODE_REG_TRACE_RUN_STATUS = 17;
static const uint32_t P10_20_EPS_DBG_MODE_REG_TRACE_RUN_STATUS_LEN = 2;
static const uint32_t P10_20_EPS_DBG_MODE_REG_IS_FROZEN_STATUS = 19;
static const uint32_t P10_20_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS = 20;
static const uint32_t P10_20_EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS_LEN = 3;
static const uint32_t P10_20_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS = 23;
static const uint32_t P10_20_EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS_LEN = 3;
static const uint32_t P10_20_EPS_DBG_MODE_REG_UNUSED = 26;
static const uint32_t P10_20_EPS_DBG_MODE_REG_UNUSED_LEN = 6;
//<< [P10_20_EPS_DBG_MODE_REG]
// perv/reg00024.H

//>> [FSXCOMP_FSXLOG_CBS_CS]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_CBS_CS = 0x00050001ull;
static const uint32_t FSXCOMP_FSXLOG_CBS_CS_FSI = 0x00002801ull;
static const uint32_t FSXCOMP_FSXLOG_CBS_CS_FSI_BYTE = 0x00002804ull;

static const uint32_t FSXCOMP_FSXLOG_CBS_CS_START_BOOT_SEQUENCER = 0;
static const uint32_t FSXCOMP_FSXLOG_CBS_CS_OPTION_SKIP_SCAN0_CLOCKSTART = 2;
static const uint32_t FSXCOMP_FSXLOG_CBS_CS_OPTION_PREVENT_SBE_START = 3;
static const uint32_t FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT = 4;
static const uint32_t FSXCOMP_FSXLOG_CBS_CS_SAMPLED_SMD_PIN = 5;
static const uint32_t FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY = 6;
static const uint32_t FSXCOMP_FSXLOG_CBS_CS_STATE_MACHINE_TRANSITION_DELAY_LEN = 10;
static const uint32_t FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR = 16;
static const uint32_t FSXCOMP_FSXLOG_CBS_CS_INTERNAL_STATE_VECTOR_LEN = 16;
//<< [FSXCOMP_FSXLOG_CBS_CS]
// perv/reg00024.H

//>> [FSXCOMP_FSXLOG_CBS_STAT]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_FSI = 0x0000280bull;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_FSI_BYTE = 0x0000282cull;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_RO = 0x0005000bull;

static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_RESET_EP = 0;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_OPCG_IP = 1;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_VITL_CLKOFF = 2;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_TEST_ENABLE = 3;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_CBS_REQ = 4;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD = 5;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_CBS_CMD_LEN = 3;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE = 8;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_CBS_STATE_LEN = 5;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_SECURITY_DEBUG_MODE = 13;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_PROTOCOL_ERROR = 14;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_PCB_IDLE = 15;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE = 16;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_CURRENT_OPCG_MODE_LEN = 4;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE = 20;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_LAST_OPCG_MODE_LEN = 4;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_PCB_ERROR = 24;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_PARITY_ERROR = 25;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_CC_ERROR = 26;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_CHIPLET_IS_ALIGNED = 27;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_PCB_REQUEST_SINCE_RESET = 28;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_TEST_ENABLE_CHANGE = 29;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_PARANOIA_VITL_CLKOFF_CHANGE = 30;
static const uint32_t FSXCOMP_FSXLOG_CBS_STAT_TP_TPFSI_CBS_ACK = 31;
//<< [FSXCOMP_FSXLOG_CBS_STAT]
// perv/reg00024.H

//>> [FSXCOMP_FSXLOG_PERV_CTRL0_COPY]
//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI = 0x0000291aull;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI_BYTE = 0x00002c68ull;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_COPY_RW = 0x0005011aull;

static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_COPY_PERV_CTRL0_COPY_REG = 0;
static const uint32_t FSXCOMP_FSXLOG_PERV_CTRL0_COPY_PERV_CTRL0_COPY_REG_LEN = 32;
//<< [FSXCOMP_FSXLOG_PERV_CTRL0_COPY]
// perv/reg00024.H

//>> [PCB_OPCG_STOP]
static const uint64_t PCB_OPCG_STOP = 0x00030030ull;

static const uint32_t PCB_OPCG_STOP_PCB_OPCGSTOP = 0;
//<< [PCB_OPCG_STOP]
// perv/reg00024.H

//>> [REC_ERR_MST14_REG1]
static const uint64_t REC_ERR_MST14_REG1 = 0x000f0079ull;

static const uint32_t REC_ERR_MST14_REG1_16_MST14_RESPONSE_BIT = 0;
static const uint32_t REC_ERR_MST14_REG1_16_MST14_ERROR_CODE = 1;
static const uint32_t REC_ERR_MST14_REG1_16_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG1_17_MST14_RESPONSE_BIT = 4;
static const uint32_t REC_ERR_MST14_REG1_17_MST14_ERROR_CODE = 5;
static const uint32_t REC_ERR_MST14_REG1_17_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG1_18_MST14_RESPONSE_BIT = 8;
static const uint32_t REC_ERR_MST14_REG1_18_MST14_ERROR_CODE = 9;
static const uint32_t REC_ERR_MST14_REG1_18_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG1_19_MST14_RESPONSE_BIT = 12;
static const uint32_t REC_ERR_MST14_REG1_19_MST14_ERROR_CODE = 13;
static const uint32_t REC_ERR_MST14_REG1_19_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG1_20_MST14_RESPONSE_BIT = 16;
static const uint32_t REC_ERR_MST14_REG1_20_MST14_ERROR_CODE = 17;
static const uint32_t REC_ERR_MST14_REG1_20_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG1_21_MST14_RESPONSE_BIT = 20;
static const uint32_t REC_ERR_MST14_REG1_21_MST14_ERROR_CODE = 21;
static const uint32_t REC_ERR_MST14_REG1_21_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG1_22_MST14_RESPONSE_BIT = 24;
static const uint32_t REC_ERR_MST14_REG1_22_MST14_ERROR_CODE = 25;
static const uint32_t REC_ERR_MST14_REG1_22_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG1_23_MST14_RESPONSE_BIT = 28;
static const uint32_t REC_ERR_MST14_REG1_23_MST14_ERROR_CODE = 29;
static const uint32_t REC_ERR_MST14_REG1_23_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG1_24_MST14_RESPONSE_BIT = 32;
static const uint32_t REC_ERR_MST14_REG1_24_MST14_ERROR_CODE = 33;
static const uint32_t REC_ERR_MST14_REG1_24_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG1_25_MST14_RESPONSE_BIT = 36;
static const uint32_t REC_ERR_MST14_REG1_25_MST14_ERROR_CODE = 37;
static const uint32_t REC_ERR_MST14_REG1_25_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG1_26_MST14_RESPONSE_BIT = 40;
static const uint32_t REC_ERR_MST14_REG1_26_MST14_ERROR_CODE = 41;
static const uint32_t REC_ERR_MST14_REG1_26_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG1_27_MST14_RESPONSE_BIT = 44;
static const uint32_t REC_ERR_MST14_REG1_27_MST14_ERROR_CODE = 45;
static const uint32_t REC_ERR_MST14_REG1_27_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG1_28_MST14_RESPONSE_BIT = 48;
static const uint32_t REC_ERR_MST14_REG1_28_MST14_ERROR_CODE = 49;
static const uint32_t REC_ERR_MST14_REG1_28_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG1_29_MST14_RESPONSE_BIT = 52;
static const uint32_t REC_ERR_MST14_REG1_29_MST14_ERROR_CODE = 53;
static const uint32_t REC_ERR_MST14_REG1_29_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG1_30_MST14_RESPONSE_BIT = 56;
static const uint32_t REC_ERR_MST14_REG1_30_MST14_ERROR_CODE = 57;
static const uint32_t REC_ERR_MST14_REG1_30_MST14_ERROR_CODE_LEN = 3;
static const uint32_t REC_ERR_MST14_REG1_31_MST14_RESPONSE_BIT = 60;
static const uint32_t REC_ERR_MST14_REG1_31_MST14_ERROR_CODE = 61;
static const uint32_t REC_ERR_MST14_REG1_31_MST14_ERROR_CODE_LEN = 3;
//<< [REC_ERR_MST14_REG1]
// perv/reg00024.H

//>> [SCAN64CONTSCAN]
static const uint64_t SCAN64CONTSCAN = 0x0003f000ull;

static const uint32_t SCAN64CONTSCAN_SCAN64CONTSCAN_REG = 0;
static const uint32_t SCAN64CONTSCAN_SCAN64CONTSCAN_REG_LEN = 64;
//<< [SCAN64CONTSCAN]
// perv/reg00024.H

//>> [TOD_PRI_PORT_0_CTRL_REG]
static const uint64_t TOD_PRI_PORT_0_CTRL_REG = 0x00040001ull;

static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_PORT_0_RX_SELECT = 0;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_PORT_0_RX_SELECT_LEN = 3;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_03 = 3;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_SELECT = 4;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_SELECT_LEN = 2;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_SELECT = 6;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_SELECT_LEN = 2;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_SELECT = 8;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_SELECT_LEN = 2;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_SELECT = 10;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_SELECT_LEN = 2;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_SELECT = 12;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_SELECT_LEN = 2;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_SELECT = 14;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_SELECT_LEN = 2;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_SELECT = 16;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_SELECT_LEN = 2;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_SELECT = 18;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_SELECT_LEN = 2;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X0_PORT_0_TX_ENABLE = 20;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X1_PORT_0_TX_ENABLE = 21;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X2_PORT_0_TX_ENABLE = 22;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X3_PORT_0_TX_ENABLE = 23;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X4_PORT_0_TX_ENABLE = 24;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X5_PORT_0_TX_ENABLE = 25;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X6_PORT_0_TX_ENABLE = 26;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_X7_PORT_0_TX_ENABLE = 27;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_31 = 28;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_31_LEN = 4;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_29 = 28; // p10:20,
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_REG_0X01_SPARE_28_29_LEN = 2;
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE = 30; // p10:20,
static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE_LEN = 10;
// ERROR Duplicate Dial         static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE = 32;
// ERROR Duplicate Dial         static const uint32_t TOD_PRI_PORT_0_CTRL_REG_PRI_I_PATH_DELAY_VALUE_LEN = 8;
//<< [TOD_PRI_PORT_0_CTRL_REG]
// perv/reg00025.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "perv/reg00024.H"
#include "perv/reg00025.H"
#endif
#endif
