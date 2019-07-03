/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_c.H $       */
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

#ifndef __p10_scom_iohs_c_H_
#define __p10_scom_iohs_c_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


static const uint64_t AXON_CPLT_STAT0 = 0x18000100ull;

static const uint32_t AXON_CPLT_STAT0_ABIST_DONE_DC = 0;
static const uint32_t AXON_CPLT_STAT0_RESERVED_2I = 2;
static const uint32_t AXON_CPLT_STAT0_RESERVED_3I = 3;
static const uint32_t AXON_CPLT_STAT0_TC_DIAG_PORT0_OUT = 4;
static const uint32_t AXON_CPLT_STAT0_TC_DIAG_PORT1_OUT = 5;
static const uint32_t AXON_CPLT_STAT0_RESERVED_6I = 6;
static const uint32_t AXON_CPLT_STAT0_CC_CTRL_OPCG_DONE_DC = 8;
static const uint32_t AXON_CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC = 9;
static const uint32_t AXON_CPLT_STAT0_FREE_USAGE_10I = 10;
static const uint32_t AXON_CPLT_STAT0_FREE_USAGE_11I = 11;
static const uint32_t AXON_CPLT_STAT0_FREE_USAGE_12I = 12;
static const uint32_t AXON_CPLT_STAT0_FREE_USAGE_13I = 13;
static const uint32_t AXON_CPLT_STAT0_FREE_USAGE_14I = 14;
static const uint32_t AXON_CPLT_STAT0_FREE_USAGE_15I = 15;
static const uint32_t AXON_CPLT_STAT0_FREE_USAGE_16I = 16;
static const uint32_t AXON_CPLT_STAT0_FREE_USAGE_17I = 17;
static const uint32_t AXON_CPLT_STAT0_FREE_USAGE_18I = 18;
static const uint32_t AXON_CPLT_STAT0_FREE_USAGE_19I = 19;
static const uint32_t AXON_CPLT_STAT0_FREE_USAGE_20I = 20;
static const uint32_t AXON_CPLT_STAT0_FREE_USAGE_21I = 21;
static const uint32_t AXON_CPLT_STAT0_FREE_USAGE_22I = 22;
static const uint32_t AXON_CPLT_STAT0_FREE_USAGE_23I = 23;
static const uint32_t AXON_CPLT_STAT0_FREE_USAGE_24I = 24;
static const uint32_t AXON_CPLT_STAT0_FREE_USAGE_25I = 25;
static const uint32_t AXON_CPLT_STAT0_FREE_USAGE_26I = 26;
static const uint32_t AXON_CPLT_STAT0_FREE_USAGE_27I = 27;
static const uint32_t AXON_CPLT_STAT0_FREE_USAGE_28I = 28;
static const uint32_t AXON_CPLT_STAT0_FREE_USAGE_29I = 29;
static const uint32_t AXON_CPLT_STAT0_FREE_USAGE_30I = 30;
static const uint32_t AXON_CPLT_STAT0_FREE_USAGE_31I = 31;
// iohs/reg00053.H

static const uint64_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2 = 0x18040082ull;

static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_XSTOP_ERR = 0;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_RECOV_ERR = 1;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SPATTN_ERR = 2;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_LXSTOP_ERR = 3;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_HOSTATTN_ERR = 4;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SYS_XSTOP_ERR = 5;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SYS_XSTOP_STAGED_ERR = 6;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_DBG_TRIG_ERR = 7;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP01 = 12;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP02 = 13;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP03 = 14;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP04 = 15;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP05 = 16;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP06 = 17;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP07 = 18;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP08 = 19;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP09 = 20;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP010 = 21;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP011 = 22;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP012 = 23;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP013 = 24;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP014 = 25;
static const uint32_t AXON_EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_UNIT_TC_FIR_LOCAL_XSTOP015 = 26;
// iohs/reg00053.H

static const uint64_t AXON_EPS_FIR_LOCAL_ACTION0 = 0x18040106ull;

static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_00 = 0;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_01 = 1;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_02 = 2;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_03 = 3;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_04 = 4;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_05 = 5;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_06 = 6;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_07 = 7;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_08 = 8;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_09 = 9;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_10 = 10;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_11 = 11;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_12 = 12;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_13 = 13;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_14 = 14;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_15 = 15;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_16 = 16;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_17 = 17;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_18 = 18;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_19 = 19;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_20 = 20;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_21 = 21;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_22 = 22;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_23 = 23;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_24 = 24;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_25 = 25;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_26 = 26;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_27 = 27;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_28 = 28;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_29 = 29;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_30 = 30;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_31 = 31;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_32 = 32;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_33 = 33;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_34 = 34;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_35 = 35;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_36 = 36;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_37 = 37;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_38 = 38;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_39 = 39;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_40 = 40;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_41 = 41;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_42 = 42;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_43 = 43;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_44 = 44;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_45 = 45;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_46 = 46;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_47 = 47;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_48 = 48;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_49 = 49;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_50 = 50;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_51 = 51;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_52 = 52;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_53 = 53;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_54 = 54;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_55 = 55;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_56 = 56;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_57 = 57;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_58 = 58;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_59 = 59;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_60 = 60;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_61 = 61;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_62 = 62;
static const uint32_t AXON_EPS_FIR_LOCAL_ACTION0_63 = 63;
// iohs/reg00053.H

static const uint64_t AXON_HOSTATTN = 0x18040004ull;

static const uint32_t AXON_HOSTATTN_ANY_HOSTATTN = 0;
static const uint32_t AXON_HOSTATTN_RESERVED1H = 1;
static const uint32_t AXON_HOSTATTN_RESERVED2H = 2;
static const uint32_t AXON_HOSTATTN_RESERVED3H = 3;
static const uint32_t AXON_HOSTATTN_HOSTATTN_PERV = 4;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN05 = 5;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN06 = 6;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN07 = 7;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN08 = 8;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN09 = 9;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN10 = 10;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN11 = 11;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN12 = 12;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN13 = 13;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN14 = 14;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN15 = 15;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN16 = 16;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN17 = 17;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN18 = 18;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN19 = 19;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN20 = 20;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN21 = 21;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN22 = 22;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN23 = 23;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN24 = 24;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN25 = 25;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN26 = 26;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN27 = 27;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN28 = 28;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN29 = 29;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN30 = 30;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN31 = 31;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN32 = 32;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN33 = 33;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN34 = 34;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN35 = 35;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN36 = 36;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN37 = 37;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN38 = 38;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN39 = 39;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN40 = 40;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN41 = 41;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN42 = 42;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN43 = 43;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN44 = 44;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN45 = 45;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN46 = 46;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN47 = 47;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN48 = 48;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN49 = 49;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN50 = 50;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN51 = 51;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN52 = 52;
static const uint32_t AXON_HOSTATTN_HOSTATTN_IN53 = 53;
// iohs/reg00053.H

static const uint64_t AXON_TRA0_TR0_CONFIG_1 = 0x18010404ull;

