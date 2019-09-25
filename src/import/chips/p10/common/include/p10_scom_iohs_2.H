/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_2.H $       */
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

#ifndef __p10_scom_iohs_2_H_
#define __p10_scom_iohs_2_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


static const uint64_t AXON_CPLT_CTRL2_RW = 0x18000002ull;
static const uint64_t AXON_CPLT_CTRL2_WO_CLEAR = 0x18000022ull;
static const uint64_t AXON_CPLT_CTRL2_WO_OR = 0x18000012ull;

static const uint32_t AXON_CPLT_CTRL2_0_PGOOD = 4;
static const uint32_t AXON_CPLT_CTRL2_1_PGOOD = 5;
static const uint32_t AXON_CPLT_CTRL2_2_PGOOD = 6;
static const uint32_t AXON_CPLT_CTRL2_3_PGOOD = 7;
static const uint32_t AXON_CPLT_CTRL2_4_PGOOD = 8;
static const uint32_t AXON_CPLT_CTRL2_5_PGOOD = 9;
static const uint32_t AXON_CPLT_CTRL2_6_PGOOD = 10;
static const uint32_t AXON_CPLT_CTRL2_7_PGOOD = 11;
static const uint32_t AXON_CPLT_CTRL2_8_PGOOD = 12;
static const uint32_t AXON_CPLT_CTRL2_9_PGOOD = 13;
static const uint32_t AXON_CPLT_CTRL2_10_PGOOD = 14;
static const uint32_t AXON_CPLT_CTRL2_11_PGOOD = 15;
static const uint32_t AXON_CPLT_CTRL2_12_PGOOD = 16;
static const uint32_t AXON_CPLT_CTRL2_13_PGOOD = 17;
static const uint32_t AXON_CPLT_CTRL2_14_PGOOD = 18;
// iohs/reg00008.H

static const uint64_t AXON_CPLT_MASK0 = 0x18000101ull;

static const uint32_t AXON_CPLT_MASK0_ITR_MASK = 0;
static const uint32_t AXON_CPLT_MASK0_ITR_MASK_LEN = 32;
// iohs/reg00008.H

static const uint64_t AXON_CTRL_PROTECT_MODE_REG = 0x180003feull;

static const uint32_t AXON_CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE = 0;
static const uint32_t AXON_CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE = 1;
// iohs/reg00008.H

static const uint64_t AXON_EPS_FIR_LOCAL_MASK_RW = 0x18040103ull;
static const uint64_t AXON_EPS_FIR_LOCAL_MASK_WO_AND = 0x18040104ull;
static const uint64_t AXON_EPS_FIR_LOCAL_MASK_WO_OR = 0x18040105ull;

static const uint32_t AXON_EPS_FIR_LOCAL_MASK_00 = 0;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_01 = 1;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_02 = 2;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_03 = 3;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_04 = 4;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_05 = 5;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_06 = 6;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_07 = 7;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_08 = 8;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_09 = 9;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_10 = 10;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_11 = 11;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_12 = 12;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_13 = 13;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_14 = 14;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_15 = 15;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_16 = 16;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_17 = 17;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_18 = 18;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_19 = 19;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_20 = 20;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_21 = 21;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_22 = 22;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_23 = 23;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_24 = 24;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_25 = 25;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_26 = 26;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_27 = 27;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_28 = 28;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_29 = 29;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_30 = 30;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_31 = 31;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_32 = 32;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_33 = 33;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_34 = 34;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_35 = 35;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_36 = 36;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_37 = 37;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_38 = 38;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_39 = 39;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_40 = 40;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_41 = 41;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_42 = 42;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_43 = 43;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_44 = 44;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_45 = 45;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_46 = 46;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_47 = 47;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_48 = 48;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_49 = 49;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_50 = 50;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_51 = 51;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_52 = 52;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_53 = 53;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_54 = 54;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_55 = 55;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_56 = 56;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_57 = 57;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_58 = 58;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_59 = 59;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_60 = 60;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_61 = 61;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_62 = 62;
static const uint32_t AXON_EPS_FIR_LOCAL_MASK_63 = 63;
// iohs/reg00008.H

static const uint64_t AXON_EPS_THERM_WSUB_SKITTER_DATA1 = 0x1805001aull;
// iohs/reg00008.H

static const uint64_t AXON_LOCAL_FIR_RW = 0x18040100ull;
static const uint64_t AXON_LOCAL_FIR_WO_AND = 0x18040101ull;
static const uint64_t AXON_LOCAL_FIR_WO_OR = 0x18040102ull;

