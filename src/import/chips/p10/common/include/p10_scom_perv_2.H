/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_perv_2.H $       */
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

#ifndef __p10_scom_perv_2_H_
#define __p10_scom_perv_2_H_


namespace scomt
{
namespace perv
{


static const uint64_t CPLT_STAT0 = 0x00000100ull;

static const uint32_t CPLT_STAT0_ABIST_DONE_DC = 0;
static const uint32_t CPLT_STAT0_EBIST_DONE_DC = 1;
static const uint32_t CPLT_STAT0_RESERVED_2I = 2;
static const uint32_t CPLT_STAT0_RESERVED_3I = 3;
static const uint32_t CPLT_STAT0_TC_DIAG_PORT0_OUT = 4;
static const uint32_t CPLT_STAT0_TC_DIAG_PORT1_OUT = 5;
static const uint32_t CPLT_STAT0_RESERVED_6I = 6;
static const uint32_t CPLT_STAT0_PLL_DESTOUT = 7;
static const uint32_t CPLT_STAT0_CC_CTRL_OPCG_DONE_DC = 8;
static const uint32_t CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC = 9;
static const uint32_t CPLT_STAT0_FREE_USAGE_10I = 10;
static const uint32_t CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_ERR = 10;
static const uint32_t CPLT_STAT0_IOPCI_TC_HSSPRTREADYA = 10;
static const uint32_t CPLT_STAT0_FREE_USAGE_11I = 11;
static const uint32_t CPLT_STAT0_CC_CTRL_PARALLEL_SCAN_COMPARE_HEADER_ERR = 11;
static const uint32_t CPLT_STAT0_IOPCI_TC_HSSPRTREADYB = 11;
static const uint32_t CPLT_STAT0_FREE_USAGE_12I = 12;
static const uint32_t CPLT_STAT0_ANES_TP_VMEAS_CLK_STOPPED = 12;
static const uint32_t CPLT_STAT0_ANEQ_TP_VMEAS_CLK_STOPPED = 12;
static const uint32_t CPLT_STAT0_MC_TC_0_FIR_HOST_ATTN = 12;
static const uint32_t CPLT_STAT0_FREE_USAGE_13I = 13;
static const uint32_t CPLT_STAT0_ANES_TP_VMEAS_RESULT_OUT = 13;
static const uint32_t CPLT_STAT0_ANES_TP_VMEAS_RESULT_OUT_LEN = 10;
static const uint32_t CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_OUT = 13;
static const uint32_t CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_OUT_LEN = 10;
static const uint32_t CPLT_STAT0_MC_TC_1_FIR_HOST_ATTN = 13;
static const uint32_t CPLT_STAT0_FREE_USAGE_14I = 14;
static const uint32_t CPLT_STAT0_MC_TC_2_FIR_HOST_ATTN = 14;
static const uint32_t CPLT_STAT0_FREE_USAGE_15I = 15;
static const uint32_t CPLT_STAT0_MC_TC_3_FIR_HOST_ATTN = 15;
static const uint32_t CPLT_STAT0_FREE_USAGE_16I = 16;
static const uint32_t CPLT_STAT0_MC_TC_4_FIR_HOST_ATTN = 16;
static const uint32_t CPLT_STAT0_FREE_USAGE_17I = 17;
static const uint32_t CPLT_STAT0_MC_TC_5_FIR_HOST_ATTN = 17;
static const uint32_t CPLT_STAT0_FREE_USAGE_18I = 18;
static const uint32_t CPLT_STAT0_MC_TC_6_FIR_HOST_ATTN = 18;
static const uint32_t CPLT_STAT0_FREE_USAGE_19I = 19;
static const uint32_t CPLT_STAT0_MC_TC_7_FIR_HOST_ATTN = 19;
static const uint32_t CPLT_STAT0_FREE_USAGE_20I = 20;
static const uint32_t CPLT_STAT0_MC_TC_8_FIR_HOST_ATTN = 20;
static const uint32_t CPLT_STAT0_FREE_USAGE_21I = 21;
static const uint32_t CPLT_STAT0_FREE_USAGE_22I = 22;
static const uint32_t CPLT_STAT0_FREE_USAGE_23I = 23;
static const uint32_t CPLT_STAT0_ANES_TP_VMEAS_RESULT_VALID = 23;
static const uint32_t CPLT_STAT0_ANEQ_TP_VMEAS_RESULT_VALID = 23;
// perv/reg00002.H

static const uint64_t EPS_THERM_WSUB2_MODE_REG = 0x0005002full;

static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_DIS_CPM_BUBBLE_CORR = 0;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_FORCE_THRES_ACT = 1;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_THRES_TRIP_ENA = 2;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_THRES_TRIP_ENA_LEN = 3;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_DTS_SAMPLE_ENA = 5;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_SAMPLE_PULSE_CNT = 6;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_SAMPLE_PULSE_CNT_LEN = 4;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_THRES_MODE_ENA = 10;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_THRES_MODE_ENA_LEN = 2;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_MODE = 12;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_DTS_TRIGGER_SEL = 13;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_THRES_OVERFLOW_MASK = 14;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_DTS_READ_SEL = 16;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_DTS_READ_SEL_LEN = 4;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L1 = 20;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L1_LEN = 3;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L2 = 24;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L2_LEN = 3;
static const uint32_t EPS_THERM_WSUB2_MODE_REG_THERM_DTS_ENABLE_L3 = 28;
// perv/reg00002.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA0_TR1_TRACE_HI_DATA_REG = 0x00018220ull;

static const uint32_t L3TRA0_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t L3TRA0_TR1_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// perv/reg00002.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA0_TR1_CONFIG_5 = 0x00018228ull;

static const uint32_t L3TRA0_TR1_CONFIG_5_C = 0;
static const uint32_t L3TRA0_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t L3TRA0_TR1_CONFIG_5_D = 24;
static const uint32_t L3TRA0_TR1_CONFIG_5_D_LEN = 24;
// perv/reg00002.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA1_TR0_CONFIG_3 = 0x00018246ull;

static const uint32_t L3TRA1_TR0_CONFIG_3_C = 0;
static const uint32_t L3TRA1_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t L3TRA1_TR0_CONFIG_3_D = 24;
static const uint32_t L3TRA1_TR0_CONFIG_3_D_LEN = 24;
// perv/reg00002.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA2_TR0_CONFIG_4 = 0x00018287ull;

static const uint32_t L3TRA2_TR0_CONFIG_4_A = 0;
static const uint32_t L3TRA2_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t L3TRA2_TR0_CONFIG_4_B = 24;
static const uint32_t L3TRA2_TR0_CONFIG_4_B_LEN = 24;
// perv/reg00002.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA3_TR0_TRACE_LO_DATA_REG = 0x000182c1ull;

static const uint32_t L3TRA3_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t L3TRA3_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t L3TRA3_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t L3TRA3_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t L3TRA3_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t L3TRA3_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t L3TRA3_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t L3TRA3_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t L3TRA3_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t L3TRA3_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t L3TRA3_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// perv/reg00002.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t L3TRA3_TR1_CONFIG_2 = 0x000182e5ull;

static const uint32_t L3TRA3_TR1_CONFIG_2_A = 0;
static const uint32_t L3TRA3_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t L3TRA3_TR1_CONFIG_2_B = 24;
static const uint32_t L3TRA3_TR1_CONFIG_2_B_LEN = 24;
// perv/reg00002.H

static const uint64_t SPATTN_NCX = 0x00040005ull;
static const uint64_t SPATTN_ROX = 0x00040004ull;

static const uint32_t SPATTN_ANY_SPATTN = 0;
static const uint32_t SPATTN_RESERVED1S = 1;
static const uint32_t SPATTN_RESERVED2S = 2;
static const uint32_t SPATTN_RESERVED3S = 3;
static const uint32_t SPATTN_SPATTN_PERV = 4;
static const uint32_t SPATTN_SPATTN_IN05 = 5;
static const uint32_t SPATTN_SPATTN_IN06 = 6;
static const uint32_t SPATTN_SPATTN_IN07 = 7;
static const uint32_t SPATTN_SPATTN_IN08 = 8;
static const uint32_t SPATTN_SPATTN_IN09 = 9;
static const uint32_t SPATTN_SPATTN_IN10 = 10;
static const uint32_t SPATTN_SPATTN_IN11 = 11;
static const uint32_t SPATTN_SPATTN_IN12 = 12;
static const uint32_t SPATTN_SPATTN_IN13 = 13;
static const uint32_t SPATTN_SPATTN_IN14 = 14;
static const uint32_t SPATTN_SPATTN_IN15 = 15;
static const uint32_t SPATTN_SPATTN_IN16 = 16;
static const uint32_t SPATTN_SPATTN_IN17 = 17;
static const uint32_t SPATTN_SPATTN_IN18 = 18;
static const uint32_t SPATTN_SPATTN_IN19 = 19;
static const uint32_t SPATTN_SPATTN_IN20 = 20;
static const uint32_t SPATTN_SPATTN_IN21 = 21;
static const uint32_t SPATTN_SPATTN_IN22 = 22;
static const uint32_t SPATTN_SPATTN_IN23 = 23;
static const uint32_t SPATTN_SPATTN_IN24 = 24;
static const uint32_t SPATTN_SPATTN_IN25 = 25;
static const uint32_t SPATTN_SPATTN_IN26 = 26;
static const uint32_t SPATTN_SPATTN_IN27 = 27;
static const uint32_t SPATTN_SPATTN_IN28 = 28;
static const uint32_t SPATTN_SPATTN_IN29 = 29;
static const uint32_t SPATTN_SPATTN_IN30 = 30;
static const uint32_t SPATTN_SPATTN_IN31 = 31;
static const uint32_t SPATTN_SPATTN_IN32 = 32;
static const uint32_t SPATTN_SPATTN_IN33 = 33;
static const uint32_t SPATTN_SPATTN_IN34 = 34;
static const uint32_t SPATTN_SPATTN_IN35 = 35;
// perv/reg00002.H

static const uint64_t TRA0_TR1_CONFIG_5 = 0x00010448ull;

static const uint32_t TRA0_TR1_CONFIG_5_C = 0;
static const uint32_t TRA0_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TRA0_TR1_CONFIG_5_D = 24;
static const uint32_t TRA0_TR1_CONFIG_5_D_LEN = 24;
// perv/reg00002.H

static const uint64_t TRA1_TR0_CONFIG_3 = 0x00010486ull;

static const uint32_t TRA1_TR0_CONFIG_3_C = 0;
static const uint32_t TRA1_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t TRA1_TR0_CONFIG_3_D = 24;
static const uint32_t TRA1_TR0_CONFIG_3_D_LEN = 24;
// perv/reg00002.H

static const uint64_t TRA2_TR0_CONFIG_4 = 0x00010507ull;

static const uint32_t TRA2_TR0_CONFIG_4_A = 0;
static const uint32_t TRA2_TR0_CONFIG_4_A_LEN = 24;
static const uint32_t TRA2_TR0_CONFIG_4_B = 24;
static const uint32_t TRA2_TR0_CONFIG_4_B_LEN = 24;
// perv/reg00002.H

static const uint64_t TRA3_TR1_CONFIG_2 = 0x000105c5ull;

static const uint32_t TRA3_TR1_CONFIG_2_A = 0;
static const uint32_t TRA3_TR1_CONFIG_2_A_LEN = 24;
static const uint32_t TRA3_TR1_CONFIG_2_B = 24;
static const uint32_t TRA3_TR1_CONFIG_2_B_LEN = 24;
// perv/reg00002.H

static const uint64_t TRA4_TR0_TRACE_HI_DATA_REG = 0x00010600ull;

static const uint32_t TRA4_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TRA4_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// perv/reg00002.H

static const uint64_t TRA4_TR1_CONFIG_3 = 0x00010646ull;

static const uint32_t TRA4_TR1_CONFIG_3_C = 0;
static const uint32_t TRA4_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TRA4_TR1_CONFIG_3_D = 24;
static const uint32_t TRA4_TR1_CONFIG_3_D_LEN = 24;
// perv/reg00002.H

static const uint64_t TRA5_TR0_CONFIG_5 = 0x00010688ull;

static const uint32_t TRA5_TR0_CONFIG_5_C = 0;
static const uint32_t TRA5_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TRA5_TR0_CONFIG_5_D = 24;
static const uint32_t TRA5_TR0_CONFIG_5_D_LEN = 24;
// perv/reg00002.H

static const uint64_t TRA6_TR0_CONFIG_2 = 0x00010705ull;

static const uint32_t TRA6_TR0_CONFIG_2_A = 0;
static const uint32_t TRA6_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TRA6_TR0_CONFIG_2_B = 24;
static const uint32_t TRA6_TR0_CONFIG_2_B_LEN = 24;
// perv/reg00002.H

}
}
#include "perv/reg00002.H"
#endif
