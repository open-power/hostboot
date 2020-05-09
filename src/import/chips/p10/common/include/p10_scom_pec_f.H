/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pec_f.H $        */
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

#ifndef __p10_scom_pec_f_H_
#define __p10_scom_pec_f_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace pec
{
#endif


//>> [BIST]
static const uint64_t BIST = 0x0803000bull;

static const uint32_t BIST_TC_BIST_START_TEST_DC = 0;
static const uint32_t BIST_TC_SRAM_ABIST_MODE_DC = 1;
static const uint32_t BIST_TC_IOBIST_MODE_DC = 3;
static const uint32_t BIST_REGION_PERV = 4;
static const uint32_t BIST_REGION_UNIT1 = 5;
static const uint32_t BIST_REGION_UNIT2 = 6;
static const uint32_t BIST_REGION_UNIT3 = 7;
static const uint32_t BIST_REGION_UNIT4 = 8;
static const uint32_t BIST_REGION_UNIT5 = 9;
static const uint32_t BIST_REGION_UNIT6 = 10;
static const uint32_t BIST_REGION_UNIT7 = 11;
static const uint32_t BIST_REGION_UNIT8 = 12;
static const uint32_t BIST_REGION_UNIT9 = 13;
static const uint32_t BIST_REGION_UNIT10 = 14;
static const uint32_t BIST_REGION_UNIT11 = 15;
static const uint32_t BIST_REGION_UNIT12 = 16;
static const uint32_t BIST_REGION_UNIT13 = 17;
static const uint32_t BIST_REGION_UNIT14 = 18;
static const uint32_t BIST_STROBE_WINDOW_EN = 48;
//<< [BIST]
// pec/reg00015.H

//>> [CPLT_CTRL5]
static const uint64_t CPLT_CTRL5_RW = 0x08000005ull;
static const uint64_t CPLT_CTRL5_WO_CLEAR = 0x08000025ull;
static const uint64_t CPLT_CTRL5_WO_OR = 0x08000015ull;

static const uint32_t CPLT_CTRL5_TC_CCFG_PMA0_MUX_SEL_DC = 0;
static const uint32_t CPLT_CTRL5_TC_CCFG_PMA1_MUX_SEL_DC = 1;
static const uint32_t CPLT_CTRL5_TC_CCFG_PMA2_MUX_SEL_DC = 2;
static const uint32_t CPLT_CTRL5_TC_CCFG_PMA3_MUX_SEL_DC = 3;
static const uint32_t CPLT_CTRL5_TC_CCFG_PCS01_MUX_SEL_DC = 4;
static const uint32_t CPLT_CTRL5_TC_CCFG_PCS23_MUX_SEL_DC = 5;
static const uint32_t CPLT_CTRL5_TC_CCFG_PIPE_LANEX_EXT_PLL_MODE_DC = 6;
static const uint32_t CPLT_CTRL5_TC_CCFG_PHYX_CR_PARA_SEL_DC = 7;
static const uint32_t CPLT_CTRL5_TC_CCFG_PHY_EXT_CTRL_SEL_DC = 8;
static const uint32_t CPLT_CTRL5_09 = 9;
static const uint32_t CPLT_CTRL5_010 = 10;
static const uint32_t CPLT_CTRL5_011 = 11;
static const uint32_t CPLT_CTRL5_012 = 12;
static const uint32_t CPLT_CTRL5_013 = 13;
static const uint32_t CPLT_CTRL5_014 = 14;
static const uint32_t CPLT_CTRL5_015 = 15;
static const uint32_t CPLT_CTRL5_016 = 16;
static const uint32_t CPLT_CTRL5_017 = 17;
static const uint32_t CPLT_CTRL5_018 = 18;
static const uint32_t CPLT_CTRL5_019 = 19;
//<< [CPLT_CTRL5]
// pec/reg00015.H

//>> [EPS_FIR_CLKSTOP_ON_XSTOP_MASK2]
static const uint64_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2 = 0x08040082ull;

static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_XSTOP_ERR = 0;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_RECOV_ERR = 1;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SPATTN_ERR = 2;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_LXSTOP_ERR = 3;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_HOSTATTN_ERR = 4;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SYS_XSTOP_ERR = 5;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK2_SYS_XSTOP_STAGED_ERR = 6;
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
//<< [EPS_FIR_CLKSTOP_ON_XSTOP_MASK2]
// pec/reg00015.H

//>> [EPS_THERM_WSUB_DTS_RESULT0]
static const uint64_t EPS_THERM_WSUB_DTS_RESULT0 = 0x08050000ull;

static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_0_RESULT = 0;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_0_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_1_RESULT = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_1_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_2_RESULT = 32;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_2_RESULT_LEN = 16;
//<< [EPS_THERM_WSUB_DTS_RESULT0]
// pec/reg00015.H

//>> [MULTICAST_GROUP_3]
static const uint64_t MULTICAST_GROUP_3 = 0x080f0003ull;

static const uint32_t MULTICAST_GROUP_3_MULTICAST3_GROUP = 3;
static const uint32_t MULTICAST_GROUP_3_MULTICAST3_GROUP_LEN = 3;
//<< [MULTICAST_GROUP_3]
// pec/reg00015.H

//>> [PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG]
static const uint64_t PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG = 0x03011811ull;

static const uint32_t PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_PE_WRITE_PACING_MODE = 0;
static const uint32_t PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_PE_WRITE_PACING_MODE_LEN = 2;
static const uint32_t PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_PE_WRITE_PACING_DISABLE_SCOPE = 2;
static const uint32_t PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_RESERVED_03 = 3;
static const uint32_t PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_PE_WRITE_PACING_GROUP_MIN_CYCLES = 4;
static const uint32_t PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_PE_WRITE_PACING_GROUP_MIN_CYCLES_LEN = 4;
static const uint32_t PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_PE_WRITE_PACING_GROUP_MAX_CYCLES = 8;
static const uint32_t PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_PE_WRITE_PACING_GROUP_MAX_CYCLES_LEN = 4;
static const uint32_t PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_PE_WRITE_PACING_SYSTEM_MIN_CYCLES = 12;
static const uint32_t PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_PE_WRITE_PACING_SYSTEM_MIN_CYCLES_LEN = 4;
static const uint32_t PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_PE_WRITE_PACING_SYSTEM_MAX_CYCLES = 16;
static const uint32_t PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_PE_WRITE_PACING_SYSTEM_MAX_CYCLES_LEN = 4;
static const uint32_t PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_PE_WRITE_PACING_NUM_OF_CLEAN_RANGES = 20;
static const uint32_t PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_PE_WRITE_PACING_NUM_OF_CLEAN_RANGES_LEN = 4;
static const uint32_t PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_PE_WRITE_PACING_NUM_OF_HPCACK = 24;
static const uint32_t PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG_PE_WRITE_PACING_NUM_OF_HPCACK_LEN = 4;
//<< [PB_PBCQ_PEPBREGS_PE_WRITE_PACING_REG]
// pec/reg00015.H

//>> [PROTECT_MODE_REG]
static const uint64_t PROTECT_MODE_REG = 0x080f03feull;

static const uint32_t PROTECT_MODE_REG_READ_PROTECT_ENABLE = 0;
static const uint32_t PROTECT_MODE_REG_WRITE_PROTECT_ENABLE = 1;
//<< [PROTECT_MODE_REG]
// pec/reg00015.H

//>> [TIMEOUT_REG]
static const uint64_t TIMEOUT_REG = 0x080f0010ull;

static const uint32_t TIMEOUT_REG_INT_TIMEOUT = 0;
static const uint32_t TIMEOUT_REG_INT_TIMEOUT_LEN = 2;
//<< [TIMEOUT_REG]
// pec/reg00015.H

//>> [TRA0_TR0_CONFIG_1]
static const uint64_t TRA0_TR0_CONFIG_1 = 0x08010404ull;

static const uint32_t TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
//<< [TRA0_TR0_CONFIG_1]
// pec/reg00015.H

//>> [VITAL_SCAN_OUT]
static const uint64_t VITAL_SCAN_OUT = 0x080f0017ull;
//<< [VITAL_SCAN_OUT]
// pec/reg00015.H

//>> [XSTOP_UNMASKED]
static const uint64_t XSTOP_UNMASKED = 0x08040010ull;

static const uint32_t XSTOP_UNMASKED_IN = 1;
static const uint32_t XSTOP_UNMASKED_IN_LEN = 53;
//<< [XSTOP_UNMASKED]
// pec/reg00015.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "pec/reg00015.H"
#endif
#endif