static const uint32_t AXON_LOCAL_FIR_CFIR = 0;
static const uint32_t AXON_LOCAL_FIR_CPLT_CTRL = 1;
static const uint32_t AXON_LOCAL_FIR_CC_PCB = 2;
static const uint32_t AXON_LOCAL_FIR_CC_OTHERS = 3;
static const uint32_t AXON_LOCAL_FIR_IN04 = 4;
static const uint32_t AXON_LOCAL_FIR_IN05 = 5;
static const uint32_t AXON_LOCAL_FIR_IN06 = 6;
static const uint32_t AXON_LOCAL_FIR_IN07 = 7;
static const uint32_t AXON_LOCAL_FIR_IN08 = 8;
static const uint32_t AXON_LOCAL_FIR_IN09 = 9;
static const uint32_t AXON_LOCAL_FIR_IN10 = 10;
static const uint32_t AXON_LOCAL_FIR_IN11 = 11;
static const uint32_t AXON_LOCAL_FIR_IN12 = 12;
static const uint32_t AXON_LOCAL_FIR_IN13 = 13;
static const uint32_t AXON_LOCAL_FIR_IN14 = 14;
static const uint32_t AXON_LOCAL_FIR_IN15 = 15;
static const uint32_t AXON_LOCAL_FIR_IN16 = 16;
static const uint32_t AXON_LOCAL_FIR_IN17 = 17;
static const uint32_t AXON_LOCAL_FIR_IN18 = 18;
static const uint32_t AXON_LOCAL_FIR_IN19 = 19;
static const uint32_t AXON_LOCAL_FIR_IN20 = 20;
static const uint32_t AXON_LOCAL_FIR_IN21 = 21;
static const uint32_t AXON_LOCAL_FIR_IN22 = 22;
static const uint32_t AXON_LOCAL_FIR_IN23 = 23;
static const uint32_t AXON_LOCAL_FIR_IN24 = 24;
static const uint32_t AXON_LOCAL_FIR_IN25 = 25;
static const uint32_t AXON_LOCAL_FIR_IN26 = 26;
static const uint32_t AXON_LOCAL_FIR_IN27 = 27;
static const uint32_t AXON_LOCAL_FIR_IN28 = 28;
static const uint32_t AXON_LOCAL_FIR_IN29 = 29;
static const uint32_t AXON_LOCAL_FIR_IN30 = 30;
static const uint32_t AXON_LOCAL_FIR_IN31 = 31;
static const uint32_t AXON_LOCAL_FIR_IN32 = 32;
static const uint32_t AXON_LOCAL_FIR_IN33 = 33;
static const uint32_t AXON_LOCAL_FIR_IN34 = 34;
static const uint32_t AXON_LOCAL_FIR_IN35 = 35;
static const uint32_t AXON_LOCAL_FIR_IN36 = 36;
static const uint32_t AXON_LOCAL_FIR_IN37 = 37;
static const uint32_t AXON_LOCAL_FIR_IN38 = 38;
static const uint32_t AXON_LOCAL_FIR_IN39 = 39;
static const uint32_t AXON_LOCAL_FIR_IN40 = 40;
static const uint32_t AXON_LOCAL_FIR_IN41 = 41;
static const uint32_t AXON_LOCAL_FIR_IN42 = 42;
static const uint32_t AXON_LOCAL_FIR_IN43 = 43;
static const uint32_t AXON_LOCAL_FIR_IN44 = 44;
static const uint32_t AXON_LOCAL_FIR_IN45 = 45;
static const uint32_t AXON_LOCAL_FIR_IN46 = 46;
static const uint32_t AXON_LOCAL_FIR_IN47 = 47;
static const uint32_t AXON_LOCAL_FIR_IN48 = 48;
static const uint32_t AXON_LOCAL_FIR_IN49 = 49;
static const uint32_t AXON_LOCAL_FIR_IN50 = 50;
static const uint32_t AXON_LOCAL_FIR_IN51 = 51;
static const uint32_t AXON_LOCAL_FIR_IN52 = 52;
static const uint32_t AXON_LOCAL_FIR_IN53 = 53;
static const uint32_t AXON_LOCAL_FIR_IN54 = 54;
static const uint32_t AXON_LOCAL_FIR_IN55 = 55;
static const uint32_t AXON_LOCAL_FIR_IN56 = 56;
static const uint32_t AXON_LOCAL_FIR_IN57 = 57;
static const uint32_t AXON_LOCAL_FIR_IN58 = 58;
static const uint32_t AXON_LOCAL_FIR_IN59 = 59;
static const uint32_t AXON_LOCAL_FIR_IN60 = 60;
static const uint32_t AXON_LOCAL_FIR_IN61 = 61;
static const uint32_t AXON_LOCAL_FIR_IN62 = 62;
static const uint32_t AXON_LOCAL_FIR_EXT_LOCAL_XSTOP = 63;
// iohs/reg00008.H

static const uint64_t AXON_LOCAL_XSTOP_UNMASKED = 0x18040013ull;

static const uint32_t AXON_LOCAL_XSTOP_UNMASKED_LOCAL_XSTOP_UNMASKED_IN = 1;
static const uint32_t AXON_LOCAL_XSTOP_UNMASKED_LOCAL_XSTOP_UNMASKED_IN_LEN = 15;
// iohs/reg00008.H

static const uint64_t DLP_FIR_ACTION0_REG = 0x18011006ull;

static const uint32_t DLP_FIR_ACTION0_REG_DLP_FIR_ACTION0 = 0;
static const uint32_t DLP_FIR_ACTION0_REG_DLP_FIR_ACTION0_LEN = 62;
// iohs/reg00008.H

static const uint64_t DLP_FIR_ACTION1_REG = 0x18011007ull;

static const uint32_t DLP_FIR_ACTION1_REG_DLP_FIR_ACTION1 = 0;
static const uint32_t DLP_FIR_ACTION1_REG_DLP_FIR_ACTION1_LEN = 62;
// iohs/reg00008.H

static const uint64_t DLP_PERF_COUNTERS_0 = 0x1801101eull;

static const uint32_t DLP_PERF_COUNTERS_0_0 = 0;
static const uint32_t DLP_PERF_COUNTERS_0_0_LEN = 16;
static const uint32_t DLP_PERF_COUNTERS_0_1 = 16;
static const uint32_t DLP_PERF_COUNTERS_0_1_LEN = 16;
static const uint32_t DLP_PERF_COUNTERS_0_2 = 32;
static const uint32_t DLP_PERF_COUNTERS_0_2_LEN = 16;
static const uint32_t DLP_PERF_COUNTERS_0_3 = 48;
static const uint32_t DLP_PERF_COUNTERS_0_3_LEN = 16;
// iohs/reg00008.H

static const uint64_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE11_PG = 0x8008580010012c3full;

static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE11_PG_CTL_DATASM_CLKDIST_PDWN = 48;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE11_PG_AMP_START_VAL = 49;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE11_PG_AMP_START_VAL_LEN = 8;
// iohs/reg00008.H

static const uint64_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE21_PG = 0x8008a80010012c3full;

static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN = 48;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE21_PG_RX_SERVO_STATUS_ERROR_EN_LEN = 4;
// iohs/reg00008.H

static const uint64_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE2_PG = 0x8008100010012c3full;

static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_ENABLE = 48;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_PIPE_SKIP_COUNT = 49;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_PIPE_SKIP_COUNT_LEN = 4;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_SAMPLE_MASK = 53;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE2_PG_SCOPE_MODE_SAMPLE_MASK_LEN = 7;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE2_PG_DATA_PIPE_CLR_ON_READ_MODE = 60;
// iohs/reg00008.H

static const uint64_t IOO_RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG = 0x8008000010012c3full;

static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_0 = 48;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_1 = 49;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_2 = 50;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_3 = 51;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_SPARE_MODE_PG_4 = 52;
// iohs/reg00008.H

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT13_PG = 0x8009e80010012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_DISABLE_SM = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_SYNC_MAIN_ALT = 49;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT13_PG_CDR_LOCK_OVRD = 50;
// iohs/reg00008.H

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT23_PG = 0x800a380010012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15 = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT23_PG_RX_A_LANE_FAIL_0_15_LEN = 16;
// iohs/reg00008.H

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT33_PG = 0x800a880010012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1 = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1_LEN = 8;
// iohs/reg00008.H

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_STAT15_PG = 0x800b000010012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_STAT15_PG_RX_AMP_HYST_MIN_RO_SIGNAL = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_STAT15_PG_RX_AMP_HYST_MIN_RO_SIGNAL_LEN = 8;
// iohs/reg00008.H

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_STAT25_PG = 0x800b500010012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_STAT25_PG_RX_PSAVE_REQ_DL_16_23_STS_RO_SIGNAL = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_STAT25_PG_RX_PSAVE_REQ_DL_16_23_STS_RO_SIGNAL_LEN = 8;
// iohs/reg00008.H

static const uint64_t IOO_RX0_RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL = 0x8003c00d10012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL_INIT_DONE = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_13_PLREGS_RX_CNTL1_PL_RECAL_DONE = 49;
// iohs/reg00008.H

