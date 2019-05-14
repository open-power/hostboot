/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_eq_5.H $         */
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

#ifndef __p10_scom_eq_5_H_
#define __p10_scom_eq_5_H_


namespace scomt
{
namespace eq
{


static const uint64_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK1 = 0x20040081ull;

static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_ANY_XSTOP_ERR = 0;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_ANY_RECOV_ERR = 1;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_ANY_SPATTN_ERR = 2;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_ANY_LXSTOP_ERR = 3;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_ANY_HOSTATTN_ERR = 4;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYSTEM_XSTOP = 5;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_OOB1 = 6;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_DBG_FIR_XSTOP_ON_TRIG = 7;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP01 = 12;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP02 = 13;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP03 = 14;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP04 = 15;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP05 = 16;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP06 = 17;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP07 = 18;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP08 = 19;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP09 = 20;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP10 = 21;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP11 = 22;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP12 = 23;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP13 = 24;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP14 = 25;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_UNIT_TC_FIR_LOCAL_XSTOP15 = 26;
// eq/reg00005.H

static const uint64_t EPS_THERM_WSUB_SKITTER_DATA0 = 0x20050019ull;
// eq/reg00005.H

static const uint64_t EPS_THERM_WSUB_SKITTER_MODE_REG = 0x20050010ull;

static const uint32_t EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_HOLD_SAMPLE = 0;
static const uint32_t EPS_THERM_WSUB_SKITTER_MODE_REG_DISABLE_SKITTER_STICKINESS = 1;
static const uint32_t EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_HOLD_DBGTRIG_SEL = 4;
static const uint32_t EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_HOLD_DBGTRIG_SEL_LEN = 2;
static const uint32_t EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_RESET_TRIG_SEL = 6;
static const uint32_t EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_RESET_TRIG_SEL_LEN = 2;
static const uint32_t EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_SAMPLE_GUTS = 8;
static const uint32_t EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_SAMPLE_GUTS_LEN = 2;
static const uint32_t EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_HOLD_SAMPLE_WITH_TRIGGER = 44;
static const uint32_t EPS_THERM_WSUB_SKITTER_MODE_REG_SKITTER_DATA_V_LT = 45;
// eq/reg00005.H

static const uint64_t EPS_THERM_WSUB2_DTS_RESULT1 = 0x20050021ull;

static const uint32_t EPS_THERM_WSUB2_DTS_RESULT1_4_RESULT = 0;
static const uint32_t EPS_THERM_WSUB2_DTS_RESULT1_4_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB2_DTS_RESULT1_5_RESULT = 16;
static const uint32_t EPS_THERM_WSUB2_DTS_RESULT1_5_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB2_DTS_RESULT1_6_RESULT = 32;
static const uint32_t EPS_THERM_WSUB2_DTS_RESULT1_6_RESULT_LEN = 16;
// eq/reg00005.H

static const uint64_t ERROR_STATUS = 0x2003000full;

static const uint32_t ERROR_STATUS_PCB_WRITE_NOT_ALLOWED_ERR = 0;
static const uint32_t ERROR_STATUS_PCB_READ_NOT_ALLOWED_ERR = 1;
static const uint32_t ERROR_STATUS_PCB_PARITY_ON_CMD_ERR = 2;
static const uint32_t ERROR_STATUS_PCB_ADDRESS_NOT_VALID_ERR = 3;
static const uint32_t ERROR_STATUS_PCB_PARITY_ON_ADDR_ERR = 4;
static const uint32_t ERROR_STATUS_PCB_PARITY_ON_DATA_ERR = 5;
static const uint32_t ERROR_STATUS_PCB_PROTECTED_ACCESS_INVALID_ERR = 6;
static const uint32_t ERROR_STATUS_PCB_PARITY_ON_SPCIF_ERR = 7;
static const uint32_t ERROR_STATUS_PCB_WRITE_AND_OPCG_IP_ERR = 8;
static const uint32_t ERROR_STATUS_SCAN_READ_AND_OPCG_IP_ERR = 9;
static const uint32_t ERROR_STATUS_CLOCK_CMD_CONFLICT_ERR = 10;
static const uint32_t ERROR_STATUS_SCAN_COLLISION_ERR = 11;
static const uint32_t ERROR_STATUS_PREVENTED_SCAN_COLLISION_ERR = 12;
static const uint32_t ERROR_STATUS_OPCG_TRIGGER_ERR = 13;
static const uint32_t ERROR_STATUS_PHASE_CNT_CORRUPTION_ERR = 14;
static const uint32_t ERROR_STATUS_CLOCK_CMD_PREVENTED_ERR = 15;
static const uint32_t ERROR_STATUS_PARITY_ON_OPCG_SM_ERR = 16;
static const uint32_t ERROR_STATUS_PARITY_ON_CLOCK_MUX_REG_ERR = 17;
static const uint32_t ERROR_STATUS_PARITY_ON_OPCG_REG_ERR = 18;
static const uint32_t ERROR_STATUS_PARITY_ON_SYNC_CONFIG_REG_ERR = 19;
static const uint32_t ERROR_STATUS_PARITY_ON_XSTOP_REG_ERR = 20;
static const uint32_t ERROR_STATUS_PARITY_ON_GPIO_REG_ERR = 21;
static const uint32_t ERROR_STATUS_CLKCMD_REQUEST_ERR = 22;
static const uint32_t ERROR_STATUS_CBS_PROTOCOL_ERR = 23;
static const uint32_t ERROR_STATUS_VITL_ALIGN_ERR = 24;
static const uint32_t ERROR_STATUS_UNIT_SYNC_LVL_ERR = 25;
static const uint32_t ERROR_STATUS_PARITY_ON_SELFBOOT_CMD_STATE_ERR = 26;
static const uint32_t ERROR_STATUS_OPCG_STOPPED_BY_PCB_ERR = 27;
// eq/reg00005.H

static const uint64_t L3TRA0_TR0_CONFIG_2 = 0x20018205ull;

static const uint32_t L3TRA0_TR0_CONFIG_2_A = 0;
static const uint32_t L3TRA0_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t L3TRA0_TR0_CONFIG_2_B = 24;
static const uint32_t L3TRA0_TR0_CONFIG_2_B_LEN = 24;
// eq/reg00005.H

static const uint64_t L3TRA1_TR1_CONFIG_4 = 0x20018267ull;

static const uint32_t L3TRA1_TR1_CONFIG_4_A = 0;
static const uint32_t L3TRA1_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t L3TRA1_TR1_CONFIG_4_B = 24;
static const uint32_t L3TRA1_TR1_CONFIG_4_B_LEN = 24;
// eq/reg00005.H

static const uint64_t L3TRA2_TR1_CONFIG_3 = 0x200182a6ull;

static const uint32_t L3TRA2_TR1_CONFIG_3_C = 0;
static const uint32_t L3TRA2_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t L3TRA2_TR1_CONFIG_3_D = 24;
static const uint32_t L3TRA2_TR1_CONFIG_3_D_LEN = 24;
// eq/reg00005.H

static const uint64_t L3TRA3_TR0_CONFIG_5 = 0x200182c8ull;

static const uint32_t L3TRA3_TR0_CONFIG_5_C = 0;
static const uint32_t L3TRA3_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t L3TRA3_TR0_CONFIG_5_D = 24;
static const uint32_t L3TRA3_TR0_CONFIG_5_D_LEN = 24;
// eq/reg00005.H

static const uint64_t NET_CTRL1_RW = 0x200f0044ull;
static const uint64_t NET_CTRL1_RW_WAND = 0x200f0045ull;
static const uint64_t NET_CTRL1_RW_WOR = 0x200f0046ull;

static const uint32_t NET_CTRL1_ACHE0_CLK_DCC_BYPASS = 0;
static const uint32_t NET_CTRL1_ACHE1_CLK_DCC_BYPASS = 1;
static const uint32_t NET_CTRL1_ACHE2_CLK_DCC_BYPASS = 2;
static const uint32_t NET_CTRL1_ACHE3_CLK_DCC_BYPASS = 3;
static const uint32_t NET_CTRL1_ORE0_CLK_DCC_BYPASS = 4;
static const uint32_t NET_CTRL1_ORE1_CLK_DCC_BYPASS = 5;
static const uint32_t NET_CTRL1_ORE2_CLK_DCC_BYPASS = 6;
static const uint32_t NET_CTRL1_ORE3_CLK_DCC_BYPASS = 7;
static const uint32_t NET_CTRL1_ACHE0_CLK_PDLY_BYPASS = 8;
static const uint32_t NET_CTRL1_ACHE1_CLK_PDLY_BYPASS = 9;
static const uint32_t NET_CTRL1_ACHE2_CLK_PDLY_BYPASS = 10;
static const uint32_t NET_CTRL1_ACHE3_CLK_PDLY_BYPASS = 11;
static const uint32_t NET_CTRL1_ORE0_CLK_PDLY_BYPASS = 12;
static const uint32_t NET_CTRL1_ORE1_CLK_PDLY_BYPASS = 13;
static const uint32_t NET_CTRL1_ORE2_CLK_PDLY_BYPASS = 14;
static const uint32_t NET_CTRL1_ORE3_CLK_PDLY_BYPASS = 15;
static const uint32_t NET_CTRL1_ACHE0_CLK_SKEWADJUST_RESET_DC = 16;
static const uint32_t NET_CTRL1_ACHE1_CLK_SKEWADJUST_RESET_DC = 17;
static const uint32_t NET_CTRL1_ACHE2_CLK_SKEWADJUST_RESET_DC = 18;
static const uint32_t NET_CTRL1_ACHE3_CLK_SKEWADJUST_RESET_DC = 19;
static const uint32_t NET_CTRL1_ORE0_CLK_DCADJUST_RESET_DC = 20;
static const uint32_t NET_CTRL1_ORE1_CLK_DCADJUST_RESET_DC = 21;
static const uint32_t NET_CTRL1_ORE2_CLK_DCADJUST_RESET_DC = 22;
static const uint32_t NET_CTRL1_ORE3_CLK_DCADJUST_RESET_DC = 23;
// eq/reg00005.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint64_t QME_DB0_PPE = 0x00000006c0001000ull;
static const uint64_t QME_DB0_RW = 0x200e0100ull;

static const uint32_t QME_DB0_NUMBER = 0;
static const uint32_t QME_DB0_NUMBER_LEN = 8;
static const uint32_t QME_DB0_DATA = 8;
static const uint32_t QME_DB0_DATA_LEN = 56;
// eq/reg00005.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint64_t QME_EITR_PPE = 0x00000006c00026c0ull;
static const uint64_t QME_EITR_PPE1 = 0x00000006c00026f0ull;
static const uint64_t QME_EITR_PPE2 = 0x00000006c00026e0ull;
static const uint64_t QME_EITR_RW = 0x200e026cull;
static const uint64_t QME_EITR_WO_CLEAR = 0x200e026full;
static const uint64_t QME_EITR_WO_OR = 0x200e026eull;

static const uint32_t QME_EITR_QME_EITR_INTERRUPT_TYPE = 0;
static const uint32_t QME_EITR_QME_EITR_INTERRUPT_TYPE_LEN = 64;
// eq/reg00005.H

static const uint64_t SCAN_LONG_ROTATE = 0x20039000ull;
// eq/reg00005.H

}
}
#include "eq/reg00005.H"
#endif
