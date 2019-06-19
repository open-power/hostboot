/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mc_f.H $         */
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

#ifndef __p10_scom_mc_f_H_
#define __p10_scom_mc_f_H_


namespace scomt
{
namespace mc
{


static const uint64_t BIST = 0x0c03000bull;

static const uint32_t BIST_TC_BIST_START_TEST_DC = 0;
static const uint32_t BIST_TC_SRAM_ABIST_MODE_DC = 1;
static const uint32_t BIST_TC_IOBIST_MODE_DC = 3;
static const uint32_t BIST_BIST_PERV = 4;
static const uint32_t BIST_BIST_UNIT1 = 5;
static const uint32_t BIST_BIST_UNIT2 = 6;
static const uint32_t BIST_BIST_UNIT3 = 7;
static const uint32_t BIST_BIST_UNIT4 = 8;
static const uint32_t BIST_BIST_UNIT5 = 9;
static const uint32_t BIST_BIST_UNIT6 = 10;
static const uint32_t BIST_BIST_UNIT7 = 11;
static const uint32_t BIST_BIST_UNIT8 = 12;
static const uint32_t BIST_BIST_UNIT9 = 13;
static const uint32_t BIST_BIST_UNIT10 = 14;
static const uint32_t BIST_BIST_UNIT11 = 15;
static const uint32_t BIST_BIST_UNIT12 = 16;
static const uint32_t BIST_BIST_UNIT13 = 17;
static const uint32_t BIST_BIST_UNIT14 = 18;
static const uint32_t BIST_BIST_STROBE_WINDOW_EN = 48;
// mc/reg00015.H

static const uint64_t CPLT_CTRL5_RW = 0x0c000005ull;
static const uint64_t CPLT_CTRL5_WO_CLEAR = 0x0c000025ull;
static const uint64_t CPLT_CTRL5_WO_OR = 0x0c000015ull;

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
// mc/reg00015.H

static const uint64_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2 = 0x0c040082ull;

static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_XSTOP_ERR = 0;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_RECOV_ERR = 1;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SPATTN_ERR = 2;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_LXSTOP_ERR = 3;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_HOSTATTN_ERR = 4;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SYS_XSTOP_ERR = 5;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_OOB1_ERR = 6;
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
// mc/reg00015.H

static const uint64_t EPS_THERM_WSUB_DTS_RESULT0 = 0x0c050000ull;

static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_0_RESULT = 0;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_0_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_1_RESULT = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_1_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_2_RESULT = 32;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_2_RESULT_LEN = 16;
// mc/reg00015.H

static const uint64_t MBA_SCOMFIR_MCDBG_SCOM_CFG = 0x0c010f98ull;

static const uint32_t MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM01 = 0;
static const uint32_t MBA_SCOMFIR_MCDBG_SCOM_CFG_01_OR_ENABLE = 1;
static const uint32_t MBA_SCOMFIR_MCDBG_SCOM_CFG_ACT_SCOM23 = 2;
static const uint32_t MBA_SCOMFIR_MCDBG_SCOM_CFG_23_OR_ENABLE = 3;
// mc/reg00015.H

static const uint64_t MBA_SCOMFIR_WATCFG0BQ = 0x0c010f81ull;

static const uint32_t MBA_SCOMFIR_WATCFG0BQ_MSKA = 0;
static const uint32_t MBA_SCOMFIR_WATCFG0BQ_MSKA_LEN = 44;
static const uint32_t MBA_SCOMFIR_WATCFG0BQ_CNTL = 44;
static const uint32_t MBA_SCOMFIR_WATCFG0BQ_CNTL_LEN = 17;
// mc/reg00015.H

static const uint64_t MBA_SCOMFIR_WATCFG1EQ = 0x0c010f89ull;

static const uint32_t MBA_SCOMFIR_WATCFG1EQ_WATCFG1EQ_CFG_WAT_PATB = 0;
static const uint32_t MBA_SCOMFIR_WATCFG1EQ_WATCFG1EQ_CFG_WAT_PATB_LEN = 44;
// mc/reg00015.H

static const uint64_t MULTICAST_GROUP_3 = 0x0c0f0003ull;

static const uint32_t MULTICAST_GROUP_3_MULTICAST3_GROUP = 3;
static const uint32_t MULTICAST_GROUP_3_MULTICAST3_GROUP_LEN = 3;
// mc/reg00015.H

static const uint64_t PROTECT_MODE_REG = 0x0c0f03feull;

static const uint32_t PROTECT_MODE_REG_READ_PROTECT_ENABLE = 0;
static const uint32_t PROTECT_MODE_REG_WRITE_PROTECT_ENABLE = 1;
// mc/reg00015.H

static const uint64_t SCOMFIR_AADR = 0x0c010c2dull;

static const uint32_t SCOMFIR_AADR_AADR_DATA = 0;
static const uint32_t SCOMFIR_AADR_AADR_DATA_LEN = 64;
// mc/reg00015.H

static const uint64_t SCOMFIR_MCERPT2 = 0x0c010c1aull;

static const uint32_t SCOMFIR_MCERPT2_CAR3_SMF_ERROR = 0;
static const uint32_t SCOMFIR_MCERPT2_COLL_0_ERROR = 1;
static const uint32_t SCOMFIR_MCERPT2_COLL_1_ERROR = 2;
static const uint32_t SCOMFIR_MCERPT2_OP_HIT_0_ERROR = 3;
static const uint32_t SCOMFIR_MCERPT2_OP_HIT_1_ERROR = 4;
static const uint32_t SCOMFIR_MCERPT2_RTAG_0_ARRAY_PARITY_ERROR = 5;
static const uint32_t SCOMFIR_MCERPT2_RTAG_1_ARRAY_PARITY_ERROR = 6;
static const uint32_t SCOMFIR_MCERPT2_MCFGP0A_PARITY_ERROR = 7;
static const uint32_t SCOMFIR_MCERPT2_MCFGP1A_PARITY_ERROR = 8;
static const uint32_t SCOMFIR_MCERPT2_MCMODE3_PARITY_ERROR = 9;
static const uint32_t SCOMFIR_MCERPT2_MCFGPR0_BAD_TTYPE = 11;
static const uint32_t SCOMFIR_MCERPT2_MCFGPR1_BAD_TTYPE = 12;
static const uint32_t SCOMFIR_MCERPT2_MCFGPM0A_PARITY_ERROR = 17;
static const uint32_t SCOMFIR_MCERPT2_MCFGPM1A_PARITY_ERROR = 18;
static const uint32_t SCOMFIR_MCERPT2_POP_RCMD0_NOHIT = 19;
static const uint32_t SCOMFIR_MCERPT2_POP_RCMD1_NOHIT = 20;
static const uint32_t SCOMFIR_MCERPT2_POP_RCMD2_NOHIT = 21;
static const uint32_t SCOMFIR_MCERPT2_POP_RCMD3_NOHIT = 22;
static const uint32_t SCOMFIR_MCERPT2_POP_RCMD0_BADHIT = 23;
static const uint32_t SCOMFIR_MCERPT2_POP_RCMD1_BADHIT = 24;
static const uint32_t SCOMFIR_MCERPT2_POP_RCMD2_BADHIT = 25;
static const uint32_t SCOMFIR_MCERPT2_POP_RCMD3_BADHIT = 26;
static const uint32_t SCOMFIR_MCERPT2_MULTISYNC = 27;
static const uint32_t SCOMFIR_MCERPT2_SYNC_WHILE_ACTIVE = 28;
// mc/reg00015.H

static const uint64_t SCOMFIR_MCFGP1E = 0x0c010c17ull;

static const uint32_t SCOMFIR_MCFGP1E_VALID = 0;
static const uint32_t SCOMFIR_MCFGP1E_EXTEND_TO_END_OF_RANGE = 1;
static const uint32_t SCOMFIR_MCFGP1E_LOWER_ADDRESS = 2;
static const uint32_t SCOMFIR_MCFGP1E_LOWER_ADDRESS_LEN = 19;
static const uint32_t SCOMFIR_MCFGP1E_UPPER_ADDRESS = 21;
static const uint32_t SCOMFIR_MCFGP1E_UPPER_ADDRESS_LEN = 19;
// mc/reg00015.H

static const uint64_t SCOMFIR_MCFGPM0A = 0x0c010c21ull;

static const uint32_t SCOMFIR_MCFGPM0A_HOLE_VALID = 0;
static const uint32_t SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS = 1;
static const uint32_t SCOMFIR_MCFGPM0A_HOLE_LOWER_ADDRESS_LEN = 15;
static const uint32_t SCOMFIR_MCFGPM0A_RESERVED_16_21 = 16;
static const uint32_t SCOMFIR_MCFGPM0A_RESERVED_16_21_LEN = 6;
static const uint32_t SCOMFIR_MCFGPM0A_SMF_VALID = 22;
static const uint32_t SCOMFIR_MCFGPM0A_SMF_EXTEND_TO_END_OF_RANGE = 23;
static const uint32_t SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS = 24;
static const uint32_t SCOMFIR_MCFGPM0A_SMF_LOWER_ADDRESS_LEN = 19;
static const uint32_t SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS = 43;
static const uint32_t SCOMFIR_MCFGPM0A_SMF_UPPER_ADDRESS_LEN = 19;
// mc/reg00015.H

static const uint64_t SCOMFIR_MCLFSR = 0x0c010c14ull;

static const uint32_t SCOMFIR_MCLFSR_TRY_LPC_LFSR_SELECT = 0;
static const uint32_t SCOMFIR_MCLFSR_TRY_LPC_LFSR_SELECT_LEN = 2;
static const uint32_t SCOMFIR_MCLFSR_SERVED_2_4 = 2;
static const uint32_t SCOMFIR_MCLFSR_SERVED_2_4_LEN = 3;
// mc/reg00015.H

static const uint64_t TIMEOUT_REG = 0x0c0f0010ull;
// mc/reg00015.H

static const uint64_t TRA0_TR0_CONFIG_1 = 0x0c010404ull;

static const uint32_t TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// mc/reg00015.H

static const uint64_t VITAL_SCAN_OUT = 0x0c0f0017ull;
// mc/reg00015.H

static const uint64_t XSTOP_UNMASKED = 0x0c040010ull;

static const uint32_t XSTOP_UNMASKED_XSTOP_UNMASKED_IN = 1;
static const uint32_t XSTOP_UNMASKED_XSTOP_UNMASKED_IN_LEN = 53;
// mc/reg00015.H

}
}
#ifndef __PPE_HCODE__
    #include "mc/reg00015.H"
#endif
#endif
