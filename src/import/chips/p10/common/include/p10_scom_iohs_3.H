/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_3.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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

#ifndef __p10_scom_iohs_3_H_
#define __p10_scom_iohs_3_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


//>> [DLP_MISC_ERROR_STATUS]
static const uint64_t DLP_MISC_ERROR_STATUS = 0x18011029ull;

static const uint32_t DLP_MISC_ERROR_STATUS_MISC_RESET_KEEPER = 0;
static const uint32_t DLP_MISC_ERROR_STATUS_MISC_INT_ERROR_STATUS = 1;
static const uint32_t DLP_MISC_ERROR_STATUS_MISC_INT_ERROR_STATUS_LEN = 7;
static const uint32_t P10_20_DLP_MISC_ERROR_STATUS_RECEIVE_CONTROL_ERROR = 1; // p10:20,
static const uint32_t P10_20_DLP_MISC_ERROR_STATUS_LINK0_INTERNAL_ACK_ERROR = 2; // p10:20,
static const uint32_t P10_20_DLP_MISC_ERROR_STATUS_LINK0_T9_CONTROL_ERROR = 3; // p10:20,
static const uint32_t P10_20_DLP_MISC_ERROR_STATUS_LINK0_NUM_SAVE_ERROR = 4; // p10:20,
static const uint32_t P10_20_DLP_MISC_ERROR_STATUS_LINK1_INTERNAL_ACK_ERROR = 5; // p10:20,
static const uint32_t P10_20_DLP_MISC_ERROR_STATUS_LINK1_T9_CONTROL_ERROR = 6; // p10:20,
static const uint32_t P10_20_DLP_MISC_ERROR_STATUS_LINK1_NUM_SAVE_ERROR = 7; // p10:20,
static const uint32_t DLP_MISC_ERROR_STATUS_DLX0_ERROR_STATUS = 8;
static const uint32_t DLP_MISC_ERROR_STATUS_DLX0_ERROR_STATUS_LEN = 8;
static const uint32_t DLP_MISC_ERROR_STATUS_DLX1_ERROR_STATUS = 16;
static const uint32_t DLP_MISC_ERROR_STATUS_DLX1_ERROR_STATUS_LEN = 8;
static const uint32_t DLP_MISC_ERROR_STATUS_OLL_ERROR_STATUS = 24;
static const uint32_t DLP_MISC_ERROR_STATUS_OLL_ERROR_STATUS_LEN = 18;
static const uint32_t DLP_MISC_ERROR_STATUS_ODL_ERROR_STATUS = 44;
static const uint32_t DLP_MISC_ERROR_STATUS_ODL_ERROR_STATUS_LEN = 18;
//<< [DLP_MISC_ERROR_STATUS]
// iohs/reg00012.H

//>> [IOO_RX0_0_RD_RX_DAC_REGS_CNTL3_PL]
static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL3_PL = 0x8000180010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL3_PL_GAIN = 48;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL3_PL_GAIN_LEN = 3;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL3_PL_ZERO = 51;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL3_PL_ZERO_LEN = 3;
//<< [IOO_RX0_0_RD_RX_DAC_REGS_CNTL3_PL]
// iohs/reg00012.H

//>> [MULTICAST_GROUP_1]
static const uint64_t MULTICAST_GROUP_1 = 0x180f0001ull;

static const uint32_t MULTICAST_GROUP_1_MULTICAST1_GROUP = 3;
static const uint32_t MULTICAST_GROUP_1_MULTICAST1_GROUP_LEN = 3;
//<< [MULTICAST_GROUP_1]
// iohs/reg00015.H

//>> [NET_CTRL0]
static const uint64_t NET_CTRL0_RW = 0x180f0040ull;
static const uint64_t NET_CTRL0_RW_WAND = 0x180f0041ull;
static const uint64_t NET_CTRL0_RW_WOR = 0x180f0042ull;

