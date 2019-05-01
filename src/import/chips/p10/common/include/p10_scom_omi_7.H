/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omi_7.H $        */
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

#include "proc_scomt.H"

#ifndef __p10_scom_omi_7_H_
#define __p10_scom_omi_7_H_


namespace scomt
{
namespace omi
{


static const uint64_t CYA_BITS = 0x0c01176full;

static const uint32_t CYA_BITS_BITS1 = 32;
static const uint32_t CYA_BITS_BITS1_LEN = 17;
static const uint32_t CYA_BITS_KILL_CRC_REPLAY1 = 49;
static const uint32_t CYA_BITS_RETRAIN_CRC_REPLAY1 = 50;
static const uint32_t CYA_BITS_PM_DISABLE_EDPL1 = 51;
static const uint32_t CYA_BITS_RETRAIN_CRC_RETRAIN1 = 52;
static const uint32_t CYA_BITS_RETRAIN_CRC_RESET1 = 53;
static const uint32_t CYA_BITS_FRBUF_FULL1 = 54;
static const uint32_t CYA_BITS_FRBUF_FULL_REPLAY1 = 55;
static const uint32_t CYA_BITS_PM_RETRAIN1 = 56;
static const uint32_t CYA_BITS_PM_RESET1 = 57;
static const uint32_t CYA_BITS_CRC_RETRAIN1 = 58;
static const uint32_t CYA_BITS_CRC_RESET1 = 59;
static const uint32_t CYA_BITS_RESERVED1 = 60;
static const uint32_t CYA_BITS_RESERVED1_LEN = 4;
// omi/reg00007.H

static const uint64_t ERROR_MASK = 0x0c011762ull;

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
// omi/reg00007.H

}
}
#include "omi/reg00007.H"
#endif
