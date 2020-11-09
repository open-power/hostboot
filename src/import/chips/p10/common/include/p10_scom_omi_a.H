/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omi_a.H $        */
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

#ifndef __p10_scom_omi_a_H_
#define __p10_scom_omi_a_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace omi
{
#endif


//>> [ERROR_CAPTURE]
static const uint64_t ERROR_CAPTURE = 0x0c011414ull;

static const uint32_t ERROR_CAPTURE_DL0_ERROR_CAPTURE_INFO = 1;
static const uint32_t ERROR_CAPTURE_DL0_ERROR_CAPTURE_INFO_LEN = 63;
static const uint32_t ERROR_CAPTURE_DL1_ERROR_CAPTURE_INFO = 1;
static const uint32_t ERROR_CAPTURE_DL1_ERROR_CAPTURE_INFO_LEN = 63;
static const uint32_t P10_20_ERROR_CAPTURE_DL0_ERROR_CAPTURE_INFO = 1; // p10:20,
static const uint32_t P10_20_ERROR_CAPTURE_DL0_ERROR_CAPTURE_INFO_LEN = 7;
static const uint32_t P10_20_ERROR_CAPTURE_DL1_ERROR_CAPTURE_INFO = 1; // p10:20,
static const uint32_t P10_20_ERROR_CAPTURE_DL1_ERROR_CAPTURE_INFO_LEN = 7;
//<< [ERROR_CAPTURE]
// omi/reg00020.H

//>> [RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL]
static const uint64_t RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL = 0x8000304010012c3full;

static const uint32_t RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_GAIN = 48;
static const uint32_t RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_GAIN_LEN = 4;
static const uint32_t RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_PEAK1 = 52;
static const uint32_t RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_PEAK1_LEN = 4;
static const uint32_t RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_PEAK2 = 56;
static const uint32_t RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL_PEAK2_LEN = 4;
//<< [RXPACKS_0_DEFAULT_RD_RX_DAC_REGS_CNTL6_PL]
// omi/reg00020.H

//>> [STATUS]
static const uint64_t STATUS = 0x0c011416ull;

static const uint32_t STATUS_TRAINED_MODE = 0;
static const uint32_t STATUS_TRAINED_MODE_LEN = 4;
static const uint32_t STATUS_RX_LANE_REVERSED = 4;
static const uint32_t STATUS_TX_LANE_REVERSED = 5;
static const uint32_t STATUS_IDLE_SIZE = 6;
static const uint32_t STATUS_ACK_PTRS_EQUAL = 7;
static const uint32_t STATUS_RSVD1 = 8;
static const uint32_t STATUS_RSVD1_LEN = 4;
static const uint32_t STATUS_REQUESTED_LN_WIDTH = 12;
static const uint32_t STATUS_REQUESTED_LN_WIDTH_LEN = 2;
static const uint32_t STATUS_ACTUAL_LN_WIDTH = 14;
static const uint32_t STATUS_ACTUAL_LN_WIDTH_LEN = 2;
static const uint32_t STATUS_TX_TRAINED_LANES = 16;
static const uint32_t STATUS_TX_TRAINED_LANES_LEN = 8;
static const uint32_t STATUS_RX_TRAINED_LANES = 24;
static const uint32_t STATUS_RX_TRAINED_LANES_LEN = 8;
static const uint32_t STATUS_ENDPOINT_INFO = 32;
static const uint32_t STATUS_ENDPOINT_INFO_LEN = 15;
static const uint32_t STATUS_PM_DISABLED = 47;
static const uint32_t STATUS_RSVD2 = 48;
static const uint32_t STATUS_TRAINING_STATE_MACHINE = 49;
static const uint32_t STATUS_TRAINING_STATE_MACHINE_LEN = 3;
static const uint32_t STATUS_RSVD3 = 52;
static const uint32_t STATUS_RSVD3_LEN = 3;
static const uint32_t STATUS_DESKEW_DONE = 55;
static const uint32_t STATUS_LANES_DISABLED = 56;
static const uint32_t STATUS_LANES_DISABLED_LEN = 8;
//<< [STATUS]
// omi/reg00021.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "omi/reg00020.H"
#include "omi/reg00021.H"
#endif
#endif