static const uint32_t AXON_TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t AXON_TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// iohs/reg00053.H

static const uint64_t AXON_XSTOP3 = 0x1803000eull;

static const uint32_t AXON_XSTOP3_XSTOP3_MASK_B = 0;
static const uint32_t AXON_XSTOP3_ALIGNED_XSTOP3 = 1;
static const uint32_t AXON_XSTOP3_TRIGGER_OPCG_ON_XSTOP3 = 2;
static const uint32_t AXON_XSTOP3_XSTOP3_WAIT_ALLWAYS = 3;
static const uint32_t AXON_XSTOP3_XSTOP3_PERV = 4;
static const uint32_t AXON_XSTOP3_XSTOP3_UNIT1 = 5;
static const uint32_t AXON_XSTOP3_XSTOP3_UNIT2 = 6;
static const uint32_t AXON_XSTOP3_XSTOP3_UNIT3 = 7;
static const uint32_t AXON_XSTOP3_XSTOP3_UNIT4 = 8;
static const uint32_t AXON_XSTOP3_XSTOP3_UNIT5 = 9;
static const uint32_t AXON_XSTOP3_XSTOP3_UNIT6 = 10;
static const uint32_t AXON_XSTOP3_XSTOP3_UNIT7 = 11;
static const uint32_t AXON_XSTOP3_XSTOP3_UNIT8 = 12;
static const uint32_t AXON_XSTOP3_XSTOP3_UNIT9 = 13;
static const uint32_t AXON_XSTOP3_XSTOP3_UNIT10 = 14;
static const uint32_t AXON_XSTOP3_XSTOP3_UNIT11 = 15;
static const uint32_t AXON_XSTOP3_XSTOP3_UNIT12 = 16;
static const uint32_t AXON_XSTOP3_XSTOP3_UNIT13 = 17;
static const uint32_t AXON_XSTOP3_XSTOP3_UNIT14 = 18;
static const uint32_t AXON_XSTOP3_XSTOP3_WAIT_CYCLES = 48;
static const uint32_t AXON_XSTOP3_XSTOP3_WAIT_CYCLES_LEN = 12;
// iohs/reg00053.H

static const uint64_t DLP_CONTROL = 0x1801100bull;

static const uint32_t DLP_CONTROL_0_PHY_TRAINING = 0;
static const uint32_t DLP_CONTROL_0_STARTUP = 1;
static const uint32_t DLP_CONTROL_0_HOLD_PATT_A = 2;
static const uint32_t DLP_CONTROL_0_HOLD_PATT_B = 3;
static const uint32_t DLP_CONTROL_0_RUN_LANE_DISABLE = 4;
static const uint32_t DLP_CONTROL_0_RUN_LANE_OVERRIDE = 5;
static const uint32_t DLP_CONTROL_0_IGNORE_PHY = 6;
static const uint32_t DLP_CONTROL_0_IGNORE_FENCE = 7;
static const uint32_t DLP_CONTROL_0_ERR_INJ_COMMAND = 8;
static const uint32_t DLP_CONTROL_0_ERR_INJ_COMMAND_LEN = 4;
static const uint32_t DLP_CONTROL_0_ERR_INJ_COMMAND_LANES = 12;
static const uint32_t DLP_CONTROL_0_ERR_INJ_COMMAND_LANES_LEN = 9;
static const uint32_t DLP_CONTROL_0_COMMAND = 28;
static const uint32_t DLP_CONTROL_0_COMMAND_LEN = 4;
static const uint32_t DLP_CONTROL_1_PHY_TRAINING = 32;
static const uint32_t DLP_CONTROL_1_STARTUP = 33;
static const uint32_t DLP_CONTROL_1_HOLD_PATT_A = 34;
static const uint32_t DLP_CONTROL_1_HOLD_PATT_B = 35;
static const uint32_t DLP_CONTROL_1_RUN_LANE_DISABLE = 36;
static const uint32_t DLP_CONTROL_1_RUN_LANE_OVERRIDE = 37;
static const uint32_t DLP_CONTROL_1_IGNORE_PHY = 38;
static const uint32_t DLP_CONTROL_1_IGNORE_FENCE = 39;
static const uint32_t DLP_CONTROL_1_ERR_INJ_COMMAND = 40;
static const uint32_t DLP_CONTROL_1_ERR_INJ_COMMAND_LEN = 4;
static const uint32_t DLP_CONTROL_1_ERR_INJ_COMMAND_LANES = 44;
static const uint32_t DLP_CONTROL_1_ERR_INJ_COMMAND_LANES_LEN = 9;
static const uint32_t DLP_CONTROL_1_COMMAND = 60;
static const uint32_t DLP_CONTROL_1_COMMAND_LEN = 4;
// iohs/reg00053.H

static const uint64_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG = 0x8008600010012c3full;

static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_CLOCK_DAC = 48;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_CLOCK_DAC_LEN = 3;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_DATA_DAC = 51;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_DATA_DAC_LEN = 3;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_VSET_DAC = 54;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_VSET_DAC_LEN = 2;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_BYPASS = 56;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE12_PG_PDWN_B = 57;
// iohs/reg00053.H

static const uint64_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG = 0x8008080010012c3full;

static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_CLKDIST_PDWN = 48;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE1_PG_16TO1 = 51;
// iohs/reg00053.H

static const uint64_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG = 0x8008b00010012c3full;

static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_FILTER_DEPTH = 48;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_FILTER_DEPTH_LEN = 5;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_TIMEOUT = 53;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_TIMEOUT_LEN = 4;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_SERVO_RESTORE_PR = 57;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_VOTE_RATIO_CFG = 58;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_VOTE_RATIO_CFG_LEN = 3;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_SERVO_THRESH4 = 61;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_SERVO_THRESH4_LEN = 2;
static const uint32_t IOO_RX0_RXCTL_CTL_REGS_RX_MODE22_PG_VOTE_WIN_BOTH = 63;
// iohs/reg00053.H

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT10_PG = 0x8009d00010012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT10_PG_RX_PSAVE_FORCE_REQ_16_23_0 = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT10_PG_RX_PSAVE_FORCE_REQ_16_23_0_LEN = 8;
// iohs/reg00053.H

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG = 0x800a200010012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIME = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIME_LEN = 6;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIME = 54;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIME_LEN = 6;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_TIMER_DOUBLE_MODE = 61;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FIFO_TIMER_DOUBLE_MODE = 62;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT20_PG_FW_VALID_BYPASS = 63;
// iohs/reg00053.H

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT30_PG = 0x800a700010012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT30_PG_RX_B_LANE_DONE_16_23 = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNT30_PG_RX_B_LANE_DONE_16_23_LEN = 8;
// iohs/reg00053.H

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL3_PG = 0x8009980010012c3full;
// iohs/reg00053.H

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_STAT16_PG = 0x800b080010012c3full;
// iohs/reg00053.H

static const uint64_t IOO_RX0_RXCTL_DATASM_REGS_RX_STAT26_PG = 0x800b580010012c3full;
// iohs/reg00053.H