static const uint64_t IOO_RX0_RXCTL_DATASM_13_PLREGS_RX_STAT1_PL = 0x8003e00d10012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_13_PLREGS_RX_STAT1_PL_DL_PHY_RUN_LANE_RO_SIGNAL = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_13_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_REQ_RO_SIGNAL = 49;
static const uint32_t IOO_RX0_RXCTL_DATASM_13_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_RO_SIGNAL = 50;
static const uint32_t IOO_RX0_RXCTL_DATASM_13_PLREGS_RX_STAT1_PL_DL_PHY_RECAL_ABORT_STICKY_RO_SIGNAL = 51;
static const uint32_t IOO_RX0_RXCTL_DATASM_13_PLREGS_RX_STAT1_PL_PSAVE_REQ_DL_RO_SIGNAL = 52;
static const uint32_t IOO_RX0_RXCTL_DATASM_13_PLREGS_RX_STAT1_PL_PSAVE_STS_PHY_RO_SIGNAL = 53;
// iohs/reg00008.H

static const uint64_t IOO_RX0_RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL = 0x8003d80310012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL_REQ_ALT = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_3_PLREGS_RX_CNTL3_PL_STS_ALT = 49;
// iohs/reg00008.H

static const uint64_t IOO_RX0_RXCTL_DATASM_5_PLREGS_RX_MODE1_PL = 0x8003d00510012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK = 49;
static const uint32_t IOO_RX0_RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK = 50;
static const uint32_t IOO_RX0_RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK = 51;
static const uint32_t IOO_RX0_RXCTL_DATASM_5_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK = 52;
// iohs/reg00008.H

static const uint64_t IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL2_PL = 0x8003c80710012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_SET_WO_PULSE_SLOW_SIGNAL = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL2_PL_PHY_DL_INIT_DONE_CLR_WO_PULSE_SLOW_SIGNAL = 49;
static const uint32_t IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_SET_WO_PULSE_SLOW_SIGNAL = 50;
static const uint32_t IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL2_PL_PHY_DL_RECAL_DONE_CLR_WO_PULSE_SLOW_SIGNAL = 51;
static const uint32_t IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL2_PL_DL_PHY_RECAL_ABORT_STICKY_CLR_WO_PULSE_SLOW_SIGNAL = 52;
// iohs/reg00008.H

static const uint64_t IOO_RX0_0_RD_RX_BIT_REGS_MODE6_PL = 0x8003480010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_MODE6_PL_TIME_VAL = 48;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN = 13;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE = 62;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_MODE6_PL_DISABLE_SM = 63;
// iohs/reg00008.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX28_PL = 0x8000e00010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001 = 56;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001_LEN = 8;
// iohs/reg00008.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX38_PL = 0x8001300010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011 = 56;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011_LEN = 8;
// iohs/reg00008.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX48_PL = 0x8001800010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101 = 56;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101_LEN = 8;
// iohs/reg00008.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX58_PL = 0x8001d00010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111 = 56;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111_LEN = 8;
// iohs/reg00008.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX24_PL = 0x8000c00010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E = 56;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E_LEN = 8;
// iohs/reg00008.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX64_PL = 0x8002000010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101 = 56;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101_LEN = 8;
// iohs/reg00008.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX74_PL = 0x8002500010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111 = 56;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111_LEN = 8;
// iohs/reg00008.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL16_PL = 0x8000800010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL16_PL_DATA = 48;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL16_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL16_PL_EDGE = 54;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL16_PL_EDGE_LEN = 5;
// iohs/reg00008.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL8_PL = 0x8000400010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL8_PL_CLK_PHASE_SELECT = 48;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL8_PL_CLK_PHASE_SELECT_LEN = 2;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL8_PL_DPR_VBN_CAL = 50;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL8_PL_DPR_VBN_CAL_LEN = 2;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL8_PL_OFF_DISABLE_DM_B = 52;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL8_PL_CTLE_CONFIG_DC = 53;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL8_PL_CTLE_CONFIG_DC_LEN = 3;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL8_PL_VDAC_CONFIG_DC = 56;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL8_PL_VDAC_CONFIG_DC_LEN = 2;
// iohs/reg00008.H

static const uint64_t IOO_RX0_0_RD_1_RX_BIT_REGS_SPARE_MODE_PL = 0x8003000110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_SPARE_MODE_PL_0 = 48;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_SPARE_MODE_PL_1 = 49;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_SPARE_MODE_PL_2 = 50;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_SPARE_MODE_PL_3 = 51;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_SPARE_MODE_PL_4 = 52;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_SPARE_MODE_PL_5 = 53;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_SPARE_MODE_PL_6 = 54;
static const uint32_t IOO_RX0_0_RD_1_RX_BIT_REGS_SPARE_MODE_PL_7 = 55;
// iohs/reg00008.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX33_PL = 0x8001080110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110 = 56;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110_LEN = 8;
// iohs/reg00008.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX43_PL = 0x8001580110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000 = 56;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000_LEN = 8;
// iohs/reg00008.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX53_PL = 0x8001a80110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010 = 56;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010_LEN = 8;
// iohs/reg00008.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX84_PL = 0x8002a00110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001 = 56;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001_LEN = 8;
// iohs/reg00008.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL10_PL = 0x8000500110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL10_PL_IF_BLEED_CMFB = 48;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL10_PL_IF_EXT_BIAS = 49;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL10_PL_IF_LPF_500M = 50;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL10_PL_SIGDET_PD = 51;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL10_PL_A_CLKSLIP = 52;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL10_PL_B_CLKSLIP = 53;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL10_PL_A_HOLD_DIV_CLKS = 54;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL10_PL_B_HOLD_DIV_CLKS = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL10_PL_A_SELCLKSLIP = 56;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL10_PL_A_SELCLKSLIP_LEN = 2;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL10_PL_B_SELCLKSLIP = 58;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL10_PL_B_SELCLKSLIP_LEN = 2;
// iohs/reg00008.H

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX61_PL = 0x8001e80210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 = 56;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN = 8;
// iohs/reg00008.H

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX71_PL = 0x8002380210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 = 56;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN = 8;
// iohs/reg00008.H

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL11_PL = 0x8000580210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL11_PL_TERM_PD = 48;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL11_PL_FREQ_ADJUST = 49;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL11_PL_FREQ_ADJUST_LEN = 5;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL11_PL_OFF_CM = 54;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL11_PL_OFF_CM_LEN = 4;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL11_PL_OFF_DM = 58;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL11_PL_OFF_DM_LEN = 6;
// iohs/reg00008.H

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL2_PL = 0x8000100210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL2_PL_NS_DATA = 48;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL2_PL_NS_DATA_LEN = 4;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL2_PL_EW_DATA = 52;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL2_PL_EW_DATA_LEN = 4;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL2_PL_NS_EDGE = 56;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL2_PL_NS_EDGE_LEN = 4;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL2_PL_EW_EDGE = 60;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL2_PL_EW_EDGE_LEN = 4;
// iohs/reg00008.H

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL = 0x8000000210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 = 48;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 = 49;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 = 50;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 = 51;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 = 52;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 = 53;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 = 54;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 = 55;
// iohs/reg00008.H

