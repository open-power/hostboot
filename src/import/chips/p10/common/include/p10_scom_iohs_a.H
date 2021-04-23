/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_a.H $       */
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

#ifndef __p10_scom_iohs_a_H_
#define __p10_scom_iohs_a_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


//>> [DLP_LINK0_TX_LANE_CONTROL]
static const uint64_t DLP_LINK0_TX_LANE_CONTROL = 0x18011010ull;

static const uint32_t DLP_LINK0_TX_LANE_CONTROL_00_CONTROL = 0;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_00_CONTROL_LEN = 4;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_01_CONTROL = 4;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_01_CONTROL_LEN = 4;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_02_CONTROL = 8;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_02_CONTROL_LEN = 4;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_03_CONTROL = 12;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_03_CONTROL_LEN = 4;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_04_CONTROL = 16;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_04_CONTROL_LEN = 4;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_05_CONTROL = 20;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_05_CONTROL_LEN = 4;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_06_CONTROL = 24;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_06_CONTROL_LEN = 4;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_07_CONTROL = 28;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_07_CONTROL_LEN = 4;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_SP_CONTROL = 32;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_SP_CONTROL_LEN = 4;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_FAILED = 48;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_FAILED_LEN = 9;
//<< [DLP_LINK0_TX_LANE_CONTROL]
// iohs/reg00044.H

//>> [IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL]
static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL = 0x8000200010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_GAIN = 48;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_GAIN_LEN = 3;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_ZERO = 51;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL_ZERO_LEN = 3;
//<< [IOO_RX0_0_RD_RX_DAC_REGS_CNTL4_PL]
// iohs/reg00044.H

//>> [IOO_RX0_RXCTL_DATASM_0_PLREGS_RX_STAT1_PL]
static const uint64_t IOO_RX0_RXCTL_DATASM_0_PLREGS_RX_STAT1_PL = 0x8003e00010012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_0_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_0_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL = 49;
static const uint32_t IOO_RX0_RXCTL_DATASM_0_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL = 50;
static const uint32_t IOO_RX0_RXCTL_DATASM_0_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL = 51;
static const uint32_t IOO_RX0_RXCTL_DATASM_0_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL = 52;
static const uint32_t IOO_RX0_RXCTL_DATASM_0_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL = 53;
//<< [IOO_RX0_RXCTL_DATASM_0_PLREGS_RX_STAT1_PL]
// iohs/reg00046.H

//>> [IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG]
static const uint64_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG = 0x800c5c0010012c3full;

static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_DAC_CNTL = 48;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_DAC_CNTL_LEN = 8;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_CLAMP_DISABLE = 56;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG_PHASE_SEL = 57;
//<< [IOO_TX0_TXCTL_CTL_REGS_TX_CNTL4_PG]
// iohs/reg00047.H

//>> [P10_20_CONFIG]
static const uint64_t CONFIG = 0x1801102bull; // p10:20,

static const uint32_t P10_20_CONFIG_RESET = 0;
static const uint32_t P10_20_CONFIG_RETRAIN = 1;
static const uint32_t P10_20_CONFIG_VERSION = 2;
static const uint32_t P10_20_CONFIG_VERSION_LEN = 6;
static const uint32_t P10_20_CONFIG_TRAIN_MODE = 8;
static const uint32_t P10_20_CONFIG_TRAIN_MODE_LEN = 4;
static const uint32_t P10_20_CONFIG_SUPPORTED_MODES = 12;
static const uint32_t P10_20_CONFIG_SUPPORTED_MODES_LEN = 4;
static const uint32_t P10_20_CONFIG_X4_BACKOFF_ENABLE = 16;
static const uint32_t P10_20_CONFIG_X1_BACKOFF_ENABLE = 17;
static const uint32_t P10_20_CONFIG_PWRMGT_ENABLE = 18;
static const uint32_t P10_20_CONFIG_TX_EP_MODE = 19;
static const uint32_t P10_20_CONFIG_PHY_CNTR_LIMIT = 20;
static const uint32_t P10_20_CONFIG_PHY_CNTR_LIMIT_LEN = 4;
static const uint32_t P10_20_CONFIG_128_130_ENCODING_ENABLED = 24;
static const uint32_t P10_20_CONFIG_TRAINING_STATUS_REGISTER_SELECT = 25;
static const uint32_t P10_20_CONFIG_CRC_TX_INJECTION = 27;
static const uint32_t P10_20_CONFIG_ECC_CE_INJECTION = 28;
static const uint32_t P10_20_CONFIG_ECC_UE_INJECTION = 29;
static const uint32_t P10_20_CONFIG_DL2TL_CONTROL_PARITY_INJECT = 30;
static const uint32_t P10_20_CONFIG_DL2TL_DATA_PARITY_INJECT = 31;
static const uint32_t P10_20_CONFIG_DEBUG_ENABLE = 33;
static const uint32_t P10_20_CONFIG_DEBUG_SELECT = 34;
static const uint32_t P10_20_CONFIG_DEBUG_SELECT_LEN = 2;
static const uint32_t P10_20_CONFIG_REPLAY_RSVD_ENTRIES = 36;
static const uint32_t P10_20_CONFIG_REPLAY_RSVD_ENTRIES_LEN = 4;
static const uint32_t P10_20_CONFIG_FWD_PROGRESS_TIMER = 40;
static const uint32_t P10_20_CONFIG_FWD_PROGRESS_TIMER_LEN = 4;
static const uint32_t P10_20_CONFIG_TLERROR_LINKDOWN = 44;
static const uint32_t P10_20_CONFIG_TLERROR_ILATRIG = 45;
static const uint32_t P10_20_CONFIG_TLERROR_AFUFREEZE = 46;
static const uint32_t P10_20_CONFIG_TLERROR_ALLFREEZE = 47;
static const uint32_t P10_20_CONFIG_TLEVENT_LINKDOWN = 48;
static const uint32_t P10_20_CONFIG_TLEVENT_ILATRIG = 49;
static const uint32_t P10_20_CONFIG_TLEVENT_AFUFREEZE = 50;
static const uint32_t P10_20_CONFIG_TLEVENT_ALLFREEZE = 51;
static const uint32_t P10_20_CONFIG_CFG_SPARE = 52;
static const uint32_t P10_20_CONFIG_CFG_SPARE_LEN = 12;
//<< [P10_20_CONFIG]
// iohs/reg00044.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "iohs/reg00044.H"
#include "iohs/reg00045.H"
#include "iohs/reg00046.H"
#include "iohs/reg00047.H"
#endif
#endif
