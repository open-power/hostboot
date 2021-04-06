/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pec_4.H $        */
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

#ifndef __p10_scom_pec_4_H_
#define __p10_scom_pec_4_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace pec
{
#endif


//>> [CLOCK_STAT_ARY]
static const uint64_t CLOCK_STAT_ARY = 0x0803000aull;

static const uint32_t CLOCK_STAT_ARY_PERV_ARY = 4;
static const uint32_t CLOCK_STAT_ARY_UNIT1_ARY = 5;
static const uint32_t CLOCK_STAT_ARY_UNIT2_ARY = 6;
static const uint32_t CLOCK_STAT_ARY_UNIT3_ARY = 7;
static const uint32_t CLOCK_STAT_ARY_UNIT4_ARY = 8;
static const uint32_t CLOCK_STAT_ARY_UNIT5_ARY = 9;
static const uint32_t CLOCK_STAT_ARY_UNIT6_ARY = 10;
static const uint32_t CLOCK_STAT_ARY_UNIT7_ARY = 11;
static const uint32_t CLOCK_STAT_ARY_UNIT8_ARY = 12;
static const uint32_t CLOCK_STAT_ARY_UNIT9_ARY = 13;
static const uint32_t CLOCK_STAT_ARY_UNIT10_ARY = 14;
static const uint32_t CLOCK_STAT_ARY_UNIT11_ARY = 15;
static const uint32_t CLOCK_STAT_ARY_UNIT12_ARY = 16;
static const uint32_t CLOCK_STAT_ARY_UNIT13_ARY = 17;
static const uint32_t CLOCK_STAT_ARY_UNIT14_ARY = 18;
//<< [CLOCK_STAT_ARY]
// pec/reg00004.H

//>> [OPCG_REG2]
static const uint64_t OPCG_REG2 = 0x08030004ull;

static const uint32_t OPCG_REG2_OPCG_GO2 = 0;
static const uint32_t OPCG_REG2_PRPG_WEIGHTING = 1;
static const uint32_t OPCG_REG2_PRPG_WEIGHTING_LEN = 3;
static const uint32_t OPCG_REG2_PRPG_SEED = 4;
static const uint32_t OPCG_REG2_PRPG_SEED_LEN = 12;
static const uint32_t OPCG_REG2_PRPG_A_VAL = 16;
static const uint32_t OPCG_REG2_PRPG_A_VAL_LEN = 12;
static const uint32_t OPCG_REG2_PRPG_B_VAL = 28;
static const uint32_t OPCG_REG2_PRPG_B_VAL_LEN = 12;
static const uint32_t OPCG_REG2_PRPG_MODE = 40;
static const uint32_t OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_PRIM = 48;
static const uint32_t OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_PRIM_LEN = 4;
static const uint32_t OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_SEC_OR_APERTURE_MASK = 52;
static const uint32_t OPCG_REG2_SM_LBIST_CTRL_WEIGHT_SEL_SEC_OR_APERTURE_MASK_LEN = 4;
static const uint32_t OPCG_REG2_SM_LBIST_CTRL_MODE_SELECT = 56;
static const uint32_t OPCG_REG2_SM_LBIST_CTRL_PRPG_HOLD_MODE = 57;
static const uint32_t OPCG_REG2_SM_LBIST_CTRL_LOCAL_OVERRIDE = 58;
static const uint32_t OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_VALUE = 59;
static const uint32_t OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_SELECT = 60;
static const uint32_t OPCG_REG2_SM_LBIST_CTRL_LOAD_APERTURE_SELECT_LEN = 4;
//<< [OPCG_REG2]
// pec/reg00004.H

//>> [TRA0_TR0_TRACE_LO_DATA_REG]
static const uint64_t TRA0_TR0_TRACE_LO_DATA_REG = 0x08010401ull;

static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TRA0_TR0_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
//<< [TRA0_TR0_TRACE_LO_DATA_REG]
// pec/reg00004.H

//>> [XSTOP1]
static const uint64_t XSTOP1 = 0x0803000cull;

static const uint32_t XSTOP1_ENABLE = 0;
static const uint32_t XSTOP1_WAIT_SNOPA = 1;
static const uint32_t XSTOP1_TRIGGER_OPCG_GO = 2;
static const uint32_t XSTOP1_WAIT_ALWAYS = 3;
static const uint32_t XSTOP1_REGION_PERV = 4;
static const uint32_t XSTOP1_REGION_UNIT1 = 5;
static const uint32_t XSTOP1_REGION_UNIT2 = 6;
static const uint32_t XSTOP1_REGION_UNIT3 = 7;
static const uint32_t XSTOP1_REGION_UNIT4 = 8;
static const uint32_t XSTOP1_REGION_UNIT5 = 9;
static const uint32_t XSTOP1_REGION_UNIT6 = 10;
static const uint32_t XSTOP1_REGION_UNIT7 = 11;
static const uint32_t XSTOP1_REGION_UNIT8 = 12;
static const uint32_t XSTOP1_REGION_UNIT9 = 13;
static const uint32_t XSTOP1_REGION_UNIT10 = 14;
static const uint32_t XSTOP1_REGION_UNIT11 = 15;
static const uint32_t XSTOP1_REGION_UNIT12 = 16;
static const uint32_t XSTOP1_REGION_UNIT13 = 17;
static const uint32_t XSTOP1_REGION_UNIT14 = 18;
static const uint32_t XSTOP1_WAIT_CYCLES = 48;
static const uint32_t XSTOP1_WAIT_CYCLES_LEN = 12;
//<< [XSTOP1]
// pec/reg00004.H

//>> [TOP1_IOPFIRMASK]
static const uint64_t TOP1_IOPFIRMASK_RW = 0x08011503ull;
static const uint64_t TOP1_IOPFIRMASK_WO_AND = 0x08011504ull;
static const uint64_t TOP1_IOPFIRMASK_WO_OR = 0x08011505ull;

static const uint32_t TOP1_IOPFIRMASK_PHY0_ECC_CE_MASK = 0;
static const uint32_t TOP1_IOPFIRMASK_PHY0_ECC_UE_MASK = 1;
static const uint32_t TOP1_IOPFIRMASK_PHY1_ECC_CE_MASK = 2;
static const uint32_t TOP1_IOPFIRMASK_PHY1_ECC_UE_MASK = 3;
static const uint32_t TOP1_IOPFIRMASK_SCOM0_ECC_CE_MASK = 4;
static const uint32_t TOP1_IOPFIRMASK_SCOM0_ECC_UE_MASK = 5;
static const uint32_t TOP1_IOPFIRMASK_SCOM1_ECC_CE_MASK = 6;
static const uint32_t TOP1_IOPFIRMASK_SCOM1_ECC_UE_MASK = 7;
static const uint32_t TOP1_IOPFIRMASK_SCRUB0_ECC_CE_MASK = 8;
static const uint32_t TOP1_IOPFIRMASK_SCRUB0_ECC_UE_MASK = 9;
static const uint32_t TOP1_IOPFIRMASK_SCRUB1_ECC_CE_MASK = 10;
static const uint32_t TOP1_IOPFIRMASK_SCRUB1_ECC_UE_MASK = 11;
//<< [TOP1_IOPFIRMASK]
// pec/reg00004.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "pec/reg00004.H"
#endif
#endif
