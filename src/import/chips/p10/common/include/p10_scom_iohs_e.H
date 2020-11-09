/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_e.H $       */
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

#ifndef __p10_scom_iohs_e_H_
#define __p10_scom_iohs_e_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


//>> [DLP_CONFIG]
static const uint64_t DLP_CONFIG = 0x1801100aull;

static const uint32_t DLP_CONFIG_LINK_PAIR = 0;
static const uint32_t DLP_CONFIG_DISABLE_SL_ECC = 1;
static const uint32_t DLP_CONFIG_DISABLE_RECAL_START = 2;
static const uint32_t DLP_CONFIG_SYN_CAPTURE_SL_ECC = 3;
static const uint32_t DLP_CONFIG_SL_UE_CRC_ERR = 4;
static const uint32_t DLP_CONFIG_REPORT_SL_CHKBIT_ERR = 5;
static const uint32_t DLP_CONFIG_BW_SAMPLE_SIZE = 6;
static const uint32_t DLP_CONFIG_BW_WINDOW_SIZE = 7;
static const uint32_t DLP_CONFIG_PACKET_DELAY_LIMIT = 11;
static const uint32_t DLP_CONFIG_PACKET_DELAY_LIMIT_LEN = 5;
static const uint32_t DLP_CONFIG_TDM_DELAY = 16;
static const uint32_t DLP_CONFIG_TDM_DELAY_LEN = 4;
static const uint32_t DLP_CONFIG_INBOUND_TOD_SELECT = 20;
static const uint32_t DLP_CONFIG_INBOUND_TOD_SELECT_LEN = 2;
static const uint32_t DLP_CONFIG_INBOUND_TOD_CROSS_SELECT = 22;
static const uint32_t DLP_CONFIG_INBOUND_TOD_CROSS_SELECT_LEN = 2;
static const uint32_t DLP_CONFIG_LINK0_OUTBOUND_TOD_SELECT = 24;
static const uint32_t DLP_CONFIG_LINK1_OUTBOUND_TOD_SELECT = 25;
static const uint32_t DLP_CONFIG_RECAL_TIMER = 29;
static const uint32_t DLP_CONFIG_RECAL_TIMER_LEN = 15;
static const uint32_t DLP_CONFIG_PSAVE_TIMEOUT = 44;
static const uint32_t DLP_CONFIG_PSAVE_TIMEOUT_LEN = 4;
static const uint32_t DLP_CONFIG_TIMEOUT = 48;
static const uint32_t DLP_CONFIG_TIMEOUT_LEN = 4;
static const uint32_t DLP_CONFIG_TIMER_1US = 52;
static const uint32_t DLP_CONFIG_TIMER_1US_LEN = 12;
//<< [DLP_CONFIG]
// iohs/reg00062.H

//>> [DLP_LAT_MEASURE]
static const uint64_t DLP_LAT_MEASURE = 0x1801100eull;

static const uint32_t DLP_LAT_MEASURE_LINK0_ROUND_TRIP_VALID = 0;
static const uint32_t DLP_LAT_MEASURE_LINK0_ROUND_TRIP = 2;
static const uint32_t DLP_LAT_MEASURE_LINK0_ROUND_TRIP_LEN = 10;
static const uint32_t DLP_LAT_MEASURE_LINK1_ROUND_TRIP_VALID = 12;
static const uint32_t DLP_LAT_MEASURE_LINK1_ROUND_TRIP = 14;
static const uint32_t DLP_LAT_MEASURE_LINK1_ROUND_TRIP_LEN = 10;
static const uint32_t DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_VALID = 24;
static const uint32_t DLP_LAT_MEASURE_LOCAL_LATENCY_LONGER_LINK = 25;
static const uint32_t DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE = 29;
static const uint32_t DLP_LAT_MEASURE_LOCAL_LATENCY_DIFFERENCE_LEN = 7;
static const uint32_t DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_VALID = 36;
static const uint32_t DLP_LAT_MEASURE_REMOTE_LATENCY_LONGER_LINK = 37;
static const uint32_t DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE = 41;
static const uint32_t DLP_LAT_MEASURE_REMOTE_LATENCY_DIFFERENCE_LEN = 7;
static const uint32_t DLP_LAT_MEASURE_LINK0_TOD_LATENCY = 49;
static const uint32_t DLP_LAT_MEASURE_LINK0_TOD_LATENCY_LEN = 7;
static const uint32_t DLP_LAT_MEASURE_LINK1_TOD_LATENCY = 57;
static const uint32_t DLP_LAT_MEASURE_LINK1_TOD_LATENCY_LEN = 7;
//<< [DLP_LAT_MEASURE]
// iohs/reg00062.H

