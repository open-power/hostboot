/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_5.H $       */
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

#ifndef __p10_scom_iohs_5_H_
#define __p10_scom_iohs_5_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


//>> [DLP_LINK0_INFO]
static const uint64_t DLP_LINK0_INFO = 0x18011014ull;

static const uint32_t DLP_LINK0_INFO_MAX_TIMEOUT = 0;
static const uint32_t DLP_LINK0_INFO_MAX_TIMEOUT_LEN = 16;
static const uint32_t DLP_LINK0_INFO_FRAME_CAP_VALID = 16;
static const uint32_t DLP_LINK0_INFO_FRAME_CAP_INST = 17;
static const uint32_t DLP_LINK0_INFO_FRAME_CAP_ADDR = 18;
static const uint32_t DLP_LINK0_INFO_FRAME_CAP_ADDR_LEN = 6;
static const uint32_t DLP_LINK0_INFO_FRAME_CAP_SYN = 24;
static const uint32_t DLP_LINK0_INFO_FRAME_CAP_SYN_LEN = 8;
static const uint32_t DLP_LINK0_INFO_REPLAY_CAP_VALID = 32;
static const uint32_t DLP_LINK0_INFO_REPLAY_CAP_INST = 33;
static const uint32_t DLP_LINK0_INFO_REPLAY_CAP_INST_LEN = 2;
static const uint32_t DLP_LINK0_INFO_REPLAY_CAP_ADDR = 35;
static const uint32_t DLP_LINK0_INFO_REPLAY_CAP_ADDR_LEN = 9;
static const uint32_t DLP_LINK0_INFO_REPLAY_CAP_SYN = 44;
static const uint32_t DLP_LINK0_INFO_REPLAY_CAP_SYN_LEN = 8;
static const uint32_t DLP_LINK0_INFO_ACK_FIFO_CAP_VALID = 52;
static const uint32_t DLP_LINK0_INFO_ACK_FIFO_CAP_ADDR = 55;
static const uint32_t DLP_LINK0_INFO_ACK_FIFO_CAP_ADDR_LEN = 9;
//<< [DLP_LINK0_INFO]
// iohs/reg00020.H

//>> [DLP_LINK1_SYN_CAPTURE]
static const uint64_t DLP_LINK1_SYN_CAPTURE = 0x18011023ull;

static const uint32_t DLP_LINK1_SYN_CAPTURE_CRC_SYN = 0;
static const uint32_t DLP_LINK1_SYN_CAPTURE_CRC_SYN_LEN = 36;
static const uint32_t DLP_LINK1_SYN_CAPTURE_SLECC_SYN0 = 36;
static const uint32_t DLP_LINK1_SYN_CAPTURE_SLECC_SYN0_LEN = 8;
static const uint32_t DLP_LINK1_SYN_CAPTURE_SLECC_SYN1 = 44;
static const uint32_t DLP_LINK1_SYN_CAPTURE_SLECC_SYN1_LEN = 8;
static const uint32_t DLP_LINK1_SYN_CAPTURE_SLECC_SYN2 = 52;
static const uint32_t DLP_LINK1_SYN_CAPTURE_SLECC_SYN2_LEN = 8;
static const uint32_t DLP_LINK1_SYN_CAPTURE_RESERVED = 60;
static const uint32_t DLP_LINK1_SYN_CAPTURE_RESERVED_LEN = 3;
static const uint32_t DLP_LINK1_SYN_CAPTURE_VALID = 63;
//<< [DLP_LINK1_SYN_CAPTURE]
// iohs/reg00020.H

//>> [NET_CTRL1]
static const uint64_t NET_CTRL1_RW = 0x180f0044ull;
static const uint64_t NET_CTRL1_RW_WAND = 0x180f0045ull;
static const uint64_t NET_CTRL1_RW_WOR = 0x180f0046ull;

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
//<< [NET_CTRL1]
// iohs/reg00024.H

//>> [IOO_TX0_0_DD_TX_BIT_REGS_CNTL3_PL]
static const uint64_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL3_PL = 0x8004440010012c3full;

static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE = 48;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE = 49;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE = 50;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR = 51;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE = 52;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE = 53;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE = 54;
//<< [IOO_TX0_0_DD_TX_BIT_REGS_CNTL3_PL]
// iohs/reg00023.H

//>> [IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG]
static const uint64_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG = 0x800cfc0010012c3full;

static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG_TX_PSAVE_FORCE_STS_16_23 = 48;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG_TX_PSAVE_FORCE_STS_16_23_LEN = 8;
//<< [IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL8_PG]
// iohs/reg00023.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "iohs/reg00020.H"
#include "iohs/reg00021.H"
#include "iohs/reg00022.H"
#include "iohs/reg00023.H"
#include "iohs/reg00024.H"
#endif
#endif