static const uint64_t IOO_RX0_0_RD_3_RX_BIT_REGS_MODE1_PL = 0x8003200310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS = 49;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS = 50;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN = 51;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL = 52;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL = 53;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL_LEN = 3;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE = 56;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK = 57;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK = 58;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT = 59;
// iohs/reg00008.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX36_PL = 0x8001200310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 = 56;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN = 8;
// iohs/reg00008.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX46_PL = 0x8001700310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 = 56;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN = 8;
// iohs/reg00008.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX56_PL = 0x8001c00310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 = 56;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN = 8;
// iohs/reg00008.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX81_PL = 0x8002880310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 = 56;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN = 8;
// iohs/reg00008.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL17_PL = 0x8000880310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL17_PL_DATA = 48;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL17_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL17_PL_EDGE = 54;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL17_PL_EDGE_LEN = 5;
// iohs/reg00009.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL7_PL = 0x8000380310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL7_PL_EN_DC = 48;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL7_PL_PR_POS = 49;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL7_PL_PR_POS_LEN = 5;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL7_PL_PR_GRAY_ENCODE_DIS = 54;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL7_PL_ATTEN_DC_SEL = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL7_PL_ATTEN_DC_SEL_LEN = 3;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL7_PL_ATTEN_AC_SEL_DC = 58;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL7_PL_ATTEN_AC_SEL_DC_LEN = 3;
// iohs/reg00009.H

static const uint64_t IOO_RX0_0_RD_4_RX_BIT_REGS_MODE3_PL = 0x8003300410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_MODE3_PL_FILTER = 48;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_MODE3_PL_FILTER_LEN = 4;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_MODE3_PL_TERM = 52;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_MODE3_PL_TERM_LEN = 9;
// iohs/reg00009.H

static const uint64_t IOO_RX0_0_RD_4_RX_BIT_REGS_STAT5_PL = 0x8003b00410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_STAT5_PL_RX_ERROR_VEC_0_15_RO_SIGNAL = 48;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_STAT5_PL_RX_ERROR_VEC_0_15_RO_SIGNAL_LEN = 16;
// iohs/reg00009.H

static const uint64_t IOO_RX0_0_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL = 0x8003180410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ = 48;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ_LEN = 3;
// iohs/reg00009.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX19_PL = 0x8000980410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N = 56;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N_LEN = 8;
// iohs/reg00009.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX29_PL = 0x8000e80410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010 = 56;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010_LEN = 8;
// iohs/reg00009.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX39_PL = 0x8001380410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100 = 56;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100_LEN = 8;
// iohs/reg00009.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX49_PL = 0x8001880410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110 = 56;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110_LEN = 8;
// iohs/reg00009.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX25_PL = 0x8000c80410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S = 56;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S_LEN = 8;
// iohs/reg00009.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX65_PL = 0x8002080410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110 = 56;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110_LEN = 8;
// iohs/reg00009.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX75_PL = 0x8002580410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000 = 56;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000_LEN = 8;
// iohs/reg00009.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL18_PL = 0x8000900410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL18_PL_DATA = 48;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL18_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL18_PL_EDGE = 54;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL18_PL_EDGE_LEN = 5;
// iohs/reg00009.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL4_PL = 0x8000200410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL4_PL_GAIN = 48;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL4_PL_GAIN_LEN = 3;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL4_PL_ZERO = 51;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL4_PL_ZERO_LEN = 3;
// iohs/reg00009.H

static const uint64_t IOO_RX0_0_RD_5_RX_BIT_REGS_FIR_MASK_PL = 0x8003100510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK = 48;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK_LEN = 3;
// iohs/reg00009.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX22_PL = 0x8000b00510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W = 56;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W_LEN = 8;
// iohs/reg00009.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX32_PL = 0x8001000510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101 = 56;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101_LEN = 8;
// iohs/reg00009.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX42_PL = 0x8001500510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111 = 56;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111_LEN = 8;
// iohs/reg00009.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX52_PL = 0x8001a00510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001 = 56;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001_LEN = 8;
// iohs/reg00009.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX85_PL = 0x8002a80510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010 = 56;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010_LEN = 8;
// iohs/reg00009.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL1_PL = 0x8000080510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS = 48;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS_LEN = 6;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS = 54;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS_LEN = 6;
// iohs/reg00009.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX34_PL = 0x8001100610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111 = 56;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX34_PL_RX_AD_LATCH_DAC_N111_LEN = 8;
// iohs/reg00009.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX44_PL = 0x8001600610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001 = 56;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX44_PL_RX_AD_LATCH_DAC_S001_LEN = 8;
// iohs/reg00009.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX54_PL = 0x8001b00610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011 = 56;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX54_PL_RX_AD_LATCH_DAC_W011_LEN = 8;
// iohs/reg00009.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX68_PL = 0x8002200610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001 = 56;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX68_PL_RX_BD_LATCH_DAC_E001_LEN = 8;
// iohs/reg00009.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX78_PL = 0x8002700610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011 = 56;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX78_PL_RX_BD_LATCH_DAC_S011_LEN = 8;
// iohs/reg00009.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX83_PL = 0x8002980610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000 = 56;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX83_PL_RX_BD_LATCH_DAC_W000_LEN = 8;
// iohs/reg00009.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL10_PL = 0x8000500610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL10_PL_IF_BLEED_CMFB = 48;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL10_PL_IF_EXT_BIAS = 49;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL10_PL_IF_LPF_500M = 50;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL10_PL_SIGDET_PD = 51;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL10_PL_A_CLKSLIP = 52;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL10_PL_B_CLKSLIP = 53;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL10_PL_A_HOLD_DIV_CLKS = 54;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL10_PL_B_HOLD_DIV_CLKS = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL10_PL_A_SELCLKSLIP = 56;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL10_PL_A_SELCLKSLIP_LEN = 2;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL10_PL_B_SELCLKSLIP = 58;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL10_PL_B_SELCLKSLIP_LEN = 2;
// iohs/reg00009.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL8_PL = 0x8000400610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL8_PL_CLK_PHASE_SELECT = 48;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL8_PL_CLK_PHASE_SELECT_LEN = 2;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL8_PL_DPR_VBN_CAL = 50;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL8_PL_DPR_VBN_CAL_LEN = 2;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL8_PL_OFF_DISABLE_DM_B = 52;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL8_PL_CTLE_CONFIG_DC = 53;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL8_PL_CTLE_CONFIG_DC_LEN = 3;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL8_PL_VDAC_CONFIG_DC = 56;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL8_PL_VDAC_CONFIG_DC_LEN = 2;
// iohs/reg00009.H

