/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pauc_7.H $       */
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

#ifndef __p10_scom_pauc_7_H_
#define __p10_scom_pauc_7_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace pauc
{
#endif


static const uint64_t DL_PPE_WRAP_SCOM_CNTL = 0x10012c60ull;

static const uint32_t DL_PPE_WRAP_SCOM_CNTL_SCOM_PPE_IORESET = 0;
static const uint32_t DL_PPE_WRAP_SCOM_CNTL_SCOM_PPE_PDWN = 1;
static const uint32_t DL_PPE_WRAP_SCOM_CNTL_SCOM_PPE_ARB_ECC_INJECT_ERR = 2;
static const uint32_t DL_PPE_WRAP_SCOM_CNTL_SCOM_PPE_INTERLEAVING = 3;
static const uint32_t DL_PPE_WRAP_SCOM_CNTL_SCOM_PPE_INTERLEAVING_LEN = 2;
static const uint32_t DL_PPE_WRAP_SCOM_CNTL_PPE_IO_VALID_ASYNC_DLY = 5;
static const uint32_t DL_PPE_WRAP_SCOM_CNTL_PPE_IO_VALID_ASYNC_DLY_LEN = 3;
static const uint32_t DL_PPE_WRAP_SCOM_CNTL_IO_PPE_DONE_ASYNC_DLY = 8;
static const uint32_t DL_PPE_WRAP_SCOM_CNTL_IO_PPE_DONE_ASYNC_DLY_LEN = 3;
static const uint32_t DL_PPE_WRAP_SCOM_CNTL_SCOM_PPE_SPARES = 11;
static const uint32_t DL_PPE_WRAP_SCOM_CNTL_SCOM_PPE_SPARES_LEN = 5;
// pauc/reg00007.H

static const uint64_t EPS_THERM_WSUB_CONTROL_REG = 0x10050012ull;

static const uint32_t EPS_THERM_WSUB_CONTROL_REG_RESET_TRIP_HISTORY = 0;
static const uint32_t EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_PULSE_CNT = 1;
static const uint32_t EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_RD = 2;
static const uint32_t EPS_THERM_WSUB_CONTROL_REG_F_RESET_CPM_WR = 3;
static const uint32_t EPS_THERM_WSUB_CONTROL_REG_RESET_SAMPLE_DTS = 4;
static const uint32_t EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS = 5;
static const uint32_t EPS_THERM_WSUB_CONTROL_REG_FORCE_SAMPLE_DTS_INTERRUPTIBLE = 6;
static const uint32_t EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L1RESULTS = 7;
static const uint32_t EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L2RESULTS = 8;
static const uint32_t EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_THRES_L3RESULTS = 9;
static const uint32_t EPS_THERM_WSUB_CONTROL_REG_FORCE_MEASURE_VOLT_INTERRUPTIBLE = 10;
static const uint32_t EPS_THERM_WSUB_CONTROL_REG_FORCE_RESET_MEASURE_VOLT = 11;
static const uint32_t EPS_THERM_WSUB_CONTROL_REG_FORCE_SHIFT_SENSOR = 12;
// pauc/reg00007.H

static const uint64_t EPS_THERM_WSUB_SKITTER_CLKSRC_REG = 0x10050016ull;

static const uint32_t EPS_THERM_WSUB_SKITTER_CLKSRC_REG_CLKSRC = 0;
static const uint32_t EPS_THERM_WSUB_SKITTER_CLKSRC_REG_CLKSRC_LEN = 3;
static const uint32_t EPS_THERM_WSUB_SKITTER_CLKSRC_REG_DELAY_SELECT = 36;
static const uint32_t EPS_THERM_WSUB_SKITTER_CLKSRC_REG_DELAY_SELECT_LEN = 2;
// pauc/reg00007.H

static const uint64_t HANG_PULSE_0_REG = 0x100f0020ull;

static const uint32_t HANG_PULSE_0_REG_HANG_PULSE_REG_0 = 0;
static const uint32_t HANG_PULSE_0_REG_HANG_PULSE_REG_0_LEN = 6;
static const uint32_t HANG_PULSE_0_REG_SUPPRESS_HANG_0 = 6;
// pauc/reg00007.H

static const uint64_t HANG_PULSE_1_REG = 0x100f0021ull;

static const uint32_t HANG_PULSE_1_REG_HANG_PULSE_REG_1 = 0;
static const uint32_t HANG_PULSE_1_REG_HANG_PULSE_REG_1_LEN = 6;
static const uint32_t HANG_PULSE_1_REG_SUPPRESS_HANG_1 = 6;
// pauc/reg00007.H

static const uint64_t HANG_PULSE_2_REG = 0x100f0022ull;

static const uint32_t HANG_PULSE_2_REG_HANG_PULSE_REG_2 = 0;
static const uint32_t HANG_PULSE_2_REG_HANG_PULSE_REG_2_LEN = 6;
static const uint32_t HANG_PULSE_2_REG_SUPPRESS_HANG_2 = 6;
// pauc/reg00007.H

static const uint64_t HANG_PULSE_3_REG = 0x100f0023ull;

static const uint32_t HANG_PULSE_3_REG_HANG_PULSE_REG_3 = 0;
static const uint32_t HANG_PULSE_3_REG_HANG_PULSE_REG_3_LEN = 6;
static const uint32_t HANG_PULSE_3_REG_SUPPRESS_HANG_3 = 6;
// pauc/reg00007.H

static const uint64_t HANG_PULSE_4_REG = 0x100f0024ull;

static const uint32_t HANG_PULSE_4_REG_HANG_PULSE_REG_4 = 0;
static const uint32_t HANG_PULSE_4_REG_HANG_PULSE_REG_4_LEN = 6;
static const uint32_t HANG_PULSE_4_REG_SUPPRESS_HANG_4 = 6;
// pauc/reg00007.H

static const uint64_t HANG_PULSE_5_REG = 0x100f0025ull;

static const uint32_t HANG_PULSE_5_REG_HANG_PULSE_REG_5 = 0;
static const uint32_t HANG_PULSE_5_REG_HANG_PULSE_REG_5_LEN = 6;
static const uint32_t HANG_PULSE_5_REG_SUPPRESS_HANG_5 = 6;
// pauc/reg00007.H

static const uint64_t HANG_PULSE_6_REG = 0x100f0026ull;

static const uint32_t HANG_PULSE_6_REG_HANG_PULSE_REG_6 = 0;
static const uint32_t HANG_PULSE_6_REG_HANG_PULSE_REG_6_LEN = 6;
static const uint32_t HANG_PULSE_6_REG_SUPPRESS_HANG_6 = 6;
// pauc/reg00007.H

static const uint64_t HOSTATTN_INTERRUPT_REG = 0x100f002bull;

static const uint32_t HOSTATTN_INTERRUPT_REG_TYPE4 = 0;
// pauc/reg00007.H

static const uint64_t OPCG_CAPT2 = 0x10030011ull;

static const uint32_t OPCG_CAPT2_13_01EVEN = 4;
static const uint32_t OPCG_CAPT2_13_01EVEN_LEN = 5;
static const uint32_t OPCG_CAPT2_14_01ODD = 9;
static const uint32_t OPCG_CAPT2_14_01ODD_LEN = 5;
static const uint32_t OPCG_CAPT2_15_02EVEN = 14;
static const uint32_t OPCG_CAPT2_15_02EVEN_LEN = 5;
static const uint32_t OPCG_CAPT2_16_02ODD = 19;
static const uint32_t OPCG_CAPT2_16_02ODD_LEN = 5;
static const uint32_t OPCG_CAPT2_17_03EVEN = 24;
static const uint32_t OPCG_CAPT2_17_03EVEN_LEN = 5;
static const uint32_t OPCG_CAPT2_18_03ODD = 29;
static const uint32_t OPCG_CAPT2_18_03ODD_LEN = 5;
static const uint32_t OPCG_CAPT2_19_04EVEN = 34;
static const uint32_t OPCG_CAPT2_19_04EVEN_LEN = 5;
static const uint32_t OPCG_CAPT2_20_04ODD = 39;
static const uint32_t OPCG_CAPT2_20_04ODD_LEN = 5;
static const uint32_t OPCG_CAPT2_21_05EVEN = 44;
static const uint32_t OPCG_CAPT2_21_05EVEN_LEN = 5;
static const uint32_t OPCG_CAPT2_22_05ODD = 49;
static const uint32_t OPCG_CAPT2_22_05ODD_LEN = 5;
static const uint32_t OPCG_CAPT2_23_06EVEN = 54;
static const uint32_t OPCG_CAPT2_23_06EVEN_LEN = 5;
static const uint32_t OPCG_CAPT2_24_06ODD = 59;
static const uint32_t OPCG_CAPT2_24_06ODD_LEN = 5;
// pauc/reg00007.H

static const uint64_t PB_PMU1_TLPM_COUNTER = 0x1001181cull;

static const uint32_t PB_PMU1_TLPM_COUNTER_0 = 0;
static const uint32_t PB_PMU1_TLPM_COUNTER_0_LEN = 16;
static const uint32_t PB_PMU1_TLPM_COUNTER_1 = 16;
static const uint32_t PB_PMU1_TLPM_COUNTER_1_LEN = 16;
static const uint32_t PB_PMU1_TLPM_COUNTER_2 = 32;
static const uint32_t PB_PMU1_TLPM_COUNTER_2_LEN = 16;
static const uint32_t PB_PMU1_TLPM_COUNTER_3 = 48;
static const uint32_t PB_PMU1_TLPM_COUNTER_3_LEN = 16;
// pauc/reg00007.H

static const uint64_t RECOV_UNMASKED = 0x10040011ull;

static const uint32_t RECOV_UNMASKED_IN = 1;
static const uint32_t RECOV_UNMASKED_IN_LEN = 53;
// pauc/reg00007.H

static const uint64_t SCAN_UPDATEDR = 0x1003a000ull;

static const uint32_t SCAN_UPDATEDR_SCAN_UPDATEDR_REG = 0;
static const uint32_t SCAN_UPDATEDR_SCAN_UPDATEDR_REG_LEN = 32;
// pauc/reg00007.H

static const uint64_t SPATTN_UNMASKED = 0x10040012ull;

static const uint32_t SPATTN_UNMASKED_IN = 1;
static const uint32_t SPATTN_UNMASKED_IN_LEN = 35;
// pauc/reg00007.H

static const uint64_t SYNC_CONFIG = 0x10030000ull;

static const uint32_t SYNC_CONFIG_SYNC_PULSE_DELAY = 0;
static const uint32_t SYNC_CONFIG_SYNC_PULSE_DELAY_LEN = 4;
static const uint32_t SYNC_CONFIG_LISTEN_TO_SYNC_PULSE_DIS = 4;
static const uint32_t SYNC_CONFIG_SYNC_PULSE_INPUT_SEL = 5;
static const uint32_t SYNC_CONFIG_USE_SYNC_FOR_SCAN = 6;
static const uint32_t SYNC_CONFIG_CLEAR_CHIPLET_IS_ALIGNED = 7;
static const uint32_t SYNC_CONFIG_PCB_NOT_BLOCKED_BY_CLKCMD = 8;
static const uint32_t SYNC_CONFIG_DISABLE_PCB_ITR = 9;
static const uint32_t SYNC_CONFIG_CONT_SCAN_DISABLE = 10;
static const uint32_t SYNC_CONFIG_SYNC_PULSE_OUT_DIS = 11;
static const uint32_t SYNC_CONFIG_REGION_PGOOD_OVERRIDE = 12;
static const uint32_t SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_EN = 15;
static const uint32_t SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE = 16;
static const uint32_t SYNC_CONFIG_PHASE_COUNTER_ON_CLKCHANGE_LEN = 8;
// pauc/reg00007.H

static const uint64_t TRA0_TR1_CONFIG_3 = 0x10010446ull;

static const uint32_t TRA0_TR1_CONFIG_3_C = 0;
static const uint32_t TRA0_TR1_CONFIG_3_C_LEN = 24;
static const uint32_t TRA0_TR1_CONFIG_3_D = 24;
static const uint32_t TRA0_TR1_CONFIG_3_D_LEN = 24;
// pauc/reg00007.H

static const uint64_t TRA1_TR0_CONFIG_5 = 0x10010488ull;

static const uint32_t TRA1_TR0_CONFIG_5_C = 0;
static const uint32_t TRA1_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TRA1_TR0_CONFIG_5_D = 24;
static const uint32_t TRA1_TR0_CONFIG_5_D_LEN = 24;
// pauc/reg00007.H

static const uint64_t TXIRLM_REGS_TX_IMPCAL_PVAL_PB = 0x800f240010012c3full;

static const uint32_t TXIRLM_REGS_TX_IMPCAL_PVAL_PB_TX_ZCAL_P = 48;
static const uint32_t TXIRLM_REGS_TX_IMPCAL_PVAL_PB_TX_ZCAL_P_LEN = 9;
// pauc/reg00007.H

static const uint64_t TXIRLM_REGS_ZCAL_FIR_MASK_PB = 0x800f900010012c3full;

static const uint32_t TXIRLM_REGS_ZCAL_FIR_MASK_PB_ZCAL_FIR_ERRS_MASK = 48;
static const uint32_t TXIRLM_REGS_ZCAL_FIR_MASK_PB_ZCAL_FIR_ERRS_MASK_LEN = 2;
// pauc/reg00007.H

#ifndef __PPE_HCODE__
}
}
#include "pauc/reg00007.H"
#endif
#endif