static const uint32_t NET_CTRL0_CHIPLET_ENABLE = 0;
static const uint32_t NET_CTRL0_PCB_EP_RESET = 1;
static const uint32_t NET_CTRL0_CLK_ASYNC_RESET = 2;
static const uint32_t NET_CTRL0_PLL_TEST_EN = 3;
static const uint32_t NET_CTRL0_PLL_RESET = 4;
static const uint32_t NET_CTRL0_PLL_BYPASS = 5;
static const uint32_t NET_CTRL0_VITAL_SCAN = 6;
static const uint32_t NET_CTRL0_VITAL_SCAN_IN = 7;
static const uint32_t NET_CTRL0_VITAL_PHASE = 8;
static const uint32_t NET_CTRL0_FLUSH_ALIGN_OVR = 9;
static const uint32_t NET_CTRL0_VITAL_AL = 10;
static const uint32_t NET_CTRL0_ACT_DIS = 11;
static const uint32_t NET_CTRL0_TOADMODE_EN = 12;
static const uint32_t NET_CTRL0_SYNC_PULSE = 13;
static const uint32_t NET_CTRL0_MPW3 = 14;
static const uint32_t NET_CTRL0_DELAY_LCLKR = 15;
static const uint32_t NET_CTRL0_VITAL_THOLD = 16;
static const uint32_t NET_CTRL0_FLUSH_SCAN_N = 17;
static const uint32_t NET_CTRL0_FENCE_EN = 18;
static const uint32_t NET_CTRL0_CPLT_RCTRL = 19;
static const uint32_t NET_CTRL0_CPLT_DCTRL = 20;
static const uint32_t NET_CTRL0_CPLT_RCTRL2 = 21;
static const uint32_t NET_CTRL0_ADJ_FUNC_CLKSEL = 22;
static const uint32_t NET_CTRL0_PM_ACCESS = 23;
static const uint32_t NET_CTRL0_FUNC_LCB_EDIS = 24;
static const uint32_t NET_CTRL0_TP_FENCE_PCB = 25;
static const uint32_t NET_CTRL0_LVLTRANS_FENCE = 26;
static const uint32_t NET_CTRL0_ARRAY_WRITE_ASSIST_EN = 27;
static const uint32_t NET_CTRL0_HTB_INTEST = 28;
static const uint32_t NET_CTRL0_HTB_EXTEST = 29;
// ERROR Duplicate Dial         static const uint32_t NET_CTRL0_PM_ACCESS = 30;
static const uint32_t P10_20_NET_CTRL0_OOB_PROTECTION = 30; // p10:20,
static const uint32_t NET_CTRL0_PLLFORCE_OUT_EN = 31;
//<< [NET_CTRL0]
// iohs/reg00015.H

//>> [PLL_LOCK_REG]
static const uint64_t PLL_LOCK_REG = 0x180f0019ull;

static const uint32_t PLL_LOCK_REG_LOCK = 0;
static const uint32_t PLL_LOCK_REG_LOCK_LEN = 8;
//<< [PLL_LOCK_REG]
// iohs/reg00015.H

//>> [IOO_TX0_TXCTL_CTL_REGS_TX_CNTL3_PG]
static const uint64_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL3_PG = 0x800c540010012c3full;

static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_FINE_SEL = 48;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_FINE_SEL_LEN = 3;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_COARSE_SEL = 51;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_COARSE_SEL_LEN = 4;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_BER_SEL = 55;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL3_PG_BER_SEL_LEN = 6;
//<< [IOO_TX0_TXCTL_CTL_REGS_TX_CNTL3_PG]
// iohs/reg00015.H

//>> [IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG]
static const uint64_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG = 0x800cf40010012c3full;

static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15 = 48;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG_TX_PSAVE_FORCE_STS_0_15_LEN = 16;
//<< [IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL7_PG]
// iohs/reg00015.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "iohs/reg00012.H"
#include "iohs/reg00013.H"
#include "iohs/reg00014.H"
#include "iohs/reg00015.H"
#endif
#endif