static const uint64_t IOO_RX0_1_RD_RX_BIT_REGS_MODE1_PL = 0x8003200710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_MODE1_PL_PSAVE_DIG_REQ_DIS = 49;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_MODE1_PL_PSAVE_ANA_REQ_DIS = 50;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_MODE1_PL_BERPL_COUNT_EN = 51;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_MODE1_PL_BERPL_EXP_DATA_SEL = 52;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL = 53;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_MODE1_PL_BERPL_PATTERN_SEL_LEN = 3;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_MODE1_PL_BERPL_MASK_MODE = 56;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_REQ_DL_MASK = 57;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_MODE1_PL_BUMP_SL_1UI_DONE_DL_MASK = 58;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_MODE1_PL_BERPL_LANE_INVERT = 59;
// iohs/reg00009.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL = 0x8000b80710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N = 56;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX23_PL_RX_BE_LATCH_DAC_N_LEN = 8;
// iohs/reg00009.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL = 0x8001f80710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100 = 56;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX63_PL_RX_BD_LATCH_DAC_N100_LEN = 8;
// iohs/reg00009.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL = 0x8002480710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110 = 56;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX73_PL_RX_BD_LATCH_DAC_E110_LEN = 8;
// iohs/reg00009.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL = 0x8002c00710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101 = 56;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX88_PL_RX_BD_LATCH_DAC_W101_LEN = 8;
// iohs/reg00009.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL16_PL = 0x8000800710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL16_PL_DATA = 48;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL16_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL16_PL_EDGE = 54;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL16_PL_EDGE_LEN = 5;
// iohs/reg00009.H

static const uint64_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTLX5_PL = 0x8003800810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTLX5_PL_SET_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL = 48;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTLX5_PL_CLR_CAL_LANE_SEL_WO_PULSE_SLOW_SIGNAL = 49;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_A_WO_PULSE_SLOW_SIGNAL = 50;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_A_WO_PULSE_SLOW_SIGNAL = 51;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SL_1UI_B_WO_PULSE_SLOW_SIGNAL = 52;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTLX5_PL_PR_BUMP_SR_1UI_B_WO_PULSE_SLOW_SIGNAL = 53;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL = 54;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTLX5_PL_PR_IN_COARSE_MODE_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL = 55;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_A_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL = 56;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTLX5_PL_PR_UNLOCKED_B_STICKY_CLEAR_WO_PULSE_SLOW_SIGNAL = 57;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_A_WO_PULSE_SLOW_SIGNAL = 58;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTLX5_PL_PR_TAKE_FW_SNAPSHOT_B_WO_PULSE_SLOW_SIGNAL = 59;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTLX5_PL_ERR_TRAP_RST_WO_PULSE_SLOW_SIGNAL = 60;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_A_CLR_WO_PULSE_SLOW_SIGNAL = 61;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTLX5_PL_PSAVE_CDRLOCK_TIMER_FAIL_B_CLR_WO_PULSE_SLOW_SIGNAL = 62;
// iohs/reg00009.H

static const uint64_t IOO_RX0_1_RD_2_RX_BIT_REGS_MODE6_PL = 0x8003480810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_MODE6_PL_TIME_VAL = 48;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN = 13;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE = 62;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_MODE6_PL_DISABLE_SM = 63;
// iohs/reg00009.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX21_PL = 0x8000a80810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S = 56;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S_LEN = 8;
// iohs/reg00009.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX31_PL = 0x8000f80810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100 = 56;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100_LEN = 8;
// iohs/reg00009.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX41_PL = 0x8001480810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110 = 56;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110_LEN = 8;
// iohs/reg00009.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX51_PL = 0x8001980810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000 = 56;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000_LEN = 8;
// iohs/reg00009.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX86_PL = 0x8002b00810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011 = 56;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011_LEN = 8;
// iohs/reg00009.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL17_PL = 0x8000880810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL17_PL_DATA = 48;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL17_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL17_PL_EDGE = 54;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL17_PL_EDGE_LEN = 5;
// iohs/reg00009.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL2_PL = 0x8000100810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL2_PL_NS_DATA = 48;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL2_PL_NS_DATA_LEN = 4;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL2_PL_EW_DATA = 52;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL2_PL_EW_DATA_LEN = 4;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL2_PL_NS_EDGE = 56;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL2_PL_NS_EDGE_LEN = 4;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL2_PL_EW_EDGE = 60;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL2_PL_EW_EDGE_LEN = 4;
// iohs/reg00009.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX26_PL = 0x8000d01110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W = 56;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W_LEN = 8;
// iohs/reg00009.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX66_PL = 0x8002101110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111 = 56;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111_LEN = 8;
// iohs/reg00009.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX76_PL = 0x8002601110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001 = 56;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001_LEN = 8;
// iohs/reg00009.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL11_PL = 0x8000581110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL11_PL_TERM_PD = 48;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL11_PL_FREQ_ADJUST = 49;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL11_PL_FREQ_ADJUST_LEN = 5;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL11_PL_OFF_CM = 54;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL11_PL_OFF_CM_LEN = 4;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL11_PL_OFF_DM = 58;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL11_PL_OFF_DM_LEN = 6;
// iohs/reg00009.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL7_PL = 0x8000381110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL7_PL_EN_DC = 48;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL7_PL_PR_POS = 49;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL7_PL_PR_POS_LEN = 5;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL7_PL_PR_GRAY_ENCODE_DIS = 54;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL7_PL_ATTEN_DC_SEL = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL7_PL_ATTEN_DC_SEL_LEN = 3;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL7_PL_ATTEN_AC_SEL_DC = 58;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL7_PL_ATTEN_AC_SEL_DC_LEN = 3;
// iohs/reg00009.H

static const uint64_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE8_PL = 0x8003581010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH = 48;
static const uint32_t IOO_RX0_1_RD_4_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH_LEN = 12;
// iohs/reg00009.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX35_PL = 0x8001181010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000 = 56;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000_LEN = 8;
// iohs/reg00010.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX45_PL = 0x8001681010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010 = 56;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010_LEN = 8;
// iohs/reg00010.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX55_PL = 0x8001b81010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100 = 56;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100_LEN = 8;
// iohs/reg00010.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX59_PL = 0x8001d81010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000 = 56;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000_LEN = 8;
// iohs/reg00010.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX69_PL = 0x8002281010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010 = 56;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010_LEN = 8;
// iohs/reg00010.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX79_PL = 0x8002781010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100 = 56;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100_LEN = 8;
// iohs/reg00010.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX82_PL = 0x8002901010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111 = 56;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111_LEN = 8;
// iohs/reg00010.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL4_PL = 0x8000201010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL4_PL_GAIN = 48;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL4_PL_GAIN_LEN = 3;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL4_PL_ZERO = 51;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL4_PL_ZERO_LEN = 3;
// iohs/reg00010.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_DATA_SPARE_MODE_PL = 0x8000001010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 = 48;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 = 49;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 = 50;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 = 51;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 = 52;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 = 53;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 = 54;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 = 55;
// iohs/reg00010.H