static const uint64_t IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL = 0x8003d00f10012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK = 49;
static const uint32_t IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK = 50;
static const uint32_t IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK = 51;
static const uint32_t IOO_RX0_RXCTL_DATASM_11_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK = 52;
// iohs/reg00053.H

static const uint64_t IOO_RX0_RXCTL_DATASM_13_PLREGS_RX_CNTL2_PL = 0x8003c80d10012c3full;
// iohs/reg00053.H

static const uint64_t IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL = 0x8003d80910012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_REQ_ALT = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_17_PLREGS_RX_CNTL3_PL_STS_ALT = 49;
// iohs/reg00053.H

static const uint64_t IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL = 0x8003d81510012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_REQ_ALT = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_21_PLREGS_RX_CNTL3_PL_STS_ALT = 49;
// iohs/reg00053.H

static const uint64_t IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL = 0x8003c00710012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_INIT_DONE = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_CNTL1_PL_RECAL_DONE = 49;
// iohs/reg00053.H

static const uint64_t IOO_RX0_RXCTL_DATASM_7_PLREGS_RX_STAT1_PL = 0x8003e00710012c3full;
// iohs/reg00053.H

static const uint64_t IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL = 0x8003d00810012c3full;

static const uint32_t IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK = 48;
static const uint32_t IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK = 49;
static const uint32_t IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK = 50;
static const uint32_t IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK = 51;
static const uint32_t IOO_RX0_RXCTL_DATASM_8_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK = 52;
// iohs/reg00053.H

static const uint64_t IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL = 0x8003700010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_IORESET = 48;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET = 49;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A = 50;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B = 51;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A = 52;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B = 53;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE = 54;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN = 55;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK = 57;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK_LEN = 4;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR = 61;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR_LEN = 3;
// iohs/reg00053.H

static const uint64_t IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL = 0x8003400010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE = 48;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE_LEN = 4;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE = 56;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE_LEN = 7;
// iohs/reg00053.H

static const uint64_t IOO_RX0_0_RD_RX_BIT_REGS_STAT3_PL = 0x8003a00010012c3full;
// iohs/reg00053.H

static const uint64_t IOO_RX0_0_RD_RX_BIT_REGS_FIR_MASK_PL = 0x8003100010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK = 48;
static const uint32_t IOO_RX0_0_RD_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK_LEN = 3;
// iohs/reg00053.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX67_PL = 0x8002180010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000 = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000_LEN = 9;
// iohs/reg00053.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX77_PL = 0x8002680010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010 = 55;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010_LEN = 9;
// iohs/reg00053.H

static const uint64_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL = 0x8000780010012c3full;

static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN = 48;
static const uint32_t IOO_RX0_0_RD_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN = 49;
// iohs/reg00053.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX20_PL = 0x8000a00110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E_LEN = 9;
// iohs/reg00053.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX30_PL = 0x8000f00110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011 = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011_LEN = 9;
// iohs/reg00053.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX40_PL = 0x8001400110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101 = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101_LEN = 9;
// iohs/reg00053.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX50_PL = 0x8001900110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111 = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111_LEN = 9;
// iohs/reg00053.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX87_PL = 0x8002b80110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100 = 55;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100_LEN = 9;
// iohs/reg00053.H

static const uint64_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL = 0x8000680110012c3full;

static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL_GAIN = 48;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL_GAIN_LEN = 4;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL_PEAK1 = 52;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL_PEAK1_LEN = 4;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL_PEAK2 = 56;
static const uint32_t IOO_RX0_0_RD_1_RX_DAC_REGS_CNTL13_PL_PEAK2_LEN = 4;
// iohs/reg00053.H

static const uint64_t IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL = 0x8003000210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_0 = 48;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_1 = 49;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_2 = 50;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_3 = 51;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_4 = 52;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_5 = 53;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_6 = 54;
static const uint32_t IOO_RX0_0_RD_2_RX_BIT_REGS_SPARE_MODE_PL_7 = 55;
// iohs/reg00053.H

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL = 0x8001f00210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011 = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011_LEN = 9;
// iohs/reg00053.H

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL = 0x8002400210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101 = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101_LEN = 9;
// iohs/reg00053.H

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL = 0x8002c80210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110 = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110_LEN = 9;
// iohs/reg00053.H

static const uint64_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL = 0x8000080210012c3full;

static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS = 48;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS_LEN = 6;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN = 54;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS = 55;
static const uint32_t IOO_RX0_0_RD_2_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS_LEN = 6;
// iohs/reg00053.H

static const uint64_t IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL = 0x8003780310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL_A = 49;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL_A_LEN = 7;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL_B = 57;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_CNTL4_PL_B_LEN = 7;
// iohs/reg00053.H

static const uint64_t IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL = 0x8003280310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN = 48;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR = 49;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN = 50;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN = 51;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN = 52;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_LOCK_RATIO = 53;
static const uint32_t IOO_RX0_0_RD_3_RX_BIT_REGS_MODE2_PL_LOCK_RATIO_LEN = 10;
// iohs/reg00053.H

static const uint64_t IOO_RX0_0_RD_3_RX_BIT_REGS_STAT4_PL = 0x8003a80310012c3full;
// iohs/reg00053.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX35_PL = 0x8001180310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000_LEN = 9;
// iohs/reg00053.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX45_PL = 0x8001680310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010_LEN = 9;
// iohs/reg00053.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX55_PL = 0x8001b80310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100_LEN = 9;
// iohs/reg00053.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX59_PL = 0x8001d80310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000_LEN = 9;
// iohs/reg00053.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX69_PL = 0x8002280310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010_LEN = 9;
// iohs/reg00053.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX79_PL = 0x8002780310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100_LEN = 9;
// iohs/reg00053.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX82_PL = 0x8002900310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111 = 55;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111_LEN = 9;
// iohs/reg00054.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL14_PL = 0x8000700310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL14_PL_DATA = 48;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL14_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL14_PL_EDGE = 54;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL14_PL_EDGE_LEN = 5;
// iohs/reg00054.H

static const uint64_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL4_PL = 0x8000200310012c3full;

static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL4_PL_GAIN = 48;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL4_PL_GAIN_LEN = 3;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL4_PL_ZERO = 51;
static const uint32_t IOO_RX0_0_RD_3_RX_DAC_REGS_CNTL4_PL_ZERO_LEN = 3;
// iohs/reg00054.H

static const uint64_t IOO_RX0_0_RD_4_RX_BIT_REGS_CNTL6_PL = 0x8003880410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL = 48;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL_LEN = 2;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A = 50;
static const uint32_t IOO_RX0_0_RD_4_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B = 51;
// iohs/reg00054.H

static const uint64_t IOO_RX0_0_RD_4_RX_BIT_REGS_STAT6_PL = 0x8003b80410012c3full;
// iohs/reg00054.H

