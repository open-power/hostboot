/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omi_0.H $        */
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

#ifndef __p10_scom_omi_0_H_
#define __p10_scom_omi_0_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace omi
{
#endif


//>> [ERROR_HOLD]
static const uint64_t ERROR_HOLD = 0x0c011413ull;

static const uint32_t ERROR_HOLD_47 = 16;
static const uint32_t ERROR_HOLD_46 = 17;
static const uint32_t ERROR_HOLD_45 = 18;
static const uint32_t ERROR_HOLD_44 = 19;
static const uint32_t ERROR_HOLD_43 = 20;
static const uint32_t ERROR_HOLD_42 = 21;
static const uint32_t ERROR_HOLD_41 = 22;
static const uint32_t ERROR_HOLD_40 = 23;
static const uint32_t ERROR_HOLD_39 = 24;
static const uint32_t ERROR_HOLD_38 = 25;
static const uint32_t ERROR_HOLD_37 = 26;
static const uint32_t ERROR_HOLD_36 = 27;
static const uint32_t ERROR_HOLD_35 = 28;
static const uint32_t ERROR_HOLD_34 = 29;
static const uint32_t ERROR_HOLD_33 = 30;
static const uint32_t ERROR_HOLD_32 = 31;
static const uint32_t ERROR_HOLD_31 = 32;
static const uint32_t ERROR_HOLD_30 = 33;
static const uint32_t ERROR_HOLD_29 = 34;
static const uint32_t ERROR_HOLD_28 = 35;
static const uint32_t ERROR_HOLD_27 = 36;
static const uint32_t ERROR_HOLD_26 = 37;
static const uint32_t ERROR_HOLD_25 = 38;
static const uint32_t ERROR_HOLD_24 = 39;
static const uint32_t ERROR_HOLD_23 = 40;
static const uint32_t ERROR_HOLD_22 = 41;
static const uint32_t ERROR_HOLD_21 = 42;
static const uint32_t ERROR_HOLD_20 = 43;
static const uint32_t ERROR_HOLD_19 = 44;
static const uint32_t ERROR_HOLD_18 = 45;
static const uint32_t ERROR_HOLD_17 = 46;
static const uint32_t ERROR_HOLD_16 = 47;
static const uint32_t ERROR_HOLD_15 = 48;
static const uint32_t ERROR_HOLD_14 = 49;
static const uint32_t ERROR_HOLD_13 = 50;
static const uint32_t ERROR_HOLD_12 = 51;
static const uint32_t ERROR_HOLD_11 = 52;
static const uint32_t ERROR_HOLD_10 = 53;
static const uint32_t ERROR_HOLD_09 = 54;
static const uint32_t ERROR_HOLD_08 = 55;
static const uint32_t ERROR_HOLD_07 = 56;
static const uint32_t ERROR_HOLD_06 = 57;
static const uint32_t ERROR_HOLD_05 = 58;
static const uint32_t ERROR_HOLD_04 = 59;
static const uint32_t ERROR_HOLD_03 = 60;
static const uint32_t ERROR_HOLD_02 = 61;
static const uint32_t ERROR_HOLD_01 = 62;
static const uint32_t ERROR_HOLD_00 = 63;
//<< [ERROR_HOLD]
// omi/reg00000.H

//>> [RXCTL_DATASM_0_PLREGS_RX_MODE1_PL]
static const uint64_t RXCTL_DATASM_0_PLREGS_RX_MODE1_PL = 0x8003d04010012c3full;

static const uint32_t RXCTL_DATASM_0_PLREGS_RX_MODE1_PL_RECAL_REQ_DL_MASK = 48;
static const uint32_t RXCTL_DATASM_0_PLREGS_RX_MODE1_PL_RECAL_DONE_DL_MASK = 49;
static const uint32_t RXCTL_DATASM_0_PLREGS_RX_MODE1_PL_RUN_LANE_DL_MASK = 50;
static const uint32_t RXCTL_DATASM_0_PLREGS_RX_MODE1_PL_RECAL_ABORT_DL_MASK = 51;
static const uint32_t RXCTL_DATASM_0_PLREGS_RX_MODE1_PL_INIT_DONE_DL_MASK = 52;
//<< [RXCTL_DATASM_0_PLREGS_RX_MODE1_PL]
// omi/reg00000.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "omi/reg00000.H"
#include "omi/reg00001.H"
#endif
#endif
