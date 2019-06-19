/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omic_f.H $       */
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

#ifndef __p10_scom_omic_f_H_
#define __p10_scom_omic_f_H_


namespace scomt
{
namespace omic
{


static const uint64_t CTL_REGS_RX_CNTL2_PG = 0x8009084010012c3full;

static const uint32_t CTL_REGS_RX_CNTL2_PG_AMP_SERVO_RESTORE_DAC = 48;
static const uint32_t CTL_REGS_RX_CNTL2_PG_LOFF_SERVO_RESTORE_DAC = 49;
static const uint32_t CTL_REGS_RX_CNTL2_PG_SERVO_DISABLE_RESULT = 50;
static const uint32_t CTL_REGS_RX_CNTL2_PG_CAL_LANE_PG_PHY_GCRMSG = 51;
static const uint32_t CTL_REGS_RX_CNTL2_PG_CAL_LANE_PG_PHY_GCRMSG_LEN = 5;
static const uint32_t CTL_REGS_RX_CNTL2_PG_AMP_SERVO_MASK_H0 = 56;
static const uint32_t CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_INC = 57;
static const uint32_t CTL_REGS_RX_CNTL2_PG_AMP_SERVO_VOTE_BIAS_DEC = 58;
// omic/reg00015.H

static const uint64_t CTL_REGS_RX_MODE11_PG = 0x8008584010012c3full;

static const uint32_t CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN = 48;
static const uint32_t CTL_REGS_RX_MODE11_PG_AMP_START_VAL = 49;
static const uint32_t CTL_REGS_RX_MODE11_PG_AMP_START_VAL_LEN = 9;
// omic/reg00015.H

static const uint64_t CTL_REGS_RX_MODE21_PG = 0x8008a84010012c3full;

static const uint32_t CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN = 48;
static const uint32_t CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN_LEN = 4;
// omic/reg00015.H

static const uint64_t CTL_REGS_RX_MODE4_PG = 0x8008204010012c3full;

static const uint32_t CTL_REGS_RX_MODE4_PG_INC0 = 48;
static const uint32_t CTL_REGS_RX_MODE4_PG_INC0_LEN = 4;
static const uint32_t CTL_REGS_RX_MODE4_PG_DEC0 = 52;
static const uint32_t CTL_REGS_RX_MODE4_PG_DEC0_LEN = 4;
static const uint32_t CTL_REGS_RX_MODE4_PG_INC1 = 56;
static const uint32_t CTL_REGS_RX_MODE4_PG_INC1_LEN = 4;
static const uint32_t CTL_REGS_RX_MODE4_PG_DEC1 = 60;
static const uint32_t CTL_REGS_RX_MODE4_PG_DEC1_LEN = 4;
// omic/reg00015.H

static const uint64_t CTL_REGS_RX_SPARE_MODE_PG = 0x8008004010012c3full;

static const uint32_t CTL_REGS_RX_SPARE_MODE_PG_0 = 48;
static const uint32_t CTL_REGS_RX_SPARE_MODE_PG_1 = 49;
static const uint32_t CTL_REGS_RX_SPARE_MODE_PG_2 = 50;
static const uint32_t CTL_REGS_RX_SPARE_MODE_PG_3 = 51;
static const uint32_t CTL_REGS_RX_SPARE_MODE_PG_4 = 52;
// omic/reg00015.H

static const uint64_t CTL_REGS_TX_CNTL3_PG = 0x800c544010012c3full;

static const uint32_t CTL_REGS_TX_CNTL3_PG_FINE_SEL = 48;
static const uint32_t CTL_REGS_TX_CNTL3_PG_FINE_SEL_LEN = 3;
static const uint32_t CTL_REGS_TX_CNTL3_PG_COARSE_SEL = 51;
static const uint32_t CTL_REGS_TX_CNTL3_PG_COARSE_SEL_LEN = 4;
static const uint32_t CTL_REGS_TX_CNTL3_PG_BER_SEL = 55;
static const uint32_t CTL_REGS_TX_CNTL3_PG_BER_SEL_LEN = 6;
// omic/reg00015.H

static const uint64_t DATASM_REGS_RX_CNT13_PG = 0x8009e84010012c3full;

static const uint32_t DATASM_REGS_RX_CNT13_PG_DISABLE_SM = 48;
static const uint32_t DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT = 49;
static const uint32_t DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD = 50;
// omic/reg00015.H

static const uint64_t DATASM_REGS_RX_CNT23_PG = 0x800a384010012c3full;

static const uint32_t DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15 = 48;
static const uint32_t DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15_LEN = 16;
// omic/reg00015.H

static const uint64_t DATASM_REGS_RX_CNT33_PG = 0x800a884010012c3full;

static const uint32_t DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1 = 48;
static const uint32_t DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1_LEN = 8;
// omic/reg00015.H

static const uint64_t DATASM_REGS_RX_SPARE_MODE_PG = 0x8009804010012c3full;

static const uint32_t DATASM_REGS_RX_SPARE_MODE_PG_0 = 48;
static const uint32_t DATASM_REGS_RX_SPARE_MODE_PG_1 = 49;
static const uint32_t DATASM_REGS_RX_SPARE_MODE_PG_2 = 50;
static const uint32_t DATASM_REGS_RX_SPARE_MODE_PG_3 = 51;
static const uint32_t DATASM_REGS_RX_SPARE_MODE_PG_4 = 52;
static const uint32_t DATASM_REGS_RX_SPARE_MODE_PG_5 = 53;
static const uint32_t DATASM_REGS_RX_SPARE_MODE_PG_6 = 54;
static const uint32_t DATASM_REGS_RX_SPARE_MODE_PG_7 = 55;
// omic/reg00015.H

static const uint64_t MC_OMI_FIR_REG_RW = 0x0c011740ull;
static const uint64_t MC_OMI_FIR_REG_WO_AND = 0x0c011741ull;
static const uint64_t MC_OMI_FIR_REG_WO_OR = 0x0c011742ull;

static const uint32_t MC_OMI_FIR_REG_DL0_FATAL_ERROR = 0;
static const uint32_t MC_OMI_FIR_REG_DL0_DATA_UE = 1;
static const uint32_t MC_OMI_FIR_REG_DL0_FLIT_CE = 2;
static const uint32_t MC_OMI_FIR_REG_DL0_CRC_ERROR = 3;
static const uint32_t MC_OMI_FIR_REG_DL0_NACK = 4;
static const uint32_t MC_OMI_FIR_REG_DL0_X4_MODE = 5;
static const uint32_t MC_OMI_FIR_REG_DL0_EDPL = 6;
static const uint32_t MC_OMI_FIR_REG_DL0_TIMEOUT = 7;
static const uint32_t MC_OMI_FIR_REG_DL0_REMOTE_RETRAIN = 8;
static const uint32_t MC_OMI_FIR_REG_DL0_ERROR_RETRAIN = 9;
static const uint32_t MC_OMI_FIR_REG_DL0_EDPL_RETRAIN = 10;
static const uint32_t MC_OMI_FIR_REG_DL0_TRAINED = 11;
static const uint32_t MC_OMI_FIR_REG_DL0_ENDPOINT_FIR0 = 12;
static const uint32_t MC_OMI_FIR_REG_DL0_ENDPOINT_FIR1 = 13;
static const uint32_t MC_OMI_FIR_REG_DL0_ENDPOINT_FIR2 = 14;
static const uint32_t MC_OMI_FIR_REG_DL0_ENDPOINT_FIR3 = 15;
static const uint32_t MC_OMI_FIR_REG_DL0_ENDPOINT_FIR4 = 16;
static const uint32_t MC_OMI_FIR_REG_DL0_ENDPOINT_FIR5 = 17;
static const uint32_t MC_OMI_FIR_REG_DL0_ENDPOINT_FIR6 = 18;
static const uint32_t MC_OMI_FIR_REG_DL0_ENDPOINT_FIR7 = 19;
static const uint32_t MC_OMI_FIR_REG_DL1_FATAL_ERROR = 20;
static const uint32_t MC_OMI_FIR_REG_DL1_DATA_UE = 21;
static const uint32_t MC_OMI_FIR_REG_DL1_FLIT_CE = 22;
static const uint32_t MC_OMI_FIR_REG_DL1_CRC_ERROR = 23;
static const uint32_t MC_OMI_FIR_REG_DL1_NACK = 24;
static const uint32_t MC_OMI_FIR_REG_DL1_X4_MODE = 25;
static const uint32_t MC_OMI_FIR_REG_DL1_EDPL = 26;
static const uint32_t MC_OMI_FIR_REG_DL1_TIMEOUT = 27;
static const uint32_t MC_OMI_FIR_REG_DL1_REMOTE_RETRAIN = 28;
static const uint32_t MC_OMI_FIR_REG_DL1_ERROR_RETRAIN = 29;
static const uint32_t MC_OMI_FIR_REG_DL1_EDPL_RETRAIN = 30;
static const uint32_t MC_OMI_FIR_REG_DL1_TRAINED = 31;
static const uint32_t MC_OMI_FIR_REG_DL1_ENDPOINT_FIR0 = 32;
static const uint32_t MC_OMI_FIR_REG_DL1_ENDPOINT_FIR1 = 33;
static const uint32_t MC_OMI_FIR_REG_DL1_ENDPOINT_FIR2 = 34;
static const uint32_t MC_OMI_FIR_REG_DL1_ENDPOINT_FIR3 = 35;
static const uint32_t MC_OMI_FIR_REG_DL1_ENDPOINT_FIR4 = 36;
static const uint32_t MC_OMI_FIR_REG_DL1_ENDPOINT_FIR5 = 37;
static const uint32_t MC_OMI_FIR_REG_DL1_ENDPOINT_FIR6 = 38;
static const uint32_t MC_OMI_FIR_REG_DL1_ENDPOINT_FIR7 = 39;
static const uint32_t MC_OMI_FIR_REG_PERF_MON_WRAPPED = 60;
// omic/reg00015.H

static const uint64_t TX_CTL_SM_REGS_CTLSM_CNTL12_PG = 0x800d1c4010012c3full;

static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL12_PG_SUBSET6 = 48;
static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL12_PG_SUBSET6_LEN = 6;
static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL12_PG_DISABLE_SM = 54;
static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIME = 55;
static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIME_LEN = 6;
static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL12_PG_TIMER_DOUBLE_MODE = 61;
// omic/reg00015.H

static const uint64_t TX_CTL_SM_REGS_CTLSM_CNTL2_PG = 0x800ccc4010012c3full;

static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL2_PG_TX_PSAVE_FENCE_REQ_DL_IO_16_23 = 48;
static const uint32_t TX_CTL_SM_REGS_CTLSM_CNTL2_PG_TX_PSAVE_FENCE_REQ_DL_IO_16_23_LEN = 8;
// omic/reg00015.H

static const uint64_t TX_CTL_SM_REGS_CTLSM_STAT2_PG = 0x800d4c4010012c3full;
// omic/reg00015.H

static const uint64_t TX_CTL_SM_REGS_FIR_ERROR_INJECT_PG = 0x800c9c4010012c3full;

static const uint32_t TX_CTL_SM_REGS_FIR_ERROR_INJECT_PG_TX_PG_FIR_ERR_INJ = 48;
static const uint32_t TX_CTL_SM_REGS_FIR_ERROR_INJECT_PG_TX_PG_FIR_ERR_INJ_LEN = 4;
// omic/reg00015.H

}
}
#ifndef __PPE_HCODE__
    #include "omic/reg00015.H"
#endif
#endif