static const uint64_t IOO_RX0_0_RD_4_RX_BIT_REGS_FIR_PL = 0x8003080410012c3full;
// iohs/reg00054.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX26_PL = 0x8000d00410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W_LEN = 9;
// iohs/reg00054.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX66_PL = 0x8002100410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111 = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111_LEN = 9;
// iohs/reg00054.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX76_PL = 0x8002600410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001 = 55;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001_LEN = 9;
// iohs/reg00054.H

static const uint64_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL7_PL = 0x8000380410012c3full;

static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL7_PL_EN_DC = 48;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL7_PL_PR_POS = 49;
static const uint32_t IOO_RX0_0_RD_4_RX_DAC_REGS_CNTL7_PL_PR_POS_LEN = 5;
// iohs/reg00054.H

static const uint64_t IOO_RX0_0_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL = 0x8003180510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ = 48;
static const uint32_t IOO_RX0_0_RD_5_RX_BIT_REGS_FIR_ERROR_INJECT_PL_RX_PL_FIR_ERR_INJ_LEN = 3;
// iohs/reg00054.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX21_PL = 0x8000a80510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S_LEN = 9;
// iohs/reg00054.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX31_PL = 0x8000f80510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100 = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100_LEN = 9;
// iohs/reg00054.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX41_PL = 0x8001480510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110 = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110_LEN = 9;
// iohs/reg00054.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX51_PL = 0x8001980510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000 = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000_LEN = 9;
// iohs/reg00054.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX86_PL = 0x8002b00510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011 = 55;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011_LEN = 9;
// iohs/reg00054.H

static const uint64_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL2_PL = 0x8000100510012c3full;

static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL2_PL_NS_DATA = 48;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL2_PL_NS_DATA_LEN = 4;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL2_PL_EW_DATA = 52;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL2_PL_EW_DATA_LEN = 4;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL2_PL_NS_EDGE = 56;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL2_PL_NS_EDGE_LEN = 4;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL2_PL_EW_EDGE = 60;
static const uint32_t IOO_RX0_0_RD_5_RX_DAC_REGS_CNTL2_PL_EW_EDGE_LEN = 4;
// iohs/reg00054.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX27_PL = 0x8000d80610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000 = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX27_PL_RX_AD_LATCH_DAC_N000_LEN = 9;
// iohs/reg00054.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX37_PL = 0x8001280610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010 = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX37_PL_RX_AD_LATCH_DAC_E010_LEN = 9;
// iohs/reg00054.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX47_PL = 0x8001780610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100 = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX47_PL_RX_AD_LATCH_DAC_S100_LEN = 9;
// iohs/reg00054.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX57_PL = 0x8001c80610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110 = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_A_CNTLX57_PL_RX_AD_LATCH_DAC_W110_LEN = 9;
// iohs/reg00054.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX80_PL = 0x8002800610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101 = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX80_PL_RX_BD_LATCH_DAC_S101_LEN = 9;
// iohs/reg00054.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX90_PL = 0x8002d00610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111 = 55;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_LOFF_B_CNTLX90_PL_RX_BD_LATCH_DAC_W111_LEN = 9;
// iohs/reg00054.H

static const uint64_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL13_PL = 0x8000680610012c3full;

static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL13_PL_GAIN = 48;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL13_PL_GAIN_LEN = 4;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL13_PL_PEAK1 = 52;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL13_PL_PEAK1_LEN = 4;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL13_PL_PEAK2 = 56;
static const uint32_t IOO_RX0_1_RD_0_RX_DAC_REGS_CNTL13_PL_PEAK2_LEN = 4;
// iohs/reg00054.H

static const uint64_t IOO_RX0_1_RD_RX_BIT_REGS_CNTL4_PL = 0x8003780710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_CNTL4_PL_A = 49;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_CNTL4_PL_A_LEN = 7;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_CNTL4_PL_B = 57;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_CNTL4_PL_B_LEN = 7;
// iohs/reg00054.H

static const uint64_t IOO_RX0_1_RD_RX_BIT_REGS_CNTLX5_PL = 0x8003800710012c3full;
// iohs/reg00054.H

static const uint64_t IOO_RX0_1_RD_RX_BIT_REGS_MODE2_PL = 0x8003280710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_EN = 48;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_MODE2_PL_INVALID_LOCK_FILTER_DIR = 49;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_MODE2_PL_COARSE_MODE_EN = 50;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_MODE2_PL_COARSE_UNLOCK_EN = 51;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_MODE2_PL_LOCK_INVALID_EN = 52;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_MODE2_PL_LOCK_RATIO = 53;
static const uint32_t IOO_RX0_1_RD_RX_BIT_REGS_MODE2_PL_LOCK_RATIO_LEN = 10;
// iohs/reg00054.H

static const uint64_t IOO_RX0_1_RD_RX_BIT_REGS_STAT4_PL = 0x8003a80710012c3full;
// iohs/reg00054.H

static const uint64_t IOO_RX0_1_RD_RX_BIT_REGS_FIR_PL = 0x8003080710012c3full;
// iohs/reg00054.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX60_PL = 0x8001e00710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001 = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX60_PL_RX_BD_LATCH_DAC_N001_LEN = 9;
// iohs/reg00054.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX70_PL = 0x8002300710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011 = 55;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_LOFF_B_CNTLX70_PL_RX_BD_LATCH_DAC_E011_LEN = 9;
// iohs/reg00054.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL15_PL = 0x8000780710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL15_PL_A_FENCE_EN = 48;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_CNTL15_PL_B_FENCE_EN = 49;
// iohs/reg00054.H

static const uint64_t IOO_RX0_1_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL = 0x8000000710012c3full;

static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_0 = 48;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_1 = 49;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_2 = 50;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_3 = 51;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_4 = 52;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_5 = 53;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_6 = 54;
static const uint32_t IOO_RX0_1_RD_RX_DAC_REGS_DATA_SPARE_MODE_PL_7 = 55;
// iohs/reg00054.H

static const uint64_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTL3_PL = 0x8003700810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTL3_PL_IORESET = 48;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET = 49;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A = 50;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B = 51;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A = 52;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B = 53;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE = 54;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN = 55;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK = 57;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK_LEN = 4;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR = 61;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR_LEN = 3;
// iohs/reg00054.H

static const uint64_t IOO_RX0_1_RD_2_RX_BIT_REGS_MODE5_PL = 0x8003400810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE = 48;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE_LEN = 4;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE = 56;
static const uint32_t IOO_RX0_1_RD_2_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE_LEN = 7;
// iohs/reg00054.H

static const uint64_t IOO_RX0_1_RD_2_RX_BIT_REGS_STAT3_PL = 0x8003a00810012c3full;
// iohs/reg00054.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX22_PL = 0x8000b00810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W = 55;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX22_PL_RX_AE_LATCH_DAC_W_LEN = 9;
// iohs/reg00054.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX32_PL = 0x8001000810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101 = 55;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX32_PL_RX_AD_LATCH_DAC_N101_LEN = 9;
// iohs/reg00054.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX42_PL = 0x8001500810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111 = 55;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX42_PL_RX_AD_LATCH_DAC_E111_LEN = 9;
// iohs/reg00054.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX52_PL = 0x8001a00810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001 = 55;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_A_CNTLX52_PL_RX_AD_LATCH_DAC_W001_LEN = 9;
// iohs/reg00054.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX85_PL = 0x8002a80810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010 = 55;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_LOFF_B_CNTLX85_PL_RX_BD_LATCH_DAC_W010_LEN = 9;
// iohs/reg00054.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL14_PL = 0x8000700810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL14_PL_DATA = 48;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL14_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL14_PL_EDGE = 54;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL14_PL_EDGE_LEN = 5;
// iohs/reg00054.H

