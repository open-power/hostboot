/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mc_d.H $         */
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

#ifndef __p10_scom_mc_d_H_
#define __p10_scom_mc_d_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace mc
{
#endif


//>> [CTRL_ATOMIC_LOCK_REG]
static const uint64_t CTRL_ATOMIC_LOCK_REG = 0x0c0003ffull;

static const uint32_t CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE = 0;
static const uint32_t CTRL_ATOMIC_LOCK_REG_ID = 1;
static const uint32_t CTRL_ATOMIC_LOCK_REG_ID_LEN = 4;
static const uint32_t CTRL_ATOMIC_LOCK_REG_ACTIVITY = 8;
static const uint32_t CTRL_ATOMIC_LOCK_REG_ACTIVITY_LEN = 8;
//<< [CTRL_ATOMIC_LOCK_REG]
// mc/reg00013.H

//>> [EPS_DBG_DEBUG_TRACE_CONTROL]
static const uint64_t EPS_DBG_DEBUG_TRACE_CONTROL = 0x0c0107d0ull;

static const uint32_t EPS_DBG_DEBUG_TRACE_CONTROL_START = 0;
static const uint32_t EPS_DBG_DEBUG_TRACE_CONTROL_STOP = 1;
static const uint32_t EPS_DBG_DEBUG_TRACE_CONTROL_RESET = 2;
//<< [EPS_DBG_DEBUG_TRACE_CONTROL]
// mc/reg00013.H

//>> [MBA_SCOMFIR_MISCFIRMASK]
static const uint64_t MBA_SCOMFIR_MISCFIRMASK_RW = 0x0c010f03ull;
static const uint64_t MBA_SCOMFIR_MISCFIRMASK_WO_AND = 0x0c010f04ull;
static const uint64_t MBA_SCOMFIR_MISCFIRMASK_WO_OR = 0x0c010f05ull;

static const uint32_t MBA_SCOMFIR_MISCFIRMASK_MISCFIRMASK_FIR_MASK = 0;
static const uint32_t MBA_SCOMFIR_MISCFIRMASK_MISCFIRMASK_FIR_MASK_LEN = 12;
//<< [MBA_SCOMFIR_MISCFIRMASK]
// mc/reg00013.H

//>> [OPCG_CAPT1]
static const uint64_t OPCG_CAPT1 = 0x0c030010ull;

static const uint32_t OPCG_CAPT1_COUNT = 0;
static const uint32_t OPCG_CAPT1_COUNT_LEN = 4;
static const uint32_t OPCG_CAPT1_SEQ_01 = 4;
static const uint32_t OPCG_CAPT1_SEQ_01_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_02 = 9;
static const uint32_t OPCG_CAPT1_SEQ_02_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_03 = 14;
static const uint32_t OPCG_CAPT1_SEQ_03_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_04 = 19;
static const uint32_t OPCG_CAPT1_SEQ_04_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_05 = 24;
static const uint32_t OPCG_CAPT1_SEQ_05_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_06 = 29;
static const uint32_t OPCG_CAPT1_SEQ_06_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_07 = 34;
static const uint32_t OPCG_CAPT1_SEQ_07_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_08 = 39;
static const uint32_t OPCG_CAPT1_SEQ_08_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_09 = 44;
static const uint32_t OPCG_CAPT1_SEQ_09_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_10 = 49;
static const uint32_t OPCG_CAPT1_SEQ_10_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_11 = 54;
static const uint32_t OPCG_CAPT1_SEQ_11_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_12 = 59;
static const uint32_t OPCG_CAPT1_SEQ_12_LEN = 5;
//<< [OPCG_CAPT1]
// mc/reg00013.H

//>> [RECOV_MASK]
static const uint64_t RECOV_MASK_RW = 0x0c040041ull;
static const uint64_t RECOV_MASK_WO_CLEAR = 0x0c040061ull;
static const uint64_t RECOV_MASK_WO_OR = 0x0c040051ull;

static const uint32_t RECOV_MASK_1 = 1;
static const uint32_t RECOV_MASK_2 = 2;
static const uint32_t RECOV_MASK_3 = 3;
static const uint32_t RECOV_MASK_4 = 4;
static const uint32_t RECOV_MASK_5 = 5;
static const uint32_t RECOV_MASK_6 = 6;
static const uint32_t RECOV_MASK_7 = 7;
static const uint32_t RECOV_MASK_8 = 8;
static const uint32_t RECOV_MASK_9 = 9;
static const uint32_t RECOV_MASK_10 = 10;
static const uint32_t RECOV_MASK_11 = 11;
static const uint32_t RECOV_MASK_12 = 12;
static const uint32_t RECOV_MASK_13 = 13;
static const uint32_t RECOV_MASK_14 = 14;
static const uint32_t RECOV_MASK_15 = 15;
static const uint32_t RECOV_MASK_16 = 16;
static const uint32_t RECOV_MASK_17 = 17;
static const uint32_t RECOV_MASK_18 = 18;
static const uint32_t RECOV_MASK_19 = 19;
static const uint32_t RECOV_MASK_20 = 20;
static const uint32_t RECOV_MASK_21 = 21;
static const uint32_t RECOV_MASK_22 = 22;
static const uint32_t RECOV_MASK_23 = 23;
static const uint32_t RECOV_MASK_24 = 24;
static const uint32_t RECOV_MASK_25 = 25;
static const uint32_t RECOV_MASK_26 = 26;
static const uint32_t RECOV_MASK_27 = 27;
static const uint32_t RECOV_MASK_28 = 28;
static const uint32_t RECOV_MASK_29 = 29;
static const uint32_t RECOV_MASK_30 = 30;
static const uint32_t RECOV_MASK_31 = 31;
static const uint32_t RECOV_MASK_32 = 32;
static const uint32_t RECOV_MASK_33 = 33;
static const uint32_t RECOV_MASK_34 = 34;
static const uint32_t RECOV_MASK_35 = 35;
static const uint32_t RECOV_MASK_36 = 36;
static const uint32_t RECOV_MASK_37 = 37;
static const uint32_t RECOV_MASK_38 = 38;
static const uint32_t RECOV_MASK_39 = 39;
static const uint32_t RECOV_MASK_40 = 40;
static const uint32_t RECOV_MASK_41 = 41;
static const uint32_t RECOV_MASK_42 = 42;
static const uint32_t RECOV_MASK_43 = 43;
static const uint32_t RECOV_MASK_44 = 44;
static const uint32_t RECOV_MASK_45 = 45;
static const uint32_t RECOV_MASK_46 = 46;
static const uint32_t RECOV_MASK_47 = 47;
static const uint32_t RECOV_MASK_48 = 48;
static const uint32_t RECOV_MASK_49 = 49;
static const uint32_t RECOV_MASK_50 = 50;
static const uint32_t RECOV_MASK_51 = 51;
static const uint32_t RECOV_MASK_52 = 52;
static const uint32_t RECOV_MASK_53 = 53;
//<< [RECOV_MASK]
// mc/reg00013.H

//>> [SCOMFIR_MCFGP1]
static const uint64_t SCOMFIR_MCFGP1 = 0x0c010c0bull;

static const uint32_t SCOMFIR_MCFGP1_1_VALID = 0;
static const uint32_t SCOMFIR_MCFGP1_1_GROUP_BASE_ADDRESS = 1;
static const uint32_t SCOMFIR_MCFGP1_1_GROUP_BASE_ADDRESS_LEN = 24;
static const uint32_t SCOMFIR_MCFGP1_1_GROUP_SIZE = 25;
static const uint32_t SCOMFIR_MCFGP1_1_GROUP_SIZE_LEN = 15;
static const uint32_t SCOMFIR_MCFGP1_1_MC_CHANNELS_PER_GROUP = 40;
static const uint32_t SCOMFIR_MCFGP1_1_MC_CHANNELS_PER_GROUP_LEN = 3;
static const uint32_t SCOMFIR_MCFGP1_1_GROUP_MEMBER_IDENTIFICATION = 43;
static const uint32_t SCOMFIR_MCFGP1_1_GROUP_MEMBER_IDENTIFICATION_LEN = 3;
static const uint32_t SCOMFIR_MCFGP1_R1_CONFIGURATION_GROUP_SIZE = 46;
static const uint32_t SCOMFIR_MCFGP1_R1_CONFIGURATION_GROUP_SIZE_LEN = 8;
static const uint32_t SCOMFIR_MCFGP1_R1_MMIO_GROUP_SIZE = 54;
static const uint32_t SCOMFIR_MCFGP1_R1_MMIO_GROUP_SIZE_LEN = 8;
//<< [SCOMFIR_MCFGP1]
// mc/reg00013.H

//>> [XSTOP5]
static const uint64_t XSTOP5 = 0x0c030015ull;

static const uint32_t XSTOP5_ENABLE = 0;
static const uint32_t XSTOP5_WAIT_SNOPA = 1;
static const uint32_t XSTOP5_TRIGGER_OPCG_GO = 2;
static const uint32_t XSTOP5_WAIT_ALWAYS = 3;
static const uint32_t XSTOP5_REGION_PERV = 4;
static const uint32_t XSTOP5_REGION_UNIT1 = 5;
static const uint32_t XSTOP5_REGION_UNIT2 = 6;
static const uint32_t XSTOP5_REGION_UNIT3 = 7;
static const uint32_t XSTOP5_REGION_UNIT4 = 8;
static const uint32_t XSTOP5_REGION_UNIT5 = 9;
static const uint32_t XSTOP5_REGION_UNIT6 = 10;
static const uint32_t XSTOP5_REGION_UNIT7 = 11;
static const uint32_t XSTOP5_REGION_UNIT8 = 12;
static const uint32_t XSTOP5_REGION_UNIT9 = 13;
static const uint32_t XSTOP5_REGION_UNIT10 = 14;
static const uint32_t XSTOP5_REGION_UNIT11 = 15;
static const uint32_t XSTOP5_REGION_UNIT12 = 16;
static const uint32_t XSTOP5_REGION_UNIT13 = 17;
static const uint32_t XSTOP5_REGION_UNIT14 = 18;
static const uint32_t XSTOP5_WAIT_CYCLES = 48;
static const uint32_t XSTOP5_WAIT_CYCLES_LEN = 12;
//<< [XSTOP5]
// mc/reg00013.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "mc/reg00013.H"
#endif
#endif
