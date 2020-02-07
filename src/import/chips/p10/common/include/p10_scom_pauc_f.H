/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pauc_f.H $       */
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

#ifndef __p10_scom_pauc_f_H_
#define __p10_scom_pauc_f_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace pauc
{
#endif


static const uint64_t BIST = 0x1003000bull;

static const uint32_t BIST_TC_BIST_START_TEST_DC = 0;
static const uint32_t BIST_TC_SRAM_ABIST_MODE_DC = 1;
static const uint32_t BIST_TC_IOBIST_MODE_DC = 3;
static const uint32_t BIST_REGION_PERV = 4;
static const uint32_t BIST_REGION_UNIT1 = 5;
static const uint32_t BIST_REGION_UNIT2 = 6;
static const uint32_t BIST_REGION_UNIT3 = 7;
static const uint32_t BIST_REGION_UNIT4 = 8;
static const uint32_t BIST_REGION_UNIT5 = 9;
static const uint32_t BIST_REGION_UNIT6 = 10;
static const uint32_t BIST_REGION_UNIT7 = 11;
static const uint32_t BIST_REGION_UNIT8 = 12;
static const uint32_t BIST_REGION_UNIT9 = 13;
static const uint32_t BIST_REGION_UNIT10 = 14;
static const uint32_t BIST_REGION_UNIT11 = 15;
static const uint32_t BIST_REGION_UNIT12 = 16;
static const uint32_t BIST_REGION_UNIT13 = 17;
static const uint32_t BIST_REGION_UNIT14 = 18;
static const uint32_t BIST_STROBE_WINDOW_EN = 48;
// pauc/reg00015.H

static const uint64_t CPLT_CTRL5_RW = 0x10000005ull;
static const uint64_t CPLT_CTRL5_WO_CLEAR = 0x10000025ull;
static const uint64_t CPLT_CTRL5_WO_OR = 0x10000015ull;

static const uint32_t CPLT_CTRL5_0 = 0;
static const uint32_t CPLT_CTRL5_1 = 1;
static const uint32_t CPLT_CTRL5_2 = 2;
static const uint32_t CPLT_CTRL5_3 = 3;
static const uint32_t CPLT_CTRL5_4 = 4;
static const uint32_t CPLT_CTRL5_5 = 5;
static const uint32_t CPLT_CTRL5_6 = 6;
static const uint32_t CPLT_CTRL5_7 = 7;
static const uint32_t CPLT_CTRL5_8 = 8;
static const uint32_t CPLT_CTRL5_9 = 9;
static const uint32_t CPLT_CTRL5_10 = 10;
static const uint32_t CPLT_CTRL5_11 = 11;
static const uint32_t CPLT_CTRL5_12 = 12;
static const uint32_t CPLT_CTRL5_13 = 13;
static const uint32_t CPLT_CTRL5_14 = 14;
static const uint32_t CPLT_CTRL5_15 = 15;
static const uint32_t CPLT_CTRL5_16 = 16;
static const uint32_t CPLT_CTRL5_17 = 17;
static const uint32_t CPLT_CTRL5_18 = 18;
static const uint32_t CPLT_CTRL5_19 = 19;
// pauc/reg00015.H

static const uint64_t DL_PPE_WRAP_XIRAMRA = 0x10012c51ull;

static const uint32_t DL_PPE_WRAP_XIRAMRA_XCR = 1;
static const uint32_t DL_PPE_WRAP_XIRAMRA_XCR_LEN = 3;
static const uint32_t DL_PPE_WRAP_XIRAMRA_RAMRA_SPRG0 = 32;
static const uint32_t DL_PPE_WRAP_XIRAMRA_RAMRA_SPRG0_LEN = 32;
// pauc/reg00015.H

static const uint64_t DL_PPE_WRAP_SCOM_WORK_REG2 = 0x10012c62ull;

static const uint32_t DL_PPE_WRAP_SCOM_WORK_REG2_SCOM_PPE_WORK2 = 0;
static const uint32_t DL_PPE_WRAP_SCOM_WORK_REG2_SCOM_PPE_WORK2_LEN = 32;
// pauc/reg00015.H

static const uint64_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2 = 0x10040082ull;

static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_XSTOP_ERR = 0;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_RECOV_ERR = 1;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SPATTN_ERR = 2;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_LXSTOP_ERR = 3;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_HOSTATTN_ERR = 4;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SYS_XSTOP_ERR = 5;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SYS_XSTOP_STAGED_ERR = 6;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_DBG_TRIG_ERR = 7;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP01 = 12;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP02 = 13;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP03 = 14;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP04 = 15;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP05 = 16;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP06 = 17;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP07 = 18;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP08 = 19;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP09 = 20;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP010 = 21;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP011 = 22;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP012 = 23;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP013 = 24;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP014 = 25;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP015 = 26;
// pauc/reg00015.H

static const uint64_t EPS_THERM_WSUB_DTS_RESULT0 = 0x10050000ull;

static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_0_RESULT = 0;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_0_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_1_RESULT = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_1_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_2_RESULT = 32;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_2_RESULT_LEN = 16;
// pauc/reg00015.H

static const uint64_t MULTICAST_GROUP_3 = 0x100f0003ull;

static const uint32_t MULTICAST_GROUP_3_MULTICAST3_GROUP = 3;
static const uint32_t MULTICAST_GROUP_3_MULTICAST3_GROUP_LEN = 3;
// pauc/reg00015.H

static const uint64_t PB_MAILBOX_CTL_REG = 0x1001182eull;

static const uint32_t PB_MAILBOX_CTL_REG_B_VALID = 0;
static const uint32_t PB_MAILBOX_CTL_REG_B_WR_NOT_RD = 1;
static const uint32_t PB_MAILBOX_CTL_REG_B_BAD_ADDR = 2;
static const uint32_t PB_MAILBOX_CTL_REG_B_LINK_DOWN = 3;
static const uint32_t PB_MAILBOX_CTL_REG_B_CORRUPT = 4;
static const uint32_t PB_MAILBOX_CTL_REG_B_SENT = 5;
static const uint32_t PB_MAILBOX_CTL_REG_B_BAD_WRITE = 6;
static const uint32_t PB_MAILBOX_CTL_REG_B_RESET = 7;
static const uint32_t PB_MAILBOX_CTL_REG_AILBOX_ID = 8;
static const uint32_t PB_MAILBOX_CTL_REG_B_LINK_ID = 9;
static const uint32_t PB_MAILBOX_CTL_REG_B_LINK_ID_LEN = 3;
static const uint32_t PB_MAILBOX_CTL_REG_B_SPARE = 12;
static const uint32_t PB_MAILBOX_CTL_REG_B_SPARE_LEN = 4;
// pauc/reg00015.H

static const uint64_t PB_TL_LINK_SYN_01_REG = 0x10011812ull;

static const uint32_t PB_TL_LINK_SYN_01_REG_0_SCOM_SYN0 = 0;
static const uint32_t PB_TL_LINK_SYN_01_REG_0_SCOM_SYN0_LEN = 8;
static const uint32_t PB_TL_LINK_SYN_01_REG_0_SCOM_SYN1 = 8;
static const uint32_t PB_TL_LINK_SYN_01_REG_0_SCOM_SYN1_LEN = 8;
static const uint32_t PB_TL_LINK_SYN_01_REG_0_SCOM_SYN2 = 16;
static const uint32_t PB_TL_LINK_SYN_01_REG_0_SCOM_SYN2_LEN = 8;
static const uint32_t PB_TL_LINK_SYN_01_REG_0_SCOM_SYN3 = 24;
static const uint32_t PB_TL_LINK_SYN_01_REG_0_SCOM_SYN3_LEN = 8;
static const uint32_t PB_TL_LINK_SYN_01_REG_1_SCOM_SYN0 = 32;
static const uint32_t PB_TL_LINK_SYN_01_REG_1_SCOM_SYN0_LEN = 8;
static const uint32_t PB_TL_LINK_SYN_01_REG_1_SCOM_SYN1 = 40;
static const uint32_t PB_TL_LINK_SYN_01_REG_1_SCOM_SYN1_LEN = 8;
static const uint32_t PB_TL_LINK_SYN_01_REG_1_SCOM_SYN2 = 48;
static const uint32_t PB_TL_LINK_SYN_01_REG_1_SCOM_SYN2_LEN = 8;
static const uint32_t PB_TL_LINK_SYN_01_REG_1_SCOM_SYN3 = 56;
static const uint32_t PB_TL_LINK_SYN_01_REG_1_SCOM_SYN3_LEN = 8;
// pauc/reg00015.H

static const uint64_t PROTECT_MODE_REG = 0x100f03feull;

static const uint32_t PROTECT_MODE_REG_READ_PROTECT_ENABLE = 0;
static const uint32_t PROTECT_MODE_REG_WRITE_PROTECT_ENABLE = 1;
// pauc/reg00015.H

static const uint64_t TIMEOUT_REG = 0x100f0010ull;

static const uint32_t TIMEOUT_REG_INT_TIMEOUT = 0;
static const uint32_t TIMEOUT_REG_INT_TIMEOUT_LEN = 2;
// pauc/reg00015.H

static const uint64_t TRA0_TR0_CONFIG_1 = 0x10010404ull;

static const uint32_t TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// pauc/reg00015.H

static const uint64_t TXIRLM_REGS_TX_IMPCAL3_PB = 0x800f15c010012c3full;

static const uint32_t TXIRLM_REGS_TX_IMPCAL3_PB_TX_ZCAL_SAMPLE_CNT_RO_SIGNAL = 48;
static const uint32_t TXIRLM_REGS_TX_IMPCAL3_PB_TX_ZCAL_SAMPLE_CNT_RO_SIGNAL_LEN = 10;
// pauc/reg00015.H

static const uint64_t TXIRLM_REGS_TX_IMPCAL_SWO1_PB = 0x800f35c010012c3full;

static const uint32_t TXIRLM_REGS_TX_IMPCAL_SWO1_PB_SWO_EN = 48;
static const uint32_t TXIRLM_REGS_TX_IMPCAL_SWO1_PB_SWO_CAL_SEGS = 49;
static const uint32_t TXIRLM_REGS_TX_IMPCAL_SWO1_PB_SWO_CMP_INV = 50;
static const uint32_t TXIRLM_REGS_TX_IMPCAL_SWO1_PB_SWO_CMP_OFFSET = 51;
static const uint32_t TXIRLM_REGS_TX_IMPCAL_SWO1_PB_SWO_CMP_RESET = 52;
static const uint32_t TXIRLM_REGS_TX_IMPCAL_SWO1_PB_SWO_POWERDOWN = 53;
static const uint32_t TXIRLM_REGS_TX_IMPCAL_SWO1_PB_SWO_TCOIL = 54;
static const uint32_t TXIRLM_REGS_TX_IMPCAL_SWO1_PB_RANGE_CHECK = 56;
static const uint32_t TXIRLM_REGS_TX_IMPCAL_SWO1_PB_CYA_DATA_INV = 57;
static const uint32_t TXIRLM_REGS_TX_IMPCAL_SWO1_PB_TEST_OVR_2R = 58;
static const uint32_t TXIRLM_REGS_TX_IMPCAL_SWO1_PB_TEST_OVR_1R = 59;
static const uint32_t TXIRLM_REGS_TX_IMPCAL_SWO1_PB_TEST_OVR_4X_SEG = 60;
static const uint32_t TXIRLM_REGS_TX_IMPCAL_SWO1_PB_TEST_CLK_DIV = 61;
static const uint32_t TXIRLM_REGS_TX_IMPCAL_SWO1_PB_TEST_CLK_DIV_LEN = 2;
// pauc/reg00015.H

static const uint64_t VITAL_SCAN_OUT = 0x100f0017ull;
// pauc/reg00015.H

static const uint64_t XSTOP_UNMASKED = 0x10040010ull;

static const uint32_t XSTOP_UNMASKED_IN = 1;
static const uint32_t XSTOP_UNMASKED_IN_LEN = 53;
// pauc/reg00015.H

#ifndef __PPE_HCODE__
}
}
#include "pauc/reg00015.H"
#endif
#endif
