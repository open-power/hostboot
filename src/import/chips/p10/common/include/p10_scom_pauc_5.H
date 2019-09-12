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

#ifndef __PPE_HCODE__
    #include "proc_scomt.H"
#endif

#ifndef __p10_scom_pauc_5_H_
#define __p10_scom_pauc_5_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace pauc
{
#endif


static const uint64_t DL_PPE_WRAP_XIDBGPRO = 0x10012c55ull;

static const uint32_t DL_PPE_WRAP_XIDBGPRO_XSR_HS = 0;
static const uint32_t DL_PPE_WRAP_XIDBGPRO_XSR_HC = 1;
static const uint32_t DL_PPE_WRAP_XIDBGPRO_XSR_HC_LEN = 3;
static const uint32_t DL_PPE_WRAP_XIDBGPRO_XSR_HCP = 4;
static const uint32_t DL_PPE_WRAP_XIDBGPRO_XSR_RIP = 5;
static const uint32_t DL_PPE_WRAP_XIDBGPRO_XSR_SIP = 6;
static const uint32_t DL_PPE_WRAP_XIDBGPRO_XSR_TRAP = 7;
static const uint32_t DL_PPE_WRAP_XIDBGPRO_XSR_IAC = 8;
static const uint32_t DL_PPE_WRAP_XIDBGPRO_NULL_MSR_SIBRC = 9;
static const uint32_t DL_PPE_WRAP_XIDBGPRO_NULL_MSR_SIBRC_LEN = 3;
static const uint32_t DL_PPE_WRAP_XIDBGPRO_XSR_RDAC = 12;
static const uint32_t DL_PPE_WRAP_XIDBGPRO_XSR_WDAC = 13;
static const uint32_t DL_PPE_WRAP_XIDBGPRO_NULL_MSR_WE = 14;
static const uint32_t DL_PPE_WRAP_XIDBGPRO_XSR_TRH = 15;
static const uint32_t DL_PPE_WRAP_XIDBGPRO_XSR_SMS = 16;
static const uint32_t DL_PPE_WRAP_XIDBGPRO_XSR_SMS_LEN = 4;
static const uint32_t DL_PPE_WRAP_XIDBGPRO_NULL_MSR_LP = 20;
static const uint32_t DL_PPE_WRAP_XIDBGPRO_XSR_EP = 21;
static const uint32_t DL_PPE_WRAP_XIDBGPRO_XSR_PTR = 24;
static const uint32_t DL_PPE_WRAP_XIDBGPRO_XSR_ST = 25;
static const uint32_t DL_PPE_WRAP_XIDBGPRO_XSR_MFE = 28;
static const uint32_t DL_PPE_WRAP_XIDBGPRO_XSR_MCS = 29;
static const uint32_t DL_PPE_WRAP_XIDBGPRO_XSR_MCS_LEN = 3;
static const uint32_t DL_PPE_WRAP_XIDBGPRO_IAR = 32;
static const uint32_t DL_PPE_WRAP_XIDBGPRO_IAR_LEN = 30;
// pauc/reg00005.H

static const uint64_t DL_PPE_WRAP_SCOM_WORK_REG1 = 0x10012c61ull;

static const uint32_t DL_PPE_WRAP_SCOM_WORK_REG1_SCOM_PPE_WORK1 = 0;
static const uint32_t DL_PPE_WRAP_SCOM_WORK_REG1_SCOM_PPE_WORK1_LEN = 32;
// pauc/reg00005.H

static const uint64_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK1 = 0x10040081ull;

static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_XSTOP_ERR = 0;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_RECOV_ERR = 1;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SPATTN_ERR = 2;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_LXSTOP_ERR = 3;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_HOSTATTN_ERR = 4;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_ERR = 5;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_SYS_XSTOP_STAGED_ERR = 6;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK1_DBG_TRIG_ERR = 7;
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

static const uint32_t NET_CTRL1_CACHE0_CLK_DCC_BYPASS = 0;
static const uint32_t NET_CTRL1_CACHE1_CLK_DCC_BYPASS = 1;
static const uint32_t NET_CTRL1_CACHE2_CLK_DCC_BYPASS = 2;
static const uint32_t NET_CTRL1_CACHE3_CLK_DCC_BYPASS = 3;
static const uint32_t NET_CTRL1_CORE0_CLK_DCC_BYPASS = 4;
static const uint32_t NET_CTRL1_CORE1_CLK_DCC_BYPASS = 5;
static const uint32_t NET_CTRL1_CORE2_CLK_DCC_BYPASS = 6;
static const uint32_t NET_CTRL1_CORE3_CLK_DCC_BYPASS = 7;
static const uint32_t NET_CTRL1_CACHE0_CLK_PDLY_BYPASS = 8;
static const uint32_t NET_CTRL1_CACHE1_CLK_PDLY_BYPASS = 9;
static const uint32_t NET_CTRL1_CACHE2_CLK_PDLY_BYPASS = 10;
static const uint32_t NET_CTRL1_CACHE3_CLK_PDLY_BYPASS = 11;
static const uint32_t NET_CTRL1_CORE0_CLK_PDLY_BYPASS = 12;
static const uint32_t NET_CTRL1_CORE1_CLK_PDLY_BYPASS = 13;
static const uint32_t NET_CTRL1_CORE2_CLK_PDLY_BYPASS = 14;
static const uint32_t NET_CTRL1_CORE3_CLK_PDLY_BYPASS = 15;
static const uint32_t NET_CTRL1_CACHE0_CLK_SKEWADJUST_RESET_DC = 16;
static const uint32_t NET_CTRL1_CACHE1_CLK_SKEWADJUST_RESET_DC = 17;
static const uint32_t NET_CTRL1_CACHE2_CLK_SKEWADJUST_RESET_DC = 18;
static const uint32_t NET_CTRL1_CACHE3_CLK_SKEWADJUST_RESET_DC = 19;
static const uint32_t NET_CTRL1_CORE0_CLK_DCADJUST_RESET_DC = 20;
static const uint32_t NET_CTRL1_CORE1_CLK_DCADJUST_RESET_DC = 21;
static const uint32_t NET_CTRL1_CORE2_CLK_DCADJUST_RESET_DC = 22;
static const uint32_t NET_CTRL1_CORE3_CLK_DCADJUST_RESET_DC = 23;
static const uint32_t NET_CTRL1_PCB_ACCESS = 24;
static const uint32_t NET_CTRL1_PCB_ACCESS_LEN = 8;
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

static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_OB01_RTAG_PBITERR = 0;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_OB01_RTAG_PERR = 1;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_OB01_MISC_PERR = 2;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_OB01_F0VC0_EVENPERR = 3;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_OB01_F0VC0_ODDPERR = 4;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_OB01_F0VC1_EVENPERR = 5;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_OB01_F0VC1_ODDPERR = 6;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_OB01_F1VC0_EVENPERR = 7;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_OB01_F1VC0_ODDPERR = 8;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_OB01_F1VC1_EVENPERR = 9;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_OB01_F1VC1_ODDPERR = 10;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_OB01_F0_UNDERFLOW = 11;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_OB01_F0_OVERFLOW = 12;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_OB01_F1_UNDERFLOW = 13;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_OB01_F1_OVERFLOW = 14;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_OB01_VC0_UNDERFLOW = 15;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_OB01_VC0_OVERFLOW = 16;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_OB01_VC1_UNDERFLOW = 17;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_OB01_VC1_OVERFLOW = 18;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_OB01_F0VC0_UNDERFLOW = 19;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_OB01_F0VC0_OVERFLOW = 20;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_OB01_F0VC1_UNDERFLOW = 21;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_OB01_F0VC1_OVERFLOW = 22;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_OB01_F1VC0_UNDERFLOW = 23;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_OB01_F1VC0_OVERFLOW = 24;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_OB01_F1VC1_UNDERFLOW = 25;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_OB01_F1VC1_OVERFLOW = 26;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_OB01_VC0_PREFETCH_OVERFLOW = 27;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_OB01_VC1_PREFETCH_OVERFLOW = 28;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_IB01_EVN0_UNDERFLOW = 29;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_IB01_EVN0_OVERFLOW = 30;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_IB01_EVN1_UNDERFLOW = 31;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_IB01_EVN1_OVERFLOW = 32;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_IB01_RTAG_PBITERR = 33;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_IB01_RTAG_PERR = 34;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_IB01_MISC_PERR = 35;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_IB01_ODD0_UNDERFLOW = 36;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_IB01_ODD0_OVERFLOW = 37;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_IB01_ODD1_UNDERFLOW = 38;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_IB01_ODD1_OVERFLOW = 39;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_IB01_RTAG_UNDERFLOW = 40;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_IB01_RTAG_OVERFLOW = 41;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_IB01_DATA_UNDERFLOW = 42;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_IB01_DATA_OVERFLOW = 43;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_IB01_VC0_UNDERFLOW = 44;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_IB01_VC0_OVERFLOW = 45;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_IB01_VC1_UNDERFLOW = 46;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_IB01_VC1_OVERFLOW = 47;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_OB01_F0VC0_OVER_UNDERFLOW = 48;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_OB01_F0VC1_OVER_UNDERFLOW = 49;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_OB01_F1VC0_OVER_UNDERFLOW = 50;
static const uint32_t PB_DOB01_DIB01_INT_ERR_REG_OB01_F1VC1_OVER_UNDERFLOW = 51;
// pauc/reg00005.H

static const uint64_t PB_MAILBOX_30_REG = 0x10011836ull;
// pauc/reg00005.H

static const uint64_t PB_MAILBOX_31_REG = 0x10011837ull;
// pauc/reg00005.H

static const uint64_t PB_PMU1_CNPM_COUNTER = 0x10011822ull;

static const uint32_t PB_PMU1_CNPM_COUNTER_0 = 0;
static const uint32_t PB_PMU1_CNPM_COUNTER_0_LEN = 16;
static const uint32_t PB_PMU1_CNPM_COUNTER_1 = 16;
static const uint32_t PB_PMU1_CNPM_COUNTER_1_LEN = 16;
static const uint32_t PB_PMU1_CNPM_COUNTER_2 = 32;
static const uint32_t PB_PMU1_CNPM_COUNTER_2_LEN = 16;
static const uint32_t PB_PMU1_CNPM_COUNTER_3 = 48;
static const uint32_t PB_PMU1_CNPM_COUNTER_3_LEN = 16;
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

static const uint64_t PB_TL_LINK_ERR_INJECT_REG = 0x1001180dull;

static const uint32_t PB_TL_LINK_ERR_INJECT_REG_STUCK = 0;
static const uint32_t PB_TL_LINK_ERR_INJECT_REG_SINGLE = 1;
static const uint32_t PB_TL_LINK_ERR_INJECT_REG_BIT_17 = 2;
static const uint32_t PB_TL_LINK_ERR_INJECT_REG_BIT_23 = 3;
static const uint32_t PB_TL_LINK_ERR_INJECT_REG_LINK_0_EVN = 4;
static const uint32_t PB_TL_LINK_ERR_INJECT_REG_LINK_0_ODD = 5;
static const uint32_t PB_TL_LINK_ERR_INJECT_REG_LINK_1_EVN = 6;
static const uint32_t PB_TL_LINK_ERR_INJECT_REG_LINK_1_ODD = 7;
// pauc/reg00005.H

static const uint64_t SCAN_LONG_ROTATE = 0x10039000ull;
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

static const uint64_t TXIRLM_REGS_TX_IMPCAL_SWO8_PB = 0x800f6c0010012c3full;

static const uint32_t TXIRLM_REGS_TX_IMPCAL_SWO8_PB_TX_ZCAL_SWO_IMP_CNTL_1R_1XP_32_39 = 48;
static const uint32_t TXIRLM_REGS_TX_IMPCAL_SWO8_PB_TX_ZCAL_SWO_IMP_CNTL_1R_1XP_32_39_LEN = 8;
// pauc/reg00005.H

#ifndef __PPE_HCODE__
}
}
#include "pauc/reg00005.H"
#endif
#endif
