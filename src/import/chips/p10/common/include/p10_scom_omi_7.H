/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omi_7.H $        */
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

#ifndef __p10_scom_omi_7_H_
#define __p10_scom_omi_7_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace omi
{
#endif


//>> [CYA_BITS]
static const uint64_t CYA_BITS = 0x0c01141full;

static const uint32_t CYA_BITS_PRBS15_NPRBS7_0 = 0;
static const uint32_t CYA_BITS_PRBS15_NPRBS7_1 = 0;
static const uint32_t CYA_BITS_BITS0_RSVD0 = 1;
static const uint32_t CYA_BITS_BITS0_RSVD0_LEN = 22;
static const uint32_t CYA_BITS_BITS1_RSVD0 = 1;
static const uint32_t CYA_BITS_BITS1_RSVD0_LEN = 22;
static const uint32_t P10_20_CYA_BITS_BITS0_RSVD0 = 1; // p10:20,
static const uint32_t P10_20_CYA_BITS_BITS0_RSVD0_LEN = 21;
static const uint32_t P10_20_CYA_BITS_CS_STS_REG_UPDATE = 22; // p10:20,
static const uint32_t CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT0 = 23;
static const uint32_t CYA_BITS_RX_PN_SWAP_OVERRIDE_SELECT1 = 23;
static const uint32_t CYA_BITS_RX_PN_SWAP_OVERRIDE0 = 24;
static const uint32_t CYA_BITS_RX_PN_SWAP_OVERRIDE0_LEN = 8;
static const uint32_t CYA_BITS_RX_PN_SWAP_OVERRIDE1 = 24;
static const uint32_t CYA_BITS_RX_PN_SWAP_OVERRIDE1_LEN = 8;
static const uint32_t CYA_BITS_BITS0_RSVD1 = 32;
static const uint32_t CYA_BITS_BITS0_RSVD1_LEN = 12;
static const uint32_t CYA_BITS_BITS1_RSVD1 = 32;
static const uint32_t CYA_BITS_BITS1_RSVD1_LEN = 12;
static const uint32_t P10_20_CYA_BITS_BITS0_RSVD1 = 32; // p10:20,
static const uint32_t P10_20_CYA_BITS_BITS0_RSVD1_LEN = 9;
static const uint32_t P10_20_CYA_BITS_CS_EDPL = 41; // p10:20,
static const uint32_t P10_20_CYA_BITS_RPB_READ_EN = 42; // p10:20,
static const uint32_t P10_20_CYA_BITS_EARLY_RL_DETECT = 43; // p10:20,
static const uint32_t CYA_BITS_TX_PSAVE_DELAY_TIMER0 = 44;
static const uint32_t CYA_BITS_TX_PSAVE_DELAY_TIMER0_LEN = 3;
static const uint32_t CYA_BITS_TX_PSAVE_DELAY_TIMER1 = 44;
static const uint32_t CYA_BITS_TX_PSAVE_DELAY_TIMER1_LEN = 3;
static const uint32_t CYA_BITS_FAST_RETRAIN_DISABLE0 = 47;
static const uint32_t CYA_BITS_FAST_RETRAIN_DISABLE1 = 47;
static const uint32_t CYA_BITS_FLT_TRUNC_FIX = 48;
static const uint32_t CYA_BITS_BITS1_RSVD2 = 48;
static const uint32_t CYA_BITS_KILL_CRC_REPLAY0 = 49;
static const uint32_t CYA_BITS_KILL_CRC_REPLAY1 = 49;
static const uint32_t CYA_BITS_RETRAIN_CRC_REPLAY0 = 50;
static const uint32_t CYA_BITS_RETRAIN_CRC_REPLAY1 = 50;
static const uint32_t CYA_BITS_PM_DISABLE_EDPL0 = 51;
static const uint32_t CYA_BITS_PM_DISABLE_EDPL1 = 51;
static const uint32_t CYA_BITS_RETRAIN_CRC_RETRAIN0 = 52;
static const uint32_t CYA_BITS_RETRAIN_CRC_RETRAIN1 = 52;
static const uint32_t CYA_BITS_RETRAIN_CRC_RESET0 = 53;
static const uint32_t CYA_BITS_RETRAIN_CRC_RESET1 = 53;
static const uint32_t CYA_BITS_FRBUF_FULL0 = 54;
static const uint32_t CYA_BITS_FRBUF_FULL1 = 54;
static const uint32_t CYA_BITS_FRBUF_FULL_REPLAY0 = 55;
static const uint32_t CYA_BITS_FRBUF_FULL_REPLAY1 = 55;
static const uint32_t CYA_BITS_PM_RETRAIN0 = 56;
static const uint32_t CYA_BITS_PM_RETRAIN1 = 56;
static const uint32_t CYA_BITS_PM_RESET0 = 57;
static const uint32_t CYA_BITS_PM_RESET1 = 57;
static const uint32_t CYA_BITS_CRC_RETRAIN0 = 58;
static const uint32_t CYA_BITS_CRC_RETRAIN1 = 58;
static const uint32_t CYA_BITS_CRC_RESET0 = 59;
static const uint32_t CYA_BITS_CRC_RESET1 = 59;
static const uint32_t CYA_BITS_RP_NONZERO0 = 60;
static const uint32_t CYA_BITS_RP_NONZERO1 = 60;
static const uint32_t CYA_BITS_BITS0_RSVD3 = 61;
static const uint32_t CYA_BITS_BITS0_RSVD3_LEN = 3;
static const uint32_t CYA_BITS_BITS1_RSVD3 = 61;
static const uint32_t CYA_BITS_BITS1_RSVD3_LEN = 3;
//<< [CYA_BITS]
// omi/reg00014.H

//>> [ERROR_MASK]
static const uint64_t ERROR_MASK = 0x0c011412ull;

static const uint32_t ERROR_MASK_47 = 16;
static const uint32_t ERROR_MASK_46 = 17;
static const uint32_t ERROR_MASK_45 = 18;
static const uint32_t ERROR_MASK_44 = 19;
static const uint32_t ERROR_MASK_43 = 20;
static const uint32_t ERROR_MASK_42 = 21;
static const uint32_t ERROR_MASK_41 = 22;
static const uint32_t ERROR_MASK_40 = 23;
static const uint32_t ERROR_MASK_39 = 24;
static const uint32_t ERROR_MASK_38 = 25;
static const uint32_t ERROR_MASK_37 = 26;
static const uint32_t ERROR_MASK_36 = 27;
static const uint32_t ERROR_MASK_35 = 28;
static const uint32_t ERROR_MASK_34 = 29;
static const uint32_t ERROR_MASK_33 = 30;
static const uint32_t ERROR_MASK_32 = 31;
static const uint32_t ERROR_MASK_31 = 32;
static const uint32_t ERROR_MASK_30 = 33;
static const uint32_t ERROR_MASK_29 = 34;
static const uint32_t ERROR_MASK_28 = 35;
static const uint32_t ERROR_MASK_27 = 36;
static const uint32_t ERROR_MASK_26 = 37;
static const uint32_t ERROR_MASK_25 = 38;
static const uint32_t ERROR_MASK_24 = 39;
static const uint32_t ERROR_MASK_23 = 40;
static const uint32_t ERROR_MASK_22 = 41;
static const uint32_t ERROR_MASK_21 = 42;
static const uint32_t ERROR_MASK_20 = 43;
static const uint32_t ERROR_MASK_19 = 44;
static const uint32_t ERROR_MASK_18 = 45;
static const uint32_t ERROR_MASK_17 = 46;
static const uint32_t ERROR_MASK_16 = 47;
static const uint32_t ERROR_MASK_15 = 48;
static const uint32_t ERROR_MASK_14 = 49;
static const uint32_t ERROR_MASK_13 = 50;
static const uint32_t ERROR_MASK_12 = 51;
static const uint32_t ERROR_MASK_11 = 52;
static const uint32_t ERROR_MASK_10 = 53;
static const uint32_t ERROR_MASK_09 = 54;
static const uint32_t ERROR_MASK_08 = 55;
static const uint32_t ERROR_MASK_07 = 56;
static const uint32_t ERROR_MASK_06 = 57;
static const uint32_t ERROR_MASK_05 = 58;
static const uint32_t ERROR_MASK_04 = 59;
static const uint32_t ERROR_MASK_03 = 60;
static const uint32_t ERROR_MASK_02 = 61;
static const uint32_t ERROR_MASK_01 = 62;
static const uint32_t ERROR_MASK_00 = 63;
//<< [ERROR_MASK]
// omi/reg00014.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "omi/reg00014.H"
#include "omi/reg00015.H"
#endif
#endif