//>> [DLP_LINK0_QUALITY]
static const uint64_t DLP_LINK0_QUALITY = 0x18011026ull;

static const uint32_t DLP_LINK0_QUALITY_TX_BW = 1;
static const uint32_t DLP_LINK0_QUALITY_TX_BW_LEN = 11;
static const uint32_t DLP_LINK0_QUALITY_RX_BW = 13;
static const uint32_t DLP_LINK0_QUALITY_RX_BW_LEN = 11;
static const uint32_t DLP_LINK0_QUALITY_ERROR_RATE = 25;
static const uint32_t DLP_LINK0_QUALITY_ERROR_RATE_LEN = 23;
static const uint32_t DLP_LINK0_QUALITY_LINK_CAP_SLECC_SYN3 = 48;
static const uint32_t DLP_LINK0_QUALITY_LINK_CAP_SLECC_SYN3_LEN = 8;
static const uint32_t DLP_LINK0_QUALITY_SPARE_COUNTER_2 = 57;
static const uint32_t DLP_LINK0_QUALITY_SPARE_COUNTER_2_LEN = 7;
//<< [DLP_LINK0_QUALITY]
// iohs/reg00062.H

//>> [DLP_PHY_CONFIG]
static const uint64_t DLP_PHY_CONFIG = 0x1801100cull;

static const uint32_t DLP_PHY_CONFIG_PHY_TRAIN_A_ADJ = 0;
static const uint32_t DLP_PHY_CONFIG_PHY_TRAIN_A_ADJ_LEN = 2;
static const uint32_t DLP_PHY_CONFIG_PHY_TRAIN_B_ADJ = 2;
static const uint32_t DLP_PHY_CONFIG_PHY_TRAIN_B_ADJ_LEN = 2;
static const uint32_t DLP_PHY_CONFIG_PHY_TRAIN_TIME = 4;
static const uint32_t DLP_PHY_CONFIG_PHY_TRAIN_TIME_LEN = 4;
static const uint32_t DLP_PHY_CONFIG_PHY_TRAIN_A_HYST = 8;
static const uint32_t DLP_PHY_CONFIG_PHY_TRAIN_A_HYST_LEN = 4;
static const uint32_t DLP_PHY_CONFIG_PHY_TRAIN_B_HYST = 12;
static const uint32_t DLP_PHY_CONFIG_PHY_TRAIN_B_HYST_LEN = 4;
static const uint32_t DLP_PHY_CONFIG_PRBS_PHASE_SELECT = 16;
static const uint32_t DLP_PHY_CONFIG_PRBS_PHASE_SELECT_LEN = 24;
static const uint32_t DLP_PHY_CONFIG_PRBS_CONFIG = 40;
static const uint32_t DLP_PHY_CONFIG_PRBS_CONFIG_LEN = 10;
static const uint32_t DLP_PHY_CONFIG_PRBS_INVERT = 50;
static const uint32_t DLP_PHY_CONFIG_LINK0_SELECT = 56;
static const uint32_t DLP_PHY_CONFIG_LINK1_SELECT = 57;
static const uint32_t DLP_PHY_CONFIG_PRBS15_NPRBS7 = 59;
static const uint32_t DLP_PHY_CONFIG_PRECODER_ENABLE = 60;
static const uint32_t DLP_PHY_CONFIG_50G_MODE = 61;
static const uint32_t DLP_PHY_CONFIG_DL_SELECT = 62;
static const uint32_t DLP_PHY_CONFIG_DL_SELECT_LEN = 2;
//<< [DLP_PHY_CONFIG]
// iohs/reg00062.H

//>> [SLAVE_CONFIG_REG]
static const uint64_t SLAVE_CONFIG_REG = 0x180f001eull;