static const uint64_t IOO_RX0_1_RD_5_RX_BIT_REGS_CNTL2_PL = 0x8003680f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_A = 48;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A = 49;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A = 50;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_CNTL2_PL_ENABLE_B = 51;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B = 52;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B = 53;
// iohs/reg00010.H

static const uint64_t IOO_RX0_1_RD_5_RX_BIT_REGS_MODE4_PL = 0x8003380f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT = 48;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT_LEN = 4;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_MODE4_PL_PHASE_STEP = 56;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_MODE4_PL_PHASE_STEP_LEN = 7;
// iohs/reg00010.H

static const uint64_t IOO_RX0_1_RD_5_RX_BIT_REGS_STAT2_PL = 0x8003980f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_STAT2_PL_RX_PR_FW_SNAPSHOT_A_RO_SIGNAL = 48;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_STAT2_PL_RX_PR_FW_SNAPSHOT_A_RO_SIGNAL_LEN = 15;
// iohs/reg00010.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX62_PL = 0x8001f00f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011 = 56;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011_LEN = 8;
// iohs/reg00010.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX72_PL = 0x8002400f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101 = 56;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101_LEN = 8;
// iohs/reg00010.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX89_PL = 0x8002c80f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110 = 56;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110_LEN = 8;
// iohs/reg00010.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL18_PL = 0x8000900f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL18_PL_DATA = 48;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL18_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL18_PL_EDGE = 54;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL18_PL_EDGE_LEN = 5;
// iohs/reg00010.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL1_PL = 0x8000080f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS = 48;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS_LEN = 6;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS = 54;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS_LEN = 6;
// iohs/reg00010.H

static const uint64_t IOO_RX0_2_RD_0_RX_BIT_REGS_MODE3_PL = 0x8003300e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_MODE3_PL_FILTER = 48;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_MODE3_PL_FILTER_LEN = 4;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_MODE3_PL_TERM = 52;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_MODE3_PL_TERM_LEN = 9;
// iohs/reg00010.H

static const uint64_t IOO_RX0_2_RD_0_RX_BIT_REGS_STAT5_PL = 0x8003b00e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_STAT5_PL_RX_ERROR_VEC_0_15_RO_SIGNAL = 48;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_STAT5_PL_RX_ERROR_VEC_0_15_RO_SIGNAL_LEN = 16;
// iohs/reg00010.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX33_PL = 0x8001080e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110 = 56;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX33_PL_RX_AD_LATCH_DAC_N110_LEN = 8;
// iohs/reg00010.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX43_PL = 0x8001580e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000 = 56;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX43_PL_RX_AD_LATCH_DAC_S000_LEN = 8;
// iohs/reg00010.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX53_PL = 0x8001a80e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010 = 56;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX53_PL_RX_AD_LATCH_DAC_W010_LEN = 8;
// iohs/reg00010.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX84_PL = 0x8002a00e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001 = 56;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX84_PL_RX_BD_LATCH_DAC_W001_LEN = 8;
// iohs/reg00010.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL3_PL = 0x8000180e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL3_PL_GAIN = 48;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL3_PL_GAIN_LEN = 3;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL3_PL_ZERO = 51;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_CNTL3_PL_ZERO_LEN = 3;
// iohs/reg00010.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX28_PL = 0x8000e00d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001 = 56;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX28_PL_RX_AD_LATCH_DAC_N001_LEN = 8;
// iohs/reg00010.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX38_PL = 0x8001300d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011 = 56;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX38_PL_RX_AD_LATCH_DAC_E011_LEN = 8;
// iohs/reg00010.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX48_PL = 0x8001800d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101 = 56;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX48_PL_RX_AD_LATCH_DAC_S101_LEN = 8;
// iohs/reg00010.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX58_PL = 0x8001d00d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111 = 56;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_A_CNTLX58_PL_RX_AD_LATCH_DAC_W111_LEN = 8;
// iohs/reg00010.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX24_PL = 0x8000c00d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E = 56;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX24_PL_RX_BE_LATCH_DAC_E_LEN = 8;
// iohs/reg00010.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX64_PL = 0x8002000d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101 = 56;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX64_PL_RX_BD_LATCH_DAC_N101_LEN = 8;
// iohs/reg00010.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX74_PL = 0x8002500d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111 = 56;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX74_PL_RX_BD_LATCH_DAC_E111_LEN = 8;
// iohs/reg00010.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL6_PL = 0x8000300d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL6_PL_GAIN = 48;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL6_PL_GAIN_LEN = 4;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL6_PL_PEAK1 = 52;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL6_PL_PEAK1_LEN = 4;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL6_PL_PEAK2 = 56;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL6_PL_PEAK2_LEN = 4;
// iohs/reg00010.H

static const uint64_t IOO_RX0_2_RD_RX_BIT_REGS_MODE8_PL = 0x8003580c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH = 48;
static const uint32_t IOO_RX0_2_RD_RX_BIT_REGS_MODE8_PL_RX_BERPL_SAT_THRESH_LEN = 12;
// iohs/reg00010.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX36_PL = 0x8001200c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 = 56;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN = 8;
// iohs/reg00010.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX46_PL = 0x8001700c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 = 56;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN = 8;
// iohs/reg00010.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX56_PL = 0x8001c00c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 = 56;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN = 8;
// iohs/reg00010.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX81_PL = 0x8002880c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 = 56;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN = 8;
// iohs/reg00010.H

static const uint64_t IOO_RX0_2_RD_3_RX_BIT_REGS_CNTL2_PL = 0x8003680b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_CNTL2_PL_ENABLE_A = 48;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_A = 49;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_A = 50;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_CNTL2_PL_ENABLE_B = 51;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_CNTL2_PL_SLAVE_MODE_B = 52;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_CNTL2_PL_QUAD_MODE_B = 53;
// iohs/reg00010.H

static const uint64_t IOO_RX0_2_RD_3_RX_BIT_REGS_MODE4_PL = 0x8003380b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT = 48;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_MODE4_PL_FW_INERTIA_AMT_LEN = 4;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_MODE4_PL_PHASE_STEP = 56;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_MODE4_PL_PHASE_STEP_LEN = 7;
// iohs/reg00010.H

static const uint64_t IOO_RX0_2_RD_3_RX_BIT_REGS_STAT2_PL = 0x8003980b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_STAT2_PL_RX_PR_FW_SNAPSHOT_A_RO_SIGNAL = 48;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_STAT2_PL_RX_PR_FW_SNAPSHOT_A_RO_SIGNAL_LEN = 15;
// iohs/reg00010.H

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX61_PL = 0x8001e80b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 = 56;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN = 8;
// iohs/reg00010.H

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX71_PL = 0x8002380b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 = 56;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN = 8;
// iohs/reg00010.H

