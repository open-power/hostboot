/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pec_b.H $        */
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

#ifndef __p10_scom_pec_b_H_
#define __p10_scom_pec_b_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace pec
{
#endif


//>> [ATOMIC_LOCK_REG]
static const uint64_t ATOMIC_LOCK_REG = 0x080f03ffull;

static const uint32_t ATOMIC_LOCK_REG_LOCK_ENABLE = 0;
static const uint32_t ATOMIC_LOCK_REG_ID = 1;
static const uint32_t ATOMIC_LOCK_REG_ID_LEN = 4;
static const uint32_t ATOMIC_LOCK_REG_ACTIVITY = 8;
static const uint32_t ATOMIC_LOCK_REG_ACTIVITY_LEN = 8;
//<< [ATOMIC_LOCK_REG]
// pec/reg00011.H

//>> [ATTN_INTERRUPT_REG]
static const uint64_t ATTN_INTERRUPT_REG = 0x080f001aull;

static const uint32_t ATTN_INTERRUPT_REG_ATTN = 0;
//<< [ATTN_INTERRUPT_REG]
// pec/reg00011.H

//>> [EPS_FIR_LOCAL_MASK]
static const uint64_t EPS_FIR_LOCAL_MASK_RW = 0x08040103ull;
static const uint64_t EPS_FIR_LOCAL_MASK_WO_AND = 0x08040104ull;
static const uint64_t EPS_FIR_LOCAL_MASK_WO_OR = 0x08040105ull;

static const uint32_t EPS_FIR_LOCAL_MASK_00 = 0;
static const uint32_t EPS_FIR_LOCAL_MASK_01 = 1;
static const uint32_t EPS_FIR_LOCAL_MASK_02 = 2;
static const uint32_t EPS_FIR_LOCAL_MASK_03 = 3;
static const uint32_t EPS_FIR_LOCAL_MASK_04 = 4;
static const uint32_t EPS_FIR_LOCAL_MASK_05 = 5;
static const uint32_t EPS_FIR_LOCAL_MASK_06 = 6;
static const uint32_t EPS_FIR_LOCAL_MASK_07 = 7;
static const uint32_t EPS_FIR_LOCAL_MASK_08 = 8;
static const uint32_t EPS_FIR_LOCAL_MASK_09 = 9;
static const uint32_t EPS_FIR_LOCAL_MASK_10 = 10;
static const uint32_t EPS_FIR_LOCAL_MASK_11 = 11;
static const uint32_t EPS_FIR_LOCAL_MASK_12 = 12;
static const uint32_t EPS_FIR_LOCAL_MASK_13 = 13;
static const uint32_t EPS_FIR_LOCAL_MASK_14 = 14;
static const uint32_t EPS_FIR_LOCAL_MASK_15 = 15;
static const uint32_t EPS_FIR_LOCAL_MASK_16 = 16;
static const uint32_t EPS_FIR_LOCAL_MASK_17 = 17;
static const uint32_t EPS_FIR_LOCAL_MASK_18 = 18;
static const uint32_t EPS_FIR_LOCAL_MASK_19 = 19;
static const uint32_t EPS_FIR_LOCAL_MASK_20 = 20;
static const uint32_t EPS_FIR_LOCAL_MASK_21 = 21;
static const uint32_t EPS_FIR_LOCAL_MASK_22 = 22;
static const uint32_t EPS_FIR_LOCAL_MASK_23 = 23;
static const uint32_t EPS_FIR_LOCAL_MASK_24 = 24;
static const uint32_t EPS_FIR_LOCAL_MASK_25 = 25;
static const uint32_t EPS_FIR_LOCAL_MASK_26 = 26;
static const uint32_t EPS_FIR_LOCAL_MASK_27 = 27;
static const uint32_t EPS_FIR_LOCAL_MASK_28 = 28;
static const uint32_t EPS_FIR_LOCAL_MASK_29 = 29;
static const uint32_t EPS_FIR_LOCAL_MASK_30 = 30;
static const uint32_t EPS_FIR_LOCAL_MASK_31 = 31;
static const uint32_t EPS_FIR_LOCAL_MASK_32 = 32;
static const uint32_t EPS_FIR_LOCAL_MASK_33 = 33;
static const uint32_t EPS_FIR_LOCAL_MASK_34 = 34;
static const uint32_t EPS_FIR_LOCAL_MASK_35 = 35;
static const uint32_t EPS_FIR_LOCAL_MASK_36 = 36;
static const uint32_t EPS_FIR_LOCAL_MASK_37 = 37;
static const uint32_t EPS_FIR_LOCAL_MASK_38 = 38;
static const uint32_t EPS_FIR_LOCAL_MASK_39 = 39;
static const uint32_t EPS_FIR_LOCAL_MASK_40 = 40;
static const uint32_t EPS_FIR_LOCAL_MASK_41 = 41;
static const uint32_t EPS_FIR_LOCAL_MASK_42 = 42;
static const uint32_t EPS_FIR_LOCAL_MASK_43 = 43;
static const uint32_t EPS_FIR_LOCAL_MASK_44 = 44;
static const uint32_t EPS_FIR_LOCAL_MASK_45 = 45;
static const uint32_t EPS_FIR_LOCAL_MASK_46 = 46;
static const uint32_t EPS_FIR_LOCAL_MASK_47 = 47;
static const uint32_t EPS_FIR_LOCAL_MASK_48 = 48;
static const uint32_t EPS_FIR_LOCAL_MASK_49 = 49;
static const uint32_t EPS_FIR_LOCAL_MASK_50 = 50;
static const uint32_t EPS_FIR_LOCAL_MASK_51 = 51;
static const uint32_t EPS_FIR_LOCAL_MASK_52 = 52;
static const uint32_t EPS_FIR_LOCAL_MASK_53 = 53;
static const uint32_t EPS_FIR_LOCAL_MASK_54 = 54;
static const uint32_t EPS_FIR_LOCAL_MASK_55 = 55;
static const uint32_t EPS_FIR_LOCAL_MASK_56 = 56;
static const uint32_t EPS_FIR_LOCAL_MASK_57 = 57;
static const uint32_t EPS_FIR_LOCAL_MASK_58 = 58;
static const uint32_t EPS_FIR_LOCAL_MASK_59 = 59;
static const uint32_t EPS_FIR_LOCAL_MASK_60 = 60;
static const uint32_t EPS_FIR_LOCAL_MASK_61 = 61;
static const uint32_t EPS_FIR_LOCAL_MASK_62 = 62;
static const uint32_t EPS_FIR_LOCAL_MASK_63 = 63;
//<< [EPS_FIR_LOCAL_MASK]
// pec/reg00011.H

//>> [LOCAL_FIR]
static const uint64_t LOCAL_FIR_RW = 0x08040100ull;
static const uint64_t LOCAL_FIR_WO_AND = 0x08040101ull;
static const uint64_t LOCAL_FIR_WO_OR = 0x08040102ull;

static const uint32_t LOCAL_FIR_CFIR = 0;
static const uint32_t LOCAL_FIR_CPLT_CTRL = 1;
static const uint32_t LOCAL_FIR_CC_PCB = 2;
static const uint32_t LOCAL_FIR_CC_OTHERS = 3;
static const uint32_t LOCAL_FIR_IN04 = 4;
static const uint32_t LOCAL_FIR_IN05 = 5;
static const uint32_t LOCAL_FIR_IN06 = 6;
static const uint32_t LOCAL_FIR_IN07 = 7;
static const uint32_t LOCAL_FIR_IN08 = 8;
static const uint32_t LOCAL_FIR_IN09 = 9;
static const uint32_t LOCAL_FIR_IN10 = 10;
static const uint32_t LOCAL_FIR_IN11 = 11;
static const uint32_t LOCAL_FIR_IN12 = 12;
static const uint32_t LOCAL_FIR_IN13 = 13;
static const uint32_t LOCAL_FIR_IN14 = 14;
static const uint32_t LOCAL_FIR_IN15 = 15;
static const uint32_t LOCAL_FIR_IN16 = 16;
static const uint32_t LOCAL_FIR_IN17 = 17;
static const uint32_t LOCAL_FIR_IN18 = 18;
static const uint32_t LOCAL_FIR_IN19 = 19;
static const uint32_t LOCAL_FIR_IN20 = 20;
static const uint32_t LOCAL_FIR_IN21 = 21;
static const uint32_t LOCAL_FIR_IN22 = 22;
static const uint32_t LOCAL_FIR_IN23 = 23;
static const uint32_t LOCAL_FIR_IN24 = 24;
static const uint32_t LOCAL_FIR_IN25 = 25;
static const uint32_t LOCAL_FIR_IN26 = 26;
static const uint32_t LOCAL_FIR_IN27 = 27;
static const uint32_t LOCAL_FIR_IN28 = 28;
static const uint32_t LOCAL_FIR_IN29 = 29;
static const uint32_t LOCAL_FIR_IN30 = 30;
static const uint32_t LOCAL_FIR_IN31 = 31;
static const uint32_t LOCAL_FIR_IN32 = 32;
static const uint32_t LOCAL_FIR_IN33 = 33;
static const uint32_t LOCAL_FIR_IN34 = 34;
static const uint32_t LOCAL_FIR_IN35 = 35;
static const uint32_t LOCAL_FIR_IN36 = 36;
static const uint32_t LOCAL_FIR_IN37 = 37;
static const uint32_t LOCAL_FIR_IN38 = 38;
static const uint32_t LOCAL_FIR_IN39 = 39;
static const uint32_t LOCAL_FIR_IN40 = 40;
static const uint32_t LOCAL_FIR_IN41 = 41;
static const uint32_t LOCAL_FIR_IN42 = 42;
static const uint32_t LOCAL_FIR_IN43 = 43;
static const uint32_t LOCAL_FIR_IN44 = 44;
static const uint32_t LOCAL_FIR_IN45 = 45;
static const uint32_t LOCAL_FIR_IN46 = 46;
static const uint32_t LOCAL_FIR_IN47 = 47;
static const uint32_t LOCAL_FIR_IN48 = 48;
static const uint32_t LOCAL_FIR_IN49 = 49;
static const uint32_t LOCAL_FIR_IN50 = 50;
static const uint32_t LOCAL_FIR_IN51 = 51;
static const uint32_t LOCAL_FIR_IN52 = 52;
static const uint32_t LOCAL_FIR_IN53 = 53;
static const uint32_t LOCAL_FIR_IN54 = 54;
static const uint32_t LOCAL_FIR_IN55 = 55;
static const uint32_t LOCAL_FIR_IN56 = 56;
static const uint32_t LOCAL_FIR_IN57 = 57;
static const uint32_t LOCAL_FIR_IN58 = 58;
static const uint32_t LOCAL_FIR_IN59 = 59;
static const uint32_t LOCAL_FIR_IN60 = 60;
static const uint32_t LOCAL_FIR_IN61 = 61;
static const uint32_t LOCAL_FIR_IN62 = 62;
static const uint32_t LOCAL_FIR_EXT_LOCAL_XSTOP = 63;
//<< [LOCAL_FIR]
// pec/reg00011.H

//>> [RECOV]
static const uint64_t RECOV = 0x08040001ull;

static const uint32_t RECOV_ANY_RECOV = 0;
static const uint32_t RECOV_RESERVED1R = 1;
static const uint32_t RECOV_ANY_LOCAL_XSTOP = 2;
static const uint32_t RECOV_RESERVED3R = 3;
static const uint32_t RECOV_PERV = 4;
static const uint32_t RECOV_IN05 = 5;
static const uint32_t RECOV_IN06 = 6;
static const uint32_t RECOV_IN07 = 7;
static const uint32_t RECOV_IN08 = 8;
static const uint32_t RECOV_IN09 = 9;
static const uint32_t RECOV_IN10 = 10;
static const uint32_t RECOV_IN11 = 11;
static const uint32_t RECOV_IN12 = 12;
static const uint32_t RECOV_IN13 = 13;
static const uint32_t RECOV_IN14 = 14;
static const uint32_t RECOV_IN15 = 15;
static const uint32_t RECOV_IN16 = 16;
static const uint32_t RECOV_IN17 = 17;
static const uint32_t RECOV_IN18 = 18;
static const uint32_t RECOV_IN19 = 19;
static const uint32_t RECOV_IN20 = 20;
static const uint32_t RECOV_IN21 = 21;
static const uint32_t RECOV_IN22 = 22;
static const uint32_t RECOV_IN23 = 23;
static const uint32_t RECOV_IN24 = 24;
static const uint32_t RECOV_IN25 = 25;
static const uint32_t RECOV_IN26 = 26;
static const uint32_t RECOV_IN27 = 27;
static const uint32_t RECOV_IN28 = 28;
static const uint32_t RECOV_IN29 = 29;
static const uint32_t RECOV_IN30 = 30;
static const uint32_t RECOV_IN31 = 31;
static const uint32_t RECOV_IN32 = 32;
static const uint32_t RECOV_IN33 = 33;
static const uint32_t RECOV_IN34 = 34;
static const uint32_t RECOV_IN35 = 35;
static const uint32_t RECOV_IN36 = 36;
static const uint32_t RECOV_IN37 = 37;
static const uint32_t RECOV_IN38 = 38;
static const uint32_t RECOV_IN39 = 39;
static const uint32_t RECOV_IN40 = 40;
static const uint32_t RECOV_IN41 = 41;
static const uint32_t RECOV_IN42 = 42;
static const uint32_t RECOV_IN43 = 43;
static const uint32_t RECOV_IN44 = 44;
static const uint32_t RECOV_IN45 = 45;
static const uint32_t RECOV_IN46 = 46;
static const uint32_t RECOV_IN47 = 47;
static const uint32_t RECOV_IN48 = 48;
static const uint32_t RECOV_IN49 = 49;
static const uint32_t RECOV_IN50 = 50;
static const uint32_t RECOV_IN51 = 51;
static const uint32_t RECOV_IN52 = 52;
static const uint32_t RECOV_IN53 = 53;
//<< [RECOV]
// pec/reg00011.H

//>> [XSTOP4]
static const uint64_t XSTOP4 = 0x08030014ull;

static const uint32_t XSTOP4_ENABLE = 0;
static const uint32_t XSTOP4_WAIT_SNOPA = 1;
static const uint32_t XSTOP4_TRIGGER_OPCG_GO = 2;
static const uint32_t XSTOP4_WAIT_ALWAYS = 3;
static const uint32_t XSTOP4_REGION_PERV = 4;
static const uint32_t XSTOP4_REGION_UNIT1 = 5;
static const uint32_t XSTOP4_REGION_UNIT2 = 6;
static const uint32_t XSTOP4_REGION_UNIT3 = 7;
static const uint32_t XSTOP4_REGION_UNIT4 = 8;
static const uint32_t XSTOP4_REGION_UNIT5 = 9;
static const uint32_t XSTOP4_REGION_UNIT6 = 10;
static const uint32_t XSTOP4_REGION_UNIT7 = 11;
static const uint32_t XSTOP4_REGION_UNIT8 = 12;
static const uint32_t XSTOP4_REGION_UNIT9 = 13;
static const uint32_t XSTOP4_REGION_UNIT10 = 14;
static const uint32_t XSTOP4_REGION_UNIT11 = 15;
static const uint32_t XSTOP4_REGION_UNIT12 = 16;
static const uint32_t XSTOP4_REGION_UNIT13 = 17;
static const uint32_t XSTOP4_REGION_UNIT14 = 18;
static const uint32_t XSTOP4_WAIT_CYCLES = 48;
static const uint32_t XSTOP4_WAIT_CYCLES_LEN = 12;
//<< [XSTOP4]
// pec/reg00011.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "pec/reg00011.H"
#endif
#endif