static const uint32_t SLAVE_CONFIG_REG_DISABLE_PERV_THOLD_CHECK = 0;
static const uint32_t P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_PERV_THOLD_CHECK = 0; // p10:20,
static const uint32_t SLAVE_CONFIG_REG_DISABLE_MALF_PULSE_GEN = 1;
static const uint32_t P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_MALF_PULSE_GEN = 1; // p10:20,
static const uint32_t SLAVE_CONFIG_REG_STOP_HANG_CNT_SYS_XSTP = 2;
static const uint32_t P10_20_SLAVE_CONFIG_REG_CFG_STOP_HANG_CNT_SYS_XSTP = 2; // p10:20,
static const uint32_t SLAVE_CONFIG_REG_DISABLE_CL_ATOMIC_LOCK = 3;
static const uint32_t P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_CL_ATOMIC_LOCK = 3; // p10:20,
static const uint32_t SLAVE_CONFIG_REG_DISABLE_HEARTBEAT = 4;
static const uint32_t P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_HEARTBEAT = 4; // p10:20,
static const uint32_t SLAVE_CONFIG_REG_DISABLE_FORCE_TO_ZERO = 5;
static const uint32_t P10_20_SLAVE_CONFIG_REG_CFG_DISABLE_FORCE_TO_ZERO = 5; // p10:20,
static const uint32_t SLAVE_CONFIG_REG_PM_DISABLE = 6;
static const uint32_t P10_20_SLAVE_CONFIG_REG_CFG_PM_DISABLE = 6; // p10:20,
static const uint32_t SLAVE_CONFIG_REG_PM_MUX_DISABLE = 7;
static const uint32_t P10_20_SLAVE_CONFIG_REG_CFG_PM_MUX_DISABLE = 7; // p10:20,
static const uint32_t SLAVE_CONFIG_REG_MASK_REG_PARITY_ERRS = 8;
static const uint32_t P10_20_SLAVE_CONFIG_REG_CFG_MASK_REG_PARITY_ERRS = 8; // p10:20,
static const uint32_t SLAVE_CONFIG_REG_MASK_PCB_IF_ERRS = 9;
static const uint32_t P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCB_IF_ERRS = 9; // p10:20,
static const uint32_t SLAVE_CONFIG_REG_MASK_HEARTBEAT_ERRS = 10;
static const uint32_t P10_20_SLAVE_CONFIG_REG_CFG_MASK_HEARTBEAT_ERRS = 10; // p10:20,
static const uint32_t SLAVE_CONFIG_REG_MASK_PCBSL_ERRS = 11;
static const uint32_t P10_20_SLAVE_CONFIG_REG_CFG_MASK_PCBSL_ERRS = 11; // p10:20,
static const uint32_t SLAVE_CONFIG_REG_MASK_PLL_ERRS = 12;
static const uint32_t SLAVE_CONFIG_REG_MASK_PLL_ERRS_LEN = 8;
static const uint32_t P10_20_SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS = 12; // p10:20,
static const uint32_t P10_20_SLAVE_CONFIG_REG_CFG_MASK_PLL_ERRS_LEN = 8;
static const uint32_t SLAVE_CONFIG_REG_QME_PAR_DIS = 20;
static const uint32_t P10_20_SLAVE_CONFIG_REG_CFG_QME_PAR_DIS = 20; // p10:20,
static const uint32_t SLAVE_CONFIG_REG_FORCE_0_QME = 21;
static const uint32_t P10_20_SLAVE_CONFIG_REG_CFG_FORCE_0_QME = 21; // p10:20,
static const uint32_t P10_20_SLAVE_CONFIG_REG_MASK_QME_RISING_EDGE_DETECTED_ON_QUIESCE = 22; // p10:20,
static const uint32_t P10_20_SLAVE_CONFIG_REG_MASK_QME_INTR_RISING_EDGE_DETECTED_ON_QUIESCE = 23; // p10:20,
//<< [SLAVE_CONFIG_REG]
// iohs/reg00066.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "iohs/reg00062.H"
#include "iohs/reg00063.H"
#include "iohs/reg00064.H"
#include "iohs/reg00065.H"
#include "iohs/reg00066.H"
#endif
#endif