static const uint64_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL1_PL = 0x8000080810012c3full;

static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS = 48;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL1_PL_A_BANK_CONTROLS_LEN = 6;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL1_PL_LANE_ANA_PDWN = 54;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS = 55;
static const uint32_t IOO_RX0_1_RD_2_RX_DAC_REGS_CNTL1_PL_B_BANK_CONTROLS_LEN = 6;
// iohs/reg00054.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX19_PL = 0x8000981110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX19_PL_RX_AE_LATCH_DAC_N_LEN = 9;
// iohs/reg00054.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX29_PL = 0x8000e81110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010 = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX29_PL_RX_AD_LATCH_DAC_N010_LEN = 9;
// iohs/reg00054.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX39_PL = 0x8001381110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100 = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX39_PL_RX_AD_LATCH_DAC_E100_LEN = 9;
// iohs/reg00054.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX49_PL = 0x8001881110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110 = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_A_CNTLX49_PL_RX_AD_LATCH_DAC_S110_LEN = 9;
// iohs/reg00054.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX25_PL = 0x8000c81110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX25_PL_RX_BE_LATCH_DAC_S_LEN = 9;
// iohs/reg00054.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX65_PL = 0x8002081110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110 = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX65_PL_RX_BD_LATCH_DAC_N110_LEN = 9;
// iohs/reg00054.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX75_PL = 0x8002581110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000 = 55;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_LOFF_B_CNTLX75_PL_RX_BD_LATCH_DAC_S000_LEN = 9;
// iohs/reg00054.H

static const uint64_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL4_PL = 0x8000201110012c3full;

static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL4_PL_GAIN = 48;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL4_PL_GAIN_LEN = 3;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL4_PL_ZERO = 51;
static const uint32_t IOO_RX0_1_RD_3_RX_DAC_REGS_CNTL4_PL_ZERO_LEN = 3;
// iohs/reg00055.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX36_PL = 0x8001201010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001 = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX36_PL_RX_AD_LATCH_DAC_E001_LEN = 9;
// iohs/reg00055.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX46_PL = 0x8001701010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011 = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX46_PL_RX_AD_LATCH_DAC_S011_LEN = 9;
// iohs/reg00055.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX56_PL = 0x8001c01010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101 = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_A_CNTLX56_PL_RX_AD_LATCH_DAC_W101_LEN = 9;
// iohs/reg00055.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX81_PL = 0x8002881010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110 = 55;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_LOFF_B_CNTLX81_PL_RX_BD_LATCH_DAC_S110_LEN = 9;
// iohs/reg00055.H

static const uint64_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL7_PL = 0x8000381010012c3full;

static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL7_PL_EN_DC = 48;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL7_PL_PR_POS = 49;
static const uint32_t IOO_RX0_1_RD_4_RX_DAC_REGS_CNTL7_PL_PR_POS_LEN = 5;
// iohs/reg00055.H

static const uint64_t IOO_RX0_1_RD_5_RX_BIT_REGS_CNTLX1_PL = 0x8003600f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_CNTLX1_PL_PIPE_FORMAT = 48;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_CNTLX1_PL_PIPE_DATA_SRC = 49;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL = 50;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_CNTLX1_PL_PIPE_SEL_LEN = 3;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A = 53;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_A_LEN = 2;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_CNTLX1_PL_PR_QUAD_SEL_B_LEN = 2;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_CNTLX1_PL_CAL_LANE_SEL = 57;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_CNTLX1_PL_BANK_SEL_A = 58;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_CNTLX1_PL_PIPE_MARGIN = 59;
// iohs/reg00055.H

static const uint64_t IOO_RX0_1_RD_5_RX_BIT_REGS_MODE7_PL = 0x8003500f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL = 48;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL_LEN = 2;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO = 50;
static const uint32_t IOO_RX0_1_RD_5_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO_LEN = 10;
// iohs/reg00055.H

static const uint64_t IOO_RX0_1_RD_5_RX_BIT_REGS_STAT1_PL = 0x8003900f10012c3full;
// iohs/reg00055.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX61_PL = 0x8001e80f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010 = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX61_PL_RX_BD_LATCH_DAC_N010_LEN = 9;
// iohs/reg00055.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX71_PL = 0x8002380f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100 = 55;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_LOFF_B_CNTLX71_PL_RX_BD_LATCH_DAC_E100_LEN = 9;
// iohs/reg00055.H

static const uint64_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL2_PL = 0x8000100f10012c3full;

static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL2_PL_NS_DATA = 48;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL2_PL_NS_DATA_LEN = 4;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL2_PL_EW_DATA = 52;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL2_PL_EW_DATA_LEN = 4;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL2_PL_NS_EDGE = 56;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL2_PL_NS_EDGE_LEN = 4;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL2_PL_EW_EDGE = 60;
static const uint32_t IOO_RX0_1_RD_5_RX_DAC_REGS_CNTL2_PL_EW_EDGE_LEN = 4;
// iohs/reg00055.H

static const uint64_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTL6_PL = 0x8003880e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL = 48;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTL6_PL_SAVE_FW_VAL_SEL_LEN = 2;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_A = 50;
static const uint32_t IOO_RX0_2_RD_0_RX_BIT_REGS_CNTL6_PL_R_PSAVE_PH_FORCE_B = 51;
// iohs/reg00055.H

static const uint64_t IOO_RX0_2_RD_0_RX_BIT_REGS_STAT6_PL = 0x8003b80e10012c3full;
// iohs/reg00055.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX20_PL = 0x8000a00e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX20_PL_RX_AE_LATCH_DAC_E_LEN = 9;
// iohs/reg00055.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX30_PL = 0x8000f00e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011 = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX30_PL_RX_AD_LATCH_DAC_N011_LEN = 9;
// iohs/reg00055.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX40_PL = 0x8001400e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101 = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX40_PL_RX_AD_LATCH_DAC_E101_LEN = 9;
// iohs/reg00055.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX50_PL = 0x8001900e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111 = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_A_CNTLX50_PL_RX_AD_LATCH_DAC_S111_LEN = 9;
// iohs/reg00055.H

static const uint64_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX87_PL = 0x8002b80e10012c3full;

