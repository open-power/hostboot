/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_0.H $       */
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

#ifndef __p10_scom_iohs_0_H_
#define __p10_scom_iohs_0_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


//>> [DLP_LINK0_SYN_CAPTURE]
static const uint64_t DLP_LINK0_SYN_CAPTURE = 0x18011022ull;

static const uint32_t DLP_LINK0_SYN_CAPTURE_CRC_SYN = 0;
static const uint32_t DLP_LINK0_SYN_CAPTURE_CRC_SYN_LEN = 36;
static const uint32_t DLP_LINK0_SYN_CAPTURE_SLECC_SYN0 = 36;
static const uint32_t DLP_LINK0_SYN_CAPTURE_SLECC_SYN0_LEN = 8;
static const uint32_t DLP_LINK0_SYN_CAPTURE_SLECC_SYN1 = 44;
static const uint32_t DLP_LINK0_SYN_CAPTURE_SLECC_SYN1_LEN = 8;
static const uint32_t DLP_LINK0_SYN_CAPTURE_SLECC_SYN2 = 52;
static const uint32_t DLP_LINK0_SYN_CAPTURE_SLECC_SYN2_LEN = 8;
static const uint32_t DLP_LINK0_SYN_CAPTURE_RESERVED = 60;
static const uint32_t DLP_LINK0_SYN_CAPTURE_RESERVED_LEN = 3;
static const uint32_t DLP_LINK0_SYN_CAPTURE_VALID = 63;
//<< [DLP_LINK0_SYN_CAPTURE]
// iohs/reg00000.H

//>> [DLP_LINK1_INFO]
static const uint64_t DLP_LINK1_INFO = 0x18011015ull;

static const uint32_t DLP_LINK1_INFO_MAX_TIMEOUT = 0;
static const uint32_t DLP_LINK1_INFO_MAX_TIMEOUT_LEN = 16;
static const uint32_t DLP_LINK1_INFO_FRAME_CAP_VALID = 16;
static const uint32_t DLP_LINK1_INFO_FRAME_CAP_INST = 17;
static const uint32_t DLP_LINK1_INFO_FRAME_CAP_ADDR = 18;
static const uint32_t DLP_LINK1_INFO_FRAME_CAP_ADDR_LEN = 6;
static const uint32_t DLP_LINK1_INFO_FRAME_CAP_SYN = 24;
static const uint32_t DLP_LINK1_INFO_FRAME_CAP_SYN_LEN = 8;
static const uint32_t DLP_LINK1_INFO_REPLAY_CAP_VALID = 32;
static const uint32_t DLP_LINK1_INFO_REPLAY_CAP_INST = 33;
static const uint32_t DLP_LINK1_INFO_REPLAY_CAP_INST_LEN = 2;
static const uint32_t DLP_LINK1_INFO_REPLAY_CAP_ADDR = 35;
static const uint32_t DLP_LINK1_INFO_REPLAY_CAP_ADDR_LEN = 9;
static const uint32_t DLP_LINK1_INFO_REPLAY_CAP_SYN = 44;
static const uint32_t DLP_LINK1_INFO_REPLAY_CAP_SYN_LEN = 8;
static const uint32_t DLP_LINK1_INFO_ACK_FIFO_CAP_VALID = 52;
static const uint32_t DLP_LINK1_INFO_ACK_FIFO_CAP_ADDR = 55;
static const uint32_t DLP_LINK1_INFO_ACK_FIFO_CAP_ADDR_LEN = 9;
//<< [DLP_LINK1_INFO]
// iohs/reg00000.H

//>> [IOO_RX0_0_RD_RX_DAC_REGS_CNTL13_PL]
static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL13_PL = 0x8000680010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL13_PL_GAIN = 48;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL13_PL_GAIN_LEN = 4;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL13_PL_PEAK1 = 52;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL13_PL_PEAK1_LEN = 4;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL13_PL_PEAK2 = 56;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL13_PL_PEAK2_LEN = 4;
//<< [IOO_RX0_0_RD_RX_DAC_REGS_CNTL13_PL]
// iohs/reg00000.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "iohs/reg00000.H"
#include "iohs/reg00001.H"
#include "iohs/reg00002.H"
#include "iohs/reg00003.H"
#endif
#endif
