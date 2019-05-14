/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pauc_5.H $       */
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

#ifndef __p10_scom_pauc_5_H_
#define __p10_scom_pauc_5_H_


namespace scomt
{
namespace pauc
{


static const uint64_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK1 = 0x10040081ull;

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
// pauc/reg00005.H

static const uint64_t EPS_THERM_WSUB_SKITTER_DATA0 = 0x10050019ull;
// pauc/reg00005.H

static const uint64_t EPS_THERM_WSUB_SKITTER_MODE_REG = 0x10050010ull;

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
// pauc/reg00005.H

static const uint64_t ERROR_STATUS = 0x1003000full;

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
// pauc/reg00005.H

static const uint64_t NET_CTRL1_RW = 0x100f0044ull;
static const uint64_t NET_CTRL1_RW_WAND = 0x100f0045ull;
static const uint64_t NET_CTRL1_RW_WOR = 0x100f0046ull;

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
// pauc/reg00005.H

static const uint64_t PB_CNPM_PMU_PRESCALER = 0x10011820ull;

static const uint32_t PB_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C0 = 0;
static const uint32_t PB_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C0_LEN = 2;
static const uint32_t PB_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C1 = 2;
static const uint32_t PB_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C1_LEN = 2;
static const uint32_t PB_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C2 = 4;
static const uint32_t PB_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C2_LEN = 2;
static const uint32_t PB_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C3 = 6;
static const uint32_t PB_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP0_C3_LEN = 2;
static const uint32_t PB_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C0 = 8;
static const uint32_t PB_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C0_LEN = 2;
static const uint32_t PB_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C1 = 10;
static const uint32_t PB_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C1_LEN = 2;
static const uint32_t PB_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C2 = 12;
static const uint32_t PB_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C2_LEN = 2;
static const uint32_t PB_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C3 = 14;
static const uint32_t PB_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP1_C3_LEN = 2;
static const uint32_t PB_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C0 = 16;
static const uint32_t PB_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C0_LEN = 2;
static const uint32_t PB_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C1 = 18;
static const uint32_t PB_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C1_LEN = 2;
static const uint32_t PB_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C2 = 20;
static const uint32_t PB_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C2_LEN = 2;
static const uint32_t PB_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C3 = 22;
static const uint32_t PB_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP2_C3_LEN = 2;
static const uint32_t PB_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C0 = 24;
static const uint32_t PB_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C0_LEN = 2;
static const uint32_t PB_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C1 = 26;
static const uint32_t PB_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C1_LEN = 2;
static const uint32_t PB_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C2 = 28;
static const uint32_t PB_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C2_LEN = 2;
static const uint32_t PB_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C3 = 30;
static const uint32_t PB_CNPM_PMU_PRESCALER_CNPM_PRESCALER_GRP3_C3_LEN = 2;
static const uint32_t PB_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C0 = 32;
static const uint32_t PB_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C0_LEN = 2;
static const uint32_t PB_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C1 = 34;
static const uint32_t PB_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C1_LEN = 2;
static const uint32_t PB_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C2 = 36;
static const uint32_t PB_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C2_LEN = 2;
static const uint32_t PB_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C3 = 38;
static const uint32_t PB_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP0_C3_LEN = 2;
static const uint32_t PB_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C0 = 40;
static const uint32_t PB_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C0_LEN = 2;
static const uint32_t PB_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C1 = 42;
static const uint32_t PB_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C1_LEN = 2;
static const uint32_t PB_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C2 = 44;
static const uint32_t PB_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C2_LEN = 2;
static const uint32_t PB_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C3 = 46;
static const uint32_t PB_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP1_C3_LEN = 2;
static const uint32_t PB_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C0 = 48;
static const uint32_t PB_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C0_LEN = 2;
static const uint32_t PB_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C1 = 50;
static const uint32_t PB_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C1_LEN = 2;
static const uint32_t PB_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C2 = 52;
static const uint32_t PB_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C2_LEN = 2;
static const uint32_t PB_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C3 = 54;
static const uint32_t PB_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP2_C3_LEN = 2;
static const uint32_t PB_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C0 = 56;
static const uint32_t PB_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C0_LEN = 2;
static const uint32_t PB_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C1 = 58;
static const uint32_t PB_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C1_LEN = 2;
static const uint32_t PB_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C2 = 60;
static const uint32_t PB_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C2_LEN = 2;
static const uint32_t PB_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C3 = 62;
static const uint32_t PB_CNPM_PMU_PRESCALER_TLPM_PRESCALER_GRP3_C3_LEN = 2;
// pauc/reg00005.H

static const uint64_t PB_DOB01_DIB01_INT_ERR_REG = 0x10011828ull;
// pauc/reg00005.H

static const uint64_t PB_MAILBOX_30_REG = 0x10011836ull;
// pauc/reg00005.H

static const uint64_t PB_MAILBOX_31_REG = 0x10011837ull;
// pauc/reg00005.H

static const uint64_t PB_PMU1_CNPM_COUNTER = 0x10011822ull;
// pauc/reg00005.H

static const uint64_t PB_PSAVE23_MODE_CFG = 0x10011816ull;

static const uint32_t PB_PSAVE23_MODE_CFG_MODE = 0;
static const uint32_t PB_PSAVE23_MODE_CFG_MODE_LEN = 2;
static const uint32_t PB_PSAVE23_MODE_CFG_WIDTH = 2;
static const uint32_t PB_PSAVE23_MODE_CFG_WIDTH_LEN = 3;
static const uint32_t PB_PSAVE23_MODE_CFG_SPARE = 5;
static const uint32_t PB_PSAVE23_MODE_CFG_SPARE_LEN = 3;
static const uint32_t PB_PSAVE23_MODE_CFG_MIN_RAND_UC = 8;
static const uint32_t PB_PSAVE23_MODE_CFG_MIN_RAND_UC_LEN = 8;
// pauc/reg00005.H

static const uint64_t PB_PTL_FIR_ACTION0_REG = 0x10011806ull;

static const uint32_t PB_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0 = 0;
static const uint32_t PB_PTL_FIR_ACTION0_REG_PB_PTL_FIR_ACTION0_LEN = 40;
// pauc/reg00005.H

static const uint64_t PB_PTL_FIR_ACTION1_REG = 0x10011807ull;

static const uint32_t PB_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1 = 0;
static const uint32_t PB_PTL_FIR_ACTION1_REG_PB_PTL_FIR_ACTION1_LEN = 40;
// pauc/reg00005.H

static const uint64_t PPE_ARB_CSAR = 0x10012c0dull;

static const uint32_t PPE_ARB_CSAR_CSAR_SRAM_ADDRESS = 16;
static const uint32_t PPE_ARB_CSAR_CSAR_SRAM_ADDRESS_LEN = 13;
// pauc/reg00005.H

static const uint64_t PPE_MIB_XISGB = 0x10012c18ull;

static const uint32_t PPE_MIB_XISGB_SGB_STORE_ADDRESS = 0;
static const uint32_t PPE_MIB_XISGB_SGB_STORE_ADDRESS_LEN = 32;
static const uint32_t PPE_MIB_XISGB_MEM_IMPRECISE_ERROR_PENDING = 35;
static const uint32_t PPE_MIB_XISGB_SGB_BYTE_VALID = 36;
static const uint32_t PPE_MIB_XISGB_SGB_BYTE_VALID_LEN = 4;
static const uint32_t PPE_MIB_XISGB_SGB_FLUSH_PENDING = 63;
// pauc/reg00005.H

static const uint64_t PPE_XIRAMEDR = 0x10012c14ull;

static const uint32_t PPE_XIRAMEDR_GA_IR = 0;
static const uint32_t PPE_XIRAMEDR_GA_IR_LEN = 32;
static const uint32_t PPE_XIRAMEDR_EDR = 32;
static const uint32_t PPE_XIRAMEDR_EDR_LEN = 32;
// pauc/reg00005.H

static const uint64_t REGS_TX_IMPCAL_SWO9_PB = 0x800f740010012c3full;

static const uint32_t REGS_TX_IMPCAL_SWO9_PB_1R_4XP = 48;
static const uint32_t REGS_TX_IMPCAL_SWO9_PB_1R_4XP_LEN = 10;
static const uint32_t REGS_TX_IMPCAL_SWO9_PB_1R_4XN = 58;
static const uint32_t REGS_TX_IMPCAL_SWO9_PB_2R_1XP = 59;
static const uint32_t REGS_TX_IMPCAL_SWO9_PB_2R_1XN = 60;
// pauc/reg00005.H

static const uint64_t SCAN_LONG_ROTATE = 0x10039000ull;
// pauc/reg00005.H

static const uint64_t SCOM_PPE_CNTL = 0x10012c20ull;

static const uint32_t SCOM_PPE_CNTL_SCOM_PPE_IORESET = 0;
static const uint32_t SCOM_PPE_CNTL_SCOM_PPE_PDWN = 1;
static const uint32_t SCOM_PPE_CNTL_SCOM_PPE_ARB_ECC_INJECT_ERR = 2;
static const uint32_t SCOM_PPE_CNTL_SCOM_PPE_INTERLEAVING = 3;
static const uint32_t SCOM_PPE_CNTL_SCOM_PPE_INTERLEAVING_LEN = 2;
static const uint32_t SCOM_PPE_CNTL_PPE_IO_VALID_ASYNC_DLY = 5;
static const uint32_t SCOM_PPE_CNTL_PPE_IO_VALID_ASYNC_DLY_LEN = 3;
static const uint32_t SCOM_PPE_CNTL_IO_PPE_DONE_ASYNC_DLY = 8;
static const uint32_t SCOM_PPE_CNTL_IO_PPE_DONE_ASYNC_DLY_LEN = 3;
static const uint32_t SCOM_PPE_CNTL_SCOM_PPE_SPARES = 11;
static const uint32_t SCOM_PPE_CNTL_SCOM_PPE_SPARES_LEN = 5;
// pauc/reg00005.H

static const uint64_t TRA0_TR0_CONFIG_2 = 0x10010405ull;

static const uint32_t TRA0_TR0_CONFIG_2_A = 0;
static const uint32_t TRA0_TR0_CONFIG_2_A_LEN = 24;
static const uint32_t TRA0_TR0_CONFIG_2_B = 24;
static const uint32_t TRA0_TR0_CONFIG_2_B_LEN = 24;
// pauc/reg00005.H

static const uint64_t TRA1_TR0_TRACE_HI_DATA_REG = 0x10010480ull;

static const uint32_t TRA1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t TRA1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// pauc/reg00005.H

}
}
#include "pauc/reg00005.H"
#endif