static const uint64_t IOO_RX0_2_RD_4_RX_BIT_REGS_MODE6_PL = 0x8003480a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_MODE6_PL_TIME_VAL = 48;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_MODE6_PL_TIME_VAL_LEN = 13;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_MODE6_PL_TIMER_DOUBLE_MODE = 62;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_MODE6_PL_DISABLE_SM = 63;
// iohs/reg00010.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX22_PL = 0x8000b00a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W = 56;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W_LEN = 8;
// iohs/reg00010.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX32_PL = 0x8001000a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101 = 56;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101_LEN = 8;
// iohs/reg00010.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX42_PL = 0x8001500a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111 = 56;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111_LEN = 8;
// iohs/reg00010.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX52_PL = 0x8001a00a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001 = 56;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001_LEN = 8;
// iohs/reg00010.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX85_PL = 0x8002a80a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010 = 56;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010_LEN = 8;
// iohs/reg00010.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL14_PL = 0x8000700a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL14_PL_DATA = 48;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL14_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL14_PL_EDGE = 54;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL14_PL_EDGE_LEN = 5;
// iohs/reg00010.H

static const uint64_t IOO_RX0_2_RD_5_RX_BIT_REGS_FIR_PL = 0x8003080910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL = 48;
static const uint32_t IOO_RX0_2_RD_5_RX_BIT_REGS_FIR_PL_RX_PL_FIR_ERRS_RO_SIGNAL_LEN = 3;
// iohs/reg00010.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX19_PL = 0x8000980910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N = 56;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N_LEN = 8;
// iohs/reg00011.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX29_PL = 0x8000e80910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010 = 56;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010_LEN = 8;
// iohs/reg00011.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX39_PL = 0x8001380910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100 = 56;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100_LEN = 8;
// iohs/reg00011.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX49_PL = 0x8001880910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110 = 56;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110_LEN = 8;
// iohs/reg00011.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX25_PL = 0x8000c80910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S = 56;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S_LEN = 8;
// iohs/reg00011.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX65_PL = 0x8002080910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110 = 56;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110_LEN = 8;
// iohs/reg00011.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX75_PL = 0x8002580910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000 = 56;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000_LEN = 8;
// iohs/reg00011.H

static const uint64_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL8_PG = 0x800c7c0010012c3full;

static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31 = 48;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_CNTL8_PG_TX_PATTERN_16_31_LEN = 16;
// iohs/reg00011.H

static const uint64_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL13_PG = 0x800d240010012c3full;

static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL13_PG_TX_PSAVE_FORCE_REQ_0_15_1 = 48;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL13_PG_TX_PSAVE_FORCE_REQ_0_15_1_LEN = 16;
// iohs/reg00011.H

static const uint64_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL23_PL = 0x8004e40010012c3full;

static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// iohs/reg00011.H

static const uint64_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL7_PL = 0x8004640010012c3full;

static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL7_PL_EN = 51;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL7_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL7_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL7_PL_SEL_LEN = 5;
// iohs/reg00011.H

static const uint64_t IOO_TX0_0_DD_TX_BIT_REGS_MODE1_PL = 0x80041c0010012c3full;

static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_MODE1_PL_LANE_INVERT = 48;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE = 49;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE_LEN = 2;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN = 51;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN = 52;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS = 53;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE = 54;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE = 55;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 = 60;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 = 61;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 = 62;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 = 63;
// iohs/reg00011.H

static const uint64_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL19_PL = 0x8004c40110012c3full;

static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL19_PL_EN = 51;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL19_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL19_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL19_PL_SEL_LEN = 5;
// iohs/reg00011.H

static const uint64_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL29_PL = 0x8005140110012c3full;

static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN = 48;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN_LEN = 16;
// iohs/reg00011.H

static const uint64_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL15_PL = 0x8004a40310012c3full;

static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL = 48;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN = 4;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE = 52;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM = 53;
// iohs/reg00011.H

static const uint64_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL25_PL = 0x8004f40310012c3full;

static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// iohs/reg00011.H

static const uint64_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL3_PL = 0x8004440310012c3full;

static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE = 48;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE = 49;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE = 50;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR = 51;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE = 52;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE = 53;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE = 54;
// iohs/reg00011.H

static const uint64_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL18_PL = 0x8004bc0410012c3full;

static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN = 48;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN = 16;
// iohs/reg00011.H

static const uint64_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL22_PL = 0x8004dc0510012c3full;

static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL22_PL_EN = 51;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL22_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL22_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL22_PL_SEL_LEN = 5;
// iohs/reg00011.H

static const uint64_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL22_PL = 0x8004dc0610012c3full;

static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL22_PL_EN = 51;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL22_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL22_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL22_PL_SEL_LEN = 5;
// iohs/reg00011.H

static const uint64_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL9_PL = 0x8004740610012c3full;

static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_24_HS_EN = 48;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_24_HS_EN_LEN = 9;
// iohs/reg00011.H

static const uint64_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL18_PL = 0x8004bc0710012c3full;

static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN = 48;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN = 16;
// iohs/reg00011.H

static const uint64_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL4_PL = 0x80044c0710012c3full;

static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL4_PL_EN = 51;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL4_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL4_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL4_PL_SEL_LEN = 5;
// iohs/reg00011.H

static const uint64_t IOO_TX0_1_DD_TX_BIT_REGS_MODE2_PL = 0x8004240710012c3full;

static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY = 48;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY_LEN = 3;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE = 56;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_MODE2_PL_RXCAL = 57;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL = 58;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL_LEN = 3;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_MODE2_PL_FIFO_HOLD = 61;
// iohs/reg00011.H

static const uint64_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL14_PL = 0x80049c1110012c3full;

static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS = 48;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL14_PL_BANK_CONTROLS_LEN = 6;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL = 54;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_VAL_LEN = 3;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL14_PL_PSAVE_FIFO_INIT_TIMER_DOUBLE_MODE = 57;
// iohs/reg00011.H

static const uint64_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL24_PL = 0x8004ec1110012c3full;

static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN = 48;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL24_PL_TX_PSEG_MAIN_16_24_SAFE_EN_LEN = 9;
// iohs/reg00011.H

static const uint64_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL19_PL = 0x8004c41010012c3full;

static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL19_PL_EN = 51;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL19_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL19_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL19_PL_SEL_LEN = 5;
// iohs/reg00011.H

static const uint64_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL29_PL = 0x8005141010012c3full;

static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN = 48;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN_LEN = 16;
// iohs/reg00011.H

static const uint64_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL3_PL = 0x8004441010012c3full;

static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE = 48;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE = 49;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE = 50;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR = 51;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE = 52;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE = 53;
static const uint32_t IOO_TX0_1_DD_4_TX_BIT_REGS_CNTL3_PL_EOL_MODE_DISABLE = 54;
// iohs/reg00011.H