static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100 = 55;
static const uint32_t IOO_RX0_2_RD_0_RX_DAC_REGS_LOFF_B_CNTLX87_PL_RX_BD_LATCH_DAC_W100_LEN = 9;
// iohs/reg00055.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX67_PL = 0x8002180d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000 = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX67_PL_RX_BD_LATCH_DAC_E000_LEN = 9;
// iohs/reg00055.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX77_PL = 0x8002680d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010 = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_LOFF_B_CNTLX77_PL_RX_BD_LATCH_DAC_S010_LEN = 9;
// iohs/reg00055.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL5_PL = 0x8000280d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL5_PL_NS_DATA = 48;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL5_PL_NS_DATA_LEN = 4;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL5_PL_EW_DATA = 52;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL5_PL_EW_DATA_LEN = 4;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL5_PL_NS_EDGE = 56;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL5_PL_NS_EDGE_LEN = 4;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL5_PL_EW_EDGE = 60;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTL5_PL_EW_EDGE_LEN = 4;
// iohs/reg00055.H

static const uint64_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTLX9_PL = 0x8000480d10012c3full;

static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL = 48;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTLX9_PL_A_SPEC_MUX_SEL_LEN = 7;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL = 55;
static const uint32_t IOO_RX0_2_RD_1_RX_DAC_REGS_CNTLX9_PL_B_SPEC_MUX_SEL_LEN = 7;
// iohs/reg00055.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX35_PL = 0x8001180c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX35_PL_RX_AD_LATCH_DAC_E000_LEN = 9;
// iohs/reg00055.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX45_PL = 0x8001680c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX45_PL_RX_AD_LATCH_DAC_S010_LEN = 9;
// iohs/reg00055.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX55_PL = 0x8001b80c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_A_CNTLX55_PL_RX_AD_LATCH_DAC_W100_LEN = 9;
// iohs/reg00055.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX59_PL = 0x8001d80c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX59_PL_RX_BD_LATCH_DAC_N000_LEN = 9;
// iohs/reg00055.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX69_PL = 0x8002280c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX69_PL_RX_BD_LATCH_DAC_E010_LEN = 9;
// iohs/reg00055.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX79_PL = 0x8002780c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX79_PL_RX_BD_LATCH_DAC_S100_LEN = 9;
// iohs/reg00055.H

static const uint64_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX82_PL = 0x8002900c10012c3full;

static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111 = 55;
static const uint32_t IOO_RX0_2_RD_RX_DAC_REGS_LOFF_B_CNTLX82_PL_RX_BD_LATCH_DAC_S111_LEN = 9;
// iohs/reg00055.H

static const uint64_t IOO_RX0_2_RD_3_RX_BIT_REGS_MODE7_PL = 0x8003500b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL = 48;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_MODE7_PL_SAVE_CDRLOCK_MODE_SEL_LEN = 2;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO = 50;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_MODE7_PL_R_UNLOCK_RATIO_LEN = 10;
// iohs/reg00055.H

static const uint64_t IOO_RX0_2_RD_3_RX_BIT_REGS_STAT1_PL = 0x8003900b10012c3full;
// iohs/reg00055.H

static const uint64_t IOO_RX0_2_RD_3_RX_BIT_REGS_FIR_MASK_PL = 0x8003100b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK = 48;
static const uint32_t IOO_RX0_2_RD_3_RX_BIT_REGS_FIR_MASK_PL_RX_PL_FIR_ERRS_MASK_LEN = 3;
// iohs/reg00055.H

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX62_PL = 0x8001f00b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011 = 55;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX62_PL_RX_BD_LATCH_DAC_N011_LEN = 9;
// iohs/reg00055.H

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX72_PL = 0x8002400b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101 = 55;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX72_PL_RX_BD_LATCH_DAC_E101_LEN = 9;
// iohs/reg00055.H

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX89_PL = 0x8002c80b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110 = 55;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_LOFF_B_CNTLX89_PL_RX_BD_LATCH_DAC_W110_LEN = 9;
// iohs/reg00055.H

static const uint64_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL18_PL = 0x8000900b10012c3full;

static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL18_PL_DATA = 48;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL18_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL18_PL_EDGE = 54;
static const uint32_t IOO_RX0_2_RD_3_RX_DAC_REGS_CNTL18_PL_EDGE_LEN = 5;
// iohs/reg00055.H

static const uint64_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL3_PL = 0x8003700a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL3_PL_IORESET = 48;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL3_PL_IODOM_IORESET = 49;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_A = 50;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL3_PL_PR_FW_RESET_B = 51;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_A = 52;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL3_PL_PR_BIT_LOCK_DONE_B = 53;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL3_PL_BERPL_PRBS_SEED_MODE = 54;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_EN = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK = 57;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL3_PL_ERR_TRAP_MASK_LEN = 4;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR = 61;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_CNTL3_PL_BIAS_COUNTER_AGING_FACTOR_LEN = 3;
// iohs/reg00055.H

static const uint64_t IOO_RX0_2_RD_4_RX_BIT_REGS_MODE5_PL = 0x8003400a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE = 48;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_MODE5_PL_FW_INERTIA_AMT_COARSE_LEN = 4;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE = 56;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_MODE5_PL_PHASE_STEP_COARSE_LEN = 7;
// iohs/reg00055.H

static const uint64_t IOO_RX0_2_RD_4_RX_BIT_REGS_STAT3_PL = 0x8003a00a10012c3full;
// iohs/reg00055.H

static const uint64_t IOO_RX0_2_RD_4_RX_BIT_REGS_SPARE_MODE_PL = 0x8003000a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_SPARE_MODE_PL_0 = 48;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_SPARE_MODE_PL_1 = 49;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_SPARE_MODE_PL_2 = 50;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_SPARE_MODE_PL_3 = 51;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_SPARE_MODE_PL_4 = 52;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_SPARE_MODE_PL_5 = 53;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_SPARE_MODE_PL_6 = 54;
static const uint32_t IOO_RX0_2_RD_4_RX_BIT_REGS_SPARE_MODE_PL_7 = 55;
// iohs/reg00055.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX21_PL = 0x8000a80a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX21_PL_RX_AE_LATCH_DAC_S_LEN = 9;
// iohs/reg00055.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX31_PL = 0x8000f80a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100 = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX31_PL_RX_AD_LATCH_DAC_N100_LEN = 9;
// iohs/reg00055.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX41_PL = 0x8001480a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110 = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX41_PL_RX_AD_LATCH_DAC_E110_LEN = 9;
// iohs/reg00055.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX51_PL = 0x8001980a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000 = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_A_CNTLX51_PL_RX_AD_LATCH_DAC_W000_LEN = 9;
// iohs/reg00055.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX86_PL = 0x8002b00a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011 = 55;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_LOFF_B_CNTLX86_PL_RX_BD_LATCH_DAC_W011_LEN = 9;
// iohs/reg00055.H

static const uint64_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL17_PL = 0x8000880a10012c3full;

