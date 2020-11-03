/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pauc_d.H $       */
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

#ifndef __p10_scom_pauc_d_H_
#define __p10_scom_pauc_d_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace pauc
{
#endif


//>> [CTRL_ATOMIC_LOCK_REG]
static const uint64_t CTRL_ATOMIC_LOCK_REG = 0x100003ffull;

static const uint32_t CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE = 0;
static const uint32_t CTRL_ATOMIC_LOCK_REG_ID = 1;
static const uint32_t CTRL_ATOMIC_LOCK_REG_ID_LEN = 4;
static const uint32_t CTRL_ATOMIC_LOCK_REG_ACTIVITY = 8;
static const uint32_t CTRL_ATOMIC_LOCK_REG_ACTIVITY_LEN = 8;
//<< [CTRL_ATOMIC_LOCK_REG]
// pauc/reg00013.H

//>> [EPS_DBG_DEBUG_TRACE_CONTROL]
static const uint64_t EPS_DBG_DEBUG_TRACE_CONTROL = 0x100107d0ull;

static const uint32_t EPS_DBG_DEBUG_TRACE_CONTROL_START = 0;
static const uint32_t EPS_DBG_DEBUG_TRACE_CONTROL_STOP = 1;
static const uint32_t EPS_DBG_DEBUG_TRACE_CONTROL_RESET = 2;
//<< [EPS_DBG_DEBUG_TRACE_CONTROL]
// pauc/reg00013.H

//>> [OPCG_CAPT1]
static const uint64_t OPCG_CAPT1 = 0x10030010ull;

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
// pauc/reg00013.H

//>> [PB_PTL_FIR_REG]
static const uint64_t PB_PTL_FIR_REG_RW = 0x10011800ull;
static const uint64_t PB_PTL_FIR_REG_WO_AND = 0x10011801ull;
static const uint64_t PB_PTL_FIR_REG_WO_OR = 0x10011802ull;

static const uint32_t PB_PTL_FIR_REG_FMR00_TRAINED = 0;
static const uint32_t PB_PTL_FIR_REG_FMR01_TRAINED = 1;
static const uint32_t PB_PTL_FIR_REG_FMR02_TRAINED = 2;
static const uint32_t PB_PTL_FIR_REG_FMR03_TRAINED = 3;
static const uint32_t PB_PTL_FIR_REG_DOB01_UE = 4;
static const uint32_t PB_PTL_FIR_REG_DOB01_CE = 5;
static const uint32_t PB_PTL_FIR_REG_DOB01_SUE = 6;
static const uint32_t PB_PTL_FIR_REG_DOB01_ERR = 7;
static const uint32_t PB_PTL_FIR_REG_DOB23_UE = 8;
static const uint32_t PB_PTL_FIR_REG_DOB23_CE = 9;
static const uint32_t PB_PTL_FIR_REG_DOB23_SUE = 10;
static const uint32_t PB_PTL_FIR_REG_DOB23_ERR = 11;
static const uint32_t PB_PTL_FIR_REG_FRAMER00_ATTN = 12;
static const uint32_t PB_PTL_FIR_REG_CROB01_ATTN = 13;
static const uint32_t PB_PTL_FIR_REG_FRAMER01_ATTN = 14;
static const uint32_t PB_PTL_FIR_REG_FRAMER02_ATTN = 15;
static const uint32_t PB_PTL_FIR_REG_CROB23_ATTN = 16;
static const uint32_t PB_PTL_FIR_REG_FRAMER03_ATTN = 17;
static const uint32_t PB_PTL_FIR_REG_PARSER00_ATTN = 18;
static const uint32_t PB_PTL_FIR_REG_PARSER01_ATTN = 19;
static const uint32_t PB_PTL_FIR_REG_PARSER02_ATTN = 20;
static const uint32_t PB_PTL_FIR_REG_PARSER03_ATTN = 21;
static const uint32_t PB_PTL_FIR_REG_LINK_DOWN_0_ATTN = 22;
static const uint32_t PB_PTL_FIR_REG_LINK_DOWN_1_ATTN = 23;
static const uint32_t PB_PTL_FIR_REG_LINK_DOWN_2_ATTN = 24;
static const uint32_t PB_PTL_FIR_REG_LINK_DOWN_3_ATTN = 25;
static const uint32_t PB_PTL_FIR_REG_DIB01_ERR = 26;
static const uint32_t PB_PTL_FIR_REG_DIB23_ERR = 27;
static const uint32_t PB_PTL_FIR_REG_MB00_SPATTN = 28;
static const uint32_t PB_PTL_FIR_REG_MB01_SPATTN = 29;
static const uint32_t PB_PTL_FIR_REG_MB10_SPATTN = 30;
static const uint32_t PB_PTL_FIR_REG_MB11_SPATTN = 31;
static const uint32_t PB_PTL_FIR_REG_MB20_SPATTN = 32;
static const uint32_t PB_PTL_FIR_REG_MB21_SPATTN = 33;
static const uint32_t PB_PTL_FIR_REG_MB30_SPATTN = 34;
static const uint32_t PB_PTL_FIR_REG_MB31_SPATTN = 35;
static const uint32_t PB_PTL_FIR_REG_PTL0_SPARE = 36;
static const uint32_t PB_PTL_FIR_REG_PTL1_SPARE = 37;
static const uint32_t PB_PTL_FIR_REG_PTL2_SPARE = 38;
static const uint32_t PB_PTL_FIR_REG_PTL3_SPARE = 39;
//<< [PB_PTL_FIR_REG]
// pauc/reg00013.H

//>> [RECOV_MASK]
static const uint64_t RECOV_MASK_RW = 0x10040041ull;
static const uint64_t RECOV_MASK_WO_CLEAR = 0x10040061ull;
static const uint64_t RECOV_MASK_WO_OR = 0x10040051ull;

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
// pauc/reg00013.H

//>> [XSTOP5]
static const uint64_t XSTOP5 = 0x10030015ull;

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
// pauc/reg00013.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "pauc/reg00013.H"
#endif
#endif