static const uint64_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL23_PL = 0x8004e40f10012c3full;

static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// iohs/reg00011.H

static const uint64_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL8_PL = 0x80046c0e10012c3full;

static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN = 48;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL8_PL_TX_PSEG_MAIN_0_15_HS_EN_LEN = 16;
// iohs/reg00011.H

static const uint64_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL10_PL = 0x80047c0d10012c3full;

static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN = 48;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN = 16;
// iohs/reg00011.H

static const uint64_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL20_PL = 0x8004cc0d10012c3full;

static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL20_PL_EN = 51;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL20_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL20_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL20_PL_SEL_LEN = 5;
// iohs/reg00011.H

static const uint64_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL30_PL = 0x80051c0d10012c3full;

static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE = 48;
// iohs/reg00011.H

static const uint64_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL5_PL = 0x8004540d10012c3full;

static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL5_PL_EN = 51;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL5_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL5_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL5_PL_SEL_LEN = 5;
// iohs/reg00011.H

static const uint64_t IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_PL = 0x8004040d10012c3full;

static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL = 48;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_FIR_PL_TX_PL_FIR_ERRS_RO_SIGNAL_LEN = 2;
// iohs/reg00011.H

static const uint64_t IOO_TX0_2_DD_1_TX_BIT_REGS_MODE3_PL = 0x80042c0d10012c3full;

static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_MODE3_PL_D2_CTRL = 48;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_MODE3_PL_D2_CTRL_LEN = 2;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL = 50;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_MODE3_PL_D2_DIV_CTRL_LEN = 2;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_MODE3_PL_BOOST_HS_EN = 52;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_MODE3_PL_BOOST_SAFE_EN = 53;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_MODE3_PL_SEG_TEST_LEAKAGE_CTRL = 54;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL = 55;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_MODE3_PL_DCC_CMP_HIGH_SEL_LEN = 3;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL = 58;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_MODE3_PL_DCC_CMP_LOW_SEL_LEN = 3;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL = 61;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_MODE3_PL_DCC_CMP_SAMP_SEL_LEN = 2;
// iohs/reg00011.H

static const uint64_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL16_PL = 0x8004ac0c10012c3full;

static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL16_PL_I_TUNE = 48;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL16_PL_I_TUNE_LEN = 6;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL16_PL_Q_TUNE = 54;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL16_PL_Q_TUNE_LEN = 6;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL16_PL_PHASE_SEL = 60;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL16_PL_MAIN_SEL = 61;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL16_PL_PAD_SEL = 62;
// iohs/reg00011.H

static const uint64_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL26_PL = 0x8004fc0c10012c3full;

static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN = 48;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_24_SAFE_EN_LEN = 9;
// iohs/reg00011.H

static const uint64_t IOO_TX0_2_DD_TX_BIT_REGS_FIR_ERROR_INJECT_PL = 0x8004140c10012c3full;

static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ = 48;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ_LEN = 2;
// iohs/reg00011.H

static const uint64_t IOO_TX0_2_DD_TX_BIT_REGS_STAT1_PL = 0x8005240c10012c3full;

static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_STAT1_PL_TX_BIST_PRBS_ERR_DET_RO_SIGNAL = 48;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_STAT1_PL_TX_BIST_PRBS_ACTIVITY_DET_RO_SIGNAL = 49;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS = 50;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS_LEN = 2;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_STAT1_PL_TX_TDR_CAPT_VAL_RO_SIGNAL = 63;
// iohs/reg00011.H

static const uint64_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL11_PL = 0x8004840a10012c3full;

static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_24_HS_EN = 48;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_24_HS_EN_LEN = 9;
// iohs/reg00011.H

static const uint64_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL1G_PL = 0x8004340a10012c3full;

static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL1G_PL_ERR_INJECT_WO_PULSE_SLOW_SIGNAL = 48;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL1G_PL_ERR_INJECT_WO_PULSE_SLOW_SIGNAL_LEN = 6;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL1G_PL_FIFO_INIT_WO_PULSE_SLOW_SIGNAL = 59;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL1G_PL_SET_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 60;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL1G_PL_CLR_UNLOAD_CLK_DISABLE_WO_PULSE_SLOW_SIGNAL = 61;
// iohs/reg00011.H

static const uint64_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL21_PL = 0x8004d40a10012c3full;

static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL21_PL_EN = 51;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL21_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL21_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL21_PL_SEL_LEN = 5;
// iohs/reg00011.H

static const uint64_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL2_PL = 0x80043c0a10012c3full;

static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL2_PL_RESET = 48;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL2_PL_DOM_IORESET = 49;
// iohs/reg00011.H

static const uint64_t IOO_TX0_2_DD_4_TX_BIT_REGS_STAT2_PL = 0x80052c0a10012c3full;

static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_STAT2_PL_UP_CNT_RO_SIGNAL = 48;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_STAT2_PL_UP_CNT_RO_SIGNAL_LEN = 8;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_STAT2_PL_DOWN_CNT_RO_SIGNAL = 56;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_STAT2_PL_DOWN_CNT_RO_SIGNAL_LEN = 8;
// iohs/reg00011.H

static const uint64_t REGS_PRX0_DLR_APCR = 0x18011038ull;

static const uint32_t REGS_PRX0_DLR_APCR_LINK_POPULATED = 0;
static const uint32_t REGS_PRX0_DLR_APCR_LINK_TYPE = 1;
static const uint32_t REGS_PRX0_DLR_APCR_LINK_TYPE_LEN = 3;
static const uint32_t REGS_PRX0_DLR_APCR_LINK_INFO = 4;
static const uint32_t REGS_PRX0_DLR_APCR_LINK_INFO_LEN = 6;
static const uint32_t REGS_PRX0_DLR_APCR_DL_ENABLE = 10;
static const uint32_t REGS_PRX0_DLR_APCR_FREEZE_PROXY = 11;
static const uint32_t REGS_PRX0_DLR_APCR_WINDOW_SELECT = 12;
static const uint32_t REGS_PRX0_DLR_APCR_WINDOW_SELECT_LEN = 4;
static const uint32_t REGS_PRX0_DLR_APCR_DIV2_WEIGHT = 16;
static const uint32_t REGS_PRX0_DLR_APCR_DIV2_WEIGHT_LEN = 4;
static const uint32_t REGS_PRX0_DLR_APCR_DIV4_WEIGHT = 20;
static const uint32_t REGS_PRX0_DLR_APCR_DIV4_WEIGHT_LEN = 4;
// iohs/reg00011.H

#ifndef __PPE_HCODE__
}
}
#include "iohs/reg00008.H"
#include "iohs/reg00009.H"
#include "iohs/reg00010.H"
#include "iohs/reg00011.H"
#endif
#endif