static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL17_PL_DATA = 48;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL17_PL_DATA_LEN = 5;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL17_PL_EDGE = 54;
static const uint32_t IOO_RX0_2_RD_4_RX_DAC_REGS_CNTL17_PL_EDGE_LEN = 5;
// iohs/reg00055.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX26_PL = 0x8000d00910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX26_PL_RX_BE_LATCH_DAC_W_LEN = 9;
// iohs/reg00055.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX66_PL = 0x8002100910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111 = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX66_PL_RX_BD_LATCH_DAC_N111_LEN = 9;
// iohs/reg00055.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX76_PL = 0x8002600910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001 = 55;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_LOFF_B_CNTLX76_PL_RX_BD_LATCH_DAC_S001_LEN = 9;
// iohs/reg00055.H

static const uint64_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL11_PL = 0x8000580910012c3full;

static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL11_PL_TERM_PD = 48;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL11_PL_FREQ_ADJUST = 49;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL11_PL_FREQ_ADJUST_LEN = 5;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL11_PL_OFF_CM = 54;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL11_PL_OFF_CM_LEN = 4;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL11_PL_OFF_DM = 58;
static const uint32_t IOO_RX0_2_RD_5_RX_DAC_REGS_CNTL11_PL_OFF_DM_LEN = 6;
// iohs/reg00056.H

static const uint64_t IOO_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG = 0x800c040010012c3full;

static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_0 = 48;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_1 = 49;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_2 = 50;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_3 = 51;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_4 = 52;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_5 = 53;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_6 = 54;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_7 = 55;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_8_9 = 56;
static const uint32_t IOO_TX0_TXCTL_CTL_REGS_TX_SPARE_MODE_PG_8_9_LEN = 2;
// iohs/reg00056.H

static const uint64_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL10_PG = 0x800d0c0010012c3full;

static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL10_PG_2 = 48;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL10_PG_2_LEN = 6;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL10_PG_3 = 54;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL10_PG_3_LEN = 6;
// iohs/reg00056.H

static const uint64_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_FIR_MASK_PG = 0x800c8c0010012c3full;

static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_FIR_MASK_PG_TX_PG_FIR_ERRS_MASK = 48;
static const uint32_t IOO_TX0_TXCTL_TX_CTL_SM_REGS_FIR_MASK_PG_TX_PG_FIR_ERRS_MASK_LEN = 5;
// iohs/reg00056.H

static const uint64_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL10_PL = 0x80047c0010012c3full;

static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN = 48;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN = 16;
// iohs/reg00056.H

static const uint64_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL20_PL = 0x8004cc0010012c3full;

static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL20_PL_EN = 51;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL20_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL20_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL20_PL_SEL_LEN = 5;
// iohs/reg00056.H

static const uint64_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL30_PL = 0x80051c0010012c3full;

static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE = 48;
// iohs/reg00056.H

static const uint64_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL4_PL = 0x80044c0010012c3full;

static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL4_PL_EN = 51;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL4_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL4_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_CNTL4_PL_SEL_LEN = 5;
// iohs/reg00056.H

static const uint64_t IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL = 0x8004240010012c3full;

static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY = 48;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_L2U_DLY_LEN = 3;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_CLK_DISABLE = 56;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_RXCAL = 57;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL = 58;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_UNLOAD_SEL_LEN = 3;
static const uint32_t IOO_TX0_0_DD_TX_BIT_REGS_MODE2_PL_FIFO_HOLD = 61;
// iohs/reg00056.H

static const uint64_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL9_PL = 0x8004740110012c3full;

static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN = 48;
static const uint32_t IOO_TX0_0_DD_1_TX_BIT_REGS_CNTL9_PL_TX_PSEG_MAIN_16_18_HS_EN_LEN = 3;
// iohs/reg00056.H

static const uint64_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL16_PL = 0x8004ac0310012c3full;

static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL16_PL_I_TUNE = 48;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL16_PL_I_TUNE_LEN = 6;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL16_PL_Q_TUNE = 54;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL16_PL_Q_TUNE_LEN = 6;
// iohs/reg00056.H

static const uint64_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL26_PL = 0x8004fc0310012c3full;

static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN = 48;
static const uint32_t IOO_TX0_0_DD_3_TX_BIT_REGS_CNTL26_PL_TX_NSEG_MAIN_16_18_SAFE_EN_LEN = 3;
// iohs/reg00056.H

static const uint64_t IOO_TX0_0_DD_4_TX_BIT_REGS_FIR_MASK_PL = 0x80040c0410012c3full;

static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK = 48;
static const uint32_t IOO_TX0_0_DD_4_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN = 2;
// iohs/reg00056.H

static const uint64_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL11_PL = 0x8004840510012c3full;

static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN = 48;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN_LEN = 3;
// iohs/reg00056.H

static const uint64_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL1G_PL = 0x8004340510012c3full;
// iohs/reg00056.H

static const uint64_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL21_PL = 0x8004d40510012c3full;

static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL21_PL_EN = 51;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL21_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL21_PL_SEL = 56;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL21_PL_SEL_LEN = 5;
// iohs/reg00056.H

static const uint64_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL3_PL = 0x8004440510012c3full;

static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE = 48;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE = 49;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE = 50;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR = 51;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE = 52;
static const uint32_t IOO_TX0_0_DD_5_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE = 53;
// iohs/reg00056.H

static const uint64_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL11_PL = 0x8004840610012c3full;

static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN = 48;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL11_PL_TX_NSEG_MAIN_16_18_HS_EN_LEN = 3;
// iohs/reg00056.H

static const uint64_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL1G_PL = 0x8004340610012c3full;
// iohs/reg00056.H

static const uint64_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL21_PL = 0x8004d40610012c3full;

static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL21_PL_EN = 51;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL21_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL21_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_CNTL21_PL_SEL_LEN = 5;
// iohs/reg00056.H

static const uint64_t IOO_TX0_1_DD_0_TX_BIT_REGS_FIR_ERROR_INJECT_PL = 0x8004140610012c3full;

static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ = 48;
static const uint32_t IOO_TX0_1_DD_0_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ_LEN = 2;
// iohs/reg00056.H

static const uint64_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL7_PL = 0x8004640710012c3full;

static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL7_PL_EN = 51;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL7_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL7_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_CNTL7_PL_SEL_LEN = 5;
// iohs/reg00056.H

static const uint64_t IOO_TX0_1_DD_TX_BIT_REGS_MODE1_PL = 0x80041c0710012c3full;

static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_MODE1_PL_LANE_PDWN = 48;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_MODE1_PL_LANE_INVERT = 49;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE = 50;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_MODE1_PL_LANE_QUIESCE_LEN = 2;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_MODE1_PL_MAIN_PKG_EN = 52;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_MODE1_PL_FFE_PKG_EN = 53;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_MODE1_PL_PSAVE_REQ_DIS = 54;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_A_ENABLE = 55;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_MODE1_PL_ERR_INJ_B_ENABLE = 56;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_0 = 60;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_1 = 61;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_2 = 62;
static const uint32_t IOO_TX0_1_DD_TX_BIT_REGS_MODE1_PL_PL_SPARE_MODE_3 = 63;
// iohs/reg00056.H

static const uint64_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL3_PL = 0x8004440810012c3full;

static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL3_PL_TDR_ENABLE = 48;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL3_PL_PATTERN_ENABLE = 49;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_ENABLE = 50;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL3_PL_BIST_PRBS_CLEAR = 51;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL3_PL_RXDET_ENABLE = 52;
static const uint32_t IOO_TX0_1_DD_2_TX_BIT_REGS_CNTL3_PL_RXDET_PULSE = 53;
// iohs/reg00056.H

static const uint64_t IOO_TX0_1_DD_2_TX_BIT_REGS_FIR_PL = 0x8004040810012c3full;
// iohs/reg00056.H

static const uint64_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL17_PL = 0x8004b41110012c3full;

static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_EN = 48;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL = 49;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL17_PL_BIST_HS_CUST_SEL_LEN = 3;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE = 52;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL17_PL_DCC_IQ_TUNE_LEN = 5;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL17_PL_DCC_PAT = 57;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL17_PL_DCC_PAT_LEN = 4;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL17_PL_DCC_AZ = 61;
// iohs/reg00056.H

static const uint64_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL27_PL = 0x8005041110012c3full;

static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL27_PL_EN = 49;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL27_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL27_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_3_TX_BIT_REGS_CNTL27_PL_SEL_LEN = 7;
// iohs/reg00056.H

static const uint64_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL10_PL = 0x80047c0f10012c3full;

static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN = 48;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL10_PL_TX_NSEG_MAIN_0_15_HS_EN_LEN = 16;
// iohs/reg00056.H

static const uint64_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL20_PL = 0x8004cc0f10012c3full;

static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL20_PL_EN = 51;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL20_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL20_PL_SEL = 56;
static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL20_PL_SEL_LEN = 5;
// iohs/reg00056.H

static const uint64_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL30_PL = 0x80051c0f10012c3full;

static const uint32_t IOO_TX0_1_DD_5_TX_BIT_REGS_CNTL30_PL_TX_FORCE_HS_FFE = 48;
// iohs/reg00056.H

static const uint64_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL19_PL = 0x8004c40e10012c3full;

static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL19_PL_EN = 51;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL19_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL19_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL19_PL_SEL_LEN = 5;
// iohs/reg00056.H

static const uint64_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL29_PL = 0x8005140e10012c3full;

static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN = 48;
static const uint32_t IOO_TX0_2_DD_0_TX_BIT_REGS_CNTL29_PL_TX_ATTEN_SAFE_EN_LEN = 16;
// iohs/reg00056.H

static const uint64_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL13_PL = 0x8004940d10012c3full;

static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL13_PL_EN = 49;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL13_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL13_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL13_PL_SEL_LEN = 7;
// iohs/reg00056.H

static const uint64_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL23_PL = 0x8004e40d10012c3full;

static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL23_PL_TX_PSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// iohs/reg00056.H

static const uint64_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL6_PL = 0x80045c0d10012c3full;

static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL6_PL_EN = 51;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL6_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL6_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_1_TX_BIT_REGS_CNTL6_PL_SEL_LEN = 5;
// iohs/reg00056.H

static const uint64_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL15_PL = 0x8004a40c10012c3full;

static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL = 48;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_VAL_LEN = 4;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL15_PL_EL_UNLOAD_TIMER_DOUBLE_MODE = 52;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL15_PL_ISABLE_PL_SM = 53;
// iohs/reg00056.H

static const uint64_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL25_PL = 0x8004f40c10012c3full;

static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN = 48;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL25_PL_TX_NSEG_MAIN_0_15_SAFE_EN_LEN = 16;
// iohs/reg00056.H

static const uint64_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL2_PL = 0x80043c0c10012c3full;

static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL2_PL_RESET = 48;
static const uint32_t IOO_TX0_2_DD_TX_BIT_REGS_CNTL2_PL_DOM_IORESET = 49;
// iohs/reg00056.H

static const uint64_t IOO_TX0_2_DD_3_TX_BIT_REGS_FIR_MASK_PL = 0x80040c0b10012c3full;

static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK = 48;
static const uint32_t IOO_TX0_2_DD_3_TX_BIT_REGS_FIR_MASK_PL_TX_PL_FIR_ERRS_MASK_LEN = 2;
// iohs/reg00056.H

static const uint64_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL12_PL = 0x80048c0a10012c3full;

static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL12_PL_EN = 49;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL12_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL12_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL12_PL_SEL_LEN = 7;
// iohs/reg00056.H

static const uint64_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL22_PL = 0x8004dc0a10012c3full;

static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL22_PL_EN = 51;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL22_PL_EN_LEN = 5;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL22_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_CNTL22_PL_SEL_LEN = 5;
// iohs/reg00056.H

static const uint64_t IOO_TX0_2_DD_4_TX_BIT_REGS_STAT1_PL = 0x8005240a10012c3full;

static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS = 50;
static const uint32_t IOO_TX0_2_DD_4_TX_BIT_REGS_STAT1_PL_TX_SEG_TEST_STATUS_LEN = 2;
// iohs/reg00056.H

static const uint64_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL18_PL = 0x8004bc0910012c3full;

static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN = 48;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL18_PL_TX_ATTEN_HS_EN_LEN = 16;
// iohs/reg00056.H

static const uint64_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL28_PL = 0x80050c0910012c3full;

static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL28_PL_EN = 49;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL28_PL_EN_LEN = 7;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL28_PL_SEL = 56;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_CNTL28_PL_SEL_LEN = 7;
// iohs/reg00056.H

static const uint64_t IOO_TX0_2_DD_5_TX_BIT_REGS_FIR_ERROR_INJECT_PL = 0x8004140910012c3full;

static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ = 48;
static const uint32_t IOO_TX0_2_DD_5_TX_BIT_REGS_FIR_ERROR_INJECT_PL_TX_PL_FIR_ERR_INJ_LEN = 2;
// iohs/reg00056.H

static const uint64_t IOO_TX0_2_DD_5_TX_BIT_REGS_FIR_PL = 0x8004040910012c3full;
// iohs/reg00056.H

static const uint64_t MULTICAST_GROUP_4 = 0x180f0004ull;

static const uint32_t MULTICAST_GROUP_4_MULTICAST4_GROUP = 3;
static const uint32_t MULTICAST_GROUP_4_MULTICAST4_GROUP_LEN = 3;
// iohs/reg00056.H

static const uint64_t PRE_COUNTER_REG = 0x180f0028ull;

static const uint32_t PRE_COUNTER_REG_PRE_COUNTER = 0;
static const uint32_t PRE_COUNTER_REG_PRE_COUNTER_LEN = 8;
// iohs/reg00056.H

static const uint64_t REGS_PRX1_DLR_APCR = 0x1801103cull;
// iohs/reg00056.H

static const uint64_t XSTOP_INTERRUPT_REG = 0x180f001cull;
// iohs/reg00056.H

#ifndef __PPE_HCODE__
}
}
#include "iohs/reg00053.H"
#include "iohs/reg00054.H"
#include "iohs/reg00055.H"
#include "iohs/reg00056.H"
#endif
#endif
